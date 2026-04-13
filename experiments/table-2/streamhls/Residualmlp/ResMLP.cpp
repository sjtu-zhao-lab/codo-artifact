
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
  hls::stream<float> v0[1][1],
  float v1[8][10]
) {
  loop0: for (int v2 = 0; v2 < 8; v2++) {
    loop1: for (int v3 = 0; v3 < 10; v3++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop2: for (int v4 = 0; v4 < 1; v4++) {
        loop3: for (int v5 = 0; v5 < 1; v5++) {
          float v6 = v0[v4][v5].read();
          v1[(v2 + v4)][(v3 + v5)] = v6;
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v7[1][1],
  float v8[10],
  hls::stream<float> v9[1][1]
) {
  loop4: for (int v10 = 0; v10 < 8; v10++) {
    loop5: for (int v11 = 0; v11 < 10; v11++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop6: for (int v12 = 0; v12 < 1; v12++) {
        loop7: for (int v13 = 0; v13 < 1; v13++) {
          float v14 = v7[v12][v13].read();
          float v15 = v8[(v11 + v13)];
          float v16 = v14 + v15;
          v9[v12][v13].write(v16);
        }
      }
    }
  }
  return ;
}

void node2(
  hls::stream<float> v17[4][1],
  hls::stream<float> v18[1][4],
  hls::stream<float> v19[1][1],
  float v20
) {
  float v21[8][10];
  float v22[256][10];
  #pragma HLS array_partition variable=v22 cyclic dim=1 factor=4

  float v23[8][256];
  #pragma HLS array_partition variable=v23 cyclic dim=2 factor=4

  loop8: for (int v24 = 0; v24 < 8; v24++) {
    loop9: for (int v25 = 0; v25 < 64; v25++) {
      loop10: for (int v26 = 0; v26 < 10; v26++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop11: for (int v27 = 0; v27 < 1; v27++) {
          loop12: for (int v28 = 0; v28 < 4; v28++) {
            loop13: for (int v29 = 0; v29 < 1; v29++) {
              if ((v26 + v29) == 0) {
                float v30 = v18[v27][v28].read();
                v23[(v24 + v27)][(v28 + (v25 * 4))] = v30;
              }
              float v31 = v23[(v24 + v27)][(v28 + (v25 * 4))];
              if ((v24 + v27) == 0) {
                float v32 = v17[v28][v29].read();
                v22[(v28 + (v25 * 4))][(v26 + v29)] = v32;
              }
              float v33 = v22[(v28 + (v25 * 4))][(v26 + v29)];
              if ((v28 + (v25 * 4)) == 0) {
                v21[(v24 + v27)][(v26 + v29)] = v20;
              }
              float v34 = v21[(v24 + v27)][(v26 + v29)];
              float v35 = v31 * v33;
              float v36 = v34 + v35;
              v21[(v24 + v27)][(v26 + v29)] = v36;
              if (((v28 + (v25 * 4)) - 255) == 0) {
                float v37 = v21[(v24 + v27)][(v26 + v29)];
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
  float v38[10][256],
  hls::stream<float> v39[4][1]
) {
  #pragma HLS array_partition variable=v38 cyclic dim=2 factor=4

  loop14: for (int v40 = 0; v40 < 64; v40++) {
    loop15: for (int v41 = 0; v41 < 10; v41++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop16: for (int v42 = 0; v42 < 4; v42++) {
        loop17: for (int v43 = 0; v43 < 1; v43++) {
          float v44 = v38[(v41 + v43)][(v42 + (v40 * 4))];
          v39[v42][v43].write(v44);
        }
      }
    }
  }
  return ;
}

void node4(
  hls::stream<float> v45[1][4],
  float v46[256],
  hls::stream<float> v47[1][4]
) {
  #pragma HLS array_partition variable=v46 cyclic dim=1 factor=4

  loop18: for (int v48 = 0; v48 < 8; v48++) {
    loop19: for (int v49 = 0; v49 < 64; v49++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop20: for (int v50 = 0; v50 < 1; v50++) {
        loop21: for (int v51 = 0; v51 < 4; v51++) {
          float v52 = v45[v50][v51].read();
          float v53 = v46[(v51 + (v49 * 4))];
          float v54 = v52 + v53;
          v47[v50][v51].write(v54);
        }
      }
    }
  }
  return ;
}

void node5(
  hls::stream<float> v55[1][8],
  float v56[512][256],
  hls::stream<float> v57[1][4],
  float v58
) {
  #pragma HLS array_partition variable=v56 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v56 cyclic dim=2 factor=4

  float v59[8][256];
  #pragma HLS array_partition variable=v59 cyclic dim=2 factor=4

  float v60[512][256];
  #pragma HLS array_partition variable=v60 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v60 cyclic dim=2 factor=4

  float v61[8][512];
  #pragma HLS array_partition variable=v61 cyclic dim=2 factor=8

  loop22: for (int v62 = 0; v62 < 8; v62++) {
    loop23: for (int v63 = 0; v63 < 64; v63++) {
      loop24: for (int v64 = 0; v64 < 64; v64++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop25: for (int v65 = 0; v65 < 1; v65++) {
          loop26: for (int v66 = 0; v66 < 8; v66++) {
            loop27: for (int v67 = 0; v67 < 4; v67++) {
              if ((v67 + (v64 * 4)) == 0) {
                float v68 = v55[v65][v66].read();
                v61[(v62 + v65)][(v66 + (v63 * 8))] = v68;
              }
              float v69 = v61[(v62 + v65)][(v66 + (v63 * 8))];
              if ((v62 + v65) == 0) {
                float v70 = v56[(v66 + (v63 * 8))][(v67 + (v64 * 4))];
                v60[(v66 + (v63 * 8))][(v67 + (v64 * 4))] = v70;
              }
              float v71 = v60[(v66 + (v63 * 8))][(v67 + (v64 * 4))];
              if ((v66 + (v63 * 8)) == 0) {
                v59[(v62 + v65)][(v67 + (v64 * 4))] = v58;
              }
              float v72 = v59[(v62 + v65)][(v67 + (v64 * 4))];
              float v73 = v69 * v71;
              float v74 = v72 + v73;
              v59[(v62 + v65)][(v67 + (v64 * 4))] = v74;
              if (((v66 + (v63 * 8)) - 511) == 0) {
                float v75 = v59[(v62 + v65)][(v67 + (v64 * 4))];
                v57[v65][v67].write(v75);
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
  float v76[256][512],
  float v77[512][256]
) {
  #pragma HLS array_partition variable=v76 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v76 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v77 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v77 cyclic dim=2 factor=4

  loop28: for (int v78 = 0; v78 < 64; v78++) {
    loop29: for (int v79 = 0; v79 < 64; v79++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop30: for (int v80 = 0; v80 < 4; v80++) {
        loop31: for (int v81 = 0; v81 < 8; v81++) {
          float v82 = v76[(v80 + (v78 * 4))][(v81 + (v79 * 8))];
          v77[(v81 + (v79 * 8))][(v80 + (v78 * 4))] = v82;
        }
      }
    }
  }
  return ;
}

void node7(
  hls::stream<float> v83[1][8],
  float v84[512],
  hls::stream<float> v85[1][8],
  hls::stream<float> v86[1][8],
  float v87
) {
  #pragma HLS array_partition variable=v84 cyclic dim=1 factor=8

  loop32: for (int v88 = 0; v88 < 8; v88++) {
    loop33: for (int v89 = 0; v89 < 64; v89++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop34: for (int v90 = 0; v90 < 1; v90++) {
        loop35: for (int v91 = 0; v91 < 8; v91++) {
          float v92 = v83[v90][v91].read();
          float v93 = v84[(v91 + (v89 * 8))];
          float v94 = v85[v90][v91].read();
          float v95 = v92 + v93;
          float v96 = v95 + v94;
          bool v97 = v96 > v87;
          float v98 = v97 ? (float)v96 : (float)v87;
          v86[v90][v91].write(v98);
        }
      }
    }
  }
  return ;
}

void node8(
  hls::stream<float> v99[8][8],
  hls::stream<float> v100[1][8],
  hls::stream<float> v101[1][8],
  float v102
) {
  float v103[8][512];
  #pragma HLS array_partition variable=v103 cyclic dim=2 factor=8

  float v104[512][512];
  #pragma HLS array_partition variable=v104 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v104 cyclic dim=2 factor=8

  float v105[8][512];
  #pragma HLS array_partition variable=v105 cyclic dim=2 factor=8

  loop36: for (int v106 = 0; v106 < 8; v106++) {
    loop37: for (int v107 = 0; v107 < 64; v107++) {
      loop38: for (int v108 = 0; v108 < 64; v108++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop39: for (int v109 = 0; v109 < 1; v109++) {
          loop40: for (int v110 = 0; v110 < 8; v110++) {
            loop41: for (int v111 = 0; v111 < 8; v111++) {
              if ((v111 + (v108 * 8)) == 0) {
                float v112 = v100[v109][v110].read();
                v105[(v106 + v109)][(v110 + (v107 * 8))] = v112;
              }
              float v113 = v105[(v106 + v109)][(v110 + (v107 * 8))];
              if ((v106 + v109) == 0) {
                float v114 = v99[v110][v111].read();
                v104[(v110 + (v107 * 8))][(v111 + (v108 * 8))] = v114;
              }
              float v115 = v104[(v110 + (v107 * 8))][(v111 + (v108 * 8))];
              if ((v110 + (v107 * 8)) == 0) {
                v103[(v106 + v109)][(v111 + (v108 * 8))] = v102;
              }
              float v116 = v103[(v106 + v109)][(v111 + (v108 * 8))];
              float v117 = v113 * v115;
              float v118 = v116 + v117;
              v103[(v106 + v109)][(v111 + (v108 * 8))] = v118;
              if (((v110 + (v107 * 8)) - 511) == 0) {
                float v119 = v103[(v106 + v109)][(v111 + (v108 * 8))];
                v101[v109][v111].write(v119);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node9(
  float v120[512][512],
  hls::stream<float> v121[8][8]
) {
  #pragma HLS array_partition variable=v120 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v120 cyclic dim=2 factor=8

  loop42: for (int v122 = 0; v122 < 64; v122++) {
    loop43: for (int v123 = 0; v123 < 64; v123++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop44: for (int v124 = 0; v124 < 8; v124++) {
        loop45: for (int v125 = 0; v125 < 8; v125++) {
          float v126 = v120[(v125 + (v123 * 8))][(v124 + (v122 * 8))];
          v121[v124][v125].write(v126);
        }
      }
    }
  }
  return ;
}

void node10(
  hls::stream<float> v127[1][8],
  hls::stream<float> v128[1][8],
  float v129
) {
  loop46: for (int v130 = 0; v130 < 8; v130++) {
    loop47: for (int v131 = 0; v131 < 64; v131++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop48: for (int v132 = 0; v132 < 1; v132++) {
        loop49: for (int v133 = 0; v133 < 8; v133++) {
          float v134 = v127[v132][v133].read();
          bool v135 = v134 > v129;
          float v136 = v135 ? (float)v134 : (float)v129;
          v128[v132][v133].write(v136);
        }
      }
    }
  }
  return ;
}

void node11(
  hls::stream<float> v137[1][8],
  float v138[512],
  hls::stream<float> v139[1][8],
  hls::stream<float> v140[1][8]
) {
  #pragma HLS array_partition variable=v138 cyclic dim=1 factor=8

  loop50: for (int v141 = 0; v141 < 8; v141++) {
    loop51: for (int v142 = 0; v142 < 64; v142++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop52: for (int v143 = 0; v143 < 1; v143++) {
        loop53: for (int v144 = 0; v144 < 8; v144++) {
          float v145 = v137[v143][v144].read();
          float v146 = v138[(v144 + (v142 * 8))];
          float v147 = v145 + v146;
          v139[v143][v144].write(v147);
          v140[v143][v144].write(v147);
        }
      }
    }
  }
  return ;
}

void node12(
  float v148[8][1024],
  hls::stream<float> v149[8][8],
  hls::stream<float> v150[1][8],
  float v151
) {
  #pragma HLS array_partition variable=v148 cyclic dim=2 factor=8

  float v152[8][512];
  #pragma HLS array_partition variable=v152 cyclic dim=2 factor=8

  float v153[1024][512];
  #pragma HLS array_partition variable=v153 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v153 cyclic dim=2 factor=8

  loop54: for (int v154 = 0; v154 < 8; v154++) {
    loop55: for (int v155 = 0; v155 < 128; v155++) {
      loop56: for (int v156 = 0; v156 < 64; v156++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop57: for (int v157 = 0; v157 < 1; v157++) {
          loop58: for (int v158 = 0; v158 < 8; v158++) {
            loop59: for (int v159 = 0; v159 < 8; v159++) {
              float v160 = v148[(v154 + v157)][(v158 + (v155 * 8))];
              if ((v154 + v157) == 0) {
                float v161 = v149[v158][v159].read();
                v153[(v158 + (v155 * 8))][(v159 + (v156 * 8))] = v161;
              }
              float v162 = v153[(v158 + (v155 * 8))][(v159 + (v156 * 8))];
              if ((v158 + (v155 * 8)) == 0) {
                v152[(v154 + v157)][(v159 + (v156 * 8))] = v151;
              }
              float v163 = v152[(v154 + v157)][(v159 + (v156 * 8))];
              float v164 = v160 * v162;
              float v165 = v163 + v164;
              v152[(v154 + v157)][(v159 + (v156 * 8))] = v165;
              if (((v158 + (v155 * 8)) - 1023) == 0) {
                float v166 = v152[(v154 + v157)][(v159 + (v156 * 8))];
                v150[v157][v159].write(v166);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node13(
  float v167[512][1024],
  hls::stream<float> v168[8][8]
) {
  #pragma HLS array_partition variable=v167 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v167 cyclic dim=2 factor=8

  loop60: for (int v169 = 0; v169 < 128; v169++) {
    loop61: for (int v170 = 0; v170 < 64; v170++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop62: for (int v171 = 0; v171 < 8; v171++) {
        loop63: for (int v172 = 0; v172 < 8; v172++) {
          float v173 = v167[(v172 + (v170 * 8))][(v171 + (v169 * 8))];
          v168[v171][v172].write(v173);
        }
      }
    }
  }
  return ;
}

void forward(
  float v174[8][1024],
  float v175[512],
  float v176[512][1024],
  float v177[512],
  float v178[512][512],
  float v179[256],
  float v180[256][512],
  float v181[10],
  float v182[10][256],
  float v183[8][10]
) {
	#pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v174 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v175 cyclic dim=1 factor=8

  #pragma HLS array_partition variable=v176 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v176 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v177 cyclic dim=1 factor=8

  #pragma HLS array_partition variable=v178 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v178 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v179 cyclic dim=1 factor=4

  #pragma HLS array_partition variable=v180 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v180 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v182 cyclic dim=2 factor=4

  hls::stream<float> v184[1][1];
	#pragma HLS STREAM variable=v184 depth=80
  hls::stream<float> v185[1][1];
	#pragma HLS STREAM variable=v185 depth=80
  hls::stream<float> v186[4][1];
	#pragma HLS STREAM variable=v186 depth=640
  hls::stream<float> v187[1][4];
	#pragma HLS STREAM variable=v187 depth=512
  hls::stream<float> v188[1][4];
	#pragma HLS STREAM variable=v188 depth=512
  float v189[512][256];
  #pragma HLS array_partition variable=v189 cyclic dim=1 factor=8
  #pragma HLS array_partition variable=v189 cyclic dim=2 factor=4

  hls::stream<float> v190[1][8];
	#pragma HLS STREAM variable=v190 depth=512
  hls::stream<float> v191[1][8];
	#pragma HLS STREAM variable=v191 depth=512
  hls::stream<float> v192[8][8];
	#pragma HLS STREAM variable=v192 depth=4096
  hls::stream<float> v193[1][8];
	#pragma HLS STREAM variable=v193 depth=512
  hls::stream<float> v194[1][8];
	#pragma HLS STREAM variable=v194 depth=512
  hls::stream<float> v195[1][8];
	#pragma HLS STREAM variable=v195 depth=512
  hls::stream<float> v196[1][8];
	#pragma HLS STREAM variable=v196 depth=512
  hls::stream<float> v197[8][8];
	#pragma HLS STREAM variable=v197 depth=8192
  node13(v176, v197);
  node12(v174, v197, v196, 0.000000);
  node11(v196, v175, v195, v194);
  node10(v195, v193, 0.000000);
  node9(v178, v192);
  node8(v192, v193, v191, 0.000000);
  node7(v191, v177, v194, v190, 0.000000);
  node6(v180, v189);
  node5(v190, v189, v188, 0.000000);
  node4(v188, v179, v187);
  node3(v182, v186);
  node2(v186, v187, v185, 0.000000);
  node1(v185, v181, v184);
  node0(v184, v183);
  return ;
}

