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
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v652(96);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v653(1);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v654(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v655(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v656(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v657(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v658(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v659(36864);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v660(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v661(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v662(9216);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v663(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v664(2304);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v665(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v666(54);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v667(160);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v668(1);
    
    cl_mem_ext_ptr_t source_v652_hbm;
    source_v652_hbm.obj = source_v652.data();
    source_v652_hbm.param = 0;
    source_v652_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v653_hbm;
    source_v653_hbm.obj = source_v653.data();
    source_v653_hbm.param = 0;
    source_v653_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v654_hbm;
    source_v654_hbm.obj = source_v654.data();
    source_v654_hbm.param = 0;
    source_v654_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v655_hbm;
    source_v655_hbm.obj = source_v655.data();
    source_v655_hbm.param = 0;
    source_v655_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v656_hbm;
    source_v656_hbm.obj = source_v656.data();
    source_v656_hbm.param = 0;
    source_v656_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v657_hbm;
    source_v657_hbm.obj = source_v657.data();
    source_v657_hbm.param = 0;
    source_v657_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v658_hbm;
    source_v658_hbm.obj = source_v658.data();
    source_v658_hbm.param = 0;
    source_v658_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v659_hbm;
    source_v659_hbm.obj = source_v659.data();
    source_v659_hbm.param = 0;
    source_v659_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v660_hbm;
    source_v660_hbm.obj = source_v660.data();
    source_v660_hbm.param = 0;
    source_v660_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v661_hbm;
    source_v661_hbm.obj = source_v661.data();
    source_v661_hbm.param = 0;
    source_v661_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v662_hbm;
    source_v662_hbm.obj = source_v662.data();
    source_v662_hbm.param = 0;
    source_v662_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v663_hbm;
    source_v663_hbm.obj = source_v663.data();
    source_v663_hbm.param = 0;
    source_v663_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v664_hbm;
    source_v664_hbm.obj = source_v664.data();
    source_v664_hbm.param = 0;
    source_v664_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v665_hbm;
    source_v665_hbm.obj = source_v665.data();
    source_v665_hbm.param = 0;
    source_v665_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v666_hbm;
    source_v666_hbm.obj = source_v666.data();
    source_v666_hbm.param = 0;
    source_v666_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v667_hbm;
    source_v667_hbm.obj = source_v667.data();
    source_v667_hbm.param = 0;
    source_v667_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v668_hbm;
    source_v668_hbm.obj = source_v668.data();
    source_v668_hbm.param = 0;
    source_v668_hbm.flags = HBM[16];
    
OCL_CHECK(err, cl::Buffer v652_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 96, &source_v652_hbm, &err));
OCL_CHECK(err, cl::Buffer v653_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1, &source_v653_hbm, &err));
OCL_CHECK(err, cl::Buffer v654_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v654_hbm, &err));
OCL_CHECK(err, cl::Buffer v655_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v655_hbm, &err));
OCL_CHECK(err, cl::Buffer v656_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v656_hbm, &err));
OCL_CHECK(err, cl::Buffer v657_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v657_hbm, &err));
OCL_CHECK(err, cl::Buffer v658_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v658_hbm, &err));
OCL_CHECK(err, cl::Buffer v659_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 36864, &source_v659_hbm, &err));
OCL_CHECK(err, cl::Buffer v660_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v660_hbm, &err));
OCL_CHECK(err, cl::Buffer v661_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v661_hbm, &err));
OCL_CHECK(err, cl::Buffer v662_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 9216, &source_v662_hbm, &err));
OCL_CHECK(err, cl::Buffer v663_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v663_hbm, &err));
OCL_CHECK(err, cl::Buffer v664_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 2304, &source_v664_hbm, &err));
OCL_CHECK(err, cl::Buffer v665_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v665_hbm, &err));
OCL_CHECK(err, cl::Buffer v666_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 54, &source_v666_hbm, &err));
OCL_CHECK(err, cl::Buffer v667_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 160, &source_v667_hbm, &err));
OCL_CHECK(err, cl::Buffer v668_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1, &source_v668_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v652_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v653_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v654_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v655_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v656_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v657_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v658_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v659_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v660_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v661_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v662_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v663_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v664_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v665_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v666_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v667_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v668_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v652_buf, 
v653_buf, 
v654_buf, 
v655_buf, 
v656_buf, 
v657_buf, 
v658_buf, 
v659_buf, 
v660_buf, 
v661_buf, 
v662_buf, 
v663_buf, 
v664_buf, 
v665_buf, 
v666_buf, 
v667_buf, 
v668_buf, 
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
