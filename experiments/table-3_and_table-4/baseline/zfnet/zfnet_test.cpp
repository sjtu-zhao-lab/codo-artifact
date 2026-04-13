
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
  int8_t v0[4096][1000],
  int8_t v1[1][4096],
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
      for (int v9 = 0; v9 < 4096; v9 += 1) {	// L13
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
  int8_t v20[1][4096][1][1],
  int8_t v21[4096],
  int8_t v22[4096][4096],
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
      for (int v29 = 0; v29 < 4096; v29 += 1) {	// L43
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
    for (int v36 = 0; v36 < 4096; v36 += 1) {	// L54
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
  int8_t v42[4096][256][5][5],
  int8_t v43[1][256][5][5],
  int8_t v44[1][4096][1][1]
) {	// L65
  // #pragma HLS dataflow

  int8_t v45[1][4096][1][1];	// L67
  // #pragma HLS stream variable=v45 depth=10 type=fifo

  #pragma HLS bind_storage variable=v45 type=ram_t2p impl=bram

  for (int v46 = 0; v46 < 1; v46 += 1) {	// L68
    for (int v47 = 0; v47 < 4096; v47 += 1) {	// L69
      for (int v48 = 0; v48 < 1; v48 += 1) {	// L70
        for (int v49 = 0; v49 < 1; v49 += 1) {	// L71
          v45[v46][v47][v48][v49] = (int8_t)0.000000;	// L72
        }
      }
    }
  }
  for (int v50 = 0; v50 < 1; v50 += 1) {	// L77
    for (int v51 = 0; v51 < 4096; v51 += 1) {	// L78
      for (int v52 = 0; v52 < 1; v52 += 1) {	// L79
        for (int v53 = 0; v53 < 1; v53 += 1) {	// L80
          for (int v54 = 0; v54 < 256; v54 += 1) {	// L81
            for (int v55 = 0; v55 < 5; v55 += 1) {	// L82
              for (int v56 = 0; v56 < 5; v56 += 1) {	// L83
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
    for (int v63 = 0; v63 < 4096; v63 += 1) {	// L98
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
  int8_t v69[1][256][12][12],
  int8_t v70[1][256][5][5]
) {	// L111
  // #pragma HLS dataflow

  for (int v71 = 0; v71 < 1; v71 += 1) {	// L113
    for (int v72 = 0; v72 < 256; v72 += 1) {	// L114
      for (int v73 = 0; v73 < 5; v73 += 1) {	// L115
        for (int v74 = 0; v74 < 5; v74 += 1) {	// L116
          v70[v71][v72][v73][v74] = (int8_t)-INFINITY;	// L117
        }
      }
    }
  }
  for (int v75 = 0; v75 < 1; v75 += 1) {	// L122
    for (int v76 = 0; v76 < 256; v76 += 1) {	// L123
      for (int v77 = 0; v77 < 5; v77 += 1) {	// L124
        for (int v78 = 0; v78 < 5; v78 += 1) {	// L125
          for (int v79 = 0; v79 < 3; v79 += 1) {	// L126
            for (int v80 = 0; v80 < 3; v80 += 1) {	// L127
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
  int8_t v84[256][384][3][3],
  int8_t v85[1][384][12][12],
  int8_t v86[1][256][12][12]
) {	// L140
  // #pragma HLS dataflow

  int8_t v87[1][384][14][14];	// L142
  // #pragma HLS stream variable=v87 depth=10 type=fifo

  #pragma HLS bind_storage variable=v87 type=ram_t2p impl=bram

  for (int v88 = 0; v88 < 1; v88 += 1) {	// L143
    for (int v89 = 0; v89 < 384; v89 += 1) {	// L144
      for (int v90 = 0; v90 < 14; v90 += 1) {	// L145
        for (int v91 = 0; v91 < 14; v91 += 1) {	// L146
          v87[v88][v89][v90][v91] = (int8_t)0.000000;	// L147
        }
      }
    }
  }
  for (int v92 = 0; v92 < 1; v92 += 1) {	// L152
    for (int v93 = 0; v93 < 384; v93 += 1) {	// L153
      for (int v94 = 0; v94 < 12; v94 += 1) {	// L154
        for (int v95 = 0; v95 < 12; v95 += 1) {	// L155
          int8_t v96 = v85[v92][v93][v94][v95];	// L156
          v87[v92][v93][(v94 + 1)][(v95 + 1)] = v96;	// L157
        }
      }
    }
  }
  int8_t v97[1][256][12][12];	// L162
  // #pragma HLS stream variable=v97 depth=10 type=fifo

  #pragma HLS bind_storage variable=v97 type=ram_t2p impl=bram

  for (int v98 = 0; v98 < 1; v98 += 1) {	// L163
    for (int v99 = 0; v99 < 256; v99 += 1) {	// L164
      for (int v100 = 0; v100 < 12; v100 += 1) {	// L165
        for (int v101 = 0; v101 < 12; v101 += 1) {	// L166
          v97[v98][v99][v100][v101] = (int8_t)0.000000;	// L167
        }
      }
    }
  }
  for (int v102 = 0; v102 < 1; v102 += 1) {	// L172
    for (int v103 = 0; v103 < 256; v103 += 1) {	// L173
      for (int v104 = 0; v104 < 12; v104 += 1) {	// L174
        for (int v105 = 0; v105 < 12; v105 += 1) {	// L175
          for (int v106 = 0; v106 < 384; v106 += 1) {	// L176
            for (int v107 = 0; v107 < 3; v107 += 1) {	// L177
              for (int v108 = 0; v108 < 3; v108 += 1) {	// L178
                int8_t v109 = v87[v102][v106][(v104 + v107)][(v105 + v108)];	// L179
                int8_t v110 = v84[v103][v106][v107][v108];	// L180
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
    for (int v115 = 0; v115 < 256; v115 += 1) {	// L193
      for (int v116 = 0; v116 < 12; v116 += 1) {	// L194
        for (int v117 = 0; v117 < 12; v117 += 1) {	// L195
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
  int8_t v121[384][384][3][3],
  int8_t v122[1][384][12][12],
  int8_t v123[1][384][12][12]
) {	// L206
  // #pragma HLS dataflow

  int8_t v124[1][384][14][14];	// L208
  // #pragma HLS stream variable=v124 depth=10 type=fifo

  #pragma HLS bind_storage variable=v124 type=ram_t2p impl=bram

  for (int v125 = 0; v125 < 1; v125 += 1) {	// L209
    for (int v126 = 0; v126 < 384; v126 += 1) {	// L210
      for (int v127 = 0; v127 < 14; v127 += 1) {	// L211
        for (int v128 = 0; v128 < 14; v128 += 1) {	// L212
          v124[v125][v126][v127][v128] = (int8_t)0.000000;	// L213
        }
      }
    }
  }
  for (int v129 = 0; v129 < 1; v129 += 1) {	// L218
    for (int v130 = 0; v130 < 384; v130 += 1) {	// L219
      for (int v131 = 0; v131 < 12; v131 += 1) {	// L220
        for (int v132 = 0; v132 < 12; v132 += 1) {	// L221
          int8_t v133 = v122[v129][v130][v131][v132];	// L222
          v124[v129][v130][(v131 + 1)][(v132 + 1)] = v133;	// L223
        }
      }
    }
  }
  int8_t v134[1][384][12][12];	// L228
  // #pragma HLS stream variable=v134 depth=10 type=fifo

  #pragma HLS bind_storage variable=v134 type=ram_t2p impl=bram

  for (int v135 = 0; v135 < 1; v135 += 1) {	// L229
    for (int v136 = 0; v136 < 384; v136 += 1) {	// L230
      for (int v137 = 0; v137 < 12; v137 += 1) {	// L231
        for (int v138 = 0; v138 < 12; v138 += 1) {	// L232
          v134[v135][v136][v137][v138] = (int8_t)0.000000;	// L233
        }
      }
    }
  }
  for (int v139 = 0; v139 < 1; v139 += 1) {	// L238
    for (int v140 = 0; v140 < 384; v140 += 1) {	// L239
      for (int v141 = 0; v141 < 12; v141 += 1) {	// L240
        for (int v142 = 0; v142 < 12; v142 += 1) {	// L241
          for (int v143 = 0; v143 < 384; v143 += 1) {	// L242
            for (int v144 = 0; v144 < 3; v144 += 1) {	// L243
              for (int v145 = 0; v145 < 3; v145 += 1) {	// L244
                int8_t v146 = v124[v139][v143][(v141 + v144)][(v142 + v145)];	// L245
                int8_t v147 = v121[v140][v143][v144][v145];	// L246
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
    for (int v152 = 0; v152 < 384; v152 += 1) {	// L259
      for (int v153 = 0; v153 < 12; v153 += 1) {	// L260
        for (int v154 = 0; v154 < 12; v154 += 1) {	// L261
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
  int8_t v158[384][256][3][3],
  int8_t v159[1][256][12][12],
  int8_t v160[1][384][12][12]
) {	// L272
  // #pragma HLS dataflow

  int8_t v161[1][256][14][14];	// L274
  // #pragma HLS stream variable=v161 depth=10 type=fifo

  #pragma HLS bind_storage variable=v161 type=ram_t2p impl=bram

  for (int v162 = 0; v162 < 1; v162 += 1) {	// L275
    for (int v163 = 0; v163 < 256; v163 += 1) {	// L276
      for (int v164 = 0; v164 < 14; v164 += 1) {	// L277
        for (int v165 = 0; v165 < 14; v165 += 1) {	// L278
          v161[v162][v163][v164][v165] = (int8_t)0.000000;	// L279
        }
      }
    }
  }
  for (int v166 = 0; v166 < 1; v166 += 1) {	// L284
    for (int v167 = 0; v167 < 256; v167 += 1) {	// L285
      for (int v168 = 0; v168 < 12; v168 += 1) {	// L286
        for (int v169 = 0; v169 < 12; v169 += 1) {	// L287
          int8_t v170 = v159[v166][v167][v168][v169];	// L288
          v161[v166][v167][(v168 + 1)][(v169 + 1)] = v170;	// L289
        }
      }
    }
  }
  int8_t v171[1][384][12][12];	// L294
  // #pragma HLS stream variable=v171 depth=10 type=fifo

  #pragma HLS bind_storage variable=v171 type=ram_t2p impl=bram

  for (int v172 = 0; v172 < 1; v172 += 1) {	// L295
    for (int v173 = 0; v173 < 384; v173 += 1) {	// L296
      for (int v174 = 0; v174 < 12; v174 += 1) {	// L297
        for (int v175 = 0; v175 < 12; v175 += 1) {	// L298
          v171[v172][v173][v174][v175] = (int8_t)0.000000;	// L299
        }
      }
    }
  }
  for (int v176 = 0; v176 < 1; v176 += 1) {	// L304
    for (int v177 = 0; v177 < 384; v177 += 1) {	// L305
      for (int v178 = 0; v178 < 12; v178 += 1) {	// L306
        for (int v179 = 0; v179 < 12; v179 += 1) {	// L307
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
    for (int v189 = 0; v189 < 384; v189 += 1) {	// L325
      for (int v190 = 0; v190 < 12; v190 += 1) {	// L326
        for (int v191 = 0; v191 < 12; v191 += 1) {	// L327
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
  int8_t v195[1][256][26][26],
  int8_t v196[1][256][12][12]
) {	// L338
  // #pragma HLS dataflow

  for (int v197 = 0; v197 < 1; v197 += 1) {	// L340
    for (int v198 = 0; v198 < 256; v198 += 1) {	// L341
      for (int v199 = 0; v199 < 12; v199 += 1) {	// L342
        for (int v200 = 0; v200 < 12; v200 += 1) {	// L343
          v196[v197][v198][v199][v200] = (int8_t)-INFINITY;	// L344
        }
      }
    }
  }
  for (int v201 = 0; v201 < 1; v201 += 1) {	// L349
    for (int v202 = 0; v202 < 256; v202 += 1) {	// L350
      for (int v203 = 0; v203 < 12; v203 += 1) {	// L351
        for (int v204 = 0; v204 < 12; v204 += 1) {	// L352
          for (int v205 = 0; v205 < 3; v205 += 1) {	// L353
            for (int v206 = 0; v206 < 3; v206 += 1) {	// L354
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
  int8_t v210[256][96][5][5],
  int8_t v211[1][96][54][54],
  int8_t v212[1][256][26][26]
) {	// L367
  // #pragma HLS dataflow

  int8_t v213[1][96][56][56];	// L369
  // #pragma HLS stream variable=v213 depth=10 type=fifo

  #pragma HLS bind_storage variable=v213 type=ram_t2p impl=bram

  for (int v214 = 0; v214 < 1; v214 += 1) {	// L370
    for (int v215 = 0; v215 < 96; v215 += 1) {	// L371
      for (int v216 = 0; v216 < 56; v216 += 1) {	// L372
        for (int v217 = 0; v217 < 56; v217 += 1) {	// L373
          v213[v214][v215][v216][v217] = (int8_t)0.000000;	// L374
        }
      }
    }
  }
  for (int v218 = 0; v218 < 1; v218 += 1) {	// L379
    for (int v219 = 0; v219 < 96; v219 += 1) {	// L380
      for (int v220 = 0; v220 < 54; v220 += 1) {	// L381
        for (int v221 = 0; v221 < 54; v221 += 1) {	// L382
          int8_t v222 = v211[v218][v219][v220][v221];	// L383
          v213[v218][v219][(v220 + 1)][(v221 + 1)] = v222;	// L384
        }
      }
    }
  }
  int8_t v223[1][256][26][26];	// L389
  // #pragma HLS stream variable=v223 depth=10 type=fifo

  #pragma HLS bind_storage variable=v223 type=ram_t2p impl=bram

  for (int v224 = 0; v224 < 1; v224 += 1) {	// L390
    for (int v225 = 0; v225 < 256; v225 += 1) {	// L391
      for (int v226 = 0; v226 < 26; v226 += 1) {	// L392
        for (int v227 = 0; v227 < 26; v227 += 1) {	// L393
          v223[v224][v225][v226][v227] = (int8_t)0.000000;	// L394
        }
      }
    }
  }
  for (int v228 = 0; v228 < 1; v228 += 1) {	// L399
    for (int v229 = 0; v229 < 256; v229 += 1) {	// L400
      for (int v230 = 0; v230 < 26; v230 += 1) {	// L401
        for (int v231 = 0; v231 < 26; v231 += 1) {	// L402
          for (int v232 = 0; v232 < 96; v232 += 1) {	// L403
            for (int v233 = 0; v233 < 5; v233 += 1) {	// L404
              for (int v234 = 0; v234 < 5; v234 += 1) {	// L405
                int8_t v235 = v213[v228][v232][((v230 * 2) + v233)][((v231 * 2) + v234)];	// L406
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
      for (int v242 = 0; v242 < 26; v242 += 1) {	// L421
        for (int v243 = 0; v243 < 26; v243 += 1) {	// L422
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
  int8_t v247[1][96][110][110],
  int8_t v248[1][96][54][54]
) {	// L433
  // #pragma HLS dataflow

  for (int v249 = 0; v249 < 1; v249 += 1) {	// L435
    for (int v250 = 0; v250 < 96; v250 += 1) {	// L436
      for (int v251 = 0; v251 < 54; v251 += 1) {	// L437
        for (int v252 = 0; v252 < 54; v252 += 1) {	// L438
          v248[v249][v250][v251][v252] = (int8_t)-INFINITY;	// L439
        }
      }
    }
  }
  for (int v253 = 0; v253 < 1; v253 += 1) {	// L444
    for (int v254 = 0; v254 < 96; v254 += 1) {	// L445
      for (int v255 = 0; v255 < 54; v255 += 1) {	// L446
        for (int v256 = 0; v256 < 54; v256 += 1) {	// L447
          for (int v257 = 0; v257 < 3; v257 += 1) {	// L448
            for (int v258 = 0; v258 < 3; v258 += 1) {	// L449
              int8_t v259 = v247[v253][v254][((v255 * 2) + v257)][((v256 * 2) + v258)];	// L450
              int8_t v260 = v248[v253][v254][v255][v256];	// L451
              int8_t v261 = max(v260, v259);	// L452
              v248[v253][v254][v255][v256] = v261;	// L453
            }
          }
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v262[96][3][7][7],
  int8_t v263[1][3][224][224],
  int8_t v264[1][96][110][110]
) {	// L462
  // #pragma HLS dataflow

  int8_t v265[1][3][226][226];	// L464
  // #pragma HLS stream variable=v265 depth=10 type=fifo

  #pragma HLS bind_storage variable=v265 type=ram_t2p impl=bram

  for (int v266 = 0; v266 < 1; v266 += 1) {	// L465
    for (int v267 = 0; v267 < 3; v267 += 1) {	// L466
      for (int v268 = 0; v268 < 226; v268 += 1) {	// L467
        for (int v269 = 0; v269 < 226; v269 += 1) {	// L468
          v265[v266][v267][v268][v269] = (int8_t)0.000000;	// L469
        }
      }
    }
  }
  for (int v270 = 0; v270 < 1; v270 += 1) {	// L474
    for (int v271 = 0; v271 < 3; v271 += 1) {	// L475
      for (int v272 = 0; v272 < 224; v272 += 1) {	// L476
        for (int v273 = 0; v273 < 224; v273 += 1) {	// L477
          int8_t v274 = v263[v270][v271][v272][v273];	// L478
          v265[v270][v271][(v272 + 1)][(v273 + 1)] = v274;	// L479
        }
      }
    }
  }
  int8_t v275[1][96][110][110];	// L484
  // #pragma HLS stream variable=v275 depth=10 type=fifo

  #pragma HLS bind_storage variable=v275 type=ram_t2p impl=bram

  for (int v276 = 0; v276 < 1; v276 += 1) {	// L485
    for (int v277 = 0; v277 < 96; v277 += 1) {	// L486
      for (int v278 = 0; v278 < 110; v278 += 1) {	// L487
        for (int v279 = 0; v279 < 110; v279 += 1) {	// L488
          v275[v276][v277][v278][v279] = (int8_t)0.000000;	// L489
        }
      }
    }
  }
  for (int v280 = 0; v280 < 1; v280 += 1) {	// L494
    for (int v281 = 0; v281 < 96; v281 += 1) {	// L495
      for (int v282 = 0; v282 < 110; v282 += 1) {	// L496
        for (int v283 = 0; v283 < 110; v283 += 1) {	// L497
          for (int v284 = 0; v284 < 3; v284 += 1) {	// L498
            for (int v285 = 0; v285 < 7; v285 += 1) {	// L499
              for (int v286 = 0; v286 < 7; v286 += 1) {	// L500
                int8_t v287 = v265[v280][v284][((v282 * 2) + v285)][((v283 * 2) + v286)];	// L501
                int8_t v288 = v262[v281][v284][v285][v286];	// L502
                int8_t v289 = v275[v280][v281][v282][v283];	// L503
                int8_t v290 = v287 * v288;	// L504
                int8_t v291 = v289 + v290;	// L505
                v275[v280][v281][v282][v283] = v291;	// L506
              }
            }
          }
        }
      }
    }
  }
  for (int v292 = 0; v292 < 1; v292 += 1) {	// L514
    for (int v293 = 0; v293 < 96; v293 += 1) {	// L515
      for (int v294 = 0; v294 < 110; v294 += 1) {	// L516
        for (int v295 = 0; v295 < 110; v295 += 1) {	// L517
          int8_t v296 = v275[0][v293][v294][v295];	// L518
          bool v297 = v296 > (int8_t)0.000000;	// L519
          int8_t v298 = v297 ? v296 : (int8_t)0.000000;	// L520
          v264[v292][v293][v294][v295] = v298;	// L521
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  int8_t v299[1][3][224][224],
  int8_t v300[1000],
  int8_t v301[4096],
  int8_t v302[4096][256][5][5],
  int8_t v303[256][384][3][3],
  int8_t v304[384][384][3][3],
  int8_t v305[384][256][3][3],
  int8_t v306[256][96][5][5],
  int8_t v307[96][3][7][7],
  int8_t v308[4096][4096],
  int8_t v309[4096][1000],
  int8_t v310[1][1000]
) {	// L528
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v299
  #pragma HLS bind_storage variable=v299 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v300
  #pragma HLS bind_storage variable=v300 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v301
  #pragma HLS bind_storage variable=v301 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v302
  #pragma HLS bind_storage variable=v302 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v303
  #pragma HLS bind_storage variable=v303 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v304
  #pragma HLS bind_storage variable=v304 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v305
  #pragma HLS bind_storage variable=v305 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v306
  #pragma HLS bind_storage variable=v306 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v307
  #pragma HLS bind_storage variable=v307 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v308
  #pragma HLS bind_storage variable=v308 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v309
  #pragma HLS bind_storage variable=v309 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v310
  #pragma HLS bind_storage variable=v310 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  int8_t v311[1][96][110][110];	// L530
  // #pragma HLS stream variable=v311 depth=10 type=fifo

  #pragma HLS bind_storage variable=v311 type=ram_t2p impl=bram

  main_graph_node10(v307, v299, v311);	// L531
  int8_t v312[1][96][54][54];	// L532
  // #pragma HLS stream variable=v312 depth=10 type=fifo

  #pragma HLS bind_storage variable=v312 type=ram_t2p impl=bram

  main_graph_node9(v311, v312);	// L533
  int8_t v313[1][256][26][26];	// L534
  // #pragma HLS stream variable=v313 depth=10 type=fifo

  #pragma HLS bind_storage variable=v313 type=ram_t2p impl=bram

  main_graph_node8(v306, v312, v313);	// L535
  int8_t v314[1][256][12][12];	// L536
  // #pragma HLS stream variable=v314 depth=10 type=fifo

  #pragma HLS bind_storage variable=v314 type=ram_t2p impl=bram

  main_graph_node7(v313, v314);	// L537
  int8_t v315[1][384][12][12];	// L538
  // #pragma HLS stream variable=v315 depth=10 type=fifo

  #pragma HLS bind_storage variable=v315 type=ram_t2p impl=bram

  main_graph_node6(v305, v314, v315);	// L539   
  int8_t v316[1][384][12][12];	// L540
  // #pragma HLS stream variable=v316 depth=10 type=fifo

  #pragma HLS bind_storage variable=v316 type=ram_t2p impl=bram

  main_graph_node5(v304, v315, v316);	// L541
  int8_t v317[1][256][12][12];	// L542
  // #pragma HLS stream variable=v317 depth=10 type=fifo

  #pragma HLS bind_storage variable=v317 type=ram_t2p impl=bram

  main_graph_node4(v303, v316, v317);	// L543
  int8_t v318[1][256][5][5];	// L544
  // #pragma HLS stream variable=v318 depth=10 type=fifo

  #pragma HLS bind_storage variable=v318 type=ram_t2p impl=bram

  main_graph_node3(v317, v318);	// L545
  int8_t v319[1][4096][1][1];	// L546
  // #pragma HLS stream variable=v319 depth=10 type=fifo

  #pragma HLS bind_storage variable=v319 type=ram_t2p impl=bram

  main_graph_node2(v302, v318, v319);	// L547
  int8_t v320[1][4096];	// L548
  // #pragma HLS stream variable=v320 depth=10 type=fifo

  #pragma HLS bind_storage variable=v320 type=ram_t2p impl=bram

  main_graph_node1(v319, v301, v308, v320);	// L549
  main_graph_node0(v309, v320, v300, v310);	// L550
}

