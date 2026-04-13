
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
  int8_t v0[1][1000],
  int8_t v1[1000],
  int8_t v2[1][1000]
) {	// L10
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L11
    for (int v4 = 0; v4 < 1000; v4 += 1) {	// L12
      int8_t v5 = v0[0][v4];	// L13
      int8_t v6 = v1[v4];	// L14
      int8_t v7 = v5 + v6;	// L15
      v2[v3][v4] = v7;	// L16
    }
  }
  return ;	// L19
}

void main_graph_node1(
  int8_t v8[1][4096],
  int8_t v9[4096][1000],
  int8_t v10[1][1000]
) {	// L21
  #pragma HLS dataflow

  int8_t v11[1][1000];	// L23
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L24
    for (int v13 = 0; v13 < 1000; v13 += 1) {	// L25
      v11[v12][v13] = (int8_t)0.000000;	// L26
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L29
    for (int v15 = 0; v15 < 1000; v15 += 1) {	// L30
      for (int v16 = 0; v16 < 4096; v16 += 1) {	// L31
        int8_t v17 = v8[v14][v16];	// L32
        int8_t v18 = v9[v16][v15];	// L33
        int8_t v19 = v11[v14][v15];	// L34
        int8_t v20 = v17 * v18;	// L35
        int8_t v21 = v19 + v20;	// L36
        v10[v14][v15] = v21;	// L37
      }
    }
  }
  return ;	// L41
}

void main_graph_node2(
  int8_t v22[1][4096],
  int8_t v23[4096],
  int8_t v24[1][4096]
) {	// L43
  #pragma HLS dataflow

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L45
    for (int v26 = 0; v26 < 4096; v26 += 1) {	// L46
      int8_t v27 = v22[0][v26];	// L47
      int8_t v28 = v23[v26];	// L48
      int8_t v29 = v27 + v28;	// L49
      bool v30 = v29 > (int8_t)0.000000;	// L50
      int8_t v31 = v30 ? v29 : (int8_t)0.000000;	// L51
      v24[v25][v26] = v31;	// L52
    }
  }
  return ;	// L55
}

void main_graph_node3(
  int8_t v32[1][4096][1][1],
  int8_t v33[4096][4096],
  int8_t v34[1][4096]
) {	// L57
  #pragma HLS dataflow

  int8_t v35[1][4096];	// L59
  #pragma HLS bind_storage variable=v35 type=ram_t2p impl=bram

  for (int v36 = 0; v36 < 1; v36 += 1) {	// L60
    for (int v37 = 0; v37 < 4096; v37 += 1) {	// L61
      v35[v36][v37] = (int8_t)0.000000;	// L62
    }
  }
  for (int v38 = 0; v38 < 1; v38 += 1) {	// L65
    for (int v39 = 0; v39 < 4096; v39 += 1) {	// L66
      for (int v40 = 0; v40 < 4096; v40 += 1) {	// L67
        int8_t v41 = v32[v38][v40][0][0];	// L68
        int8_t v42 = v33[v40][v39];	// L69
        int8_t v43 = v35[v38][v39];	// L70
        int8_t v44 = v41 * v42;	// L71
        int8_t v45 = v43 + v44;	// L72
        v34[v38][v39] = v45;	// L73
      }
    }
  }
  return ;	// L77
}

void main_graph_node4(
  int8_t v46[1][256][5][5],
  int8_t v47[4096][256][5][5],
  int8_t v48[1][4096][1][1]
) {	// L79
  #pragma HLS dataflow

  int8_t v49[1][4096][1][1];	// L81
  #pragma HLS stream variable=v49 depth=10 type=fifo

  #pragma HLS bind_storage variable=v49 type=ram_t2p impl=bram

  int8_t v50[1][256][5][5];	// L82
  #pragma HLS array_partition variable=v50 cyclic factor=5 dim=3
  #pragma HLS bind_storage variable=v50 type=ram_2p impl=bram

  int8_t v51[1][256][5][5];	// L83
  #pragma HLS array_partition variable=v51 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v51 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v51 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v51 type=ram_2p impl=lutram

  for (int v52 = 0; v52 < 1; v52 += 1) {	// L84
    for (int v53 = 0; v53 < 5; v53 += 1) {	// L85
      for (int v54 = 0; v54 < 5; v54 += 1) {	// L86
        for (int v55 = 0; v55 < 256; v55 += 1) {	// L87
          int8_t v56 = v50[v52][v55][1][v54];	// L88
          v50[v52][v55][0][v54] = v56;	// L89
          int8_t v57 = v50[v52][v55][2][v54];	// L90
          v50[v52][v55][1][v54] = v57;	// L91
          int8_t v58 = v50[v52][v55][3][v54];	// L92
          v50[v52][v55][2][v54] = v58;	// L93
          int8_t v59 = v50[v52][v55][4][v54];	// L94
          v50[v52][v55][3][v54] = v59;	// L95
          int8_t v60 = v46[v52][v55][v53][v54];	// L96
          v50[v52][v55][4][v54] = v60;	// L97
        }
        if ((v53 - 4) >= 0) {	// L99
          for (int v61 = 0; v61 < 256; v61 += 1) {	// L100
            for (int v62 = 0; v62 < 5; v62 += 1) {	// L101
              int8_t v63 = v51[v52][v61][v62][1];	// L102
              v51[v52][v61][v62][0] = v63;	// L103
              int8_t v64 = v51[v52][v61][v62][2];	// L104
              v51[v52][v61][v62][1] = v64;	// L105
              int8_t v65 = v51[v52][v61][v62][3];	// L106
              v51[v52][v61][v62][2] = v65;	// L107
              int8_t v66 = v51[v52][v61][v62][4];	// L108
              v51[v52][v61][v62][3] = v66;	// L109
              int8_t v67 = v50[v52][v61][v62][v54];	// L110
              v51[v52][v61][v62][4] = v67;	// L111
            }
          }
          if ((v54 - 4) >= 0) {	// L114
            int8_t v68[4096];	// L115
            #pragma HLS bind_storage variable=v68 type=ram_2p impl=bram

            for (int v69 = 0; v69 < 4096; v69 += 1) {	// L116
              v68[v69] = (int8_t)0.000000;	// L117
              for (int v70 = 0; v70 < 32; v70 += 1) {	// L118
                #pragma HLS pipeline II=1
                for (int v71 = 0; v71 < 8; v71 += 1) {	// L119
                  for (int v72 = 0; v72 < 5; v72 += 1) {	// L120
                    for (int v73 = 0; v73 < 5; v73 += 1) {	// L121
                      int8_t v74 = v51[v52][(v71 + (v70 * 8))][v72][v73];	// L122
                      int8_t v75 = v47[v69][(v71 + (v70 * 8))][v72][v73];	// L123
                      int8_t v76 = v74 * v75;	// L124
                      int8_t v77 = v68[v69];	// L125
                      int8_t v78 = v77 + v76;	// L126
                      v68[v69] = v78;	// L127
                    }
                  }
                }
              }
              int8_t v79 = v68[v69];	// L132
              v49[v52][v69][(v53 - 4)][(v54 - 4)] = v79;	// L133
            }
          }
        }
      }
    }
  }
  for (int v80 = 0; v80 < 1; v80 += 1) {	// L140
    for (int v81 = 0; v81 < 1; v81 += 1) {	// L141
      for (int v82 = 0; v82 < 1; v82 += 1) {	// L142
        for (int v83 = 0; v83 < 4096; v83 += 1) {	// L143
          int8_t v84 = v49[0][v83][0][0];	// L144
          bool v85 = v84 > (int8_t)0.000000;	// L145
          int8_t v86 = v85 ? v84 : (int8_t)0.000000;	// L146
          v48[v80][v83][v81][v82] = v86;	// L147
        }
      }
    }
  }
  return ;	// L152
}

void main_graph_node5(
  int8_t v87[1][256][12][12],
  int8_t v88[1][256][5][5]
) {	// L154
  #pragma HLS dataflow

  int8_t v89;	// L157
  v89 = (int8_t)-INFINITY;	// L158
  int8_t v90[1][256][12][12];	// L159
  #pragma HLS bind_storage variable=v90 type=ram_2p impl=bram

  for (int v91 = 0; v91 < 1; v91 += 1) {	// L160
    for (int v92 = 0; v92 < 12; v92 += 1) {	// L161
      for (int v93 = 0; v93 < 12; v93 += 1) {	// L162
        for (int v94 = 0; v94 < 256; v94 += 1) {	// L163
          int8_t v95 = v87[v91][v94][v92][v93];	// L164
          v90[v91][v94][v92][v93] = v95;	// L165
        }
      }
    }
  }
  for (int v96 = 0; v96 < 1; v96 += 1) {	// L170
    for (int v97 = 0; v97 < 5; v97 += 1) {	// L171
      for (int v98 = 0; v98 < 5; v98 += 1) {	// L172
        for (int v99 = 0; v99 < 256; v99 += 1) {	// L173
          int8_t v100;	// L174
          v100 = (int8_t)0.000000;	// L175
          for (int v101 = 0; v101 < 3; v101 += 1) {	// L176
            for (int v102 = 0; v102 < 3; v102 += 1) {	// L177
              int8_t v103 = v90[v96][v99][((v97 * 2) + v101)][((v98 * 2) + v102)];	// L178
              int8_t v104 = v89;	// L179
              int8_t v105 = max(v104, v103);	// L180
              v100 = v105;	// L181
            }
          }
          int8_t v106 = v100;	// L184
          v88[v96][v99][v97][v98] = v106;	// L185
        }
      }
    }
  }
  return ;	// L190
}

void main_graph_node6(
  int8_t v107[256][384][3][3],
  int8_t v108[1][384][12][12],
  int8_t v109[1][256][12][12]
) {	// L192
  #pragma HLS dataflow

  int8_t v110[1][384][14][14];	// L194
  #pragma HLS stream variable=v110 depth=10 type=fifo

  #pragma HLS bind_storage variable=v110 type=ram_t2p impl=bram

  for (int v111 = 0; v111 < 1; v111 += 1) {	// L195
    for (int v112 = 0; v112 < 14; v112 += 1) {	// L196
      for (int v113 = 0; v113 < 14; v113 += 1) {	// L197
        for (int v114 = 0; v114 < 384; v114 += 1) {	// L198
          int8_t v115;	// L199
          v115 = (int8_t)0.000000;	// L200
          if (((-v112) + 11) >= 0 && ((-v113) + 11) >= 0) {	// L201
            int8_t v116 = v108[v111][v114][v112][v113];	// L202
            v115 = v116;	// L203
          }
          int8_t v117 = v115;	// L205
          v110[v111][v114][v112][v113] = v117;	// L206
        }
      }
    }
  }
  int8_t v118[1][256][12][12];	// L211
  #pragma HLS stream variable=v118 depth=10 type=fifo

  #pragma HLS bind_storage variable=v118 type=ram_t2p impl=bram

  int8_t v119[1][384][3][14];	// L212
  #pragma HLS array_partition variable=v119 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v119 type=ram_2p impl=bram

  int8_t v120[1][384][3][3];	// L213
  #pragma HLS array_partition variable=v120 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v120 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v120 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v120 type=ram_2p impl=lutram

  for (int v121 = 0; v121 < 1; v121 += 1) {	// L214
    for (int v122 = 0; v122 < 14; v122 += 1) {	// L215
      for (int v123 = 0; v123 < 14; v123 += 1) {	// L216
        for (int v124 = 0; v124 < 384; v124 += 1) {	// L217
          int8_t v125 = v119[v121][v124][1][v123];	// L218
          v119[v121][v124][0][v123] = v125;	// L219
          int8_t v126 = v119[v121][v124][2][v123];	// L220
          v119[v121][v124][1][v123] = v126;	// L221
          int8_t v127 = v110[v121][v124][v122][v123];	// L222
          v119[v121][v124][2][v123] = v127;	// L223
        }
        if ((v122 - 2) >= 0) {	// L225
          for (int v128 = 0; v128 < 384; v128 += 1) {	// L226
            for (int v129 = 0; v129 < 3; v129 += 1) {	// L227
              int8_t v130 = v120[v121][v128][v129][1];	// L228
              v120[v121][v128][v129][0] = v130;	// L229
              int8_t v131 = v120[v121][v128][v129][2];	// L230
              v120[v121][v128][v129][1] = v131;	// L231
              int8_t v132 = v119[v121][v128][v129][v123];	// L232
              v120[v121][v128][v129][2] = v132;	// L233
            }
          }
          if ((v123 - 2) >= 0) {	// L236
            int8_t v133[256];	// L237
            #pragma HLS bind_storage variable=v133 type=ram_2p impl=bram

            for (int v134 = 0; v134 < 256; v134 += 1) {	// L238
              v133[v134] = (int8_t)0.000000;	// L239
              for (int v135 = 0; v135 < 96; v135 += 1) {	// L240
                #pragma HLS pipeline II=1
                for (int v136 = 0; v136 < 4; v136 += 1) {	// L241
                  for (int v137 = 0; v137 < 3; v137 += 1) {	// L242
                    for (int v138 = 0; v138 < 3; v138 += 1) {	// L243
                      int8_t v139 = v120[v121][(v136 + (v135 * 4))][v137][v138];	// L244
                      int8_t v140 = v107[v134][(v136 + (v135 * 4))][v137][v138];	// L245
                      int8_t v141 = v139 * v140;	// L246
                      int8_t v142 = v133[v134];	// L247
                      int8_t v143 = v142 + v141;	// L248
                      v133[v134] = v143;	// L249
                    }
                  }
                }
              }
              int8_t v144 = v133[v134];	// L254
              v118[v121][v134][(v122 - 2)][(v123 - 2)] = v144;	// L255
            }
          }
        }
      }
    }
  }
  for (int v145 = 0; v145 < 1; v145 += 1) {	// L262
    for (int v146 = 0; v146 < 12; v146 += 1) {	// L263
      for (int v147 = 0; v147 < 12; v147 += 1) {	// L264
        for (int v148 = 0; v148 < 256; v148 += 1) {	// L265
          int8_t v149 = v118[0][v148][v146][v147];	// L266
          bool v150 = v149 > (int8_t)0.000000;	// L267
          int8_t v151 = v150 ? v149 : (int8_t)0.000000;	// L268
          v109[v145][v148][v146][v147] = v151;	// L269
        }
      }
    }
  }
  return ;	// L274
}

void main_graph_node7(
  int8_t v152[1][384][12][12],
  int8_t v153[384][384][3][3],
  int8_t v154[1][384][12][12]
) {	// L276
  #pragma HLS dataflow

  int8_t v155[1][384][14][14];	// L278
  #pragma HLS stream variable=v155 depth=10 type=fifo

  #pragma HLS bind_storage variable=v155 type=ram_t2p impl=bram

  for (int v156 = 0; v156 < 1; v156 += 1) {	// L279
    for (int v157 = 0; v157 < 14; v157 += 1) {	// L280
      for (int v158 = 0; v158 < 14; v158 += 1) {	// L281
        for (int v159 = 0; v159 < 384; v159 += 1) {	// L282
          int8_t v160;	// L283
          v160 = (int8_t)0.000000;	// L284
          if (((-v157) + 11) >= 0 && ((-v158) + 11) >= 0) {	// L285
            int8_t v161 = v152[v156][v159][v157][v158];	// L286
            v160 = v161;	// L287
          }
          int8_t v162 = v160;	// L289
          v155[v156][v159][v157][v158] = v162;	// L290
        }
      }
    }
  }
  int8_t v163[1][384][12][12];	// L295
  #pragma HLS stream variable=v163 depth=10 type=fifo

  #pragma HLS bind_storage variable=v163 type=ram_t2p impl=bram

  int8_t v164[1][384][3][14];	// L296
  #pragma HLS array_partition variable=v164 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v164 type=ram_2p impl=bram

  int8_t v165[1][384][3][3];	// L297
  #pragma HLS array_partition variable=v165 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v165 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v165 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v165 type=ram_2p impl=lutram

  for (int v166 = 0; v166 < 1; v166 += 1) {	// L298
    for (int v167 = 0; v167 < 14; v167 += 1) {	// L299
      for (int v168 = 0; v168 < 14; v168 += 1) {	// L300
        for (int v169 = 0; v169 < 384; v169 += 1) {	// L301
          int8_t v170 = v164[v166][v169][1][v168];	// L302
          v164[v166][v169][0][v168] = v170;	// L303
          int8_t v171 = v164[v166][v169][2][v168];	// L304
          v164[v166][v169][1][v168] = v171;	// L305
          int8_t v172 = v155[v166][v169][v167][v168];	// L306
          v164[v166][v169][2][v168] = v172;	// L307
        }
        if ((v167 - 2) >= 0) {	// L309
          for (int v173 = 0; v173 < 384; v173 += 1) {	// L310
            for (int v174 = 0; v174 < 3; v174 += 1) {	// L311
              int8_t v175 = v165[v166][v173][v174][1];	// L312
              v165[v166][v173][v174][0] = v175;	// L313
              int8_t v176 = v165[v166][v173][v174][2];	// L314
              v165[v166][v173][v174][1] = v176;	// L315
              int8_t v177 = v164[v166][v173][v174][v168];	// L316
              v165[v166][v173][v174][2] = v177;	// L317
            }
          }
          if ((v168 - 2) >= 0) {	// L320
            int8_t v178[384];	// L321
            #pragma HLS bind_storage variable=v178 type=ram_2p impl=bram

            for (int v179 = 0; v179 < 384; v179 += 1) {	// L322
              v178[v179] = (int8_t)0.000000;	// L323
              for (int v180 = 0; v180 < 48; v180 += 1) {	// L324
                #pragma HLS pipeline II=1
                for (int v181 = 0; v181 < 8; v181 += 1) {	// L325
                  for (int v182 = 0; v182 < 3; v182 += 1) {	// L326
                    for (int v183 = 0; v183 < 3; v183 += 1) {	// L327
                      int8_t v184 = v165[v166][(v181 + (v180 * 8))][v182][v183];	// L328
                      int8_t v185 = v153[v179][(v181 + (v180 * 8))][v182][v183];	// L329
                      int8_t v186 = v184 * v185;	// L330
                      int8_t v187 = v178[v179];	// L331
                      int8_t v188 = v187 + v186;	// L332
                      v178[v179] = v188;	// L333
                    }
                  }
                }
              }
              int8_t v189 = v178[v179];	// L338
              v163[v166][v179][(v167 - 2)][(v168 - 2)] = v189;	// L339
            }
          }
        }
      }
    }
  }
  for (int v190 = 0; v190 < 1; v190 += 1) {	// L346
    for (int v191 = 0; v191 < 12; v191 += 1) {	// L347
      for (int v192 = 0; v192 < 12; v192 += 1) {	// L348
        for (int v193 = 0; v193 < 384; v193 += 1) {	// L349
          int8_t v194 = v163[0][v193][v191][v192];	// L350
          bool v195 = v194 > (int8_t)0.000000;	// L351
          int8_t v196 = v195 ? v194 : (int8_t)0.000000;	// L352
          v154[v190][v193][v191][v192] = v196;	// L353
        }
      }
    }
  }
  return ;	// L358
}

void main_graph_node8(
  int8_t v197[1][256][12][12],
  int8_t v198[384][256][3][3],
  int8_t v199[1][384][12][12]
) {	// L360
  #pragma HLS dataflow

  int8_t v200[1][256][14][14];	// L362
  #pragma HLS stream variable=v200 depth=10 type=fifo

  #pragma HLS bind_storage variable=v200 type=ram_t2p impl=bram

  for (int v201 = 0; v201 < 1; v201 += 1) {	// L363
    for (int v202 = 0; v202 < 14; v202 += 1) {	// L364
      for (int v203 = 0; v203 < 14; v203 += 1) {	// L365
        for (int v204 = 0; v204 < 256; v204 += 1) {	// L366
          int8_t v205;	// L367
          v205 = (int8_t)0.000000;	// L368
          if (((-v202) + 11) >= 0 && ((-v203) + 11) >= 0) {	// L369
            int8_t v206 = v197[v201][v204][v202][v203];	// L370
            v205 = v206;	// L371
          }
          int8_t v207 = v205;	// L373
          v200[v201][v204][v202][v203] = v207;	// L374
        }
      }
    }
  }
  int8_t v208[1][384][12][12];	// L379
  #pragma HLS stream variable=v208 depth=10 type=fifo

  #pragma HLS bind_storage variable=v208 type=ram_t2p impl=bram

  int8_t v209[1][256][3][14];	// L380
  #pragma HLS array_partition variable=v209 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v209 type=ram_2p impl=bram

  int8_t v210[1][256][3][3];	// L381
  #pragma HLS array_partition variable=v210 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v210 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v210 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v210 type=ram_2p impl=lutram

  for (int v211 = 0; v211 < 1; v211 += 1) {	// L382
    for (int v212 = 0; v212 < 14; v212 += 1) {	// L383
      for (int v213 = 0; v213 < 14; v213 += 1) {	// L384
        for (int v214 = 0; v214 < 256; v214 += 1) {	// L385
          int8_t v215 = v209[v211][v214][1][v213];	// L386
          v209[v211][v214][0][v213] = v215;	// L387
          int8_t v216 = v209[v211][v214][2][v213];	// L388
          v209[v211][v214][1][v213] = v216;	// L389
          int8_t v217 = v200[v211][v214][v212][v213];	// L390
          v209[v211][v214][2][v213] = v217;	// L391
        }
        if ((v212 - 2) >= 0) {	// L393
          for (int v218 = 0; v218 < 256; v218 += 1) {	// L394
            for (int v219 = 0; v219 < 3; v219 += 1) {	// L395
              int8_t v220 = v210[v211][v218][v219][1];	// L396
              v210[v211][v218][v219][0] = v220;	// L397
              int8_t v221 = v210[v211][v218][v219][2];	// L398
              v210[v211][v218][v219][1] = v221;	// L399
              int8_t v222 = v209[v211][v218][v219][v213];	// L400
              v210[v211][v218][v219][2] = v222;	// L401
            }
          }
          if ((v213 - 2) >= 0) {	// L404
            int8_t v223[384];	// L405
            #pragma HLS bind_storage variable=v223 type=ram_2p impl=bram

            for (int v224 = 0; v224 < 384; v224 += 1) {	// L406
              v223[v224] = (int8_t)0.000000;	// L407
              for (int v225 = 0; v225 < 64; v225 += 1) {	// L408
                #pragma HLS pipeline II=1
                for (int v226 = 0; v226 < 4; v226 += 1) {	// L409
                  for (int v227 = 0; v227 < 3; v227 += 1) {	// L410
                    for (int v228 = 0; v228 < 3; v228 += 1) {	// L411
                      int8_t v229 = v210[v211][(v226 + (v225 * 4))][v227][v228];	// L412
                      int8_t v230 = v198[v224][(v226 + (v225 * 4))][v227][v228];	// L413
                      int8_t v231 = v229 * v230;	// L414
                      int8_t v232 = v223[v224];	// L415
                      int8_t v233 = v232 + v231;	// L416
                      v223[v224] = v233;	// L417
                    }
                  }
                }
              }
              int8_t v234 = v223[v224];	// L422
              v208[v211][v224][(v212 - 2)][(v213 - 2)] = v234;	// L423
            }
          }
        }
      }
    }
  }
  for (int v235 = 0; v235 < 1; v235 += 1) {	// L430
    for (int v236 = 0; v236 < 12; v236 += 1) {	// L431
      for (int v237 = 0; v237 < 12; v237 += 1) {	// L432
        for (int v238 = 0; v238 < 384; v238 += 1) {	// L433
          int8_t v239 = v208[0][v238][v236][v237];	// L434
          bool v240 = v239 > (int8_t)0.000000;	// L435
          int8_t v241 = v240 ? v239 : (int8_t)0.000000;	// L436
          v199[v235][v238][v236][v237] = v241;	// L437
        }
      }
    }
  }
  return ;	// L442
}

void main_graph_node9(
  int8_t v242[1][256][26][26],
  int8_t v243[1][256][12][12]
) {	// L444
  #pragma HLS dataflow

  int8_t v244;	// L447
  v244 = (int8_t)-INFINITY;	// L448
  int8_t v245[1][256][26][26];	// L449
  #pragma HLS bind_storage variable=v245 type=ram_2p impl=bram

  for (int v246 = 0; v246 < 1; v246 += 1) {	// L450
    for (int v247 = 0; v247 < 26; v247 += 1) {	// L451
      for (int v248 = 0; v248 < 26; v248 += 1) {	// L452
        for (int v249 = 0; v249 < 256; v249 += 1) {	// L453
          int8_t v250 = v242[v246][v249][v247][v248];	// L454
          v245[v246][v249][v247][v248] = v250;	// L455
        }
      }
    }
  }
  for (int v251 = 0; v251 < 1; v251 += 1) {	// L460
    for (int v252 = 0; v252 < 12; v252 += 1) {	// L461
      for (int v253 = 0; v253 < 12; v253 += 1) {	// L462
        for (int v254 = 0; v254 < 256; v254 += 1) {	// L463
          int8_t v255;	// L464
          v255 = (int8_t)0.000000;	// L465
          for (int v256 = 0; v256 < 3; v256 += 1) {	// L466
            for (int v257 = 0; v257 < 3; v257 += 1) {	// L467
              int8_t v258 = v245[v251][v254][((v252 * 2) + v256)][((v253 * 2) + v257)];	// L468
              int8_t v259 = v244;	// L469
              int8_t v260 = max(v259, v258);	// L470
              v255 = v260;	// L471
            }
          }
          int8_t v261 = v255;	// L474
          v243[v251][v254][v252][v253] = v261;	// L475
        }
      }
    }
  }
  return ;	// L480
}

void main_graph_node10(
  int8_t v262[256][96][5][5],
  int8_t v263[1][96][54][54],
  int8_t v264[1][256][26][26]
) {	// L482
  #pragma HLS dataflow

  int8_t v265[1][96][56][56];	// L484
  #pragma HLS stream variable=v265 depth=10 type=fifo

  #pragma HLS bind_storage variable=v265 type=ram_t2p impl=bram

  for (int v266 = 0; v266 < 1; v266 += 1) {	// L485
    for (int v267 = 0; v267 < 56; v267 += 1) {	// L486
      for (int v268 = 0; v268 < 56; v268 += 1) {	// L487
        for (int v269 = 0; v269 < 96; v269 += 1) {	// L488
          int8_t v270;	// L489
          v270 = (int8_t)0.000000;	// L490
          if (((-v267) + 53) >= 0 && ((-v268) + 53) >= 0) {	// L491
            int8_t v271 = v263[v266][v269][v267][v268];	// L492
            v270 = v271;	// L493
          }
          int8_t v272 = v270;	// L495
          v265[v266][v269][v267][v268] = v272;	// L496
        }
      }
    }
  }
  int8_t v273[1][256][26][26];	// L501
  #pragma HLS stream variable=v273 depth=10 type=fifo

  #pragma HLS bind_storage variable=v273 type=ram_t2p impl=bram

  int8_t v274[1][96][5][56];	// L502
  #pragma HLS array_partition variable=v274 cyclic factor=5 dim=3
  #pragma HLS bind_storage variable=v274 type=ram_2p impl=bram

  int8_t v275[1][96][5][5];	// L503
  #pragma HLS array_partition variable=v275 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v275 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v275 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v275 type=ram_2p impl=lutram

  for (int v276 = 0; v276 < 1; v276 += 1) {	// L504
    for (int v277 = 0; v277 < 56; v277 += 1) {	// L505
      for (int v278 = 0; v278 < 56; v278 += 1) {	// L506
        for (int v279 = 0; v279 < 96; v279 += 1) {	// L507
          int8_t v280 = v274[v276][v279][1][v278];	// L508
          v274[v276][v279][0][v278] = v280;	// L509
          int8_t v281 = v274[v276][v279][2][v278];	// L510
          v274[v276][v279][1][v278] = v281;	// L511
          int8_t v282 = v274[v276][v279][3][v278];	// L512
          v274[v276][v279][2][v278] = v282;	// L513
          int8_t v283 = v274[v276][v279][4][v278];	// L514
          v274[v276][v279][3][v278] = v283;	// L515
          int8_t v284 = v265[v276][v279][v277][v278];	// L516
          v274[v276][v279][4][v278] = v284;	// L517
        }
        if ((v277 - 30) >= 0) {	// L519
          for (int v285 = 0; v285 < 96; v285 += 1) {	// L520
            for (int v286 = 0; v286 < 5; v286 += 1) {	// L521
              int8_t v287 = v275[v276][v285][v286][1];	// L522
              v275[v276][v285][v286][0] = v287;	// L523
              int8_t v288 = v275[v276][v285][v286][2];	// L524
              v275[v276][v285][v286][1] = v288;	// L525
              int8_t v289 = v275[v276][v285][v286][3];	// L526
              v275[v276][v285][v286][2] = v289;	// L527
              int8_t v290 = v275[v276][v285][v286][4];	// L528
              v275[v276][v285][v286][3] = v290;	// L529
              int8_t v291 = v274[v276][v285][v286][v278];	// L530
              v275[v276][v285][v286][4] = v291;	// L531
            }
          }
          if ((v278 - 30) >= 0) {	// L534
            int8_t v292[256];	// L535
            #pragma HLS bind_storage variable=v292 type=ram_2p impl=bram

            for (int v293 = 0; v293 < 256; v293 += 1) {	// L536
              v292[v293] = (int8_t)0.000000;	// L537
              for (int v294 = 0; v294 < 6; v294 += 1) {	// L538
                #pragma HLS pipeline II=1
                for (int v295 = 0; v295 < 16; v295 += 1) {	// L539
                  for (int v296 = 0; v296 < 5; v296 += 1) {	// L540
                    for (int v297 = 0; v297 < 5; v297 += 1) {	// L541
                      int8_t v298 = v275[v276][(v295 + (v294 * 16))][v296][v297];	// L542
                      int8_t v299 = v262[v293][(v295 + (v294 * 16))][v296][v297];	// L543
                      int8_t v300 = v298 * v299;	// L544
                      int8_t v301 = v292[v293];	// L545
                      int8_t v302 = v301 + v300;	// L546
                      v292[v293] = v302;	// L547
                    }
                  }
                }
              }
              int8_t v303 = v292[v293];	// L552
              v273[v276][v293][(v277 - 30)][(v278 - 30)] = v303;	// L553
            }
          }
        }
      }
    }
  }
  for (int v304 = 0; v304 < 1; v304 += 1) {	// L560
    for (int v305 = 0; v305 < 26; v305 += 1) {	// L561
      for (int v306 = 0; v306 < 26; v306 += 1) {	// L562
        for (int v307 = 0; v307 < 256; v307 += 1) {	// L563
          int8_t v308 = v273[0][v307][v305][v306];	// L564
          bool v309 = v308 > (int8_t)0.000000;	// L565
          int8_t v310 = v309 ? v308 : (int8_t)0.000000;	// L566
          v264[v304][v307][v305][v306] = v310;	// L567
        }
      }
    }
  }
  return ;	// L572
}

void main_graph_node11(
  int8_t v311[1][96][110][110],
  int8_t v312[1][96][54][54]
) {	// L574
  #pragma HLS dataflow

  int8_t v313;	// L577
  v313 = (int8_t)-INFINITY;	// L578
  int8_t v314[1][96][110][110];	// L579
  #pragma HLS array_partition variable=v314 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v314 type=ram_2p impl=bram

  for (int v315 = 0; v315 < 1; v315 += 1) {	// L580
    for (int v316 = 0; v316 < 110; v316 += 1) {	// L581
      for (int v317 = 0; v317 < 110; v317 += 1) {	// L582
        for (int v318 = 0; v318 < 48; v318 += 1) {	// L583
          #pragma HLS pipeline II=1
          for (int v319 = 0; v319 < 2; v319 += 1) {	// L584
            int8_t v320 = v311[v315][(v319 + (v318 * 2))][v316][v317];	// L585
            v314[v315][(v319 + (v318 * 2))][v316][v317] = v320;	// L586
          }
        }
      }
    }
  }
  for (int v321 = 0; v321 < 1; v321 += 1) {	// L592
    for (int v322 = 0; v322 < 54; v322 += 1) {	// L593
      for (int v323 = 0; v323 < 54; v323 += 1) {	// L594
        for (int v324 = 0; v324 < 96; v324 += 1) {	// L595
          int8_t v325;	// L596
          v325 = (int8_t)0.000000;	// L597
          for (int v326 = 0; v326 < 3; v326 += 1) {	// L598
            for (int v327 = 0; v327 < 3; v327 += 1) {	// L599
              int8_t v328 = v314[v321][v324][((v322 * 2) + v326)][((v323 * 2) + v327)];	// L600
              int8_t v329 = v313;	// L601
              int8_t v330 = max(v329, v328);	// L602
              v325 = v330;	// L603
            }
          }
          int8_t v331 = v325;	// L606
          v312[v321][v324][v322][v323] = v331;	// L607
        }
      }
    }
  }
  return ;	// L612
}

void main_graph_node12(
  int8_t v332[96][3][7][7],
  int8_t v333[1][3][224][224],
  int8_t v334[1][96][110][110]
) {	// L614
  #pragma HLS dataflow

  int8_t v335[1][3][226][226];	// L616
  #pragma HLS stream variable=v335 depth=10 type=fifo

  #pragma HLS bind_storage variable=v335 type=ram_t2p impl=bram

  for (int v336 = 0; v336 < 1; v336 += 1) {	// L617
    for (int v337 = 0; v337 < 226; v337 += 1) {	// L618
      for (int v338 = 0; v338 < 226; v338 += 1) {	// L619
        for (int v339 = 0; v339 < 3; v339 += 1) {	// L620
          int8_t v340;	// L621
          v340 = (int8_t)0.000000;	// L622
          if (((-v337) + 223) >= 0 && ((-v338) + 223) >= 0) {	// L623
            int8_t v341 = v333[v336][v339][v337][v338];	// L624
            v340 = v341;	// L625
          }
          int8_t v342 = v340;	// L627
          v335[v336][v339][v337][v338] = v342;	// L628
        }
      }
    }
  }
  int8_t v343[1][96][110][110];	// L633
  #pragma HLS stream variable=v343 depth=10 type=fifo

  #pragma HLS array_partition variable=v343 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v343 type=ram_t2p impl=bram

  int8_t v344[1][3][7][226];	// L634
  #pragma HLS array_partition variable=v344 cyclic factor=7 dim=3
  #pragma HLS bind_storage variable=v344 type=ram_2p impl=lutram

  int8_t v345[1][3][7][7];	// L635
  #pragma HLS array_partition variable=v345 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v345 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v345 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v345 type=ram_2p impl=lutram

  for (int v346 = 0; v346 < 1; v346 += 1) {	// L636
    for (int v347 = 0; v347 < 226; v347 += 1) {	// L637
      for (int v348 = 0; v348 < 226; v348 += 1) {	// L638
        for (int v349 = 0; v349 < 3; v349 += 1) {	// L639
          int8_t v350 = v344[v346][v349][1][v348];	// L640
          v344[v346][v349][0][v348] = v350;	// L641
          int8_t v351 = v344[v346][v349][2][v348];	// L642
          v344[v346][v349][1][v348] = v351;	// L643
          int8_t v352 = v344[v346][v349][3][v348];	// L644
          v344[v346][v349][2][v348] = v352;	// L645
          int8_t v353 = v344[v346][v349][4][v348];	// L646
          v344[v346][v349][3][v348] = v353;	// L647
          int8_t v354 = v344[v346][v349][5][v348];	// L648
          v344[v346][v349][4][v348] = v354;	// L649
          int8_t v355 = v344[v346][v349][6][v348];	// L650
          v344[v346][v349][5][v348] = v355;	// L651
          int8_t v356 = v335[v346][v349][v347][v348];	// L652
          v344[v346][v349][6][v348] = v356;	// L653
        }
        if ((v347 - 116) >= 0) {	// L655
          for (int v357 = 0; v357 < 3; v357 += 1) {	// L656
            for (int v358 = 0; v358 < 7; v358 += 1) {	// L657
              int8_t v359 = v345[v346][v357][v358][1];	// L658
              v345[v346][v357][v358][0] = v359;	// L659
              int8_t v360 = v345[v346][v357][v358][2];	// L660
              v345[v346][v357][v358][1] = v360;	// L661
              int8_t v361 = v345[v346][v357][v358][3];	// L662
              v345[v346][v357][v358][2] = v361;	// L663
              int8_t v362 = v345[v346][v357][v358][4];	// L664
              v345[v346][v357][v358][3] = v362;	// L665
              int8_t v363 = v345[v346][v357][v358][5];	// L666
              v345[v346][v357][v358][4] = v363;	// L667
              int8_t v364 = v345[v346][v357][v358][6];	// L668
              v345[v346][v357][v358][5] = v364;	// L669
              int8_t v365 = v344[v346][v357][v358][v348];	// L670
              v345[v346][v357][v358][6] = v365;	// L671
            }
          }
          if ((v348 - 116) >= 0) {	// L674
            int8_t v366[96];	// L675
            #pragma HLS array_partition variable=v366 cyclic factor=2 dim=1
            #pragma HLS bind_storage variable=v366 type=ram_2p impl=lutram

            for (int v367 = 0; v367 < 48; v367 += 1) {	// L676
              #pragma HLS pipeline II=1
              for (int v368 = 0; v368 < 2; v368 += 1) {	// L677
                v366[(v368 + (v367 * 2))] = (int8_t)0.000000;	// L678
                for (int v369 = 0; v369 < 3; v369 += 1) {	// L679
                  for (int v370 = 0; v370 < 7; v370 += 1) {	// L680
                    for (int v371 = 0; v371 < 7; v371 += 1) {	// L681
                      int8_t v372 = v345[v346][v369][v370][v371];	// L682
                      int8_t v373 = v332[(v368 + (v367 * 2))][v369][v370][v371];	// L683
                      int8_t v374 = v372 * v373;	// L684
                      int8_t v375 = v366[(v368 + (v367 * 2))];	// L685
                      int8_t v376 = v375 + v374;	// L686
                      v366[(v368 + (v367 * 2))] = v376;	// L687
                    }
                  }
                }
                int8_t v377 = v366[(v368 + (v367 * 2))];	// L691
                v343[v346][(v368 + (v367 * 2))][(v347 - 116)][(v348 - 116)] = v377;	// L692
              }
            }
          }
        }
      }
    }
  }
  for (int v378 = 0; v378 < 1; v378 += 1) {	// L700
    for (int v379 = 0; v379 < 110; v379 += 1) {	// L701
      for (int v380 = 0; v380 < 110; v380 += 1) {	// L702
        for (int v381 = 0; v381 < 48; v381 += 1) {	// L703
          #pragma HLS pipeline II=1
          for (int v382 = 0; v382 < 2; v382 += 1) {	// L704
            int8_t v383 = v343[0][(v382 + (v381 * 2))][v379][v380];	// L705
            bool v384 = v383 > (int8_t)0.000000;	// L706
            int8_t v385 = v384 ? v383 : (int8_t)0.000000;	// L707
            v334[v378][(v382 + (v381 * 2))][v379][v380] = v385;	// L708
          }
        }
      }
    }
  }
  return ;	// L714
}

/// This is top function.
void main_graph(
  int8_t v386[1][3][224][224],
  int8_t v387[1000],
  int8_t v388[4096],
  int8_t v389[4096][256][5][5],
  int8_t v390[256][384][3][3],
  int8_t v391[384][384][3][3],
  int8_t v392[384][256][3][3],
  int8_t v393[256][96][5][5],
  int8_t v394[96][3][7][7],
  int8_t v395[4096][4096],
  int8_t v396[4096][1000],
  int8_t v397[1][1000]
) {	// L716
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v386 bundle=gmem1
  #pragma HLS bind_storage variable=v386 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v387 bundle=gmem2
  #pragma HLS bind_storage variable=v387 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v388 bundle=gmem3
  #pragma HLS bind_storage variable=v388 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v389 bundle=gmem4
  #pragma HLS array_partition variable=v389 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v389 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v389 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v389 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v390 bundle=gmem5
  #pragma HLS array_partition variable=v390 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v390 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v390 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v390 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v391 bundle=gmem6
  #pragma HLS array_partition variable=v391 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v391 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v391 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v391 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v392 bundle=gmem7
  #pragma HLS array_partition variable=v392 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v392 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v392 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v392 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v393 bundle=gmem8
  #pragma HLS array_partition variable=v393 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v393 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v393 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v393 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v394 bundle=gmem9
  #pragma HLS array_partition variable=v394 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v394 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v394 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v394 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v394 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v395 bundle=gmem10
  #pragma HLS bind_storage variable=v395 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v396 bundle=gmem11
  #pragma HLS bind_storage variable=v396 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v397 bundle=gmem12
  #pragma HLS bind_storage variable=v397 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v398[1][96][110][110];	// L718
  #pragma HLS stream variable=v398 depth=10 type=fifo

  #pragma HLS array_partition variable=v398 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v398 type=ram_t2p impl=bram

  main_graph_node12(v394, v386, v398);	// L719
  int8_t v399[1][96][54][54];	// L720
  #pragma HLS stream variable=v399 depth=10 type=fifo

  #pragma HLS bind_storage variable=v399 type=ram_t2p impl=bram

  main_graph_node11(v398, v399);	// L721
  int8_t v400[1][256][26][26];	// L722
  #pragma HLS stream variable=v400 depth=10 type=fifo

  #pragma HLS bind_storage variable=v400 type=ram_t2p impl=bram

  main_graph_node10(v393, v399, v400);	// L723
  int8_t v401[1][256][12][12];	// L724
  #pragma HLS stream variable=v401 depth=10 type=fifo

  #pragma HLS bind_storage variable=v401 type=ram_t2p impl=bram

  main_graph_node9(v400, v401);	// L725
  int8_t v402[1][384][12][12];	// L726
  #pragma HLS stream variable=v402 depth=10 type=fifo

  #pragma HLS bind_storage variable=v402 type=ram_t2p impl=bram

  main_graph_node8(v401, v392, v402);	// L727
  int8_t v403[1][384][12][12];	// L728
  #pragma HLS stream variable=v403 depth=10 type=fifo

  #pragma HLS bind_storage variable=v403 type=ram_t2p impl=bram

  main_graph_node7(v402, v391, v403);	// L729
  int8_t v404[1][256][12][12];	// L730
  #pragma HLS stream variable=v404 depth=10 type=fifo

  #pragma HLS bind_storage variable=v404 type=ram_t2p impl=bram

  main_graph_node6(v390, v403, v404);	// L731
  int8_t v405[1][256][5][5];	// L732
  #pragma HLS stream variable=v405 depth=10 type=fifo

  #pragma HLS bind_storage variable=v405 type=ram_t2p impl=bram

  main_graph_node5(v404, v405);	// L733
  int8_t v406[1][4096][1][1];	// L734
  #pragma HLS bind_storage variable=v406 type=ram_t2p impl=bram

  main_graph_node4(v405, v389, v406);	// L735
  int8_t v407[1][4096];	// L736
  #pragma HLS bind_storage variable=v407 type=ram_t2p impl=bram

  main_graph_node3(v406, v395, v407);	// L737
  int8_t v408[1][4096];	// L738
  #pragma HLS bind_storage variable=v408 type=ram_t2p impl=bram

  main_graph_node2(v407, v388, v408);	// L739
  int8_t v409[1][1000];	// L740
  #pragma HLS bind_storage variable=v409 type=ram_t2p impl=bram

  main_graph_node1(v408, v396, v409);	// L741
  main_graph_node0(v409, v387, v397);	// L742
  return ;	// L743
}

