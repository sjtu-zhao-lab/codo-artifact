
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
  int8_t v0[1][1024][1][1],
  int8_t v1[1024][1000],
  int8_t v2[1000],
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
        int8_t v10 = v0[v7][v9][0][0];	// L14
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
      int8_t v18 = v2[v16];	// L26
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
  int8_t v35[1][1024][2][2],
  int8_t v36[1][1],
  int8_t v37[1][1024][1][1]
) {	// L58
  // #pragma HLS dataflow

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L62
    for (int v39 = 0; v39 < 1024; v39 += 1) {	// L63
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L64
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L65
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L66
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L71
    for (int v43 = 0; v43 < 1024; v43 += 1) {	// L72
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
  int8_t v59[1][1024][1][1],
  int8_t v60[1][1024][2][2]
) {	// L98
  // #pragma HLS dataflow

  for (int v61 = 0; v61 < 1; v61 += 1) {	// L100
    for (int v62 = 0; v62 < 1024; v62 += 1) {	// L101
      for (int v63 = 0; v63 < 2; v63 += 1) {	// L102
        for (int v64 = 0; v64 < 2; v64 += 1) {	// L103
          v60[v61][v62][v63][v64] = (int8_t)0.000000;	// L104
        }
      }
    }
  }
  for (int v65 = 0; v65 < 1; v65 += 1) {	// L109
    for (int v66 = 0; v66 < 1024; v66 += 1) {	// L110
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
  int8_t v70[1024][1024][1][1],
  int8_t v71[1][1024][1][1],
  int8_t v72[1][1024][1][1]
) {	// L121
  // #pragma HLS dataflow

  int8_t v73[1][1024][1][1];	// L123
  // #pragma HLS stream variable=v73 depth=10 type=fifo

  #pragma HLS bind_storage variable=v73 type=ram_t2p impl=bram

  for (int v74 = 0; v74 < 1; v74 += 1) {	// L124
    for (int v75 = 0; v75 < 1024; v75 += 1) {	// L125
      for (int v76 = 0; v76 < 1; v76 += 1) {	// L126
        for (int v77 = 0; v77 < 1; v77 += 1) {	// L127
          v73[v74][v75][v76][v77] = (int8_t)0.000000;	// L128
        }
      }
    }
  }
  for (int v78 = 0; v78 < 1; v78 += 1) {	// L133
    for (int v79 = 0; v79 < 1024; v79 += 1) {	// L134
      for (int v80 = 0; v80 < 1; v80 += 1) {	// L135
        for (int v81 = 0; v81 < 1; v81 += 1) {	// L136
          for (int v82 = 0; v82 < 1024; v82 += 1) {	// L137
            for (int v83 = 0; v83 < 1; v83 += 1) {	// L138
              for (int v84 = 0; v84 < 1; v84 += 1) {	// L139
                int8_t v85 = v71[v78][v82][(v80 + v83)][(v81 + v84)];	// L140
                int8_t v86 = v70[v79][v82][v83][v84];	// L141
                int8_t v87 = v73[v78][v79][v80][v81];	// L142
                int8_t v88 = v85 * v86;	// L143
                int8_t v89 = v87 + v88;	// L144
                v73[v78][v79][v80][v81] = v89;	// L145
              }
            }
          }
        }
      }
    }
  }
  for (int v90 = 0; v90 < 1; v90 += 1) {	// L153
    for (int v91 = 0; v91 < 1024; v91 += 1) {	// L154
      for (int v92 = 0; v92 < 1; v92 += 1) {	// L155
        for (int v93 = 0; v93 < 1; v93 += 1) {	// L156
          int8_t v94 = v73[0][v91][0][0];	// L157
          bool v95 = v94 > (int8_t)0.000000;	// L158
          int8_t v96 = v95 ? v94 : (int8_t)0.000000;	// L159
          v72[v90][v91][v92][v93] = v96;	// L160
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v97[1][1024][1][1],
  int8_t v98[1024][3][3],
  int8_t v99[1][1024][1][1]
) {	// L167
  // #pragma HLS dataflow

  int8_t v100[1][1024][3][3];	// L169
  // #pragma HLS stream variable=v100 depth=10 type=fifo

  #pragma HLS bind_storage variable=v100 type=ram_t2p impl=bram

  for (int v101 = 0; v101 < 1; v101 += 1) {	// L170
    for (int v102 = 0; v102 < 1024; v102 += 1) {	// L171
      for (int v103 = 0; v103 < 3; v103 += 1) {	// L172
        for (int v104 = 0; v104 < 3; v104 += 1) {	// L173
          v100[v101][v102][v103][v104] = (int8_t)0.000000;	// L174
        }
      }
    }
  }
  for (int v105 = 0; v105 < 1; v105 += 1) {	// L179
    for (int v106 = 0; v106 < 1024; v106 += 1) {	// L180
      for (int v107 = 0; v107 < 1; v107 += 1) {	// L181
        for (int v108 = 0; v108 < 1; v108 += 1) {	// L182
          int8_t v109 = v97[v105][v106][v107][v108];	// L183
          v100[v105][v106][(v107 + 1)][(v108 + 1)] = v109;	// L184
        }
      }
    }
  }
  int8_t v110[1][1024][1][1];	// L189
  // #pragma HLS stream variable=v110 depth=10 type=fifo

  #pragma HLS bind_storage variable=v110 type=ram_t2p impl=bram

  for (int v111 = 0; v111 < 1; v111 += 1) {	// L190
    for (int v112 = 0; v112 < 1024; v112 += 1) {	// L191
      for (int v113 = 0; v113 < 1; v113 += 1) {	// L192
        for (int v114 = 0; v114 < 1; v114 += 1) {	// L193
          v110[v111][v112][v113][v114] = (int8_t)0.000000;	// L194
        }
      }
    }
  }
  for (int v115 = 0; v115 < 1; v115 += 1) {	// L199
    for (int v116 = 0; v116 < 1; v116 += 1) {	// L200
      for (int v117 = 0; v117 < 1; v117 += 1) {	// L201
        for (int v118 = 0; v118 < 1024; v118 += 1) {	// L202
          for (int v119 = 0; v119 < 3; v119 += 1) {	// L203
            for (int v120 = 0; v120 < 3; v120 += 1) {	// L204
              int8_t v121 = v100[v115][v118][(v116 + v119)][(v117 + v120)];	// L205
              int8_t v122 = v98[v118][v119][v120];	// L206
              int8_t v123 = v110[v115][v118][v116][v117];	// L207
              int8_t v124 = v121 * v122;	// L208
              int8_t v125 = v123 + v124;	// L209
              v110[v115][v118][v116][v117] = v125;	// L210
            }
          }
        }
      }
    }
  }
  for (int v126 = 0; v126 < 1; v126 += 1) {	// L217
    for (int v127 = 0; v127 < 1024; v127 += 1) {	// L218
      for (int v128 = 0; v128 < 1; v128 += 1) {	// L219
        for (int v129 = 0; v129 < 1; v129 += 1) {	// L220
          int8_t v130 = v110[0][v127][0][0];	// L221
          bool v131 = v130 > (int8_t)0.000000;	// L222
          int8_t v132 = v131 ? v130 : (int8_t)0.000000;	// L223
          v99[v126][v127][v128][v129] = v132;	// L224
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v133[1][512][1][1],
  int8_t v134[1024][512][1][1],
  int8_t v135[1][1024][1][1]
) {	// L231
  // #pragma HLS dataflow

  int8_t v136[1][1024][1][1];	// L233
  // #pragma HLS stream variable=v136 depth=10 type=fifo

  #pragma HLS bind_storage variable=v136 type=ram_t2p impl=bram

  for (int v137 = 0; v137 < 1; v137 += 1) {	// L234
    for (int v138 = 0; v138 < 1024; v138 += 1) {	// L235
      for (int v139 = 0; v139 < 1; v139 += 1) {	// L236
        for (int v140 = 0; v140 < 1; v140 += 1) {	// L237
          v136[v137][v138][v139][v140] = (int8_t)0.000000;	// L238
        }
      }
    }
  }
  for (int v141 = 0; v141 < 1; v141 += 1) {	// L243
    for (int v142 = 0; v142 < 1024; v142 += 1) {	// L244
      for (int v143 = 0; v143 < 1; v143 += 1) {	// L245
        for (int v144 = 0; v144 < 1; v144 += 1) {	// L246
          for (int v145 = 0; v145 < 512; v145 += 1) {	// L247
            for (int v146 = 0; v146 < 1; v146 += 1) {	// L248
              for (int v147 = 0; v147 < 1; v147 += 1) {	// L249
                int8_t v148 = v133[v141][v145][(v143 + v146)][(v144 + v147)];	// L250
                int8_t v149 = v134[v142][v145][v146][v147];	// L251
                int8_t v150 = v136[v141][v142][v143][v144];	// L252
                int8_t v151 = v148 * v149;	// L253
                int8_t v152 = v150 + v151;	// L254
                v136[v141][v142][v143][v144] = v152;	// L255
              }
            }
          }
        }
      }
    }
  }
  for (int v153 = 0; v153 < 1; v153 += 1) {	// L263
    for (int v154 = 0; v154 < 1024; v154 += 1) {	// L264
      for (int v155 = 0; v155 < 1; v155 += 1) {	// L265
        for (int v156 = 0; v156 < 1; v156 += 1) {	// L266
          int8_t v157 = v136[0][v154][0][0];	// L267
          bool v158 = v157 > (int8_t)0.000000;	// L268
          int8_t v159 = v158 ? v157 : (int8_t)0.000000;	// L269
          v135[v153][v154][v155][v156] = v159;	// L270
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v160[1][512][2][2],
  int8_t v161[512][3][3],
  int8_t v162[1][512][1][1]
) {	// L277
  // #pragma HLS dataflow

  int8_t v163[1][512][4][4];	// L279
  // #pragma HLS stream variable=v163 depth=10 type=fifo

  #pragma HLS bind_storage variable=v163 type=ram_t2p impl=bram

  for (int v164 = 0; v164 < 1; v164 += 1) {	// L280
    for (int v165 = 0; v165 < 512; v165 += 1) {	// L281
      for (int v166 = 0; v166 < 4; v166 += 1) {	// L282
        for (int v167 = 0; v167 < 4; v167 += 1) {	// L283
          v163[v164][v165][v166][v167] = (int8_t)0.000000;	// L284
        }
      }
    }
  }
  for (int v168 = 0; v168 < 1; v168 += 1) {	// L289
    for (int v169 = 0; v169 < 512; v169 += 1) {	// L290
      for (int v170 = 0; v170 < 2; v170 += 1) {	// L291
        for (int v171 = 0; v171 < 2; v171 += 1) {	// L292
          int8_t v172 = v160[v168][v169][v170][v171];	// L293
          v163[v168][v169][(v170 + 1)][(v171 + 1)] = v172;	// L294
        }
      }
    }
  }
  int8_t v173[1][512][1][1];	// L299
  // #pragma HLS stream variable=v173 depth=10 type=fifo

  #pragma HLS bind_storage variable=v173 type=ram_t2p impl=bram

  for (int v174 = 0; v174 < 1; v174 += 1) {	// L300
    for (int v175 = 0; v175 < 512; v175 += 1) {	// L301
      for (int v176 = 0; v176 < 1; v176 += 1) {	// L302
        for (int v177 = 0; v177 < 1; v177 += 1) {	// L303
          v173[v174][v175][v176][v177] = (int8_t)0.000000;	// L304
        }
      }
    }
  }
  for (int v178 = 0; v178 < 1; v178 += 1) {	// L309
    for (int v179 = 0; v179 < 1; v179 += 1) {	// L310
      for (int v180 = 0; v180 < 1; v180 += 1) {	// L311
        for (int v181 = 0; v181 < 512; v181 += 1) {	// L312
          for (int v182 = 0; v182 < 3; v182 += 1) {	// L313
            for (int v183 = 0; v183 < 3; v183 += 1) {	// L314
              int8_t v184 = v163[v178][v181][((v179 * 2) + v182)][((v180 * 2) + v183)];	// L315
              int8_t v185 = v161[v181][v182][v183];	// L316
              int8_t v186 = v173[v178][v181][v179][v180];	// L317
              int8_t v187 = v184 * v185;	// L318
              int8_t v188 = v186 + v187;	// L319
              v173[v178][v181][v179][v180] = v188;	// L320
            }
          }
        }
      }
    }
  }
  for (int v189 = 0; v189 < 1; v189 += 1) {	// L327
    for (int v190 = 0; v190 < 512; v190 += 1) {	// L328
      for (int v191 = 0; v191 < 1; v191 += 1) {	// L329
        for (int v192 = 0; v192 < 1; v192 += 1) {	// L330
          int8_t v193 = v173[0][v190][0][0];	// L331
          bool v194 = v193 > (int8_t)0.000000;	// L332
          int8_t v195 = v194 ? v193 : (int8_t)0.000000;	// L333
          v162[v189][v190][v191][v192] = v195;	// L334
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v196[512][512][1][1],
  int8_t v197[1][512][2][2],
  int8_t v198[1][512][2][2]
) {	// L341
  // #pragma HLS dataflow

  int8_t v199[1][512][2][2];	// L343
  // #pragma HLS stream variable=v199 depth=10 type=fifo

  #pragma HLS bind_storage variable=v199 type=ram_t2p impl=bram

  for (int v200 = 0; v200 < 1; v200 += 1) {	// L344
    for (int v201 = 0; v201 < 512; v201 += 1) {	// L345
      for (int v202 = 0; v202 < 2; v202 += 1) {	// L346
        for (int v203 = 0; v203 < 2; v203 += 1) {	// L347
          v199[v200][v201][v202][v203] = (int8_t)0.000000;	// L348
        }
      }
    }
  }
  for (int v204 = 0; v204 < 1; v204 += 1) {	// L353
    for (int v205 = 0; v205 < 512; v205 += 1) {	// L354
      for (int v206 = 0; v206 < 2; v206 += 1) {	// L355
        for (int v207 = 0; v207 < 2; v207 += 1) {	// L356
          for (int v208 = 0; v208 < 512; v208 += 1) {	// L357
            for (int v209 = 0; v209 < 1; v209 += 1) {	// L358
              for (int v210 = 0; v210 < 1; v210 += 1) {	// L359
                int8_t v211 = v197[v204][v208][(v206 + v209)][(v207 + v210)];	// L360
                int8_t v212 = v196[v205][v208][v209][v210];	// L361
                int8_t v213 = v199[v204][v205][v206][v207];	// L362
                int8_t v214 = v211 * v212;	// L363
                int8_t v215 = v213 + v214;	// L364
                v199[v204][v205][v206][v207] = v215;	// L365
              }
            }
          }
        }
      }
    }
  }
  for (int v216 = 0; v216 < 1; v216 += 1) {	// L373
    for (int v217 = 0; v217 < 512; v217 += 1) {	// L374
      for (int v218 = 0; v218 < 2; v218 += 1) {	// L375
        for (int v219 = 0; v219 < 2; v219 += 1) {	// L376
          int8_t v220 = v199[0][v217][v218][v219];	// L377
          bool v221 = v220 > (int8_t)0.000000;	// L378
          int8_t v222 = v221 ? v220 : (int8_t)0.000000;	// L379
          v198[v216][v217][v218][v219] = v222;	// L380
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v223[1][512][2][2],
  int8_t v224[512][3][3],
  int8_t v225[1][512][2][2]
) {	// L387
  // #pragma HLS dataflow

  int8_t v226[1][512][4][4];	// L389
  // #pragma HLS stream variable=v226 depth=10 type=fifo

  #pragma HLS bind_storage variable=v226 type=ram_t2p impl=bram

  for (int v227 = 0; v227 < 1; v227 += 1) {	// L390
    for (int v228 = 0; v228 < 512; v228 += 1) {	// L391
      for (int v229 = 0; v229 < 4; v229 += 1) {	// L392
        for (int v230 = 0; v230 < 4; v230 += 1) {	// L393
          v226[v227][v228][v229][v230] = (int8_t)0.000000;	// L394
        }
      }
    }
  }
  for (int v231 = 0; v231 < 1; v231 += 1) {	// L399
    for (int v232 = 0; v232 < 512; v232 += 1) {	// L400
      for (int v233 = 0; v233 < 2; v233 += 1) {	// L401
        for (int v234 = 0; v234 < 2; v234 += 1) {	// L402
          int8_t v235 = v223[v231][v232][v233][v234];	// L403
          v226[v231][v232][(v233 + 1)][(v234 + 1)] = v235;	// L404
        }
      }
    }
  }
  int8_t v236[1][512][2][2];	// L409
  // #pragma HLS stream variable=v236 depth=10 type=fifo

  #pragma HLS bind_storage variable=v236 type=ram_t2p impl=bram

  for (int v237 = 0; v237 < 1; v237 += 1) {	// L410
    for (int v238 = 0; v238 < 512; v238 += 1) {	// L411
      for (int v239 = 0; v239 < 2; v239 += 1) {	// L412
        for (int v240 = 0; v240 < 2; v240 += 1) {	// L413
          v236[v237][v238][v239][v240] = (int8_t)0.000000;	// L414
        }
      }
    }
  }
  for (int v241 = 0; v241 < 1; v241 += 1) {	// L419
    for (int v242 = 0; v242 < 2; v242 += 1) {	// L420
      for (int v243 = 0; v243 < 2; v243 += 1) {	// L421
        for (int v244 = 0; v244 < 512; v244 += 1) {	// L422
          for (int v245 = 0; v245 < 3; v245 += 1) {	// L423
            for (int v246 = 0; v246 < 3; v246 += 1) {	// L424
              int8_t v247 = v226[v241][v244][(v242 + v245)][(v243 + v246)];	// L425
              int8_t v248 = v224[v244][v245][v246];	// L426
              int8_t v249 = v236[v241][v244][v242][v243];	// L427
              int8_t v250 = v247 * v248;	// L428
              int8_t v251 = v249 + v250;	// L429
              v236[v241][v244][v242][v243] = v251;	// L430
            }
          }
        }
      }
    }
  }
  for (int v252 = 0; v252 < 1; v252 += 1) {	// L437
    for (int v253 = 0; v253 < 512; v253 += 1) {	// L438
      for (int v254 = 0; v254 < 2; v254 += 1) {	// L439
        for (int v255 = 0; v255 < 2; v255 += 1) {	// L440
          int8_t v256 = v236[0][v253][v254][v255];	// L441
          bool v257 = v256 > (int8_t)0.000000;	// L442
          int8_t v258 = v257 ? v256 : (int8_t)0.000000;	// L443
          v225[v252][v253][v254][v255] = v258;	// L444
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v259[1][512][2][2],
  int8_t v260[512][512][1][1],
  int8_t v261[1][512][2][2]
) {	// L451
  // #pragma HLS dataflow

  int8_t v262[1][512][2][2];	// L453
  // #pragma HLS stream variable=v262 depth=10 type=fifo

  #pragma HLS bind_storage variable=v262 type=ram_t2p impl=bram

  for (int v263 = 0; v263 < 1; v263 += 1) {	// L454
    for (int v264 = 0; v264 < 512; v264 += 1) {	// L455
      for (int v265 = 0; v265 < 2; v265 += 1) {	// L456
        for (int v266 = 0; v266 < 2; v266 += 1) {	// L457
          v262[v263][v264][v265][v266] = (int8_t)0.000000;	// L458
        }
      }
    }
  }
  for (int v267 = 0; v267 < 1; v267 += 1) {	// L463
    for (int v268 = 0; v268 < 512; v268 += 1) {	// L464
      for (int v269 = 0; v269 < 2; v269 += 1) {	// L465
        for (int v270 = 0; v270 < 2; v270 += 1) {	// L466
          for (int v271 = 0; v271 < 512; v271 += 1) {	// L467
            for (int v272 = 0; v272 < 1; v272 += 1) {	// L468
              for (int v273 = 0; v273 < 1; v273 += 1) {	// L469
                int8_t v274 = v259[v267][v271][(v269 + v272)][(v270 + v273)];	// L470
                int8_t v275 = v260[v268][v271][v272][v273];	// L471
                int8_t v276 = v262[v267][v268][v269][v270];	// L472
                int8_t v277 = v274 * v275;	// L473
                int8_t v278 = v276 + v277;	// L474
                v262[v267][v268][v269][v270] = v278;	// L475
              }
            }
          }
        }
      }
    }
  }
  for (int v279 = 0; v279 < 1; v279 += 1) {	// L483
    for (int v280 = 0; v280 < 512; v280 += 1) {	// L484
      for (int v281 = 0; v281 < 2; v281 += 1) {	// L485
        for (int v282 = 0; v282 < 2; v282 += 1) {	// L486
          int8_t v283 = v262[0][v280][v281][v282];	// L487
          bool v284 = v283 > (int8_t)0.000000;	// L488
          int8_t v285 = v284 ? v283 : (int8_t)0.000000;	// L489
          v261[v279][v280][v281][v282] = v285;	// L490
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v286[512][3][3],
  int8_t v287[1][512][2][2],
  int8_t v288[1][512][2][2]
) {	// L497
  // #pragma HLS dataflow

  int8_t v289[1][512][4][4];	// L499
  // #pragma HLS stream variable=v289 depth=10 type=fifo

  #pragma HLS bind_storage variable=v289 type=ram_t2p impl=bram

  for (int v290 = 0; v290 < 1; v290 += 1) {	// L500
    for (int v291 = 0; v291 < 512; v291 += 1) {	// L501
      for (int v292 = 0; v292 < 4; v292 += 1) {	// L502
        for (int v293 = 0; v293 < 4; v293 += 1) {	// L503
          v289[v290][v291][v292][v293] = (int8_t)0.000000;	// L504
        }
      }
    }
  }
  for (int v294 = 0; v294 < 1; v294 += 1) {	// L509
    for (int v295 = 0; v295 < 512; v295 += 1) {	// L510
      for (int v296 = 0; v296 < 2; v296 += 1) {	// L511
        for (int v297 = 0; v297 < 2; v297 += 1) {	// L512
          int8_t v298 = v287[v294][v295][v296][v297];	// L513
          v289[v294][v295][(v296 + 1)][(v297 + 1)] = v298;	// L514
        }
      }
    }
  }
  int8_t v299[1][512][2][2];	// L519
  // #pragma HLS stream variable=v299 depth=10 type=fifo

  #pragma HLS bind_storage variable=v299 type=ram_t2p impl=bram

  for (int v300 = 0; v300 < 1; v300 += 1) {	// L520
    for (int v301 = 0; v301 < 512; v301 += 1) {	// L521
      for (int v302 = 0; v302 < 2; v302 += 1) {	// L522
        for (int v303 = 0; v303 < 2; v303 += 1) {	// L523
          v299[v300][v301][v302][v303] = (int8_t)0.000000;	// L524
        }
      }
    }
  }
  for (int v304 = 0; v304 < 1; v304 += 1) {	// L529
    for (int v305 = 0; v305 < 2; v305 += 1) {	// L530
      for (int v306 = 0; v306 < 2; v306 += 1) {	// L531
        for (int v307 = 0; v307 < 512; v307 += 1) {	// L532
          for (int v308 = 0; v308 < 3; v308 += 1) {	// L533
            for (int v309 = 0; v309 < 3; v309 += 1) {	// L534
              int8_t v310 = v289[v304][v307][(v305 + v308)][(v306 + v309)];	// L535
              int8_t v311 = v286[v307][v308][v309];	// L536
              int8_t v312 = v299[v304][v307][v305][v306];	// L537
              int8_t v313 = v310 * v311;	// L538
              int8_t v314 = v312 + v313;	// L539
              v299[v304][v307][v305][v306] = v314;	// L540
            }
          }
        }
      }
    }
  }
  for (int v315 = 0; v315 < 1; v315 += 1) {	// L547
    for (int v316 = 0; v316 < 512; v316 += 1) {	// L548
      for (int v317 = 0; v317 < 2; v317 += 1) {	// L549
        for (int v318 = 0; v318 < 2; v318 += 1) {	// L550
          int8_t v319 = v299[0][v316][v317][v318];	// L551
          bool v320 = v319 > (int8_t)0.000000;	// L552
          int8_t v321 = v320 ? v319 : (int8_t)0.000000;	// L553
          v288[v315][v316][v317][v318] = v321;	// L554
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v322[1][512][2][2],
  int8_t v323[512][512][1][1],
  int8_t v324[1][512][2][2]
) {	// L561
  // #pragma HLS dataflow

  int8_t v325[1][512][2][2];	// L563
  // #pragma HLS stream variable=v325 depth=10 type=fifo

  #pragma HLS bind_storage variable=v325 type=ram_t2p impl=bram

  for (int v326 = 0; v326 < 1; v326 += 1) {	// L564
    for (int v327 = 0; v327 < 512; v327 += 1) {	// L565
      for (int v328 = 0; v328 < 2; v328 += 1) {	// L566
        for (int v329 = 0; v329 < 2; v329 += 1) {	// L567
          v325[v326][v327][v328][v329] = (int8_t)0.000000;	// L568
        }
      }
    }
  }
  for (int v330 = 0; v330 < 1; v330 += 1) {	// L573
    for (int v331 = 0; v331 < 512; v331 += 1) {	// L574
      for (int v332 = 0; v332 < 2; v332 += 1) {	// L575
        for (int v333 = 0; v333 < 2; v333 += 1) {	// L576
          for (int v334 = 0; v334 < 512; v334 += 1) {	// L577
            for (int v335 = 0; v335 < 1; v335 += 1) {	// L578
              for (int v336 = 0; v336 < 1; v336 += 1) {	// L579
                int8_t v337 = v322[v330][v334][(v332 + v335)][(v333 + v336)];	// L580
                int8_t v338 = v323[v331][v334][v335][v336];	// L581
                int8_t v339 = v325[v330][v331][v332][v333];	// L582
                int8_t v340 = v337 * v338;	// L583
                int8_t v341 = v339 + v340;	// L584
                v325[v330][v331][v332][v333] = v341;	// L585
              }
            }
          }
        }
      }
    }
  }
  for (int v342 = 0; v342 < 1; v342 += 1) {	// L593
    for (int v343 = 0; v343 < 512; v343 += 1) {	// L594
      for (int v344 = 0; v344 < 2; v344 += 1) {	// L595
        for (int v345 = 0; v345 < 2; v345 += 1) {	// L596
          int8_t v346 = v325[0][v343][v344][v345];	// L597
          bool v347 = v346 > (int8_t)0.000000;	// L598
          int8_t v348 = v347 ? v346 : (int8_t)0.000000;	// L599
          v324[v342][v343][v344][v345] = v348;	// L600
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v349[512][3][3],
  int8_t v350[1][512][2][2],
  int8_t v351[1][512][2][2]
) {	// L607
  // #pragma HLS dataflow

  int8_t v352[1][512][4][4];	// L609
  // #pragma HLS stream variable=v352 depth=10 type=fifo

  #pragma HLS bind_storage variable=v352 type=ram_t2p impl=bram

  for (int v353 = 0; v353 < 1; v353 += 1) {	// L610
    for (int v354 = 0; v354 < 512; v354 += 1) {	// L611
      for (int v355 = 0; v355 < 4; v355 += 1) {	// L612
        for (int v356 = 0; v356 < 4; v356 += 1) {	// L613
          v352[v353][v354][v355][v356] = (int8_t)0.000000;	// L614
        }
      }
    }
  }
  for (int v357 = 0; v357 < 1; v357 += 1) {	// L619
    for (int v358 = 0; v358 < 512; v358 += 1) {	// L620
      for (int v359 = 0; v359 < 2; v359 += 1) {	// L621
        for (int v360 = 0; v360 < 2; v360 += 1) {	// L622
          int8_t v361 = v350[v357][v358][v359][v360];	// L623
          v352[v357][v358][(v359 + 1)][(v360 + 1)] = v361;	// L624
        }
      }
    }
  }
  int8_t v362[1][512][2][2];	// L629
  // #pragma HLS stream variable=v362 depth=10 type=fifo

  #pragma HLS bind_storage variable=v362 type=ram_t2p impl=bram

  for (int v363 = 0; v363 < 1; v363 += 1) {	// L630
    for (int v364 = 0; v364 < 512; v364 += 1) {	// L631
      for (int v365 = 0; v365 < 2; v365 += 1) {	// L632
        for (int v366 = 0; v366 < 2; v366 += 1) {	// L633
          v362[v363][v364][v365][v366] = (int8_t)0.000000;	// L634
        }
      }
    }
  }
  for (int v367 = 0; v367 < 1; v367 += 1) {	// L639
    for (int v368 = 0; v368 < 2; v368 += 1) {	// L640
      for (int v369 = 0; v369 < 2; v369 += 1) {	// L641
        for (int v370 = 0; v370 < 512; v370 += 1) {	// L642
          for (int v371 = 0; v371 < 3; v371 += 1) {	// L643
            for (int v372 = 0; v372 < 3; v372 += 1) {	// L644
              int8_t v373 = v352[v367][v370][(v368 + v371)][(v369 + v372)];	// L645
              int8_t v374 = v349[v370][v371][v372];	// L646
              int8_t v375 = v362[v367][v370][v368][v369];	// L647
              int8_t v376 = v373 * v374;	// L648
              int8_t v377 = v375 + v376;	// L649
              v362[v367][v370][v368][v369] = v377;	// L650
            }
          }
        }
      }
    }
  }
  for (int v378 = 0; v378 < 1; v378 += 1) {	// L657
    for (int v379 = 0; v379 < 512; v379 += 1) {	// L658
      for (int v380 = 0; v380 < 2; v380 += 1) {	// L659
        for (int v381 = 0; v381 < 2; v381 += 1) {	// L660
          int8_t v382 = v362[0][v379][v380][v381];	// L661
          bool v383 = v382 > (int8_t)0.000000;	// L662
          int8_t v384 = v383 ? v382 : (int8_t)0.000000;	// L663
          v351[v378][v379][v380][v381] = v384;	// L664
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v385[1][512][2][2],
  int8_t v386[512][512][1][1],
  int8_t v387[1][512][2][2]
) {	// L671
  // #pragma HLS dataflow

  int8_t v388[1][512][2][2];	// L673
  // #pragma HLS stream variable=v388 depth=10 type=fifo

  #pragma HLS bind_storage variable=v388 type=ram_t2p impl=bram

  for (int v389 = 0; v389 < 1; v389 += 1) {	// L674
    for (int v390 = 0; v390 < 512; v390 += 1) {	// L675
      for (int v391 = 0; v391 < 2; v391 += 1) {	// L676
        for (int v392 = 0; v392 < 2; v392 += 1) {	// L677
          v388[v389][v390][v391][v392] = (int8_t)0.000000;	// L678
        }
      }
    }
  }
  for (int v393 = 0; v393 < 1; v393 += 1) {	// L683
    for (int v394 = 0; v394 < 512; v394 += 1) {	// L684
      for (int v395 = 0; v395 < 2; v395 += 1) {	// L685
        for (int v396 = 0; v396 < 2; v396 += 1) {	// L686
          for (int v397 = 0; v397 < 512; v397 += 1) {	// L687
            for (int v398 = 0; v398 < 1; v398 += 1) {	// L688
              for (int v399 = 0; v399 < 1; v399 += 1) {	// L689
                int8_t v400 = v385[v393][v397][(v395 + v398)][(v396 + v399)];	// L690
                int8_t v401 = v386[v394][v397][v398][v399];	// L691
                int8_t v402 = v388[v393][v394][v395][v396];	// L692
                int8_t v403 = v400 * v401;	// L693
                int8_t v404 = v402 + v403;	// L694
                v388[v393][v394][v395][v396] = v404;	// L695
              }
            }
          }
        }
      }
    }
  }
  for (int v405 = 0; v405 < 1; v405 += 1) {	// L703
    for (int v406 = 0; v406 < 512; v406 += 1) {	// L704
      for (int v407 = 0; v407 < 2; v407 += 1) {	// L705
        for (int v408 = 0; v408 < 2; v408 += 1) {	// L706
          int8_t v409 = v388[0][v406][v407][v408];	// L707
          bool v410 = v409 > (int8_t)0.000000;	// L708
          int8_t v411 = v410 ? v409 : (int8_t)0.000000;	// L709
          v387[v405][v406][v407][v408] = v411;	// L710
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v412[1][512][2][2],
  int8_t v413[512][3][3],
  int8_t v414[1][512][2][2]
) {	// L717
  // #pragma HLS dataflow

  int8_t v415[1][512][4][4];	// L719
  // #pragma HLS stream variable=v415 depth=10 type=fifo

  #pragma HLS bind_storage variable=v415 type=ram_t2p impl=bram

  for (int v416 = 0; v416 < 1; v416 += 1) {	// L720
    for (int v417 = 0; v417 < 512; v417 += 1) {	// L721
      for (int v418 = 0; v418 < 4; v418 += 1) {	// L722
        for (int v419 = 0; v419 < 4; v419 += 1) {	// L723
          v415[v416][v417][v418][v419] = (int8_t)0.000000;	// L724
        }
      }
    }
  }
  for (int v420 = 0; v420 < 1; v420 += 1) {	// L729
    for (int v421 = 0; v421 < 512; v421 += 1) {	// L730
      for (int v422 = 0; v422 < 2; v422 += 1) {	// L731
        for (int v423 = 0; v423 < 2; v423 += 1) {	// L732
          int8_t v424 = v412[v420][v421][v422][v423];	// L733
          v415[v420][v421][(v422 + 1)][(v423 + 1)] = v424;	// L734
        }
      }
    }
  }
  int8_t v425[1][512][2][2];	// L739
  // #pragma HLS stream variable=v425 depth=10 type=fifo

  #pragma HLS bind_storage variable=v425 type=ram_t2p impl=bram

  for (int v426 = 0; v426 < 1; v426 += 1) {	// L740
    for (int v427 = 0; v427 < 512; v427 += 1) {	// L741
      for (int v428 = 0; v428 < 2; v428 += 1) {	// L742
        for (int v429 = 0; v429 < 2; v429 += 1) {	// L743
          v425[v426][v427][v428][v429] = (int8_t)0.000000;	// L744
        }
      }
    }
  }
  for (int v430 = 0; v430 < 1; v430 += 1) {	// L749
    for (int v431 = 0; v431 < 2; v431 += 1) {	// L750
      for (int v432 = 0; v432 < 2; v432 += 1) {	// L751
        for (int v433 = 0; v433 < 512; v433 += 1) {	// L752
          for (int v434 = 0; v434 < 3; v434 += 1) {	// L753
            for (int v435 = 0; v435 < 3; v435 += 1) {	// L754
              int8_t v436 = v415[v430][v433][(v431 + v434)][(v432 + v435)];	// L755
              int8_t v437 = v413[v433][v434][v435];	// L756
              int8_t v438 = v425[v430][v433][v431][v432];	// L757
              int8_t v439 = v436 * v437;	// L758
              int8_t v440 = v438 + v439;	// L759
              v425[v430][v433][v431][v432] = v440;	// L760
            }
          }
        }
      }
    }
  }
  for (int v441 = 0; v441 < 1; v441 += 1) {	// L767
    for (int v442 = 0; v442 < 512; v442 += 1) {	// L768
      for (int v443 = 0; v443 < 2; v443 += 1) {	// L769
        for (int v444 = 0; v444 < 2; v444 += 1) {	// L770
          int8_t v445 = v425[0][v442][v443][v444];	// L771
          bool v446 = v445 > (int8_t)0.000000;	// L772
          int8_t v447 = v446 ? v445 : (int8_t)0.000000;	// L773
          v414[v441][v442][v443][v444] = v447;	// L774
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v448[512][512][1][1],
  int8_t v449[1][512][2][2],
  int8_t v450[1][512][2][2]
) {	// L781
  // #pragma HLS dataflow

  int8_t v451[1][512][2][2];	// L783
  // #pragma HLS stream variable=v451 depth=10 type=fifo

  #pragma HLS bind_storage variable=v451 type=ram_t2p impl=bram

  for (int v452 = 0; v452 < 1; v452 += 1) {	// L784
    for (int v453 = 0; v453 < 512; v453 += 1) {	// L785
      for (int v454 = 0; v454 < 2; v454 += 1) {	// L786
        for (int v455 = 0; v455 < 2; v455 += 1) {	// L787
          v451[v452][v453][v454][v455] = (int8_t)0.000000;	// L788
        }
      }
    }
  }
  for (int v456 = 0; v456 < 1; v456 += 1) {	// L793
    for (int v457 = 0; v457 < 512; v457 += 1) {	// L794
      for (int v458 = 0; v458 < 2; v458 += 1) {	// L795
        for (int v459 = 0; v459 < 2; v459 += 1) {	// L796
          for (int v460 = 0; v460 < 512; v460 += 1) {	// L797
            for (int v461 = 0; v461 < 1; v461 += 1) {	// L798
              for (int v462 = 0; v462 < 1; v462 += 1) {	// L799
                int8_t v463 = v449[v456][v460][(v458 + v461)][(v459 + v462)];	// L800
                int8_t v464 = v448[v457][v460][v461][v462];	// L801
                int8_t v465 = v451[v456][v457][v458][v459];	// L802
                int8_t v466 = v463 * v464;	// L803
                int8_t v467 = v465 + v466;	// L804
                v451[v456][v457][v458][v459] = v467;	// L805
              }
            }
          }
        }
      }
    }
  }
  for (int v468 = 0; v468 < 1; v468 += 1) {	// L813
    for (int v469 = 0; v469 < 512; v469 += 1) {	// L814
      for (int v470 = 0; v470 < 2; v470 += 1) {	// L815
        for (int v471 = 0; v471 < 2; v471 += 1) {	// L816
          int8_t v472 = v451[0][v469][v470][v471];	// L817
          bool v473 = v472 > (int8_t)0.000000;	// L818
          int8_t v474 = v473 ? v472 : (int8_t)0.000000;	// L819
          v450[v468][v469][v470][v471] = v474;	// L820
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v475[512][3][3],
  int8_t v476[1][512][2][2],
  int8_t v477[1][512][2][2]
) {	// L827
  // #pragma HLS dataflow

  int8_t v478[1][512][4][4];	// L829
  // #pragma HLS stream variable=v478 depth=10 type=fifo

  #pragma HLS bind_storage variable=v478 type=ram_t2p impl=bram

  for (int v479 = 0; v479 < 1; v479 += 1) {	// L830
    for (int v480 = 0; v480 < 512; v480 += 1) {	// L831
      for (int v481 = 0; v481 < 4; v481 += 1) {	// L832
        for (int v482 = 0; v482 < 4; v482 += 1) {	// L833
          v478[v479][v480][v481][v482] = (int8_t)0.000000;	// L834
        }
      }
    }
  }
  for (int v483 = 0; v483 < 1; v483 += 1) {	// L839
    for (int v484 = 0; v484 < 512; v484 += 1) {	// L840
      for (int v485 = 0; v485 < 2; v485 += 1) {	// L841
        for (int v486 = 0; v486 < 2; v486 += 1) {	// L842
          int8_t v487 = v476[v483][v484][v485][v486];	// L843
          v478[v483][v484][(v485 + 1)][(v486 + 1)] = v487;	// L844
        }
      }
    }
  }
  int8_t v488[1][512][2][2];	// L849
  // #pragma HLS stream variable=v488 depth=10 type=fifo

  #pragma HLS bind_storage variable=v488 type=ram_t2p impl=bram

  for (int v489 = 0; v489 < 1; v489 += 1) {	// L850
    for (int v490 = 0; v490 < 512; v490 += 1) {	// L851
      for (int v491 = 0; v491 < 2; v491 += 1) {	// L852
        for (int v492 = 0; v492 < 2; v492 += 1) {	// L853
          v488[v489][v490][v491][v492] = (int8_t)0.000000;	// L854
        }
      }
    }
  }
  for (int v493 = 0; v493 < 1; v493 += 1) {	// L859
    for (int v494 = 0; v494 < 2; v494 += 1) {	// L860
      for (int v495 = 0; v495 < 2; v495 += 1) {	// L861
        for (int v496 = 0; v496 < 512; v496 += 1) {	// L862
          for (int v497 = 0; v497 < 3; v497 += 1) {	// L863
            for (int v498 = 0; v498 < 3; v498 += 1) {	// L864
              int8_t v499 = v478[v493][v496][(v494 + v497)][(v495 + v498)];	// L865
              int8_t v500 = v475[v496][v497][v498];	// L866
              int8_t v501 = v488[v493][v496][v494][v495];	// L867
              int8_t v502 = v499 * v500;	// L868
              int8_t v503 = v501 + v502;	// L869
              v488[v493][v496][v494][v495] = v503;	// L870
            }
          }
        }
      }
    }
  }
  for (int v504 = 0; v504 < 1; v504 += 1) {	// L877
    for (int v505 = 0; v505 < 512; v505 += 1) {	// L878
      for (int v506 = 0; v506 < 2; v506 += 1) {	// L879
        for (int v507 = 0; v507 < 2; v507 += 1) {	// L880
          int8_t v508 = v488[0][v505][v506][v507];	// L881
          bool v509 = v508 > (int8_t)0.000000;	// L882
          int8_t v510 = v509 ? v508 : (int8_t)0.000000;	// L883
          v477[v504][v505][v506][v507] = v510;	// L884
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v511[1][256][2][2],
  int8_t v512[512][256][1][1],
  int8_t v513[1][512][2][2]
) {	// L891
  // #pragma HLS dataflow

  int8_t v514[1][512][2][2];	// L893
  // #pragma HLS stream variable=v514 depth=10 type=fifo

  #pragma HLS bind_storage variable=v514 type=ram_t2p impl=bram

  for (int v515 = 0; v515 < 1; v515 += 1) {	// L894
    for (int v516 = 0; v516 < 512; v516 += 1) {	// L895
      for (int v517 = 0; v517 < 2; v517 += 1) {	// L896
        for (int v518 = 0; v518 < 2; v518 += 1) {	// L897
          v514[v515][v516][v517][v518] = (int8_t)0.000000;	// L898
        }
      }
    }
  }
  for (int v519 = 0; v519 < 1; v519 += 1) {	// L903
    for (int v520 = 0; v520 < 512; v520 += 1) {	// L904
      for (int v521 = 0; v521 < 2; v521 += 1) {	// L905
        for (int v522 = 0; v522 < 2; v522 += 1) {	// L906
          for (int v523 = 0; v523 < 256; v523 += 1) {	// L907
            for (int v524 = 0; v524 < 1; v524 += 1) {	// L908
              for (int v525 = 0; v525 < 1; v525 += 1) {	// L909
                int8_t v526 = v511[v519][v523][(v521 + v524)][(v522 + v525)];	// L910
                int8_t v527 = v512[v520][v523][v524][v525];	// L911
                int8_t v528 = v514[v519][v520][v521][v522];	// L912
                int8_t v529 = v526 * v527;	// L913
                int8_t v530 = v528 + v529;	// L914
                v514[v519][v520][v521][v522] = v530;	// L915
              }
            }
          }
        }
      }
    }
  }
  for (int v531 = 0; v531 < 1; v531 += 1) {	// L923
    for (int v532 = 0; v532 < 512; v532 += 1) {	// L924
      for (int v533 = 0; v533 < 2; v533 += 1) {	// L925
        for (int v534 = 0; v534 < 2; v534 += 1) {	// L926
          int8_t v535 = v514[0][v532][v533][v534];	// L927
          bool v536 = v535 > (int8_t)0.000000;	// L928
          int8_t v537 = v536 ? v535 : (int8_t)0.000000;	// L929
          v513[v531][v532][v533][v534] = v537;	// L930
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v538[1][256][4][4],
  int8_t v539[256][3][3],
  int8_t v540[1][256][2][2]
) {	// L937
  // #pragma HLS dataflow

  int8_t v541[1][256][6][6];	// L939
  // #pragma HLS stream variable=v541 depth=10 type=fifo

  #pragma HLS bind_storage variable=v541 type=ram_t2p impl=bram

  for (int v542 = 0; v542 < 1; v542 += 1) {	// L940
    for (int v543 = 0; v543 < 256; v543 += 1) {	// L941
      for (int v544 = 0; v544 < 6; v544 += 1) {	// L942
        for (int v545 = 0; v545 < 6; v545 += 1) {	// L943
          v541[v542][v543][v544][v545] = (int8_t)0.000000;	// L944
        }
      }
    }
  }
  for (int v546 = 0; v546 < 1; v546 += 1) {	// L949
    for (int v547 = 0; v547 < 256; v547 += 1) {	// L950
      for (int v548 = 0; v548 < 4; v548 += 1) {	// L951
        for (int v549 = 0; v549 < 4; v549 += 1) {	// L952
          int8_t v550 = v538[v546][v547][v548][v549];	// L953
          v541[v546][v547][(v548 + 1)][(v549 + 1)] = v550;	// L954
        }
      }
    }
  }
  int8_t v551[1][256][2][2];	// L959
  // #pragma HLS stream variable=v551 depth=10 type=fifo

  #pragma HLS bind_storage variable=v551 type=ram_t2p impl=bram

  for (int v552 = 0; v552 < 1; v552 += 1) {	// L960
    for (int v553 = 0; v553 < 256; v553 += 1) {	// L961
      for (int v554 = 0; v554 < 2; v554 += 1) {	// L962
        for (int v555 = 0; v555 < 2; v555 += 1) {	// L963
          v551[v552][v553][v554][v555] = (int8_t)0.000000;	// L964
        }
      }
    }
  }
  for (int v556 = 0; v556 < 1; v556 += 1) {	// L969
    for (int v557 = 0; v557 < 2; v557 += 1) {	// L970
      for (int v558 = 0; v558 < 2; v558 += 1) {	// L971
        for (int v559 = 0; v559 < 256; v559 += 1) {	// L972
          for (int v560 = 0; v560 < 3; v560 += 1) {	// L973
            for (int v561 = 0; v561 < 3; v561 += 1) {	// L974
              int8_t v562 = v541[v556][v559][((v557 * 2) + v560)][((v558 * 2) + v561)];	// L975
              int8_t v563 = v539[v559][v560][v561];	// L976
              int8_t v564 = v551[v556][v559][v557][v558];	// L977
              int8_t v565 = v562 * v563;	// L978
              int8_t v566 = v564 + v565;	// L979
              v551[v556][v559][v557][v558] = v566;	// L980
            }
          }
        }
      }
    }
  }
  for (int v567 = 0; v567 < 1; v567 += 1) {	// L987
    for (int v568 = 0; v568 < 256; v568 += 1) {	// L988
      for (int v569 = 0; v569 < 2; v569 += 1) {	// L989
        for (int v570 = 0; v570 < 2; v570 += 1) {	// L990
          int8_t v571 = v551[0][v568][v569][v570];	// L991
          bool v572 = v571 > (int8_t)0.000000;	// L992
          int8_t v573 = v572 ? v571 : (int8_t)0.000000;	// L993
          v540[v567][v568][v569][v570] = v573;	// L994
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v574[256][256][1][1],
  int8_t v575[1][256][4][4],
  int8_t v576[1][256][4][4]
) {	// L1001
  // #pragma HLS dataflow

  int8_t v577[1][256][4][4];	// L1003
  // #pragma HLS stream variable=v577 depth=10 type=fifo

  #pragma HLS bind_storage variable=v577 type=ram_t2p impl=bram

  for (int v578 = 0; v578 < 1; v578 += 1) {	// L1004
    for (int v579 = 0; v579 < 256; v579 += 1) {	// L1005
      for (int v580 = 0; v580 < 4; v580 += 1) {	// L1006
        for (int v581 = 0; v581 < 4; v581 += 1) {	// L1007
          v577[v578][v579][v580][v581] = (int8_t)0.000000;	// L1008
        }
      }
    }
  }
  for (int v582 = 0; v582 < 1; v582 += 1) {	// L1013
    for (int v583 = 0; v583 < 256; v583 += 1) {	// L1014
      for (int v584 = 0; v584 < 4; v584 += 1) {	// L1015
        for (int v585 = 0; v585 < 4; v585 += 1) {	// L1016
          for (int v586 = 0; v586 < 256; v586 += 1) {	// L1017
            for (int v587 = 0; v587 < 1; v587 += 1) {	// L1018
              for (int v588 = 0; v588 < 1; v588 += 1) {	// L1019
                int8_t v589 = v575[v582][v586][(v584 + v587)][(v585 + v588)];	// L1020
                int8_t v590 = v574[v583][v586][v587][v588];	// L1021
                int8_t v591 = v577[v582][v583][v584][v585];	// L1022
                int8_t v592 = v589 * v590;	// L1023
                int8_t v593 = v591 + v592;	// L1024
                v577[v582][v583][v584][v585] = v593;	// L1025
              }
            }
          }
        }
      }
    }
  }
  for (int v594 = 0; v594 < 1; v594 += 1) {	// L1033
    for (int v595 = 0; v595 < 256; v595 += 1) {	// L1034
      for (int v596 = 0; v596 < 4; v596 += 1) {	// L1035
        for (int v597 = 0; v597 < 4; v597 += 1) {	// L1036
          int8_t v598 = v577[0][v595][v596][v597];	// L1037
          bool v599 = v598 > (int8_t)0.000000;	// L1038
          int8_t v600 = v599 ? v598 : (int8_t)0.000000;	// L1039
          v576[v594][v595][v596][v597] = v600;	// L1040
        }
      }
    }
  }
}

void main_graph_node21(
  int8_t v601[256][3][3],
  int8_t v602[1][256][4][4],
  int8_t v603[1][256][4][4]
) {	// L1047
  // #pragma HLS dataflow

  int8_t v604[1][256][6][6];	// L1049
  // #pragma HLS stream variable=v604 depth=10 type=fifo

  #pragma HLS bind_storage variable=v604 type=ram_t2p impl=bram

  for (int v605 = 0; v605 < 1; v605 += 1) {	// L1050
    for (int v606 = 0; v606 < 256; v606 += 1) {	// L1051
      for (int v607 = 0; v607 < 6; v607 += 1) {	// L1052
        for (int v608 = 0; v608 < 6; v608 += 1) {	// L1053
          v604[v605][v606][v607][v608] = (int8_t)0.000000;	// L1054
        }
      }
    }
  }
  for (int v609 = 0; v609 < 1; v609 += 1) {	// L1059
    for (int v610 = 0; v610 < 256; v610 += 1) {	// L1060
      for (int v611 = 0; v611 < 4; v611 += 1) {	// L1061
        for (int v612 = 0; v612 < 4; v612 += 1) {	// L1062
          int8_t v613 = v602[v609][v610][v611][v612];	// L1063
          v604[v609][v610][(v611 + 1)][(v612 + 1)] = v613;	// L1064
        }
      }
    }
  }
  int8_t v614[1][256][4][4];	// L1069
  // #pragma HLS stream variable=v614 depth=10 type=fifo

  #pragma HLS bind_storage variable=v614 type=ram_t2p impl=bram

  for (int v615 = 0; v615 < 1; v615 += 1) {	// L1070
    for (int v616 = 0; v616 < 256; v616 += 1) {	// L1071
      for (int v617 = 0; v617 < 4; v617 += 1) {	// L1072
        for (int v618 = 0; v618 < 4; v618 += 1) {	// L1073
          v614[v615][v616][v617][v618] = (int8_t)0.000000;	// L1074
        }
      }
    }
  }
  for (int v619 = 0; v619 < 1; v619 += 1) {	// L1079
    for (int v620 = 0; v620 < 4; v620 += 1) {	// L1080
      for (int v621 = 0; v621 < 4; v621 += 1) {	// L1081
        for (int v622 = 0; v622 < 256; v622 += 1) {	// L1082
          for (int v623 = 0; v623 < 3; v623 += 1) {	// L1083
            for (int v624 = 0; v624 < 3; v624 += 1) {	// L1084
              int8_t v625 = v604[v619][v622][(v620 + v623)][(v621 + v624)];	// L1085
              int8_t v626 = v601[v622][v623][v624];	// L1086
              int8_t v627 = v614[v619][v622][v620][v621];	// L1087
              int8_t v628 = v625 * v626;	// L1088
              int8_t v629 = v627 + v628;	// L1089
              v614[v619][v622][v620][v621] = v629;	// L1090
            }
          }
        }
      }
    }
  }
  for (int v630 = 0; v630 < 1; v630 += 1) {	// L1097
    for (int v631 = 0; v631 < 256; v631 += 1) {	// L1098
      for (int v632 = 0; v632 < 4; v632 += 1) {	// L1099
        for (int v633 = 0; v633 < 4; v633 += 1) {	// L1100
          int8_t v634 = v614[0][v631][v632][v633];	// L1101
          bool v635 = v634 > (int8_t)0.000000;	// L1102
          int8_t v636 = v635 ? v634 : (int8_t)0.000000;	// L1103
          v603[v630][v631][v632][v633] = v636;	// L1104
        }
      }
    }
  }
}

void main_graph_node22(
  int8_t v637[1][128][4][4],
  int8_t v638[256][128][1][1],
  int8_t v639[1][256][4][4]
) {	// L1111
  // #pragma HLS dataflow

  int8_t v640[1][256][4][4];	// L1113
  // #pragma HLS stream variable=v640 depth=10 type=fifo

  #pragma HLS bind_storage variable=v640 type=ram_t2p impl=bram

  for (int v641 = 0; v641 < 1; v641 += 1) {	// L1114
    for (int v642 = 0; v642 < 256; v642 += 1) {	// L1115
      for (int v643 = 0; v643 < 4; v643 += 1) {	// L1116
        for (int v644 = 0; v644 < 4; v644 += 1) {	// L1117
          v640[v641][v642][v643][v644] = (int8_t)0.000000;	// L1118
        }
      }
    }
  }
  for (int v645 = 0; v645 < 1; v645 += 1) {	// L1123
    for (int v646 = 0; v646 < 256; v646 += 1) {	// L1124
      for (int v647 = 0; v647 < 4; v647 += 1) {	// L1125
        for (int v648 = 0; v648 < 4; v648 += 1) {	// L1126
          for (int v649 = 0; v649 < 128; v649 += 1) {	// L1127
            for (int v650 = 0; v650 < 1; v650 += 1) {	// L1128
              for (int v651 = 0; v651 < 1; v651 += 1) {	// L1129
                int8_t v652 = v637[v645][v649][(v647 + v650)][(v648 + v651)];	// L1130
                int8_t v653 = v638[v646][v649][v650][v651];	// L1131
                int8_t v654 = v640[v645][v646][v647][v648];	// L1132
                int8_t v655 = v652 * v653;	// L1133
                int8_t v656 = v654 + v655;	// L1134
                v640[v645][v646][v647][v648] = v656;	// L1135
              }
            }
          }
        }
      }
    }
  }
  for (int v657 = 0; v657 < 1; v657 += 1) {	// L1143
    for (int v658 = 0; v658 < 256; v658 += 1) {	// L1144
      for (int v659 = 0; v659 < 4; v659 += 1) {	// L1145
        for (int v660 = 0; v660 < 4; v660 += 1) {	// L1146
          int8_t v661 = v640[0][v658][v659][v660];	// L1147
          bool v662 = v661 > (int8_t)0.000000;	// L1148
          int8_t v663 = v662 ? v661 : (int8_t)0.000000;	// L1149
          v639[v657][v658][v659][v660] = v663;	// L1150
        }
      }
    }
  }
}

void main_graph_node23(
  int8_t v664[128][3][3],
  int8_t v665[1][128][8][8],
  int8_t v666[1][128][4][4]
) {	// L1157
  // #pragma HLS dataflow

  int8_t v667[1][128][10][10];	// L1159
  // #pragma HLS stream variable=v667 depth=10 type=fifo

  #pragma HLS bind_storage variable=v667 type=ram_t2p impl=bram

  for (int v668 = 0; v668 < 1; v668 += 1) {	// L1160
    for (int v669 = 0; v669 < 128; v669 += 1) {	// L1161
      for (int v670 = 0; v670 < 10; v670 += 1) {	// L1162
        for (int v671 = 0; v671 < 10; v671 += 1) {	// L1163
          v667[v668][v669][v670][v671] = (int8_t)0.000000;	// L1164
        }
      }
    }
  }
  for (int v672 = 0; v672 < 1; v672 += 1) {	// L1169
    for (int v673 = 0; v673 < 128; v673 += 1) {	// L1170
      for (int v674 = 0; v674 < 8; v674 += 1) {	// L1171
        for (int v675 = 0; v675 < 8; v675 += 1) {	// L1172
          int8_t v676 = v665[v672][v673][v674][v675];	// L1173
          v667[v672][v673][(v674 + 1)][(v675 + 1)] = v676;	// L1174
        }
      }
    }
  }
  int8_t v677[1][128][4][4];	// L1179
  // #pragma HLS stream variable=v677 depth=10 type=fifo

  #pragma HLS bind_storage variable=v677 type=ram_t2p impl=bram

  for (int v678 = 0; v678 < 1; v678 += 1) {	// L1180
    for (int v679 = 0; v679 < 128; v679 += 1) {	// L1181
      for (int v680 = 0; v680 < 4; v680 += 1) {	// L1182
        for (int v681 = 0; v681 < 4; v681 += 1) {	// L1183
          v677[v678][v679][v680][v681] = (int8_t)0.000000;	// L1184
        }
      }
    }
  }
  for (int v682 = 0; v682 < 1; v682 += 1) {	// L1189
    for (int v683 = 0; v683 < 4; v683 += 1) {	// L1190
      for (int v684 = 0; v684 < 4; v684 += 1) {	// L1191
        for (int v685 = 0; v685 < 128; v685 += 1) {	// L1192
          for (int v686 = 0; v686 < 3; v686 += 1) {	// L1193
            for (int v687 = 0; v687 < 3; v687 += 1) {	// L1194
              int8_t v688 = v667[v682][v685][((v683 * 2) + v686)][((v684 * 2) + v687)];	// L1195
              int8_t v689 = v664[v685][v686][v687];	// L1196
              int8_t v690 = v677[v682][v685][v683][v684];	// L1197
              int8_t v691 = v688 * v689;	// L1198
              int8_t v692 = v690 + v691;	// L1199
              v677[v682][v685][v683][v684] = v692;	// L1200
            }
          }
        }
      }
    }
  }
  for (int v693 = 0; v693 < 1; v693 += 1) {	// L1207
    for (int v694 = 0; v694 < 128; v694 += 1) {	// L1208
      for (int v695 = 0; v695 < 4; v695 += 1) {	// L1209
        for (int v696 = 0; v696 < 4; v696 += 1) {	// L1210
          int8_t v697 = v677[0][v694][v695][v696];	// L1211
          bool v698 = v697 > (int8_t)0.000000;	// L1212
          int8_t v699 = v698 ? v697 : (int8_t)0.000000;	// L1213
          v666[v693][v694][v695][v696] = v699;	// L1214
        }
      }
    }
  }
}

void main_graph_node24(
  int8_t v700[1][128][8][8],
  int8_t v701[128][128][1][1],
  int8_t v702[1][128][8][8]
) {	// L1221
  // #pragma HLS dataflow

  int8_t v703[1][128][8][8];	// L1223
  // #pragma HLS stream variable=v703 depth=10 type=fifo

  #pragma HLS bind_storage variable=v703 type=ram_t2p impl=bram

  for (int v704 = 0; v704 < 1; v704 += 1) {	// L1224
    for (int v705 = 0; v705 < 128; v705 += 1) {	// L1225
      for (int v706 = 0; v706 < 8; v706 += 1) {	// L1226
        for (int v707 = 0; v707 < 8; v707 += 1) {	// L1227
          v703[v704][v705][v706][v707] = (int8_t)0.000000;	// L1228
        }
      }
    }
  }
  for (int v708 = 0; v708 < 1; v708 += 1) {	// L1233
    for (int v709 = 0; v709 < 128; v709 += 1) {	// L1234
      for (int v710 = 0; v710 < 8; v710 += 1) {	// L1235
        for (int v711 = 0; v711 < 8; v711 += 1) {	// L1236
          for (int v712 = 0; v712 < 128; v712 += 1) {	// L1237
            for (int v713 = 0; v713 < 1; v713 += 1) {	// L1238
              for (int v714 = 0; v714 < 1; v714 += 1) {	// L1239
                int8_t v715 = v700[v708][v712][(v710 + v713)][(v711 + v714)];	// L1240
                int8_t v716 = v701[v709][v712][v713][v714];	// L1241
                int8_t v717 = v703[v708][v709][v710][v711];	// L1242
                int8_t v718 = v715 * v716;	// L1243
                int8_t v719 = v717 + v718;	// L1244
                v703[v708][v709][v710][v711] = v719;	// L1245
              }
            }
          }
        }
      }
    }
  }
  for (int v720 = 0; v720 < 1; v720 += 1) {	// L1253
    for (int v721 = 0; v721 < 128; v721 += 1) {	// L1254
      for (int v722 = 0; v722 < 8; v722 += 1) {	// L1255
        for (int v723 = 0; v723 < 8; v723 += 1) {	// L1256
          int8_t v724 = v703[0][v721][v722][v723];	// L1257
          bool v725 = v724 > (int8_t)0.000000;	// L1258
          int8_t v726 = v725 ? v724 : (int8_t)0.000000;	// L1259
          v702[v720][v721][v722][v723] = v726;	// L1260
        }
      }
    }
  }
}

void main_graph_node25(
  int8_t v727[1][128][8][8],
  int8_t v728[128][3][3],
  int8_t v729[1][128][8][8]
) {	// L1267
  // #pragma HLS dataflow

  int8_t v730[1][128][10][10];	// L1269
  // #pragma HLS stream variable=v730 depth=10 type=fifo

  #pragma HLS bind_storage variable=v730 type=ram_t2p impl=bram

  for (int v731 = 0; v731 < 1; v731 += 1) {	// L1270
    for (int v732 = 0; v732 < 128; v732 += 1) {	// L1271
      for (int v733 = 0; v733 < 10; v733 += 1) {	// L1272
        for (int v734 = 0; v734 < 10; v734 += 1) {	// L1273
          v730[v731][v732][v733][v734] = (int8_t)0.000000;	// L1274
        }
      }
    }
  }
  for (int v735 = 0; v735 < 1; v735 += 1) {	// L1279
    for (int v736 = 0; v736 < 128; v736 += 1) {	// L1280
      for (int v737 = 0; v737 < 8; v737 += 1) {	// L1281
        for (int v738 = 0; v738 < 8; v738 += 1) {	// L1282
          int8_t v739 = v727[v735][v736][v737][v738];	// L1283
          v730[v735][v736][(v737 + 1)][(v738 + 1)] = v739;	// L1284
        }
      }
    }
  }
  int8_t v740[1][128][8][8];	// L1289
  // #pragma HLS stream variable=v740 depth=10 type=fifo

  #pragma HLS bind_storage variable=v740 type=ram_t2p impl=bram

  for (int v741 = 0; v741 < 1; v741 += 1) {	// L1290
    for (int v742 = 0; v742 < 128; v742 += 1) {	// L1291
      for (int v743 = 0; v743 < 8; v743 += 1) {	// L1292
        for (int v744 = 0; v744 < 8; v744 += 1) {	// L1293
          v740[v741][v742][v743][v744] = (int8_t)0.000000;	// L1294
        }
      }
    }
  }
  for (int v745 = 0; v745 < 1; v745 += 1) {	// L1299
    for (int v746 = 0; v746 < 8; v746 += 1) {	// L1300
      for (int v747 = 0; v747 < 8; v747 += 1) {	// L1301
        for (int v748 = 0; v748 < 128; v748 += 1) {	// L1302
          for (int v749 = 0; v749 < 3; v749 += 1) {	// L1303
            for (int v750 = 0; v750 < 3; v750 += 1) {	// L1304
              int8_t v751 = v730[v745][v748][(v746 + v749)][(v747 + v750)];	// L1305
              int8_t v752 = v728[v748][v749][v750];	// L1306
              int8_t v753 = v740[v745][v748][v746][v747];	// L1307
              int8_t v754 = v751 * v752;	// L1308
              int8_t v755 = v753 + v754;	// L1309
              v740[v745][v748][v746][v747] = v755;	// L1310
            }
          }
        }
      }
    }
  }
  for (int v756 = 0; v756 < 1; v756 += 1) {	// L1317
    for (int v757 = 0; v757 < 128; v757 += 1) {	// L1318
      for (int v758 = 0; v758 < 8; v758 += 1) {	// L1319
        for (int v759 = 0; v759 < 8; v759 += 1) {	// L1320
          int8_t v760 = v740[0][v757][v758][v759];	// L1321
          bool v761 = v760 > (int8_t)0.000000;	// L1322
          int8_t v762 = v761 ? v760 : (int8_t)0.000000;	// L1323
          v729[v756][v757][v758][v759] = v762;	// L1324
        }
      }
    }
  }
}

void main_graph_node26(
  int8_t v763[1][64][8][8],
  int8_t v764[128][64][1][1],
  int8_t v765[1][128][8][8]
) {	// L1331
  // #pragma HLS dataflow

  int8_t v766[1][128][8][8];	// L1333
  // #pragma HLS stream variable=v766 depth=10 type=fifo

  #pragma HLS bind_storage variable=v766 type=ram_t2p impl=bram

  for (int v767 = 0; v767 < 1; v767 += 1) {	// L1334
    for (int v768 = 0; v768 < 128; v768 += 1) {	// L1335
      for (int v769 = 0; v769 < 8; v769 += 1) {	// L1336
        for (int v770 = 0; v770 < 8; v770 += 1) {	// L1337
          v766[v767][v768][v769][v770] = (int8_t)0.000000;	// L1338
        }
      }
    }
  }
  for (int v771 = 0; v771 < 1; v771 += 1) {	// L1343
    for (int v772 = 0; v772 < 128; v772 += 1) {	// L1344
      for (int v773 = 0; v773 < 8; v773 += 1) {	// L1345
        for (int v774 = 0; v774 < 8; v774 += 1) {	// L1346
          for (int v775 = 0; v775 < 64; v775 += 1) {	// L1347
            for (int v776 = 0; v776 < 1; v776 += 1) {	// L1348
              for (int v777 = 0; v777 < 1; v777 += 1) {	// L1349
                int8_t v778 = v763[v771][v775][(v773 + v776)][(v774 + v777)];	// L1350
                int8_t v779 = v764[v772][v775][v776][v777];	// L1351
                int8_t v780 = v766[v771][v772][v773][v774];	// L1352
                int8_t v781 = v778 * v779;	// L1353
                int8_t v782 = v780 + v781;	// L1354
                v766[v771][v772][v773][v774] = v782;	// L1355
              }
            }
          }
        }
      }
    }
  }
  for (int v783 = 0; v783 < 1; v783 += 1) {	// L1363
    for (int v784 = 0; v784 < 128; v784 += 1) {	// L1364
      for (int v785 = 0; v785 < 8; v785 += 1) {	// L1365
        for (int v786 = 0; v786 < 8; v786 += 1) {	// L1366
          int8_t v787 = v766[0][v784][v785][v786];	// L1367
          bool v788 = v787 > (int8_t)0.000000;	// L1368
          int8_t v789 = v788 ? v787 : (int8_t)0.000000;	// L1369
          v765[v783][v784][v785][v786] = v789;	// L1370
        }
      }
    }
  }
}

void main_graph_node27(
  int8_t v790[64][3][3],
  int8_t v791[1][64][16][16],
  int8_t v792[1][64][8][8]
) {	// L1377
  // #pragma HLS dataflow

  int8_t v793[1][64][18][18];	// L1379
  // #pragma HLS stream variable=v793 depth=10 type=fifo

  #pragma HLS bind_storage variable=v793 type=ram_t2p impl=bram

  for (int v794 = 0; v794 < 1; v794 += 1) {	// L1380
    for (int v795 = 0; v795 < 64; v795 += 1) {	// L1381
      for (int v796 = 0; v796 < 18; v796 += 1) {	// L1382
        for (int v797 = 0; v797 < 18; v797 += 1) {	// L1383
          v793[v794][v795][v796][v797] = (int8_t)0.000000;	// L1384
        }
      }
    }
  }
  for (int v798 = 0; v798 < 1; v798 += 1) {	// L1389
    for (int v799 = 0; v799 < 64; v799 += 1) {	// L1390
      for (int v800 = 0; v800 < 16; v800 += 1) {	// L1391
        for (int v801 = 0; v801 < 16; v801 += 1) {	// L1392
          int8_t v802 = v791[v798][v799][v800][v801];	// L1393
          v793[v798][v799][(v800 + 1)][(v801 + 1)] = v802;	// L1394
        }
      }
    }
  }
  int8_t v803[1][64][8][8];	// L1399
  // #pragma HLS stream variable=v803 depth=10 type=fifo

  #pragma HLS bind_storage variable=v803 type=ram_t2p impl=bram

  for (int v804 = 0; v804 < 1; v804 += 1) {	// L1400
    for (int v805 = 0; v805 < 64; v805 += 1) {	// L1401
      for (int v806 = 0; v806 < 8; v806 += 1) {	// L1402
        for (int v807 = 0; v807 < 8; v807 += 1) {	// L1403
          v803[v804][v805][v806][v807] = (int8_t)0.000000;	// L1404
        }
      }
    }
  }
  for (int v808 = 0; v808 < 1; v808 += 1) {	// L1409
    for (int v809 = 0; v809 < 8; v809 += 1) {	// L1410
      for (int v810 = 0; v810 < 8; v810 += 1) {	// L1411
        for (int v811 = 0; v811 < 64; v811 += 1) {	// L1412
          for (int v812 = 0; v812 < 3; v812 += 1) {	// L1413
            for (int v813 = 0; v813 < 3; v813 += 1) {	// L1414
              int8_t v814 = v793[v808][v811][((v809 * 2) + v812)][((v810 * 2) + v813)];	// L1415
              int8_t v815 = v790[v811][v812][v813];	// L1416
              int8_t v816 = v803[v808][v811][v809][v810];	// L1417
              int8_t v817 = v814 * v815;	// L1418
              int8_t v818 = v816 + v817;	// L1419
              v803[v808][v811][v809][v810] = v818;	// L1420
            }
          }
        }
      }
    }
  }
  for (int v819 = 0; v819 < 1; v819 += 1) {	// L1427
    for (int v820 = 0; v820 < 64; v820 += 1) {	// L1428
      for (int v821 = 0; v821 < 8; v821 += 1) {	// L1429
        for (int v822 = 0; v822 < 8; v822 += 1) {	// L1430
          int8_t v823 = v803[0][v820][v821][v822];	// L1431
          bool v824 = v823 > (int8_t)0.000000;	// L1432
          int8_t v825 = v824 ? v823 : (int8_t)0.000000;	// L1433
          v792[v819][v820][v821][v822] = v825;	// L1434
        }
      }
    }
  }
}

void main_graph_node28(
  int8_t v826[64][32][1][1],
  int8_t v827[1][32][16][16],
  int8_t v828[1][64][16][16]
) {	// L1441
  // #pragma HLS dataflow

  int8_t v829[1][64][16][16];	// L1443
  // #pragma HLS stream variable=v829 depth=10 type=fifo

  #pragma HLS bind_storage variable=v829 type=ram_t2p impl=bram

  for (int v830 = 0; v830 < 1; v830 += 1) {	// L1444
    for (int v831 = 0; v831 < 64; v831 += 1) {	// L1445
      for (int v832 = 0; v832 < 16; v832 += 1) {	// L1446
        for (int v833 = 0; v833 < 16; v833 += 1) {	// L1447
          v829[v830][v831][v832][v833] = (int8_t)0.000000;	// L1448
        }
      }
    }
  }
  for (int v834 = 0; v834 < 1; v834 += 1) {	// L1453
    for (int v835 = 0; v835 < 64; v835 += 1) {	// L1454
      for (int v836 = 0; v836 < 16; v836 += 1) {	// L1455
        for (int v837 = 0; v837 < 16; v837 += 1) {	// L1456
          for (int v838 = 0; v838 < 32; v838 += 1) {	// L1457
            for (int v839 = 0; v839 < 1; v839 += 1) {	// L1458
              for (int v840 = 0; v840 < 1; v840 += 1) {	// L1459
                int8_t v841 = v827[v834][v838][(v836 + v839)][(v837 + v840)];	// L1460
                int8_t v842 = v826[v835][v838][v839][v840];	// L1461
                int8_t v843 = v829[v834][v835][v836][v837];	// L1462
                int8_t v844 = v841 * v842;	// L1463
                int8_t v845 = v843 + v844;	// L1464
                v829[v834][v835][v836][v837] = v845;	// L1465
              }
            }
          }
        }
      }
    }
  }
  for (int v846 = 0; v846 < 1; v846 += 1) {	// L1473
    for (int v847 = 0; v847 < 64; v847 += 1) {	// L1474
      for (int v848 = 0; v848 < 16; v848 += 1) {	// L1475
        for (int v849 = 0; v849 < 16; v849 += 1) {	// L1476
          int8_t v850 = v829[0][v847][v848][v849];	// L1477
          bool v851 = v850 > (int8_t)0.000000;	// L1478
          int8_t v852 = v851 ? v850 : (int8_t)0.000000;	// L1479
          v828[v846][v847][v848][v849] = v852;	// L1480
        }
      }
    }
  }
}

void main_graph_node29(
  int8_t v853[1][32][16][16],
  int8_t v854[32][3][3],
  int8_t v855[1][32][16][16]
) {	// L1487
  // #pragma HLS dataflow

  int8_t v856[1][32][18][18];	// L1489
  // #pragma HLS stream variable=v856 depth=10 type=fifo

  #pragma HLS bind_storage variable=v856 type=ram_t2p impl=bram

  for (int v857 = 0; v857 < 1; v857 += 1) {	// L1490
    for (int v858 = 0; v858 < 32; v858 += 1) {	// L1491
      for (int v859 = 0; v859 < 18; v859 += 1) {	// L1492
        for (int v860 = 0; v860 < 18; v860 += 1) {	// L1493
          v856[v857][v858][v859][v860] = (int8_t)0.000000;	// L1494
        }
      }
    }
  }
  for (int v861 = 0; v861 < 1; v861 += 1) {	// L1499
    for (int v862 = 0; v862 < 32; v862 += 1) {	// L1500
      for (int v863 = 0; v863 < 16; v863 += 1) {	// L1501
        for (int v864 = 0; v864 < 16; v864 += 1) {	// L1502
          int8_t v865 = v853[v861][v862][v863][v864];	// L1503
          v856[v861][v862][(v863 + 1)][(v864 + 1)] = v865;	// L1504
        }
      }
    }
  }
  int8_t v866[1][32][16][16];	// L1509
  // #pragma HLS stream variable=v866 depth=10 type=fifo

  #pragma HLS bind_storage variable=v866 type=ram_t2p impl=bram

  for (int v867 = 0; v867 < 1; v867 += 1) {	// L1510
    for (int v868 = 0; v868 < 32; v868 += 1) {	// L1511
      for (int v869 = 0; v869 < 16; v869 += 1) {	// L1512
        for (int v870 = 0; v870 < 16; v870 += 1) {	// L1513
          v866[v867][v868][v869][v870] = (int8_t)0.000000;	// L1514
        }
      }
    }
  }
  for (int v871 = 0; v871 < 1; v871 += 1) {	// L1519
    for (int v872 = 0; v872 < 16; v872 += 1) {	// L1520
      for (int v873 = 0; v873 < 16; v873 += 1) {	// L1521
        for (int v874 = 0; v874 < 32; v874 += 1) {	// L1522
          for (int v875 = 0; v875 < 3; v875 += 1) {	// L1523
            for (int v876 = 0; v876 < 3; v876 += 1) {	// L1524
              int8_t v877 = v856[v871][v874][(v872 + v875)][(v873 + v876)];	// L1525
              int8_t v878 = v854[v874][v875][v876];	// L1526
              int8_t v879 = v866[v871][v874][v872][v873];	// L1527
              int8_t v880 = v877 * v878;	// L1528
              int8_t v881 = v879 + v880;	// L1529
              v866[v871][v874][v872][v873] = v881;	// L1530
            }
          }
        }
      }
    }
  }
  for (int v882 = 0; v882 < 1; v882 += 1) {	// L1537
    for (int v883 = 0; v883 < 32; v883 += 1) {	// L1538
      for (int v884 = 0; v884 < 16; v884 += 1) {	// L1539
        for (int v885 = 0; v885 < 16; v885 += 1) {	// L1540
          int8_t v886 = v866[0][v883][v884][v885];	// L1541
          bool v887 = v886 > (int8_t)0.000000;	// L1542
          int8_t v888 = v887 ? v886 : (int8_t)0.000000;	// L1543
          v855[v882][v883][v884][v885] = v888;	// L1544
        }
      }
    }
  }
}

void main_graph_node30(
  int8_t v889[32][3][3][3],
  int8_t v890[1][3][32][32],
  int8_t v891[1][32][16][16]
) {	// L1551
  // #pragma HLS dataflow

  int8_t v892[1][3][34][34];	// L1553
  // #pragma HLS stream variable=v892 depth=10 type=fifo

  #pragma HLS bind_storage variable=v892 type=ram_t2p impl=bram

  for (int v893 = 0; v893 < 1; v893 += 1) {	// L1554
    for (int v894 = 0; v894 < 3; v894 += 1) {	// L1555
      for (int v895 = 0; v895 < 34; v895 += 1) {	// L1556
        for (int v896 = 0; v896 < 34; v896 += 1) {	// L1557
          v892[v893][v894][v895][v896] = (int8_t)0.000000;	// L1558
        }
      }
    }
  }
  for (int v897 = 0; v897 < 1; v897 += 1) {	// L1563
    for (int v898 = 0; v898 < 3; v898 += 1) {	// L1564
      for (int v899 = 0; v899 < 32; v899 += 1) {	// L1565
        for (int v900 = 0; v900 < 32; v900 += 1) {	// L1566
          int8_t v901 = v890[v897][v898][v899][v900];	// L1567
          v892[v897][v898][(v899 + 1)][(v900 + 1)] = v901;	// L1568
        }
      }
    }
  }
  int8_t v902[1][32][16][16];	// L1573
  // #pragma HLS stream variable=v902 depth=10 type=fifo

  #pragma HLS bind_storage variable=v902 type=ram_t2p impl=bram

  for (int v903 = 0; v903 < 1; v903 += 1) {	// L1574
    for (int v904 = 0; v904 < 32; v904 += 1) {	// L1575
      for (int v905 = 0; v905 < 16; v905 += 1) {	// L1576
        for (int v906 = 0; v906 < 16; v906 += 1) {	// L1577
          v902[v903][v904][v905][v906] = (int8_t)0.000000;	// L1578
        }
      }
    }
  }
  for (int v907 = 0; v907 < 1; v907 += 1) {	// L1583
    for (int v908 = 0; v908 < 32; v908 += 1) {	// L1584
      for (int v909 = 0; v909 < 16; v909 += 1) {	// L1585
        for (int v910 = 0; v910 < 16; v910 += 1) {	// L1586
          for (int v911 = 0; v911 < 3; v911 += 1) {	// L1587
            for (int v912 = 0; v912 < 3; v912 += 1) {	// L1588
              for (int v913 = 0; v913 < 3; v913 += 1) {	// L1589
                int8_t v914 = v892[v907][v911][((v909 * 2) + v912)][((v910 * 2) + v913)];	// L1590
                int8_t v915 = v889[v908][v911][v912][v913];	// L1591
                int8_t v916 = v902[v907][v908][v909][v910];	// L1592
                int8_t v917 = v914 * v915;	// L1593
                int8_t v918 = v916 + v917;	// L1594
                v902[v907][v908][v909][v910] = v918;	// L1595
              }
            }
          }
        }
      }
    }
  }
  for (int v919 = 0; v919 < 1; v919 += 1) {	// L1603
    for (int v920 = 0; v920 < 32; v920 += 1) {	// L1604
      for (int v921 = 0; v921 < 16; v921 += 1) {	// L1605
        for (int v922 = 0; v922 < 16; v922 += 1) {	// L1606
          int8_t v923 = v902[0][v920][v921][v922];	// L1607
          bool v924 = v923 > (int8_t)0.000000;	// L1608
          int8_t v925 = v924 ? v923 : (int8_t)0.000000;	// L1609
          v891[v919][v920][v921][v922] = v925;	// L1610
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v926[1][3][32][32],
  int8_t v927[1000],
  int8_t v928[1024][1024][1][1],
  int8_t v929[1024][512][1][1],
  int8_t v930[512][512][1][1],
  int8_t v931[512][512][1][1],
  int8_t v932[512][512][1][1],
  int8_t v933[512][512][1][1],
  int8_t v934[512][512][1][1],
  int8_t v935[512][256][1][1],
  int8_t v936[256][256][1][1],
  int8_t v937[256][128][1][1],
  int8_t v938[128][128][1][1],
  int8_t v939[128][64][1][1],
  int8_t v940[64][32][1][1],
  int8_t v941[32][3][3][3],
  int8_t v942[32][3][3],
  int8_t v943[64][3][3],
  int8_t v944[128][3][3],
  int8_t v945[128][3][3],
  int8_t v946[256][3][3],
  int8_t v947[256][3][3],
  int8_t v948[512][3][3],
  int8_t v949[512][3][3],
  int8_t v950[512][3][3],
  int8_t v951[512][3][3],
  int8_t v952[512][3][3],
  int8_t v953[512][3][3],
  int8_t v954[1024][3][3],
  int8_t v955[1024][1000],
  int8_t v956[1][1000]
) {	// L1617
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v926
  #pragma HLS bind_storage variable=v926 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v927
  #pragma HLS bind_storage variable=v927 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v928
  #pragma HLS bind_storage variable=v928 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v929
  #pragma HLS bind_storage variable=v929 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v930
  #pragma HLS bind_storage variable=v930 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v931
  #pragma HLS bind_storage variable=v931 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v932
  #pragma HLS bind_storage variable=v932 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v933
  #pragma HLS bind_storage variable=v933 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v934
  #pragma HLS bind_storage variable=v934 type=ram_t2p impl=bram

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

  // #pragma HLS dataflow

  int8_t v957[1][32][16][16];	// L1619
  // #pragma HLS stream variable=v957 depth=10 type=fifo

  #pragma HLS bind_storage variable=v957 type=ram_t2p impl=bram

  main_graph_node30(v941, v926, v957);	// L1620
  int8_t v958[1][32][16][16];	// L1621
  // #pragma HLS stream variable=v958 depth=10 type=fifo

  #pragma HLS bind_storage variable=v958 type=ram_t2p impl=bram

  main_graph_node29(v957, v942, v958);	// L1622
  int8_t v959[1][64][16][16];	// L1623
  // #pragma HLS stream variable=v959 depth=10 type=fifo

  #pragma HLS bind_storage variable=v959 type=ram_t2p impl=bram

  main_graph_node28(v940, v958, v959);	// L1624
  int8_t v960[1][64][8][8];	// L1625
  // #pragma HLS stream variable=v960 depth=10 type=fifo

  #pragma HLS bind_storage variable=v960 type=ram_t2p impl=bram

  main_graph_node27(v943, v959, v960);	// L1626
  int8_t v961[1][128][8][8];	// L1627
  // #pragma HLS stream variable=v961 depth=10 type=fifo

  #pragma HLS bind_storage variable=v961 type=ram_t2p impl=bram

  main_graph_node26(v960, v939, v961);	// L1628
  int8_t v962[1][128][8][8];	// L1629
  // #pragma HLS stream variable=v962 depth=10 type=fifo

  #pragma HLS bind_storage variable=v962 type=ram_t2p impl=bram

  main_graph_node25(v961, v944, v962);	// L1630
  int8_t v963[1][128][8][8];	// L1631
  // #pragma HLS stream variable=v963 depth=10 type=fifo

  #pragma HLS bind_storage variable=v963 type=ram_t2p impl=bram

  main_graph_node24(v962, v938, v963);	// L1632
  int8_t v964[1][128][4][4];	// L1633
  // #pragma HLS stream variable=v964 depth=10 type=fifo

  #pragma HLS bind_storage variable=v964 type=ram_t2p impl=bram

  main_graph_node23(v945, v963, v964);	// L1634
  int8_t v965[1][256][4][4];	// L1635
  // #pragma HLS stream variable=v965 depth=10 type=fifo

  #pragma HLS bind_storage variable=v965 type=ram_t2p impl=bram

  main_graph_node22(v964, v937, v965);	// L1636
  int8_t v966[1][256][4][4];	// L1637
  // #pragma HLS stream variable=v966 depth=10 type=fifo

  #pragma HLS bind_storage variable=v966 type=ram_t2p impl=bram

  main_graph_node21(v946, v965, v966);	// L1638
  int8_t v967[1][256][4][4];	// L1639
  // #pragma HLS stream variable=v967 depth=10 type=fifo

  #pragma HLS bind_storage variable=v967 type=ram_t2p impl=bram

  main_graph_node20(v936, v966, v967);	// L1640
  int8_t v968[1][256][2][2];	// L1641
  // #pragma HLS stream variable=v968 depth=10 type=fifo

  #pragma HLS bind_storage variable=v968 type=ram_t2p impl=bram

  main_graph_node19(v967, v947, v968);	// L1642
  int8_t v969[1][512][2][2];	// L1643
  // #pragma HLS stream variable=v969 depth=10 type=fifo

  #pragma HLS bind_storage variable=v969 type=ram_t2p impl=bram

  main_graph_node18(v968, v935, v969);	// L1644
  int8_t v970[1][512][2][2];	// L1645
  // #pragma HLS stream variable=v970 depth=10 type=fifo

  #pragma HLS bind_storage variable=v970 type=ram_t2p impl=bram

  main_graph_node17(v948, v969, v970);	// L1646
  int8_t v971[1][512][2][2];	// L1647
  // #pragma HLS stream variable=v971 depth=10 type=fifo

  #pragma HLS bind_storage variable=v971 type=ram_t2p impl=bram

  main_graph_node16(v934, v970, v971);	// L1648
  int8_t v972[1][512][2][2];	// L1649
  // #pragma HLS stream variable=v972 depth=10 type=fifo

  #pragma HLS bind_storage variable=v972 type=ram_t2p impl=bram

  main_graph_node15(v971, v949, v972);	// L1650
  int8_t v973[1][512][2][2];	// L1651
  // #pragma HLS stream variable=v973 depth=10 type=fifo

  #pragma HLS bind_storage variable=v973 type=ram_t2p impl=bram

  main_graph_node14(v972, v933, v973);	// L1652
  int8_t v974[1][512][2][2];	// L1653
  // #pragma HLS stream variable=v974 depth=10 type=fifo

  #pragma HLS bind_storage variable=v974 type=ram_t2p impl=bram

  main_graph_node13(v950, v973, v974);	// L1654
  int8_t v975[1][512][2][2];	// L1655
  // #pragma HLS stream variable=v975 depth=10 type=fifo

  #pragma HLS bind_storage variable=v975 type=ram_t2p impl=bram

  main_graph_node12(v974, v932, v975);	// L1656
  int8_t v976[1][512][2][2];	// L1657
  // #pragma HLS stream variable=v976 depth=10 type=fifo

  #pragma HLS bind_storage variable=v976 type=ram_t2p impl=bram

  main_graph_node11(v951, v975, v976);	// L1658
  int8_t v977[1][512][2][2];	// L1659
  // #pragma HLS stream variable=v977 depth=10 type=fifo

  #pragma HLS bind_storage variable=v977 type=ram_t2p impl=bram

  main_graph_node10(v976, v931, v977);	// L1660
  int8_t v978[1][512][2][2];	// L1661
  // #pragma HLS stream variable=v978 depth=10 type=fifo

  #pragma HLS bind_storage variable=v978 type=ram_t2p impl=bram

  main_graph_node9(v977, v952, v978);	// L1662
  int8_t v979[1][512][2][2];	// L1663
  // #pragma HLS stream variable=v979 depth=10 type=fifo

  #pragma HLS bind_storage variable=v979 type=ram_t2p impl=bram

  main_graph_node8(v930, v978, v979);	// L1664
  int8_t v980[1][512][1][1];	// L1665
  // #pragma HLS stream variable=v980 depth=10 type=fifo

  #pragma HLS bind_storage variable=v980 type=ram_t2p impl=bram

  main_graph_node7(v979, v953, v980);	// L1666
  int8_t v981[1][1024][1][1];	// L1667
  // #pragma HLS stream variable=v981 depth=10 type=fifo

  #pragma HLS bind_storage variable=v981 type=ram_t2p impl=bram

  main_graph_node6(v980, v929, v981);	// L1668
  int8_t v982[1][1024][1][1];	// L1669
  // #pragma HLS stream variable=v982 depth=10 type=fifo

  #pragma HLS bind_storage variable=v982 type=ram_t2p impl=bram

  main_graph_node5(v981, v954, v982);	// L1670
  int8_t v983[1][1024][1][1];	// L1671
  // #pragma HLS stream variable=v983 depth=10 type=fifo

  #pragma HLS bind_storage variable=v983 type=ram_t2p impl=bram

  main_graph_node4(v928, v982, v983);	// L1672
  int8_t v984[1][1024][2][2];	// L1673
  // #pragma HLS stream variable=v984 depth=10 type=fifo

  #pragma HLS bind_storage variable=v984 type=ram_t2p impl=bram

  main_graph_node3(v983, v984);	// L1674
  int8_t v985[1][1];	// L1675
  // #pragma HLS stream variable=v985 depth=10 type=fifo

  #pragma HLS bind_storage variable=v985 type=ram_t2p impl=bram

  int8_t v986[1][1024][1][1];	// L1676
  // #pragma HLS stream variable=v986 depth=10 type=fifo

  #pragma HLS bind_storage variable=v986 type=ram_t2p impl=bram

  main_graph_node2(v984, v985, v986);	// L1677
  int8_t v987[1][1024][1][1];	// L1678
  // #pragma HLS stream variable=v987 depth=10 type=fifo

  #pragma HLS bind_storage variable=v987 type=ram_t2p impl=bram

  main_graph_node1(v986, v985, v987);	// L1679
  main_graph_node0(v987, v955, v927, v956);	// L1680
}

