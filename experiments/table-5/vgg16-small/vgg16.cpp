
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
  int8_t v0[1][512][1][1],
  int8_t v1[10],
  int8_t v2[512][10],
  int8_t v3[1][10]
) {	// L15
  #pragma HLS dataflow

  int8_t v4[1][10];	// L17
  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  int8_t v5[1][10];	// L18
  #pragma HLS bind_storage variable=v5 type=ram_t2p impl=bram

  for (int v6 = 0; v6 < 1; v6 += 1) {	// L19
    for (int v7 = 0; v7 < 10; v7 += 1) {	// L20
      v4[v6][v7] = (int8_t)0.000000;	// L21
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L24
    for (int v9 = 0; v9 < 10; v9 += 1) {	// L25
      for (int v10 = 0; v10 < 512; v10 += 1) {	// L26
        int8_t v11 = v0[v8][v10][0][0];	// L27
        int8_t v12 = v2[v10][v9];	// L28
        int8_t v13 = v4[v8][v9];	// L29
        int8_t v14 = v11 * v12;	// L30
        int8_t v15 = v13 + v14;	// L31
        v5[v8][v9] = v15;	// L32
      }
    }
  }
  for (int v16 = 0; v16 < 1; v16 += 1) {	// L36
    for (int v17 = 0; v17 < 10; v17 += 1) {	// L37
      int8_t v18 = v5[0][v17];	// L38
      int8_t v19 = v1[v17];	// L39
      int8_t v20 = v18 + v19;	// L40
      v3[v16][v17] = v20;	// L41
    }
  }
}

void main_graph_node1(
  int8_t v21[1][512][1][1],
  int8_t v22[1][1],
  int8_t v23[1][512][1][1]
) {	// L46
  #pragma HLS dataflow

  int8_t v24[1][512][1][1];	// L47
  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L48
    for (int v26 = 0; v26 < 512; v26 += 1) {	// L49
      for (int v27 = 0; v27 < 1; v27 += 1) {	// L50
        for (int v28 = 0; v28 < 1; v28 += 1) {	// L51
          int8_t v29 = v21[v25][v26][v27][v28];	// L52
          v24[v25][v26][v27][v28] = v29;	// L53
          int8_t v30 = v22[v27][v28];	// L54
          int8_t v31 = v24[v25][v26][v27][v28];	// L55
          int8_t v32 = v31 / v30;	// L56
          v23[v25][v26][v27][v28] = v32;	// L57
        }
      }
    }
  }
}

void main_graph_node2(
  int8_t v33[1][512][2][2],
  int8_t v34[1][1],
  int8_t v35[1][512][1][1]
) {	// L64
  #pragma HLS dataflow

  int8_t v36[1][512][1][1];	// L68
  #pragma HLS bind_storage variable=v36 type=ram_t2p impl=bram

  for (int v37 = 0; v37 < 1; v37 += 1) {	// L69
    for (int v38 = 0; v38 < 512; v38 += 1) {	// L70
      for (int v39 = 0; v39 < 1; v39 += 1) {	// L71
        for (int v40 = 0; v40 < 1; v40 += 1) {	// L72
          v36[v37][v38][v39][v40] = (int8_t)0.000000;	// L73
        }
      }
    }
  }
  for (int v41 = 0; v41 < 1; v41 += 1) {	// L78
    for (int v42 = 0; v42 < 512; v42 += 1) {	// L79
      for (int v43 = 0; v43 < 1; v43 += 1) {	// L80
        for (int v44 = 0; v44 < 1; v44 += 1) {	// L81
          for (int v45 = 0; v45 < 1; v45 += 1) {	// L82
            for (int v46 = 0; v46 < 1; v46 += 1) {	// L83
              int8_t v47 = v36[v41][v42][v43][v44];	// L84
              int v48 = v43 + (int)1;	// L85
              int v49 = v44 + (int)1;	// L86
              int v50 = v43 + v45;	// L87
              int v51 = v44 + v46;	// L88
              int8_t v52 = v33[v41][v42][v50][v51];	// L89
              bool v53 = v50 < v48;	// L90
              int8_t v54 = v53 ? v52 : (int8_t)0.000000;	// L91
              bool v55 = v51 < v49;	// L92
              int8_t v56 = v55 ? v54 : (int8_t)0.000000;	// L93
              int8_t v57 = v56 + v47;	// L94
              v35[v41][v42][v43][v44] = v57;	// L95
              v34[v41][v42] = (int8_t)1.000000;	// L96
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v58[1][512][1][1],
  int8_t v59[1][512][2][2]
) {	// L105
  #pragma HLS dataflow

  for (int v60 = 0; v60 < 1; v60 += 1) {	// L107
    for (int v61 = 0; v61 < 2; v61 += 1) {	// L108
      for (int v62 = 0; v62 < 2; v62 += 1) {	// L109
        for (int v63 = 0; v63 < 512; v63 += 1) {	// L110
          int8_t v64;	// L111
          v64 = (int8_t)0.000000;	// L112
          if ((-v61) >= 0 && (-v62) >= 0) {	// L113
            int8_t v65 = v58[v60][v63][v61][v62];	// L114
            v64 = v65;	// L115
          }
          int8_t v66 = v64;	// L117
          v59[v60][v63][v61][v62] = v66;	// L118
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v67[1][512][2][2],
  int8_t v68[512][512][3][3],
  int8_t v69[1][512][1][1]
) {	// L125
  #pragma HLS dataflow

  int8_t v70[1][512][4][4];	// L127
  #pragma HLS stream variable=v70 depth=10 type=fifo

  #pragma HLS bind_storage variable=v70 type=ram_t2p impl=bram

  for (int v71 = 0; v71 < 1; v71 += 1) {	// L128
    for (int v72 = 0; v72 < 4; v72 += 1) {	// L129
      for (int v73 = 0; v73 < 4; v73 += 1) {	// L130
        for (int v74 = 0; v74 < 512; v74 += 1) {	// L131
          int8_t v75;	// L132
          v75 = (int8_t)0.000000;	// L133
          if (((-v72) + 1) >= 0 && ((-v73) + 1) >= 0) {	// L134
            int8_t v76 = v67[v71][v74][v72][v73];	// L135
            v75 = v76;	// L136
          }
          int8_t v77 = v75;	// L138
          v70[v71][v74][v72][v73] = v77;	// L139
        }
      }
    }
  }
  int8_t v78[1][512][1][1];	// L144
  #pragma HLS stream variable=v78 depth=10 type=fifo

  #pragma HLS bind_storage variable=v78 type=ram_t2p impl=bram

  int8_t v79[1][512][3][4];	// L145
  #pragma HLS array_partition variable=v79 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v79 type=ram_2p impl=bram

  int8_t v80[1][512][3][3];	// L146
  #pragma HLS array_partition variable=v80 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v80 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v80 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v80 type=ram_2p impl=lutram

  for (int v81 = 0; v81 < 1; v81 += 1) {	// L147
    for (int v82 = 0; v82 < 4; v82 += 1) {	// L148
      for (int v83 = 0; v83 < 4; v83 += 1) {	// L149
        for (int v84 = 0; v84 < 512; v84 += 1) {	// L150
          int8_t v85 = v79[v81][v84][1][v83];	// L151
          v79[v81][v84][0][v83] = v85;	// L152
          int8_t v86 = v79[v81][v84][2][v83];	// L153
          v79[v81][v84][1][v83] = v86;	// L154
          int8_t v87 = v70[v81][v84][v82][v83];	// L155
          v79[v81][v84][2][v83] = v87;	// L156
        }
        if ((v82 - 3) >= 0) {	// L158
          for (int v88 = 0; v88 < 512; v88 += 1) {	// L159
            for (int v89 = 0; v89 < 3; v89 += 1) {	// L160
              int8_t v90 = v80[v81][v88][v89][1];	// L161
              v80[v81][v88][v89][0] = v90;	// L162
              int8_t v91 = v80[v81][v88][v89][2];	// L163
              v80[v81][v88][v89][1] = v91;	// L164
              int8_t v92 = v79[v81][v88][v89][v83];	// L165
              v80[v81][v88][v89][2] = v92;	// L166
            }
          }
          if ((v83 - 3) >= 0) {	// L169
            int8_t v93[512];	// L170
            #pragma HLS bind_storage variable=v93 type=ram_2p impl=bram

            for (int v94 = 0; v94 < 512; v94 += 1) {	// L171
              v93[v94] = (int8_t)0.000000;	// L172
              for (int v95 = 0; v95 < 128; v95 += 1) {	// L173
                #pragma HLS pipeline II=1
                for (int v96 = 0; v96 < 4; v96 += 1) {	// L174
                  for (int v97 = 0; v97 < 3; v97 += 1) {	// L175
                    for (int v98 = 0; v98 < 3; v98 += 1) {	// L176
                      int8_t v99 = v80[v81][(v96 + (v95 * 4))][v97][v98];	// L177
                      int8_t v100 = v68[v94][(v96 + (v95 * 4))][v97][v98];	// L178
                      int8_t v101 = v99 * v100;	// L179
                      int8_t v102 = v93[v94];	// L180
                      int8_t v103 = v102 + v101;	// L181
                      v93[v94] = v103;	// L182
                    }
                  }
                }
              }
              int8_t v104 = v93[v94];	// L187
              v78[v81][v94][(v82 - 3)][(v83 - 3)] = v104;	// L188
            }
          }
        }
      }
    }
  }
  for (int v105 = 0; v105 < 1; v105 += 1) {	// L195
    for (int v106 = 0; v106 < 1; v106 += 1) {	// L196
      for (int v107 = 0; v107 < 1; v107 += 1) {	// L197
        for (int v108 = 0; v108 < 512; v108 += 1) {	// L198
          int8_t v109 = v78[0][v108][0][0];	// L199
          bool v110 = v109 > (int8_t)0.000000;	// L200
          int8_t v111 = v110 ? v109 : (int8_t)0.000000;	// L201
          v69[v105][v108][v106][v107] = v111;	// L202
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v112[1][512][2][2],
  int8_t v113[512][512][3][3],
  int8_t v114[1][512][2][2]
) {	// L209
  #pragma HLS dataflow

  int8_t v115[1][512][4][4];	// L211
  #pragma HLS stream variable=v115 depth=10 type=fifo

  #pragma HLS bind_storage variable=v115 type=ram_t2p impl=bram

  for (int v116 = 0; v116 < 1; v116 += 1) {	// L212
    for (int v117 = 0; v117 < 4; v117 += 1) {	// L213
      for (int v118 = 0; v118 < 4; v118 += 1) {	// L214
        for (int v119 = 0; v119 < 512; v119 += 1) {	// L215
          int8_t v120;	// L216
          v120 = (int8_t)0.000000;	// L217
          if (((-v117) + 1) >= 0 && ((-v118) + 1) >= 0) {	// L218
            int8_t v121 = v112[v116][v119][v117][v118];	// L219
            v120 = v121;	// L220
          }
          int8_t v122 = v120;	// L222
          v115[v116][v119][v117][v118] = v122;	// L223
        }
      }
    }
  }
  int8_t v123[1][512][2][2];	// L228
  #pragma HLS stream variable=v123 depth=10 type=fifo

  #pragma HLS bind_storage variable=v123 type=ram_t2p impl=bram

  int8_t v124[1][512][3][4];	// L229
  #pragma HLS array_partition variable=v124 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v124 type=ram_2p impl=bram

  int8_t v125[1][512][3][3];	// L230
  #pragma HLS array_partition variable=v125 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v125 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v125 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v125 type=ram_2p impl=lutram

  for (int v126 = 0; v126 < 1; v126 += 1) {	// L231
    for (int v127 = 0; v127 < 4; v127 += 1) {	// L232
      for (int v128 = 0; v128 < 4; v128 += 1) {	// L233
        for (int v129 = 0; v129 < 512; v129 += 1) {	// L234
          int8_t v130 = v124[v126][v129][1][v128];	// L235
          v124[v126][v129][0][v128] = v130;	// L236
          int8_t v131 = v124[v126][v129][2][v128];	// L237
          v124[v126][v129][1][v128] = v131;	// L238
          int8_t v132 = v115[v126][v129][v127][v128];	// L239
          v124[v126][v129][2][v128] = v132;	// L240
        }
        if ((v127 - 2) >= 0) {	// L242
          for (int v133 = 0; v133 < 512; v133 += 1) {	// L243
            for (int v134 = 0; v134 < 3; v134 += 1) {	// L244
              int8_t v135 = v125[v126][v133][v134][1];	// L245
              v125[v126][v133][v134][0] = v135;	// L246
              int8_t v136 = v125[v126][v133][v134][2];	// L247
              v125[v126][v133][v134][1] = v136;	// L248
              int8_t v137 = v124[v126][v133][v134][v128];	// L249
              v125[v126][v133][v134][2] = v137;	// L250
            }
          }
          if ((v128 - 2) >= 0) {	// L253
            int8_t v138[512];	// L254
            #pragma HLS bind_storage variable=v138 type=ram_2p impl=bram

            for (int v139 = 0; v139 < 512; v139 += 1) {	// L255
              v138[v139] = (int8_t)0.000000;	// L256
              for (int v140 = 0; v140 < 128; v140 += 1) {	// L257
                #pragma HLS pipeline II=1
                for (int v141 = 0; v141 < 4; v141 += 1) {	// L258
                  for (int v142 = 0; v142 < 3; v142 += 1) {	// L259
                    for (int v143 = 0; v143 < 3; v143 += 1) {	// L260
                      int8_t v144 = v125[v126][(v141 + (v140 * 4))][v142][v143];	// L261
                      int8_t v145 = v113[v139][(v141 + (v140 * 4))][v142][v143];	// L262
                      int8_t v146 = v144 * v145;	// L263
                      int8_t v147 = v138[v139];	// L264
                      int8_t v148 = v147 + v146;	// L265
                      v138[v139] = v148;	// L266
                    }
                  }
                }
              }
              int8_t v149 = v138[v139];	// L271
              v123[v126][v139][(v127 - 2)][(v128 - 2)] = v149;	// L272
            }
          }
        }
      }
    }
  }
  for (int v150 = 0; v150 < 1; v150 += 1) {	// L279
    for (int v151 = 0; v151 < 2; v151 += 1) {	// L280
      for (int v152 = 0; v152 < 2; v152 += 1) {	// L281
        for (int v153 = 0; v153 < 512; v153 += 1) {	// L282
          int8_t v154 = v123[0][v153][v151][v152];	// L283
          bool v155 = v154 > (int8_t)0.000000;	// L284
          int8_t v156 = v155 ? v154 : (int8_t)0.000000;	// L285
          v114[v150][v153][v151][v152] = v156;	// L286
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v157[512][512][3][3],
  int8_t v158[1][512][2][2],
  int8_t v159[1][512][2][2]
) {	// L293
  #pragma HLS dataflow

  int8_t v160[1][512][4][4];	// L295
  #pragma HLS stream variable=v160 depth=10 type=fifo

  #pragma HLS bind_storage variable=v160 type=ram_t2p impl=bram

  for (int v161 = 0; v161 < 1; v161 += 1) {	// L296
    for (int v162 = 0; v162 < 4; v162 += 1) {	// L297
      for (int v163 = 0; v163 < 4; v163 += 1) {	// L298
        for (int v164 = 0; v164 < 512; v164 += 1) {	// L299
          int8_t v165;	// L300
          v165 = (int8_t)0.000000;	// L301
          if (((-v162) + 1) >= 0 && ((-v163) + 1) >= 0) {	// L302
            int8_t v166 = v158[v161][v164][v162][v163];	// L303
            v165 = v166;	// L304
          }
          int8_t v167 = v165;	// L306
          v160[v161][v164][v162][v163] = v167;	// L307
        }
      }
    }
  }
  int8_t v168[1][512][2][2];	// L312
  #pragma HLS stream variable=v168 depth=10 type=fifo

  #pragma HLS bind_storage variable=v168 type=ram_t2p impl=bram

  int8_t v169[1][512][3][4];	// L313
  #pragma HLS array_partition variable=v169 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v169 type=ram_2p impl=bram

  int8_t v170[1][512][3][3];	// L314
  #pragma HLS array_partition variable=v170 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v170 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v170 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v170 type=ram_2p impl=lutram

  for (int v171 = 0; v171 < 1; v171 += 1) {	// L315
    for (int v172 = 0; v172 < 4; v172 += 1) {	// L316
      for (int v173 = 0; v173 < 4; v173 += 1) {	// L317
        for (int v174 = 0; v174 < 512; v174 += 1) {	// L318
          int8_t v175 = v169[v171][v174][1][v173];	// L319
          v169[v171][v174][0][v173] = v175;	// L320
          int8_t v176 = v169[v171][v174][2][v173];	// L321
          v169[v171][v174][1][v173] = v176;	// L322
          int8_t v177 = v160[v171][v174][v172][v173];	// L323
          v169[v171][v174][2][v173] = v177;	// L324
        }
        if ((v172 - 2) >= 0) {	// L326
          for (int v178 = 0; v178 < 512; v178 += 1) {	// L327
            for (int v179 = 0; v179 < 3; v179 += 1) {	// L328
              int8_t v180 = v170[v171][v178][v179][1];	// L329
              v170[v171][v178][v179][0] = v180;	// L330
              int8_t v181 = v170[v171][v178][v179][2];	// L331
              v170[v171][v178][v179][1] = v181;	// L332
              int8_t v182 = v169[v171][v178][v179][v173];	// L333
              v170[v171][v178][v179][2] = v182;	// L334
            }
          }
          if ((v173 - 2) >= 0) {	// L337
            int8_t v183[512];	// L338
            #pragma HLS bind_storage variable=v183 type=ram_2p impl=bram

            for (int v184 = 0; v184 < 512; v184 += 1) {	// L339
              v183[v184] = (int8_t)0.000000;	// L340
              for (int v185 = 0; v185 < 128; v185 += 1) {	// L341
                #pragma HLS pipeline II=1
                for (int v186 = 0; v186 < 4; v186 += 1) {	// L342
                  for (int v187 = 0; v187 < 3; v187 += 1) {	// L343
                    for (int v188 = 0; v188 < 3; v188 += 1) {	// L344
                      int8_t v189 = v170[v171][(v186 + (v185 * 4))][v187][v188];	// L345
                      int8_t v190 = v157[v184][(v186 + (v185 * 4))][v187][v188];	// L346
                      int8_t v191 = v189 * v190;	// L347
                      int8_t v192 = v183[v184];	// L348
                      int8_t v193 = v192 + v191;	// L349
                      v183[v184] = v193;	// L350
                    }
                  }
                }
              }
              int8_t v194 = v183[v184];	// L355
              v168[v171][v184][(v172 - 2)][(v173 - 2)] = v194;	// L356
            }
          }
        }
      }
    }
  }
  for (int v195 = 0; v195 < 1; v195 += 1) {	// L363
    for (int v196 = 0; v196 < 2; v196 += 1) {	// L364
      for (int v197 = 0; v197 < 2; v197 += 1) {	// L365
        for (int v198 = 0; v198 < 512; v198 += 1) {	// L366
          int8_t v199 = v168[0][v198][v196][v197];	// L367
          bool v200 = v199 > (int8_t)0.000000;	// L368
          int8_t v201 = v200 ? v199 : (int8_t)0.000000;	// L369
          v159[v195][v198][v196][v197] = v201;	// L370
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v202[1][512][4][4],
  int8_t v203[512][512][3][3],
  int8_t v204[1][512][2][2]
) {	// L377
  #pragma HLS dataflow

  int8_t v205[1][512][6][6];	// L379
  #pragma HLS stream variable=v205 depth=10 type=fifo

  #pragma HLS bind_storage variable=v205 type=ram_t2p impl=bram

  for (int v206 = 0; v206 < 1; v206 += 1) {	// L380
    for (int v207 = 0; v207 < 6; v207 += 1) {	// L381
      for (int v208 = 0; v208 < 6; v208 += 1) {	// L382
        for (int v209 = 0; v209 < 512; v209 += 1) {	// L383
          int8_t v210;	// L384
          v210 = (int8_t)0.000000;	// L385
          if (((-v207) + 3) >= 0 && ((-v208) + 3) >= 0) {	// L386
            int8_t v211 = v202[v206][v209][v207][v208];	// L387
            v210 = v211;	// L388
          }
          int8_t v212 = v210;	// L390
          v205[v206][v209][v207][v208] = v212;	// L391
        }
      }
    }
  }
  int8_t v213[1][512][2][2];	// L396
  #pragma HLS stream variable=v213 depth=10 type=fifo

  #pragma HLS bind_storage variable=v213 type=ram_t2p impl=bram

  int8_t v214[1][512][3][6];	// L397
  #pragma HLS array_partition variable=v214 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v214 type=ram_2p impl=bram

  int8_t v215[1][512][3][3];	// L398
  #pragma HLS array_partition variable=v215 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v215 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v215 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v215 type=ram_2p impl=lutram

  for (int v216 = 0; v216 < 1; v216 += 1) {	// L399
    for (int v217 = 0; v217 < 6; v217 += 1) {	// L400
      for (int v218 = 0; v218 < 6; v218 += 1) {	// L401
        for (int v219 = 0; v219 < 512; v219 += 1) {	// L402
          int8_t v220 = v214[v216][v219][1][v218];	// L403
          v214[v216][v219][0][v218] = v220;	// L404
          int8_t v221 = v214[v216][v219][2][v218];	// L405
          v214[v216][v219][1][v218] = v221;	// L406
          int8_t v222 = v205[v216][v219][v217][v218];	// L407
          v214[v216][v219][2][v218] = v222;	// L408
        }
        if ((v217 - 4) >= 0) {	// L410
          for (int v223 = 0; v223 < 512; v223 += 1) {	// L411
            for (int v224 = 0; v224 < 3; v224 += 1) {	// L412
              int8_t v225 = v215[v216][v223][v224][1];	// L413
              v215[v216][v223][v224][0] = v225;	// L414
              int8_t v226 = v215[v216][v223][v224][2];	// L415
              v215[v216][v223][v224][1] = v226;	// L416
              int8_t v227 = v214[v216][v223][v224][v218];	// L417
              v215[v216][v223][v224][2] = v227;	// L418
            }
          }
          if ((v218 - 4) >= 0) {	// L421
            int8_t v228[512];	// L422
            #pragma HLS bind_storage variable=v228 type=ram_2p impl=bram

            for (int v229 = 0; v229 < 512; v229 += 1) {	// L423
              v228[v229] = (int8_t)0.000000;	// L424
              for (int v230 = 0; v230 < 64; v230 += 1) {	// L425
                #pragma HLS pipeline II=1
                for (int v231 = 0; v231 < 8; v231 += 1) {	// L426
                  for (int v232 = 0; v232 < 3; v232 += 1) {	// L427
                    for (int v233 = 0; v233 < 3; v233 += 1) {	// L428
                      int8_t v234 = v215[v216][(v231 + (v230 * 8))][v232][v233];	// L429
                      int8_t v235 = v203[v229][(v231 + (v230 * 8))][v232][v233];	// L430
                      int8_t v236 = v234 * v235;	// L431
                      int8_t v237 = v228[v229];	// L432
                      int8_t v238 = v237 + v236;	// L433
                      v228[v229] = v238;	// L434
                    }
                  }
                }
              }
              int8_t v239 = v228[v229];	// L439
              v213[v216][v229][(v217 - 4)][(v218 - 4)] = v239;	// L440
            }
          }
        }
      }
    }
  }
  for (int v240 = 0; v240 < 1; v240 += 1) {	// L447
    for (int v241 = 0; v241 < 2; v241 += 1) {	// L448
      for (int v242 = 0; v242 < 2; v242 += 1) {	// L449
        for (int v243 = 0; v243 < 512; v243 += 1) {	// L450
          int8_t v244 = v213[0][v243][v241][v242];	// L451
          bool v245 = v244 > (int8_t)0.000000;	// L452
          int8_t v246 = v245 ? v244 : (int8_t)0.000000;	// L453
          v204[v240][v243][v241][v242] = v246;	// L454
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v247[1][512][4][4],
  int8_t v248[512][512][3][3],
  int8_t v249[1][512][4][4]
) {	// L461
  #pragma HLS dataflow

  int8_t v250[1][512][6][6];	// L463
  #pragma HLS stream variable=v250 depth=10 type=fifo

  #pragma HLS bind_storage variable=v250 type=ram_t2p impl=bram

  for (int v251 = 0; v251 < 1; v251 += 1) {	// L464
    for (int v252 = 0; v252 < 6; v252 += 1) {	// L465
      for (int v253 = 0; v253 < 6; v253 += 1) {	// L466
        for (int v254 = 0; v254 < 512; v254 += 1) {	// L467
          int8_t v255;	// L468
          v255 = (int8_t)0.000000;	// L469
          if (((-v252) + 3) >= 0 && ((-v253) + 3) >= 0) {	// L470
            int8_t v256 = v247[v251][v254][v252][v253];	// L471
            v255 = v256;	// L472
          }
          int8_t v257 = v255;	// L474
          v250[v251][v254][v252][v253] = v257;	// L475
        }
      }
    }
  }
  int8_t v258[1][512][4][4];	// L480
  #pragma HLS stream variable=v258 depth=10 type=fifo

  #pragma HLS bind_storage variable=v258 type=ram_t2p impl=bram

  int8_t v259[1][512][3][6];	// L481
  #pragma HLS array_partition variable=v259 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v259 type=ram_2p impl=bram

  int8_t v260[1][512][3][3];	// L482
  #pragma HLS array_partition variable=v260 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v260 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v260 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v260 type=ram_2p impl=lutram

  for (int v261 = 0; v261 < 1; v261 += 1) {	// L483
    for (int v262 = 0; v262 < 6; v262 += 1) {	// L484
      for (int v263 = 0; v263 < 6; v263 += 1) {	// L485
        for (int v264 = 0; v264 < 512; v264 += 1) {	// L486
          int8_t v265 = v259[v261][v264][1][v263];	// L487
          v259[v261][v264][0][v263] = v265;	// L488
          int8_t v266 = v259[v261][v264][2][v263];	// L489
          v259[v261][v264][1][v263] = v266;	// L490
          int8_t v267 = v250[v261][v264][v262][v263];	// L491
          v259[v261][v264][2][v263] = v267;	// L492
        }
        if ((v262 - 2) >= 0) {	// L494
          for (int v268 = 0; v268 < 512; v268 += 1) {	// L495
            for (int v269 = 0; v269 < 3; v269 += 1) {	// L496
              int8_t v270 = v260[v261][v268][v269][1];	// L497
              v260[v261][v268][v269][0] = v270;	// L498
              int8_t v271 = v260[v261][v268][v269][2];	// L499
              v260[v261][v268][v269][1] = v271;	// L500
              int8_t v272 = v259[v261][v268][v269][v263];	// L501
              v260[v261][v268][v269][2] = v272;	// L502
            }
          }
          if ((v263 - 2) >= 0) {	// L505
            int8_t v273[512];	// L506
            #pragma HLS bind_storage variable=v273 type=ram_2p impl=bram

            for (int v274 = 0; v274 < 512; v274 += 1) {	// L507
              v273[v274] = (int8_t)0.000000;	// L508
              for (int v275 = 0; v275 < 64; v275 += 1) {	// L509
                #pragma HLS pipeline II=1
                for (int v276 = 0; v276 < 8; v276 += 1) {	// L510
                  for (int v277 = 0; v277 < 3; v277 += 1) {	// L511
                    for (int v278 = 0; v278 < 3; v278 += 1) {	// L512
                      int8_t v279 = v260[v261][(v276 + (v275 * 8))][v277][v278];	// L513
                      int8_t v280 = v248[v274][(v276 + (v275 * 8))][v277][v278];	// L514
                      int8_t v281 = v279 * v280;	// L515
                      int8_t v282 = v273[v274];	// L516
                      int8_t v283 = v282 + v281;	// L517
                      v273[v274] = v283;	// L518
                    }
                  }
                }
              }
              int8_t v284 = v273[v274];	// L523
              v258[v261][v274][(v262 - 2)][(v263 - 2)] = v284;	// L524
            }
          }
        }
      }
    }
  }
  for (int v285 = 0; v285 < 1; v285 += 1) {	// L531
    for (int v286 = 0; v286 < 4; v286 += 1) {	// L532
      for (int v287 = 0; v287 < 4; v287 += 1) {	// L533
        for (int v288 = 0; v288 < 512; v288 += 1) {	// L534
          int8_t v289 = v258[0][v288][v286][v287];	// L535
          bool v290 = v289 > (int8_t)0.000000;	// L536
          int8_t v291 = v290 ? v289 : (int8_t)0.000000;	// L537
          v249[v285][v288][v286][v287] = v291;	// L538
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v292[1][256][4][4],
  int8_t v293[512][256][3][3],
  int8_t v294[1][512][4][4]
) {	// L545
  #pragma HLS dataflow

  int8_t v295[1][256][6][6];	// L547
  #pragma HLS stream variable=v295 depth=10 type=fifo

  #pragma HLS bind_storage variable=v295 type=ram_t2p impl=bram

  for (int v296 = 0; v296 < 1; v296 += 1) {	// L548
    for (int v297 = 0; v297 < 6; v297 += 1) {	// L549
      for (int v298 = 0; v298 < 6; v298 += 1) {	// L550
        for (int v299 = 0; v299 < 256; v299 += 1) {	// L551
          int8_t v300;	// L552
          v300 = (int8_t)0.000000;	// L553
          if (((-v297) + 3) >= 0 && ((-v298) + 3) >= 0) {	// L554
            int8_t v301 = v292[v296][v299][v297][v298];	// L555
            v300 = v301;	// L556
          }
          int8_t v302 = v300;	// L558
          v295[v296][v299][v297][v298] = v302;	// L559
        }
      }
    }
  }
  int8_t v303[1][512][4][4];	// L564
  #pragma HLS stream variable=v303 depth=10 type=fifo

  #pragma HLS bind_storage variable=v303 type=ram_t2p impl=bram

  int8_t v304[1][256][3][6];	// L565
  #pragma HLS array_partition variable=v304 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v304 type=ram_2p impl=bram

  int8_t v305[1][256][3][3];	// L566
  #pragma HLS array_partition variable=v305 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v305 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v305 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v305 type=ram_2p impl=lutram

  for (int v306 = 0; v306 < 1; v306 += 1) {	// L567
    for (int v307 = 0; v307 < 6; v307 += 1) {	// L568
      for (int v308 = 0; v308 < 6; v308 += 1) {	// L569
        for (int v309 = 0; v309 < 256; v309 += 1) {	// L570
          int8_t v310 = v304[v306][v309][1][v308];	// L571
          v304[v306][v309][0][v308] = v310;	// L572
          int8_t v311 = v304[v306][v309][2][v308];	// L573
          v304[v306][v309][1][v308] = v311;	// L574
          int8_t v312 = v295[v306][v309][v307][v308];	// L575
          v304[v306][v309][2][v308] = v312;	// L576
        }
        if ((v307 - 2) >= 0) {	// L578
          for (int v313 = 0; v313 < 256; v313 += 1) {	// L579
            for (int v314 = 0; v314 < 3; v314 += 1) {	// L580
              int8_t v315 = v305[v306][v313][v314][1];	// L581
              v305[v306][v313][v314][0] = v315;	// L582
              int8_t v316 = v305[v306][v313][v314][2];	// L583
              v305[v306][v313][v314][1] = v316;	// L584
              int8_t v317 = v304[v306][v313][v314][v308];	// L585
              v305[v306][v313][v314][2] = v317;	// L586
            }
          }
          if ((v308 - 2) >= 0) {	// L589
            int8_t v318[512];	// L590
            #pragma HLS bind_storage variable=v318 type=ram_2p impl=bram

            for (int v319 = 0; v319 < 512; v319 += 1) {	// L591
              v318[v319] = (int8_t)0.000000;	// L592
              for (int v320 = 0; v320 < 64; v320 += 1) {	// L593
                #pragma HLS pipeline II=1
                for (int v321 = 0; v321 < 4; v321 += 1) {	// L594
                  for (int v322 = 0; v322 < 3; v322 += 1) {	// L595
                    for (int v323 = 0; v323 < 3; v323 += 1) {	// L596
                      int8_t v324 = v305[v306][(v321 + (v320 * 4))][v322][v323];	// L597
                      int8_t v325 = v293[v319][(v321 + (v320 * 4))][v322][v323];	// L598
                      int8_t v326 = v324 * v325;	// L599
                      int8_t v327 = v318[v319];	// L600
                      int8_t v328 = v327 + v326;	// L601
                      v318[v319] = v328;	// L602
                    }
                  }
                }
              }
              int8_t v329 = v318[v319];	// L607
              v303[v306][v319][(v307 - 2)][(v308 - 2)] = v329;	// L608
            }
          }
        }
      }
    }
  }
  for (int v330 = 0; v330 < 1; v330 += 1) {	// L615
    for (int v331 = 0; v331 < 4; v331 += 1) {	// L616
      for (int v332 = 0; v332 < 4; v332 += 1) {	// L617
        for (int v333 = 0; v333 < 512; v333 += 1) {	// L618
          int8_t v334 = v303[0][v333][v331][v332];	// L619
          bool v335 = v334 > (int8_t)0.000000;	// L620
          int8_t v336 = v335 ? v334 : (int8_t)0.000000;	// L621
          v294[v330][v333][v331][v332] = v336;	// L622
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v337[1][256][8][8],
  int8_t v338[256][256][3][3],
  int8_t v339[1][256][4][4]
) {	// L629
  #pragma HLS dataflow

  int8_t v340[1][256][10][10];	// L631
  #pragma HLS stream variable=v340 depth=10 type=fifo

  #pragma HLS bind_storage variable=v340 type=ram_t2p impl=bram

  for (int v341 = 0; v341 < 1; v341 += 1) {	// L632
    for (int v342 = 0; v342 < 10; v342 += 1) {	// L633
      for (int v343 = 0; v343 < 10; v343 += 1) {	// L634
        for (int v344 = 0; v344 < 256; v344 += 1) {	// L635
          int8_t v345;	// L636
          v345 = (int8_t)0.000000;	// L637
          if (((-v342) + 7) >= 0 && ((-v343) + 7) >= 0) {	// L638
            int8_t v346 = v337[v341][v344][v342][v343];	// L639
            v345 = v346;	// L640
          }
          int8_t v347 = v345;	// L642
          v340[v341][v344][v342][v343] = v347;	// L643
        }
      }
    }
  }
  int8_t v348[1][256][4][4];	// L648
  #pragma HLS stream variable=v348 depth=10 type=fifo

  #pragma HLS bind_storage variable=v348 type=ram_t2p impl=bram

  int8_t v349[1][256][3][10];	// L649
  #pragma HLS array_partition variable=v349 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v349 type=ram_2p impl=bram

  int8_t v350[1][256][3][3];	// L650
  #pragma HLS array_partition variable=v350 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v350 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v350 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v350 type=ram_2p impl=lutram

  for (int v351 = 0; v351 < 1; v351 += 1) {	// L651
    for (int v352 = 0; v352 < 10; v352 += 1) {	// L652
      for (int v353 = 0; v353 < 10; v353 += 1) {	// L653
        for (int v354 = 0; v354 < 256; v354 += 1) {	// L654
          int8_t v355 = v349[v351][v354][1][v353];	// L655
          v349[v351][v354][0][v353] = v355;	// L656
          int8_t v356 = v349[v351][v354][2][v353];	// L657
          v349[v351][v354][1][v353] = v356;	// L658
          int8_t v357 = v340[v351][v354][v352][v353];	// L659
          v349[v351][v354][2][v353] = v357;	// L660
        }
        if ((v352 - 6) >= 0) {	// L662
          for (int v358 = 0; v358 < 256; v358 += 1) {	// L663
            for (int v359 = 0; v359 < 3; v359 += 1) {	// L664
              int8_t v360 = v350[v351][v358][v359][1];	// L665
              v350[v351][v358][v359][0] = v360;	// L666
              int8_t v361 = v350[v351][v358][v359][2];	// L667
              v350[v351][v358][v359][1] = v361;	// L668
              int8_t v362 = v349[v351][v358][v359][v353];	// L669
              v350[v351][v358][v359][2] = v362;	// L670
            }
          }
          if ((v353 - 6) >= 0) {	// L673
            int8_t v363[256];	// L674
            #pragma HLS bind_storage variable=v363 type=ram_2p impl=bram

            for (int v364 = 0; v364 < 256; v364 += 1) {	// L675
              v363[v364] = (int8_t)0.000000;	// L676
              for (int v365 = 0; v365 < 32; v365 += 1) {	// L677
                #pragma HLS pipeline II=1
                for (int v366 = 0; v366 < 8; v366 += 1) {	// L678
                  for (int v367 = 0; v367 < 3; v367 += 1) {	// L679
                    for (int v368 = 0; v368 < 3; v368 += 1) {	// L680
                      int8_t v369 = v350[v351][(v366 + (v365 * 8))][v367][v368];	// L681
                      int8_t v370 = v338[v364][(v366 + (v365 * 8))][v367][v368];	// L682
                      int8_t v371 = v369 * v370;	// L683
                      int8_t v372 = v363[v364];	// L684
                      int8_t v373 = v372 + v371;	// L685
                      v363[v364] = v373;	// L686
                    }
                  }
                }
              }
              int8_t v374 = v363[v364];	// L691
              v348[v351][v364][(v352 - 6)][(v353 - 6)] = v374;	// L692
            }
          }
        }
      }
    }
  }
  for (int v375 = 0; v375 < 1; v375 += 1) {	// L699
    for (int v376 = 0; v376 < 4; v376 += 1) {	// L700
      for (int v377 = 0; v377 < 4; v377 += 1) {	// L701
        for (int v378 = 0; v378 < 256; v378 += 1) {	// L702
          int8_t v379 = v348[0][v378][v376][v377];	// L703
          bool v380 = v379 > (int8_t)0.000000;	// L704
          int8_t v381 = v380 ? v379 : (int8_t)0.000000;	// L705
          v339[v375][v378][v376][v377] = v381;	// L706
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v382[256][256][3][3],
  int8_t v383[1][256][8][8],
  int8_t v384[1][256][8][8]
) {	// L713
  #pragma HLS dataflow

  int8_t v385[1][256][10][10];	// L715
  #pragma HLS stream variable=v385 depth=10 type=fifo

  #pragma HLS bind_storage variable=v385 type=ram_t2p impl=bram

  for (int v386 = 0; v386 < 1; v386 += 1) {	// L716
    for (int v387 = 0; v387 < 10; v387 += 1) {	// L717
      for (int v388 = 0; v388 < 10; v388 += 1) {	// L718
        for (int v389 = 0; v389 < 256; v389 += 1) {	// L719
          int8_t v390;	// L720
          v390 = (int8_t)0.000000;	// L721
          if (((-v387) + 7) >= 0 && ((-v388) + 7) >= 0) {	// L722
            int8_t v391 = v383[v386][v389][v387][v388];	// L723
            v390 = v391;	// L724
          }
          int8_t v392 = v390;	// L726
          v385[v386][v389][v387][v388] = v392;	// L727
        }
      }
    }
  }
  int8_t v393[1][256][8][8];	// L732
  #pragma HLS stream variable=v393 depth=10 type=fifo

  #pragma HLS bind_storage variable=v393 type=ram_t2p impl=bram

  int8_t v394[1][256][3][10];	// L733
  #pragma HLS array_partition variable=v394 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v394 type=ram_2p impl=bram

  int8_t v395[1][256][3][3];	// L734
  #pragma HLS array_partition variable=v395 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v395 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v395 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v395 type=ram_2p impl=lutram

  for (int v396 = 0; v396 < 1; v396 += 1) {	// L735
    for (int v397 = 0; v397 < 10; v397 += 1) {	// L736
      for (int v398 = 0; v398 < 10; v398 += 1) {	// L737
        for (int v399 = 0; v399 < 256; v399 += 1) {	// L738
          int8_t v400 = v394[v396][v399][1][v398];	// L739
          v394[v396][v399][0][v398] = v400;	// L740
          int8_t v401 = v394[v396][v399][2][v398];	// L741
          v394[v396][v399][1][v398] = v401;	// L742
          int8_t v402 = v385[v396][v399][v397][v398];	// L743
          v394[v396][v399][2][v398] = v402;	// L744
        }
        if ((v397 - 2) >= 0) {	// L746
          for (int v403 = 0; v403 < 256; v403 += 1) {	// L747
            for (int v404 = 0; v404 < 3; v404 += 1) {	// L748
              int8_t v405 = v395[v396][v403][v404][1];	// L749
              v395[v396][v403][v404][0] = v405;	// L750
              int8_t v406 = v395[v396][v403][v404][2];	// L751
              v395[v396][v403][v404][1] = v406;	// L752
              int8_t v407 = v394[v396][v403][v404][v398];	// L753
              v395[v396][v403][v404][2] = v407;	// L754
            }
          }
          if ((v398 - 2) >= 0) {	// L757
            int8_t v408[256];	// L758
            #pragma HLS bind_storage variable=v408 type=ram_2p impl=bram

            for (int v409 = 0; v409 < 256; v409 += 1) {	// L759
              v408[v409] = (int8_t)0.000000;	// L760
              for (int v410 = 0; v410 < 32; v410 += 1) {	// L761
                #pragma HLS pipeline II=1
                for (int v411 = 0; v411 < 8; v411 += 1) {	// L762
                  for (int v412 = 0; v412 < 3; v412 += 1) {	// L763
                    for (int v413 = 0; v413 < 3; v413 += 1) {	// L764
                      int8_t v414 = v395[v396][(v411 + (v410 * 8))][v412][v413];	// L765
                      int8_t v415 = v382[v409][(v411 + (v410 * 8))][v412][v413];	// L766
                      int8_t v416 = v414 * v415;	// L767
                      int8_t v417 = v408[v409];	// L768
                      int8_t v418 = v417 + v416;	// L769
                      v408[v409] = v418;	// L770
                    }
                  }
                }
              }
              int8_t v419 = v408[v409];	// L775
              v393[v396][v409][(v397 - 2)][(v398 - 2)] = v419;	// L776
            }
          }
        }
      }
    }
  }
  for (int v420 = 0; v420 < 1; v420 += 1) {	// L783
    for (int v421 = 0; v421 < 8; v421 += 1) {	// L784
      for (int v422 = 0; v422 < 8; v422 += 1) {	// L785
        for (int v423 = 0; v423 < 256; v423 += 1) {	// L786
          int8_t v424 = v393[0][v423][v421][v422];	// L787
          bool v425 = v424 > (int8_t)0.000000;	// L788
          int8_t v426 = v425 ? v424 : (int8_t)0.000000;	// L789
          v384[v420][v423][v421][v422] = v426;	// L790
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v427[1][128][8][8],
  int8_t v428[256][128][3][3],
  int8_t v429[1][256][8][8]
) {	// L797
  #pragma HLS dataflow

  int8_t v430[1][128][10][10];	// L799
  #pragma HLS stream variable=v430 depth=10 type=fifo

  #pragma HLS bind_storage variable=v430 type=ram_t2p impl=bram

  for (int v431 = 0; v431 < 1; v431 += 1) {	// L800
    for (int v432 = 0; v432 < 10; v432 += 1) {	// L801
      for (int v433 = 0; v433 < 10; v433 += 1) {	// L802
        for (int v434 = 0; v434 < 128; v434 += 1) {	// L803
          int8_t v435;	// L804
          v435 = (int8_t)0.000000;	// L805
          if (((-v432) + 7) >= 0 && ((-v433) + 7) >= 0) {	// L806
            int8_t v436 = v427[v431][v434][v432][v433];	// L807
            v435 = v436;	// L808
          }
          int8_t v437 = v435;	// L810
          v430[v431][v434][v432][v433] = v437;	// L811
        }
      }
    }
  }
  int8_t v438[1][256][8][8];	// L816
  #pragma HLS stream variable=v438 depth=10 type=fifo

  #pragma HLS bind_storage variable=v438 type=ram_t2p impl=bram

  int8_t v439[1][128][3][10];	// L817
  #pragma HLS array_partition variable=v439 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v439 type=ram_2p impl=bram

  int8_t v440[1][128][3][3];	// L818
  #pragma HLS array_partition variable=v440 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v440 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v440 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v440 type=ram_2p impl=lutram

  for (int v441 = 0; v441 < 1; v441 += 1) {	// L819
    for (int v442 = 0; v442 < 10; v442 += 1) {	// L820
      for (int v443 = 0; v443 < 10; v443 += 1) {	// L821
        for (int v444 = 0; v444 < 128; v444 += 1) {	// L822
          int8_t v445 = v439[v441][v444][1][v443];	// L823
          v439[v441][v444][0][v443] = v445;	// L824
          int8_t v446 = v439[v441][v444][2][v443];	// L825
          v439[v441][v444][1][v443] = v446;	// L826
          int8_t v447 = v430[v441][v444][v442][v443];	// L827
          v439[v441][v444][2][v443] = v447;	// L828
        }
        if ((v442 - 2) >= 0) {	// L830
          for (int v448 = 0; v448 < 128; v448 += 1) {	// L831
            for (int v449 = 0; v449 < 3; v449 += 1) {	// L832
              int8_t v450 = v440[v441][v448][v449][1];	// L833
              v440[v441][v448][v449][0] = v450;	// L834
              int8_t v451 = v440[v441][v448][v449][2];	// L835
              v440[v441][v448][v449][1] = v451;	// L836
              int8_t v452 = v439[v441][v448][v449][v443];	// L837
              v440[v441][v448][v449][2] = v452;	// L838
            }
          }
          if ((v443 - 2) >= 0) {	// L841
            int8_t v453[256];	// L842
            #pragma HLS bind_storage variable=v453 type=ram_2p impl=bram

            for (int v454 = 0; v454 < 256; v454 += 1) {	// L843
              v453[v454] = (int8_t)0.000000;	// L844
              for (int v455 = 0; v455 < 32; v455 += 1) {	// L845
                #pragma HLS pipeline II=1
                for (int v456 = 0; v456 < 4; v456 += 1) {	// L846
                  for (int v457 = 0; v457 < 3; v457 += 1) {	// L847
                    for (int v458 = 0; v458 < 3; v458 += 1) {	// L848
                      int8_t v459 = v440[v441][(v456 + (v455 * 4))][v457][v458];	// L849
                      int8_t v460 = v428[v454][(v456 + (v455 * 4))][v457][v458];	// L850
                      int8_t v461 = v459 * v460;	// L851
                      int8_t v462 = v453[v454];	// L852
                      int8_t v463 = v462 + v461;	// L853
                      v453[v454] = v463;	// L854
                    }
                  }
                }
              }
              int8_t v464 = v453[v454];	// L859
              v438[v441][v454][(v442 - 2)][(v443 - 2)] = v464;	// L860
            }
          }
        }
      }
    }
  }
  for (int v465 = 0; v465 < 1; v465 += 1) {	// L867
    for (int v466 = 0; v466 < 8; v466 += 1) {	// L868
      for (int v467 = 0; v467 < 8; v467 += 1) {	// L869
        for (int v468 = 0; v468 < 256; v468 += 1) {	// L870
          int8_t v469 = v438[0][v468][v466][v467];	// L871
          bool v470 = v469 > (int8_t)0.000000;	// L872
          int8_t v471 = v470 ? v469 : (int8_t)0.000000;	// L873
          v429[v465][v468][v466][v467] = v471;	// L874
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v472[1][128][16][16],
  int8_t v473[128][128][3][3],
  int8_t v474[1][128][8][8]
) {	// L881
  #pragma HLS dataflow

  int8_t v475[1][128][18][18];	// L883
  #pragma HLS stream variable=v475 depth=10 type=fifo

  #pragma HLS bind_storage variable=v475 type=ram_t2p impl=bram

  for (int v476 = 0; v476 < 1; v476 += 1) {	// L884
    for (int v477 = 0; v477 < 18; v477 += 1) {	// L885
      for (int v478 = 0; v478 < 18; v478 += 1) {	// L886
        for (int v479 = 0; v479 < 128; v479 += 1) {	// L887
          int8_t v480;	// L888
          v480 = (int8_t)0.000000;	// L889
          if (((-v477) + 15) >= 0 && ((-v478) + 15) >= 0) {	// L890
            int8_t v481 = v472[v476][v479][v477][v478];	// L891
            v480 = v481;	// L892
          }
          int8_t v482 = v480;	// L894
          v475[v476][v479][v477][v478] = v482;	// L895
        }
      }
    }
  }
  int8_t v483[1][128][8][8];	// L900
  #pragma HLS stream variable=v483 depth=10 type=fifo

  #pragma HLS bind_storage variable=v483 type=ram_t2p impl=bram

  int8_t v484[1][128][3][18];	// L901
  #pragma HLS array_partition variable=v484 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v484 type=ram_2p impl=bram

  int8_t v485[1][128][3][3];	// L902
  #pragma HLS array_partition variable=v485 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v485 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v485 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v485 type=ram_2p impl=lutram

  for (int v486 = 0; v486 < 1; v486 += 1) {	// L903
    for (int v487 = 0; v487 < 18; v487 += 1) {	// L904
      for (int v488 = 0; v488 < 18; v488 += 1) {	// L905
        for (int v489 = 0; v489 < 128; v489 += 1) {	// L906
          int8_t v490 = v484[v486][v489][1][v488];	// L907
          v484[v486][v489][0][v488] = v490;	// L908
          int8_t v491 = v484[v486][v489][2][v488];	// L909
          v484[v486][v489][1][v488] = v491;	// L910
          int8_t v492 = v475[v486][v489][v487][v488];	// L911
          v484[v486][v489][2][v488] = v492;	// L912
        }
        if ((v487 - 10) >= 0) {	// L914
          for (int v493 = 0; v493 < 128; v493 += 1) {	// L915
            for (int v494 = 0; v494 < 3; v494 += 1) {	// L916
              int8_t v495 = v485[v486][v493][v494][1];	// L917
              v485[v486][v493][v494][0] = v495;	// L918
              int8_t v496 = v485[v486][v493][v494][2];	// L919
              v485[v486][v493][v494][1] = v496;	// L920
              int8_t v497 = v484[v486][v493][v494][v488];	// L921
              v485[v486][v493][v494][2] = v497;	// L922
            }
          }
          if ((v488 - 10) >= 0) {	// L925
            int8_t v498[128];	// L926
            #pragma HLS bind_storage variable=v498 type=ram_2p impl=bram

            for (int v499 = 0; v499 < 128; v499 += 1) {	// L927
              v498[v499] = (int8_t)0.000000;	// L928
              for (int v500 = 0; v500 < 16; v500 += 1) {	// L929
                #pragma HLS pipeline II=1
                for (int v501 = 0; v501 < 8; v501 += 1) {	// L930
                  for (int v502 = 0; v502 < 3; v502 += 1) {	// L931
                    for (int v503 = 0; v503 < 3; v503 += 1) {	// L932
                      int8_t v504 = v485[v486][(v501 + (v500 * 8))][v502][v503];	// L933
                      int8_t v505 = v473[v499][(v501 + (v500 * 8))][v502][v503];	// L934
                      int8_t v506 = v504 * v505;	// L935
                      int8_t v507 = v498[v499];	// L936
                      int8_t v508 = v507 + v506;	// L937
                      v498[v499] = v508;	// L938
                    }
                  }
                }
              }
              int8_t v509 = v498[v499];	// L943
              v483[v486][v499][(v487 - 10)][(v488 - 10)] = v509;	// L944
            }
          }
        }
      }
    }
  }
  for (int v510 = 0; v510 < 1; v510 += 1) {	// L951
    for (int v511 = 0; v511 < 8; v511 += 1) {	// L952
      for (int v512 = 0; v512 < 8; v512 += 1) {	// L953
        for (int v513 = 0; v513 < 128; v513 += 1) {	// L954
          int8_t v514 = v483[0][v513][v511][v512];	// L955
          bool v515 = v514 > (int8_t)0.000000;	// L956
          int8_t v516 = v515 ? v514 : (int8_t)0.000000;	// L957
          v474[v510][v513][v511][v512] = v516;	// L958
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v517[128][64][3][3],
  int8_t v518[1][64][16][16],
  int8_t v519[1][128][16][16]
) {	// L965
  #pragma HLS dataflow

  int8_t v520[1][64][18][18];	// L967
  #pragma HLS stream variable=v520 depth=10 type=fifo

  #pragma HLS bind_storage variable=v520 type=ram_t2p impl=bram

  for (int v521 = 0; v521 < 1; v521 += 1) {	// L968
    for (int v522 = 0; v522 < 18; v522 += 1) {	// L969
      for (int v523 = 0; v523 < 18; v523 += 1) {	// L970
        for (int v524 = 0; v524 < 64; v524 += 1) {	// L971
          int8_t v525;	// L972
          v525 = (int8_t)0.000000;	// L973
          if (((-v522) + 15) >= 0 && ((-v523) + 15) >= 0) {	// L974
            int8_t v526 = v518[v521][v524][v522][v523];	// L975
            v525 = v526;	// L976
          }
          int8_t v527 = v525;	// L978
          v520[v521][v524][v522][v523] = v527;	// L979
        }
      }
    }
  }
  int8_t v528[1][128][16][16];	// L984
  #pragma HLS stream variable=v528 depth=10 type=fifo

  #pragma HLS bind_storage variable=v528 type=ram_t2p impl=bram

  int8_t v529[1][64][3][18];	// L985
  #pragma HLS array_partition variable=v529 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v529 type=ram_2p impl=bram

  int8_t v530[1][64][3][3];	// L986
  #pragma HLS array_partition variable=v530 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v530 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v530 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v530 type=ram_2p impl=lutram

  for (int v531 = 0; v531 < 1; v531 += 1) {	// L987
    for (int v532 = 0; v532 < 18; v532 += 1) {	// L988
      for (int v533 = 0; v533 < 18; v533 += 1) {	// L989
        for (int v534 = 0; v534 < 64; v534 += 1) {	// L990
          int8_t v535 = v529[v531][v534][1][v533];	// L991
          v529[v531][v534][0][v533] = v535;	// L992
          int8_t v536 = v529[v531][v534][2][v533];	// L993
          v529[v531][v534][1][v533] = v536;	// L994
          int8_t v537 = v520[v531][v534][v532][v533];	// L995
          v529[v531][v534][2][v533] = v537;	// L996
        }
        if ((v532 - 2) >= 0) {	// L998
          for (int v538 = 0; v538 < 64; v538 += 1) {	// L999
            for (int v539 = 0; v539 < 3; v539 += 1) {	// L1000
              int8_t v540 = v530[v531][v538][v539][1];	// L1001
              v530[v531][v538][v539][0] = v540;	// L1002
              int8_t v541 = v530[v531][v538][v539][2];	// L1003
              v530[v531][v538][v539][1] = v541;	// L1004
              int8_t v542 = v529[v531][v538][v539][v533];	// L1005
              v530[v531][v538][v539][2] = v542;	// L1006
            }
          }
          if ((v533 - 2) >= 0) {	// L1009
            int8_t v543[128];	// L1010
            #pragma HLS bind_storage variable=v543 type=ram_2p impl=bram

            for (int v544 = 0; v544 < 128; v544 += 1) {	// L1011
              v543[v544] = (int8_t)0.000000;	// L1012
              for (int v545 = 0; v545 < 16; v545 += 1) {	// L1013
                #pragma HLS pipeline II=1
                for (int v546 = 0; v546 < 4; v546 += 1) {	// L1014
                  for (int v547 = 0; v547 < 3; v547 += 1) {	// L1015
                    for (int v548 = 0; v548 < 3; v548 += 1) {	// L1016
                      int8_t v549 = v530[v531][(v546 + (v545 * 4))][v547][v548];	// L1017
                      int8_t v550 = v517[v544][(v546 + (v545 * 4))][v547][v548];	// L1018
                      int8_t v551 = v549 * v550;	// L1019
                      int8_t v552 = v543[v544];	// L1020
                      int8_t v553 = v552 + v551;	// L1021
                      v543[v544] = v553;	// L1022
                    }
                  }
                }
              }
              int8_t v554 = v543[v544];	// L1027
              v528[v531][v544][(v532 - 2)][(v533 - 2)] = v554;	// L1028
            }
          }
        }
      }
    }
  }
  for (int v555 = 0; v555 < 1; v555 += 1) {	// L1035
    for (int v556 = 0; v556 < 16; v556 += 1) {	// L1036
      for (int v557 = 0; v557 < 16; v557 += 1) {	// L1037
        for (int v558 = 0; v558 < 128; v558 += 1) {	// L1038
          int8_t v559 = v528[0][v558][v556][v557];	// L1039
          bool v560 = v559 > (int8_t)0.000000;	// L1040
          int8_t v561 = v560 ? v559 : (int8_t)0.000000;	// L1041
          v519[v555][v558][v556][v557] = v561;	// L1042
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v562[1][64][32][32],
  int8_t v563[64][64][3][3],
  int8_t v564[1][64][16][16]
) {	// L1049
  #pragma HLS dataflow

  int8_t v565[1][64][34][34];	// L1051
  #pragma HLS stream variable=v565 depth=10 type=fifo

  #pragma HLS bind_storage variable=v565 type=ram_t2p impl=bram

  for (int v566 = 0; v566 < 1; v566 += 1) {	// L1052
    for (int v567 = 0; v567 < 34; v567 += 1) {	// L1053
      for (int v568 = 0; v568 < 34; v568 += 1) {	// L1054
        for (int v569 = 0; v569 < 64; v569 += 1) {	// L1055
          int8_t v570;	// L1056
          v570 = (int8_t)0.000000;	// L1057
          if (((-v567) + 31) >= 0 && ((-v568) + 31) >= 0) {	// L1058
            int8_t v571 = v562[v566][v569][v567][v568];	// L1059
            v570 = v571;	// L1060
          }
          int8_t v572 = v570;	// L1062
          v565[v566][v569][v567][v568] = v572;	// L1063
        }
      }
    }
  }
  int8_t v573[1][64][16][16];	// L1068
  #pragma HLS stream variable=v573 depth=10 type=fifo

  #pragma HLS bind_storage variable=v573 type=ram_t2p impl=bram

  int8_t v574[1][64][3][34];	// L1069
  #pragma HLS array_partition variable=v574 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v574 type=ram_2p impl=bram

  int8_t v575[1][64][3][3];	// L1070
  #pragma HLS array_partition variable=v575 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v575 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v575 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v575 type=ram_2p impl=lutram

  for (int v576 = 0; v576 < 1; v576 += 1) {	// L1071
    for (int v577 = 0; v577 < 34; v577 += 1) {	// L1072
      for (int v578 = 0; v578 < 34; v578 += 1) {	// L1073
        for (int v579 = 0; v579 < 64; v579 += 1) {	// L1074
          int8_t v580 = v574[v576][v579][1][v578];	// L1075
          v574[v576][v579][0][v578] = v580;	// L1076
          int8_t v581 = v574[v576][v579][2][v578];	// L1077
          v574[v576][v579][1][v578] = v581;	// L1078
          int8_t v582 = v565[v576][v579][v577][v578];	// L1079
          v574[v576][v579][2][v578] = v582;	// L1080
        }
        if ((v577 - 18) >= 0) {	// L1082
          for (int v583 = 0; v583 < 64; v583 += 1) {	// L1083
            for (int v584 = 0; v584 < 3; v584 += 1) {	// L1084
              int8_t v585 = v575[v576][v583][v584][1];	// L1085
              v575[v576][v583][v584][0] = v585;	// L1086
              int8_t v586 = v575[v576][v583][v584][2];	// L1087
              v575[v576][v583][v584][1] = v586;	// L1088
              int8_t v587 = v574[v576][v583][v584][v578];	// L1089
              v575[v576][v583][v584][2] = v587;	// L1090
            }
          }
          if ((v578 - 18) >= 0) {	// L1093
            int8_t v588[64];	// L1094
            #pragma HLS bind_storage variable=v588 type=ram_2p impl=bram

            for (int v589 = 0; v589 < 64; v589 += 1) {	// L1095
              v588[v589] = (int8_t)0.000000;	// L1096
              for (int v590 = 0; v590 < 8; v590 += 1) {	// L1097
                #pragma HLS pipeline II=1
                for (int v591 = 0; v591 < 8; v591 += 1) {	// L1098
                  for (int v592 = 0; v592 < 3; v592 += 1) {	// L1099
                    for (int v593 = 0; v593 < 3; v593 += 1) {	// L1100
                      int8_t v594 = v575[v576][(v591 + (v590 * 8))][v592][v593];	// L1101
                      int8_t v595 = v563[v589][(v591 + (v590 * 8))][v592][v593];	// L1102
                      int8_t v596 = v594 * v595;	// L1103
                      int8_t v597 = v588[v589];	// L1104
                      int8_t v598 = v597 + v596;	// L1105
                      v588[v589] = v598;	// L1106
                    }
                  }
                }
              }
              int8_t v599 = v588[v589];	// L1111
              v573[v576][v589][(v577 - 18)][(v578 - 18)] = v599;	// L1112
            }
          }
        }
      }
    }
  }
  for (int v600 = 0; v600 < 1; v600 += 1) {	// L1119
    for (int v601 = 0; v601 < 16; v601 += 1) {	// L1120
      for (int v602 = 0; v602 < 16; v602 += 1) {	// L1121
        for (int v603 = 0; v603 < 64; v603 += 1) {	// L1122
          int8_t v604 = v573[0][v603][v601][v602];	// L1123
          bool v605 = v604 > (int8_t)0.000000;	// L1124
          int8_t v606 = v605 ? v604 : (int8_t)0.000000;	// L1125
          v564[v600][v603][v601][v602] = v606;	// L1126
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v607[1][3][32][32],
  int8_t v608[64][3][3][3],
  int8_t v609[1][64][32][32]
) {	// L1133
  #pragma HLS dataflow

  int8_t v610[1][3][34][34];	// L1135
  #pragma HLS stream variable=v610 depth=10 type=fifo

  #pragma HLS bind_storage variable=v610 type=ram_t2p impl=bram

  for (int v611 = 0; v611 < 1; v611 += 1) {	// L1136
    for (int v612 = 0; v612 < 34; v612 += 1) {	// L1137
      for (int v613 = 0; v613 < 34; v613 += 1) {	// L1138
        for (int v614 = 0; v614 < 3; v614 += 1) {	// L1139
          int8_t v615;	// L1140
          v615 = (int8_t)0.000000;	// L1141
          if (((-v612) + 31) >= 0 && ((-v613) + 31) >= 0) {	// L1142
            int8_t v616 = v607[v611][v614][v612][v613];	// L1143
            v615 = v616;	// L1144
          }
          int8_t v617 = v615;	// L1146
          v610[v611][v614][v612][v613] = v617;	// L1147
        }
      }
    }
  }
  int8_t v618[1][64][32][32];	// L1152
  #pragma HLS stream variable=v618 depth=10 type=fifo

  #pragma HLS bind_storage variable=v618 type=ram_t2p impl=bram

  int8_t v619[1][3][3][34];	// L1153
  #pragma HLS array_partition variable=v619 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v619 type=ram_2p impl=lutram

  int8_t v620[1][3][3][3];	// L1154
  #pragma HLS array_partition variable=v620 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v620 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v620 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v620 type=ram_2p impl=lutram

  for (int v621 = 0; v621 < 1; v621 += 1) {	// L1155
    for (int v622 = 0; v622 < 34; v622 += 1) {	// L1156
      for (int v623 = 0; v623 < 34; v623 += 1) {	// L1157
        for (int v624 = 0; v624 < 3; v624 += 1) {	// L1158
          int8_t v625 = v619[v621][v624][1][v623];	// L1159
          v619[v621][v624][0][v623] = v625;	// L1160
          int8_t v626 = v619[v621][v624][2][v623];	// L1161
          v619[v621][v624][1][v623] = v626;	// L1162
          int8_t v627 = v610[v621][v624][v622][v623];	// L1163
          v619[v621][v624][2][v623] = v627;	// L1164
        }
        if ((v622 - 2) >= 0) {	// L1166
          for (int v628 = 0; v628 < 3; v628 += 1) {	// L1167
            for (int v629 = 0; v629 < 3; v629 += 1) {	// L1168
              int8_t v630 = v620[v621][v628][v629][1];	// L1169
              v620[v621][v628][v629][0] = v630;	// L1170
              int8_t v631 = v620[v621][v628][v629][2];	// L1171
              v620[v621][v628][v629][1] = v631;	// L1172
              int8_t v632 = v619[v621][v628][v629][v623];	// L1173
              v620[v621][v628][v629][2] = v632;	// L1174
            }
          }
          if ((v623 - 2) >= 0) {	// L1177
            int8_t v633[64];	// L1178
            #pragma HLS bind_storage variable=v633 type=ram_2p impl=bram

            for (int v634 = 0; v634 < 64; v634 += 1) {	// L1179
              #pragma HLS pipeline II=1
              for (int v635 = 0; v635 < 1; v635 += 1) {	// L1180
                v633[(v634 + v635)] = (int8_t)0.000000;	// L1181
                for (int v636 = 0; v636 < 3; v636 += 1) {	// L1182
                  for (int v637 = 0; v637 < 3; v637 += 1) {	// L1183
                    for (int v638 = 0; v638 < 3; v638 += 1) {	// L1184
                      int8_t v639 = v620[v621][v636][v637][v638];	// L1185
                      int8_t v640 = v608[(v634 + v635)][v636][v637][v638];	// L1186
                      int8_t v641 = v639 * v640;	// L1187
                      int8_t v642 = v633[(v634 + v635)];	// L1188
                      int8_t v643 = v642 + v641;	// L1189
                      v633[(v634 + v635)] = v643;	// L1190
                    }
                  }
                }
                int8_t v644 = v633[(v634 + v635)];	// L1194
                v618[v621][(v634 + v635)][(v622 - 2)][(v623 - 2)] = v644;	// L1195
              }
            }
          }
        }
      }
    }
  }
  for (int v645 = 0; v645 < 1; v645 += 1) {	// L1203
    for (int v646 = 0; v646 < 32; v646 += 1) {	// L1204
      for (int v647 = 0; v647 < 32; v647 += 1) {	// L1205
        for (int v648 = 0; v648 < 64; v648 += 1) {	// L1206
          int8_t v649 = v618[0][v648][v646][v647];	// L1207
          bool v650 = v649 > (int8_t)0.000000;	// L1208
          int8_t v651 = v650 ? v649 : (int8_t)0.000000;	// L1209
          v609[v645][v648][v646][v647] = v651;	// L1210
        }
      }
    }
  }
}
void load_array(
    int8_t v652[1][3][32][32],ap_uint<256> *vv652,
    int8_t v653[10],ap_uint<256> *vv653,
    int8_t v654[512][512][3][3],ap_uint<256> *vv654,
    int8_t v655[512][512][3][3],ap_uint<256> *vv655,
    int8_t v656[512][512][3][3],ap_uint<256> *vv656,
    int8_t v657[512][512][3][3],ap_uint<256> *vv657,
    int8_t v658[512][512][3][3],ap_uint<256> *vv658,
    int8_t v659[512][256][3][3],ap_uint<256> *vv659,
    int8_t v660[256][256][3][3],ap_uint<256> *vv660,
    int8_t v661[256][256][3][3],ap_uint<256> *vv661,
    int8_t v662[256][128][3][3],ap_uint<256> *vv662,
    int8_t v663[128][128][3][3],ap_uint<256> *vv663,
    int8_t v664[128][64][3][3],ap_uint<256> *vv664,
    int8_t v665[64][64][3][3],ap_uint<256> *vv665,
    int8_t v666[64][3][3][3],ap_uint<256> *vv666,
    int8_t v667[512][10],ap_uint<256> *vv667,
    int8_t v668[1][10],ap_uint<256> *vv668
) {
ap_uint<256> temp_0;
ap_uint<256> temp_1;
ap_uint<256> temp_2;
ap_uint<256> temp_3;
ap_uint<256> temp_4;
ap_uint<256> temp_5;
ap_uint<256> temp_6;
ap_uint<256> temp_7;
ap_uint<256> temp_8;
ap_uint<256> temp_9;
ap_uint<256> temp_10;
ap_uint<256> temp_11;
ap_uint<256> temp_12;
ap_uint<256> temp_13;
ap_uint<256> temp_14;
ap_uint<256> temp_15;
ap_uint<256> temp_16;
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 32; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_0 = vv652[i * 3 * 32 * 1 + j * 32 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v652[i][j][k][l * 32 + bias] = temp_0.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 1; ++i) { 
      temp_1 = vv653[i];
      for (int bias = 0; bias < 10; ++bias) { 
                    v653[i * 32 + bias] = temp_1.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_2 = vv654[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v654[i][j * 32 + bias][k][l] = temp_2.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_3 = vv655[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v655[i][j * 32 + bias][k][l] = temp_3.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_4 = vv656[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v656[i][j * 32 + bias][k][l] = temp_4.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_5 = vv657[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v657[i][j * 32 + bias][k][l] = temp_5.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_6 = vv658[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v658[i][j * 32 + bias][k][l] = temp_6.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_7 = vv659[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v659[i][j * 32 + bias][k][l] = temp_7.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_8 = vv660[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v660[i][j * 32 + bias][k][l] = temp_8.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_9 = vv661[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v661[i][j * 32 + bias][k][l] = temp_9.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_10 = vv662[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v662[i][j * 32 + bias][k][l] = temp_10.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_11 = vv663[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v663[i][j * 32 + bias][k][l] = temp_11.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_12 = vv664[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v664[i][j * 32 + bias][k][l] = temp_12.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_13 = vv665[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v665[i][j * 32 + bias][k][l] = temp_13.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_14 = vv666[i * 3 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v666[i * 32 + bias][j][k][l] = temp_14.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 10; ++j) {
          temp_15 = vv667[i * 10 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v667[i * 32 + bias][j] = temp_15.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 1; ++j) {
          temp_16 = vv668[i * 1 + j];
          for (int bias = 0; bias < 10; ++bias) { 
              v668[i][j * 32 + bias] = temp_16.range(bias*8+7, bias*8);
}
}
}
}



/// This is top function.
void main_graph(
    ap_uint<256> *vv652,
    ap_uint<256> *vv653,
    ap_uint<256> *vv654,
    ap_uint<256> *vv655,
    ap_uint<256> *vv656,
    ap_uint<256> *vv657,
    ap_uint<256> *vv658,
    ap_uint<256> *vv659,
    ap_uint<256> *vv660,
    ap_uint<256> *vv661,
    ap_uint<256> *vv662,
    ap_uint<256> *vv663,
    ap_uint<256> *vv664,
    ap_uint<256> *vv665,
    ap_uint<256> *vv666,
    ap_uint<256> *vv667,
    ap_uint<256> *vv668
) {	// L1217
  #pragma HLS interface s_axilite port=return 
  #pragma HLS INTERFACE m_axi port=vv652 offset = slave bundle=gmem0
  #pragma HLS INTERFACE m_axi port=vv653 offset = slave bundle=gmem1
  #pragma HLS INTERFACE m_axi port=vv654 offset = slave bundle=gmem2
  #pragma HLS INTERFACE m_axi port=vv655 offset = slave bundle=gmem3
  #pragma HLS INTERFACE m_axi port=vv656 offset = slave bundle=gmem4
  #pragma HLS INTERFACE m_axi port=vv657 offset = slave bundle=gmem5
  #pragma HLS INTERFACE m_axi port=vv658 offset = slave bundle=gmem6
  #pragma HLS INTERFACE m_axi port=vv659 offset = slave bundle=gmem7
  #pragma HLS INTERFACE m_axi port=vv660 offset = slave bundle=gmem8
  #pragma HLS INTERFACE m_axi port=vv661 offset = slave bundle=gmem9
  #pragma HLS INTERFACE m_axi port=vv662 offset = slave bundle=gmem10
  #pragma HLS INTERFACE m_axi port=vv663 offset = slave bundle=gmem11
  #pragma HLS INTERFACE m_axi port=vv664 offset = slave bundle=gmem12
  #pragma HLS INTERFACE m_axi port=vv665 offset = slave bundle=gmem13
  #pragma HLS INTERFACE m_axi port=vv666 offset = slave bundle=gmem14
  #pragma HLS INTERFACE m_axi port=vv667 offset = slave bundle=gmem15
  #pragma HLS INTERFACE m_axi port=vv668 offset = slave bundle=gmem16

  int8_t v652[1][3][32][32];
  int8_t v653[10];
  int8_t v654[512][512][3][3];
  int8_t v655[512][512][3][3];
  int8_t v656[512][512][3][3];
  int8_t v657[512][512][3][3];
  int8_t v658[512][512][3][3];
  int8_t v659[512][256][3][3];
  int8_t v660[256][256][3][3];
  int8_t v661[256][256][3][3];
  int8_t v662[256][128][3][3];
  int8_t v663[128][128][3][3];
  int8_t v664[128][64][3][3];
  int8_t v665[64][64][3][3];
  int8_t v666[64][3][3][3];
  int8_t v667[512][10];
  int8_t v668[1][10];
  #pragma HLS interface bram port=v652
  #pragma HLS bind_storage variable=v652 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v653
  #pragma HLS bind_storage variable=v653 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v654
  #pragma HLS array_partition variable=v654 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v654 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v654 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v654 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v655
  #pragma HLS array_partition variable=v655 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v655 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v655 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v655 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v656
  #pragma HLS array_partition variable=v656 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v656 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v656 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v656 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v657
  #pragma HLS array_partition variable=v657 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v657 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v657 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v657 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v658
  #pragma HLS array_partition variable=v658 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v658 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v658 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v658 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v659
  #pragma HLS array_partition variable=v659 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v659 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v659 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v659 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v660
  #pragma HLS array_partition variable=v660 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v660 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v660 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v660 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v661
  #pragma HLS array_partition variable=v661 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v661 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v662
  #pragma HLS array_partition variable=v662 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v662 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v662 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v662 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v663
  #pragma HLS array_partition variable=v663 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v663 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v663 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v663 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v664
  #pragma HLS array_partition variable=v664 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v664 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v664 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v664 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v665
  #pragma HLS array_partition variable=v665 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v665 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v665 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v665 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v666
  #pragma HLS array_partition variable=v666 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v666 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v666 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v666 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v667
  #pragma HLS bind_storage variable=v667 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v668
  #pragma HLS bind_storage variable=v668 type=ram_t2p impl=bram
load_array(
        v652,vv652,
        v653,vv653,
        v654,vv654,
        v655,vv655,
        v656,vv656,
        v657,vv657,
        v658,vv658,
        v659,vv659,
        v660,vv660,
        v661,vv661,
        v662,vv662,
        v663,vv663,
        v664,vv664,
        v665,vv665,
        v666,vv666,
        v667,vv667,
        v668,vv668
    );

  // #pragma HLS dataflow

  // int8_t v669[1][64][32][32];	// L1219
  // #pragma HLS stream variable=v669 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v669 type=ram_t2p impl=bram

  // main_graph_node16(v652, v666, v669);	// L1220
  // int8_t v670[1][64][16][16];	// L1221
  // #pragma HLS stream variable=v670 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v670 type=ram_t2p impl=bram

  // main_graph_node15(v669, v665, v670);	// L1222
  // int8_t v671[1][128][16][16];	// L1223
  // #pragma HLS stream variable=v671 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v671 type=ram_t2p impl=bram

  // main_graph_node14(v664, v670, v671);	// L1224
  // int8_t v672[1][128][8][8];	// L1225
  // #pragma HLS stream variable=v672 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v672 type=ram_t2p impl=bram

  // main_graph_node13(v671, v663, v672);	// L1226
  // int8_t v673[1][256][8][8];	// L1227
  // #pragma HLS stream variable=v673 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v673 type=ram_t2p impl=bram

  // main_graph_node12(v672, v662, v673);	// L1228
  // int8_t v674[1][256][8][8];	// L1229
  // #pragma HLS stream variable=v674 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v674 type=ram_t2p impl=bram

  // main_graph_node11(v661, v673, v674);	// L1230
  // int8_t v675[1][256][4][4];	// L1231
  // #pragma HLS stream variable=v675 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v675 type=ram_t2p impl=bram

  // main_graph_node10(v674, v660, v675);	// L1232
  // int8_t v676[1][512][4][4];	// L1233
  // #pragma HLS stream variable=v676 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v676 type=ram_t2p impl=bram

  // main_graph_node9(v675, v659, v676);	// L1234
  // int8_t v677[1][512][4][4];	// L1235
  // #pragma HLS stream variable=v677 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v677 type=ram_t2p impl=bram

  // main_graph_node8(v676, v658, v677);	// L1236
  // int8_t v678[1][512][2][2];	// L1237
  // #pragma HLS stream variable=v678 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v678 type=ram_t2p impl=bram

  // main_graph_node7(v677, v657, v678);	// L1238
  // int8_t v679[1][512][2][2];	// L1239
  // #pragma HLS stream variable=v679 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v679 type=ram_t2p impl=bram

  // main_graph_node6(v656, v678, v679);	// L1240
  // int8_t v680[1][512][2][2];	// L1241
  // #pragma HLS stream variable=v680 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v680 type=ram_t2p impl=bram

  // main_graph_node5(v679, v655, v680);	// L1242
  // int8_t v681[1][512][1][1];	// L1243
  // #pragma HLS stream variable=v681 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v681 type=ram_t2p impl=bram

  // main_graph_node4(v680, v654, v681);	// L1244
  // int8_t v682[1][512][2][2];	// L1245
  // #pragma HLS bind_storage variable=v682 type=ram_t2p impl=bram

  // main_graph_node3(v681, v682);	// L1246
  // int8_t v683[1][1];	// L1247
  // #pragma HLS bind_storage variable=v683 type=ram_t2p impl=bram

  // int8_t v684[1][512][1][1];	// L1248
  // #pragma HLS bind_storage variable=v684 type=ram_t2p impl=bram

  // main_graph_node2(v682, v683, v684);	// L1249
  // int8_t v685[1][512][1][1];	// L1250
  // #pragma HLS bind_storage variable=v685 type=ram_t2p impl=bram

  // main_graph_node1(v684, v683, v685);	// L1251
  // main_graph_node0(v685, v653, v667, v668);	// L1252
}

