
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
  float v0[1][512][128],
  float v1[128],
  float v2[1][512][128]
) {	// L6
  #pragma HLS dataflow

  float v3[128];	// L7
  #pragma HLS array_partition variable=v3 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=lutram

  for (int v4 = 0; v4 < 1; v4 += 1) {	// L8
    for (int v5 = 0; v5 < 128; v5 += 1) {	// L9
      for (int v6 = 0; v6 < 32; v6 += 1) {	// L10
        #pragma HLS pipeline II=1
        for (int v7 = 0; v7 < 1; v7 += 1) {	// L11
          for (int v8 = 0; v8 < 4; v8 += 1) {	// L12
            for (int v9 = 0; v9 < 4; v9 += 1) {	// L13
              float v10 = v0[0][(v8 + (v5 * 4))][(v9 + (v6 * 4))];	// L14
              if ((v8 + (v5 * 4)) == 0) {	// L15
                float v11 = v1[(v9 + (v6 * 4))];	// L16
                v3[(v9 + (v6 * 4))] = v11;	// L17
              }
              float v12 = v3[(v9 + (v6 * 4))];	// L19
              float v13 = v10 + v12;	// L20
              v2[(v4 + v7)][(v8 + (v5 * 4))][(v9 + (v6 * 4))] = v13;	// L21
            }
          }
        }
      }
    }
  }
  return ;	// L28
}

void main_graph_node1(
  float v14[1][512][256],
  float v15[256][128],
  float v16[1][512][128]
) {	// L30
  #pragma HLS dataflow

  float v17[1][512][256];	// L32
  #pragma HLS array_partition variable=v17 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v17 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v17 type=ram_2p impl=bram

  float v18[1][512][128];	// L33
  #pragma HLS stream variable=v18 depth=10 type=fifo

  #pragma HLS array_partition variable=v18 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v18 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v18 type=ram_2p impl=bram

  float v19[1][512][128];	// L34
  #pragma HLS array_partition variable=v19 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v19 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v19 type=ram_2p impl=bram

  for (int v20 = 0; v20 < 1; v20 += 1) {	// L35
    for (int v21 = 0; v21 < 128; v21 += 1) {	// L36
      for (int v22 = 0; v22 < 32; v22 += 1) {	// L37
        #pragma HLS pipeline II=1
        for (int v23 = 0; v23 < 1; v23 += 1) {	// L38
          for (int v24 = 0; v24 < 4; v24 += 1) {	// L39
            for (int v25 = 0; v25 < 4; v25 += 1) {	// L40
              v18[(v20 + v23)][(v24 + (v21 * 4))][(v25 + (v22 * 4))] = (float)0.000000;	// L41
            }
          }
        }
      }
    }
  }
  for (int v26 = 0; v26 < 1; v26 += 1) {	// L48
    for (int v27 = 0; v27 < 128; v27 += 1) {	// L49
      for (int v28 = 0; v28 < 64; v28 += 1) {	// L50
        for (int v29 = 0; v29 < 32; v29 += 1) {	// L51
          #pragma HLS pipeline II=1
          for (int v30 = 0; v30 < 1; v30 += 1) {	// L52
            for (int v31 = 0; v31 < 4; v31 += 1) {	// L53
              for (int v32 = 0; v32 < 4; v32 += 1) {	// L54
                for (int v33 = 0; v33 < 4; v33 += 1) {	// L55
                  if ((v33 + (v29 * 4)) == 0) {	// L56
                    float v34 = v14[(v26 + v30)][(v31 + (v27 * 4))][(v32 + (v28 * 4))];	// L57
                    v17[(v26 + v30)][(v31 + (v27 * 4))][(v32 + (v28 * 4))] = v34;	// L58
                  }
                  float v35 = v17[(v26 + v30)][(v31 + (v27 * 4))][(v32 + (v28 * 4))];	// L60
                  float v36 = v15[(v32 + (v28 * 4))][(v33 + (v29 * 4))];	// L61
                  if ((v32 + (v28 * 4)) == 0) {	// L62
                    float v37 = v18[(v26 + v30)][(v31 + (v27 * 4))][(v33 + (v29 * 4))];	// L63
                    v19[(v26 + v30)][(v31 + (v27 * 4))][(v33 + (v29 * 4))] = v37;	// L64
                  }
                  float v38 = v19[(v26 + v30)][(v31 + (v27 * 4))][(v33 + (v29 * 4))];	// L66
                  float v39 = v35 * v36;	// L67
                  float v40 = v38 + v39;	// L68
                  v19[(v26 + v30)][(v31 + (v27 * 4))][(v33 + (v29 * 4))] = v40;	// L69
                  if (((v32 + (v28 * 4)) - 255) == 0) {	// L70
                    float v41 = v19[(v26 + v30)][(v31 + (v27 * 4))][(v33 + (v29 * 4))];	// L71
                    v16[(v26 + v30)][(v31 + (v27 * 4))][(v33 + (v29 * 4))] = v41;	// L72
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L82
}

void main_graph_node2(
  float v42[1][512][256],
  float v43[256],
  float v44[1][512][256]
) {	// L84
  #pragma HLS dataflow

  float v45[256];	// L86
  #pragma HLS array_partition variable=v45 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v45 type=ram_2p impl=lutram

  for (int v46 = 0; v46 < 1; v46 += 1) {	// L87
    for (int v47 = 0; v47 < 128; v47 += 1) {	// L88
      for (int v48 = 0; v48 < 64; v48 += 1) {	// L89
        #pragma HLS pipeline II=1
        for (int v49 = 0; v49 < 1; v49 += 1) {	// L90
          for (int v50 = 0; v50 < 4; v50 += 1) {	// L91
            for (int v51 = 0; v51 < 4; v51 += 1) {	// L92
              float v52 = v42[0][(v50 + (v47 * 4))][(v51 + (v48 * 4))];	// L93
              if ((v50 + (v47 * 4)) == 0) {	// L94
                float v53 = v43[(v51 + (v48 * 4))];	// L95
                v45[(v51 + (v48 * 4))] = v53;	// L96
              }
              float v54 = v45[(v51 + (v48 * 4))];	// L98
              float v55 = v52 + v54;	// L99
              bool v56 = v55 > (float)0.000000;	// L100
              float v57 = v56 ? v55 : (float)0.000000;	// L101
              v44[(v46 + v49)][(v50 + (v47 * 4))][(v51 + (v48 * 4))] = v57;	// L102
            }
          }
        }
      }
    }
  }
  return ;	// L109
}

void main_graph_node3(
  float v58[1][512][128],
  float v59[128][256],
  float v60[1][512][256]
) {	// L111
  #pragma HLS dataflow

  float v61[1][512][256];	// L113
  #pragma HLS stream variable=v61 depth=10 type=fifo

  #pragma HLS array_partition variable=v61 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v61 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v61 type=ram_2p impl=bram

  float v62[1][512][256];	// L114
  #pragma HLS array_partition variable=v62 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v62 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v62 type=ram_2p impl=bram

  float v63[1][512][128];	// L115
  #pragma HLS stream variable=v63 depth=10 type=fifo

  #pragma HLS array_partition variable=v63 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v63 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v63 type=ram_t2p impl=bram

  float v64[1][512][128];	// L116
  #pragma HLS array_partition variable=v64 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v64 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v64 type=ram_2p impl=bram

  for (int v65 = 0; v65 < 1; v65 += 1) {	// L117
    for (int v66 = 0; v66 < 128; v66 += 1) {	// L118
      for (int v67 = 0; v67 < 32; v67 += 1) {	// L119
        #pragma HLS pipeline II=1
        for (int v68 = 0; v68 < 1; v68 += 1) {	// L120
          for (int v69 = 0; v69 < 4; v69 += 1) {	// L121
            for (int v70 = 0; v70 < 4; v70 += 1) {	// L122
              float v71 = v58[0][(v69 + (v66 * 4))][(v70 + (v67 * 4))];	// L123
              v63[(v65 + v68)][(v69 + (v66 * 4))][(v70 + (v67 * 4))] = v71;	// L124
            }
          }
        }
      }
    }
  }
  for (int v72 = 0; v72 < 1; v72 += 1) {	// L131
    for (int v73 = 0; v73 < 128; v73 += 1) {	// L132
      for (int v74 = 0; v74 < 64; v74 += 1) {	// L133
        #pragma HLS pipeline II=1
        for (int v75 = 0; v75 < 1; v75 += 1) {	// L134
          for (int v76 = 0; v76 < 4; v76 += 1) {	// L135
            for (int v77 = 0; v77 < 4; v77 += 1) {	// L136
              v61[(v72 + v75)][(v76 + (v73 * 4))][(v77 + (v74 * 4))] = (float)0.000000;	// L137
            }
          }
        }
      }
    }
  }
  for (int v78 = 0; v78 < 1; v78 += 1) {	// L144
    for (int v79 = 0; v79 < 128; v79 += 1) {	// L145
      for (int v80 = 0; v80 < 32; v80 += 1) {	// L146
        for (int v81 = 0; v81 < 64; v81 += 1) {	// L147
          #pragma HLS pipeline II=1
          for (int v82 = 0; v82 < 1; v82 += 1) {	// L148
            for (int v83 = 0; v83 < 4; v83 += 1) {	// L149
              for (int v84 = 0; v84 < 4; v84 += 1) {	// L150
                for (int v85 = 0; v85 < 4; v85 += 1) {	// L151
                  if ((v85 + (v81 * 4)) == 0) {	// L152
                    float v86 = v63[(v78 + v82)][(v83 + (v79 * 4))][(v84 + (v80 * 4))];	// L153
                    v64[(v78 + v82)][(v83 + (v79 * 4))][(v84 + (v80 * 4))] = v86;	// L154
                  }
                  float v87 = v64[(v78 + v82)][(v83 + (v79 * 4))][(v84 + (v80 * 4))];	// L156
                  float v88 = v59[(v84 + (v80 * 4))][(v85 + (v81 * 4))];	// L157
                  if ((v84 + (v80 * 4)) == 0) {	// L158
                    float v89 = v61[(v78 + v82)][(v83 + (v79 * 4))][(v85 + (v81 * 4))];	// L159
                    v62[(v78 + v82)][(v83 + (v79 * 4))][(v85 + (v81 * 4))] = v89;	// L160
                  }
                  float v90 = v62[(v78 + v82)][(v83 + (v79 * 4))][(v85 + (v81 * 4))];	// L162
                  float v91 = v87 * v88;	// L163
                  float v92 = v90 + v91;	// L164
                  v62[(v78 + v82)][(v83 + (v79 * 4))][(v85 + (v81 * 4))] = v92;	// L165
                  if (((v84 + (v80 * 4)) - 127) == 0) {	// L166
                    float v93 = v62[(v78 + v82)][(v83 + (v79 * 4))][(v85 + (v81 * 4))];	// L167
                    v60[(v78 + v82)][(v83 + (v79 * 4))][(v85 + (v81 * 4))] = v93;	// L168
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ;	// L178
}

/// This is top function.
void main_graph(
  float v94[1][512][128],
  float v95[128][256],
  float v96[256],
  float v97[128],
  float v98[256][128],
  float v99[1][512][128]
) {	// L180
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v94 bundle=gmem1
  #pragma HLS array_partition variable=v94 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v94 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v94 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v95 bundle=gmem2
  #pragma HLS array_partition variable=v95 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v95 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v95 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v96 bundle=gmem3
  #pragma HLS array_partition variable=v96 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v96 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v97 bundle=gmem4
  #pragma HLS array_partition variable=v97 cyclic factor=4 dim=1
  #pragma HLS bind_storage variable=v97 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v98 bundle=gmem5
  #pragma HLS array_partition variable=v98 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v98 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v98 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v99 bundle=gmem6
  #pragma HLS array_partition variable=v99 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v99 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v99 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v100[1][512][256];	// L182
  #pragma HLS stream variable=v100 depth=10 type=fifo

  #pragma HLS array_partition variable=v100 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v100 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v100 type=ram_t2p impl=bram

  main_graph_node3(v94, v95, v100);	// L183
  float v101[1][512][256];	// L184
  #pragma HLS stream variable=v101 depth=10 type=fifo

  #pragma HLS array_partition variable=v101 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v101 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v101 type=ram_t2p impl=bram

  main_graph_node2(v100, v96, v101);	// L185
  float v102[1][512][128];	// L186
  #pragma HLS stream variable=v102 depth=10 type=fifo

  #pragma HLS array_partition variable=v102 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v102 cyclic factor=4 dim=3
  #pragma HLS bind_storage variable=v102 type=ram_t2p impl=bram

  main_graph_node1(v101, v98, v102);	// L187
  main_graph_node0(v102, v97, v99);	// L188
  return ;	// L189
}

