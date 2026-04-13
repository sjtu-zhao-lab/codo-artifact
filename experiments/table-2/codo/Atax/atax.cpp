
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
  float v0[390][410],
  float v1[390],
  float v2[410]
) {	// L6
  #pragma HLS dataflow

  float v3[390];	// L8
  #pragma HLS array_partition variable=v3 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=lutram

  float v4[410];	// L9
  #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS array_partition variable=v4 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v4 type=ram_2p impl=lutram

  float v5[410];	// L10
  #pragma HLS array_partition variable=v5 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v5 type=ram_2p impl=lutram

  float v6[410][390];	// L11
  #pragma HLS stream variable=v6 depth=10 type=fifo

  #pragma HLS array_partition variable=v6 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v6 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v6 type=ram_t2p impl=bram

  for (int v7 = 0; v7 < 39; v7 += 1) {	// L12
    for (int v8 = 0; v8 < 41; v8 += 1) {	// L13
      #pragma HLS pipeline II=1
      for (int v9 = 0; v9 < 10; v9 += 1) {	// L14
        for (int v10 = 0; v10 < 10; v10 += 1) {	// L15
          float v11 = v0[(v9 + (v7 * 10))][(v10 + (v8 * 10))];	// L16
          v6[(v10 + (v8 * 10))][(v9 + (v7 * 10))] = v11;	// L17
        }
      }
    }
  }
  for (int v12 = 0; v12 < 41; v12 += 1) {	// L22
    #pragma HLS pipeline II=1
    for (int v13 = 0; v13 < 10; v13 += 1) {	// L23
      v4[(v13 + (v12 * 10))] = (float)0.000000;	// L24
    }
  }
  for (int v14 = 0; v14 < 39; v14 += 1) {	// L27
    for (int v15 = 0; v15 < 41; v15 += 1) {	// L28
      #pragma HLS pipeline II=1
      for (int v16 = 0; v16 < 10; v16 += 1) {	// L29
        for (int v17 = 0; v17 < 10; v17 += 1) {	// L30
          float v18 = v6[(v17 + (v15 * 10))][(v16 + (v14 * 10))];	// L31
          if ((v17 + (v15 * 10)) == 0) {	// L32
            float v19 = v1[(v16 + (v14 * 10))];	// L33
            v3[(v16 + (v14 * 10))] = v19;	// L34
          }
          float v20 = v3[(v16 + (v14 * 10))];	// L36
          if ((v16 + (v14 * 10)) == 0) {	// L37
            float v21 = v4[(v17 + (v15 * 10))];	// L38
            v5[(v17 + (v15 * 10))] = v21;	// L39
          }
          float v22 = v5[(v17 + (v15 * 10))];	// L41
          float v23 = v18 * v20;	// L42
          float v24 = v22 + v23;	// L43
          v5[(v17 + (v15 * 10))] = v24;	// L44
          if (((v16 + (v14 * 10)) - 389) == 0) {	// L45
            float v25 = v5[(v17 + (v15 * 10))];	// L46
            v2[(v17 + (v15 * 10))] = v25;	// L47
          }
        }
      }
    }
  }
  return ;	// L53
}

void main_graph_node1(
  float v26[390][410],
  float v27[410],
  float v28[390]
) {	// L55
  #pragma HLS dataflow

  float v29[410];	// L57
  #pragma HLS array_partition variable=v29 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v29 type=ram_2p impl=lutram

  float v30[390];	// L58
  #pragma HLS stream variable=v30 depth=10 type=fifo

  #pragma HLS array_partition variable=v30 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v30 type=ram_2p impl=lutram

  float v31[390];	// L59
  #pragma HLS array_partition variable=v31 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v31 type=ram_2p impl=lutram

  for (int v32 = 0; v32 < 39; v32 += 1) {	// L60
    #pragma HLS pipeline II=1
    for (int v33 = 0; v33 < 10; v33 += 1) {	// L61
      v30[(v33 + (v32 * 10))] = (float)0.000000;	// L62
    }
  }
  for (int v34 = 0; v34 < 41; v34 += 1) {	// L65
    for (int v35 = 0; v35 < 39; v35 += 1) {	// L66
      #pragma HLS pipeline II=1
      for (int v36 = 0; v36 < 10; v36 += 1) {	// L67
        for (int v37 = 0; v37 < 10; v37 += 1) {	// L68
          float v38 = v26[(v37 + (v35 * 10))][(v36 + (v34 * 10))];	// L69
          if ((v37 + (v35 * 10)) == 0) {	// L70
            float v39 = v27[(v36 + (v34 * 10))];	// L71
            v29[(v36 + (v34 * 10))] = v39;	// L72
          }
          float v40 = v29[(v36 + (v34 * 10))];	// L74
          if ((v36 + (v34 * 10)) == 0) {	// L75
            float v41 = v30[(v37 + (v35 * 10))];	// L76
            v31[(v37 + (v35 * 10))] = v41;	// L77
          }
          float v42 = v31[(v37 + (v35 * 10))];	// L79
          float v43 = v38 * v40;	// L80
          float v44 = v42 + v43;	// L81
          v31[(v37 + (v35 * 10))] = v44;	// L82
          if (((v36 + (v34 * 10)) - 409) == 0) {	// L83
            float v45 = v31[(v37 + (v35 * 10))];	// L84
            v28[(v37 + (v35 * 10))] = v45;	// L85
          }
        }
      }
    }
  }
  return ;	// L91
}

/// This is top function.
void main_graph(
  float v46[390][410],
  float v47[410],
  float v48[410]
) {	// L93
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v46 bundle=gmem1
  #pragma HLS array_partition variable=v46 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v46 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v46 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v47 bundle=gmem2
  #pragma HLS array_partition variable=v47 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v47 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v48 bundle=gmem3
  #pragma HLS array_partition variable=v48 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v48 type=ram_2p impl=lutram

  #pragma HLS dataflow

  float v49[390];	// L95
  #pragma HLS stream variable=v49 depth=10 type=fifo

  #pragma HLS array_partition variable=v49 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v49 type=ram_2p impl=lutram

  main_graph_node1(v46, v47, v49);	// L96
  main_graph_node0(v46, v49, v48);	// L97
  return ;	// L98
}

