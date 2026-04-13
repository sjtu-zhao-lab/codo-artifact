
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
  float v0[8][10],
  float v1[10],
  float v2[8][10]
) {	// L9
  #pragma HLS dataflow

  float v3[10];	// L10
  #pragma HLS array_partition variable=v3 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=lutram

  for (int v4 = 0; v4 < 4; v4 += 1) {	// L11
    for (int v5 = 0; v5 < 5; v5 += 1) {	// L12
      #pragma HLS pipeline II=1
      for (int v6 = 0; v6 < 2; v6 += 1) {	// L13
        for (int v7 = 0; v7 < 2; v7 += 1) {	// L14
          float v8 = v0[(v6 + (v4 * 2))][(v7 + (v5 * 2))];	// L15
          if ((v6 + (v4 * 2)) == 0) {	// L16
            float v9 = v1[(v7 + (v5 * 2))];	// L17
            v3[(v7 + (v5 * 2))] = v9;	// L18
          }
          float v10 = v3[(v7 + (v5 * 2))];	// L20
          float v11 = v8 + v10;	// L21
          v2[(v6 + (v4 * 2))][(v7 + (v5 * 2))] = v11;	// L22
        }
      }
    }
  }
  return ;	// L27
}

void main_graph_node1(
  float v12[8][256],
  float v13[256][10],
  float v14[8][10]
) {	// L29
  #pragma HLS dataflow

  float v15[256][10];	// L31
  #pragma HLS array_partition variable=v15 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v15 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v15 type=ram_2p impl=lutram

  float v16[8][256];	// L32
  #pragma HLS array_partition variable=v16 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v16 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v16 type=ram_2p impl=lutram

  float v17[8][10];	// L33
  #pragma HLS stream variable=v17 depth=10 type=fifo

  #pragma HLS array_partition variable=v17 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v17 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v17 type=ram_2p impl=lutram

  float v18[8][10];	// L34
  #pragma HLS array_partition variable=v18 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v18 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v18 type=ram_2p impl=lutram

  for (int v19 = 0; v19 < 4; v19 += 1) {	// L35
    for (int v20 = 0; v20 < 5; v20 += 1) {	// L36
      #pragma HLS pipeline II=1
      for (int v21 = 0; v21 < 2; v21 += 1) {	// L37
        for (int v22 = 0; v22 < 2; v22 += 1) {	// L38
          v17[(v21 + (v19 * 2))][(v22 + (v20 * 2))] = (float)0.000000;	// L39
        }
      }
    }
  }
  for (int v23 = 0; v23 < 4; v23 += 1) {	// L44
    for (int v24 = 0; v24 < 128; v24 += 1) {	// L45
      for (int v25 = 0; v25 < 5; v25 += 1) {	// L46
        #pragma HLS pipeline II=1
        for (int v26 = 0; v26 < 2; v26 += 1) {	// L47
          for (int v27 = 0; v27 < 2; v27 += 1) {	// L48
            for (int v28 = 0; v28 < 2; v28 += 1) {	// L49
              if ((v28 + (v25 * 2)) == 0) {	// L50
                float v29 = v12[(v26 + (v23 * 2))][(v27 + (v24 * 2))];	// L51
                v16[(v26 + (v23 * 2))][(v27 + (v24 * 2))] = v29;	// L52
              }
              float v30 = v16[(v26 + (v23 * 2))][(v27 + (v24 * 2))];	// L54
              if ((v26 + (v23 * 2)) == 0) {	// L55
                float v31 = v13[(v27 + (v24 * 2))][(v28 + (v25 * 2))];	// L56
                v15[(v27 + (v24 * 2))][(v28 + (v25 * 2))] = v31;	// L57
              }
              float v32 = v15[(v27 + (v24 * 2))][(v28 + (v25 * 2))];	// L59
              if ((v27 + (v24 * 2)) == 0) {	// L60
                float v33 = v17[(v26 + (v23 * 2))][(v28 + (v25 * 2))];	// L61
                v18[(v26 + (v23 * 2))][(v28 + (v25 * 2))] = v33;	// L62
              }
              float v34 = v18[(v26 + (v23 * 2))][(v28 + (v25 * 2))];	// L64
              float v35 = v30 * v32;	// L65
              float v36 = v34 + v35;	// L66
              v18[(v26 + (v23 * 2))][(v28 + (v25 * 2))] = v36;	// L67
              if (((v27 + (v24 * 2)) - 255) == 0) {	// L68
                float v37 = v18[(v26 + (v23 * 2))][(v28 + (v25 * 2))];	// L69
                v14[(v26 + (v23 * 2))][(v28 + (v25 * 2))] = v37;	// L70
              }
            }
          }
        }
      }
    }
  }
  return ;	// L78
}

void main_graph_node2(
  float v38[8][256],
  float v39[256],
  float v40[8][256]
) {	// L80
  #pragma HLS dataflow

  float v41[256];	// L81
  #pragma HLS array_partition variable=v41 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v41 type=ram_2p impl=lutram

  for (int v42 = 0; v42 < 4; v42 += 1) {	// L82
    for (int v43 = 0; v43 < 128; v43 += 1) {	// L83
      #pragma HLS pipeline II=1
      for (int v44 = 0; v44 < 2; v44 += 1) {	// L84
        for (int v45 = 0; v45 < 2; v45 += 1) {	// L85
          float v46 = v38[(v44 + (v42 * 2))][(v45 + (v43 * 2))];	// L86
          if ((v44 + (v42 * 2)) == 0) {	// L87
            float v47 = v39[(v45 + (v43 * 2))];	// L88
            v41[(v45 + (v43 * 2))] = v47;	// L89
          }
          float v48 = v41[(v45 + (v43 * 2))];	// L91
          float v49 = v46 + v48;	// L92
          v40[(v44 + (v42 * 2))][(v45 + (v43 * 2))] = v49;	// L93
        }
      }
    }
  }
  return ;	// L98
}

void main_graph_node3(
  float v50[8][512],
  float v51[512][256],
  float v52[8][256]
) {	// L100
  #pragma HLS dataflow

  float v53[512][256];	// L102
  #pragma HLS array_partition variable=v53 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v53 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v53 type=ram_2p impl=bram

  float v54[8][512];	// L103
  #pragma HLS array_partition variable=v54 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v54 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v54 type=ram_2p impl=lutram

  float v55[8][256];	// L104
  #pragma HLS stream variable=v55 depth=10 type=fifo

  #pragma HLS array_partition variable=v55 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v55 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v55 type=ram_2p impl=lutram

  float v56[8][256];	// L105
  #pragma HLS array_partition variable=v56 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v56 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v56 type=ram_2p impl=lutram

  for (int v57 = 0; v57 < 4; v57 += 1) {	// L106
    for (int v58 = 0; v58 < 128; v58 += 1) {	// L107
      #pragma HLS pipeline II=1
      for (int v59 = 0; v59 < 2; v59 += 1) {	// L108
        for (int v60 = 0; v60 < 2; v60 += 1) {	// L109
          v55[(v59 + (v57 * 2))][(v60 + (v58 * 2))] = (float)0.000000;	// L110
        }
      }
    }
  }
  for (int v61 = 0; v61 < 4; v61 += 1) {	// L115
    for (int v62 = 0; v62 < 128; v62 += 1) {	// L116
      for (int v63 = 0; v63 < 128; v63 += 1) {	// L117
        #pragma HLS pipeline II=1
        for (int v64 = 0; v64 < 2; v64 += 1) {	// L118
          for (int v65 = 0; v65 < 4; v65 += 1) {	// L119
            for (int v66 = 0; v66 < 2; v66 += 1) {	// L120
              if ((v66 + (v63 * 2)) == 0) {	// L121
                float v67 = v50[(v64 + (v61 * 2))][(v65 + (v62 * 4))];	// L122
                v54[(v64 + (v61 * 2))][(v65 + (v62 * 4))] = v67;	// L123
              }
              float v68 = v54[(v64 + (v61 * 2))][(v65 + (v62 * 4))];	// L125
              if ((v64 + (v61 * 2)) == 0) {	// L126
                float v69 = v51[(v65 + (v62 * 4))][(v66 + (v63 * 2))];	// L127
                v53[(v65 + (v62 * 4))][(v66 + (v63 * 2))] = v69;	// L128
              }
              float v70 = v53[(v65 + (v62 * 4))][(v66 + (v63 * 2))];	// L130
              if ((v65 + (v62 * 4)) == 0) {	// L131
                float v71 = v55[(v64 + (v61 * 2))][(v66 + (v63 * 2))];	// L132
                v56[(v64 + (v61 * 2))][(v66 + (v63 * 2))] = v71;	// L133
              }
              float v72 = v56[(v64 + (v61 * 2))][(v66 + (v63 * 2))];	// L135
              float v73 = v68 * v70;	// L136
              float v74 = v72 + v73;	// L137
              v56[(v64 + (v61 * 2))][(v66 + (v63 * 2))] = v74;	// L138
              if (((v65 + (v62 * 4)) - 511) == 0) {	// L139
                float v75 = v56[(v64 + (v61 * 2))][(v66 + (v63 * 2))];	// L140
                v52[(v64 + (v61 * 2))][(v66 + (v63 * 2))] = v75;	// L141
              }
            }
          }
        }
      }
    }
  }
  return ;	// L149
}

void main_graph_node4(
  float v76[8][512],
  float v77[512],
  float v78[8][512],
  float v79[8][512]
) {	// L151
  #pragma HLS dataflow

  float v80[512];	// L153
  #pragma HLS array_partition variable=v80 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v80 type=ram_2p impl=lutram

  for (int v81 = 0; v81 < 4; v81 += 1) {	// L154
    for (int v82 = 0; v82 < 128; v82 += 1) {	// L155
      #pragma HLS pipeline II=1
      for (int v83 = 0; v83 < 2; v83 += 1) {	// L156
        for (int v84 = 0; v84 < 4; v84 += 1) {	// L157
          float v85 = v76[(v83 + (v81 * 2))][(v84 + (v82 * 4))];	// L158
          if ((v83 + (v81 * 2)) == 0) {	// L159
            float v86 = v77[(v84 + (v82 * 4))];	// L160
            v80[(v84 + (v82 * 4))] = v86;	// L161
          }
          float v87 = v80[(v84 + (v82 * 4))];	// L163
          float v88 = v78[(v83 + (v81 * 2))][(v84 + (v82 * 4))];	// L164
          float v89 = v85 + v87;	// L165
          float v90 = v89 + v88;	// L166
          bool v91 = v90 > (float)0.000000;	// L167
          float v92 = v91 ? v90 : (float)0.000000;	// L168
          v79[(v83 + (v81 * 2))][(v84 + (v82 * 4))] = v92;	// L169
        }
      }
    }
  }
  return ;	// L174
}

void main_graph_node5(
  float v93[8][512],
  float v94[512][512],
  float v95[8][512]
) {	// L176
  #pragma HLS dataflow

  float v96[512][512];	// L178
  #pragma HLS array_partition variable=v96 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v96 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v96 type=ram_2p impl=bram

  float v97[8][512];	// L179
  #pragma HLS array_partition variable=v97 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v97 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v97 type=ram_2p impl=lutram

  float v98[8][512];	// L180
  #pragma HLS stream variable=v98 depth=10 type=fifo

  #pragma HLS array_partition variable=v98 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v98 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v98 type=ram_2p impl=lutram

  float v99[8][512];	// L181
  #pragma HLS array_partition variable=v99 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v99 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v99 type=ram_2p impl=lutram

  for (int v100 = 0; v100 < 4; v100 += 1) {	// L182
    for (int v101 = 0; v101 < 128; v101 += 1) {	// L183
      #pragma HLS pipeline II=1
      for (int v102 = 0; v102 < 2; v102 += 1) {	// L184
        for (int v103 = 0; v103 < 4; v103 += 1) {	// L185
          v98[(v102 + (v100 * 2))][(v103 + (v101 * 4))] = (float)0.000000;	// L186
        }
      }
    }
  }
  for (int v104 = 0; v104 < 4; v104 += 1) {	// L191
    for (int v105 = 0; v105 < 128; v105 += 1) {	// L192
      for (int v106 = 0; v106 < 128; v106 += 1) {	// L193
        #pragma HLS pipeline II=1
        for (int v107 = 0; v107 < 2; v107 += 1) {	// L194
          for (int v108 = 0; v108 < 4; v108 += 1) {	// L195
            for (int v109 = 0; v109 < 4; v109 += 1) {	// L196
              if ((v109 + (v106 * 4)) == 0) {	// L197
                float v110 = v93[(v107 + (v104 * 2))][(v108 + (v105 * 4))];	// L198
                v97[(v107 + (v104 * 2))][(v108 + (v105 * 4))] = v110;	// L199
              }
              float v111 = v97[(v107 + (v104 * 2))][(v108 + (v105 * 4))];	// L201
              if ((v107 + (v104 * 2)) == 0) {	// L202
                float v112 = v94[(v108 + (v105 * 4))][(v109 + (v106 * 4))];	// L203
                v96[(v108 + (v105 * 4))][(v109 + (v106 * 4))] = v112;	// L204
              }
              float v113 = v96[(v108 + (v105 * 4))][(v109 + (v106 * 4))];	// L206
              if ((v108 + (v105 * 4)) == 0) {	// L207
                float v114 = v98[(v107 + (v104 * 2))][(v109 + (v106 * 4))];	// L208
                v99[(v107 + (v104 * 2))][(v109 + (v106 * 4))] = v114;	// L209
              }
              float v115 = v99[(v107 + (v104 * 2))][(v109 + (v106 * 4))];	// L211
              float v116 = v111 * v113;	// L212
              float v117 = v115 + v116;	// L213
              v99[(v107 + (v104 * 2))][(v109 + (v106 * 4))] = v117;	// L214
              if (((v108 + (v105 * 4)) - 511) == 0) {	// L215
                float v118 = v99[(v107 + (v104 * 2))][(v109 + (v106 * 4))];	// L216
                v95[(v107 + (v104 * 2))][(v109 + (v106 * 4))] = v118;	// L217
              }
            }
          }
        }
      }
    }
  }
  return ;	// L225
}

void main_graph_node6(
  float v119[8][512],
  float v120[8][512]
) {	// L227
  #pragma HLS dataflow

  for (int v121 = 0; v121 < 4; v121 += 1) {	// L229
    for (int v122 = 0; v122 < 128; v122 += 1) {	// L230
      #pragma HLS pipeline II=1
      for (int v123 = 0; v123 < 2; v123 += 1) {	// L231
        for (int v124 = 0; v124 < 4; v124 += 1) {	// L232
          float v125 = v119[(v123 + (v121 * 2))][(v124 + (v122 * 4))];	// L233
          bool v126 = v125 > (float)0.000000;	// L234
          float v127 = v126 ? v125 : (float)0.000000;	// L235
          v120[(v123 + (v121 * 2))][(v124 + (v122 * 4))] = v127;	// L236
        }
      }
    }
  }
  return ;	// L241
}

void main_graph_node7(
  float v128[8][512],
  float v129[8][512],
  float v130[8][512]
) {	// L243
  #pragma HLS dataflow

  for (int v131 = 0; v131 < 4; v131 += 1) {	// L244
    for (int v132 = 0; v132 < 128; v132 += 1) {	// L245
      #pragma HLS pipeline II=1
      for (int v133 = 0; v133 < 2; v133 += 1) {	// L246
        for (int v134 = 0; v134 < 4; v134 += 1) {	// L247
          float v135 = v128[(v133 + (v131 * 2))][(v134 + (v132 * 4))];	// L248
          v129[(v133 + (v131 * 2))][(v134 + (v132 * 4))] = v135;	// L249
          v130[(v133 + (v131 * 2))][(v134 + (v132 * 4))] = v135;	// L250
        }
      }
    }
  }
  return ;	// L255
}

void main_graph_node8(
  float v136[8][512],
  float v137[512],
  float v138[8][512]
) {	// L257
  #pragma HLS dataflow

  float v139[512];	// L258
  #pragma HLS array_partition variable=v139 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v139 type=ram_2p impl=lutram

  for (int v140 = 0; v140 < 4; v140 += 1) {	// L259
    for (int v141 = 0; v141 < 128; v141 += 1) {	// L260
      #pragma HLS pipeline II=1
      for (int v142 = 0; v142 < 2; v142 += 1) {	// L261
        for (int v143 = 0; v143 < 4; v143 += 1) {	// L262
          float v144 = v136[(v142 + (v140 * 2))][(v143 + (v141 * 4))];	// L263
          if ((v142 + (v140 * 2)) == 0) {	// L264
            float v145 = v137[(v143 + (v141 * 4))];	// L265
            v139[(v143 + (v141 * 4))] = v145;	// L266
          }
          float v146 = v139[(v143 + (v141 * 4))];	// L268
          float v147 = v144 + v146;	// L269
          v138[(v142 + (v140 * 2))][(v143 + (v141 * 4))] = v147;	// L270
        }
      }
    }
  }
  return ;	// L275
}

void main_graph_node9(
  float v148[8][1024],
  float v149[1024][512],
  float v150[8][512]
) {	// L277
  #pragma HLS dataflow

  float v151[1024][512];	// L279
  #pragma HLS array_partition variable=v151 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v151 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v151 type=ram_2p impl=bram

  float v152[8][1024];	// L280
  #pragma HLS array_partition variable=v152 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v152 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v152 type=ram_2p impl=lutram

  float v153[8][512];	// L281
  #pragma HLS stream variable=v153 depth=10 type=fifo

  #pragma HLS array_partition variable=v153 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v153 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v153 type=ram_2p impl=lutram

  float v154[8][512];	// L282
  #pragma HLS array_partition variable=v154 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v154 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v154 type=ram_2p impl=lutram

  for (int v155 = 0; v155 < 4; v155 += 1) {	// L283
    for (int v156 = 0; v156 < 128; v156 += 1) {	// L284
      #pragma HLS pipeline II=1
      for (int v157 = 0; v157 < 2; v157 += 1) {	// L285
        for (int v158 = 0; v158 < 4; v158 += 1) {	// L286
          v153[(v157 + (v155 * 2))][(v158 + (v156 * 4))] = (float)0.000000;	// L287
        }
      }
    }
  }
  for (int v159 = 0; v159 < 4; v159 += 1) {	// L292
    for (int v160 = 0; v160 < 128; v160 += 1) {	// L293
      for (int v161 = 0; v161 < 128; v161 += 1) {	// L294
        #pragma HLS pipeline II=1
        for (int v162 = 0; v162 < 2; v162 += 1) {	// L295
          for (int v163 = 0; v163 < 8; v163 += 1) {	// L296
            for (int v164 = 0; v164 < 4; v164 += 1) {	// L297
              if ((v164 + (v161 * 4)) == 0) {	// L298
                float v165 = v148[(v162 + (v159 * 2))][(v163 + (v160 * 8))];	// L299
                v152[(v162 + (v159 * 2))][(v163 + (v160 * 8))] = v165;	// L300
              }
              float v166 = v152[(v162 + (v159 * 2))][(v163 + (v160 * 8))];	// L302
              if ((v162 + (v159 * 2)) == 0) {	// L303
                float v167 = v149[(v163 + (v160 * 8))][(v164 + (v161 * 4))];	// L304
                v151[(v163 + (v160 * 8))][(v164 + (v161 * 4))] = v167;	// L305
              }
              float v168 = v151[(v163 + (v160 * 8))][(v164 + (v161 * 4))];	// L307
              if ((v163 + (v160 * 8)) == 0) {	// L308
                float v169 = v153[(v162 + (v159 * 2))][(v164 + (v161 * 4))];	// L309
                v154[(v162 + (v159 * 2))][(v164 + (v161 * 4))] = v169;	// L310
              }
              float v170 = v154[(v162 + (v159 * 2))][(v164 + (v161 * 4))];	// L312
              float v171 = v166 * v168;	// L313
              float v172 = v170 + v171;	// L314
              v154[(v162 + (v159 * 2))][(v164 + (v161 * 4))] = v172;	// L315
              if (((v163 + (v160 * 8)) - 1023) == 0) {	// L316
                float v173 = v154[(v162 + (v159 * 2))][(v164 + (v161 * 4))];	// L317
                v150[(v162 + (v159 * 2))][(v164 + (v161 * 4))] = v173;	// L318
              }
            }
          }
        }
      }
    }
  }
  return ;	// L326
}

/// This is top function.
void main_graph(
  float v174[8][1024],
  float v175[1024][512],
  float v176[512],
  float v177[512],
  float v178[256],
  float v179[10],
  float v180[512][512],
  float v181[512][256],
  float v182[256][10],
  float v183[8][10]
) {	// L328
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v174 bundle=gmem1
  #pragma HLS array_partition variable=v174 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v174 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v174 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v175 bundle=gmem2
  #pragma HLS array_partition variable=v175 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v175 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v175 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v176 bundle=gmem3
  #pragma HLS array_partition variable=v176 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v176 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v177 bundle=gmem4
  #pragma HLS array_partition variable=v177 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v177 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v178 bundle=gmem5
  #pragma HLS array_partition variable=v178 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v178 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v179 bundle=gmem6
  #pragma HLS array_partition variable=v179 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v179 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v180 bundle=gmem7
  #pragma HLS array_partition variable=v180 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v180 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v180 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v181 bundle=gmem8
  #pragma HLS array_partition variable=v181 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v181 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v181 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v182 bundle=gmem9
  #pragma HLS array_partition variable=v182 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v182 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v182 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v183 bundle=gmem10
  #pragma HLS array_partition variable=v183 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v183 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v183 type=ram_2p impl=lutram

  #pragma HLS dataflow

  float v184[8][512];	// L330
  #pragma HLS stream variable=v184 depth=10 type=fifo

  #pragma HLS array_partition variable=v184 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v184 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v184 type=ram_2p impl=lutram

  main_graph_node9(v174, v175, v184);	// L331
  float v185[8][512];	// L332
  #pragma HLS stream variable=v185 depth=10 type=fifo

  #pragma HLS array_partition variable=v185 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v185 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v185 type=ram_2p impl=lutram

  main_graph_node8(v184, v176, v185);	// L333
  float v186[8][512];	// L334
  #pragma HLS stream variable=v186 depth=10 type=fifo

  #pragma HLS array_partition variable=v186 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v186 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v186 type=ram_2p impl=lutram

  float v187[8][512];	// L335
  #pragma HLS stream variable=v187 depth=10 type=fifo

  #pragma HLS array_partition variable=v187 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v187 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v187 type=ram_2p impl=lutram

  main_graph_node7(v185, v186, v187);	// L336
  float v188[8][512];	// L337
  #pragma HLS stream variable=v188 depth=10 type=fifo

  #pragma HLS array_partition variable=v188 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v188 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v188 type=ram_2p impl=lutram

  main_graph_node6(v187, v188);	// L338
  float v189[8][512];	// L339
  #pragma HLS stream variable=v189 depth=10 type=fifo

  #pragma HLS array_partition variable=v189 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v189 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v189 type=ram_2p impl=lutram

  main_graph_node5(v188, v180, v189);	// L340
  float v190[8][512];	// L341
  #pragma HLS stream variable=v190 depth=10 type=fifo

  #pragma HLS array_partition variable=v190 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v190 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v190 type=ram_2p impl=lutram

  main_graph_node4(v189, v177, v186, v190);	// L342
  float v191[8][256];	// L343
  #pragma HLS stream variable=v191 depth=10 type=fifo

  #pragma HLS array_partition variable=v191 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v191 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v191 type=ram_2p impl=lutram

  main_graph_node3(v190, v181, v191);	// L344
  float v192[8][256];	// L345
  #pragma HLS stream variable=v192 depth=10 type=fifo

  #pragma HLS array_partition variable=v192 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v192 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v192 type=ram_2p impl=lutram

  main_graph_node2(v191, v178, v192);	// L346
  float v193[8][10];	// L347
  #pragma HLS stream variable=v193 depth=10 type=fifo

  #pragma HLS array_partition variable=v193 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v193 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v193 type=ram_2p impl=lutram

  main_graph_node1(v192, v182, v193);	// L348
  main_graph_node0(v193, v179, v183);	// L349
  return ;	// L350
}

