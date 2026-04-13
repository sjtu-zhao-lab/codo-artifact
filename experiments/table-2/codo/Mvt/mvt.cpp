
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
  float v0[400][400],
  float v1[400],
  float v2[400]
) {	// L5
  #pragma HLS dataflow

  float v3[400];	// L7
  #pragma HLS array_partition variable=v3 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=lutram

  float v4[400];	// L8
  #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS array_partition variable=v4 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v4 type=ram_2p impl=lutram

  float v5[400];	// L9
  #pragma HLS array_partition variable=v5 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v5 type=ram_2p impl=lutram

  float v6[400][400];	// L10
  #pragma HLS stream variable=v6 depth=10 type=fifo

  #pragma HLS array_partition variable=v6 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v6 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v6 type=ram_t2p impl=bram

  for (int v7 = 0; v7 < 40; v7 += 1) {	// L11
    for (int v8 = 0; v8 < 40; v8 += 1) {	// L12
      #pragma HLS pipeline II=1
      for (int v9 = 0; v9 < 10; v9 += 1) {	// L13
        for (int v10 = 0; v10 < 10; v10 += 1) {	// L14
          float v11 = v0[(v9 + (v7 * 10))][(v10 + (v8 * 10))];	// L15
          v6[(v10 + (v8 * 10))][(v9 + (v7 * 10))] = v11;	// L16
        }
      }
    }
  }
  for (int v12 = 0; v12 < 40; v12 += 1) {	// L21
    #pragma HLS pipeline II=1
    for (int v13 = 0; v13 < 10; v13 += 1) {	// L22
      v4[(v13 + (v12 * 10))] = (float)0.000000;	// L23
    }
  }
  for (int v14 = 0; v14 < 40; v14 += 1) {	// L26
    for (int v15 = 0; v15 < 40; v15 += 1) {	// L27
      #pragma HLS pipeline II=1
      for (int v16 = 0; v16 < 10; v16 += 1) {	// L28
        for (int v17 = 0; v17 < 10; v17 += 1) {	// L29
          float v18 = v6[(v17 + (v15 * 10))][(v16 + (v14 * 10))];	// L30
          if ((v17 + (v15 * 10)) == 0) {	// L31
            float v19 = v1[(v16 + (v14 * 10))];	// L32
            v3[(v16 + (v14 * 10))] = v19;	// L33
          }
          float v20 = v3[(v16 + (v14 * 10))];	// L35
          if ((v16 + (v14 * 10)) == 0) {	// L36
            float v21 = v4[(v17 + (v15 * 10))];	// L37
            v5[(v17 + (v15 * 10))] = v21;	// L38
          }
          float v22 = v5[(v17 + (v15 * 10))];	// L40
          float v23 = v18 * v20;	// L41
          float v24 = v22 + v23;	// L42
          v5[(v17 + (v15 * 10))] = v24;	// L43
          if (((v16 + (v14 * 10)) - 399) == 0) {	// L44
            float v25 = v5[(v17 + (v15 * 10))];	// L45
            v2[(v17 + (v15 * 10))] = v25;	// L46
          }
        }
      }
    }
  }
  return ;	// L52
}

void main_graph_node1(
  float v26[400][400],
  float v27[400],
  float v28[400]
) {	// L54
  #pragma HLS dataflow

  float v29[400];	// L56
  #pragma HLS array_partition variable=v29 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v29 type=ram_2p impl=lutram

  float v30[400];	// L57
  #pragma HLS stream variable=v30 depth=10 type=fifo

  #pragma HLS array_partition variable=v30 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v30 type=ram_2p impl=lutram

  float v31[400];	// L58
  #pragma HLS array_partition variable=v31 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v31 type=ram_2p impl=lutram

  for (int v32 = 0; v32 < 40; v32 += 1) {	// L59
    #pragma HLS pipeline II=1
    for (int v33 = 0; v33 < 10; v33 += 1) {	// L60
      v30[(v33 + (v32 * 10))] = (float)0.000000;	// L61
    }
  }
  for (int v34 = 0; v34 < 40; v34 += 1) {	// L64
    for (int v35 = 0; v35 < 40; v35 += 1) {	// L65
      #pragma HLS pipeline II=1
      for (int v36 = 0; v36 < 10; v36 += 1) {	// L66
        for (int v37 = 0; v37 < 10; v37 += 1) {	// L67
          float v38 = v26[(v37 + (v35 * 10))][(v36 + (v34 * 10))];	// L68
          if ((v37 + (v35 * 10)) == 0) {	// L69
            float v39 = v27[(v36 + (v34 * 10))];	// L70
            v29[(v36 + (v34 * 10))] = v39;	// L71
          }
          float v40 = v29[(v36 + (v34 * 10))];	// L73
          if ((v36 + (v34 * 10)) == 0) {	// L74
            float v41 = v30[(v37 + (v35 * 10))];	// L75
            v31[(v37 + (v35 * 10))] = v41;	// L76
          }
          float v42 = v31[(v37 + (v35 * 10))];	// L78
          float v43 = v38 * v40;	// L79
          float v44 = v42 + v43;	// L80
          v31[(v37 + (v35 * 10))] = v44;	// L81
          if (((v36 + (v34 * 10)) - 399) == 0) {	// L82
            float v45 = v31[(v37 + (v35 * 10))];	// L83
            v28[(v37 + (v35 * 10))] = v45;	// L84
          }
        }
      }
    }
  }
  return ;	// L90
}

/// This is top function.
void main_graph(
  float v46[400][400],
  float v47[400][400],
  float v48[400],
  float v49[400],
  float v50[400],
  float v51[400]
) {	// L92
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v46 bundle=gmem1
  #pragma HLS array_partition variable=v46 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v46 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v46 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v47 bundle=gmem2
  #pragma HLS array_partition variable=v47 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v47 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v47 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v48 bundle=gmem3
  #pragma HLS array_partition variable=v48 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v48 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v49 bundle=gmem4
  #pragma HLS array_partition variable=v49 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v49 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v50 bundle=gmem5
  #pragma HLS array_partition variable=v50 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v50 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v51 bundle=gmem6
  #pragma HLS array_partition variable=v51 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v51 type=ram_2p impl=lutram

  #pragma HLS dataflow

  main_graph_node1(v46, v48, v50);	// L95
  main_graph_node0(v47, v49, v51);	// L96
  return ;}

