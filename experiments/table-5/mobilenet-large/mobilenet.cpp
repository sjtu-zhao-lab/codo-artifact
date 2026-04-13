
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
) {	// L16
  #pragma HLS dataflow

  int8_t v4[1][1000];	// L18
  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  int8_t v5[1][1000];	// L19
  #pragma HLS bind_storage variable=v5 type=ram_t2p impl=bram

  for (int v6 = 0; v6 < 1; v6 += 1) {	// L20
    for (int v7 = 0; v7 < 1000; v7 += 1) {	// L21
      v4[v6][v7] = (int8_t)0.000000;	// L22
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L25
    for (int v9 = 0; v9 < 1000; v9 += 1) {	// L26
      for (int v10 = 0; v10 < 1024; v10 += 1) {	// L27
        int8_t v11 = v0[v8][v10][0][0];	// L28
        int8_t v12 = v1[v10][v9];	// L29
        int8_t v13 = v4[v8][v9];	// L30
        int8_t v14 = v11 * v12;	// L31
        int8_t v15 = v13 + v14;	// L32
        v5[v8][v9] = v15;	// L33
      }
    }
  }
  for (int v16 = 0; v16 < 1; v16 += 1) {	// L37
    for (int v17 = 0; v17 < 1000; v17 += 1) {	// L38
      int8_t v18 = v5[0][v17];	// L39
      int8_t v19 = v2[v17];	// L40
      int8_t v20 = v18 + v19;	// L41
      v3[v16][v17] = v20;	// L42
    }
  }
}

void main_graph_node1(
  int8_t v21[1][1024][1][1],
  int8_t v22[1][1],
  int8_t v23[1][1024][1][1]
) {	// L47
  #pragma HLS dataflow

  int8_t v24[1][1024][1][1];	// L48
  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L49
    for (int v26 = 0; v26 < 1024; v26 += 1) {	// L50
      for (int v27 = 0; v27 < 1; v27 += 1) {	// L51
        for (int v28 = 0; v28 < 1; v28 += 1) {	// L52
          int8_t v29 = v21[v25][v26][v27][v28];	// L53
          v24[v25][v26][v27][v28] = v29;	// L54
          int8_t v30 = v22[v27][v28];	// L55
          int8_t v31 = v24[v25][v26][v27][v28];	// L56
          int8_t v32 = v31 / v30;	// L57
          v23[v25][v26][v27][v28] = v32;	// L58
        }
      }
    }
  }
}

void main_graph_node2(
  int8_t v33[1][1024][8][8],
  int8_t v34[1][1024][1][1],
  int8_t v35[1][1]
) {	// L65
  #pragma HLS dataflow

  int8_t v36[1][1024][1][1];	// L69
  #pragma HLS bind_storage variable=v36 type=ram_t2p impl=bram

  for (int v37 = 0; v37 < 1; v37 += 1) {	// L70
    for (int v38 = 0; v38 < 1024; v38 += 1) {	// L71
      for (int v39 = 0; v39 < 1; v39 += 1) {	// L72
        for (int v40 = 0; v40 < 1; v40 += 1) {	// L73
          v36[v37][v38][v39][v40] = (int8_t)0.000000;	// L74
        }
      }
    }
  }
  for (int v41 = 0; v41 < 1; v41 += 1) {	// L79
    for (int v42 = 0; v42 < 1024; v42 += 1) {	// L80
      for (int v43 = 0; v43 < 1; v43 += 1) {	// L81
        for (int v44 = 0; v44 < 1; v44 += 1) {	// L82
          for (int v45 = 0; v45 < 7; v45 += 1) {	// L83
            for (int v46 = 0; v46 < 7; v46 += 1) {	// L84
              int8_t v47 = v36[v41][v42][v43][v44];	// L85
              int v48 = v43 * (int)7;	// L86
              int v49 = v43 + (int)1;	// L87
              int v50 = v49 * (int)7;	// L88
              int v51 = v44 * (int)7;	// L89
              int v52 = v44 + (int)1;	// L90
              int v53 = v52 * (int)7;	// L91
              int v54 = v48 + v45;	// L92
              int v55 = v51 + v46;	// L93
              int8_t v56 = v33[v41][v42][v54][v55];	// L94
              bool v57 = v54 < v50;	// L95
              int8_t v58 = v57 ? v56 : (int8_t)0.000000;	// L96
              bool v59 = v55 < v53;	// L97
              int8_t v60 = v59 ? v58 : (int8_t)0.000000;	// L98
              int8_t v61 = v60 + v47;	// L99
              int v62 = v50 - v48;	// L100
              int v63 = v53 - v51;	// L101
              int v64 = v62 * v63;	// L102
              ap_int<64> v65 = v64;	// L103
              int8_t v66 = v65;	// L104
              v34[v41][v42][v43][v44] = v61;	// L105
              v35[v41][v42] = v66;	// L106
            }
          }
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v67[1][1024][7][7],
  int8_t v68[1][1024][8][8]
) {	// L115
  #pragma HLS dataflow

  for (int v69 = 0; v69 < 1; v69 += 1) {	// L117
    for (int v70 = 0; v70 < 8; v70 += 1) {	// L118
      for (int v71 = 0; v71 < 8; v71 += 1) {	// L119
        for (int v72 = 0; v72 < 1024; v72 += 1) {	// L120
          int8_t v73;	// L121
          v73 = (int8_t)0.000000;	// L122
          if (((-v70) + 6) >= 0 && ((-v71) + 6) >= 0) {	// L123
            int8_t v74 = v67[v69][v72][v70][v71];	// L124
            v73 = v74;	// L125
          }
          int8_t v75 = v73;	// L127
          v68[v69][v72][v70][v71] = v75;	// L128
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v76[1][1024][7][7],
  int8_t v77[1024][1024][1][1],
  int8_t v78[1][1024][7][7]
) {	// L135
  #pragma HLS dataflow

  int8_t v79[1][1024][7][7];	// L137
  #pragma HLS stream variable=v79 depth=10 type=fifo

  #pragma HLS bind_storage variable=v79 type=ram_t2p impl=bram

  int8_t v80[1][1024][1][7];	// L138
  #pragma HLS bind_storage variable=v80 type=ram_2p impl=bram

  int8_t v81[1][1024][1][1];	// L139
  #pragma HLS array_partition variable=v81 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v81 type=ram_2p impl=lutram

  for (int v82 = 0; v82 < 1; v82 += 1) {	// L140
    for (int v83 = 0; v83 < 7; v83 += 1) {	// L141
      for (int v84 = 0; v84 < 7; v84 += 1) {	// L142
        for (int v85 = 0; v85 < 1024; v85 += 1) {	// L143
          int8_t v86 = v76[v82][v85][v83][v84];	// L144
          v80[v82][v85][0][v84] = v86;	// L145
        }
        if (v83 >= 0) {	// L147
          for (int v87 = 0; v87 < 1024; v87 += 1) {	// L148
            for (int v88 = 0; v88 < 1; v88 += 1) {	// L149
              int8_t v89 = v80[v82][v87][v88][v84];	// L150
              v81[v82][v87][v88][0] = v89;	// L151
            }
          }
          if (v84 >= 0) {	// L154
            int8_t v90[1024];	// L155
            #pragma HLS bind_storage variable=v90 type=ram_2p impl=bram

            for (int v91 = 0; v91 < 1024; v91 += 1) {	// L156
              v90[v91] = (int8_t)0.000000;	// L157
              for (int v92 = 0; v92 < 32; v92 += 1) {	// L158
                #pragma HLS pipeline II=1
                for (int v93 = 0; v93 < 32; v93 += 1) {	// L159
                  for (int v94 = 0; v94 < 1; v94 += 1) {	// L160
                    for (int v95 = 0; v95 < 1; v95 += 1) {	// L161
                      int8_t v96 = v81[v82][(v93 + (v92 * 32))][v94][v95];	// L162
                      int8_t v97 = v77[v91][(v93 + (v92 * 32))][v94][v95];	// L163
                      int8_t v98 = v96 * v97;	// L164
                      int8_t v99 = v90[v91];	// L165
                      int8_t v100 = v99 + v98;	// L166
                      v90[v91] = v100;	// L167
                    }
                  }
                }
              }
              int8_t v101 = v90[v91];	// L172
              v79[v82][v91][v83][v84] = v101;	// L173
            }
          }
        }
      }
    }
  }
  for (int v102 = 0; v102 < 1; v102 += 1) {	// L180
    for (int v103 = 0; v103 < 7; v103 += 1) {	// L181
      for (int v104 = 0; v104 < 7; v104 += 1) {	// L182
        for (int v105 = 0; v105 < 1024; v105 += 1) {	// L183
          int8_t v106 = v79[0][v105][v103][v104];	// L184
          bool v107 = v106 > (int8_t)0.000000;	// L185
          int8_t v108 = v107 ? v106 : (int8_t)0.000000;	// L186
          v78[v102][v105][v103][v104] = v108;	// L187
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v109[1024][3][3],
  int8_t v110[1][1024][7][7],
  int8_t v111[1][1024][7][7]
) {	// L194
  #pragma HLS dataflow

  int8_t v112[1][1024][9][9];	// L196
  #pragma HLS stream variable=v112 depth=10 type=fifo

  #pragma HLS bind_storage variable=v112 type=ram_t2p impl=bram

  for (int v113 = 0; v113 < 1; v113 += 1) {	// L197
    for (int v114 = 0; v114 < 9; v114 += 1) {	// L198
      for (int v115 = 0; v115 < 9; v115 += 1) {	// L199
        for (int v116 = 0; v116 < 1024; v116 += 1) {	// L200
          int8_t v117;	// L201
          v117 = (int8_t)0.000000;	// L202
          if (((-v114) + 6) >= 0 && ((-v115) + 6) >= 0) {	// L203
            int8_t v118 = v110[v113][v116][v114][v115];	// L204
            v117 = v118;	// L205
          }
          int8_t v119 = v117;	// L207
          v112[v113][v116][v114][v115] = v119;	// L208
        }
      }
    }
  }
  int8_t v120[1][1024][7][7];	// L213
  #pragma HLS stream variable=v120 depth=10 type=fifo

  #pragma HLS bind_storage variable=v120 type=ram_t2p impl=bram

  int8_t v121[1][1024][3][9];	// L214
  #pragma HLS array_partition variable=v121 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v121 type=ram_2p impl=bram

  int8_t v122[1][1024][3][3];	// L215
  #pragma HLS array_partition variable=v122 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v122 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v122 type=ram_2p impl=bram

  for (int v123 = 0; v123 < 1; v123 += 1) {	// L216
    for (int v124 = 0; v124 < 9; v124 += 1) {	// L217
      for (int v125 = 0; v125 < 9; v125 += 1) {	// L218
        for (int v126 = 0; v126 < 1024; v126 += 1) {	// L219
          int8_t v127 = v121[v123][v126][1][v125];	// L220
          v121[v123][v126][0][v125] = v127;	// L221
          int8_t v128 = v121[v123][v126][2][v125];	// L222
          v121[v123][v126][1][v125] = v128;	// L223
          int8_t v129 = v112[v123][v126][v124][v125];	// L224
          v121[v123][v126][2][v125] = v129;	// L225
        }
        if ((v124 - 2) >= 0) {	// L227
          for (int v130 = 0; v130 < 1024; v130 += 1) {	// L228
            for (int v131 = 0; v131 < 3; v131 += 1) {	// L229
              int8_t v132 = v122[v123][v130][v131][1];	// L230
              v122[v123][v130][v131][0] = v132;	// L231
              int8_t v133 = v122[v123][v130][v131][2];	// L232
              v122[v123][v130][v131][1] = v133;	// L233
              int8_t v134 = v121[v123][v130][v131][v125];	// L234
              v122[v123][v130][v131][2] = v134;	// L235
            }
          }
          if ((v125 - 2) >= 0) {	// L238
            int8_t v135[1024];	// L239
            #pragma HLS bind_storage variable=v135 type=ram_2p impl=bram

            for (int v136 = 0; v136 < 1024; v136 += 1) {	// L240
              #pragma HLS pipeline II=1
              for (int v137 = 0; v137 < 1; v137 += 1) {	// L241
                v135[(v136 + v137)] = (int8_t)0.000000;	// L242
                for (int v138 = 0; v138 < 3; v138 += 1) {	// L243
                  for (int v139 = 0; v139 < 3; v139 += 1) {	// L244
                    int8_t v140 = v122[v123][(v136 + v137)][v138][v139];	// L245
                    int8_t v141 = v109[(v136 + v137)][v138][v139];	// L246
                    int8_t v142 = v140 * v141;	// L247
                    int8_t v143 = v135[(v136 + v137)];	// L248
                    int8_t v144 = v143 + v142;	// L249
                    v135[(v136 + v137)] = v144;	// L250
                  }
                }
                int8_t v145 = v135[(v136 + v137)];	// L253
                v120[v123][(v136 + v137)][(v124 - 2)][(v125 - 2)] = v145;	// L254
              }
            }
          }
        }
      }
    }
  }
  for (int v146 = 0; v146 < 1; v146 += 1) {	// L262
    for (int v147 = 0; v147 < 7; v147 += 1) {	// L263
      for (int v148 = 0; v148 < 7; v148 += 1) {	// L264
        for (int v149 = 0; v149 < 1024; v149 += 1) {	// L265
          int8_t v150 = v120[0][v149][v147][v148];	// L266
          bool v151 = v150 > (int8_t)0.000000;	// L267
          int8_t v152 = v151 ? v150 : (int8_t)0.000000;	// L268
          v111[v146][v149][v147][v148] = v152;	// L269
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v153[1024][512][1][1],
  int8_t v154[1][512][7][7],
  int8_t v155[1][1024][7][7]
) {	// L276
  #pragma HLS dataflow

  int8_t v156[1][1024][7][7];	// L278
  #pragma HLS stream variable=v156 depth=10 type=fifo

  #pragma HLS bind_storage variable=v156 type=ram_t2p impl=bram

  int8_t v157[1][512][1][7];	// L279
  #pragma HLS bind_storage variable=v157 type=ram_2p impl=bram

  int8_t v158[1][512][1][1];	// L280
  #pragma HLS array_partition variable=v158 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v158 type=ram_2p impl=lutram

  for (int v159 = 0; v159 < 1; v159 += 1) {	// L281
    for (int v160 = 0; v160 < 7; v160 += 1) {	// L282
      for (int v161 = 0; v161 < 7; v161 += 1) {	// L283
        for (int v162 = 0; v162 < 512; v162 += 1) {	// L284
          int8_t v163 = v154[v159][v162][v160][v161];	// L285
          v157[v159][v162][0][v161] = v163;	// L286
        }
        if (v160 >= 0) {	// L288
          for (int v164 = 0; v164 < 512; v164 += 1) {	// L289
            for (int v165 = 0; v165 < 1; v165 += 1) {	// L290
              int8_t v166 = v157[v159][v164][v165][v161];	// L291
              v158[v159][v164][v165][0] = v166;	// L292
            }
          }
          if (v161 >= 0) {	// L295
            int8_t v167[1024];	// L296
            #pragma HLS bind_storage variable=v167 type=ram_2p impl=bram

            for (int v168 = 0; v168 < 1024; v168 += 1) {	// L297
              v167[v168] = (int8_t)0.000000;	// L298
              for (int v169 = 0; v169 < 32; v169 += 1) {	// L299
                #pragma HLS pipeline II=1
                for (int v170 = 0; v170 < 16; v170 += 1) {	// L300
                  for (int v171 = 0; v171 < 1; v171 += 1) {	// L301
                    for (int v172 = 0; v172 < 1; v172 += 1) {	// L302
                      int8_t v173 = v158[v159][(v170 + (v169 * 16))][v171][v172];	// L303
                      int8_t v174 = v153[v168][(v170 + (v169 * 16))][v171][v172];	// L304
                      int8_t v175 = v173 * v174;	// L305
                      int8_t v176 = v167[v168];	// L306
                      int8_t v177 = v176 + v175;	// L307
                      v167[v168] = v177;	// L308
                    }
                  }
                }
              }
              int8_t v178 = v167[v168];	// L313
              v156[v159][v168][v160][v161] = v178;	// L314
            }
          }
        }
      }
    }
  }
  for (int v179 = 0; v179 < 1; v179 += 1) {	// L321
    for (int v180 = 0; v180 < 7; v180 += 1) {	// L322
      for (int v181 = 0; v181 < 7; v181 += 1) {	// L323
        for (int v182 = 0; v182 < 1024; v182 += 1) {	// L324
          int8_t v183 = v156[0][v182][v180][v181];	// L325
          bool v184 = v183 > (int8_t)0.000000;	// L326
          int8_t v185 = v184 ? v183 : (int8_t)0.000000;	// L327
          v155[v179][v182][v180][v181] = v185;	// L328
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v186[512][3][3],
  int8_t v187[1][512][14][14],
  int8_t v188[1][512][7][7]
) {	// L335
  #pragma HLS dataflow

  int8_t v189[1][512][16][16];	// L337
  #pragma HLS stream variable=v189 depth=10 type=fifo

  #pragma HLS bind_storage variable=v189 type=ram_t2p impl=bram

  for (int v190 = 0; v190 < 1; v190 += 1) {	// L338
    for (int v191 = 0; v191 < 16; v191 += 1) {	// L339
      for (int v192 = 0; v192 < 16; v192 += 1) {	// L340
        for (int v193 = 0; v193 < 512; v193 += 1) {	// L341
          int8_t v194;	// L342
          v194 = (int8_t)0.000000;	// L343
          if (((-v191) + 13) >= 0 && ((-v192) + 13) >= 0) {	// L344
            int8_t v195 = v187[v190][v193][v191][v192];	// L345
            v194 = v195;	// L346
          }
          int8_t v196 = v194;	// L348
          v189[v190][v193][v191][v192] = v196;	// L349
        }
      }
    }
  }
  int8_t v197[1][512][7][7];	// L354
  #pragma HLS stream variable=v197 depth=10 type=fifo

  #pragma HLS bind_storage variable=v197 type=ram_t2p impl=bram

  int8_t v198[1][512][3][16];	// L355
  #pragma HLS array_partition variable=v198 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v198 type=ram_2p impl=bram

  int8_t v199[1][512][3][3];	// L356
  #pragma HLS array_partition variable=v199 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v199 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v199 type=ram_2p impl=lutram

  for (int v200 = 0; v200 < 1; v200 += 1) {	// L357
    for (int v201 = 0; v201 < 16; v201 += 1) {	// L358
      for (int v202 = 0; v202 < 16; v202 += 1) {	// L359
        for (int v203 = 0; v203 < 512; v203 += 1) {	// L360
          int8_t v204 = v198[v200][v203][1][v202];	// L361
          v198[v200][v203][0][v202] = v204;	// L362
          int8_t v205 = v198[v200][v203][2][v202];	// L363
          v198[v200][v203][1][v202] = v205;	// L364
          int8_t v206 = v189[v200][v203][v201][v202];	// L365
          v198[v200][v203][2][v202] = v206;	// L366
        }
        if ((v201 - 9) >= 0) {	// L368
          for (int v207 = 0; v207 < 512; v207 += 1) {	// L369
            for (int v208 = 0; v208 < 3; v208 += 1) {	// L370
              int8_t v209 = v199[v200][v207][v208][1];	// L371
              v199[v200][v207][v208][0] = v209;	// L372
              int8_t v210 = v199[v200][v207][v208][2];	// L373
              v199[v200][v207][v208][1] = v210;	// L374
              int8_t v211 = v198[v200][v207][v208][v202];	// L375
              v199[v200][v207][v208][2] = v211;	// L376
            }
          }
          if ((v202 - 9) >= 0) {	// L379
            int8_t v212[512];	// L380
            #pragma HLS bind_storage variable=v212 type=ram_2p impl=bram

            for (int v213 = 0; v213 < 512; v213 += 1) {	// L381
              #pragma HLS pipeline II=1
              for (int v214 = 0; v214 < 1; v214 += 1) {	// L382
                v212[(v213 + v214)] = (int8_t)0.000000;	// L383
                for (int v215 = 0; v215 < 3; v215 += 1) {	// L384
                  for (int v216 = 0; v216 < 3; v216 += 1) {	// L385
                    int8_t v217 = v199[v200][(v213 + v214)][v215][v216];	// L386
                    int8_t v218 = v186[(v213 + v214)][v215][v216];	// L387
                    int8_t v219 = v217 * v218;	// L388
                    int8_t v220 = v212[(v213 + v214)];	// L389
                    int8_t v221 = v220 + v219;	// L390
                    v212[(v213 + v214)] = v221;	// L391
                  }
                }
                int8_t v222 = v212[(v213 + v214)];	// L394
                v197[v200][(v213 + v214)][(v201 - 9)][(v202 - 9)] = v222;	// L395
              }
            }
          }
        }
      }
    }
  }
  for (int v223 = 0; v223 < 1; v223 += 1) {	// L403
    for (int v224 = 0; v224 < 7; v224 += 1) {	// L404
      for (int v225 = 0; v225 < 7; v225 += 1) {	// L405
        for (int v226 = 0; v226 < 512; v226 += 1) {	// L406
          int8_t v227 = v197[0][v226][v224][v225];	// L407
          bool v228 = v227 > (int8_t)0.000000;	// L408
          int8_t v229 = v228 ? v227 : (int8_t)0.000000;	// L409
          v188[v223][v226][v224][v225] = v229;	// L410
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v230[1][512][14][14],
  int8_t v231[512][512][1][1],
  int8_t v232[1][512][14][14]
) {	// L417
  #pragma HLS dataflow

  int8_t v233[1][512][14][14];	// L419
  #pragma HLS stream variable=v233 depth=10 type=fifo

  #pragma HLS bind_storage variable=v233 type=ram_t2p impl=bram

  int8_t v234[1][512][1][14];	// L420
  #pragma HLS bind_storage variable=v234 type=ram_2p impl=bram

  int8_t v235[1][512][1][1];	// L421
  #pragma HLS array_partition variable=v235 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v235 type=ram_2p impl=lutram

  for (int v236 = 0; v236 < 1; v236 += 1) {	// L422
    for (int v237 = 0; v237 < 14; v237 += 1) {	// L423
      for (int v238 = 0; v238 < 14; v238 += 1) {	// L424
        for (int v239 = 0; v239 < 512; v239 += 1) {	// L425
          int8_t v240 = v230[v236][v239][v237][v238];	// L426
          v234[v236][v239][0][v238] = v240;	// L427
        }
        if (v237 >= 0) {	// L429
          for (int v241 = 0; v241 < 512; v241 += 1) {	// L430
            for (int v242 = 0; v242 < 1; v242 += 1) {	// L431
              int8_t v243 = v234[v236][v241][v242][v238];	// L432
              v235[v236][v241][v242][0] = v243;	// L433
            }
          }
          if (v238 >= 0) {	// L436
            int8_t v244[512];	// L437
            #pragma HLS bind_storage variable=v244 type=ram_2p impl=bram

            for (int v245 = 0; v245 < 512; v245 += 1) {	// L438
              v244[v245] = (int8_t)0.000000;	// L439
              for (int v246 = 0; v246 < 16; v246 += 1) {	// L440
                #pragma HLS pipeline II=1
                for (int v247 = 0; v247 < 32; v247 += 1) {	// L441
                  for (int v248 = 0; v248 < 1; v248 += 1) {	// L442
                    for (int v249 = 0; v249 < 1; v249 += 1) {	// L443
                      int8_t v250 = v235[v236][(v247 + (v246 * 32))][v248][v249];	// L444
                      int8_t v251 = v231[v245][(v247 + (v246 * 32))][v248][v249];	// L445
                      int8_t v252 = v250 * v251;	// L446
                      int8_t v253 = v244[v245];	// L447
                      int8_t v254 = v253 + v252;	// L448
                      v244[v245] = v254;	// L449
                    }
                  }
                }
              }
              int8_t v255 = v244[v245];	// L454
              v233[v236][v245][v237][v238] = v255;	// L455
            }
          }
        }
      }
    }
  }
  for (int v256 = 0; v256 < 1; v256 += 1) {	// L462
    for (int v257 = 0; v257 < 14; v257 += 1) {	// L463
      for (int v258 = 0; v258 < 14; v258 += 1) {	// L464
        for (int v259 = 0; v259 < 512; v259 += 1) {	// L465
          int8_t v260 = v233[0][v259][v257][v258];	// L466
          bool v261 = v260 > (int8_t)0.000000;	// L467
          int8_t v262 = v261 ? v260 : (int8_t)0.000000;	// L468
          v232[v256][v259][v257][v258] = v262;	// L469
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v263[1][512][14][14],
  int8_t v264[512][3][3],
  int8_t v265[1][512][14][14]
) {	// L476
  #pragma HLS dataflow

  int8_t v266[1][512][16][16];	// L478
  #pragma HLS stream variable=v266 depth=10 type=fifo

  #pragma HLS bind_storage variable=v266 type=ram_t2p impl=bram

  for (int v267 = 0; v267 < 1; v267 += 1) {	// L479
    for (int v268 = 0; v268 < 16; v268 += 1) {	// L480
      for (int v269 = 0; v269 < 16; v269 += 1) {	// L481
        for (int v270 = 0; v270 < 512; v270 += 1) {	// L482
          int8_t v271;	// L483
          v271 = (int8_t)0.000000;	// L484
          if (((-v268) + 13) >= 0 && ((-v269) + 13) >= 0) {	// L485
            int8_t v272 = v263[v267][v270][v268][v269];	// L486
            v271 = v272;	// L487
          }
          int8_t v273 = v271;	// L489
          v266[v267][v270][v268][v269] = v273;	// L490
        }
      }
    }
  }
  int8_t v274[1][512][14][14];	// L495
  #pragma HLS stream variable=v274 depth=10 type=fifo

  #pragma HLS bind_storage variable=v274 type=ram_t2p impl=bram

  int8_t v275[1][512][3][16];	// L496
  #pragma HLS array_partition variable=v275 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v275 type=ram_2p impl=bram

  int8_t v276[1][512][3][3];	// L497
  #pragma HLS array_partition variable=v276 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v276 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v276 type=ram_2p impl=lutram

  for (int v277 = 0; v277 < 1; v277 += 1) {	// L498
    for (int v278 = 0; v278 < 16; v278 += 1) {	// L499
      for (int v279 = 0; v279 < 16; v279 += 1) {	// L500
        for (int v280 = 0; v280 < 512; v280 += 1) {	// L501
          int8_t v281 = v275[v277][v280][1][v279];	// L502
          v275[v277][v280][0][v279] = v281;	// L503
          int8_t v282 = v275[v277][v280][2][v279];	// L504
          v275[v277][v280][1][v279] = v282;	// L505
          int8_t v283 = v266[v277][v280][v278][v279];	// L506
          v275[v277][v280][2][v279] = v283;	// L507
        }
        if ((v278 - 2) >= 0) {	// L509
          for (int v284 = 0; v284 < 512; v284 += 1) {	// L510
            for (int v285 = 0; v285 < 3; v285 += 1) {	// L511
              int8_t v286 = v276[v277][v284][v285][1];	// L512
              v276[v277][v284][v285][0] = v286;	// L513
              int8_t v287 = v276[v277][v284][v285][2];	// L514
              v276[v277][v284][v285][1] = v287;	// L515
              int8_t v288 = v275[v277][v284][v285][v279];	// L516
              v276[v277][v284][v285][2] = v288;	// L517
            }
          }
          if ((v279 - 2) >= 0) {	// L520
            int8_t v289[512];	// L521
            #pragma HLS bind_storage variable=v289 type=ram_2p impl=bram

            for (int v290 = 0; v290 < 512; v290 += 1) {	// L522
              #pragma HLS pipeline II=1
              for (int v291 = 0; v291 < 1; v291 += 1) {	// L523
                v289[(v290 + v291)] = (int8_t)0.000000;	// L524
                for (int v292 = 0; v292 < 3; v292 += 1) {	// L525
                  for (int v293 = 0; v293 < 3; v293 += 1) {	// L526
                    int8_t v294 = v276[v277][(v290 + v291)][v292][v293];	// L527
                    int8_t v295 = v264[(v290 + v291)][v292][v293];	// L528
                    int8_t v296 = v294 * v295;	// L529
                    int8_t v297 = v289[(v290 + v291)];	// L530
                    int8_t v298 = v297 + v296;	// L531
                    v289[(v290 + v291)] = v298;	// L532
                  }
                }
                int8_t v299 = v289[(v290 + v291)];	// L535
                v274[v277][(v290 + v291)][(v278 - 2)][(v279 - 2)] = v299;	// L536
              }
            }
          }
        }
      }
    }
  }
  for (int v300 = 0; v300 < 1; v300 += 1) {	// L544
    for (int v301 = 0; v301 < 14; v301 += 1) {	// L545
      for (int v302 = 0; v302 < 14; v302 += 1) {	// L546
        for (int v303 = 0; v303 < 512; v303 += 1) {	// L547
          int8_t v304 = v274[0][v303][v301][v302];	// L548
          bool v305 = v304 > (int8_t)0.000000;	// L549
          int8_t v306 = v305 ? v304 : (int8_t)0.000000;	// L550
          v265[v300][v303][v301][v302] = v306;	// L551
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v307[512][512][1][1],
  int8_t v308[1][512][14][14],
  int8_t v309[1][512][14][14]
) {	// L558
  #pragma HLS dataflow

  int8_t v310[1][512][14][14];	// L560
  #pragma HLS stream variable=v310 depth=10 type=fifo

  #pragma HLS bind_storage variable=v310 type=ram_t2p impl=bram

  int8_t v311[1][512][1][14];	// L561
  #pragma HLS bind_storage variable=v311 type=ram_2p impl=bram

  int8_t v312[1][512][1][1];	// L562
  #pragma HLS array_partition variable=v312 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v312 type=ram_2p impl=lutram

  for (int v313 = 0; v313 < 1; v313 += 1) {	// L563
    for (int v314 = 0; v314 < 14; v314 += 1) {	// L564
      for (int v315 = 0; v315 < 14; v315 += 1) {	// L565
        for (int v316 = 0; v316 < 512; v316 += 1) {	// L566
          int8_t v317 = v308[v313][v316][v314][v315];	// L567
          v311[v313][v316][0][v315] = v317;	// L568
        }
        if (v314 >= 0) {	// L570
          for (int v318 = 0; v318 < 512; v318 += 1) {	// L571
            for (int v319 = 0; v319 < 1; v319 += 1) {	// L572
              int8_t v320 = v311[v313][v318][v319][v315];	// L573
              v312[v313][v318][v319][0] = v320;	// L574
            }
          }
          if (v315 >= 0) {	// L577
            int8_t v321[512];	// L578
            #pragma HLS bind_storage variable=v321 type=ram_2p impl=bram

            for (int v322 = 0; v322 < 512; v322 += 1) {	// L579
              v321[v322] = (int8_t)0.000000;	// L580
              for (int v323 = 0; v323 < 16; v323 += 1) {	// L581
                #pragma HLS pipeline II=1
                for (int v324 = 0; v324 < 32; v324 += 1) {	// L582
                  for (int v325 = 0; v325 < 1; v325 += 1) {	// L583
                    for (int v326 = 0; v326 < 1; v326 += 1) {	// L584
                      int8_t v327 = v312[v313][(v324 + (v323 * 32))][v325][v326];	// L585
                      int8_t v328 = v307[v322][(v324 + (v323 * 32))][v325][v326];	// L586
                      int8_t v329 = v327 * v328;	// L587
                      int8_t v330 = v321[v322];	// L588
                      int8_t v331 = v330 + v329;	// L589
                      v321[v322] = v331;	// L590
                    }
                  }
                }
              }
              int8_t v332 = v321[v322];	// L595
              v310[v313][v322][v314][v315] = v332;	// L596
            }
          }
        }
      }
    }
  }
  for (int v333 = 0; v333 < 1; v333 += 1) {	// L603
    for (int v334 = 0; v334 < 14; v334 += 1) {	// L604
      for (int v335 = 0; v335 < 14; v335 += 1) {	// L605
        for (int v336 = 0; v336 < 512; v336 += 1) {	// L606
          int8_t v337 = v310[0][v336][v334][v335];	// L607
          bool v338 = v337 > (int8_t)0.000000;	// L608
          int8_t v339 = v338 ? v337 : (int8_t)0.000000;	// L609
          v309[v333][v336][v334][v335] = v339;	// L610
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v340[512][3][3],
  int8_t v341[1][512][14][14],
  int8_t v342[1][512][14][14]
) {	// L617
  #pragma HLS dataflow

  int8_t v343[1][512][16][16];	// L619
  #pragma HLS stream variable=v343 depth=10 type=fifo

  #pragma HLS bind_storage variable=v343 type=ram_t2p impl=bram

  for (int v344 = 0; v344 < 1; v344 += 1) {	// L620
    for (int v345 = 0; v345 < 16; v345 += 1) {	// L621
      for (int v346 = 0; v346 < 16; v346 += 1) {	// L622
        for (int v347 = 0; v347 < 512; v347 += 1) {	// L623
          int8_t v348;	// L624
          v348 = (int8_t)0.000000;	// L625
          if (((-v345) + 13) >= 0 && ((-v346) + 13) >= 0) {	// L626
            int8_t v349 = v341[v344][v347][v345][v346];	// L627
            v348 = v349;	// L628
          }
          int8_t v350 = v348;	// L630
          v343[v344][v347][v345][v346] = v350;	// L631
        }
      }
    }
  }
  int8_t v351[1][512][14][14];	// L636
  #pragma HLS stream variable=v351 depth=10 type=fifo

  #pragma HLS bind_storage variable=v351 type=ram_t2p impl=bram

  int8_t v352[1][512][3][16];	// L637
  #pragma HLS array_partition variable=v352 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v352 type=ram_2p impl=bram

  int8_t v353[1][512][3][3];	// L638
  #pragma HLS array_partition variable=v353 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v353 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v353 type=ram_2p impl=lutram

  for (int v354 = 0; v354 < 1; v354 += 1) {	// L639
    for (int v355 = 0; v355 < 16; v355 += 1) {	// L640
      for (int v356 = 0; v356 < 16; v356 += 1) {	// L641
        for (int v357 = 0; v357 < 512; v357 += 1) {	// L642
          int8_t v358 = v352[v354][v357][1][v356];	// L643
          v352[v354][v357][0][v356] = v358;	// L644
          int8_t v359 = v352[v354][v357][2][v356];	// L645
          v352[v354][v357][1][v356] = v359;	// L646
          int8_t v360 = v343[v354][v357][v355][v356];	// L647
          v352[v354][v357][2][v356] = v360;	// L648
        }
        if ((v355 - 2) >= 0) {	// L650
          for (int v361 = 0; v361 < 512; v361 += 1) {	// L651
            for (int v362 = 0; v362 < 3; v362 += 1) {	// L652
              int8_t v363 = v353[v354][v361][v362][1];	// L653
              v353[v354][v361][v362][0] = v363;	// L654
              int8_t v364 = v353[v354][v361][v362][2];	// L655
              v353[v354][v361][v362][1] = v364;	// L656
              int8_t v365 = v352[v354][v361][v362][v356];	// L657
              v353[v354][v361][v362][2] = v365;	// L658
            }
          }
          if ((v356 - 2) >= 0) {	// L661
            int8_t v366[512];	// L662
            #pragma HLS bind_storage variable=v366 type=ram_2p impl=bram

            for (int v367 = 0; v367 < 512; v367 += 1) {	// L663
              #pragma HLS pipeline II=1
              for (int v368 = 0; v368 < 1; v368 += 1) {	// L664
                v366[(v367 + v368)] = (int8_t)0.000000;	// L665
                for (int v369 = 0; v369 < 3; v369 += 1) {	// L666
                  for (int v370 = 0; v370 < 3; v370 += 1) {	// L667
                    int8_t v371 = v353[v354][(v367 + v368)][v369][v370];	// L668
                    int8_t v372 = v340[(v367 + v368)][v369][v370];	// L669
                    int8_t v373 = v371 * v372;	// L670
                    int8_t v374 = v366[(v367 + v368)];	// L671
                    int8_t v375 = v374 + v373;	// L672
                    v366[(v367 + v368)] = v375;	// L673
                  }
                }
                int8_t v376 = v366[(v367 + v368)];	// L676
                v351[v354][(v367 + v368)][(v355 - 2)][(v356 - 2)] = v376;	// L677
              }
            }
          }
        }
      }
    }
  }
  for (int v377 = 0; v377 < 1; v377 += 1) {	// L685
    for (int v378 = 0; v378 < 14; v378 += 1) {	// L686
      for (int v379 = 0; v379 < 14; v379 += 1) {	// L687
        for (int v380 = 0; v380 < 512; v380 += 1) {	// L688
          int8_t v381 = v351[0][v380][v378][v379];	// L689
          bool v382 = v381 > (int8_t)0.000000;	// L690
          int8_t v383 = v382 ? v381 : (int8_t)0.000000;	// L691
          v342[v377][v380][v378][v379] = v383;	// L692
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v384[1][512][14][14],
  int8_t v385[512][512][1][1],
  int8_t v386[1][512][14][14]
) {	// L699
  #pragma HLS dataflow

  int8_t v387[1][512][14][14];	// L701
  #pragma HLS stream variable=v387 depth=10 type=fifo

  #pragma HLS bind_storage variable=v387 type=ram_t2p impl=bram

  int8_t v388[1][512][1][14];	// L702
  #pragma HLS bind_storage variable=v388 type=ram_2p impl=bram

  int8_t v389[1][512][1][1];	// L703
  #pragma HLS array_partition variable=v389 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v389 type=ram_2p impl=lutram

  for (int v390 = 0; v390 < 1; v390 += 1) {	// L704
    for (int v391 = 0; v391 < 14; v391 += 1) {	// L705
      for (int v392 = 0; v392 < 14; v392 += 1) {	// L706
        for (int v393 = 0; v393 < 512; v393 += 1) {	// L707
          int8_t v394 = v384[v390][v393][v391][v392];	// L708
          v388[v390][v393][0][v392] = v394;	// L709
        }
        if (v391 >= 0) {	// L711
          for (int v395 = 0; v395 < 512; v395 += 1) {	// L712
            for (int v396 = 0; v396 < 1; v396 += 1) {	// L713
              int8_t v397 = v388[v390][v395][v396][v392];	// L714
              v389[v390][v395][v396][0] = v397;	// L715
            }
          }
          if (v392 >= 0) {	// L718
            int8_t v398[512];	// L719
            #pragma HLS bind_storage variable=v398 type=ram_2p impl=bram

            for (int v399 = 0; v399 < 512; v399 += 1) {	// L720
              v398[v399] = (int8_t)0.000000;	// L721
              for (int v400 = 0; v400 < 16; v400 += 1) {	// L722
                #pragma HLS pipeline II=1
                for (int v401 = 0; v401 < 32; v401 += 1) {	// L723
                  for (int v402 = 0; v402 < 1; v402 += 1) {	// L724
                    for (int v403 = 0; v403 < 1; v403 += 1) {	// L725
                      int8_t v404 = v389[v390][(v401 + (v400 * 32))][v402][v403];	// L726
                      int8_t v405 = v385[v399][(v401 + (v400 * 32))][v402][v403];	// L727
                      int8_t v406 = v404 * v405;	// L728
                      int8_t v407 = v398[v399];	// L729
                      int8_t v408 = v407 + v406;	// L730
                      v398[v399] = v408;	// L731
                    }
                  }
                }
              }
              int8_t v409 = v398[v399];	// L736
              v387[v390][v399][v391][v392] = v409;	// L737
            }
          }
        }
      }
    }
  }
  for (int v410 = 0; v410 < 1; v410 += 1) {	// L744
    for (int v411 = 0; v411 < 14; v411 += 1) {	// L745
      for (int v412 = 0; v412 < 14; v412 += 1) {	// L746
        for (int v413 = 0; v413 < 512; v413 += 1) {	// L747
          int8_t v414 = v387[0][v413][v411][v412];	// L748
          bool v415 = v414 > (int8_t)0.000000;	// L749
          int8_t v416 = v415 ? v414 : (int8_t)0.000000;	// L750
          v386[v410][v413][v411][v412] = v416;	// L751
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v417[1][512][14][14],
  int8_t v418[512][3][3],
  int8_t v419[1][512][14][14]
) {	// L758
  #pragma HLS dataflow

  int8_t v420[1][512][16][16];	// L760
  #pragma HLS stream variable=v420 depth=10 type=fifo

  #pragma HLS bind_storage variable=v420 type=ram_t2p impl=bram

  for (int v421 = 0; v421 < 1; v421 += 1) {	// L761
    for (int v422 = 0; v422 < 16; v422 += 1) {	// L762
      for (int v423 = 0; v423 < 16; v423 += 1) {	// L763
        for (int v424 = 0; v424 < 512; v424 += 1) {	// L764
          int8_t v425;	// L765
          v425 = (int8_t)0.000000;	// L766
          if (((-v422) + 13) >= 0 && ((-v423) + 13) >= 0) {	// L767
            int8_t v426 = v417[v421][v424][v422][v423];	// L768
            v425 = v426;	// L769
          }
          int8_t v427 = v425;	// L771
          v420[v421][v424][v422][v423] = v427;	// L772
        }
      }
    }
  }
  int8_t v428[1][512][14][14];	// L777
  #pragma HLS stream variable=v428 depth=10 type=fifo

  #pragma HLS bind_storage variable=v428 type=ram_t2p impl=bram

  int8_t v429[1][512][3][16];	// L778
  #pragma HLS array_partition variable=v429 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v429 type=ram_2p impl=bram

  int8_t v430[1][512][3][3];	// L779
  #pragma HLS array_partition variable=v430 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v430 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v430 type=ram_2p impl=lutram

  for (int v431 = 0; v431 < 1; v431 += 1) {	// L780
    for (int v432 = 0; v432 < 16; v432 += 1) {	// L781
      for (int v433 = 0; v433 < 16; v433 += 1) {	// L782
        for (int v434 = 0; v434 < 512; v434 += 1) {	// L783
          int8_t v435 = v429[v431][v434][1][v433];	// L784
          v429[v431][v434][0][v433] = v435;	// L785
          int8_t v436 = v429[v431][v434][2][v433];	// L786
          v429[v431][v434][1][v433] = v436;	// L787
          int8_t v437 = v420[v431][v434][v432][v433];	// L788
          v429[v431][v434][2][v433] = v437;	// L789
        }
        if ((v432 - 2) >= 0) {	// L791
          for (int v438 = 0; v438 < 512; v438 += 1) {	// L792
            for (int v439 = 0; v439 < 3; v439 += 1) {	// L793
              int8_t v440 = v430[v431][v438][v439][1];	// L794
              v430[v431][v438][v439][0] = v440;	// L795
              int8_t v441 = v430[v431][v438][v439][2];	// L796
              v430[v431][v438][v439][1] = v441;	// L797
              int8_t v442 = v429[v431][v438][v439][v433];	// L798
              v430[v431][v438][v439][2] = v442;	// L799
            }
          }
          if ((v433 - 2) >= 0) {	// L802
            int8_t v443[512];	// L803
            #pragma HLS bind_storage variable=v443 type=ram_2p impl=bram

            for (int v444 = 0; v444 < 512; v444 += 1) {	// L804
              #pragma HLS pipeline II=1
              for (int v445 = 0; v445 < 1; v445 += 1) {	// L805
                v443[(v444 + v445)] = (int8_t)0.000000;	// L806
                for (int v446 = 0; v446 < 3; v446 += 1) {	// L807
                  for (int v447 = 0; v447 < 3; v447 += 1) {	// L808
                    int8_t v448 = v430[v431][(v444 + v445)][v446][v447];	// L809
                    int8_t v449 = v418[(v444 + v445)][v446][v447];	// L810
                    int8_t v450 = v448 * v449;	// L811
                    int8_t v451 = v443[(v444 + v445)];	// L812
                    int8_t v452 = v451 + v450;	// L813
                    v443[(v444 + v445)] = v452;	// L814
                  }
                }
                int8_t v453 = v443[(v444 + v445)];	// L817
                v428[v431][(v444 + v445)][(v432 - 2)][(v433 - 2)] = v453;	// L818
              }
            }
          }
        }
      }
    }
  }
  for (int v454 = 0; v454 < 1; v454 += 1) {	// L826
    for (int v455 = 0; v455 < 14; v455 += 1) {	// L827
      for (int v456 = 0; v456 < 14; v456 += 1) {	// L828
        for (int v457 = 0; v457 < 512; v457 += 1) {	// L829
          int8_t v458 = v428[0][v457][v455][v456];	// L830
          bool v459 = v458 > (int8_t)0.000000;	// L831
          int8_t v460 = v459 ? v458 : (int8_t)0.000000;	// L832
          v419[v454][v457][v455][v456] = v460;	// L833
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v461[512][512][1][1],
  int8_t v462[1][512][14][14],
  int8_t v463[1][512][14][14]
) {	// L840
  #pragma HLS dataflow

  int8_t v464[1][512][14][14];	// L842
  #pragma HLS stream variable=v464 depth=10 type=fifo

  #pragma HLS bind_storage variable=v464 type=ram_t2p impl=bram

  int8_t v465[1][512][1][14];	// L843
  #pragma HLS bind_storage variable=v465 type=ram_2p impl=bram

  int8_t v466[1][512][1][1];	// L844
  #pragma HLS array_partition variable=v466 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v466 type=ram_2p impl=lutram

  for (int v467 = 0; v467 < 1; v467 += 1) {	// L845
    for (int v468 = 0; v468 < 14; v468 += 1) {	// L846
      for (int v469 = 0; v469 < 14; v469 += 1) {	// L847
        for (int v470 = 0; v470 < 512; v470 += 1) {	// L848
          int8_t v471 = v462[v467][v470][v468][v469];	// L849
          v465[v467][v470][0][v469] = v471;	// L850
        }
        if (v468 >= 0) {	// L852
          for (int v472 = 0; v472 < 512; v472 += 1) {	// L853
            for (int v473 = 0; v473 < 1; v473 += 1) {	// L854
              int8_t v474 = v465[v467][v472][v473][v469];	// L855
              v466[v467][v472][v473][0] = v474;	// L856
            }
          }
          if (v469 >= 0) {	// L859
            int8_t v475[512];	// L860
            #pragma HLS bind_storage variable=v475 type=ram_2p impl=bram

            for (int v476 = 0; v476 < 512; v476 += 1) {	// L861
              v475[v476] = (int8_t)0.000000;	// L862
              for (int v477 = 0; v477 < 16; v477 += 1) {	// L863
                #pragma HLS pipeline II=1
                for (int v478 = 0; v478 < 32; v478 += 1) {	// L864
                  for (int v479 = 0; v479 < 1; v479 += 1) {	// L865
                    for (int v480 = 0; v480 < 1; v480 += 1) {	// L866
                      int8_t v481 = v466[v467][(v478 + (v477 * 32))][v479][v480];	// L867
                      int8_t v482 = v461[v476][(v478 + (v477 * 32))][v479][v480];	// L868
                      int8_t v483 = v481 * v482;	// L869
                      int8_t v484 = v475[v476];	// L870
                      int8_t v485 = v484 + v483;	// L871
                      v475[v476] = v485;	// L872
                    }
                  }
                }
              }
              int8_t v486 = v475[v476];	// L877
              v464[v467][v476][v468][v469] = v486;	// L878
            }
          }
        }
      }
    }
  }
  for (int v487 = 0; v487 < 1; v487 += 1) {	// L885
    for (int v488 = 0; v488 < 14; v488 += 1) {	// L886
      for (int v489 = 0; v489 < 14; v489 += 1) {	// L887
        for (int v490 = 0; v490 < 512; v490 += 1) {	// L888
          int8_t v491 = v464[0][v490][v488][v489];	// L889
          bool v492 = v491 > (int8_t)0.000000;	// L890
          int8_t v493 = v492 ? v491 : (int8_t)0.000000;	// L891
          v463[v487][v490][v488][v489] = v493;	// L892
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v494[1][512][14][14],
  int8_t v495[512][3][3],
  int8_t v496[1][512][14][14]
) {	// L899
  #pragma HLS dataflow

  int8_t v497[1][512][16][16];	// L901
  #pragma HLS stream variable=v497 depth=10 type=fifo

  #pragma HLS bind_storage variable=v497 type=ram_t2p impl=bram

  for (int v498 = 0; v498 < 1; v498 += 1) {	// L902
    for (int v499 = 0; v499 < 16; v499 += 1) {	// L903
      for (int v500 = 0; v500 < 16; v500 += 1) {	// L904
        for (int v501 = 0; v501 < 512; v501 += 1) {	// L905
          int8_t v502;	// L906
          v502 = (int8_t)0.000000;	// L907
          if (((-v499) + 13) >= 0 && ((-v500) + 13) >= 0) {	// L908
            int8_t v503 = v494[v498][v501][v499][v500];	// L909
            v502 = v503;	// L910
          }
          int8_t v504 = v502;	// L912
          v497[v498][v501][v499][v500] = v504;	// L913
        }
      }
    }
  }
  int8_t v505[1][512][14][14];	// L918
  #pragma HLS stream variable=v505 depth=10 type=fifo

  #pragma HLS bind_storage variable=v505 type=ram_t2p impl=bram

  int8_t v506[1][512][3][16];	// L919
  #pragma HLS array_partition variable=v506 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v506 type=ram_2p impl=bram

  int8_t v507[1][512][3][3];	// L920
  #pragma HLS array_partition variable=v507 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v507 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v507 type=ram_2p impl=lutram

  for (int v508 = 0; v508 < 1; v508 += 1) {	// L921
    for (int v509 = 0; v509 < 16; v509 += 1) {	// L922
      for (int v510 = 0; v510 < 16; v510 += 1) {	// L923
        for (int v511 = 0; v511 < 512; v511 += 1) {	// L924
          int8_t v512 = v506[v508][v511][1][v510];	// L925
          v506[v508][v511][0][v510] = v512;	// L926
          int8_t v513 = v506[v508][v511][2][v510];	// L927
          v506[v508][v511][1][v510] = v513;	// L928
          int8_t v514 = v497[v508][v511][v509][v510];	// L929
          v506[v508][v511][2][v510] = v514;	// L930
        }
        if ((v509 - 2) >= 0) {	// L932
          for (int v515 = 0; v515 < 512; v515 += 1) {	// L933
            for (int v516 = 0; v516 < 3; v516 += 1) {	// L934
              int8_t v517 = v507[v508][v515][v516][1];	// L935
              v507[v508][v515][v516][0] = v517;	// L936
              int8_t v518 = v507[v508][v515][v516][2];	// L937
              v507[v508][v515][v516][1] = v518;	// L938
              int8_t v519 = v506[v508][v515][v516][v510];	// L939
              v507[v508][v515][v516][2] = v519;	// L940
            }
          }
          if ((v510 - 2) >= 0) {	// L943
            int8_t v520[512];	// L944
            #pragma HLS bind_storage variable=v520 type=ram_2p impl=bram

            for (int v521 = 0; v521 < 512; v521 += 1) {	// L945
              #pragma HLS pipeline II=1
              for (int v522 = 0; v522 < 1; v522 += 1) {	// L946
                v520[(v521 + v522)] = (int8_t)0.000000;	// L947
                for (int v523 = 0; v523 < 3; v523 += 1) {	// L948
                  for (int v524 = 0; v524 < 3; v524 += 1) {	// L949
                    int8_t v525 = v507[v508][(v521 + v522)][v523][v524];	// L950
                    int8_t v526 = v495[(v521 + v522)][v523][v524];	// L951
                    int8_t v527 = v525 * v526;	// L952
                    int8_t v528 = v520[(v521 + v522)];	// L953
                    int8_t v529 = v528 + v527;	// L954
                    v520[(v521 + v522)] = v529;	// L955
                  }
                }
                int8_t v530 = v520[(v521 + v522)];	// L958
                v505[v508][(v521 + v522)][(v509 - 2)][(v510 - 2)] = v530;	// L959
              }
            }
          }
        }
      }
    }
  }
  for (int v531 = 0; v531 < 1; v531 += 1) {	// L967
    for (int v532 = 0; v532 < 14; v532 += 1) {	// L968
      for (int v533 = 0; v533 < 14; v533 += 1) {	// L969
        for (int v534 = 0; v534 < 512; v534 += 1) {	// L970
          int8_t v535 = v505[0][v534][v532][v533];	// L971
          bool v536 = v535 > (int8_t)0.000000;	// L972
          int8_t v537 = v536 ? v535 : (int8_t)0.000000;	// L973
          v496[v531][v534][v532][v533] = v537;	// L974
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v538[512][512][1][1],
  int8_t v539[1][512][14][14],
  int8_t v540[1][512][14][14]
) {	// L981
  #pragma HLS dataflow

  int8_t v541[1][512][14][14];	// L983
  #pragma HLS stream variable=v541 depth=10 type=fifo

  #pragma HLS bind_storage variable=v541 type=ram_t2p impl=bram

  int8_t v542[1][512][1][14];	// L984
  #pragma HLS bind_storage variable=v542 type=ram_2p impl=bram

  int8_t v543[1][512][1][1];	// L985
  #pragma HLS array_partition variable=v543 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v543 type=ram_2p impl=lutram

  for (int v544 = 0; v544 < 1; v544 += 1) {	// L986
    for (int v545 = 0; v545 < 14; v545 += 1) {	// L987
      for (int v546 = 0; v546 < 14; v546 += 1) {	// L988
        for (int v547 = 0; v547 < 512; v547 += 1) {	// L989
          int8_t v548 = v539[v544][v547][v545][v546];	// L990
          v542[v544][v547][0][v546] = v548;	// L991
        }
        if (v545 >= 0) {	// L993
          for (int v549 = 0; v549 < 512; v549 += 1) {	// L994
            for (int v550 = 0; v550 < 1; v550 += 1) {	// L995
              int8_t v551 = v542[v544][v549][v550][v546];	// L996
              v543[v544][v549][v550][0] = v551;	// L997
            }
          }
          if (v546 >= 0) {	// L1000
            int8_t v552[512];	// L1001
            #pragma HLS bind_storage variable=v552 type=ram_2p impl=bram

            for (int v553 = 0; v553 < 512; v553 += 1) {	// L1002
              v552[v553] = (int8_t)0.000000;	// L1003
              for (int v554 = 0; v554 < 16; v554 += 1) {	// L1004
                #pragma HLS pipeline II=1
                for (int v555 = 0; v555 < 32; v555 += 1) {	// L1005
                  for (int v556 = 0; v556 < 1; v556 += 1) {	// L1006
                    for (int v557 = 0; v557 < 1; v557 += 1) {	// L1007
                      int8_t v558 = v543[v544][(v555 + (v554 * 32))][v556][v557];	// L1008
                      int8_t v559 = v538[v553][(v555 + (v554 * 32))][v556][v557];	// L1009
                      int8_t v560 = v558 * v559;	// L1010
                      int8_t v561 = v552[v553];	// L1011
                      int8_t v562 = v561 + v560;	// L1012
                      v552[v553] = v562;	// L1013
                    }
                  }
                }
              }
              int8_t v563 = v552[v553];	// L1018
              v541[v544][v553][v545][v546] = v563;	// L1019
            }
          }
        }
      }
    }
  }
  for (int v564 = 0; v564 < 1; v564 += 1) {	// L1026
    for (int v565 = 0; v565 < 14; v565 += 1) {	// L1027
      for (int v566 = 0; v566 < 14; v566 += 1) {	// L1028
        for (int v567 = 0; v567 < 512; v567 += 1) {	// L1029
          int8_t v568 = v541[0][v567][v565][v566];	// L1030
          bool v569 = v568 > (int8_t)0.000000;	// L1031
          int8_t v570 = v569 ? v568 : (int8_t)0.000000;	// L1032
          v540[v564][v567][v565][v566] = v570;	// L1033
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v571[512][3][3],
  int8_t v572[1][512][14][14],
  int8_t v573[1][512][14][14]
) {	// L1040
  #pragma HLS dataflow

  int8_t v574[1][512][16][16];	// L1042
  #pragma HLS stream variable=v574 depth=10 type=fifo

  #pragma HLS bind_storage variable=v574 type=ram_t2p impl=bram

  for (int v575 = 0; v575 < 1; v575 += 1) {	// L1043
    for (int v576 = 0; v576 < 16; v576 += 1) {	// L1044
      for (int v577 = 0; v577 < 16; v577 += 1) {	// L1045
        for (int v578 = 0; v578 < 512; v578 += 1) {	// L1046
          int8_t v579;	// L1047
          v579 = (int8_t)0.000000;	// L1048
          if (((-v576) + 13) >= 0 && ((-v577) + 13) >= 0) {	// L1049
            int8_t v580 = v572[v575][v578][v576][v577];	// L1050
            v579 = v580;	// L1051
          }
          int8_t v581 = v579;	// L1053
          v574[v575][v578][v576][v577] = v581;	// L1054
        }
      }
    }
  }
  int8_t v582[1][512][14][14];	// L1059
  #pragma HLS stream variable=v582 depth=10 type=fifo

  #pragma HLS bind_storage variable=v582 type=ram_t2p impl=bram

  int8_t v583[1][512][3][16];	// L1060
  #pragma HLS array_partition variable=v583 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v583 type=ram_2p impl=bram

  int8_t v584[1][512][3][3];	// L1061
  #pragma HLS array_partition variable=v584 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v584 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v584 type=ram_2p impl=lutram

  for (int v585 = 0; v585 < 1; v585 += 1) {	// L1062
    for (int v586 = 0; v586 < 16; v586 += 1) {	// L1063
      for (int v587 = 0; v587 < 16; v587 += 1) {	// L1064
        for (int v588 = 0; v588 < 512; v588 += 1) {	// L1065
          int8_t v589 = v583[v585][v588][1][v587];	// L1066
          v583[v585][v588][0][v587] = v589;	// L1067
          int8_t v590 = v583[v585][v588][2][v587];	// L1068
          v583[v585][v588][1][v587] = v590;	// L1069
          int8_t v591 = v574[v585][v588][v586][v587];	// L1070
          v583[v585][v588][2][v587] = v591;	// L1071
        }
        if ((v586 - 2) >= 0) {	// L1073
          for (int v592 = 0; v592 < 512; v592 += 1) {	// L1074
            for (int v593 = 0; v593 < 3; v593 += 1) {	// L1075
              int8_t v594 = v584[v585][v592][v593][1];	// L1076
              v584[v585][v592][v593][0] = v594;	// L1077
              int8_t v595 = v584[v585][v592][v593][2];	// L1078
              v584[v585][v592][v593][1] = v595;	// L1079
              int8_t v596 = v583[v585][v592][v593][v587];	// L1080
              v584[v585][v592][v593][2] = v596;	// L1081
            }
          }
          if ((v587 - 2) >= 0) {	// L1084
            int8_t v597[512];	// L1085
            #pragma HLS bind_storage variable=v597 type=ram_2p impl=bram

            for (int v598 = 0; v598 < 512; v598 += 1) {	// L1086
              #pragma HLS pipeline II=1
              for (int v599 = 0; v599 < 1; v599 += 1) {	// L1087
                v597[(v598 + v599)] = (int8_t)0.000000;	// L1088
                for (int v600 = 0; v600 < 3; v600 += 1) {	// L1089
                  for (int v601 = 0; v601 < 3; v601 += 1) {	// L1090
                    int8_t v602 = v584[v585][(v598 + v599)][v600][v601];	// L1091
                    int8_t v603 = v571[(v598 + v599)][v600][v601];	// L1092
                    int8_t v604 = v602 * v603;	// L1093
                    int8_t v605 = v597[(v598 + v599)];	// L1094
                    int8_t v606 = v605 + v604;	// L1095
                    v597[(v598 + v599)] = v606;	// L1096
                  }
                }
                int8_t v607 = v597[(v598 + v599)];	// L1099
                v582[v585][(v598 + v599)][(v586 - 2)][(v587 - 2)] = v607;	// L1100
              }
            }
          }
        }
      }
    }
  }
  for (int v608 = 0; v608 < 1; v608 += 1) {	// L1108
    for (int v609 = 0; v609 < 14; v609 += 1) {	// L1109
      for (int v610 = 0; v610 < 14; v610 += 1) {	// L1110
        for (int v611 = 0; v611 < 512; v611 += 1) {	// L1111
          int8_t v612 = v582[0][v611][v609][v610];	// L1112
          bool v613 = v612 > (int8_t)0.000000;	// L1113
          int8_t v614 = v613 ? v612 : (int8_t)0.000000;	// L1114
          v573[v608][v611][v609][v610] = v614;	// L1115
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v615[512][256][1][1],
  int8_t v616[1][256][14][14],
  int8_t v617[1][512][14][14]
) {	// L1122
  #pragma HLS dataflow

  int8_t v618[1][512][14][14];	// L1124
  #pragma HLS stream variable=v618 depth=10 type=fifo

  #pragma HLS bind_storage variable=v618 type=ram_t2p impl=bram

  int8_t v619[1][256][1][14];	// L1125
  #pragma HLS bind_storage variable=v619 type=ram_2p impl=bram

  int8_t v620[1][256][1][1];	// L1126
  #pragma HLS array_partition variable=v620 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v620 type=ram_2p impl=lutram

  for (int v621 = 0; v621 < 1; v621 += 1) {	// L1127
    for (int v622 = 0; v622 < 14; v622 += 1) {	// L1128
      for (int v623 = 0; v623 < 14; v623 += 1) {	// L1129
        for (int v624 = 0; v624 < 256; v624 += 1) {	// L1130
          int8_t v625 = v616[v621][v624][v622][v623];	// L1131
          v619[v621][v624][0][v623] = v625;	// L1132
        }
        if (v622 >= 0) {	// L1134
          for (int v626 = 0; v626 < 256; v626 += 1) {	// L1135
            for (int v627 = 0; v627 < 1; v627 += 1) {	// L1136
              int8_t v628 = v619[v621][v626][v627][v623];	// L1137
              v620[v621][v626][v627][0] = v628;	// L1138
            }
          }
          if (v623 >= 0) {	// L1141
            int8_t v629[512];	// L1142
            #pragma HLS bind_storage variable=v629 type=ram_2p impl=bram

            for (int v630 = 0; v630 < 512; v630 += 1) {	// L1143
              v629[v630] = (int8_t)0.000000;	// L1144
              for (int v631 = 0; v631 < 16; v631 += 1) {	// L1145
                #pragma HLS pipeline II=1
                for (int v632 = 0; v632 < 16; v632 += 1) {	// L1146
                  for (int v633 = 0; v633 < 1; v633 += 1) {	// L1147
                    for (int v634 = 0; v634 < 1; v634 += 1) {	// L1148
                      int8_t v635 = v620[v621][(v632 + (v631 * 16))][v633][v634];	// L1149
                      int8_t v636 = v615[v630][(v632 + (v631 * 16))][v633][v634];	// L1150
                      int8_t v637 = v635 * v636;	// L1151
                      int8_t v638 = v629[v630];	// L1152
                      int8_t v639 = v638 + v637;	// L1153
                      v629[v630] = v639;	// L1154
                    }
                  }
                }
              }
              int8_t v640 = v629[v630];	// L1159
              v618[v621][v630][v622][v623] = v640;	// L1160
            }
          }
        }
      }
    }
  }
  for (int v641 = 0; v641 < 1; v641 += 1) {	// L1167
    for (int v642 = 0; v642 < 14; v642 += 1) {	// L1168
      for (int v643 = 0; v643 < 14; v643 += 1) {	// L1169
        for (int v644 = 0; v644 < 512; v644 += 1) {	// L1170
          int8_t v645 = v618[0][v644][v642][v643];	// L1171
          bool v646 = v645 > (int8_t)0.000000;	// L1172
          int8_t v647 = v646 ? v645 : (int8_t)0.000000;	// L1173
          v617[v641][v644][v642][v643] = v647;	// L1174
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v648[1][256][28][28],
  int8_t v649[256][3][3],
  int8_t v650[1][256][14][14]
) {	// L1181
  #pragma HLS dataflow

  int8_t v651[1][256][30][30];	// L1183
  #pragma HLS stream variable=v651 depth=10 type=fifo

  #pragma HLS bind_storage variable=v651 type=ram_t2p impl=bram

  for (int v652 = 0; v652 < 1; v652 += 1) {	// L1184
    for (int v653 = 0; v653 < 30; v653 += 1) {	// L1185
      for (int v654 = 0; v654 < 30; v654 += 1) {	// L1186
        for (int v655 = 0; v655 < 256; v655 += 1) {	// L1187
          int8_t v656;	// L1188
          v656 = (int8_t)0.000000;	// L1189
          if (((-v653) + 27) >= 0 && ((-v654) + 27) >= 0) {	// L1190
            int8_t v657 = v648[v652][v655][v653][v654];	// L1191
            v656 = v657;	// L1192
          }
          int8_t v658 = v656;	// L1194
          v651[v652][v655][v653][v654] = v658;	// L1195
        }
      }
    }
  }
  int8_t v659[1][256][14][14];	// L1200
  #pragma HLS stream variable=v659 depth=10 type=fifo

  #pragma HLS bind_storage variable=v659 type=ram_t2p impl=bram

  int8_t v660[1][256][3][30];	// L1201
  #pragma HLS array_partition variable=v660 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v660 type=ram_2p impl=bram

  int8_t v661[1][256][3][3];	// L1202
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v661 type=ram_2p impl=lutram

  for (int v662 = 0; v662 < 1; v662 += 1) {	// L1203
    for (int v663 = 0; v663 < 30; v663 += 1) {	// L1204
      for (int v664 = 0; v664 < 30; v664 += 1) {	// L1205
        for (int v665 = 0; v665 < 256; v665 += 1) {	// L1206
          int8_t v666 = v660[v662][v665][1][v664];	// L1207
          v660[v662][v665][0][v664] = v666;	// L1208
          int8_t v667 = v660[v662][v665][2][v664];	// L1209
          v660[v662][v665][1][v664] = v667;	// L1210
          int8_t v668 = v651[v662][v665][v663][v664];	// L1211
          v660[v662][v665][2][v664] = v668;	// L1212
        }
        if ((v663 - 16) >= 0) {	// L1214
          for (int v669 = 0; v669 < 256; v669 += 1) {	// L1215
            for (int v670 = 0; v670 < 3; v670 += 1) {	// L1216
              int8_t v671 = v661[v662][v669][v670][1];	// L1217
              v661[v662][v669][v670][0] = v671;	// L1218
              int8_t v672 = v661[v662][v669][v670][2];	// L1219
              v661[v662][v669][v670][1] = v672;	// L1220
              int8_t v673 = v660[v662][v669][v670][v664];	// L1221
              v661[v662][v669][v670][2] = v673;	// L1222
            }
          }
          if ((v664 - 16) >= 0) {	// L1225
            int8_t v674[256];	// L1226
            #pragma HLS bind_storage variable=v674 type=ram_2p impl=bram

            for (int v675 = 0; v675 < 256; v675 += 1) {	// L1227
              #pragma HLS pipeline II=1
              for (int v676 = 0; v676 < 1; v676 += 1) {	// L1228
                v674[(v675 + v676)] = (int8_t)0.000000;	// L1229
                for (int v677 = 0; v677 < 3; v677 += 1) {	// L1230
                  for (int v678 = 0; v678 < 3; v678 += 1) {	// L1231
                    int8_t v679 = v661[v662][(v675 + v676)][v677][v678];	// L1232
                    int8_t v680 = v649[(v675 + v676)][v677][v678];	// L1233
                    int8_t v681 = v679 * v680;	// L1234
                    int8_t v682 = v674[(v675 + v676)];	// L1235
                    int8_t v683 = v682 + v681;	// L1236
                    v674[(v675 + v676)] = v683;	// L1237
                  }
                }
                int8_t v684 = v674[(v675 + v676)];	// L1240
                v659[v662][(v675 + v676)][(v663 - 16)][(v664 - 16)] = v684;	// L1241
              }
            }
          }
        }
      }
    }
  }
  for (int v685 = 0; v685 < 1; v685 += 1) {	// L1249
    for (int v686 = 0; v686 < 14; v686 += 1) {	// L1250
      for (int v687 = 0; v687 < 14; v687 += 1) {	// L1251
        for (int v688 = 0; v688 < 256; v688 += 1) {	// L1252
          int8_t v689 = v659[0][v688][v686][v687];	// L1253
          bool v690 = v689 > (int8_t)0.000000;	// L1254
          int8_t v691 = v690 ? v689 : (int8_t)0.000000;	// L1255
          v650[v685][v688][v686][v687] = v691;	// L1256
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v692[1][256][28][28],
  int8_t v693[256][256][1][1],
  int8_t v694[1][256][28][28]
) {	// L1263
  #pragma HLS dataflow

  int8_t v695[1][256][28][28];	// L1265
  #pragma HLS stream variable=v695 depth=10 type=fifo

  #pragma HLS bind_storage variable=v695 type=ram_t2p impl=bram

  int8_t v696[1][256][1][28];	// L1266
  #pragma HLS bind_storage variable=v696 type=ram_2p impl=bram

  int8_t v697[1][256][1][1];	// L1267
  #pragma HLS array_partition variable=v697 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v697 type=ram_2p impl=lutram

  for (int v698 = 0; v698 < 1; v698 += 1) {	// L1268
    for (int v699 = 0; v699 < 28; v699 += 1) {	// L1269
      for (int v700 = 0; v700 < 28; v700 += 1) {	// L1270
        for (int v701 = 0; v701 < 256; v701 += 1) {	// L1271
          int8_t v702 = v692[v698][v701][v699][v700];	// L1272
          v696[v698][v701][0][v700] = v702;	// L1273
        }
        if (v699 >= 0) {	// L1275
          for (int v703 = 0; v703 < 256; v703 += 1) {	// L1276
            for (int v704 = 0; v704 < 1; v704 += 1) {	// L1277
              int8_t v705 = v696[v698][v703][v704][v700];	// L1278
              v697[v698][v703][v704][0] = v705;	// L1279
            }
          }
          if (v700 >= 0) {	// L1282
            int8_t v706[256];	// L1283
            #pragma HLS bind_storage variable=v706 type=ram_2p impl=bram

            for (int v707 = 0; v707 < 256; v707 += 1) {	// L1284
              v706[v707] = (int8_t)0.000000;	// L1285
              for (int v708 = 0; v708 < 8; v708 += 1) {	// L1286
                #pragma HLS pipeline II=1
                for (int v709 = 0; v709 < 32; v709 += 1) {	// L1287
                  for (int v710 = 0; v710 < 1; v710 += 1) {	// L1288
                    for (int v711 = 0; v711 < 1; v711 += 1) {	// L1289
                      int8_t v712 = v697[v698][(v709 + (v708 * 32))][v710][v711];	// L1290
                      int8_t v713 = v693[v707][(v709 + (v708 * 32))][v710][v711];	// L1291
                      int8_t v714 = v712 * v713;	// L1292
                      int8_t v715 = v706[v707];	// L1293
                      int8_t v716 = v715 + v714;	// L1294
                      v706[v707] = v716;	// L1295
                    }
                  }
                }
              }
              int8_t v717 = v706[v707];	// L1300
              v695[v698][v707][v699][v700] = v717;	// L1301
            }
          }
        }
      }
    }
  }
  for (int v718 = 0; v718 < 1; v718 += 1) {	// L1308
    for (int v719 = 0; v719 < 28; v719 += 1) {	// L1309
      for (int v720 = 0; v720 < 28; v720 += 1) {	// L1310
        for (int v721 = 0; v721 < 256; v721 += 1) {	// L1311
          int8_t v722 = v695[0][v721][v719][v720];	// L1312
          bool v723 = v722 > (int8_t)0.000000;	// L1313
          int8_t v724 = v723 ? v722 : (int8_t)0.000000;	// L1314
          v694[v718][v721][v719][v720] = v724;	// L1315
        }
      }
    }
  }
}

void main_graph_node21(
  int8_t v725[256][3][3],
  int8_t v726[1][256][28][28],
  int8_t v727[1][256][28][28]
) {	// L1322
  #pragma HLS dataflow

  int8_t v728[1][256][30][30];	// L1324
  #pragma HLS stream variable=v728 depth=10 type=fifo

  #pragma HLS bind_storage variable=v728 type=ram_t2p impl=bram

  for (int v729 = 0; v729 < 1; v729 += 1) {	// L1325
    for (int v730 = 0; v730 < 30; v730 += 1) {	// L1326
      for (int v731 = 0; v731 < 30; v731 += 1) {	// L1327
        for (int v732 = 0; v732 < 256; v732 += 1) {	// L1328
          int8_t v733;	// L1329
          v733 = (int8_t)0.000000;	// L1330
          if (((-v730) + 27) >= 0 && ((-v731) + 27) >= 0) {	// L1331
            int8_t v734 = v726[v729][v732][v730][v731];	// L1332
            v733 = v734;	// L1333
          }
          int8_t v735 = v733;	// L1335
          v728[v729][v732][v730][v731] = v735;	// L1336
        }
      }
    }
  }
  int8_t v736[1][256][28][28];	// L1341
  #pragma HLS stream variable=v736 depth=10 type=fifo

  #pragma HLS bind_storage variable=v736 type=ram_t2p impl=bram

  int8_t v737[1][256][3][30];	// L1342
  #pragma HLS array_partition variable=v737 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v737 type=ram_2p impl=bram

  int8_t v738[1][256][3][3];	// L1343
  #pragma HLS array_partition variable=v738 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v738 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v738 type=ram_2p impl=lutram

  for (int v739 = 0; v739 < 1; v739 += 1) {	// L1344
    for (int v740 = 0; v740 < 30; v740 += 1) {	// L1345
      for (int v741 = 0; v741 < 30; v741 += 1) {	// L1346
        for (int v742 = 0; v742 < 256; v742 += 1) {	// L1347
          int8_t v743 = v737[v739][v742][1][v741];	// L1348
          v737[v739][v742][0][v741] = v743;	// L1349
          int8_t v744 = v737[v739][v742][2][v741];	// L1350
          v737[v739][v742][1][v741] = v744;	// L1351
          int8_t v745 = v728[v739][v742][v740][v741];	// L1352
          v737[v739][v742][2][v741] = v745;	// L1353
        }
        if ((v740 - 2) >= 0) {	// L1355
          for (int v746 = 0; v746 < 256; v746 += 1) {	// L1356
            for (int v747 = 0; v747 < 3; v747 += 1) {	// L1357
              int8_t v748 = v738[v739][v746][v747][1];	// L1358
              v738[v739][v746][v747][0] = v748;	// L1359
              int8_t v749 = v738[v739][v746][v747][2];	// L1360
              v738[v739][v746][v747][1] = v749;	// L1361
              int8_t v750 = v737[v739][v746][v747][v741];	// L1362
              v738[v739][v746][v747][2] = v750;	// L1363
            }
          }
          if ((v741 - 2) >= 0) {	// L1366
            int8_t v751[256];	// L1367
            #pragma HLS bind_storage variable=v751 type=ram_2p impl=bram

            for (int v752 = 0; v752 < 256; v752 += 1) {	// L1368
              #pragma HLS pipeline II=1
              for (int v753 = 0; v753 < 1; v753 += 1) {	// L1369
                v751[(v752 + v753)] = (int8_t)0.000000;	// L1370
                for (int v754 = 0; v754 < 3; v754 += 1) {	// L1371
                  for (int v755 = 0; v755 < 3; v755 += 1) {	// L1372
                    int8_t v756 = v738[v739][(v752 + v753)][v754][v755];	// L1373
                    int8_t v757 = v725[(v752 + v753)][v754][v755];	// L1374
                    int8_t v758 = v756 * v757;	// L1375
                    int8_t v759 = v751[(v752 + v753)];	// L1376
                    int8_t v760 = v759 + v758;	// L1377
                    v751[(v752 + v753)] = v760;	// L1378
                  }
                }
                int8_t v761 = v751[(v752 + v753)];	// L1381
                v736[v739][(v752 + v753)][(v740 - 2)][(v741 - 2)] = v761;	// L1382
              }
            }
          }
        }
      }
    }
  }
  for (int v762 = 0; v762 < 1; v762 += 1) {	// L1390
    for (int v763 = 0; v763 < 28; v763 += 1) {	// L1391
      for (int v764 = 0; v764 < 28; v764 += 1) {	// L1392
        for (int v765 = 0; v765 < 256; v765 += 1) {	// L1393
          int8_t v766 = v736[0][v765][v763][v764];	// L1394
          bool v767 = v766 > (int8_t)0.000000;	// L1395
          int8_t v768 = v767 ? v766 : (int8_t)0.000000;	// L1396
          v727[v762][v765][v763][v764] = v768;	// L1397
        }
      }
    }
  }
}

void main_graph_node22(
  int8_t v769[1][128][28][28],
  int8_t v770[256][128][1][1],
  int8_t v771[1][256][28][28]
) {	// L1404
  #pragma HLS dataflow

  int8_t v772[1][256][28][28];	// L1406
  #pragma HLS stream variable=v772 depth=10 type=fifo

  #pragma HLS bind_storage variable=v772 type=ram_t2p impl=bram

  int8_t v773[1][128][1][28];	// L1407
  #pragma HLS array_partition variable=v773 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v773 type=ram_2p impl=lutram

  int8_t v774[1][128][1][1];	// L1408
  #pragma HLS array_partition variable=v774 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v774 type=ram_2p impl=lutram

  for (int v775 = 0; v775 < 1; v775 += 1) {	// L1409
    for (int v776 = 0; v776 < 28; v776 += 1) {	// L1410
      for (int v777 = 0; v777 < 28; v777 += 1) {	// L1411
        for (int v778 = 0; v778 < 16; v778 += 1) {	// L1412
          #pragma HLS pipeline II=1
          for (int v779 = 0; v779 < 8; v779 += 1) {	// L1413
            int8_t v780 = v769[v775][(v779 + (v778 * 8))][v776][v777];	// L1414
            v773[v775][(v779 + (v778 * 8))][0][v777] = v780;	// L1415
          }
        }
        if (v776 >= 0) {	// L1418
          for (int v781 = 0; v781 < 16; v781 += 1) {	// L1419
            #pragma HLS pipeline II=1
            for (int v782 = 0; v782 < 8; v782 += 1) {	// L1420
              for (int v783 = 0; v783 < 1; v783 += 1) {	// L1421
                int8_t v784 = v773[v775][(v782 + (v781 * 8))][v783][v777];	// L1422
                v774[v775][(v782 + (v781 * 8))][v783][0] = v784;	// L1423
              }
            }
          }
          if (v777 >= 0) {	// L1427
            int8_t v785[256];	// L1428
            #pragma HLS bind_storage variable=v785 type=ram_2p impl=bram

            for (int v786 = 0; v786 < 256; v786 += 1) {	// L1429
              v785[v786] = (int8_t)0.000000;	// L1430
              for (int v787 = 0; v787 < 8; v787 += 1) {	// L1431
                #pragma HLS pipeline II=1
                for (int v788 = 0; v788 < 16; v788 += 1) {	// L1432
                  for (int v789 = 0; v789 < 1; v789 += 1) {	// L1433
                    for (int v790 = 0; v790 < 1; v790 += 1) {	// L1434
                      int8_t v791 = v774[v775][(v788 + (v787 * 16))][v789][v790];	// L1435
                      int8_t v792 = v770[v786][(v788 + (v787 * 16))][v789][v790];	// L1436
                      int8_t v793 = v791 * v792;	// L1437
                      int8_t v794 = v785[v786];	// L1438
                      int8_t v795 = v794 + v793;	// L1439
                      v785[v786] = v795;	// L1440
                    }
                  }
                }
              }
              int8_t v796 = v785[v786];	// L1445
              v772[v775][v786][v776][v777] = v796;	// L1446
            }
          }
        }
      }
    }
  }
  for (int v797 = 0; v797 < 1; v797 += 1) {	// L1453
    for (int v798 = 0; v798 < 28; v798 += 1) {	// L1454
      for (int v799 = 0; v799 < 28; v799 += 1) {	// L1455
        for (int v800 = 0; v800 < 256; v800 += 1) {	// L1456
          int8_t v801 = v772[0][v800][v798][v799];	// L1457
          bool v802 = v801 > (int8_t)0.000000;	// L1458
          int8_t v803 = v802 ? v801 : (int8_t)0.000000;	// L1459
          v771[v797][v800][v798][v799] = v803;	// L1460
        }
      }
    }
  }
}

void main_graph_node23(
  int8_t v804[1][128][56][56],
  int8_t v805[128][3][3],
  int8_t v806[1][128][28][28]
) {	// L1467
  #pragma HLS dataflow

  int8_t v807[1][128][58][58];	// L1469
  #pragma HLS stream variable=v807 depth=10 type=fifo

  #pragma HLS bind_storage variable=v807 type=ram_t2p impl=bram

  for (int v808 = 0; v808 < 1; v808 += 1) {	// L1470
    for (int v809 = 0; v809 < 58; v809 += 1) {	// L1471
      for (int v810 = 0; v810 < 58; v810 += 1) {	// L1472
        for (int v811 = 0; v811 < 128; v811 += 1) {	// L1473
          int8_t v812;	// L1474
          v812 = (int8_t)0.000000;	// L1475
          if (((-v809) + 55) >= 0 && ((-v810) + 55) >= 0) {	// L1476
            int8_t v813 = v804[v808][v811][v809][v810];	// L1477
            v812 = v813;	// L1478
          }
          int8_t v814 = v812;	// L1480
          v807[v808][v811][v809][v810] = v814;	// L1481
        }
      }
    }
  }
  int8_t v815[1][128][28][28];	// L1486
  #pragma HLS stream variable=v815 depth=10 type=fifo

  #pragma HLS array_partition variable=v815 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v815 type=ram_t2p impl=bram

  int8_t v816[1][128][3][58];	// L1487
  #pragma HLS array_partition variable=v816 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v816 type=ram_2p impl=bram

  int8_t v817[1][128][3][3];	// L1488
  #pragma HLS array_partition variable=v817 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v817 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v817 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v817 type=ram_2p impl=lutram

  for (int v818 = 0; v818 < 1; v818 += 1) {	// L1489
    for (int v819 = 0; v819 < 58; v819 += 1) {	// L1490
      for (int v820 = 0; v820 < 58; v820 += 1) {	// L1491
        for (int v821 = 0; v821 < 128; v821 += 1) {	// L1492
          int8_t v822 = v816[v818][v821][1][v820];	// L1493
          v816[v818][v821][0][v820] = v822;	// L1494
          int8_t v823 = v816[v818][v821][2][v820];	// L1495
          v816[v818][v821][1][v820] = v823;	// L1496
          int8_t v824 = v807[v818][v821][v819][v820];	// L1497
          v816[v818][v821][2][v820] = v824;	// L1498
        }
        if ((v819 - 30) >= 0) {	// L1500
          for (int v825 = 0; v825 < 128; v825 += 1) {	// L1501
            for (int v826 = 0; v826 < 3; v826 += 1) {	// L1502
              int8_t v827 = v817[v818][v825][v826][1];	// L1503
              v817[v818][v825][v826][0] = v827;	// L1504
              int8_t v828 = v817[v818][v825][v826][2];	// L1505
              v817[v818][v825][v826][1] = v828;	// L1506
              int8_t v829 = v816[v818][v825][v826][v820];	// L1507
              v817[v818][v825][v826][2] = v829;	// L1508
            }
          }
          if ((v820 - 30) >= 0) {	// L1511
            int8_t v830[128];	// L1512
            #pragma HLS array_partition variable=v830 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v830 type=ram_2p impl=lutram

            for (int v831 = 0; v831 < 16; v831 += 1) {	// L1513
              #pragma HLS pipeline II=1
              for (int v832 = 0; v832 < 8; v832 += 1) {	// L1514
                v830[(v832 + (v831 * 8))] = (int8_t)0.000000;	// L1515
                for (int v833 = 0; v833 < 3; v833 += 1) {	// L1516
                  for (int v834 = 0; v834 < 3; v834 += 1) {	// L1517
                    int8_t v835 = v817[v818][(v832 + (v831 * 8))][v833][v834];	// L1518
                    int8_t v836 = v805[(v832 + (v831 * 8))][v833][v834];	// L1519
                    int8_t v837 = v835 * v836;	// L1520
                    int8_t v838 = v830[(v832 + (v831 * 8))];	// L1521
                    int8_t v839 = v838 + v837;	// L1522
                    v830[(v832 + (v831 * 8))] = v839;	// L1523
                  }
                }
                int8_t v840 = v830[(v832 + (v831 * 8))];	// L1526
                v815[v818][(v832 + (v831 * 8))][(v819 - 30)][(v820 - 30)] = v840;	// L1527
              }
            }
          }
        }
      }
    }
  }
  for (int v841 = 0; v841 < 1; v841 += 1) {	// L1535
    for (int v842 = 0; v842 < 28; v842 += 1) {	// L1536
      for (int v843 = 0; v843 < 28; v843 += 1) {	// L1537
        for (int v844 = 0; v844 < 16; v844 += 1) {	// L1538
          #pragma HLS pipeline II=1
          for (int v845 = 0; v845 < 8; v845 += 1) {	// L1539
            int8_t v846 = v815[0][(v845 + (v844 * 8))][v842][v843];	// L1540
            bool v847 = v846 > (int8_t)0.000000;	// L1541
            int8_t v848 = v847 ? v846 : (int8_t)0.000000;	// L1542
            v806[v841][(v845 + (v844 * 8))][v842][v843] = v848;	// L1543
          }
        }
      }
    }
  }
}

void main_graph_node24(
  int8_t v849[1][128][56][56],
  int8_t v850[128][128][1][1],
  int8_t v851[1][128][56][56]
) {	// L1551
  #pragma HLS dataflow

  int8_t v852[1][128][56][56];	// L1553
  #pragma HLS stream variable=v852 depth=10 type=fifo

  #pragma HLS bind_storage variable=v852 type=ram_t2p impl=bram

  int8_t v853[1][128][1][56];	// L1554
  #pragma HLS array_partition variable=v853 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v853 type=ram_2p impl=lutram

  int8_t v854[1][128][1][1];	// L1555
  #pragma HLS array_partition variable=v854 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v854 type=ram_2p impl=lutram

  for (int v855 = 0; v855 < 1; v855 += 1) {	// L1556
    for (int v856 = 0; v856 < 56; v856 += 1) {	// L1557
      for (int v857 = 0; v857 < 56; v857 += 1) {	// L1558
        for (int v858 = 0; v858 < 16; v858 += 1) {	// L1559
          #pragma HLS pipeline II=1
          for (int v859 = 0; v859 < 8; v859 += 1) {	// L1560
            int8_t v860 = v849[v855][(v859 + (v858 * 8))][v856][v857];	// L1561
            v853[v855][(v859 + (v858 * 8))][0][v857] = v860;	// L1562
          }
        }
        if (v856 >= 0) {	// L1565
          for (int v861 = 0; v861 < 16; v861 += 1) {	// L1566
            #pragma HLS pipeline II=1
            for (int v862 = 0; v862 < 8; v862 += 1) {	// L1567
              for (int v863 = 0; v863 < 1; v863 += 1) {	// L1568
                int8_t v864 = v853[v855][(v862 + (v861 * 8))][v863][v857];	// L1569
                v854[v855][(v862 + (v861 * 8))][v863][0] = v864;	// L1570
              }
            }
          }
          if (v857 >= 0) {	// L1574
            int8_t v865[128];	// L1575
            #pragma HLS bind_storage variable=v865 type=ram_2p impl=bram

            for (int v866 = 0; v866 < 128; v866 += 1) {	// L1576
              v865[v866] = (int8_t)0.000000;	// L1577
              for (int v867 = 0; v867 < 4; v867 += 1) {	// L1578
                #pragma HLS pipeline II=1
                for (int v868 = 0; v868 < 32; v868 += 1) {	// L1579
                  for (int v869 = 0; v869 < 1; v869 += 1) {	// L1580
                    for (int v870 = 0; v870 < 1; v870 += 1) {	// L1581
                      int8_t v871 = v854[v855][(v868 + (v867 * 32))][v869][v870];	// L1582
                      int8_t v872 = v850[v866][(v868 + (v867 * 32))][v869][v870];	// L1583
                      int8_t v873 = v871 * v872;	// L1584
                      int8_t v874 = v865[v866];	// L1585
                      int8_t v875 = v874 + v873;	// L1586
                      v865[v866] = v875;	// L1587
                    }
                  }
                }
              }
              int8_t v876 = v865[v866];	// L1592
              v852[v855][v866][v856][v857] = v876;	// L1593
            }
          }
        }
      }
    }
  }
  for (int v877 = 0; v877 < 1; v877 += 1) {	// L1600
    for (int v878 = 0; v878 < 56; v878 += 1) {	// L1601
      for (int v879 = 0; v879 < 56; v879 += 1) {	// L1602
        for (int v880 = 0; v880 < 128; v880 += 1) {	// L1603
          int8_t v881 = v852[0][v880][v878][v879];	// L1604
          bool v882 = v881 > (int8_t)0.000000;	// L1605
          int8_t v883 = v882 ? v881 : (int8_t)0.000000;	// L1606
          v851[v877][v880][v878][v879] = v883;	// L1607
        }
      }
    }
  }
}

void main_graph_node25(
  int8_t v884[1][128][56][56],
  int8_t v885[128][3][3],
  int8_t v886[1][128][56][56]
) {	// L1614
  #pragma HLS dataflow

  int8_t v887[1][128][58][58];	// L1616
  #pragma HLS stream variable=v887 depth=10 type=fifo

  #pragma HLS bind_storage variable=v887 type=ram_t2p impl=bram

  for (int v888 = 0; v888 < 1; v888 += 1) {	// L1617
    for (int v889 = 0; v889 < 58; v889 += 1) {	// L1618
      for (int v890 = 0; v890 < 58; v890 += 1) {	// L1619
        for (int v891 = 0; v891 < 128; v891 += 1) {	// L1620
          int8_t v892;	// L1621
          v892 = (int8_t)0.000000;	// L1622
          if (((-v889) + 55) >= 0 && ((-v890) + 55) >= 0) {	// L1623
            int8_t v893 = v884[v888][v891][v889][v890];	// L1624
            v892 = v893;	// L1625
          }
          int8_t v894 = v892;	// L1627
          v887[v888][v891][v889][v890] = v894;	// L1628
        }
      }
    }
  }
  int8_t v895[1][128][56][56];	// L1633
  #pragma HLS stream variable=v895 depth=10 type=fifo

  #pragma HLS array_partition variable=v895 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v895 type=ram_t2p impl=bram

  int8_t v896[1][128][3][58];	// L1634
  #pragma HLS array_partition variable=v896 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v896 type=ram_2p impl=bram

  int8_t v897[1][128][3][3];	// L1635
  #pragma HLS array_partition variable=v897 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v897 type=ram_2p impl=lutram

  for (int v898 = 0; v898 < 1; v898 += 1) {	// L1636
    for (int v899 = 0; v899 < 58; v899 += 1) {	// L1637
      for (int v900 = 0; v900 < 58; v900 += 1) {	// L1638
        for (int v901 = 0; v901 < 128; v901 += 1) {	// L1639
          int8_t v902 = v896[v898][v901][1][v900];	// L1640
          v896[v898][v901][0][v900] = v902;	// L1641
          int8_t v903 = v896[v898][v901][2][v900];	// L1642
          v896[v898][v901][1][v900] = v903;	// L1643
          int8_t v904 = v887[v898][v901][v899][v900];	// L1644
          v896[v898][v901][2][v900] = v904;	// L1645
        }
        if ((v899 - 2) >= 0) {	// L1647
          for (int v905 = 0; v905 < 128; v905 += 1) {	// L1648
            for (int v906 = 0; v906 < 3; v906 += 1) {	// L1649
              int8_t v907 = v897[v898][v905][v906][1];	// L1650
              v897[v898][v905][v906][0] = v907;	// L1651
              int8_t v908 = v897[v898][v905][v906][2];	// L1652
              v897[v898][v905][v906][1] = v908;	// L1653
              int8_t v909 = v896[v898][v905][v906][v900];	// L1654
              v897[v898][v905][v906][2] = v909;	// L1655
            }
          }
          if ((v900 - 2) >= 0) {	// L1658
            int8_t v910[128];	// L1659
            #pragma HLS array_partition variable=v910 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v910 type=ram_2p impl=lutram

            for (int v911 = 0; v911 < 16; v911 += 1) {	// L1660
              #pragma HLS pipeline II=1
              for (int v912 = 0; v912 < 8; v912 += 1) {	// L1661
                v910[(v912 + (v911 * 8))] = (int8_t)0.000000;	// L1662
                for (int v913 = 0; v913 < 3; v913 += 1) {	// L1663
                  for (int v914 = 0; v914 < 3; v914 += 1) {	// L1664
                    int8_t v915 = v897[v898][(v912 + (v911 * 8))][v913][v914];	// L1665
                    int8_t v916 = v885[(v912 + (v911 * 8))][v913][v914];	// L1666
                    int8_t v917 = v915 * v916;	// L1667
                    int8_t v918 = v910[(v912 + (v911 * 8))];	// L1668
                    int8_t v919 = v918 + v917;	// L1669
                    v910[(v912 + (v911 * 8))] = v919;	// L1670
                  }
                }
                int8_t v920 = v910[(v912 + (v911 * 8))];	// L1673
                v895[v898][(v912 + (v911 * 8))][(v899 - 2)][(v900 - 2)] = v920;	// L1674
              }
            }
          }
        }
      }
    }
  }
  for (int v921 = 0; v921 < 1; v921 += 1) {	// L1682
    for (int v922 = 0; v922 < 56; v922 += 1) {	// L1683
      for (int v923 = 0; v923 < 56; v923 += 1) {	// L1684
        for (int v924 = 0; v924 < 16; v924 += 1) {	// L1685
          #pragma HLS pipeline II=1
          for (int v925 = 0; v925 < 8; v925 += 1) {	// L1686
            int8_t v926 = v895[0][(v925 + (v924 * 8))][v922][v923];	// L1687
            bool v927 = v926 > (int8_t)0.000000;	// L1688
            int8_t v928 = v927 ? v926 : (int8_t)0.000000;	// L1689
            v886[v921][(v925 + (v924 * 8))][v922][v923] = v928;	// L1690
          }
        }
      }
    }
  }
}

void main_graph_node26(
  int8_t v929[1][64][56][56],
  int8_t v930[128][64][1][1],
  int8_t v931[1][128][56][56]
) {	// L1698
  #pragma HLS dataflow

  int8_t v932[1][128][56][56];	// L1700
  #pragma HLS stream variable=v932 depth=10 type=fifo

  #pragma HLS bind_storage variable=v932 type=ram_t2p impl=bram

  int8_t v933[1][64][1][56];	// L1701
  #pragma HLS array_partition variable=v933 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v933 type=ram_2p impl=lutram

  int8_t v934[1][64][1][1];	// L1702
  #pragma HLS array_partition variable=v934 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v934 type=ram_2p impl=lutram

  for (int v935 = 0; v935 < 1; v935 += 1) {	// L1703
    for (int v936 = 0; v936 < 56; v936 += 1) {	// L1704
      for (int v937 = 0; v937 < 56; v937 += 1) {	// L1705
        for (int v938 = 0; v938 < 4; v938 += 1) {	// L1706
          #pragma HLS pipeline II=1
          for (int v939 = 0; v939 < 16; v939 += 1) {	// L1707
            int8_t v940 = v929[v935][(v939 + (v938 * 16))][v936][v937];	// L1708
            v933[v935][(v939 + (v938 * 16))][0][v937] = v940;	// L1709
          }
        }
        if (v936 >= 0) {	// L1712
          for (int v941 = 0; v941 < 4; v941 += 1) {	// L1713
            #pragma HLS pipeline II=1
            for (int v942 = 0; v942 < 16; v942 += 1) {	// L1714
              for (int v943 = 0; v943 < 1; v943 += 1) {	// L1715
                int8_t v944 = v933[v935][(v942 + (v941 * 16))][v943][v937];	// L1716
                v934[v935][(v942 + (v941 * 16))][v943][0] = v944;	// L1717
              }
            }
          }
          if (v937 >= 0) {	// L1721
            int8_t v945[128];	// L1722
            #pragma HLS bind_storage variable=v945 type=ram_2p impl=bram

            for (int v946 = 0; v946 < 128; v946 += 1) {	// L1723
              v945[v946] = (int8_t)0.000000;	// L1724
              for (int v947 = 0; v947 < 4; v947 += 1) {	// L1725
                #pragma HLS pipeline II=1
                for (int v948 = 0; v948 < 16; v948 += 1) {	// L1726
                  for (int v949 = 0; v949 < 1; v949 += 1) {	// L1727
                    for (int v950 = 0; v950 < 1; v950 += 1) {	// L1728
                      int8_t v951 = v934[v935][(v948 + (v947 * 16))][v949][v950];	// L1729
                      int8_t v952 = v930[v946][(v948 + (v947 * 16))][v949][v950];	// L1730
                      int8_t v953 = v951 * v952;	// L1731
                      int8_t v954 = v945[v946];	// L1732
                      int8_t v955 = v954 + v953;	// L1733
                      v945[v946] = v955;	// L1734
                    }
                  }
                }
              }
              int8_t v956 = v945[v946];	// L1739
              v932[v935][v946][v936][v937] = v956;	// L1740
            }
          }
        }
      }
    }
  }
  for (int v957 = 0; v957 < 1; v957 += 1) {	// L1747
    for (int v958 = 0; v958 < 56; v958 += 1) {	// L1748
      for (int v959 = 0; v959 < 56; v959 += 1) {	// L1749
        for (int v960 = 0; v960 < 128; v960 += 1) {	// L1750
          int8_t v961 = v932[0][v960][v958][v959];	// L1751
          bool v962 = v961 > (int8_t)0.000000;	// L1752
          int8_t v963 = v962 ? v961 : (int8_t)0.000000;	// L1753
          v931[v957][v960][v958][v959] = v963;	// L1754
        }
      }
    }
  }
}

void main_graph_node27(
  int8_t v964[64][3][3],
  int8_t v965[1][64][112][112],
  int8_t v966[1][64][56][56]
) {	// L1761
  #pragma HLS dataflow

  int8_t v967[1][64][114][114];	// L1763
  #pragma HLS stream variable=v967 depth=10 type=fifo

  #pragma HLS bind_storage variable=v967 type=ram_t2p impl=bram

  for (int v968 = 0; v968 < 1; v968 += 1) {	// L1764
    for (int v969 = 0; v969 < 114; v969 += 1) {	// L1765
      for (int v970 = 0; v970 < 114; v970 += 1) {	// L1766
        for (int v971 = 0; v971 < 64; v971 += 1) {	// L1767
          int8_t v972;	// L1768
          v972 = (int8_t)0.000000;	// L1769
          if (((-v969) + 111) >= 0 && ((-v970) + 111) >= 0) {	// L1770
            int8_t v973 = v965[v968][v971][v969][v970];	// L1771
            v972 = v973;	// L1772
          }
          int8_t v974 = v972;	// L1774
          v967[v968][v971][v969][v970] = v974;	// L1775
        }
      }
    }
  }
  int8_t v975[1][64][56][56];	// L1780
  #pragma HLS stream variable=v975 depth=10 type=fifo

  #pragma HLS array_partition variable=v975 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v975 type=ram_t2p impl=bram

  int8_t v976[1][64][3][114];	// L1781
  #pragma HLS array_partition variable=v976 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v976 type=ram_2p impl=bram

  int8_t v977[1][64][3][3];	// L1782
  #pragma HLS array_partition variable=v977 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v977 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v977 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v977 type=ram_2p impl=lutram

  for (int v978 = 0; v978 < 1; v978 += 1) {	// L1783
    for (int v979 = 0; v979 < 114; v979 += 1) {	// L1784
      for (int v980 = 0; v980 < 114; v980 += 1) {	// L1785
        for (int v981 = 0; v981 < 64; v981 += 1) {	// L1786
          int8_t v982 = v976[v978][v981][1][v980];	// L1787
          v976[v978][v981][0][v980] = v982;	// L1788
          int8_t v983 = v976[v978][v981][2][v980];	// L1789
          v976[v978][v981][1][v980] = v983;	// L1790
          int8_t v984 = v967[v978][v981][v979][v980];	// L1791
          v976[v978][v981][2][v980] = v984;	// L1792
        }
        if ((v979 - 58) >= 0) {	// L1794
          for (int v985 = 0; v985 < 64; v985 += 1) {	// L1795
            for (int v986 = 0; v986 < 3; v986 += 1) {	// L1796
              int8_t v987 = v977[v978][v985][v986][1];	// L1797
              v977[v978][v985][v986][0] = v987;	// L1798
              int8_t v988 = v977[v978][v985][v986][2];	// L1799
              v977[v978][v985][v986][1] = v988;	// L1800
              int8_t v989 = v976[v978][v985][v986][v980];	// L1801
              v977[v978][v985][v986][2] = v989;	// L1802
            }
          }
          if ((v980 - 58) >= 0) {	// L1805
            int8_t v990[64];	// L1806
            #pragma HLS array_partition variable=v990 cyclic factor=16 dim=1
            #pragma HLS bind_storage variable=v990 type=ram_2p impl=lutram

            for (int v991 = 0; v991 < 4; v991 += 1) {	// L1807
              #pragma HLS pipeline II=1
              for (int v992 = 0; v992 < 16; v992 += 1) {	// L1808
                v990[(v992 + (v991 * 16))] = (int8_t)0.000000;	// L1809
                for (int v993 = 0; v993 < 3; v993 += 1) {	// L1810
                  for (int v994 = 0; v994 < 3; v994 += 1) {	// L1811
                    int8_t v995 = v977[v978][(v992 + (v991 * 16))][v993][v994];	// L1812
                    int8_t v996 = v964[(v992 + (v991 * 16))][v993][v994];	// L1813
                    int8_t v997 = v995 * v996;	// L1814
                    int8_t v998 = v990[(v992 + (v991 * 16))];	// L1815
                    int8_t v999 = v998 + v997;	// L1816
                    v990[(v992 + (v991 * 16))] = v999;	// L1817
                  }
                }
                int8_t v1000 = v990[(v992 + (v991 * 16))];	// L1820
                v975[v978][(v992 + (v991 * 16))][(v979 - 58)][(v980 - 58)] = v1000;	// L1821
              }
            }
          }
        }
      }
    }
  }
  for (int v1001 = 0; v1001 < 1; v1001 += 1) {	// L1829
    for (int v1002 = 0; v1002 < 56; v1002 += 1) {	// L1830
      for (int v1003 = 0; v1003 < 56; v1003 += 1) {	// L1831
        for (int v1004 = 0; v1004 < 4; v1004 += 1) {	// L1832
          #pragma HLS pipeline II=1
          for (int v1005 = 0; v1005 < 16; v1005 += 1) {	// L1833
            int8_t v1006 = v975[0][(v1005 + (v1004 * 16))][v1002][v1003];	// L1834
            bool v1007 = v1006 > (int8_t)0.000000;	// L1835
            int8_t v1008 = v1007 ? v1006 : (int8_t)0.000000;	// L1836
            v966[v1001][(v1005 + (v1004 * 16))][v1002][v1003] = v1008;	// L1837
          }
        }
      }
    }
  }
}

void main_graph_node28(
  int8_t v1009[64][32][1][1],
  int8_t v1010[1][32][112][112],
  int8_t v1011[1][64][112][112]
) {	// L1845
  #pragma HLS dataflow

  int8_t v1012[1][64][112][112];	// L1847
  #pragma HLS stream variable=v1012 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1012 type=ram_t2p impl=bram

  int8_t v1013[1][32][1][112];	// L1848
  #pragma HLS array_partition variable=v1013 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1013 type=ram_2p impl=lutram

  int8_t v1014[1][32][1][1];	// L1849
  #pragma HLS array_partition variable=v1014 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1014 type=ram_2p impl=lutram

  for (int v1015 = 0; v1015 < 1; v1015 += 1) {	// L1850
    for (int v1016 = 0; v1016 < 112; v1016 += 1) {	// L1851
      for (int v1017 = 0; v1017 < 112; v1017 += 1) {	// L1852
        for (int v1018 = 0; v1018 < 4; v1018 += 1) {	// L1853
          #pragma HLS pipeline II=1
          for (int v1019 = 0; v1019 < 8; v1019 += 1) {	// L1854
            int8_t v1020 = v1010[v1015][(v1019 + (v1018 * 8))][v1016][v1017];	// L1855
            v1013[v1015][(v1019 + (v1018 * 8))][0][v1017] = v1020;	// L1856
          }
        }
        if (v1016 >= 0) {	// L1859
          for (int v1021 = 0; v1021 < 4; v1021 += 1) {	// L1860
            #pragma HLS pipeline II=1
            for (int v1022 = 0; v1022 < 8; v1022 += 1) {	// L1861
              for (int v1023 = 0; v1023 < 1; v1023 += 1) {	// L1862
                int8_t v1024 = v1013[v1015][(v1022 + (v1021 * 8))][v1023][v1017];	// L1863
                v1014[v1015][(v1022 + (v1021 * 8))][v1023][0] = v1024;	// L1864
              }
            }
          }
          if (v1017 >= 0) {	// L1868
            int8_t v1025[64];	// L1869
            #pragma HLS bind_storage variable=v1025 type=ram_2p impl=bram

            for (int v1026 = 0; v1026 < 64; v1026 += 1) {	// L1870
              v1025[v1026] = (int8_t)0.000000;	// L1871
              for (int v1027 = 0; v1027 < 1; v1027 += 1) {	// L1872
                #pragma HLS pipeline II=1
                for (int v1028 = 0; v1028 < 32; v1028 += 1) {	// L1873
                  for (int v1029 = 0; v1029 < 1; v1029 += 1) {	// L1874
                    for (int v1030 = 0; v1030 < 1; v1030 += 1) {	// L1875
                      int8_t v1031 = v1014[v1015][(v1028 + (v1027 * 32))][v1029][v1030];	// L1876
                      int8_t v1032 = v1009[v1026][(v1028 + (v1027 * 32))][v1029][v1030];	// L1877
                      int8_t v1033 = v1031 * v1032;	// L1878
                      int8_t v1034 = v1025[v1026];	// L1879
                      int8_t v1035 = v1034 + v1033;	// L1880
                      v1025[v1026] = v1035;	// L1881
                    }
                  }
                }
              }
              int8_t v1036 = v1025[v1026];	// L1886
              v1012[v1015][v1026][v1016][v1017] = v1036;	// L1887
            }
          }
        }
      }
    }
  }
  for (int v1037 = 0; v1037 < 1; v1037 += 1) {	// L1894
    for (int v1038 = 0; v1038 < 112; v1038 += 1) {	// L1895
      for (int v1039 = 0; v1039 < 112; v1039 += 1) {	// L1896
        for (int v1040 = 0; v1040 < 64; v1040 += 1) {	// L1897
          int8_t v1041 = v1012[0][v1040][v1038][v1039];	// L1898
          bool v1042 = v1041 > (int8_t)0.000000;	// L1899
          int8_t v1043 = v1042 ? v1041 : (int8_t)0.000000;	// L1900
          v1011[v1037][v1040][v1038][v1039] = v1043;	// L1901
        }
      }
    }
  }
}

void main_graph_node29(
  int8_t v1044[1][32][112][112],
  int8_t v1045[32][3][3],
  int8_t v1046[1][32][112][112]
) {	// L1908
  #pragma HLS dataflow

  int8_t v1047[1][32][114][114];	// L1910
  #pragma HLS stream variable=v1047 depth=10 type=fifo

  #pragma HLS array_partition variable=v1047 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1047 type=ram_t2p impl=bram

  for (int v1048 = 0; v1048 < 1; v1048 += 1) {	// L1911
    for (int v1049 = 0; v1049 < 114; v1049 += 1) {	// L1912
      for (int v1050 = 0; v1050 < 114; v1050 += 1) {	// L1913
        for (int v1051 = 0; v1051 < 2; v1051 += 1) {	// L1914
          #pragma HLS pipeline II=1
          for (int v1052 = 0; v1052 < 16; v1052 += 1) {	// L1915
            int8_t v1053;	// L1916
            v1053 = (int8_t)0.000000;	// L1917
            if (((-v1049) + 111) >= 0 && ((-v1050) + 111) >= 0) {	// L1918
              int8_t v1054 = v1044[v1048][(v1052 + (v1051 * 16))][v1049][v1050];	// L1919
              v1053 = v1054;	// L1920
            }
            int8_t v1055 = v1053;	// L1922
            v1047[v1048][(v1052 + (v1051 * 16))][v1049][v1050] = v1055;	// L1923
          }
        }
      }
    }
  }
  int8_t v1056[1][32][112][112];	// L1929
  #pragma HLS stream variable=v1056 depth=10 type=fifo

  #pragma HLS array_partition variable=v1056 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1056 type=ram_t2p impl=bram

  int8_t v1057[1][32][3][114];	// L1930
  #pragma HLS array_partition variable=v1057 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1057 type=ram_2p impl=lutram

  int8_t v1058[1][32][3][3];	// L1931
  #pragma HLS array_partition variable=v1058 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1058 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1058 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1058 type=ram_2p impl=lutram

  for (int v1059 = 0; v1059 < 1; v1059 += 1) {	// L1932
    for (int v1060 = 0; v1060 < 114; v1060 += 1) {	// L1933
      for (int v1061 = 0; v1061 < 114; v1061 += 1) {	// L1934
        for (int v1062 = 0; v1062 < 2; v1062 += 1) {	// L1935
          #pragma HLS pipeline II=1
          for (int v1063 = 0; v1063 < 16; v1063 += 1) {	// L1936
            int8_t v1064 = v1057[v1059][(v1063 + (v1062 * 16))][1][v1061];	// L1937
            v1057[v1059][(v1063 + (v1062 * 16))][0][v1061] = v1064;	// L1938
            int8_t v1065 = v1057[v1059][(v1063 + (v1062 * 16))][2][v1061];	// L1939
            v1057[v1059][(v1063 + (v1062 * 16))][1][v1061] = v1065;	// L1940
            int8_t v1066 = v1047[v1059][(v1063 + (v1062 * 16))][v1060][v1061];	// L1941
            v1057[v1059][(v1063 + (v1062 * 16))][2][v1061] = v1066;	// L1942
          }
        }
        if ((v1060 - 2) >= 0) {	// L1945
          for (int v1067 = 0; v1067 < 2; v1067 += 1) {	// L1946
            #pragma HLS pipeline II=1
            for (int v1068 = 0; v1068 < 16; v1068 += 1) {	// L1947
              for (int v1069 = 0; v1069 < 3; v1069 += 1) {	// L1948
                int8_t v1070 = v1058[v1059][(v1068 + (v1067 * 16))][v1069][1];	// L1949
                v1058[v1059][(v1068 + (v1067 * 16))][v1069][0] = v1070;	// L1950
                int8_t v1071 = v1058[v1059][(v1068 + (v1067 * 16))][v1069][2];	// L1951
                v1058[v1059][(v1068 + (v1067 * 16))][v1069][1] = v1071;	// L1952
                int8_t v1072 = v1057[v1059][(v1068 + (v1067 * 16))][v1069][v1061];	// L1953
                v1058[v1059][(v1068 + (v1067 * 16))][v1069][2] = v1072;	// L1954
              }
            }
          }
          if ((v1061 - 2) >= 0) {	// L1958
            int8_t v1073[32];	// L1959
            #pragma HLS array_partition variable=v1073 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v1073 type=ram_2p impl=lutram

            for (int v1074 = 0; v1074 < 4; v1074 += 1) {	// L1960
              #pragma HLS pipeline II=1
              for (int v1075 = 0; v1075 < 8; v1075 += 1) {	// L1961
                v1073[(v1075 + (v1074 * 8))] = (int8_t)0.000000;	// L1962
                for (int v1076 = 0; v1076 < 3; v1076 += 1) {	// L1963
                  for (int v1077 = 0; v1077 < 3; v1077 += 1) {	// L1964
                    int8_t v1078 = v1058[v1059][(v1075 + (v1074 * 8))][v1076][v1077];	// L1965
                    int8_t v1079 = v1045[(v1075 + (v1074 * 8))][v1076][v1077];	// L1966
                    int8_t v1080 = v1078 * v1079;	// L1967
                    int8_t v1081 = v1073[(v1075 + (v1074 * 8))];	// L1968
                    int8_t v1082 = v1081 + v1080;	// L1969
                    v1073[(v1075 + (v1074 * 8))] = v1082;	// L1970
                  }
                }
                int8_t v1083 = v1073[(v1075 + (v1074 * 8))];	// L1973
                v1056[v1059][(v1075 + (v1074 * 8))][(v1060 - 2)][(v1061 - 2)] = v1083;	// L1974
              }
            }
          }
        }
      }
    }
  }
  for (int v1084 = 0; v1084 < 1; v1084 += 1) {	// L1982
    for (int v1085 = 0; v1085 < 112; v1085 += 1) {	// L1983
      for (int v1086 = 0; v1086 < 112; v1086 += 1) {	// L1984
        for (int v1087 = 0; v1087 < 4; v1087 += 1) {	// L1985
          #pragma HLS pipeline II=1
          for (int v1088 = 0; v1088 < 8; v1088 += 1) {	// L1986
            int8_t v1089 = v1056[0][(v1088 + (v1087 * 8))][v1085][v1086];	// L1987
            bool v1090 = v1089 > (int8_t)0.000000;	// L1988
            int8_t v1091 = v1090 ? v1089 : (int8_t)0.000000;	// L1989
            v1046[v1084][(v1088 + (v1087 * 8))][v1085][v1086] = v1091;	// L1990
          }
        }
      }
    }
  }
}

void main_graph_node30(
  int8_t v1092[1][3][224][224],
  int8_t v1093[32][3][3][3],
  int8_t v1094[1][32][112][112]
) {	// L1998
  #pragma HLS dataflow

  int8_t v1095[1][3][226][226];	// L2000
  #pragma HLS stream variable=v1095 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1095 type=ram_t2p impl=bram

  for (int v1096 = 0; v1096 < 1; v1096 += 1) {	// L2001
    for (int v1097 = 0; v1097 < 226; v1097 += 1) {	// L2002
      for (int v1098 = 0; v1098 < 226; v1098 += 1) {	// L2003
        for (int v1099 = 0; v1099 < 3; v1099 += 1) {	// L2004
          int8_t v1100;	// L2005
          v1100 = (int8_t)0.000000;	// L2006
          if (((-v1097) + 223) >= 0 && ((-v1098) + 223) >= 0) {	// L2007
            int8_t v1101 = v1092[v1096][v1099][v1097][v1098];	// L2008
            v1100 = v1101;	// L2009
          }
          int8_t v1102 = v1100;	// L2011
          v1095[v1096][v1099][v1097][v1098] = v1102;	// L2012
        }
      }
    }
  }
  int8_t v1103[1][32][112][112];	// L2017
  #pragma HLS stream variable=v1103 depth=10 type=fifo

  #pragma HLS array_partition variable=v1103 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1103 type=ram_t2p impl=bram

  int8_t v1104[1][3][3][226];	// L2018
  #pragma HLS array_partition variable=v1104 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1104 type=ram_2p impl=lutram

  int8_t v1105[1][3][3][3];	// L2019
  #pragma HLS array_partition variable=v1105 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1105 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1105 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1105 type=ram_2p impl=lutram

  for (int v1106 = 0; v1106 < 1; v1106 += 1) {	// L2020
    for (int v1107 = 0; v1107 < 226; v1107 += 1) {	// L2021
      for (int v1108 = 0; v1108 < 226; v1108 += 1) {	// L2022
        for (int v1109 = 0; v1109 < 3; v1109 += 1) {	// L2023
          int8_t v1110 = v1104[v1106][v1109][1][v1108];	// L2024
          v1104[v1106][v1109][0][v1108] = v1110;	// L2025
          int8_t v1111 = v1104[v1106][v1109][2][v1108];	// L2026
          v1104[v1106][v1109][1][v1108] = v1111;	// L2027
          int8_t v1112 = v1095[v1106][v1109][v1107][v1108];	// L2028
          v1104[v1106][v1109][2][v1108] = v1112;	// L2029
        }
        if ((v1107 - 114) >= 0) {	// L2031
          for (int v1113 = 0; v1113 < 3; v1113 += 1) {	// L2032
            for (int v1114 = 0; v1114 < 3; v1114 += 1) {	// L2033
              int8_t v1115 = v1105[v1106][v1113][v1114][1];	// L2034
              v1105[v1106][v1113][v1114][0] = v1115;	// L2035
              int8_t v1116 = v1105[v1106][v1113][v1114][2];	// L2036
              v1105[v1106][v1113][v1114][1] = v1116;	// L2037
              int8_t v1117 = v1104[v1106][v1113][v1114][v1108];	// L2038
              v1105[v1106][v1113][v1114][2] = v1117;	// L2039
            }
          }
          if ((v1108 - 114) >= 0) {	// L2042
            int8_t v1118[32];	// L2043
            #pragma HLS array_partition variable=v1118 cyclic factor=16 dim=1
            #pragma HLS bind_storage variable=v1118 type=ram_2p impl=lutram

            for (int v1119 = 0; v1119 < 2; v1119 += 1) {	// L2044
              #pragma HLS pipeline II=1
              for (int v1120 = 0; v1120 < 16; v1120 += 1) {	// L2045
                v1118[(v1120 + (v1119 * 16))] = (int8_t)0.000000;	// L2046
                for (int v1121 = 0; v1121 < 3; v1121 += 1) {	// L2047
                  for (int v1122 = 0; v1122 < 3; v1122 += 1) {	// L2048
                    for (int v1123 = 0; v1123 < 3; v1123 += 1) {	// L2049
                      int8_t v1124 = v1105[v1106][v1121][v1122][v1123];	// L2050
                      int8_t v1125 = v1093[(v1120 + (v1119 * 16))][v1121][v1122][v1123];	// L2051
                      int8_t v1126 = v1124 * v1125;	// L2052
                      int8_t v1127 = v1118[(v1120 + (v1119 * 16))];	// L2053
                      int8_t v1128 = v1127 + v1126;	// L2054
                      v1118[(v1120 + (v1119 * 16))] = v1128;	// L2055
                    }
                  }
                }
                int8_t v1129 = v1118[(v1120 + (v1119 * 16))];	// L2059
                v1103[v1106][(v1120 + (v1119 * 16))][(v1107 - 114)][(v1108 - 114)] = v1129;	// L2060
              }
            }
          }
        }
      }
    }
  }
  for (int v1130 = 0; v1130 < 1; v1130 += 1) {	// L2068
    for (int v1131 = 0; v1131 < 112; v1131 += 1) {	// L2069
      for (int v1132 = 0; v1132 < 112; v1132 += 1) {	// L2070
        for (int v1133 = 0; v1133 < 2; v1133 += 1) {	// L2071
          #pragma HLS pipeline II=1
          for (int v1134 = 0; v1134 < 16; v1134 += 1) {	// L2072
            int8_t v1135 = v1103[0][(v1134 + (v1133 * 16))][v1131][v1132];	// L2073
            bool v1136 = v1135 > (int8_t)0.000000;	// L2074
            int8_t v1137 = v1136 ? v1135 : (int8_t)0.000000;	// L2075
            v1094[v1130][(v1134 + (v1133 * 16))][v1131][v1132] = v1137;	// L2076
          }
        }
      }
    }
  }
}

void load_array(
    int8_t v1138[1][3][224][224],ap_uint<256> *vv1138,
    int8_t v1139[1000],ap_uint<256> *vv1139,
    int8_t v1140[1024][1024][1][1],ap_uint<256> *vv1140,
    int8_t v1141[1024][512][1][1],ap_uint<256> *vv1141,
    int8_t v1142[512][512][1][1],ap_uint<256> *vv1142,
    int8_t v1143[512][512][1][1],ap_uint<256> *vv1143,
    int8_t v1144[512][512][1][1],ap_uint<256> *vv1144,
    int8_t v1145[512][512][1][1],ap_uint<256> *vv1145,
    int8_t v1146[512][512][1][1],ap_uint<256> *vv1146,
    int8_t v1147[512][256][1][1],ap_uint<256> *vv1147,
    int8_t v1148[256][256][1][1],ap_uint<256> *vv1148,
    int8_t v1149[256][128][1][1],ap_uint<256> *vv1149,
    int8_t v1150[128][128][1][1],ap_uint<256> *vv1150,
    int8_t v1151[128][64][1][1],ap_uint<256> *vv1151,
    int8_t v1152[64][32][1][1],ap_uint<256> *vv1152,
    int8_t v1153[32][3][3][3],ap_uint<256> *vv1153,
    int8_t v1154[32][3][3],ap_uint<256> *vv1154,
    int8_t v1155[64][3][3],ap_uint<256> *vv1155,
    int8_t v1156[128][3][3],ap_uint<256> *vv1156,
    int8_t v1157[128][3][3],ap_uint<256> *vv1157,
    int8_t v1158[256][3][3],ap_uint<256> *vv1158,
    int8_t v1159[256][3][3],ap_uint<256> *vv1159,
    int8_t v1160[512][3][3],ap_uint<256> *vv1160,
    int8_t v1161[512][3][3],ap_uint<256> *vv1161,
    int8_t v1162[512][3][3],ap_uint<256> *vv1162,
    int8_t v1163[512][3][3],ap_uint<256> *vv1163,
    int8_t v1164[512][3][3],ap_uint<256> *vv1164,
    int8_t v1165[512][3][3],ap_uint<256> *vv1165,
    int8_t v1166[1024][3][3],ap_uint<256> *vv1166,
    int8_t v1167[1024][1000],ap_uint<256> *vv1167,
    int8_t v1168[1][1000],ap_uint<256> *vv1168
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
ap_uint<256> temp_24;
ap_uint<256> temp_25;
ap_uint<256> temp_26;
ap_uint<256> temp_27;
ap_uint<256> temp_28;
ap_uint<256> temp_29;
ap_uint<256> temp_30;
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 224; ++k) {
              for (int l = 0; l < 7; ++l) {
              temp_0 = vv1138[i * 3 * 224 * 7 + j * 224 * 7 + k * 7 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1138[i][j][k][l * 32 + bias] = temp_0.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 31; ++i) { 
      temp_1 = vv1139[i];
      for (int bias = 0; bias < 32; ++bias) { 
                    v1139[i * 32 + bias] = temp_1.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 1024; ++i) {
      for (int j = 0; j < 32; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_2 = vv1140[i * 32 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1140[i][j * 32 + bias][k][l] = temp_2.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 1024; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_3 = vv1141[i * 16 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1141[i][j * 32 + bias][k][l] = temp_3.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_4 = vv1142[i * 16 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1142[i][j * 32 + bias][k][l] = temp_4.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_5 = vv1143[i * 16 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1143[i][j * 32 + bias][k][l] = temp_5.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_6 = vv1144[i * 16 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1144[i][j * 32 + bias][k][l] = temp_6.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_7 = vv1145[i * 16 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1145[i][j * 32 + bias][k][l] = temp_7.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_8 = vv1146[i * 16 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1146[i][j * 32 + bias][k][l] = temp_8.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_9 = vv1147[i * 8 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1147[i][j * 32 + bias][k][l] = temp_9.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_10 = vv1148[i * 8 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1148[i][j * 32 + bias][k][l] = temp_10.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_11 = vv1149[i * 4 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1149[i][j * 32 + bias][k][l] = temp_11.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_12 = vv1150[i * 4 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1150[i][j * 32 + bias][k][l] = temp_12.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_13 = vv1151[i * 2 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1151[i][j * 32 + bias][k][l] = temp_13.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 1; ++j) {
          for (int k = 0; k < 1; ++k) {
              for (int l = 0; l < 1; ++l) {
              temp_14 = vv1152[i * 1 * 1 * 1 + j * 1 * 1 + k * 1 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1152[i][j * 32 + bias][k][l] = temp_14.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_15 = vv1153[i * 3 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1153[i * 32 + bias][j][k][l] = temp_15.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_16 = vv1154[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1154[i * 32 + bias][j][k] = temp_16.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_17 = vv1155[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1155[i * 32 + bias][j][k] = temp_17.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_18 = vv1156[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1156[i * 32 + bias][j][k] = temp_18.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_19 = vv1157[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1157[i * 32 + bias][j][k] = temp_19.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_20 = vv1158[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1158[i * 32 + bias][j][k] = temp_20.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_21 = vv1159[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1159[i * 32 + bias][j][k] = temp_21.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_22 = vv1160[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1160[i * 32 + bias][j][k] = temp_22.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_23 = vv1161[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1161[i * 32 + bias][j][k] = temp_23.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_24 = vv1162[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1162[i * 32 + bias][j][k] = temp_24.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_25 = vv1163[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1163[i * 32 + bias][j][k] = temp_25.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_26 = vv1164[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1164[i * 32 + bias][j][k] = temp_26.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_27 = vv1165[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1165[i * 32 + bias][j][k] = temp_27.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 32; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              temp_28 = vv1166[i * 3 * 3 + j * 3 + k];
              for (int bias = 0; bias < 32; ++bias) { 
                  v1166[i * 32 + bias][j][k] = temp_28.range(bias*8+7, bias*8);
}
}
}
}
    for (int i = 0; i < 1024; ++i) {
      for (int j = 0; j < 31; ++j) {
          temp_29 = vv1167[i * 31 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v1167[i][j * 32 + bias] = temp_29.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 31; ++j) {
          temp_30 = vv1168[i * 31 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v1168[i][j * 32 + bias] = temp_30.range(bias*8+7, bias*8);
}
}
}
}



/// This is top function.
void main_graph(
    ap_uint<256> *vv1138,
    ap_uint<256> *vv1139,
    ap_uint<256> *vv1140,
    ap_uint<256> *vv1141,
    ap_uint<256> *vv1142,
    ap_uint<256> *vv1143,
    ap_uint<256> *vv1144,
    ap_uint<256> *vv1145,
    ap_uint<256> *vv1146,
    ap_uint<256> *vv1147,
    ap_uint<256> *vv1148,
    ap_uint<256> *vv1149,
    ap_uint<256> *vv1150,
    ap_uint<256> *vv1151,
    ap_uint<256> *vv1152,
    ap_uint<256> *vv1153,
    ap_uint<256> *vv1154,
    ap_uint<256> *vv1155,
    ap_uint<256> *vv1156,
    ap_uint<256> *vv1157,
    ap_uint<256> *vv1158,
    ap_uint<256> *vv1159,
    ap_uint<256> *vv1160,
    ap_uint<256> *vv1161,
    ap_uint<256> *vv1162,
    ap_uint<256> *vv1163,
    ap_uint<256> *vv1164,
    ap_uint<256> *vv1165,
    ap_uint<256> *vv1166,
    ap_uint<256> *vv1167,
    ap_uint<256> *vv1168
) {	// L2084
  #pragma HLS interface s_axilite port=return 
  #pragma HLS INTERFACE m_axi port=vv1138 offset = slave bundle=gmem0
  #pragma HLS INTERFACE m_axi port=vv1139 offset = slave bundle=gmem1
  #pragma HLS INTERFACE m_axi port=vv1140 offset = slave bundle=gmem2
  #pragma HLS INTERFACE m_axi port=vv1141 offset = slave bundle=gmem3
  #pragma HLS INTERFACE m_axi port=vv1142 offset = slave bundle=gmem4
  #pragma HLS INTERFACE m_axi port=vv1143 offset = slave bundle=gmem5
  #pragma HLS INTERFACE m_axi port=vv1144 offset = slave bundle=gmem6
  #pragma HLS INTERFACE m_axi port=vv1145 offset = slave bundle=gmem7
  #pragma HLS INTERFACE m_axi port=vv1146 offset = slave bundle=gmem8
  #pragma HLS INTERFACE m_axi port=vv1147 offset = slave bundle=gmem9
  #pragma HLS INTERFACE m_axi port=vv1148 offset = slave bundle=gmem10
  #pragma HLS INTERFACE m_axi port=vv1149 offset = slave bundle=gmem11
  #pragma HLS INTERFACE m_axi port=vv1150 offset = slave bundle=gmem12
  #pragma HLS INTERFACE m_axi port=vv1151 offset = slave bundle=gmem13
  #pragma HLS INTERFACE m_axi port=vv1152 offset = slave bundle=gmem14
  #pragma HLS INTERFACE m_axi port=vv1153 offset = slave bundle=gmem15
  #pragma HLS INTERFACE m_axi port=vv1154 offset = slave bundle=gmem16
  #pragma HLS INTERFACE m_axi port=vv1155 offset = slave bundle=gmem17
  #pragma HLS INTERFACE m_axi port=vv1156 offset = slave bundle=gmem18
  #pragma HLS INTERFACE m_axi port=vv1157 offset = slave bundle=gmem19
  #pragma HLS INTERFACE m_axi port=vv1158 offset = slave bundle=gmem20
  #pragma HLS INTERFACE m_axi port=vv1159 offset = slave bundle=gmem21
  #pragma HLS INTERFACE m_axi port=vv1160 offset = slave bundle=gmem22
  #pragma HLS INTERFACE m_axi port=vv1161 offset = slave bundle=gmem23
  #pragma HLS INTERFACE m_axi port=vv1162 offset = slave bundle=gmem24
  #pragma HLS INTERFACE m_axi port=vv1163 offset = slave bundle=gmem25
  #pragma HLS INTERFACE m_axi port=vv1164 offset = slave bundle=gmem26
  #pragma HLS INTERFACE m_axi port=vv1165 offset = slave bundle=gmem27
  #pragma HLS INTERFACE m_axi port=vv1166 offset = slave bundle=gmem28
  #pragma HLS INTERFACE m_axi port=vv1167 offset = slave bundle=gmem29
  #pragma HLS INTERFACE m_axi port=vv1168 offset = slave bundle=gmem30

  int8_t v1138[1][3][224][224];
  int8_t v1139[1000];
  int8_t v1140[1024][1024][1][1];
  int8_t v1141[1024][512][1][1];
  int8_t v1142[512][512][1][1];
  int8_t v1143[512][512][1][1];
  int8_t v1144[512][512][1][1];
  int8_t v1145[512][512][1][1];
  int8_t v1146[512][512][1][1];
  int8_t v1147[512][256][1][1];
  int8_t v1148[256][256][1][1];
  int8_t v1149[256][128][1][1];
  int8_t v1150[128][128][1][1];
  int8_t v1151[128][64][1][1];
  int8_t v1152[64][32][1][1];
  int8_t v1153[32][3][3][3];
  int8_t v1154[32][3][3];
  int8_t v1155[64][3][3];
  int8_t v1156[128][3][3];
  int8_t v1157[128][3][3];
  int8_t v1158[256][3][3];
  int8_t v1159[256][3][3];
  int8_t v1160[512][3][3];
  int8_t v1161[512][3][3];
  int8_t v1162[512][3][3];
  int8_t v1163[512][3][3];
  int8_t v1164[512][3][3];
  int8_t v1165[512][3][3];
  int8_t v1166[1024][3][3];
  int8_t v1167[1024][1000];
  int8_t v1168[1][1000];
  #pragma HLS interface bram port=v1138
  #pragma HLS bind_storage variable=v1138 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1139
  #pragma HLS bind_storage variable=v1139 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1140
  #pragma HLS array_partition variable=v1140 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1140 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1141
  #pragma HLS array_partition variable=v1141 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1141 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1142
  #pragma HLS array_partition variable=v1142 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1142 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1143
  #pragma HLS array_partition variable=v1143 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1143 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1144
  #pragma HLS array_partition variable=v1144 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1144 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1145
  #pragma HLS array_partition variable=v1145 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1145 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1146
  #pragma HLS array_partition variable=v1146 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1146 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1147
  #pragma HLS array_partition variable=v1147 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1147 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1148
  #pragma HLS array_partition variable=v1148 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1148 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1149
  #pragma HLS array_partition variable=v1149 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1149 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1150
  #pragma HLS array_partition variable=v1150 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1150 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1151
  #pragma HLS array_partition variable=v1151 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1151 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1152
  #pragma HLS array_partition variable=v1152 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1152 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1153
  #pragma HLS array_partition variable=v1153 cyclic factor=16 dim=1
  #pragma HLS array_partition variable=v1153 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1153 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1153 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1153 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1154
  #pragma HLS array_partition variable=v1154 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1154 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1154 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1154 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1155
  #pragma HLS array_partition variable=v1155 cyclic factor=16 dim=1
  #pragma HLS array_partition variable=v1155 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1155 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1155 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1156
  #pragma HLS array_partition variable=v1156 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1156 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1156 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1156 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1157
  #pragma HLS array_partition variable=v1157 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1157 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1157 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1157 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1158
  #pragma HLS array_partition variable=v1158 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1158 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1158 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1159
  #pragma HLS array_partition variable=v1159 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1159 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1159 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1160
  #pragma HLS array_partition variable=v1160 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1160 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1160 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1161
  #pragma HLS array_partition variable=v1161 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1161 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1161 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1162
  #pragma HLS array_partition variable=v1162 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1162 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1162 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1163
  #pragma HLS array_partition variable=v1163 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1163 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1163 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1164
  #pragma HLS array_partition variable=v1164 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1164 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1164 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1165
  #pragma HLS array_partition variable=v1165 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1165 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1165 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1166
  #pragma HLS array_partition variable=v1166 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1166 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1166 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1167
  #pragma HLS bind_storage variable=v1167 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1168
  #pragma HLS bind_storage variable=v1168 type=ram_t2p impl=bram

load_array(
        v1138,vv1138,
        v1139,vv1139,
        v1140,vv1140,
        v1141,vv1141,
        v1142,vv1142,
        v1143,vv1143,
        v1144,vv1144,
        v1145,vv1145,
        v1146,vv1146,
        v1147,vv1147,
        v1148,vv1148,
        v1149,vv1149,
        v1150,vv1150,
        v1151,vv1151,
        v1152,vv1152,
        v1153,vv1153,
        v1154,vv1154,
        v1155,vv1155,
        v1156,vv1156,
        v1157,vv1157,
        v1158,vv1158,
        v1159,vv1159,
        v1160,vv1160,
        v1161,vv1161,
        v1162,vv1162,
        v1163,vv1163,
        v1164,vv1164,
        v1165,vv1165,
        v1166,vv1166,
        v1167,vv1167,
        v1168,vv1168
    );

  // #pragma HLS dataflow

  // int8_t v1169[1][32][112][112];	// L2086
  // #pragma HLS stream variable=v1169 depth=3000 type=fifo

  // #pragma HLS array_partition variable=v1169 cyclic factor=16 dim=2
  // #pragma HLS bind_storage variable=v1169 type=ram_t2p impl=bram

  // main_graph_node30(v1138, v1153, v1169);	// L2087
  // int8_t v1170[1][32][112][112];	// L2088
  // #pragma HLS stream variable=v1170 depth=3000 type=fifo

  // #pragma HLS array_partition variable=v1170 cyclic factor=8 dim=2
  // #pragma HLS bind_storage variable=v1170 type=ram_t2p impl=bram

  // main_graph_node29(v1169, v1154, v1170);	// L2089
  // int8_t v1171[1][64][112][112];	// L2090
  // #pragma HLS stream variable=v1171 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1171 type=ram_t2p impl=bram

  // main_graph_node28(v1152, v1170, v1171);	// L2091
  // int8_t v1172[1][64][56][56];	// L2092
  // #pragma HLS stream variable=v1172 depth=3000 type=fifo

  // #pragma HLS array_partition variable=v1172 cyclic factor=16 dim=2
  // #pragma HLS bind_storage variable=v1172 type=ram_t2p impl=bram

  // main_graph_node27(v1155, v1171, v1172);	// L2093
  // int8_t v1173[1][128][56][56];	// L2094
  // #pragma HLS stream variable=v1173 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1173 type=ram_t2p impl=bram

  // main_graph_node26(v1172, v1151, v1173);	// L2095
  // int8_t v1174[1][128][56][56];	// L2096
  // #pragma HLS stream variable=v1174 depth=3000 type=fifo

  // #pragma HLS array_partition variable=v1174 cyclic factor=8 dim=2
  // #pragma HLS bind_storage variable=v1174 type=ram_t2p impl=bram

  // main_graph_node25(v1173, v1156, v1174);	// L2097
  // int8_t v1175[1][128][56][56];	// L2098
  // #pragma HLS stream variable=v1175 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1175 type=ram_t2p impl=bram

  // main_graph_node24(v1174, v1150, v1175);	// L2099
  // int8_t v1176[1][128][28][28];	// L2100
  // #pragma HLS stream variable=v1176 depth=3000 type=fifo

  // #pragma HLS array_partition variable=v1176 cyclic factor=8 dim=2
  // #pragma HLS bind_storage variable=v1176 type=ram_t2p impl=bram

  // main_graph_node23(v1175, v1157, v1176);	// L2101
  // int8_t v1177[1][256][28][28];	// L2102
  // #pragma HLS stream variable=v1177 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1177 type=ram_t2p impl=bram

  // main_graph_node22(v1176, v1149, v1177);	// L2103
  // int8_t v1178[1][256][28][28];	// L2104
  // #pragma HLS stream variable=v1178 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1178 type=ram_t2p impl=bram

  // main_graph_node21(v1158, v1177, v1178);	// L2105
  // int8_t v1179[1][256][28][28];	// L2106
  // #pragma HLS stream variable=v1179 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1179 type=ram_t2p impl=bram

  // main_graph_node20(v1178, v1148, v1179);	// L2107
  // int8_t v1180[1][256][14][14];	// L2108
  // #pragma HLS stream variable=v1180 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1180 type=ram_t2p impl=bram

  // main_graph_node19(v1179, v1159, v1180);	// L2109
  // int8_t v1181[1][512][14][14];	// L2110
  // #pragma HLS stream variable=v1181 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1181 type=ram_t2p impl=bram

  // main_graph_node18(v1147, v1180, v1181);	// L2111
  // int8_t v1182[1][512][14][14];	// L2112
  // #pragma HLS stream variable=v1182 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1182 type=ram_t2p impl=bram

  // main_graph_node17(v1160, v1181, v1182);	// L2113
  // int8_t v1183[1][512][14][14];	// L2114
  // #pragma HLS stream variable=v1183 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1183 type=ram_t2p impl=bram

  // main_graph_node16(v1146, v1182, v1183);	// L2115
  // int8_t v1184[1][512][14][14];	// L2116
  // #pragma HLS stream variable=v1184 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1184 type=ram_t2p impl=bram

  // main_graph_node15(v1183, v1161, v1184);	// L2117
  // int8_t v1185[1][512][14][14];	// L2118
  // #pragma HLS stream variable=v1185 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1185 type=ram_t2p impl=bram

  // main_graph_node14(v1145, v1184, v1185);	// L2119
  // int8_t v1186[1][512][14][14];	// L2120
  // #pragma HLS stream variable=v1186 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1186 type=ram_t2p impl=bram

  // main_graph_node13(v1185, v1162, v1186);	// L2121
  // int8_t v1187[1][512][14][14];	// L2122
  // #pragma HLS stream variable=v1187 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1187 type=ram_t2p impl=bram

  // main_graph_node12(v1186, v1144, v1187);	// L2123
  // int8_t v1188[1][512][14][14];	// L2124
  // #pragma HLS stream variable=v1188 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1188 type=ram_t2p impl=bram

  // main_graph_node11(v1163, v1187, v1188);	// L2125
  // int8_t v1189[1][512][14][14];	// L2126
  // #pragma HLS stream variable=v1189 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1189 type=ram_t2p impl=bram

  // main_graph_node10(v1143, v1188, v1189);	// L2127
  // int8_t v1190[1][512][14][14];	// L2128
  // #pragma HLS stream variable=v1190 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1190 type=ram_t2p impl=bram

  // main_graph_node9(v1189, v1164, v1190);	// L2129
  // int8_t v1191[1][512][14][14];	// L2130
  // #pragma HLS stream variable=v1191 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1191 type=ram_t2p impl=bram

  // main_graph_node8(v1190, v1142, v1191);	// L2131
  // int8_t v1192[1][512][7][7];	// L2132
  // #pragma HLS stream variable=v1192 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1192 type=ram_t2p impl=bram

  // main_graph_node7(v1165, v1191, v1192);	// L2133
  // int8_t v1193[1][1024][7][7];	// L2134
  // #pragma HLS stream variable=v1193 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1193 type=ram_t2p impl=bram

  // main_graph_node6(v1141, v1192, v1193);	// L2135
  // int8_t v1194[1][1024][7][7];	// L2136
  // #pragma HLS stream variable=v1194 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1194 type=ram_t2p impl=bram

  // main_graph_node5(v1166, v1193, v1194);	// L2137
  // int8_t v1195[1][1024][7][7];	// L2138
  // #pragma HLS stream variable=v1195 depth=3000 type=fifo

  // #pragma HLS bind_storage variable=v1195 type=ram_t2p impl=bram

  // main_graph_node4(v1194, v1140, v1195);	// L2139
  // int8_t v1196[1][1024][8][8];	// L2140
  // #pragma HLS bind_storage variable=v1196 type=ram_t2p impl=bram

  // main_graph_node3(v1195, v1196);	// L2141
  // int8_t v1197[1][1];	// L2142
  // #pragma HLS bind_storage variable=v1197 type=ram_t2p impl=bram

  // int8_t v1198[1][1024][1][1];	// L2143
  // #pragma HLS bind_storage variable=v1198 type=ram_t2p impl=bram

  // main_graph_node2(v1196, v1198, v1197);	// L2144
  // int8_t v1199[1][1024][1][1];	// L2145
  // #pragma HLS bind_storage variable=v1199 type=ram_t2p impl=bram

  // main_graph_node1(v1198, v1197, v1199);	// L2146
  // main_graph_node0(v1199, v1167, v1139, v1168);	// L2147
}

