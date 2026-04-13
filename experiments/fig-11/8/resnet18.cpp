
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
  int8_t v0[512][1000],
  int8_t v1[1000],
  int8_t v2[1][512][1][1],
  int8_t v3[1][1000]
) {	// L17
  #pragma HLS dataflow

  int8_t v4[1][1000];	// L19
  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  int8_t v5[1][1000];	// L20
  #pragma HLS bind_storage variable=v5 type=ram_t2p impl=bram

  for (int v6 = 0; v6 < 1; v6 += 1) {	// L21
    for (int v7 = 0; v7 < 1000; v7 += 1) {	// L22
      v4[v6][v7] = (int8_t)0.000000;	// L23
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L26
    for (int v9 = 0; v9 < 1000; v9 += 1) {	// L27
      for (int v10 = 0; v10 < 512; v10 += 1) {	// L28
        int8_t v11 = v2[v8][v10][0][0];	// L29
        int8_t v12 = v0[v10][v9];	// L30
        int8_t v13 = v4[v8][v9];	// L31
        int8_t v14 = v11 * v12;	// L32
        int8_t v15 = v13 + v14;	// L33
        v5[v8][v9] = v15;	// L34
      }
    }
  }
  for (int v16 = 0; v16 < 1; v16 += 1) {	// L38
    for (int v17 = 0; v17 < 1000; v17 += 1) {	// L39
      int8_t v18 = v5[0][v17];	// L40
      int8_t v19 = v1[v17];	// L41
      int8_t v20 = v18 + v19;	// L42
      v3[v16][v17] = v20;	// L43
    }
  }
}

void main_graph_node1(
  int8_t v21[1][512][1][1],
  int8_t v22[1][1],
  int8_t v23[1][512][1][1]
) {	// L48
  #pragma HLS dataflow

  int8_t v24[1][512][1][1];	// L49
  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L50
    for (int v26 = 0; v26 < 512; v26 += 1) {	// L51
      for (int v27 = 0; v27 < 1; v27 += 1) {	// L52
        for (int v28 = 0; v28 < 1; v28 += 1) {	// L53
          int8_t v29 = v21[v25][v26][v27][v28];	// L54
          v24[v25][v26][v27][v28] = v29;	// L55
          int8_t v30 = v22[v27][v28];	// L56
          int8_t v31 = v24[v25][v26][v27][v28];	// L57
          int8_t v32 = v31 / v30;	// L58
          v23[v25][v26][v27][v28] = v32;	// L59
        }
      }
    }
  }
}

void main_graph_node2(
  int8_t v33[1][512][8][8],
  int8_t v34[1][512][1][1],
  int8_t v35[1][1]
) {	// L66
  #pragma HLS dataflow

  int8_t v36[1][512][1][1];	// L70
  #pragma HLS bind_storage variable=v36 type=ram_t2p impl=bram

  for (int v37 = 0; v37 < 1; v37 += 1) {	// L71
    for (int v38 = 0; v38 < 512; v38 += 1) {	// L72
      for (int v39 = 0; v39 < 1; v39 += 1) {	// L73
        for (int v40 = 0; v40 < 1; v40 += 1) {	// L74
          v36[v37][v38][v39][v40] = (int8_t)0.000000;	// L75
        }
      }
    }
  }
  for (int v41 = 0; v41 < 1; v41 += 1) {	// L80
    for (int v42 = 0; v42 < 512; v42 += 1) {	// L81
      for (int v43 = 0; v43 < 1; v43 += 1) {	// L82
        for (int v44 = 0; v44 < 1; v44 += 1) {	// L83
          for (int v45 = 0; v45 < 7; v45 += 1) {	// L84
            for (int v46 = 0; v46 < 7; v46 += 1) {	// L85
              int8_t v47 = v36[v41][v42][v43][v44];	// L86
              int v48 = v43 * (int)7;	// L87
              int v49 = v43 + (int)1;	// L88
              int v50 = v49 * (int)7;	// L89
              int v51 = v44 * (int)7;	// L90
              int v52 = v44 + (int)1;	// L91
              int v53 = v52 * (int)7;	// L92
              int v54 = v48 + v45;	// L93
              int v55 = v51 + v46;	// L94
              int8_t v56 = v33[v41][v42][v54][v55];	// L95
              bool v57 = v54 < v50;	// L96
              int8_t v58 = v57 ? v56 : (int8_t)0.000000;	// L97
              bool v59 = v55 < v53;	// L98
              int8_t v60 = v59 ? v58 : (int8_t)0.000000;	// L99
              int8_t v61 = v60 + v47;	// L100
              int v62 = v50 - v48;	// L101
              int v63 = v53 - v51;	// L102
              int v64 = v62 * v63;	// L103
              ap_int<64> v65 = v64;	// L104
              int8_t v66 = v65;	// L105
              v34[v41][v42][v43][v44] = v61;	// L106
              v35[v41][v42] = v66;	// L107
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v67[1][512][7][7],
  int8_t v68[1][512][8][8]
) {	// L116
  #pragma HLS dataflow

  for (int v69 = 0; v69 < 1; v69 += 1) {	// L118
    for (int v70 = 0; v70 < 8; v70 += 1) {	// L119
      for (int v71 = 0; v71 < 8; v71 += 1) {	// L120
        for (int v72 = 0; v72 < 512; v72 += 1) {	// L121
          int8_t v73;	// L122
          v73 = (int8_t)0.000000;	// L123
          if (((-v70) + 6) >= 0 && ((-v71) + 6) >= 0) {	// L124
            int8_t v74 = v67[v69][v72][v70][v71];	// L125
            v73 = v74;	// L126
          }
          int8_t v75 = v73;	// L128
          v68[v69][v72][v70][v71] = v75;	// L129
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v76[1][512][7][7],
  int8_t v77[512][512][3][3],
  int8_t v78[1][512][7][7],
  int8_t v79[1][512][7][7]
) {	// L136
  #pragma HLS dataflow

  int8_t v80[1][512][9][9];	// L138
  #pragma HLS stream variable=v80 depth=10 type=fifo

  #pragma HLS bind_storage variable=v80 type=ram_t2p impl=bram

  for (int v81 = 0; v81 < 1; v81 += 1) {	// L139
    for (int v82 = 0; v82 < 9; v82 += 1) {	// L140
      for (int v83 = 0; v83 < 9; v83 += 1) {	// L141
        for (int v84 = 0; v84 < 512; v84 += 1) {	// L142
          int8_t v85;	// L143
          v85 = (int8_t)0.000000;	// L144
          if (((-v82) + 6) >= 0 && ((-v83) + 6) >= 0) {	// L145
            int8_t v86 = v76[v81][v84][v82][v83];	// L146
            v85 = v86;	// L147
          }
          int8_t v87 = v85;	// L149
          v80[v81][v84][v82][v83] = v87;	// L150
        }
      }
    }
  }
  int8_t v88[1][512][7][7];	// L155
  #pragma HLS stream variable=v88 depth=10 type=fifo

  #pragma HLS bind_storage variable=v88 type=ram_t2p impl=bram

  int8_t v89[1][512][3][9];	// L156
  #pragma HLS array_partition variable=v89 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v89 type=ram_2p impl=bram

  int8_t v90[1][512][3][3];	// L157
  #pragma HLS array_partition variable=v90 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v90 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v90 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v90 type=ram_2p impl=lutram

  for (int v91 = 0; v91 < 1; v91 += 1) {	// L158
    for (int v92 = 0; v92 < 9; v92 += 1) {	// L159
      for (int v93 = 0; v93 < 9; v93 += 1) {	// L160
        for (int v94 = 0; v94 < 512; v94 += 1) {	// L161
          int8_t v95 = v89[v91][v94][1][v93];	// L162
          v89[v91][v94][0][v93] = v95;	// L163
          int8_t v96 = v89[v91][v94][2][v93];	// L164
          v89[v91][v94][1][v93] = v96;	// L165
          int8_t v97 = v80[v91][v94][v92][v93];	// L166
          v89[v91][v94][2][v93] = v97;	// L167
        }
        if ((v92 - 2) >= 0) {	// L169
          for (int v98 = 0; v98 < 512; v98 += 1) {	// L170
            for (int v99 = 0; v99 < 3; v99 += 1) {	// L171
              int8_t v100 = v90[v91][v98][v99][1];	// L172
              v90[v91][v98][v99][0] = v100;	// L173
              int8_t v101 = v90[v91][v98][v99][2];	// L174
              v90[v91][v98][v99][1] = v101;	// L175
              int8_t v102 = v89[v91][v98][v99][v93];	// L176
              v90[v91][v98][v99][2] = v102;	// L177
            }
          }
          if ((v93 - 2) >= 0) {	// L180
            int8_t v103[512];	// L181
            #pragma HLS bind_storage variable=v103 type=ram_2p impl=bram

            for (int v104 = 0; v104 < 512; v104 += 1) {	// L182
              v103[v104] = (int8_t)0.000000;	// L183
              for (int v105 = 0; v105 < 64; v105 += 1) {	// L184
                #pragma HLS pipeline II=1
                for (int v106 = 0; v106 < 8; v106 += 1) {	// L185
                  for (int v107 = 0; v107 < 3; v107 += 1) {	// L186
                    for (int v108 = 0; v108 < 3; v108 += 1) {	// L187
                      int8_t v109 = v90[v91][(v106 + (v105 * 8))][v107][v108];	// L188
                      int8_t v110 = v77[v104][(v106 + (v105 * 8))][v107][v108];	// L189
                      int8_t v111 = v109 * v110;	// L190
                      int8_t v112 = v103[v104];	// L191
                      int8_t v113 = v112 + v111;	// L192
                      v103[v104] = v113;	// L193
                    }
                  }
                }
              }
              int8_t v114 = v103[v104];	// L198
              v88[v91][v104][(v92 - 2)][(v93 - 2)] = v114;	// L199
            }
          }
        }
      }
    }
  }
  for (int v115 = 0; v115 < 1; v115 += 1) {	// L206
    for (int v116 = 0; v116 < 7; v116 += 1) {	// L207
      for (int v117 = 0; v117 < 7; v117 += 1) {	// L208
        for (int v118 = 0; v118 < 512; v118 += 1) {	// L209
          int8_t v119 = v88[0][v118][v116][v117];	// L210
          int8_t v120 = v78[0][v118][v116][v117];	// L211
          int8_t v121 = v119 + v120;	// L212
          bool v122 = v121 > (int8_t)0.000000;	// L213
          int8_t v123 = v122 ? v121 : (int8_t)0.000000;	// L214
          v79[v115][v118][v116][v117] = v123;	// L215
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v124[1][512][7][7],
  int8_t v125[512][512][3][3],
  int8_t v126[1][512][7][7]
) {	// L222
  #pragma HLS dataflow

  int8_t v127[1][512][9][9];	// L224
  #pragma HLS stream variable=v127 depth=10 type=fifo

  #pragma HLS bind_storage variable=v127 type=ram_t2p impl=bram

  for (int v128 = 0; v128 < 1; v128 += 1) {	// L225
    for (int v129 = 0; v129 < 9; v129 += 1) {	// L226
      for (int v130 = 0; v130 < 9; v130 += 1) {	// L227
        for (int v131 = 0; v131 < 512; v131 += 1) {	// L228
          int8_t v132;	// L229
          v132 = (int8_t)0.000000;	// L230
          if (((-v129) + 6) >= 0 && ((-v130) + 6) >= 0) {	// L231
            int8_t v133 = v124[v128][v131][v129][v130];	// L232
            v132 = v133;	// L233
          }
          int8_t v134 = v132;	// L235
          v127[v128][v131][v129][v130] = v134;	// L236
        }
      }
    }
  }
  int8_t v135[1][512][7][7];	// L241
  #pragma HLS stream variable=v135 depth=10 type=fifo

  #pragma HLS bind_storage variable=v135 type=ram_t2p impl=bram

  int8_t v136[1][512][3][9];	// L242
  #pragma HLS array_partition variable=v136 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v136 type=ram_2p impl=bram

  int8_t v137[1][512][3][3];	// L243
  #pragma HLS array_partition variable=v137 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v137 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v137 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v137 type=ram_2p impl=lutram

  for (int v138 = 0; v138 < 1; v138 += 1) {	// L244
    for (int v139 = 0; v139 < 9; v139 += 1) {	// L245
      for (int v140 = 0; v140 < 9; v140 += 1) {	// L246
        for (int v141 = 0; v141 < 512; v141 += 1) {	// L247
          int8_t v142 = v136[v138][v141][1][v140];	// L248
          v136[v138][v141][0][v140] = v142;	// L249
          int8_t v143 = v136[v138][v141][2][v140];	// L250
          v136[v138][v141][1][v140] = v143;	// L251
          int8_t v144 = v127[v138][v141][v139][v140];	// L252
          v136[v138][v141][2][v140] = v144;	// L253
        }
        if ((v139 - 2) >= 0) {	// L255
          for (int v145 = 0; v145 < 512; v145 += 1) {	// L256
            for (int v146 = 0; v146 < 3; v146 += 1) {	// L257
              int8_t v147 = v137[v138][v145][v146][1];	// L258
              v137[v138][v145][v146][0] = v147;	// L259
              int8_t v148 = v137[v138][v145][v146][2];	// L260
              v137[v138][v145][v146][1] = v148;	// L261
              int8_t v149 = v136[v138][v145][v146][v140];	// L262
              v137[v138][v145][v146][2] = v149;	// L263
            }
          }
          if ((v140 - 2) >= 0) {	// L266
            int8_t v150[512];	// L267
            #pragma HLS bind_storage variable=v150 type=ram_2p impl=bram

            for (int v151 = 0; v151 < 512; v151 += 1) {	// L268
              v150[v151] = (int8_t)0.000000;	// L269
              for (int v152 = 0; v152 < 64; v152 += 1) {	// L270
                #pragma HLS pipeline II=1
                for (int v153 = 0; v153 < 8; v153 += 1) {	// L271
                  for (int v154 = 0; v154 < 3; v154 += 1) {	// L272
                    for (int v155 = 0; v155 < 3; v155 += 1) {	// L273
                      int8_t v156 = v137[v138][(v153 + (v152 * 8))][v154][v155];	// L274
                      int8_t v157 = v125[v151][(v153 + (v152 * 8))][v154][v155];	// L275
                      int8_t v158 = v156 * v157;	// L276
                      int8_t v159 = v150[v151];	// L277
                      int8_t v160 = v159 + v158;	// L278
                      v150[v151] = v160;	// L279
                    }
                  }
                }
              }
              int8_t v161 = v150[v151];	// L284
              v135[v138][v151][(v139 - 2)][(v140 - 2)] = v161;	// L285
            }
          }
        }
      }
    }
  }
  for (int v162 = 0; v162 < 1; v162 += 1) {	// L292
    for (int v163 = 0; v163 < 7; v163 += 1) {	// L293
      for (int v164 = 0; v164 < 7; v164 += 1) {	// L294
        for (int v165 = 0; v165 < 512; v165 += 1) {	// L295
          int8_t v166 = v135[0][v165][v163][v164];	// L296
          bool v167 = v166 > (int8_t)0.000000;	// L297
          int8_t v168 = v167 ? v166 : (int8_t)0.000000;	// L298
          v126[v162][v165][v163][v164] = v168;	// L299
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v169[1][512][7][7],
  int8_t v170[1][512][7][7],
  int8_t v171[1][512][7][7]
) {	// L306
  #pragma HLS dataflow

  for (int v172 = 0; v172 < 1; v172 += 1) {	// L307
    for (int v173 = 0; v173 < 7; v173 += 1) {	// L308
      for (int v174 = 0; v174 < 7; v174 += 1) {	// L309
        for (int v175 = 0; v175 < 512; v175 += 1) {	// L310
          int8_t v176 = v169[v172][v175][v173][v174];	// L311
          v170[v172][v175][v173][v174] = v176;	// L312
          int8_t v177 = v169[v172][v175][v173][v174];	// L313
          v171[v172][v175][v173][v174] = v177;	// L314
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v178[1][512][7][7],
  int8_t v179[1][256][14][14],
  int8_t v180[512][256][1][1],
  int8_t v181[1][512][7][7]
) {	// L321
  #pragma HLS dataflow

  int8_t v182[1][512][7][7];	// L323
  #pragma HLS stream variable=v182 depth=10 type=fifo

  #pragma HLS bind_storage variable=v182 type=ram_t2p impl=bram

  int8_t v183[1][256][1][14];	// L324
  #pragma HLS bind_storage variable=v183 type=ram_2p impl=bram

  int8_t v184[1][256][1][1];	// L325
  #pragma HLS array_partition variable=v184 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v184 type=ram_2p impl=lutram

  for (int v185 = 0; v185 < 1; v185 += 1) {	// L326
    for (int v186 = 0; v186 < 14; v186 += 1) {	// L327
      for (int v187 = 0; v187 < 14; v187 += 1) {	// L328
        for (int v188 = 0; v188 < 256; v188 += 1) {	// L329
          int8_t v189 = v179[v185][v188][v186][v187];	// L330
          v183[v185][v188][0][v187] = v189;	// L331
        }
        if ((v186 - 7) >= 0) {	// L333
          for (int v190 = 0; v190 < 256; v190 += 1) {	// L334
            for (int v191 = 0; v191 < 1; v191 += 1) {	// L335
              int8_t v192 = v183[v185][v190][v191][v187];	// L336
              v184[v185][v190][v191][0] = v192;	// L337
            }
          }
          if ((v187 - 7) >= 0) {	// L340
            int8_t v193[512];	// L341
            #pragma HLS bind_storage variable=v193 type=ram_2p impl=bram

            for (int v194 = 0; v194 < 512; v194 += 1) {	// L342
              v193[v194] = (int8_t)0.000000;	// L343
              for (int v195 = 0; v195 < 32; v195 += 1) {	// L344
                #pragma HLS pipeline II=1
                for (int v196 = 0; v196 < 8; v196 += 1) {	// L345
                  for (int v197 = 0; v197 < 1; v197 += 1) {	// L346
                    for (int v198 = 0; v198 < 1; v198 += 1) {	// L347
                      int8_t v199 = v184[v185][(v196 + (v195 * 8))][v197][v198];	// L348
                      int8_t v200 = v180[v194][(v196 + (v195 * 8))][v197][v198];	// L349
                      int8_t v201 = v199 * v200;	// L350
                      int8_t v202 = v193[v194];	// L351
                      int8_t v203 = v202 + v201;	// L352
                      v193[v194] = v203;	// L353
                    }
                  }
                }
              }
              int8_t v204 = v193[v194];	// L358
              v182[v185][v194][(v186 - 7)][(v187 - 7)] = v204;	// L359
            }
          }
        }
      }
    }
  }
  for (int v205 = 0; v205 < 1; v205 += 1) {	// L366
    for (int v206 = 0; v206 < 7; v206 += 1) {	// L367
      for (int v207 = 0; v207 < 7; v207 += 1) {	// L368
        for (int v208 = 0; v208 < 512; v208 += 1) {	// L369
          int8_t v209 = v178[0][v208][v206][v207];	// L370
          int8_t v210 = v182[0][v208][v206][v207];	// L371
          int8_t v211 = v209 + v210;	// L372
          bool v212 = v211 > (int8_t)0.000000;	// L373
          int8_t v213 = v212 ? v211 : (int8_t)0.000000;	// L374
          v181[v205][v208][v206][v207] = v213;	// L375
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v214[512][512][3][3],
  int8_t v215[1][512][7][7],
  int8_t v216[1][512][7][7]
) {	// L382
  #pragma HLS dataflow

  int8_t v217[1][512][9][9];	// L384
  #pragma HLS stream variable=v217 depth=10 type=fifo

  #pragma HLS bind_storage variable=v217 type=ram_t2p impl=bram

  for (int v218 = 0; v218 < 1; v218 += 1) {	// L385
    for (int v219 = 0; v219 < 9; v219 += 1) {	// L386
      for (int v220 = 0; v220 < 9; v220 += 1) {	// L387
        for (int v221 = 0; v221 < 512; v221 += 1) {	// L388
          int8_t v222;	// L389
          v222 = (int8_t)0.000000;	// L390
          if (((-v219) + 6) >= 0 && ((-v220) + 6) >= 0) {	// L391
            int8_t v223 = v215[v218][v221][v219][v220];	// L392
            v222 = v223;	// L393
          }
          int8_t v224 = v222;	// L395
          v217[v218][v221][v219][v220] = v224;	// L396
        }
      }
    }
  }
  int8_t v225[1][512][3][9];	// L401
  #pragma HLS array_partition variable=v225 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v225 type=ram_2p impl=bram

  int8_t v226[1][512][3][3];	// L402
  #pragma HLS array_partition variable=v226 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v226 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v226 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v226 type=ram_2p impl=lutram

  for (int v227 = 0; v227 < 1; v227 += 1) {	// L403
    for (int v228 = 0; v228 < 9; v228 += 1) {	// L404
      for (int v229 = 0; v229 < 9; v229 += 1) {	// L405
        for (int v230 = 0; v230 < 512; v230 += 1) {	// L406
          int8_t v231 = v225[v227][v230][1][v229];	// L407
          v225[v227][v230][0][v229] = v231;	// L408
          int8_t v232 = v225[v227][v230][2][v229];	// L409
          v225[v227][v230][1][v229] = v232;	// L410
          int8_t v233 = v217[v227][v230][v228][v229];	// L411
          v225[v227][v230][2][v229] = v233;	// L412
        }
        if ((v228 - 2) >= 0) {	// L414
          for (int v234 = 0; v234 < 512; v234 += 1) {	// L415
            for (int v235 = 0; v235 < 3; v235 += 1) {	// L416
              int8_t v236 = v226[v227][v234][v235][1];	// L417
              v226[v227][v234][v235][0] = v236;	// L418
              int8_t v237 = v226[v227][v234][v235][2];	// L419
              v226[v227][v234][v235][1] = v237;	// L420
              int8_t v238 = v225[v227][v234][v235][v229];	// L421
              v226[v227][v234][v235][2] = v238;	// L422
            }
          }
          if ((v229 - 2) >= 0) {	// L425
            int8_t v239[512];	// L426
            #pragma HLS bind_storage variable=v239 type=ram_2p impl=bram

            for (int v240 = 0; v240 < 512; v240 += 1) {	// L427
              v239[v240] = (int8_t)0.000000;	// L428
              for (int v241 = 0; v241 < 64; v241 += 1) {	// L429
                #pragma HLS pipeline II=1
                for (int v242 = 0; v242 < 8; v242 += 1) {	// L430
                  for (int v243 = 0; v243 < 3; v243 += 1) {	// L431
                    for (int v244 = 0; v244 < 3; v244 += 1) {	// L432
                      int8_t v245 = v226[v227][(v242 + (v241 * 8))][v243][v244];	// L433
                      int8_t v246 = v214[v240][(v242 + (v241 * 8))][v243][v244];	// L434
                      int8_t v247 = v245 * v246;	// L435
                      int8_t v248 = v239[v240];	// L436
                      int8_t v249 = v248 + v247;	// L437
                      v239[v240] = v249;	// L438
                    }
                  }
                }
              }
              int8_t v250 = v239[v240];	// L443
              v216[v227][v240][(v228 - 2)][(v229 - 2)] = v250;	// L444
            }
          }
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v251[1][256][14][14],
  int8_t v252[512][256][3][3],
  int8_t v253[1][512][7][7]
) {	// L453
  #pragma HLS dataflow

  int8_t v254[1][256][16][16];	// L455
  #pragma HLS stream variable=v254 depth=10 type=fifo

  #pragma HLS bind_storage variable=v254 type=ram_t2p impl=bram

  for (int v255 = 0; v255 < 1; v255 += 1) {	// L456
    for (int v256 = 0; v256 < 16; v256 += 1) {	// L457
      for (int v257 = 0; v257 < 16; v257 += 1) {	// L458
        for (int v258 = 0; v258 < 256; v258 += 1) {	// L459
          int8_t v259;	// L460
          v259 = (int8_t)0.000000;	// L461
          if (((-v256) + 13) >= 0 && ((-v257) + 13) >= 0) {	// L462
            int8_t v260 = v251[v255][v258][v256][v257];	// L463
            v259 = v260;	// L464
          }
          int8_t v261 = v259;	// L466
          v254[v255][v258][v256][v257] = v261;	// L467
        }
      }
    }
  }
  int8_t v262[1][512][7][7];	// L472
  #pragma HLS stream variable=v262 depth=10 type=fifo

  #pragma HLS bind_storage variable=v262 type=ram_t2p impl=bram

  int8_t v263[1][256][3][16];	// L473
  #pragma HLS array_partition variable=v263 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v263 type=ram_2p impl=bram

  int8_t v264[1][256][3][3];	// L474
  #pragma HLS array_partition variable=v264 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v264 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v264 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v264 type=ram_2p impl=lutram

  for (int v265 = 0; v265 < 1; v265 += 1) {	// L475
    for (int v266 = 0; v266 < 16; v266 += 1) {	// L476
      for (int v267 = 0; v267 < 16; v267 += 1) {	// L477
        for (int v268 = 0; v268 < 256; v268 += 1) {	// L478
          int8_t v269 = v263[v265][v268][1][v267];	// L479
          v263[v265][v268][0][v267] = v269;	// L480
          int8_t v270 = v263[v265][v268][2][v267];	// L481
          v263[v265][v268][1][v267] = v270;	// L482
          int8_t v271 = v254[v265][v268][v266][v267];	// L483
          v263[v265][v268][2][v267] = v271;	// L484
        }
        if ((v266 - 9) >= 0) {	// L486
          for (int v272 = 0; v272 < 256; v272 += 1) {	// L487
            for (int v273 = 0; v273 < 3; v273 += 1) {	// L488
              int8_t v274 = v264[v265][v272][v273][1];	// L489
              v264[v265][v272][v273][0] = v274;	// L490
              int8_t v275 = v264[v265][v272][v273][2];	// L491
              v264[v265][v272][v273][1] = v275;	// L492
              int8_t v276 = v263[v265][v272][v273][v267];	// L493
              v264[v265][v272][v273][2] = v276;	// L494
            }
          }
          if ((v267 - 9) >= 0) {	// L497
            int8_t v277[512];	// L498
            #pragma HLS bind_storage variable=v277 type=ram_2p impl=bram

            for (int v278 = 0; v278 < 512; v278 += 1) {	// L499
              v277[v278] = (int8_t)0.000000;	// L500
              for (int v279 = 0; v279 < 32; v279 += 1) {	// L501
                #pragma HLS pipeline II=1
                for (int v280 = 0; v280 < 8; v280 += 1) {	// L502
                  for (int v281 = 0; v281 < 3; v281 += 1) {	// L503
                    for (int v282 = 0; v282 < 3; v282 += 1) {	// L504
                      int8_t v283 = v264[v265][(v280 + (v279 * 8))][v281][v282];	// L505
                      int8_t v284 = v252[v278][(v280 + (v279 * 8))][v281][v282];	// L506
                      int8_t v285 = v283 * v284;	// L507
                      int8_t v286 = v277[v278];	// L508
                      int8_t v287 = v286 + v285;	// L509
                      v277[v278] = v287;	// L510
                    }
                  }
                }
              }
              int8_t v288 = v277[v278];	// L515
              v262[v265][v278][(v266 - 9)][(v267 - 9)] = v288;	// L516
            }
          }
        }
      }
    }
  }
  for (int v289 = 0; v289 < 1; v289 += 1) {	// L523
    for (int v290 = 0; v290 < 7; v290 += 1) {	// L524
      for (int v291 = 0; v291 < 7; v291 += 1) {	// L525
        for (int v292 = 0; v292 < 512; v292 += 1) {	// L526
          int8_t v293 = v262[0][v292][v290][v291];	// L527
          bool v294 = v293 > (int8_t)0.000000;	// L528
          int8_t v295 = v294 ? v293 : (int8_t)0.000000;	// L529
          v253[v289][v292][v290][v291] = v295;	// L530
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v296[1][256][14][14],
  int8_t v297[1][256][14][14],
  int8_t v298[1][256][14][14]
) {	// L537
  #pragma HLS dataflow

  for (int v299 = 0; v299 < 1; v299 += 1) {	// L538
    for (int v300 = 0; v300 < 14; v300 += 1) {	// L539
      for (int v301 = 0; v301 < 14; v301 += 1) {	// L540
        for (int v302 = 0; v302 < 256; v302 += 1) {	// L541
          int8_t v303 = v296[v299][v302][v300][v301];	// L542
          v297[v299][v302][v300][v301] = v303;	// L543
          int8_t v304 = v296[v299][v302][v300][v301];	// L544
          v298[v299][v302][v300][v301] = v304;	// L545
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v305[1][256][14][14],
  int8_t v306[1][256][14][14],
  int8_t v307[256][256][3][3],
  int8_t v308[1][256][14][14]
) {	// L552
  #pragma HLS dataflow

  int8_t v309[1][256][16][16];	// L554
  #pragma HLS stream variable=v309 depth=10 type=fifo

  #pragma HLS bind_storage variable=v309 type=ram_t2p impl=bram

  for (int v310 = 0; v310 < 1; v310 += 1) {	// L555
    for (int v311 = 0; v311 < 16; v311 += 1) {	// L556
      for (int v312 = 0; v312 < 16; v312 += 1) {	// L557
        for (int v313 = 0; v313 < 256; v313 += 1) {	// L558
          int8_t v314;	// L559
          v314 = (int8_t)0.000000;	// L560
          if (((-v311) + 13) >= 0 && ((-v312) + 13) >= 0) {	// L561
            int8_t v315 = v306[v310][v313][v311][v312];	// L562
            v314 = v315;	// L563
          }
          int8_t v316 = v314;	// L565
          v309[v310][v313][v311][v312] = v316;	// L566
        }
      }
    }
  }
  int8_t v317[1][256][14][14];	// L571
  #pragma HLS stream variable=v317 depth=10 type=fifo

  #pragma HLS bind_storage variable=v317 type=ram_t2p impl=bram

  int8_t v318[1][256][3][16];	// L572
  #pragma HLS array_partition variable=v318 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v318 type=ram_2p impl=bram

  int8_t v319[1][256][3][3];	// L573
  #pragma HLS array_partition variable=v319 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v319 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v319 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v319 type=ram_2p impl=lutram

  for (int v320 = 0; v320 < 1; v320 += 1) {	// L574
    for (int v321 = 0; v321 < 16; v321 += 1) {	// L575
      for (int v322 = 0; v322 < 16; v322 += 1) {	// L576
        for (int v323 = 0; v323 < 256; v323 += 1) {	// L577
          int8_t v324 = v318[v320][v323][1][v322];	// L578
          v318[v320][v323][0][v322] = v324;	// L579
          int8_t v325 = v318[v320][v323][2][v322];	// L580
          v318[v320][v323][1][v322] = v325;	// L581
          int8_t v326 = v309[v320][v323][v321][v322];	// L582
          v318[v320][v323][2][v322] = v326;	// L583
        }
        if ((v321 - 2) >= 0) {	// L585
          for (int v327 = 0; v327 < 256; v327 += 1) {	// L586
            for (int v328 = 0; v328 < 3; v328 += 1) {	// L587
              int8_t v329 = v319[v320][v327][v328][1];	// L588
              v319[v320][v327][v328][0] = v329;	// L589
              int8_t v330 = v319[v320][v327][v328][2];	// L590
              v319[v320][v327][v328][1] = v330;	// L591
              int8_t v331 = v318[v320][v327][v328][v322];	// L592
              v319[v320][v327][v328][2] = v331;	// L593
            }
          }
          if ((v322 - 2) >= 0) {	// L596
            int8_t v332[256];	// L597
            #pragma HLS bind_storage variable=v332 type=ram_2p impl=bram

            for (int v333 = 0; v333 < 256; v333 += 1) {	// L598
              v332[v333] = (int8_t)0.000000;	// L599
              for (int v334 = 0; v334 < 64; v334 += 1) {	// L600
                #pragma HLS pipeline II=1
                for (int v335 = 0; v335 < 4; v335 += 1) {	// L601
                  for (int v336 = 0; v336 < 3; v336 += 1) {	// L602
                    for (int v337 = 0; v337 < 3; v337 += 1) {	// L603
                      int8_t v338 = v319[v320][(v335 + (v334 * 4))][v336][v337];	// L604
                      int8_t v339 = v307[v333][(v335 + (v334 * 4))][v336][v337];	// L605
                      int8_t v340 = v338 * v339;	// L606
                      int8_t v341 = v332[v333];	// L607
                      int8_t v342 = v341 + v340;	// L608
                      v332[v333] = v342;	// L609
                    }
                  }
                }
              }
              int8_t v343 = v332[v333];	// L614
              v317[v320][v333][(v321 - 2)][(v322 - 2)] = v343;	// L615
            }
          }
        }
      }
    }
  }
  for (int v344 = 0; v344 < 1; v344 += 1) {	// L622
    for (int v345 = 0; v345 < 14; v345 += 1) {	// L623
      for (int v346 = 0; v346 < 14; v346 += 1) {	// L624
        for (int v347 = 0; v347 < 256; v347 += 1) {	// L625
          int8_t v348 = v317[0][v347][v345][v346];	// L626
          int8_t v349 = v305[0][v347][v345][v346];	// L627
          int8_t v350 = v348 + v349;	// L628
          bool v351 = v350 > (int8_t)0.000000;	// L629
          int8_t v352 = v351 ? v350 : (int8_t)0.000000;	// L630
          v308[v344][v347][v345][v346] = v352;	// L631
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v353[1][256][14][14],
  int8_t v354[256][256][3][3],
  int8_t v355[1][256][14][14]
) {	// L638
  #pragma HLS dataflow

  int8_t v356[1][256][16][16];	// L640
  #pragma HLS stream variable=v356 depth=10 type=fifo

  #pragma HLS bind_storage variable=v356 type=ram_t2p impl=bram

  for (int v357 = 0; v357 < 1; v357 += 1) {	// L641
    for (int v358 = 0; v358 < 16; v358 += 1) {	// L642
      for (int v359 = 0; v359 < 16; v359 += 1) {	// L643
        for (int v360 = 0; v360 < 256; v360 += 1) {	// L644
          int8_t v361;	// L645
          v361 = (int8_t)0.000000;	// L646
          if (((-v358) + 13) >= 0 && ((-v359) + 13) >= 0) {	// L647
            int8_t v362 = v353[v357][v360][v358][v359];	// L648
            v361 = v362;	// L649
          }
          int8_t v363 = v361;	// L651
          v356[v357][v360][v358][v359] = v363;	// L652
        }
      }
    }
  }
  int8_t v364[1][256][14][14];	// L657
  #pragma HLS stream variable=v364 depth=10 type=fifo

  #pragma HLS bind_storage variable=v364 type=ram_t2p impl=bram

  int8_t v365[1][256][3][16];	// L658
  #pragma HLS array_partition variable=v365 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v365 type=ram_2p impl=bram

  int8_t v366[1][256][3][3];	// L659
  #pragma HLS array_partition variable=v366 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v366 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v366 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v366 type=ram_2p impl=lutram

  for (int v367 = 0; v367 < 1; v367 += 1) {	// L660
    for (int v368 = 0; v368 < 16; v368 += 1) {	// L661
      for (int v369 = 0; v369 < 16; v369 += 1) {	// L662
        for (int v370 = 0; v370 < 256; v370 += 1) {	// L663
          int8_t v371 = v365[v367][v370][1][v369];	// L664
          v365[v367][v370][0][v369] = v371;	// L665
          int8_t v372 = v365[v367][v370][2][v369];	// L666
          v365[v367][v370][1][v369] = v372;	// L667
          int8_t v373 = v356[v367][v370][v368][v369];	// L668
          v365[v367][v370][2][v369] = v373;	// L669
        }
        if ((v368 - 2) >= 0) {	// L671
          for (int v374 = 0; v374 < 256; v374 += 1) {	// L672
            for (int v375 = 0; v375 < 3; v375 += 1) {	// L673
              int8_t v376 = v366[v367][v374][v375][1];	// L674
              v366[v367][v374][v375][0] = v376;	// L675
              int8_t v377 = v366[v367][v374][v375][2];	// L676
              v366[v367][v374][v375][1] = v377;	// L677
              int8_t v378 = v365[v367][v374][v375][v369];	// L678
              v366[v367][v374][v375][2] = v378;	// L679
            }
          }
          if ((v369 - 2) >= 0) {	// L682
            int8_t v379[256];	// L683
            #pragma HLS bind_storage variable=v379 type=ram_2p impl=bram

            for (int v380 = 0; v380 < 256; v380 += 1) {	// L684
              v379[v380] = (int8_t)0.000000;	// L685
              for (int v381 = 0; v381 < 64; v381 += 1) {	// L686
                #pragma HLS pipeline II=1
                for (int v382 = 0; v382 < 4; v382 += 1) {	// L687
                  for (int v383 = 0; v383 < 3; v383 += 1) {	// L688
                    for (int v384 = 0; v384 < 3; v384 += 1) {	// L689
                      int8_t v385 = v366[v367][(v382 + (v381 * 4))][v383][v384];	// L690
                      int8_t v386 = v354[v380][(v382 + (v381 * 4))][v383][v384];	// L691
                      int8_t v387 = v385 * v386;	// L692
                      int8_t v388 = v379[v380];	// L693
                      int8_t v389 = v388 + v387;	// L694
                      v379[v380] = v389;	// L695
                    }
                  }
                }
              }
              int8_t v390 = v379[v380];	// L700
              v364[v367][v380][(v368 - 2)][(v369 - 2)] = v390;	// L701
            }
          }
        }
      }
    }
  }
  for (int v391 = 0; v391 < 1; v391 += 1) {	// L708
    for (int v392 = 0; v392 < 14; v392 += 1) {	// L709
      for (int v393 = 0; v393 < 14; v393 += 1) {	// L710
        for (int v394 = 0; v394 < 256; v394 += 1) {	// L711
          int8_t v395 = v364[0][v394][v392][v393];	// L712
          bool v396 = v395 > (int8_t)0.000000;	// L713
          int8_t v397 = v396 ? v395 : (int8_t)0.000000;	// L714
          v355[v391][v394][v392][v393] = v397;	// L715
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v398[1][256][14][14],
  int8_t v399[1][256][14][14],
  int8_t v400[1][256][14][14]
) {	// L722
  #pragma HLS dataflow

  for (int v401 = 0; v401 < 1; v401 += 1) {	// L723
    for (int v402 = 0; v402 < 14; v402 += 1) {	// L724
      for (int v403 = 0; v403 < 14; v403 += 1) {	// L725
        for (int v404 = 0; v404 < 256; v404 += 1) {	// L726
          int8_t v405 = v398[v401][v404][v402][v403];	// L727
          v399[v401][v404][v402][v403] = v405;	// L728
          int8_t v406 = v398[v401][v404][v402][v403];	// L729
          v400[v401][v404][v402][v403] = v406;	// L730
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v407[1][128][28][28],
  int8_t v408[256][128][1][1],
  int8_t v409[1][256][14][14],
  int8_t v410[1][256][14][14]
) {	// L737
  #pragma HLS dataflow

  int8_t v411[1][256][14][14];	// L739
  #pragma HLS stream variable=v411 depth=10 type=fifo

  #pragma HLS bind_storage variable=v411 type=ram_t2p impl=bram

  int8_t v412[1][128][1][28];	// L740
  #pragma HLS bind_storage variable=v412 type=ram_2p impl=bram

  int8_t v413[1][128][1][1];	// L741
  #pragma HLS array_partition variable=v413 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v413 type=ram_2p impl=lutram

  for (int v414 = 0; v414 < 1; v414 += 1) {	// L742
    for (int v415 = 0; v415 < 28; v415 += 1) {	// L743
      for (int v416 = 0; v416 < 28; v416 += 1) {	// L744
        for (int v417 = 0; v417 < 128; v417 += 1) {	// L745
          int8_t v418 = v407[v414][v417][v415][v416];	// L746
          v412[v414][v417][0][v416] = v418;	// L747
        }
        if ((v415 - 14) >= 0) {	// L749
          for (int v419 = 0; v419 < 128; v419 += 1) {	// L750
            for (int v420 = 0; v420 < 1; v420 += 1) {	// L751
              int8_t v421 = v412[v414][v419][v420][v416];	// L752
              v413[v414][v419][v420][0] = v421;	// L753
            }
          }
          if ((v416 - 14) >= 0) {	// L756
            int8_t v422[256];	// L757
            #pragma HLS bind_storage variable=v422 type=ram_2p impl=bram

            for (int v423 = 0; v423 < 256; v423 += 1) {	// L758
              v422[v423] = (int8_t)0.000000;	// L759
              for (int v424 = 0; v424 < 16; v424 += 1) {	// L760
                #pragma HLS pipeline II=1
                for (int v425 = 0; v425 < 8; v425 += 1) {	// L761
                  for (int v426 = 0; v426 < 1; v426 += 1) {	// L762
                    for (int v427 = 0; v427 < 1; v427 += 1) {	// L763
                      int8_t v428 = v413[v414][(v425 + (v424 * 8))][v426][v427];	// L764
                      int8_t v429 = v408[v423][(v425 + (v424 * 8))][v426][v427];	// L765
                      int8_t v430 = v428 * v429;	// L766
                      int8_t v431 = v422[v423];	// L767
                      int8_t v432 = v431 + v430;	// L768
                      v422[v423] = v432;	// L769
                    }
                  }
                }
              }
              int8_t v433 = v422[v423];	// L774
              v411[v414][v423][(v415 - 14)][(v416 - 14)] = v433;	// L775
            }
          }
        }
      }
    }
  }
  for (int v434 = 0; v434 < 1; v434 += 1) {	// L782
    for (int v435 = 0; v435 < 14; v435 += 1) {	// L783
      for (int v436 = 0; v436 < 14; v436 += 1) {	// L784
        for (int v437 = 0; v437 < 256; v437 += 1) {	// L785
          int8_t v438 = v409[0][v437][v435][v436];	// L786
          int8_t v439 = v411[0][v437][v435][v436];	// L787
          int8_t v440 = v438 + v439;	// L788
          bool v441 = v440 > (int8_t)0.000000;	// L789
          int8_t v442 = v441 ? v440 : (int8_t)0.000000;	// L790
          v410[v434][v437][v435][v436] = v442;	// L791
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v443[1][256][14][14],
  int8_t v444[256][256][3][3],
  int8_t v445[1][256][14][14]
) {	// L798
  #pragma HLS dataflow

  int8_t v446[1][256][16][16];	// L800
  #pragma HLS stream variable=v446 depth=10 type=fifo

  #pragma HLS bind_storage variable=v446 type=ram_t2p impl=bram

  for (int v447 = 0; v447 < 1; v447 += 1) {	// L801
    for (int v448 = 0; v448 < 16; v448 += 1) {	// L802
      for (int v449 = 0; v449 < 16; v449 += 1) {	// L803
        for (int v450 = 0; v450 < 256; v450 += 1) {	// L804
          int8_t v451;	// L805
          v451 = (int8_t)0.000000;	// L806
          if (((-v448) + 13) >= 0 && ((-v449) + 13) >= 0) {	// L807
            int8_t v452 = v443[v447][v450][v448][v449];	// L808
            v451 = v452;	// L809
          }
          int8_t v453 = v451;	// L811
          v446[v447][v450][v448][v449] = v453;	// L812
        }
      }
    }
  }
  int8_t v454[1][256][3][16];	// L817
  #pragma HLS array_partition variable=v454 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v454 type=ram_2p impl=bram

  int8_t v455[1][256][3][3];	// L818
  #pragma HLS array_partition variable=v455 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v455 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v455 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v455 type=ram_2p impl=lutram

  for (int v456 = 0; v456 < 1; v456 += 1) {	// L819
    for (int v457 = 0; v457 < 16; v457 += 1) {	// L820
      for (int v458 = 0; v458 < 16; v458 += 1) {	// L821
        for (int v459 = 0; v459 < 256; v459 += 1) {	// L822
          int8_t v460 = v454[v456][v459][1][v458];	// L823
          v454[v456][v459][0][v458] = v460;	// L824
          int8_t v461 = v454[v456][v459][2][v458];	// L825
          v454[v456][v459][1][v458] = v461;	// L826
          int8_t v462 = v446[v456][v459][v457][v458];	// L827
          v454[v456][v459][2][v458] = v462;	// L828
        }
        if ((v457 - 2) >= 0) {	// L830
          for (int v463 = 0; v463 < 256; v463 += 1) {	// L831
            for (int v464 = 0; v464 < 3; v464 += 1) {	// L832
              int8_t v465 = v455[v456][v463][v464][1];	// L833
              v455[v456][v463][v464][0] = v465;	// L834
              int8_t v466 = v455[v456][v463][v464][2];	// L835
              v455[v456][v463][v464][1] = v466;	// L836
              int8_t v467 = v454[v456][v463][v464][v458];	// L837
              v455[v456][v463][v464][2] = v467;	// L838
            }
          }
          if ((v458 - 2) >= 0) {	// L841
            int8_t v468[256];	// L842
            #pragma HLS bind_storage variable=v468 type=ram_2p impl=bram

            for (int v469 = 0; v469 < 256; v469 += 1) {	// L843
              v468[v469] = (int8_t)0.000000;	// L844
              for (int v470 = 0; v470 < 64; v470 += 1) {	// L845
                #pragma HLS pipeline II=1
                for (int v471 = 0; v471 < 4; v471 += 1) {	// L846
                  for (int v472 = 0; v472 < 3; v472 += 1) {	// L847
                    for (int v473 = 0; v473 < 3; v473 += 1) {	// L848
                      int8_t v474 = v455[v456][(v471 + (v470 * 4))][v472][v473];	// L849
                      int8_t v475 = v444[v469][(v471 + (v470 * 4))][v472][v473];	// L850
                      int8_t v476 = v474 * v475;	// L851
                      int8_t v477 = v468[v469];	// L852
                      int8_t v478 = v477 + v476;	// L853
                      v468[v469] = v478;	// L854
                    }
                  }
                }
              }
              int8_t v479 = v468[v469];	// L859
              v445[v456][v469][(v457 - 2)][(v458 - 2)] = v479;	// L860
            }
          }
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v480[1][128][28][28],
  int8_t v481[256][128][3][3],
  int8_t v482[1][256][14][14]
) {	// L869
  #pragma HLS dataflow

  int8_t v483[1][128][30][30];	// L871
  #pragma HLS stream variable=v483 depth=10 type=fifo

  #pragma HLS bind_storage variable=v483 type=ram_t2p impl=bram

  for (int v484 = 0; v484 < 1; v484 += 1) {	// L872
    for (int v485 = 0; v485 < 30; v485 += 1) {	// L873
      for (int v486 = 0; v486 < 30; v486 += 1) {	// L874
        for (int v487 = 0; v487 < 128; v487 += 1) {	// L875
          int8_t v488;	// L876
          v488 = (int8_t)0.000000;	// L877
          if (((-v485) + 27) >= 0 && ((-v486) + 27) >= 0) {	// L878
            int8_t v489 = v480[v484][v487][v485][v486];	// L879
            v488 = v489;	// L880
          }
          int8_t v490 = v488;	// L882
          v483[v484][v487][v485][v486] = v490;	// L883
        }
      }
    }
  }
  int8_t v491[1][256][14][14];	// L888
  #pragma HLS stream variable=v491 depth=10 type=fifo

  #pragma HLS bind_storage variable=v491 type=ram_t2p impl=bram

  int8_t v492[1][128][3][30];	// L889
  #pragma HLS array_partition variable=v492 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v492 type=ram_2p impl=bram

  int8_t v493[1][128][3][3];	// L890
  #pragma HLS array_partition variable=v493 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v493 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v493 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v493 type=ram_2p impl=lutram

  for (int v494 = 0; v494 < 1; v494 += 1) {	// L891
    for (int v495 = 0; v495 < 30; v495 += 1) {	// L892
      for (int v496 = 0; v496 < 30; v496 += 1) {	// L893
        for (int v497 = 0; v497 < 128; v497 += 1) {	// L894
          int8_t v498 = v492[v494][v497][1][v496];	// L895
          v492[v494][v497][0][v496] = v498;	// L896
          int8_t v499 = v492[v494][v497][2][v496];	// L897
          v492[v494][v497][1][v496] = v499;	// L898
          int8_t v500 = v483[v494][v497][v495][v496];	// L899
          v492[v494][v497][2][v496] = v500;	// L900
        }
        if ((v495 - 16) >= 0) {	// L902
          for (int v501 = 0; v501 < 128; v501 += 1) {	// L903
            for (int v502 = 0; v502 < 3; v502 += 1) {	// L904
              int8_t v503 = v493[v494][v501][v502][1];	// L905
              v493[v494][v501][v502][0] = v503;	// L906
              int8_t v504 = v493[v494][v501][v502][2];	// L907
              v493[v494][v501][v502][1] = v504;	// L908
              int8_t v505 = v492[v494][v501][v502][v496];	// L909
              v493[v494][v501][v502][2] = v505;	// L910
            }
          }
          if ((v496 - 16) >= 0) {	// L913
            int8_t v506[256];	// L914
            #pragma HLS bind_storage variable=v506 type=ram_2p impl=bram

            for (int v507 = 0; v507 < 256; v507 += 1) {	// L915
              v506[v507] = (int8_t)0.000000;	// L916
              for (int v508 = 0; v508 < 16; v508 += 1) {	// L917
                #pragma HLS pipeline II=1
                for (int v509 = 0; v509 < 8; v509 += 1) {	// L918
                  for (int v510 = 0; v510 < 3; v510 += 1) {	// L919
                    for (int v511 = 0; v511 < 3; v511 += 1) {	// L920
                      int8_t v512 = v493[v494][(v509 + (v508 * 8))][v510][v511];	// L921
                      int8_t v513 = v481[v507][(v509 + (v508 * 8))][v510][v511];	// L922
                      int8_t v514 = v512 * v513;	// L923
                      int8_t v515 = v506[v507];	// L924
                      int8_t v516 = v515 + v514;	// L925
                      v506[v507] = v516;	// L926
                    }
                  }
                }
              }
              int8_t v517 = v506[v507];	// L931
              v491[v494][v507][(v495 - 16)][(v496 - 16)] = v517;	// L932
            }
          }
        }
      }
    }
  }
  for (int v518 = 0; v518 < 1; v518 += 1) {	// L939
    for (int v519 = 0; v519 < 14; v519 += 1) {	// L940
      for (int v520 = 0; v520 < 14; v520 += 1) {	// L941
        for (int v521 = 0; v521 < 256; v521 += 1) {	// L942
          int8_t v522 = v491[0][v521][v519][v520];	// L943
          bool v523 = v522 > (int8_t)0.000000;	// L944
          int8_t v524 = v523 ? v522 : (int8_t)0.000000;	// L945
          v482[v518][v521][v519][v520] = v524;	// L946
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v525[1][128][28][28],
  int8_t v526[1][128][28][28],
  int8_t v527[1][128][28][28]
) {	// L953
  #pragma HLS dataflow

  for (int v528 = 0; v528 < 1; v528 += 1) {	// L954
    for (int v529 = 0; v529 < 28; v529 += 1) {	// L955
      for (int v530 = 0; v530 < 28; v530 += 1) {	// L956
        for (int v531 = 0; v531 < 128; v531 += 1) {	// L957
          int8_t v532 = v525[v528][v531][v529][v530];	// L958
          v526[v528][v531][v529][v530] = v532;	// L959
          int8_t v533 = v525[v528][v531][v529][v530];	// L960
          v527[v528][v531][v529][v530] = v533;	// L961
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v534[1][128][28][28],
  int8_t v535[1][128][28][28],
  int8_t v536[128][128][3][3],
  int8_t v537[1][128][28][28]
) {	// L968
  #pragma HLS dataflow

  int8_t v538[1][128][30][30];	// L970
  #pragma HLS stream variable=v538 depth=10 type=fifo

  #pragma HLS bind_storage variable=v538 type=ram_t2p impl=bram

  for (int v539 = 0; v539 < 1; v539 += 1) {	// L971
    for (int v540 = 0; v540 < 30; v540 += 1) {	// L972
      for (int v541 = 0; v541 < 30; v541 += 1) {	// L973
        for (int v542 = 0; v542 < 128; v542 += 1) {	// L974
          int8_t v543;	// L975
          v543 = (int8_t)0.000000;	// L976
          if (((-v540) + 27) >= 0 && ((-v541) + 27) >= 0) {	// L977
            int8_t v544 = v535[v539][v542][v540][v541];	// L978
            v543 = v544;	// L979
          }
          int8_t v545 = v543;	// L981
          v538[v539][v542][v540][v541] = v545;	// L982
        }
      }
    }
  }
  int8_t v546[1][128][28][28];	// L987
  #pragma HLS stream variable=v546 depth=10 type=fifo

  #pragma HLS bind_storage variable=v546 type=ram_t2p impl=bram

  int8_t v547[1][128][3][30];	// L988
  #pragma HLS array_partition variable=v547 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v547 type=ram_2p impl=bram

  int8_t v548[1][128][3][3];	// L989
  #pragma HLS array_partition variable=v548 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v548 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v548 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v548 type=ram_2p impl=lutram

  for (int v549 = 0; v549 < 1; v549 += 1) {	// L990
    for (int v550 = 0; v550 < 30; v550 += 1) {	// L991
      for (int v551 = 0; v551 < 30; v551 += 1) {	// L992
        for (int v552 = 0; v552 < 128; v552 += 1) {	// L993
          int8_t v553 = v547[v549][v552][1][v551];	// L994
          v547[v549][v552][0][v551] = v553;	// L995
          int8_t v554 = v547[v549][v552][2][v551];	// L996
          v547[v549][v552][1][v551] = v554;	// L997
          int8_t v555 = v538[v549][v552][v550][v551];	// L998
          v547[v549][v552][2][v551] = v555;	// L999
        }
        if ((v550 - 2) >= 0) {	// L1001
          for (int v556 = 0; v556 < 128; v556 += 1) {	// L1002
            for (int v557 = 0; v557 < 3; v557 += 1) {	// L1003
              int8_t v558 = v548[v549][v556][v557][1];	// L1004
              v548[v549][v556][v557][0] = v558;	// L1005
              int8_t v559 = v548[v549][v556][v557][2];	// L1006
              v548[v549][v556][v557][1] = v559;	// L1007
              int8_t v560 = v547[v549][v556][v557][v551];	// L1008
              v548[v549][v556][v557][2] = v560;	// L1009
            }
          }
          if ((v551 - 2) >= 0) {	// L1012
            int8_t v561[128];	// L1013
            #pragma HLS bind_storage variable=v561 type=ram_2p impl=bram

            for (int v562 = 0; v562 < 128; v562 += 1) {	// L1014
              v561[v562] = (int8_t)0.000000;	// L1015
              for (int v563 = 0; v563 < 32; v563 += 1) {	// L1016
                #pragma HLS pipeline II=1
                for (int v564 = 0; v564 < 4; v564 += 1) {	// L1017
                  for (int v565 = 0; v565 < 3; v565 += 1) {	// L1018
                    for (int v566 = 0; v566 < 3; v566 += 1) {	// L1019
                      int8_t v567 = v548[v549][(v564 + (v563 * 4))][v565][v566];	// L1020
                      int8_t v568 = v536[v562][(v564 + (v563 * 4))][v565][v566];	// L1021
                      int8_t v569 = v567 * v568;	// L1022
                      int8_t v570 = v561[v562];	// L1023
                      int8_t v571 = v570 + v569;	// L1024
                      v561[v562] = v571;	// L1025
                    }
                  }
                }
              }
              int8_t v572 = v561[v562];	// L1030
              v546[v549][v562][(v550 - 2)][(v551 - 2)] = v572;	// L1031
            }
          }
        }
      }
    }
  }
  for (int v573 = 0; v573 < 1; v573 += 1) {	// L1038
    for (int v574 = 0; v574 < 28; v574 += 1) {	// L1039
      for (int v575 = 0; v575 < 28; v575 += 1) {	// L1040
        for (int v576 = 0; v576 < 128; v576 += 1) {	// L1041
          int8_t v577 = v546[0][v576][v574][v575];	// L1042
          int8_t v578 = v534[0][v576][v574][v575];	// L1043
          int8_t v579 = v577 + v578;	// L1044
          bool v580 = v579 > (int8_t)0.000000;	// L1045
          int8_t v581 = v580 ? v579 : (int8_t)0.000000;	// L1046
          v537[v573][v576][v574][v575] = v581;	// L1047
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v582[1][128][28][28],
  int8_t v583[128][128][3][3],
  int8_t v584[1][128][28][28]
) {	// L1054
  #pragma HLS dataflow

  int8_t v585[1][128][30][30];	// L1056
  #pragma HLS stream variable=v585 depth=10 type=fifo

  #pragma HLS bind_storage variable=v585 type=ram_t2p impl=bram

  for (int v586 = 0; v586 < 1; v586 += 1) {	// L1057
    for (int v587 = 0; v587 < 30; v587 += 1) {	// L1058
      for (int v588 = 0; v588 < 30; v588 += 1) {	// L1059
        for (int v589 = 0; v589 < 128; v589 += 1) {	// L1060
          int8_t v590;	// L1061
          v590 = (int8_t)0.000000;	// L1062
          if (((-v587) + 27) >= 0 && ((-v588) + 27) >= 0) {	// L1063
            int8_t v591 = v582[v586][v589][v587][v588];	// L1064
            v590 = v591;	// L1065
          }
          int8_t v592 = v590;	// L1067
          v585[v586][v589][v587][v588] = v592;	// L1068
        }
      }
    }
  }
  int8_t v593[1][128][28][28];	// L1073
  #pragma HLS stream variable=v593 depth=10 type=fifo

  #pragma HLS bind_storage variable=v593 type=ram_t2p impl=bram

  int8_t v594[1][128][3][30];	// L1074
  #pragma HLS array_partition variable=v594 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v594 type=ram_2p impl=bram

  int8_t v595[1][128][3][3];	// L1075
  #pragma HLS array_partition variable=v595 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v595 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v595 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v595 type=ram_2p impl=lutram

  for (int v596 = 0; v596 < 1; v596 += 1) {	// L1076
    for (int v597 = 0; v597 < 30; v597 += 1) {	// L1077
      for (int v598 = 0; v598 < 30; v598 += 1) {	// L1078
        for (int v599 = 0; v599 < 128; v599 += 1) {	// L1079
          int8_t v600 = v594[v596][v599][1][v598];	// L1080
          v594[v596][v599][0][v598] = v600;	// L1081
          int8_t v601 = v594[v596][v599][2][v598];	// L1082
          v594[v596][v599][1][v598] = v601;	// L1083
          int8_t v602 = v585[v596][v599][v597][v598];	// L1084
          v594[v596][v599][2][v598] = v602;	// L1085
        }
        if ((v597 - 2) >= 0) {	// L1087
          for (int v603 = 0; v603 < 128; v603 += 1) {	// L1088
            for (int v604 = 0; v604 < 3; v604 += 1) {	// L1089
              int8_t v605 = v595[v596][v603][v604][1];	// L1090
              v595[v596][v603][v604][0] = v605;	// L1091
              int8_t v606 = v595[v596][v603][v604][2];	// L1092
              v595[v596][v603][v604][1] = v606;	// L1093
              int8_t v607 = v594[v596][v603][v604][v598];	// L1094
              v595[v596][v603][v604][2] = v607;	// L1095
            }
          }
          if ((v598 - 2) >= 0) {	// L1098
            int8_t v608[128];	// L1099
            #pragma HLS bind_storage variable=v608 type=ram_2p impl=bram

            for (int v609 = 0; v609 < 128; v609 += 1) {	// L1100
              v608[v609] = (int8_t)0.000000;	// L1101
              for (int v610 = 0; v610 < 32; v610 += 1) {	// L1102
                #pragma HLS pipeline II=1
                for (int v611 = 0; v611 < 4; v611 += 1) {	// L1103
                  for (int v612 = 0; v612 < 3; v612 += 1) {	// L1104
                    for (int v613 = 0; v613 < 3; v613 += 1) {	// L1105
                      int8_t v614 = v595[v596][(v611 + (v610 * 4))][v612][v613];	// L1106
                      int8_t v615 = v583[v609][(v611 + (v610 * 4))][v612][v613];	// L1107
                      int8_t v616 = v614 * v615;	// L1108
                      int8_t v617 = v608[v609];	// L1109
                      int8_t v618 = v617 + v616;	// L1110
                      v608[v609] = v618;	// L1111
                    }
                  }
                }
              }
              int8_t v619 = v608[v609];	// L1116
              v593[v596][v609][(v597 - 2)][(v598 - 2)] = v619;	// L1117
            }
          }
        }
      }
    }
  }
  for (int v620 = 0; v620 < 1; v620 += 1) {	// L1124
    for (int v621 = 0; v621 < 28; v621 += 1) {	// L1125
      for (int v622 = 0; v622 < 28; v622 += 1) {	// L1126
        for (int v623 = 0; v623 < 128; v623 += 1) {	// L1127
          int8_t v624 = v593[0][v623][v621][v622];	// L1128
          bool v625 = v624 > (int8_t)0.000000;	// L1129
          int8_t v626 = v625 ? v624 : (int8_t)0.000000;	// L1130
          v584[v620][v623][v621][v622] = v626;	// L1131
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v627[1][128][28][28],
  int8_t v628[1][128][28][28],
  int8_t v629[1][128][28][28]
) {	// L1138
  #pragma HLS dataflow

  for (int v630 = 0; v630 < 1; v630 += 1) {	// L1139
    for (int v631 = 0; v631 < 28; v631 += 1) {	// L1140
      for (int v632 = 0; v632 < 28; v632 += 1) {	// L1141
        for (int v633 = 0; v633 < 128; v633 += 1) {	// L1142
          int8_t v634 = v627[v630][v633][v631][v632];	// L1143
          v628[v630][v633][v631][v632] = v634;	// L1144
          int8_t v635 = v627[v630][v633][v631][v632];	// L1145
          v629[v630][v633][v631][v632] = v635;	// L1146
        }
      }
    }
  }
}

void main_graph_node21(
  int8_t v636[128][64][1][1],
  int8_t v637[1][128][28][28],
  int8_t v638[1][64][56][56],
  int8_t v639[1][128][28][28]
) {	// L1153
  #pragma HLS dataflow

  int8_t v640[1][128][28][28];	// L1155
  #pragma HLS stream variable=v640 depth=10 type=fifo

  #pragma HLS bind_storage variable=v640 type=ram_t2p impl=bram

  int8_t v641[1][64][1][56];	// L1156
  #pragma HLS bind_storage variable=v641 type=ram_2p impl=bram

  int8_t v642[1][64][1][1];	// L1157
  #pragma HLS array_partition variable=v642 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v642 type=ram_2p impl=lutram

  for (int v643 = 0; v643 < 1; v643 += 1) {	// L1158
    for (int v644 = 0; v644 < 56; v644 += 1) {	// L1159
      for (int v645 = 0; v645 < 56; v645 += 1) {	// L1160
        for (int v646 = 0; v646 < 64; v646 += 1) {	// L1161
          int8_t v647 = v638[v643][v646][v644][v645];	// L1162
          v641[v643][v646][0][v645] = v647;	// L1163
        }
        if ((v644 - 28) >= 0) {	// L1165
          for (int v648 = 0; v648 < 64; v648 += 1) {	// L1166
            for (int v649 = 0; v649 < 1; v649 += 1) {	// L1167
              int8_t v650 = v641[v643][v648][v649][v645];	// L1168
              v642[v643][v648][v649][0] = v650;	// L1169
            }
          }
          if ((v645 - 28) >= 0) {	// L1172
            int8_t v651[128];	// L1173
            #pragma HLS bind_storage variable=v651 type=ram_2p impl=bram

            for (int v652 = 0; v652 < 128; v652 += 1) {	// L1174
              v651[v652] = (int8_t)0.000000;	// L1175
              for (int v653 = 0; v653 < 8; v653 += 1) {	// L1176
                #pragma HLS pipeline II=1
                for (int v654 = 0; v654 < 8; v654 += 1) {	// L1177
                  for (int v655 = 0; v655 < 1; v655 += 1) {	// L1178
                    for (int v656 = 0; v656 < 1; v656 += 1) {	// L1179
                      int8_t v657 = v642[v643][(v654 + (v653 * 8))][v655][v656];	// L1180
                      int8_t v658 = v636[v652][(v654 + (v653 * 8))][v655][v656];	// L1181
                      int8_t v659 = v657 * v658;	// L1182
                      int8_t v660 = v651[v652];	// L1183
                      int8_t v661 = v660 + v659;	// L1184
                      v651[v652] = v661;	// L1185
                    }
                  }
                }
              }
              int8_t v662 = v651[v652];	// L1190
              v640[v643][v652][(v644 - 28)][(v645 - 28)] = v662;	// L1191
            }
          }
        }
      }
    }
  }
  for (int v663 = 0; v663 < 1; v663 += 1) {	// L1198
    for (int v664 = 0; v664 < 28; v664 += 1) {	// L1199
      for (int v665 = 0; v665 < 28; v665 += 1) {	// L1200
        for (int v666 = 0; v666 < 128; v666 += 1) {	// L1201
          int8_t v667 = v637[0][v666][v664][v665];	// L1202
          int8_t v668 = v640[0][v666][v664][v665];	// L1203
          int8_t v669 = v667 + v668;	// L1204
          bool v670 = v669 > (int8_t)0.000000;	// L1205
          int8_t v671 = v670 ? v669 : (int8_t)0.000000;	// L1206
          v639[v663][v666][v664][v665] = v671;	// L1207
        }
      }
    }
  }
}

void main_graph_node22(
  int8_t v672[1][128][28][28],
  int8_t v673[128][128][3][3],
  int8_t v674[1][128][28][28]
) {	// L1214
  #pragma HLS dataflow

  int8_t v675[1][128][30][30];	// L1216
  #pragma HLS stream variable=v675 depth=10 type=fifo

  #pragma HLS bind_storage variable=v675 type=ram_t2p impl=bram

  for (int v676 = 0; v676 < 1; v676 += 1) {	// L1217
    for (int v677 = 0; v677 < 30; v677 += 1) {	// L1218
      for (int v678 = 0; v678 < 30; v678 += 1) {	// L1219
        for (int v679 = 0; v679 < 128; v679 += 1) {	// L1220
          int8_t v680;	// L1221
          v680 = (int8_t)0.000000;	// L1222
          if (((-v677) + 27) >= 0 && ((-v678) + 27) >= 0) {	// L1223
            int8_t v681 = v672[v676][v679][v677][v678];	// L1224
            v680 = v681;	// L1225
          }
          int8_t v682 = v680;	// L1227
          v675[v676][v679][v677][v678] = v682;	// L1228
        }
      }
    }
  }
  int8_t v683[1][128][3][30];	// L1233
  #pragma HLS array_partition variable=v683 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v683 type=ram_2p impl=bram

  int8_t v684[1][128][3][3];	// L1234
  #pragma HLS array_partition variable=v684 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v684 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v684 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v684 type=ram_2p impl=lutram

  for (int v685 = 0; v685 < 1; v685 += 1) {	// L1235
    for (int v686 = 0; v686 < 30; v686 += 1) {	// L1236
      for (int v687 = 0; v687 < 30; v687 += 1) {	// L1237
        for (int v688 = 0; v688 < 128; v688 += 1) {	// L1238
          int8_t v689 = v683[v685][v688][1][v687];	// L1239
          v683[v685][v688][0][v687] = v689;	// L1240
          int8_t v690 = v683[v685][v688][2][v687];	// L1241
          v683[v685][v688][1][v687] = v690;	// L1242
          int8_t v691 = v675[v685][v688][v686][v687];	// L1243
          v683[v685][v688][2][v687] = v691;	// L1244
        }
        if ((v686 - 2) >= 0) {	// L1246
          for (int v692 = 0; v692 < 128; v692 += 1) {	// L1247
            for (int v693 = 0; v693 < 3; v693 += 1) {	// L1248
              int8_t v694 = v684[v685][v692][v693][1];	// L1249
              v684[v685][v692][v693][0] = v694;	// L1250
              int8_t v695 = v684[v685][v692][v693][2];	// L1251
              v684[v685][v692][v693][1] = v695;	// L1252
              int8_t v696 = v683[v685][v692][v693][v687];	// L1253
              v684[v685][v692][v693][2] = v696;	// L1254
            }
          }
          if ((v687 - 2) >= 0) {	// L1257
            int8_t v697[128];	// L1258
            #pragma HLS bind_storage variable=v697 type=ram_2p impl=bram

            for (int v698 = 0; v698 < 128; v698 += 1) {	// L1259
              v697[v698] = (int8_t)0.000000;	// L1260
              for (int v699 = 0; v699 < 32; v699 += 1) {	// L1261
                #pragma HLS pipeline II=1
                for (int v700 = 0; v700 < 4; v700 += 1) {	// L1262
                  for (int v701 = 0; v701 < 3; v701 += 1) {	// L1263
                    for (int v702 = 0; v702 < 3; v702 += 1) {	// L1264
                      int8_t v703 = v684[v685][(v700 + (v699 * 4))][v701][v702];	// L1265
                      int8_t v704 = v673[v698][(v700 + (v699 * 4))][v701][v702];	// L1266
                      int8_t v705 = v703 * v704;	// L1267
                      int8_t v706 = v697[v698];	// L1268
                      int8_t v707 = v706 + v705;	// L1269
                      v697[v698] = v707;	// L1270
                    }
                  }
                }
              }
              int8_t v708 = v697[v698];	// L1275
              v674[v685][v698][(v686 - 2)][(v687 - 2)] = v708;	// L1276
            }
          }
        }
      }
    }
  }
}

void main_graph_node23(
  int8_t v709[128][64][3][3],
  int8_t v710[1][64][56][56],
  int8_t v711[1][128][28][28]
) {	// L1285
  #pragma HLS dataflow

  int8_t v712[1][64][58][58];	// L1287
  #pragma HLS stream variable=v712 depth=10 type=fifo

  #pragma HLS bind_storage variable=v712 type=ram_t2p impl=bram

  for (int v713 = 0; v713 < 1; v713 += 1) {	// L1288
    for (int v714 = 0; v714 < 58; v714 += 1) {	// L1289
      for (int v715 = 0; v715 < 58; v715 += 1) {	// L1290
        for (int v716 = 0; v716 < 64; v716 += 1) {	// L1291
          int8_t v717;	// L1292
          v717 = (int8_t)0.000000;	// L1293
          if (((-v714) + 55) >= 0 && ((-v715) + 55) >= 0) {	// L1294
            int8_t v718 = v710[v713][v716][v714][v715];	// L1295
            v717 = v718;	// L1296
          }
          int8_t v719 = v717;	// L1298
          v712[v713][v716][v714][v715] = v719;	// L1299
        }
      }
    }
  }
  int8_t v720[1][128][28][28];	// L1304
  #pragma HLS stream variable=v720 depth=10 type=fifo

  #pragma HLS bind_storage variable=v720 type=ram_t2p impl=bram

  int8_t v721[1][64][3][58];	// L1305
  #pragma HLS array_partition variable=v721 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v721 type=ram_2p impl=bram

  int8_t v722[1][64][3][3];	// L1306
  #pragma HLS array_partition variable=v722 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v722 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v722 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v722 type=ram_2p impl=lutram

  for (int v723 = 0; v723 < 1; v723 += 1) {	// L1307
    for (int v724 = 0; v724 < 58; v724 += 1) {	// L1308
      for (int v725 = 0; v725 < 58; v725 += 1) {	// L1309
        for (int v726 = 0; v726 < 64; v726 += 1) {	// L1310
          int8_t v727 = v721[v723][v726][1][v725];	// L1311
          v721[v723][v726][0][v725] = v727;	// L1312
          int8_t v728 = v721[v723][v726][2][v725];	// L1313
          v721[v723][v726][1][v725] = v728;	// L1314
          int8_t v729 = v712[v723][v726][v724][v725];	// L1315
          v721[v723][v726][2][v725] = v729;	// L1316
        }
        if ((v724 - 30) >= 0) {	// L1318
          for (int v730 = 0; v730 < 64; v730 += 1) {	// L1319
            for (int v731 = 0; v731 < 3; v731 += 1) {	// L1320
              int8_t v732 = v722[v723][v730][v731][1];	// L1321
              v722[v723][v730][v731][0] = v732;	// L1322
              int8_t v733 = v722[v723][v730][v731][2];	// L1323
              v722[v723][v730][v731][1] = v733;	// L1324
              int8_t v734 = v721[v723][v730][v731][v725];	// L1325
              v722[v723][v730][v731][2] = v734;	// L1326
            }
          }
          if ((v725 - 30) >= 0) {	// L1329
            int8_t v735[128];	// L1330
            #pragma HLS bind_storage variable=v735 type=ram_2p impl=bram

            for (int v736 = 0; v736 < 128; v736 += 1) {	// L1331
              v735[v736] = (int8_t)0.000000;	// L1332
              for (int v737 = 0; v737 < 8; v737 += 1) {	// L1333
                #pragma HLS pipeline II=1
                for (int v738 = 0; v738 < 8; v738 += 1) {	// L1334
                  for (int v739 = 0; v739 < 3; v739 += 1) {	// L1335
                    for (int v740 = 0; v740 < 3; v740 += 1) {	// L1336
                      int8_t v741 = v722[v723][(v738 + (v737 * 8))][v739][v740];	// L1337
                      int8_t v742 = v709[v736][(v738 + (v737 * 8))][v739][v740];	// L1338
                      int8_t v743 = v741 * v742;	// L1339
                      int8_t v744 = v735[v736];	// L1340
                      int8_t v745 = v744 + v743;	// L1341
                      v735[v736] = v745;	// L1342
                    }
                  }
                }
              }
              int8_t v746 = v735[v736];	// L1347
              v720[v723][v736][(v724 - 30)][(v725 - 30)] = v746;	// L1348
            }
          }
        }
      }
    }
  }
  for (int v747 = 0; v747 < 1; v747 += 1) {	// L1355
    for (int v748 = 0; v748 < 28; v748 += 1) {	// L1356
      for (int v749 = 0; v749 < 28; v749 += 1) {	// L1357
        for (int v750 = 0; v750 < 128; v750 += 1) {	// L1358
          int8_t v751 = v720[0][v750][v748][v749];	// L1359
          bool v752 = v751 > (int8_t)0.000000;	// L1360
          int8_t v753 = v752 ? v751 : (int8_t)0.000000;	// L1361
          v711[v747][v750][v748][v749] = v753;	// L1362
        }
      }
    }
  }
}

void main_graph_node24(
  int8_t v754[1][64][56][56],
  int8_t v755[1][64][56][56],
  int8_t v756[1][64][56][56]
) {	// L1369
  #pragma HLS dataflow

  for (int v757 = 0; v757 < 1; v757 += 1) {	// L1370
    for (int v758 = 0; v758 < 56; v758 += 1) {	// L1371
      for (int v759 = 0; v759 < 56; v759 += 1) {	// L1372
        for (int v760 = 0; v760 < 64; v760 += 1) {	// L1373
          int8_t v761 = v754[v757][v760][v758][v759];	// L1374
          v755[v757][v760][v758][v759] = v761;	// L1375
          int8_t v762 = v754[v757][v760][v758][v759];	// L1376
          v756[v757][v760][v758][v759] = v762;	// L1377
        }
      }
    }
  }
}

void main_graph_node25(
  int8_t v763[1][64][56][56],
  int8_t v764[64][64][3][3],
  int8_t v765[1][64][56][56],
  int8_t v766[1][64][56][56]
) {	// L1384
  #pragma HLS dataflow

  int8_t v767[1][64][58][58];	// L1386
  #pragma HLS stream variable=v767 depth=10 type=fifo

  #pragma HLS bind_storage variable=v767 type=ram_t2p impl=bram

  for (int v768 = 0; v768 < 1; v768 += 1) {	// L1387
    for (int v769 = 0; v769 < 58; v769 += 1) {	// L1388
      for (int v770 = 0; v770 < 58; v770 += 1) {	// L1389
        for (int v771 = 0; v771 < 64; v771 += 1) {	// L1390
          int8_t v772;	// L1391
          v772 = (int8_t)0.000000;	// L1392
          if (((-v769) + 55) >= 0 && ((-v770) + 55) >= 0) {	// L1393
            int8_t v773 = v763[v768][v771][v769][v770];	// L1394
            v772 = v773;	// L1395
          }
          int8_t v774 = v772;	// L1397
          v767[v768][v771][v769][v770] = v774;	// L1398
        }
      }
    }
  }
  int8_t v775[1][64][56][56];	// L1403
  #pragma HLS stream variable=v775 depth=10 type=fifo

  #pragma HLS bind_storage variable=v775 type=ram_t2p impl=bram

  int8_t v776[1][64][3][58];	// L1404
  #pragma HLS array_partition variable=v776 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v776 type=ram_2p impl=bram

  int8_t v777[1][64][3][3];	// L1405
  #pragma HLS array_partition variable=v777 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v777 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v777 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v777 type=ram_2p impl=lutram

  for (int v778 = 0; v778 < 1; v778 += 1) {	// L1406
    for (int v779 = 0; v779 < 58; v779 += 1) {	// L1407
      for (int v780 = 0; v780 < 58; v780 += 1) {	// L1408
        for (int v781 = 0; v781 < 64; v781 += 1) {	// L1409
          int8_t v782 = v776[v778][v781][1][v780];	// L1410
          v776[v778][v781][0][v780] = v782;	// L1411
          int8_t v783 = v776[v778][v781][2][v780];	// L1412
          v776[v778][v781][1][v780] = v783;	// L1413
          int8_t v784 = v767[v778][v781][v779][v780];	// L1414
          v776[v778][v781][2][v780] = v784;	// L1415
        }
        if ((v779 - 2) >= 0) {	// L1417
          for (int v785 = 0; v785 < 64; v785 += 1) {	// L1418
            for (int v786 = 0; v786 < 3; v786 += 1) {	// L1419
              int8_t v787 = v777[v778][v785][v786][1];	// L1420
              v777[v778][v785][v786][0] = v787;	// L1421
              int8_t v788 = v777[v778][v785][v786][2];	// L1422
              v777[v778][v785][v786][1] = v788;	// L1423
              int8_t v789 = v776[v778][v785][v786][v780];	// L1424
              v777[v778][v785][v786][2] = v789;	// L1425
            }
          }
          if ((v780 - 2) >= 0) {	// L1428
            int8_t v790[64];	// L1429
            #pragma HLS bind_storage variable=v790 type=ram_2p impl=bram

            for (int v791 = 0; v791 < 64; v791 += 1) {	// L1430
              v790[v791] = (int8_t)0.000000;	// L1431
              for (int v792 = 0; v792 < 16; v792 += 1) {	// L1432
                #pragma HLS pipeline II=1
                for (int v793 = 0; v793 < 4; v793 += 1) {	// L1433
                  for (int v794 = 0; v794 < 3; v794 += 1) {	// L1434
                    for (int v795 = 0; v795 < 3; v795 += 1) {	// L1435
                      int8_t v796 = v777[v778][(v793 + (v792 * 4))][v794][v795];	// L1436
                      int8_t v797 = v764[v791][(v793 + (v792 * 4))][v794][v795];	// L1437
                      int8_t v798 = v796 * v797;	// L1438
                      int8_t v799 = v790[v791];	// L1439
                      int8_t v800 = v799 + v798;	// L1440
                      v790[v791] = v800;	// L1441
                    }
                  }
                }
              }
              int8_t v801 = v790[v791];	// L1446
              v775[v778][v791][(v779 - 2)][(v780 - 2)] = v801;	// L1447
            }
          }
        }
      }
    }
  }
  for (int v802 = 0; v802 < 1; v802 += 1) {	// L1454
    for (int v803 = 0; v803 < 56; v803 += 1) {	// L1455
      for (int v804 = 0; v804 < 56; v804 += 1) {	// L1456
        for (int v805 = 0; v805 < 64; v805 += 1) {	// L1457
          int8_t v806 = v775[0][v805][v803][v804];	// L1458
          int8_t v807 = v765[0][v805][v803][v804];	// L1459
          int8_t v808 = v806 + v807;	// L1460
          bool v809 = v808 > (int8_t)0.000000;	// L1461
          int8_t v810 = v809 ? v808 : (int8_t)0.000000;	// L1462
          v766[v802][v805][v803][v804] = v810;	// L1463
        }
      }
    }
  }
}

void main_graph_node26(
  int8_t v811[64][64][3][3],
  int8_t v812[1][64][56][56],
  int8_t v813[1][64][56][56]
) {	// L1470
  #pragma HLS dataflow

  int8_t v814[1][64][58][58];	// L1472
  #pragma HLS stream variable=v814 depth=10 type=fifo

  #pragma HLS bind_storage variable=v814 type=ram_t2p impl=bram

  for (int v815 = 0; v815 < 1; v815 += 1) {	// L1473
    for (int v816 = 0; v816 < 58; v816 += 1) {	// L1474
      for (int v817 = 0; v817 < 58; v817 += 1) {	// L1475
        for (int v818 = 0; v818 < 64; v818 += 1) {	// L1476
          int8_t v819;	// L1477
          v819 = (int8_t)0.000000;	// L1478
          if (((-v816) + 55) >= 0 && ((-v817) + 55) >= 0) {	// L1479
            int8_t v820 = v812[v815][v818][v816][v817];	// L1480
            v819 = v820;	// L1481
          }
          int8_t v821 = v819;	// L1483
          v814[v815][v818][v816][v817] = v821;	// L1484
        }
      }
    }
  }
  int8_t v822[1][64][56][56];	// L1489
  #pragma HLS stream variable=v822 depth=10 type=fifo

  #pragma HLS bind_storage variable=v822 type=ram_t2p impl=bram

  int8_t v823[1][64][3][58];	// L1490
  #pragma HLS array_partition variable=v823 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v823 type=ram_2p impl=bram

  int8_t v824[1][64][3][3];	// L1491
  #pragma HLS array_partition variable=v824 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v824 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v824 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v824 type=ram_2p impl=lutram

  for (int v825 = 0; v825 < 1; v825 += 1) {	// L1492
    for (int v826 = 0; v826 < 58; v826 += 1) {	// L1493
      for (int v827 = 0; v827 < 58; v827 += 1) {	// L1494
        for (int v828 = 0; v828 < 64; v828 += 1) {	// L1495
          int8_t v829 = v823[v825][v828][1][v827];	// L1496
          v823[v825][v828][0][v827] = v829;	// L1497
          int8_t v830 = v823[v825][v828][2][v827];	// L1498
          v823[v825][v828][1][v827] = v830;	// L1499
          int8_t v831 = v814[v825][v828][v826][v827];	// L1500
          v823[v825][v828][2][v827] = v831;	// L1501
        }
        if ((v826 - 2) >= 0) {	// L1503
          for (int v832 = 0; v832 < 64; v832 += 1) {	// L1504
            for (int v833 = 0; v833 < 3; v833 += 1) {	// L1505
              int8_t v834 = v824[v825][v832][v833][1];	// L1506
              v824[v825][v832][v833][0] = v834;	// L1507
              int8_t v835 = v824[v825][v832][v833][2];	// L1508
              v824[v825][v832][v833][1] = v835;	// L1509
              int8_t v836 = v823[v825][v832][v833][v827];	// L1510
              v824[v825][v832][v833][2] = v836;	// L1511
            }
          }
          if ((v827 - 2) >= 0) {	// L1514
            int8_t v837[64];	// L1515
            #pragma HLS bind_storage variable=v837 type=ram_2p impl=bram

            for (int v838 = 0; v838 < 64; v838 += 1) {	// L1516
              v837[v838] = (int8_t)0.000000;	// L1517
              for (int v839 = 0; v839 < 16; v839 += 1) {	// L1518
                #pragma HLS pipeline II=1
                for (int v840 = 0; v840 < 4; v840 += 1) {	// L1519
                  for (int v841 = 0; v841 < 3; v841 += 1) {	// L1520
                    for (int v842 = 0; v842 < 3; v842 += 1) {	// L1521
                      int8_t v843 = v824[v825][(v840 + (v839 * 4))][v841][v842];	// L1522
                      int8_t v844 = v811[v838][(v840 + (v839 * 4))][v841][v842];	// L1523
                      int8_t v845 = v843 * v844;	// L1524
                      int8_t v846 = v837[v838];	// L1525
                      int8_t v847 = v846 + v845;	// L1526
                      v837[v838] = v847;	// L1527
                    }
                  }
                }
              }
              int8_t v848 = v837[v838];	// L1532
              v822[v825][v838][(v826 - 2)][(v827 - 2)] = v848;	// L1533
            }
          }
        }
      }
    }
  }
  for (int v849 = 0; v849 < 1; v849 += 1) {	// L1540
    for (int v850 = 0; v850 < 56; v850 += 1) {	// L1541
      for (int v851 = 0; v851 < 56; v851 += 1) {	// L1542
        for (int v852 = 0; v852 < 64; v852 += 1) {	// L1543
          int8_t v853 = v822[0][v852][v850][v851];	// L1544
          bool v854 = v853 > (int8_t)0.000000;	// L1545
          int8_t v855 = v854 ? v853 : (int8_t)0.000000;	// L1546
          v813[v849][v852][v850][v851] = v855;	// L1547
        }
      }
    }
  }
}

void main_graph_node27(
  int8_t v856[1][64][56][56],
  int8_t v857[1][64][56][56],
  int8_t v858[1][64][56][56]
) {	// L1554
  #pragma HLS dataflow

  for (int v859 = 0; v859 < 1; v859 += 1) {	// L1555
    for (int v860 = 0; v860 < 56; v860 += 1) {	// L1556
      for (int v861 = 0; v861 < 56; v861 += 1) {	// L1557
        for (int v862 = 0; v862 < 64; v862 += 1) {	// L1558
          int8_t v863 = v856[v859][v862][v860][v861];	// L1559
          v857[v859][v862][v860][v861] = v863;	// L1560
          int8_t v864 = v856[v859][v862][v860][v861];	// L1561
          v858[v859][v862][v860][v861] = v864;	// L1562
        }
      }
    }
  }
}

void main_graph_node28(
  int8_t v865[1][64][56][56],
  int8_t v866[1][64][56][56],
  int8_t v867[64][64][3][3],
  int8_t v868[1][64][56][56]
) {	// L1569
  #pragma HLS dataflow

  int8_t v869[1][64][58][58];	// L1571
  #pragma HLS stream variable=v869 depth=10 type=fifo

  #pragma HLS bind_storage variable=v869 type=ram_t2p impl=bram

  for (int v870 = 0; v870 < 1; v870 += 1) {	// L1572
    for (int v871 = 0; v871 < 58; v871 += 1) {	// L1573
      for (int v872 = 0; v872 < 58; v872 += 1) {	// L1574
        for (int v873 = 0; v873 < 64; v873 += 1) {	// L1575
          int8_t v874;	// L1576
          v874 = (int8_t)0.000000;	// L1577
          if (((-v871) + 55) >= 0 && ((-v872) + 55) >= 0) {	// L1578
            int8_t v875 = v865[v870][v873][v871][v872];	// L1579
            v874 = v875;	// L1580
          }
          int8_t v876 = v874;	// L1582
          v869[v870][v873][v871][v872] = v876;	// L1583
        }
      }
    }
  }
  int8_t v877[1][64][56][56];	// L1588
  #pragma HLS stream variable=v877 depth=10 type=fifo

  #pragma HLS bind_storage variable=v877 type=ram_t2p impl=bram

  int8_t v878[1][64][3][58];	// L1589
  #pragma HLS array_partition variable=v878 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v878 type=ram_2p impl=bram

  int8_t v879[1][64][3][3];	// L1590
  #pragma HLS array_partition variable=v879 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v879 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v879 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v879 type=ram_2p impl=lutram

  for (int v880 = 0; v880 < 1; v880 += 1) {	// L1591
    for (int v881 = 0; v881 < 58; v881 += 1) {	// L1592
      for (int v882 = 0; v882 < 58; v882 += 1) {	// L1593
        for (int v883 = 0; v883 < 64; v883 += 1) {	// L1594
          int8_t v884 = v878[v880][v883][1][v882];	// L1595
          v878[v880][v883][0][v882] = v884;	// L1596
          int8_t v885 = v878[v880][v883][2][v882];	// L1597
          v878[v880][v883][1][v882] = v885;	// L1598
          int8_t v886 = v869[v880][v883][v881][v882];	// L1599
          v878[v880][v883][2][v882] = v886;	// L1600
        }
        if ((v881 - 2) >= 0) {	// L1602
          for (int v887 = 0; v887 < 64; v887 += 1) {	// L1603
            for (int v888 = 0; v888 < 3; v888 += 1) {	// L1604
              int8_t v889 = v879[v880][v887][v888][1];	// L1605
              v879[v880][v887][v888][0] = v889;	// L1606
              int8_t v890 = v879[v880][v887][v888][2];	// L1607
              v879[v880][v887][v888][1] = v890;	// L1608
              int8_t v891 = v878[v880][v887][v888][v882];	// L1609
              v879[v880][v887][v888][2] = v891;	// L1610
            }
          }
          if ((v882 - 2) >= 0) {	// L1613
            int8_t v892[64];	// L1614
            #pragma HLS bind_storage variable=v892 type=ram_2p impl=bram

            for (int v893 = 0; v893 < 64; v893 += 1) {	// L1615
              v892[v893] = (int8_t)0.000000;	// L1616
              for (int v894 = 0; v894 < 16; v894 += 1) {	// L1617
                #pragma HLS pipeline II=1
                for (int v895 = 0; v895 < 4; v895 += 1) {	// L1618
                  for (int v896 = 0; v896 < 3; v896 += 1) {	// L1619
                    for (int v897 = 0; v897 < 3; v897 += 1) {	// L1620
                      int8_t v898 = v879[v880][(v895 + (v894 * 4))][v896][v897];	// L1621
                      int8_t v899 = v867[v893][(v895 + (v894 * 4))][v896][v897];	// L1622
                      int8_t v900 = v898 * v899;	// L1623
                      int8_t v901 = v892[v893];	// L1624
                      int8_t v902 = v901 + v900;	// L1625
                      v892[v893] = v902;	// L1626
                    }
                  }
                }
              }
              int8_t v903 = v892[v893];	// L1631
              v877[v880][v893][(v881 - 2)][(v882 - 2)] = v903;	// L1632
            }
          }
        }
      }
    }
  }
  for (int v904 = 0; v904 < 1; v904 += 1) {	// L1639
    for (int v905 = 0; v905 < 56; v905 += 1) {	// L1640
      for (int v906 = 0; v906 < 56; v906 += 1) {	// L1641
        for (int v907 = 0; v907 < 64; v907 += 1) {	// L1642
          int8_t v908 = v877[0][v907][v905][v906];	// L1643
          int8_t v909 = v866[0][v907][v905][v906];	// L1644
          int8_t v910 = v908 + v909;	// L1645
          bool v911 = v910 > (int8_t)0.000000;	// L1646
          int8_t v912 = v911 ? v910 : (int8_t)0.000000;	// L1647
          v868[v904][v907][v905][v906] = v912;	// L1648
        }
      }
    }
  }
}

void main_graph_node29(
  int8_t v913[1][64][56][56],
  int8_t v914[64][64][3][3],
  int8_t v915[1][64][56][56]
) {	// L1655
  #pragma HLS dataflow

  int8_t v916[1][64][58][58];	// L1657
  #pragma HLS stream variable=v916 depth=10 type=fifo

  #pragma HLS bind_storage variable=v916 type=ram_t2p impl=bram

  for (int v917 = 0; v917 < 1; v917 += 1) {	// L1658
    for (int v918 = 0; v918 < 58; v918 += 1) {	// L1659
      for (int v919 = 0; v919 < 58; v919 += 1) {	// L1660
        for (int v920 = 0; v920 < 64; v920 += 1) {	// L1661
          int8_t v921;	// L1662
          v921 = (int8_t)0.000000;	// L1663
          if (((-v918) + 55) >= 0 && ((-v919) + 55) >= 0) {	// L1664
            int8_t v922 = v913[v917][v920][v918][v919];	// L1665
            v921 = v922;	// L1666
          }
          int8_t v923 = v921;	// L1668
          v916[v917][v920][v918][v919] = v923;	// L1669
        }
      }
    }
  }
  int8_t v924[1][64][56][56];	// L1674
  #pragma HLS stream variable=v924 depth=10 type=fifo

  #pragma HLS bind_storage variable=v924 type=ram_t2p impl=bram

  int8_t v925[1][64][3][58];	// L1675
  #pragma HLS array_partition variable=v925 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v925 type=ram_2p impl=bram

  int8_t v926[1][64][3][3];	// L1676
  #pragma HLS array_partition variable=v926 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v926 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v926 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v926 type=ram_2p impl=lutram

  for (int v927 = 0; v927 < 1; v927 += 1) {	// L1677
    for (int v928 = 0; v928 < 58; v928 += 1) {	// L1678
      for (int v929 = 0; v929 < 58; v929 += 1) {	// L1679
        for (int v930 = 0; v930 < 64; v930 += 1) {	// L1680
          int8_t v931 = v925[v927][v930][1][v929];	// L1681
          v925[v927][v930][0][v929] = v931;	// L1682
          int8_t v932 = v925[v927][v930][2][v929];	// L1683
          v925[v927][v930][1][v929] = v932;	// L1684
          int8_t v933 = v916[v927][v930][v928][v929];	// L1685
          v925[v927][v930][2][v929] = v933;	// L1686
        }
        if ((v928 - 2) >= 0) {	// L1688
          for (int v934 = 0; v934 < 64; v934 += 1) {	// L1689
            for (int v935 = 0; v935 < 3; v935 += 1) {	// L1690
              int8_t v936 = v926[v927][v934][v935][1];	// L1691
              v926[v927][v934][v935][0] = v936;	// L1692
              int8_t v937 = v926[v927][v934][v935][2];	// L1693
              v926[v927][v934][v935][1] = v937;	// L1694
              int8_t v938 = v925[v927][v934][v935][v929];	// L1695
              v926[v927][v934][v935][2] = v938;	// L1696
            }
          }
          if ((v929 - 2) >= 0) {	// L1699
            int8_t v939[64];	// L1700
            #pragma HLS bind_storage variable=v939 type=ram_2p impl=bram

            for (int v940 = 0; v940 < 64; v940 += 1) {	// L1701
              v939[v940] = (int8_t)0.000000;	// L1702
              for (int v941 = 0; v941 < 16; v941 += 1) {	// L1703
                #pragma HLS pipeline II=1
                for (int v942 = 0; v942 < 4; v942 += 1) {	// L1704
                  for (int v943 = 0; v943 < 3; v943 += 1) {	// L1705
                    for (int v944 = 0; v944 < 3; v944 += 1) {	// L1706
                      int8_t v945 = v926[v927][(v942 + (v941 * 4))][v943][v944];	// L1707
                      int8_t v946 = v914[v940][(v942 + (v941 * 4))][v943][v944];	// L1708
                      int8_t v947 = v945 * v946;	// L1709
                      int8_t v948 = v939[v940];	// L1710
                      int8_t v949 = v948 + v947;	// L1711
                      v939[v940] = v949;	// L1712
                    }
                  }
                }
              }
              int8_t v950 = v939[v940];	// L1717
              v924[v927][v940][(v928 - 2)][(v929 - 2)] = v950;	// L1718
            }
          }
        }
      }
    }
  }
  for (int v951 = 0; v951 < 1; v951 += 1) {	// L1725
    for (int v952 = 0; v952 < 56; v952 += 1) {	// L1726
      for (int v953 = 0; v953 < 56; v953 += 1) {	// L1727
        for (int v954 = 0; v954 < 64; v954 += 1) {	// L1728
          int8_t v955 = v924[0][v954][v952][v953];	// L1729
          bool v956 = v955 > (int8_t)0.000000;	// L1730
          int8_t v957 = v956 ? v955 : (int8_t)0.000000;	// L1731
          v915[v951][v954][v952][v953] = v957;	// L1732
        }
      }
    }
  }
}

void main_graph_node30(
  int8_t v958[1][64][56][56],
  int8_t v959[1][64][56][56],
  int8_t v960[1][64][56][56]
) {	// L1739
  #pragma HLS dataflow

  for (int v961 = 0; v961 < 1; v961 += 1) {	// L1740
    for (int v962 = 0; v962 < 56; v962 += 1) {	// L1741
      for (int v963 = 0; v963 < 56; v963 += 1) {	// L1742
        for (int v964 = 0; v964 < 64; v964 += 1) {	// L1743
          int8_t v965 = v958[v961][v964][v962][v963];	// L1744
          v959[v961][v964][v962][v963] = v965;	// L1745
          int8_t v966 = v958[v961][v964][v962][v963];	// L1746
          v960[v961][v964][v962][v963] = v966;	// L1747
        }
      }
    }
  }
}

void main_graph_node31(
  int8_t v967[1][64][112][112],
  int8_t v968[1][64][56][56]
) {	// L1754
  #pragma HLS dataflow

  int8_t v969;	// L1757
  v969 = (int8_t)-INFINITY;	// L1758
  int8_t v970[1][64][114][114];	// L1759
  #pragma HLS bind_storage variable=v970 type=ram_t2p impl=bram

  for (int v971 = 0; v971 < 1; v971 += 1) {	// L1760
    for (int v972 = 0; v972 < 64; v972 += 1) {	// L1761
      for (int v973 = 0; v973 < 114; v973 += 1) {	// L1762
        for (int v974 = 0; v974 < 114; v974 += 1) {	// L1763
          int8_t v975;	// L1764
          v975 = (int8_t)-INFINITY;	// L1765
          if (((-v973) + 111) >= 0 && ((-v974) + 111) >= 0) {	// L1766
            int8_t v976 = v967[v971][v972][v973][v974];	// L1767
            v975 = v976;	// L1768
          }
          int8_t v977 = v975;	// L1770
          v970[v971][v972][v973][v974] = v977;	// L1771
        }
      }
    }
  }
  for (int v978 = 0; v978 < 1; v978 += 1) {	// L1776
    for (int v979 = 0; v979 < 56; v979 += 1) {	// L1777
      for (int v980 = 0; v980 < 56; v980 += 1) {	// L1778
        for (int v981 = 0; v981 < 64; v981 += 1) {	// L1779
          int8_t v982;	// L1780
          v982 = (int8_t)0.000000;	// L1781
          for (int v983 = 0; v983 < 3; v983 += 1) {	// L1782
            for (int v984 = 0; v984 < 3; v984 += 1) {	// L1783
              int8_t v985 = v970[v978][v981][((v979 * 2) + v983)][((v980 * 2) + v984)];	// L1784
              int8_t v986 = v969;	// L1785
              int8_t v987 = max(v986, v985);	// L1786
              v982 = v987;	// L1787
            }
          }
          int8_t v988 = v982;	// L1790
          v968[v978][v981][v979][v980] = v988;	// L1791
        }
      }
    }
  }
}

void main_graph_node32(
  int8_t v989[1][64][224][224],
  int8_t v990[1][64][112][112]
) {	// L1798
  #pragma HLS dataflow

  int8_t v991;	// L1801
  v991 = (int8_t)-INFINITY;	// L1802
  int8_t v992[1][64][112][112];	// L1803
  #pragma HLS bind_storage variable=v992 type=ram_t2p impl=bram

  for (int v993 = 0; v993 < 1; v993 += 1) {	// L1804
    for (int v994 = 0; v994 < 112; v994 += 1) {	// L1805
      for (int v995 = 0; v995 < 2; v995 += 1) {	// L1806
        for (int v996 = 0; v996 < 112; v996 += 1) {	// L1807
          for (int v997 = 0; v997 < 2; v997 += 1) {	// L1808
            for (int v998 = 0; v998 < 64; v998 += 1) {	// L1809
              #pragma HLS pipeline II=1
              for (int v999 = 0; v999 < 1; v999 += 1) {	// L1810
                int8_t v1000 = v989[v993][(v998 + v999)][((v994 * 2) + v995)][((v996 * 2) + v997)];	// L1811
                int8_t v1001 = v991;	// L1812
                int8_t v1002 = max(v1001, v1000);	// L1813
                v992[v993][(v998 + v999)][v994][v996] = v1002;	// L1814
              }
            }
          }
        }
      }
    }
  }
  for (int v1003 = 0; v1003 < 1; v1003 += 1) {	// L1822
    for (int v1004 = 0; v1004 < 64; v1004 += 1) {	// L1823
      for (int v1005 = 0; v1005 < 112; v1005 += 1) {	// L1824
        for (int v1006 = 0; v1006 < 112; v1006 += 1) {	// L1825
          int8_t v1007 = v992[0][v1004][v1005][v1006];	// L1826
          bool v1008 = v1007 > (int8_t)0.000000;	// L1827
          int8_t v1009 = v1008 ? v1007 : (int8_t)0.000000;	// L1828
          v990[v1003][v1004][v1005][v1006] = v1009;	// L1829
        }
      }
    }
  }
}

void main_graph_node33(
  int8_t v1010[1][3][224][224],
  int8_t v1011[64][3][7][7],
  int8_t v1012[1][64][224][224]
) {	// L1836
  #pragma HLS dataflow

  int8_t v1013[1][3][230][230];	// L1838
  #pragma HLS stream variable=v1013 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1013 type=ram_t2p impl=bram

  for (int v1014 = 0; v1014 < 1; v1014 += 1) {	// L1839
    for (int v1015 = 0; v1015 < 230; v1015 += 1) {	// L1840
      for (int v1016 = 0; v1016 < 230; v1016 += 1) {	// L1841
        for (int v1017 = 0; v1017 < 3; v1017 += 1) {	// L1842
          int8_t v1018;	// L1843
          v1018 = (int8_t)0.000000;	// L1844
          if (((-v1015) + 223) >= 0 && ((-v1016) + 223) >= 0) {	// L1845
            int8_t v1019 = v1010[v1014][v1017][v1015][v1016];	// L1846
            v1018 = v1019;	// L1847
          }
          int8_t v1020 = v1018;	// L1849
          v1013[v1014][v1017][v1015][v1016] = v1020;	// L1850
        }
      }
    }
  }
  int8_t v1021[1][3][7][230];	// L1855
  #pragma HLS array_partition variable=v1021 cyclic factor=7 dim=3
  #pragma HLS bind_storage variable=v1021 type=ram_2p impl=lutram

  int8_t v1022[1][3][7][7];	// L1856
  #pragma HLS array_partition variable=v1022 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1022 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v1022 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v1022 type=ram_2p impl=lutram

  for (int v1023 = 0; v1023 < 1; v1023 += 1) {	// L1857
    for (int v1024 = 0; v1024 < 230; v1024 += 1) {	// L1858
      for (int v1025 = 0; v1025 < 230; v1025 += 1) {	// L1859
        for (int v1026 = 0; v1026 < 3; v1026 += 1) {	// L1860
          int8_t v1027 = v1021[v1023][v1026][1][v1025];	// L1861
          v1021[v1023][v1026][0][v1025] = v1027;	// L1862
          int8_t v1028 = v1021[v1023][v1026][2][v1025];	// L1863
          v1021[v1023][v1026][1][v1025] = v1028;	// L1864
          int8_t v1029 = v1021[v1023][v1026][3][v1025];	// L1865
          v1021[v1023][v1026][2][v1025] = v1029;	// L1866
          int8_t v1030 = v1021[v1023][v1026][4][v1025];	// L1867
          v1021[v1023][v1026][3][v1025] = v1030;	// L1868
          int8_t v1031 = v1021[v1023][v1026][5][v1025];	// L1869
          v1021[v1023][v1026][4][v1025] = v1031;	// L1870
          int8_t v1032 = v1021[v1023][v1026][6][v1025];	// L1871
          v1021[v1023][v1026][5][v1025] = v1032;	// L1872
          int8_t v1033 = v1013[v1023][v1026][v1024][v1025];	// L1873
          v1021[v1023][v1026][6][v1025] = v1033;	// L1874
        }
        if ((v1024 - 6) >= 0) {	// L1876
          for (int v1034 = 0; v1034 < 3; v1034 += 1) {	// L1877
            for (int v1035 = 0; v1035 < 7; v1035 += 1) {	// L1878
              int8_t v1036 = v1022[v1023][v1034][v1035][1];	// L1879
              v1022[v1023][v1034][v1035][0] = v1036;	// L1880
              int8_t v1037 = v1022[v1023][v1034][v1035][2];	// L1881
              v1022[v1023][v1034][v1035][1] = v1037;	// L1882
              int8_t v1038 = v1022[v1023][v1034][v1035][3];	// L1883
              v1022[v1023][v1034][v1035][2] = v1038;	// L1884
              int8_t v1039 = v1022[v1023][v1034][v1035][4];	// L1885
              v1022[v1023][v1034][v1035][3] = v1039;	// L1886
              int8_t v1040 = v1022[v1023][v1034][v1035][5];	// L1887
              v1022[v1023][v1034][v1035][4] = v1040;	// L1888
              int8_t v1041 = v1022[v1023][v1034][v1035][6];	// L1889
              v1022[v1023][v1034][v1035][5] = v1041;	// L1890
              int8_t v1042 = v1021[v1023][v1034][v1035][v1025];	// L1891
              v1022[v1023][v1034][v1035][6] = v1042;	// L1892
            }
          }
          if ((v1025 - 6) >= 0) {	// L1895
            int8_t v1043[64];	// L1896
            #pragma HLS bind_storage variable=v1043 type=ram_2p impl=bram

            for (int v1044 = 0; v1044 < 64; v1044 += 1) {	// L1897
              #pragma HLS pipeline II=1
              for (int v1045 = 0; v1045 < 1; v1045 += 1) {	// L1898
                v1043[(v1044 + v1045)] = (int8_t)0.000000;	// L1899
                for (int v1046 = 0; v1046 < 3; v1046 += 1) {	// L1900
                  for (int v1047 = 0; v1047 < 7; v1047 += 1) {	// L1901
                    for (int v1048 = 0; v1048 < 7; v1048 += 1) {	// L1902
                      int8_t v1049 = v1022[v1023][v1046][v1047][v1048];	// L1903
                      int8_t v1050 = v1011[(v1044 + v1045)][v1046][v1047][v1048];	// L1904
                      int8_t v1051 = v1049 * v1050;	// L1905
                      int8_t v1052 = v1043[(v1044 + v1045)];	// L1906
                      int8_t v1053 = v1052 + v1051;	// L1907
                      v1043[(v1044 + v1045)] = v1053;	// L1908
                    }
                  }
                }
                int8_t v1054 = v1043[(v1044 + v1045)];	// L1912
                v1012[v1023][(v1044 + v1045)][(v1024 - 6)][(v1025 - 6)] = v1054;	// L1913
              }
            }
          }
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v1055[1][3][224][224],
  int8_t v1056[1000],
  int8_t v1057[512][512][3][3],
  int8_t v1058[512][512][3][3],
  int8_t v1059[512][256][1][1],
  int8_t v1060[512][512][3][3],
  int8_t v1061[512][256][3][3],
  int8_t v1062[256][256][3][3],
  int8_t v1063[256][256][3][3],
  int8_t v1064[256][128][1][1],
  int8_t v1065[256][256][3][3],
  int8_t v1066[256][128][3][3],
  int8_t v1067[128][128][3][3],
  int8_t v1068[128][128][3][3],
  int8_t v1069[128][64][1][1],
  int8_t v1070[128][128][3][3],
  int8_t v1071[128][64][3][3],
  int8_t v1072[64][64][3][3],
  int8_t v1073[64][64][3][3],
  int8_t v1074[64][64][3][3],
  int8_t v1075[64][64][3][3],
  int8_t v1076[64][3][7][7],
  int8_t v1077[512][1000],
  int8_t v1078[1][1000]
) {	// L1923
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v1055
  #pragma HLS bind_storage variable=v1055 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1056
  #pragma HLS bind_storage variable=v1056 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1057
  #pragma HLS array_partition variable=v1057 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1057 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1057 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1057 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1058
  #pragma HLS array_partition variable=v1058 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1058 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1058 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1058 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1059
  #pragma HLS array_partition variable=v1059 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1059 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1060
  #pragma HLS array_partition variable=v1060 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1060 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1060 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1060 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1061
  #pragma HLS array_partition variable=v1061 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1061 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1061 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1061 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1062
  #pragma HLS array_partition variable=v1062 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1062 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1062 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1062 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1063
  #pragma HLS array_partition variable=v1063 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1063 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1063 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1063 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1064
  #pragma HLS array_partition variable=v1064 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1064 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1065
  #pragma HLS array_partition variable=v1065 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1065 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1065 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1065 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1066
  #pragma HLS array_partition variable=v1066 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1066 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1066 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1066 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1067
  #pragma HLS array_partition variable=v1067 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1067 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1067 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1067 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1068
  #pragma HLS array_partition variable=v1068 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1068 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1068 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1068 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1069
  #pragma HLS array_partition variable=v1069 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1069 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1070
  #pragma HLS array_partition variable=v1070 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1070 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1070 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1070 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1071
  #pragma HLS array_partition variable=v1071 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1071 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1071 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1071 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1072
  #pragma HLS array_partition variable=v1072 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1072 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1072 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1072 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1073
  #pragma HLS array_partition variable=v1073 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1073 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1073 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1073 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1074
  #pragma HLS array_partition variable=v1074 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1074 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1074 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1074 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1075
  #pragma HLS array_partition variable=v1075 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v1075 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1075 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1075 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1076
  #pragma HLS array_partition variable=v1076 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1076 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v1076 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v1076 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1077
  #pragma HLS bind_storage variable=v1077 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1078
  #pragma HLS bind_storage variable=v1078 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v1079[1][64][224][224];	// L1925
  #pragma HLS stream variable=v1079 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1079 type=ram_t2p impl=bram

  main_graph_node33(v1055, v1076, v1079);	// L1926
  int8_t v1080[1][64][112][112];	// L1927
  #pragma HLS stream variable=v1080 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1080 type=ram_t2p impl=bram

  main_graph_node32(v1079, v1080);	// L1928
  int8_t v1081[1][64][56][56];	// L1929
  #pragma HLS stream variable=v1081 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1081 type=ram_t2p impl=bram

  main_graph_node31(v1080, v1081);	// L1930
  int8_t v1082[1][64][56][56];	// L1931
  #pragma HLS stream variable=v1082 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1082 type=ram_t2p impl=bram

  int8_t v1083[1][64][56][56];	// L1932
  #pragma HLS stream variable=v1083 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1083 type=ram_t2p impl=bram

  main_graph_node30(v1081, v1082, v1083);	// L1933
  int8_t v1084[1][64][56][56];	// L1934
  #pragma HLS stream variable=v1084 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1084 type=ram_t2p impl=bram

  main_graph_node29(v1083, v1075, v1084);	// L1935
  int8_t v1085[1][64][56][56];	// L1936
  #pragma HLS stream variable=v1085 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1085 type=ram_t2p impl=bram

  main_graph_node28(v1084, v1082, v1074, v1085);	// L1937
  int8_t v1086[1][64][56][56];	// L1938
  #pragma HLS stream variable=v1086 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1086 type=ram_t2p impl=bram

  int8_t v1087[1][64][56][56];	// L1939
  #pragma HLS stream variable=v1087 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1087 type=ram_t2p impl=bram

  main_graph_node27(v1085, v1086, v1087);	// L1940
  int8_t v1088[1][64][56][56];	// L1941
  #pragma HLS stream variable=v1088 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1088 type=ram_t2p impl=bram

  main_graph_node26(v1073, v1087, v1088);	// L1942
  int8_t v1089[1][64][56][56];	// L1943
  #pragma HLS stream variable=v1089 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1089 type=ram_t2p impl=bram

  main_graph_node25(v1088, v1072, v1086, v1089);	// L1944
  int8_t v1090[1][64][56][56];	// L1945
  #pragma HLS stream variable=v1090 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1090 type=ram_t2p impl=bram

  int8_t v1091[1][64][56][56];	// L1946
  #pragma HLS stream variable=v1091 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1091 type=ram_t2p impl=bram

  main_graph_node24(v1089, v1090, v1091);	// L1947
  int8_t v1092[1][128][28][28];	// L1948
  #pragma HLS stream variable=v1092 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1092 type=ram_t2p impl=bram

  main_graph_node23(v1071, v1091, v1092);	// L1949
  int8_t v1093[1][128][28][28];	// L1950
  #pragma HLS stream variable=v1093 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1093 type=ram_t2p impl=bram

  main_graph_node22(v1092, v1070, v1093);	// L1951
  int8_t v1094[1][128][28][28];	// L1952
  #pragma HLS stream variable=v1094 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1094 type=ram_t2p impl=bram

  main_graph_node21(v1069, v1093, v1090, v1094);	// L1953
  int8_t v1095[1][128][28][28];	// L1954
  #pragma HLS stream variable=v1095 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1095 type=ram_t2p impl=bram

  int8_t v1096[1][128][28][28];	// L1955
  #pragma HLS stream variable=v1096 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1096 type=ram_t2p impl=bram

  main_graph_node20(v1094, v1095, v1096);	// L1956
  int8_t v1097[1][128][28][28];	// L1957
  #pragma HLS stream variable=v1097 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1097 type=ram_t2p impl=bram

  main_graph_node19(v1096, v1068, v1097);	// L1958
  int8_t v1098[1][128][28][28];	// L1959
  #pragma HLS stream variable=v1098 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1098 type=ram_t2p impl=bram

  main_graph_node18(v1095, v1097, v1067, v1098);	// L1960
  int8_t v1099[1][128][28][28];	// L1961
  #pragma HLS stream variable=v1099 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1099 type=ram_t2p impl=bram

  int8_t v1100[1][128][28][28];	// L1962
  #pragma HLS stream variable=v1100 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1100 type=ram_t2p impl=bram

  main_graph_node17(v1098, v1099, v1100);	// L1963
  int8_t v1101[1][256][14][14];	// L1964
  #pragma HLS stream variable=v1101 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1101 type=ram_t2p impl=bram

  main_graph_node16(v1100, v1066, v1101);	// L1965
  int8_t v1102[1][256][14][14];	// L1966
  #pragma HLS stream variable=v1102 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1102 type=ram_t2p impl=bram

  main_graph_node15(v1101, v1065, v1102);	// L1967
  int8_t v1103[1][256][14][14];	// L1968
  #pragma HLS stream variable=v1103 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1103 type=ram_t2p impl=bram

  main_graph_node14(v1099, v1064, v1102, v1103);	// L1969
  int8_t v1104[1][256][14][14];	// L1970
  #pragma HLS stream variable=v1104 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1104 type=ram_t2p impl=bram

  int8_t v1105[1][256][14][14];	// L1971
  #pragma HLS stream variable=v1105 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1105 type=ram_t2p impl=bram

  main_graph_node13(v1103, v1104, v1105);	// L1972
  int8_t v1106[1][256][14][14];	// L1973
  #pragma HLS stream variable=v1106 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1106 type=ram_t2p impl=bram

  main_graph_node12(v1105, v1063, v1106);	// L1974
  int8_t v1107[1][256][14][14];	// L1975
  #pragma HLS stream variable=v1107 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1107 type=ram_t2p impl=bram

  main_graph_node11(v1104, v1106, v1062, v1107);	// L1976
  int8_t v1108[1][256][14][14];	// L1977
  #pragma HLS stream variable=v1108 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1108 type=ram_t2p impl=bram

  int8_t v1109[1][256][14][14];	// L1978
  #pragma HLS stream variable=v1109 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1109 type=ram_t2p impl=bram

  main_graph_node10(v1107, v1108, v1109);	// L1979
  int8_t v1110[1][512][7][7];	// L1980
  #pragma HLS stream variable=v1110 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1110 type=ram_t2p impl=bram

  main_graph_node9(v1109, v1061, v1110);	// L1981
  int8_t v1111[1][512][7][7];	// L1982
  #pragma HLS stream variable=v1111 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1111 type=ram_t2p impl=bram

  main_graph_node8(v1060, v1110, v1111);	// L1983
  int8_t v1112[1][512][7][7];	// L1984
  #pragma HLS stream variable=v1112 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1112 type=ram_t2p impl=bram

  main_graph_node7(v1111, v1108, v1059, v1112);	// L1985
  int8_t v1113[1][512][7][7];	// L1986
  #pragma HLS stream variable=v1113 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1113 type=ram_t2p impl=bram

  int8_t v1114[1][512][7][7];	// L1987
  #pragma HLS stream variable=v1114 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1114 type=ram_t2p impl=bram

  main_graph_node6(v1112, v1113, v1114);	// L1988
  int8_t v1115[1][512][7][7];	// L1989
  #pragma HLS stream variable=v1115 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1115 type=ram_t2p impl=bram

  main_graph_node5(v1114, v1058, v1115);	// L1990
  int8_t v1116[1][512][7][7];	// L1991
  #pragma HLS stream variable=v1116 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1116 type=ram_t2p impl=bram

  main_graph_node4(v1115, v1057, v1113, v1116);	// L1992
  int8_t v1117[1][512][8][8];	// L1993
  #pragma HLS bind_storage variable=v1117 type=ram_t2p impl=bram

  main_graph_node3(v1116, v1117);	// L1994
  int8_t v1118[1][1];	// L1995
  #pragma HLS bind_storage variable=v1118 type=ram_t2p impl=bram

  int8_t v1119[1][512][1][1];	// L1996
  #pragma HLS bind_storage variable=v1119 type=ram_t2p impl=bram

  main_graph_node2(v1117, v1119, v1118);	// L1997
  int8_t v1120[1][512][1][1];	// L1998
  #pragma HLS bind_storage variable=v1120 type=ram_t2p impl=bram

  main_graph_node1(v1119, v1118, v1120);	// L1999
  main_graph_node0(v1077, v1056, v1120, v1078);	// L2000
}

