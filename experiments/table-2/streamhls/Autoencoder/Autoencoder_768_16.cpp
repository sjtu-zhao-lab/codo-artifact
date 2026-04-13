
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
  hls::stream<float> v0[1][16],
  float v1[128][512]
) {
  #pragma HLS array_partition variable=v1 cyclic dim=2 factor=16

  loop0: for (int v2 = 0; v2 < 128; v2++) {
    loop1: for (int v3 = 0; v3 < 32; v3++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop2: for (int v4 = 0; v4 < 1; v4++) {
        loop3: for (int v5 = 0; v5 < 16; v5++) {
          float v6 = v0[v4][v5].read();
          v1[(v2 + v4)][(v5 + (v3 * 16))] = v6;
        }
      }
    }
  }
  return ;
}

void node1(
  hls::stream<float> v7[1][16],
  float v8[512],
  hls::stream<float> v9[1][16],
  float v10
) {
  #pragma HLS array_partition variable=v8 cyclic dim=1 factor=16

  loop4: for (int v11 = 0; v11 < 128; v11++) {
    loop5: for (int v12 = 0; v12 < 32; v12++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop6: for (int v13 = 0; v13 < 1; v13++) {
        loop7: for (int v14 = 0; v14 < 16; v14++) {
          float v15 = v7[v13][v14].read();
          float v16 = v8[(v14 + (v12 * 16))];
          float v17 = v15 + v16;
          float v18 = -(v17);
          float v19 = exp(v18);
          float v20 = v19 + v10;
          float v21 = v10 / v20;
          v9[v13][v14].write(v21);
        }
      }
    }
  }
  return ;
}

void node2(
  hls::stream<float> v22[4][16],
  hls::stream<float> v23[1][4],
  hls::stream<float> v24[1][16],
  float v25
) {
  float v26[128][512];
  #pragma HLS array_partition variable=v26 cyclic dim=2 factor=16

  float v27[256][512];
  #pragma HLS array_partition variable=v27 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v27 cyclic dim=2 factor=16

  float v28[128][256];
  #pragma HLS array_partition variable=v28 cyclic dim=2 factor=4

  loop8: for (int v29 = 0; v29 < 128; v29++) {
    loop9: for (int v30 = 0; v30 < 64; v30++) {
      loop10: for (int v31 = 0; v31 < 32; v31++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop11: for (int v32 = 0; v32 < 1; v32++) {
          loop12: for (int v33 = 0; v33 < 4; v33++) {
            loop13: for (int v34 = 0; v34 < 16; v34++) {
              if ((v34 + (v31 * 16)) == 0) {
                float v35 = v23[v32][v33].read();
                v28[(v29 + v32)][(v33 + (v30 * 4))] = v35;
              }
              float v36 = v28[(v29 + v32)][(v33 + (v30 * 4))];
              if ((v29 + v32) == 0) {
                float v37 = v22[v33][v34].read();
                v27[(v33 + (v30 * 4))][(v34 + (v31 * 16))] = v37;
              }
              float v38 = v27[(v33 + (v30 * 4))][(v34 + (v31 * 16))];
              if ((v33 + (v30 * 4)) == 0) {
                v26[(v29 + v32)][(v34 + (v31 * 16))] = v25;
              }
              float v39 = v26[(v29 + v32)][(v34 + (v31 * 16))];
              float v40 = v36 * v38;
              float v41 = v39 + v40;
              v26[(v29 + v32)][(v34 + (v31 * 16))] = v41;
              if (((v33 + (v30 * 4)) - 255) == 0) {
                float v42 = v26[(v29 + v32)][(v34 + (v31 * 16))];
                v24[v32][v34].write(v42);
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
  float v43[512][256],
  hls::stream<float> v44[4][16]
) {
  #pragma HLS array_partition variable=v43 cyclic dim=1 factor=16
  #pragma HLS array_partition variable=v43 cyclic dim=2 factor=4

  loop14: for (int v45 = 0; v45 < 64; v45++) {
    loop15: for (int v46 = 0; v46 < 32; v46++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop16: for (int v47 = 0; v47 < 4; v47++) {
        loop17: for (int v48 = 0; v48 < 16; v48++) {
          float v49 = v43[(v48 + (v46 * 16))][(v47 + (v45 * 4))];
          v44[v47][v48].write(v49);
        }
      }
    }
  }
  return ;
}

void node4(
  hls::stream<float> v50[1][4],
  float v51[256],
  hls::stream<float> v52[1][4],
  float v53
) {
  #pragma HLS array_partition variable=v51 cyclic dim=1 factor=4

  loop18: for (int v54 = 0; v54 < 128; v54++) {
    loop19: for (int v55 = 0; v55 < 64; v55++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop20: for (int v56 = 0; v56 < 1; v56++) {
        loop21: for (int v57 = 0; v57 < 4; v57++) {
          float v58 = v50[v56][v57].read();
          float v59 = v51[(v57 + (v55 * 4))];
          float v60 = v58 + v59;
          bool v61 = v60 > v53;
          float v62 = v61 ? (float)v60 : (float)v53;
          v52[v56][v57].write(v62);
        }
      }
    }
  }
  return ;
}

void node5(
  hls::stream<float> v63[1][4],
  hls::stream<float> v64[4][4],
  hls::stream<float> v65[1][4],
  float v66
) {
  float v67[128][256];
  #pragma HLS array_partition variable=v67 cyclic dim=2 factor=4

  float v68[128][256];
  #pragma HLS array_partition variable=v68 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v68 cyclic dim=2 factor=4

  float v69[128][128];
  #pragma HLS array_partition variable=v69 cyclic dim=2 factor=4

  loop22: for (int v70 = 0; v70 < 128; v70++) {
    loop23: for (int v71 = 0; v71 < 32; v71++) {
      loop24: for (int v72 = 0; v72 < 64; v72++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop25: for (int v73 = 0; v73 < 1; v73++) {
          loop26: for (int v74 = 0; v74 < 4; v74++) {
            loop27: for (int v75 = 0; v75 < 4; v75++) {
              if ((v75 + (v72 * 4)) == 0) {
                float v76 = v63[v73][v74].read();
                v69[(v70 + v73)][(v74 + (v71 * 4))] = v76;
              }
              float v77 = v69[(v70 + v73)][(v74 + (v71 * 4))];
              if ((v70 + v73) == 0) {
                float v78 = v64[v74][v75].read();
                v68[(v74 + (v71 * 4))][(v75 + (v72 * 4))] = v78;
              }
              float v79 = v68[(v74 + (v71 * 4))][(v75 + (v72 * 4))];
              if ((v74 + (v71 * 4)) == 0) {
                v67[(v70 + v73)][(v75 + (v72 * 4))] = v66;
              }
              float v80 = v67[(v70 + v73)][(v75 + (v72 * 4))];
              float v81 = v77 * v79;
              float v82 = v80 + v81;
              v67[(v70 + v73)][(v75 + (v72 * 4))] = v82;
              if (((v74 + (v71 * 4)) - 127) == 0) {
                float v83 = v67[(v70 + v73)][(v75 + (v72 * 4))];
                v65[v73][v75].write(v83);
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
  float v84[256][128],
  hls::stream<float> v85[4][4]
) {
  #pragma HLS array_partition variable=v84 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v84 cyclic dim=2 factor=4

  loop28: for (int v86 = 0; v86 < 32; v86++) {
    loop29: for (int v87 = 0; v87 < 64; v87++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop30: for (int v88 = 0; v88 < 4; v88++) {
        loop31: for (int v89 = 0; v89 < 4; v89++) {
          float v90 = v84[(v89 + (v87 * 4))][(v88 + (v86 * 4))];
          v85[v88][v89].write(v90);
        }
      }
    }
  }
  return ;
}

void node7(
  hls::stream<float> v91[1][4],
  float v92[128],
  hls::stream<float> v93[1][4],
  float v94
) {
  #pragma HLS array_partition variable=v92 cyclic dim=1 factor=4

  loop32: for (int v95 = 0; v95 < 128; v95++) {
    loop33: for (int v96 = 0; v96 < 32; v96++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop34: for (int v97 = 0; v97 < 1; v97++) {
        loop35: for (int v98 = 0; v98 < 4; v98++) {
          float v99 = v91[v97][v98].read();
          float v100 = v92[(v98 + (v96 * 4))];
          float v101 = v99 + v100;
          bool v102 = v101 > v94;
          float v103 = v102 ? (float)v101 : (float)v94;
          v93[v97][v98].write(v103);
        }
      }
    }
  }
  return ;
}

void node8(
  hls::stream<float> v104[1][4],
  hls::stream<float> v105[1][1],
  hls::stream<float> v106[1][4],
  float v107
) {
  float v108[128][128];
  #pragma HLS array_partition variable=v108 cyclic dim=2 factor=4

  float v109[64][128];
  #pragma HLS array_partition variable=v109 cyclic dim=2 factor=4

  float v110[128][64];
  loop36: for (int v111 = 0; v111 < 128; v111++) {
    loop37: for (int v112 = 0; v112 < 64; v112++) {
      loop38: for (int v113 = 0; v113 < 32; v113++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop39: for (int v114 = 0; v114 < 1; v114++) {
          loop40: for (int v115 = 0; v115 < 1; v115++) {
            loop41: for (int v116 = 0; v116 < 4; v116++) {
              if ((v116 + (v113 * 4)) == 0) {
                float v117 = v105[v114][v115].read();
                v110[(v111 + v114)][(v112 + v115)] = v117;
              }
              float v118 = v110[(v111 + v114)][(v112 + v115)];
              if ((v111 + v114) == 0) {
                float v119 = v104[v115][v116].read();
                v109[(v112 + v115)][(v116 + (v113 * 4))] = v119;
              }
              float v120 = v109[(v112 + v115)][(v116 + (v113 * 4))];
              if ((v112 + v115) == 0) {
                v108[(v111 + v114)][(v116 + (v113 * 4))] = v107;
              }
              float v121 = v108[(v111 + v114)][(v116 + (v113 * 4))];
              float v122 = v118 * v120;
              float v123 = v121 + v122;
              v108[(v111 + v114)][(v116 + (v113 * 4))] = v123;
              if (((v112 + v115) - 63) == 0) {
                float v124 = v108[(v111 + v114)][(v116 + (v113 * 4))];
                v106[v114][v116].write(v124);
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
  float v125[128][64],
  hls::stream<float> v126[1][4]
) {
  #pragma HLS array_partition variable=v125 cyclic dim=1 factor=4

  loop42: for (int v127 = 0; v127 < 64; v127++) {
    loop43: for (int v128 = 0; v128 < 32; v128++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop44: for (int v129 = 0; v129 < 1; v129++) {
        loop45: for (int v130 = 0; v130 < 4; v130++) {
          float v131 = v125[(v130 + (v128 * 4))][(v127 + v129)];
          v126[v129][v130].write(v131);
        }
      }
    }
  }
  return ;
}

void node10(
  hls::stream<float> v132[1][1],
  float v133[64],
  hls::stream<float> v134[1][1]
) {
  loop46: for (int v135 = 0; v135 < 128; v135++) {
    loop47: for (int v136 = 0; v136 < 64; v136++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop48: for (int v137 = 0; v137 < 1; v137++) {
        loop49: for (int v138 = 0; v138 < 1; v138++) {
          float v139 = v132[v137][v138].read();
          float v140 = v133[(v136 + v138)];
          float v141 = v139 + v140;
          v134[v137][v138].write(v141);
        }
      }
    }
  }
  return ;
}

void node11(
  hls::stream<float> v142[1][8],
  float v143[128][64],
  hls::stream<float> v144[1][1],
  float v145
) {
  #pragma HLS array_partition variable=v143 cyclic dim=1 factor=8

  float v146[128][64];
  float v147[128][64];
  #pragma HLS array_partition variable=v147 cyclic dim=1 factor=8

  float v148[128][128];
  #pragma HLS array_partition variable=v148 cyclic dim=2 factor=8

  loop50: for (int v149 = 0; v149 < 128; v149++) {
    loop51: for (int v150 = 0; v150 < 16; v150++) {
      loop52: for (int v151 = 0; v151 < 64; v151++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop53: for (int v152 = 0; v152 < 1; v152++) {
          loop54: for (int v153 = 0; v153 < 8; v153++) {
            loop55: for (int v154 = 0; v154 < 1; v154++) {
              if ((v151 + v154) == 0) {
                float v155 = v142[v152][v153].read();
                v148[(v149 + v152)][(v153 + (v150 * 8))] = v155;
              }
              float v156 = v148[(v149 + v152)][(v153 + (v150 * 8))];
              if ((v149 + v152) == 0) {
                float v157 = v143[(v153 + (v150 * 8))][(v151 + v154)];
                v147[(v153 + (v150 * 8))][(v151 + v154)] = v157;
              }
              float v158 = v147[(v153 + (v150 * 8))][(v151 + v154)];
              if ((v153 + (v150 * 8)) == 0) {
                v146[(v149 + v152)][(v151 + v154)] = v145;
              }
              float v159 = v146[(v149 + v152)][(v151 + v154)];
              float v160 = v156 * v158;
              float v161 = v159 + v160;
              v146[(v149 + v152)][(v151 + v154)] = v161;
              if (((v153 + (v150 * 8)) - 127) == 0) {
                float v162 = v146[(v149 + v152)][(v151 + v154)];
                v144[v152][v154].write(v162);
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
  float v163[64][128],
  float v164[128][64]
) {
  #pragma HLS array_partition variable=v163 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v164 cyclic dim=1 factor=8

  loop56: for (int v165 = 0; v165 < 64; v165++) {
    loop57: for (int v166 = 0; v166 < 16; v166++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop58: for (int v167 = 0; v167 < 1; v167++) {
        loop59: for (int v168 = 0; v168 < 8; v168++) {
          float v169 = v163[(v165 + v167)][(v168 + (v166 * 8))];
          v164[(v168 + (v166 * 8))][(v165 + v167)] = v169;
        }
      }
    }
  }
  return ;
}

void node13(
  hls::stream<float> v170[1][8],
  float v171[128],
  hls::stream<float> v172[1][8],
  float v173
) {
  #pragma HLS array_partition variable=v171 cyclic dim=1 factor=8

  loop60: for (int v174 = 0; v174 < 128; v174++) {
    loop61: for (int v175 = 0; v175 < 16; v175++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop62: for (int v176 = 0; v176 < 1; v176++) {
        loop63: for (int v177 = 0; v177 < 8; v177++) {
          float v178 = v170[v176][v177].read();
          float v179 = v171[(v177 + (v175 * 8))];
          float v180 = v178 + v179;
          bool v181 = v180 > v173;
          float v182 = v181 ? (float)v180 : (float)v173;
          v172[v176][v177].write(v182);
        }
      }
    }
  }
  return ;
}

void node14(
  hls::stream<float> v183[1][8],
  hls::stream<float> v184[1][1],
  hls::stream<float> v185[1][8],
  float v186
) {
  float v187[128][128];
  #pragma HLS array_partition variable=v187 cyclic dim=2 factor=8

  float v188[256][128];
  #pragma HLS array_partition variable=v188 cyclic dim=2 factor=8

  float v189[128][256];
  loop64: for (int v190 = 0; v190 < 128; v190++) {
    loop65: for (int v191 = 0; v191 < 256; v191++) {
      loop66: for (int v192 = 0; v192 < 16; v192++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop67: for (int v193 = 0; v193 < 1; v193++) {
          loop68: for (int v194 = 0; v194 < 1; v194++) {
            loop69: for (int v195 = 0; v195 < 8; v195++) {
              if ((v195 + (v192 * 8)) == 0) {
                float v196 = v184[v193][v194].read();
                v189[(v190 + v193)][(v191 + v194)] = v196;
              }
              float v197 = v189[(v190 + v193)][(v191 + v194)];
              if ((v190 + v193) == 0) {
                float v198 = v183[v194][v195].read();
                v188[(v191 + v194)][(v195 + (v192 * 8))] = v198;
              }
              float v199 = v188[(v191 + v194)][(v195 + (v192 * 8))];
              if ((v191 + v194) == 0) {
                v187[(v190 + v193)][(v195 + (v192 * 8))] = v186;
              }
              float v200 = v187[(v190 + v193)][(v195 + (v192 * 8))];
              float v201 = v197 * v199;
              float v202 = v200 + v201;
              v187[(v190 + v193)][(v195 + (v192 * 8))] = v202;
              if (((v191 + v194) - 255) == 0) {
                float v203 = v187[(v190 + v193)][(v195 + (v192 * 8))];
                v185[v193][v195].write(v203);
              }
            }
          }
        }
      }
    }
  }
  return ;
}

void node15(
  float v204[128][256],
  hls::stream<float> v205[1][8]
) {
  #pragma HLS array_partition variable=v204 cyclic dim=1 factor=8

  loop70: for (int v206 = 0; v206 < 256; v206++) {
    loop71: for (int v207 = 0; v207 < 16; v207++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop72: for (int v208 = 0; v208 < 1; v208++) {
        loop73: for (int v209 = 0; v209 < 8; v209++) {
          float v210 = v204[(v209 + (v207 * 8))][(v206 + v208)];
          v205[v208][v209].write(v210);
        }
      }
    }
  }
  return ;
}

void node16(
  hls::stream<float> v211[1][1],
  float v212[256],
  hls::stream<float> v213[1][1],
  float v214
) {
  loop74: for (int v215 = 0; v215 < 128; v215++) {
    loop75: for (int v216 = 0; v216 < 256; v216++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop76: for (int v217 = 0; v217 < 1; v217++) {
        loop77: for (int v218 = 0; v218 < 1; v218++) {
          float v219 = v211[v217][v218].read();
          float v220 = v212[(v216 + v218)];
          float v221 = v219 + v220;
          bool v222 = v221 > v214;
          float v223 = v222 ? (float)v221 : (float)v214;
          v213[v217][v218].write(v223);
        }
      }
    }
  }
  return ;
}

void node17(
  hls::stream<float> v224[32][1],
  float v225[128][512],
  hls::stream<float> v226[1][1],
  float v227
) {
  #pragma HLS array_partition variable=v225 cyclic dim=2 factor=32

  float v228[128][256];
  float v229[512][256];
  #pragma HLS array_partition variable=v229 cyclic dim=1 factor=32

  loop78: for (int v230 = 0; v230 < 128; v230++) {
    loop79: for (int v231 = 0; v231 < 16; v231++) {
      loop80: for (int v232 = 0; v232 < 256; v232++) {
        #pragma HLS pipeline II=1
        #pragma HLS loop_flatten
        loop81: for (int v233 = 0; v233 < 1; v233++) {
          loop82: for (int v234 = 0; v234 < 32; v234++) {
            loop83: for (int v235 = 0; v235 < 1; v235++) {
              float v236 = v225[(v230 + v233)][(v234 + (v231 * 32))];
              if ((v230 + v233) == 0) {
                float v237 = v224[v234][v235].read();
                v229[(v234 + (v231 * 32))][(v232 + v235)] = v237;
              }
              float v238 = v229[(v234 + (v231 * 32))][(v232 + v235)];
              if ((v234 + (v231 * 32)) == 0) {
                v228[(v230 + v233)][(v232 + v235)] = v227;
              }
              float v239 = v228[(v230 + v233)][(v232 + v235)];
              float v240 = v236 * v238;
              float v241 = v239 + v240;
              v228[(v230 + v233)][(v232 + v235)] = v241;
              if (((v234 + (v231 * 32)) - 511) == 0) {
                float v242 = v228[(v230 + v233)][(v232 + v235)];
                v226[v233][v235].write(v242);
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
  float v243[256][512],
  hls::stream<float> v244[32][1]
) {
  #pragma HLS array_partition variable=v243 cyclic dim=2 factor=32

  loop84: for (int v245 = 0; v245 < 16; v245++) {
    loop85: for (int v246 = 0; v246 < 256; v246++) {
      #pragma HLS pipeline II=1
      #pragma HLS loop_flatten
      loop86: for (int v247 = 0; v247 < 32; v247++) {
        loop87: for (int v248 = 0; v248 < 1; v248++) {
          float v249 = v243[(v246 + v248)][(v247 + (v245 * 32))];
          v244[v247][v248].write(v249);
        }
      }
    }
  }
  return ;
}

void forward(
  float v250[128][512],
  float v251[256],
  float v252[256][512],
  float v253[128],
  float v254[128][256],
  float v255[64],
  float v256[64][128],
  float v257[128],
  float v258[128][64],
  float v259[256],
  float v260[256][128],
  float v261[512],
  float v262[512][256],
  float v263[128][512]
) {
	#pragma HLS DATAFLOW
  #pragma HLS array_partition variable=v250 cyclic dim=2 factor=32

  #pragma HLS array_partition variable=v252 cyclic dim=2 factor=32

  #pragma HLS array_partition variable=v253 cyclic dim=1 factor=8

  #pragma HLS array_partition variable=v254 cyclic dim=1 factor=8

  #pragma HLS array_partition variable=v256 cyclic dim=2 factor=8

  #pragma HLS array_partition variable=v257 cyclic dim=1 factor=4

  #pragma HLS array_partition variable=v258 cyclic dim=1 factor=4

  #pragma HLS array_partition variable=v259 cyclic dim=1 factor=4

  #pragma HLS array_partition variable=v260 cyclic dim=1 factor=4
  #pragma HLS array_partition variable=v260 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v261 cyclic dim=1 factor=16

  #pragma HLS array_partition variable=v262 cyclic dim=1 factor=16
  #pragma HLS array_partition variable=v262 cyclic dim=2 factor=4

  #pragma HLS array_partition variable=v263 cyclic dim=2 factor=16

  hls::stream<float> v264[1][16];
	#pragma HLS STREAM variable=v264 depth=4096
  hls::stream<float> v265[1][16];
	#pragma HLS STREAM variable=v265 depth=4096
  hls::stream<float> v266[4][16];
	#pragma HLS STREAM variable=v266 depth=2048
  hls::stream<float> v267[1][4];
	#pragma HLS STREAM variable=v267 depth=8192
  hls::stream<float> v268[1][4];
	#pragma HLS STREAM variable=v268 depth=8192
  hls::stream<float> v269[4][4];
	#pragma HLS STREAM variable=v269 depth=2048
  hls::stream<float> v270[1][4];
	#pragma HLS STREAM variable=v270 depth=4096
  hls::stream<float> v271[1][4];
	#pragma HLS STREAM variable=v271 depth=4096
  hls::stream<float> v272[1][4];
	#pragma HLS STREAM variable=v272 depth=2048
  hls::stream<float> v273[1][1];
	#pragma HLS STREAM variable=v273 depth=8192
  hls::stream<float> v274[1][1];
	#pragma HLS STREAM variable=v274 depth=8192
  float v275[128][64];
  #pragma HLS array_partition variable=v275 cyclic dim=1 factor=8

  hls::stream<float> v276[1][8];
	#pragma HLS STREAM variable=v276 depth=2048
  hls::stream<float> v277[1][8];
	#pragma HLS STREAM variable=v277 depth=2048
  hls::stream<float> v278[1][8];
	#pragma HLS STREAM variable=v278 depth=4096
  hls::stream<float> v279[1][1];
	#pragma HLS STREAM variable=v279 depth=32768
  hls::stream<float> v280[1][1];
	#pragma HLS STREAM variable=v280 depth=32768
  hls::stream<float> v281[32][1];
	#pragma HLS STREAM variable=v281 depth=4096
  node18(v252, v281);
  node17(v281, v250, v280, 0.000000);
  node16(v280, v251, v279, 0.000000);
  node15(v254, v278);
  node14(v278, v279, v277, 0.000000);
  node13(v277, v253, v276, 0.000000);
  node12(v256, v275);
  node11(v276, v275, v274, 0.000000);
  node10(v274, v255, v273);
  node9(v258, v272);
  node8(v272, v273, v271, 0.000000);
  node7(v271, v257, v270, 0.000000);
  node6(v260, v269);
  node5(v270, v269, v268, 0.000000);
  node4(v268, v259, v267, 0.000000);
  node3(v262, v266);
  node2(v266, v267, v265, 0.000000);
  node1(v265, v261, v264, 1.000000);
  node0(v264, v263);
  return ;
}

