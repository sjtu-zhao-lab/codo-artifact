
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

void forward_node0(
  float v0[400][400],
  float v1[400],
  float v2[400]
) {	// L3
  // #pragma HLS dataflow

  float v3[400][400];	// L5
  // #pragma HLS stream variable=v3 depth=10 type=fifo

  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  for (int v4 = 0; v4 < 400; v4 += 1) {	// L6
    for (int v5 = 0; v5 < 400; v5 += 1) {	// L7
      float v6 = v0[v4][v5];	// L8
      v3[v5][v4] = v6;	// L9
    }
  }
  for (int v7 = 0; v7 < 400; v7 += 1) {	// L12
    v2[v7] = (float)0.000000;	// L13
  }
  for (int v8 = 0; v8 < 400; v8 += 1) {	// L15
    for (int v9 = 0; v9 < 400; v9 += 1) {	// L16
      float v10 = v3[v8][v9];	// L17
      float v11 = v1[v9];	// L18
      float v12 = v2[v8];	// L19
      float v13 = v10 * v11;	// L20
      float v14 = v12 + v13;	// L21
      v2[v8] = v14;	// L22
    }
  }
}

void forward_node1(
  float v15[400][400],
  float v16[400],
  float v17[400]
) {	// L27
  // #pragma HLS dataflow

  for (int v18 = 0; v18 < 400; v18 += 1) {	// L29
    v17[v18] = (float)0.000000;	// L30
  }
  for (int v19 = 0; v19 < 400; v19 += 1) {	// L32
    for (int v20 = 0; v20 < 400; v20 += 1) {	// L33
      float v21 = v15[v19][v20];	// L34
      float v22 = v16[v20];	// L35
      float v23 = v17[v19];	// L36
      float v24 = v21 * v22;	// L37
      float v25 = v23 + v24;	// L38
      v17[v19] = v25;	// L39
    }
  }
}

/// This is top function.
void forward(
  float v26[400][400],
  float v27[400][400],
  float v28[400],
  float v29[400],
  float v30[400],
  float v31[400]
) {	// L44
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v26
  #pragma HLS bind_storage variable=v26 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v27
  #pragma HLS bind_storage variable=v27 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v28
  #pragma HLS bind_storage variable=v28 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v29
  #pragma HLS bind_storage variable=v29 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v30
  #pragma HLS bind_storage variable=v30 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v31
  #pragma HLS bind_storage variable=v31 type=ram_t2p impl=bram

  // #pragma HLS dataflow

  forward_node1(v26, v28, v30);	// L47
  forward_node0(v27, v29, v31);	// L48
}

