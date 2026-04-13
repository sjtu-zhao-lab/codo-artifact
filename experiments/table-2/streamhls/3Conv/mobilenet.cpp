
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
  hls::stream<float> v0[2][2][2],
  float v1[1][32][32][32]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=2 factor=2
  #pragma HLS array_partition variable=v1 cyclic dim=3 factor=2
  #pragma HLS array_partition variable=v1 cyclic dim=4 factor=2

  loop0: for (int v2 = 0; v2 < 16; v2++) {
    loop1: for (int v3 = 0; v3 < 16; v3++) {
      loop2: for (int v4 = 0; v4 < 16; v4++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop3: for (int v5 = 0; v5 < 2; v5++) {
          loop4: for (int v6 = 0; v6 < 2; v6++) {
            loop5: for (int v7 = 0; v7 < 2; v7++) {
              float v8 = v0[v5][v6][v7].read();
              v1[0][(v5 + (v2 * 2))][(v6 + (v3 * 2))][(v7 + (v4 * 2))] = v8;
            }
          }
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v9[2][2][2],
  hls::stream<float> v10[2][2][2],
  float v11
) {
  loop6: for (int v12 = 0; v12 < 16; v12++) {
    loop7: for (int v13 = 0; v13 < 16; v13++) {
      loop8: for (int v14 = 0; v14 < 16; v14++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop9: for (int v15 = 0; v15 < 2; v15++) {
          loop10: for (int v16 = 0; v16 < 2; v16++) {
            loop11: for (int v17 = 0; v17 < 2; v17++) {
              float v18 = v9[v15][v16][v17].read();
              bool v19 = v18 > v11;
              float v20 = v19 ? (float)v18 : (float)v11;
              v10[v15][v16][v17].write(v20);
            }
          }
        }
      }
    }
  }
  return ;
}

void node2(
  float v21[32][32][3][3],
  float v22[32][34][34],
  hls::stream<float> v23[2][2][2],
  float v24
) {
  #pragma HLS array_partition variable=v21 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v21 cyclic dim=2 factor=2

  #pragma HLS array_partition variable=v22 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v22 cyclic dim=2 factor=2

  float v25[32][32][32];
  #pragma HLS array_partition variable=v25 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v25 cyclic dim=2 factor=2
  #pragma HLS array_partition variable=v25 cyclic dim=3 factor=2

  loop12: for (int v26 = 0; v26 < 3; v26++) {
    loop13: for (int v27 = 0; v27 < 16; v27++) {
      loop14: for (int v28 = 0; v28 < 16; v28++) {
        loop15: for (int v29 = 0; v29 < 16; v29++) {
          loop16: for (int v30 = 0; v30 < 3; v30++) {
            loop17: for (int v31 = 0; v31 < 16; v31++) {
              #pragma HLS pipeline II=1
              #pragma HLS loop_flatten
              loop18: for (int v32 = 0; v32 < 1; v32++) {
                loop19: for (int v33 = 0; v33 < 2; v33++) {
                  loop20: for (int v34 = 0; v34 < 2; v34++) {
                    loop21: for (int v35 = 0; v35 < 2; v35++) {
                      loop22: for (int v36 = 0; v36 < 1; v36++) {
                        loop23: for (int v37 = 0; v37 < 2; v37++) {
                          float v38 = v22[(v34 + (v28 * 2))][(((v35 + (v29 * 2)) + v26) + v32)][(((v37 + (v31 * 2)) + v30) + v36)];
                          float v39 = v21[(v33 + (v27 * 2))][(v34 + (v28 * 2))][(v26 + v32)][(v30 + v36)];
                          if ((v34 + (v28 * 2)) == 0 && (v26 + v32) == 0 && (v30 + v36) == 0) {
                            v25[(v33 + (v27 * 2))][(v35 + (v29 * 2))][(v37 + (v31 * 2))] = v24;
                          }
                          float v40 = v25[(v33 + (v27 * 2))][(v35 + (v29 * 2))][(v37 + (v31 * 2))];
                          float v41 = v38 * v39;
                          float v42 = v40 + v41;
                          v25[(v33 + (v27 * 2))][(v35 + (v29 * 2))][(v37 + (v31 * 2))] = v42;
                          if (((v34 + (v28 * 2)) - 31) == 0 && ((v26 + v32) - 2) == 0 && ((v30 + v36) - 2) == 0) {
                            float v43 = v25[(v33 + (v27 * 2))][(v35 + (v29 * 2))][(v37 + (v31 * 2))];
                            v23[v33][v35][v37].write(v43);
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
  hls::stream<float> v44[2][2][1],
  float v45[32][34][34]
) {
  #pragma HLS array_partition variable=v45 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v45 cyclic dim=2 factor=2

  loop24: for (int v46 = 0; v46 < 32; v46++) {
    loop25: for (int v47 = 0; v47 < 16; v47++) {
      loop26: for (int v48 = 0; v48 < 16; v48++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop27: for (int v49 = 0; v49 < 1; v49++) {
          loop28: for (int v50 = 0; v50 < 2; v50++) {
            loop29: for (int v51 = 0; v51 < 2; v51++) {
              float v52 = v44[v51][v50][v49].read();
              v45[(v51 + (v48 * 2))][((v50 + (v47 * 2)) + 1)][((v46 + v49) + 1)] = v52;
            }
          }
        }
      }
    }
  }
  return ;
}

void node4(
  float v53[32][34][34],
  float v54
) {
  #pragma HLS array_partition variable=v53 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v53 cyclic dim=2 factor=2

  loop30: for (int v55 = 0; v55 < 34; v55++) {
    loop31: for (int v56 = 0; v56 < 17; v56++) {
      loop32: for (int v57 = 0; v57 < 16; v57++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop33: for (int v58 = 0; v58 < 1; v58++) {
          loop34: for (int v59 = 0; v59 < 2; v59++) {
            loop35: for (int v60 = 0; v60 < 2; v60++) {
              v53[(v60 + (v57 * 2))][(v59 + (v56 * 2))][(v55 + v58)] = v54;
            }
          }
        }
      }
    }
  }
  return ;
}

void node5(
  hls::stream<float> v61[2][2][1],
  hls::stream<float> v62[2][2][1],
  float v63
) {
  loop36: for (int v64 = 0; v64 < 32; v64++) {
    loop37: for (int v65 = 0; v65 < 16; v65++) {
      loop38: for (int v66 = 0; v66 < 16; v66++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop39: for (int v67 = 0; v67 < 1; v67++) {
          loop40: for (int v68 = 0; v68 < 2; v68++) {
            loop41: for (int v69 = 0; v69 < 2; v69++) {
              float v70 = v61[v69][v68][v67].read();
              bool v71 = v70 > v63;
              float v72 = v71 ? (float)v70 : (float)v63;
              v62[v69][v68][v67].write(v72);
            }
          }
        }
      }
    }
  }
  return ;
}

void node6(
  float v73[32][32][3][3],
  float v74[32][34][34],
  hls::stream<float> v75[2][2][1],
  float v76
) {
  #pragma HLS array_partition variable=v73 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v73 cyclic dim=2 factor=2

  #pragma HLS array_partition variable=v74 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v74 cyclic dim=2 factor=2

  float v77[32][32][32];
  #pragma HLS array_partition variable=v77 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v77 cyclic dim=2 factor=2

  loop42: for (int v78 = 0; v78 < 16; v78++) {
    loop43: for (int v79 = 0; v79 < 32; v79++) {
      loop44: for (int v80 = 0; v80 < 3; v80++) {
        loop45: for (int v81 = 0; v81 < 16; v81++) {
          loop46: for (int v82 = 0; v82 < 3; v82++) {
            loop47: for (int v83 = 0; v83 < 16; v83++) {
              #pragma HLS pipeline II=1
              #pragma HLS loop_flatten
              loop48: for (int v84 = 0; v84 < 2; v84++) {
                loop49: for (int v85 = 0; v85 < 1; v85++) {
                  loop50: for (int v86 = 0; v86 < 1; v86++) {
                    loop51: for (int v87 = 0; v87 < 2; v87++) {
                      loop52: for (int v88 = 0; v88 < 1; v88++) {
                        loop53: for (int v89 = 0; v89 < 2; v89++) {
                          float v90 = v74[(v84 + (v78 * 2))][(((v87 + (v81 * 2)) + v82) + v88)][(((v79 + v85) + v80) + v86)];
                          float v91 = v73[(v89 + (v83 * 2))][(v84 + (v78 * 2))][(v82 + v88)][(v80 + v86)];
                          if ((v84 + (v78 * 2)) == 0 && (v82 + v88) == 0 && (v80 + v86) == 0) {
                            v77[(v89 + (v83 * 2))][(v87 + (v81 * 2))][(v79 + v85)] = v76;
                          }
                          float v92 = v77[(v89 + (v83 * 2))][(v87 + (v81 * 2))][(v79 + v85)];
                          float v93 = v90 * v91;
                          float v94 = v92 + v93;
                          v77[(v89 + (v83 * 2))][(v87 + (v81 * 2))][(v79 + v85)] = v94;
                          if (((v84 + (v78 * 2)) - 31) == 0 && ((v82 + v88) - 2) == 0 && ((v80 + v86) - 2) == 0) {
                            float v95 = v77[(v89 + (v83 * 2))][(v87 + (v81 * 2))][(v79 + v85)];
                            v75[v89][v87][v85].write(v95);
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
  hls::stream<float> v96[2][2][1],
  float v97[32][34][34]
) {
  #pragma HLS array_partition variable=v97 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v97 cyclic dim=2 factor=2

  loop54: for (int v98 = 0; v98 < 16; v98++) {
    loop55: for (int v99 = 0; v99 < 32; v99++) {
      loop56: for (int v100 = 0; v100 < 16; v100++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop57: for (int v101 = 0; v101 < 2; v101++) {
          loop58: for (int v102 = 0; v102 < 1; v102++) {
            loop59: for (int v103 = 0; v103 < 2; v103++) {
              float v104 = v96[v103][v101][v102].read();
              v97[(v103 + (v100 * 2))][((v101 + (v98 * 2)) + 1)][((v99 + v102) + 1)] = v104;
            }
          }
        }
      }
    }
  }
  return ;
}

void node8(
  float v105[32][34][34],
  float v106
) {
  #pragma HLS array_partition variable=v105 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v105 cyclic dim=2 factor=2

  loop60: for (int v107 = 0; v107 < 17; v107++) {
    loop61: for (int v108 = 0; v108 < 34; v108++) {
      loop62: for (int v109 = 0; v109 < 16; v109++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop63: for (int v110 = 0; v110 < 2; v110++) {
          loop64: for (int v111 = 0; v111 < 1; v111++) {
            loop65: for (int v112 = 0; v112 < 2; v112++) {
              v105[(v112 + (v109 * 2))][(v110 + (v107 * 2))][(v108 + v111)] = v106;
            }
          }
        }
      }
    }
  }
  return ;
}

void node9(
  hls::stream<float> v113[2][2][1],
  hls::stream<float> v114[2][2][1],
  float v115
) {
  loop66: for (int v116 = 0; v116 < 16; v116++) {
    loop67: for (int v117 = 0; v117 < 32; v117++) {
      loop68: for (int v118 = 0; v118 < 16; v118++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop69: for (int v119 = 0; v119 < 2; v119++) {
          loop70: for (int v120 = 0; v120 < 1; v120++) {
            loop71: for (int v121 = 0; v121 < 2; v121++) {
              float v122 = v113[v121][v119][v120].read();
              bool v123 = v122 > v115;
              float v124 = v123 ? (float)v122 : (float)v115;
              v114[v121][v119][v120].write(v124);
            }
          }
        }
      }
    }
  }
  return ;
}

void node10(
  float v125[32][3][3][3],
  float v126[3][34][34],
  hls::stream<float> v127[2][2][1],
  float v128
) {
  #pragma HLS array_partition variable=v125 cyclic dim=1 factor=2

  #pragma HLS array_partition variable=v126 cyclic dim=2 factor=2

  float v129[32][32][32];
  #pragma HLS array_partition variable=v129 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v129 cyclic dim=2 factor=2

  loop72: for (int v130 = 0; v130 < 3; v130++) {
    loop73: for (int v131 = 0; v131 < 3; v131++) {
      loop74: for (int v132 = 0; v132 < 3; v132++) {
        loop75: for (int v133 = 0; v133 < 16; v133++) {
          loop76: for (int v134 = 0; v134 < 32; v134++) {
            loop77: for (int v135 = 0; v135 < 16; v135++) {
              #pragma HLS pipeline II=1
              #pragma HLS loop_flatten
              loop78: for (int v136 = 0; v136 < 1; v136++) {
                loop79: for (int v137 = 0; v137 < 1; v137++) {
                  loop80: for (int v138 = 0; v138 < 1; v138++) {
                    loop81: for (int v139 = 0; v139 < 2; v139++) {
                      loop82: for (int v140 = 0; v140 < 1; v140++) {
                        loop83: for (int v141 = 0; v141 < 2; v141++) {
                          float v142 = v126[(v131 + v137)][(((v139 + (v133 * 2)) + v132) + v138)][(((v134 + v140) + v130) + v136)];
                          float v143 = v125[(v141 + (v135 * 2))][(v131 + v137)][(v132 + v138)][(v130 + v136)];
                          if ((v131 + v137) == 0 && (v132 + v138) == 0 && (v130 + v136) == 0) {
                            v129[(v141 + (v135 * 2))][(v139 + (v133 * 2))][(v134 + v140)] = v128;
                          }
                          float v144 = v129[(v141 + (v135 * 2))][(v139 + (v133 * 2))][(v134 + v140)];
                          float v145 = v142 * v143;
                          float v146 = v144 + v145;
                          v129[(v141 + (v135 * 2))][(v139 + (v133 * 2))][(v134 + v140)] = v146;
                          if (((v131 + v137) - 2) == 0 && ((v132 + v138) - 2) == 0 && ((v130 + v136) - 2) == 0) {
                            float v147 = v129[(v141 + (v135 * 2))][(v139 + (v133 * 2))][(v134 + v140)];
                            v127[v141][v139][v140].write(v147);
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

void node11(
  float v148[1][3][32][32],
  float v149[3][34][34]
) {
  #pragma HLS array_partition variable=v148 cyclic dim=3 factor=2

  #pragma HLS array_partition variable=v149 cyclic dim=2 factor=2

  loop84: for (int v150 = 0; v150 < 16; v150++) {
    loop85: for (int v151 = 0; v151 < 3; v151++) {
      loop86: for (int v152 = 0; v152 < 32; v152++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop87: for (int v153 = 0; v153 < 2; v153++) {
          loop88: for (int v154 = 0; v154 < 1; v154++) {
            loop89: for (int v155 = 0; v155 < 1; v155++) {
              float v156 = v148[0][(v151 + v154)][(v153 + (v150 * 2))][(v152 + v155)];
              v149[(v151 + v154)][((v153 + (v150 * 2)) + 1)][((v152 + v155) + 1)] = v156;
            }
          }
        }
      }
    }
  }
  return ;
}

void node12(
  float v157[3][34][34],
  float v158
) {
  #pragma HLS array_partition variable=v157 cyclic dim=2 factor=2

  loop90: for (int v159 = 0; v159 < 3; v159++) {
    loop91: for (int v160 = 0; v160 < 34; v160++) {
      loop92: for (int v161 = 0; v161 < 17; v161++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop93: for (int v162 = 0; v162 < 1; v162++) {
          loop94: for (int v163 = 0; v163 < 1; v163++) {
            loop95: for (int v164 = 0; v164 < 2; v164++) {
              v157[(v159 + v162)][(v164 + (v161 * 2))][(v160 + v163)] = v158;
            }
          }
        }
      }
    }
  }
  return ;
}

void forward(
  float v165[1][3][32][32],
  float v166[32][3][3][3],
  float v167[32][32][3][3],
  float v168[32][32][3][3],
  float v169[1][32][32][32]
) {
	// #pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v165 cyclic dim=3 factor=2

  #pragma HLS array_partition variable=v166 cyclic dim=1 factor=2

  #pragma HLS array_partition variable=v167 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v167 cyclic dim=2 factor=2

  #pragma HLS array_partition variable=v168 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v168 cyclic dim=2 factor=2

  #pragma HLS array_partition variable=v169 cyclic dim=2 factor=2
  #pragma HLS array_partition variable=v169 cyclic dim=3 factor=2
  #pragma HLS array_partition variable=v169 cyclic dim=4 factor=2

  hls::stream<float> v170[2][2][2];
	#pragma HLS STREAM variable=v170 depth=4096
  hls::stream<float> v171[2][2][2];
	#pragma HLS STREAM variable=v171 depth=4096
  float v172[32][34][34];
  #pragma HLS array_partition variable=v172 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v172 cyclic dim=2 factor=2

  hls::stream<float> v173[2][2][1];
	#pragma HLS STREAM variable=v173 depth=8192
  hls::stream<float> v174[2][2][1];
	#pragma HLS STREAM variable=v174 depth=8192
  float v175[32][34][34];
  #pragma HLS array_partition variable=v175 cyclic dim=1 factor=2
  #pragma HLS array_partition variable=v175 cyclic dim=2 factor=2

  hls::stream<float> v176[2][2][1];
	#pragma HLS STREAM variable=v176 depth=8192
  hls::stream<float> v177[2][2][1];
	#pragma HLS STREAM variable=v177 depth=8192
  float v178[3][34][34];
  #pragma HLS array_partition variable=v178 cyclic dim=2 factor=2

  node12(v178, 0.000000);
  node11(v165, v178);
  node10(v166, v178, v177, 0.000000);
  node9(v177, v176, 0.000000);
  node8(v175, 0.000000);
  node7(v176, v175);
  node6(v167, v175, v174, 0.000000);
  node5(v174, v173, 0.000000);
  node4(v172, 0.000000);
  node3(v173, v172);
  node2(v168, v172, v171, 0.000000);
  node1(v171, v170, 0.000000);
  node0(v170, v169);
  return ;
}

