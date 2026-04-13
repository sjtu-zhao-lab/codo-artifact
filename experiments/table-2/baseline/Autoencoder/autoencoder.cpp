
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
  float v0[512],
  float v1[256][512],
  float v2[128][256],
  float v3[128][512]
) {	// L3
  // #pragma HLS dataflow

  float v4[128][512];	// L6
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 128; v5 += 1) {	// L7
    for (int v6 = 0; v6 < 512; v6 += 1) {	// L8
      v4[v5][v6] = (float)0.000000;	// L9
    }
  }
  for (int v7 = 0; v7 < 128; v7 += 1) {	// L12
    for (int v8 = 0; v8 < 512; v8 += 1) {	// L13
      for (int v9 = 0; v9 < 256; v9 += 1) {	// L14
        float v10 = v2[v7][v9];	// L15
        float v11 = v1[v9][v8];	// L16
        float v12 = v4[v7][v8];	// L17
        float v13 = v10 * v11;	// L18
        float v14 = v12 + v13;	// L19
        v4[v7][v8] = v14;	// L20
      }
    }
  }
  for (int v15 = 0; v15 < 128; v15 += 1) {	// L24
    for (int v16 = 0; v16 < 512; v16 += 1) {	// L25
      float v17 = v4[v15][v16];	// L26
      float v18 = v0[v16];	// L27
      float v19 = v17 + v18;	// L28
      float v20 = -(v19);	// L29
      float v21 = exp(v20);	// L30
      float v22 = v21 + (float)1.000000;	// L31
      float v23 = (float)1.000000 / v22;	// L32
      v3[v15][v16] = v23;	// L33
    }
  }
}

void main_graph_node1(
  float v24[128][128],
  float v25[256],
  float v26[128][256],
  float v27[128][256]
) {	// L38
  // #pragma HLS dataflow

  float v28[128][256];	// L40
  // #pragma HLS stream variable=v28 depth=10 type=fifo

  #pragma HLS bind_storage variable=v28 type=ram_t2p impl=bram

  for (int v29 = 0; v29 < 128; v29 += 1) {	// L41
    for (int v30 = 0; v30 < 256; v30 += 1) {	// L42
      v28[v29][v30] = (float)0.000000;	// L43
    }
  }
  for (int v31 = 0; v31 < 128; v31 += 1) {	// L46
    for (int v32 = 0; v32 < 256; v32 += 1) {	// L47
      for (int v33 = 0; v33 < 128; v33 += 1) {	// L48
        float v34 = v24[v31][v33];	// L49
        float v35 = v26[v33][v32];	// L50
        float v36 = v28[v31][v32];	// L51
        float v37 = v34 * v35;	// L52
        float v38 = v36 + v37;	// L53
        v28[v31][v32] = v38;	// L54
      }
    }
  }
  for (int v39 = 0; v39 < 128; v39 += 1) {	// L58
    for (int v40 = 0; v40 < 256; v40 += 1) {	// L59
      float v41 = v28[v39][v40];	// L60
      float v42 = v25[v40];	// L61
      float v43 = v41 + v42;	// L62
      bool v44 = v43 > (float)0.000000;	// L63
      float v45 = v44 ? v43 : (float)0.000000;	// L64
      v27[v39][v40] = v45;	// L65
    }
  }
}

void main_graph_node2(
  float v46[128][64],
  float v47[128],
  float v48[64][128],
  float v49[128][128]
) {	// L70
  // #pragma HLS dataflow

  float v50[128][128];	// L72
  // #pragma HLS stream variable=v50 depth=10 type=fifo

  #pragma HLS bind_storage variable=v50 type=ram_t2p impl=bram

  for (int v51 = 0; v51 < 128; v51 += 1) {	// L73
    for (int v52 = 0; v52 < 128; v52 += 1) {	// L74
      v50[v51][v52] = (float)0.000000;	// L75
    }
  }
  for (int v53 = 0; v53 < 128; v53 += 1) {	// L78
    for (int v54 = 0; v54 < 128; v54 += 1) {	// L79
      for (int v55 = 0; v55 < 64; v55 += 1) {	// L80
        float v56 = v46[v53][v55];	// L81
        float v57 = v48[v55][v54];	// L82
        float v58 = v50[v53][v54];	// L83
        float v59 = v56 * v57;	// L84
        float v60 = v58 + v59;	// L85
        v50[v53][v54] = v60;	// L86
      }
    }
  }
  for (int v61 = 0; v61 < 128; v61 += 1) {	// L90
    for (int v62 = 0; v62 < 128; v62 += 1) {	// L91
      float v63 = v50[v61][v62];	// L92
      float v64 = v47[v62];	// L93
      float v65 = v63 + v64;	// L94
      bool v66 = v65 > (float)0.000000;	// L95
      float v67 = v66 ? v65 : (float)0.000000;	// L96
      v49[v61][v62] = v67;	// L97
    }
  }
}

void main_graph_node3(
  float v68[128][128],
  float v69[128][64],
  float v70[64],
  float v71[128][64]
) {	// L102
  // #pragma HLS dataflow

  float v72[128][64];	// L104
  // #pragma HLS stream variable=v72 depth=10 type=fifo

  #pragma HLS bind_storage variable=v72 type=ram_t2p impl=bram

  for (int v73 = 0; v73 < 128; v73 += 1) {	// L105
    for (int v74 = 0; v74 < 64; v74 += 1) {	// L106
      v72[v73][v74] = (float)0.000000;	// L107
    }
  }
  for (int v75 = 0; v75 < 128; v75 += 1) {	// L110
    for (int v76 = 0; v76 < 64; v76 += 1) {	// L111
      for (int v77 = 0; v77 < 128; v77 += 1) {	// L112
        float v78 = v68[v75][v77];	// L113
        float v79 = v69[v77][v76];	// L114
        float v80 = v72[v75][v76];	// L115
        float v81 = v78 * v79;	// L116
        float v82 = v80 + v81;	// L117
        v72[v75][v76] = v82;	// L118
      }
    }
  }
  for (int v83 = 0; v83 < 128; v83 += 1) {	// L122
    for (int v84 = 0; v84 < 64; v84 += 1) {	// L123
      float v85 = v72[v83][v84];	// L124
      float v86 = v70[v84];	// L125
      float v87 = v85 + v86;	// L126
      v71[v83][v84] = v87;	// L127
    }
  }
}

void main_graph_node4(
  float v88[128][256],
  float v89[256][128],
  float v90[128],
  float v91[128][128]
) {	// L132
  // #pragma HLS dataflow

  float v92[128][128];	// L134
  // #pragma HLS stream variable=v92 depth=10 type=fifo

  #pragma HLS bind_storage variable=v92 type=ram_t2p impl=bram

  for (int v93 = 0; v93 < 128; v93 += 1) {	// L135
    for (int v94 = 0; v94 < 128; v94 += 1) {	// L136
      v92[v93][v94] = (float)0.000000;	// L137
    }
  }
  for (int v95 = 0; v95 < 128; v95 += 1) {	// L140
    for (int v96 = 0; v96 < 128; v96 += 1) {	// L141
      for (int v97 = 0; v97 < 256; v97 += 1) {	// L142
        float v98 = v88[v95][v97];	// L143
        float v99 = v89[v97][v96];	// L144
        float v100 = v92[v95][v96];	// L145
        float v101 = v98 * v99;	// L146
        float v102 = v100 + v101;	// L147
        v92[v95][v96] = v102;	// L148
      }
    }
  }
  for (int v103 = 0; v103 < 128; v103 += 1) {	// L152
    for (int v104 = 0; v104 < 128; v104 += 1) {	// L153
      float v105 = v92[v103][v104];	// L154
      float v106 = v90[v104];	// L155
      float v107 = v105 + v106;	// L156
      bool v108 = v107 > (float)0.000000;	// L157
      float v109 = v108 ? v107 : (float)0.000000;	// L158
      v91[v103][v104] = v109;	// L159
    }
  }
}

void main_graph_node5(
  float v110[256],
  float v111[128][512],
  float v112[512][256],
  float v113[128][256]
) {	// L164
  // #pragma HLS dataflow

  float v114[128][256];	// L166
  // #pragma HLS stream variable=v114 depth=10 type=fifo

  #pragma HLS bind_storage variable=v114 type=ram_t2p impl=bram

  for (int v115 = 0; v115 < 128; v115 += 1) {	// L167
    for (int v116 = 0; v116 < 256; v116 += 1) {	// L168
      v114[v115][v116] = (float)0.000000;	// L169
    }
  }
  for (int v117 = 0; v117 < 128; v117 += 1) {	// L172
    for (int v118 = 0; v118 < 256; v118 += 1) {	// L173
      for (int v119 = 0; v119 < 512; v119 += 1) {	// L174
        float v120 = v111[v117][v119];	// L175
        float v121 = v112[v119][v118];	// L176
        float v122 = v114[v117][v118];	// L177
        float v123 = v120 * v121;	// L178
        float v124 = v122 + v123;	// L179
        v114[v117][v118] = v124;	// L180
      }
    }
  }
  for (int v125 = 0; v125 < 128; v125 += 1) {	// L184
    for (int v126 = 0; v126 < 256; v126 += 1) {	// L185
      float v127 = v114[v125][v126];	// L186
      float v128 = v110[v126];	// L187
      float v129 = v127 + v128;	// L188
      bool v130 = v129 > (float)0.000000;	// L189
      float v131 = v130 ? v129 : (float)0.000000;	// L190
      v113[v125][v126] = v131;	// L191
    }
  }
}

/// This is top function.
void main_graph(
  float v132[128][512],
  float v133[512][256],
  float v134[256],
  float v135[128],
  float v136[64],
  float v137[128],
  float v138[256],
  float v139[512],
  float v140[256][128],
  float v141[128][64],
  float v142[64][128],
  float v143[128][256],
  float v144[256][512],
  float v145[128][512]
) {	// L196
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v132
  #pragma HLS bind_storage variable=v132 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v133
  #pragma HLS bind_storage variable=v133 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v134
  #pragma HLS bind_storage variable=v134 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v135
  #pragma HLS bind_storage variable=v135 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v136
  #pragma HLS bind_storage variable=v136 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v137
  #pragma HLS bind_storage variable=v137 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v138
  #pragma HLS bind_storage variable=v138 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v139
  #pragma HLS bind_storage variable=v139 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v140
  #pragma HLS bind_storage variable=v140 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v141
  #pragma HLS bind_storage variable=v141 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v142
  #pragma HLS bind_storage variable=v142 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v143
  #pragma HLS bind_storage variable=v143 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v144
  #pragma HLS bind_storage variable=v144 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v145
  #pragma HLS bind_storage variable=v145 type=ram_t2p impl=bram

  // // #pragma HLS dataflow

  float v146[128][256];	// L198
  // #pragma HLS stream variable=v146 depth=10 type=fifo

  #pragma HLS bind_storage variable=v146 type=ram_t2p impl=bram

  main_graph_node5(v134, v132, v133, v146);	// L199
  float v147[128][128];	// L200
  // #pragma HLS stream variable=v147 depth=10 type=fifo

  #pragma HLS bind_storage variable=v147 type=ram_t2p impl=bram

  main_graph_node4(v146, v140, v135, v147);	// L201
  float v148[128][64];	// L202
  // #pragma HLS stream variable=v148 depth=10 type=fifo

  #pragma HLS bind_storage variable=v148 type=ram_t2p impl=bram

  main_graph_node3(v147, v141, v136, v148);	// L203
  float v149[128][128];	// L204
  // #pragma HLS stream variable=v149 depth=10 type=fifo

  #pragma HLS bind_storage variable=v149 type=ram_t2p impl=bram

  main_graph_node2(v148, v137, v142, v149);	// L205
  float v150[128][256];	// L206
  // #pragma HLS stream variable=v150 depth=10 type=fifo

  #pragma HLS bind_storage variable=v150 type=ram_t2p impl=bram

  main_graph_node1(v149, v138, v143, v150);	// L207
  main_graph_node0(v139, v144, v150, v145);	// L208
}

