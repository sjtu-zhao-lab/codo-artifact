
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
  float v0[250],
  float v1[250],
  float v2[250][250],
  float v3[250]
) {	// L3
  // #pragma HLS dataflow

  float v4[250];	// L7
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 250; v5 += 1) {	// L8
    v4[v5] = (float)0.000000;	// L9
  }
  for (int v6 = 0; v6 < 250; v6 += 1) {	// L11
    for (int v7 = 0; v7 < 250; v7 += 1) {	// L12
      float v8 = v2[v6][v7];	// L13
      float v9 = v1[v7];	// L14
      float v10 = v4[v6];	// L15
      float v11 = v8 * v9;	// L16
      float v12 = v10 + v11;	// L17
      v4[v6] = v12;	// L18
    }
  }
  for (int v13 = 0; v13 < 250; v13 += 1) {	// L21
    float v14 = v0[v13];	// L22
    float v15 = v4[v13];	// L23
    float v16 = (double)1.200000;	// L24
    float v17 = v15 * v16;	// L25
    float v18 = v14 * (float)1.500000;	// L26
    float v19 = v18 + v17;	// L27
    v3[v13] = v19;	// L28
  }
}

void main_graph_node1(
  float v20[250][250],
  float v21[250],
  float v22[250]
) {	// L32
  // #pragma HLS dataflow

  for (int v23 = 0; v23 < 250; v23 += 1) {	// L34
    v22[v23] = (float)0.000000;	// L35
  }
  for (int v24 = 0; v24 < 250; v24 += 1) {	// L37
    for (int v25 = 0; v25 < 250; v25 += 1) {	// L38
      float v26 = v20[v24][v25];	// L39
      float v27 = v21[v25];	// L40
      float v28 = v22[v24];	// L41
      float v29 = v26 * v27;	// L42
      float v30 = v28 + v29;	// L43
      v22[v24] = v30;	// L44
    }
  }
}

/// This is top function.
void main_graph(
  float v31[250][250],
  float v32[250][250],
  float v33[250],
  float v34[250]
) {	// L49
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v31
  #pragma HLS bind_storage variable=v31 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v32
  #pragma HLS bind_storage variable=v32 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v33
  #pragma HLS bind_storage variable=v33 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v34
  #pragma HLS bind_storage variable=v34 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  float v35[250];	// L51
  // #pragma HLS stream variable=v35 depth=10 type=fifo

  #pragma HLS bind_storage variable=v35 type=ram_t2p impl=bram

  main_graph_node1(v31, v33, v35);	// L52
  main_graph_node0(v35, v33, v32, v34);	// L53
}

