
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for Vitis Host.
//
//===----------------------------------------------------------------------===//

#include "xcl2.hpp"
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <unistd.h>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>

using std::vector;


#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
#include <regex>
#include <thread>
#include <atomic>

#define MAX_HBM_CHANNEL_COUNT 32
#define CHANNEL_NAME(n) n | XCL_MEM_TOPOLOGY
const int HBM[MAX_HBM_CHANNEL_COUNT] = {
    CHANNEL_NAME(0),  CHANNEL_NAME(1),  CHANNEL_NAME(2),  CHANNEL_NAME(3),  CHANNEL_NAME(4),
    CHANNEL_NAME(5),  CHANNEL_NAME(6),  CHANNEL_NAME(7),  CHANNEL_NAME(8),  CHANNEL_NAME(9),
    CHANNEL_NAME(10), CHANNEL_NAME(11), CHANNEL_NAME(12), CHANNEL_NAME(13), CHANNEL_NAME(14),
    CHANNEL_NAME(15), CHANNEL_NAME(16), CHANNEL_NAME(17), CHANNEL_NAME(18), CHANNEL_NAME(19),
    CHANNEL_NAME(20), CHANNEL_NAME(21), CHANNEL_NAME(22), CHANNEL_NAME(23), CHANNEL_NAME(24),
    CHANNEL_NAME(25), CHANNEL_NAME(26), CHANNEL_NAME(27), CHANNEL_NAME(28), CHANNEL_NAME(29),
    CHANNEL_NAME(30), CHANNEL_NAME(31)};

const int DDR[2] = {CHANNEL_NAME(32), CHANNEL_NAME(33)};

  int main(int argc, char** argv) {

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    cl_int err;
    cl::Context context;
    cl::CommandQueue q;
    cl::Kernel kernel;
    cl::Program program;

    auto devices = xcl::get_xil_devices();
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    bool valid_device = false;
    
    for (unsigned int i = 0; i < devices.size(); i++) {
        // for (auto device : devices) {
        auto device = devices[i];
        // Creating Context and Command Queue for selected Device
        OCL_CHECK(err, context = cl::Context(device, nullptr, nullptr, nullptr, &err));
        OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
        std::cout << "Trying to program device[" << i << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
        OCL_CHECK(err, program = cl::Program(context, {device}, bins, nullptr, &err));
        if (err != CL_SUCCESS) {
            std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
        } else {
            std::cout << "Device[" << i << "]: program successful!\n";
            valid_device = true;
    
            OCL_CHECK(err, kernel = cl::Kernel(program, "main_graph", &err));
            break; // we break because we found a valid device
        }
    }
    if (!valid_device) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }
    // Allocate Memory in Host Memory

    // void query_power(xrt::device &dev) {
    //     while (keep_running) {
    //         auto dev_info = dev.get_info<xrt::info::device::electrical>();

    //         auto bdf = dev.get_info<xrt::info::device::bdf>();
    //         std::cout << bdf << std::endl;

    //         std::regex watts_regex(R"%%(\"power_consumption_watts\"\s*:\s*\"([0-9.]+)\")%%");
    //         std::smatch matches;

    //         if (std::regex_search(dev_info, matches, watts_regex)) {
    //             std::string power_consumption_watts = matches[1];
    //             std::cout << "Power consumption (watts): " << power_consumption_watts << std::endl;
    //         }
    //         std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    //     }
    // }  
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v840(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v841_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v841_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v842(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v843(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v844(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v845(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v846(128);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v847(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v848_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v848_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v849_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v849_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v850_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v850_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_3(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_4(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_5(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_6(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_7(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v851_8(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_3(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_4(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_5(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_6(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_7(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v852_8(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v853(32);
    
    cl_mem_ext_ptr_t source_v840_hbm;
    source_v840_hbm.obj = source_v840.data();
    source_v840_hbm.param = 0;
    source_v840_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v841_1_hbm;
    source_v841_1_hbm.obj = source_v841_1.data();
    source_v841_1_hbm.param = 0;
    source_v841_1_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v841_2_hbm;
    source_v841_2_hbm.obj = source_v841_2.data();
    source_v841_2_hbm.param = 0;
    source_v841_2_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v842_hbm;
    source_v842_hbm.obj = source_v842.data();
    source_v842_hbm.param = 0;
    source_v842_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v843_hbm;
    source_v843_hbm.obj = source_v843.data();
    source_v843_hbm.param = 0;
    source_v843_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v844_hbm;
    source_v844_hbm.obj = source_v844.data();
    source_v844_hbm.param = 0;
    source_v844_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v845_hbm;
    source_v845_hbm.obj = source_v845.data();
    source_v845_hbm.param = 0;
    source_v845_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v846_hbm;
    source_v846_hbm.obj = source_v846.data();
    source_v846_hbm.param = 0;
    source_v846_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v847_hbm;
    source_v847_hbm.obj = source_v847.data();
    source_v847_hbm.param = 0;
    source_v847_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v848_1_hbm;
    source_v848_1_hbm.obj = source_v848_1.data();
    source_v848_1_hbm.param = 0;
    source_v848_1_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v848_2_hbm;
    source_v848_2_hbm.obj = source_v848_2.data();
    source_v848_2_hbm.param = 0;
    source_v848_2_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v849_1_hbm;
    source_v849_1_hbm.obj = source_v849_1.data();
    source_v849_1_hbm.param = 0;
    source_v849_1_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v849_2_hbm;
    source_v849_2_hbm.obj = source_v849_2.data();
    source_v849_2_hbm.param = 0;
    source_v849_2_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v850_1_hbm;
    source_v850_1_hbm.obj = source_v850_1.data();
    source_v850_1_hbm.param = 0;
    source_v850_1_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v850_2_hbm;
    source_v850_2_hbm.obj = source_v850_2.data();
    source_v850_2_hbm.param = 0;
    source_v850_2_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v851_1_hbm;
    source_v851_1_hbm.obj = source_v851_1.data();
    source_v851_1_hbm.param = 0;
    source_v851_1_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v851_2_hbm;
    source_v851_2_hbm.obj = source_v851_2.data();
    source_v851_2_hbm.param = 0;
    source_v851_2_hbm.flags = HBM[16];
    
    
    cl_mem_ext_ptr_t source_v851_3_hbm;
    source_v851_3_hbm.obj = source_v851_3.data();
    source_v851_3_hbm.param = 0;
    source_v851_3_hbm.flags = HBM[17];
    
    
    cl_mem_ext_ptr_t source_v851_4_hbm;
    source_v851_4_hbm.obj = source_v851_4.data();
    source_v851_4_hbm.param = 0;
    source_v851_4_hbm.flags = HBM[18];
    
    
    cl_mem_ext_ptr_t source_v851_5_hbm;
    source_v851_5_hbm.obj = source_v851_5.data();
    source_v851_5_hbm.param = 0;
    source_v851_5_hbm.flags = HBM[19];
    
    
    cl_mem_ext_ptr_t source_v851_6_hbm;
    source_v851_6_hbm.obj = source_v851_6.data();
    source_v851_6_hbm.param = 0;
    source_v851_6_hbm.flags = HBM[20];
    
    
    cl_mem_ext_ptr_t source_v851_7_hbm;
    source_v851_7_hbm.obj = source_v851_7.data();
    source_v851_7_hbm.param = 0;
    source_v851_7_hbm.flags = HBM[21];
    
    
    cl_mem_ext_ptr_t source_v851_8_hbm;
    source_v851_8_hbm.obj = source_v851_8.data();
    source_v851_8_hbm.param = 0;
    source_v851_8_hbm.flags = HBM[22];
    
    
    cl_mem_ext_ptr_t source_v852_1_hbm;
    source_v852_1_hbm.obj = source_v852_1.data();
    source_v852_1_hbm.param = 0;
    source_v852_1_hbm.flags = HBM[23];
    
    
    cl_mem_ext_ptr_t source_v852_2_hbm;
    source_v852_2_hbm.obj = source_v852_2.data();
    source_v852_2_hbm.param = 0;
    source_v852_2_hbm.flags = HBM[24];
    
    
    cl_mem_ext_ptr_t source_v852_3_hbm;
    source_v852_3_hbm.obj = source_v852_3.data();
    source_v852_3_hbm.param = 0;
    source_v852_3_hbm.flags = HBM[25];
    
    
    cl_mem_ext_ptr_t source_v852_4_hbm;
    source_v852_4_hbm.obj = source_v852_4.data();
    source_v852_4_hbm.param = 0;
    source_v852_4_hbm.flags = HBM[26];
    
    
    cl_mem_ext_ptr_t source_v852_5_hbm;
    source_v852_5_hbm.obj = source_v852_5.data();
    source_v852_5_hbm.param = 0;
    source_v852_5_hbm.flags = HBM[27];
    
    
    cl_mem_ext_ptr_t source_v852_6_hbm;
    source_v852_6_hbm.obj = source_v852_6.data();
    source_v852_6_hbm.param = 0;
    source_v852_6_hbm.flags = HBM[28];
    
    
    cl_mem_ext_ptr_t source_v852_7_hbm;
    source_v852_7_hbm.obj = source_v852_7.data();
    source_v852_7_hbm.param = 0;
    source_v852_7_hbm.flags = HBM[29];
    
    
    cl_mem_ext_ptr_t source_v852_8_hbm;
    source_v852_8_hbm.obj = source_v852_8.data();
    source_v852_8_hbm.param = 0;
    source_v852_8_hbm.flags = HBM[30];
    
    
    cl_mem_ext_ptr_t source_v853_hbm;
    source_v853_hbm.obj = source_v853.data();
    source_v853_hbm.param = 0;
    source_v853_hbm.flags = HBM[31];
    
OCL_CHECK(err, cl::Buffer v840_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v840_hbm, &err));
OCL_CHECK(err, cl::Buffer v841_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v841_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v841_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v841_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v842_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v842_hbm, &err));
OCL_CHECK(err, cl::Buffer v843_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v843_hbm, &err));
OCL_CHECK(err, cl::Buffer v844_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v844_hbm, &err));
OCL_CHECK(err, cl::Buffer v845_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v845_hbm, &err));
OCL_CHECK(err, cl::Buffer v846_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 128, &source_v846_hbm, &err));
OCL_CHECK(err, cl::Buffer v847_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v847_hbm, &err));
OCL_CHECK(err, cl::Buffer v848_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v848_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v848_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v848_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v849_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v849_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v849_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v849_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v850_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v850_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v850_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v850_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_3_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_3_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_4_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_4_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_5_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_5_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_6_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_6_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_7_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_7_hbm, &err));
OCL_CHECK(err, cl::Buffer v851_8_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v851_8_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_3_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_3_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_4_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_4_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_5_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_5_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_6_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_6_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_7_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_7_hbm, &err));
OCL_CHECK(err, cl::Buffer v852_8_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v852_8_hbm, &err));
OCL_CHECK(err, cl::Buffer v853_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v853_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v840_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v841_1_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v841_2_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v842_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v843_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v844_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v845_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v846_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v847_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v848_1_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v848_2_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v849_1_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v849_2_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v850_1_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v850_2_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v851_1_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v851_2_buf));
    OCL_CHECK(err, err = kernel.setArg(17, v851_3_buf));
    OCL_CHECK(err, err = kernel.setArg(18, v851_4_buf));
    OCL_CHECK(err, err = kernel.setArg(19, v851_5_buf));
    OCL_CHECK(err, err = kernel.setArg(20, v851_6_buf));
    OCL_CHECK(err, err = kernel.setArg(21, v851_7_buf));
    OCL_CHECK(err, err = kernel.setArg(22, v851_8_buf));
    OCL_CHECK(err, err = kernel.setArg(23, v852_1_buf));
    OCL_CHECK(err, err = kernel.setArg(24, v852_2_buf));
    OCL_CHECK(err, err = kernel.setArg(25, v852_3_buf));
    OCL_CHECK(err, err = kernel.setArg(26, v852_4_buf));
    OCL_CHECK(err, err = kernel.setArg(27, v852_5_buf));
    OCL_CHECK(err, err = kernel.setArg(28, v852_6_buf));
    OCL_CHECK(err, err = kernel.setArg(29, v852_7_buf));
    OCL_CHECK(err, err = kernel.setArg(30, v852_8_buf));
    OCL_CHECK(err, err = kernel.setArg(31, v853_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v840_buf, 
v841_1_buf, 
v841_2_buf, 
v842_buf, 
v843_buf, 
v844_buf, 
v845_buf, 
v846_buf, 
v847_buf, 
v848_1_buf, 
v848_2_buf, 
v849_1_buf, 
v849_2_buf, 
v850_1_buf, 
v850_2_buf, 
v851_1_buf, 
v851_2_buf, 
v851_3_buf, 
v851_4_buf, 
v851_5_buf, 
v851_6_buf, 
v851_7_buf, 
v851_8_buf, 
v852_1_buf, 
v852_2_buf, 
v852_3_buf, 
v852_4_buf, 
v852_5_buf, 
v852_6_buf, 
v852_7_buf, 
v852_8_buf, 
v853_buf
}, 0 /* from host */));










    cl::Event event;
    uint64_t nstimestart, nstimeend;
    std::cout << "|-------------------------+-------------------------|"
              << "| Kernel                  |    Wall-Clock Time (ns) |"
              << "|-------------------------+-------------------------|";

    // Launch the Kernel
    OCL_CHECK(err, err = q.enqueueTask(kernel, nullptr, &event));
    // Copy Result from Device Global Memory to Host Local Memory
    // OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v848_buf}, CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();

    // Get the execution time
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START, &nstimestart));
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END, &nstimeend));
    auto exe_time = nstimeend - nstimestart;std::cout << "| " << std::left << std::setw(24) << "main_graph "
              << "|" << std::right << std::setw(24) << exe_time << " |\n";

    std::cout << "|-------------------------+-------------------------|";
    std::cout << "Note: Wall Clock Time is meaningful for real hardware execution << only, not for emulation.";
    std::cout << "Please refer to profile summary for kernel execution time for << hardware emulation.";
    std::cout << "TEST PASSED";
    return EXIT_SUCCESS;
}
