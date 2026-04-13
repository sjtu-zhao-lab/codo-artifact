
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
) {	// L5
  #pragma HLS dataflow

  float v4[1][32][114][114];	// L9
  #pragma HLS stream variable=v4 depth=10 type=fifo

  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L10
    for (int v6 = 0; v6 < 114; v6 += 1) {	// L11
      for (int v7 = 0; v7 < 114; v7 += 1) {	// L12
        for (int v8 = 0; v8 < 32; v8 += 1) {	// L13
          float v9;	// L14
          v9 = (float)0.000000;	// L15
          if (((-v6) + 111) >= 0 && ((-v7) + 111) >= 0) {	// L16
            float v10 = v0[v5][v8][v6][v7];	// L17
            v9 = v10;	// L18
          }
          float v11 = v9;	// L20
          v4[v5][v8][v6][v7] = v11;	// L21
        }
      }
    }
  }
  float v12[1][32][112][112];	// L26
  #pragma HLS stream variable=v12 depth=10 type=fifo

  #pragma HLS bind_storage variable=v12 type=ram_t2p impl=bram

  float v13[1][32][3][114];	// L27
  #pragma HLS array_partition variable=v13 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v13 type=ram_2p impl=bram

  float v14[1][32][3][3];	// L28
  #pragma HLS array_partition variable=v14 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v14 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v14 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v14 type=ram_2p impl=lutram

  for (int v15 = 0; v15 < 1; v15 += 1) {	// L29
    for (int v16 = 0; v16 < 114; v16 += 1) {	// L30
      for (int v17 = 0; v17 < 114; v17 += 1) {	// L31
        for (int v18 = 0; v18 < 32; v18 += 1) {	// L32
          float v19 = v13[v15][v18][1][v17];	// L33
          v13[v15][v18][0][v17] = v19;	// L34
          float v20 = v13[v15][v18][2][v17];	// L35
          v13[v15][v18][1][v17] = v20;	// L36
          float v21 = v4[v15][v18][v16][v17];	// L37
          v13[v15][v18][2][v17] = v21;	// L38
        }
        if ((v16 - 2) >= 0) {	// L40
          for (int v22 = 0; v22 < 32; v22 += 1) {	// L41
            for (int v23 = 0; v23 < 3; v23 += 1) {	// L42
              float v24 = v14[v15][v22][v23][1];	// L43
              v14[v15][v22][v23][0] = v24;	// L44
              float v25 = v14[v15][v22][v23][2];	// L45
              v14[v15][v22][v23][1] = v25;	// L46
              float v26 = v13[v15][v22][v23][v17];	// L47
              v14[v15][v22][v23][2] = v26;	// L48
            }
          }
          if ((v17 - 2) >= 0) {	// L51
            float v27[32];	// L52
            #pragma HLS bind_storage variable=v27 type=ram_2p impl=bram

            for (int v28 = 0; v28 < 32; v28 += 1) {	// L53
              v27[v28] = (float)0.000000;	// L54
              for (int v29 = 0; v29 < 2; v29 += 1) {	// L55
                #pragma HLS pipeline II=1
                for (int v30 = 0; v30 < 16; v30 += 1) {	// L56
                  for (int v31 = 0; v31 < 3; v31 += 1) {	// L57
                    for (int v32 = 0; v32 < 3; v32 += 1) {	// L58
                      float v33 = v14[v15][(v30 + (v29 * 16))][v31][v32];	// L59
                      float v34 = v1[v28][(v30 + (v29 * 16))][v31][v32];	// L60
                      float v35 = v33 * v34;	// L61
                      float v36 = v27[v28];	// L62
                      float v37 = v36 + v35;	// L63
                      v27[v28] = v37;	// L64
                    }
                  }
                }
              }
              float v38 = v27[v28];	// L69
              v12[v15][v28][(v16 - 2)][(v17 - 2)] = v38;	// L70
            }
          }
        }
      }
    }
  }
  for (int v39 = 0; v39 < 1; v39 += 1) {	// L77
    for (int v40 = 0; v40 < 112; v40 += 1) {	// L78
      for (int v41 = 0; v41 < 112; v41 += 1) {	// L79
        for (int v42 = 0; v42 < 32; v42 += 1) {	// L80
          float v43 = v12[0][v42][v40][v41];	// L81
          float v44 = v2[0][v42][v40][v41];	// L82
          float v45 = (double)0.000010;	// L83
          float v46 = v45 + (float)1.000000;	// L84
          float v47 = 1.0 / sqrt(v46);	// L85
          float v48 = v43 * v47;	// L86
          float v49 = v48 + (float)0.000000;	// L87
          float v50 = v49 + v44;	// L88
          bool v51 = v50 > (float)0.000000;	// L89
          float v52 = v51 ? v50 : (float)0.000000;	// L90
          v3[v39][v42][v40][v41] = v52;	// L91
        }
      }
    }
  }
  return ;	// L96
}

void main_graph_node1(
  float v53[32][32][3][3],
  float v54[1][32][112][112],
  float v55[1][32][112][112]
) {	// L98
  #pragma HLS dataflow

  float v56[1][32][114][114];	// L102
  #pragma HLS stream variable=v56 depth=10 type=fifo

  #pragma HLS bind_storage variable=v56 type=ram_t2p impl=bram

  for (int v57 = 0; v57 < 1; v57 += 1) {	// L103
    for (int v58 = 0; v58 < 114; v58 += 1) {	// L104
      for (int v59 = 0; v59 < 114; v59 += 1) {	// L105
        for (int v60 = 0; v60 < 32; v60 += 1) {	// L106
          float v61;	// L107
          v61 = (float)0.000000;	// L108
          if (((-v58) + 111) >= 0 && ((-v59) + 111) >= 0) {	// L109
            float v62 = v54[v57][v60][v58][v59];	// L110
            v61 = v62;	// L111
          }
          float v63 = v61;	// L113
          v56[v57][v60][v58][v59] = v63;	// L114
        }
      }
    }
  }
  float v64[1][32][112][112];	// L119
  #pragma HLS stream variable=v64 depth=10 type=fifo

  #pragma HLS bind_storage variable=v64 type=ram_t2p impl=bram

  float v65[1][32][3][114];	// L120
  #pragma HLS array_partition variable=v65 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v65 type=ram_2p impl=bram

  float v66[1][32][3][3];	// L121
  #pragma HLS array_partition variable=v66 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v66 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v66 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v66 type=ram_2p impl=lutram

  for (int v67 = 0; v67 < 1; v67 += 1) {	// L122
    for (int v68 = 0; v68 < 114; v68 += 1) {	// L123
      for (int v69 = 0; v69 < 114; v69 += 1) {	// L124
        for (int v70 = 0; v70 < 32; v70 += 1) {	// L125
          float v71 = v65[v67][v70][1][v69];	// L126
          v65[v67][v70][0][v69] = v71;	// L127
          float v72 = v65[v67][v70][2][v69];	// L128
          v65[v67][v70][1][v69] = v72;	// L129
          float v73 = v56[v67][v70][v68][v69];	// L130
          v65[v67][v70][2][v69] = v73;	// L131
        }
        if ((v68 - 2) >= 0) {	// L133
          for (int v74 = 0; v74 < 32; v74 += 1) {	// L134
            for (int v75 = 0; v75 < 3; v75 += 1) {	// L135
              float v76 = v66[v67][v74][v75][1];	// L136
              v66[v67][v74][v75][0] = v76;	// L137
              float v77 = v66[v67][v74][v75][2];	// L138
              v66[v67][v74][v75][1] = v77;	// L139
              float v78 = v65[v67][v74][v75][v69];	// L140
              v66[v67][v74][v75][2] = v78;	// L141
            }
          }
          if ((v69 - 2) >= 0) {	// L144
            float v79[32];	// L145
            #pragma HLS bind_storage variable=v79 type=ram_2p impl=bram

            for (int v80 = 0; v80 < 32; v80 += 1) {	// L146
              v79[v80] = (float)0.000000;	// L147
              for (int v81 = 0; v81 < 2; v81 += 1) {	// L148
                #pragma HLS pipeline II=1
                for (int v82 = 0; v82 < 16; v82 += 1) {	// L149
                  for (int v83 = 0; v83 < 3; v83 += 1) {	// L150
                    for (int v84 = 0; v84 < 3; v84 += 1) {	// L151
                      float v85 = v66[v67][(v82 + (v81 * 16))][v83][v84];	// L152
                      float v86 = v53[v80][(v82 + (v81 * 16))][v83][v84];	// L153
                      float v87 = v85 * v86;	// L154
                      float v88 = v79[v80];	// L155
                      float v89 = v88 + v87;	// L156
                      v79[v80] = v89;	// L157
                    }
                  }
                }
              }
              float v90 = v79[v80];	// L162
              v64[v67][v80][(v68 - 2)][(v69 - 2)] = v90;	// L163
            }
          }
        }
      }
    }
  }
  for (int v91 = 0; v91 < 1; v91 += 1) {	// L170
    for (int v92 = 0; v92 < 112; v92 += 1) {	// L171
      for (int v93 = 0; v93 < 112; v93 += 1) {	// L172
        for (int v94 = 0; v94 < 32; v94 += 1) {	// L173
          float v95 = v64[0][v94][v92][v93];	// L174
          float v96 = (double)0.000010;	// L175
          float v97 = v96 + (float)1.000000;	// L176
          float v98 = 1.0 / sqrt(v97);	// L177
          float v99 = v95 * v98;	// L178
          float v100 = v99 + (float)0.000000;	// L179
          bool v101 = v100 > (float)0.000000;	// L180
          float v102 = v101 ? v100 : (float)0.000000;	// L181
          v55[v91][v94][v92][v93] = v102;	// L182
        }
      }
    }
  }
  return ;	// L187
}

/// This is top function.
void main_graph(
  float v103[1][32][112][112],
  float v104[32][32][3][3],
  float v105[32][32][3][3],
  float v106[1][32][112][112]
) {	// L189
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v103 bundle=gmem1
  #pragma HLS bind_storage variable=v103 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v104 bundle=gmem2
  #pragma HLS array_partition variable=v104 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v104 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v104 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v104 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v105 bundle=gmem3
  #pragma HLS array_partition variable=v105 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v105 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v105 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v105 type=ram_2p impl=lutram

  #pragma HLS interface bram port=v106 bundle=gmem4
  #pragma HLS bind_storage variable=v106 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v107[1][32][112][112];	// L191
  #pragma HLS stream variable=v107 depth=10 type=fifo

  #pragma HLS bind_storage variable=v107 type=ram_t2p impl=bram

  main_graph_node1(v104, v103, v107);	// L192
  main_graph_node0(v107, v105, v103, v106);	// L193
  return ;	// L194
}

