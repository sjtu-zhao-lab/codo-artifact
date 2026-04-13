
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
  float v0[256][10],
  float v1[10],
  float v2[8][256],
  float v3[8][10]
) {	// L3
  // #pragma HLS stream

  float v4[8][10];	// L5
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 8; v5 += 1) {	// L6
    for (int v6 = 0; v6 < 10; v6 += 1) {	// L7
      v4[v5][v6] = (float)0.000000;	// L8
    }
  }
  for (int v7 = 0; v7 < 8; v7 += 1) {	// L11
    for (int v8 = 0; v8 < 10; v8 += 1) {	// L12
      for (int v9 = 0; v9 < 256; v9 += 1) {	// L13
        float v10 = v2[v7][v9];	// L14
        float v11 = v0[v9][v8];	// L15
        float v12 = v4[v7][v8];	// L16
        float v13 = v10 * v11;	// L17
        float v14 = v12 + v13;	// L18
        v4[v7][v8] = v14;	// L19
      }
    }
  }
  for (int v15 = 0; v15 < 8; v15 += 1) {	// L23
    for (int v16 = 0; v16 < 10; v16 += 1) {	// L24
      float v17 = v4[v15][v16];	// L25
      float v18 = v1[v16];	// L26
      float v19 = v17 + v18;	// L27
      v3[v15][v16] = v19;	// L28
    }
  }
}

void main_graph_node1(
  float v20[256],
  float v21[8][512],
  float v22[512][256],
  float v23[8][256]
) {	// L33
  // #pragma HLS stream

  float v24[8][256];	// L35
  // #pragma HLS stream variable=v24 depth=10 type=fifo

  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  for (int v25 = 0; v25 < 8; v25 += 1) {	// L36
    for (int v26 = 0; v26 < 256; v26 += 1) {	// L37
      v24[v25][v26] = (float)0.000000;	// L38
    }
  }
  for (int v27 = 0; v27 < 8; v27 += 1) {	// L41
    for (int v28 = 0; v28 < 256; v28 += 1) {	// L42
      for (int v29 = 0; v29 < 512; v29 += 1) {	// L43
        float v30 = v21[v27][v29];	// L44
        float v31 = v22[v29][v28];	// L45
        float v32 = v24[v27][v28];	// L46
        float v33 = v30 * v31;	// L47
        float v34 = v32 + v33;	// L48
        v24[v27][v28] = v34;	// L49
      }
    }
  }
  for (int v35 = 0; v35 < 8; v35 += 1) {	// L53
    for (int v36 = 0; v36 < 256; v36 += 1) {	// L54
      float v37 = v24[v35][v36];	// L55
      float v38 = v20[v36];	// L56
      float v39 = v37 + v38;	// L57
      v23[v35][v36] = v39;	// L58
    }
  }
}

void main_graph_node2(
  float v40[8][512],
  float v41[512],
  float v42[512][512],
  float v43[8][512],
  float v44[8][512]
) {	// L63
  // #pragma HLS stream

  float v45[8][512];	// L65
  // #pragma HLS stream variable=v45 depth=10 type=fifo

  #pragma HLS bind_storage variable=v45 type=ram_t2p impl=bram

  for (int v46 = 0; v46 < 8; v46 += 1) {	// L66
    for (int v47 = 0; v47 < 512; v47 += 1) {	// L67
      v45[v46][v47] = (float)0.000000;	// L68
    }
  }
  for (int v48 = 0; v48 < 8; v48 += 1) {	// L71
    for (int v49 = 0; v49 < 512; v49 += 1) {	// L72
      for (int v50 = 0; v50 < 512; v50 += 1) {	// L73
        float v51 = v43[v48][v50];	// L74
        float v52 = v42[v50][v49];	// L75
        float v53 = v45[v48][v49];	// L76
        float v54 = v51 * v52;	// L77
        float v55 = v53 + v54;	// L78
        v45[v48][v49] = v55;	// L79
      }
    }
  }
  for (int v56 = 0; v56 < 8; v56 += 1) {	// L83
    for (int v57 = 0; v57 < 512; v57 += 1) {	// L84
      float v58 = v45[v56][v57];	// L85
      float v59 = v41[v57];	// L86
      float v60 = v40[v56][v57];	// L87
      float v61 = v58 + v59;	// L88
      float v62 = v61 + v60;	// L89
      bool v63 = v62 > (float)0.000000;	// L90
      float v64 = v63 ? v62 : (float)0.000000;	// L91
      v44[v56][v57] = v64;	// L92
    }
  }
}

void main_graph_node3(
  float v65[512],
  float v66[1024][512],
  float v67[8][1024],
  float v68[8][512],
  float v69[8][512]
) {	// L97
  // #pragma HLS stream

  float v70[8][512];	// L99
  // #pragma HLS stream variable=v70 depth=10 type=fifo

  #pragma HLS bind_storage variable=v70 type=ram_t2p impl=bram

  for (int v71 = 0; v71 < 8; v71 += 1) {	// L100
    for (int v72 = 0; v72 < 512; v72 += 1) {	// L101
      v70[v71][v72] = (float)0.000000;	// L102
    }
  }
  for (int v73 = 0; v73 < 8; v73 += 1) {	// L105
    for (int v74 = 0; v74 < 512; v74 += 1) {	// L106
      for (int v75 = 0; v75 < 1024; v75 += 1) {	// L107
        float v76 = v67[v73][v75];	// L108
        float v77 = v66[v75][v74];	// L109
        float v78 = v70[v73][v74];	// L110
        float v79 = v76 * v77;	// L111
        float v80 = v78 + v79;	// L112
        v70[v73][v74] = v80;	// L113
      }
    }
  }
  for (int v81 = 0; v81 < 8; v81 += 1) {	// L117
    for (int v82 = 0; v82 < 512; v82 += 1) {	// L118
      float v83 = v70[v81][v82];	// L119
      float v84 = v65[v82];	// L120
      float v85 = v83 + v84;	// L121
      v68[v81][v82] = v85;	// L122
    }
  }
  for (int v86 = 0; v86 < 8; v86 += 1) {	// L125
    for (int v87 = 0; v87 < 512; v87 += 1) {	// L126
      float v88 = v68[v86][v87];	// L127
      bool v89 = v88 > (float)0.000000;	// L128
      float v90 = v89 ? v88 : (float)0.000000;	// L129
      v69[v86][v87] = v90;	// L130
    }
  }
}

/// This is top function.
void main_graph(
  float v91[8][1024],
  float v92[1024][512],
  float v93[512],
  float v94[512],
  float v95[256],
  float v96[10],
  float v97[512][512],
  float v98[512][256],
  float v99[256][10],
  float v100[8][10]
) {	// L135
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v91
  #pragma HLS bind_storage variable=v91 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v92
  #pragma HLS bind_storage variable=v92 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v93
  #pragma HLS bind_storage variable=v93 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v94
  #pragma HLS bind_storage variable=v94 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v95
  #pragma HLS bind_storage variable=v95 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v96
  #pragma HLS bind_storage variable=v96 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v97
  #pragma HLS bind_storage variable=v97 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v98
  #pragma HLS bind_storage variable=v98 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v99
  #pragma HLS bind_storage variable=v99 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v100
  #pragma HLS bind_storage variable=v100 type=ram_t2p impl=bram

  // // #pragma HLS stream

  float v101[8][512];	// L137
  // #pragma HLS stream variable=v101 depth=10 type=fifo

  #pragma HLS bind_storage variable=v101 type=ram_t2p impl=bram

  float v102[8][512];	// L138
  // #pragma HLS stream variable=v102 depth=10 type=fifo

  #pragma HLS bind_storage variable=v102 type=ram_t2p impl=bram

  main_graph_node3(v93, v92, v91, v101, v102);	// L139
  float v103[8][512];	// L140
  // #pragma HLS stream variable=v103 depth=10 type=fifo

  #pragma HLS bind_storage variable=v103 type=ram_t2p impl=bram

  main_graph_node2(v101, v94, v97, v102, v103);	// L141
  float v104[8][256];	// L142
  // #pragma HLS stream variable=v104 depth=10 type=fifo

  #pragma HLS bind_storage variable=v104 type=ram_t2p impl=bram

  main_graph_node1(v95, v103, v98, v104);	// L143
  main_graph_node0(v99, v96, v104, v100);	// L144
}

