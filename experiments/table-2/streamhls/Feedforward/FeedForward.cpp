
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
  hls::stream<float> v0[1][8],
  float v1[1][512][128]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=3 factor=8

  loop0: for (int v2 = 0; v2 < 512; v2++) {
    loop1: for (int v3 = 0; v3 < 16; v3++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop2: for (int v4 = 0; v4 < 1; v4++) {
        loop3: for (int v5 = 0; v5 < 8; v5++) {
          float v6 = v0[v4][v5].read();
          v1[0][(v2 + v4)][(v5 + (v3 * 8))] = v6;
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v7[1][8],
  float v8[128],
  hls::stream<float> v9[1][8]
) {
  #pragma HLS array_partition variable=v8 cyclic dim=1 factor=8

  loop4: for (int v10 = 0; v10 < 512; v10++) {
    loop5: for (int v11 = 0; v11 < 16; v11++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop6: for (int v12 = 0; v12 < 1; v12++) {
        loop7: for (int v13 = 0; v13 < 8; v13++) {
          float v14 = v7[v12][v13].read();
          float v15 = v8[(v13 + (v11 * 8))];
          float v16 = v14 + v15;
          v9[v12][v13].write(v16);
        }
      }
    }
  }
  return ;
}

void node2(
  hls::stream<float> v17[8][8],
  hls::stream<float> v18[1][8],
  hls::stream<float> v19[1][8],
  float v20
) {
  float v21[512][128];
  #pragma HLS array_partition variable=v21 cyclic dim=2 factor=8

  float v22[256][128];
  #pragma HLS array_partition variable=v22 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v22 cyclic dim=2 factor=8

  float v23[512][256];
  #pragma HLS array_partition variable=v23 cyclic dim=2 factor=8

  loop8: for (int v24 = 0; v24 < 512; v24++) {
    loop9: for (int v25 = 0; v25 < 32; v25++) {
      loop10: for (int v26 = 0; v26 < 16; v26++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop11: for (int v27 = 0; v27 < 1; v27++) {
          loop12: for (int v28 = 0; v28 < 8; v28++) {
            loop13: for (int v29 = 0; v29 < 8; v29++) {
              if ((v29 + (v26 * 8)) == 0) {
                float v30 = v18[v27][v28].read();
                v23[(v24 + v27)][(v28 + (v25 * 8))] = v30;
              }
              float v31 = v23[(v24 + v27)][(v28 + (v25 * 8))];
              if ((v24 + v27) == 0) {
                float v32 = v17[v28][v29].read();
                v22[(v28 + (v25 * 8))][(v29 + (v26 * 8))] = v32;
              }
              float v33 = v22[(v28 + (v25 * 8))][(v29 + (v26 * 8))];
              if ((v28 + (v25 * 8)) == 0) {
                v21[(v24 + v27)][(v29 + (v26 * 8))] = v20;
              }
              float v34 = v21[(v24 + v27)][(v29 + (v26 * 8))];
              float v35 = v31 * v33;
              float v36 = v34 + v35;
              v21[(v24 + v27)][(v29 + (v26 * 8))] = v36;
              if (((v28 + (v25 * 8)) - 255) == 0) {
                float v37 = v21[(v24 + v27)][(v29 + (v26 * 8))];
                v19[v27][v29].write(v37);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node3(
  float v38[128][256],
  hls::stream<float> v39[8][8]
) {
  #pragma HLS array_partition variable=v38 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v38 cyclic dim=2 factor=8

  loop14: for (int v40 = 0; v40 < 32; v40++) {
    loop15: for (int v41 = 0; v41 < 16; v41++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop16: for (int v42 = 0; v42 < 8; v42++) {
        loop17: for (int v43 = 0; v43 < 8; v43++) {
          float v44 = v38[(v43 + (v41 * 8))][(v42 + (v40 * 8))];
          v39[v42][v43].write(v44);
        }
      }
    }
  }
  return ;
}

void node4(
  hls::stream<float> v45[1][8],
  float v46[256],
  hls::stream<float> v47[1][8],
  float v48
) {
  #pragma HLS array_partition variable=v46 cyclic dim=1 factor=8

  loop18: for (int v49 = 0; v49 < 512; v49++) {
    loop19: for (int v50 = 0; v50 < 32; v50++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop20: for (int v51 = 0; v51 < 1; v51++) {
        loop21: for (int v52 = 0; v52 < 8; v52++) {
          float v53 = v45[v51][v52].read();
          float v54 = v46[(v52 + (v50 * 8))];
          float v55 = v53 + v54;
          bool v56 = v55 > v48;
          float v57 = v56 ? (float)v55 : (float)v48;
          v47[v51][v52].write(v57);
        }
      }
    }
  }
  return ;
}

void node5(
  hls::stream<float> v58[1][8],
  hls::stream<float> v59[8][8],
  hls::stream<float> v60[1][8],
  float v61
) {
  float v62[512][256];
  #pragma HLS array_partition variable=v62 cyclic dim=2 factor=8

  float v63[128][256];
  #pragma HLS array_partition variable=v63 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v63 cyclic dim=2 factor=8

  float v64[512][128];
  #pragma HLS array_partition variable=v64 cyclic dim=2 factor=8

  loop22: for (int v65 = 0; v65 < 512; v65++) {
    loop23: for (int v66 = 0; v66 < 16; v66++) {
      loop24: for (int v67 = 0; v67 < 32; v67++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop25: for (int v68 = 0; v68 < 1; v68++) {
          loop26: for (int v69 = 0; v69 < 8; v69++) {
            loop27: for (int v70 = 0; v70 < 8; v70++) {
              if ((v70 + (v67 * 8)) == 0) {
                float v71 = v58[v68][v69].read();
                v64[(v65 + v68)][(v69 + (v66 * 8))] = v71;
              }
              float v72 = v64[(v65 + v68)][(v69 + (v66 * 8))];
              if ((v65 + v68) == 0) {
                float v73 = v59[v69][v70].read();
                v63[(v69 + (v66 * 8))][(v70 + (v67 * 8))] = v73;
              }
              float v74 = v63[(v69 + (v66 * 8))][(v70 + (v67 * 8))];
              if ((v69 + (v66 * 8)) == 0) {
                v62[(v65 + v68)][(v70 + (v67 * 8))] = v61;
              }
              float v75 = v62[(v65 + v68)][(v70 + (v67 * 8))];
              float v76 = v72 * v74;
              float v77 = v75 + v76;
              v62[(v65 + v68)][(v70 + (v67 * 8))] = v77;
              if (((v69 + (v66 * 8)) - 127) == 0) {
                float v78 = v62[(v65 + v68)][(v70 + (v67 * 8))];
                v60[v68][v70].write(v78);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node6(
  float v79[256][128],
  hls::stream<float> v80[8][8]
) {
  #pragma HLS array_partition variable=v79 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v79 cyclic dim=2 factor=8

  loop28: for (int v81 = 0; v81 < 16; v81++) {
    loop29: for (int v82 = 0; v82 < 32; v82++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop30: for (int v83 = 0; v83 < 8; v83++) {
        loop31: for (int v84 = 0; v84 < 8; v84++) {
          float v85 = v79[(v84 + (v82 * 8))][(v83 + (v81 * 8))];
          v80[v83][v84].write(v85);
        }
      }
    }
  }
  return ;
}

void node7(
  float v86[1][512][128],
  hls::stream<float> v87[1][8]
) {
  #pragma HLS array_partition variable=v86 cyclic dim=3 factor=8

  loop32: for (int v88 = 0; v88 < 512; v88++) {
    loop33: for (int v89 = 0; v89 < 16; v89++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop34: for (int v90 = 0; v90 < 1; v90++) {
        loop35: for (int v91 = 0; v91 < 8; v91++) {
          float v92 = v86[0][(v88 + v90)][(v91 + (v89 * 8))];
          v87[v90][v91].write(v92);
        }
      }
    }
  }
  return ;
}

void forward(
  float v93[1][512][128],
  float v94[256],
  float v95[256][128],
  float v96[128],
  float v97[128][256],
  float v98[1][512][128]
) {
	#pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v93 cyclic dim=3 factor=8

  #pragma HLS array_partition variable=v94 cyclic dim=1 factor=8

  #pragma HLS array_partition variable=v95 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v95 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v96 cyclic dim=1 factor=8

  #pragma HLS array_partition variable=v97 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v97 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v98 cyclic dim=3 factor=8

  hls::stream<float> v99[1][8];
	#pragma HLS STREAM variable=v99 depth=8192
  hls::stream<float> v100[1][8];
	#pragma HLS STREAM variable=v100 depth=8192
  hls::stream<float> v101[8][8];
	#pragma HLS STREAM variable=v101 depth=512
  hls::stream<float> v102[1][8];
	#pragma HLS STREAM variable=v102 depth=16384
  hls::stream<float> v103[1][8];
	#pragma HLS STREAM variable=v103 depth=16384
  hls::stream<float> v104[8][8];
	#pragma HLS STREAM variable=v104 depth=512
  hls::stream<float> v105[1][8];
	#pragma HLS STREAM variable=v105 depth=8192
  node7(v93, v105);
  node6(v95, v104);
  node5(v105, v104, v103, 0.000000);
  node4(v103, v94, v102, 0.000000);
  node3(v97, v101);
  node2(v101, v102, v100, 0.000000);
  node1(v100, v96, v99);
  node0(v99, v98);
  return ;
}

