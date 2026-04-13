
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
  int8_t v0[1][1470],
  int8_t v1[1470],
  int8_t v2[1][1470]
) {	// L13
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L14
    for (int v4 = 0; v4 < 1470; v4 += 1) {	// L15
      int8_t v5 = v0[0][v4];	// L16
      int8_t v6 = v1[v4];	// L17
      int8_t v7 = v5 + v6;	// L18
      v2[v3][v4] = v7;	// L19
    }
  }
  return ;	// L22
}

void main_graph_node1(
  int8_t v8[1][4096],
  int8_t v9[4096][1470],
  int8_t v10[1][1470]
) {	// L24
  #pragma HLS dataflow

  int8_t v11[1][1470];	// L26
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L27
    for (int v13 = 0; v13 < 1470; v13 += 1) {	// L28
      v11[v12][v13] = (int8_t)0.000000;	// L29
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L32
    for (int v15 = 0; v15 < 1470; v15 += 1) {	// L33
      for (int v16 = 0; v16 < 4096; v16 += 1) {	// L34
        int8_t v17 = v8[v14][v16];	// L35
        int8_t v18 = v9[v16][v15];	// L36
        int8_t v19 = v11[v14][v15];	// L37
        int8_t v20 = v17 * v18;	// L38
        int8_t v21 = v19 + v20;	// L39
        v10[v14][v15] = v21;	// L40
      }
    }
  }
  return ;	// L44
}

void main_graph_node2(
  int8_t v22[1][4096],
  int8_t v23[4096],
  int8_t v24[1][4096]
) {	// L46
  #pragma HLS dataflow

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L48
    for (int v26 = 0; v26 < 4096; v26 += 1) {	// L49
      int8_t v27 = v22[0][v26];	// L50
      int8_t v28 = v23[v26];	// L51
      int8_t v29 = v27 + v28;	// L52
      bool v30 = v29 > (int8_t)0.000000;	// L53
      int8_t v31 = v30 ? v29 : (int8_t)0.000000;	// L54
      v24[v25][v26] = v31;	// L55
    }
  }
  return ;	// L58
}

void main_graph_node3(
  int8_t v32[1][256][1][1],
  int8_t v33[256][4096],
  int8_t v34[1][4096]
) {	// L60
  #pragma HLS dataflow

  int8_t v35[1][4096];	// L62
  #pragma HLS bind_storage variable=v35 type=ram_t2p impl=bram

  for (int v36 = 0; v36 < 1; v36 += 1) {	// L63
    for (int v37 = 0; v37 < 4096; v37 += 1) {	// L64
      v35[v36][v37] = (int8_t)0.000000;	// L65
    }
  }
  for (int v38 = 0; v38 < 1; v38 += 1) {	// L68
    for (int v39 = 0; v39 < 4096; v39 += 1) {	// L69
      for (int v40 = 0; v40 < 256; v40 += 1) {	// L70
        int8_t v41 = v32[v38][v40][0][0];	// L71
        int8_t v42 = v33[v40][v39];	// L72
        int8_t v43 = v35[v38][v39];	// L73
        int8_t v44 = v41 * v42;	// L74
        int8_t v45 = v43 + v44;	// L75
        v34[v38][v39] = v45;	// L76
      }
    }
  }
  return ;	// L80
}

void main_graph_node4(
  int8_t v46[256][1024][20][6],
  int8_t v47[1][1024][20][6],
  int8_t v48[1][256][1][1]
) {	// L82
  #pragma HLS dataflow

  int8_t v49[1][1024][20][6];	// L84
  #pragma HLS array_partition variable=v49 cyclic factor=20 dim=3
  #pragma HLS bind_storage variable=v49 type=ram_2p impl=bram

  int8_t v50[1][1024][20][6];	// L85
  #pragma HLS array_partition variable=v50 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v50 cyclic factor=20 dim=3
  #pragma HLS array_partition variable=v50 cyclic factor=6 dim=4
  #pragma HLS bind_storage variable=v50 type=ram_2p impl=lutram

  for (int v51 = 0; v51 < 1; v51 += 1) {	// L86
    for (int v52 = 0; v52 < 20; v52 += 1) {	// L87
      for (int v53 = 0; v53 < 6; v53 += 1) {	// L88
        for (int v54 = 0; v54 < 1024; v54 += 1) {	// L89
          int8_t v55 = v49[v51][v54][1][v53];	// L90
          v49[v51][v54][0][v53] = v55;	// L91
          int8_t v56 = v49[v51][v54][2][v53];	// L92
          v49[v51][v54][1][v53] = v56;	// L93
          int8_t v57 = v49[v51][v54][3][v53];	// L94
          v49[v51][v54][2][v53] = v57;	// L95
          int8_t v58 = v49[v51][v54][4][v53];	// L96
          v49[v51][v54][3][v53] = v58;	// L97
          int8_t v59 = v49[v51][v54][5][v53];	// L98
          v49[v51][v54][4][v53] = v59;	// L99
          int8_t v60 = v49[v51][v54][6][v53];	// L100
          v49[v51][v54][5][v53] = v60;	// L101
          int8_t v61 = v49[v51][v54][7][v53];	// L102
          v49[v51][v54][6][v53] = v61;	// L103
          int8_t v62 = v49[v51][v54][8][v53];	// L104
          v49[v51][v54][7][v53] = v62;	// L105
          int8_t v63 = v49[v51][v54][9][v53];	// L106
          v49[v51][v54][8][v53] = v63;	// L107
          int8_t v64 = v49[v51][v54][10][v53];	// L108
          v49[v51][v54][9][v53] = v64;	// L109
          int8_t v65 = v49[v51][v54][11][v53];	// L110
          v49[v51][v54][10][v53] = v65;	// L111
          int8_t v66 = v49[v51][v54][12][v53];	// L112
          v49[v51][v54][11][v53] = v66;	// L113
          int8_t v67 = v49[v51][v54][13][v53];	// L114
          v49[v51][v54][12][v53] = v67;	// L115
          int8_t v68 = v49[v51][v54][14][v53];	// L116
          v49[v51][v54][13][v53] = v68;	// L117
          int8_t v69 = v49[v51][v54][15][v53];	// L118
          v49[v51][v54][14][v53] = v69;	// L119
          int8_t v70 = v49[v51][v54][16][v53];	// L120
          v49[v51][v54][15][v53] = v70;	// L121
          int8_t v71 = v49[v51][v54][17][v53];	// L122
          v49[v51][v54][16][v53] = v71;	// L123
          int8_t v72 = v49[v51][v54][18][v53];	// L124
          v49[v51][v54][17][v53] = v72;	// L125
          int8_t v73 = v49[v51][v54][19][v53];	// L126
          v49[v51][v54][18][v53] = v73;	// L127
          int8_t v74 = v47[v51][(v54 / 0)][0][0];	// L128
          v49[v51][v54][19][v53] = v74;	// L129
        }
        if ((v52 - 19) >= 0) {	// L131
          for (int v75 = 0; v75 < 1024; v75 += 1) {	// L132
            for (int v76 = 0; v76 < 20; v76 += 1) {	// L133
              int8_t v77 = v50[v51][v75][v76][1];	// L134
              v50[v51][v75][v76][0] = v77;	// L135
              int8_t v78 = v50[v51][v75][v76][2];	// L136
              v50[v51][v75][v76][1] = v78;	// L137
              int8_t v79 = v50[v51][v75][v76][3];	// L138
              v50[v51][v75][v76][2] = v79;	// L139
              int8_t v80 = v50[v51][v75][v76][4];	// L140
              v50[v51][v75][v76][3] = v80;	// L141
              int8_t v81 = v50[v51][v75][v76][5];	// L142
              v50[v51][v75][v76][4] = v81;	// L143
              int8_t v82 = v49[v51][v75][v76][v53];	// L144
              v50[v51][v75][v76][5] = v82;	// L145
            }
          }
          if ((v53 - 5) >= 0) {	// L148
            int8_t v83[256];	// L149
            #pragma HLS bind_storage variable=v83 type=ram_2p impl=bram

            for (int v84 = 0; v84 < 256; v84 += 1) {	// L150
              v83[v84] = (int8_t)0.000000;	// L151
              for (int v85 = 0; v85 < 256; v85 += 1) {	// L152
                #pragma HLS pipeline II=1
                for (int v86 = 0; v86 < 4; v86 += 1) {	// L153
                  for (int v87 = 0; v87 < 20; v87 += 1) {	// L154
                    for (int v88 = 0; v88 < 6; v88 += 1) {	// L155
                      int8_t v89 = v50[v51][(v86 + (v85 * 4))][v87][v88];	// L156
                      int8_t v90 = v46[v84][(v86 + (v85 * 4))][v87][v88];	// L157
                      int8_t v91 = v89 * v90;	// L158
                      int8_t v92 = v83[v84];	// L159
                      int8_t v93 = v92 + v91;	// L160
                      v83[v84] = v93;	// L161
                    }
                  }
                }
              }
              int8_t v94 = v83[v84];	// L166
              v48[v51][v84][(v52 - 19)][(v53 - 19)] = v94;	// L167
            }
          }
        }
      }
    }
  }
  return ;	// L174
}

void main_graph_node5(
  int8_t v95[1024][1024][3][3],
  int8_t v96[1][1024][20][6],
  int8_t v97[1][1024][20][6]
) {	// L176
  #pragma HLS dataflow

  int8_t v98[1][1024][22][8];	// L178
  #pragma HLS stream variable=v98 depth=10 type=fifo

  #pragma HLS bind_storage variable=v98 type=ram_t2p impl=bram

  for (int v99 = 0; v99 < 1; v99 += 1) {	// L179
    for (int v100 = 0; v100 < 22; v100 += 1) {	// L180
      for (int v101 = 0; v101 < 8; v101 += 1) {	// L181
        for (int v102 = 0; v102 < 1024; v102 += 1) {	// L182
          int8_t v103;	// L183
          v103 = (int8_t)0.000000;	// L184
          if (((-v100) + 19) >= 0 && ((-v101) + 5) >= 0) {	// L185
            int8_t v104 = v96[v99][v102][v100][v101];	// L186
            v103 = v104;	// L187
          }
          int8_t v105 = v103;	// L189
          v98[v99][v102][v100][v101] = v105;	// L190
        }
      }
    }
  }
  int8_t v106[1][1024][20][6];	// L195
  #pragma HLS stream variable=v106 depth=10 type=fifo

  #pragma HLS bind_storage variable=v106 type=ram_t2p impl=bram

  int8_t v107[1][1024][3][8];	// L196
  #pragma HLS array_partition variable=v107 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v107 type=ram_2p impl=bram

  int8_t v108[1][1024][3][3];	// L197
  #pragma HLS array_partition variable=v108 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v108 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v108 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v108 type=ram_2p impl=lutram

  for (int v109 = 0; v109 < 1; v109 += 1) {	// L198
    for (int v110 = 0; v110 < 22; v110 += 1) {	// L199
      for (int v111 = 0; v111 < 8; v111 += 1) {	// L200
        for (int v112 = 0; v112 < 1024; v112 += 1) {	// L201
          int8_t v113 = v107[v109][v112][1][v111];	// L202
          v107[v109][v112][0][v111] = v113;	// L203
          int8_t v114 = v107[v109][v112][2][v111];	// L204
          v107[v109][v112][1][v111] = v114;	// L205
          int8_t v115 = v98[v109][v112][v110][v111];	// L206
          v107[v109][v112][2][v111] = v115;	// L207
        }
        if ((v110 - 2) >= 0) {	// L209
          for (int v116 = 0; v116 < 1024; v116 += 1) {	// L210
            for (int v117 = 0; v117 < 3; v117 += 1) {	// L211
              int8_t v118 = v108[v109][v116][v117][1];	// L212
              v108[v109][v116][v117][0] = v118;	// L213
              int8_t v119 = v108[v109][v116][v117][2];	// L214
              v108[v109][v116][v117][1] = v119;	// L215
              int8_t v120 = v107[v109][v116][v117][v111];	// L216
              v108[v109][v116][v117][2] = v120;	// L217
            }
          }
          if ((v111 - 2) >= 0) {	// L220
            int8_t v121[1024];	// L221
            #pragma HLS bind_storage variable=v121 type=ram_2p impl=bram

            for (int v122 = 0; v122 < 1024; v122 += 1) {	// L222
              v121[v122] = (int8_t)0.000000;	// L223
              for (int v123 = 0; v123 < 64; v123 += 1) {	// L224
                #pragma HLS pipeline II=1
                for (int v124 = 0; v124 < 16; v124 += 1) {	// L225
                  for (int v125 = 0; v125 < 3; v125 += 1) {	// L226
                    for (int v126 = 0; v126 < 3; v126 += 1) {	// L227
                      int8_t v127 = v108[v109][(v124 + (v123 * 16))][v125][v126];	// L228
                      int8_t v128 = v95[v122][(v124 + (v123 * 16))][v125][v126];	// L229
                      int8_t v129 = v127 * v128;	// L230
                      int8_t v130 = v121[v122];	// L231
                      int8_t v131 = v130 + v129;	// L232
                      v121[v122] = v131;	// L233
                    }
                  }
                }
              }
              int8_t v132 = v121[v122];	// L238
              v106[v109][v122][(v110 - 2)][(v111 - 2)] = v132;	// L239
            }
          }
        }
      }
    }
  }
  for (int v133 = 0; v133 < 1; v133 += 1) {	// L246
    for (int v134 = 0; v134 < 20; v134 += 1) {	// L247
      for (int v135 = 0; v135 < 6; v135 += 1) {	// L248
        for (int v136 = 0; v136 < 1024; v136 += 1) {	// L249
          int8_t v137 = v106[0][v136][v134][v135];	// L250
          bool v138 = v137 > (int8_t)0.000000;	// L251
          int8_t v139 = v138 ? v137 : (int8_t)0.000000;	// L252
          v97[v133][v136][v134][v135] = v139;	// L253
        }
      }
    }
  }
  return ;	// L258
}

void main_graph_node6(
  int8_t v140[1][512][20][6],
  int8_t v141[1024][512][3][3],
  int8_t v142[1][1024][20][6]
) {	// L260
  #pragma HLS dataflow

  int8_t v143[1][512][22][8];	// L262
  #pragma HLS stream variable=v143 depth=10 type=fifo

  #pragma HLS bind_storage variable=v143 type=ram_t2p impl=bram

  for (int v144 = 0; v144 < 1; v144 += 1) {	// L263
    for (int v145 = 0; v145 < 22; v145 += 1) {	// L264
      for (int v146 = 0; v146 < 8; v146 += 1) {	// L265
        for (int v147 = 0; v147 < 512; v147 += 1) {	// L266
          int8_t v148;	// L267
          v148 = (int8_t)0.000000;	// L268
          if (((-v145) + 19) >= 0 && ((-v146) + 5) >= 0) {	// L269
            int8_t v149 = v140[v144][v147][v145][v146];	// L270
            v148 = v149;	// L271
          }
          int8_t v150 = v148;	// L273
          v143[v144][v147][v145][v146] = v150;	// L274
        }
      }
    }
  }
  int8_t v151[1][1024][20][6];	// L279
  #pragma HLS stream variable=v151 depth=10 type=fifo

  #pragma HLS bind_storage variable=v151 type=ram_t2p impl=bram

  int8_t v152[1][512][3][8];	// L280
  #pragma HLS array_partition variable=v152 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v152 type=ram_2p impl=bram

  int8_t v153[1][512][3][3];	// L281
  #pragma HLS array_partition variable=v153 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v153 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v153 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v153 type=ram_2p impl=lutram

  for (int v154 = 0; v154 < 1; v154 += 1) {	// L282
    for (int v155 = 0; v155 < 22; v155 += 1) {	// L283
      for (int v156 = 0; v156 < 8; v156 += 1) {	// L284
        for (int v157 = 0; v157 < 512; v157 += 1) {	// L285
          int8_t v158 = v152[v154][v157][1][v156];	// L286
          v152[v154][v157][0][v156] = v158;	// L287
          int8_t v159 = v152[v154][v157][2][v156];	// L288
          v152[v154][v157][1][v156] = v159;	// L289
          int8_t v160 = v143[v154][v157][v155][v156];	// L290
          v152[v154][v157][2][v156] = v160;	// L291
        }
        if ((v155 - 2) >= 0) {	// L293
          for (int v161 = 0; v161 < 512; v161 += 1) {	// L294
            for (int v162 = 0; v162 < 3; v162 += 1) {	// L295
              int8_t v163 = v153[v154][v161][v162][1];	// L296
              v153[v154][v161][v162][0] = v163;	// L297
              int8_t v164 = v153[v154][v161][v162][2];	// L298
              v153[v154][v161][v162][1] = v164;	// L299
              int8_t v165 = v152[v154][v161][v162][v156];	// L300
              v153[v154][v161][v162][2] = v165;	// L301
            }
          }
          if ((v156 - 2) >= 0) {	// L304
            int8_t v166[1024];	// L305
            #pragma HLS bind_storage variable=v166 type=ram_2p impl=bram

            for (int v167 = 0; v167 < 1024; v167 += 1) {	// L306
              v166[v167] = (int8_t)0.000000;	// L307
              for (int v168 = 0; v168 < 64; v168 += 1) {	// L308
                #pragma HLS pipeline II=1
                for (int v169 = 0; v169 < 8; v169 += 1) {	// L309
                  for (int v170 = 0; v170 < 3; v170 += 1) {	// L310
                    for (int v171 = 0; v171 < 3; v171 += 1) {	// L311
                      int8_t v172 = v153[v154][(v169 + (v168 * 8))][v170][v171];	// L312
                      int8_t v173 = v141[v167][(v169 + (v168 * 8))][v170][v171];	// L313
                      int8_t v174 = v172 * v173;	// L314
                      int8_t v175 = v166[v167];	// L315
                      int8_t v176 = v175 + v174;	// L316
                      v166[v167] = v176;	// L317
                    }
                  }
                }
              }
              int8_t v177 = v166[v167];	// L322
              v151[v154][v167][(v155 - 2)][(v156 - 2)] = v177;	// L323
            }
          }
        }
      }
    }
  }
  for (int v178 = 0; v178 < 1; v178 += 1) {	// L330
    for (int v179 = 0; v179 < 20; v179 += 1) {	// L331
      for (int v180 = 0; v180 < 6; v180 += 1) {	// L332
        for (int v181 = 0; v181 < 1024; v181 += 1) {	// L333
          int8_t v182 = v151[0][v181][v179][v180];	// L334
          bool v183 = v182 > (int8_t)0.000000;	// L335
          int8_t v184 = v183 ? v182 : (int8_t)0.000000;	// L336
          v142[v178][v181][v179][v180] = v184;	// L337
        }
      }
    }
  }
  return ;	// L342
}

void main_graph_node7(
  int8_t v185[1][512][20][6],
  int8_t v186[512][512][3][3],
  int8_t v187[1][512][20][6]
) {	// L344
  #pragma HLS dataflow

  int8_t v188[1][512][22][8];	// L346
  #pragma HLS stream variable=v188 depth=10 type=fifo

  #pragma HLS bind_storage variable=v188 type=ram_t2p impl=bram

  for (int v189 = 0; v189 < 1; v189 += 1) {	// L347
    for (int v190 = 0; v190 < 22; v190 += 1) {	// L348
      for (int v191 = 0; v191 < 8; v191 += 1) {	// L349
        for (int v192 = 0; v192 < 512; v192 += 1) {	// L350
          int8_t v193;	// L351
          v193 = (int8_t)0.000000;	// L352
          if (((-v190) + 19) >= 0 && ((-v191) + 5) >= 0) {	// L353
            int8_t v194 = v185[v189][v192][v190][v191];	// L354
            v193 = v194;	// L355
          }
          int8_t v195 = v193;	// L357
          v188[v189][v192][v190][v191] = v195;	// L358
        }
      }
    }
  }
  int8_t v196[1][512][20][6];	// L363
  #pragma HLS stream variable=v196 depth=10 type=fifo

  #pragma HLS bind_storage variable=v196 type=ram_t2p impl=bram

  int8_t v197[1][512][3][8];	// L364
  #pragma HLS array_partition variable=v197 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v197 type=ram_2p impl=bram

  int8_t v198[1][512][3][3];	// L365
  #pragma HLS array_partition variable=v198 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v198 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v198 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v198 type=ram_2p impl=lutram

  for (int v199 = 0; v199 < 1; v199 += 1) {	// L366
    for (int v200 = 0; v200 < 22; v200 += 1) {	// L367
      for (int v201 = 0; v201 < 8; v201 += 1) {	// L368
        for (int v202 = 0; v202 < 512; v202 += 1) {	// L369
          int8_t v203 = v197[v199][v202][1][v201];	// L370
          v197[v199][v202][0][v201] = v203;	// L371
          int8_t v204 = v197[v199][v202][2][v201];	// L372
          v197[v199][v202][1][v201] = v204;	// L373
          int8_t v205 = v188[v199][v202][v200][v201];	// L374
          v197[v199][v202][2][v201] = v205;	// L375
        }
        if ((v200 - 2) >= 0) {	// L377
          for (int v206 = 0; v206 < 512; v206 += 1) {	// L378
            for (int v207 = 0; v207 < 3; v207 += 1) {	// L379
              int8_t v208 = v198[v199][v206][v207][1];	// L380
              v198[v199][v206][v207][0] = v208;	// L381
              int8_t v209 = v198[v199][v206][v207][2];	// L382
              v198[v199][v206][v207][1] = v209;	// L383
              int8_t v210 = v197[v199][v206][v207][v201];	// L384
              v198[v199][v206][v207][2] = v210;	// L385
            }
          }
          if ((v201 - 2) >= 0) {	// L388
            int8_t v211[512];	// L389
            #pragma HLS bind_storage variable=v211 type=ram_2p impl=bram

            for (int v212 = 0; v212 < 512; v212 += 1) {	// L390
              v211[v212] = (int8_t)0.000000;	// L391
              for (int v213 = 0; v213 < 128; v213 += 1) {	// L392
                #pragma HLS pipeline II=1
                for (int v214 = 0; v214 < 4; v214 += 1) {	// L393
                  for (int v215 = 0; v215 < 3; v215 += 1) {	// L394
                    for (int v216 = 0; v216 < 3; v216 += 1) {	// L395
                      int8_t v217 = v198[v199][(v214 + (v213 * 4))][v215][v216];	// L396
                      int8_t v218 = v186[v212][(v214 + (v213 * 4))][v215][v216];	// L397
                      int8_t v219 = v217 * v218;	// L398
                      int8_t v220 = v211[v212];	// L399
                      int8_t v221 = v220 + v219;	// L400
                      v211[v212] = v221;	// L401
                    }
                  }
                }
              }
              int8_t v222 = v211[v212];	// L406
              v196[v199][v212][(v200 - 2)][(v201 - 2)] = v222;	// L407
            }
          }
        }
      }
    }
  }
  for (int v223 = 0; v223 < 1; v223 += 1) {	// L414
    for (int v224 = 0; v224 < 20; v224 += 1) {	// L415
      for (int v225 = 0; v225 < 6; v225 += 1) {	// L416
        for (int v226 = 0; v226 < 512; v226 += 1) {	// L417
          int8_t v227 = v196[0][v226][v224][v225];	// L418
          bool v228 = v227 > (int8_t)0.000000;	// L419
          int8_t v229 = v228 ? v227 : (int8_t)0.000000;	// L420
          v187[v223][v226][v224][v225] = v229;	// L421
        }
      }
    }
  }
  return ;	// L426
}

void main_graph_node8(
  int8_t v230[1][512][40][12],
  int8_t v231[1][512][20][6]
) {	// L428
  #pragma HLS dataflow

  int8_t v232;	// L431
  v232 = (int8_t)-INFINITY;	// L432
  int8_t v233[1][512][40][12];	// L433
  #pragma HLS bind_storage variable=v233 type=ram_2p impl=bram

  for (int v234 = 0; v234 < 1; v234 += 1) {	// L434
    for (int v235 = 0; v235 < 40; v235 += 1) {	// L435
      for (int v236 = 0; v236 < 12; v236 += 1) {	// L436
        for (int v237 = 0; v237 < 512; v237 += 1) {	// L437
          int8_t v238 = v230[v234][v237][v235][v236];	// L438
          v233[v234][v237][v235][v236] = v238;	// L439
        }
      }
    }
  }
  for (int v239 = 0; v239 < 1; v239 += 1) {	// L444
    for (int v240 = 0; v240 < 20; v240 += 1) {	// L445
      for (int v241 = 0; v241 < 6; v241 += 1) {	// L446
        for (int v242 = 0; v242 < 512; v242 += 1) {	// L447
          int8_t v243;	// L448
          v243 = (int8_t)0.000000;	// L449
          for (int v244 = 0; v244 < 2; v244 += 1) {	// L450
            for (int v245 = 0; v245 < 2; v245 += 1) {	// L451
              int8_t v246 = v233[v239][v242][((v240 * 2) + v244)][((v241 * 2) + v245)];	// L452
              int8_t v247 = v232;	// L453
              int8_t v248 = max(v247, v246);	// L454
              v243 = v248;	// L455
            }
          }
          int8_t v249 = v243;	// L458
          v231[v239][v242][v240][v241] = v249;	// L459
        }
      }
    }
  }
  return ;	// L464
}

void main_graph_node9(
  int8_t v250[1][256][40][12],
  int8_t v251[512][256][3][3],
  int8_t v252[1][512][40][12]
) {	// L466
  #pragma HLS dataflow

  int8_t v253[1][256][42][14];	// L468
  #pragma HLS stream variable=v253 depth=10 type=fifo

  #pragma HLS bind_storage variable=v253 type=ram_t2p impl=bram

  for (int v254 = 0; v254 < 1; v254 += 1) {	// L469
    for (int v255 = 0; v255 < 42; v255 += 1) {	// L470
      for (int v256 = 0; v256 < 14; v256 += 1) {	// L471
        for (int v257 = 0; v257 < 256; v257 += 1) {	// L472
          int8_t v258;	// L473
          v258 = (int8_t)0.000000;	// L474
          if (((-v255) + 39) >= 0 && ((-v256) + 11) >= 0) {	// L475
            int8_t v259 = v250[v254][v257][v255][v256];	// L476
            v258 = v259;	// L477
          }
          int8_t v260 = v258;	// L479
          v253[v254][v257][v255][v256] = v260;	// L480
        }
      }
    }
  }
  int8_t v261[1][512][40][12];	// L485
  #pragma HLS stream variable=v261 depth=10 type=fifo

  #pragma HLS bind_storage variable=v261 type=ram_t2p impl=bram

  int8_t v262[1][256][3][14];	// L486
  #pragma HLS array_partition variable=v262 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v262 type=ram_2p impl=bram

  int8_t v263[1][256][3][3];	// L487
  #pragma HLS array_partition variable=v263 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v263 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v263 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v263 type=ram_2p impl=lutram

  for (int v264 = 0; v264 < 1; v264 += 1) {	// L488
    for (int v265 = 0; v265 < 42; v265 += 1) {	// L489
      for (int v266 = 0; v266 < 14; v266 += 1) {	// L490
        for (int v267 = 0; v267 < 256; v267 += 1) {	// L491
          int8_t v268 = v262[v264][v267][1][v266];	// L492
          v262[v264][v267][0][v266] = v268;	// L493
          int8_t v269 = v262[v264][v267][2][v266];	// L494
          v262[v264][v267][1][v266] = v269;	// L495
          int8_t v270 = v253[v264][v267][v265][v266];	// L496
          v262[v264][v267][2][v266] = v270;	// L497
        }
        if ((v265 - 2) >= 0) {	// L499
          for (int v271 = 0; v271 < 256; v271 += 1) {	// L500
            for (int v272 = 0; v272 < 3; v272 += 1) {	// L501
              int8_t v273 = v263[v264][v271][v272][1];	// L502
              v263[v264][v271][v272][0] = v273;	// L503
              int8_t v274 = v263[v264][v271][v272][2];	// L504
              v263[v264][v271][v272][1] = v274;	// L505
              int8_t v275 = v262[v264][v271][v272][v266];	// L506
              v263[v264][v271][v272][2] = v275;	// L507
            }
          }
          if ((v266 - 2) >= 0) {	// L510
            int8_t v276[512];	// L511
            #pragma HLS bind_storage variable=v276 type=ram_2p impl=bram

            for (int v277 = 0; v277 < 512; v277 += 1) {	// L512
              v276[v277] = (int8_t)0.000000;	// L513
              for (int v278 = 0; v278 < 32; v278 += 1) {	// L514
                #pragma HLS pipeline II=1
                for (int v279 = 0; v279 < 8; v279 += 1) {	// L515
                  for (int v280 = 0; v280 < 3; v280 += 1) {	// L516
                    for (int v281 = 0; v281 < 3; v281 += 1) {	// L517
                      int8_t v282 = v263[v264][(v279 + (v278 * 8))][v280][v281];	// L518
                      int8_t v283 = v251[v277][(v279 + (v278 * 8))][v280][v281];	// L519
                      int8_t v284 = v282 * v283;	// L520
                      int8_t v285 = v276[v277];	// L521
                      int8_t v286 = v285 + v284;	// L522
                      v276[v277] = v286;	// L523
                    }
                  }
                }
              }
              int8_t v287 = v276[v277];	// L528
              v261[v264][v277][(v265 - 2)][(v266 - 2)] = v287;	// L529
            }
          }
        }
      }
    }
  }
  for (int v288 = 0; v288 < 1; v288 += 1) {	// L536
    for (int v289 = 0; v289 < 40; v289 += 1) {	// L537
      for (int v290 = 0; v290 < 12; v290 += 1) {	// L538
        for (int v291 = 0; v291 < 512; v291 += 1) {	// L539
          int8_t v292 = v261[0][v291][v289][v290];	// L540
          bool v293 = v292 > (int8_t)0.000000;	// L541
          int8_t v294 = v293 ? v292 : (int8_t)0.000000;	// L542
          v252[v288][v291][v289][v290] = v294;	// L543
        }
      }
    }
  }
  return ;	// L548
}

void main_graph_node10(
  int8_t v295[1][256][80][24],
  int8_t v296[1][256][40][12]
) {	// L550
  #pragma HLS dataflow

  int8_t v297;	// L553
  v297 = (int8_t)-INFINITY;	// L554
  int8_t v298[1][256][80][24];	// L555
  #pragma HLS bind_storage variable=v298 type=ram_2p impl=bram

  for (int v299 = 0; v299 < 1; v299 += 1) {	// L556
    for (int v300 = 0; v300 < 80; v300 += 1) {	// L557
      for (int v301 = 0; v301 < 24; v301 += 1) {	// L558
        for (int v302 = 0; v302 < 256; v302 += 1) {	// L559
          int8_t v303 = v295[v299][v302][v300][v301];	// L560
          v298[v299][v302][v300][v301] = v303;	// L561
        }
      }
    }
  }
  for (int v304 = 0; v304 < 1; v304 += 1) {	// L566
    for (int v305 = 0; v305 < 40; v305 += 1) {	// L567
      for (int v306 = 0; v306 < 12; v306 += 1) {	// L568
        for (int v307 = 0; v307 < 256; v307 += 1) {	// L569
          int8_t v308;	// L570
          v308 = (int8_t)0.000000;	// L571
          for (int v309 = 0; v309 < 2; v309 += 1) {	// L572
            for (int v310 = 0; v310 < 2; v310 += 1) {	// L573
              int8_t v311 = v298[v304][v307][((v305 * 2) + v309)][((v306 * 2) + v310)];	// L574
              int8_t v312 = v297;	// L575
              int8_t v313 = max(v312, v311);	// L576
              v308 = v313;	// L577
            }
          }
          int8_t v314 = v308;	// L580
          v296[v304][v307][v305][v306] = v314;	// L581
        }
      }
    }
  }
  return ;	// L586
}

void main_graph_node11(
  int8_t v315[256][128][3][3],
  int8_t v316[1][128][80][24],
  int8_t v317[1][256][80][24]
) {	// L588
  #pragma HLS dataflow

  int8_t v318[1][128][82][26];	// L590
  #pragma HLS stream variable=v318 depth=10 type=fifo

  #pragma HLS bind_storage variable=v318 type=ram_t2p impl=bram

  for (int v319 = 0; v319 < 1; v319 += 1) {	// L591
    for (int v320 = 0; v320 < 82; v320 += 1) {	// L592
      for (int v321 = 0; v321 < 26; v321 += 1) {	// L593
        for (int v322 = 0; v322 < 128; v322 += 1) {	// L594
          int8_t v323;	// L595
          v323 = (int8_t)0.000000;	// L596
          if (((-v320) + 79) >= 0 && ((-v321) + 23) >= 0) {	// L597
            int8_t v324 = v316[v319][v322][v320][v321];	// L598
            v323 = v324;	// L599
          }
          int8_t v325 = v323;	// L601
          v318[v319][v322][v320][v321] = v325;	// L602
        }
      }
    }
  }
  int8_t v326[1][256][80][24];	// L607
  #pragma HLS stream variable=v326 depth=10 type=fifo

  #pragma HLS bind_storage variable=v326 type=ram_t2p impl=bram

  int8_t v327[1][128][3][26];	// L608
  #pragma HLS array_partition variable=v327 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v327 type=ram_2p impl=bram

  int8_t v328[1][128][3][3];	// L609
  #pragma HLS array_partition variable=v328 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v328 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v328 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v328 type=ram_2p impl=lutram

  for (int v329 = 0; v329 < 1; v329 += 1) {	// L610
    for (int v330 = 0; v330 < 82; v330 += 1) {	// L611
      for (int v331 = 0; v331 < 26; v331 += 1) {	// L612
        for (int v332 = 0; v332 < 128; v332 += 1) {	// L613
          int8_t v333 = v327[v329][v332][1][v331];	// L614
          v327[v329][v332][0][v331] = v333;	// L615
          int8_t v334 = v327[v329][v332][2][v331];	// L616
          v327[v329][v332][1][v331] = v334;	// L617
          int8_t v335 = v318[v329][v332][v330][v331];	// L618
          v327[v329][v332][2][v331] = v335;	// L619
        }
        if ((v330 - 2) >= 0) {	// L621
          for (int v336 = 0; v336 < 128; v336 += 1) {	// L622
            for (int v337 = 0; v337 < 3; v337 += 1) {	// L623
              int8_t v338 = v328[v329][v336][v337][1];	// L624
              v328[v329][v336][v337][0] = v338;	// L625
              int8_t v339 = v328[v329][v336][v337][2];	// L626
              v328[v329][v336][v337][1] = v339;	// L627
              int8_t v340 = v327[v329][v336][v337][v331];	// L628
              v328[v329][v336][v337][2] = v340;	// L629
            }
          }
          if ((v331 - 2) >= 0) {	// L632
            int8_t v341[256];	// L633
            #pragma HLS bind_storage variable=v341 type=ram_2p impl=bram

            for (int v342 = 0; v342 < 256; v342 += 1) {	// L634
              v341[v342] = (int8_t)0.000000;	// L635
              for (int v343 = 0; v343 < 16; v343 += 1) {	// L636
                #pragma HLS pipeline II=1
                for (int v344 = 0; v344 < 8; v344 += 1) {	// L637
                  for (int v345 = 0; v345 < 3; v345 += 1) {	// L638
                    for (int v346 = 0; v346 < 3; v346 += 1) {	// L639
                      int8_t v347 = v328[v329][(v344 + (v343 * 8))][v345][v346];	// L640
                      int8_t v348 = v315[v342][(v344 + (v343 * 8))][v345][v346];	// L641
                      int8_t v349 = v347 * v348;	// L642
                      int8_t v350 = v341[v342];	// L643
                      int8_t v351 = v350 + v349;	// L644
                      v341[v342] = v351;	// L645
                    }
                  }
                }
              }
              int8_t v352 = v341[v342];	// L650
              v326[v329][v342][(v330 - 2)][(v331 - 2)] = v352;	// L651
            }
          }
        }
      }
    }
  }
  for (int v353 = 0; v353 < 1; v353 += 1) {	// L658
    for (int v354 = 0; v354 < 80; v354 += 1) {	// L659
      for (int v355 = 0; v355 < 24; v355 += 1) {	// L660
        for (int v356 = 0; v356 < 256; v356 += 1) {	// L661
          int8_t v357 = v326[0][v356][v354][v355];	// L662
          bool v358 = v357 > (int8_t)0.000000;	// L663
          int8_t v359 = v358 ? v357 : (int8_t)0.000000;	// L664
          v317[v353][v356][v354][v355] = v359;	// L665
        }
      }
    }
  }
  return ;	// L670
}

void main_graph_node12(
  int8_t v360[1][128][160][48],
  int8_t v361[1][128][80][24]
) {	// L672
  #pragma HLS dataflow

  int8_t v362;	// L675
  v362 = (int8_t)-INFINITY;	// L676
  int8_t v363[1][128][160][48];	// L677
  #pragma HLS bind_storage variable=v363 type=ram_2p impl=bram

  for (int v364 = 0; v364 < 1; v364 += 1) {	// L678
    for (int v365 = 0; v365 < 160; v365 += 1) {	// L679
      for (int v366 = 0; v366 < 48; v366 += 1) {	// L680
        for (int v367 = 0; v367 < 128; v367 += 1) {	// L681
          int8_t v368 = v360[v364][v367][v365][v366];	// L682
          v363[v364][v367][v365][v366] = v368;	// L683
        }
      }
    }
  }
  for (int v369 = 0; v369 < 1; v369 += 1) {	// L688
    for (int v370 = 0; v370 < 80; v370 += 1) {	// L689
      for (int v371 = 0; v371 < 24; v371 += 1) {	// L690
        for (int v372 = 0; v372 < 128; v372 += 1) {	// L691
          int8_t v373;	// L692
          v373 = (int8_t)0.000000;	// L693
          for (int v374 = 0; v374 < 2; v374 += 1) {	// L694
            for (int v375 = 0; v375 < 2; v375 += 1) {	// L695
              int8_t v376 = v363[v369][v372][((v370 * 2) + v374)][((v371 * 2) + v375)];	// L696
              int8_t v377 = v362;	// L697
              int8_t v378 = max(v377, v376);	// L698
              v373 = v378;	// L699
            }
          }
          int8_t v379 = v373;	// L702
          v361[v369][v372][v370][v371] = v379;	// L703
        }
      }
    }
  }
  return ;	// L708
}

void main_graph_node13(
  int8_t v380[128][64][3][3],
  int8_t v381[1][64][160][48],
  int8_t v382[1][128][160][48]
) {	// L710
  #pragma HLS dataflow

  int8_t v383[1][64][162][50];	// L712
  #pragma HLS stream variable=v383 depth=10 type=fifo

  #pragma HLS bind_storage variable=v383 type=ram_t2p impl=bram

  for (int v384 = 0; v384 < 1; v384 += 1) {	// L713
    for (int v385 = 0; v385 < 162; v385 += 1) {	// L714
      for (int v386 = 0; v386 < 50; v386 += 1) {	// L715
        for (int v387 = 0; v387 < 64; v387 += 1) {	// L716
          int8_t v388;	// L717
          v388 = (int8_t)0.000000;	// L718
          if (((-v385) + 159) >= 0 && ((-v386) + 47) >= 0) {	// L719
            int8_t v389 = v381[v384][v387][v385][v386];	// L720
            v388 = v389;	// L721
          }
          int8_t v390 = v388;	// L723
          v383[v384][v387][v385][v386] = v390;	// L724
        }
      }
    }
  }
  int8_t v391[1][128][160][48];	// L729
  #pragma HLS stream variable=v391 depth=10 type=fifo

  #pragma HLS bind_storage variable=v391 type=ram_t2p impl=bram

  int8_t v392[1][64][3][50];	// L730
  #pragma HLS array_partition variable=v392 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v392 type=ram_2p impl=bram

  int8_t v393[1][64][3][3];	// L731
  #pragma HLS array_partition variable=v393 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v393 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v393 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v393 type=ram_2p impl=lutram

  for (int v394 = 0; v394 < 1; v394 += 1) {	// L732
    for (int v395 = 0; v395 < 162; v395 += 1) {	// L733
      for (int v396 = 0; v396 < 50; v396 += 1) {	// L734
        for (int v397 = 0; v397 < 64; v397 += 1) {	// L735
          int8_t v398 = v392[v394][v397][1][v396];	// L736
          v392[v394][v397][0][v396] = v398;	// L737
          int8_t v399 = v392[v394][v397][2][v396];	// L738
          v392[v394][v397][1][v396] = v399;	// L739
          int8_t v400 = v383[v394][v397][v395][v396];	// L740
          v392[v394][v397][2][v396] = v400;	// L741
        }
        if ((v395 - 2) >= 0) {	// L743
          for (int v401 = 0; v401 < 64; v401 += 1) {	// L744
            for (int v402 = 0; v402 < 3; v402 += 1) {	// L745
              int8_t v403 = v393[v394][v401][v402][1];	// L746
              v393[v394][v401][v402][0] = v403;	// L747
              int8_t v404 = v393[v394][v401][v402][2];	// L748
              v393[v394][v401][v402][1] = v404;	// L749
              int8_t v405 = v392[v394][v401][v402][v396];	// L750
              v393[v394][v401][v402][2] = v405;	// L751
            }
          }
          if ((v396 - 2) >= 0) {	// L754
            int8_t v406[128];	// L755
            #pragma HLS bind_storage variable=v406 type=ram_2p impl=bram

            for (int v407 = 0; v407 < 128; v407 += 1) {	// L756
              v406[v407] = (int8_t)0.000000;	// L757
              for (int v408 = 0; v408 < 8; v408 += 1) {	// L758
                #pragma HLS pipeline II=1
                for (int v409 = 0; v409 < 8; v409 += 1) {	// L759
                  for (int v410 = 0; v410 < 3; v410 += 1) {	// L760
                    for (int v411 = 0; v411 < 3; v411 += 1) {	// L761
                      int8_t v412 = v393[v394][(v409 + (v408 * 8))][v410][v411];	// L762
                      int8_t v413 = v380[v407][(v409 + (v408 * 8))][v410][v411];	// L763
                      int8_t v414 = v412 * v413;	// L764
                      int8_t v415 = v406[v407];	// L765
                      int8_t v416 = v415 + v414;	// L766
                      v406[v407] = v416;	// L767
                    }
                  }
                }
              }
              int8_t v417 = v406[v407];	// L772
              v391[v394][v407][(v395 - 2)][(v396 - 2)] = v417;	// L773
            }
          }
        }
      }
    }
  }
  for (int v418 = 0; v418 < 1; v418 += 1) {	// L780
    for (int v419 = 0; v419 < 160; v419 += 1) {	// L781
      for (int v420 = 0; v420 < 48; v420 += 1) {	// L782
        for (int v421 = 0; v421 < 128; v421 += 1) {	// L783
          int8_t v422 = v391[0][v421][v419][v420];	// L784
          bool v423 = v422 > (int8_t)0.000000;	// L785
          int8_t v424 = v423 ? v422 : (int8_t)0.000000;	// L786
          v382[v418][v421][v419][v420] = v424;	// L787
        }
      }
    }
  }
  return ;	// L792
}

void main_graph_node14(
  int8_t v425[1][64][320][96],
  int8_t v426[1][64][160][48]
) {	// L794
  #pragma HLS dataflow

  int8_t v427;	// L797
  v427 = (int8_t)-INFINITY;	// L798
  int8_t v428[1][64][320][96];	// L799
  #pragma HLS bind_storage variable=v428 type=ram_2p impl=bram

  for (int v429 = 0; v429 < 1; v429 += 1) {	// L800
    for (int v430 = 0; v430 < 320; v430 += 1) {	// L801
      for (int v431 = 0; v431 < 96; v431 += 1) {	// L802
        for (int v432 = 0; v432 < 64; v432 += 1) {	// L803
          int8_t v433 = v425[v429][v432][v430][v431];	// L804
          v428[v429][v432][v430][v431] = v433;	// L805
        }
      }
    }
  }
  for (int v434 = 0; v434 < 1; v434 += 1) {	// L810
    for (int v435 = 0; v435 < 160; v435 += 1) {	// L811
      for (int v436 = 0; v436 < 48; v436 += 1) {	// L812
        for (int v437 = 0; v437 < 64; v437 += 1) {	// L813
          int8_t v438;	// L814
          v438 = (int8_t)0.000000;	// L815
          for (int v439 = 0; v439 < 2; v439 += 1) {	// L816
            for (int v440 = 0; v440 < 2; v440 += 1) {	// L817
              int8_t v441 = v428[v434][v437][((v435 * 2) + v439)][((v436 * 2) + v440)];	// L818
              int8_t v442 = v427;	// L819
              int8_t v443 = max(v442, v441);	// L820
              v438 = v443;	// L821
            }
          }
          int8_t v444 = v438;	// L824
          v426[v434][v437][v435][v436] = v444;	// L825
        }
      }
    }
  }
  return ;	// L830
}

void main_graph_node15(
  int8_t v445[64][32][3][3],
  int8_t v446[1][32][320][96],
  int8_t v447[1][64][320][96]
) {	// L832
  #pragma HLS dataflow

  int8_t v448[1][32][322][98];	// L834
  #pragma HLS stream variable=v448 depth=10 type=fifo

  #pragma HLS bind_storage variable=v448 type=ram_t2p impl=bram

  for (int v449 = 0; v449 < 1; v449 += 1) {	// L835
    for (int v450 = 0; v450 < 322; v450 += 1) {	// L836
      for (int v451 = 0; v451 < 98; v451 += 1) {	// L837
        for (int v452 = 0; v452 < 32; v452 += 1) {	// L838
          int8_t v453;	// L839
          v453 = (int8_t)0.000000;	// L840
          if (((-v450) + 319) >= 0 && ((-v451) + 95) >= 0) {	// L841
            int8_t v454 = v446[v449][v452][v450][v451];	// L842
            v453 = v454;	// L843
          }
          int8_t v455 = v453;	// L845
          v448[v449][v452][v450][v451] = v455;	// L846
        }
      }
    }
  }
  int8_t v456[1][64][320][96];	// L851
  #pragma HLS stream variable=v456 depth=10 type=fifo

  #pragma HLS bind_storage variable=v456 type=ram_t2p impl=bram

  int8_t v457[1][32][3][98];	// L852
  #pragma HLS array_partition variable=v457 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v457 type=ram_2p impl=bram

  int8_t v458[1][32][3][3];	// L853
  #pragma HLS array_partition variable=v458 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v458 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v458 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v458 type=ram_2p impl=lutram

  for (int v459 = 0; v459 < 1; v459 += 1) {	// L854
    for (int v460 = 0; v460 < 322; v460 += 1) {	// L855
      for (int v461 = 0; v461 < 98; v461 += 1) {	// L856
        for (int v462 = 0; v462 < 32; v462 += 1) {	// L857
          int8_t v463 = v457[v459][v462][1][v461];	// L858
          v457[v459][v462][0][v461] = v463;	// L859
          int8_t v464 = v457[v459][v462][2][v461];	// L860
          v457[v459][v462][1][v461] = v464;	// L861
          int8_t v465 = v448[v459][v462][v460][v461];	// L862
          v457[v459][v462][2][v461] = v465;	// L863
        }
        if ((v460 - 2) >= 0) {	// L865
          for (int v466 = 0; v466 < 32; v466 += 1) {	// L866
            for (int v467 = 0; v467 < 3; v467 += 1) {	// L867
              int8_t v468 = v458[v459][v466][v467][1];	// L868
              v458[v459][v466][v467][0] = v468;	// L869
              int8_t v469 = v458[v459][v466][v467][2];	// L870
              v458[v459][v466][v467][1] = v469;	// L871
              int8_t v470 = v457[v459][v466][v467][v461];	// L872
              v458[v459][v466][v467][2] = v470;	// L873
            }
          }
          if ((v461 - 2) >= 0) {	// L876
            int8_t v471[64];	// L877
            #pragma HLS bind_storage variable=v471 type=ram_2p impl=bram

            for (int v472 = 0; v472 < 64; v472 += 1) {	// L878
              v471[v472] = (int8_t)0.000000;	// L879
              for (int v473 = 0; v473 < 4; v473 += 1) {	// L880
                #pragma HLS pipeline II=1
                for (int v474 = 0; v474 < 8; v474 += 1) {	// L881
                  for (int v475 = 0; v475 < 3; v475 += 1) {	// L882
                    for (int v476 = 0; v476 < 3; v476 += 1) {	// L883
                      int8_t v477 = v458[v459][(v474 + (v473 * 8))][v475][v476];	// L884
                      int8_t v478 = v445[v472][(v474 + (v473 * 8))][v475][v476];	// L885
                      int8_t v479 = v477 * v478;	// L886
                      int8_t v480 = v471[v472];	// L887
                      int8_t v481 = v480 + v479;	// L888
                      v471[v472] = v481;	// L889
                    }
                  }
                }
              }
              int8_t v482 = v471[v472];	// L894
              v456[v459][v472][(v460 - 2)][(v461 - 2)] = v482;	// L895
            }
          }
        }
      }
    }
  }
  for (int v483 = 0; v483 < 1; v483 += 1) {	// L902
    for (int v484 = 0; v484 < 320; v484 += 1) {	// L903
      for (int v485 = 0; v485 < 96; v485 += 1) {	// L904
        for (int v486 = 0; v486 < 64; v486 += 1) {	// L905
          int8_t v487 = v456[0][v486][v484][v485];	// L906
          bool v488 = v487 > (int8_t)0.000000;	// L907
          int8_t v489 = v488 ? v487 : (int8_t)0.000000;	// L908
          v447[v483][v486][v484][v485] = v489;	// L909
        }
      }
    }
  }
  return ;	// L914
}

void main_graph_node16(
  int8_t v490[1][32][640][192],
  int8_t v491[1][32][320][96]
) {	// L916
  #pragma HLS dataflow

  int8_t v492;	// L919
  v492 = (int8_t)-INFINITY;	// L920
  int8_t v493[1][32][640][192];	// L921
  #pragma HLS array_partition variable=v493 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v493 type=ram_2p impl=bram

  for (int v494 = 0; v494 < 1; v494 += 1) {	// L922
    for (int v495 = 0; v495 < 640; v495 += 1) {	// L923
      for (int v496 = 0; v496 < 192; v496 += 1) {	// L924
        for (int v497 = 0; v497 < 8; v497 += 1) {	// L925
          #pragma HLS pipeline II=1
          for (int v498 = 0; v498 < 4; v498 += 1) {	// L926
            int8_t v499 = v490[v494][(v498 + (v497 * 4))][v495][v496];	// L927
            v493[v494][(v498 + (v497 * 4))][v495][v496] = v499;	// L928
          }
        }
      }
    }
  }
  for (int v500 = 0; v500 < 1; v500 += 1) {	// L934
    for (int v501 = 0; v501 < 320; v501 += 1) {	// L935
      for (int v502 = 0; v502 < 96; v502 += 1) {	// L936
        for (int v503 = 0; v503 < 32; v503 += 1) {	// L937
          int8_t v504;	// L938
          v504 = (int8_t)0.000000;	// L939
          for (int v505 = 0; v505 < 2; v505 += 1) {	// L940
            for (int v506 = 0; v506 < 2; v506 += 1) {	// L941
              int8_t v507 = v493[v500][v503][((v501 * 2) + v505)][((v502 * 2) + v506)];	// L942
              int8_t v508 = v492;	// L943
              int8_t v509 = max(v508, v507);	// L944
              v504 = v509;	// L945
            }
          }
          int8_t v510 = v504;	// L948
          v491[v500][v503][v501][v502] = v510;	// L949
        }
      }
    }
  }
  return ;	// L954
}

void main_graph_node17(
  int8_t v511[1][16][640][192],
  int8_t v512[32][16][3][3],
  int8_t v513[1][32][640][192]
) {	// L956
  #pragma HLS dataflow

  int8_t v514[1][16][642][194];	// L958
  #pragma HLS stream variable=v514 depth=10 type=fifo

  #pragma HLS bind_storage variable=v514 type=ram_t2p impl=bram

  for (int v515 = 0; v515 < 1; v515 += 1) {	// L959
    for (int v516 = 0; v516 < 642; v516 += 1) {	// L960
      for (int v517 = 0; v517 < 194; v517 += 1) {	// L961
        for (int v518 = 0; v518 < 16; v518 += 1) {	// L962
          int8_t v519;	// L963
          v519 = (int8_t)0.000000;	// L964
          if (((-v516) + 639) >= 0 && ((-v517) + 191) >= 0) {	// L965
            int8_t v520 = v511[v515][v518][v516][v517];	// L966
            v519 = v520;	// L967
          }
          int8_t v521 = v519;	// L969
          v514[v515][v518][v516][v517] = v521;	// L970
        }
      }
    }
  }
  int8_t v522[1][32][640][192];	// L975
  #pragma HLS stream variable=v522 depth=10 type=fifo

  #pragma HLS array_partition variable=v522 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v522 type=ram_t2p impl=bram

  int8_t v523[1][16][3][194];	// L976
  #pragma HLS array_partition variable=v523 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v523 type=ram_2p impl=bram

  int8_t v524[1][16][3][3];	// L977
  #pragma HLS array_partition variable=v524 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v524 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v524 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v524 type=ram_2p impl=lutram

  for (int v525 = 0; v525 < 1; v525 += 1) {	// L978
    for (int v526 = 0; v526 < 642; v526 += 1) {	// L979
      for (int v527 = 0; v527 < 194; v527 += 1) {	// L980
        for (int v528 = 0; v528 < 16; v528 += 1) {	// L981
          int8_t v529 = v523[v525][v528][1][v527];	// L982
          v523[v525][v528][0][v527] = v529;	// L983
          int8_t v530 = v523[v525][v528][2][v527];	// L984
          v523[v525][v528][1][v527] = v530;	// L985
          int8_t v531 = v514[v525][v528][v526][v527];	// L986
          v523[v525][v528][2][v527] = v531;	// L987
        }
        if ((v526 - 2) >= 0) {	// L989
          for (int v532 = 0; v532 < 16; v532 += 1) {	// L990
            for (int v533 = 0; v533 < 3; v533 += 1) {	// L991
              int8_t v534 = v524[v525][v532][v533][1];	// L992
              v524[v525][v532][v533][0] = v534;	// L993
              int8_t v535 = v524[v525][v532][v533][2];	// L994
              v524[v525][v532][v533][1] = v535;	// L995
              int8_t v536 = v523[v525][v532][v533][v527];	// L996
              v524[v525][v532][v533][2] = v536;	// L997
            }
          }
          if ((v527 - 2) >= 0) {	// L1000
            int8_t v537[32];	// L1001
            #pragma HLS array_partition variable=v537 cyclic factor=4 dim=1
            #pragma HLS bind_storage variable=v537 type=ram_2p impl=lutram

            for (int v538 = 0; v538 < 8; v538 += 1) {	// L1002
              #pragma HLS pipeline II=1
              for (int v539 = 0; v539 < 4; v539 += 1) {	// L1003
                v537[(v539 + (v538 * 4))] = (int8_t)0.000000;	// L1004
                for (int v540 = 0; v540 < 16; v540 += 1) {	// L1005
                  for (int v541 = 0; v541 < 3; v541 += 1) {	// L1006
                    for (int v542 = 0; v542 < 3; v542 += 1) {	// L1007
                      int8_t v543 = v524[v525][v540][v541][v542];	// L1008
                      int8_t v544 = v512[(v539 + (v538 * 4))][v540][v541][v542];	// L1009
                      int8_t v545 = v543 * v544;	// L1010
                      int8_t v546 = v537[(v539 + (v538 * 4))];	// L1011
                      int8_t v547 = v546 + v545;	// L1012
                      v537[(v539 + (v538 * 4))] = v547;	// L1013
                    }
                  }
                }
                int8_t v548 = v537[(v539 + (v538 * 4))];	// L1017
                v522[v525][(v539 + (v538 * 4))][(v526 - 2)][(v527 - 2)] = v548;	// L1018
              }
            }
          }
        }
      }
    }
  }
  for (int v549 = 0; v549 < 1; v549 += 1) {	// L1026
    for (int v550 = 0; v550 < 640; v550 += 1) {	// L1027
      for (int v551 = 0; v551 < 192; v551 += 1) {	// L1028
        for (int v552 = 0; v552 < 8; v552 += 1) {	// L1029
          #pragma HLS pipeline II=1
          for (int v553 = 0; v553 < 4; v553 += 1) {	// L1030
            int8_t v554 = v522[0][(v553 + (v552 * 4))][v550][v551];	// L1031
            bool v555 = v554 > (int8_t)0.000000;	// L1032
            int8_t v556 = v555 ? v554 : (int8_t)0.000000;	// L1033
            v513[v549][(v553 + (v552 * 4))][v550][v551] = v556;	// L1034
          }
        }
      }
    }
  }
  return ;	// L1040
}

void main_graph_node18(
  int8_t v557[1][16][1280][384],
  int8_t v558[1][16][640][192]
) {	// L1042
  #pragma HLS dataflow

  int8_t v559;	// L1045
  v559 = (int8_t)-INFINITY;	// L1046
  int8_t v560[1][16][1280][384];	// L1047
  #pragma HLS array_partition variable=v560 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v560 type=ram_2p impl=bram

  for (int v561 = 0; v561 < 1; v561 += 1) {	// L1048
    for (int v562 = 0; v562 < 1280; v562 += 1) {	// L1049
      for (int v563 = 0; v563 < 384; v563 += 1) {	// L1050
        for (int v564 = 0; v564 < 1; v564 += 1) {	// L1051
          #pragma HLS pipeline II=1
          for (int v565 = 0; v565 < 16; v565 += 1) {	// L1052
            int8_t v566 = v557[v561][(v565 + (v564 * 32))][v562][v563];	// L1053
            v560[v561][(v565 + (v564 * 32))][v562][v563] = v566;	// L1054
          }
        }
      }
    }
  }
  for (int v567 = 0; v567 < 1; v567 += 1) {	// L1060
    for (int v568 = 0; v568 < 640; v568 += 1) {	// L1061
      for (int v569 = 0; v569 < 192; v569 += 1) {	// L1062
        for (int v570 = 0; v570 < 16; v570 += 1) {	// L1063
          int8_t v571;	// L1064
          v571 = (int8_t)0.000000;	// L1065
          for (int v572 = 0; v572 < 2; v572 += 1) {	// L1066
            for (int v573 = 0; v573 < 2; v573 += 1) {	// L1067
              int8_t v574 = v560[v567][v570][((v568 * 2) + v572)][((v569 * 2) + v573)];	// L1068
              int8_t v575 = v559;	// L1069
              int8_t v576 = max(v575, v574);	// L1070
              v571 = v576;	// L1071
            }
          }
          int8_t v577 = v571;	// L1074
          v558[v567][v570][v568][v569] = v577;	// L1075
        }
      }
    }
  }
  return ;	// L1080
}

void main_graph_node19(
  int8_t v578[1][3][1280][384],
  int8_t v579[16][3][3][3],
  int8_t v580[1][16][1280][384]
) {	// L1082
  #pragma HLS dataflow

  int8_t v581[1][3][1282][386];	// L1084
  #pragma HLS stream variable=v581 depth=10 type=fifo

  #pragma HLS bind_storage variable=v581 type=ram_t2p impl=bram

  for (int v582 = 0; v582 < 1; v582 += 1) {	// L1085
    for (int v583 = 0; v583 < 1282; v583 += 1) {	// L1086
      for (int v584 = 0; v584 < 386; v584 += 1) {	// L1087
        for (int v585 = 0; v585 < 3; v585 += 1) {	// L1088
          int8_t v586;	// L1089
          v586 = (int8_t)0.000000;	// L1090
          if (((-v583) + 1279) >= 0 && ((-v584) + 383) >= 0) {	// L1091
            int8_t v587 = v578[v582][v585][v583][v584];	// L1092
            v586 = v587;	// L1093
          }
          int8_t v588 = v586;	// L1095
          v581[v582][v585][v583][v584] = v588;	// L1096
        }
      }
    }
  }
  int8_t v589[1][16][1280][384];	// L1101
  #pragma HLS stream variable=v589 depth=10 type=fifo

  #pragma HLS array_partition variable=v589 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v589 type=ram_t2p impl=bram

  int8_t v590[1][3][3][386];	// L1102
  #pragma HLS array_partition variable=v590 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v590 type=ram_2p impl=bram

  int8_t v591[1][3][3][3];	// L1103
  #pragma HLS array_partition variable=v591 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v591 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v591 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v591 type=ram_2p impl=lutram

  for (int v592 = 0; v592 < 1; v592 += 1) {	// L1104
    for (int v593 = 0; v593 < 1282; v593 += 1) {	// L1105
      for (int v594 = 0; v594 < 386; v594 += 1) {	// L1106
        for (int v595 = 0; v595 < 3; v595 += 1) {	// L1107
          int8_t v596 = v590[v592][v595][1][v594];	// L1108
          v590[v592][v595][0][v594] = v596;	// L1109
          int8_t v597 = v590[v592][v595][2][v594];	// L1110
          v590[v592][v595][1][v594] = v597;	// L1111
          int8_t v598 = v581[v592][v595][v593][v594];	// L1112
          v590[v592][v595][2][v594] = v598;	// L1113
        }
        if ((v593 - 2) >= 0) {	// L1115
          for (int v599 = 0; v599 < 3; v599 += 1) {	// L1116
            for (int v600 = 0; v600 < 3; v600 += 1) {	// L1117
              int8_t v601 = v591[v592][v599][v600][1];	// L1118
              v591[v592][v599][v600][0] = v601;	// L1119
              int8_t v602 = v591[v592][v599][v600][2];	// L1120
              v591[v592][v599][v600][1] = v602;	// L1121
              int8_t v603 = v590[v592][v599][v600][v594];	// L1122
              v591[v592][v599][v600][2] = v603;	// L1123
            }
          }
          if ((v594 - 2) >= 0) {	// L1126
            int8_t v604[16];	// L1127
            #pragma HLS array_partition variable=v604 cyclic factor=16 dim=1
            #pragma HLS bind_storage variable=v604 type=ram_2p impl=lutram

            for (int v605 = 0; v605 < 1; v605 += 1) {	// L1128
              #pragma HLS pipeline II=1
              for (int v606 = 0; v606 < 16; v606 += 1) {	// L1129
                v604[(v606 + (v605 * 32))] = (int8_t)0.000000;	// L1130
                for (int v607 = 0; v607 < 3; v607 += 1) {	// L1131
                  for (int v608 = 0; v608 < 3; v608 += 1) {	// L1132
                    for (int v609 = 0; v609 < 3; v609 += 1) {	// L1133
                      int8_t v610 = v591[v592][v607][v608][v609];	// L1134
                      int8_t v611 = v579[(v606 + (v605 * 32))][v607][v608][v609];	// L1135
                      int8_t v612 = v610 * v611;	// L1136
                      int8_t v613 = v604[(v606 + (v605 * 32))];	// L1137
                      int8_t v614 = v613 + v612;	// L1138
                      v604[(v606 + (v605 * 32))] = v614;	// L1139
                    }
                  }
                }
                int8_t v615 = v604[(v606 + (v605 * 32))];	// L1143
                v589[v592][(v606 + (v605 * 32))][(v593 - 2)][(v594 - 2)] = v615;	// L1144
              }
            }
          }
        }
      }
    }
  }
  for (int v616 = 0; v616 < 1; v616 += 1) {	// L1152
    for (int v617 = 0; v617 < 1280; v617 += 1) {	// L1153
      for (int v618 = 0; v618 < 384; v618 += 1) {	// L1154
        for (int v619 = 0; v619 < 1; v619 += 1) {	// L1155
          #pragma HLS pipeline II=1
          for (int v620 = 0; v620 < 16; v620 += 1) {	// L1156
            int8_t v621 = v589[0][(v620 + (v619 * 32))][v617][v618];	// L1157
            bool v622 = v621 > (int8_t)0.000000;	// L1158
            int8_t v623 = v622 ? v621 : (int8_t)0.000000;	// L1159
            v580[v616][(v620 + (v619 * 32))][v617][v618] = v623;	// L1160
          }
        }
      }
    }
  }
  return ;	// L1166
}

/// This is top function.
void main_graph(
  int8_t v624[1][3][1280][384],
  int8_t v625[1470],
  int8_t v626[4096],
  int8_t v627[256][1024][20][6],
  int8_t v628[1024][1024][3][3],
  int8_t v629[1024][512][3][3],
  int8_t v630[512][512][3][3],
  int8_t v631[512][256][3][3],
  int8_t v632[256][128][3][3],
  int8_t v633[128][64][3][3],
  int8_t v634[64][32][3][3],
  int8_t v635[32][16][3][3],
  int8_t v636[16][3][3][3],
  int8_t v637[256][4096],
  int8_t v638[4096][1470],
  int8_t v639[1][1470]
) {	// L1168
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v624 bundle=gmem1
  #pragma HLS bind_storage variable=v624 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v625 bundle=gmem2
  #pragma HLS bind_storage variable=v625 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v626 bundle=gmem3
  #pragma HLS bind_storage variable=v626 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v627 bundle=gmem4
  #pragma HLS array_partition variable=v627 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v627 cyclic factor=20 dim=3
  #pragma HLS array_partition variable=v627 cyclic factor=6 dim=4
  #pragma HLS bind_storage variable=v627 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v628 bundle=gmem5
  #pragma HLS array_partition variable=v628 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v628 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v628 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v628 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v629 bundle=gmem6
  #pragma HLS array_partition variable=v629 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v629 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v629 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v629 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v630 bundle=gmem7
  #pragma HLS array_partition variable=v630 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v630 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v630 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v630 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v631 bundle=gmem8
  #pragma HLS array_partition variable=v631 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v631 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v631 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v631 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v632 bundle=gmem9
  #pragma HLS array_partition variable=v632 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v632 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v632 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v632 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v633 bundle=gmem10
  #pragma HLS array_partition variable=v633 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v633 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v633 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v633 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v634 bundle=gmem11
  #pragma HLS array_partition variable=v634 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v634 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v634 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v634 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v635 bundle=gmem12
  #pragma HLS array_partition variable=v635 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v635 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v635 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v635 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v635 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v636 bundle=gmem13
  #pragma HLS array_partition variable=v636 cyclic factor=16 dim=1
  #pragma HLS array_partition variable=v636 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v636 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v636 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v636 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v637 bundle=gmem14
  #pragma HLS bind_storage variable=v637 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v638 bundle=gmem15
  #pragma HLS bind_storage variable=v638 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v639 bundle=gmem16
  #pragma HLS bind_storage variable=v639 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v640[1][16][1280][384];	// L1170
  #pragma HLS stream variable=v640 depth=10 type=fifo

  #pragma HLS array_partition variable=v640 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v640 type=ram_t2p impl=bram

  main_graph_node19(v624, v636, v640);	// L1171
  int8_t v641[1][16][640][192];	// L1172
  #pragma HLS stream variable=v641 depth=10 type=fifo

  #pragma HLS bind_storage variable=v641 type=ram_t2p impl=bram

  main_graph_node18(v640, v641);	// L1173
  int8_t v642[1][32][640][192];	// L1174
  #pragma HLS stream variable=v642 depth=10 type=fifo

  #pragma HLS array_partition variable=v642 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v642 type=ram_t2p impl=bram

  main_graph_node17(v641, v635, v642);	// L1175
  int8_t v643[1][32][320][96];	// L1176
  #pragma HLS stream variable=v643 depth=10 type=fifo

  #pragma HLS bind_storage variable=v643 type=ram_t2p impl=bram

  main_graph_node16(v642, v643);	// L1177
  int8_t v644[1][64][320][96];	// L1178
  #pragma HLS stream variable=v644 depth=10 type=fifo

  #pragma HLS bind_storage variable=v644 type=ram_t2p impl=bram

  main_graph_node15(v634, v643, v644);	// L1179
  int8_t v645[1][64][160][48];	// L1180
  #pragma HLS stream variable=v645 depth=10 type=fifo

  #pragma HLS bind_storage variable=v645 type=ram_t2p impl=bram

  main_graph_node14(v644, v645);	// L1181
  int8_t v646[1][128][160][48];	// L1182
  #pragma HLS stream variable=v646 depth=10 type=fifo

  #pragma HLS bind_storage variable=v646 type=ram_t2p impl=bram

  main_graph_node13(v633, v645, v646);	// L1183
  int8_t v647[1][128][80][24];	// L1184
  #pragma HLS stream variable=v647 depth=10 type=fifo

  #pragma HLS bind_storage variable=v647 type=ram_t2p impl=bram

  main_graph_node12(v646, v647);	// L1185
  int8_t v648[1][256][80][24];	// L1186
  #pragma HLS stream variable=v648 depth=10 type=fifo

  #pragma HLS bind_storage variable=v648 type=ram_t2p impl=bram

  main_graph_node11(v632, v647, v648);	// L1187
  int8_t v649[1][256][40][12];	// L1188
  #pragma HLS stream variable=v649 depth=10 type=fifo

  #pragma HLS bind_storage variable=v649 type=ram_t2p impl=bram

  main_graph_node10(v648, v649);	// L1189
  int8_t v650[1][512][40][12];	// L1190
  #pragma HLS stream variable=v650 depth=10 type=fifo

  #pragma HLS bind_storage variable=v650 type=ram_t2p impl=bram

  main_graph_node9(v649, v631, v650);	// L1191
  int8_t v651[1][512][20][6];	// L1192
  #pragma HLS stream variable=v651 depth=10 type=fifo

  #pragma HLS bind_storage variable=v651 type=ram_t2p impl=bram

  main_graph_node8(v650, v651);	// L1193
  int8_t v652[1][512][20][6];	// L1194
  #pragma HLS stream variable=v652 depth=10 type=fifo

  #pragma HLS bind_storage variable=v652 type=ram_t2p impl=bram

  main_graph_node7(v651, v630, v652);	// L1195
  int8_t v653[1][1024][20][6];	// L1196
  #pragma HLS stream variable=v653 depth=10 type=fifo

  #pragma HLS bind_storage variable=v653 type=ram_t2p impl=bram

  main_graph_node6(v652, v629, v653);	// L1197
  int8_t v654[1][1024][20][6];	// L1198
  #pragma HLS stream variable=v654 depth=10 type=fifo

  #pragma HLS bind_storage variable=v654 type=ram_t2p impl=bram

  main_graph_node5(v628, v653, v654);	// L1199
  int8_t v655[1][256][1][1];	// L1200
  #pragma HLS bind_storage variable=v655 type=ram_t2p impl=bram

  main_graph_node4(v627, v654, v655);	// L1201
  int8_t v656[1][4096];	// L1202
  #pragma HLS bind_storage variable=v656 type=ram_t2p impl=bram

  main_graph_node3(v655, v637, v656);	// L1203
  int8_t v657[1][4096];	// L1204
  #pragma HLS bind_storage variable=v657 type=ram_t2p impl=bram

  main_graph_node2(v656, v626, v657);	// L1205
  int8_t v658[1][1470];	// L1206
  #pragma HLS bind_storage variable=v658 type=ram_t2p impl=bram

  main_graph_node1(v657, v638, v658);	// L1207
  main_graph_node0(v658, v625, v639);	// L1208
  return ;	// L1209
}

