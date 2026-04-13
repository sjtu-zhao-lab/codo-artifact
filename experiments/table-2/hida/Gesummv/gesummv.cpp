
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

/// This is top function.
/// Latency=6274, interval=6274
/// DSP=180, BRAM=0
void kernel_gesummv(
  ap_int<32> v0,
  float v1,
  float v2,
  float v3[250][250],
  float v4[250][250],
  float v5[250],
  float v6[250],
  float v7[250]
) {	// L4, [0,6274)
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface s_axilite port=v0 bundle=ctrl
  #pragma HLS interface s_axilite port=v1 bundle=ctrl
  #pragma HLS interface s_axilite port=v2 bundle=ctrl
  #pragma HLS interface bram port=v3
  #pragma HLS array_partition variable=v3 cyclic factor=10 dim=1

  #pragma HLS interface bram port=v4
  #pragma HLS array_partition variable=v4 cyclic factor=10 dim=1

  #pragma HLS interface bram port=v5
  #pragma HLS array_partition variable=v5 cyclic factor=10 dim=1

  #pragma HLS interface bram port=v6
  #pragma HLS interface bram port=v7
  #pragma HLS array_partition variable=v7 cyclic factor=10 dim=1

  for (int v8 = 0; v8 < 250; v8 += 1) {	// L6, [0,6272), iterCycle=21, II=1
    for (int v9 = 0; v9 < 25; v9 += 1) {	// L7, [0,47), iterCycle=21, II=1
      #pragma HLS pipeline II=1
      float v10 = v5[(v9 * 10)];	// L8, [4,6)
      float v11 = (v8 == 0) ? (float)0.000000 : v10;	// L9, [6,6)
      float v12 = v7[(v9 * 10)];	// L10, [4,6)
      float v13 = (v8 == 0) ? (float)0.000000 : v12;	// L11, [6,6)
      float v14 = v3[(v9 * 10)][v8];	// L12, [0,2)
      float v15 = v6[v8];	// L13, [0,2)
      float v16 = v14 * v15;	// L14, [2,6)
      float v17 = v16 + v11;	// L15, [6,11)
      v5[(v9 * 10)] = v17;	// L16, [20,21)
      float v18 = v4[(v9 * 10)][v8];	// L17, [0,2)
      float v19 = v18 * v15;	// L18, [2,6)
      float v20 = v19 + v13;	// L19, [6,11)
      float v21 = v1 * v17;	// L20, [11,15)
      float v22 = v2 * v20;	// L21, [11,15)
      float v23 = v21 + v22;	// L22, [15,20)
      float v24 = (((-v8) + 249) == 0) ? v23 : v13;	// L23, [20,20)
      v7[(v9 * 10)] = v24;	// L24, [20,21)
      float v25 = v5[((v9 * 10) + 1)];	// L25, [4,6)
      float v26 = (v8 == 0) ? (float)0.000000 : v25;	// L26, [6,6)
      float v27 = v7[((v9 * 10) + 1)];	// L27, [4,6)
      float v28 = (v8 == 0) ? (float)0.000000 : v27;	// L28, [6,6)
      float v29 = v3[((v9 * 10) + 1)][v8];	// L29, [0,2)
      float v30 = v29 * v15;	// L30, [2,6)
      float v31 = v30 + v26;	// L31, [6,11)
      v5[((v9 * 10) + 1)] = v31;	// L32, [20,21)
      float v32 = v4[((v9 * 10) + 1)][v8];	// L33, [0,2)
      float v33 = v32 * v15;	// L34, [2,6)
      float v34 = v33 + v28;	// L35, [6,11)
      float v35 = v1 * v31;	// L36, [11,15)
      float v36 = v2 * v34;	// L37, [11,15)
      float v37 = v35 + v36;	// L38, [15,20)
      float v38 = (((-v8) + 249) == 0) ? v37 : v28;	// L39, [20,20)
      v7[((v9 * 10) + 1)] = v38;	// L40, [20,21)
      float v39 = v5[((v9 * 10) + 2)];	// L41, [4,6)
      float v40 = (v8 == 0) ? (float)0.000000 : v39;	// L42, [6,6)
      float v41 = v7[((v9 * 10) + 2)];	// L43, [4,6)
      float v42 = (v8 == 0) ? (float)0.000000 : v41;	// L44, [6,6)
      float v43 = v3[((v9 * 10) + 2)][v8];	// L45, [0,2)
      float v44 = v43 * v15;	// L46, [2,6)
      float v45 = v44 + v40;	// L47, [6,11)
      v5[((v9 * 10) + 2)] = v45;	// L48, [20,21)
      float v46 = v4[((v9 * 10) + 2)][v8];	// L49, [0,2)
      float v47 = v46 * v15;	// L50, [2,6)
      float v48 = v47 + v42;	// L51, [6,11)
      float v49 = v1 * v45;	// L52, [11,15)
      float v50 = v2 * v48;	// L53, [11,15)
      float v51 = v49 + v50;	// L54, [15,20)
      float v52 = (((-v8) + 249) == 0) ? v51 : v42;	// L55, [20,20)
      v7[((v9 * 10) + 2)] = v52;	// L56, [20,21)
      float v53 = v5[((v9 * 10) + 3)];	// L57, [4,6)
      float v54 = (v8 == 0) ? (float)0.000000 : v53;	// L58, [6,6)
      float v55 = v7[((v9 * 10) + 3)];	// L59, [4,6)
      float v56 = (v8 == 0) ? (float)0.000000 : v55;	// L60, [6,6)
      float v57 = v3[((v9 * 10) + 3)][v8];	// L61, [0,2)
      float v58 = v57 * v15;	// L62, [2,6)
      float v59 = v58 + v54;	// L63, [6,11)
      v5[((v9 * 10) + 3)] = v59;	// L64, [20,21)
      float v60 = v4[((v9 * 10) + 3)][v8];	// L65, [0,2)
      float v61 = v60 * v15;	// L66, [2,6)
      float v62 = v61 + v56;	// L67, [6,11)
      float v63 = v1 * v59;	// L68, [11,15)
      float v64 = v2 * v62;	// L69, [11,15)
      float v65 = v63 + v64;	// L70, [15,20)
      float v66 = (((-v8) + 249) == 0) ? v65 : v56;	// L71, [20,20)
      v7[((v9 * 10) + 3)] = v66;	// L72, [20,21)
      float v67 = v5[((v9 * 10) + 4)];	// L73, [4,6)
      float v68 = (v8 == 0) ? (float)0.000000 : v67;	// L74, [6,6)
      float v69 = v7[((v9 * 10) + 4)];	// L75, [4,6)
      float v70 = (v8 == 0) ? (float)0.000000 : v69;	// L76, [6,6)
      float v71 = v3[((v9 * 10) + 4)][v8];	// L77, [0,2)
      float v72 = v71 * v15;	// L78, [2,6)
      float v73 = v72 + v68;	// L79, [6,11)
      v5[((v9 * 10) + 4)] = v73;	// L80, [20,21)
      float v74 = v4[((v9 * 10) + 4)][v8];	// L81, [0,2)
      float v75 = v74 * v15;	// L82, [2,6)
      float v76 = v75 + v70;	// L83, [6,11)
      float v77 = v1 * v73;	// L84, [11,15)
      float v78 = v2 * v76;	// L85, [11,15)
      float v79 = v77 + v78;	// L86, [15,20)
      float v80 = (((-v8) + 249) == 0) ? v79 : v70;	// L87, [20,20)
      v7[((v9 * 10) + 4)] = v80;	// L88, [20,21)
      float v81 = v5[((v9 * 10) + 5)];	// L89, [4,6)
      float v82 = (v8 == 0) ? (float)0.000000 : v81;	// L90, [6,6)
      float v83 = v7[((v9 * 10) + 5)];	// L91, [4,6)
      float v84 = (v8 == 0) ? (float)0.000000 : v83;	// L92, [6,6)
      float v85 = v3[((v9 * 10) + 5)][v8];	// L93, [0,2)
      float v86 = v85 * v15;	// L94, [2,6)
      float v87 = v86 + v82;	// L95, [6,11)
      v5[((v9 * 10) + 5)] = v87;	// L96, [20,21)
      float v88 = v4[((v9 * 10) + 5)][v8];	// L97, [0,2)
      float v89 = v88 * v15;	// L98, [2,6)
      float v90 = v89 + v84;	// L99, [6,11)
      float v91 = v1 * v87;	// L100, [11,15)
      float v92 = v2 * v90;	// L101, [11,15)
      float v93 = v91 + v92;	// L102, [15,20)
      float v94 = (((-v8) + 249) == 0) ? v93 : v84;	// L103, [20,20)
      v7[((v9 * 10) + 5)] = v94;	// L104, [20,21)
      float v95 = v5[((v9 * 10) + 6)];	// L105, [4,6)
      float v96 = (v8 == 0) ? (float)0.000000 : v95;	// L106, [6,6)
      float v97 = v7[((v9 * 10) + 6)];	// L107, [4,6)
      float v98 = (v8 == 0) ? (float)0.000000 : v97;	// L108, [6,6)
      float v99 = v3[((v9 * 10) + 6)][v8];	// L109, [0,2)
      float v100 = v99 * v15;	// L110, [2,6)
      float v101 = v100 + v96;	// L111, [6,11)
      v5[((v9 * 10) + 6)] = v101;	// L112, [20,21)
      float v102 = v4[((v9 * 10) + 6)][v8];	// L113, [0,2)
      float v103 = v102 * v15;	// L114, [2,6)
      float v104 = v103 + v98;	// L115, [6,11)
      float v105 = v1 * v101;	// L116, [11,15)
      float v106 = v2 * v104;	// L117, [11,15)
      float v107 = v105 + v106;	// L118, [15,20)
      float v108 = (((-v8) + 249) == 0) ? v107 : v98;	// L119, [20,20)
      v7[((v9 * 10) + 6)] = v108;	// L120, [20,21)
      float v109 = v5[((v9 * 10) + 7)];	// L121, [4,6)
      float v110 = (v8 == 0) ? (float)0.000000 : v109;	// L122, [6,6)
      float v111 = v7[((v9 * 10) + 7)];	// L123, [4,6)
      float v112 = (v8 == 0) ? (float)0.000000 : v111;	// L124, [6,6)
      float v113 = v3[((v9 * 10) + 7)][v8];	// L125, [0,2)
      float v114 = v113 * v15;	// L126, [2,6)
      float v115 = v114 + v110;	// L127, [6,11)
      v5[((v9 * 10) + 7)] = v115;	// L128, [20,21)
      float v116 = v4[((v9 * 10) + 7)][v8];	// L129, [0,2)
      float v117 = v116 * v15;	// L130, [2,6)
      float v118 = v117 + v112;	// L131, [6,11)
      float v119 = v1 * v115;	// L132, [11,15)
      float v120 = v2 * v118;	// L133, [11,15)
      float v121 = v119 + v120;	// L134, [15,20)
      float v122 = (((-v8) + 249) == 0) ? v121 : v112;	// L135, [20,20)
      v7[((v9 * 10) + 7)] = v122;	// L136, [20,21)
      float v123 = v5[((v9 * 10) + 8)];	// L137, [4,6)
      float v124 = (v8 == 0) ? (float)0.000000 : v123;	// L138, [6,6)
      float v125 = v7[((v9 * 10) + 8)];	// L139, [4,6)
      float v126 = (v8 == 0) ? (float)0.000000 : v125;	// L140, [6,6)
      float v127 = v3[((v9 * 10) + 8)][v8];	// L141, [0,2)
      float v128 = v127 * v15;	// L142, [2,6)
      float v129 = v128 + v124;	// L143, [6,11)
      v5[((v9 * 10) + 8)] = v129;	// L144, [20,21)
      float v130 = v4[((v9 * 10) + 8)][v8];	// L145, [0,2)
      float v131 = v130 * v15;	// L146, [2,6)
      float v132 = v131 + v126;	// L147, [6,11)
      float v133 = v1 * v129;	// L148, [11,15)
      float v134 = v2 * v132;	// L149, [11,15)
      float v135 = v133 + v134;	// L150, [15,20)
      float v136 = (((-v8) + 249) == 0) ? v135 : v126;	// L151, [20,20)
      v7[((v9 * 10) + 8)] = v136;	// L152, [20,21)
      float v137 = v5[((v9 * 10) + 9)];	// L153, [4,6)
      float v138 = (v8 == 0) ? (float)0.000000 : v137;	// L154, [6,6)
      float v139 = v7[((v9 * 10) + 9)];	// L155, [4,6)
      float v140 = (v8 == 0) ? (float)0.000000 : v139;	// L156, [6,6)
      float v141 = v3[((v9 * 10) + 9)][v8];	// L157, [0,2)
      float v142 = v141 * v15;	// L158, [2,6)
      float v143 = v142 + v138;	// L159, [6,11)
      v5[((v9 * 10) + 9)] = v143;	// L160, [20,21)
      float v144 = v4[((v9 * 10) + 9)][v8];	// L161, [0,2)
      float v145 = v144 * v15;	// L162, [2,6)
      float v146 = v145 + v140;	// L163, [6,11)
      float v147 = v1 * v143;	// L164, [11,15)
      float v148 = v2 * v146;	// L165, [11,15)
      float v149 = v147 + v148;	// L166, [15,20)
      float v150 = (((-v8) + 249) == 0) ? v149 : v140;	// L167, [20,20)
      v7[((v9 * 10) + 9)] = v150;	// L168, [20,21)
    }
  }
}

