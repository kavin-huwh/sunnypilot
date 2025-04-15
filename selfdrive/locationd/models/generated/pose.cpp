#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3039420483993860343) {
   out_3039420483993860343[0] = delta_x[0] + nom_x[0];
   out_3039420483993860343[1] = delta_x[1] + nom_x[1];
   out_3039420483993860343[2] = delta_x[2] + nom_x[2];
   out_3039420483993860343[3] = delta_x[3] + nom_x[3];
   out_3039420483993860343[4] = delta_x[4] + nom_x[4];
   out_3039420483993860343[5] = delta_x[5] + nom_x[5];
   out_3039420483993860343[6] = delta_x[6] + nom_x[6];
   out_3039420483993860343[7] = delta_x[7] + nom_x[7];
   out_3039420483993860343[8] = delta_x[8] + nom_x[8];
   out_3039420483993860343[9] = delta_x[9] + nom_x[9];
   out_3039420483993860343[10] = delta_x[10] + nom_x[10];
   out_3039420483993860343[11] = delta_x[11] + nom_x[11];
   out_3039420483993860343[12] = delta_x[12] + nom_x[12];
   out_3039420483993860343[13] = delta_x[13] + nom_x[13];
   out_3039420483993860343[14] = delta_x[14] + nom_x[14];
   out_3039420483993860343[15] = delta_x[15] + nom_x[15];
   out_3039420483993860343[16] = delta_x[16] + nom_x[16];
   out_3039420483993860343[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8695657740442878095) {
   out_8695657740442878095[0] = -nom_x[0] + true_x[0];
   out_8695657740442878095[1] = -nom_x[1] + true_x[1];
   out_8695657740442878095[2] = -nom_x[2] + true_x[2];
   out_8695657740442878095[3] = -nom_x[3] + true_x[3];
   out_8695657740442878095[4] = -nom_x[4] + true_x[4];
   out_8695657740442878095[5] = -nom_x[5] + true_x[5];
   out_8695657740442878095[6] = -nom_x[6] + true_x[6];
   out_8695657740442878095[7] = -nom_x[7] + true_x[7];
   out_8695657740442878095[8] = -nom_x[8] + true_x[8];
   out_8695657740442878095[9] = -nom_x[9] + true_x[9];
   out_8695657740442878095[10] = -nom_x[10] + true_x[10];
   out_8695657740442878095[11] = -nom_x[11] + true_x[11];
   out_8695657740442878095[12] = -nom_x[12] + true_x[12];
   out_8695657740442878095[13] = -nom_x[13] + true_x[13];
   out_8695657740442878095[14] = -nom_x[14] + true_x[14];
   out_8695657740442878095[15] = -nom_x[15] + true_x[15];
   out_8695657740442878095[16] = -nom_x[16] + true_x[16];
   out_8695657740442878095[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7820924518988244848) {
   out_7820924518988244848[0] = 1.0;
   out_7820924518988244848[1] = 0.0;
   out_7820924518988244848[2] = 0.0;
   out_7820924518988244848[3] = 0.0;
   out_7820924518988244848[4] = 0.0;
   out_7820924518988244848[5] = 0.0;
   out_7820924518988244848[6] = 0.0;
   out_7820924518988244848[7] = 0.0;
   out_7820924518988244848[8] = 0.0;
   out_7820924518988244848[9] = 0.0;
   out_7820924518988244848[10] = 0.0;
   out_7820924518988244848[11] = 0.0;
   out_7820924518988244848[12] = 0.0;
   out_7820924518988244848[13] = 0.0;
   out_7820924518988244848[14] = 0.0;
   out_7820924518988244848[15] = 0.0;
   out_7820924518988244848[16] = 0.0;
   out_7820924518988244848[17] = 0.0;
   out_7820924518988244848[18] = 0.0;
   out_7820924518988244848[19] = 1.0;
   out_7820924518988244848[20] = 0.0;
   out_7820924518988244848[21] = 0.0;
   out_7820924518988244848[22] = 0.0;
   out_7820924518988244848[23] = 0.0;
   out_7820924518988244848[24] = 0.0;
   out_7820924518988244848[25] = 0.0;
   out_7820924518988244848[26] = 0.0;
   out_7820924518988244848[27] = 0.0;
   out_7820924518988244848[28] = 0.0;
   out_7820924518988244848[29] = 0.0;
   out_7820924518988244848[30] = 0.0;
   out_7820924518988244848[31] = 0.0;
   out_7820924518988244848[32] = 0.0;
   out_7820924518988244848[33] = 0.0;
   out_7820924518988244848[34] = 0.0;
   out_7820924518988244848[35] = 0.0;
   out_7820924518988244848[36] = 0.0;
   out_7820924518988244848[37] = 0.0;
   out_7820924518988244848[38] = 1.0;
   out_7820924518988244848[39] = 0.0;
   out_7820924518988244848[40] = 0.0;
   out_7820924518988244848[41] = 0.0;
   out_7820924518988244848[42] = 0.0;
   out_7820924518988244848[43] = 0.0;
   out_7820924518988244848[44] = 0.0;
   out_7820924518988244848[45] = 0.0;
   out_7820924518988244848[46] = 0.0;
   out_7820924518988244848[47] = 0.0;
   out_7820924518988244848[48] = 0.0;
   out_7820924518988244848[49] = 0.0;
   out_7820924518988244848[50] = 0.0;
   out_7820924518988244848[51] = 0.0;
   out_7820924518988244848[52] = 0.0;
   out_7820924518988244848[53] = 0.0;
   out_7820924518988244848[54] = 0.0;
   out_7820924518988244848[55] = 0.0;
   out_7820924518988244848[56] = 0.0;
   out_7820924518988244848[57] = 1.0;
   out_7820924518988244848[58] = 0.0;
   out_7820924518988244848[59] = 0.0;
   out_7820924518988244848[60] = 0.0;
   out_7820924518988244848[61] = 0.0;
   out_7820924518988244848[62] = 0.0;
   out_7820924518988244848[63] = 0.0;
   out_7820924518988244848[64] = 0.0;
   out_7820924518988244848[65] = 0.0;
   out_7820924518988244848[66] = 0.0;
   out_7820924518988244848[67] = 0.0;
   out_7820924518988244848[68] = 0.0;
   out_7820924518988244848[69] = 0.0;
   out_7820924518988244848[70] = 0.0;
   out_7820924518988244848[71] = 0.0;
   out_7820924518988244848[72] = 0.0;
   out_7820924518988244848[73] = 0.0;
   out_7820924518988244848[74] = 0.0;
   out_7820924518988244848[75] = 0.0;
   out_7820924518988244848[76] = 1.0;
   out_7820924518988244848[77] = 0.0;
   out_7820924518988244848[78] = 0.0;
   out_7820924518988244848[79] = 0.0;
   out_7820924518988244848[80] = 0.0;
   out_7820924518988244848[81] = 0.0;
   out_7820924518988244848[82] = 0.0;
   out_7820924518988244848[83] = 0.0;
   out_7820924518988244848[84] = 0.0;
   out_7820924518988244848[85] = 0.0;
   out_7820924518988244848[86] = 0.0;
   out_7820924518988244848[87] = 0.0;
   out_7820924518988244848[88] = 0.0;
   out_7820924518988244848[89] = 0.0;
   out_7820924518988244848[90] = 0.0;
   out_7820924518988244848[91] = 0.0;
   out_7820924518988244848[92] = 0.0;
   out_7820924518988244848[93] = 0.0;
   out_7820924518988244848[94] = 0.0;
   out_7820924518988244848[95] = 1.0;
   out_7820924518988244848[96] = 0.0;
   out_7820924518988244848[97] = 0.0;
   out_7820924518988244848[98] = 0.0;
   out_7820924518988244848[99] = 0.0;
   out_7820924518988244848[100] = 0.0;
   out_7820924518988244848[101] = 0.0;
   out_7820924518988244848[102] = 0.0;
   out_7820924518988244848[103] = 0.0;
   out_7820924518988244848[104] = 0.0;
   out_7820924518988244848[105] = 0.0;
   out_7820924518988244848[106] = 0.0;
   out_7820924518988244848[107] = 0.0;
   out_7820924518988244848[108] = 0.0;
   out_7820924518988244848[109] = 0.0;
   out_7820924518988244848[110] = 0.0;
   out_7820924518988244848[111] = 0.0;
   out_7820924518988244848[112] = 0.0;
   out_7820924518988244848[113] = 0.0;
   out_7820924518988244848[114] = 1.0;
   out_7820924518988244848[115] = 0.0;
   out_7820924518988244848[116] = 0.0;
   out_7820924518988244848[117] = 0.0;
   out_7820924518988244848[118] = 0.0;
   out_7820924518988244848[119] = 0.0;
   out_7820924518988244848[120] = 0.0;
   out_7820924518988244848[121] = 0.0;
   out_7820924518988244848[122] = 0.0;
   out_7820924518988244848[123] = 0.0;
   out_7820924518988244848[124] = 0.0;
   out_7820924518988244848[125] = 0.0;
   out_7820924518988244848[126] = 0.0;
   out_7820924518988244848[127] = 0.0;
   out_7820924518988244848[128] = 0.0;
   out_7820924518988244848[129] = 0.0;
   out_7820924518988244848[130] = 0.0;
   out_7820924518988244848[131] = 0.0;
   out_7820924518988244848[132] = 0.0;
   out_7820924518988244848[133] = 1.0;
   out_7820924518988244848[134] = 0.0;
   out_7820924518988244848[135] = 0.0;
   out_7820924518988244848[136] = 0.0;
   out_7820924518988244848[137] = 0.0;
   out_7820924518988244848[138] = 0.0;
   out_7820924518988244848[139] = 0.0;
   out_7820924518988244848[140] = 0.0;
   out_7820924518988244848[141] = 0.0;
   out_7820924518988244848[142] = 0.0;
   out_7820924518988244848[143] = 0.0;
   out_7820924518988244848[144] = 0.0;
   out_7820924518988244848[145] = 0.0;
   out_7820924518988244848[146] = 0.0;
   out_7820924518988244848[147] = 0.0;
   out_7820924518988244848[148] = 0.0;
   out_7820924518988244848[149] = 0.0;
   out_7820924518988244848[150] = 0.0;
   out_7820924518988244848[151] = 0.0;
   out_7820924518988244848[152] = 1.0;
   out_7820924518988244848[153] = 0.0;
   out_7820924518988244848[154] = 0.0;
   out_7820924518988244848[155] = 0.0;
   out_7820924518988244848[156] = 0.0;
   out_7820924518988244848[157] = 0.0;
   out_7820924518988244848[158] = 0.0;
   out_7820924518988244848[159] = 0.0;
   out_7820924518988244848[160] = 0.0;
   out_7820924518988244848[161] = 0.0;
   out_7820924518988244848[162] = 0.0;
   out_7820924518988244848[163] = 0.0;
   out_7820924518988244848[164] = 0.0;
   out_7820924518988244848[165] = 0.0;
   out_7820924518988244848[166] = 0.0;
   out_7820924518988244848[167] = 0.0;
   out_7820924518988244848[168] = 0.0;
   out_7820924518988244848[169] = 0.0;
   out_7820924518988244848[170] = 0.0;
   out_7820924518988244848[171] = 1.0;
   out_7820924518988244848[172] = 0.0;
   out_7820924518988244848[173] = 0.0;
   out_7820924518988244848[174] = 0.0;
   out_7820924518988244848[175] = 0.0;
   out_7820924518988244848[176] = 0.0;
   out_7820924518988244848[177] = 0.0;
   out_7820924518988244848[178] = 0.0;
   out_7820924518988244848[179] = 0.0;
   out_7820924518988244848[180] = 0.0;
   out_7820924518988244848[181] = 0.0;
   out_7820924518988244848[182] = 0.0;
   out_7820924518988244848[183] = 0.0;
   out_7820924518988244848[184] = 0.0;
   out_7820924518988244848[185] = 0.0;
   out_7820924518988244848[186] = 0.0;
   out_7820924518988244848[187] = 0.0;
   out_7820924518988244848[188] = 0.0;
   out_7820924518988244848[189] = 0.0;
   out_7820924518988244848[190] = 1.0;
   out_7820924518988244848[191] = 0.0;
   out_7820924518988244848[192] = 0.0;
   out_7820924518988244848[193] = 0.0;
   out_7820924518988244848[194] = 0.0;
   out_7820924518988244848[195] = 0.0;
   out_7820924518988244848[196] = 0.0;
   out_7820924518988244848[197] = 0.0;
   out_7820924518988244848[198] = 0.0;
   out_7820924518988244848[199] = 0.0;
   out_7820924518988244848[200] = 0.0;
   out_7820924518988244848[201] = 0.0;
   out_7820924518988244848[202] = 0.0;
   out_7820924518988244848[203] = 0.0;
   out_7820924518988244848[204] = 0.0;
   out_7820924518988244848[205] = 0.0;
   out_7820924518988244848[206] = 0.0;
   out_7820924518988244848[207] = 0.0;
   out_7820924518988244848[208] = 0.0;
   out_7820924518988244848[209] = 1.0;
   out_7820924518988244848[210] = 0.0;
   out_7820924518988244848[211] = 0.0;
   out_7820924518988244848[212] = 0.0;
   out_7820924518988244848[213] = 0.0;
   out_7820924518988244848[214] = 0.0;
   out_7820924518988244848[215] = 0.0;
   out_7820924518988244848[216] = 0.0;
   out_7820924518988244848[217] = 0.0;
   out_7820924518988244848[218] = 0.0;
   out_7820924518988244848[219] = 0.0;
   out_7820924518988244848[220] = 0.0;
   out_7820924518988244848[221] = 0.0;
   out_7820924518988244848[222] = 0.0;
   out_7820924518988244848[223] = 0.0;
   out_7820924518988244848[224] = 0.0;
   out_7820924518988244848[225] = 0.0;
   out_7820924518988244848[226] = 0.0;
   out_7820924518988244848[227] = 0.0;
   out_7820924518988244848[228] = 1.0;
   out_7820924518988244848[229] = 0.0;
   out_7820924518988244848[230] = 0.0;
   out_7820924518988244848[231] = 0.0;
   out_7820924518988244848[232] = 0.0;
   out_7820924518988244848[233] = 0.0;
   out_7820924518988244848[234] = 0.0;
   out_7820924518988244848[235] = 0.0;
   out_7820924518988244848[236] = 0.0;
   out_7820924518988244848[237] = 0.0;
   out_7820924518988244848[238] = 0.0;
   out_7820924518988244848[239] = 0.0;
   out_7820924518988244848[240] = 0.0;
   out_7820924518988244848[241] = 0.0;
   out_7820924518988244848[242] = 0.0;
   out_7820924518988244848[243] = 0.0;
   out_7820924518988244848[244] = 0.0;
   out_7820924518988244848[245] = 0.0;
   out_7820924518988244848[246] = 0.0;
   out_7820924518988244848[247] = 1.0;
   out_7820924518988244848[248] = 0.0;
   out_7820924518988244848[249] = 0.0;
   out_7820924518988244848[250] = 0.0;
   out_7820924518988244848[251] = 0.0;
   out_7820924518988244848[252] = 0.0;
   out_7820924518988244848[253] = 0.0;
   out_7820924518988244848[254] = 0.0;
   out_7820924518988244848[255] = 0.0;
   out_7820924518988244848[256] = 0.0;
   out_7820924518988244848[257] = 0.0;
   out_7820924518988244848[258] = 0.0;
   out_7820924518988244848[259] = 0.0;
   out_7820924518988244848[260] = 0.0;
   out_7820924518988244848[261] = 0.0;
   out_7820924518988244848[262] = 0.0;
   out_7820924518988244848[263] = 0.0;
   out_7820924518988244848[264] = 0.0;
   out_7820924518988244848[265] = 0.0;
   out_7820924518988244848[266] = 1.0;
   out_7820924518988244848[267] = 0.0;
   out_7820924518988244848[268] = 0.0;
   out_7820924518988244848[269] = 0.0;
   out_7820924518988244848[270] = 0.0;
   out_7820924518988244848[271] = 0.0;
   out_7820924518988244848[272] = 0.0;
   out_7820924518988244848[273] = 0.0;
   out_7820924518988244848[274] = 0.0;
   out_7820924518988244848[275] = 0.0;
   out_7820924518988244848[276] = 0.0;
   out_7820924518988244848[277] = 0.0;
   out_7820924518988244848[278] = 0.0;
   out_7820924518988244848[279] = 0.0;
   out_7820924518988244848[280] = 0.0;
   out_7820924518988244848[281] = 0.0;
   out_7820924518988244848[282] = 0.0;
   out_7820924518988244848[283] = 0.0;
   out_7820924518988244848[284] = 0.0;
   out_7820924518988244848[285] = 1.0;
   out_7820924518988244848[286] = 0.0;
   out_7820924518988244848[287] = 0.0;
   out_7820924518988244848[288] = 0.0;
   out_7820924518988244848[289] = 0.0;
   out_7820924518988244848[290] = 0.0;
   out_7820924518988244848[291] = 0.0;
   out_7820924518988244848[292] = 0.0;
   out_7820924518988244848[293] = 0.0;
   out_7820924518988244848[294] = 0.0;
   out_7820924518988244848[295] = 0.0;
   out_7820924518988244848[296] = 0.0;
   out_7820924518988244848[297] = 0.0;
   out_7820924518988244848[298] = 0.0;
   out_7820924518988244848[299] = 0.0;
   out_7820924518988244848[300] = 0.0;
   out_7820924518988244848[301] = 0.0;
   out_7820924518988244848[302] = 0.0;
   out_7820924518988244848[303] = 0.0;
   out_7820924518988244848[304] = 1.0;
   out_7820924518988244848[305] = 0.0;
   out_7820924518988244848[306] = 0.0;
   out_7820924518988244848[307] = 0.0;
   out_7820924518988244848[308] = 0.0;
   out_7820924518988244848[309] = 0.0;
   out_7820924518988244848[310] = 0.0;
   out_7820924518988244848[311] = 0.0;
   out_7820924518988244848[312] = 0.0;
   out_7820924518988244848[313] = 0.0;
   out_7820924518988244848[314] = 0.0;
   out_7820924518988244848[315] = 0.0;
   out_7820924518988244848[316] = 0.0;
   out_7820924518988244848[317] = 0.0;
   out_7820924518988244848[318] = 0.0;
   out_7820924518988244848[319] = 0.0;
   out_7820924518988244848[320] = 0.0;
   out_7820924518988244848[321] = 0.0;
   out_7820924518988244848[322] = 0.0;
   out_7820924518988244848[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5896986433657445748) {
   out_5896986433657445748[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5896986433657445748[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5896986433657445748[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5896986433657445748[3] = dt*state[12] + state[3];
   out_5896986433657445748[4] = dt*state[13] + state[4];
   out_5896986433657445748[5] = dt*state[14] + state[5];
   out_5896986433657445748[6] = state[6];
   out_5896986433657445748[7] = state[7];
   out_5896986433657445748[8] = state[8];
   out_5896986433657445748[9] = state[9];
   out_5896986433657445748[10] = state[10];
   out_5896986433657445748[11] = state[11];
   out_5896986433657445748[12] = state[12];
   out_5896986433657445748[13] = state[13];
   out_5896986433657445748[14] = state[14];
   out_5896986433657445748[15] = state[15];
   out_5896986433657445748[16] = state[16];
   out_5896986433657445748[17] = state[17];
}
void F_fun(double *state, double dt, double *out_9070954291872551139) {
   out_9070954291872551139[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9070954291872551139[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9070954291872551139[2] = 0;
   out_9070954291872551139[3] = 0;
   out_9070954291872551139[4] = 0;
   out_9070954291872551139[5] = 0;
   out_9070954291872551139[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9070954291872551139[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9070954291872551139[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9070954291872551139[9] = 0;
   out_9070954291872551139[10] = 0;
   out_9070954291872551139[11] = 0;
   out_9070954291872551139[12] = 0;
   out_9070954291872551139[13] = 0;
   out_9070954291872551139[14] = 0;
   out_9070954291872551139[15] = 0;
   out_9070954291872551139[16] = 0;
   out_9070954291872551139[17] = 0;
   out_9070954291872551139[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9070954291872551139[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9070954291872551139[20] = 0;
   out_9070954291872551139[21] = 0;
   out_9070954291872551139[22] = 0;
   out_9070954291872551139[23] = 0;
   out_9070954291872551139[24] = 0;
   out_9070954291872551139[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9070954291872551139[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9070954291872551139[27] = 0;
   out_9070954291872551139[28] = 0;
   out_9070954291872551139[29] = 0;
   out_9070954291872551139[30] = 0;
   out_9070954291872551139[31] = 0;
   out_9070954291872551139[32] = 0;
   out_9070954291872551139[33] = 0;
   out_9070954291872551139[34] = 0;
   out_9070954291872551139[35] = 0;
   out_9070954291872551139[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9070954291872551139[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9070954291872551139[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9070954291872551139[39] = 0;
   out_9070954291872551139[40] = 0;
   out_9070954291872551139[41] = 0;
   out_9070954291872551139[42] = 0;
   out_9070954291872551139[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9070954291872551139[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9070954291872551139[45] = 0;
   out_9070954291872551139[46] = 0;
   out_9070954291872551139[47] = 0;
   out_9070954291872551139[48] = 0;
   out_9070954291872551139[49] = 0;
   out_9070954291872551139[50] = 0;
   out_9070954291872551139[51] = 0;
   out_9070954291872551139[52] = 0;
   out_9070954291872551139[53] = 0;
   out_9070954291872551139[54] = 0;
   out_9070954291872551139[55] = 0;
   out_9070954291872551139[56] = 0;
   out_9070954291872551139[57] = 1;
   out_9070954291872551139[58] = 0;
   out_9070954291872551139[59] = 0;
   out_9070954291872551139[60] = 0;
   out_9070954291872551139[61] = 0;
   out_9070954291872551139[62] = 0;
   out_9070954291872551139[63] = 0;
   out_9070954291872551139[64] = 0;
   out_9070954291872551139[65] = 0;
   out_9070954291872551139[66] = dt;
   out_9070954291872551139[67] = 0;
   out_9070954291872551139[68] = 0;
   out_9070954291872551139[69] = 0;
   out_9070954291872551139[70] = 0;
   out_9070954291872551139[71] = 0;
   out_9070954291872551139[72] = 0;
   out_9070954291872551139[73] = 0;
   out_9070954291872551139[74] = 0;
   out_9070954291872551139[75] = 0;
   out_9070954291872551139[76] = 1;
   out_9070954291872551139[77] = 0;
   out_9070954291872551139[78] = 0;
   out_9070954291872551139[79] = 0;
   out_9070954291872551139[80] = 0;
   out_9070954291872551139[81] = 0;
   out_9070954291872551139[82] = 0;
   out_9070954291872551139[83] = 0;
   out_9070954291872551139[84] = 0;
   out_9070954291872551139[85] = dt;
   out_9070954291872551139[86] = 0;
   out_9070954291872551139[87] = 0;
   out_9070954291872551139[88] = 0;
   out_9070954291872551139[89] = 0;
   out_9070954291872551139[90] = 0;
   out_9070954291872551139[91] = 0;
   out_9070954291872551139[92] = 0;
   out_9070954291872551139[93] = 0;
   out_9070954291872551139[94] = 0;
   out_9070954291872551139[95] = 1;
   out_9070954291872551139[96] = 0;
   out_9070954291872551139[97] = 0;
   out_9070954291872551139[98] = 0;
   out_9070954291872551139[99] = 0;
   out_9070954291872551139[100] = 0;
   out_9070954291872551139[101] = 0;
   out_9070954291872551139[102] = 0;
   out_9070954291872551139[103] = 0;
   out_9070954291872551139[104] = dt;
   out_9070954291872551139[105] = 0;
   out_9070954291872551139[106] = 0;
   out_9070954291872551139[107] = 0;
   out_9070954291872551139[108] = 0;
   out_9070954291872551139[109] = 0;
   out_9070954291872551139[110] = 0;
   out_9070954291872551139[111] = 0;
   out_9070954291872551139[112] = 0;
   out_9070954291872551139[113] = 0;
   out_9070954291872551139[114] = 1;
   out_9070954291872551139[115] = 0;
   out_9070954291872551139[116] = 0;
   out_9070954291872551139[117] = 0;
   out_9070954291872551139[118] = 0;
   out_9070954291872551139[119] = 0;
   out_9070954291872551139[120] = 0;
   out_9070954291872551139[121] = 0;
   out_9070954291872551139[122] = 0;
   out_9070954291872551139[123] = 0;
   out_9070954291872551139[124] = 0;
   out_9070954291872551139[125] = 0;
   out_9070954291872551139[126] = 0;
   out_9070954291872551139[127] = 0;
   out_9070954291872551139[128] = 0;
   out_9070954291872551139[129] = 0;
   out_9070954291872551139[130] = 0;
   out_9070954291872551139[131] = 0;
   out_9070954291872551139[132] = 0;
   out_9070954291872551139[133] = 1;
   out_9070954291872551139[134] = 0;
   out_9070954291872551139[135] = 0;
   out_9070954291872551139[136] = 0;
   out_9070954291872551139[137] = 0;
   out_9070954291872551139[138] = 0;
   out_9070954291872551139[139] = 0;
   out_9070954291872551139[140] = 0;
   out_9070954291872551139[141] = 0;
   out_9070954291872551139[142] = 0;
   out_9070954291872551139[143] = 0;
   out_9070954291872551139[144] = 0;
   out_9070954291872551139[145] = 0;
   out_9070954291872551139[146] = 0;
   out_9070954291872551139[147] = 0;
   out_9070954291872551139[148] = 0;
   out_9070954291872551139[149] = 0;
   out_9070954291872551139[150] = 0;
   out_9070954291872551139[151] = 0;
   out_9070954291872551139[152] = 1;
   out_9070954291872551139[153] = 0;
   out_9070954291872551139[154] = 0;
   out_9070954291872551139[155] = 0;
   out_9070954291872551139[156] = 0;
   out_9070954291872551139[157] = 0;
   out_9070954291872551139[158] = 0;
   out_9070954291872551139[159] = 0;
   out_9070954291872551139[160] = 0;
   out_9070954291872551139[161] = 0;
   out_9070954291872551139[162] = 0;
   out_9070954291872551139[163] = 0;
   out_9070954291872551139[164] = 0;
   out_9070954291872551139[165] = 0;
   out_9070954291872551139[166] = 0;
   out_9070954291872551139[167] = 0;
   out_9070954291872551139[168] = 0;
   out_9070954291872551139[169] = 0;
   out_9070954291872551139[170] = 0;
   out_9070954291872551139[171] = 1;
   out_9070954291872551139[172] = 0;
   out_9070954291872551139[173] = 0;
   out_9070954291872551139[174] = 0;
   out_9070954291872551139[175] = 0;
   out_9070954291872551139[176] = 0;
   out_9070954291872551139[177] = 0;
   out_9070954291872551139[178] = 0;
   out_9070954291872551139[179] = 0;
   out_9070954291872551139[180] = 0;
   out_9070954291872551139[181] = 0;
   out_9070954291872551139[182] = 0;
   out_9070954291872551139[183] = 0;
   out_9070954291872551139[184] = 0;
   out_9070954291872551139[185] = 0;
   out_9070954291872551139[186] = 0;
   out_9070954291872551139[187] = 0;
   out_9070954291872551139[188] = 0;
   out_9070954291872551139[189] = 0;
   out_9070954291872551139[190] = 1;
   out_9070954291872551139[191] = 0;
   out_9070954291872551139[192] = 0;
   out_9070954291872551139[193] = 0;
   out_9070954291872551139[194] = 0;
   out_9070954291872551139[195] = 0;
   out_9070954291872551139[196] = 0;
   out_9070954291872551139[197] = 0;
   out_9070954291872551139[198] = 0;
   out_9070954291872551139[199] = 0;
   out_9070954291872551139[200] = 0;
   out_9070954291872551139[201] = 0;
   out_9070954291872551139[202] = 0;
   out_9070954291872551139[203] = 0;
   out_9070954291872551139[204] = 0;
   out_9070954291872551139[205] = 0;
   out_9070954291872551139[206] = 0;
   out_9070954291872551139[207] = 0;
   out_9070954291872551139[208] = 0;
   out_9070954291872551139[209] = 1;
   out_9070954291872551139[210] = 0;
   out_9070954291872551139[211] = 0;
   out_9070954291872551139[212] = 0;
   out_9070954291872551139[213] = 0;
   out_9070954291872551139[214] = 0;
   out_9070954291872551139[215] = 0;
   out_9070954291872551139[216] = 0;
   out_9070954291872551139[217] = 0;
   out_9070954291872551139[218] = 0;
   out_9070954291872551139[219] = 0;
   out_9070954291872551139[220] = 0;
   out_9070954291872551139[221] = 0;
   out_9070954291872551139[222] = 0;
   out_9070954291872551139[223] = 0;
   out_9070954291872551139[224] = 0;
   out_9070954291872551139[225] = 0;
   out_9070954291872551139[226] = 0;
   out_9070954291872551139[227] = 0;
   out_9070954291872551139[228] = 1;
   out_9070954291872551139[229] = 0;
   out_9070954291872551139[230] = 0;
   out_9070954291872551139[231] = 0;
   out_9070954291872551139[232] = 0;
   out_9070954291872551139[233] = 0;
   out_9070954291872551139[234] = 0;
   out_9070954291872551139[235] = 0;
   out_9070954291872551139[236] = 0;
   out_9070954291872551139[237] = 0;
   out_9070954291872551139[238] = 0;
   out_9070954291872551139[239] = 0;
   out_9070954291872551139[240] = 0;
   out_9070954291872551139[241] = 0;
   out_9070954291872551139[242] = 0;
   out_9070954291872551139[243] = 0;
   out_9070954291872551139[244] = 0;
   out_9070954291872551139[245] = 0;
   out_9070954291872551139[246] = 0;
   out_9070954291872551139[247] = 1;
   out_9070954291872551139[248] = 0;
   out_9070954291872551139[249] = 0;
   out_9070954291872551139[250] = 0;
   out_9070954291872551139[251] = 0;
   out_9070954291872551139[252] = 0;
   out_9070954291872551139[253] = 0;
   out_9070954291872551139[254] = 0;
   out_9070954291872551139[255] = 0;
   out_9070954291872551139[256] = 0;
   out_9070954291872551139[257] = 0;
   out_9070954291872551139[258] = 0;
   out_9070954291872551139[259] = 0;
   out_9070954291872551139[260] = 0;
   out_9070954291872551139[261] = 0;
   out_9070954291872551139[262] = 0;
   out_9070954291872551139[263] = 0;
   out_9070954291872551139[264] = 0;
   out_9070954291872551139[265] = 0;
   out_9070954291872551139[266] = 1;
   out_9070954291872551139[267] = 0;
   out_9070954291872551139[268] = 0;
   out_9070954291872551139[269] = 0;
   out_9070954291872551139[270] = 0;
   out_9070954291872551139[271] = 0;
   out_9070954291872551139[272] = 0;
   out_9070954291872551139[273] = 0;
   out_9070954291872551139[274] = 0;
   out_9070954291872551139[275] = 0;
   out_9070954291872551139[276] = 0;
   out_9070954291872551139[277] = 0;
   out_9070954291872551139[278] = 0;
   out_9070954291872551139[279] = 0;
   out_9070954291872551139[280] = 0;
   out_9070954291872551139[281] = 0;
   out_9070954291872551139[282] = 0;
   out_9070954291872551139[283] = 0;
   out_9070954291872551139[284] = 0;
   out_9070954291872551139[285] = 1;
   out_9070954291872551139[286] = 0;
   out_9070954291872551139[287] = 0;
   out_9070954291872551139[288] = 0;
   out_9070954291872551139[289] = 0;
   out_9070954291872551139[290] = 0;
   out_9070954291872551139[291] = 0;
   out_9070954291872551139[292] = 0;
   out_9070954291872551139[293] = 0;
   out_9070954291872551139[294] = 0;
   out_9070954291872551139[295] = 0;
   out_9070954291872551139[296] = 0;
   out_9070954291872551139[297] = 0;
   out_9070954291872551139[298] = 0;
   out_9070954291872551139[299] = 0;
   out_9070954291872551139[300] = 0;
   out_9070954291872551139[301] = 0;
   out_9070954291872551139[302] = 0;
   out_9070954291872551139[303] = 0;
   out_9070954291872551139[304] = 1;
   out_9070954291872551139[305] = 0;
   out_9070954291872551139[306] = 0;
   out_9070954291872551139[307] = 0;
   out_9070954291872551139[308] = 0;
   out_9070954291872551139[309] = 0;
   out_9070954291872551139[310] = 0;
   out_9070954291872551139[311] = 0;
   out_9070954291872551139[312] = 0;
   out_9070954291872551139[313] = 0;
   out_9070954291872551139[314] = 0;
   out_9070954291872551139[315] = 0;
   out_9070954291872551139[316] = 0;
   out_9070954291872551139[317] = 0;
   out_9070954291872551139[318] = 0;
   out_9070954291872551139[319] = 0;
   out_9070954291872551139[320] = 0;
   out_9070954291872551139[321] = 0;
   out_9070954291872551139[322] = 0;
   out_9070954291872551139[323] = 1;
}
void h_4(double *state, double *unused, double *out_465271435169248184) {
   out_465271435169248184[0] = state[6] + state[9];
   out_465271435169248184[1] = state[7] + state[10];
   out_465271435169248184[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5473301169682226033) {
   out_5473301169682226033[0] = 0;
   out_5473301169682226033[1] = 0;
   out_5473301169682226033[2] = 0;
   out_5473301169682226033[3] = 0;
   out_5473301169682226033[4] = 0;
   out_5473301169682226033[5] = 0;
   out_5473301169682226033[6] = 1;
   out_5473301169682226033[7] = 0;
   out_5473301169682226033[8] = 0;
   out_5473301169682226033[9] = 1;
   out_5473301169682226033[10] = 0;
   out_5473301169682226033[11] = 0;
   out_5473301169682226033[12] = 0;
   out_5473301169682226033[13] = 0;
   out_5473301169682226033[14] = 0;
   out_5473301169682226033[15] = 0;
   out_5473301169682226033[16] = 0;
   out_5473301169682226033[17] = 0;
   out_5473301169682226033[18] = 0;
   out_5473301169682226033[19] = 0;
   out_5473301169682226033[20] = 0;
   out_5473301169682226033[21] = 0;
   out_5473301169682226033[22] = 0;
   out_5473301169682226033[23] = 0;
   out_5473301169682226033[24] = 0;
   out_5473301169682226033[25] = 1;
   out_5473301169682226033[26] = 0;
   out_5473301169682226033[27] = 0;
   out_5473301169682226033[28] = 1;
   out_5473301169682226033[29] = 0;
   out_5473301169682226033[30] = 0;
   out_5473301169682226033[31] = 0;
   out_5473301169682226033[32] = 0;
   out_5473301169682226033[33] = 0;
   out_5473301169682226033[34] = 0;
   out_5473301169682226033[35] = 0;
   out_5473301169682226033[36] = 0;
   out_5473301169682226033[37] = 0;
   out_5473301169682226033[38] = 0;
   out_5473301169682226033[39] = 0;
   out_5473301169682226033[40] = 0;
   out_5473301169682226033[41] = 0;
   out_5473301169682226033[42] = 0;
   out_5473301169682226033[43] = 0;
   out_5473301169682226033[44] = 1;
   out_5473301169682226033[45] = 0;
   out_5473301169682226033[46] = 0;
   out_5473301169682226033[47] = 1;
   out_5473301169682226033[48] = 0;
   out_5473301169682226033[49] = 0;
   out_5473301169682226033[50] = 0;
   out_5473301169682226033[51] = 0;
   out_5473301169682226033[52] = 0;
   out_5473301169682226033[53] = 0;
}
void h_10(double *state, double *unused, double *out_7120793259445942863) {
   out_7120793259445942863[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7120793259445942863[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7120793259445942863[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4773805674865799228) {
   out_4773805674865799228[0] = 0;
   out_4773805674865799228[1] = 9.8100000000000005*cos(state[1]);
   out_4773805674865799228[2] = 0;
   out_4773805674865799228[3] = 0;
   out_4773805674865799228[4] = -state[8];
   out_4773805674865799228[5] = state[7];
   out_4773805674865799228[6] = 0;
   out_4773805674865799228[7] = state[5];
   out_4773805674865799228[8] = -state[4];
   out_4773805674865799228[9] = 0;
   out_4773805674865799228[10] = 0;
   out_4773805674865799228[11] = 0;
   out_4773805674865799228[12] = 1;
   out_4773805674865799228[13] = 0;
   out_4773805674865799228[14] = 0;
   out_4773805674865799228[15] = 1;
   out_4773805674865799228[16] = 0;
   out_4773805674865799228[17] = 0;
   out_4773805674865799228[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4773805674865799228[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4773805674865799228[20] = 0;
   out_4773805674865799228[21] = state[8];
   out_4773805674865799228[22] = 0;
   out_4773805674865799228[23] = -state[6];
   out_4773805674865799228[24] = -state[5];
   out_4773805674865799228[25] = 0;
   out_4773805674865799228[26] = state[3];
   out_4773805674865799228[27] = 0;
   out_4773805674865799228[28] = 0;
   out_4773805674865799228[29] = 0;
   out_4773805674865799228[30] = 0;
   out_4773805674865799228[31] = 1;
   out_4773805674865799228[32] = 0;
   out_4773805674865799228[33] = 0;
   out_4773805674865799228[34] = 1;
   out_4773805674865799228[35] = 0;
   out_4773805674865799228[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4773805674865799228[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4773805674865799228[38] = 0;
   out_4773805674865799228[39] = -state[7];
   out_4773805674865799228[40] = state[6];
   out_4773805674865799228[41] = 0;
   out_4773805674865799228[42] = state[4];
   out_4773805674865799228[43] = -state[3];
   out_4773805674865799228[44] = 0;
   out_4773805674865799228[45] = 0;
   out_4773805674865799228[46] = 0;
   out_4773805674865799228[47] = 0;
   out_4773805674865799228[48] = 0;
   out_4773805674865799228[49] = 0;
   out_4773805674865799228[50] = 1;
   out_4773805674865799228[51] = 0;
   out_4773805674865799228[52] = 0;
   out_4773805674865799228[53] = 1;
}
void h_13(double *state, double *unused, double *out_9068625888459029095) {
   out_9068625888459029095[0] = state[3];
   out_9068625888459029095[1] = state[4];
   out_9068625888459029095[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2261027344349893232) {
   out_2261027344349893232[0] = 0;
   out_2261027344349893232[1] = 0;
   out_2261027344349893232[2] = 0;
   out_2261027344349893232[3] = 1;
   out_2261027344349893232[4] = 0;
   out_2261027344349893232[5] = 0;
   out_2261027344349893232[6] = 0;
   out_2261027344349893232[7] = 0;
   out_2261027344349893232[8] = 0;
   out_2261027344349893232[9] = 0;
   out_2261027344349893232[10] = 0;
   out_2261027344349893232[11] = 0;
   out_2261027344349893232[12] = 0;
   out_2261027344349893232[13] = 0;
   out_2261027344349893232[14] = 0;
   out_2261027344349893232[15] = 0;
   out_2261027344349893232[16] = 0;
   out_2261027344349893232[17] = 0;
   out_2261027344349893232[18] = 0;
   out_2261027344349893232[19] = 0;
   out_2261027344349893232[20] = 0;
   out_2261027344349893232[21] = 0;
   out_2261027344349893232[22] = 1;
   out_2261027344349893232[23] = 0;
   out_2261027344349893232[24] = 0;
   out_2261027344349893232[25] = 0;
   out_2261027344349893232[26] = 0;
   out_2261027344349893232[27] = 0;
   out_2261027344349893232[28] = 0;
   out_2261027344349893232[29] = 0;
   out_2261027344349893232[30] = 0;
   out_2261027344349893232[31] = 0;
   out_2261027344349893232[32] = 0;
   out_2261027344349893232[33] = 0;
   out_2261027344349893232[34] = 0;
   out_2261027344349893232[35] = 0;
   out_2261027344349893232[36] = 0;
   out_2261027344349893232[37] = 0;
   out_2261027344349893232[38] = 0;
   out_2261027344349893232[39] = 0;
   out_2261027344349893232[40] = 0;
   out_2261027344349893232[41] = 1;
   out_2261027344349893232[42] = 0;
   out_2261027344349893232[43] = 0;
   out_2261027344349893232[44] = 0;
   out_2261027344349893232[45] = 0;
   out_2261027344349893232[46] = 0;
   out_2261027344349893232[47] = 0;
   out_2261027344349893232[48] = 0;
   out_2261027344349893232[49] = 0;
   out_2261027344349893232[50] = 0;
   out_2261027344349893232[51] = 0;
   out_2261027344349893232[52] = 0;
   out_2261027344349893232[53] = 0;
}
void h_14(double *state, double *unused, double *out_1147034822821919030) {
   out_1147034822821919030[0] = state[6];
   out_1147034822821919030[1] = state[7];
   out_1147034822821919030[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5908417696327109632) {
   out_5908417696327109632[0] = 0;
   out_5908417696327109632[1] = 0;
   out_5908417696327109632[2] = 0;
   out_5908417696327109632[3] = 0;
   out_5908417696327109632[4] = 0;
   out_5908417696327109632[5] = 0;
   out_5908417696327109632[6] = 1;
   out_5908417696327109632[7] = 0;
   out_5908417696327109632[8] = 0;
   out_5908417696327109632[9] = 0;
   out_5908417696327109632[10] = 0;
   out_5908417696327109632[11] = 0;
   out_5908417696327109632[12] = 0;
   out_5908417696327109632[13] = 0;
   out_5908417696327109632[14] = 0;
   out_5908417696327109632[15] = 0;
   out_5908417696327109632[16] = 0;
   out_5908417696327109632[17] = 0;
   out_5908417696327109632[18] = 0;
   out_5908417696327109632[19] = 0;
   out_5908417696327109632[20] = 0;
   out_5908417696327109632[21] = 0;
   out_5908417696327109632[22] = 0;
   out_5908417696327109632[23] = 0;
   out_5908417696327109632[24] = 0;
   out_5908417696327109632[25] = 1;
   out_5908417696327109632[26] = 0;
   out_5908417696327109632[27] = 0;
   out_5908417696327109632[28] = 0;
   out_5908417696327109632[29] = 0;
   out_5908417696327109632[30] = 0;
   out_5908417696327109632[31] = 0;
   out_5908417696327109632[32] = 0;
   out_5908417696327109632[33] = 0;
   out_5908417696327109632[34] = 0;
   out_5908417696327109632[35] = 0;
   out_5908417696327109632[36] = 0;
   out_5908417696327109632[37] = 0;
   out_5908417696327109632[38] = 0;
   out_5908417696327109632[39] = 0;
   out_5908417696327109632[40] = 0;
   out_5908417696327109632[41] = 0;
   out_5908417696327109632[42] = 0;
   out_5908417696327109632[43] = 0;
   out_5908417696327109632[44] = 1;
   out_5908417696327109632[45] = 0;
   out_5908417696327109632[46] = 0;
   out_5908417696327109632[47] = 0;
   out_5908417696327109632[48] = 0;
   out_5908417696327109632[49] = 0;
   out_5908417696327109632[50] = 0;
   out_5908417696327109632[51] = 0;
   out_5908417696327109632[52] = 0;
   out_5908417696327109632[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3039420483993860343) {
  err_fun(nom_x, delta_x, out_3039420483993860343);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8695657740442878095) {
  inv_err_fun(nom_x, true_x, out_8695657740442878095);
}
void pose_H_mod_fun(double *state, double *out_7820924518988244848) {
  H_mod_fun(state, out_7820924518988244848);
}
void pose_f_fun(double *state, double dt, double *out_5896986433657445748) {
  f_fun(state,  dt, out_5896986433657445748);
}
void pose_F_fun(double *state, double dt, double *out_9070954291872551139) {
  F_fun(state,  dt, out_9070954291872551139);
}
void pose_h_4(double *state, double *unused, double *out_465271435169248184) {
  h_4(state, unused, out_465271435169248184);
}
void pose_H_4(double *state, double *unused, double *out_5473301169682226033) {
  H_4(state, unused, out_5473301169682226033);
}
void pose_h_10(double *state, double *unused, double *out_7120793259445942863) {
  h_10(state, unused, out_7120793259445942863);
}
void pose_H_10(double *state, double *unused, double *out_4773805674865799228) {
  H_10(state, unused, out_4773805674865799228);
}
void pose_h_13(double *state, double *unused, double *out_9068625888459029095) {
  h_13(state, unused, out_9068625888459029095);
}
void pose_H_13(double *state, double *unused, double *out_2261027344349893232) {
  H_13(state, unused, out_2261027344349893232);
}
void pose_h_14(double *state, double *unused, double *out_1147034822821919030) {
  h_14(state, unused, out_1147034822821919030);
}
void pose_H_14(double *state, double *unused, double *out_5908417696327109632) {
  H_14(state, unused, out_5908417696327109632);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
