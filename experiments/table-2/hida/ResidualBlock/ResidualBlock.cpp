
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

void forward_node1(
  float v0[16][28][28],
  float v1[32][112][112],
  int v2,
  int v3,
  int v4
) {	// L13
  #pragma HLS inline
  for (int v5 = 0; v5 < 16; v5 += 1) {	// L14
    for (int v6 = 0; v6 < 28; v6 += 1) {	// L15
      for (int v7 = 0; v7 < 28; v7 += 2) {	// L16
        #pragma HLS pipeline II=1
        float v8 = v0[v5][v6][v7];	// L17
        v1[(v5 + (v2 * 16))][(v6 + (v3 * 28))][(v7 + (v4 * 28))] = v8;	// L18
        float v9 = v0[v5][v6][(v7 + 1)];	// L19
        v1[(v5 + (v2 * 16))][(v6 + (v3 * 28))][((v7 + (v4 * 28)) + 1)] = v9;	// L20
      }
    }
  }
}

void forward_node2(
  float v10[16][28][28],
  float v11[32][112][112],
  int v12,
  int v13,
  int v14
) {	// L26
  #pragma HLS inline
  for (int v15 = 0; v15 < 16; v15 += 1) {	// L27
    for (int v16 = 0; v16 < 28; v16 += 1) {	// L28
      for (int v17 = 0; v17 < 28; v17 += 2) {	// L29
        #pragma HLS pipeline II=1
        float v18 = v10[v15][v16][v17];	// L30
        v11[(v15 + (v12 * 16))][(v16 + (v13 * 28))][(v17 + (v14 * 28))] = v18;	// L31
        float v19 = v10[v15][v16][(v17 + 1)];	// L32
        v11[(v15 + (v12 * 16))][(v16 + (v13 * 28))][((v17 + (v14 * 28)) + 1)] = v19;	// L33
      }
    }
  }
}

void forward_node3(
  float v20[16][28][28],
  float v21[16][16],
  float v22[16][28][28],
  float v23[16][28][28],
  float v24[16][28][28],
  float v25[16][28][28],
  int v26,
  int v27,
  int v28
) {	// L39
  #pragma HLS inline
  for (int v29 = 0; v29 < 16; v29 += 1) {	// L43
    for (int v30 = 0; v30 < 16; v30 += 2) {	// L44
      for (int v31 = 0; v31 < 28; v31 += 4) {	// L45
        for (int v32 = 0; v32 < 28; v32 += 4) {	// L46
          #pragma HLS pipeline II=1
          float v33 = v20[v29][v31][v32];	// L47
          float v34 = v21[v30][v29];	// L48
          float v35 = v23[v30][v31][v32];	// L49
          float v36 = v25[v30][v31][v32];	// L50
          float v37 = (v29 == 0) ? v35 : v36;	// L51
          float v38 = v33 * v34;	// L52
          float v39 = v37 + v38;	// L53
          v25[v30][v31][v32] = v39;	// L54
          float v40 = v22[v30][v31][v32];	// L55
          float v41 = (double)0.000010;	// L56
          float v42 = v41 + (float)1.000000;	// L57
          float v43 = 1.0 / sqrt(v42);	// L58
          float v44 = v39 * v43;	// L59
          float v45 = v44 + (float)0.000000;	// L60
          float v46 = v45 + v40;	// L61
          bool v47 = v46 > (float)0.000000;	// L62
          float v48 = v47 ? v46 : (float)0.000000;	// L63
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L64
            v24[v30][v31][v32] = v48;	// L65
          }
          float v49 = v20[v29][v31][(v32 + 1)];	// L67
          float v50 = v23[v30][v31][(v32 + 1)];	// L68
          float v51 = v25[v30][v31][(v32 + 1)];	// L69
          float v52 = (v29 == 0) ? v50 : v51;	// L70
          float v53 = v49 * v34;	// L71
          float v54 = v52 + v53;	// L72
          v25[v30][v31][(v32 + 1)] = v54;	// L73
          float v55 = v22[v30][v31][(v32 + 1)];	// L74
          float v56 = (double)0.000010;	// L75
          float v57 = v56 + (float)1.000000;	// L76
          float v58 = 1.0 / sqrt(v57);	// L77
          float v59 = v54 * v58;	// L78
          float v60 = v59 + (float)0.000000;	// L79
          float v61 = v60 + v55;	// L80
          bool v62 = v61 > (float)0.000000;	// L81
          float v63 = v62 ? v61 : (float)0.000000;	// L82
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L83
            v24[v30][v31][(v32 + 1)] = v63;	// L84
          }
          float v64 = v20[v29][v31][(v32 + 2)];	// L86
          float v65 = v23[v30][v31][(v32 + 2)];	// L87
          float v66 = v25[v30][v31][(v32 + 2)];	// L88
          float v67 = (v29 == 0) ? v65 : v66;	// L89
          float v68 = v64 * v34;	// L90
          float v69 = v67 + v68;	// L91
          v25[v30][v31][(v32 + 2)] = v69;	// L92
          float v70 = v22[v30][v31][(v32 + 2)];	// L93
          float v71 = (double)0.000010;	// L94
          float v72 = v71 + (float)1.000000;	// L95
          float v73 = 1.0 / sqrt(v72);	// L96
          float v74 = v69 * v73;	// L97
          float v75 = v74 + (float)0.000000;	// L98
          float v76 = v75 + v70;	// L99
          bool v77 = v76 > (float)0.000000;	// L100
          float v78 = v77 ? v76 : (float)0.000000;	// L101
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L102
            v24[v30][v31][(v32 + 2)] = v78;	// L103
          }
          float v79 = v20[v29][v31][(v32 + 3)];	// L105
          float v80 = v23[v30][v31][(v32 + 3)];	// L106
          float v81 = v25[v30][v31][(v32 + 3)];	// L107
          float v82 = (v29 == 0) ? v80 : v81;	// L108
          float v83 = v79 * v34;	// L109
          float v84 = v82 + v83;	// L110
          v25[v30][v31][(v32 + 3)] = v84;	// L111
          float v85 = v22[v30][v31][(v32 + 3)];	// L112
          float v86 = (double)0.000010;	// L113
          float v87 = v86 + (float)1.000000;	// L114
          float v88 = 1.0 / sqrt(v87);	// L115
          float v89 = v84 * v88;	// L116
          float v90 = v89 + (float)0.000000;	// L117
          float v91 = v90 + v85;	// L118
          bool v92 = v91 > (float)0.000000;	// L119
          float v93 = v92 ? v91 : (float)0.000000;	// L120
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L121
            v24[v30][v31][(v32 + 3)] = v93;	// L122
          }
          float v94 = v20[v29][(v31 + 1)][v32];	// L124
          float v95 = v23[v30][(v31 + 1)][v32];	// L125
          float v96 = v25[v30][(v31 + 1)][v32];	// L126
          float v97 = (v29 == 0) ? v95 : v96;	// L127
          float v98 = v94 * v34;	// L128
          float v99 = v97 + v98;	// L129
          v25[v30][(v31 + 1)][v32] = v99;	// L130
          float v100 = v22[v30][(v31 + 1)][v32];	// L131
          float v101 = (double)0.000010;	// L132
          float v102 = v101 + (float)1.000000;	// L133
          float v103 = 1.0 / sqrt(v102);	// L134
          float v104 = v99 * v103;	// L135
          float v105 = v104 + (float)0.000000;	// L136
          float v106 = v105 + v100;	// L137
          bool v107 = v106 > (float)0.000000;	// L138
          float v108 = v107 ? v106 : (float)0.000000;	// L139
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L140
            v24[v30][(v31 + 1)][v32] = v108;	// L141
          }
          float v109 = v20[v29][(v31 + 1)][(v32 + 1)];	// L143
          float v110 = v23[v30][(v31 + 1)][(v32 + 1)];	// L144
          float v111 = v25[v30][(v31 + 1)][(v32 + 1)];	// L145
          float v112 = (v29 == 0) ? v110 : v111;	// L146
          float v113 = v109 * v34;	// L147
          float v114 = v112 + v113;	// L148
          v25[v30][(v31 + 1)][(v32 + 1)] = v114;	// L149
          float v115 = v22[v30][(v31 + 1)][(v32 + 1)];	// L150
          float v116 = (double)0.000010;	// L151
          float v117 = v116 + (float)1.000000;	// L152
          float v118 = 1.0 / sqrt(v117);	// L153
          float v119 = v114 * v118;	// L154
          float v120 = v119 + (float)0.000000;	// L155
          float v121 = v120 + v115;	// L156
          bool v122 = v121 > (float)0.000000;	// L157
          float v123 = v122 ? v121 : (float)0.000000;	// L158
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L159
            v24[v30][(v31 + 1)][(v32 + 1)] = v123;	// L160
          }
          float v124 = v20[v29][(v31 + 1)][(v32 + 2)];	// L162
          float v125 = v23[v30][(v31 + 1)][(v32 + 2)];	// L163
          float v126 = v25[v30][(v31 + 1)][(v32 + 2)];	// L164
          float v127 = (v29 == 0) ? v125 : v126;	// L165
          float v128 = v124 * v34;	// L166
          float v129 = v127 + v128;	// L167
          v25[v30][(v31 + 1)][(v32 + 2)] = v129;	// L168
          float v130 = v22[v30][(v31 + 1)][(v32 + 2)];	// L169
          float v131 = (double)0.000010;	// L170
          float v132 = v131 + (float)1.000000;	// L171
          float v133 = 1.0 / sqrt(v132);	// L172
          float v134 = v129 * v133;	// L173
          float v135 = v134 + (float)0.000000;	// L174
          float v136 = v135 + v130;	// L175
          bool v137 = v136 > (float)0.000000;	// L176
          float v138 = v137 ? v136 : (float)0.000000;	// L177
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L178
            v24[v30][(v31 + 1)][(v32 + 2)] = v138;	// L179
          }
          float v139 = v20[v29][(v31 + 1)][(v32 + 3)];	// L181
          float v140 = v23[v30][(v31 + 1)][(v32 + 3)];	// L182
          float v141 = v25[v30][(v31 + 1)][(v32 + 3)];	// L183
          float v142 = (v29 == 0) ? v140 : v141;	// L184
          float v143 = v139 * v34;	// L185
          float v144 = v142 + v143;	// L186
          v25[v30][(v31 + 1)][(v32 + 3)] = v144;	// L187
          float v145 = v22[v30][(v31 + 1)][(v32 + 3)];	// L188
          float v146 = (double)0.000010;	// L189
          float v147 = v146 + (float)1.000000;	// L190
          float v148 = 1.0 / sqrt(v147);	// L191
          float v149 = v144 * v148;	// L192
          float v150 = v149 + (float)0.000000;	// L193
          float v151 = v150 + v145;	// L194
          bool v152 = v151 > (float)0.000000;	// L195
          float v153 = v152 ? v151 : (float)0.000000;	// L196
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L197
            v24[v30][(v31 + 1)][(v32 + 3)] = v153;	// L198
          }
          float v154 = v20[v29][(v31 + 2)][v32];	// L200
          float v155 = v23[v30][(v31 + 2)][v32];	// L201
          float v156 = v25[v30][(v31 + 2)][v32];	// L202
          float v157 = (v29 == 0) ? v155 : v156;	// L203
          float v158 = v154 * v34;	// L204
          float v159 = v157 + v158;	// L205
          v25[v30][(v31 + 2)][v32] = v159;	// L206
          float v160 = v22[v30][(v31 + 2)][v32];	// L207
          float v161 = (double)0.000010;	// L208
          float v162 = v161 + (float)1.000000;	// L209
          float v163 = 1.0 / sqrt(v162);	// L210
          float v164 = v159 * v163;	// L211
          float v165 = v164 + (float)0.000000;	// L212
          float v166 = v165 + v160;	// L213
          bool v167 = v166 > (float)0.000000;	// L214
          float v168 = v167 ? v166 : (float)0.000000;	// L215
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L216
            v24[v30][(v31 + 2)][v32] = v168;	// L217
          }
          float v169 = v20[v29][(v31 + 2)][(v32 + 1)];	// L219
          float v170 = v23[v30][(v31 + 2)][(v32 + 1)];	// L220
          float v171 = v25[v30][(v31 + 2)][(v32 + 1)];	// L221
          float v172 = (v29 == 0) ? v170 : v171;	// L222
          float v173 = v169 * v34;	// L223
          float v174 = v172 + v173;	// L224
          v25[v30][(v31 + 2)][(v32 + 1)] = v174;	// L225
          float v175 = v22[v30][(v31 + 2)][(v32 + 1)];	// L226
          float v176 = (double)0.000010;	// L227
          float v177 = v176 + (float)1.000000;	// L228
          float v178 = 1.0 / sqrt(v177);	// L229
          float v179 = v174 * v178;	// L230
          float v180 = v179 + (float)0.000000;	// L231
          float v181 = v180 + v175;	// L232
          bool v182 = v181 > (float)0.000000;	// L233
          float v183 = v182 ? v181 : (float)0.000000;	// L234
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L235
            v24[v30][(v31 + 2)][(v32 + 1)] = v183;	// L236
          }
          float v184 = v20[v29][(v31 + 2)][(v32 + 2)];	// L238
          float v185 = v23[v30][(v31 + 2)][(v32 + 2)];	// L239
          float v186 = v25[v30][(v31 + 2)][(v32 + 2)];	// L240
          float v187 = (v29 == 0) ? v185 : v186;	// L241
          float v188 = v184 * v34;	// L242
          float v189 = v187 + v188;	// L243
          v25[v30][(v31 + 2)][(v32 + 2)] = v189;	// L244
          float v190 = v22[v30][(v31 + 2)][(v32 + 2)];	// L245
          float v191 = (double)0.000010;	// L246
          float v192 = v191 + (float)1.000000;	// L247
          float v193 = 1.0 / sqrt(v192);	// L248
          float v194 = v189 * v193;	// L249
          float v195 = v194 + (float)0.000000;	// L250
          float v196 = v195 + v190;	// L251
          bool v197 = v196 > (float)0.000000;	// L252
          float v198 = v197 ? v196 : (float)0.000000;	// L253
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L254
            v24[v30][(v31 + 2)][(v32 + 2)] = v198;	// L255
          }
          float v199 = v20[v29][(v31 + 2)][(v32 + 3)];	// L257
          float v200 = v23[v30][(v31 + 2)][(v32 + 3)];	// L258
          float v201 = v25[v30][(v31 + 2)][(v32 + 3)];	// L259
          float v202 = (v29 == 0) ? v200 : v201;	// L260
          float v203 = v199 * v34;	// L261
          float v204 = v202 + v203;	// L262
          v25[v30][(v31 + 2)][(v32 + 3)] = v204;	// L263
          float v205 = v22[v30][(v31 + 2)][(v32 + 3)];	// L264
          float v206 = (double)0.000010;	// L265
          float v207 = v206 + (float)1.000000;	// L266
          float v208 = 1.0 / sqrt(v207);	// L267
          float v209 = v204 * v208;	// L268
          float v210 = v209 + (float)0.000000;	// L269
          float v211 = v210 + v205;	// L270
          bool v212 = v211 > (float)0.000000;	// L271
          float v213 = v212 ? v211 : (float)0.000000;	// L272
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L273
            v24[v30][(v31 + 2)][(v32 + 3)] = v213;	// L274
          }
          float v214 = v20[v29][(v31 + 3)][v32];	// L276
          float v215 = v23[v30][(v31 + 3)][v32];	// L277
          float v216 = v25[v30][(v31 + 3)][v32];	// L278
          float v217 = (v29 == 0) ? v215 : v216;	// L279
          float v218 = v214 * v34;	// L280
          float v219 = v217 + v218;	// L281
          v25[v30][(v31 + 3)][v32] = v219;	// L282
          float v220 = v22[v30][(v31 + 3)][v32];	// L283
          float v221 = (double)0.000010;	// L284
          float v222 = v221 + (float)1.000000;	// L285
          float v223 = 1.0 / sqrt(v222);	// L286
          float v224 = v219 * v223;	// L287
          float v225 = v224 + (float)0.000000;	// L288
          float v226 = v225 + v220;	// L289
          bool v227 = v226 > (float)0.000000;	// L290
          float v228 = v227 ? v226 : (float)0.000000;	// L291
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L292
            v24[v30][(v31 + 3)][v32] = v228;	// L293
          }
          float v229 = v20[v29][(v31 + 3)][(v32 + 1)];	// L295
          float v230 = v23[v30][(v31 + 3)][(v32 + 1)];	// L296
          float v231 = v25[v30][(v31 + 3)][(v32 + 1)];	// L297
          float v232 = (v29 == 0) ? v230 : v231;	// L298
          float v233 = v229 * v34;	// L299
          float v234 = v232 + v233;	// L300
          v25[v30][(v31 + 3)][(v32 + 1)] = v234;	// L301
          float v235 = v22[v30][(v31 + 3)][(v32 + 1)];	// L302
          float v236 = (double)0.000010;	// L303
          float v237 = v236 + (float)1.000000;	// L304
          float v238 = 1.0 / sqrt(v237);	// L305
          float v239 = v234 * v238;	// L306
          float v240 = v239 + (float)0.000000;	// L307
          float v241 = v240 + v235;	// L308
          bool v242 = v241 > (float)0.000000;	// L309
          float v243 = v242 ? v241 : (float)0.000000;	// L310
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L311
            v24[v30][(v31 + 3)][(v32 + 1)] = v243;	// L312
          }
          float v244 = v20[v29][(v31 + 3)][(v32 + 2)];	// L314
          float v245 = v23[v30][(v31 + 3)][(v32 + 2)];	// L315
          float v246 = v25[v30][(v31 + 3)][(v32 + 2)];	// L316
          float v247 = (v29 == 0) ? v245 : v246;	// L317
          float v248 = v244 * v34;	// L318
          float v249 = v247 + v248;	// L319
          v25[v30][(v31 + 3)][(v32 + 2)] = v249;	// L320
          float v250 = v22[v30][(v31 + 3)][(v32 + 2)];	// L321
          float v251 = (double)0.000010;	// L322
          float v252 = v251 + (float)1.000000;	// L323
          float v253 = 1.0 / sqrt(v252);	// L324
          float v254 = v249 * v253;	// L325
          float v255 = v254 + (float)0.000000;	// L326
          float v256 = v255 + v250;	// L327
          bool v257 = v256 > (float)0.000000;	// L328
          float v258 = v257 ? v256 : (float)0.000000;	// L329
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L330
            v24[v30][(v31 + 3)][(v32 + 2)] = v258;	// L331
          }
          float v259 = v20[v29][(v31 + 3)][(v32 + 3)];	// L333
          float v260 = v23[v30][(v31 + 3)][(v32 + 3)];	// L334
          float v261 = v25[v30][(v31 + 3)][(v32 + 3)];	// L335
          float v262 = (v29 == 0) ? v260 : v261;	// L336
          float v263 = v259 * v34;	// L337
          float v264 = v262 + v263;	// L338
          v25[v30][(v31 + 3)][(v32 + 3)] = v264;	// L339
          float v265 = v22[v30][(v31 + 3)][(v32 + 3)];	// L340
          float v266 = (double)0.000010;	// L341
          float v267 = v266 + (float)1.000000;	// L342
          float v268 = 1.0 / sqrt(v267);	// L343
          float v269 = v264 * v268;	// L344
          float v270 = v269 + (float)0.000000;	// L345
          float v271 = v270 + v265;	// L346
          bool v272 = v271 > (float)0.000000;	// L347
          float v273 = v272 ? v271 : (float)0.000000;	// L348
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L349
            v24[v30][(v31 + 3)][(v32 + 3)] = v273;	// L350
          }
          float v274 = v21[(v30 + 1)][v29];	// L352
          float v275 = v23[(v30 + 1)][v31][v32];	// L353
          float v276 = v25[(v30 + 1)][v31][v32];	// L354
          float v277 = (v29 == 0) ? v275 : v276;	// L355
          float v278 = v33 * v274;	// L356
          float v279 = v277 + v278;	// L357
          v25[(v30 + 1)][v31][v32] = v279;	// L358
          float v280 = v22[(v30 + 1)][v31][v32];	// L359
          float v281 = (double)0.000010;	// L360
          float v282 = v281 + (float)1.000000;	// L361
          float v283 = 1.0 / sqrt(v282);	// L362
          float v284 = v279 * v283;	// L363
          float v285 = v284 + (float)0.000000;	// L364
          float v286 = v285 + v280;	// L365
          bool v287 = v286 > (float)0.000000;	// L366
          float v288 = v287 ? v286 : (float)0.000000;	// L367
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L368
            v24[(v30 + 1)][v31][v32] = v288;	// L369
          }
          float v289 = v23[(v30 + 1)][v31][(v32 + 1)];	// L371
          float v290 = v25[(v30 + 1)][v31][(v32 + 1)];	// L372
          float v291 = (v29 == 0) ? v289 : v290;	// L373
          float v292 = v49 * v274;	// L374
          float v293 = v291 + v292;	// L375
          v25[(v30 + 1)][v31][(v32 + 1)] = v293;	// L376
          float v294 = v22[(v30 + 1)][v31][(v32 + 1)];	// L377
          float v295 = (double)0.000010;	// L378
          float v296 = v295 + (float)1.000000;	// L379
          float v297 = 1.0 / sqrt(v296);	// L380
          float v298 = v293 * v297;	// L381
          float v299 = v298 + (float)0.000000;	// L382
          float v300 = v299 + v294;	// L383
          bool v301 = v300 > (float)0.000000;	// L384
          float v302 = v301 ? v300 : (float)0.000000;	// L385
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L386
            v24[(v30 + 1)][v31][(v32 + 1)] = v302;	// L387
          }
          float v303 = v23[(v30 + 1)][v31][(v32 + 2)];	// L389
          float v304 = v25[(v30 + 1)][v31][(v32 + 2)];	// L390
          float v305 = (v29 == 0) ? v303 : v304;	// L391
          float v306 = v64 * v274;	// L392
          float v307 = v305 + v306;	// L393
          v25[(v30 + 1)][v31][(v32 + 2)] = v307;	// L394
          float v308 = v22[(v30 + 1)][v31][(v32 + 2)];	// L395
          float v309 = (double)0.000010;	// L396
          float v310 = v309 + (float)1.000000;	// L397
          float v311 = 1.0 / sqrt(v310);	// L398
          float v312 = v307 * v311;	// L399
          float v313 = v312 + (float)0.000000;	// L400
          float v314 = v313 + v308;	// L401
          bool v315 = v314 > (float)0.000000;	// L402
          float v316 = v315 ? v314 : (float)0.000000;	// L403
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L404
            v24[(v30 + 1)][v31][(v32 + 2)] = v316;	// L405
          }
          float v317 = v23[(v30 + 1)][v31][(v32 + 3)];	// L407
          float v318 = v25[(v30 + 1)][v31][(v32 + 3)];	// L408
          float v319 = (v29 == 0) ? v317 : v318;	// L409
          float v320 = v79 * v274;	// L410
          float v321 = v319 + v320;	// L411
          v25[(v30 + 1)][v31][(v32 + 3)] = v321;	// L412
          float v322 = v22[(v30 + 1)][v31][(v32 + 3)];	// L413
          float v323 = (double)0.000010;	// L414
          float v324 = v323 + (float)1.000000;	// L415
          float v325 = 1.0 / sqrt(v324);	// L416
          float v326 = v321 * v325;	// L417
          float v327 = v326 + (float)0.000000;	// L418
          float v328 = v327 + v322;	// L419
          bool v329 = v328 > (float)0.000000;	// L420
          float v330 = v329 ? v328 : (float)0.000000;	// L421
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L422
            v24[(v30 + 1)][v31][(v32 + 3)] = v330;	// L423
          }
          float v331 = v23[(v30 + 1)][(v31 + 1)][v32];	// L425
          float v332 = v25[(v30 + 1)][(v31 + 1)][v32];	// L426
          float v333 = (v29 == 0) ? v331 : v332;	// L427
          float v334 = v94 * v274;	// L428
          float v335 = v333 + v334;	// L429
          v25[(v30 + 1)][(v31 + 1)][v32] = v335;	// L430
          float v336 = v22[(v30 + 1)][(v31 + 1)][v32];	// L431
          float v337 = (double)0.000010;	// L432
          float v338 = v337 + (float)1.000000;	// L433
          float v339 = 1.0 / sqrt(v338);	// L434
          float v340 = v335 * v339;	// L435
          float v341 = v340 + (float)0.000000;	// L436
          float v342 = v341 + v336;	// L437
          bool v343 = v342 > (float)0.000000;	// L438
          float v344 = v343 ? v342 : (float)0.000000;	// L439
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L440
            v24[(v30 + 1)][(v31 + 1)][v32] = v344;	// L441
          }
          float v345 = v23[(v30 + 1)][(v31 + 1)][(v32 + 1)];	// L443
          float v346 = v25[(v30 + 1)][(v31 + 1)][(v32 + 1)];	// L444
          float v347 = (v29 == 0) ? v345 : v346;	// L445
          float v348 = v109 * v274;	// L446
          float v349 = v347 + v348;	// L447
          v25[(v30 + 1)][(v31 + 1)][(v32 + 1)] = v349;	// L448
          float v350 = v22[(v30 + 1)][(v31 + 1)][(v32 + 1)];	// L449
          float v351 = (double)0.000010;	// L450
          float v352 = v351 + (float)1.000000;	// L451
          float v353 = 1.0 / sqrt(v352);	// L452
          float v354 = v349 * v353;	// L453
          float v355 = v354 + (float)0.000000;	// L454
          float v356 = v355 + v350;	// L455
          bool v357 = v356 > (float)0.000000;	// L456
          float v358 = v357 ? v356 : (float)0.000000;	// L457
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L458
            v24[(v30 + 1)][(v31 + 1)][(v32 + 1)] = v358;	// L459
          }
          float v359 = v23[(v30 + 1)][(v31 + 1)][(v32 + 2)];	// L461
          float v360 = v25[(v30 + 1)][(v31 + 1)][(v32 + 2)];	// L462
          float v361 = (v29 == 0) ? v359 : v360;	// L463
          float v362 = v124 * v274;	// L464
          float v363 = v361 + v362;	// L465
          v25[(v30 + 1)][(v31 + 1)][(v32 + 2)] = v363;	// L466
          float v364 = v22[(v30 + 1)][(v31 + 1)][(v32 + 2)];	// L467
          float v365 = (double)0.000010;	// L468
          float v366 = v365 + (float)1.000000;	// L469
          float v367 = 1.0 / sqrt(v366);	// L470
          float v368 = v363 * v367;	// L471
          float v369 = v368 + (float)0.000000;	// L472
          float v370 = v369 + v364;	// L473
          bool v371 = v370 > (float)0.000000;	// L474
          float v372 = v371 ? v370 : (float)0.000000;	// L475
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L476
            v24[(v30 + 1)][(v31 + 1)][(v32 + 2)] = v372;	// L477
          }
          float v373 = v23[(v30 + 1)][(v31 + 1)][(v32 + 3)];	// L479
          float v374 = v25[(v30 + 1)][(v31 + 1)][(v32 + 3)];	// L480
          float v375 = (v29 == 0) ? v373 : v374;	// L481
          float v376 = v139 * v274;	// L482
          float v377 = v375 + v376;	// L483
          v25[(v30 + 1)][(v31 + 1)][(v32 + 3)] = v377;	// L484
          float v378 = v22[(v30 + 1)][(v31 + 1)][(v32 + 3)];	// L485
          float v379 = (double)0.000010;	// L486
          float v380 = v379 + (float)1.000000;	// L487
          float v381 = 1.0 / sqrt(v380);	// L488
          float v382 = v377 * v381;	// L489
          float v383 = v382 + (float)0.000000;	// L490
          float v384 = v383 + v378;	// L491
          bool v385 = v384 > (float)0.000000;	// L492
          float v386 = v385 ? v384 : (float)0.000000;	// L493
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L494
            v24[(v30 + 1)][(v31 + 1)][(v32 + 3)] = v386;	// L495
          }
          float v387 = v23[(v30 + 1)][(v31 + 2)][v32];	// L497
          float v388 = v25[(v30 + 1)][(v31 + 2)][v32];	// L498
          float v389 = (v29 == 0) ? v387 : v388;	// L499
          float v390 = v154 * v274;	// L500
          float v391 = v389 + v390;	// L501
          v25[(v30 + 1)][(v31 + 2)][v32] = v391;	// L502
          float v392 = v22[(v30 + 1)][(v31 + 2)][v32];	// L503
          float v393 = (double)0.000010;	// L504
          float v394 = v393 + (float)1.000000;	// L505
          float v395 = 1.0 / sqrt(v394);	// L506
          float v396 = v391 * v395;	// L507
          float v397 = v396 + (float)0.000000;	// L508
          float v398 = v397 + v392;	// L509
          bool v399 = v398 > (float)0.000000;	// L510
          float v400 = v399 ? v398 : (float)0.000000;	// L511
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L512
            v24[(v30 + 1)][(v31 + 2)][v32] = v400;	// L513
          }
          float v401 = v23[(v30 + 1)][(v31 + 2)][(v32 + 1)];	// L515
          float v402 = v25[(v30 + 1)][(v31 + 2)][(v32 + 1)];	// L516
          float v403 = (v29 == 0) ? v401 : v402;	// L517
          float v404 = v169 * v274;	// L518
          float v405 = v403 + v404;	// L519
          v25[(v30 + 1)][(v31 + 2)][(v32 + 1)] = v405;	// L520
          float v406 = v22[(v30 + 1)][(v31 + 2)][(v32 + 1)];	// L521
          float v407 = (double)0.000010;	// L522
          float v408 = v407 + (float)1.000000;	// L523
          float v409 = 1.0 / sqrt(v408);	// L524
          float v410 = v405 * v409;	// L525
          float v411 = v410 + (float)0.000000;	// L526
          float v412 = v411 + v406;	// L527
          bool v413 = v412 > (float)0.000000;	// L528
          float v414 = v413 ? v412 : (float)0.000000;	// L529
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L530
            v24[(v30 + 1)][(v31 + 2)][(v32 + 1)] = v414;	// L531
          }
          float v415 = v23[(v30 + 1)][(v31 + 2)][(v32 + 2)];	// L533
          float v416 = v25[(v30 + 1)][(v31 + 2)][(v32 + 2)];	// L534
          float v417 = (v29 == 0) ? v415 : v416;	// L535
          float v418 = v184 * v274;	// L536
          float v419 = v417 + v418;	// L537
          v25[(v30 + 1)][(v31 + 2)][(v32 + 2)] = v419;	// L538
          float v420 = v22[(v30 + 1)][(v31 + 2)][(v32 + 2)];	// L539
          float v421 = (double)0.000010;	// L540
          float v422 = v421 + (float)1.000000;	// L541
          float v423 = 1.0 / sqrt(v422);	// L542
          float v424 = v419 * v423;	// L543
          float v425 = v424 + (float)0.000000;	// L544
          float v426 = v425 + v420;	// L545
          bool v427 = v426 > (float)0.000000;	// L546
          float v428 = v427 ? v426 : (float)0.000000;	// L547
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L548
            v24[(v30 + 1)][(v31 + 2)][(v32 + 2)] = v428;	// L549
          }
          float v429 = v23[(v30 + 1)][(v31 + 2)][(v32 + 3)];	// L551
          float v430 = v25[(v30 + 1)][(v31 + 2)][(v32 + 3)];	// L552
          float v431 = (v29 == 0) ? v429 : v430;	// L553
          float v432 = v199 * v274;	// L554
          float v433 = v431 + v432;	// L555
          v25[(v30 + 1)][(v31 + 2)][(v32 + 3)] = v433;	// L556
          float v434 = v22[(v30 + 1)][(v31 + 2)][(v32 + 3)];	// L557
          float v435 = (double)0.000010;	// L558
          float v436 = v435 + (float)1.000000;	// L559
          float v437 = 1.0 / sqrt(v436);	// L560
          float v438 = v433 * v437;	// L561
          float v439 = v438 + (float)0.000000;	// L562
          float v440 = v439 + v434;	// L563
          bool v441 = v440 > (float)0.000000;	// L564
          float v442 = v441 ? v440 : (float)0.000000;	// L565
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L566
            v24[(v30 + 1)][(v31 + 2)][(v32 + 3)] = v442;	// L567
          }
          float v443 = v23[(v30 + 1)][(v31 + 3)][v32];	// L569
          float v444 = v25[(v30 + 1)][(v31 + 3)][v32];	// L570
          float v445 = (v29 == 0) ? v443 : v444;	// L571
          float v446 = v214 * v274;	// L572
          float v447 = v445 + v446;	// L573
          v25[(v30 + 1)][(v31 + 3)][v32] = v447;	// L574
          float v448 = v22[(v30 + 1)][(v31 + 3)][v32];	// L575
          float v449 = (double)0.000010;	// L576
          float v450 = v449 + (float)1.000000;	// L577
          float v451 = 1.0 / sqrt(v450);	// L578
          float v452 = v447 * v451;	// L579
          float v453 = v452 + (float)0.000000;	// L580
          float v454 = v453 + v448;	// L581
          bool v455 = v454 > (float)0.000000;	// L582
          float v456 = v455 ? v454 : (float)0.000000;	// L583
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L584
            v24[(v30 + 1)][(v31 + 3)][v32] = v456;	// L585
          }
          float v457 = v23[(v30 + 1)][(v31 + 3)][(v32 + 1)];	// L587
          float v458 = v25[(v30 + 1)][(v31 + 3)][(v32 + 1)];	// L588
          float v459 = (v29 == 0) ? v457 : v458;	// L589
          float v460 = v229 * v274;	// L590
          float v461 = v459 + v460;	// L591
          v25[(v30 + 1)][(v31 + 3)][(v32 + 1)] = v461;	// L592
          float v462 = v22[(v30 + 1)][(v31 + 3)][(v32 + 1)];	// L593
          float v463 = (double)0.000010;	// L594
          float v464 = v463 + (float)1.000000;	// L595
          float v465 = 1.0 / sqrt(v464);	// L596
          float v466 = v461 * v465;	// L597
          float v467 = v466 + (float)0.000000;	// L598
          float v468 = v467 + v462;	// L599
          bool v469 = v468 > (float)0.000000;	// L600
          float v470 = v469 ? v468 : (float)0.000000;	// L601
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L602
            v24[(v30 + 1)][(v31 + 3)][(v32 + 1)] = v470;	// L603
          }
          float v471 = v23[(v30 + 1)][(v31 + 3)][(v32 + 2)];	// L605
          float v472 = v25[(v30 + 1)][(v31 + 3)][(v32 + 2)];	// L606
          float v473 = (v29 == 0) ? v471 : v472;	// L607
          float v474 = v244 * v274;	// L608
          float v475 = v473 + v474;	// L609
          v25[(v30 + 1)][(v31 + 3)][(v32 + 2)] = v475;	// L610
          float v476 = v22[(v30 + 1)][(v31 + 3)][(v32 + 2)];	// L611
          float v477 = (double)0.000010;	// L612
          float v478 = v477 + (float)1.000000;	// L613
          float v479 = 1.0 / sqrt(v478);	// L614
          float v480 = v475 * v479;	// L615
          float v481 = v480 + (float)0.000000;	// L616
          float v482 = v481 + v476;	// L617
          bool v483 = v482 > (float)0.000000;	// L618
          float v484 = v483 ? v482 : (float)0.000000;	// L619
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L620
            v24[(v30 + 1)][(v31 + 3)][(v32 + 2)] = v484;	// L621
          }
          float v485 = v23[(v30 + 1)][(v31 + 3)][(v32 + 3)];	// L623
          float v486 = v25[(v30 + 1)][(v31 + 3)][(v32 + 3)];	// L624
          float v487 = (v29 == 0) ? v485 : v486;	// L625
          float v488 = v259 * v274;	// L626
          float v489 = v487 + v488;	// L627
          v25[(v30 + 1)][(v31 + 3)][(v32 + 3)] = v489;	// L628
          float v490 = v22[(v30 + 1)][(v31 + 3)][(v32 + 3)];	// L629
          float v491 = (double)0.000010;	// L630
          float v492 = v491 + (float)1.000000;	// L631
          float v493 = 1.0 / sqrt(v492);	// L632
          float v494 = v489 * v493;	// L633
          float v495 = v494 + (float)0.000000;	// L634
          float v496 = v495 + v490;	// L635
          bool v497 = v496 > (float)0.000000;	// L636
          float v498 = v497 ? v496 : (float)0.000000;	// L637
          if ((((-v29) + (v27 * -16)) + 31) == 0 && ((-v28) + 2) == 0 && ((-v26) + 2) == 0) {	// L638
            v24[(v30 + 1)][(v31 + 3)][(v32 + 3)] = v498;	// L639
          }
        }
      }
    }
  }
}

void forward_node4(
  float v499[32][112][112],
  float v500[16][28][28],
  int v501,
  int v502,
  int v503
) {	// L647
  #pragma HLS inline
  for (int v504 = 0; v504 < 16; v504 += 1) {	// L648
    for (int v505 = 0; v505 < 28; v505 += 1) {	// L649
      for (int v506 = 0; v506 < 28; v506 += 2) {	// L650
        #pragma HLS pipeline II=1
        float v507 = v499[(v504 + (v501 * 16))][(v505 + (v502 * 28))][(v506 + (v503 * 28))];	// L651
        v500[v504][v505][v506] = v507;	// L652
        float v508 = v499[(v504 + (v501 * 16))][(v505 + (v502 * 28))][((v506 + (v503 * 28)) + 1)];	// L653
        v500[v504][v505][(v506 + 1)] = v508;	// L654
      }
    }
  }
}

void forward_node5(
  float v509[32][112][112],
  float v510[16][28][28],
  int v511,
  int v512,
  int v513
) {	// L660
  #pragma HLS inline
  for (int v514 = 0; v514 < 16; v514 += 1) {	// L661
    for (int v515 = 0; v515 < 28; v515 += 1) {	// L662
      for (int v516 = 0; v516 < 28; v516 += 2) {	// L663
        #pragma HLS pipeline II=1
        float v517 = v509[(v514 + (v511 * 16))][(v515 + (v512 * 28))][(v516 + (v513 * 28))];	// L664
        v510[v514][v515][v516] = v517;	// L665
        float v518 = v509[(v514 + (v511 * 16))][(v515 + (v512 * 28))][((v516 + (v513 * 28)) + 1)];	// L666
        v510[v514][v515][(v516 + 1)] = v518;	// L667
      }
    }
  }
}

void forward_node6(
  float v519[32][32][3][3],
  float v520[16][16],
  int v521,
  int v522,
  int v523,
  int v524
) {	// L673
  #pragma HLS inline
  for (int v525 = 0; v525 < 16; v525 += 1) {	// L674
    for (int v526 = 0; v526 < 16; v526 += 1) {	// L675
      #pragma HLS pipeline II=1
      float v527 = v519[(v525 + (v523 * 16))][(v526 + (v524 * 16))][v521][v522];	// L676
      v520[v525][v526] = v527;	// L677
    }
  }
}

void forward_node7(
  float v528[32][112][112],
  float v529[16][28][28],
  int v530,
  int v531,
  int v532,
  int v533,
  int v534
) {	// L682
  #pragma HLS inline
  for (int v535 = 0; v535 < 16; v535 += 1) {	// L683
    for (int v536 = 0; v536 < 28; v536 += 1) {	// L684
      for (int v537 = 0; v537 < 28; v537 += 2) {	// L685
        #pragma HLS pipeline II=1
        float v538 = v528[(v535 + (v530 * 16))][(((v536 + v531) + (v532 * 28)) - 1)][(((v537 + v533) + (v534 * 28)) - 1)];	// L686
        v529[v535][v536][v537] = v538;	// L687
        float v539 = v528[(v535 + (v530 * 16))][(((v536 + v531) + (v532 * 28)) - 1)][((v537 + v533) + (v534 * 28))];	// L688
        v529[v535][v536][(v537 + 1)] = v539;	// L689
      }
    }
  }
}

void forward_node0(
  float v540[32][112][112],
  float v541[32][112][112],
  float v542[32][32][3][3],
  float v543[32][112][112],
  float v544[32][112][112],
  float v545[32][112][112]
) {	// L695
  for (int v546 = 0; v546 < 576; v546 += 1) {	// L696
    #pragma HLS dataflow
    int v547 = (v546 % 4);	// L697
    int v548 = ((v546 / 4) % 4);	// L698
    int v549 = (((v546 / 4) / 4) % 2);	// L699
    int v550 = ((((v546 / 4) / 4) / 2) % 3);	// L700
    int v551 = (((((v546 / 4) / 4) / 2) / 3) % 3);	// L701
    int v552 = (((((v546 / 4) / 4) / 2) / 3) / 3);	// L702
    float v553[16][28][28];	// L703
    #pragma HLS array_partition variable=v553 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v553 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v553 cyclic factor=4 dim=3
    #pragma HLS resource variable=v553 core=ram_2p_lutram

    float v554[16][28][28];	// L704
    #pragma HLS array_partition variable=v554 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v554 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v554 cyclic factor=4 dim=3
    #pragma HLS resource variable=v554 core=ram_2p_lutram

    float v555[16][28][28];	// L705
    #pragma HLS array_partition variable=v555 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v555 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v555 cyclic factor=4 dim=3
    #pragma HLS resource variable=v555 core=ram_2p_lutram

    float v556[16][16];	// L706
    #pragma HLS array_partition variable=v556 cyclic factor=2 dim=1
    #pragma HLS resource variable=v556 core=ram_2p_lutram

    float v557[16][28][28];	// L707
    #pragma HLS array_partition variable=v557 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v557 cyclic factor=4 dim=3
    #pragma HLS resource variable=v557 core=ram_2p_lutram

    forward_node7(v540, v557, v552, v551, v548, v550, v547);	// L708
    forward_node6(v542, v556, v551, v550, v549, v552);	// L709
    forward_node5(v543, v555, v549, v548, v547);	// L710
    forward_node4(v541, v554, v549, v548, v547);	// L711
    float v558[16][28][28];	// L712
    #pragma HLS array_partition variable=v558 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v558 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v558 cyclic factor=4 dim=3
    #pragma HLS resource variable=v558 core=ram_2p_lutram

    forward_node3(v557, v556, v554, v555, v553, v558, v550, v552, v551);	// L713
    forward_node2(v558, v544, v549, v548, v547);	// L714
    forward_node1(v553, v545, v549, v548, v547);	// L715
  }
}

void forward_node9(
  float v559[16][28][28],
  float v560[32][112][112],
  int v561,
  int v562,
  int v563
) {	// L719
  #pragma HLS inline
  for (int v564 = 0; v564 < 16; v564 += 1) {	// L720
    for (int v565 = 0; v565 < 28; v565 += 1) {	// L721
      for (int v566 = 0; v566 < 28; v566 += 2) {	// L722
        #pragma HLS pipeline II=1
        float v567 = v559[v564][v565][v566];	// L723
        v560[(v564 + (v561 * 16))][(v565 + (v562 * 28))][(v566 + (v563 * 28))] = v567;	// L724
        float v568 = v559[v564][v565][(v566 + 1)];	// L725
        v560[(v564 + (v561 * 16))][(v565 + (v562 * 28))][((v566 + (v563 * 28)) + 1)] = v568;	// L726
      }
    }
  }
}

void forward_node10(
  float v569[16][28][28],
  float v570[16][28][28],
  float v571[16][16],
  float v572[16][28][28],
  float v573[16][28][28],
  int v574,
  int v575,
  int v576
) {	// L732
  #pragma HLS inline
  for (int v577 = 0; v577 < 16; v577 += 1) {	// L736
    for (int v578 = 0; v578 < 16; v578 += 2) {	// L737
      for (int v579 = 0; v579 < 28; v579 += 4) {	// L738
        for (int v580 = 0; v580 < 28; v580 += 4) {	// L739
          #pragma HLS pipeline II=1
          float v581 = v569[v578][v579][v580];	// L740
          float v582 = v572[v578][v579][v580];	// L741
          float v583 = v573[v578][v579][v580];	// L742
          float v584 = (v577 == 0) ? v582 : v583;	// L743
          float v585 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v581 : v584;	// L744
          float v586 = v570[v577][v579][v580];	// L745
          float v587 = v571[v578][v577];	// L746
          float v588 = v586 * v587;	// L747
          float v589 = v585 + v588;	// L748
          float v590 = (double)0.000010;	// L749
          float v591 = v590 + (float)1.000000;	// L750
          float v592 = 1.0 / sqrt(v591);	// L751
          float v593 = v589 * v592;	// L752
          float v594 = v593 + (float)0.000000;	// L753
          bool v595 = v594 > (float)0.000000;	// L754
          float v596 = v595 ? v594 : (float)0.000000;	// L755
          float v597 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v596 : v589;	// L756
          v573[v578][v579][v580] = v597;	// L757
          float v598 = v569[v578][v579][(v580 + 1)];	// L758
          float v599 = v572[v578][v579][(v580 + 1)];	// L759
          float v600 = v573[v578][v579][(v580 + 1)];	// L760
          float v601 = (v577 == 0) ? v599 : v600;	// L761
          float v602 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v598 : v601;	// L762
          float v603 = v570[v577][v579][(v580 + 1)];	// L763
          float v604 = v603 * v587;	// L764
          float v605 = v602 + v604;	// L765
          float v606 = (double)0.000010;	// L766
          float v607 = v606 + (float)1.000000;	// L767
          float v608 = 1.0 / sqrt(v607);	// L768
          float v609 = v605 * v608;	// L769
          float v610 = v609 + (float)0.000000;	// L770
          bool v611 = v610 > (float)0.000000;	// L771
          float v612 = v611 ? v610 : (float)0.000000;	// L772
          float v613 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v612 : v605;	// L773
          v573[v578][v579][(v580 + 1)] = v613;	// L774
          float v614 = v569[v578][v579][(v580 + 2)];	// L775
          float v615 = v572[v578][v579][(v580 + 2)];	// L776
          float v616 = v573[v578][v579][(v580 + 2)];	// L777
          float v617 = (v577 == 0) ? v615 : v616;	// L778
          float v618 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v614 : v617;	// L779
          float v619 = v570[v577][v579][(v580 + 2)];	// L780
          float v620 = v619 * v587;	// L781
          float v621 = v618 + v620;	// L782
          float v622 = (double)0.000010;	// L783
          float v623 = v622 + (float)1.000000;	// L784
          float v624 = 1.0 / sqrt(v623);	// L785
          float v625 = v621 * v624;	// L786
          float v626 = v625 + (float)0.000000;	// L787
          bool v627 = v626 > (float)0.000000;	// L788
          float v628 = v627 ? v626 : (float)0.000000;	// L789
          float v629 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v628 : v621;	// L790
          v573[v578][v579][(v580 + 2)] = v629;	// L791
          float v630 = v569[v578][v579][(v580 + 3)];	// L792
          float v631 = v572[v578][v579][(v580 + 3)];	// L793
          float v632 = v573[v578][v579][(v580 + 3)];	// L794
          float v633 = (v577 == 0) ? v631 : v632;	// L795
          float v634 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v630 : v633;	// L796
          float v635 = v570[v577][v579][(v580 + 3)];	// L797
          float v636 = v635 * v587;	// L798
          float v637 = v634 + v636;	// L799
          float v638 = (double)0.000010;	// L800
          float v639 = v638 + (float)1.000000;	// L801
          float v640 = 1.0 / sqrt(v639);	// L802
          float v641 = v637 * v640;	// L803
          float v642 = v641 + (float)0.000000;	// L804
          bool v643 = v642 > (float)0.000000;	// L805
          float v644 = v643 ? v642 : (float)0.000000;	// L806
          float v645 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v644 : v637;	// L807
          v573[v578][v579][(v580 + 3)] = v645;	// L808
          float v646 = v569[v578][(v579 + 1)][v580];	// L809
          float v647 = v572[v578][(v579 + 1)][v580];	// L810
          float v648 = v573[v578][(v579 + 1)][v580];	// L811
          float v649 = (v577 == 0) ? v647 : v648;	// L812
          float v650 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v646 : v649;	// L813
          float v651 = v570[v577][(v579 + 1)][v580];	// L814
          float v652 = v651 * v587;	// L815
          float v653 = v650 + v652;	// L816
          float v654 = (double)0.000010;	// L817
          float v655 = v654 + (float)1.000000;	// L818
          float v656 = 1.0 / sqrt(v655);	// L819
          float v657 = v653 * v656;	// L820
          float v658 = v657 + (float)0.000000;	// L821
          bool v659 = v658 > (float)0.000000;	// L822
          float v660 = v659 ? v658 : (float)0.000000;	// L823
          float v661 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v660 : v653;	// L824
          v573[v578][(v579 + 1)][v580] = v661;	// L825
          float v662 = v569[v578][(v579 + 1)][(v580 + 1)];	// L826
          float v663 = v572[v578][(v579 + 1)][(v580 + 1)];	// L827
          float v664 = v573[v578][(v579 + 1)][(v580 + 1)];	// L828
          float v665 = (v577 == 0) ? v663 : v664;	// L829
          float v666 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v662 : v665;	// L830
          float v667 = v570[v577][(v579 + 1)][(v580 + 1)];	// L831
          float v668 = v667 * v587;	// L832
          float v669 = v666 + v668;	// L833
          float v670 = (double)0.000010;	// L834
          float v671 = v670 + (float)1.000000;	// L835
          float v672 = 1.0 / sqrt(v671);	// L836
          float v673 = v669 * v672;	// L837
          float v674 = v673 + (float)0.000000;	// L838
          bool v675 = v674 > (float)0.000000;	// L839
          float v676 = v675 ? v674 : (float)0.000000;	// L840
          float v677 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v676 : v669;	// L841
          v573[v578][(v579 + 1)][(v580 + 1)] = v677;	// L842
          float v678 = v569[v578][(v579 + 1)][(v580 + 2)];	// L843
          float v679 = v572[v578][(v579 + 1)][(v580 + 2)];	// L844
          float v680 = v573[v578][(v579 + 1)][(v580 + 2)];	// L845
          float v681 = (v577 == 0) ? v679 : v680;	// L846
          float v682 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v678 : v681;	// L847
          float v683 = v570[v577][(v579 + 1)][(v580 + 2)];	// L848
          float v684 = v683 * v587;	// L849
          float v685 = v682 + v684;	// L850
          float v686 = (double)0.000010;	// L851
          float v687 = v686 + (float)1.000000;	// L852
          float v688 = 1.0 / sqrt(v687);	// L853
          float v689 = v685 * v688;	// L854
          float v690 = v689 + (float)0.000000;	// L855
          bool v691 = v690 > (float)0.000000;	// L856
          float v692 = v691 ? v690 : (float)0.000000;	// L857
          float v693 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v692 : v685;	// L858
          v573[v578][(v579 + 1)][(v580 + 2)] = v693;	// L859
          float v694 = v569[v578][(v579 + 1)][(v580 + 3)];	// L860
          float v695 = v572[v578][(v579 + 1)][(v580 + 3)];	// L861
          float v696 = v573[v578][(v579 + 1)][(v580 + 3)];	// L862
          float v697 = (v577 == 0) ? v695 : v696;	// L863
          float v698 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v694 : v697;	// L864
          float v699 = v570[v577][(v579 + 1)][(v580 + 3)];	// L865
          float v700 = v699 * v587;	// L866
          float v701 = v698 + v700;	// L867
          float v702 = (double)0.000010;	// L868
          float v703 = v702 + (float)1.000000;	// L869
          float v704 = 1.0 / sqrt(v703);	// L870
          float v705 = v701 * v704;	// L871
          float v706 = v705 + (float)0.000000;	// L872
          bool v707 = v706 > (float)0.000000;	// L873
          float v708 = v707 ? v706 : (float)0.000000;	// L874
          float v709 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v708 : v701;	// L875
          v573[v578][(v579 + 1)][(v580 + 3)] = v709;	// L876
          float v710 = v569[v578][(v579 + 2)][v580];	// L877
          float v711 = v572[v578][(v579 + 2)][v580];	// L878
          float v712 = v573[v578][(v579 + 2)][v580];	// L879
          float v713 = (v577 == 0) ? v711 : v712;	// L880
          float v714 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v710 : v713;	// L881
          float v715 = v570[v577][(v579 + 2)][v580];	// L882
          float v716 = v715 * v587;	// L883
          float v717 = v714 + v716;	// L884
          float v718 = (double)0.000010;	// L885
          float v719 = v718 + (float)1.000000;	// L886
          float v720 = 1.0 / sqrt(v719);	// L887
          float v721 = v717 * v720;	// L888
          float v722 = v721 + (float)0.000000;	// L889
          bool v723 = v722 > (float)0.000000;	// L890
          float v724 = v723 ? v722 : (float)0.000000;	// L891
          float v725 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v724 : v717;	// L892
          v573[v578][(v579 + 2)][v580] = v725;	// L893
          float v726 = v569[v578][(v579 + 2)][(v580 + 1)];	// L894
          float v727 = v572[v578][(v579 + 2)][(v580 + 1)];	// L895
          float v728 = v573[v578][(v579 + 2)][(v580 + 1)];	// L896
          float v729 = (v577 == 0) ? v727 : v728;	// L897
          float v730 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v726 : v729;	// L898
          float v731 = v570[v577][(v579 + 2)][(v580 + 1)];	// L899
          float v732 = v731 * v587;	// L900
          float v733 = v730 + v732;	// L901
          float v734 = (double)0.000010;	// L902
          float v735 = v734 + (float)1.000000;	// L903
          float v736 = 1.0 / sqrt(v735);	// L904
          float v737 = v733 * v736;	// L905
          float v738 = v737 + (float)0.000000;	// L906
          bool v739 = v738 > (float)0.000000;	// L907
          float v740 = v739 ? v738 : (float)0.000000;	// L908
          float v741 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v740 : v733;	// L909
          v573[v578][(v579 + 2)][(v580 + 1)] = v741;	// L910
          float v742 = v569[v578][(v579 + 2)][(v580 + 2)];	// L911
          float v743 = v572[v578][(v579 + 2)][(v580 + 2)];	// L912
          float v744 = v573[v578][(v579 + 2)][(v580 + 2)];	// L913
          float v745 = (v577 == 0) ? v743 : v744;	// L914
          float v746 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v742 : v745;	// L915
          float v747 = v570[v577][(v579 + 2)][(v580 + 2)];	// L916
          float v748 = v747 * v587;	// L917
          float v749 = v746 + v748;	// L918
          float v750 = (double)0.000010;	// L919
          float v751 = v750 + (float)1.000000;	// L920
          float v752 = 1.0 / sqrt(v751);	// L921
          float v753 = v749 * v752;	// L922
          float v754 = v753 + (float)0.000000;	// L923
          bool v755 = v754 > (float)0.000000;	// L924
          float v756 = v755 ? v754 : (float)0.000000;	// L925
          float v757 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v756 : v749;	// L926
          v573[v578][(v579 + 2)][(v580 + 2)] = v757;	// L927
          float v758 = v569[v578][(v579 + 2)][(v580 + 3)];	// L928
          float v759 = v572[v578][(v579 + 2)][(v580 + 3)];	// L929
          float v760 = v573[v578][(v579 + 2)][(v580 + 3)];	// L930
          float v761 = (v577 == 0) ? v759 : v760;	// L931
          float v762 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v758 : v761;	// L932
          float v763 = v570[v577][(v579 + 2)][(v580 + 3)];	// L933
          float v764 = v763 * v587;	// L934
          float v765 = v762 + v764;	// L935
          float v766 = (double)0.000010;	// L936
          float v767 = v766 + (float)1.000000;	// L937
          float v768 = 1.0 / sqrt(v767);	// L938
          float v769 = v765 * v768;	// L939
          float v770 = v769 + (float)0.000000;	// L940
          bool v771 = v770 > (float)0.000000;	// L941
          float v772 = v771 ? v770 : (float)0.000000;	// L942
          float v773 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v772 : v765;	// L943
          v573[v578][(v579 + 2)][(v580 + 3)] = v773;	// L944
          float v774 = v569[v578][(v579 + 3)][v580];	// L945
          float v775 = v572[v578][(v579 + 3)][v580];	// L946
          float v776 = v573[v578][(v579 + 3)][v580];	// L947
          float v777 = (v577 == 0) ? v775 : v776;	// L948
          float v778 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v774 : v777;	// L949
          float v779 = v570[v577][(v579 + 3)][v580];	// L950
          float v780 = v779 * v587;	// L951
          float v781 = v778 + v780;	// L952
          float v782 = (double)0.000010;	// L953
          float v783 = v782 + (float)1.000000;	// L954
          float v784 = 1.0 / sqrt(v783);	// L955
          float v785 = v781 * v784;	// L956
          float v786 = v785 + (float)0.000000;	// L957
          bool v787 = v786 > (float)0.000000;	// L958
          float v788 = v787 ? v786 : (float)0.000000;	// L959
          float v789 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v788 : v781;	// L960
          v573[v578][(v579 + 3)][v580] = v789;	// L961
          float v790 = v569[v578][(v579 + 3)][(v580 + 1)];	// L962
          float v791 = v572[v578][(v579 + 3)][(v580 + 1)];	// L963
          float v792 = v573[v578][(v579 + 3)][(v580 + 1)];	// L964
          float v793 = (v577 == 0) ? v791 : v792;	// L965
          float v794 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v790 : v793;	// L966
          float v795 = v570[v577][(v579 + 3)][(v580 + 1)];	// L967
          float v796 = v795 * v587;	// L968
          float v797 = v794 + v796;	// L969
          float v798 = (double)0.000010;	// L970
          float v799 = v798 + (float)1.000000;	// L971
          float v800 = 1.0 / sqrt(v799);	// L972
          float v801 = v797 * v800;	// L973
          float v802 = v801 + (float)0.000000;	// L974
          bool v803 = v802 > (float)0.000000;	// L975
          float v804 = v803 ? v802 : (float)0.000000;	// L976
          float v805 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v804 : v797;	// L977
          v573[v578][(v579 + 3)][(v580 + 1)] = v805;	// L978
          float v806 = v569[v578][(v579 + 3)][(v580 + 2)];	// L979
          float v807 = v572[v578][(v579 + 3)][(v580 + 2)];	// L980
          float v808 = v573[v578][(v579 + 3)][(v580 + 2)];	// L981
          float v809 = (v577 == 0) ? v807 : v808;	// L982
          float v810 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v806 : v809;	// L983
          float v811 = v570[v577][(v579 + 3)][(v580 + 2)];	// L984
          float v812 = v811 * v587;	// L985
          float v813 = v810 + v812;	// L986
          float v814 = (double)0.000010;	// L987
          float v815 = v814 + (float)1.000000;	// L988
          float v816 = 1.0 / sqrt(v815);	// L989
          float v817 = v813 * v816;	// L990
          float v818 = v817 + (float)0.000000;	// L991
          bool v819 = v818 > (float)0.000000;	// L992
          float v820 = v819 ? v818 : (float)0.000000;	// L993
          float v821 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v820 : v813;	// L994
          v573[v578][(v579 + 3)][(v580 + 2)] = v821;	// L995
          float v822 = v569[v578][(v579 + 3)][(v580 + 3)];	// L996
          float v823 = v572[v578][(v579 + 3)][(v580 + 3)];	// L997
          float v824 = v573[v578][(v579 + 3)][(v580 + 3)];	// L998
          float v825 = (v577 == 0) ? v823 : v824;	// L999
          float v826 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v822 : v825;	// L1000
          float v827 = v570[v577][(v579 + 3)][(v580 + 3)];	// L1001
          float v828 = v827 * v587;	// L1002
          float v829 = v826 + v828;	// L1003
          float v830 = (double)0.000010;	// L1004
          float v831 = v830 + (float)1.000000;	// L1005
          float v832 = 1.0 / sqrt(v831);	// L1006
          float v833 = v829 * v832;	// L1007
          float v834 = v833 + (float)0.000000;	// L1008
          bool v835 = v834 > (float)0.000000;	// L1009
          float v836 = v835 ? v834 : (float)0.000000;	// L1010
          float v837 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v836 : v829;	// L1011
          v573[v578][(v579 + 3)][(v580 + 3)] = v837;	// L1012
          float v838 = v569[(v578 + 1)][v579][v580];	// L1013
          float v839 = v572[(v578 + 1)][v579][v580];	// L1014
          float v840 = v573[(v578 + 1)][v579][v580];	// L1015
          float v841 = (v577 == 0) ? v839 : v840;	// L1016
          float v842 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v838 : v841;	// L1017
          float v843 = v571[(v578 + 1)][v577];	// L1018
          float v844 = v586 * v843;	// L1019
          float v845 = v842 + v844;	// L1020
          float v846 = (double)0.000010;	// L1021
          float v847 = v846 + (float)1.000000;	// L1022
          float v848 = 1.0 / sqrt(v847);	// L1023
          float v849 = v845 * v848;	// L1024
          float v850 = v849 + (float)0.000000;	// L1025
          bool v851 = v850 > (float)0.000000;	// L1026
          float v852 = v851 ? v850 : (float)0.000000;	// L1027
          float v853 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v852 : v845;	// L1028
          v573[(v578 + 1)][v579][v580] = v853;	// L1029
          float v854 = v569[(v578 + 1)][v579][(v580 + 1)];	// L1030
          float v855 = v572[(v578 + 1)][v579][(v580 + 1)];	// L1031
          float v856 = v573[(v578 + 1)][v579][(v580 + 1)];	// L1032
          float v857 = (v577 == 0) ? v855 : v856;	// L1033
          float v858 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v854 : v857;	// L1034
          float v859 = v603 * v843;	// L1035
          float v860 = v858 + v859;	// L1036
          float v861 = (double)0.000010;	// L1037
          float v862 = v861 + (float)1.000000;	// L1038
          float v863 = 1.0 / sqrt(v862);	// L1039
          float v864 = v860 * v863;	// L1040
          float v865 = v864 + (float)0.000000;	// L1041
          bool v866 = v865 > (float)0.000000;	// L1042
          float v867 = v866 ? v865 : (float)0.000000;	// L1043
          float v868 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v867 : v860;	// L1044
          v573[(v578 + 1)][v579][(v580 + 1)] = v868;	// L1045
          float v869 = v569[(v578 + 1)][v579][(v580 + 2)];	// L1046
          float v870 = v572[(v578 + 1)][v579][(v580 + 2)];	// L1047
          float v871 = v573[(v578 + 1)][v579][(v580 + 2)];	// L1048
          float v872 = (v577 == 0) ? v870 : v871;	// L1049
          float v873 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v869 : v872;	// L1050
          float v874 = v619 * v843;	// L1051
          float v875 = v873 + v874;	// L1052
          float v876 = (double)0.000010;	// L1053
          float v877 = v876 + (float)1.000000;	// L1054
          float v878 = 1.0 / sqrt(v877);	// L1055
          float v879 = v875 * v878;	// L1056
          float v880 = v879 + (float)0.000000;	// L1057
          bool v881 = v880 > (float)0.000000;	// L1058
          float v882 = v881 ? v880 : (float)0.000000;	// L1059
          float v883 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v882 : v875;	// L1060
          v573[(v578 + 1)][v579][(v580 + 2)] = v883;	// L1061
          float v884 = v569[(v578 + 1)][v579][(v580 + 3)];	// L1062
          float v885 = v572[(v578 + 1)][v579][(v580 + 3)];	// L1063
          float v886 = v573[(v578 + 1)][v579][(v580 + 3)];	// L1064
          float v887 = (v577 == 0) ? v885 : v886;	// L1065
          float v888 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v884 : v887;	// L1066
          float v889 = v635 * v843;	// L1067
          float v890 = v888 + v889;	// L1068
          float v891 = (double)0.000010;	// L1069
          float v892 = v891 + (float)1.000000;	// L1070
          float v893 = 1.0 / sqrt(v892);	// L1071
          float v894 = v890 * v893;	// L1072
          float v895 = v894 + (float)0.000000;	// L1073
          bool v896 = v895 > (float)0.000000;	// L1074
          float v897 = v896 ? v895 : (float)0.000000;	// L1075
          float v898 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v897 : v890;	// L1076
          v573[(v578 + 1)][v579][(v580 + 3)] = v898;	// L1077
          float v899 = v569[(v578 + 1)][(v579 + 1)][v580];	// L1078
          float v900 = v572[(v578 + 1)][(v579 + 1)][v580];	// L1079
          float v901 = v573[(v578 + 1)][(v579 + 1)][v580];	// L1080
          float v902 = (v577 == 0) ? v900 : v901;	// L1081
          float v903 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v899 : v902;	// L1082
          float v904 = v651 * v843;	// L1083
          float v905 = v903 + v904;	// L1084
          float v906 = (double)0.000010;	// L1085
          float v907 = v906 + (float)1.000000;	// L1086
          float v908 = 1.0 / sqrt(v907);	// L1087
          float v909 = v905 * v908;	// L1088
          float v910 = v909 + (float)0.000000;	// L1089
          bool v911 = v910 > (float)0.000000;	// L1090
          float v912 = v911 ? v910 : (float)0.000000;	// L1091
          float v913 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v912 : v905;	// L1092
          v573[(v578 + 1)][(v579 + 1)][v580] = v913;	// L1093
          float v914 = v569[(v578 + 1)][(v579 + 1)][(v580 + 1)];	// L1094
          float v915 = v572[(v578 + 1)][(v579 + 1)][(v580 + 1)];	// L1095
          float v916 = v573[(v578 + 1)][(v579 + 1)][(v580 + 1)];	// L1096
          float v917 = (v577 == 0) ? v915 : v916;	// L1097
          float v918 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v914 : v917;	// L1098
          float v919 = v667 * v843;	// L1099
          float v920 = v918 + v919;	// L1100
          float v921 = (double)0.000010;	// L1101
          float v922 = v921 + (float)1.000000;	// L1102
          float v923 = 1.0 / sqrt(v922);	// L1103
          float v924 = v920 * v923;	// L1104
          float v925 = v924 + (float)0.000000;	// L1105
          bool v926 = v925 > (float)0.000000;	// L1106
          float v927 = v926 ? v925 : (float)0.000000;	// L1107
          float v928 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v927 : v920;	// L1108
          v573[(v578 + 1)][(v579 + 1)][(v580 + 1)] = v928;	// L1109
          float v929 = v569[(v578 + 1)][(v579 + 1)][(v580 + 2)];	// L1110
          float v930 = v572[(v578 + 1)][(v579 + 1)][(v580 + 2)];	// L1111
          float v931 = v573[(v578 + 1)][(v579 + 1)][(v580 + 2)];	// L1112
          float v932 = (v577 == 0) ? v930 : v931;	// L1113
          float v933 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v929 : v932;	// L1114
          float v934 = v683 * v843;	// L1115
          float v935 = v933 + v934;	// L1116
          float v936 = (double)0.000010;	// L1117
          float v937 = v936 + (float)1.000000;	// L1118
          float v938 = 1.0 / sqrt(v937);	// L1119
          float v939 = v935 * v938;	// L1120
          float v940 = v939 + (float)0.000000;	// L1121
          bool v941 = v940 > (float)0.000000;	// L1122
          float v942 = v941 ? v940 : (float)0.000000;	// L1123
          float v943 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v942 : v935;	// L1124
          v573[(v578 + 1)][(v579 + 1)][(v580 + 2)] = v943;	// L1125
          float v944 = v569[(v578 + 1)][(v579 + 1)][(v580 + 3)];	// L1126
          float v945 = v572[(v578 + 1)][(v579 + 1)][(v580 + 3)];	// L1127
          float v946 = v573[(v578 + 1)][(v579 + 1)][(v580 + 3)];	// L1128
          float v947 = (v577 == 0) ? v945 : v946;	// L1129
          float v948 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v944 : v947;	// L1130
          float v949 = v699 * v843;	// L1131
          float v950 = v948 + v949;	// L1132
          float v951 = (double)0.000010;	// L1133
          float v952 = v951 + (float)1.000000;	// L1134
          float v953 = 1.0 / sqrt(v952);	// L1135
          float v954 = v950 * v953;	// L1136
          float v955 = v954 + (float)0.000000;	// L1137
          bool v956 = v955 > (float)0.000000;	// L1138
          float v957 = v956 ? v955 : (float)0.000000;	// L1139
          float v958 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v957 : v950;	// L1140
          v573[(v578 + 1)][(v579 + 1)][(v580 + 3)] = v958;	// L1141
          float v959 = v569[(v578 + 1)][(v579 + 2)][v580];	// L1142
          float v960 = v572[(v578 + 1)][(v579 + 2)][v580];	// L1143
          float v961 = v573[(v578 + 1)][(v579 + 2)][v580];	// L1144
          float v962 = (v577 == 0) ? v960 : v961;	// L1145
          float v963 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v959 : v962;	// L1146
          float v964 = v715 * v843;	// L1147
          float v965 = v963 + v964;	// L1148
          float v966 = (double)0.000010;	// L1149
          float v967 = v966 + (float)1.000000;	// L1150
          float v968 = 1.0 / sqrt(v967);	// L1151
          float v969 = v965 * v968;	// L1152
          float v970 = v969 + (float)0.000000;	// L1153
          bool v971 = v970 > (float)0.000000;	// L1154
          float v972 = v971 ? v970 : (float)0.000000;	// L1155
          float v973 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v972 : v965;	// L1156
          v573[(v578 + 1)][(v579 + 2)][v580] = v973;	// L1157
          float v974 = v569[(v578 + 1)][(v579 + 2)][(v580 + 1)];	// L1158
          float v975 = v572[(v578 + 1)][(v579 + 2)][(v580 + 1)];	// L1159
          float v976 = v573[(v578 + 1)][(v579 + 2)][(v580 + 1)];	// L1160
          float v977 = (v577 == 0) ? v975 : v976;	// L1161
          float v978 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v974 : v977;	// L1162
          float v979 = v731 * v843;	// L1163
          float v980 = v978 + v979;	// L1164
          float v981 = (double)0.000010;	// L1165
          float v982 = v981 + (float)1.000000;	// L1166
          float v983 = 1.0 / sqrt(v982);	// L1167
          float v984 = v980 * v983;	// L1168
          float v985 = v984 + (float)0.000000;	// L1169
          bool v986 = v985 > (float)0.000000;	// L1170
          float v987 = v986 ? v985 : (float)0.000000;	// L1171
          float v988 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v987 : v980;	// L1172
          v573[(v578 + 1)][(v579 + 2)][(v580 + 1)] = v988;	// L1173
          float v989 = v569[(v578 + 1)][(v579 + 2)][(v580 + 2)];	// L1174
          float v990 = v572[(v578 + 1)][(v579 + 2)][(v580 + 2)];	// L1175
          float v991 = v573[(v578 + 1)][(v579 + 2)][(v580 + 2)];	// L1176
          float v992 = (v577 == 0) ? v990 : v991;	// L1177
          float v993 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v989 : v992;	// L1178
          float v994 = v747 * v843;	// L1179
          float v995 = v993 + v994;	// L1180
          float v996 = (double)0.000010;	// L1181
          float v997 = v996 + (float)1.000000;	// L1182
          float v998 = 1.0 / sqrt(v997);	// L1183
          float v999 = v995 * v998;	// L1184
          float v1000 = v999 + (float)0.000000;	// L1185
          bool v1001 = v1000 > (float)0.000000;	// L1186
          float v1002 = v1001 ? v1000 : (float)0.000000;	// L1187
          float v1003 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v1002 : v995;	// L1188
          v573[(v578 + 1)][(v579 + 2)][(v580 + 2)] = v1003;	// L1189
          float v1004 = v569[(v578 + 1)][(v579 + 2)][(v580 + 3)];	// L1190
          float v1005 = v572[(v578 + 1)][(v579 + 2)][(v580 + 3)];	// L1191
          float v1006 = v573[(v578 + 1)][(v579 + 2)][(v580 + 3)];	// L1192
          float v1007 = (v577 == 0) ? v1005 : v1006;	// L1193
          float v1008 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v1004 : v1007;	// L1194
          float v1009 = v763 * v843;	// L1195
          float v1010 = v1008 + v1009;	// L1196
          float v1011 = (double)0.000010;	// L1197
          float v1012 = v1011 + (float)1.000000;	// L1198
          float v1013 = 1.0 / sqrt(v1012);	// L1199
          float v1014 = v1010 * v1013;	// L1200
          float v1015 = v1014 + (float)0.000000;	// L1201
          bool v1016 = v1015 > (float)0.000000;	// L1202
          float v1017 = v1016 ? v1015 : (float)0.000000;	// L1203
          float v1018 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v1017 : v1010;	// L1204
          v573[(v578 + 1)][(v579 + 2)][(v580 + 3)] = v1018;	// L1205
          float v1019 = v569[(v578 + 1)][(v579 + 3)][v580];	// L1206
          float v1020 = v572[(v578 + 1)][(v579 + 3)][v580];	// L1207
          float v1021 = v573[(v578 + 1)][(v579 + 3)][v580];	// L1208
          float v1022 = (v577 == 0) ? v1020 : v1021;	// L1209
          float v1023 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v1019 : v1022;	// L1210
          float v1024 = v779 * v843;	// L1211
          float v1025 = v1023 + v1024;	// L1212
          float v1026 = (double)0.000010;	// L1213
          float v1027 = v1026 + (float)1.000000;	// L1214
          float v1028 = 1.0 / sqrt(v1027);	// L1215
          float v1029 = v1025 * v1028;	// L1216
          float v1030 = v1029 + (float)0.000000;	// L1217
          bool v1031 = v1030 > (float)0.000000;	// L1218
          float v1032 = v1031 ? v1030 : (float)0.000000;	// L1219
          float v1033 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v1032 : v1025;	// L1220
          v573[(v578 + 1)][(v579 + 3)][v580] = v1033;	// L1221
          float v1034 = v569[(v578 + 1)][(v579 + 3)][(v580 + 1)];	// L1222
          float v1035 = v572[(v578 + 1)][(v579 + 3)][(v580 + 1)];	// L1223
          float v1036 = v573[(v578 + 1)][(v579 + 3)][(v580 + 1)];	// L1224
          float v1037 = (v577 == 0) ? v1035 : v1036;	// L1225
          float v1038 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v1034 : v1037;	// L1226
          float v1039 = v795 * v843;	// L1227
          float v1040 = v1038 + v1039;	// L1228
          float v1041 = (double)0.000010;	// L1229
          float v1042 = v1041 + (float)1.000000;	// L1230
          float v1043 = 1.0 / sqrt(v1042);	// L1231
          float v1044 = v1040 * v1043;	// L1232
          float v1045 = v1044 + (float)0.000000;	// L1233
          bool v1046 = v1045 > (float)0.000000;	// L1234
          float v1047 = v1046 ? v1045 : (float)0.000000;	// L1235
          float v1048 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v1047 : v1040;	// L1236
          v573[(v578 + 1)][(v579 + 3)][(v580 + 1)] = v1048;	// L1237
          float v1049 = v569[(v578 + 1)][(v579 + 3)][(v580 + 2)];	// L1238
          float v1050 = v572[(v578 + 1)][(v579 + 3)][(v580 + 2)];	// L1239
          float v1051 = v573[(v578 + 1)][(v579 + 3)][(v580 + 2)];	// L1240
          float v1052 = (v577 == 0) ? v1050 : v1051;	// L1241
          float v1053 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v1049 : v1052;	// L1242
          float v1054 = v811 * v843;	// L1243
          float v1055 = v1053 + v1054;	// L1244
          float v1056 = (double)0.000010;	// L1245
          float v1057 = v1056 + (float)1.000000;	// L1246
          float v1058 = 1.0 / sqrt(v1057);	// L1247
          float v1059 = v1055 * v1058;	// L1248
          float v1060 = v1059 + (float)0.000000;	// L1249
          bool v1061 = v1060 > (float)0.000000;	// L1250
          float v1062 = v1061 ? v1060 : (float)0.000000;	// L1251
          float v1063 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v1062 : v1055;	// L1252
          v573[(v578 + 1)][(v579 + 3)][(v580 + 2)] = v1063;	// L1253
          float v1064 = v569[(v578 + 1)][(v579 + 3)][(v580 + 3)];	// L1254
          float v1065 = v572[(v578 + 1)][(v579 + 3)][(v580 + 3)];	// L1255
          float v1066 = v573[(v578 + 1)][(v579 + 3)][(v580 + 3)];	// L1256
          float v1067 = (v577 == 0) ? v1065 : v1066;	// L1257
          float v1068 = ((v577 + (v575 * 16)) == 0 && v576 == 0 && v574 == 0) ? v1064 : v1067;	// L1258
          float v1069 = v827 * v843;	// L1259
          float v1070 = v1068 + v1069;	// L1260
          float v1071 = (double)0.000010;	// L1261
          float v1072 = v1071 + (float)1.000000;	// L1262
          float v1073 = 1.0 / sqrt(v1072);	// L1263
          float v1074 = v1070 * v1073;	// L1264
          float v1075 = v1074 + (float)0.000000;	// L1265
          bool v1076 = v1075 > (float)0.000000;	// L1266
          float v1077 = v1076 ? v1075 : (float)0.000000;	// L1267
          float v1078 = ((((-v577) + (v575 * -16)) + 31) == 0 && ((-v576) + 2) == 0 && ((-v574) + 2) == 0) ? v1077 : v1070;	// L1268
          v573[(v578 + 1)][(v579 + 3)][(v580 + 3)] = v1078;	// L1269
        }
      }
    }
  }
}

void forward_node11(
  float v1079[32][32][3][3],
  float v1080[16][16],
  int v1081,
  int v1082,
  int v1083,
  int v1084
) {	// L1276
  #pragma HLS inline
  for (int v1085 = 0; v1085 < 16; v1085 += 1) {	// L1277
    for (int v1086 = 0; v1086 < 16; v1086 += 1) {	// L1278
      #pragma HLS pipeline II=1
      float v1087 = v1079[(v1085 + (v1083 * 16))][(v1086 + (v1084 * 16))][v1081][v1082];	// L1279
      v1080[v1085][v1086] = v1087;	// L1280
    }
  }
}

void forward_node12(
  float v1088[32][112][112],
  float v1089[16][28][28],
  int v1090,
  int v1091,
  int v1092,
  int v1093,
  int v1094
) {	// L1285
  #pragma HLS inline
  for (int v1095 = 0; v1095 < 16; v1095 += 1) {	// L1286
    for (int v1096 = 0; v1096 < 28; v1096 += 1) {	// L1287
      for (int v1097 = 0; v1097 < 28; v1097 += 2) {	// L1288
        #pragma HLS pipeline II=1
        float v1098 = v1088[(v1095 + (v1090 * 16))][(((v1096 + v1091) + (v1092 * 28)) - 1)][(((v1097 + v1093) + (v1094 * 28)) - 1)];	// L1289
        v1089[v1095][v1096][v1097] = v1098;	// L1290
        float v1099 = v1088[(v1095 + (v1090 * 16))][(((v1096 + v1091) + (v1092 * 28)) - 1)][((v1097 + v1093) + (v1094 * 28))];	// L1291
        v1089[v1095][v1096][(v1097 + 1)] = v1099;	// L1292
      }
    }
  }
}

void forward_node13(
  float v1100[32][112][112],
  float v1101[16][28][28],
  int v1102,
  int v1103,
  int v1104
) {	// L1298
  #pragma HLS inline
  for (int v1105 = 0; v1105 < 16; v1105 += 1) {	// L1299
    for (int v1106 = 0; v1106 < 28; v1106 += 1) {	// L1300
      for (int v1107 = 0; v1107 < 28; v1107 += 2) {	// L1301
        #pragma HLS pipeline II=1
        float v1108 = v1100[(v1105 + (v1102 * 16))][(v1106 + (v1103 * 28))][(v1107 + (v1104 * 28))];	// L1302
        v1101[v1105][v1106][v1107] = v1108;	// L1303
        float v1109 = v1100[(v1105 + (v1102 * 16))][(v1106 + (v1103 * 28))][((v1107 + (v1104 * 28)) + 1)];	// L1304
        v1101[v1105][v1106][(v1107 + 1)] = v1109;	// L1305
      }
    }
  }
}

void forward_node14(
  float v1110[32][112][112],
  float v1111[16][28][28],
  int v1112,
  int v1113,
  int v1114
) {	// L1311
  #pragma HLS inline
  for (int v1115 = 0; v1115 < 16; v1115 += 1) {	// L1312
    for (int v1116 = 0; v1116 < 28; v1116 += 1) {	// L1313
      for (int v1117 = 0; v1117 < 28; v1117 += 2) {	// L1314
        #pragma HLS pipeline II=1
        float v1118 = v1110[(v1115 + (v1112 * 16))][(v1116 + (v1113 * 28))][(v1117 + (v1114 * 28))];	// L1315
        v1111[v1115][v1116][v1117] = v1118;	// L1316
        float v1119 = v1110[(v1115 + (v1112 * 16))][(v1116 + (v1113 * 28))][((v1117 + (v1114 * 28)) + 1)];	// L1317
        v1111[v1115][v1116][(v1117 + 1)] = v1119;	// L1318
      }
    }
  }
}

void forward_node8(
  float v1120[32][112][112],
  float v1121[32][32][3][3],
  float v1122[32][112][112],
  float v1123[32][112][112],
  float v1124[32][112][112]
) {	// L1324
  for (int v1125 = 0; v1125 < 576; v1125 += 1) {	// L1325
    #pragma HLS dataflow
    int v1126 = (v1125 % 4);	// L1326
    int v1127 = ((v1125 / 4) % 4);	// L1327
    int v1128 = (((v1125 / 4) / 4) % 2);	// L1328
    int v1129 = ((((v1125 / 4) / 4) / 2) % 3);	// L1329
    int v1130 = (((((v1125 / 4) / 4) / 2) / 3) % 3);	// L1330
    int v1131 = (((((v1125 / 4) / 4) / 2) / 3) / 3);	// L1331
    float v1132[16][16];	// L1332
    #pragma HLS array_partition variable=v1132 cyclic factor=2 dim=1
    #pragma HLS resource variable=v1132 core=ram_2p_lutram

    float v1133[16][28][28];	// L1333
    #pragma HLS array_partition variable=v1133 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v1133 cyclic factor=4 dim=3
    #pragma HLS resource variable=v1133 core=ram_2p_lutram

    float v1134[16][28][28];	// L1334
    #pragma HLS array_partition variable=v1134 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1134 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v1134 cyclic factor=4 dim=3
    #pragma HLS resource variable=v1134 core=ram_2p_lutram

    float v1135[16][28][28];	// L1335
    #pragma HLS array_partition variable=v1135 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1135 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v1135 cyclic factor=4 dim=3
    #pragma HLS resource variable=v1135 core=ram_2p_lutram

    forward_node14(v1122, v1135, v1128, v1127, v1126);	// L1336
    forward_node13(v1123, v1134, v1128, v1127, v1126);	// L1337
    forward_node12(v1120, v1133, v1131, v1130, v1127, v1129, v1126);	// L1338
    forward_node11(v1121, v1132, v1130, v1129, v1128, v1131);	// L1339
    float v1136[16][28][28];	// L1340
    #pragma HLS array_partition variable=v1136 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v1136 cyclic factor=4 dim=2
    #pragma HLS array_partition variable=v1136 cyclic factor=4 dim=3
    #pragma HLS resource variable=v1136 core=ram_2p_lutram

    forward_node10(v1135, v1133, v1132, v1134, v1136, v1129, v1131, v1130);	// L1341
    forward_node9(v1136, v1124, v1128, v1127, v1126);	// L1342
  }
}

/// This is top function.
void forward(
  float v1137[32][112][112],
  float v1138[32][112][112],
  float v1139[32][112][112],
  float v1140[32][32][3][3],
  float v1141[32][32][3][3],
  float v1142[32][112][112],
  float v1143[32][112][112],
  float v1144[32][112][112],
  float v1145[32][112][112],
  float v1146[32][112][112],
  float v1147[32][112][112]
) {	// L1346
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface m_axi offset=slave port=v1147 bundle=axi_10

  #pragma HLS interface m_axi offset=slave port=v1146 bundle=axi_9

  #pragma HLS interface m_axi offset=slave port=v1145 bundle=axi_8

  #pragma HLS interface m_axi offset=slave port=v1144 bundle=axi_7

  #pragma HLS interface m_axi offset=slave port=v1143 bundle=axi_6

  #pragma HLS interface m_axi offset=slave port=v1142 bundle=axi_5

  #pragma HLS interface m_axi offset=slave port=v1141 bundle=axi_4

  #pragma HLS interface m_axi offset=slave port=v1140 bundle=axi_3

  #pragma HLS interface m_axi offset=slave port=v1139 bundle=axi_2

  #pragma HLS interface m_axi offset=slave port=v1138 bundle=axi_1

  #pragma HLS interface m_axi offset=slave port=v1137 bundle=axi_0

  forward_node8(v1138, v1140, v1142, v1146, v1145);	// L1369
  forward_node0(v1147, v1137, v1141, v1144, v1143, v1139);	// L1370
}

