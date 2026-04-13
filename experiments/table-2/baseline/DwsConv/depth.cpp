
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
  float v0[1][64][112][112],
  float v1[64][64][1][1],
  float v2[1][64][112][112]
) {	// L3
  // #pragma HLS dataflow

  float v3[1][64][112][112];	// L7
  // #pragma HLS stream variable=v3 depth=10 type=fifo

  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  for (int v4 = 0; v4 < 1; v4 += 1) {	// L8
    for (int v5 = 0; v5 < 64; v5 += 1) {	// L9
      for (int v6 = 0; v6 < 112; v6 += 1) {	// L10
        for (int v7 = 0; v7 < 112; v7 += 1) {	// L11
          v3[v4][v5][v6][v7] = (float)0.000000;	// L12
        }
      }
    }
  }
  for (int v8 = 0; v8 < 1; v8 += 1) {	// L17
    for (int v9 = 0; v9 < 64; v9 += 1) {	// L18
      for (int v10 = 0; v10 < 112; v10 += 1) {	// L19
        for (int v11 = 0; v11 < 112; v11 += 1) {	// L20
          for (int v12 = 0; v12 < 64; v12 += 1) {	// L21
            for (int v13 = 0; v13 < 1; v13 += 1) {	// L22
              for (int v14 = 0; v14 < 1; v14 += 1) {	// L23
                float v15 = v0[v8][v12][(v10 + v13)][(v11 + v14)];	// L24
                float v16 = v1[v9][v12][v13][v14];	// L25
                float v17 = v3[v8][v9][v10][v11];	// L26
                float v18 = v15 * v16;	// L27
                float v19 = v17 + v18;	// L28
                v3[v8][v9][v10][v11] = v19;	// L29
              }
            }
          }
        }
      }
    }
  }
  for (int v20 = 0; v20 < 1; v20 += 1) {	// L37
    for (int v21 = 0; v21 < 64; v21 += 1) {	// L38
      for (int v22 = 0; v22 < 112; v22 += 1) {	// L39
        for (int v23 = 0; v23 < 112; v23 += 1) {	// L40
          float v24 = v3[0][v21][v22][v23];	// L41
          float v25 = (double)0.000010;	// L42
          float v26 = v25 + (float)1.000000;	// L43
          float v27 = 1.0 / sqrt(v26);	// L44
          float v28 = v24 * v27;	// L45
          float v29 = v28 + (float)0.000000;	// L46
          bool v30 = v29 > (float)0.000000;	// L47
          float v31 = v30 ? v29 : (float)0.000000;	// L48
          v2[v20][v21][v22][v23] = v31;	// L49
        }
      }
    }
  }
}

void main_graph_node1(
  float v32[1][64][112][112],
  float v33[64][3][3],
  float v34[1][64][112][112]
) {	// L56
  // #pragma HLS dataflow

  float v35[1][64][114][114];	// L58
  // #pragma HLS stream variable=v35 depth=10 type=fifo

  #pragma HLS bind_storage variable=v35 type=ram_t2p impl=bram

  for (int v36 = 0; v36 < 1; v36 += 1) {	// L59
    for (int v37 = 0; v37 < 64; v37 += 1) {	// L60
      for (int v38 = 0; v38 < 114; v38 += 1) {	// L61
        for (int v39 = 0; v39 < 114; v39 += 1) {	// L62
          v35[v36][v37][v38][v39] = (float)0.000000;	// L63
        }
      }
    }
  }
  for (int v40 = 0; v40 < 1; v40 += 1) {	// L68
    for (int v41 = 0; v41 < 64; v41 += 1) {	// L69
      for (int v42 = 0; v42 < 112; v42 += 1) {	// L70
        for (int v43 = 0; v43 < 112; v43 += 1) {	// L71
          float v44 = v32[v40][v41][v42][v43];	// L72
          v35[v40][v41][(v42 + 1)][(v43 + 1)] = v44;	// L73
        }
      }
    }
  }
  for (int v45 = 0; v45 < 1; v45 += 1) {	// L78
    for (int v46 = 0; v46 < 64; v46 += 1) {	// L79
      for (int v47 = 0; v47 < 112; v47 += 1) {	// L80
        for (int v48 = 0; v48 < 112; v48 += 1) {	// L81
          v34[v45][v46][v47][v48] = (float)0.000000;	// L82
        }
      }
    }
  }
  for (int v49 = 0; v49 < 1; v49 += 1) {	// L87
    for (int v50 = 0; v50 < 112; v50 += 1) {	// L88
      for (int v51 = 0; v51 < 112; v51 += 1) {	// L89
        for (int v52 = 0; v52 < 64; v52 += 1) {	// L90
          for (int v53 = 0; v53 < 3; v53 += 1) {	// L91
            for (int v54 = 0; v54 < 3; v54 += 1) {	// L92
              float v55 = v35[v49][v52][(v50 + v53)][(v51 + v54)];	// L93
              float v56 = v33[v52][v53][v54];	// L94
              float v57 = v34[v49][v52][v50][v51];	// L95
              float v58 = v55 * v56;	// L96
              float v59 = v57 + v58;	// L97
              v34[v49][v52][v50][v51] = v59;	// L98
            }
          }
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  float v60[1][64][112][112],
  float v61[64][64][1][1],
  float v62[64][3][3],
  float v63[1][64][112][112]
) {	// L107
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v60
  #pragma HLS bind_storage variable=v60 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v61
  #pragma HLS bind_storage variable=v61 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v62
  #pragma HLS bind_storage variable=v62 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v63
  #pragma HLS bind_storage variable=v63 type=ram_t2p impl=bram

  // // #pragma HLS dataflow

  float v64[1][64][112][112];	// L109
  // #pragma HLS stream variable=v64 depth=10 type=fifo

  #pragma HLS bind_storage variable=v64 type=ram_t2p impl=bram

  main_graph_node1(v60, v62, v64);	// L110
  main_graph_node0(v64, v61, v63);	// L111
}

