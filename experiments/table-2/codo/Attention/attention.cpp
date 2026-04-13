
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
  float v0[1][16][512],
  float v1[512],
  float v2[1][16][512]
) {	// L8
  #pragma HLS dataflow

  float v3[512];	// L9
  #pragma HLS array_partition variable=v3 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=lutram

  for (int v4 = 0; v4 < 1; v4 += 1) {	// L10
    for (int v5 = 0; v5 < 8; v5 += 1) {	// L11
      for (int v6 = 0; v6 < 128; v6 += 1) {	// L12
        #pragma HLS pipeline II=1
        for (int v7 = 0; v7 < 1; v7 += 1) {	// L13
          for (int v8 = 0; v8 < 2; v8 += 1) {	// L14
            for (int v9 = 0; v9 < 4; v9 += 1) {	// L15
              float v10 = v0[0][(v8 + (v5 * 2))][(v9 + (v6 * 4))];	// L16
              if ((v8 + (v5 * 2)) == 0) {	// L17
                float v11 = v1[(v9 + (v6 * 4))];	// L18
                v3[(v9 + (v6 * 4))] = v11;	// L19
              }
              float v12 = v3[(v9 + (v6 * 4))];	// L21
              float v13 = v10 + v12;	// L22
              v2[(v4 + v7)][(v8 + (v5 * 2))][(v9 + (v6 * 4))] = v13;	// L23
            }
          }
        }
      }
    }
  }
  return ;	// L30
}

void main_graph_node1(
  float v14[512][512],
  float v15[1][8][16][64],
  float v16[1][16][512]
) {	// L32
  #pragma HLS dataflow

  float v17[1][16][512];	// L34
  #pragma HLS stream variable=v17 depth=10 type=fifo

  #pragma HLS array_partition variable=v17 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v17 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v17 type=ram_2p impl=bram

  float v18[1][16][512];	// L35
  #pragma HLS array_partition variable=v18 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v18 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v18 type=ram_2p impl=bram

  float v19[1][16][8][64];	// L36
  #pragma HLS stream variable=v19 depth=10 type=fifo

  #pragma HLS array_partition variable=v19 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v19 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v19 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v19 type=ram_t2p impl=bram

  for (int v20 = 0; v20 < 1; v20 += 1) {	// L37
    for (int v21 = 0; v21 < 4; v21 += 1) {	// L38
      for (int v22 = 0; v22 < 8; v22 += 1) {	// L39
        for (int v23 = 0; v23 < 32; v23 += 1) {	// L40
          #pragma HLS pipeline II=1
          for (int v24 = 0; v24 < 1; v24 += 1) {	// L41
            for (int v25 = 0; v25 < 2; v25 += 1) {	// L42
              for (int v26 = 0; v26 < 2; v26 += 1) {	// L43
                for (int v27 = 0; v27 < 2; v27 += 1) {	// L44
                  float v28 = v15[(v20 + v24)][(v25 + (v21 * 2))][(v26 + (v22 * 2))][(v27 + (v23 * 2))];	// L45
                  v19[(v20 + v24)][(v26 + (v22 * 2))][(v25 + (v21 * 2))][(v27 + (v23 * 2))] = v28;	// L46
                }
              }
            }
          }
        }
      }
    }
  }
  float v29[1][16][512];	// L55
  #pragma HLS stream variable=v29 depth=10 type=fifo

  #pragma HLS array_partition variable=v29 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v29 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v29 type=ram_t2p impl=bram

  float v30[1][16][512];	// L56
  #pragma HLS array_partition variable=v30 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v30 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v30 type=ram_2p impl=bram

  for (int v31 = 0; v31 < 1; v31 += 1) {	// L57
    for (int v32 = 0; v32 < 8; v32 += 1) {	// L58
      for (int v33 = 0; v33 < 128; v33 += 1) {	// L59
        #pragma HLS pipeline II=1
        for (int v34 = 0; v34 < 1; v34 += 1) {	// L60
          for (int v35 = 0; v35 < 2; v35 += 1) {	// L61
            for (int v36 = 0; v36 < 4; v36 += 1) {	// L62
              float v37 = v19[0][(v35 + (v32 * 2))][(v33 / 16)][((v36 + (v33 * 4)) % 64)];	// L63
              v29[(v31 + v34)][(v35 + (v32 * 2))][(v36 + (v33 * 4))] = v37;	// L64
            }
          }
        }
      }
    }
  }
  for (int v38 = 0; v38 < 1; v38 += 1) {	// L71
    for (int v39 = 0; v39 < 8; v39 += 1) {	// L72
      for (int v40 = 0; v40 < 128; v40 += 1) {	// L73
        #pragma HLS pipeline II=1
        for (int v41 = 0; v41 < 1; v41 += 1) {	// L74
          for (int v42 = 0; v42 < 2; v42 += 1) {	// L75
            for (int v43 = 0; v43 < 4; v43 += 1) {	// L76
              v17[(v38 + v41)][(v42 + (v39 * 2))][(v43 + (v40 * 4))] = (float)0.000000;	// L77
            }
          }
        }
      }
    }
  }
  for (int v44 = 0; v44 < 1; v44 += 1) {	// L84
    for (int v45 = 0; v45 < 8; v45 += 1) {	// L85
      for (int v46 = 0; v46 < 128; v46 += 1) {	// L86
        for (int v47 = 0; v47 < 128; v47 += 1) {	// L87
          #pragma HLS pipeline II=1
          for (int v48 = 0; v48 < 1; v48 += 1) {	// L88
            for (int v49 = 0; v49 < 2; v49 += 1) {	// L89
              for (int v50 = 0; v50 < 4; v50 += 1) {	// L90
                for (int v51 = 0; v51 < 4; v51 += 1) {	// L91
                  if ((v51 + (v47 * 4)) == 0) {	// L92
                    float v52 = v29[(v44 + v48)][(v49 + (v45 * 2))][(v50 + (v46 * 4))];	// L93
                    v30[(v44 + v48)][(v49 + (v45 * 2))][(v50 + (v46 * 4))] = v52;	// L94
                  }
                  float v53 = v30[(v44 + v48)][(v49 + (v45 * 2))][(v50 + (v46 * 4))];	// L96
                  float v54 = v14[(v50 + (v46 * 4))][(v51 + (v47 * 4))];	// L97
                  if ((v50 + (v46 * 4)) == 0) {	// L98
                    float v55 = v17[(v44 + v48)][(v49 + (v45 * 2))][(v51 + (v47 * 4))];	// L99
                    v18[(v44 + v48)][(v49 + (v45 * 2))][(v51 + (v47 * 4))] = v55;	// L100
                  }
                  float v56 = v18[(v44 + v48)][(v49 + (v45 * 2))][(v51 + (v47 * 4))];	// L102
                  float v57 = v53 * v54;	// L103
                  float v58 = v56 + v57;	// L104
                  v18[(v44 + v48)][(v49 + (v45 * 2))][(v51 + (v47 * 4))] = v58;	// L105
                  if (((v50 + (v46 * 4)) - 511) == 0) {	// L106
                    float v59 = v18[(v44 + v48)][(v49 + (v45 * 2))][(v51 + (v47 * 4))];	// L107
                    v16[(v44 + v48)][(v49 + (v45 * 2))][(v51 + (v47 * 4))] = v59;	// L108
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L118
}

void main_graph_node2(
  float v60[1][8][16][16],
  float v61[1][8][16][1],
  float v62[1][16][512],
  float v63[1][8][16][64],
  float v64[1][8][16][64]
) {	// L120
  #pragma HLS dataflow

  float v65[1][16][512];	// L121
  #pragma HLS array_partition variable=v65 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v65 block factor=128 dim=3
  #pragma HLS bind_storage variable=v65 type=ram_2p impl=bram

  float v66[1][8][16][1];	// L122
  #pragma HLS array_partition variable=v66 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v66 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v66 type=ram_2p impl=lutram

  float v67[1][8][16][16];	// L123
  #pragma HLS array_partition variable=v67 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v67 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v67 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v67 type=ram_2p impl=lutram

  float v68[1][8][16][64];	// L124
  #pragma HLS stream variable=v68 depth=10 type=fifo

  #pragma HLS array_partition variable=v68 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v68 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v68 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v68 type=ram_2p impl=bram

  float v69[1][8][16][64];	// L125
  #pragma HLS array_partition variable=v69 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v69 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v69 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v69 type=ram_2p impl=bram

  for (int v70 = 0; v70 < 1; v70 += 1) {	// L126
    for (int v71 = 0; v71 < 4; v71 += 1) {	// L127
      for (int v72 = 0; v72 < 8; v72 += 1) {	// L128
        for (int v73 = 0; v73 < 32; v73 += 1) {	// L129
          #pragma HLS pipeline II=1
          for (int v74 = 0; v74 < 1; v74 += 1) {	// L130
            for (int v75 = 0; v75 < 2; v75 += 1) {	// L131
              for (int v76 = 0; v76 < 2; v76 += 1) {	// L132
                for (int v77 = 0; v77 < 2; v77 += 1) {	// L133
                  float v78 = v63[(v70 + v74)][(v75 + (v71 * 2))][(v76 + (v72 * 2))][(v77 + (v73 * 2))];	// L134
                  v68[(v70 + v74)][(v75 + (v71 * 2))][(v76 + (v72 * 2))][(v77 + (v73 * 2))] = v78;	// L135
                }
              }
            }
          }
        }
      }
    }
  }
  for (int v79 = 0; v79 < 1; v79 += 1) {	// L144
    for (int v80 = 0; v80 < 4; v80 += 1) {	// L145
      for (int v81 = 0; v81 < 8; v81 += 1) {	// L146
        for (int v82 = 0; v82 < 8; v82 += 1) {	// L147
          for (int v83 = 0; v83 < 32; v83 += 1) {	// L148
            #pragma HLS pipeline II=1
            for (int v84 = 0; v84 < 1; v84 += 1) {	// L149
              for (int v85 = 0; v85 < 2; v85 += 1) {	// L150
                for (int v86 = 0; v86 < 2; v86 += 1) {	// L151
                  for (int v87 = 0; v87 < 2; v87 += 1) {	// L152
                    for (int v88 = 0; v88 < 2; v88 += 1) {	// L153
                      if ((v88 + (v83 * 2)) == 0) {	// L154
                        float v89 = v60[0][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v87 + (v82 * 2))];	// L155
                        v67[0][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v87 + (v82 * 2))] = v89;	// L156
                      }
                      float v90 = v67[0][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v87 + (v82 * 2))];	// L158
                      if ((v88 + (v83 * 2)) == 0) {	// L159
                        float v91 = v61[0][(v85 + (v80 * 2))][(v86 + (v81 * 2))][0];	// L160
                        v66[0][(v85 + (v80 * 2))][(v86 + (v81 * 2))][0] = v91;	// L161
                      }
                      float v92 = v66[0][(v85 + (v80 * 2))][(v86 + (v81 * 2))][0];	// L163
                      if ((v86 + (v81 * 2)) == 0) {	// L164
                        float v93 = v62[0][(v87 + (v82 * 2))][((((v85 * 64) + (v80 * 128)) + v88) + (v83 * 2))];	// L165
                        v65[0][(v87 + (v82 * 2))][((((v85 * 64) + (v80 * 128)) + v88) + (v83 * 2))] = v93;	// L166
                      }
                      float v94 = v65[0][(v87 + (v82 * 2))][((((v85 * 64) + (v80 * 128)) + v88) + (v83 * 2))];	// L168
                      if ((v87 + (v82 * 2)) == 0) {	// L169
                        float v95 = v68[(v79 + v84)][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v88 + (v83 * 2))];	// L170
                        v69[(v79 + v84)][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v88 + (v83 * 2))] = v95;	// L171
                      }
                      float v96 = v69[(v79 + v84)][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v88 + (v83 * 2))];	// L173
                      float v97 = v90 / v92;	// L174
                      float v98 = v97 * v94;	// L175
                      float v99 = v96 + v98;	// L176
                      v69[(v79 + v84)][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v88 + (v83 * 2))] = v99;	// L177
                      if (((v87 + (v82 * 2)) - 15) == 0) {	// L178
                        float v100 = v69[(v79 + v84)][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v88 + (v83 * 2))];	// L179
                        v64[(v79 + v84)][(v85 + (v80 * 2))][(v86 + (v81 * 2))][(v88 + (v83 * 2))] = v100;	// L180
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L192
}

void main_graph_node3(
  float v101[1][8][16][64]
) {	// L194
  #pragma HLS dataflow

  for (int v102 = 0; v102 < 1; v102 += 1) {	// L196
    for (int v103 = 0; v103 < 4; v103 += 1) {	// L197
      for (int v104 = 0; v104 < 8; v104 += 1) {	// L198
        for (int v105 = 0; v105 < 32; v105 += 1) {	// L199
          #pragma HLS pipeline II=1
          for (int v106 = 0; v106 < 1; v106 += 1) {	// L200
            for (int v107 = 0; v107 < 2; v107 += 1) {	// L201
              for (int v108 = 0; v108 < 2; v108 += 1) {	// L202
                for (int v109 = 0; v109 < 2; v109 += 1) {	// L203
                  v101[(v102 + v106)][(v107 + (v103 * 2))][(v108 + (v104 * 2))][(v109 + (v105 * 2))] = (float)0.000000;	// L204
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L213
}

void main_graph_node4(
  float v110[1][8][16][16],
  float v111[1][8][16][1]
) {	// L215
  #pragma HLS dataflow

  float v112[1][8][16][1];	// L217
  #pragma HLS stream variable=v112 depth=10 type=fifo

  #pragma HLS array_partition variable=v112 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v112 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v112 type=ram_2p impl=lutram

  float v113[1][8][16][1];	// L218
  #pragma HLS array_partition variable=v113 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v113 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v113 type=ram_2p impl=lutram

  for (int v114 = 0; v114 < 1; v114 += 1) {	// L219
    for (int v115 = 0; v115 < 4; v115 += 1) {	// L220
      for (int v116 = 0; v116 < 8; v116 += 1) {	// L221
        for (int v117 = 0; v117 < 1; v117 += 1) {	// L222
          #pragma HLS pipeline II=1
          for (int v118 = 0; v118 < 1; v118 += 1) {	// L223
            for (int v119 = 0; v119 < 2; v119 += 1) {	// L224
              for (int v120 = 0; v120 < 2; v120 += 1) {	// L225
                for (int v121 = 0; v121 < 1; v121 += 1) {	// L226
                  v112[(v114 + v118)][(v119 + (v115 * 2))][(v120 + (v116 * 2))][(v117 + v121)] = (float)0.000000;	// L227
                }
              }
            }
          }
        }
      }
    }
  }
  for (int v122 = 0; v122 < 1; v122 += 1) {	// L236
    for (int v123 = 0; v123 < 4; v123 += 1) {	// L237
      for (int v124 = 0; v124 < 8; v124 += 1) {	// L238
        for (int v125 = 0; v125 < 8; v125 += 1) {	// L239
          #pragma HLS pipeline II=1
          for (int v126 = 0; v126 < 1; v126 += 1) {	// L240
            for (int v127 = 0; v127 < 2; v127 += 1) {	// L241
              for (int v128 = 0; v128 < 2; v128 += 1) {	// L242
                for (int v129 = 0; v129 < 2; v129 += 1) {	// L243
                  float v130 = v110[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][(v128 + (v124 * 2))];	// L244
                  if ((v128 + (v124 * 2)) == 0) {	// L245
                    float v131 = v112[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][0];	// L246
                    v113[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][0] = v131;	// L247
                  }
                  float v132 = v113[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][0];	// L249
                  float v133 = v130 + v132;	// L250
                  v113[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][0] = v133;	// L251
                  if (((v128 + (v124 * 2)) - 15) == 0) {	// L252
                    float v134 = v113[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][0];	// L253
                    v111[(v122 + v126)][(v127 + (v123 * 2))][(v129 + (v125 * 2))][0] = v134;	// L254
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L264
}

void main_graph_node5(
  float v135[1][8][16][16],
  float v136[1][8][16][16],
  float v137[1][8][16][16]
) {	// L266
  #pragma HLS dataflow

  for (int v138 = 0; v138 < 1; v138 += 1) {	// L267
    for (int v139 = 0; v139 < 4; v139 += 1) {	// L268
      for (int v140 = 0; v140 < 8; v140 += 1) {	// L269
        for (int v141 = 0; v141 < 8; v141 += 1) {	// L270
          #pragma HLS pipeline II=1
          for (int v142 = 0; v142 < 1; v142 += 1) {	// L271
            for (int v143 = 0; v143 < 2; v143 += 1) {	// L272
              for (int v144 = 0; v144 < 2; v144 += 1) {	// L273
                for (int v145 = 0; v145 < 2; v145 += 1) {	// L274
                  float v146 = v135[(v138 + v142)][(v143 + (v139 * 2))][(v144 + (v140 * 2))][(v145 + (v141 * 2))];	// L275
                  v136[(v138 + v142)][(v143 + (v139 * 2))][(v144 + (v140 * 2))][(v145 + (v141 * 2))] = v146;	// L276
                  v137[(v138 + v142)][(v143 + (v139 * 2))][(v144 + (v140 * 2))][(v145 + (v141 * 2))] = v146;	// L277
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L286
}

void main_graph_node6(
  float v147[1][8][16][16],
  float v148[1][8][16][1],
  float v149[1][8][16][16]
) {	// L288
  #pragma HLS dataflow

  float v150[1][8][16][1];	// L289
  #pragma HLS array_partition variable=v150 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v150 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v150 type=ram_2p impl=lutram

  for (int v151 = 0; v151 < 1; v151 += 1) {	// L290
    for (int v152 = 0; v152 < 4; v152 += 1) {	// L291
      for (int v153 = 0; v153 < 8; v153 += 1) {	// L292
        for (int v154 = 0; v154 < 8; v154 += 1) {	// L293
          #pragma HLS pipeline II=1
          for (int v155 = 0; v155 < 1; v155 += 1) {	// L294
            for (int v156 = 0; v156 < 2; v156 += 1) {	// L295
              for (int v157 = 0; v157 < 2; v157 += 1) {	// L296
                for (int v158 = 0; v158 < 2; v158 += 1) {	// L297
                  float v159 = v147[0][(v156 + (v152 * 2))][(v157 + (v153 * 2))][(v158 + (v154 * 2))];	// L298
                  if ((v158 + (v154 * 2)) == 0) {	// L299
                    float v160 = v148[0][(v156 + (v152 * 2))][(v157 + (v153 * 2))][0];	// L300
                    v150[0][(v156 + (v152 * 2))][(v157 + (v153 * 2))][0] = v160;	// L301
                  }
                  float v161 = v150[0][(v156 + (v152 * 2))][(v157 + (v153 * 2))][0];	// L303
                  float v162 = v159 - v161;	// L304
                  float v163 = exp(v162);	// L305
                  v149[(v151 + v155)][(v156 + (v152 * 2))][(v157 + (v153 * 2))][(v158 + (v154 * 2))] = v163;	// L306
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L315
}

void main_graph_node7(
  float v164[1][8][16][16],
  float v165[1][8][16][1]
) {	// L317
  #pragma HLS dataflow

  float v166[1][8][16][1];	// L319
  #pragma HLS stream variable=v166 depth=10 type=fifo

  #pragma HLS array_partition variable=v166 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v166 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v166 type=ram_2p impl=lutram

  float v167[1][8][16][1];	// L320
  #pragma HLS array_partition variable=v167 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v167 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v167 type=ram_2p impl=lutram

  for (int v168 = 0; v168 < 1; v168 += 1) {	// L321
    for (int v169 = 0; v169 < 4; v169 += 1) {	// L322
      for (int v170 = 0; v170 < 8; v170 += 1) {	// L323
        for (int v171 = 0; v171 < 1; v171 += 1) {	// L324
          #pragma HLS pipeline II=1
          for (int v172 = 0; v172 < 1; v172 += 1) {	// L325
            for (int v173 = 0; v173 < 2; v173 += 1) {	// L326
              for (int v174 = 0; v174 < 2; v174 += 1) {	// L327
                for (int v175 = 0; v175 < 1; v175 += 1) {	// L328
                  v166[(v168 + v172)][(v173 + (v169 * 2))][(v174 + (v170 * 2))][(v171 + v175)] = (float)-INFINITY;	// L329
                }
              }
            }
          }
        }
      }
    }
  }
  for (int v176 = 0; v176 < 1; v176 += 1) {	// L338
    for (int v177 = 0; v177 < 4; v177 += 1) {	// L339
      for (int v178 = 0; v178 < 8; v178 += 1) {	// L340
        for (int v179 = 0; v179 < 8; v179 += 1) {	// L341
          #pragma HLS pipeline II=1
          for (int v180 = 0; v180 < 1; v180 += 1) {	// L342
            for (int v181 = 0; v181 < 2; v181 += 1) {	// L343
              for (int v182 = 0; v182 < 2; v182 += 1) {	// L344
                for (int v183 = 0; v183 < 2; v183 += 1) {	// L345
                  float v184 = v164[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][(v182 + (v178 * 2))];	// L346
                  if ((v182 + (v178 * 2)) == 0) {	// L347
                    float v185 = v166[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][0];	// L348
                    v167[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][0] = v185;	// L349
                  }
                  float v186 = v167[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][0];	// L351
                  float v187 = max(v184, v186);	// L352
                  v167[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][0] = v187;	// L353
                  if (((v182 + (v178 * 2)) - 15) == 0) {	// L354
                    float v188 = v167[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][0];	// L355
                    v165[(v176 + v180)][(v181 + (v177 * 2))][(v183 + (v179 * 2))][0] = v188;	// L356
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L366
}

void main_graph_node8(
  float v189[1][8][16][16],
  float v190[1][8][16][16],
  float v191[1][8][16][16]
) {	// L368
  #pragma HLS dataflow

  for (int v192 = 0; v192 < 1; v192 += 1) {	// L369
    for (int v193 = 0; v193 < 4; v193 += 1) {	// L370
      for (int v194 = 0; v194 < 8; v194 += 1) {	// L371
        for (int v195 = 0; v195 < 8; v195 += 1) {	// L372
          #pragma HLS pipeline II=1
          for (int v196 = 0; v196 < 1; v196 += 1) {	// L373
            for (int v197 = 0; v197 < 2; v197 += 1) {	// L374
              for (int v198 = 0; v198 < 2; v198 += 1) {	// L375
                for (int v199 = 0; v199 < 2; v199 += 1) {	// L376
                  float v200 = v189[(v192 + v196)][(v197 + (v193 * 2))][(v198 + (v194 * 2))][(v199 + (v195 * 2))];	// L377
                  v190[(v192 + v196)][(v197 + (v193 * 2))][(v198 + (v194 * 2))][(v199 + (v195 * 2))] = v200;	// L378
                  v191[(v192 + v196)][(v197 + (v193 * 2))][(v198 + (v194 * 2))][(v199 + (v195 * 2))] = v200;	// L379
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L388
}

void main_graph_node9(
  float v201[1][8][16][16],
  float v202[1][8][16][16]
) {	// L390
  #pragma HLS dataflow

  for (int v203 = 0; v203 < 1; v203 += 1) {	// L392
    for (int v204 = 0; v204 < 4; v204 += 1) {	// L393
      for (int v205 = 0; v205 < 8; v205 += 1) {	// L394
        for (int v206 = 0; v206 < 8; v206 += 1) {	// L395
          #pragma HLS pipeline II=1
          for (int v207 = 0; v207 < 1; v207 += 1) {	// L396
            for (int v208 = 0; v208 < 2; v208 += 1) {	// L397
              for (int v209 = 0; v209 < 2; v209 += 1) {	// L398
                for (int v210 = 0; v210 < 2; v210 += 1) {	// L399
                  float v211 = v201[0][(v208 + (v204 * 2))][(v209 + (v205 * 2))][(v210 + (v206 * 2))];	// L400
                  float v212 = v211 * (float)0.125000;	// L401
                  v202[(v203 + v207)][(v208 + (v204 * 2))][(v209 + (v205 * 2))][(v210 + (v206 * 2))] = v212;	// L402
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L411
}

void main_graph_node10(
  float v213[1][8][16][16],
  float v214[1][16][512],
  float v215[1][16][512],
  float v216[1][8][16][16]
) {	// L413
  #pragma HLS dataflow

  float v217[1][16][512];	// L414
  #pragma HLS array_partition variable=v217 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v217 block factor=128 dim=3
  #pragma HLS bind_storage variable=v217 type=ram_2p impl=bram

  float v218[1][16][512];	// L415
  #pragma HLS array_partition variable=v218 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v218 block factor=128 dim=3
  #pragma HLS bind_storage variable=v218 type=ram_2p impl=bram

  float v219[1][8][16][16];	// L416
  #pragma HLS stream variable=v219 depth=10 type=fifo

  #pragma HLS array_partition variable=v219 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v219 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v219 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v219 type=ram_2p impl=lutram

  float v220[1][8][16][16];	// L417
  #pragma HLS array_partition variable=v220 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v220 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v220 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v220 type=ram_2p impl=lutram

  for (int v221 = 0; v221 < 1; v221 += 1) {	// L418
    for (int v222 = 0; v222 < 4; v222 += 1) {	// L419
      for (int v223 = 0; v223 < 8; v223 += 1) {	// L420
        for (int v224 = 0; v224 < 8; v224 += 1) {	// L421
          #pragma HLS pipeline II=1
          for (int v225 = 0; v225 < 1; v225 += 1) {	// L422
            for (int v226 = 0; v226 < 2; v226 += 1) {	// L423
              for (int v227 = 0; v227 < 2; v227 += 1) {	// L424
                for (int v228 = 0; v228 < 2; v228 += 1) {	// L425
                  float v229 = v213[(v221 + v225)][(v226 + (v222 * 2))][(v227 + (v223 * 2))][(v228 + (v224 * 2))];	// L426
                  v219[(v221 + v225)][(v226 + (v222 * 2))][(v227 + (v223 * 2))][(v228 + (v224 * 2))] = v229;	// L427
                }
              }
            }
          }
        }
      }
    }
  }
  for (int v230 = 0; v230 < 1; v230 += 1) {	// L436
    for (int v231 = 0; v231 < 4; v231 += 1) {	// L437
      for (int v232 = 0; v232 < 8; v232 += 1) {	// L438
        for (int v233 = 0; v233 < 32; v233 += 1) {	// L439
          for (int v234 = 0; v234 < 8; v234 += 1) {	// L440
            #pragma HLS pipeline II=1
            for (int v235 = 0; v235 < 1; v235 += 1) {	// L441
              for (int v236 = 0; v236 < 2; v236 += 1) {	// L442
                for (int v237 = 0; v237 < 2; v237 += 1) {	// L443
                  for (int v238 = 0; v238 < 2; v238 += 1) {	// L444
                    for (int v239 = 0; v239 < 2; v239 += 1) {	// L445
                      if ((v239 + (v234 * 2)) == 0) {	// L446
                        float v240 = v215[0][(v237 + (v232 * 2))][((((v236 * 64) + (v231 * 128)) + v238) + (v233 * 2))];	// L447
                        v218[0][(v237 + (v232 * 2))][((((v236 * 64) + (v231 * 128)) + v238) + (v233 * 2))] = v240;	// L448
                      }
                      float v241 = v218[0][(v237 + (v232 * 2))][((((v236 * 64) + (v231 * 128)) + v238) + (v233 * 2))];	// L450
                      if ((v237 + (v232 * 2)) == 0) {	// L451
                        float v242 = v214[0][(v239 + (v234 * 2))][((((v236 * 64) + (v231 * 128)) + v238) + (v233 * 2))];	// L452
                        v217[0][(v239 + (v234 * 2))][((((v236 * 64) + (v231 * 128)) + v238) + (v233 * 2))] = v242;	// L453
                      }
                      float v243 = v217[0][(v239 + (v234 * 2))][((((v236 * 64) + (v231 * 128)) + v238) + (v233 * 2))];	// L455
                      if ((v238 + (v233 * 2)) == 0) {	// L456
                        float v244 = v219[(v230 + v235)][(v236 + (v231 * 2))][(v237 + (v232 * 2))][(v239 + (v234 * 2))];	// L457
                        v220[(v230 + v235)][(v236 + (v231 * 2))][(v237 + (v232 * 2))][(v239 + (v234 * 2))] = v244;	// L458
                      }
                      float v245 = v220[(v230 + v235)][(v236 + (v231 * 2))][(v237 + (v232 * 2))][(v239 + (v234 * 2))];	// L460
                      float v246 = v241 * v243;	// L461
                      float v247 = v245 + v246;	// L462
                      v220[(v230 + v235)][(v236 + (v231 * 2))][(v237 + (v232 * 2))][(v239 + (v234 * 2))] = v247;	// L463
                      if (((v238 + (v233 * 2)) - 63) == 0) {	// L464
                        float v248 = v220[(v230 + v235)][(v236 + (v231 * 2))][(v237 + (v232 * 2))][(v239 + (v234 * 2))];	// L465
                        v216[(v230 + v235)][(v236 + (v231 * 2))][(v237 + (v232 * 2))][(v239 + (v234 * 2))] = v248;	// L466
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L478
}

void main_graph_node11(
  float v249[1][8][16][16]
) {	// L480
  #pragma HLS dataflow

  for (int v250 = 0; v250 < 1; v250 += 1) {	// L482
    for (int v251 = 0; v251 < 4; v251 += 1) {	// L483
      for (int v252 = 0; v252 < 8; v252 += 1) {	// L484
        for (int v253 = 0; v253 < 8; v253 += 1) {	// L485
          #pragma HLS pipeline II=1
          for (int v254 = 0; v254 < 1; v254 += 1) {	// L486
            for (int v255 = 0; v255 < 2; v255 += 1) {	// L487
              for (int v256 = 0; v256 < 2; v256 += 1) {	// L488
                for (int v257 = 0; v257 < 2; v257 += 1) {	// L489
                  v249[(v250 + v254)][(v255 + (v251 * 2))][(v256 + (v252 * 2))][(v257 + (v253 * 2))] = (float)0.000000;	// L490
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L499
}

void main_graph_node12(
  float v258[1][16][512],
  float v259[512],
  float v260[1][16][512]
) {	// L501
  #pragma HLS dataflow

  float v261[512];	// L502
  #pragma HLS array_partition variable=v261 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v261 type=ram_2p impl=lutram

  for (int v262 = 0; v262 < 1; v262 += 1) {	// L503
    for (int v263 = 0; v263 < 8; v263 += 1) {	// L504
      for (int v264 = 0; v264 < 128; v264 += 1) {	// L505
        #pragma HLS pipeline II=1
        for (int v265 = 0; v265 < 1; v265 += 1) {	// L506
          for (int v266 = 0; v266 < 2; v266 += 1) {	// L507
            for (int v267 = 0; v267 < 4; v267 += 1) {	// L508
              float v268 = v258[0][(v266 + (v263 * 2))][(v267 + (v264 * 4))];	// L509
              if ((v266 + (v263 * 2)) == 0) {	// L510
                float v269 = v259[(v267 + (v264 * 4))];	// L511
                v261[(v267 + (v264 * 4))] = v269;	// L512
              }
              float v270 = v261[(v267 + (v264 * 4))];	// L514
              float v271 = v268 + v270;	// L515
              v260[(v262 + v265)][(v266 + (v263 * 2))][(v267 + (v264 * 4))] = v271;	// L516
            }
          }
        }
      }
    }
  }
  return ;	// L523
}

void main_graph_node13(
  float v272[1][16][512],
  float v273[512][512],
  float v274[1][16][512]
) {	// L525
  #pragma HLS dataflow

  float v275[1][16][512];	// L527
  #pragma HLS array_partition variable=v275 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v275 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v275 type=ram_2p impl=bram

  float v276[1][16][512];	// L528
  #pragma HLS stream variable=v276 depth=10 type=fifo

  #pragma HLS array_partition variable=v276 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v276 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v276 type=ram_2p impl=bram

  float v277[1][16][512];	// L529
  #pragma HLS array_partition variable=v277 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v277 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v277 type=ram_2p impl=bram

  for (int v278 = 0; v278 < 1; v278 += 1) {	// L530
    for (int v279 = 0; v279 < 8; v279 += 1) {	// L531
      for (int v280 = 0; v280 < 128; v280 += 1) {	// L532
        #pragma HLS pipeline II=1
        for (int v281 = 0; v281 < 1; v281 += 1) {	// L533
          for (int v282 = 0; v282 < 2; v282 += 1) {	// L534
            for (int v283 = 0; v283 < 4; v283 += 1) {	// L535
              v276[(v278 + v281)][(v282 + (v279 * 2))][(v283 + (v280 * 4))] = (float)0.000000;	// L536
            }
          }
        }
      }
    }
  }
  for (int v284 = 0; v284 < 1; v284 += 1) {	// L543
    for (int v285 = 0; v285 < 8; v285 += 1) {	// L544
      for (int v286 = 0; v286 < 128; v286 += 1) {	// L545
        for (int v287 = 0; v287 < 128; v287 += 1) {	// L546
          #pragma HLS pipeline II=1
          for (int v288 = 0; v288 < 1; v288 += 1) {	// L547
            for (int v289 = 0; v289 < 2; v289 += 1) {	// L548
              for (int v290 = 0; v290 < 4; v290 += 1) {	// L549
                for (int v291 = 0; v291 < 4; v291 += 1) {	// L550
                  if ((v291 + (v287 * 4)) == 0) {	// L551
                    float v292 = v272[(v284 + v288)][(v289 + (v285 * 2))][(v290 + (v286 * 4))];	// L552
                    v275[(v284 + v288)][(v289 + (v285 * 2))][(v290 + (v286 * 4))] = v292;	// L553
                  }
                  float v293 = v275[(v284 + v288)][(v289 + (v285 * 2))][(v290 + (v286 * 4))];	// L555
                  float v294 = v273[(v290 + (v286 * 4))][(v291 + (v287 * 4))];	// L556
                  if ((v290 + (v286 * 4)) == 0) {	// L557
                    float v295 = v276[(v284 + v288)][(v289 + (v285 * 2))][(v291 + (v287 * 4))];	// L558
                    v277[(v284 + v288)][(v289 + (v285 * 2))][(v291 + (v287 * 4))] = v295;	// L559
                  }
                  float v296 = v277[(v284 + v288)][(v289 + (v285 * 2))][(v291 + (v287 * 4))];	// L561
                  float v297 = v293 * v294;	// L562
                  float v298 = v296 + v297;	// L563
                  v277[(v284 + v288)][(v289 + (v285 * 2))][(v291 + (v287 * 4))] = v298;	// L564
                  if (((v290 + (v286 * 4)) - 511) == 0) {	// L565
                    float v299 = v277[(v284 + v288)][(v289 + (v285 * 2))][(v291 + (v287 * 4))];	// L566
                    v274[(v284 + v288)][(v289 + (v285 * 2))][(v291 + (v287 * 4))] = v299;	// L567
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L577
}

void main_graph_node14(
  float v300[1][16][512],
  float v301[512],
  float v302[1][16][512]
) {	// L579
  #pragma HLS dataflow

  float v303[512];	// L580
  #pragma HLS array_partition variable=v303 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v303 type=ram_2p impl=lutram

  for (int v304 = 0; v304 < 1; v304 += 1) {	// L581
    for (int v305 = 0; v305 < 8; v305 += 1) {	// L582
      for (int v306 = 0; v306 < 128; v306 += 1) {	// L583
        #pragma HLS pipeline II=1
        for (int v307 = 0; v307 < 1; v307 += 1) {	// L584
          for (int v308 = 0; v308 < 2; v308 += 1) {	// L585
            for (int v309 = 0; v309 < 4; v309 += 1) {	// L586
              float v310 = v300[0][(v308 + (v305 * 2))][(v309 + (v306 * 4))];	// L587
              if ((v308 + (v305 * 2)) == 0) {	// L588
                float v311 = v301[(v309 + (v306 * 4))];	// L589
                v303[(v309 + (v306 * 4))] = v311;	// L590
              }
              float v312 = v303[(v309 + (v306 * 4))];	// L592
              float v313 = v310 + v312;	// L593
              v302[(v304 + v307)][(v308 + (v305 * 2))][(v309 + (v306 * 4))] = v313;	// L594
            }
          }
        }
      }
    }
  }
  return ;	// L601
}

void main_graph_node15(
  float v314[512][512],
  float v315[1][16][512],
  float v316[1][16][512]
) {	// L603
  #pragma HLS dataflow

  float v317[1][16][512];	// L605
  #pragma HLS array_partition variable=v317 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v317 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v317 type=ram_2p impl=bram

  float v318[1][16][512];	// L606
  #pragma HLS stream variable=v318 depth=10 type=fifo

  #pragma HLS array_partition variable=v318 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v318 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v318 type=ram_2p impl=bram

  float v319[1][16][512];	// L607
  #pragma HLS array_partition variable=v319 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v319 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v319 type=ram_2p impl=bram

  for (int v320 = 0; v320 < 1; v320 += 1) {	// L608
    for (int v321 = 0; v321 < 8; v321 += 1) {	// L609
      for (int v322 = 0; v322 < 128; v322 += 1) {	// L610
        #pragma HLS pipeline II=1
        for (int v323 = 0; v323 < 1; v323 += 1) {	// L611
          for (int v324 = 0; v324 < 2; v324 += 1) {	// L612
            for (int v325 = 0; v325 < 4; v325 += 1) {	// L613
              v318[(v320 + v323)][(v324 + (v321 * 2))][(v325 + (v322 * 4))] = (float)0.000000;	// L614
            }
          }
        }
      }
    }
  }
  for (int v326 = 0; v326 < 1; v326 += 1) {	// L621
    for (int v327 = 0; v327 < 8; v327 += 1) {	// L622
      for (int v328 = 0; v328 < 128; v328 += 1) {	// L623
        for (int v329 = 0; v329 < 128; v329 += 1) {	// L624
          #pragma HLS pipeline II=1
          for (int v330 = 0; v330 < 1; v330 += 1) {	// L625
            for (int v331 = 0; v331 < 2; v331 += 1) {	// L626
              for (int v332 = 0; v332 < 4; v332 += 1) {	// L627
                for (int v333 = 0; v333 < 4; v333 += 1) {	// L628
                  if ((v333 + (v329 * 4)) == 0) {	// L629
                    float v334 = v315[(v326 + v330)][(v331 + (v327 * 2))][(v332 + (v328 * 4))];	// L630
                    v317[(v326 + v330)][(v331 + (v327 * 2))][(v332 + (v328 * 4))] = v334;	// L631
                  }
                  float v335 = v317[(v326 + v330)][(v331 + (v327 * 2))][(v332 + (v328 * 4))];	// L633
                  float v336 = v314[(v332 + (v328 * 4))][(v333 + (v329 * 4))];	// L634
                  if ((v332 + (v328 * 4)) == 0) {	// L635
                    float v337 = v318[(v326 + v330)][(v331 + (v327 * 2))][(v333 + (v329 * 4))];	// L636
                    v319[(v326 + v330)][(v331 + (v327 * 2))][(v333 + (v329 * 4))] = v337;	// L637
                  }
                  float v338 = v319[(v326 + v330)][(v331 + (v327 * 2))][(v333 + (v329 * 4))];	// L639
                  float v339 = v335 * v336;	// L640
                  float v340 = v338 + v339;	// L641
                  v319[(v326 + v330)][(v331 + (v327 * 2))][(v333 + (v329 * 4))] = v340;	// L642
                  if (((v332 + (v328 * 4)) - 511) == 0) {	// L643
                    float v341 = v319[(v326 + v330)][(v331 + (v327 * 2))][(v333 + (v329 * 4))];	// L644
                    v316[(v326 + v330)][(v331 + (v327 * 2))][(v333 + (v329 * 4))] = v341;	// L645
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L655
}

void main_graph_node16(
  float v342[1][16][512],
  float v343[512],
  float v344[1][16][512]
) {	// L657
  #pragma HLS dataflow

  float v345[512];	// L658
  #pragma HLS array_partition variable=v345 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v345 type=ram_2p impl=lutram

  for (int v346 = 0; v346 < 1; v346 += 1) {	// L659
    for (int v347 = 0; v347 < 8; v347 += 1) {	// L660
      for (int v348 = 0; v348 < 128; v348 += 1) {	// L661
        #pragma HLS pipeline II=1
        for (int v349 = 0; v349 < 1; v349 += 1) {	// L662
          for (int v350 = 0; v350 < 2; v350 += 1) {	// L663
            for (int v351 = 0; v351 < 4; v351 += 1) {	// L664
              float v352 = v342[0][(v350 + (v347 * 2))][(v351 + (v348 * 4))];	// L665
              if ((v350 + (v347 * 2)) == 0) {	// L666
                float v353 = v343[(v351 + (v348 * 4))];	// L667
                v345[(v351 + (v348 * 4))] = v353;	// L668
              }
              float v354 = v345[(v351 + (v348 * 4))];	// L670
              float v355 = v352 + v354;	// L671
              v344[(v346 + v349)][(v350 + (v347 * 2))][(v351 + (v348 * 4))] = v355;	// L672
            }
          }
        }
      }
    }
  }
  return ;	// L679
}

void main_graph_node17(
  float v356[1][16][512],
  float v357[512][512],
  float v358[1][16][512]
) {	// L681
  #pragma HLS dataflow

  float v359[1][16][512];	// L683
  #pragma HLS array_partition variable=v359 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v359 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v359 type=ram_2p impl=bram

  float v360[1][16][512];	// L684
  #pragma HLS stream variable=v360 depth=10 type=fifo

  #pragma HLS array_partition variable=v360 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v360 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v360 type=ram_2p impl=bram

  float v361[1][16][512];	// L685
  #pragma HLS array_partition variable=v361 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v361 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v361 type=ram_2p impl=bram

  for (int v362 = 0; v362 < 1; v362 += 1) {	// L686
    for (int v363 = 0; v363 < 8; v363 += 1) {	// L687
      for (int v364 = 0; v364 < 128; v364 += 1) {	// L688
        #pragma HLS pipeline II=1
        for (int v365 = 0; v365 < 1; v365 += 1) {	// L689
          for (int v366 = 0; v366 < 2; v366 += 1) {	// L690
            for (int v367 = 0; v367 < 4; v367 += 1) {	// L691
              v360[(v362 + v365)][(v366 + (v363 * 2))][(v367 + (v364 * 4))] = (float)0.000000;	// L692
            }
          }
        }
      }
    }
  }
  for (int v368 = 0; v368 < 1; v368 += 1) {	// L699
    for (int v369 = 0; v369 < 8; v369 += 1) {	// L700
      for (int v370 = 0; v370 < 128; v370 += 1) {	// L701
        for (int v371 = 0; v371 < 128; v371 += 1) {	// L702
          #pragma HLS pipeline II=1
          for (int v372 = 0; v372 < 1; v372 += 1) {	// L703
            for (int v373 = 0; v373 < 2; v373 += 1) {	// L704
              for (int v374 = 0; v374 < 4; v374 += 1) {	// L705
                for (int v375 = 0; v375 < 4; v375 += 1) {	// L706
                  if ((v375 + (v371 * 4)) == 0) {	// L707
                    float v376 = v356[(v368 + v372)][(v373 + (v369 * 2))][(v374 + (v370 * 4))];	// L708
                    v359[(v368 + v372)][(v373 + (v369 * 2))][(v374 + (v370 * 4))] = v376;	// L709
                  }
                  float v377 = v359[(v368 + v372)][(v373 + (v369 * 2))][(v374 + (v370 * 4))];	// L711
                  float v378 = v357[(v374 + (v370 * 4))][(v375 + (v371 * 4))];	// L712
                  if ((v374 + (v370 * 4)) == 0) {	// L713
                    float v379 = v360[(v368 + v372)][(v373 + (v369 * 2))][(v375 + (v371 * 4))];	// L714
                    v361[(v368 + v372)][(v373 + (v369 * 2))][(v375 + (v371 * 4))] = v379;	// L715
                  }
                  float v380 = v361[(v368 + v372)][(v373 + (v369 * 2))][(v375 + (v371 * 4))];	// L717
                  float v381 = v377 * v378;	// L718
                  float v382 = v380 + v381;	// L719
                  v361[(v368 + v372)][(v373 + (v369 * 2))][(v375 + (v371 * 4))] = v382;	// L720
                  if (((v374 + (v370 * 4)) - 511) == 0) {	// L721
                    float v383 = v361[(v368 + v372)][(v373 + (v369 * 2))][(v375 + (v371 * 4))];	// L722
                    v358[(v368 + v372)][(v373 + (v369 * 2))][(v375 + (v371 * 4))] = v383;	// L723
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L733
}

void main_graph_node18(
  float v384[1][16][512],
  float v385[1][16][512],
  float v386[1][16][512],
  float v387[1][16][512]
) {	// L735
  #pragma HLS dataflow

  for (int v388 = 0; v388 < 1; v388 += 1) {	// L736
    for (int v389 = 0; v389 < 8; v389 += 1) {	// L737
      for (int v390 = 0; v390 < 128; v390 += 1) {	// L738
        #pragma HLS pipeline II=1
        for (int v391 = 0; v391 < 1; v391 += 1) {	// L739
          for (int v392 = 0; v392 < 2; v392 += 1) {	// L740
            for (int v393 = 0; v393 < 4; v393 += 1) {	// L741
              float v394 = v384[(v388 + v391)][(v392 + (v389 * 2))][(v393 + (v390 * 4))];	// L742
              v385[(v388 + v391)][(v392 + (v389 * 2))][(v393 + (v390 * 4))] = v394;	// L743
              v386[(v388 + v391)][(v392 + (v389 * 2))][(v393 + (v390 * 4))] = v394;	// L744
              v387[(v388 + v391)][(v392 + (v389 * 2))][(v393 + (v390 * 4))] = v394;	// L745
            }
          }
        }
      }
    }
  }
  return ;	// L752
}

void main_graph_node19(
  float v395[1][16][512],
  float v396[1][16][512]
) {	// L754
  #pragma HLS dataflow

  for (int v397 = 0; v397 < 1; v397 += 1) {	// L755
    for (int v398 = 0; v398 < 8; v398 += 1) {	// L756
      for (int v399 = 0; v399 < 128; v399 += 1) {	// L757
        #pragma HLS pipeline II=1
        for (int v400 = 0; v400 < 1; v400 += 1) {	// L758
          for (int v401 = 0; v401 < 2; v401 += 1) {	// L759
            for (int v402 = 0; v402 < 4; v402 += 1) {	// L760
              float v403 = v395[0][(v401 + (v398 * 2))][(v402 + (v399 * 4))];	// L761
              v396[(v397 + v400)][(v401 + (v398 * 2))][(v402 + (v399 * 4))] = v403;	// L762
            }
          }
        }
      }
    }
  }
  return ;	// L769
}

/// This is top function.
void main_graph(
  float v404[1][16][512],
  float v405[512][512],
  float v406[512],
  float v407[512],
  float v408[512],
  float v409[512],
  float v410[512][512],
  float v411[512][512],
  float v412[512][512],
  float v413[1][16][512]
) {	// L771
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v404 bundle=gmem1
  #pragma HLS array_partition variable=v404 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v404 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v404 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v405 bundle=gmem2
  #pragma HLS array_partition variable=v405 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v405 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v405 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v406 bundle=gmem3
  #pragma HLS array_partition variable=v406 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v406 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v407 bundle=gmem4
  #pragma HLS array_partition variable=v407 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v407 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v408 bundle=gmem5
  #pragma HLS array_partition variable=v408 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v408 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v409 bundle=gmem6
  #pragma HLS array_partition variable=v409 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v409 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v410 bundle=gmem7
  #pragma HLS array_partition variable=v410 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v410 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v410 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v411 bundle=gmem8
  #pragma HLS array_partition variable=v411 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v411 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v411 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v412 bundle=gmem9
  #pragma HLS array_partition variable=v412 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v412 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v412 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v413 bundle=gmem10
  #pragma HLS array_partition variable=v413 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v413 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v413 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v414[1][16][512];	// L773
  #pragma HLS stream variable=v414 depth=10 type=fifo

  #pragma HLS array_partition variable=v414 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v414 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v414 type=ram_t2p impl=bram

  main_graph_node19(v404, v414);	// L774
  float v415[1][16][512];	// L775
  #pragma HLS stream variable=v415 depth=10 type=fifo

  #pragma HLS array_partition variable=v415 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v415 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v415 type=ram_t2p impl=bram

  float v416[1][16][512];	// L776
  #pragma HLS stream variable=v416 depth=10 type=fifo

  #pragma HLS array_partition variable=v416 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v416 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v416 type=ram_t2p impl=bram

  float v417[1][16][512];	// L777
  #pragma HLS stream variable=v417 depth=10 type=fifo

  #pragma HLS array_partition variable=v417 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v417 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v417 type=ram_t2p impl=bram

  main_graph_node18(v414, v415, v416, v417);	// L778
  float v418[1][16][512];	// L779
  #pragma HLS stream variable=v418 depth=10 type=fifo

  #pragma HLS array_partition variable=v418 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v418 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v418 type=ram_t2p impl=bram

  main_graph_node17(v417, v405, v418);	// L780
  float v419[1][16][512];	// L781
  #pragma HLS stream variable=v419 depth=10 type=fifo

  #pragma HLS array_partition variable=v419 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v419 block factor=128 dim=3
  #pragma HLS bind_storage variable=v419 type=ram_t2p impl=bram

  main_graph_node16(v418, v406, v419);	// L782
  float v420[1][16][512];	// L783
  #pragma HLS stream variable=v420 depth=10 type=fifo

  #pragma HLS array_partition variable=v420 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v420 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v420 type=ram_t2p impl=bram

  main_graph_node15(v410, v416, v420);	// L784
  float v421[1][16][512];	// L785
  #pragma HLS stream variable=v421 depth=10 type=fifo

  #pragma HLS array_partition variable=v421 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v421 block factor=128 dim=3
  #pragma HLS bind_storage variable=v421 type=ram_t2p impl=bram

  main_graph_node14(v420, v407, v421);	// L786
  float v422[1][16][512];	// L787
  #pragma HLS stream variable=v422 depth=10 type=fifo

  #pragma HLS array_partition variable=v422 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v422 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v422 type=ram_t2p impl=bram

  main_graph_node13(v415, v411, v422);	// L788
  float v423[1][16][512];	// L789
  #pragma HLS stream variable=v423 depth=10 type=fifo

  #pragma HLS array_partition variable=v423 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v423 block factor=128 dim=3
  #pragma HLS bind_storage variable=v423 type=ram_t2p impl=bram

  main_graph_node12(v422, v408, v423);	// L790
  float v424[1][8][16][16];	// L791
  #pragma HLS stream variable=v424 depth=10 type=fifo

  #pragma HLS array_partition variable=v424 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v424 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v424 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v424 type=ram_2p impl=lutram

  main_graph_node11(v424);	// L792
  float v425[1][8][16][16];	// L793
  #pragma HLS stream variable=v425 depth=10 type=fifo

  #pragma HLS array_partition variable=v425 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v425 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v425 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v425 type=ram_2p impl=lutram

  main_graph_node10(v424, v421, v419, v425);	// L794
  float v426[1][8][16][16];	// L795
  #pragma HLS stream variable=v426 depth=10 type=fifo

  #pragma HLS array_partition variable=v426 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v426 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v426 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v426 type=ram_2p impl=lutram

  main_graph_node9(v425, v426);	// L796
  float v427[1][8][16][16];	// L797
  #pragma HLS stream variable=v427 depth=10 type=fifo

  #pragma HLS array_partition variable=v427 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v427 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v427 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v427 type=ram_2p impl=lutram

  float v428[1][8][16][16];	// L798
  #pragma HLS stream variable=v428 depth=10 type=fifo

  #pragma HLS array_partition variable=v428 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v428 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v428 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v428 type=ram_2p impl=lutram

  main_graph_node8(v426, v427, v428);	// L799
  float v429[1][8][16][1];	// L800
  #pragma HLS stream variable=v429 depth=10 type=fifo

  #pragma HLS array_partition variable=v429 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v429 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v429 type=ram_2p impl=lutram

  main_graph_node7(v428, v429);	// L801
  float v430[1][8][16][16];	// L802
  #pragma HLS stream variable=v430 depth=10 type=fifo

  #pragma HLS array_partition variable=v430 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v430 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v430 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v430 type=ram_2p impl=lutram

  main_graph_node6(v427, v429, v430);	// L803
  float v431[1][8][16][16];	// L804
  #pragma HLS stream variable=v431 depth=10 type=fifo

  #pragma HLS array_partition variable=v431 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v431 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v431 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v431 type=ram_2p impl=lutram

  float v432[1][8][16][16];	// L805
  #pragma HLS stream variable=v432 depth=10 type=fifo

  #pragma HLS array_partition variable=v432 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v432 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v432 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v432 type=ram_2p impl=lutram

  main_graph_node5(v430, v431, v432);	// L806
  float v433[1][8][16][1];	// L807
  #pragma HLS stream variable=v433 depth=10 type=fifo

  #pragma HLS array_partition variable=v433 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v433 cyclic factor=2 dim=3
  #pragma HLS bind_storage variable=v433 type=ram_2p impl=lutram

  main_graph_node4(v432, v433);	// L808
  float v434[1][8][16][64];	// L809
  #pragma HLS stream variable=v434 depth=10 type=fifo

  #pragma HLS array_partition variable=v434 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v434 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v434 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v434 type=ram_t2p impl=bram

  main_graph_node3(v434);	// L810
  float v435[1][8][16][64];	// L811
  #pragma HLS stream variable=v435 depth=10 type=fifo

  #pragma HLS array_partition variable=v435 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v435 cyclic factor=2 dim=3
  #pragma HLS array_partition variable=v435 cyclic factor=2 dim=4
  #pragma HLS bind_storage variable=v435 type=ram_t2p impl=bram

  main_graph_node2(v431, v433, v423, v434, v435);	// L812
  float v436[1][16][512];	// L813
  #pragma HLS stream variable=v436 depth=10 type=fifo

  #pragma HLS array_partition variable=v436 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v436 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v436 type=ram_t2p impl=bram

  main_graph_node1(v412, v435, v436);	// L814
  main_graph_node0(v436, v409, v413);	// L815
  return ;	// L816
}

