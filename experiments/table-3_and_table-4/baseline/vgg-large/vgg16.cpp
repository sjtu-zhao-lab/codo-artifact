
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
  int8_t v0[2048][1000],
  int8_t v1[1][2048],
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
      for (int v9 = 0; v9 < 2048; v9 += 1) {	// L13
        int8_t v10 = v1[v7][v9];	// L14
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
      int8_t v18 = v2[v16];	// L26
      int8_t v19 = v17 + v18;	// L27
      v3[v15][v16] = v19;	// L28
    }
  }
}

void main_graph_node1(
  int8_t v20[1][2048][1][1],
  int8_t v21[2048],
  int8_t v22[2048][2048],
  int8_t v23[1][2048]
) {	// L33
  // #pragma HLS dataflow

  int8_t v24[1][2048];	// L35
  // #pragma HLS stream variable=v24 depth=10 type=fifo

  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L36
    for (int v26 = 0; v26 < 2048; v26 += 1) {	// L37
      v24[v25][v26] = (int8_t)0.000000;	// L38
    }
  }
  for (int v27 = 0; v27 < 1; v27 += 1) {	// L41
    for (int v28 = 0; v28 < 2048; v28 += 1) {	// L42
      for (int v29 = 0; v29 < 2048; v29 += 1) {	// L43
        int8_t v30 = v20[v27][v29][0][0];	// L44
        int8_t v31 = v22[v29][v28];	// L45
        int8_t v32 = v24[v27][v28];	// L46
        int8_t v33 = v30 * v31;	// L47
        int8_t v34 = v32 + v33;	// L48
        v24[v27][v28] = v34;	// L49
      }
    }
  }
  for (int v35 = 0; v35 < 1; v35 += 1) {	// L53
    for (int v36 = 0; v36 < 2048; v36 += 1) {	// L54
      int8_t v37 = v24[0][v36];	// L55
      int8_t v38 = v21[v36];	// L56
      int8_t v39 = v37 + v38;	// L57
      bool v40 = v39 > (int8_t)0.000000;	// L58
      int8_t v41 = v40 ? v39 : (int8_t)0.000000;	// L59
      v23[v35][v36] = v41;	// L60
    }
  }
}

void main_graph_node2(
  int8_t v42[2048][512][7][7],
  int8_t v43[1][512][7][7],
  int8_t v44[1][2048][1][1]
) {	// L65
  // #pragma HLS dataflow

  int8_t v45[1][2048][1][1];	// L67
  // #pragma HLS stream variable=v45 depth=10 type=fifo

  #pragma HLS bind_storage variable=v45 type=ram_t2p impl=bram

  for (int v46 = 0; v46 < 1; v46 += 1) {	// L68
    for (int v47 = 0; v47 < 2048; v47 += 1) {	// L69
      for (int v48 = 0; v48 < 1; v48 += 1) {	// L70
        for (int v49 = 0; v49 < 1; v49 += 1) {	// L71
          v45[v46][v47][v48][v49] = (int8_t)0.000000;	// L72
        }
      }
    }
  }
  for (int v50 = 0; v50 < 1; v50 += 1) {	// L77
    for (int v51 = 0; v51 < 2048; v51 += 1) {	// L78
      for (int v52 = 0; v52 < 1; v52 += 1) {	// L79
        for (int v53 = 0; v53 < 1; v53 += 1) {	// L80
          for (int v54 = 0; v54 < 512; v54 += 1) {	// L81
            for (int v55 = 0; v55 < 7; v55 += 1) {	// L82
              for (int v56 = 0; v56 < 7; v56 += 1) {	// L83
                int8_t v57 = v43[v50][v54][(v52 + v55)][(v53 + v56)];	// L84
                int8_t v58 = v42[v51][v54][v55][v56];	// L85
                int8_t v59 = v45[v50][v51][v52][v53];	// L86
                int8_t v60 = v57 * v58;	// L87
                int8_t v61 = v59 + v60;	// L88
                v45[v50][v51][v52][v53] = v61;	// L89
              }
            }
          }
        }
      }
    }
  }
  for (int v62 = 0; v62 < 1; v62 += 1) {	// L97
    for (int v63 = 0; v63 < 2048; v63 += 1) {	// L98
      for (int v64 = 0; v64 < 1; v64 += 1) {	// L99
        for (int v65 = 0; v65 < 1; v65 += 1) {	// L100
          int8_t v66 = v45[0][v63][0][0];	// L101
          bool v67 = v66 > (int8_t)0.000000;	// L102
          int8_t v68 = v67 ? v66 : (int8_t)0.000000;	// L103
          v44[v62][v63][v64][v65] = v68;	// L104
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v69[1][512][14][14],
  int8_t v70[1][512][7][7]
) {	// L111
  // #pragma HLS dataflow

  for (int v71 = 0; v71 < 1; v71 += 1) {	// L113
    for (int v72 = 0; v72 < 512; v72 += 1) {	// L114
      for (int v73 = 0; v73 < 7; v73 += 1) {	// L115
        for (int v74 = 0; v74 < 7; v74 += 1) {	// L116
          v70[v71][v72][v73][v74] = (int8_t)-INFINITY;	// L117
        }
      }
    }
  }
  for (int v75 = 0; v75 < 1; v75 += 1) {	// L122
    for (int v76 = 0; v76 < 512; v76 += 1) {	// L123
      for (int v77 = 0; v77 < 7; v77 += 1) {	// L124
        for (int v78 = 0; v78 < 7; v78 += 1) {	// L125
          for (int v79 = 0; v79 < 2; v79 += 1) {	// L126
            for (int v80 = 0; v80 < 2; v80 += 1) {	// L127
              int8_t v81 = v69[v75][v76][((v77 * 2) + v79)][((v78 * 2) + v80)];	// L128
              int8_t v82 = v70[v75][v76][v77][v78];	// L129
              int8_t v83 = max(v82, v81);	// L130
              v70[v75][v76][v77][v78] = v83;	// L131
            }
          }
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v84[1][512][14][14],
  int8_t v85[512][512][3][3],
  int8_t v86[1][512][14][14]
) {	// L140
  // #pragma HLS dataflow

  int8_t v87[1][512][16][16];	// L142
  // #pragma HLS stream variable=v87 depth=10 type=fifo

  #pragma HLS bind_storage variable=v87 type=ram_t2p impl=bram

  for (int v88 = 0; v88 < 1; v88 += 1) {	// L143
    for (int v89 = 0; v89 < 512; v89 += 1) {	// L144
      for (int v90 = 0; v90 < 16; v90 += 1) {	// L145
        for (int v91 = 0; v91 < 16; v91 += 1) {	// L146
          v87[v88][v89][v90][v91] = (int8_t)0.000000;	// L147
        }
      }
    }
  }
  for (int v92 = 0; v92 < 1; v92 += 1) {	// L152
    for (int v93 = 0; v93 < 512; v93 += 1) {	// L153
      for (int v94 = 0; v94 < 14; v94 += 1) {	// L154
        for (int v95 = 0; v95 < 14; v95 += 1) {	// L155
          int8_t v96 = v84[v92][v93][v94][v95];	// L156
          v87[v92][v93][(v94 + 1)][(v95 + 1)] = v96;	// L157
        }
      }
    }
  }
  int8_t v97[1][512][14][14];	// L162
  // #pragma HLS stream variable=v97 depth=10 type=fifo

  #pragma HLS bind_storage variable=v97 type=ram_t2p impl=bram

  for (int v98 = 0; v98 < 1; v98 += 1) {	// L163
    for (int v99 = 0; v99 < 512; v99 += 1) {	// L164
      for (int v100 = 0; v100 < 14; v100 += 1) {	// L165
        for (int v101 = 0; v101 < 14; v101 += 1) {	// L166
          v97[v98][v99][v100][v101] = (int8_t)0.000000;	// L167
        }
      }
    }
  }
  for (int v102 = 0; v102 < 1; v102 += 1) {	// L172
    for (int v103 = 0; v103 < 512; v103 += 1) {	// L173
      for (int v104 = 0; v104 < 14; v104 += 1) {	// L174
        for (int v105 = 0; v105 < 14; v105 += 1) {	// L175
          for (int v106 = 0; v106 < 512; v106 += 1) {	// L176
            for (int v107 = 0; v107 < 3; v107 += 1) {	// L177
              for (int v108 = 0; v108 < 3; v108 += 1) {	// L178
                int8_t v109 = v87[v102][v106][(v104 + v107)][(v105 + v108)];	// L179
                int8_t v110 = v85[v103][v106][v107][v108];	// L180
                int8_t v111 = v97[v102][v103][v104][v105];	// L181
                int8_t v112 = v109 * v110;	// L182
                int8_t v113 = v111 + v112;	// L183
                v97[v102][v103][v104][v105] = v113;	// L184
              }
            }
          }
        }
      }
    }
  }
  for (int v114 = 0; v114 < 1; v114 += 1) {	// L192
    for (int v115 = 0; v115 < 512; v115 += 1) {	// L193
      for (int v116 = 0; v116 < 14; v116 += 1) {	// L194
        for (int v117 = 0; v117 < 14; v117 += 1) {	// L195
          int8_t v118 = v97[0][v115][v116][v117];	// L196
          bool v119 = v118 > (int8_t)0.000000;	// L197
          int8_t v120 = v119 ? v118 : (int8_t)0.000000;	// L198
          v86[v114][v115][v116][v117] = v120;	// L199
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v121[1][512][14][14],
  int8_t v122[512][512][3][3],
  int8_t v123[1][512][14][14]
) {	// L206
  // #pragma HLS dataflow

  int8_t v124[1][512][16][16];	// L208
  // #pragma HLS stream variable=v124 depth=10 type=fifo

  #pragma HLS bind_storage variable=v124 type=ram_t2p impl=bram

  for (int v125 = 0; v125 < 1; v125 += 1) {	// L209
    for (int v126 = 0; v126 < 512; v126 += 1) {	// L210
      for (int v127 = 0; v127 < 16; v127 += 1) {	// L211
        for (int v128 = 0; v128 < 16; v128 += 1) {	// L212
          v124[v125][v126][v127][v128] = (int8_t)0.000000;	// L213
        }
      }
    }
  }
  for (int v129 = 0; v129 < 1; v129 += 1) {	// L218
    for (int v130 = 0; v130 < 512; v130 += 1) {	// L219
      for (int v131 = 0; v131 < 14; v131 += 1) {	// L220
        for (int v132 = 0; v132 < 14; v132 += 1) {	// L221
          int8_t v133 = v121[v129][v130][v131][v132];	// L222
          v124[v129][v130][(v131 + 1)][(v132 + 1)] = v133;	// L223
        }
      }
    }
  }
  int8_t v134[1][512][14][14];	// L228
  // #pragma HLS stream variable=v134 depth=10 type=fifo

  #pragma HLS bind_storage variable=v134 type=ram_t2p impl=bram

  for (int v135 = 0; v135 < 1; v135 += 1) {	// L229
    for (int v136 = 0; v136 < 512; v136 += 1) {	// L230
      for (int v137 = 0; v137 < 14; v137 += 1) {	// L231
        for (int v138 = 0; v138 < 14; v138 += 1) {	// L232
          v134[v135][v136][v137][v138] = (int8_t)0.000000;	// L233
        }
      }
    }
  }
  for (int v139 = 0; v139 < 1; v139 += 1) {	// L238
    for (int v140 = 0; v140 < 512; v140 += 1) {	// L239
      for (int v141 = 0; v141 < 14; v141 += 1) {	// L240
        for (int v142 = 0; v142 < 14; v142 += 1) {	// L241
          for (int v143 = 0; v143 < 512; v143 += 1) {	// L242
            for (int v144 = 0; v144 < 3; v144 += 1) {	// L243
              for (int v145 = 0; v145 < 3; v145 += 1) {	// L244
                int8_t v146 = v124[v139][v143][(v141 + v144)][(v142 + v145)];	// L245
                int8_t v147 = v122[v140][v143][v144][v145];	// L246
                int8_t v148 = v134[v139][v140][v141][v142];	// L247
                int8_t v149 = v146 * v147;	// L248
                int8_t v150 = v148 + v149;	// L249
                v134[v139][v140][v141][v142] = v150;	// L250
              }
            }
          }
        }
      }
    }
  }
  for (int v151 = 0; v151 < 1; v151 += 1) {	// L258
    for (int v152 = 0; v152 < 512; v152 += 1) {	// L259
      for (int v153 = 0; v153 < 14; v153 += 1) {	// L260
        for (int v154 = 0; v154 < 14; v154 += 1) {	// L261
          int8_t v155 = v134[0][v152][v153][v154];	// L262
          bool v156 = v155 > (int8_t)0.000000;	// L263
          int8_t v157 = v156 ? v155 : (int8_t)0.000000;	// L264
          v123[v151][v152][v153][v154] = v157;	// L265
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v158[512][256][3][3],
  int8_t v159[1][256][14][14],
  int8_t v160[1][512][14][14]
) {	// L272
  // #pragma HLS dataflow

  int8_t v161[1][256][16][16];	// L274
  // #pragma HLS stream variable=v161 depth=10 type=fifo

  #pragma HLS bind_storage variable=v161 type=ram_t2p impl=bram

  for (int v162 = 0; v162 < 1; v162 += 1) {	// L275
    for (int v163 = 0; v163 < 256; v163 += 1) {	// L276
      for (int v164 = 0; v164 < 16; v164 += 1) {	// L277
        for (int v165 = 0; v165 < 16; v165 += 1) {	// L278
          v161[v162][v163][v164][v165] = (int8_t)0.000000;	// L279
        }
      }
    }
  }
  for (int v166 = 0; v166 < 1; v166 += 1) {	// L284
    for (int v167 = 0; v167 < 256; v167 += 1) {	// L285
      for (int v168 = 0; v168 < 14; v168 += 1) {	// L286
        for (int v169 = 0; v169 < 14; v169 += 1) {	// L287
          int8_t v170 = v159[v166][v167][v168][v169];	// L288
          v161[v166][v167][(v168 + 1)][(v169 + 1)] = v170;	// L289
        }
      }
    }
  }
  int8_t v171[1][512][14][14];	// L294
  // #pragma HLS stream variable=v171 depth=10 type=fifo

  #pragma HLS bind_storage variable=v171 type=ram_t2p impl=bram

  for (int v172 = 0; v172 < 1; v172 += 1) {	// L295
    for (int v173 = 0; v173 < 512; v173 += 1) {	// L296
      for (int v174 = 0; v174 < 14; v174 += 1) {	// L297
        for (int v175 = 0; v175 < 14; v175 += 1) {	// L298
          v171[v172][v173][v174][v175] = (int8_t)0.000000;	// L299
        }
      }
    }
  }
  for (int v176 = 0; v176 < 1; v176 += 1) {	// L304
    for (int v177 = 0; v177 < 512; v177 += 1) {	// L305
      for (int v178 = 0; v178 < 14; v178 += 1) {	// L306
        for (int v179 = 0; v179 < 14; v179 += 1) {	// L307
          for (int v180 = 0; v180 < 256; v180 += 1) {	// L308
            for (int v181 = 0; v181 < 3; v181 += 1) {	// L309
              for (int v182 = 0; v182 < 3; v182 += 1) {	// L310
                int8_t v183 = v161[v176][v180][(v178 + v181)][(v179 + v182)];	// L311
                int8_t v184 = v158[v177][v180][v181][v182];	// L312
                int8_t v185 = v171[v176][v177][v178][v179];	// L313
                int8_t v186 = v183 * v184;	// L314
                int8_t v187 = v185 + v186;	// L315
                v171[v176][v177][v178][v179] = v187;	// L316
              }
            }
          }
        }
      }
    }
  }
  for (int v188 = 0; v188 < 1; v188 += 1) {	// L324
    for (int v189 = 0; v189 < 512; v189 += 1) {	// L325
      for (int v190 = 0; v190 < 14; v190 += 1) {	// L326
        for (int v191 = 0; v191 < 14; v191 += 1) {	// L327
          int8_t v192 = v171[0][v189][v190][v191];	// L328
          bool v193 = v192 > (int8_t)0.000000;	// L329
          int8_t v194 = v193 ? v192 : (int8_t)0.000000;	// L330
          v160[v188][v189][v190][v191] = v194;	// L331
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v195[1][256][28][28],
  int8_t v196[1][256][14][14]
) {	// L338
  // #pragma HLS dataflow

  for (int v197 = 0; v197 < 1; v197 += 1) {	// L340
    for (int v198 = 0; v198 < 256; v198 += 1) {	// L341
      for (int v199 = 0; v199 < 14; v199 += 1) {	// L342
        for (int v200 = 0; v200 < 14; v200 += 1) {	// L343
          v196[v197][v198][v199][v200] = (int8_t)-INFINITY;	// L344
        }
      }
    }
  }
  for (int v201 = 0; v201 < 1; v201 += 1) {	// L349
    for (int v202 = 0; v202 < 256; v202 += 1) {	// L350
      for (int v203 = 0; v203 < 14; v203 += 1) {	// L351
        for (int v204 = 0; v204 < 14; v204 += 1) {	// L352
          for (int v205 = 0; v205 < 2; v205 += 1) {	// L353
            for (int v206 = 0; v206 < 2; v206 += 1) {	// L354
              int8_t v207 = v195[v201][v202][((v203 * 2) + v205)][((v204 * 2) + v206)];	// L355
              int8_t v208 = v196[v201][v202][v203][v204];	// L356
              int8_t v209 = max(v208, v207);	// L357
              v196[v201][v202][v203][v204] = v209;	// L358
            }
          }
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v210[256][256][3][3],
  int8_t v211[1][256][28][28],
  int8_t v212[1][256][28][28]
) {	// L367
  // #pragma HLS dataflow

  int8_t v213[1][256][30][30];	// L369
  // #pragma HLS stream variable=v213 depth=10 type=fifo

  #pragma HLS bind_storage variable=v213 type=ram_t2p impl=bram

  for (int v214 = 0; v214 < 1; v214 += 1) {	// L370
    for (int v215 = 0; v215 < 256; v215 += 1) {	// L371
      for (int v216 = 0; v216 < 30; v216 += 1) {	// L372
        for (int v217 = 0; v217 < 30; v217 += 1) {	// L373
          v213[v214][v215][v216][v217] = (int8_t)0.000000;	// L374
        }
      }
    }
  }
  for (int v218 = 0; v218 < 1; v218 += 1) {	// L379
    for (int v219 = 0; v219 < 256; v219 += 1) {	// L380
      for (int v220 = 0; v220 < 28; v220 += 1) {	// L381
        for (int v221 = 0; v221 < 28; v221 += 1) {	// L382
          int8_t v222 = v211[v218][v219][v220][v221];	// L383
          v213[v218][v219][(v220 + 1)][(v221 + 1)] = v222;	// L384
        }
      }
    }
  }
  int8_t v223[1][256][28][28];	// L389
  // #pragma HLS stream variable=v223 depth=10 type=fifo

  #pragma HLS bind_storage variable=v223 type=ram_t2p impl=bram

  for (int v224 = 0; v224 < 1; v224 += 1) {	// L390
    for (int v225 = 0; v225 < 256; v225 += 1) {	// L391
      for (int v226 = 0; v226 < 28; v226 += 1) {	// L392
        for (int v227 = 0; v227 < 28; v227 += 1) {	// L393
          v223[v224][v225][v226][v227] = (int8_t)0.000000;	// L394
        }
      }
    }
  }
  for (int v228 = 0; v228 < 1; v228 += 1) {	// L399
    for (int v229 = 0; v229 < 256; v229 += 1) {	// L400
      for (int v230 = 0; v230 < 28; v230 += 1) {	// L401
        for (int v231 = 0; v231 < 28; v231 += 1) {	// L402
          for (int v232 = 0; v232 < 256; v232 += 1) {	// L403
            for (int v233 = 0; v233 < 3; v233 += 1) {	// L404
              for (int v234 = 0; v234 < 3; v234 += 1) {	// L405
                int8_t v235 = v213[v228][v232][(v230 + v233)][(v231 + v234)];	// L406
                int8_t v236 = v210[v229][v232][v233][v234];	// L407
                int8_t v237 = v223[v228][v229][v230][v231];	// L408
                int8_t v238 = v235 * v236;	// L409
                int8_t v239 = v237 + v238;	// L410
                v223[v228][v229][v230][v231] = v239;	// L411
              }
            }
          }
        }
      }
    }
  }
  for (int v240 = 0; v240 < 1; v240 += 1) {	// L419
    for (int v241 = 0; v241 < 256; v241 += 1) {	// L420
      for (int v242 = 0; v242 < 28; v242 += 1) {	// L421
        for (int v243 = 0; v243 < 28; v243 += 1) {	// L422
          int8_t v244 = v223[0][v241][v242][v243];	// L423
          bool v245 = v244 > (int8_t)0.000000;	// L424
          int8_t v246 = v245 ? v244 : (int8_t)0.000000;	// L425
          v212[v240][v241][v242][v243] = v246;	// L426
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v247[1][256][28][28],
  int8_t v248[256][256][3][3],
  int8_t v249[1][256][28][28]
) {	// L433
  // #pragma HLS dataflow

  int8_t v250[1][256][30][30];	// L435
  // #pragma HLS stream variable=v250 depth=10 type=fifo

  #pragma HLS bind_storage variable=v250 type=ram_t2p impl=bram

  for (int v251 = 0; v251 < 1; v251 += 1) {	// L436
    for (int v252 = 0; v252 < 256; v252 += 1) {	// L437
      for (int v253 = 0; v253 < 30; v253 += 1) {	// L438
        for (int v254 = 0; v254 < 30; v254 += 1) {	// L439
          v250[v251][v252][v253][v254] = (int8_t)0.000000;	// L440
        }
      }
    }
  }
  for (int v255 = 0; v255 < 1; v255 += 1) {	// L445
    for (int v256 = 0; v256 < 256; v256 += 1) {	// L446
      for (int v257 = 0; v257 < 28; v257 += 1) {	// L447
        for (int v258 = 0; v258 < 28; v258 += 1) {	// L448
          int8_t v259 = v247[v255][v256][v257][v258];	// L449
          v250[v255][v256][(v257 + 1)][(v258 + 1)] = v259;	// L450
        }
      }
    }
  }
  int8_t v260[1][256][28][28];	// L455
  // #pragma HLS stream variable=v260 depth=10 type=fifo

  #pragma HLS bind_storage variable=v260 type=ram_t2p impl=bram

  for (int v261 = 0; v261 < 1; v261 += 1) {	// L456
    for (int v262 = 0; v262 < 256; v262 += 1) {	// L457
      for (int v263 = 0; v263 < 28; v263 += 1) {	// L458
        for (int v264 = 0; v264 < 28; v264 += 1) {	// L459
          v260[v261][v262][v263][v264] = (int8_t)0.000000;	// L460
        }
      }
    }
  }
  for (int v265 = 0; v265 < 1; v265 += 1) {	// L465
    for (int v266 = 0; v266 < 256; v266 += 1) {	// L466
      for (int v267 = 0; v267 < 28; v267 += 1) {	// L467
        for (int v268 = 0; v268 < 28; v268 += 1) {	// L468
          for (int v269 = 0; v269 < 256; v269 += 1) {	// L469
            for (int v270 = 0; v270 < 3; v270 += 1) {	// L470
              for (int v271 = 0; v271 < 3; v271 += 1) {	// L471
                int8_t v272 = v250[v265][v269][(v267 + v270)][(v268 + v271)];	// L472
                int8_t v273 = v248[v266][v269][v270][v271];	// L473
                int8_t v274 = v260[v265][v266][v267][v268];	// L474
                int8_t v275 = v272 * v273;	// L475
                int8_t v276 = v274 + v275;	// L476
                v260[v265][v266][v267][v268] = v276;	// L477
              }
            }
          }
        }
      }
    }
  }
  for (int v277 = 0; v277 < 1; v277 += 1) {	// L485
    for (int v278 = 0; v278 < 256; v278 += 1) {	// L486
      for (int v279 = 0; v279 < 28; v279 += 1) {	// L487
        for (int v280 = 0; v280 < 28; v280 += 1) {	// L488
          int8_t v281 = v260[0][v278][v279][v280];	// L489
          bool v282 = v281 > (int8_t)0.000000;	// L490
          int8_t v283 = v282 ? v281 : (int8_t)0.000000;	// L491
          v249[v277][v278][v279][v280] = v283;	// L492
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v284[1][128][28][28],
  int8_t v285[256][128][3][3],
  int8_t v286[1][256][28][28]
) {	// L499
  // #pragma HLS dataflow

  int8_t v287[1][128][30][30];	// L501
  // #pragma HLS stream variable=v287 depth=10 type=fifo

  #pragma HLS bind_storage variable=v287 type=ram_t2p impl=bram

  for (int v288 = 0; v288 < 1; v288 += 1) {	// L502
    for (int v289 = 0; v289 < 128; v289 += 1) {	// L503
      for (int v290 = 0; v290 < 30; v290 += 1) {	// L504
        for (int v291 = 0; v291 < 30; v291 += 1) {	// L505
          v287[v288][v289][v290][v291] = (int8_t)0.000000;	// L506
        }
      }
    }
  }
  for (int v292 = 0; v292 < 1; v292 += 1) {	// L511
    for (int v293 = 0; v293 < 128; v293 += 1) {	// L512
      for (int v294 = 0; v294 < 28; v294 += 1) {	// L513
        for (int v295 = 0; v295 < 28; v295 += 1) {	// L514
          int8_t v296 = v284[v292][v293][v294][v295];	// L515
          v287[v292][v293][(v294 + 1)][(v295 + 1)] = v296;	// L516
        }
      }
    }
  }
  int8_t v297[1][256][28][28];	// L521
  // #pragma HLS stream variable=v297 depth=10 type=fifo

  #pragma HLS bind_storage variable=v297 type=ram_t2p impl=bram

  for (int v298 = 0; v298 < 1; v298 += 1) {	// L522
    for (int v299 = 0; v299 < 256; v299 += 1) {	// L523
      for (int v300 = 0; v300 < 28; v300 += 1) {	// L524
        for (int v301 = 0; v301 < 28; v301 += 1) {	// L525
          v297[v298][v299][v300][v301] = (int8_t)0.000000;	// L526
        }
      }
    }
  }
  for (int v302 = 0; v302 < 1; v302 += 1) {	// L531
    for (int v303 = 0; v303 < 256; v303 += 1) {	// L532
      for (int v304 = 0; v304 < 28; v304 += 1) {	// L533
        for (int v305 = 0; v305 < 28; v305 += 1) {	// L534
          for (int v306 = 0; v306 < 128; v306 += 1) {	// L535
            for (int v307 = 0; v307 < 3; v307 += 1) {	// L536
              for (int v308 = 0; v308 < 3; v308 += 1) {	// L537
                int8_t v309 = v287[v302][v306][(v304 + v307)][(v305 + v308)];	// L538
                int8_t v310 = v285[v303][v306][v307][v308];	// L539
                int8_t v311 = v297[v302][v303][v304][v305];	// L540
                int8_t v312 = v309 * v310;	// L541
                int8_t v313 = v311 + v312;	// L542
                v297[v302][v303][v304][v305] = v313;	// L543
              }
            }
          }
        }
      }
    }
  }
  for (int v314 = 0; v314 < 1; v314 += 1) {	// L551
    for (int v315 = 0; v315 < 256; v315 += 1) {	// L552
      for (int v316 = 0; v316 < 28; v316 += 1) {	// L553
        for (int v317 = 0; v317 < 28; v317 += 1) {	// L554
          int8_t v318 = v297[0][v315][v316][v317];	// L555
          bool v319 = v318 > (int8_t)0.000000;	// L556
          int8_t v320 = v319 ? v318 : (int8_t)0.000000;	// L557
          v286[v314][v315][v316][v317] = v320;	// L558
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v321[1][128][56][56],
  int8_t v322[1][128][28][28]
) {	// L565
  // #pragma HLS dataflow

  for (int v323 = 0; v323 < 1; v323 += 1) {	// L567
    for (int v324 = 0; v324 < 128; v324 += 1) {	// L568
      for (int v325 = 0; v325 < 28; v325 += 1) {	// L569
        for (int v326 = 0; v326 < 28; v326 += 1) {	// L570
          v322[v323][v324][v325][v326] = (int8_t)-INFINITY;	// L571
        }
      }
    }
  }
  for (int v327 = 0; v327 < 1; v327 += 1) {	// L576
    for (int v328 = 0; v328 < 128; v328 += 1) {	// L577
      for (int v329 = 0; v329 < 28; v329 += 1) {	// L578
        for (int v330 = 0; v330 < 28; v330 += 1) {	// L579
          for (int v331 = 0; v331 < 2; v331 += 1) {	// L580
            for (int v332 = 0; v332 < 2; v332 += 1) {	// L581
              int8_t v333 = v321[v327][v328][((v329 * 2) + v331)][((v330 * 2) + v332)];	// L582
              int8_t v334 = v322[v327][v328][v329][v330];	// L583
              int8_t v335 = max(v334, v333);	// L584
              v322[v327][v328][v329][v330] = v335;	// L585
            }
          }
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v336[1][128][56][56],
  int8_t v337[128][128][3][3],
  int8_t v338[1][128][56][56]
) {	// L594
  // #pragma HLS dataflow

  int8_t v339[1][128][58][58];	// L596
  // #pragma HLS stream variable=v339 depth=10 type=fifo

  #pragma HLS bind_storage variable=v339 type=ram_t2p impl=bram

  for (int v340 = 0; v340 < 1; v340 += 1) {	// L597
    for (int v341 = 0; v341 < 128; v341 += 1) {	// L598
      for (int v342 = 0; v342 < 58; v342 += 1) {	// L599
        for (int v343 = 0; v343 < 58; v343 += 1) {	// L600
          v339[v340][v341][v342][v343] = (int8_t)0.000000;	// L601
        }
      }
    }
  }
  for (int v344 = 0; v344 < 1; v344 += 1) {	// L606
    for (int v345 = 0; v345 < 128; v345 += 1) {	// L607
      for (int v346 = 0; v346 < 56; v346 += 1) {	// L608
        for (int v347 = 0; v347 < 56; v347 += 1) {	// L609
          int8_t v348 = v336[v344][v345][v346][v347];	// L610
          v339[v344][v345][(v346 + 1)][(v347 + 1)] = v348;	// L611
        }
      }
    }
  }
  int8_t v349[1][128][56][56];	// L616
  // #pragma HLS stream variable=v349 depth=10 type=fifo

  #pragma HLS bind_storage variable=v349 type=ram_t2p impl=bram

  for (int v350 = 0; v350 < 1; v350 += 1) {	// L617
    for (int v351 = 0; v351 < 128; v351 += 1) {	// L618
      for (int v352 = 0; v352 < 56; v352 += 1) {	// L619
        for (int v353 = 0; v353 < 56; v353 += 1) {	// L620
          v349[v350][v351][v352][v353] = (int8_t)0.000000;	// L621
        }
      }
    }
  }
  for (int v354 = 0; v354 < 1; v354 += 1) {	// L626
    for (int v355 = 0; v355 < 128; v355 += 1) {	// L627
      for (int v356 = 0; v356 < 56; v356 += 1) {	// L628
        for (int v357 = 0; v357 < 56; v357 += 1) {	// L629
          for (int v358 = 0; v358 < 128; v358 += 1) {	// L630
            for (int v359 = 0; v359 < 3; v359 += 1) {	// L631
              for (int v360 = 0; v360 < 3; v360 += 1) {	// L632
                int8_t v361 = v339[v354][v358][(v356 + v359)][(v357 + v360)];	// L633
                int8_t v362 = v337[v355][v358][v359][v360];	// L634
                int8_t v363 = v349[v354][v355][v356][v357];	// L635
                int8_t v364 = v361 * v362;	// L636
                int8_t v365 = v363 + v364;	// L637
                v349[v354][v355][v356][v357] = v365;	// L638
              }
            }
          }
        }
      }
    }
  }
  for (int v366 = 0; v366 < 1; v366 += 1) {	// L646
    for (int v367 = 0; v367 < 128; v367 += 1) {	// L647
      for (int v368 = 0; v368 < 56; v368 += 1) {	// L648
        for (int v369 = 0; v369 < 56; v369 += 1) {	// L649
          int8_t v370 = v349[0][v367][v368][v369];	// L650
          bool v371 = v370 > (int8_t)0.000000;	// L651
          int8_t v372 = v371 ? v370 : (int8_t)0.000000;	// L652
          v338[v366][v367][v368][v369] = v372;	// L653
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v373[1][128][56][56],
  int8_t v374[128][128][3][3],
  int8_t v375[1][128][56][56]
) {	// L660
  // #pragma HLS dataflow

  int8_t v376[1][128][58][58];	// L662
  // #pragma HLS stream variable=v376 depth=10 type=fifo

  #pragma HLS bind_storage variable=v376 type=ram_t2p impl=bram

  for (int v377 = 0; v377 < 1; v377 += 1) {	// L663
    for (int v378 = 0; v378 < 128; v378 += 1) {	// L664
      for (int v379 = 0; v379 < 58; v379 += 1) {	// L665
        for (int v380 = 0; v380 < 58; v380 += 1) {	// L666
          v376[v377][v378][v379][v380] = (int8_t)0.000000;	// L667
        }
      }
    }
  }
  for (int v381 = 0; v381 < 1; v381 += 1) {	// L672
    for (int v382 = 0; v382 < 128; v382 += 1) {	// L673
      for (int v383 = 0; v383 < 56; v383 += 1) {	// L674
        for (int v384 = 0; v384 < 56; v384 += 1) {	// L675
          int8_t v385 = v373[v381][v382][v383][v384];	// L676
          v376[v381][v382][(v383 + 1)][(v384 + 1)] = v385;	// L677
        }
      }
    }
  }
  int8_t v386[1][128][56][56];	// L682
  // #pragma HLS stream variable=v386 depth=10 type=fifo

  #pragma HLS bind_storage variable=v386 type=ram_t2p impl=bram

  for (int v387 = 0; v387 < 1; v387 += 1) {	// L683
    for (int v388 = 0; v388 < 128; v388 += 1) {	// L684
      for (int v389 = 0; v389 < 56; v389 += 1) {	// L685
        for (int v390 = 0; v390 < 56; v390 += 1) {	// L686
          v386[v387][v388][v389][v390] = (int8_t)0.000000;	// L687
        }
      }
    }
  }
  for (int v391 = 0; v391 < 1; v391 += 1) {	// L692
    for (int v392 = 0; v392 < 128; v392 += 1) {	// L693
      for (int v393 = 0; v393 < 56; v393 += 1) {	// L694
        for (int v394 = 0; v394 < 56; v394 += 1) {	// L695
          for (int v395 = 0; v395 < 128; v395 += 1) {	// L696
            for (int v396 = 0; v396 < 3; v396 += 1) {	// L697
              for (int v397 = 0; v397 < 3; v397 += 1) {	// L698
                int8_t v398 = v376[v391][v395][(v393 + v396)][(v394 + v397)];	// L699
                int8_t v399 = v374[v392][v395][v396][v397];	// L700
                int8_t v400 = v386[v391][v392][v393][v394];	// L701
                int8_t v401 = v398 * v399;	// L702
                int8_t v402 = v400 + v401;	// L703
                v386[v391][v392][v393][v394] = v402;	// L704
              }
            }
          }
        }
      }
    }
  }
  for (int v403 = 0; v403 < 1; v403 += 1) {	// L712
    for (int v404 = 0; v404 < 128; v404 += 1) {	// L713
      for (int v405 = 0; v405 < 56; v405 += 1) {	// L714
        for (int v406 = 0; v406 < 56; v406 += 1) {	// L715
          int8_t v407 = v386[0][v404][v405][v406];	// L716
          bool v408 = v407 > (int8_t)0.000000;	// L717
          int8_t v409 = v408 ? v407 : (int8_t)0.000000;	// L718
          v375[v403][v404][v405][v406] = v409;	// L719
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v410[1][64][56][56],
  int8_t v411[128][64][3][3],
  int8_t v412[1][128][56][56]
) {	// L726
  // #pragma HLS dataflow

  int8_t v413[1][64][58][58];	// L728
  // #pragma HLS stream variable=v413 depth=10 type=fifo

  #pragma HLS bind_storage variable=v413 type=ram_t2p impl=bram

  for (int v414 = 0; v414 < 1; v414 += 1) {	// L729
    for (int v415 = 0; v415 < 64; v415 += 1) {	// L730
      for (int v416 = 0; v416 < 58; v416 += 1) {	// L731
        for (int v417 = 0; v417 < 58; v417 += 1) {	// L732
          v413[v414][v415][v416][v417] = (int8_t)0.000000;	// L733
        }
      }
    }
  }
  for (int v418 = 0; v418 < 1; v418 += 1) {	// L738
    for (int v419 = 0; v419 < 64; v419 += 1) {	// L739
      for (int v420 = 0; v420 < 56; v420 += 1) {	// L740
        for (int v421 = 0; v421 < 56; v421 += 1) {	// L741
          int8_t v422 = v410[v418][v419][v420][v421];	// L742
          v413[v418][v419][(v420 + 1)][(v421 + 1)] = v422;	// L743
        }
      }
    }
  }
  int8_t v423[1][128][56][56];	// L748
  // #pragma HLS stream variable=v423 depth=10 type=fifo

  #pragma HLS bind_storage variable=v423 type=ram_t2p impl=bram

  for (int v424 = 0; v424 < 1; v424 += 1) {	// L749
    for (int v425 = 0; v425 < 128; v425 += 1) {	// L750
      for (int v426 = 0; v426 < 56; v426 += 1) {	// L751
        for (int v427 = 0; v427 < 56; v427 += 1) {	// L752
          v423[v424][v425][v426][v427] = (int8_t)0.000000;	// L753
        }
      }
    }
  }
  for (int v428 = 0; v428 < 1; v428 += 1) {	// L758
    for (int v429 = 0; v429 < 128; v429 += 1) {	// L759
      for (int v430 = 0; v430 < 56; v430 += 1) {	// L760
        for (int v431 = 0; v431 < 56; v431 += 1) {	// L761
          for (int v432 = 0; v432 < 64; v432 += 1) {	// L762
            for (int v433 = 0; v433 < 3; v433 += 1) {	// L763
              for (int v434 = 0; v434 < 3; v434 += 1) {	// L764
                int8_t v435 = v413[v428][v432][(v430 + v433)][(v431 + v434)];	// L765
                int8_t v436 = v411[v429][v432][v433][v434];	// L766
                int8_t v437 = v423[v428][v429][v430][v431];	// L767
                int8_t v438 = v435 * v436;	// L768
                int8_t v439 = v437 + v438;	// L769
                v423[v428][v429][v430][v431] = v439;	// L770
              }
            }
          }
        }
      }
    }
  }
  for (int v440 = 0; v440 < 1; v440 += 1) {	// L778
    for (int v441 = 0; v441 < 128; v441 += 1) {	// L779
      for (int v442 = 0; v442 < 56; v442 += 1) {	// L780
        for (int v443 = 0; v443 < 56; v443 += 1) {	// L781
          int8_t v444 = v423[0][v441][v442][v443];	// L782
          bool v445 = v444 > (int8_t)0.000000;	// L783
          int8_t v446 = v445 ? v444 : (int8_t)0.000000;	// L784
          v412[v440][v441][v442][v443] = v446;	// L785
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v447[1][64][112][112],
  int8_t v448[1][64][56][56]
) {	// L792
  // #pragma HLS dataflow

  for (int v449 = 0; v449 < 1; v449 += 1) {	// L794
    for (int v450 = 0; v450 < 64; v450 += 1) {	// L795
      for (int v451 = 0; v451 < 56; v451 += 1) {	// L796
        for (int v452 = 0; v452 < 56; v452 += 1) {	// L797
          v448[v449][v450][v451][v452] = (int8_t)-INFINITY;	// L798
        }
      }
    }
  }
  for (int v453 = 0; v453 < 1; v453 += 1) {	// L803
    for (int v454 = 0; v454 < 64; v454 += 1) {	// L804
      for (int v455 = 0; v455 < 56; v455 += 1) {	// L805
        for (int v456 = 0; v456 < 56; v456 += 1) {	// L806
          for (int v457 = 0; v457 < 2; v457 += 1) {	// L807
            for (int v458 = 0; v458 < 2; v458 += 1) {	// L808
              int8_t v459 = v447[v453][v454][((v455 * 2) + v457)][((v456 * 2) + v458)];	// L809
              int8_t v460 = v448[v453][v454][v455][v456];	// L810
              int8_t v461 = max(v460, v459);	// L811
              v448[v453][v454][v455][v456] = v461;	// L812
            }
          }
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v462[1][64][112][112],
  int8_t v463[64][64][3][3],
  int8_t v464[1][64][112][112]
) {	// L821
  // #pragma HLS dataflow

  int8_t v465[1][64][114][114];	// L823
  // #pragma HLS stream variable=v465 depth=10 type=fifo

  #pragma HLS bind_storage variable=v465 type=ram_t2p impl=bram

  for (int v466 = 0; v466 < 1; v466 += 1) {	// L824
    for (int v467 = 0; v467 < 64; v467 += 1) {	// L825
      for (int v468 = 0; v468 < 114; v468 += 1) {	// L826
        for (int v469 = 0; v469 < 114; v469 += 1) {	// L827
          v465[v466][v467][v468][v469] = (int8_t)0.000000;	// L828
        }
      }
    }
  }
  for (int v470 = 0; v470 < 1; v470 += 1) {	// L833
    for (int v471 = 0; v471 < 64; v471 += 1) {	// L834
      for (int v472 = 0; v472 < 112; v472 += 1) {	// L835
        for (int v473 = 0; v473 < 112; v473 += 1) {	// L836
          int8_t v474 = v462[v470][v471][v472][v473];	// L837
          v465[v470][v471][(v472 + 1)][(v473 + 1)] = v474;	// L838
        }
      }
    }
  }
  int8_t v475[1][64][112][112];	// L843
  // #pragma HLS stream variable=v475 depth=10 type=fifo

  #pragma HLS bind_storage variable=v475 type=ram_t2p impl=bram

  for (int v476 = 0; v476 < 1; v476 += 1) {	// L844
    for (int v477 = 0; v477 < 64; v477 += 1) {	// L845
      for (int v478 = 0; v478 < 112; v478 += 1) {	// L846
        for (int v479 = 0; v479 < 112; v479 += 1) {	// L847
          v475[v476][v477][v478][v479] = (int8_t)0.000000;	// L848
        }
      }
    }
  }
  for (int v480 = 0; v480 < 1; v480 += 1) {	// L853
    for (int v481 = 0; v481 < 64; v481 += 1) {	// L854
      for (int v482 = 0; v482 < 112; v482 += 1) {	// L855
        for (int v483 = 0; v483 < 112; v483 += 1) {	// L856
          for (int v484 = 0; v484 < 64; v484 += 1) {	// L857
            for (int v485 = 0; v485 < 3; v485 += 1) {	// L858
              for (int v486 = 0; v486 < 3; v486 += 1) {	// L859
                int8_t v487 = v465[v480][v484][(v482 + v485)][(v483 + v486)];	// L860
                int8_t v488 = v463[v481][v484][v485][v486];	// L861
                int8_t v489 = v475[v480][v481][v482][v483];	// L862
                int8_t v490 = v487 * v488;	// L863
                int8_t v491 = v489 + v490;	// L864
                v475[v480][v481][v482][v483] = v491;	// L865
              }
            }
          }
        }
      }
    }
  }
  for (int v492 = 0; v492 < 1; v492 += 1) {	// L873
    for (int v493 = 0; v493 < 64; v493 += 1) {	// L874
      for (int v494 = 0; v494 < 112; v494 += 1) {	// L875
        for (int v495 = 0; v495 < 112; v495 += 1) {	// L876
          int8_t v496 = v475[0][v493][v494][v495];	// L877
          bool v497 = v496 > (int8_t)0.000000;	// L878
          int8_t v498 = v497 ? v496 : (int8_t)0.000000;	// L879
          v464[v492][v493][v494][v495] = v498;	// L880
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v499[64][32][3][3],
  int8_t v500[1][32][112][112],
  int8_t v501[1][64][112][112]
) {	// L887
  // #pragma HLS dataflow

  int8_t v502[1][32][114][114];	// L889
  // #pragma HLS stream variable=v502 depth=10 type=fifo

  #pragma HLS bind_storage variable=v502 type=ram_t2p impl=bram

  for (int v503 = 0; v503 < 1; v503 += 1) {	// L890
    for (int v504 = 0; v504 < 32; v504 += 1) {	// L891
      for (int v505 = 0; v505 < 114; v505 += 1) {	// L892
        for (int v506 = 0; v506 < 114; v506 += 1) {	// L893
          v502[v503][v504][v505][v506] = (int8_t)0.000000;	// L894
        }
      }
    }
  }
  for (int v507 = 0; v507 < 1; v507 += 1) {	// L899
    for (int v508 = 0; v508 < 32; v508 += 1) {	// L900
      for (int v509 = 0; v509 < 112; v509 += 1) {	// L901
        for (int v510 = 0; v510 < 112; v510 += 1) {	// L902
          int8_t v511 = v500[v507][v508][v509][v510];	// L903
          v502[v507][v508][(v509 + 1)][(v510 + 1)] = v511;	// L904
        }
      }
    }
  }
  int8_t v512[1][64][112][112];	// L909
  // #pragma HLS stream variable=v512 depth=10 type=fifo

  #pragma HLS bind_storage variable=v512 type=ram_t2p impl=bram

  for (int v513 = 0; v513 < 1; v513 += 1) {	// L910
    for (int v514 = 0; v514 < 64; v514 += 1) {	// L911
      for (int v515 = 0; v515 < 112; v515 += 1) {	// L912
        for (int v516 = 0; v516 < 112; v516 += 1) {	// L913
          v512[v513][v514][v515][v516] = (int8_t)0.000000;	// L914
        }
      }
    }
  }
  for (int v517 = 0; v517 < 1; v517 += 1) {	// L919
    for (int v518 = 0; v518 < 64; v518 += 1) {	// L920
      for (int v519 = 0; v519 < 112; v519 += 1) {	// L921
        for (int v520 = 0; v520 < 112; v520 += 1) {	// L922
          for (int v521 = 0; v521 < 32; v521 += 1) {	// L923
            for (int v522 = 0; v522 < 3; v522 += 1) {	// L924
              for (int v523 = 0; v523 < 3; v523 += 1) {	// L925
                int8_t v524 = v502[v517][v521][(v519 + v522)][(v520 + v523)];	// L926
                int8_t v525 = v499[v518][v521][v522][v523];	// L927
                int8_t v526 = v512[v517][v518][v519][v520];	// L928
                int8_t v527 = v524 * v525;	// L929
                int8_t v528 = v526 + v527;	// L930
                v512[v517][v518][v519][v520] = v528;	// L931
              }
            }
          }
        }
      }
    }
  }
  for (int v529 = 0; v529 < 1; v529 += 1) {	// L939
    for (int v530 = 0; v530 < 64; v530 += 1) {	// L940
      for (int v531 = 0; v531 < 112; v531 += 1) {	// L941
        for (int v532 = 0; v532 < 112; v532 += 1) {	// L942
          int8_t v533 = v512[0][v530][v531][v532];	// L943
          bool v534 = v533 > (int8_t)0.000000;	// L944
          int8_t v535 = v534 ? v533 : (int8_t)0.000000;	// L945
          v501[v529][v530][v531][v532] = v535;	// L946
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v536[1][32][224][224],
  int8_t v537[1][32][112][112]
) {	// L953
  // #pragma HLS dataflow

  for (int v538 = 0; v538 < 1; v538 += 1) {	// L955
    for (int v539 = 0; v539 < 32; v539 += 1) {	// L956
      for (int v540 = 0; v540 < 112; v540 += 1) {	// L957
        for (int v541 = 0; v541 < 112; v541 += 1) {	// L958
          v537[v538][v539][v540][v541] = (int8_t)-INFINITY;	// L959
        }
      }
    }
  }
  for (int v542 = 0; v542 < 1; v542 += 1) {	// L964
    for (int v543 = 0; v543 < 32; v543 += 1) {	// L965
      for (int v544 = 0; v544 < 112; v544 += 1) {	// L966
        for (int v545 = 0; v545 < 112; v545 += 1) {	// L967
          for (int v546 = 0; v546 < 2; v546 += 1) {	// L968
            for (int v547 = 0; v547 < 2; v547 += 1) {	// L969
              int8_t v548 = v536[v542][v543][((v544 * 2) + v546)][((v545 * 2) + v547)];	// L970
              int8_t v549 = v537[v542][v543][v544][v545];	// L971
              int8_t v550 = max(v549, v548);	// L972
              v537[v542][v543][v544][v545] = v550;	// L973
            }
          }
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v551[32][32][3][3],
  int8_t v552[1][32][224][224],
  int8_t v553[1][32][224][224]
) {	// L982
  // #pragma HLS dataflow

  int8_t v554[1][32][226][226];	// L984
  // #pragma HLS stream variable=v554 depth=10 type=fifo

  #pragma HLS bind_storage variable=v554 type=ram_t2p impl=bram

  for (int v555 = 0; v555 < 1; v555 += 1) {	// L985
    for (int v556 = 0; v556 < 32; v556 += 1) {	// L986
      for (int v557 = 0; v557 < 226; v557 += 1) {	// L987
        for (int v558 = 0; v558 < 226; v558 += 1) {	// L988
          v554[v555][v556][v557][v558] = (int8_t)0.000000;	// L989
        }
      }
    }
  }
  for (int v559 = 0; v559 < 1; v559 += 1) {	// L994
    for (int v560 = 0; v560 < 32; v560 += 1) {	// L995
      for (int v561 = 0; v561 < 224; v561 += 1) {	// L996
        for (int v562 = 0; v562 < 224; v562 += 1) {	// L997
          int8_t v563 = v552[v559][v560][v561][v562];	// L998
          v554[v559][v560][(v561 + 1)][(v562 + 1)] = v563;	// L999
        }
      }
    }
  }
  int8_t v564[1][32][224][224];	// L1004
  // #pragma HLS stream variable=v564 depth=10 type=fifo

  #pragma HLS bind_storage variable=v564 type=ram_t2p impl=bram

  for (int v565 = 0; v565 < 1; v565 += 1) {	// L1005
    for (int v566 = 0; v566 < 32; v566 += 1) {	// L1006
      for (int v567 = 0; v567 < 224; v567 += 1) {	// L1007
        for (int v568 = 0; v568 < 224; v568 += 1) {	// L1008
          v564[v565][v566][v567][v568] = (int8_t)0.000000;	// L1009
        }
      }
    }
  }
  for (int v569 = 0; v569 < 1; v569 += 1) {	// L1014
    for (int v570 = 0; v570 < 32; v570 += 1) {	// L1015
      for (int v571 = 0; v571 < 224; v571 += 1) {	// L1016
        for (int v572 = 0; v572 < 224; v572 += 1) {	// L1017
          for (int v573 = 0; v573 < 32; v573 += 1) {	// L1018
            for (int v574 = 0; v574 < 3; v574 += 1) {	// L1019
              for (int v575 = 0; v575 < 3; v575 += 1) {	// L1020
                int8_t v576 = v554[v569][v573][(v571 + v574)][(v572 + v575)];	// L1021
                int8_t v577 = v551[v570][v573][v574][v575];	// L1022
                int8_t v578 = v564[v569][v570][v571][v572];	// L1023
                int8_t v579 = v576 * v577;	// L1024
                int8_t v580 = v578 + v579;	// L1025
                v564[v569][v570][v571][v572] = v580;	// L1026
              }
            }
          }
        }
      }
    }
  }
  for (int v581 = 0; v581 < 1; v581 += 1) {	// L1034
    for (int v582 = 0; v582 < 32; v582 += 1) {	// L1035
      for (int v583 = 0; v583 < 224; v583 += 1) {	// L1036
        for (int v584 = 0; v584 < 224; v584 += 1) {	// L1037
          int8_t v585 = v564[0][v582][v583][v584];	// L1038
          bool v586 = v585 > (int8_t)0.000000;	// L1039
          int8_t v587 = v586 ? v585 : (int8_t)0.000000;	// L1040
          v553[v581][v582][v583][v584] = v587;	// L1041
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v588[1][3][224][224],
  int8_t v589[32][3][3][3],
  int8_t v590[1][32][224][224]
) {	// L1048
  // #pragma HLS dataflow

  int8_t v591[1][3][226][226];	// L1050
  // #pragma HLS stream variable=v591 depth=10 type=fifo

  #pragma HLS bind_storage variable=v591 type=ram_t2p impl=bram

  for (int v592 = 0; v592 < 1; v592 += 1) {	// L1051
    for (int v593 = 0; v593 < 3; v593 += 1) {	// L1052
      for (int v594 = 0; v594 < 226; v594 += 1) {	// L1053
        for (int v595 = 0; v595 < 226; v595 += 1) {	// L1054
          v591[v592][v593][v594][v595] = (int8_t)0.000000;	// L1055
        }
      }
    }
  }
  for (int v596 = 0; v596 < 1; v596 += 1) {	// L1060
    for (int v597 = 0; v597 < 3; v597 += 1) {	// L1061
      for (int v598 = 0; v598 < 224; v598 += 1) {	// L1062
        for (int v599 = 0; v599 < 224; v599 += 1) {	// L1063
          int8_t v600 = v588[v596][v597][v598][v599];	// L1064
          v591[v596][v597][(v598 + 1)][(v599 + 1)] = v600;	// L1065
        }
      }
    }
  }
  int8_t v601[1][32][224][224];	// L1070
  // #pragma HLS stream variable=v601 depth=10 type=fifo

  #pragma HLS bind_storage variable=v601 type=ram_t2p impl=bram

  for (int v602 = 0; v602 < 1; v602 += 1) {	// L1071
    for (int v603 = 0; v603 < 32; v603 += 1) {	// L1072
      for (int v604 = 0; v604 < 224; v604 += 1) {	// L1073
        for (int v605 = 0; v605 < 224; v605 += 1) {	// L1074
          v601[v602][v603][v604][v605] = (int8_t)0.000000;	// L1075
        }
      }
    }
  }
  for (int v606 = 0; v606 < 1; v606 += 1) {	// L1080
    for (int v607 = 0; v607 < 32; v607 += 1) {	// L1081
      for (int v608 = 0; v608 < 224; v608 += 1) {	// L1082
        for (int v609 = 0; v609 < 224; v609 += 1) {	// L1083
          for (int v610 = 0; v610 < 3; v610 += 1) {	// L1084
            for (int v611 = 0; v611 < 3; v611 += 1) {	// L1085
              for (int v612 = 0; v612 < 3; v612 += 1) {	// L1086
                int8_t v613 = v591[v606][v610][(v608 + v611)][(v609 + v612)];	// L1087
                int8_t v614 = v589[v607][v610][v611][v612];	// L1088
                int8_t v615 = v601[v606][v607][v608][v609];	// L1089
                int8_t v616 = v613 * v614;	// L1090
                int8_t v617 = v615 + v616;	// L1091
                v601[v606][v607][v608][v609] = v617;	// L1092
              }
            }
          }
        }
      }
    }
  }
  for (int v618 = 0; v618 < 1; v618 += 1) {	// L1100
    for (int v619 = 0; v619 < 32; v619 += 1) {	// L1101
      for (int v620 = 0; v620 < 224; v620 += 1) {	// L1102
        for (int v621 = 0; v621 < 224; v621 += 1) {	// L1103
          int8_t v622 = v601[0][v619][v620][v621];	// L1104
          bool v623 = v622 > (int8_t)0.000000;	// L1105
          int8_t v624 = v623 ? v622 : (int8_t)0.000000;	// L1106
          v590[v618][v619][v620][v621] = v624;	// L1107
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v625[1][3][224][224],
  int8_t v626[1000],
  int8_t v627[2048],
  int8_t v628[2048][512][7][7],
  int8_t v629[512][512][3][3],
  int8_t v630[512][512][3][3],
  int8_t v631[512][256][3][3],
  int8_t v632[256][256][3][3],
  int8_t v633[256][256][3][3],
  int8_t v634[256][128][3][3],
  int8_t v635[128][128][3][3],
  int8_t v636[128][128][3][3],
  int8_t v637[128][64][3][3],
  int8_t v638[64][64][3][3],
  int8_t v639[64][32][3][3],
  int8_t v640[32][32][3][3],
  int8_t v641[32][3][3][3],
  int8_t v642[2048][2048],
  int8_t v643[2048][1000],
  int8_t v644[1][1000]
) {	// L1114
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v625
  #pragma HLS bind_storage variable=v625 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v626
  #pragma HLS bind_storage variable=v626 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v627
  #pragma HLS bind_storage variable=v627 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v628
  #pragma HLS bind_storage variable=v628 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v629
  #pragma HLS bind_storage variable=v629 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v630
  #pragma HLS bind_storage variable=v630 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v631
  #pragma HLS bind_storage variable=v631 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v632
  #pragma HLS bind_storage variable=v632 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v633
  #pragma HLS bind_storage variable=v633 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v634
  #pragma HLS bind_storage variable=v634 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v635
  #pragma HLS bind_storage variable=v635 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v636
  #pragma HLS bind_storage variable=v636 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v637
  #pragma HLS bind_storage variable=v637 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v638
  #pragma HLS bind_storage variable=v638 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v639
  #pragma HLS bind_storage variable=v639 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v640
  #pragma HLS bind_storage variable=v640 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v641
  #pragma HLS bind_storage variable=v641 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v642
  #pragma HLS bind_storage variable=v642 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v643
  #pragma HLS bind_storage variable=v643 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v644
  #pragma HLS bind_storage variable=v644 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  int8_t v645[1][32][224][224];	// L1116
  // #pragma HLS stream variable=v645 depth=10 type=fifo

  #pragma HLS bind_storage variable=v645 type=ram_t2p impl=bram

  main_graph_node20(v625, v641, v645);	// L1117      PCR
  int8_t v646[1][32][224][224];	// L1118
  // #pragma HLS stream variable=v646 depth=10 type=fifo

  #pragma HLS bind_storage variable=v646 type=ram_t2p impl=bram

  main_graph_node19(v640, v645, v646);	// L1119        PCR
  int8_t v647[1][32][112][112];	// L1120
  // #pragma HLS stream variable=v647 depth=10 type=fifo

  #pragma HLS bind_storage variable=v647 type=ram_t2p impl=bram

  main_graph_node18(v646, v647);	// L1121      POOL
  int8_t v648[1][64][112][112];	// L1122
  // #pragma HLS stream variable=v648 depth=10 type=fifo

  #pragma HLS bind_storage variable=v648 type=ram_t2p impl=bram

  main_graph_node17(v639, v647, v648);	// L1123      PCR
  int8_t v649[1][64][112][112];	// L1124
  // #pragma HLS stream variable=v649 depth=10 type=fifo

  #pragma HLS bind_storage variable=v649 type=ram_t2p impl=bram

  main_graph_node16(v648, v638, v649);	// L1125    PCR
  int8_t v650[1][64][56][56];	// L1126
  // #pragma HLS stream variable=v650 depth=10 type=fifo

  #pragma HLS bind_storage variable=v650 type=ram_t2p impl=bram

  main_graph_node15(v649, v650);	// L1127      POOL
  int8_t v651[1][128][56][56];	// L1128
  // #pragma HLS stream variable=v651 depth=10 type=fifo

  #pragma HLS bind_storage variable=v651 type=ram_t2p impl=bram

  main_graph_node14(v650, v637, v651);	// L1129      PCR
  int8_t v652[1][128][56][56];	// L1130
  // #pragma HLS stream variable=v652 depth=10 type=fifo

  #pragma HLS bind_storage variable=v652 type=ram_t2p impl=bram

  main_graph_node13(v651, v636, v652);	// L1131    PCR
  int8_t v653[1][128][56][56];	// L1132
  // #pragma HLS stream variable=v653 depth=10 type=fifo

  #pragma HLS bind_storage variable=v653 type=ram_t2p impl=bram

  main_graph_node12(v652, v635, v653);	// L1133
  int8_t v654[1][128][28][28];	// L1134
  // #pragma HLS stream variable=v654 depth=10 type=fifo

  #pragma HLS bind_storage variable=v654 type=ram_t2p impl=bram

  main_graph_node11(v653, v654);	// L1135
  int8_t v655[1][256][28][28];	// L1136
  // #pragma HLS stream variable=v655 depth=10 type=fifo

  #pragma HLS bind_storage variable=v655 type=ram_t2p impl=bram

  main_graph_node10(v654, v634, v655);	// L1137
  int8_t v656[1][256][28][28];	// L1138
  // #pragma HLS stream variable=v656 depth=10 type=fifo

  #pragma HLS bind_storage variable=v656 type=ram_t2p impl=bram

  main_graph_node9(v655, v633, v656);	// L1139
  int8_t v657[1][256][28][28];	// L1140
  // #pragma HLS stream variable=v657 depth=10 type=fifo

  #pragma HLS bind_storage variable=v657 type=ram_t2p impl=bram

  main_graph_node8(v632, v656, v657);	// L1141
  int8_t v658[1][256][14][14];	// L1142
  // #pragma HLS stream variable=v658 depth=10 type=fifo

  #pragma HLS bind_storage variable=v658 type=ram_t2p impl=bram

  main_graph_node7(v657, v658);	// L1143
  int8_t v659[1][512][14][14];	// L1144
  // #pragma HLS stream variable=v659 depth=10 type=fifo

  #pragma HLS bind_storage variable=v659 type=ram_t2p impl=bram

  main_graph_node6(v631, v658, v659);	// L1145
  int8_t v660[1][512][14][14];	// L1146
  // #pragma HLS stream variable=v660 depth=10 type=fifo

  #pragma HLS bind_storage variable=v660 type=ram_t2p impl=bram

  main_graph_node5(v659, v630, v660);	// L1147
  int8_t v661[1][512][14][14];	// L1148
  // #pragma HLS stream variable=v661 depth=10 type=fifo

  #pragma HLS bind_storage variable=v661 type=ram_t2p impl=bram

  main_graph_node4(v660, v629, v661);	// L1149
  int8_t v662[1][512][7][7];	// L1150
  // #pragma HLS stream variable=v662 depth=10 type=fifo

  #pragma HLS bind_storage variable=v662 type=ram_t2p impl=bram

  main_graph_node3(v661, v662);	// L1151
  int8_t v663[1][2048][1][1];	// L1152
  // #pragma HLS stream variable=v663 depth=10 type=fifo

  #pragma HLS bind_storage variable=v663 type=ram_t2p impl=bram

  main_graph_node2(v628, v662, v663);	// L1153
  int8_t v664[1][2048];	// L1154
  // #pragma HLS stream variable=v664 depth=10 type=fifo

  #pragma HLS bind_storage variable=v664 type=ram_t2p impl=bram

  main_graph_node1(v663, v627, v642, v664);	// L1155
  main_graph_node0(v643, v664, v626, v644);	// L1156
}

