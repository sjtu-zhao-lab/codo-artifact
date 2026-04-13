#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "llvm/Support/Debug.h"
#include "codo/Init_All_Dialects.h"

#include<string>
#include <vector>
#include <regex>
#include <map>


#define DEBUG_TYPE "codo"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

void three_mm_loopreorder(AffineLoopBands &bands){
  //get three loop's dependence
  int band_cnt = 1;
  // here registername mapping: 1:provide row, 2:provide column, 3:as storage register
  std::map<std::string, int> band1_mapping;
  std::map<std::string, int> band2_mapping;
  std::map<std::string, int> band3_mapping;
  std::string output1, output2,output3;
  for (auto &band : bands)
  {
    std::string row, col, reduction;
    auto loop_affine = band[0];
    std::map<std::string, int> band_mapping;
    std::string output;
    std::string load1_reg;
    std::vector<std::string> load1;
    std::string load2_reg;
    std::vector<std::string> load2;
    std::string store1_reg;
    std::vector<std::string> store1;
    int load_cnt = 1;
    loop_affine.walk([&load1_reg,&load1,&load2_reg,&load2,&store1_reg,&store1,&load_cnt](Operation *op)
                     {
                        
                          //  llvm::outs() << op->getName() << "\n";
                          // auto op_num = op->getNumOperands();
                          // llvm::outs() << op_num << "\n";
                        
                        if (isa<affine::AffineLoadOp>(*op))
                        {

                          std::string opString;
                          llvm::raw_string_ostream ostream(opString);
                          op->print(ostream);
                          std::vector<std::string> registers;
                          std::regex reg(R"(%\w+)");
                          auto begin = std::sregex_iterator(opString.begin(), opString.end(), reg);
                          auto end = std::sregex_iterator();
                          for (auto it = begin; it != end; ++it)
                          {
                            registers.push_back(it->str());
                          }
                          if (load_cnt == 1)
                          {
                            load1.push_back(registers[registers.size() - 2]);
                            load1.push_back(registers[registers.size() - 1]);
                            load1_reg = registers[1];
                          }
                          if (load_cnt == 2)
                          {
                            load2.push_back(registers[registers.size() - 2]);
                            load2.push_back(registers[registers.size() - 1]);
                            load2_reg = registers[1];
                          }
                          load_cnt++;
                        }

                      
                        if (isa<affine::AffineStoreOp>(*op))
                        {
                          std::string opString;
                          llvm::raw_string_ostream ostream(opString);
                          op->print(ostream);
                          std::vector<std::string> registers;
                          std::regex reg(R"(%\w+)");
                          auto begin = std::sregex_iterator(opString.begin(), opString.end(), reg);
                          auto end = std::sregex_iterator();
                          for (auto it = begin; it != end; ++it)
                          {
                            registers.push_back(it->str());
                          }
                          store1.push_back(registers[registers.size() - 2]);
                          store1.push_back(registers[registers.size() - 1]);
                          store1_reg = registers[1];
                        }

                        
                      
                      });
    if(load1[1] == load2[0])
    {
    band_mapping[load1_reg] = 1;
    band_mapping[load2_reg] = 2;
    band_mapping[store1_reg] = 3;
    row = load1[0];
    col = load2[1];
    reduction = load1[1];
    }
    else{
    band_mapping[load1_reg] = 2;
    band_mapping[load2_reg] = 1;
    band_mapping[store1_reg] = 3;
    row = load2[0];
    col = load1[1];
    reduction = load2[1];
    }
    output = store1_reg;
    llvm::outs() << output << "\n";
      if (band_cnt == 1)
      {
        band1_mapping = band_mapping;
        output1 = output;
      }
      else if (band_cnt == 2){
        band2_mapping = band_mapping;
        output2 = output;
      }
      else{
        band3_mapping = band_mapping;
        output3 = output;
    }
    band_cnt++;
    // if the matmul loop is not row fisrt, then change it to row-column-reduction in the inner side

    std::string opString;
    llvm::raw_string_ostream ostream(opString);
    loop_affine->print(ostream);
    std::vector<std::string> registers;
    std::regex reg(R"(%\w+)");
    auto begin = std::sregex_iterator(opString.begin(), opString.end(), reg);
    auto end = std::sregex_iterator();
    int order_cnt = 0;
    int row_cnt, col_cnt, reduction_cnt;
    auto depth = band.size();
    for (auto it = begin; it != end; ++it)
    {
      if (order_cnt >= depth)
      {
        break;
      }
      if (it->str() == row)
      {
        row_cnt = order_cnt;
      }
      if (it->str() == col)
      {
        col_cnt = order_cnt;
      }
      if (it->str() == reduction)
      {
        reduction_cnt = order_cnt;
      }
      order_cnt++;
      registers.push_back(it->str());
      }
      unsigned perm[depth];
      int ind_true = 0;
      for (auto ind = 0; ind < depth; ind++)
      {
        if(ind == row_cnt || ind == col_cnt || ind == reduction_cnt){
          continue;
        }
        perm[ind_true]=ind;
        ind_true++;
      }
      perm[depth -3] = row_cnt;
      perm[depth -2] = col_cnt;
      perm[depth - 1] = reduction_cnt;

      ArrayRef<unsigned> permMap(perm, depth);
      auto newroot = band[permuteLoops(band, permMap)];
      band.clear();
      getLoopBandFromOutermost(newroot, band);
      band.resize(depth);
  }
  //reorder band1 and band2 according to band3
  if(band3_mapping[output1] == 1)
  {
    auto &band = bands[1];
    auto depth = band.size();
    unsigned perm[depth];
    for (auto ind = 0; ind < depth-3;ind++){
      perm[ind] = ind;
    }
    perm[depth -3] = depth -2;
    perm[depth -2] = depth -3;
    perm[depth - 1] = depth - 1;
    ArrayRef<unsigned> permMap(perm, depth);
    auto newroot = band[permuteLoops(band, permMap)];
    band.clear();
    getLoopBandFromOutermost(newroot, band);
    band.resize(3);
    // band[0].dump();
  }
  else
  {
    auto &band = bands[0];
    auto depth = band.size();
    unsigned perm[depth];
    for (auto ind = 0; ind < depth-3;ind++){
      perm[ind] = ind;
    }
    perm[depth -3] = depth -2;
    perm[depth -2] = depth -3;
    perm[depth - 1] = depth - 1;
    ArrayRef<unsigned> permMap(perm, depth);
    auto newroot = band[permuteLoops(band, permMap)];
    band.clear();
    getLoopBandFromOutermost(newroot, band);
    band.resize(3);
    // band[0].dump();
  }
}

/// TODO: support to pass in permutation map.

namespace {
struct AffineLoopReorder : public AffineLoopReorderBase<AffineLoopReorder> {
  void runOnOperation() override {
    // Collect all target loop bands.
    AffineLoopBands targetBands;
    getLoopBands(getOperation().front(), targetBands);
    auto func = getOperation();
    SmallVector<Operation*, 6> loopsToDelete;

    // find the solid activation layer
    std::vector<int> solid_ind;
    solid_ind.push_back(0);
    int ind = 0;
    for (auto &band : targetBands)
    {
      auto loop = band[0];

      llvm::outs() << loop->getName() << "\n";

      std::string opString;
      llvm::raw_string_ostream ostream(opString);

      loop->print(ostream);
      // llvm::outs() << opString << "\n";

      std::vector<std::string> registers;
      std::regex reg("arith\\.divf");
      auto begin = std::sregex_iterator(opString.begin(), opString.end(), reg);
      auto end = std::sregex_iterator();
      for (auto it = begin; it != end; ++it)
      {
        solid_ind.push_back(ind);
        break;
        // llvm::outs() << it->str() << "\n";
        // registers.push_back(it->str());
      }
      ind++;
      break;
    }
    // reorder the loop of each 3mm block
    for (auto block_ind = 0; block_ind < solid_ind.size();block_ind++){
      auto left = solid_ind[block_ind];
      auto right = (block_ind == solid_ind.size() - 1) ? targetBands.size() : solid_ind[block_ind + 1];
      llvm::outs()<<left<<"     "<<right<<"\n"; 
      AffineLoopBands three_mm_bands;
      for(int i = left; i<right;i++){
        three_mm_bands.push_back(targetBands[i]);
      }
      llvm::outs() << three_mm_bands.size()<<"\n";
      three_mm_loopreorder(three_mm_bands);

      auto &band = three_mm_bands[2];

      auto &loop_affine = band[0];
      llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;
      std::vector<int> buffer_dim1, buffer_dim2;
      int load_cnt=1;
      loop_affine.walk([&](Operation *op)
                       {
        if(auto loadOp = dyn_cast<affine::AffineLoadOp>(op)){
          loadOp.dump();
          MemRefType memRefType = loadOp.getMemRefType();
          auto memRef = loadOp.getMemRef();
          auto shape = memRef.getType().dyn_cast<MemRefType>().getShape();
          for(auto it=shape.begin();it!=shape.end();it++)
          {
            // llvm::outs() << *it << "\n";
            if(load_cnt==1)
              buffer_dim1.push_back((int)(*it));
            if(load_cnt==2)
              buffer_dim2.push_back((int)(*it));
          }
          load_cnt++;
          // shape.dump();
          // llvm::outs() << shape << "\n";
          loadOps.push_back(loadOp);
        }
        if(auto storeOp = dyn_cast<affine::AffineStoreOp>(op)){
          MemRefType memRefType = storeOp.getMemRefType();
          auto memRef = storeOp.getMemRef();
          storeOps.push_back(storeOp);
        } });

      // auto memRef = loadOps[0].getMemRef();
      // auto memRefType = memRef.getType();
      // mlir::OpBuilder builder(&context);

      // auto buffer1_ref = MemRefType::get({buffer_dim1[buffer_dim1.size()-2], buffer_dim1[buffer_dim1.size()-1]}, memRefType);
      // auto buffer2_ref = MemRefType::get({buffer_dim2[buffer_dim2.size()-2], buffer_dim2[buffer_dim2.size()-1]}, memRefType);

      // auto line_buffer1_ref = MemRefType::get({buffer_dim1[buffer_dim1.size()-1]}, memRefType);
      // auto line_buffer2_ref = MemRefType::get({buffer_dim2[buffer_dim2.size()-2]}, memRefType);

      // auto buffer1 = builder.create<memref::AllocaOp>(mlir::UnknownLoc::get(&context), buffer1_ref);
      // auto buffer2 = builder.create<memref::AllocaOp>(mlir::UnknownLoc::get(&context), buffer2_ref);
      // auto line_buffer1 = builder.create<memref::AllocaOp>(mlir::UnknownLoc::get(&context), line_buffer1_ref);
      // auto line_buffer2 = builder.create<memref::AllocaOp>(mlir::UnknownLoc::get(&context), line_buffer2_ref);

      // here three_mm_bands include three_mm block with size of 3
      // the matmul loop are the 3 most inner loops
      // TODO:  for the 3-th matmul loop: three_mm_bands[2] with depth = n+3 loop order is [dim 1]...[dim n][dim n+1][dim n+2][dim n+3],
      //  computation: C[dim 1]...[dim n][dim n+1][dim n+3] = A[dim 1]...[dim n][dim n+1][dim n+2] * B[dim 1]...[dim n][dim n+2][dim n+3]:
      //   1. create the reuse buffer buffer1[dim n+1][dim n+2], buffer1[dim n+2][dim n+3], 
      //    line_buffer1[dim n+2], line_buffer2[dim n+2]
      //   2. insert the outer loop after [dim n] with upperbound: max([dim n].upperbound, [dim n+1].upperbound)
      //      {
      //      3. insert buffer update: buffer1[outer][all] = A[dim 1]...[dim n][outer][all]; buffer2[all][outer] = A[dim 1]...[dim n][all][outer]
      //      linebuffer1[all] = A[dim 1]...[dim n][outer][all];  linebuffer2[all] = B[dim 1]...[dim n][all][outer];
      //      4. insert the inner loop with upperbound: outer 
      //          {
      //          5. insert the reduction loop: k: 1->dim n+2
      //            {
      //            insert  C[dim 1]...[dim n][inner][outer] += linebuffer2[k] * buffer1[outer][k]
      //            insert  C[dim 1]...[dim n][outer][inner] += linebuffer1[k] * buffer2[k][outer]
      //            }
      //          }
      //      6. insert the reduction loop: k: 1->dim n+2
      //            {
      //            insert  C[dim 1]...[dim n][outer][outer] += linebuffer2[k] * linebuffer1[k]
      //            }
      //     }

      //  insert 1-6 between loop [dim n] and loop [dim n+1], then erase loop [dim n+1],  [dim n+2], [dim n+3]
    }


    //





    
  }
};
} // namespace

std::unique_ptr<Pass> codo::createAffineLoopReorderPass() {
  return std::make_unique<AffineLoopReorder>();
}
