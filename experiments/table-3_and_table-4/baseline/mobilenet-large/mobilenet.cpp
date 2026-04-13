
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
  int8_t v0[1000],
  int8_t v1[1024][1000],
  int8_t v2[1][1024][1][1],
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
      for (int v9 = 0; v9 < 1024; v9 += 1) {	// L13
        int8_t v10 = v2[v7][v9][0][0];	// L14
        int8_t v11 = v1[v9][v8];	// L15
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
      int8_t v18 = v0[v16];	// L26
      int8_t v19 = v17 + v18;	// L27
      v3[v15][v16] = v19;	// L28
    }
  }
}

void main_graph_node1(
  int8_t v20[1][1024][1][1],
  int8_t v21[1][1],
  int8_t v22[1][1024][1][1]
) {	// L33
  // #pragma HLS dataflow

  for (int v23 = 0; v23 < 1; v23 += 1) {	// L34
    for (int v24 = 0; v24 < 1024; v24 += 1) {	// L35
      for (int v25 = 0; v25 < 1; v25 += 1) {	// L36
        for (int v26 = 0; v26 < 1; v26 += 1) {	// L37
          int8_t v27 = v20[v23][v24][v25][v26];	// L38
          v22[v23][v24][v25][v26] = v27;	// L39
        }
      }
    }
  }
  for (int v28 = 0; v28 < 1; v28 += 1) {	// L44
    for (int v29 = 0; v29 < 1024; v29 += 1) {	// L45
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
  int8_t v35[1][1024][8][8],
  int8_t v36[1][1024][1][1],
  int8_t v37[1][1]
) {	// L58
  // #pragma HLS dataflow

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L62
    for (int v39 = 0; v39 < 1024; v39 += 1) {	// L63
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L64
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L65
          v36[v38][v39][v40][v41] = (int8_t)0.000000;	// L66
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L71
    for (int v43 = 0; v43 < 1024; v43 += 1) {	// L72
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L73
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L74
          for (int v46 = 0; v46 < 7; v46 += 1) {	// L75
            for (int v47 = 0; v47 < 7; v47 += 1) {	// L76
              int8_t v48 = v36[v42][v43][v44][v45];	// L77
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
              v36[v42][v43][v44][v45] = v62;	// L97
              v37[v44][v45] = v67;	// L98
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v68[1][1024][7][7],
  int8_t v69[1][1024][8][8]
) {	// L107
  // #pragma HLS dataflow

  for (int v70 = 0; v70 < 1; v70 += 1) {	// L109
    for (int v71 = 0; v71 < 1024; v71 += 1) {	// L110
      for (int v72 = 0; v72 < 8; v72 += 1) {	// L111
        for (int v73 = 0; v73 < 8; v73 += 1) {	// L112
          v69[v70][v71][v72][v73] = (int8_t)0.000000;	// L113
        }
      }
    }
  }
  for (int v74 = 0; v74 < 1; v74 += 1) {	// L118
    for (int v75 = 0; v75 < 1024; v75 += 1) {	// L119
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
  int8_t v79[1][1024][7][7],
  int8_t v80[1024][1024][1][1],
  int8_t v81[1][1024][7][7]
) {	// L130
  // #pragma HLS dataflow

  int8_t v82[1][1024][7][7];	// L132
  // #pragma HLS stream variable=v82 depth=10 type=fifo

  #pragma HLS bind_storage variable=v82 type=ram_t2p impl=bram

  for (int v83 = 0; v83 < 1; v83 += 1) {	// L133
    for (int v84 = 0; v84 < 1024; v84 += 1) {	// L134
      for (int v85 = 0; v85 < 7; v85 += 1) {	// L135
        for (int v86 = 0; v86 < 7; v86 += 1) {	// L136
          v82[v83][v84][v85][v86] = (int8_t)0.000000;	// L137
        }
      }
    }
  }
  for (int v87 = 0; v87 < 1; v87 += 1) {	// L142
    for (int v88 = 0; v88 < 1024; v88 += 1) {	// L143
      for (int v89 = 0; v89 < 7; v89 += 1) {	// L144
        for (int v90 = 0; v90 < 7; v90 += 1) {	// L145
          for (int v91 = 0; v91 < 1024; v91 += 1) {	// L146
            for (int v92 = 0; v92 < 1; v92 += 1) {	// L147
              for (int v93 = 0; v93 < 1; v93 += 1) {	// L148
                int8_t v94 = v79[v87][v91][(v89 + v92)][(v90 + v93)];	// L149
                int8_t v95 = v80[v88][v91][v92][v93];	// L150
                int8_t v96 = v82[v87][v88][v89][v90];	// L151
                int8_t v97 = v94 * v95;	// L152
                int8_t v98 = v96 + v97;	// L153
                v82[v87][v88][v89][v90] = v98;	// L154
              }
            }
          }
        }
      }
    }
  }
  for (int v99 = 0; v99 < 1; v99 += 1) {	// L162
    for (int v100 = 0; v100 < 1024; v100 += 1) {	// L163
      for (int v101 = 0; v101 < 7; v101 += 1) {	// L164
        for (int v102 = 0; v102 < 7; v102 += 1) {	// L165
          int8_t v103 = v82[0][v100][v101][v102];	// L166
          bool v104 = v103 > (int8_t)0.000000;	// L167
          int8_t v105 = v104 ? v103 : (int8_t)0.000000;	// L168
          v81[v99][v100][v101][v102] = v105;	// L169
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v106[1024][3][3],
  int8_t v107[1][1024][7][7],
  int8_t v108[1][1024][7][7]
) {	// L176
  // #pragma HLS dataflow

  int8_t v109[1][1024][9][9];	// L178
  // #pragma HLS stream variable=v109 depth=10 type=fifo

  #pragma HLS bind_storage variable=v109 type=ram_t2p impl=bram

  for (int v110 = 0; v110 < 1; v110 += 1) {	// L179
    for (int v111 = 0; v111 < 1024; v111 += 1) {	// L180
      for (int v112 = 0; v112 < 9; v112 += 1) {	// L181
        for (int v113 = 0; v113 < 9; v113 += 1) {	// L182
          v109[v110][v111][v112][v113] = (int8_t)0.000000;	// L183
        }
      }
    }
  }
  for (int v114 = 0; v114 < 1; v114 += 1) {	// L188
    for (int v115 = 0; v115 < 1024; v115 += 1) {	// L189
      for (int v116 = 0; v116 < 7; v116 += 1) {	// L190
        for (int v117 = 0; v117 < 7; v117 += 1) {	// L191
          int8_t v118 = v107[v114][v115][v116][v117];	// L192
          v109[v114][v115][(v116 + 1)][(v117 + 1)] = v118;	// L193
        }
      }
    }
  }
  int8_t v119[1][1024][7][7];	// L198
  // #pragma HLS stream variable=v119 depth=10 type=fifo

  #pragma HLS bind_storage variable=v119 type=ram_t2p impl=bram

  for (int v120 = 0; v120 < 1; v120 += 1) {	// L199
    for (int v121 = 0; v121 < 1024; v121 += 1) {	// L200
      for (int v122 = 0; v122 < 7; v122 += 1) {	// L201
        for (int v123 = 0; v123 < 7; v123 += 1) {	// L202
          v119[v120][v121][v122][v123] = (int8_t)0.000000;	// L203
        }
      }
    }
  }
  for (int v124 = 0; v124 < 1; v124 += 1) {	// L208
    for (int v125 = 0; v125 < 7; v125 += 1) {	// L209
      for (int v126 = 0; v126 < 7; v126 += 1) {	// L210
        for (int v127 = 0; v127 < 1024; v127 += 1) {	// L211
          for (int v128 = 0; v128 < 3; v128 += 1) {	// L212
            for (int v129 = 0; v129 < 3; v129 += 1) {	// L213
              int8_t v130 = v109[v124][v127][(v125 + v128)][(v126 + v129)];	// L214
              int8_t v131 = v106[v127][v128][v129];	// L215
              int8_t v132 = v119[v124][v127][v125][v126];	// L216
              int8_t v133 = v130 * v131;	// L217
              int8_t v134 = v132 + v133;	// L218
              v119[v124][v127][v125][v126] = v134;	// L219
            }
          }
        }
      }
    }
  }
  for (int v135 = 0; v135 < 1; v135 += 1) {	// L226
    for (int v136 = 0; v136 < 1024; v136 += 1) {	// L227
      for (int v137 = 0; v137 < 7; v137 += 1) {	// L228
        for (int v138 = 0; v138 < 7; v138 += 1) {	// L229
          int8_t v139 = v119[0][v136][v137][v138];	// L230
          bool v140 = v139 > (int8_t)0.000000;	// L231
          int8_t v141 = v140 ? v139 : (int8_t)0.000000;	// L232
          v108[v135][v136][v137][v138] = v141;	// L233
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v142[1024][512][1][1],
  int8_t v143[1][512][7][7],
  int8_t v144[1][1024][7][7]
) {	// L240
  // #pragma HLS dataflow

  int8_t v145[1][1024][7][7];	// L242
  // #pragma HLS stream variable=v145 depth=10 type=fifo

  #pragma HLS bind_storage variable=v145 type=ram_t2p impl=bram

  for (int v146 = 0; v146 < 1; v146 += 1) {	// L243
    for (int v147 = 0; v147 < 1024; v147 += 1) {	// L244
      for (int v148 = 0; v148 < 7; v148 += 1) {	// L245
        for (int v149 = 0; v149 < 7; v149 += 1) {	// L246
          v145[v146][v147][v148][v149] = (int8_t)0.000000;	// L247
        }
      }
    }
  }
  for (int v150 = 0; v150 < 1; v150 += 1) {	// L252
    for (int v151 = 0; v151 < 1024; v151 += 1) {	// L253
      for (int v152 = 0; v152 < 7; v152 += 1) {	// L254
        for (int v153 = 0; v153 < 7; v153 += 1) {	// L255
          for (int v154 = 0; v154 < 512; v154 += 1) {	// L256
            for (int v155 = 0; v155 < 1; v155 += 1) {	// L257
              for (int v156 = 0; v156 < 1; v156 += 1) {	// L258
                int8_t v157 = v143[v150][v154][(v152 + v155)][(v153 + v156)];	// L259
                int8_t v158 = v142[v151][v154][v155][v156];	// L260
                int8_t v159 = v145[v150][v151][v152][v153];	// L261
                int8_t v160 = v157 * v158;	// L262
                int8_t v161 = v159 + v160;	// L263
                v145[v150][v151][v152][v153] = v161;	// L264
              }
            }
          }
        }
      }
    }
  }
  for (int v162 = 0; v162 < 1; v162 += 1) {	// L272
    for (int v163 = 0; v163 < 1024; v163 += 1) {	// L273
      for (int v164 = 0; v164 < 7; v164 += 1) {	// L274
        for (int v165 = 0; v165 < 7; v165 += 1) {	// L275
          int8_t v166 = v145[0][v163][v164][v165];	// L276
          bool v167 = v166 > (int8_t)0.000000;	// L277
          int8_t v168 = v167 ? v166 : (int8_t)0.000000;	// L278
          v144[v162][v163][v164][v165] = v168;	// L279
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v169[512][3][3],
  int8_t v170[1][512][14][14],
  int8_t v171[1][512][7][7]
) {	// L286
  // #pragma HLS dataflow

  int8_t v172[1][512][16][16];	// L288
  // #pragma HLS stream variable=v172 depth=10 type=fifo

  #pragma HLS bind_storage variable=v172 type=ram_t2p impl=bram

  for (int v173 = 0; v173 < 1; v173 += 1) {	// L289
    for (int v174 = 0; v174 < 512; v174 += 1) {	// L290
      for (int v175 = 0; v175 < 16; v175 += 1) {	// L291
        for (int v176 = 0; v176 < 16; v176 += 1) {	// L292
          v172[v173][v174][v175][v176] = (int8_t)0.000000;	// L293
        }
      }
    }
  }
  for (int v177 = 0; v177 < 1; v177 += 1) {	// L298
    for (int v178 = 0; v178 < 512; v178 += 1) {	// L299
      for (int v179 = 0; v179 < 14; v179 += 1) {	// L300
        for (int v180 = 0; v180 < 14; v180 += 1) {	// L301
          int8_t v181 = v170[v177][v178][v179][v180];	// L302
          v172[v177][v178][(v179 + 1)][(v180 + 1)] = v181;	// L303
        }
      }
    }
  }
  int8_t v182[1][512][7][7];	// L308
  // #pragma HLS stream variable=v182 depth=10 type=fifo

  #pragma HLS bind_storage variable=v182 type=ram_t2p impl=bram

  for (int v183 = 0; v183 < 1; v183 += 1) {	// L309
    for (int v184 = 0; v184 < 512; v184 += 1) {	// L310
      for (int v185 = 0; v185 < 7; v185 += 1) {	// L311
        for (int v186 = 0; v186 < 7; v186 += 1) {	// L312
          v182[v183][v184][v185][v186] = (int8_t)0.000000;	// L313
        }
      }
    }
  }
  for (int v187 = 0; v187 < 1; v187 += 1) {	// L318
    for (int v188 = 0; v188 < 7; v188 += 1) {	// L319
      for (int v189 = 0; v189 < 7; v189 += 1) {	// L320
        for (int v190 = 0; v190 < 512; v190 += 1) {	// L321
          for (int v191 = 0; v191 < 3; v191 += 1) {	// L322
            for (int v192 = 0; v192 < 3; v192 += 1) {	// L323
              int8_t v193 = v172[v187][v190][((v188 * 2) + v191)][((v189 * 2) + v192)];	// L324
              int8_t v194 = v169[v190][v191][v192];	// L325
              int8_t v195 = v182[v187][v190][v188][v189];	// L326
              int8_t v196 = v193 * v194;	// L327
              int8_t v197 = v195 + v196;	// L328
              v182[v187][v190][v188][v189] = v197;	// L329
            }
          }
        }
      }
    }
  }
  for (int v198 = 0; v198 < 1; v198 += 1) {	// L336
    for (int v199 = 0; v199 < 512; v199 += 1) {	// L337
      for (int v200 = 0; v200 < 7; v200 += 1) {	// L338
        for (int v201 = 0; v201 < 7; v201 += 1) {	// L339
          int8_t v202 = v182[0][v199][v200][v201];	// L340
          bool v203 = v202 > (int8_t)0.000000;	// L341
          int8_t v204 = v203 ? v202 : (int8_t)0.000000;	// L342
          v171[v198][v199][v200][v201] = v204;	// L343
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v205[1][512][14][14],
  int8_t v206[512][512][1][1],
  int8_t v207[1][512][14][14]
) {	// L350
  // #pragma HLS dataflow

  int8_t v208[1][512][14][14];	// L352
  // #pragma HLS stream variable=v208 depth=10 type=fifo

  #pragma HLS bind_storage variable=v208 type=ram_t2p impl=bram

  for (int v209 = 0; v209 < 1; v209 += 1) {	// L353
    for (int v210 = 0; v210 < 512; v210 += 1) {	// L354
      for (int v211 = 0; v211 < 14; v211 += 1) {	// L355
        for (int v212 = 0; v212 < 14; v212 += 1) {	// L356
          v208[v209][v210][v211][v212] = (int8_t)0.000000;	// L357
        }
      }
    }
  }
  for (int v213 = 0; v213 < 1; v213 += 1) {	// L362
    for (int v214 = 0; v214 < 512; v214 += 1) {	// L363
      for (int v215 = 0; v215 < 14; v215 += 1) {	// L364
        for (int v216 = 0; v216 < 14; v216 += 1) {	// L365
          for (int v217 = 0; v217 < 512; v217 += 1) {	// L366
            for (int v218 = 0; v218 < 1; v218 += 1) {	// L367
              for (int v219 = 0; v219 < 1; v219 += 1) {	// L368
                int8_t v220 = v205[v213][v217][(v215 + v218)][(v216 + v219)];	// L369
                int8_t v221 = v206[v214][v217][v218][v219];	// L370
                int8_t v222 = v208[v213][v214][v215][v216];	// L371
                int8_t v223 = v220 * v221;	// L372
                int8_t v224 = v222 + v223;	// L373
                v208[v213][v214][v215][v216] = v224;	// L374
              }
            }
          }
        }
      }
    }
  }
  for (int v225 = 0; v225 < 1; v225 += 1) {	// L382
    for (int v226 = 0; v226 < 512; v226 += 1) {	// L383
      for (int v227 = 0; v227 < 14; v227 += 1) {	// L384
        for (int v228 = 0; v228 < 14; v228 += 1) {	// L385
          int8_t v229 = v208[0][v226][v227][v228];	// L386
          bool v230 = v229 > (int8_t)0.000000;	// L387
          int8_t v231 = v230 ? v229 : (int8_t)0.000000;	// L388
          v207[v225][v226][v227][v228] = v231;	// L389
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v232[1][512][14][14],
  int8_t v233[512][3][3],
  int8_t v234[1][512][14][14]
) {	// L396
  // #pragma HLS dataflow

  int8_t v235[1][512][16][16];	// L398
  // #pragma HLS stream variable=v235 depth=10 type=fifo

  #pragma HLS bind_storage variable=v235 type=ram_t2p impl=bram

  for (int v236 = 0; v236 < 1; v236 += 1) {	// L399
    for (int v237 = 0; v237 < 512; v237 += 1) {	// L400
      for (int v238 = 0; v238 < 16; v238 += 1) {	// L401
        for (int v239 = 0; v239 < 16; v239 += 1) {	// L402
          v235[v236][v237][v238][v239] = (int8_t)0.000000;	// L403
        }
      }
    }
  }
  for (int v240 = 0; v240 < 1; v240 += 1) {	// L408
    for (int v241 = 0; v241 < 512; v241 += 1) {	// L409
      for (int v242 = 0; v242 < 14; v242 += 1) {	// L410
        for (int v243 = 0; v243 < 14; v243 += 1) {	// L411
          int8_t v244 = v232[v240][v241][v242][v243];	// L412
          v235[v240][v241][(v242 + 1)][(v243 + 1)] = v244;	// L413
        }
      }
    }
  }
  int8_t v245[1][512][14][14];	// L418
  // #pragma HLS stream variable=v245 depth=10 type=fifo

  #pragma HLS bind_storage variable=v245 type=ram_t2p impl=bram

  for (int v246 = 0; v246 < 1; v246 += 1) {	// L419
    for (int v247 = 0; v247 < 512; v247 += 1) {	// L420
      for (int v248 = 0; v248 < 14; v248 += 1) {	// L421
        for (int v249 = 0; v249 < 14; v249 += 1) {	// L422
          v245[v246][v247][v248][v249] = (int8_t)0.000000;	// L423
        }
      }
    }
  }
  for (int v250 = 0; v250 < 1; v250 += 1) {	// L428
    for (int v251 = 0; v251 < 14; v251 += 1) {	// L429
      for (int v252 = 0; v252 < 14; v252 += 1) {	// L430
        for (int v253 = 0; v253 < 512; v253 += 1) {	// L431
          for (int v254 = 0; v254 < 3; v254 += 1) {	// L432
            for (int v255 = 0; v255 < 3; v255 += 1) {	// L433
              int8_t v256 = v235[v250][v253][(v251 + v254)][(v252 + v255)];	// L434
              int8_t v257 = v233[v253][v254][v255];	// L435
              int8_t v258 = v245[v250][v253][v251][v252];	// L436
              int8_t v259 = v256 * v257;	// L437
              int8_t v260 = v258 + v259;	// L438
              v245[v250][v253][v251][v252] = v260;	// L439
            }
          }
        }
      }
    }
  }
  for (int v261 = 0; v261 < 1; v261 += 1) {	// L446
    for (int v262 = 0; v262 < 512; v262 += 1) {	// L447
      for (int v263 = 0; v263 < 14; v263 += 1) {	// L448
        for (int v264 = 0; v264 < 14; v264 += 1) {	// L449
          int8_t v265 = v245[0][v262][v263][v264];	// L450
          bool v266 = v265 > (int8_t)0.000000;	// L451
          int8_t v267 = v266 ? v265 : (int8_t)0.000000;	// L452
          v234[v261][v262][v263][v264] = v267;	// L453
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v268[1][512][14][14],
  int8_t v269[512][512][1][1],
  int8_t v270[1][512][14][14]
) {	// L460
  // #pragma HLS dataflow

  int8_t v271[1][512][14][14];	// L462
  // #pragma HLS stream variable=v271 depth=10 type=fifo

  #pragma HLS bind_storage variable=v271 type=ram_t2p impl=bram

  for (int v272 = 0; v272 < 1; v272 += 1) {	// L463
    for (int v273 = 0; v273 < 512; v273 += 1) {	// L464
      for (int v274 = 0; v274 < 14; v274 += 1) {	// L465
        for (int v275 = 0; v275 < 14; v275 += 1) {	// L466
          v271[v272][v273][v274][v275] = (int8_t)0.000000;	// L467
        }
      }
    }
  }
  for (int v276 = 0; v276 < 1; v276 += 1) {	// L472
    for (int v277 = 0; v277 < 512; v277 += 1) {	// L473
      for (int v278 = 0; v278 < 14; v278 += 1) {	// L474
        for (int v279 = 0; v279 < 14; v279 += 1) {	// L475
          for (int v280 = 0; v280 < 512; v280 += 1) {	// L476
            for (int v281 = 0; v281 < 1; v281 += 1) {	// L477
              for (int v282 = 0; v282 < 1; v282 += 1) {	// L478
                int8_t v283 = v268[v276][v280][(v278 + v281)][(v279 + v282)];	// L479
                int8_t v284 = v269[v277][v280][v281][v282];	// L480
                int8_t v285 = v271[v276][v277][v278][v279];	// L481
                int8_t v286 = v283 * v284;	// L482
                int8_t v287 = v285 + v286;	// L483
                v271[v276][v277][v278][v279] = v287;	// L484
              }
            }
          }
        }
      }
    }
  }
  for (int v288 = 0; v288 < 1; v288 += 1) {	// L492
    for (int v289 = 0; v289 < 512; v289 += 1) {	// L493
      for (int v290 = 0; v290 < 14; v290 += 1) {	// L494
        for (int v291 = 0; v291 < 14; v291 += 1) {	// L495
          int8_t v292 = v271[0][v289][v290][v291];	// L496
          bool v293 = v292 > (int8_t)0.000000;	// L497
          int8_t v294 = v293 ? v292 : (int8_t)0.000000;	// L498
          v270[v288][v289][v290][v291] = v294;	// L499
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v295[1][512][14][14],
  int8_t v296[512][3][3],
  int8_t v297[1][512][14][14]
) {	// L506
  // #pragma HLS dataflow

  int8_t v298[1][512][16][16];	// L508
  // #pragma HLS stream variable=v298 depth=10 type=fifo

  #pragma HLS bind_storage variable=v298 type=ram_t2p impl=bram

  for (int v299 = 0; v299 < 1; v299 += 1) {	// L509
    for (int v300 = 0; v300 < 512; v300 += 1) {	// L510
      for (int v301 = 0; v301 < 16; v301 += 1) {	// L511
        for (int v302 = 0; v302 < 16; v302 += 1) {	// L512
          v298[v299][v300][v301][v302] = (int8_t)0.000000;	// L513
        }
      }
    }
  }
  for (int v303 = 0; v303 < 1; v303 += 1) {	// L518
    for (int v304 = 0; v304 < 512; v304 += 1) {	// L519
      for (int v305 = 0; v305 < 14; v305 += 1) {	// L520
        for (int v306 = 0; v306 < 14; v306 += 1) {	// L521
          int8_t v307 = v295[v303][v304][v305][v306];	// L522
          v298[v303][v304][(v305 + 1)][(v306 + 1)] = v307;	// L523
        }
      }
    }
  }
  int8_t v308[1][512][14][14];	// L528
  // #pragma HLS stream variable=v308 depth=10 type=fifo

  #pragma HLS bind_storage variable=v308 type=ram_t2p impl=bram

  for (int v309 = 0; v309 < 1; v309 += 1) {	// L529
    for (int v310 = 0; v310 < 512; v310 += 1) {	// L530
      for (int v311 = 0; v311 < 14; v311 += 1) {	// L531
        for (int v312 = 0; v312 < 14; v312 += 1) {	// L532
          v308[v309][v310][v311][v312] = (int8_t)0.000000;	// L533
        }
      }
    }
  }
  for (int v313 = 0; v313 < 1; v313 += 1) {	// L538
    for (int v314 = 0; v314 < 14; v314 += 1) {	// L539
      for (int v315 = 0; v315 < 14; v315 += 1) {	// L540
        for (int v316 = 0; v316 < 512; v316 += 1) {	// L541
          for (int v317 = 0; v317 < 3; v317 += 1) {	// L542
            for (int v318 = 0; v318 < 3; v318 += 1) {	// L543
              int8_t v319 = v298[v313][v316][(v314 + v317)][(v315 + v318)];	// L544
              int8_t v320 = v296[v316][v317][v318];	// L545
              int8_t v321 = v308[v313][v316][v314][v315];	// L546
              int8_t v322 = v319 * v320;	// L547
              int8_t v323 = v321 + v322;	// L548
              v308[v313][v316][v314][v315] = v323;	// L549
            }
          }
        }
      }
    }
  }
  for (int v324 = 0; v324 < 1; v324 += 1) {	// L556
    for (int v325 = 0; v325 < 512; v325 += 1) {	// L557
      for (int v326 = 0; v326 < 14; v326 += 1) {	// L558
        for (int v327 = 0; v327 < 14; v327 += 1) {	// L559
          int8_t v328 = v308[0][v325][v326][v327];	// L560
          bool v329 = v328 > (int8_t)0.000000;	// L561
          int8_t v330 = v329 ? v328 : (int8_t)0.000000;	// L562
          v297[v324][v325][v326][v327] = v330;	// L563
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v331[512][512][1][1],
  int8_t v332[1][512][14][14],
  int8_t v333[1][512][14][14]
) {	// L570
  // #pragma HLS dataflow

  int8_t v334[1][512][14][14];	// L572
  // #pragma HLS stream variable=v334 depth=10 type=fifo

  #pragma HLS bind_storage variable=v334 type=ram_t2p impl=bram

  for (int v335 = 0; v335 < 1; v335 += 1) {	// L573
    for (int v336 = 0; v336 < 512; v336 += 1) {	// L574
      for (int v337 = 0; v337 < 14; v337 += 1) {	// L575
        for (int v338 = 0; v338 < 14; v338 += 1) {	// L576
          v334[v335][v336][v337][v338] = (int8_t)0.000000;	// L577
        }
      }
    }
  }
  for (int v339 = 0; v339 < 1; v339 += 1) {	// L582
    for (int v340 = 0; v340 < 512; v340 += 1) {	// L583
      for (int v341 = 0; v341 < 14; v341 += 1) {	// L584
        for (int v342 = 0; v342 < 14; v342 += 1) {	// L585
          for (int v343 = 0; v343 < 512; v343 += 1) {	// L586
            for (int v344 = 0; v344 < 1; v344 += 1) {	// L587
              for (int v345 = 0; v345 < 1; v345 += 1) {	// L588
                int8_t v346 = v332[v339][v343][(v341 + v344)][(v342 + v345)];	// L589
                int8_t v347 = v331[v340][v343][v344][v345];	// L590
                int8_t v348 = v334[v339][v340][v341][v342];	// L591
                int8_t v349 = v346 * v347;	// L592
                int8_t v350 = v348 + v349;	// L593
                v334[v339][v340][v341][v342] = v350;	// L594
              }
            }
          }
        }
      }
    }
  }
  for (int v351 = 0; v351 < 1; v351 += 1) {	// L602
    for (int v352 = 0; v352 < 512; v352 += 1) {	// L603
      for (int v353 = 0; v353 < 14; v353 += 1) {	// L604
        for (int v354 = 0; v354 < 14; v354 += 1) {	// L605
          int8_t v355 = v334[0][v352][v353][v354];	// L606
          bool v356 = v355 > (int8_t)0.000000;	// L607
          int8_t v357 = v356 ? v355 : (int8_t)0.000000;	// L608
          v333[v351][v352][v353][v354] = v357;	// L609
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v358[512][3][3],
  int8_t v359[1][512][14][14],
  int8_t v360[1][512][14][14]
) {	// L616
  // #pragma HLS dataflow

  int8_t v361[1][512][16][16];	// L618
  // #pragma HLS stream variable=v361 depth=10 type=fifo

  #pragma HLS bind_storage variable=v361 type=ram_t2p impl=bram

  for (int v362 = 0; v362 < 1; v362 += 1) {	// L619
    for (int v363 = 0; v363 < 512; v363 += 1) {	// L620
      for (int v364 = 0; v364 < 16; v364 += 1) {	// L621
        for (int v365 = 0; v365 < 16; v365 += 1) {	// L622
          v361[v362][v363][v364][v365] = (int8_t)0.000000;	// L623
        }
      }
    }
  }
  for (int v366 = 0; v366 < 1; v366 += 1) {	// L628
    for (int v367 = 0; v367 < 512; v367 += 1) {	// L629
      for (int v368 = 0; v368 < 14; v368 += 1) {	// L630
        for (int v369 = 0; v369 < 14; v369 += 1) {	// L631
          int8_t v370 = v359[v366][v367][v368][v369];	// L632
          v361[v366][v367][(v368 + 1)][(v369 + 1)] = v370;	// L633
        }
      }
    }
  }
  int8_t v371[1][512][14][14];	// L638
  // #pragma HLS stream variable=v371 depth=10 type=fifo

  #pragma HLS bind_storage variable=v371 type=ram_t2p impl=bram

  for (int v372 = 0; v372 < 1; v372 += 1) {	// L639
    for (int v373 = 0; v373 < 512; v373 += 1) {	// L640
      for (int v374 = 0; v374 < 14; v374 += 1) {	// L641
        for (int v375 = 0; v375 < 14; v375 += 1) {	// L642
          v371[v372][v373][v374][v375] = (int8_t)0.000000;	// L643
        }
      }
    }
  }
  for (int v376 = 0; v376 < 1; v376 += 1) {	// L648
    for (int v377 = 0; v377 < 14; v377 += 1) {	// L649
      for (int v378 = 0; v378 < 14; v378 += 1) {	// L650
        for (int v379 = 0; v379 < 512; v379 += 1) {	// L651
          for (int v380 = 0; v380 < 3; v380 += 1) {	// L652
            for (int v381 = 0; v381 < 3; v381 += 1) {	// L653
              int8_t v382 = v361[v376][v379][(v377 + v380)][(v378 + v381)];	// L654
              int8_t v383 = v358[v379][v380][v381];	// L655
              int8_t v384 = v371[v376][v379][v377][v378];	// L656
              int8_t v385 = v382 * v383;	// L657
              int8_t v386 = v384 + v385;	// L658
              v371[v376][v379][v377][v378] = v386;	// L659
            }
          }
        }
      }
    }
  }
  for (int v387 = 0; v387 < 1; v387 += 1) {	// L666
    for (int v388 = 0; v388 < 512; v388 += 1) {	// L667
      for (int v389 = 0; v389 < 14; v389 += 1) {	// L668
        for (int v390 = 0; v390 < 14; v390 += 1) {	// L669
          int8_t v391 = v371[0][v388][v389][v390];	// L670
          bool v392 = v391 > (int8_t)0.000000;	// L671
          int8_t v393 = v392 ? v391 : (int8_t)0.000000;	// L672
          v360[v387][v388][v389][v390] = v393;	// L673
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v394[512][512][1][1],
  int8_t v395[1][512][14][14],
  int8_t v396[1][512][14][14]
) {	// L680
  // #pragma HLS dataflow

  int8_t v397[1][512][14][14];	// L682
  // #pragma HLS stream variable=v397 depth=10 type=fifo

  #pragma HLS bind_storage variable=v397 type=ram_t2p impl=bram

  for (int v398 = 0; v398 < 1; v398 += 1) {	// L683
    for (int v399 = 0; v399 < 512; v399 += 1) {	// L684
      for (int v400 = 0; v400 < 14; v400 += 1) {	// L685
        for (int v401 = 0; v401 < 14; v401 += 1) {	// L686
          v397[v398][v399][v400][v401] = (int8_t)0.000000;	// L687
        }
      }
    }
  }
  for (int v402 = 0; v402 < 1; v402 += 1) {	// L692
    for (int v403 = 0; v403 < 512; v403 += 1) {	// L693
      for (int v404 = 0; v404 < 14; v404 += 1) {	// L694
        for (int v405 = 0; v405 < 14; v405 += 1) {	// L695
          for (int v406 = 0; v406 < 512; v406 += 1) {	// L696
            for (int v407 = 0; v407 < 1; v407 += 1) {	// L697
              for (int v408 = 0; v408 < 1; v408 += 1) {	// L698
                int8_t v409 = v395[v402][v406][(v404 + v407)][(v405 + v408)];	// L699
                int8_t v410 = v394[v403][v406][v407][v408];	// L700
                int8_t v411 = v397[v402][v403][v404][v405];	// L701
                int8_t v412 = v409 * v410;	// L702
                int8_t v413 = v411 + v412;	// L703
                v397[v402][v403][v404][v405] = v413;	// L704
              }
            }
          }
        }
      }
    }
  }
  for (int v414 = 0; v414 < 1; v414 += 1) {	// L712
    for (int v415 = 0; v415 < 512; v415 += 1) {	// L713
      for (int v416 = 0; v416 < 14; v416 += 1) {	// L714
        for (int v417 = 0; v417 < 14; v417 += 1) {	// L715
          int8_t v418 = v397[0][v415][v416][v417];	// L716
          bool v419 = v418 > (int8_t)0.000000;	// L717
          int8_t v420 = v419 ? v418 : (int8_t)0.000000;	// L718
          v396[v414][v415][v416][v417] = v420;	// L719
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v421[512][3][3],
  int8_t v422[1][512][14][14],
  int8_t v423[1][512][14][14]
) {	// L726
  // #pragma HLS dataflow

  int8_t v424[1][512][16][16];	// L728
  // #pragma HLS stream variable=v424 depth=10 type=fifo

  #pragma HLS bind_storage variable=v424 type=ram_t2p impl=bram

  for (int v425 = 0; v425 < 1; v425 += 1) {	// L729
    for (int v426 = 0; v426 < 512; v426 += 1) {	// L730
      for (int v427 = 0; v427 < 16; v427 += 1) {	// L731
        for (int v428 = 0; v428 < 16; v428 += 1) {	// L732
          v424[v425][v426][v427][v428] = (int8_t)0.000000;	// L733
        }
      }
    }
  }
  for (int v429 = 0; v429 < 1; v429 += 1) {	// L738
    for (int v430 = 0; v430 < 512; v430 += 1) {	// L739
      for (int v431 = 0; v431 < 14; v431 += 1) {	// L740
        for (int v432 = 0; v432 < 14; v432 += 1) {	// L741
          int8_t v433 = v422[v429][v430][v431][v432];	// L742
          v424[v429][v430][(v431 + 1)][(v432 + 1)] = v433;	// L743
        }
      }
    }
  }
  int8_t v434[1][512][14][14];	// L748
  // #pragma HLS stream variable=v434 depth=10 type=fifo

  #pragma HLS bind_storage variable=v434 type=ram_t2p impl=bram

  for (int v435 = 0; v435 < 1; v435 += 1) {	// L749
    for (int v436 = 0; v436 < 512; v436 += 1) {	// L750
      for (int v437 = 0; v437 < 14; v437 += 1) {	// L751
        for (int v438 = 0; v438 < 14; v438 += 1) {	// L752
          v434[v435][v436][v437][v438] = (int8_t)0.000000;	// L753
        }
      }
    }
  }
  for (int v439 = 0; v439 < 1; v439 += 1) {	// L758
    for (int v440 = 0; v440 < 14; v440 += 1) {	// L759
      for (int v441 = 0; v441 < 14; v441 += 1) {	// L760
        for (int v442 = 0; v442 < 512; v442 += 1) {	// L761
          for (int v443 = 0; v443 < 3; v443 += 1) {	// L762
            for (int v444 = 0; v444 < 3; v444 += 1) {	// L763
              int8_t v445 = v424[v439][v442][(v440 + v443)][(v441 + v444)];	// L764
              int8_t v446 = v421[v442][v443][v444];	// L765
              int8_t v447 = v434[v439][v442][v440][v441];	// L766
              int8_t v448 = v445 * v446;	// L767
              int8_t v449 = v447 + v448;	// L768
              v434[v439][v442][v440][v441] = v449;	// L769
            }
          }
        }
      }
    }
  }
  for (int v450 = 0; v450 < 1; v450 += 1) {	// L776
    for (int v451 = 0; v451 < 512; v451 += 1) {	// L777
      for (int v452 = 0; v452 < 14; v452 += 1) {	// L778
        for (int v453 = 0; v453 < 14; v453 += 1) {	// L779
          int8_t v454 = v434[0][v451][v452][v453];	// L780
          bool v455 = v454 > (int8_t)0.000000;	// L781
          int8_t v456 = v455 ? v454 : (int8_t)0.000000;	// L782
          v423[v450][v451][v452][v453] = v456;	// L783
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v457[1][512][14][14],
  int8_t v458[512][512][1][1],
  int8_t v459[1][512][14][14]
) {	// L790
  // #pragma HLS dataflow

  int8_t v460[1][512][14][14];	// L792
  // #pragma HLS stream variable=v460 depth=10 type=fifo

  #pragma HLS bind_storage variable=v460 type=ram_t2p impl=bram

  for (int v461 = 0; v461 < 1; v461 += 1) {	// L793
    for (int v462 = 0; v462 < 512; v462 += 1) {	// L794
      for (int v463 = 0; v463 < 14; v463 += 1) {	// L795
        for (int v464 = 0; v464 < 14; v464 += 1) {	// L796
          v460[v461][v462][v463][v464] = (int8_t)0.000000;	// L797
        }
      }
    }
  }
  for (int v465 = 0; v465 < 1; v465 += 1) {	// L802
    for (int v466 = 0; v466 < 512; v466 += 1) {	// L803
      for (int v467 = 0; v467 < 14; v467 += 1) {	// L804
        for (int v468 = 0; v468 < 14; v468 += 1) {	// L805
          for (int v469 = 0; v469 < 512; v469 += 1) {	// L806
            for (int v470 = 0; v470 < 1; v470 += 1) {	// L807
              for (int v471 = 0; v471 < 1; v471 += 1) {	// L808
                int8_t v472 = v457[v465][v469][(v467 + v470)][(v468 + v471)];	// L809
                int8_t v473 = v458[v466][v469][v470][v471];	// L810
                int8_t v474 = v460[v465][v466][v467][v468];	// L811
                int8_t v475 = v472 * v473;	// L812
                int8_t v476 = v474 + v475;	// L813
                v460[v465][v466][v467][v468] = v476;	// L814
              }
            }
          }
        }
      }
    }
  }
  for (int v477 = 0; v477 < 1; v477 += 1) {	// L822
    for (int v478 = 0; v478 < 512; v478 += 1) {	// L823
      for (int v479 = 0; v479 < 14; v479 += 1) {	// L824
        for (int v480 = 0; v480 < 14; v480 += 1) {	// L825
          int8_t v481 = v460[0][v478][v479][v480];	// L826
          bool v482 = v481 > (int8_t)0.000000;	// L827
          int8_t v483 = v482 ? v481 : (int8_t)0.000000;	// L828
          v459[v477][v478][v479][v480] = v483;	// L829
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v484[1][512][14][14],
  int8_t v485[512][3][3],
  int8_t v486[1][512][14][14]
) {	// L836
  // #pragma HLS dataflow

  int8_t v487[1][512][16][16];	// L838
  // #pragma HLS stream variable=v487 depth=10 type=fifo

  #pragma HLS bind_storage variable=v487 type=ram_t2p impl=bram

  for (int v488 = 0; v488 < 1; v488 += 1) {	// L839
    for (int v489 = 0; v489 < 512; v489 += 1) {	// L840
      for (int v490 = 0; v490 < 16; v490 += 1) {	// L841
        for (int v491 = 0; v491 < 16; v491 += 1) {	// L842
          v487[v488][v489][v490][v491] = (int8_t)0.000000;	// L843
        }
      }
    }
  }
  for (int v492 = 0; v492 < 1; v492 += 1) {	// L848
    for (int v493 = 0; v493 < 512; v493 += 1) {	// L849
      for (int v494 = 0; v494 < 14; v494 += 1) {	// L850
        for (int v495 = 0; v495 < 14; v495 += 1) {	// L851
          int8_t v496 = v484[v492][v493][v494][v495];	// L852
          v487[v492][v493][(v494 + 1)][(v495 + 1)] = v496;	// L853
        }
      }
    }
  }
  int8_t v497[1][512][14][14];	// L858
  // #pragma HLS stream variable=v497 depth=10 type=fifo

  #pragma HLS bind_storage variable=v497 type=ram_t2p impl=bram

  for (int v498 = 0; v498 < 1; v498 += 1) {	// L859
    for (int v499 = 0; v499 < 512; v499 += 1) {	// L860
      for (int v500 = 0; v500 < 14; v500 += 1) {	// L861
        for (int v501 = 0; v501 < 14; v501 += 1) {	// L862
          v497[v498][v499][v500][v501] = (int8_t)0.000000;	// L863
        }
      }
    }
  }
  for (int v502 = 0; v502 < 1; v502 += 1) {	// L868
    for (int v503 = 0; v503 < 14; v503 += 1) {	// L869
      for (int v504 = 0; v504 < 14; v504 += 1) {	// L870
        for (int v505 = 0; v505 < 512; v505 += 1) {	// L871
          for (int v506 = 0; v506 < 3; v506 += 1) {	// L872
            for (int v507 = 0; v507 < 3; v507 += 1) {	// L873
              int8_t v508 = v487[v502][v505][(v503 + v506)][(v504 + v507)];	// L874
              int8_t v509 = v485[v505][v506][v507];	// L875
              int8_t v510 = v497[v502][v505][v503][v504];	// L876
              int8_t v511 = v508 * v509;	// L877
              int8_t v512 = v510 + v511;	// L878
              v497[v502][v505][v503][v504] = v512;	// L879
            }
          }
        }
      }
    }
  }
  for (int v513 = 0; v513 < 1; v513 += 1) {	// L886
    for (int v514 = 0; v514 < 512; v514 += 1) {	// L887
      for (int v515 = 0; v515 < 14; v515 += 1) {	// L888
        for (int v516 = 0; v516 < 14; v516 += 1) {	// L889
          int8_t v517 = v497[0][v514][v515][v516];	// L890
          bool v518 = v517 > (int8_t)0.000000;	// L891
          int8_t v519 = v518 ? v517 : (int8_t)0.000000;	// L892
          v486[v513][v514][v515][v516] = v519;	// L893
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v520[1][256][14][14],
  int8_t v521[512][256][1][1],
  int8_t v522[1][512][14][14]
) {	// L900
  // #pragma HLS dataflow

  int8_t v523[1][512][14][14];	// L902
  // #pragma HLS stream variable=v523 depth=10 type=fifo

  #pragma HLS bind_storage variable=v523 type=ram_t2p impl=bram

  for (int v524 = 0; v524 < 1; v524 += 1) {	// L903
    for (int v525 = 0; v525 < 512; v525 += 1) {	// L904
      for (int v526 = 0; v526 < 14; v526 += 1) {	// L905
        for (int v527 = 0; v527 < 14; v527 += 1) {	// L906
          v523[v524][v525][v526][v527] = (int8_t)0.000000;	// L907
        }
      }
    }
  }
  for (int v528 = 0; v528 < 1; v528 += 1) {	// L912
    for (int v529 = 0; v529 < 512; v529 += 1) {	// L913
      for (int v530 = 0; v530 < 14; v530 += 1) {	// L914
        for (int v531 = 0; v531 < 14; v531 += 1) {	// L915
          for (int v532 = 0; v532 < 256; v532 += 1) {	// L916
            for (int v533 = 0; v533 < 1; v533 += 1) {	// L917
              for (int v534 = 0; v534 < 1; v534 += 1) {	// L918
                int8_t v535 = v520[v528][v532][(v530 + v533)][(v531 + v534)];	// L919
                int8_t v536 = v521[v529][v532][v533][v534];	// L920
                int8_t v537 = v523[v528][v529][v530][v531];	// L921
                int8_t v538 = v535 * v536;	// L922
                int8_t v539 = v537 + v538;	// L923
                v523[v528][v529][v530][v531] = v539;	// L924
              }
            }
          }
        }
      }
    }
  }
  for (int v540 = 0; v540 < 1; v540 += 1) {	// L932
    for (int v541 = 0; v541 < 512; v541 += 1) {	// L933
      for (int v542 = 0; v542 < 14; v542 += 1) {	// L934
        for (int v543 = 0; v543 < 14; v543 += 1) {	// L935
          int8_t v544 = v523[0][v541][v542][v543];	// L936
          bool v545 = v544 > (int8_t)0.000000;	// L937
          int8_t v546 = v545 ? v544 : (int8_t)0.000000;	// L938
          v522[v540][v541][v542][v543] = v546;	// L939
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v547[1][256][28][28],
  int8_t v548[256][3][3],
  int8_t v549[1][256][14][14]
) {	// L946
  // #pragma HLS dataflow

  int8_t v550[1][256][30][30];	// L948
  // #pragma HLS stream variable=v550 depth=10 type=fifo

  #pragma HLS bind_storage variable=v550 type=ram_t2p impl=bram

  for (int v551 = 0; v551 < 1; v551 += 1) {	// L949
    for (int v552 = 0; v552 < 256; v552 += 1) {	// L950
      for (int v553 = 0; v553 < 30; v553 += 1) {	// L951
        for (int v554 = 0; v554 < 30; v554 += 1) {	// L952
          v550[v551][v552][v553][v554] = (int8_t)0.000000;	// L953
        }
      }
    }
  }
  for (int v555 = 0; v555 < 1; v555 += 1) {	// L958
    for (int v556 = 0; v556 < 256; v556 += 1) {	// L959
      for (int v557 = 0; v557 < 28; v557 += 1) {	// L960
        for (int v558 = 0; v558 < 28; v558 += 1) {	// L961
          int8_t v559 = v547[v555][v556][v557][v558];	// L962
          v550[v555][v556][(v557 + 1)][(v558 + 1)] = v559;	// L963
        }
      }
    }
  }
  int8_t v560[1][256][14][14];	// L968
  // #pragma HLS stream variable=v560 depth=10 type=fifo

  #pragma HLS bind_storage variable=v560 type=ram_t2p impl=bram

  for (int v561 = 0; v561 < 1; v561 += 1) {	// L969
    for (int v562 = 0; v562 < 256; v562 += 1) {	// L970
      for (int v563 = 0; v563 < 14; v563 += 1) {	// L971
        for (int v564 = 0; v564 < 14; v564 += 1) {	// L972
          v560[v561][v562][v563][v564] = (int8_t)0.000000;	// L973
        }
      }
    }
  }
  for (int v565 = 0; v565 < 1; v565 += 1) {	// L978
    for (int v566 = 0; v566 < 14; v566 += 1) {	// L979
      for (int v567 = 0; v567 < 14; v567 += 1) {	// L980
        for (int v568 = 0; v568 < 256; v568 += 1) {	// L981
          for (int v569 = 0; v569 < 3; v569 += 1) {	// L982
            for (int v570 = 0; v570 < 3; v570 += 1) {	// L983
              int8_t v571 = v550[v565][v568][((v566 * 2) + v569)][((v567 * 2) + v570)];	// L984
              int8_t v572 = v548[v568][v569][v570];	// L985
              int8_t v573 = v560[v565][v568][v566][v567];	// L986
              int8_t v574 = v571 * v572;	// L987
              int8_t v575 = v573 + v574;	// L988
              v560[v565][v568][v566][v567] = v575;	// L989
            }
          }
        }
      }
    }
  }
  for (int v576 = 0; v576 < 1; v576 += 1) {	// L996
    for (int v577 = 0; v577 < 256; v577 += 1) {	// L997
      for (int v578 = 0; v578 < 14; v578 += 1) {	// L998
        for (int v579 = 0; v579 < 14; v579 += 1) {	// L999
          int8_t v580 = v560[0][v577][v578][v579];	// L1000
          bool v581 = v580 > (int8_t)0.000000;	// L1001
          int8_t v582 = v581 ? v580 : (int8_t)0.000000;	// L1002
          v549[v576][v577][v578][v579] = v582;	// L1003
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v583[1][256][28][28],
  int8_t v584[256][256][1][1],
  int8_t v585[1][256][28][28]
) {	// L1010
  // #pragma HLS dataflow

  int8_t v586[1][256][28][28];	// L1012
  // #pragma HLS stream variable=v586 depth=10 type=fifo

  #pragma HLS bind_storage variable=v586 type=ram_t2p impl=bram

  for (int v587 = 0; v587 < 1; v587 += 1) {	// L1013
    for (int v588 = 0; v588 < 256; v588 += 1) {	// L1014
      for (int v589 = 0; v589 < 28; v589 += 1) {	// L1015
        for (int v590 = 0; v590 < 28; v590 += 1) {	// L1016
          v586[v587][v588][v589][v590] = (int8_t)0.000000;	// L1017
        }
      }
    }
  }
  for (int v591 = 0; v591 < 1; v591 += 1) {	// L1022
    for (int v592 = 0; v592 < 256; v592 += 1) {	// L1023
      for (int v593 = 0; v593 < 28; v593 += 1) {	// L1024
        for (int v594 = 0; v594 < 28; v594 += 1) {	// L1025
          for (int v595 = 0; v595 < 256; v595 += 1) {	// L1026
            for (int v596 = 0; v596 < 1; v596 += 1) {	// L1027
              for (int v597 = 0; v597 < 1; v597 += 1) {	// L1028
                int8_t v598 = v583[v591][v595][(v593 + v596)][(v594 + v597)];	// L1029
                int8_t v599 = v584[v592][v595][v596][v597];	// L1030
                int8_t v600 = v586[v591][v592][v593][v594];	// L1031
                int8_t v601 = v598 * v599;	// L1032
                int8_t v602 = v600 + v601;	// L1033
                v586[v591][v592][v593][v594] = v602;	// L1034
              }
            }
          }
        }
      }
    }
  }
  for (int v603 = 0; v603 < 1; v603 += 1) {	// L1042
    for (int v604 = 0; v604 < 256; v604 += 1) {	// L1043
      for (int v605 = 0; v605 < 28; v605 += 1) {	// L1044
        for (int v606 = 0; v606 < 28; v606 += 1) {	// L1045
          int8_t v607 = v586[0][v604][v605][v606];	// L1046
          bool v608 = v607 > (int8_t)0.000000;	// L1047
          int8_t v609 = v608 ? v607 : (int8_t)0.000000;	// L1048
          v585[v603][v604][v605][v606] = v609;	// L1049
        }
      }
    }
  }
}

void main_graph_node21(
  int8_t v610[256][3][3],
  int8_t v611[1][256][28][28],
  int8_t v612[1][256][28][28]
) {	// L1056
  // #pragma HLS dataflow

  int8_t v613[1][256][30][30];	// L1058
  // #pragma HLS stream variable=v613 depth=10 type=fifo

  #pragma HLS bind_storage variable=v613 type=ram_t2p impl=bram

  for (int v614 = 0; v614 < 1; v614 += 1) {	// L1059
    for (int v615 = 0; v615 < 256; v615 += 1) {	// L1060
      for (int v616 = 0; v616 < 30; v616 += 1) {	// L1061
        for (int v617 = 0; v617 < 30; v617 += 1) {	// L1062
          v613[v614][v615][v616][v617] = (int8_t)0.000000;	// L1063
        }
      }
    }
  }
  for (int v618 = 0; v618 < 1; v618 += 1) {	// L1068
    for (int v619 = 0; v619 < 256; v619 += 1) {	// L1069
      for (int v620 = 0; v620 < 28; v620 += 1) {	// L1070
        for (int v621 = 0; v621 < 28; v621 += 1) {	// L1071
          int8_t v622 = v611[v618][v619][v620][v621];	// L1072
          v613[v618][v619][(v620 + 1)][(v621 + 1)] = v622;	// L1073
        }
      }
    }
  }
  int8_t v623[1][256][28][28];	// L1078
  // #pragma HLS stream variable=v623 depth=10 type=fifo

  #pragma HLS bind_storage variable=v623 type=ram_t2p impl=bram

  for (int v624 = 0; v624 < 1; v624 += 1) {	// L1079
    for (int v625 = 0; v625 < 256; v625 += 1) {	// L1080
      for (int v626 = 0; v626 < 28; v626 += 1) {	// L1081
        for (int v627 = 0; v627 < 28; v627 += 1) {	// L1082
          v623[v624][v625][v626][v627] = (int8_t)0.000000;	// L1083
        }
      }
    }
  }
  for (int v628 = 0; v628 < 1; v628 += 1) {	// L1088
    for (int v629 = 0; v629 < 28; v629 += 1) {	// L1089
      for (int v630 = 0; v630 < 28; v630 += 1) {	// L1090
        for (int v631 = 0; v631 < 256; v631 += 1) {	// L1091
          for (int v632 = 0; v632 < 3; v632 += 1) {	// L1092
            for (int v633 = 0; v633 < 3; v633 += 1) {	// L1093
              int8_t v634 = v613[v628][v631][(v629 + v632)][(v630 + v633)];	// L1094
              int8_t v635 = v610[v631][v632][v633];	// L1095
              int8_t v636 = v623[v628][v631][v629][v630];	// L1096
              int8_t v637 = v634 * v635;	// L1097
              int8_t v638 = v636 + v637;	// L1098
              v623[v628][v631][v629][v630] = v638;	// L1099
            }
          }
        }
      }
    }
  }
  for (int v639 = 0; v639 < 1; v639 += 1) {	// L1106
    for (int v640 = 0; v640 < 256; v640 += 1) {	// L1107
      for (int v641 = 0; v641 < 28; v641 += 1) {	// L1108
        for (int v642 = 0; v642 < 28; v642 += 1) {	// L1109
          int8_t v643 = v623[0][v640][v641][v642];	// L1110
          bool v644 = v643 > (int8_t)0.000000;	// L1111
          int8_t v645 = v644 ? v643 : (int8_t)0.000000;	// L1112
          v612[v639][v640][v641][v642] = v645;	// L1113
        }
      }
    }
  }
}

void main_graph_node22(
  int8_t v646[256][128][1][1],
  int8_t v647[1][128][28][28],
  int8_t v648[1][256][28][28]
) {	// L1120
  // #pragma HLS dataflow

  int8_t v649[1][256][28][28];	// L1122
  // #pragma HLS stream variable=v649 depth=10 type=fifo

  #pragma HLS bind_storage variable=v649 type=ram_t2p impl=bram

  for (int v650 = 0; v650 < 1; v650 += 1) {	// L1123
    for (int v651 = 0; v651 < 256; v651 += 1) {	// L1124
      for (int v652 = 0; v652 < 28; v652 += 1) {	// L1125
        for (int v653 = 0; v653 < 28; v653 += 1) {	// L1126
          v649[v650][v651][v652][v653] = (int8_t)0.000000;	// L1127
        }
      }
    }
  }
  for (int v654 = 0; v654 < 1; v654 += 1) {	// L1132
    for (int v655 = 0; v655 < 256; v655 += 1) {	// L1133
      for (int v656 = 0; v656 < 28; v656 += 1) {	// L1134
        for (int v657 = 0; v657 < 28; v657 += 1) {	// L1135
          for (int v658 = 0; v658 < 128; v658 += 1) {	// L1136
            for (int v659 = 0; v659 < 1; v659 += 1) {	// L1137
              for (int v660 = 0; v660 < 1; v660 += 1) {	// L1138
                int8_t v661 = v647[v654][v658][(v656 + v659)][(v657 + v660)];	// L1139
                int8_t v662 = v646[v655][v658][v659][v660];	// L1140
                int8_t v663 = v649[v654][v655][v656][v657];	// L1141
                int8_t v664 = v661 * v662;	// L1142
                int8_t v665 = v663 + v664;	// L1143
                v649[v654][v655][v656][v657] = v665;	// L1144
              }
            }
          }
        }
      }
    }
  }
  for (int v666 = 0; v666 < 1; v666 += 1) {	// L1152
    for (int v667 = 0; v667 < 256; v667 += 1) {	// L1153
      for (int v668 = 0; v668 < 28; v668 += 1) {	// L1154
        for (int v669 = 0; v669 < 28; v669 += 1) {	// L1155
          int8_t v670 = v649[0][v667][v668][v669];	// L1156
          bool v671 = v670 > (int8_t)0.000000;	// L1157
          int8_t v672 = v671 ? v670 : (int8_t)0.000000;	// L1158
          v648[v666][v667][v668][v669] = v672;	// L1159
        }
      }
    }
  }
}

void main_graph_node23(
  int8_t v673[1][128][56][56],
  int8_t v674[128][3][3],
  int8_t v675[1][128][28][28]
) {	// L1166
  // #pragma HLS dataflow

  int8_t v676[1][128][58][58];	// L1168
  // #pragma HLS stream variable=v676 depth=10 type=fifo

  #pragma HLS bind_storage variable=v676 type=ram_t2p impl=bram

  for (int v677 = 0; v677 < 1; v677 += 1) {	// L1169
    for (int v678 = 0; v678 < 128; v678 += 1) {	// L1170
      for (int v679 = 0; v679 < 58; v679 += 1) {	// L1171
        for (int v680 = 0; v680 < 58; v680 += 1) {	// L1172
          v676[v677][v678][v679][v680] = (int8_t)0.000000;	// L1173
        }
      }
    }
  }
  for (int v681 = 0; v681 < 1; v681 += 1) {	// L1178
    for (int v682 = 0; v682 < 128; v682 += 1) {	// L1179
      for (int v683 = 0; v683 < 56; v683 += 1) {	// L1180
        for (int v684 = 0; v684 < 56; v684 += 1) {	// L1181
          int8_t v685 = v673[v681][v682][v683][v684];	// L1182
          v676[v681][v682][(v683 + 1)][(v684 + 1)] = v685;	// L1183
        }
      }
    }
  }
  int8_t v686[1][128][28][28];	// L1188
  // #pragma HLS stream variable=v686 depth=10 type=fifo

  #pragma HLS bind_storage variable=v686 type=ram_t2p impl=bram

  for (int v687 = 0; v687 < 1; v687 += 1) {	// L1189
    for (int v688 = 0; v688 < 128; v688 += 1) {	// L1190
      for (int v689 = 0; v689 < 28; v689 += 1) {	// L1191
        for (int v690 = 0; v690 < 28; v690 += 1) {	// L1192
          v686[v687][v688][v689][v690] = (int8_t)0.000000;	// L1193
        }
      }
    }
  }
  for (int v691 = 0; v691 < 1; v691 += 1) {	// L1198
    for (int v692 = 0; v692 < 28; v692 += 1) {	// L1199
      for (int v693 = 0; v693 < 28; v693 += 1) {	// L1200
        for (int v694 = 0; v694 < 128; v694 += 1) {	// L1201
          for (int v695 = 0; v695 < 3; v695 += 1) {	// L1202
            for (int v696 = 0; v696 < 3; v696 += 1) {	// L1203
              int8_t v697 = v676[v691][v694][((v692 * 2) + v695)][((v693 * 2) + v696)];	// L1204
              int8_t v698 = v674[v694][v695][v696];	// L1205
              int8_t v699 = v686[v691][v694][v692][v693];	// L1206
              int8_t v700 = v697 * v698;	// L1207
              int8_t v701 = v699 + v700;	// L1208
              v686[v691][v694][v692][v693] = v701;	// L1209
            }
          }
        }
      }
    }
  }
  for (int v702 = 0; v702 < 1; v702 += 1) {	// L1216
    for (int v703 = 0; v703 < 128; v703 += 1) {	// L1217
      for (int v704 = 0; v704 < 28; v704 += 1) {	// L1218
        for (int v705 = 0; v705 < 28; v705 += 1) {	// L1219
          int8_t v706 = v686[0][v703][v704][v705];	// L1220
          bool v707 = v706 > (int8_t)0.000000;	// L1221
          int8_t v708 = v707 ? v706 : (int8_t)0.000000;	// L1222
          v675[v702][v703][v704][v705] = v708;	// L1223
        }
      }
    }
  }
}

void main_graph_node24(
  int8_t v709[128][128][1][1],
  int8_t v710[1][128][56][56],
  int8_t v711[1][128][56][56]
) {	// L1230
  // #pragma HLS dataflow

  int8_t v712[1][128][56][56];	// L1232
  // #pragma HLS stream variable=v712 depth=10 type=fifo

  #pragma HLS bind_storage variable=v712 type=ram_t2p impl=bram

  for (int v713 = 0; v713 < 1; v713 += 1) {	// L1233
    for (int v714 = 0; v714 < 128; v714 += 1) {	// L1234
      for (int v715 = 0; v715 < 56; v715 += 1) {	// L1235
        for (int v716 = 0; v716 < 56; v716 += 1) {	// L1236
          v712[v713][v714][v715][v716] = (int8_t)0.000000;	// L1237
        }
      }
    }
  }
  for (int v717 = 0; v717 < 1; v717 += 1) {	// L1242
    for (int v718 = 0; v718 < 128; v718 += 1) {	// L1243
      for (int v719 = 0; v719 < 56; v719 += 1) {	// L1244
        for (int v720 = 0; v720 < 56; v720 += 1) {	// L1245
          for (int v721 = 0; v721 < 128; v721 += 1) {	// L1246
            for (int v722 = 0; v722 < 1; v722 += 1) {	// L1247
              for (int v723 = 0; v723 < 1; v723 += 1) {	// L1248
                int8_t v724 = v710[v717][v721][(v719 + v722)][(v720 + v723)];	// L1249
                int8_t v725 = v709[v718][v721][v722][v723];	// L1250
                int8_t v726 = v712[v717][v718][v719][v720];	// L1251
                int8_t v727 = v724 * v725;	// L1252
                int8_t v728 = v726 + v727;	// L1253
                v712[v717][v718][v719][v720] = v728;	// L1254
              }
            }
          }
        }
      }
    }
  }
  for (int v729 = 0; v729 < 1; v729 += 1) {	// L1262
    for (int v730 = 0; v730 < 128; v730 += 1) {	// L1263
      for (int v731 = 0; v731 < 56; v731 += 1) {	// L1264
        for (int v732 = 0; v732 < 56; v732 += 1) {	// L1265
          int8_t v733 = v712[0][v730][v731][v732];	// L1266
          bool v734 = v733 > (int8_t)0.000000;	// L1267
          int8_t v735 = v734 ? v733 : (int8_t)0.000000;	// L1268
          v711[v729][v730][v731][v732] = v735;	// L1269
        }
      }
    }
  }
}

void main_graph_node25(
  int8_t v736[1][128][56][56],
  int8_t v737[128][3][3],
  int8_t v738[1][128][56][56]
) {	// L1276
  // #pragma HLS dataflow

  int8_t v739[1][128][58][58];	// L1278
  // #pragma HLS stream variable=v739 depth=10 type=fifo

  #pragma HLS bind_storage variable=v739 type=ram_t2p impl=bram

  for (int v740 = 0; v740 < 1; v740 += 1) {	// L1279
    for (int v741 = 0; v741 < 128; v741 += 1) {	// L1280
      for (int v742 = 0; v742 < 58; v742 += 1) {	// L1281
        for (int v743 = 0; v743 < 58; v743 += 1) {	// L1282
          v739[v740][v741][v742][v743] = (int8_t)0.000000;	// L1283
        }
      }
    }
  }
  for (int v744 = 0; v744 < 1; v744 += 1) {	// L1288
    for (int v745 = 0; v745 < 128; v745 += 1) {	// L1289
      for (int v746 = 0; v746 < 56; v746 += 1) {	// L1290
        for (int v747 = 0; v747 < 56; v747 += 1) {	// L1291
          int8_t v748 = v736[v744][v745][v746][v747];	// L1292
          v739[v744][v745][(v746 + 1)][(v747 + 1)] = v748;	// L1293
        }
      }
    }
  }
  int8_t v749[1][128][56][56];	// L1298
  // #pragma HLS stream variable=v749 depth=10 type=fifo

  #pragma HLS bind_storage variable=v749 type=ram_t2p impl=bram

  for (int v750 = 0; v750 < 1; v750 += 1) {	// L1299
    for (int v751 = 0; v751 < 128; v751 += 1) {	// L1300
      for (int v752 = 0; v752 < 56; v752 += 1) {	// L1301
        for (int v753 = 0; v753 < 56; v753 += 1) {	// L1302
          v749[v750][v751][v752][v753] = (int8_t)0.000000;	// L1303
        }
      }
    }
  }
  for (int v754 = 0; v754 < 1; v754 += 1) {	// L1308
    for (int v755 = 0; v755 < 56; v755 += 1) {	// L1309
      for (int v756 = 0; v756 < 56; v756 += 1) {	// L1310
        for (int v757 = 0; v757 < 128; v757 += 1) {	// L1311
          for (int v758 = 0; v758 < 3; v758 += 1) {	// L1312
            for (int v759 = 0; v759 < 3; v759 += 1) {	// L1313
              int8_t v760 = v739[v754][v757][(v755 + v758)][(v756 + v759)];	// L1314
              int8_t v761 = v737[v757][v758][v759];	// L1315
              int8_t v762 = v749[v754][v757][v755][v756];	// L1316
              int8_t v763 = v760 * v761;	// L1317
              int8_t v764 = v762 + v763;	// L1318
              v749[v754][v757][v755][v756] = v764;	// L1319
            }
          }
        }
      }
    }
  }
  for (int v765 = 0; v765 < 1; v765 += 1) {	// L1326
    for (int v766 = 0; v766 < 128; v766 += 1) {	// L1327
      for (int v767 = 0; v767 < 56; v767 += 1) {	// L1328
        for (int v768 = 0; v768 < 56; v768 += 1) {	// L1329
          int8_t v769 = v749[0][v766][v767][v768];	// L1330
          bool v770 = v769 > (int8_t)0.000000;	// L1331
          int8_t v771 = v770 ? v769 : (int8_t)0.000000;	// L1332
          v738[v765][v766][v767][v768] = v771;	// L1333
        }
      }
    }
  }
}

void main_graph_node26(
  int8_t v772[128][64][1][1],
  int8_t v773[1][64][56][56],
  int8_t v774[1][128][56][56]
) {	// L1340
  // #pragma HLS dataflow

  int8_t v775[1][128][56][56];	// L1342
  // #pragma HLS stream variable=v775 depth=10 type=fifo

  #pragma HLS bind_storage variable=v775 type=ram_t2p impl=bram

  for (int v776 = 0; v776 < 1; v776 += 1) {	// L1343
    for (int v777 = 0; v777 < 128; v777 += 1) {	// L1344
      for (int v778 = 0; v778 < 56; v778 += 1) {	// L1345
        for (int v779 = 0; v779 < 56; v779 += 1) {	// L1346
          v775[v776][v777][v778][v779] = (int8_t)0.000000;	// L1347
        }
      }
    }
  }
  for (int v780 = 0; v780 < 1; v780 += 1) {	// L1352
    for (int v781 = 0; v781 < 128; v781 += 1) {	// L1353
      for (int v782 = 0; v782 < 56; v782 += 1) {	// L1354
        for (int v783 = 0; v783 < 56; v783 += 1) {	// L1355
          for (int v784 = 0; v784 < 64; v784 += 1) {	// L1356
            for (int v785 = 0; v785 < 1; v785 += 1) {	// L1357
              for (int v786 = 0; v786 < 1; v786 += 1) {	// L1358
                int8_t v787 = v773[v780][v784][(v782 + v785)][(v783 + v786)];	// L1359
                int8_t v788 = v772[v781][v784][v785][v786];	// L1360
                int8_t v789 = v775[v780][v781][v782][v783];	// L1361
                int8_t v790 = v787 * v788;	// L1362
                int8_t v791 = v789 + v790;	// L1363
                v775[v780][v781][v782][v783] = v791;	// L1364
              }
            }
          }
        }
      }
    }
  }
  for (int v792 = 0; v792 < 1; v792 += 1) {	// L1372
    for (int v793 = 0; v793 < 128; v793 += 1) {	// L1373
      for (int v794 = 0; v794 < 56; v794 += 1) {	// L1374
        for (int v795 = 0; v795 < 56; v795 += 1) {	// L1375
          int8_t v796 = v775[0][v793][v794][v795];	// L1376
          bool v797 = v796 > (int8_t)0.000000;	// L1377
          int8_t v798 = v797 ? v796 : (int8_t)0.000000;	// L1378
          v774[v792][v793][v794][v795] = v798;	// L1379
        }
      }
    }
  }
}

void main_graph_node27(
  int8_t v799[1][64][112][112],
  int8_t v800[64][3][3],
  int8_t v801[1][64][56][56]
) {	// L1386
  // #pragma HLS dataflow

  int8_t v802[1][64][114][114];	// L1388
  // #pragma HLS stream variable=v802 depth=10 type=fifo

  #pragma HLS bind_storage variable=v802 type=ram_t2p impl=bram

  for (int v803 = 0; v803 < 1; v803 += 1) {	// L1389
    for (int v804 = 0; v804 < 64; v804 += 1) {	// L1390
      for (int v805 = 0; v805 < 114; v805 += 1) {	// L1391
        for (int v806 = 0; v806 < 114; v806 += 1) {	// L1392
          v802[v803][v804][v805][v806] = (int8_t)0.000000;	// L1393
        }
      }
    }
  }
  for (int v807 = 0; v807 < 1; v807 += 1) {	// L1398
    for (int v808 = 0; v808 < 64; v808 += 1) {	// L1399
      for (int v809 = 0; v809 < 112; v809 += 1) {	// L1400
        for (int v810 = 0; v810 < 112; v810 += 1) {	// L1401
          int8_t v811 = v799[v807][v808][v809][v810];	// L1402
          v802[v807][v808][(v809 + 1)][(v810 + 1)] = v811;	// L1403
        }
      }
    }
  }
  int8_t v812[1][64][56][56];	// L1408
  // #pragma HLS stream variable=v812 depth=10 type=fifo

  #pragma HLS bind_storage variable=v812 type=ram_t2p impl=bram

  for (int v813 = 0; v813 < 1; v813 += 1) {	// L1409
    for (int v814 = 0; v814 < 64; v814 += 1) {	// L1410
      for (int v815 = 0; v815 < 56; v815 += 1) {	// L1411
        for (int v816 = 0; v816 < 56; v816 += 1) {	// L1412
          v812[v813][v814][v815][v816] = (int8_t)0.000000;	// L1413
        }
      }
    }
  }
  for (int v817 = 0; v817 < 1; v817 += 1) {	// L1418
    for (int v818 = 0; v818 < 56; v818 += 1) {	// L1419
      for (int v819 = 0; v819 < 56; v819 += 1) {	// L1420
        for (int v820 = 0; v820 < 64; v820 += 1) {	// L1421
          for (int v821 = 0; v821 < 3; v821 += 1) {	// L1422
            for (int v822 = 0; v822 < 3; v822 += 1) {	// L1423
              int8_t v823 = v802[v817][v820][((v818 * 2) + v821)][((v819 * 2) + v822)];	// L1424
              int8_t v824 = v800[v820][v821][v822];	// L1425
              int8_t v825 = v812[v817][v820][v818][v819];	// L1426
              int8_t v826 = v823 * v824;	// L1427
              int8_t v827 = v825 + v826;	// L1428
              v812[v817][v820][v818][v819] = v827;	// L1429
            }
          }
        }
      }
    }
  }
  for (int v828 = 0; v828 < 1; v828 += 1) {	// L1436
    for (int v829 = 0; v829 < 64; v829 += 1) {	// L1437
      for (int v830 = 0; v830 < 56; v830 += 1) {	// L1438
        for (int v831 = 0; v831 < 56; v831 += 1) {	// L1439
          int8_t v832 = v812[0][v829][v830][v831];	// L1440
          bool v833 = v832 > (int8_t)0.000000;	// L1441
          int8_t v834 = v833 ? v832 : (int8_t)0.000000;	// L1442
          v801[v828][v829][v830][v831] = v834;	// L1443
        }
      }
    }
  }
}

void main_graph_node28(
  int8_t v835[1][32][112][112],
  int8_t v836[64][32][1][1],
  int8_t v837[1][64][112][112]
) {	// L1450
  // #pragma HLS dataflow

  int8_t v838[1][64][112][112];	// L1452
  // #pragma HLS stream variable=v838 depth=10 type=fifo

  #pragma HLS bind_storage variable=v838 type=ram_t2p impl=bram

  for (int v839 = 0; v839 < 1; v839 += 1) {	// L1453
    for (int v840 = 0; v840 < 64; v840 += 1) {	// L1454
      for (int v841 = 0; v841 < 112; v841 += 1) {	// L1455
        for (int v842 = 0; v842 < 112; v842 += 1) {	// L1456
          v838[v839][v840][v841][v842] = (int8_t)0.000000;	// L1457
        }
      }
    }
  }
  for (int v843 = 0; v843 < 1; v843 += 1) {	// L1462
    for (int v844 = 0; v844 < 64; v844 += 1) {	// L1463
      for (int v845 = 0; v845 < 112; v845 += 1) {	// L1464
        for (int v846 = 0; v846 < 112; v846 += 1) {	// L1465
          for (int v847 = 0; v847 < 32; v847 += 1) {	// L1466
            for (int v848 = 0; v848 < 1; v848 += 1) {	// L1467
              for (int v849 = 0; v849 < 1; v849 += 1) {	// L1468
                int8_t v850 = v835[v843][v847][(v845 + v848)][(v846 + v849)];	// L1469
                int8_t v851 = v836[v844][v847][v848][v849];	// L1470
                int8_t v852 = v838[v843][v844][v845][v846];	// L1471
                int8_t v853 = v850 * v851;	// L1472
                int8_t v854 = v852 + v853;	// L1473
                v838[v843][v844][v845][v846] = v854;	// L1474
              }
            }
          }
        }
      }
    }
  }
  for (int v855 = 0; v855 < 1; v855 += 1) {	// L1482
    for (int v856 = 0; v856 < 64; v856 += 1) {	// L1483
      for (int v857 = 0; v857 < 112; v857 += 1) {	// L1484
        for (int v858 = 0; v858 < 112; v858 += 1) {	// L1485
          int8_t v859 = v838[0][v856][v857][v858];	// L1486
          bool v860 = v859 > (int8_t)0.000000;	// L1487
          int8_t v861 = v860 ? v859 : (int8_t)0.000000;	// L1488
          v837[v855][v856][v857][v858] = v861;	// L1489
        }
      }
    }
  }
}

void main_graph_node29(
  int8_t v862[32][3][3],
  int8_t v863[1][32][112][112],
  int8_t v864[1][32][112][112]
) {	// L1496
  // #pragma HLS dataflow

  int8_t v865[1][32][114][114];	// L1498
  // #pragma HLS stream variable=v865 depth=10 type=fifo

  #pragma HLS bind_storage variable=v865 type=ram_t2p impl=bram

  for (int v866 = 0; v866 < 1; v866 += 1) {	// L1499
    for (int v867 = 0; v867 < 32; v867 += 1) {	// L1500
      for (int v868 = 0; v868 < 114; v868 += 1) {	// L1501
        for (int v869 = 0; v869 < 114; v869 += 1) {	// L1502
          v865[v866][v867][v868][v869] = (int8_t)0.000000;	// L1503
        }
      }
    }
  }
  for (int v870 = 0; v870 < 1; v870 += 1) {	// L1508
    for (int v871 = 0; v871 < 32; v871 += 1) {	// L1509
      for (int v872 = 0; v872 < 112; v872 += 1) {	// L1510
        for (int v873 = 0; v873 < 112; v873 += 1) {	// L1511
          int8_t v874 = v863[v870][v871][v872][v873];	// L1512
          v865[v870][v871][(v872 + 1)][(v873 + 1)] = v874;	// L1513
        }
      }
    }
  }
  int8_t v875[1][32][112][112];	// L1518
  // #pragma HLS stream variable=v875 depth=10 type=fifo

  #pragma HLS bind_storage variable=v875 type=ram_t2p impl=bram

  for (int v876 = 0; v876 < 1; v876 += 1) {	// L1519
    for (int v877 = 0; v877 < 32; v877 += 1) {	// L1520
      for (int v878 = 0; v878 < 112; v878 += 1) {	// L1521
        for (int v879 = 0; v879 < 112; v879 += 1) {	// L1522
          v875[v876][v877][v878][v879] = (int8_t)0.000000;	// L1523
        }
      }
    }
  }
  for (int v880 = 0; v880 < 1; v880 += 1) {	// L1528
    for (int v881 = 0; v881 < 112; v881 += 1) {	// L1529
      for (int v882 = 0; v882 < 112; v882 += 1) {	// L1530
        for (int v883 = 0; v883 < 32; v883 += 1) {	// L1531
          for (int v884 = 0; v884 < 3; v884 += 1) {	// L1532
            for (int v885 = 0; v885 < 3; v885 += 1) {	// L1533
              int8_t v886 = v865[v880][v883][(v881 + v884)][(v882 + v885)];	// L1534
              int8_t v887 = v862[v883][v884][v885];	// L1535
              int8_t v888 = v875[v880][v883][v881][v882];	// L1536
              int8_t v889 = v886 * v887;	// L1537
              int8_t v890 = v888 + v889;	// L1538
              v875[v880][v883][v881][v882] = v890;	// L1539
            }
          }
        }
      }
    }
  }
  for (int v891 = 0; v891 < 1; v891 += 1) {	// L1546
    for (int v892 = 0; v892 < 32; v892 += 1) {	// L1547
      for (int v893 = 0; v893 < 112; v893 += 1) {	// L1548
        for (int v894 = 0; v894 < 112; v894 += 1) {	// L1549
          int8_t v895 = v875[0][v892][v893][v894];	// L1550
          bool v896 = v895 > (int8_t)0.000000;	// L1551
          int8_t v897 = v896 ? v895 : (int8_t)0.000000;	// L1552
          v864[v891][v892][v893][v894] = v897;	// L1553
        }
      }
    }
  }
}

void main_graph_node30(
  int8_t v898[32][3][3][3],
  int8_t v899[1][3][224][224],
  int8_t v900[1][32][112][112]
) {	// L1560
  // #pragma HLS dataflow

  int8_t v901[1][3][226][226];	// L1562
  // #pragma HLS stream variable=v901 depth=10 type=fifo

  #pragma HLS bind_storage variable=v901 type=ram_t2p impl=bram

  for (int v902 = 0; v902 < 1; v902 += 1) {	// L1563
    for (int v903 = 0; v903 < 3; v903 += 1) {	// L1564
      for (int v904 = 0; v904 < 226; v904 += 1) {	// L1565
        for (int v905 = 0; v905 < 226; v905 += 1) {	// L1566
          v901[v902][v903][v904][v905] = (int8_t)0.000000;	// L1567
        }
      }
    }
  }
  for (int v906 = 0; v906 < 1; v906 += 1) {	// L1572
    for (int v907 = 0; v907 < 3; v907 += 1) {	// L1573
      for (int v908 = 0; v908 < 224; v908 += 1) {	// L1574
        for (int v909 = 0; v909 < 224; v909 += 1) {	// L1575
          int8_t v910 = v899[v906][v907][v908][v909];	// L1576
          v901[v906][v907][(v908 + 1)][(v909 + 1)] = v910;	// L1577
        }
      }
    }
  }
  int8_t v911[1][32][112][112];	// L1582
  // #pragma HLS stream variable=v911 depth=10 type=fifo

  #pragma HLS bind_storage variable=v911 type=ram_t2p impl=bram

  for (int v912 = 0; v912 < 1; v912 += 1) {	// L1583
    for (int v913 = 0; v913 < 32; v913 += 1) {	// L1584
      for (int v914 = 0; v914 < 112; v914 += 1) {	// L1585
        for (int v915 = 0; v915 < 112; v915 += 1) {	// L1586
          v911[v912][v913][v914][v915] = (int8_t)0.000000;	// L1587
        }
      }
    }
  }
  for (int v916 = 0; v916 < 1; v916 += 1) {	// L1592
    for (int v917 = 0; v917 < 32; v917 += 1) {	// L1593
      for (int v918 = 0; v918 < 112; v918 += 1) {	// L1594
        for (int v919 = 0; v919 < 112; v919 += 1) {	// L1595
          for (int v920 = 0; v920 < 3; v920 += 1) {	// L1596
            for (int v921 = 0; v921 < 3; v921 += 1) {	// L1597
              for (int v922 = 0; v922 < 3; v922 += 1) {	// L1598
                int8_t v923 = v901[v916][v920][((v918 * 2) + v921)][((v919 * 2) + v922)];	// L1599
                int8_t v924 = v898[v917][v920][v921][v922];	// L1600
                int8_t v925 = v911[v916][v917][v918][v919];	// L1601
                int8_t v926 = v923 * v924;	// L1602
                int8_t v927 = v925 + v926;	// L1603
                v911[v916][v917][v918][v919] = v927;	// L1604
              }
            }
          }
        }
      }
    }
  }
  for (int v928 = 0; v928 < 1; v928 += 1) {	// L1612
    for (int v929 = 0; v929 < 32; v929 += 1) {	// L1613
      for (int v930 = 0; v930 < 112; v930 += 1) {	// L1614
        for (int v931 = 0; v931 < 112; v931 += 1) {	// L1615
          int8_t v932 = v911[0][v929][v930][v931];	// L1616
          bool v933 = v932 > (int8_t)0.000000;	// L1617
          int8_t v934 = v933 ? v932 : (int8_t)0.000000;	// L1618
          v900[v928][v929][v930][v931] = v934;	// L1619
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v935[1][3][224][224],
  int8_t v936[1000],
  int8_t v937[1024][1024][1][1],
  int8_t v938[1024][512][1][1],
  int8_t v939[512][512][1][1],
  int8_t v940[512][512][1][1],
  int8_t v941[512][512][1][1],
  int8_t v942[512][512][1][1],
  int8_t v943[512][512][1][1],
  int8_t v944[512][256][1][1],
  int8_t v945[256][256][1][1],
  int8_t v946[256][128][1][1],
  int8_t v947[128][128][1][1],
  int8_t v948[128][64][1][1],
  int8_t v949[64][32][1][1],
  int8_t v950[32][3][3][3],
  int8_t v951[32][3][3],
  int8_t v952[64][3][3],
  int8_t v953[128][3][3],
  int8_t v954[128][3][3],
  int8_t v955[256][3][3],
  int8_t v956[256][3][3],
  int8_t v957[512][3][3],
  int8_t v958[512][3][3],
  int8_t v959[512][3][3],
  int8_t v960[512][3][3],
  int8_t v961[512][3][3],
  int8_t v962[512][3][3],
  int8_t v963[1024][3][3],
  int8_t v964[1024][1000],
  int8_t v965[1][1000]
) {	// L1626
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v935
  #pragma HLS bind_storage variable=v935 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v936
  #pragma HLS bind_storage variable=v936 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v937
  #pragma HLS bind_storage variable=v937 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v938
  #pragma HLS bind_storage variable=v938 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v939
  #pragma HLS bind_storage variable=v939 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v940
  #pragma HLS bind_storage variable=v940 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v941
  #pragma HLS bind_storage variable=v941 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v942
  #pragma HLS bind_storage variable=v942 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v943
  #pragma HLS bind_storage variable=v943 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v944
  #pragma HLS bind_storage variable=v944 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v945
  #pragma HLS bind_storage variable=v945 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v946
  #pragma HLS bind_storage variable=v946 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v947
  #pragma HLS bind_storage variable=v947 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v948
  #pragma HLS bind_storage variable=v948 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v949
  #pragma HLS bind_storage variable=v949 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v950
  #pragma HLS bind_storage variable=v950 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v951
  #pragma HLS bind_storage variable=v951 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v952
  #pragma HLS bind_storage variable=v952 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v953
  #pragma HLS bind_storage variable=v953 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v954
  #pragma HLS bind_storage variable=v954 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v955
  #pragma HLS bind_storage variable=v955 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v956
  #pragma HLS bind_storage variable=v956 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v957
  #pragma HLS bind_storage variable=v957 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v958
  #pragma HLS bind_storage variable=v958 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v959
  #pragma HLS bind_storage variable=v959 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v960
  #pragma HLS bind_storage variable=v960 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v961
  #pragma HLS bind_storage variable=v961 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v962
  #pragma HLS bind_storage variable=v962 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v963
  #pragma HLS bind_storage variable=v963 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v964
  #pragma HLS bind_storage variable=v964 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v965
  #pragma HLS bind_storage variable=v965 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  int8_t v966[1][32][112][112];	// L1628
  // #pragma HLS stream variable=v966 depth=10 type=fifo

  #pragma HLS bind_storage variable=v966 type=ram_t2p impl=bram

  main_graph_node30(v950, v935, v966);	// L1629                   PCR
  int8_t v967[1][32][112][112];	// L1630
  // #pragma HLS stream variable=v967 depth=10 type=fifo

  #pragma HLS bind_storage variable=v967 type=ram_t2p impl=bram

  main_graph_node29(v951, v966, v967);	// L1631                      PCR 
  int8_t v968[1][64][112][112];	// L1632
  // #pragma HLS stream variable=v968 depth=10 type=fifo

  #pragma HLS bind_storage variable=v968 type=ram_t2p impl=bram

  main_graph_node28(v967, v949, v968);	// L1633                      CR
  int8_t v969[1][64][56][56];	// L1634
  // #pragma HLS stream variable=v969 depth=10 type=fifo

  #pragma HLS bind_storage variable=v969 type=ram_t2p impl=bram

  main_graph_node27(v968, v952, v969);	// L1635                      PCR
  int8_t v970[1][128][56][56];	// L1636
  // #pragma HLS stream variable=v970 depth=10 type=fifo

  #pragma HLS bind_storage variable=v970 type=ram_t2p impl=bram

  main_graph_node26(v948, v969, v970);	// L1637                    CR
  int8_t v971[1][128][56][56];	// L1638
  // #pragma HLS stream variable=v971 depth=10 type=fifo

  #pragma HLS bind_storage variable=v971 type=ram_t2p impl=bram

  main_graph_node25(v970, v953, v971);	// L1639              PCR
  int8_t v972[1][128][56][56];	// L1640
  // #pragma HLS stream variable=v972 depth=10 type=fifo

  #pragma HLS bind_storage variable=v972 type=ram_t2p impl=bram

  main_graph_node24(v947, v971, v972);	// L1641               CR
  int8_t v973[1][128][28][28];	// L1642
  // #pragma HLS stream variable=v973 depth=10 type=fifo

  #pragma HLS bind_storage variable=v973 type=ram_t2p impl=bram

  main_graph_node23(v972, v954, v973);	// L1643           PCR       
  int8_t v974[1][256][28][28];	// L1644
  // #pragma HLS stream variable=v974 depth=10 type=fifo

  #pragma HLS bind_storage variable=v974 type=ram_t2p impl=bram

  main_graph_node22(v946, v973, v974);	// L1645              CR
  int8_t v975[1][256][28][28];	// L1646
  // #pragma HLS stream variable=v975 depth=10 type=fifo

  #pragma HLS bind_storage variable=v975 type=ram_t2p impl=bram

  main_graph_node21(v955, v974, v975);	// L1647
  int8_t v976[1][256][28][28];	// L1648
  // #pragma HLS stream variable=v976 depth=10 type=fifo

  #pragma HLS bind_storage variable=v976 type=ram_t2p impl=bram

  main_graph_node20(v975, v945, v976);	// L1649
  int8_t v977[1][256][14][14];	// L1650
  // #pragma HLS stream variable=v977 depth=10 type=fifo

  #pragma HLS bind_storage variable=v977 type=ram_t2p impl=bram

  main_graph_node19(v976, v956, v977);	// L1651
  int8_t v978[1][512][14][14];	// L1652
  // #pragma HLS stream variable=v978 depth=10 type=fifo

  #pragma HLS bind_storage variable=v978 type=ram_t2p impl=bram

  main_graph_node18(v977, v944, v978);	// L1653
  int8_t v979[1][512][14][14];	// L1654
  // #pragma HLS stream variable=v979 depth=10 type=fifo

  #pragma HLS bind_storage variable=v979 type=ram_t2p impl=bram

  main_graph_node17(v978, v957, v979);	// L1655
  int8_t v980[1][512][14][14];	// L1656
  // #pragma HLS stream variable=v980 depth=10 type=fifo

  #pragma HLS bind_storage variable=v980 type=ram_t2p impl=bram

  main_graph_node16(v979, v943, v980);	// L1657
  int8_t v981[1][512][14][14];	// L1658
  // #pragma HLS stream variable=v981 depth=10 type=fifo

  #pragma HLS bind_storage variable=v981 type=ram_t2p impl=bram

  main_graph_node15(v958, v980, v981);	// L1659
  int8_t v982[1][512][14][14];	// L1660
  // #pragma HLS stream variable=v982 depth=10 type=fifo

  #pragma HLS bind_storage variable=v982 type=ram_t2p impl=bram

  main_graph_node14(v942, v981, v982);	// L1661
  int8_t v983[1][512][14][14];	// L1662
  // #pragma HLS stream variable=v983 depth=10 type=fifo

  #pragma HLS bind_storage variable=v983 type=ram_t2p impl=bram

  main_graph_node13(v959, v982, v983);	// L1663
  int8_t v984[1][512][14][14];	// L1664
  // #pragma HLS stream variable=v984 depth=10 type=fifo

  #pragma HLS bind_storage variable=v984 type=ram_t2p impl=bram

  main_graph_node12(v941, v983, v984);	// L1665
  int8_t v985[1][512][14][14];	// L1666
  // #pragma HLS stream variable=v985 depth=10 type=fifo

  #pragma HLS bind_storage variable=v985 type=ram_t2p impl=bram

  main_graph_node11(v984, v960, v985);	// L1667
  int8_t v986[1][512][14][14];	// L1668
  // #pragma HLS stream variable=v986 depth=10 type=fifo

  #pragma HLS bind_storage variable=v986 type=ram_t2p impl=bram

  main_graph_node10(v985, v940, v986);	// L1669
  int8_t v987[1][512][14][14];	// L1670
  // #pragma HLS stream variable=v987 depth=10 type=fifo

  #pragma HLS bind_storage variable=v987 type=ram_t2p impl=bram

  main_graph_node9(v986, v961, v987);	// L1671
  int8_t v988[1][512][14][14];	// L1672
  // #pragma HLS stream variable=v988 depth=10 type=fifo

  #pragma HLS bind_storage variable=v988 type=ram_t2p impl=bram

  main_graph_node8(v987, v939, v988);	// L1673
  int8_t v989[1][512][7][7];	// L1674
  // #pragma HLS stream variable=v989 depth=10 type=fifo

  #pragma HLS bind_storage variable=v989 type=ram_t2p impl=bram

  main_graph_node7(v962, v988, v989);	// L1675
  int8_t v990[1][1024][7][7];	// L1676
  // #pragma HLS stream variable=v990 depth=10 type=fifo

  #pragma HLS bind_storage variable=v990 type=ram_t2p impl=bram

  main_graph_node6(v938, v989, v990);	// L1677
  int8_t v991[1][1024][7][7];	// L1678
  // #pragma HLS stream variable=v991 depth=10 type=fifo

  #pragma HLS bind_storage variable=v991 type=ram_t2p impl=bram

  main_graph_node5(v963, v990, v991);	// L1679
  int8_t v992[1][1024][7][7];	// L1680
  // #pragma HLS stream variable=v992 depth=10 type=fifo

  #pragma HLS bind_storage variable=v992 type=ram_t2p impl=bram

  main_graph_node4(v991, v937, v992);	// L1681
  int8_t v993[1][1024][8][8];	// L1682
  // #pragma HLS stream variable=v993 depth=10 type=fifo

  #pragma HLS bind_storage variable=v993 type=ram_t2p impl=bram

  main_graph_node3(v992, v993);	// L1683
  int8_t v994[1][1];	// L1684
  // #pragma HLS stream variable=v994 depth=10 type=fifo

  #pragma HLS bind_storage variable=v994 type=ram_t2p impl=bram

  int8_t v995[1][1024][1][1];	// L1685
  // #pragma HLS stream variable=v995 depth=10 type=fifo

  #pragma HLS bind_storage variable=v995 type=ram_t2p impl=bram

  main_graph_node2(v993, v995, v994);	// L1686
  int8_t v996[1][1024][1][1];	// L1687
  // #pragma HLS stream variable=v996 depth=10 type=fifo

  #pragma HLS bind_storage variable=v996 type=ram_t2p impl=bram

  main_graph_node1(v995, v994, v996);	// L1688
  main_graph_node0(v936, v964, v996, v965);	// L1689
}

