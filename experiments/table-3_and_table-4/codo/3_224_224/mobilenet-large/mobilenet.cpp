
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
) {	// L16
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 1; v3 += 1) {	// L17
    for (int v4 = 0; v4 < 1000; v4 += 1) {	// L18
      int8_t v5 = v0[0][v4];	// L19
      int8_t v6 = v1[v4];	// L20
      int8_t v7 = v5 + v6;	// L21
      v2[v3][v4] = v7;	// L22
    }
  }
  return ;	// L25
}

void main_graph_node1(
  int8_t v8[1][1024][1][1],
  int8_t v9[1024][1000],
  int8_t v10[1][1000]
) {	// L27
  #pragma HLS dataflow

  int8_t v11[1][1000];	// L29
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  for (int v12 = 0; v12 < 1; v12 += 1) {	// L30
    for (int v13 = 0; v13 < 1000; v13 += 1) {	// L31
      v11[v12][v13] = (int8_t)0.000000;	// L32
    }
  }
  for (int v14 = 0; v14 < 1; v14 += 1) {	// L35
    for (int v15 = 0; v15 < 1000; v15 += 1) {	// L36
      for (int v16 = 0; v16 < 1024; v16 += 1) {	// L37
        int8_t v17 = v8[v14][v16][0][0];	// L38
        int8_t v18 = v9[v16][v15];	// L39
        int8_t v19 = v11[v14][v15];	// L40
        int8_t v20 = v17 * v18;	// L41
        int8_t v21 = v19 + v20;	// L42
        v10[v14][v15] = v21;	// L43
      }
    }
  }
  return ;	// L47
}

void main_graph_node2(
  int8_t v22[1][1024][1][1],
  int8_t v23[1][1],
  int8_t v24[1][1024][1][1]
) {	// L49
  #pragma HLS dataflow

  int8_t v25[1][1024][1][1];	// L50
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  for (int v26 = 0; v26 < 1; v26 += 1) {	// L51
    for (int v27 = 0; v27 < 1024; v27 += 1) {	// L52
      for (int v28 = 0; v28 < 1; v28 += 1) {	// L53
        for (int v29 = 0; v29 < 1; v29 += 1) {	// L54
          int8_t v30 = v22[v26][v27][v28][v29];	// L55
          v25[v26][v27][v28][v29] = v30;	// L56
          int8_t v31 = v23[v28][v29];	// L57
          int8_t v32 = v25[v26][v27][v28][v29];	// L58
          int8_t v33 = v32 / v31;	// L59
          v24[v26][v27][v28][v29] = v33;	// L60
        }
      }
    }
  }
  return ;	// L65
}

void main_graph_node3(
  int8_t v34[1][1024][8][8],
  int8_t v35[1][1],
  int8_t v36[1][1024][1][1]
) {	// L67
  #pragma HLS dataflow

  int8_t v37[1][1024][1][1];	// L71
  #pragma HLS bind_storage variable=v37 type=ram_t2p impl=bram

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L72
    for (int v39 = 0; v39 < 1024; v39 += 1) {	// L73
      for (int v40 = 0; v40 < 1; v40 += 1) {	// L74
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L75
          v37[v38][v39][v40][v41] = (int8_t)0.000000;	// L76
        }
      }
    }
  }
  for (int v42 = 0; v42 < 1; v42 += 1) {	// L81
    for (int v43 = 0; v43 < 1024; v43 += 1) {	// L82
      for (int v44 = 0; v44 < 1; v44 += 1) {	// L83
        for (int v45 = 0; v45 < 1; v45 += 1) {	// L84
          for (int v46 = 0; v46 < 7; v46 += 1) {	// L85
            for (int v47 = 0; v47 < 7; v47 += 1) {	// L86
              int8_t v48 = v37[v42][v43][v44][v45];	// L87
              int v49 = v44 * (int)7;	// L88
              int v50 = v44 + (int)1;	// L89
              int v51 = v50 * (int)7;	// L90
              int v52 = v45 * (int)7;	// L91
              int v53 = v45 + (int)1;	// L92
              int v54 = v53 * (int)7;	// L93
              int v55 = v49 + v46;	// L94
              int v56 = v52 + v47;	// L95
              int8_t v57 = v34[v42][v43][v55][v56];	// L96
              bool v58 = v55 < v51;	// L97
              int8_t v59 = v58 ? v57 : (int8_t)0.000000;	// L98
              bool v60 = v56 < v54;	// L99
              int8_t v61 = v60 ? v59 : (int8_t)0.000000;	// L100
              int8_t v62 = v61 + v48;	// L101
              int v63 = v51 - v49;	// L102
              int v64 = v54 - v52;	// L103
              int v65 = v63 * v64;	// L104
              ap_int<64> v66 = v65;	// L105
              int8_t v67 = v66;	// L106
              v36[v42][v43][v44][v45] = v62;	// L107
              v35[v42][v43] = v67;	// L108
            }
          }
        }
      }
    }
  }
  return ;	// L115
}

void main_graph_node4(
  int8_t v68[1][1024][7][7],
  int8_t v69[1][1024][8][8]
) {	// L117
  #pragma HLS dataflow

  for (int v70 = 0; v70 < 1; v70 += 1) {	// L119
    for (int v71 = 0; v71 < 8; v71 += 1) {	// L120
      for (int v72 = 0; v72 < 8; v72 += 1) {	// L121
        for (int v73 = 0; v73 < 1024; v73 += 1) {	// L122
          int8_t v74;	// L123
          v74 = (int8_t)0.000000;	// L124
          if (((-v71) + 6) >= 0 && ((-v72) + 6) >= 0) {	// L125
            int8_t v75 = v68[v70][v73][v71][v72];	// L126
            v74 = v75;	// L127
          }
          int8_t v76 = v74;	// L129
          v69[v70][v73][v71][v72] = v76;	// L130
        }
      }
    }
  }
  return ;	// L135
}

void main_graph_node5(
  int8_t v77[1][1024][7][7],
  int8_t v78[1024][1024][1][1],
  int8_t v79[1][1024][7][7]
) {	// L137
  #pragma HLS dataflow

  int8_t v80[1][1024][7][7];	// L139
  #pragma HLS stream variable=v80 depth=10 type=fifo

  #pragma HLS bind_storage variable=v80 type=ram_t2p impl=bram

  int8_t v81[1][1024][1][7];	// L140
  #pragma HLS bind_storage variable=v81 type=ram_2p impl=bram

  int8_t v82[1][1024][1][1];	// L141
  #pragma HLS array_partition variable=v82 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v82 type=ram_2p impl=lutram

  for (int v83 = 0; v83 < 1; v83 += 1) {	// L142
    for (int v84 = 0; v84 < 7; v84 += 1) {	// L143
      for (int v85 = 0; v85 < 7; v85 += 1) {	// L144
        for (int v86 = 0; v86 < 1024; v86 += 1) {	// L145
          int8_t v87 = v77[v83][v86][v84][v85];	// L146
          v81[v83][v86][0][v85] = v87;	// L147
        }
        if (v84 >= 0) {	// L149
          for (int v88 = 0; v88 < 1024; v88 += 1) {	// L150
            for (int v89 = 0; v89 < 1; v89 += 1) {	// L151
              int8_t v90 = v81[v83][v88][v89][v85];	// L152
              v82[v83][v88][v89][0] = v90;	// L153
            }
          }
          if (v85 >= 0) {	// L156
            int8_t v91[1024];	// L157
            #pragma HLS bind_storage variable=v91 type=ram_2p impl=bram

            for (int v92 = 0; v92 < 1024; v92 += 1) {	// L158
              v91[v92] = (int8_t)0.000000;	// L159
              for (int v93 = 0; v93 < 32; v93 += 1) {	// L160
                #pragma HLS pipeline II=1
                for (int v94 = 0; v94 < 32; v94 += 1) {	// L161
                  for (int v95 = 0; v95 < 1; v95 += 1) {	// L162
                    for (int v96 = 0; v96 < 1; v96 += 1) {	// L163
                      int8_t v97 = v82[v83][(v94 + (v93 * 32))][v95][v96];	// L164
                      int8_t v98 = v78[v92][(v94 + (v93 * 32))][v95][v96];	// L165
                      int8_t v99 = v97 * v98;	// L166
                      int8_t v100 = v91[v92];	// L167
                      int8_t v101 = v100 + v99;	// L168
                      v91[v92] = v101;	// L169
                    }
                  }
                }
              }
              int8_t v102 = v91[v92];	// L174
              v80[v83][v92][v84][v85] = v102;	// L175
            }
          }
        }
      }
    }
  }
  for (int v103 = 0; v103 < 1; v103 += 1) {	// L182
    for (int v104 = 0; v104 < 7; v104 += 1) {	// L183
      for (int v105 = 0; v105 < 7; v105 += 1) {	// L184
        for (int v106 = 0; v106 < 1024; v106 += 1) {	// L185
          int8_t v107 = v80[0][v106][v104][v105];	// L186
          bool v108 = v107 > (int8_t)0.000000;	// L187
          int8_t v109 = v108 ? v107 : (int8_t)0.000000;	// L188
          v79[v103][v106][v104][v105] = v109;	// L189
        }
      }
    }
  }
  return ;	// L194
}

void main_graph_node6(
  int8_t v110[1][1024][7][7],
  int8_t v111[1024][3][3],
  int8_t v112[1][1024][7][7]
) {	// L196
  #pragma HLS dataflow

  int8_t v113[1][1024][9][9];	// L198
  #pragma HLS stream variable=v113 depth=10 type=fifo

  #pragma HLS bind_storage variable=v113 type=ram_t2p impl=bram

  for (int v114 = 0; v114 < 1; v114 += 1) {	// L199
    for (int v115 = 0; v115 < 9; v115 += 1) {	// L200
      for (int v116 = 0; v116 < 9; v116 += 1) {	// L201
        for (int v117 = 0; v117 < 1024; v117 += 1) {	// L202
          int8_t v118;	// L203
          v118 = (int8_t)0.000000;	// L204
          if (((-v115) + 6) >= 0 && ((-v116) + 6) >= 0) {	// L205
            int8_t v119 = v110[v114][v117][v115][v116];	// L206
            v118 = v119;	// L207
          }
          int8_t v120 = v118;	// L209
          v113[v114][v117][v115][v116] = v120;	// L210
        }
      }
    }
  }
  int8_t v121[1][1024][7][7];	// L215
  #pragma HLS stream variable=v121 depth=10 type=fifo

  #pragma HLS bind_storage variable=v121 type=ram_t2p impl=bram

  int8_t v122[1][1024][3][9];	// L216
  #pragma HLS array_partition variable=v122 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v122 type=ram_2p impl=bram

  int8_t v123[1][1024][3][3];	// L217
  #pragma HLS array_partition variable=v123 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v123 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v123 type=ram_2p impl=bram

  for (int v124 = 0; v124 < 1; v124 += 1) {	// L218
    for (int v125 = 0; v125 < 9; v125 += 1) {	// L219
      for (int v126 = 0; v126 < 9; v126 += 1) {	// L220
        for (int v127 = 0; v127 < 1024; v127 += 1) {	// L221
          int8_t v128 = v122[v124][v127][1][v126];	// L222
          v122[v124][v127][0][v126] = v128;	// L223
          int8_t v129 = v122[v124][v127][2][v126];	// L224
          v122[v124][v127][1][v126] = v129;	// L225
          int8_t v130 = v113[v124][v127][v125][v126];	// L226
          v122[v124][v127][2][v126] = v130;	// L227
        }
        if ((v125 - 2) >= 0) {	// L229
          for (int v131 = 0; v131 < 1024; v131 += 1) {	// L230
            for (int v132 = 0; v132 < 3; v132 += 1) {	// L231
              int8_t v133 = v123[v124][v131][v132][1];	// L232
              v123[v124][v131][v132][0] = v133;	// L233
              int8_t v134 = v123[v124][v131][v132][2];	// L234
              v123[v124][v131][v132][1] = v134;	// L235
              int8_t v135 = v122[v124][v131][v132][v126];	// L236
              v123[v124][v131][v132][2] = v135;	// L237
            }
          }
          if ((v126 - 2) >= 0) {	// L240
            int8_t v136[1024];	// L241
            #pragma HLS bind_storage variable=v136 type=ram_2p impl=bram

            for (int v137 = 0; v137 < 1024; v137 += 1) {	// L242
              #pragma HLS pipeline II=1
              for (int v138 = 0; v138 < 1; v138 += 1) {	// L243
                v136[(v137 + v138)] = (int8_t)0.000000;	// L244
                for (int v139 = 0; v139 < 3; v139 += 1) {	// L245
                  for (int v140 = 0; v140 < 3; v140 += 1) {	// L246
                    int8_t v141 = v123[v124][(v137 + v138)][v139][v140];	// L247
                    int8_t v142 = v111[(v137 + v138)][v139][v140];	// L248
                    int8_t v143 = v141 * v142;	// L249
                    int8_t v144 = v136[(v137 + v138)];	// L250
                    int8_t v145 = v144 + v143;	// L251
                    v136[(v137 + v138)] = v145;	// L252
                  }
                }
                int8_t v146 = v136[(v137 + v138)];	// L255
                v121[v124][(v137 + v138)][(v125 - 2)][(v126 - 2)] = v146;	// L256
              }
            }
          }
        }
      }
    }
  }
  for (int v147 = 0; v147 < 1; v147 += 1) {	// L264
    for (int v148 = 0; v148 < 7; v148 += 1) {	// L265
      for (int v149 = 0; v149 < 7; v149 += 1) {	// L266
        for (int v150 = 0; v150 < 1024; v150 += 1) {	// L267
          int8_t v151 = v121[0][v150][v148][v149];	// L268
          bool v152 = v151 > (int8_t)0.000000;	// L269
          int8_t v153 = v152 ? v151 : (int8_t)0.000000;	// L270
          v112[v147][v150][v148][v149] = v153;	// L271
        }
      }
    }
  }
  return ;	// L276
}

void main_graph_node7(
  int8_t v154[1024][512][1][1],
  int8_t v155[1][512][7][7],
  int8_t v156[1][1024][7][7]
) {	// L278
  #pragma HLS dataflow

  int8_t v157[1][1024][7][7];	// L280
  #pragma HLS stream variable=v157 depth=10 type=fifo

  #pragma HLS bind_storage variable=v157 type=ram_t2p impl=bram

  int8_t v158[1][512][1][7];	// L281
  #pragma HLS bind_storage variable=v158 type=ram_2p impl=bram

  int8_t v159[1][512][1][1];	// L282
  #pragma HLS array_partition variable=v159 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v159 type=ram_2p impl=lutram

  for (int v160 = 0; v160 < 1; v160 += 1) {	// L283
    for (int v161 = 0; v161 < 7; v161 += 1) {	// L284
      for (int v162 = 0; v162 < 7; v162 += 1) {	// L285
        for (int v163 = 0; v163 < 512; v163 += 1) {	// L286
          int8_t v164 = v155[v160][v163][v161][v162];	// L287
          v158[v160][v163][0][v162] = v164;	// L288
        }
        if (v161 >= 0) {	// L290
          for (int v165 = 0; v165 < 512; v165 += 1) {	// L291
            for (int v166 = 0; v166 < 1; v166 += 1) {	// L292
              int8_t v167 = v158[v160][v165][v166][v162];	// L293
              v159[v160][v165][v166][0] = v167;	// L294
            }
          }
          if (v162 >= 0) {	// L297
            int8_t v168[1024];	// L298
            #pragma HLS bind_storage variable=v168 type=ram_2p impl=bram

            for (int v169 = 0; v169 < 1024; v169 += 1) {	// L299
              v168[v169] = (int8_t)0.000000;	// L300
              for (int v170 = 0; v170 < 32; v170 += 1) {	// L301
                #pragma HLS pipeline II=1
                for (int v171 = 0; v171 < 16; v171 += 1) {	// L302
                  for (int v172 = 0; v172 < 1; v172 += 1) {	// L303
                    for (int v173 = 0; v173 < 1; v173 += 1) {	// L304
                      int8_t v174 = v159[v160][(v171 + (v170 * 16))][v172][v173];	// L305
                      int8_t v175 = v154[v169][(v171 + (v170 * 16))][v172][v173];	// L306
                      int8_t v176 = v174 * v175;	// L307
                      int8_t v177 = v168[v169];	// L308
                      int8_t v178 = v177 + v176;	// L309
                      v168[v169] = v178;	// L310
                    }
                  }
                }
              }
              int8_t v179 = v168[v169];	// L315
              v157[v160][v169][v161][v162] = v179;	// L316
            }
          }
        }
      }
    }
  }
  for (int v180 = 0; v180 < 1; v180 += 1) {	// L323
    for (int v181 = 0; v181 < 7; v181 += 1) {	// L324
      for (int v182 = 0; v182 < 7; v182 += 1) {	// L325
        for (int v183 = 0; v183 < 1024; v183 += 1) {	// L326
          int8_t v184 = v157[0][v183][v181][v182];	// L327
          bool v185 = v184 > (int8_t)0.000000;	// L328
          int8_t v186 = v185 ? v184 : (int8_t)0.000000;	// L329
          v156[v180][v183][v181][v182] = v186;	// L330
        }
      }
    }
  }
  return ;	// L335
}

void main_graph_node8(
  int8_t v187[1][512][14][14],
  int8_t v188[512][3][3],
  int8_t v189[1][512][7][7]
) {	// L337
  #pragma HLS dataflow

  int8_t v190[1][512][16][16];	// L339
  #pragma HLS stream variable=v190 depth=10 type=fifo

  #pragma HLS bind_storage variable=v190 type=ram_t2p impl=bram

  for (int v191 = 0; v191 < 1; v191 += 1) {	// L340
    for (int v192 = 0; v192 < 16; v192 += 1) {	// L341
      for (int v193 = 0; v193 < 16; v193 += 1) {	// L342
        for (int v194 = 0; v194 < 512; v194 += 1) {	// L343
          int8_t v195;	// L344
          v195 = (int8_t)0.000000;	// L345
          if (((-v192) + 13) >= 0 && ((-v193) + 13) >= 0) {	// L346
            int8_t v196 = v187[v191][v194][v192][v193];	// L347
            v195 = v196;	// L348
          }
          int8_t v197 = v195;	// L350
          v190[v191][v194][v192][v193] = v197;	// L351
        }
      }
    }
  }
  int8_t v198[1][512][7][7];	// L356
  #pragma HLS stream variable=v198 depth=10 type=fifo

  #pragma HLS bind_storage variable=v198 type=ram_t2p impl=bram

  int8_t v199[1][512][3][16];	// L357
  #pragma HLS array_partition variable=v199 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v199 type=ram_2p impl=bram

  int8_t v200[1][512][3][3];	// L358
  #pragma HLS array_partition variable=v200 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v200 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v200 type=ram_2p impl=lutram

  for (int v201 = 0; v201 < 1; v201 += 1) {	// L359
    for (int v202 = 0; v202 < 16; v202 += 1) {	// L360
      for (int v203 = 0; v203 < 16; v203 += 1) {	// L361
        for (int v204 = 0; v204 < 512; v204 += 1) {	// L362
          int8_t v205 = v199[v201][v204][1][v203];	// L363
          v199[v201][v204][0][v203] = v205;	// L364
          int8_t v206 = v199[v201][v204][2][v203];	// L365
          v199[v201][v204][1][v203] = v206;	// L366
          int8_t v207 = v190[v201][v204][v202][v203];	// L367
          v199[v201][v204][2][v203] = v207;	// L368
        }
        if ((v202 - 9) >= 0) {	// L370
          for (int v208 = 0; v208 < 512; v208 += 1) {	// L371
            for (int v209 = 0; v209 < 3; v209 += 1) {	// L372
              int8_t v210 = v200[v201][v208][v209][1];	// L373
              v200[v201][v208][v209][0] = v210;	// L374
              int8_t v211 = v200[v201][v208][v209][2];	// L375
              v200[v201][v208][v209][1] = v211;	// L376
              int8_t v212 = v199[v201][v208][v209][v203];	// L377
              v200[v201][v208][v209][2] = v212;	// L378
            }
          }
          if ((v203 - 9) >= 0) {	// L381
            int8_t v213[512];	// L382
            #pragma HLS bind_storage variable=v213 type=ram_2p impl=bram

            for (int v214 = 0; v214 < 512; v214 += 1) {	// L383
              #pragma HLS pipeline II=1
              for (int v215 = 0; v215 < 1; v215 += 1) {	// L384
                v213[(v214 + v215)] = (int8_t)0.000000;	// L385
                for (int v216 = 0; v216 < 3; v216 += 1) {	// L386
                  for (int v217 = 0; v217 < 3; v217 += 1) {	// L387
                    int8_t v218 = v200[v201][(v214 + v215)][v216][v217];	// L388
                    int8_t v219 = v188[(v214 + v215)][v216][v217];	// L389
                    int8_t v220 = v218 * v219;	// L390
                    int8_t v221 = v213[(v214 + v215)];	// L391
                    int8_t v222 = v221 + v220;	// L392
                    v213[(v214 + v215)] = v222;	// L393
                  }
                }
                int8_t v223 = v213[(v214 + v215)];	// L396
                v198[v201][(v214 + v215)][(v202 - 9)][(v203 - 9)] = v223;	// L397
              }
            }
          }
        }
      }
    }
  }
  for (int v224 = 0; v224 < 1; v224 += 1) {	// L405
    for (int v225 = 0; v225 < 7; v225 += 1) {	// L406
      for (int v226 = 0; v226 < 7; v226 += 1) {	// L407
        for (int v227 = 0; v227 < 512; v227 += 1) {	// L408
          int8_t v228 = v198[0][v227][v225][v226];	// L409
          bool v229 = v228 > (int8_t)0.000000;	// L410
          int8_t v230 = v229 ? v228 : (int8_t)0.000000;	// L411
          v189[v224][v227][v225][v226] = v230;	// L412
        }
      }
    }
  }
  return ;	// L417
}

void main_graph_node9(
  int8_t v231[512][512][1][1],
  int8_t v232[1][512][14][14],
  int8_t v233[1][512][14][14]
) {	// L419
  #pragma HLS dataflow

  int8_t v234[1][512][14][14];	// L421
  #pragma HLS stream variable=v234 depth=10 type=fifo

  #pragma HLS bind_storage variable=v234 type=ram_t2p impl=bram

  int8_t v235[1][512][1][14];	// L422
  #pragma HLS bind_storage variable=v235 type=ram_2p impl=bram

  int8_t v236[1][512][1][1];	// L423
  #pragma HLS array_partition variable=v236 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v236 type=ram_2p impl=lutram

  for (int v237 = 0; v237 < 1; v237 += 1) {	// L424
    for (int v238 = 0; v238 < 14; v238 += 1) {	// L425
      for (int v239 = 0; v239 < 14; v239 += 1) {	// L426
        for (int v240 = 0; v240 < 512; v240 += 1) {	// L427
          int8_t v241 = v232[v237][v240][v238][v239];	// L428
          v235[v237][v240][0][v239] = v241;	// L429
        }
        if (v238 >= 0) {	// L431
          for (int v242 = 0; v242 < 512; v242 += 1) {	// L432
            for (int v243 = 0; v243 < 1; v243 += 1) {	// L433
              int8_t v244 = v235[v237][v242][v243][v239];	// L434
              v236[v237][v242][v243][0] = v244;	// L435
            }
          }
          if (v239 >= 0) {	// L438
            int8_t v245[512];	// L439
            #pragma HLS bind_storage variable=v245 type=ram_2p impl=bram

            for (int v246 = 0; v246 < 512; v246 += 1) {	// L440
              v245[v246] = (int8_t)0.000000;	// L441
              for (int v247 = 0; v247 < 16; v247 += 1) {	// L442
                #pragma HLS pipeline II=1
                for (int v248 = 0; v248 < 32; v248 += 1) {	// L443
                  for (int v249 = 0; v249 < 1; v249 += 1) {	// L444
                    for (int v250 = 0; v250 < 1; v250 += 1) {	// L445
                      int8_t v251 = v236[v237][(v248 + (v247 * 32))][v249][v250];	// L446
                      int8_t v252 = v231[v246][(v248 + (v247 * 32))][v249][v250];	// L447
                      int8_t v253 = v251 * v252;	// L448
                      int8_t v254 = v245[v246];	// L449
                      int8_t v255 = v254 + v253;	// L450
                      v245[v246] = v255;	// L451
                    }
                  }
                }
              }
              int8_t v256 = v245[v246];	// L456
              v234[v237][v246][v238][v239] = v256;	// L457
            }
          }
        }
      }
    }
  }
  for (int v257 = 0; v257 < 1; v257 += 1) {	// L464
    for (int v258 = 0; v258 < 14; v258 += 1) {	// L465
      for (int v259 = 0; v259 < 14; v259 += 1) {	// L466
        for (int v260 = 0; v260 < 512; v260 += 1) {	// L467
          int8_t v261 = v234[0][v260][v258][v259];	// L468
          bool v262 = v261 > (int8_t)0.000000;	// L469
          int8_t v263 = v262 ? v261 : (int8_t)0.000000;	// L470
          v233[v257][v260][v258][v259] = v263;	// L471
        }
      }
    }
  }
  return ;	// L476
}

void main_graph_node10(
  int8_t v264[1][512][14][14],
  int8_t v265[512][3][3],
  int8_t v266[1][512][14][14]
) {	// L478
  #pragma HLS dataflow

  int8_t v267[1][512][16][16];	// L480
  #pragma HLS stream variable=v267 depth=10 type=fifo

  #pragma HLS bind_storage variable=v267 type=ram_t2p impl=bram

  for (int v268 = 0; v268 < 1; v268 += 1) {	// L481
    for (int v269 = 0; v269 < 16; v269 += 1) {	// L482
      for (int v270 = 0; v270 < 16; v270 += 1) {	// L483
        for (int v271 = 0; v271 < 512; v271 += 1) {	// L484
          int8_t v272;	// L485
          v272 = (int8_t)0.000000;	// L486
          if (((-v269) + 13) >= 0 && ((-v270) + 13) >= 0) {	// L487
            int8_t v273 = v264[v268][v271][v269][v270];	// L488
            v272 = v273;	// L489
          }
          int8_t v274 = v272;	// L491
          v267[v268][v271][v269][v270] = v274;	// L492
        }
      }
    }
  }
  int8_t v275[1][512][14][14];	// L497
  #pragma HLS stream variable=v275 depth=10 type=fifo

  #pragma HLS bind_storage variable=v275 type=ram_t2p impl=bram

  int8_t v276[1][512][3][16];	// L498
  #pragma HLS array_partition variable=v276 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v276 type=ram_2p impl=bram

  int8_t v277[1][512][3][3];	// L499
  #pragma HLS array_partition variable=v277 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v277 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v277 type=ram_2p impl=lutram

  for (int v278 = 0; v278 < 1; v278 += 1) {	// L500
    for (int v279 = 0; v279 < 16; v279 += 1) {	// L501
      for (int v280 = 0; v280 < 16; v280 += 1) {	// L502
        for (int v281 = 0; v281 < 512; v281 += 1) {	// L503
          int8_t v282 = v276[v278][v281][1][v280];	// L504
          v276[v278][v281][0][v280] = v282;	// L505
          int8_t v283 = v276[v278][v281][2][v280];	// L506
          v276[v278][v281][1][v280] = v283;	// L507
          int8_t v284 = v267[v278][v281][v279][v280];	// L508
          v276[v278][v281][2][v280] = v284;	// L509
        }
        if ((v279 - 2) >= 0) {	// L511
          for (int v285 = 0; v285 < 512; v285 += 1) {	// L512
            for (int v286 = 0; v286 < 3; v286 += 1) {	// L513
              int8_t v287 = v277[v278][v285][v286][1];	// L514
              v277[v278][v285][v286][0] = v287;	// L515
              int8_t v288 = v277[v278][v285][v286][2];	// L516
              v277[v278][v285][v286][1] = v288;	// L517
              int8_t v289 = v276[v278][v285][v286][v280];	// L518
              v277[v278][v285][v286][2] = v289;	// L519
            }
          }
          if ((v280 - 2) >= 0) {	// L522
            int8_t v290[512];	// L523
            #pragma HLS bind_storage variable=v290 type=ram_2p impl=bram

            for (int v291 = 0; v291 < 512; v291 += 1) {	// L524
              #pragma HLS pipeline II=1
              for (int v292 = 0; v292 < 1; v292 += 1) {	// L525
                v290[(v291 + v292)] = (int8_t)0.000000;	// L526
                for (int v293 = 0; v293 < 3; v293 += 1) {	// L527
                  for (int v294 = 0; v294 < 3; v294 += 1) {	// L528
                    int8_t v295 = v277[v278][(v291 + v292)][v293][v294];	// L529
                    int8_t v296 = v265[(v291 + v292)][v293][v294];	// L530
                    int8_t v297 = v295 * v296;	// L531
                    int8_t v298 = v290[(v291 + v292)];	// L532
                    int8_t v299 = v298 + v297;	// L533
                    v290[(v291 + v292)] = v299;	// L534
                  }
                }
                int8_t v300 = v290[(v291 + v292)];	// L537
                v275[v278][(v291 + v292)][(v279 - 2)][(v280 - 2)] = v300;	// L538
              }
            }
          }
        }
      }
    }
  }
  for (int v301 = 0; v301 < 1; v301 += 1) {	// L546
    for (int v302 = 0; v302 < 14; v302 += 1) {	// L547
      for (int v303 = 0; v303 < 14; v303 += 1) {	// L548
        for (int v304 = 0; v304 < 512; v304 += 1) {	// L549
          int8_t v305 = v275[0][v304][v302][v303];	// L550
          bool v306 = v305 > (int8_t)0.000000;	// L551
          int8_t v307 = v306 ? v305 : (int8_t)0.000000;	// L552
          v266[v301][v304][v302][v303] = v307;	// L553
        }
      }
    }
  }
  return ;	// L558
}

void main_graph_node11(
  int8_t v308[1][512][14][14],
  int8_t v309[512][512][1][1],
  int8_t v310[1][512][14][14]
) {	// L560
  #pragma HLS dataflow

  int8_t v311[1][512][14][14];	// L562
  #pragma HLS stream variable=v311 depth=10 type=fifo

  #pragma HLS bind_storage variable=v311 type=ram_t2p impl=bram

  int8_t v312[1][512][1][14];	// L563
  #pragma HLS bind_storage variable=v312 type=ram_2p impl=bram

  int8_t v313[1][512][1][1];	// L564
  #pragma HLS array_partition variable=v313 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v313 type=ram_2p impl=lutram

  for (int v314 = 0; v314 < 1; v314 += 1) {	// L565
    for (int v315 = 0; v315 < 14; v315 += 1) {	// L566
      for (int v316 = 0; v316 < 14; v316 += 1) {	// L567
        for (int v317 = 0; v317 < 512; v317 += 1) {	// L568
          int8_t v318 = v308[v314][v317][v315][v316];	// L569
          v312[v314][v317][0][v316] = v318;	// L570
        }
        if (v315 >= 0) {	// L572
          for (int v319 = 0; v319 < 512; v319 += 1) {	// L573
            for (int v320 = 0; v320 < 1; v320 += 1) {	// L574
              int8_t v321 = v312[v314][v319][v320][v316];	// L575
              v313[v314][v319][v320][0] = v321;	// L576
            }
          }
          if (v316 >= 0) {	// L579
            int8_t v322[512];	// L580
            #pragma HLS bind_storage variable=v322 type=ram_2p impl=bram

            for (int v323 = 0; v323 < 512; v323 += 1) {	// L581
              v322[v323] = (int8_t)0.000000;	// L582
              for (int v324 = 0; v324 < 16; v324 += 1) {	// L583
                #pragma HLS pipeline II=1
                for (int v325 = 0; v325 < 32; v325 += 1) {	// L584
                  for (int v326 = 0; v326 < 1; v326 += 1) {	// L585
                    for (int v327 = 0; v327 < 1; v327 += 1) {	// L586
                      int8_t v328 = v313[v314][(v325 + (v324 * 32))][v326][v327];	// L587
                      int8_t v329 = v309[v323][(v325 + (v324 * 32))][v326][v327];	// L588
                      int8_t v330 = v328 * v329;	// L589
                      int8_t v331 = v322[v323];	// L590
                      int8_t v332 = v331 + v330;	// L591
                      v322[v323] = v332;	// L592
                    }
                  }
                }
              }
              int8_t v333 = v322[v323];	// L597
              v311[v314][v323][v315][v316] = v333;	// L598
            }
          }
        }
      }
    }
  }
  for (int v334 = 0; v334 < 1; v334 += 1) {	// L605
    for (int v335 = 0; v335 < 14; v335 += 1) {	// L606
      for (int v336 = 0; v336 < 14; v336 += 1) {	// L607
        for (int v337 = 0; v337 < 512; v337 += 1) {	// L608
          int8_t v338 = v311[0][v337][v335][v336];	// L609
          bool v339 = v338 > (int8_t)0.000000;	// L610
          int8_t v340 = v339 ? v338 : (int8_t)0.000000;	// L611
          v310[v334][v337][v335][v336] = v340;	// L612
        }
      }
    }
  }
  return ;	// L617
}

void main_graph_node12(
  int8_t v341[1][512][14][14],
  int8_t v342[512][3][3],
  int8_t v343[1][512][14][14]
) {	// L619
  #pragma HLS dataflow

  int8_t v344[1][512][16][16];	// L621
  #pragma HLS stream variable=v344 depth=10 type=fifo

  #pragma HLS bind_storage variable=v344 type=ram_t2p impl=bram

  for (int v345 = 0; v345 < 1; v345 += 1) {	// L622
    for (int v346 = 0; v346 < 16; v346 += 1) {	// L623
      for (int v347 = 0; v347 < 16; v347 += 1) {	// L624
        for (int v348 = 0; v348 < 512; v348 += 1) {	// L625
          int8_t v349;	// L626
          v349 = (int8_t)0.000000;	// L627
          if (((-v346) + 13) >= 0 && ((-v347) + 13) >= 0) {	// L628
            int8_t v350 = v341[v345][v348][v346][v347];	// L629
            v349 = v350;	// L630
          }
          int8_t v351 = v349;	// L632
          v344[v345][v348][v346][v347] = v351;	// L633
        }
      }
    }
  }
  int8_t v352[1][512][14][14];	// L638
  #pragma HLS stream variable=v352 depth=10 type=fifo

  #pragma HLS bind_storage variable=v352 type=ram_t2p impl=bram

  int8_t v353[1][512][3][16];	// L639
  #pragma HLS array_partition variable=v353 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v353 type=ram_2p impl=bram

  int8_t v354[1][512][3][3];	// L640
  #pragma HLS array_partition variable=v354 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v354 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v354 type=ram_2p impl=lutram

  for (int v355 = 0; v355 < 1; v355 += 1) {	// L641
    for (int v356 = 0; v356 < 16; v356 += 1) {	// L642
      for (int v357 = 0; v357 < 16; v357 += 1) {	// L643
        for (int v358 = 0; v358 < 512; v358 += 1) {	// L644
          int8_t v359 = v353[v355][v358][1][v357];	// L645
          v353[v355][v358][0][v357] = v359;	// L646
          int8_t v360 = v353[v355][v358][2][v357];	// L647
          v353[v355][v358][1][v357] = v360;	// L648
          int8_t v361 = v344[v355][v358][v356][v357];	// L649
          v353[v355][v358][2][v357] = v361;	// L650
        }
        if ((v356 - 2) >= 0) {	// L652
          for (int v362 = 0; v362 < 512; v362 += 1) {	// L653
            for (int v363 = 0; v363 < 3; v363 += 1) {	// L654
              int8_t v364 = v354[v355][v362][v363][1];	// L655
              v354[v355][v362][v363][0] = v364;	// L656
              int8_t v365 = v354[v355][v362][v363][2];	// L657
              v354[v355][v362][v363][1] = v365;	// L658
              int8_t v366 = v353[v355][v362][v363][v357];	// L659
              v354[v355][v362][v363][2] = v366;	// L660
            }
          }
          if ((v357 - 2) >= 0) {	// L663
            int8_t v367[512];	// L664
            #pragma HLS bind_storage variable=v367 type=ram_2p impl=bram

            for (int v368 = 0; v368 < 512; v368 += 1) {	// L665
              #pragma HLS pipeline II=1
              for (int v369 = 0; v369 < 1; v369 += 1) {	// L666
                v367[(v368 + v369)] = (int8_t)0.000000;	// L667
                for (int v370 = 0; v370 < 3; v370 += 1) {	// L668
                  for (int v371 = 0; v371 < 3; v371 += 1) {	// L669
                    int8_t v372 = v354[v355][(v368 + v369)][v370][v371];	// L670
                    int8_t v373 = v342[(v368 + v369)][v370][v371];	// L671
                    int8_t v374 = v372 * v373;	// L672
                    int8_t v375 = v367[(v368 + v369)];	// L673
                    int8_t v376 = v375 + v374;	// L674
                    v367[(v368 + v369)] = v376;	// L675
                  }
                }
                int8_t v377 = v367[(v368 + v369)];	// L678
                v352[v355][(v368 + v369)][(v356 - 2)][(v357 - 2)] = v377;	// L679
              }
            }
          }
        }
      }
    }
  }
  for (int v378 = 0; v378 < 1; v378 += 1) {	// L687
    for (int v379 = 0; v379 < 14; v379 += 1) {	// L688
      for (int v380 = 0; v380 < 14; v380 += 1) {	// L689
        for (int v381 = 0; v381 < 512; v381 += 1) {	// L690
          int8_t v382 = v352[0][v381][v379][v380];	// L691
          bool v383 = v382 > (int8_t)0.000000;	// L692
          int8_t v384 = v383 ? v382 : (int8_t)0.000000;	// L693
          v343[v378][v381][v379][v380] = v384;	// L694
        }
      }
    }
  }
  return ;	// L699
}

void main_graph_node13(
  int8_t v385[1][512][14][14],
  int8_t v386[512][512][1][1],
  int8_t v387[1][512][14][14]
) {	// L701
  #pragma HLS dataflow

  int8_t v388[1][512][14][14];	// L703
  #pragma HLS stream variable=v388 depth=10 type=fifo

  #pragma HLS bind_storage variable=v388 type=ram_t2p impl=bram

  int8_t v389[1][512][1][14];	// L704
  #pragma HLS bind_storage variable=v389 type=ram_2p impl=bram

  int8_t v390[1][512][1][1];	// L705
  #pragma HLS array_partition variable=v390 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v390 type=ram_2p impl=lutram

  for (int v391 = 0; v391 < 1; v391 += 1) {	// L706
    for (int v392 = 0; v392 < 14; v392 += 1) {	// L707
      for (int v393 = 0; v393 < 14; v393 += 1) {	// L708
        for (int v394 = 0; v394 < 512; v394 += 1) {	// L709
          int8_t v395 = v385[v391][v394][v392][v393];	// L710
          v389[v391][v394][0][v393] = v395;	// L711
        }
        if (v392 >= 0) {	// L713
          for (int v396 = 0; v396 < 512; v396 += 1) {	// L714
            for (int v397 = 0; v397 < 1; v397 += 1) {	// L715
              int8_t v398 = v389[v391][v396][v397][v393];	// L716
              v390[v391][v396][v397][0] = v398;	// L717
            }
          }
          if (v393 >= 0) {	// L720
            int8_t v399[512];	// L721
            #pragma HLS bind_storage variable=v399 type=ram_2p impl=bram

            for (int v400 = 0; v400 < 512; v400 += 1) {	// L722
              v399[v400] = (int8_t)0.000000;	// L723
              for (int v401 = 0; v401 < 16; v401 += 1) {	// L724
                #pragma HLS pipeline II=1
                for (int v402 = 0; v402 < 32; v402 += 1) {	// L725
                  for (int v403 = 0; v403 < 1; v403 += 1) {	// L726
                    for (int v404 = 0; v404 < 1; v404 += 1) {	// L727
                      int8_t v405 = v390[v391][(v402 + (v401 * 32))][v403][v404];	// L728
                      int8_t v406 = v386[v400][(v402 + (v401 * 32))][v403][v404];	// L729
                      int8_t v407 = v405 * v406;	// L730
                      int8_t v408 = v399[v400];	// L731
                      int8_t v409 = v408 + v407;	// L732
                      v399[v400] = v409;	// L733
                    }
                  }
                }
              }
              int8_t v410 = v399[v400];	// L738
              v388[v391][v400][v392][v393] = v410;	// L739
            }
          }
        }
      }
    }
  }
  for (int v411 = 0; v411 < 1; v411 += 1) {	// L746
    for (int v412 = 0; v412 < 14; v412 += 1) {	// L747
      for (int v413 = 0; v413 < 14; v413 += 1) {	// L748
        for (int v414 = 0; v414 < 512; v414 += 1) {	// L749
          int8_t v415 = v388[0][v414][v412][v413];	// L750
          bool v416 = v415 > (int8_t)0.000000;	// L751
          int8_t v417 = v416 ? v415 : (int8_t)0.000000;	// L752
          v387[v411][v414][v412][v413] = v417;	// L753
        }
      }
    }
  }
  return ;	// L758
}

void main_graph_node14(
  int8_t v418[512][3][3],
  int8_t v419[1][512][14][14],
  int8_t v420[1][512][14][14]
) {	// L760
  #pragma HLS dataflow

  int8_t v421[1][512][16][16];	// L762
  #pragma HLS stream variable=v421 depth=10 type=fifo

  #pragma HLS bind_storage variable=v421 type=ram_t2p impl=bram

  for (int v422 = 0; v422 < 1; v422 += 1) {	// L763
    for (int v423 = 0; v423 < 16; v423 += 1) {	// L764
      for (int v424 = 0; v424 < 16; v424 += 1) {	// L765
        for (int v425 = 0; v425 < 512; v425 += 1) {	// L766
          int8_t v426;	// L767
          v426 = (int8_t)0.000000;	// L768
          if (((-v423) + 13) >= 0 && ((-v424) + 13) >= 0) {	// L769
            int8_t v427 = v419[v422][v425][v423][v424];	// L770
            v426 = v427;	// L771
          }
          int8_t v428 = v426;	// L773
          v421[v422][v425][v423][v424] = v428;	// L774
        }
      }
    }
  }
  int8_t v429[1][512][14][14];	// L779
  #pragma HLS stream variable=v429 depth=10 type=fifo

  #pragma HLS bind_storage variable=v429 type=ram_t2p impl=bram

  int8_t v430[1][512][3][16];	// L780
  #pragma HLS array_partition variable=v430 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v430 type=ram_2p impl=bram

  int8_t v431[1][512][3][3];	// L781
  #pragma HLS array_partition variable=v431 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v431 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v431 type=ram_2p impl=lutram

  for (int v432 = 0; v432 < 1; v432 += 1) {	// L782
    for (int v433 = 0; v433 < 16; v433 += 1) {	// L783
      for (int v434 = 0; v434 < 16; v434 += 1) {	// L784
        for (int v435 = 0; v435 < 512; v435 += 1) {	// L785
          int8_t v436 = v430[v432][v435][1][v434];	// L786
          v430[v432][v435][0][v434] = v436;	// L787
          int8_t v437 = v430[v432][v435][2][v434];	// L788
          v430[v432][v435][1][v434] = v437;	// L789
          int8_t v438 = v421[v432][v435][v433][v434];	// L790
          v430[v432][v435][2][v434] = v438;	// L791
        }
        if ((v433 - 2) >= 0) {	// L793
          for (int v439 = 0; v439 < 512; v439 += 1) {	// L794
            for (int v440 = 0; v440 < 3; v440 += 1) {	// L795
              int8_t v441 = v431[v432][v439][v440][1];	// L796
              v431[v432][v439][v440][0] = v441;	// L797
              int8_t v442 = v431[v432][v439][v440][2];	// L798
              v431[v432][v439][v440][1] = v442;	// L799
              int8_t v443 = v430[v432][v439][v440][v434];	// L800
              v431[v432][v439][v440][2] = v443;	// L801
            }
          }
          if ((v434 - 2) >= 0) {	// L804
            int8_t v444[512];	// L805
            #pragma HLS bind_storage variable=v444 type=ram_2p impl=bram

            for (int v445 = 0; v445 < 512; v445 += 1) {	// L806
              #pragma HLS pipeline II=1
              for (int v446 = 0; v446 < 1; v446 += 1) {	// L807
                v444[(v445 + v446)] = (int8_t)0.000000;	// L808
                for (int v447 = 0; v447 < 3; v447 += 1) {	// L809
                  for (int v448 = 0; v448 < 3; v448 += 1) {	// L810
                    int8_t v449 = v431[v432][(v445 + v446)][v447][v448];	// L811
                    int8_t v450 = v418[(v445 + v446)][v447][v448];	// L812
                    int8_t v451 = v449 * v450;	// L813
                    int8_t v452 = v444[(v445 + v446)];	// L814
                    int8_t v453 = v452 + v451;	// L815
                    v444[(v445 + v446)] = v453;	// L816
                  }
                }
                int8_t v454 = v444[(v445 + v446)];	// L819
                v429[v432][(v445 + v446)][(v433 - 2)][(v434 - 2)] = v454;	// L820
              }
            }
          }
        }
      }
    }
  }
  for (int v455 = 0; v455 < 1; v455 += 1) {	// L828
    for (int v456 = 0; v456 < 14; v456 += 1) {	// L829
      for (int v457 = 0; v457 < 14; v457 += 1) {	// L830
        for (int v458 = 0; v458 < 512; v458 += 1) {	// L831
          int8_t v459 = v429[0][v458][v456][v457];	// L832
          bool v460 = v459 > (int8_t)0.000000;	// L833
          int8_t v461 = v460 ? v459 : (int8_t)0.000000;	// L834
          v420[v455][v458][v456][v457] = v461;	// L835
        }
      }
    }
  }
  return ;	// L840
}

void main_graph_node15(
  int8_t v462[512][512][1][1],
  int8_t v463[1][512][14][14],
  int8_t v464[1][512][14][14]
) {	// L842
  #pragma HLS dataflow

  int8_t v465[1][512][14][14];	// L844
  #pragma HLS stream variable=v465 depth=10 type=fifo

  #pragma HLS bind_storage variable=v465 type=ram_t2p impl=bram

  int8_t v466[1][512][1][14];	// L845
  #pragma HLS bind_storage variable=v466 type=ram_2p impl=bram

  int8_t v467[1][512][1][1];	// L846
  #pragma HLS array_partition variable=v467 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v467 type=ram_2p impl=lutram

  for (int v468 = 0; v468 < 1; v468 += 1) {	// L847
    for (int v469 = 0; v469 < 14; v469 += 1) {	// L848
      for (int v470 = 0; v470 < 14; v470 += 1) {	// L849
        for (int v471 = 0; v471 < 512; v471 += 1) {	// L850
          int8_t v472 = v463[v468][v471][v469][v470];	// L851
          v466[v468][v471][0][v470] = v472;	// L852
        }
        if (v469 >= 0) {	// L854
          for (int v473 = 0; v473 < 512; v473 += 1) {	// L855
            for (int v474 = 0; v474 < 1; v474 += 1) {	// L856
              int8_t v475 = v466[v468][v473][v474][v470];	// L857
              v467[v468][v473][v474][0] = v475;	// L858
            }
          }
          if (v470 >= 0) {	// L861
            int8_t v476[512];	// L862
            #pragma HLS bind_storage variable=v476 type=ram_2p impl=bram

            for (int v477 = 0; v477 < 512; v477 += 1) {	// L863
              v476[v477] = (int8_t)0.000000;	// L864
              for (int v478 = 0; v478 < 16; v478 += 1) {	// L865
                #pragma HLS pipeline II=1
                for (int v479 = 0; v479 < 32; v479 += 1) {	// L866
                  for (int v480 = 0; v480 < 1; v480 += 1) {	// L867
                    for (int v481 = 0; v481 < 1; v481 += 1) {	// L868
                      int8_t v482 = v467[v468][(v479 + (v478 * 32))][v480][v481];	// L869
                      int8_t v483 = v462[v477][(v479 + (v478 * 32))][v480][v481];	// L870
                      int8_t v484 = v482 * v483;	// L871
                      int8_t v485 = v476[v477];	// L872
                      int8_t v486 = v485 + v484;	// L873
                      v476[v477] = v486;	// L874
                    }
                  }
                }
              }
              int8_t v487 = v476[v477];	// L879
              v465[v468][v477][v469][v470] = v487;	// L880
            }
          }
        }
      }
    }
  }
  for (int v488 = 0; v488 < 1; v488 += 1) {	// L887
    for (int v489 = 0; v489 < 14; v489 += 1) {	// L888
      for (int v490 = 0; v490 < 14; v490 += 1) {	// L889
        for (int v491 = 0; v491 < 512; v491 += 1) {	// L890
          int8_t v492 = v465[0][v491][v489][v490];	// L891
          bool v493 = v492 > (int8_t)0.000000;	// L892
          int8_t v494 = v493 ? v492 : (int8_t)0.000000;	// L893
          v464[v488][v491][v489][v490] = v494;	// L894
        }
      }
    }
  }
  return ;	// L899
}

void main_graph_node16(
  int8_t v495[1][512][14][14],
  int8_t v496[512][3][3],
  int8_t v497[1][512][14][14]
) {	// L901
  #pragma HLS dataflow

  int8_t v498[1][512][16][16];	// L903
  #pragma HLS stream variable=v498 depth=10 type=fifo

  #pragma HLS bind_storage variable=v498 type=ram_t2p impl=bram

  for (int v499 = 0; v499 < 1; v499 += 1) {	// L904
    for (int v500 = 0; v500 < 16; v500 += 1) {	// L905
      for (int v501 = 0; v501 < 16; v501 += 1) {	// L906
        for (int v502 = 0; v502 < 512; v502 += 1) {	// L907
          int8_t v503;	// L908
          v503 = (int8_t)0.000000;	// L909
          if (((-v500) + 13) >= 0 && ((-v501) + 13) >= 0) {	// L910
            int8_t v504 = v495[v499][v502][v500][v501];	// L911
            v503 = v504;	// L912
          }
          int8_t v505 = v503;	// L914
          v498[v499][v502][v500][v501] = v505;	// L915
        }
      }
    }
  }
  int8_t v506[1][512][14][14];	// L920
  #pragma HLS stream variable=v506 depth=10 type=fifo

  #pragma HLS bind_storage variable=v506 type=ram_t2p impl=bram

  int8_t v507[1][512][3][16];	// L921
  #pragma HLS array_partition variable=v507 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v507 type=ram_2p impl=bram

  int8_t v508[1][512][3][3];	// L922
  #pragma HLS array_partition variable=v508 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v508 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v508 type=ram_2p impl=lutram

  for (int v509 = 0; v509 < 1; v509 += 1) {	// L923
    for (int v510 = 0; v510 < 16; v510 += 1) {	// L924
      for (int v511 = 0; v511 < 16; v511 += 1) {	// L925
        for (int v512 = 0; v512 < 512; v512 += 1) {	// L926
          int8_t v513 = v507[v509][v512][1][v511];	// L927
          v507[v509][v512][0][v511] = v513;	// L928
          int8_t v514 = v507[v509][v512][2][v511];	// L929
          v507[v509][v512][1][v511] = v514;	// L930
          int8_t v515 = v498[v509][v512][v510][v511];	// L931
          v507[v509][v512][2][v511] = v515;	// L932
        }
        if ((v510 - 2) >= 0) {	// L934
          for (int v516 = 0; v516 < 512; v516 += 1) {	// L935
            for (int v517 = 0; v517 < 3; v517 += 1) {	// L936
              int8_t v518 = v508[v509][v516][v517][1];	// L937
              v508[v509][v516][v517][0] = v518;	// L938
              int8_t v519 = v508[v509][v516][v517][2];	// L939
              v508[v509][v516][v517][1] = v519;	// L940
              int8_t v520 = v507[v509][v516][v517][v511];	// L941
              v508[v509][v516][v517][2] = v520;	// L942
            }
          }
          if ((v511 - 2) >= 0) {	// L945
            int8_t v521[512];	// L946
            #pragma HLS bind_storage variable=v521 type=ram_2p impl=bram

            for (int v522 = 0; v522 < 512; v522 += 1) {	// L947
              #pragma HLS pipeline II=1
              for (int v523 = 0; v523 < 1; v523 += 1) {	// L948
                v521[(v522 + v523)] = (int8_t)0.000000;	// L949
                for (int v524 = 0; v524 < 3; v524 += 1) {	// L950
                  for (int v525 = 0; v525 < 3; v525 += 1) {	// L951
                    int8_t v526 = v508[v509][(v522 + v523)][v524][v525];	// L952
                    int8_t v527 = v496[(v522 + v523)][v524][v525];	// L953
                    int8_t v528 = v526 * v527;	// L954
                    int8_t v529 = v521[(v522 + v523)];	// L955
                    int8_t v530 = v529 + v528;	// L956
                    v521[(v522 + v523)] = v530;	// L957
                  }
                }
                int8_t v531 = v521[(v522 + v523)];	// L960
                v506[v509][(v522 + v523)][(v510 - 2)][(v511 - 2)] = v531;	// L961
              }
            }
          }
        }
      }
    }
  }
  for (int v532 = 0; v532 < 1; v532 += 1) {	// L969
    for (int v533 = 0; v533 < 14; v533 += 1) {	// L970
      for (int v534 = 0; v534 < 14; v534 += 1) {	// L971
        for (int v535 = 0; v535 < 512; v535 += 1) {	// L972
          int8_t v536 = v506[0][v535][v533][v534];	// L973
          bool v537 = v536 > (int8_t)0.000000;	// L974
          int8_t v538 = v537 ? v536 : (int8_t)0.000000;	// L975
          v497[v532][v535][v533][v534] = v538;	// L976
        }
      }
    }
  }
  return ;	// L981
}

void main_graph_node17(
  int8_t v539[512][512][1][1],
  int8_t v540[1][512][14][14],
  int8_t v541[1][512][14][14]
) {	// L983
  #pragma HLS dataflow

  int8_t v542[1][512][14][14];	// L985
  #pragma HLS stream variable=v542 depth=10 type=fifo

  #pragma HLS bind_storage variable=v542 type=ram_t2p impl=bram

  int8_t v543[1][512][1][14];	// L986
  #pragma HLS bind_storage variable=v543 type=ram_2p impl=bram

  int8_t v544[1][512][1][1];	// L987
  #pragma HLS array_partition variable=v544 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v544 type=ram_2p impl=lutram

  for (int v545 = 0; v545 < 1; v545 += 1) {	// L988
    for (int v546 = 0; v546 < 14; v546 += 1) {	// L989
      for (int v547 = 0; v547 < 14; v547 += 1) {	// L990
        for (int v548 = 0; v548 < 512; v548 += 1) {	// L991
          int8_t v549 = v540[v545][v548][v546][v547];	// L992
          v543[v545][v548][0][v547] = v549;	// L993
        }
        if (v546 >= 0) {	// L995
          for (int v550 = 0; v550 < 512; v550 += 1) {	// L996
            for (int v551 = 0; v551 < 1; v551 += 1) {	// L997
              int8_t v552 = v543[v545][v550][v551][v547];	// L998
              v544[v545][v550][v551][0] = v552;	// L999
            }
          }
          if (v547 >= 0) {	// L1002
            int8_t v553[512];	// L1003
            #pragma HLS bind_storage variable=v553 type=ram_2p impl=bram

            for (int v554 = 0; v554 < 512; v554 += 1) {	// L1004
              v553[v554] = (int8_t)0.000000;	// L1005
              for (int v555 = 0; v555 < 16; v555 += 1) {	// L1006
                #pragma HLS pipeline II=1
                for (int v556 = 0; v556 < 32; v556 += 1) {	// L1007
                  for (int v557 = 0; v557 < 1; v557 += 1) {	// L1008
                    for (int v558 = 0; v558 < 1; v558 += 1) {	// L1009
                      int8_t v559 = v544[v545][(v556 + (v555 * 32))][v557][v558];	// L1010
                      int8_t v560 = v539[v554][(v556 + (v555 * 32))][v557][v558];	// L1011
                      int8_t v561 = v559 * v560;	// L1012
                      int8_t v562 = v553[v554];	// L1013
                      int8_t v563 = v562 + v561;	// L1014
                      v553[v554] = v563;	// L1015
                    }
                  }
                }
              }
              int8_t v564 = v553[v554];	// L1020
              v542[v545][v554][v546][v547] = v564;	// L1021
            }
          }
        }
      }
    }
  }
  for (int v565 = 0; v565 < 1; v565 += 1) {	// L1028
    for (int v566 = 0; v566 < 14; v566 += 1) {	// L1029
      for (int v567 = 0; v567 < 14; v567 += 1) {	// L1030
        for (int v568 = 0; v568 < 512; v568 += 1) {	// L1031
          int8_t v569 = v542[0][v568][v566][v567];	// L1032
          bool v570 = v569 > (int8_t)0.000000;	// L1033
          int8_t v571 = v570 ? v569 : (int8_t)0.000000;	// L1034
          v541[v565][v568][v566][v567] = v571;	// L1035
        }
      }
    }
  }
  return ;	// L1040
}

void main_graph_node18(
  int8_t v572[1][512][14][14],
  int8_t v573[512][3][3],
  int8_t v574[1][512][14][14]
) {	// L1042
  #pragma HLS dataflow

  int8_t v575[1][512][16][16];	// L1044
  #pragma HLS stream variable=v575 depth=10 type=fifo

  #pragma HLS bind_storage variable=v575 type=ram_t2p impl=bram

  for (int v576 = 0; v576 < 1; v576 += 1) {	// L1045
    for (int v577 = 0; v577 < 16; v577 += 1) {	// L1046
      for (int v578 = 0; v578 < 16; v578 += 1) {	// L1047
        for (int v579 = 0; v579 < 512; v579 += 1) {	// L1048
          int8_t v580;	// L1049
          v580 = (int8_t)0.000000;	// L1050
          if (((-v577) + 13) >= 0 && ((-v578) + 13) >= 0) {	// L1051
            int8_t v581 = v572[v576][v579][v577][v578];	// L1052
            v580 = v581;	// L1053
          }
          int8_t v582 = v580;	// L1055
          v575[v576][v579][v577][v578] = v582;	// L1056
        }
      }
    }
  }
  int8_t v583[1][512][14][14];	// L1061
  #pragma HLS stream variable=v583 depth=10 type=fifo

  #pragma HLS bind_storage variable=v583 type=ram_t2p impl=bram

  int8_t v584[1][512][3][16];	// L1062
  #pragma HLS array_partition variable=v584 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v584 type=ram_2p impl=bram

  int8_t v585[1][512][3][3];	// L1063
  #pragma HLS array_partition variable=v585 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v585 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v585 type=ram_2p impl=lutram

  for (int v586 = 0; v586 < 1; v586 += 1) {	// L1064
    for (int v587 = 0; v587 < 16; v587 += 1) {	// L1065
      for (int v588 = 0; v588 < 16; v588 += 1) {	// L1066
        for (int v589 = 0; v589 < 512; v589 += 1) {	// L1067
          int8_t v590 = v584[v586][v589][1][v588];	// L1068
          v584[v586][v589][0][v588] = v590;	// L1069
          int8_t v591 = v584[v586][v589][2][v588];	// L1070
          v584[v586][v589][1][v588] = v591;	// L1071
          int8_t v592 = v575[v586][v589][v587][v588];	// L1072
          v584[v586][v589][2][v588] = v592;	// L1073
        }
        if ((v587 - 2) >= 0) {	// L1075
          for (int v593 = 0; v593 < 512; v593 += 1) {	// L1076
            for (int v594 = 0; v594 < 3; v594 += 1) {	// L1077
              int8_t v595 = v585[v586][v593][v594][1];	// L1078
              v585[v586][v593][v594][0] = v595;	// L1079
              int8_t v596 = v585[v586][v593][v594][2];	// L1080
              v585[v586][v593][v594][1] = v596;	// L1081
              int8_t v597 = v584[v586][v593][v594][v588];	// L1082
              v585[v586][v593][v594][2] = v597;	// L1083
            }
          }
          if ((v588 - 2) >= 0) {	// L1086
            int8_t v598[512];	// L1087
            #pragma HLS bind_storage variable=v598 type=ram_2p impl=bram

            for (int v599 = 0; v599 < 512; v599 += 1) {	// L1088
              #pragma HLS pipeline II=1
              for (int v600 = 0; v600 < 1; v600 += 1) {	// L1089
                v598[(v599 + v600)] = (int8_t)0.000000;	// L1090
                for (int v601 = 0; v601 < 3; v601 += 1) {	// L1091
                  for (int v602 = 0; v602 < 3; v602 += 1) {	// L1092
                    int8_t v603 = v585[v586][(v599 + v600)][v601][v602];	// L1093
                    int8_t v604 = v573[(v599 + v600)][v601][v602];	// L1094
                    int8_t v605 = v603 * v604;	// L1095
                    int8_t v606 = v598[(v599 + v600)];	// L1096
                    int8_t v607 = v606 + v605;	// L1097
                    v598[(v599 + v600)] = v607;	// L1098
                  }
                }
                int8_t v608 = v598[(v599 + v600)];	// L1101
                v583[v586][(v599 + v600)][(v587 - 2)][(v588 - 2)] = v608;	// L1102
              }
            }
          }
        }
      }
    }
  }
  for (int v609 = 0; v609 < 1; v609 += 1) {	// L1110
    for (int v610 = 0; v610 < 14; v610 += 1) {	// L1111
      for (int v611 = 0; v611 < 14; v611 += 1) {	// L1112
        for (int v612 = 0; v612 < 512; v612 += 1) {	// L1113
          int8_t v613 = v583[0][v612][v610][v611];	// L1114
          bool v614 = v613 > (int8_t)0.000000;	// L1115
          int8_t v615 = v614 ? v613 : (int8_t)0.000000;	// L1116
          v574[v609][v612][v610][v611] = v615;	// L1117
        }
      }
    }
  }
  return ;	// L1122
}

void main_graph_node19(
  int8_t v616[512][256][1][1],
  int8_t v617[1][256][14][14],
  int8_t v618[1][512][14][14]
) {	// L1124
  #pragma HLS dataflow

  int8_t v619[1][512][14][14];	// L1126
  #pragma HLS stream variable=v619 depth=10 type=fifo

  #pragma HLS bind_storage variable=v619 type=ram_t2p impl=bram

  int8_t v620[1][256][1][14];	// L1127
  #pragma HLS bind_storage variable=v620 type=ram_2p impl=bram

  int8_t v621[1][256][1][1];	// L1128
  #pragma HLS array_partition variable=v621 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v621 type=ram_2p impl=lutram

  for (int v622 = 0; v622 < 1; v622 += 1) {	// L1129
    for (int v623 = 0; v623 < 14; v623 += 1) {	// L1130
      for (int v624 = 0; v624 < 14; v624 += 1) {	// L1131
        for (int v625 = 0; v625 < 256; v625 += 1) {	// L1132
          int8_t v626 = v617[v622][v625][v623][v624];	// L1133
          v620[v622][v625][0][v624] = v626;	// L1134
        }
        if (v623 >= 0) {	// L1136
          for (int v627 = 0; v627 < 256; v627 += 1) {	// L1137
            for (int v628 = 0; v628 < 1; v628 += 1) {	// L1138
              int8_t v629 = v620[v622][v627][v628][v624];	// L1139
              v621[v622][v627][v628][0] = v629;	// L1140
            }
          }
          if (v624 >= 0) {	// L1143
            int8_t v630[512];	// L1144
            #pragma HLS bind_storage variable=v630 type=ram_2p impl=bram

            for (int v631 = 0; v631 < 512; v631 += 1) {	// L1145
              v630[v631] = (int8_t)0.000000;	// L1146
              for (int v632 = 0; v632 < 16; v632 += 1) {	// L1147
                #pragma HLS pipeline II=1
                for (int v633 = 0; v633 < 16; v633 += 1) {	// L1148
                  for (int v634 = 0; v634 < 1; v634 += 1) {	// L1149
                    for (int v635 = 0; v635 < 1; v635 += 1) {	// L1150
                      int8_t v636 = v621[v622][(v633 + (v632 * 16))][v634][v635];	// L1151
                      int8_t v637 = v616[v631][(v633 + (v632 * 16))][v634][v635];	// L1152
                      int8_t v638 = v636 * v637;	// L1153
                      int8_t v639 = v630[v631];	// L1154
                      int8_t v640 = v639 + v638;	// L1155
                      v630[v631] = v640;	// L1156
                    }
                  }
                }
              }
              int8_t v641 = v630[v631];	// L1161
              v619[v622][v631][v623][v624] = v641;	// L1162
            }
          }
        }
      }
    }
  }
  for (int v642 = 0; v642 < 1; v642 += 1) {	// L1169
    for (int v643 = 0; v643 < 14; v643 += 1) {	// L1170
      for (int v644 = 0; v644 < 14; v644 += 1) {	// L1171
        for (int v645 = 0; v645 < 512; v645 += 1) {	// L1172
          int8_t v646 = v619[0][v645][v643][v644];	// L1173
          bool v647 = v646 > (int8_t)0.000000;	// L1174
          int8_t v648 = v647 ? v646 : (int8_t)0.000000;	// L1175
          v618[v642][v645][v643][v644] = v648;	// L1176
        }
      }
    }
  }
  return ;	// L1181
}

void main_graph_node20(
  int8_t v649[256][3][3],
  int8_t v650[1][256][28][28],
  int8_t v651[1][256][14][14]
) {	// L1183
  #pragma HLS dataflow

  int8_t v652[1][256][30][30];	// L1185
  #pragma HLS stream variable=v652 depth=10 type=fifo

  #pragma HLS bind_storage variable=v652 type=ram_t2p impl=bram

  for (int v653 = 0; v653 < 1; v653 += 1) {	// L1186
    for (int v654 = 0; v654 < 30; v654 += 1) {	// L1187
      for (int v655 = 0; v655 < 30; v655 += 1) {	// L1188
        for (int v656 = 0; v656 < 256; v656 += 1) {	// L1189
          int8_t v657;	// L1190
          v657 = (int8_t)0.000000;	// L1191
          if (((-v654) + 27) >= 0 && ((-v655) + 27) >= 0) {	// L1192
            int8_t v658 = v650[v653][v656][v654][v655];	// L1193
            v657 = v658;	// L1194
          }
          int8_t v659 = v657;	// L1196
          v652[v653][v656][v654][v655] = v659;	// L1197
        }
      }
    }
  }
  int8_t v660[1][256][14][14];	// L1202
  #pragma HLS stream variable=v660 depth=10 type=fifo

  #pragma HLS bind_storage variable=v660 type=ram_t2p impl=bram

  int8_t v661[1][256][3][30];	// L1203
  #pragma HLS array_partition variable=v661 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v661 type=ram_2p impl=bram

  int8_t v662[1][256][3][3];	// L1204
  #pragma HLS array_partition variable=v662 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v662 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v662 type=ram_2p impl=lutram

  for (int v663 = 0; v663 < 1; v663 += 1) {	// L1205
    for (int v664 = 0; v664 < 30; v664 += 1) {	// L1206
      for (int v665 = 0; v665 < 30; v665 += 1) {	// L1207
        for (int v666 = 0; v666 < 256; v666 += 1) {	// L1208
          int8_t v667 = v661[v663][v666][1][v665];	// L1209
          v661[v663][v666][0][v665] = v667;	// L1210
          int8_t v668 = v661[v663][v666][2][v665];	// L1211
          v661[v663][v666][1][v665] = v668;	// L1212
          int8_t v669 = v652[v663][v666][v664][v665];	// L1213
          v661[v663][v666][2][v665] = v669;	// L1214
        }
        if ((v664 - 16) >= 0) {	// L1216
          for (int v670 = 0; v670 < 256; v670 += 1) {	// L1217
            for (int v671 = 0; v671 < 3; v671 += 1) {	// L1218
              int8_t v672 = v662[v663][v670][v671][1];	// L1219
              v662[v663][v670][v671][0] = v672;	// L1220
              int8_t v673 = v662[v663][v670][v671][2];	// L1221
              v662[v663][v670][v671][1] = v673;	// L1222
              int8_t v674 = v661[v663][v670][v671][v665];	// L1223
              v662[v663][v670][v671][2] = v674;	// L1224
            }
          }
          if ((v665 - 16) >= 0) {	// L1227
            int8_t v675[256];	// L1228
            #pragma HLS bind_storage variable=v675 type=ram_2p impl=bram

            for (int v676 = 0; v676 < 256; v676 += 1) {	// L1229
              #pragma HLS pipeline II=1
              for (int v677 = 0; v677 < 1; v677 += 1) {	// L1230
                v675[(v676 + v677)] = (int8_t)0.000000;	// L1231
                for (int v678 = 0; v678 < 3; v678 += 1) {	// L1232
                  for (int v679 = 0; v679 < 3; v679 += 1) {	// L1233
                    int8_t v680 = v662[v663][(v676 + v677)][v678][v679];	// L1234
                    int8_t v681 = v649[(v676 + v677)][v678][v679];	// L1235
                    int8_t v682 = v680 * v681;	// L1236
                    int8_t v683 = v675[(v676 + v677)];	// L1237
                    int8_t v684 = v683 + v682;	// L1238
                    v675[(v676 + v677)] = v684;	// L1239
                  }
                }
                int8_t v685 = v675[(v676 + v677)];	// L1242
                v660[v663][(v676 + v677)][(v664 - 16)][(v665 - 16)] = v685;	// L1243
              }
            }
          }
        }
      }
    }
  }
  for (int v686 = 0; v686 < 1; v686 += 1) {	// L1251
    for (int v687 = 0; v687 < 14; v687 += 1) {	// L1252
      for (int v688 = 0; v688 < 14; v688 += 1) {	// L1253
        for (int v689 = 0; v689 < 256; v689 += 1) {	// L1254
          int8_t v690 = v660[0][v689][v687][v688];	// L1255
          bool v691 = v690 > (int8_t)0.000000;	// L1256
          int8_t v692 = v691 ? v690 : (int8_t)0.000000;	// L1257
          v651[v686][v689][v687][v688] = v692;	// L1258
        }
      }
    }
  }
  return ;	// L1263
}

void main_graph_node21(
  int8_t v693[256][256][1][1],
  int8_t v694[1][256][28][28],
  int8_t v695[1][256][28][28]
) {	// L1265
  #pragma HLS dataflow

  int8_t v696[1][256][28][28];	// L1267
  #pragma HLS stream variable=v696 depth=10 type=fifo

  #pragma HLS bind_storage variable=v696 type=ram_t2p impl=bram

  int8_t v697[1][256][1][28];	// L1268
  #pragma HLS bind_storage variable=v697 type=ram_2p impl=bram

  int8_t v698[1][256][1][1];	// L1269
  #pragma HLS array_partition variable=v698 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v698 type=ram_2p impl=lutram

  for (int v699 = 0; v699 < 1; v699 += 1) {	// L1270
    for (int v700 = 0; v700 < 28; v700 += 1) {	// L1271
      for (int v701 = 0; v701 < 28; v701 += 1) {	// L1272
        for (int v702 = 0; v702 < 256; v702 += 1) {	// L1273
          int8_t v703 = v694[v699][v702][v700][v701];	// L1274
          v697[v699][v702][0][v701] = v703;	// L1275
        }
        if (v700 >= 0) {	// L1277
          for (int v704 = 0; v704 < 256; v704 += 1) {	// L1278
            for (int v705 = 0; v705 < 1; v705 += 1) {	// L1279
              int8_t v706 = v697[v699][v704][v705][v701];	// L1280
              v698[v699][v704][v705][0] = v706;	// L1281
            }
          }
          if (v701 >= 0) {	// L1284
            int8_t v707[256];	// L1285
            #pragma HLS bind_storage variable=v707 type=ram_2p impl=bram

            for (int v708 = 0; v708 < 256; v708 += 1) {	// L1286
              v707[v708] = (int8_t)0.000000;	// L1287
              for (int v709 = 0; v709 < 8; v709 += 1) {	// L1288
                #pragma HLS pipeline II=1
                for (int v710 = 0; v710 < 32; v710 += 1) {	// L1289
                  for (int v711 = 0; v711 < 1; v711 += 1) {	// L1290
                    for (int v712 = 0; v712 < 1; v712 += 1) {	// L1291
                      int8_t v713 = v698[v699][(v710 + (v709 * 32))][v711][v712];	// L1292
                      int8_t v714 = v693[v708][(v710 + (v709 * 32))][v711][v712];	// L1293
                      int8_t v715 = v713 * v714;	// L1294
                      int8_t v716 = v707[v708];	// L1295
                      int8_t v717 = v716 + v715;	// L1296
                      v707[v708] = v717;	// L1297
                    }
                  }
                }
              }
              int8_t v718 = v707[v708];	// L1302
              v696[v699][v708][v700][v701] = v718;	// L1303
            }
          }
        }
      }
    }
  }
  for (int v719 = 0; v719 < 1; v719 += 1) {	// L1310
    for (int v720 = 0; v720 < 28; v720 += 1) {	// L1311
      for (int v721 = 0; v721 < 28; v721 += 1) {	// L1312
        for (int v722 = 0; v722 < 256; v722 += 1) {	// L1313
          int8_t v723 = v696[0][v722][v720][v721];	// L1314
          bool v724 = v723 > (int8_t)0.000000;	// L1315
          int8_t v725 = v724 ? v723 : (int8_t)0.000000;	// L1316
          v695[v719][v722][v720][v721] = v725;	// L1317
        }
      }
    }
  }
  return ;	// L1322
}

void main_graph_node22(
  int8_t v726[1][256][28][28],
  int8_t v727[256][3][3],
  int8_t v728[1][256][28][28]
) {	// L1324
  #pragma HLS dataflow

  int8_t v729[1][256][30][30];	// L1326
  #pragma HLS stream variable=v729 depth=10 type=fifo

  #pragma HLS bind_storage variable=v729 type=ram_t2p impl=bram

  for (int v730 = 0; v730 < 1; v730 += 1) {	// L1327
    for (int v731 = 0; v731 < 30; v731 += 1) {	// L1328
      for (int v732 = 0; v732 < 30; v732 += 1) {	// L1329
        for (int v733 = 0; v733 < 256; v733 += 1) {	// L1330
          int8_t v734;	// L1331
          v734 = (int8_t)0.000000;	// L1332
          if (((-v731) + 27) >= 0 && ((-v732) + 27) >= 0) {	// L1333
            int8_t v735 = v726[v730][v733][v731][v732];	// L1334
            v734 = v735;	// L1335
          }
          int8_t v736 = v734;	// L1337
          v729[v730][v733][v731][v732] = v736;	// L1338
        }
      }
    }
  }
  int8_t v737[1][256][28][28];	// L1343
  #pragma HLS stream variable=v737 depth=10 type=fifo

  #pragma HLS bind_storage variable=v737 type=ram_t2p impl=bram

  int8_t v738[1][256][3][30];	// L1344
  #pragma HLS array_partition variable=v738 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v738 type=ram_2p impl=bram

  int8_t v739[1][256][3][3];	// L1345
  #pragma HLS array_partition variable=v739 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v739 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v739 type=ram_2p impl=lutram

  for (int v740 = 0; v740 < 1; v740 += 1) {	// L1346
    for (int v741 = 0; v741 < 30; v741 += 1) {	// L1347
      for (int v742 = 0; v742 < 30; v742 += 1) {	// L1348
        for (int v743 = 0; v743 < 256; v743 += 1) {	// L1349
          int8_t v744 = v738[v740][v743][1][v742];	// L1350
          v738[v740][v743][0][v742] = v744;	// L1351
          int8_t v745 = v738[v740][v743][2][v742];	// L1352
          v738[v740][v743][1][v742] = v745;	// L1353
          int8_t v746 = v729[v740][v743][v741][v742];	// L1354
          v738[v740][v743][2][v742] = v746;	// L1355
        }
        if ((v741 - 2) >= 0) {	// L1357
          for (int v747 = 0; v747 < 256; v747 += 1) {	// L1358
            for (int v748 = 0; v748 < 3; v748 += 1) {	// L1359
              int8_t v749 = v739[v740][v747][v748][1];	// L1360
              v739[v740][v747][v748][0] = v749;	// L1361
              int8_t v750 = v739[v740][v747][v748][2];	// L1362
              v739[v740][v747][v748][1] = v750;	// L1363
              int8_t v751 = v738[v740][v747][v748][v742];	// L1364
              v739[v740][v747][v748][2] = v751;	// L1365
            }
          }
          if ((v742 - 2) >= 0) {	// L1368
            int8_t v752[256];	// L1369
            #pragma HLS bind_storage variable=v752 type=ram_2p impl=bram

            for (int v753 = 0; v753 < 256; v753 += 1) {	// L1370
              #pragma HLS pipeline II=1
              for (int v754 = 0; v754 < 1; v754 += 1) {	// L1371
                v752[(v753 + v754)] = (int8_t)0.000000;	// L1372
                for (int v755 = 0; v755 < 3; v755 += 1) {	// L1373
                  for (int v756 = 0; v756 < 3; v756 += 1) {	// L1374
                    int8_t v757 = v739[v740][(v753 + v754)][v755][v756];	// L1375
                    int8_t v758 = v727[(v753 + v754)][v755][v756];	// L1376
                    int8_t v759 = v757 * v758;	// L1377
                    int8_t v760 = v752[(v753 + v754)];	// L1378
                    int8_t v761 = v760 + v759;	// L1379
                    v752[(v753 + v754)] = v761;	// L1380
                  }
                }
                int8_t v762 = v752[(v753 + v754)];	// L1383
                v737[v740][(v753 + v754)][(v741 - 2)][(v742 - 2)] = v762;	// L1384
              }
            }
          }
        }
      }
    }
  }
  for (int v763 = 0; v763 < 1; v763 += 1) {	// L1392
    for (int v764 = 0; v764 < 28; v764 += 1) {	// L1393
      for (int v765 = 0; v765 < 28; v765 += 1) {	// L1394
        for (int v766 = 0; v766 < 256; v766 += 1) {	// L1395
          int8_t v767 = v737[0][v766][v764][v765];	// L1396
          bool v768 = v767 > (int8_t)0.000000;	// L1397
          int8_t v769 = v768 ? v767 : (int8_t)0.000000;	// L1398
          v728[v763][v766][v764][v765] = v769;	// L1399
        }
      }
    }
  }
  return ;	// L1404
}

void main_graph_node23(
  int8_t v770[1][128][28][28],
  int8_t v771[256][128][1][1],
  int8_t v772[1][256][28][28]
) {	// L1406
  #pragma HLS dataflow

  int8_t v773[1][256][28][28];	// L1408
  #pragma HLS stream variable=v773 depth=10 type=fifo

  #pragma HLS bind_storage variable=v773 type=ram_t2p impl=bram

  int8_t v774[1][128][1][28];	// L1409
  #pragma HLS array_partition variable=v774 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v774 type=ram_2p impl=lutram

  int8_t v775[1][128][1][1];	// L1410
  #pragma HLS array_partition variable=v775 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v775 type=ram_2p impl=lutram

  for (int v776 = 0; v776 < 1; v776 += 1) {	// L1411
    for (int v777 = 0; v777 < 28; v777 += 1) {	// L1412
      for (int v778 = 0; v778 < 28; v778 += 1) {	// L1413
        for (int v779 = 0; v779 < 16; v779 += 1) {	// L1414
          #pragma HLS pipeline II=1
          for (int v780 = 0; v780 < 8; v780 += 1) {	// L1415
            int8_t v781 = v770[v776][(v780 + (v779 * 8))][v777][v778];	// L1416
            v774[v776][(v780 + (v779 * 8))][0][v778] = v781;	// L1417
          }
        }
        if (v777 >= 0) {	// L1420
          for (int v782 = 0; v782 < 16; v782 += 1) {	// L1421
            #pragma HLS pipeline II=1
            for (int v783 = 0; v783 < 8; v783 += 1) {	// L1422
              for (int v784 = 0; v784 < 1; v784 += 1) {	// L1423
                int8_t v785 = v774[v776][(v783 + (v782 * 8))][v784][v778];	// L1424
                v775[v776][(v783 + (v782 * 8))][v784][0] = v785;	// L1425
              }
            }
          }
          if (v778 >= 0) {	// L1429
            int8_t v786[256];	// L1430
            #pragma HLS bind_storage variable=v786 type=ram_2p impl=bram

            for (int v787 = 0; v787 < 256; v787 += 1) {	// L1431
              v786[v787] = (int8_t)0.000000;	// L1432
              for (int v788 = 0; v788 < 8; v788 += 1) {	// L1433
                #pragma HLS pipeline II=1
                for (int v789 = 0; v789 < 16; v789 += 1) {	// L1434
                  for (int v790 = 0; v790 < 1; v790 += 1) {	// L1435
                    for (int v791 = 0; v791 < 1; v791 += 1) {	// L1436
                      int8_t v792 = v775[v776][(v789 + (v788 * 16))][v790][v791];	// L1437
                      int8_t v793 = v771[v787][(v789 + (v788 * 16))][v790][v791];	// L1438
                      int8_t v794 = v792 * v793;	// L1439
                      int8_t v795 = v786[v787];	// L1440
                      int8_t v796 = v795 + v794;	// L1441
                      v786[v787] = v796;	// L1442
                    }
                  }
                }
              }
              int8_t v797 = v786[v787];	// L1447
              v773[v776][v787][v777][v778] = v797;	// L1448
            }
          }
        }
      }
    }
  }
  for (int v798 = 0; v798 < 1; v798 += 1) {	// L1455
    for (int v799 = 0; v799 < 28; v799 += 1) {	// L1456
      for (int v800 = 0; v800 < 28; v800 += 1) {	// L1457
        for (int v801 = 0; v801 < 256; v801 += 1) {	// L1458
          int8_t v802 = v773[0][v801][v799][v800];	// L1459
          bool v803 = v802 > (int8_t)0.000000;	// L1460
          int8_t v804 = v803 ? v802 : (int8_t)0.000000;	// L1461
          v772[v798][v801][v799][v800] = v804;	// L1462
        }
      }
    }
  }
  return ;	// L1467
}

void main_graph_node24(
  int8_t v805[128][3][3],
  int8_t v806[1][128][56][56],
  int8_t v807[1][128][28][28]
) {	// L1469
  #pragma HLS dataflow

  int8_t v808[1][128][58][58];	// L1471
  #pragma HLS stream variable=v808 depth=10 type=fifo

  #pragma HLS bind_storage variable=v808 type=ram_t2p impl=bram

  for (int v809 = 0; v809 < 1; v809 += 1) {	// L1472
    for (int v810 = 0; v810 < 58; v810 += 1) {	// L1473
      for (int v811 = 0; v811 < 58; v811 += 1) {	// L1474
        for (int v812 = 0; v812 < 128; v812 += 1) {	// L1475
          int8_t v813;	// L1476
          v813 = (int8_t)0.000000;	// L1477
          if (((-v810) + 55) >= 0 && ((-v811) + 55) >= 0) {	// L1478
            int8_t v814 = v806[v809][v812][v810][v811];	// L1479
            v813 = v814;	// L1480
          }
          int8_t v815 = v813;	// L1482
          v808[v809][v812][v810][v811] = v815;	// L1483
        }
      }
    }
  }
  int8_t v816[1][128][28][28];	// L1488
  #pragma HLS stream variable=v816 depth=10 type=fifo

  #pragma HLS array_partition variable=v816 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v816 type=ram_t2p impl=bram

  int8_t v817[1][128][3][58];	// L1489
  #pragma HLS array_partition variable=v817 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v817 type=ram_2p impl=bram

  int8_t v818[1][128][3][3];	// L1490
  #pragma HLS array_partition variable=v818 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v818 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v818 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v818 type=ram_2p impl=lutram

  for (int v819 = 0; v819 < 1; v819 += 1) {	// L1491
    for (int v820 = 0; v820 < 58; v820 += 1) {	// L1492
      for (int v821 = 0; v821 < 58; v821 += 1) {	// L1493
        for (int v822 = 0; v822 < 128; v822 += 1) {	// L1494
          int8_t v823 = v817[v819][v822][1][v821];	// L1495
          v817[v819][v822][0][v821] = v823;	// L1496
          int8_t v824 = v817[v819][v822][2][v821];	// L1497
          v817[v819][v822][1][v821] = v824;	// L1498
          int8_t v825 = v808[v819][v822][v820][v821];	// L1499
          v817[v819][v822][2][v821] = v825;	// L1500
        }
        if ((v820 - 30) >= 0) {	// L1502
          for (int v826 = 0; v826 < 128; v826 += 1) {	// L1503
            for (int v827 = 0; v827 < 3; v827 += 1) {	// L1504
              int8_t v828 = v818[v819][v826][v827][1];	// L1505
              v818[v819][v826][v827][0] = v828;	// L1506
              int8_t v829 = v818[v819][v826][v827][2];	// L1507
              v818[v819][v826][v827][1] = v829;	// L1508
              int8_t v830 = v817[v819][v826][v827][v821];	// L1509
              v818[v819][v826][v827][2] = v830;	// L1510
            }
          }
          if ((v821 - 30) >= 0) {	// L1513
            int8_t v831[128];	// L1514
            #pragma HLS array_partition variable=v831 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v831 type=ram_2p impl=lutram

            for (int v832 = 0; v832 < 16; v832 += 1) {	// L1515
              #pragma HLS pipeline II=1
              for (int v833 = 0; v833 < 8; v833 += 1) {	// L1516
                v831[(v833 + (v832 * 8))] = (int8_t)0.000000;	// L1517
                for (int v834 = 0; v834 < 3; v834 += 1) {	// L1518
                  for (int v835 = 0; v835 < 3; v835 += 1) {	// L1519
                    int8_t v836 = v818[v819][(v833 + (v832 * 8))][v834][v835];	// L1520
                    int8_t v837 = v805[(v833 + (v832 * 8))][v834][v835];	// L1521
                    int8_t v838 = v836 * v837;	// L1522
                    int8_t v839 = v831[(v833 + (v832 * 8))];	// L1523
                    int8_t v840 = v839 + v838;	// L1524
                    v831[(v833 + (v832 * 8))] = v840;	// L1525
                  }
                }
                int8_t v841 = v831[(v833 + (v832 * 8))];	// L1528
                v816[v819][(v833 + (v832 * 8))][(v820 - 30)][(v821 - 30)] = v841;	// L1529
              }
            }
          }
        }
      }
    }
  }
  for (int v842 = 0; v842 < 1; v842 += 1) {	// L1537
    for (int v843 = 0; v843 < 28; v843 += 1) {	// L1538
      for (int v844 = 0; v844 < 28; v844 += 1) {	// L1539
        for (int v845 = 0; v845 < 16; v845 += 1) {	// L1540
          #pragma HLS pipeline II=1
          for (int v846 = 0; v846 < 8; v846 += 1) {	// L1541
            int8_t v847 = v816[0][(v846 + (v845 * 8))][v843][v844];	// L1542
            bool v848 = v847 > (int8_t)0.000000;	// L1543
            int8_t v849 = v848 ? v847 : (int8_t)0.000000;	// L1544
            v807[v842][(v846 + (v845 * 8))][v843][v844] = v849;	// L1545
          }
        }
      }
    }
  }
  return ;	// L1551
}

void main_graph_node25(
  int8_t v850[128][128][1][1],
  int8_t v851[1][128][56][56],
  int8_t v852[1][128][56][56]
) {	// L1553
  #pragma HLS dataflow

  int8_t v853[1][128][56][56];	// L1555
  #pragma HLS stream variable=v853 depth=10 type=fifo

  #pragma HLS bind_storage variable=v853 type=ram_t2p impl=bram

  int8_t v854[1][128][1][56];	// L1556
  #pragma HLS array_partition variable=v854 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v854 type=ram_2p impl=lutram

  int8_t v855[1][128][1][1];	// L1557
  #pragma HLS array_partition variable=v855 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v855 type=ram_2p impl=lutram

  for (int v856 = 0; v856 < 1; v856 += 1) {	// L1558
    for (int v857 = 0; v857 < 56; v857 += 1) {	// L1559
      for (int v858 = 0; v858 < 56; v858 += 1) {	// L1560
        for (int v859 = 0; v859 < 16; v859 += 1) {	// L1561
          #pragma HLS pipeline II=1
          for (int v860 = 0; v860 < 8; v860 += 1) {	// L1562
            int8_t v861 = v851[v856][(v860 + (v859 * 8))][v857][v858];	// L1563
            v854[v856][(v860 + (v859 * 8))][0][v858] = v861;	// L1564
          }
        }
        if (v857 >= 0) {	// L1567
          for (int v862 = 0; v862 < 16; v862 += 1) {	// L1568
            #pragma HLS pipeline II=1
            for (int v863 = 0; v863 < 8; v863 += 1) {	// L1569
              for (int v864 = 0; v864 < 1; v864 += 1) {	// L1570
                int8_t v865 = v854[v856][(v863 + (v862 * 8))][v864][v858];	// L1571
                v855[v856][(v863 + (v862 * 8))][v864][0] = v865;	// L1572
              }
            }
          }
          if (v858 >= 0) {	// L1576
            int8_t v866[128];	// L1577
            #pragma HLS bind_storage variable=v866 type=ram_2p impl=bram

            for (int v867 = 0; v867 < 128; v867 += 1) {	// L1578
              v866[v867] = (int8_t)0.000000;	// L1579
              for (int v868 = 0; v868 < 4; v868 += 1) {	// L1580
                #pragma HLS pipeline II=1
                for (int v869 = 0; v869 < 32; v869 += 1) {	// L1581
                  for (int v870 = 0; v870 < 1; v870 += 1) {	// L1582
                    for (int v871 = 0; v871 < 1; v871 += 1) {	// L1583
                      int8_t v872 = v855[v856][(v869 + (v868 * 32))][v870][v871];	// L1584
                      int8_t v873 = v850[v867][(v869 + (v868 * 32))][v870][v871];	// L1585
                      int8_t v874 = v872 * v873;	// L1586
                      int8_t v875 = v866[v867];	// L1587
                      int8_t v876 = v875 + v874;	// L1588
                      v866[v867] = v876;	// L1589
                    }
                  }
                }
              }
              int8_t v877 = v866[v867];	// L1594
              v853[v856][v867][v857][v858] = v877;	// L1595
            }
          }
        }
      }
    }
  }
  for (int v878 = 0; v878 < 1; v878 += 1) {	// L1602
    for (int v879 = 0; v879 < 56; v879 += 1) {	// L1603
      for (int v880 = 0; v880 < 56; v880 += 1) {	// L1604
        for (int v881 = 0; v881 < 128; v881 += 1) {	// L1605
          int8_t v882 = v853[0][v881][v879][v880];	// L1606
          bool v883 = v882 > (int8_t)0.000000;	// L1607
          int8_t v884 = v883 ? v882 : (int8_t)0.000000;	// L1608
          v852[v878][v881][v879][v880] = v884;	// L1609
        }
      }
    }
  }
  return ;	// L1614
}

void main_graph_node26(
  int8_t v885[128][3][3],
  int8_t v886[1][128][56][56],
  int8_t v887[1][128][56][56]
) {	// L1616
  #pragma HLS dataflow

  int8_t v888[1][128][58][58];	// L1618
  #pragma HLS stream variable=v888 depth=10 type=fifo

  #pragma HLS bind_storage variable=v888 type=ram_t2p impl=bram

  for (int v889 = 0; v889 < 1; v889 += 1) {	// L1619
    for (int v890 = 0; v890 < 58; v890 += 1) {	// L1620
      for (int v891 = 0; v891 < 58; v891 += 1) {	// L1621
        for (int v892 = 0; v892 < 128; v892 += 1) {	// L1622
          int8_t v893;	// L1623
          v893 = (int8_t)0.000000;	// L1624
          if (((-v890) + 55) >= 0 && ((-v891) + 55) >= 0) {	// L1625
            int8_t v894 = v886[v889][v892][v890][v891];	// L1626
            v893 = v894;	// L1627
          }
          int8_t v895 = v893;	// L1629
          v888[v889][v892][v890][v891] = v895;	// L1630
        }
      }
    }
  }
  int8_t v896[1][128][56][56];	// L1635
  #pragma HLS stream variable=v896 depth=10 type=fifo

  #pragma HLS array_partition variable=v896 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v896 type=ram_t2p impl=bram

  int8_t v897[1][128][3][58];	// L1636
  #pragma HLS array_partition variable=v897 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v897 type=ram_2p impl=bram

  int8_t v898[1][128][3][3];	// L1637
  #pragma HLS array_partition variable=v898 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v898 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v898 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v898 type=ram_2p impl=lutram

  for (int v899 = 0; v899 < 1; v899 += 1) {	// L1638
    for (int v900 = 0; v900 < 58; v900 += 1) {	// L1639
      for (int v901 = 0; v901 < 58; v901 += 1) {	// L1640
        for (int v902 = 0; v902 < 128; v902 += 1) {	// L1641
          int8_t v903 = v897[v899][v902][1][v901];	// L1642
          v897[v899][v902][0][v901] = v903;	// L1643
          int8_t v904 = v897[v899][v902][2][v901];	// L1644
          v897[v899][v902][1][v901] = v904;	// L1645
          int8_t v905 = v888[v899][v902][v900][v901];	// L1646
          v897[v899][v902][2][v901] = v905;	// L1647
        }
        if ((v900 - 2) >= 0) {	// L1649
          for (int v906 = 0; v906 < 128; v906 += 1) {	// L1650
            for (int v907 = 0; v907 < 3; v907 += 1) {	// L1651
              int8_t v908 = v898[v899][v906][v907][1];	// L1652
              v898[v899][v906][v907][0] = v908;	// L1653
              int8_t v909 = v898[v899][v906][v907][2];	// L1654
              v898[v899][v906][v907][1] = v909;	// L1655
              int8_t v910 = v897[v899][v906][v907][v901];	// L1656
              v898[v899][v906][v907][2] = v910;	// L1657
            }
          }
          if ((v901 - 2) >= 0) {	// L1660
            int8_t v911[128];	// L1661
            #pragma HLS array_partition variable=v911 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v911 type=ram_2p impl=lutram

            for (int v912 = 0; v912 < 16; v912 += 1) {	// L1662
              #pragma HLS pipeline II=1
              for (int v913 = 0; v913 < 8; v913 += 1) {	// L1663
                v911[(v913 + (v912 * 8))] = (int8_t)0.000000;	// L1664
                for (int v914 = 0; v914 < 3; v914 += 1) {	// L1665
                  for (int v915 = 0; v915 < 3; v915 += 1) {	// L1666
                    int8_t v916 = v898[v899][(v913 + (v912 * 8))][v914][v915];	// L1667
                    int8_t v917 = v885[(v913 + (v912 * 8))][v914][v915];	// L1668
                    int8_t v918 = v916 * v917;	// L1669
                    int8_t v919 = v911[(v913 + (v912 * 8))];	// L1670
                    int8_t v920 = v919 + v918;	// L1671
                    v911[(v913 + (v912 * 8))] = v920;	// L1672
                  }
                }
                int8_t v921 = v911[(v913 + (v912 * 8))];	// L1675
                v896[v899][(v913 + (v912 * 8))][(v900 - 2)][(v901 - 2)] = v921;	// L1676
              }
            }
          }
        }
      }
    }
  }
  for (int v922 = 0; v922 < 1; v922 += 1) {	// L1684
    for (int v923 = 0; v923 < 56; v923 += 1) {	// L1685
      for (int v924 = 0; v924 < 56; v924 += 1) {	// L1686
        for (int v925 = 0; v925 < 16; v925 += 1) {	// L1687
          #pragma HLS pipeline II=1
          for (int v926 = 0; v926 < 8; v926 += 1) {	// L1688
            int8_t v927 = v896[0][(v926 + (v925 * 8))][v923][v924];	// L1689
            bool v928 = v927 > (int8_t)0.000000;	// L1690
            int8_t v929 = v928 ? v927 : (int8_t)0.000000;	// L1691
            v887[v922][(v926 + (v925 * 8))][v923][v924] = v929;	// L1692
          }
        }
      }
    }
  }
  return ;	// L1698
}

void main_graph_node27(
  int8_t v930[1][64][56][56],
  int8_t v931[128][64][1][1],
  int8_t v932[1][128][56][56]
) {	// L1700
  #pragma HLS dataflow

  int8_t v933[1][128][56][56];	// L1702
  #pragma HLS stream variable=v933 depth=10 type=fifo

  #pragma HLS bind_storage variable=v933 type=ram_t2p impl=bram

  int8_t v934[1][64][1][56];	// L1703
  #pragma HLS array_partition variable=v934 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v934 type=ram_2p impl=lutram

  int8_t v935[1][64][1][1];	// L1704
  #pragma HLS array_partition variable=v935 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v935 type=ram_2p impl=lutram

  for (int v936 = 0; v936 < 1; v936 += 1) {	// L1705
    for (int v937 = 0; v937 < 56; v937 += 1) {	// L1706
      for (int v938 = 0; v938 < 56; v938 += 1) {	// L1707
        for (int v939 = 0; v939 < 4; v939 += 1) {	// L1708
          #pragma HLS pipeline II=1
          for (int v940 = 0; v940 < 16; v940 += 1) {	// L1709
            int8_t v941 = v930[v936][(v940 + (v939 * 16))][v937][v938];	// L1710
            v934[v936][(v940 + (v939 * 16))][0][v938] = v941;	// L1711
          }
        }
        if (v937 >= 0) {	// L1714
          for (int v942 = 0; v942 < 4; v942 += 1) {	// L1715
            #pragma HLS pipeline II=1
            for (int v943 = 0; v943 < 16; v943 += 1) {	// L1716
              for (int v944 = 0; v944 < 1; v944 += 1) {	// L1717
                int8_t v945 = v934[v936][(v943 + (v942 * 16))][v944][v938];	// L1718
                v935[v936][(v943 + (v942 * 16))][v944][0] = v945;	// L1719
              }
            }
          }
          if (v938 >= 0) {	// L1723
            int8_t v946[128];	// L1724
            #pragma HLS bind_storage variable=v946 type=ram_2p impl=bram

            for (int v947 = 0; v947 < 128; v947 += 1) {	// L1725
              v946[v947] = (int8_t)0.000000;	// L1726
              for (int v948 = 0; v948 < 4; v948 += 1) {	// L1727
                #pragma HLS pipeline II=1
                for (int v949 = 0; v949 < 16; v949 += 1) {	// L1728
                  for (int v950 = 0; v950 < 1; v950 += 1) {	// L1729
                    for (int v951 = 0; v951 < 1; v951 += 1) {	// L1730
                      int8_t v952 = v935[v936][(v949 + (v948 * 16))][v950][v951];	// L1731
                      int8_t v953 = v931[v947][(v949 + (v948 * 16))][v950][v951];	// L1732
                      int8_t v954 = v952 * v953;	// L1733
                      int8_t v955 = v946[v947];	// L1734
                      int8_t v956 = v955 + v954;	// L1735
                      v946[v947] = v956;	// L1736
                    }
                  }
                }
              }
              int8_t v957 = v946[v947];	// L1741
              v933[v936][v947][v937][v938] = v957;	// L1742
            }
          }
        }
      }
    }
  }
  for (int v958 = 0; v958 < 1; v958 += 1) {	// L1749
    for (int v959 = 0; v959 < 56; v959 += 1) {	// L1750
      for (int v960 = 0; v960 < 56; v960 += 1) {	// L1751
        for (int v961 = 0; v961 < 128; v961 += 1) {	// L1752
          int8_t v962 = v933[0][v961][v959][v960];	// L1753
          bool v963 = v962 > (int8_t)0.000000;	// L1754
          int8_t v964 = v963 ? v962 : (int8_t)0.000000;	// L1755
          v932[v958][v961][v959][v960] = v964;	// L1756
        }
      }
    }
  }
  return ;	// L1761
}

void main_graph_node28(
  int8_t v965[1][64][112][112],
  int8_t v966[64][3][3],
  int8_t v967[1][64][56][56]
) {	// L1763
  #pragma HLS dataflow

  int8_t v968[1][64][114][114];	// L1765
  #pragma HLS stream variable=v968 depth=10 type=fifo

  #pragma HLS bind_storage variable=v968 type=ram_t2p impl=bram

  for (int v969 = 0; v969 < 1; v969 += 1) {	// L1766
    for (int v970 = 0; v970 < 114; v970 += 1) {	// L1767
      for (int v971 = 0; v971 < 114; v971 += 1) {	// L1768
        for (int v972 = 0; v972 < 64; v972 += 1) {	// L1769
          int8_t v973;	// L1770
          v973 = (int8_t)0.000000;	// L1771
          if (((-v970) + 111) >= 0 && ((-v971) + 111) >= 0) {	// L1772
            int8_t v974 = v965[v969][v972][v970][v971];	// L1773
            v973 = v974;	// L1774
          }
          int8_t v975 = v973;	// L1776
          v968[v969][v972][v970][v971] = v975;	// L1777
        }
      }
    }
  }
  int8_t v976[1][64][56][56];	// L1782
  #pragma HLS stream variable=v976 depth=10 type=fifo

  #pragma HLS array_partition variable=v976 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v976 type=ram_t2p impl=bram

  int8_t v977[1][64][3][114];	// L1783
  #pragma HLS array_partition variable=v977 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v977 type=ram_2p impl=bram

  int8_t v978[1][64][3][3];	// L1784
  #pragma HLS array_partition variable=v978 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v978 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v978 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v978 type=ram_2p impl=lutram

  for (int v979 = 0; v979 < 1; v979 += 1) {	// L1785
    for (int v980 = 0; v980 < 114; v980 += 1) {	// L1786
      for (int v981 = 0; v981 < 114; v981 += 1) {	// L1787
        for (int v982 = 0; v982 < 64; v982 += 1) {	// L1788
          int8_t v983 = v977[v979][v982][1][v981];	// L1789
          v977[v979][v982][0][v981] = v983;	// L1790
          int8_t v984 = v977[v979][v982][2][v981];	// L1791
          v977[v979][v982][1][v981] = v984;	// L1792
          int8_t v985 = v968[v979][v982][v980][v981];	// L1793
          v977[v979][v982][2][v981] = v985;	// L1794
        }
        if ((v980 - 58) >= 0) {	// L1796
          for (int v986 = 0; v986 < 64; v986 += 1) {	// L1797
            for (int v987 = 0; v987 < 3; v987 += 1) {	// L1798
              int8_t v988 = v978[v979][v986][v987][1];	// L1799
              v978[v979][v986][v987][0] = v988;	// L1800
              int8_t v989 = v978[v979][v986][v987][2];	// L1801
              v978[v979][v986][v987][1] = v989;	// L1802
              int8_t v990 = v977[v979][v986][v987][v981];	// L1803
              v978[v979][v986][v987][2] = v990;	// L1804
            }
          }
          if ((v981 - 58) >= 0) {	// L1807
            int8_t v991[64];	// L1808
            #pragma HLS array_partition variable=v991 cyclic factor=16 dim=1
            #pragma HLS bind_storage variable=v991 type=ram_2p impl=lutram

            for (int v992 = 0; v992 < 4; v992 += 1) {	// L1809
              #pragma HLS pipeline II=1
              for (int v993 = 0; v993 < 16; v993 += 1) {	// L1810
                v991[(v993 + (v992 * 16))] = (int8_t)0.000000;	// L1811
                for (int v994 = 0; v994 < 3; v994 += 1) {	// L1812
                  for (int v995 = 0; v995 < 3; v995 += 1) {	// L1813
                    int8_t v996 = v978[v979][(v993 + (v992 * 16))][v994][v995];	// L1814
                    int8_t v997 = v966[(v993 + (v992 * 16))][v994][v995];	// L1815
                    int8_t v998 = v996 * v997;	// L1816
                    int8_t v999 = v991[(v993 + (v992 * 16))];	// L1817
                    int8_t v1000 = v999 + v998;	// L1818
                    v991[(v993 + (v992 * 16))] = v1000;	// L1819
                  }
                }
                int8_t v1001 = v991[(v993 + (v992 * 16))];	// L1822
                v976[v979][(v993 + (v992 * 16))][(v980 - 58)][(v981 - 58)] = v1001;	// L1823
              }
            }
          }
        }
      }
    }
  }
  for (int v1002 = 0; v1002 < 1; v1002 += 1) {	// L1831
    for (int v1003 = 0; v1003 < 56; v1003 += 1) {	// L1832
      for (int v1004 = 0; v1004 < 56; v1004 += 1) {	// L1833
        for (int v1005 = 0; v1005 < 4; v1005 += 1) {	// L1834
          #pragma HLS pipeline II=1
          for (int v1006 = 0; v1006 < 16; v1006 += 1) {	// L1835
            int8_t v1007 = v976[0][(v1006 + (v1005 * 16))][v1003][v1004];	// L1836
            bool v1008 = v1007 > (int8_t)0.000000;	// L1837
            int8_t v1009 = v1008 ? v1007 : (int8_t)0.000000;	// L1838
            v967[v1002][(v1006 + (v1005 * 16))][v1003][v1004] = v1009;	// L1839
          }
        }
      }
    }
  }
  return ;	// L1845
}

void main_graph_node29(
  int8_t v1010[1][32][112][112],
  int8_t v1011[64][32][1][1],
  int8_t v1012[1][64][112][112]
) {	// L1847
  #pragma HLS dataflow

  int8_t v1013[1][64][112][112];	// L1849
  #pragma HLS stream variable=v1013 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1013 type=ram_t2p impl=bram

  int8_t v1014[1][32][1][112];	// L1850
  #pragma HLS array_partition variable=v1014 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1014 type=ram_2p impl=lutram

  int8_t v1015[1][32][1][1];	// L1851
  #pragma HLS array_partition variable=v1015 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1015 type=ram_2p impl=lutram

  for (int v1016 = 0; v1016 < 1; v1016 += 1) {	// L1852
    for (int v1017 = 0; v1017 < 112; v1017 += 1) {	// L1853
      for (int v1018 = 0; v1018 < 112; v1018 += 1) {	// L1854
        for (int v1019 = 0; v1019 < 4; v1019 += 1) {	// L1855
          #pragma HLS pipeline II=1
          for (int v1020 = 0; v1020 < 8; v1020 += 1) {	// L1856
            int8_t v1021 = v1010[v1016][(v1020 + (v1019 * 8))][v1017][v1018];	// L1857
            v1014[v1016][(v1020 + (v1019 * 8))][0][v1018] = v1021;	// L1858
          }
        }
        if (v1017 >= 0) {	// L1861
          for (int v1022 = 0; v1022 < 4; v1022 += 1) {	// L1862
            #pragma HLS pipeline II=1
            for (int v1023 = 0; v1023 < 8; v1023 += 1) {	// L1863
              for (int v1024 = 0; v1024 < 1; v1024 += 1) {	// L1864
                int8_t v1025 = v1014[v1016][(v1023 + (v1022 * 8))][v1024][v1018];	// L1865
                v1015[v1016][(v1023 + (v1022 * 8))][v1024][0] = v1025;	// L1866
              }
            }
          }
          if (v1018 >= 0) {	// L1870
            int8_t v1026[64];	// L1871
            #pragma HLS bind_storage variable=v1026 type=ram_2p impl=bram

            for (int v1027 = 0; v1027 < 64; v1027 += 1) {	// L1872
              v1026[v1027] = (int8_t)0.000000;	// L1873
              for (int v1028 = 0; v1028 < 1; v1028 += 1) {	// L1874
                #pragma HLS pipeline II=1
                for (int v1029 = 0; v1029 < 32; v1029 += 1) {	// L1875
                  for (int v1030 = 0; v1030 < 1; v1030 += 1) {	// L1876
                    for (int v1031 = 0; v1031 < 1; v1031 += 1) {	// L1877
                      int8_t v1032 = v1015[v1016][(v1029 + (v1028 * 32))][v1030][v1031];	// L1878
                      int8_t v1033 = v1011[v1027][(v1029 + (v1028 * 32))][v1030][v1031];	// L1879
                      int8_t v1034 = v1032 * v1033;	// L1880
                      int8_t v1035 = v1026[v1027];	// L1881
                      int8_t v1036 = v1035 + v1034;	// L1882
                      v1026[v1027] = v1036;	// L1883
                    }
                  }
                }
              }
              int8_t v1037 = v1026[v1027];	// L1888
              v1013[v1016][v1027][v1017][v1018] = v1037;	// L1889
            }
          }
        }
      }
    }
  }
  for (int v1038 = 0; v1038 < 1; v1038 += 1) {	// L1896
    for (int v1039 = 0; v1039 < 112; v1039 += 1) {	// L1897
      for (int v1040 = 0; v1040 < 112; v1040 += 1) {	// L1898
        for (int v1041 = 0; v1041 < 64; v1041 += 1) {	// L1899
          int8_t v1042 = v1013[0][v1041][v1039][v1040];	// L1900
          bool v1043 = v1042 > (int8_t)0.000000;	// L1901
          int8_t v1044 = v1043 ? v1042 : (int8_t)0.000000;	// L1902
          v1012[v1038][v1041][v1039][v1040] = v1044;	// L1903
        }
      }
    }
  }
  return ;	// L1908
}

void main_graph_node30(
  int8_t v1045[1][32][112][112],
  int8_t v1046[32][3][3],
  int8_t v1047[1][32][112][112]
) {	// L1910
  #pragma HLS dataflow

  int8_t v1048[1][32][114][114];	// L1912
  #pragma HLS stream variable=v1048 depth=10 type=fifo

  #pragma HLS array_partition variable=v1048 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1048 type=ram_t2p impl=bram

  for (int v1049 = 0; v1049 < 1; v1049 += 1) {	// L1913
    for (int v1050 = 0; v1050 < 114; v1050 += 1) {	// L1914
      for (int v1051 = 0; v1051 < 114; v1051 += 1) {	// L1915
        for (int v1052 = 0; v1052 < 2; v1052 += 1) {	// L1916
          #pragma HLS pipeline II=1
          for (int v1053 = 0; v1053 < 16; v1053 += 1) {	// L1917
            int8_t v1054;	// L1918
            v1054 = (int8_t)0.000000;	// L1919
            if (((-v1050) + 111) >= 0 && ((-v1051) + 111) >= 0) {	// L1920
              int8_t v1055 = v1045[v1049][(v1053 + (v1052 * 16))][v1050][v1051];	// L1921
              v1054 = v1055;	// L1922
            }
            int8_t v1056 = v1054;	// L1924
            v1048[v1049][(v1053 + (v1052 * 16))][v1050][v1051] = v1056;	// L1925
          }
        }
      }
    }
  }
  int8_t v1057[1][32][112][112];	// L1931
  #pragma HLS stream variable=v1057 depth=10 type=fifo

  #pragma HLS array_partition variable=v1057 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1057 type=ram_t2p impl=bram

  int8_t v1058[1][32][3][114];	// L1932
  #pragma HLS array_partition variable=v1058 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1058 type=ram_2p impl=lutram

  int8_t v1059[1][32][3][3];	// L1933
  #pragma HLS array_partition variable=v1059 cyclic factor=8 dim=2
  #pragma HLS array_partition variable=v1059 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1059 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1059 type=ram_2p impl=lutram

  for (int v1060 = 0; v1060 < 1; v1060 += 1) {	// L1934
    for (int v1061 = 0; v1061 < 114; v1061 += 1) {	// L1935
      for (int v1062 = 0; v1062 < 114; v1062 += 1) {	// L1936
        for (int v1063 = 0; v1063 < 2; v1063 += 1) {	// L1937
          #pragma HLS pipeline II=1
          for (int v1064 = 0; v1064 < 16; v1064 += 1) {	// L1938
            int8_t v1065 = v1058[v1060][(v1064 + (v1063 * 16))][1][v1062];	// L1939
            v1058[v1060][(v1064 + (v1063 * 16))][0][v1062] = v1065;	// L1940
            int8_t v1066 = v1058[v1060][(v1064 + (v1063 * 16))][2][v1062];	// L1941
            v1058[v1060][(v1064 + (v1063 * 16))][1][v1062] = v1066;	// L1942
            int8_t v1067 = v1048[v1060][(v1064 + (v1063 * 16))][v1061][v1062];	// L1943
            v1058[v1060][(v1064 + (v1063 * 16))][2][v1062] = v1067;	// L1944
          }
        }
        if ((v1061 - 2) >= 0) {	// L1947
          for (int v1068 = 0; v1068 < 2; v1068 += 1) {	// L1948
            #pragma HLS pipeline II=1
            for (int v1069 = 0; v1069 < 16; v1069 += 1) {	// L1949
              for (int v1070 = 0; v1070 < 3; v1070 += 1) {	// L1950
                int8_t v1071 = v1059[v1060][(v1069 + (v1068 * 16))][v1070][1];	// L1951
                v1059[v1060][(v1069 + (v1068 * 16))][v1070][0] = v1071;	// L1952
                int8_t v1072 = v1059[v1060][(v1069 + (v1068 * 16))][v1070][2];	// L1953
                v1059[v1060][(v1069 + (v1068 * 16))][v1070][1] = v1072;	// L1954
                int8_t v1073 = v1058[v1060][(v1069 + (v1068 * 16))][v1070][v1062];	// L1955
                v1059[v1060][(v1069 + (v1068 * 16))][v1070][2] = v1073;	// L1956
              }
            }
          }
          if ((v1062 - 2) >= 0) {	// L1960
            int8_t v1074[32];	// L1961
            #pragma HLS array_partition variable=v1074 cyclic factor=8 dim=1
            #pragma HLS bind_storage variable=v1074 type=ram_2p impl=lutram

            for (int v1075 = 0; v1075 < 4; v1075 += 1) {	// L1962
              #pragma HLS pipeline II=1
              for (int v1076 = 0; v1076 < 8; v1076 += 1) {	// L1963
                v1074[(v1076 + (v1075 * 8))] = (int8_t)0.000000;	// L1964
                for (int v1077 = 0; v1077 < 3; v1077 += 1) {	// L1965
                  for (int v1078 = 0; v1078 < 3; v1078 += 1) {	// L1966
                    int8_t v1079 = v1059[v1060][(v1076 + (v1075 * 8))][v1077][v1078];	// L1967
                    int8_t v1080 = v1046[(v1076 + (v1075 * 8))][v1077][v1078];	// L1968
                    int8_t v1081 = v1079 * v1080;	// L1969
                    int8_t v1082 = v1074[(v1076 + (v1075 * 8))];	// L1970
                    int8_t v1083 = v1082 + v1081;	// L1971
                    v1074[(v1076 + (v1075 * 8))] = v1083;	// L1972
                  }
                }
                int8_t v1084 = v1074[(v1076 + (v1075 * 8))];	// L1975
                v1057[v1060][(v1076 + (v1075 * 8))][(v1061 - 2)][(v1062 - 2)] = v1084;	// L1976
              }
            }
          }
        }
      }
    }
  }
  for (int v1085 = 0; v1085 < 1; v1085 += 1) {	// L1984
    for (int v1086 = 0; v1086 < 112; v1086 += 1) {	// L1985
      for (int v1087 = 0; v1087 < 112; v1087 += 1) {	// L1986
        for (int v1088 = 0; v1088 < 4; v1088 += 1) {	// L1987
          #pragma HLS pipeline II=1
          for (int v1089 = 0; v1089 < 8; v1089 += 1) {	// L1988
            int8_t v1090 = v1057[0][(v1089 + (v1088 * 8))][v1086][v1087];	// L1989
            bool v1091 = v1090 > (int8_t)0.000000;	// L1990
            int8_t v1092 = v1091 ? v1090 : (int8_t)0.000000;	// L1991
            v1047[v1085][(v1089 + (v1088 * 8))][v1086][v1087] = v1092;	// L1992
          }
        }
      }
    }
  }
  return ;	// L1998
}

void main_graph_node31(
  int8_t v1093[1][3][224][224],
  int8_t v1094[32][3][3][3],
  int8_t v1095[1][32][112][112]
) {	// L2000
  #pragma HLS dataflow

  int8_t v1096[1][3][226][226];	// L2002
  #pragma HLS stream variable=v1096 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1096 type=ram_t2p impl=bram

  for (int v1097 = 0; v1097 < 1; v1097 += 1) {	// L2003
    for (int v1098 = 0; v1098 < 226; v1098 += 1) {	// L2004
      for (int v1099 = 0; v1099 < 226; v1099 += 1) {	// L2005
        for (int v1100 = 0; v1100 < 3; v1100 += 1) {	// L2006
          int8_t v1101;	// L2007
          v1101 = (int8_t)0.000000;	// L2008
          if (((-v1098) + 223) >= 0 && ((-v1099) + 223) >= 0) {	// L2009
            int8_t v1102 = v1093[v1097][v1100][v1098][v1099];	// L2010
            v1101 = v1102;	// L2011
          }
          int8_t v1103 = v1101;	// L2013
          v1096[v1097][v1100][v1098][v1099] = v1103;	// L2014
        }
      }
    }
  }
  int8_t v1104[1][32][112][112];	// L2019
  #pragma HLS stream variable=v1104 depth=10 type=fifo

  #pragma HLS array_partition variable=v1104 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1104 type=ram_t2p impl=bram

  int8_t v1105[1][3][3][226];	// L2020
  #pragma HLS array_partition variable=v1105 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1105 type=ram_2p impl=lutram

  int8_t v1106[1][3][3][3];	// L2021
  #pragma HLS array_partition variable=v1106 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1106 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1106 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1106 type=ram_2p impl=lutram

  for (int v1107 = 0; v1107 < 1; v1107 += 1) {	// L2022
    for (int v1108 = 0; v1108 < 226; v1108 += 1) {	// L2023
      for (int v1109 = 0; v1109 < 226; v1109 += 1) {	// L2024
        for (int v1110 = 0; v1110 < 3; v1110 += 1) {	// L2025
          int8_t v1111 = v1105[v1107][v1110][1][v1109];	// L2026
          v1105[v1107][v1110][0][v1109] = v1111;	// L2027
          int8_t v1112 = v1105[v1107][v1110][2][v1109];	// L2028
          v1105[v1107][v1110][1][v1109] = v1112;	// L2029
          int8_t v1113 = v1096[v1107][v1110][v1108][v1109];	// L2030
          v1105[v1107][v1110][2][v1109] = v1113;	// L2031
        }
        if ((v1108 - 114) >= 0) {	// L2033
          for (int v1114 = 0; v1114 < 3; v1114 += 1) {	// L2034
            for (int v1115 = 0; v1115 < 3; v1115 += 1) {	// L2035
              int8_t v1116 = v1106[v1107][v1114][v1115][1];	// L2036
              v1106[v1107][v1114][v1115][0] = v1116;	// L2037
              int8_t v1117 = v1106[v1107][v1114][v1115][2];	// L2038
              v1106[v1107][v1114][v1115][1] = v1117;	// L2039
              int8_t v1118 = v1105[v1107][v1114][v1115][v1109];	// L2040
              v1106[v1107][v1114][v1115][2] = v1118;	// L2041
            }
          }
          if ((v1109 - 114) >= 0) {	// L2044
            int8_t v1119[32];	// L2045
            #pragma HLS array_partition variable=v1119 cyclic factor=16 dim=1
            #pragma HLS bind_storage variable=v1119 type=ram_2p impl=lutram

            for (int v1120 = 0; v1120 < 2; v1120 += 1) {	// L2046
              #pragma HLS pipeline II=1
              for (int v1121 = 0; v1121 < 16; v1121 += 1) {	// L2047
                v1119[(v1121 + (v1120 * 16))] = (int8_t)0.000000;	// L2048
                for (int v1122 = 0; v1122 < 3; v1122 += 1) {	// L2049
                  for (int v1123 = 0; v1123 < 3; v1123 += 1) {	// L2050
                    for (int v1124 = 0; v1124 < 3; v1124 += 1) {	// L2051
                      int8_t v1125 = v1106[v1107][v1122][v1123][v1124];	// L2052
                      int8_t v1126 = v1094[(v1121 + (v1120 * 16))][v1122][v1123][v1124];	// L2053
                      int8_t v1127 = v1125 * v1126;	// L2054
                      int8_t v1128 = v1119[(v1121 + (v1120 * 16))];	// L2055
                      int8_t v1129 = v1128 + v1127;	// L2056
                      v1119[(v1121 + (v1120 * 16))] = v1129;	// L2057
                    }
                  }
                }
                int8_t v1130 = v1119[(v1121 + (v1120 * 16))];	// L2061
                v1104[v1107][(v1121 + (v1120 * 16))][(v1108 - 114)][(v1109 - 114)] = v1130;	// L2062
              }
            }
          }
        }
      }
    }
  }
  for (int v1131 = 0; v1131 < 1; v1131 += 1) {	// L2070
    for (int v1132 = 0; v1132 < 112; v1132 += 1) {	// L2071
      for (int v1133 = 0; v1133 < 112; v1133 += 1) {	// L2072
        for (int v1134 = 0; v1134 < 2; v1134 += 1) {	// L2073
          #pragma HLS pipeline II=1
          for (int v1135 = 0; v1135 < 16; v1135 += 1) {	// L2074
            int8_t v1136 = v1104[0][(v1135 + (v1134 * 16))][v1132][v1133];	// L2075
            bool v1137 = v1136 > (int8_t)0.000000;	// L2076
            int8_t v1138 = v1137 ? v1136 : (int8_t)0.000000;	// L2077
            v1095[v1131][(v1135 + (v1134 * 16))][v1132][v1133] = v1138;	// L2078
          }
        }
      }
    }
  }
  return ;	// L2084
}

/// This is top function.
void main_graph(
  int8_t v1139[1][3][224][224],
  int8_t v1140[1000],
  int8_t v1141[1024][1024][1][1],
  int8_t v1142[1024][512][1][1],
  int8_t v1143[512][512][1][1],
  int8_t v1144[512][512][1][1],
  int8_t v1145[512][512][1][1],
  int8_t v1146[512][512][1][1],
  int8_t v1147[512][512][1][1],
  int8_t v1148[512][256][1][1],
  int8_t v1149[256][256][1][1],
  int8_t v1150[256][128][1][1],
  int8_t v1151[128][128][1][1],
  int8_t v1152[128][64][1][1],
  int8_t v1153[64][32][1][1],
  int8_t v1154[32][3][3][3],
  int8_t v1155[32][3][3],
  int8_t v1156[64][3][3],
  int8_t v1157[128][3][3],
  int8_t v1158[128][3][3],
  int8_t v1159[256][3][3],
  int8_t v1160[256][3][3],
  int8_t v1161[512][3][3],
  int8_t v1162[512][3][3],
  int8_t v1163[512][3][3],
  int8_t v1164[512][3][3],
  int8_t v1165[512][3][3],
  int8_t v1166[512][3][3],
  int8_t v1167[1024][3][3],
  int8_t v1168[1024][1000],
  int8_t v1169[1][1000]
) {	// L2086
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v1139 bundle=gmem1
  #pragma HLS bind_storage variable=v1139 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1140 bundle=gmem2
  #pragma HLS bind_storage variable=v1140 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1141 bundle=gmem3
  #pragma HLS array_partition variable=v1141 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1141 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1142 bundle=gmem4
  #pragma HLS array_partition variable=v1142 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1142 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1143 bundle=gmem5
  #pragma HLS array_partition variable=v1143 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1143 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1144 bundle=gmem6
  #pragma HLS array_partition variable=v1144 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1144 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1145 bundle=gmem7
  #pragma HLS array_partition variable=v1145 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1145 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1146 bundle=gmem8
  #pragma HLS array_partition variable=v1146 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1146 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1147 bundle=gmem9
  #pragma HLS array_partition variable=v1147 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1147 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1148 bundle=gmem10
  #pragma HLS array_partition variable=v1148 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1148 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1149 bundle=gmem11
  #pragma HLS array_partition variable=v1149 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1149 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1150 bundle=gmem12
  #pragma HLS array_partition variable=v1150 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1150 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1151 bundle=gmem13
  #pragma HLS array_partition variable=v1151 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1151 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1152 bundle=gmem14
  #pragma HLS array_partition variable=v1152 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1152 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1153 bundle=gmem15
  #pragma HLS array_partition variable=v1153 cyclic factor=32 dim=2
  #pragma HLS bind_storage variable=v1153 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1154 bundle=gmem16
  #pragma HLS array_partition variable=v1154 cyclic factor=16 dim=1
  #pragma HLS array_partition variable=v1154 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1154 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v1154 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v1154 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1155 bundle=gmem17
  #pragma HLS array_partition variable=v1155 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1155 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1155 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1155 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1156 bundle=gmem18
  #pragma HLS array_partition variable=v1156 cyclic factor=16 dim=1
  #pragma HLS array_partition variable=v1156 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1156 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1156 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1157 bundle=gmem19
  #pragma HLS array_partition variable=v1157 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1157 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1157 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1157 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1158 bundle=gmem20
  #pragma HLS array_partition variable=v1158 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v1158 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1158 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1158 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1159 bundle=gmem21
  #pragma HLS array_partition variable=v1159 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1159 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1159 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1160 bundle=gmem22
  #pragma HLS array_partition variable=v1160 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1160 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1160 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1161 bundle=gmem23
  #pragma HLS array_partition variable=v1161 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1161 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1161 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1162 bundle=gmem24
  #pragma HLS array_partition variable=v1162 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1162 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1162 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1163 bundle=gmem25
  #pragma HLS array_partition variable=v1163 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1163 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1163 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1164 bundle=gmem26
  #pragma HLS array_partition variable=v1164 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1164 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1164 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1165 bundle=gmem27
  #pragma HLS array_partition variable=v1165 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1165 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1165 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1166 bundle=gmem28
  #pragma HLS array_partition variable=v1166 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1166 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1166 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v1167 bundle=gmem29
  #pragma HLS array_partition variable=v1167 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v1167 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v1167 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1168 bundle=gmem30
  #pragma HLS bind_storage variable=v1168 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v1169 bundle=gmem31
  #pragma HLS bind_storage variable=v1169 type=ram_t2p impl=bram

  #pragma HLS dataflow

  int8_t v1170[1][32][112][112];	// L2088
  #pragma HLS stream variable=v1170 depth=10 type=fifo

  #pragma HLS array_partition variable=v1170 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1170 type=ram_t2p impl=bram

  main_graph_node31(v1139, v1154, v1170);	// L2089
  int8_t v1171[1][32][112][112];	// L2090
  #pragma HLS stream variable=v1171 depth=10 type=fifo

  #pragma HLS array_partition variable=v1171 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1171 type=ram_t2p impl=bram

  main_graph_node30(v1170, v1155, v1171);	// L2091
  int8_t v1172[1][64][112][112];	// L2092
  #pragma HLS stream variable=v1172 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1172 type=ram_t2p impl=bram

  main_graph_node29(v1171, v1153, v1172);	// L2093
  int8_t v1173[1][64][56][56];	// L2094
  #pragma HLS stream variable=v1173 depth=10 type=fifo

  #pragma HLS array_partition variable=v1173 cyclic factor=16 dim=2
  #pragma HLS bind_storage variable=v1173 type=ram_t2p impl=bram

  main_graph_node28(v1172, v1156, v1173);	// L2095
  int8_t v1174[1][128][56][56];	// L2096
  #pragma HLS stream variable=v1174 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1174 type=ram_t2p impl=bram

  main_graph_node27(v1173, v1152, v1174);	// L2097
  int8_t v1175[1][128][56][56];	// L2098
  #pragma HLS stream variable=v1175 depth=10 type=fifo

  #pragma HLS array_partition variable=v1175 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1175 type=ram_t2p impl=bram

  main_graph_node26(v1157, v1174, v1175);	// L2099
  int8_t v1176[1][128][56][56];	// L2100
  #pragma HLS stream variable=v1176 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1176 type=ram_t2p impl=bram

  main_graph_node25(v1151, v1175, v1176);	// L2101
  int8_t v1177[1][128][28][28];	// L2102
  #pragma HLS stream variable=v1177 depth=10 type=fifo

  #pragma HLS array_partition variable=v1177 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v1177 type=ram_t2p impl=bram

  main_graph_node24(v1158, v1176, v1177);	// L2103
  int8_t v1178[1][256][28][28];	// L2104
  #pragma HLS stream variable=v1178 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1178 type=ram_t2p impl=bram

  main_graph_node23(v1177, v1150, v1178);	// L2105
  int8_t v1179[1][256][28][28];	// L2106
  #pragma HLS stream variable=v1179 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1179 type=ram_t2p impl=bram

  main_graph_node22(v1178, v1159, v1179);	// L2107
  int8_t v1180[1][256][28][28];	// L2108
  #pragma HLS stream variable=v1180 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1180 type=ram_t2p impl=bram

  main_graph_node21(v1149, v1179, v1180);	// L2109
  int8_t v1181[1][256][14][14];	// L2110
  #pragma HLS stream variable=v1181 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1181 type=ram_t2p impl=bram

  main_graph_node20(v1160, v1180, v1181);	// L2111
  int8_t v1182[1][512][14][14];	// L2112
  #pragma HLS stream variable=v1182 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1182 type=ram_t2p impl=bram

  main_graph_node19(v1148, v1181, v1182);	// L2113
  int8_t v1183[1][512][14][14];	// L2114
  #pragma HLS stream variable=v1183 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1183 type=ram_t2p impl=bram

  main_graph_node18(v1182, v1161, v1183);	// L2115
  int8_t v1184[1][512][14][14];	// L2116
  #pragma HLS stream variable=v1184 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1184 type=ram_t2p impl=bram

  main_graph_node17(v1147, v1183, v1184);	// L2117
  int8_t v1185[1][512][14][14];	// L2118
  #pragma HLS stream variable=v1185 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1185 type=ram_t2p impl=bram

  main_graph_node16(v1184, v1162, v1185);	// L2119
  int8_t v1186[1][512][14][14];	// L2120
  #pragma HLS stream variable=v1186 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1186 type=ram_t2p impl=bram

  main_graph_node15(v1146, v1185, v1186);	// L2121
  int8_t v1187[1][512][14][14];	// L2122
  #pragma HLS stream variable=v1187 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1187 type=ram_t2p impl=bram

  main_graph_node14(v1163, v1186, v1187);	// L2123
  int8_t v1188[1][512][14][14];	// L2124
  #pragma HLS stream variable=v1188 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1188 type=ram_t2p impl=bram

  main_graph_node13(v1187, v1145, v1188);	// L2125
  int8_t v1189[1][512][14][14];	// L2126
  #pragma HLS stream variable=v1189 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1189 type=ram_t2p impl=bram

  main_graph_node12(v1188, v1164, v1189);	// L2127
  int8_t v1190[1][512][14][14];	// L2128
  #pragma HLS stream variable=v1190 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1190 type=ram_t2p impl=bram

  main_graph_node11(v1189, v1144, v1190);	// L2129
  int8_t v1191[1][512][14][14];	// L2130
  #pragma HLS stream variable=v1191 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1191 type=ram_t2p impl=bram

  main_graph_node10(v1190, v1165, v1191);	// L2131
  int8_t v1192[1][512][14][14];	// L2132
  #pragma HLS stream variable=v1192 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1192 type=ram_t2p impl=bram

  main_graph_node9(v1143, v1191, v1192);	// L2133
  int8_t v1193[1][512][7][7];	// L2134
  #pragma HLS stream variable=v1193 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1193 type=ram_t2p impl=bram

  main_graph_node8(v1192, v1166, v1193);	// L2135
  int8_t v1194[1][1024][7][7];	// L2136
  #pragma HLS stream variable=v1194 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1194 type=ram_t2p impl=bram

  main_graph_node7(v1142, v1193, v1194);	// L2137
  int8_t v1195[1][1024][7][7];	// L2138
  #pragma HLS stream variable=v1195 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1195 type=ram_t2p impl=bram

  main_graph_node6(v1194, v1167, v1195);	// L2139
  int8_t v1196[1][1024][7][7];	// L2140
  #pragma HLS stream variable=v1196 depth=10 type=fifo

  #pragma HLS bind_storage variable=v1196 type=ram_t2p impl=bram

  main_graph_node5(v1195, v1141, v1196);	// L2141
  int8_t v1197[1][1024][8][8];	// L2142
  #pragma HLS bind_storage variable=v1197 type=ram_t2p impl=bram

  main_graph_node4(v1196, v1197);	// L2143
  int8_t v1198[1][1];	// L2144
  #pragma HLS bind_storage variable=v1198 type=ram_t2p impl=bram

  int8_t v1199[1][1024][1][1];	// L2145
  #pragma HLS bind_storage variable=v1199 type=ram_t2p impl=bram

  main_graph_node3(v1197, v1198, v1199);	// L2146
  int8_t v1200[1][1024][1][1];	// L2147
  #pragma HLS bind_storage variable=v1200 type=ram_t2p impl=bram

  main_graph_node2(v1199, v1198, v1200);	// L2148
  int8_t v1201[1][1000];	// L2149
  #pragma HLS bind_storage variable=v1201 type=ram_t2p impl=bram

  main_graph_node1(v1200, v1168, v1201);	// L2150
  main_graph_node0(v1201, v1140, v1169);	// L2151
  return ;	// L2152
}

