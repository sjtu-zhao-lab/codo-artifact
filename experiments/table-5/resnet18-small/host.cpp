/**
* Copyright (C) 2019-2021 Xilinx, Inc
*
* Licensed under the Apache License, Version 2.0 (the "License"). You may
* not use this file except in compliance with the License. A copy of the
* License is located at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations
* under the License.
*/
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

std::atomic<bool> keep_running(true);


void query_power(xrt::device &dev) {
    while (keep_running) {

        auto dev_info = dev.get_info<xrt::info::device::electrical>();

        auto bdf = dev.get_info<xrt::info::device::bdf>();
        std::cout << bdf << std::endl;


        std::regex watts_regex(R"(\"power_consumption_watts\"\s*:\s*\"([0-9.]+)\")");
        std::smatch matches;

        if (std::regex_search(dev_info, matches, watts_regex)) {
            std::string power_consumption_watts = matches[1];
            std::cout << "Power consumption (watts): " << power_consumption_watts << std::endl;
        }


        std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }
}


// HBM channels
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

    // Read settings
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    cl_int err;
    cl::Context context;
    cl::Kernel kernel;
    cl::CommandQueue q;

    xrt::device dev;

    auto devices = xcl::get_xil_devices();
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    bool valid_device = false;

    for (unsigned int i = 1; i < devices.size(); i++) {

        dev = xrt::device(i); 
        auto device = devices[i];
        auto device_name = device.getInfo<CL_DEVICE_NAME>();
    
        // Creating Context and Command Queue for selected Device
        OCL_CHECK(err, context = cl::Context(device, nullptr, nullptr, nullptr, &err));
        OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

        std::cout << "Trying to program device[" << i << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
        cl::Program program(context, {device}, bins, nullptr, &err);
        if (err != CL_SUCCESS) {
            std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
        } else {
            std::cout << "Device[" << i << "]: program successful!\n";
            OCL_CHECK(err, kernel = cl::Kernel(program, "main_graph", &err));
            valid_device = true;
            break; // we break because we found a valid device
        }
    }
    if (!valid_device) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }

    // Map the contents of the buffer object into host memory
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1012(96);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1013(1);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1014(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1015(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1016(4096);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1017(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1018(36864);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1019(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1020(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1021(1024);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1022(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1023(9216);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1024(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1025(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1026(256);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1027(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1028(2304);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1029(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1030(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1031(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1032(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1033(54);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1034(160);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1035(1);
    
    cl_mem_ext_ptr_t source_v1012_hbm;
    source_v1012_hbm.obj = source_v1012.data();
    source_v1012_hbm.param = 0;
    source_v1012_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v1013_hbm;
    source_v1013_hbm.obj = source_v1013.data();
    source_v1013_hbm.param = 0;
    source_v1013_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v1014_hbm;
    source_v1014_hbm.obj = source_v1014.data();
    source_v1014_hbm.param = 0;
    source_v1014_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v1015_hbm;
    source_v1015_hbm.obj = source_v1015.data();
    source_v1015_hbm.param = 0;
    source_v1015_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v1016_hbm;
    source_v1016_hbm.obj = source_v1016.data();
    source_v1016_hbm.param = 0;
    source_v1016_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v1017_hbm;
    source_v1017_hbm.obj = source_v1017.data();
    source_v1017_hbm.param = 0;
    source_v1017_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v1018_hbm;
    source_v1018_hbm.obj = source_v1018.data();
    source_v1018_hbm.param = 0;
    source_v1018_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v1019_hbm;
    source_v1019_hbm.obj = source_v1019.data();
    source_v1019_hbm.param = 0;
    source_v1019_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v1020_hbm;
    source_v1020_hbm.obj = source_v1020.data();
    source_v1020_hbm.param = 0;
    source_v1020_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v1021_hbm;
    source_v1021_hbm.obj = source_v1021.data();
    source_v1021_hbm.param = 0;
    source_v1021_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v1022_hbm;
    source_v1022_hbm.obj = source_v1022.data();
    source_v1022_hbm.param = 0;
    source_v1022_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v1023_hbm;
    source_v1023_hbm.obj = source_v1023.data();
    source_v1023_hbm.param = 0;
    source_v1023_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v1024_hbm;
    source_v1024_hbm.obj = source_v1024.data();
    source_v1024_hbm.param = 0;
    source_v1024_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v1025_hbm;
    source_v1025_hbm.obj = source_v1025.data();
    source_v1025_hbm.param = 0;
    source_v1025_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v1026_hbm;
    source_v1026_hbm.obj = source_v1026.data();
    source_v1026_hbm.param = 0;
    source_v1026_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v1027_hbm;
    source_v1027_hbm.obj = source_v1027.data();
    source_v1027_hbm.param = 0;
    source_v1027_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v1028_hbm;
    source_v1028_hbm.obj = source_v1028.data();
    source_v1028_hbm.param = 0;
    source_v1028_hbm.flags = HBM[16];
    
    
    cl_mem_ext_ptr_t source_v1029_hbm;
    source_v1029_hbm.obj = source_v1029.data();
    source_v1029_hbm.param = 0;
    source_v1029_hbm.flags = HBM[17];
    
    
    cl_mem_ext_ptr_t source_v1030_hbm;
    source_v1030_hbm.obj = source_v1030.data();
    source_v1030_hbm.param = 0;
    source_v1030_hbm.flags = HBM[18];
    
    
    cl_mem_ext_ptr_t source_v1031_hbm;
    source_v1031_hbm.obj = source_v1031.data();
    source_v1031_hbm.param = 0;
    source_v1031_hbm.flags = HBM[19];
    
    
    cl_mem_ext_ptr_t source_v1032_hbm;
    source_v1032_hbm.obj = source_v1032.data();
    source_v1032_hbm.param = 0;
    source_v1032_hbm.flags = HBM[20];
    
    
    cl_mem_ext_ptr_t source_v1033_hbm;
    source_v1033_hbm.obj = source_v1033.data();
    source_v1033_hbm.param = 0;
    source_v1033_hbm.flags = HBM[21];
    
    
    cl_mem_ext_ptr_t source_v1034_hbm;
    source_v1034_hbm.obj = source_v1034.data();
    source_v1034_hbm.param = 0;
    source_v1034_hbm.flags = HBM[22];
    
    
    cl_mem_ext_ptr_t source_v1035_hbm;
    source_v1035_hbm.obj = source_v1035.data();
    source_v1035_hbm.param = 0;
    source_v1035_hbm.flags = HBM[23];
    
OCL_CHECK(err, cl::Buffer v1012_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 96, &source_v1012_hbm, &err));
OCL_CHECK(err, cl::Buffer v1013_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1, &source_v1013_hbm, &err));
OCL_CHECK(err, cl::Buffer v1014_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v1014_hbm, &err));
OCL_CHECK(err, cl::Buffer v1015_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v1015_hbm, &err));
OCL_CHECK(err, cl::Buffer v1016_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4096, &source_v1016_hbm, &err));
OCL_CHECK(err, cl::Buffer v1017_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v1017_hbm, &err));
OCL_CHECK(err, cl::Buffer v1018_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 36864, &source_v1018_hbm, &err));
OCL_CHECK(err, cl::Buffer v1019_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v1019_hbm, &err));
OCL_CHECK(err, cl::Buffer v1020_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v1020_hbm, &err));
OCL_CHECK(err, cl::Buffer v1021_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1024, &source_v1021_hbm, &err));
OCL_CHECK(err, cl::Buffer v1022_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v1022_hbm, &err));
OCL_CHECK(err, cl::Buffer v1023_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 9216, &source_v1023_hbm, &err));
OCL_CHECK(err, cl::Buffer v1024_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v1024_hbm, &err));
OCL_CHECK(err, cl::Buffer v1025_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v1025_hbm, &err));
OCL_CHECK(err, cl::Buffer v1026_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 256, &source_v1026_hbm, &err));
OCL_CHECK(err, cl::Buffer v1027_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v1027_hbm, &err));
OCL_CHECK(err, cl::Buffer v1028_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 2304, &source_v1028_hbm, &err));
OCL_CHECK(err, cl::Buffer v1029_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1029_hbm, &err));
OCL_CHECK(err, cl::Buffer v1030_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1030_hbm, &err));
OCL_CHECK(err, cl::Buffer v1031_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1031_hbm, &err));
OCL_CHECK(err, cl::Buffer v1032_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1032_hbm, &err));
OCL_CHECK(err, cl::Buffer v1033_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 54, &source_v1033_hbm, &err));
OCL_CHECK(err, cl::Buffer v1034_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 160, &source_v1034_hbm, &err));
OCL_CHECK(err, cl::Buffer v1035_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1, &source_v1035_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v1012_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v1013_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v1014_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v1015_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v1016_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v1017_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v1018_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v1019_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v1020_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v1021_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v1022_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v1023_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v1024_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v1025_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v1026_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v1027_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v1028_buf));
    OCL_CHECK(err, err = kernel.setArg(17, v1029_buf));
    OCL_CHECK(err, err = kernel.setArg(18, v1030_buf));
    OCL_CHECK(err, err = kernel.setArg(19, v1031_buf));
    OCL_CHECK(err, err = kernel.setArg(20, v1032_buf));
    OCL_CHECK(err, err = kernel.setArg(21, v1033_buf));
    OCL_CHECK(err, err = kernel.setArg(22, v1034_buf));
    OCL_CHECK(err, err = kernel.setArg(23, v1035_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v1012_buf, 
v1013_buf, 
v1014_buf, 
v1015_buf, 
v1016_buf, 
v1017_buf, 
v1018_buf, 
v1019_buf, 
v1020_buf, 
v1021_buf, 
v1022_buf, 
v1023_buf, 
v1024_buf, 
v1025_buf, 
v1026_buf, 
v1027_buf, 
v1028_buf, 
v1029_buf, 
v1030_buf, 
v1031_buf, 
v1032_buf, 
v1033_buf, 
v1034_buf, 
v1035_buf, 
}, 0 /* from host */));


    OCL_CHECK(err, err = q.finish());
    std::cout << "Data transfer done" << std::endl;
    std::thread power_thread(query_power, std::ref(dev));
    std::chrono::high_resolution_clock::time_point kStart = std::chrono::high_resolution_clock::now();
    std::cout << "Launching Kernel..." << std::endl;
    OCL_CHECK(err, err = q.enqueueTask(kernel));
    OCL_CHECK(err, err = q.finish());
    std::cout << "Kernel execution done" << std::endl;
    std::chrono::high_resolution_clock::time_point kEnd = std::chrono::high_resolution_clock::now();
    cl_ulong totalTime = std::chrono::duration_cast<std::chrono::microseconds>(kEnd - kStart).count();
    keep_running = false;
    
    power_thread.join();
    std::cout << std::fixed << std::setprecision(2) << std::setw(8) << totalTime<< std::endl;


    std::cout << "Getting Results..." << std::endl;
    // OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v1263_buf}, CL_MIGRATE_MEM_OBJECT_HOST));

    // OCL_CHECK(err, err = q.finish());
    std::cout << "Data read done" << std::endl;

    std::cout << "TEST " << "PASSED" << std::endl;
    return EXIT_SUCCESS;
}
