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

// Adder Tree Helper Template Function
template<typename T, int N>
T adder_tree(T inputs[N]) {
    #pragma HLS INLINE
    T stage[N];
    #pragma HLS ARRAY_PARTITION variable=stage complete dim=1

    for (int i = 0; i < N; i++) {
        #pragma HLS UNROLL
        stage[i] = inputs[i];
    }

    int current_size = N;
    while (current_size > 1) {
        int next_size = (current_size + 1) / 2;
        for (int i = 0; i < next_size; i++) {
            #pragma HLS UNROLL
            if (i * 2 + 1 < current_size) {
                stage[i] = stage[i * 2] + stage[i * 2 + 1];
            } else {
                stage[i] = stage[i * 2];
            }
        }
        current_size = next_size;
    }
    return stage[0];
}

void main_graph_node0(
  float v0[32][32][3][3],
  float v1[1][32][32][32],
  float v2[1][32][32][32]
) {
  #pragma HLS dataflow

  float v3[1][32][34][34];
  #pragma HLS stream variable=v3 depth=10 type=fifo
  #pragma HLS bind_storage variable=v3 type=ram_t2p impl=bram

  for (int v4 = 0; v4 < 1; v4 += 1) {
    for (int v5 = 0; v5 < 34; v5 += 1) {
      for (int v6 = 0; v6 < 34; v6 += 1) {
        for (int v7 = 0; v7 < 32; v7 += 1) {
          #pragma HLS pipeline II=1
          float v8 = (v5 < 32 && v6 < 32) ? v1[v4][v7][v5][v6] : 0.0f;
          v3[v4][v7][v5][v6] = v8;
        }
      }
    }
  }

  float v11[1][32][32][32];
  #pragma HLS stream variable=v11 depth=10 type=fifo
  #pragma HLS bind_storage variable=v11 type=ram_t2p impl=bram

  float v12[1][32][3][34];
  #pragma HLS array_partition variable=v12 complete dim=3
  #pragma HLS bind_storage variable=v12 type=ram_2p impl=bram

  float v13[1][32][3][3];
  #pragma HLS array_partition variable=v13 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v13 complete dim=3
  #pragma HLS array_partition variable=v13 complete dim=4
  #pragma HLS bind_storage variable=v13 type=ram_2p impl=lutram

  for (int v14 = 0; v14 < 1; v14 += 1) {
    for (int v15 = 0; v15 < 34; v15 += 1) {
      for (int v16 = 0; v16 < 34; v16 += 1) {
        for (int v17 = 0; v17 < 32; v17 += 1) {
          #pragma HLS pipeline II=1
          v12[v14][v17][0][v16] = v12[v14][v17][1][v16];
          v12[v14][v17][1][v16] = v12[v14][v17][2][v16];
          v12[v14][v17][2][v16] = v3[v14][v17][v15][v16];
        }
        if (v15 >= 2) {
          for (int v21 = 0; v21 < 32; v21 += 1) {
            #pragma HLS pipeline II=1
            for (int v22 = 0; v22 < 3; v22 += 1) {
              #pragma HLS UNROLL
              v13[v14][v21][v22][0] = v13[v14][v21][v22][1];
              v13[v14][v21][v22][1] = v13[v14][v21][v22][2];
              v13[v14][v21][v22][2] = v12[v14][v21][v22][v16];
            }
          }
          if (v16 >= 2) {
            float v26[32];
            #pragma HLS ARRAY_PARTITION variable=v26 complete dim=1

            for (int v27 = 0; v27 < 32; v27 += 1) {
              v26[v27] = 0.0f;
              for (int v28 = 0; v28 < 2; v28 += 1) {
                #pragma HLS pipeline II=1
                const int TREE_SIZE = 16 * 3 * 3;
                float products[TREE_SIZE];
                #pragma HLS ARRAY_PARTITION variable=products complete

                for (int i = 0; i < TREE_SIZE; i++) {
                  #pragma HLS UNROLL
                  int w = i % 3;
                  int h = (i / 3) % 3;
                  int ch = i / 9;
                  products[i] = v13[v14][ch + (v28 * 16)][h][w] * v0[v27][ch + (v28 * 16)][h][w];
                }
                v26[v27] += adder_tree<float, TREE_SIZE>(products);
              }
              v11[v14][v27][v15-2][v16-2] = v26[v27];
            }
          }
        }
      }
    }
  }

  for (int v39 = 0; v39 < 32; v39 += 1) {
    for (int v40 = 0; v40 < 32; v40 += 1) {
      #pragma HLS pipeline II=1
      for (int v41 = 0; v41 < 32; v41 += 1) {
        #pragma HLS UNROLL factor=16
        float v42 = v11[0][v41][v39][v40];
        v2[0][v41][v39][v40] = (v42 > 0.0f) ? v42 : 0.0f;
      }
    }
  }
}

void main_graph_node1(
  float v45[32][32][3][3],
  float v46[1][32][32][32],
  float v47[1][32][32][32]
) {
  #pragma HLS dataflow

  float v48[1][32][34][34];
  #pragma HLS stream variable=v48 depth=10 type=fifo
  #pragma HLS bind_storage variable=v48 type=ram_t2p impl=bram

  for (int v50 = 0; v50 < 34; v50 += 1) {
    for (int v51 = 0; v51 < 34; v51 += 1) {
      for (int v52 = 0; v52 < 32; v52 += 1) {
        #pragma HLS pipeline II=1
        v48[0][v52][v50][v51] = (v50 < 32 && v51 < 32) ? v46[0][v52][v50][v51] : 0.0f;
      }
    }
  }

  float v56[1][32][32][32];
  #pragma HLS stream variable=v56 depth=10 type=fifo
  #pragma HLS bind_storage variable=v56 type=ram_t2p impl=bram

  float v57[1][32][3][34];
  #pragma HLS array_partition variable=v57 complete dim=3
  #pragma HLS bind_storage variable=v57 type=ram_2p impl=bram

  float v58[1][32][3][3];
  #pragma HLS array_partition variable=v58 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v58 complete dim=3
  #pragma HLS array_partition variable=v58 complete dim=4
  #pragma HLS bind_storage variable=v58 type=ram_2p impl=lutram

  for (int v60 = 0; v60 < 34; v60 += 1) {
    for (int v61 = 0; v61 < 34; v61 += 1) {
      for (int v62 = 0; v62 < 32; v62 += 1) {
        #pragma HLS pipeline II=1
        v57[0][v62][0][v61] = v57[0][v62][1][v61];
        v57[0][v62][1][v61] = v57[0][v62][2][v61];
        v57[0][v62][2][v61] = v48[0][v62][v60][v61];
      }
      if (v60 >= 2) {
        for (int v66 = 0; v66 < 32; v66 += 1) {
          #pragma HLS pipeline II=1
          for (int v67 = 0; v67 < 3; v67 += 1) {
            #pragma HLS UNROLL
            v58[0][v66][v67][0] = v58[0][v66][v67][1];
            v58[0][v66][v67][1] = v58[0][v66][v67][2];
            v58[0][v66][v67][2] = v57[0][v66][v67][v61];
          }
        }
        if (v61 >= 2) {
          float v71[32];
          #pragma HLS ARRAY_PARTITION variable=v71 complete dim=1
          for (int v72 = 0; v72 < 32; v72 += 1) {
            v71[v72] = 0.0f;
            for (int v73 = 0; v73 < 2; v73 += 1) {
              #pragma HLS pipeline II=1
              const int T_SIZE = 16 * 3 * 3;
              float prods[T_SIZE];
              #pragma HLS ARRAY_PARTITION variable=prods complete
              for (int i = 0; i < T_SIZE; i++) {
                #pragma HLS UNROLL
                int w = i % 3; int h = (i/3)%3; int ch = i/9;
                prods[i] = v58[0][ch + (v73*16)][h][w] * v45[v72][ch + (v73*16)][h][w];
              }
              v71[v72] += adder_tree<float, T_SIZE>(prods);
            }
            v56[0][v72][v60-2][v61-2] = v71[v72];
          }
        }
      }
    }
  }

  for (int v84 = 0; v84 < 32; v84 += 1) {
    for (int v85 = 0; v85 < 32; v85 += 1) {
      #pragma HLS pipeline II=1
      for (int v86 = 0; v86 < 32; v86 += 1) {
        #pragma HLS UNROLL factor=16
        float v87 = v56[0][v86][v84][v85];
        v47[0][v86][v84][v85] = (v87 > 0.0f) ? v87 : 0.0f;
      }
    }
  }
}

void main_graph_node2(
  float v90[1][3][32][32],
  float v91[32][3][3][3],
  float v92[1][32][32][32]
) {
  #pragma HLS dataflow

  float v93[1][3][34][34];
  #pragma HLS stream variable=v93 depth=10 type=fifo
  #pragma HLS bind_storage variable=v93 type=ram_t2p impl=bram

  for (int v95 = 0; v95 < 34; v95 += 1) {
    for (int v96 = 0; v96 < 34; v96 += 1) {
      for (int v97 = 0; v97 < 3; v97 += 1) {
        #pragma HLS pipeline II=1
        v93[0][v97][v95][v96] = (v95 < 32 && v96 < 32) ? v90[0][v97][v95][v96] : 0.0f;
      }
    }
  }

  float v101[1][32][32][32];
  #pragma HLS stream variable=v101 depth=10 type=fifo
  #pragma HLS bind_storage variable=v101 type=ram_t2p impl=bram

  float v102[1][3][3][34];
  #pragma HLS array_partition variable=v102 complete dim=3
  #pragma HLS bind_storage variable=v102 type=ram_2p impl=lutram

  float v103[1][3][3][3];
  #pragma HLS array_partition variable=v103 complete dim=2
  #pragma HLS array_partition variable=v103 complete dim=3
  #pragma HLS array_partition variable=v103 complete dim=4
  #pragma HLS bind_storage variable=v103 type=ram_2p impl=lutram

  for (int v105 = 0; v105 < 34; v105 += 1) {
    for (int v106 = 0; v106 < 34; v106 += 1) {
      for (int v107 = 0; v107 < 3; v107 += 1) {
        #pragma HLS pipeline II=1
        v102[0][v107][0][v106] = v102[0][v107][1][v106];
        v102[0][v107][1][v106] = v102[0][v107][2][v106];
        v102[0][v107][2][v106] = v93[0][v107][v105][v106];
      }
      if (v105 >= 2) {
        for (int v111 = 0; v111 < 3; v111 += 1) {
          #pragma HLS pipeline II=1
          for (int v112 = 0; v112 < 3; v112 += 1) {
            #pragma HLS UNROLL
            v103[0][v111][v112][0] = v103[0][v111][v112][1];
            v103[0][v111][v112][1] = v103[0][v111][v112][2];
            v103[0][v111][v112][2] = v102[0][v111][v112][v106];
          }
        }
        if (v106 >= 2) {
          for (int v117 = 0; v117 < 32; v117 += 1) {
            #pragma HLS pipeline II=1
            const int N2_SIZE = 3 * 3 * 3;
            float p[N2_SIZE];
            #pragma HLS ARRAY_PARTITION variable=p complete
            for (int i = 0; i < N2_SIZE; i++) {
              #pragma HLS UNROLL
              int w = i % 3; int h = (i/3)%3; int ch = i/9;
              p[i] = v103[0][ch][h][w] * v91[v117][ch][h][w];
            }
            v101[0][v117][v105-2][v106-2] = adder_tree<float, N2_SIZE>(p);
          }
        }
      }
    }
  }

  for (int v129 = 0; v129 < 32; v129 += 1) {
    for (int v130 = 0; v130 < 32; v130 += 1) {
      #pragma HLS pipeline II=1
      for (int v131 = 0; v131 < 32; v131 += 1) {
        #pragma HLS UNROLL factor=16
        float v132 = v101[0][v131][v129][v130];
        v92[0][v131][v129][v130] = (v132 > 0.0f) ? v132 : 0.0f;
      }
    }
  }
}

void main_graph(
  float v135[1][3][32][32],
  float v136[32][3][3][3],
  float v137[32][32][3][3],
  float v138[32][32][3][3],
  float v139[1][32][32][32]
) {
  #pragma HLS DATAFLOW
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v135
  #pragma HLS interface bram port=v136
  #pragma HLS interface bram port=v137
  #pragma HLS interface bram port=v138
  #pragma HLS interface bram port=v139

  // 全分区以支持 AdderTree 单周期读取
  #pragma HLS array_partition variable=v136 complete dim=2
  #pragma HLS array_partition variable=v136 complete dim=3
  #pragma HLS array_partition variable=v136 complete dim=4
  #pragma HLS array_partition variable=v137 complete dim=2
  #pragma HLS array_partition variable=v137 complete dim=3
  #pragma HLS array_partition variable=v137 complete dim=4
  #pragma HLS array_partition variable=v138 complete dim=2
  #pragma HLS array_partition variable=v138 complete dim=3
  #pragma HLS array_partition variable=v138 complete dim=4

  float v140[1][32][32][32];
  #pragma HLS stream variable=v140 depth=10 type=fifo
  float v141[1][32][32][32];
  #pragma HLS stream variable=v141 depth=10 type=fifo

  main_graph_node2(v135, v136, v140);
  main_graph_node1(v137, v140, v141);
  main_graph_node0(v138, v141, v139);
}