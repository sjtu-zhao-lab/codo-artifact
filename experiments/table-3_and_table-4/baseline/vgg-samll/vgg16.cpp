
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
  int8_t v0[10],
  int8_t v1[512][10],
  int8_t v2[1][512][1][1],
  int8_t v3[1][10]
) {	// L3
  // #pragma HLS dataflow

  int8_t v4[1][10];	// L5
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L6
    for (int v6 = 0; v6 < 10; v6 += 1) {	// L7
      v4[v5][v6] = (int8_t)0.000000;	// L8
    }
  }
  for (int v7 = 0; v7 < 1; v7 += 1) {	// L11
    for (int v8 = 0; v8 < 10; v8 += 1) {	// L12
      for (int v9 = 0; v9 < 512; v9 += 1) {	// L13
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
    for (int v16 = 0; v16 < 10; v16 += 1) {	// L24
      int8_t v17 = v4[0][v16];	// L25
      int8_t v18 = v0[v16];	// L26
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
  int8_t v35[1][512][2][2],
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
          for (int v46 = 0; v46 < 1; v46 += 1) {	// L75
            for (int v47 = 0; v47 < 1; v47 += 1) {	// L76
              int8_t v48 = v37[v42][v43][v44][v45];	// L77
              int v49 = v44 + (int)1;	// L78
              int v50 = v45 + (int)1;	// L79
              int v51 = v44 + v46;	// L80
              int v52 = v45 + v47;	// L81
              int8_t v53 = v35[v42][v43][v51][v52];	// L82
              bool v54 = v51 < v49;	// L83
              int8_t v55 = v54 ? v53 : (int8_t)0.000000;	// L84
              bool v56 = v52 < v50;	// L85
              int8_t v57 = v56 ? v55 : (int8_t)0.000000;	// L86
              int8_t v58 = v57 + v48;	// L87
              v37[v42][v43][v44][v45] = v58;	// L88
              v36[v44][v45] = (int8_t)1.000000;	// L89
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v59[1][512][1][1],
  int8_t v60[1][512][2][2]
) {	// L98
  // #pragma HLS dataflow

  for (int v61 = 0; v61 < 1; v61 += 1) {	// L100
    for (int v62 = 0; v62 < 512; v62 += 1) {	// L101
      for (int v63 = 0; v63 < 2; v63 += 1) {	// L102
        for (int v64 = 0; v64 < 2; v64 += 1) {	// L103
          v60[v61][v62][v63][v64] = (int8_t)0.000000;	// L104
        }
      }
    }
  }
  for (int v65 = 0; v65 < 1; v65 += 1) {	// L109
    for (int v66 = 0; v66 < 512; v66 += 1) {	// L110
      for (int v67 = 0; v67 < 1; v67 += 1) {	// L111
        for (int v68 = 0; v68 < 1; v68 += 1) {	// L112
          int8_t v69 = v59[v65][v66][v67][v68];	// L113
          v60[v65][v66][v67][v68] = v69;	// L114
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v70[512][512][3][3],
  int8_t v71[1][512][2][2],
  int8_t v72[1][512][1][1]
) {	// L121
  // #pragma HLS dataflow

  int8_t v73[1][512][4][4];	// L123
  // #pragma HLS stream variable=v73 depth=10 type=fifo

  #pragma HLS bind_storage variable=v73 type=ram_t2p impl=bram

  for (int v74 = 0; v74 < 1; v74 += 1) {	// L124
    for (int v75 = 0; v75 < 512; v75 += 1) {	// L125
      for (int v76 = 0; v76 < 4; v76 += 1) {	// L126
        for (int v77 = 0; v77 < 4; v77 += 1) {	// L127
          v73[v74][v75][v76][v77] = (int8_t)0.000000;	// L128
        }
      }
    }
  }
  for (int v78 = 0; v78 < 1; v78 += 1) {	// L133
    for (int v79 = 0; v79 < 512; v79 += 1) {	// L134
      for (int v80 = 0; v80 < 2; v80 += 1) {	// L135
        for (int v81 = 0; v81 < 2; v81 += 1) {	// L136
          int8_t v82 = v71[v78][v79][v80][v81];	// L137
          v73[v78][v79][(v80 + 1)][(v81 + 1)] = v82;	// L138
        }
      }
    }
  }
  int8_t v83[1][512][1][1];	// L143
  // #pragma HLS stream variable=v83 depth=10 type=fifo

  #pragma HLS bind_storage variable=v83 type=ram_t2p impl=bram

  for (int v84 = 0; v84 < 1; v84 += 1) {	// L144
    for (int v85 = 0; v85 < 512; v85 += 1) {	// L145
      for (int v86 = 0; v86 < 1; v86 += 1) {	// L146
        for (int v87 = 0; v87 < 1; v87 += 1) {	// L147
          v83[v84][v85][v86][v87] = (int8_t)0.000000;	// L148
        }
      }
    }
  }
  for (int v88 = 0; v88 < 1; v88 += 1) {	// L153
    for (int v89 = 0; v89 < 512; v89 += 1) {	// L154
      for (int v90 = 0; v90 < 1; v90 += 1) {	// L155
        for (int v91 = 0; v91 < 1; v91 += 1) {	// L156
          for (int v92 = 0; v92 < 512; v92 += 1) {	// L157
            for (int v93 = 0; v93 < 3; v93 += 1) {	// L158
              for (int v94 = 0; v94 < 3; v94 += 1) {	// L159
                int8_t v95 = v73[v88][v92][((v90 * 2) + v93)][((v91 * 2) + v94)];	// L160
                int8_t v96 = v70[v89][v92][v93][v94];	// L161
                int8_t v97 = v83[v88][v89][v90][v91];	// L162
                int8_t v98 = v95 * v96;	// L163
                int8_t v99 = v97 + v98;	// L164
                v83[v88][v89][v90][v91] = v99;	// L165
              }
            }
          }
        }
      }
    }
  }
  for (int v100 = 0; v100 < 1; v100 += 1) {	// L173
    for (int v101 = 0; v101 < 512; v101 += 1) {	// L174
      for (int v102 = 0; v102 < 1; v102 += 1) {	// L175
        for (int v103 = 0; v103 < 1; v103 += 1) {	// L176
          int8_t v104 = v83[0][v101][0][0];	// L177
          bool v105 = v104 > (int8_t)0.000000;	// L178
          int8_t v106 = v105 ? v104 : (int8_t)0.000000;	// L179
          v72[v100][v101][v102][v103] = v106;	// L180
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v107[1][512][2][2],
  int8_t v108[512][512][3][3],
  int8_t v109[1][512][2][2]
) {	// L187
  // #pragma HLS dataflow

  int8_t v110[1][512][4][4];	// L189
  // #pragma HLS stream variable=v110 depth=10 type=fifo

  #pragma HLS bind_storage variable=v110 type=ram_t2p impl=bram

  for (int v111 = 0; v111 < 1; v111 += 1) {	// L190
    for (int v112 = 0; v112 < 512; v112 += 1) {	// L191
      for (int v113 = 0; v113 < 4; v113 += 1) {	// L192
        for (int v114 = 0; v114 < 4; v114 += 1) {	// L193
          v110[v111][v112][v113][v114] = (int8_t)0.000000;	// L194
        }
      }
    }
  }
  for (int v115 = 0; v115 < 1; v115 += 1) {	// L199
    for (int v116 = 0; v116 < 512; v116 += 1) {	// L200
      for (int v117 = 0; v117 < 2; v117 += 1) {	// L201
        for (int v118 = 0; v118 < 2; v118 += 1) {	// L202
          int8_t v119 = v107[v115][v116][v117][v118];	// L203
          v110[v115][v116][(v117 + 1)][(v118 + 1)] = v119;	// L204
        }
      }
    }
  }
  int8_t v120[1][512][2][2];	// L209
  // #pragma HLS stream variable=v120 depth=10 type=fifo

  #pragma HLS bind_storage variable=v120 type=ram_t2p impl=bram

  for (int v121 = 0; v121 < 1; v121 += 1) {	// L210
    for (int v122 = 0; v122 < 512; v122 += 1) {	// L211
      for (int v123 = 0; v123 < 2; v123 += 1) {	// L212
        for (int v124 = 0; v124 < 2; v124 += 1) {	// L213
          v120[v121][v122][v123][v124] = (int8_t)0.000000;	// L214
        }
      }
    }
  }
  for (int v125 = 0; v125 < 1; v125 += 1) {	// L219
    for (int v126 = 0; v126 < 512; v126 += 1) {	// L220
      for (int v127 = 0; v127 < 2; v127 += 1) {	// L221
        for (int v128 = 0; v128 < 2; v128 += 1) {	// L222
          for (int v129 = 0; v129 < 512; v129 += 1) {	// L223
            for (int v130 = 0; v130 < 3; v130 += 1) {	// L224
              for (int v131 = 0; v131 < 3; v131 += 1) {	// L225
                int8_t v132 = v110[v125][v129][(v127 + v130)][(v128 + v131)];	// L226
                int8_t v133 = v108[v126][v129][v130][v131];	// L227
                int8_t v134 = v120[v125][v126][v127][v128];	// L228
                int8_t v135 = v132 * v133;	// L229
                int8_t v136 = v134 + v135;	// L230
                v120[v125][v126][v127][v128] = v136;	// L231
              }
            }
          }
        }
      }
    }
  }
  for (int v137 = 0; v137 < 1; v137 += 1) {	// L239
    for (int v138 = 0; v138 < 512; v138 += 1) {	// L240
      for (int v139 = 0; v139 < 2; v139 += 1) {	// L241
        for (int v140 = 0; v140 < 2; v140 += 1) {	// L242
          int8_t v141 = v120[0][v138][v139][v140];	// L243
          bool v142 = v141 > (int8_t)0.000000;	// L244
          int8_t v143 = v142 ? v141 : (int8_t)0.000000;	// L245
          v109[v137][v138][v139][v140] = v143;	// L246
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v144[1][512][2][2],
  int8_t v145[512][512][3][3],
  int8_t v146[1][512][2][2]
) {	// L253
  // #pragma HLS dataflow

  int8_t v147[1][512][4][4];	// L255
  // #pragma HLS stream variable=v147 depth=10 type=fifo

  #pragma HLS bind_storage variable=v147 type=ram_t2p impl=bram

  for (int v148 = 0; v148 < 1; v148 += 1) {	// L256
    for (int v149 = 0; v149 < 512; v149 += 1) {	// L257
      for (int v150 = 0; v150 < 4; v150 += 1) {	// L258
        for (int v151 = 0; v151 < 4; v151 += 1) {	// L259
          v147[v148][v149][v150][v151] = (int8_t)0.000000;	// L260
        }
      }
    }
  }
  for (int v152 = 0; v152 < 1; v152 += 1) {	// L265
    for (int v153 = 0; v153 < 512; v153 += 1) {	// L266
      for (int v154 = 0; v154 < 2; v154 += 1) {	// L267
        for (int v155 = 0; v155 < 2; v155 += 1) {	// L268
          int8_t v156 = v144[v152][v153][v154][v155];	// L269
          v147[v152][v153][(v154 + 1)][(v155 + 1)] = v156;	// L270
        }
      }
    }
  }
  int8_t v157[1][512][2][2];	// L275
  // #pragma HLS stream variable=v157 depth=10 type=fifo

  #pragma HLS bind_storage variable=v157 type=ram_t2p impl=bram

  for (int v158 = 0; v158 < 1; v158 += 1) {	// L276
    for (int v159 = 0; v159 < 512; v159 += 1) {	// L277
      for (int v160 = 0; v160 < 2; v160 += 1) {	// L278
        for (int v161 = 0; v161 < 2; v161 += 1) {	// L279
          v157[v158][v159][v160][v161] = (int8_t)0.000000;	// L280
        }
      }
    }
  }
  for (int v162 = 0; v162 < 1; v162 += 1) {	// L285
    for (int v163 = 0; v163 < 512; v163 += 1) {	// L286
      for (int v164 = 0; v164 < 2; v164 += 1) {	// L287
        for (int v165 = 0; v165 < 2; v165 += 1) {	// L288
          for (int v166 = 0; v166 < 512; v166 += 1) {	// L289
            for (int v167 = 0; v167 < 3; v167 += 1) {	// L290
              for (int v168 = 0; v168 < 3; v168 += 1) {	// L291
                int8_t v169 = v147[v162][v166][(v164 + v167)][(v165 + v168)];	// L292
                int8_t v170 = v145[v163][v166][v167][v168];	// L293
                int8_t v171 = v157[v162][v163][v164][v165];	// L294
                int8_t v172 = v169 * v170;	// L295
                int8_t v173 = v171 + v172;	// L296
                v157[v162][v163][v164][v165] = v173;	// L297
              }
            }
          }
        }
      }
    }
  }
  for (int v174 = 0; v174 < 1; v174 += 1) {	// L305
    for (int v175 = 0; v175 < 512; v175 += 1) {	// L306
      for (int v176 = 0; v176 < 2; v176 += 1) {	// L307
        for (int v177 = 0; v177 < 2; v177 += 1) {	// L308
          int8_t v178 = v157[0][v175][v176][v177];	// L309
          bool v179 = v178 > (int8_t)0.000000;	// L310
          int8_t v180 = v179 ? v178 : (int8_t)0.000000;	// L311
          v146[v174][v175][v176][v177] = v180;	// L312
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v181[1][512][4][4],
  int8_t v182[512][512][3][3],
  int8_t v183[1][512][2][2]
) {	// L319
  // #pragma HLS dataflow

  int8_t v184[1][512][6][6];	// L321
  // #pragma HLS stream variable=v184 depth=10 type=fifo

  #pragma HLS bind_storage variable=v184 type=ram_t2p impl=bram

  for (int v185 = 0; v185 < 1; v185 += 1) {	// L322
    for (int v186 = 0; v186 < 512; v186 += 1) {	// L323
      for (int v187 = 0; v187 < 6; v187 += 1) {	// L324
        for (int v188 = 0; v188 < 6; v188 += 1) {	// L325
          v184[v185][v186][v187][v188] = (int8_t)0.000000;	// L326
        }
      }
    }
  }
  for (int v189 = 0; v189 < 1; v189 += 1) {	// L331
    for (int v190 = 0; v190 < 512; v190 += 1) {	// L332
      for (int v191 = 0; v191 < 4; v191 += 1) {	// L333
        for (int v192 = 0; v192 < 4; v192 += 1) {	// L334
          int8_t v193 = v181[v189][v190][v191][v192];	// L335
          v184[v189][v190][(v191 + 1)][(v192 + 1)] = v193;	// L336
        }
      }
    }
  }
  int8_t v194[1][512][2][2];	// L341
  // #pragma HLS stream variable=v194 depth=10 type=fifo

  #pragma HLS bind_storage variable=v194 type=ram_t2p impl=bram

  for (int v195 = 0; v195 < 1; v195 += 1) {	// L342
    for (int v196 = 0; v196 < 512; v196 += 1) {	// L343
      for (int v197 = 0; v197 < 2; v197 += 1) {	// L344
        for (int v198 = 0; v198 < 2; v198 += 1) {	// L345
          v194[v195][v196][v197][v198] = (int8_t)0.000000;	// L346
        }
      }
    }
  }
  for (int v199 = 0; v199 < 1; v199 += 1) {	// L351
    for (int v200 = 0; v200 < 512; v200 += 1) {	// L352
      for (int v201 = 0; v201 < 2; v201 += 1) {	// L353
        for (int v202 = 0; v202 < 2; v202 += 1) {	// L354
          for (int v203 = 0; v203 < 512; v203 += 1) {	// L355
            for (int v204 = 0; v204 < 3; v204 += 1) {	// L356
              for (int v205 = 0; v205 < 3; v205 += 1) {	// L357
                int8_t v206 = v184[v199][v203][((v201 * 2) + v204)][((v202 * 2) + v205)];	// L358
                int8_t v207 = v182[v200][v203][v204][v205];	// L359
                int8_t v208 = v194[v199][v200][v201][v202];	// L360
                int8_t v209 = v206 * v207;	// L361
                int8_t v210 = v208 + v209;	// L362
                v194[v199][v200][v201][v202] = v210;	// L363
              }
            }
          }
        }
      }
    }
  }
  for (int v211 = 0; v211 < 1; v211 += 1) {	// L371
    for (int v212 = 0; v212 < 512; v212 += 1) {	// L372
      for (int v213 = 0; v213 < 2; v213 += 1) {	// L373
        for (int v214 = 0; v214 < 2; v214 += 1) {	// L374
          int8_t v215 = v194[0][v212][v213][v214];	// L375
          bool v216 = v215 > (int8_t)0.000000;	// L376
          int8_t v217 = v216 ? v215 : (int8_t)0.000000;	// L377
          v183[v211][v212][v213][v214] = v217;	// L378
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v218[512][512][3][3],
  int8_t v219[1][512][4][4],
  int8_t v220[1][512][4][4]
) {	// L385
  // #pragma HLS dataflow

  int8_t v221[1][512][6][6];	// L387
  // #pragma HLS stream variable=v221 depth=10 type=fifo

  #pragma HLS bind_storage variable=v221 type=ram_t2p impl=bram

  for (int v222 = 0; v222 < 1; v222 += 1) {	// L388
    for (int v223 = 0; v223 < 512; v223 += 1) {	// L389
      for (int v224 = 0; v224 < 6; v224 += 1) {	// L390
        for (int v225 = 0; v225 < 6; v225 += 1) {	// L391
          v221[v222][v223][v224][v225] = (int8_t)0.000000;	// L392
        }
      }
    }
  }
  for (int v226 = 0; v226 < 1; v226 += 1) {	// L397
    for (int v227 = 0; v227 < 512; v227 += 1) {	// L398
      for (int v228 = 0; v228 < 4; v228 += 1) {	// L399
        for (int v229 = 0; v229 < 4; v229 += 1) {	// L400
          int8_t v230 = v219[v226][v227][v228][v229];	// L401
          v221[v226][v227][(v228 + 1)][(v229 + 1)] = v230;	// L402
        }
      }
    }
  }
  int8_t v231[1][512][4][4];	// L407
  // #pragma HLS stream variable=v231 depth=10 type=fifo

  #pragma HLS bind_storage variable=v231 type=ram_t2p impl=bram

  for (int v232 = 0; v232 < 1; v232 += 1) {	// L408
    for (int v233 = 0; v233 < 512; v233 += 1) {	// L409
      for (int v234 = 0; v234 < 4; v234 += 1) {	// L410
        for (int v235 = 0; v235 < 4; v235 += 1) {	// L411
          v231[v232][v233][v234][v235] = (int8_t)0.000000;	// L412
        }
      }
    }
  }
  for (int v236 = 0; v236 < 1; v236 += 1) {	// L417
    for (int v237 = 0; v237 < 512; v237 += 1) {	// L418
      for (int v238 = 0; v238 < 4; v238 += 1) {	// L419
        for (int v239 = 0; v239 < 4; v239 += 1) {	// L420
          for (int v240 = 0; v240 < 512; v240 += 1) {	// L421
            for (int v241 = 0; v241 < 3; v241 += 1) {	// L422
              for (int v242 = 0; v242 < 3; v242 += 1) {	// L423
                int8_t v243 = v221[v236][v240][(v238 + v241)][(v239 + v242)];	// L424
                int8_t v244 = v218[v237][v240][v241][v242];	// L425
                int8_t v245 = v231[v236][v237][v238][v239];	// L426
                int8_t v246 = v243 * v244;	// L427
                int8_t v247 = v245 + v246;	// L428
                v231[v236][v237][v238][v239] = v247;	// L429
              }
            }
          }
        }
      }
    }
  }
  for (int v248 = 0; v248 < 1; v248 += 1) {	// L437
    for (int v249 = 0; v249 < 512; v249 += 1) {	// L438
      for (int v250 = 0; v250 < 4; v250 += 1) {	// L439
        for (int v251 = 0; v251 < 4; v251 += 1) {	// L440
          int8_t v252 = v231[0][v249][v250][v251];	// L441
          bool v253 = v252 > (int8_t)0.000000;	// L442
          int8_t v254 = v253 ? v252 : (int8_t)0.000000;	// L443
          v220[v248][v249][v250][v251] = v254;	// L444
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v255[1][256][4][4],
  int8_t v256[512][256][3][3],
  int8_t v257[1][512][4][4]
) {	// L451
  // #pragma HLS dataflow

  int8_t v258[1][256][6][6];	// L453
  // #pragma HLS stream variable=v258 depth=10 type=fifo

  #pragma HLS bind_storage variable=v258 type=ram_t2p impl=bram

  for (int v259 = 0; v259 < 1; v259 += 1) {	// L454
    for (int v260 = 0; v260 < 256; v260 += 1) {	// L455
      for (int v261 = 0; v261 < 6; v261 += 1) {	// L456
        for (int v262 = 0; v262 < 6; v262 += 1) {	// L457
          v258[v259][v260][v261][v262] = (int8_t)0.000000;	// L458
        }
      }
    }
  }
  for (int v263 = 0; v263 < 1; v263 += 1) {	// L463
    for (int v264 = 0; v264 < 256; v264 += 1) {	// L464
      for (int v265 = 0; v265 < 4; v265 += 1) {	// L465
        for (int v266 = 0; v266 < 4; v266 += 1) {	// L466
          int8_t v267 = v255[v263][v264][v265][v266];	// L467
          v258[v263][v264][(v265 + 1)][(v266 + 1)] = v267;	// L468
        }
      }
    }
  }
  int8_t v268[1][512][4][4];	// L473
  // #pragma HLS stream variable=v268 depth=10 type=fifo

  #pragma HLS bind_storage variable=v268 type=ram_t2p impl=bram

  for (int v269 = 0; v269 < 1; v269 += 1) {	// L474
    for (int v270 = 0; v270 < 512; v270 += 1) {	// L475
      for (int v271 = 0; v271 < 4; v271 += 1) {	// L476
        for (int v272 = 0; v272 < 4; v272 += 1) {	// L477
          v268[v269][v270][v271][v272] = (int8_t)0.000000;	// L478
        }
      }
    }
  }
  for (int v273 = 0; v273 < 1; v273 += 1) {	// L483
    for (int v274 = 0; v274 < 512; v274 += 1) {	// L484
      for (int v275 = 0; v275 < 4; v275 += 1) {	// L485
        for (int v276 = 0; v276 < 4; v276 += 1) {	// L486
          for (int v277 = 0; v277 < 256; v277 += 1) {	// L487
            for (int v278 = 0; v278 < 3; v278 += 1) {	// L488
              for (int v279 = 0; v279 < 3; v279 += 1) {	// L489
                int8_t v280 = v258[v273][v277][(v275 + v278)][(v276 + v279)];	// L490
                int8_t v281 = v256[v274][v277][v278][v279];	// L491
                int8_t v282 = v268[v273][v274][v275][v276];	// L492
                int8_t v283 = v280 * v281;	// L493
                int8_t v284 = v282 + v283;	// L494
                v268[v273][v274][v275][v276] = v284;	// L495
              }
            }
          }
        }
      }
    }
  }
  for (int v285 = 0; v285 < 1; v285 += 1) {	// L503
    for (int v286 = 0; v286 < 512; v286 += 1) {	// L504
      for (int v287 = 0; v287 < 4; v287 += 1) {	// L505
        for (int v288 = 0; v288 < 4; v288 += 1) {	// L506
          int8_t v289 = v268[0][v286][v287][v288];	// L507
          bool v290 = v289 > (int8_t)0.000000;	// L508
          int8_t v291 = v290 ? v289 : (int8_t)0.000000;	// L509
          v257[v285][v286][v287][v288] = v291;	// L510
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v292[1][256][8][8],
  int8_t v293[256][256][3][3],
  int8_t v294[1][256][4][4]
) {	// L517
  // #pragma HLS dataflow

  int8_t v295[1][256][10][10];	// L519
  // #pragma HLS stream variable=v295 depth=10 type=fifo

  #pragma HLS bind_storage variable=v295 type=ram_t2p impl=bram

  for (int v296 = 0; v296 < 1; v296 += 1) {	// L520
    for (int v297 = 0; v297 < 256; v297 += 1) {	// L521
      for (int v298 = 0; v298 < 10; v298 += 1) {	// L522
        for (int v299 = 0; v299 < 10; v299 += 1) {	// L523
          v295[v296][v297][v298][v299] = (int8_t)0.000000;	// L524
        }
      }
    }
  }
  for (int v300 = 0; v300 < 1; v300 += 1) {	// L529
    for (int v301 = 0; v301 < 256; v301 += 1) {	// L530
      for (int v302 = 0; v302 < 8; v302 += 1) {	// L531
        for (int v303 = 0; v303 < 8; v303 += 1) {	// L532
          int8_t v304 = v292[v300][v301][v302][v303];	// L533
          v295[v300][v301][(v302 + 1)][(v303 + 1)] = v304;	// L534
        }
      }
    }
  }
  int8_t v305[1][256][4][4];	// L539
  // #pragma HLS stream variable=v305 depth=10 type=fifo

  #pragma HLS bind_storage variable=v305 type=ram_t2p impl=bram

  for (int v306 = 0; v306 < 1; v306 += 1) {	// L540
    for (int v307 = 0; v307 < 256; v307 += 1) {	// L541
      for (int v308 = 0; v308 < 4; v308 += 1) {	// L542
        for (int v309 = 0; v309 < 4; v309 += 1) {	// L543
          v305[v306][v307][v308][v309] = (int8_t)0.000000;	// L544
        }
      }
    }
  }
  for (int v310 = 0; v310 < 1; v310 += 1) {	// L549
    for (int v311 = 0; v311 < 256; v311 += 1) {	// L550
      for (int v312 = 0; v312 < 4; v312 += 1) {	// L551
        for (int v313 = 0; v313 < 4; v313 += 1) {	// L552
          for (int v314 = 0; v314 < 256; v314 += 1) {	// L553
            for (int v315 = 0; v315 < 3; v315 += 1) {	// L554
              for (int v316 = 0; v316 < 3; v316 += 1) {	// L555
                int8_t v317 = v295[v310][v314][((v312 * 2) + v315)][((v313 * 2) + v316)];	// L556
                int8_t v318 = v293[v311][v314][v315][v316];	// L557
                int8_t v319 = v305[v310][v311][v312][v313];	// L558
                int8_t v320 = v317 * v318;	// L559
                int8_t v321 = v319 + v320;	// L560
                v305[v310][v311][v312][v313] = v321;	// L561
              }
            }
          }
        }
      }
    }
  }
  for (int v322 = 0; v322 < 1; v322 += 1) {	// L569
    for (int v323 = 0; v323 < 256; v323 += 1) {	// L570
      for (int v324 = 0; v324 < 4; v324 += 1) {	// L571
        for (int v325 = 0; v325 < 4; v325 += 1) {	// L572
          int8_t v326 = v305[0][v323][v324][v325];	// L573
          bool v327 = v326 > (int8_t)0.000000;	// L574
          int8_t v328 = v327 ? v326 : (int8_t)0.000000;	// L575
          v294[v322][v323][v324][v325] = v328;	// L576
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v329[1][256][8][8],
  int8_t v330[256][256][3][3],
  int8_t v331[1][256][8][8]
) {	// L583
  // #pragma HLS dataflow

  int8_t v332[1][256][10][10];	// L585
  // #pragma HLS stream variable=v332 depth=10 type=fifo

  #pragma HLS bind_storage variable=v332 type=ram_t2p impl=bram

  for (int v333 = 0; v333 < 1; v333 += 1) {	// L586
    for (int v334 = 0; v334 < 256; v334 += 1) {	// L587
      for (int v335 = 0; v335 < 10; v335 += 1) {	// L588
        for (int v336 = 0; v336 < 10; v336 += 1) {	// L589
          v332[v333][v334][v335][v336] = (int8_t)0.000000;	// L590
        }
      }
    }
  }
  for (int v337 = 0; v337 < 1; v337 += 1) {	// L595
    for (int v338 = 0; v338 < 256; v338 += 1) {	// L596
      for (int v339 = 0; v339 < 8; v339 += 1) {	// L597
        for (int v340 = 0; v340 < 8; v340 += 1) {	// L598
          int8_t v341 = v329[v337][v338][v339][v340];	// L599
          v332[v337][v338][(v339 + 1)][(v340 + 1)] = v341;	// L600
        }
      }
    }
  }
  int8_t v342[1][256][8][8];	// L605
  // #pragma HLS stream variable=v342 depth=10 type=fifo

  #pragma HLS bind_storage variable=v342 type=ram_t2p impl=bram

  for (int v343 = 0; v343 < 1; v343 += 1) {	// L606
    for (int v344 = 0; v344 < 256; v344 += 1) {	// L607
      for (int v345 = 0; v345 < 8; v345 += 1) {	// L608
        for (int v346 = 0; v346 < 8; v346 += 1) {	// L609
          v342[v343][v344][v345][v346] = (int8_t)0.000000;	// L610
        }
      }
    }
  }
  for (int v347 = 0; v347 < 1; v347 += 1) {	// L615
    for (int v348 = 0; v348 < 256; v348 += 1) {	// L616
      for (int v349 = 0; v349 < 8; v349 += 1) {	// L617
        for (int v350 = 0; v350 < 8; v350 += 1) {	// L618
          for (int v351 = 0; v351 < 256; v351 += 1) {	// L619
            for (int v352 = 0; v352 < 3; v352 += 1) {	// L620
              for (int v353 = 0; v353 < 3; v353 += 1) {	// L621
                int8_t v354 = v332[v347][v351][(v349 + v352)][(v350 + v353)];	// L622
                int8_t v355 = v330[v348][v351][v352][v353];	// L623
                int8_t v356 = v342[v347][v348][v349][v350];	// L624
                int8_t v357 = v354 * v355;	// L625
                int8_t v358 = v356 + v357;	// L626
                v342[v347][v348][v349][v350] = v358;	// L627
              }
            }
          }
        }
      }
    }
  }
  for (int v359 = 0; v359 < 1; v359 += 1) {	// L635
    for (int v360 = 0; v360 < 256; v360 += 1) {	// L636
      for (int v361 = 0; v361 < 8; v361 += 1) {	// L637
        for (int v362 = 0; v362 < 8; v362 += 1) {	// L638
          int8_t v363 = v342[0][v360][v361][v362];	// L639
          bool v364 = v363 > (int8_t)0.000000;	// L640
          int8_t v365 = v364 ? v363 : (int8_t)0.000000;	// L641
          v331[v359][v360][v361][v362] = v365;	// L642
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v366[256][128][3][3],
  int8_t v367[1][128][8][8],
  int8_t v368[1][256][8][8]
) {	// L649
  // #pragma HLS dataflow

  int8_t v369[1][128][10][10];	// L651
  // #pragma HLS stream variable=v369 depth=10 type=fifo

  #pragma HLS bind_storage variable=v369 type=ram_t2p impl=bram

  for (int v370 = 0; v370 < 1; v370 += 1) {	// L652
    for (int v371 = 0; v371 < 128; v371 += 1) {	// L653
      for (int v372 = 0; v372 < 10; v372 += 1) {	// L654
        for (int v373 = 0; v373 < 10; v373 += 1) {	// L655
          v369[v370][v371][v372][v373] = (int8_t)0.000000;	// L656
        }
      }
    }
  }
  for (int v374 = 0; v374 < 1; v374 += 1) {	// L661
    for (int v375 = 0; v375 < 128; v375 += 1) {	// L662
      for (int v376 = 0; v376 < 8; v376 += 1) {	// L663
        for (int v377 = 0; v377 < 8; v377 += 1) {	// L664
          int8_t v378 = v367[v374][v375][v376][v377];	// L665
          v369[v374][v375][(v376 + 1)][(v377 + 1)] = v378;	// L666
        }
      }
    }
  }
  int8_t v379[1][256][8][8];	// L671
  // #pragma HLS stream variable=v379 depth=10 type=fifo

  #pragma HLS bind_storage variable=v379 type=ram_t2p impl=bram

  for (int v380 = 0; v380 < 1; v380 += 1) {	// L672
    for (int v381 = 0; v381 < 256; v381 += 1) {	// L673
      for (int v382 = 0; v382 < 8; v382 += 1) {	// L674
        for (int v383 = 0; v383 < 8; v383 += 1) {	// L675
          v379[v380][v381][v382][v383] = (int8_t)0.000000;	// L676
        }
      }
    }
  }
  for (int v384 = 0; v384 < 1; v384 += 1) {	// L681
    for (int v385 = 0; v385 < 256; v385 += 1) {	// L682
      for (int v386 = 0; v386 < 8; v386 += 1) {	// L683
        for (int v387 = 0; v387 < 8; v387 += 1) {	// L684
          for (int v388 = 0; v388 < 128; v388 += 1) {	// L685
            for (int v389 = 0; v389 < 3; v389 += 1) {	// L686
              for (int v390 = 0; v390 < 3; v390 += 1) {	// L687
                int8_t v391 = v369[v384][v388][(v386 + v389)][(v387 + v390)];	// L688
                int8_t v392 = v366[v385][v388][v389][v390];	// L689
                int8_t v393 = v379[v384][v385][v386][v387];	// L690
                int8_t v394 = v391 * v392;	// L691
                int8_t v395 = v393 + v394;	// L692
                v379[v384][v385][v386][v387] = v395;	// L693
              }
            }
          }
        }
      }
    }
  }
  for (int v396 = 0; v396 < 1; v396 += 1) {	// L701
    for (int v397 = 0; v397 < 256; v397 += 1) {	// L702
      for (int v398 = 0; v398 < 8; v398 += 1) {	// L703
        for (int v399 = 0; v399 < 8; v399 += 1) {	// L704
          int8_t v400 = v379[0][v397][v398][v399];	// L705
          bool v401 = v400 > (int8_t)0.000000;	// L706
          int8_t v402 = v401 ? v400 : (int8_t)0.000000;	// L707
          v368[v396][v397][v398][v399] = v402;	// L708
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v403[1][128][16][16],
  int8_t v404[128][128][3][3],
  int8_t v405[1][128][8][8]
) {	// L715
  // #pragma HLS dataflow

  int8_t v406[1][128][18][18];	// L717
  // #pragma HLS stream variable=v406 depth=10 type=fifo

  #pragma HLS bind_storage variable=v406 type=ram_t2p impl=bram

  for (int v407 = 0; v407 < 1; v407 += 1) {	// L718
    for (int v408 = 0; v408 < 128; v408 += 1) {	// L719
      for (int v409 = 0; v409 < 18; v409 += 1) {	// L720
        for (int v410 = 0; v410 < 18; v410 += 1) {	// L721
          v406[v407][v408][v409][v410] = (int8_t)0.000000;	// L722
        }
      }
    }
  }
  for (int v411 = 0; v411 < 1; v411 += 1) {	// L727
    for (int v412 = 0; v412 < 128; v412 += 1) {	// L728
      for (int v413 = 0; v413 < 16; v413 += 1) {	// L729
        for (int v414 = 0; v414 < 16; v414 += 1) {	// L730
          int8_t v415 = v403[v411][v412][v413][v414];	// L731
          v406[v411][v412][(v413 + 1)][(v414 + 1)] = v415;	// L732
        }
      }
    }
  }
  int8_t v416[1][128][8][8];	// L737
  // #pragma HLS stream variable=v416 depth=10 type=fifo

  #pragma HLS bind_storage variable=v416 type=ram_t2p impl=bram

  for (int v417 = 0; v417 < 1; v417 += 1) {	// L738
    for (int v418 = 0; v418 < 128; v418 += 1) {	// L739
      for (int v419 = 0; v419 < 8; v419 += 1) {	// L740
        for (int v420 = 0; v420 < 8; v420 += 1) {	// L741
          v416[v417][v418][v419][v420] = (int8_t)0.000000;	// L742
        }
      }
    }
  }
  for (int v421 = 0; v421 < 1; v421 += 1) {	// L747
    for (int v422 = 0; v422 < 128; v422 += 1) {	// L748
      for (int v423 = 0; v423 < 8; v423 += 1) {	// L749
        for (int v424 = 0; v424 < 8; v424 += 1) {	// L750
          for (int v425 = 0; v425 < 128; v425 += 1) {	// L751
            for (int v426 = 0; v426 < 3; v426 += 1) {	// L752
              for (int v427 = 0; v427 < 3; v427 += 1) {	// L753
                int8_t v428 = v406[v421][v425][((v423 * 2) + v426)][((v424 * 2) + v427)];	// L754
                int8_t v429 = v404[v422][v425][v426][v427];	// L755
                int8_t v430 = v416[v421][v422][v423][v424];	// L756
                int8_t v431 = v428 * v429;	// L757
                int8_t v432 = v430 + v431;	// L758
                v416[v421][v422][v423][v424] = v432;	// L759
              }
            }
          }
        }
      }
    }
  }
  for (int v433 = 0; v433 < 1; v433 += 1) {	// L767
    for (int v434 = 0; v434 < 128; v434 += 1) {	// L768
      for (int v435 = 0; v435 < 8; v435 += 1) {	// L769
        for (int v436 = 0; v436 < 8; v436 += 1) {	// L770
          int8_t v437 = v416[0][v434][v435][v436];	// L771
          bool v438 = v437 > (int8_t)0.000000;	// L772
          int8_t v439 = v438 ? v437 : (int8_t)0.000000;	// L773
          v405[v433][v434][v435][v436] = v439;	// L774
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v440[1][64][16][16],
  int8_t v441[128][64][3][3],
  int8_t v442[1][128][16][16]
) {	// L781
  // #pragma HLS dataflow

  int8_t v443[1][64][18][18];	// L783
  // #pragma HLS stream variable=v443 depth=10 type=fifo

  #pragma HLS bind_storage variable=v443 type=ram_t2p impl=bram

  for (int v444 = 0; v444 < 1; v444 += 1) {	// L784
    for (int v445 = 0; v445 < 64; v445 += 1) {	// L785
      for (int v446 = 0; v446 < 18; v446 += 1) {	// L786
        for (int v447 = 0; v447 < 18; v447 += 1) {	// L787
          v443[v444][v445][v446][v447] = (int8_t)0.000000;	// L788
        }
      }
    }
  }
  for (int v448 = 0; v448 < 1; v448 += 1) {	// L793
    for (int v449 = 0; v449 < 64; v449 += 1) {	// L794
      for (int v450 = 0; v450 < 16; v450 += 1) {	// L795
        for (int v451 = 0; v451 < 16; v451 += 1) {	// L796
          int8_t v452 = v440[v448][v449][v450][v451];	// L797
          v443[v448][v449][(v450 + 1)][(v451 + 1)] = v452;	// L798
        }
      }
    }
  }
  int8_t v453[1][128][16][16];	// L803
  // #pragma HLS stream variable=v453 depth=10 type=fifo

  #pragma HLS bind_storage variable=v453 type=ram_t2p impl=bram

  for (int v454 = 0; v454 < 1; v454 += 1) {	// L804
    for (int v455 = 0; v455 < 128; v455 += 1) {	// L805
      for (int v456 = 0; v456 < 16; v456 += 1) {	// L806
        for (int v457 = 0; v457 < 16; v457 += 1) {	// L807
          v453[v454][v455][v456][v457] = (int8_t)0.000000;	// L808
        }
      }
    }
  }
  for (int v458 = 0; v458 < 1; v458 += 1) {	// L813
    for (int v459 = 0; v459 < 128; v459 += 1) {	// L814
      for (int v460 = 0; v460 < 16; v460 += 1) {	// L815
        for (int v461 = 0; v461 < 16; v461 += 1) {	// L816
          for (int v462 = 0; v462 < 64; v462 += 1) {	// L817
            for (int v463 = 0; v463 < 3; v463 += 1) {	// L818
              for (int v464 = 0; v464 < 3; v464 += 1) {	// L819
                int8_t v465 = v443[v458][v462][(v460 + v463)][(v461 + v464)];	// L820
                int8_t v466 = v441[v459][v462][v463][v464];	// L821
                int8_t v467 = v453[v458][v459][v460][v461];	// L822
                int8_t v468 = v465 * v466;	// L823
                int8_t v469 = v467 + v468;	// L824
                v453[v458][v459][v460][v461] = v469;	// L825
              }
            }
          }
        }
      }
    }
  }
  for (int v470 = 0; v470 < 1; v470 += 1) {	// L833
    for (int v471 = 0; v471 < 128; v471 += 1) {	// L834
      for (int v472 = 0; v472 < 16; v472 += 1) {	// L835
        for (int v473 = 0; v473 < 16; v473 += 1) {	// L836
          int8_t v474 = v453[0][v471][v472][v473];	// L837
          bool v475 = v474 > (int8_t)0.000000;	// L838
          int8_t v476 = v475 ? v474 : (int8_t)0.000000;	// L839
          v442[v470][v471][v472][v473] = v476;	// L840
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v477[64][64][3][3],
  int8_t v478[1][64][32][32],
  int8_t v479[1][64][16][16]
) {	// L847
  // #pragma HLS dataflow

  int8_t v480[1][64][34][34];	// L849
  // #pragma HLS stream variable=v480 depth=10 type=fifo

  #pragma HLS bind_storage variable=v480 type=ram_t2p impl=bram

  for (int v481 = 0; v481 < 1; v481 += 1) {	// L850
    for (int v482 = 0; v482 < 64; v482 += 1) {	// L851
      for (int v483 = 0; v483 < 34; v483 += 1) {	// L852
        for (int v484 = 0; v484 < 34; v484 += 1) {	// L853
          v480[v481][v482][v483][v484] = (int8_t)0.000000;	// L854
        }
      }
    }
  }
  for (int v485 = 0; v485 < 1; v485 += 1) {	// L859
    for (int v486 = 0; v486 < 64; v486 += 1) {	// L860
      for (int v487 = 0; v487 < 32; v487 += 1) {	// L861
        for (int v488 = 0; v488 < 32; v488 += 1) {	// L862
          int8_t v489 = v478[v485][v486][v487][v488];	// L863
          v480[v485][v486][(v487 + 1)][(v488 + 1)] = v489;	// L864
        }
      }
    }
  }
  int8_t v490[1][64][16][16];	// L869
  // #pragma HLS stream variable=v490 depth=10 type=fifo

  #pragma HLS bind_storage variable=v490 type=ram_t2p impl=bram

  for (int v491 = 0; v491 < 1; v491 += 1) {	// L870
    for (int v492 = 0; v492 < 64; v492 += 1) {	// L871
      for (int v493 = 0; v493 < 16; v493 += 1) {	// L872
        for (int v494 = 0; v494 < 16; v494 += 1) {	// L873
          v490[v491][v492][v493][v494] = (int8_t)0.000000;	// L874
        }
      }
    }
  }
  for (int v495 = 0; v495 < 1; v495 += 1) {	// L879
    for (int v496 = 0; v496 < 64; v496 += 1) {	// L880
      for (int v497 = 0; v497 < 16; v497 += 1) {	// L881
        for (int v498 = 0; v498 < 16; v498 += 1) {	// L882
          for (int v499 = 0; v499 < 64; v499 += 1) {	// L883
            for (int v500 = 0; v500 < 3; v500 += 1) {	// L884
              for (int v501 = 0; v501 < 3; v501 += 1) {	// L885
                int8_t v502 = v480[v495][v499][((v497 * 2) + v500)][((v498 * 2) + v501)];	// L886
                int8_t v503 = v477[v496][v499][v500][v501];	// L887
                int8_t v504 = v490[v495][v496][v497][v498];	// L888
                int8_t v505 = v502 * v503;	// L889
                int8_t v506 = v504 + v505;	// L890
                v490[v495][v496][v497][v498] = v506;	// L891
              }
            }
          }
        }
      }
    }
  }
  for (int v507 = 0; v507 < 1; v507 += 1) {	// L899
    for (int v508 = 0; v508 < 64; v508 += 1) {	// L900
      for (int v509 = 0; v509 < 16; v509 += 1) {	// L901
        for (int v510 = 0; v510 < 16; v510 += 1) {	// L902
          int8_t v511 = v490[0][v508][v509][v510];	// L903
          bool v512 = v511 > (int8_t)0.000000;	// L904
          int8_t v513 = v512 ? v511 : (int8_t)0.000000;	// L905
          v479[v507][v508][v509][v510] = v513;	// L906
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v514[1][3][32][32],
  int8_t v515[64][3][3][3],
  int8_t v516[1][64][32][32]
) {	// L913
  // #pragma HLS dataflow

  int8_t v517[1][3][34][34];	// L915
  // #pragma HLS stream variable=v517 depth=10 type=fifo

  #pragma HLS bind_storage variable=v517 type=ram_t2p impl=bram

  for (int v518 = 0; v518 < 1; v518 += 1) {	// L916
    for (int v519 = 0; v519 < 3; v519 += 1) {	// L917
      for (int v520 = 0; v520 < 34; v520 += 1) {	// L918
        for (int v521 = 0; v521 < 34; v521 += 1) {	// L919
          v517[v518][v519][v520][v521] = (int8_t)0.000000;	// L920
        }
      }
    }
  }
  for (int v522 = 0; v522 < 1; v522 += 1) {	// L925
    for (int v523 = 0; v523 < 3; v523 += 1) {	// L926
      for (int v524 = 0; v524 < 32; v524 += 1) {	// L927
        for (int v525 = 0; v525 < 32; v525 += 1) {	// L928
          int8_t v526 = v514[v522][v523][v524][v525];	// L929
          v517[v522][v523][(v524 + 1)][(v525 + 1)] = v526;	// L930
        }
      }
    }
  }
  int8_t v527[1][64][32][32];	// L935
  // #pragma HLS stream variable=v527 depth=10 type=fifo

  #pragma HLS bind_storage variable=v527 type=ram_t2p impl=bram

  for (int v528 = 0; v528 < 1; v528 += 1) {	// L936
    for (int v529 = 0; v529 < 64; v529 += 1) {	// L937
      for (int v530 = 0; v530 < 32; v530 += 1) {	// L938
        for (int v531 = 0; v531 < 32; v531 += 1) {	// L939
          v527[v528][v529][v530][v531] = (int8_t)0.000000;	// L940
        }
      }
    }
  }
  for (int v532 = 0; v532 < 1; v532 += 1) {	// L945
    for (int v533 = 0; v533 < 64; v533 += 1) {	// L946
      for (int v534 = 0; v534 < 32; v534 += 1) {	// L947
        for (int v535 = 0; v535 < 32; v535 += 1) {	// L948
          for (int v536 = 0; v536 < 3; v536 += 1) {	// L949
            for (int v537 = 0; v537 < 3; v537 += 1) {	// L950
              for (int v538 = 0; v538 < 3; v538 += 1) {	// L951
                int8_t v539 = v517[v532][v536][(v534 + v537)][(v535 + v538)];	// L952
                int8_t v540 = v515[v533][v536][v537][v538];	// L953
                int8_t v541 = v527[v532][v533][v534][v535];	// L954
                int8_t v542 = v539 * v540;	// L955
                int8_t v543 = v541 + v542;	// L956
                v527[v532][v533][v534][v535] = v543;	// L957
              }
            }
          }
        }
      }
    }
  }
  for (int v544 = 0; v544 < 1; v544 += 1) {	// L965
    for (int v545 = 0; v545 < 64; v545 += 1) {	// L966
      for (int v546 = 0; v546 < 32; v546 += 1) {	// L967
        for (int v547 = 0; v547 < 32; v547 += 1) {	// L968
          int8_t v548 = v527[0][v545][v546][v547];	// L969
          bool v549 = v548 > (int8_t)0.000000;	// L970
          int8_t v550 = v549 ? v548 : (int8_t)0.000000;	// L971
          v516[v544][v545][v546][v547] = v550;	// L972
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v551[1][3][32][32],
  int8_t v552[10],
  int8_t v553[512][512][3][3],
  int8_t v554[512][512][3][3],
  int8_t v555[512][512][3][3],
  int8_t v556[512][512][3][3],
  int8_t v557[512][512][3][3],
  int8_t v558[512][256][3][3],
  int8_t v559[256][256][3][3],
  int8_t v560[256][256][3][3],
  int8_t v561[256][128][3][3],
  int8_t v562[128][128][3][3],
  int8_t v563[128][64][3][3],
  int8_t v564[64][64][3][3],
  int8_t v565[64][3][3][3],
  int8_t v566[512][10],
  int8_t v567[1][10]
) {	// L979
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v551
  #pragma HLS bind_storage variable=v551 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v552
  #pragma HLS bind_storage variable=v552 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v553
  #pragma HLS bind_storage variable=v553 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v554
  #pragma HLS bind_storage variable=v554 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v555
  #pragma HLS bind_storage variable=v555 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v556
  #pragma HLS bind_storage variable=v556 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v557
  #pragma HLS bind_storage variable=v557 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v558
  #pragma HLS bind_storage variable=v558 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v559
  #pragma HLS bind_storage variable=v559 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v560
  #pragma HLS bind_storage variable=v560 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v561
  #pragma HLS bind_storage variable=v561 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v562
  #pragma HLS bind_storage variable=v562 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v563
  #pragma HLS bind_storage variable=v563 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v564
  #pragma HLS bind_storage variable=v564 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v565
  #pragma HLS bind_storage variable=v565 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v566
  #pragma HLS bind_storage variable=v566 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v567
  #pragma HLS bind_storage variable=v567 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  int8_t v568[1][64][32][32];	// L981
  // #pragma HLS stream variable=v568 depth=10 type=fifo

  #pragma HLS bind_storage variable=v568 type=ram_t2p impl=bram

  main_graph_node16(v551, v565, v568);	// L982  PCR
  int8_t v569[1][64][16][16];	// L983
  // #pragma HLS stream variable=v569 depth=10 type=fifo

  #pragma HLS bind_storage variable=v569 type=ram_t2p impl=bram

  main_graph_node15(v564, v568, v569);	// L984   PCR
  int8_t v570[1][128][16][16];	// L985
  // #pragma HLS stream variable=v570 depth=10 type=fifo

  #pragma HLS bind_storage variable=v570 type=ram_t2p impl=bram

  main_graph_node14(v569, v563, v570);	// L986     PCR
  int8_t v571[1][128][8][8];	// L987
  // #pragma HLS stream variable=v571 depth=10 type=fifo

  #pragma HLS bind_storage variable=v571 type=ram_t2p impl=bram

  main_graph_node13(v570, v562, v571);	// L988       PCR
  int8_t v572[1][256][8][8];	// L989
  // #pragma HLS stream variable=v572 depth=10 type=fifo

  #pragma HLS bind_storage variable=v572 type=ram_t2p impl=bram

  main_graph_node12(v561, v571, v572);	// L990     PCR
  int8_t v573[1][256][8][8];	// L991
  // #pragma HLS stream variable=v573 depth=10 type=fifo

  #pragma HLS bind_storage variable=v573 type=ram_t2p impl=bram

  main_graph_node11(v572, v560, v573);	// L992     PCR
  int8_t v574[1][256][4][4];	// L993
  // #pragma HLS stream variable=v574 depth=10 type=fifo

  #pragma HLS bind_storage variable=v574 type=ram_t2p impl=bram

  main_graph_node10(v573, v559, v574);	// L994
  int8_t v575[1][512][4][4];	// L995
  // #pragma HLS stream variable=v575 depth=10 type=fifo

  #pragma HLS bind_storage variable=v575 type=ram_t2p impl=bram

  main_graph_node9(v574, v558, v575);	// L996
  int8_t v576[1][512][4][4];	// L997
  // #pragma HLS stream variable=v576 depth=10 type=fifo

  #pragma HLS bind_storage variable=v576 type=ram_t2p impl=bram

  main_graph_node8(v557, v575, v576);	// L998
  int8_t v577[1][512][2][2];	// L999
  // #pragma HLS stream variable=v577 depth=10 type=fifo

  #pragma HLS bind_storage variable=v577 type=ram_t2p impl=bram

  main_graph_node7(v576, v556, v577);	// L1000
  int8_t v578[1][512][2][2];	// L1001
  // #pragma HLS stream variable=v578 depth=10 type=fifo

  #pragma HLS bind_storage variable=v578 type=ram_t2p impl=bram

  main_graph_node6(v577, v555, v578);	// L1002
  int8_t v579[1][512][2][2];	// L1003
  // #pragma HLS stream variable=v579 depth=10 type=fifo

  #pragma HLS bind_storage variable=v579 type=ram_t2p impl=bram

  main_graph_node5(v578, v554, v579);	// L1004
  int8_t v580[1][512][1][1];	// L1005
  // #pragma HLS stream variable=v580 depth=10 type=fifo

  #pragma HLS bind_storage variable=v580 type=ram_t2p impl=bram

  main_graph_node4(v553, v579, v580);	// L1006
  int8_t v581[1][512][2][2];	// L1007
  // #pragma HLS stream variable=v581 depth=10 type=fifo

  #pragma HLS bind_storage variable=v581 type=ram_t2p impl=bram

  main_graph_node3(v580, v581);	// L1008
  int8_t v582[1][1];	// L1009
  // #pragma HLS stream variable=v582 depth=10 type=fifo

  #pragma HLS bind_storage variable=v582 type=ram_t2p impl=bram

  int8_t v583[1][512][1][1];	// L1010
  // #pragma HLS stream variable=v583 depth=10 type=fifo

  #pragma HLS bind_storage variable=v583 type=ram_t2p impl=bram

  main_graph_node2(v581, v582, v583);	// L1011
  int8_t v584[1][512][1][1];	// L1012
  // #pragma HLS stream variable=v584 depth=10 type=fifo

  #pragma HLS bind_storage variable=v584 type=ram_t2p impl=bram

  main_graph_node1(v583, v582, v584);	// L1013
  main_graph_node0(v552, v566, v584, v567);	// L1014
}

