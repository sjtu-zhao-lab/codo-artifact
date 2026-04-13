
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
#include <hls_stream.h>
#include <hls_half.h>
#include <cassert>
#include <hls_math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void node0(
  hls::stream<float> v0[2],
  float v1[400]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=1 factor=2

  loop0: for (int v2 = 0; v2 < 200; v2++) {
    #pragma HLS pipeline II=1
    #pragma HLS loop_flatten
    loop1: for (int v3 = 0; v3 < 2; v3++) {
      float v4 = v0[v3].read();
      v1[(v3 + (v2 * 2))] = v4;
    }
  }
  return ;
}

void node1(
  hls::stream<float> v5[2],
  float v6[400]
) {
  #pragma HLS array_partition variable=v6 cyclic dim=1 factor=2

  loop2: for (int v7 = 0; v7 < 200; v7++) {
    #pragma HLS pipeline II=1
    #pragma HLS loop_flatten
    loop3: for (int v8 = 0; v8 < 2; v8++) {
      float v9 = v5[v8].read();
      v6[(v8 + (v7 * 2))] = v9;
    }
  }
  return ;
}

void node2(
  hls::stream<float> v10[2][40],
  float v11[400],
  hls::stream<float> v12[2],
  float v13
) {
  #pragma HLS array_partition variable=v11 cyclic dim=1 factor=40

  float v14[400];
  #pragma HLS array_partition variable=v14 cyclic dim=1 factor=2

  loop4: for (int v15 = 0; v15 < 10; v15++) {
    loop5: for (int v16 = 0; v16 < 200; v16++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop6: for (int v17 = 0; v17 < 40; v17++) {
        loop7: for (int v18 = 0; v18 < 2; v18++) {
          float v19 = v10[v18][v17].read();
          float v20 = v11[(v17 + (v15 * 40))];
          if ((v17 + (v15 * 40)) == 0) {
            v14[(v18 + (v16 * 2))] = v13;
          }
          float v21 = v14[(v18 + (v16 * 2))];
          float v22 = v19 * v20;
          float v23 = v21 + v22;
          v14[(v18 + (v16 * 2))] = v23;
          if (((v17 + (v15 * 40)) - 399) == 0) {
            float v24 = v14[(v18 + (v16 * 2))];
            v12[v18].write(v24);
          }
        }
      }
    }
  }
  return ;
}

void node3(
  float v25[400][400],
  hls::stream<float> v26[2][40]
) {
  #pragma HLS array_partition variable=v25 cyclic dim=1 factor=40
  #pragma HLS array_partition variable=v25 cyclic dim=2 factor=2

  loop8: for (int v27 = 0; v27 < 10; v27++) {
    loop9: for (int v28 = 0; v28 < 200; v28++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop10: for (int v29 = 0; v29 < 40; v29++) {
        loop11: for (int v30 = 0; v30 < 2; v30++) {
          float v31 = v25[(v29 + (v27 * 40))][(v30 + (v28 * 2))];
          v26[v30][v29].write(v31);
        }
      }
    }
  }
  return ;
}

void node4(
  float v32[400][400],
  float v33[400],
  hls::stream<float> v34[2],
  float v35
) {
  #pragma HLS array_partition variable=v32 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v32 cyclic dim=2 factor=40

  #pragma HLS array_partition variable=v33 cyclic dim=1 factor=40

  float v36[400];
  #pragma HLS array_partition variable=v36 cyclic dim=1 factor=2

  loop12: for (int v37 = 0; v37 < 10; v37++) {
    loop13: for (int v38 = 0; v38 < 200; v38++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop14: for (int v39 = 0; v39 < 40; v39++) {
        loop15: for (int v40 = 0; v40 < 2; v40++) {
          float v41 = v32[(v40 + (v38 * 2))][(v39 + (v37 * 40))];
          float v42 = v33[(v39 + (v37 * 40))];
          if ((v39 + (v37 * 40)) == 0) {
            v36[(v40 + (v38 * 2))] = v35;
          }
          float v43 = v36[(v40 + (v38 * 2))];
          float v44 = v41 * v42;
          float v45 = v43 + v44;
          v36[(v40 + (v38 * 2))] = v45;
          if (((v39 + (v37 * 40)) - 399) == 0) {
            float v46 = v36[(v40 + (v38 * 2))];
            v34[v40].write(v46);
          }
        }
      }
    }
  }
  return ;
}

void forward(
  float v47[400][400],
  float v48[400][400],
  float v49[400],
  float v50[400],
  float v51[400],
  float v52[400]
) {
	#pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v47 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v47 cyclic dim=2 factor=40

  #pragma HLS array_partition variable=v48 cyclic dim=1 factor=40
  #pragma HLS array_partition variable=v48 cyclic dim=2 factor=2

  #pragma HLS array_partition variable=v49 cyclic dim=1 factor=40

  #pragma HLS array_partition variable=v50 cyclic dim=1 factor=40

  #pragma HLS array_partition variable=v51 cyclic dim=1 factor=2

  #pragma HLS array_partition variable=v52 cyclic dim=1 factor=2

  hls::stream<float> v53[2];
	#pragma HLS STREAM variable=v53 depth=200
  hls::stream<float> v54[2][40];
	#pragma HLS STREAM variable=v54 depth=2000
  hls::stream<float> v55[2];
	#pragma HLS STREAM variable=v55 depth=200
  node4(v47, v49, v55, 0.000000);
  node3(v48, v54);
  node2(v54, v50, v53, 0.000000);
  node1(v55, v51);
  node0(v53, v52);
  return ;
}

