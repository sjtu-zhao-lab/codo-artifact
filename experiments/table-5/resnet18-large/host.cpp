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
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1055(4704);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1056(31);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1057(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1058(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1059(4096);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1060(73728);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1061(36864);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1062(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1063(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1064(1024);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1065(18432);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1066(9216);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1067(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1068(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1069(256);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1070(4608);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1071(2304);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1072(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1073(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1074(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1075(1152);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1076(294);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1077(16000);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1078(31);
    
    cl_mem_ext_ptr_t source_v1055_hbm;
    source_v1055_hbm.obj = source_v1055.data();
    source_v1055_hbm.param = 0;
    source_v1055_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v1056_hbm;
    source_v1056_hbm.obj = source_v1056.data();
    source_v1056_hbm.param = 0;
    source_v1056_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v1057_hbm;
    source_v1057_hbm.obj = source_v1057.data();
    source_v1057_hbm.param = 0;
    source_v1057_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v1058_hbm;
    source_v1058_hbm.obj = source_v1058.data();
    source_v1058_hbm.param = 0;
    source_v1058_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v1059_hbm;
    source_v1059_hbm.obj = source_v1059.data();
    source_v1059_hbm.param = 0;
    source_v1059_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v1060_hbm;
    source_v1060_hbm.obj = source_v1060.data();
    source_v1060_hbm.param = 0;
    source_v1060_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v1061_hbm;
    source_v1061_hbm.obj = source_v1061.data();
    source_v1061_hbm.param = 0;
    source_v1061_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v1062_hbm;
    source_v1062_hbm.obj = source_v1062.data();
    source_v1062_hbm.param = 0;
    source_v1062_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v1063_hbm;
    source_v1063_hbm.obj = source_v1063.data();
    source_v1063_hbm.param = 0;
    source_v1063_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v1064_hbm;
    source_v1064_hbm.obj = source_v1064.data();
    source_v1064_hbm.param = 0;
    source_v1064_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v1065_hbm;
    source_v1065_hbm.obj = source_v1065.data();
    source_v1065_hbm.param = 0;
    source_v1065_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v1066_hbm;
    source_v1066_hbm.obj = source_v1066.data();
    source_v1066_hbm.param = 0;
    source_v1066_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v1067_hbm;
    source_v1067_hbm.obj = source_v1067.data();
    source_v1067_hbm.param = 0;
    source_v1067_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v1068_hbm;
    source_v1068_hbm.obj = source_v1068.data();
    source_v1068_hbm.param = 0;
    source_v1068_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v1069_hbm;
    source_v1069_hbm.obj = source_v1069.data();
    source_v1069_hbm.param = 0;
    source_v1069_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v1070_hbm;
    source_v1070_hbm.obj = source_v1070.data();
    source_v1070_hbm.param = 0;
    source_v1070_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v1071_hbm;
    source_v1071_hbm.obj = source_v1071.data();
    source_v1071_hbm.param = 0;
    source_v1071_hbm.flags = HBM[16];
    
    
    cl_mem_ext_ptr_t source_v1072_hbm;
    source_v1072_hbm.obj = source_v1072.data();
    source_v1072_hbm.param = 0;
    source_v1072_hbm.flags = HBM[17];
    
    
    cl_mem_ext_ptr_t source_v1073_hbm;
    source_v1073_hbm.obj = source_v1073.data();
    source_v1073_hbm.param = 0;
    source_v1073_hbm.flags = HBM[18];
    
    
    cl_mem_ext_ptr_t source_v1074_hbm;
    source_v1074_hbm.obj = source_v1074.data();
    source_v1074_hbm.param = 0;
    source_v1074_hbm.flags = HBM[19];
    
    
    cl_mem_ext_ptr_t source_v1075_hbm;
    source_v1075_hbm.obj = source_v1075.data();
    source_v1075_hbm.param = 0;
    source_v1075_hbm.flags = HBM[20];
    
    
    cl_mem_ext_ptr_t source_v1076_hbm;
    source_v1076_hbm.obj = source_v1076.data();
    source_v1076_hbm.param = 0;
    source_v1076_hbm.flags = HBM[21];
    
    
    cl_mem_ext_ptr_t source_v1077_hbm;
    source_v1077_hbm.obj = source_v1077.data();
    source_v1077_hbm.param = 0;
    source_v1077_hbm.flags = HBM[22];
    
    
    cl_mem_ext_ptr_t source_v1078_hbm;
    source_v1078_hbm.obj = source_v1078.data();
    source_v1078_hbm.param = 0;
    source_v1078_hbm.flags = HBM[23];
    
OCL_CHECK(err, cl::Buffer v1055_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4704, &source_v1055_hbm, &err));
OCL_CHECK(err, cl::Buffer v1056_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v1056_hbm, &err));
OCL_CHECK(err, cl::Buffer v1057_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v1057_hbm, &err));
OCL_CHECK(err, cl::Buffer v1058_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v1058_hbm, &err));
OCL_CHECK(err, cl::Buffer v1059_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4096, &source_v1059_hbm, &err));
OCL_CHECK(err, cl::Buffer v1060_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 73728, &source_v1060_hbm, &err));
OCL_CHECK(err, cl::Buffer v1061_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 36864, &source_v1061_hbm, &err));
OCL_CHECK(err, cl::Buffer v1062_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v1062_hbm, &err));
OCL_CHECK(err, cl::Buffer v1063_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v1063_hbm, &err));
OCL_CHECK(err, cl::Buffer v1064_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1024, &source_v1064_hbm, &err));
OCL_CHECK(err, cl::Buffer v1065_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18432, &source_v1065_hbm, &err));
OCL_CHECK(err, cl::Buffer v1066_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 9216, &source_v1066_hbm, &err));
OCL_CHECK(err, cl::Buffer v1067_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v1067_hbm, &err));
OCL_CHECK(err, cl::Buffer v1068_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v1068_hbm, &err));
OCL_CHECK(err, cl::Buffer v1069_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 256, &source_v1069_hbm, &err));
OCL_CHECK(err, cl::Buffer v1070_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4608, &source_v1070_hbm, &err));
OCL_CHECK(err, cl::Buffer v1071_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 2304, &source_v1071_hbm, &err));
OCL_CHECK(err, cl::Buffer v1072_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1072_hbm, &err));
OCL_CHECK(err, cl::Buffer v1073_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1073_hbm, &err));
OCL_CHECK(err, cl::Buffer v1074_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1074_hbm, &err));
OCL_CHECK(err, cl::Buffer v1075_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1152, &source_v1075_hbm, &err));
OCL_CHECK(err, cl::Buffer v1076_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 294, &source_v1076_hbm, &err));
OCL_CHECK(err, cl::Buffer v1077_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16000, &source_v1077_hbm, &err));
OCL_CHECK(err, cl::Buffer v1078_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v1078_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v1055_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v1056_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v1057_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v1058_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v1059_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v1060_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v1061_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v1062_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v1063_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v1064_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v1065_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v1066_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v1067_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v1068_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v1069_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v1070_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v1071_buf));
    OCL_CHECK(err, err = kernel.setArg(17, v1072_buf));
    OCL_CHECK(err, err = kernel.setArg(18, v1073_buf));
    OCL_CHECK(err, err = kernel.setArg(19, v1074_buf));
    OCL_CHECK(err, err = kernel.setArg(20, v1075_buf));
    OCL_CHECK(err, err = kernel.setArg(21, v1076_buf));
    OCL_CHECK(err, err = kernel.setArg(22, v1077_buf));
    OCL_CHECK(err, err = kernel.setArg(23, v1078_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v1055_buf, 
v1056_buf, 
v1057_buf, 
v1058_buf, 
v1059_buf, 
v1060_buf, 
v1061_buf, 
v1062_buf, 
v1063_buf, 
v1064_buf, 
v1065_buf, 
v1066_buf, 
v1067_buf, 
v1068_buf, 
v1069_buf, 
v1070_buf, 
v1071_buf, 
v1072_buf, 
v1073_buf, 
v1074_buf, 
v1075_buf, 
v1076_buf, 
v1077_buf, 
v1078_buf, 
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
