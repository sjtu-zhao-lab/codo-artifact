
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
  hls::stream<float> v0[4][1][7],
  float v1[1][64][112][112]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=2 factor=4
  #pragma HLS array_partition variable=v1 cyclic dim=4 factor=7

  loop0: for (int v2 = 0; v2 < 16; v2++) {
    loop1: for (int v3 = 0; v3 < 112; v3++) {
      loop2: for (int v4 = 0; v4 < 16; v4++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop3: for (int v5 = 0; v5 < 4; v5++) {
          loop4: for (int v6 = 0; v6 < 1; v6++) {
            loop5: for (int v7 = 0; v7 < 7; v7++) {
              float v8 = v0[v5][v6][v7].read();
              v1[0][(v5 + (v2 * 4))][(v3 + v6)][(v7 + (v4 * 7))] = v8;
            }
          }
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v9[4][1][7],
  hls::stream<float> v10[4][1][7],
  double v11,
  float v12,
  float v13
) {
  loop6: for (int v14 = 0; v14 < 16; v14++) {
    loop7: for (int v15 = 0; v15 < 112; v15++) {
      loop8: for (int v16 = 0; v16 < 16; v16++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop9: for (int v17 = 0; v17 < 4; v17++) {
          loop10: for (int v18 = 0; v18 < 1; v18++) {
            loop11: for (int v19 = 0; v19 < 7; v19++) {
              float v20 = v9[v17][v18][v19].read();
              float v21 = v11;
              float v22 = v21 + v12;
              float v23 = 1.0 / sqrt(v22);
              float v24 = v20 * v23;
              float v25 = v24 + v13;
              bool v26 = v25 > v13;
              float v27 = v26 ? (float)v25 : (float)v13;
              v10[v17][v18][v19].write(v27);
            }
          }
        }
      }
    }
  }
  return ;
}

void node2(
  hls::stream<float> v28[4][1][7],
  float v29[64][64][1][1],
  hls::stream<float> v30[4][1][7],
  float v31
) {
  float v32[64][112][112];
  #pragma HLS array_partition variable=v32 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v32 cyclic dim=3 factor=7

  float v33[64][112][112];
  #pragma HLS array_partition variable=v33 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v33 cyclic dim=3 factor=7

  loop12: for (int v34 = 0; v34 < 16; v34++) {
    loop13: for (int v35 = 0; v35 < 16; v35++) {
      loop14: for (int v36 = 0; v36 < 112; v36++) {
        loop15: for (int v37 = 0; v37 < 16; v37++) {
          #pragma HLS pipeline II=1
          #pragma HLS loop_flatten
          loop16: for (int v38 = 0; v38 < 4; v38++) {
            loop17: for (int v39 = 0; v39 < 4; v39++) {
              loop18: for (int v40 = 0; v40 < 1; v40++) {
                loop19: for (int v41 = 0; v41 < 7; v41++) {
                  if ((v39 + (v35 * 4)) == 0) {
                    float v42 = v28[v38][v40][v41].read();
                    v33[(v38 + (v34 * 4))][(v36 + v40)][(v41 + (v37 * 7))] = v42;
                  }
                  float v43 = v33[(v38 + (v34 * 4))][(v36 + v40)][(v41 + (v37 * 7))];
                  float v44 = v29[(v39 + (v35 * 4))][(v38 + (v34 * 4))][0][0];
                  if ((v38 + (v34 * 4)) == 0) {
                    v32[(v39 + (v35 * 4))][(v36 + v40)][(v41 + (v37 * 7))] = v31;
                  }
                  float v45 = v32[(v39 + (v35 * 4))][(v36 + v40)][(v41 + (v37 * 7))];
                  float v46 = v43 * v44;
                  float v47 = v45 + v46;
                  v32[(v39 + (v35 * 4))][(v36 + v40)][(v41 + (v37 * 7))] = v47;
                  if (((v38 + (v34 * 4)) - 63) == 0) {
                    float v48 = v32[(v39 + (v35 * 4))][(v36 + v40)][(v41 + (v37 * 7))];
                    v30[v39][v40][v41].write(v48);
                  }
                }
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
  float v49[64][3][3],
  float v50[64][114][114],
  hls::stream<float> v51[4][1][7],
  float v52
) {
  #pragma HLS array_partition variable=v49 cyclic dim=1 factor=4

  #pragma HLS array_partition variable=v50 cyclic dim=1 factor=4

  float v53[64][112][112];
  #pragma HLS array_partition variable=v53 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v53 cyclic dim=3 factor=7

  loop20: for (int v54 = 0; v54 < 16; v54++) {
    loop21: for (int v55 = 0; v55 < 112; v55++) {
      loop22: for (int v56 = 0; v56 < 3; v56++) {
        loop23: for (int v57 = 0; v57 < 3; v57++) {
          loop24: for (int v58 = 0; v58 < 16; v58++) {
            #pragma HLS pipeline II=1
            #pragma HLS loop_flatten
            loop25: for (int v59 = 0; v59 < 4; v59++) {
              loop26: for (int v60 = 0; v60 < 1; v60++) {
                loop27: for (int v61 = 0; v61 < 1; v61++) {
                  loop28: for (int v62 = 0; v62 < 1; v62++) {
                    loop29: for (int v63 = 0; v63 < 7; v63++) {
                      float v64 = v50[(v59 + (v54 * 4))][(((v55 + v60) + v56) + v61)][(((v63 + (v58 * 7)) + v57) + v62)];
                      float v65 = v49[(v59 + (v54 * 4))][(v56 + v61)][(v57 + v62)];
                      if ((v56 + v61) == 0 && (v57 + v62) == 0) {
                        v53[(v59 + (v54 * 4))][(v55 + v60)][(v63 + (v58 * 7))] = v52;
                      }
                      float v66 = v53[(v59 + (v54 * 4))][(v55 + v60)][(v63 + (v58 * 7))];
                      float v67 = v64 * v65;
                      float v68 = v66 + v67;
                      v53[(v59 + (v54 * 4))][(v55 + v60)][(v63 + (v58 * 7))] = v68;
                      if (((v56 + v61) - 2) == 0 && ((v57 + v62) - 2) == 0) {
                        float v69 = v53[(v59 + (v54 * 4))][(v55 + v60)][(v63 + (v58 * 7))];
                        v51[v59][v60][v63].write(v69);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node4(
  float v70[1][64][112][112],
  float v71[64][114][114]
) {
  #pragma HLS array_partition variable=v70 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v71 cyclic dim=1 factor=4

  loop30: for (int v72 = 0; v72 < 16; v72++) {
    loop31: for (int v73 = 0; v73 < 112; v73++) {
      loop32: for (int v74 = 0; v74 < 112; v74++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop33: for (int v75 = 0; v75 < 4; v75++) {
          loop34: for (int v76 = 0; v76 < 1; v76++) {
            loop35: for (int v77 = 0; v77 < 1; v77++) {
              float v78 = v70[0][(v75 + (v72 * 4))][(v73 + v76)][(v74 + v77)];
              v71[(v75 + (v72 * 4))][((v73 + v76) + 1)][((v74 + v77) + 1)] = v78;
            }
          }
        }
      }
    }
  }
  return ;
}

void node5(
  float v79[64][114][114],
  float v80
) {
  #pragma HLS array_partition variable=v79 cyclic dim=1 factor=4

  loop36: for (int v81 = 0; v81 < 16; v81++) {
    loop37: for (int v82 = 0; v82 < 114; v82++) {
      loop38: for (int v83 = 0; v83 < 114; v83++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop39: for (int v84 = 0; v84 < 4; v84++) {
          loop40: for (int v85 = 0; v85 < 1; v85++) {
            loop41: for (int v86 = 0; v86 < 1; v86++) {
              v79[(v84 + (v81 * 4))][(v82 + v85)][(v83 + v86)] = v80;
            }
          }
        }
      }
    }
  }
  return ;
}

void forward(
  float v87[1][64][112][112],
  float v88[64][64][1][1],
  float v89[64][3][3],
  float v90[1][64][112][112]
) {
	// #pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v87 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v89 cyclic dim=1 factor=4

  #pragma HLS array_partition variable=v90 cyclic dim=2 factor=4
  #pragma HLS array_partition variable=v90 cyclic dim=4 factor=7

  hls::stream<float> v91[4][1][7];
	#pragma HLS STREAM variable=v91 depth=28672
  hls::stream<float> v92[4][1][7];
	#pragma HLS STREAM variable=v92 depth=28672
  hls::stream<float> v93[4][1][7];
	#pragma HLS STREAM variable=v93 depth=28672
  float v94[64][114][114];
  #pragma HLS array_partition variable=v94 cyclic dim=1 factor=4

  node5(v94, 0.000000);
  node4(v87, v94);
  node3(v89, v94, v93, 0.000000);
  node2(v93, v88, v92, 0.000000);
  node1(v92, v91, 0.000010, 1.000000, 0.000000);
  node0(v91, v90);
  return ;
}

