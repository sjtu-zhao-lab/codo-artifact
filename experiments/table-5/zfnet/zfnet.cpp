
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
  int8_t v0[1][4096],
  int8_t v1[4096][1000],
  int8_t v2[1000],
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
      for (int v10 = 0; v10 < 4096; v10 += 1) {	// L21
        int8_t v11 = v0[v8][v10];	// L22
        int8_t v12 = v1[v10][v9];	// L23
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
      int8_t v19 = v2[v17];	// L34
      int8_t v20 = v18 + v19;	// L35
      v3[v16][v17] = v20;	// L36
    }
  }
}

void main_graph_node1(
  int8_t v21[1][4096][1][1],
  int8_t v22[4096],
  int8_t v23[4096][4096],
  int8_t v24[1][4096]
) {	// L41
  #pragma HLS dataflow

  int8_t v25[1][4096];	// L43
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  int8_t v26[1][4096];	// L44
  #pragma HLS bind_storage variable=v26 type=ram_t2p impl=bram

  for (int v27 = 0; v27 < 1; v27 += 1) {	// L45
    for (int v28 = 0; v28 < 4096; v28 += 1) {	// L46
      v25[v27][v28] = (int8_t)0.000000;	// L47
    }
  }
  for (int v29 = 0; v29 < 1; v29 += 1) {	// L50
    for (int v30 = 0; v30 < 4096; v30 += 1) {	// L51
      for (int v31 = 0; v31 < 4096; v31 += 1) {	// L52
        int8_t v32 = v21[v29][v31][0][0];	// L53
        int8_t v33 = v23[v31][v30];	// L54
        int8_t v34 = v25[v29][v30];	// L55
        int8_t v35 = v32 * v33;	// L56
        int8_t v36 = v34 + v35;	// L57
        v26[v29][v30] = v36;	// L58
      }
    }
  }
  for (int v37 = 0; v37 < 1; v37 += 1) {	// L62
    for (int v38 = 0; v38 < 4096; v38 += 1) {	// L63
      int8_t v39 = v26[0][v38];	// L64
      int8_t v40 = v22[v38];	// L65
      int8_t v41 = v39 + v40;	// L66
      bool v42 = v41 > (int8_t)0.000000;	// L67
      int8_t v43 = v42 ? v41 : (int8_t)0.000000;	// L68
      v24[v37][v38] = v43;	// L69
    }
  }
}

void main_graph_node2(
  int8_t v44[1][256][5][5],
  int8_t v45[4096][256][5][5],
  int8_t v46[1][4096][1][1]
) {	// L74
  #pragma HLS dataflow

  int8_t v47[1][4096][1][1];	// L76
  #pragma HLS stream variable=v47 depth=10 type=fifo

  #pragma HLS bind_storage variable=v47 type=ram_t2p impl=bram

  int8_t v48[1][256][5][5];	// L77
  #pragma HLS array_partition variable=v48 cyclic factor=5 dim=3
  #pragma HLS bind_storage variable=v48 type=ram_2p impl=bram

  int8_t v49[1][256][5][5];	// L78
  #pragma HLS array_partition variable=v49 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v49 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v49 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v49 type=ram_2p impl=lutram

  for (int v50 = 0; v50 < 1; v50 += 1) {	// L79
    for (int v51 = 0; v51 < 5; v51 += 1) {	// L80
      for (int v52 = 0; v52 < 5; v52 += 1) {	// L81
        for (int v53 = 0; v53 < 256; v53 += 1) {	// L82
          int8_t v54 = v48[v50][v53][1][v52];	// L83
          v48[v50][v53][0][v52] = v54;	// L84
          int8_t v55 = v48[v50][v53][2][v52];	// L85
          v48[v50][v53][1][v52] = v55;	// L86
          int8_t v56 = v48[v50][v53][3][v52];	// L87
          v48[v50][v53][2][v52] = v56;	// L88
          int8_t v57 = v48[v50][v53][4][v52];	// L89
          v48[v50][v53][3][v52] = v57;	// L90
          int8_t v58 = v44[v50][v53][v51][v52];	// L91
          v48[v50][v53][4][v52] = v58;	// L92
        }
        if ((v51 - 4) >= 0) {	// L94
          for (int v59 = 0; v59 < 256; v59 += 1) {	// L95
            for (int v60 = 0; v60 < 5; v60 += 1) {	// L96
              int8_t v61 = v49[v50][v59][v60][1];	// L97
              v49[v50][v59][v60][0] = v61;	// L98
              int8_t v62 = v49[v50][v59][v60][2];	// L99
              v49[v50][v59][v60][1] = v62;	// L100
              int8_t v63 = v49[v50][v59][v60][3];	// L101
              v49[v50][v59][v60][2] = v63;	// L102
              int8_t v64 = v49[v50][v59][v60][4];	// L103
              v49[v50][v59][v60][3] = v64;	// L104
              int8_t v65 = v48[v50][v59][v60][v52];	// L105
              v49[v50][v59][v60][4] = v65;	// L106
            }
          }
          if ((v52 - 4) >= 0) {	// L109
            int8_t v66[4096];	// L110
            #pragma HLS bind_storage variable=v66 type=ram_2p impl=bram

            for (int v67 = 0; v67 < 4096; v67 += 1) {	// L111
              v66[v67] = (int8_t)0.000000;	// L112
              for (int v68 = 0; v68 < 32; v68 += 1) {	// L113
                #pragma HLS pipeline II=1
                for (int v69 = 0; v69 < 8; v69 += 1) {	// L114
                  for (int v70 = 0; v70 < 5; v70 += 1) {	// L115
                    for (int v71 = 0; v71 < 5; v71 += 1) {	// L116
                      int8_t v72 = v49[v50][(v69 + (v68 * 8))][v70][v71];	// L117
                      int8_t v73 = v45[v67][(v69 + (v68 * 8))][v70][v71];	// L118
                      int8_t v74 = v72 * v73;	// L119
                      int8_t v75 = v66[v67];	// L120
                      int8_t v76 = v75 + v74;	// L121
                      v66[v67] = v76;	// L122
                    }
                  }
                }
              }
              int8_t v77 = v66[v67];	// L127
              v47[v50][v67][(v51 - 4)][(v52 - 4)] = v77;	// L128
            }
          }
        }
      }
    }
  }
  for (int v78 = 0; v78 < 1; v78 += 1) {	// L135
    for (int v79 = 0; v79 < 1; v79 += 1) {	// L136
      for (int v80 = 0; v80 < 1; v80 += 1) {	// L137
        for (int v81 = 0; v81 < 4096; v81 += 1) {	// L138
          int8_t v82 = v47[0][v81][0][0];	// L139
          bool v83 = v82 > (int8_t)0.000000;	// L140
          int8_t v84 = v83 ? v82 : (int8_t)0.000000;	// L141
          v46[v78][v81][v79][v80] = v84;	// L142
        }
      }
    }
  }
}

void main_graph_node3(
  int8_t v85[1][256][12][12],
  int8_t v86[1][256][5][5]
) {	// L149
  #pragma HLS dataflow

  int8_t v87;	// L152
  v87 = (int8_t)-INFINITY;	// L153
  int8_t v88[1][256][12][12];	// L154
  #pragma HLS bind_storage variable=v88 type=ram_2p impl=bram

  for (int v89 = 0; v89 < 1; v89 += 1) {	// L155
    for (int v90 = 0; v90 < 12; v90 += 1) {	// L156
      for (int v91 = 0; v91 < 12; v91 += 1) {	// L157
        for (int v92 = 0; v92 < 256; v92 += 1) {	// L158
          int8_t v93 = v85[v89][v92][v90][v91];	// L159
          v88[v89][v92][v90][v91] = v93;	// L160
        }
      }
    }
  }
  for (int v94 = 0; v94 < 1; v94 += 1) {	// L165
    for (int v95 = 0; v95 < 5; v95 += 1) {	// L166
      for (int v96 = 0; v96 < 5; v96 += 1) {	// L167
        for (int v97 = 0; v97 < 256; v97 += 1) {	// L168
          int8_t v98;	// L169
          v98 = (int8_t)0.000000;	// L170
          for (int v99 = 0; v99 < 3; v99 += 1) {	// L171
            for (int v100 = 0; v100 < 3; v100 += 1) {	// L172
              int8_t v101 = v88[v94][v97][((v95 * 2) + v99)][((v96 * 2) + v100)];	// L173
              int8_t v102 = v87;	// L174
              int8_t v103 = max(v102, v101);	// L175
              v98 = v103;	// L176
            }
          }
          int8_t v104 = v98;	// L179
          v86[v94][v97][v95][v96] = v104;	// L180
        }
      }
    }
  }
}

void main_graph_node4(
  int8_t v105[256][384][3][3],
  int8_t v106[1][384][12][12],
  int8_t v107[1][256][12][12]
) {	// L187
  #pragma HLS dataflow

  int8_t v108[1][384][14][14];	// L189
  #pragma HLS stream variable=v108 depth=10 type=fifo

  #pragma HLS bind_storage variable=v108 type=ram_t2p impl=bram

  for (int v109 = 0; v109 < 1; v109 += 1) {	// L190
    for (int v110 = 0; v110 < 14; v110 += 1) {	// L191
      for (int v111 = 0; v111 < 14; v111 += 1) {	// L192
        for (int v112 = 0; v112 < 384; v112 += 1) {	// L193
          int8_t v113;	// L194
          v113 = (int8_t)0.000000;	// L195
          if (((-v110) + 11) >= 0 && ((-v111) + 11) >= 0) {	// L196
            int8_t v114 = v106[v109][v112][v110][v111];	// L197
            v113 = v114;	// L198
          }
          int8_t v115 = v113;	// L200
          v108[v109][v112][v110][v111] = v115;	// L201
        }
      }
    }
  }
  int8_t v116[1][256][12][12];	// L206
  #pragma HLS stream variable=v116 depth=10 type=fifo

  #pragma HLS bind_storage variable=v116 type=ram_t2p impl=bram

  int8_t v117[1][384][3][14];	// L207
  #pragma HLS array_partition variable=v117 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v117 type=ram_2p impl=bram

  int8_t v118[1][384][3][3];	// L208
  #pragma HLS array_partition variable=v118 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v118 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v118 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v118 type=ram_2p impl=lutram

  for (int v119 = 0; v119 < 1; v119 += 1) {	// L209
    for (int v120 = 0; v120 < 14; v120 += 1) {	// L210
      for (int v121 = 0; v121 < 14; v121 += 1) {	// L211
        for (int v122 = 0; v122 < 384; v122 += 1) {	// L212
          int8_t v123 = v117[v119][v122][1][v121];	// L213
          v117[v119][v122][0][v121] = v123;	// L214
          int8_t v124 = v117[v119][v122][2][v121];	// L215
          v117[v119][v122][1][v121] = v124;	// L216
          int8_t v125 = v108[v119][v122][v120][v121];	// L217
          v117[v119][v122][2][v121] = v125;	// L218
        }
        if ((v120 - 2) >= 0) {	// L220
          for (int v126 = 0; v126 < 384; v126 += 1) {	// L221
            for (int v127 = 0; v127 < 3; v127 += 1) {	// L222
              int8_t v128 = v118[v119][v126][v127][1];	// L223
              v118[v119][v126][v127][0] = v128;	// L224
              int8_t v129 = v118[v119][v126][v127][2];	// L225
              v118[v119][v126][v127][1] = v129;	// L226
              int8_t v130 = v117[v119][v126][v127][v121];	// L227
              v118[v119][v126][v127][2] = v130;	// L228
            }
          }
          if ((v121 - 2) >= 0) {	// L231
            int8_t v131[256];	// L232
            #pragma HLS bind_storage variable=v131 type=ram_2p impl=bram

            for (int v132 = 0; v132 < 256; v132 += 1) {	// L233
              v131[v132] = (int8_t)0.000000;	// L234
              for (int v133 = 0; v133 < 96; v133 += 1) {	// L235
                #pragma HLS pipeline II=1
                for (int v134 = 0; v134 < 4; v134 += 1) {	// L236
                  for (int v135 = 0; v135 < 3; v135 += 1) {	// L237
                    for (int v136 = 0; v136 < 3; v136 += 1) {	// L238
                      int8_t v137 = v118[v119][(v134 + (v133 * 4))][v135][v136];	// L239
                      int8_t v138 = v105[v132][(v134 + (v133 * 4))][v135][v136];	// L240
                      int8_t v139 = v137 * v138;	// L241
                      int8_t v140 = v131[v132];	// L242
                      int8_t v141 = v140 + v139;	// L243
                      v131[v132] = v141;	// L244
                    }
                  }
                }
              }
              int8_t v142 = v131[v132];	// L249
              v116[v119][v132][(v120 - 2)][(v121 - 2)] = v142;	// L250
            }
          }
        }
      }
    }
  }
  for (int v143 = 0; v143 < 1; v143 += 1) {	// L257
    for (int v144 = 0; v144 < 12; v144 += 1) {	// L258
      for (int v145 = 0; v145 < 12; v145 += 1) {	// L259
        for (int v146 = 0; v146 < 256; v146 += 1) {	// L260
          int8_t v147 = v116[0][v146][v144][v145];	// L261
          bool v148 = v147 > (int8_t)0.000000;	// L262
          int8_t v149 = v148 ? v147 : (int8_t)0.000000;	// L263
          v107[v143][v146][v144][v145] = v149;	// L264
        }
      }
    }
  }
}

void main_graph_node5(
  int8_t v150[384][384][3][3],
  int8_t v151[1][384][12][12],
  int8_t v152[1][384][12][12]
) {	// L271
  #pragma HLS dataflow

  int8_t v153[1][384][14][14];	// L273
  #pragma HLS stream variable=v153 depth=10 type=fifo

  #pragma HLS bind_storage variable=v153 type=ram_t2p impl=bram

  for (int v154 = 0; v154 < 1; v154 += 1) {	// L274
    for (int v155 = 0; v155 < 14; v155 += 1) {	// L275
      for (int v156 = 0; v156 < 14; v156 += 1) {	// L276
        for (int v157 = 0; v157 < 384; v157 += 1) {	// L277
          int8_t v158;	// L278
          v158 = (int8_t)0.000000;	// L279
          if (((-v155) + 11) >= 0 && ((-v156) + 11) >= 0) {	// L280
            int8_t v159 = v151[v154][v157][v155][v156];	// L281
            v158 = v159;	// L282
          }
          int8_t v160 = v158;	// L284
          v153[v154][v157][v155][v156] = v160;	// L285
        }
      }
    }
  }
  int8_t v161[1][384][12][12];	// L290
  #pragma HLS stream variable=v161 depth=10 type=fifo

  #pragma HLS bind_storage variable=v161 type=ram_t2p impl=bram

  int8_t v162[1][384][3][14];	// L291
  #pragma HLS array_partition variable=v162 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v162 type=ram_2p impl=bram

  int8_t v163[1][384][3][3];	// L292
  #pragma HLS array_partition variable=v163 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v163 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v163 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v163 type=ram_2p impl=lutram

  for (int v164 = 0; v164 < 1; v164 += 1) {	// L293
    for (int v165 = 0; v165 < 14; v165 += 1) {	// L294
      for (int v166 = 0; v166 < 14; v166 += 1) {	// L295
        for (int v167 = 0; v167 < 384; v167 += 1) {	// L296
          int8_t v168 = v162[v164][v167][1][v166];	// L297
          v162[v164][v167][0][v166] = v168;	// L298
          int8_t v169 = v162[v164][v167][2][v166];	// L299
          v162[v164][v167][1][v166] = v169;	// L300
          int8_t v170 = v153[v164][v167][v165][v166];	// L301
          v162[v164][v167][2][v166] = v170;	// L302
        }
        if ((v165 - 2) >= 0) {	// L304
          for (int v171 = 0; v171 < 384; v171 += 1) {	// L305
            for (int v172 = 0; v172 < 3; v172 += 1) {	// L306
              int8_t v173 = v163[v164][v171][v172][1];	// L307
              v163[v164][v171][v172][0] = v173;	// L308
              int8_t v174 = v163[v164][v171][v172][2];	// L309
              v163[v164][v171][v172][1] = v174;	// L310
              int8_t v175 = v162[v164][v171][v172][v166];	// L311
              v163[v164][v171][v172][2] = v175;	// L312
            }
          }
          if ((v166 - 2) >= 0) {	// L315
            int8_t v176[384];	// L316
            #pragma HLS bind_storage variable=v176 type=ram_2p impl=bram

            for (int v177 = 0; v177 < 384; v177 += 1) {	// L317
              v176[v177] = (int8_t)0.000000;	// L318
              for (int v178 = 0; v178 < 48; v178 += 1) {	// L319
                #pragma HLS pipeline II=1
                for (int v179 = 0; v179 < 8; v179 += 1) {	// L320
                  for (int v180 = 0; v180 < 3; v180 += 1) {	// L321
                    for (int v181 = 0; v181 < 3; v181 += 1) {	// L322
                      int8_t v182 = v163[v164][(v179 + (v178 * 8))][v180][v181];	// L323
                      int8_t v183 = v150[v177][(v179 + (v178 * 8))][v180][v181];	// L324
                      int8_t v184 = v182 * v183;	// L325
                      int8_t v185 = v176[v177];	// L326
                      int8_t v186 = v185 + v184;	// L327
                      v176[v177] = v186;	// L328
                    }
                  }
                }
              }
              int8_t v187 = v176[v177];	// L333
              v161[v164][v177][(v165 - 2)][(v166 - 2)] = v187;	// L334
            }
          }
        }
      }
    }
  }
  for (int v188 = 0; v188 < 1; v188 += 1) {	// L341
    for (int v189 = 0; v189 < 12; v189 += 1) {	// L342
      for (int v190 = 0; v190 < 12; v190 += 1) {	// L343
        for (int v191 = 0; v191 < 384; v191 += 1) {	// L344
          int8_t v192 = v161[0][v191][v189][v190];	// L345
          bool v193 = v192 > (int8_t)0.000000;	// L346
          int8_t v194 = v193 ? v192 : (int8_t)0.000000;	// L347
          v152[v188][v191][v189][v190] = v194;	// L348
        }
      }
    }
  }
}

void main_graph_node6(
  int8_t v195[1][256][12][12],
  int8_t v196[384][256][3][3],
  int8_t v197[1][384][12][12]
) {	// L355
  #pragma HLS dataflow

  int8_t v198[1][256][14][14];	// L357
  #pragma HLS stream variable=v198 depth=10 type=fifo

  #pragma HLS bind_storage variable=v198 type=ram_t2p impl=bram

  for (int v199 = 0; v199 < 1; v199 += 1) {	// L358
    for (int v200 = 0; v200 < 14; v200 += 1) {	// L359
      for (int v201 = 0; v201 < 14; v201 += 1) {	// L360
        for (int v202 = 0; v202 < 256; v202 += 1) {	// L361
          int8_t v203;	// L362
          v203 = (int8_t)0.000000;	// L363
          if (((-v200) + 11) >= 0 && ((-v201) + 11) >= 0) {	// L364
            int8_t v204 = v195[v199][v202][v200][v201];	// L365
            v203 = v204;	// L366
          }
          int8_t v205 = v203;	// L368
          v198[v199][v202][v200][v201] = v205;	// L369
        }
      }
    }
  }
  int8_t v206[1][384][12][12];	// L374
  #pragma HLS stream variable=v206 depth=10 type=fifo

  #pragma HLS bind_storage variable=v206 type=ram_t2p impl=bram

  int8_t v207[1][256][3][14];	// L375
  #pragma HLS array_partition variable=v207 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v207 type=ram_2p impl=bram

  int8_t v208[1][256][3][3];	// L376
  #pragma HLS array_partition variable=v208 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v208 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v208 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v208 type=ram_2p impl=lutram

  for (int v209 = 0; v209 < 1; v209 += 1) {	// L377
    for (int v210 = 0; v210 < 14; v210 += 1) {	// L378
      for (int v211 = 0; v211 < 14; v211 += 1) {	// L379
        for (int v212 = 0; v212 < 256; v212 += 1) {	// L380
          int8_t v213 = v207[v209][v212][1][v211];	// L381
          v207[v209][v212][0][v211] = v213;	// L382
          int8_t v214 = v207[v209][v212][2][v211];	// L383
          v207[v209][v212][1][v211] = v214;	// L384
          int8_t v215 = v198[v209][v212][v210][v211];	// L385
          v207[v209][v212][2][v211] = v215;	// L386
        }
        if ((v210 - 2) >= 0) {	// L388
          for (int v216 = 0; v216 < 256; v216 += 1) {	// L389
            for (int v217 = 0; v217 < 3; v217 += 1) {	// L390
              int8_t v218 = v208[v209][v216][v217][1];	// L391
              v208[v209][v216][v217][0] = v218;	// L392
              int8_t v219 = v208[v209][v216][v217][2];	// L393
              v208[v209][v216][v217][1] = v219;	// L394
              int8_t v220 = v207[v209][v216][v217][v211];	// L395
              v208[v209][v216][v217][2] = v220;	// L396
            }
          }
          if ((v211 - 2) >= 0) {	// L399
            int8_t v221[384];	// L400
            #pragma HLS bind_storage variable=v221 type=ram_2p impl=bram

            for (int v222 = 0; v222 < 384; v222 += 1) {	// L401
              v221[v222] = (int8_t)0.000000;	// L402
              for (int v223 = 0; v223 < 64; v223 += 1) {	// L403
                #pragma HLS pipeline II=1
                for (int v224 = 0; v224 < 4; v224 += 1) {	// L404
                  for (int v225 = 0; v225 < 3; v225 += 1) {	// L405
                    for (int v226 = 0; v226 < 3; v226 += 1) {	// L406
                      int8_t v227 = v208[v209][(v224 + (v223 * 4))][v225][v226];	// L407
                      int8_t v228 = v196[v222][(v224 + (v223 * 4))][v225][v226];	// L408
                      int8_t v229 = v227 * v228;	// L409
                      int8_t v230 = v221[v222];	// L410
                      int8_t v231 = v230 + v229;	// L411
                      v221[v222] = v231;	// L412
                    }
                  }
                }
              }
              int8_t v232 = v221[v222];	// L417
              v206[v209][v222][(v210 - 2)][(v211 - 2)] = v232;	// L418
            }
          }
        }
      }
    }
  }
  for (int v233 = 0; v233 < 1; v233 += 1) {	// L425
    for (int v234 = 0; v234 < 12; v234 += 1) {	// L426
      for (int v235 = 0; v235 < 12; v235 += 1) {	// L427
        for (int v236 = 0; v236 < 384; v236 += 1) {	// L428
          int8_t v237 = v206[0][v236][v234][v235];	// L429
          bool v238 = v237 > (int8_t)0.000000;	// L430
          int8_t v239 = v238 ? v237 : (int8_t)0.000000;	// L431
          v197[v233][v236][v234][v235] = v239;	// L432
        }
      }
    }
  }
}

void main_graph_node7(
  int8_t v240[1][256][26][26],
  int8_t v241[1][256][12][12]
) {	// L439
  #pragma HLS dataflow

  int8_t v242;	// L442
  v242 = (int8_t)-INFINITY;	// L443
  int8_t v243[1][256][26][26];	// L444
  #pragma HLS bind_storage variable=v243 type=ram_2p impl=bram

  for (int v244 = 0; v244 < 1; v244 += 1) {	// L445
    for (int v245 = 0; v245 < 26; v245 += 1) {	// L446
      for (int v246 = 0; v246 < 26; v246 += 1) {	// L447
        for (int v247 = 0; v247 < 256; v247 += 1) {	// L448
          int8_t v248 = v240[v244][v247][v245][v246];	// L449
          v243[v244][v247][v245][v246] = v248;	// L450
        }
      }
    }
  }
  for (int v249 = 0; v249 < 1; v249 += 1) {	// L455
    for (int v250 = 0; v250 < 12; v250 += 1) {	// L456
      for (int v251 = 0; v251 < 12; v251 += 1) {	// L457
        for (int v252 = 0; v252 < 256; v252 += 1) {	// L458
          int8_t v253;	// L459
          v253 = (int8_t)0.000000;	// L460
          for (int v254 = 0; v254 < 3; v254 += 1) {	// L461
            for (int v255 = 0; v255 < 3; v255 += 1) {	// L462
              int8_t v256 = v243[v249][v252][((v250 * 2) + v254)][((v251 * 2) + v255)];	// L463
              int8_t v257 = v242;	// L464
              int8_t v258 = max(v257, v256);	// L465
              v253 = v258;	// L466
            }
          }
          int8_t v259 = v253;	// L469
          v241[v249][v252][v250][v251] = v259;	// L470
        }
      }
    }
  }
}

void main_graph_node8(
  int8_t v260[1][96][54][54],
  int8_t v261[256][96][5][5],
  int8_t v262[1][256][26][26]
) {	// L477
  #pragma HLS dataflow

  int8_t v263[1][96][56][56];	// L479
  #pragma HLS stream variable=v263 depth=10 type=fifo

  #pragma HLS bind_storage variable=v263 type=ram_t2p impl=bram

  for (int v264 = 0; v264 < 1; v264 += 1) {	// L480
    for (int v265 = 0; v265 < 56; v265 += 1) {	// L481
      for (int v266 = 0; v266 < 56; v266 += 1) {	// L482
        for (int v267 = 0; v267 < 96; v267 += 1) {	// L483
          int8_t v268;	// L484
          v268 = (int8_t)0.000000;	// L485
          if (((-v265) + 53) >= 0 && ((-v266) + 53) >= 0) {	// L486
            int8_t v269 = v260[v264][v267][v265][v266];	// L487
            v268 = v269;	// L488
          }
          int8_t v270 = v268;	// L490
          v263[v264][v267][v265][v266] = v270;	// L491
        }
      }
    }
  }
  int8_t v271[1][256][26][26];	// L496
  #pragma HLS stream variable=v271 depth=10 type=fifo

  #pragma HLS bind_storage variable=v271 type=ram_t2p impl=bram

  int8_t v272[1][96][5][56];	// L497
  #pragma HLS array_partition variable=v272 cyclic factor=5 dim=3
  #pragma HLS bind_storage variable=v272 type=ram_2p impl=bram

  int8_t v273[1][96][5][5];	// L498
  #pragma HLS array_partition variable=v273 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v273 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v273 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v273 type=ram_2p impl=lutram

  for (int v274 = 0; v274 < 1; v274 += 1) {	// L499
    for (int v275 = 0; v275 < 56; v275 += 1) {	// L500
      for (int v276 = 0; v276 < 56; v276 += 1) {	// L501
        for (int v277 = 0; v277 < 96; v277 += 1) {	// L502
          int8_t v278 = v272[v274][v277][1][v276];	// L503
          v272[v274][v277][0][v276] = v278;	// L504
          int8_t v279 = v272[v274][v277][2][v276];	// L505
          v272[v274][v277][1][v276] = v279;	// L506
          int8_t v280 = v272[v274][v277][3][v276];	// L507
          v272[v274][v277][2][v276] = v280;	// L508
          int8_t v281 = v272[v274][v277][4][v276];	// L509
          v272[v274][v277][3][v276] = v281;	// L510
          int8_t v282 = v263[v274][v277][v275][v276];	// L511
          v272[v274][v277][4][v276] = v282;	// L512
        }
        if ((v275 - 30) >= 0) {	// L514
          for (int v283 = 0; v283 < 96; v283 += 1) {	// L515
            for (int v284 = 0; v284 < 5; v284 += 1) {	// L516
              int8_t v285 = v273[v274][v283][v284][1];	// L517
              v273[v274][v283][v284][0] = v285;	// L518
              int8_t v286 = v273[v274][v283][v284][2];	// L519
              v273[v274][v283][v284][1] = v286;	// L520
              int8_t v287 = v273[v274][v283][v284][3];	// L521
              v273[v274][v283][v284][2] = v287;	// L522
              int8_t v288 = v273[v274][v283][v284][4];	// L523
              v273[v274][v283][v284][3] = v288;	// L524
              int8_t v289 = v272[v274][v283][v284][v276];	// L525
              v273[v274][v283][v284][4] = v289;	// L526
            }
          }
          if ((v276 - 30) >= 0) {	// L529
            int8_t v290[256];	// L530
            #pragma HLS bind_storage variable=v290 type=ram_2p impl=bram

            for (int v291 = 0; v291 < 256; v291 += 1) {	// L531
              v290[v291] = (int8_t)0.000000;	// L532
              for (int v292 = 0; v292 < 6; v292 += 1) {	// L533
                #pragma HLS pipeline II=1
                for (int v293 = 0; v293 < 16; v293 += 1) {	// L534
                  for (int v294 = 0; v294 < 5; v294 += 1) {	// L535
                    for (int v295 = 0; v295 < 5; v295 += 1) {	// L536
                      int8_t v296 = v273[v274][(v293 + (v292 * 16))][v294][v295];	// L537
                      int8_t v297 = v261[v291][(v293 + (v292 * 16))][v294][v295];	// L538
                      int8_t v298 = v296 * v297;	// L539
                      int8_t v299 = v290[v291];	// L540
                      int8_t v300 = v299 + v298;	// L541
                      v290[v291] = v300;	// L542
                    }
                  }
                }
              }
              int8_t v301 = v290[v291];	// L547
              v271[v274][v291][(v275 - 30)][(v276 - 30)] = v301;	// L548
            }
          }
        }
      }
    }
  }
  for (int v302 = 0; v302 < 1; v302 += 1) {	// L555
    for (int v303 = 0; v303 < 26; v303 += 1) {	// L556
      for (int v304 = 0; v304 < 26; v304 += 1) {	// L557
        for (int v305 = 0; v305 < 256; v305 += 1) {	// L558
          int8_t v306 = v271[0][v305][v303][v304];	// L559
          bool v307 = v306 > (int8_t)0.000000;	// L560
          int8_t v308 = v307 ? v306 : (int8_t)0.000000;	// L561
          v262[v302][v305][v303][v304] = v308;	// L562
        }
      }
    }
  }
}

void main_graph_node9(
  int8_t v309[1][96][110][110],
  int8_t v310[1][96][54][54]
) {	// L569
  #pragma HLS dataflow

  int8_t v311;	// L572
  v311 = (int8_t)-INFINITY;	// L573
  int8_t v312[1][96][110][110];	// L574
  #pragma HLS array_partition variable=v312 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v312 type=ram_2p impl=bram

  for (int v313 = 0; v313 < 1; v313 += 1) {	// L575
    for (int v314 = 0; v314 < 110; v314 += 1) {	// L576
      for (int v315 = 0; v315 < 110; v315 += 1) {	// L577
        for (int v316 = 0; v316 < 48; v316 += 1) {	// L578
          #pragma HLS pipeline II=1
          for (int v317 = 0; v317 < 2; v317 += 1) {	// L579
            int8_t v318 = v309[v313][(v317 + (v316 * 2))][v314][v315];	// L580
            v312[v313][(v317 + (v316 * 2))][v314][v315] = v318;	// L581
          }
        }
      }
    }
  }
  for (int v319 = 0; v319 < 1; v319 += 1) {	// L587
    for (int v320 = 0; v320 < 54; v320 += 1) {	// L588
      for (int v321 = 0; v321 < 54; v321 += 1) {	// L589
        for (int v322 = 0; v322 < 96; v322 += 1) {	// L590
          int8_t v323;	// L591
          v323 = (int8_t)0.000000;	// L592
          for (int v324 = 0; v324 < 3; v324 += 1) {	// L593
            for (int v325 = 0; v325 < 3; v325 += 1) {	// L594
              int8_t v326 = v312[v319][v322][((v320 * 2) + v324)][((v321 * 2) + v325)];	// L595
              int8_t v327 = v311;	// L596
              int8_t v328 = max(v327, v326);	// L597
              v323 = v328;	// L598
            }
          }
          int8_t v329 = v323;	// L601
          v310[v319][v322][v320][v321] = v329;	// L602
        }
      }
    }
  }
}

void main_graph_node10(
  int8_t v330[96][3][7][7],
  int8_t v331[1][3][224][224],
  int8_t v332[1][96][110][110]
) {	// L609
  #pragma HLS dataflow

  int8_t v333[1][3][226][226];	// L611
  #pragma HLS stream variable=v333 depth=10 type=fifo

  #pragma HLS bind_storage variable=v333 type=ram_t2p impl=bram

  for (int v334 = 0; v334 < 1; v334 += 1) {	// L612
    for (int v335 = 0; v335 < 226; v335 += 1) {	// L613
      for (int v336 = 0; v336 < 226; v336 += 1) {	// L614
        for (int v337 = 0; v337 < 3; v337 += 1) {	// L615
          int8_t v338;	// L616
          v338 = (int8_t)0.000000;	// L617
          if (((-v335) + 223) >= 0 && ((-v336) + 223) >= 0) {	// L618
            int8_t v339 = v331[v334][v337][v335][v336];	// L619
            v338 = v339;	// L620
          }
          int8_t v340 = v338;	// L622
          v333[v334][v337][v335][v336] = v340;	// L623
        }
      }
    }
  }
  int8_t v341[1][96][110][110];	// L628
  #pragma HLS stream variable=v341 depth=10 type=fifo

  #pragma HLS array_partition variable=v341 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v341 type=ram_t2p impl=bram

  int8_t v342[1][3][7][226];	// L629
  #pragma HLS array_partition variable=v342 cyclic factor=7 dim=3
  #pragma HLS bind_storage variable=v342 type=ram_2p impl=lutram

  int8_t v343[1][3][7][7];	// L630
  #pragma HLS array_partition variable=v343 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v343 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v343 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v343 type=ram_2p impl=lutram

  for (int v344 = 0; v344 < 1; v344 += 1) {	// L631
    for (int v345 = 0; v345 < 226; v345 += 1) {	// L632
      for (int v346 = 0; v346 < 226; v346 += 1) {	// L633
        for (int v347 = 0; v347 < 3; v347 += 1) {	// L634
          int8_t v348 = v342[v344][v347][1][v346];	// L635
          v342[v344][v347][0][v346] = v348;	// L636
          int8_t v349 = v342[v344][v347][2][v346];	// L637
          v342[v344][v347][1][v346] = v349;	// L638
          int8_t v350 = v342[v344][v347][3][v346];	// L639
          v342[v344][v347][2][v346] = v350;	// L640
          int8_t v351 = v342[v344][v347][4][v346];	// L641
          v342[v344][v347][3][v346] = v351;	// L642
          int8_t v352 = v342[v344][v347][5][v346];	// L643
          v342[v344][v347][4][v346] = v352;	// L644
          int8_t v353 = v342[v344][v347][6][v346];	// L645
          v342[v344][v347][5][v346] = v353;	// L646
          int8_t v354 = v333[v344][v347][v345][v346];	// L647
          v342[v344][v347][6][v346] = v354;	// L648
        }
        if ((v345 - 116) >= 0) {	// L650
          for (int v355 = 0; v355 < 3; v355 += 1) {	// L651
            for (int v356 = 0; v356 < 7; v356 += 1) {	// L652
              int8_t v357 = v343[v344][v355][v356][1];	// L653
              v343[v344][v355][v356][0] = v357;	// L654
              int8_t v358 = v343[v344][v355][v356][2];	// L655
              v343[v344][v355][v356][1] = v358;	// L656
              int8_t v359 = v343[v344][v355][v356][3];	// L657
              v343[v344][v355][v356][2] = v359;	// L658
              int8_t v360 = v343[v344][v355][v356][4];	// L659
              v343[v344][v355][v356][3] = v360;	// L660
              int8_t v361 = v343[v344][v355][v356][5];	// L661
              v343[v344][v355][v356][4] = v361;	// L662
              int8_t v362 = v343[v344][v355][v356][6];	// L663
              v343[v344][v355][v356][5] = v362;	// L664
              int8_t v363 = v342[v344][v355][v356][v346];	// L665
              v343[v344][v355][v356][6] = v363;	// L666
            }
          }
          if ((v346 - 116) >= 0) {	// L669
            int8_t v364[96];	// L670
            #pragma HLS array_partition variable=v364 cyclic factor=2 dim=1
            #pragma HLS bind_storage variable=v364 type=ram_2p impl=lutram

            for (int v365 = 0; v365 < 48; v365 += 1) {	// L671
              #pragma HLS pipeline II=1
              for (int v366 = 0; v366 < 2; v366 += 1) {	// L672
                v364[(v366 + (v365 * 2))] = (int8_t)0.000000;	// L673
                for (int v367 = 0; v367 < 3; v367 += 1) {	// L674
                  for (int v368 = 0; v368 < 7; v368 += 1) {	// L675
                    for (int v369 = 0; v369 < 7; v369 += 1) {	// L676
                      int8_t v370 = v343[v344][v367][v368][v369];	// L677
                      int8_t v371 = v330[(v366 + (v365 * 2))][v367][v368][v369];	// L678
                      int8_t v372 = v370 * v371;	// L679
                      int8_t v373 = v364[(v366 + (v365 * 2))];	// L680
                      int8_t v374 = v373 + v372;	// L681
                      v364[(v366 + (v365 * 2))] = v374;	// L682
                    }
                  }
                }
                int8_t v375 = v364[(v366 + (v365 * 2))];	// L686
                v341[v344][(v366 + (v365 * 2))][(v345 - 116)][(v346 - 116)] = v375;	// L687
              }
            }
          }
        }
      }
    }
  }
  for (int v376 = 0; v376 < 1; v376 += 1) {	// L695
    for (int v377 = 0; v377 < 110; v377 += 1) {	// L696
      for (int v378 = 0; v378 < 110; v378 += 1) {	// L697
        for (int v379 = 0; v379 < 48; v379 += 1) {	// L698
          #pragma HLS pipeline II=1
          for (int v380 = 0; v380 < 2; v380 += 1) {	// L699
            int8_t v381 = v341[0][(v380 + (v379 * 2))][v377][v378];	// L700
            bool v382 = v381 > (int8_t)0.000000;	// L701
            int8_t v383 = v382 ? v381 : (int8_t)0.000000;	// L702
            v332[v376][(v380 + (v379 * 2))][v377][v378] = v383;	// L703
          }
        }
      }
    }
  }
}

void load_array(
    int8_t v384[1][3][224][224],ap_uint<256> *vv384,
    int8_t v385[1000],ap_uint<256> *vv385,
    int8_t v386[4096],ap_uint<256> *vv386,
    int8_t v387[4096][256][5][5],ap_uint<256> *vv387,
    int8_t v388[256][384][3][3],ap_uint<256> *vv388,
    int8_t v389[384][384][3][3],ap_uint<256> *vv389,
    int8_t v390[384][256][3][3],ap_uint<256> *vv390,
    int8_t v391[256][96][5][5],ap_uint<256> *vv391,
    int8_t v392[96][3][7][7],ap_uint<256> *vv392,
    int8_t v393[4096][4096],ap_uint<256> *vv393,
    int8_t v394[4096][1000],ap_uint<256> *vv394,
    int8_t v395[1][1000],ap_uint<256> *vv395
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
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 224; ++k) {
              for (int l = 0; l < 7; ++l) {
              temp_0 = vv384[i * 3 * 224 * 7 + j * 224 * 7 + k * 7 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v384[i][j][k][l * 32 + bias] = temp_0.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 31; ++i) { 
      temp_1 = vv385[i];
      for (int bias = 0; bias < 32; ++bias) { 
                    v385[i * 32 + bias] = temp_1.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 128; ++i) { 
      temp_2 = vv386[i];
      for (int bias = 0; bias < 32; ++bias) { 
                    v386[i * 32 + bias] = temp_2.range(bias*8+7, bias*8);
}
}
    for (int i = 0; i < 4096; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 5; ++k) {
              for (int l = 0; l < 5; ++l) {
              temp_3 = vv387[i * 8 * 5 * 5 + j * 5 * 5 + k * 5 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v387[i][j * 32 + bias][k][l] = temp_3.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 12; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_4 = vv388[i * 12 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v388[i][j * 32 + bias][k][l] = temp_4.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 384; ++i) {
      for (int j = 0; j < 12; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_5 = vv389[i * 12 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v389[i][j * 32 + bias][k][l] = temp_5.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 384; ++i) {
      for (int j = 0; j < 8; ++j) {
          for (int k = 0; k < 3; ++k) {
              for (int l = 0; l < 3; ++l) {
              temp_6 = vv390[i * 8 * 3 * 3 + j * 3 * 3 + k * 3 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v390[i][j * 32 + bias][k][l] = temp_6.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 256; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 5; ++k) {
              for (int l = 0; l < 5; ++l) {
              temp_7 = vv391[i * 3 * 5 * 5 + j * 5 * 5 + k * 5 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v391[i][j * 32 + bias][k][l] = temp_7.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 7; ++k) {
              for (int l = 0; l < 7; ++l) {
              temp_8 = vv392[i * 3 * 7 * 7 + j * 7 * 7 + k * 7 + l];
              for (int bias = 0; bias < 32; ++bias) { 
                  v392[i * 32 + bias][j][k][l] = temp_8.range(bias*8+7, bias*8);
}
}
}
}
}
    for (int i = 0; i < 4096; ++i) {
      for (int j = 0; j < 128; ++j) {
          temp_9 = vv393[i * 128 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v393[i][j * 32 + bias] = temp_9.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 4096; ++i) {
      for (int j = 0; j < 31; ++j) {
          temp_10 = vv394[i * 31 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v394[i][j * 32 + bias] = temp_10.range(bias*8+7, bias*8);
}
}
}
    for (int i = 0; i < 1; ++i) {
      for (int j = 0; j < 31; ++j) {
          temp_11 = vv395[i * 31 + j];
          for (int bias = 0; bias < 32; ++bias) { 
              v395[i][j * 32 + bias] = temp_11.range(bias*8+7, bias*8);
}
}
}
}



/// This is top function.
void main_graph(
    ap_uint<256> *vv384,
    ap_uint<256> *vv385,
    ap_uint<256> *vv386,
    ap_uint<256> *vv387,
    ap_uint<256> *vv388,
    ap_uint<256> *vv389,
    ap_uint<256> *vv390,
    ap_uint<256> *vv391,
    ap_uint<256> *vv392,
    ap_uint<256> *vv393,
    ap_uint<256> *vv394,
    ap_uint<256> *vv395
  
) {	// L711
  #pragma HLS interface s_axilite port=return 

  #pragma HLS INTERFACE m_axi port=vv384 offset = slave bundle=gmem0
  #pragma HLS INTERFACE m_axi port=vv385 offset = slave bundle=gmem1
  #pragma HLS INTERFACE m_axi port=vv386 offset = slave bundle=gmem2
  #pragma HLS INTERFACE m_axi port=vv387 offset = slave bundle=gmem3
  #pragma HLS INTERFACE m_axi port=vv388 offset = slave bundle=gmem4
  #pragma HLS INTERFACE m_axi port=vv389 offset = slave bundle=gmem5
  #pragma HLS INTERFACE m_axi port=vv390 offset = slave bundle=gmem6
  #pragma HLS INTERFACE m_axi port=vv391 offset = slave bundle=gmem7
  #pragma HLS INTERFACE m_axi port=vv392 offset = slave bundle=gmem8
  #pragma HLS INTERFACE m_axi port=vv393 offset = slave bundle=gmem9
  #pragma HLS INTERFACE m_axi port=vv394 offset = slave bundle=gmem10
  #pragma HLS INTERFACE m_axi port=vv395 offset = slave bundle=gmem11

  int8_t v384[1][3][224][224];
  int8_t v385[1000];
  int8_t v386[4096];
  int8_t v387[4096][256][5][5];
  int8_t v388[256][384][3][3];
  int8_t v389[384][384][3][3];
  int8_t v390[384][256][3][3];
  int8_t v391[256][96][5][5];
  int8_t v392[96][3][7][7];
  int8_t v393[4096][4096];
  int8_t v394[4096][1000];
  int8_t v395[1][1000];

  #pragma HLS interface bram port=v384
  #pragma HLS bind_storage variable=v384 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v385
  #pragma HLS bind_storage variable=v385 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v386
  #pragma HLS bind_storage variable=v386 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v387
  #pragma HLS array_partition variable=v387 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v387 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v387 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v387 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v388
  #pragma HLS array_partition variable=v388 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v388 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v388 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v388 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v389
  #pragma HLS array_partition variable=v389 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v389 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v389 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v389 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v390
  #pragma HLS array_partition variable=v390 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v390 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v390 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v390 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v391
  #pragma HLS array_partition variable=v391 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v391 cyclic factor=5 dim=3
  #pragma HLS array_partition variable=v391 cyclic factor=5 dim=4
  #pragma HLS bind_storage variable=v391 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v392
  #pragma HLS array_partition variable=v392 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v392 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v392 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v392 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v392 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v393
  #pragma HLS bind_storage variable=v393 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v394
  #pragma HLS bind_storage variable=v394 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v395
  #pragma HLS bind_storage variable=v395 type=ram_t2p impl=bram
load_array(
        v384,vv384,
        v385,vv385,
        v386,vv386,
        v387,vv387,
        v388,vv388,
        v389,vv389,
        v390,vv390,
        v391,vv391,
        v392,vv392,
        v393,vv393,
        v394,vv394,
        v395,vv395
    );
// func(
//   v384,
//   v385,
//   v386,
//   v387,
//   v388,
//   v389,
//   v390,
//   v391,
//   v392,
//   v393,
//   v394,
//   v395
// );

}

