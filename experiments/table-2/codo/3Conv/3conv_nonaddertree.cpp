
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
  float v0[32][32][3][3],
  float v1[1][32][32][32],
  float v2[1][32][32][32]
) {	// L5
  #pragma HLS dataflow

  float v3[1][32][34][34];	// L7
  #pragma HLS stream variable=v3 depth=10 type=fifo

  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  for (int v4 = 0; v4 < 1; v4 += 1) {	// L8
    for (int v5 = 0; v5 < 34; v5 += 1) {	// L9
      for (int v6 = 0; v6 < 34; v6 += 1) {	// L10
        for (int v7 = 0; v7 < 32; v7 += 1) {	// L11
          float v8;	// L12
          v8 = (float)0.000000;	// L13
          if (((-v5) + 31) >= 0 && ((-v6) + 31) >= 0) {	// L14
            float v9 = v1[v4][v7][v5][v6];	// L15
            v8 = v9;	// L16
          }
          float v10 = v8;	// L18
          v3[v4][v7][v5][v6] = v10;	// L19
        }
      }
    }
  }
  float v11[1][32][32][32];	// L24
  #pragma HLS stream variable=v11 depth=10 type=fifo

  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  float v12[1][32][3][34];	// L25
  #pragma HLS array_partition variable=v12 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v12 type=ram_2p impl=bram

  float v13[1][32][3][3];	// L26
  #pragma HLS array_partition variable=v13 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v13 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v13 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v13 type=ram_2p impl=lutram

  for (int v14 = 0; v14 < 1; v14 += 1) {	// L27
    for (int v15 = 0; v15 < 34; v15 += 1) {	// L28
      for (int v16 = 0; v16 < 34; v16 += 1) {	// L29
        for (int v17 = 0; v17 < 32; v17 += 1) {	// L30
          float v18 = v12[v14][v17][1][v16];	// L31
          v12[v14][v17][0][v16] = v18;	// L32
          float v19 = v12[v14][v17][2][v16];	// L33
          v12[v14][v17][1][v16] = v19;	// L34
          float v20 = v3[v14][v17][v15][v16];	// L35
          v12[v14][v17][2][v16] = v20;	// L36
        }
        if ((v15 - 2) >= 0) {	// L38
          for (int v21 = 0; v21 < 32; v21 += 1) {	// L39
            for (int v22 = 0; v22 < 3; v22 += 1) {	// L40
              float v23 = v13[v14][v21][v22][1];	// L41
              v13[v14][v21][v22][0] = v23;	// L42
              float v24 = v13[v14][v21][v22][2];	// L43
              v13[v14][v21][v22][1] = v24;	// L44
              float v25 = v12[v14][v21][v22][v16];	// L45
              v13[v14][v21][v22][2] = v25;	// L46
            }
          }
          if ((v16 - 2) >= 0) {	// L49
            float v26[32];	// L50
            #pragma HLS bind_storage variable=v26 type=ram_2p impl=bram

            for (int v27 = 0; v27 < 32; v27 += 1) {	// L51
              v26[v27] = (float)0.000000;	// L52
              for (int v28 = 0; v28 < 2; v28 += 1) {	// L53
                #pragma HLS pipeline II=1
                for (int v29 = 0; v29 < 16; v29 += 1) {	// L54
                  for (int v30 = 0; v30 < 3; v30 += 1) {	// L55
                    for (int v31 = 0; v31 < 3; v31 += 1) {	// L56
                      float v32 = v13[v14][(v29 + (v28 * 16))][v30][v31];	// L57
                      float v33 = v0[v27][(v29 + (v28 * 16))][v30][v31];	// L58
                      float v34 = v32 * v33;	// L59
                      float v35 = v26[v27];	// L60
                      float v36 = v35 + v34;	// L61
                      v26[v27] = v36;	// L62
                    }
                  }
                }
              }
              float v37 = v26[v27];	// L67
              v11[v14][v27][(v15 - 2)][(v16 - 2)] = v37;	// L68
            }
          }
        }
      }
    }
  }
  for (int v38 = 0; v38 < 1; v38 += 1) {	// L75
    for (int v39 = 0; v39 < 32; v39 += 1) {	// L76
      for (int v40 = 0; v40 < 32; v40 += 1) {	// L77
        for (int v41 = 0; v41 < 32; v41 += 1) {	// L78
          float v42 = v11[0][v41][v39][v40];	// L79
          bool v43 = v42 > (float)0.000000;	// L80
          float v44 = v43 ? v42 : (float)0.000000;	// L81
          v2[v38][v41][v39][v40] = v44;	// L82
        }
      }
    }
  }
  return ;	// L87
}

void main_graph_node1(
  float v45[32][32][3][3],
  float v46[1][32][32][32],
  float v47[1][32][32][32]
) {	// L89
  #pragma HLS dataflow

  float v48[1][32][34][34];	// L91
  #pragma HLS stream variable=v48 depth=10 type=fifo

  #pragma HLS bind_storage variable=v48 type=ram_t2p impl=bram

  for (int v49 = 0; v49 < 1; v49 += 1) {	// L92
    for (int v50 = 0; v50 < 34; v50 += 1) {	// L93
      for (int v51 = 0; v51 < 34; v51 += 1) {	// L94
        for (int v52 = 0; v52 < 32; v52 += 1) {	// L95
          float v53;	// L96
          v53 = (float)0.000000;	// L97
          if (((-v50) + 31) >= 0 && ((-v51) + 31) >= 0) {	// L98
            float v54 = v46[v49][v52][v50][v51];	// L99
            v53 = v54;	// L100
          }
          float v55 = v53;	// L102
          v48[v49][v52][v50][v51] = v55;	// L103
        }
      }
    }
  }
  float v56[1][32][32][32];	// L108
  #pragma HLS stream variable=v56 depth=10 type=fifo

  #pragma HLS bind_storage variable=v56 type=ram_t2p impl=bram

  float v57[1][32][3][34];	// L109
  #pragma HLS array_partition variable=v57 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v57 type=ram_2p impl=bram

  float v58[1][32][3][3];	// L110
  #pragma HLS array_partition variable=v58 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v58 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v58 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v58 type=ram_2p impl=lutram

  for (int v59 = 0; v59 < 1; v59 += 1) {	// L111
    for (int v60 = 0; v60 < 34; v60 += 1) {	// L112
      for (int v61 = 0; v61 < 34; v61 += 1) {	// L113
        for (int v62 = 0; v62 < 32; v62 += 1) {	// L114
          float v63 = v57[v59][v62][1][v61];	// L115
          v57[v59][v62][0][v61] = v63;	// L116
          float v64 = v57[v59][v62][2][v61];	// L117
          v57[v59][v62][1][v61] = v64;	// L118
          float v65 = v48[v59][v62][v60][v61];	// L119
          v57[v59][v62][2][v61] = v65;	// L120
        }
        if ((v60 - 2) >= 0) {	// L122
          for (int v66 = 0; v66 < 32; v66 += 1) {	// L123
            for (int v67 = 0; v67 < 3; v67 += 1) {	// L124
              float v68 = v58[v59][v66][v67][1];	// L125
              v58[v59][v66][v67][0] = v68;	// L126
              float v69 = v58[v59][v66][v67][2];	// L127
              v58[v59][v66][v67][1] = v69;	// L128
              float v70 = v57[v59][v66][v67][v61];	// L129
              v58[v59][v66][v67][2] = v70;	// L130
            }
          }
          if ((v61 - 2) >= 0) {	// L133
            float v71[32];	// L134
            #pragma HLS bind_storage variable=v71 type=ram_2p impl=bram

            for (int v72 = 0; v72 < 32; v72 += 1) {	// L135
              v71[v72] = (float)0.000000;	// L136
              for (int v73 = 0; v73 < 2; v73 += 1) {	// L137
                #pragma HLS pipeline II=1
                for (int v74 = 0; v74 < 16; v74 += 1) {	// L138
                  for (int v75 = 0; v75 < 3; v75 += 1) {	// L139
                    for (int v76 = 0; v76 < 3; v76 += 1) {	// L140
                      float v77 = v58[v59][(v74 + (v73 * 16))][v75][v76];	// L141
                      float v78 = v45[v72][(v74 + (v73 * 16))][v75][v76];	// L142
                      float v79 = v77 * v78;	// L143
                      float v80 = v71[v72];	// L144
                      float v81 = v80 + v79;	// L145
                      v71[v72] = v81;	// L146
                    }
                  }
                }
              }
              float v82 = v71[v72];	// L151
              v56[v59][v72][(v60 - 2)][(v61 - 2)] = v82;	// L152
            }
          }
        }
      }
    }
  }
  for (int v83 = 0; v83 < 1; v83 += 1) {	// L159
    for (int v84 = 0; v84 < 32; v84 += 1) {	// L160
      for (int v85 = 0; v85 < 32; v85 += 1) {	// L161
        for (int v86 = 0; v86 < 32; v86 += 1) {	// L162
          float v87 = v56[0][v86][v84][v85];	// L163
          bool v88 = v87 > (float)0.000000;	// L164
          float v89 = v88 ? v87 : (float)0.000000;	// L165
          v47[v83][v86][v84][v85] = v89;	// L166
        }
      }
    }
  }
  return ;	// L171
}

void main_graph_node2(
  float v90[1][3][32][32],
  float v91[32][3][3][3],
  float v92[1][32][32][32]
) {	// L173
  #pragma HLS dataflow

  float v93[1][3][34][34];	// L175
  #pragma HLS stream variable=v93 depth=10 type=fifo

  #pragma HLS bind_storage variable=v93 type=ram_t2p impl=bram

  for (int v94 = 0; v94 < 1; v94 += 1) {	// L176
    for (int v95 = 0; v95 < 34; v95 += 1) {	// L177
      for (int v96 = 0; v96 < 34; v96 += 1) {	// L178
        for (int v97 = 0; v97 < 3; v97 += 1) {	// L179
          float v98;	// L180
          v98 = (float)0.000000;	// L181
          if (((-v95) + 31) >= 0 && ((-v96) + 31) >= 0) {	// L182
            float v99 = v90[v94][v97][v95][v96];	// L183
            v98 = v99;	// L184
          }
          float v100 = v98;	// L186
          v93[v94][v97][v95][v96] = v100;	// L187
        }
      }
    }
  }
  float v101[1][32][32][32];	// L192
  #pragma HLS stream variable=v101 depth=10 type=fifo

  #pragma HLS bind_storage variable=v101 type=ram_t2p impl=bram

  float v102[1][3][3][34];	// L193
  #pragma HLS array_partition variable=v102 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v102 type=ram_2p impl=lutram

  float v103[1][3][3][3];	// L194
  #pragma HLS array_partition variable=v103 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v103 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v103 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v103 type=ram_2p impl=lutram

  for (int v104 = 0; v104 < 1; v104 += 1) {	// L195
    for (int v105 = 0; v105 < 34; v105 += 1) {	// L196
      for (int v106 = 0; v106 < 34; v106 += 1) {	// L197
        for (int v107 = 0; v107 < 3; v107 += 1) {	// L198
          float v108 = v102[v104][v107][1][v106];	// L199
          v102[v104][v107][0][v106] = v108;	// L200
          float v109 = v102[v104][v107][2][v106];	// L201
          v102[v104][v107][1][v106] = v109;	// L202
          float v110 = v93[v104][v107][v105][v106];	// L203
          v102[v104][v107][2][v106] = v110;	// L204
        }
        if ((v105 - 2) >= 0) {	// L206
          for (int v111 = 0; v111 < 3; v111 += 1) {	// L207
            for (int v112 = 0; v112 < 3; v112 += 1) {	// L208
              float v113 = v103[v104][v111][v112][1];	// L209
              v103[v104][v111][v112][0] = v113;	// L210
              float v114 = v103[v104][v111][v112][2];	// L211
              v103[v104][v111][v112][1] = v114;	// L212
              float v115 = v102[v104][v111][v112][v106];	// L213
              v103[v104][v111][v112][2] = v115;	// L214
            }
          }
          if ((v106 - 2) >= 0) {	// L217
            float v116[32];	// L218
            #pragma HLS bind_storage variable=v116 type=ram_2p impl=bram

            for (int v117 = 0; v117 < 32; v117 += 1) {	// L219
              #pragma HLS pipeline II=1
              for (int v118 = 0; v118 < 1; v118 += 1) {	// L220
                v116[(v117 + v118)] = (float)0.000000;	// L221
                for (int v119 = 0; v119 < 3; v119 += 1) {	// L222
                  for (int v120 = 0; v120 < 3; v120 += 1) {	// L223
                    for (int v121 = 0; v121 < 3; v121 += 1) {	// L224
                      float v122 = v103[v104][v119][v120][v121];	// L225
                      float v123 = v91[(v117 + v118)][v119][v120][v121];	// L226
                      float v124 = v122 * v123;	// L227
                      float v125 = v116[(v117 + v118)];	// L228
                      float v126 = v125 + v124;	// L229
                      v116[(v117 + v118)] = v126;	// L230
                    }
                  }
                }
                float v127 = v116[(v117 + v118)];	// L234
                v101[v104][(v117 + v118)][(v105 - 2)][(v106 - 2)] = v127;	// L235
              }
            }
          }
        }
      }
    }
  }
  for (int v128 = 0; v128 < 1; v128 += 1) {	// L243
    for (int v129 = 0; v129 < 32; v129 += 1) {	// L244
      for (int v130 = 0; v130 < 32; v130 += 1) {	// L245
        for (int v131 = 0; v131 < 32; v131 += 1) {	// L246
          float v132 = v101[0][v131][v129][v130];	// L247
          bool v133 = v132 > (float)0.000000;	// L248
          float v134 = v133 ? v132 : (float)0.000000;	// L249
          v92[v128][v131][v129][v130] = v134;	// L250
        }
      }
    }
  }
  return ;	// L255
}

/// This is top function.
void main_graph(
  float v135[1][3][32][32],
  float v136[32][3][3][3],
  float v137[32][32][3][3],
  float v138[32][32][3][3],
  float v139[1][32][32][32]
) {	// L257
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v135 bundle=gmem1
  #pragma HLS bind_storage variable=v135 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v136 bundle=gmem2
  #pragma HLS array_partition variable=v136 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v136 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v136 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v136 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v137 bundle=gmem3
  #pragma HLS array_partition variable=v137 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v137 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v137 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v137 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v138 bundle=gmem4
  #pragma HLS array_partition variable=v138 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v138 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v138 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v138 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v139 bundle=gmem5
  #pragma HLS bind_storage variable=v139 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v140[1][32][32][32];	// L259
  #pragma HLS stream variable=v140 depth=10 type=fifo

  #pragma HLS bind_storage variable=v140 type=ram_t2p impl=bram

  main_graph_node2(v135, v136, v140);	// L260
  float v141[1][32][32][32];	// L261
  #pragma HLS stream variable=v141 depth=10 type=fifo

  #pragma HLS bind_storage variable=v141 type=ram_t2p impl=bram

  main_graph_node1(v137, v140, v141);	// L262
  main_graph_node0(v138, v141, v139);	// L263
  return ;	// L264
}

