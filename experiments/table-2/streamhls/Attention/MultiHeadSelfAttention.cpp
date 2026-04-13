
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
  hls::stream<float> v0[1][32],
  float v1[1][16][512]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=3 factor=32

  loop0: for (int v2 = 0; v2 < 16; v2++) {
    loop1: for (int v3 = 0; v3 < 16; v3++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop2: for (int v4 = 0; v4 < 1; v4++) {
        loop3: for (int v5 = 0; v5 < 32; v5++) {
          float v6 = v0[v4][v5].read();
          v1[0][(v2 + v4)][(v5 + (v3 * 32))] = v6;
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v7[1][32],
  float v8[512],
  hls::stream<float> v9[1][32]
) {
  #pragma HLS array_partition variable=v8 cyclic dim=1 factor=32

  loop4: for (int v10 = 0; v10 < 16; v10++) {
    loop5: for (int v11 = 0; v11 < 16; v11++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop6: for (int v12 = 0; v12 < 1; v12++) {
        loop7: for (int v13 = 0; v13 < 32; v13++) {
          float v14 = v7[v12][v13].read();
          float v15 = v8[(v13 + (v11 * 32))];
          float v16 = v14 + v15;
          v9[v12][v13].write(v16);
        }
      }
    }
  }
  return ;
}

void node2(
  hls::stream<float> v17[1][1],
  float v18[512][512],
  hls::stream<float> v19[1][32],
  float v20
) {
  #pragma HLS array_partition variable=v18 cyclic dim=2 factor=32

  float v21[16][512];
  #pragma HLS array_partition variable=v21 cyclic dim=2 factor=32

  float v22[512][512];
  #pragma HLS array_partition variable=v22 cyclic dim=2 factor=32

  float v23[16][512];
  loop8: for (int v24 = 0; v24 < 16; v24++) {
    loop9: for (int v25 = 0; v25 < 512; v25++) {
      loop10: for (int v26 = 0; v26 < 16; v26++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop11: for (int v27 = 0; v27 < 1; v27++) {
          loop12: for (int v28 = 0; v28 < 1; v28++) {
            loop13: for (int v29 = 0; v29 < 32; v29++) {
              if ((v29 + (v26 * 32)) == 0) {
                float v30 = v17[v27][v28].read();
                v23[(v24 + v27)][(v25 + v28)] = v30;
              }
              float v31 = v23[(v24 + v27)][(v25 + v28)];
              if ((v24 + v27) == 0) {
                float v32 = v18[(v25 + v28)][(v29 + (v26 * 32))];
                v22[(v25 + v28)][(v29 + (v26 * 32))] = v32;
              }
              float v33 = v22[(v25 + v28)][(v29 + (v26 * 32))];
              if ((v25 + v28) == 0) {
                v21[(v24 + v27)][(v29 + (v26 * 32))] = v20;
              }
              float v34 = v21[(v24 + v27)][(v29 + (v26 * 32))];
              float v35 = v31 * v33;
              float v36 = v34 + v35;
              v21[(v24 + v27)][(v29 + (v26 * 32))] = v36;
              if (((v25 + v28) - 511) == 0) {
                float v37 = v21[(v24 + v27)][(v29 + (v26 * 32))];
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
  float v38[512][512],
  float v39[512][512]
) {
  #pragma HLS array_partition variable=v38 cyclic dim=1 factor=32

  #pragma HLS array_partition variable=v39 cyclic dim=2 factor=32

  loop14: for (int v40 = 0; v40 < 16; v40++) {
    loop15: for (int v41 = 0; v41 < 512; v41++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop16: for (int v42 = 0; v42 < 32; v42++) {
        loop17: for (int v43 = 0; v43 < 1; v43++) {
          float v44 = v38[(v42 + (v40 * 32))][(v41 + v43)];
          v39[(v41 + v43)][(v42 + (v40 * 32))] = v44;
        }
      }
    }
  }
  return ;
}

void node4(
  float v45[16][8][64],
  hls::stream<float> v46[1][1]
) {
  loop18: for (int v47 = 0; v47 < 16; v47++) {
    loop19: for (int v48 = 0; v48 < 512; v48++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop20: for (int v49 = 0; v49 < 1; v49++) {
        loop21: for (int v50 = 0; v50 < 1; v50++) {
          float v51 = v45[(v47 + v49)][(v48 / 64)][((v48 + v50) % 64)];
          v46[v49][v50].write(v51);
        }
      }
    }
  }
  return ;
}

void node5(
  float v52[8][16][64],
  float v53[16][8][64]
) {
  loop22: for (int v54 = 0; v54 < 16; v54++) {
    loop23: for (int v55 = 0; v55 < 8; v55++) {
      loop24: for (int v56 = 0; v56 < 64; v56++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop25: for (int v57 = 0; v57 < 1; v57++) {
          loop26: for (int v58 = 0; v58 < 1; v58++) {
            loop27: for (int v59 = 0; v59 < 1; v59++) {
              float v60 = v52[(v55 + v58)][(v54 + v57)][(v56 + v59)];
              v53[(v54 + v57)][(v55 + v58)][(v56 + v59)] = v60;
            }
          }
        }
      }
    }
  }
  return ;
}

void node6(
  hls::stream<float> v61[1][1][1],
  hls::stream<float> v62[1][1][1],
  float v63[8][16][64],
  float v64
) {
  float v65[8][16][64];
  float v66[8][16][64];
  float v67[8][16][16];
  loop28: for (int v68 = 0; v68 < 16; v68++) {
    loop29: for (int v69 = 0; v69 < 8; v69++) {
      loop30: for (int v70 = 0; v70 < 16; v70++) {
        loop31: for (int v71 = 0; v71 < 64; v71++) {
          #pragma HLS pipeline II=1
          #pragma HLS loop_flatten
          loop32: for (int v72 = 0; v72 < 1; v72++) {
            loop33: for (int v73 = 0; v73 < 1; v73++) {
              loop34: for (int v74 = 0; v74 < 1; v74++) {
                loop35: for (int v75 = 0; v75 < 1; v75++) {
                  if ((v71 + v75) == 0) {
                    float v76 = v62[v73][v72][v74].read();
                    v67[(v69 + v73)][(v68 + v72)][(v70 + v74)] = v76;
                  }
                  float v77 = v67[(v69 + v73)][(v68 + v72)][(v70 + v74)];
                  if ((v68 + v72) == 0) {
                    float v78 = v61[v73][v74][v75].read();
                    v66[(v69 + v73)][(v70 + v74)][(v71 + v75)] = v78;
                  }
                  float v79 = v66[(v69 + v73)][(v70 + v74)][(v71 + v75)];
                  if ((v70 + v74) == 0) {
                    v65[(v69 + v73)][(v68 + v72)][(v71 + v75)] = v64;
                  }
                  float v80 = v65[(v69 + v73)][(v68 + v72)][(v71 + v75)];
                  float v81 = v77 * v79;
                  float v82 = v80 + v81;
                  v65[(v69 + v73)][(v68 + v72)][(v71 + v75)] = v82;
                  if (((v70 + v74) - 15) == 0) {
                    float v83 = v65[(v69 + v73)][(v68 + v72)][(v71 + v75)];
                    v63[(v69 + v73)][(v68 + v72)][(v71 + v75)] = v83;
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
  float v84[16][512],
  hls::stream<float> v85[1][1][1]
) {
  loop36: for (int v86 = 0; v86 < 8; v86++) {
    loop37: for (int v87 = 0; v87 < 16; v87++) {
      loop38: for (int v88 = 0; v88 < 64; v88++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop39: for (int v89 = 0; v89 < 1; v89++) {
          loop40: for (int v90 = 0; v90 < 1; v90++) {
            loop41: for (int v91 = 0; v91 < 1; v91++) {
              float v92 = v84[(v87 + v90)][((((v86 * 64) + (v89 * 64)) + v88) + v91)];
              v85[v89][v90][v91].write(v92);
            }
          }
        }
      }
    }
  }
  return ;
}

void node8(
  hls::stream<float> v93[1][1][1],
  hls::stream<float> v94[1][1],
  hls::stream<float> v95[1][1][1]
) {
  float v96[8][16];
  loop42: for (int v97 = 0; v97 < 16; v97++) {
    loop43: for (int v98 = 0; v98 < 8; v98++) {
      loop44: for (int v99 = 0; v99 < 16; v99++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop45: for (int v100 = 0; v100 < 1; v100++) {
          loop46: for (int v101 = 0; v101 < 1; v101++) {
            loop47: for (int v102 = 0; v102 < 1; v102++) {
              float v103 = v93[v101][v100][v102].read();
              if ((v99 + v102) == 0) {
                float v104 = v94[v101][v100].read();
                v96[(v98 + v101)][(v97 + v100)] = v104;
              }
              float v105 = v96[(v98 + v101)][(v97 + v100)];
              float v106 = v103 / v105;
              v95[v101][v100][v102].write(v106);
            }
          }
        }
      }
    }
  }
  return ;
}

void node9(
  hls::stream<float> v107[1][1][1],
  hls::stream<float> v108[1][1],
  float v109
) {
  float v110[8][16];
  loop48: for (int v111 = 0; v111 < 16; v111++) {
    loop49: for (int v112 = 0; v112 < 8; v112++) {
      loop50: for (int v113 = 0; v113 < 16; v113++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop51: for (int v114 = 0; v114 < 1; v114++) {
          loop52: for (int v115 = 0; v115 < 1; v115++) {
            loop53: for (int v116 = 0; v116 < 1; v116++) {
              float v117 = v107[v115][v114][v116].read();
              if ((v113 + v116) == 0) {
                v110[(v112 + v115)][(v111 + v114)] = v109;
              }
              float v118 = v110[(v112 + v115)][(v111 + v114)];
              float v119 = v117 + v118;
              v110[(v112 + v115)][(v111 + v114)] = v119;
              if (((v113 + v116) - 15) == 0) {
                float v120 = v110[(v112 + v115)][(v111 + v114)];
                v108[v115][v114].write(v120);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node10(
  hls::stream<float> v121[1][1][1],
  hls::stream<float> v122[1][1],
  hls::stream<float> v123[1][1][1],
  hls::stream<float> v124[1][1][1]
) {
  float v125[8][16];
  loop54: for (int v126 = 0; v126 < 16; v126++) {
    loop55: for (int v127 = 0; v127 < 8; v127++) {
      loop56: for (int v128 = 0; v128 < 16; v128++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop57: for (int v129 = 0; v129 < 1; v129++) {
          loop58: for (int v130 = 0; v130 < 1; v130++) {
            loop59: for (int v131 = 0; v131 < 1; v131++) {
              float v132 = v121[v130][v129][v131].read();
              if ((v128 + v131) == 0) {
                float v133 = v122[v130][v129].read();
                v125[(v127 + v130)][(v126 + v129)] = v133;
              }
              float v134 = v125[(v127 + v130)][(v126 + v129)];
              float v135 = v132 - v134;
              float v136 = exp(v135);
              v123[v130][v129][v131].write(v136);
              v124[v130][v129][v131].write(v136);
            }
          }
        }
      }
    }
  }
  return ;
}

void node11(
  hls::stream<float> v137[1][1][1],
  hls::stream<float> v138[1][1],
  float v139
) {
  float v140[8][16];
  loop60: for (int v141 = 0; v141 < 16; v141++) {
    loop61: for (int v142 = 0; v142 < 8; v142++) {
      loop62: for (int v143 = 0; v143 < 16; v143++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop63: for (int v144 = 0; v144 < 1; v144++) {
          loop64: for (int v145 = 0; v145 < 1; v145++) {
            loop65: for (int v146 = 0; v146 < 1; v146++) {
              float v147 = v137[v145][v144][v146].read();
              if ((v143 + v146) == 0) {
                v140[(v142 + v145)][(v141 + v144)] = v139;
              }
              float v148 = v140[(v142 + v145)][(v141 + v144)];
              float v149 = fmax(v147, v148);
              v140[(v142 + v145)][(v141 + v144)] = v149;
              if (((v143 + v146) - 15) == 0) {
                float v150 = v140[(v142 + v145)][(v141 + v144)];
                v138[v145][v144].write(v150);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node12(
  hls::stream<float> v151[1][1][1],
  hls::stream<float> v152[1][1][1],
  hls::stream<float> v153[1][1][1],
  float v154
) {
  loop66: for (int v155 = 0; v155 < 16; v155++) {
    loop67: for (int v156 = 0; v156 < 8; v156++) {
      loop68: for (int v157 = 0; v157 < 16; v157++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop69: for (int v158 = 0; v158 < 1; v158++) {
          loop70: for (int v159 = 0; v159 < 1; v159++) {
            loop71: for (int v160 = 0; v160 < 1; v160++) {
              float v161 = v151[v159][v158][v160].read();
              float v162 = v161 / v154;
              v152[v159][v158][v160].write(v162);
              v153[v159][v158][v160].write(v162);
            }
          }
        }
      }
    }
  }
  return ;
}

void node13(
  hls::stream<float> v163[1][4][1],
  hls::stream<float> v164[1][1][4],
  hls::stream<float> v165[1][1][1],
  float v166
) {
  float v167[8][16][16];
  float v168[8][64][16];
  #pragma HLS array_partition variable=v168 cyclic dim=2 factor=4

  float v169[8][16][64];
  #pragma HLS array_partition variable=v169 cyclic dim=3 factor=4

  loop72: for (int v170 = 0; v170 < 16; v170++) {
    loop73: for (int v171 = 0; v171 < 8; v171++) {
      loop74: for (int v172 = 0; v172 < 16; v172++) {
        loop75: for (int v173 = 0; v173 < 16; v173++) {
          #pragma HLS pipeline II=1
          #pragma HLS loop_flatten
          loop76: for (int v174 = 0; v174 < 1; v174++) {
            loop77: for (int v175 = 0; v175 < 1; v175++) {
              loop78: for (int v176 = 0; v176 < 4; v176++) {
                loop79: for (int v177 = 0; v177 < 1; v177++) {
                  if ((v173 + v177) == 0) {
                    float v178 = v164[v175][v174][v176].read();
                    v169[(v171 + v175)][(v170 + v174)][(v176 + (v172 * 4))] = v178;
                  }
                  float v179 = v169[(v171 + v175)][(v170 + v174)][(v176 + (v172 * 4))];
                  if ((v170 + v174) == 0) {
                    float v180 = v163[v175][v176][v177].read();
                    v168[(v171 + v175)][(v176 + (v172 * 4))][(v173 + v177)] = v180;
                  }
                  float v181 = v168[(v171 + v175)][(v176 + (v172 * 4))][(v173 + v177)];
                  if ((v176 + (v172 * 4)) == 0) {
                    v167[(v171 + v175)][(v170 + v174)][(v173 + v177)] = v166;
                  }
                  float v182 = v167[(v171 + v175)][(v170 + v174)][(v173 + v177)];
                  float v183 = v179 * v181;
                  float v184 = v182 + v183;
                  v167[(v171 + v175)][(v170 + v174)][(v173 + v177)] = v184;
                  if (((v176 + (v172 * 4)) - 63) == 0) {
                    float v185 = v167[(v171 + v175)][(v170 + v174)][(v173 + v177)];
                    v165[v175][v174][v177].write(v185);
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

void node14(
  float v186[16][512],
  hls::stream<float> v187[1][4][1]
) {
  loop80: for (int v188 = 0; v188 < 8; v188++) {
    loop81: for (int v189 = 0; v189 < 16; v189++) {
      loop82: for (int v190 = 0; v190 < 16; v190++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop83: for (int v191 = 0; v191 < 1; v191++) {
          loop84: for (int v192 = 0; v192 < 4; v192++) {
            loop85: for (int v193 = 0; v193 < 1; v193++) {
              float v194 = v186[(v190 + v193)][((((v188 * 64) + (v191 * 64)) + v192) + (v189 * 4))];
              v187[v191][v192][v193].write(v194);
            }
          }
        }
      }
    }
  }
  return ;
}

void node15(
  float v195[16][512],
  hls::stream<float> v196[1][1][4]
) {
  loop86: for (int v197 = 0; v197 < 16; v197++) {
    loop87: for (int v198 = 0; v198 < 8; v198++) {
      loop88: for (int v199 = 0; v199 < 16; v199++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop89: for (int v200 = 0; v200 < 1; v200++) {
          loop90: for (int v201 = 0; v201 < 1; v201++) {
            loop91: for (int v202 = 0; v202 < 4; v202++) {
              float v203 = v195[(v197 + v200)][((((v198 * 64) + (v201 * 64)) + v202) + (v199 * 4))];
              v196[v201][v200][v202].write(v203);
            }
          }
        }
      }
    }
  }
  return ;
}

void node16(
  hls::stream<float> v204[1][1],
  float v205[512],
  float v206[16][512]
) {
  loop92: for (int v207 = 0; v207 < 512; v207++) {
    loop93: for (int v208 = 0; v208 < 16; v208++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop94: for (int v209 = 0; v209 < 1; v209++) {
        loop95: for (int v210 = 0; v210 < 1; v210++) {
          float v211 = v204[v210][v209].read();
          float v212 = v205[(v207 + v209)];
          float v213 = v211 + v212;
          v206[(v208 + v210)][(v207 + v209)] = v213;
        }
      }
    }
  }
  return ;
}

void node17(
  hls::stream<float> v214[32][1],
  hls::stream<float> v215[1][32],
  hls::stream<float> v216[1][1],
  float v217
) {
  float v218[16][512];
  float v219[512][512];
  #pragma HLS array_partition variable=v219 cyclic dim=1 factor=32

  float v220[16][512];
  #pragma HLS array_partition variable=v220 cyclic dim=2 factor=32

  loop96: for (int v221 = 0; v221 < 16; v221++) {
    loop97: for (int v222 = 0; v222 < 512; v222++) {
      loop98: for (int v223 = 0; v223 < 16; v223++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop99: for (int v224 = 0; v224 < 32; v224++) {
          loop100: for (int v225 = 0; v225 < 1; v225++) {
            loop101: for (int v226 = 0; v226 < 1; v226++) {
              if ((v222 + v225) == 0) {
                float v227 = v215[v226][v224].read();
                v220[(v223 + v226)][(v224 + (v221 * 32))] = v227;
              }
              float v228 = v220[(v223 + v226)][(v224 + (v221 * 32))];
              if ((v223 + v226) == 0) {
                float v229 = v214[v224][v225].read();
                v219[(v224 + (v221 * 32))][(v222 + v225)] = v229;
              }
              float v230 = v219[(v224 + (v221 * 32))][(v222 + v225)];
              if ((v224 + (v221 * 32)) == 0) {
                v218[(v223 + v226)][(v222 + v225)] = v217;
              }
              float v231 = v218[(v223 + v226)][(v222 + v225)];
              float v232 = v228 * v230;
              float v233 = v231 + v232;
              v218[(v223 + v226)][(v222 + v225)] = v233;
              if (((v224 + (v221 * 32)) - 511) == 0) {
                float v234 = v218[(v223 + v226)][(v222 + v225)];
                v216[v226][v225].write(v234);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node18(
  float v235[512][512],
  hls::stream<float> v236[32][1]
) {
  #pragma HLS array_partition variable=v235 cyclic dim=2 factor=32

  loop102: for (int v237 = 0; v237 < 16; v237++) {
    loop103: for (int v238 = 0; v238 < 512; v238++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop104: for (int v239 = 0; v239 < 32; v239++) {
        loop105: for (int v240 = 0; v240 < 1; v240++) {
          float v241 = v235[(v238 + v240)][(v239 + (v237 * 32))];
          v236[v239][v240].write(v241);
        }
      }
    }
  }
  return ;
}

void node19(
  hls::stream<float> v242[1][1],
  float v243[512],
  float v244[16][512]
) {
  loop106: for (int v245 = 0; v245 < 16; v245++) {
    loop107: for (int v246 = 0; v246 < 512; v246++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop108: for (int v247 = 0; v247 < 1; v247++) {
        loop109: for (int v248 = 0; v248 < 1; v248++) {
          float v249 = v242[v247][v248].read();
          float v250 = v243[(v246 + v248)];
          float v251 = v249 + v250;
          v244[(v245 + v247)][(v246 + v248)] = v251;
        }
      }
    }
  }
  return ;
}

void node20(
  hls::stream<float> v252[32][1],
  hls::stream<float> v253[1][32],
  hls::stream<float> v254[1][1],
  float v255
) {
  float v256[16][512];
  float v257[512][512];
  #pragma HLS array_partition variable=v257 cyclic dim=1 factor=32

  float v258[16][512];
  #pragma HLS array_partition variable=v258 cyclic dim=2 factor=32

  loop110: for (int v259 = 0; v259 < 16; v259++) {
    loop111: for (int v260 = 0; v260 < 16; v260++) {
      loop112: for (int v261 = 0; v261 < 512; v261++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop113: for (int v262 = 0; v262 < 32; v262++) {
          loop114: for (int v263 = 0; v263 < 1; v263++) {
            loop115: for (int v264 = 0; v264 < 1; v264++) {
              if ((v261 + v264) == 0) {
                float v265 = v253[v263][v262].read();
                v258[(v260 + v263)][(v262 + (v259 * 32))] = v265;
              }
              float v266 = v258[(v260 + v263)][(v262 + (v259 * 32))];
              if ((v260 + v263) == 0) {
                float v267 = v252[v262][v264].read();
                v257[(v262 + (v259 * 32))][(v261 + v264)] = v267;
              }
              float v268 = v257[(v262 + (v259 * 32))][(v261 + v264)];
              if ((v262 + (v259 * 32)) == 0) {
                v256[(v260 + v263)][(v261 + v264)] = v255;
              }
              float v269 = v256[(v260 + v263)][(v261 + v264)];
              float v270 = v266 * v268;
              float v271 = v269 + v270;
              v256[(v260 + v263)][(v261 + v264)] = v271;
              if (((v262 + (v259 * 32)) - 511) == 0) {
                float v272 = v256[(v260 + v263)][(v261 + v264)];
                v254[v263][v264].write(v272);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node21(
  float v273[512][512],
  hls::stream<float> v274[32][1]
) {
  #pragma HLS array_partition variable=v273 cyclic dim=2 factor=32

  loop116: for (int v275 = 0; v275 < 16; v275++) {
    loop117: for (int v276 = 0; v276 < 512; v276++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop118: for (int v277 = 0; v277 < 32; v277++) {
        loop119: for (int v278 = 0; v278 < 1; v278++) {
          float v279 = v273[(v276 + v278)][(v277 + (v275 * 32))];
          v274[v277][v278].write(v279);
        }
      }
    }
  }
  return ;
}

void node22(
  hls::stream<float> v280[1][1],
  float v281[512],
  float v282[16][512]
) {
  loop120: for (int v283 = 0; v283 < 512; v283++) {
    loop121: for (int v284 = 0; v284 < 16; v284++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop122: for (int v285 = 0; v285 < 1; v285++) {
        loop123: for (int v286 = 0; v286 < 1; v286++) {
          float v287 = v280[v286][v285].read();
          float v288 = v281[(v283 + v285)];
          float v289 = v287 + v288;
          v282[(v284 + v286)][(v283 + v285)] = v289;
        }
      }
    }
  }
  return ;
}

void node23(
  hls::stream<float> v290[32][1],
  hls::stream<float> v291[1][32],
  hls::stream<float> v292[1][1],
  float v293
) {
  float v294[16][512];
  float v295[512][512];
  #pragma HLS array_partition variable=v295 cyclic dim=1 factor=32

  float v296[16][512];
  #pragma HLS array_partition variable=v296 cyclic dim=2 factor=32

  loop124: for (int v297 = 0; v297 < 16; v297++) {
    loop125: for (int v298 = 0; v298 < 512; v298++) {
      loop126: for (int v299 = 0; v299 < 16; v299++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop127: for (int v300 = 0; v300 < 32; v300++) {
          loop128: for (int v301 = 0; v301 < 1; v301++) {
            loop129: for (int v302 = 0; v302 < 1; v302++) {
              if ((v298 + v301) == 0) {
                float v303 = v291[v302][v300].read();
                v296[(v299 + v302)][(v300 + (v297 * 32))] = v303;
              }
              float v304 = v296[(v299 + v302)][(v300 + (v297 * 32))];
              if ((v299 + v302) == 0) {
                float v305 = v290[v300][v301].read();
                v295[(v300 + (v297 * 32))][(v298 + v301)] = v305;
              }
              float v306 = v295[(v300 + (v297 * 32))][(v298 + v301)];
              if ((v300 + (v297 * 32)) == 0) {
                v294[(v299 + v302)][(v298 + v301)] = v293;
              }
              float v307 = v294[(v299 + v302)][(v298 + v301)];
              float v308 = v304 * v306;
              float v309 = v307 + v308;
              v294[(v299 + v302)][(v298 + v301)] = v309;
              if (((v300 + (v297 * 32)) - 511) == 0) {
                float v310 = v294[(v299 + v302)][(v298 + v301)];
                v292[v302][v301].write(v310);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node24(
  float v311[512][512],
  hls::stream<float> v312[32][1]
) {
  #pragma HLS array_partition variable=v311 cyclic dim=2 factor=32

  loop130: for (int v313 = 0; v313 < 16; v313++) {
    loop131: for (int v314 = 0; v314 < 512; v314++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop132: for (int v315 = 0; v315 < 32; v315++) {
        loop133: for (int v316 = 0; v316 < 1; v316++) {
          float v317 = v311[(v314 + v316)][(v315 + (v313 * 32))];
          v312[v315][v316].write(v317);
        }
      }
    }
  }
  return ;
}

void node25(
  float v318[1][16][512],
  hls::stream<float> v319[1][32],
  hls::stream<float> v320[1][32],
  hls::stream<float> v321[1][32]
) {
  #pragma HLS array_partition variable=v318 cyclic dim=3 factor=32

  loop134: for (int v322 = 0; v322 < 16; v322++) {
    loop135: for (int v323 = 0; v323 < 16; v323++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop136: for (int v324 = 0; v324 < 32; v324++) {
        loop137: for (int v325 = 0; v325 < 1; v325++) {
          float v326 = v318[0][(v323 + v325)][(v324 + (v322 * 32))];
          v319[v325][v324].write(v326);
          v320[v325][v324].write(v326);
          v321[v325][v324].write(v326);
        }
      }
    }
  }
  return ;
}

void forward(
  float v327[1][16][512],
  float v328[512],
  float v329[512][512],
  float v330[512],
  float v331[512][512],
  float v332[512],
  float v333[512][512],
  float v334[512],
  float v335[512][512],
  float v336[1][16][512]
) {
	#pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v327 cyclic dim=3 factor=32

  #pragma HLS array_partition variable=v329 cyclic dim=2 factor=32

  #pragma HLS array_partition variable=v331 cyclic dim=2 factor=32

  #pragma HLS array_partition variable=v333 cyclic dim=2 factor=32

  #pragma HLS array_partition variable=v334 cyclic dim=1 factor=32

  #pragma HLS array_partition variable=v335 cyclic dim=1 factor=32

  #pragma HLS array_partition variable=v336 cyclic dim=3 factor=32

  hls::stream<float> v337[1][32];
	#pragma HLS STREAM variable=v337 depth=256
  hls::stream<float> v338[1][32];
	#pragma HLS STREAM variable=v338 depth=256
  float v339[512][512];
  #pragma HLS array_partition variable=v339 cyclic dim=2 factor=32

  hls::stream<float> v340[1][1];
	#pragma HLS STREAM variable=v340 depth=8192
  float v341[16][8][64];
  float v342[8][16][64];
  hls::stream<float> v343[1][1][1];
	#pragma HLS STREAM variable=v343 depth=8192
  hls::stream<float> v344[1][1][1];
	#pragma HLS STREAM variable=v344 depth=2048
  hls::stream<float> v345[1][1];
	#pragma HLS STREAM variable=v345 depth=128
  hls::stream<float> v346[1][1][1];
	#pragma HLS STREAM variable=v346 depth=2048
  hls::stream<float> v347[1][1][1];
	#pragma HLS STREAM variable=v347 depth=2048
  hls::stream<float> v348[1][1];
	#pragma HLS STREAM variable=v348 depth=128
  hls::stream<float> v349[1][1][1];
	#pragma HLS STREAM variable=v349 depth=2048
  hls::stream<float> v350[1][1][1];
	#pragma HLS STREAM variable=v350 depth=2048
  hls::stream<float> v351[1][1][1];
	#pragma HLS STREAM variable=v351 depth=2048
  hls::stream<float> v352[1][4][1];
	#pragma HLS STREAM variable=v352 depth=2048
  hls::stream<float> v353[1][1][4];
	#pragma HLS STREAM variable=v353 depth=2048
  float v354[16][512];
  hls::stream<float> v355[1][1];
	#pragma HLS STREAM variable=v355 depth=8192
  hls::stream<float> v356[32][1];
	#pragma HLS STREAM variable=v356 depth=8192
  float v357[16][512];
  hls::stream<float> v358[1][1];
	#pragma HLS STREAM variable=v358 depth=8192
  hls::stream<float> v359[32][1];
	#pragma HLS STREAM variable=v359 depth=8192
  float v360[16][512];
  hls::stream<float> v361[1][1];
	#pragma HLS STREAM variable=v361 depth=8192
  hls::stream<float> v362[32][1];
	#pragma HLS STREAM variable=v362 depth=8192
  hls::stream<float> v363[1][32];
	#pragma HLS STREAM variable=v363 depth=256
  hls::stream<float> v364[1][32];
	#pragma HLS STREAM variable=v364 depth=256
  hls::stream<float> v365[1][32];
	#pragma HLS STREAM variable=v365 depth=256
  node25(v327, v365, v364, v363);
  node24(v329, v362);
  node23(v362, v363, v361, 0.000000);
  node22(v361, v328, v360);
  node21(v331, v359);
  node20(v359, v364, v358, 0.000000);
  node19(v358, v330, v357);
  node18(v333, v356);
  node17(v356, v365, v355, 0.000000);
  node16(v355, v332, v354);
  node15(v360, v353);
  node14(v357, v352);
  node13(v352, v353, v351, 0.000000);
  node12(v351, v350, v349, 8.000000);
  node11(v350, v348, -INFINITY);
  node10(v349, v348, v347, v346);
  node9(v347, v345, 0.000000);
  node8(v346, v345, v344);
  node7(v354, v343);
  node6(v343, v344, v342, 0.000000);
  node5(v342, v341);
  node4(v341, v340);
  node3(v335, v339);
  node2(v340, v339, v338, 0.000000);
  node1(v338, v334, v337);
  node0(v337, v336);
  return ;
}

