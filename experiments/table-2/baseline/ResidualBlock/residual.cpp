
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
  float v0[1][32][112][112],
  float v1[32][32][3][3],
  float v2[1][32][112][112],
  float v3[1][32][112][112]
) {	// L3
  // #pragma HLS dataflow

  float v4[1][32][114][114];	// L7
  // #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L8
    for (int v6 = 0; v6 < 32; v6 += 1) {	// L9
      for (int v7 = 0; v7 < 114; v7 += 1) {	// L10
        for (int v8 = 0; v8 < 114; v8 += 1) {	// L11
          v4[v5][v6][v7][v8] = (float)0.000000;	// L12
        }
      }
    }
  }
  for (int v9 = 0; v9 < 1; v9 += 1) {	// L17
    for (int v10 = 0; v10 < 32; v10 += 1) {	// L18
      for (int v11 = 0; v11 < 112; v11 += 1) {	// L19
        for (int v12 = 0; v12 < 112; v12 += 1) {	// L20
          float v13 = v2[v9][v10][v11][v12];	// L21
          v4[v9][v10][(v11 + 1)][(v12 + 1)] = v13;	// L22
        }
      }
    }
  }
  float v14[1][32][112][112];	// L27
  // #pragma HLS stream variable=v14 depth=10 type=fifo

  #pragma HLS bind_storage variable=v14 type=ram_t2p impl=bram

  for (int v15 = 0; v15 < 1; v15 += 1) {	// L28
    for (int v16 = 0; v16 < 32; v16 += 1) {	// L29
      for (int v17 = 0; v17 < 112; v17 += 1) {	// L30
        for (int v18 = 0; v18 < 112; v18 += 1) {	// L31
          v14[v15][v16][v17][v18] = (float)0.000000;	// L32
        }
      }
    }
  }
  for (int v19 = 0; v19 < 1; v19 += 1) {	// L37
    for (int v20 = 0; v20 < 32; v20 += 1) {	// L38
      for (int v21 = 0; v21 < 112; v21 += 1) {	// L39
        for (int v22 = 0; v22 < 112; v22 += 1) {	// L40
          for (int v23 = 0; v23 < 32; v23 += 1) {	// L41
            for (int v24 = 0; v24 < 3; v24 += 1) {	// L42
              for (int v25 = 0; v25 < 3; v25 += 1) {	// L43
                float v26 = v4[v19][v23][(v21 + v24)][(v22 + v25)];	// L44
                float v27 = v1[v20][v23][v24][v25];	// L45
                float v28 = v14[v19][v20][v21][v22];	// L46
                float v29 = v26 * v27;	// L47
                float v30 = v28 + v29;	// L48
                v14[v19][v20][v21][v22] = v30;	// L49
              }
            }
          }
        }
      }
    }
  }
  for (int v31 = 0; v31 < 1; v31 += 1) {	// L57
    for (int v32 = 0; v32 < 32; v32 += 1) {	// L58
      for (int v33 = 0; v33 < 112; v33 += 1) {	// L59
        for (int v34 = 0; v34 < 112; v34 += 1) {	// L60
          float v35 = v14[0][v32][v33][v34];	// L61
          float v36 = v0[0][v32][v33][v34];	// L62
          float v37 = (double)0.000010;	// L63
          float v38 = v37 + (float)1.000000;	// L64
          float v39 = 1.0 / sqrt(v38);	// L65
          float v40 = v35 * v39;	// L66
          float v41 = v40 + (float)0.000000;	// L67
          float v42 = v41 + v36;	// L68
          bool v43 = v42 > (float)0.000000;	// L69
          float v44 = v43 ? v42 : (float)0.000000;	// L70
          v3[v31][v32][v33][v34] = v44;	// L71
        }
      }
    }
  }
}

void main_graph_node1(
  float v45[32][32][3][3],
  float v46[1][32][112][112],
  float v47[1][32][112][112]
) {	// L78
  // #pragma HLS dataflow

  float v48[1][32][114][114];	// L82
  // #pragma HLS stream variable=v48 depth=10 type=fifo

  #pragma HLS bind_storage variable=v48 type=ram_t2p impl=bram

  for (int v49 = 0; v49 < 1; v49 += 1) {	// L83
    for (int v50 = 0; v50 < 32; v50 += 1) {	// L84
      for (int v51 = 0; v51 < 114; v51 += 1) {	// L85
        for (int v52 = 0; v52 < 114; v52 += 1) {	// L86
          v48[v49][v50][v51][v52] = (float)0.000000;	// L87
        }
      }
    }
  }
  for (int v53 = 0; v53 < 1; v53 += 1) {	// L92
    for (int v54 = 0; v54 < 32; v54 += 1) {	// L93
      for (int v55 = 0; v55 < 112; v55 += 1) {	// L94
        for (int v56 = 0; v56 < 112; v56 += 1) {	// L95
          float v57 = v46[v53][v54][v55][v56];	// L96
          v48[v53][v54][(v55 + 1)][(v56 + 1)] = v57;	// L97
        }
      }
    }
  }
  float v58[1][32][112][112];	// L102
  // #pragma HLS stream variable=v58 depth=10 type=fifo

  #pragma HLS bind_storage variable=v58 type=ram_t2p impl=bram

  for (int v59 = 0; v59 < 1; v59 += 1) {	// L103
    for (int v60 = 0; v60 < 32; v60 += 1) {	// L104
      for (int v61 = 0; v61 < 112; v61 += 1) {	// L105
        for (int v62 = 0; v62 < 112; v62 += 1) {	// L106
          v58[v59][v60][v61][v62] = (float)0.000000;	// L107
        }
      }
    }
  }
  for (int v63 = 0; v63 < 1; v63 += 1) {	// L112
    for (int v64 = 0; v64 < 32; v64 += 1) {	// L113
      for (int v65 = 0; v65 < 112; v65 += 1) {	// L114
        for (int v66 = 0; v66 < 112; v66 += 1) {	// L115
          for (int v67 = 0; v67 < 32; v67 += 1) {	// L116
            for (int v68 = 0; v68 < 3; v68 += 1) {	// L117
              for (int v69 = 0; v69 < 3; v69 += 1) {	// L118
                float v70 = v48[v63][v67][(v65 + v68)][(v66 + v69)];	// L119
                float v71 = v45[v64][v67][v68][v69];	// L120
                float v72 = v58[v63][v64][v65][v66];	// L121
                float v73 = v70 * v71;	// L122
                float v74 = v72 + v73;	// L123
                v58[v63][v64][v65][v66] = v74;	// L124
              }
            }
          }
        }
      }
    }
  }
  for (int v75 = 0; v75 < 1; v75 += 1) {	// L132
    for (int v76 = 0; v76 < 32; v76 += 1) {	// L133
      for (int v77 = 0; v77 < 112; v77 += 1) {	// L134
        for (int v78 = 0; v78 < 112; v78 += 1) {	// L135
          float v79 = v58[0][v76][v77][v78];	// L136
          float v80 = (double)0.000010;	// L137
          float v81 = v80 + (float)1.000000;	// L138
          float v82 = 1.0 / sqrt(v81);	// L139
          float v83 = v79 * v82;	// L140
          float v84 = v83 + (float)0.000000;	// L141
          bool v85 = v84 > (float)0.000000;	// L142
          float v86 = v85 ? v84 : (float)0.000000;	// L143
          v47[v75][v76][v77][v78] = v86;	// L144
        }
      }
    }
  }
}

/// This is top function.
void main_graph(
  float v87[1][32][112][112],
  float v88[32][32][3][3],
  float v89[32][32][3][3],
  float v90[1][32][112][112]
) {	// L151
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v87
  #pragma HLS bind_storage variable=v87 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v88
  #pragma HLS bind_storage variable=v88 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v89
  #pragma HLS bind_storage variable=v89 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v90
  #pragma HLS bind_storage variable=v90 type=ram_t2p impl=bram

  // // #pragma HLS dataflow

  float v91[1][32][112][112];	// L153
  // #pragma HLS stream variable=v91 depth=10 type=fifo

  #pragma HLS bind_storage variable=v91 type=ram_t2p impl=bram

  main_graph_node1(v88, v87, v91);	// L154
  main_graph_node0(v87, v89, v91, v90);	// L155
}

