
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
  int8_t v0[1470],
  int8_t v1[4096][1470],
  int8_t v2[1][4096],
  int8_t v3[1][1470]
) {	// L3
  // #pragma HLS dataflow

  int8_t v4[1][1470];	// L5
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L6
    for (int v6 = 0; v6 < 1470; v6 += 1) {	// L7
      v4[v5][v6] = (int8_t)0.000000;	// L8
    }
  }
  for (int v7 = 0; v7 < 1; v7 += 1) {	// L11
    for (int v8 = 0; v8 < 1470; v8 += 1) {	// L12
      for (int v9 = 0; v9 < 4096; v9 += 1) {	// L13
        int8_t v10 = v2[v7][v9];	// L14
        int8_t v11 = v1[v9][v8];	// L15
        int8_t v12 = v4[v7][v8];	// L16
        int8_t v13 = v10 * v11;	// L17
        int8_t v14 = v12 + v13;	// L18
        v4[v7][v8] = v14;	// L19
      }
    }
  }
  for (int v15 = 0; v15 < 1; v15 += 1) {	// L23
    for (int v16 = 0; v16 < 1470; v16 += 1) {	// L24
      int8_t v17 = v4[0][v16];	// L25
      int8_t v18 = v0[v16];	// L26
      int8_t v19 = v17 + v18;	// L27
      v3[v15][v16] = v19;	// L28
    }
  }
}

void main_graph_node1(
  int8_t v20[1][256][1][1],
  int8_t v21[256][4096],
  int8_t v22[4096],
  int8_t v23[1][4096]
) {	// L33
  // #pragma HLS dataflow

  int8_t v24[1][4096];	// L35
  // #pragma HLS stream variable=v24 depth=10 type=fifo

  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L36
    for (int v26 = 0; v26 < 4096; v26 += 1) {	// L37
      v24[v25][v26] = (int8_t)0.000000;	// L38
    }
  }
  for (int v27 = 0; v27 < 1; v27 += 1) {	// L41
    for (int v28 = 0; v28 < 4096; v28 += 1) {	// L42
      for (int v29 = 0; v29 < 256; v29 += 1) {	// L43
        int8_t v30 = v20[v27][v29][0][0];	// L44
        int8_t v31 = v21[v29][v28];	// L45
        int8_t v32 = v24[v27][v28];	// L46
        int8_t v33 = v30 * v31;	// L47
        int8_t v34 = v32 + v33;	// L48
        v24[v27][v28] = v34;	// L49
      }
    }
  }
  for (int v35 = 0; v35 < 1; v35 += 1) {	// L53
    for (int v36 = 0; v36 < 4096; v36 += 1) {	// L54
      int8_t v37 = v24[0][v36];	// L55
      int8_t v38 = v22[v36];	// L56
      int8_t v39 = v37 + v38;	// L57
      bool v40 = v39 > (int8_t)0.000000;	// L58
      int8_t v41 = v40 ? v39 : (int8_t)0.000000;	// L59
      v23[v35][v36] = v41;	// L60
    }
  }
}

void main_graph_node2(
  int8_t v42[1][1024][20][6],
  int8_t v43[256][1024][20][6],
  int8_t v44[1][256][1][1]
) {	// L65
  // #pragma HLS dataflow

  for (int v45 = 0; v45 < 1; v45 += 1) {	// L67
    for (int v46 = 0; v46 < 256; v46 += 1) {	// L68
      for (int v47 = 0; v47 < 1; v47 += 1) {	// L69
        for (int v48 = 0; v48 < 1; v48 += 1) {	// L70
          v44[v45][v46][v47][v48] = (int8_t)0.000000;	// L71
        }
      }
    }
  }
  for (int v49 = 0; v49 < 1; v49 += 1) {	// L76
    for (int v50 = 0; v50 < 256; v50 += 1) {	// L77
      for (int v51 = 0; v51 < 1; v51 += 1) {	// L78
        for (int v52 = 0; v52 < 1; v52 += 1) {	// L79
          for (int v53 = 0; v53 < 1024; v53 += 1) {	// L80
            for (int v54 = 0; v54 < 20; v54 += 1) {	// L81
              for (int v55 = 0; v55 < 6; v55 += 1) {	// L82
                int8_t v56 = v42[v49][v53][(v51 + v54)][(v52 + v55)];	// L83
                int8_t v57 = v43[v50][v53][v54][v55];	// L84
                int8_t v58 = v44[v49][v50][v51][v52];	// L85
                int8_t v59 = v56 * v57;	// L86
                int8_t v60 = v58 + v59;	// L87
                v44[v49][v50][v51][v52] = v60;	// L88
              }
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v61[1][1024][20][6],
  int8_t v62[1024][1024][3][3],
  int8_t v63[1][1024][20][6]
) {	// L98
  // #pragma HLS dataflow

  int8_t v64[1][1024][22][8];	// L100
  // #pragma HLS stream variable=v64 depth=10 type=fifo

  #pragma HLS bind_storage variable=v64 type=ram_t2p impl=bram

  for (int v65 = 0; v65 < 1; v65 += 1) {	// L101
    for (int v66 = 0; v66 < 1024; v66 += 1) {	// L102
      for (int v67 = 0; v67 < 22; v67 += 1) {	// L103
        for (int v68 = 0; v68 < 8; v68 += 1) {	// L104
          v64[v65][v66][v67][v68] = (int8_t)0.000000;	// L105
        }
      }
    }
  }
  for (int v69 = 0; v69 < 1; v69 += 1) {	// L110
    for (int v70 = 0; v70 < 1024; v70 += 1) {	// L111
      for (int v71 = 0; v71 < 20; v71 += 1) {	// L112
        for (int v72 = 0; v72 < 6; v72 += 1) {	// L113
          int8_t v73 = v61[v69][v70][v71][v72];	// L114
          v64[v69][v70][(v71 + 1)][(v72 + 1)] = v73;	// L115
        }
      }
    }
  }
  int8_t v74[1][1024][20][6];	// L120
  // #pragma HLS stream variable=v74 depth=10 type=fifo

  #pragma HLS bind_storage variable=v74 type=ram_t2p impl=bram

  for (int v75 = 0; v75 < 1; v75 += 1) {	// L121
    for (int v76 = 0; v76 < 1024; v76 += 1) {	// L122
      for (int v77 = 0; v77 < 20; v77 += 1) {	// L123
        for (int v78 = 0; v78 < 6; v78 += 1) {	// L124
          v74[v75][v76][v77][v78] = (int8_t)0.000000;	// L125
        }
      }
    }
  }
  for (int v79 = 0; v79 < 1; v79 += 1) {	// L130
    for (int v80 = 0; v80 < 1024; v80 += 1) {	// L131
      for (int v81 = 0; v81 < 20; v81 += 1) {	// L132
        for (int v82 = 0; v82 < 6; v82 += 1) {	// L133
          for (int v83 = 0; v83 < 1024; v83 += 1) {	// L134
            for (int v84 = 0; v84 < 3; v84 += 1) {	// L135
              for (int v85 = 0; v85 < 3; v85 += 1) {	// L136
                int8_t v86 = v64[v79][v83][(v81 + v84)][(v82 + v85)];	// L137
                int8_t v87 = v62[v80][v83][v84][v85];	// L138
                int8_t v88 = v74[v79][v80][v81][v82];	// L139
                int8_t v89 = v86 * v87;	// L140
                int8_t v90 = v88 + v89;	// L141
                v74[v79][v80][v81][v82] = v90;	// L142
              }
            }
          }
        }
      }
    }
  }
  for (int v91 = 0; v91 < 1; v91 += 1) {	// L150
    for (int v92 = 0; v92 < 1024; v92 += 1) {	// L151
      for (int v93 = 0; v93 < 20; v93 += 1) {	// L152
        for (int v94 = 0; v94 < 6; v94 += 1) {	// L153
          int8_t v95 = v74[0][v92][v93][v94];	// L154
          bool v96 = v95 > (int8_t)0.000000;	// L155
          int8_t v97 = v96 ? v95 : (int8_t)0.000000;	// L156
          v63[v91][v92][v93][v94] = v97;	// L157
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v98[1][512][20][6],
  int8_t v99[1024][512][3][3],
  int8_t v100[1][1024][20][6]
) {	// L164
  // #pragma HLS dataflow

  int8_t v101[1][512][22][8];	// L166
  // #pragma HLS stream variable=v101 depth=10 type=fifo

  #pragma HLS bind_storage variable=v101 type=ram_t2p impl=bram

  for (int v102 = 0; v102 < 1; v102 += 1) {	// L167
    for (int v103 = 0; v103 < 512; v103 += 1) {	// L168
      for (int v104 = 0; v104 < 22; v104 += 1) {	// L169
        for (int v105 = 0; v105 < 8; v105 += 1) {	// L170
          v101[v102][v103][v104][v105] = (int8_t)0.000000;	// L171
        }
      }
    }
  }
  for (int v106 = 0; v106 < 1; v106 += 1) {	// L176
    for (int v107 = 0; v107 < 512; v107 += 1) {	// L177
      for (int v108 = 0; v108 < 20; v108 += 1) {	// L178
        for (int v109 = 0; v109 < 6; v109 += 1) {	// L179
          int8_t v110 = v98[v106][v107][v108][v109];	// L180
          v101[v106][v107][(v108 + 1)][(v109 + 1)] = v110;	// L181
        }
      }
    }
  }
  int8_t v111[1][1024][20][6];	// L186
  // #pragma HLS stream variable=v111 depth=10 type=fifo

  #pragma HLS bind_storage variable=v111 type=ram_t2p impl=bram

  for (int v112 = 0; v112 < 1; v112 += 1) {	// L187
    for (int v113 = 0; v113 < 1024; v113 += 1) {	// L188
      for (int v114 = 0; v114 < 20; v114 += 1) {	// L189
        for (int v115 = 0; v115 < 6; v115 += 1) {	// L190
          v111[v112][v113][v114][v115] = (int8_t)0.000000;	// L191
        }
      }
    }
  }
  for (int v116 = 0; v116 < 1; v116 += 1) {	// L196
    for (int v117 = 0; v117 < 1024; v117 += 1) {	// L197
      for (int v118 = 0; v118 < 20; v118 += 1) {	// L198
        for (int v119 = 0; v119 < 6; v119 += 1) {	// L199
          for (int v120 = 0; v120 < 512; v120 += 1) {	// L200
            for (int v121 = 0; v121 < 3; v121 += 1) {	// L201
              for (int v122 = 0; v122 < 3; v122 += 1) {	// L202
                int8_t v123 = v101[v116][v120][(v118 + v121)][(v119 + v122)];	// L203
                int8_t v124 = v99[v117][v120][v121][v122];	// L204
                int8_t v125 = v111[v116][v117][v118][v119];	// L205
                int8_t v126 = v123 * v124;	// L206
                int8_t v127 = v125 + v126;	// L207
                v111[v116][v117][v118][v119] = v127;	// L208
              }
            }
          }
        }
      }
    }
  }
  for (int v128 = 0; v128 < 1; v128 += 1) {	// L216
    for (int v129 = 0; v129 < 1024; v129 += 1) {	// L217
      for (int v130 = 0; v130 < 20; v130 += 1) {	// L218
        for (int v131 = 0; v131 < 6; v131 += 1) {	// L219
          int8_t v132 = v111[0][v129][v130][v131];	// L220
          bool v133 = v132 > (int8_t)0.000000;	// L221
          int8_t v134 = v133 ? v132 : (int8_t)0.000000;	// L222
          v100[v128][v129][v130][v131] = v134;	// L223
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v135[1][512][20][6],
  int8_t v136[512][512][3][3],
  int8_t v137[1][512][20][6]
) {	// L230
  // #pragma HLS dataflow

  int8_t v138[1][512][22][8];	// L232
  // #pragma HLS stream variable=v138 depth=10 type=fifo

  #pragma HLS bind_storage variable=v138 type=ram_t2p impl=bram

  for (int v139 = 0; v139 < 1; v139 += 1) {	// L233
    for (int v140 = 0; v140 < 512; v140 += 1) {	// L234
      for (int v141 = 0; v141 < 22; v141 += 1) {	// L235
        for (int v142 = 0; v142 < 8; v142 += 1) {	// L236
          v138[v139][v140][v141][v142] = (int8_t)0.000000;	// L237
        }
      }
    }
  }
  for (int v143 = 0; v143 < 1; v143 += 1) {	// L242
    for (int v144 = 0; v144 < 512; v144 += 1) {	// L243
      for (int v145 = 0; v145 < 20; v145 += 1) {	// L244
        for (int v146 = 0; v146 < 6; v146 += 1) {	// L245
          int8_t v147 = v135[v143][v144][v145][v146];	// L246
          v138[v143][v144][(v145 + 1)][(v146 + 1)] = v147;	// L247
        }
      }
    }
  }
  int8_t v148[1][512][20][6];	// L252
  // #pragma HLS stream variable=v148 depth=10 type=fifo

  #pragma HLS bind_storage variable=v148 type=ram_t2p impl=bram

  for (int v149 = 0; v149 < 1; v149 += 1) {	// L253
    for (int v150 = 0; v150 < 512; v150 += 1) {	// L254
      for (int v151 = 0; v151 < 20; v151 += 1) {	// L255
        for (int v152 = 0; v152 < 6; v152 += 1) {	// L256
          v148[v149][v150][v151][v152] = (int8_t)0.000000;	// L257
        }
      }
    }
  }
  for (int v153 = 0; v153 < 1; v153 += 1) {	// L262
    for (int v154 = 0; v154 < 512; v154 += 1) {	// L263
      for (int v155 = 0; v155 < 20; v155 += 1) {	// L264
        for (int v156 = 0; v156 < 6; v156 += 1) {	// L265
          for (int v157 = 0; v157 < 512; v157 += 1) {	// L266
            for (int v158 = 0; v158 < 3; v158 += 1) {	// L267
              for (int v159 = 0; v159 < 3; v159 += 1) {	// L268
                int8_t v160 = v138[v153][v157][(v155 + v158)][(v156 + v159)];	// L269
                int8_t v161 = v136[v154][v157][v158][v159];	// L270
                int8_t v162 = v148[v153][v154][v155][v156];	// L271
                int8_t v163 = v160 * v161;	// L272
                int8_t v164 = v162 + v163;	// L273
                v148[v153][v154][v155][v156] = v164;	// L274
              }
            }
          }
        }
      }
    }
  }
  for (int v165 = 0; v165 < 1; v165 += 1) {	// L282
    for (int v166 = 0; v166 < 512; v166 += 1) {	// L283
      for (int v167 = 0; v167 < 20; v167 += 1) {	// L284
        for (int v168 = 0; v168 < 6; v168 += 1) {	// L285
          int8_t v169 = v148[0][v166][v167][v168];	// L286
          bool v170 = v169 > (int8_t)0.000000;	// L287
          int8_t v171 = v170 ? v169 : (int8_t)0.000000;	// L288
          v137[v165][v166][v167][v168] = v171;	// L289
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v172[1][512][40][12],
  int8_t v173[1][512][20][6]
) {	// L296
  // #pragma HLS dataflow

  for (int v174 = 0; v174 < 1; v174 += 1) {	// L298
    for (int v175 = 0; v175 < 512; v175 += 1) {	// L299
      for (int v176 = 0; v176 < 20; v176 += 1) {	// L300
        for (int v177 = 0; v177 < 6; v177 += 1) {	// L301
          v173[v174][v175][v176][v177] = (int8_t)-INFINITY;	// L302
        }
      }
    }
  }
  for (int v178 = 0; v178 < 1; v178 += 1) {	// L307
    for (int v179 = 0; v179 < 512; v179 += 1) {	// L308
      for (int v180 = 0; v180 < 20; v180 += 1) {	// L309
        for (int v181 = 0; v181 < 6; v181 += 1) {	// L310
          for (int v182 = 0; v182 < 2; v182 += 1) {	// L311
            for (int v183 = 0; v183 < 2; v183 += 1) {	// L312
              int8_t v184 = v172[v178][v179][((v180 * 2) + v182)][((v181 * 2) + v183)];	// L313
              int8_t v185 = v173[v178][v179][v180][v181];	// L314
              int8_t v186 = max(v185, v184);	// L315
              v173[v178][v179][v180][v181] = v186;	// L316
            }
          }
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v187[512][256][3][3],
  int8_t v188[1][256][40][12],
  int8_t v189[1][512][40][12]
) {	// L325
  // #pragma HLS dataflow

  int8_t v190[1][256][42][14];	// L327
  // #pragma HLS stream variable=v190 depth=10 type=fifo

  #pragma HLS bind_storage variable=v190 type=ram_t2p impl=bram

  for (int v191 = 0; v191 < 1; v191 += 1) {	// L328
    for (int v192 = 0; v192 < 256; v192 += 1) {	// L329
      for (int v193 = 0; v193 < 42; v193 += 1) {	// L330
        for (int v194 = 0; v194 < 14; v194 += 1) {	// L331
          v190[v191][v192][v193][v194] = (int8_t)0.000000;	// L332
        }
      }
    }
  }
  for (int v195 = 0; v195 < 1; v195 += 1) {	// L337
    for (int v196 = 0; v196 < 256; v196 += 1) {	// L338
      for (int v197 = 0; v197 < 40; v197 += 1) {	// L339
        for (int v198 = 0; v198 < 12; v198 += 1) {	// L340
          int8_t v199 = v188[v195][v196][v197][v198];	// L341
          v190[v195][v196][(v197 + 1)][(v198 + 1)] = v199;	// L342
        }
      }
    }
  }
  int8_t v200[1][512][40][12];	// L347
  // #pragma HLS stream variable=v200 depth=10 type=fifo

  #pragma HLS bind_storage variable=v200 type=ram_t2p impl=bram

  for (int v201 = 0; v201 < 1; v201 += 1) {	// L348
    for (int v202 = 0; v202 < 512; v202 += 1) {	// L349
      for (int v203 = 0; v203 < 40; v203 += 1) {	// L350
        for (int v204 = 0; v204 < 12; v204 += 1) {	// L351
          v200[v201][v202][v203][v204] = (int8_t)0.000000;	// L352
        }
      }
    }
  }
  for (int v205 = 0; v205 < 1; v205 += 1) {	// L357
    for (int v206 = 0; v206 < 512; v206 += 1) {	// L358
      for (int v207 = 0; v207 < 40; v207 += 1) {	// L359
        for (int v208 = 0; v208 < 12; v208 += 1) {	// L360
          for (int v209 = 0; v209 < 256; v209 += 1) {	// L361
            for (int v210 = 0; v210 < 3; v210 += 1) {	// L362
              for (int v211 = 0; v211 < 3; v211 += 1) {	// L363
                int8_t v212 = v190[v205][v209][(v207 + v210)][(v208 + v211)];	// L364
                int8_t v213 = v187[v206][v209][v210][v211];	// L365
                int8_t v214 = v200[v205][v206][v207][v208];	// L366
                int8_t v215 = v212 * v213;	// L367
                int8_t v216 = v214 + v215;	// L368
                v200[v205][v206][v207][v208] = v216;	// L369
              }
            }
          }
        }
      }
    }
  }
  for (int v217 = 0; v217 < 1; v217 += 1) {	// L377
    for (int v218 = 0; v218 < 512; v218 += 1) {	// L378
      for (int v219 = 0; v219 < 40; v219 += 1) {	// L379
        for (int v220 = 0; v220 < 12; v220 += 1) {	// L380
          int8_t v221 = v200[0][v218][v219][v220];	// L381
          bool v222 = v221 > (int8_t)0.000000;	// L382
          int8_t v223 = v222 ? v221 : (int8_t)0.000000;	// L383
          v189[v217][v218][v219][v220] = v223;	// L384
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v224[1][256][80][24],
  int8_t v225[1][256][40][12]
) {	// L391
  // #pragma HLS dataflow

  for (int v226 = 0; v226 < 1; v226 += 1) {	// L393
    for (int v227 = 0; v227 < 256; v227 += 1) {	// L394
      for (int v228 = 0; v228 < 40; v228 += 1) {	// L395
        for (int v229 = 0; v229 < 12; v229 += 1) {	// L396
          v225[v226][v227][v228][v229] = (int8_t)-INFINITY;	// L397
        }
      }
    }
  }
  for (int v230 = 0; v230 < 1; v230 += 1) {	// L402
    for (int v231 = 0; v231 < 256; v231 += 1) {	// L403
      for (int v232 = 0; v232 < 40; v232 += 1) {	// L404
        for (int v233 = 0; v233 < 12; v233 += 1) {	// L405
          for (int v234 = 0; v234 < 2; v234 += 1) {	// L406
            for (int v235 = 0; v235 < 2; v235 += 1) {	// L407
              int8_t v236 = v224[v230][v231][((v232 * 2) + v234)][((v233 * 2) + v235)];	// L408
              int8_t v237 = v225[v230][v231][v232][v233];	// L409
              int8_t v238 = max(v237, v236);	// L410
              v225[v230][v231][v232][v233] = v238;	// L411
            }
          }
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v239[256][128][3][3],
  int8_t v240[1][128][80][24],
  int8_t v241[1][256][80][24]
) {	// L420
  // #pragma HLS dataflow

  int8_t v242[1][128][82][26];	// L422
  // #pragma HLS stream variable=v242 depth=10 type=fifo

  #pragma HLS bind_storage variable=v242 type=ram_t2p impl=bram

  for (int v243 = 0; v243 < 1; v243 += 1) {	// L423
    for (int v244 = 0; v244 < 128; v244 += 1) {	// L424
      for (int v245 = 0; v245 < 82; v245 += 1) {	// L425
        for (int v246 = 0; v246 < 26; v246 += 1) {	// L426
          v242[v243][v244][v245][v246] = (int8_t)0.000000;	// L427
        }
      }
    }
  }
  for (int v247 = 0; v247 < 1; v247 += 1) {	// L432
    for (int v248 = 0; v248 < 128; v248 += 1) {	// L433
      for (int v249 = 0; v249 < 80; v249 += 1) {	// L434
        for (int v250 = 0; v250 < 24; v250 += 1) {	// L435
          int8_t v251 = v240[v247][v248][v249][v250];	// L436
          v242[v247][v248][(v249 + 1)][(v250 + 1)] = v251;	// L437
        }
      }
    }
  }
  int8_t v252[1][256][80][24];	// L442
  // #pragma HLS stream variable=v252 depth=10 type=fifo

  #pragma HLS bind_storage variable=v252 type=ram_t2p impl=bram

  for (int v253 = 0; v253 < 1; v253 += 1) {	// L443
    for (int v254 = 0; v254 < 256; v254 += 1) {	// L444
      for (int v255 = 0; v255 < 80; v255 += 1) {	// L445
        for (int v256 = 0; v256 < 24; v256 += 1) {	// L446
          v252[v253][v254][v255][v256] = (int8_t)0.000000;	// L447
        }
      }
    }
  }
  for (int v257 = 0; v257 < 1; v257 += 1) {	// L452
    for (int v258 = 0; v258 < 256; v258 += 1) {	// L453
      for (int v259 = 0; v259 < 80; v259 += 1) {	// L454
        for (int v260 = 0; v260 < 24; v260 += 1) {	// L455
          for (int v261 = 0; v261 < 128; v261 += 1) {	// L456
            for (int v262 = 0; v262 < 3; v262 += 1) {	// L457
              for (int v263 = 0; v263 < 3; v263 += 1) {	// L458
                int8_t v264 = v242[v257][v261][(v259 + v262)][(v260 + v263)];	// L459
                int8_t v265 = v239[v258][v261][v262][v263];	// L460
                int8_t v266 = v252[v257][v258][v259][v260];	// L461
                int8_t v267 = v264 * v265;	// L462
                int8_t v268 = v266 + v267;	// L463
                v252[v257][v258][v259][v260] = v268;	// L464
              }
            }
          }
        }
      }
    }
  }
  for (int v269 = 0; v269 < 1; v269 += 1) {	// L472
    for (int v270 = 0; v270 < 256; v270 += 1) {	// L473
      for (int v271 = 0; v271 < 80; v271 += 1) {	// L474
        for (int v272 = 0; v272 < 24; v272 += 1) {	// L475
          int8_t v273 = v252[0][v270][v271][v272];	// L476
          bool v274 = v273 > (int8_t)0.000000;	// L477
          int8_t v275 = v274 ? v273 : (int8_t)0.000000;	// L478
          v241[v269][v270][v271][v272] = v275;	// L479
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v276[1][128][160][48],
  int8_t v277[1][128][80][24]
) {	// L486
  // #pragma HLS dataflow

  for (int v278 = 0; v278 < 1; v278 += 1) {	// L488
    for (int v279 = 0; v279 < 128; v279 += 1) {	// L489
      for (int v280 = 0; v280 < 80; v280 += 1) {	// L490
        for (int v281 = 0; v281 < 24; v281 += 1) {	// L491
          v277[v278][v279][v280][v281] = (int8_t)-INFINITY;	// L492
        }
      }
    }
  }
  for (int v282 = 0; v282 < 1; v282 += 1) {	// L497
    for (int v283 = 0; v283 < 128; v283 += 1) {	// L498
      for (int v284 = 0; v284 < 80; v284 += 1) {	// L499
        for (int v285 = 0; v285 < 24; v285 += 1) {	// L500
          for (int v286 = 0; v286 < 2; v286 += 1) {	// L501
            for (int v287 = 0; v287 < 2; v287 += 1) {	// L502
              int8_t v288 = v276[v282][v283][((v284 * 2) + v286)][((v285 * 2) + v287)];	// L503
              int8_t v289 = v277[v282][v283][v284][v285];	// L504
              int8_t v290 = max(v289, v288);	// L505
              v277[v282][v283][v284][v285] = v290;	// L506
            }
          }
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v291[1][64][160][48],
  int8_t v292[128][64][3][3],
  int8_t v293[1][128][160][48]
) {	// L515
  // #pragma HLS dataflow

  int8_t v294[1][64][162][50];	// L517
  // #pragma HLS stream variable=v294 depth=10 type=fifo

  #pragma HLS bind_storage variable=v294 type=ram_t2p impl=bram

  for (int v295 = 0; v295 < 1; v295 += 1) {	// L518
    for (int v296 = 0; v296 < 64; v296 += 1) {	// L519
      for (int v297 = 0; v297 < 162; v297 += 1) {	// L520
        for (int v298 = 0; v298 < 50; v298 += 1) {	// L521
          v294[v295][v296][v297][v298] = (int8_t)0.000000;	// L522
        }
      }
    }
  }
  for (int v299 = 0; v299 < 1; v299 += 1) {	// L527
    for (int v300 = 0; v300 < 64; v300 += 1) {	// L528
      for (int v301 = 0; v301 < 160; v301 += 1) {	// L529
        for (int v302 = 0; v302 < 48; v302 += 1) {	// L530
          int8_t v303 = v291[v299][v300][v301][v302];	// L531
          v294[v299][v300][(v301 + 1)][(v302 + 1)] = v303;	// L532
        }
      }
    }
  }
  int8_t v304[1][128][160][48];	// L537
  // #pragma HLS stream variable=v304 depth=10 type=fifo

  #pragma HLS bind_storage variable=v304 type=ram_t2p impl=bram

  for (int v305 = 0; v305 < 1; v305 += 1) {	// L538
    for (int v306 = 0; v306 < 128; v306 += 1) {	// L539
      for (int v307 = 0; v307 < 160; v307 += 1) {	// L540
        for (int v308 = 0; v308 < 48; v308 += 1) {	// L541
          v304[v305][v306][v307][v308] = (int8_t)0.000000;	// L542
        }
      }
    }
  }
  for (int v309 = 0; v309 < 1; v309 += 1) {	// L547
    for (int v310 = 0; v310 < 128; v310 += 1) {	// L548
      for (int v311 = 0; v311 < 160; v311 += 1) {	// L549
        for (int v312 = 0; v312 < 48; v312 += 1) {	// L550
          for (int v313 = 0; v313 < 64; v313 += 1) {	// L551
            for (int v314 = 0; v314 < 3; v314 += 1) {	// L552
              for (int v315 = 0; v315 < 3; v315 += 1) {	// L553
                int8_t v316 = v294[v309][v313][(v311 + v314)][(v312 + v315)];	// L554
                int8_t v317 = v292[v310][v313][v314][v315];	// L555
                int8_t v318 = v304[v309][v310][v311][v312];	// L556
                int8_t v319 = v316 * v317;	// L557
                int8_t v320 = v318 + v319;	// L558
                v304[v309][v310][v311][v312] = v320;	// L559
              }
            }
          }
        }
      }
    }
  }
  for (int v321 = 0; v321 < 1; v321 += 1) {	// L567
    for (int v322 = 0; v322 < 128; v322 += 1) {	// L568
      for (int v323 = 0; v323 < 160; v323 += 1) {	// L569
        for (int v324 = 0; v324 < 48; v324 += 1) {	// L570
          int8_t v325 = v304[0][v322][v323][v324];	// L571
          bool v326 = v325 > (int8_t)0.000000;	// L572
          int8_t v327 = v326 ? v325 : (int8_t)0.000000;	// L573
          v293[v321][v322][v323][v324] = v327;	// L574
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v328[1][64][320][96],
  int8_t v329[1][64][160][48]
) {	// L581
  // #pragma HLS dataflow

  for (int v330 = 0; v330 < 1; v330 += 1) {	// L583
    for (int v331 = 0; v331 < 64; v331 += 1) {	// L584
      for (int v332 = 0; v332 < 160; v332 += 1) {	// L585
        for (int v333 = 0; v333 < 48; v333 += 1) {	// L586
          v329[v330][v331][v332][v333] = (int8_t)-INFINITY;	// L587
        }
      }
    }
  }
  for (int v334 = 0; v334 < 1; v334 += 1) {	// L592
    for (int v335 = 0; v335 < 64; v335 += 1) {	// L593
      for (int v336 = 0; v336 < 160; v336 += 1) {	// L594
        for (int v337 = 0; v337 < 48; v337 += 1) {	// L595
          for (int v338 = 0; v338 < 2; v338 += 1) {	// L596
            for (int v339 = 0; v339 < 2; v339 += 1) {	// L597
              int8_t v340 = v328[v334][v335][((v336 * 2) + v338)][((v337 * 2) + v339)];	// L598
              int8_t v341 = v329[v334][v335][v336][v337];	// L599
              int8_t v342 = max(v341, v340);	// L600
              v329[v334][v335][v336][v337] = v342;	// L601
            }
          }
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v343[64][32][3][3],
  int8_t v344[1][32][320][96],
  int8_t v345[1][64][320][96]
) {	// L610
  // #pragma HLS dataflow

  int8_t v346[1][32][322][98];	// L612
  // #pragma HLS stream variable=v346 depth=10 type=fifo

  #pragma HLS bind_storage variable=v346 type=ram_t2p impl=bram

  for (int v347 = 0; v347 < 1; v347 += 1) {	// L613
    for (int v348 = 0; v348 < 32; v348 += 1) {	// L614
      for (int v349 = 0; v349 < 322; v349 += 1) {	// L615
        for (int v350 = 0; v350 < 98; v350 += 1) {	// L616
          v346[v347][v348][v349][v350] = (int8_t)0.000000;	// L617
        }
      }
    }
  }
  for (int v351 = 0; v351 < 1; v351 += 1) {	// L622
    for (int v352 = 0; v352 < 32; v352 += 1) {	// L623
      for (int v353 = 0; v353 < 320; v353 += 1) {	// L624
        for (int v354 = 0; v354 < 96; v354 += 1) {	// L625
          int8_t v355 = v344[v351][v352][v353][v354];	// L626
          v346[v351][v352][(v353 + 1)][(v354 + 1)] = v355;	// L627
        }
      }
    }
  }
  int8_t v356[1][64][320][96];	// L632
  // #pragma HLS stream variable=v356 depth=10 type=fifo

  #pragma HLS bind_storage variable=v356 type=ram_t2p impl=bram

  for (int v357 = 0; v357 < 1; v357 += 1) {	// L633
    for (int v358 = 0; v358 < 64; v358 += 1) {	// L634
      for (int v359 = 0; v359 < 320; v359 += 1) {	// L635
        for (int v360 = 0; v360 < 96; v360 += 1) {	// L636
          v356[v357][v358][v359][v360] = (int8_t)0.000000;	// L637
        }
      }
    }
  }
  for (int v361 = 0; v361 < 1; v361 += 1) {	// L642
    for (int v362 = 0; v362 < 64; v362 += 1) {	// L643
      for (int v363 = 0; v363 < 320; v363 += 1) {	// L644
        for (int v364 = 0; v364 < 96; v364 += 1) {	// L645
          for (int v365 = 0; v365 < 32; v365 += 1) {	// L646
            for (int v366 = 0; v366 < 3; v366 += 1) {	// L647
              for (int v367 = 0; v367 < 3; v367 += 1) {	// L648
                int8_t v368 = v346[v361][v365][(v363 + v366)][(v364 + v367)];	// L649
                int8_t v369 = v343[v362][v365][v366][v367];	// L650
                int8_t v370 = v356[v361][v362][v363][v364];	// L651
                int8_t v371 = v368 * v369;	// L652
                int8_t v372 = v370 + v371;	// L653
                v356[v361][v362][v363][v364] = v372;	// L654
              }
            }
          }
        }
      }
    }
  }
  for (int v373 = 0; v373 < 1; v373 += 1) {	// L662
    for (int v374 = 0; v374 < 64; v374 += 1) {	// L663
      for (int v375 = 0; v375 < 320; v375 += 1) {	// L664
        for (int v376 = 0; v376 < 96; v376 += 1) {	// L665
          int8_t v377 = v356[0][v374][v375][v376];	// L666
          bool v378 = v377 > (int8_t)0.000000;	// L667
          int8_t v379 = v378 ? v377 : (int8_t)0.000000;	// L668
          v345[v373][v374][v375][v376] = v379;	// L669
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v380[1][32][640][192],
  int8_t v381[1][32][320][96]
) {	// L676
  // #pragma HLS dataflow

  for (int v382 = 0; v382 < 1; v382 += 1) {	// L678
    for (int v383 = 0; v383 < 32; v383 += 1) {	// L679
      for (int v384 = 0; v384 < 320; v384 += 1) {	// L680
        for (int v385 = 0; v385 < 96; v385 += 1) {	// L681
          v381[v382][v383][v384][v385] = (int8_t)-INFINITY;	// L682
        }
      }
    }
  }
  for (int v386 = 0; v386 < 1; v386 += 1) {	// L687
    for (int v387 = 0; v387 < 32; v387 += 1) {	// L688
      for (int v388 = 0; v388 < 320; v388 += 1) {	// L689
        for (int v389 = 0; v389 < 96; v389 += 1) {	// L690
          for (int v390 = 0; v390 < 2; v390 += 1) {	// L691
            for (int v391 = 0; v391 < 2; v391 += 1) {	// L692
              int8_t v392 = v380[v386][v387][((v388 * 2) + v390)][((v389 * 2) + v391)];	// L693
              int8_t v393 = v381[v386][v387][v388][v389];	// L694
              int8_t v394 = max(v393, v392);	// L695
              v381[v386][v387][v388][v389] = v394;	// L696
            }
          }
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v395[1][16][640][192],
  int8_t v396[32][16][3][3],
  int8_t v397[1][32][640][192]
) {	// L705
  // #pragma HLS dataflow

  int8_t v398[1][16][642][194];	// L707
  // #pragma HLS stream variable=v398 depth=10 type=fifo

  #pragma HLS bind_storage variable=v398 type=ram_t2p impl=bram

  for (int v399 = 0; v399 < 1; v399 += 1) {	// L708
    for (int v400 = 0; v400 < 16; v400 += 1) {	// L709
      for (int v401 = 0; v401 < 642; v401 += 1) {	// L710
        for (int v402 = 0; v402 < 194; v402 += 1) {	// L711
          v398[v399][v400][v401][v402] = (int8_t)0.000000;	// L712
        }
      }
    }
  }
  for (int v403 = 0; v403 < 1; v403 += 1) {	// L717
    for (int v404 = 0; v404 < 16; v404 += 1) {	// L718
      for (int v405 = 0; v405 < 640; v405 += 1) {	// L719
        for (int v406 = 0; v406 < 192; v406 += 1) {	// L720
          int8_t v407 = v395[v403][v404][v405][v406];	// L721
          v398[v403][v404][(v405 + 1)][(v406 + 1)] = v407;	// L722
        }
      }
    }
  }
  int8_t v408[1][32][640][192];	// L727
  // #pragma HLS stream variable=v408 depth=10 type=fifo

  #pragma HLS bind_storage variable=v408 type=ram_t2p impl=bram

  for (int v409 = 0; v409 < 1; v409 += 1) {	// L728
    for (int v410 = 0; v410 < 32; v410 += 1) {	// L729
      for (int v411 = 0; v411 < 640; v411 += 1) {	// L730
        for (int v412 = 0; v412 < 192; v412 += 1) {	// L731
          v408[v409][v410][v411][v412] = (int8_t)0.000000;	// L732
        }
      }
    }
  }
  for (int v413 = 0; v413 < 1; v413 += 1) {	// L737
    for (int v414 = 0; v414 < 32; v414 += 1) {	// L738
      for (int v415 = 0; v415 < 640; v415 += 1) {	// L739
        for (int v416 = 0; v416 < 192; v416 += 1) {	// L740
          for (int v417 = 0; v417 < 16; v417 += 1) {	// L741
            for (int v418 = 0; v418 < 3; v418 += 1) {	// L742
              for (int v419 = 0; v419 < 3; v419 += 1) {	// L743
                int8_t v420 = v398[v413][v417][(v415 + v418)][(v416 + v419)];	// L744
                int8_t v421 = v396[v414][v417][v418][v419];	// L745
                int8_t v422 = v408[v413][v414][v415][v416];	// L746
                int8_t v423 = v420 * v421;	// L747
                int8_t v424 = v422 + v423;	// L748
                v408[v413][v414][v415][v416] = v424;	// L749
              }
            }
          }
        }
      }
    }
  }
  for (int v425 = 0; v425 < 1; v425 += 1) {	// L757
    for (int v426 = 0; v426 < 32; v426 += 1) {	// L758
      for (int v427 = 0; v427 < 640; v427 += 1) {	// L759
        for (int v428 = 0; v428 < 192; v428 += 1) {	// L760
          int8_t v429 = v408[0][v426][v427][v428];	// L761
          bool v430 = v429 > (int8_t)0.000000;	// L762
          int8_t v431 = v430 ? v429 : (int8_t)0.000000;	// L763
          v397[v425][v426][v427][v428] = v431;	// L764
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v432[1][16][1280][384],
  int8_t v433[1][16][640][192]
) {	// L771
  // #pragma HLS dataflow

  for (int v434 = 0; v434 < 1; v434 += 1) {	// L773
    for (int v435 = 0; v435 < 16; v435 += 1) {	// L774
      for (int v436 = 0; v436 < 640; v436 += 1) {	// L775
        for (int v437 = 0; v437 < 192; v437 += 1) {	// L776
          v433[v434][v435][v436][v437] = (int8_t)-INFINITY;	// L777
        }
      }
    }
  }
  for (int v438 = 0; v438 < 1; v438 += 1) {	// L782
    for (int v439 = 0; v439 < 16; v439 += 1) {	// L783
      for (int v440 = 0; v440 < 640; v440 += 1) {	// L784
        for (int v441 = 0; v441 < 192; v441 += 1) {	// L785
          for (int v442 = 0; v442 < 2; v442 += 1) {	// L786
            for (int v443 = 0; v443 < 2; v443 += 1) {	// L787
              int8_t v444 = v432[v438][v439][((v440 * 2) + v442)][((v441 * 2) + v443)];	// L788
              int8_t v445 = v433[v438][v439][v440][v441];	// L789
              int8_t v446 = max(v445, v444);	// L790
              v433[v438][v439][v440][v441] = v446;	// L791
            }
          }
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v447[1][3][1280][384],
  int8_t v448[16][3][3][3],
  int8_t v449[1][16][1280][384]
) {	// L800
  // #pragma HLS dataflow

  int8_t v450[1][3][1282][386];	// L802
  // #pragma HLS stream variable=v450 depth=10 type=fifo

  #pragma HLS bind_storage variable=v450 type=ram_t2p impl=bram

  for (int v451 = 0; v451 < 1; v451 += 1) {	// L803
    for (int v452 = 0; v452 < 3; v452 += 1) {	// L804
      for (int v453 = 0; v453 < 1282; v453 += 1) {	// L805
        for (int v454 = 0; v454 < 386; v454 += 1) {	// L806
          v450[v451][v452][v453][v454] = (int8_t)0.000000;	// L807
        }
      }
    }
  }
  for (int v455 = 0; v455 < 1; v455 += 1) {	// L812
    for (int v456 = 0; v456 < 3; v456 += 1) {	// L813
      for (int v457 = 0; v457 < 1280; v457 += 1) {	// L814
        for (int v458 = 0; v458 < 384; v458 += 1) {	// L815
          int8_t v459 = v447[v455][v456][v457][v458];	// L816
          v450[v455][v456][(v457 + 1)][(v458 + 1)] = v459;	// L817
        }
      }
    }
  }
  int8_t v460[1][16][1280][384];	// L822
  // #pragma HLS stream variable=v460 depth=10 type=fifo

  #pragma HLS bind_storage variable=v460 type=ram_t2p impl=bram

  for (int v461 = 0; v461 < 1; v461 += 1) {	// L823
    for (int v462 = 0; v462 < 16; v462 += 1) {	// L824
      for (int v463 = 0; v463 < 1280; v463 += 1) {	// L825
        for (int v464 = 0; v464 < 384; v464 += 1) {	// L826
          v460[v461][v462][v463][v464] = (int8_t)0.000000;	// L827
        }
      }
    }
  }
  for (int v465 = 0; v465 < 1; v465 += 1) {	// L832
    for (int v466 = 0; v466 < 16; v466 += 1) {	// L833
      for (int v467 = 0; v467 < 1280; v467 += 1) {	// L834
        for (int v468 = 0; v468 < 384; v468 += 1) {	// L835
          for (int v469 = 0; v469 < 3; v469 += 1) {	// L836
            for (int v470 = 0; v470 < 3; v470 += 1) {	// L837
              for (int v471 = 0; v471 < 3; v471 += 1) {	// L838
                int8_t v472 = v450[v465][v469][(v467 + v470)][(v468 + v471)];	// L839
                int8_t v473 = v448[v466][v469][v470][v471];	// L840
                int8_t v474 = v460[v465][v466][v467][v468];	// L841
                int8_t v475 = v472 * v473;	// L842
                int8_t v476 = v474 + v475;	// L843
                v460[v465][v466][v467][v468] = v476;	// L844
              }
            }
          }
        }
      }
    }
  }
  for (int v477 = 0; v477 < 1; v477 += 1) {	// L852
    for (int v478 = 0; v478 < 16; v478 += 1) {	// L853
      for (int v479 = 0; v479 < 1280; v479 += 1) {	// L854
        for (int v480 = 0; v480 < 384; v480 += 1) {	// L855
          int8_t v481 = v460[0][v478][v479][v480];	// L856
          bool v482 = v481 > (int8_t)0.000000;	// L857
          int8_t v483 = v482 ? v481 : (int8_t)0.000000;	// L858
          v449[v477][v478][v479][v480] = v483;	// L859
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v484[1][3][1280][384],
  int8_t v485[1470],
  int8_t v486[4096],
  int8_t v487[256][1024][20][6],
  int8_t v488[1024][1024][3][3],
  int8_t v489[1024][512][3][3],
  int8_t v490[512][512][3][3],
  int8_t v491[512][256][3][3],
  int8_t v492[256][128][3][3],
  int8_t v493[128][64][3][3],
  int8_t v494[64][32][3][3],
  int8_t v495[32][16][3][3],
  int8_t v496[16][3][3][3],
  int8_t v497[256][4096],
  int8_t v498[4096][1470],
  int8_t v499[1][1470]
) {	// L866
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v484
  #pragma HLS bind_storage variable=v484 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v485
  #pragma HLS bind_storage variable=v485 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v486
  #pragma HLS bind_storage variable=v486 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v487
  #pragma HLS bind_storage variable=v487 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v488
  #pragma HLS bind_storage variable=v488 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v489
  #pragma HLS bind_storage variable=v489 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v490
  #pragma HLS bind_storage variable=v490 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v491
  #pragma HLS bind_storage variable=v491 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v492
  #pragma HLS bind_storage variable=v492 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v493
  #pragma HLS bind_storage variable=v493 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v494
  #pragma HLS bind_storage variable=v494 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v495
  #pragma HLS bind_storage variable=v495 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v496
  #pragma HLS bind_storage variable=v496 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v497
  #pragma HLS bind_storage variable=v497 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v498
  #pragma HLS bind_storage variable=v498 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v499
  #pragma HLS bind_storage variable=v499 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  int8_t v500[1][16][1280][384];	// L868
  // #pragma HLS stream variable=v500 depth=10 type=fifo

  #pragma HLS bind_storage variable=v500 type=ram_t2p impl=bram

  main_graph_node17(v484, v496, v500);	// L869       PCR
  int8_t v501[1][16][640][192];	// L870
  // #pragma HLS stream variable=v501 depth=10 type=fifo

  #pragma HLS bind_storage variable=v501 type=ram_t2p impl=bram

  main_graph_node16(v500, v501);	// L871       Pool
  int8_t v502[1][32][640][192];	// L872
  // #pragma HLS stream variable=v502 depth=10 type=fifo

  #pragma HLS bind_storage variable=v502 type=ram_t2p impl=bram

  main_graph_node15(v501, v495, v502);	// L873       PCR
  int8_t v503[1][32][320][96];	// L874
  // #pragma HLS stream variable=v503 depth=10 type=fifo

  #pragma HLS bind_storage variable=v503 type=ram_t2p impl=bram

  main_graph_node14(v502, v503);	// L875         Pool
  int8_t v504[1][64][320][96];	// L876
  // #pragma HLS stream variable=v504 depth=10 type=fifo

  #pragma HLS bind_storage variable=v504 type=ram_t2p impl=bram

  main_graph_node13(v494, v503, v504);	// L877
  int8_t v505[1][64][160][48];	// L878
  // #pragma HLS stream variable=v505 depth=10 type=fifo

  #pragma HLS bind_storage variable=v505 type=ram_t2p impl=bram

  main_graph_node12(v504, v505);	// L879
  int8_t v506[1][128][160][48];	// L880
  // #pragma HLS stream variable=v506 depth=10 type=fifo

  #pragma HLS bind_storage variable=v506 type=ram_t2p impl=bram

  main_graph_node11(v505, v493, v506);	// L881
  int8_t v507[1][128][80][24];	// L882
  // #pragma HLS stream variable=v507 depth=10 type=fifo

  #pragma HLS bind_storage variable=v507 type=ram_t2p impl=bram

  main_graph_node10(v506, v507);	// L883
  int8_t v508[1][256][80][24];	// L884
  // #pragma HLS stream variable=v508 depth=10 type=fifo

  #pragma HLS bind_storage variable=v508 type=ram_t2p impl=bram

  main_graph_node9(v492, v507, v508);	// L885
  int8_t v509[1][256][40][12];	// L886
  // #pragma HLS stream variable=v509 depth=10 type=fifo

  #pragma HLS bind_storage variable=v509 type=ram_t2p impl=bram

  main_graph_node8(v508, v509);	// L887
  int8_t v510[1][512][40][12];	// L888
  // #pragma HLS stream variable=v510 depth=10 type=fifo

  #pragma HLS bind_storage variable=v510 type=ram_t2p impl=bram

  main_graph_node7(v491, v509, v510);	// L889
  int8_t v511[1][512][20][6];	// L890
  // #pragma HLS stream variable=v511 depth=10 type=fifo

  #pragma HLS bind_storage variable=v511 type=ram_t2p impl=bram

  main_graph_node6(v510, v511);	// L891
  int8_t v512[1][512][20][6];	// L892
  // #pragma HLS stream variable=v512 depth=10 type=fifo

  #pragma HLS bind_storage variable=v512 type=ram_t2p impl=bram

  main_graph_node5(v511, v490, v512);	// L893
  int8_t v513[1][1024][20][6];	// L894
  // #pragma HLS stream variable=v513 depth=10 type=fifo

  #pragma HLS bind_storage variable=v513 type=ram_t2p impl=bram

  main_graph_node4(v512, v489, v513);	// L895
  int8_t v514[1][1024][20][6];	// L896
  // #pragma HLS stream variable=v514 depth=10 type=fifo

  #pragma HLS bind_storage variable=v514 type=ram_t2p impl=bram

  main_graph_node3(v513, v488, v514);	// L897
  int8_t v515[1][256][1][1];	// L898
  // #pragma HLS stream variable=v515 depth=10 type=fifo

  #pragma HLS bind_storage variable=v515 type=ram_t2p impl=bram

  main_graph_node2(v514, v487, v515);	// L899
  int8_t v516[1][4096];	// L900
  // #pragma HLS stream variable=v516 depth=10 type=fifo

  #pragma HLS bind_storage variable=v516 type=ram_t2p impl=bram

  main_graph_node1(v515, v497, v486, v516);	// L901
  main_graph_node0(v485, v498, v516, v499);	// L902
}

