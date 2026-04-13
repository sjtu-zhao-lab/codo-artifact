
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
  float v0[128][512],
  float v1[512],
  float v2[128][512]
) {	// L9
  #pragma HLS dataflow

  float v3[512];	// L11
  #pragma HLS array_partition variable=v3 cyclic factor=8 dim=1
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=lutram

  for (int v4 = 0; v4 < 64; v4 += 1) {	// L12
    for (int v5 = 0; v5 < 64; v5 += 1) {	// L13
      #pragma HLS pipeline II=1
      for (int v6 = 0; v6 < 2; v6 += 1) {	// L14
        for (int v7 = 0; v7 < 8; v7 += 1) {	// L15
          float v8 = v0[(v6 + (v4 * 2))][(v7 + (v5 * 8))];	// L16
          if ((v6 + (v4 * 2)) == 0) {	// L17
            float v9 = v1[(v7 + (v5 * 8))];	// L18
            v3[(v7 + (v5 * 8))] = v9;	// L19
          }
          float v10 = v3[(v7 + (v5 * 8))];	// L21
          float v11 = v8 + v10;	// L22
          float v12 = -(v11);	// L23
          float v13 = exp(v12);	// L24
          float v14 = v13 + (float)1.000000;	// L25
          float v15 = (float)1.000000 / v14;	// L26
          v2[(v6 + (v4 * 2))][(v7 + (v5 * 8))] = v15;	// L27
        }
      }
    }
  }
  return ;	// L32
}

void main_graph_node1(
  float v16[128][256],
  float v17[256][512],
  float v18[128][512]
) {	// L34
  #pragma HLS dataflow

  float v19[256][512];	// L36
  #pragma HLS array_partition variable=v19 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v19 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v19 type=ram_2p impl=bram

  float v20[128][256];	// L37
  #pragma HLS array_partition variable=v20 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v20 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v20 type=ram_2p impl=bram

  float v21[128][512];	// L38
  #pragma HLS stream variable=v21 depth=10 type=fifo

  #pragma HLS array_partition variable=v21 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v21 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v21 type=ram_2p impl=bram

  float v22[128][512];	// L39
  #pragma HLS array_partition variable=v22 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v22 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v22 type=ram_2p impl=bram

  for (int v23 = 0; v23 < 64; v23 += 1) {	// L40
    for (int v24 = 0; v24 < 64; v24 += 1) {	// L41
      #pragma HLS pipeline II=1
      for (int v25 = 0; v25 < 2; v25 += 1) {	// L42
        for (int v26 = 0; v26 < 8; v26 += 1) {	// L43
          v21[(v25 + (v23 * 2))][(v26 + (v24 * 8))] = (float)0.000000;	// L44
        }
      }
    }
  }
  for (int v27 = 0; v27 < 64; v27 += 1) {	// L49
    for (int v28 = 0; v28 < 128; v28 += 1) {	// L50
      for (int v29 = 0; v29 < 64; v29 += 1) {	// L51
        #pragma HLS pipeline II=1
        for (int v30 = 0; v30 < 2; v30 += 1) {	// L52
          for (int v31 = 0; v31 < 2; v31 += 1) {	// L53
            for (int v32 = 0; v32 < 8; v32 += 1) {	// L54
              if ((v32 + (v29 * 8)) == 0) {	// L55
                float v33 = v16[(v30 + (v27 * 2))][(v31 + (v28 * 2))];	// L56
                v20[(v30 + (v27 * 2))][(v31 + (v28 * 2))] = v33;	// L57
              }
              float v34 = v20[(v30 + (v27 * 2))][(v31 + (v28 * 2))];	// L59
              if ((v30 + (v27 * 2)) == 0) {	// L60
                float v35 = v17[(v31 + (v28 * 2))][(v32 + (v29 * 8))];	// L61
                v19[(v31 + (v28 * 2))][(v32 + (v29 * 8))] = v35;	// L62
              }
              float v36 = v19[(v31 + (v28 * 2))][(v32 + (v29 * 8))];	// L64
              if ((v31 + (v28 * 2)) == 0) {	// L65
                float v37 = v21[(v30 + (v27 * 2))][(v32 + (v29 * 8))];	// L66
                v22[(v30 + (v27 * 2))][(v32 + (v29 * 8))] = v37;	// L67
              }
              float v38 = v22[(v30 + (v27 * 2))][(v32 + (v29 * 8))];	// L69
              float v39 = v34 * v36;	// L70
              float v40 = v38 + v39;	// L71
              v22[(v30 + (v27 * 2))][(v32 + (v29 * 8))] = v40;	// L72
              if (((v31 + (v28 * 2)) - 255) == 0) {	// L73
                float v41 = v22[(v30 + (v27 * 2))][(v32 + (v29 * 8))];	// L74
                v18[(v30 + (v27 * 2))][(v32 + (v29 * 8))] = v41;	// L75
              }
            }
          }
        }
      }
    }
  }
  return ;	// L83
}

void main_graph_node2(
  float v42[128][256],
  float v43[256],
  float v44[128][256]
) {	// L85
  #pragma HLS dataflow

  float v45[256];	// L87
  #pragma HLS array_partition variable=v45 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v45 type=ram_2p impl=lutram

  for (int v46 = 0; v46 < 64; v46 += 1) {	// L88
    for (int v47 = 0; v47 < 128; v47 += 1) {	// L89
      #pragma HLS pipeline II=1
      for (int v48 = 0; v48 < 2; v48 += 1) {	// L90
        for (int v49 = 0; v49 < 2; v49 += 1) {	// L91
          float v50 = v42[(v48 + (v46 * 2))][(v49 + (v47 * 2))];	// L92
          if ((v48 + (v46 * 2)) == 0) {	// L93
            float v51 = v43[(v49 + (v47 * 2))];	// L94
            v45[(v49 + (v47 * 2))] = v51;	// L95
          }
          float v52 = v45[(v49 + (v47 * 2))];	// L97
          float v53 = v50 + v52;	// L98
          bool v54 = v53 > (float)0.000000;	// L99
          float v55 = v54 ? v53 : (float)0.000000;	// L100
          v44[(v48 + (v46 * 2))][(v49 + (v47 * 2))] = v55;	// L101
        }
      }
    }
  }
  return ;	// L106
}

void main_graph_node3(
  float v56[128][128],
  float v57[128][256],
  float v58[128][256]
) {	// L108
  #pragma HLS dataflow

  float v59[128][256];	// L110
  #pragma HLS array_partition variable=v59 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v59 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v59 type=ram_2p impl=bram

  float v60[128][128];	// L111
  #pragma HLS array_partition variable=v60 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v60 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v60 type=ram_2p impl=bram

  float v61[128][256];	// L112
  #pragma HLS stream variable=v61 depth=10 type=fifo

  #pragma HLS array_partition variable=v61 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v61 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v61 type=ram_2p impl=bram

  float v62[128][256];	// L113
  #pragma HLS array_partition variable=v62 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v62 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v62 type=ram_2p impl=bram

  for (int v63 = 0; v63 < 64; v63 += 1) {	// L114
    for (int v64 = 0; v64 < 128; v64 += 1) {	// L115
      #pragma HLS pipeline II=1
      for (int v65 = 0; v65 < 2; v65 += 1) {	// L116
        for (int v66 = 0; v66 < 2; v66 += 1) {	// L117
          v61[(v65 + (v63 * 2))][(v66 + (v64 * 2))] = (float)0.000000;	// L118
        }
      }
    }
  }
  for (int v67 = 0; v67 < 64; v67 += 1) {	// L123
    for (int v68 = 0; v68 < 64; v68 += 1) {	// L124
      for (int v69 = 0; v69 < 128; v69 += 1) {	// L125
        #pragma HLS pipeline II=1
        for (int v70 = 0; v70 < 2; v70 += 1) {	// L126
          for (int v71 = 0; v71 < 2; v71 += 1) {	// L127
            for (int v72 = 0; v72 < 2; v72 += 1) {	// L128
              if ((v72 + (v69 * 2)) == 0) {	// L129
                float v73 = v56[(v70 + (v67 * 2))][(v71 + (v68 * 2))];	// L130
                v60[(v70 + (v67 * 2))][(v71 + (v68 * 2))] = v73;	// L131
              }
              float v74 = v60[(v70 + (v67 * 2))][(v71 + (v68 * 2))];	// L133
              if ((v70 + (v67 * 2)) == 0) {	// L134
                float v75 = v57[(v71 + (v68 * 2))][(v72 + (v69 * 2))];	// L135
                v59[(v71 + (v68 * 2))][(v72 + (v69 * 2))] = v75;	// L136
              }
              float v76 = v59[(v71 + (v68 * 2))][(v72 + (v69 * 2))];	// L138
              if ((v71 + (v68 * 2)) == 0) {	// L139
                float v77 = v61[(v70 + (v67 * 2))][(v72 + (v69 * 2))];	// L140
                v62[(v70 + (v67 * 2))][(v72 + (v69 * 2))] = v77;	// L141
              }
              float v78 = v62[(v70 + (v67 * 2))][(v72 + (v69 * 2))];	// L143
              float v79 = v74 * v76;	// L144
              float v80 = v78 + v79;	// L145
              v62[(v70 + (v67 * 2))][(v72 + (v69 * 2))] = v80;	// L146
              if (((v71 + (v68 * 2)) - 127) == 0) {	// L147
                float v81 = v62[(v70 + (v67 * 2))][(v72 + (v69 * 2))];	// L148
                v58[(v70 + (v67 * 2))][(v72 + (v69 * 2))] = v81;	// L149
              }
            }
          }
        }
      }
    }
  }
  return ;	// L157
}

void main_graph_node4(
  float v82[128][128],
  float v83[128],
  float v84[128][128]
) {	// L159
  #pragma HLS dataflow

  float v85[128];	// L161
  #pragma HLS array_partition variable=v85 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v85 type=ram_2p impl=lutram

  for (int v86 = 0; v86 < 64; v86 += 1) {	// L162
    for (int v87 = 0; v87 < 64; v87 += 1) {	// L163
      #pragma HLS pipeline II=1
      for (int v88 = 0; v88 < 2; v88 += 1) {	// L164
        for (int v89 = 0; v89 < 2; v89 += 1) {	// L165
          float v90 = v82[(v88 + (v86 * 2))][(v89 + (v87 * 2))];	// L166
          if ((v88 + (v86 * 2)) == 0) {	// L167
            float v91 = v83[(v89 + (v87 * 2))];	// L168
            v85[(v89 + (v87 * 2))] = v91;	// L169
          }
          float v92 = v85[(v89 + (v87 * 2))];	// L171
          float v93 = v90 + v92;	// L172
          bool v94 = v93 > (float)0.000000;	// L173
          float v95 = v94 ? v93 : (float)0.000000;	// L174
          v84[(v88 + (v86 * 2))][(v89 + (v87 * 2))] = v95;	// L175
        }
      }
    }
  }
  return ;	// L180
}

void main_graph_node5(
  float v96[128][64],
  float v97[64][128],
  float v98[128][128]
) {	// L182
  #pragma HLS dataflow

  float v99[64][128];	// L184
  #pragma HLS array_partition variable=v99 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v99 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v99 type=ram_2p impl=bram

  float v100[128][64];	// L185
  #pragma HLS array_partition variable=v100 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v100 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v100 type=ram_2p impl=bram

  float v101[128][128];	// L186
  #pragma HLS stream variable=v101 depth=10 type=fifo

  #pragma HLS array_partition variable=v101 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v101 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v101 type=ram_2p impl=bram

  float v102[128][128];	// L187
  #pragma HLS array_partition variable=v102 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v102 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v102 type=ram_2p impl=bram

  for (int v103 = 0; v103 < 64; v103 += 1) {	// L188
    for (int v104 = 0; v104 < 64; v104 += 1) {	// L189
      #pragma HLS pipeline II=1
      for (int v105 = 0; v105 < 2; v105 += 1) {	// L190
        for (int v106 = 0; v106 < 2; v106 += 1) {	// L191
          v101[(v105 + (v103 * 2))][(v106 + (v104 * 2))] = (float)0.000000;	// L192
        }
      }
    }
  }
  for (int v107 = 0; v107 < 64; v107 += 1) {	// L197
    for (int v108 = 0; v108 < 32; v108 += 1) {	// L198
      for (int v109 = 0; v109 < 64; v109 += 1) {	// L199
        #pragma HLS pipeline II=1
        for (int v110 = 0; v110 < 2; v110 += 1) {	// L200
          for (int v111 = 0; v111 < 2; v111 += 1) {	// L201
            for (int v112 = 0; v112 < 2; v112 += 1) {	// L202
              if ((v112 + (v109 * 2)) == 0) {	// L203
                float v113 = v96[(v110 + (v107 * 2))][(v111 + (v108 * 2))];	// L204
                v100[(v110 + (v107 * 2))][(v111 + (v108 * 2))] = v113;	// L205
              }
              float v114 = v100[(v110 + (v107 * 2))][(v111 + (v108 * 2))];	// L207
              if ((v110 + (v107 * 2)) == 0) {	// L208
                float v115 = v97[(v111 + (v108 * 2))][(v112 + (v109 * 2))];	// L209
                v99[(v111 + (v108 * 2))][(v112 + (v109 * 2))] = v115;	// L210
              }
              float v116 = v99[(v111 + (v108 * 2))][(v112 + (v109 * 2))];	// L212
              if ((v111 + (v108 * 2)) == 0) {	// L213
                float v117 = v101[(v110 + (v107 * 2))][(v112 + (v109 * 2))];	// L214
                v102[(v110 + (v107 * 2))][(v112 + (v109 * 2))] = v117;	// L215
              }
              float v118 = v102[(v110 + (v107 * 2))][(v112 + (v109 * 2))];	// L217
              float v119 = v114 * v116;	// L218
              float v120 = v118 + v119;	// L219
              v102[(v110 + (v107 * 2))][(v112 + (v109 * 2))] = v120;	// L220
              if (((v111 + (v108 * 2)) - 63) == 0) {	// L221
                float v121 = v102[(v110 + (v107 * 2))][(v112 + (v109 * 2))];	// L222
                v98[(v110 + (v107 * 2))][(v112 + (v109 * 2))] = v121;	// L223
              }
            }
          }
        }
      }
    }
  }
  return ;	// L231
}

void main_graph_node6(
  float v122[128][64],
  float v123[64],
  float v124[128][64]
) {	// L233
  #pragma HLS dataflow

  float v125[64];	// L234
  #pragma HLS array_partition variable=v125 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v125 type=ram_2p impl=lutram

  for (int v126 = 0; v126 < 64; v126 += 1) {	// L235
    for (int v127 = 0; v127 < 32; v127 += 1) {	// L236
      #pragma HLS pipeline II=1
      for (int v128 = 0; v128 < 2; v128 += 1) {	// L237
        for (int v129 = 0; v129 < 2; v129 += 1) {	// L238
          float v130 = v122[(v128 + (v126 * 2))][(v129 + (v127 * 2))];	// L239
          if ((v128 + (v126 * 2)) == 0) {	// L240
            float v131 = v123[(v129 + (v127 * 2))];	// L241
            v125[(v129 + (v127 * 2))] = v131;	// L242
          }
          float v132 = v125[(v129 + (v127 * 2))];	// L244
          float v133 = v130 + v132;	// L245
          v124[(v128 + (v126 * 2))][(v129 + (v127 * 2))] = v133;	// L246
        }
      }
    }
  }
  return ;	// L251
}

void main_graph_node7(
  float v134[128][128],
  float v135[128][64],
  float v136[128][64]
) {	// L253
  #pragma HLS dataflow

  float v137[128][64];	// L255
  #pragma HLS array_partition variable=v137 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v137 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v137 type=ram_2p impl=bram

  float v138[128][128];	// L256
  #pragma HLS array_partition variable=v138 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v138 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v138 type=ram_2p impl=bram

  float v139[128][64];	// L257
  #pragma HLS stream variable=v139 depth=10 type=fifo

  #pragma HLS array_partition variable=v139 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v139 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v139 type=ram_2p impl=bram

  float v140[128][64];	// L258
  #pragma HLS array_partition variable=v140 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v140 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v140 type=ram_2p impl=bram

  for (int v141 = 0; v141 < 64; v141 += 1) {	// L259
    for (int v142 = 0; v142 < 32; v142 += 1) {	// L260
      #pragma HLS pipeline II=1
      for (int v143 = 0; v143 < 2; v143 += 1) {	// L261
        for (int v144 = 0; v144 < 2; v144 += 1) {	// L262
          v139[(v143 + (v141 * 2))][(v144 + (v142 * 2))] = (float)0.000000;	// L263
        }
      }
    }
  }
  for (int v145 = 0; v145 < 64; v145 += 1) {	// L268
    for (int v146 = 0; v146 < 64; v146 += 1) {	// L269
      for (int v147 = 0; v147 < 32; v147 += 1) {	// L270
        #pragma HLS pipeline II=1
        for (int v148 = 0; v148 < 2; v148 += 1) {	// L271
          for (int v149 = 0; v149 < 2; v149 += 1) {	// L272
            for (int v150 = 0; v150 < 2; v150 += 1) {	// L273
              if ((v150 + (v147 * 2)) == 0) {	// L274
                float v151 = v134[(v148 + (v145 * 2))][(v149 + (v146 * 2))];	// L275
                v138[(v148 + (v145 * 2))][(v149 + (v146 * 2))] = v151;	// L276
              }
              float v152 = v138[(v148 + (v145 * 2))][(v149 + (v146 * 2))];	// L278
              if ((v148 + (v145 * 2)) == 0) {	// L279
                float v153 = v135[(v149 + (v146 * 2))][(v150 + (v147 * 2))];	// L280
                v137[(v149 + (v146 * 2))][(v150 + (v147 * 2))] = v153;	// L281
              }
              float v154 = v137[(v149 + (v146 * 2))][(v150 + (v147 * 2))];	// L283
              if ((v149 + (v146 * 2)) == 0) {	// L284
                float v155 = v139[(v148 + (v145 * 2))][(v150 + (v147 * 2))];	// L285
                v140[(v148 + (v145 * 2))][(v150 + (v147 * 2))] = v155;	// L286
              }
              float v156 = v140[(v148 + (v145 * 2))][(v150 + (v147 * 2))];	// L288
              float v157 = v152 * v154;	// L289
              float v158 = v156 + v157;	// L290
              v140[(v148 + (v145 * 2))][(v150 + (v147 * 2))] = v158;	// L291
              if (((v149 + (v146 * 2)) - 127) == 0) {	// L292
                float v159 = v140[(v148 + (v145 * 2))][(v150 + (v147 * 2))];	// L293
                v136[(v148 + (v145 * 2))][(v150 + (v147 * 2))] = v159;	// L294
              }
            }
          }
        }
      }
    }
  }
  return ;	// L302
}

void main_graph_node8(
  float v160[128][128],
  float v161[128],
  float v162[128][128]
) {	// L304
  #pragma HLS dataflow

  float v163[128];	// L306
  #pragma HLS array_partition variable=v163 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v163 type=ram_2p impl=lutram

  for (int v164 = 0; v164 < 64; v164 += 1) {	// L307
    for (int v165 = 0; v165 < 64; v165 += 1) {	// L308
      #pragma HLS pipeline II=1
      for (int v166 = 0; v166 < 2; v166 += 1) {	// L309
        for (int v167 = 0; v167 < 2; v167 += 1) {	// L310
          float v168 = v160[(v166 + (v164 * 2))][(v167 + (v165 * 2))];	// L311
          if ((v166 + (v164 * 2)) == 0) {	// L312
            float v169 = v161[(v167 + (v165 * 2))];	// L313
            v163[(v167 + (v165 * 2))] = v169;	// L314
          }
          float v170 = v163[(v167 + (v165 * 2))];	// L316
          float v171 = v168 + v170;	// L317
          bool v172 = v171 > (float)0.000000;	// L318
          float v173 = v172 ? v171 : (float)0.000000;	// L319
          v162[(v166 + (v164 * 2))][(v167 + (v165 * 2))] = v173;	// L320
        }
      }
    }
  }
  return ;	// L325
}

void main_graph_node9(
  float v174[128][256],
  float v175[256][128],
  float v176[128][128]
) {	// L327
  #pragma HLS dataflow

  float v177[256][128];	// L329
  #pragma HLS array_partition variable=v177 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v177 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v177 type=ram_2p impl=bram

  float v178[128][256];	// L330
  #pragma HLS array_partition variable=v178 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v178 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v178 type=ram_2p impl=bram

  float v179[128][128];	// L331
  #pragma HLS stream variable=v179 depth=10 type=fifo

  #pragma HLS array_partition variable=v179 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v179 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v179 type=ram_2p impl=bram

  float v180[128][128];	// L332
  #pragma HLS array_partition variable=v180 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v180 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v180 type=ram_2p impl=bram

  for (int v181 = 0; v181 < 64; v181 += 1) {	// L333
    for (int v182 = 0; v182 < 64; v182 += 1) {	// L334
      #pragma HLS pipeline II=1
      for (int v183 = 0; v183 < 2; v183 += 1) {	// L335
        for (int v184 = 0; v184 < 2; v184 += 1) {	// L336
          v179[(v183 + (v181 * 2))][(v184 + (v182 * 2))] = (float)0.000000;	// L337
        }
      }
    }
  }
  for (int v185 = 0; v185 < 64; v185 += 1) {	// L342
    for (int v186 = 0; v186 < 128; v186 += 1) {	// L343
      for (int v187 = 0; v187 < 64; v187 += 1) {	// L344
        #pragma HLS pipeline II=1
        for (int v188 = 0; v188 < 2; v188 += 1) {	// L345
          for (int v189 = 0; v189 < 2; v189 += 1) {	// L346
            for (int v190 = 0; v190 < 2; v190 += 1) {	// L347
              if ((v190 + (v187 * 2)) == 0) {	// L348
                float v191 = v174[(v188 + (v185 * 2))][(v189 + (v186 * 2))];	// L349
                v178[(v188 + (v185 * 2))][(v189 + (v186 * 2))] = v191;	// L350
              }
              float v192 = v178[(v188 + (v185 * 2))][(v189 + (v186 * 2))];	// L352
              if ((v188 + (v185 * 2)) == 0) {	// L353
                float v193 = v175[(v189 + (v186 * 2))][(v190 + (v187 * 2))];	// L354
                v177[(v189 + (v186 * 2))][(v190 + (v187 * 2))] = v193;	// L355
              }
              float v194 = v177[(v189 + (v186 * 2))][(v190 + (v187 * 2))];	// L357
              if ((v189 + (v186 * 2)) == 0) {	// L358
                float v195 = v179[(v188 + (v185 * 2))][(v190 + (v187 * 2))];	// L359
                v180[(v188 + (v185 * 2))][(v190 + (v187 * 2))] = v195;	// L360
              }
              float v196 = v180[(v188 + (v185 * 2))][(v190 + (v187 * 2))];	// L362
              float v197 = v192 * v194;	// L363
              float v198 = v196 + v197;	// L364
              v180[(v188 + (v185 * 2))][(v190 + (v187 * 2))] = v198;	// L365
              if (((v189 + (v186 * 2)) - 255) == 0) {	// L366
                float v199 = v180[(v188 + (v185 * 2))][(v190 + (v187 * 2))];	// L367
                v176[(v188 + (v185 * 2))][(v190 + (v187 * 2))] = v199;	// L368
              }
            }
          }
        }
      }
    }
  }
  return ;	// L376
}

void main_graph_node10(
  float v200[128][256],
  float v201[256],
  float v202[128][256]
) {	// L378
  #pragma HLS dataflow

  float v203[256];	// L380
  #pragma HLS array_partition variable=v203 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v203 type=ram_2p impl=lutram

  for (int v204 = 0; v204 < 64; v204 += 1) {	// L381
    for (int v205 = 0; v205 < 128; v205 += 1) {	// L382
      #pragma HLS pipeline II=1
      for (int v206 = 0; v206 < 2; v206 += 1) {	// L383
        for (int v207 = 0; v207 < 2; v207 += 1) {	// L384
          float v208 = v200[(v206 + (v204 * 2))][(v207 + (v205 * 2))];	// L385
          if ((v206 + (v204 * 2)) == 0) {	// L386
            float v209 = v201[(v207 + (v205 * 2))];	// L387
            v203[(v207 + (v205 * 2))] = v209;	// L388
          }
          float v210 = v203[(v207 + (v205 * 2))];	// L390
          float v211 = v208 + v210;	// L391
          bool v212 = v211 > (float)0.000000;	// L392
          float v213 = v212 ? v211 : (float)0.000000;	// L393
          v202[(v206 + (v204 * 2))][(v207 + (v205 * 2))] = v213;	// L394
        }
      }
    }
  }
  return ;	// L399
}

void main_graph_node11(
  float v214[128][512],
  float v215[512][256],
  float v216[128][256]
) {	// L401
  #pragma HLS dataflow

  float v217[512][256];	// L403
  #pragma HLS array_partition variable=v217 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v217 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v217 type=ram_2p impl=bram

  float v218[128][512];	// L404
  #pragma HLS array_partition variable=v218 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v218 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v218 type=ram_2p impl=bram

  float v219[128][256];	// L405
  #pragma HLS stream variable=v219 depth=10 type=fifo

  #pragma HLS array_partition variable=v219 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v219 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v219 type=ram_2p impl=bram

  float v220[128][256];	// L406
  #pragma HLS array_partition variable=v220 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v220 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v220 type=ram_2p impl=bram

  for (int v221 = 0; v221 < 64; v221 += 1) {	// L407
    for (int v222 = 0; v222 < 128; v222 += 1) {	// L408
      #pragma HLS pipeline II=1
      for (int v223 = 0; v223 < 2; v223 += 1) {	// L409
        for (int v224 = 0; v224 < 2; v224 += 1) {	// L410
          v219[(v223 + (v221 * 2))][(v224 + (v222 * 2))] = (float)0.000000;	// L411
        }
      }
    }
  }
  for (int v225 = 0; v225 < 64; v225 += 1) {	// L416
    for (int v226 = 0; v226 < 64; v226 += 1) {	// L417
      for (int v227 = 0; v227 < 128; v227 += 1) {	// L418
        #pragma HLS pipeline II=1
        for (int v228 = 0; v228 < 2; v228 += 1) {	// L419
          for (int v229 = 0; v229 < 8; v229 += 1) {	// L420
            for (int v230 = 0; v230 < 2; v230 += 1) {	// L421
              if ((v230 + (v227 * 2)) == 0) {	// L422
                float v231 = v214[(v228 + (v225 * 2))][(v229 + (v226 * 8))];	// L423
                v218[(v228 + (v225 * 2))][(v229 + (v226 * 8))] = v231;	// L424
              }
              float v232 = v218[(v228 + (v225 * 2))][(v229 + (v226 * 8))];	// L426
              if ((v228 + (v225 * 2)) == 0) {	// L427
                float v233 = v215[(v229 + (v226 * 8))][(v230 + (v227 * 2))];	// L428
                v217[(v229 + (v226 * 8))][(v230 + (v227 * 2))] = v233;	// L429
              }
              float v234 = v217[(v229 + (v226 * 8))][(v230 + (v227 * 2))];	// L431
              if ((v229 + (v226 * 8)) == 0) {	// L432
                float v235 = v219[(v228 + (v225 * 2))][(v230 + (v227 * 2))];	// L433
                v220[(v228 + (v225 * 2))][(v230 + (v227 * 2))] = v235;	// L434
              }
              float v236 = v220[(v228 + (v225 * 2))][(v230 + (v227 * 2))];	// L436
              float v237 = v232 * v234;	// L437
              float v238 = v236 + v237;	// L438
              v220[(v228 + (v225 * 2))][(v230 + (v227 * 2))] = v238;	// L439
              if (((v229 + (v226 * 8)) - 511) == 0) {	// L440
                float v239 = v220[(v228 + (v225 * 2))][(v230 + (v227 * 2))];	// L441
                v216[(v228 + (v225 * 2))][(v230 + (v227 * 2))] = v239;	// L442
              }
            }
          }
        }
      }
    }
  }
  return ;	// L450
}

/// This is top function.
void main_graph(
  float v240[128][512],
  float v241[512][256],
  float v242[256],
  float v243[128],
  float v244[64],
  float v245[128],
  float v246[256],
  float v247[512],
  float v248[256][128],
  float v249[128][64],
  float v250[64][128],
  float v251[128][256],
  float v252[256][512],
  float v253[128][512]
) {	// L452
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v240 bundle=gmem1
  #pragma HLS array_partition variable=v240 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v240 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v240 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v241 bundle=gmem2
  #pragma HLS array_partition variable=v241 cyclic factor=8 dim=1
  #pragma HLS array_partition variable=v241 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v241 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v242 bundle=gmem3
  #pragma HLS array_partition variable=v242 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v242 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v243 bundle=gmem4
  #pragma HLS array_partition variable=v243 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v243 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v244 bundle=gmem5
  #pragma HLS array_partition variable=v244 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v244 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v245 bundle=gmem6
  #pragma HLS array_partition variable=v245 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v245 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v246 bundle=gmem7
  #pragma HLS array_partition variable=v246 cyclic factor=2 dim=1
  #pragma HLS bind_storage variable=v246 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v247 bundle=gmem8
  #pragma HLS array_partition variable=v247 cyclic factor=8 dim=1
  #pragma HLS bind_storage variable=v247 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v248 bundle=gmem9
  #pragma HLS array_partition variable=v248 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v248 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v248 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v249 bundle=gmem10
  #pragma HLS array_partition variable=v249 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v249 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v249 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v250 bundle=gmem11
  #pragma HLS array_partition variable=v250 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v250 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v250 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v251 bundle=gmem12
  #pragma HLS array_partition variable=v251 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v251 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v251 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v252 bundle=gmem13
  #pragma HLS array_partition variable=v252 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v252 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v252 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v253 bundle=gmem14
  #pragma HLS array_partition variable=v253 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v253 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v253 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v254[128][256];	// L454
  #pragma HLS stream variable=v254 depth=10 type=fifo

  #pragma HLS array_partition variable=v254 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v254 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v254 type=ram_t2p impl=bram

  main_graph_node11(v240, v241, v254);	// L455
  float v255[128][256];	// L456
  #pragma HLS stream variable=v255 depth=10 type=fifo

  #pragma HLS array_partition variable=v255 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v255 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v255 type=ram_t2p impl=bram

  main_graph_node10(v254, v242, v255);	// L457
  float v256[128][128];	// L458
  #pragma HLS stream variable=v256 depth=10 type=fifo

  #pragma HLS array_partition variable=v256 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v256 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v256 type=ram_t2p impl=bram

  main_graph_node9(v255, v248, v256);	// L459
  float v257[128][128];	// L460
  #pragma HLS stream variable=v257 depth=10 type=fifo

  #pragma HLS array_partition variable=v257 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v257 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v257 type=ram_t2p impl=bram

  main_graph_node8(v256, v243, v257);	// L461
  float v258[128][64];	// L462
  #pragma HLS stream variable=v258 depth=10 type=fifo

  #pragma HLS array_partition variable=v258 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v258 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v258 type=ram_t2p impl=bram

  main_graph_node7(v257, v249, v258);	// L463
  float v259[128][64];	// L464
  #pragma HLS stream variable=v259 depth=10 type=fifo

  #pragma HLS array_partition variable=v259 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v259 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v259 type=ram_t2p impl=bram

  main_graph_node6(v258, v244, v259);	// L465
  float v260[128][128];	// L466
  #pragma HLS stream variable=v260 depth=10 type=fifo

  #pragma HLS array_partition variable=v260 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v260 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v260 type=ram_t2p impl=bram

  main_graph_node5(v259, v250, v260);	// L467
  float v261[128][128];	// L468
  #pragma HLS stream variable=v261 depth=10 type=fifo

  #pragma HLS array_partition variable=v261 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v261 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v261 type=ram_t2p impl=bram

  main_graph_node4(v260, v245, v261);	// L469
  float v262[128][256];	// L470
  #pragma HLS stream variable=v262 depth=10 type=fifo

  #pragma HLS array_partition variable=v262 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v262 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v262 type=ram_t2p impl=bram

  main_graph_node3(v261, v251, v262);	// L471
  float v263[128][256];	// L472
  #pragma HLS stream variable=v263 depth=10 type=fifo

  #pragma HLS array_partition variable=v263 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v263 cyclic factor=2 dim=2
  #pragma HLS bind_storage variable=v263 type=ram_t2p impl=bram

  main_graph_node2(v262, v246, v263);	// L473
  float v264[128][512];	// L474
  #pragma HLS stream variable=v264 depth=10 type=fifo

  #pragma HLS array_partition variable=v264 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v264 cyclic factor=8 dim=2
  #pragma HLS bind_storage variable=v264 type=ram_t2p impl=bram

  main_graph_node1(v263, v252, v264);	// L475
  main_graph_node0(v264, v247, v253);	// L476
  return ;	// L477
}

