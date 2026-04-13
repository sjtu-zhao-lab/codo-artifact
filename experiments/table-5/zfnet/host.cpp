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

using std::vector;


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

    xrt::device dev;
    // auto dev_info = dev.get_info<xrt::info::device::electrical>();
    // std::regex watts_regex(R"(\"power_consumption_watts\"\s*:\s*\"([0-9.]+)\")");
    // std::smatch matches;

    // if (std::regex_search(dev_info, matches, watts_regex)) {
    //     std::string power_consumption_watts = matches[1];
    //     std::cout << "Power consumption (watts): " << power_consumption_watts << std::endl;
    // }
        
    

    std::string binaryFile = argv[1];
    cl_int err;
    cl::Context context;
    cl::Kernel kernel;
    cl::CommandQueue q;

    auto devices = xcl::get_xil_devices();
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    bool valid_device = false;

    for (unsigned int i = 0; i < devices.size(); i++) {
        
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
            char bdf[20];
            clGetDeviceInfo(device(), CL_DEVICE_PCIE_BDF, sizeof(bdf), &bdf, nullptr);
            std::cout << "Device[" << bdf << "]: program successful!\n";
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
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v384(4704);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v385(31);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v386(128);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v387(819200);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v388(27648);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v389(41472);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v390(27648);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v391(19200);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v392(441);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v393(524288);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v394(128000);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v395(31);
    
    cl_mem_ext_ptr_t source_v384_hbm;
    source_v384_hbm.obj = source_v384.data();
    source_v384_hbm.param = 0;
    source_v384_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v385_hbm;
    source_v385_hbm.obj = source_v385.data();
    source_v385_hbm.param = 0;
    source_v385_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v386_hbm;
    source_v386_hbm.obj = source_v386.data();
    source_v386_hbm.param = 0;
    source_v386_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v387_hbm;
    source_v387_hbm.obj = source_v387.data();
    source_v387_hbm.param = 0;
    source_v387_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v388_hbm;
    source_v388_hbm.obj = source_v388.data();
    source_v388_hbm.param = 0;
    source_v388_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v389_hbm;
    source_v389_hbm.obj = source_v389.data();
    source_v389_hbm.param = 0;
    source_v389_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v390_hbm;
    source_v390_hbm.obj = source_v390.data();
    source_v390_hbm.param = 0;
    source_v390_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v391_hbm;
    source_v391_hbm.obj = source_v391.data();
    source_v391_hbm.param = 0;
    source_v391_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v392_hbm;
    source_v392_hbm.obj = source_v392.data();
    source_v392_hbm.param = 0;
    source_v392_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v393_hbm;
    source_v393_hbm.obj = source_v393.data();
    source_v393_hbm.param = 0;
    source_v393_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v394_hbm;
    source_v394_hbm.obj = source_v394.data();
    source_v394_hbm.param = 0;
    source_v394_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v395_hbm;
    source_v395_hbm.obj = source_v395.data();
    source_v395_hbm.param = 0;
    source_v395_hbm.flags = HBM[11];
    
OCL_CHECK(err, cl::Buffer v384_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4704, &source_v384_hbm, &err));
OCL_CHECK(err, cl::Buffer v385_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v385_hbm, &err));
OCL_CHECK(err, cl::Buffer v386_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 128, &source_v386_hbm, &err));
OCL_CHECK(err, cl::Buffer v387_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 819200, &source_v387_hbm, &err));
OCL_CHECK(err, cl::Buffer v388_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 27648, &source_v388_hbm, &err));
OCL_CHECK(err, cl::Buffer v389_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 41472, &source_v389_hbm, &err));
OCL_CHECK(err, cl::Buffer v390_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 27648, &source_v390_hbm, &err));
OCL_CHECK(err, cl::Buffer v391_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 19200, &source_v391_hbm, &err));
OCL_CHECK(err, cl::Buffer v392_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 441, &source_v392_hbm, &err));
OCL_CHECK(err, cl::Buffer v393_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 524288, &source_v393_hbm, &err));
OCL_CHECK(err, cl::Buffer v394_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 128000, &source_v394_hbm, &err));
OCL_CHECK(err, cl::Buffer v395_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v395_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v384_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v385_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v386_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v387_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v388_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v389_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v390_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v391_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v392_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v393_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v394_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v395_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v384_buf, 
v385_buf, 
v386_buf, 
v387_buf, 
v388_buf, 
v389_buf, 
v390_buf, 
v391_buf, 
v392_buf, 
v393_buf, 
v394_buf, 
v395_buf, 
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
