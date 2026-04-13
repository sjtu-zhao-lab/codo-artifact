
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
  int8_t v0[1][10],
  int8_t v1[10],
  int8_t v2[1][10]
) {	// L14
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L15
    for (int v4 = 0; v4 < 10; v4 += 1) {	// L16
      int8_t v5 = v0[0][v4];	// L17
      int8_t v6 = v1[v4];	// L18
      int8_t v7 = v5 + v6;	// L19
      v2[v3][v4] = v7;	// L20
    }
  }
  return ;	// L23
}

void main_graph_node1(
  int8_t v8[1][512][1][1],
  int8_t v9[512][10],
  int8_t v10[1][10]
) {	// L25
  #pragma HLS dataflow

  int8_t v11[1][10];	// L27
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L28
    for (int v13 = 0; v13 < 10; v13 += 1) {	// L29
      v11[v12][v13] = (int8_t)0.000000;	// L30
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L33
    for (int v15 = 0; v15 < 10; v15 += 1) {	// L34
      for (int v16 = 0; v16 < 512; v16 += 1) {	// L35
        int8_t v17 = v8[v14][v16][0][0];	// L36
        int8_t v18 = v9[v16][v15];	// L37
        int8_t v19 = v11[v14][v15];	// L38
        int8_t v20 = v17 * v18;	// L39
        int8_t v21 = v19 + v20;	// L40
        v10[v14][v15] = v21;	// L41
      }
    }
  }
  return ;	// L45
}

void main_graph_node2(
  int8_t v22[1][512][1][1],
  int8_t v23[1][1],
  int8_t v24[1][512][1][1]
) {	// L47
  #pragma HLS dataflow

  int8_t v25[1][512][1][1];	// L48
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  for (int v26 = 0; v26 < 1; v26 += 1) {	// L49
    for (int v27 = 0; v27 < 512; v27 += 1) {	// L50
      for (int v28 = 0; v28 < 1; v28 += 1) {	// L51
        for (int v29 = 0; v29 < 1; v29 += 1) {	// L52
          int8_t v30 = v22[v26][v27][v28][v29];	// L53
          v25[v26][v27][v28][v29] = v30;	// L54
          int8_t v31 = v23[v28][v29];	// L55
          int8_t v32 = v25[v26][v27][v28][v29];	// L56
          int8_t v33 = v32 / v31;	// L57
          v24[v26][v27][v28][v29] = v33;	// L58
        }
      }
    }
  }
  return ;	// L63
}

void main_graph_node3(
  int8_t v34[1][512][5][5],
  int8_t v35[1][512][1][1],
  int8_t v36[1][1]
) {	// L65
  #pragma HLS dataflow

  int8_t v37[1][512][1][1];	// L69
  #pragma HLS bind_storage variable=v37 type=ram_t2p impl=bram

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L70
    for (int v39 = 0; v39 < 512; v39 += 1) {	// L71
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L72
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L73
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L74
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L79
    for (int v43 = 0; v43 < 512; v43 += 1) {	// L80
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L81
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L82
          for (int v46 = 0; v46 < 4; v46 += 1) {	// L83
            for (int v47 = 0; v47 < 4; v47 += 1) {	// L84
              int8_t v48 = v37[v42][v43][v44][v45];	// L85
              int v49 = v44 * (int)4;	// L86
              int v50 = v44 + (int)1;	// L87
              int v51 = v50 * (int)4;	// L88
              int v52 = v45 * (int)4;	// L89
              int v53 = v45 + (int)1;	// L90
              int v54 = v53 * (int)4;	// L91
              int v55 = v49 + v46;	// L92
              int v56 = v52 + v47;	// L93
              int8_t v57 = v34[v42][v43][v55][v56];	// L94
              bool v58 = v55 < v51;	// L95
              int8_t v59 = v58 ? v57 : (int8_t)0.000000;	// L96
              bool v60 = v56 < v54;	// L97
              int8_t v61 = v60 ? v59 : (int8_t)0.000000;	// L98
              int8_t v62 = v61 + v48;	// L99
              int v63 = v51 - v49;	// L100
              int v64 = v54 - v52;	// L101
              int v65 = v63 * v64;	// L102
              ap_int<64> v66 = v65;	// L103
              int8_t v67 = v66;	// L104
              v35[v42][v43][v44][v45] = v62;	// L105
              v36[v42][v43] = v67;	// L106
            }
          }
        }
      }
    }
  }
  return ;	// L113
}

void main_graph_node4(
  int8_t v68[1][512][4][4],
  int8_t v69[1][512][5][5]
) {	// L115
  #pragma HLS dataflow

  for (int v70 = 0; v70 < 1; v70 += 1) {	// L117
    for (int v71 = 0; v71 < 512; v71 += 1) {	// L118
      for (int v72 = 0; v72 < 5; v72 += 1) {	// L119
        for (int v73 = 0; v73 < 5; v73 += 1) {	// L120
          int8_t v74;	// L121
          v74 = (int8_t)0.000000;	// L122
          if (((-v72) + 3) >= 0 && ((-v73) + 3) >= 0) {	// L123
            int8_t v75 = v68[v70][v71][v72][v73];	// L124
            v74 = v75;	// L125
          }
          int8_t v76 = v74;	// L127
          v69[v70][v71][v72][v73] = v76;	// L128
        }
      }
    }
  }
  return ;	// L133
}

void main_graph_node5(
  int8_t v77[1][512][4][4],
  int8_t v78[1][512][4][4],
  int8_t v79[1][512][4][4]
) {	// L135
  #pragma HLS dataflow

  for (int v80 = 0; v80 < 1; v80 += 1) {	// L137
    for (int v81 = 0; v81 < 4; v81 += 1) {	// L138
      for (int v82 = 0; v82 < 4; v82 += 1) {	// L139
        for (int v83 = 0; v83 < 512; v83 += 1) {	// L140
          int8_t v84 = v77[0][v83][v81][v82];	// L141
          int8_t v85 = v78[0][v83][v81][v82];	// L142
          int8_t v86 = v84 + v85;	// L143
          bool v87 = v86 > (int8_t)0.000000;	// L144
          int8_t v88 = v87 ? v86 : (int8_t)0.000000;	// L145
          v79[v80][v83][v81][v82] = v88;	// L146
        }
      }
    }
  }
  return ;	// L151
}

void main_graph_node6(
  int8_t v89[512][512][3][3],
  int8_t v90[1][512][4][4],
  int8_t v91[1][512][4][4]
) {	// L153
  #pragma HLS dataflow

  int8_t v92[1][512][6][6];	// L155
  #pragma HLS stream variable=v92 depth=10 type=fifo

  #pragma HLS bind_storage variable=v92 type=ram_t2p impl=bram

  for (int v93 = 0; v93 < 1; v93 += 1) {	// L156
    for (int v94 = 0; v94 < 6; v94 += 1) {	// L157
      for (int v95 = 0; v95 < 6; v95 += 1) {	// L158
        for (int v96 = 0; v96 < 512; v96 += 1) {	// L159
          int8_t v97;	// L160
          v97 = (int8_t)0.000000;	// L161
          if (((-v94) + 3) >= 0 && ((-v95) + 3) >= 0) {	// L162
            int8_t v98 = v90[v93][v96][v94][v95];	// L163
            v97 = v98;	// L164
          }
          int8_t v99 = v97;	// L166
          v92[v93][v96][v94][v95] = v99;	// L167
        }
      }
    }
  }
  int8_t v100[1][512][3][6];	// L172
  #pragma HLS array_partition variable=v100 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v100 type=ram_2p impl=bram

  int8_t v101[1][512][3][3];	// L173
  #pragma HLS array_partition variable=v101 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v101 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v101 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v101 type=ram_2p impl=lutram

  for (int v102 = 0; v102 < 1; v102 += 1) {	// L174
    for (int v103 = 0; v103 < 6; v103 += 1) {	// L175
      for (int v104 = 0; v104 < 6; v104 += 1) {	// L176
        for (int v105 = 0; v105 < 512; v105 += 1) {	// L177
          int8_t v106 = v100[v102][v105][1][v104];	// L178
          v100[v102][v105][0][v104] = v106;	// L179
          int8_t v107 = v100[v102][v105][2][v104];	// L180
          v100[v102][v105][1][v104] = v107;	// L181
          int8_t v108 = v92[v102][v105][v103][v104];	// L182
          v100[v102][v105][2][v104] = v108;	// L183
        }
        if ((v103 - 2) >= 0) {	// L185
          for (int v109 = 0; v109 < 512; v109 += 1) {	// L186
            for (int v110 = 0; v110 < 3; v110 += 1) {	// L187
              int8_t v111 = v101[v102][v109][v110][1];	// L188
              v101[v102][v109][v110][0] = v111;	// L189
              int8_t v112 = v101[v102][v109][v110][2];	// L190
              v101[v102][v109][v110][1] = v112;	// L191
              int8_t v113 = v100[v102][v109][v110][v104];	// L192
              v101[v102][v109][v110][2] = v113;	// L193
            }
          }
          if ((v104 - 2) >= 0) {	// L196
            int8_t v114[512];	// L197
            #pragma HLS bind_storage variable=v114 type=ram_2p impl=bram

            for (int v115 = 0; v115 < 512; v115 += 1) {	// L198
              v114[v115] = (int8_t)0.000000;	// L199
              for (int v116 = 0; v116 < 64; v116 += 1) {	// L200
                #pragma HLS pipeline II=1
                for (int v117 = 0; v117 < 8; v117 += 1) {	// L201
                  for (int v118 = 0; v118 < 3; v118 += 1) {	// L202
                    for (int v119 = 0; v119 < 3; v119 += 1) {	// L203
                      int8_t v120 = v101[v102][(v117 + (v116 * 8))][v118][v119];	// L204
                      int8_t v121 = v89[v115][(v117 + (v116 * 8))][v118][v119];	// L205
                      int8_t v122 = v120 * v121;	// L206
                      int8_t v123 = v114[v115];	// L207
                      int8_t v124 = v123 + v122;	// L208
                      v114[v115] = v124;	// L209
                    }
                  }
                }
              }
              int8_t v125 = v114[v115];	// L214
              v91[v102][v115][(v103 - 2)][(v104 - 2)] = v125;	// L215
            }
          }
        }
      }
    }
  }
  return ;	// L222
}

void main_graph_node7(
  int8_t v126[1][512][4][4],
  int8_t v127[512][512][3][3],
  int8_t v128[1][512][4][4]
) {	// L224
  #pragma HLS dataflow

  int8_t v129[1][512][6][6];	// L226
  #pragma HLS stream variable=v129 depth=10 type=fifo

  #pragma HLS bind_storage variable=v129 type=ram_t2p impl=bram

  for (int v130 = 0; v130 < 1; v130 += 1) {	// L227
    for (int v131 = 0; v131 < 6; v131 += 1) {	// L228
      for (int v132 = 0; v132 < 6; v132 += 1) {	// L229
        for (int v133 = 0; v133 < 512; v133 += 1) {	// L230
          int8_t v134;	// L231
          v134 = (int8_t)0.000000;	// L232
          if (((-v131) + 3) >= 0 && ((-v132) + 3) >= 0) {	// L233
            int8_t v135 = v126[v130][v133][v131][v132];	// L234
            v134 = v135;	// L235
          }
          int8_t v136 = v134;	// L237
          v129[v130][v133][v131][v132] = v136;	// L238
        }
      }
    }
  }
  int8_t v137[1][512][4][4];	// L243
  #pragma HLS stream variable=v137 depth=10 type=fifo

  #pragma HLS bind_storage variable=v137 type=ram_t2p impl=bram

  int8_t v138[1][512][3][6];	// L244
  #pragma HLS array_partition variable=v138 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v138 type=ram_2p impl=bram

  int8_t v139[1][512][3][3];	// L245
  #pragma HLS array_partition variable=v139 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v139 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v139 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v139 type=ram_2p impl=lutram

  for (int v140 = 0; v140 < 1; v140 += 1) {	// L246
    for (int v141 = 0; v141 < 6; v141 += 1) {	// L247
      for (int v142 = 0; v142 < 6; v142 += 1) {	// L248
        for (int v143 = 0; v143 < 512; v143 += 1) {	// L249
          int8_t v144 = v138[v140][v143][1][v142];	// L250
          v138[v140][v143][0][v142] = v144;	// L251
          int8_t v145 = v138[v140][v143][2][v142];	// L252
          v138[v140][v143][1][v142] = v145;	// L253
          int8_t v146 = v129[v140][v143][v141][v142];	// L254
          v138[v140][v143][2][v142] = v146;	// L255
        }
        if ((v141 - 2) >= 0) {	// L257
          for (int v147 = 0; v147 < 512; v147 += 1) {	// L258
            for (int v148 = 0; v148 < 3; v148 += 1) {	// L259
              int8_t v149 = v139[v140][v147][v148][1];	// L260
              v139[v140][v147][v148][0] = v149;	// L261
              int8_t v150 = v139[v140][v147][v148][2];	// L262
              v139[v140][v147][v148][1] = v150;	// L263
              int8_t v151 = v138[v140][v147][v148][v142];	// L264
              v139[v140][v147][v148][2] = v151;	// L265
            }
          }
          if ((v142 - 2) >= 0) {	// L268
            int8_t v152[512];	// L269
            #pragma HLS bind_storage variable=v152 type=ram_2p impl=bram

            for (int v153 = 0; v153 < 512; v153 += 1) {	// L270
              v152[v153] = (int8_t)0.000000;	// L271
              for (int v154 = 0; v154 < 64; v154 += 1) {	// L272
                #pragma HLS pipeline II=1
                for (int v155 = 0; v155 < 8; v155 += 1) {	// L273
                  for (int v156 = 0; v156 < 3; v156 += 1) {	// L274
                    for (int v157 = 0; v157 < 3; v157 += 1) {	// L275
                      int8_t v158 = v139[v140][(v155 + (v154 * 8))][v156][v157];	// L276
                      int8_t v159 = v127[v153][(v155 + (v154 * 8))][v156][v157];	// L277
                      int8_t v160 = v158 * v159;	// L278
                      int8_t v161 = v152[v153];	// L279
                      int8_t v162 = v161 + v160;	// L280
                      v152[v153] = v162;	// L281
                    }
                  }
                }
              }
              int8_t v163 = v152[v153];	// L286
              v137[v140][v153][(v141 - 2)][(v142 - 2)] = v163;	// L287
            }
          }
        }
      }
    }
  }
  for (int v164 = 0; v164 < 1; v164 += 1) {	// L294
    for (int v165 = 0; v165 < 4; v165 += 1) {	// L295
      for (int v166 = 0; v166 < 4; v166 += 1) {	// L296
        for (int v167 = 0; v167 < 512; v167 += 1) {	// L297
          int8_t v168 = v137[0][v167][v165][v166];	// L298
          bool v169 = v168 > (int8_t)0.000000;	// L299
          int8_t v170 = v169 ? v168 : (int8_t)0.000000;	// L300
          v128[v164][v167][v165][v166] = v170;	// L301
        }
      }
    }
  }
  return ;	// L306
}

void main_graph_node8(
  int8_t v171[1][512][4][4],
  int8_t v172[1][512][4][4],
  int8_t v173[1][512][4][4]
) {	// L308
  #pragma HLS dataflow

  for (int v174 = 0; v174 < 1; v174 += 1) {	// L309
    for (int v175 = 0; v175 < 4; v175 += 1) {	// L310
      for (int v176 = 0; v176 < 4; v176 += 1) {	// L311
        for (int v177 = 0; v177 < 512; v177 += 1) {	// L312
          int8_t v178 = v171[v174][v177][v175][v176];	// L313
          v172[v174][v177][v175][v176] = v178;	// L314
          int8_t v179 = v171[v174][v177][v175][v176];	// L315
          v173[v174][v177][v175][v176] = v179;	// L316
        }
      }
    }
  }
  return ;	// L321
}

void main_graph_node9(
  int8_t v180[1][512][4][4],
  int8_t v181[1][512][4][4],
  int8_t v182[1][512][4][4]
) {	// L323
  #pragma HLS dataflow

  for (int v183 = 0; v183 < 1; v183 += 1) {	// L325
    for (int v184 = 0; v184 < 4; v184 += 1) {	// L326
      for (int v185 = 0; v185 < 4; v185 += 1) {	// L327
        for (int v186 = 0; v186 < 512; v186 += 1) {	// L328
          int8_t v187 = v180[0][v186][v184][v185];	// L329
          int8_t v188 = v181[0][v186][v184][v185];	// L330
          int8_t v189 = v187 + v188;	// L331
          bool v190 = v189 > (int8_t)0.000000;	// L332
          int8_t v191 = v190 ? v189 : (int8_t)0.000000;	// L333
          v182[v183][v186][v184][v185] = v191;	// L334
        }
      }
    }
  }
  return ;	// L339
}

void main_graph_node10(
  int8_t v192[1][256][8][8],
  int8_t v193[512][256][1][1],
  int8_t v194[1][512][4][4]
) {	// L341
  #pragma HLS dataflow

  int8_t v195[1][256][1][8];	// L343
  #pragma HLS bind_storage variable=v195 type=ram_2p impl=bram

  int8_t v196[1][256][1][1];	// L344
  #pragma HLS array_partition variable=v196 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v196 type=ram_2p impl=lutram

  for (int v197 = 0; v197 < 1; v197 += 1) {	// L345
    for (int v198 = 0; v198 < 8; v198 += 1) {	// L346
      for (int v199 = 0; v199 < 8; v199 += 1) {	// L347
        for (int v200 = 0; v200 < 256; v200 += 1) {	// L348
          int8_t v201 = v192[v197][v200][v198][v199];	// L349
          v195[v197][v200][0][v199] = v201;	// L350
        }
        if ((v198 - 4) >= 0) {	// L352
          for (int v202 = 0; v202 < 256; v202 += 1) {	// L353
            for (int v203 = 0; v203 < 1; v203 += 1) {	// L354
              int8_t v204 = v195[v197][v202][v203][v199];	// L355
              v196[v197][v202][v203][0] = v204;	// L356
            }
          }
          if ((v199 - 4) >= 0) {	// L359
            int8_t v205[512];	// L360
            #pragma HLS bind_storage variable=v205 type=ram_2p impl=bram

            for (int v206 = 0; v206 < 512; v206 += 1) {	// L361
              v205[v206] = (int8_t)0.000000;	// L362
              for (int v207 = 0; v207 < 32; v207 += 1) {	// L363
                #pragma HLS pipeline II=1
                for (int v208 = 0; v208 < 8; v208 += 1) {	// L364
                  for (int v209 = 0; v209 < 1; v209 += 1) {	// L365
                    for (int v210 = 0; v210 < 1; v210 += 1) {	// L366
                      int8_t v211 = v196[v197][(v208 + (v207 * 8))][v209][v210];	// L367
                      int8_t v212 = v193[v206][(v208 + (v207 * 8))][v209][v210];	// L368
                      int8_t v213 = v211 * v212;	// L369
                      int8_t v214 = v205[v206];	// L370
                      int8_t v215 = v214 + v213;	// L371
                      v205[v206] = v215;	// L372
                    }
                  }
                }
              }
              int8_t v216 = v205[v206];	// L377
              v194[v197][v206][(v198 - 4)][(v199 - 4)] = v216;	// L378
            }
          }
        }
      }
    }
  }
  return ;	// L385
}

void main_graph_node11(
  int8_t v217[512][512][3][3],
  int8_t v218[1][512][4][4],
  int8_t v219[1][512][4][4]
) {	// L387
  #pragma HLS dataflow

  int8_t v220[1][512][6][6];	// L389
  #pragma HLS stream variable=v220 depth=10 type=fifo

  #pragma HLS bind_storage variable=v220 type=ram_t2p impl=bram

  for (int v221 = 0; v221 < 1; v221 += 1) {	// L390
    for (int v222 = 0; v222 < 6; v222 += 1) {	// L391
      for (int v223 = 0; v223 < 6; v223 += 1) {	// L392
        for (int v224 = 0; v224 < 512; v224 += 1) {	// L393
          int8_t v225;	// L394
          v225 = (int8_t)0.000000;	// L395
          if (((-v222) + 3) >= 0 && ((-v223) + 3) >= 0) {	// L396
            int8_t v226 = v218[v221][v224][v222][v223];	// L397
            v225 = v226;	// L398
          }
          int8_t v227 = v225;	// L400
          v220[v221][v224][v222][v223] = v227;	// L401
        }
      }
    }
  }
  int8_t v228[1][512][3][6];	// L406
  #pragma HLS array_partition variable=v228 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v228 type=ram_2p impl=bram

  int8_t v229[1][512][3][3];	// L407
  #pragma HLS array_partition variable=v229 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v229 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v229 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v229 type=ram_2p impl=lutram

  for (int v230 = 0; v230 < 1; v230 += 1) {	// L408
    for (int v231 = 0; v231 < 6; v231 += 1) {	// L409
      for (int v232 = 0; v232 < 6; v232 += 1) {	// L410
        for (int v233 = 0; v233 < 512; v233 += 1) {	// L411
          int8_t v234 = v228[v230][v233][1][v232];	// L412
          v228[v230][v233][0][v232] = v234;	// L413
          int8_t v235 = v228[v230][v233][2][v232];	// L414
          v228[v230][v233][1][v232] = v235;	// L415
          int8_t v236 = v220[v230][v233][v231][v232];	// L416
          v228[v230][v233][2][v232] = v236;	// L417
        }
        if ((v231 - 2) >= 0) {	// L419
          for (int v237 = 0; v237 < 512; v237 += 1) {	// L420
            for (int v238 = 0; v238 < 3; v238 += 1) {	// L421
              int8_t v239 = v229[v230][v237][v238][1];	// L422
              v229[v230][v237][v238][0] = v239;	// L423
              int8_t v240 = v229[v230][v237][v238][2];	// L424
              v229[v230][v237][v238][1] = v240;	// L425
              int8_t v241 = v228[v230][v237][v238][v232];	// L426
              v229[v230][v237][v238][2] = v241;	// L427
            }
          }
          if ((v232 - 2) >= 0) {	// L430
            int8_t v242[512];	// L431
            #pragma HLS bind_storage variable=v242 type=ram_2p impl=bram

            for (int v243 = 0; v243 < 512; v243 += 1) {	// L432
              v242[v243] = (int8_t)0.000000;	// L433
              for (int v244 = 0; v244 < 64; v244 += 1) {	// L434
                #pragma HLS pipeline II=1
                for (int v245 = 0; v245 < 8; v245 += 1) {	// L435
                  for (int v246 = 0; v246 < 3; v246 += 1) {	// L436
                    for (int v247 = 0; v247 < 3; v247 += 1) {	// L437
                      int8_t v248 = v229[v230][(v245 + (v244 * 8))][v246][v247];	// L438
                      int8_t v249 = v217[v243][(v245 + (v244 * 8))][v246][v247];	// L439
                      int8_t v250 = v248 * v249;	// L440
                      int8_t v251 = v242[v243];	// L441
                      int8_t v252 = v251 + v250;	// L442
                      v242[v243] = v252;	// L443
                    }
                  }
                }
              }
              int8_t v253 = v242[v243];	// L448
              v219[v230][v243][(v231 - 2)][(v232 - 2)] = v253;	// L449
            }
          }
        }
      }
    }
  }
  return ;	// L456
}

void main_graph_node12(
  int8_t v254[1][256][8][8],
  int8_t v255[512][256][3][3],
  int8_t v256[1][512][4][4]
) {	// L458
  #pragma HLS dataflow

  int8_t v257[1][256][10][10];	// L460
  #pragma HLS stream variable=v257 depth=10 type=fifo

  #pragma HLS bind_storage variable=v257 type=ram_t2p impl=bram

  for (int v258 = 0; v258 < 1; v258 += 1) {	// L461
    for (int v259 = 0; v259 < 10; v259 += 1) {	// L462
      for (int v260 = 0; v260 < 10; v260 += 1) {	// L463
        for (int v261 = 0; v261 < 256; v261 += 1) {	// L464
          int8_t v262;	// L465
          v262 = (int8_t)0.000000;	// L466
          if (((-v259) + 7) >= 0 && ((-v260) + 7) >= 0) {	// L467
            int8_t v263 = v254[v258][v261][v259][v260];	// L468
            v262 = v263;	// L469
          }
          int8_t v264 = v262;	// L471
          v257[v258][v261][v259][v260] = v264;	// L472
        }
      }
    }
  }
  int8_t v265[1][512][4][4];	// L477
  #pragma HLS stream variable=v265 depth=10 type=fifo

  #pragma HLS bind_storage variable=v265 type=ram_t2p impl=bram

  int8_t v266[1][256][3][10];	// L478
  #pragma HLS array_partition variable=v266 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v266 type=ram_2p impl=bram

  int8_t v267[1][256][3][3];	// L479
  #pragma HLS array_partition variable=v267 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v267 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v267 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v267 type=ram_2p impl=lutram

  for (int v268 = 0; v268 < 1; v268 += 1) {	// L480
    for (int v269 = 0; v269 < 10; v269 += 1) {	// L481
      for (int v270 = 0; v270 < 10; v270 += 1) {	// L482
        for (int v271 = 0; v271 < 256; v271 += 1) {	// L483
          int8_t v272 = v266[v268][v271][1][v270];	// L484
          v266[v268][v271][0][v270] = v272;	// L485
          int8_t v273 = v266[v268][v271][2][v270];	// L486
          v266[v268][v271][1][v270] = v273;	// L487
          int8_t v274 = v257[v268][v271][v269][v270];	// L488
          v266[v268][v271][2][v270] = v274;	// L489
        }
        if ((v269 - 6) >= 0) {	// L491
          for (int v275 = 0; v275 < 256; v275 += 1) {	// L492
            for (int v276 = 0; v276 < 3; v276 += 1) {	// L493
              int8_t v277 = v267[v268][v275][v276][1];	// L494
              v267[v268][v275][v276][0] = v277;	// L495
              int8_t v278 = v267[v268][v275][v276][2];	// L496
              v267[v268][v275][v276][1] = v278;	// L497
              int8_t v279 = v266[v268][v275][v276][v270];	// L498
              v267[v268][v275][v276][2] = v279;	// L499
            }
          }
          if ((v270 - 6) >= 0) {	// L502
            int8_t v280[512];	// L503
            #pragma HLS bind_storage variable=v280 type=ram_2p impl=bram

            for (int v281 = 0; v281 < 512; v281 += 1) {	// L504
              v280[v281] = (int8_t)0.000000;	// L505
              for (int v282 = 0; v282 < 32; v282 += 1) {	// L506
                #pragma HLS pipeline II=1
                for (int v283 = 0; v283 < 8; v283 += 1) {	// L507
                  for (int v284 = 0; v284 < 3; v284 += 1) {	// L508
                    for (int v285 = 0; v285 < 3; v285 += 1) {	// L509
                      int8_t v286 = v267[v268][(v283 + (v282 * 8))][v284][v285];	// L510
                      int8_t v287 = v255[v281][(v283 + (v282 * 8))][v284][v285];	// L511
                      int8_t v288 = v286 * v287;	// L512
                      int8_t v289 = v280[v281];	// L513
                      int8_t v290 = v289 + v288;	// L514
                      v280[v281] = v290;	// L515
                    }
                  }
                }
              }
              int8_t v291 = v280[v281];	// L520
              v265[v268][v281][(v269 - 6)][(v270 - 6)] = v291;	// L521
            }
          }
        }
      }
    }
  }
  for (int v292 = 0; v292 < 1; v292 += 1) {	// L528
    for (int v293 = 0; v293 < 4; v293 += 1) {	// L529
      for (int v294 = 0; v294 < 4; v294 += 1) {	// L530
        for (int v295 = 0; v295 < 512; v295 += 1) {	// L531
          int8_t v296 = v265[0][v295][v293][v294];	// L532
          bool v297 = v296 > (int8_t)0.000000;	// L533
          int8_t v298 = v297 ? v296 : (int8_t)0.000000;	// L534
          v256[v292][v295][v293][v294] = v298;	// L535
        }
      }
    }
  }
  return ;	// L540
}

void main_graph_node13(
  int8_t v299[1][256][8][8],
  int8_t v300[1][256][8][8],
  int8_t v301[1][256][8][8]
) {	// L542
  #pragma HLS dataflow

  for (int v302 = 0; v302 < 1; v302 += 1) {	// L543
    for (int v303 = 0; v303 < 8; v303 += 1) {	// L544
      for (int v304 = 0; v304 < 8; v304 += 1) {	// L545
        for (int v305 = 0; v305 < 256; v305 += 1) {	// L546
          int8_t v306 = v299[v302][v305][v303][v304];	// L547
          v300[v302][v305][v303][v304] = v306;	// L548
          int8_t v307 = v299[v302][v305][v303][v304];	// L549
          v301[v302][v305][v303][v304] = v307;	// L550
        }
      }
    }
  }
  return ;	// L555
}

void main_graph_node14(
  int8_t v308[1][256][8][8],
  int8_t v309[1][256][8][8],
  int8_t v310[1][256][8][8]
) {	// L557
  #pragma HLS dataflow

  for (int v311 = 0; v311 < 1; v311 += 1) {	// L559
    for (int v312 = 0; v312 < 8; v312 += 1) {	// L560
      for (int v313 = 0; v313 < 8; v313 += 1) {	// L561
        for (int v314 = 0; v314 < 256; v314 += 1) {	// L562
          int8_t v315 = v308[0][v314][v312][v313];	// L563
          int8_t v316 = v309[0][v314][v312][v313];	// L564
          int8_t v317 = v315 + v316;	// L565
          bool v318 = v317 > (int8_t)0.000000;	// L566
          int8_t v319 = v318 ? v317 : (int8_t)0.000000;	// L567
          v310[v311][v314][v312][v313] = v319;	// L568
        }
      }
    }
  }
  return ;	// L573
}

void main_graph_node15(
  int8_t v320[256][256][3][3],
  int8_t v321[1][256][8][8],
  int8_t v322[1][256][8][8]
) {	// L575
  #pragma HLS dataflow

  int8_t v323[1][256][10][10];	// L577
  #pragma HLS stream variable=v323 depth=10 type=fifo

  #pragma HLS bind_storage variable=v323 type=ram_t2p impl=bram

  for (int v324 = 0; v324 < 1; v324 += 1) {	// L578
    for (int v325 = 0; v325 < 10; v325 += 1) {	// L579
      for (int v326 = 0; v326 < 10; v326 += 1) {	// L580
        for (int v327 = 0; v327 < 256; v327 += 1) {	// L581
          int8_t v328;	// L582
          v328 = (int8_t)0.000000;	// L583
          if (((-v325) + 7) >= 0 && ((-v326) + 7) >= 0) {	// L584
            int8_t v329 = v321[v324][v327][v325][v326];	// L585
            v328 = v329;	// L586
          }
          int8_t v330 = v328;	// L588
          v323[v324][v327][v325][v326] = v330;	// L589
        }
      }
    }
  }
  int8_t v331[1][256][3][10];	// L594
  #pragma HLS array_partition variable=v331 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v331 type=ram_2p impl=bram

  int8_t v332[1][256][3][3];	// L595
  #pragma HLS array_partition variable=v332 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v332 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v332 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v332 type=ram_2p impl=lutram

  for (int v333 = 0; v333 < 1; v333 += 1) {	// L596
    for (int v334 = 0; v334 < 10; v334 += 1) {	// L597
      for (int v335 = 0; v335 < 10; v335 += 1) {	// L598
        for (int v336 = 0; v336 < 256; v336 += 1) {	// L599
          int8_t v337 = v331[v333][v336][1][v335];	// L600
          v331[v333][v336][0][v335] = v337;	// L601
          int8_t v338 = v331[v333][v336][2][v335];	// L602
          v331[v333][v336][1][v335] = v338;	// L603
          int8_t v339 = v323[v333][v336][v334][v335];	// L604
          v331[v333][v336][2][v335] = v339;	// L605
        }
        if ((v334 - 2) >= 0) {	// L607
          for (int v340 = 0; v340 < 256; v340 += 1) {	// L608
            for (int v341 = 0; v341 < 3; v341 += 1) {	// L609
              int8_t v342 = v332[v333][v340][v341][1];	// L610
              v332[v333][v340][v341][0] = v342;	// L611
              int8_t v343 = v332[v333][v340][v341][2];	// L612
              v332[v333][v340][v341][1] = v343;	// L613
              int8_t v344 = v331[v333][v340][v341][v335];	// L614
              v332[v333][v340][v341][2] = v344;	// L615
            }
          }
          if ((v335 - 2) >= 0) {	// L618
            int8_t v345[256];	// L619
            #pragma HLS bind_storage variable=v345 type=ram_2p impl=bram

            for (int v346 = 0; v346 < 256; v346 += 1) {	// L620
              v345[v346] = (int8_t)0.000000;	// L621
              for (int v347 = 0; v347 < 64; v347 += 1) {	// L622
                #pragma HLS pipeline II=1
                for (int v348 = 0; v348 < 4; v348 += 1) {	// L623
                  for (int v349 = 0; v349 < 3; v349 += 1) {	// L624
                    for (int v350 = 0; v350 < 3; v350 += 1) {	// L625
                      int8_t v351 = v332[v333][(v348 + (v347 * 4))][v349][v350];	// L626
                      int8_t v352 = v320[v346][(v348 + (v347 * 4))][v349][v350];	// L627
                      int8_t v353 = v351 * v352;	// L628
                      int8_t v354 = v345[v346];	// L629
                      int8_t v355 = v354 + v353;	// L630
                      v345[v346] = v355;	// L631
                    }
                  }
                }
              }
              int8_t v356 = v345[v346];	// L636
              v322[v333][v346][(v334 - 2)][(v335 - 2)] = v356;	// L637
            }
          }
        }
      }
    }
  }
  return ;	// L644
}

void main_graph_node16(
  int8_t v357[1][256][8][8],
  int8_t v358[256][256][3][3],
  int8_t v359[1][256][8][8]
) {	// L646
  #pragma HLS dataflow

  int8_t v360[1][256][10][10];	// L648
  #pragma HLS stream variable=v360 depth=10 type=fifo

  #pragma HLS bind_storage variable=v360 type=ram_t2p impl=bram

  for (int v361 = 0; v361 < 1; v361 += 1) {	// L649
    for (int v362 = 0; v362 < 10; v362 += 1) {	// L650
      for (int v363 = 0; v363 < 10; v363 += 1) {	// L651
        for (int v364 = 0; v364 < 256; v364 += 1) {	// L652
          int8_t v365;	// L653
          v365 = (int8_t)0.000000;	// L654
          if (((-v362) + 7) >= 0 && ((-v363) + 7) >= 0) {	// L655
            int8_t v366 = v357[v361][v364][v362][v363];	// L656
            v365 = v366;	// L657
          }
          int8_t v367 = v365;	// L659
          v360[v361][v364][v362][v363] = v367;	// L660
        }
      }
    }
  }
  int8_t v368[1][256][8][8];	// L665
  #pragma HLS stream variable=v368 depth=10 type=fifo

  #pragma HLS bind_storage variable=v368 type=ram_t2p impl=bram

  int8_t v369[1][256][3][10];	// L666
  #pragma HLS array_partition variable=v369 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v369 type=ram_2p impl=bram

  int8_t v370[1][256][3][3];	// L667
  #pragma HLS array_partition variable=v370 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v370 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v370 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v370 type=ram_2p impl=lutram

  for (int v371 = 0; v371 < 1; v371 += 1) {	// L668
    for (int v372 = 0; v372 < 10; v372 += 1) {	// L669
      for (int v373 = 0; v373 < 10; v373 += 1) {	// L670
        for (int v374 = 0; v374 < 256; v374 += 1) {	// L671
          int8_t v375 = v369[v371][v374][1][v373];	// L672
          v369[v371][v374][0][v373] = v375;	// L673
          int8_t v376 = v369[v371][v374][2][v373];	// L674
          v369[v371][v374][1][v373] = v376;	// L675
          int8_t v377 = v360[v371][v374][v372][v373];	// L676
          v369[v371][v374][2][v373] = v377;	// L677
        }
        if ((v372 - 2) >= 0) {	// L679
          for (int v378 = 0; v378 < 256; v378 += 1) {	// L680
            for (int v379 = 0; v379 < 3; v379 += 1) {	// L681
              int8_t v380 = v370[v371][v378][v379][1];	// L682
              v370[v371][v378][v379][0] = v380;	// L683
              int8_t v381 = v370[v371][v378][v379][2];	// L684
              v370[v371][v378][v379][1] = v381;	// L685
              int8_t v382 = v369[v371][v378][v379][v373];	// L686
              v370[v371][v378][v379][2] = v382;	// L687
            }
          }
          if ((v373 - 2) >= 0) {	// L690
            int8_t v383[256];	// L691
            #pragma HLS bind_storage variable=v383 type=ram_2p impl=bram

            for (int v384 = 0; v384 < 256; v384 += 1) {	// L692
              v383[v384] = (int8_t)0.000000;	// L693
              for (int v385 = 0; v385 < 64; v385 += 1) {	// L694
                #pragma HLS pipeline II=1
                for (int v386 = 0; v386 < 4; v386 += 1) {	// L695
                  for (int v387 = 0; v387 < 3; v387 += 1) {	// L696
                    for (int v388 = 0; v388 < 3; v388 += 1) {	// L697
                      int8_t v389 = v370[v371][(v386 + (v385 * 4))][v387][v388];	// L698
                      int8_t v390 = v358[v384][(v386 + (v385 * 4))][v387][v388];	// L699
                      int8_t v391 = v389 * v390;	// L700
                      int8_t v392 = v383[v384];	// L701
                      int8_t v393 = v392 + v391;	// L702
                      v383[v384] = v393;	// L703
                    }
                  }
                }
              }
              int8_t v394 = v383[v384];	// L708
              v368[v371][v384][(v372 - 2)][(v373 - 2)] = v394;	// L709
            }
          }
        }
      }
    }
  }
  for (int v395 = 0; v395 < 1; v395 += 1) {	// L716
    for (int v396 = 0; v396 < 8; v396 += 1) {	// L717
      for (int v397 = 0; v397 < 8; v397 += 1) {	// L718
        for (int v398 = 0; v398 < 256; v398 += 1) {	// L719
          int8_t v399 = v368[0][v398][v396][v397];	// L720
          bool v400 = v399 > (int8_t)0.000000;	// L721
          int8_t v401 = v400 ? v399 : (int8_t)0.000000;	// L722
          v359[v395][v398][v396][v397] = v401;	// L723
        }
      }
    }
  }
  return ;	// L728
}

void main_graph_node17(
  int8_t v402[1][256][8][8],
  int8_t v403[1][256][8][8],
  int8_t v404[1][256][8][8]
) {	// L730
  #pragma HLS dataflow

  for (int v405 = 0; v405 < 1; v405 += 1) {	// L731
    for (int v406 = 0; v406 < 8; v406 += 1) {	// L732
      for (int v407 = 0; v407 < 8; v407 += 1) {	// L733
        for (int v408 = 0; v408 < 256; v408 += 1) {	// L734
          int8_t v409 = v402[v405][v408][v406][v407];	// L735
          v403[v405][v408][v406][v407] = v409;	// L736
          int8_t v410 = v402[v405][v408][v406][v407];	// L737
          v404[v405][v408][v406][v407] = v410;	// L738
        }
      }
    }
  }
  return ;	// L743
}

void main_graph_node18(
  int8_t v411[1][256][8][8],
  int8_t v412[1][256][8][8],
  int8_t v413[1][256][8][8]
) {	// L745
  #pragma HLS dataflow

  for (int v414 = 0; v414 < 1; v414 += 1) {	// L747
    for (int v415 = 0; v415 < 8; v415 += 1) {	// L748
      for (int v416 = 0; v416 < 8; v416 += 1) {	// L749
        for (int v417 = 0; v417 < 256; v417 += 1) {	// L750
          int8_t v418 = v411[0][v417][v415][v416];	// L751
          int8_t v419 = v412[0][v417][v415][v416];	// L752
          int8_t v420 = v418 + v419;	// L753
          bool v421 = v420 > (int8_t)0.000000;	// L754
          int8_t v422 = v421 ? v420 : (int8_t)0.000000;	// L755
          v413[v414][v417][v415][v416] = v422;	// L756
        }
      }
    }
  }
  return ;	// L761
}

void main_graph_node19(
  int8_t v423[256][128][1][1],
  int8_t v424[1][128][16][16],
  int8_t v425[1][256][8][8]
) {	// L763
  #pragma HLS dataflow

  int8_t v426[1][128][1][16];	// L765
  #pragma HLS bind_storage variable=v426 type=ram_2p impl=bram

  int8_t v427[1][128][1][1];	// L766
  #pragma HLS array_partition variable=v427 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v427 type=ram_2p impl=lutram

  for (int v428 = 0; v428 < 1; v428 += 1) {	// L767
    for (int v429 = 0; v429 < 16; v429 += 1) {	// L768
      for (int v430 = 0; v430 < 16; v430 += 1) {	// L769
        for (int v431 = 0; v431 < 128; v431 += 1) {	// L770
          int8_t v432 = v424[v428][v431][v429][v430];	// L771
          v426[v428][v431][0][v430] = v432;	// L772
        }
        if ((v429 - 8) >= 0) {	// L774
          for (int v433 = 0; v433 < 128; v433 += 1) {	// L775
            for (int v434 = 0; v434 < 1; v434 += 1) {	// L776
              int8_t v435 = v426[v428][v433][v434][v430];	// L777
              v427[v428][v433][v434][0] = v435;	// L778
            }
          }
          if ((v430 - 8) >= 0) {	// L781
            int8_t v436[256];	// L782
            #pragma HLS bind_storage variable=v436 type=ram_2p impl=bram

            for (int v437 = 0; v437 < 256; v437 += 1) {	// L783
              v436[v437] = (int8_t)0.000000;	// L784
              for (int v438 = 0; v438 < 16; v438 += 1) {	// L785
                #pragma HLS pipeline II=1
                for (int v439 = 0; v439 < 8; v439 += 1) {	// L786
                  for (int v440 = 0; v440 < 1; v440 += 1) {	// L787
                    for (int v441 = 0; v441 < 1; v441 += 1) {	// L788
                      int8_t v442 = v427[v428][(v439 + (v438 * 8))][v440][v441];	// L789
                      int8_t v443 = v423[v437][(v439 + (v438 * 8))][v440][v441];	// L790
                      int8_t v444 = v442 * v443;	// L791
                      int8_t v445 = v436[v437];	// L792
                      int8_t v446 = v445 + v444;	// L793
                      v436[v437] = v446;	// L794
                    }
                  }
                }
              }
              int8_t v447 = v436[v437];	// L799
              v425[v428][v437][(v429 - 8)][(v430 - 8)] = v447;	// L800
            }
          }
        }
      }
    }
  }
  return ;	// L807
}

void main_graph_node20(
  int8_t v448[256][256][3][3],
  int8_t v449[1][256][8][8],
  int8_t v450[1][256][8][8]
) {	// L809
  #pragma HLS dataflow

  int8_t v451[1][256][10][10];	// L811
  #pragma HLS stream variable=v451 depth=10 type=fifo

  #pragma HLS bind_storage variable=v451 type=ram_t2p impl=bram

  for (int v452 = 0; v452 < 1; v452 += 1) {	// L812
    for (int v453 = 0; v453 < 10; v453 += 1) {	// L813
      for (int v454 = 0; v454 < 10; v454 += 1) {	// L814
        for (int v455 = 0; v455 < 256; v455 += 1) {	// L815
          int8_t v456;	// L816
          v456 = (int8_t)0.000000;	// L817
          if (((-v453) + 7) >= 0 && ((-v454) + 7) >= 0) {	// L818
            int8_t v457 = v449[v452][v455][v453][v454];	// L819
            v456 = v457;	// L820
          }
          int8_t v458 = v456;	// L822
          v451[v452][v455][v453][v454] = v458;	// L823
        }
      }
    }
  }
  int8_t v459[1][256][3][10];	// L828
  #pragma HLS array_partition variable=v459 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v459 type=ram_2p impl=bram

  int8_t v460[1][256][3][3];	// L829
  #pragma HLS array_partition variable=v460 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v460 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v460 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v460 type=ram_2p impl=lutram

  for (int v461 = 0; v461 < 1; v461 += 1) {	// L830
    for (int v462 = 0; v462 < 10; v462 += 1) {	// L831
      for (int v463 = 0; v463 < 10; v463 += 1) {	// L832
        for (int v464 = 0; v464 < 256; v464 += 1) {	// L833
          int8_t v465 = v459[v461][v464][1][v463];	// L834
          v459[v461][v464][0][v463] = v465;	// L835
          int8_t v466 = v459[v461][v464][2][v463];	// L836
          v459[v461][v464][1][v463] = v466;	// L837
          int8_t v467 = v451[v461][v464][v462][v463];	// L838
          v459[v461][v464][2][v463] = v467;	// L839
        }
        if ((v462 - 2) >= 0) {	// L841
          for (int v468 = 0; v468 < 256; v468 += 1) {	// L842
            for (int v469 = 0; v469 < 3; v469 += 1) {	// L843
              int8_t v470 = v460[v461][v468][v469][1];	// L844
              v460[v461][v468][v469][0] = v470;	// L845
              int8_t v471 = v460[v461][v468][v469][2];	// L846
              v460[v461][v468][v469][1] = v471;	// L847
              int8_t v472 = v459[v461][v468][v469][v463];	// L848
              v460[v461][v468][v469][2] = v472;	// L849
            }
          }
          if ((v463 - 2) >= 0) {	// L852
            int8_t v473[256];	// L853
            #pragma HLS bind_storage variable=v473 type=ram_2p impl=bram

            for (int v474 = 0; v474 < 256; v474 += 1) {	// L854
              v473[v474] = (int8_t)0.000000;	// L855
              for (int v475 = 0; v475 < 64; v475 += 1) {	// L856
                #pragma HLS pipeline II=1
                for (int v476 = 0; v476 < 4; v476 += 1) {	// L857
                  for (int v477 = 0; v477 < 3; v477 += 1) {	// L858
                    for (int v478 = 0; v478 < 3; v478 += 1) {	// L859
                      int8_t v479 = v460[v461][(v476 + (v475 * 4))][v477][v478];	// L860
                      int8_t v480 = v448[v474][(v476 + (v475 * 4))][v477][v478];	// L861
                      int8_t v481 = v479 * v480;	// L862
                      int8_t v482 = v473[v474];	// L863
                      int8_t v483 = v482 + v481;	// L864
                      v473[v474] = v483;	// L865
                    }
                  }
                }
              }
              int8_t v484 = v473[v474];	// L870
              v450[v461][v474][(v462 - 2)][(v463 - 2)] = v484;	// L871
            }
          }
        }
      }
    }
  }
  return ;	// L878
}

void main_graph_node21(
  int8_t v485[256][128][3][3],
  int8_t v486[1][128][16][16],
  int8_t v487[1][256][8][8]
) {	// L880
  #pragma HLS dataflow

  int8_t v488[1][128][18][18];	// L882
  #pragma HLS stream variable=v488 depth=10 type=fifo

  #pragma HLS bind_storage variable=v488 type=ram_t2p impl=bram

  for (int v489 = 0; v489 < 1; v489 += 1) {	// L883
    for (int v490 = 0; v490 < 18; v490 += 1) {	// L884
      for (int v491 = 0; v491 < 18; v491 += 1) {	// L885
        for (int v492 = 0; v492 < 128; v492 += 1) {	// L886
          int8_t v493;	// L887
          v493 = (int8_t)0.000000;	// L888
          if (((-v490) + 15) >= 0 && ((-v491) + 15) >= 0) {	// L889
            int8_t v494 = v486[v489][v492][v490][v491];	// L890
            v493 = v494;	// L891
          }
          int8_t v495 = v493;	// L893
          v488[v489][v492][v490][v491] = v495;	// L894
        }
      }
    }
  }
  int8_t v496[1][256][8][8];	// L899
  #pragma HLS stream variable=v496 depth=10 type=fifo

  #pragma HLS bind_storage variable=v496 type=ram_t2p impl=bram

  int8_t v497[1][128][3][18];	// L900
  #pragma HLS array_partition variable=v497 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v497 type=ram_2p impl=bram

  int8_t v498[1][128][3][3];	// L901
  #pragma HLS array_partition variable=v498 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v498 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v498 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v498 type=ram_2p impl=lutram

  for (int v499 = 0; v499 < 1; v499 += 1) {	// L902
    for (int v500 = 0; v500 < 18; v500 += 1) {	// L903
      for (int v501 = 0; v501 < 18; v501 += 1) {	// L904
        for (int v502 = 0; v502 < 128; v502 += 1) {	// L905
          int8_t v503 = v497[v499][v502][1][v501];	// L906
          v497[v499][v502][0][v501] = v503;	// L907
          int8_t v504 = v497[v499][v502][2][v501];	// L908
          v497[v499][v502][1][v501] = v504;	// L909
          int8_t v505 = v488[v499][v502][v500][v501];	// L910
          v497[v499][v502][2][v501] = v505;	// L911
        }
        if ((v500 - 10) >= 0) {	// L913
          for (int v506 = 0; v506 < 128; v506 += 1) {	// L914
            for (int v507 = 0; v507 < 3; v507 += 1) {	// L915
              int8_t v508 = v498[v499][v506][v507][1];	// L916
              v498[v499][v506][v507][0] = v508;	// L917
              int8_t v509 = v498[v499][v506][v507][2];	// L918
              v498[v499][v506][v507][1] = v509;	// L919
              int8_t v510 = v497[v499][v506][v507][v501];	// L920
              v498[v499][v506][v507][2] = v510;	// L921
            }
          }
          if ((v501 - 10) >= 0) {	// L924
            int8_t v511[256];	// L925
            #pragma HLS bind_storage variable=v511 type=ram_2p impl=bram

            for (int v512 = 0; v512 < 256; v512 += 1) {	// L926
              v511[v512] = (int8_t)0.000000;	// L927
              for (int v513 = 0; v513 < 16; v513 += 1) {	// L928
                #pragma HLS pipeline II=1
                for (int v514 = 0; v514 < 8; v514 += 1) {	// L929
                  for (int v515 = 0; v515 < 3; v515 += 1) {	// L930
                    for (int v516 = 0; v516 < 3; v516 += 1) {	// L931
                      int8_t v517 = v498[v499][(v514 + (v513 * 8))][v515][v516];	// L932
                      int8_t v518 = v485[v512][(v514 + (v513 * 8))][v515][v516];	// L933
                      int8_t v519 = v517 * v518;	// L934
                      int8_t v520 = v511[v512];	// L935
                      int8_t v521 = v520 + v519;	// L936
                      v511[v512] = v521;	// L937
                    }
                  }
                }
              }
              int8_t v522 = v511[v512];	// L942
              v496[v499][v512][(v500 - 10)][(v501 - 10)] = v522;	// L943
            }
          }
        }
      }
    }
  }
  for (int v523 = 0; v523 < 1; v523 += 1) {	// L950
    for (int v524 = 0; v524 < 8; v524 += 1) {	// L951
      for (int v525 = 0; v525 < 8; v525 += 1) {	// L952
        for (int v526 = 0; v526 < 256; v526 += 1) {	// L953
          int8_t v527 = v496[0][v526][v524][v525];	// L954
          bool v528 = v527 > (int8_t)0.000000;	// L955
          int8_t v529 = v528 ? v527 : (int8_t)0.000000;	// L956
          v487[v523][v526][v524][v525] = v529;	// L957
        }
      }
    }
  }
  return ;	// L962
}

void main_graph_node22(
  int8_t v530[1][128][16][16],
  int8_t v531[1][128][16][16],
  int8_t v532[1][128][16][16]
) {	// L964
  #pragma HLS dataflow

  for (int v533 = 0; v533 < 1; v533 += 1) {	// L965
    for (int v534 = 0; v534 < 16; v534 += 1) {	// L966
      for (int v535 = 0; v535 < 16; v535 += 1) {	// L967
        for (int v536 = 0; v536 < 128; v536 += 1) {	// L968
          int8_t v537 = v530[v533][v536][v534][v535];	// L969
          v531[v533][v536][v534][v535] = v537;	// L970
          int8_t v538 = v530[v533][v536][v534][v535];	// L971
          v532[v533][v536][v534][v535] = v538;	// L972
        }
      }
    }
  }
  return ;	// L977
}

void main_graph_node23(
  int8_t v539[1][128][16][16],
  int8_t v540[1][128][16][16],
  int8_t v541[1][128][16][16]
) {	// L979
  #pragma HLS dataflow

  for (int v542 = 0; v542 < 1; v542 += 1) {	// L981
    for (int v543 = 0; v543 < 16; v543 += 1) {	// L982
      for (int v544 = 0; v544 < 16; v544 += 1) {	// L983
        for (int v545 = 0; v545 < 128; v545 += 1) {	// L984
          int8_t v546 = v539[0][v545][v543][v544];	// L985
          int8_t v547 = v540[0][v545][v543][v544];	// L986
          int8_t v548 = v546 + v547;	// L987
          bool v549 = v548 > (int8_t)0.000000;	// L988
          int8_t v550 = v549 ? v548 : (int8_t)0.000000;	// L989
          v541[v542][v545][v543][v544] = v550;	// L990
        }
      }
    }
  }
  return ;	// L995
}

void main_graph_node24(
  int8_t v551[128][128][3][3],
  int8_t v552[1][128][16][16],
  int8_t v553[1][128][16][16]
) {	// L997
  #pragma HLS dataflow

  int8_t v554[1][128][18][18];	// L999
  #pragma HLS stream variable=v554 depth=10 type=fifo

  #pragma HLS bind_storage variable=v554 type=ram_t2p impl=bram

  for (int v555 = 0; v555 < 1; v555 += 1) {	// L1000
    for (int v556 = 0; v556 < 18; v556 += 1) {	// L1001
      for (int v557 = 0; v557 < 18; v557 += 1) {	// L1002
        for (int v558 = 0; v558 < 128; v558 += 1) {	// L1003
          int8_t v559;	// L1004
          v559 = (int8_t)0.000000;	// L1005
          if (((-v556) + 15) >= 0 && ((-v557) + 15) >= 0) {	// L1006
            int8_t v560 = v552[v555][v558][v556][v557];	// L1007
            v559 = v560;	// L1008
          }
          int8_t v561 = v559;	// L1010
          v554[v555][v558][v556][v557] = v561;	// L1011
        }
      }
    }
  }
  int8_t v562[1][128][3][18];	// L1016
  #pragma HLS array_partition variable=v562 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v562 type=ram_2p impl=bram

  int8_t v563[1][128][3][3];	// L1017
  #pragma HLS array_partition variable=v563 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v563 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v563 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v563 type=ram_2p impl=lutram

  for (int v564 = 0; v564 < 1; v564 += 1) {	// L1018
    for (int v565 = 0; v565 < 18; v565 += 1) {	// L1019
      for (int v566 = 0; v566 < 18; v566 += 1) {	// L1020
        for (int v567 = 0; v567 < 128; v567 += 1) {	// L1021
          int8_t v568 = v562[v564][v567][1][v566];	// L1022
          v562[v564][v567][0][v566] = v568;	// L1023
          int8_t v569 = v562[v564][v567][2][v566];	// L1024
          v562[v564][v567][1][v566] = v569;	// L1025
          int8_t v570 = v554[v564][v567][v565][v566];	// L1026
          v562[v564][v567][2][v566] = v570;	// L1027
        }
        if ((v565 - 2) >= 0) {	// L1029
          for (int v571 = 0; v571 < 128; v571 += 1) {	// L1030
            for (int v572 = 0; v572 < 3; v572 += 1) {	// L1031
              int8_t v573 = v563[v564][v571][v572][1];	// L1032
              v563[v564][v571][v572][0] = v573;	// L1033
              int8_t v574 = v563[v564][v571][v572][2];	// L1034
              v563[v564][v571][v572][1] = v574;	// L1035
              int8_t v575 = v562[v564][v571][v572][v566];	// L1036
              v563[v564][v571][v572][2] = v575;	// L1037
            }
          }
          if ((v566 - 2) >= 0) {	// L1040
            int8_t v576[128];	// L1041
            #pragma HLS bind_storage variable=v576 type=ram_2p impl=bram

            for (int v577 = 0; v577 < 128; v577 += 1) {	// L1042
              v576[v577] = (int8_t)0.000000;	// L1043
              for (int v578 = 0; v578 < 32; v578 += 1) {	// L1044
                #pragma HLS pipeline II=1
                for (int v579 = 0; v579 < 4; v579 += 1) {	// L1045
                  for (int v580 = 0; v580 < 3; v580 += 1) {	// L1046
                    for (int v581 = 0; v581 < 3; v581 += 1) {	// L1047
                      int8_t v582 = v563[v564][(v579 + (v578 * 4))][v580][v581];	// L1048
                      int8_t v583 = v551[v577][(v579 + (v578 * 4))][v580][v581];	// L1049
                      int8_t v584 = v582 * v583;	// L1050
                      int8_t v585 = v576[v577];	// L1051
                      int8_t v586 = v585 + v584;	// L1052
                      v576[v577] = v586;	// L1053
                    }
                  }
                }
              }
              int8_t v587 = v576[v577];	// L1058
              v553[v564][v577][(v565 - 2)][(v566 - 2)] = v587;	// L1059
            }
          }
        }
      }
    }
  }
  return ;	// L1066
}

void main_graph_node25(
  int8_t v588[128][128][3][3],
  int8_t v589[1][128][16][16],
  int8_t v590[1][128][16][16]
) {	// L1068
  #pragma HLS dataflow

  int8_t v591[1][128][18][18];	// L1070
  #pragma HLS stream variable=v591 depth=10 type=fifo

  #pragma HLS bind_storage variable=v591 type=ram_t2p impl=bram

  for (int v592 = 0; v592 < 1; v592 += 1) {	// L1071
    for (int v593 = 0; v593 < 18; v593 += 1) {	// L1072
      for (int v594 = 0; v594 < 18; v594 += 1) {	// L1073
        for (int v595 = 0; v595 < 128; v595 += 1) {	// L1074
          int8_t v596;	// L1075
          v596 = (int8_t)0.000000;	// L1076
          if (((-v593) + 15) >= 0 && ((-v594) + 15) >= 0) {	// L1077
            int8_t v597 = v589[v592][v595][v593][v594];	// L1078
            v596 = v597;	// L1079
          }
          int8_t v598 = v596;	// L1081
          v591[v592][v595][v593][v594] = v598;	// L1082
        }
      }
    }
  }
  int8_t v599[1][128][16][16];	// L1087
  #pragma HLS stream variable=v599 depth=10 type=fifo

  #pragma HLS bind_storage variable=v599 type=ram_t2p impl=bram

  int8_t v600[1][128][3][18];	// L1088
  #pragma HLS array_partition variable=v600 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v600 type=ram_2p impl=bram

  int8_t v601[1][128][3][3];	// L1089
  #pragma HLS array_partition variable=v601 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v601 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v601 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v601 type=ram_2p impl=lutram

  for (int v602 = 0; v602 < 1; v602 += 1) {	// L1090
    for (int v603 = 0; v603 < 18; v603 += 1) {	// L1091
      for (int v604 = 0; v604 < 18; v604 += 1) {	// L1092
        for (int v605 = 0; v605 < 128; v605 += 1) {	// L1093
          int8_t v606 = v600[v602][v605][1][v604];	// L1094
          v600[v602][v605][0][v604] = v606;	// L1095
          int8_t v607 = v600[v602][v605][2][v604];	// L1096
          v600[v602][v605][1][v604] = v607;	// L1097
          int8_t v608 = v591[v602][v605][v603][v604];	// L1098
          v600[v602][v605][2][v604] = v608;	// L1099
        }
        if ((v603 - 2) >= 0) {	// L1101
          for (int v609 = 0; v609 < 128; v609 += 1) {	// L1102
            for (int v610 = 0; v610 < 3; v610 += 1) {	// L1103
              int8_t v611 = v601[v602][v609][v610][1];	// L1104
              v601[v602][v609][v610][0] = v611;	// L1105
              int8_t v612 = v601[v602][v609][v610][2];	// L1106
              v601[v602][v609][v610][1] = v612;	// L1107
              int8_t v613 = v600[v602][v609][v610][v604];	// L1108
              v601[v602][v609][v610][2] = v613;	// L1109
            }
          }
          if ((v604 - 2) >= 0) {	// L1112
            int8_t v614[128];	// L1113
            #pragma HLS bind_storage variable=v614 type=ram_2p impl=bram

            for (int v615 = 0; v615 < 128; v615 += 1) {	// L1114
              v614[v615] = (int8_t)0.000000;	// L1115
              for (int v616 = 0; v616 < 32; v616 += 1) {	// L1116
                #pragma HLS pipeline II=1
                for (int v617 = 0; v617 < 4; v617 += 1) {	// L1117
                  for (int v618 = 0; v618 < 3; v618 += 1) {	// L1118
                    for (int v619 = 0; v619 < 3; v619 += 1) {	// L1119
                      int8_t v620 = v601[v602][(v617 + (v616 * 4))][v618][v619];	// L1120
                      int8_t v621 = v588[v615][(v617 + (v616 * 4))][v618][v619];	// L1121
                      int8_t v622 = v620 * v621;	// L1122
                      int8_t v623 = v614[v615];	// L1123
                      int8_t v624 = v623 + v622;	// L1124
                      v614[v615] = v624;	// L1125
                    }
                  }
                }
              }
              int8_t v625 = v614[v615];	// L1130
              v599[v602][v615][(v603 - 2)][(v604 - 2)] = v625;	// L1131
            }
          }
        }
      }
    }
  }
  for (int v626 = 0; v626 < 1; v626 += 1) {	// L1138
    for (int v627 = 0; v627 < 16; v627 += 1) {	// L1139
      for (int v628 = 0; v628 < 16; v628 += 1) {	// L1140
        for (int v629 = 0; v629 < 128; v629 += 1) {	// L1141
          int8_t v630 = v599[0][v629][v627][v628];	// L1142
          bool v631 = v630 > (int8_t)0.000000;	// L1143
          int8_t v632 = v631 ? v630 : (int8_t)0.000000;	// L1144
          v590[v626][v629][v627][v628] = v632;	// L1145
        }
      }
    }
  }
  return ;	// L1150
}

void main_graph_node26(
  int8_t v633[1][128][16][16],
  int8_t v634[1][128][16][16],
  int8_t v635[1][128][16][16]
) {	// L1152
  #pragma HLS dataflow

  for (int v636 = 0; v636 < 1; v636 += 1) {	// L1153
    for (int v637 = 0; v637 < 16; v637 += 1) {	// L1154
      for (int v638 = 0; v638 < 16; v638 += 1) {	// L1155
        for (int v639 = 0; v639 < 128; v639 += 1) {	// L1156
          int8_t v640 = v633[v636][v639][v637][v638];	// L1157
          v634[v636][v639][v637][v638] = v640;	// L1158
          int8_t v641 = v633[v636][v639][v637][v638];	// L1159
          v635[v636][v639][v637][v638] = v641;	// L1160
        }
      }
    }
  }
  return ;	// L1165
}

void main_graph_node27(
  int8_t v642[1][128][16][16],
  int8_t v643[1][128][16][16],
  int8_t v644[1][128][16][16]
) {	// L1167
  #pragma HLS dataflow

  for (int v645 = 0; v645 < 1; v645 += 1) {	// L1169
    for (int v646 = 0; v646 < 16; v646 += 1) {	// L1170
      for (int v647 = 0; v647 < 16; v647 += 1) {	// L1171
        for (int v648 = 0; v648 < 128; v648 += 1) {	// L1172
          int8_t v649 = v642[0][v648][v646][v647];	// L1173
          int8_t v650 = v643[0][v648][v646][v647];	// L1174
          int8_t v651 = v649 + v650;	// L1175
          bool v652 = v651 > (int8_t)0.000000;	// L1176
          int8_t v653 = v652 ? v651 : (int8_t)0.000000;	// L1177
          v644[v645][v648][v646][v647] = v653;	// L1178
        }
      }
    }
  }
  return ;	// L1183
}

void main_graph_node28(
  int8_t v654[128][64][1][1],
  int8_t v655[1][64][32][32],
  int8_t v656[1][128][16][16]
) {	// L1185
  #pragma HLS dataflow

  int8_t v657[1][64][1][32];	// L1187
  #pragma HLS bind_storage variable=v657 type=ram_2p impl=bram

  int8_t v658[1][64][1][1];	// L1188
  #pragma HLS array_partition variable=v658 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v658 type=ram_2p impl=lutram

  for (int v659 = 0; v659 < 1; v659 += 1) {	// L1189
    for (int v660 = 0; v660 < 32; v660 += 1) {	// L1190
      for (int v661 = 0; v661 < 32; v661 += 1) {	// L1191
        for (int v662 = 0; v662 < 64; v662 += 1) {	// L1192
          int8_t v663 = v655[v659][v662][v660][v661];	// L1193
          v657[v659][v662][0][v661] = v663;	// L1194
        }
        if ((v660 - 16) >= 0) {	// L1196
          for (int v664 = 0; v664 < 64; v664 += 1) {	// L1197
            for (int v665 = 0; v665 < 1; v665 += 1) {	// L1198
              int8_t v666 = v657[v659][v664][v665][v661];	// L1199
              v658[v659][v664][v665][0] = v666;	// L1200
            }
          }
          if ((v661 - 16) >= 0) {	// L1203
            int8_t v667[128];	// L1204
            #pragma HLS bind_storage variable=v667 type=ram_2p impl=bram

            for (int v668 = 0; v668 < 128; v668 += 1) {	// L1205
              v667[v668] = (int8_t)0.000000;	// L1206
              for (int v669 = 0; v669 < 8; v669 += 1) {	// L1207
                #pragma HLS pipeline II=1
                for (int v670 = 0; v670 < 8; v670 += 1) {	// L1208
                  for (int v671 = 0; v671 < 1; v671 += 1) {	// L1209
                    for (int v672 = 0; v672 < 1; v672 += 1) {	// L1210
                      int8_t v673 = v658[v659][(v670 + (v669 * 8))][v671][v672];	// L1211
                      int8_t v674 = v654[v668][(v670 + (v669 * 8))][v671][v672];	// L1212
                      int8_t v675 = v673 * v674;	// L1213
                      int8_t v676 = v667[v668];	// L1214
                      int8_t v677 = v676 + v675;	// L1215
                      v667[v668] = v677;	// L1216
                    }
                  }
                }
              }
              int8_t v678 = v667[v668];	// L1221
              v656[v659][v668][(v660 - 16)][(v661 - 16)] = v678;	// L1222
            }
          }
        }
      }
    }
  }
  return ;	// L1229
}

void main_graph_node29(
  int8_t v679[1][128][16][16],
  int8_t v680[128][128][3][3],
  int8_t v681[1][128][16][16]
) {	// L1231
  #pragma HLS dataflow

  int8_t v682[1][128][18][18];	// L1233
  #pragma HLS stream variable=v682 depth=10 type=fifo

  #pragma HLS bind_storage variable=v682 type=ram_t2p impl=bram

  for (int v683 = 0; v683 < 1; v683 += 1) {	// L1234
    for (int v684 = 0; v684 < 18; v684 += 1) {	// L1235
      for (int v685 = 0; v685 < 18; v685 += 1) {	// L1236
        for (int v686 = 0; v686 < 128; v686 += 1) {	// L1237
          int8_t v687;	// L1238
          v687 = (int8_t)0.000000;	// L1239
          if (((-v684) + 15) >= 0 && ((-v685) + 15) >= 0) {	// L1240
            int8_t v688 = v679[v683][v686][v684][v685];	// L1241
            v687 = v688;	// L1242
          }
          int8_t v689 = v687;	// L1244
          v682[v683][v686][v684][v685] = v689;	// L1245
        }
      }
    }
  }
  int8_t v690[1][128][3][18];	// L1250
  #pragma HLS array_partition variable=v690 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v690 type=ram_2p impl=bram

  int8_t v691[1][128][3][3];	// L1251
  #pragma HLS array_partition variable=v691 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v691 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v691 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v691 type=ram_2p impl=lutram

  for (int v692 = 0; v692 < 1; v692 += 1) {	// L1252
    for (int v693 = 0; v693 < 18; v693 += 1) {	// L1253
      for (int v694 = 0; v694 < 18; v694 += 1) {	// L1254
        for (int v695 = 0; v695 < 128; v695 += 1) {	// L1255
          int8_t v696 = v690[v692][v695][1][v694];	// L1256
          v690[v692][v695][0][v694] = v696;	// L1257
          int8_t v697 = v690[v692][v695][2][v694];	// L1258
          v690[v692][v695][1][v694] = v697;	// L1259
          int8_t v698 = v682[v692][v695][v693][v694];	// L1260
          v690[v692][v695][2][v694] = v698;	// L1261
        }
        if ((v693 - 2) >= 0) {	// L1263
          for (int v699 = 0; v699 < 128; v699 += 1) {	// L1264
            for (int v700 = 0; v700 < 3; v700 += 1) {	// L1265
              int8_t v701 = v691[v692][v699][v700][1];	// L1266
              v691[v692][v699][v700][0] = v701;	// L1267
              int8_t v702 = v691[v692][v699][v700][2];	// L1268
              v691[v692][v699][v700][1] = v702;	// L1269
              int8_t v703 = v690[v692][v699][v700][v694];	// L1270
              v691[v692][v699][v700][2] = v703;	// L1271
            }
          }
          if ((v694 - 2) >= 0) {	// L1274
            int8_t v704[128];	// L1275
            #pragma HLS bind_storage variable=v704 type=ram_2p impl=bram

            for (int v705 = 0; v705 < 128; v705 += 1) {	// L1276
              v704[v705] = (int8_t)0.000000;	// L1277
              for (int v706 = 0; v706 < 32; v706 += 1) {	// L1278
                #pragma HLS pipeline II=1
                for (int v707 = 0; v707 < 4; v707 += 1) {	// L1279
                  for (int v708 = 0; v708 < 3; v708 += 1) {	// L1280
                    for (int v709 = 0; v709 < 3; v709 += 1) {	// L1281
                      int8_t v710 = v691[v692][(v707 + (v706 * 4))][v708][v709];	// L1282
                      int8_t v711 = v680[v705][(v707 + (v706 * 4))][v708][v709];	// L1283
                      int8_t v712 = v710 * v711;	// L1284
                      int8_t v713 = v704[v705];	// L1285
                      int8_t v714 = v713 + v712;	// L1286
                      v704[v705] = v714;	// L1287
                    }
                  }
                }
              }
              int8_t v715 = v704[v705];	// L1292
              v681[v692][v705][(v693 - 2)][(v694 - 2)] = v715;	// L1293
            }
          }
        }
      }
    }
  }
  return ;	// L1300
}

void main_graph_node30(
  int8_t v716[128][64][3][3],
  int8_t v717[1][64][32][32],
  int8_t v718[1][128][16][16]
) {	// L1302
  #pragma HLS dataflow

  int8_t v719[1][64][34][34];	// L1304
  #pragma HLS stream variable=v719 depth=10 type=fifo

  #pragma HLS bind_storage variable=v719 type=ram_t2p impl=bram

  for (int v720 = 0; v720 < 1; v720 += 1) {	// L1305
    for (int v721 = 0; v721 < 34; v721 += 1) {	// L1306
      for (int v722 = 0; v722 < 34; v722 += 1) {	// L1307
        for (int v723 = 0; v723 < 64; v723 += 1) {	// L1308
          int8_t v724;	// L1309
          v724 = (int8_t)0.000000;	// L1310
          if (((-v721) + 31) >= 0 && ((-v722) + 31) >= 0) {	// L1311
            int8_t v725 = v717[v720][v723][v721][v722];	// L1312
            v724 = v725;	// L1313
          }
          int8_t v726 = v724;	// L1315
          v719[v720][v723][v721][v722] = v726;	// L1316
        }
      }
    }
  }
  int8_t v727[1][128][16][16];	// L1321
  #pragma HLS stream variable=v727 depth=10 type=fifo

  #pragma HLS bind_storage variable=v727 type=ram_t2p impl=bram

  int8_t v728[1][64][3][34];	// L1322
  #pragma HLS array_partition variable=v728 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v728 type=ram_2p impl=bram

  int8_t v729[1][64][3][3];	// L1323
  #pragma HLS array_partition variable=v729 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v729 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v729 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v729 type=ram_2p impl=lutram

  for (int v730 = 0; v730 < 1; v730 += 1) {	// L1324
    for (int v731 = 0; v731 < 34; v731 += 1) {	// L1325
      for (int v732 = 0; v732 < 34; v732 += 1) {	// L1326
        for (int v733 = 0; v733 < 64; v733 += 1) {	// L1327
          int8_t v734 = v728[v730][v733][1][v732];	// L1328
          v728[v730][v733][0][v732] = v734;	// L1329
          int8_t v735 = v728[v730][v733][2][v732];	// L1330
          v728[v730][v733][1][v732] = v735;	// L1331
          int8_t v736 = v719[v730][v733][v731][v732];	// L1332
          v728[v730][v733][2][v732] = v736;	// L1333
        }
        if ((v731 - 18) >= 0) {	// L1335
          for (int v737 = 0; v737 < 64; v737 += 1) {	// L1336
            for (int v738 = 0; v738 < 3; v738 += 1) {	// L1337
              int8_t v739 = v729[v730][v737][v738][1];	// L1338
              v729[v730][v737][v738][0] = v739;	// L1339
              int8_t v740 = v729[v730][v737][v738][2];	// L1340
              v729[v730][v737][v738][1] = v740;	// L1341
              int8_t v741 = v728[v730][v737][v738][v732];	// L1342
              v729[v730][v737][v738][2] = v741;	// L1343
            }
          }
          if ((v732 - 18) >= 0) {	// L1346
            int8_t v742[128];	// L1347
            #pragma HLS bind_storage variable=v742 type=ram_2p impl=bram

            for (int v743 = 0; v743 < 128; v743 += 1) {	// L1348
              v742[v743] = (int8_t)0.000000;	// L1349
              for (int v744 = 0; v744 < 8; v744 += 1) {	// L1350
                #pragma HLS pipeline II=1
                for (int v745 = 0; v745 < 8; v745 += 1) {	// L1351
                  for (int v746 = 0; v746 < 3; v746 += 1) {	// L1352
                    for (int v747 = 0; v747 < 3; v747 += 1) {	// L1353
                      int8_t v748 = v729[v730][(v745 + (v744 * 8))][v746][v747];	// L1354
                      int8_t v749 = v716[v743][(v745 + (v744 * 8))][v746][v747];	// L1355
                      int8_t v750 = v748 * v749;	// L1356
                      int8_t v751 = v742[v743];	// L1357
                      int8_t v752 = v751 + v750;	// L1358
                      v742[v743] = v752;	// L1359
                    }
                  }
                }
              }
              int8_t v753 = v742[v743];	// L1364
              v727[v730][v743][(v731 - 18)][(v732 - 18)] = v753;	// L1365
            }
          }
        }
      }
    }
  }
  for (int v754 = 0; v754 < 1; v754 += 1) {	// L1372
    for (int v755 = 0; v755 < 16; v755 += 1) {	// L1373
      for (int v756 = 0; v756 < 16; v756 += 1) {	// L1374
        for (int v757 = 0; v757 < 128; v757 += 1) {	// L1375
          int8_t v758 = v727[0][v757][v755][v756];	// L1376
          bool v759 = v758 > (int8_t)0.000000;	// L1377
          int8_t v760 = v759 ? v758 : (int8_t)0.000000;	// L1378
          v718[v754][v757][v755][v756] = v760;	// L1379
        }
      }
    }
  }
  return ;	// L1384
}

void main_graph_node31(
  int8_t v761[1][64][32][32],
  int8_t v762[1][64][32][32],
  int8_t v763[1][64][32][32]
) {	// L1386
  #pragma HLS dataflow

  for (int v764 = 0; v764 < 1; v764 += 1) {	// L1387
    for (int v765 = 0; v765 < 32; v765 += 1) {	// L1388
      for (int v766 = 0; v766 < 32; v766 += 1) {	// L1389
        for (int v767 = 0; v767 < 64; v767 += 1) {	// L1390
          int8_t v768 = v761[v764][v767][v765][v766];	// L1391
          v762[v764][v767][v765][v766] = v768;	// L1392
          int8_t v769 = v761[v764][v767][v765][v766];	// L1393
          v763[v764][v767][v765][v766] = v769;	// L1394
        }
      }
    }
  }
  return ;	// L1399
}

void main_graph_node32(
  int8_t v770[1][64][32][32],
  int8_t v771[1][64][32][32],
  int8_t v772[1][64][32][32]
) {	// L1401
  #pragma HLS dataflow

  for (int v773 = 0; v773 < 1; v773 += 1) {	// L1403
    for (int v774 = 0; v774 < 32; v774 += 1) {	// L1404
      for (int v775 = 0; v775 < 32; v775 += 1) {	// L1405
        for (int v776 = 0; v776 < 64; v776 += 1) {	// L1406
          int8_t v777 = v770[0][v776][v774][v775];	// L1407
          int8_t v778 = v771[0][v776][v774][v775];	// L1408
          int8_t v779 = v777 + v778;	// L1409
          bool v780 = v779 > (int8_t)0.000000;	// L1410
          int8_t v781 = v780 ? v779 : (int8_t)0.000000;	// L1411
          v772[v773][v776][v774][v775] = v781;	// L1412
        }
      }
    }
  }
  return ;	// L1417
}

void main_graph_node33(
  int8_t v782[64][64][3][3],
  int8_t v783[1][64][32][32],
  int8_t v784[1][64][32][32]
) {	// L1419
  #pragma HLS dataflow

  int8_t v785[1][64][34][34];	// L1421
  #pragma HLS stream variable=v785 depth=10 type=fifo

  #pragma HLS bind_storage variable=v785 type=ram_t2p impl=bram

  for (int v786 = 0; v786 < 1; v786 += 1) {	// L1422
    for (int v787 = 0; v787 < 34; v787 += 1) {	// L1423
      for (int v788 = 0; v788 < 34; v788 += 1) {	// L1424
        for (int v789 = 0; v789 < 64; v789 += 1) {	// L1425
          int8_t v790;	// L1426
          v790 = (int8_t)0.000000;	// L1427
          if (((-v787) + 31) >= 0 && ((-v788) + 31) >= 0) {	// L1428
            int8_t v791 = v783[v786][v789][v787][v788];	// L1429
            v790 = v791;	// L1430
          }
          int8_t v792 = v790;	// L1432
          v785[v786][v789][v787][v788] = v792;	// L1433
        }
      }
    }
  }
  int8_t v793[1][64][3][34];	// L1438
  #pragma HLS array_partition variable=v793 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v793 type=ram_2p impl=bram

  int8_t v794[1][64][3][3];	// L1439
  #pragma HLS array_partition variable=v794 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v794 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v794 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v794 type=ram_2p impl=lutram

  for (int v795 = 0; v795 < 1; v795 += 1) {	// L1440
    for (int v796 = 0; v796 < 34; v796 += 1) {	// L1441
      for (int v797 = 0; v797 < 34; v797 += 1) {	// L1442
        for (int v798 = 0; v798 < 64; v798 += 1) {	// L1443
          int8_t v799 = v793[v795][v798][1][v797];	// L1444
          v793[v795][v798][0][v797] = v799;	// L1445
          int8_t v800 = v793[v795][v798][2][v797];	// L1446
          v793[v795][v798][1][v797] = v800;	// L1447
          int8_t v801 = v785[v795][v798][v796][v797];	// L1448
          v793[v795][v798][2][v797] = v801;	// L1449
        }
        if ((v796 - 2) >= 0) {	// L1451
          for (int v802 = 0; v802 < 64; v802 += 1) {	// L1452
            for (int v803 = 0; v803 < 3; v803 += 1) {	// L1453
              int8_t v804 = v794[v795][v802][v803][1];	// L1454
              v794[v795][v802][v803][0] = v804;	// L1455
              int8_t v805 = v794[v795][v802][v803][2];	// L1456
              v794[v795][v802][v803][1] = v805;	// L1457
              int8_t v806 = v793[v795][v802][v803][v797];	// L1458
              v794[v795][v802][v803][2] = v806;	// L1459
            }
          }
          if ((v797 - 2) >= 0) {	// L1462
            int8_t v807[64];	// L1463
            #pragma HLS bind_storage variable=v807 type=ram_2p impl=bram

            for (int v808 = 0; v808 < 64; v808 += 1) {	// L1464
              v807[v808] = (int8_t)0.000000;	// L1465
              for (int v809 = 0; v809 < 16; v809 += 1) {	// L1466
                #pragma HLS pipeline II=1
                for (int v810 = 0; v810 < 4; v810 += 1) {	// L1467
                  for (int v811 = 0; v811 < 3; v811 += 1) {	// L1468
                    for (int v812 = 0; v812 < 3; v812 += 1) {	// L1469
                      int8_t v813 = v794[v795][(v810 + (v809 * 4))][v811][v812];	// L1470
                      int8_t v814 = v782[v808][(v810 + (v809 * 4))][v811][v812];	// L1471
                      int8_t v815 = v813 * v814;	// L1472
                      int8_t v816 = v807[v808];	// L1473
                      int8_t v817 = v816 + v815;	// L1474
                      v807[v808] = v817;	// L1475
                    }
                  }
                }
              }
              int8_t v818 = v807[v808];	// L1480
              v784[v795][v808][(v796 - 2)][(v797 - 2)] = v818;	// L1481
            }
          }
        }
      }
    }
  }
  return ;	// L1488
}

void main_graph_node34(
  int8_t v819[64][64][3][3],
  int8_t v820[1][64][32][32],
  int8_t v821[1][64][32][32]
) {	// L1490
  #pragma HLS dataflow

  int8_t v822[1][64][34][34];	// L1492
  #pragma HLS stream variable=v822 depth=10 type=fifo

  #pragma HLS bind_storage variable=v822 type=ram_t2p impl=bram

  for (int v823 = 0; v823 < 1; v823 += 1) {	// L1493
    for (int v824 = 0; v824 < 34; v824 += 1) {	// L1494
      for (int v825 = 0; v825 < 34; v825 += 1) {	// L1495
        for (int v826 = 0; v826 < 64; v826 += 1) {	// L1496
          int8_t v827;	// L1497
          v827 = (int8_t)0.000000;	// L1498
          if (((-v824) + 31) >= 0 && ((-v825) + 31) >= 0) {	// L1499
            int8_t v828 = v820[v823][v826][v824][v825];	// L1500
            v827 = v828;	// L1501
          }
          int8_t v829 = v827;	// L1503
          v822[v823][v826][v824][v825] = v829;	// L1504
        }
      }
    }
  }
  int8_t v830[1][64][32][32];	// L1509
  #pragma HLS stream variable=v830 depth=10 type=fifo

  #pragma HLS bind_storage variable=v830 type=ram_t2p impl=bram

  int8_t v831[1][64][3][34];	// L1510
  #pragma HLS array_partition variable=v831 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v831 type=ram_2p impl=bram

  int8_t v832[1][64][3][3];	// L1511
  #pragma HLS array_partition variable=v832 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v832 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v832 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v832 type=ram_2p impl=lutram

  for (int v833 = 0; v833 < 1; v833 += 1) {	// L1512
    for (int v834 = 0; v834 < 34; v834 += 1) {	// L1513
      for (int v835 = 0; v835 < 34; v835 += 1) {	// L1514
        for (int v836 = 0; v836 < 64; v836 += 1) {	// L1515
          int8_t v837 = v831[v833][v836][1][v835];	// L1516
          v831[v833][v836][0][v835] = v837;	// L1517
          int8_t v838 = v831[v833][v836][2][v835];	// L1518
          v831[v833][v836][1][v835] = v838;	// L1519
          int8_t v839 = v822[v833][v836][v834][v835];	// L1520
          v831[v833][v836][2][v835] = v839;	// L1521
        }
        if ((v834 - 2) >= 0) {	// L1523
          for (int v840 = 0; v840 < 64; v840 += 1) {	// L1524
            for (int v841 = 0; v841 < 3; v841 += 1) {	// L1525
              int8_t v842 = v832[v833][v840][v841][1];	// L1526
              v832[v833][v840][v841][0] = v842;	// L1527
              int8_t v843 = v832[v833][v840][v841][2];	// L1528
              v832[v833][v840][v841][1] = v843;	// L1529
              int8_t v844 = v831[v833][v840][v841][v835];	// L1530
              v832[v833][v840][v841][2] = v844;	// L1531
            }
          }
          if ((v835 - 2) >= 0) {	// L1534
            int8_t v845[64];	// L1535
            #pragma HLS bind_storage variable=v845 type=ram_2p impl=bram

            for (int v846 = 0; v846 < 64; v846 += 1) {	// L1536
              v845[v846] = (int8_t)0.000000;	// L1537
              for (int v847 = 0; v847 < 16; v847 += 1) {	// L1538
                #pragma HLS pipeline II=1
                for (int v848 = 0; v848 < 4; v848 += 1) {	// L1539
                  for (int v849 = 0; v849 < 3; v849 += 1) {	// L1540
                    for (int v850 = 0; v850 < 3; v850 += 1) {	// L1541
                      int8_t v851 = v832[v833][(v848 + (v847 * 4))][v849][v850];	// L1542
                      int8_t v852 = v819[v846][(v848 + (v847 * 4))][v849][v850];	// L1543
                      int8_t v853 = v851 * v852;	// L1544
                      int8_t v854 = v845[v846];	// L1545
                      int8_t v855 = v854 + v853;	// L1546
                      v845[v846] = v855;	// L1547
                    }
                  }
                }
              }
              int8_t v856 = v845[v846];	// L1552
              v830[v833][v846][(v834 - 2)][(v835 - 2)] = v856;	// L1553
            }
          }
        }
      }
    }
  }
  for (int v857 = 0; v857 < 1; v857 += 1) {	// L1560
    for (int v858 = 0; v858 < 32; v858 += 1) {	// L1561
      for (int v859 = 0; v859 < 32; v859 += 1) {	// L1562
        for (int v860 = 0; v860 < 64; v860 += 1) {	// L1563
          int8_t v861 = v830[0][v860][v858][v859];	// L1564
          bool v862 = v861 > (int8_t)0.000000;	// L1565
          int8_t v863 = v862 ? v861 : (int8_t)0.000000;	// L1566
          v821[v857][v860][v858][v859] = v863;	// L1567
        }
      }
    }
  }
  return ;	// L1572
}

void main_graph_node35(
  int8_t v864[1][64][32][32],
  int8_t v865[1][64][32][32],
  int8_t v866[1][64][32][32]
) {	// L1574
  #pragma HLS dataflow

  for (int v867 = 0; v867 < 1; v867 += 1) {	// L1575
    for (int v868 = 0; v868 < 32; v868 += 1) {	// L1576
      for (int v869 = 0; v869 < 32; v869 += 1) {	// L1577
        for (int v870 = 0; v870 < 64; v870 += 1) {	// L1578
          int8_t v871 = v864[v867][v870][v868][v869];	// L1579
          v865[v867][v870][v868][v869] = v871;	// L1580
          int8_t v872 = v864[v867][v870][v868][v869];	// L1581
          v866[v867][v870][v868][v869] = v872;	// L1582
        }
      }
    }
  }
  return ;	// L1587
}

void main_graph_node36(
  int8_t v873[1][64][32][32],
  int8_t v874[1][64][32][32],
  int8_t v875[1][64][32][32]
) {	// L1589
  #pragma HLS dataflow

  for (int v876 = 0; v876 < 1; v876 += 1) {	// L1591
    for (int v877 = 0; v877 < 32; v877 += 1) {	// L1592
      for (int v878 = 0; v878 < 32; v878 += 1) {	// L1593
        for (int v879 = 0; v879 < 64; v879 += 1) {	// L1594
          int8_t v880 = v873[0][v879][v877][v878];	// L1595
          int8_t v881 = v874[0][v879][v877][v878];	// L1596
          int8_t v882 = v880 + v881;	// L1597
          bool v883 = v882 > (int8_t)0.000000;	// L1598
          int8_t v884 = v883 ? v882 : (int8_t)0.000000;	// L1599
          v875[v876][v879][v877][v878] = v884;	// L1600
        }
      }
    }
  }
  return ;	// L1605
}

void main_graph_node37(
  int8_t v885[1][64][32][32],
  int8_t v886[64][64][3][3],
  int8_t v887[1][64][32][32]
) {	// L1607
  #pragma HLS dataflow

  int8_t v888[1][64][34][34];	// L1609
  #pragma HLS stream variable=v888 depth=10 type=fifo

  #pragma HLS bind_storage variable=v888 type=ram_t2p impl=bram

  for (int v889 = 0; v889 < 1; v889 += 1) {	// L1610
    for (int v890 = 0; v890 < 34; v890 += 1) {	// L1611
      for (int v891 = 0; v891 < 34; v891 += 1) {	// L1612
        for (int v892 = 0; v892 < 64; v892 += 1) {	// L1613
          int8_t v893;	// L1614
          v893 = (int8_t)0.000000;	// L1615
          if (((-v890) + 31) >= 0 && ((-v891) + 31) >= 0) {	// L1616
            int8_t v894 = v885[v889][v892][v890][v891];	// L1617
            v893 = v894;	// L1618
          }
          int8_t v895 = v893;	// L1620
          v888[v889][v892][v890][v891] = v895;	// L1621
        }
      }
    }
  }
  int8_t v896[1][64][3][34];	// L1626
  #pragma HLS array_partition variable=v896 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v896 type=ram_2p impl=bram

  int8_t v897[1][64][3][3];	// L1627
  #pragma HLS array_partition variable=v897 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v897 type=ram_2p impl=lutram

  for (int v898 = 0; v898 < 1; v898 += 1) {	// L1628
    for (int v899 = 0; v899 < 34; v899 += 1) {	// L1629
      for (int v900 = 0; v900 < 34; v900 += 1) {	// L1630
        for (int v901 = 0; v901 < 64; v901 += 1) {	// L1631
          int8_t v902 = v896[v898][v901][1][v900];	// L1632
          v896[v898][v901][0][v900] = v902;	// L1633
          int8_t v903 = v896[v898][v901][2][v900];	// L1634
          v896[v898][v901][1][v900] = v903;	// L1635
          int8_t v904 = v888[v898][v901][v899][v900];	// L1636
          v896[v898][v901][2][v900] = v904;	// L1637
        }
        if ((v899 - 2) >= 0) {	// L1639
          for (int v905 = 0; v905 < 64; v905 += 1) {	// L1640
            for (int v906 = 0; v906 < 3; v906 += 1) {	// L1641
              int8_t v907 = v897[v898][v905][v906][1];	// L1642
              v897[v898][v905][v906][0] = v907;	// L1643
              int8_t v908 = v897[v898][v905][v906][2];	// L1644
              v897[v898][v905][v906][1] = v908;	// L1645
              int8_t v909 = v896[v898][v905][v906][v900];	// L1646
              v897[v898][v905][v906][2] = v909;	// L1647
            }
          }
          if ((v900 - 2) >= 0) {	// L1650
            int8_t v910[64];	// L1651
            #pragma HLS bind_storage variable=v910 type=ram_2p impl=bram

            for (int v911 = 0; v911 < 64; v911 += 1) {	// L1652
              v910[v911] = (int8_t)0.000000;	// L1653
              for (int v912 = 0; v912 < 16; v912 += 1) {	// L1654
                #pragma HLS pipeline II=1
                for (int v913 = 0; v913 < 4; v913 += 1) {	// L1655
                  for (int v914 = 0; v914 < 3; v914 += 1) {	// L1656
                    for (int v915 = 0; v915 < 3; v915 += 1) {	// L1657
                      int8_t v916 = v897[v898][(v913 + (v912 * 4))][v914][v915];	// L1658
                      int8_t v917 = v886[v911][(v913 + (v912 * 4))][v914][v915];	// L1659
                      int8_t v918 = v916 * v917;	// L1660
                      int8_t v919 = v910[v911];	// L1661
                      int8_t v920 = v919 + v918;	// L1662
                      v910[v911] = v920;	// L1663
                    }
                  }
                }
              }
              int8_t v921 = v910[v911];	// L1668
              v887[v898][v911][(v899 - 2)][(v900 - 2)] = v921;	// L1669
            }
          }
        }
      }
    }
  }
  return ;	// L1676
}

void main_graph_node38(
  int8_t v922[64][64][3][3],
  int8_t v923[1][64][32][32],
  int8_t v924[1][64][32][32]
) {	// L1678
  #pragma HLS dataflow

  int8_t v925[1][64][34][34];	// L1680
  #pragma HLS stream variable=v925 depth=10 type=fifo

  #pragma HLS bind_storage variable=v925 type=ram_t2p impl=bram

  for (int v926 = 0; v926 < 1; v926 += 1) {	// L1681
    for (int v927 = 0; v927 < 34; v927 += 1) {	// L1682
      for (int v928 = 0; v928 < 34; v928 += 1) {	// L1683
        for (int v929 = 0; v929 < 64; v929 += 1) {	// L1684
          int8_t v930;	// L1685
          v930 = (int8_t)0.000000;	// L1686
          if (((-v927) + 31) >= 0 && ((-v928) + 31) >= 0) {	// L1687
            int8_t v931 = v923[v926][v929][v927][v928];	// L1688
            v930 = v931;	// L1689
          }
          int8_t v932 = v930;	// L1691
          v925[v926][v929][v927][v928] = v932;	// L1692
        }
      }
    }
  }
  int8_t v933[1][64][32][32];	// L1697
  #pragma HLS stream variable=v933 depth=10 type=fifo

  #pragma HLS bind_storage variable=v933 type=ram_t2p impl=bram

  int8_t v934[1][64][3][34];	// L1698
  #pragma HLS array_partition variable=v934 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v934 type=ram_2p impl=bram

  int8_t v935[1][64][3][3];	// L1699
  #pragma HLS array_partition variable=v935 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v935 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v935 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v935 type=ram_2p impl=lutram

  for (int v936 = 0; v936 < 1; v936 += 1) {	// L1700
    for (int v937 = 0; v937 < 34; v937 += 1) {	// L1701
      for (int v938 = 0; v938 < 34; v938 += 1) {	// L1702
        for (int v939 = 0; v939 < 64; v939 += 1) {	// L1703
          int8_t v940 = v934[v936][v939][1][v938];	// L1704
          v934[v936][v939][0][v938] = v940;	// L1705
          int8_t v941 = v934[v936][v939][2][v938];	// L1706
          v934[v936][v939][1][v938] = v941;	// L1707
          int8_t v942 = v925[v936][v939][v937][v938];	// L1708
          v934[v936][v939][2][v938] = v942;	// L1709
        }
        if ((v937 - 2) >= 0) {	// L1711
          for (int v943 = 0; v943 < 64; v943 += 1) {	// L1712
            for (int v944 = 0; v944 < 3; v944 += 1) {	// L1713
              int8_t v945 = v935[v936][v943][v944][1];	// L1714
              v935[v936][v943][v944][0] = v945;	// L1715
              int8_t v946 = v935[v936][v943][v944][2];	// L1716
              v935[v936][v943][v944][1] = v946;	// L1717
              int8_t v947 = v934[v936][v943][v944][v938];	// L1718
              v935[v936][v943][v944][2] = v947;	// L1719
            }
          }
          if ((v938 - 2) >= 0) {	// L1722
            int8_t v948[64];	// L1723
            #pragma HLS bind_storage variable=v948 type=ram_2p impl=bram

            for (int v949 = 0; v949 < 64; v949 += 1) {	// L1724
              v948[v949] = (int8_t)0.000000;	// L1725
              for (int v950 = 0; v950 < 16; v950 += 1) {	// L1726
                #pragma HLS pipeline II=1
                for (int v951 = 0; v951 < 4; v951 += 1) {	// L1727
                  for (int v952 = 0; v952 < 3; v952 += 1) {	// L1728
                    for (int v953 = 0; v953 < 3; v953 += 1) {	// L1729
                      int8_t v954 = v935[v936][(v951 + (v950 * 4))][v952][v953];	// L1730
                      int8_t v955 = v922[v949][(v951 + (v950 * 4))][v952][v953];	// L1731
                      int8_t v956 = v954 * v955;	// L1732
                      int8_t v957 = v948[v949];	// L1733
                      int8_t v958 = v957 + v956;	// L1734
                      v948[v949] = v958;	// L1735
                    }
                  }
                }
              }
              int8_t v959 = v948[v949];	// L1740
              v933[v936][v949][(v937 - 2)][(v938 - 2)] = v959;	// L1741
            }
          }
        }
      }
    }
  }
  for (int v960 = 0; v960 < 1; v960 += 1) {	// L1748
    for (int v961 = 0; v961 < 32; v961 += 1) {	// L1749
      for (int v962 = 0; v962 < 32; v962 += 1) {	// L1750
        for (int v963 = 0; v963 < 64; v963 += 1) {	// L1751
          int8_t v964 = v933[0][v963][v961][v962];	// L1752
          bool v965 = v964 > (int8_t)0.000000;	// L1753
          int8_t v966 = v965 ? v964 : (int8_t)0.000000;	// L1754
          v924[v960][v963][v961][v962] = v966;	// L1755
        }
      }
    }
  }
  return ;	// L1760
}

void main_graph_node39(
  int8_t v967[1][64][32][32],
  int8_t v968[1][64][32][32],
  int8_t v969[1][64][32][32]
) {	// L1762
  #pragma HLS dataflow

  for (int v970 = 0; v970 < 1; v970 += 1) {	// L1763
    for (int v971 = 0; v971 < 32; v971 += 1) {	// L1764
      for (int v972 = 0; v972 < 32; v972 += 1) {	// L1765
        for (int v973 = 0; v973 < 64; v973 += 1) {	// L1766
          int8_t v974 = v967[v970][v973][v971][v972];	// L1767
          v968[v970][v973][v971][v972] = v974;	// L1768
          int8_t v975 = v967[v970][v973][v971][v972];	// L1769
          v969[v970][v973][v971][v972] = v975;	// L1770
        }
      }
    }
  }
  return ;	// L1775
}

void main_graph_node40(
  int8_t v976[64][3][3][3],
  int8_t v977[1][3][32][32],
  int8_t v978[1][64][32][32]
) {	// L1777
  #pragma HLS dataflow

  int8_t v979[1][3][34][34];	// L1779
  #pragma HLS stream variable=v979 depth=10 type=fifo

  #pragma HLS bind_storage variable=v979 type=ram_t2p impl=bram

  for (int v980 = 0; v980 < 1; v980 += 1) {	// L1780
    for (int v981 = 0; v981 < 34; v981 += 1) {	// L1781
      for (int v982 = 0; v982 < 34; v982 += 1) {	// L1782
        for (int v983 = 0; v983 < 3; v983 += 1) {	// L1783
          int8_t v984;	// L1784
          v984 = (int8_t)0.000000;	// L1785
          if (((-v981) + 31) >= 0 && ((-v982) + 31) >= 0) {	// L1786
            int8_t v985 = v977[v980][v983][v981][v982];	// L1787
            v984 = v985;	// L1788
          }
          int8_t v986 = v984;	// L1790
          v979[v980][v983][v981][v982] = v986;	// L1791
        }
      }
    }
  }
  int8_t v987[1][64][32][32];	// L1796
  #pragma HLS stream variable=v987 depth=10 type=fifo

  #pragma HLS bind_storage variable=v987 type=ram_t2p impl=bram

  int8_t v988[1][3][3][34];	// L1797
  #pragma HLS array_partition variable=v988 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v988 type=ram_2p impl=lutram

  int8_t v989[1][3][3][3];	// L1798
  #pragma HLS array_partition variable=v989 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v989 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v989 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v989 type=ram_2p impl=lutram

  for (int v990 = 0; v990 < 1; v990 += 1) {	// L1799
    for (int v991 = 0; v991 < 34; v991 += 1) {	// L1800
      for (int v992 = 0; v992 < 34; v992 += 1) {	// L1801
        for (int v993 = 0; v993 < 3; v993 += 1) {	// L1802
          int8_t v994 = v988[v990][v993][1][v992];	// L1803
          v988[v990][v993][0][v992] = v994;	// L1804
          int8_t v995 = v988[v990][v993][2][v992];	// L1805
          v988[v990][v993][1][v992] = v995;	// L1806
          int8_t v996 = v979[v990][v993][v991][v992];	// L1807
          v988[v990][v993][2][v992] = v996;	// L1808
        }
        if ((v991 - 2) >= 0) {	// L1810
          for (int v997 = 0; v997 < 3; v997 += 1) {	// L1811
            for (int v998 = 0; v998 < 3; v998 += 1) {	// L1812
              int8_t v999 = v989[v990][v997][v998][1];	// L1813
              v989[v990][v997][v998][0] = v999;	// L1814
              int8_t v1000 = v989[v990][v997][v998][2];	// L1815
              v989[v990][v997][v998][1] = v1000;	// L1816
              int8_t v1001 = v988[v990][v997][v998][v992];	// L1817
              v989[v990][v997][v998][2] = v1001;	// L1818
            }
          }
          if ((v992 - 2) >= 0) {	// L1821
            int8_t v1002[64];	// L1822
            #pragma HLS bind_storage variable=v1002 type=ram_2p impl=bram

            for (int v1003 = 0; v1003 < 64; v1003 += 1) {	// L1823
              #pragma HLS pipeline II=1
              for (int v1004 = 0; v1004 < 1; v1004 += 1) {	// L1824
                v1002[(v1003 + v1004)] = (int8_t)0.000000;	// L1825
                for (int v1005 = 0; v1005 < 3; v1005 += 1) {	// L1826
                  for (int v1006 = 0; v1006 < 3; v1006 += 1) {	// L1827
                    for (int v1007 = 0; v1007 < 3; v1007 += 1) {	// L1828
                      int8_t v1008 = v989[v990][v1005][v1006][v1007];	// L1829
                      int8_t v1009 = v976[(v1003 + v1004)][v1005][v1006][v1007];	// L1830
                      int8_t v1010 = v1008 * v1009;	// L1831
                      int8_t v1011 = v1002[(v1003 + v1004)];	// L1832
                      int8_t v1012 = v1011 + v1010;	// L1833
                      v1002[(v1003 + v1004)] = v1012;	// L1834
                    }
                  }
                }
                int8_t v1013 = v1002[(v1003 + v1004)];	// L1838
                v987[v990][(v1003 + v1004)][(v991 - 2)][(v992 - 2)] = v1013;	// L1839
              }
            }
          }
        }
      }
    }
  }
  for (int v1014 = 0; v1014 < 1; v1014 += 1) {	// L1847
    for (int v1015 = 0; v1015 < 32; v1015 += 1) {	// L1848
      for (int v1016 = 0; v1016 < 32; v1016 += 1) {	// L1849
        for (int v1017 = 0; v1017 < 64; v1017 += 1) {	// L1850
          int8_t v1018 = v987[0][v1017][v1015][v1016];	// L1851
          bool v1019 = v1018 > (int8_t)0.000000;	// L1852
          int8_t v1020 = v1019 ? v1018 : (int8_t)0.000000;	// L1853
          v978[v1014][v1017][v1015][v1016] = v1020;	// L1854
        }
      }
    }
  }
  return ;	// L1859
}

/// This is top function.
void main_graph(
  int8_t v1021[1][3][32][32],
  int8_t v1022[10],
  int8_t v1023[512][512][3][3],
  int8_t v1024[512][512][3][3],
  int8_t v1025[512][256][1][1],
  int8_t v1026[512][512][3][3],
  int8_t v1027[512][256][3][3],
  int8_t v1028[256][256][3][3],
  int8_t v1029[256][256][3][3],
  int8_t v1030[256][128][1][1],
  int8_t v1031[256][256][3][3],
  int8_t v1032[256][128][3][3],
  int8_t v1033[128][128][3][3],
  int8_t v1034[128][128][3][3],
  int8_t v1035[128][64][1][1],
  int8_t v1036[128][128][3][3],
  int8_t v1037[128][64][3][3],
  int8_t v1038[64][64][3][3],
  int8_t v1039[64][64][3][3],
  int8_t v1040[64][64][3][3],
  int8_t v1041[64][64][3][3],
  int8_t v1042[64][3][3][3],
  int8_t v1043[512][10],
  int8_t v1044[1][10]
) {	// L1861
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v1021 bundle=gmem1
  #pragma HLS bind_storage variable=v1021 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1022 bundle=gmem2
  #pragma HLS bind_storage variable=v1022 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1023 bundle=gmem3
  #pragma HLS array_partition variable=v1023 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1023 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1023 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1023 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1024 bundle=gmem4
  #pragma HLS array_partition variable=v1024 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1024 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1024 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1024 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1025 bundle=gmem5
  #pragma HLS array_partition variable=v1025 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1025 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1026 bundle=gmem6
  #pragma HLS array_partition variable=v1026 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1026 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1026 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1026 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1027 bundle=gmem7
  #pragma HLS array_partition variable=v1027 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1027 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1027 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1027 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1028 bundle=gmem8
  #pragma HLS array_partition variable=v1028 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1028 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1028 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1028 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1029 bundle=gmem9
  #pragma HLS array_partition variable=v1029 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1029 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1029 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1029 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1030 bundle=gmem10
  #pragma HLS array_partition variable=v1030 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1030 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1031 bundle=gmem11
  #pragma HLS array_partition variable=v1031 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1031 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1031 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1031 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1032 bundle=gmem12
  #pragma HLS array_partition variable=v1032 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1032 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1032 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1032 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1033 bundle=gmem13
  #pragma HLS array_partition variable=v1033 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1033 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1033 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1033 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1034 bundle=gmem14
  #pragma HLS array_partition variable=v1034 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1034 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1034 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1034 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1035 bundle=gmem15
  #pragma HLS array_partition variable=v1035 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1035 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1036 bundle=gmem16
  #pragma HLS array_partition variable=v1036 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1036 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1036 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1036 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1037 bundle=gmem17
  #pragma HLS array_partition variable=v1037 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1037 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1037 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1037 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1038 bundle=gmem18
  #pragma HLS array_partition variable=v1038 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1038 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1038 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1038 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1039 bundle=gmem19
  #pragma HLS array_partition variable=v1039 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1039 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1039 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1039 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1040 bundle=gmem20
  #pragma HLS array_partition variable=v1040 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1040 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1040 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1040 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1041 bundle=gmem21
  #pragma HLS array_partition variable=v1041 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1041 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1041 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1041 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1042 bundle=gmem22
  #pragma HLS array_partition variable=v1042 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1042 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1042 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1042 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1043 bundle=gmem23
  #pragma HLS bind_storage variable=v1043 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1044 bundle=gmem24
  #pragma HLS bind_storage variable=v1044 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v1045[1][64][32][32];	// L1863
  #pragma HLS stream variable=v1045 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1045 type=ram_t2p impl=bram

  main_graph_node40(v1042, v1021, v1045);	// L1864
  int8_t v1046[1][64][32][32];	// L1865
  #pragma HLS bind_storage variable=v1046 type=ram_t2p impl=bram

  int8_t v1047[1][64][32][32];	// L1866
  #pragma HLS stream variable=v1047 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1047 type=ram_t2p impl=bram

  main_graph_node39(v1045, v1046, v1047);	// L1867
  int8_t v1048[1][64][32][32];	// L1868
  #pragma HLS stream variable=v1048 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1048 type=ram_t2p impl=bram

  main_graph_node38(v1041, v1047, v1048);	// L1869
  int8_t v1049[1][64][32][32];	// L1870
  #pragma HLS stream variable=v1049 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1049 type=ram_t2p impl=bram

  main_graph_node37(v1048, v1040, v1049);	// L1871
  int8_t v1050[1][64][32][32];	// L1872
  #pragma HLS bind_storage variable=v1050 type=ram_t2p impl=bram

  main_graph_node36(v1049, v1046, v1050);	// L1873
  int8_t v1051[1][64][32][32];	// L1874
  #pragma HLS bind_storage variable=v1051 type=ram_t2p impl=bram

  int8_t v1052[1][64][32][32];	// L1875
  #pragma HLS stream variable=v1052 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1052 type=ram_t2p impl=bram

  main_graph_node35(v1050, v1051, v1052);	// L1876
  int8_t v1053[1][64][32][32];	// L1877
  #pragma HLS stream variable=v1053 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1053 type=ram_t2p impl=bram

  main_graph_node34(v1039, v1052, v1053);	// L1878
  int8_t v1054[1][64][32][32];	// L1879
  #pragma HLS stream variable=v1054 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1054 type=ram_t2p impl=bram

  main_graph_node33(v1038, v1053, v1054);	// L1880
  int8_t v1055[1][64][32][32];	// L1881
  #pragma HLS bind_storage variable=v1055 type=ram_t2p impl=bram

  main_graph_node32(v1054, v1051, v1055);	// L1882
  int8_t v1056[1][64][32][32];	// L1883
  #pragma HLS stream variable=v1056 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1056 type=ram_t2p impl=bram

  int8_t v1057[1][64][32][32];	// L1884
  #pragma HLS stream variable=v1057 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1057 type=ram_t2p impl=bram

  main_graph_node31(v1055, v1056, v1057);	// L1885
  int8_t v1058[1][128][16][16];	// L1886
  #pragma HLS stream variable=v1058 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1058 type=ram_t2p impl=bram

  main_graph_node30(v1037, v1057, v1058);	// L1887
  int8_t v1059[1][128][16][16];	// L1888
  #pragma HLS stream variable=v1059 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1059 type=ram_t2p impl=bram

  main_graph_node29(v1058, v1036, v1059);	// L1889
  int8_t v1060[1][128][16][16];	// L1890
  #pragma HLS stream variable=v1060 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1060 type=ram_t2p impl=bram

  main_graph_node28(v1035, v1056, v1060);	// L1891
  int8_t v1061[1][128][16][16];	// L1892
  #pragma HLS bind_storage variable=v1061 type=ram_t2p impl=bram

  main_graph_node27(v1059, v1060, v1061);	// L1893
  int8_t v1062[1][128][16][16];	// L1894
  #pragma HLS bind_storage variable=v1062 type=ram_t2p impl=bram

  int8_t v1063[1][128][16][16];	// L1895
  #pragma HLS stream variable=v1063 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1063 type=ram_t2p impl=bram

  main_graph_node26(v1061, v1062, v1063);	// L1896
  int8_t v1064[1][128][16][16];	// L1897
  #pragma HLS stream variable=v1064 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1064 type=ram_t2p impl=bram

  main_graph_node25(v1034, v1063, v1064);	// L1898
  int8_t v1065[1][128][16][16];	// L1899
  #pragma HLS stream variable=v1065 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1065 type=ram_t2p impl=bram

  main_graph_node24(v1033, v1064, v1065);	// L1900
  int8_t v1066[1][128][16][16];	// L1901
  #pragma HLS bind_storage variable=v1066 type=ram_t2p impl=bram

  main_graph_node23(v1065, v1062, v1066);	// L1902
  int8_t v1067[1][128][16][16];	// L1903
  #pragma HLS stream variable=v1067 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1067 type=ram_t2p impl=bram

  int8_t v1068[1][128][16][16];	// L1904
  #pragma HLS stream variable=v1068 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1068 type=ram_t2p impl=bram

  main_graph_node22(v1066, v1067, v1068);	// L1905
  int8_t v1069[1][256][8][8];	// L1906
  #pragma HLS stream variable=v1069 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1069 type=ram_t2p impl=bram

  main_graph_node21(v1032, v1068, v1069);	// L1907
  int8_t v1070[1][256][8][8];	// L1908
  #pragma HLS stream variable=v1070 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1070 type=ram_t2p impl=bram

  main_graph_node20(v1031, v1069, v1070);	// L1909
  int8_t v1071[1][256][8][8];	// L1910
  #pragma HLS stream variable=v1071 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1071 type=ram_t2p impl=bram

  main_graph_node19(v1030, v1067, v1071);	// L1911
  int8_t v1072[1][256][8][8];	// L1912
  #pragma HLS bind_storage variable=v1072 type=ram_t2p impl=bram

  main_graph_node18(v1070, v1071, v1072);	// L1913
  int8_t v1073[1][256][8][8];	// L1914
  #pragma HLS bind_storage variable=v1073 type=ram_t2p impl=bram

  int8_t v1074[1][256][8][8];	// L1915
  #pragma HLS stream variable=v1074 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1074 type=ram_t2p impl=bram

  main_graph_node17(v1072, v1073, v1074);	// L1916
  int8_t v1075[1][256][8][8];	// L1917
  #pragma HLS stream variable=v1075 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1075 type=ram_t2p impl=bram

  main_graph_node16(v1074, v1029, v1075);	// L1918
  int8_t v1076[1][256][8][8];	// L1919
  #pragma HLS stream variable=v1076 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1076 type=ram_t2p impl=bram

  main_graph_node15(v1028, v1075, v1076);	// L1920
  int8_t v1077[1][256][8][8];	// L1921
  #pragma HLS bind_storage variable=v1077 type=ram_t2p impl=bram

  main_graph_node14(v1076, v1073, v1077);	// L1922
  int8_t v1078[1][256][8][8];	// L1923
  #pragma HLS stream variable=v1078 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1078 type=ram_t2p impl=bram

  int8_t v1079[1][256][8][8];	// L1924
  #pragma HLS stream variable=v1079 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1079 type=ram_t2p impl=bram

  main_graph_node13(v1077, v1078, v1079);	// L1925
  int8_t v1080[1][512][4][4];	// L1926
  #pragma HLS stream variable=v1080 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1080 type=ram_t2p impl=bram

  main_graph_node12(v1079, v1027, v1080);	// L1927
  int8_t v1081[1][512][4][4];	// L1928
  #pragma HLS stream variable=v1081 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1081 type=ram_t2p impl=bram

  main_graph_node11(v1026, v1080, v1081);	// L1929
  int8_t v1082[1][512][4][4];	// L1930
  #pragma HLS stream variable=v1082 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1082 type=ram_t2p impl=bram

  main_graph_node10(v1078, v1025, v1082);	// L1931
  int8_t v1083[1][512][4][4];	// L1932
  #pragma HLS bind_storage variable=v1083 type=ram_t2p impl=bram

  main_graph_node9(v1081, v1082, v1083);	// L1933
  int8_t v1084[1][512][4][4];	// L1934
  #pragma HLS bind_storage variable=v1084 type=ram_t2p impl=bram

  int8_t v1085[1][512][4][4];	// L1935
  #pragma HLS stream variable=v1085 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1085 type=ram_t2p impl=bram

  main_graph_node8(v1083, v1084, v1085);	// L1936
  int8_t v1086[1][512][4][4];	// L1937
  #pragma HLS stream variable=v1086 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1086 type=ram_t2p impl=bram

  main_graph_node7(v1085, v1024, v1086);	// L1938
  int8_t v1087[1][512][4][4];	// L1939
  #pragma HLS stream variable=v1087 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1087 type=ram_t2p impl=bram

  main_graph_node6(v1023, v1086, v1087);	// L1940
  int8_t v1088[1][512][4][4];	// L1941
  #pragma HLS bind_storage variable=v1088 type=ram_t2p impl=bram

  main_graph_node5(v1087, v1084, v1088);	// L1942
  int8_t v1089[1][512][5][5];	// L1943
  #pragma HLS bind_storage variable=v1089 type=ram_t2p impl=bram

  main_graph_node4(v1088, v1089);	// L1944
  int8_t v1090[1][1];	// L1945
  #pragma HLS bind_storage variable=v1090 type=ram_t2p impl=bram

  int8_t v1091[1][512][1][1];	// L1946
  #pragma HLS bind_storage variable=v1091 type=ram_t2p impl=bram

  main_graph_node3(v1089, v1091, v1090);	// L1947
  int8_t v1092[1][512][1][1];	// L1948
  #pragma HLS bind_storage variable=v1092 type=ram_t2p impl=bram

  main_graph_node2(v1091, v1090, v1092);	// L1949
  int8_t v1093[1][10];	// L1950
  #pragma HLS bind_storage variable=v1093 type=ram_t2p impl=bram

  main_graph_node1(v1092, v1043, v1093);	// L1951
  main_graph_node0(v1093, v1022, v1044);	// L1952
  return ;	// L1953
}

