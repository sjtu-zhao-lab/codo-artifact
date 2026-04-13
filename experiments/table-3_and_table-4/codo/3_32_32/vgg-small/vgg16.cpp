
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
  int8_t v0[1][10],
  int8_t v1[10],
  int8_t v2[1][10]
) {	// L15
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L16
    for (int v4 = 0; v4 < 10; v4 += 1) {	// L17
      int8_t v5 = v0[0][v4];	// L18
      int8_t v6 = v1[v4];	// L19
      int8_t v7 = v5 + v6;	// L20
      v2[v3][v4] = v7;	// L21
    }
  }
  return ;	// L24
}

void main_graph_node1(
  int8_t v8[1][512][1][1],
  int8_t v9[512][10],
  int8_t v10[1][10]
) {	// L26
  #pragma HLS dataflow

  int8_t v11[1][10];	// L28
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L29
    for (int v13 = 0; v13 < 10; v13 += 1) {	// L30
      v11[v12][v13] = (int8_t)0.000000;	// L31
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L34
    for (int v15 = 0; v15 < 10; v15 += 1) {	// L35
      for (int v16 = 0; v16 < 512; v16 += 1) {	// L36
        int8_t v17 = v8[v14][v16][0][0];	// L37
        int8_t v18 = v9[v16][v15];	// L38
        int8_t v19 = v11[v14][v15];	// L39
        int8_t v20 = v17 * v18;	// L40
        int8_t v21 = v19 + v20;	// L41
        v10[v14][v15] = v21;	// L42
      }
    }
  }
  return ;	// L46
}

void main_graph_node2(
  int8_t v22[1][512][1][1],
  int8_t v23[1][1],
  int8_t v24[1][512][1][1]
) {	// L48
  #pragma HLS dataflow

  int8_t v25[1][512][1][1];	// L49
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  for (int v26 = 0; v26 < 1; v26 += 1) {	// L50
    for (int v27 = 0; v27 < 512; v27 += 1) {	// L51
      for (int v28 = 0; v28 < 1; v28 += 1) {	// L52
        for (int v29 = 0; v29 < 1; v29 += 1) {	// L53
          int8_t v30 = v22[v26][v27][v28][v29];	// L54
          v25[v26][v27][v28][v29] = v30;	// L55
          int8_t v31 = v23[v28][v29];	// L56
          int8_t v32 = v25[v26][v27][v28][v29];	// L57
          int8_t v33 = v32 / v31;	// L58
          v24[v26][v27][v28][v29] = v33;	// L59
        }
      }
    }
  }
  return ;	// L64
}

void main_graph_node3(
  int8_t v34[1][512][2][2],
  int8_t v35[1][1],
  int8_t v36[1][512][1][1]
) {	// L66
  #pragma HLS dataflow

  int8_t v37[1][512][1][1];	// L70
  #pragma HLS bind_storage variable=v37 type=ram_t2p impl=bram

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L71
    for (int v39 = 0; v39 < 512; v39 += 1) {	// L72
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L73
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L74
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L75
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L80
    for (int v43 = 0; v43 < 512; v43 += 1) {	// L81
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L82
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L83
          for (int v46 = 0; v46 < 1; v46 += 1) {	// L84
            for (int v47 = 0; v47 < 1; v47 += 1) {	// L85
              int8_t v48 = v37[v42][v43][v44][v45];	// L86
              int v49 = v44 + (int)1;	// L87
              int v50 = v45 + (int)1;	// L88
              int v51 = v44 + v46;	// L89
              int v52 = v45 + v47;	// L90
              int8_t v53 = v34[v42][v43][v51][v52];	// L91
              bool v54 = v51 < v49;	// L92
              int8_t v55 = v54 ? v53 : (int8_t)0.000000;	// L93
              bool v56 = v52 < v50;	// L94
              int8_t v57 = v56 ? v55 : (int8_t)0.000000;	// L95
              int8_t v58 = v57 + v48;	// L96
              v36[v42][v43][v44][v45] = v58;	// L97
              v35[v42][v43] = (int8_t)1.000000;	// L98
            }
          }
        }
      }
    }
  }
  return ;	// L105
}

void main_graph_node4(
  int8_t v59[1][512][1][1],
  int8_t v60[1][512][2][2]
) {	// L107
  #pragma HLS dataflow

  for (int v61 = 0; v61 < 1; v61 += 1) {	// L109
    for (int v62 = 0; v62 < 2; v62 += 1) {	// L110
      for (int v63 = 0; v63 < 2; v63 += 1) {	// L111
        for (int v64 = 0; v64 < 512; v64 += 1) {	// L112
          int8_t v65;	// L113
          v65 = (int8_t)0.000000;	// L114
          if ((-v62) >= 0 && (-v63) >= 0) {	// L115
            int8_t v66 = v59[v61][v64][v62][v63];	// L116
            v65 = v66;	// L117
          }
          int8_t v67 = v65;	// L119
          v60[v61][v64][v62][v63] = v67;	// L120
        }
      }
    }
  }
  return ;	// L125
}

void main_graph_node5(
  int8_t v68[1][512][2][2],
  int8_t v69[512][512][3][3],
  int8_t v70[1][512][1][1]
) {	// L127
  #pragma HLS dataflow

  int8_t v71[1][512][4][4];	// L129
  #pragma HLS stream variable=v71 depth=10 type=fifo

  #pragma HLS bind_storage variable=v71 type=ram_t2p impl=bram

  for (int v72 = 0; v72 < 1; v72 += 1) {	// L130
    for (int v73 = 0; v73 < 4; v73 += 1) {	// L131
      for (int v74 = 0; v74 < 4; v74 += 1) {	// L132
        for (int v75 = 0; v75 < 512; v75 += 1) {	// L133
          int8_t v76;	// L134
          v76 = (int8_t)0.000000;	// L135
          if (((-v73) + 1) >= 0 && ((-v74) + 1) >= 0) {	// L136
            int8_t v77 = v68[v72][v75][v73][v74];	// L137
            v76 = v77;	// L138
          }
          int8_t v78 = v76;	// L140
          v71[v72][v75][v73][v74] = v78;	// L141
        }
      }
    }
  }
  int8_t v79[1][512][1][1];	// L146
  #pragma HLS stream variable=v79 depth=10 type=fifo

  #pragma HLS bind_storage variable=v79 type=ram_t2p impl=bram

  int8_t v80[1][512][3][4];	// L147
  #pragma HLS array_partition variable=v80 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v80 type=ram_2p impl=bram

  int8_t v81[1][512][3][3];	// L148
  #pragma HLS array_partition variable=v81 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v81 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v81 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v81 type=ram_2p impl=lutram

  for (int v82 = 0; v82 < 1; v82 += 1) {	// L149
    for (int v83 = 0; v83 < 4; v83 += 1) {	// L150
      for (int v84 = 0; v84 < 4; v84 += 1) {	// L151
        for (int v85 = 0; v85 < 512; v85 += 1) {	// L152
          int8_t v86 = v80[v82][v85][1][v84];	// L153
          v80[v82][v85][0][v84] = v86;	// L154
          int8_t v87 = v80[v82][v85][2][v84];	// L155
          v80[v82][v85][1][v84] = v87;	// L156
          int8_t v88 = v71[v82][v85][v83][v84];	// L157
          v80[v82][v85][2][v84] = v88;	// L158
        }
        if ((v83 - 3) >= 0) {	// L160
          for (int v89 = 0; v89 < 512; v89 += 1) {	// L161
            for (int v90 = 0; v90 < 3; v90 += 1) {	// L162
              int8_t v91 = v81[v82][v89][v90][1];	// L163
              v81[v82][v89][v90][0] = v91;	// L164
              int8_t v92 = v81[v82][v89][v90][2];	// L165
              v81[v82][v89][v90][1] = v92;	// L166
              int8_t v93 = v80[v82][v89][v90][v84];	// L167
              v81[v82][v89][v90][2] = v93;	// L168
            }
          }
          if ((v84 - 3) >= 0) {	// L171
            int8_t v94[512];	// L172
            #pragma HLS bind_storage variable=v94 type=ram_2p impl=bram

            for (int v95 = 0; v95 < 512; v95 += 1) {	// L173
              v94[v95] = (int8_t)0.000000;	// L174
              for (int v96 = 0; v96 < 128; v96 += 1) {	// L175
                #pragma HLS pipeline II=1
                for (int v97 = 0; v97 < 4; v97 += 1) {	// L176
                  for (int v98 = 0; v98 < 3; v98 += 1) {	// L177
                    for (int v99 = 0; v99 < 3; v99 += 1) {	// L178
                      int8_t v100 = v81[v82][(v97 + (v96 * 4))][v98][v99];	// L179
                      int8_t v101 = v69[v95][(v97 + (v96 * 4))][v98][v99];	// L180
                      int8_t v102 = v100 * v101;	// L181
                      int8_t v103 = v94[v95];	// L182
                      int8_t v104 = v103 + v102;	// L183
                      v94[v95] = v104;	// L184
                    }
                  }
                }
              }
              int8_t v105 = v94[v95];	// L189
              v79[v82][v95][(v83 - 3)][(v84 - 3)] = v105;	// L190
            }
          }
        }
      }
    }
  }
  for (int v106 = 0; v106 < 1; v106 += 1) {	// L197
    for (int v107 = 0; v107 < 1; v107 += 1) {	// L198
      for (int v108 = 0; v108 < 1; v108 += 1) {	// L199
        for (int v109 = 0; v109 < 512; v109 += 1) {	// L200
          int8_t v110 = v79[0][v109][0][0];	// L201
          bool v111 = v110 > (int8_t)0.000000;	// L202
          int8_t v112 = v111 ? v110 : (int8_t)0.000000;	// L203
          v70[v106][v109][v107][v108] = v112;	// L204
        }
      }
    }
  }
  return ;	// L209
}

void main_graph_node6(
  int8_t v113[1][512][2][2],
  int8_t v114[512][512][3][3],
  int8_t v115[1][512][2][2]
) {	// L211
  #pragma HLS dataflow

  int8_t v116[1][512][4][4];	// L213
  #pragma HLS stream variable=v116 depth=10 type=fifo

  #pragma HLS bind_storage variable=v116 type=ram_t2p impl=bram

  for (int v117 = 0; v117 < 1; v117 += 1) {	// L214
    for (int v118 = 0; v118 < 4; v118 += 1) {	// L215
      for (int v119 = 0; v119 < 4; v119 += 1) {	// L216
        for (int v120 = 0; v120 < 512; v120 += 1) {	// L217
          int8_t v121;	// L218
          v121 = (int8_t)0.000000;	// L219
          if (((-v118) + 1) >= 0 && ((-v119) + 1) >= 0) {	// L220
            int8_t v122 = v113[v117][v120][v118][v119];	// L221
            v121 = v122;	// L222
          }
          int8_t v123 = v121;	// L224
          v116[v117][v120][v118][v119] = v123;	// L225
        }
      }
    }
  }
  int8_t v124[1][512][2][2];	// L230
  #pragma HLS stream variable=v124 depth=10 type=fifo

  #pragma HLS bind_storage variable=v124 type=ram_t2p impl=bram

  int8_t v125[1][512][3][4];	// L231
  #pragma HLS array_partition variable=v125 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v125 type=ram_2p impl=bram

  int8_t v126[1][512][3][3];	// L232
  #pragma HLS array_partition variable=v126 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v126 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v126 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v126 type=ram_2p impl=lutram

  for (int v127 = 0; v127 < 1; v127 += 1) {	// L233
    for (int v128 = 0; v128 < 4; v128 += 1) {	// L234
      for (int v129 = 0; v129 < 4; v129 += 1) {	// L235
        for (int v130 = 0; v130 < 512; v130 += 1) {	// L236
          int8_t v131 = v125[v127][v130][1][v129];	// L237
          v125[v127][v130][0][v129] = v131;	// L238
          int8_t v132 = v125[v127][v130][2][v129];	// L239
          v125[v127][v130][1][v129] = v132;	// L240
          int8_t v133 = v116[v127][v130][v128][v129];	// L241
          v125[v127][v130][2][v129] = v133;	// L242
        }
        if ((v128 - 2) >= 0) {	// L244
          for (int v134 = 0; v134 < 512; v134 += 1) {	// L245
            for (int v135 = 0; v135 < 3; v135 += 1) {	// L246
              int8_t v136 = v126[v127][v134][v135][1];	// L247
              v126[v127][v134][v135][0] = v136;	// L248
              int8_t v137 = v126[v127][v134][v135][2];	// L249
              v126[v127][v134][v135][1] = v137;	// L250
              int8_t v138 = v125[v127][v134][v135][v129];	// L251
              v126[v127][v134][v135][2] = v138;	// L252
            }
          }
          if ((v129 - 2) >= 0) {	// L255
            int8_t v139[512];	// L256
            #pragma HLS bind_storage variable=v139 type=ram_2p impl=bram

            for (int v140 = 0; v140 < 512; v140 += 1) {	// L257
              v139[v140] = (int8_t)0.000000;	// L258
              for (int v141 = 0; v141 < 128; v141 += 1) {	// L259
                #pragma HLS pipeline II=1
                for (int v142 = 0; v142 < 4; v142 += 1) {	// L260
                  for (int v143 = 0; v143 < 3; v143 += 1) {	// L261
                    for (int v144 = 0; v144 < 3; v144 += 1) {	// L262
                      int8_t v145 = v126[v127][(v142 + (v141 * 4))][v143][v144];	// L263
                      int8_t v146 = v114[v140][(v142 + (v141 * 4))][v143][v144];	// L264
                      int8_t v147 = v145 * v146;	// L265
                      int8_t v148 = v139[v140];	// L266
                      int8_t v149 = v148 + v147;	// L267
                      v139[v140] = v149;	// L268
                    }
                  }
                }
              }
              int8_t v150 = v139[v140];	// L273
              v124[v127][v140][(v128 - 2)][(v129 - 2)] = v150;	// L274
            }
          }
        }
      }
    }
  }
  for (int v151 = 0; v151 < 1; v151 += 1) {	// L281
    for (int v152 = 0; v152 < 2; v152 += 1) {	// L282
      for (int v153 = 0; v153 < 2; v153 += 1) {	// L283
        for (int v154 = 0; v154 < 512; v154 += 1) {	// L284
          int8_t v155 = v124[0][v154][v152][v153];	// L285
          bool v156 = v155 > (int8_t)0.000000;	// L286
          int8_t v157 = v156 ? v155 : (int8_t)0.000000;	// L287
          v115[v151][v154][v152][v153] = v157;	// L288
        }
      }
    }
  }
  return ;	// L293
}

void main_graph_node7(
  int8_t v158[1][512][2][2],
  int8_t v159[512][512][3][3],
  int8_t v160[1][512][2][2]
) {	// L295
  #pragma HLS dataflow

  int8_t v161[1][512][4][4];	// L297
  #pragma HLS stream variable=v161 depth=10 type=fifo

  #pragma HLS bind_storage variable=v161 type=ram_t2p impl=bram

  for (int v162 = 0; v162 < 1; v162 += 1) {	// L298
    for (int v163 = 0; v163 < 4; v163 += 1) {	// L299
      for (int v164 = 0; v164 < 4; v164 += 1) {	// L300
        for (int v165 = 0; v165 < 512; v165 += 1) {	// L301
          int8_t v166;	// L302
          v166 = (int8_t)0.000000;	// L303
          if (((-v163) + 1) >= 0 && ((-v164) + 1) >= 0) {	// L304
            int8_t v167 = v158[v162][v165][v163][v164];	// L305
            v166 = v167;	// L306
          }
          int8_t v168 = v166;	// L308
          v161[v162][v165][v163][v164] = v168;	// L309
        }
      }
    }
  }
  int8_t v169[1][512][2][2];	// L314
  #pragma HLS stream variable=v169 depth=10 type=fifo

  #pragma HLS bind_storage variable=v169 type=ram_t2p impl=bram

  int8_t v170[1][512][3][4];	// L315
  #pragma HLS array_partition variable=v170 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v170 type=ram_2p impl=bram

  int8_t v171[1][512][3][3];	// L316
  #pragma HLS array_partition variable=v171 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v171 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v171 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v171 type=ram_2p impl=lutram

  for (int v172 = 0; v172 < 1; v172 += 1) {	// L317
    for (int v173 = 0; v173 < 4; v173 += 1) {	// L318
      for (int v174 = 0; v174 < 4; v174 += 1) {	// L319
        for (int v175 = 0; v175 < 512; v175 += 1) {	// L320
          int8_t v176 = v170[v172][v175][1][v174];	// L321
          v170[v172][v175][0][v174] = v176;	// L322
          int8_t v177 = v170[v172][v175][2][v174];	// L323
          v170[v172][v175][1][v174] = v177;	// L324
          int8_t v178 = v161[v172][v175][v173][v174];	// L325
          v170[v172][v175][2][v174] = v178;	// L326
        }
        if ((v173 - 2) >= 0) {	// L328
          for (int v179 = 0; v179 < 512; v179 += 1) {	// L329
            for (int v180 = 0; v180 < 3; v180 += 1) {	// L330
              int8_t v181 = v171[v172][v179][v180][1];	// L331
              v171[v172][v179][v180][0] = v181;	// L332
              int8_t v182 = v171[v172][v179][v180][2];	// L333
              v171[v172][v179][v180][1] = v182;	// L334
              int8_t v183 = v170[v172][v179][v180][v174];	// L335
              v171[v172][v179][v180][2] = v183;	// L336
            }
          }
          if ((v174 - 2) >= 0) {	// L339
            int8_t v184[512];	// L340
            #pragma HLS bind_storage variable=v184 type=ram_2p impl=bram

            for (int v185 = 0; v185 < 512; v185 += 1) {	// L341
              v184[v185] = (int8_t)0.000000;	// L342
              for (int v186 = 0; v186 < 128; v186 += 1) {	// L343
                #pragma HLS pipeline II=1
                for (int v187 = 0; v187 < 4; v187 += 1) {	// L344
                  for (int v188 = 0; v188 < 3; v188 += 1) {	// L345
                    for (int v189 = 0; v189 < 3; v189 += 1) {	// L346
                      int8_t v190 = v171[v172][(v187 + (v186 * 4))][v188][v189];	// L347
                      int8_t v191 = v159[v185][(v187 + (v186 * 4))][v188][v189];	// L348
                      int8_t v192 = v190 * v191;	// L349
                      int8_t v193 = v184[v185];	// L350
                      int8_t v194 = v193 + v192;	// L351
                      v184[v185] = v194;	// L352
                    }
                  }
                }
              }
              int8_t v195 = v184[v185];	// L357
              v169[v172][v185][(v173 - 2)][(v174 - 2)] = v195;	// L358
            }
          }
        }
      }
    }
  }
  for (int v196 = 0; v196 < 1; v196 += 1) {	// L365
    for (int v197 = 0; v197 < 2; v197 += 1) {	// L366
      for (int v198 = 0; v198 < 2; v198 += 1) {	// L367
        for (int v199 = 0; v199 < 512; v199 += 1) {	// L368
          int8_t v200 = v169[0][v199][v197][v198];	// L369
          bool v201 = v200 > (int8_t)0.000000;	// L370
          int8_t v202 = v201 ? v200 : (int8_t)0.000000;	// L371
          v160[v196][v199][v197][v198] = v202;	// L372
        }
      }
    }
  }
  return ;	// L377
}

void main_graph_node8(
  int8_t v203[512][512][3][3],
  int8_t v204[1][512][4][4],
  int8_t v205[1][512][2][2]
) {	// L379
  #pragma HLS dataflow

  int8_t v206[1][512][6][6];	// L381
  #pragma HLS stream variable=v206 depth=10 type=fifo

  #pragma HLS bind_storage variable=v206 type=ram_t2p impl=bram

  for (int v207 = 0; v207 < 1; v207 += 1) {	// L382
    for (int v208 = 0; v208 < 6; v208 += 1) {	// L383
      for (int v209 = 0; v209 < 6; v209 += 1) {	// L384
        for (int v210 = 0; v210 < 512; v210 += 1) {	// L385
          int8_t v211;	// L386
          v211 = (int8_t)0.000000;	// L387
          if (((-v208) + 3) >= 0 && ((-v209) + 3) >= 0) {	// L388
            int8_t v212 = v204[v207][v210][v208][v209];	// L389
            v211 = v212;	// L390
          }
          int8_t v213 = v211;	// L392
          v206[v207][v210][v208][v209] = v213;	// L393
        }
      }
    }
  }
  int8_t v214[1][512][2][2];	// L398
  #pragma HLS stream variable=v214 depth=10 type=fifo

  #pragma HLS bind_storage variable=v214 type=ram_t2p impl=bram

  int8_t v215[1][512][3][6];	// L399
  #pragma HLS array_partition variable=v215 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v215 type=ram_2p impl=bram

  int8_t v216[1][512][3][3];	// L400
  #pragma HLS array_partition variable=v216 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v216 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v216 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v216 type=ram_2p impl=lutram

  for (int v217 = 0; v217 < 1; v217 += 1) {	// L401
    for (int v218 = 0; v218 < 6; v218 += 1) {	// L402
      for (int v219 = 0; v219 < 6; v219 += 1) {	// L403
        for (int v220 = 0; v220 < 512; v220 += 1) {	// L404
          int8_t v221 = v215[v217][v220][1][v219];	// L405
          v215[v217][v220][0][v219] = v221;	// L406
          int8_t v222 = v215[v217][v220][2][v219];	// L407
          v215[v217][v220][1][v219] = v222;	// L408
          int8_t v223 = v206[v217][v220][v218][v219];	// L409
          v215[v217][v220][2][v219] = v223;	// L410
        }
        if ((v218 - 4) >= 0) {	// L412
          for (int v224 = 0; v224 < 512; v224 += 1) {	// L413
            for (int v225 = 0; v225 < 3; v225 += 1) {	// L414
              int8_t v226 = v216[v217][v224][v225][1];	// L415
              v216[v217][v224][v225][0] = v226;	// L416
              int8_t v227 = v216[v217][v224][v225][2];	// L417
              v216[v217][v224][v225][1] = v227;	// L418
              int8_t v228 = v215[v217][v224][v225][v219];	// L419
              v216[v217][v224][v225][2] = v228;	// L420
            }
          }
          if ((v219 - 4) >= 0) {	// L423
            int8_t v229[512];	// L424
            #pragma HLS bind_storage variable=v229 type=ram_2p impl=bram

            for (int v230 = 0; v230 < 512; v230 += 1) {	// L425
              v229[v230] = (int8_t)0.000000;	// L426
              for (int v231 = 0; v231 < 64; v231 += 1) {	// L427
                #pragma HLS pipeline II=1
                for (int v232 = 0; v232 < 8; v232 += 1) {	// L428
                  for (int v233 = 0; v233 < 3; v233 += 1) {	// L429
                    for (int v234 = 0; v234 < 3; v234 += 1) {	// L430
                      int8_t v235 = v216[v217][(v232 + (v231 * 8))][v233][v234];	// L431
                      int8_t v236 = v203[v230][(v232 + (v231 * 8))][v233][v234];	// L432
                      int8_t v237 = v235 * v236;	// L433
                      int8_t v238 = v229[v230];	// L434
                      int8_t v239 = v238 + v237;	// L435
                      v229[v230] = v239;	// L436
                    }
                  }
                }
              }
              int8_t v240 = v229[v230];	// L441
              v214[v217][v230][(v218 - 4)][(v219 - 4)] = v240;	// L442
            }
          }
        }
      }
    }
  }
  for (int v241 = 0; v241 < 1; v241 += 1) {	// L449
    for (int v242 = 0; v242 < 2; v242 += 1) {	// L450
      for (int v243 = 0; v243 < 2; v243 += 1) {	// L451
        for (int v244 = 0; v244 < 512; v244 += 1) {	// L452
          int8_t v245 = v214[0][v244][v242][v243];	// L453
          bool v246 = v245 > (int8_t)0.000000;	// L454
          int8_t v247 = v246 ? v245 : (int8_t)0.000000;	// L455
          v205[v241][v244][v242][v243] = v247;	// L456
        }
      }
    }
  }
  return ;	// L461
}

void main_graph_node9(
  int8_t v248[512][512][3][3],
  int8_t v249[1][512][4][4],
  int8_t v250[1][512][4][4]
) {	// L463
  #pragma HLS dataflow

  int8_t v251[1][512][6][6];	// L465
  #pragma HLS stream variable=v251 depth=10 type=fifo

  #pragma HLS bind_storage variable=v251 type=ram_t2p impl=bram

  for (int v252 = 0; v252 < 1; v252 += 1) {	// L466
    for (int v253 = 0; v253 < 6; v253 += 1) {	// L467
      for (int v254 = 0; v254 < 6; v254 += 1) {	// L468
        for (int v255 = 0; v255 < 512; v255 += 1) {	// L469
          int8_t v256;	// L470
          v256 = (int8_t)0.000000;	// L471
          if (((-v253) + 3) >= 0 && ((-v254) + 3) >= 0) {	// L472
            int8_t v257 = v249[v252][v255][v253][v254];	// L473
            v256 = v257;	// L474
          }
          int8_t v258 = v256;	// L476
          v251[v252][v255][v253][v254] = v258;	// L477
        }
      }
    }
  }
  int8_t v259[1][512][4][4];	// L482
  #pragma HLS stream variable=v259 depth=10 type=fifo

  #pragma HLS bind_storage variable=v259 type=ram_t2p impl=bram

  int8_t v260[1][512][3][6];	// L483
  #pragma HLS array_partition variable=v260 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v260 type=ram_2p impl=bram

  int8_t v261[1][512][3][3];	// L484
  #pragma HLS array_partition variable=v261 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v261 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v261 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v261 type=ram_2p impl=lutram

  for (int v262 = 0; v262 < 1; v262 += 1) {	// L485
    for (int v263 = 0; v263 < 6; v263 += 1) {	// L486
      for (int v264 = 0; v264 < 6; v264 += 1) {	// L487
        for (int v265 = 0; v265 < 512; v265 += 1) {	// L488
          int8_t v266 = v260[v262][v265][1][v264];	// L489
          v260[v262][v265][0][v264] = v266;	// L490
          int8_t v267 = v260[v262][v265][2][v264];	// L491
          v260[v262][v265][1][v264] = v267;	// L492
          int8_t v268 = v251[v262][v265][v263][v264];	// L493
          v260[v262][v265][2][v264] = v268;	// L494
        }
        if ((v263 - 2) >= 0) {	// L496
          for (int v269 = 0; v269 < 512; v269 += 1) {	// L497
            for (int v270 = 0; v270 < 3; v270 += 1) {	// L498
              int8_t v271 = v261[v262][v269][v270][1];	// L499
              v261[v262][v269][v270][0] = v271;	// L500
              int8_t v272 = v261[v262][v269][v270][2];	// L501
              v261[v262][v269][v270][1] = v272;	// L502
              int8_t v273 = v260[v262][v269][v270][v264];	// L503
              v261[v262][v269][v270][2] = v273;	// L504
            }
          }
          if ((v264 - 2) >= 0) {	// L507
            int8_t v274[512];	// L508
            #pragma HLS bind_storage variable=v274 type=ram_2p impl=bram

            for (int v275 = 0; v275 < 512; v275 += 1) {	// L509
              v274[v275] = (int8_t)0.000000;	// L510
              for (int v276 = 0; v276 < 64; v276 += 1) {	// L511
                #pragma HLS pipeline II=1
                for (int v277 = 0; v277 < 8; v277 += 1) {	// L512
                  for (int v278 = 0; v278 < 3; v278 += 1) {	// L513
                    for (int v279 = 0; v279 < 3; v279 += 1) {	// L514
                      int8_t v280 = v261[v262][(v277 + (v276 * 8))][v278][v279];	// L515
                      int8_t v281 = v248[v275][(v277 + (v276 * 8))][v278][v279];	// L516
                      int8_t v282 = v280 * v281;	// L517
                      int8_t v283 = v274[v275];	// L518
                      int8_t v284 = v283 + v282;	// L519
                      v274[v275] = v284;	// L520
                    }
                  }
                }
              }
              int8_t v285 = v274[v275];	// L525
              v259[v262][v275][(v263 - 2)][(v264 - 2)] = v285;	// L526
            }
          }
        }
      }
    }
  }
  for (int v286 = 0; v286 < 1; v286 += 1) {	// L533
    for (int v287 = 0; v287 < 4; v287 += 1) {	// L534
      for (int v288 = 0; v288 < 4; v288 += 1) {	// L535
        for (int v289 = 0; v289 < 512; v289 += 1) {	// L536
          int8_t v290 = v259[0][v289][v287][v288];	// L537
          bool v291 = v290 > (int8_t)0.000000;	// L538
          int8_t v292 = v291 ? v290 : (int8_t)0.000000;	// L539
          v250[v286][v289][v287][v288] = v292;	// L540
        }
      }
    }
  }
  return ;	// L545
}

void main_graph_node10(
  int8_t v293[512][256][3][3],
  int8_t v294[1][256][4][4],
  int8_t v295[1][512][4][4]
) {	// L547
  #pragma HLS dataflow

  int8_t v296[1][256][6][6];	// L549
  #pragma HLS stream variable=v296 depth=10 type=fifo

  #pragma HLS bind_storage variable=v296 type=ram_t2p impl=bram

  for (int v297 = 0; v297 < 1; v297 += 1) {	// L550
    for (int v298 = 0; v298 < 6; v298 += 1) {	// L551
      for (int v299 = 0; v299 < 6; v299 += 1) {	// L552
        for (int v300 = 0; v300 < 256; v300 += 1) {	// L553
          int8_t v301;	// L554
          v301 = (int8_t)0.000000;	// L555
          if (((-v298) + 3) >= 0 && ((-v299) + 3) >= 0) {	// L556
            int8_t v302 = v294[v297][v300][v298][v299];	// L557
            v301 = v302;	// L558
          }
          int8_t v303 = v301;	// L560
          v296[v297][v300][v298][v299] = v303;	// L561
        }
      }
    }
  }
  int8_t v304[1][512][4][4];	// L566
  #pragma HLS stream variable=v304 depth=10 type=fifo

  #pragma HLS bind_storage variable=v304 type=ram_t2p impl=bram

  int8_t v305[1][256][3][6];	// L567
  #pragma HLS array_partition variable=v305 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v305 type=ram_2p impl=bram

  int8_t v306[1][256][3][3];	// L568
  #pragma HLS array_partition variable=v306 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v306 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v306 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v306 type=ram_2p impl=lutram

  for (int v307 = 0; v307 < 1; v307 += 1) {	// L569
    for (int v308 = 0; v308 < 6; v308 += 1) {	// L570
      for (int v309 = 0; v309 < 6; v309 += 1) {	// L571
        for (int v310 = 0; v310 < 256; v310 += 1) {	// L572
          int8_t v311 = v305[v307][v310][1][v309];	// L573
          v305[v307][v310][0][v309] = v311;	// L574
          int8_t v312 = v305[v307][v310][2][v309];	// L575
          v305[v307][v310][1][v309] = v312;	// L576
          int8_t v313 = v296[v307][v310][v308][v309];	// L577
          v305[v307][v310][2][v309] = v313;	// L578
        }
        if ((v308 - 2) >= 0) {	// L580
          for (int v314 = 0; v314 < 256; v314 += 1) {	// L581
            for (int v315 = 0; v315 < 3; v315 += 1) {	// L582
              int8_t v316 = v306[v307][v314][v315][1];	// L583
              v306[v307][v314][v315][0] = v316;	// L584
              int8_t v317 = v306[v307][v314][v315][2];	// L585
              v306[v307][v314][v315][1] = v317;	// L586
              int8_t v318 = v305[v307][v314][v315][v309];	// L587
              v306[v307][v314][v315][2] = v318;	// L588
            }
          }
          if ((v309 - 2) >= 0) {	// L591
            int8_t v319[512];	// L592
            #pragma HLS bind_storage variable=v319 type=ram_2p impl=bram

            for (int v320 = 0; v320 < 512; v320 += 1) {	// L593
              v319[v320] = (int8_t)0.000000;	// L594
              for (int v321 = 0; v321 < 64; v321 += 1) {	// L595
                #pragma HLS pipeline II=1
                for (int v322 = 0; v322 < 4; v322 += 1) {	// L596
                  for (int v323 = 0; v323 < 3; v323 += 1) {	// L597
                    for (int v324 = 0; v324 < 3; v324 += 1) {	// L598
                      int8_t v325 = v306[v307][(v322 + (v321 * 4))][v323][v324];	// L599
                      int8_t v326 = v293[v320][(v322 + (v321 * 4))][v323][v324];	// L600
                      int8_t v327 = v325 * v326;	// L601
                      int8_t v328 = v319[v320];	// L602
                      int8_t v329 = v328 + v327;	// L603
                      v319[v320] = v329;	// L604
                    }
                  }
                }
              }
              int8_t v330 = v319[v320];	// L609
              v304[v307][v320][(v308 - 2)][(v309 - 2)] = v330;	// L610
            }
          }
        }
      }
    }
  }
  for (int v331 = 0; v331 < 1; v331 += 1) {	// L617
    for (int v332 = 0; v332 < 4; v332 += 1) {	// L618
      for (int v333 = 0; v333 < 4; v333 += 1) {	// L619
        for (int v334 = 0; v334 < 512; v334 += 1) {	// L620
          int8_t v335 = v304[0][v334][v332][v333];	// L621
          bool v336 = v335 > (int8_t)0.000000;	// L622
          int8_t v337 = v336 ? v335 : (int8_t)0.000000;	// L623
          v295[v331][v334][v332][v333] = v337;	// L624
        }
      }
    }
  }
  return ;	// L629
}

void main_graph_node11(
  int8_t v338[1][256][8][8],
  int8_t v339[256][256][3][3],
  int8_t v340[1][256][4][4]
) {	// L631
  #pragma HLS dataflow

  int8_t v341[1][256][10][10];	// L633
  #pragma HLS stream variable=v341 depth=10 type=fifo

  #pragma HLS bind_storage variable=v341 type=ram_t2p impl=bram

  for (int v342 = 0; v342 < 1; v342 += 1) {	// L634
    for (int v343 = 0; v343 < 10; v343 += 1) {	// L635
      for (int v344 = 0; v344 < 10; v344 += 1) {	// L636
        for (int v345 = 0; v345 < 256; v345 += 1) {	// L637
          int8_t v346;	// L638
          v346 = (int8_t)0.000000;	// L639
          if (((-v343) + 7) >= 0 && ((-v344) + 7) >= 0) {	// L640
            int8_t v347 = v338[v342][v345][v343][v344];	// L641
            v346 = v347;	// L642
          }
          int8_t v348 = v346;	// L644
          v341[v342][v345][v343][v344] = v348;	// L645
        }
      }
    }
  }
  int8_t v349[1][256][4][4];	// L650
  #pragma HLS stream variable=v349 depth=10 type=fifo

  #pragma HLS bind_storage variable=v349 type=ram_t2p impl=bram

  int8_t v350[1][256][3][10];	// L651
  #pragma HLS array_partition variable=v350 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v350 type=ram_2p impl=bram

  int8_t v351[1][256][3][3];	// L652
  #pragma HLS array_partition variable=v351 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v351 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v351 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v351 type=ram_2p impl=lutram

  for (int v352 = 0; v352 < 1; v352 += 1) {	// L653
    for (int v353 = 0; v353 < 10; v353 += 1) {	// L654
      for (int v354 = 0; v354 < 10; v354 += 1) {	// L655
        for (int v355 = 0; v355 < 256; v355 += 1) {	// L656
          int8_t v356 = v350[v352][v355][1][v354];	// L657
          v350[v352][v355][0][v354] = v356;	// L658
          int8_t v357 = v350[v352][v355][2][v354];	// L659
          v350[v352][v355][1][v354] = v357;	// L660
          int8_t v358 = v341[v352][v355][v353][v354];	// L661
          v350[v352][v355][2][v354] = v358;	// L662
        }
        if ((v353 - 6) >= 0) {	// L664
          for (int v359 = 0; v359 < 256; v359 += 1) {	// L665
            for (int v360 = 0; v360 < 3; v360 += 1) {	// L666
              int8_t v361 = v351[v352][v359][v360][1];	// L667
              v351[v352][v359][v360][0] = v361;	// L668
              int8_t v362 = v351[v352][v359][v360][2];	// L669
              v351[v352][v359][v360][1] = v362;	// L670
              int8_t v363 = v350[v352][v359][v360][v354];	// L671
              v351[v352][v359][v360][2] = v363;	// L672
            }
          }
          if ((v354 - 6) >= 0) {	// L675
            int8_t v364[256];	// L676
            #pragma HLS bind_storage variable=v364 type=ram_2p impl=bram

            for (int v365 = 0; v365 < 256; v365 += 1) {	// L677
              v364[v365] = (int8_t)0.000000;	// L678
              for (int v366 = 0; v366 < 32; v366 += 1) {	// L679
                #pragma HLS pipeline II=1
                for (int v367 = 0; v367 < 8; v367 += 1) {	// L680
                  for (int v368 = 0; v368 < 3; v368 += 1) {	// L681
                    for (int v369 = 0; v369 < 3; v369 += 1) {	// L682
                      int8_t v370 = v351[v352][(v367 + (v366 * 8))][v368][v369];	// L683
                      int8_t v371 = v339[v365][(v367 + (v366 * 8))][v368][v369];	// L684
                      int8_t v372 = v370 * v371;	// L685
                      int8_t v373 = v364[v365];	// L686
                      int8_t v374 = v373 + v372;	// L687
                      v364[v365] = v374;	// L688
                    }
                  }
                }
              }
              int8_t v375 = v364[v365];	// L693
              v349[v352][v365][(v353 - 6)][(v354 - 6)] = v375;	// L694
            }
          }
        }
      }
    }
  }
  for (int v376 = 0; v376 < 1; v376 += 1) {	// L701
    for (int v377 = 0; v377 < 4; v377 += 1) {	// L702
      for (int v378 = 0; v378 < 4; v378 += 1) {	// L703
        for (int v379 = 0; v379 < 256; v379 += 1) {	// L704
          int8_t v380 = v349[0][v379][v377][v378];	// L705
          bool v381 = v380 > (int8_t)0.000000;	// L706
          int8_t v382 = v381 ? v380 : (int8_t)0.000000;	// L707
          v340[v376][v379][v377][v378] = v382;	// L708
        }
      }
    }
  }
  return ;	// L713
}

void main_graph_node12(
  int8_t v383[1][256][8][8],
  int8_t v384[256][256][3][3],
  int8_t v385[1][256][8][8]
) {	// L715
  #pragma HLS dataflow

  int8_t v386[1][256][10][10];	// L717
  #pragma HLS stream variable=v386 depth=10 type=fifo

  #pragma HLS bind_storage variable=v386 type=ram_t2p impl=bram

  for (int v387 = 0; v387 < 1; v387 += 1) {	// L718
    for (int v388 = 0; v388 < 10; v388 += 1) {	// L719
      for (int v389 = 0; v389 < 10; v389 += 1) {	// L720
        for (int v390 = 0; v390 < 256; v390 += 1) {	// L721
          int8_t v391;	// L722
          v391 = (int8_t)0.000000;	// L723
          if (((-v388) + 7) >= 0 && ((-v389) + 7) >= 0) {	// L724
            int8_t v392 = v383[v387][v390][v388][v389];	// L725
            v391 = v392;	// L726
          }
          int8_t v393 = v391;	// L728
          v386[v387][v390][v388][v389] = v393;	// L729
        }
      }
    }
  }
  int8_t v394[1][256][8][8];	// L734
  #pragma HLS stream variable=v394 depth=10 type=fifo

  #pragma HLS bind_storage variable=v394 type=ram_t2p impl=bram

  int8_t v395[1][256][3][10];	// L735
  #pragma HLS array_partition variable=v395 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v395 type=ram_2p impl=bram

  int8_t v396[1][256][3][3];	// L736
  #pragma HLS array_partition variable=v396 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v396 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v396 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v396 type=ram_2p impl=lutram

  for (int v397 = 0; v397 < 1; v397 += 1) {	// L737
    for (int v398 = 0; v398 < 10; v398 += 1) {	// L738
      for (int v399 = 0; v399 < 10; v399 += 1) {	// L739
        for (int v400 = 0; v400 < 256; v400 += 1) {	// L740
          int8_t v401 = v395[v397][v400][1][v399];	// L741
          v395[v397][v400][0][v399] = v401;	// L742
          int8_t v402 = v395[v397][v400][2][v399];	// L743
          v395[v397][v400][1][v399] = v402;	// L744
          int8_t v403 = v386[v397][v400][v398][v399];	// L745
          v395[v397][v400][2][v399] = v403;	// L746
        }
        if ((v398 - 2) >= 0) {	// L748
          for (int v404 = 0; v404 < 256; v404 += 1) {	// L749
            for (int v405 = 0; v405 < 3; v405 += 1) {	// L750
              int8_t v406 = v396[v397][v404][v405][1];	// L751
              v396[v397][v404][v405][0] = v406;	// L752
              int8_t v407 = v396[v397][v404][v405][2];	// L753
              v396[v397][v404][v405][1] = v407;	// L754
              int8_t v408 = v395[v397][v404][v405][v399];	// L755
              v396[v397][v404][v405][2] = v408;	// L756
            }
          }
          if ((v399 - 2) >= 0) {	// L759
            int8_t v409[256];	// L760
            #pragma HLS bind_storage variable=v409 type=ram_2p impl=bram

            for (int v410 = 0; v410 < 256; v410 += 1) {	// L761
              v409[v410] = (int8_t)0.000000;	// L762
              for (int v411 = 0; v411 < 32; v411 += 1) {	// L763
                #pragma HLS pipeline II=1
                for (int v412 = 0; v412 < 8; v412 += 1) {	// L764
                  for (int v413 = 0; v413 < 3; v413 += 1) {	// L765
                    for (int v414 = 0; v414 < 3; v414 += 1) {	// L766
                      int8_t v415 = v396[v397][(v412 + (v411 * 8))][v413][v414];	// L767
                      int8_t v416 = v384[v410][(v412 + (v411 * 8))][v413][v414];	// L768
                      int8_t v417 = v415 * v416;	// L769
                      int8_t v418 = v409[v410];	// L770
                      int8_t v419 = v418 + v417;	// L771
                      v409[v410] = v419;	// L772
                    }
                  }
                }
              }
              int8_t v420 = v409[v410];	// L777
              v394[v397][v410][(v398 - 2)][(v399 - 2)] = v420;	// L778
            }
          }
        }
      }
    }
  }
  for (int v421 = 0; v421 < 1; v421 += 1) {	// L785
    for (int v422 = 0; v422 < 8; v422 += 1) {	// L786
      for (int v423 = 0; v423 < 8; v423 += 1) {	// L787
        for (int v424 = 0; v424 < 256; v424 += 1) {	// L788
          int8_t v425 = v394[0][v424][v422][v423];	// L789
          bool v426 = v425 > (int8_t)0.000000;	// L790
          int8_t v427 = v426 ? v425 : (int8_t)0.000000;	// L791
          v385[v421][v424][v422][v423] = v427;	// L792
        }
      }
    }
  }
  return ;	// L797
}

void main_graph_node13(
  int8_t v428[256][128][3][3],
  int8_t v429[1][128][8][8],
  int8_t v430[1][256][8][8]
) {	// L799
  #pragma HLS dataflow

  int8_t v431[1][128][10][10];	// L801
  #pragma HLS stream variable=v431 depth=10 type=fifo

  #pragma HLS bind_storage variable=v431 type=ram_t2p impl=bram

  for (int v432 = 0; v432 < 1; v432 += 1) {	// L802
    for (int v433 = 0; v433 < 10; v433 += 1) {	// L803
      for (int v434 = 0; v434 < 10; v434 += 1) {	// L804
        for (int v435 = 0; v435 < 128; v435 += 1) {	// L805
          int8_t v436;	// L806
          v436 = (int8_t)0.000000;	// L807
          if (((-v433) + 7) >= 0 && ((-v434) + 7) >= 0) {	// L808
            int8_t v437 = v429[v432][v435][v433][v434];	// L809
            v436 = v437;	// L810
          }
          int8_t v438 = v436;	// L812
          v431[v432][v435][v433][v434] = v438;	// L813
        }
      }
    }
  }
  int8_t v439[1][256][8][8];	// L818
  #pragma HLS stream variable=v439 depth=10 type=fifo

  #pragma HLS bind_storage variable=v439 type=ram_t2p impl=bram

  int8_t v440[1][128][3][10];	// L819
  #pragma HLS array_partition variable=v440 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v440 type=ram_2p impl=bram

  int8_t v441[1][128][3][3];	// L820
  #pragma HLS array_partition variable=v441 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v441 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v441 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v441 type=ram_2p impl=lutram

  for (int v442 = 0; v442 < 1; v442 += 1) {	// L821
    for (int v443 = 0; v443 < 10; v443 += 1) {	// L822
      for (int v444 = 0; v444 < 10; v444 += 1) {	// L823
        for (int v445 = 0; v445 < 128; v445 += 1) {	// L824
          int8_t v446 = v440[v442][v445][1][v444];	// L825
          v440[v442][v445][0][v444] = v446;	// L826
          int8_t v447 = v440[v442][v445][2][v444];	// L827
          v440[v442][v445][1][v444] = v447;	// L828
          int8_t v448 = v431[v442][v445][v443][v444];	// L829
          v440[v442][v445][2][v444] = v448;	// L830
        }
        if ((v443 - 2) >= 0) {	// L832
          for (int v449 = 0; v449 < 128; v449 += 1) {	// L833
            for (int v450 = 0; v450 < 3; v450 += 1) {	// L834
              int8_t v451 = v441[v442][v449][v450][1];	// L835
              v441[v442][v449][v450][0] = v451;	// L836
              int8_t v452 = v441[v442][v449][v450][2];	// L837
              v441[v442][v449][v450][1] = v452;	// L838
              int8_t v453 = v440[v442][v449][v450][v444];	// L839
              v441[v442][v449][v450][2] = v453;	// L840
            }
          }
          if ((v444 - 2) >= 0) {	// L843
            int8_t v454[256];	// L844
            #pragma HLS bind_storage variable=v454 type=ram_2p impl=bram

            for (int v455 = 0; v455 < 256; v455 += 1) {	// L845
              v454[v455] = (int8_t)0.000000;	// L846
              for (int v456 = 0; v456 < 32; v456 += 1) {	// L847
                #pragma HLS pipeline II=1
                for (int v457 = 0; v457 < 4; v457 += 1) {	// L848
                  for (int v458 = 0; v458 < 3; v458 += 1) {	// L849
                    for (int v459 = 0; v459 < 3; v459 += 1) {	// L850
                      int8_t v460 = v441[v442][(v457 + (v456 * 4))][v458][v459];	// L851
                      int8_t v461 = v428[v455][(v457 + (v456 * 4))][v458][v459];	// L852
                      int8_t v462 = v460 * v461;	// L853
                      int8_t v463 = v454[v455];	// L854
                      int8_t v464 = v463 + v462;	// L855
                      v454[v455] = v464;	// L856
                    }
                  }
                }
              }
              int8_t v465 = v454[v455];	// L861
              v439[v442][v455][(v443 - 2)][(v444 - 2)] = v465;	// L862
            }
          }
        }
      }
    }
  }
  for (int v466 = 0; v466 < 1; v466 += 1) {	// L869
    for (int v467 = 0; v467 < 8; v467 += 1) {	// L870
      for (int v468 = 0; v468 < 8; v468 += 1) {	// L871
        for (int v469 = 0; v469 < 256; v469 += 1) {	// L872
          int8_t v470 = v439[0][v469][v467][v468];	// L873
          bool v471 = v470 > (int8_t)0.000000;	// L874
          int8_t v472 = v471 ? v470 : (int8_t)0.000000;	// L875
          v430[v466][v469][v467][v468] = v472;	// L876
        }
      }
    }
  }
  return ;	// L881
}

void main_graph_node14(
  int8_t v473[128][128][3][3],
  int8_t v474[1][128][16][16],
  int8_t v475[1][128][8][8]
) {	// L883
  #pragma HLS dataflow

  int8_t v476[1][128][18][18];	// L885
  #pragma HLS stream variable=v476 depth=10 type=fifo

  #pragma HLS bind_storage variable=v476 type=ram_t2p impl=bram

  for (int v477 = 0; v477 < 1; v477 += 1) {	// L886
    for (int v478 = 0; v478 < 18; v478 += 1) {	// L887
      for (int v479 = 0; v479 < 18; v479 += 1) {	// L888
        for (int v480 = 0; v480 < 128; v480 += 1) {	// L889
          int8_t v481;	// L890
          v481 = (int8_t)0.000000;	// L891
          if (((-v478) + 15) >= 0 && ((-v479) + 15) >= 0) {	// L892
            int8_t v482 = v474[v477][v480][v478][v479];	// L893
            v481 = v482;	// L894
          }
          int8_t v483 = v481;	// L896
          v476[v477][v480][v478][v479] = v483;	// L897
        }
      }
    }
  }
  int8_t v484[1][128][8][8];	// L902
  #pragma HLS stream variable=v484 depth=10 type=fifo

  #pragma HLS bind_storage variable=v484 type=ram_t2p impl=bram

  int8_t v485[1][128][3][18];	// L903
  #pragma HLS array_partition variable=v485 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v485 type=ram_2p impl=bram

  int8_t v486[1][128][3][3];	// L904
  #pragma HLS array_partition variable=v486 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v486 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v486 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v486 type=ram_2p impl=lutram

  for (int v487 = 0; v487 < 1; v487 += 1) {	// L905
    for (int v488 = 0; v488 < 18; v488 += 1) {	// L906
      for (int v489 = 0; v489 < 18; v489 += 1) {	// L907
        for (int v490 = 0; v490 < 128; v490 += 1) {	// L908
          int8_t v491 = v485[v487][v490][1][v489];	// L909
          v485[v487][v490][0][v489] = v491;	// L910
          int8_t v492 = v485[v487][v490][2][v489];	// L911
          v485[v487][v490][1][v489] = v492;	// L912
          int8_t v493 = v476[v487][v490][v488][v489];	// L913
          v485[v487][v490][2][v489] = v493;	// L914
        }
        if ((v488 - 10) >= 0) {	// L916
          for (int v494 = 0; v494 < 128; v494 += 1) {	// L917
            for (int v495 = 0; v495 < 3; v495 += 1) {	// L918
              int8_t v496 = v486[v487][v494][v495][1];	// L919
              v486[v487][v494][v495][0] = v496;	// L920
              int8_t v497 = v486[v487][v494][v495][2];	// L921
              v486[v487][v494][v495][1] = v497;	// L922
              int8_t v498 = v485[v487][v494][v495][v489];	// L923
              v486[v487][v494][v495][2] = v498;	// L924
            }
          }
          if ((v489 - 10) >= 0) {	// L927
            int8_t v499[128];	// L928
            #pragma HLS bind_storage variable=v499 type=ram_2p impl=bram

            for (int v500 = 0; v500 < 128; v500 += 1) {	// L929
              v499[v500] = (int8_t)0.000000;	// L930
              for (int v501 = 0; v501 < 16; v501 += 1) {	// L931
                #pragma HLS pipeline II=1
                for (int v502 = 0; v502 < 8; v502 += 1) {	// L932
                  for (int v503 = 0; v503 < 3; v503 += 1) {	// L933
                    for (int v504 = 0; v504 < 3; v504 += 1) {	// L934
                      int8_t v505 = v486[v487][(v502 + (v501 * 8))][v503][v504];	// L935
                      int8_t v506 = v473[v500][(v502 + (v501 * 8))][v503][v504];	// L936
                      int8_t v507 = v505 * v506;	// L937
                      int8_t v508 = v499[v500];	// L938
                      int8_t v509 = v508 + v507;	// L939
                      v499[v500] = v509;	// L940
                    }
                  }
                }
              }
              int8_t v510 = v499[v500];	// L945
              v484[v487][v500][(v488 - 10)][(v489 - 10)] = v510;	// L946
            }
          }
        }
      }
    }
  }
  for (int v511 = 0; v511 < 1; v511 += 1) {	// L953
    for (int v512 = 0; v512 < 8; v512 += 1) {	// L954
      for (int v513 = 0; v513 < 8; v513 += 1) {	// L955
        for (int v514 = 0; v514 < 128; v514 += 1) {	// L956
          int8_t v515 = v484[0][v514][v512][v513];	// L957
          bool v516 = v515 > (int8_t)0.000000;	// L958
          int8_t v517 = v516 ? v515 : (int8_t)0.000000;	// L959
          v475[v511][v514][v512][v513] = v517;	// L960
        }
      }
    }
  }
  return ;	// L965
}

void main_graph_node15(
  int8_t v518[1][64][16][16],
  int8_t v519[128][64][3][3],
  int8_t v520[1][128][16][16]
) {	// L967
  #pragma HLS dataflow

  int8_t v521[1][64][18][18];	// L969
  #pragma HLS stream variable=v521 depth=10 type=fifo

  #pragma HLS bind_storage variable=v521 type=ram_t2p impl=bram

  for (int v522 = 0; v522 < 1; v522 += 1) {	// L970
    for (int v523 = 0; v523 < 18; v523 += 1) {	// L971
      for (int v524 = 0; v524 < 18; v524 += 1) {	// L972
        for (int v525 = 0; v525 < 64; v525 += 1) {	// L973
          int8_t v526;	// L974
          v526 = (int8_t)0.000000;	// L975
          if (((-v523) + 15) >= 0 && ((-v524) + 15) >= 0) {	// L976
            int8_t v527 = v518[v522][v525][v523][v524];	// L977
            v526 = v527;	// L978
          }
          int8_t v528 = v526;	// L980
          v521[v522][v525][v523][v524] = v528;	// L981
        }
      }
    }
  }
  int8_t v529[1][128][16][16];	// L986
  #pragma HLS stream variable=v529 depth=10 type=fifo

  #pragma HLS bind_storage variable=v529 type=ram_t2p impl=bram

  int8_t v530[1][64][3][18];	// L987
  #pragma HLS array_partition variable=v530 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v530 type=ram_2p impl=bram

  int8_t v531[1][64][3][3];	// L988
  #pragma HLS array_partition variable=v531 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v531 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v531 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v531 type=ram_2p impl=lutram

  for (int v532 = 0; v532 < 1; v532 += 1) {	// L989
    for (int v533 = 0; v533 < 18; v533 += 1) {	// L990
      for (int v534 = 0; v534 < 18; v534 += 1) {	// L991
        for (int v535 = 0; v535 < 64; v535 += 1) {	// L992
          int8_t v536 = v530[v532][v535][1][v534];	// L993
          v530[v532][v535][0][v534] = v536;	// L994
          int8_t v537 = v530[v532][v535][2][v534];	// L995
          v530[v532][v535][1][v534] = v537;	// L996
          int8_t v538 = v521[v532][v535][v533][v534];	// L997
          v530[v532][v535][2][v534] = v538;	// L998
        }
        if ((v533 - 2) >= 0) {	// L1000
          for (int v539 = 0; v539 < 64; v539 += 1) {	// L1001
            for (int v540 = 0; v540 < 3; v540 += 1) {	// L1002
              int8_t v541 = v531[v532][v539][v540][1];	// L1003
              v531[v532][v539][v540][0] = v541;	// L1004
              int8_t v542 = v531[v532][v539][v540][2];	// L1005
              v531[v532][v539][v540][1] = v542;	// L1006
              int8_t v543 = v530[v532][v539][v540][v534];	// L1007
              v531[v532][v539][v540][2] = v543;	// L1008
            }
          }
          if ((v534 - 2) >= 0) {	// L1011
            int8_t v544[128];	// L1012
            #pragma HLS bind_storage variable=v544 type=ram_2p impl=bram

            for (int v545 = 0; v545 < 128; v545 += 1) {	// L1013
              v544[v545] = (int8_t)0.000000;	// L1014
              for (int v546 = 0; v546 < 16; v546 += 1) {	// L1015
                #pragma HLS pipeline II=1
                for (int v547 = 0; v547 < 4; v547 += 1) {	// L1016
                  for (int v548 = 0; v548 < 3; v548 += 1) {	// L1017
                    for (int v549 = 0; v549 < 3; v549 += 1) {	// L1018
                      int8_t v550 = v531[v532][(v547 + (v546 * 4))][v548][v549];	// L1019
                      int8_t v551 = v519[v545][(v547 + (v546 * 4))][v548][v549];	// L1020
                      int8_t v552 = v550 * v551;	// L1021
                      int8_t v553 = v544[v545];	// L1022
                      int8_t v554 = v553 + v552;	// L1023
                      v544[v545] = v554;	// L1024
                    }
                  }
                }
              }
              int8_t v555 = v544[v545];	// L1029
              v529[v532][v545][(v533 - 2)][(v534 - 2)] = v555;	// L1030
            }
          }
        }
      }
    }
  }
  for (int v556 = 0; v556 < 1; v556 += 1) {	// L1037
    for (int v557 = 0; v557 < 16; v557 += 1) {	// L1038
      for (int v558 = 0; v558 < 16; v558 += 1) {	// L1039
        for (int v559 = 0; v559 < 128; v559 += 1) {	// L1040
          int8_t v560 = v529[0][v559][v557][v558];	// L1041
          bool v561 = v560 > (int8_t)0.000000;	// L1042
          int8_t v562 = v561 ? v560 : (int8_t)0.000000;	// L1043
          v520[v556][v559][v557][v558] = v562;	// L1044
        }
      }
    }
  }
  return ;	// L1049
}

void main_graph_node16(
  int8_t v563[64][64][3][3],
  int8_t v564[1][64][32][32],
  int8_t v565[1][64][16][16]
) {	// L1051
  #pragma HLS dataflow

  int8_t v566[1][64][34][34];	// L1053
  #pragma HLS stream variable=v566 depth=10 type=fifo

  #pragma HLS bind_storage variable=v566 type=ram_t2p impl=bram

  for (int v567 = 0; v567 < 1; v567 += 1) {	// L1054
    for (int v568 = 0; v568 < 34; v568 += 1) {	// L1055
      for (int v569 = 0; v569 < 34; v569 += 1) {	// L1056
        for (int v570 = 0; v570 < 64; v570 += 1) {	// L1057
          int8_t v571;	// L1058
          v571 = (int8_t)0.000000;	// L1059
          if (((-v568) + 31) >= 0 && ((-v569) + 31) >= 0) {	// L1060
            int8_t v572 = v564[v567][v570][v568][v569];	// L1061
            v571 = v572;	// L1062
          }
          int8_t v573 = v571;	// L1064
          v566[v567][v570][v568][v569] = v573;	// L1065
        }
      }
    }
  }
  int8_t v574[1][64][16][16];	// L1070
  #pragma HLS stream variable=v574 depth=10 type=fifo

  #pragma HLS bind_storage variable=v574 type=ram_t2p impl=bram

  int8_t v575[1][64][3][34];	// L1071
  #pragma HLS array_partition variable=v575 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v575 type=ram_2p impl=bram

  int8_t v576[1][64][3][3];	// L1072
  #pragma HLS array_partition variable=v576 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v576 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v576 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v576 type=ram_2p impl=lutram

  for (int v577 = 0; v577 < 1; v577 += 1) {	// L1073
    for (int v578 = 0; v578 < 34; v578 += 1) {	// L1074
      for (int v579 = 0; v579 < 34; v579 += 1) {	// L1075
        for (int v580 = 0; v580 < 64; v580 += 1) {	// L1076
          int8_t v581 = v575[v577][v580][1][v579];	// L1077
          v575[v577][v580][0][v579] = v581;	// L1078
          int8_t v582 = v575[v577][v580][2][v579];	// L1079
          v575[v577][v580][1][v579] = v582;	// L1080
          int8_t v583 = v566[v577][v580][v578][v579];	// L1081
          v575[v577][v580][2][v579] = v583;	// L1082
        }
        if ((v578 - 18) >= 0) {	// L1084
          for (int v584 = 0; v584 < 64; v584 += 1) {	// L1085
            for (int v585 = 0; v585 < 3; v585 += 1) {	// L1086
              int8_t v586 = v576[v577][v584][v585][1];	// L1087
              v576[v577][v584][v585][0] = v586;	// L1088
              int8_t v587 = v576[v577][v584][v585][2];	// L1089
              v576[v577][v584][v585][1] = v587;	// L1090
              int8_t v588 = v575[v577][v584][v585][v579];	// L1091
              v576[v577][v584][v585][2] = v588;	// L1092
            }
          }
          if ((v579 - 18) >= 0) {	// L1095
            int8_t v589[64];	// L1096
            #pragma HLS bind_storage variable=v589 type=ram_2p impl=bram

            for (int v590 = 0; v590 < 64; v590 += 1) {	// L1097
              v589[v590] = (int8_t)0.000000;	// L1098
              for (int v591 = 0; v591 < 8; v591 += 1) {	// L1099
                #pragma HLS pipeline II=1
                for (int v592 = 0; v592 < 8; v592 += 1) {	// L1100
                  for (int v593 = 0; v593 < 3; v593 += 1) {	// L1101
                    for (int v594 = 0; v594 < 3; v594 += 1) {	// L1102
                      int8_t v595 = v576[v577][(v592 + (v591 * 8))][v593][v594];	// L1103
                      int8_t v596 = v563[v590][(v592 + (v591 * 8))][v593][v594];	// L1104
                      int8_t v597 = v595 * v596;	// L1105
                      int8_t v598 = v589[v590];	// L1106
                      int8_t v599 = v598 + v597;	// L1107
                      v589[v590] = v599;	// L1108
                    }
                  }
                }
              }
              int8_t v600 = v589[v590];	// L1113
              v574[v577][v590][(v578 - 18)][(v579 - 18)] = v600;	// L1114
            }
          }
        }
      }
    }
  }
  for (int v601 = 0; v601 < 1; v601 += 1) {	// L1121
    for (int v602 = 0; v602 < 16; v602 += 1) {	// L1122
      for (int v603 = 0; v603 < 16; v603 += 1) {	// L1123
        for (int v604 = 0; v604 < 64; v604 += 1) {	// L1124
          int8_t v605 = v574[0][v604][v602][v603];	// L1125
          bool v606 = v605 > (int8_t)0.000000;	// L1126
          int8_t v607 = v606 ? v605 : (int8_t)0.000000;	// L1127
          v565[v601][v604][v602][v603] = v607;	// L1128
        }
      }
    }
  }
  return ;	// L1133
}

void main_graph_node17(
  int8_t v608[1][3][32][32],
  int8_t v609[64][3][3][3],
  int8_t v610[1][64][32][32]
) {	// L1135
  #pragma HLS dataflow

  int8_t v611[1][3][34][34];	// L1137
  #pragma HLS stream variable=v611 depth=10 type=fifo

  #pragma HLS bind_storage variable=v611 type=ram_t2p impl=bram

  for (int v612 = 0; v612 < 1; v612 += 1) {	// L1138
    for (int v613 = 0; v613 < 34; v613 += 1) {	// L1139
      for (int v614 = 0; v614 < 34; v614 += 1) {	// L1140
        for (int v615 = 0; v615 < 3; v615 += 1) {	// L1141
          int8_t v616;	// L1142
          v616 = (int8_t)0.000000;	// L1143
          if (((-v613) + 31) >= 0 && ((-v614) + 31) >= 0) {	// L1144
            int8_t v617 = v608[v612][v615][v613][v614];	// L1145
            v616 = v617;	// L1146
          }
          int8_t v618 = v616;	// L1148
          v611[v612][v615][v613][v614] = v618;	// L1149
        }
      }
    }
  }
  int8_t v619[1][64][32][32];	// L1154
  #pragma HLS stream variable=v619 depth=10 type=fifo

  #pragma HLS bind_storage variable=v619 type=ram_t2p impl=bram

  int8_t v620[1][3][3][34];	// L1155
  #pragma HLS array_partition variable=v620 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v620 type=ram_2p impl=lutram

  int8_t v621[1][3][3][3];	// L1156
  #pragma HLS array_partition variable=v621 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v621 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v621 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v621 type=ram_2p impl=lutram

  for (int v622 = 0; v622 < 1; v622 += 1) {	// L1157
    for (int v623 = 0; v623 < 34; v623 += 1) {	// L1158
      for (int v624 = 0; v624 < 34; v624 += 1) {	// L1159
        for (int v625 = 0; v625 < 3; v625 += 1) {	// L1160
          int8_t v626 = v620[v622][v625][1][v624];	// L1161
          v620[v622][v625][0][v624] = v626;	// L1162
          int8_t v627 = v620[v622][v625][2][v624];	// L1163
          v620[v622][v625][1][v624] = v627;	// L1164
          int8_t v628 = v611[v622][v625][v623][v624];	// L1165
          v620[v622][v625][2][v624] = v628;	// L1166
        }
        if ((v623 - 2) >= 0) {	// L1168
          for (int v629 = 0; v629 < 3; v629 += 1) {	// L1169
            for (int v630 = 0; v630 < 3; v630 += 1) {	// L1170
              int8_t v631 = v621[v622][v629][v630][1];	// L1171
              v621[v622][v629][v630][0] = v631;	// L1172
              int8_t v632 = v621[v622][v629][v630][2];	// L1173
              v621[v622][v629][v630][1] = v632;	// L1174
              int8_t v633 = v620[v622][v629][v630][v624];	// L1175
              v621[v622][v629][v630][2] = v633;	// L1176
            }
          }
          if ((v624 - 2) >= 0) {	// L1179
            int8_t v634[64];	// L1180
            #pragma HLS bind_storage variable=v634 type=ram_2p impl=bram

            for (int v635 = 0; v635 < 64; v635 += 1) {	// L1181
              #pragma HLS pipeline II=1
              for (int v636 = 0; v636 < 1; v636 += 1) {	// L1182
                v634[(v635 + v636)] = (int8_t)0.000000;	// L1183
                for (int v637 = 0; v637 < 3; v637 += 1) {	// L1184
                  for (int v638 = 0; v638 < 3; v638 += 1) {	// L1185
                    for (int v639 = 0; v639 < 3; v639 += 1) {	// L1186
                      int8_t v640 = v621[v622][v637][v638][v639];	// L1187
                      int8_t v641 = v609[(v635 + v636)][v637][v638][v639];	// L1188
                      int8_t v642 = v640 * v641;	// L1189
                      int8_t v643 = v634[(v635 + v636)];	// L1190
                      int8_t v644 = v643 + v642;	// L1191
                      v634[(v635 + v636)] = v644;	// L1192
                    }
                  }
                }
                int8_t v645 = v634[(v635 + v636)];	// L1196
                v619[v622][(v635 + v636)][(v623 - 2)][(v624 - 2)] = v645;	// L1197
              }
            }
          }
        }
      }
    }
  }
  for (int v646 = 0; v646 < 1; v646 += 1) {	// L1205
    for (int v647 = 0; v647 < 32; v647 += 1) {	// L1206
      for (int v648 = 0; v648 < 32; v648 += 1) {	// L1207
        for (int v649 = 0; v649 < 64; v649 += 1) {	// L1208
          int8_t v650 = v619[0][v649][v647][v648];	// L1209
          bool v651 = v650 > (int8_t)0.000000;	// L1210
          int8_t v652 = v651 ? v650 : (int8_t)0.000000;	// L1211
          v610[v646][v649][v647][v648] = v652;	// L1212
        }
      }
    }
  }
  return ;	// L1217
}

/// This is top function.
void main_graph(
  int8_t v653[1][3][32][32],
  int8_t v654[10],
  int8_t v655[512][512][3][3],
  int8_t v656[512][512][3][3],
  int8_t v657[512][512][3][3],
  int8_t v658[512][512][3][3],
  int8_t v659[512][512][3][3],
  int8_t v660[512][256][3][3],
  int8_t v661[256][256][3][3],
  int8_t v662[256][256][3][3],
  int8_t v663[256][128][3][3],
  int8_t v664[128][128][3][3],
  int8_t v665[128][64][3][3],
  int8_t v666[64][64][3][3],
  int8_t v667[64][3][3][3],
  int8_t v668[512][10],
  int8_t v669[1][10]
) {	// L1219
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v653 bundle=gmem1
  #pragma HLS bind_storage variable=v653 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v654 bundle=gmem2
  #pragma HLS bind_storage variable=v654 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v655 bundle=gmem3
  #pragma HLS array_partition variable=v655 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v655 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v655 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v655 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v656 bundle=gmem4
  #pragma HLS array_partition variable=v656 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v656 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v656 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v656 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v657 bundle=gmem5
  #pragma HLS array_partition variable=v657 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v657 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v657 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v657 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v658 bundle=gmem6
  #pragma HLS array_partition variable=v658 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v658 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v658 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v658 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v659 bundle=gmem7
  #pragma HLS array_partition variable=v659 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v659 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v659 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v659 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v660 bundle=gmem8
  #pragma HLS array_partition variable=v660 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v660 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v660 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v660 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v661 bundle=gmem9
  #pragma HLS array_partition variable=v661 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v661 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v662 bundle=gmem10
  #pragma HLS array_partition variable=v662 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v662 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v662 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v662 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v663 bundle=gmem11
  #pragma HLS array_partition variable=v663 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v663 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v663 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v663 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v664 bundle=gmem12
  #pragma HLS array_partition variable=v664 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v664 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v664 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v664 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v665 bundle=gmem13
  #pragma HLS array_partition variable=v665 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v665 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v665 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v665 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v666 bundle=gmem14
  #pragma HLS array_partition variable=v666 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v666 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v666 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v666 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v667 bundle=gmem15
  #pragma HLS array_partition variable=v667 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v667 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v667 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v667 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v668 bundle=gmem16
  #pragma HLS bind_storage variable=v668 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v669 bundle=gmem17
  #pragma HLS bind_storage variable=v669 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v670[1][64][32][32];	// L1221
  #pragma HLS stream variable=v670 depth=10 type=fifo

  #pragma HLS bind_storage variable=v670 type=ram_t2p impl=bram

  main_graph_node17(v653, v667, v670);	// L1222
  int8_t v671[1][64][16][16];	// L1223
  #pragma HLS stream variable=v671 depth=10 type=fifo

  #pragma HLS bind_storage variable=v671 type=ram_t2p impl=bram

  main_graph_node16(v666, v670, v671);	// L1224
  int8_t v672[1][128][16][16];	// L1225
  #pragma HLS stream variable=v672 depth=10 type=fifo

  #pragma HLS bind_storage variable=v672 type=ram_t2p impl=bram

  main_graph_node15(v671, v665, v672);	// L1226
  int8_t v673[1][128][8][8];	// L1227
  #pragma HLS stream variable=v673 depth=10 type=fifo

  #pragma HLS bind_storage variable=v673 type=ram_t2p impl=bram

  main_graph_node14(v664, v672, v673);	// L1228
  int8_t v674[1][256][8][8];	// L1229
  #pragma HLS stream variable=v674 depth=10 type=fifo

  #pragma HLS bind_storage variable=v674 type=ram_t2p impl=bram

  main_graph_node13(v663, v673, v674);	// L1230
  int8_t v675[1][256][8][8];	// L1231
  #pragma HLS stream variable=v675 depth=10 type=fifo

  #pragma HLS bind_storage variable=v675 type=ram_t2p impl=bram

  main_graph_node12(v674, v662, v675);	// L1232
  int8_t v676[1][256][4][4];	// L1233
  #pragma HLS stream variable=v676 depth=10 type=fifo

  #pragma HLS bind_storage variable=v676 type=ram_t2p impl=bram

  main_graph_node11(v675, v661, v676);	// L1234
  int8_t v677[1][512][4][4];	// L1235
  #pragma HLS stream variable=v677 depth=10 type=fifo

  #pragma HLS bind_storage variable=v677 type=ram_t2p impl=bram

  main_graph_node10(v660, v676, v677);	// L1236
  int8_t v678[1][512][4][4];	// L1237
  #pragma HLS stream variable=v678 depth=10 type=fifo

  #pragma HLS bind_storage variable=v678 type=ram_t2p impl=bram

  main_graph_node9(v659, v677, v678);	// L1238
  int8_t v679[1][512][2][2];	// L1239
  #pragma HLS stream variable=v679 depth=10 type=fifo

  #pragma HLS bind_storage variable=v679 type=ram_t2p impl=bram

  main_graph_node8(v658, v678, v679);	// L1240
  int8_t v680[1][512][2][2];	// L1241
  #pragma HLS stream variable=v680 depth=10 type=fifo

  #pragma HLS bind_storage variable=v680 type=ram_t2p impl=bram

  main_graph_node7(v679, v657, v680);	// L1242
  int8_t v681[1][512][2][2];	// L1243
  #pragma HLS stream variable=v681 depth=10 type=fifo

  #pragma HLS bind_storage variable=v681 type=ram_t2p impl=bram

  main_graph_node6(v680, v656, v681);	// L1244
  int8_t v682[1][512][1][1];	// L1245
  #pragma HLS stream variable=v682 depth=10 type=fifo

  #pragma HLS bind_storage variable=v682 type=ram_t2p impl=bram

  main_graph_node5(v681, v655, v682);	// L1246
  int8_t v683[1][512][2][2];	// L1247
  #pragma HLS bind_storage variable=v683 type=ram_t2p impl=bram

  main_graph_node4(v682, v683);	// L1248
  int8_t v684[1][1];	// L1249
  #pragma HLS bind_storage variable=v684 type=ram_t2p impl=bram

  int8_t v685[1][512][1][1];	// L1250
  #pragma HLS bind_storage variable=v685 type=ram_t2p impl=bram

  main_graph_node3(v683, v684, v685);	// L1251
  int8_t v686[1][512][1][1];	// L1252
  #pragma HLS bind_storage variable=v686 type=ram_t2p impl=bram

  main_graph_node2(v685, v684, v686);	// L1253
  int8_t v687[1][10];	// L1254
  #pragma HLS bind_storage variable=v687 type=ram_t2p impl=bram

  main_graph_node1(v686, v668, v687);	// L1255
  main_graph_node0(v687, v654, v669);	// L1256
  return ;	// L1257
}

