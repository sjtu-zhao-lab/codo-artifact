
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
  int8_t v8[1][2048],
  int8_t v9[2048][1000],
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
      for (int v16 = 0; v16 < 2048; v16 += 1) {	// L31
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
  int8_t v22[1][2048],
  int8_t v23[2048],
  int8_t v24[1][2048]
) {	// L43
  #pragma HLS dataflow

  for (int v25 = 0; v25 < 1; v25 += 1) {	// L45
    for (int v26 = 0; v26 < 2048; v26 += 1) {	// L46
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
  int8_t v32[1][2048][1][1],
  int8_t v33[2048][2048],
  int8_t v34[1][2048]
) {	// L57
  #pragma HLS dataflow

  int8_t v35[1][2048];	// L59
  #pragma HLS bind_storage variable=v35 type=ram_t2p impl=bram

  for (int v36 = 0; v36 < 1; v36 += 1) {	// L60
    for (int v37 = 0; v37 < 2048; v37 += 1) {	// L61
      v35[v36][v37] = (int8_t)0.000000;	// L62
    }
  }
  for (int v38 = 0; v38 < 1; v38 += 1) {	// L65
    for (int v39 = 0; v39 < 2048; v39 += 1) {	// L66
      for (int v40 = 0; v40 < 2048; v40 += 1) {	// L67
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
  int8_t v46[1][512][7][7],
  int8_t v47[2048][512][7][7],
  int8_t v48[1][2048][1][1]
) {	// L79
  #pragma HLS dataflow

  int8_t v49[1][2048][1][1];	// L81
  #pragma HLS stream variable=v49 depth=10 type=fifo

  #pragma HLS bind_storage variable=v49 type=ram_t2p impl=bram

  int8_t v50[1][512][7][7];	// L82
  #pragma HLS array_partition variable=v50 cyclic factor=7 dim=3
  #pragma HLS bind_storage variable=v50 type=ram_2p impl=bram

  int8_t v51[1][512][7][7];	// L83
  #pragma HLS array_partition variable=v51 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v51 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v51 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v51 type=ram_2p impl=lutram

  for (int v52 = 0; v52 < 1; v52 += 1) {	// L84
    for (int v53 = 0; v53 < 7; v53 += 1) {	// L85
      for (int v54 = 0; v54 < 7; v54 += 1) {	// L86
        for (int v55 = 0; v55 < 512; v55 += 1) {	// L87
          int8_t v56 = v50[v52][v55][1][v54];	// L88
          v50[v52][v55][0][v54] = v56;	// L89
          int8_t v57 = v50[v52][v55][2][v54];	// L90
          v50[v52][v55][1][v54] = v57;	// L91
          int8_t v58 = v50[v52][v55][3][v54];	// L92
          v50[v52][v55][2][v54] = v58;	// L93
          int8_t v59 = v50[v52][v55][4][v54];	// L94
          v50[v52][v55][3][v54] = v59;	// L95
          int8_t v60 = v50[v52][v55][5][v54];	// L96
          v50[v52][v55][4][v54] = v60;	// L97
          int8_t v61 = v50[v52][v55][6][v54];	// L98
          v50[v52][v55][5][v54] = v61;	// L99
          int8_t v62 = v46[v52][v55][v53][v54];	// L100
          v50[v52][v55][6][v54] = v62;	// L101
        }
        if ((v53 - 6) >= 0) {	// L103
          for (int v63 = 0; v63 < 512; v63 += 1) {	// L104
            for (int v64 = 0; v64 < 7; v64 += 1) {	// L105
              int8_t v65 = v51[v52][v63][v64][1];	// L106
              v51[v52][v63][v64][0] = v65;	// L107
              int8_t v66 = v51[v52][v63][v64][2];	// L108
              v51[v52][v63][v64][1] = v66;	// L109
              int8_t v67 = v51[v52][v63][v64][3];	// L110
              v51[v52][v63][v64][2] = v67;	// L111
              int8_t v68 = v51[v52][v63][v64][4];	// L112
              v51[v52][v63][v64][3] = v68;	// L113
              int8_t v69 = v51[v52][v63][v64][5];	// L114
              v51[v52][v63][v64][4] = v69;	// L115
              int8_t v70 = v51[v52][v63][v64][6];	// L116
              v51[v52][v63][v64][5] = v70;	// L117
              int8_t v71 = v50[v52][v63][v64][v54];	// L118
              v51[v52][v63][v64][6] = v71;	// L119
            }
          }
          if ((v54 - 6) >= 0) {	// L122
            int8_t v72[2048];	// L123
            #pragma HLS bind_storage variable=v72 type=ram_2p impl=bram

            for (int v73 = 0; v73 < 2048; v73 += 1) {	// L124
              v72[v73] = (int8_t)0.000000;	// L125
              for (int v74 = 0; v74 < 64; v74 += 1) {	// L126
                #pragma HLS pipeline II=1
                for (int v75 = 0; v75 < 8; v75 += 1) {	// L127
                  for (int v76 = 0; v76 < 7; v76 += 1) {	// L128
                    for (int v77 = 0; v77 < 7; v77 += 1) {	// L129
                      int8_t v78 = v51[v52][(v75 + (v74 * 8))][v76][v77];	// L130
                      int8_t v79 = v47[v73][(v75 + (v74 * 8))][v76][v77];	// L131
                      int8_t v80 = v78 * v79;	// L132
                      int8_t v81 = v72[v73];	// L133
                      int8_t v82 = v81 + v80;	// L134
                      v72[v73] = v82;	// L135
                    }
                  }
                }
              }
              int8_t v83 = v72[v73];	// L140
              v49[v52][v73][(v53 - 6)][(v54 - 6)] = v83;	// L141
            }
          }
        }
      }
    }
  }
  for (int v84 = 0; v84 < 1; v84 += 1) {	// L148
    for (int v85 = 0; v85 < 1; v85 += 1) {	// L149
      for (int v86 = 0; v86 < 1; v86 += 1) {	// L150
        for (int v87 = 0; v87 < 2048; v87 += 1) {	// L151
          int8_t v88 = v49[0][v87][0][0];	// L152
          bool v89 = v88 > (int8_t)0.000000;	// L153
          int8_t v90 = v89 ? v88 : (int8_t)0.000000;	// L154
          v48[v84][v87][v85][v86] = v90;	// L155
        }
      }
    }
  }
  return ;	// L160
}

void main_graph_node5(
  int8_t v91[1][512][14][14],
  int8_t v92[1][512][7][7]
) {	// L162
  #pragma HLS dataflow

  int8_t v93;	// L165
  v93 = (int8_t)-INFINITY;	// L166
  int8_t v94[1][512][14][14];	// L167
  #pragma HLS bind_storage variable=v94 type=ram_2p impl=bram

  for (int v95 = 0; v95 < 1; v95 += 1) {	// L168
    for (int v96 = 0; v96 < 14; v96 += 1) {	// L169
      for (int v97 = 0; v97 < 14; v97 += 1) {	// L170
        for (int v98 = 0; v98 < 512; v98 += 1) {	// L171
          int8_t v99 = v91[v95][v98][v96][v97];	// L172
          v94[v95][v98][v96][v97] = v99;	// L173
        }
      }
    }
  }
  for (int v100 = 0; v100 < 1; v100 += 1) {	// L178
    for (int v101 = 0; v101 < 7; v101 += 1) {	// L179
      for (int v102 = 0; v102 < 7; v102 += 1) {	// L180
        for (int v103 = 0; v103 < 512; v103 += 1) {	// L181
          int8_t v104;	// L182
          v104 = (int8_t)0.000000;	// L183
          for (int v105 = 0; v105 < 2; v105 += 1) {	// L184
            for (int v106 = 0; v106 < 2; v106 += 1) {	// L185
              int8_t v107 = v94[v100][v103][((v101 * 2) + v105)][((v102 * 2) + v106)];	// L186
              int8_t v108 = v93;	// L187
              int8_t v109 = max(v108, v107);	// L188
              v104 = v109;	// L189
            }
          }
          int8_t v110 = v104;	// L192
          v92[v100][v103][v101][v102] = v110;	// L193
        }
      }
    }
  }
  return ;	// L198
}

void main_graph_node6(
  int8_t v111[512][512][3][3],
  int8_t v112[1][512][14][14],
  int8_t v113[1][512][14][14]
) {	// L200
  #pragma HLS dataflow

  int8_t v114[1][512][16][16];	// L202
  #pragma HLS stream variable=v114 depth=10 type=fifo

  #pragma HLS bind_storage variable=v114 type=ram_t2p impl=bram

  for (int v115 = 0; v115 < 1; v115 += 1) {	// L203
    for (int v116 = 0; v116 < 16; v116 += 1) {	// L204
      for (int v117 = 0; v117 < 16; v117 += 1) {	// L205
        for (int v118 = 0; v118 < 512; v118 += 1) {	// L206
          int8_t v119;	// L207
          v119 = (int8_t)0.000000;	// L208
          if (((-v116) + 13) >= 0 && ((-v117) + 13) >= 0) {	// L209
            int8_t v120 = v112[v115][v118][v116][v117];	// L210
            v119 = v120;	// L211
          }
          int8_t v121 = v119;	// L213
          v114[v115][v118][v116][v117] = v121;	// L214
        }
      }
    }
  }
  int8_t v122[1][512][14][14];	// L219
  #pragma HLS stream variable=v122 depth=10 type=fifo

  #pragma HLS bind_storage variable=v122 type=ram_t2p impl=bram

  int8_t v123[1][512][3][16];	// L220
  #pragma HLS array_partition variable=v123 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v123 type=ram_2p impl=bram

  int8_t v124[1][512][3][3];	// L221
  #pragma HLS array_partition variable=v124 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v124 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v124 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v124 type=ram_2p impl=lutram

  for (int v125 = 0; v125 < 1; v125 += 1) {	// L222
    for (int v126 = 0; v126 < 16; v126 += 1) {	// L223
      for (int v127 = 0; v127 < 16; v127 += 1) {	// L224
        for (int v128 = 0; v128 < 512; v128 += 1) {	// L225
          int8_t v129 = v123[v125][v128][1][v127];	// L226
          v123[v125][v128][0][v127] = v129;	// L227
          int8_t v130 = v123[v125][v128][2][v127];	// L228
          v123[v125][v128][1][v127] = v130;	// L229
          int8_t v131 = v114[v125][v128][v126][v127];	// L230
          v123[v125][v128][2][v127] = v131;	// L231
        }
        if ((v126 - 2) >= 0) {	// L233
          for (int v132 = 0; v132 < 512; v132 += 1) {	// L234
            for (int v133 = 0; v133 < 3; v133 += 1) {	// L235
              int8_t v134 = v124[v125][v132][v133][1];	// L236
              v124[v125][v132][v133][0] = v134;	// L237
              int8_t v135 = v124[v125][v132][v133][2];	// L238
              v124[v125][v132][v133][1] = v135;	// L239
              int8_t v136 = v123[v125][v132][v133][v127];	// L240
              v124[v125][v132][v133][2] = v136;	// L241
            }
          }
          if ((v127 - 2) >= 0) {	// L244
            int8_t v137[512];	// L245
            #pragma HLS bind_storage variable=v137 type=ram_2p impl=bram

            for (int v138 = 0; v138 < 512; v138 += 1) {	// L246
              v137[v138] = (int8_t)0.000000;	// L247
              for (int v139 = 0; v139 < 32; v139 += 1) {	// L248
                #pragma HLS pipeline II=1
                for (int v140 = 0; v140 < 16; v140 += 1) {	// L249
                  for (int v141 = 0; v141 < 3; v141 += 1) {	// L250
                    for (int v142 = 0; v142 < 3; v142 += 1) {	// L251
                      int8_t v143 = v124[v125][(v140 + (v139 * 16))][v141][v142];	// L252
                      int8_t v144 = v111[v138][(v140 + (v139 * 16))][v141][v142];	// L253
                      int8_t v145 = v143 * v144;	// L254
                      int8_t v146 = v137[v138];	// L255
                      int8_t v147 = v146 + v145;	// L256
                      v137[v138] = v147;	// L257
                    }
                  }
                }
              }
              int8_t v148 = v137[v138];	// L262
              v122[v125][v138][(v126 - 2)][(v127 - 2)] = v148;	// L263
            }
          }
        }
      }
    }
  }
  for (int v149 = 0; v149 < 1; v149 += 1) {	// L270
    for (int v150 = 0; v150 < 14; v150 += 1) {	// L271
      for (int v151 = 0; v151 < 14; v151 += 1) {	// L272
        for (int v152 = 0; v152 < 512; v152 += 1) {	// L273
          int8_t v153 = v122[0][v152][v150][v151];	// L274
          bool v154 = v153 > (int8_t)0.000000;	// L275
          int8_t v155 = v154 ? v153 : (int8_t)0.000000;	// L276
          v113[v149][v152][v150][v151] = v155;	// L277
        }
      }
    }
  }
  return ;	// L282
}

void main_graph_node7(
  int8_t v156[1][512][14][14],
  int8_t v157[512][512][3][3],
  int8_t v158[1][512][14][14]
) {	// L284
  #pragma HLS dataflow

  int8_t v159[1][512][16][16];	// L286
  #pragma HLS stream variable=v159 depth=10 type=fifo

  #pragma HLS bind_storage variable=v159 type=ram_t2p impl=bram

  for (int v160 = 0; v160 < 1; v160 += 1) {	// L287
    for (int v161 = 0; v161 < 16; v161 += 1) {	// L288
      for (int v162 = 0; v162 < 16; v162 += 1) {	// L289
        for (int v163 = 0; v163 < 512; v163 += 1) {	// L290
          int8_t v164;	// L291
          v164 = (int8_t)0.000000;	// L292
          if (((-v161) + 13) >= 0 && ((-v162) + 13) >= 0) {	// L293
            int8_t v165 = v156[v160][v163][v161][v162];	// L294
            v164 = v165;	// L295
          }
          int8_t v166 = v164;	// L297
          v159[v160][v163][v161][v162] = v166;	// L298
        }
      }
    }
  }
  int8_t v167[1][512][14][14];	// L303
  #pragma HLS stream variable=v167 depth=10 type=fifo

  #pragma HLS bind_storage variable=v167 type=ram_t2p impl=bram

  int8_t v168[1][512][3][16];	// L304
  #pragma HLS array_partition variable=v168 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v168 type=ram_2p impl=bram

  int8_t v169[1][512][3][3];	// L305
  #pragma HLS array_partition variable=v169 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v169 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v169 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v169 type=ram_2p impl=lutram

  for (int v170 = 0; v170 < 1; v170 += 1) {	// L306
    for (int v171 = 0; v171 < 16; v171 += 1) {	// L307
      for (int v172 = 0; v172 < 16; v172 += 1) {	// L308
        for (int v173 = 0; v173 < 512; v173 += 1) {	// L309
          int8_t v174 = v168[v170][v173][1][v172];	// L310
          v168[v170][v173][0][v172] = v174;	// L311
          int8_t v175 = v168[v170][v173][2][v172];	// L312
          v168[v170][v173][1][v172] = v175;	// L313
          int8_t v176 = v159[v170][v173][v171][v172];	// L314
          v168[v170][v173][2][v172] = v176;	// L315
        }
        if ((v171 - 2) >= 0) {	// L317
          for (int v177 = 0; v177 < 512; v177 += 1) {	// L318
            for (int v178 = 0; v178 < 3; v178 += 1) {	// L319
              int8_t v179 = v169[v170][v177][v178][1];	// L320
              v169[v170][v177][v178][0] = v179;	// L321
              int8_t v180 = v169[v170][v177][v178][2];	// L322
              v169[v170][v177][v178][1] = v180;	// L323
              int8_t v181 = v168[v170][v177][v178][v172];	// L324
              v169[v170][v177][v178][2] = v181;	// L325
            }
          }
          if ((v172 - 2) >= 0) {	// L328
            int8_t v182[512];	// L329
            #pragma HLS bind_storage variable=v182 type=ram_2p impl=bram

            for (int v183 = 0; v183 < 512; v183 += 1) {	// L330
              v182[v183] = (int8_t)0.000000;	// L331
              for (int v184 = 0; v184 < 32; v184 += 1) {	// L332
                #pragma HLS pipeline II=1
                for (int v185 = 0; v185 < 16; v185 += 1) {	// L333
                  for (int v186 = 0; v186 < 3; v186 += 1) {	// L334
                    for (int v187 = 0; v187 < 3; v187 += 1) {	// L335
                      int8_t v188 = v169[v170][(v185 + (v184 * 16))][v186][v187];	// L336
                      int8_t v189 = v157[v183][(v185 + (v184 * 16))][v186][v187];	// L337
                      int8_t v190 = v188 * v189;	// L338
                      int8_t v191 = v182[v183];	// L339
                      int8_t v192 = v191 + v190;	// L340
                      v182[v183] = v192;	// L341
                    }
                  }
                }
              }
              int8_t v193 = v182[v183];	// L346
              v167[v170][v183][(v171 - 2)][(v172 - 2)] = v193;	// L347
            }
          }
        }
      }
    }
  }
  for (int v194 = 0; v194 < 1; v194 += 1) {	// L354
    for (int v195 = 0; v195 < 14; v195 += 1) {	// L355
      for (int v196 = 0; v196 < 14; v196 += 1) {	// L356
        for (int v197 = 0; v197 < 512; v197 += 1) {	// L357
          int8_t v198 = v167[0][v197][v195][v196];	// L358
          bool v199 = v198 > (int8_t)0.000000;	// L359
          int8_t v200 = v199 ? v198 : (int8_t)0.000000;	// L360
          v158[v194][v197][v195][v196] = v200;	// L361
        }
      }
    }
  }
  return ;	// L366
}

void main_graph_node8(
  int8_t v201[1][256][14][14],
  int8_t v202[512][256][3][3],
  int8_t v203[1][512][14][14]
) {	// L368
  #pragma HLS dataflow

  int8_t v204[1][256][16][16];	// L370
  #pragma HLS stream variable=v204 depth=10 type=fifo

  #pragma HLS bind_storage variable=v204 type=ram_t2p impl=bram

  for (int v205 = 0; v205 < 1; v205 += 1) {	// L371
    for (int v206 = 0; v206 < 16; v206 += 1) {	// L372
      for (int v207 = 0; v207 < 16; v207 += 1) {	// L373
        for (int v208 = 0; v208 < 256; v208 += 1) {	// L374
          int8_t v209;	// L375
          v209 = (int8_t)0.000000;	// L376
          if (((-v206) + 13) >= 0 && ((-v207) + 13) >= 0) {	// L377
            int8_t v210 = v201[v205][v208][v206][v207];	// L378
            v209 = v210;	// L379
          }
          int8_t v211 = v209;	// L381
          v204[v205][v208][v206][v207] = v211;	// L382
        }
      }
    }
  }
  int8_t v212[1][512][14][14];	// L387
  #pragma HLS stream variable=v212 depth=10 type=fifo

  #pragma HLS bind_storage variable=v212 type=ram_t2p impl=bram

  int8_t v213[1][256][3][16];	// L388
  #pragma HLS array_partition variable=v213 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v213 type=ram_2p impl=bram

  int8_t v214[1][256][3][3];	// L389
  #pragma HLS array_partition variable=v214 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v214 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v214 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v214 type=ram_2p impl=lutram

  for (int v215 = 0; v215 < 1; v215 += 1) {	// L390
    for (int v216 = 0; v216 < 16; v216 += 1) {	// L391
      for (int v217 = 0; v217 < 16; v217 += 1) {	// L392
        for (int v218 = 0; v218 < 256; v218 += 1) {	// L393
          int8_t v219 = v213[v215][v218][1][v217];	// L394
          v213[v215][v218][0][v217] = v219;	// L395
          int8_t v220 = v213[v215][v218][2][v217];	// L396
          v213[v215][v218][1][v217] = v220;	// L397
          int8_t v221 = v204[v215][v218][v216][v217];	// L398
          v213[v215][v218][2][v217] = v221;	// L399
        }
        if ((v216 - 2) >= 0) {	// L401
          for (int v222 = 0; v222 < 256; v222 += 1) {	// L402
            for (int v223 = 0; v223 < 3; v223 += 1) {	// L403
              int8_t v224 = v214[v215][v222][v223][1];	// L404
              v214[v215][v222][v223][0] = v224;	// L405
              int8_t v225 = v214[v215][v222][v223][2];	// L406
              v214[v215][v222][v223][1] = v225;	// L407
              int8_t v226 = v213[v215][v222][v223][v217];	// L408
              v214[v215][v222][v223][2] = v226;	// L409
            }
          }
          if ((v217 - 2) >= 0) {	// L412
            int8_t v227[512];	// L413
            #pragma HLS bind_storage variable=v227 type=ram_2p impl=bram

            for (int v228 = 0; v228 < 512; v228 += 1) {	// L414
              v227[v228] = (int8_t)0.000000;	// L415
              for (int v229 = 0; v229 < 32; v229 += 1) {	// L416
                #pragma HLS pipeline II=1
                for (int v230 = 0; v230 < 8; v230 += 1) {	// L417
                  for (int v231 = 0; v231 < 3; v231 += 1) {	// L418
                    for (int v232 = 0; v232 < 3; v232 += 1) {	// L419
                      int8_t v233 = v214[v215][(v230 + (v229 * 8))][v231][v232];	// L420
                      int8_t v234 = v202[v228][(v230 + (v229 * 8))][v231][v232];	// L421
                      int8_t v235 = v233 * v234;	// L422
                      int8_t v236 = v227[v228];	// L423
                      int8_t v237 = v236 + v235;	// L424
                      v227[v228] = v237;	// L425
                    }
                  }
                }
              }
              int8_t v238 = v227[v228];	// L430
              v212[v215][v228][(v216 - 2)][(v217 - 2)] = v238;	// L431
            }
          }
        }
      }
    }
  }
  for (int v239 = 0; v239 < 1; v239 += 1) {	// L438
    for (int v240 = 0; v240 < 14; v240 += 1) {	// L439
      for (int v241 = 0; v241 < 14; v241 += 1) {	// L440
        for (int v242 = 0; v242 < 512; v242 += 1) {	// L441
          int8_t v243 = v212[0][v242][v240][v241];	// L442
          bool v244 = v243 > (int8_t)0.000000;	// L443
          int8_t v245 = v244 ? v243 : (int8_t)0.000000;	// L444
          v203[v239][v242][v240][v241] = v245;	// L445
        }
      }
    }
  }
  return ;	// L450
}

void main_graph_node9(
  int8_t v246[1][256][28][28],
  int8_t v247[1][256][14][14]
) {	// L452
  #pragma HLS dataflow

  int8_t v248;	// L455
  v248 = (int8_t)-INFINITY;	// L456
  int8_t v249[1][256][28][28];	// L457
  #pragma HLS bind_storage variable=v249 type=ram_2p impl=bram

  for (int v250 = 0; v250 < 1; v250 += 1) {	// L458
    for (int v251 = 0; v251 < 28; v251 += 1) {	// L459
      for (int v252 = 0; v252 < 28; v252 += 1) {	// L460
        for (int v253 = 0; v253 < 256; v253 += 1) {	// L461
          int8_t v254 = v246[v250][v253][v251][v252];	// L462
          v249[v250][v253][v251][v252] = v254;	// L463
        }
      }
    }
  }
  for (int v255 = 0; v255 < 1; v255 += 1) {	// L468
    for (int v256 = 0; v256 < 14; v256 += 1) {	// L469
      for (int v257 = 0; v257 < 14; v257 += 1) {	// L470
        for (int v258 = 0; v258 < 256; v258 += 1) {	// L471
          int8_t v259;	// L472
          v259 = (int8_t)0.000000;	// L473
          for (int v260 = 0; v260 < 2; v260 += 1) {	// L474
            for (int v261 = 0; v261 < 2; v261 += 1) {	// L475
              int8_t v262 = v249[v255][v258][((v256 * 2) + v260)][((v257 * 2) + v261)];	// L476
              int8_t v263 = v248;	// L477
              int8_t v264 = max(v263, v262);	// L478
              v259 = v264;	// L479
            }
          }
          int8_t v265 = v259;	// L482
          v247[v255][v258][v256][v257] = v265;	// L483
        }
      }
    }
  }
  return ;	// L488
}

void main_graph_node10(
  int8_t v266[1][256][28][28],
  int8_t v267[256][256][3][3],
  int8_t v268[1][256][28][28]
) {	// L490
  #pragma HLS dataflow

  int8_t v269[1][256][30][30];	// L492
  #pragma HLS stream variable=v269 depth=10 type=fifo

  #pragma HLS bind_storage variable=v269 type=ram_t2p impl=bram

  for (int v270 = 0; v270 < 1; v270 += 1) {	// L493
    for (int v271 = 0; v271 < 30; v271 += 1) {	// L494
      for (int v272 = 0; v272 < 30; v272 += 1) {	// L495
        for (int v273 = 0; v273 < 256; v273 += 1) {	// L496
          int8_t v274;	// L497
          v274 = (int8_t)0.000000;	// L498
          if (((-v271) + 27) >= 0 && ((-v272) + 27) >= 0) {	// L499
            int8_t v275 = v266[v270][v273][v271][v272];	// L500
            v274 = v275;	// L501
          }
          int8_t v276 = v274;	// L503
          v269[v270][v273][v271][v272] = v276;	// L504
        }
      }
    }
  }
  int8_t v277[1][256][28][28];	// L509
  #pragma HLS stream variable=v277 depth=10 type=fifo

  #pragma HLS bind_storage variable=v277 type=ram_t2p impl=bram

  int8_t v278[1][256][3][30];	// L510
  #pragma HLS array_partition variable=v278 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v278 type=ram_2p impl=bram

  int8_t v279[1][256][3][3];	// L511
  #pragma HLS array_partition variable=v279 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v279 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v279 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v279 type=ram_2p impl=lutram

  for (int v280 = 0; v280 < 1; v280 += 1) {	// L512
    for (int v281 = 0; v281 < 30; v281 += 1) {	// L513
      for (int v282 = 0; v282 < 30; v282 += 1) {	// L514
        for (int v283 = 0; v283 < 256; v283 += 1) {	// L515
          int8_t v284 = v278[v280][v283][1][v282];	// L516
          v278[v280][v283][0][v282] = v284;	// L517
          int8_t v285 = v278[v280][v283][2][v282];	// L518
          v278[v280][v283][1][v282] = v285;	// L519
          int8_t v286 = v269[v280][v283][v281][v282];	// L520
          v278[v280][v283][2][v282] = v286;	// L521
        }
        if ((v281 - 2) >= 0) {	// L523
          for (int v287 = 0; v287 < 256; v287 += 1) {	// L524
            for (int v288 = 0; v288 < 3; v288 += 1) {	// L525
              int8_t v289 = v279[v280][v287][v288][1];	// L526
              v279[v280][v287][v288][0] = v289;	// L527
              int8_t v290 = v279[v280][v287][v288][2];	// L528
              v279[v280][v287][v288][1] = v290;	// L529
              int8_t v291 = v278[v280][v287][v288][v282];	// L530
              v279[v280][v287][v288][2] = v291;	// L531
            }
          }
          if ((v282 - 2) >= 0) {	// L534
            int8_t v292[256];	// L535
            #pragma HLS bind_storage variable=v292 type=ram_2p impl=bram

            for (int v293 = 0; v293 < 256; v293 += 1) {	// L536
              v292[v293] = (int8_t)0.000000;	// L537
              for (int v294 = 0; v294 < 32; v294 += 1) {	// L538
                #pragma HLS pipeline II=1
                for (int v295 = 0; v295 < 8; v295 += 1) {	// L539
                  for (int v296 = 0; v296 < 3; v296 += 1) {	// L540
                    for (int v297 = 0; v297 < 3; v297 += 1) {	// L541
                      int8_t v298 = v279[v280][(v295 + (v294 * 8))][v296][v297];	// L542
                      int8_t v299 = v267[v293][(v295 + (v294 * 8))][v296][v297];	// L543
                      int8_t v300 = v298 * v299;	// L544
                      int8_t v301 = v292[v293];	// L545
                      int8_t v302 = v301 + v300;	// L546
                      v292[v293] = v302;	// L547
                    }
                  }
                }
              }
              int8_t v303 = v292[v293];	// L552
              v277[v280][v293][(v281 - 2)][(v282 - 2)] = v303;	// L553
            }
          }
        }
      }
    }
  }
  for (int v304 = 0; v304 < 1; v304 += 1) {	// L560
    for (int v305 = 0; v305 < 28; v305 += 1) {	// L561
      for (int v306 = 0; v306 < 28; v306 += 1) {	// L562
        for (int v307 = 0; v307 < 256; v307 += 1) {	// L563
          int8_t v308 = v277[0][v307][v305][v306];	// L564
          bool v309 = v308 > (int8_t)0.000000;	// L565
          int8_t v310 = v309 ? v308 : (int8_t)0.000000;	// L566
          v268[v304][v307][v305][v306] = v310;	// L567
        }
      }
    }
  }
  return ;	// L572
}

void main_graph_node11(
  int8_t v311[1][256][28][28],
  int8_t v312[256][256][3][3],
  int8_t v313[1][256][28][28]
) {	// L574
  #pragma HLS dataflow

  int8_t v314[1][256][30][30];	// L576
  #pragma HLS stream variable=v314 depth=10 type=fifo

  #pragma HLS bind_storage variable=v314 type=ram_t2p impl=bram

  for (int v315 = 0; v315 < 1; v315 += 1) {	// L577
    for (int v316 = 0; v316 < 30; v316 += 1) {	// L578
      for (int v317 = 0; v317 < 30; v317 += 1) {	// L579
        for (int v318 = 0; v318 < 256; v318 += 1) {	// L580
          int8_t v319;	// L581
          v319 = (int8_t)0.000000;	// L582
          if (((-v316) + 27) >= 0 && ((-v317) + 27) >= 0) {	// L583
            int8_t v320 = v311[v315][v318][v316][v317];	// L584
            v319 = v320;	// L585
          }
          int8_t v321 = v319;	// L587
          v314[v315][v318][v316][v317] = v321;	// L588
        }
      }
    }
  }
  int8_t v322[1][256][28][28];	// L593
  #pragma HLS stream variable=v322 depth=10 type=fifo

  #pragma HLS bind_storage variable=v322 type=ram_t2p impl=bram

  int8_t v323[1][256][3][30];	// L594
  #pragma HLS array_partition variable=v323 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v323 type=ram_2p impl=bram

  int8_t v324[1][256][3][3];	// L595
  #pragma HLS array_partition variable=v324 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v324 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v324 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v324 type=ram_2p impl=lutram

  for (int v325 = 0; v325 < 1; v325 += 1) {	// L596
    for (int v326 = 0; v326 < 30; v326 += 1) {	// L597
      for (int v327 = 0; v327 < 30; v327 += 1) {	// L598
        for (int v328 = 0; v328 < 256; v328 += 1) {	// L599
          int8_t v329 = v323[v325][v328][1][v327];	// L600
          v323[v325][v328][0][v327] = v329;	// L601
          int8_t v330 = v323[v325][v328][2][v327];	// L602
          v323[v325][v328][1][v327] = v330;	// L603
          int8_t v331 = v314[v325][v328][v326][v327];	// L604
          v323[v325][v328][2][v327] = v331;	// L605
        }
        if ((v326 - 2) >= 0) {	// L607
          for (int v332 = 0; v332 < 256; v332 += 1) {	// L608
            for (int v333 = 0; v333 < 3; v333 += 1) {	// L609
              int8_t v334 = v324[v325][v332][v333][1];	// L610
              v324[v325][v332][v333][0] = v334;	// L611
              int8_t v335 = v324[v325][v332][v333][2];	// L612
              v324[v325][v332][v333][1] = v335;	// L613
              int8_t v336 = v323[v325][v332][v333][v327];	// L614
              v324[v325][v332][v333][2] = v336;	// L615
            }
          }
          if ((v327 - 2) >= 0) {	// L618
            int8_t v337[256];	// L619
            #pragma HLS bind_storage variable=v337 type=ram_2p impl=bram

            for (int v338 = 0; v338 < 256; v338 += 1) {	// L620
              v337[v338] = (int8_t)0.000000;	// L621
              for (int v339 = 0; v339 < 32; v339 += 1) {	// L622
                #pragma HLS pipeline II=1
                for (int v340 = 0; v340 < 8; v340 += 1) {	// L623
                  for (int v341 = 0; v341 < 3; v341 += 1) {	// L624
                    for (int v342 = 0; v342 < 3; v342 += 1) {	// L625
                      int8_t v343 = v324[v325][(v340 + (v339 * 8))][v341][v342];	// L626
                      int8_t v344 = v312[v338][(v340 + (v339 * 8))][v341][v342];	// L627
                      int8_t v345 = v343 * v344;	// L628
                      int8_t v346 = v337[v338];	// L629
                      int8_t v347 = v346 + v345;	// L630
                      v337[v338] = v347;	// L631
                    }
                  }
                }
              }
              int8_t v348 = v337[v338];	// L636
              v322[v325][v338][(v326 - 2)][(v327 - 2)] = v348;	// L637
            }
          }
        }
      }
    }
  }
  for (int v349 = 0; v349 < 1; v349 += 1) {	// L644
    for (int v350 = 0; v350 < 28; v350 += 1) {	// L645
      for (int v351 = 0; v351 < 28; v351 += 1) {	// L646
        for (int v352 = 0; v352 < 256; v352 += 1) {	// L647
          int8_t v353 = v322[0][v352][v350][v351];	// L648
          bool v354 = v353 > (int8_t)0.000000;	// L649
          int8_t v355 = v354 ? v353 : (int8_t)0.000000;	// L650
          v313[v349][v352][v350][v351] = v355;	// L651
        }
      }
    }
  }
  return ;	// L656
}

void main_graph_node12(
  int8_t v356[1][128][28][28],
  int8_t v357[256][128][3][3],
  int8_t v358[1][256][28][28]
) {	// L658
  #pragma HLS dataflow

  int8_t v359[1][128][30][30];	// L660
  #pragma HLS stream variable=v359 depth=10 type=fifo

  #pragma HLS bind_storage variable=v359 type=ram_t2p impl=bram

  for (int v360 = 0; v360 < 1; v360 += 1) {	// L661
    for (int v361 = 0; v361 < 30; v361 += 1) {	// L662
      for (int v362 = 0; v362 < 30; v362 += 1) {	// L663
        for (int v363 = 0; v363 < 128; v363 += 1) {	// L664
          int8_t v364;	// L665
          v364 = (int8_t)0.000000;	// L666
          if (((-v361) + 27) >= 0 && ((-v362) + 27) >= 0) {	// L667
            int8_t v365 = v356[v360][v363][v361][v362];	// L668
            v364 = v365;	// L669
          }
          int8_t v366 = v364;	// L671
          v359[v360][v363][v361][v362] = v366;	// L672
        }
      }
    }
  }
  int8_t v367[1][256][28][28];	// L677
  #pragma HLS stream variable=v367 depth=10 type=fifo

  #pragma HLS bind_storage variable=v367 type=ram_t2p impl=bram

  int8_t v368[1][128][3][30];	// L678
  #pragma HLS array_partition variable=v368 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v368 type=ram_2p impl=bram

  int8_t v369[1][128][3][3];	// L679
  #pragma HLS array_partition variable=v369 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v369 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v369 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v369 type=ram_2p impl=lutram

  for (int v370 = 0; v370 < 1; v370 += 1) {	// L680
    for (int v371 = 0; v371 < 30; v371 += 1) {	// L681
      for (int v372 = 0; v372 < 30; v372 += 1) {	// L682
        for (int v373 = 0; v373 < 128; v373 += 1) {	// L683
          int8_t v374 = v368[v370][v373][1][v372];	// L684
          v368[v370][v373][0][v372] = v374;	// L685
          int8_t v375 = v368[v370][v373][2][v372];	// L686
          v368[v370][v373][1][v372] = v375;	// L687
          int8_t v376 = v359[v370][v373][v371][v372];	// L688
          v368[v370][v373][2][v372] = v376;	// L689
        }
        if ((v371 - 2) >= 0) {	// L691
          for (int v377 = 0; v377 < 128; v377 += 1) {	// L692
            for (int v378 = 0; v378 < 3; v378 += 1) {	// L693
              int8_t v379 = v369[v370][v377][v378][1];	// L694
              v369[v370][v377][v378][0] = v379;	// L695
              int8_t v380 = v369[v370][v377][v378][2];	// L696
              v369[v370][v377][v378][1] = v380;	// L697
              int8_t v381 = v368[v370][v377][v378][v372];	// L698
              v369[v370][v377][v378][2] = v381;	// L699
            }
          }
          if ((v372 - 2) >= 0) {	// L702
            int8_t v382[256];	// L703
            #pragma HLS bind_storage variable=v382 type=ram_2p impl=bram

            for (int v383 = 0; v383 < 256; v383 += 1) {	// L704
              v382[v383] = (int8_t)0.000000;	// L705
              for (int v384 = 0; v384 < 32; v384 += 1) {	// L706
                #pragma HLS pipeline II=1
                for (int v385 = 0; v385 < 4; v385 += 1) {	// L707
                  for (int v386 = 0; v386 < 3; v386 += 1) {	// L708
                    for (int v387 = 0; v387 < 3; v387 += 1) {	// L709
                      int8_t v388 = v369[v370][(v385 + (v384 * 4))][v386][v387];	// L710
                      int8_t v389 = v357[v383][(v385 + (v384 * 4))][v386][v387];	// L711
                      int8_t v390 = v388 * v389;	// L712
                      int8_t v391 = v382[v383];	// L713
                      int8_t v392 = v391 + v390;	// L714
                      v382[v383] = v392;	// L715
                    }
                  }
                }
              }
              int8_t v393 = v382[v383];	// L720
              v367[v370][v383][(v371 - 2)][(v372 - 2)] = v393;	// L721
            }
          }
        }
      }
    }
  }
  for (int v394 = 0; v394 < 1; v394 += 1) {	// L728
    for (int v395 = 0; v395 < 28; v395 += 1) {	// L729
      for (int v396 = 0; v396 < 28; v396 += 1) {	// L730
        for (int v397 = 0; v397 < 256; v397 += 1) {	// L731
          int8_t v398 = v367[0][v397][v395][v396];	// L732
          bool v399 = v398 > (int8_t)0.000000;	// L733
          int8_t v400 = v399 ? v398 : (int8_t)0.000000;	// L734
          v358[v394][v397][v395][v396] = v400;	// L735
        }
      }
    }
  }
  return ;	// L740
}

void main_graph_node13(
  int8_t v401[1][128][56][56],
  int8_t v402[1][128][28][28]
) {	// L742
  #pragma HLS dataflow

  int8_t v403;	// L745
  v403 = (int8_t)-INFINITY;	// L746
  int8_t v404[1][128][56][56];	// L747
  #pragma HLS bind_storage variable=v404 type=ram_2p impl=bram

  for (int v405 = 0; v405 < 1; v405 += 1) {	// L748
    for (int v406 = 0; v406 < 56; v406 += 1) {	// L749
      for (int v407 = 0; v407 < 56; v407 += 1) {	// L750
        for (int v408 = 0; v408 < 128; v408 += 1) {	// L751
          int8_t v409 = v401[v405][v408][v406][v407];	// L752
          v404[v405][v408][v406][v407] = v409;	// L753
        }
      }
    }
  }
  for (int v410 = 0; v410 < 1; v410 += 1) {	// L758
    for (int v411 = 0; v411 < 28; v411 += 1) {	// L759
      for (int v412 = 0; v412 < 28; v412 += 1) {	// L760
        for (int v413 = 0; v413 < 128; v413 += 1) {	// L761
          int8_t v414;	// L762
          v414 = (int8_t)0.000000;	// L763
          for (int v415 = 0; v415 < 2; v415 += 1) {	// L764
            for (int v416 = 0; v416 < 2; v416 += 1) {	// L765
              int8_t v417 = v404[v410][v413][((v411 * 2) + v415)][((v412 * 2) + v416)];	// L766
              int8_t v418 = v403;	// L767
              int8_t v419 = max(v418, v417);	// L768
              v414 = v419;	// L769
            }
          }
          int8_t v420 = v414;	// L772
          v402[v410][v413][v411][v412] = v420;	// L773
        }
      }
    }
  }
  return ;	// L778
}

void main_graph_node14(
  int8_t v421[1][128][56][56],
  int8_t v422[128][128][3][3],
  int8_t v423[1][128][56][56]
) {	// L780
  #pragma HLS dataflow

  int8_t v424[1][128][58][58];	// L782
  #pragma HLS stream variable=v424 depth=10 type=fifo

  #pragma HLS bind_storage variable=v424 type=ram_t2p impl=bram

  for (int v425 = 0; v425 < 1; v425 += 1) {	// L783
    for (int v426 = 0; v426 < 58; v426 += 1) {	// L784
      for (int v427 = 0; v427 < 58; v427 += 1) {	// L785
        for (int v428 = 0; v428 < 128; v428 += 1) {	// L786
          int8_t v429;	// L787
          v429 = (int8_t)0.000000;	// L788
          if (((-v426) + 55) >= 0 && ((-v427) + 55) >= 0) {	// L789
            int8_t v430 = v421[v425][v428][v426][v427];	// L790
            v429 = v430;	// L791
          }
          int8_t v431 = v429;	// L793
          v424[v425][v428][v426][v427] = v431;	// L794
        }
      }
    }
  }
  int8_t v432[1][128][56][56];	// L799
  #pragma HLS stream variable=v432 depth=10 type=fifo

  #pragma HLS bind_storage variable=v432 type=ram_t2p impl=bram

  int8_t v433[1][128][3][58];	// L800
  #pragma HLS array_partition variable=v433 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v433 type=ram_2p impl=bram

  int8_t v434[1][128][3][3];	// L801
  #pragma HLS array_partition variable=v434 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v434 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v434 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v434 type=ram_2p impl=lutram

  for (int v435 = 0; v435 < 1; v435 += 1) {	// L802
    for (int v436 = 0; v436 < 58; v436 += 1) {	// L803
      for (int v437 = 0; v437 < 58; v437 += 1) {	// L804
        for (int v438 = 0; v438 < 128; v438 += 1) {	// L805
          int8_t v439 = v433[v435][v438][1][v437];	// L806
          v433[v435][v438][0][v437] = v439;	// L807
          int8_t v440 = v433[v435][v438][2][v437];	// L808
          v433[v435][v438][1][v437] = v440;	// L809
          int8_t v441 = v424[v435][v438][v436][v437];	// L810
          v433[v435][v438][2][v437] = v441;	// L811
        }
        if ((v436 - 2) >= 0) {	// L813
          for (int v442 = 0; v442 < 128; v442 += 1) {	// L814
            for (int v443 = 0; v443 < 3; v443 += 1) {	// L815
              int8_t v444 = v434[v435][v442][v443][1];	// L816
              v434[v435][v442][v443][0] = v444;	// L817
              int8_t v445 = v434[v435][v442][v443][2];	// L818
              v434[v435][v442][v443][1] = v445;	// L819
              int8_t v446 = v433[v435][v442][v443][v437];	// L820
              v434[v435][v442][v443][2] = v446;	// L821
            }
          }
          if ((v437 - 2) >= 0) {	// L824
            int8_t v447[128];	// L825
            #pragma HLS bind_storage variable=v447 type=ram_2p impl=bram

            for (int v448 = 0; v448 < 128; v448 += 1) {	// L826
              v447[v448] = (int8_t)0.000000;	// L827
              for (int v449 = 0; v449 < 8; v449 += 1) {	// L828
                #pragma HLS pipeline II=1
                for (int v450 = 0; v450 < 16; v450 += 1) {	// L829
                  for (int v451 = 0; v451 < 3; v451 += 1) {	// L830
                    for (int v452 = 0; v452 < 3; v452 += 1) {	// L831
                      int8_t v453 = v434[v435][(v450 + (v449 * 16))][v451][v452];	// L832
                      int8_t v454 = v422[v448][(v450 + (v449 * 16))][v451][v452];	// L833
                      int8_t v455 = v453 * v454;	// L834
                      int8_t v456 = v447[v448];	// L835
                      int8_t v457 = v456 + v455;	// L836
                      v447[v448] = v457;	// L837
                    }
                  }
                }
              }
              int8_t v458 = v447[v448];	// L842
              v432[v435][v448][(v436 - 2)][(v437 - 2)] = v458;	// L843
            }
          }
        }
      }
    }
  }
  for (int v459 = 0; v459 < 1; v459 += 1) {	// L850
    for (int v460 = 0; v460 < 56; v460 += 1) {	// L851
      for (int v461 = 0; v461 < 56; v461 += 1) {	// L852
        for (int v462 = 0; v462 < 128; v462 += 1) {	// L853
          int8_t v463 = v432[0][v462][v460][v461];	// L854
          bool v464 = v463 > (int8_t)0.000000;	// L855
          int8_t v465 = v464 ? v463 : (int8_t)0.000000;	// L856
          v423[v459][v462][v460][v461] = v465;	// L857
        }
      }
    }
  }
  return ;	// L862
}

void main_graph_node15(
  int8_t v466[128][128][3][3],
  int8_t v467[1][128][56][56],
  int8_t v468[1][128][56][56]
) {	// L864
  #pragma HLS dataflow

  int8_t v469[1][128][58][58];	// L866
  #pragma HLS stream variable=v469 depth=10 type=fifo

  #pragma HLS bind_storage variable=v469 type=ram_t2p impl=bram

  for (int v470 = 0; v470 < 1; v470 += 1) {	// L867
    for (int v471 = 0; v471 < 58; v471 += 1) {	// L868
      for (int v472 = 0; v472 < 58; v472 += 1) {	// L869
        for (int v473 = 0; v473 < 128; v473 += 1) {	// L870
          int8_t v474;	// L871
          v474 = (int8_t)0.000000;	// L872
          if (((-v471) + 55) >= 0 && ((-v472) + 55) >= 0) {	// L873
            int8_t v475 = v467[v470][v473][v471][v472];	// L874
            v474 = v475;	// L875
          }
          int8_t v476 = v474;	// L877
          v469[v470][v473][v471][v472] = v476;	// L878
        }
      }
    }
  }
  int8_t v477[1][128][56][56];	// L883
  #pragma HLS stream variable=v477 depth=10 type=fifo

  #pragma HLS bind_storage variable=v477 type=ram_t2p impl=bram

  int8_t v478[1][128][3][58];	// L884
  #pragma HLS array_partition variable=v478 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v478 type=ram_2p impl=bram

  int8_t v479[1][128][3][3];	// L885
  #pragma HLS array_partition variable=v479 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v479 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v479 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v479 type=ram_2p impl=lutram

  for (int v480 = 0; v480 < 1; v480 += 1) {	// L886
    for (int v481 = 0; v481 < 58; v481 += 1) {	// L887
      for (int v482 = 0; v482 < 58; v482 += 1) {	// L888
        for (int v483 = 0; v483 < 128; v483 += 1) {	// L889
          int8_t v484 = v478[v480][v483][1][v482];	// L890
          v478[v480][v483][0][v482] = v484;	// L891
          int8_t v485 = v478[v480][v483][2][v482];	// L892
          v478[v480][v483][1][v482] = v485;	// L893
          int8_t v486 = v469[v480][v483][v481][v482];	// L894
          v478[v480][v483][2][v482] = v486;	// L895
        }
        if ((v481 - 2) >= 0) {	// L897
          for (int v487 = 0; v487 < 128; v487 += 1) {	// L898
            for (int v488 = 0; v488 < 3; v488 += 1) {	// L899
              int8_t v489 = v479[v480][v487][v488][1];	// L900
              v479[v480][v487][v488][0] = v489;	// L901
              int8_t v490 = v479[v480][v487][v488][2];	// L902
              v479[v480][v487][v488][1] = v490;	// L903
              int8_t v491 = v478[v480][v487][v488][v482];	// L904
              v479[v480][v487][v488][2] = v491;	// L905
            }
          }
          if ((v482 - 2) >= 0) {	// L908
            int8_t v492[128];	// L909
            #pragma HLS bind_storage variable=v492 type=ram_2p impl=bram

            for (int v493 = 0; v493 < 128; v493 += 1) {	// L910
              v492[v493] = (int8_t)0.000000;	// L911
              for (int v494 = 0; v494 < 8; v494 += 1) {	// L912
                #pragma HLS pipeline II=1
                for (int v495 = 0; v495 < 16; v495 += 1) {	// L913
                  for (int v496 = 0; v496 < 3; v496 += 1) {	// L914
                    for (int v497 = 0; v497 < 3; v497 += 1) {	// L915
                      int8_t v498 = v479[v480][(v495 + (v494 * 16))][v496][v497];	// L916
                      int8_t v499 = v466[v493][(v495 + (v494 * 16))][v496][v497];	// L917
                      int8_t v500 = v498 * v499;	// L918
                      int8_t v501 = v492[v493];	// L919
                      int8_t v502 = v501 + v500;	// L920
                      v492[v493] = v502;	// L921
                    }
                  }
                }
              }
              int8_t v503 = v492[v493];	// L926
              v477[v480][v493][(v481 - 2)][(v482 - 2)] = v503;	// L927
            }
          }
        }
      }
    }
  }
  for (int v504 = 0; v504 < 1; v504 += 1) {	// L934
    for (int v505 = 0; v505 < 56; v505 += 1) {	// L935
      for (int v506 = 0; v506 < 56; v506 += 1) {	// L936
        for (int v507 = 0; v507 < 128; v507 += 1) {	// L937
          int8_t v508 = v477[0][v507][v505][v506];	// L938
          bool v509 = v508 > (int8_t)0.000000;	// L939
          int8_t v510 = v509 ? v508 : (int8_t)0.000000;	// L940
          v468[v504][v507][v505][v506] = v510;	// L941
        }
      }
    }
  }
  return ;	// L946
}

void main_graph_node16(
  int8_t v511[128][64][3][3],
  int8_t v512[1][64][56][56],
  int8_t v513[1][128][56][56]
) {	// L948
  #pragma HLS dataflow

  int8_t v514[1][64][58][58];	// L950
  #pragma HLS stream variable=v514 depth=10 type=fifo

  #pragma HLS bind_storage variable=v514 type=ram_t2p impl=bram

  for (int v515 = 0; v515 < 1; v515 += 1) {	// L951
    for (int v516 = 0; v516 < 58; v516 += 1) {	// L952
      for (int v517 = 0; v517 < 58; v517 += 1) {	// L953
        for (int v518 = 0; v518 < 64; v518 += 1) {	// L954
          int8_t v519;	// L955
          v519 = (int8_t)0.000000;	// L956
          if (((-v516) + 55) >= 0 && ((-v517) + 55) >= 0) {	// L957
            int8_t v520 = v512[v515][v518][v516][v517];	// L958
            v519 = v520;	// L959
          }
          int8_t v521 = v519;	// L961
          v514[v515][v518][v516][v517] = v521;	// L962
        }
      }
    }
  }
  int8_t v522[1][128][56][56];	// L967
  #pragma HLS stream variable=v522 depth=10 type=fifo

  #pragma HLS bind_storage variable=v522 type=ram_t2p impl=bram

  int8_t v523[1][64][3][58];	// L968
  #pragma HLS array_partition variable=v523 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v523 type=ram_2p impl=bram

  int8_t v524[1][64][3][3];	// L969
  #pragma HLS array_partition variable=v524 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v524 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v524 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v524 type=ram_2p impl=lutram

  for (int v525 = 0; v525 < 1; v525 += 1) {	// L970
    for (int v526 = 0; v526 < 58; v526 += 1) {	// L971
      for (int v527 = 0; v527 < 58; v527 += 1) {	// L972
        for (int v528 = 0; v528 < 64; v528 += 1) {	// L973
          int8_t v529 = v523[v525][v528][1][v527];	// L974
          v523[v525][v528][0][v527] = v529;	// L975
          int8_t v530 = v523[v525][v528][2][v527];	// L976
          v523[v525][v528][1][v527] = v530;	// L977
          int8_t v531 = v514[v525][v528][v526][v527];	// L978
          v523[v525][v528][2][v527] = v531;	// L979
        }
        if ((v526 - 2) >= 0) {	// L981
          for (int v532 = 0; v532 < 64; v532 += 1) {	// L982
            for (int v533 = 0; v533 < 3; v533 += 1) {	// L983
              int8_t v534 = v524[v525][v532][v533][1];	// L984
              v524[v525][v532][v533][0] = v534;	// L985
              int8_t v535 = v524[v525][v532][v533][2];	// L986
              v524[v525][v532][v533][1] = v535;	// L987
              int8_t v536 = v523[v525][v532][v533][v527];	// L988
              v524[v525][v532][v533][2] = v536;	// L989
            }
          }
          if ((v527 - 2) >= 0) {	// L992
            int8_t v537[128];	// L993
            #pragma HLS bind_storage variable=v537 type=ram_2p impl=bram

            for (int v538 = 0; v538 < 128; v538 += 1) {	// L994
              v537[v538] = (int8_t)0.000000;	// L995
              for (int v539 = 0; v539 < 16; v539 += 1) {	// L996
                #pragma HLS pipeline II=1
                for (int v540 = 0; v540 < 4; v540 += 1) {	// L997
                  for (int v541 = 0; v541 < 3; v541 += 1) {	// L998
                    for (int v542 = 0; v542 < 3; v542 += 1) {	// L999
                      int8_t v543 = v524[v525][(v540 + (v539 * 4))][v541][v542];	// L1000
                      int8_t v544 = v511[v538][(v540 + (v539 * 4))][v541][v542];	// L1001
                      int8_t v545 = v543 * v544;	// L1002
                      int8_t v546 = v537[v538];	// L1003
                      int8_t v547 = v546 + v545;	// L1004
                      v537[v538] = v547;	// L1005
                    }
                  }
                }
              }
              int8_t v548 = v537[v538];	// L1010
              v522[v525][v538][(v526 - 2)][(v527 - 2)] = v548;	// L1011
            }
          }
        }
      }
    }
  }
  for (int v549 = 0; v549 < 1; v549 += 1) {	// L1018
    for (int v550 = 0; v550 < 56; v550 += 1) {	// L1019
      for (int v551 = 0; v551 < 56; v551 += 1) {	// L1020
        for (int v552 = 0; v552 < 128; v552 += 1) {	// L1021
          int8_t v553 = v522[0][v552][v550][v551];	// L1022
          bool v554 = v553 > (int8_t)0.000000;	// L1023
          int8_t v555 = v554 ? v553 : (int8_t)0.000000;	// L1024
          v513[v549][v552][v550][v551] = v555;	// L1025
        }
      }
    }
  }
  return ;	// L1030
}

void main_graph_node17(
  int8_t v556[1][64][112][112],
  int8_t v557[1][64][56][56]
) {	// L1032
  #pragma HLS dataflow

  int8_t v558;	// L1035
  v558 = (int8_t)-INFINITY;	// L1036
  int8_t v559[1][64][112][112];	// L1037
  #pragma HLS bind_storage variable=v559 type=ram_2p impl=bram

  for (int v560 = 0; v560 < 1; v560 += 1) {	// L1038
    for (int v561 = 0; v561 < 112; v561 += 1) {	// L1039
      for (int v562 = 0; v562 < 112; v562 += 1) {	// L1040
        for (int v563 = 0; v563 < 64; v563 += 1) {	// L1041
          int8_t v564 = v556[v560][v563][v561][v562];	// L1042
          v559[v560][v563][v561][v562] = v564;	// L1043
        }
      }
    }
  }
  for (int v565 = 0; v565 < 1; v565 += 1) {	// L1048
    for (int v566 = 0; v566 < 56; v566 += 1) {	// L1049
      for (int v567 = 0; v567 < 56; v567 += 1) {	// L1050
        for (int v568 = 0; v568 < 64; v568 += 1) {	// L1051
          int8_t v569;	// L1052
          v569 = (int8_t)0.000000;	// L1053
          for (int v570 = 0; v570 < 2; v570 += 1) {	// L1054
            for (int v571 = 0; v571 < 2; v571 += 1) {	// L1055
              int8_t v572 = v559[v565][v568][((v566 * 2) + v570)][((v567 * 2) + v571)];	// L1056
              int8_t v573 = v558;	// L1057
              int8_t v574 = max(v573, v572);	// L1058
              v569 = v574;	// L1059
            }
          }
          int8_t v575 = v569;	// L1062
          v557[v565][v568][v566][v567] = v575;	// L1063
        }
      }
    }
  }
  return ;	// L1068
}

void main_graph_node18(
  int8_t v576[64][64][3][3],
  int8_t v577[1][64][112][112],
  int8_t v578[1][64][112][112]
) {	// L1070
  #pragma HLS dataflow

  int8_t v579[1][64][114][114];	// L1072
  #pragma HLS stream variable=v579 depth=10 type=fifo

  #pragma HLS bind_storage variable=v579 type=ram_t2p impl=bram

  for (int v580 = 0; v580 < 1; v580 += 1) {	// L1073
    for (int v581 = 0; v581 < 114; v581 += 1) {	// L1074
      for (int v582 = 0; v582 < 114; v582 += 1) {	// L1075
        for (int v583 = 0; v583 < 64; v583 += 1) {	// L1076
          int8_t v584;	// L1077
          v584 = (int8_t)0.000000;	// L1078
          if (((-v581) + 111) >= 0 && ((-v582) + 111) >= 0) {	// L1079
            int8_t v585 = v577[v580][v583][v581][v582];	// L1080
            v584 = v585;	// L1081
          }
          int8_t v586 = v584;	// L1083
          v579[v580][v583][v581][v582] = v586;	// L1084
        }
      }
    }
  }
  int8_t v587[1][64][112][112];	// L1089
  #pragma HLS stream variable=v587 depth=10 type=fifo

  #pragma HLS bind_storage variable=v587 type=ram_t2p impl=bram

  int8_t v588[1][64][3][114];	// L1090
  #pragma HLS array_partition variable=v588 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v588 type=ram_2p impl=bram

  int8_t v589[1][64][3][3];	// L1091
  #pragma HLS array_partition variable=v589 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v589 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v589 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v589 type=ram_2p impl=lutram

  for (int v590 = 0; v590 < 1; v590 += 1) {	// L1092
    for (int v591 = 0; v591 < 114; v591 += 1) {	// L1093
      for (int v592 = 0; v592 < 114; v592 += 1) {	// L1094
        for (int v593 = 0; v593 < 64; v593 += 1) {	// L1095
          int8_t v594 = v588[v590][v593][1][v592];	// L1096
          v588[v590][v593][0][v592] = v594;	// L1097
          int8_t v595 = v588[v590][v593][2][v592];	// L1098
          v588[v590][v593][1][v592] = v595;	// L1099
          int8_t v596 = v579[v590][v593][v591][v592];	// L1100
          v588[v590][v593][2][v592] = v596;	// L1101
        }
        if ((v591 - 2) >= 0) {	// L1103
          for (int v597 = 0; v597 < 64; v597 += 1) {	// L1104
            for (int v598 = 0; v598 < 3; v598 += 1) {	// L1105
              int8_t v599 = v589[v590][v597][v598][1];	// L1106
              v589[v590][v597][v598][0] = v599;	// L1107
              int8_t v600 = v589[v590][v597][v598][2];	// L1108
              v589[v590][v597][v598][1] = v600;	// L1109
              int8_t v601 = v588[v590][v597][v598][v592];	// L1110
              v589[v590][v597][v598][2] = v601;	// L1111
            }
          }
          if ((v592 - 2) >= 0) {	// L1114
            int8_t v602[64];	// L1115
            #pragma HLS bind_storage variable=v602 type=ram_2p impl=bram

            for (int v603 = 0; v603 < 64; v603 += 1) {	// L1116
              v602[v603] = (int8_t)0.000000;	// L1117
              for (int v604 = 0; v604 < 4; v604 += 1) {	// L1118
                #pragma HLS pipeline II=1
                for (int v605 = 0; v605 < 16; v605 += 1) {	// L1119
                  for (int v606 = 0; v606 < 3; v606 += 1) {	// L1120
                    for (int v607 = 0; v607 < 3; v607 += 1) {	// L1121
                      int8_t v608 = v589[v590][(v605 + (v604 * 16))][v606][v607];	// L1122
                      int8_t v609 = v576[v603][(v605 + (v604 * 16))][v606][v607];	// L1123
                      int8_t v610 = v608 * v609;	// L1124
                      int8_t v611 = v602[v603];	// L1125
                      int8_t v612 = v611 + v610;	// L1126
                      v602[v603] = v612;	// L1127
                    }
                  }
                }
              }
              int8_t v613 = v602[v603];	// L1132
              v587[v590][v603][(v591 - 2)][(v592 - 2)] = v613;	// L1133
            }
          }
        }
      }
    }
  }
  for (int v614 = 0; v614 < 1; v614 += 1) {	// L1140
    for (int v615 = 0; v615 < 112; v615 += 1) {	// L1141
      for (int v616 = 0; v616 < 112; v616 += 1) {	// L1142
        for (int v617 = 0; v617 < 64; v617 += 1) {	// L1143
          int8_t v618 = v587[0][v617][v615][v616];	// L1144
          bool v619 = v618 > (int8_t)0.000000;	// L1145
          int8_t v620 = v619 ? v618 : (int8_t)0.000000;	// L1146
          v578[v614][v617][v615][v616] = v620;	// L1147
        }
      }
    }
  }
  return ;	// L1152
}

void main_graph_node19(
  int8_t v621[64][32][3][3],
  int8_t v622[1][32][112][112],
  int8_t v623[1][64][112][112]
) {	// L1154
  #pragma HLS dataflow

  int8_t v624[1][32][114][114];	// L1156
  #pragma HLS stream variable=v624 depth=10 type=fifo

  #pragma HLS bind_storage variable=v624 type=ram_t2p impl=bram

  for (int v625 = 0; v625 < 1; v625 += 1) {	// L1157
    for (int v626 = 0; v626 < 114; v626 += 1) {	// L1158
      for (int v627 = 0; v627 < 114; v627 += 1) {	// L1159
        for (int v628 = 0; v628 < 32; v628 += 1) {	// L1160
          int8_t v629;	// L1161
          v629 = (int8_t)0.000000;	// L1162
          if (((-v626) + 111) >= 0 && ((-v627) + 111) >= 0) {	// L1163
            int8_t v630 = v622[v625][v628][v626][v627];	// L1164
            v629 = v630;	// L1165
          }
          int8_t v631 = v629;	// L1167
          v624[v625][v628][v626][v627] = v631;	// L1168
        }
      }
    }
  }
  int8_t v632[1][64][112][112];	// L1173
  #pragma HLS stream variable=v632 depth=10 type=fifo

  #pragma HLS bind_storage variable=v632 type=ram_t2p impl=bram

  int8_t v633[1][32][3][114];	// L1174
  #pragma HLS array_partition variable=v633 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v633 type=ram_2p impl=bram

  int8_t v634[1][32][3][3];	// L1175
  #pragma HLS array_partition variable=v634 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v634 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v634 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v634 type=ram_2p impl=lutram

  for (int v635 = 0; v635 < 1; v635 += 1) {	// L1176
    for (int v636 = 0; v636 < 114; v636 += 1) {	// L1177
      for (int v637 = 0; v637 < 114; v637 += 1) {	// L1178
        for (int v638 = 0; v638 < 32; v638 += 1) {	// L1179
          int8_t v639 = v633[v635][v638][1][v637];	// L1180
          v633[v635][v638][0][v637] = v639;	// L1181
          int8_t v640 = v633[v635][v638][2][v637];	// L1182
          v633[v635][v638][1][v637] = v640;	// L1183
          int8_t v641 = v624[v635][v638][v636][v637];	// L1184
          v633[v635][v638][2][v637] = v641;	// L1185
        }
        if ((v636 - 2) >= 0) {	// L1187
          for (int v642 = 0; v642 < 32; v642 += 1) {	// L1188
            for (int v643 = 0; v643 < 3; v643 += 1) {	// L1189
              int8_t v644 = v634[v635][v642][v643][1];	// L1190
              v634[v635][v642][v643][0] = v644;	// L1191
              int8_t v645 = v634[v635][v642][v643][2];	// L1192
              v634[v635][v642][v643][1] = v645;	// L1193
              int8_t v646 = v633[v635][v642][v643][v637];	// L1194
              v634[v635][v642][v643][2] = v646;	// L1195
            }
          }
          if ((v637 - 2) >= 0) {	// L1198
            int8_t v647[64];	// L1199
            #pragma HLS bind_storage variable=v647 type=ram_2p impl=bram

            for (int v648 = 0; v648 < 64; v648 += 1) {	// L1200
              v647[v648] = (int8_t)0.000000;	// L1201
              for (int v649 = 0; v649 < 4; v649 += 1) {	// L1202
                #pragma HLS pipeline II=1
                for (int v650 = 0; v650 < 8; v650 += 1) {	// L1203
                  for (int v651 = 0; v651 < 3; v651 += 1) {	// L1204
                    for (int v652 = 0; v652 < 3; v652 += 1) {	// L1205
                      int8_t v653 = v634[v635][(v650 + (v649 * 8))][v651][v652];	// L1206
                      int8_t v654 = v621[v648][(v650 + (v649 * 8))][v651][v652];	// L1207
                      int8_t v655 = v653 * v654;	// L1208
                      int8_t v656 = v647[v648];	// L1209
                      int8_t v657 = v656 + v655;	// L1210
                      v647[v648] = v657;	// L1211
                    }
                  }
                }
              }
              int8_t v658 = v647[v648];	// L1216
              v632[v635][v648][(v636 - 2)][(v637 - 2)] = v658;	// L1217
            }
          }
        }
      }
    }
  }
  for (int v659 = 0; v659 < 1; v659 += 1) {	// L1224
    for (int v660 = 0; v660 < 112; v660 += 1) {	// L1225
      for (int v661 = 0; v661 < 112; v661 += 1) {	// L1226
        for (int v662 = 0; v662 < 64; v662 += 1) {	// L1227
          int8_t v663 = v632[0][v662][v660][v661];	// L1228
          bool v664 = v663 > (int8_t)0.000000;	// L1229
          int8_t v665 = v664 ? v663 : (int8_t)0.000000;	// L1230
          v623[v659][v662][v660][v661] = v665;	// L1231
        }
      }
    }
  }
  return ;	// L1236
}

void main_graph_node20(
  int8_t v666[1][32][224][224],
  int8_t v667[1][32][112][112]
) {	// L1238
  #pragma HLS dataflow

  int8_t v668;	// L1241
  v668 = (int8_t)-INFINITY;	// L1242
  int8_t v669[1][32][224][224];	// L1243
  #pragma HLS bind_storage variable=v669 type=ram_2p impl=bram

  for (int v670 = 0; v670 < 1; v670 += 1) {	// L1244
    for (int v671 = 0; v671 < 224; v671 += 1) {	// L1245
      for (int v672 = 0; v672 < 224; v672 += 1) {	// L1246
        for (int v673 = 0; v673 < 32; v673 += 1) {	// L1247
          int8_t v674 = v666[v670][v673][v671][v672];	// L1248
          v669[v670][v673][v671][v672] = v674;	// L1249
        }
      }
    }
  }
  for (int v675 = 0; v675 < 1; v675 += 1) {	// L1254
    for (int v676 = 0; v676 < 112; v676 += 1) {	// L1255
      for (int v677 = 0; v677 < 112; v677 += 1) {	// L1256
        for (int v678 = 0; v678 < 32; v678 += 1) {	// L1257
          int8_t v679;	// L1258
          v679 = (int8_t)0.000000;	// L1259
          for (int v680 = 0; v680 < 2; v680 += 1) {	// L1260
            for (int v681 = 0; v681 < 2; v681 += 1) {	// L1261
              int8_t v682 = v669[v675][v678][((v676 * 2) + v680)][((v677 * 2) + v681)];	// L1262
              int8_t v683 = v668;	// L1263
              int8_t v684 = max(v683, v682);	// L1264
              v679 = v684;	// L1265
            }
          }
          int8_t v685 = v679;	// L1268
          v667[v675][v678][v676][v677] = v685;	// L1269
        }
      }
    }
  }
  return ;	// L1274
}

void main_graph_node21(
  int8_t v686[1][32][224][224],
  int8_t v687[32][32][3][3],
  int8_t v688[1][32][224][224]
) {	// L1276
  #pragma HLS dataflow

  int8_t v689[1][32][226][226];	// L1278
  #pragma HLS stream variable=v689 depth=10 type=fifo

  #pragma HLS bind_storage variable=v689 type=ram_t2p impl=bram

  for (int v690 = 0; v690 < 1; v690 += 1) {	// L1279
    for (int v691 = 0; v691 < 226; v691 += 1) {	// L1280
      for (int v692 = 0; v692 < 226; v692 += 1) {	// L1281
        for (int v693 = 0; v693 < 32; v693 += 1) {	// L1282
          int8_t v694;	// L1283
          v694 = (int8_t)0.000000;	// L1284
          if (((-v691) + 223) >= 0 && ((-v692) + 223) >= 0) {	// L1285
            int8_t v695 = v686[v690][v693][v691][v692];	// L1286
            v694 = v695;	// L1287
          }
          int8_t v696 = v694;	// L1289
          v689[v690][v693][v691][v692] = v696;	// L1290
        }
      }
    }
  }
  int8_t v697[1][32][224][224];	// L1295
  #pragma HLS stream variable=v697 depth=10 type=fifo

  #pragma HLS bind_storage variable=v697 type=ram_t2p impl=bram

  int8_t v698[1][32][3][226];	// L1296
  #pragma HLS array_partition variable=v698 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v698 type=ram_2p impl=bram

  int8_t v699[1][32][3][3];	// L1297
  #pragma HLS array_partition variable=v699 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v699 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v699 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v699 type=ram_2p impl=lutram

  for (int v700 = 0; v700 < 1; v700 += 1) {	// L1298
    for (int v701 = 0; v701 < 226; v701 += 1) {	// L1299
      for (int v702 = 0; v702 < 226; v702 += 1) {	// L1300
        for (int v703 = 0; v703 < 32; v703 += 1) {	// L1301
          int8_t v704 = v698[v700][v703][1][v702];	// L1302
          v698[v700][v703][0][v702] = v704;	// L1303
          int8_t v705 = v698[v700][v703][2][v702];	// L1304
          v698[v700][v703][1][v702] = v705;	// L1305
          int8_t v706 = v689[v700][v703][v701][v702];	// L1306
          v698[v700][v703][2][v702] = v706;	// L1307
        }
        if ((v701 - 2) >= 0) {	// L1309
          for (int v707 = 0; v707 < 32; v707 += 1) {	// L1310
            for (int v708 = 0; v708 < 3; v708 += 1) {	// L1311
              int8_t v709 = v699[v700][v707][v708][1];	// L1312
              v699[v700][v707][v708][0] = v709;	// L1313
              int8_t v710 = v699[v700][v707][v708][2];	// L1314
              v699[v700][v707][v708][1] = v710;	// L1315
              int8_t v711 = v698[v700][v707][v708][v702];	// L1316
              v699[v700][v707][v708][2] = v711;	// L1317
            }
          }
          if ((v702 - 2) >= 0) {	// L1320
            int8_t v712[32];	// L1321
            #pragma HLS bind_storage variable=v712 type=ram_2p impl=bram

            for (int v713 = 0; v713 < 32; v713 += 1) {	// L1322
              v712[v713] = (int8_t)0.000000;	// L1323
              for (int v714 = 0; v714 < 2; v714 += 1) {	// L1324
                #pragma HLS pipeline II=1
                for (int v715 = 0; v715 < 16; v715 += 1) {	// L1325
                  for (int v716 = 0; v716 < 3; v716 += 1) {	// L1326
                    for (int v717 = 0; v717 < 3; v717 += 1) {	// L1327
                      int8_t v718 = v699[v700][(v715 + (v714 * 16))][v716][v717];	// L1328
                      int8_t v719 = v687[v713][(v715 + (v714 * 16))][v716][v717];	// L1329
                      int8_t v720 = v718 * v719;	// L1330
                      int8_t v721 = v712[v713];	// L1331
                      int8_t v722 = v721 + v720;	// L1332
                      v712[v713] = v722;	// L1333
                    }
                  }
                }
              }
              int8_t v723 = v712[v713];	// L1338
              v697[v700][v713][(v701 - 2)][(v702 - 2)] = v723;	// L1339
            }
          }
        }
      }
    }
  }
  for (int v724 = 0; v724 < 1; v724 += 1) {	// L1346
    for (int v725 = 0; v725 < 224; v725 += 1) {	// L1347
      for (int v726 = 0; v726 < 224; v726 += 1) {	// L1348
        for (int v727 = 0; v727 < 32; v727 += 1) {	// L1349
          int8_t v728 = v697[0][v727][v725][v726];	// L1350
          bool v729 = v728 > (int8_t)0.000000;	// L1351
          int8_t v730 = v729 ? v728 : (int8_t)0.000000;	// L1352
          v688[v724][v727][v725][v726] = v730;	// L1353
        }
      }
    }
  }
  return ;	// L1358
}

void main_graph_node22(
  int8_t v731[1][3][224][224],
  int8_t v732[32][3][3][3],
  int8_t v733[1][32][224][224]
) {	// L1360
  #pragma HLS dataflow

  int8_t v734[1][3][226][226];	// L1362
  #pragma HLS stream variable=v734 depth=10 type=fifo

  #pragma HLS bind_storage variable=v734 type=ram_t2p impl=bram

  for (int v735 = 0; v735 < 1; v735 += 1) {	// L1363
    for (int v736 = 0; v736 < 226; v736 += 1) {	// L1364
      for (int v737 = 0; v737 < 226; v737 += 1) {	// L1365
        for (int v738 = 0; v738 < 3; v738 += 1) {	// L1366
          int8_t v739;	// L1367
          v739 = (int8_t)0.000000;	// L1368
          if (((-v736) + 223) >= 0 && ((-v737) + 223) >= 0) {	// L1369
            int8_t v740 = v731[v735][v738][v736][v737];	// L1370
            v739 = v740;	// L1371
          }
          int8_t v741 = v739;	// L1373
          v734[v735][v738][v736][v737] = v741;	// L1374
        }
      }
    }
  }
  int8_t v742[1][32][224][224];	// L1379
  #pragma HLS stream variable=v742 depth=10 type=fifo

  #pragma HLS bind_storage variable=v742 type=ram_t2p impl=bram

  int8_t v743[1][3][3][226];	// L1380
  #pragma HLS array_partition variable=v743 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v743 type=ram_2p impl=lutram

  int8_t v744[1][3][3][3];	// L1381
  #pragma HLS array_partition variable=v744 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v744 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v744 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v744 type=ram_2p impl=lutram

  for (int v745 = 0; v745 < 1; v745 += 1) {	// L1382
    for (int v746 = 0; v746 < 226; v746 += 1) {	// L1383
      for (int v747 = 0; v747 < 226; v747 += 1) {	// L1384
        for (int v748 = 0; v748 < 3; v748 += 1) {	// L1385
          int8_t v749 = v743[v745][v748][1][v747];	// L1386
          v743[v745][v748][0][v747] = v749;	// L1387
          int8_t v750 = v743[v745][v748][2][v747];	// L1388
          v743[v745][v748][1][v747] = v750;	// L1389
          int8_t v751 = v734[v745][v748][v746][v747];	// L1390
          v743[v745][v748][2][v747] = v751;	// L1391
        }
        if ((v746 - 2) >= 0) {	// L1393
          for (int v752 = 0; v752 < 3; v752 += 1) {	// L1394
            for (int v753 = 0; v753 < 3; v753 += 1) {	// L1395
              int8_t v754 = v744[v745][v752][v753][1];	// L1396
              v744[v745][v752][v753][0] = v754;	// L1397
              int8_t v755 = v744[v745][v752][v753][2];	// L1398
              v744[v745][v752][v753][1] = v755;	// L1399
              int8_t v756 = v743[v745][v752][v753][v747];	// L1400
              v744[v745][v752][v753][2] = v756;	// L1401
            }
          }
          if ((v747 - 2) >= 0) {	// L1404
            int8_t v757[32];	// L1405
            #pragma HLS bind_storage variable=v757 type=ram_2p impl=bram

            for (int v758 = 0; v758 < 32; v758 += 1) {	// L1406
              #pragma HLS pipeline II=1
              for (int v759 = 0; v759 < 1; v759 += 1) {	// L1407
                v757[(v758 + v759)] = (int8_t)0.000000;	// L1408
                for (int v760 = 0; v760 < 3; v760 += 1) {	// L1409
                  for (int v761 = 0; v761 < 3; v761 += 1) {	// L1410
                    for (int v762 = 0; v762 < 3; v762 += 1) {	// L1411
                      int8_t v763 = v744[v745][v760][v761][v762];	// L1412
                      int8_t v764 = v732[(v758 + v759)][v760][v761][v762];	// L1413
                      int8_t v765 = v763 * v764;	// L1414
                      int8_t v766 = v757[(v758 + v759)];	// L1415
                      int8_t v767 = v766 + v765;	// L1416
                      v757[(v758 + v759)] = v767;	// L1417
                    }
                  }
                }
                int8_t v768 = v757[(v758 + v759)];	// L1421
                v742[v745][(v758 + v759)][(v746 - 2)][(v747 - 2)] = v768;	// L1422
              }
            }
          }
        }
      }
    }
  }
  for (int v769 = 0; v769 < 1; v769 += 1) {	// L1430
    for (int v770 = 0; v770 < 224; v770 += 1) {	// L1431
      for (int v771 = 0; v771 < 224; v771 += 1) {	// L1432
        for (int v772 = 0; v772 < 32; v772 += 1) {	// L1433
          int8_t v773 = v742[0][v772][v770][v771];	// L1434
          bool v774 = v773 > (int8_t)0.000000;	// L1435
          int8_t v775 = v774 ? v773 : (int8_t)0.000000;	// L1436
          v733[v769][v772][v770][v771] = v775;	// L1437
        }
      }
    }
  }
  return ;	// L1442
}

/// This is top function.
void main_graph(
  int8_t v776[1][3][224][224],
  int8_t v777[1000],
  int8_t v778[2048],
  int8_t v779[2048][512][7][7],
  int8_t v780[512][512][3][3],
  int8_t v781[512][512][3][3],
  int8_t v782[512][256][3][3],
  int8_t v783[256][256][3][3],
  int8_t v784[256][256][3][3],
  int8_t v785[256][128][3][3],
  int8_t v786[128][128][3][3],
  int8_t v787[128][128][3][3],
  int8_t v788[128][64][3][3],
  int8_t v789[64][64][3][3],
  int8_t v790[64][32][3][3],
  int8_t v791[32][32][3][3],
  int8_t v792[32][3][3][3],
  int8_t v793[2048][2048],
  int8_t v794[2048][1000],
  int8_t v795[1][1000]
) {	// L1444
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v776 bundle=gmem1
  #pragma HLS bind_storage variable=v776 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v777 bundle=gmem2
  #pragma HLS bind_storage variable=v777 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v778 bundle=gmem3
  #pragma HLS bind_storage variable=v778 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v779 bundle=gmem4
  #pragma HLS array_partition variable=v779 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v779 cyclic factor=7 dim=3
  #pragma HLS array_partition variable=v779 cyclic factor=7 dim=4
  #pragma HLS bind_storage variable=v779 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v780 bundle=gmem5
  #pragma HLS array_partition variable=v780 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v780 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v780 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v780 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v781 bundle=gmem6
  #pragma HLS array_partition variable=v781 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v781 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v781 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v781 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v782 bundle=gmem7
  #pragma HLS array_partition variable=v782 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v782 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v782 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v782 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v783 bundle=gmem8
  #pragma HLS array_partition variable=v783 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v783 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v783 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v783 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v784 bundle=gmem9
  #pragma HLS array_partition variable=v784 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v784 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v784 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v784 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v785 bundle=gmem10
  #pragma HLS array_partition variable=v785 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v785 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v785 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v785 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v786 bundle=gmem11
  #pragma HLS array_partition variable=v786 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v786 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v786 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v786 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v787 bundle=gmem12
  #pragma HLS array_partition variable=v787 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v787 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v787 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v787 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v788 bundle=gmem13
  #pragma HLS array_partition variable=v788 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v788 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v788 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v788 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v789 bundle=gmem14
  #pragma HLS array_partition variable=v789 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v789 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v789 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v789 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v790 bundle=gmem15
  #pragma HLS array_partition variable=v790 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v790 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v790 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v790 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v791 bundle=gmem16
  #pragma HLS array_partition variable=v791 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v791 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v791 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v791 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v792 bundle=gmem17
  #pragma HLS array_partition variable=v792 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v792 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v792 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v792 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v793 bundle=gmem18
  #pragma HLS bind_storage variable=v793 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v794 bundle=gmem19
  #pragma HLS bind_storage variable=v794 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v795 bundle=gmem20
  #pragma HLS bind_storage variable=v795 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v796[1][32][224][224];	// L1446
  #pragma HLS stream variable=v796 depth=10 type=fifo

  #pragma HLS bind_storage variable=v796 type=ram_t2p impl=bram

  main_graph_node22(v776, v792, v796);	// L1447
  int8_t v797[1][32][224][224];	// L1448
  #pragma HLS stream variable=v797 depth=10 type=fifo

  #pragma HLS bind_storage variable=v797 type=ram_t2p impl=bram

  main_graph_node21(v796, v791, v797);	// L1449
  int8_t v798[1][32][112][112];	// L1450
  #pragma HLS stream variable=v798 depth=10 type=fifo

  #pragma HLS bind_storage variable=v798 type=ram_t2p impl=bram

  main_graph_node20(v797, v798);	// L1451
  int8_t v799[1][64][112][112];	// L1452
  #pragma HLS stream variable=v799 depth=10 type=fifo

  #pragma HLS bind_storage variable=v799 type=ram_t2p impl=bram

  main_graph_node19(v790, v798, v799);	// L1453
  int8_t v800[1][64][112][112];	// L1454
  #pragma HLS stream variable=v800 depth=10 type=fifo

  #pragma HLS bind_storage variable=v800 type=ram_t2p impl=bram

  main_graph_node18(v789, v799, v800);	// L1455
  int8_t v801[1][64][56][56];	// L1456
  #pragma HLS stream variable=v801 depth=10 type=fifo

  #pragma HLS bind_storage variable=v801 type=ram_t2p impl=bram

  main_graph_node17(v800, v801);	// L1457
  int8_t v802[1][128][56][56];	// L1458
  #pragma HLS stream variable=v802 depth=10 type=fifo

  #pragma HLS bind_storage variable=v802 type=ram_t2p impl=bram

  main_graph_node16(v788, v801, v802);	// L1459
  int8_t v803[1][128][56][56];	// L1460
  #pragma HLS stream variable=v803 depth=10 type=fifo

  #pragma HLS bind_storage variable=v803 type=ram_t2p impl=bram

  main_graph_node15(v787, v802, v803);	// L1461
  int8_t v804[1][128][56][56];	// L1462
  #pragma HLS stream variable=v804 depth=10 type=fifo

  #pragma HLS bind_storage variable=v804 type=ram_t2p impl=bram

  main_graph_node14(v803, v786, v804);	// L1463
  int8_t v805[1][128][28][28];	// L1464
  #pragma HLS stream variable=v805 depth=10 type=fifo

  #pragma HLS bind_storage variable=v805 type=ram_t2p impl=bram

  main_graph_node13(v804, v805);	// L1465
  int8_t v806[1][256][28][28];	// L1466
  #pragma HLS stream variable=v806 depth=10 type=fifo

  #pragma HLS bind_storage variable=v806 type=ram_t2p impl=bram

  main_graph_node12(v805, v785, v806);	// L1467
  int8_t v807[1][256][28][28];	// L1468
  #pragma HLS stream variable=v807 depth=10 type=fifo

  #pragma HLS bind_storage variable=v807 type=ram_t2p impl=bram

  main_graph_node11(v806, v784, v807);	// L1469
  int8_t v808[1][256][28][28];	// L1470
  #pragma HLS stream variable=v808 depth=10 type=fifo

  #pragma HLS bind_storage variable=v808 type=ram_t2p impl=bram

  main_graph_node10(v807, v783, v808);	// L1471
  int8_t v809[1][256][14][14];	// L1472
  #pragma HLS stream variable=v809 depth=10 type=fifo

  #pragma HLS bind_storage variable=v809 type=ram_t2p impl=bram

  main_graph_node9(v808, v809);	// L1473
  int8_t v810[1][512][14][14];	// L1474
  #pragma HLS stream variable=v810 depth=10 type=fifo

  #pragma HLS bind_storage variable=v810 type=ram_t2p impl=bram

  main_graph_node8(v809, v782, v810);	// L1475
  int8_t v811[1][512][14][14];	// L1476
  #pragma HLS stream variable=v811 depth=10 type=fifo

  #pragma HLS bind_storage variable=v811 type=ram_t2p impl=bram

  main_graph_node7(v810, v781, v811);	// L1477
  int8_t v812[1][512][14][14];	// L1478
  #pragma HLS stream variable=v812 depth=10 type=fifo

  #pragma HLS bind_storage variable=v812 type=ram_t2p impl=bram

  main_graph_node6(v780, v811, v812);	// L1479
  int8_t v813[1][512][7][7];	// L1480
  #pragma HLS stream variable=v813 depth=10 type=fifo

  #pragma HLS bind_storage variable=v813 type=ram_t2p impl=bram

  main_graph_node5(v812, v813);	// L1481
  int8_t v814[1][2048][1][1];	// L1482
  #pragma HLS bind_storage variable=v814 type=ram_t2p impl=bram

  main_graph_node4(v813, v779, v814);	// L1483
  int8_t v815[1][2048];	// L1484
  #pragma HLS bind_storage variable=v815 type=ram_t2p impl=bram

  main_graph_node3(v814, v793, v815);	// L1485
  int8_t v816[1][2048];	// L1486
  #pragma HLS bind_storage variable=v816 type=ram_t2p impl=bram

  main_graph_node2(v815, v778, v816);	// L1487
  int8_t v817[1][1000];	// L1488
  #pragma HLS bind_storage variable=v817 type=ram_t2p impl=bram

  main_graph_node1(v816, v794, v817);	// L1489
  main_graph_node0(v817, v777, v795);	// L1490
  return ;	// L1491
}

