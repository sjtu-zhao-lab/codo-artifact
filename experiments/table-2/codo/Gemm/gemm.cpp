
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
  float v1[240][220],
  float v2[200][220],
  float v3[200][220]
) {	// L5
  #pragma HLS dataflow

  float v4[240][220];	// L9
  #pragma HLS array_partition variable=v4 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v4 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v4 type=ram_2p impl=bram

  float v5[200][240];	// L10
  #pragma HLS array_partition variable=v5 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v5 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v5 type=ram_2p impl=bram

  float v6[200][220];	// L11
  #pragma HLS stream variable=v6 depth=10 type=fifo

  #pragma HLS array_partition variable=v6 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v6 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v6 type=ram_t2p impl=bram

  float v7[200][220];	// L12
  #pragma HLS stream variable=v7 depth=10 type=fifo

  #pragma HLS array_partition variable=v7 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v7 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v7 type=ram_2p impl=bram

  float v8[200][220];	// L13
  #pragma HLS array_partition variable=v8 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v8 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v8 type=ram_2p impl=bram

  for (int v9 = 0; v9 < 40; v9 += 1) {	// L14
    for (int v10 = 0; v10 < 44; v10 += 1) {	// L15
      #pragma HLS pipeline II=1
      for (int v11 = 0; v11 < 5; v11 += 1) {	// L16
        for (int v12 = 0; v12 < 5; v12 += 1) {	// L17
          v7[(v11 + (v9 * 5))][(v12 + (v10 * 5))] = (float)0.000000;	// L18
        }
      }
    }
  }
  for (int v13 = 0; v13 < 40; v13 += 1) {	// L23
    for (int v14 = 0; v14 < 48; v14 += 1) {	// L24
      for (int v15 = 0; v15 < 44; v15 += 1) {	// L25
        #pragma HLS pipeline II=1
        for (int v16 = 0; v16 < 5; v16 += 1) {	// L26
          for (int v17 = 0; v17 < 5; v17 += 1) {	// L27
            for (int v18 = 0; v18 < 5; v18 += 1) {	// L28
              if ((v18 + (v15 * 5)) == 0) {	// L29
                float v19 = v0[(v16 + (v13 * 5))][(v17 + (v14 * 5))];	// L30
                v5[(v16 + (v13 * 5))][(v17 + (v14 * 5))] = v19;	// L31
              }
              float v20 = v5[(v16 + (v13 * 5))][(v17 + (v14 * 5))];	// L33
              if ((v16 + (v13 * 5)) == 0) {	// L34
                float v21 = v1[(v17 + (v14 * 5))][(v18 + (v15 * 5))];	// L35
                v4[(v17 + (v14 * 5))][(v18 + (v15 * 5))] = v21;	// L36
              }
              float v22 = v4[(v17 + (v14 * 5))][(v18 + (v15 * 5))];	// L38
              if ((v17 + (v14 * 5)) == 0) {	// L39
                float v23 = v7[(v16 + (v13 * 5))][(v18 + (v15 * 5))];	// L40
                v8[(v16 + (v13 * 5))][(v18 + (v15 * 5))] = v23;	// L41
              }
              float v24 = v8[(v16 + (v13 * 5))][(v18 + (v15 * 5))];	// L43
              float v25 = v20 * v22;	// L44
              float v26 = v24 + v25;	// L45
              v8[(v16 + (v13 * 5))][(v18 + (v15 * 5))] = v26;	// L46
              if (((v17 + (v14 * 5)) - 239) == 0) {	// L47
                float v27 = v8[(v16 + (v13 * 5))][(v18 + (v15 * 5))];	// L48
                v6[(v16 + (v13 * 5))][(v18 + (v15 * 5))] = v27;	// L49
              }
            }
          }
        }
      }
    }
  }
  for (int v28 = 0; v28 < 40; v28 += 1) {	// L57
    for (int v29 = 0; v29 < 44; v29 += 1) {	// L58
      #pragma HLS pipeline II=1
      for (int v30 = 0; v30 < 5; v30 += 1) {	// L59
        for (int v31 = 0; v31 < 5; v31 += 1) {	// L60
          float v32 = v6[(v30 + (v28 * 5))][(v31 + (v29 * 5))];	// L61
          float v33 = v2[(v30 + (v28 * 5))][(v31 + (v29 * 5))];	// L62
          float v34 = (double)0.100000;	// L63
          float v35 = v33 * v34;	// L64
          float v36 = v32 * (float)0.500000;	// L65
          float v37 = v36 + v35;	// L66
          v3[(v30 + (v28 * 5))][(v31 + (v29 * 5))] = v37;	// L67
        }
      }
    }
  }
  return ;	// L72
}

/// This is top function.
void main_graph(
  float v38[200][240],
  float v39[240][220],
  float v40[200][220],
  float v41[200][220]
) {	// L74
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v38 bundle=gmem1
  #pragma HLS array_partition variable=v38 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v38 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v38 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v39 bundle=gmem2
  #pragma HLS array_partition variable=v39 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v39 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v39 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v40 bundle=gmem3
  #pragma HLS array_partition variable=v40 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v40 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v40 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v41 bundle=gmem4
  #pragma HLS array_partition variable=v41 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v41 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v41 type=ram_t2p impl=bram

  #pragma HLS dataflow

  main_graph_node0(v38, v39, v40, v41);	// L76
  return ;	// L77
}

