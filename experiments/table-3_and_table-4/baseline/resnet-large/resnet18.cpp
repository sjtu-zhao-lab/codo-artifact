
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
) {	// L3
  // #pragma HLS dataflow

  int8_t v4[1][1000];	// L5
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L6
    for (int v6 = 0; v6 < 1000; v6 += 1) {	// L7
      v4[v5][v6] = (int8_t)0.000000;	// L8
    }
  }
  for (int v7 = 0; v7 < 1; v7 += 1) {	// L11
    for (int v8 = 0; v8 < 1000; v8 += 1) {	// L12
      for (int v9 = 0; v9 < 512; v9 += 1) {	// L13
        int8_t v10 = v2[v7][v9][0][0];	// L14
        int8_t v11 = v0[v9][v8];	// L15
        int8_t v12 = v4[v7][v8];	// L16
        int8_t v13 = v10 * v11;	// L17
        int8_t v14 = v12 + v13;	// L18
        v4[v7][v8] = v14;	// L19
      }
    }
  }
  for (int v15 = 0; v15 < 1; v15 += 1) {	// L23
    for (int v16 = 0; v16 < 1000; v16 += 1) {	// L24
      int8_t v17 = v4[0][v16];	// L25
      int8_t v18 = v1[v16];	// L26
      int8_t v19 = v17 + v18;	// L27
      v3[v15][v16] = v19;	// L28
    }
  }
}

void main_graph_node1(
  int8_t v20[1][512][1][1],
  int8_t v21[1][1],
  int8_t v22[1][512][1][1]
) {	// L33
  // #pragma HLS dataflow

  for (int v23 = 0; v23 < 1; v23 += 1) {	// L34
    for (int v24 = 0; v24 < 512; v24 += 1) {	// L35
      for (int v25 = 0; v25 < 1; v25 += 1) {	// L36
        for (int v26 = 0; v26 < 1; v26 += 1) {	// L37
          int8_t v27 = v20[v23][v24][v25][v26];	// L38
          v22[v23][v24][v25][v26] = v27;	// L39
        }
      }
    }
  }
  for (int v28 = 0; v28 < 1; v28 += 1) {	// L44
    for (int v29 = 0; v29 < 512; v29 += 1) {	// L45
      for (int v30 = 0; v30 < 1; v30 += 1) {	// L46
        for (int v31 = 0; v31 < 1; v31 += 1) {	// L47
          int8_t v32 = v21[v30][v31];	// L48
          int8_t v33 = v22[v28][v29][v30][v31];	// L49
          int8_t v34 = v33 / v32;	// L50
          v22[v28][v29][v30][v31] = v34;	// L51
        }
      }
    }
  }
}

void main_graph_node2(
  int8_t v35[1][512][8][8],
  int8_t v36[1][1],
  int8_t v37[1][512][1][1]
) {	// L58
  // #pragma HLS dataflow

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L62
    for (int v39 = 0; v39 < 512; v39 += 1) {	// L63
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L64
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L65
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L66
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L71
    for (int v43 = 0; v43 < 512; v43 += 1) {	// L72
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L73
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L74
          for (int v46 = 0; v46 < 7; v46 += 1) {	// L75
            for (int v47 = 0; v47 < 7; v47 += 1) {	// L76
              int8_t v48 = v37[v42][v43][v44][v45];	// L77
              int v49 = v44 * (int)7;	// L78
              int v50 = v44 + (int)1;	// L79
              int v51 = v50 * (int)7;	// L80
              int v52 = v45 * (int)7;	// L81
              int v53 = v45 + (int)1;	// L82
              int v54 = v53 * (int)7;	// L83
              int v55 = v49 + v46;	// L84
              int v56 = v52 + v47;	// L85
              int8_t v57 = v35[v42][v43][v55][v56];	// L86
              bool v58 = v55 < v51;	// L87
              int8_t v59 = v58 ? v57 : (int8_t)0.000000;	// L88
              bool v60 = v56 < v54;	// L89
              int8_t v61 = v60 ? v59 : (int8_t)0.000000;	// L90
              int8_t v62 = v61 + v48;	// L91
              int v63 = v51 - v49;	// L92
              int v64 = v54 - v52;	// L93
              int v65 = v63 * v64;	// L94
              ap_int<64> v66 = v65;	// L95
              int8_t v67 = v66;	// L96
              v37[v42][v43][v44][v45] = v62;	// L97
              v36[v44][v45] = v67;	// L98
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v68[1][512][7][7],
  int8_t v69[1][512][8][8]
) {	// L107
  // #pragma HLS dataflow

  for (int v70 = 0; v70 < 1; v70 += 1) {	// L109
    for (int v71 = 0; v71 < 512; v71 += 1) {	// L110
      for (int v72 = 0; v72 < 8; v72 += 1) {	// L111
        for (int v73 = 0; v73 < 8; v73 += 1) {	// L112
          v69[v70][v71][v72][v73] = (int8_t)0.000000;	// L113
        }
      }
    }
  }
  for (int v74 = 0; v74 < 1; v74 += 1) {	// L118
    for (int v75 = 0; v75 < 512; v75 += 1) {	// L119
      for (int v76 = 0; v76 < 7; v76 += 1) {	// L120
        for (int v77 = 0; v77 < 7; v77 += 1) {	// L121
          int8_t v78 = v68[v74][v75][v76][v77];	// L122
          v69[v74][v75][v76][v77] = v78;	// L123
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v79[512][512][3][3],
  int8_t v80[1][512][7][7],
  int8_t v81[1][512][7][7],
  int8_t v82[1][512][7][7]
) {	// L130
  // #pragma HLS dataflow

  int8_t v83[1][512][9][9];	// L132
  // #pragma HLS stream variable=v83 depth=10 type=fifo

  #pragma HLS bind_storage variable=v83 type=ram_t2p impl=bram

  for (int v84 = 0; v84 < 1; v84 += 1) {	// L133
    for (int v85 = 0; v85 < 512; v85 += 1) {	// L134
      for (int v86 = 0; v86 < 9; v86 += 1) {	// L135
        for (int v87 = 0; v87 < 9; v87 += 1) {	// L136
          v83[v84][v85][v86][v87] = (int8_t)0.000000;	// L137
        }
      }
    }
  }
  for (int v88 = 0; v88 < 1; v88 += 1) {	// L142
    for (int v89 = 0; v89 < 512; v89 += 1) {	// L143
      for (int v90 = 0; v90 < 7; v90 += 1) {	// L144
        for (int v91 = 0; v91 < 7; v91 += 1) {	// L145
          int8_t v92 = v80[v88][v89][v90][v91];	// L146
          v83[v88][v89][(v90 + 1)][(v91 + 1)] = v92;	// L147
        }
      }
    }
  }
  int8_t v93[1][512][7][7];	// L152
  // #pragma HLS stream variable=v93 depth=10 type=fifo

  #pragma HLS bind_storage variable=v93 type=ram_t2p impl=bram

  for (int v94 = 0; v94 < 1; v94 += 1) {	// L153
    for (int v95 = 0; v95 < 512; v95 += 1) {	// L154
      for (int v96 = 0; v96 < 7; v96 += 1) {	// L155
        for (int v97 = 0; v97 < 7; v97 += 1) {	// L156
          v93[v94][v95][v96][v97] = (int8_t)0.000000;	// L157
        }
      }
    }
  }
  for (int v98 = 0; v98 < 1; v98 += 1) {	// L162
    for (int v99 = 0; v99 < 512; v99 += 1) {	// L163
      for (int v100 = 0; v100 < 7; v100 += 1) {	// L164
        for (int v101 = 0; v101 < 7; v101 += 1) {	// L165
          for (int v102 = 0; v102 < 512; v102 += 1) {	// L166
            for (int v103 = 0; v103 < 3; v103 += 1) {	// L167
              for (int v104 = 0; v104 < 3; v104 += 1) {	// L168
                int8_t v105 = v83[v98][v102][(v100 + v103)][(v101 + v104)];	// L169
                int8_t v106 = v79[v99][v102][v103][v104];	// L170
                int8_t v107 = v93[v98][v99][v100][v101];	// L171
                int8_t v108 = v105 * v106;	// L172
                int8_t v109 = v107 + v108;	// L173
                v93[v98][v99][v100][v101] = v109;	// L174
              }
            }
          }
        }
      }
    }
  }
  for (int v110 = 0; v110 < 1; v110 += 1) {	// L182
    for (int v111 = 0; v111 < 512; v111 += 1) {	// L183
      for (int v112 = 0; v112 < 7; v112 += 1) {	// L184
        for (int v113 = 0; v113 < 7; v113 += 1) {	// L185
          int8_t v114 = v93[0][v111][v112][v113];	// L186
          int8_t v115 = v81[0][v111][v112][v113];	// L187
          int8_t v116 = v114 + v115;	// L188
          bool v117 = v116 > (int8_t)0.000000;	// L189
          int8_t v118 = v117 ? v116 : (int8_t)0.000000;	// L190
          v82[v110][v111][v112][v113] = v118;	// L191
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v119[512][512][3][3],
  int8_t v120[1][512][7][7],
  int8_t v121[1][512][7][7]
) {	// L198
  // #pragma HLS dataflow

  int8_t v122[1][512][9][9];	// L200
  // #pragma HLS stream variable=v122 depth=10 type=fifo

  #pragma HLS bind_storage variable=v122 type=ram_t2p impl=bram

  for (int v123 = 0; v123 < 1; v123 += 1) {	// L201
    for (int v124 = 0; v124 < 512; v124 += 1) {	// L202
      for (int v125 = 0; v125 < 9; v125 += 1) {	// L203
        for (int v126 = 0; v126 < 9; v126 += 1) {	// L204
          v122[v123][v124][v125][v126] = (int8_t)0.000000;	// L205
        }
      }
    }
  }
  for (int v127 = 0; v127 < 1; v127 += 1) {	// L210
    for (int v128 = 0; v128 < 512; v128 += 1) {	// L211
      for (int v129 = 0; v129 < 7; v129 += 1) {	// L212
        for (int v130 = 0; v130 < 7; v130 += 1) {	// L213
          int8_t v131 = v120[v127][v128][v129][v130];	// L214
          v122[v127][v128][(v129 + 1)][(v130 + 1)] = v131;	// L215
        }
      }
    }
  }
  int8_t v132[1][512][7][7];	// L220
  // #pragma HLS stream variable=v132 depth=10 type=fifo

  #pragma HLS bind_storage variable=v132 type=ram_t2p impl=bram

  for (int v133 = 0; v133 < 1; v133 += 1) {	// L221
    for (int v134 = 0; v134 < 512; v134 += 1) {	// L222
      for (int v135 = 0; v135 < 7; v135 += 1) {	// L223
        for (int v136 = 0; v136 < 7; v136 += 1) {	// L224
          v132[v133][v134][v135][v136] = (int8_t)0.000000;	// L225
        }
      }
    }
  }
  for (int v137 = 0; v137 < 1; v137 += 1) {	// L230
    for (int v138 = 0; v138 < 512; v138 += 1) {	// L231
      for (int v139 = 0; v139 < 7; v139 += 1) {	// L232
        for (int v140 = 0; v140 < 7; v140 += 1) {	// L233
          for (int v141 = 0; v141 < 512; v141 += 1) {	// L234
            for (int v142 = 0; v142 < 3; v142 += 1) {	// L235
              for (int v143 = 0; v143 < 3; v143 += 1) {	// L236
                int8_t v144 = v122[v137][v141][(v139 + v142)][(v140 + v143)];	// L237
                int8_t v145 = v119[v138][v141][v142][v143];	// L238
                int8_t v146 = v132[v137][v138][v139][v140];	// L239
                int8_t v147 = v144 * v145;	// L240
                int8_t v148 = v146 + v147;	// L241
                v132[v137][v138][v139][v140] = v148;	// L242
              }
            }
          }
        }
      }
    }
  }
  for (int v149 = 0; v149 < 1; v149 += 1) {	// L250
    for (int v150 = 0; v150 < 512; v150 += 1) {	// L251
      for (int v151 = 0; v151 < 7; v151 += 1) {	// L252
        for (int v152 = 0; v152 < 7; v152 += 1) {	// L253
          int8_t v153 = v132[0][v150][v151][v152];	// L254
          bool v154 = v153 > (int8_t)0.000000;	// L255
          int8_t v155 = v154 ? v153 : (int8_t)0.000000;	// L256
          v121[v149][v150][v151][v152] = v155;	// L257
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v156[512][256][1][1],
  int8_t v157[1][512][7][7],
  int8_t v158[1][256][14][14],
  int8_t v159[1][512][7][7]
) {	// L264
  // #pragma HLS dataflow

  int8_t v160[1][512][7][7];	// L266
  // #pragma HLS stream variable=v160 depth=10 type=fifo

  #pragma HLS bind_storage variable=v160 type=ram_t2p impl=bram

  for (int v161 = 0; v161 < 1; v161 += 1) {	// L267
    for (int v162 = 0; v162 < 512; v162 += 1) {	// L268
      for (int v163 = 0; v163 < 7; v163 += 1) {	// L269
        for (int v164 = 0; v164 < 7; v164 += 1) {	// L270
          v160[v161][v162][v163][v164] = (int8_t)0.000000;	// L271
        }
      }
    }
  }
  for (int v165 = 0; v165 < 1; v165 += 1) {	// L276
    for (int v166 = 0; v166 < 512; v166 += 1) {	// L277
      for (int v167 = 0; v167 < 7; v167 += 1) {	// L278
        for (int v168 = 0; v168 < 7; v168 += 1) {	// L279
          for (int v169 = 0; v169 < 256; v169 += 1) {	// L280
            for (int v170 = 0; v170 < 1; v170 += 1) {	// L281
              for (int v171 = 0; v171 < 1; v171 += 1) {	// L282
                int8_t v172 = v158[v165][v169][((v167 * 2) + v170)][((v168 * 2) + v171)];	// L283
                int8_t v173 = v156[v166][v169][v170][v171];	// L284
                int8_t v174 = v160[v165][v166][v167][v168];	// L285
                int8_t v175 = v172 * v173;	// L286
                int8_t v176 = v174 + v175;	// L287
                v160[v165][v166][v167][v168] = v176;	// L288
              }
            }
          }
        }
      }
    }
  }
  for (int v177 = 0; v177 < 1; v177 += 1) {	// L296
    for (int v178 = 0; v178 < 512; v178 += 1) {	// L297
      for (int v179 = 0; v179 < 7; v179 += 1) {	// L298
        for (int v180 = 0; v180 < 7; v180 += 1) {	// L299
          int8_t v181 = v157[0][v178][v179][v180];	// L300
          int8_t v182 = v160[0][v178][v179][v180];	// L301
          int8_t v183 = v181 + v182;	// L302
          bool v184 = v183 > (int8_t)0.000000;	// L303
          int8_t v185 = v184 ? v183 : (int8_t)0.000000;	// L304
          v159[v177][v178][v179][v180] = v185;	// L305
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v186[512][512][3][3],
  int8_t v187[1][512][7][7],
  int8_t v188[1][512][7][7]
) {	// L312
  // #pragma HLS dataflow

  int8_t v189[1][512][9][9];	// L314
  // #pragma HLS stream variable=v189 depth=10 type=fifo

  #pragma HLS bind_storage variable=v189 type=ram_t2p impl=bram

  for (int v190 = 0; v190 < 1; v190 += 1) {	// L315
    for (int v191 = 0; v191 < 512; v191 += 1) {	// L316
      for (int v192 = 0; v192 < 9; v192 += 1) {	// L317
        for (int v193 = 0; v193 < 9; v193 += 1) {	// L318
          v189[v190][v191][v192][v193] = (int8_t)0.000000;	// L319
        }
      }
    }
  }
  for (int v194 = 0; v194 < 1; v194 += 1) {	// L324
    for (int v195 = 0; v195 < 512; v195 += 1) {	// L325
      for (int v196 = 0; v196 < 7; v196 += 1) {	// L326
        for (int v197 = 0; v197 < 7; v197 += 1) {	// L327
          int8_t v198 = v187[v194][v195][v196][v197];	// L328
          v189[v194][v195][(v196 + 1)][(v197 + 1)] = v198;	// L329
        }
      }
    }
  }
  for (int v199 = 0; v199 < 1; v199 += 1) {	// L334
    for (int v200 = 0; v200 < 512; v200 += 1) {	// L335
      for (int v201 = 0; v201 < 7; v201 += 1) {	// L336
        for (int v202 = 0; v202 < 7; v202 += 1) {	// L337
          v188[v199][v200][v201][v202] = (int8_t)0.000000;	// L338
        }
      }
    }
  }
  for (int v203 = 0; v203 < 1; v203 += 1) {	// L343
    for (int v204 = 0; v204 < 512; v204 += 1) {	// L344
      for (int v205 = 0; v205 < 7; v205 += 1) {	// L345
        for (int v206 = 0; v206 < 7; v206 += 1) {	// L346
          for (int v207 = 0; v207 < 512; v207 += 1) {	// L347
            for (int v208 = 0; v208 < 3; v208 += 1) {	// L348
              for (int v209 = 0; v209 < 3; v209 += 1) {	// L349
                int8_t v210 = v189[v203][v207][(v205 + v208)][(v206 + v209)];	// L350
                int8_t v211 = v186[v204][v207][v208][v209];	// L351
                int8_t v212 = v188[v203][v204][v205][v206];	// L352
                int8_t v213 = v210 * v211;	// L353
                int8_t v214 = v212 + v213;	// L354
                v188[v203][v204][v205][v206] = v214;	// L355
              }
            }
          }
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v215[512][256][3][3],
  int8_t v216[1][256][14][14],
  int8_t v217[1][512][7][7]
) {	// L365
  // #pragma HLS dataflow

  int8_t v218[1][256][16][16];	// L367
  // #pragma HLS stream variable=v218 depth=10 type=fifo

  #pragma HLS bind_storage variable=v218 type=ram_t2p impl=bram

  for (int v219 = 0; v219 < 1; v219 += 1) {	// L368
    for (int v220 = 0; v220 < 256; v220 += 1) {	// L369
      for (int v221 = 0; v221 < 16; v221 += 1) {	// L370
        for (int v222 = 0; v222 < 16; v222 += 1) {	// L371
          v218[v219][v220][v221][v222] = (int8_t)0.000000;	// L372
        }
      }
    }
  }
  for (int v223 = 0; v223 < 1; v223 += 1) {	// L377
    for (int v224 = 0; v224 < 256; v224 += 1) {	// L378
      for (int v225 = 0; v225 < 14; v225 += 1) {	// L379
        for (int v226 = 0; v226 < 14; v226 += 1) {	// L380
          int8_t v227 = v216[v223][v224][v225][v226];	// L381
          v218[v223][v224][(v225 + 1)][(v226 + 1)] = v227;	// L382
        }
      }
    }
  }
  int8_t v228[1][512][7][7];	// L387
  // #pragma HLS stream variable=v228 depth=10 type=fifo

  #pragma HLS bind_storage variable=v228 type=ram_t2p impl=bram

  for (int v229 = 0; v229 < 1; v229 += 1) {	// L388
    for (int v230 = 0; v230 < 512; v230 += 1) {	// L389
      for (int v231 = 0; v231 < 7; v231 += 1) {	// L390
        for (int v232 = 0; v232 < 7; v232 += 1) {	// L391
          v228[v229][v230][v231][v232] = (int8_t)0.000000;	// L392
        }
      }
    }
  }
  for (int v233 = 0; v233 < 1; v233 += 1) {	// L397
    for (int v234 = 0; v234 < 512; v234 += 1) {	// L398
      for (int v235 = 0; v235 < 7; v235 += 1) {	// L399
        for (int v236 = 0; v236 < 7; v236 += 1) {	// L400
          for (int v237 = 0; v237 < 256; v237 += 1) {	// L401
            for (int v238 = 0; v238 < 3; v238 += 1) {	// L402
              for (int v239 = 0; v239 < 3; v239 += 1) {	// L403
                int8_t v240 = v218[v233][v237][((v235 * 2) + v238)][((v236 * 2) + v239)];	// L404
                int8_t v241 = v215[v234][v237][v238][v239];	// L405
                int8_t v242 = v228[v233][v234][v235][v236];	// L406
                int8_t v243 = v240 * v241;	// L407
                int8_t v244 = v242 + v243;	// L408
                v228[v233][v234][v235][v236] = v244;	// L409
              }
            }
          }
        }
      }
    }
  }
  for (int v245 = 0; v245 < 1; v245 += 1) {	// L417
    for (int v246 = 0; v246 < 512; v246 += 1) {	// L418
      for (int v247 = 0; v247 < 7; v247 += 1) {	// L419
        for (int v248 = 0; v248 < 7; v248 += 1) {	// L420
          int8_t v249 = v228[0][v246][v247][v248];	// L421
          bool v250 = v249 > (int8_t)0.000000;	// L422
          int8_t v251 = v250 ? v249 : (int8_t)0.000000;	// L423
          v217[v245][v246][v247][v248] = v251;	// L424
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v252[1][256][14][14],
  int8_t v253[1][256][14][14],
  int8_t v254[256][256][3][3],
  int8_t v255[1][256][14][14]
) {	// L431
  // #pragma HLS dataflow

  int8_t v256[1][256][16][16];	// L433
  // #pragma HLS stream variable=v256 depth=10 type=fifo

  #pragma HLS bind_storage variable=v256 type=ram_t2p impl=bram

  for (int v257 = 0; v257 < 1; v257 += 1) {	// L434
    for (int v258 = 0; v258 < 256; v258 += 1) {	// L435
      for (int v259 = 0; v259 < 16; v259 += 1) {	// L436
        for (int v260 = 0; v260 < 16; v260 += 1) {	// L437
          v256[v257][v258][v259][v260] = (int8_t)0.000000;	// L438
        }
      }
    }
  }
  for (int v261 = 0; v261 < 1; v261 += 1) {	// L443
    for (int v262 = 0; v262 < 256; v262 += 1) {	// L444
      for (int v263 = 0; v263 < 14; v263 += 1) {	// L445
        for (int v264 = 0; v264 < 14; v264 += 1) {	// L446
          int8_t v265 = v252[v261][v262][v263][v264];	// L447
          v256[v261][v262][(v263 + 1)][(v264 + 1)] = v265;	// L448
        }
      }
    }
  }
  int8_t v266[1][256][14][14];	// L453
  // #pragma HLS stream variable=v266 depth=10 type=fifo

  #pragma HLS bind_storage variable=v266 type=ram_t2p impl=bram

  for (int v267 = 0; v267 < 1; v267 += 1) {	// L454
    for (int v268 = 0; v268 < 256; v268 += 1) {	// L455
      for (int v269 = 0; v269 < 14; v269 += 1) {	// L456
        for (int v270 = 0; v270 < 14; v270 += 1) {	// L457
          v266[v267][v268][v269][v270] = (int8_t)0.000000;	// L458
        }
      }
    }
  }
  for (int v271 = 0; v271 < 1; v271 += 1) {	// L463
    for (int v272 = 0; v272 < 256; v272 += 1) {	// L464
      for (int v273 = 0; v273 < 14; v273 += 1) {	// L465
        for (int v274 = 0; v274 < 14; v274 += 1) {	// L466
          for (int v275 = 0; v275 < 256; v275 += 1) {	// L467
            for (int v276 = 0; v276 < 3; v276 += 1) {	// L468
              for (int v277 = 0; v277 < 3; v277 += 1) {	// L469
                int8_t v278 = v256[v271][v275][(v273 + v276)][(v274 + v277)];	// L470
                int8_t v279 = v254[v272][v275][v276][v277];	// L471
                int8_t v280 = v266[v271][v272][v273][v274];	// L472
                int8_t v281 = v278 * v279;	// L473
                int8_t v282 = v280 + v281;	// L474
                v266[v271][v272][v273][v274] = v282;	// L475
              }
            }
          }
        }
      }
    }
  }
  for (int v283 = 0; v283 < 1; v283 += 1) {	// L483
    for (int v284 = 0; v284 < 256; v284 += 1) {	// L484
      for (int v285 = 0; v285 < 14; v285 += 1) {	// L485
        for (int v286 = 0; v286 < 14; v286 += 1) {	// L486
          int8_t v287 = v266[0][v284][v285][v286];	// L487
          int8_t v288 = v253[0][v284][v285][v286];	// L488
          int8_t v289 = v287 + v288;	// L489
          bool v290 = v289 > (int8_t)0.000000;	// L490
          int8_t v291 = v290 ? v289 : (int8_t)0.000000;	// L491
          v255[v283][v284][v285][v286] = v291;	// L492
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v292[256][256][3][3],
  int8_t v293[1][256][14][14],
  int8_t v294[1][256][14][14]
) {	// L499
  // #pragma HLS dataflow

  int8_t v295[1][256][16][16];	// L501
  // #pragma HLS stream variable=v295 depth=10 type=fifo

  #pragma HLS bind_storage variable=v295 type=ram_t2p impl=bram

  for (int v296 = 0; v296 < 1; v296 += 1) {	// L502
    for (int v297 = 0; v297 < 256; v297 += 1) {	// L503
      for (int v298 = 0; v298 < 16; v298 += 1) {	// L504
        for (int v299 = 0; v299 < 16; v299 += 1) {	// L505
          v295[v296][v297][v298][v299] = (int8_t)0.000000;	// L506
        }
      }
    }
  }
  for (int v300 = 0; v300 < 1; v300 += 1) {	// L511
    for (int v301 = 0; v301 < 256; v301 += 1) {	// L512
      for (int v302 = 0; v302 < 14; v302 += 1) {	// L513
        for (int v303 = 0; v303 < 14; v303 += 1) {	// L514
          int8_t v304 = v293[v300][v301][v302][v303];	// L515
          v295[v300][v301][(v302 + 1)][(v303 + 1)] = v304;	// L516
        }
      }
    }
  }
  int8_t v305[1][256][14][14];	// L521
  // #pragma HLS stream variable=v305 depth=10 type=fifo

  #pragma HLS bind_storage variable=v305 type=ram_t2p impl=bram

  for (int v306 = 0; v306 < 1; v306 += 1) {	// L522
    for (int v307 = 0; v307 < 256; v307 += 1) {	// L523
      for (int v308 = 0; v308 < 14; v308 += 1) {	// L524
        for (int v309 = 0; v309 < 14; v309 += 1) {	// L525
          v305[v306][v307][v308][v309] = (int8_t)0.000000;	// L526
        }
      }
    }
  }
  for (int v310 = 0; v310 < 1; v310 += 1) {	// L531
    for (int v311 = 0; v311 < 256; v311 += 1) {	// L532
      for (int v312 = 0; v312 < 14; v312 += 1) {	// L533
        for (int v313 = 0; v313 < 14; v313 += 1) {	// L534
          for (int v314 = 0; v314 < 256; v314 += 1) {	// L535
            for (int v315 = 0; v315 < 3; v315 += 1) {	// L536
              for (int v316 = 0; v316 < 3; v316 += 1) {	// L537
                int8_t v317 = v295[v310][v314][(v312 + v315)][(v313 + v316)];	// L538
                int8_t v318 = v292[v311][v314][v315][v316];	// L539
                int8_t v319 = v305[v310][v311][v312][v313];	// L540
                int8_t v320 = v317 * v318;	// L541
                int8_t v321 = v319 + v320;	// L542
                v305[v310][v311][v312][v313] = v321;	// L543
              }
            }
          }
        }
      }
    }
  }
  for (int v322 = 0; v322 < 1; v322 += 1) {	// L551
    for (int v323 = 0; v323 < 256; v323 += 1) {	// L552
      for (int v324 = 0; v324 < 14; v324 += 1) {	// L553
        for (int v325 = 0; v325 < 14; v325 += 1) {	// L554
          int8_t v326 = v305[0][v323][v324][v325];	// L555
          bool v327 = v326 > (int8_t)0.000000;	// L556
          int8_t v328 = v327 ? v326 : (int8_t)0.000000;	// L557
          v294[v322][v323][v324][v325] = v328;	// L558
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v329[1][128][28][28],
  int8_t v330[256][128][1][1],
  int8_t v331[1][256][14][14],
  int8_t v332[1][256][14][14]
) {	// L565
  // #pragma HLS dataflow

  int8_t v333[1][256][14][14];	// L567
  // #pragma HLS stream variable=v333 depth=10 type=fifo

  #pragma HLS bind_storage variable=v333 type=ram_t2p impl=bram

  for (int v334 = 0; v334 < 1; v334 += 1) {	// L568
    for (int v335 = 0; v335 < 256; v335 += 1) {	// L569
      for (int v336 = 0; v336 < 14; v336 += 1) {	// L570
        for (int v337 = 0; v337 < 14; v337 += 1) {	// L571
          v333[v334][v335][v336][v337] = (int8_t)0.000000;	// L572
        }
      }
    }
  }
  for (int v338 = 0; v338 < 1; v338 += 1) {	// L577
    for (int v339 = 0; v339 < 256; v339 += 1) {	// L578
      for (int v340 = 0; v340 < 14; v340 += 1) {	// L579
        for (int v341 = 0; v341 < 14; v341 += 1) {	// L580
          for (int v342 = 0; v342 < 128; v342 += 1) {	// L581
            for (int v343 = 0; v343 < 1; v343 += 1) {	// L582
              for (int v344 = 0; v344 < 1; v344 += 1) {	// L583
                int8_t v345 = v329[v338][v342][((v340 * 2) + v343)][((v341 * 2) + v344)];	// L584
                int8_t v346 = v330[v339][v342][v343][v344];	// L585
                int8_t v347 = v333[v338][v339][v340][v341];	// L586
                int8_t v348 = v345 * v346;	// L587
                int8_t v349 = v347 + v348;	// L588
                v333[v338][v339][v340][v341] = v349;	// L589
              }
            }
          }
        }
      }
    }
  }
  for (int v350 = 0; v350 < 1; v350 += 1) {	// L597
    for (int v351 = 0; v351 < 256; v351 += 1) {	// L598
      for (int v352 = 0; v352 < 14; v352 += 1) {	// L599
        for (int v353 = 0; v353 < 14; v353 += 1) {	// L600
          int8_t v354 = v331[0][v351][v352][v353];	// L601
          int8_t v355 = v333[0][v351][v352][v353];	// L602
          int8_t v356 = v354 + v355;	// L603
          bool v357 = v356 > (int8_t)0.000000;	// L604
          int8_t v358 = v357 ? v356 : (int8_t)0.000000;	// L605
          v332[v350][v351][v352][v353] = v358;	// L606
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v359[256][256][3][3],
  int8_t v360[1][256][14][14],
  int8_t v361[1][256][14][14]
) {	// L613
  // #pragma HLS dataflow

  int8_t v362[1][256][16][16];	// L615
  // #pragma HLS stream variable=v362 depth=10 type=fifo

  #pragma HLS bind_storage variable=v362 type=ram_t2p impl=bram

  for (int v363 = 0; v363 < 1; v363 += 1) {	// L616
    for (int v364 = 0; v364 < 256; v364 += 1) {	// L617
      for (int v365 = 0; v365 < 16; v365 += 1) {	// L618
        for (int v366 = 0; v366 < 16; v366 += 1) {	// L619
          v362[v363][v364][v365][v366] = (int8_t)0.000000;	// L620
        }
      }
    }
  }
  for (int v367 = 0; v367 < 1; v367 += 1) {	// L625
    for (int v368 = 0; v368 < 256; v368 += 1) {	// L626
      for (int v369 = 0; v369 < 14; v369 += 1) {	// L627
        for (int v370 = 0; v370 < 14; v370 += 1) {	// L628
          int8_t v371 = v360[v367][v368][v369][v370];	// L629
          v362[v367][v368][(v369 + 1)][(v370 + 1)] = v371;	// L630
        }
      }
    }
  }
  for (int v372 = 0; v372 < 1; v372 += 1) {	// L635
    for (int v373 = 0; v373 < 256; v373 += 1) {	// L636
      for (int v374 = 0; v374 < 14; v374 += 1) {	// L637
        for (int v375 = 0; v375 < 14; v375 += 1) {	// L638
          v361[v372][v373][v374][v375] = (int8_t)0.000000;	// L639
        }
      }
    }
  }
  for (int v376 = 0; v376 < 1; v376 += 1) {	// L644
    for (int v377 = 0; v377 < 256; v377 += 1) {	// L645
      for (int v378 = 0; v378 < 14; v378 += 1) {	// L646
        for (int v379 = 0; v379 < 14; v379 += 1) {	// L647
          for (int v380 = 0; v380 < 256; v380 += 1) {	// L648
            for (int v381 = 0; v381 < 3; v381 += 1) {	// L649
              for (int v382 = 0; v382 < 3; v382 += 1) {	// L650
                int8_t v383 = v362[v376][v380][(v378 + v381)][(v379 + v382)];	// L651
                int8_t v384 = v359[v377][v380][v381][v382];	// L652
                int8_t v385 = v361[v376][v377][v378][v379];	// L653
                int8_t v386 = v383 * v384;	// L654
                int8_t v387 = v385 + v386;	// L655
                v361[v376][v377][v378][v379] = v387;	// L656
              }
            }
          }
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v388[1][128][28][28],
  int8_t v389[256][128][3][3],
  int8_t v390[1][256][14][14]
) {	// L666
  // #pragma HLS dataflow

  int8_t v391[1][128][30][30];	// L668
  // #pragma HLS stream variable=v391 depth=10 type=fifo

  #pragma HLS bind_storage variable=v391 type=ram_t2p impl=bram

  for (int v392 = 0; v392 < 1; v392 += 1) {	// L669
    for (int v393 = 0; v393 < 128; v393 += 1) {	// L670
      for (int v394 = 0; v394 < 30; v394 += 1) {	// L671
        for (int v395 = 0; v395 < 30; v395 += 1) {	// L672
          v391[v392][v393][v394][v395] = (int8_t)0.000000;	// L673
        }
      }
    }
  }
  for (int v396 = 0; v396 < 1; v396 += 1) {	// L678
    for (int v397 = 0; v397 < 128; v397 += 1) {	// L679
      for (int v398 = 0; v398 < 28; v398 += 1) {	// L680
        for (int v399 = 0; v399 < 28; v399 += 1) {	// L681
          int8_t v400 = v388[v396][v397][v398][v399];	// L682
          v391[v396][v397][(v398 + 1)][(v399 + 1)] = v400;	// L683
        }
      }
    }
  }
  int8_t v401[1][256][14][14];	// L688
  // #pragma HLS stream variable=v401 depth=10 type=fifo

  #pragma HLS bind_storage variable=v401 type=ram_t2p impl=bram

  for (int v402 = 0; v402 < 1; v402 += 1) {	// L689
    for (int v403 = 0; v403 < 256; v403 += 1) {	// L690
      for (int v404 = 0; v404 < 14; v404 += 1) {	// L691
        for (int v405 = 0; v405 < 14; v405 += 1) {	// L692
          v401[v402][v403][v404][v405] = (int8_t)0.000000;	// L693
        }
      }
    }
  }
  for (int v406 = 0; v406 < 1; v406 += 1) {	// L698
    for (int v407 = 0; v407 < 256; v407 += 1) {	// L699
      for (int v408 = 0; v408 < 14; v408 += 1) {	// L700
        for (int v409 = 0; v409 < 14; v409 += 1) {	// L701
          for (int v410 = 0; v410 < 128; v410 += 1) {	// L702
            for (int v411 = 0; v411 < 3; v411 += 1) {	// L703
              for (int v412 = 0; v412 < 3; v412 += 1) {	// L704
                int8_t v413 = v391[v406][v410][((v408 * 2) + v411)][((v409 * 2) + v412)];	// L705
                int8_t v414 = v389[v407][v410][v411][v412];	// L706
                int8_t v415 = v401[v406][v407][v408][v409];	// L707
                int8_t v416 = v413 * v414;	// L708
                int8_t v417 = v415 + v416;	// L709
                v401[v406][v407][v408][v409] = v417;	// L710
              }
            }
          }
        }
      }
    }
  }
  for (int v418 = 0; v418 < 1; v418 += 1) {	// L718
    for (int v419 = 0; v419 < 256; v419 += 1) {	// L719
      for (int v420 = 0; v420 < 14; v420 += 1) {	// L720
        for (int v421 = 0; v421 < 14; v421 += 1) {	// L721
          int8_t v422 = v401[0][v419][v420][v421];	// L722
          bool v423 = v422 > (int8_t)0.000000;	// L723
          int8_t v424 = v423 ? v422 : (int8_t)0.000000;	// L724
          v390[v418][v419][v420][v421] = v424;	// L725
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v425[128][128][3][3],
  int8_t v426[1][128][28][28],
  int8_t v427[1][128][28][28],
  int8_t v428[1][128][28][28]
) {	// L732
  // #pragma HLS dataflow

  int8_t v429[1][128][30][30];	// L734
  // #pragma HLS stream variable=v429 depth=10 type=fifo

  #pragma HLS bind_storage variable=v429 type=ram_t2p impl=bram

  for (int v430 = 0; v430 < 1; v430 += 1) {	// L735
    for (int v431 = 0; v431 < 128; v431 += 1) {	// L736
      for (int v432 = 0; v432 < 30; v432 += 1) {	// L737
        for (int v433 = 0; v433 < 30; v433 += 1) {	// L738
          v429[v430][v431][v432][v433] = (int8_t)0.000000;	// L739
        }
      }
    }
  }
  for (int v434 = 0; v434 < 1; v434 += 1) {	// L744
    for (int v435 = 0; v435 < 128; v435 += 1) {	// L745
      for (int v436 = 0; v436 < 28; v436 += 1) {	// L746
        for (int v437 = 0; v437 < 28; v437 += 1) {	// L747
          int8_t v438 = v427[v434][v435][v436][v437];	// L748
          v429[v434][v435][(v436 + 1)][(v437 + 1)] = v438;	// L749
        }
      }
    }
  }
  int8_t v439[1][128][28][28];	// L754
  // #pragma HLS stream variable=v439 depth=10 type=fifo

  #pragma HLS bind_storage variable=v439 type=ram_t2p impl=bram

  for (int v440 = 0; v440 < 1; v440 += 1) {	// L755
    for (int v441 = 0; v441 < 128; v441 += 1) {	// L756
      for (int v442 = 0; v442 < 28; v442 += 1) {	// L757
        for (int v443 = 0; v443 < 28; v443 += 1) {	// L758
          v439[v440][v441][v442][v443] = (int8_t)0.000000;	// L759
        }
      }
    }
  }
  for (int v444 = 0; v444 < 1; v444 += 1) {	// L764
    for (int v445 = 0; v445 < 128; v445 += 1) {	// L765
      for (int v446 = 0; v446 < 28; v446 += 1) {	// L766
        for (int v447 = 0; v447 < 28; v447 += 1) {	// L767
          for (int v448 = 0; v448 < 128; v448 += 1) {	// L768
            for (int v449 = 0; v449 < 3; v449 += 1) {	// L769
              for (int v450 = 0; v450 < 3; v450 += 1) {	// L770
                int8_t v451 = v429[v444][v448][(v446 + v449)][(v447 + v450)];	// L771
                int8_t v452 = v425[v445][v448][v449][v450];	// L772
                int8_t v453 = v439[v444][v445][v446][v447];	// L773
                int8_t v454 = v451 * v452;	// L774
                int8_t v455 = v453 + v454;	// L775
                v439[v444][v445][v446][v447] = v455;	// L776
              }
            }
          }
        }
      }
    }
  }
  for (int v456 = 0; v456 < 1; v456 += 1) {	// L784
    for (int v457 = 0; v457 < 128; v457 += 1) {	// L785
      for (int v458 = 0; v458 < 28; v458 += 1) {	// L786
        for (int v459 = 0; v459 < 28; v459 += 1) {	// L787
          int8_t v460 = v439[0][v457][v458][v459];	// L788
          int8_t v461 = v426[0][v457][v458][v459];	// L789
          int8_t v462 = v460 + v461;	// L790
          bool v463 = v462 > (int8_t)0.000000;	// L791
          int8_t v464 = v463 ? v462 : (int8_t)0.000000;	// L792
          v428[v456][v457][v458][v459] = v464;	// L793
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v465[1][128][28][28],
  int8_t v466[128][128][3][3],
  int8_t v467[1][128][28][28]
) {	// L800
  // #pragma HLS dataflow

  int8_t v468[1][128][30][30];	// L802
  // #pragma HLS stream variable=v468 depth=10 type=fifo

  #pragma HLS bind_storage variable=v468 type=ram_t2p impl=bram

  for (int v469 = 0; v469 < 1; v469 += 1) {	// L803
    for (int v470 = 0; v470 < 128; v470 += 1) {	// L804
      for (int v471 = 0; v471 < 30; v471 += 1) {	// L805
        for (int v472 = 0; v472 < 30; v472 += 1) {	// L806
          v468[v469][v470][v471][v472] = (int8_t)0.000000;	// L807
        }
      }
    }
  }
  for (int v473 = 0; v473 < 1; v473 += 1) {	// L812
    for (int v474 = 0; v474 < 128; v474 += 1) {	// L813
      for (int v475 = 0; v475 < 28; v475 += 1) {	// L814
        for (int v476 = 0; v476 < 28; v476 += 1) {	// L815
          int8_t v477 = v465[v473][v474][v475][v476];	// L816
          v468[v473][v474][(v475 + 1)][(v476 + 1)] = v477;	// L817
        }
      }
    }
  }
  int8_t v478[1][128][28][28];	// L822
  // #pragma HLS stream variable=v478 depth=10 type=fifo

  #pragma HLS bind_storage variable=v478 type=ram_t2p impl=bram

  for (int v479 = 0; v479 < 1; v479 += 1) {	// L823
    for (int v480 = 0; v480 < 128; v480 += 1) {	// L824
      for (int v481 = 0; v481 < 28; v481 += 1) {	// L825
        for (int v482 = 0; v482 < 28; v482 += 1) {	// L826
          v478[v479][v480][v481][v482] = (int8_t)0.000000;	// L827
        }
      }
    }
  }
  for (int v483 = 0; v483 < 1; v483 += 1) {	// L832
    for (int v484 = 0; v484 < 128; v484 += 1) {	// L833
      for (int v485 = 0; v485 < 28; v485 += 1) {	// L834
        for (int v486 = 0; v486 < 28; v486 += 1) {	// L835
          for (int v487 = 0; v487 < 128; v487 += 1) {	// L836
            for (int v488 = 0; v488 < 3; v488 += 1) {	// L837
              for (int v489 = 0; v489 < 3; v489 += 1) {	// L838
                int8_t v490 = v468[v483][v487][(v485 + v488)][(v486 + v489)];	// L839
                int8_t v491 = v466[v484][v487][v488][v489];	// L840
                int8_t v492 = v478[v483][v484][v485][v486];	// L841
                int8_t v493 = v490 * v491;	// L842
                int8_t v494 = v492 + v493;	// L843
                v478[v483][v484][v485][v486] = v494;	// L844
              }
            }
          }
        }
      }
    }
  }
  for (int v495 = 0; v495 < 1; v495 += 1) {	// L852
    for (int v496 = 0; v496 < 128; v496 += 1) {	// L853
      for (int v497 = 0; v497 < 28; v497 += 1) {	// L854
        for (int v498 = 0; v498 < 28; v498 += 1) {	// L855
          int8_t v499 = v478[0][v496][v497][v498];	// L856
          bool v500 = v499 > (int8_t)0.000000;	// L857
          int8_t v501 = v500 ? v499 : (int8_t)0.000000;	// L858
          v467[v495][v496][v497][v498] = v501;	// L859
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v502[1][64][56][56],
  int8_t v503[1][128][28][28],
  int8_t v504[128][64][1][1],
  int8_t v505[1][128][28][28]
) {	// L866
  // #pragma HLS dataflow

  int8_t v506[1][128][28][28];	// L868
  // #pragma HLS stream variable=v506 depth=10 type=fifo

  #pragma HLS bind_storage variable=v506 type=ram_t2p impl=bram

  for (int v507 = 0; v507 < 1; v507 += 1) {	// L869
    for (int v508 = 0; v508 < 128; v508 += 1) {	// L870
      for (int v509 = 0; v509 < 28; v509 += 1) {	// L871
        for (int v510 = 0; v510 < 28; v510 += 1) {	// L872
          v506[v507][v508][v509][v510] = (int8_t)0.000000;	// L873
        }
      }
    }
  }
  for (int v511 = 0; v511 < 1; v511 += 1) {	// L878
    for (int v512 = 0; v512 < 128; v512 += 1) {	// L879
      for (int v513 = 0; v513 < 28; v513 += 1) {	// L880
        for (int v514 = 0; v514 < 28; v514 += 1) {	// L881
          for (int v515 = 0; v515 < 64; v515 += 1) {	// L882
            for (int v516 = 0; v516 < 1; v516 += 1) {	// L883
              for (int v517 = 0; v517 < 1; v517 += 1) {	// L884
                int8_t v518 = v502[v511][v515][((v513 * 2) + v516)][((v514 * 2) + v517)];	// L885
                int8_t v519 = v504[v512][v515][v516][v517];	// L886
                int8_t v520 = v506[v511][v512][v513][v514];	// L887
                int8_t v521 = v518 * v519;	// L888
                int8_t v522 = v520 + v521;	// L889
                v506[v511][v512][v513][v514] = v522;	// L890
              }
            }
          }
        }
      }
    }
  }
  for (int v523 = 0; v523 < 1; v523 += 1) {	// L898
    for (int v524 = 0; v524 < 128; v524 += 1) {	// L899
      for (int v525 = 0; v525 < 28; v525 += 1) {	// L900
        for (int v526 = 0; v526 < 28; v526 += 1) {	// L901
          int8_t v527 = v503[0][v524][v525][v526];	// L902
          int8_t v528 = v506[0][v524][v525][v526];	// L903
          int8_t v529 = v527 + v528;	// L904
          bool v530 = v529 > (int8_t)0.000000;	// L905
          int8_t v531 = v530 ? v529 : (int8_t)0.000000;	// L906
          v505[v523][v524][v525][v526] = v531;	// L907
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v532[128][128][3][3],
  int8_t v533[1][128][28][28],
  int8_t v534[1][128][28][28]
) {	// L914
  // #pragma HLS dataflow

  int8_t v535[1][128][30][30];	// L916
  // #pragma HLS stream variable=v535 depth=10 type=fifo

  #pragma HLS bind_storage variable=v535 type=ram_t2p impl=bram

  for (int v536 = 0; v536 < 1; v536 += 1) {	// L917
    for (int v537 = 0; v537 < 128; v537 += 1) {	// L918
      for (int v538 = 0; v538 < 30; v538 += 1) {	// L919
        for (int v539 = 0; v539 < 30; v539 += 1) {	// L920
          v535[v536][v537][v538][v539] = (int8_t)0.000000;	// L921
        }
      }
    }
  }
  for (int v540 = 0; v540 < 1; v540 += 1) {	// L926
    for (int v541 = 0; v541 < 128; v541 += 1) {	// L927
      for (int v542 = 0; v542 < 28; v542 += 1) {	// L928
        for (int v543 = 0; v543 < 28; v543 += 1) {	// L929
          int8_t v544 = v533[v540][v541][v542][v543];	// L930
          v535[v540][v541][(v542 + 1)][(v543 + 1)] = v544;	// L931
        }
      }
    }
  }
  for (int v545 = 0; v545 < 1; v545 += 1) {	// L936
    for (int v546 = 0; v546 < 128; v546 += 1) {	// L937
      for (int v547 = 0; v547 < 28; v547 += 1) {	// L938
        for (int v548 = 0; v548 < 28; v548 += 1) {	// L939
          v534[v545][v546][v547][v548] = (int8_t)0.000000;	// L940
        }
      }
    }
  }
  for (int v549 = 0; v549 < 1; v549 += 1) {	// L945
    for (int v550 = 0; v550 < 128; v550 += 1) {	// L946
      for (int v551 = 0; v551 < 28; v551 += 1) {	// L947
        for (int v552 = 0; v552 < 28; v552 += 1) {	// L948
          for (int v553 = 0; v553 < 128; v553 += 1) {	// L949
            for (int v554 = 0; v554 < 3; v554 += 1) {	// L950
              for (int v555 = 0; v555 < 3; v555 += 1) {	// L951
                int8_t v556 = v535[v549][v553][(v551 + v554)][(v552 + v555)];	// L952
                int8_t v557 = v532[v550][v553][v554][v555];	// L953
                int8_t v558 = v534[v549][v550][v551][v552];	// L954
                int8_t v559 = v556 * v557;	// L955
                int8_t v560 = v558 + v559;	// L956
                v534[v549][v550][v551][v552] = v560;	// L957
              }
            }
          }
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v561[128][64][3][3],
  int8_t v562[1][64][56][56],
  int8_t v563[1][128][28][28]
) {	// L967
  // #pragma HLS dataflow

  int8_t v564[1][64][58][58];	// L969
  // #pragma HLS stream variable=v564 depth=10 type=fifo

  #pragma HLS bind_storage variable=v564 type=ram_t2p impl=bram

  for (int v565 = 0; v565 < 1; v565 += 1) {	// L970
    for (int v566 = 0; v566 < 64; v566 += 1) {	// L971
      for (int v567 = 0; v567 < 58; v567 += 1) {	// L972
        for (int v568 = 0; v568 < 58; v568 += 1) {	// L973
          v564[v565][v566][v567][v568] = (int8_t)0.000000;	// L974
        }
      }
    }
  }
  for (int v569 = 0; v569 < 1; v569 += 1) {	// L979
    for (int v570 = 0; v570 < 64; v570 += 1) {	// L980
      for (int v571 = 0; v571 < 56; v571 += 1) {	// L981
        for (int v572 = 0; v572 < 56; v572 += 1) {	// L982
          int8_t v573 = v562[v569][v570][v571][v572];	// L983
          v564[v569][v570][(v571 + 1)][(v572 + 1)] = v573;	// L984
        }
      }
    }
  }
  int8_t v574[1][128][28][28];	// L989
  // #pragma HLS stream variable=v574 depth=10 type=fifo

  #pragma HLS bind_storage variable=v574 type=ram_t2p impl=bram

  for (int v575 = 0; v575 < 1; v575 += 1) {	// L990
    for (int v576 = 0; v576 < 128; v576 += 1) {	// L991
      for (int v577 = 0; v577 < 28; v577 += 1) {	// L992
        for (int v578 = 0; v578 < 28; v578 += 1) {	// L993
          v574[v575][v576][v577][v578] = (int8_t)0.000000;	// L994
        }
      }
    }
  }
  for (int v579 = 0; v579 < 1; v579 += 1) {	// L999
    for (int v580 = 0; v580 < 128; v580 += 1) {	// L1000
      for (int v581 = 0; v581 < 28; v581 += 1) {	// L1001
        for (int v582 = 0; v582 < 28; v582 += 1) {	// L1002
          for (int v583 = 0; v583 < 64; v583 += 1) {	// L1003
            for (int v584 = 0; v584 < 3; v584 += 1) {	// L1004
              for (int v585 = 0; v585 < 3; v585 += 1) {	// L1005
                int8_t v586 = v564[v579][v583][((v581 * 2) + v584)][((v582 * 2) + v585)];	// L1006
                int8_t v587 = v561[v580][v583][v584][v585];	// L1007
                int8_t v588 = v574[v579][v580][v581][v582];	// L1008
                int8_t v589 = v586 * v587;	// L1009
                int8_t v590 = v588 + v589;	// L1010
                v574[v579][v580][v581][v582] = v590;	// L1011
              }
            }
          }
        }
      }
    }
  }
  for (int v591 = 0; v591 < 1; v591 += 1) {	// L1019
    for (int v592 = 0; v592 < 128; v592 += 1) {	// L1020
      for (int v593 = 0; v593 < 28; v593 += 1) {	// L1021
        for (int v594 = 0; v594 < 28; v594 += 1) {	// L1022
          int8_t v595 = v574[0][v592][v593][v594];	// L1023
          bool v596 = v595 > (int8_t)0.000000;	// L1024
          int8_t v597 = v596 ? v595 : (int8_t)0.000000;	// L1025
          v563[v591][v592][v593][v594] = v597;	// L1026
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v598[1][64][56][56],
  int8_t v599[64][64][3][3],
  int8_t v600[1][64][56][56],
  int8_t v601[1][64][56][56]
) {	// L1033
  // #pragma HLS dataflow

  int8_t v602[1][64][58][58];	// L1035
  // #pragma HLS stream variable=v602 depth=10 type=fifo

  #pragma HLS bind_storage variable=v602 type=ram_t2p impl=bram

  for (int v603 = 0; v603 < 1; v603 += 1) {	// L1036
    for (int v604 = 0; v604 < 64; v604 += 1) {	// L1037
      for (int v605 = 0; v605 < 58; v605 += 1) {	// L1038
        for (int v606 = 0; v606 < 58; v606 += 1) {	// L1039
          v602[v603][v604][v605][v606] = (int8_t)0.000000;	// L1040
        }
      }
    }
  }
  for (int v607 = 0; v607 < 1; v607 += 1) {	// L1045
    for (int v608 = 0; v608 < 64; v608 += 1) {	// L1046
      for (int v609 = 0; v609 < 56; v609 += 1) {	// L1047
        for (int v610 = 0; v610 < 56; v610 += 1) {	// L1048
          int8_t v611 = v600[v607][v608][v609][v610];	// L1049
          v602[v607][v608][(v609 + 1)][(v610 + 1)] = v611;	// L1050
        }
      }
    }
  }
  int8_t v612[1][64][56][56];	// L1055
  // #pragma HLS stream variable=v612 depth=10 type=fifo

  #pragma HLS bind_storage variable=v612 type=ram_t2p impl=bram

  for (int v613 = 0; v613 < 1; v613 += 1) {	// L1056
    for (int v614 = 0; v614 < 64; v614 += 1) {	// L1057
      for (int v615 = 0; v615 < 56; v615 += 1) {	// L1058
        for (int v616 = 0; v616 < 56; v616 += 1) {	// L1059
          v612[v613][v614][v615][v616] = (int8_t)0.000000;	// L1060
        }
      }
    }
  }
  for (int v617 = 0; v617 < 1; v617 += 1) {	// L1065
    for (int v618 = 0; v618 < 64; v618 += 1) {	// L1066
      for (int v619 = 0; v619 < 56; v619 += 1) {	// L1067
        for (int v620 = 0; v620 < 56; v620 += 1) {	// L1068
          for (int v621 = 0; v621 < 64; v621 += 1) {	// L1069
            for (int v622 = 0; v622 < 3; v622 += 1) {	// L1070
              for (int v623 = 0; v623 < 3; v623 += 1) {	// L1071
                int8_t v624 = v602[v617][v621][(v619 + v622)][(v620 + v623)];	// L1072
                int8_t v625 = v599[v618][v621][v622][v623];	// L1073
                int8_t v626 = v612[v617][v618][v619][v620];	// L1074
                int8_t v627 = v624 * v625;	// L1075
                int8_t v628 = v626 + v627;	// L1076
                v612[v617][v618][v619][v620] = v628;	// L1077
              }
            }
          }
        }
      }
    }
  }
  for (int v629 = 0; v629 < 1; v629 += 1) {	// L1085
    for (int v630 = 0; v630 < 64; v630 += 1) {	// L1086
      for (int v631 = 0; v631 < 56; v631 += 1) {	// L1087
        for (int v632 = 0; v632 < 56; v632 += 1) {	// L1088
          int8_t v633 = v612[0][v630][v631][v632];	// L1089
          int8_t v634 = v598[0][v630][v631][v632];	// L1090
          int8_t v635 = v633 + v634;	// L1091
          bool v636 = v635 > (int8_t)0.000000;	// L1092
          int8_t v637 = v636 ? v635 : (int8_t)0.000000;	// L1093
          v601[v629][v630][v631][v632] = v637;	// L1094
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v638[1][64][56][56],
  int8_t v639[64][64][3][3],
  int8_t v640[1][64][56][56]
) {	// L1101
  // #pragma HLS dataflow

  int8_t v641[1][64][58][58];	// L1103
  // #pragma HLS stream variable=v641 depth=10 type=fifo

  #pragma HLS bind_storage variable=v641 type=ram_t2p impl=bram

  for (int v642 = 0; v642 < 1; v642 += 1) {	// L1104
    for (int v643 = 0; v643 < 64; v643 += 1) {	// L1105
      for (int v644 = 0; v644 < 58; v644 += 1) {	// L1106
        for (int v645 = 0; v645 < 58; v645 += 1) {	// L1107
          v641[v642][v643][v644][v645] = (int8_t)0.000000;	// L1108
        }
      }
    }
  }
  for (int v646 = 0; v646 < 1; v646 += 1) {	// L1113
    for (int v647 = 0; v647 < 64; v647 += 1) {	// L1114
      for (int v648 = 0; v648 < 56; v648 += 1) {	// L1115
        for (int v649 = 0; v649 < 56; v649 += 1) {	// L1116
          int8_t v650 = v638[v646][v647][v648][v649];	// L1117
          v641[v646][v647][(v648 + 1)][(v649 + 1)] = v650;	// L1118
        }
      }
    }
  }
  int8_t v651[1][64][56][56];	// L1123
  // #pragma HLS stream variable=v651 depth=10 type=fifo

  #pragma HLS bind_storage variable=v651 type=ram_t2p impl=bram

  for (int v652 = 0; v652 < 1; v652 += 1) {	// L1124
    for (int v653 = 0; v653 < 64; v653 += 1) {	// L1125
      for (int v654 = 0; v654 < 56; v654 += 1) {	// L1126
        for (int v655 = 0; v655 < 56; v655 += 1) {	// L1127
          v651[v652][v653][v654][v655] = (int8_t)0.000000;	// L1128
        }
      }
    }
  }
  for (int v656 = 0; v656 < 1; v656 += 1) {	// L1133
    for (int v657 = 0; v657 < 64; v657 += 1) {	// L1134
      for (int v658 = 0; v658 < 56; v658 += 1) {	// L1135
        for (int v659 = 0; v659 < 56; v659 += 1) {	// L1136
          for (int v660 = 0; v660 < 64; v660 += 1) {	// L1137
            for (int v661 = 0; v661 < 3; v661 += 1) {	// L1138
              for (int v662 = 0; v662 < 3; v662 += 1) {	// L1139
                int8_t v663 = v641[v656][v660][(v658 + v661)][(v659 + v662)];	// L1140
                int8_t v664 = v639[v657][v660][v661][v662];	// L1141
                int8_t v665 = v651[v656][v657][v658][v659];	// L1142
                int8_t v666 = v663 * v664;	// L1143
                int8_t v667 = v665 + v666;	// L1144
                v651[v656][v657][v658][v659] = v667;	// L1145
              }
            }
          }
        }
      }
    }
  }
  for (int v668 = 0; v668 < 1; v668 += 1) {	// L1153
    for (int v669 = 0; v669 < 64; v669 += 1) {	// L1154
      for (int v670 = 0; v670 < 56; v670 += 1) {	// L1155
        for (int v671 = 0; v671 < 56; v671 += 1) {	// L1156
          int8_t v672 = v651[0][v669][v670][v671];	// L1157
          bool v673 = v672 > (int8_t)0.000000;	// L1158
          int8_t v674 = v673 ? v672 : (int8_t)0.000000;	// L1159
          v640[v668][v669][v670][v671] = v674;	// L1160
        }
      }
    }
  }
}

void main_graph_node21(
  int8_t v675[1][64][56][56],
  int8_t v676[64][64][3][3],
  int8_t v677[1][64][56][56],
  int8_t v678[1][64][56][56]
) {	// L1167
  // #pragma HLS dataflow

  int8_t v679[1][64][58][58];	// L1169
  // #pragma HLS stream variable=v679 depth=10 type=fifo

  #pragma HLS bind_storage variable=v679 type=ram_t2p impl=bram

  for (int v680 = 0; v680 < 1; v680 += 1) {	// L1170
    for (int v681 = 0; v681 < 64; v681 += 1) {	// L1171
      for (int v682 = 0; v682 < 58; v682 += 1) {	// L1172
        for (int v683 = 0; v683 < 58; v683 += 1) {	// L1173
          v679[v680][v681][v682][v683] = (int8_t)0.000000;	// L1174
        }
      }
    }
  }
  for (int v684 = 0; v684 < 1; v684 += 1) {	// L1179
    for (int v685 = 0; v685 < 64; v685 += 1) {	// L1180
      for (int v686 = 0; v686 < 56; v686 += 1) {	// L1181
        for (int v687 = 0; v687 < 56; v687 += 1) {	// L1182
          int8_t v688 = v677[v684][v685][v686][v687];	// L1183
          v679[v684][v685][(v686 + 1)][(v687 + 1)] = v688;	// L1184
        }
      }
    }
  }
  int8_t v689[1][64][56][56];	// L1189
  // #pragma HLS stream variable=v689 depth=10 type=fifo

  #pragma HLS bind_storage variable=v689 type=ram_t2p impl=bram

  for (int v690 = 0; v690 < 1; v690 += 1) {	// L1190
    for (int v691 = 0; v691 < 64; v691 += 1) {	// L1191
      for (int v692 = 0; v692 < 56; v692 += 1) {	// L1192
        for (int v693 = 0; v693 < 56; v693 += 1) {	// L1193
          v689[v690][v691][v692][v693] = (int8_t)0.000000;	// L1194
        }
      }
    }
  }
  for (int v694 = 0; v694 < 1; v694 += 1) {	// L1199
    for (int v695 = 0; v695 < 64; v695 += 1) {	// L1200
      for (int v696 = 0; v696 < 56; v696 += 1) {	// L1201
        for (int v697 = 0; v697 < 56; v697 += 1) {	// L1202
          for (int v698 = 0; v698 < 64; v698 += 1) {	// L1203
            for (int v699 = 0; v699 < 3; v699 += 1) {	// L1204
              for (int v700 = 0; v700 < 3; v700 += 1) {	// L1205
                int8_t v701 = v679[v694][v698][(v696 + v699)][(v697 + v700)];	// L1206
                int8_t v702 = v676[v695][v698][v699][v700];	// L1207
                int8_t v703 = v689[v694][v695][v696][v697];	// L1208
                int8_t v704 = v701 * v702;	// L1209
                int8_t v705 = v703 + v704;	// L1210
                v689[v694][v695][v696][v697] = v705;	// L1211
              }
            }
          }
        }
      }
    }
  }
  for (int v706 = 0; v706 < 1; v706 += 1) {	// L1219
    for (int v707 = 0; v707 < 64; v707 += 1) {	// L1220
      for (int v708 = 0; v708 < 56; v708 += 1) {	// L1221
        for (int v709 = 0; v709 < 56; v709 += 1) {	// L1222
          int8_t v710 = v689[0][v707][v708][v709];	// L1223
          int8_t v711 = v675[0][v707][v708][v709];	// L1224
          int8_t v712 = v710 + v711;	// L1225
          bool v713 = v712 > (int8_t)0.000000;	// L1226
          int8_t v714 = v713 ? v712 : (int8_t)0.000000;	// L1227
          v678[v706][v707][v708][v709] = v714;	// L1228
        }
      }
    }
  }
}

void main_graph_node22(
  int8_t v715[1][64][56][56],
  int8_t v716[64][64][3][3],
  int8_t v717[1][64][56][56]
) {	// L1235
  // #pragma HLS dataflow

  int8_t v718[1][64][58][58];	// L1237
  // #pragma HLS stream variable=v718 depth=10 type=fifo

  #pragma HLS bind_storage variable=v718 type=ram_t2p impl=bram

  for (int v719 = 0; v719 < 1; v719 += 1) {	// L1238
    for (int v720 = 0; v720 < 64; v720 += 1) {	// L1239
      for (int v721 = 0; v721 < 58; v721 += 1) {	// L1240
        for (int v722 = 0; v722 < 58; v722 += 1) {	// L1241
          v718[v719][v720][v721][v722] = (int8_t)0.000000;	// L1242
        }
      }
    }
  }
  for (int v723 = 0; v723 < 1; v723 += 1) {	// L1247
    for (int v724 = 0; v724 < 64; v724 += 1) {	// L1248
      for (int v725 = 0; v725 < 56; v725 += 1) {	// L1249
        for (int v726 = 0; v726 < 56; v726 += 1) {	// L1250
          int8_t v727 = v715[v723][v724][v725][v726];	// L1251
          v718[v723][v724][(v725 + 1)][(v726 + 1)] = v727;	// L1252
        }
      }
    }
  }
  int8_t v728[1][64][56][56];	// L1257
  // #pragma HLS stream variable=v728 depth=10 type=fifo

  #pragma HLS bind_storage variable=v728 type=ram_t2p impl=bram

  for (int v729 = 0; v729 < 1; v729 += 1) {	// L1258
    for (int v730 = 0; v730 < 64; v730 += 1) {	// L1259
      for (int v731 = 0; v731 < 56; v731 += 1) {	// L1260
        for (int v732 = 0; v732 < 56; v732 += 1) {	// L1261
          v728[v729][v730][v731][v732] = (int8_t)0.000000;	// L1262
        }
      }
    }
  }
  for (int v733 = 0; v733 < 1; v733 += 1) {	// L1267
    for (int v734 = 0; v734 < 64; v734 += 1) {	// L1268
      for (int v735 = 0; v735 < 56; v735 += 1) {	// L1269
        for (int v736 = 0; v736 < 56; v736 += 1) {	// L1270
          for (int v737 = 0; v737 < 64; v737 += 1) {	// L1271
            for (int v738 = 0; v738 < 3; v738 += 1) {	// L1272
              for (int v739 = 0; v739 < 3; v739 += 1) {	// L1273
                int8_t v740 = v718[v733][v737][(v735 + v738)][(v736 + v739)];	// L1274
                int8_t v741 = v716[v734][v737][v738][v739];	// L1275
                int8_t v742 = v728[v733][v734][v735][v736];	// L1276
                int8_t v743 = v740 * v741;	// L1277
                int8_t v744 = v742 + v743;	// L1278
                v728[v733][v734][v735][v736] = v744;	// L1279
              }
            }
          }
        }
      }
    }
  }
  for (int v745 = 0; v745 < 1; v745 += 1) {	// L1287
    for (int v746 = 0; v746 < 64; v746 += 1) {	// L1288
      for (int v747 = 0; v747 < 56; v747 += 1) {	// L1289
        for (int v748 = 0; v748 < 56; v748 += 1) {	// L1290
          int8_t v749 = v728[0][v746][v747][v748];	// L1291
          bool v750 = v749 > (int8_t)0.000000;	// L1292
          int8_t v751 = v750 ? v749 : (int8_t)0.000000;	// L1293
          v717[v745][v746][v747][v748] = v751;	// L1294
        }
      }
    }
  }
}

void main_graph_node23(
  int8_t v752[1][64][112][112],
  int8_t v753[1][64][56][56]
) {	// L1301
  // #pragma HLS dataflow

  int8_t v754[1][64][114][114];	// L1303
  // #pragma HLS stream variable=v754 depth=10 type=fifo

  #pragma HLS bind_storage variable=v754 type=ram_t2p impl=bram

  for (int v755 = 0; v755 < 1; v755 += 1) {	// L1304
    for (int v756 = 0; v756 < 64; v756 += 1) {	// L1305
      for (int v757 = 0; v757 < 114; v757 += 1) {	// L1306
        for (int v758 = 0; v758 < 114; v758 += 1) {	// L1307
          v754[v755][v756][v757][v758] = (int8_t)-INFINITY;	// L1308
        }
      }
    }
  }
  for (int v759 = 0; v759 < 1; v759 += 1) {	// L1313
    for (int v760 = 0; v760 < 64; v760 += 1) {	// L1314
      for (int v761 = 0; v761 < 112; v761 += 1) {	// L1315
        for (int v762 = 0; v762 < 112; v762 += 1) {	// L1316
          int8_t v763 = v752[v759][v760][v761][v762];	// L1317
          v754[v759][v760][(v761 + 1)][(v762 + 1)] = v763;	// L1318
        }
      }
    }
  }
  for (int v764 = 0; v764 < 1; v764 += 1) {	// L1323
    for (int v765 = 0; v765 < 64; v765 += 1) {	// L1324
      for (int v766 = 0; v766 < 56; v766 += 1) {	// L1325
        for (int v767 = 0; v767 < 56; v767 += 1) {	// L1326
          v753[v764][v765][v766][v767] = (int8_t)-INFINITY;	// L1327
        }
      }
    }
  }
  for (int v768 = 0; v768 < 1; v768 += 1) {	// L1332
    for (int v769 = 0; v769 < 64; v769 += 1) {	// L1333
      for (int v770 = 0; v770 < 56; v770 += 1) {	// L1334
        for (int v771 = 0; v771 < 56; v771 += 1) {	// L1335
          for (int v772 = 0; v772 < 3; v772 += 1) {	// L1336
            for (int v773 = 0; v773 < 3; v773 += 1) {	// L1337
              int8_t v774 = v754[v768][v769][((v770 * 2) + v772)][((v771 * 2) + v773)];	// L1338
              int8_t v775 = v753[v768][v769][v770][v771];	// L1339
              int8_t v776 = max(v775, v774);	// L1340
              v753[v768][v769][v770][v771] = v776;	// L1341
            }
          }
        }
      }
    }
  }
}

void main_graph_node24(
  int8_t v777[1][64][224][224],
  int8_t v778[1][64][112][112]
) {	// L1350
  // #pragma HLS dataflow

  int8_t v779[1][64][112][112];	// L1353
  // #pragma HLS stream variable=v779 depth=10 type=fifo

  #pragma HLS bind_storage variable=v779 type=ram_t2p impl=bram

  for (int v780 = 0; v780 < 1; v780 += 1) {	// L1354
    for (int v781 = 0; v781 < 64; v781 += 1) {	// L1355
      for (int v782 = 0; v782 < 112; v782 += 1) {	// L1356
        for (int v783 = 0; v783 < 112; v783 += 1) {	// L1357
          v779[v780][v781][v782][v783] = (int8_t)-INFINITY;	// L1358
        }
      }
    }
  }
  for (int v784 = 0; v784 < 1; v784 += 1) {	// L1363
    for (int v785 = 0; v785 < 64; v785 += 1) {	// L1364
      for (int v786 = 0; v786 < 112; v786 += 1) {	// L1365
        for (int v787 = 0; v787 < 112; v787 += 1) {	// L1366
          for (int v788 = 0; v788 < 2; v788 += 1) {	// L1367
            for (int v789 = 0; v789 < 2; v789 += 1) {	// L1368
              int8_t v790 = v777[v784][v785][((v786 * 2) + v788)][((v787 * 2) + v789)];	// L1369
              int8_t v791 = v779[v784][v785][v786][v787];	// L1370
              int8_t v792 = max(v791, v790);	// L1371
              v779[v784][v785][v786][v787] = v792;	// L1372
            }
          }
        }
      }
    }
  }
  for (int v793 = 0; v793 < 1; v793 += 1) {	// L1379
    for (int v794 = 0; v794 < 64; v794 += 1) {	// L1380
      for (int v795 = 0; v795 < 112; v795 += 1) {	// L1381
        for (int v796 = 0; v796 < 112; v796 += 1) {	// L1382
          int8_t v797 = v779[0][v794][v795][v796];	// L1383
          bool v798 = v797 > (int8_t)0.000000;	// L1384
          int8_t v799 = v798 ? v797 : (int8_t)0.000000;	// L1385
          v778[v793][v794][v795][v796] = v799;	// L1386
        }
      }
    }
  }
}

void main_graph_node25(
  int8_t v800[64][3][7][7],
  int8_t v801[1][3][224][224],
  int8_t v802[1][64][224][224]
) {	// L1393
  // #pragma HLS dataflow

  int8_t v803[1][3][230][230];	// L1395
  // #pragma HLS stream variable=v803 depth=10 type=fifo

  #pragma HLS bind_storage variable=v803 type=ram_t2p impl=bram

  for (int v804 = 0; v804 < 1; v804 += 1) {	// L1396
    for (int v805 = 0; v805 < 3; v805 += 1) {	// L1397
      for (int v806 = 0; v806 < 230; v806 += 1) {	// L1398
        for (int v807 = 0; v807 < 230; v807 += 1) {	// L1399
          v803[v804][v805][v806][v807] = (int8_t)0.000000;	// L1400
        }
      }
    }
  }
  for (int v808 = 0; v808 < 1; v808 += 1) {	// L1405
    for (int v809 = 0; v809 < 3; v809 += 1) {	// L1406
      for (int v810 = 0; v810 < 224; v810 += 1) {	// L1407
        for (int v811 = 0; v811 < 224; v811 += 1) {	// L1408
          int8_t v812 = v801[v808][v809][v810][v811];	// L1409
          v803[v808][v809][(v810 + 3)][(v811 + 3)] = v812;	// L1410
        }
      }
    }
  }
  for (int v813 = 0; v813 < 1; v813 += 1) {	// L1415
    for (int v814 = 0; v814 < 64; v814 += 1) {	// L1416
      for (int v815 = 0; v815 < 224; v815 += 1) {	// L1417
        for (int v816 = 0; v816 < 224; v816 += 1) {	// L1418
          v802[v813][v814][v815][v816] = (int8_t)0.000000;	// L1419
        }
      }
    }
  }
  for (int v817 = 0; v817 < 1; v817 += 1) {	// L1424
    for (int v818 = 0; v818 < 64; v818 += 1) {	// L1425
      for (int v819 = 0; v819 < 224; v819 += 1) {	// L1426
        for (int v820 = 0; v820 < 224; v820 += 1) {	// L1427
          for (int v821 = 0; v821 < 3; v821 += 1) {	// L1428
            for (int v822 = 0; v822 < 7; v822 += 1) {	// L1429
              for (int v823 = 0; v823 < 7; v823 += 1) {	// L1430
                int8_t v824 = v803[v817][v821][(v819 + v822)][(v820 + v823)];	// L1431
                int8_t v825 = v800[v818][v821][v822][v823];	// L1432
                int8_t v826 = v802[v817][v818][v819][v820];	// L1433
                int8_t v827 = v824 * v825;	// L1434
                int8_t v828 = v826 + v827;	// L1435
                v802[v817][v818][v819][v820] = v828;	// L1436
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
  int8_t v829[1][3][224][224],
  int8_t v830[1000],
  int8_t v831[512][512][3][3],
  int8_t v832[512][512][3][3],
  int8_t v833[512][256][1][1],
  int8_t v834[512][512][3][3],
  int8_t v835[512][256][3][3],
  int8_t v836[256][256][3][3],
  int8_t v837[256][256][3][3],
  int8_t v838[256][128][1][1],
  int8_t v839[256][256][3][3],
  int8_t v840[256][128][3][3],
  int8_t v841[128][128][3][3],
  int8_t v842[128][128][3][3],
  int8_t v843[128][64][1][1],
  int8_t v844[128][128][3][3],
  int8_t v845[128][64][3][3],
  int8_t v846[64][64][3][3],
  int8_t v847[64][64][3][3],
  int8_t v848[64][64][3][3],
  int8_t v849[64][64][3][3],
  int8_t v850[64][3][7][7],
  int8_t v851[512][1000],
  int8_t v852[1][1000]
) {	// L1446
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v829
  #pragma HLS bind_storage variable=v829 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v830
  #pragma HLS bind_storage variable=v830 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v831
  #pragma HLS bind_storage variable=v831 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v832
  #pragma HLS bind_storage variable=v832 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v833
  #pragma HLS bind_storage variable=v833 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v834
  #pragma HLS bind_storage variable=v834 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v835
  #pragma HLS bind_storage variable=v835 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v836
  #pragma HLS bind_storage variable=v836 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v837
  #pragma HLS bind_storage variable=v837 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v838
  #pragma HLS bind_storage variable=v838 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v839
  #pragma HLS bind_storage variable=v839 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v840
  #pragma HLS bind_storage variable=v840 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v841
  #pragma HLS bind_storage variable=v841 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v842
  #pragma HLS bind_storage variable=v842 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v843
  #pragma HLS bind_storage variable=v843 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v844
  #pragma HLS bind_storage variable=v844 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v845
  #pragma HLS bind_storage variable=v845 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v846
  #pragma HLS bind_storage variable=v846 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v847
  #pragma HLS bind_storage variable=v847 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v848
  #pragma HLS bind_storage variable=v848 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v849
  #pragma HLS bind_storage variable=v849 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v850
  #pragma HLS bind_storage variable=v850 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v851
  #pragma HLS bind_storage variable=v851 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v852
  #pragma HLS bind_storage variable=v852 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  int8_t v853[1][64][224][224];	// L1448
  // #pragma HLS stream variable=v853 depth=10 type=fifo

  #pragma HLS bind_storage variable=v853 type=ram_t2p impl=bram

  main_graph_node25(v850, v829, v853);	// L1449
  int8_t v854[1][64][112][112];	// L1450
  // #pragma HLS stream variable=v854 depth=10 type=fifo

  #pragma HLS bind_storage variable=v854 type=ram_t2p impl=bram

  main_graph_node24(v853, v854);	// L1451
  int8_t v855[1][64][56][56];	// L1452
  // #pragma HLS stream variable=v855 depth=10 type=fifo

  #pragma HLS bind_storage variable=v855 type=ram_t2p impl=bram

  main_graph_node23(v854, v855);	// L1453
  int8_t v856[1][64][56][56];	// L1454
  // #pragma HLS stream variable=v856 depth=10 type=fifo

  #pragma HLS bind_storage variable=v856 type=ram_t2p impl=bram

  main_graph_node22(v855, v849, v856);	// L1455
  int8_t v857[1][64][56][56];	// L1456
  // #pragma HLS stream variable=v857 depth=10 type=fifo

  #pragma HLS bind_storage variable=v857 type=ram_t2p impl=bram

  main_graph_node21(v855, v848, v856, v857);	// L1457
  int8_t v858[1][64][56][56];	// L1458
  // #pragma HLS stream variable=v858 depth=10 type=fifo

  #pragma HLS bind_storage variable=v858 type=ram_t2p impl=bram

  main_graph_node20(v857, v847, v858);	// L1459
  int8_t v859[1][64][56][56];	// L1460
  // #pragma HLS stream variable=v859 depth=10 type=fifo

  #pragma HLS bind_storage variable=v859 type=ram_t2p impl=bram

  main_graph_node19(v857, v846, v858, v859);	// L1461
  int8_t v860[1][128][28][28];	// L1462
  // #pragma HLS stream variable=v860 depth=10 type=fifo

  #pragma HLS bind_storage variable=v860 type=ram_t2p impl=bram

  main_graph_node18(v845, v859, v860);	// L1463
  int8_t v861[1][128][28][28];	// L1464
  // #pragma HLS stream variable=v861 depth=10 type=fifo

  #pragma HLS bind_storage variable=v861 type=ram_t2p impl=bram

  main_graph_node17(v844, v860, v861);	// L1465
  int8_t v862[1][128][28][28];	// L1466
  // #pragma HLS stream variable=v862 depth=10 type=fifo

  #pragma HLS bind_storage variable=v862 type=ram_t2p impl=bram

  main_graph_node16(v859, v861, v843, v862);	// L1467
  int8_t v863[1][128][28][28];	// L1468
  // #pragma HLS stream variable=v863 depth=10 type=fifo

  #pragma HLS bind_storage variable=v863 type=ram_t2p impl=bram

  main_graph_node15(v862, v842, v863);	// L1469
  int8_t v864[1][128][28][28];	// L1470
  // #pragma HLS stream variable=v864 depth=10 type=fifo

  #pragma HLS bind_storage variable=v864 type=ram_t2p impl=bram

  main_graph_node14(v841, v862, v863, v864);	// L1471
  int8_t v865[1][256][14][14];	// L1472
  // #pragma HLS stream variable=v865 depth=10 type=fifo

  #pragma HLS bind_storage variable=v865 type=ram_t2p impl=bram

  main_graph_node13(v864, v840, v865);	// L1473
  int8_t v866[1][256][14][14];	// L1474
  // #pragma HLS stream variable=v866 depth=10 type=fifo

  #pragma HLS bind_storage variable=v866 type=ram_t2p impl=bram

  main_graph_node12(v839, v865, v866);	// L1475
  int8_t v867[1][256][14][14];	// L1476
  // #pragma HLS stream variable=v867 depth=10 type=fifo

  #pragma HLS bind_storage variable=v867 type=ram_t2p impl=bram

  main_graph_node11(v864, v838, v866, v867);	// L1477
  int8_t v868[1][256][14][14];	// L1478
  // #pragma HLS stream variable=v868 depth=10 type=fifo

  #pragma HLS bind_storage variable=v868 type=ram_t2p impl=bram

  main_graph_node10(v837, v867, v868);	// L1479
  int8_t v869[1][256][14][14];	// L1480
  // #pragma HLS stream variable=v869 depth=10 type=fifo

  #pragma HLS bind_storage variable=v869 type=ram_t2p impl=bram

  main_graph_node9(v868, v867, v836, v869);	// L1481
  int8_t v870[1][512][7][7];	// L1482
  // #pragma HLS stream variable=v870 depth=10 type=fifo

  #pragma HLS bind_storage variable=v870 type=ram_t2p impl=bram

  main_graph_node8(v835, v869, v870);	// L1483
  int8_t v871[1][512][7][7];	// L1484
  // #pragma HLS stream variable=v871 depth=10 type=fifo

  #pragma HLS bind_storage variable=v871 type=ram_t2p impl=bram

  main_graph_node7(v834, v870, v871);	// L1485
  int8_t v872[1][512][7][7];	// L1486
  // #pragma HLS stream variable=v872 depth=10 type=fifo

  #pragma HLS bind_storage variable=v872 type=ram_t2p impl=bram

  main_graph_node6(v833, v871, v869, v872);	// L1487
  int8_t v873[1][512][7][7];	// L1488
  // #pragma HLS stream variable=v873 depth=10 type=fifo

  #pragma HLS bind_storage variable=v873 type=ram_t2p impl=bram

  main_graph_node5(v832, v872, v873);	// L1489
  int8_t v874[1][512][7][7];	// L1490
  // #pragma HLS stream variable=v874 depth=10 type=fifo

  #pragma HLS bind_storage variable=v874 type=ram_t2p impl=bram

  main_graph_node4(v831, v873, v872, v874);	// L1491
  int8_t v875[1][512][8][8];	// L1492
  // #pragma HLS stream variable=v875 depth=10 type=fifo

  #pragma HLS bind_storage variable=v875 type=ram_t2p impl=bram

  main_graph_node3(v874, v875);	// L1493
  int8_t v876[1][1];	// L1494
  // #pragma HLS stream variable=v876 depth=10 type=fifo

  #pragma HLS bind_storage variable=v876 type=ram_t2p impl=bram

  int8_t v877[1][512][1][1];	// L1495
  // #pragma HLS stream variable=v877 depth=10 type=fifo

  #pragma HLS bind_storage variable=v877 type=ram_t2p impl=bram

  main_graph_node2(v875, v876, v877);	// L1496
  int8_t v878[1][512][1][1];	// L1497
  // #pragma HLS stream variable=v878 depth=10 type=fifo

  #pragma HLS bind_storage variable=v878 type=ram_t2p impl=bram

  main_graph_node1(v877, v876, v878);	// L1498
  main_graph_node0(v851, v830, v878, v852);	// L1499
}

