
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
  float v0[180][180],
  float v1[180][210],
  float v2[180][210]
) {	// L3
  // #pragma HLS dataflow

  for (int v3 = 0; v3 < 180; v3 += 1) {	// L5
    for (int v4 = 0; v4 < 210; v4 += 1) {	// L6
      v2[v3][v4] = (float)0.000000;	// L7
    }
  }
  for (int v5 = 0; v5 < 180; v5 += 1) {	// L10
    for (int v6 = 0; v6 < 210; v6 += 1) {	// L11
      for (int v7 = 0; v7 < 180; v7 += 1) {	// L12
        float v8 = v0[v5][v7];	// L13
        float v9 = v1[v7][v6];	// L14
        float v10 = v2[v5][v6];	// L15
        float v11 = v8 * v9;	// L16
        float v12 = v10 + v11;	// L17
        v2[v5][v6] = v12;	// L18
      }
    }
  }
}

void main_graph_node1(
  float v13[180][220],
  float v14[220][210],
  float v15[180][210]
) {	// L24
  // #pragma HLS dataflow

  for (int v16 = 0; v16 < 180; v16 += 1) {	// L26
    for (int v17 = 0; v17 < 210; v17 += 1) {	// L27
      v15[v16][v17] = (float)0.000000;	// L28
    }
  }
  for (int v18 = 0; v18 < 180; v18 += 1) {	// L31
    for (int v19 = 0; v19 < 210; v19 += 1) {	// L32
      for (int v20 = 0; v20 < 220; v20 += 1) {	// L33
        float v21 = v13[v18][v20];	// L34
        float v22 = v14[v20][v19];	// L35
        float v23 = v15[v18][v19];	// L36
        float v24 = v21 * v22;	// L37
        float v25 = v23 + v24;	// L38
        v15[v18][v19] = v25;	// L39
      }
    }
  }
}

void main_graph_node2(
  float v26[180][210],
  float v27[210][180],
  float v28[180][180]
) {	// L45
  // #pragma HLS dataflow

  for (int v29 = 0; v29 < 180; v29 += 1) {	// L47
    for (int v30 = 0; v30 < 180; v30 += 1) {	// L48
      v28[v29][v30] = (float)0.000000;	// L49
    }
  }
  for (int v31 = 0; v31 < 180; v31 += 1) {	// L52
    for (int v32 = 0; v32 < 180; v32 += 1) {	// L53
      for (int v33 = 0; v33 < 210; v33 += 1) {	// L54
        float v34 = v26[v31][v33];	// L55
        float v35 = v27[v33][v32];	// L56
        float v36 = v28[v31][v32];	// L57
        float v37 = v34 * v35;	// L58
        float v38 = v36 + v37;	// L59
        v28[v31][v32] = v38;	// L60
      }
    }
  }
}

/// This is top function.
void main_graph(
  float v39[180][210],
  float v40[210][180],
  float v41[180][220],
  float v42[220][210],
  float v43[180][210]
) {	// L66
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v39
  #pragma HLS bind_storage variable=v39 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v40
  #pragma HLS bind_storage variable=v40 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v41
  #pragma HLS bind_storage variable=v41 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v42
  #pragma HLS bind_storage variable=v42 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v43
  #pragma HLS bind_storage variable=v43 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  float v44[180][180];	// L68
  // #pragma HLS stream variable=v44 depth=10 type=fifo

  #pragma HLS bind_storage variable=v44 type=ram_t2p impl=bram

  main_graph_node2(v39, v40, v44);	// L69
  float v45[180][210];	// L70
  // #pragma HLS stream variable=v45 depth=10 type=fifo

  #pragma HLS bind_storage variable=v45 type=ram_t2p impl=bram

  main_graph_node1(v41, v42, v45);	// L71
  main_graph_node0(v44, v45, v43);	// L72
}

