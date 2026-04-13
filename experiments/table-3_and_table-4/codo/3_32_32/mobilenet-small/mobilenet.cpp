
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

void main_graph_node0(
  int8_t v0[1][1000],
  int8_t v1[1000],
  int8_t v2[1][1000]
) {	// L16
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L17
    for (int v4 = 0; v4 < 1000; v4 += 1) {	// L18
      int8_t v5 = v0[0][v4];	// L19
      int8_t v6 = v1[v4];	// L20
      int8_t v7 = v5 + v6;	// L21
      v2[v3][v4] = v7;	// L22
    }
  }
  return ;	// L25
}

void main_graph_node1(
  int8_t v8[1][1024][1][1],
  int8_t v9[1024][1000],
  int8_t v10[1][1000]
) {	// L27
  #pragma HLS dataflow

  int8_t v11[1][1000];	// L29
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L30
    for (int v13 = 0; v13 < 1000; v13 += 1) {	// L31
      v11[v12][v13] = (int8_t)0.000000;	// L32
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L35
    for (int v15 = 0; v15 < 1000; v15 += 1) {	// L36
      for (int v16 = 0; v16 < 1024; v16 += 1) {	// L37
        int8_t v17 = v8[v14][v16][0][0];	// L38
        int8_t v18 = v9[v16][v15];	// L39
        int8_t v19 = v11[v14][v15];	// L40
        int8_t v20 = v17 * v18;	// L41
        int8_t v21 = v19 + v20;	// L42
        v10[v14][v15] = v21;	// L43
      }
    }
  }
  return ;	// L47
}

void main_graph_node2(
  int8_t v22[1][1024][1][1],
  int8_t v23[1][1],
  int8_t v24[1][1024][1][1]
) {	// L49
  #pragma HLS dataflow

  int8_t v25[1][1024][1][1];	// L50
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  for (int v26 = 0; v26 < 1; v26 += 1) {	// L51
    for (int v27 = 0; v27 < 1024; v27 += 1) {	// L52
      for (int v28 = 0; v28 < 1; v28 += 1) {	// L53
        for (int v29 = 0; v29 < 1; v29 += 1) {	// L54
          int8_t v30 = v22[v26][v27][v28][v29];	// L55
          v25[v26][v27][v28][v29] = v30;	// L56
          int8_t v31 = v23[v28][v29];	// L57
          int8_t v32 = v25[v26][v27][v28][v29];	// L58
          int8_t v33 = v32 / v31;	// L59
          v24[v26][v27][v28][v29] = v33;	// L60
        }
      }
    }
  }
  return ;	// L65
}

void main_graph_node3(
  int8_t v34[1][1024][2][2],
  int8_t v35[1][1],
  int8_t v36[1][1024][1][1]
) {	// L67
  #pragma HLS dataflow

  int8_t v37[1][1024][1][1];	// L71
  #pragma HLS bind_storage variable=v37 type=ram_t2p impl=bram

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L72
    for (int v39 = 0; v39 < 1024; v39 += 1) {	// L73
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L74
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L75
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L76
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L81
    for (int v43 = 0; v43 < 1024; v43 += 1) {	// L82
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L83
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L84
          for (int v46 = 0; v46 < 1; v46 += 1) {	// L85
            for (int v47 = 0; v47 < 1; v47 += 1) {	// L86
              int8_t v48 = v37[v42][v43][v44][v45];	// L87
              int v49 = v44 + (int)1;	// L88
              int v50 = v45 + (int)1;	// L89
              int v51 = v44 + v46;	// L90
              int v52 = v45 + v47;	// L91
              int8_t v53 = v34[v42][v43][v51][v52];	// L92
              bool v54 = v51 < v49;	// L93
              int8_t v55 = v54 ? v53 : (int8_t)0.000000;	// L94
              bool v56 = v52 < v50;	// L95
              int8_t v57 = v56 ? v55 : (int8_t)0.000000;	// L96
              int8_t v58 = v57 + v48;	// L97
              v36[v42][v43][v44][v45] = v58;	// L98
              v35[v42][v43] = (int8_t)1.000000;	// L99
            }
          }
        }
      }
    }
  }
  return ;	// L106
}

void main_graph_node4(
  int8_t v59[1][1024][1][1],
  int8_t v60[1][1024][2][2]
) {	// L108
  #pragma HLS dataflow

  for (int v61 = 0; v61 < 1; v61 += 1) {	// L110
    for (int v62 = 0; v62 < 2; v62 += 1) {	// L111
      for (int v63 = 0; v63 < 2; v63 += 1) {	// L112
        for (int v64 = 0; v64 < 1024; v64 += 1) {	// L113
          int8_t v65;	// L114
          v65 = (int8_t)0.000000;	// L115
          if ((-v62) >= 0 && (-v63) >= 0) {	// L116
            int8_t v66 = v59[v61][v64][v62][v63];	// L117
            v65 = v66;	// L118
          }
          int8_t v67 = v65;	// L120
          v60[v61][v64][v62][v63] = v67;	// L121
        }
      }
    }
  }
  return ;	// L126
}

void main_graph_node5(
  int8_t v68[1024][1024][1][1],
  int8_t v69[1][1024][1][1],
  int8_t v70[1][1024][1][1]
) {	// L128
  #pragma HLS dataflow

  int8_t v71[1][1024][1][1];	// L130
  #pragma HLS stream variable=v71 depth=10 type=fifo

  #pragma HLS bind_storage variable=v71 type=ram_t2p impl=bram

  int8_t v72[1][1024][1][1];	// L131
  #pragma HLS bind_storage variable=v72 type=ram_2p impl=bram

  int8_t v73[1][1024][1][1];	// L132
  #pragma HLS array_partition variable=v73 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v73 type=ram_2p impl=lutram

  for (int v74 = 0; v74 < 1; v74 += 1) {	// L133
    for (int v75 = 0; v75 < 1; v75 += 1) {	// L134
      for (int v76 = 0; v76 < 1; v76 += 1) {	// L135
        for (int v77 = 0; v77 < 1024; v77 += 1) {	// L136
          int8_t v78 = v69[v74][v77][v75][v76];	// L137
          v72[v74][v77][0][v76] = v78;	// L138
        }
        if (v75 >= 0) {	// L140
          for (int v79 = 0; v79 < 1024; v79 += 1) {	// L141
            for (int v80 = 0; v80 < 1; v80 += 1) {	// L142
              int8_t v81 = v72[v74][v79][v80][v76];	// L143
              v73[v74][v79][v80][0] = v81;	// L144
            }
          }
          if (v76 >= 0) {	// L147
            int8_t v82[1024];	// L148
            #pragma HLS bind_storage variable=v82 type=ram_2p impl=bram

            for (int v83 = 0; v83 < 1024; v83 += 1) {	// L149
              v82[v83] = (int8_t)0.000000;	// L150
              for (int v84 = 0; v84 < 64; v84 += 1) {	// L151
                #pragma HLS pipeline II=1
                for (int v85 = 0; v85 < 16; v85 += 1) {	// L152
                  for (int v86 = 0; v86 < 1; v86 += 1) {	// L153
                    for (int v87 = 0; v87 < 1; v87 += 1) {	// L154
                      int8_t v88 = v73[v74][(v85 + (v84 * 16))][v86][v87];	// L155
                      int8_t v89 = v68[v83][(v85 + (v84 * 16))][v86][v87];	// L156
                      int8_t v90 = v88 * v89;	// L157
                      int8_t v91 = v82[v83];	// L158
                      int8_t v92 = v91 + v90;	// L159
                      v82[v83] = v92;	// L160
                    }
                  }
                }
              }
              int8_t v93 = v82[v83];	// L165
              v71[v74][v83][v75][v76] = v93;	// L166
            }
          }
        }
      }
    }
  }
  for (int v94 = 0; v94 < 1; v94 += 1) {	// L173
    for (int v95 = 0; v95 < 1; v95 += 1) {	// L174
      for (int v96 = 0; v96 < 1; v96 += 1) {	// L175
        for (int v97 = 0; v97 < 1024; v97 += 1) {	// L176
          int8_t v98 = v71[0][v97][0][0];	// L177
          bool v99 = v98 > (int8_t)0.000000;	// L178
          int8_t v100 = v99 ? v98 : (int8_t)0.000000;	// L179
          v70[v94][v97][v95][v96] = v100;	// L180
        }
      }
    }
  }
  return ;	// L185
}

void main_graph_node6(
  int8_t v101[1][1024][1][1],
  int8_t v102[1024][3][3],
  int8_t v103[1][1024][1][1]
) {	// L187
  #pragma HLS dataflow

  int8_t v104[1][1024][3][3];	// L189
  #pragma HLS stream variable=v104 depth=10 type=fifo

  #pragma HLS bind_storage variable=v104 type=ram_t2p impl=bram

  for (int v105 = 0; v105 < 1; v105 += 1) {	// L190
    for (int v106 = 0; v106 < 3; v106 += 1) {	// L191
      for (int v107 = 0; v107 < 3; v107 += 1) {	// L192
        for (int v108 = 0; v108 < 1024; v108 += 1) {	// L193
          int8_t v109;	// L194
          v109 = (int8_t)0.000000;	// L195
          if ((-v106) >= 0 && (-v107) >= 0) {	// L196
            int8_t v110 = v101[v105][v108][v106][v107];	// L197
            v109 = v110;	// L198
          }
          int8_t v111 = v109;	// L200
          v104[v105][v108][v106][v107] = v111;	// L201
        }
      }
    }
  }
  int8_t v112[1][1024][1][1];	// L206
  #pragma HLS stream variable=v112 depth=10 type=fifo

  #pragma HLS bind_storage variable=v112 type=ram_t2p impl=bram

  int8_t v113[1][1024][3][3];	// L207
  #pragma HLS array_partition variable=v113 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v113 type=ram_2p impl=bram

  int8_t v114[1][1024][3][3];	// L208
  #pragma HLS array_partition variable=v114 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v114 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v114 type=ram_2p impl=bram

  for (int v115 = 0; v115 < 1; v115 += 1) {	// L209
    for (int v116 = 0; v116 < 3; v116 += 1) {	// L210
      for (int v117 = 0; v117 < 3; v117 += 1) {	// L211
        for (int v118 = 0; v118 < 1024; v118 += 1) {	// L212
          int8_t v119 = v113[v115][v118][1][v117];	// L213
          v113[v115][v118][0][v117] = v119;	// L214
          int8_t v120 = v113[v115][v118][2][v117];	// L215
          v113[v115][v118][1][v117] = v120;	// L216
          int8_t v121 = v104[v115][v118][v116][v117];	// L217
          v113[v115][v118][2][v117] = v121;	// L218
        }
        if ((v116 - 2) >= 0) {	// L220
          for (int v122 = 0; v122 < 1024; v122 += 1) {	// L221
            for (int v123 = 0; v123 < 3; v123 += 1) {	// L222
              int8_t v124 = v114[v115][v122][v123][1];	// L223
              v114[v115][v122][v123][0] = v124;	// L224
              int8_t v125 = v114[v115][v122][v123][2];	// L225
              v114[v115][v122][v123][1] = v125;	// L226
              int8_t v126 = v113[v115][v122][v123][v117];	// L227
              v114[v115][v122][v123][2] = v126;	// L228
            }
          }
          if ((v117 - 2) >= 0) {	// L231
            int8_t v127[1024];	// L232
            #pragma HLS bind_storage variable=v127 type=ram_2p impl=bram

            for (int v128 = 0; v128 < 1024; v128 += 1) {	// L233
              #pragma HLS pipeline II=1
              for (int v129 = 0; v129 < 1; v129 += 1) {	// L234
                v127[(v128 + v129)] = (int8_t)0.000000;	// L235
                for (int v130 = 0; v130 < 3; v130 += 1) {	// L236
                  for (int v131 = 0; v131 < 3; v131 += 1) {	// L237
                    int8_t v132 = v114[v115][(v128 + v129)][v130][v131];	// L238
                    int8_t v133 = v102[(v128 + v129)][v130][v131];	// L239
                    int8_t v134 = v132 * v133;	// L240
                    int8_t v135 = v127[(v128 + v129)];	// L241
                    int8_t v136 = v135 + v134;	// L242
                    v127[(v128 + v129)] = v136;	// L243
                  }
                }
                int8_t v137 = v127[(v128 + v129)];	// L246
                v112[v115][(v128 + v129)][(v116 - 2)][(v117 - 2)] = v137;	// L247
              }
            }
          }
        }
      }
    }
  }
  for (int v138 = 0; v138 < 1; v138 += 1) {	// L255
    for (int v139 = 0; v139 < 1; v139 += 1) {	// L256
      for (int v140 = 0; v140 < 1; v140 += 1) {	// L257
        for (int v141 = 0; v141 < 1024; v141 += 1) {	// L258
          int8_t v142 = v112[0][v141][0][0];	// L259
          bool v143 = v142 > (int8_t)0.000000;	// L260
          int8_t v144 = v143 ? v142 : (int8_t)0.000000;	// L261
          v103[v138][v141][v139][v140] = v144;	// L262
        }
      }
    }
  }
  return ;	// L267
}

void main_graph_node7(
  int8_t v145[1024][512][1][1],
  int8_t v146[1][512][1][1],
  int8_t v147[1][1024][1][1]
) {	// L269
  #pragma HLS dataflow

  int8_t v148[1][1024][1][1];	// L271
  #pragma HLS stream variable=v148 depth=10 type=fifo

  #pragma HLS bind_storage variable=v148 type=ram_t2p impl=bram

  int8_t v149[1][512][1][1];	// L272
  #pragma HLS bind_storage variable=v149 type=ram_2p impl=bram

  int8_t v150[1][512][1][1];	// L273
  #pragma HLS array_partition variable=v150 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v150 type=ram_2p impl=lutram

  for (int v151 = 0; v151 < 1; v151 += 1) {	// L274
    for (int v152 = 0; v152 < 1; v152 += 1) {	// L275
      for (int v153 = 0; v153 < 1; v153 += 1) {	// L276
        for (int v154 = 0; v154 < 512; v154 += 1) {	// L277
          int8_t v155 = v146[v151][v154][v152][v153];	// L278
          v149[v151][v154][0][v153] = v155;	// L279
        }
        if (v152 >= 0) {	// L281
          for (int v156 = 0; v156 < 512; v156 += 1) {	// L282
            for (int v157 = 0; v157 < 1; v157 += 1) {	// L283
              int8_t v158 = v149[v151][v156][v157][v153];	// L284
              v150[v151][v156][v157][0] = v158;	// L285
            }
          }
          if (v153 >= 0) {	// L288
            int8_t v159[1024];	// L289
            #pragma HLS bind_storage variable=v159 type=ram_2p impl=bram

            for (int v160 = 0; v160 < 1024; v160 += 1) {	// L290
              v159[v160] = (int8_t)0.000000;	// L291
              for (int v161 = 0; v161 < 64; v161 += 1) {	// L292
                #pragma HLS pipeline II=1
                for (int v162 = 0; v162 < 8; v162 += 1) {	// L293
                  for (int v163 = 0; v163 < 1; v163 += 1) {	// L294
                    for (int v164 = 0; v164 < 1; v164 += 1) {	// L295
                      int8_t v165 = v150[v151][(v162 + (v161 * 8))][v163][v164];	// L296
                      int8_t v166 = v145[v160][(v162 + (v161 * 8))][v163][v164];	// L297
                      int8_t v167 = v165 * v166;	// L298
                      int8_t v168 = v159[v160];	// L299
                      int8_t v169 = v168 + v167;	// L300
                      v159[v160] = v169;	// L301
                    }
                  }
                }
              }
              int8_t v170 = v159[v160];	// L306
              v148[v151][v160][v152][v153] = v170;	// L307
            }
          }
        }
      }
    }
  }
  for (int v171 = 0; v171 < 1; v171 += 1) {	// L314
    for (int v172 = 0; v172 < 1; v172 += 1) {	// L315
      for (int v173 = 0; v173 < 1; v173 += 1) {	// L316
        for (int v174 = 0; v174 < 1024; v174 += 1) {	// L317
          int8_t v175 = v148[0][v174][0][0];	// L318
          bool v176 = v175 > (int8_t)0.000000;	// L319
          int8_t v177 = v176 ? v175 : (int8_t)0.000000;	// L320
          v147[v171][v174][v172][v173] = v177;	// L321
        }
      }
    }
  }
  return ;	// L326
}

void main_graph_node8(
  int8_t v178[512][3][3],
  int8_t v179[1][512][2][2],
  int8_t v180[1][512][1][1]
) {	// L328
  #pragma HLS dataflow

  int8_t v181[1][512][4][4];	// L330
  #pragma HLS stream variable=v181 depth=10 type=fifo

  #pragma HLS bind_storage variable=v181 type=ram_t2p impl=bram

  for (int v182 = 0; v182 < 1; v182 += 1) {	// L331
    for (int v183 = 0; v183 < 4; v183 += 1) {	// L332
      for (int v184 = 0; v184 < 4; v184 += 1) {	// L333
        for (int v185 = 0; v185 < 512; v185 += 1) {	// L334
          int8_t v186;	// L335
          v186 = (int8_t)0.000000;	// L336
          if (((-v183) + 1) >= 0 && ((-v184) + 1) >= 0) {	// L337
            int8_t v187 = v179[v182][v185][v183][v184];	// L338
            v186 = v187;	// L339
          }
          int8_t v188 = v186;	// L341
          v181[v182][v185][v183][v184] = v188;	// L342
        }
      }
    }
  }
  int8_t v189[1][512][1][1];	// L347
  #pragma HLS stream variable=v189 depth=10 type=fifo

  #pragma HLS bind_storage variable=v189 type=ram_t2p impl=bram

  int8_t v190[1][512][3][4];	// L348
  #pragma HLS array_partition variable=v190 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v190 type=ram_2p impl=bram

  int8_t v191[1][512][3][3];	// L349
  #pragma HLS array_partition variable=v191 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v191 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v191 type=ram_2p impl=lutram

  for (int v192 = 0; v192 < 1; v192 += 1) {	// L350
    for (int v193 = 0; v193 < 4; v193 += 1) {	// L351
      for (int v194 = 0; v194 < 4; v194 += 1) {	// L352
        for (int v195 = 0; v195 < 512; v195 += 1) {	// L353
          int8_t v196 = v190[v192][v195][1][v194];	// L354
          v190[v192][v195][0][v194] = v196;	// L355
          int8_t v197 = v190[v192][v195][2][v194];	// L356
          v190[v192][v195][1][v194] = v197;	// L357
          int8_t v198 = v181[v192][v195][v193][v194];	// L358
          v190[v192][v195][2][v194] = v198;	// L359
        }
        if ((v193 - 3) >= 0) {	// L361
          for (int v199 = 0; v199 < 512; v199 += 1) {	// L362
            for (int v200 = 0; v200 < 3; v200 += 1) {	// L363
              int8_t v201 = v191[v192][v199][v200][1];	// L364
              v191[v192][v199][v200][0] = v201;	// L365
              int8_t v202 = v191[v192][v199][v200][2];	// L366
              v191[v192][v199][v200][1] = v202;	// L367
              int8_t v203 = v190[v192][v199][v200][v194];	// L368
              v191[v192][v199][v200][2] = v203;	// L369
            }
          }
          if ((v194 - 3) >= 0) {	// L372
            int8_t v204[512];	// L373
            #pragma HLS bind_storage variable=v204 type=ram_2p impl=bram

            for (int v205 = 0; v205 < 512; v205 += 1) {	// L374
              #pragma HLS pipeline II=1
              for (int v206 = 0; v206 < 1; v206 += 1) {	// L375
                v204[(v205 + v206)] = (int8_t)0.000000;	// L376
                for (int v207 = 0; v207 < 3; v207 += 1) {	// L377
                  for (int v208 = 0; v208 < 3; v208 += 1) {	// L378
                    int8_t v209 = v191[v192][(v205 + v206)][v207][v208];	// L379
                    int8_t v210 = v178[(v205 + v206)][v207][v208];	// L380
                    int8_t v211 = v209 * v210;	// L381
                    int8_t v212 = v204[(v205 + v206)];	// L382
                    int8_t v213 = v212 + v211;	// L383
                    v204[(v205 + v206)] = v213;	// L384
                  }
                }
                int8_t v214 = v204[(v205 + v206)];	// L387
                v189[v192][(v205 + v206)][(v193 - 3)][(v194 - 3)] = v214;	// L388
              }
            }
          }
        }
      }
    }
  }
  for (int v215 = 0; v215 < 1; v215 += 1) {	// L396
    for (int v216 = 0; v216 < 1; v216 += 1) {	// L397
      for (int v217 = 0; v217 < 1; v217 += 1) {	// L398
        for (int v218 = 0; v218 < 512; v218 += 1) {	// L399
          int8_t v219 = v189[0][v218][0][0];	// L400
          bool v220 = v219 > (int8_t)0.000000;	// L401
          int8_t v221 = v220 ? v219 : (int8_t)0.000000;	// L402
          v180[v215][v218][v216][v217] = v221;	// L403
        }
      }
    }
  }
  return ;	// L408
}

void main_graph_node9(
  int8_t v222[512][512][1][1],
  int8_t v223[1][512][2][2],
  int8_t v224[1][512][2][2]
) {	// L410
  #pragma HLS dataflow

  int8_t v225[1][512][2][2];	// L412
  #pragma HLS stream variable=v225 depth=10 type=fifo

  #pragma HLS bind_storage variable=v225 type=ram_t2p impl=bram

  int8_t v226[1][512][1][2];	// L413
  #pragma HLS bind_storage variable=v226 type=ram_2p impl=bram

  int8_t v227[1][512][1][1];	// L414
  #pragma HLS array_partition variable=v227 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v227 type=ram_2p impl=lutram

  for (int v228 = 0; v228 < 1; v228 += 1) {	// L415
    for (int v229 = 0; v229 < 2; v229 += 1) {	// L416
      for (int v230 = 0; v230 < 2; v230 += 1) {	// L417
        for (int v231 = 0; v231 < 512; v231 += 1) {	// L418
          int8_t v232 = v223[v228][v231][v229][v230];	// L419
          v226[v228][v231][0][v230] = v232;	// L420
        }
        if (v229 >= 0) {	// L422
          for (int v233 = 0; v233 < 512; v233 += 1) {	// L423
            for (int v234 = 0; v234 < 1; v234 += 1) {	// L424
              int8_t v235 = v226[v228][v233][v234][v230];	// L425
              v227[v228][v233][v234][0] = v235;	// L426
            }
          }
          if (v230 >= 0) {	// L429
            int8_t v236[512];	// L430
            #pragma HLS bind_storage variable=v236 type=ram_2p impl=bram

            for (int v237 = 0; v237 < 512; v237 += 1) {	// L431
              v236[v237] = (int8_t)0.000000;	// L432
              for (int v238 = 0; v238 < 32; v238 += 1) {	// L433
                #pragma HLS pipeline II=1
                for (int v239 = 0; v239 < 16; v239 += 1) {	// L434
                  for (int v240 = 0; v240 < 1; v240 += 1) {	// L435
                    for (int v241 = 0; v241 < 1; v241 += 1) {	// L436
                      int8_t v242 = v227[v228][(v239 + (v238 * 16))][v240][v241];	// L437
                      int8_t v243 = v222[v237][(v239 + (v238 * 16))][v240][v241];	// L438
                      int8_t v244 = v242 * v243;	// L439
                      int8_t v245 = v236[v237];	// L440
                      int8_t v246 = v245 + v244;	// L441
                      v236[v237] = v246;	// L442
                    }
                  }
                }
              }
              int8_t v247 = v236[v237];	// L447
              v225[v228][v237][v229][v230] = v247;	// L448
            }
          }
        }
      }
    }
  }
  for (int v248 = 0; v248 < 1; v248 += 1) {	// L455
    for (int v249 = 0; v249 < 2; v249 += 1) {	// L456
      for (int v250 = 0; v250 < 2; v250 += 1) {	// L457
        for (int v251 = 0; v251 < 512; v251 += 1) {	// L458
          int8_t v252 = v225[0][v251][v249][v250];	// L459
          bool v253 = v252 > (int8_t)0.000000;	// L460
          int8_t v254 = v253 ? v252 : (int8_t)0.000000;	// L461
          v224[v248][v251][v249][v250] = v254;	// L462
        }
      }
    }
  }
  return ;	// L467
}

void main_graph_node10(
  int8_t v255[1][512][2][2],
  int8_t v256[512][3][3],
  int8_t v257[1][512][2][2]
) {	// L469
  #pragma HLS dataflow

  int8_t v258[1][512][4][4];	// L471
  #pragma HLS stream variable=v258 depth=10 type=fifo

  #pragma HLS bind_storage variable=v258 type=ram_t2p impl=bram

  for (int v259 = 0; v259 < 1; v259 += 1) {	// L472
    for (int v260 = 0; v260 < 4; v260 += 1) {	// L473
      for (int v261 = 0; v261 < 4; v261 += 1) {	// L474
        for (int v262 = 0; v262 < 512; v262 += 1) {	// L475
          int8_t v263;	// L476
          v263 = (int8_t)0.000000;	// L477
          if (((-v260) + 1) >= 0 && ((-v261) + 1) >= 0) {	// L478
            int8_t v264 = v255[v259][v262][v260][v261];	// L479
            v263 = v264;	// L480
          }
          int8_t v265 = v263;	// L482
          v258[v259][v262][v260][v261] = v265;	// L483
        }
      }
    }
  }
  int8_t v266[1][512][2][2];	// L488
  #pragma HLS stream variable=v266 depth=10 type=fifo

  #pragma HLS bind_storage variable=v266 type=ram_t2p impl=bram

  int8_t v267[1][512][3][4];	// L489
  #pragma HLS array_partition variable=v267 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v267 type=ram_2p impl=bram

  int8_t v268[1][512][3][3];	// L490
  #pragma HLS array_partition variable=v268 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v268 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v268 type=ram_2p impl=lutram

  for (int v269 = 0; v269 < 1; v269 += 1) {	// L491
    for (int v270 = 0; v270 < 4; v270 += 1) {	// L492
      for (int v271 = 0; v271 < 4; v271 += 1) {	// L493
        for (int v272 = 0; v272 < 512; v272 += 1) {	// L494
          int8_t v273 = v267[v269][v272][1][v271];	// L495
          v267[v269][v272][0][v271] = v273;	// L496
          int8_t v274 = v267[v269][v272][2][v271];	// L497
          v267[v269][v272][1][v271] = v274;	// L498
          int8_t v275 = v258[v269][v272][v270][v271];	// L499
          v267[v269][v272][2][v271] = v275;	// L500
        }
        if ((v270 - 2) >= 0) {	// L502
          for (int v276 = 0; v276 < 512; v276 += 1) {	// L503
            for (int v277 = 0; v277 < 3; v277 += 1) {	// L504
              int8_t v278 = v268[v269][v276][v277][1];	// L505
              v268[v269][v276][v277][0] = v278;	// L506
              int8_t v279 = v268[v269][v276][v277][2];	// L507
              v268[v269][v276][v277][1] = v279;	// L508
              int8_t v280 = v267[v269][v276][v277][v271];	// L509
              v268[v269][v276][v277][2] = v280;	// L510
            }
          }
          if ((v271 - 2) >= 0) {	// L513
            int8_t v281[512];	// L514
            #pragma HLS bind_storage variable=v281 type=ram_2p impl=bram

            for (int v282 = 0; v282 < 512; v282 += 1) {	// L515
              #pragma HLS pipeline II=1
              for (int v283 = 0; v283 < 1; v283 += 1) {	// L516
                v281[(v282 + v283)] = (int8_t)0.000000;	// L517
                for (int v284 = 0; v284 < 3; v284 += 1) {	// L518
                  for (int v285 = 0; v285 < 3; v285 += 1) {	// L519
                    int8_t v286 = v268[v269][(v282 + v283)][v284][v285];	// L520
                    int8_t v287 = v256[(v282 + v283)][v284][v285];	// L521
                    int8_t v288 = v286 * v287;	// L522
                    int8_t v289 = v281[(v282 + v283)];	// L523
                    int8_t v290 = v289 + v288;	// L524
                    v281[(v282 + v283)] = v290;	// L525
                  }
                }
                int8_t v291 = v281[(v282 + v283)];	// L528
                v266[v269][(v282 + v283)][(v270 - 2)][(v271 - 2)] = v291;	// L529
              }
            }
          }
        }
      }
    }
  }
  for (int v292 = 0; v292 < 1; v292 += 1) {	// L537
    for (int v293 = 0; v293 < 2; v293 += 1) {	// L538
      for (int v294 = 0; v294 < 2; v294 += 1) {	// L539
        for (int v295 = 0; v295 < 512; v295 += 1) {	// L540
          int8_t v296 = v266[0][v295][v293][v294];	// L541
          bool v297 = v296 > (int8_t)0.000000;	// L542
          int8_t v298 = v297 ? v296 : (int8_t)0.000000;	// L543
          v257[v292][v295][v293][v294] = v298;	// L544
        }
      }
    }
  }
  return ;	// L549
}

void main_graph_node11(
  int8_t v299[512][512][1][1],
  int8_t v300[1][512][2][2],
  int8_t v301[1][512][2][2]
) {	// L551
  #pragma HLS dataflow

  int8_t v302[1][512][2][2];	// L553
  #pragma HLS stream variable=v302 depth=10 type=fifo

  #pragma HLS bind_storage variable=v302 type=ram_t2p impl=bram

  int8_t v303[1][512][1][2];	// L554
  #pragma HLS bind_storage variable=v303 type=ram_2p impl=bram

  int8_t v304[1][512][1][1];	// L555
  #pragma HLS array_partition variable=v304 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v304 type=ram_2p impl=lutram

  for (int v305 = 0; v305 < 1; v305 += 1) {	// L556
    for (int v306 = 0; v306 < 2; v306 += 1) {	// L557
      for (int v307 = 0; v307 < 2; v307 += 1) {	// L558
        for (int v308 = 0; v308 < 512; v308 += 1) {	// L559
          int8_t v309 = v300[v305][v308][v306][v307];	// L560
          v303[v305][v308][0][v307] = v309;	// L561
        }
        if (v306 >= 0) {	// L563
          for (int v310 = 0; v310 < 512; v310 += 1) {	// L564
            for (int v311 = 0; v311 < 1; v311 += 1) {	// L565
              int8_t v312 = v303[v305][v310][v311][v307];	// L566
              v304[v305][v310][v311][0] = v312;	// L567
            }
          }
          if (v307 >= 0) {	// L570
            int8_t v313[512];	// L571
            #pragma HLS bind_storage variable=v313 type=ram_2p impl=bram

            for (int v314 = 0; v314 < 512; v314 += 1) {	// L572
              v313[v314] = (int8_t)0.000000;	// L573
              for (int v315 = 0; v315 < 32; v315 += 1) {	// L574
                #pragma HLS pipeline II=1
                for (int v316 = 0; v316 < 16; v316 += 1) {	// L575
                  for (int v317 = 0; v317 < 1; v317 += 1) {	// L576
                    for (int v318 = 0; v318 < 1; v318 += 1) {	// L577
                      int8_t v319 = v304[v305][(v316 + (v315 * 16))][v317][v318];	// L578
                      int8_t v320 = v299[v314][(v316 + (v315 * 16))][v317][v318];	// L579
                      int8_t v321 = v319 * v320;	// L580
                      int8_t v322 = v313[v314];	// L581
                      int8_t v323 = v322 + v321;	// L582
                      v313[v314] = v323;	// L583
                    }
                  }
                }
              }
              int8_t v324 = v313[v314];	// L588
              v302[v305][v314][v306][v307] = v324;	// L589
            }
          }
        }
      }
    }
  }
  for (int v325 = 0; v325 < 1; v325 += 1) {	// L596
    for (int v326 = 0; v326 < 2; v326 += 1) {	// L597
      for (int v327 = 0; v327 < 2; v327 += 1) {	// L598
        for (int v328 = 0; v328 < 512; v328 += 1) {	// L599
          int8_t v329 = v302[0][v328][v326][v327];	// L600
          bool v330 = v329 > (int8_t)0.000000;	// L601
          int8_t v331 = v330 ? v329 : (int8_t)0.000000;	// L602
          v301[v325][v328][v326][v327] = v331;	// L603
        }
      }
    }
  }
  return ;	// L608
}

void main_graph_node12(
  int8_t v332[1][512][2][2],
  int8_t v333[512][3][3],
  int8_t v334[1][512][2][2]
) {	// L610
  #pragma HLS dataflow

  int8_t v335[1][512][4][4];	// L612
  #pragma HLS stream variable=v335 depth=10 type=fifo

  #pragma HLS bind_storage variable=v335 type=ram_t2p impl=bram

  for (int v336 = 0; v336 < 1; v336 += 1) {	// L613
    for (int v337 = 0; v337 < 4; v337 += 1) {	// L614
      for (int v338 = 0; v338 < 4; v338 += 1) {	// L615
        for (int v339 = 0; v339 < 512; v339 += 1) {	// L616
          int8_t v340;	// L617
          v340 = (int8_t)0.000000;	// L618
          if (((-v337) + 1) >= 0 && ((-v338) + 1) >= 0) {	// L619
            int8_t v341 = v332[v336][v339][v337][v338];	// L620
            v340 = v341;	// L621
          }
          int8_t v342 = v340;	// L623
          v335[v336][v339][v337][v338] = v342;	// L624
        }
      }
    }
  }
  int8_t v343[1][512][2][2];	// L629
  #pragma HLS stream variable=v343 depth=10 type=fifo

  #pragma HLS bind_storage variable=v343 type=ram_t2p impl=bram

  int8_t v344[1][512][3][4];	// L630
  #pragma HLS array_partition variable=v344 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v344 type=ram_2p impl=bram

  int8_t v345[1][512][3][3];	// L631
  #pragma HLS array_partition variable=v345 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v345 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v345 type=ram_2p impl=lutram

  for (int v346 = 0; v346 < 1; v346 += 1) {	// L632
    for (int v347 = 0; v347 < 4; v347 += 1) {	// L633
      for (int v348 = 0; v348 < 4; v348 += 1) {	// L634
        for (int v349 = 0; v349 < 512; v349 += 1) {	// L635
          int8_t v350 = v344[v346][v349][1][v348];	// L636
          v344[v346][v349][0][v348] = v350;	// L637
          int8_t v351 = v344[v346][v349][2][v348];	// L638
          v344[v346][v349][1][v348] = v351;	// L639
          int8_t v352 = v335[v346][v349][v347][v348];	// L640
          v344[v346][v349][2][v348] = v352;	// L641
        }
        if ((v347 - 2) >= 0) {	// L643
          for (int v353 = 0; v353 < 512; v353 += 1) {	// L644
            for (int v354 = 0; v354 < 3; v354 += 1) {	// L645
              int8_t v355 = v345[v346][v353][v354][1];	// L646
              v345[v346][v353][v354][0] = v355;	// L647
              int8_t v356 = v345[v346][v353][v354][2];	// L648
              v345[v346][v353][v354][1] = v356;	// L649
              int8_t v357 = v344[v346][v353][v354][v348];	// L650
              v345[v346][v353][v354][2] = v357;	// L651
            }
          }
          if ((v348 - 2) >= 0) {	// L654
            int8_t v358[512];	// L655
            #pragma HLS bind_storage variable=v358 type=ram_2p impl=bram

            for (int v359 = 0; v359 < 512; v359 += 1) {	// L656
              #pragma HLS pipeline II=1
              for (int v360 = 0; v360 < 1; v360 += 1) {	// L657
                v358[(v359 + v360)] = (int8_t)0.000000;	// L658
                for (int v361 = 0; v361 < 3; v361 += 1) {	// L659
                  for (int v362 = 0; v362 < 3; v362 += 1) {	// L660
                    int8_t v363 = v345[v346][(v359 + v360)][v361][v362];	// L661
                    int8_t v364 = v333[(v359 + v360)][v361][v362];	// L662
                    int8_t v365 = v363 * v364;	// L663
                    int8_t v366 = v358[(v359 + v360)];	// L664
                    int8_t v367 = v366 + v365;	// L665
                    v358[(v359 + v360)] = v367;	// L666
                  }
                }
                int8_t v368 = v358[(v359 + v360)];	// L669
                v343[v346][(v359 + v360)][(v347 - 2)][(v348 - 2)] = v368;	// L670
              }
            }
          }
        }
      }
    }
  }
  for (int v369 = 0; v369 < 1; v369 += 1) {	// L678
    for (int v370 = 0; v370 < 2; v370 += 1) {	// L679
      for (int v371 = 0; v371 < 2; v371 += 1) {	// L680
        for (int v372 = 0; v372 < 512; v372 += 1) {	// L681
          int8_t v373 = v343[0][v372][v370][v371];	// L682
          bool v374 = v373 > (int8_t)0.000000;	// L683
          int8_t v375 = v374 ? v373 : (int8_t)0.000000;	// L684
          v334[v369][v372][v370][v371] = v375;	// L685
        }
      }
    }
  }
  return ;	// L690
}

void main_graph_node13(
  int8_t v376[1][512][2][2],
  int8_t v377[512][512][1][1],
  int8_t v378[1][512][2][2]
) {	// L692
  #pragma HLS dataflow

  int8_t v379[1][512][2][2];	// L694
  #pragma HLS stream variable=v379 depth=10 type=fifo

  #pragma HLS bind_storage variable=v379 type=ram_t2p impl=bram

  int8_t v380[1][512][1][2];	// L695
  #pragma HLS bind_storage variable=v380 type=ram_2p impl=bram

  int8_t v381[1][512][1][1];	// L696
  #pragma HLS array_partition variable=v381 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v381 type=ram_2p impl=lutram

  for (int v382 = 0; v382 < 1; v382 += 1) {	// L697
    for (int v383 = 0; v383 < 2; v383 += 1) {	// L698
      for (int v384 = 0; v384 < 2; v384 += 1) {	// L699
        for (int v385 = 0; v385 < 512; v385 += 1) {	// L700
          int8_t v386 = v376[v382][v385][v383][v384];	// L701
          v380[v382][v385][0][v384] = v386;	// L702
        }
        if (v383 >= 0) {	// L704
          for (int v387 = 0; v387 < 512; v387 += 1) {	// L705
            for (int v388 = 0; v388 < 1; v388 += 1) {	// L706
              int8_t v389 = v380[v382][v387][v388][v384];	// L707
              v381[v382][v387][v388][0] = v389;	// L708
            }
          }
          if (v384 >= 0) {	// L711
            int8_t v390[512];	// L712
            #pragma HLS bind_storage variable=v390 type=ram_2p impl=bram

            for (int v391 = 0; v391 < 512; v391 += 1) {	// L713
              v390[v391] = (int8_t)0.000000;	// L714
              for (int v392 = 0; v392 < 32; v392 += 1) {	// L715
                #pragma HLS pipeline II=1
                for (int v393 = 0; v393 < 16; v393 += 1) {	// L716
                  for (int v394 = 0; v394 < 1; v394 += 1) {	// L717
                    for (int v395 = 0; v395 < 1; v395 += 1) {	// L718
                      int8_t v396 = v381[v382][(v393 + (v392 * 16))][v394][v395];	// L719
                      int8_t v397 = v377[v391][(v393 + (v392 * 16))][v394][v395];	// L720
                      int8_t v398 = v396 * v397;	// L721
                      int8_t v399 = v390[v391];	// L722
                      int8_t v400 = v399 + v398;	// L723
                      v390[v391] = v400;	// L724
                    }
                  }
                }
              }
              int8_t v401 = v390[v391];	// L729
              v379[v382][v391][v383][v384] = v401;	// L730
            }
          }
        }
      }
    }
  }
  for (int v402 = 0; v402 < 1; v402 += 1) {	// L737
    for (int v403 = 0; v403 < 2; v403 += 1) {	// L738
      for (int v404 = 0; v404 < 2; v404 += 1) {	// L739
        for (int v405 = 0; v405 < 512; v405 += 1) {	// L740
          int8_t v406 = v379[0][v405][v403][v404];	// L741
          bool v407 = v406 > (int8_t)0.000000;	// L742
          int8_t v408 = v407 ? v406 : (int8_t)0.000000;	// L743
          v378[v402][v405][v403][v404] = v408;	// L744
        }
      }
    }
  }
  return ;	// L749
}

void main_graph_node14(
  int8_t v409[512][3][3],
  int8_t v410[1][512][2][2],
  int8_t v411[1][512][2][2]
) {	// L751
  #pragma HLS dataflow

  int8_t v412[1][512][4][4];	// L753
  #pragma HLS stream variable=v412 depth=10 type=fifo

  #pragma HLS bind_storage variable=v412 type=ram_t2p impl=bram

  for (int v413 = 0; v413 < 1; v413 += 1) {	// L754
    for (int v414 = 0; v414 < 4; v414 += 1) {	// L755
      for (int v415 = 0; v415 < 4; v415 += 1) {	// L756
        for (int v416 = 0; v416 < 512; v416 += 1) {	// L757
          int8_t v417;	// L758
          v417 = (int8_t)0.000000;	// L759
          if (((-v414) + 1) >= 0 && ((-v415) + 1) >= 0) {	// L760
            int8_t v418 = v410[v413][v416][v414][v415];	// L761
            v417 = v418;	// L762
          }
          int8_t v419 = v417;	// L764
          v412[v413][v416][v414][v415] = v419;	// L765
        }
      }
    }
  }
  int8_t v420[1][512][2][2];	// L770
  #pragma HLS stream variable=v420 depth=10 type=fifo

  #pragma HLS bind_storage variable=v420 type=ram_t2p impl=bram

  int8_t v421[1][512][3][4];	// L771
  #pragma HLS array_partition variable=v421 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v421 type=ram_2p impl=bram

  int8_t v422[1][512][3][3];	// L772
  #pragma HLS array_partition variable=v422 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v422 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v422 type=ram_2p impl=lutram

  for (int v423 = 0; v423 < 1; v423 += 1) {	// L773
    for (int v424 = 0; v424 < 4; v424 += 1) {	// L774
      for (int v425 = 0; v425 < 4; v425 += 1) {	// L775
        for (int v426 = 0; v426 < 512; v426 += 1) {	// L776
          int8_t v427 = v421[v423][v426][1][v425];	// L777
          v421[v423][v426][0][v425] = v427;	// L778
          int8_t v428 = v421[v423][v426][2][v425];	// L779
          v421[v423][v426][1][v425] = v428;	// L780
          int8_t v429 = v412[v423][v426][v424][v425];	// L781
          v421[v423][v426][2][v425] = v429;	// L782
        }
        if ((v424 - 2) >= 0) {	// L784
          for (int v430 = 0; v430 < 512; v430 += 1) {	// L785
            for (int v431 = 0; v431 < 3; v431 += 1) {	// L786
              int8_t v432 = v422[v423][v430][v431][1];	// L787
              v422[v423][v430][v431][0] = v432;	// L788
              int8_t v433 = v422[v423][v430][v431][2];	// L789
              v422[v423][v430][v431][1] = v433;	// L790
              int8_t v434 = v421[v423][v430][v431][v425];	// L791
              v422[v423][v430][v431][2] = v434;	// L792
            }
          }
          if ((v425 - 2) >= 0) {	// L795
            int8_t v435[512];	// L796
            #pragma HLS bind_storage variable=v435 type=ram_2p impl=bram

            for (int v436 = 0; v436 < 512; v436 += 1) {	// L797
              #pragma HLS pipeline II=1
              for (int v437 = 0; v437 < 1; v437 += 1) {	// L798
                v435[(v436 + v437)] = (int8_t)0.000000;	// L799
                for (int v438 = 0; v438 < 3; v438 += 1) {	// L800
                  for (int v439 = 0; v439 < 3; v439 += 1) {	// L801
                    int8_t v440 = v422[v423][(v436 + v437)][v438][v439];	// L802
                    int8_t v441 = v409[(v436 + v437)][v438][v439];	// L803
                    int8_t v442 = v440 * v441;	// L804
                    int8_t v443 = v435[(v436 + v437)];	// L805
                    int8_t v444 = v443 + v442;	// L806
                    v435[(v436 + v437)] = v444;	// L807
                  }
                }
                int8_t v445 = v435[(v436 + v437)];	// L810
                v420[v423][(v436 + v437)][(v424 - 2)][(v425 - 2)] = v445;	// L811
              }
            }
          }
        }
      }
    }
  }
  for (int v446 = 0; v446 < 1; v446 += 1) {	// L819
    for (int v447 = 0; v447 < 2; v447 += 1) {	// L820
      for (int v448 = 0; v448 < 2; v448 += 1) {	// L821
        for (int v449 = 0; v449 < 512; v449 += 1) {	// L822
          int8_t v450 = v420[0][v449][v447][v448];	// L823
          bool v451 = v450 > (int8_t)0.000000;	// L824
          int8_t v452 = v451 ? v450 : (int8_t)0.000000;	// L825
          v411[v446][v449][v447][v448] = v452;	// L826
        }
      }
    }
  }
  return ;	// L831
}

void main_graph_node15(
  int8_t v453[512][512][1][1],
  int8_t v454[1][512][2][2],
  int8_t v455[1][512][2][2]
) {	// L833
  #pragma HLS dataflow

  int8_t v456[1][512][2][2];	// L835
  #pragma HLS stream variable=v456 depth=10 type=fifo

  #pragma HLS bind_storage variable=v456 type=ram_t2p impl=bram

  int8_t v457[1][512][1][2];	// L836
  #pragma HLS bind_storage variable=v457 type=ram_2p impl=bram

  int8_t v458[1][512][1][1];	// L837
  #pragma HLS array_partition variable=v458 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v458 type=ram_2p impl=lutram

  for (int v459 = 0; v459 < 1; v459 += 1) {	// L838
    for (int v460 = 0; v460 < 2; v460 += 1) {	// L839
      for (int v461 = 0; v461 < 2; v461 += 1) {	// L840
        for (int v462 = 0; v462 < 512; v462 += 1) {	// L841
          int8_t v463 = v454[v459][v462][v460][v461];	// L842
          v457[v459][v462][0][v461] = v463;	// L843
        }
        if (v460 >= 0) {	// L845
          for (int v464 = 0; v464 < 512; v464 += 1) {	// L846
            for (int v465 = 0; v465 < 1; v465 += 1) {	// L847
              int8_t v466 = v457[v459][v464][v465][v461];	// L848
              v458[v459][v464][v465][0] = v466;	// L849
            }
          }
          if (v461 >= 0) {	// L852
            int8_t v467[512];	// L853
            #pragma HLS bind_storage variable=v467 type=ram_2p impl=bram

            for (int v468 = 0; v468 < 512; v468 += 1) {	// L854
              v467[v468] = (int8_t)0.000000;	// L855
              for (int v469 = 0; v469 < 32; v469 += 1) {	// L856
                #pragma HLS pipeline II=1
                for (int v470 = 0; v470 < 16; v470 += 1) {	// L857
                  for (int v471 = 0; v471 < 1; v471 += 1) {	// L858
                    for (int v472 = 0; v472 < 1; v472 += 1) {	// L859
                      int8_t v473 = v458[v459][(v470 + (v469 * 16))][v471][v472];	// L860
                      int8_t v474 = v453[v468][(v470 + (v469 * 16))][v471][v472];	// L861
                      int8_t v475 = v473 * v474;	// L862
                      int8_t v476 = v467[v468];	// L863
                      int8_t v477 = v476 + v475;	// L864
                      v467[v468] = v477;	// L865
                    }
                  }
                }
              }
              int8_t v478 = v467[v468];	// L870
              v456[v459][v468][v460][v461] = v478;	// L871
            }
          }
        }
      }
    }
  }
  for (int v479 = 0; v479 < 1; v479 += 1) {	// L878
    for (int v480 = 0; v480 < 2; v480 += 1) {	// L879
      for (int v481 = 0; v481 < 2; v481 += 1) {	// L880
        for (int v482 = 0; v482 < 512; v482 += 1) {	// L881
          int8_t v483 = v456[0][v482][v480][v481];	// L882
          bool v484 = v483 > (int8_t)0.000000;	// L883
          int8_t v485 = v484 ? v483 : (int8_t)0.000000;	// L884
          v455[v479][v482][v480][v481] = v485;	// L885
        }
      }
    }
  }
  return ;	// L890
}

void main_graph_node16(
  int8_t v486[1][512][2][2],
  int8_t v487[512][3][3],
  int8_t v488[1][512][2][2]
) {	// L892
  #pragma HLS dataflow

  int8_t v489[1][512][4][4];	// L894
  #pragma HLS stream variable=v489 depth=10 type=fifo

  #pragma HLS bind_storage variable=v489 type=ram_t2p impl=bram

  for (int v490 = 0; v490 < 1; v490 += 1) {	// L895
    for (int v491 = 0; v491 < 4; v491 += 1) {	// L896
      for (int v492 = 0; v492 < 4; v492 += 1) {	// L897
        for (int v493 = 0; v493 < 512; v493 += 1) {	// L898
          int8_t v494;	// L899
          v494 = (int8_t)0.000000;	// L900
          if (((-v491) + 1) >= 0 && ((-v492) + 1) >= 0) {	// L901
            int8_t v495 = v486[v490][v493][v491][v492];	// L902
            v494 = v495;	// L903
          }
          int8_t v496 = v494;	// L905
          v489[v490][v493][v491][v492] = v496;	// L906
        }
      }
    }
  }
  int8_t v497[1][512][2][2];	// L911
  #pragma HLS stream variable=v497 depth=10 type=fifo

  #pragma HLS bind_storage variable=v497 type=ram_t2p impl=bram

  int8_t v498[1][512][3][4];	// L912
  #pragma HLS array_partition variable=v498 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v498 type=ram_2p impl=bram

  int8_t v499[1][512][3][3];	// L913
  #pragma HLS array_partition variable=v499 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v499 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v499 type=ram_2p impl=lutram

  for (int v500 = 0; v500 < 1; v500 += 1) {	// L914
    for (int v501 = 0; v501 < 4; v501 += 1) {	// L915
      for (int v502 = 0; v502 < 4; v502 += 1) {	// L916
        for (int v503 = 0; v503 < 512; v503 += 1) {	// L917
          int8_t v504 = v498[v500][v503][1][v502];	// L918
          v498[v500][v503][0][v502] = v504;	// L919
          int8_t v505 = v498[v500][v503][2][v502];	// L920
          v498[v500][v503][1][v502] = v505;	// L921
          int8_t v506 = v489[v500][v503][v501][v502];	// L922
          v498[v500][v503][2][v502] = v506;	// L923
        }
        if ((v501 - 2) >= 0) {	// L925
          for (int v507 = 0; v507 < 512; v507 += 1) {	// L926
            for (int v508 = 0; v508 < 3; v508 += 1) {	// L927
              int8_t v509 = v499[v500][v507][v508][1];	// L928
              v499[v500][v507][v508][0] = v509;	// L929
              int8_t v510 = v499[v500][v507][v508][2];	// L930
              v499[v500][v507][v508][1] = v510;	// L931
              int8_t v511 = v498[v500][v507][v508][v502];	// L932
              v499[v500][v507][v508][2] = v511;	// L933
            }
          }
          if ((v502 - 2) >= 0) {	// L936
            int8_t v512[512];	// L937
            #pragma HLS bind_storage variable=v512 type=ram_2p impl=bram

            for (int v513 = 0; v513 < 512; v513 += 1) {	// L938
              #pragma HLS pipeline II=1
              for (int v514 = 0; v514 < 1; v514 += 1) {	// L939
                v512[(v513 + v514)] = (int8_t)0.000000;	// L940
                for (int v515 = 0; v515 < 3; v515 += 1) {	// L941
                  for (int v516 = 0; v516 < 3; v516 += 1) {	// L942
                    int8_t v517 = v499[v500][(v513 + v514)][v515][v516];	// L943
                    int8_t v518 = v487[(v513 + v514)][v515][v516];	// L944
                    int8_t v519 = v517 * v518;	// L945
                    int8_t v520 = v512[(v513 + v514)];	// L946
                    int8_t v521 = v520 + v519;	// L947
                    v512[(v513 + v514)] = v521;	// L948
                  }
                }
                int8_t v522 = v512[(v513 + v514)];	// L951
                v497[v500][(v513 + v514)][(v501 - 2)][(v502 - 2)] = v522;	// L952
              }
            }
          }
        }
      }
    }
  }
  for (int v523 = 0; v523 < 1; v523 += 1) {	// L960
    for (int v524 = 0; v524 < 2; v524 += 1) {	// L961
      for (int v525 = 0; v525 < 2; v525 += 1) {	// L962
        for (int v526 = 0; v526 < 512; v526 += 1) {	// L963
          int8_t v527 = v497[0][v526][v524][v525];	// L964
          bool v528 = v527 > (int8_t)0.000000;	// L965
          int8_t v529 = v528 ? v527 : (int8_t)0.000000;	// L966
          v488[v523][v526][v524][v525] = v529;	// L967
        }
      }
    }
  }
  return ;	// L972
}

void main_graph_node17(
  int8_t v530[1][512][2][2],
  int8_t v531[512][512][1][1],
  int8_t v532[1][512][2][2]
) {	// L974
  #pragma HLS dataflow

  int8_t v533[1][512][2][2];	// L976
  #pragma HLS stream variable=v533 depth=10 type=fifo

  #pragma HLS bind_storage variable=v533 type=ram_t2p impl=bram

  int8_t v534[1][512][1][2];	// L977
  #pragma HLS bind_storage variable=v534 type=ram_2p impl=bram

  int8_t v535[1][512][1][1];	// L978
  #pragma HLS array_partition variable=v535 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v535 type=ram_2p impl=lutram

  for (int v536 = 0; v536 < 1; v536 += 1) {	// L979
    for (int v537 = 0; v537 < 2; v537 += 1) {	// L980
      for (int v538 = 0; v538 < 2; v538 += 1) {	// L981
        for (int v539 = 0; v539 < 512; v539 += 1) {	// L982
          int8_t v540 = v530[v536][v539][v537][v538];	// L983
          v534[v536][v539][0][v538] = v540;	// L984
        }
        if (v537 >= 0) {	// L986
          for (int v541 = 0; v541 < 512; v541 += 1) {	// L987
            for (int v542 = 0; v542 < 1; v542 += 1) {	// L988
              int8_t v543 = v534[v536][v541][v542][v538];	// L989
              v535[v536][v541][v542][0] = v543;	// L990
            }
          }
          if (v538 >= 0) {	// L993
            int8_t v544[512];	// L994
            #pragma HLS bind_storage variable=v544 type=ram_2p impl=bram

            for (int v545 = 0; v545 < 512; v545 += 1) {	// L995
              v544[v545] = (int8_t)0.000000;	// L996
              for (int v546 = 0; v546 < 32; v546 += 1) {	// L997
                #pragma HLS pipeline II=1
                for (int v547 = 0; v547 < 16; v547 += 1) {	// L998
                  for (int v548 = 0; v548 < 1; v548 += 1) {	// L999
                    for (int v549 = 0; v549 < 1; v549 += 1) {	// L1000
                      int8_t v550 = v535[v536][(v547 + (v546 * 16))][v548][v549];	// L1001
                      int8_t v551 = v531[v545][(v547 + (v546 * 16))][v548][v549];	// L1002
                      int8_t v552 = v550 * v551;	// L1003
                      int8_t v553 = v544[v545];	// L1004
                      int8_t v554 = v553 + v552;	// L1005
                      v544[v545] = v554;	// L1006
                    }
                  }
                }
              }
              int8_t v555 = v544[v545];	// L1011
              v533[v536][v545][v537][v538] = v555;	// L1012
            }
          }
        }
      }
    }
  }
  for (int v556 = 0; v556 < 1; v556 += 1) {	// L1019
    for (int v557 = 0; v557 < 2; v557 += 1) {	// L1020
      for (int v558 = 0; v558 < 2; v558 += 1) {	// L1021
        for (int v559 = 0; v559 < 512; v559 += 1) {	// L1022
          int8_t v560 = v533[0][v559][v557][v558];	// L1023
          bool v561 = v560 > (int8_t)0.000000;	// L1024
          int8_t v562 = v561 ? v560 : (int8_t)0.000000;	// L1025
          v532[v556][v559][v557][v558] = v562;	// L1026
        }
      }
    }
  }
  return ;	// L1031
}

void main_graph_node18(
  int8_t v563[512][3][3],
  int8_t v564[1][512][2][2],
  int8_t v565[1][512][2][2]
) {	// L1033
  #pragma HLS dataflow

  int8_t v566[1][512][4][4];	// L1035
  #pragma HLS stream variable=v566 depth=10 type=fifo

  #pragma HLS bind_storage variable=v566 type=ram_t2p impl=bram

  for (int v567 = 0; v567 < 1; v567 += 1) {	// L1036
    for (int v568 = 0; v568 < 4; v568 += 1) {	// L1037
      for (int v569 = 0; v569 < 4; v569 += 1) {	// L1038
        for (int v570 = 0; v570 < 512; v570 += 1) {	// L1039
          int8_t v571;	// L1040
          v571 = (int8_t)0.000000;	// L1041
          if (((-v568) + 1) >= 0 && ((-v569) + 1) >= 0) {	// L1042
            int8_t v572 = v564[v567][v570][v568][v569];	// L1043
            v571 = v572;	// L1044
          }
          int8_t v573 = v571;	// L1046
          v566[v567][v570][v568][v569] = v573;	// L1047
        }
      }
    }
  }
  int8_t v574[1][512][2][2];	// L1052
  #pragma HLS stream variable=v574 depth=10 type=fifo

  #pragma HLS bind_storage variable=v574 type=ram_t2p impl=bram

  int8_t v575[1][512][3][4];	// L1053
  #pragma HLS array_partition variable=v575 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v575 type=ram_2p impl=bram

  int8_t v576[1][512][3][3];	// L1054
  #pragma HLS array_partition variable=v576 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v576 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v576 type=ram_2p impl=lutram

  for (int v577 = 0; v577 < 1; v577 += 1) {	// L1055
    for (int v578 = 0; v578 < 4; v578 += 1) {	// L1056
      for (int v579 = 0; v579 < 4; v579 += 1) {	// L1057
        for (int v580 = 0; v580 < 512; v580 += 1) {	// L1058
          int8_t v581 = v575[v577][v580][1][v579];	// L1059
          v575[v577][v580][0][v579] = v581;	// L1060
          int8_t v582 = v575[v577][v580][2][v579];	// L1061
          v575[v577][v580][1][v579] = v582;	// L1062
          int8_t v583 = v566[v577][v580][v578][v579];	// L1063
          v575[v577][v580][2][v579] = v583;	// L1064
        }
        if ((v578 - 2) >= 0) {	// L1066
          for (int v584 = 0; v584 < 512; v584 += 1) {	// L1067
            for (int v585 = 0; v585 < 3; v585 += 1) {	// L1068
              int8_t v586 = v576[v577][v584][v585][1];	// L1069
              v576[v577][v584][v585][0] = v586;	// L1070
              int8_t v587 = v576[v577][v584][v585][2];	// L1071
              v576[v577][v584][v585][1] = v587;	// L1072
              int8_t v588 = v575[v577][v584][v585][v579];	// L1073
              v576[v577][v584][v585][2] = v588;	// L1074
            }
          }
          if ((v579 - 2) >= 0) {	// L1077
            int8_t v589[512];	// L1078
            #pragma HLS bind_storage variable=v589 type=ram_2p impl=bram

            for (int v590 = 0; v590 < 512; v590 += 1) {	// L1079
              #pragma HLS pipeline II=1
              for (int v591 = 0; v591 < 1; v591 += 1) {	// L1080
                v589[(v590 + v591)] = (int8_t)0.000000;	// L1081
                for (int v592 = 0; v592 < 3; v592 += 1) {	// L1082
                  for (int v593 = 0; v593 < 3; v593 += 1) {	// L1083
                    int8_t v594 = v576[v577][(v590 + v591)][v592][v593];	// L1084
                    int8_t v595 = v563[(v590 + v591)][v592][v593];	// L1085
                    int8_t v596 = v594 * v595;	// L1086
                    int8_t v597 = v589[(v590 + v591)];	// L1087
                    int8_t v598 = v597 + v596;	// L1088
                    v589[(v590 + v591)] = v598;	// L1089
                  }
                }
                int8_t v599 = v589[(v590 + v591)];	// L1092
                v574[v577][(v590 + v591)][(v578 - 2)][(v579 - 2)] = v599;	// L1093
              }
            }
          }
        }
      }
    }
  }
  for (int v600 = 0; v600 < 1; v600 += 1) {	// L1101
    for (int v601 = 0; v601 < 2; v601 += 1) {	// L1102
      for (int v602 = 0; v602 < 2; v602 += 1) {	// L1103
        for (int v603 = 0; v603 < 512; v603 += 1) {	// L1104
          int8_t v604 = v574[0][v603][v601][v602];	// L1105
          bool v605 = v604 > (int8_t)0.000000;	// L1106
          int8_t v606 = v605 ? v604 : (int8_t)0.000000;	// L1107
          v565[v600][v603][v601][v602] = v606;	// L1108
        }
      }
    }
  }
  return ;	// L1113
}

void main_graph_node19(
  int8_t v607[512][256][1][1],
  int8_t v608[1][256][2][2],
  int8_t v609[1][512][2][2]
) {	// L1115
  #pragma HLS dataflow

  int8_t v610[1][512][2][2];	// L1117
  #pragma HLS stream variable=v610 depth=10 type=fifo

  #pragma HLS bind_storage variable=v610 type=ram_t2p impl=bram

  int8_t v611[1][256][1][2];	// L1118
  #pragma HLS bind_storage variable=v611 type=ram_2p impl=bram

  int8_t v612[1][256][1][1];	// L1119
  #pragma HLS array_partition variable=v612 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v612 type=ram_2p impl=lutram

  for (int v613 = 0; v613 < 1; v613 += 1) {	// L1120
    for (int v614 = 0; v614 < 2; v614 += 1) {	// L1121
      for (int v615 = 0; v615 < 2; v615 += 1) {	// L1122
        for (int v616 = 0; v616 < 256; v616 += 1) {	// L1123
          int8_t v617 = v608[v613][v616][v614][v615];	// L1124
          v611[v613][v616][0][v615] = v617;	// L1125
        }
        if (v614 >= 0) {	// L1127
          for (int v618 = 0; v618 < 256; v618 += 1) {	// L1128
            for (int v619 = 0; v619 < 1; v619 += 1) {	// L1129
              int8_t v620 = v611[v613][v618][v619][v615];	// L1130
              v612[v613][v618][v619][0] = v620;	// L1131
            }
          }
          if (v615 >= 0) {	// L1134
            int8_t v621[512];	// L1135
            #pragma HLS bind_storage variable=v621 type=ram_2p impl=bram

            for (int v622 = 0; v622 < 512; v622 += 1) {	// L1136
              v621[v622] = (int8_t)0.000000;	// L1137
              for (int v623 = 0; v623 < 32; v623 += 1) {	// L1138
                #pragma HLS pipeline II=1
                for (int v624 = 0; v624 < 8; v624 += 1) {	// L1139
                  for (int v625 = 0; v625 < 1; v625 += 1) {	// L1140
                    for (int v626 = 0; v626 < 1; v626 += 1) {	// L1141
                      int8_t v627 = v612[v613][(v624 + (v623 * 8))][v625][v626];	// L1142
                      int8_t v628 = v607[v622][(v624 + (v623 * 8))][v625][v626];	// L1143
                      int8_t v629 = v627 * v628;	// L1144
                      int8_t v630 = v621[v622];	// L1145
                      int8_t v631 = v630 + v629;	// L1146
                      v621[v622] = v631;	// L1147
                    }
                  }
                }
              }
              int8_t v632 = v621[v622];	// L1152
              v610[v613][v622][v614][v615] = v632;	// L1153
            }
          }
        }
      }
    }
  }
  for (int v633 = 0; v633 < 1; v633 += 1) {	// L1160
    for (int v634 = 0; v634 < 2; v634 += 1) {	// L1161
      for (int v635 = 0; v635 < 2; v635 += 1) {	// L1162
        for (int v636 = 0; v636 < 512; v636 += 1) {	// L1163
          int8_t v637 = v610[0][v636][v634][v635];	// L1164
          bool v638 = v637 > (int8_t)0.000000;	// L1165
          int8_t v639 = v638 ? v637 : (int8_t)0.000000;	// L1166
          v609[v633][v636][v634][v635] = v639;	// L1167
        }
      }
    }
  }
  return ;	// L1172
}

void main_graph_node20(
  int8_t v640[256][3][3],
  int8_t v641[1][256][4][4],
  int8_t v642[1][256][2][2]
) {	// L1174
  #pragma HLS dataflow

  int8_t v643[1][256][6][6];	// L1176
  #pragma HLS stream variable=v643 depth=10 type=fifo

  #pragma HLS bind_storage variable=v643 type=ram_t2p impl=bram

  for (int v644 = 0; v644 < 1; v644 += 1) {	// L1177
    for (int v645 = 0; v645 < 6; v645 += 1) {	// L1178
      for (int v646 = 0; v646 < 6; v646 += 1) {	// L1179
        for (int v647 = 0; v647 < 256; v647 += 1) {	// L1180
          int8_t v648;	// L1181
          v648 = (int8_t)0.000000;	// L1182
          if (((-v645) + 3) >= 0 && ((-v646) + 3) >= 0) {	// L1183
            int8_t v649 = v641[v644][v647][v645][v646];	// L1184
            v648 = v649;	// L1185
          }
          int8_t v650 = v648;	// L1187
          v643[v644][v647][v645][v646] = v650;	// L1188
        }
      }
    }
  }
  int8_t v651[1][256][2][2];	// L1193
  #pragma HLS stream variable=v651 depth=10 type=fifo

  #pragma HLS bind_storage variable=v651 type=ram_t2p impl=bram

  int8_t v652[1][256][3][6];	// L1194
  #pragma HLS array_partition variable=v652 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v652 type=ram_2p impl=bram

  int8_t v653[1][256][3][3];	// L1195
  #pragma HLS array_partition variable=v653 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v653 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v653 type=ram_2p impl=lutram

  for (int v654 = 0; v654 < 1; v654 += 1) {	// L1196
    for (int v655 = 0; v655 < 6; v655 += 1) {	// L1197
      for (int v656 = 0; v656 < 6; v656 += 1) {	// L1198
        for (int v657 = 0; v657 < 256; v657 += 1) {	// L1199
          int8_t v658 = v652[v654][v657][1][v656];	// L1200
          v652[v654][v657][0][v656] = v658;	// L1201
          int8_t v659 = v652[v654][v657][2][v656];	// L1202
          v652[v654][v657][1][v656] = v659;	// L1203
          int8_t v660 = v643[v654][v657][v655][v656];	// L1204
          v652[v654][v657][2][v656] = v660;	// L1205
        }
        if ((v655 - 4) >= 0) {	// L1207
          for (int v661 = 0; v661 < 256; v661 += 1) {	// L1208
            for (int v662 = 0; v662 < 3; v662 += 1) {	// L1209
              int8_t v663 = v653[v654][v661][v662][1];	// L1210
              v653[v654][v661][v662][0] = v663;	// L1211
              int8_t v664 = v653[v654][v661][v662][2];	// L1212
              v653[v654][v661][v662][1] = v664;	// L1213
              int8_t v665 = v652[v654][v661][v662][v656];	// L1214
              v653[v654][v661][v662][2] = v665;	// L1215
            }
          }
          if ((v656 - 4) >= 0) {	// L1218
            int8_t v666[256];	// L1219
            #pragma HLS bind_storage variable=v666 type=ram_2p impl=bram

            for (int v667 = 0; v667 < 256; v667 += 1) {	// L1220
              #pragma HLS pipeline II=1
              for (int v668 = 0; v668 < 1; v668 += 1) {	// L1221
                v666[(v667 + v668)] = (int8_t)0.000000;	// L1222
                for (int v669 = 0; v669 < 3; v669 += 1) {	// L1223
                  for (int v670 = 0; v670 < 3; v670 += 1) {	// L1224
                    int8_t v671 = v653[v654][(v667 + v668)][v669][v670];	// L1225
                    int8_t v672 = v640[(v667 + v668)][v669][v670];	// L1226
                    int8_t v673 = v671 * v672;	// L1227
                    int8_t v674 = v666[(v667 + v668)];	// L1228
                    int8_t v675 = v674 + v673;	// L1229
                    v666[(v667 + v668)] = v675;	// L1230
                  }
                }
                int8_t v676 = v666[(v667 + v668)];	// L1233
                v651[v654][(v667 + v668)][(v655 - 4)][(v656 - 4)] = v676;	// L1234
              }
            }
          }
        }
      }
    }
  }
  for (int v677 = 0; v677 < 1; v677 += 1) {	// L1242
    for (int v678 = 0; v678 < 2; v678 += 1) {	// L1243
      for (int v679 = 0; v679 < 2; v679 += 1) {	// L1244
        for (int v680 = 0; v680 < 256; v680 += 1) {	// L1245
          int8_t v681 = v651[0][v680][v678][v679];	// L1246
          bool v682 = v681 > (int8_t)0.000000;	// L1247
          int8_t v683 = v682 ? v681 : (int8_t)0.000000;	// L1248
          v642[v677][v680][v678][v679] = v683;	// L1249
        }
      }
    }
  }
  return ;	// L1254
}

void main_graph_node21(
  int8_t v684[256][256][1][1],
  int8_t v685[1][256][4][4],
  int8_t v686[1][256][4][4]
) {	// L1256
  #pragma HLS dataflow

  int8_t v687[1][256][4][4];	// L1258
  #pragma HLS stream variable=v687 depth=10 type=fifo

  #pragma HLS bind_storage variable=v687 type=ram_t2p impl=bram

  int8_t v688[1][256][1][4];	// L1259
  #pragma HLS bind_storage variable=v688 type=ram_2p impl=bram

  int8_t v689[1][256][1][1];	// L1260
  #pragma HLS array_partition variable=v689 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v689 type=ram_2p impl=lutram

  for (int v690 = 0; v690 < 1; v690 += 1) {	// L1261
    for (int v691 = 0; v691 < 4; v691 += 1) {	// L1262
      for (int v692 = 0; v692 < 4; v692 += 1) {	// L1263
        for (int v693 = 0; v693 < 256; v693 += 1) {	// L1264
          int8_t v694 = v685[v690][v693][v691][v692];	// L1265
          v688[v690][v693][0][v692] = v694;	// L1266
        }
        if (v691 >= 0) {	// L1268
          for (int v695 = 0; v695 < 256; v695 += 1) {	// L1269
            for (int v696 = 0; v696 < 1; v696 += 1) {	// L1270
              int8_t v697 = v688[v690][v695][v696][v692];	// L1271
              v689[v690][v695][v696][0] = v697;	// L1272
            }
          }
          if (v692 >= 0) {	// L1275
            int8_t v698[256];	// L1276
            #pragma HLS bind_storage variable=v698 type=ram_2p impl=bram

            for (int v699 = 0; v699 < 256; v699 += 1) {	// L1277
              v698[v699] = (int8_t)0.000000;	// L1278
              for (int v700 = 0; v700 < 16; v700 += 1) {	// L1279
                #pragma HLS pipeline II=1
                for (int v701 = 0; v701 < 16; v701 += 1) {	// L1280
                  for (int v702 = 0; v702 < 1; v702 += 1) {	// L1281
                    for (int v703 = 0; v703 < 1; v703 += 1) {	// L1282
                      int8_t v704 = v689[v690][(v701 + (v700 * 16))][v702][v703];	// L1283
                      int8_t v705 = v684[v699][(v701 + (v700 * 16))][v702][v703];	// L1284
                      int8_t v706 = v704 * v705;	// L1285
                      int8_t v707 = v698[v699];	// L1286
                      int8_t v708 = v707 + v706;	// L1287
                      v698[v699] = v708;	// L1288
                    }
                  }
                }
              }
              int8_t v709 = v698[v699];	// L1293
              v687[v690][v699][v691][v692] = v709;	// L1294
            }
          }
        }
      }
    }
  }
  for (int v710 = 0; v710 < 1; v710 += 1) {	// L1301
    for (int v711 = 0; v711 < 4; v711 += 1) {	// L1302
      for (int v712 = 0; v712 < 4; v712 += 1) {	// L1303
        for (int v713 = 0; v713 < 256; v713 += 1) {	// L1304
          int8_t v714 = v687[0][v713][v711][v712];	// L1305
          bool v715 = v714 > (int8_t)0.000000;	// L1306
          int8_t v716 = v715 ? v714 : (int8_t)0.000000;	// L1307
          v686[v710][v713][v711][v712] = v716;	// L1308
        }
      }
    }
  }
  return ;	// L1313
}

void main_graph_node22(
  int8_t v717[1][256][4][4],
  int8_t v718[256][3][3],
  int8_t v719[1][256][4][4]
) {	// L1315
  #pragma HLS dataflow

  int8_t v720[1][256][6][6];	// L1317
  #pragma HLS stream variable=v720 depth=10 type=fifo

  #pragma HLS bind_storage variable=v720 type=ram_t2p impl=bram

  for (int v721 = 0; v721 < 1; v721 += 1) {	// L1318
    for (int v722 = 0; v722 < 6; v722 += 1) {	// L1319
      for (int v723 = 0; v723 < 6; v723 += 1) {	// L1320
        for (int v724 = 0; v724 < 256; v724 += 1) {	// L1321
          int8_t v725;	// L1322
          v725 = (int8_t)0.000000;	// L1323
          if (((-v722) + 3) >= 0 && ((-v723) + 3) >= 0) {	// L1324
            int8_t v726 = v717[v721][v724][v722][v723];	// L1325
            v725 = v726;	// L1326
          }
          int8_t v727 = v725;	// L1328
          v720[v721][v724][v722][v723] = v727;	// L1329
        }
      }
    }
  }
  int8_t v728[1][256][4][4];	// L1334
  #pragma HLS stream variable=v728 depth=10 type=fifo

  #pragma HLS bind_storage variable=v728 type=ram_t2p impl=bram

  int8_t v729[1][256][3][6];	// L1335
  #pragma HLS array_partition variable=v729 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v729 type=ram_2p impl=bram

  int8_t v730[1][256][3][3];	// L1336
  #pragma HLS array_partition variable=v730 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v730 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v730 type=ram_2p impl=lutram

  for (int v731 = 0; v731 < 1; v731 += 1) {	// L1337
    for (int v732 = 0; v732 < 6; v732 += 1) {	// L1338
      for (int v733 = 0; v733 < 6; v733 += 1) {	// L1339
        for (int v734 = 0; v734 < 256; v734 += 1) {	// L1340
          int8_t v735 = v729[v731][v734][1][v733];	// L1341
          v729[v731][v734][0][v733] = v735;	// L1342
          int8_t v736 = v729[v731][v734][2][v733];	// L1343
          v729[v731][v734][1][v733] = v736;	// L1344
          int8_t v737 = v720[v731][v734][v732][v733];	// L1345
          v729[v731][v734][2][v733] = v737;	// L1346
        }
        if ((v732 - 2) >= 0) {	// L1348
          for (int v738 = 0; v738 < 256; v738 += 1) {	// L1349
            for (int v739 = 0; v739 < 3; v739 += 1) {	// L1350
              int8_t v740 = v730[v731][v738][v739][1];	// L1351
              v730[v731][v738][v739][0] = v740;	// L1352
              int8_t v741 = v730[v731][v738][v739][2];	// L1353
              v730[v731][v738][v739][1] = v741;	// L1354
              int8_t v742 = v729[v731][v738][v739][v733];	// L1355
              v730[v731][v738][v739][2] = v742;	// L1356
            }
          }
          if ((v733 - 2) >= 0) {	// L1359
            int8_t v743[256];	// L1360
            #pragma HLS bind_storage variable=v743 type=ram_2p impl=bram

            for (int v744 = 0; v744 < 256; v744 += 1) {	// L1361
              #pragma HLS pipeline II=1
              for (int v745 = 0; v745 < 1; v745 += 1) {	// L1362
                v743[(v744 + v745)] = (int8_t)0.000000;	// L1363
                for (int v746 = 0; v746 < 3; v746 += 1) {	// L1364
                  for (int v747 = 0; v747 < 3; v747 += 1) {	// L1365
                    int8_t v748 = v730[v731][(v744 + v745)][v746][v747];	// L1366
                    int8_t v749 = v718[(v744 + v745)][v746][v747];	// L1367
                    int8_t v750 = v748 * v749;	// L1368
                    int8_t v751 = v743[(v744 + v745)];	// L1369
                    int8_t v752 = v751 + v750;	// L1370
                    v743[(v744 + v745)] = v752;	// L1371
                  }
                }
                int8_t v753 = v743[(v744 + v745)];	// L1374
                v728[v731][(v744 + v745)][(v732 - 2)][(v733 - 2)] = v753;	// L1375
              }
            }
          }
        }
      }
    }
  }
  for (int v754 = 0; v754 < 1; v754 += 1) {	// L1383
    for (int v755 = 0; v755 < 4; v755 += 1) {	// L1384
      for (int v756 = 0; v756 < 4; v756 += 1) {	// L1385
        for (int v757 = 0; v757 < 256; v757 += 1) {	// L1386
          int8_t v758 = v728[0][v757][v755][v756];	// L1387
          bool v759 = v758 > (int8_t)0.000000;	// L1388
          int8_t v760 = v759 ? v758 : (int8_t)0.000000;	// L1389
          v719[v754][v757][v755][v756] = v760;	// L1390
        }
      }
    }
  }
  return ;	// L1395
}

void main_graph_node23(
  int8_t v761[256][128][1][1],
  int8_t v762[1][128][4][4],
  int8_t v763[1][256][4][4]
) {	// L1397
  #pragma HLS dataflow

  int8_t v764[1][256][4][4];	// L1399
  #pragma HLS stream variable=v764 depth=10 type=fifo

  #pragma HLS bind_storage variable=v764 type=ram_t2p impl=bram

  int8_t v765[1][128][1][4];	// L1400
  #pragma HLS bind_storage variable=v765 type=ram_2p impl=bram

  int8_t v766[1][128][1][1];	// L1401
  #pragma HLS array_partition variable=v766 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v766 type=ram_2p impl=lutram

  for (int v767 = 0; v767 < 1; v767 += 1) {	// L1402
    for (int v768 = 0; v768 < 4; v768 += 1) {	// L1403
      for (int v769 = 0; v769 < 4; v769 += 1) {	// L1404
        for (int v770 = 0; v770 < 128; v770 += 1) {	// L1405
          int8_t v771 = v762[v767][v770][v768][v769];	// L1406
          v765[v767][v770][0][v769] = v771;	// L1407
        }
        if (v768 >= 0) {	// L1409
          for (int v772 = 0; v772 < 128; v772 += 1) {	// L1410
            for (int v773 = 0; v773 < 1; v773 += 1) {	// L1411
              int8_t v774 = v765[v767][v772][v773][v769];	// L1412
              v766[v767][v772][v773][0] = v774;	// L1413
            }
          }
          if (v769 >= 0) {	// L1416
            int8_t v775[256];	// L1417
            #pragma HLS bind_storage variable=v775 type=ram_2p impl=bram

            for (int v776 = 0; v776 < 256; v776 += 1) {	// L1418
              v775[v776] = (int8_t)0.000000;	// L1419
              for (int v777 = 0; v777 < 16; v777 += 1) {	// L1420
                #pragma HLS pipeline II=1
                for (int v778 = 0; v778 < 8; v778 += 1) {	// L1421
                  for (int v779 = 0; v779 < 1; v779 += 1) {	// L1422
                    for (int v780 = 0; v780 < 1; v780 += 1) {	// L1423
                      int8_t v781 = v766[v767][(v778 + (v777 * 8))][v779][v780];	// L1424
                      int8_t v782 = v761[v776][(v778 + (v777 * 8))][v779][v780];	// L1425
                      int8_t v783 = v781 * v782;	// L1426
                      int8_t v784 = v775[v776];	// L1427
                      int8_t v785 = v784 + v783;	// L1428
                      v775[v776] = v785;	// L1429
                    }
                  }
                }
              }
              int8_t v786 = v775[v776];	// L1434
              v764[v767][v776][v768][v769] = v786;	// L1435
            }
          }
        }
      }
    }
  }
  for (int v787 = 0; v787 < 1; v787 += 1) {	// L1442
    for (int v788 = 0; v788 < 4; v788 += 1) {	// L1443
      for (int v789 = 0; v789 < 4; v789 += 1) {	// L1444
        for (int v790 = 0; v790 < 256; v790 += 1) {	// L1445
          int8_t v791 = v764[0][v790][v788][v789];	// L1446
          bool v792 = v791 > (int8_t)0.000000;	// L1447
          int8_t v793 = v792 ? v791 : (int8_t)0.000000;	// L1448
          v763[v787][v790][v788][v789] = v793;	// L1449
        }
      }
    }
  }
  return ;	// L1454
}

void main_graph_node24(
  int8_t v794[128][3][3],
  int8_t v795[1][128][8][8],
  int8_t v796[1][128][4][4]
) {	// L1456
  #pragma HLS dataflow

  int8_t v797[1][128][10][10];	// L1458
  #pragma HLS stream variable=v797 depth=10 type=fifo

  #pragma HLS bind_storage variable=v797 type=ram_t2p impl=bram

  for (int v798 = 0; v798 < 1; v798 += 1) {	// L1459
    for (int v799 = 0; v799 < 10; v799 += 1) {	// L1460
      for (int v800 = 0; v800 < 10; v800 += 1) {	// L1461
        for (int v801 = 0; v801 < 128; v801 += 1) {	// L1462
          int8_t v802;	// L1463
          v802 = (int8_t)0.000000;	// L1464
          if (((-v799) + 7) >= 0 && ((-v800) + 7) >= 0) {	// L1465
            int8_t v803 = v795[v798][v801][v799][v800];	// L1466
            v802 = v803;	// L1467
          }
          int8_t v804 = v802;	// L1469
          v797[v798][v801][v799][v800] = v804;	// L1470
        }
      }
    }
  }
  int8_t v805[1][128][4][4];	// L1475
  #pragma HLS stream variable=v805 depth=10 type=fifo

  #pragma HLS bind_storage variable=v805 type=ram_t2p impl=bram

  int8_t v806[1][128][3][10];	// L1476
  #pragma HLS array_partition variable=v806 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v806 type=ram_2p impl=bram

  int8_t v807[1][128][3][3];	// L1477
  #pragma HLS array_partition variable=v807 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v807 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v807 type=ram_2p impl=lutram

  for (int v808 = 0; v808 < 1; v808 += 1) {	// L1478
    for (int v809 = 0; v809 < 10; v809 += 1) {	// L1479
      for (int v810 = 0; v810 < 10; v810 += 1) {	// L1480
        for (int v811 = 0; v811 < 128; v811 += 1) {	// L1481
          int8_t v812 = v806[v808][v811][1][v810];	// L1482
          v806[v808][v811][0][v810] = v812;	// L1483
          int8_t v813 = v806[v808][v811][2][v810];	// L1484
          v806[v808][v811][1][v810] = v813;	// L1485
          int8_t v814 = v797[v808][v811][v809][v810];	// L1486
          v806[v808][v811][2][v810] = v814;	// L1487
        }
        if ((v809 - 6) >= 0) {	// L1489
          for (int v815 = 0; v815 < 128; v815 += 1) {	// L1490
            for (int v816 = 0; v816 < 3; v816 += 1) {	// L1491
              int8_t v817 = v807[v808][v815][v816][1];	// L1492
              v807[v808][v815][v816][0] = v817;	// L1493
              int8_t v818 = v807[v808][v815][v816][2];	// L1494
              v807[v808][v815][v816][1] = v818;	// L1495
              int8_t v819 = v806[v808][v815][v816][v810];	// L1496
              v807[v808][v815][v816][2] = v819;	// L1497
            }
          }
          if ((v810 - 6) >= 0) {	// L1500
            int8_t v820[128];	// L1501
            #pragma HLS bind_storage variable=v820 type=ram_2p impl=bram

            for (int v821 = 0; v821 < 128; v821 += 1) {	// L1502
              #pragma HLS pipeline II=1
              for (int v822 = 0; v822 < 1; v822 += 1) {	// L1503
                v820[(v821 + v822)] = (int8_t)0.000000;	// L1504
                for (int v823 = 0; v823 < 3; v823 += 1) {	// L1505
                  for (int v824 = 0; v824 < 3; v824 += 1) {	// L1506
                    int8_t v825 = v807[v808][(v821 + v822)][v823][v824];	// L1507
                    int8_t v826 = v794[(v821 + v822)][v823][v824];	// L1508
                    int8_t v827 = v825 * v826;	// L1509
                    int8_t v828 = v820[(v821 + v822)];	// L1510
                    int8_t v829 = v828 + v827;	// L1511
                    v820[(v821 + v822)] = v829;	// L1512
                  }
                }
                int8_t v830 = v820[(v821 + v822)];	// L1515
                v805[v808][(v821 + v822)][(v809 - 6)][(v810 - 6)] = v830;	// L1516
              }
            }
          }
        }
      }
    }
  }
  for (int v831 = 0; v831 < 1; v831 += 1) {	// L1524
    for (int v832 = 0; v832 < 4; v832 += 1) {	// L1525
      for (int v833 = 0; v833 < 4; v833 += 1) {	// L1526
        for (int v834 = 0; v834 < 128; v834 += 1) {	// L1527
          int8_t v835 = v805[0][v834][v832][v833];	// L1528
          bool v836 = v835 > (int8_t)0.000000;	// L1529
          int8_t v837 = v836 ? v835 : (int8_t)0.000000;	// L1530
          v796[v831][v834][v832][v833] = v837;	// L1531
        }
      }
    }
  }
  return ;	// L1536
}

void main_graph_node25(
  int8_t v838[128][128][1][1],
  int8_t v839[1][128][8][8],
  int8_t v840[1][128][8][8]
) {	// L1538
  #pragma HLS dataflow

  int8_t v841[1][128][8][8];	// L1540
  #pragma HLS stream variable=v841 depth=10 type=fifo

  #pragma HLS bind_storage variable=v841 type=ram_t2p impl=bram

  int8_t v842[1][128][1][8];	// L1541
  #pragma HLS bind_storage variable=v842 type=ram_2p impl=bram

  int8_t v843[1][128][1][1];	// L1542
  #pragma HLS array_partition variable=v843 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v843 type=ram_2p impl=lutram

  for (int v844 = 0; v844 < 1; v844 += 1) {	// L1543
    for (int v845 = 0; v845 < 8; v845 += 1) {	// L1544
      for (int v846 = 0; v846 < 8; v846 += 1) {	// L1545
        for (int v847 = 0; v847 < 128; v847 += 1) {	// L1546
          int8_t v848 = v839[v844][v847][v845][v846];	// L1547
          v842[v844][v847][0][v846] = v848;	// L1548
        }
        if (v845 >= 0) {	// L1550
          for (int v849 = 0; v849 < 128; v849 += 1) {	// L1551
            for (int v850 = 0; v850 < 1; v850 += 1) {	// L1552
              int8_t v851 = v842[v844][v849][v850][v846];	// L1553
              v843[v844][v849][v850][0] = v851;	// L1554
            }
          }
          if (v846 >= 0) {	// L1557
            int8_t v852[128];	// L1558
            #pragma HLS bind_storage variable=v852 type=ram_2p impl=bram

            for (int v853 = 0; v853 < 128; v853 += 1) {	// L1559
              v852[v853] = (int8_t)0.000000;	// L1560
              for (int v854 = 0; v854 < 8; v854 += 1) {	// L1561
                #pragma HLS pipeline II=1
                for (int v855 = 0; v855 < 16; v855 += 1) {	// L1562
                  for (int v856 = 0; v856 < 1; v856 += 1) {	// L1563
                    for (int v857 = 0; v857 < 1; v857 += 1) {	// L1564
                      int8_t v858 = v843[v844][(v855 + (v854 * 16))][v856][v857];	// L1565
                      int8_t v859 = v838[v853][(v855 + (v854 * 16))][v856][v857];	// L1566
                      int8_t v860 = v858 * v859;	// L1567
                      int8_t v861 = v852[v853];	// L1568
                      int8_t v862 = v861 + v860;	// L1569
                      v852[v853] = v862;	// L1570
                    }
                  }
                }
              }
              int8_t v863 = v852[v853];	// L1575
              v841[v844][v853][v845][v846] = v863;	// L1576
            }
          }
        }
      }
    }
  }
  for (int v864 = 0; v864 < 1; v864 += 1) {	// L1583
    for (int v865 = 0; v865 < 8; v865 += 1) {	// L1584
      for (int v866 = 0; v866 < 8; v866 += 1) {	// L1585
        for (int v867 = 0; v867 < 128; v867 += 1) {	// L1586
          int8_t v868 = v841[0][v867][v865][v866];	// L1587
          bool v869 = v868 > (int8_t)0.000000;	// L1588
          int8_t v870 = v869 ? v868 : (int8_t)0.000000;	// L1589
          v840[v864][v867][v865][v866] = v870;	// L1590
        }
      }
    }
  }
  return ;	// L1595
}

void main_graph_node26(
  int8_t v871[128][3][3],
  int8_t v872[1][128][8][8],
  int8_t v873[1][128][8][8]
) {	// L1597
  #pragma HLS dataflow

  int8_t v874[1][128][10][10];	// L1599
  #pragma HLS stream variable=v874 depth=10 type=fifo

  #pragma HLS bind_storage variable=v874 type=ram_t2p impl=bram

  for (int v875 = 0; v875 < 1; v875 += 1) {	// L1600
    for (int v876 = 0; v876 < 10; v876 += 1) {	// L1601
      for (int v877 = 0; v877 < 10; v877 += 1) {	// L1602
        for (int v878 = 0; v878 < 128; v878 += 1) {	// L1603
          int8_t v879;	// L1604
          v879 = (int8_t)0.000000;	// L1605
          if (((-v876) + 7) >= 0 && ((-v877) + 7) >= 0) {	// L1606
            int8_t v880 = v872[v875][v878][v876][v877];	// L1607
            v879 = v880;	// L1608
          }
          int8_t v881 = v879;	// L1610
          v874[v875][v878][v876][v877] = v881;	// L1611
        }
      }
    }
  }
  int8_t v882[1][128][8][8];	// L1616
  #pragma HLS stream variable=v882 depth=10 type=fifo

  #pragma HLS bind_storage variable=v882 type=ram_t2p impl=bram

  int8_t v883[1][128][3][10];	// L1617
  #pragma HLS array_partition variable=v883 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v883 type=ram_2p impl=bram

  int8_t v884[1][128][3][3];	// L1618
  #pragma HLS array_partition variable=v884 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v884 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v884 type=ram_2p impl=lutram

  for (int v885 = 0; v885 < 1; v885 += 1) {	// L1619
    for (int v886 = 0; v886 < 10; v886 += 1) {	// L1620
      for (int v887 = 0; v887 < 10; v887 += 1) {	// L1621
        for (int v888 = 0; v888 < 128; v888 += 1) {	// L1622
          int8_t v889 = v883[v885][v888][1][v887];	// L1623
          v883[v885][v888][0][v887] = v889;	// L1624
          int8_t v890 = v883[v885][v888][2][v887];	// L1625
          v883[v885][v888][1][v887] = v890;	// L1626
          int8_t v891 = v874[v885][v888][v886][v887];	// L1627
          v883[v885][v888][2][v887] = v891;	// L1628
        }
        if ((v886 - 2) >= 0) {	// L1630
          for (int v892 = 0; v892 < 128; v892 += 1) {	// L1631
            for (int v893 = 0; v893 < 3; v893 += 1) {	// L1632
              int8_t v894 = v884[v885][v892][v893][1];	// L1633
              v884[v885][v892][v893][0] = v894;	// L1634
              int8_t v895 = v884[v885][v892][v893][2];	// L1635
              v884[v885][v892][v893][1] = v895;	// L1636
              int8_t v896 = v883[v885][v892][v893][v887];	// L1637
              v884[v885][v892][v893][2] = v896;	// L1638
            }
          }
          if ((v887 - 2) >= 0) {	// L1641
            int8_t v897[128];	// L1642
            #pragma HLS bind_storage variable=v897 type=ram_2p impl=bram

            for (int v898 = 0; v898 < 128; v898 += 1) {	// L1643
              #pragma HLS pipeline II=1
              for (int v899 = 0; v899 < 1; v899 += 1) {	// L1644
                v897[(v898 + v899)] = (int8_t)0.000000;	// L1645
                for (int v900 = 0; v900 < 3; v900 += 1) {	// L1646
                  for (int v901 = 0; v901 < 3; v901 += 1) {	// L1647
                    int8_t v902 = v884[v885][(v898 + v899)][v900][v901];	// L1648
                    int8_t v903 = v871[(v898 + v899)][v900][v901];	// L1649
                    int8_t v904 = v902 * v903;	// L1650
                    int8_t v905 = v897[(v898 + v899)];	// L1651
                    int8_t v906 = v905 + v904;	// L1652
                    v897[(v898 + v899)] = v906;	// L1653
                  }
                }
                int8_t v907 = v897[(v898 + v899)];	// L1656
                v882[v885][(v898 + v899)][(v886 - 2)][(v887 - 2)] = v907;	// L1657
              }
            }
          }
        }
      }
    }
  }
  for (int v908 = 0; v908 < 1; v908 += 1) {	// L1665
    for (int v909 = 0; v909 < 8; v909 += 1) {	// L1666
      for (int v910 = 0; v910 < 8; v910 += 1) {	// L1667
        for (int v911 = 0; v911 < 128; v911 += 1) {	// L1668
          int8_t v912 = v882[0][v911][v909][v910];	// L1669
          bool v913 = v912 > (int8_t)0.000000;	// L1670
          int8_t v914 = v913 ? v912 : (int8_t)0.000000;	// L1671
          v873[v908][v911][v909][v910] = v914;	// L1672
        }
      }
    }
  }
  return ;	// L1677
}

void main_graph_node27(
  int8_t v915[128][64][1][1],
  int8_t v916[1][64][8][8],
  int8_t v917[1][128][8][8]
) {	// L1679
  #pragma HLS dataflow

  int8_t v918[1][128][8][8];	// L1681
  #pragma HLS stream variable=v918 depth=10 type=fifo

  #pragma HLS bind_storage variable=v918 type=ram_t2p impl=bram

  int8_t v919[1][64][1][8];	// L1682
  #pragma HLS array_partition variable=v919 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v919 type=ram_2p impl=lutram

  int8_t v920[1][64][1][1];	// L1683
  #pragma HLS array_partition variable=v920 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v920 type=ram_2p impl=lutram

  for (int v921 = 0; v921 < 1; v921 += 1) {	// L1684
    for (int v922 = 0; v922 < 8; v922 += 1) {	// L1685
      for (int v923 = 0; v923 < 8; v923 += 1) {	// L1686
        for (int v924 = 0; v924 < 8; v924 += 1) {	// L1687
          #pragma HLS pipeline II=1
          for (int v925 = 0; v925 < 8; v925 += 1) {	// L1688
            int8_t v926 = v916[v921][(v925 + (v924 * 8))][v922][v923];	// L1689
            v919[v921][(v925 + (v924 * 8))][0][v923] = v926;	// L1690
          }
        }
        if (v922 >= 0) {	// L1693
          for (int v927 = 0; v927 < 8; v927 += 1) {	// L1694
            #pragma HLS pipeline II=1
            for (int v928 = 0; v928 < 8; v928 += 1) {	// L1695
              for (int v929 = 0; v929 < 1; v929 += 1) {	// L1696
                int8_t v930 = v919[v921][(v928 + (v927 * 8))][v929][v923];	// L1697
                v920[v921][(v928 + (v927 * 8))][v929][0] = v930;	// L1698
              }
            }
          }
          if (v923 >= 0) {	// L1702
            int8_t v931[128];	// L1703
            #pragma HLS bind_storage variable=v931 type=ram_2p impl=bram

            for (int v932 = 0; v932 < 128; v932 += 1) {	// L1704
              v931[v932] = (int8_t)0.000000;	// L1705
              for (int v933 = 0; v933 < 8; v933 += 1) {	// L1706
                #pragma HLS pipeline II=1
                for (int v934 = 0; v934 < 8; v934 += 1) {	// L1707
                  for (int v935 = 0; v935 < 1; v935 += 1) {	// L1708
                    for (int v936 = 0; v936 < 1; v936 += 1) {	// L1709
                      int8_t v937 = v920[v921][(v934 + (v933 * 8))][v935][v936];	// L1710
                      int8_t v938 = v915[v932][(v934 + (v933 * 8))][v935][v936];	// L1711
                      int8_t v939 = v937 * v938;	// L1712
                      int8_t v940 = v931[v932];	// L1713
                      int8_t v941 = v940 + v939;	// L1714
                      v931[v932] = v941;	// L1715
                    }
                  }
                }
              }
              int8_t v942 = v931[v932];	// L1720
              v918[v921][v932][v922][v923] = v942;	// L1721
            }
          }
        }
      }
    }
  }
  for (int v943 = 0; v943 < 1; v943 += 1) {	// L1728
    for (int v944 = 0; v944 < 8; v944 += 1) {	// L1729
      for (int v945 = 0; v945 < 8; v945 += 1) {	// L1730
        for (int v946 = 0; v946 < 128; v946 += 1) {	// L1731
          int8_t v947 = v918[0][v946][v944][v945];	// L1732
          bool v948 = v947 > (int8_t)0.000000;	// L1733
          int8_t v949 = v948 ? v947 : (int8_t)0.000000;	// L1734
          v917[v943][v946][v944][v945] = v949;	// L1735
        }
      }
    }
  }
  return ;	// L1740
}

void main_graph_node28(
  int8_t v950[1][64][16][16],
  int8_t v951[64][3][3],
  int8_t v952[1][64][8][8]
) {	// L1742
  #pragma HLS dataflow

  int8_t v953[1][64][18][18];	// L1744
  #pragma HLS stream variable=v953 depth=10 type=fifo

  #pragma HLS bind_storage variable=v953 type=ram_t2p impl=bram

  for (int v954 = 0; v954 < 1; v954 += 1) {	// L1745
    for (int v955 = 0; v955 < 18; v955 += 1) {	// L1746
      for (int v956 = 0; v956 < 18; v956 += 1) {	// L1747
        for (int v957 = 0; v957 < 64; v957 += 1) {	// L1748
          int8_t v958;	// L1749
          v958 = (int8_t)0.000000;	// L1750
          if (((-v955) + 15) >= 0 && ((-v956) + 15) >= 0) {	// L1751
            int8_t v959 = v950[v954][v957][v955][v956];	// L1752
            v958 = v959;	// L1753
          }
          int8_t v960 = v958;	// L1755
          v953[v954][v957][v955][v956] = v960;	// L1756
        }
      }
    }
  }
  int8_t v961[1][64][8][8];	// L1761
  #pragma HLS stream variable=v961 depth=10 type=fifo

  #pragma HLS array_partition variable=v961 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v961 type=ram_2p impl=lutram

  int8_t v962[1][64][3][18];	// L1762
  #pragma HLS array_partition variable=v962 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v962 type=ram_2p impl=bram

  int8_t v963[1][64][3][3];	// L1763
  #pragma HLS array_partition variable=v963 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v963 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v963 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v963 type=ram_2p impl=lutram

  for (int v964 = 0; v964 < 1; v964 += 1) {	// L1764
    for (int v965 = 0; v965 < 18; v965 += 1) {	// L1765
      for (int v966 = 0; v966 < 18; v966 += 1) {	// L1766
        for (int v967 = 0; v967 < 64; v967 += 1) {	// L1767
          int8_t v968 = v962[v964][v967][1][v966];	// L1768
          v962[v964][v967][0][v966] = v968;	// L1769
          int8_t v969 = v962[v964][v967][2][v966];	// L1770
          v962[v964][v967][1][v966] = v969;	// L1771
          int8_t v970 = v953[v964][v967][v965][v966];	// L1772
          v962[v964][v967][2][v966] = v970;	// L1773
        }
        if ((v965 - 10) >= 0) {	// L1775
          for (int v971 = 0; v971 < 64; v971 += 1) {	// L1776
            for (int v972 = 0; v972 < 3; v972 += 1) {	// L1777
              int8_t v973 = v963[v964][v971][v972][1];	// L1778
              v963[v964][v971][v972][0] = v973;	// L1779
              int8_t v974 = v963[v964][v971][v972][2];	// L1780
              v963[v964][v971][v972][1] = v974;	// L1781
              int8_t v975 = v962[v964][v971][v972][v966];	// L1782
              v963[v964][v971][v972][2] = v975;	// L1783
            }
          }
          if ((v966 - 10) >= 0) {	// L1786
            int8_t v976[64];	// L1787
            #pragma HLS array_partition variable=v976 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v976 type=ram_2p impl=lutram

            for (int v977 = 0; v977 < 8; v977 += 1) {	// L1788
              #pragma HLS pipeline II=1
              for (int v978 = 0; v978 < 8; v978 += 1) {	// L1789
                v976[(v978 + (v977 * 8))] = (int8_t)0.000000;	// L1790
                for (int v979 = 0; v979 < 3; v979 += 1) {	// L1791
                  for (int v980 = 0; v980 < 3; v980 += 1) {	// L1792
                    int8_t v981 = v963[v964][(v978 + (v977 * 8))][v979][v980];	// L1793
                    int8_t v982 = v951[(v978 + (v977 * 8))][v979][v980];	// L1794
                    int8_t v983 = v981 * v982;	// L1795
                    int8_t v984 = v976[(v978 + (v977 * 8))];	// L1796
                    int8_t v985 = v984 + v983;	// L1797
                    v976[(v978 + (v977 * 8))] = v985;	// L1798
                  }
                }
                int8_t v986 = v976[(v978 + (v977 * 8))];	// L1801
                v961[v964][(v978 + (v977 * 8))][(v965 - 10)][(v966 - 10)] = v986;	// L1802
              }
            }
          }
        }
      }
    }
  }
  for (int v987 = 0; v987 < 1; v987 += 1) {	// L1810
    for (int v988 = 0; v988 < 8; v988 += 1) {	// L1811
      for (int v989 = 0; v989 < 8; v989 += 1) {	// L1812
        for (int v990 = 0; v990 < 8; v990 += 1) {	// L1813
          #pragma HLS pipeline II=1
          for (int v991 = 0; v991 < 8; v991 += 1) {	// L1814
            int8_t v992 = v961[0][(v991 + (v990 * 8))][v988][v989];	// L1815
            bool v993 = v992 > (int8_t)0.000000;	// L1816
            int8_t v994 = v993 ? v992 : (int8_t)0.000000;	// L1817
            v952[v987][(v991 + (v990 * 8))][v988][v989] = v994;	// L1818
          }
        }
      }
    }
  }
  return ;	// L1824
}

void main_graph_node29(
  int8_t v995[64][32][1][1],
  int8_t v996[1][32][16][16],
  int8_t v997[1][64][16][16]
) {	// L1826
  #pragma HLS dataflow

  int8_t v998[1][64][16][16];	// L1828
  #pragma HLS stream variable=v998 depth=10 type=fifo

  #pragma HLS bind_storage variable=v998 type=ram_t2p impl=bram

  int8_t v999[1][32][1][16];	// L1829
  #pragma HLS bind_storage variable=v999 type=ram_2p impl=bram

  int8_t v1000[1][32][1][1];	// L1830
  #pragma HLS array_partition variable=v1000 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1000 type=ram_2p impl=lutram

  for (int v1001 = 0; v1001 < 1; v1001 += 1) {	// L1831
    for (int v1002 = 0; v1002 < 16; v1002 += 1) {	// L1832
      for (int v1003 = 0; v1003 < 16; v1003 += 1) {	// L1833
        for (int v1004 = 0; v1004 < 32; v1004 += 1) {	// L1834
          int8_t v1005 = v996[v1001][v1004][v1002][v1003];	// L1835
          v999[v1001][v1004][0][v1003] = v1005;	// L1836
        }
        if (v1002 >= 0) {	// L1838
          for (int v1006 = 0; v1006 < 32; v1006 += 1) {	// L1839
            for (int v1007 = 0; v1007 < 1; v1007 += 1) {	// L1840
              int8_t v1008 = v999[v1001][v1006][v1007][v1003];	// L1841
              v1000[v1001][v1006][v1007][0] = v1008;	// L1842
            }
          }
          if (v1003 >= 0) {	// L1845
            int8_t v1009[64];	// L1846
            #pragma HLS bind_storage variable=v1009 type=ram_2p impl=bram

            for (int v1010 = 0; v1010 < 64; v1010 += 1) {	// L1847
              v1009[v1010] = (int8_t)0.000000;	// L1848
              for (int v1011 = 0; v1011 < 2; v1011 += 1) {	// L1849
                #pragma HLS pipeline II=1
                for (int v1012 = 0; v1012 < 16; v1012 += 1) {	// L1850
                  for (int v1013 = 0; v1013 < 1; v1013 += 1) {	// L1851
                    for (int v1014 = 0; v1014 < 1; v1014 += 1) {	// L1852
                      int8_t v1015 = v1000[v1001][(v1012 + (v1011 * 16))][v1013][v1014];	// L1853
                      int8_t v1016 = v995[v1010][(v1012 + (v1011 * 16))][v1013][v1014];	// L1854
                      int8_t v1017 = v1015 * v1016;	// L1855
                      int8_t v1018 = v1009[v1010];	// L1856
                      int8_t v1019 = v1018 + v1017;	// L1857
                      v1009[v1010] = v1019;	// L1858
                    }
                  }
                }
              }
              int8_t v1020 = v1009[v1010];	// L1863
              v998[v1001][v1010][v1002][v1003] = v1020;	// L1864
            }
          }
        }
      }
    }
  }
  for (int v1021 = 0; v1021 < 1; v1021 += 1) {	// L1871
    for (int v1022 = 0; v1022 < 16; v1022 += 1) {	// L1872
      for (int v1023 = 0; v1023 < 16; v1023 += 1) {	// L1873
        for (int v1024 = 0; v1024 < 64; v1024 += 1) {	// L1874
          int8_t v1025 = v998[0][v1024][v1022][v1023];	// L1875
          bool v1026 = v1025 > (int8_t)0.000000;	// L1876
          int8_t v1027 = v1026 ? v1025 : (int8_t)0.000000;	// L1877
          v997[v1021][v1024][v1022][v1023] = v1027;	// L1878
        }
      }
    }
  }
  return ;	// L1883
}

void main_graph_node30(
  int8_t v1028[32][3][3],
  int8_t v1029[1][32][16][16],
  int8_t v1030[1][32][16][16]
) {	// L1885
  #pragma HLS dataflow

  int8_t v1031[1][32][18][18];	// L1887
  #pragma HLS stream variable=v1031 depth=10 type=fifo

  #pragma HLS array_partition variable=v1031 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v1031 type=ram_t2p impl=bram

  for (int v1032 = 0; v1032 < 1; v1032 += 1) {	// L1888
    for (int v1033 = 0; v1033 < 18; v1033 += 1) {	// L1889
      for (int v1034 = 0; v1034 < 18; v1034 += 1) {	// L1890
        for (int v1035 = 0; v1035 < 16; v1035 += 1) {	// L1891
          #pragma HLS pipeline II=1
          for (int v1036 = 0; v1036 < 2; v1036 += 1) {	// L1892
            int8_t v1037;	// L1893
            v1037 = (int8_t)0.000000;	// L1894
            if (((-v1033) + 15) >= 0 && ((-v1034) + 15) >= 0) {	// L1895
              int8_t v1038 = v1029[v1032][(v1036 + (v1035 * 2))][v1033][v1034];	// L1896
              v1037 = v1038;	// L1897
            }
            int8_t v1039 = v1037;	// L1899
            v1031[v1032][(v1036 + (v1035 * 2))][v1033][v1034] = v1039;	// L1900
          }
        }
      }
    }
  }
  int8_t v1040[1][32][16][16];	// L1906
  #pragma HLS stream variable=v1040 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1040 type=ram_t2p impl=bram

  int8_t v1041[1][32][3][18];	// L1907
  #pragma HLS array_partition variable=v1041 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1041 type=ram_2p impl=lutram

  int8_t v1042[1][32][3][3];	// L1908
  #pragma HLS array_partition variable=v1042 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1042 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1042 type=ram_2p impl=lutram

  for (int v1043 = 0; v1043 < 1; v1043 += 1) {	// L1909
    for (int v1044 = 0; v1044 < 18; v1044 += 1) {	// L1910
      for (int v1045 = 0; v1045 < 18; v1045 += 1) {	// L1911
        for (int v1046 = 0; v1046 < 16; v1046 += 1) {	// L1912
          #pragma HLS pipeline II=1
          for (int v1047 = 0; v1047 < 2; v1047 += 1) {	// L1913
            int8_t v1048 = v1041[v1043][(v1047 + (v1046 * 2))][1][v1045];	// L1914
            v1041[v1043][(v1047 + (v1046 * 2))][0][v1045] = v1048;	// L1915
            int8_t v1049 = v1041[v1043][(v1047 + (v1046 * 2))][2][v1045];	// L1916
            v1041[v1043][(v1047 + (v1046 * 2))][1][v1045] = v1049;	// L1917
            int8_t v1050 = v1031[v1043][(v1047 + (v1046 * 2))][v1044][v1045];	// L1918
            v1041[v1043][(v1047 + (v1046 * 2))][2][v1045] = v1050;	// L1919
          }
        }
        if ((v1044 - 2) >= 0) {	// L1922
          for (int v1051 = 0; v1051 < 16; v1051 += 1) {	// L1923
            #pragma HLS pipeline II=1
            for (int v1052 = 0; v1052 < 2; v1052 += 1) {	// L1924
              for (int v1053 = 0; v1053 < 3; v1053 += 1) {	// L1925
                int8_t v1054 = v1042[v1043][(v1052 + (v1051 * 2))][v1053][1];	// L1926
                v1042[v1043][(v1052 + (v1051 * 2))][v1053][0] = v1054;	// L1927
                int8_t v1055 = v1042[v1043][(v1052 + (v1051 * 2))][v1053][2];	// L1928
                v1042[v1043][(v1052 + (v1051 * 2))][v1053][1] = v1055;	// L1929
                int8_t v1056 = v1041[v1043][(v1052 + (v1051 * 2))][v1053][v1045];	// L1930
                v1042[v1043][(v1052 + (v1051 * 2))][v1053][2] = v1056;	// L1931
              }
            }
          }
          if ((v1045 - 2) >= 0) {	// L1935
            int8_t v1057[32];	// L1936
            #pragma HLS bind_storage variable=v1057 type=ram_2p impl=bram

            for (int v1058 = 0; v1058 < 32; v1058 += 1) {	// L1937
              #pragma HLS pipeline II=1
              for (int v1059 = 0; v1059 < 1; v1059 += 1) {	// L1938
                v1057[(v1058 + v1059)] = (int8_t)0.000000;	// L1939
                for (int v1060 = 0; v1060 < 3; v1060 += 1) {	// L1940
                  for (int v1061 = 0; v1061 < 3; v1061 += 1) {	// L1941
                    int8_t v1062 = v1042[v1043][(v1058 + v1059)][v1060][v1061];	// L1942
                    int8_t v1063 = v1028[(v1058 + v1059)][v1060][v1061];	// L1943
                    int8_t v1064 = v1062 * v1063;	// L1944
                    int8_t v1065 = v1057[(v1058 + v1059)];	// L1945
                    int8_t v1066 = v1065 + v1064;	// L1946
                    v1057[(v1058 + v1059)] = v1066;	// L1947
                  }
                }
                int8_t v1067 = v1057[(v1058 + v1059)];	// L1950
                v1040[v1043][(v1058 + v1059)][(v1044 - 2)][(v1045 - 2)] = v1067;	// L1951
              }
            }
          }
        }
      }
    }
  }
  for (int v1068 = 0; v1068 < 1; v1068 += 1) {	// L1959
    for (int v1069 = 0; v1069 < 16; v1069 += 1) {	// L1960
      for (int v1070 = 0; v1070 < 16; v1070 += 1) {	// L1961
        for (int v1071 = 0; v1071 < 32; v1071 += 1) {	// L1962
          int8_t v1072 = v1040[0][v1071][v1069][v1070];	// L1963
          bool v1073 = v1072 > (int8_t)0.000000;	// L1964
          int8_t v1074 = v1073 ? v1072 : (int8_t)0.000000;	// L1965
          v1030[v1068][v1071][v1069][v1070] = v1074;	// L1966
        }
      }
    }
  }
  return ;	// L1971
}

void main_graph_node31(
  int8_t v1075[32][3][3][3],
  int8_t v1076[1][3][32][32],
  int8_t v1077[1][32][16][16]
) {	// L1973
  #pragma HLS dataflow

  int8_t v1078[1][3][34][34];	// L1975
  #pragma HLS stream variable=v1078 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1078 type=ram_t2p impl=bram

  for (int v1079 = 0; v1079 < 1; v1079 += 1) {	// L1976
    for (int v1080 = 0; v1080 < 34; v1080 += 1) {	// L1977
      for (int v1081 = 0; v1081 < 34; v1081 += 1) {	// L1978
        for (int v1082 = 0; v1082 < 3; v1082 += 1) {	// L1979
          int8_t v1083;	// L1980
          v1083 = (int8_t)0.000000;	// L1981
          if (((-v1080) + 31) >= 0 && ((-v1081) + 31) >= 0) {	// L1982
            int8_t v1084 = v1076[v1079][v1082][v1080][v1081];	// L1983
            v1083 = v1084;	// L1984
          }
          int8_t v1085 = v1083;	// L1986
          v1078[v1079][v1082][v1080][v1081] = v1085;	// L1987
        }
      }
    }
  }
  int8_t v1086[1][32][16][16];	// L1992
  #pragma HLS stream variable=v1086 depth=10 type=fifo

  #pragma HLS array_partition variable=v1086 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v1086 type=ram_t2p impl=bram

  int8_t v1087[1][3][3][34];	// L1993
  #pragma HLS array_partition variable=v1087 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1087 type=ram_2p impl=lutram

  int8_t v1088[1][3][3][3];	// L1994
  #pragma HLS array_partition variable=v1088 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1088 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1088 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1088 type=ram_2p impl=lutram

  for (int v1089 = 0; v1089 < 1; v1089 += 1) {	// L1995
    for (int v1090 = 0; v1090 < 34; v1090 += 1) {	// L1996
      for (int v1091 = 0; v1091 < 34; v1091 += 1) {	// L1997
        for (int v1092 = 0; v1092 < 3; v1092 += 1) {	// L1998
          int8_t v1093 = v1087[v1089][v1092][1][v1091];	// L1999
          v1087[v1089][v1092][0][v1091] = v1093;	// L2000
          int8_t v1094 = v1087[v1089][v1092][2][v1091];	// L2001
          v1087[v1089][v1092][1][v1091] = v1094;	// L2002
          int8_t v1095 = v1078[v1089][v1092][v1090][v1091];	// L2003
          v1087[v1089][v1092][2][v1091] = v1095;	// L2004
        }
        if ((v1090 - 18) >= 0) {	// L2006
          for (int v1096 = 0; v1096 < 3; v1096 += 1) {	// L2007
            for (int v1097 = 0; v1097 < 3; v1097 += 1) {	// L2008
              int8_t v1098 = v1088[v1089][v1096][v1097][1];	// L2009
              v1088[v1089][v1096][v1097][0] = v1098;	// L2010
              int8_t v1099 = v1088[v1089][v1096][v1097][2];	// L2011
              v1088[v1089][v1096][v1097][1] = v1099;	// L2012
              int8_t v1100 = v1087[v1089][v1096][v1097][v1091];	// L2013
              v1088[v1089][v1096][v1097][2] = v1100;	// L2014
            }
          }
          if ((v1091 - 18) >= 0) {	// L2017
            int8_t v1101[32];	// L2018
            #pragma HLS array_partition variable=v1101 cyclic factor=2 dim=1
            #pragma HLS bind_storage variable=v1101 type=ram_2p impl=lutram

            for (int v1102 = 0; v1102 < 16; v1102 += 1) {	// L2019
              #pragma HLS pipeline II=1
              for (int v1103 = 0; v1103 < 2; v1103 += 1) {	// L2020
                v1101[(v1103 + (v1102 * 2))] = (int8_t)0.000000;	// L2021
                for (int v1104 = 0; v1104 < 3; v1104 += 1) {	// L2022
                  for (int v1105 = 0; v1105 < 3; v1105 += 1) {	// L2023
                    for (int v1106 = 0; v1106 < 3; v1106 += 1) {	// L2024
                      int8_t v1107 = v1088[v1089][v1104][v1105][v1106];	// L2025
                      int8_t v1108 = v1075[(v1103 + (v1102 * 2))][v1104][v1105][v1106];	// L2026
                      int8_t v1109 = v1107 * v1108;	// L2027
                      int8_t v1110 = v1101[(v1103 + (v1102 * 2))];	// L2028
                      int8_t v1111 = v1110 + v1109;	// L2029
                      v1101[(v1103 + (v1102 * 2))] = v1111;	// L2030
                    }
                  }
                }
                int8_t v1112 = v1101[(v1103 + (v1102 * 2))];	// L2034
                v1086[v1089][(v1103 + (v1102 * 2))][(v1090 - 18)][(v1091 - 18)] = v1112;	// L2035
              }
            }
          }
        }
      }
    }
  }
  for (int v1113 = 0; v1113 < 1; v1113 += 1) {	// L2043
    for (int v1114 = 0; v1114 < 16; v1114 += 1) {	// L2044
      for (int v1115 = 0; v1115 < 16; v1115 += 1) {	// L2045
        for (int v1116 = 0; v1116 < 16; v1116 += 1) {	// L2046
          #pragma HLS pipeline II=1
          for (int v1117 = 0; v1117 < 2; v1117 += 1) {	// L2047
            int8_t v1118 = v1086[0][(v1117 + (v1116 * 2))][v1114][v1115];	// L2048
            bool v1119 = v1118 > (int8_t)0.000000;	// L2049
            int8_t v1120 = v1119 ? v1118 : (int8_t)0.000000;	// L2050
            v1077[v1113][(v1117 + (v1116 * 2))][v1114][v1115] = v1120;	// L2051
          }
        }
      }
    }
  }
  return ;	// L2057
}

/// This is top function.
void main_graph(
  int8_t v1121[1][3][32][32],
  int8_t v1122[1000],
  int8_t v1123[1024][1024][1][1],
  int8_t v1124[1024][512][1][1],
  int8_t v1125[512][512][1][1],
  int8_t v1126[512][512][1][1],
  int8_t v1127[512][512][1][1],
  int8_t v1128[512][512][1][1],
  int8_t v1129[512][512][1][1],
  int8_t v1130[512][256][1][1],
  int8_t v1131[256][256][1][1],
  int8_t v1132[256][128][1][1],
  int8_t v1133[128][128][1][1],
  int8_t v1134[128][64][1][1],
  int8_t v1135[64][32][1][1],
  int8_t v1136[32][3][3][3],
  int8_t v1137[32][3][3],
  int8_t v1138[64][3][3],
  int8_t v1139[128][3][3],
  int8_t v1140[128][3][3],
  int8_t v1141[256][3][3],
  int8_t v1142[256][3][3],
  int8_t v1143[512][3][3],
  int8_t v1144[512][3][3],
  int8_t v1145[512][3][3],
  int8_t v1146[512][3][3],
  int8_t v1147[512][3][3],
  int8_t v1148[512][3][3],
  int8_t v1149[1024][3][3],
  int8_t v1150[1024][1000],
  int8_t v1151[1][1000]
) {	// L2059
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v1121 bundle=gmem1
  #pragma HLS bind_storage variable=v1121 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1122 bundle=gmem2
  #pragma HLS bind_storage variable=v1122 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1123 bundle=gmem3
  #pragma HLS array_partition variable=v1123 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1123 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1124 bundle=gmem4
  #pragma HLS array_partition variable=v1124 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1124 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1125 bundle=gmem5
  #pragma HLS array_partition variable=v1125 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1125 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1126 bundle=gmem6
  #pragma HLS array_partition variable=v1126 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1126 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1127 bundle=gmem7
  #pragma HLS array_partition variable=v1127 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1127 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1128 bundle=gmem8
  #pragma HLS array_partition variable=v1128 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1128 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1129 bundle=gmem9
  #pragma HLS array_partition variable=v1129 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1129 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1130 bundle=gmem10
  #pragma HLS array_partition variable=v1130 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1130 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1131 bundle=gmem11
  #pragma HLS array_partition variable=v1131 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1131 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1132 bundle=gmem12
  #pragma HLS array_partition variable=v1132 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1132 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1133 bundle=gmem13
  #pragma HLS array_partition variable=v1133 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1133 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1134 bundle=gmem14
  #pragma HLS array_partition variable=v1134 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1134 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1135 bundle=gmem15
  #pragma HLS array_partition variable=v1135 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1135 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1136 bundle=gmem16
  #pragma HLS array_partition variable=v1136 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v1136 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1136 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1136 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1136 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1137 bundle=gmem17
  #pragma HLS array_partition variable=v1137 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1137 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1137 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1138 bundle=gmem18
  #pragma HLS array_partition variable=v1138 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1138 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1138 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1138 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1139 bundle=gmem19
  #pragma HLS array_partition variable=v1139 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1139 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1139 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1140 bundle=gmem20
  #pragma HLS array_partition variable=v1140 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1140 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1140 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1141 bundle=gmem21
  #pragma HLS array_partition variable=v1141 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1141 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1141 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1142 bundle=gmem22
  #pragma HLS array_partition variable=v1142 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1142 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1142 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1143 bundle=gmem23
  #pragma HLS array_partition variable=v1143 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1143 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1143 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1144 bundle=gmem24
  #pragma HLS array_partition variable=v1144 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1144 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1144 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1145 bundle=gmem25
  #pragma HLS array_partition variable=v1145 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1145 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1145 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1146 bundle=gmem26
  #pragma HLS array_partition variable=v1146 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1146 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1146 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1147 bundle=gmem27
  #pragma HLS array_partition variable=v1147 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1147 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1147 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1148 bundle=gmem28
  #pragma HLS array_partition variable=v1148 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1148 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1148 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1149 bundle=gmem29
  #pragma HLS array_partition variable=v1149 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1149 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1149 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1150 bundle=gmem30
  #pragma HLS bind_storage variable=v1150 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1151 bundle=gmem31
  #pragma HLS bind_storage variable=v1151 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v1152[1][32][16][16];	// L2061
  #pragma HLS stream variable=v1152 depth=10 type=fifo

  #pragma HLS array_partition variable=v1152 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v1152 type=ram_t2p impl=bram

  main_graph_node31(v1136, v1121, v1152);	// L2062
  int8_t v1153[1][32][16][16];	// L2063
  #pragma HLS stream variable=v1153 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1153 type=ram_t2p impl=bram

  main_graph_node30(v1137, v1152, v1153);	// L2064
  int8_t v1154[1][64][16][16];	// L2065
  #pragma HLS stream variable=v1154 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1154 type=ram_t2p impl=bram

  main_graph_node29(v1135, v1153, v1154);	// L2066
  int8_t v1155[1][64][8][8];	// L2067
  #pragma HLS stream variable=v1155 depth=10 type=fifo

  #pragma HLS array_partition variable=v1155 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1155 type=ram_2p impl=lutram

  main_graph_node28(v1154, v1138, v1155);	// L2068
  int8_t v1156[1][128][8][8];	// L2069
  #pragma HLS stream variable=v1156 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1156 type=ram_t2p impl=bram

  main_graph_node27(v1134, v1155, v1156);	// L2070
  int8_t v1157[1][128][8][8];	// L2071
  #pragma HLS stream variable=v1157 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1157 type=ram_t2p impl=bram

  main_graph_node26(v1139, v1156, v1157);	// L2072
  int8_t v1158[1][128][8][8];	// L2073
  #pragma HLS stream variable=v1158 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1158 type=ram_t2p impl=bram

  main_graph_node25(v1133, v1157, v1158);	// L2074
  int8_t v1159[1][128][4][4];	// L2075
  #pragma HLS stream variable=v1159 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1159 type=ram_t2p impl=bram

  main_graph_node24(v1140, v1158, v1159);	// L2076
  int8_t v1160[1][256][4][4];	// L2077
  #pragma HLS stream variable=v1160 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1160 type=ram_t2p impl=bram

  main_graph_node23(v1132, v1159, v1160);	// L2078
  int8_t v1161[1][256][4][4];	// L2079
  #pragma HLS stream variable=v1161 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1161 type=ram_t2p impl=bram

  main_graph_node22(v1160, v1141, v1161);	// L2080
  int8_t v1162[1][256][4][4];	// L2081
  #pragma HLS stream variable=v1162 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1162 type=ram_t2p impl=bram

  main_graph_node21(v1131, v1161, v1162);	// L2082
  int8_t v1163[1][256][2][2];	// L2083
  #pragma HLS stream variable=v1163 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1163 type=ram_t2p impl=bram

  main_graph_node20(v1142, v1162, v1163);	// L2084
  int8_t v1164[1][512][2][2];	// L2085
  #pragma HLS stream variable=v1164 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1164 type=ram_t2p impl=bram

  main_graph_node19(v1130, v1163, v1164);	// L2086
  int8_t v1165[1][512][2][2];	// L2087
  #pragma HLS stream variable=v1165 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1165 type=ram_t2p impl=bram

  main_graph_node18(v1143, v1164, v1165);	// L2088
  int8_t v1166[1][512][2][2];	// L2089
  #pragma HLS stream variable=v1166 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1166 type=ram_t2p impl=bram

  main_graph_node17(v1165, v1129, v1166);	// L2090
  int8_t v1167[1][512][2][2];	// L2091
  #pragma HLS stream variable=v1167 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1167 type=ram_t2p impl=bram

  main_graph_node16(v1166, v1144, v1167);	// L2092
  int8_t v1168[1][512][2][2];	// L2093
  #pragma HLS stream variable=v1168 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1168 type=ram_t2p impl=bram

  main_graph_node15(v1128, v1167, v1168);	// L2094
  int8_t v1169[1][512][2][2];	// L2095
  #pragma HLS stream variable=v1169 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1169 type=ram_t2p impl=bram

  main_graph_node14(v1145, v1168, v1169);	// L2096
  int8_t v1170[1][512][2][2];	// L2097
  #pragma HLS stream variable=v1170 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1170 type=ram_t2p impl=bram

  main_graph_node13(v1169, v1127, v1170);	// L2098
  int8_t v1171[1][512][2][2];	// L2099
  #pragma HLS stream variable=v1171 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1171 type=ram_t2p impl=bram

  main_graph_node12(v1170, v1146, v1171);	// L2100
  int8_t v1172[1][512][2][2];	// L2101
  #pragma HLS stream variable=v1172 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1172 type=ram_t2p impl=bram

  main_graph_node11(v1126, v1171, v1172);	// L2102
  int8_t v1173[1][512][2][2];	// L2103
  #pragma HLS stream variable=v1173 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1173 type=ram_t2p impl=bram

  main_graph_node10(v1172, v1147, v1173);	// L2104
  int8_t v1174[1][512][2][2];	// L2105
  #pragma HLS stream variable=v1174 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1174 type=ram_t2p impl=bram

  main_graph_node9(v1125, v1173, v1174);	// L2106
  int8_t v1175[1][512][1][1];	// L2107
  #pragma HLS stream variable=v1175 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1175 type=ram_t2p impl=bram

  main_graph_node8(v1148, v1174, v1175);	// L2108
  int8_t v1176[1][1024][1][1];	// L2109
  #pragma HLS stream variable=v1176 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1176 type=ram_t2p impl=bram

  main_graph_node7(v1124, v1175, v1176);	// L2110
  int8_t v1177[1][1024][1][1];	// L2111
  #pragma HLS stream variable=v1177 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1177 type=ram_t2p impl=bram

  main_graph_node6(v1176, v1149, v1177);	// L2112
  int8_t v1178[1][1024][1][1];	// L2113
  #pragma HLS stream variable=v1178 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1178 type=ram_t2p impl=bram

  main_graph_node5(v1123, v1177, v1178);	// L2114
  int8_t v1179[1][1024][2][2];	// L2115
  #pragma HLS bind_storage variable=v1179 type=ram_t2p impl=bram

  main_graph_node4(v1178, v1179);	// L2116
  int8_t v1180[1][1];	// L2117
  #pragma HLS bind_storage variable=v1180 type=ram_t2p impl=bram

  int8_t v1181[1][1024][1][1];	// L2118
  #pragma HLS bind_storage variable=v1181 type=ram_t2p impl=bram

  main_graph_node3(v1179, v1180, v1181);	// L2119
  int8_t v1182[1][1024][1][1];	// L2120
  #pragma HLS bind_storage variable=v1182 type=ram_t2p impl=bram

  main_graph_node2(v1181, v1180, v1182);	// L2121
  int8_t v1183[1][1000];	// L2122
  #pragma HLS bind_storage variable=v1183 type=ram_t2p impl=bram

  main_graph_node1(v1182, v1150, v1183);	// L2123
  main_graph_node0(v1183, v1122, v1151);	// L2124
  return ;	// L2125
}

