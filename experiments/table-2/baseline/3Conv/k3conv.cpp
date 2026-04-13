
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
) {	// L3
  // #pragma HLS dataflow

  float v3[1][32][34][34];	// L5
  // #pragma HLS stream variable=v3 depth=10 type=fifo

  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  for (int v4 = 0; v4 < 1; v4 += 1) {	// L6
    for (int v5 = 0; v5 < 32; v5 += 1) {	// L7
      for (int v6 = 0; v6 < 34; v6 += 1) {	// L8
        for (int v7 = 0; v7 < 34; v7 += 1) {	// L9
          v3[v4][v5][v6][v7] = (float)0.000000;	// L10
        }
      }
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L15
    for (int v9 = 0; v9 < 32; v9 += 1) {	// L16
      for (int v10 = 0; v10 < 32; v10 += 1) {	// L17
        for (int v11 = 0; v11 < 32; v11 += 1) {	// L18
          float v12 = v1[v8][v9][v10][v11];	// L19
          v3[v8][v9][(v10 + 1)][(v11 + 1)] = v12;	// L20
        }
      }
    }
  }
  float v13[1][32][32][32];	// L25
  // #pragma HLS stream variable=v13 depth=10 type=fifo

  #pragma HLS bind_storage variable=v13 type=ram_t2p impl=bram

  for (int v14 = 0; v14 < 1; v14 += 1) {	// L26
    for (int v15 = 0; v15 < 32; v15 += 1) {	// L27
      for (int v16 = 0; v16 < 32; v16 += 1) {	// L28
        for (int v17 = 0; v17 < 32; v17 += 1) {	// L29
          v13[v14][v15][v16][v17] = (float)0.000000;	// L30
        }
      }
    }
  }
  for (int v18 = 0; v18 < 1; v18 += 1) {	// L35
    for (int v19 = 0; v19 < 32; v19 += 1) {	// L36
      for (int v20 = 0; v20 < 32; v20 += 1) {	// L37
        for (int v21 = 0; v21 < 32; v21 += 1) {	// L38
          for (int v22 = 0; v22 < 32; v22 += 1) {	// L39
            for (int v23 = 0; v23 < 3; v23 += 1) {	// L40
              for (int v24 = 0; v24 < 3; v24 += 1) {	// L41
                float v25 = v3[v18][v22][(v20 + v23)][(v21 + v24)];	// L42
                float v26 = v0[v19][v22][v23][v24];	// L43
                float v27 = v13[v18][v19][v20][v21];	// L44
                float v28 = v25 * v26;	// L45
                float v29 = v27 + v28;	// L46
                v13[v18][v19][v20][v21] = v29;	// L47
              }
            }
          }
        }
      }
    }
  }
  for (int v30 = 0; v30 < 1; v30 += 1) {	// L55
    for (int v31 = 0; v31 < 32; v31 += 1) {	// L56
      for (int v32 = 0; v32 < 32; v32 += 1) {	// L57
        for (int v33 = 0; v33 < 32; v33 += 1) {	// L58
          float v34 = v13[0][v31][v32][v33];	// L59
          bool v35 = v34 > (float)0.000000;	// L60
          float v36 = v35 ? v34 : (float)0.000000;	// L61
          v2[v30][v31][v32][v33] = v36;	// L62
        }
      }
    }
  }
}

void main_graph_node1(
  float v37[1][32][32][32],
  float v38[32][32][3][3],
  float v39[1][32][32][32]
) {	// L69
  // #pragma HLS dataflow

  float v40[1][32][34][34];	// L71
  // #pragma HLS stream variable=v40 depth=10 type=fifo

  #pragma HLS bind_storage variable=v40 type=ram_t2p impl=bram

  for (int v41 = 0; v41 < 1; v41 += 1) {	// L72
    for (int v42 = 0; v42 < 32; v42 += 1) {	// L73
      for (int v43 = 0; v43 < 34; v43 += 1) {	// L74
        for (int v44 = 0; v44 < 34; v44 += 1) {	// L75
          v40[v41][v42][v43][v44] = (float)0.000000;	// L76
        }
      }
    }
  }
  for (int v45 = 0; v45 < 1; v45 += 1) {	// L81
    for (int v46 = 0; v46 < 32; v46 += 1) {	// L82
      for (int v47 = 0; v47 < 32; v47 += 1) {	// L83
        for (int v48 = 0; v48 < 32; v48 += 1) {	// L84
          float v49 = v37[v45][v46][v47][v48];	// L85
          v40[v45][v46][(v47 + 1)][(v48 + 1)] = v49;	// L86
        }
      }
    }
  }
  float v50[1][32][32][32];	// L91
  // #pragma HLS stream variable=v50 depth=10 type=fifo

  #pragma HLS bind_storage variable=v50 type=ram_t2p impl=bram

  for (int v51 = 0; v51 < 1; v51 += 1) {	// L92
    for (int v52 = 0; v52 < 32; v52 += 1) {	// L93
      for (int v53 = 0; v53 < 32; v53 += 1) {	// L94
        for (int v54 = 0; v54 < 32; v54 += 1) {	// L95
          v50[v51][v52][v53][v54] = (float)0.000000;	// L96
        }
      }
    }
  }
  for (int v55 = 0; v55 < 1; v55 += 1) {	// L101
    for (int v56 = 0; v56 < 32; v56 += 1) {	// L102
      for (int v57 = 0; v57 < 32; v57 += 1) {	// L103
        for (int v58 = 0; v58 < 32; v58 += 1) {	// L104
          for (int v59 = 0; v59 < 32; v59 += 1) {	// L105
            for (int v60 = 0; v60 < 3; v60 += 1) {	// L106
              for (int v61 = 0; v61 < 3; v61 += 1) {	// L107
                float v62 = v40[v55][v59][(v57 + v60)][(v58 + v61)];	// L108
                float v63 = v38[v56][v59][v60][v61];	// L109
                float v64 = v50[v55][v56][v57][v58];	// L110
                float v65 = v62 * v63;	// L111
                float v66 = v64 + v65;	// L112
                v50[v55][v56][v57][v58] = v66;	// L113
              }
            }
          }
        }
      }
    }
  }
  for (int v67 = 0; v67 < 1; v67 += 1) {	// L121
    for (int v68 = 0; v68 < 32; v68 += 1) {	// L122
      for (int v69 = 0; v69 < 32; v69 += 1) {	// L123
        for (int v70 = 0; v70 < 32; v70 += 1) {	// L124
          float v71 = v50[0][v68][v69][v70];	// L125
          bool v72 = v71 > (float)0.000000;	// L126
          float v73 = v72 ? v71 : (float)0.000000;	// L127
          v39[v67][v68][v69][v70] = v73;	// L128
        }
      }
    }
  }
}

void main_graph_node2(
  float v74[1][3][32][32],
  float v75[32][3][3][3],
  float v76[1][32][32][32]
) {	// L135
  // #pragma HLS dataflow

  float v77[1][3][34][34];	// L137
  // #pragma HLS stream variable=v77 depth=10 type=fifo

  #pragma HLS bind_storage variable=v77 type=ram_t2p impl=bram

  for (int v78 = 0; v78 < 1; v78 += 1) {	// L138
    for (int v79 = 0; v79 < 3; v79 += 1) {	// L139
      for (int v80 = 0; v80 < 34; v80 += 1) {	// L140
        for (int v81 = 0; v81 < 34; v81 += 1) {	// L141
          v77[v78][v79][v80][v81] = (float)0.000000;	// L142
        }
      }
    }
  }
  for (int v82 = 0; v82 < 1; v82 += 1) {	// L147
    for (int v83 = 0; v83 < 3; v83 += 1) {	// L148
      for (int v84 = 0; v84 < 32; v84 += 1) {	// L149
        for (int v85 = 0; v85 < 32; v85 += 1) {	// L150
          float v86 = v74[v82][v83][v84][v85];	// L151
          v77[v82][v83][(v84 + 1)][(v85 + 1)] = v86;	// L152
        }
      }
    }
  }
  float v87[1][32][32][32];	// L157
  // #pragma HLS stream variable=v87 depth=10 type=fifo

  #pragma HLS bind_storage variable=v87 type=ram_t2p impl=bram

  for (int v88 = 0; v88 < 1; v88 += 1) {	// L158
    for (int v89 = 0; v89 < 32; v89 += 1) {	// L159
      for (int v90 = 0; v90 < 32; v90 += 1) {	// L160
        for (int v91 = 0; v91 < 32; v91 += 1) {	// L161
          v87[v88][v89][v90][v91] = (float)0.000000;	// L162
        }
      }
    }
  }
  for (int v92 = 0; v92 < 1; v92 += 1) {	// L167
    for (int v93 = 0; v93 < 32; v93 += 1) {	// L168
      for (int v94 = 0; v94 < 32; v94 += 1) {	// L169
        for (int v95 = 0; v95 < 32; v95 += 1) {	// L170
          for (int v96 = 0; v96 < 3; v96 += 1) {	// L171
            for (int v97 = 0; v97 < 3; v97 += 1) {	// L172
              for (int v98 = 0; v98 < 3; v98 += 1) {	// L173
                float v99 = v77[v92][v96][(v94 + v97)][(v95 + v98)];	// L174
                float v100 = v75[v93][v96][v97][v98];	// L175
                float v101 = v87[v92][v93][v94][v95];	// L176
                float v102 = v99 * v100;	// L177
                float v103 = v101 + v102;	// L178
                v87[v92][v93][v94][v95] = v103;	// L179
              }
            }
          }
        }
      }
    }
  }
  for (int v104 = 0; v104 < 1; v104 += 1) {	// L187
    for (int v105 = 0; v105 < 32; v105 += 1) {	// L188
      for (int v106 = 0; v106 < 32; v106 += 1) {	// L189
        for (int v107 = 0; v107 < 32; v107 += 1) {	// L190
          float v108 = v87[0][v105][v106][v107];	// L191
          bool v109 = v108 > (float)0.000000;	// L192
          float v110 = v109 ? v108 : (float)0.000000;	// L193
          v76[v104][v105][v106][v107] = v110;	// L194
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  float v111[1][3][32][32],
  float v112[32][3][3][3],
  float v113[32][32][3][3],
  float v114[32][32][3][3],
  float v115[1][32][32][32]
) {	// L201
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v111
  #pragma HLS bind_storage variable=v111 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v112
  #pragma HLS bind_storage variable=v112 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v113
  #pragma HLS bind_storage variable=v113 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v114
  #pragma HLS bind_storage variable=v114 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v115
  #pragma HLS bind_storage variable=v115 type=ram_t2p impl=bram

  // // #pragma HLS dataflow

  float v116[1][32][32][32];	// L203
  // #pragma HLS stream variable=v116 depth=10 type=fifo

  #pragma HLS bind_storage variable=v116 type=ram_t2p impl=bram

  main_graph_node2(v111, v112, v116);	// L204
  float v117[1][32][32][32];	// L205
  // #pragma HLS stream variable=v117 depth=10 type=fifo

  #pragma HLS bind_storage variable=v117 type=ram_t2p impl=bram

  main_graph_node1(v116, v113, v117);	// L206
  main_graph_node0(v114, v117, v115);	// L207
}

