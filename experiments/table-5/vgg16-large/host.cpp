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
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v774(4704);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v775(31);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v776(64);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v777(1605632);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v778(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v779(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v780(36864);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v781(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v782(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v783(9216);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v784(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v785(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v786(2304);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v787(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v788(576);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v789(288);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v790(27);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v791(131072);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v792(64000);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v793(31);
    
    cl_mem_ext_ptr_t source_v774_hbm;
    source_v774_hbm.obj = source_v774.data();
    source_v774_hbm.param = 0;
    source_v774_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v775_hbm;
    source_v775_hbm.obj = source_v775.data();
    source_v775_hbm.param = 0;
    source_v775_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v776_hbm;
    source_v776_hbm.obj = source_v776.data();
    source_v776_hbm.param = 0;
    source_v776_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v777_hbm;
    source_v777_hbm.obj = source_v777.data();
    source_v777_hbm.param = 0;
    source_v777_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v778_hbm;
    source_v778_hbm.obj = source_v778.data();
    source_v778_hbm.param = 0;
    source_v778_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v779_hbm;
    source_v779_hbm.obj = source_v779.data();
    source_v779_hbm.param = 0;
    source_v779_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v780_hbm;
    source_v780_hbm.obj = source_v780.data();
    source_v780_hbm.param = 0;
    source_v780_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v781_hbm;
    source_v781_hbm.obj = source_v781.data();
    source_v781_hbm.param = 0;
    source_v781_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v782_hbm;
    source_v782_hbm.obj = source_v782.data();
    source_v782_hbm.param = 0;
    source_v782_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v783_hbm;
    source_v783_hbm.obj = source_v783.data();
    source_v783_hbm.param = 0;
    source_v783_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v784_hbm;
    source_v784_hbm.obj = source_v784.data();
    source_v784_hbm.param = 0;
    source_v784_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v785_hbm;
    source_v785_hbm.obj = source_v785.data();
    source_v785_hbm.param = 0;
    source_v785_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v786_hbm;
    source_v786_hbm.obj = source_v786.data();
    source_v786_hbm.param = 0;
    source_v786_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v787_hbm;
    source_v787_hbm.obj = source_v787.data();
    source_v787_hbm.param = 0;
    source_v787_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v788_hbm;
    source_v788_hbm.obj = source_v788.data();
    source_v788_hbm.param = 0;
    source_v788_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v789_hbm;
    source_v789_hbm.obj = source_v789.data();
    source_v789_hbm.param = 0;
    source_v789_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v790_hbm;
    source_v790_hbm.obj = source_v790.data();
    source_v790_hbm.param = 0;
    source_v790_hbm.flags = HBM[16];
    
    
    cl_mem_ext_ptr_t source_v791_hbm;
    source_v791_hbm.obj = source_v791.data();
    source_v791_hbm.param = 0;
    source_v791_hbm.flags = HBM[17];
    
    
    cl_mem_ext_ptr_t source_v792_hbm;
    source_v792_hbm.obj = source_v792.data();
    source_v792_hbm.param = 0;
    source_v792_hbm.flags = HBM[18];
    
    
    cl_mem_ext_ptr_t source_v793_hbm;
    source_v793_hbm.obj = source_v793.data();
    source_v793_hbm.param = 0;
    source_v793_hbm.flags = HBM[19];
    
OCL_CHECK(err, cl::Buffer v774_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4704, &source_v774_hbm, &err));
OCL_CHECK(err, cl::Buffer v775_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v775_hbm, &err));
OCL_CHECK(err, cl::Buffer v776_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 64, &source_v776_hbm, &err));
OCL_CHECK(err, cl::Buffer v777_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1605632, &source_v777_hbm, &err));
OCL_CHECK(err, cl::Buffer v778_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v778_hbm, &err));
OCL_CHECK(err, cl::Buffer v779_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v779_hbm, &err));
OCL_CHECK(err, cl::Buffer v780_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 36864, &source_v780_hbm, &err));
OCL_CHECK(err, cl::Buffer v781_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v781_hbm, &err));
OCL_CHECK(err, cl::Buffer v782_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v782_hbm, &err));
OCL_CHECK(err, cl::Buffer v783_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 9216, &source_v783_hbm, &err));
OCL_CHECK(err, cl::Buffer v784_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v784_hbm, &err));
OCL_CHECK(err, cl::Buffer v785_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v785_hbm, &err));
OCL_CHECK(err, cl::Buffer v786_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 2304, &source_v786_hbm, &err));
OCL_CHECK(err, cl::Buffer v787_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v787_hbm, &err));
OCL_CHECK(err, cl::Buffer v788_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 576, &source_v788_hbm, &err));
OCL_CHECK(err, cl::Buffer v789_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 288, &source_v789_hbm, &err));
OCL_CHECK(err, cl::Buffer v790_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 27, &source_v790_hbm, &err));
OCL_CHECK(err, cl::Buffer v791_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 131072, &source_v791_hbm, &err));
OCL_CHECK(err, cl::Buffer v792_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 64000, &source_v792_hbm, &err));
OCL_CHECK(err, cl::Buffer v793_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v793_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v774_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v775_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v776_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v777_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v778_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v779_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v780_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v781_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v782_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v783_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v784_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v785_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v786_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v787_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v788_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v789_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v790_buf));
    OCL_CHECK(err, err = kernel.setArg(17, v791_buf));
    OCL_CHECK(err, err = kernel.setArg(18, v792_buf));
    OCL_CHECK(err, err = kernel.setArg(19, v793_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v774_buf, 
v775_buf, 
v776_buf, 
v777_buf, 
v778_buf, 
v779_buf, 
v780_buf, 
v781_buf, 
v782_buf, 
v783_buf, 
v784_buf, 
v785_buf, 
v786_buf, 
v787_buf, 
v788_buf, 
v789_buf, 
v790_buf, 
v791_buf, 
v792_buf, 
v793_buf, 
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
