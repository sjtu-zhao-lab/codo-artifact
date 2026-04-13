
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
  int8_t v0[512][10],
  int8_t v1[1][512][1][1],
  int8_t v2[10],
  int8_t v3[1][10]
) {	// L14
  #pragma HLS dataflow

  int8_t v4[1][10];	// L16
  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  int8_t v5[1][10];	// L17
  #pragma HLS bind_storage variable=v5 type=ram_t2p impl=bram

  for (int v6 = 0; v6 < 1; v6 += 1) {	// L18
    for (int v7 = 0; v7 < 10; v7 += 1) {	// L19
      v4[v6][v7] = (int8_t)0.000000;	// L20
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L23
    for (int v9 = 0; v9 < 10; v9 += 1) {	// L24
      for (int v10 = 0; v10 < 512; v10 += 1) {	// L25
        int8_t v11 = v1[v8][v10][0][0];	// L26
        int8_t v12 = v0[v10][v9];	// L27
        int8_t v13 = v4[v8][v9];	// L28
        int8_t v14 = v11 * v12;	// L29
        int8_t v15 = v13 + v14;	// L30
        v5[v8][v9] = v15;	// L31
      }
    }
  }
  for (int v16 = 0; v16 < 1; v16 += 1) {	// L35
    for (int v17 = 0; v17 < 10; v17 += 1) {	// L36
      int8_t v18 = v5[0][v17];	// L37
      int8_t v19 = v2[v17];	// L38
      int8_t v20 = v18 + v19;	// L39
      v3[v16][v17] = v20;	// L40
    }
  }
}

void main_graph_node1(
  int8_t v21[1][512][1][1],
  int8_t v22[1][1],
  int8_t v23[1][512][1][1]
) {	// L45
  #pragma HLS dataflow

  int8_t v24[1][512][1][1];	// L46
  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L47
    for (int v26 = 0; v26 < 512; v26 += 1) {	// L48
      for (int v27 = 0; v27 < 1; v27 += 1) {	// L49
        for (int v28 = 0; v28 < 1; v28 += 1) {	// L50
          int8_t v29 = v21[v25][v26][v27][v28];	// L51
          v24[v25][v26][v27][v28] = v29;	// L52
          int8_t v30 = v22[v27][v28];	// L53
          int8_t v31 = v24[v25][v26][v27][v28];	// L54
          int8_t v32 = v31 / v30;	// L55
          v23[v25][v26][v27][v28] = v32;	// L56
        }
      }
    }
  }
}

void main_graph_node2(
  int8_t v33[1][512][5][5],
  int8_t v34[1][512][1][1],
  int8_t v35[1][1]
) {	// L63
  #pragma HLS dataflow

  int8_t v36[1][512][1][1];	// L67
  #pragma HLS bind_storage variable=v36 type=ram_t2p impl=bram

  for (int v37 = 0; v37 < 1; v37 += 1) {	// L68
    for (int v38 = 0; v38 < 512; v38 += 1) {	// L69
      for (int v39 = 0; v39 < 1; v39 += 1) {	// L70
        for (int v40 = 0; v40 < 1; v40 += 1) {	// L71
          v36[v37][v38][v39][v40] = (int8_t)0.000000;	// L72
        }
      }
    }
  }
  for (int v41 = 0; v41 < 1; v41 += 1) {	// L77
    for (int v42 = 0; v42 < 512; v42 += 1) {	// L78
      for (int v43 = 0; v43 < 1; v43 += 1) {	// L79
        for (int v44 = 0; v44 < 1; v44 += 1) {	// L80
          for (int v45 = 0; v45 < 4; v45 += 1) {	// L81
            for (int v46 = 0; v46 < 4; v46 += 1) {	// L82
              int8_t v47 = v36[v41][v42][v43][v44];	// L83
              int v48 = v43 * (int)4;	// L84
              int v49 = v43 + (int)1;	// L85
              int v50 = v49 * (int)4;	// L86
              int v51 = v44 * (int)4;	// L87
              int v52 = v44 + (int)1;	// L88
              int v53 = v52 * (int)4;	// L89
              int v54 = v48 + v45;	// L90
              int v55 = v51 + v46;	// L91
              int8_t v56 = v33[v41][v42][v54][v55];	// L92
              bool v57 = v54 < v50;	// L93
              int8_t v58 = v57 ? v56 : (int8_t)0.000000;	// L94
              bool v59 = v55 < v53;	// L95
              int8_t v60 = v59 ? v58 : (int8_t)0.000000;	// L96
              int8_t v61 = v60 + v47;	// L97
              int v62 = v50 - v48;	// L98
              int v63 = v53 - v51;	// L99
              int v64 = v62 * v63;	// L100
              ap_int<64> v65 = v64;	// L101
              int8_t v66 = v65;	// L102
              v34[v41][v42][v43][v44] = v61;	// L103
              v35[v41][v42] = v66;	// L104
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v67[1][512][4][4],
  int8_t v68[1][512][5][5]
) {	// L113
  #pragma HLS dataflow

  for (int v69 = 0; v69 < 1; v69 += 1) {	// L115
    for (int v70 = 0; v70 < 5; v70 += 1) {	// L116
      for (int v71 = 0; v71 < 5; v71 += 1) {	// L117
        for (int v72 = 0; v72 < 512; v72 += 1) {	// L118
          int8_t v73;	// L119
          v73 = (int8_t)0.000000;	// L120
          if (((-v70) + 3) >= 0 && ((-v71) + 3) >= 0) {	// L121
            int8_t v74 = v67[v69][v72][v70][v71];	// L122
            v73 = v74;	// L123
          }
          int8_t v75 = v73;	// L125
          v68[v69][v72][v70][v71] = v75;	// L126
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v76[1][512][4][4],
  int8_t v77[1][512][4][4],
  int8_t v78[512][512][3][3],
  int8_t v79[1][512][4][4]
) {	// L133
  #pragma HLS dataflow

  int8_t v80[1][512][6][6];	// L135
  #pragma HLS stream variable=v80 depth=10 type=fifo

  #pragma HLS bind_storage variable=v80 type=ram_t2p impl=bram

  for (int v81 = 0; v81 < 1; v81 += 1) {	// L136
    for (int v82 = 0; v82 < 6; v82 += 1) {	// L137
      for (int v83 = 0; v83 < 6; v83 += 1) {	// L138
        for (int v84 = 0; v84 < 512; v84 += 1) {	// L139
          int8_t v85;	// L140
          v85 = (int8_t)0.000000;	// L141
          if (((-v82) + 3) >= 0 && ((-v83) + 3) >= 0) {	// L142
            int8_t v86 = v77[v81][v84][v82][v83];	// L143
            v85 = v86;	// L144
          }
          int8_t v87 = v85;	// L146
          v80[v81][v84][v82][v83] = v87;	// L147
        }
      }
    }
  }
  int8_t v88[1][512][4][4];	// L152
  #pragma HLS stream variable=v88 depth=10 type=fifo

  #pragma HLS bind_storage variable=v88 type=ram_t2p impl=bram

  int8_t v89[1][512][3][6];	// L153
  #pragma HLS array_partition variable=v89 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v89 type=ram_2p impl=bram

  int8_t v90[1][512][3][3];	// L154
  #pragma HLS array_partition variable=v90 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v90 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v90 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v90 type=ram_2p impl=lutram

  for (int v91 = 0; v91 < 1; v91 += 1) {	// L155
    for (int v92 = 0; v92 < 6; v92 += 1) {	// L156
      for (int v93 = 0; v93 < 6; v93 += 1) {	// L157
        for (int v94 = 0; v94 < 512; v94 += 1) {	// L158
          int8_t v95 = v89[v91][v94][1][v93];	// L159
          v89[v91][v94][0][v93] = v95;	// L160
          int8_t v96 = v89[v91][v94][2][v93];	// L161
          v89[v91][v94][1][v93] = v96;	// L162
          int8_t v97 = v80[v91][v94][v92][v93];	// L163
          v89[v91][v94][2][v93] = v97;	// L164
        }
        if ((v92 - 2) >= 0) {	// L166
          for (int v98 = 0; v98 < 512; v98 += 1) {	// L167
            for (int v99 = 0; v99 < 3; v99 += 1) {	// L168
              int8_t v100 = v90[v91][v98][v99][1];	// L169
              v90[v91][v98][v99][0] = v100;	// L170
              int8_t v101 = v90[v91][v98][v99][2];	// L171
              v90[v91][v98][v99][1] = v101;	// L172
              int8_t v102 = v89[v91][v98][v99][v93];	// L173
              v90[v91][v98][v99][2] = v102;	// L174
            }
          }
          if ((v93 - 2) >= 0) {	// L177
            int8_t v103[512];	// L178
            #pragma HLS bind_storage variable=v103 type=ram_2p impl=bram

            for (int v104 = 0; v104 < 512; v104 += 1) {	// L179
              v103[v104] = (int8_t)0.000000;	// L180
              for (int v105 = 0; v105 < 64; v105 += 1) {	// L181
                #pragma HLS pipeline II=1
                for (int v106 = 0; v106 < 8; v106 += 1) {	// L182
                  for (int v107 = 0; v107 < 3; v107 += 1) {	// L183
                    for (int v108 = 0; v108 < 3; v108 += 1) {	// L184
                      int8_t v109 = v90[v91][(v106 + (v105 * 8))][v107][v108];	// L185
                      int8_t v110 = v78[v104][(v106 + (v105 * 8))][v107][v108];	// L186
                      int8_t v111 = v109 * v110;	// L187
                      int8_t v112 = v103[v104];	// L188
                      int8_t v113 = v112 + v111;	// L189
                      v103[v104] = v113;	// L190
                    }
                  }
                }
              }
              int8_t v114 = v103[v104];	// L195
              v88[v91][v104][(v92 - 2)][(v93 - 2)] = v114;	// L196
            }
          }
        }
      }
    }
  }
  for (int v115 = 0; v115 < 1; v115 += 1) {	// L203
    for (int v116 = 0; v116 < 4; v116 += 1) {	// L204
      for (int v117 = 0; v117 < 4; v117 += 1) {	// L205
        for (int v118 = 0; v118 < 512; v118 += 1) {	// L206
          int8_t v119 = v88[0][v118][v116][v117];	// L207
          int8_t v120 = v76[0][v118][v116][v117];	// L208
          int8_t v121 = v119 + v120;	// L209
          bool v122 = v121 > (int8_t)0.000000;	// L210
          int8_t v123 = v122 ? v121 : (int8_t)0.000000;	// L211
          v79[v115][v118][v116][v117] = v123;	// L212
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v124[1][512][4][4],
  int8_t v125[512][512][3][3],
  int8_t v126[1][512][4][4]
) {	// L219
  #pragma HLS dataflow

  int8_t v127[1][512][6][6];	// L221
  #pragma HLS stream variable=v127 depth=10 type=fifo

  #pragma HLS bind_storage variable=v127 type=ram_t2p impl=bram

  for (int v128 = 0; v128 < 1; v128 += 1) {	// L222
    for (int v129 = 0; v129 < 6; v129 += 1) {	// L223
      for (int v130 = 0; v130 < 6; v130 += 1) {	// L224
        for (int v131 = 0; v131 < 512; v131 += 1) {	// L225
          int8_t v132;	// L226
          v132 = (int8_t)0.000000;	// L227
          if (((-v129) + 3) >= 0 && ((-v130) + 3) >= 0) {	// L228
            int8_t v133 = v124[v128][v131][v129][v130];	// L229
            v132 = v133;	// L230
          }
          int8_t v134 = v132;	// L232
          v127[v128][v131][v129][v130] = v134;	// L233
        }
      }
    }
  }
  int8_t v135[1][512][4][4];	// L238
  #pragma HLS stream variable=v135 depth=10 type=fifo

  #pragma HLS bind_storage variable=v135 type=ram_t2p impl=bram

  int8_t v136[1][512][3][6];	// L239
  #pragma HLS array_partition variable=v136 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v136 type=ram_2p impl=bram

  int8_t v137[1][512][3][3];	// L240
  #pragma HLS array_partition variable=v137 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v137 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v137 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v137 type=ram_2p impl=lutram

  for (int v138 = 0; v138 < 1; v138 += 1) {	// L241
    for (int v139 = 0; v139 < 6; v139 += 1) {	// L242
      for (int v140 = 0; v140 < 6; v140 += 1) {	// L243
        for (int v141 = 0; v141 < 512; v141 += 1) {	// L244
          int8_t v142 = v136[v138][v141][1][v140];	// L245
          v136[v138][v141][0][v140] = v142;	// L246
          int8_t v143 = v136[v138][v141][2][v140];	// L247
          v136[v138][v141][1][v140] = v143;	// L248
          int8_t v144 = v127[v138][v141][v139][v140];	// L249
          v136[v138][v141][2][v140] = v144;	// L250
        }
        if ((v139 - 2) >= 0) {	// L252
          for (int v145 = 0; v145 < 512; v145 += 1) {	// L253
            for (int v146 = 0; v146 < 3; v146 += 1) {	// L254
              int8_t v147 = v137[v138][v145][v146][1];	// L255
              v137[v138][v145][v146][0] = v147;	// L256
              int8_t v148 = v137[v138][v145][v146][2];	// L257
              v137[v138][v145][v146][1] = v148;	// L258
              int8_t v149 = v136[v138][v145][v146][v140];	// L259
              v137[v138][v145][v146][2] = v149;	// L260
            }
          }
          if ((v140 - 2) >= 0) {	// L263
            int8_t v150[512];	// L264
            #pragma HLS bind_storage variable=v150 type=ram_2p impl=bram

            for (int v151 = 0; v151 < 512; v151 += 1) {	// L265
              v150[v151] = (int8_t)0.000000;	// L266
              for (int v152 = 0; v152 < 64; v152 += 1) {	// L267
                #pragma HLS pipeline II=1
                for (int v153 = 0; v153 < 8; v153 += 1) {	// L268
                  for (int v154 = 0; v154 < 3; v154 += 1) {	// L269
                    for (int v155 = 0; v155 < 3; v155 += 1) {	// L270
                      int8_t v156 = v137[v138][(v153 + (v152 * 8))][v154][v155];	// L271
                      int8_t v157 = v125[v151][(v153 + (v152 * 8))][v154][v155];	// L272
                      int8_t v158 = v156 * v157;	// L273
                      int8_t v159 = v150[v151];	// L274
                      int8_t v160 = v159 + v158;	// L275
                      v150[v151] = v160;	// L276
                    }
                  }
                }
              }
              int8_t v161 = v150[v151];	// L281
              v135[v138][v151][(v139 - 2)][(v140 - 2)] = v161;	// L282
            }
          }
        }
      }
    }
  }
  for (int v162 = 0; v162 < 1; v162 += 1) {	// L289
    for (int v163 = 0; v163 < 4; v163 += 1) {	// L290
      for (int v164 = 0; v164 < 4; v164 += 1) {	// L291
        for (int v165 = 0; v165 < 512; v165 += 1) {	// L292
          int8_t v166 = v135[0][v165][v163][v164];	// L293
          bool v167 = v166 > (int8_t)0.000000;	// L294
          int8_t v168 = v167 ? v166 : (int8_t)0.000000;	// L295
          v126[v162][v165][v163][v164] = v168;	// L296
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v169[1][512][4][4],
  int8_t v170[1][512][4][4],
  int8_t v171[1][512][4][4]
) {	// L303
  #pragma HLS dataflow

  for (int v172 = 0; v172 < 1; v172 += 1) {	// L304
    for (int v173 = 0; v173 < 4; v173 += 1) {	// L305
      for (int v174 = 0; v174 < 4; v174 += 1) {	// L306
        for (int v175 = 0; v175 < 512; v175 += 1) {	// L307
          int8_t temp = v169[v172][v175][v173][v174];	// L308
          v170[v172][v175][v173][v174] = temp;	// L309
          int8_t v177 = temp;	// L310
          v171[v172][v175][v173][v174] = v177;	// L311
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v178[1][256][8][8],
  int8_t v179[512][256][1][1],
  int8_t v180[1][512][4][4],
  int8_t v181[1][512][4][4]
) {	// L318
  #pragma HLS dataflow

  int8_t v182[1][512][4][4];	// L320
  #pragma HLS stream variable=v182 depth=10 type=fifo

  #pragma HLS bind_storage variable=v182 type=ram_t2p impl=bram

  int8_t v183[1][256][1][8];	// L321
  #pragma HLS bind_storage variable=v183 type=ram_2p impl=bram

  int8_t v184[1][256][1][1];	// L322
  #pragma HLS array_partition variable=v184 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v184 type=ram_2p impl=lutram

  for (int v185 = 0; v185 < 1; v185 += 1) {	// L323
    for (int v186 = 0; v186 < 8; v186 += 1) {	// L324
      for (int v187 = 0; v187 < 8; v187 += 1) {	// L325
        for (int v188 = 0; v188 < 256; v188 += 1) {	// L326
          int8_t v189 = v178[v185][v188][v186][v187];	// L327
          v183[v185][v188][0][v187] = v189;	// L328
        }
        if ((v186 - 4) >= 0) {	// L330
          for (int v190 = 0; v190 < 256; v190 += 1) {	// L331
            for (int v191 = 0; v191 < 1; v191 += 1) {	// L332
              int8_t v192 = v183[v185][v190][v191][v187];	// L333
              v184[v185][v190][v191][0] = v192;	// L334
            }
          }
          if ((v187 - 4) >= 0) {	// L337
            int8_t v193[512];	// L338
            #pragma HLS bind_storage variable=v193 type=ram_2p impl=bram

            for (int v194 = 0; v194 < 512; v194 += 1) {	// L339
              v193[v194] = (int8_t)0.000000;	// L340
              for (int v195 = 0; v195 < 32; v195 += 1) {	// L341
                #pragma HLS pipeline II=1
                for (int v196 = 0; v196 < 8; v196 += 1) {	// L342
                  for (int v197 = 0; v197 < 1; v197 += 1) {	// L343
                    for (int v198 = 0; v198 < 1; v198 += 1) {	// L344
                      int8_t v199 = v184[v185][(v196 + (v195 * 8))][v197][v198];	// L345
                      int8_t v200 = v179[v194][(v196 + (v195 * 8))][v197][v198];	// L346
                      int8_t v201 = v199 * v200;	// L347
                      int8_t v202 = v193[v194];	// L348
                      int8_t v203 = v202 + v201;	// L349
                      v193[v194] = v203;	// L350
                    }
                  }
                }
              }
              int8_t v204 = v193[v194];	// L355
              v182[v185][v194][(v186 - 4)][(v187 - 4)] = v204;	// L356
            }
          }
        }
      }
    }
  }
  for (int v205 = 0; v205 < 1; v205 += 1) {	// L363
    for (int v206 = 0; v206 < 4; v206 += 1) {	// L364
      for (int v207 = 0; v207 < 4; v207 += 1) {	// L365
        for (int v208 = 0; v208 < 512; v208 += 1) {	// L366
          int8_t v209 = v180[0][v208][v206][v207];	// L367
          int8_t v210 = v182[0][v208][v206][v207];	// L368
          int8_t v211 = v209 + v210;	// L369
          bool v212 = v211 > (int8_t)0.000000;	// L370
          int8_t v213 = v212 ? v211 : (int8_t)0.000000;	// L371
          v181[v205][v208][v206][v207] = v213;	// L372
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v214[1][512][4][4],
  int8_t v215[512][512][3][3],
  int8_t v216[1][512][4][4]
) {	// L379
  #pragma HLS dataflow

  int8_t v217[1][512][6][6];	// L381
  #pragma HLS stream variable=v217 depth=10 type=fifo

  #pragma HLS bind_storage variable=v217 type=ram_t2p impl=bram

  for (int v218 = 0; v218 < 1; v218 += 1) {	// L382
    for (int v219 = 0; v219 < 6; v219 += 1) {	// L383
      for (int v220 = 0; v220 < 6; v220 += 1) {	// L384
        for (int v221 = 0; v221 < 512; v221 += 1) {	// L385
          int8_t v222;	// L386
          v222 = (int8_t)0.000000;	// L387
          if (((-v219) + 3) >= 0 && ((-v220) + 3) >= 0) {	// L388
            int8_t v223 = v214[v218][v221][v219][v220];	// L389
            v222 = v223;	// L390
          }
          int8_t v224 = v222;	// L392
          v217[v218][v221][v219][v220] = v224;	// L393
        }
      }
    }
  }
  int8_t v225[1][512][3][6];	// L398
  #pragma HLS array_partition variable=v225 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v225 type=ram_2p impl=bram

  int8_t v226[1][512][3][3];	// L399
  #pragma HLS array_partition variable=v226 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v226 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v226 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v226 type=ram_2p impl=lutram

  for (int v227 = 0; v227 < 1; v227 += 1) {	// L400
    for (int v228 = 0; v228 < 6; v228 += 1) {	// L401
      for (int v229 = 0; v229 < 6; v229 += 1) {	// L402
        for (int v230 = 0; v230 < 512; v230 += 1) {	// L403
          int8_t v231 = v225[v227][v230][1][v229];	// L404
          v225[v227][v230][0][v229] = v231;	// L405
          int8_t v232 = v225[v227][v230][2][v229];	// L406
          v225[v227][v230][1][v229] = v232;	// L407
          int8_t v233 = v217[v227][v230][v228][v229];	// L408
          v225[v227][v230][2][v229] = v233;	// L409
        }
        if ((v228 - 2) >= 0) {	// L411
          for (int v234 = 0; v234 < 512; v234 += 1) {	// L412
            for (int v235 = 0; v235 < 3; v235 += 1) {	// L413
              int8_t v236 = v226[v227][v234][v235][1];	// L414
              v226[v227][v234][v235][0] = v236;	// L415
              int8_t v237 = v226[v227][v234][v235][2];	// L416
              v226[v227][v234][v235][1] = v237;	// L417
              int8_t v238 = v225[v227][v234][v235][v229];	// L418
              v226[v227][v234][v235][2] = v238;	// L419
            }
          }
          if ((v229 - 2) >= 0) {	// L422
            int8_t v239[512];	// L423
            #pragma HLS bind_storage variable=v239 type=ram_2p impl=bram

            for (int v240 = 0; v240 < 512; v240 += 1) {	// L424
              v239[v240] = (int8_t)0.000000;	// L425
              for (int v241 = 0; v241 < 64; v241 += 1) {	// L426
                #pragma HLS pipeline II=1
                for (int v242 = 0; v242 < 8; v242 += 1) {	// L427
                  for (int v243 = 0; v243 < 3; v243 += 1) {	// L428
                    for (int v244 = 0; v244 < 3; v244 += 1) {	// L429
                      int8_t v245 = v226[v227][(v242 + (v241 * 8))][v243][v244];	// L430
                      int8_t v246 = v215[v240][(v242 + (v241 * 8))][v243][v244];	// L431
                      int8_t v247 = v245 * v246;	// L432
                      int8_t v248 = v239[v240];	// L433
                      int8_t v249 = v248 + v247;	// L434
                      v239[v240] = v249;	// L435
                    }
                  }
                }
              }
              int8_t v250 = v239[v240];	// L440
              v216[v227][v240][(v228 - 2)][(v229 - 2)] = v250;	// L441
            }
          }
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v251[1][256][8][8],
  int8_t v252[512][256][3][3],
  int8_t v253[1][512][4][4]
) {	// L450
  #pragma HLS dataflow

  int8_t v254[1][256][10][10];	// L452
  #pragma HLS stream variable=v254 depth=10 type=fifo

  #pragma HLS bind_storage variable=v254 type=ram_t2p impl=bram

  for (int v255 = 0; v255 < 1; v255 += 1) {	// L453
    for (int v256 = 0; v256 < 10; v256 += 1) {	// L454
      for (int v257 = 0; v257 < 10; v257 += 1) {	// L455
        for (int v258 = 0; v258 < 256; v258 += 1) {	// L456
          int8_t v259;	// L457
          v259 = (int8_t)0.000000;	// L458
          if (((-v256) + 7) >= 0 && ((-v257) + 7) >= 0) {	// L459
            int8_t v260 = v251[v255][v258][v256][v257];	// L460
            v259 = v260;	// L461
          }
          int8_t v261 = v259;	// L463
          v254[v255][v258][v256][v257] = v261;	// L464
        }
      }
    }
  }
  int8_t v262[1][512][4][4];	// L469
  #pragma HLS stream variable=v262 depth=10 type=fifo

  #pragma HLS bind_storage variable=v262 type=ram_t2p impl=bram

  int8_t v263[1][256][3][10];	// L470
  #pragma HLS array_partition variable=v263 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v263 type=ram_2p impl=bram

  int8_t v264[1][256][3][3];	// L471
  #pragma HLS array_partition variable=v264 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v264 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v264 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v264 type=ram_2p impl=lutram

  for (int v265 = 0; v265 < 1; v265 += 1) {	// L472
    for (int v266 = 0; v266 < 10; v266 += 1) {	// L473
      for (int v267 = 0; v267 < 10; v267 += 1) {	// L474
        for (int v268 = 0; v268 < 256; v268 += 1) {	// L475
          int8_t v269 = v263[v265][v268][1][v267];	// L476
          v263[v265][v268][0][v267] = v269;	// L477
          int8_t v270 = v263[v265][v268][2][v267];	// L478
          v263[v265][v268][1][v267] = v270;	// L479
          int8_t v271 = v254[v265][v268][v266][v267];	// L480
          v263[v265][v268][2][v267] = v271;	// L481
        }
        if ((v266 - 6) >= 0) {	// L483
          for (int v272 = 0; v272 < 256; v272 += 1) {	// L484
            for (int v273 = 0; v273 < 3; v273 += 1) {	// L485
              int8_t v274 = v264[v265][v272][v273][1];	// L486
              v264[v265][v272][v273][0] = v274;	// L487
              int8_t v275 = v264[v265][v272][v273][2];	// L488
              v264[v265][v272][v273][1] = v275;	// L489
              int8_t v276 = v263[v265][v272][v273][v267];	// L490
              v264[v265][v272][v273][2] = v276;	// L491
            }
          }
          if ((v267 - 6) >= 0) {	// L494
            int8_t v277[512];	// L495
            #pragma HLS bind_storage variable=v277 type=ram_2p impl=bram

            for (int v278 = 0; v278 < 512; v278 += 1) {	// L496
              v277[v278] = (int8_t)0.000000;	// L497
              for (int v279 = 0; v279 < 32; v279 += 1) {	// L498
                #pragma HLS pipeline II=1
                for (int v280 = 0; v280 < 8; v280 += 1) {	// L499
                  for (int v281 = 0; v281 < 3; v281 += 1) {	// L500
                    for (int v282 = 0; v282 < 3; v282 += 1) {	// L501
                      int8_t v283 = v264[v265][(v280 + (v279 * 8))][v281][v282];	// L502
                      int8_t v284 = v252[v278][(v280 + (v279 * 8))][v281][v282];	// L503
                      int8_t v285 = v283 * v284;	// L504
                      int8_t v286 = v277[v278];	// L505
                      int8_t v287 = v286 + v285;	// L506
                      v277[v278] = v287;	// L507
                    }
                  }
                }
              }
              int8_t v288 = v277[v278];	// L512
              v262[v265][v278][(v266 - 6)][(v267 - 6)] = v288;	// L513
            }
          }
        }
      }
    }
  }
  for (int v289 = 0; v289 < 1; v289 += 1) {	// L520
    for (int v290 = 0; v290 < 4; v290 += 1) {	// L521
      for (int v291 = 0; v291 < 4; v291 += 1) {	// L522
        for (int v292 = 0; v292 < 512; v292 += 1) {	// L523
          int8_t v293 = v262[0][v292][v290][v291];	// L524
          bool v294 = v293 > (int8_t)0.000000;	// L525
          int8_t v295 = v294 ? v293 : (int8_t)0.000000;	// L526
          v253[v289][v292][v290][v291] = v295;	// L527
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v296[1][256][8][8],
  int8_t v297[1][256][8][8],
  int8_t v298[1][256][8][8]
) {	// L534
  #pragma HLS dataflow

  for (int v299 = 0; v299 < 1; v299 += 1) {	// L535
    for (int v300 = 0; v300 < 8; v300 += 1) {	// L536
      for (int v301 = 0; v301 < 8; v301 += 1) {	// L537
        for (int v302 = 0; v302 < 256; v302 += 1) {	// L538
          int8_t temp = v296[v299][v302][v300][v301];	// L539
          v297[v299][v302][v300][v301] = temp;	// L540
          int8_t v304 = temp;	// L541
          v298[v299][v302][v300][v301] = v304;	// L542
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v305[1][256][8][8],
  int8_t v306[256][256][3][3],
  int8_t v307[1][256][8][8],
  int8_t v308[1][256][8][8]
) {	// L549
  #pragma HLS dataflow

  int8_t v309[1][256][10][10];	// L551
  #pragma HLS stream variable=v309 depth=10 type=fifo

  #pragma HLS bind_storage variable=v309 type=ram_t2p impl=bram

  for (int v310 = 0; v310 < 1; v310 += 1) {	// L552
    for (int v311 = 0; v311 < 10; v311 += 1) {	// L553
      for (int v312 = 0; v312 < 10; v312 += 1) {	// L554
        for (int v313 = 0; v313 < 256; v313 += 1) {	// L555
          int8_t v314;	// L556
          v314 = (int8_t)0.000000;	// L557
          if (((-v311) + 7) >= 0 && ((-v312) + 7) >= 0) {	// L558
            int8_t v315 = v307[v310][v313][v311][v312];	// L559
            v314 = v315;	// L560
          }
          int8_t v316 = v314;	// L562
          v309[v310][v313][v311][v312] = v316;	// L563
        }
      }
    }
  }
  int8_t v317[1][256][8][8];	// L568
  #pragma HLS stream variable=v317 depth=10 type=fifo

  #pragma HLS bind_storage variable=v317 type=ram_t2p impl=bram

  int8_t v318[1][256][3][10];	// L569
  #pragma HLS array_partition variable=v318 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v318 type=ram_2p impl=bram

  int8_t v319[1][256][3][3];	// L570
  #pragma HLS array_partition variable=v319 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v319 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v319 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v319 type=ram_2p impl=lutram

  for (int v320 = 0; v320 < 1; v320 += 1) {	// L571
    for (int v321 = 0; v321 < 10; v321 += 1) {	// L572
      for (int v322 = 0; v322 < 10; v322 += 1) {	// L573
        for (int v323 = 0; v323 < 256; v323 += 1) {	// L574
          int8_t v324 = v318[v320][v323][1][v322];	// L575
          v318[v320][v323][0][v322] = v324;	// L576
          int8_t v325 = v318[v320][v323][2][v322];	// L577
          v318[v320][v323][1][v322] = v325;	// L578
          int8_t v326 = v309[v320][v323][v321][v322];	// L579
          v318[v320][v323][2][v322] = v326;	// L580
        }
        if ((v321 - 2) >= 0) {	// L582
          for (int v327 = 0; v327 < 256; v327 += 1) {	// L583
            for (int v328 = 0; v328 < 3; v328 += 1) {	// L584
              int8_t v329 = v319[v320][v327][v328][1];	// L585
              v319[v320][v327][v328][0] = v329;	// L586
              int8_t v330 = v319[v320][v327][v328][2];	// L587
              v319[v320][v327][v328][1] = v330;	// L588
              int8_t v331 = v318[v320][v327][v328][v322];	// L589
              v319[v320][v327][v328][2] = v331;	// L590
            }
          }
          if ((v322 - 2) >= 0) {	// L593
            int8_t v332[256];	// L594
            #pragma HLS bind_storage variable=v332 type=ram_2p impl=bram

            for (int v333 = 0; v333 < 256; v333 += 1) {	// L595
              v332[v333] = (int8_t)0.000000;	// L596
              for (int v334 = 0; v334 < 64; v334 += 1) {	// L597
                #pragma HLS pipeline II=1
                for (int v335 = 0; v335 < 4; v335 += 1) {	// L598
                  for (int v336 = 0; v336 < 3; v336 += 1) {	// L599
                    for (int v337 = 0; v337 < 3; v337 += 1) {	// L600
                      int8_t v338 = v319[v320][(v335 + (v334 * 4))][v336][v337];	// L601
                      int8_t v339 = v306[v333][(v335 + (v334 * 4))][v336][v337];	// L602
                      int8_t v340 = v338 * v339;	// L603
                      int8_t v341 = v332[v333];	// L604
                      int8_t v342 = v341 + v340;	// L605
                      v332[v333] = v342;	// L606
                    }
                  }
                }
              }
              int8_t v343 = v332[v333];	// L611
              v317[v320][v333][(v321 - 2)][(v322 - 2)] = v343;	// L612
            }
          }
        }
      }
    }
  }
  for (int v344 = 0; v344 < 1; v344 += 1) {	// L619
    for (int v345 = 0; v345 < 8; v345 += 1) {	// L620
      for (int v346 = 0; v346 < 8; v346 += 1) {	// L621
        for (int v347 = 0; v347 < 256; v347 += 1) {	// L622
          int8_t v348 = v317[0][v347][v345][v346];	// L623
          int8_t v349 = v305[0][v347][v345][v346];	// L624
          int8_t v350 = v348 + v349;	// L625
          bool v351 = v350 > (int8_t)0.000000;	// L626
          int8_t v352 = v351 ? v350 : (int8_t)0.000000;	// L627
          v308[v344][v347][v345][v346] = v352;	// L628
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v353[256][256][3][3],
  int8_t v354[1][256][8][8],
  int8_t v355[1][256][8][8]
) {	// L635
  #pragma HLS dataflow

  int8_t v356[1][256][10][10];	// L637
  #pragma HLS stream variable=v356 depth=10 type=fifo

  #pragma HLS bind_storage variable=v356 type=ram_t2p impl=bram

  for (int v357 = 0; v357 < 1; v357 += 1) {	// L638
    for (int v358 = 0; v358 < 10; v358 += 1) {	// L639
      for (int v359 = 0; v359 < 10; v359 += 1) {	// L640
        for (int v360 = 0; v360 < 256; v360 += 1) {	// L641
          int8_t v361;	// L642
          v361 = (int8_t)0.000000;	// L643
          if (((-v358) + 7) >= 0 && ((-v359) + 7) >= 0) {	// L644
            int8_t v362 = v354[v357][v360][v358][v359];	// L645
            v361 = v362;	// L646
          }
          int8_t v363 = v361;	// L648
          v356[v357][v360][v358][v359] = v363;	// L649
        }
      }
    }
  }
  int8_t v364[1][256][8][8];	// L654
  #pragma HLS stream variable=v364 depth=10 type=fifo

  #pragma HLS bind_storage variable=v364 type=ram_t2p impl=bram

  int8_t v365[1][256][3][10];	// L655
  #pragma HLS array_partition variable=v365 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v365 type=ram_2p impl=bram

  int8_t v366[1][256][3][3];	// L656
  #pragma HLS array_partition variable=v366 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v366 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v366 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v366 type=ram_2p impl=lutram

  for (int v367 = 0; v367 < 1; v367 += 1) {	// L657
    for (int v368 = 0; v368 < 10; v368 += 1) {	// L658
      for (int v369 = 0; v369 < 10; v369 += 1) {	// L659
        for (int v370 = 0; v370 < 256; v370 += 1) {	// L660
          int8_t v371 = v365[v367][v370][1][v369];	// L661
          v365[v367][v370][0][v369] = v371;	// L662
          int8_t v372 = v365[v367][v370][2][v369];	// L663
          v365[v367][v370][1][v369] = v372;	// L664
          int8_t v373 = v356[v367][v370][v368][v369];	// L665
          v365[v367][v370][2][v369] = v373;	// L666
        }
        if ((v368 - 2) >= 0) {	// L668
          for (int v374 = 0; v374 < 256; v374 += 1) {	// L669
            for (int v375 = 0; v375 < 3; v375 += 1) {	// L670
              int8_t v376 = v366[v367][v374][v375][1];	// L671
              v366[v367][v374][v375][0] = v376;	// L672
              int8_t v377 = v366[v367][v374][v375][2];	// L673
              v366[v367][v374][v375][1] = v377;	// L674
              int8_t v378 = v365[v367][v374][v375][v369];	// L675
              v366[v367][v374][v375][2] = v378;	// L676
            }
          }
          if ((v369 - 2) >= 0) {	// L679
            int8_t v379[256];	// L680
            #pragma HLS bind_storage variable=v379 type=ram_2p impl=bram

            for (int v380 = 0; v380 < 256; v380 += 1) {	// L681
              v379[v380] = (int8_t)0.000000;	// L682
              for (int v381 = 0; v381 < 64; v381 += 1) {	// L683
                #pragma HLS pipeline II=1
                for (int v382 = 0; v382 < 4; v382 += 1) {	// L684
                  for (int v383 = 0; v383 < 3; v383 += 1) {	// L685
                    for (int v384 = 0; v384 < 3; v384 += 1) {	// L686
                      int8_t v385 = v366[v367][(v382 + (v381 * 4))][v383][v384];	// L687
                      int8_t v386 = v353[v380][(v382 + (v381 * 4))][v383][v384];	// L688
                      int8_t v387 = v385 * v386;	// L689
                      int8_t v388 = v379[v380];	// L690
                      int8_t v389 = v388 + v387;	// L691
                      v379[v380] = v389;	// L692
                    }
                  }
                }
              }
              int8_t v390 = v379[v380];	// L697
              v364[v367][v380][(v368 - 2)][(v369 - 2)] = v390;	// L698
            }
          }
        }
      }
    }
  }
  for (int v391 = 0; v391 < 1; v391 += 1) {	// L705
    for (int v392 = 0; v392 < 8; v392 += 1) {	// L706
      for (int v393 = 0; v393 < 8; v393 += 1) {	// L707
        for (int v394 = 0; v394 < 256; v394 += 1) {	// L708
          int8_t v395 = v364[0][v394][v392][v393];	// L709
          bool v396 = v395 > (int8_t)0.000000;	// L710
          int8_t v397 = v396 ? v395 : (int8_t)0.000000;	// L711
          v355[v391][v394][v392][v393] = v397;	// L712
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v398[1][256][8][8],
  int8_t v399[1][256][8][8],
  int8_t v400[1][256][8][8]
) {	// L719
  #pragma HLS dataflow

  for (int v401 = 0; v401 < 1; v401 += 1) {	// L720
    for (int v402 = 0; v402 < 8; v402 += 1) {	// L721
      for (int v403 = 0; v403 < 8; v403 += 1) {	// L722
        for (int v404 = 0; v404 < 256; v404 += 1) {	// L723
          int8_t temp = v398[v401][v404][v402][v403];	// L724
          v399[v401][v404][v402][v403] = temp;	// L725
          int8_t v406 = temp;	// L726
          v400[v401][v404][v402][v403] = v406;	// L727
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v407[256][128][1][1],
  int8_t v408[1][128][16][16],
  int8_t v409[1][256][8][8],
  int8_t v410[1][256][8][8]
) {	// L734
  #pragma HLS dataflow

  int8_t v411[1][256][8][8];	// L736
  #pragma HLS stream variable=v411 depth=10 type=fifo

  #pragma HLS bind_storage variable=v411 type=ram_t2p impl=bram

  int8_t v412[1][128][1][16];	// L737
  #pragma HLS bind_storage variable=v412 type=ram_2p impl=bram

  int8_t v413[1][128][1][1];	// L738
  #pragma HLS array_partition variable=v413 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v413 type=ram_2p impl=lutram

  for (int v414 = 0; v414 < 1; v414 += 1) {	// L739
    for (int v415 = 0; v415 < 16; v415 += 1) {	// L740
      for (int v416 = 0; v416 < 16; v416 += 1) {	// L741
        for (int v417 = 0; v417 < 128; v417 += 1) {	// L742
          int8_t v418 = v408[v414][v417][v415][v416];	// L743
          v412[v414][v417][0][v416] = v418;	// L744
        }
        if ((v415 - 8) >= 0) {	// L746
          for (int v419 = 0; v419 < 128; v419 += 1) {	// L747
            for (int v420 = 0; v420 < 1; v420 += 1) {	// L748
              int8_t v421 = v412[v414][v419][v420][v416];	// L749
              v413[v414][v419][v420][0] = v421;	// L750
            }
          }
          if ((v416 - 8) >= 0) {	// L753
            int8_t v422[256];	// L754
            #pragma HLS bind_storage variable=v422 type=ram_2p impl=bram

            for (int v423 = 0; v423 < 256; v423 += 1) {	// L755
              v422[v423] = (int8_t)0.000000;	// L756
              for (int v424 = 0; v424 < 16; v424 += 1) {	// L757
                #pragma HLS pipeline II=1
                for (int v425 = 0; v425 < 8; v425 += 1) {	// L758
                  for (int v426 = 0; v426 < 1; v426 += 1) {	// L759
                    for (int v427 = 0; v427 < 1; v427 += 1) {	// L760
                      int8_t v428 = v413[v414][(v425 + (v424 * 8))][v426][v427];	// L761
                      int8_t v429 = v407[v423][(v425 + (v424 * 8))][v426][v427];	// L762
                      int8_t v430 = v428 * v429;	// L763
                      int8_t v431 = v422[v423];	// L764
                      int8_t v432 = v431 + v430;	// L765
                      v422[v423] = v432;	// L766
                    }
                  }
                }
              }
              int8_t v433 = v422[v423];	// L771
              v411[v414][v423][(v415 - 8)][(v416 - 8)] = v433;	// L772
            }
          }
        }
      }
    }
  }
  for (int v434 = 0; v434 < 1; v434 += 1) {	// L779
    for (int v435 = 0; v435 < 8; v435 += 1) {	// L780
      for (int v436 = 0; v436 < 8; v436 += 1) {	// L781
        for (int v437 = 0; v437 < 256; v437 += 1) {	// L782
          int8_t v438 = v409[0][v437][v435][v436];	// L783
          int8_t v439 = v411[0][v437][v435][v436];	// L784
          int8_t v440 = v438 + v439;	// L785
          bool v441 = v440 > (int8_t)0.000000;	// L786
          int8_t v442 = v441 ? v440 : (int8_t)0.000000;	// L787
          v410[v434][v437][v435][v436] = v442;	// L788
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v443[1][256][8][8],
  int8_t v444[256][256][3][3],
  int8_t v445[1][256][8][8]
) {	// L795
  #pragma HLS dataflow

  int8_t v446[1][256][10][10];	// L797
  #pragma HLS stream variable=v446 depth=10 type=fifo

  #pragma HLS bind_storage variable=v446 type=ram_t2p impl=bram

  for (int v447 = 0; v447 < 1; v447 += 1) {	// L798
    for (int v448 = 0; v448 < 10; v448 += 1) {	// L799
      for (int v449 = 0; v449 < 10; v449 += 1) {	// L800
        for (int v450 = 0; v450 < 256; v450 += 1) {	// L801
          int8_t v451;	// L802
          v451 = (int8_t)0.000000;	// L803
          if (((-v448) + 7) >= 0 && ((-v449) + 7) >= 0) {	// L804
            int8_t v452 = v443[v447][v450][v448][v449];	// L805
            v451 = v452;	// L806
          }
          int8_t v453 = v451;	// L808
          v446[v447][v450][v448][v449] = v453;	// L809
        }
      }
    }
  }
  int8_t v454[1][256][3][10];	// L814
  #pragma HLS array_partition variable=v454 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v454 type=ram_2p impl=bram

  int8_t v455[1][256][3][3];	// L815
  #pragma HLS array_partition variable=v455 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v455 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v455 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v455 type=ram_2p impl=lutram

  for (int v456 = 0; v456 < 1; v456 += 1) {	// L816
    for (int v457 = 0; v457 < 10; v457 += 1) {	// L817
      for (int v458 = 0; v458 < 10; v458 += 1) {	// L818
        for (int v459 = 0; v459 < 256; v459 += 1) {	// L819
          int8_t v460 = v454[v456][v459][1][v458];	// L820
          v454[v456][v459][0][v458] = v460;	// L821
          int8_t v461 = v454[v456][v459][2][v458];	// L822
          v454[v456][v459][1][v458] = v461;	// L823
          int8_t v462 = v446[v456][v459][v457][v458];	// L824
          v454[v456][v459][2][v458] = v462;	// L825
        }
        if ((v457 - 2) >= 0) {	// L827
          for (int v463 = 0; v463 < 256; v463 += 1) {	// L828
            for (int v464 = 0; v464 < 3; v464 += 1) {	// L829
              int8_t v465 = v455[v456][v463][v464][1];	// L830
              v455[v456][v463][v464][0] = v465;	// L831
              int8_t v466 = v455[v456][v463][v464][2];	// L832
              v455[v456][v463][v464][1] = v466;	// L833
              int8_t v467 = v454[v456][v463][v464][v458];	// L834
              v455[v456][v463][v464][2] = v467;	// L835
            }
          }
          if ((v458 - 2) >= 0) {	// L838
            int8_t v468[256];	// L839
            #pragma HLS bind_storage variable=v468 type=ram_2p impl=bram

            for (int v469 = 0; v469 < 256; v469 += 1) {	// L840
              v468[v469] = (int8_t)0.000000;	// L841
              for (int v470 = 0; v470 < 64; v470 += 1) {	// L842
                #pragma HLS pipeline II=1
                for (int v471 = 0; v471 < 4; v471 += 1) {	// L843
                  for (int v472 = 0; v472 < 3; v472 += 1) {	// L844
                    for (int v473 = 0; v473 < 3; v473 += 1) {	// L845
                      int8_t v474 = v455[v456][(v471 + (v470 * 4))][v472][v473];	// L846
                      int8_t v475 = v444[v469][(v471 + (v470 * 4))][v472][v473];	// L847
                      int8_t v476 = v474 * v475;	// L848
                      int8_t v477 = v468[v469];	// L849
                      int8_t v478 = v477 + v476;	// L850
                      v468[v469] = v478;	// L851
                    }
                  }
                }
              }
              int8_t v479 = v468[v469];	// L856
              v445[v456][v469][(v457 - 2)][(v458 - 2)] = v479;	// L857
            }
          }
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v480[256][128][3][3],
  int8_t v481[1][128][16][16],
  int8_t v482[1][256][8][8]
) {	// L866
  #pragma HLS dataflow

  int8_t v483[1][128][18][18];	// L868
  #pragma HLS stream variable=v483 depth=10 type=fifo

  #pragma HLS bind_storage variable=v483 type=ram_t2p impl=bram

  for (int v484 = 0; v484 < 1; v484 += 1) {	// L869
    for (int v485 = 0; v485 < 18; v485 += 1) {	// L870
      for (int v486 = 0; v486 < 18; v486 += 1) {	// L871
        for (int v487 = 0; v487 < 128; v487 += 1) {	// L872
          int8_t v488;	// L873
          v488 = (int8_t)0.000000;	// L874
          if (((-v485) + 15) >= 0 && ((-v486) + 15) >= 0) {	// L875
            int8_t v489 = v481[v484][v487][v485][v486];	// L876
            v488 = v489;	// L877
          }
          int8_t v490 = v488;	// L879
          v483[v484][v487][v485][v486] = v490;	// L880
        }
      }
    }
  }
  int8_t v491[1][256][8][8];	// L885
  #pragma HLS stream variable=v491 depth=10 type=fifo

  #pragma HLS bind_storage variable=v491 type=ram_t2p impl=bram

  int8_t v492[1][128][3][18];	// L886
  #pragma HLS array_partition variable=v492 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v492 type=ram_2p impl=bram

  int8_t v493[1][128][3][3];	// L887
  #pragma HLS array_partition variable=v493 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v493 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v493 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v493 type=ram_2p impl=lutram

  for (int v494 = 0; v494 < 1; v494 += 1) {	// L888
    for (int v495 = 0; v495 < 18; v495 += 1) {	// L889
      for (int v496 = 0; v496 < 18; v496 += 1) {	// L890
        for (int v497 = 0; v497 < 128; v497 += 1) {	// L891
          int8_t v498 = v492[v494][v497][1][v496];	// L892
          v492[v494][v497][0][v496] = v498;	// L893
          int8_t v499 = v492[v494][v497][2][v496];	// L894
          v492[v494][v497][1][v496] = v499;	// L895
          int8_t v500 = v483[v494][v497][v495][v496];	// L896
          v492[v494][v497][2][v496] = v500;	// L897
        }
        if ((v495 - 10) >= 0) {	// L899
          for (int v501 = 0; v501 < 128; v501 += 1) {	// L900
            for (int v502 = 0; v502 < 3; v502 += 1) {	// L901
              int8_t v503 = v493[v494][v501][v502][1];	// L902
              v493[v494][v501][v502][0] = v503;	// L903
              int8_t v504 = v493[v494][v501][v502][2];	// L904
              v493[v494][v501][v502][1] = v504;	// L905
              int8_t v505 = v492[v494][v501][v502][v496];	// L906
              v493[v494][v501][v502][2] = v505;	// L907
            }
          }
          if ((v496 - 10) >= 0) {	// L910
            int8_t v506[256];	// L911
            #pragma HLS bind_storage variable=v506 type=ram_2p impl=bram

            for (int v507 = 0; v507 < 256; v507 += 1) {	// L912
              v506[v507] = (int8_t)0.000000;	// L913
              for (int v508 = 0; v508 < 16; v508 += 1) {	// L914
                #pragma HLS pipeline II=1
                for (int v509 = 0; v509 < 8; v509 += 1) {	// L915
                  for (int v510 = 0; v510 < 3; v510 += 1) {	// L916
                    for (int v511 = 0; v511 < 3; v511 += 1) {	// L917
                      int8_t v512 = v493[v494][(v509 + (v508 * 8))][v510][v511];	// L918
                      int8_t v513 = v480[v507][(v509 + (v508 * 8))][v510][v511];	// L919
                      int8_t v514 = v512 * v513;	// L920
                      int8_t v515 = v506[v507];	// L921
                      int8_t v516 = v515 + v514;	// L922
                      v506[v507] = v516;	// L923
                    }
                  }
                }
              }
              int8_t v517 = v506[v507];	// L928
              v491[v494][v507][(v495 - 10)][(v496 - 10)] = v517;	// L929
            }
          }
        }
      }
    }
  }
  for (int v518 = 0; v518 < 1; v518 += 1) {	// L936
    for (int v519 = 0; v519 < 8; v519 += 1) {	// L937
      for (int v520 = 0; v520 < 8; v520 += 1) {	// L938
        for (int v521 = 0; v521 < 256; v521 += 1) {	// L939
          int8_t v522 = v491[0][v521][v519][v520];	// L940
          bool v523 = v522 > (int8_t)0.000000;	// L941
          int8_t v524 = v523 ? v522 : (int8_t)0.000000;	// L942
          v482[v518][v521][v519][v520] = v524;	// L943
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v525[1][128][16][16],
  int8_t v526[1][128][16][16],
  int8_t v527[1][128][16][16]
) {	// L950
  #pragma HLS dataflow

  for (int v528 = 0; v528 < 1; v528 += 1) {	// L951
    for (int v529 = 0; v529 < 16; v529 += 1) {	// L952
      for (int v530 = 0; v530 < 16; v530 += 1) {	// L953
        for (int v531 = 0; v531 < 128; v531 += 1) {	// L954
          int8_t temp = v525[v528][v531][v529][v530];	// L955
          v526[v528][v531][v529][v530] = temp;	// L956
          int8_t v533 = temp;	// L957
          v527[v528][v531][v529][v530] = v533;	// L958
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v534[1][128][16][16],
  int8_t v535[128][128][3][3],
  int8_t v536[1][128][16][16],
  int8_t v537[1][128][16][16]
) {	// L965
  #pragma HLS dataflow

  int8_t v538[1][128][18][18];	// L967
  #pragma HLS stream variable=v538 depth=10 type=fifo

  #pragma HLS bind_storage variable=v538 type=ram_t2p impl=bram

  for (int v539 = 0; v539 < 1; v539 += 1) {	// L968
    for (int v540 = 0; v540 < 18; v540 += 1) {	// L969
      for (int v541 = 0; v541 < 18; v541 += 1) {	// L970
        for (int v542 = 0; v542 < 128; v542 += 1) {	// L971
          int8_t v543;	// L972
          v543 = (int8_t)0.000000;	// L973
          if (((-v540) + 15) >= 0 && ((-v541) + 15) >= 0) {	// L974
            int8_t v544 = v534[v539][v542][v540][v541];	// L975
            v543 = v544;	// L976
          }
          int8_t v545 = v543;	// L978
          v538[v539][v542][v540][v541] = v545;	// L979
        }
      }
    }
  }
  int8_t v546[1][128][16][16];	// L984
  #pragma HLS stream variable=v546 depth=10 type=fifo

  #pragma HLS bind_storage variable=v546 type=ram_t2p impl=bram

  int8_t v547[1][128][3][18];	// L985
  #pragma HLS array_partition variable=v547 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v547 type=ram_2p impl=bram

  int8_t v548[1][128][3][3];	// L986
  #pragma HLS array_partition variable=v548 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v548 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v548 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v548 type=ram_2p impl=lutram

  for (int v549 = 0; v549 < 1; v549 += 1) {	// L987
    for (int v550 = 0; v550 < 18; v550 += 1) {	// L988
      for (int v551 = 0; v551 < 18; v551 += 1) {	// L989
        for (int v552 = 0; v552 < 128; v552 += 1) {	// L990
          int8_t v553 = v547[v549][v552][1][v551];	// L991
          v547[v549][v552][0][v551] = v553;	// L992
          int8_t v554 = v547[v549][v552][2][v551];	// L993
          v547[v549][v552][1][v551] = v554;	// L994
          int8_t v555 = v538[v549][v552][v550][v551];	// L995
          v547[v549][v552][2][v551] = v555;	// L996
        }
        if ((v550 - 2) >= 0) {	// L998
          for (int v556 = 0; v556 < 128; v556 += 1) {	// L999
            for (int v557 = 0; v557 < 3; v557 += 1) {	// L1000
              int8_t v558 = v548[v549][v556][v557][1];	// L1001
              v548[v549][v556][v557][0] = v558;	// L1002
              int8_t v559 = v548[v549][v556][v557][2];	// L1003
              v548[v549][v556][v557][1] = v559;	// L1004
              int8_t v560 = v547[v549][v556][v557][v551];	// L1005
              v548[v549][v556][v557][2] = v560;	// L1006
            }
          }
          if ((v551 - 2) >= 0) {	// L1009
            int8_t v561[128];	// L1010
            #pragma HLS bind_storage variable=v561 type=ram_2p impl=bram

            for (int v562 = 0; v562 < 128; v562 += 1) {	// L1011
              v561[v562] = (int8_t)0.000000;	// L1012
              for (int v563 = 0; v563 < 32; v563 += 1) {	// L1013
                #pragma HLS pipeline II=1
                for (int v564 = 0; v564 < 4; v564 += 1) {	// L1014
                  for (int v565 = 0; v565 < 3; v565 += 1) {	// L1015
                    for (int v566 = 0; v566 < 3; v566 += 1) {	// L1016
                      int8_t v567 = v548[v549][(v564 + (v563 * 4))][v565][v566];	// L1017
                      int8_t v568 = v535[v562][(v564 + (v563 * 4))][v565][v566];	// L1018
                      int8_t v569 = v567 * v568;	// L1019
                      int8_t v570 = v561[v562];	// L1020
                      int8_t v571 = v570 + v569;	// L1021
                      v561[v562] = v571;	// L1022
                    }
                  }
                }
              }
              int8_t v572 = v561[v562];	// L1027
              v546[v549][v562][(v550 - 2)][(v551 - 2)] = v572;	// L1028
            }
          }
        }
      }
    }
  }
  for (int v573 = 0; v573 < 1; v573 += 1) {	// L1035
    for (int v574 = 0; v574 < 16; v574 += 1) {	// L1036
      for (int v575 = 0; v575 < 16; v575 += 1) {	// L1037
        for (int v576 = 0; v576 < 128; v576 += 1) {	// L1038
          int8_t v577 = v546[0][v576][v574][v575];	// L1039
          int8_t v578 = v536[0][v576][v574][v575];	// L1040
          int8_t v579 = v577 + v578;	// L1041
          bool v580 = v579 > (int8_t)0.000000;	// L1042
          int8_t v581 = v580 ? v579 : (int8_t)0.000000;	// L1043
          v537[v573][v576][v574][v575] = v581;	// L1044
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v582[128][128][3][3],
  int8_t v583[1][128][16][16],
  int8_t v584[1][128][16][16]
) {	// L1051
  #pragma HLS dataflow

  int8_t v585[1][128][18][18];	// L1053
  #pragma HLS stream variable=v585 depth=10 type=fifo

  #pragma HLS bind_storage variable=v585 type=ram_t2p impl=bram

  for (int v586 = 0; v586 < 1; v586 += 1) {	// L1054
    for (int v587 = 0; v587 < 18; v587 += 1) {	// L1055
      for (int v588 = 0; v588 < 18; v588 += 1) {	// L1056
        for (int v589 = 0; v589 < 128; v589 += 1) {	// L1057
          int8_t v590;	// L1058
          v590 = (int8_t)0.000000;	// L1059
          if (((-v587) + 15) >= 0 && ((-v588) + 15) >= 0) {	// L1060
            int8_t v591 = v583[v586][v589][v587][v588];	// L1061
            v590 = v591;	// L1062
          }
          int8_t v592 = v590;	// L1064
          v585[v586][v589][v587][v588] = v592;	// L1065
        }
      }
    }
  }
  int8_t v593[1][128][16][16];	// L1070
  #pragma HLS stream variable=v593 depth=10 type=fifo

  #pragma HLS bind_storage variable=v593 type=ram_t2p impl=bram

  int8_t v594[1][128][3][18];	// L1071
  #pragma HLS array_partition variable=v594 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v594 type=ram_2p impl=bram

  int8_t v595[1][128][3][3];	// L1072
  #pragma HLS array_partition variable=v595 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v595 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v595 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v595 type=ram_2p impl=lutram

  for (int v596 = 0; v596 < 1; v596 += 1) {	// L1073
    for (int v597 = 0; v597 < 18; v597 += 1) {	// L1074
      for (int v598 = 0; v598 < 18; v598 += 1) {	// L1075
        for (int v599 = 0; v599 < 128; v599 += 1) {	// L1076
          int8_t v600 = v594[v596][v599][1][v598];	// L1077
          v594[v596][v599][0][v598] = v600;	// L1078
          int8_t v601 = v594[v596][v599][2][v598];	// L1079
          v594[v596][v599][1][v598] = v601;	// L1080
          int8_t v602 = v585[v596][v599][v597][v598];	// L1081
          v594[v596][v599][2][v598] = v602;	// L1082
        }
        if ((v597 - 2) >= 0) {	// L1084
          for (int v603 = 0; v603 < 128; v603 += 1) {	// L1085
            for (int v604 = 0; v604 < 3; v604 += 1) {	// L1086
              int8_t v605 = v595[v596][v603][v604][1];	// L1087
              v595[v596][v603][v604][0] = v605;	// L1088
              int8_t v606 = v595[v596][v603][v604][2];	// L1089
              v595[v596][v603][v604][1] = v606;	// L1090
              int8_t v607 = v594[v596][v603][v604][v598];	// L1091
              v595[v596][v603][v604][2] = v607;	// L1092
            }
          }
          if ((v598 - 2) >= 0) {	// L1095
            int8_t v608[128];	// L1096
            #pragma HLS bind_storage variable=v608 type=ram_2p impl=bram

            for (int v609 = 0; v609 < 128; v609 += 1) {	// L1097
              v608[v609] = (int8_t)0.000000;	// L1098
              for (int v610 = 0; v610 < 32; v610 += 1) {	// L1099
                #pragma HLS pipeline II=1
                for (int v611 = 0; v611 < 4; v611 += 1) {	// L1100
                  for (int v612 = 0; v612 < 3; v612 += 1) {	// L1101
                    for (int v613 = 0; v613 < 3; v613 += 1) {	// L1102
                      int8_t v614 = v595[v596][(v611 + (v610 * 4))][v612][v613];	// L1103
                      int8_t v615 = v582[v609][(v611 + (v610 * 4))][v612][v613];	// L1104
                      int8_t v616 = v614 * v615;	// L1105
                      int8_t v617 = v608[v609];	// L1106
                      int8_t v618 = v617 + v616;	// L1107
                      v608[v609] = v618;	// L1108
                    }
                  }
                }
              }
              int8_t v619 = v608[v609];	// L1113
              v593[v596][v609][(v597 - 2)][(v598 - 2)] = v619;	// L1114
            }
          }
        }
      }
    }
  }
  for (int v620 = 0; v620 < 1; v620 += 1) {	// L1121
    for (int v621 = 0; v621 < 16; v621 += 1) {	// L1122
      for (int v622 = 0; v622 < 16; v622 += 1) {	// L1123
        for (int v623 = 0; v623 < 128; v623 += 1) {	// L1124
          int8_t v624 = v593[0][v623][v621][v622];	// L1125
          bool v625 = v624 > (int8_t)0.000000;	// L1126
          int8_t v626 = v625 ? v624 : (int8_t)0.000000;	// L1127
          v584[v620][v623][v621][v622] = v626;	// L1128
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v627[1][128][16][16],
  int8_t v628[1][128][16][16],
  int8_t v629[1][128][16][16]
) {	// L1135
  #pragma HLS dataflow

  for (int v630 = 0; v630 < 1; v630 += 1) {	// L1136
    for (int v631 = 0; v631 < 16; v631 += 1) {	// L1137
      for (int v632 = 0; v632 < 16; v632 += 1) {	// L1138
        for (int v633 = 0; v633 < 128; v633 += 1) {	// L1139
          int8_t temp = v627[v630][v633][v631][v632];	// L1140
          v628[v630][v633][v631][v632] = temp;	// L1141
          int8_t v635 = temp;	// L1142
          v629[v630][v633][v631][v632] = v635;	// L1143
        }
      }
    }
  }
}

void main_graph_node21(
  int8_t v636[1][64][32][32],
  int8_t v637[128][64][1][1],
  int8_t v638[1][128][16][16],
  int8_t v639[1][128][16][16]
) {	// L1150
  #pragma HLS dataflow

  int8_t v640[1][128][16][16];	// L1152
  #pragma HLS stream variable=v640 depth=10 type=fifo

  #pragma HLS bind_storage variable=v640 type=ram_t2p impl=bram

  int8_t v641[1][64][1][32];	// L1153
  #pragma HLS bind_storage variable=v641 type=ram_2p impl=bram

  int8_t v642[1][64][1][1];	// L1154
  #pragma HLS array_partition variable=v642 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v642 type=ram_2p impl=lutram

  for (int v643 = 0; v643 < 1; v643 += 1) {	// L1155
    for (int v644 = 0; v644 < 32; v644 += 1) {	// L1156
      for (int v645 = 0; v645 < 32; v645 += 1) {	// L1157
        for (int v646 = 0; v646 < 64; v646 += 1) {	// L1158
          int8_t v647 = v636[v643][v646][v644][v645];	// L1159
          v641[v643][v646][0][v645] = v647;	// L1160
        }
        if ((v644 - 16) >= 0) {	// L1162
          for (int v648 = 0; v648 < 64; v648 += 1) {	// L1163
            for (int v649 = 0; v649 < 1; v649 += 1) {	// L1164
              int8_t v650 = v641[v643][v648][v649][v645];	// L1165
              v642[v643][v648][v649][0] = v650;	// L1166
            }
          }
          if ((v645 - 16) >= 0) {	// L1169
            int8_t v651[128];	// L1170
            #pragma HLS bind_storage variable=v651 type=ram_2p impl=bram

            for (int v652 = 0; v652 < 128; v652 += 1) {	// L1171
              v651[v652] = (int8_t)0.000000;	// L1172
              for (int v653 = 0; v653 < 8; v653 += 1) {	// L1173
                #pragma HLS pipeline II=1
                for (int v654 = 0; v654 < 8; v654 += 1) {	// L1174
                  for (int v655 = 0; v655 < 1; v655 += 1) {	// L1175
                    for (int v656 = 0; v656 < 1; v656 += 1) {	// L1176
                      int8_t v657 = v642[v643][(v654 + (v653 * 8))][v655][v656];	// L1177
                      int8_t v658 = v637[v652][(v654 + (v653 * 8))][v655][v656];	// L1178
                      int8_t v659 = v657 * v658;	// L1179
                      int8_t v660 = v651[v652];	// L1180
                      int8_t v661 = v660 + v659;	// L1181
                      v651[v652] = v661;	// L1182
                    }
                  }
                }
              }
              int8_t v662 = v651[v652];	// L1187
              v640[v643][v652][(v644 - 16)][(v645 - 16)] = v662;	// L1188
            }
          }
        }
      }
    }
  }
  for (int v663 = 0; v663 < 1; v663 += 1) {	// L1195
    for (int v664 = 0; v664 < 16; v664 += 1) {	// L1196
      for (int v665 = 0; v665 < 16; v665 += 1) {	// L1197
        for (int v666 = 0; v666 < 128; v666 += 1) {	// L1198
          int8_t v667 = v638[0][v666][v664][v665];	// L1199
          int8_t v668 = v640[0][v666][v664][v665];	// L1200
          int8_t v669 = v667 + v668;	// L1201
          bool v670 = v669 > (int8_t)0.000000;	// L1202
          int8_t v671 = v670 ? v669 : (int8_t)0.000000;	// L1203
          v639[v663][v666][v664][v665] = v671;	// L1204
        }
      }
    }
  }
}

void main_graph_node22(
  int8_t v672[1][128][16][16],
  int8_t v673[128][128][3][3],
  int8_t v674[1][128][16][16]
) {	// L1211
  #pragma HLS dataflow

  int8_t v675[1][128][18][18];	// L1213
  #pragma HLS stream variable=v675 depth=10 type=fifo

  #pragma HLS bind_storage variable=v675 type=ram_t2p impl=bram

  for (int v676 = 0; v676 < 1; v676 += 1) {	// L1214
    for (int v677 = 0; v677 < 18; v677 += 1) {	// L1215
      for (int v678 = 0; v678 < 18; v678 += 1) {	// L1216
        for (int v679 = 0; v679 < 128; v679 += 1) {	// L1217
          int8_t v680;	// L1218
          v680 = (int8_t)0.000000;	// L1219
          if (((-v677) + 15) >= 0 && ((-v678) + 15) >= 0) {	// L1220
            int8_t v681 = v672[v676][v679][v677][v678];	// L1221
            v680 = v681;	// L1222
          }
          int8_t v682 = v680;	// L1224
          v675[v676][v679][v677][v678] = v682;	// L1225
        }
      }
    }
  }
  int8_t v683[1][128][3][18];	// L1230
  #pragma HLS array_partition variable=v683 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v683 type=ram_2p impl=bram

  int8_t v684[1][128][3][3];	// L1231
  #pragma HLS array_partition variable=v684 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v684 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v684 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v684 type=ram_2p impl=lutram

  for (int v685 = 0; v685 < 1; v685 += 1) {	// L1232
    for (int v686 = 0; v686 < 18; v686 += 1) {	// L1233
      for (int v687 = 0; v687 < 18; v687 += 1) {	// L1234
        for (int v688 = 0; v688 < 128; v688 += 1) {	// L1235
          int8_t v689 = v683[v685][v688][1][v687];	// L1236
          v683[v685][v688][0][v687] = v689;	// L1237
          int8_t v690 = v683[v685][v688][2][v687];	// L1238
          v683[v685][v688][1][v687] = v690;	// L1239
          int8_t v691 = v675[v685][v688][v686][v687];	// L1240
          v683[v685][v688][2][v687] = v691;	// L1241
        }
        if ((v686 - 2) >= 0) {	// L1243
          for (int v692 = 0; v692 < 128; v692 += 1) {	// L1244
            for (int v693 = 0; v693 < 3; v693 += 1) {	// L1245
              int8_t v694 = v684[v685][v692][v693][1];	// L1246
              v684[v685][v692][v693][0] = v694;	// L1247
              int8_t v695 = v684[v685][v692][v693][2];	// L1248
              v684[v685][v692][v693][1] = v695;	// L1249
              int8_t v696 = v683[v685][v692][v693][v687];	// L1250
              v684[v685][v692][v693][2] = v696;	// L1251
            }
          }
          if ((v687 - 2) >= 0) {	// L1254
            int8_t v697[128];	// L1255
            #pragma HLS bind_storage variable=v697 type=ram_2p impl=bram

            for (int v698 = 0; v698 < 128; v698 += 1) {	// L1256
              v697[v698] = (int8_t)0.000000;	// L1257
              for (int v699 = 0; v699 < 32; v699 += 1) {	// L1258
                #pragma HLS pipeline II=1
                for (int v700 = 0; v700 < 4; v700 += 1) {	// L1259
                  for (int v701 = 0; v701 < 3; v701 += 1) {	// L1260
                    for (int v702 = 0; v702 < 3; v702 += 1) {	// L1261
                      int8_t v703 = v684[v685][(v700 + (v699 * 4))][v701][v702];	// L1262
                      int8_t v704 = v673[v698][(v700 + (v699 * 4))][v701][v702];	// L1263
                      int8_t v705 = v703 * v704;	// L1264
                      int8_t v706 = v697[v698];	// L1265
                      int8_t v707 = v706 + v705;	// L1266
                      v697[v698] = v707;	// L1267
                    }
                  }
                }
              }
              int8_t v708 = v697[v698];	// L1272
              v674[v685][v698][(v686 - 2)][(v687 - 2)] = v708;	// L1273
            }
          }
        }
      }
    }
  }
}

void main_graph_node23(
  int8_t v709[1][64][32][32],
  int8_t v710[128][64][3][3],
  int8_t v711[1][128][16][16]
) {	// L1282
  #pragma HLS dataflow

  int8_t v712[1][64][34][34];	// L1284
  #pragma HLS stream variable=v712 depth=10 type=fifo

  #pragma HLS bind_storage variable=v712 type=ram_t2p impl=bram

  for (int v713 = 0; v713 < 1; v713 += 1) {	// L1285
    for (int v714 = 0; v714 < 34; v714 += 1) {	// L1286
      for (int v715 = 0; v715 < 34; v715 += 1) {	// L1287
        for (int v716 = 0; v716 < 64; v716 += 1) {	// L1288
          int8_t v717;	// L1289
          v717 = (int8_t)0.000000;	// L1290
          if (((-v714) + 31) >= 0 && ((-v715) + 31) >= 0) {	// L1291
            int8_t v718 = v709[v713][v716][v714][v715];	// L1292
            v717 = v718;	// L1293
          }
          int8_t v719 = v717;	// L1295
          v712[v713][v716][v714][v715] = v719;	// L1296
        }
      }
    }
  }
  int8_t v720[1][128][16][16];	// L1301
  #pragma HLS stream variable=v720 depth=10 type=fifo

  #pragma HLS bind_storage variable=v720 type=ram_t2p impl=bram

  int8_t v721[1][64][3][34];	// L1302
  #pragma HLS array_partition variable=v721 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v721 type=ram_2p impl=bram

  int8_t v722[1][64][3][3];	// L1303
  #pragma HLS array_partition variable=v722 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v722 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v722 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v722 type=ram_2p impl=lutram

  for (int v723 = 0; v723 < 1; v723 += 1) {	// L1304
    for (int v724 = 0; v724 < 34; v724 += 1) {	// L1305
      for (int v725 = 0; v725 < 34; v725 += 1) {	// L1306
        for (int v726 = 0; v726 < 64; v726 += 1) {	// L1307
          int8_t v727 = v721[v723][v726][1][v725];	// L1308
          v721[v723][v726][0][v725] = v727;	// L1309
          int8_t v728 = v721[v723][v726][2][v725];	// L1310
          v721[v723][v726][1][v725] = v728;	// L1311
          int8_t v729 = v712[v723][v726][v724][v725];	// L1312
          v721[v723][v726][2][v725] = v729;	// L1313
        }
        if ((v724 - 18) >= 0) {	// L1315
          for (int v730 = 0; v730 < 64; v730 += 1) {	// L1316
            for (int v731 = 0; v731 < 3; v731 += 1) {	// L1317
              int8_t v732 = v722[v723][v730][v731][1];	// L1318
              v722[v723][v730][v731][0] = v732;	// L1319
              int8_t v733 = v722[v723][v730][v731][2];	// L1320
              v722[v723][v730][v731][1] = v733;	// L1321
              int8_t v734 = v721[v723][v730][v731][v725];	// L1322
              v722[v723][v730][v731][2] = v734;	// L1323
            }
          }
          if ((v725 - 18) >= 0) {	// L1326
            int8_t v735[128];	// L1327
            #pragma HLS bind_storage variable=v735 type=ram_2p impl=bram

            for (int v736 = 0; v736 < 128; v736 += 1) {	// L1328
              v735[v736] = (int8_t)0.000000;	// L1329
              for (int v737 = 0; v737 < 8; v737 += 1) {	// L1330
                #pragma HLS pipeline II=1
                for (int v738 = 0; v738 < 8; v738 += 1) {	// L1331
                  for (int v739 = 0; v739 < 3; v739 += 1) {	// L1332
                    for (int v740 = 0; v740 < 3; v740 += 1) {	// L1333
                      int8_t v741 = v722[v723][(v738 + (v737 * 8))][v739][v740];	// L1334
                      int8_t v742 = v710[v736][(v738 + (v737 * 8))][v739][v740];	// L1335
                      int8_t v743 = v741 * v742;	// L1336
                      int8_t v744 = v735[v736];	// L1337
                      int8_t v745 = v744 + v743;	// L1338
                      v735[v736] = v745;	// L1339
                    }
                  }
                }
              }
              int8_t v746 = v735[v736];	// L1344
              v720[v723][v736][(v724 - 18)][(v725 - 18)] = v746;	// L1345
            }
          }
        }
      }
    }
  }
  for (int v747 = 0; v747 < 1; v747 += 1) {	// L1352
    for (int v748 = 0; v748 < 16; v748 += 1) {	// L1353
      for (int v749 = 0; v749 < 16; v749 += 1) {	// L1354
        for (int v750 = 0; v750 < 128; v750 += 1) {	// L1355
          int8_t v751 = v720[0][v750][v748][v749];	// L1356
          bool v752 = v751 > (int8_t)0.000000;	// L1357
          int8_t v753 = v752 ? v751 : (int8_t)0.000000;	// L1358
          v711[v747][v750][v748][v749] = v753;	// L1359
        }
      }
    }
  }
}

void main_graph_node24(
  int8_t v754[1][64][32][32],
  int8_t v755[1][64][32][32],
  int8_t v756[1][64][32][32]
) {	// L1366
  #pragma HLS dataflow

  for (int v757 = 0; v757 < 1; v757 += 1) {	// L1367
    for (int v758 = 0; v758 < 32; v758 += 1) {	// L1368
      for (int v759 = 0; v759 < 32; v759 += 1) {	// L1369
        for (int v760 = 0; v760 < 64; v760 += 1) {	// L1370
          int8_t temp = v754[v757][v760][v758][v759];	// L1371
          v755[v757][v760][v758][v759] = temp;	// L1372
          int8_t v762 = temp;	// L1373
          v756[v757][v760][v758][v759] = v762;	// L1374
        }
      }
    }
  }
}

void main_graph_node25(
  int8_t v763[1][64][32][32],
  int8_t v764[64][64][3][3],
  int8_t v765[1][64][32][32],
  int8_t v766[1][64][32][32]
) {	// L1381
  #pragma HLS dataflow

  int8_t v767[1][64][34][34];	// L1383
  #pragma HLS stream variable=v767 depth=10 type=fifo

  #pragma HLS bind_storage variable=v767 type=ram_t2p impl=bram

  for (int v768 = 0; v768 < 1; v768 += 1) {	// L1384
    for (int v769 = 0; v769 < 34; v769 += 1) {	// L1385
      for (int v770 = 0; v770 < 34; v770 += 1) {	// L1386
        for (int v771 = 0; v771 < 64; v771 += 1) {	// L1387
          int8_t v772;	// L1388
          v772 = (int8_t)0.000000;	// L1389
          if (((-v769) + 31) >= 0 && ((-v770) + 31) >= 0) {	// L1390
            int8_t v773 = v765[v768][v771][v769][v770];	// L1391
            v772 = v773;	// L1392
          }
          int8_t v774 = v772;	// L1394
          v767[v768][v771][v769][v770] = v774;	// L1395
        }
      }
    }
  }
  int8_t v775[1][64][32][32];	// L1400
  #pragma HLS stream variable=v775 depth=10 type=fifo

  #pragma HLS bind_storage variable=v775 type=ram_t2p impl=bram

  int8_t v776[1][64][3][34];	// L1401
  #pragma HLS array_partition variable=v776 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v776 type=ram_2p impl=bram

  int8_t v777[1][64][3][3];	// L1402
  #pragma HLS array_partition variable=v777 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v777 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v777 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v777 type=ram_2p impl=lutram

  for (int v778 = 0; v778 < 1; v778 += 1) {	// L1403
    for (int v779 = 0; v779 < 34; v779 += 1) {	// L1404
      for (int v780 = 0; v780 < 34; v780 += 1) {	// L1405
        for (int v781 = 0; v781 < 64; v781 += 1) {	// L1406
          int8_t v782 = v776[v778][v781][1][v780];	// L1407
          v776[v778][v781][0][v780] = v782;	// L1408
          int8_t v783 = v776[v778][v781][2][v780];	// L1409
          v776[v778][v781][1][v780] = v783;	// L1410
          int8_t v784 = v767[v778][v781][v779][v780];	// L1411
          v776[v778][v781][2][v780] = v784;	// L1412
        }
        if ((v779 - 2) >= 0) {	// L1414
          for (int v785 = 0; v785 < 64; v785 += 1) {	// L1415
            for (int v786 = 0; v786 < 3; v786 += 1) {	// L1416
              int8_t v787 = v777[v778][v785][v786][1];	// L1417
              v777[v778][v785][v786][0] = v787;	// L1418
              int8_t v788 = v777[v778][v785][v786][2];	// L1419
              v777[v778][v785][v786][1] = v788;	// L1420
              int8_t v789 = v776[v778][v785][v786][v780];	// L1421
              v777[v778][v785][v786][2] = v789;	// L1422
            }
          }
          if ((v780 - 2) >= 0) {	// L1425
            int8_t v790[64];	// L1426
            #pragma HLS bind_storage variable=v790 type=ram_2p impl=bram

            for (int v791 = 0; v791 < 64; v791 += 1) {	// L1427
              v790[v791] = (int8_t)0.000000;	// L1428
              for (int v792 = 0; v792 < 16; v792 += 1) {	// L1429
                #pragma HLS pipeline II=1
                for (int v793 = 0; v793 < 4; v793 += 1) {	// L1430
                  for (int v794 = 0; v794 < 3; v794 += 1) {	// L1431
                    for (int v795 = 0; v795 < 3; v795 += 1) {	// L1432
                      int8_t v796 = v777[v778][(v793 + (v792 * 4))][v794][v795];	// L1433
                      int8_t v797 = v764[v791][(v793 + (v792 * 4))][v794][v795];	// L1434
                      int8_t v798 = v796 * v797;	// L1435
                      int8_t v799 = v790[v791];	// L1436
                      int8_t v800 = v799 + v798;	// L1437
                      v790[v791] = v800;	// L1438
                    }
                  }
                }
              }
              int8_t v801 = v790[v791];	// L1443
              v775[v778][v791][(v779 - 2)][(v780 - 2)] = v801;	// L1444
            }
          }
        }
      }
    }
  }
  for (int v802 = 0; v802 < 1; v802 += 1) {	// L1451
    for (int v803 = 0; v803 < 32; v803 += 1) {	// L1452
      for (int v804 = 0; v804 < 32; v804 += 1) {	// L1453
        for (int v805 = 0; v805 < 64; v805 += 1) {	// L1454
          int8_t v806 = v775[0][v805][v803][v804];	// L1455
          int8_t v807 = v763[0][v805][v803][v804];	// L1456
          int8_t v808 = v806 + v807;	// L1457
          bool v809 = v808 > (int8_t)0.000000;	// L1458
          int8_t v810 = v809 ? v808 : (int8_t)0.000000;	// L1459
          v766[v802][v805][v803][v804] = v810;	// L1460
        }
      }
    }
  }
}

void main_graph_node26(
  int8_t v811[1][64][32][32],
  int8_t v812[64][64][3][3],
  int8_t v813[1][64][32][32]
) {	// L1467
  #pragma HLS dataflow

  int8_t v814[1][64][34][34];	// L1469
  #pragma HLS stream variable=v814 depth=10 type=fifo

  #pragma HLS bind_storage variable=v814 type=ram_t2p impl=bram

  for (int v815 = 0; v815 < 1; v815 += 1) {	// L1470
    for (int v816 = 0; v816 < 34; v816 += 1) {	// L1471
      for (int v817 = 0; v817 < 34; v817 += 1) {	// L1472
        for (int v818 = 0; v818 < 64; v818 += 1) {	// L1473
          int8_t v819;	// L1474
          v819 = (int8_t)0.000000;	// L1475
          if (((-v816) + 31) >= 0 && ((-v817) + 31) >= 0) {	// L1476
            int8_t v820 = v811[v815][v818][v816][v817];	// L1477
            v819 = v820;	// L1478
          }
          int8_t v821 = v819;	// L1480
          v814[v815][v818][v816][v817] = v821;	// L1481
        }
      }
    }
  }
  int8_t v822[1][64][32][32];	// L1486
  #pragma HLS stream variable=v822 depth=10 type=fifo

  #pragma HLS bind_storage variable=v822 type=ram_t2p impl=bram

  int8_t v823[1][64][3][34];	// L1487
  #pragma HLS array_partition variable=v823 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v823 type=ram_2p impl=bram

  int8_t v824[1][64][3][3];	// L1488
  #pragma HLS array_partition variable=v824 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v824 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v824 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v824 type=ram_2p impl=lutram

  for (int v825 = 0; v825 < 1; v825 += 1) {	// L1489
    for (int v826 = 0; v826 < 34; v826 += 1) {	// L1490
      for (int v827 = 0; v827 < 34; v827 += 1) {	// L1491
        for (int v828 = 0; v828 < 64; v828 += 1) {	// L1492
          int8_t v829 = v823[v825][v828][1][v827];	// L1493
          v823[v825][v828][0][v827] = v829;	// L1494
          int8_t v830 = v823[v825][v828][2][v827];	// L1495
          v823[v825][v828][1][v827] = v830;	// L1496
          int8_t v831 = v814[v825][v828][v826][v827];	// L1497
          v823[v825][v828][2][v827] = v831;	// L1498
        }
        if ((v826 - 2) >= 0) {	// L1500
          for (int v832 = 0; v832 < 64; v832 += 1) {	// L1501
            for (int v833 = 0; v833 < 3; v833 += 1) {	// L1502
              int8_t v834 = v824[v825][v832][v833][1];	// L1503
              v824[v825][v832][v833][0] = v834;	// L1504
              int8_t v835 = v824[v825][v832][v833][2];	// L1505
              v824[v825][v832][v833][1] = v835;	// L1506
              int8_t v836 = v823[v825][v832][v833][v827];	// L1507
              v824[v825][v832][v833][2] = v836;	// L1508
            }
          }
          if ((v827 - 2) >= 0) {	// L1511
            int8_t v837[64];	// L1512
            #pragma HLS bind_storage variable=v837 type=ram_2p impl=bram

            for (int v838 = 0; v838 < 64; v838 += 1) {	// L1513
              v837[v838] = (int8_t)0.000000;	// L1514
              for (int v839 = 0; v839 < 16; v839 += 1) {	// L1515
                #pragma HLS pipeline II=1
                for (int v840 = 0; v840 < 4; v840 += 1) {	// L1516
                  for (int v841 = 0; v841 < 3; v841 += 1) {	// L1517
                    for (int v842 = 0; v842 < 3; v842 += 1) {	// L1518
                      int8_t v843 = v824[v825][(v840 + (v839 * 4))][v841][v842];	// L1519
                      int8_t v844 = v812[v838][(v840 + (v839 * 4))][v841][v842];	// L1520
                      int8_t v845 = v843 * v844;	// L1521
                      int8_t v846 = v837[v838];	// L1522
                      int8_t v847 = v846 + v845;	// L1523
                      v837[v838] = v847;	// L1524
                    }
                  }
                }
              }
              int8_t v848 = v837[v838];	// L1529
              v822[v825][v838][(v826 - 2)][(v827 - 2)] = v848;	// L1530
            }
          }
        }
      }
    }
  }
  for (int v849 = 0; v849 < 1; v849 += 1) {	// L1537
    for (int v850 = 0; v850 < 32; v850 += 1) {	// L1538
      for (int v851 = 0; v851 < 32; v851 += 1) {	// L1539
        for (int v852 = 0; v852 < 64; v852 += 1) {	// L1540
          int8_t v853 = v822[0][v852][v850][v851];	// L1541
          bool v854 = v853 > (int8_t)0.000000;	// L1542
          int8_t v855 = v854 ? v853 : (int8_t)0.000000;	// L1543
          v813[v849][v852][v850][v851] = v855;	// L1544
        }
      }
    }
  }
}

void main_graph_node27(
  int8_t v856[1][64][32][32],
  int8_t v857[1][64][32][32],
  int8_t v858[1][64][32][32]
) {	// L1551
  #pragma HLS dataflow

  for (int v859 = 0; v859 < 1; v859 += 1) {	// L1552
    for (int v860 = 0; v860 < 32; v860 += 1) {	// L1553
      for (int v861 = 0; v861 < 32; v861 += 1) {	// L1554
        for (int v862 = 0; v862 < 64; v862 += 1) {	// L1555
          int8_t temp = v856[v859][v862][v860][v861];	// L1556
          v857[v859][v862][v860][v861] = temp;	// L1557
          int8_t v864 = temp;	// L1558
          v858[v859][v862][v860][v861] = v864;	// L1559
        }
      }
    }
  }
}

void main_graph_node28(
  int8_t v865[1][64][32][32],
  int8_t v866[1][64][32][32],
  int8_t v867[64][64][3][3],
  int8_t v868[1][64][32][32]
) {	// L1566
  #pragma HLS dataflow

  int8_t v869[1][64][34][34];	// L1568
  #pragma HLS stream variable=v869 depth=10 type=fifo

  #pragma HLS bind_storage variable=v869 type=ram_t2p impl=bram

  for (int v870 = 0; v870 < 1; v870 += 1) {	// L1569
    for (int v871 = 0; v871 < 34; v871 += 1) {	// L1570
      for (int v872 = 0; v872 < 34; v872 += 1) {	// L1571
        for (int v873 = 0; v873 < 64; v873 += 1) {	// L1572
          int8_t v874;	// L1573
          v874 = (int8_t)0.000000;	// L1574
          if (((-v871) + 31) >= 0 && ((-v872) + 31) >= 0) {	// L1575
            int8_t v875 = v866[v870][v873][v871][v872];	// L1576
            v874 = v875;	// L1577
          }
          int8_t v876 = v874;	// L1579
          v869[v870][v873][v871][v872] = v876;	// L1580
        }
      }
    }
  }
  int8_t v877[1][64][32][32];	// L1585
  #pragma HLS stream variable=v877 depth=10 type=fifo

  #pragma HLS bind_storage variable=v877 type=ram_t2p impl=bram

  int8_t v878[1][64][3][34];	// L1586
  #pragma HLS array_partition variable=v878 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v878 type=ram_2p impl=bram

  int8_t v879[1][64][3][3];	// L1587
  #pragma HLS array_partition variable=v879 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v879 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v879 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v879 type=ram_2p impl=lutram

  for (int v880 = 0; v880 < 1; v880 += 1) {	// L1588
    for (int v881 = 0; v881 < 34; v881 += 1) {	// L1589
      for (int v882 = 0; v882 < 34; v882 += 1) {	// L1590
        for (int v883 = 0; v883 < 64; v883 += 1) {	// L1591
          int8_t v884 = v878[v880][v883][1][v882];	// L1592
          v878[v880][v883][0][v882] = v884;	// L1593
          int8_t v885 = v878[v880][v883][2][v882];	// L1594
          v878[v880][v883][1][v882] = v885;	// L1595
          int8_t v886 = v869[v880][v883][v881][v882];	// L1596
          v878[v880][v883][2][v882] = v886;	// L1597
        }
        if ((v881 - 2) >= 0) {	// L1599
          for (int v887 = 0; v887 < 64; v887 += 1) {	// L1600
            for (int v888 = 0; v888 < 3; v888 += 1) {	// L1601
              int8_t v889 = v879[v880][v887][v888][1];	// L1602
              v879[v880][v887][v888][0] = v889;	// L1603
              int8_t v890 = v879[v880][v887][v888][2];	// L1604
              v879[v880][v887][v888][1] = v890;	// L1605
              int8_t v891 = v878[v880][v887][v888][v882];	// L1606
              v879[v880][v887][v888][2] = v891;	// L1607
            }
          }
          if ((v882 - 2) >= 0) {	// L1610
            int8_t v892[64];	// L1611
            #pragma HLS bind_storage variable=v892 type=ram_2p impl=bram

            for (int v893 = 0; v893 < 64; v893 += 1) {	// L1612
              v892[v893] = (int8_t)0.000000;	// L1613
              for (int v894 = 0; v894 < 16; v894 += 1) {	// L1614
                #pragma HLS pipeline II=1
                for (int v895 = 0; v895 < 4; v895 += 1) {	// L1615
                  for (int v896 = 0; v896 < 3; v896 += 1) {	// L1616
                    for (int v897 = 0; v897 < 3; v897 += 1) {	// L1617
                      int8_t v898 = v879[v880][(v895 + (v894 * 4))][v896][v897];	// L1618
                      int8_t v899 = v867[v893][(v895 + (v894 * 4))][v896][v897];	// L1619
                      int8_t v900 = v898 * v899;	// L1620
                      int8_t v901 = v892[v893];	// L1621
                      int8_t v902 = v901 + v900;	// L1622
                      v892[v893] = v902;	// L1623
                    }
                  }
                }
              }
              int8_t v903 = v892[v893];	// L1628
              v877[v880][v893][(v881 - 2)][(v882 - 2)] = v903;	// L1629
            }
          }
        }
      }
    }
  }
  for (int v904 = 0; v904 < 1; v904 += 1) {	// L1636
    for (int v905 = 0; v905 < 32; v905 += 1) {	// L1637
      for (int v906 = 0; v906 < 32; v906 += 1) {	// L1638
        for (int v907 = 0; v907 < 64; v907 += 1) {	// L1639
          int8_t v908 = v877[0][v907][v905][v906];	// L1640
          int8_t v909 = v865[0][v907][v905][v906];	// L1641
          int8_t v910 = v908 + v909;	// L1642
          bool v911 = v910 > (int8_t)0.000000;	// L1643
          int8_t v912 = v911 ? v910 : (int8_t)0.000000;	// L1644
          v868[v904][v907][v905][v906] = v912;	// L1645
        }
      }
    }
  }
}

void main_graph_node29(
  int8_t v913[1][64][32][32],
  int8_t v914[64][64][3][3],
  int8_t v915[1][64][32][32]
) {	// L1652
  #pragma HLS dataflow

  int8_t v916[1][64][34][34];	// L1654
  #pragma HLS stream variable=v916 depth=10 type=fifo

  #pragma HLS bind_storage variable=v916 type=ram_t2p impl=bram

  for (int v917 = 0; v917 < 1; v917 += 1) {	// L1655
    for (int v918 = 0; v918 < 34; v918 += 1) {	// L1656
      for (int v919 = 0; v919 < 34; v919 += 1) {	// L1657
        for (int v920 = 0; v920 < 64; v920 += 1) {	// L1658
          int8_t v921;	// L1659
          v921 = (int8_t)0.000000;	// L1660
          if (((-v918) + 31) >= 0 && ((-v919) + 31) >= 0) {	// L1661
            int8_t v922 = v913[v917][v920][v918][v919];	// L1662
            v921 = v922;	// L1663
          }
          int8_t v923 = v921;	// L1665
          v916[v917][v920][v918][v919] = v923;	// L1666
        }
      }
    }
  }
  int8_t v924[1][64][32][32];	// L1671
  #pragma HLS stream variable=v924 depth=10 type=fifo

  #pragma HLS bind_storage variable=v924 type=ram_t2p impl=bram

  int8_t v925[1][64][3][34];	// L1672
  #pragma HLS array_partition variable=v925 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v925 type=ram_2p impl=bram

  int8_t v926[1][64][3][3];	// L1673
  #pragma HLS array_partition variable=v926 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v926 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v926 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v926 type=ram_2p impl=lutram

  for (int v927 = 0; v927 < 1; v927 += 1) {	// L1674
    for (int v928 = 0; v928 < 34; v928 += 1) {	// L1675
      for (int v929 = 0; v929 < 34; v929 += 1) {	// L1676
        for (int v930 = 0; v930 < 64; v930 += 1) {	// L1677
          int8_t v931 = v925[v927][v930][1][v929];	// L1678
          v925[v927][v930][0][v929] = v931;	// L1679
          int8_t v932 = v925[v927][v930][2][v929];	// L1680
          v925[v927][v930][1][v929] = v932;	// L1681
          int8_t v933 = v916[v927][v930][v928][v929];	// L1682
          v925[v927][v930][2][v929] = v933;	// L1683
        }
        if ((v928 - 2) >= 0) {	// L1685
          for (int v934 = 0; v934 < 64; v934 += 1) {	// L1686
            for (int v935 = 0; v935 < 3; v935 += 1) {	// L1687
              int8_t v936 = v926[v927][v934][v935][1];	// L1688
              v926[v927][v934][v935][0] = v936;	// L1689
              int8_t v937 = v926[v927][v934][v935][2];	// L1690
              v926[v927][v934][v935][1] = v937;	// L1691
              int8_t v938 = v925[v927][v934][v935][v929];	// L1692
              v926[v927][v934][v935][2] = v938;	// L1693
            }
          }
          if ((v929 - 2) >= 0) {	// L1696
            int8_t v939[64];	// L1697
            #pragma HLS bind_storage variable=v939 type=ram_2p impl=bram

            for (int v940 = 0; v940 < 64; v940 += 1) {	// L1698
              v939[v940] = (int8_t)0.000000;	// L1699
              for (int v941 = 0; v941 < 16; v941 += 1) {	// L1700
                #pragma HLS pipeline II=1
                for (int v942 = 0; v942 < 4; v942 += 1) {	// L1701
                  for (int v943 = 0; v943 < 3; v943 += 1) {	// L1702
                    for (int v944 = 0; v944 < 3; v944 += 1) {	// L1703
                      int8_t v945 = v926[v927][(v942 + (v941 * 4))][v943][v944];	// L1704
                      int8_t v946 = v914[v940][(v942 + (v941 * 4))][v943][v944];	// L1705
                      int8_t v947 = v945 * v946;	// L1706
                      int8_t v948 = v939[v940];	// L1707
                      int8_t v949 = v948 + v947;	// L1708
                      v939[v940] = v949;	// L1709
                    }
                  }
                }
              }
              int8_t v950 = v939[v940];	// L1714
              v924[v927][v940][(v928 - 2)][(v929 - 2)] = v950;	// L1715
            }
          }
        }
      }
    }
  }
  for (int v951 = 0; v951 < 1; v951 += 1) {	// L1722
    for (int v952 = 0; v952 < 32; v952 += 1) {	// L1723
      for (int v953 = 0; v953 < 32; v953 += 1) {	// L1724
        for (int v954 = 0; v954 < 64; v954 += 1) {	// L1725
          int8_t v955 = v924[0][v954][v952][v953];	// L1726
          bool v956 = v955 > (int8_t)0.000000;	// L1727
          int8_t v957 = v956 ? v955 : (int8_t)0.000000;	// L1728
          v915[v951][v954][v952][v953] = v957;	// L1729
        }
      }
    }
  }
}

void main_graph_node30(
  int8_t v958[1][64][32][32],
  int8_t v959[1][64][32][32],
  int8_t v960[1][64][32][32]
) {	// L1736
  #pragma HLS dataflow

  for (int v961 = 0; v961 < 1; v961 += 1) {	// L1737
    for (int v962 = 0; v962 < 32; v962 += 1) {	// L1738
      for (int v963 = 0; v963 < 32; v963 += 1) {	// L1739
        for (int v964 = 0; v964 < 64; v964 += 1) {	// L1740
          int8_t temp = v958[v961][v964][v962][v963];	// L1741
          v959[v961][v964][v962][v963] = temp;	// L1742
          int8_t v966 = temp;	// L1743
          v960[v961][v964][v962][v963] = v966;	// L1744
        }
      }
    }
  }
}

void main_graph_node31(
  int8_t v967[1][3][32][32],
  int8_t v968[64][3][3][3],
  int8_t v969[1][64][32][32]
) {	// L1751
  #pragma HLS dataflow

  int8_t v970[1][3][34][34];	// L1753
  #pragma HLS stream variable=v970 depth=10 type=fifo

  #pragma HLS bind_storage variable=v970 type=ram_t2p impl=bram

  for (int v971 = 0; v971 < 1; v971 += 1) {	// L1754
    for (int v972 = 0; v972 < 34; v972 += 1) {	// L1755
      for (int v973 = 0; v973 < 34; v973 += 1) {	// L1756
        for (int v974 = 0; v974 < 3; v974 += 1) {	// L1757
          int8_t v975;	// L1758
          v975 = (int8_t)0.000000;	// L1759
          if (((-v972) + 31) >= 0 && ((-v973) + 31) >= 0) {	// L1760
            int8_t v976 = v967[v971][v974][v972][v973];	// L1761
            v975 = v976;	// L1762
          }
          int8_t v977 = v975;	// L1764
          v970[v971][v974][v972][v973] = v977;	// L1765
        }
      }
    }
  }
  int8_t v978[1][64][32][32];	// L1770
  #pragma HLS stream variable=v978 depth=10 type=fifo

  #pragma HLS bind_storage variable=v978 type=ram_t2p impl=bram

  int8_t v979[1][3][3][34];	// L1771
  #pragma HLS array_partition variable=v979 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v979 type=ram_2p impl=lutram

  int8_t v980[1][3][3][3];	// L1772
  #pragma HLS array_partition variable=v980 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v980 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v980 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v980 type=ram_2p impl=lutram

  for (int v981 = 0; v981 < 1; v981 += 1) {	// L1773
    for (int v982 = 0; v982 < 34; v982 += 1) {	// L1774
      for (int v983 = 0; v983 < 34; v983 += 1) {	// L1775
        for (int v984 = 0; v984 < 3; v984 += 1) {	// L1776
          int8_t v985 = v979[v981][v984][1][v983];	// L1777
          v979[v981][v984][0][v983] = v985;	// L1778
          int8_t v986 = v979[v981][v984][2][v983];	// L1779
          v979[v981][v984][1][v983] = v986;	// L1780
          int8_t v987 = v970[v981][v984][v982][v983];	// L1781
          v979[v981][v984][2][v983] = v987;	// L1782
        }
        if ((v982 - 2) >= 0) {	// L1784
          for (int v988 = 0; v988 < 3; v988 += 1) {	// L1785
            for (int v989 = 0; v989 < 3; v989 += 1) {	// L1786
              int8_t v990 = v980[v981][v988][v989][1];	// L1787
              v980[v981][v988][v989][0] = v990;	// L1788
              int8_t v991 = v980[v981][v988][v989][2];	// L1789
              v980[v981][v988][v989][1] = v991;	// L1790
              int8_t v992 = v979[v981][v988][v989][v983];	// L1791
              v980[v981][v988][v989][2] = v992;	// L1792
            }
          }
          if ((v983 - 2) >= 0) {	// L1795
            int8_t v993[64];	// L1796
            #pragma HLS bind_storage variable=v993 type=ram_2p impl=bram

            for (int v994 = 0; v994 < 64; v994 += 1) {	// L1797
              #pragma HLS pipeline II=1
              for (int v995 = 0; v995 < 1; v995 += 1) {	// L1798
                v993[(v994 + v995)] = (int8_t)0.000000;	// L1799
                for (int v996 = 0; v996 < 3; v996 += 1) {	// L1800
                  for (int v997 = 0; v997 < 3; v997 += 1) {	// L1801
                    for (int v998 = 0; v998 < 3; v998 += 1) {	// L1802
                      int8_t v999 = v980[v981][v996][v997][v998];	// L1803
                      int8_t v1000 = v968[(v994 + v995)][v996][v997][v998];	// L1804
                      int8_t v1001 = v999 * v1000;	// L1805
                      int8_t v1002 = v993[(v994 + v995)];	// L1806
                      int8_t v1003 = v1002 + v1001;	// L1807
                      v993[(v994 + v995)] = v1003;	// L1808
                    }
                  }
                }
                int8_t v1004 = v993[(v994 + v995)];	// L1812
                v978[v981][(v994 + v995)][(v982 - 2)][(v983 - 2)] = v1004;	// L1813
              }
            }
          }
        }
      }
    }
  }
  for (int v1005 = 0; v1005 < 1; v1005 += 1) {	// L1821
    for (int v1006 = 0; v1006 < 32; v1006 += 1) {	// L1822
      for (int v1007 = 0; v1007 < 32; v1007 += 1) {	// L1823
        for (int v1008 = 0; v1008 < 64; v1008 += 1) {	// L1824
          int8_t v1009 = v978[0][v1008][v1006][v1007];	// L1825
          bool v1010 = v1009 > (int8_t)0.000000;	// L1826
          int8_t v1011 = v1010 ? v1009 : (int8_t)0.000000;	// L1827
          v969[v1005][v1008][v1006][v1007] = v1011;	// L1828
        }
      }
    }
  }
}

void load_array(
    int8_t v1012[1][3][32][32],ap_uint<256> *vv1012,
    int8_t v1013[10],ap_uint<256> *vv1013,
    int8_t v1014[512][512][3][3],ap_uint<256> *vv1014,
    int8_t v1015[512][512][3][3],ap_uint<256> *vv1015,
    int8_t v1016[512][256][1][1],ap_uint<256> *vv1016,
    int8_t v1017[512][512][3][3],ap_uint<256> *vv1017,
    int8_t v1018[512][256][3][3],ap_uint<256> *vv1018,
    int8_t v1019[256][256][3][3],ap_uint<256> *vv1019,
    int8_t v1020[256][256][3][3],ap_uint<256> *vv1020,
    int8_t v1021[256][128][1][1],ap_uint<256> *vv1021,
    int8_t v1022[256][256][3][3],ap_uint<256> *vv1022,
    int8_t v1023[256][128][3][3],ap_uint<256> *vv1023,
    int8_t v1024[128][128][3][3],ap_uint<256> *vv1024,
    int8_t v1025[128][128][3][3],ap_uint<256> *vv1025,
    int8_t v1026[128][64][1][1],ap_uint<256> *vv1026,
    int8_t v1027[128][128][3][3],ap_uint<256> *vv1027,
    int8_t v1028[128][64][3][3],ap_uint<256> *vv1028,
    int8_t v1029[64][64][3][3],ap_uint<256> *vv1029,
    int8_t v1030[64][64][3][3],ap_uint<256> *vv1030,
    int8_t v1031[64][64][3][3],ap_uint<256> *vv1031,
    int8_t v1032[64][64][3][3],ap_uint<256> *vv1032,
    int8_t v1033[64][3][3][3],ap_uint<256> *vv1033,
    int8_t v1034[512][10],ap_uint<256> *vv1034,
    int8_t v1035[1][10],ap_uint<256> *vv1035
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
ap_uint<256> temp_17;
ap_uint<256> temp_18;
ap_uint<256> temp_19;
ap_uint<256> temp_20;
ap_uint<256> temp_21;
ap_uint<256> temp_22;
ap_uint<256> temp_23;
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 32; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_0 = vv1012[i * 3 * 32 * 1 + j * 32 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1012[i][j][k][l * 32 + bias] = temp_0.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 1; ++i) { 
      temp_1 = vv1013[i];
      for (int bias = 0; bias < 10; ++bias) { 
                    v1013[i * 32 + bias] = temp_1.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_2 = vv1014[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1014[i][j * 32 + bias][k][l] = temp_2.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_3 = vv1015[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1015[i][j * 32 + bias][k][l] = temp_3.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_4 = vv1016[i * 8 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1016[i][j * 32 + bias][k][l] = temp_4.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_5 = vv1017[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1017[i][j * 32 + bias][k][l] = temp_5.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_6 = vv1018[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1018[i][j * 32 + bias][k][l] = temp_6.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_7 = vv1019[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1019[i][j * 32 + bias][k][l] = temp_7.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_8 = vv1020[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1020[i][j * 32 + bias][k][l] = temp_8.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_9 = vv1021[i * 4 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1021[i][j * 32 + bias][k][l] = temp_9.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_10 = vv1022[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1022[i][j * 32 + bias][k][l] = temp_10.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_11 = vv1023[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1023[i][j * 32 + bias][k][l] = temp_11.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_12 = vv1024[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1024[i][j * 32 + bias][k][l] = temp_12.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_13 = vv1025[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1025[i][j * 32 + bias][k][l] = temp_13.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_14 = vv1026[i * 2 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1026[i][j * 32 + bias][k][l] = temp_14.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_15 = vv1027[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1027[i][j * 32 + bias][k][l] = temp_15.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_16 = vv1028[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1028[i][j * 32 + bias][k][l] = temp_16.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_17 = vv1029[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1029[i][j * 32 + bias][k][l] = temp_17.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_18 = vv1030[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1030[i][j * 32 + bias][k][l] = temp_18.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_19 = vv1031[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1031[i][j * 32 + bias][k][l] = temp_19.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_20 = vv1032[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1032[i][j * 32 + bias][k][l] = temp_20.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_21 = vv1033[i * 3 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1033[i * 32 + bias][j][k][l] = temp_21.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 10; ++j) {
          temp_22 = vv1034[i * 10 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v1034[i * 32 + bias][j] = temp_22.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 1; ++j) {
          temp_23 = vv1035[i * 1 + j];
          for (int bias = 0; bias < 10; ++bias) { 
              v1035[i][j * 32 + bias] = temp_23.range(bias*8+7, bias*8);
}
}
}
}



/// This is top function.
void main_graph(
    ap_uint<256> *vv1012,
    ap_uint<256> *vv1013,
    ap_uint<256> *vv1014,
    ap_uint<256> *vv1015,
    ap_uint<256> *vv1016,
    ap_uint<256> *vv1017,
    ap_uint<256> *vv1018,
    ap_uint<256> *vv1019,
    ap_uint<256> *vv1020,
    ap_uint<256> *vv1021,
    ap_uint<256> *vv1022,
    ap_uint<256> *vv1023,
    ap_uint<256> *vv1024,
    ap_uint<256> *vv1025,
    ap_uint<256> *vv1026,
    ap_uint<256> *vv1027,
    ap_uint<256> *vv1028,
    ap_uint<256> *vv1029,
    ap_uint<256> *vv1030,
    ap_uint<256> *vv1031,
    ap_uint<256> *vv1032,
    ap_uint<256> *vv1033,
    ap_uint<256> *vv1034,
    ap_uint<256> *vv1035
) {	// L1835
  #pragma HLS interface s_axilite port=return 

  #pragma HLS INTERFACE m_axi port=vv1012 offset = slave bundle=gmem0
  #pragma HLS INTERFACE m_axi port=vv1013 offset = slave bundle=gmem1
  #pragma HLS INTERFACE m_axi port=vv1014 offset = slave bundle=gmem2
  #pragma HLS INTERFACE m_axi port=vv1015 offset = slave bundle=gmem3
  #pragma HLS INTERFACE m_axi port=vv1016 offset = slave bundle=gmem4
  #pragma HLS INTERFACE m_axi port=vv1017 offset = slave bundle=gmem5
  #pragma HLS INTERFACE m_axi port=vv1018 offset = slave bundle=gmem6
  #pragma HLS INTERFACE m_axi port=vv1019 offset = slave bundle=gmem7
  #pragma HLS INTERFACE m_axi port=vv1020 offset = slave bundle=gmem8
  #pragma HLS INTERFACE m_axi port=vv1021 offset = slave bundle=gmem9
  #pragma HLS INTERFACE m_axi port=vv1022 offset = slave bundle=gmem10
  #pragma HLS INTERFACE m_axi port=vv1023 offset = slave bundle=gmem11
  #pragma HLS INTERFACE m_axi port=vv1024 offset = slave bundle=gmem12
  #pragma HLS INTERFACE m_axi port=vv1025 offset = slave bundle=gmem13
  #pragma HLS INTERFACE m_axi port=vv1026 offset = slave bundle=gmem14
  #pragma HLS INTERFACE m_axi port=vv1027 offset = slave bundle=gmem15
  #pragma HLS INTERFACE m_axi port=vv1028 offset = slave bundle=gmem16
  #pragma HLS INTERFACE m_axi port=vv1029 offset = slave bundle=gmem17
  #pragma HLS INTERFACE m_axi port=vv1030 offset = slave bundle=gmem18
  #pragma HLS INTERFACE m_axi port=vv1031 offset = slave bundle=gmem19
  #pragma HLS INTERFACE m_axi port=vv1032 offset = slave bundle=gmem20
  #pragma HLS INTERFACE m_axi port=vv1033 offset = slave bundle=gmem21
  #pragma HLS INTERFACE m_axi port=vv1034 offset = slave bundle=gmem22
  #pragma HLS INTERFACE m_axi port=vv1035 offset = slave bundle=gmem23

  int8_t v1012[1][3][32][32];
  int8_t v1013[10];
  int8_t v1014[512][512][3][3];
  int8_t v1015[512][512][3][3];
  int8_t v1016[512][256][1][1];
  int8_t v1017[512][512][3][3];
  int8_t v1018[512][256][3][3];
  int8_t v1019[256][256][3][3];
  int8_t v1020[256][256][3][3];
  int8_t v1021[256][128][1][1];
  int8_t v1022[256][256][3][3];
  int8_t v1023[256][128][3][3];
  int8_t v1024[128][128][3][3];
  int8_t v1025[128][128][3][3];
  int8_t v1026[128][64][1][1];
  int8_t v1027[128][128][3][3];
  int8_t v1028[128][64][3][3];
  int8_t v1029[64][64][3][3];
  int8_t v1030[64][64][3][3];
  int8_t v1031[64][64][3][3];
  int8_t v1032[64][64][3][3];
  int8_t v1033[64][3][3][3];
  int8_t v1034[512][10];
  int8_t v1035[1][10];
  #pragma HLS interface bram port=v1012
  #pragma HLS bind_storage variable=v1012 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1013
  #pragma HLS bind_storage variable=v1013 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1014
  #pragma HLS array_partition variable=v1014 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1014 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1014 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1014 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1015
  #pragma HLS array_partition variable=v1015 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1015 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1015 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1015 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1016
  #pragma HLS array_partition variable=v1016 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1016 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1017
  #pragma HLS array_partition variable=v1017 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1017 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1017 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1017 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1018
  #pragma HLS array_partition variable=v1018 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1018 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1018 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1018 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1019
  #pragma HLS array_partition variable=v1019 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1019 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1019 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1019 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1020
  #pragma HLS array_partition variable=v1020 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1020 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1020 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1020 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1021
  #pragma HLS array_partition variable=v1021 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1021 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1022
  #pragma HLS array_partition variable=v1022 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1022 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1022 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1022 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1023
  #pragma HLS array_partition variable=v1023 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1023 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1023 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1023 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1024
  #pragma HLS array_partition variable=v1024 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1024 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1024 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1024 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1025
  #pragma HLS array_partition variable=v1025 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1025 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1025 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1025 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1026
  #pragma HLS array_partition variable=v1026 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1026 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1027
  #pragma HLS array_partition variable=v1027 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1027 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1027 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1027 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1028
  #pragma HLS array_partition variable=v1028 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1028 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1028 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1028 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1029
  #pragma HLS array_partition variable=v1029 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1029 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1029 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1029 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1030
  #pragma HLS array_partition variable=v1030 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1030 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1030 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1030 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1031
  #pragma HLS array_partition variable=v1031 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1031 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1031 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1031 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1032
  #pragma HLS array_partition variable=v1032 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1032 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1032 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1032 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1033
  #pragma HLS array_partition variable=v1033 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1033 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1033 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1033 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1034
  #pragma HLS bind_storage variable=v1034 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1035
  #pragma HLS bind_storage variable=v1035 type=ram_t2p impl=bram
load_array(
        v1012,vv1012,
        v1013,vv1013,
        v1014,vv1014,
        v1015,vv1015,
        v1016,vv1016,
        v1017,vv1017,
        v1018,vv1018,
        v1019,vv1019,
        v1020,vv1020,
        v1021,vv1021,
        v1022,vv1022,
        v1023,vv1023,
        v1024,vv1024,
        v1025,vv1025,
        v1026,vv1026,
        v1027,vv1027,
        v1028,vv1028,
        v1029,vv1029,
        v1030,vv1030,
        v1031,vv1031,
        v1032,vv1032,
        v1033,vv1033,
        v1034,vv1034,
        v1035,vv1035
    );

  // #pragma HLS dataflow

  // int8_t v1036[1][64][32][32];	// L1837
  // #pragma HLS stream variable=v1036 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1036 type=ram_t2p impl=bram

  // main_graph_node31(v1012, v1033, v1036);	// L1838
  // int8_t v1037[1][64][32][32];	// L1839
  // #pragma HLS stream variable=v1037 depth=64*32*32 type=fifo

  // #pragma HLS bind_storage variable=v1037 type=ram_t2p impl=bram

  // int8_t v1038[1][64][32][32];	// L1840
  // #pragma HLS stream variable=v1038 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1038 type=ram_t2p impl=bram

  // main_graph_node30(v1036, v1037, v1038);	// L1841
  // int8_t v1039[1][64][32][32];	// L1842
  // #pragma HLS stream variable=v1039 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1039 type=ram_t2p impl=bram

  // main_graph_node29(v1038, v1032, v1039);	// L1843
  // int8_t v1040[1][64][32][32];	// L1844
  // #pragma HLS stream variable=v1040 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1040 type=ram_t2p impl=bram

  // main_graph_node28(v1037, v1039, v1031, v1040);	// L1845
  // int8_t v1041[1][64][32][32];	// L1846
  // #pragma HLS stream variable=v1041 depth=64*32*32 type=fifo

  // #pragma HLS bind_storage variable=v1041 type=ram_t2p impl=bram

  // int8_t v1042[1][64][32][32];	// L1847
  // #pragma HLS stream variable=v1042 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1042 type=ram_t2p impl=bram

  // main_graph_node27(v1040, v1041, v1042);	// L1848
  // int8_t v1043[1][64][32][32];	// L1849
  // #pragma HLS stream variable=v1043 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1043 type=ram_t2p impl=bram

  // main_graph_node26(v1042, v1030, v1043);	// L1850
  // int8_t v1044[1][64][32][32];	// L1851
  // #pragma HLS stream variable=v1044 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1044 type=ram_t2p impl=bram

  // main_graph_node25(v1041, v1029, v1043, v1044);	// L1852
  // int8_t v1045[1][64][32][32];	// L1853
  // #pragma HLS stream variable=v1045 depth=64*32*32 type=fifo

  // #pragma HLS bind_storage variable=v1045 type=ram_t2p impl=bram

  // int8_t v1046[1][64][32][32];	// L1854
  // #pragma HLS stream variable=v1046 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1046 type=ram_t2p impl=bram

  // main_graph_node24(v1044, v1045, v1046);	// L1855
  // int8_t v1047[1][128][16][16];	// L1856
  // #pragma HLS stream variable=v1047 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1047 type=ram_t2p impl=bram

  // main_graph_node23(v1046, v1028, v1047);	// L1857
  // int8_t v1048[1][128][16][16];	// L1858
  // #pragma HLS stream variable=v1048 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1048 type=ram_t2p impl=bram

  // main_graph_node22(v1047, v1027, v1048);	// L1859
  // int8_t v1049[1][128][16][16];	// L1860
  // #pragma HLS stream variable=v1049 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1049 type=ram_t2p impl=bram

  // main_graph_node21(v1045, v1026, v1048, v1049);	// L1861
  // int8_t v1050[1][128][16][16];	// L1862
  // #pragma HLS stream variable=v1050 depth=128*16*16 type=fifo

  // #pragma HLS bind_storage variable=v1050 type=ram_t2p impl=bram

  // int8_t v1051[1][128][16][16];	// L1863
  // #pragma HLS stream variable=v1051 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1051 type=ram_t2p impl=bram

  // main_graph_node20(v1049, v1050, v1051);	// L1864
  // int8_t v1052[1][128][16][16];	// L1865
  // #pragma HLS stream variable=v1052 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1052 type=ram_t2p impl=bram

  // main_graph_node19(v1025, v1051, v1052);	// L1866
  // int8_t v1053[1][128][16][16];	// L1867
  // #pragma HLS stream variable=v1053 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1053 type=ram_t2p impl=bram

  // main_graph_node18(v1052, v1024, v1050, v1053);	// L1868
  // int8_t v1054[1][128][16][16];	// L1869
  // #pragma HLS stream variable=v1054 depth=128*16*16 type=fifo

  // #pragma HLS bind_storage variable=v1054 type=ram_t2p impl=bram

  // int8_t v1055[1][128][16][16];	// L1870
  // #pragma HLS stream variable=v1055 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1055 type=ram_t2p impl=bram

  // main_graph_node17(v1053, v1054, v1055);	// L1871
  // int8_t v1056[1][256][8][8];	// L1872
  // #pragma HLS stream variable=v1056 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1056 type=ram_t2p impl=bram

  // main_graph_node16(v1023, v1055, v1056);	// L1873
  // int8_t v1057[1][256][8][8];	// L1874
  // #pragma HLS stream variable=v1057 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1057 type=ram_t2p impl=bram

  // main_graph_node15(v1056, v1022, v1057);	// L1875
  // int8_t v1058[1][256][8][8];	// L1876
  // #pragma HLS stream variable=v1058 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1058 type=ram_t2p impl=bram

  // main_graph_node14(v1021, v1054, v1057, v1058);	// L1877
  // int8_t v1059[1][256][8][8];	// L1878
  // #pragma HLS stream variable=v1059 depth=256*8*8 type=fifo

  // #pragma HLS bind_storage variable=v1059 type=ram_t2p impl=bram

  // int8_t v1060[1][256][8][8];	// L1879
  // #pragma HLS stream variable=v1060 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1060 type=ram_t2p impl=bram

  // main_graph_node13(v1058, v1059, v1060);	// L1880
  // int8_t v1061[1][256][8][8];	// L1881
  // #pragma HLS stream variable=v1061 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1061 type=ram_t2p impl=bram

  // main_graph_node12(v1020, v1060, v1061);	// L1882
  // int8_t v1062[1][256][8][8];	// L1883
  // #pragma HLS stream variable=v1062 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1062 type=ram_t2p impl=bram

  // main_graph_node11(v1059, v1019, v1061, v1062);	// L1884
  // int8_t v1063[1][256][8][8];	// L1885
  // #pragma HLS stream variable=v1063 depth=256*8*8 type=fifo

  // #pragma HLS bind_storage variable=v1063 type=ram_t2p impl=bram

  // int8_t v1064[1][256][8][8];	// L1886
  // #pragma HLS stream variable=v1064 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1064 type=ram_t2p impl=bram

  // main_graph_node10(v1062, v1063, v1064);	// L1887
  // int8_t v1065[1][512][4][4];	// L1888
  // #pragma HLS stream variable=v1065 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1065 type=ram_t2p impl=bram

  // main_graph_node9(v1064, v1018, v1065);	// L1889
  // int8_t v1066[1][512][4][4];	// L1890
  // #pragma HLS stream variable=v1066 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1066 type=ram_t2p impl=bram

  // main_graph_node8(v1065, v1017, v1066);	// L1891
  // int8_t v1067[1][512][4][4];	// L1892
  // #pragma HLS stream variable=v1067 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1067 type=ram_t2p impl=bram

  // main_graph_node7(v1063, v1016, v1066, v1067);	// L1893
  // int8_t v1068[1][512][4][4];	// L1894
  // #pragma HLS stream variable=v1068 depth=512*4*4 type=fifo

  // #pragma HLS bind_storage variable=v1068 type=ram_t2p impl=bram

  // int8_t v1069[1][512][4][4];	// L1895
  // #pragma HLS stream variable=v1069 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1069 type=ram_t2p impl=bram

  // main_graph_node6(v1067, v1068, v1069);	// L1896
  // int8_t v1070[1][512][4][4];	// L1897
  // #pragma HLS stream variable=v1070 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1070 type=ram_t2p impl=bram

  // main_graph_node5(v1069, v1015, v1070);	// L1898
  // int8_t v1071[1][512][4][4];	// L1899
  // #pragma HLS stream variable=v1071 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1071 type=ram_t2p impl=bram

  // main_graph_node4(v1068, v1070, v1014, v1071);	// L1900
  // int8_t v1072[1][512][5][5];	// L1901
  // #pragma HLS bind_storage variable=v1072 type=ram_t2p impl=bram

  // main_graph_node3(v1071, v1072);	// L1902
  // int8_t v1073[1][1];	// L1903
  // #pragma HLS bind_storage variable=v1073 type=ram_t2p impl=bram

  // int8_t v1074[1][512][1][1];	// L1904
  // #pragma HLS bind_storage variable=v1074 type=ram_t2p impl=bram

  // main_graph_node2(v1072, v1074, v1073);	// L1905
  // int8_t v1075[1][512][1][1];	// L1906
  // #pragma HLS bind_storage variable=v1075 type=ram_t2p impl=bram

  // main_graph_node1(v1074, v1073, v1075);	// L1907
  // main_graph_node0(v1034, v1075, v1013, v1035);	// L1908
}

