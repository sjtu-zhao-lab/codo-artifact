//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

// --- Adder Tree Helper Template ---
template<typename T, int N>
T adder_tree(T inputs[N]) {
    #pragma HLS INLINE
    T stage[N];
    #pragma HLS ARRAY_PARTITION variable=stage complete dim=1

    for (int i = 0; i < N; i++) {
        #pragma HLS UNROLL
        stage[i] = inputs[i];
    }

    int current_size = N;
    while (current_size > 1) {
        int next_size = (current_size + 1) / 2;
        for (int i = 0; i < next_size; i++) {
            #pragma HLS UNROLL
            if (i * 2 + 1 < current_size) {
                stage[i] = stage[i * 2] + stage[i * 2 + 1];
            } else {
                stage[i] = stage[i * 2];
            }
        }
        current_size = next_size;
    }
    return stage[0];
}

void main_graph_node0(
  float v0[1][64][112][112],
  float v1[64][64][1][1],
  float v2[1][64][112][112]
) {
  #pragma HLS dataflow

  float v3[1][64][112][112];
  #pragma HLS stream variable=v3 depth=10 type=fifo
  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  float v4[1][64][1][112];
  #pragma HLS array_partition variable=v4 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v4 type=ram_2p impl=bram

  float v5[1][64][1][1];
  #pragma HLS array_partition variable=v5 complete dim=2 // 修改：完全拆分以便加法树并行访问
  #pragma HLS bind_storage variable=v5 type=ram_2p impl=lutram

  for (int v6 = 0; v6 < 1; v6 += 1) {
    for (int v7 = 0; v7 < 112; v7 += 1) {
      for (int v8 = 0; v8 < 112; v8 += 1) {
        // --- 数据搬运到本地 ---
        for (int v9 = 0; v9 < 16; v9 += 1) {
          #pragma HLS pipeline II=1
          for (int v10 = 0; v10 < 4; v10 += 1) {
            #pragma HLS UNROLL
            v4[v6][(v10 + (v9 * 4))][0][v8] = v0[v6][(v10 + (v9 * 4))][v7][v8];
          }
        }

        if (v7 >= 0) {
          for (int v12 = 0; v12 < 16; v12 += 1) {
            #pragma HLS pipeline II=1
            for (int v13 = 0; v13 < 4; v13 += 1) {
              #pragma HLS UNROLL
              v5[v6][(v13 + (v12 * 4))][0][0] = v4[v6][(v13 + (v12 * 4))][0][v8];
            }
          }

          if (v8 >= 0) {
            // --- 使用加法树重构 Pointwise 卷积 ---
            for (int v17 = 0; v17 < 64; v17 += 1) {
              #pragma HLS pipeline II=1
              
              const int REDUCTION_SIZE = 64;
              float products[REDUCTION_SIZE];
              #pragma HLS ARRAY_PARTITION variable=products complete

              Generate_Prods_Node0:
              for (int v19 = 0; v19 < 64; v19 += 1) {
                #pragma HLS UNROLL
                // v18, v20, v21 在原始代码中均为 1，此处直接展开 64 个通道
                float v22 = v5[v6][v19][0][0];
                float v23 = v1[v17][v19][0][0];
                products[v19] = v22 * v23;
              }

              // 调用加法树
              v3[v6][v17][v7][v8] = adder_tree<float, REDUCTION_SIZE>(products);
            }
          }
        }
      }
    }
  }

  // --- ReLU & Scaling ---
  for (int v28 = 0; v28 < 1; v28 += 1) {
    for (int v29 = 0; v29 < 112; v29 += 1) {
      for (int v30 = 0; v30 < 112; v30 += 1) {
        #pragma HLS pipeline II=1
        for (int v31 = 0; v31 < 64; v31 += 1) {
          #pragma HLS UNROLL factor=4
          float v32 = v3[0][v31][v29][v30];
          float v35 = 0.999995; // 1/sqrt(1.00001) 的近似值
          float v37 = v32 * v35;
          v2[v28][v31][v29][v30] = (v37 > 0.0f) ? v37 : 0.0f;
        }
      }
    }
  }
}

void main_graph_node1(
  float v40[1][64][112][112],
  float v41[64][3][3],
  float v42[1][64][112][112]
) {
  #pragma HLS dataflow

  float v43[1][64][114][114];
  #pragma HLS stream variable=v43 depth=10 type=fifo
  #pragma HLS bind_storage variable=v43 type=ram_t2p impl=bram

  // Padding 逻辑
  for (int v44 = 0; v44 < 1; v44 += 1) {
    for (int v45 = 0; v45 < 114; v45 += 1) {
      for (int v46 = 0; v46 < 114; v46 += 1) {
        #pragma HLS pipeline II=1
        for (int v47 = 0; v47 < 64; v47 += 1) {
          #pragma HLS UNROLL factor=8
          float v48 = 0.0f;
          if (v45 < 112 && v46 < 112) {
            v48 = v40[v44][v47][v45][v46];
          }
          v43[v44][v47][v45][v46] = v48;
        }
      }
    }
  }

  float v51[1][64][3][114];
  #pragma HLS array_partition variable=v51 complete dim=3
  #pragma HLS bind_storage variable=v51 type=ram_2p impl=bram

  float v52[1][64][3][3];
  #pragma HLS array_partition variable=v52 complete dim=3
  #pragma HLS array_partition variable=v52 complete dim=4
  #pragma HLS bind_storage variable=v52 type=ram_2p impl=lutram

  for (int v53 = 0; v53 < 1; v53 += 1) {
    for (int v54 = 0; v54 < 114; v54 += 1) {
      for (int v55 = 0; v55 < 114; v55 += 1) {
        // Line Buffer 更新
        for (int v56 = 0; v56 < 64; v56 += 1) {
          #pragma HLS pipeline II=1
          v51[v53][v56][0][v55] = v51[v53][v56][1][v55];
          v51[v53][v56][1][v55] = v51[v53][v56][2][v55];
          v51[v53][v56][2][v55] = v43[v53][v56][v54][v55];
        }

        if (v54 >= 2) {
          // Window 更新
          for (int v60 = 0; v60 < 64; v60 += 1) {
            #pragma HLS pipeline II=1
            for (int v61 = 0; v61 < 3; v61 += 1) {
              #pragma HLS UNROLL
              v52[v53][v60][v61][0] = v52[v53][v60][v61][1];
              v52[v53][v60][v61][1] = v52[v53][v60][v61][2];
              v52[v53][v60][v61][2] = v51[v53][v60][v61][v55];
            }
          }

          if (v55 >= 2) {
            // --- 使用加法树重构 3x3 Depthwise 卷积 ---
            for (int v66 = 0; v66 < 16; v66 += 1) {
              #pragma HLS pipeline II=1
              for (int v67 = 0; v67 < 4; v67 += 1) {
                #pragma HLS UNROLL
                
                const int KERNEL_SIZE = 9;
                float products[KERNEL_SIZE];
                #pragma HLS ARRAY_PARTITION variable=products complete
                
                int curr_ch = (v67 + (v66 * 4));
                
                Generate_Prods_Node1:
                for (int i = 0; i < 9; i++) {
                  #pragma HLS UNROLL
                  int r = i / 3;
                  int c = i % 3;
                  products[i] = v52[v53][curr_ch][r][c] * v41[curr_ch][r][c];
                }

                v42[v53][curr_ch][v54-2][v55-2] = adder_tree<float, KERNEL_SIZE>(products);
              }
            }
          }
        }
      }
    }
  }
}

void main_graph(
  float v76[1][64][112][112],
  float v77[64][64][1][1],
  float v78[64][3][3],
  float v79[1][64][112][112]
) {
  #pragma HLS interface bram port=v76
  #pragma HLS interface bram port=v77
  #pragma HLS interface bram port=v78
  #pragma HLS interface bram port=v79
  #pragma HLS interface s_axilite port=return bundle=ctrl

  // 必须对参与加法树的数组维度进行 Partition
  #pragma HLS array_partition variable=v77 complete dim=2
  #pragma HLS array_partition variable=v78 complete dim=2
  #pragma HLS array_partition variable=v78 complete dim=3

  #pragma HLS dataflow

  float v80[1][64][112][112];
  #pragma HLS stream variable=v80 depth=10 type=fifo
  #pragma HLS array_partition variable=v80 cyclic factor=4 dim=2

  main_graph_node1(v76, v78, v80);
  main_graph_node0(v80, v77, v79);
}