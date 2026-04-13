
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
  float v0[512][512],
  float v1[512],
  float v2[1][8][16][64],
  float v3[1][16][512]
) {	// L3
   // #pragma HLS dataflow

  float v4[1][16][8][64];	// L5
   // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L6
    for (int v6 = 0; v6 < 8; v6 += 1) {	// L7
      for (int v7 = 0; v7 < 16; v7 += 1) {	// L8
        for (int v8 = 0; v8 < 64; v8 += 1) {	// L9
          float v9 = v2[v5][v6][v7][v8];	// L10
          v4[v5][v7][v6][v8] = v9;	// L11
        }
      }
    }
  }
  float v10[1][16][512];	// L16
   // #pragma HLS stream variable=v10 depth=10 type=fifo

  #pragma HLS bind_storage variable=v10 type=ram_t2p impl=bram

  for (int v11 = 0; v11 < 1; v11 += 1) {	// L17
    for (int v12 = 0; v12 < 16; v12 += 1) {	// L18
      for (int v13 = 0; v13 < 512; v13 += 1) {	// L19
        float v14 = v4[0][v12][(v13 / 64)][(v13 % 64)];	// L20
        v10[v11][v12][v13] = v14;	// L21
      }
    }
  }
  float v15[1][512][512];	// L25
   // #pragma HLS stream variable=v15 depth=10 type=fifo

  #pragma HLS bind_storage variable=v15 type=ram_t2p impl=bram

  for (int v16 = 0; v16 < 1; v16 += 1) {	// L26
    for (int v17 = 0; v17 < 512; v17 += 1) {	// L27
      for (int v18 = 0; v18 < 512; v18 += 1) {	// L28
        float v19 = v0[v17][v18];	// L29
        v15[v16][v17][v18] = v19;	// L30
      }
    }
  }
  float v20[1][16][512];	// L34
   // #pragma HLS stream variable=v20 depth=10 type=fifo

  #pragma HLS bind_storage variable=v20 type=ram_t2p impl=bram

  for (int v21 = 0; v21 < 1; v21 += 1) {	// L35
    for (int v22 = 0; v22 < 16; v22 += 1) {	// L36
      for (int v23 = 0; v23 < 512; v23 += 1) {	// L37
        v20[v21][v22][v23] = (float)0.000000;	// L38
      }
    }
  }
  for (int v24 = 0; v24 < 1; v24 += 1) {	// L42
    for (int v25 = 0; v25 < 16; v25 += 1) {	// L43
      for (int v26 = 0; v26 < 512; v26 += 1) {	// L44
        for (int v27 = 0; v27 < 512; v27 += 1) {	// L45
          float v28 = v10[v24][v25][v27];	// L46
          float v29 = v15[v24][v27][v26];	// L47
          float v30 = v20[v24][v25][v26];	// L48
          float v31 = v28 * v29;	// L49
          float v32 = v30 + v31;	// L50
          v20[v24][v25][v26] = v32;	// L51
        }
      }
    }
  }
  for (int v33 = 0; v33 < 1; v33 += 1) {	// L56
    for (int v34 = 0; v34 < 16; v34 += 1) {	// L57
      for (int v35 = 0; v35 < 512; v35 += 1) {	// L58
        float v36 = v20[0][v34][v35];	// L59
        float v37 = v1[v35];	// L60
        float v38 = v36 + v37;	// L61
        v3[v33][v34][v35] = v38;	// L62
      }
    }
  }
}

void main_graph_node1(
  float v39[1][16][512],
  float v40[1][8][16][64],
  float v41[1][8][16][1],
  float v42[1][8][16][16],
  float v43[1][8][16][64]
) {	// L68
   // #pragma HLS dataflow

  for (int v44 = 0; v44 < 1; v44 += 1) {	// L69
    for (int v45 = 0; v45 < 8; v45 += 1) {	// L70
      for (int v46 = 0; v46 < 16; v46 += 1) {	// L71
        for (int v47 = 0; v47 < 64; v47 += 1) {	// L72
          float v48 = v40[v44][v45][v46][v47];	// L73
          v43[v44][v45][v46][v47] = v48;	// L74
        }
      }
    }
  }
  for (int v49 = 0; v49 < 1; v49 += 1) {	// L79
    for (int v50 = 0; v50 < 8; v50 += 1) {	// L80
      for (int v51 = 0; v51 < 16; v51 += 1) {	// L81
        for (int v52 = 0; v52 < 64; v52 += 1) {	// L82
          for (int v53 = 0; v53 < 16; v53 += 1) {	// L83
            float v54 = v42[0][v50][v51][v53];	// L84
            float v55 = v41[0][v50][v51][0];	// L85
            float v56 = v39[0][v53][((v50 * 64) + v52)];	// L86
            float v57 = v43[v49][v50][v51][v52];	// L87
            float v58 = v54 / v55;	// L88
            float v59 = v58 * v56;	// L89
            float v60 = v57 + v59;	// L90
            v43[v49][v50][v51][v52] = v60;	// L91
          }
        }
      }
    }
  }
}

void main_graph_node2(
  float v61[1][8][16][64]
) {	// L99
  // #pragma HLS inline
   // #pragma HLS dataflow

  for (int v62 = 0; v62 < 1; v62 += 1) {	// L101
    for (int v63 = 0; v63 < 8; v63 += 1) {	// L102
      for (int v64 = 0; v64 < 16; v64 += 1) {	// L103
        for (int v65 = 0; v65 < 64; v65 += 1) {	// L104
          v61[v62][v63][v64][v65] = (float)0.000000;	// L105
        }
      }
    }
  }
}

void main_graph_node3(
  float v66[1][8][16][16],
  float v67[1][8][16][1]
) {	// L112
   // #pragma HLS dataflow

  for (int v68 = 0; v68 < 1; v68 += 1) {	// L114
    for (int v69 = 0; v69 < 8; v69 += 1) {	// L115
      for (int v70 = 0; v70 < 16; v70 += 1) {	// L116
        for (int v71 = 0; v71 < 1; v71 += 1) {	// L117
          v67[v68][v69][v70][v71] = (float)0.000000;	// L118
        }
      }
    }
  }
  for (int v72 = 0; v72 < 1; v72 += 1) {	// L123
    for (int v73 = 0; v73 < 8; v73 += 1) {	// L124
      for (int v74 = 0; v74 < 16; v74 += 1) {	// L125
        for (int v75 = 0; v75 < 16; v75 += 1) {	// L126
          float v76 = v66[v72][v73][v74][v75];	// L127
          float v77 = v67[v72][v73][v74][0];	// L128
          float v78 = v76 + v77;	// L129
          v67[v72][v73][v74][0] = v78;	// L130
        }
      }
    }
  }
}

void main_graph_node4(
  float v79[1][8][16][16],
  float v80[1][8][16][16],
  float v81[1][8][16][16]
) {	// L137
   // #pragma HLS dataflow

  for (int v82 = 0; v82 < 1; v82 += 1) {	// L138
    for (int v83 = 0; v83 < 8; v83 += 1) {	// L139
      for (int v84 = 0; v84 < 16; v84 += 1) {	// L140
        for (int v85 = 0; v85 < 16; v85 += 1) {	// L141
          float v86 = v79[v82][v83][v84][v85];	// L142
          v80[v82][v83][v84][v85] = v86;	// L143
        }
      }
    }
  }
  for (int v87 = 0; v87 < 1; v87 += 1) {	// L148
    for (int v88 = 0; v88 < 8; v88 += 1) {	// L149
      for (int v89 = 0; v89 < 16; v89 += 1) {	// L150
        for (int v90 = 0; v90 < 16; v90 += 1) {	// L151
          float v91 = v79[v87][v88][v89][v90];	// L152
          v81[v87][v88][v89][v90] = v91;	// L153
        }
      }
    }
  }
}

void main_graph_node5(
  float v92[1][8][16][16],
  float v93[1][8][16][1],
  float v94[1][8][16][16]
) {	// L160
  #pragma HLS inline
   // #pragma HLS dataflow

  for (int v95 = 0; v95 < 1; v95 += 1) {	// L161
    for (int v96 = 0; v96 < 8; v96 += 1) {	// L162
      for (int v97 = 0; v97 < 16; v97 += 1) {	// L163
        for (int v98 = 0; v98 < 16; v98 += 1) {	// L164
          float v99 = v92[0][v96][v97][v98];	// L165
          float v100 = v93[0][v96][v97][0];	// L166
          float v101 = v99 - v100;	// L167
          float v102 = exp(v101);	// L168
          v94[v95][v96][v97][v98] = v102;	// L169
        }
      }
    }
  }
}

void main_graph_node6(
  float v103[1][8][16][16],
  float v104[1][8][16][1]
) {	// L176
   // #pragma HLS dataflow

  for (int v105 = 0; v105 < 1; v105 += 1) {	// L178
    for (int v106 = 0; v106 < 8; v106 += 1) {	// L179
      for (int v107 = 0; v107 < 16; v107 += 1) {	// L180
        for (int v108 = 0; v108 < 1; v108 += 1) {	// L181
          v104[v105][v106][v107][v108] = (float)-INFINITY;	// L182
        }
      }
    }
  }
  for (int v109 = 0; v109 < 1; v109 += 1) {	// L187
    for (int v110 = 0; v110 < 8; v110 += 1) {	// L188
      for (int v111 = 0; v111 < 16; v111 += 1) {	// L189
        for (int v112 = 0; v112 < 16; v112 += 1) {	// L190
          float v113 = v103[v109][v110][v111][v112];	// L191
          float v114 = v104[v109][v110][v111][0];	// L192
          float v115 = max(v113, v114);	// L193
          v104[v109][v110][v111][0] = v115;	// L194
        }
      }
    }
  }
}

void main_graph_node7(
  float v116[1][8][16][16],
  float v117[1][8][16][16],
  float v118[1][8][16][16]
) {	// L201
   // #pragma HLS dataflow

  for (int v119 = 0; v119 < 1; v119 += 1) {	// L202
    for (int v120 = 0; v120 < 8; v120 += 1) {	// L203
      for (int v121 = 0; v121 < 16; v121 += 1) {	// L204
        for (int v122 = 0; v122 < 16; v122 += 1) {	// L205
          float v123 = v116[v119][v120][v121][v122];	// L206
          v117[v119][v120][v121][v122] = v123;	// L207
        }
      }
    }
  }
  for (int v124 = 0; v124 < 1; v124 += 1) {	// L212
    for (int v125 = 0; v125 < 8; v125 += 1) {	// L213
      for (int v126 = 0; v126 < 16; v126 += 1) {	// L214
        for (int v127 = 0; v127 < 16; v127 += 1) {	// L215
          float v128 = v116[v124][v125][v126][v127];	// L216
          v118[v124][v125][v126][v127] = v128;	// L217
        }
      }
    }
  }
}

void main_graph_node8(
  float v129[1][8][16][16],
  float v130[1][8][16][16]
) {	// L224
  #pragma HLS inline
   // #pragma HLS dataflow

  for (int v131 = 0; v131 < 1; v131 += 1) {	// L226
    for (int v132 = 0; v132 < 8; v132 += 1) {	// L227
      for (int v133 = 0; v133 < 16; v133 += 1) {	// L228
        for (int v134 = 0; v134 < 16; v134 += 1) {	// L229
          float v135 = v129[0][v132][v133][v134];	// L230
          float v136 = v135 / (float)8.000000;	// L231
          v130[v131][v132][v133][v134] = v136;	// L232
        }
      }
    }
  }
}

void main_graph_node9(
  float v137[1][16][512],
  float v138[1][8][16][16],
  float v139[1][16][512],
  float v140[1][8][16][16]
) {	// L239
   // #pragma HLS dataflow

  for (int v141 = 0; v141 < 1; v141 += 1) {	// L240
    for (int v142 = 0; v142 < 8; v142 += 1) {	// L241
      for (int v143 = 0; v143 < 16; v143 += 1) {	// L242
        for (int v144 = 0; v144 < 16; v144 += 1) {	// L243
          float v145 = v138[v141][v142][v143][v144];	// L244
          v140[v141][v142][v143][v144] = v145;	// L245
        }
      }
    }
  }
  for (int v146 = 0; v146 < 1; v146 += 1) {	// L250
    for (int v147 = 0; v147 < 8; v147 += 1) {	// L251
      for (int v148 = 0; v148 < 16; v148 += 1) {	// L252
        for (int v149 = 0; v149 < 16; v149 += 1) {	// L253
          for (int v150 = 0; v150 < 64; v150 += 1) {	// L254
            float v151 = v137[0][v148][((v147 * 64) + v150)];	// L255
            float v152 = v139[0][v149][((v147 * 64) + v150)];	// L256
            float v153 = v140[v146][v147][v148][v149];	// L257
            float v154 = v151 * v152;	// L258
            float v155 = v153 + v154;	// L259
            v140[v146][v147][v148][v149] = v155;	// L260
          }
        }
      }
    }
  }
}

void main_graph_node10(
  float v156[1][8][16][16]
) {	// L268
  #pragma HLS inline
   // #pragma HLS dataflow

  for (int v157 = 0; v157 < 1; v157 += 1) {	// L270
    for (int v158 = 0; v158 < 8; v158 += 1) {	// L271
      for (int v159 = 0; v159 < 16; v159 += 1) {	// L272
        for (int v160 = 0; v160 < 16; v160 += 1) {	// L273
          v156[v157][v158][v159][v160] = (float)0.000000;	// L274
        }
      }
    }
  }
}

void main_graph_node11(
  float v161[512],
  float v162[512][512],
  float v163[1][16][512],
  float v164[1][16][512]
) {	// L281
   // #pragma HLS dataflow

  float v165[1][512][512];	// L283
   // #pragma HLS stream variable=v165 depth=10 type=fifo

  #pragma HLS bind_storage variable=v165 type=ram_t2p impl=bram

  for (int v166 = 0; v166 < 1; v166 += 1) {	// L284
    for (int v167 = 0; v167 < 512; v167 += 1) {	// L285
      for (int v168 = 0; v168 < 512; v168 += 1) {	// L286
        float v169 = v162[v167][v168];	// L287
        v165[v166][v167][v168] = v169;	// L288
      }
    }
  }
  float v170[1][16][512];	// L292
   // #pragma HLS stream variable=v170 depth=10 type=fifo

  #pragma HLS bind_storage variable=v170 type=ram_t2p impl=bram

  for (int v171 = 0; v171 < 1; v171 += 1) {	// L293
    for (int v172 = 0; v172 < 16; v172 += 1) {	// L294
      for (int v173 = 0; v173 < 512; v173 += 1) {	// L295
        v170[v171][v172][v173] = (float)0.000000;	// L296
      }
    }
  }
  for (int v174 = 0; v174 < 1; v174 += 1) {	// L300
    for (int v175 = 0; v175 < 16; v175 += 1) {	// L301
      for (int v176 = 0; v176 < 512; v176 += 1) {	// L302
        for (int v177 = 0; v177 < 512; v177 += 1) {	// L303
          float v178 = v163[v174][v175][v177];	// L304
          float v179 = v165[v174][v177][v176];	// L305
          float v180 = v170[v174][v175][v176];	// L306
          float v181 = v178 * v179;	// L307
          float v182 = v180 + v181;	// L308
          v170[v174][v175][v176] = v182;	// L309
        }
      }
    }
  }
  for (int v183 = 0; v183 < 1; v183 += 1) {	// L314
    for (int v184 = 0; v184 < 16; v184 += 1) {	// L315
      for (int v185 = 0; v185 < 512; v185 += 1) {	// L316
        float v186 = v170[0][v184][v185];	// L317
        float v187 = v161[v185];	// L318
        float v188 = v186 + v187;	// L319
        v164[v183][v184][v185] = v188;	// L320
      }
    }
  }
}

void main_graph_node12(
  float v189[512],
  float v190[512][512],
  float v191[1][16][512],
  float v192[1][16][512]
) {	// L326
   // #pragma HLS dataflow

  float v193[1][512][512];	// L328
   // #pragma HLS stream variable=v193 depth=10 type=fifo

  #pragma HLS bind_storage variable=v193 type=ram_t2p impl=bram

  for (int v194 = 0; v194 < 1; v194 += 1) {	// L329
    for (int v195 = 0; v195 < 512; v195 += 1) {	// L330
      for (int v196 = 0; v196 < 512; v196 += 1) {	// L331
        float v197 = v190[v195][v196];	// L332
        v193[v194][v195][v196] = v197;	// L333
      }
    }
  }
  float v198[1][16][512];	// L337
   // #pragma HLS stream variable=v198 depth=10 type=fifo

  #pragma HLS bind_storage variable=v198 type=ram_t2p impl=bram

  for (int v199 = 0; v199 < 1; v199 += 1) {	// L338
    for (int v200 = 0; v200 < 16; v200 += 1) {	// L339
      for (int v201 = 0; v201 < 512; v201 += 1) {	// L340
        v198[v199][v200][v201] = (float)0.000000;	// L341
      }
    }
  }
  for (int v202 = 0; v202 < 1; v202 += 1) {	// L345
    for (int v203 = 0; v203 < 16; v203 += 1) {	// L346
      for (int v204 = 0; v204 < 512; v204 += 1) {	// L347
        for (int v205 = 0; v205 < 512; v205 += 1) {	// L348
          float v206 = v191[v202][v203][v205];	// L349
          float v207 = v193[v202][v205][v204];	// L350
          float v208 = v198[v202][v203][v204];	// L351
          float v209 = v206 * v207;	// L352
          float v210 = v208 + v209;	// L353
          v198[v202][v203][v204] = v210;	// L354
        }
      }
    }
  }
  for (int v211 = 0; v211 < 1; v211 += 1) {	// L359
    for (int v212 = 0; v212 < 16; v212 += 1) {	// L360
      for (int v213 = 0; v213 < 512; v213 += 1) {	// L361
        float v214 = v198[0][v212][v213];	// L362
        float v215 = v189[v213];	// L363
        float v216 = v214 + v215;	// L364
        v192[v211][v212][v213] = v216;	// L365
      }
    }
  }
}

void main_graph_node13(
  float v217[1][16][512],
  float v218[1][16][512],
  float v219[1][16][512]
) {	// L371
   // #pragma HLS dataflow

  for (int v220 = 0; v220 < 1; v220 += 1) {	// L372
    for (int v221 = 0; v221 < 16; v221 += 1) {	// L373
      for (int v222 = 0; v222 < 512; v222 += 1) {	// L374
        float v223 = v217[v220][v221][v222];	// L375
        v218[v220][v221][v222] = v223;	// L376
      }
    }
  }
  for (int v224 = 0; v224 < 1; v224 += 1) {	// L380
    for (int v225 = 0; v225 < 16; v225 += 1) {	// L381
      for (int v226 = 0; v226 < 512; v226 += 1) {	// L382
        float v227 = v217[v224][v225][v226];	// L383
        v219[v224][v225][v226] = v227;	// L384
      }
    }
  }
}

void main_graph_node14(
  float v228[512][512],
  float v229[1][16][512],
  float v230[512],
  float v231[1][16][512],
  float v232[1][16][512]
) {	// L390
   // #pragma HLS dataflow

  for (int v233 = 0; v233 < 1; v233 += 1) {	// L392
    for (int v234 = 0; v234 < 16; v234 += 1) {	// L393
      for (int v235 = 0; v235 < 512; v235 += 1) {	// L394
        float v236 = v229[0][v234][v235];	// L395
        v232[v233][v234][v235] = v236;	// L396
      }
    }
  }
  float v237[1][512][512];	// L400
   // #pragma HLS stream variable=v237 depth=10 type=fifo

  #pragma HLS bind_storage variable=v237 type=ram_t2p impl=bram

  for (int v238 = 0; v238 < 1; v238 += 1) {	// L401
    for (int v239 = 0; v239 < 512; v239 += 1) {	// L402
      for (int v240 = 0; v240 < 512; v240 += 1) {	// L403
        float v241 = v228[v239][v240];	// L404
        v237[v238][v239][v240] = v241;	// L405
      }
    }
  }
  float v242[1][16][512];	// L409
   // #pragma HLS stream variable=v242 depth=10 type=fifo

  #pragma HLS bind_storage variable=v242 type=ram_t2p impl=bram

  for (int v243 = 0; v243 < 1; v243 += 1) {	// L410
    for (int v244 = 0; v244 < 16; v244 += 1) {	// L411
      for (int v245 = 0; v245 < 512; v245 += 1) {	// L412
        v242[v243][v244][v245] = (float)0.000000;	// L413
      }
    }
  }
  for (int v246 = 0; v246 < 1; v246 += 1) {	// L417
    for (int v247 = 0; v247 < 16; v247 += 1) {	// L418
      for (int v248 = 0; v248 < 512; v248 += 1) {	// L419
        for (int v249 = 0; v249 < 512; v249 += 1) {	// L420
          float v250 = v232[v246][v247][v249];	// L421
          float v251 = v237[v246][v249][v248];	// L422
          float v252 = v242[v246][v247][v248];	// L423
          float v253 = v250 * v251;	// L424
          float v254 = v252 + v253;	// L425
          v242[v246][v247][v248] = v254;	// L426
        }
      }
    }
  }
  for (int v255 = 0; v255 < 1; v255 += 1) {	// L431
    for (int v256 = 0; v256 < 16; v256 += 1) {	// L432
      for (int v257 = 0; v257 < 512; v257 += 1) {	// L433
        float v258 = v242[0][v256][v257];	// L434
        float v259 = v230[v257];	// L435
        float v260 = v258 + v259;	// L436
        v231[v255][v256][v257] = v260;	// L437
      }
    }
  }
}

/// This is top function.
void main_graph(
  float v261[1][16][512],
  float v262[512][512],
  float v263[512],
  float v264[512],
  float v265[512],
  float v266[512],
  float v267[512][512],
  float v268[512][512],
  float v269[512][512],
  float v270[1][16][512]
) {	// L443
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v261
  #pragma HLS bind_storage variable=v261 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v262
  #pragma HLS bind_storage variable=v262 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v263
  #pragma HLS bind_storage variable=v263 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v264
  #pragma HLS bind_storage variable=v264 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v265
  #pragma HLS bind_storage variable=v265 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v266
  #pragma HLS bind_storage variable=v266 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v267
  #pragma HLS bind_storage variable=v267 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v268
  #pragma HLS bind_storage variable=v268 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v269
  #pragma HLS bind_storage variable=v269 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v270
  #pragma HLS bind_storage variable=v270 type=ram_t2p impl=bram

  //  // #pragma HLS dataflow

  float v271[1][16][512];	// L445
   // #pragma HLS stream variable=v271 depth=10 type=fifo

  #pragma HLS bind_storage variable=v271 type=ram_t2p impl=bram

  float v272[1][16][512];	// L446
   // #pragma HLS stream variable=v272 depth=10 type=fifo

  #pragma HLS bind_storage variable=v272 type=ram_t2p impl=bram

  main_graph_node14(v262, v261, v263, v271, v272);	// L447
  float v273[1][16][512];	// L448
   // #pragma HLS stream variable=v273 depth=10 type=fifo

  #pragma HLS bind_storage variable=v273 type=ram_t2p impl=bram

  float v274[1][16][512];	// L449
   // #pragma HLS stream variable=v274 depth=10 type=fifo

  #pragma HLS bind_storage variable=v274 type=ram_t2p impl=bram

  main_graph_node13(v272, v273, v274);	// L450
  float v275[1][16][512];	// L451
   // #pragma HLS stream variable=v275 depth=10 type=fifo

  #pragma HLS bind_storage variable=v275 type=ram_t2p impl=bram

  main_graph_node12(v264, v267, v274, v275);	// L452
  float v276[1][16][512];	// L453
   // #pragma HLS stream variable=v276 depth=10 type=fifo

  #pragma HLS bind_storage variable=v276 type=ram_t2p impl=bram

  main_graph_node11(v265, v268, v273, v276);	// L454
  float v277[1][8][16][16];	// L455
   // #pragma HLS stream variable=v277 depth=10 type=fifo

  #pragma HLS bind_storage variable=v277 type=ram_t2p impl=bram

  main_graph_node10(v277);	// L456
  float v278[1][8][16][16];	// L457
   // #pragma HLS stream variable=v278 depth=10 type=fifo

  #pragma HLS bind_storage variable=v278 type=ram_t2p impl=bram

  main_graph_node9(v271, v277, v275, v278);	// L458
  float v279[1][8][16][16];	// L459
   // #pragma HLS stream variable=v279 depth=10 type=fifo

  #pragma HLS bind_storage variable=v279 type=ram_t2p impl=bram

  main_graph_node8(v278, v279);	// L460
  float v280[1][8][16][16];	// L461
   // #pragma HLS stream variable=v280 depth=10 type=fifo

  #pragma HLS bind_storage variable=v280 type=ram_t2p impl=bram

  float v281[1][8][16][16];	// L462
   // #pragma HLS stream variable=v281 depth=10 type=fifo

  #pragma HLS bind_storage variable=v281 type=ram_t2p impl=bram

  main_graph_node7(v279, v280, v281);	// L463
  float v282[1][8][16][1];	// L464
   // #pragma HLS stream variable=v282 depth=10 type=fifo

  #pragma HLS bind_storage variable=v282 type=ram_t2p impl=bram

  main_graph_node6(v281, v282);	// L465
  float v283[1][8][16][16];	// L466
   // #pragma HLS stream variable=v283 depth=10 type=fifo

  #pragma HLS bind_storage variable=v283 type=ram_t2p impl=bram

  main_graph_node5(v280, v282, v283);	// L467
  float v284[1][8][16][16];	// L468
   // #pragma HLS stream variable=v284 depth=10 type=fifo

  #pragma HLS bind_storage variable=v284 type=ram_t2p impl=bram

  float v285[1][8][16][16];	// L469
   // #pragma HLS stream variable=v285 depth=10 type=fifo

  #pragma HLS bind_storage variable=v285 type=ram_t2p impl=bram

  main_graph_node4(v283, v284, v285);	// L470
  float v286[1][8][16][1];	// L471
   // #pragma HLS stream variable=v286 depth=10 type=fifo

  #pragma HLS bind_storage variable=v286 type=ram_t2p impl=bram

  main_graph_node3(v285, v286);	// L472
  float v287[1][8][16][64];	// L473
   // #pragma HLS stream variable=v287 depth=10 type=fifo

  #pragma HLS bind_storage variable=v287 type=ram_t2p impl=bram

  main_graph_node2(v287);	// L474
  float v288[1][8][16][64];	// L475
   // #pragma HLS stream variable=v288 depth=10 type=fifo

  #pragma HLS bind_storage variable=v288 type=ram_t2p impl=bram

  main_graph_node1(v276, v287, v286, v284, v288);	// L476
  main_graph_node0(v269, v266, v288, v270);	// L477
}

