
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
  float v0[64][64][1][1],
  float v1[1][64][112][112],
  float v2[1][64][112][112]
) {	// L6
  #pragma HLS dataflow

  float v3[1][64][112][112];	// L10
  #pragma HLS stream variable=v3 depth=10 type=fifo

  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  float v4[1][64][1][112];	// L11
  #pragma HLS array_partition variable=v4 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v4 type=ram_2p impl=bram

  float v5[1][64][1][1];	// L12
  #pragma HLS array_partition variable=v5 cyclic factor=64 dim=2
  #pragma HLS bind_storage variable=v5 type=ram_2p impl=lutram

  for (int v6 = 0; v6 < 1; v6 += 1) {	// L13
    for (int v7 = 0; v7 < 112; v7 += 1) {	// L14
      for (int v8 = 0; v8 < 112; v8 += 1) {	// L15
        for (int v9 = 0; v9 < 16; v9 += 1) {	// L16
          #pragma HLS pipeline II=1
          for (int v10 = 0; v10 < 4; v10 += 1) {	// L17
            float v11 = v1[v6][(v10 + (v9 * 4))][v7][v8];	// L18
            v4[v6][(v10 + (v9 * 4))][0][v8] = v11;	// L19
          }
        }
        if (v7 >= 0) {	// L22
          for (int v12 = 0; v12 < 16; v12 += 1) {	// L23
            #pragma HLS pipeline II=1
            for (int v13 = 0; v13 < 4; v13 += 1) {	// L24
              for (int v14 = 0; v14 < 1; v14 += 1) {	// L25
                float v15 = v4[v6][(v13 + (v12 * 4))][v14][v8];	// L26
                v5[v6][(v13 + (v12 * 4))][v14][0] = v15;	// L27
              }
            }
          }
          if (v8 >= 0) {	// L31
            float v16[64];	// L32
            #pragma HLS bind_storage variable=v16 type=ram_2p impl=bram

            for (int v17 = 0; v17 < 64; v17 += 1) {	// L33
              v16[v17] = (float)0.000000;	// L34
              for (int v18 = 0; v18 < 1; v18 += 1) {	// L35
                #pragma HLS pipeline II=1
                for (int v19 = 0; v19 < 64; v19 += 1) {	// L36
                  for (int v20 = 0; v20 < 1; v20 += 1) {	// L37
                    for (int v21 = 0; v21 < 1; v21 += 1) {	// L38
                      float v22 = v5[v6][(v19 + (v18 * 64))][v20][v21];	// L39
                      float v23 = v0[v17][(v19 + (v18 * 64))][v20][v21];	// L40
                      float v24 = v22 * v23;	// L41
                      float v25 = v16[v17];	// L42
                      float v26 = v25 + v24;	// L43
                      v16[v17] = v26;	// L44
                    }
                  }
                }
              }
              float v27 = v16[v17];	// L49
              v3[v6][v17][v7][v8] = v27;	// L50
            }
          }
        }
      }
    }
  }
  for (int v28 = 0; v28 < 1; v28 += 1) {	// L57
    for (int v29 = 0; v29 < 112; v29 += 1) {	// L58
      for (int v30 = 0; v30 < 112; v30 += 1) {	// L59
        for (int v31 = 0; v31 < 64; v31 += 1) {	// L60
          float v32 = v3[0][v31][v29][v30];	// L61
          float v33 = (double)0.000010;	// L62
          float v34 = v33 + (float)1.000000;	// L63
          float v35 = 1.0 / sqrt(v34);	// L64
          float v36 = v32 * v35;	// L65
          float v37 = v36 + (float)0.000000;	// L66
          bool v38 = v37 > (float)0.000000;	// L67
          float v39 = v38 ? v37 : (float)0.000000;	// L68
          v2[v28][v31][v29][v30] = v39;	// L69
        }
      }
    }
  }
  return ;	// L74
}

void main_graph_node1(
  float v40[1][64][112][112],
  float v41[64][3][3],
  float v42[1][64][112][112]
) {	// L76
  #pragma HLS dataflow

  float v43[1][64][114][114];	// L78
  #pragma HLS stream variable=v43 depth=10 type=fifo

  #pragma HLS bind_storage variable=v43 type=ram_t2p impl=bram

  for (int v44 = 0; v44 < 1; v44 += 1) {	// L79
    for (int v45 = 0; v45 < 114; v45 += 1) {	// L80
      for (int v46 = 0; v46 < 114; v46 += 1) {	// L81
        for (int v47 = 0; v47 < 64; v47 += 1) {	// L82
          float v48;	// L83
          v48 = (float)0.000000;	// L84
          if (((-v45) + 111) >= 0 && ((-v46) + 111) >= 0) {	// L85
            float v49 = v40[v44][v47][v45][v46];	// L86
            v48 = v49;	// L87
          }
          float v50 = v48;	// L89
          v43[v44][v47][v45][v46] = v50;	// L90
        }
      }
    }
  }
  float v51[1][64][3][114];	// L95
  #pragma HLS array_partition variable=v51 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v51 type=ram_2p impl=bram

  float v52[1][64][3][3];	// L96
  #pragma HLS array_partition variable=v52 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v52 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v52 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v52 type=ram_2p impl=lutram

  for (int v53 = 0; v53 < 1; v53 += 1) {	// L97
    for (int v54 = 0; v54 < 114; v54 += 1) {	// L98
      for (int v55 = 0; v55 < 114; v55 += 1) {	// L99
        for (int v56 = 0; v56 < 64; v56 += 1) {	// L100
          float v57 = v51[v53][v56][1][v55];	// L101
          v51[v53][v56][0][v55] = v57;	// L102
          float v58 = v51[v53][v56][2][v55];	// L103
          v51[v53][v56][1][v55] = v58;	// L104
          float v59 = v43[v53][v56][v54][v55];	// L105
          v51[v53][v56][2][v55] = v59;	// L106
        }
        if ((v54 - 2) >= 0) {	// L108
          for (int v60 = 0; v60 < 64; v60 += 1) {	// L109
            for (int v61 = 0; v61 < 3; v61 += 1) {	// L110
              float v62 = v52[v53][v60][v61][1];	// L111
              v52[v53][v60][v61][0] = v62;	// L112
              float v63 = v52[v53][v60][v61][2];	// L113
              v52[v53][v60][v61][1] = v63;	// L114
              float v64 = v51[v53][v60][v61][v55];	// L115
              v52[v53][v60][v61][2] = v64;	// L116
            }
          }
          if ((v55 - 2) >= 0) {	// L119
            float v65[64];	// L120
            #pragma HLS array_partition variable=v65 cyclic factor=4 dim=1
            #pragma HLS bind_storage variable=v65 type=ram_2p impl=lutram

            for (int v66 = 0; v66 < 16; v66 += 1) {	// L121
              #pragma HLS pipeline II=1
              for (int v67 = 0; v67 < 4; v67 += 1) {	// L122
                v65[(v67 + (v66 * 4))] = (float)0.000000;	// L123
                for (int v68 = 0; v68 < 3; v68 += 1) {	// L124
                  for (int v69 = 0; v69 < 3; v69 += 1) {	// L125
                    float v70 = v52[v53][(v67 + (v66 * 4))][v68][v69];	// L126
                    float v71 = v41[(v67 + (v66 * 4))][v68][v69];	// L127
                    float v72 = v70 * v71;	// L128
                    float v73 = v65[(v67 + (v66 * 4))];	// L129
                    float v74 = v73 + v72;	// L130
                    v65[(v67 + (v66 * 4))] = v74;	// L131
                  }
                }
                float v75 = v65[(v67 + (v66 * 4))];	// L134
                v42[v53][(v67 + (v66 * 4))][(v54 - 2)][(v55 - 2)] = v75;	// L135
              }
            }
          }
        }
      }
    }
  }
  return ;	// L143
}

/// This is top function.
void main_graph(
  float v76[1][64][112][112],
  float v77[64][64][1][1],
  float v78[64][3][3],
  float v79[1][64][112][112]
) {	// L145
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v76 bundle=gmem1
  #pragma HLS bind_storage variable=v76 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v77 bundle=gmem2
  #pragma HLS array_partition variable=v77 cyclic factor=64 dim=2
  #pragma HLS bind_storage variable=v77 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v78 bundle=gmem3
  #pragma HLS array_partition variable=v78 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v78 cyclic factor=3 dim=2
  #pragma HLS array_partition variable=v78 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v78 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v79 bundle=gmem4
  #pragma HLS bind_storage variable=v79 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v80[1][64][112][112];	// L147
  #pragma HLS stream variable=v80 depth=10 type=fifo

  #pragma HLS array_partition variable=v80 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v80 type=ram_t2p impl=bram

  main_graph_node1(v76, v78, v80);	// L148
  main_graph_node0(v77, v80, v79);	// L149
  return ;	// L150
}

