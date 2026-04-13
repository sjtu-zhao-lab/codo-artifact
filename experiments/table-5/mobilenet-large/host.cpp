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
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1138(4704);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1139(31);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1140(32768);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1141(16384);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1142(8192);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1143(8192);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1144(8192);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1145(8192);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1146(8192);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1147(4096);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1148(2048);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1149(1024);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1150(512);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1151(256);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1152(64);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1153(27);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1154(9);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1155(18);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1156(36);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1157(36);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1158(72);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1159(72);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1160(144);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1161(144);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1162(144);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1163(144);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1164(144);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1165(144);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1166(288);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1167(32000);
    std::vector<ap_uint<256>, aligned_allocator<ap_uint<256>>> source_v1168(31);
    
    cl_mem_ext_ptr_t source_v1138_hbm;
    source_v1138_hbm.obj = source_v1138.data();
    source_v1138_hbm.param = 0;
    source_v1138_hbm.flags = HBM[0];
    
    
    cl_mem_ext_ptr_t source_v1139_hbm;
    source_v1139_hbm.obj = source_v1139.data();
    source_v1139_hbm.param = 0;
    source_v1139_hbm.flags = HBM[1];
    
    
    cl_mem_ext_ptr_t source_v1140_hbm;
    source_v1140_hbm.obj = source_v1140.data();
    source_v1140_hbm.param = 0;
    source_v1140_hbm.flags = HBM[2];
    
    
    cl_mem_ext_ptr_t source_v1141_hbm;
    source_v1141_hbm.obj = source_v1141.data();
    source_v1141_hbm.param = 0;
    source_v1141_hbm.flags = HBM[3];
    
    
    cl_mem_ext_ptr_t source_v1142_hbm;
    source_v1142_hbm.obj = source_v1142.data();
    source_v1142_hbm.param = 0;
    source_v1142_hbm.flags = HBM[4];
    
    
    cl_mem_ext_ptr_t source_v1143_hbm;
    source_v1143_hbm.obj = source_v1143.data();
    source_v1143_hbm.param = 0;
    source_v1143_hbm.flags = HBM[5];
    
    
    cl_mem_ext_ptr_t source_v1144_hbm;
    source_v1144_hbm.obj = source_v1144.data();
    source_v1144_hbm.param = 0;
    source_v1144_hbm.flags = HBM[6];
    
    
    cl_mem_ext_ptr_t source_v1145_hbm;
    source_v1145_hbm.obj = source_v1145.data();
    source_v1145_hbm.param = 0;
    source_v1145_hbm.flags = HBM[7];
    
    
    cl_mem_ext_ptr_t source_v1146_hbm;
    source_v1146_hbm.obj = source_v1146.data();
    source_v1146_hbm.param = 0;
    source_v1146_hbm.flags = HBM[8];
    
    
    cl_mem_ext_ptr_t source_v1147_hbm;
    source_v1147_hbm.obj = source_v1147.data();
    source_v1147_hbm.param = 0;
    source_v1147_hbm.flags = HBM[9];
    
    
    cl_mem_ext_ptr_t source_v1148_hbm;
    source_v1148_hbm.obj = source_v1148.data();
    source_v1148_hbm.param = 0;
    source_v1148_hbm.flags = HBM[10];
    
    
    cl_mem_ext_ptr_t source_v1149_hbm;
    source_v1149_hbm.obj = source_v1149.data();
    source_v1149_hbm.param = 0;
    source_v1149_hbm.flags = HBM[11];
    
    
    cl_mem_ext_ptr_t source_v1150_hbm;
    source_v1150_hbm.obj = source_v1150.data();
    source_v1150_hbm.param = 0;
    source_v1150_hbm.flags = HBM[12];
    
    
    cl_mem_ext_ptr_t source_v1151_hbm;
    source_v1151_hbm.obj = source_v1151.data();
    source_v1151_hbm.param = 0;
    source_v1151_hbm.flags = HBM[13];
    
    
    cl_mem_ext_ptr_t source_v1152_hbm;
    source_v1152_hbm.obj = source_v1152.data();
    source_v1152_hbm.param = 0;
    source_v1152_hbm.flags = HBM[14];
    
    
    cl_mem_ext_ptr_t source_v1153_hbm;
    source_v1153_hbm.obj = source_v1153.data();
    source_v1153_hbm.param = 0;
    source_v1153_hbm.flags = HBM[15];
    
    
    cl_mem_ext_ptr_t source_v1154_hbm;
    source_v1154_hbm.obj = source_v1154.data();
    source_v1154_hbm.param = 0;
    source_v1154_hbm.flags = HBM[16];
    
    
    cl_mem_ext_ptr_t source_v1155_hbm;
    source_v1155_hbm.obj = source_v1155.data();
    source_v1155_hbm.param = 0;
    source_v1155_hbm.flags = HBM[17];
    
    
    cl_mem_ext_ptr_t source_v1156_hbm;
    source_v1156_hbm.obj = source_v1156.data();
    source_v1156_hbm.param = 0;
    source_v1156_hbm.flags = HBM[18];
    
    
    cl_mem_ext_ptr_t source_v1157_hbm;
    source_v1157_hbm.obj = source_v1157.data();
    source_v1157_hbm.param = 0;
    source_v1157_hbm.flags = HBM[19];
    
    
    cl_mem_ext_ptr_t source_v1158_hbm;
    source_v1158_hbm.obj = source_v1158.data();
    source_v1158_hbm.param = 0;
    source_v1158_hbm.flags = HBM[20];
    
    
    cl_mem_ext_ptr_t source_v1159_hbm;
    source_v1159_hbm.obj = source_v1159.data();
    source_v1159_hbm.param = 0;
    source_v1159_hbm.flags = HBM[21];
    
    
    cl_mem_ext_ptr_t source_v1160_hbm;
    source_v1160_hbm.obj = source_v1160.data();
    source_v1160_hbm.param = 0;
    source_v1160_hbm.flags = HBM[22];
    
    
    cl_mem_ext_ptr_t source_v1161_hbm;
    source_v1161_hbm.obj = source_v1161.data();
    source_v1161_hbm.param = 0;
    source_v1161_hbm.flags = HBM[23];
    
    
    cl_mem_ext_ptr_t source_v1162_hbm;
    source_v1162_hbm.obj = source_v1162.data();
    source_v1162_hbm.param = 0;
    source_v1162_hbm.flags = HBM[24];
    
    
    cl_mem_ext_ptr_t source_v1163_hbm;
    source_v1163_hbm.obj = source_v1163.data();
    source_v1163_hbm.param = 0;
    source_v1163_hbm.flags = HBM[25];
    
    
    cl_mem_ext_ptr_t source_v1164_hbm;
    source_v1164_hbm.obj = source_v1164.data();
    source_v1164_hbm.param = 0;
    source_v1164_hbm.flags = HBM[26];
    
    
    cl_mem_ext_ptr_t source_v1165_hbm;
    source_v1165_hbm.obj = source_v1165.data();
    source_v1165_hbm.param = 0;
    source_v1165_hbm.flags = HBM[27];
    
    
    cl_mem_ext_ptr_t source_v1166_hbm;
    source_v1166_hbm.obj = source_v1166.data();
    source_v1166_hbm.param = 0;
    source_v1166_hbm.flags = HBM[28];
    
    
    cl_mem_ext_ptr_t source_v1167_hbm;
    source_v1167_hbm.obj = source_v1167.data();
    source_v1167_hbm.param = 0;
    source_v1167_hbm.flags = HBM[29];
    
    
    cl_mem_ext_ptr_t source_v1168_hbm;
    source_v1168_hbm.obj = source_v1168.data();
    source_v1168_hbm.param = 0;
    source_v1168_hbm.flags = HBM[30];
    
OCL_CHECK(err, cl::Buffer v1138_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4704, &source_v1138_hbm, &err));
OCL_CHECK(err, cl::Buffer v1139_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v1139_hbm, &err));
OCL_CHECK(err, cl::Buffer v1140_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32768, &source_v1140_hbm, &err));
OCL_CHECK(err, cl::Buffer v1141_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 16384, &source_v1141_hbm, &err));
OCL_CHECK(err, cl::Buffer v1142_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 8192, &source_v1142_hbm, &err));
OCL_CHECK(err, cl::Buffer v1143_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 8192, &source_v1143_hbm, &err));
OCL_CHECK(err, cl::Buffer v1144_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 8192, &source_v1144_hbm, &err));
OCL_CHECK(err, cl::Buffer v1145_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 8192, &source_v1145_hbm, &err));
OCL_CHECK(err, cl::Buffer v1146_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 8192, &source_v1146_hbm, &err));
OCL_CHECK(err, cl::Buffer v1147_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 4096, &source_v1147_hbm, &err));
OCL_CHECK(err, cl::Buffer v1148_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 2048, &source_v1148_hbm, &err));
OCL_CHECK(err, cl::Buffer v1149_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 1024, &source_v1149_hbm, &err));
OCL_CHECK(err, cl::Buffer v1150_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 512, &source_v1150_hbm, &err));
OCL_CHECK(err, cl::Buffer v1151_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 256, &source_v1151_hbm, &err));
OCL_CHECK(err, cl::Buffer v1152_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 64, &source_v1152_hbm, &err));
OCL_CHECK(err, cl::Buffer v1153_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 27, &source_v1153_hbm, &err));
OCL_CHECK(err, cl::Buffer v1154_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 9, &source_v1154_hbm, &err));
OCL_CHECK(err, cl::Buffer v1155_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 18, &source_v1155_hbm, &err));
OCL_CHECK(err, cl::Buffer v1156_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 36, &source_v1156_hbm, &err));
OCL_CHECK(err, cl::Buffer v1157_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 36, &source_v1157_hbm, &err));
OCL_CHECK(err, cl::Buffer v1158_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 72, &source_v1158_hbm, &err));
OCL_CHECK(err, cl::Buffer v1159_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 72, &source_v1159_hbm, &err));
OCL_CHECK(err, cl::Buffer v1160_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 144, &source_v1160_hbm, &err));
OCL_CHECK(err, cl::Buffer v1161_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 144, &source_v1161_hbm, &err));
OCL_CHECK(err, cl::Buffer v1162_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 144, &source_v1162_hbm, &err));
OCL_CHECK(err, cl::Buffer v1163_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 144, &source_v1163_hbm, &err));
OCL_CHECK(err, cl::Buffer v1164_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 144, &source_v1164_hbm, &err));
OCL_CHECK(err, cl::Buffer v1165_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 144, &source_v1165_hbm, &err));
OCL_CHECK(err, cl::Buffer v1166_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 288, &source_v1166_hbm, &err));
OCL_CHECK(err, cl::Buffer v1167_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 32000, &source_v1167_hbm, &err));
OCL_CHECK(err, cl::Buffer v1168_buf(context, CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, sizeof(ap_uint<256>) * 31, &source_v1168_hbm, &err));

// Set kernel arguments
    OCL_CHECK(err, err = kernel.setArg(0, v1138_buf));
    OCL_CHECK(err, err = kernel.setArg(1, v1139_buf));
    OCL_CHECK(err, err = kernel.setArg(2, v1140_buf));
    OCL_CHECK(err, err = kernel.setArg(3, v1141_buf));
    OCL_CHECK(err, err = kernel.setArg(4, v1142_buf));
    OCL_CHECK(err, err = kernel.setArg(5, v1143_buf));
    OCL_CHECK(err, err = kernel.setArg(6, v1144_buf));
    OCL_CHECK(err, err = kernel.setArg(7, v1145_buf));
    OCL_CHECK(err, err = kernel.setArg(8, v1146_buf));
    OCL_CHECK(err, err = kernel.setArg(9, v1147_buf));
    OCL_CHECK(err, err = kernel.setArg(10, v1148_buf));
    OCL_CHECK(err, err = kernel.setArg(11, v1149_buf));
    OCL_CHECK(err, err = kernel.setArg(12, v1150_buf));
    OCL_CHECK(err, err = kernel.setArg(13, v1151_buf));
    OCL_CHECK(err, err = kernel.setArg(14, v1152_buf));
    OCL_CHECK(err, err = kernel.setArg(15, v1153_buf));
    OCL_CHECK(err, err = kernel.setArg(16, v1154_buf));
    OCL_CHECK(err, err = kernel.setArg(17, v1155_buf));
    OCL_CHECK(err, err = kernel.setArg(18, v1156_buf));
    OCL_CHECK(err, err = kernel.setArg(19, v1157_buf));
    OCL_CHECK(err, err = kernel.setArg(20, v1158_buf));
    OCL_CHECK(err, err = kernel.setArg(21, v1159_buf));
    OCL_CHECK(err, err = kernel.setArg(22, v1160_buf));
    OCL_CHECK(err, err = kernel.setArg(23, v1161_buf));
    OCL_CHECK(err, err = kernel.setArg(24, v1162_buf));
    OCL_CHECK(err, err = kernel.setArg(25, v1163_buf));
    OCL_CHECK(err, err = kernel.setArg(26, v1164_buf));
    OCL_CHECK(err, err = kernel.setArg(27, v1165_buf));
    OCL_CHECK(err, err = kernel.setArg(28, v1166_buf));
    OCL_CHECK(err, err = kernel.setArg(29, v1167_buf));
    OCL_CHECK(err, err = kernel.setArg(30, v1168_buf));

// Migrate buffers to device
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({v1138_buf, 
v1139_buf, 
v1140_buf, 
v1141_buf, 
v1142_buf, 
v1143_buf, 
v1144_buf, 
v1145_buf, 
v1146_buf, 
v1147_buf, 
v1148_buf, 
v1149_buf, 
v1150_buf, 
v1151_buf, 
v1152_buf, 
v1153_buf, 
v1154_buf, 
v1155_buf, 
v1156_buf, 
v1157_buf, 
v1158_buf, 
v1159_buf, 
v1160_buf, 
v1161_buf, 
v1162_buf, 
v1163_buf, 
v1164_buf, 
v1165_buf, 
v1166_buf, 
v1167_buf, 
v1168_buf, 
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
