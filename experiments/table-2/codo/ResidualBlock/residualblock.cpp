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
  float v1[1][32][112][112],
  float v2[1][32][112][112],
  float v3[1][32][112][112]
) {	// L4
  #pragma HLS dataflow

  float v4[1][32][114][114];	// L8
  #pragma HLS stream variable=v4 depth=10 type=fifo
  #pragma HLS bind_storage variable=v4 type=ram_t2p impl=bram

  for (int v5 = 0; v5 < 1; v5 += 1) {	// L9
    for (int v6 = 0; v6 < 114; v6 += 1) {	// L10
      for (int v7 = 0; v7 < 114; v7 += 1) {	// L11
        for (int v8 = 0; v8 < 32; v8 += 1) {	// L12
          #pragma HLS pipeline II=1
          float v9 = 0.000000;
          if (((-v6) + 111) >= 0 && ((-v7) + 111) >= 0) {
            v9 = v2[v5][v8][v6][v7];
          }
          v4[v5][v8][v6][v7] = v9;
        }
      }
    }
  }

  float v12[1][32][112][112];	// L25
  #pragma HLS stream variable=v12 depth=10 type=fifo
  #pragma HLS bind_storage variable=v12 type=ram_t2p impl=bram

  float v13[1][32][3][114];	// L26
  #pragma HLS array_partition variable=v13 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v13 type=ram_2p impl=bram

  float v14[1][32][3][3];	// L27
  #pragma HLS array_partition variable=v14 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v14 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v14 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v14 type=ram_2p impl=lutram

  for (int v15 = 0; v15 < 1; v15 += 1) {	// L28
    for (int v16 = 0; v16 < 114; v16 += 1) {	// L29
      for (int v17 = 0; v17 < 114; v17 += 1) {	// L30
        for (int v18 = 0; v18 < 32; v18 += 1) {	// L31
          #pragma HLS pipeline II=1
          v13[v15][v18][0][v17] = v13[v15][v18][1][v17];
          v13[v15][v18][1][v17] = v13[v15][v18][2][v17];
          v13[v15][v18][2][v17] = v4[v15][v18][v16][v17];
        }
        if ((v16 - 2) >= 0) {	// L39
          for (int v22 = 0; v22 < 32; v22 += 1) {	// L40
            #pragma HLS pipeline II=1
            for (int v23 = 0; v23 < 3; v23 += 1) {
              #pragma HLS UNROLL
              v14[v15][v22][v23][0] = v14[v15][v22][v23][1];
              v14[v15][v22][v23][1] = v14[v15][v22][v23][2];
              v14[v15][v22][v23][2] = v13[v15][v22][v23][v17];
            }
          }
          if ((v17 - 2) >= 0) {	// L50
            float v27[32];	// L51
            #pragma HLS ARRAY_PARTITION variable=v27 complete dim=1

            for (int v28 = 0; v28 < 32; v28 += 1) {	// L52
              v27[v28] = (float)0.000000;
              // 保留 v29 < 2 的循环，确保不改变原有的 II=1 下的并行度
              for (int v29 = 0; v29 < 2; v29 += 1) {	// L54
                #pragma HLS pipeline II=1
                
                // 将原有的 v30(16), v31(3), v32(3) 展开为 144 个元素的加法树
                const int TREE_SIZE = 16 * 3 * 3;
                float products[TREE_SIZE];
                #pragma HLS ARRAY_PARTITION variable=products complete dim=1

                for (int i = 0; i < TREE_SIZE; i++) {
                  #pragma HLS UNROLL
                  int v32 = i % 3;
                  int v31 = (i / 3) % 3;
                  int v30 = i / 9;
                  float v33 = v14[v15][(v30 + (v29 * 16))][v31][v32];
                  float v34 = v0[v28][(v30 + (v29 * 16))][v31][v32];
                  products[i] = v33 * v34;
                }

                // 累加每组 144 个元素的局部和
                v27[v28] += adder_tree<float, TREE_SIZE>(products);
              }
              v12[v15][v28][(v16 - 2)][(v17 - 2)] = v27[v28];
            }
          }
        }
      }
    }
  }

  for (int v39 = 0; v39 < 1; v39 += 1) {	// L76
    for (int v40 = 0; v40 < 112; v40 += 1) {	// L77
      for (int v41 = 0; v41 < 112; v41 += 1) {	// L78
        for (int v42 = 0; v42 < 32; v42 += 1) {	// L79
          #pragma HLS pipeline II=1
          float v43 = v12[0][v42][v40][v41];
          float v44 = v1[0][v42][v40][v41];
          float v47 = 1.0 / sqrt(1.000010);
          float v50 = (v43 * v47) + v44;
          v3[v39][v42][v40][v41] = (v50 > 0.0f) ? v50 : 0.0f;
        }
      }
    }
  }
}

void main_graph_node1(
  float v53[32][32][3][3],
  float v54[1][32][112][112],
  float v55[1][32][112][112]
) {	// L97
  #pragma HLS dataflow

  float v56[1][32][114][114];	// L101
  #pragma HLS stream variable=v56 depth=10 type=fifo
  #pragma HLS bind_storage variable=v56 type=ram_t2p impl=bram

  for (int v57 = 0; v57 < 1; v57 += 1) {	// L102
    for (int v58 = 0; v58 < 114; v58 += 1) {	// L103
      for (int v59 = 0; v59 < 114; v59 += 1) {	// L104
        for (int v60 = 0; v60 < 32; v60 += 1) {	// L105
          #pragma HLS pipeline II=1
          float v61 = 0.000000;
          if (((-v58) + 111) >= 0 && ((-v59) + 111) >= 0) {
            v61 = v54[v57][v60][v58][v59];
          }
          v56[v57][v60][v58][v59] = v61;
        }
      }
    }
  }

  float v64[1][32][112][112];	// L118
  #pragma HLS stream variable=v64 depth=10 type=fifo
  #pragma HLS bind_storage variable=v64 type=ram_t2p impl=bram

  float v65[1][32][3][114];	// L119
  #pragma HLS array_partition variable=v65 cyclic factor=3 dim=3
  #pragma HLS bind_storage variable=v65 type=ram_2p impl=bram

  float v66[1][32][3][3];	// L120
  #pragma HLS array_partition variable=v66 cyclic factor=16 dim=2
  #pragma HLS array_partition variable=v66 cyclic factor=3 dim=3
  #pragma HLS array_partition variable=v66 cyclic factor=3 dim=4
  #pragma HLS bind_storage variable=v66 type=ram_2p impl=lutram

  for (int v67 = 0; v67 < 1; v67 += 1) {	// L121
    for (int v68 = 0; v68 < 114; v68 += 1) {	// L122
      for (int v69 = 0; v69 < 114; v69 += 1) {	// L123
        for (int v70 = 0; v70 < 32; v70 += 1) {	// L124
          #pragma HLS pipeline II=1
          v65[v67][v70][0][v69] = v65[v67][v70][1][v69];
          v65[v67][v70][1][v69] = v65[v67][v70][2][v69];
          v65[v67][v70][2][v69] = v56[v67][v70][v68][v69];
        }
        if ((v68 - 2) >= 0) {	// L132
          for (int v74 = 0; v74 < 32; v74 += 1) {	// L133
            #pragma HLS pipeline II=1
            for (int v75 = 0; v75 < 3; v75 += 1) {
              #pragma HLS UNROLL
              v66[v67][v74][v75][0] = v66[v67][v74][v75][1];
              v66[v67][v74][v75][1] = v66[v67][v74][v75][2];
              v66[v67][v74][v75][2] = v65[v67][v74][v75][v69];
            }
          }
          if ((v69 - 2) >= 0) {	// L143
            float v79[32];	// L144
            #pragma HLS ARRAY_PARTITION variable=v79 complete dim=1

            for (int v80 = 0; v80 < 32; v80 += 1) {	// L145
              v79[v80] = (float)0.000000;
              // 保留 v81 < 2 的循环
              for (int v81 = 0; v81 < 2; v81 += 1) {	// L147
                #pragma HLS pipeline II=1
                
                const int TREE_SIZE = 16 * 3 * 3;
                float products[TREE_SIZE];
                #pragma HLS ARRAY_PARTITION variable=products complete dim=1

                for (int i = 0; i < TREE_SIZE; i++) {
                  #pragma HLS UNROLL
                  int v84 = i % 3;
                  int v83 = (i / 3) % 3;
                  int v82 = i / 9;
                  float v85 = v66[v67][(v82 + (v81 * 16))][v83][v84];
                  float v86 = v53[v80][(v82 + (v81 * 16))][v83][v84];
                  products[i] = v85 * v86;
                }
                v79[v80] += adder_tree<float, TREE_SIZE>(products);
              }
              v64[v67][v80][(v68 - 2)][(v69 - 2)] = v79[v80];
            }
          }
        }
      }
    }
  }

  for (int v91 = 0; v91 < 1; v91 += 1) {	// L169
    for (int v92 = 0; v92 < 112; v92 += 1) {	// L170
      for (int v93 = 0; v93 < 112; v93 += 1) {	// L171
        for (int v94 = 0; v94 < 32; v94 += 1) {	// L172
          #pragma HLS pipeline II=1
          float v95 = v64[0][v94][v92][v93];
          float v98 = 1.0 / sqrt(1.000010);
          float v100 = (v95 * v98);
          v55[v91][v94][v92][v93] = (v100 > 0.0f) ? v100 : 0.0f;
        }
      }
    }
  }
}

void main_graph(
  float v103[1][32][112][112],
  float v104[32][32][3][3],
  float v105[32][32][3][3],
  float v106[1][32][112][112]
) {	// L188
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

  float v107[1][32][112][112];	// L190
  #pragma HLS stream variable=v107 depth=10 type=fifo
  #pragma HLS bind_storage variable=v107 type=ram_t2p impl=bram

  main_graph_node1(v104, v103, v107);
  main_graph_node0(v105, v103, v107, v106);
}