
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
  int8_t v1[1][2048],
  int8_t v2[2048][1000],
  int8_t v3[1][1000]
) {	// L10
  #pragma HLS dataflow

  int8_t v4[1][1000];	// L12
  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  int8_t v5[1][1000];	// L13
  #pragma HLS bind_storage variable=v5 type=ram_t2p impl=bram

  for (int v6 = 0; v6 < 1; v6 += 1) {	// L14
    for (int v7 = 0; v7 < 1000; v7 += 1) {	// L15
      v4[v6][v7] = (int8_t)0.000000;	// L16
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L19
    for (int v9 = 0; v9 < 1000; v9 += 1) {	// L20
      for (int v10 = 0; v10 < 2048; v10 += 1) {	// L21
        int8_t v11 = v1[v8][v10];	// L22
        int8_t v12 = v2[v10][v9];	// L23
        int8_t v13 = v4[v8][v9];	// L24
        int8_t v14 = v11 * v12;	// L25
        int8_t v15 = v13 + v14;	// L26
        v5[v8][v9] = v15;	// L27
      }
    }
  }
  for (int v16 = 0; v16 < 1; v16 += 1) {	// L31
    for (int v17 = 0; v17 < 1000; v17 += 1) {	// L32
      int8_t v18 = v5[0][v17];	// L33
      int8_t v19 = v0[v17];	// L34
      int8_t v20 = v18 + v19;	// L35
      v3[v16][v17] = v20;	// L36
    }
  }
}

void main_graph_node1(
  int8_t v21[2048],
  int8_t v22[1][2048][1][1],
  int8_t v23[2048][2048],
  int8_t v24[1][2048]
) {	// L41
  #pragma HLS dataflow

  int8_t v25[1][2048];	// L43
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  int8_t v26[1][2048];	// L44
  #pragma HLS bind_storage variable=v26 type=ram_t2p impl=bram

  for (int v27 = 0; v27 < 1; v27 += 1) {	// L45
    for (int v28 = 0; v28 < 2048; v28 += 1) {	// L46
      v25[v27][v28] = (int8_t)0.000000;	// L47
    }
  }
  for (int v29 = 0; v29 < 1; v29 += 1) {	// L50
    for (int v30 = 0; v30 < 2048; v30 += 1) {	// L51
      for (int v31 = 0; v31 < 2048; v31 += 1) {	// L52
        int8_t v32 = v22[v29][v31][0][0];	// L53
        int8_t v33 = v23[v31][v30];	// L54
        int8_t v34 = v25[v29][v30];	// L55
        int8_t v35 = v32 * v33;	// L56
        int8_t v36 = v34 + v35;	// L57
        v26[v29][v30] = v36;	// L58
      }
    }
  }
  for (int v37 = 0; v37 < 1; v37 += 1) {	// L62
    for (int v38 = 0; v38 < 2048; v38 += 1) {	// L63
      int8_t v39 = v26[0][v38];	// L64
      int8_t v40 = v21[v38];	// L65
      int8_t v41 = v39 + v40;	// L66
      bool v42 = v41 > (int8_t)0.000000;	// L67
      int8_t v43 = v42 ? v41 : (int8_t)0.000000;	// L68
      v24[v37][v38] = v43;	// L69
    }
  }
}

void main_graph_node2(
  int8_t v44[2048][512][7][7],
  int8_t v45[1][512][7][7],
  int8_t v46[1][2048][1][1]
) {	// L74
  #pragma HLS dataflow

  int8_t v47[1][2048][1][1];	// L76
  #pragma HLS stream variable=v47 depth=10 type=fifo

  #pragma HLS bind_storage variable=v47 type=ram_t2p impl=bram

  int8_t v48[1][512][7][7];	// L77
  #pragma HLS array_partition variable=v48 cyclic factor=7 dim=3
  #pragma HLS bind_storage variable=v48 type=ram_2p impl=bram

  int8_t v49[1][512][7][7];	// L78
  #pragma HLS array_partition variable=v49 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v49 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v49 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v49 type=ram_2p impl=lutram

  for (int v50 = 0; v50 < 1; v50 += 1) {	// L79
    for (int v51 = 0; v51 < 7; v51 += 1) {	// L80
      for (int v52 = 0; v52 < 7; v52 += 1) {	// L81
        for (int v53 = 0; v53 < 512; v53 += 1) {	// L82
          int8_t v54 = v48[v50][v53][1][v52];	// L83
          v48[v50][v53][0][v52] = v54;	// L84
          int8_t v55 = v48[v50][v53][2][v52];	// L85
          v48[v50][v53][1][v52] = v55;	// L86
          int8_t v56 = v48[v50][v53][3][v52];	// L87
          v48[v50][v53][2][v52] = v56;	// L88
          int8_t v57 = v48[v50][v53][4][v52];	// L89
          v48[v50][v53][3][v52] = v57;	// L90
          int8_t v58 = v48[v50][v53][5][v52];	// L91
          v48[v50][v53][4][v52] = v58;	// L92
          int8_t v59 = v48[v50][v53][6][v52];	// L93
          v48[v50][v53][5][v52] = v59;	// L94
          int8_t v60 = v45[v50][v53][v51][v52];	// L95
          v48[v50][v53][6][v52] = v60;	// L96
        }
        if ((v51 - 6) >= 0) {	// L98
          for (int v61 = 0; v61 < 512; v61 += 1) {	// L99
            for (int v62 = 0; v62 < 7; v62 += 1) {	// L100
              int8_t v63 = v49[v50][v61][v62][1];	// L101
              v49[v50][v61][v62][0] = v63;	// L102
              int8_t v64 = v49[v50][v61][v62][2];	// L103
              v49[v50][v61][v62][1] = v64;	// L104
              int8_t v65 = v49[v50][v61][v62][3];	// L105
              v49[v50][v61][v62][2] = v65;	// L106
              int8_t v66 = v49[v50][v61][v62][4];	// L107
              v49[v50][v61][v62][3] = v66;	// L108
              int8_t v67 = v49[v50][v61][v62][5];	// L109
              v49[v50][v61][v62][4] = v67;	// L110
              int8_t v68 = v49[v50][v61][v62][6];	// L111
              v49[v50][v61][v62][5] = v68;	// L112
              int8_t v69 = v48[v50][v61][v62][v52];	// L113
              v49[v50][v61][v62][6] = v69;	// L114
            }
          }
          if ((v52 - 6) >= 0) {	// L117
            int8_t v70[2048];	// L118
            #pragma HLS bind_storage variable=v70 type=ram_2p impl=bram

            for (int v71 = 0; v71 < 2048; v71 += 1) {	// L119
              v70[v71] = (int8_t)0.000000;	// L120
              for (int v72 = 0; v72 < 64; v72 += 1) {	// L121
                #pragma HLS pipeline II=1
                for (int v73 = 0; v73 < 8; v73 += 1) {	// L122
                  for (int v74 = 0; v74 < 7; v74 += 1) {	// L123
                    for (int v75 = 0; v75 < 7; v75 += 1) {	// L124
                      int8_t v76 = v49[v50][(v73 + (v72 * 8))][v74][v75];	// L125
                      int8_t v77 = v44[v71][(v73 + (v72 * 8))][v74][v75];	// L126
                      int8_t v78 = v76 * v77;	// L127
                      int8_t v79 = v70[v71];	// L128
                      int8_t v80 = v79 + v78;	// L129
                      v70[v71] = v80;	// L130
                    }
                  }
                }
              }
              int8_t v81 = v70[v71];	// L135
              v47[v50][v71][(v51 - 6)][(v52 - 6)] = v81;	// L136
            }
          }
        }
      }
    }
  }
  for (int v82 = 0; v82 < 1; v82 += 1) {	// L143
    for (int v83 = 0; v83 < 1; v83 += 1) {	// L144
      for (int v84 = 0; v84 < 1; v84 += 1) {	// L145
        for (int v85 = 0; v85 < 2048; v85 += 1) {	// L146
          int8_t v86 = v47[0][v85][0][0];	// L147
          bool v87 = v86 > (int8_t)0.000000;	// L148
          int8_t v88 = v87 ? v86 : (int8_t)0.000000;	// L149
          v46[v82][v85][v83][v84] = v88;	// L150
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v89[1][512][14][14],
  int8_t v90[1][512][7][7]
) {	// L157
  #pragma HLS dataflow

  int8_t v91;	// L160
  v91 = (int8_t)-INFINITY;	// L161
  int8_t v92[1][512][14][14];	// L162
  #pragma HLS bind_storage variable=v92 type=ram_2p impl=bram

  for (int v93 = 0; v93 < 1; v93 += 1) {	// L163
    for (int v94 = 0; v94 < 14; v94 += 1) {	// L164
      for (int v95 = 0; v95 < 14; v95 += 1) {	// L165
        for (int v96 = 0; v96 < 512; v96 += 1) {	// L166
          int8_t v97 = v89[v93][v96][v94][v95];	// L167
          v92[v93][v96][v94][v95] = v97;	// L168
        }
      }
    }
  }
  for (int v98 = 0; v98 < 1; v98 += 1) {	// L173
    for (int v99 = 0; v99 < 7; v99 += 1) {	// L174
      for (int v100 = 0; v100 < 7; v100 += 1) {	// L175
        for (int v101 = 0; v101 < 512; v101 += 1) {	// L176
          int8_t v102;	// L177
          v102 = (int8_t)0.000000;	// L178
          for (int v103 = 0; v103 < 2; v103 += 1) {	// L179
            for (int v104 = 0; v104 < 2; v104 += 1) {	// L180
              int8_t v105 = v92[v98][v101][((v99 * 2) + v103)][((v100 * 2) + v104)];	// L181
              int8_t v106 = v91;	// L182
              int8_t v107 = max(v106, v105);	// L183
              v102 = v107;	// L184
            }
          }
          int8_t v108 = v102;	// L187
          v90[v98][v101][v99][v100] = v108;	// L188
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v109[512][512][3][3],
  int8_t v110[1][512][14][14],
  int8_t v111[1][512][14][14]
) {	// L195
  #pragma HLS dataflow

  int8_t v112[1][512][16][16];	// L197
  #pragma HLS stream variable=v112 depth=10 type=fifo

  #pragma HLS bind_storage variable=v112 type=ram_t2p impl=bram

  for (int v113 = 0; v113 < 1; v113 += 1) {	// L198
    for (int v114 = 0; v114 < 16; v114 += 1) {	// L199
      for (int v115 = 0; v115 < 16; v115 += 1) {	// L200
        for (int v116 = 0; v116 < 512; v116 += 1) {	// L201
          int8_t v117;	// L202
          v117 = (int8_t)0.000000;	// L203
          if (((-v114) + 13) >= 0 && ((-v115) + 13) >= 0) {	// L204
            int8_t v118 = v110[v113][v116][v114][v115];	// L205
            v117 = v118;	// L206
          }
          int8_t v119 = v117;	// L208
          v112[v113][v116][v114][v115] = v119;	// L209
        }
      }
    }
  }
  int8_t v120[1][512][14][14];	// L214
  #pragma HLS stream variable=v120 depth=10 type=fifo

  #pragma HLS bind_storage variable=v120 type=ram_t2p impl=bram

  int8_t v121[1][512][3][16];	// L215
  #pragma HLS array_partition variable=v121 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v121 type=ram_2p impl=bram

  int8_t v122[1][512][3][3];	// L216
  #pragma HLS array_partition variable=v122 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v122 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v122 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v122 type=ram_2p impl=lutram

  for (int v123 = 0; v123 < 1; v123 += 1) {	// L217
    for (int v124 = 0; v124 < 16; v124 += 1) {	// L218
      for (int v125 = 0; v125 < 16; v125 += 1) {	// L219
        for (int v126 = 0; v126 < 512; v126 += 1) {	// L220
          int8_t v127 = v121[v123][v126][1][v125];	// L221
          v121[v123][v126][0][v125] = v127;	// L222
          int8_t v128 = v121[v123][v126][2][v125];	// L223
          v121[v123][v126][1][v125] = v128;	// L224
          int8_t v129 = v112[v123][v126][v124][v125];	// L225
          v121[v123][v126][2][v125] = v129;	// L226
        }
        if ((v124 - 2) >= 0) {	// L228
          for (int v130 = 0; v130 < 512; v130 += 1) {	// L229
            for (int v131 = 0; v131 < 3; v131 += 1) {	// L230
              int8_t v132 = v122[v123][v130][v131][1];	// L231
              v122[v123][v130][v131][0] = v132;	// L232
              int8_t v133 = v122[v123][v130][v131][2];	// L233
              v122[v123][v130][v131][1] = v133;	// L234
              int8_t v134 = v121[v123][v130][v131][v125];	// L235
              v122[v123][v130][v131][2] = v134;	// L236
            }
          }
          if ((v125 - 2) >= 0) {	// L239
            int8_t v135[512];	// L240
            #pragma HLS bind_storage variable=v135 type=ram_2p impl=bram

            for (int v136 = 0; v136 < 512; v136 += 1) {	// L241
              v135[v136] = (int8_t)0.000000;	// L242
              for (int v137 = 0; v137 < 32; v137 += 1) {	// L243
                #pragma HLS pipeline II=1
                for (int v138 = 0; v138 < 16; v138 += 1) {	// L244
                  for (int v139 = 0; v139 < 3; v139 += 1) {	// L245
                    for (int v140 = 0; v140 < 3; v140 += 1) {	// L246
                      int8_t v141 = v122[v123][(v138 + (v137 * 16))][v139][v140];	// L247
                      int8_t v142 = v109[v136][(v138 + (v137 * 16))][v139][v140];	// L248
                      int8_t v143 = v141 * v142;	// L249
                      int8_t v144 = v135[v136];	// L250
                      int8_t v145 = v144 + v143;	// L251
                      v135[v136] = v145;	// L252
                    }
                  }
                }
              }
              int8_t v146 = v135[v136];	// L257
              v120[v123][v136][(v124 - 2)][(v125 - 2)] = v146;	// L258
            }
          }
        }
      }
    }
  }
  for (int v147 = 0; v147 < 1; v147 += 1) {	// L265
    for (int v148 = 0; v148 < 14; v148 += 1) {	// L266
      for (int v149 = 0; v149 < 14; v149 += 1) {	// L267
        for (int v150 = 0; v150 < 512; v150 += 1) {	// L268
          int8_t v151 = v120[0][v150][v148][v149];	// L269
          bool v152 = v151 > (int8_t)0.000000;	// L270
          int8_t v153 = v152 ? v151 : (int8_t)0.000000;	// L271
          v111[v147][v150][v148][v149] = v153;	// L272
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v154[1][512][14][14],
  int8_t v155[512][512][3][3],
  int8_t v156[1][512][14][14]
) {	// L279
  #pragma HLS dataflow

  int8_t v157[1][512][16][16];	// L281
  #pragma HLS stream variable=v157 depth=10 type=fifo

  #pragma HLS bind_storage variable=v157 type=ram_t2p impl=bram

  for (int v158 = 0; v158 < 1; v158 += 1) {	// L282
    for (int v159 = 0; v159 < 16; v159 += 1) {	// L283
      for (int v160 = 0; v160 < 16; v160 += 1) {	// L284
        for (int v161 = 0; v161 < 512; v161 += 1) {	// L285
          int8_t v162;	// L286
          v162 = (int8_t)0.000000;	// L287
          if (((-v159) + 13) >= 0 && ((-v160) + 13) >= 0) {	// L288
            int8_t v163 = v154[v158][v161][v159][v160];	// L289
            v162 = v163;	// L290
          }
          int8_t v164 = v162;	// L292
          v157[v158][v161][v159][v160] = v164;	// L293
        }
      }
    }
  }
  int8_t v165[1][512][14][14];	// L298
  #pragma HLS stream variable=v165 depth=10 type=fifo

  #pragma HLS bind_storage variable=v165 type=ram_t2p impl=bram

  int8_t v166[1][512][3][16];	// L299
  #pragma HLS array_partition variable=v166 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v166 type=ram_2p impl=bram

  int8_t v167[1][512][3][3];	// L300
  #pragma HLS array_partition variable=v167 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v167 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v167 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v167 type=ram_2p impl=lutram

  for (int v168 = 0; v168 < 1; v168 += 1) {	// L301
    for (int v169 = 0; v169 < 16; v169 += 1) {	// L302
      for (int v170 = 0; v170 < 16; v170 += 1) {	// L303
        for (int v171 = 0; v171 < 512; v171 += 1) {	// L304
          int8_t v172 = v166[v168][v171][1][v170];	// L305
          v166[v168][v171][0][v170] = v172;	// L306
          int8_t v173 = v166[v168][v171][2][v170];	// L307
          v166[v168][v171][1][v170] = v173;	// L308
          int8_t v174 = v157[v168][v171][v169][v170];	// L309
          v166[v168][v171][2][v170] = v174;	// L310
        }
        if ((v169 - 2) >= 0) {	// L312
          for (int v175 = 0; v175 < 512; v175 += 1) {	// L313
            for (int v176 = 0; v176 < 3; v176 += 1) {	// L314
              int8_t v177 = v167[v168][v175][v176][1];	// L315
              v167[v168][v175][v176][0] = v177;	// L316
              int8_t v178 = v167[v168][v175][v176][2];	// L317
              v167[v168][v175][v176][1] = v178;	// L318
              int8_t v179 = v166[v168][v175][v176][v170];	// L319
              v167[v168][v175][v176][2] = v179;	// L320
            }
          }
          if ((v170 - 2) >= 0) {	// L323
            int8_t v180[512];	// L324
            #pragma HLS bind_storage variable=v180 type=ram_2p impl=bram

            for (int v181 = 0; v181 < 512; v181 += 1) {	// L325
              v180[v181] = (int8_t)0.000000;	// L326
              for (int v182 = 0; v182 < 32; v182 += 1) {	// L327
                #pragma HLS pipeline II=1
                for (int v183 = 0; v183 < 16; v183 += 1) {	// L328
                  for (int v184 = 0; v184 < 3; v184 += 1) {	// L329
                    for (int v185 = 0; v185 < 3; v185 += 1) {	// L330
                      int8_t v186 = v167[v168][(v183 + (v182 * 16))][v184][v185];	// L331
                      int8_t v187 = v155[v181][(v183 + (v182 * 16))][v184][v185];	// L332
                      int8_t v188 = v186 * v187;	// L333
                      int8_t v189 = v180[v181];	// L334
                      int8_t v190 = v189 + v188;	// L335
                      v180[v181] = v190;	// L336
                    }
                  }
                }
              }
              int8_t v191 = v180[v181];	// L341
              v165[v168][v181][(v169 - 2)][(v170 - 2)] = v191;	// L342
            }
          }
        }
      }
    }
  }
  for (int v192 = 0; v192 < 1; v192 += 1) {	// L349
    for (int v193 = 0; v193 < 14; v193 += 1) {	// L350
      for (int v194 = 0; v194 < 14; v194 += 1) {	// L351
        for (int v195 = 0; v195 < 512; v195 += 1) {	// L352
          int8_t v196 = v165[0][v195][v193][v194];	// L353
          bool v197 = v196 > (int8_t)0.000000;	// L354
          int8_t v198 = v197 ? v196 : (int8_t)0.000000;	// L355
          v156[v192][v195][v193][v194] = v198;	// L356
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v199[512][256][3][3],
  int8_t v200[1][256][14][14],
  int8_t v201[1][512][14][14]
) {	// L363
  #pragma HLS dataflow

  int8_t v202[1][256][16][16];	// L365
  #pragma HLS stream variable=v202 depth=10 type=fifo

  #pragma HLS bind_storage variable=v202 type=ram_t2p impl=bram

  for (int v203 = 0; v203 < 1; v203 += 1) {	// L366
    for (int v204 = 0; v204 < 16; v204 += 1) {	// L367
      for (int v205 = 0; v205 < 16; v205 += 1) {	// L368
        for (int v206 = 0; v206 < 256; v206 += 1) {	// L369
          int8_t v207;	// L370
          v207 = (int8_t)0.000000;	// L371
          if (((-v204) + 13) >= 0 && ((-v205) + 13) >= 0) {	// L372
            int8_t v208 = v200[v203][v206][v204][v205];	// L373
            v207 = v208;	// L374
          }
          int8_t v209 = v207;	// L376
          v202[v203][v206][v204][v205] = v209;	// L377
        }
      }
    }
  }
  int8_t v210[1][512][14][14];	// L382
  #pragma HLS stream variable=v210 depth=10 type=fifo

  #pragma HLS bind_storage variable=v210 type=ram_t2p impl=bram

  int8_t v211[1][256][3][16];	// L383
  #pragma HLS array_partition variable=v211 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v211 type=ram_2p impl=bram

  int8_t v212[1][256][3][3];	// L384
  #pragma HLS array_partition variable=v212 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v212 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v212 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v212 type=ram_2p impl=lutram

  for (int v213 = 0; v213 < 1; v213 += 1) {	// L385
    for (int v214 = 0; v214 < 16; v214 += 1) {	// L386
      for (int v215 = 0; v215 < 16; v215 += 1) {	// L387
        for (int v216 = 0; v216 < 256; v216 += 1) {	// L388
          int8_t v217 = v211[v213][v216][1][v215];	// L389
          v211[v213][v216][0][v215] = v217;	// L390
          int8_t v218 = v211[v213][v216][2][v215];	// L391
          v211[v213][v216][1][v215] = v218;	// L392
          int8_t v219 = v202[v213][v216][v214][v215];	// L393
          v211[v213][v216][2][v215] = v219;	// L394
        }
        if ((v214 - 2) >= 0) {	// L396
          for (int v220 = 0; v220 < 256; v220 += 1) {	// L397
            for (int v221 = 0; v221 < 3; v221 += 1) {	// L398
              int8_t v222 = v212[v213][v220][v221][1];	// L399
              v212[v213][v220][v221][0] = v222;	// L400
              int8_t v223 = v212[v213][v220][v221][2];	// L401
              v212[v213][v220][v221][1] = v223;	// L402
              int8_t v224 = v211[v213][v220][v221][v215];	// L403
              v212[v213][v220][v221][2] = v224;	// L404
            }
          }
          if ((v215 - 2) >= 0) {	// L407
            int8_t v225[512];	// L408
            #pragma HLS bind_storage variable=v225 type=ram_2p impl=bram

            for (int v226 = 0; v226 < 512; v226 += 1) {	// L409
              v225[v226] = (int8_t)0.000000;	// L410
              for (int v227 = 0; v227 < 32; v227 += 1) {	// L411
                #pragma HLS pipeline II=1
                for (int v228 = 0; v228 < 8; v228 += 1) {	// L412
                  for (int v229 = 0; v229 < 3; v229 += 1) {	// L413
                    for (int v230 = 0; v230 < 3; v230 += 1) {	// L414
                      int8_t v231 = v212[v213][(v228 + (v227 * 8))][v229][v230];	// L415
                      int8_t v232 = v199[v226][(v228 + (v227 * 8))][v229][v230];	// L416
                      int8_t v233 = v231 * v232;	// L417
                      int8_t v234 = v225[v226];	// L418
                      int8_t v235 = v234 + v233;	// L419
                      v225[v226] = v235;	// L420
                    }
                  }
                }
              }
              int8_t v236 = v225[v226];	// L425
              v210[v213][v226][(v214 - 2)][(v215 - 2)] = v236;	// L426
            }
          }
        }
      }
    }
  }
  for (int v237 = 0; v237 < 1; v237 += 1) {	// L433
    for (int v238 = 0; v238 < 14; v238 += 1) {	// L434
      for (int v239 = 0; v239 < 14; v239 += 1) {	// L435
        for (int v240 = 0; v240 < 512; v240 += 1) {	// L436
          int8_t v241 = v210[0][v240][v238][v239];	// L437
          bool v242 = v241 > (int8_t)0.000000;	// L438
          int8_t v243 = v242 ? v241 : (int8_t)0.000000;	// L439
          v201[v237][v240][v238][v239] = v243;	// L440
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v244[1][256][28][28],
  int8_t v245[1][256][14][14]
) {	// L447
  #pragma HLS dataflow

  int8_t v246;	// L450
  v246 = (int8_t)-INFINITY;	// L451
  int8_t v247[1][256][28][28];	// L452
  #pragma HLS bind_storage variable=v247 type=ram_2p impl=bram

  for (int v248 = 0; v248 < 1; v248 += 1) {	// L453
    for (int v249 = 0; v249 < 28; v249 += 1) {	// L454
      for (int v250 = 0; v250 < 28; v250 += 1) {	// L455
        for (int v251 = 0; v251 < 256; v251 += 1) {	// L456
          int8_t v252 = v244[v248][v251][v249][v250];	// L457
          v247[v248][v251][v249][v250] = v252;	// L458
        }
      }
    }
  }
  for (int v253 = 0; v253 < 1; v253 += 1) {	// L463
    for (int v254 = 0; v254 < 14; v254 += 1) {	// L464
      for (int v255 = 0; v255 < 14; v255 += 1) {	// L465
        for (int v256 = 0; v256 < 256; v256 += 1) {	// L466
          int8_t v257;	// L467
          v257 = (int8_t)0.000000;	// L468
          for (int v258 = 0; v258 < 2; v258 += 1) {	// L469
            for (int v259 = 0; v259 < 2; v259 += 1) {	// L470
              int8_t v260 = v247[v253][v256][((v254 * 2) + v258)][((v255 * 2) + v259)];	// L471
              int8_t v261 = v246;	// L472
              int8_t v262 = max(v261, v260);	// L473
              v257 = v262;	// L474
            }
          }
          int8_t v263 = v257;	// L477
          v245[v253][v256][v254][v255] = v263;	// L478
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v264[256][256][3][3],
  int8_t v265[1][256][28][28],
  int8_t v266[1][256][28][28]
) {	// L485
  #pragma HLS dataflow

  int8_t v267[1][256][30][30];	// L487
  #pragma HLS stream variable=v267 depth=10 type=fifo

  #pragma HLS bind_storage variable=v267 type=ram_t2p impl=bram

  for (int v268 = 0; v268 < 1; v268 += 1) {	// L488
    for (int v269 = 0; v269 < 30; v269 += 1) {	// L489
      for (int v270 = 0; v270 < 30; v270 += 1) {	// L490
        for (int v271 = 0; v271 < 256; v271 += 1) {	// L491
          int8_t v272;	// L492
          v272 = (int8_t)0.000000;	// L493
          if (((-v269) + 27) >= 0 && ((-v270) + 27) >= 0) {	// L494
            int8_t v273 = v265[v268][v271][v269][v270];	// L495
            v272 = v273;	// L496
          }
          int8_t v274 = v272;	// L498
          v267[v268][v271][v269][v270] = v274;	// L499
        }
      }
    }
  }
  int8_t v275[1][256][28][28];	// L504
  #pragma HLS stream variable=v275 depth=10 type=fifo

  #pragma HLS bind_storage variable=v275 type=ram_t2p impl=bram

  int8_t v276[1][256][3][30];	// L505
  #pragma HLS array_partition variable=v276 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v276 type=ram_2p impl=bram

  int8_t v277[1][256][3][3];	// L506
  #pragma HLS array_partition variable=v277 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v277 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v277 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v277 type=ram_2p impl=lutram

  for (int v278 = 0; v278 < 1; v278 += 1) {	// L507
    for (int v279 = 0; v279 < 30; v279 += 1) {	// L508
      for (int v280 = 0; v280 < 30; v280 += 1) {	// L509
        for (int v281 = 0; v281 < 256; v281 += 1) {	// L510
          int8_t v282 = v276[v278][v281][1][v280];	// L511
          v276[v278][v281][0][v280] = v282;	// L512
          int8_t v283 = v276[v278][v281][2][v280];	// L513
          v276[v278][v281][1][v280] = v283;	// L514
          int8_t v284 = v267[v278][v281][v279][v280];	// L515
          v276[v278][v281][2][v280] = v284;	// L516
        }
        if ((v279 - 2) >= 0) {	// L518
          for (int v285 = 0; v285 < 256; v285 += 1) {	// L519
            for (int v286 = 0; v286 < 3; v286 += 1) {	// L520
              int8_t v287 = v277[v278][v285][v286][1];	// L521
              v277[v278][v285][v286][0] = v287;	// L522
              int8_t v288 = v277[v278][v285][v286][2];	// L523
              v277[v278][v285][v286][1] = v288;	// L524
              int8_t v289 = v276[v278][v285][v286][v280];	// L525
              v277[v278][v285][v286][2] = v289;	// L526
            }
          }
          if ((v280 - 2) >= 0) {	// L529
            int8_t v290[256];	// L530
            #pragma HLS bind_storage variable=v290 type=ram_2p impl=bram

            for (int v291 = 0; v291 < 256; v291 += 1) {	// L531
              v290[v291] = (int8_t)0.000000;	// L532
              for (int v292 = 0; v292 < 32; v292 += 1) {	// L533
                #pragma HLS pipeline II=1
                for (int v293 = 0; v293 < 8; v293 += 1) {	// L534
                  for (int v294 = 0; v294 < 3; v294 += 1) {	// L535
                    for (int v295 = 0; v295 < 3; v295 += 1) {	// L536
                      int8_t v296 = v277[v278][(v293 + (v292 * 8))][v294][v295];	// L537
                      int8_t v297 = v264[v291][(v293 + (v292 * 8))][v294][v295];	// L538
                      int8_t v298 = v296 * v297;	// L539
                      int8_t v299 = v290[v291];	// L540
                      int8_t v300 = v299 + v298;	// L541
                      v290[v291] = v300;	// L542
                    }
                  }
                }
              }
              int8_t v301 = v290[v291];	// L547
              v275[v278][v291][(v279 - 2)][(v280 - 2)] = v301;	// L548
            }
          }
        }
      }
    }
  }
  for (int v302 = 0; v302 < 1; v302 += 1) {	// L555
    for (int v303 = 0; v303 < 28; v303 += 1) {	// L556
      for (int v304 = 0; v304 < 28; v304 += 1) {	// L557
        for (int v305 = 0; v305 < 256; v305 += 1) {	// L558
          int8_t v306 = v275[0][v305][v303][v304];	// L559
          bool v307 = v306 > (int8_t)0.000000;	// L560
          int8_t v308 = v307 ? v306 : (int8_t)0.000000;	// L561
          v266[v302][v305][v303][v304] = v308;	// L562
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v309[1][256][28][28],
  int8_t v310[256][256][3][3],
  int8_t v311[1][256][28][28]
) {	// L569
  #pragma HLS dataflow

  int8_t v312[1][256][30][30];	// L571
  #pragma HLS stream variable=v312 depth=10 type=fifo

  #pragma HLS bind_storage variable=v312 type=ram_t2p impl=bram

  for (int v313 = 0; v313 < 1; v313 += 1) {	// L572
    for (int v314 = 0; v314 < 30; v314 += 1) {	// L573
      for (int v315 = 0; v315 < 30; v315 += 1) {	// L574
        for (int v316 = 0; v316 < 256; v316 += 1) {	// L575
          int8_t v317;	// L576
          v317 = (int8_t)0.000000;	// L577
          if (((-v314) + 27) >= 0 && ((-v315) + 27) >= 0) {	// L578
            int8_t v318 = v309[v313][v316][v314][v315];	// L579
            v317 = v318;	// L580
          }
          int8_t v319 = v317;	// L582
          v312[v313][v316][v314][v315] = v319;	// L583
        }
      }
    }
  }
  int8_t v320[1][256][28][28];	// L588
  #pragma HLS stream variable=v320 depth=10 type=fifo

  #pragma HLS bind_storage variable=v320 type=ram_t2p impl=bram

  int8_t v321[1][256][3][30];	// L589
  #pragma HLS array_partition variable=v321 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v321 type=ram_2p impl=bram

  int8_t v322[1][256][3][3];	// L590
  #pragma HLS array_partition variable=v322 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v322 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v322 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v322 type=ram_2p impl=lutram

  for (int v323 = 0; v323 < 1; v323 += 1) {	// L591
    for (int v324 = 0; v324 < 30; v324 += 1) {	// L592
      for (int v325 = 0; v325 < 30; v325 += 1) {	// L593
        for (int v326 = 0; v326 < 256; v326 += 1) {	// L594
          int8_t v327 = v321[v323][v326][1][v325];	// L595
          v321[v323][v326][0][v325] = v327;	// L596
          int8_t v328 = v321[v323][v326][2][v325];	// L597
          v321[v323][v326][1][v325] = v328;	// L598
          int8_t v329 = v312[v323][v326][v324][v325];	// L599
          v321[v323][v326][2][v325] = v329;	// L600
        }
        if ((v324 - 2) >= 0) {	// L602
          for (int v330 = 0; v330 < 256; v330 += 1) {	// L603
            for (int v331 = 0; v331 < 3; v331 += 1) {	// L604
              int8_t v332 = v322[v323][v330][v331][1];	// L605
              v322[v323][v330][v331][0] = v332;	// L606
              int8_t v333 = v322[v323][v330][v331][2];	// L607
              v322[v323][v330][v331][1] = v333;	// L608
              int8_t v334 = v321[v323][v330][v331][v325];	// L609
              v322[v323][v330][v331][2] = v334;	// L610
            }
          }
          if ((v325 - 2) >= 0) {	// L613
            int8_t v335[256];	// L614
            #pragma HLS bind_storage variable=v335 type=ram_2p impl=bram

            for (int v336 = 0; v336 < 256; v336 += 1) {	// L615
              v335[v336] = (int8_t)0.000000;	// L616
              for (int v337 = 0; v337 < 32; v337 += 1) {	// L617
                #pragma HLS pipeline II=1
                for (int v338 = 0; v338 < 8; v338 += 1) {	// L618
                  for (int v339 = 0; v339 < 3; v339 += 1) {	// L619
                    for (int v340 = 0; v340 < 3; v340 += 1) {	// L620
                      int8_t v341 = v322[v323][(v338 + (v337 * 8))][v339][v340];	// L621
                      int8_t v342 = v310[v336][(v338 + (v337 * 8))][v339][v340];	// L622
                      int8_t v343 = v341 * v342;	// L623
                      int8_t v344 = v335[v336];	// L624
                      int8_t v345 = v344 + v343;	// L625
                      v335[v336] = v345;	// L626
                    }
                  }
                }
              }
              int8_t v346 = v335[v336];	// L631
              v320[v323][v336][(v324 - 2)][(v325 - 2)] = v346;	// L632
            }
          }
        }
      }
    }
  }
  for (int v347 = 0; v347 < 1; v347 += 1) {	// L639
    for (int v348 = 0; v348 < 28; v348 += 1) {	// L640
      for (int v349 = 0; v349 < 28; v349 += 1) {	// L641
        for (int v350 = 0; v350 < 256; v350 += 1) {	// L642
          int8_t v351 = v320[0][v350][v348][v349];	// L643
          bool v352 = v351 > (int8_t)0.000000;	// L644
          int8_t v353 = v352 ? v351 : (int8_t)0.000000;	// L645
          v311[v347][v350][v348][v349] = v353;	// L646
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v354[256][128][3][3],
  int8_t v355[1][128][28][28],
  int8_t v356[1][256][28][28]
) {	// L653
  #pragma HLS dataflow

  int8_t v357[1][128][30][30];	// L655
  #pragma HLS stream variable=v357 depth=10 type=fifo

  #pragma HLS bind_storage variable=v357 type=ram_t2p impl=bram

  for (int v358 = 0; v358 < 1; v358 += 1) {	// L656
    for (int v359 = 0; v359 < 30; v359 += 1) {	// L657
      for (int v360 = 0; v360 < 30; v360 += 1) {	// L658
        for (int v361 = 0; v361 < 128; v361 += 1) {	// L659
          int8_t v362;	// L660
          v362 = (int8_t)0.000000;	// L661
          if (((-v359) + 27) >= 0 && ((-v360) + 27) >= 0) {	// L662
            int8_t v363 = v355[v358][v361][v359][v360];	// L663
            v362 = v363;	// L664
          }
          int8_t v364 = v362;	// L666
          v357[v358][v361][v359][v360] = v364;	// L667
        }
      }
    }
  }
  int8_t v365[1][256][28][28];	// L672
  #pragma HLS stream variable=v365 depth=10 type=fifo

  #pragma HLS bind_storage variable=v365 type=ram_t2p impl=bram

  int8_t v366[1][128][3][30];	// L673
  #pragma HLS array_partition variable=v366 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v366 type=ram_2p impl=bram

  int8_t v367[1][128][3][3];	// L674
  #pragma HLS array_partition variable=v367 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v367 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v367 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v367 type=ram_2p impl=lutram

  for (int v368 = 0; v368 < 1; v368 += 1) {	// L675
    for (int v369 = 0; v369 < 30; v369 += 1) {	// L676
      for (int v370 = 0; v370 < 30; v370 += 1) {	// L677
        for (int v371 = 0; v371 < 128; v371 += 1) {	// L678
          int8_t v372 = v366[v368][v371][1][v370];	// L679
          v366[v368][v371][0][v370] = v372;	// L680
          int8_t v373 = v366[v368][v371][2][v370];	// L681
          v366[v368][v371][1][v370] = v373;	// L682
          int8_t v374 = v357[v368][v371][v369][v370];	// L683
          v366[v368][v371][2][v370] = v374;	// L684
        }
        if ((v369 - 2) >= 0) {	// L686
          for (int v375 = 0; v375 < 128; v375 += 1) {	// L687
            for (int v376 = 0; v376 < 3; v376 += 1) {	// L688
              int8_t v377 = v367[v368][v375][v376][1];	// L689
              v367[v368][v375][v376][0] = v377;	// L690
              int8_t v378 = v367[v368][v375][v376][2];	// L691
              v367[v368][v375][v376][1] = v378;	// L692
              int8_t v379 = v366[v368][v375][v376][v370];	// L693
              v367[v368][v375][v376][2] = v379;	// L694
            }
          }
          if ((v370 - 2) >= 0) {	// L697
            int8_t v380[256];	// L698
            #pragma HLS bind_storage variable=v380 type=ram_2p impl=bram

            for (int v381 = 0; v381 < 256; v381 += 1) {	// L699
              v380[v381] = (int8_t)0.000000;	// L700
              for (int v382 = 0; v382 < 32; v382 += 1) {	// L701
                #pragma HLS pipeline II=1
                for (int v383 = 0; v383 < 4; v383 += 1) {	// L702
                  for (int v384 = 0; v384 < 3; v384 += 1) {	// L703
                    for (int v385 = 0; v385 < 3; v385 += 1) {	// L704
                      int8_t v386 = v367[v368][(v383 + (v382 * 4))][v384][v385];	// L705
                      int8_t v387 = v354[v381][(v383 + (v382 * 4))][v384][v385];	// L706
                      int8_t v388 = v386 * v387;	// L707
                      int8_t v389 = v380[v381];	// L708
                      int8_t v390 = v389 + v388;	// L709
                      v380[v381] = v390;	// L710
                    }
                  }
                }
              }
              int8_t v391 = v380[v381];	// L715
              v365[v368][v381][(v369 - 2)][(v370 - 2)] = v391;	// L716
            }
          }
        }
      }
    }
  }
  for (int v392 = 0; v392 < 1; v392 += 1) {	// L723
    for (int v393 = 0; v393 < 28; v393 += 1) {	// L724
      for (int v394 = 0; v394 < 28; v394 += 1) {	// L725
        for (int v395 = 0; v395 < 256; v395 += 1) {	// L726
          int8_t v396 = v365[0][v395][v393][v394];	// L727
          bool v397 = v396 > (int8_t)0.000000;	// L728
          int8_t v398 = v397 ? v396 : (int8_t)0.000000;	// L729
          v356[v392][v395][v393][v394] = v398;	// L730
        }
      }
    }
  }
}

void main_graph_node11(
  int8_t v399[1][128][56][56],
  int8_t v400[1][128][28][28]
) {	// L737
  #pragma HLS dataflow

  int8_t v401;	// L740
  v401 = (int8_t)-INFINITY;	// L741
  int8_t v402[1][128][56][56];	// L742
  #pragma HLS bind_storage variable=v402 type=ram_2p impl=bram

  for (int v403 = 0; v403 < 1; v403 += 1) {	// L743
    for (int v404 = 0; v404 < 56; v404 += 1) {	// L744
      for (int v405 = 0; v405 < 56; v405 += 1) {	// L745
        for (int v406 = 0; v406 < 128; v406 += 1) {	// L746
          int8_t v407 = v399[v403][v406][v404][v405];	// L747
          v402[v403][v406][v404][v405] = v407;	// L748
        }
      }
    }
  }
  for (int v408 = 0; v408 < 1; v408 += 1) {	// L753
    for (int v409 = 0; v409 < 28; v409 += 1) {	// L754
      for (int v410 = 0; v410 < 28; v410 += 1) {	// L755
        for (int v411 = 0; v411 < 128; v411 += 1) {	// L756
          int8_t v412;	// L757
          v412 = (int8_t)0.000000;	// L758
          for (int v413 = 0; v413 < 2; v413 += 1) {	// L759
            for (int v414 = 0; v414 < 2; v414 += 1) {	// L760
              int8_t v415 = v402[v408][v411][((v409 * 2) + v413)][((v410 * 2) + v414)];	// L761
              int8_t v416 = v401;	// L762
              int8_t v417 = max(v416, v415);	// L763
              v412 = v417;	// L764
            }
          }
          int8_t v418 = v412;	// L767
          v400[v408][v411][v409][v410] = v418;	// L768
        }
      }
    }
  }
}

void main_graph_node12(
  int8_t v419[128][128][3][3],
  int8_t v420[1][128][56][56],
  int8_t v421[1][128][56][56]
) {	// L775
  #pragma HLS dataflow

  int8_t v422[1][128][58][58];	// L777
  #pragma HLS stream variable=v422 depth=10 type=fifo

  #pragma HLS bind_storage variable=v422 type=ram_t2p impl=bram

  for (int v423 = 0; v423 < 1; v423 += 1) {	// L778
    for (int v424 = 0; v424 < 58; v424 += 1) {	// L779
      for (int v425 = 0; v425 < 58; v425 += 1) {	// L780
        for (int v426 = 0; v426 < 128; v426 += 1) {	// L781
          int8_t v427;	// L782
          v427 = (int8_t)0.000000;	// L783
          if (((-v424) + 55) >= 0 && ((-v425) + 55) >= 0) {	// L784
            int8_t v428 = v420[v423][v426][v424][v425];	// L785
            v427 = v428;	// L786
          }
          int8_t v429 = v427;	// L788
          v422[v423][v426][v424][v425] = v429;	// L789
        }
      }
    }
  }
  int8_t v430[1][128][56][56];	// L794
  #pragma HLS stream variable=v430 depth=10 type=fifo

  #pragma HLS bind_storage variable=v430 type=ram_t2p impl=bram

  int8_t v431[1][128][3][58];	// L795
  #pragma HLS array_partition variable=v431 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v431 type=ram_2p impl=bram

  int8_t v432[1][128][3][3];	// L796
  #pragma HLS array_partition variable=v432 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v432 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v432 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v432 type=ram_2p impl=lutram

  for (int v433 = 0; v433 < 1; v433 += 1) {	// L797
    for (int v434 = 0; v434 < 58; v434 += 1) {	// L798
      for (int v435 = 0; v435 < 58; v435 += 1) {	// L799
        for (int v436 = 0; v436 < 128; v436 += 1) {	// L800
          int8_t v437 = v431[v433][v436][1][v435];	// L801
          v431[v433][v436][0][v435] = v437;	// L802
          int8_t v438 = v431[v433][v436][2][v435];	// L803
          v431[v433][v436][1][v435] = v438;	// L804
          int8_t v439 = v422[v433][v436][v434][v435];	// L805
          v431[v433][v436][2][v435] = v439;	// L806
        }
        if ((v434 - 2) >= 0) {	// L808
          for (int v440 = 0; v440 < 128; v440 += 1) {	// L809
            for (int v441 = 0; v441 < 3; v441 += 1) {	// L810
              int8_t v442 = v432[v433][v440][v441][1];	// L811
              v432[v433][v440][v441][0] = v442;	// L812
              int8_t v443 = v432[v433][v440][v441][2];	// L813
              v432[v433][v440][v441][1] = v443;	// L814
              int8_t v444 = v431[v433][v440][v441][v435];	// L815
              v432[v433][v440][v441][2] = v444;	// L816
            }
          }
          if ((v435 - 2) >= 0) {	// L819
            int8_t v445[128];	// L820
            #pragma HLS bind_storage variable=v445 type=ram_2p impl=bram

            for (int v446 = 0; v446 < 128; v446 += 1) {	// L821
              v445[v446] = (int8_t)0.000000;	// L822
              for (int v447 = 0; v447 < 8; v447 += 1) {	// L823
                #pragma HLS pipeline II=1
                for (int v448 = 0; v448 < 16; v448 += 1) {	// L824
                  for (int v449 = 0; v449 < 3; v449 += 1) {	// L825
                    for (int v450 = 0; v450 < 3; v450 += 1) {	// L826
                      int8_t v451 = v432[v433][(v448 + (v447 * 16))][v449][v450];	// L827
                      int8_t v452 = v419[v446][(v448 + (v447 * 16))][v449][v450];	// L828
                      int8_t v453 = v451 * v452;	// L829
                      int8_t v454 = v445[v446];	// L830
                      int8_t v455 = v454 + v453;	// L831
                      v445[v446] = v455;	// L832
                    }
                  }
                }
              }
              int8_t v456 = v445[v446];	// L837
              v430[v433][v446][(v434 - 2)][(v435 - 2)] = v456;	// L838
            }
          }
        }
      }
    }
  }
  for (int v457 = 0; v457 < 1; v457 += 1) {	// L845
    for (int v458 = 0; v458 < 56; v458 += 1) {	// L846
      for (int v459 = 0; v459 < 56; v459 += 1) {	// L847
        for (int v460 = 0; v460 < 128; v460 += 1) {	// L848
          int8_t v461 = v430[0][v460][v458][v459];	// L849
          bool v462 = v461 > (int8_t)0.000000;	// L850
          int8_t v463 = v462 ? v461 : (int8_t)0.000000;	// L851
          v421[v457][v460][v458][v459] = v463;	// L852
        }
      }
    }
  }
}

void main_graph_node13(
  int8_t v464[1][128][56][56],
  int8_t v465[128][128][3][3],
  int8_t v466[1][128][56][56]
) {	// L859
  #pragma HLS dataflow

  int8_t v467[1][128][58][58];	// L861
  #pragma HLS stream variable=v467 depth=10 type=fifo

  #pragma HLS bind_storage variable=v467 type=ram_t2p impl=bram

  for (int v468 = 0; v468 < 1; v468 += 1) {	// L862
    for (int v469 = 0; v469 < 58; v469 += 1) {	// L863
      for (int v470 = 0; v470 < 58; v470 += 1) {	// L864
        for (int v471 = 0; v471 < 128; v471 += 1) {	// L865
          int8_t v472;	// L866
          v472 = (int8_t)0.000000;	// L867
          if (((-v469) + 55) >= 0 && ((-v470) + 55) >= 0) {	// L868
            int8_t v473 = v464[v468][v471][v469][v470];	// L869
            v472 = v473;	// L870
          }
          int8_t v474 = v472;	// L872
          v467[v468][v471][v469][v470] = v474;	// L873
        }
      }
    }
  }
  int8_t v475[1][128][56][56];	// L878
  #pragma HLS stream variable=v475 depth=10 type=fifo

  #pragma HLS bind_storage variable=v475 type=ram_t2p impl=bram

  int8_t v476[1][128][3][58];	// L879
  #pragma HLS array_partition variable=v476 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v476 type=ram_2p impl=bram

  int8_t v477[1][128][3][3];	// L880
  #pragma HLS array_partition variable=v477 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v477 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v477 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v477 type=ram_2p impl=lutram

  for (int v478 = 0; v478 < 1; v478 += 1) {	// L881
    for (int v479 = 0; v479 < 58; v479 += 1) {	// L882
      for (int v480 = 0; v480 < 58; v480 += 1) {	// L883
        for (int v481 = 0; v481 < 128; v481 += 1) {	// L884
          int8_t v482 = v476[v478][v481][1][v480];	// L885
          v476[v478][v481][0][v480] = v482;	// L886
          int8_t v483 = v476[v478][v481][2][v480];	// L887
          v476[v478][v481][1][v480] = v483;	// L888
          int8_t v484 = v467[v478][v481][v479][v480];	// L889
          v476[v478][v481][2][v480] = v484;	// L890
        }
        if ((v479 - 2) >= 0) {	// L892
          for (int v485 = 0; v485 < 128; v485 += 1) {	// L893
            for (int v486 = 0; v486 < 3; v486 += 1) {	// L894
              int8_t v487 = v477[v478][v485][v486][1];	// L895
              v477[v478][v485][v486][0] = v487;	// L896
              int8_t v488 = v477[v478][v485][v486][2];	// L897
              v477[v478][v485][v486][1] = v488;	// L898
              int8_t v489 = v476[v478][v485][v486][v480];	// L899
              v477[v478][v485][v486][2] = v489;	// L900
            }
          }
          if ((v480 - 2) >= 0) {	// L903
            int8_t v490[128];	// L904
            #pragma HLS bind_storage variable=v490 type=ram_2p impl=bram

            for (int v491 = 0; v491 < 128; v491 += 1) {	// L905
              v490[v491] = (int8_t)0.000000;	// L906
              for (int v492 = 0; v492 < 8; v492 += 1) {	// L907
                #pragma HLS pipeline II=1
                for (int v493 = 0; v493 < 16; v493 += 1) {	// L908
                  for (int v494 = 0; v494 < 3; v494 += 1) {	// L909
                    for (int v495 = 0; v495 < 3; v495 += 1) {	// L910
                      int8_t v496 = v477[v478][(v493 + (v492 * 16))][v494][v495];	// L911
                      int8_t v497 = v465[v491][(v493 + (v492 * 16))][v494][v495];	// L912
                      int8_t v498 = v496 * v497;	// L913
                      int8_t v499 = v490[v491];	// L914
                      int8_t v500 = v499 + v498;	// L915
                      v490[v491] = v500;	// L916
                    }
                  }
                }
              }
              int8_t v501 = v490[v491];	// L921
              v475[v478][v491][(v479 - 2)][(v480 - 2)] = v501;	// L922
            }
          }
        }
      }
    }
  }
  for (int v502 = 0; v502 < 1; v502 += 1) {	// L929
    for (int v503 = 0; v503 < 56; v503 += 1) {	// L930
      for (int v504 = 0; v504 < 56; v504 += 1) {	// L931
        for (int v505 = 0; v505 < 128; v505 += 1) {	// L932
          int8_t v506 = v475[0][v505][v503][v504];	// L933
          bool v507 = v506 > (int8_t)0.000000;	// L934
          int8_t v508 = v507 ? v506 : (int8_t)0.000000;	// L935
          v466[v502][v505][v503][v504] = v508;	// L936
        }
      }
    }
  }
}

void main_graph_node14(
  int8_t v509[128][64][3][3],
  int8_t v510[1][64][56][56],
  int8_t v511[1][128][56][56]
) {	// L943
  #pragma HLS dataflow

  int8_t v512[1][64][58][58];	// L945
  #pragma HLS stream variable=v512 depth=10 type=fifo

  #pragma HLS bind_storage variable=v512 type=ram_t2p impl=bram

  for (int v513 = 0; v513 < 1; v513 += 1) {	// L946
    for (int v514 = 0; v514 < 58; v514 += 1) {	// L947
      for (int v515 = 0; v515 < 58; v515 += 1) {	// L948
        for (int v516 = 0; v516 < 64; v516 += 1) {	// L949
          int8_t v517;	// L950
          v517 = (int8_t)0.000000;	// L951
          if (((-v514) + 55) >= 0 && ((-v515) + 55) >= 0) {	// L952
            int8_t v518 = v510[v513][v516][v514][v515];	// L953
            v517 = v518;	// L954
          }
          int8_t v519 = v517;	// L956
          v512[v513][v516][v514][v515] = v519;	// L957
        }
      }
    }
  }
  int8_t v520[1][128][56][56];	// L962
  #pragma HLS stream variable=v520 depth=10 type=fifo

  #pragma HLS bind_storage variable=v520 type=ram_t2p impl=bram

  int8_t v521[1][64][3][58];	// L963
  #pragma HLS array_partition variable=v521 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v521 type=ram_2p impl=bram

  int8_t v522[1][64][3][3];	// L964
  #pragma HLS array_partition variable=v522 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v522 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v522 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v522 type=ram_2p impl=lutram

  for (int v523 = 0; v523 < 1; v523 += 1) {	// L965
    for (int v524 = 0; v524 < 58; v524 += 1) {	// L966
      for (int v525 = 0; v525 < 58; v525 += 1) {	// L967
        for (int v526 = 0; v526 < 64; v526 += 1) {	// L968
          int8_t v527 = v521[v523][v526][1][v525];	// L969
          v521[v523][v526][0][v525] = v527;	// L970
          int8_t v528 = v521[v523][v526][2][v525];	// L971
          v521[v523][v526][1][v525] = v528;	// L972
          int8_t v529 = v512[v523][v526][v524][v525];	// L973
          v521[v523][v526][2][v525] = v529;	// L974
        }
        if ((v524 - 2) >= 0) {	// L976
          for (int v530 = 0; v530 < 64; v530 += 1) {	// L977
            for (int v531 = 0; v531 < 3; v531 += 1) {	// L978
              int8_t v532 = v522[v523][v530][v531][1];	// L979
              v522[v523][v530][v531][0] = v532;	// L980
              int8_t v533 = v522[v523][v530][v531][2];	// L981
              v522[v523][v530][v531][1] = v533;	// L982
              int8_t v534 = v521[v523][v530][v531][v525];	// L983
              v522[v523][v530][v531][2] = v534;	// L984
            }
          }
          if ((v525 - 2) >= 0) {	// L987
            int8_t v535[128];	// L988
            #pragma HLS bind_storage variable=v535 type=ram_2p impl=bram

            for (int v536 = 0; v536 < 128; v536 += 1) {	// L989
              v535[v536] = (int8_t)0.000000;	// L990
              for (int v537 = 0; v537 < 16; v537 += 1) {	// L991
                #pragma HLS pipeline II=1
                for (int v538 = 0; v538 < 4; v538 += 1) {	// L992
                  for (int v539 = 0; v539 < 3; v539 += 1) {	// L993
                    for (int v540 = 0; v540 < 3; v540 += 1) {	// L994
                      int8_t v541 = v522[v523][(v538 + (v537 * 4))][v539][v540];	// L995
                      int8_t v542 = v509[v536][(v538 + (v537 * 4))][v539][v540];	// L996
                      int8_t v543 = v541 * v542;	// L997
                      int8_t v544 = v535[v536];	// L998
                      int8_t v545 = v544 + v543;	// L999
                      v535[v536] = v545;	// L1000
                    }
                  }
                }
              }
              int8_t v546 = v535[v536];	// L1005
              v520[v523][v536][(v524 - 2)][(v525 - 2)] = v546;	// L1006
            }
          }
        }
      }
    }
  }
  for (int v547 = 0; v547 < 1; v547 += 1) {	// L1013
    for (int v548 = 0; v548 < 56; v548 += 1) {	// L1014
      for (int v549 = 0; v549 < 56; v549 += 1) {	// L1015
        for (int v550 = 0; v550 < 128; v550 += 1) {	// L1016
          int8_t v551 = v520[0][v550][v548][v549];	// L1017
          bool v552 = v551 > (int8_t)0.000000;	// L1018
          int8_t v553 = v552 ? v551 : (int8_t)0.000000;	// L1019
          v511[v547][v550][v548][v549] = v553;	// L1020
        }
      }
    }
  }
}

void main_graph_node15(
  int8_t v554[1][64][112][112],
  int8_t v555[1][64][56][56]
) {	// L1027
  #pragma HLS dataflow

  int8_t v556;	// L1030
  v556 = (int8_t)-INFINITY;	// L1031
  int8_t v557[1][64][112][112];	// L1032
  #pragma HLS bind_storage variable=v557 type=ram_2p impl=bram

  for (int v558 = 0; v558 < 1; v558 += 1) {	// L1033
    for (int v559 = 0; v559 < 112; v559 += 1) {	// L1034
      for (int v560 = 0; v560 < 112; v560 += 1) {	// L1035
        for (int v561 = 0; v561 < 64; v561 += 1) {	// L1036
          int8_t v562 = v554[v558][v561][v559][v560];	// L1037
          v557[v558][v561][v559][v560] = v562;	// L1038
        }
      }
    }
  }
  for (int v563 = 0; v563 < 1; v563 += 1) {	// L1043
    for (int v564 = 0; v564 < 56; v564 += 1) {	// L1044
      for (int v565 = 0; v565 < 56; v565 += 1) {	// L1045
        for (int v566 = 0; v566 < 64; v566 += 1) {	// L1046
          int8_t v567;	// L1047
          v567 = (int8_t)0.000000;	// L1048
          for (int v568 = 0; v568 < 2; v568 += 1) {	// L1049
            for (int v569 = 0; v569 < 2; v569 += 1) {	// L1050
              int8_t v570 = v557[v563][v566][((v564 * 2) + v568)][((v565 * 2) + v569)];	// L1051
              int8_t v571 = v556;	// L1052
              int8_t v572 = max(v571, v570);	// L1053
              v567 = v572;	// L1054
            }
          }
          int8_t v573 = v567;	// L1057
          v555[v563][v566][v564][v565] = v573;	// L1058
        }
      }
    }
  }
}

void main_graph_node16(
  int8_t v574[1][64][112][112],
  int8_t v575[64][64][3][3],
  int8_t v576[1][64][112][112]
) {	// L1065
  #pragma HLS dataflow

  int8_t v577[1][64][114][114];	// L1067
  #pragma HLS stream variable=v577 depth=10 type=fifo

  #pragma HLS bind_storage variable=v577 type=ram_t2p impl=bram

  for (int v578 = 0; v578 < 1; v578 += 1) {	// L1068
    for (int v579 = 0; v579 < 114; v579 += 1) {	// L1069
      for (int v580 = 0; v580 < 114; v580 += 1) {	// L1070
        for (int v581 = 0; v581 < 64; v581 += 1) {	// L1071
          int8_t v582;	// L1072
          v582 = (int8_t)0.000000;	// L1073
          if (((-v579) + 111) >= 0 && ((-v580) + 111) >= 0) {	// L1074
            int8_t v583 = v574[v578][v581][v579][v580];	// L1075
            v582 = v583;	// L1076
          }
          int8_t v584 = v582;	// L1078
          v577[v578][v581][v579][v580] = v584;	// L1079
        }
      }
    }
  }
  int8_t v585[1][64][112][112];	// L1084
  #pragma HLS stream variable=v585 depth=10 type=fifo

  #pragma HLS bind_storage variable=v585 type=ram_t2p impl=bram

  int8_t v586[1][64][3][114];	// L1085
  #pragma HLS array_partition variable=v586 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v586 type=ram_2p impl=bram

  int8_t v587[1][64][3][3];	// L1086
  #pragma HLS array_partition variable=v587 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v587 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v587 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v587 type=ram_2p impl=lutram

  for (int v588 = 0; v588 < 1; v588 += 1) {	// L1087
    for (int v589 = 0; v589 < 114; v589 += 1) {	// L1088
      for (int v590 = 0; v590 < 114; v590 += 1) {	// L1089
        for (int v591 = 0; v591 < 64; v591 += 1) {	// L1090
          int8_t v592 = v586[v588][v591][1][v590];	// L1091
          v586[v588][v591][0][v590] = v592;	// L1092
          int8_t v593 = v586[v588][v591][2][v590];	// L1093
          v586[v588][v591][1][v590] = v593;	// L1094
          int8_t v594 = v577[v588][v591][v589][v590];	// L1095
          v586[v588][v591][2][v590] = v594;	// L1096
        }
        if ((v589 - 2) >= 0) {	// L1098
          for (int v595 = 0; v595 < 64; v595 += 1) {	// L1099
            for (int v596 = 0; v596 < 3; v596 += 1) {	// L1100
              int8_t v597 = v587[v588][v595][v596][1];	// L1101
              v587[v588][v595][v596][0] = v597;	// L1102
              int8_t v598 = v587[v588][v595][v596][2];	// L1103
              v587[v588][v595][v596][1] = v598;	// L1104
              int8_t v599 = v586[v588][v595][v596][v590];	// L1105
              v587[v588][v595][v596][2] = v599;	// L1106
            }
          }
          if ((v590 - 2) >= 0) {	// L1109
            int8_t v600[64];	// L1110
            #pragma HLS bind_storage variable=v600 type=ram_2p impl=bram

            for (int v601 = 0; v601 < 64; v601 += 1) {	// L1111
              v600[v601] = (int8_t)0.000000;	// L1112
              for (int v602 = 0; v602 < 4; v602 += 1) {	// L1113
                #pragma HLS pipeline II=1
                for (int v603 = 0; v603 < 16; v603 += 1) {	// L1114
                  for (int v604 = 0; v604 < 3; v604 += 1) {	// L1115
                    for (int v605 = 0; v605 < 3; v605 += 1) {	// L1116
                      int8_t v606 = v587[v588][(v603 + (v602 * 16))][v604][v605];	// L1117
                      int8_t v607 = v575[v601][(v603 + (v602 * 16))][v604][v605];	// L1118
                      int8_t v608 = v606 * v607;	// L1119
                      int8_t v609 = v600[v601];	// L1120
                      int8_t v610 = v609 + v608;	// L1121
                      v600[v601] = v610;	// L1122
                    }
                  }
                }
              }
              int8_t v611 = v600[v601];	// L1127
              v585[v588][v601][(v589 - 2)][(v590 - 2)] = v611;	// L1128
            }
          }
        }
      }
    }
  }
  for (int v612 = 0; v612 < 1; v612 += 1) {	// L1135
    for (int v613 = 0; v613 < 112; v613 += 1) {	// L1136
      for (int v614 = 0; v614 < 112; v614 += 1) {	// L1137
        for (int v615 = 0; v615 < 64; v615 += 1) {	// L1138
          int8_t v616 = v585[0][v615][v613][v614];	// L1139
          bool v617 = v616 > (int8_t)0.000000;	// L1140
          int8_t v618 = v617 ? v616 : (int8_t)0.000000;	// L1141
          v576[v612][v615][v613][v614] = v618;	// L1142
        }
      }
    }
  }
}

void main_graph_node17(
  int8_t v619[1][32][112][112],
  int8_t v620[64][32][3][3],
  int8_t v621[1][64][112][112]
) {	// L1149
  #pragma HLS dataflow

  int8_t v622[1][32][114][114];	// L1151
  #pragma HLS stream variable=v622 depth=10 type=fifo

  #pragma HLS bind_storage variable=v622 type=ram_t2p impl=bram

  for (int v623 = 0; v623 < 1; v623 += 1) {	// L1152
    for (int v624 = 0; v624 < 114; v624 += 1) {	// L1153
      for (int v625 = 0; v625 < 114; v625 += 1) {	// L1154
        for (int v626 = 0; v626 < 32; v626 += 1) {	// L1155
          int8_t v627;	// L1156
          v627 = (int8_t)0.000000;	// L1157
          if (((-v624) + 111) >= 0 && ((-v625) + 111) >= 0) {	// L1158
            int8_t v628 = v619[v623][v626][v624][v625];	// L1159
            v627 = v628;	// L1160
          }
          int8_t v629 = v627;	// L1162
          v622[v623][v626][v624][v625] = v629;	// L1163
        }
      }
    }
  }
  int8_t v630[1][64][112][112];	// L1168
  #pragma HLS stream variable=v630 depth=10 type=fifo

  #pragma HLS bind_storage variable=v630 type=ram_t2p impl=bram

  int8_t v631[1][32][3][114];	// L1169
  #pragma HLS array_partition variable=v631 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v631 type=ram_2p impl=bram

  int8_t v632[1][32][3][3];	// L1170
  #pragma HLS array_partition variable=v632 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v632 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v632 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v632 type=ram_2p impl=lutram

  for (int v633 = 0; v633 < 1; v633 += 1) {	// L1171
    for (int v634 = 0; v634 < 114; v634 += 1) {	// L1172
      for (int v635 = 0; v635 < 114; v635 += 1) {	// L1173
        for (int v636 = 0; v636 < 32; v636 += 1) {	// L1174
          int8_t v637 = v631[v633][v636][1][v635];	// L1175
          v631[v633][v636][0][v635] = v637;	// L1176
          int8_t v638 = v631[v633][v636][2][v635];	// L1177
          v631[v633][v636][1][v635] = v638;	// L1178
          int8_t v639 = v622[v633][v636][v634][v635];	// L1179
          v631[v633][v636][2][v635] = v639;	// L1180
        }
        if ((v634 - 2) >= 0) {	// L1182
          for (int v640 = 0; v640 < 32; v640 += 1) {	// L1183
            for (int v641 = 0; v641 < 3; v641 += 1) {	// L1184
              int8_t v642 = v632[v633][v640][v641][1];	// L1185
              v632[v633][v640][v641][0] = v642;	// L1186
              int8_t v643 = v632[v633][v640][v641][2];	// L1187
              v632[v633][v640][v641][1] = v643;	// L1188
              int8_t v644 = v631[v633][v640][v641][v635];	// L1189
              v632[v633][v640][v641][2] = v644;	// L1190
            }
          }
          if ((v635 - 2) >= 0) {	// L1193
            int8_t v645[64];	// L1194
            #pragma HLS bind_storage variable=v645 type=ram_2p impl=bram

            for (int v646 = 0; v646 < 64; v646 += 1) {	// L1195
              v645[v646] = (int8_t)0.000000;	// L1196
              for (int v647 = 0; v647 < 4; v647 += 1) {	// L1197
                #pragma HLS pipeline II=1
                for (int v648 = 0; v648 < 8; v648 += 1) {	// L1198
                  for (int v649 = 0; v649 < 3; v649 += 1) {	// L1199
                    for (int v650 = 0; v650 < 3; v650 += 1) {	// L1200
                      int8_t v651 = v632[v633][(v648 + (v647 * 8))][v649][v650];	// L1201
                      int8_t v652 = v620[v646][(v648 + (v647 * 8))][v649][v650];	// L1202
                      int8_t v653 = v651 * v652;	// L1203
                      int8_t v654 = v645[v646];	// L1204
                      int8_t v655 = v654 + v653;	// L1205
                      v645[v646] = v655;	// L1206
                    }
                  }
                }
              }
              int8_t v656 = v645[v646];	// L1211
              v630[v633][v646][(v634 - 2)][(v635 - 2)] = v656;	// L1212
            }
          }
        }
      }
    }
  }
  for (int v657 = 0; v657 < 1; v657 += 1) {	// L1219
    for (int v658 = 0; v658 < 112; v658 += 1) {	// L1220
      for (int v659 = 0; v659 < 112; v659 += 1) {	// L1221
        for (int v660 = 0; v660 < 64; v660 += 1) {	// L1222
          int8_t v661 = v630[0][v660][v658][v659];	// L1223
          bool v662 = v661 > (int8_t)0.000000;	// L1224
          int8_t v663 = v662 ? v661 : (int8_t)0.000000;	// L1225
          v621[v657][v660][v658][v659] = v663;	// L1226
        }
      }
    }
  }
}

void main_graph_node18(
  int8_t v664[1][32][224][224],
  int8_t v665[1][32][112][112]
) {	// L1233
  #pragma HLS dataflow

  int8_t v666;	// L1236
  v666 = (int8_t)-INFINITY;	// L1237
  int8_t v667[1][32][224][224];	// L1238
  #pragma HLS bind_storage variable=v667 type=ram_2p impl=bram

  for (int v668 = 0; v668 < 1; v668 += 1) {	// L1239
    for (int v669 = 0; v669 < 224; v669 += 1) {	// L1240
      for (int v670 = 0; v670 < 224; v670 += 1) {	// L1241
        for (int v671 = 0; v671 < 32; v671 += 1) {	// L1242
          int8_t v672 = v664[v668][v671][v669][v670];	// L1243
          v667[v668][v671][v669][v670] = v672;	// L1244
        }
      }
    }
  }
  for (int v673 = 0; v673 < 1; v673 += 1) {	// L1249
    for (int v674 = 0; v674 < 112; v674 += 1) {	// L1250
      for (int v675 = 0; v675 < 112; v675 += 1) {	// L1251
        for (int v676 = 0; v676 < 32; v676 += 1) {	// L1252
          int8_t v677;	// L1253
          v677 = (int8_t)0.000000;	// L1254
          for (int v678 = 0; v678 < 2; v678 += 1) {	// L1255
            for (int v679 = 0; v679 < 2; v679 += 1) {	// L1256
              int8_t v680 = v667[v673][v676][((v674 * 2) + v678)][((v675 * 2) + v679)];	// L1257
              int8_t v681 = v666;	// L1258
              int8_t v682 = max(v681, v680);	// L1259
              v677 = v682;	// L1260
            }
          }
          int8_t v683 = v677;	// L1263
          v665[v673][v676][v674][v675] = v683;	// L1264
        }
      }
    }
  }
}

void main_graph_node19(
  int8_t v684[32][32][3][3],
  int8_t v685[1][32][224][224],
  int8_t v686[1][32][224][224]
) {	// L1271
  #pragma HLS dataflow

  int8_t v687[1][32][226][226];	// L1273
  #pragma HLS stream variable=v687 depth=10 type=fifo

  #pragma HLS bind_storage variable=v687 type=ram_t2p impl=bram

  for (int v688 = 0; v688 < 1; v688 += 1) {	// L1274
    for (int v689 = 0; v689 < 226; v689 += 1) {	// L1275
      for (int v690 = 0; v690 < 226; v690 += 1) {	// L1276
        for (int v691 = 0; v691 < 32; v691 += 1) {	// L1277
          int8_t v692;	// L1278
          v692 = (int8_t)0.000000;	// L1279
          if (((-v689) + 223) >= 0 && ((-v690) + 223) >= 0) {	// L1280
            int8_t v693 = v685[v688][v691][v689][v690];	// L1281
            v692 = v693;	// L1282
          }
          int8_t v694 = v692;	// L1284
          v687[v688][v691][v689][v690] = v694;	// L1285
        }
      }
    }
  }
  int8_t v695[1][32][224][224];	// L1290
  #pragma HLS stream variable=v695 depth=10 type=fifo

  #pragma HLS bind_storage variable=v695 type=ram_t2p impl=bram

  int8_t v696[1][32][3][226];	// L1291
  #pragma HLS array_partition variable=v696 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v696 type=ram_2p impl=bram

  int8_t v697[1][32][3][3];	// L1292
  #pragma HLS array_partition variable=v697 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v697 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v697 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v697 type=ram_2p impl=lutram

  for (int v698 = 0; v698 < 1; v698 += 1) {	// L1293
    for (int v699 = 0; v699 < 226; v699 += 1) {	// L1294
      for (int v700 = 0; v700 < 226; v700 += 1) {	// L1295
        for (int v701 = 0; v701 < 32; v701 += 1) {	// L1296
          int8_t v702 = v696[v698][v701][1][v700];	// L1297
          v696[v698][v701][0][v700] = v702;	// L1298
          int8_t v703 = v696[v698][v701][2][v700];	// L1299
          v696[v698][v701][1][v700] = v703;	// L1300
          int8_t v704 = v687[v698][v701][v699][v700];	// L1301
          v696[v698][v701][2][v700] = v704;	// L1302
        }
        if ((v699 - 2) >= 0) {	// L1304
          for (int v705 = 0; v705 < 32; v705 += 1) {	// L1305
            for (int v706 = 0; v706 < 3; v706 += 1) {	// L1306
              int8_t v707 = v697[v698][v705][v706][1];	// L1307
              v697[v698][v705][v706][0] = v707;	// L1308
              int8_t v708 = v697[v698][v705][v706][2];	// L1309
              v697[v698][v705][v706][1] = v708;	// L1310
              int8_t v709 = v696[v698][v705][v706][v700];	// L1311
              v697[v698][v705][v706][2] = v709;	// L1312
            }
          }
          if ((v700 - 2) >= 0) {	// L1315
            int8_t v710[32];	// L1316
            #pragma HLS bind_storage variable=v710 type=ram_2p impl=bram

            for (int v711 = 0; v711 < 32; v711 += 1) {	// L1317
              v710[v711] = (int8_t)0.000000;	// L1318
              for (int v712 = 0; v712 < 2; v712 += 1) {	// L1319
                #pragma HLS pipeline II=1
                for (int v713 = 0; v713 < 16; v713 += 1) {	// L1320
                  for (int v714 = 0; v714 < 3; v714 += 1) {	// L1321
                    for (int v715 = 0; v715 < 3; v715 += 1) {	// L1322
                      int8_t v716 = v697[v698][(v713 + (v712 * 16))][v714][v715];	// L1323
                      int8_t v717 = v684[v711][(v713 + (v712 * 16))][v714][v715];	// L1324
                      int8_t v718 = v716 * v717;	// L1325
                      int8_t v719 = v710[v711];	// L1326
                      int8_t v720 = v719 + v718;	// L1327
                      v710[v711] = v720;	// L1328
                    }
                  }
                }
              }
              int8_t v721 = v710[v711];	// L1333
              v695[v698][v711][(v699 - 2)][(v700 - 2)] = v721;	// L1334
            }
          }
        }
      }
    }
  }
  for (int v722 = 0; v722 < 1; v722 += 1) {	// L1341
    for (int v723 = 0; v723 < 224; v723 += 1) {	// L1342
      for (int v724 = 0; v724 < 224; v724 += 1) {	// L1343
        for (int v725 = 0; v725 < 32; v725 += 1) {	// L1344
          int8_t v726 = v695[0][v725][v723][v724];	// L1345
          bool v727 = v726 > (int8_t)0.000000;	// L1346
          int8_t v728 = v727 ? v726 : (int8_t)0.000000;	// L1347
          v686[v722][v725][v723][v724] = v728;	// L1348
        }
      }
    }
  }
}

void main_graph_node20(
  int8_t v729[1][3][224][224],
  int8_t v730[32][3][3][3],
  int8_t v731[1][32][224][224]
) {	// L1355
  #pragma HLS dataflow

  int8_t v732[1][3][226][226];	// L1357
  #pragma HLS stream variable=v732 depth=10 type=fifo

  #pragma HLS bind_storage variable=v732 type=ram_t2p impl=bram

  for (int v733 = 0; v733 < 1; v733 += 1) {	// L1358
    for (int v734 = 0; v734 < 226; v734 += 1) {	// L1359
      for (int v735 = 0; v735 < 226; v735 += 1) {	// L1360
        for (int v736 = 0; v736 < 3; v736 += 1) {	// L1361
          int8_t v737;	// L1362
          v737 = (int8_t)0.000000;	// L1363
          if (((-v734) + 223) >= 0 && ((-v735) + 223) >= 0) {	// L1364
            int8_t v738 = v729[v733][v736][v734][v735];	// L1365
            v737 = v738;	// L1366
          }
          int8_t v739 = v737;	// L1368
          v732[v733][v736][v734][v735] = v739;	// L1369
        }
      }
    }
  }
  int8_t v740[1][32][224][224];	// L1374
  #pragma HLS stream variable=v740 depth=10 type=fifo

  #pragma HLS bind_storage variable=v740 type=ram_t2p impl=bram

  int8_t v741[1][3][3][226];	// L1375
  #pragma HLS array_partition variable=v741 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v741 type=ram_2p impl=lutram

  int8_t v742[1][3][3][3];	// L1376
  #pragma HLS array_partition variable=v742 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v742 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v742 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v742 type=ram_2p impl=lutram

  for (int v743 = 0; v743 < 1; v743 += 1) {	// L1377
    for (int v744 = 0; v744 < 226; v744 += 1) {	// L1378
      for (int v745 = 0; v745 < 226; v745 += 1) {	// L1379
        for (int v746 = 0; v746 < 3; v746 += 1) {	// L1380
          int8_t v747 = v741[v743][v746][1][v745];	// L1381
          v741[v743][v746][0][v745] = v747;	// L1382
          int8_t v748 = v741[v743][v746][2][v745];	// L1383
          v741[v743][v746][1][v745] = v748;	// L1384
          int8_t v749 = v732[v743][v746][v744][v745];	// L1385
          v741[v743][v746][2][v745] = v749;	// L1386
        }
        if ((v744 - 2) >= 0) {	// L1388
          for (int v750 = 0; v750 < 3; v750 += 1) {	// L1389
            for (int v751 = 0; v751 < 3; v751 += 1) {	// L1390
              int8_t v752 = v742[v743][v750][v751][1];	// L1391
              v742[v743][v750][v751][0] = v752;	// L1392
              int8_t v753 = v742[v743][v750][v751][2];	// L1393
              v742[v743][v750][v751][1] = v753;	// L1394
              int8_t v754 = v741[v743][v750][v751][v745];	// L1395
              v742[v743][v750][v751][2] = v754;	// L1396
            }
          }
          if ((v745 - 2) >= 0) {	// L1399
            int8_t v755[32];	// L1400
            #pragma HLS bind_storage variable=v755 type=ram_2p impl=bram

            for (int v756 = 0; v756 < 32; v756 += 1) {	// L1401
              #pragma HLS pipeline II=1
              for (int v757 = 0; v757 < 1; v757 += 1) {	// L1402
                v755[(v756 + v757)] = (int8_t)0.000000;	// L1403
                for (int v758 = 0; v758 < 3; v758 += 1) {	// L1404
                  for (int v759 = 0; v759 < 3; v759 += 1) {	// L1405
                    for (int v760 = 0; v760 < 3; v760 += 1) {	// L1406
                      int8_t v761 = v742[v743][v758][v759][v760];	// L1407
                      int8_t v762 = v730[(v756 + v757)][v758][v759][v760];	// L1408
                      int8_t v763 = v761 * v762;	// L1409
                      int8_t v764 = v755[(v756 + v757)];	// L1410
                      int8_t v765 = v764 + v763;	// L1411
                      v755[(v756 + v757)] = v765;	// L1412
                    }
                  }
                }
                int8_t v766 = v755[(v756 + v757)];	// L1416
                v740[v743][(v756 + v757)][(v744 - 2)][(v745 - 2)] = v766;	// L1417
              }
            }
          }
        }
      }
    }
  }
  for (int v767 = 0; v767 < 1; v767 += 1) {	// L1425
    for (int v768 = 0; v768 < 224; v768 += 1) {	// L1426
      for (int v769 = 0; v769 < 224; v769 += 1) {	// L1427
        for (int v770 = 0; v770 < 32; v770 += 1) {	// L1428
          int8_t v771 = v740[0][v770][v768][v769];	// L1429
          bool v772 = v771 > (int8_t)0.000000;	// L1430
          int8_t v773 = v772 ? v771 : (int8_t)0.000000;	// L1431
          v731[v767][v770][v768][v769] = v773;	// L1432
        }
      }
    }
  }
}
void load_array(
    int8_t v774[1][3][224][224],ap_uint<256> *vv774,
    int8_t v775[1000],ap_uint<256> *vv775,
    int8_t v776[2048],ap_uint<256> *vv776,
    int8_t v777[2048][512][7][7],ap_uint<256> *vv777,
    int8_t v778[512][512][3][3],ap_uint<256> *vv778,
    int8_t v779[512][512][3][3],ap_uint<256> *vv779,
    int8_t v780[512][256][3][3],ap_uint<256> *vv780,
    int8_t v781[256][256][3][3],ap_uint<256> *vv781,
    int8_t v782[256][256][3][3],ap_uint<256> *vv782,
    int8_t v783[256][128][3][3],ap_uint<256> *vv783,
    int8_t v784[128][128][3][3],ap_uint<256> *vv784,
    int8_t v785[128][128][3][3],ap_uint<256> *vv785,
    int8_t v786[128][64][3][3],ap_uint<256> *vv786,
    int8_t v787[64][64][3][3],ap_uint<256> *vv787,
    int8_t v788[64][32][3][3],ap_uint<256> *vv788,
    int8_t v789[32][32][3][3],ap_uint<256> *vv789,
    int8_t v790[32][3][3][3],ap_uint<256> *vv790,
    int8_t v791[2048][2048],ap_uint<256> *vv791,
    int8_t v792[2048][1000],ap_uint<256> *vv792,
    int8_t v793[1][1000],ap_uint<256> *vv793
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
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 224; ++k) {
              for (int l = 0; l < 7; ++l) {
              temp_0 = vv774[i * 3 * 224 * 7 + j * 224 * 7 + k * 7 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v774[i][j][k][l * 32 + bias] = temp_0.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 31; ++i) { 
      temp_1 = vv775[i];
      for (int bias = 0; bias < 32; ++bias) { 
                    v775[i * 32 + bias] = temp_1.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 64; ++i) { 
      temp_2 = vv776[i];
      for (int bias = 0; bias < 32; ++bias) { 
                    v776[i * 32 + bias] = temp_2.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 2048; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 7; ++k) {
              for (int l = 0; l < 7; ++l) {
              temp_3 = vv777[i * 16 * 7 * 7 + j * 7 * 7 + k * 7 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v777[i][j * 32 + bias][k][l] = temp_3.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_4 = vv778[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v778[i][j * 32 + bias][k][l] = temp_4.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_5 = vv779[i * 16 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v779[i][j * 32 + bias][k][l] = temp_5.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 512; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_6 = vv780[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v780[i][j * 32 + bias][k][l] = temp_6.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_7 = vv781[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v781[i][j * 32 + bias][k][l] = temp_7.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_8 = vv782[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v782[i][j * 32 + bias][k][l] = temp_8.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_9 = vv783[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v783[i][j * 32 + bias][k][l] = temp_9.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_10 = vv784[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v784[i][j * 32 + bias][k][l] = temp_10.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_11 = vv785[i * 4 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v785[i][j * 32 + bias][k][l] = temp_11.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 128; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_12 = vv786[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v786[i][j * 32 + bias][k][l] = temp_12.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_13 = vv787[i * 2 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v787[i][j * 32 + bias][k][l] = temp_13.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 64; ++i) {
      for (int j = 0; j < 1; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_14 = vv788[i * 1 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v788[i][j * 32 + bias][k][l] = temp_14.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 32; ++i) {
      for (int j = 0; j < 1; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_15 = vv789[i * 1 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v789[i][j * 32 + bias][k][l] = temp_15.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_16 = vv790[i * 3 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v790[i * 32 + bias][j][k][l] = temp_16.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 2048; ++i) {
      for (int j = 0; j < 64; ++j) {
          temp_17 = vv791[i * 64 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v791[i][j * 32 + bias] = temp_17.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 2048; ++i) {
      for (int j = 0; j < 31; ++j) {
          temp_18 = vv792[i * 31 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v792[i][j * 32 + bias] = temp_18.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 31; ++j) {
          temp_19 = vv793[i * 31 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v793[i][j * 32 + bias] = temp_19.range(bias*8+7, bias*8);
}
}
}
}



/// This is top function.
void main_graph(
    ap_uint<256> *vv774,
    ap_uint<256> *vv775,
    ap_uint<256> *vv776,
    ap_uint<256> *vv777,
    ap_uint<256> *vv778,
    ap_uint<256> *vv779,
    ap_uint<256> *vv780,
    ap_uint<256> *vv781,
    ap_uint<256> *vv782,
    ap_uint<256> *vv783,
    ap_uint<256> *vv784,
    ap_uint<256> *vv785,
    ap_uint<256> *vv786,
    ap_uint<256> *vv787,
    ap_uint<256> *vv788,
    ap_uint<256> *vv789,
    ap_uint<256> *vv790,
    ap_uint<256> *vv791,
    ap_uint<256> *vv792,
    ap_uint<256> *vv793

) {	// L1439
  #pragma HLS interface s_axilite port=return 
  #pragma HLS INTERFACE m_axi port=vv774 offset = slave bundle=gmem0
  #pragma HLS INTERFACE m_axi port=vv775 offset = slave bundle=gmem1
  #pragma HLS INTERFACE m_axi port=vv776 offset = slave bundle=gmem2
  #pragma HLS INTERFACE m_axi port=vv777 offset = slave bundle=gmem3
  #pragma HLS INTERFACE m_axi port=vv778 offset = slave bundle=gmem4
  #pragma HLS INTERFACE m_axi port=vv779 offset = slave bundle=gmem5
  #pragma HLS INTERFACE m_axi port=vv780 offset = slave bundle=gmem6
  #pragma HLS INTERFACE m_axi port=vv781 offset = slave bundle=gmem7
  #pragma HLS INTERFACE m_axi port=vv782 offset = slave bundle=gmem8
  #pragma HLS INTERFACE m_axi port=vv783 offset = slave bundle=gmem9
  #pragma HLS INTERFACE m_axi port=vv784 offset = slave bundle=gmem10
  #pragma HLS INTERFACE m_axi port=vv785 offset = slave bundle=gmem11
  #pragma HLS INTERFACE m_axi port=vv786 offset = slave bundle=gmem12
  #pragma HLS INTERFACE m_axi port=vv787 offset = slave bundle=gmem13
  #pragma HLS INTERFACE m_axi port=vv788 offset = slave bundle=gmem14
  #pragma HLS INTERFACE m_axi port=vv789 offset = slave bundle=gmem15
  #pragma HLS INTERFACE m_axi port=vv790 offset = slave bundle=gmem16
  #pragma HLS INTERFACE m_axi port=vv791 offset = slave bundle=gmem17
  #pragma HLS INTERFACE m_axi port=vv792 offset = slave bundle=gmem18
  #pragma HLS INTERFACE m_axi port=vv793 offset = slave bundle=gmem19


  int8_t v774[1][3][224][224];
  int8_t v775[1000];
  int8_t v776[2048];
  int8_t v777[2048][512][7][7];
  int8_t v778[512][512][3][3];
  int8_t v779[512][512][3][3];
  int8_t v780[512][256][3][3];
  int8_t v781[256][256][3][3];
  int8_t v782[256][256][3][3];
  int8_t v783[256][128][3][3];
  int8_t v784[128][128][3][3];
  int8_t v785[128][128][3][3];
  int8_t v786[128][64][3][3];
  int8_t v787[64][64][3][3];
  int8_t v788[64][32][3][3];
  int8_t v789[32][32][3][3];
  int8_t v790[32][3][3][3];
  int8_t v791[2048][2048];
  int8_t v792[2048][1000];
  int8_t v793[1][1000];
  #pragma HLS interface bram port=v774
  #pragma HLS bind_storage variable=v774 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v775
  #pragma HLS bind_storage variable=v775 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v776
  #pragma HLS bind_storage variable=v776 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v777
  #pragma HLS array_partition variable=v777 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v777 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v777 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v777 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v778
  #pragma HLS array_partition variable=v778 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v778 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v778 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v778 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v779
  #pragma HLS array_partition variable=v779 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v779 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v779 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v779 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v780
  #pragma HLS array_partition variable=v780 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v780 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v780 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v780 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v781
  #pragma HLS array_partition variable=v781 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v781 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v781 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v781 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v782
  #pragma HLS array_partition variable=v782 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v782 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v782 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v782 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v783
  #pragma HLS array_partition variable=v783 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v783 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v783 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v783 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v784
  #pragma HLS array_partition variable=v784 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v784 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v784 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v784 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v785
  #pragma HLS array_partition variable=v785 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v785 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v785 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v785 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v786
  #pragma HLS array_partition variable=v786 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v786 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v786 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v786 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v787
  #pragma HLS array_partition variable=v787 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v787 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v787 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v787 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v788
  #pragma HLS array_partition variable=v788 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v788 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v788 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v788 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v789
  #pragma HLS array_partition variable=v789 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v789 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v789 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v789 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v790
  #pragma HLS array_partition variable=v790 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v790 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v790 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v790 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v791
  #pragma HLS bind_storage variable=v791 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v792
  #pragma HLS bind_storage variable=v792 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v793
  #pragma HLS bind_storage variable=v793 type=ram_t2p impl=bram

load_array(
        v774,vv774,
        v775,vv775,
        v776,vv776,
        v777,vv777,
        v778,vv778,
        v779,vv779,
        v780,vv780,
        v781,vv781,
        v782,vv782,
        v783,vv783,
        v784,vv784,
        v785,vv785,
        v786,vv786,
        v787,vv787,
        v788,vv788,
        v789,vv789,
        v790,vv790,
        v791,vv791,
        v792,vv792,
        v793,vv793
    );

  // func(
  //     v774,
  //     v775,
  //     v776,
  //     v777,
  //     v778,
  //     v779,
  //     v780,
  //     v781,
  //     v782,
  //     v783,
  //     v784,
  //     v785,
  //     v786,
  //     v787,
  //     v788,
  //     v789,
  //     v790,
  //     v791,
  //     v792,
  //     v793);
}

