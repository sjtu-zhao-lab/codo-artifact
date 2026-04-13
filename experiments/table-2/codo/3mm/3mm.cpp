
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
  float v0[180][190],
  float v1[190][210],
  float v2[180][210]
) {	// L9
  #pragma HLS dataflow

  float v3[190][210];	// L11
  #pragma HLS array_partition variable=v3 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v3 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v3 type=ram_2p impl=bram

  float v4[180][190];	// L12
  #pragma HLS array_partition variable=v4 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v4 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v4 type=ram_2p impl=bram

  float v5[180][210];	// L13
  #pragma HLS stream variable=v5 depth=10 type=fifo

  #pragma HLS array_partition variable=v5 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v5 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v5 type=ram_2p impl=bram

  float v6[180][210];	// L14
  #pragma HLS array_partition variable=v6 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v6 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v6 type=ram_2p impl=bram

  for (int v7 = 0; v7 < 60; v7 += 1) {	// L15
    for (int v8 = 0; v8 < 70; v8 += 1) {	// L16
      #pragma HLS pipeline II=1
      for (int v9 = 0; v9 < 3; v9 += 1) {	// L17
        for (int v10 = 0; v10 < 3; v10 += 1) {	// L18
          v5[(v9 + (v7 * 3))][(v10 + (v8 * 3))] = (float)0.000000;	// L19
        }
      }
    }
  }
  for (int v11 = 0; v11 < 60; v11 += 1) {	// L24
    for (int v12 = 0; v12 < 38; v12 += 1) {	// L25
      for (int v13 = 0; v13 < 70; v13 += 1) {	// L26
        #pragma HLS pipeline II=1
        for (int v14 = 0; v14 < 3; v14 += 1) {	// L27
          for (int v15 = 0; v15 < 5; v15 += 1) {	// L28
            for (int v16 = 0; v16 < 3; v16 += 1) {	// L29
              if ((v16 + (v13 * 3)) == 0) {	// L30
                float v17 = v0[(v14 + (v11 * 3))][(v15 + (v12 * 5))];	// L31
                v4[(v14 + (v11 * 3))][(v15 + (v12 * 5))] = v17;	// L32
              }
              float v18 = v4[(v14 + (v11 * 3))][(v15 + (v12 * 5))];	// L34
              if ((v14 + (v11 * 3)) == 0) {	// L35
                float v19 = v1[(v15 + (v12 * 5))][(v16 + (v13 * 3))];	// L36
                v3[(v15 + (v12 * 5))][(v16 + (v13 * 3))] = v19;	// L37
              }
              float v20 = v3[(v15 + (v12 * 5))][(v16 + (v13 * 3))];	// L39
              if ((v15 + (v12 * 5)) == 0) {	// L40
                float v21 = v5[(v14 + (v11 * 3))][(v16 + (v13 * 3))];	// L41
                v6[(v14 + (v11 * 3))][(v16 + (v13 * 3))] = v21;	// L42
              }
              float v22 = v6[(v14 + (v11 * 3))][(v16 + (v13 * 3))];	// L44
              float v23 = v18 * v20;	// L45
              float v24 = v22 + v23;	// L46
              v6[(v14 + (v11 * 3))][(v16 + (v13 * 3))] = v24;	// L47
              if (((v15 + (v12 * 5)) - 189) == 0) {	// L48
                float v25 = v6[(v14 + (v11 * 3))][(v16 + (v13 * 3))];	// L49
                v2[(v14 + (v11 * 3))][(v16 + (v13 * 3))] = v25;	// L50
              }
            }
          }
        }
      }
    }
  }
  return ;	// L58
}

void main_graph_node1(
  float v26[190][220],
  float v27[220][210],
  float v28[190][210]
) {	// L60
  #pragma HLS dataflow

  float v29[220][210];	// L62
  #pragma HLS array_partition variable=v29 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v29 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v29 type=ram_2p impl=bram

  float v30[190][220];	// L63
  #pragma HLS array_partition variable=v30 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v30 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v30 type=ram_2p impl=bram

  float v31[190][210];	// L64
  #pragma HLS stream variable=v31 depth=10 type=fifo

  #pragma HLS array_partition variable=v31 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v31 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v31 type=ram_2p impl=bram

  float v32[190][210];	// L65
  #pragma HLS array_partition variable=v32 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v32 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v32 type=ram_2p impl=bram

  for (int v33 = 0; v33 < 38; v33 += 1) {	// L66
    for (int v34 = 0; v34 < 70; v34 += 1) {	// L67
      #pragma HLS pipeline II=1
      for (int v35 = 0; v35 < 5; v35 += 1) {	// L68
        for (int v36 = 0; v36 < 3; v36 += 1) {	// L69
          v31[(v35 + (v33 * 5))][(v36 + (v34 * 3))] = (float)0.000000;	// L70
        }
      }
    }
  }
  for (int v37 = 0; v37 < 38; v37 += 1) {	// L75
    for (int v38 = 0; v38 < 55; v38 += 1) {	// L76
      for (int v39 = 0; v39 < 70; v39 += 1) {	// L77
        #pragma HLS pipeline II=1
        for (int v40 = 0; v40 < 5; v40 += 1) {	// L78
          for (int v41 = 0; v41 < 4; v41 += 1) {	// L79
            for (int v42 = 0; v42 < 3; v42 += 1) {	// L80
              if ((v42 + (v39 * 3)) == 0) {	// L81
                float v43 = v26[(v40 + (v37 * 5))][(v41 + (v38 * 4))];	// L82
                v30[(v40 + (v37 * 5))][(v41 + (v38 * 4))] = v43;	// L83
              }
              float v44 = v30[(v40 + (v37 * 5))][(v41 + (v38 * 4))];	// L85
              if ((v40 + (v37 * 5)) == 0) {	// L86
                float v45 = v27[(v41 + (v38 * 4))][(v42 + (v39 * 3))];	// L87
                v29[(v41 + (v38 * 4))][(v42 + (v39 * 3))] = v45;	// L88
              }
              float v46 = v29[(v41 + (v38 * 4))][(v42 + (v39 * 3))];	// L90
              if ((v41 + (v38 * 4)) == 0) {	// L91
                float v47 = v31[(v40 + (v37 * 5))][(v42 + (v39 * 3))];	// L92
                v32[(v40 + (v37 * 5))][(v42 + (v39 * 3))] = v47;	// L93
              }
              float v48 = v32[(v40 + (v37 * 5))][(v42 + (v39 * 3))];	// L95
              float v49 = v44 * v46;	// L96
              float v50 = v48 + v49;	// L97
              v32[(v40 + (v37 * 5))][(v42 + (v39 * 3))] = v50;	// L98
              if (((v41 + (v38 * 4)) - 219) == 0) {	// L99
                float v51 = v32[(v40 + (v37 * 5))][(v42 + (v39 * 3))];	// L100
                v28[(v40 + (v37 * 5))][(v42 + (v39 * 3))] = v51;	// L101
              }
            }
          }
        }
      }
    }
  }
  return ;	// L109
}

void main_graph_node2(
  float v52[180][200],
  float v53[200][190],
  float v54[180][190]
) {	// L111
  #pragma HLS dataflow

  float v55[200][190];	// L113
  #pragma HLS array_partition variable=v55 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v55 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v55 type=ram_2p impl=bram

  float v56[180][200];	// L114
  #pragma HLS array_partition variable=v56 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v56 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v56 type=ram_2p impl=bram

  float v57[180][190];	// L115
  #pragma HLS stream variable=v57 depth=10 type=fifo

  #pragma HLS array_partition variable=v57 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v57 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v57 type=ram_2p impl=bram

  float v58[180][190];	// L116
  #pragma HLS array_partition variable=v58 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v58 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v58 type=ram_2p impl=bram

  for (int v59 = 0; v59 < 60; v59 += 1) {	// L117
    for (int v60 = 0; v60 < 38; v60 += 1) {	// L118
      #pragma HLS pipeline II=1
      for (int v61 = 0; v61 < 3; v61 += 1) {	// L119
        for (int v62 = 0; v62 < 5; v62 += 1) {	// L120
          v57[(v61 + (v59 * 3))][(v62 + (v60 * 5))] = (float)0.000000;	// L121
        }
      }
    }
  }
  for (int v63 = 0; v63 < 60; v63 += 1) {	// L126
    for (int v64 = 0; v64 < 50; v64 += 1) {	// L127
      for (int v65 = 0; v65 < 38; v65 += 1) {	// L128
        #pragma HLS pipeline II=1
        for (int v66 = 0; v66 < 3; v66 += 1) {	// L129
          for (int v67 = 0; v67 < 4; v67 += 1) {	// L130
            for (int v68 = 0; v68 < 5; v68 += 1) {	// L131
              if ((v68 + (v65 * 5)) == 0) {	// L132
                float v69 = v52[(v66 + (v63 * 3))][(v67 + (v64 * 4))];	// L133
                v56[(v66 + (v63 * 3))][(v67 + (v64 * 4))] = v69;	// L134
              }
              float v70 = v56[(v66 + (v63 * 3))][(v67 + (v64 * 4))];	// L136
              if ((v66 + (v63 * 3)) == 0) {	// L137
                float v71 = v53[(v67 + (v64 * 4))][(v68 + (v65 * 5))];	// L138
                v55[(v67 + (v64 * 4))][(v68 + (v65 * 5))] = v71;	// L139
              }
              float v72 = v55[(v67 + (v64 * 4))][(v68 + (v65 * 5))];	// L141
              if ((v67 + (v64 * 4)) == 0) {	// L142
                float v73 = v57[(v66 + (v63 * 3))][(v68 + (v65 * 5))];	// L143
                v58[(v66 + (v63 * 3))][(v68 + (v65 * 5))] = v73;	// L144
              }
              float v74 = v58[(v66 + (v63 * 3))][(v68 + (v65 * 5))];	// L146
              float v75 = v70 * v72;	// L147
              float v76 = v74 + v75;	// L148
              v58[(v66 + (v63 * 3))][(v68 + (v65 * 5))] = v76;	// L149
              if (((v67 + (v64 * 4)) - 199) == 0) {	// L150
                float v77 = v58[(v66 + (v63 * 3))][(v68 + (v65 * 5))];	// L151
                v54[(v66 + (v63 * 3))][(v68 + (v65 * 5))] = v77;	// L152
              }
            }
          }
        }
      }
    }
  }
  return ;	// L160
}

/// This is top function.
void main_graph(
  float v78[180][200],
  float v79[200][190],
  float v80[190][220],
  float v81[220][210],
  float v82[180][210]
) {	// L162
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v78 bundle=gmem1
  #pragma HLS array_partition variable=v78 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v78 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v78 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v79 bundle=gmem2
  #pragma HLS array_partition variable=v79 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v79 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v79 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v80 bundle=gmem3
  #pragma HLS array_partition variable=v80 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v80 cyclic factor=4 dim=2
  #pragma HLS bind_storage variable=v80 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v81 bundle=gmem4
  #pragma HLS array_partition variable=v81 cyclic factor=4 dim=1
  #pragma HLS array_partition variable=v81 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v81 type=ram_t2p impl=bram

  #pragma HLS interface bram port=v82 bundle=gmem5
  #pragma HLS array_partition variable=v82 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v82 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v82 type=ram_t2p impl=bram

  #pragma HLS dataflow

  float v83[180][190];	// L164
  #pragma HLS stream variable=v83 depth=10 type=fifo

  #pragma HLS array_partition variable=v83 cyclic factor=3 dim=1
  #pragma HLS array_partition variable=v83 cyclic factor=5 dim=2
  #pragma HLS bind_storage variable=v83 type=ram_t2p impl=bram

  main_graph_node2(v78, v79, v83);	// L165
  float v84[190][210];	// L166
  #pragma HLS stream variable=v84 depth=10 type=fifo

  #pragma HLS array_partition variable=v84 cyclic factor=5 dim=1
  #pragma HLS array_partition variable=v84 cyclic factor=3 dim=2
  #pragma HLS bind_storage variable=v84 type=ram_t2p impl=bram

  main_graph_node1(v80, v81, v84);	// L167
  main_graph_node0(v83, v84, v82);	// L168
  return ;	// L169
}

