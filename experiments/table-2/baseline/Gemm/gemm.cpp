
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
  float v0[200][240],
  float v1[200][220],
  float v2[240][220],
  float v3[200][220]
) {	// L3
  // #pragma HLS dataflow

  float v4[200][220];	// L7
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 200; v5 += 1) {	// L8
    for (int v6 = 0; v6 < 220; v6 += 1) {	// L9
      v4[v5][v6] = (float)0.000000;	// L10
    }
  }
  for (int v7 = 0; v7 < 200; v7 += 1) {	// L13
    for (int v8 = 0; v8 < 220; v8 += 1) {	// L14
      for (int v9 = 0; v9 < 240; v9 += 1) {	// L15
        float v10 = v0[v7][v9];	// L16
        float v11 = v2[v9][v8];	// L17
        float v12 = v4[v7][v8];	// L18
        float v13 = v10 * v11;	// L19
        float v14 = v12 + v13;	// L20
        v4[v7][v8] = v14;	// L21
      }
    }
  }
  for (int v15 = 0; v15 < 200; v15 += 1) {	// L25
    for (int v16 = 0; v16 < 220; v16 += 1) {	// L26
      float v17 = v4[v15][v16];	// L27
      float v18 = v1[v15][v16];	// L28
      float v19 = (double)0.100000;	// L29
      float v20 = v18 * v19;	// L30
      float v21 = v17 * (float)0.500000;	// L31
      float v22 = v21 + v20;	// L32
      v3[v15][v16] = v22;	// L33
    }
  }
}

/// This is top function.
void main_graph(
  float v23[200][240],
  float v24[240][220],
  float v25[200][220],
  float v26[200][220]
) {	// L38
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v23
  #pragma HLS bind_storage variable=v23 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v24
  #pragma HLS bind_storage variable=v24 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v25
  #pragma HLS bind_storage variable=v25 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v26
  #pragma HLS bind_storage variable=v26 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  main_graph_node0(v23, v25, v24, v26);	// L40
}

