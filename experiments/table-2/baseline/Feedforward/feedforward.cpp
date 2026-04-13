
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
  float v0[1][512][256],
  float v1[256][128],
  float v2[128],
  float v3[1][512][128]
) {	// L3
  // #pragma HLS dataflow

  float v4[1][256][128];	// L5
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L6
    for (int v6 = 0; v6 < 256; v6 += 1) {	// L7
      for (int v7 = 0; v7 < 128; v7 += 1) {	// L8
        float v8 = v1[v6][v7];	// L9
        v4[v5][v6][v7] = v8;	// L10
      }
    }
  }
  float v9[1][512][128];	// L14
  // #pragma HLS stream variable=v9 depth=10 type=fifo

  #pragma HLS bind_storage variable=v9 type=ram_t2p impl=bram

  for (int v10 = 0; v10 < 1; v10 += 1) {	// L15
    for (int v11 = 0; v11 < 512; v11 += 1) {	// L16
      for (int v12 = 0; v12 < 128; v12 += 1) {	// L17
        v9[v10][v11][v12] = (float)0.000000;	// L18
      }
    }
  }
  for (int v13 = 0; v13 < 1; v13 += 1) {	// L22
    for (int v14 = 0; v14 < 512; v14 += 1) {	// L23
      for (int v15 = 0; v15 < 128; v15 += 1) {	// L24
        for (int v16 = 0; v16 < 256; v16 += 1) {	// L25
          float v17 = v0[v13][v14][v16];	// L26
          float v18 = v4[v13][v16][v15];	// L27
          float v19 = v9[v13][v14][v15];	// L28
          float v20 = v17 * v18;	// L29
          float v21 = v19 + v20;	// L30
          v9[v13][v14][v15] = v21;	// L31
        }
      }
    }
  }
  for (int v22 = 0; v22 < 1; v22 += 1) {	// L36
    for (int v23 = 0; v23 < 512; v23 += 1) {	// L37
      for (int v24 = 0; v24 < 128; v24 += 1) {	// L38
        float v25 = v9[0][v23][v24];	// L39
        float v26 = v2[v24];	// L40
        float v27 = v25 + v26;	// L41
        v3[v22][v23][v24] = v27;	// L42
      }
    }
  }
}

void main_graph_node1(
  float v28[256],
  float v29[1][512][128],
  float v30[128][256],
  float v31[1][512][256]
) {	// L48
  // #pragma HLS dataflow

  float v32[1][512][128];	// L50
  // #pragma HLS stream variable=v32 depth=10 type=fifo

  #pragma HLS bind_storage variable=v32 type=ram_t2p impl=bram

  for (int v33 = 0; v33 < 1; v33 += 1) {	// L51
    for (int v34 = 0; v34 < 512; v34 += 1) {	// L52
      for (int v35 = 0; v35 < 128; v35 += 1) {	// L53
        float v36 = v29[0][v34][v35];	// L54
        v32[v33][v34][v35] = v36;	// L55
      }
    }
  }
  float v37[1][128][256];	// L59
  // #pragma HLS stream variable=v37 depth=10 type=fifo

  #pragma HLS bind_storage variable=v37 type=ram_t2p impl=bram

  for (int v38 = 0; v38 < 1; v38 += 1) {	// L60
    for (int v39 = 0; v39 < 128; v39 += 1) {	// L61
      for (int v40 = 0; v40 < 256; v40 += 1) {	// L62
        float v41 = v30[v39][v40];	// L63
        v37[v38][v39][v40] = v41;	// L64
      }
    }
  }
  float v42[1][512][256];	// L68
  // #pragma HLS stream variable=v42 depth=10 type=fifo

  #pragma HLS bind_storage variable=v42 type=ram_t2p impl=bram

  for (int v43 = 0; v43 < 1; v43 += 1) {	// L69
    for (int v44 = 0; v44 < 512; v44 += 1) {	// L70
      for (int v45 = 0; v45 < 256; v45 += 1) {	// L71
        v42[v43][v44][v45] = (float)0.000000;	// L72
      }
    }
  }
  for (int v46 = 0; v46 < 1; v46 += 1) {	// L76
    for (int v47 = 0; v47 < 512; v47 += 1) {	// L77
      for (int v48 = 0; v48 < 256; v48 += 1) {	// L78
        for (int v49 = 0; v49 < 128; v49 += 1) {	// L79
          float v50 = v32[v46][v47][v49];	// L80
          float v51 = v37[v46][v49][v48];	// L81
          float v52 = v42[v46][v47][v48];	// L82
          float v53 = v50 * v51;	// L83
          float v54 = v52 + v53;	// L84
          v42[v46][v47][v48] = v54;	// L85
        }
      }
    }
  }
  for (int v55 = 0; v55 < 1; v55 += 1) {	// L90
    for (int v56 = 0; v56 < 512; v56 += 1) {	// L91
      for (int v57 = 0; v57 < 256; v57 += 1) {	// L92
        float v58 = v42[0][v56][v57];	// L93
        float v59 = v28[v57];	// L94
        float v60 = v58 + v59;	// L95
        bool v61 = v60 > (float)0.000000;	// L96
        float v62 = v61 ? v60 : (float)0.000000;	// L97
        v31[v55][v56][v57] = v62;	// L98
      }
    }
  }
}

/// This is top function.
void main_graph(
  float v63[1][512][128],
  float v64[128][256],
  float v65[256],
  float v66[128],
  float v67[256][128],
  float v68[1][512][128]
) {	// L104
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v63
  #pragma HLS bind_storage variable=v63 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v64
  #pragma HLS bind_storage variable=v64 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v65
  #pragma HLS bind_storage variable=v65 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v66
  #pragma HLS bind_storage variable=v66 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v67
  #pragma HLS bind_storage variable=v67 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v68
  #pragma HLS bind_storage variable=v68 type=ram_t2p impl=bram

  // // #pragma HLS dataflow

  float v69[1][512][256];	// L106
  // #pragma HLS stream variable=v69 depth=10 type=fifo

  #pragma HLS bind_storage variable=v69 type=ram_t2p impl=bram

  main_graph_node1(v65, v63, v64, v69);	// L107
  main_graph_node0(v69, v67, v66, v68);	// L108
}

