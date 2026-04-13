
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
) {	// L17
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L18
    for (int v4 = 0; v4 < 1000; v4 += 1) {	// L19
      int8_t v5 = v0[0][v4];	// L20
      int8_t v6 = v1[v4];	// L21
      int8_t v7 = v5 + v6;	// L22
      v2[v3][v4] = v7;	// L23
    }
  }
  return ;	// L26
}

void main_graph_node1(
  int8_t v8[1][512][1][1],
  int8_t v9[512][1000],
  int8_t v10[1][1000]
) {	// L28
  #pragma HLS dataflow

  int8_t v11[1][1000];	// L30
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L31
    for (int v13 = 0; v13 < 1000; v13 += 1) {	// L32
      v11[v12][v13] = (int8_t)0.000000;	// L33
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L36
    for (int v15 = 0; v15 < 1000; v15 += 1) {	// L37
      for (int v16 = 0; v16 < 512; v16 += 1) {	// L38
        int8_t v17 = v8[v14][v16][0][0];	// L39
        int8_t v18 = v9[v16][v15];	// L40
        int8_t v19 = v11[v14][v15];	// L41
        int8_t v20 = v17 * v18;	// L42
        int8_t v21 = v19 + v20;	// L43
        v10[v14][v15] = v21;	// L44
      }
    }
  }
  return ;	// L48
}

void main_graph_node2(
  int8_t v22[1][512][1][1],
  int8_t v23[1][1],
  int8_t v24[1][512][1][1]
) {	// L50
  #pragma HLS dataflow

  int8_t v25[1][512][1][1];	// L51
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  for (int v26 = 0; v26 < 1; v26 += 1) {	// L52
    for (int v27 = 0; v27 < 512; v27 += 1) {	// L53
      for (int v28 = 0; v28 < 1; v28 += 1) {	// L54
        for (int v29 = 0; v29 < 1; v29 += 1) {	// L55
          int8_t v30 = v22[v26][v27][v28][v29];	// L56
          v25[v26][v27][v28][v29] = v30;	// L57
          int8_t v31 = v23[v28][v29];	// L58
          int8_t v32 = v25[v26][v27][v28][v29];	// L59
          int8_t v33 = v32 / v31;	// L60
          v24[v26][v27][v28][v29] = v33;	// L61
        }
      }
    }
  }
  return ;	// L66
}

void main_graph_node3(
  int8_t v34[1][512][8][8],
  int8_t v35[1][1],
  int8_t v36[1][512][1][1]
) {	// L68
  #pragma HLS dataflow

  int8_t v37[1][512][1][1];	// L72
  #pragma HLS bind_storage variable=v37 type=ram_t2p impl=bram

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L73
    for (int v39 = 0; v39 < 512; v39 += 1) {	// L74
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L75
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L76
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L77
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L82
    for (int v43 = 0; v43 < 512; v43 += 1) {	// L83
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L84
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L85
          for (int v46 = 0; v46 < 7; v46 += 1) {	// L86
            for (int v47 = 0; v47 < 7; v47 += 1) {	// L87
              int8_t v48 = v37[v42][v43][v44][v45];	// L88
              int v49 = v44 * (int)7;	// L89
              int v50 = v44 + (int)1;	// L90
              int v51 = v50 * (int)7;	// L91
              int v52 = v45 * (int)7;	// L92
              int v53 = v45 + (int)1;	// L93
              int v54 = v53 * (int)7;	// L94
              int v55 = v49 + v46;	// L95
              int v56 = v52 + v47;	// L96
              int8_t v57 = v34[v42][v43][v55][v56];	// L97
              bool v58 = v55 < v51;	// L98
              int8_t v59 = v58 ? v57 : (int8_t)0.000000;	// L99
              bool v60 = v56 < v54;	// L100
              int8_t v61 = v60 ? v59 : (int8_t)0.000000;	// L101
              int8_t v62 = v61 + v48;	// L102
              int v63 = v51 - v49;	// L103
              int v64 = v54 - v52;	// L104
              int v65 = v63 * v64;	// L105
              ap_int<64> v66 = v65;	// L106
              int8_t v67 = v66;	// L107
              v36[v42][v43][v44][v45] = v62;	// L108
              v35[v42][v43] = v67;	// L109
            }
          }
        }
      }
    }
  }
  return ;	// L116
}

void main_graph_node4(
  int8_t v68[1][512][7][7],
  int8_t v69[1][512][8][8]
) {	// L118
  #pragma HLS dataflow

  for (int v70 = 0; v70 < 1; v70 += 1) {	// L120
    for (int v71 = 0; v71 < 512; v71 += 1) {	// L121
      for (int v72 = 0; v72 < 8; v72 += 1) {	// L122
        for (int v73 = 0; v73 < 8; v73 += 1) {	// L123
          int8_t v74;	// L124
          v74 = (int8_t)0.000000;	// L125
          if (((-v72) + 6) >= 0 && ((-v73) + 6) >= 0) {	// L126
            int8_t v75 = v68[v70][v71][v72][v73];	// L127
            v74 = v75;	// L128
          }
          int8_t v76 = v74;	// L130
          v69[v70][v71][v72][v73] = v76;	// L131
        }
      }
    }
  }
  return ;	// L136
}

void main_graph_node5(
  int8_t v77[1][512][7][7],
  int8_t v78[1][512][7][7],
  int8_t v79[1][512][7][7]
) {	// L138
  #pragma HLS dataflow

  for (int v80 = 0; v80 < 1; v80 += 1) {	// L140
    for (int v81 = 0; v81 < 7; v81 += 1) {	// L141
      for (int v82 = 0; v82 < 7; v82 += 1) {	// L142
        for (int v83 = 0; v83 < 512; v83 += 1) {	// L143
          int8_t v84 = v77[0][v83][v81][v82];	// L144
          int8_t v85 = v78[0][v83][v81][v82];	// L145
          int8_t v86 = v84 + v85;	// L146
          bool v87 = v86 > (int8_t)0.000000;	// L147
          int8_t v88 = v87 ? v86 : (int8_t)0.000000;	// L148
          v79[v80][v83][v81][v82] = v88;	// L149
        }
      }
    }
  }
  return ;	// L154
}

void main_graph_node6(
  int8_t v89[512][512][3][3],
  int8_t v90[1][512][7][7],
  int8_t v91[1][512][7][7]
) {	// L156
  #pragma HLS dataflow

  int8_t v92[1][512][9][9];	// L158
  #pragma HLS stream variable=v92 depth=10 type=fifo

  #pragma HLS bind_storage variable=v92 type=ram_t2p impl=bram

  for (int v93 = 0; v93 < 1; v93 += 1) {	// L159
    for (int v94 = 0; v94 < 9; v94 += 1) {	// L160
      for (int v95 = 0; v95 < 9; v95 += 1) {	// L161
        for (int v96 = 0; v96 < 512; v96 += 1) {	// L162
          int8_t v97;	// L163
          v97 = (int8_t)0.000000;	// L164
          if (((-v94) + 6) >= 0 && ((-v95) + 6) >= 0) {	// L165
            int8_t v98 = v90[v93][v96][v94][v95];	// L166
            v97 = v98;	// L167
          }
          int8_t v99 = v97;	// L169
          v92[v93][v96][v94][v95] = v99;	// L170
        }
      }
    }
  }
  int8_t v100[1][512][3][9];	// L175
  #pragma HLS array_partition variable=v100 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v100 type=ram_2p impl=bram

  int8_t v101[1][512][3][3];	// L176
  #pragma HLS array_partition variable=v101 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v101 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v101 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v101 type=ram_2p impl=lutram

  for (int v102 = 0; v102 < 1; v102 += 1) {	// L177
    for (int v103 = 0; v103 < 9; v103 += 1) {	// L178
      for (int v104 = 0; v104 < 9; v104 += 1) {	// L179
        for (int v105 = 0; v105 < 512; v105 += 1) {	// L180
          int8_t v106 = v100[v102][v105][1][v104];	// L181
          v100[v102][v105][0][v104] = v106;	// L182
          int8_t v107 = v100[v102][v105][2][v104];	// L183
          v100[v102][v105][1][v104] = v107;	// L184
          int8_t v108 = v92[v102][v105][v103][v104];	// L185
          v100[v102][v105][2][v104] = v108;	// L186
        }
        if ((v103 - 2) >= 0) {	// L188
          for (int v109 = 0; v109 < 512; v109 += 1) {	// L189
            for (int v110 = 0; v110 < 3; v110 += 1) {	// L190
              int8_t v111 = v101[v102][v109][v110][1];	// L191
              v101[v102][v109][v110][0] = v111;	// L192
              int8_t v112 = v101[v102][v109][v110][2];	// L193
              v101[v102][v109][v110][1] = v112;	// L194
              int8_t v113 = v100[v102][v109][v110][v104];	// L195
              v101[v102][v109][v110][2] = v113;	// L196
            }
          }
          if ((v104 - 2) >= 0) {	// L199
            int8_t v114[512];	// L200
            #pragma HLS bind_storage variable=v114 type=ram_2p impl=bram

            for (int v115 = 0; v115 < 512; v115 += 1) {	// L201
              v114[v115] = (int8_t)0.000000;	// L202
              for (int v116 = 0; v116 < 64; v116 += 1) {	// L203
                #pragma HLS pipeline II=1
                for (int v117 = 0; v117 < 8; v117 += 1) {	// L204
                  for (int v118 = 0; v118 < 3; v118 += 1) {	// L205
                    for (int v119 = 0; v119 < 3; v119 += 1) {	// L206
                      int8_t v120 = v101[v102][(v117 + (v116 * 8))][v118][v119];	// L207
                      int8_t v121 = v89[v115][(v117 + (v116 * 8))][v118][v119];	// L208
                      int8_t v122 = v120 * v121;	// L209
                      int8_t v123 = v114[v115];	// L210
                      int8_t v124 = v123 + v122;	// L211
                      v114[v115] = v124;	// L212
                    }
                  }
                }
              }
              int8_t v125 = v114[v115];	// L217
              v91[v102][v115][(v103 - 2)][(v104 - 2)] = v125;	// L218
            }
          }
        }
      }
    }
  }
  return ;	// L225
}

void main_graph_node7(
  int8_t v126[512][512][3][3],
  int8_t v127[1][512][7][7],
  int8_t v128[1][512][7][7]
) {	// L227
  #pragma HLS dataflow

  int8_t v129[1][512][9][9];	// L229
  #pragma HLS stream variable=v129 depth=10 type=fifo

  #pragma HLS bind_storage variable=v129 type=ram_t2p impl=bram

  for (int v130 = 0; v130 < 1; v130 += 1) {	// L230
    for (int v131 = 0; v131 < 9; v131 += 1) {	// L231
      for (int v132 = 0; v132 < 9; v132 += 1) {	// L232
        for (int v133 = 0; v133 < 512; v133 += 1) {	// L233
          int8_t v134;	// L234
          v134 = (int8_t)0.000000;	// L235
          if (((-v131) + 6) >= 0 && ((-v132) + 6) >= 0) {	// L236
            int8_t v135 = v127[v130][v133][v131][v132];	// L237
            v134 = v135;	// L238
          }
          int8_t v136 = v134;	// L240
          v129[v130][v133][v131][v132] = v136;	// L241
        }
      }
    }
  }
  int8_t v137[1][512][7][7];	// L246
  #pragma HLS stream variable=v137 depth=10 type=fifo

  #pragma HLS bind_storage variable=v137 type=ram_t2p impl=bram

  int8_t v138[1][512][3][9];	// L247
  #pragma HLS array_partition variable=v138 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v138 type=ram_2p impl=bram

  int8_t v139[1][512][3][3];	// L248
  #pragma HLS array_partition variable=v139 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v139 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v139 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v139 type=ram_2p impl=lutram

  for (int v140 = 0; v140 < 1; v140 += 1) {	// L249
    for (int v141 = 0; v141 < 9; v141 += 1) {	// L250
      for (int v142 = 0; v142 < 9; v142 += 1) {	// L251
        for (int v143 = 0; v143 < 512; v143 += 1) {	// L252
          int8_t v144 = v138[v140][v143][1][v142];	// L253
          v138[v140][v143][0][v142] = v144;	// L254
          int8_t v145 = v138[v140][v143][2][v142];	// L255
          v138[v140][v143][1][v142] = v145;	// L256
          int8_t v146 = v129[v140][v143][v141][v142];	// L257
          v138[v140][v143][2][v142] = v146;	// L258
        }
        if ((v141 - 2) >= 0) {	// L260
          for (int v147 = 0; v147 < 512; v147 += 1) {	// L261
            for (int v148 = 0; v148 < 3; v148 += 1) {	// L262
              int8_t v149 = v139[v140][v147][v148][1];	// L263
              v139[v140][v147][v148][0] = v149;	// L264
              int8_t v150 = v139[v140][v147][v148][2];	// L265
              v139[v140][v147][v148][1] = v150;	// L266
              int8_t v151 = v138[v140][v147][v148][v142];	// L267
              v139[v140][v147][v148][2] = v151;	// L268
            }
          }
          if ((v142 - 2) >= 0) {	// L271
            int8_t v152[512];	// L272
            #pragma HLS bind_storage variable=v152 type=ram_2p impl=bram

            for (int v153 = 0; v153 < 512; v153 += 1) {	// L273
              v152[v153] = (int8_t)0.000000;	// L274
              for (int v154 = 0; v154 < 64; v154 += 1) {	// L275
                #pragma HLS pipeline II=1
                for (int v155 = 0; v155 < 8; v155 += 1) {	// L276
                  for (int v156 = 0; v156 < 3; v156 += 1) {	// L277
                    for (int v157 = 0; v157 < 3; v157 += 1) {	// L278
                      int8_t v158 = v139[v140][(v155 + (v154 * 8))][v156][v157];	// L279
                      int8_t v159 = v126[v153][(v155 + (v154 * 8))][v156][v157];	// L280
                      int8_t v160 = v158 * v159;	// L281
                      int8_t v161 = v152[v153];	// L282
                      int8_t v162 = v161 + v160;	// L283
                      v152[v153] = v162;	// L284
                    }
                  }
                }
              }
              int8_t v163 = v152[v153];	// L289
              v137[v140][v153][(v141 - 2)][(v142 - 2)] = v163;	// L290
            }
          }
        }
      }
    }
  }
  for (int v164 = 0; v164 < 1; v164 += 1) {	// L297
    for (int v165 = 0; v165 < 7; v165 += 1) {	// L298
      for (int v166 = 0; v166 < 7; v166 += 1) {	// L299
        for (int v167 = 0; v167 < 512; v167 += 1) {	// L300
          int8_t v168 = v137[0][v167][v165][v166];	// L301
          bool v169 = v168 > (int8_t)0.000000;	// L302
          int8_t v170 = v169 ? v168 : (int8_t)0.000000;	// L303
          v128[v164][v167][v165][v166] = v170;	// L304
        }
      }
    }
  }
  return ;	// L309
}

void main_graph_node8(
  int8_t v171[1][512][7][7],
  int8_t v172[1][512][7][7],
  int8_t v173[1][512][7][7]
) {	// L311
  #pragma HLS dataflow

  for (int v174 = 0; v174 < 1; v174 += 1) {	// L312
    for (int v175 = 0; v175 < 7; v175 += 1) {	// L313
      for (int v176 = 0; v176 < 7; v176 += 1) {	// L314
        for (int v177 = 0; v177 < 512; v177 += 1) {	// L315
          int8_t v178 = v171[v174][v177][v175][v176];	// L316
          v172[v174][v177][v175][v176] = v178;	// L317
          int8_t v179 = v171[v174][v177][v175][v176];	// L318
          v173[v174][v177][v175][v176] = v179;	// L319
        }
      }
    }
  }
  return ;	// L324
}

void main_graph_node9(
  int8_t v180[1][512][7][7],
  int8_t v181[1][512][7][7],
  int8_t v182[1][512][7][7]
) {	// L326
  #pragma HLS dataflow

  for (int v183 = 0; v183 < 1; v183 += 1) {	// L328
    for (int v184 = 0; v184 < 7; v184 += 1) {	// L329
      for (int v185 = 0; v185 < 7; v185 += 1) {	// L330
        for (int v186 = 0; v186 < 512; v186 += 1) {	// L331
          int8_t v187 = v180[0][v186][v184][v185];	// L332
          int8_t v188 = v181[0][v186][v184][v185];	// L333
          int8_t v189 = v187 + v188;	// L334
          bool v190 = v189 > (int8_t)0.000000;	// L335
          int8_t v191 = v190 ? v189 : (int8_t)0.000000;	// L336
          v182[v183][v186][v184][v185] = v191;	// L337
        }
      }
    }
  }
  return ;	// L342
}

void main_graph_node10(
  int8_t v192[512][256][1][1],
  int8_t v193[1][256][14][14],
  int8_t v194[1][512][7][7]
) {	// L344
  #pragma HLS dataflow

  int8_t v195[1][256][1][14];	// L346
  #pragma HLS bind_storage variable=v195 type=ram_2p impl=bram

  int8_t v196[1][256][1][1];	// L347
  #pragma HLS array_partition variable=v196 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v196 type=ram_2p impl=lutram

  for (int v197 = 0; v197 < 1; v197 += 1) {	// L348
    for (int v198 = 0; v198 < 14; v198 += 1) {	// L349
      for (int v199 = 0; v199 < 14; v199 += 1) {	// L350
        for (int v200 = 0; v200 < 256; v200 += 1) {	// L351
          int8_t v201 = v193[v197][v200][v198][v199];	// L352
          v195[v197][v200][0][v199] = v201;	// L353
        }
        if ((v198 - 7) >= 0) {	// L355
          for (int v202 = 0; v202 < 256; v202 += 1) {	// L356
            for (int v203 = 0; v203 < 1; v203 += 1) {	// L357
              int8_t v204 = v195[v197][v202][v203][v199];	// L358
              v196[v197][v202][v203][0] = v204;	// L359
            }
          }
          if ((v199 - 7) >= 0) {	// L362
            int8_t v205[512];	// L363
            #pragma HLS bind_storage variable=v205 type=ram_2p impl=bram

            for (int v206 = 0; v206 < 512; v206 += 1) {	// L364
              v205[v206] = (int8_t)0.000000;	// L365
              for (int v207 = 0; v207 < 32; v207 += 1) {	// L366
                #pragma HLS pipeline II=1
                for (int v208 = 0; v208 < 8; v208 += 1) {	// L367
                  for (int v209 = 0; v209 < 1; v209 += 1) {	// L368
                    for (int v210 = 0; v210 < 1; v210 += 1) {	// L369
                      int8_t v211 = v196[v197][(v208 + (v207 * 8))][v209][v210];	// L370
                      int8_t v212 = v192[v206][(v208 + (v207 * 8))][v209][v210];	// L371
                      int8_t v213 = v211 * v212;	// L372
                      int8_t v214 = v205[v206];	// L373
                      int8_t v215 = v214 + v213;	// L374
                      v205[v206] = v215;	// L375
                    }
                  }
                }
              }
              int8_t v216 = v205[v206];	// L380
              v194[v197][v206][(v198 - 7)][(v199 - 7)] = v216;	// L381
            }
          }
        }
      }
    }
  }
  return ;	// L388
}

void main_graph_node11(
  int8_t v217[1][512][7][7],
  int8_t v218[512][512][3][3],
  int8_t v219[1][512][7][7]
) {	// L390
  #pragma HLS dataflow

  int8_t v220[1][512][9][9];	// L392
  #pragma HLS stream variable=v220 depth=10 type=fifo

  #pragma HLS bind_storage variable=v220 type=ram_t2p impl=bram

  for (int v221 = 0; v221 < 1; v221 += 1) {	// L393
    for (int v222 = 0; v222 < 9; v222 += 1) {	// L394
      for (int v223 = 0; v223 < 9; v223 += 1) {	// L395
        for (int v224 = 0; v224 < 512; v224 += 1) {	// L396
          int8_t v225;	// L397
          v225 = (int8_t)0.000000;	// L398
          if (((-v222) + 6) >= 0 && ((-v223) + 6) >= 0) {	// L399
            int8_t v226 = v217[v221][v224][v222][v223];	// L400
            v225 = v226;	// L401
          }
          int8_t v227 = v225;	// L403
          v220[v221][v224][v222][v223] = v227;	// L404
        }
      }
    }
  }
  int8_t v228[1][512][3][9];	// L409
  #pragma HLS array_partition variable=v228 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v228 type=ram_2p impl=bram

  int8_t v229[1][512][3][3];	// L410
  #pragma HLS array_partition variable=v229 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v229 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v229 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v229 type=ram_2p impl=lutram

  for (int v230 = 0; v230 < 1; v230 += 1) {	// L411
    for (int v231 = 0; v231 < 9; v231 += 1) {	// L412
      for (int v232 = 0; v232 < 9; v232 += 1) {	// L413
        for (int v233 = 0; v233 < 512; v233 += 1) {	// L414
          int8_t v234 = v228[v230][v233][1][v232];	// L415
          v228[v230][v233][0][v232] = v234;	// L416
          int8_t v235 = v228[v230][v233][2][v232];	// L417
          v228[v230][v233][1][v232] = v235;	// L418
          int8_t v236 = v220[v230][v233][v231][v232];	// L419
          v228[v230][v233][2][v232] = v236;	// L420
        }
        if ((v231 - 2) >= 0) {	// L422
          for (int v237 = 0; v237 < 512; v237 += 1) {	// L423
            for (int v238 = 0; v238 < 3; v238 += 1) {	// L424
              int8_t v239 = v229[v230][v237][v238][1];	// L425
              v229[v230][v237][v238][0] = v239;	// L426
              int8_t v240 = v229[v230][v237][v238][2];	// L427
              v229[v230][v237][v238][1] = v240;	// L428
              int8_t v241 = v228[v230][v237][v238][v232];	// L429
              v229[v230][v237][v238][2] = v241;	// L430
            }
          }
          if ((v232 - 2) >= 0) {	// L433
            int8_t v242[512];	// L434
            #pragma HLS bind_storage variable=v242 type=ram_2p impl=bram

            for (int v243 = 0; v243 < 512; v243 += 1) {	// L435
              v242[v243] = (int8_t)0.000000;	// L436
              for (int v244 = 0; v244 < 64; v244 += 1) {	// L437
                #pragma HLS pipeline II=1
                for (int v245 = 0; v245 < 8; v245 += 1) {	// L438
                  for (int v246 = 0; v246 < 3; v246 += 1) {	// L439
                    for (int v247 = 0; v247 < 3; v247 += 1) {	// L440
                      int8_t v248 = v229[v230][(v245 + (v244 * 8))][v246][v247];	// L441
                      int8_t v249 = v218[v243][(v245 + (v244 * 8))][v246][v247];	// L442
                      int8_t v250 = v248 * v249;	// L443
                      int8_t v251 = v242[v243];	// L444
                      int8_t v252 = v251 + v250;	// L445
                      v242[v243] = v252;	// L446
                    }
                  }
                }
              }
              int8_t v253 = v242[v243];	// L451
              v219[v230][v243][(v231 - 2)][(v232 - 2)] = v253;	// L452
            }
          }
        }
      }
    }
  }
  return ;	// L459
}

void main_graph_node12(
  int8_t v254[512][256][3][3],
  int8_t v255[1][256][14][14],
  int8_t v256[1][512][7][7]
) {	// L461
  #pragma HLS dataflow

  int8_t v257[1][256][16][16];	// L463
  #pragma HLS stream variable=v257 depth=10 type=fifo

  #pragma HLS bind_storage variable=v257 type=ram_t2p impl=bram

  for (int v258 = 0; v258 < 1; v258 += 1) {	// L464
    for (int v259 = 0; v259 < 16; v259 += 1) {	// L465
      for (int v260 = 0; v260 < 16; v260 += 1) {	// L466
        for (int v261 = 0; v261 < 256; v261 += 1) {	// L467
          int8_t v262;	// L468
          v262 = (int8_t)0.000000;	// L469
          if (((-v259) + 13) >= 0 && ((-v260) + 13) >= 0) {	// L470
            int8_t v263 = v255[v258][v261][v259][v260];	// L471
            v262 = v263;	// L472
          }
          int8_t v264 = v262;	// L474
          v257[v258][v261][v259][v260] = v264;	// L475
        }
      }
    }
  }
  int8_t v265[1][512][7][7];	// L480
  #pragma HLS stream variable=v265 depth=10 type=fifo

  #pragma HLS bind_storage variable=v265 type=ram_t2p impl=bram

  int8_t v266[1][256][3][16];	// L481
  #pragma HLS array_partition variable=v266 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v266 type=ram_2p impl=bram

  int8_t v267[1][256][3][3];	// L482
  #pragma HLS array_partition variable=v267 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v267 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v267 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v267 type=ram_2p impl=lutram

  for (int v268 = 0; v268 < 1; v268 += 1) {	// L483
    for (int v269 = 0; v269 < 16; v269 += 1) {	// L484
      for (int v270 = 0; v270 < 16; v270 += 1) {	// L485
        for (int v271 = 0; v271 < 256; v271 += 1) {	// L486
          int8_t v272 = v266[v268][v271][1][v270];	// L487
          v266[v268][v271][0][v270] = v272;	// L488
          int8_t v273 = v266[v268][v271][2][v270];	// L489
          v266[v268][v271][1][v270] = v273;	// L490
          int8_t v274 = v257[v268][v271][v269][v270];	// L491
          v266[v268][v271][2][v270] = v274;	// L492
        }
        if ((v269 - 9) >= 0) {	// L494
          for (int v275 = 0; v275 < 256; v275 += 1) {	// L495
            for (int v276 = 0; v276 < 3; v276 += 1) {	// L496
              int8_t v277 = v267[v268][v275][v276][1];	// L497
              v267[v268][v275][v276][0] = v277;	// L498
              int8_t v278 = v267[v268][v275][v276][2];	// L499
              v267[v268][v275][v276][1] = v278;	// L500
              int8_t v279 = v266[v268][v275][v276][v270];	// L501
              v267[v268][v275][v276][2] = v279;	// L502
            }
          }
          if ((v270 - 9) >= 0) {	// L505
            int8_t v280[512];	// L506
            #pragma HLS bind_storage variable=v280 type=ram_2p impl=bram

            for (int v281 = 0; v281 < 512; v281 += 1) {	// L507
              v280[v281] = (int8_t)0.000000;	// L508
              for (int v282 = 0; v282 < 32; v282 += 1) {	// L509
                #pragma HLS pipeline II=1
                for (int v283 = 0; v283 < 8; v283 += 1) {	// L510
                  for (int v284 = 0; v284 < 3; v284 += 1) {	// L511
                    for (int v285 = 0; v285 < 3; v285 += 1) {	// L512
                      int8_t v286 = v267[v268][(v283 + (v282 * 8))][v284][v285];	// L513
                      int8_t v287 = v254[v281][(v283 + (v282 * 8))][v284][v285];	// L514
                      int8_t v288 = v286 * v287;	// L515
                      int8_t v289 = v280[v281];	// L516
                      int8_t v290 = v289 + v288;	// L517
                      v280[v281] = v290;	// L518
                    }
                  }
                }
              }
              int8_t v291 = v280[v281];	// L523
              v265[v268][v281][(v269 - 9)][(v270 - 9)] = v291;	// L524
            }
          }
        }
      }
    }
  }
  for (int v292 = 0; v292 < 1; v292 += 1) {	// L531
    for (int v293 = 0; v293 < 7; v293 += 1) {	// L532
      for (int v294 = 0; v294 < 7; v294 += 1) {	// L533
        for (int v295 = 0; v295 < 512; v295 += 1) {	// L534
          int8_t v296 = v265[0][v295][v293][v294];	// L535
          bool v297 = v296 > (int8_t)0.000000;	// L536
          int8_t v298 = v297 ? v296 : (int8_t)0.000000;	// L537
          v256[v292][v295][v293][v294] = v298;	// L538
        }
      }
    }
  }
  return ;	// L543
}

void main_graph_node13(
  int8_t v299[1][256][14][14],
  int8_t v300[1][256][14][14],
  int8_t v301[1][256][14][14]
) {	// L545
  #pragma HLS dataflow

  for (int v302 = 0; v302 < 1; v302 += 1) {	// L546
    for (int v303 = 0; v303 < 14; v303 += 1) {	// L547
      for (int v304 = 0; v304 < 14; v304 += 1) {	// L548
        for (int v305 = 0; v305 < 256; v305 += 1) {	// L549
          int8_t v306 = v299[v302][v305][v303][v304];	// L550
          v300[v302][v305][v303][v304] = v306;	// L551
          int8_t v307 = v299[v302][v305][v303][v304];	// L552
          v301[v302][v305][v303][v304] = v307;	// L553
        }
      }
    }
  }
  return ;	// L558
}

void main_graph_node14(
  int8_t v308[1][256][14][14],
  int8_t v309[1][256][14][14],
  int8_t v310[1][256][14][14]
) {	// L560
  #pragma HLS dataflow

  for (int v311 = 0; v311 < 1; v311 += 1) {	// L562
    for (int v312 = 0; v312 < 14; v312 += 1) {	// L563
      for (int v313 = 0; v313 < 14; v313 += 1) {	// L564
        for (int v314 = 0; v314 < 256; v314 += 1) {	// L565
          int8_t v315 = v308[0][v314][v312][v313];	// L566
          int8_t v316 = v309[0][v314][v312][v313];	// L567
          int8_t v317 = v315 + v316;	// L568
          bool v318 = v317 > (int8_t)0.000000;	// L569
          int8_t v319 = v318 ? v317 : (int8_t)0.000000;	// L570
          v310[v311][v314][v312][v313] = v319;	// L571
        }
      }
    }
  }
  return ;	// L576
}

void main_graph_node15(
  int8_t v320[256][256][3][3],
  int8_t v321[1][256][14][14],
  int8_t v322[1][256][14][14]
) {	// L578
  #pragma HLS dataflow

  int8_t v323[1][256][16][16];	// L580
  #pragma HLS stream variable=v323 depth=10 type=fifo

  #pragma HLS bind_storage variable=v323 type=ram_t2p impl=bram

  for (int v324 = 0; v324 < 1; v324 += 1) {	// L581
    for (int v325 = 0; v325 < 16; v325 += 1) {	// L582
      for (int v326 = 0; v326 < 16; v326 += 1) {	// L583
        for (int v327 = 0; v327 < 256; v327 += 1) {	// L584
          int8_t v328;	// L585
          v328 = (int8_t)0.000000;	// L586
          if (((-v325) + 13) >= 0 && ((-v326) + 13) >= 0) {	// L587
            int8_t v329 = v321[v324][v327][v325][v326];	// L588
            v328 = v329;	// L589
          }
          int8_t v330 = v328;	// L591
          v323[v324][v327][v325][v326] = v330;	// L592
        }
      }
    }
  }
  int8_t v331[1][256][3][16];	// L597
  #pragma HLS array_partition variable=v331 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v331 type=ram_2p impl=bram

  int8_t v332[1][256][3][3];	// L598
  #pragma HLS array_partition variable=v332 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v332 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v332 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v332 type=ram_2p impl=lutram

  for (int v333 = 0; v333 < 1; v333 += 1) {	// L599
    for (int v334 = 0; v334 < 16; v334 += 1) {	// L600
      for (int v335 = 0; v335 < 16; v335 += 1) {	// L601
        for (int v336 = 0; v336 < 256; v336 += 1) {	// L602
          int8_t v337 = v331[v333][v336][1][v335];	// L603
          v331[v333][v336][0][v335] = v337;	// L604
          int8_t v338 = v331[v333][v336][2][v335];	// L605
          v331[v333][v336][1][v335] = v338;	// L606
          int8_t v339 = v323[v333][v336][v334][v335];	// L607
          v331[v333][v336][2][v335] = v339;	// L608
        }
        if ((v334 - 2) >= 0) {	// L610
          for (int v340 = 0; v340 < 256; v340 += 1) {	// L611
            for (int v341 = 0; v341 < 3; v341 += 1) {	// L612
              int8_t v342 = v332[v333][v340][v341][1];	// L613
              v332[v333][v340][v341][0] = v342;	// L614
              int8_t v343 = v332[v333][v340][v341][2];	// L615
              v332[v333][v340][v341][1] = v343;	// L616
              int8_t v344 = v331[v333][v340][v341][v335];	// L617
              v332[v333][v340][v341][2] = v344;	// L618
            }
          }
          if ((v335 - 2) >= 0) {	// L621
            int8_t v345[256];	// L622
            #pragma HLS bind_storage variable=v345 type=ram_2p impl=bram

            for (int v346 = 0; v346 < 256; v346 += 1) {	// L623
              v345[v346] = (int8_t)0.000000;	// L624
              for (int v347 = 0; v347 < 64; v347 += 1) {	// L625
                #pragma HLS pipeline II=1
                for (int v348 = 0; v348 < 4; v348 += 1) {	// L626
                  for (int v349 = 0; v349 < 3; v349 += 1) {	// L627
                    for (int v350 = 0; v350 < 3; v350 += 1) {	// L628
                      int8_t v351 = v332[v333][(v348 + (v347 * 4))][v349][v350];	// L629
                      int8_t v352 = v320[v346][(v348 + (v347 * 4))][v349][v350];	// L630
                      int8_t v353 = v351 * v352;	// L631
                      int8_t v354 = v345[v346];	// L632
                      int8_t v355 = v354 + v353;	// L633
                      v345[v346] = v355;	// L634
                    }
                  }
                }
              }
              int8_t v356 = v345[v346];	// L639
              v322[v333][v346][(v334 - 2)][(v335 - 2)] = v356;	// L640
            }
          }
        }
      }
    }
  }
  return ;	// L647
}

void main_graph_node16(
  int8_t v357[256][256][3][3],
  int8_t v358[1][256][14][14],
  int8_t v359[1][256][14][14]
) {	// L649
  #pragma HLS dataflow

  int8_t v360[1][256][16][16];	// L651
  #pragma HLS stream variable=v360 depth=10 type=fifo

  #pragma HLS bind_storage variable=v360 type=ram_t2p impl=bram

  for (int v361 = 0; v361 < 1; v361 += 1) {	// L652
    for (int v362 = 0; v362 < 16; v362 += 1) {	// L653
      for (int v363 = 0; v363 < 16; v363 += 1) {	// L654
        for (int v364 = 0; v364 < 256; v364 += 1) {	// L655
          int8_t v365;	// L656
          v365 = (int8_t)0.000000;	// L657
          if (((-v362) + 13) >= 0 && ((-v363) + 13) >= 0) {	// L658
            int8_t v366 = v358[v361][v364][v362][v363];	// L659
            v365 = v366;	// L660
          }
          int8_t v367 = v365;	// L662
          v360[v361][v364][v362][v363] = v367;	// L663
        }
      }
    }
  }
  int8_t v368[1][256][14][14];	// L668
  #pragma HLS stream variable=v368 depth=10 type=fifo

  #pragma HLS bind_storage variable=v368 type=ram_t2p impl=bram

  int8_t v369[1][256][3][16];	// L669
  #pragma HLS array_partition variable=v369 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v369 type=ram_2p impl=bram

  int8_t v370[1][256][3][3];	// L670
  #pragma HLS array_partition variable=v370 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v370 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v370 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v370 type=ram_2p impl=lutram

  for (int v371 = 0; v371 < 1; v371 += 1) {	// L671
    for (int v372 = 0; v372 < 16; v372 += 1) {	// L672
      for (int v373 = 0; v373 < 16; v373 += 1) {	// L673
        for (int v374 = 0; v374 < 256; v374 += 1) {	// L674
          int8_t v375 = v369[v371][v374][1][v373];	// L675
          v369[v371][v374][0][v373] = v375;	// L676
          int8_t v376 = v369[v371][v374][2][v373];	// L677
          v369[v371][v374][1][v373] = v376;	// L678
          int8_t v377 = v360[v371][v374][v372][v373];	// L679
          v369[v371][v374][2][v373] = v377;	// L680
        }
        if ((v372 - 2) >= 0) {	// L682
          for (int v378 = 0; v378 < 256; v378 += 1) {	// L683
            for (int v379 = 0; v379 < 3; v379 += 1) {	// L684
              int8_t v380 = v370[v371][v378][v379][1];	// L685
              v370[v371][v378][v379][0] = v380;	// L686
              int8_t v381 = v370[v371][v378][v379][2];	// L687
              v370[v371][v378][v379][1] = v381;	// L688
              int8_t v382 = v369[v371][v378][v379][v373];	// L689
              v370[v371][v378][v379][2] = v382;	// L690
            }
          }
          if ((v373 - 2) >= 0) {	// L693
            int8_t v383[256];	// L694
            #pragma HLS bind_storage variable=v383 type=ram_2p impl=bram

            for (int v384 = 0; v384 < 256; v384 += 1) {	// L695
              v383[v384] = (int8_t)0.000000;	// L696
              for (int v385 = 0; v385 < 64; v385 += 1) {	// L697
                #pragma HLS pipeline II=1
                for (int v386 = 0; v386 < 4; v386 += 1) {	// L698
                  for (int v387 = 0; v387 < 3; v387 += 1) {	// L699
                    for (int v388 = 0; v388 < 3; v388 += 1) {	// L700
                      int8_t v389 = v370[v371][(v386 + (v385 * 4))][v387][v388];	// L701
                      int8_t v390 = v357[v384][(v386 + (v385 * 4))][v387][v388];	// L702
                      int8_t v391 = v389 * v390;	// L703
                      int8_t v392 = v383[v384];	// L704
                      int8_t v393 = v392 + v391;	// L705
                      v383[v384] = v393;	// L706
                    }
                  }
                }
              }
              int8_t v394 = v383[v384];	// L711
              v368[v371][v384][(v372 - 2)][(v373 - 2)] = v394;	// L712
            }
          }
        }
      }
    }
  }
  for (int v395 = 0; v395 < 1; v395 += 1) {	// L719
    for (int v396 = 0; v396 < 14; v396 += 1) {	// L720
      for (int v397 = 0; v397 < 14; v397 += 1) {	// L721
        for (int v398 = 0; v398 < 256; v398 += 1) {	// L722
          int8_t v399 = v368[0][v398][v396][v397];	// L723
          bool v400 = v399 > (int8_t)0.000000;	// L724
          int8_t v401 = v400 ? v399 : (int8_t)0.000000;	// L725
          v359[v395][v398][v396][v397] = v401;	// L726
        }
      }
    }
  }
  return ;	// L731
}

void main_graph_node17(
  int8_t v402[1][256][14][14],
  int8_t v403[1][256][14][14],
  int8_t v404[1][256][14][14]
) {	// L733
  #pragma HLS dataflow

  for (int v405 = 0; v405 < 1; v405 += 1) {	// L734
    for (int v406 = 0; v406 < 14; v406 += 1) {	// L735
      for (int v407 = 0; v407 < 14; v407 += 1) {	// L736
        for (int v408 = 0; v408 < 256; v408 += 1) {	// L737
          int8_t v409 = v402[v405][v408][v406][v407];	// L738
          v403[v405][v408][v406][v407] = v409;	// L739
          int8_t v410 = v402[v405][v408][v406][v407];	// L740
          v404[v405][v408][v406][v407] = v410;	// L741
        }
      }
    }
  }
  return ;	// L746
}

void main_graph_node18(
  int8_t v411[1][256][14][14],
  int8_t v412[1][256][14][14],
  int8_t v413[1][256][14][14]
) {	// L748
  #pragma HLS dataflow

  for (int v414 = 0; v414 < 1; v414 += 1) {	// L750
    for (int v415 = 0; v415 < 14; v415 += 1) {	// L751
      for (int v416 = 0; v416 < 14; v416 += 1) {	// L752
        for (int v417 = 0; v417 < 256; v417 += 1) {	// L753
          int8_t v418 = v411[0][v417][v415][v416];	// L754
          int8_t v419 = v412[0][v417][v415][v416];	// L755
          int8_t v420 = v418 + v419;	// L756
          bool v421 = v420 > (int8_t)0.000000;	// L757
          int8_t v422 = v421 ? v420 : (int8_t)0.000000;	// L758
          v413[v414][v417][v415][v416] = v422;	// L759
        }
      }
    }
  }
  return ;	// L764
}

void main_graph_node19(
  int8_t v423[256][128][1][1],
  int8_t v424[1][128][28][28],
  int8_t v425[1][256][14][14]
) {	// L766
  #pragma HLS dataflow

  int8_t v426[1][128][1][28];	// L768
  #pragma HLS bind_storage variable=v426 type=ram_2p impl=bram

  int8_t v427[1][128][1][1];	// L769
  #pragma HLS array_partition variable=v427 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v427 type=ram_2p impl=lutram

  for (int v428 = 0; v428 < 1; v428 += 1) {	// L770
    for (int v429 = 0; v429 < 28; v429 += 1) {	// L771
      for (int v430 = 0; v430 < 28; v430 += 1) {	// L772
        for (int v431 = 0; v431 < 128; v431 += 1) {	// L773
          int8_t v432 = v424[v428][v431][v429][v430];	// L774
          v426[v428][v431][0][v430] = v432;	// L775
        }
        if ((v429 - 14) >= 0) {	// L777
          for (int v433 = 0; v433 < 128; v433 += 1) {	// L778
            for (int v434 = 0; v434 < 1; v434 += 1) {	// L779
              int8_t v435 = v426[v428][v433][v434][v430];	// L780
              v427[v428][v433][v434][0] = v435;	// L781
            }
          }
          if ((v430 - 14) >= 0) {	// L784
            int8_t v436[256];	// L785
            #pragma HLS bind_storage variable=v436 type=ram_2p impl=bram

            for (int v437 = 0; v437 < 256; v437 += 1) {	// L786
              v436[v437] = (int8_t)0.000000;	// L787
              for (int v438 = 0; v438 < 16; v438 += 1) {	// L788
                #pragma HLS pipeline II=1
                for (int v439 = 0; v439 < 8; v439 += 1) {	// L789
                  for (int v440 = 0; v440 < 1; v440 += 1) {	// L790
                    for (int v441 = 0; v441 < 1; v441 += 1) {	// L791
                      int8_t v442 = v427[v428][(v439 + (v438 * 8))][v440][v441];	// L792
                      int8_t v443 = v423[v437][(v439 + (v438 * 8))][v440][v441];	// L793
                      int8_t v444 = v442 * v443;	// L794
                      int8_t v445 = v436[v437];	// L795
                      int8_t v446 = v445 + v444;	// L796
                      v436[v437] = v446;	// L797
                    }
                  }
                }
              }
              int8_t v447 = v436[v437];	// L802
              v425[v428][v437][(v429 - 14)][(v430 - 14)] = v447;	// L803
            }
          }
        }
      }
    }
  }
  return ;	// L810
}

void main_graph_node20(
  int8_t v448[256][256][3][3],
  int8_t v449[1][256][14][14],
  int8_t v450[1][256][14][14]
) {	// L812
  #pragma HLS dataflow

  int8_t v451[1][256][16][16];	// L814
  #pragma HLS stream variable=v451 depth=10 type=fifo

  #pragma HLS bind_storage variable=v451 type=ram_t2p impl=bram

  for (int v452 = 0; v452 < 1; v452 += 1) {	// L815
    for (int v453 = 0; v453 < 16; v453 += 1) {	// L816
      for (int v454 = 0; v454 < 16; v454 += 1) {	// L817
        for (int v455 = 0; v455 < 256; v455 += 1) {	// L818
          int8_t v456;	// L819
          v456 = (int8_t)0.000000;	// L820
          if (((-v453) + 13) >= 0 && ((-v454) + 13) >= 0) {	// L821
            int8_t v457 = v449[v452][v455][v453][v454];	// L822
            v456 = v457;	// L823
          }
          int8_t v458 = v456;	// L825
          v451[v452][v455][v453][v454] = v458;	// L826
        }
      }
    }
  }
  int8_t v459[1][256][3][16];	// L831
  #pragma HLS array_partition variable=v459 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v459 type=ram_2p impl=bram

  int8_t v460[1][256][3][3];	// L832
  #pragma HLS array_partition variable=v460 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v460 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v460 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v460 type=ram_2p impl=lutram

  for (int v461 = 0; v461 < 1; v461 += 1) {	// L833
    for (int v462 = 0; v462 < 16; v462 += 1) {	// L834
      for (int v463 = 0; v463 < 16; v463 += 1) {	// L835
        for (int v464 = 0; v464 < 256; v464 += 1) {	// L836
          int8_t v465 = v459[v461][v464][1][v463];	// L837
          v459[v461][v464][0][v463] = v465;	// L838
          int8_t v466 = v459[v461][v464][2][v463];	// L839
          v459[v461][v464][1][v463] = v466;	// L840
          int8_t v467 = v451[v461][v464][v462][v463];	// L841
          v459[v461][v464][2][v463] = v467;	// L842
        }
        if ((v462 - 2) >= 0) {	// L844
          for (int v468 = 0; v468 < 256; v468 += 1) {	// L845
            for (int v469 = 0; v469 < 3; v469 += 1) {	// L846
              int8_t v470 = v460[v461][v468][v469][1];	// L847
              v460[v461][v468][v469][0] = v470;	// L848
              int8_t v471 = v460[v461][v468][v469][2];	// L849
              v460[v461][v468][v469][1] = v471;	// L850
              int8_t v472 = v459[v461][v468][v469][v463];	// L851
              v460[v461][v468][v469][2] = v472;	// L852
            }
          }
          if ((v463 - 2) >= 0) {	// L855
            int8_t v473[256];	// L856
            #pragma HLS bind_storage variable=v473 type=ram_2p impl=bram

            for (int v474 = 0; v474 < 256; v474 += 1) {	// L857
              v473[v474] = (int8_t)0.000000;	// L858
              for (int v475 = 0; v475 < 64; v475 += 1) {	// L859
                #pragma HLS pipeline II=1
                for (int v476 = 0; v476 < 4; v476 += 1) {	// L860
                  for (int v477 = 0; v477 < 3; v477 += 1) {	// L861
                    for (int v478 = 0; v478 < 3; v478 += 1) {	// L862
                      int8_t v479 = v460[v461][(v476 + (v475 * 4))][v477][v478];	// L863
                      int8_t v480 = v448[v474][(v476 + (v475 * 4))][v477][v478];	// L864
                      int8_t v481 = v479 * v480;	// L865
                      int8_t v482 = v473[v474];	// L866
                      int8_t v483 = v482 + v481;	// L867
                      v473[v474] = v483;	// L868
                    }
                  }
                }
              }
              int8_t v484 = v473[v474];	// L873
              v450[v461][v474][(v462 - 2)][(v463 - 2)] = v484;	// L874
            }
          }
        }
      }
    }
  }
  return ;	// L881
}

void main_graph_node21(
  int8_t v485[1][128][28][28],
  int8_t v486[256][128][3][3],
  int8_t v487[1][256][14][14]
) {	// L883
  #pragma HLS dataflow

  int8_t v488[1][128][30][30];	// L885
  #pragma HLS stream variable=v488 depth=10 type=fifo

  #pragma HLS bind_storage variable=v488 type=ram_t2p impl=bram

  for (int v489 = 0; v489 < 1; v489 += 1) {	// L886
    for (int v490 = 0; v490 < 30; v490 += 1) {	// L887
      for (int v491 = 0; v491 < 30; v491 += 1) {	// L888
        for (int v492 = 0; v492 < 128; v492 += 1) {	// L889
          int8_t v493;	// L890
          v493 = (int8_t)0.000000;	// L891
          if (((-v490) + 27) >= 0 && ((-v491) + 27) >= 0) {	// L892
            int8_t v494 = v485[v489][v492][v490][v491];	// L893
            v493 = v494;	// L894
          }
          int8_t v495 = v493;	// L896
          v488[v489][v492][v490][v491] = v495;	// L897
        }
      }
    }
  }
  int8_t v496[1][256][14][14];	// L902
  #pragma HLS stream variable=v496 depth=10 type=fifo

  #pragma HLS bind_storage variable=v496 type=ram_t2p impl=bram

  int8_t v497[1][128][3][30];	// L903
  #pragma HLS array_partition variable=v497 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v497 type=ram_2p impl=bram

  int8_t v498[1][128][3][3];	// L904
  #pragma HLS array_partition variable=v498 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v498 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v498 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v498 type=ram_2p impl=lutram

  for (int v499 = 0; v499 < 1; v499 += 1) {	// L905
    for (int v500 = 0; v500 < 30; v500 += 1) {	// L906
      for (int v501 = 0; v501 < 30; v501 += 1) {	// L907
        for (int v502 = 0; v502 < 128; v502 += 1) {	// L908
          int8_t v503 = v497[v499][v502][1][v501];	// L909
          v497[v499][v502][0][v501] = v503;	// L910
          int8_t v504 = v497[v499][v502][2][v501];	// L911
          v497[v499][v502][1][v501] = v504;	// L912
          int8_t v505 = v488[v499][v502][v500][v501];	// L913
          v497[v499][v502][2][v501] = v505;	// L914
        }
        if ((v500 - 16) >= 0) {	// L916
          for (int v506 = 0; v506 < 128; v506 += 1) {	// L917
            for (int v507 = 0; v507 < 3; v507 += 1) {	// L918
              int8_t v508 = v498[v499][v506][v507][1];	// L919
              v498[v499][v506][v507][0] = v508;	// L920
              int8_t v509 = v498[v499][v506][v507][2];	// L921
              v498[v499][v506][v507][1] = v509;	// L922
              int8_t v510 = v497[v499][v506][v507][v501];	// L923
              v498[v499][v506][v507][2] = v510;	// L924
            }
          }
          if ((v501 - 16) >= 0) {	// L927
            int8_t v511[256];	// L928
            #pragma HLS bind_storage variable=v511 type=ram_2p impl=bram

            for (int v512 = 0; v512 < 256; v512 += 1) {	// L929
              v511[v512] = (int8_t)0.000000;	// L930
              for (int v513 = 0; v513 < 16; v513 += 1) {	// L931
                #pragma HLS pipeline II=1
                for (int v514 = 0; v514 < 8; v514 += 1) {	// L932
                  for (int v515 = 0; v515 < 3; v515 += 1) {	// L933
                    for (int v516 = 0; v516 < 3; v516 += 1) {	// L934
                      int8_t v517 = v498[v499][(v514 + (v513 * 8))][v515][v516];	// L935
                      int8_t v518 = v486[v512][(v514 + (v513 * 8))][v515][v516];	// L936
                      int8_t v519 = v517 * v518;	// L937
                      int8_t v520 = v511[v512];	// L938
                      int8_t v521 = v520 + v519;	// L939
                      v511[v512] = v521;	// L940
                    }
                  }
                }
              }
              int8_t v522 = v511[v512];	// L945
              v496[v499][v512][(v500 - 16)][(v501 - 16)] = v522;	// L946
            }
          }
        }
      }
    }
  }
  for (int v523 = 0; v523 < 1; v523 += 1) {	// L953
    for (int v524 = 0; v524 < 14; v524 += 1) {	// L954
      for (int v525 = 0; v525 < 14; v525 += 1) {	// L955
        for (int v526 = 0; v526 < 256; v526 += 1) {	// L956
          int8_t v527 = v496[0][v526][v524][v525];	// L957
          bool v528 = v527 > (int8_t)0.000000;	// L958
          int8_t v529 = v528 ? v527 : (int8_t)0.000000;	// L959
          v487[v523][v526][v524][v525] = v529;	// L960
        }
      }
    }
  }
  return ;	// L965
}

void main_graph_node22(
  int8_t v530[1][128][28][28],
  int8_t v531[1][128][28][28],
  int8_t v532[1][128][28][28]
) {	// L967
  #pragma HLS dataflow

  for (int v533 = 0; v533 < 1; v533 += 1) {	// L968
    for (int v534 = 0; v534 < 28; v534 += 1) {	// L969
      for (int v535 = 0; v535 < 28; v535 += 1) {	// L970
        for (int v536 = 0; v536 < 128; v536 += 1) {	// L971
          int8_t v537 = v530[v533][v536][v534][v535];	// L972
          v531[v533][v536][v534][v535] = v537;	// L973
          int8_t v538 = v530[v533][v536][v534][v535];	// L974
          v532[v533][v536][v534][v535] = v538;	// L975
        }
      }
    }
  }
  return ;	// L980
}

void main_graph_node23(
  int8_t v539[1][128][28][28],
  int8_t v540[1][128][28][28],
  int8_t v541[1][128][28][28]
) {	// L982
  #pragma HLS dataflow

  for (int v542 = 0; v542 < 1; v542 += 1) {	// L984
    for (int v543 = 0; v543 < 28; v543 += 1) {	// L985
      for (int v544 = 0; v544 < 28; v544 += 1) {	// L986
        for (int v545 = 0; v545 < 128; v545 += 1) {	// L987
          int8_t v546 = v539[0][v545][v543][v544];	// L988
          int8_t v547 = v540[0][v545][v543][v544];	// L989
          int8_t v548 = v546 + v547;	// L990
          bool v549 = v548 > (int8_t)0.000000;	// L991
          int8_t v550 = v549 ? v548 : (int8_t)0.000000;	// L992
          v541[v542][v545][v543][v544] = v550;	// L993
        }
      }
    }
  }
  return ;	// L998
}

void main_graph_node24(
  int8_t v551[128][128][3][3],
  int8_t v552[1][128][28][28],
  int8_t v553[1][128][28][28]
) {	// L1000
  #pragma HLS dataflow

  int8_t v554[1][128][30][30];	// L1002
  #pragma HLS stream variable=v554 depth=10 type=fifo

  #pragma HLS bind_storage variable=v554 type=ram_t2p impl=bram

  for (int v555 = 0; v555 < 1; v555 += 1) {	// L1003
    for (int v556 = 0; v556 < 30; v556 += 1) {	// L1004
      for (int v557 = 0; v557 < 30; v557 += 1) {	// L1005
        for (int v558 = 0; v558 < 128; v558 += 1) {	// L1006
          int8_t v559;	// L1007
          v559 = (int8_t)0.000000;	// L1008
          if (((-v556) + 27) >= 0 && ((-v557) + 27) >= 0) {	// L1009
            int8_t v560 = v552[v555][v558][v556][v557];	// L1010
            v559 = v560;	// L1011
          }
          int8_t v561 = v559;	// L1013
          v554[v555][v558][v556][v557] = v561;	// L1014
        }
      }
    }
  }
  int8_t v562[1][128][3][30];	// L1019
  #pragma HLS array_partition variable=v562 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v562 type=ram_2p impl=bram

  int8_t v563[1][128][3][3];	// L1020
  #pragma HLS array_partition variable=v563 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v563 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v563 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v563 type=ram_2p impl=lutram

  for (int v564 = 0; v564 < 1; v564 += 1) {	// L1021
    for (int v565 = 0; v565 < 30; v565 += 1) {	// L1022
      for (int v566 = 0; v566 < 30; v566 += 1) {	// L1023
        for (int v567 = 0; v567 < 128; v567 += 1) {	// L1024
          int8_t v568 = v562[v564][v567][1][v566];	// L1025
          v562[v564][v567][0][v566] = v568;	// L1026
          int8_t v569 = v562[v564][v567][2][v566];	// L1027
          v562[v564][v567][1][v566] = v569;	// L1028
          int8_t v570 = v554[v564][v567][v565][v566];	// L1029
          v562[v564][v567][2][v566] = v570;	// L1030
        }
        if ((v565 - 2) >= 0) {	// L1032
          for (int v571 = 0; v571 < 128; v571 += 1) {	// L1033
            for (int v572 = 0; v572 < 3; v572 += 1) {	// L1034
              int8_t v573 = v563[v564][v571][v572][1];	// L1035
              v563[v564][v571][v572][0] = v573;	// L1036
              int8_t v574 = v563[v564][v571][v572][2];	// L1037
              v563[v564][v571][v572][1] = v574;	// L1038
              int8_t v575 = v562[v564][v571][v572][v566];	// L1039
              v563[v564][v571][v572][2] = v575;	// L1040
            }
          }
          if ((v566 - 2) >= 0) {	// L1043
            int8_t v576[128];	// L1044
            #pragma HLS bind_storage variable=v576 type=ram_2p impl=bram

            for (int v577 = 0; v577 < 128; v577 += 1) {	// L1045
              v576[v577] = (int8_t)0.000000;	// L1046
              for (int v578 = 0; v578 < 32; v578 += 1) {	// L1047
                #pragma HLS pipeline II=1
                for (int v579 = 0; v579 < 4; v579 += 1) {	// L1048
                  for (int v580 = 0; v580 < 3; v580 += 1) {	// L1049
                    for (int v581 = 0; v581 < 3; v581 += 1) {	// L1050
                      int8_t v582 = v563[v564][(v579 + (v578 * 4))][v580][v581];	// L1051
                      int8_t v583 = v551[v577][(v579 + (v578 * 4))][v580][v581];	// L1052
                      int8_t v584 = v582 * v583;	// L1053
                      int8_t v585 = v576[v577];	// L1054
                      int8_t v586 = v585 + v584;	// L1055
                      v576[v577] = v586;	// L1056
                    }
                  }
                }
              }
              int8_t v587 = v576[v577];	// L1061
              v553[v564][v577][(v565 - 2)][(v566 - 2)] = v587;	// L1062
            }
          }
        }
      }
    }
  }
  return ;	// L1069
}

void main_graph_node25(
  int8_t v588[128][128][3][3],
  int8_t v589[1][128][28][28],
  int8_t v590[1][128][28][28]
) {	// L1071
  #pragma HLS dataflow

  int8_t v591[1][128][30][30];	// L1073
  #pragma HLS stream variable=v591 depth=10 type=fifo

  #pragma HLS bind_storage variable=v591 type=ram_t2p impl=bram

  for (int v592 = 0; v592 < 1; v592 += 1) {	// L1074
    for (int v593 = 0; v593 < 30; v593 += 1) {	// L1075
      for (int v594 = 0; v594 < 30; v594 += 1) {	// L1076
        for (int v595 = 0; v595 < 128; v595 += 1) {	// L1077
          int8_t v596;	// L1078
          v596 = (int8_t)0.000000;	// L1079
          if (((-v593) + 27) >= 0 && ((-v594) + 27) >= 0) {	// L1080
            int8_t v597 = v589[v592][v595][v593][v594];	// L1081
            v596 = v597;	// L1082
          }
          int8_t v598 = v596;	// L1084
          v591[v592][v595][v593][v594] = v598;	// L1085
        }
      }
    }
  }
  int8_t v599[1][128][28][28];	// L1090
  #pragma HLS stream variable=v599 depth=10 type=fifo

  #pragma HLS bind_storage variable=v599 type=ram_t2p impl=bram

  int8_t v600[1][128][3][30];	// L1091
  #pragma HLS array_partition variable=v600 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v600 type=ram_2p impl=bram

  int8_t v601[1][128][3][3];	// L1092
  #pragma HLS array_partition variable=v601 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v601 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v601 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v601 type=ram_2p impl=lutram

  for (int v602 = 0; v602 < 1; v602 += 1) {	// L1093
    for (int v603 = 0; v603 < 30; v603 += 1) {	// L1094
      for (int v604 = 0; v604 < 30; v604 += 1) {	// L1095
        for (int v605 = 0; v605 < 128; v605 += 1) {	// L1096
          int8_t v606 = v600[v602][v605][1][v604];	// L1097
          v600[v602][v605][0][v604] = v606;	// L1098
          int8_t v607 = v600[v602][v605][2][v604];	// L1099
          v600[v602][v605][1][v604] = v607;	// L1100
          int8_t v608 = v591[v602][v605][v603][v604];	// L1101
          v600[v602][v605][2][v604] = v608;	// L1102
        }
        if ((v603 - 2) >= 0) {	// L1104
          for (int v609 = 0; v609 < 128; v609 += 1) {	// L1105
            for (int v610 = 0; v610 < 3; v610 += 1) {	// L1106
              int8_t v611 = v601[v602][v609][v610][1];	// L1107
              v601[v602][v609][v610][0] = v611;	// L1108
              int8_t v612 = v601[v602][v609][v610][2];	// L1109
              v601[v602][v609][v610][1] = v612;	// L1110
              int8_t v613 = v600[v602][v609][v610][v604];	// L1111
              v601[v602][v609][v610][2] = v613;	// L1112
            }
          }
          if ((v604 - 2) >= 0) {	// L1115
            int8_t v614[128];	// L1116
            #pragma HLS bind_storage variable=v614 type=ram_2p impl=bram

            for (int v615 = 0; v615 < 128; v615 += 1) {	// L1117
              v614[v615] = (int8_t)0.000000;	// L1118
              for (int v616 = 0; v616 < 32; v616 += 1) {	// L1119
                #pragma HLS pipeline II=1
                for (int v617 = 0; v617 < 4; v617 += 1) {	// L1120
                  for (int v618 = 0; v618 < 3; v618 += 1) {	// L1121
                    for (int v619 = 0; v619 < 3; v619 += 1) {	// L1122
                      int8_t v620 = v601[v602][(v617 + (v616 * 4))][v618][v619];	// L1123
                      int8_t v621 = v588[v615][(v617 + (v616 * 4))][v618][v619];	// L1124
                      int8_t v622 = v620 * v621;	// L1125
                      int8_t v623 = v614[v615];	// L1126
                      int8_t v624 = v623 + v622;	// L1127
                      v614[v615] = v624;	// L1128
                    }
                  }
                }
              }
              int8_t v625 = v614[v615];	// L1133
              v599[v602][v615][(v603 - 2)][(v604 - 2)] = v625;	// L1134
            }
          }
        }
      }
    }
  }
  for (int v626 = 0; v626 < 1; v626 += 1) {	// L1141
    for (int v627 = 0; v627 < 28; v627 += 1) {	// L1142
      for (int v628 = 0; v628 < 28; v628 += 1) {	// L1143
        for (int v629 = 0; v629 < 128; v629 += 1) {	// L1144
          int8_t v630 = v599[0][v629][v627][v628];	// L1145
          bool v631 = v630 > (int8_t)0.000000;	// L1146
          int8_t v632 = v631 ? v630 : (int8_t)0.000000;	// L1147
          v590[v626][v629][v627][v628] = v632;	// L1148
        }
      }
    }
  }
  return ;	// L1153
}

void main_graph_node26(
  int8_t v633[1][128][28][28],
  int8_t v634[1][128][28][28],
  int8_t v635[1][128][28][28]
) {	// L1155
  #pragma HLS dataflow

  for (int v636 = 0; v636 < 1; v636 += 1) {	// L1156
    for (int v637 = 0; v637 < 28; v637 += 1) {	// L1157
      for (int v638 = 0; v638 < 28; v638 += 1) {	// L1158
        for (int v639 = 0; v639 < 128; v639 += 1) {	// L1159
          int8_t v640 = v633[v636][v639][v637][v638];	// L1160
          v634[v636][v639][v637][v638] = v640;	// L1161
          int8_t v641 = v633[v636][v639][v637][v638];	// L1162
          v635[v636][v639][v637][v638] = v641;	// L1163
        }
      }
    }
  }
  return ;	// L1168
}

void main_graph_node27(
  int8_t v642[1][128][28][28],
  int8_t v643[1][128][28][28],
  int8_t v644[1][128][28][28]
) {	// L1170
  #pragma HLS dataflow

  for (int v645 = 0; v645 < 1; v645 += 1) {	// L1172
    for (int v646 = 0; v646 < 28; v646 += 1) {	// L1173
      for (int v647 = 0; v647 < 28; v647 += 1) {	// L1174
        for (int v648 = 0; v648 < 128; v648 += 1) {	// L1175
          int8_t v649 = v642[0][v648][v646][v647];	// L1176
          int8_t v650 = v643[0][v648][v646][v647];	// L1177
          int8_t v651 = v649 + v650;	// L1178
          bool v652 = v651 > (int8_t)0.000000;	// L1179
          int8_t v653 = v652 ? v651 : (int8_t)0.000000;	// L1180
          v644[v645][v648][v646][v647] = v653;	// L1181
        }
      }
    }
  }
  return ;	// L1186
}

void main_graph_node28(
  int8_t v654[128][64][1][1],
  int8_t v655[1][64][56][56],
  int8_t v656[1][128][28][28]
) {	// L1188
  #pragma HLS dataflow

  int8_t v657[1][64][1][56];	// L1190
  #pragma HLS bind_storage variable=v657 type=ram_2p impl=bram

  int8_t v658[1][64][1][1];	// L1191
  #pragma HLS array_partition variable=v658 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v658 type=ram_2p impl=lutram

  for (int v659 = 0; v659 < 1; v659 += 1) {	// L1192
    for (int v660 = 0; v660 < 56; v660 += 1) {	// L1193
      for (int v661 = 0; v661 < 56; v661 += 1) {	// L1194
        for (int v662 = 0; v662 < 64; v662 += 1) {	// L1195
          int8_t v663 = v655[v659][v662][v660][v661];	// L1196
          v657[v659][v662][0][v661] = v663;	// L1197
        }
        if ((v660 - 28) >= 0) {	// L1199
          for (int v664 = 0; v664 < 64; v664 += 1) {	// L1200
            for (int v665 = 0; v665 < 1; v665 += 1) {	// L1201
              int8_t v666 = v657[v659][v664][v665][v661];	// L1202
              v658[v659][v664][v665][0] = v666;	// L1203
            }
          }
          if ((v661 - 28) >= 0) {	// L1206
            int8_t v667[128];	// L1207
            #pragma HLS bind_storage variable=v667 type=ram_2p impl=bram

            for (int v668 = 0; v668 < 128; v668 += 1) {	// L1208
              v667[v668] = (int8_t)0.000000;	// L1209
              for (int v669 = 0; v669 < 8; v669 += 1) {	// L1210
                #pragma HLS pipeline II=1
                for (int v670 = 0; v670 < 8; v670 += 1) {	// L1211
                  for (int v671 = 0; v671 < 1; v671 += 1) {	// L1212
                    for (int v672 = 0; v672 < 1; v672 += 1) {	// L1213
                      int8_t v673 = v658[v659][(v670 + (v669 * 8))][v671][v672];	// L1214
                      int8_t v674 = v654[v668][(v670 + (v669 * 8))][v671][v672];	// L1215
                      int8_t v675 = v673 * v674;	// L1216
                      int8_t v676 = v667[v668];	// L1217
                      int8_t v677 = v676 + v675;	// L1218
                      v667[v668] = v677;	// L1219
                    }
                  }
                }
              }
              int8_t v678 = v667[v668];	// L1224
              v656[v659][v668][(v660 - 28)][(v661 - 28)] = v678;	// L1225
            }
          }
        }
      }
    }
  }
  return ;	// L1232
}

void main_graph_node29(
  int8_t v679[1][128][28][28],
  int8_t v680[128][128][3][3],
  int8_t v681[1][128][28][28]
) {	// L1234
  #pragma HLS dataflow

  int8_t v682[1][128][30][30];	// L1236
  #pragma HLS stream variable=v682 depth=10 type=fifo

  #pragma HLS bind_storage variable=v682 type=ram_t2p impl=bram

  for (int v683 = 0; v683 < 1; v683 += 1) {	// L1237
    for (int v684 = 0; v684 < 30; v684 += 1) {	// L1238
      for (int v685 = 0; v685 < 30; v685 += 1) {	// L1239
        for (int v686 = 0; v686 < 128; v686 += 1) {	// L1240
          int8_t v687;	// L1241
          v687 = (int8_t)0.000000;	// L1242
          if (((-v684) + 27) >= 0 && ((-v685) + 27) >= 0) {	// L1243
            int8_t v688 = v679[v683][v686][v684][v685];	// L1244
            v687 = v688;	// L1245
          }
          int8_t v689 = v687;	// L1247
          v682[v683][v686][v684][v685] = v689;	// L1248
        }
      }
    }
  }
  int8_t v690[1][128][3][30];	// L1253
  #pragma HLS array_partition variable=v690 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v690 type=ram_2p impl=bram

  int8_t v691[1][128][3][3];	// L1254
  #pragma HLS array_partition variable=v691 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v691 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v691 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v691 type=ram_2p impl=lutram

  for (int v692 = 0; v692 < 1; v692 += 1) {	// L1255
    for (int v693 = 0; v693 < 30; v693 += 1) {	// L1256
      for (int v694 = 0; v694 < 30; v694 += 1) {	// L1257
        for (int v695 = 0; v695 < 128; v695 += 1) {	// L1258
          int8_t v696 = v690[v692][v695][1][v694];	// L1259
          v690[v692][v695][0][v694] = v696;	// L1260
          int8_t v697 = v690[v692][v695][2][v694];	// L1261
          v690[v692][v695][1][v694] = v697;	// L1262
          int8_t v698 = v682[v692][v695][v693][v694];	// L1263
          v690[v692][v695][2][v694] = v698;	// L1264
        }
        if ((v693 - 2) >= 0) {	// L1266
          for (int v699 = 0; v699 < 128; v699 += 1) {	// L1267
            for (int v700 = 0; v700 < 3; v700 += 1) {	// L1268
              int8_t v701 = v691[v692][v699][v700][1];	// L1269
              v691[v692][v699][v700][0] = v701;	// L1270
              int8_t v702 = v691[v692][v699][v700][2];	// L1271
              v691[v692][v699][v700][1] = v702;	// L1272
              int8_t v703 = v690[v692][v699][v700][v694];	// L1273
              v691[v692][v699][v700][2] = v703;	// L1274
            }
          }
          if ((v694 - 2) >= 0) {	// L1277
            int8_t v704[128];	// L1278
            #pragma HLS bind_storage variable=v704 type=ram_2p impl=bram

            for (int v705 = 0; v705 < 128; v705 += 1) {	// L1279
              v704[v705] = (int8_t)0.000000;	// L1280
              for (int v706 = 0; v706 < 32; v706 += 1) {	// L1281
                #pragma HLS pipeline II=1
                for (int v707 = 0; v707 < 4; v707 += 1) {	// L1282
                  for (int v708 = 0; v708 < 3; v708 += 1) {	// L1283
                    for (int v709 = 0; v709 < 3; v709 += 1) {	// L1284
                      int8_t v710 = v691[v692][(v707 + (v706 * 4))][v708][v709];	// L1285
                      int8_t v711 = v680[v705][(v707 + (v706 * 4))][v708][v709];	// L1286
                      int8_t v712 = v710 * v711;	// L1287
                      int8_t v713 = v704[v705];	// L1288
                      int8_t v714 = v713 + v712;	// L1289
                      v704[v705] = v714;	// L1290
                    }
                  }
                }
              }
              int8_t v715 = v704[v705];	// L1295
              v681[v692][v705][(v693 - 2)][(v694 - 2)] = v715;	// L1296
            }
          }
        }
      }
    }
  }
  return ;	// L1303
}

void main_graph_node30(
  int8_t v716[128][64][3][3],
  int8_t v717[1][64][56][56],
  int8_t v718[1][128][28][28]
) {	// L1305
  #pragma HLS dataflow

  int8_t v719[1][64][58][58];	// L1307
  #pragma HLS stream variable=v719 depth=10 type=fifo

  #pragma HLS bind_storage variable=v719 type=ram_t2p impl=bram

  for (int v720 = 0; v720 < 1; v720 += 1) {	// L1308
    for (int v721 = 0; v721 < 58; v721 += 1) {	// L1309
      for (int v722 = 0; v722 < 58; v722 += 1) {	// L1310
        for (int v723 = 0; v723 < 64; v723 += 1) {	// L1311
          int8_t v724;	// L1312
          v724 = (int8_t)0.000000;	// L1313
          if (((-v721) + 55) >= 0 && ((-v722) + 55) >= 0) {	// L1314
            int8_t v725 = v717[v720][v723][v721][v722];	// L1315
            v724 = v725;	// L1316
          }
          int8_t v726 = v724;	// L1318
          v719[v720][v723][v721][v722] = v726;	// L1319
        }
      }
    }
  }
  int8_t v727[1][128][28][28];	// L1324
  #pragma HLS stream variable=v727 depth=10 type=fifo

  #pragma HLS bind_storage variable=v727 type=ram_t2p impl=bram

  int8_t v728[1][64][3][58];	// L1325
  #pragma HLS array_partition variable=v728 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v728 type=ram_2p impl=bram

  int8_t v729[1][64][3][3];	// L1326
  #pragma HLS array_partition variable=v729 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v729 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v729 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v729 type=ram_2p impl=lutram

  for (int v730 = 0; v730 < 1; v730 += 1) {	// L1327
    for (int v731 = 0; v731 < 58; v731 += 1) {	// L1328
      for (int v732 = 0; v732 < 58; v732 += 1) {	// L1329
        for (int v733 = 0; v733 < 64; v733 += 1) {	// L1330
          int8_t v734 = v728[v730][v733][1][v732];	// L1331
          v728[v730][v733][0][v732] = v734;	// L1332
          int8_t v735 = v728[v730][v733][2][v732];	// L1333
          v728[v730][v733][1][v732] = v735;	// L1334
          int8_t v736 = v719[v730][v733][v731][v732];	// L1335
          v728[v730][v733][2][v732] = v736;	// L1336
        }
        if ((v731 - 30) >= 0) {	// L1338
          for (int v737 = 0; v737 < 64; v737 += 1) {	// L1339
            for (int v738 = 0; v738 < 3; v738 += 1) {	// L1340
              int8_t v739 = v729[v730][v737][v738][1];	// L1341
              v729[v730][v737][v738][0] = v739;	// L1342
              int8_t v740 = v729[v730][v737][v738][2];	// L1343
              v729[v730][v737][v738][1] = v740;	// L1344
              int8_t v741 = v728[v730][v737][v738][v732];	// L1345
              v729[v730][v737][v738][2] = v741;	// L1346
            }
          }
          if ((v732 - 30) >= 0) {	// L1349
            int8_t v742[128];	// L1350
            #pragma HLS bind_storage variable=v742 type=ram_2p impl=bram

            for (int v743 = 0; v743 < 128; v743 += 1) {	// L1351
              v742[v743] = (int8_t)0.000000;	// L1352
              for (int v744 = 0; v744 < 8; v744 += 1) {	// L1353
                #pragma HLS pipeline II=1
                for (int v745 = 0; v745 < 8; v745 += 1) {	// L1354
                  for (int v746 = 0; v746 < 3; v746 += 1) {	// L1355
                    for (int v747 = 0; v747 < 3; v747 += 1) {	// L1356
                      int8_t v748 = v729[v730][(v745 + (v744 * 8))][v746][v747];	// L1357
                      int8_t v749 = v716[v743][(v745 + (v744 * 8))][v746][v747];	// L1358
                      int8_t v750 = v748 * v749;	// L1359
                      int8_t v751 = v742[v743];	// L1360
                      int8_t v752 = v751 + v750;	// L1361
                      v742[v743] = v752;	// L1362
                    }
                  }
                }
              }
              int8_t v753 = v742[v743];	// L1367
              v727[v730][v743][(v731 - 30)][(v732 - 30)] = v753;	// L1368
            }
          }
        }
      }
    }
  }
  for (int v754 = 0; v754 < 1; v754 += 1) {	// L1375
    for (int v755 = 0; v755 < 28; v755 += 1) {	// L1376
      for (int v756 = 0; v756 < 28; v756 += 1) {	// L1377
        for (int v757 = 0; v757 < 128; v757 += 1) {	// L1378
          int8_t v758 = v727[0][v757][v755][v756];	// L1379
          bool v759 = v758 > (int8_t)0.000000;	// L1380
          int8_t v760 = v759 ? v758 : (int8_t)0.000000;	// L1381
          v718[v754][v757][v755][v756] = v760;	// L1382
        }
      }
    }
  }
  return ;	// L1387
}

void main_graph_node31(
  int8_t v761[1][64][56][56],
  int8_t v762[1][64][56][56],
  int8_t v763[1][64][56][56]
) {	// L1389
  #pragma HLS dataflow

  for (int v764 = 0; v764 < 1; v764 += 1) {	// L1390
    for (int v765 = 0; v765 < 56; v765 += 1) {	// L1391
      for (int v766 = 0; v766 < 56; v766 += 1) {	// L1392
        for (int v767 = 0; v767 < 64; v767 += 1) {	// L1393
          int8_t v768 = v761[v764][v767][v765][v766];	// L1394
          v762[v764][v767][v765][v766] = v768;	// L1395
          int8_t v769 = v761[v764][v767][v765][v766];	// L1396
          v763[v764][v767][v765][v766] = v769;	// L1397
        }
      }
    }
  }
  return ;	// L1402
}

void main_graph_node32(
  int8_t v770[1][64][56][56],
  int8_t v771[1][64][56][56],
  int8_t v772[1][64][56][56]
) {	// L1404
  #pragma HLS dataflow

  for (int v773 = 0; v773 < 1; v773 += 1) {	// L1406
    for (int v774 = 0; v774 < 56; v774 += 1) {	// L1407
      for (int v775 = 0; v775 < 56; v775 += 1) {	// L1408
        for (int v776 = 0; v776 < 64; v776 += 1) {	// L1409
          int8_t v777 = v770[0][v776][v774][v775];	// L1410
          int8_t v778 = v771[0][v776][v774][v775];	// L1411
          int8_t v779 = v777 + v778;	// L1412
          bool v780 = v779 > (int8_t)0.000000;	// L1413
          int8_t v781 = v780 ? v779 : (int8_t)0.000000;	// L1414
          v772[v773][v776][v774][v775] = v781;	// L1415
        }
      }
    }
  }
  return ;	// L1420
}

void main_graph_node33(
  int8_t v782[64][64][3][3],
  int8_t v783[1][64][56][56],
  int8_t v784[1][64][56][56]
) {	// L1422
  #pragma HLS dataflow

  int8_t v785[1][64][58][58];	// L1424
  #pragma HLS stream variable=v785 depth=10 type=fifo

  #pragma HLS bind_storage variable=v785 type=ram_t2p impl=bram

  for (int v786 = 0; v786 < 1; v786 += 1) {	// L1425
    for (int v787 = 0; v787 < 58; v787 += 1) {	// L1426
      for (int v788 = 0; v788 < 58; v788 += 1) {	// L1427
        for (int v789 = 0; v789 < 64; v789 += 1) {	// L1428
          int8_t v790;	// L1429
          v790 = (int8_t)0.000000;	// L1430
          if (((-v787) + 55) >= 0 && ((-v788) + 55) >= 0) {	// L1431
            int8_t v791 = v783[v786][v789][v787][v788];	// L1432
            v790 = v791;	// L1433
          }
          int8_t v792 = v790;	// L1435
          v785[v786][v789][v787][v788] = v792;	// L1436
        }
      }
    }
  }
  int8_t v793[1][64][3][58];	// L1441
  #pragma HLS array_partition variable=v793 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v793 type=ram_2p impl=bram

  int8_t v794[1][64][3][3];	// L1442
  #pragma HLS array_partition variable=v794 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v794 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v794 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v794 type=ram_2p impl=lutram

  for (int v795 = 0; v795 < 1; v795 += 1) {	// L1443
    for (int v796 = 0; v796 < 58; v796 += 1) {	// L1444
      for (int v797 = 0; v797 < 58; v797 += 1) {	// L1445
        for (int v798 = 0; v798 < 64; v798 += 1) {	// L1446
          int8_t v799 = v793[v795][v798][1][v797];	// L1447
          v793[v795][v798][0][v797] = v799;	// L1448
          int8_t v800 = v793[v795][v798][2][v797];	// L1449
          v793[v795][v798][1][v797] = v800;	// L1450
          int8_t v801 = v785[v795][v798][v796][v797];	// L1451
          v793[v795][v798][2][v797] = v801;	// L1452
        }
        if ((v796 - 2) >= 0) {	// L1454
          for (int v802 = 0; v802 < 64; v802 += 1) {	// L1455
            for (int v803 = 0; v803 < 3; v803 += 1) {	// L1456
              int8_t v804 = v794[v795][v802][v803][1];	// L1457
              v794[v795][v802][v803][0] = v804;	// L1458
              int8_t v805 = v794[v795][v802][v803][2];	// L1459
              v794[v795][v802][v803][1] = v805;	// L1460
              int8_t v806 = v793[v795][v802][v803][v797];	// L1461
              v794[v795][v802][v803][2] = v806;	// L1462
            }
          }
          if ((v797 - 2) >= 0) {	// L1465
            int8_t v807[64];	// L1466
            #pragma HLS bind_storage variable=v807 type=ram_2p impl=bram

            for (int v808 = 0; v808 < 64; v808 += 1) {	// L1467
              v807[v808] = (int8_t)0.000000;	// L1468
              for (int v809 = 0; v809 < 16; v809 += 1) {	// L1469
                #pragma HLS pipeline II=1
                for (int v810 = 0; v810 < 4; v810 += 1) {	// L1470
                  for (int v811 = 0; v811 < 3; v811 += 1) {	// L1471
                    for (int v812 = 0; v812 < 3; v812 += 1) {	// L1472
                      int8_t v813 = v794[v795][(v810 + (v809 * 4))][v811][v812];	// L1473
                      int8_t v814 = v782[v808][(v810 + (v809 * 4))][v811][v812];	// L1474
                      int8_t v815 = v813 * v814;	// L1475
                      int8_t v816 = v807[v808];	// L1476
                      int8_t v817 = v816 + v815;	// L1477
                      v807[v808] = v817;	// L1478
                    }
                  }
                }
              }
              int8_t v818 = v807[v808];	// L1483
              v784[v795][v808][(v796 - 2)][(v797 - 2)] = v818;	// L1484
            }
          }
        }
      }
    }
  }
  return ;	// L1491
}

void main_graph_node34(
  int8_t v819[1][64][56][56],
  int8_t v820[64][64][3][3],
  int8_t v821[1][64][56][56]
) {	// L1493
  #pragma HLS dataflow

  int8_t v822[1][64][58][58];	// L1495
  #pragma HLS stream variable=v822 depth=10 type=fifo

  #pragma HLS bind_storage variable=v822 type=ram_t2p impl=bram

  for (int v823 = 0; v823 < 1; v823 += 1) {	// L1496
    for (int v824 = 0; v824 < 58; v824 += 1) {	// L1497
      for (int v825 = 0; v825 < 58; v825 += 1) {	// L1498
        for (int v826 = 0; v826 < 64; v826 += 1) {	// L1499
          int8_t v827;	// L1500
          v827 = (int8_t)0.000000;	// L1501
          if (((-v824) + 55) >= 0 && ((-v825) + 55) >= 0) {	// L1502
            int8_t v828 = v819[v823][v826][v824][v825];	// L1503
            v827 = v828;	// L1504
          }
          int8_t v829 = v827;	// L1506
          v822[v823][v826][v824][v825] = v829;	// L1507
        }
      }
    }
  }
  int8_t v830[1][64][56][56];	// L1512
  #pragma HLS stream variable=v830 depth=10 type=fifo

  #pragma HLS bind_storage variable=v830 type=ram_t2p impl=bram

  int8_t v831[1][64][3][58];	// L1513
  #pragma HLS array_partition variable=v831 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v831 type=ram_2p impl=bram

  int8_t v832[1][64][3][3];	// L1514
  #pragma HLS array_partition variable=v832 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v832 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v832 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v832 type=ram_2p impl=lutram

  for (int v833 = 0; v833 < 1; v833 += 1) {	// L1515
    for (int v834 = 0; v834 < 58; v834 += 1) {	// L1516
      for (int v835 = 0; v835 < 58; v835 += 1) {	// L1517
        for (int v836 = 0; v836 < 64; v836 += 1) {	// L1518
          int8_t v837 = v831[v833][v836][1][v835];	// L1519
          v831[v833][v836][0][v835] = v837;	// L1520
          int8_t v838 = v831[v833][v836][2][v835];	// L1521
          v831[v833][v836][1][v835] = v838;	// L1522
          int8_t v839 = v822[v833][v836][v834][v835];	// L1523
          v831[v833][v836][2][v835] = v839;	// L1524
        }
        if ((v834 - 2) >= 0) {	// L1526
          for (int v840 = 0; v840 < 64; v840 += 1) {	// L1527
            for (int v841 = 0; v841 < 3; v841 += 1) {	// L1528
              int8_t v842 = v832[v833][v840][v841][1];	// L1529
              v832[v833][v840][v841][0] = v842;	// L1530
              int8_t v843 = v832[v833][v840][v841][2];	// L1531
              v832[v833][v840][v841][1] = v843;	// L1532
              int8_t v844 = v831[v833][v840][v841][v835];	// L1533
              v832[v833][v840][v841][2] = v844;	// L1534
            }
          }
          if ((v835 - 2) >= 0) {	// L1537
            int8_t v845[64];	// L1538
            #pragma HLS bind_storage variable=v845 type=ram_2p impl=bram

            for (int v846 = 0; v846 < 64; v846 += 1) {	// L1539
              v845[v846] = (int8_t)0.000000;	// L1540
              for (int v847 = 0; v847 < 16; v847 += 1) {	// L1541
                #pragma HLS pipeline II=1
                for (int v848 = 0; v848 < 4; v848 += 1) {	// L1542
                  for (int v849 = 0; v849 < 3; v849 += 1) {	// L1543
                    for (int v850 = 0; v850 < 3; v850 += 1) {	// L1544
                      int8_t v851 = v832[v833][(v848 + (v847 * 4))][v849][v850];	// L1545
                      int8_t v852 = v820[v846][(v848 + (v847 * 4))][v849][v850];	// L1546
                      int8_t v853 = v851 * v852;	// L1547
                      int8_t v854 = v845[v846];	// L1548
                      int8_t v855 = v854 + v853;	// L1549
                      v845[v846] = v855;	// L1550
                    }
                  }
                }
              }
              int8_t v856 = v845[v846];	// L1555
              v830[v833][v846][(v834 - 2)][(v835 - 2)] = v856;	// L1556
            }
          }
        }
      }
    }
  }
  for (int v857 = 0; v857 < 1; v857 += 1) {	// L1563
    for (int v858 = 0; v858 < 56; v858 += 1) {	// L1564
      for (int v859 = 0; v859 < 56; v859 += 1) {	// L1565
        for (int v860 = 0; v860 < 64; v860 += 1) {	// L1566
          int8_t v861 = v830[0][v860][v858][v859];	// L1567
          bool v862 = v861 > (int8_t)0.000000;	// L1568
          int8_t v863 = v862 ? v861 : (int8_t)0.000000;	// L1569
          v821[v857][v860][v858][v859] = v863;	// L1570
        }
      }
    }
  }
  return ;	// L1575
}

void main_graph_node35(
  int8_t v864[1][64][56][56],
  int8_t v865[1][64][56][56],
  int8_t v866[1][64][56][56]
) {	// L1577
  #pragma HLS dataflow

  for (int v867 = 0; v867 < 1; v867 += 1) {	// L1578
    for (int v868 = 0; v868 < 56; v868 += 1) {	// L1579
      for (int v869 = 0; v869 < 56; v869 += 1) {	// L1580
        for (int v870 = 0; v870 < 64; v870 += 1) {	// L1581
          int8_t v871 = v864[v867][v870][v868][v869];	// L1582
          v865[v867][v870][v868][v869] = v871;	// L1583
          int8_t v872 = v864[v867][v870][v868][v869];	// L1584
          v866[v867][v870][v868][v869] = v872;	// L1585
        }
      }
    }
  }
  return ;	// L1590
}

void main_graph_node36(
  int8_t v873[1][64][56][56],
  int8_t v874[1][64][56][56],
  int8_t v875[1][64][56][56]
) {	// L1592
  #pragma HLS dataflow

  for (int v876 = 0; v876 < 1; v876 += 1) {	// L1594
    for (int v877 = 0; v877 < 56; v877 += 1) {	// L1595
      for (int v878 = 0; v878 < 56; v878 += 1) {	// L1596
        for (int v879 = 0; v879 < 64; v879 += 1) {	// L1597
          int8_t v880 = v873[0][v879][v877][v878];	// L1598
          int8_t v881 = v874[0][v879][v877][v878];	// L1599
          int8_t v882 = v880 + v881;	// L1600
          bool v883 = v882 > (int8_t)0.000000;	// L1601
          int8_t v884 = v883 ? v882 : (int8_t)0.000000;	// L1602
          v875[v876][v879][v877][v878] = v884;	// L1603
        }
      }
    }
  }
  return ;	// L1608
}

void main_graph_node37(
  int8_t v885[1][64][56][56],
  int8_t v886[64][64][3][3],
  int8_t v887[1][64][56][56]
) {	// L1610
  #pragma HLS dataflow

  int8_t v888[1][64][58][58];	// L1612
  #pragma HLS stream variable=v888 depth=10 type=fifo

  #pragma HLS bind_storage variable=v888 type=ram_t2p impl=bram

  for (int v889 = 0; v889 < 1; v889 += 1) {	// L1613
    for (int v890 = 0; v890 < 58; v890 += 1) {	// L1614
      for (int v891 = 0; v891 < 58; v891 += 1) {	// L1615
        for (int v892 = 0; v892 < 64; v892 += 1) {	// L1616
          int8_t v893;	// L1617
          v893 = (int8_t)0.000000;	// L1618
          if (((-v890) + 55) >= 0 && ((-v891) + 55) >= 0) {	// L1619
            int8_t v894 = v885[v889][v892][v890][v891];	// L1620
            v893 = v894;	// L1621
          }
          int8_t v895 = v893;	// L1623
          v888[v889][v892][v890][v891] = v895;	// L1624
        }
      }
    }
  }
  int8_t v896[1][64][3][58];	// L1629
  #pragma HLS array_partition variable=v896 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v896 type=ram_2p impl=bram

  int8_t v897[1][64][3][3];	// L1630
  #pragma HLS array_partition variable=v897 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v897 type=ram_2p impl=lutram

  for (int v898 = 0; v898 < 1; v898 += 1) {	// L1631
    for (int v899 = 0; v899 < 58; v899 += 1) {	// L1632
      for (int v900 = 0; v900 < 58; v900 += 1) {	// L1633
        for (int v901 = 0; v901 < 64; v901 += 1) {	// L1634
          int8_t v902 = v896[v898][v901][1][v900];	// L1635
          v896[v898][v901][0][v900] = v902;	// L1636
          int8_t v903 = v896[v898][v901][2][v900];	// L1637
          v896[v898][v901][1][v900] = v903;	// L1638
          int8_t v904 = v888[v898][v901][v899][v900];	// L1639
          v896[v898][v901][2][v900] = v904;	// L1640
        }
        if ((v899 - 2) >= 0) {	// L1642
          for (int v905 = 0; v905 < 64; v905 += 1) {	// L1643
            for (int v906 = 0; v906 < 3; v906 += 1) {	// L1644
              int8_t v907 = v897[v898][v905][v906][1];	// L1645
              v897[v898][v905][v906][0] = v907;	// L1646
              int8_t v908 = v897[v898][v905][v906][2];	// L1647
              v897[v898][v905][v906][1] = v908;	// L1648
              int8_t v909 = v896[v898][v905][v906][v900];	// L1649
              v897[v898][v905][v906][2] = v909;	// L1650
            }
          }
          if ((v900 - 2) >= 0) {	// L1653
            int8_t v910[64];	// L1654
            #pragma HLS bind_storage variable=v910 type=ram_2p impl=bram

            for (int v911 = 0; v911 < 64; v911 += 1) {	// L1655
              v910[v911] = (int8_t)0.000000;	// L1656
              for (int v912 = 0; v912 < 16; v912 += 1) {	// L1657
                #pragma HLS pipeline II=1
                for (int v913 = 0; v913 < 4; v913 += 1) {	// L1658
                  for (int v914 = 0; v914 < 3; v914 += 1) {	// L1659
                    for (int v915 = 0; v915 < 3; v915 += 1) {	// L1660
                      int8_t v916 = v897[v898][(v913 + (v912 * 4))][v914][v915];	// L1661
                      int8_t v917 = v886[v911][(v913 + (v912 * 4))][v914][v915];	// L1662
                      int8_t v918 = v916 * v917;	// L1663
                      int8_t v919 = v910[v911];	// L1664
                      int8_t v920 = v919 + v918;	// L1665
                      v910[v911] = v920;	// L1666
                    }
                  }
                }
              }
              int8_t v921 = v910[v911];	// L1671
              v887[v898][v911][(v899 - 2)][(v900 - 2)] = v921;	// L1672
            }
          }
        }
      }
    }
  }
  return ;	// L1679
}

void main_graph_node38(
  int8_t v922[64][64][3][3],
  int8_t v923[1][64][56][56],
  int8_t v924[1][64][56][56]
) {	// L1681
  #pragma HLS dataflow

  int8_t v925[1][64][58][58];	// L1683
  #pragma HLS stream variable=v925 depth=10 type=fifo

  #pragma HLS bind_storage variable=v925 type=ram_t2p impl=bram

  for (int v926 = 0; v926 < 1; v926 += 1) {	// L1684
    for (int v927 = 0; v927 < 58; v927 += 1) {	// L1685
      for (int v928 = 0; v928 < 58; v928 += 1) {	// L1686
        for (int v929 = 0; v929 < 64; v929 += 1) {	// L1687
          int8_t v930;	// L1688
          v930 = (int8_t)0.000000;	// L1689
          if (((-v927) + 55) >= 0 && ((-v928) + 55) >= 0) {	// L1690
            int8_t v931 = v923[v926][v929][v927][v928];	// L1691
            v930 = v931;	// L1692
          }
          int8_t v932 = v930;	// L1694
          v925[v926][v929][v927][v928] = v932;	// L1695
        }
      }
    }
  }
  int8_t v933[1][64][56][56];	// L1700
  #pragma HLS stream variable=v933 depth=10 type=fifo

  #pragma HLS bind_storage variable=v933 type=ram_t2p impl=bram

  int8_t v934[1][64][3][58];	// L1701
  #pragma HLS array_partition variable=v934 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v934 type=ram_2p impl=bram

  int8_t v935[1][64][3][3];	// L1702
  #pragma HLS array_partition variable=v935 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v935 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v935 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v935 type=ram_2p impl=lutram

  for (int v936 = 0; v936 < 1; v936 += 1) {	// L1703
    for (int v937 = 0; v937 < 58; v937 += 1) {	// L1704
      for (int v938 = 0; v938 < 58; v938 += 1) {	// L1705
        for (int v939 = 0; v939 < 64; v939 += 1) {	// L1706
          int8_t v940 = v934[v936][v939][1][v938];	// L1707
          v934[v936][v939][0][v938] = v940;	// L1708
          int8_t v941 = v934[v936][v939][2][v938];	// L1709
          v934[v936][v939][1][v938] = v941;	// L1710
          int8_t v942 = v925[v936][v939][v937][v938];	// L1711
          v934[v936][v939][2][v938] = v942;	// L1712
        }
        if ((v937 - 2) >= 0) {	// L1714
          for (int v943 = 0; v943 < 64; v943 += 1) {	// L1715
            for (int v944 = 0; v944 < 3; v944 += 1) {	// L1716
              int8_t v945 = v935[v936][v943][v944][1];	// L1717
              v935[v936][v943][v944][0] = v945;	// L1718
              int8_t v946 = v935[v936][v943][v944][2];	// L1719
              v935[v936][v943][v944][1] = v946;	// L1720
              int8_t v947 = v934[v936][v943][v944][v938];	// L1721
              v935[v936][v943][v944][2] = v947;	// L1722
            }
          }
          if ((v938 - 2) >= 0) {	// L1725
            int8_t v948[64];	// L1726
            #pragma HLS bind_storage variable=v948 type=ram_2p impl=bram

            for (int v949 = 0; v949 < 64; v949 += 1) {	// L1727
              v948[v949] = (int8_t)0.000000;	// L1728
              for (int v950 = 0; v950 < 16; v950 += 1) {	// L1729
                #pragma HLS pipeline II=1
                for (int v951 = 0; v951 < 4; v951 += 1) {	// L1730
                  for (int v952 = 0; v952 < 3; v952 += 1) {	// L1731
                    for (int v953 = 0; v953 < 3; v953 += 1) {	// L1732
                      int8_t v954 = v935[v936][(v951 + (v950 * 4))][v952][v953];	// L1733
                      int8_t v955 = v922[v949][(v951 + (v950 * 4))][v952][v953];	// L1734
                      int8_t v956 = v954 * v955;	// L1735
                      int8_t v957 = v948[v949];	// L1736
                      int8_t v958 = v957 + v956;	// L1737
                      v948[v949] = v958;	// L1738
                    }
                  }
                }
              }
              int8_t v959 = v948[v949];	// L1743
              v933[v936][v949][(v937 - 2)][(v938 - 2)] = v959;	// L1744
            }
          }
        }
      }
    }
  }
  for (int v960 = 0; v960 < 1; v960 += 1) {	// L1751
    for (int v961 = 0; v961 < 56; v961 += 1) {	// L1752
      for (int v962 = 0; v962 < 56; v962 += 1) {	// L1753
        for (int v963 = 0; v963 < 64; v963 += 1) {	// L1754
          int8_t v964 = v933[0][v963][v961][v962];	// L1755
          bool v965 = v964 > (int8_t)0.000000;	// L1756
          int8_t v966 = v965 ? v964 : (int8_t)0.000000;	// L1757
          v924[v960][v963][v961][v962] = v966;	// L1758
        }
      }
    }
  }
  return ;	// L1763
}

void main_graph_node39(
  int8_t v967[1][64][56][56],
  int8_t v968[1][64][56][56],
  int8_t v969[1][64][56][56]
) {	// L1765
  #pragma HLS dataflow

  for (int v970 = 0; v970 < 1; v970 += 1) {	// L1766
    for (int v971 = 0; v971 < 56; v971 += 1) {	// L1767
      for (int v972 = 0; v972 < 56; v972 += 1) {	// L1768
        for (int v973 = 0; v973 < 64; v973 += 1) {	// L1769
          int8_t v974 = v967[v970][v973][v971][v972];	// L1770
          v968[v970][v973][v971][v972] = v974;	// L1771
          int8_t v975 = v967[v970][v973][v971][v972];	// L1772
          v969[v970][v973][v971][v972] = v975;	// L1773
        }
      }
    }
  }
  return ;	// L1778
}

void main_graph_node40(
  int8_t v976[1][64][112][112],
  int8_t v977[1][64][56][56]
) {	// L1780
  #pragma HLS dataflow

  int8_t v978;	// L1783
  v978 = (int8_t)-INFINITY;	// L1784
  int8_t v979[1][64][114][114];	// L1785
  #pragma HLS bind_storage variable=v979 type=ram_t2p impl=bram

  for (int v980 = 0; v980 < 1; v980 += 1) {	// L1786
    for (int v981 = 0; v981 < 64; v981 += 1) {	// L1787
      for (int v982 = 0; v982 < 114; v982 += 1) {	// L1788
        for (int v983 = 0; v983 < 114; v983 += 1) {	// L1789
          int8_t v984;	// L1790
          v984 = (int8_t)-INFINITY;	// L1791
          if (((-v982) + 111) >= 0 && ((-v983) + 111) >= 0) {	// L1792
            int8_t v985 = v976[v980][v981][v982][v983];	// L1793
            v984 = v985;	// L1794
          }
          int8_t v986 = v984;	// L1796
          v979[v980][v981][v982][v983] = v986;	// L1797
        }
      }
    }
  }
  for (int v987 = 0; v987 < 1; v987 += 1) {	// L1802
    for (int v988 = 0; v988 < 56; v988 += 1) {	// L1803
      for (int v989 = 0; v989 < 56; v989 += 1) {	// L1804
        for (int v990 = 0; v990 < 64; v990 += 1) {	// L1805
          int8_t v991;	// L1806
          v991 = (int8_t)0.000000;	// L1807
          for (int v992 = 0; v992 < 3; v992 += 1) {	// L1808
            for (int v993 = 0; v993 < 3; v993 += 1) {	// L1809
              int8_t v994 = v979[v987][v990][((v988 * 2) + v992)][((v989 * 2) + v993)];	// L1810
              int8_t v995 = v978;	// L1811
              int8_t v996 = max(v995, v994);	// L1812
              v991 = v996;	// L1813
            }
          }
          int8_t v997 = v991;	// L1816
          v977[v987][v990][v988][v989] = v997;	// L1817
        }
      }
    }
  }
  return ;	// L1822
}

void main_graph_node41(
  int8_t v998[1][64][224][224],
  int8_t v999[1][64][112][112]
) {	// L1824
  #pragma HLS dataflow

  int8_t v1000;	// L1827
  v1000 = (int8_t)-INFINITY;	// L1828
  int8_t v1001[1][64][112][112];	// L1829
  #pragma HLS bind_storage variable=v1001 type=ram_t2p impl=bram

  for (int v1002 = 0; v1002 < 1; v1002 += 1) {	// L1830
    for (int v1003 = 0; v1003 < 112; v1003 += 1) {	// L1831
      for (int v1004 = 0; v1004 < 2; v1004 += 1) {	// L1832
        for (int v1005 = 0; v1005 < 112; v1005 += 1) {	// L1833
          for (int v1006 = 0; v1006 < 2; v1006 += 1) {	// L1834
            for (int v1007 = 0; v1007 < 64; v1007 += 1) {	// L1835
              #pragma HLS pipeline II=1
              for (int v1008 = 0; v1008 < 1; v1008 += 1) {	// L1836
                int8_t v1009 = v998[v1002][(v1007 + v1008)][((v1003 * 2) + v1004)][((v1005 * 2) + v1006)];	// L1837
                int8_t v1010 = v1000;	// L1838
                int8_t v1011 = max(v1010, v1009);	// L1839
                v1001[v1002][(v1007 + v1008)][v1003][v1005] = v1011;	// L1840
              }
            }
          }
        }
      }
    }
  }
  for (int v1012 = 0; v1012 < 1; v1012 += 1) {	// L1848
    for (int v1013 = 0; v1013 < 64; v1013 += 1) {	// L1849
      for (int v1014 = 0; v1014 < 112; v1014 += 1) {	// L1850
        for (int v1015 = 0; v1015 < 112; v1015 += 1) {	// L1851
          int8_t v1016 = v1001[0][v1013][v1014][v1015];	// L1852
          bool v1017 = v1016 > (int8_t)0.000000;	// L1853
          int8_t v1018 = v1017 ? v1016 : (int8_t)0.000000;	// L1854
          v999[v1012][v1013][v1014][v1015] = v1018;	// L1855
        }
      }
    }
  }
  return ;	// L1860
}

void main_graph_node42(
  int8_t v1019[1][3][224][224],
  int8_t v1020[64][3][7][7],
  int8_t v1021[1][64][224][224]
) {	// L1862
  #pragma HLS dataflow

  int8_t v1022[1][3][230][230];	// L1864
  #pragma HLS stream variable=v1022 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1022 type=ram_t2p impl=bram

  for (int v1023 = 0; v1023 < 1; v1023 += 1) {	// L1865
    for (int v1024 = 0; v1024 < 230; v1024 += 1) {	// L1866
      for (int v1025 = 0; v1025 < 230; v1025 += 1) {	// L1867
        for (int v1026 = 0; v1026 < 3; v1026 += 1) {	// L1868
          int8_t v1027;	// L1869
          v1027 = (int8_t)0.000000;	// L1870
          if (((-v1024) + 223) >= 0 && ((-v1025) + 223) >= 0) {	// L1871
            int8_t v1028 = v1019[v1023][v1026][v1024][v1025];	// L1872
            v1027 = v1028;	// L1873
          }
          int8_t v1029 = v1027;	// L1875
          v1022[v1023][v1026][v1024][v1025] = v1029;	// L1876
        }
      }
    }
  }
  int8_t v1030[1][3][7][230];	// L1881
  #pragma HLS array_partition variable=v1030 cyclic factor=7 dim=3
  #pragma HLS bind_storage variable=v1030 type=ram_2p impl=lutram

  int8_t v1031[1][3][7][7];	// L1882
  #pragma HLS array_partition variable=v1031 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1031 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v1031 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v1031 type=ram_2p impl=lutram

  for (int v1032 = 0; v1032 < 1; v1032 += 1) {	// L1883
    for (int v1033 = 0; v1033 < 230; v1033 += 1) {	// L1884
      for (int v1034 = 0; v1034 < 230; v1034 += 1) {	// L1885
        for (int v1035 = 0; v1035 < 3; v1035 += 1) {	// L1886
          int8_t v1036 = v1030[v1032][v1035][1][v1034];	// L1887
          v1030[v1032][v1035][0][v1034] = v1036;	// L1888
          int8_t v1037 = v1030[v1032][v1035][2][v1034];	// L1889
          v1030[v1032][v1035][1][v1034] = v1037;	// L1890
          int8_t v1038 = v1030[v1032][v1035][3][v1034];	// L1891
          v1030[v1032][v1035][2][v1034] = v1038;	// L1892
          int8_t v1039 = v1030[v1032][v1035][4][v1034];	// L1893
          v1030[v1032][v1035][3][v1034] = v1039;	// L1894
          int8_t v1040 = v1030[v1032][v1035][5][v1034];	// L1895
          v1030[v1032][v1035][4][v1034] = v1040;	// L1896
          int8_t v1041 = v1030[v1032][v1035][6][v1034];	// L1897
          v1030[v1032][v1035][5][v1034] = v1041;	// L1898
          int8_t v1042 = v1022[v1032][v1035][v1033][v1034];	// L1899
          v1030[v1032][v1035][6][v1034] = v1042;	// L1900
        }
        if ((v1033 - 6) >= 0) {	// L1902
          for (int v1043 = 0; v1043 < 3; v1043 += 1) {	// L1903
            for (int v1044 = 0; v1044 < 7; v1044 += 1) {	// L1904
              int8_t v1045 = v1031[v1032][v1043][v1044][1];	// L1905
              v1031[v1032][v1043][v1044][0] = v1045;	// L1906
              int8_t v1046 = v1031[v1032][v1043][v1044][2];	// L1907
              v1031[v1032][v1043][v1044][1] = v1046;	// L1908
              int8_t v1047 = v1031[v1032][v1043][v1044][3];	// L1909
              v1031[v1032][v1043][v1044][2] = v1047;	// L1910
              int8_t v1048 = v1031[v1032][v1043][v1044][4];	// L1911
              v1031[v1032][v1043][v1044][3] = v1048;	// L1912
              int8_t v1049 = v1031[v1032][v1043][v1044][5];	// L1913
              v1031[v1032][v1043][v1044][4] = v1049;	// L1914
              int8_t v1050 = v1031[v1032][v1043][v1044][6];	// L1915
              v1031[v1032][v1043][v1044][5] = v1050;	// L1916
              int8_t v1051 = v1030[v1032][v1043][v1044][v1034];	// L1917
              v1031[v1032][v1043][v1044][6] = v1051;	// L1918
            }
          }
          if ((v1034 - 6) >= 0) {	// L1921
            int8_t v1052[64];	// L1922
            #pragma HLS bind_storage variable=v1052 type=ram_2p impl=bram

            for (int v1053 = 0; v1053 < 64; v1053 += 1) {	// L1923
              #pragma HLS pipeline II=1
              for (int v1054 = 0; v1054 < 1; v1054 += 1) {	// L1924
                v1052[(v1053 + v1054)] = (int8_t)0.000000;	// L1925
                for (int v1055 = 0; v1055 < 3; v1055 += 1) {	// L1926
                  for (int v1056 = 0; v1056 < 7; v1056 += 1) {	// L1927
                    for (int v1057 = 0; v1057 < 7; v1057 += 1) {	// L1928
                      int8_t v1058 = v1031[v1032][v1055][v1056][v1057];	// L1929
                      int8_t v1059 = v1020[(v1053 + v1054)][v1055][v1056][v1057];	// L1930
                      int8_t v1060 = v1058 * v1059;	// L1931
                      int8_t v1061 = v1052[(v1053 + v1054)];	// L1932
                      int8_t v1062 = v1061 + v1060;	// L1933
                      v1052[(v1053 + v1054)] = v1062;	// L1934
                    }
                  }
                }
                int8_t v1063 = v1052[(v1053 + v1054)];	// L1938
                v1021[v1032][(v1053 + v1054)][(v1033 - 6)][(v1034 - 6)] = v1063;	// L1939
              }
            }
          }
        }
      }
    }
  }
  return ;	// L1947
}

/// This is top function.
void main_graph(
  int8_t v1064[1][3][224][224],
  int8_t v1065[1000],
  int8_t v1066[512][512][3][3],
  int8_t v1067[512][512][3][3],
  int8_t v1068[512][256][1][1],
  int8_t v1069[512][512][3][3],
  int8_t v1070[512][256][3][3],
  int8_t v1071[256][256][3][3],
  int8_t v1072[256][256][3][3],
  int8_t v1073[256][128][1][1],
  int8_t v1074[256][256][3][3],
  int8_t v1075[256][128][3][3],
  int8_t v1076[128][128][3][3],
  int8_t v1077[128][128][3][3],
  int8_t v1078[128][64][1][1],
  int8_t v1079[128][128][3][3],
  int8_t v1080[128][64][3][3],
  int8_t v1081[64][64][3][3],
  int8_t v1082[64][64][3][3],
  int8_t v1083[64][64][3][3],
  int8_t v1084[64][64][3][3],
  int8_t v1085[64][3][7][7],
  int8_t v1086[512][1000],
  int8_t v1087[1][1000]
) {	// L1949
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v1064 bundle=gmem1
  #pragma HLS bind_storage variable=v1064 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1065 bundle=gmem2
  #pragma HLS bind_storage variable=v1065 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1066 bundle=gmem3
  #pragma HLS array_partition variable=v1066 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1066 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1066 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1066 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1067 bundle=gmem4
  #pragma HLS array_partition variable=v1067 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1067 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1067 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1067 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1068 bundle=gmem5
  #pragma HLS array_partition variable=v1068 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1068 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1069 bundle=gmem6
  #pragma HLS array_partition variable=v1069 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1069 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1069 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1069 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1070 bundle=gmem7
  #pragma HLS array_partition variable=v1070 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1070 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1070 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1070 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1071 bundle=gmem8
  #pragma HLS array_partition variable=v1071 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1071 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1071 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1071 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1072 bundle=gmem9
  #pragma HLS array_partition variable=v1072 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1072 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1072 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1072 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1073 bundle=gmem10
  #pragma HLS array_partition variable=v1073 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1073 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1074 bundle=gmem11
  #pragma HLS array_partition variable=v1074 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1074 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1074 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1074 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1075 bundle=gmem12
  #pragma HLS array_partition variable=v1075 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1075 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1075 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1075 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1076 bundle=gmem13
  #pragma HLS array_partition variable=v1076 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1076 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1076 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1076 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1077 bundle=gmem14
  #pragma HLS array_partition variable=v1077 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1077 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1077 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1077 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1078 bundle=gmem15
  #pragma HLS array_partition variable=v1078 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1078 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1079 bundle=gmem16
  #pragma HLS array_partition variable=v1079 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1079 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1079 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1079 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1080 bundle=gmem17
  #pragma HLS array_partition variable=v1080 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1080 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1080 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1080 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1081 bundle=gmem18
  #pragma HLS array_partition variable=v1081 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1081 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1081 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1081 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1082 bundle=gmem19
  #pragma HLS array_partition variable=v1082 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1082 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1082 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1082 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1083 bundle=gmem20
  #pragma HLS array_partition variable=v1083 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1083 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1083 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1083 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1084 bundle=gmem21
  #pragma HLS array_partition variable=v1084 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1084 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1084 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1084 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1085 bundle=gmem22
  #pragma HLS array_partition variable=v1085 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1085 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v1085 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v1085 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1086 bundle=gmem23
  #pragma HLS bind_storage variable=v1086 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1087 bundle=gmem24
  #pragma HLS bind_storage variable=v1087 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v1088[1][64][224][224];	// L1951
  #pragma HLS stream variable=v1088 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1088 type=ram_t2p impl=bram

  main_graph_node42(v1064, v1085, v1088);	// L1952
  int8_t v1089[1][64][112][112];	// L1953
  #pragma HLS stream variable=v1089 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1089 type=ram_t2p impl=bram

  main_graph_node41(v1088, v1089);	// L1954
  int8_t v1090[1][64][56][56];	// L1955
  #pragma HLS stream variable=v1090 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1090 type=ram_t2p impl=bram

  main_graph_node40(v1089, v1090);	// L1956
  int8_t v1091[1][64][56][56];	// L1957
  #pragma HLS bind_storage variable=v1091 type=ram_t2p impl=bram

  int8_t v1092[1][64][56][56];	// L1958
  #pragma HLS stream variable=v1092 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1092 type=ram_t2p impl=bram

  main_graph_node39(v1090, v1091, v1092);	// L1959
  int8_t v1093[1][64][56][56];	// L1960
  #pragma HLS stream variable=v1093 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1093 type=ram_t2p impl=bram

  main_graph_node38(v1084, v1092, v1093);	// L1961
  int8_t v1094[1][64][56][56];	// L1962
  #pragma HLS stream variable=v1094 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1094 type=ram_t2p impl=bram

  main_graph_node37(v1093, v1083, v1094);	// L1963
  int8_t v1095[1][64][56][56];	// L1964
  #pragma HLS bind_storage variable=v1095 type=ram_t2p impl=bram

  main_graph_node36(v1094, v1091, v1095);	// L1965
  int8_t v1096[1][64][56][56];	// L1966
  #pragma HLS bind_storage variable=v1096 type=ram_t2p impl=bram

  int8_t v1097[1][64][56][56];	// L1967
  #pragma HLS stream variable=v1097 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1097 type=ram_t2p impl=bram

  main_graph_node35(v1095, v1096, v1097);	// L1968
  int8_t v1098[1][64][56][56];	// L1969
  #pragma HLS stream variable=v1098 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1098 type=ram_t2p impl=bram

  main_graph_node34(v1097, v1082, v1098);	// L1970
  int8_t v1099[1][64][56][56];	// L1971
  #pragma HLS stream variable=v1099 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1099 type=ram_t2p impl=bram

  main_graph_node33(v1081, v1098, v1099);	// L1972
  int8_t v1100[1][64][56][56];	// L1973
  #pragma HLS bind_storage variable=v1100 type=ram_t2p impl=bram

  main_graph_node32(v1099, v1096, v1100);	// L1974
  int8_t v1101[1][64][56][56];	// L1975
  #pragma HLS stream variable=v1101 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1101 type=ram_t2p impl=bram

  int8_t v1102[1][64][56][56];	// L1976
  #pragma HLS stream variable=v1102 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1102 type=ram_t2p impl=bram

  main_graph_node31(v1100, v1101, v1102);	// L1977
  int8_t v1103[1][128][28][28];	// L1978
  #pragma HLS stream variable=v1103 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1103 type=ram_t2p impl=bram

  main_graph_node30(v1080, v1102, v1103);	// L1979
  int8_t v1104[1][128][28][28];	// L1980
  #pragma HLS stream variable=v1104 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1104 type=ram_t2p impl=bram

  main_graph_node29(v1103, v1079, v1104);	// L1981
  int8_t v1105[1][128][28][28];	// L1982
  #pragma HLS stream variable=v1105 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1105 type=ram_t2p impl=bram

  main_graph_node28(v1078, v1101, v1105);	// L1983
  int8_t v1106[1][128][28][28];	// L1984
  #pragma HLS bind_storage variable=v1106 type=ram_t2p impl=bram

  main_graph_node27(v1104, v1105, v1106);	// L1985
  int8_t v1107[1][128][28][28];	// L1986
  #pragma HLS bind_storage variable=v1107 type=ram_t2p impl=bram

  int8_t v1108[1][128][28][28];	// L1987
  #pragma HLS stream variable=v1108 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1108 type=ram_t2p impl=bram

  main_graph_node26(v1106, v1107, v1108);	// L1988
  int8_t v1109[1][128][28][28];	// L1989
  #pragma HLS stream variable=v1109 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1109 type=ram_t2p impl=bram

  main_graph_node25(v1077, v1108, v1109);	// L1990
  int8_t v1110[1][128][28][28];	// L1991
  #pragma HLS stream variable=v1110 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1110 type=ram_t2p impl=bram

  main_graph_node24(v1076, v1109, v1110);	// L1992
  int8_t v1111[1][128][28][28];	// L1993
  #pragma HLS bind_storage variable=v1111 type=ram_t2p impl=bram

  main_graph_node23(v1110, v1107, v1111);	// L1994
  int8_t v1112[1][128][28][28];	// L1995
  #pragma HLS stream variable=v1112 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1112 type=ram_t2p impl=bram

  int8_t v1113[1][128][28][28];	// L1996
  #pragma HLS stream variable=v1113 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1113 type=ram_t2p impl=bram

  main_graph_node22(v1111, v1112, v1113);	// L1997
  int8_t v1114[1][256][14][14];	// L1998
  #pragma HLS stream variable=v1114 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1114 type=ram_t2p impl=bram

  main_graph_node21(v1113, v1075, v1114);	// L1999
  int8_t v1115[1][256][14][14];	// L2000
  #pragma HLS stream variable=v1115 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1115 type=ram_t2p impl=bram

  main_graph_node20(v1074, v1114, v1115);	// L2001
  int8_t v1116[1][256][14][14];	// L2002
  #pragma HLS stream variable=v1116 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1116 type=ram_t2p impl=bram

  main_graph_node19(v1073, v1112, v1116);	// L2003
  int8_t v1117[1][256][14][14];	// L2004
  #pragma HLS bind_storage variable=v1117 type=ram_t2p impl=bram

  main_graph_node18(v1115, v1116, v1117);	// L2005
  int8_t v1118[1][256][14][14];	// L2006
  #pragma HLS bind_storage variable=v1118 type=ram_t2p impl=bram

  int8_t v1119[1][256][14][14];	// L2007
  #pragma HLS stream variable=v1119 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1119 type=ram_t2p impl=bram

  main_graph_node17(v1117, v1118, v1119);	// L2008
  int8_t v1120[1][256][14][14];	// L2009
  #pragma HLS stream variable=v1120 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1120 type=ram_t2p impl=bram

  main_graph_node16(v1072, v1119, v1120);	// L2010
  int8_t v1121[1][256][14][14];	// L2011
  #pragma HLS stream variable=v1121 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1121 type=ram_t2p impl=bram

  main_graph_node15(v1071, v1120, v1121);	// L2012
  int8_t v1122[1][256][14][14];	// L2013
  #pragma HLS bind_storage variable=v1122 type=ram_t2p impl=bram

  main_graph_node14(v1121, v1118, v1122);	// L2014
  int8_t v1123[1][256][14][14];	// L2015
  #pragma HLS stream variable=v1123 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1123 type=ram_t2p impl=bram

  int8_t v1124[1][256][14][14];	// L2016
  #pragma HLS stream variable=v1124 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1124 type=ram_t2p impl=bram

  main_graph_node13(v1122, v1123, v1124);	// L2017
  int8_t v1125[1][512][7][7];	// L2018
  #pragma HLS stream variable=v1125 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1125 type=ram_t2p impl=bram

  main_graph_node12(v1070, v1124, v1125);	// L2019
  int8_t v1126[1][512][7][7];	// L2020
  #pragma HLS stream variable=v1126 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1126 type=ram_t2p impl=bram

  main_graph_node11(v1125, v1069, v1126);	// L2021
  int8_t v1127[1][512][7][7];	// L2022
  #pragma HLS stream variable=v1127 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1127 type=ram_t2p impl=bram

  main_graph_node10(v1068, v1123, v1127);	// L2023
  int8_t v1128[1][512][7][7];	// L2024
  #pragma HLS bind_storage variable=v1128 type=ram_t2p impl=bram

  main_graph_node9(v1126, v1127, v1128);	// L2025
  int8_t v1129[1][512][7][7];	// L2026
  #pragma HLS bind_storage variable=v1129 type=ram_t2p impl=bram

  int8_t v1130[1][512][7][7];	// L2027
  #pragma HLS stream variable=v1130 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1130 type=ram_t2p impl=bram

  main_graph_node8(v1128, v1129, v1130);	// L2028
  int8_t v1131[1][512][7][7];	// L2029
  #pragma HLS stream variable=v1131 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1131 type=ram_t2p impl=bram

  main_graph_node7(v1067, v1130, v1131);	// L2030
  int8_t v1132[1][512][7][7];	// L2031
  #pragma HLS stream variable=v1132 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1132 type=ram_t2p impl=bram

  main_graph_node6(v1066, v1131, v1132);	// L2032
  int8_t v1133[1][512][7][7];	// L2033
  #pragma HLS bind_storage variable=v1133 type=ram_t2p impl=bram

  main_graph_node5(v1132, v1129, v1133);	// L2034
  int8_t v1134[1][512][8][8];	// L2035
  #pragma HLS bind_storage variable=v1134 type=ram_t2p impl=bram

  main_graph_node4(v1133, v1134);	// L2036
  int8_t v1135[1][1];	// L2037
  #pragma HLS bind_storage variable=v1135 type=ram_t2p impl=bram

  int8_t v1136[1][512][1][1];	// L2038
  #pragma HLS bind_storage variable=v1136 type=ram_t2p impl=bram

  main_graph_node3(v1134, v1135, v1136);	// L2039
  int8_t v1137[1][512][1][1];	// L2040
  #pragma HLS bind_storage variable=v1137 type=ram_t2p impl=bram

  main_graph_node2(v1136, v1135, v1137);	// L2041
  int8_t v1138[1][1000];	// L2042
  #pragma HLS bind_storage variable=v1138 type=ram_t2p impl=bram

  main_graph_node1(v1137, v1086, v1138);	// L2043
  main_graph_node0(v1138, v1065, v1087);	// L2044
  return ;	// L2045
}

