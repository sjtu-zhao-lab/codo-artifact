
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
      std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v834(32*128);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v835_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v835_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v836(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v837(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v838(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v839(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v840(128);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v841(32);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v842_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v842_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v843_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v843_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v844_1(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v844_2(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v845_1(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v845_2(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v845_3(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v845_4(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v846_1(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v846_2(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v846_3(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v846_4(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v847(32*128);
    
    cl_mem_ext_ptr_t source_v834_hbm;
    source_v834_hbm.obj = source_v834.data();
    source_v834_hbm.param = 0;
    source_v834_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v835_1_hbm;
    source_v835_1_hbm.obj = source_v835_1.data();
    source_v835_1_hbm.param = 0;
    source_v835_1_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v835_2_hbm;
    source_v835_2_hbm.obj = source_v835_2.data();
    source_v835_2_hbm.param = 0;
    source_v835_2_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v836_hbm;
    source_v836_hbm.obj = source_v836.data();
    source_v836_hbm.param = 0;
    source_v836_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v837_hbm;
    source_v837_hbm.obj = source_v837.data();
    source_v837_hbm.param = 0;
    source_v837_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v838_hbm;
    source_v838_hbm.obj = source_v838.data();
    source_v838_hbm.param = 0;
    source_v838_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v839_hbm;
    source_v839_hbm.obj = source_v839.data();
    source_v839_hbm.param = 0;
    source_v839_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v840_hbm;
    source_v840_hbm.obj = source_v840.data();
    source_v840_hbm.param = 0;
    source_v840_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v841_hbm;
    source_v841_hbm.obj = source_v841.data();
    source_v841_hbm.param = 0;
    source_v841_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v842_1_hbm;
    source_v842_1_hbm.obj = source_v842_1.data();
    source_v842_1_hbm.param = 0;
    source_v842_1_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v842_2_hbm;
    source_v842_2_hbm.obj = source_v842_2.data();
    source_v842_2_hbm.param = 0;
    source_v842_2_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v843_1_hbm;
    source_v843_1_hbm.obj = source_v843_1.data();
    source_v843_1_hbm.param = 0;
    source_v843_1_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v843_2_hbm;
    source_v843_2_hbm.obj = source_v843_2.data();
    source_v843_2_hbm.param = 0;
    source_v843_2_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v844_1_hbm;
    source_v844_1_hbm.obj = source_v844_1.data();
    source_v844_1_hbm.param = 0;
    source_v844_1_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v844_2_hbm;
    source_v844_2_hbm.obj = source_v844_2.data();
    source_v844_2_hbm.param = 0;
    source_v844_2_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v845_1_hbm;
    source_v845_1_hbm.obj = source_v845_1.data();
    source_v845_1_hbm.param = 0;
    source_v845_1_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v845_2_hbm;
    source_v845_2_hbm.obj = source_v845_2.data();
    source_v845_2_hbm.param = 0;
    source_v845_2_hbm.flags = HBM[16];
    
    
    cl_mem_ext_ptr_t source_v845_3_hbm;
    source_v845_3_hbm.obj = source_v845_3.data();
    source_v845_3_hbm.param = 0;
    source_v845_3_hbm.flags = HBM[17];
    
    
    cl_mem_ext_ptr_t source_v845_4_hbm;
    source_v845_4_hbm.obj = source_v845_4.data();
    source_v845_4_hbm.param = 0;
    source_v845_4_hbm.flags = HBM[18];
    
    
    cl_mem_ext_ptr_t source_v846_1_hbm;
    source_v846_1_hbm.obj = source_v846_1.data();
    source_v846_1_hbm.param = 0;
    source_v846_1_hbm.flags = HBM[19];
    
    
    cl_mem_ext_ptr_t source_v846_2_hbm;
    source_v846_2_hbm.obj = source_v846_2.data();
    source_v846_2_hbm.param = 0;
    source_v846_2_hbm.flags = HBM[20];
    
    
    cl_mem_ext_ptr_t source_v846_3_hbm;
    source_v846_3_hbm.obj = source_v846_3.data();
    source_v846_3_hbm.param = 0;
    source_v846_3_hbm.flags = HBM[21];
    
    
    cl_mem_ext_ptr_t source_v846_4_hbm;
    source_v846_4_hbm.obj = source_v846_4.data();
    source_v846_4_hbm.param = 0;
    source_v846_4_hbm.flags = HBM[22];
    
    
    cl_mem_ext_ptr_t source_v847_hbm;
    source_v847_hbm.obj = source_v847.data();
    source_v847_hbm.param = 0;
    source_v847_hbm.flags = HBM[23];
    
OCL_CHECK(err, cl::Buffer v834_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32 *128, &source_v834_hbm, &err));
OCL_CHECK(err, cl::Buffer v835_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v835_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v835_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v835_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v836_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v836_hbm, &err));
OCL_CHECK(err, cl::Buffer v837_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v837_hbm, &err));
OCL_CHECK(err, cl::Buffer v838_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v838_hbm, &err));
OCL_CHECK(err, cl::Buffer v839_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v839_hbm, &err));
OCL_CHECK(err, cl::Buffer v840_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 128, &source_v840_hbm, &err));
OCL_CHECK(err, cl::Buffer v841_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32, &source_v841_hbm, &err));
OCL_CHECK(err, cl::Buffer v842_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v842_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v842_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v842_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v843_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v843_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v843_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v843_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v844_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v844_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v844_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v844_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v845_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v845_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v845_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v845_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v845_3_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v845_3_hbm, &err));
OCL_CHECK(err, cl::Buffer v845_4_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v845_4_hbm, &err));
OCL_CHECK(err, cl::Buffer v846_1_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v846_1_hbm, &err));
OCL_CHECK(err, cl::Buffer v846_2_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v846_2_hbm, &err));
OCL_CHECK(err, cl::Buffer v846_3_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v846_3_hbm, &err));
OCL_CHECK(err, cl::Buffer v846_4_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v846_4_hbm, &err));
OCL_CHECK(err, cl::Buffer v847_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32*128, &source_v847_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v834_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v835_1_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v835_2_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v836_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v837_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v838_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v839_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v840_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v841_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v842_1_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v842_2_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v843_1_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v843_2_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v844_1_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v844_2_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v845_1_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v845_2_buf));
    OCL_CHECK(err, err = kernel.setArg(17, v845_3_buf));
    OCL_CHECK(err, err = kernel.setArg(18, v845_4_buf));
    OCL_CHECK(err, err = kernel.setArg(19, v846_1_buf));
    OCL_CHECK(err, err = kernel.setArg(20, v846_2_buf));
    OCL_CHECK(err, err = kernel.setArg(21, v846_3_buf));
    OCL_CHECK(err, err = kernel.setArg(22, v846_4_buf));
    OCL_CHECK(err, err = kernel.setArg(23, v847_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v834_buf, 
v835_1_buf, 
v835_2_buf, 
v836_buf, 
v837_buf, 
v838_buf, 
v839_buf, 
v840_buf, 
v841_buf, 
v842_1_buf, 
v842_2_buf, 
v843_1_buf, 
v843_2_buf, 
v844_1_buf, 
v844_2_buf, 
v845_1_buf, 
v845_2_buf, 
v845_3_buf, 
v845_4_buf, 
v846_1_buf, 
v846_2_buf, 
v846_3_buf, 
v846_4_buf, 
v847_buf
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
