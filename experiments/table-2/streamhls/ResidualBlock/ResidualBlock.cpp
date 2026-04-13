
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
  hls::stream<float> v0[2][2][4],
  float v1[1][32][112][112]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=2 factor=2
  #pragma HLS array_partition variable=v1 cyclic dim=3 factor=2
  #pragma HLS array_partition variable=v1 cyclic dim=4 factor=4

  loop0: for (int v2 = 0; v2 < 56; v2++) {
    loop1: for (int v3 = 0; v3 < 28; v3++) {
      loop2: for (int v4 = 0; v4 < 16; v4++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop3: for (int v5 = 0; v5 < 2; v5++) {
          loop4: for (int v6 = 0; v6 < 4; v6++) {
            loop5: for (int v7 = 0; v7 < 2; v7++) {
              float v8 = v0[v7][v5][v6].read();
              v1[0][(v7 + (v4 * 2))][(v5 + (v2 * 2))][(v6 + (v3 * 4))] = v8;
            }
          }
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v9[2][2][4],
  float v10[1][32][112][112],
  hls::stream<float> v11[2][2][4],
  double v12,
  float v13,
  float v14
) {
  #pragma HLS array_partition variable=v10 cyclic dim=2 factor=4
  #pragma HLS array_partition variable=v10 cyclic dim=3 factor=2

  loop6: for (int v15 = 0; v15 < 56; v15++) {
    loop7: for (int v16 = 0; v16 < 28; v16++) {
      loop8: for (int v17 = 0; v17 < 16; v17++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop9: for (int v18 = 0; v18 < 2; v18++) {
          loop10: for (int v19 = 0; v19 < 4; v19++) {
            loop11: for (int v20 = 0; v20 < 2; v20++) {
              float v21 = v9[v20][v18][v19].read();
              float v22 = v10[0][(v20 + (v17 * 2))][(v18 + (v15 * 2))][(v19 + (v16 * 4))];
              float v23 = v12;
              float v24 = v23 + v13;
              float v25 = 1.0 / sqrt(v24);
              float v26 = v21 * v25;
              float v27 = v26 + v14;
              float v28 = v27 + v22;
              bool v29 = v28 > v14;
              float v30 = v29 ? (float)v28 : (float)v14;
              v11[v20][v18][v19].write(v30);
            }
          }
        }
      }
    }
  }
  return ;
}

void node2(
  float v31[32][114][114],
  float v32[32][32][3][3],
  hls::stream<float> v33[2][2][4],
  float v34
) {
  #pragma HLS array_partition variable=v31 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v31 cyclic dim=2 factor=2

  #pragma HLS array_partition variable=v32 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v32 cyclic dim=2 factor=4

  float v35[32][112][112];
  #pragma HLS array_partition variable=v35 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v35 cyclic dim=2 factor=2
  #pragma HLS array_partition variable=v35 cyclic dim=3 factor=4

  loop12: for (int v36 = 0; v36 < 56; v36++) {
    loop13: for (int v37 = 0; v37 < 28; v37++) {
      loop14: for (int v38 = 0; v38 < 3; v38++) {
        loop15: for (int v39 = 0; v39 < 8; v39++) {
          loop16: for (int v40 = 0; v40 < 3; v40++) {
            loop17: for (int v41 = 0; v41 < 16; v41++) {
              #pragma HLS pipeline II=1
              #pragma HLS loop_flatten
              loop18: for (int v42 = 0; v42 < 2; v42++) {
                loop19: for (int v43 = 0; v43 < 4; v43++) {
                  loop20: for (int v44 = 0; v44 < 1; v44++) {
                    loop21: for (int v45 = 0; v45 < 4; v45++) {
                      loop22: for (int v46 = 0; v46 < 1; v46++) {
                        loop23: for (int v47 = 0; v47 < 2; v47++) {
                          float v48 = v31[(v45 + (v39 * 4))][(((v42 + (v36 * 2)) + v38) + v44)][(((v43 + (v37 * 4)) + v40) + v46)];
                          float v49 = v32[(v47 + (v41 * 2))][(v45 + (v39 * 4))][(v38 + v44)][(v40 + v46)];
                          if ((v45 + (v39 * 4)) == 0 && (v38 + v44) == 0 && (v40 + v46) == 0) {
                            v35[(v47 + (v41 * 2))][(v42 + (v36 * 2))][(v43 + (v37 * 4))] = v34;
                          }
                          float v50 = v35[(v47 + (v41 * 2))][(v42 + (v36 * 2))][(v43 + (v37 * 4))];
                          float v51 = v48 * v49;
                          float v52 = v50 + v51;
                          v35[(v47 + (v41 * 2))][(v42 + (v36 * 2))][(v43 + (v37 * 4))] = v52;
                          if (((v45 + (v39 * 4)) - 31) == 0 && ((v38 + v44) - 2) == 0 && ((v40 + v46) - 2) == 0) {
                            float v53 = v35[(v47 + (v41 * 2))][(v42 + (v36 * 2))][(v43 + (v37 * 4))];
                            v33[v47][v42][v43].write(v53);
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
    }
  }
  return ;
}

void node3(
  hls::stream<float> v54[4][2][1],
  float v55[32][114][114]
) {
  #pragma HLS array_partition variable=v55 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v55 cyclic dim=2 factor=2

  loop24: for (int v56 = 0; v56 < 112; v56++) {
    loop25: for (int v57 = 0; v57 < 56; v57++) {
      loop26: for (int v58 = 0; v58 < 8; v58++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop27: for (int v59 = 0; v59 < 1; v59++) {
          loop28: for (int v60 = 0; v60 < 2; v60++) {
            loop29: for (int v61 = 0; v61 < 4; v61++) {
              float v62 = v54[v61][v60][v59].read();
              v55[(v61 + (v58 * 4))][((v60 + (v57 * 2)) + 1)][((v56 + v59) + 1)] = v62;
            }
          }
        }
      }
    }
  }
  return ;
}

void node4(
  float v63[32][114][114],
  float v64
) {
  #pragma HLS array_partition variable=v63 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v63 cyclic dim=2 factor=2

  loop30: for (int v65 = 0; v65 < 8; v65++) {
    loop31: for (int v66 = 0; v66 < 57; v66++) {
      loop32: for (int v67 = 0; v67 < 114; v67++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop33: for (int v68 = 0; v68 < 4; v68++) {
          loop34: for (int v69 = 0; v69 < 2; v69++) {
            loop35: for (int v70 = 0; v70 < 1; v70++) {
              v63[(v68 + (v65 * 4))][(v69 + (v66 * 2))][(v67 + v70)] = v64;
            }
          }
        }
      }
    }
  }
  return ;
}

void node5(
  hls::stream<float> v71[4][2][1],
  hls::stream<float> v72[4][2][1],
  double v73,
  float v74,
  float v75
) {
  loop36: for (int v76 = 0; v76 < 112; v76++) {
    loop37: for (int v77 = 0; v77 < 56; v77++) {
      loop38: for (int v78 = 0; v78 < 8; v78++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop39: for (int v79 = 0; v79 < 1; v79++) {
          loop40: for (int v80 = 0; v80 < 2; v80++) {
            loop41: for (int v81 = 0; v81 < 4; v81++) {
              float v82 = v71[v81][v80][v79].read();
              float v83 = v73;
              float v84 = v83 + v74;
              float v85 = 1.0 / sqrt(v84);
              float v86 = v82 * v85;
              float v87 = v86 + v75;
              bool v88 = v87 > v75;
              float v89 = v88 ? (float)v87 : (float)v75;
              v72[v81][v80][v79].write(v89);
            }
          }
        }
      }
    }
  }
  return ;
}

void node6(
  float v90[32][32][3][3],
  float v91[32][114][114],
  hls::stream<float> v92[4][2][1],
  float v93
) {
  #pragma HLS array_partition variable=v90 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v90 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v91 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v91 cyclic dim=2 factor=2

  float v94[32][112][112];
  #pragma HLS array_partition variable=v94 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v94 cyclic dim=2 factor=2

  loop42: for (int v95 = 0; v95 < 3; v95++) {
    loop43: for (int v96 = 0; v96 < 112; v96++) {
      loop44: for (int v97 = 0; v97 < 3; v97++) {
        loop45: for (int v98 = 0; v98 < 56; v98++) {
          loop46: for (int v99 = 0; v99 < 8; v99++) {
            loop47: for (int v100 = 0; v100 < 8; v100++) {
              #pragma HLS pipeline II=1
              #pragma HLS loop_flatten
              loop48: for (int v101 = 0; v101 < 1; v101++) {
                loop49: for (int v102 = 0; v102 < 1; v102++) {
                  loop50: for (int v103 = 0; v103 < 1; v103++) {
                    loop51: for (int v104 = 0; v104 < 2; v104++) {
                      loop52: for (int v105 = 0; v105 < 4; v105++) {
                        loop53: for (int v106 = 0; v106 < 4; v106++) {
                          float v107 = v91[(v105 + (v99 * 4))][(((v104 + (v98 * 2)) + v97) + v103)][(((v96 + v102) + v95) + v101)];
                          float v108 = v90[(v106 + (v100 * 4))][(v105 + (v99 * 4))][(v97 + v103)][(v95 + v101)];
                          if ((v105 + (v99 * 4)) == 0 && (v97 + v103) == 0 && (v95 + v101) == 0) {
                            v94[(v106 + (v100 * 4))][(v104 + (v98 * 2))][(v96 + v102)] = v93;
                          }
                          float v109 = v94[(v106 + (v100 * 4))][(v104 + (v98 * 2))][(v96 + v102)];
                          float v110 = v107 * v108;
                          float v111 = v109 + v110;
                          v94[(v106 + (v100 * 4))][(v104 + (v98 * 2))][(v96 + v102)] = v111;
                          if (((v105 + (v99 * 4)) - 31) == 0 && ((v97 + v103) - 2) == 0 && ((v95 + v101) - 2) == 0) {
                            float v112 = v94[(v106 + (v100 * 4))][(v104 + (v98 * 2))][(v96 + v102)];
                            v92[v106][v104][v102].write(v112);
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
    }
  }
  return ;
}

void node7(
  float v113[1][32][112][112],
  float v114[32][114][114]
) {
  #pragma HLS array_partition variable=v113 cyclic dim=2 factor=4
  #pragma HLS array_partition variable=v113 cyclic dim=3 factor=2

  #pragma HLS array_partition variable=v114 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v114 cyclic dim=2 factor=2

  loop54: for (int v115 = 0; v115 < 8; v115++) {
    loop55: for (int v116 = 0; v116 < 56; v116++) {
      loop56: for (int v117 = 0; v117 < 112; v117++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop57: for (int v118 = 0; v118 < 4; v118++) {
          loop58: for (int v119 = 0; v119 < 2; v119++) {
            loop59: for (int v120 = 0; v120 < 1; v120++) {
              float v121 = v113[0][(v118 + (v115 * 4))][(v119 + (v116 * 2))][(v117 + v120)];
              v114[(v118 + (v115 * 4))][((v119 + (v116 * 2)) + 1)][((v117 + v120) + 1)] = v121;
            }
          }
        }
      }
    }
  }
  return ;
}

void node8(
  float v122[32][114][114],
  float v123
) {
  #pragma HLS array_partition variable=v122 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v122 cyclic dim=2 factor=2

  loop60: for (int v124 = 0; v124 < 8; v124++) {
    loop61: for (int v125 = 0; v125 < 57; v125++) {
      loop62: for (int v126 = 0; v126 < 114; v126++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop63: for (int v127 = 0; v127 < 4; v127++) {
          loop64: for (int v128 = 0; v128 < 2; v128++) {
            loop65: for (int v129 = 0; v129 < 1; v129++) {
              v122[(v127 + (v124 * 4))][(v128 + (v125 * 2))][(v126 + v129)] = v123;
            }
          }
        }
      }
    }
  }
  return ;
}

void forward(
  float v130[1][32][112][112],
  float v131[32][32][3][3],
  float v132[32][32][3][3],
  float v133[1][32][112][112]
) {
	// #pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v130 cyclic dim=2 factor=4
  #pragma HLS array_partition variable=v130 cyclic dim=3 factor=2

  #pragma HLS array_partition variable=v131 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v131 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v132 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v132 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v133 cyclic dim=2 factor=2
  #pragma HLS array_partition variable=v133 cyclic dim=3 factor=2
  #pragma HLS array_partition variable=v133 cyclic dim=4 factor=4

  hls::stream<float> v134[2][2][4];
	#pragma HLS STREAM variable=v134 depth=25088
  hls::stream<float> v135[2][2][4];
	#pragma HLS STREAM variable=v135 depth=25088
  float v136[32][114][114];
  #pragma HLS array_partition variable=v136 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v136 cyclic dim=2 factor=2

  hls::stream<float> v137[4][2][1];
	#pragma HLS STREAM variable=v137 depth=50176
  hls::stream<float> v138[4][2][1];
	#pragma HLS STREAM variable=v138 depth=50176
  float v139[32][114][114];
  #pragma HLS array_partition variable=v139 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v139 cyclic dim=2 factor=2

  node8(v139, 0.000000);
  node7(v130, v139);
  node6(v131, v139, v138, 0.000000);
  node5(v138, v137, 0.000010, 1.000000, 0.000000);
  node4(v136, 0.000000);
  node3(v137, v136);
  node2(v136, v132, v135, 0.000000);
  node1(v135, v130, v134, 0.000010, 1.000000, 0.000000);
  node0(v134, v133);
  return ;
}

