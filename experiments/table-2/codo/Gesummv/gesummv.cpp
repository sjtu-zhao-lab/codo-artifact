
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
  float v2[250]
) {	// L5
  #pragma HLS dataflow

  for (int v3 = 0; v3 < 25; v3 += 1) {	// L8
    #pragma HLS pipeline II=1
    for (int v4 = 0; v4 < 10; v4 += 1) {	// L9
      float v5 = v0[(v4 + (v3 * 10))];	// L10
      float v6 = v1[(v4 + (v3 * 10))];	// L11
      float v7 = (double)1.200000;	// L12
      float v8 = v6 * v7;	// L13
      float v9 = v5 * (float)1.500000;	// L14
      float v10 = v9 + v8;	// L15
      v2[(v4 + (v3 * 10))] = v10;	// L16
    }
  }
  return ;	// L19
}

void main_graph_node1(
  float v11[250][250],
  float v12[250],
  float v13[250]
) {	// L21
  #pragma HLS dataflow

  float v14[250];	// L23
  #pragma HLS array_partition variable=v14 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v14 type=ram_2p impl=lutram

  float v15[250];	// L24
  #pragma HLS stream variable=v15 depth=10 type=fifo

  #pragma HLS array_partition variable=v15 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v15 type=ram_2p impl=lutram

  float v16[250];	// L25
  #pragma HLS array_partition variable=v16 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v16 type=ram_2p impl=lutram

  for (int v17 = 0; v17 < 25; v17 += 1) {	// L26
    #pragma HLS pipeline II=1
    for (int v18 = 0; v18 < 10; v18 += 1) {	// L27
      v15[(v18 + (v17 * 10))] = (float)0.000000;	// L28
    }
  }
  for (int v19 = 0; v19 < 25; v19 += 1) {	// L31
    for (int v20 = 0; v20 < 25; v20 += 1) {	// L32
      #pragma HLS pipeline II=1
      for (int v21 = 0; v21 < 10; v21 += 1) {	// L33
        for (int v22 = 0; v22 < 10; v22 += 1) {	// L34
          float v23 = v11[(v22 + (v20 * 10))][(v21 + (v19 * 10))];	// L35
          if ((v22 + (v20 * 10)) == 0) {	// L36
            float v24 = v12[(v21 + (v19 * 10))];	// L37
            v14[(v21 + (v19 * 10))] = v24;	// L38
          }
          float v25 = v14[(v21 + (v19 * 10))];	// L40
          if ((v21 + (v19 * 10)) == 0) {	// L41
            float v26 = v15[(v22 + (v20 * 10))];	// L42
            v16[(v22 + (v20 * 10))] = v26;	// L43
          }
          float v27 = v16[(v22 + (v20 * 10))];	// L45
          float v28 = v23 * v25;	// L46
          float v29 = v27 + v28;	// L47
          v16[(v22 + (v20 * 10))] = v29;	// L48
          if (((v21 + (v19 * 10)) - 249) == 0) {	// L49
            float v30 = v16[(v22 + (v20 * 10))];	// L50
            v13[(v22 + (v20 * 10))] = v30;	// L51
          }
        }
      }
    }
  }
  return ;	// L57
}

void main_graph_node2(
  float v31[250][250],
  float v32[250],
  float v33[250]
) {	// L59
  #pragma HLS dataflow

  float v34[250];	// L61
  #pragma HLS array_partition variable=v34 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v34 type=ram_2p impl=lutram

  float v35[250];	// L62
  #pragma HLS stream variable=v35 depth=10 type=fifo

  #pragma HLS array_partition variable=v35 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v35 type=ram_2p impl=lutram

  float v36[250];	// L63
  #pragma HLS array_partition variable=v36 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v36 type=ram_2p impl=lutram

  for (int v37 = 0; v37 < 25; v37 += 1) {	// L64
    #pragma HLS pipeline II=1
    for (int v38 = 0; v38 < 10; v38 += 1) {	// L65
      v35[(v38 + (v37 * 10))] = (float)0.000000;	// L66
    }
  }
  for (int v39 = 0; v39 < 25; v39 += 1) {	// L69
    for (int v40 = 0; v40 < 25; v40 += 1) {	// L70
      #pragma HLS pipeline II=1
      for (int v41 = 0; v41 < 10; v41 += 1) {	// L71
        for (int v42 = 0; v42 < 10; v42 += 1) {	// L72
          float v43 = v31[(v42 + (v40 * 10))][(v41 + (v39 * 10))];	// L73
          if ((v42 + (v40 * 10)) == 0) {	// L74
            float v44 = v32[(v41 + (v39 * 10))];	// L75
            v34[(v41 + (v39 * 10))] = v44;	// L76
          }
          float v45 = v34[(v41 + (v39 * 10))];	// L78
          if ((v41 + (v39 * 10)) == 0) {	// L79
            float v46 = v35[(v42 + (v40 * 10))];	// L80
            v36[(v42 + (v40 * 10))] = v46;	// L81
          }
          float v47 = v36[(v42 + (v40 * 10))];	// L83
          float v48 = v43 * v45;	// L84
          float v49 = v47 + v48;	// L85
          v36[(v42 + (v40 * 10))] = v49;	// L86
          if (((v41 + (v39 * 10)) - 249) == 0) {	// L87
            float v50 = v36[(v42 + (v40 * 10))];	// L88
            v33[(v42 + (v40 * 10))] = v50;	// L89
          }
        }
      }
    }
  }
  return ;	// L95
}

/// This is top function.
void main_graph(
  float v51[250][250],
  float v52[250][250],
  float v53[250],
  float v54[250]
) {	// L97
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v51 bundle=gmem1
  #pragma HLS array_partition variable=v51 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v51 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v51 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v52 bundle=gmem2
  #pragma HLS array_partition variable=v52 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v52 cyclic factor=10 dim=2
  #pragma HLS bind_storage variable=v52 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v53 bundle=gmem3
  #pragma HLS array_partition variable=v53 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v53 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v54 bundle=gmem4
  #pragma HLS array_partition variable=v54 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v54 type=ram_2p impl=lutram

  #pragma HLS dataflow

  float v55[250];	// L99
  #pragma HLS stream variable=v55 depth=10 type=fifo

  #pragma HLS array_partition variable=v55 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v55 type=ram_2p impl=lutram

  main_graph_node2(v51, v53, v55);	// L100
  float v56[250];	// L101
  #pragma HLS stream variable=v56 depth=10 type=fifo

  #pragma HLS array_partition variable=v56 cyclic factor=10 dim=1
  #pragma HLS bind_storage variable=v56 type=ram_2p impl=lutram

  main_graph_node1(v52, v53, v56);	// L102
  main_graph_node0(v55, v56, v54);	// L103
  return ;	// L104
}

