#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8544072379141929842) {
   out_8544072379141929842[0] = delta_x[0] + nom_x[0];
   out_8544072379141929842[1] = delta_x[1] + nom_x[1];
   out_8544072379141929842[2] = delta_x[2] + nom_x[2];
   out_8544072379141929842[3] = delta_x[3] + nom_x[3];
   out_8544072379141929842[4] = delta_x[4] + nom_x[4];
   out_8544072379141929842[5] = delta_x[5] + nom_x[5];
   out_8544072379141929842[6] = delta_x[6] + nom_x[6];
   out_8544072379141929842[7] = delta_x[7] + nom_x[7];
   out_8544072379141929842[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_575509770703173388) {
   out_575509770703173388[0] = -nom_x[0] + true_x[0];
   out_575509770703173388[1] = -nom_x[1] + true_x[1];
   out_575509770703173388[2] = -nom_x[2] + true_x[2];
   out_575509770703173388[3] = -nom_x[3] + true_x[3];
   out_575509770703173388[4] = -nom_x[4] + true_x[4];
   out_575509770703173388[5] = -nom_x[5] + true_x[5];
   out_575509770703173388[6] = -nom_x[6] + true_x[6];
   out_575509770703173388[7] = -nom_x[7] + true_x[7];
   out_575509770703173388[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4067700316453588280) {
   out_4067700316453588280[0] = 1.0;
   out_4067700316453588280[1] = 0.0;
   out_4067700316453588280[2] = 0.0;
   out_4067700316453588280[3] = 0.0;
   out_4067700316453588280[4] = 0.0;
   out_4067700316453588280[5] = 0.0;
   out_4067700316453588280[6] = 0.0;
   out_4067700316453588280[7] = 0.0;
   out_4067700316453588280[8] = 0.0;
   out_4067700316453588280[9] = 0.0;
   out_4067700316453588280[10] = 1.0;
   out_4067700316453588280[11] = 0.0;
   out_4067700316453588280[12] = 0.0;
   out_4067700316453588280[13] = 0.0;
   out_4067700316453588280[14] = 0.0;
   out_4067700316453588280[15] = 0.0;
   out_4067700316453588280[16] = 0.0;
   out_4067700316453588280[17] = 0.0;
   out_4067700316453588280[18] = 0.0;
   out_4067700316453588280[19] = 0.0;
   out_4067700316453588280[20] = 1.0;
   out_4067700316453588280[21] = 0.0;
   out_4067700316453588280[22] = 0.0;
   out_4067700316453588280[23] = 0.0;
   out_4067700316453588280[24] = 0.0;
   out_4067700316453588280[25] = 0.0;
   out_4067700316453588280[26] = 0.0;
   out_4067700316453588280[27] = 0.0;
   out_4067700316453588280[28] = 0.0;
   out_4067700316453588280[29] = 0.0;
   out_4067700316453588280[30] = 1.0;
   out_4067700316453588280[31] = 0.0;
   out_4067700316453588280[32] = 0.0;
   out_4067700316453588280[33] = 0.0;
   out_4067700316453588280[34] = 0.0;
   out_4067700316453588280[35] = 0.0;
   out_4067700316453588280[36] = 0.0;
   out_4067700316453588280[37] = 0.0;
   out_4067700316453588280[38] = 0.0;
   out_4067700316453588280[39] = 0.0;
   out_4067700316453588280[40] = 1.0;
   out_4067700316453588280[41] = 0.0;
   out_4067700316453588280[42] = 0.0;
   out_4067700316453588280[43] = 0.0;
   out_4067700316453588280[44] = 0.0;
   out_4067700316453588280[45] = 0.0;
   out_4067700316453588280[46] = 0.0;
   out_4067700316453588280[47] = 0.0;
   out_4067700316453588280[48] = 0.0;
   out_4067700316453588280[49] = 0.0;
   out_4067700316453588280[50] = 1.0;
   out_4067700316453588280[51] = 0.0;
   out_4067700316453588280[52] = 0.0;
   out_4067700316453588280[53] = 0.0;
   out_4067700316453588280[54] = 0.0;
   out_4067700316453588280[55] = 0.0;
   out_4067700316453588280[56] = 0.0;
   out_4067700316453588280[57] = 0.0;
   out_4067700316453588280[58] = 0.0;
   out_4067700316453588280[59] = 0.0;
   out_4067700316453588280[60] = 1.0;
   out_4067700316453588280[61] = 0.0;
   out_4067700316453588280[62] = 0.0;
   out_4067700316453588280[63] = 0.0;
   out_4067700316453588280[64] = 0.0;
   out_4067700316453588280[65] = 0.0;
   out_4067700316453588280[66] = 0.0;
   out_4067700316453588280[67] = 0.0;
   out_4067700316453588280[68] = 0.0;
   out_4067700316453588280[69] = 0.0;
   out_4067700316453588280[70] = 1.0;
   out_4067700316453588280[71] = 0.0;
   out_4067700316453588280[72] = 0.0;
   out_4067700316453588280[73] = 0.0;
   out_4067700316453588280[74] = 0.0;
   out_4067700316453588280[75] = 0.0;
   out_4067700316453588280[76] = 0.0;
   out_4067700316453588280[77] = 0.0;
   out_4067700316453588280[78] = 0.0;
   out_4067700316453588280[79] = 0.0;
   out_4067700316453588280[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7035847373951105392) {
   out_7035847373951105392[0] = state[0];
   out_7035847373951105392[1] = state[1];
   out_7035847373951105392[2] = state[2];
   out_7035847373951105392[3] = state[3];
   out_7035847373951105392[4] = state[4];
   out_7035847373951105392[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7035847373951105392[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7035847373951105392[7] = state[7];
   out_7035847373951105392[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8058880950702710154) {
   out_8058880950702710154[0] = 1;
   out_8058880950702710154[1] = 0;
   out_8058880950702710154[2] = 0;
   out_8058880950702710154[3] = 0;
   out_8058880950702710154[4] = 0;
   out_8058880950702710154[5] = 0;
   out_8058880950702710154[6] = 0;
   out_8058880950702710154[7] = 0;
   out_8058880950702710154[8] = 0;
   out_8058880950702710154[9] = 0;
   out_8058880950702710154[10] = 1;
   out_8058880950702710154[11] = 0;
   out_8058880950702710154[12] = 0;
   out_8058880950702710154[13] = 0;
   out_8058880950702710154[14] = 0;
   out_8058880950702710154[15] = 0;
   out_8058880950702710154[16] = 0;
   out_8058880950702710154[17] = 0;
   out_8058880950702710154[18] = 0;
   out_8058880950702710154[19] = 0;
   out_8058880950702710154[20] = 1;
   out_8058880950702710154[21] = 0;
   out_8058880950702710154[22] = 0;
   out_8058880950702710154[23] = 0;
   out_8058880950702710154[24] = 0;
   out_8058880950702710154[25] = 0;
   out_8058880950702710154[26] = 0;
   out_8058880950702710154[27] = 0;
   out_8058880950702710154[28] = 0;
   out_8058880950702710154[29] = 0;
   out_8058880950702710154[30] = 1;
   out_8058880950702710154[31] = 0;
   out_8058880950702710154[32] = 0;
   out_8058880950702710154[33] = 0;
   out_8058880950702710154[34] = 0;
   out_8058880950702710154[35] = 0;
   out_8058880950702710154[36] = 0;
   out_8058880950702710154[37] = 0;
   out_8058880950702710154[38] = 0;
   out_8058880950702710154[39] = 0;
   out_8058880950702710154[40] = 1;
   out_8058880950702710154[41] = 0;
   out_8058880950702710154[42] = 0;
   out_8058880950702710154[43] = 0;
   out_8058880950702710154[44] = 0;
   out_8058880950702710154[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8058880950702710154[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8058880950702710154[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8058880950702710154[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8058880950702710154[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8058880950702710154[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8058880950702710154[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8058880950702710154[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8058880950702710154[53] = -9.8000000000000007*dt;
   out_8058880950702710154[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8058880950702710154[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8058880950702710154[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8058880950702710154[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8058880950702710154[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8058880950702710154[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8058880950702710154[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8058880950702710154[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8058880950702710154[62] = 0;
   out_8058880950702710154[63] = 0;
   out_8058880950702710154[64] = 0;
   out_8058880950702710154[65] = 0;
   out_8058880950702710154[66] = 0;
   out_8058880950702710154[67] = 0;
   out_8058880950702710154[68] = 0;
   out_8058880950702710154[69] = 0;
   out_8058880950702710154[70] = 1;
   out_8058880950702710154[71] = 0;
   out_8058880950702710154[72] = 0;
   out_8058880950702710154[73] = 0;
   out_8058880950702710154[74] = 0;
   out_8058880950702710154[75] = 0;
   out_8058880950702710154[76] = 0;
   out_8058880950702710154[77] = 0;
   out_8058880950702710154[78] = 0;
   out_8058880950702710154[79] = 0;
   out_8058880950702710154[80] = 1;
}
void h_25(double *state, double *unused, double *out_4978326154836552473) {
   out_4978326154836552473[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8971392141638253120) {
   out_8971392141638253120[0] = 0;
   out_8971392141638253120[1] = 0;
   out_8971392141638253120[2] = 0;
   out_8971392141638253120[3] = 0;
   out_8971392141638253120[4] = 0;
   out_8971392141638253120[5] = 0;
   out_8971392141638253120[6] = 1;
   out_8971392141638253120[7] = 0;
   out_8971392141638253120[8] = 0;
}
void h_24(double *state, double *unused, double *out_5436580866969982380) {
   out_5436580866969982380[0] = state[4];
   out_5436580866969982380[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2899780125479780395) {
   out_2899780125479780395[0] = 0;
   out_2899780125479780395[1] = 0;
   out_2899780125479780395[2] = 0;
   out_2899780125479780395[3] = 0;
   out_2899780125479780395[4] = 1;
   out_2899780125479780395[5] = 0;
   out_2899780125479780395[6] = 0;
   out_2899780125479780395[7] = 0;
   out_2899780125479780395[8] = 0;
   out_2899780125479780395[9] = 0;
   out_2899780125479780395[10] = 0;
   out_2899780125479780395[11] = 0;
   out_2899780125479780395[12] = 0;
   out_2899780125479780395[13] = 0;
   out_2899780125479780395[14] = 1;
   out_2899780125479780395[15] = 0;
   out_2899780125479780395[16] = 0;
   out_2899780125479780395[17] = 0;
}
void h_30(double *state, double *unused, double *out_4703132092552046584) {
   out_4703132092552046584[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6957018973564049869) {
   out_6957018973564049869[0] = 0;
   out_6957018973564049869[1] = 0;
   out_6957018973564049869[2] = 0;
   out_6957018973564049869[3] = 0;
   out_6957018973564049869[4] = 1;
   out_6957018973564049869[5] = 0;
   out_6957018973564049869[6] = 0;
   out_6957018973564049869[7] = 0;
   out_6957018973564049869[8] = 0;
}
void h_26(double *state, double *unused, double *out_8741938713496659387) {
   out_8741938713496659387[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5229888822764196896) {
   out_5229888822764196896[0] = 0;
   out_5229888822764196896[1] = 0;
   out_5229888822764196896[2] = 0;
   out_5229888822764196896[3] = 0;
   out_5229888822764196896[4] = 0;
   out_5229888822764196896[5] = 0;
   out_5229888822764196896[6] = 0;
   out_5229888822764196896[7] = 1;
   out_5229888822764196896[8] = 0;
}
void h_27(double *state, double *unused, double *out_5921836007738214908) {
   out_5921836007738214908[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6667289882694588139) {
   out_6667289882694588139[0] = 0;
   out_6667289882694588139[1] = 0;
   out_6667289882694588139[2] = 0;
   out_6667289882694588139[3] = 1;
   out_6667289882694588139[4] = 0;
   out_6667289882694588139[5] = 0;
   out_6667289882694588139[6] = 0;
   out_6667289882694588139[7] = 0;
   out_6667289882694588139[8] = 0;
}
void h_29(double *state, double *unused, double *out_298541175108799061) {
   out_298541175108799061[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4953927155825037106) {
   out_4953927155825037106[0] = 0;
   out_4953927155825037106[1] = 1;
   out_4953927155825037106[2] = 0;
   out_4953927155825037106[3] = 0;
   out_4953927155825037106[4] = 0;
   out_4953927155825037106[5] = 0;
   out_4953927155825037106[6] = 0;
   out_4953927155825037106[7] = 0;
   out_4953927155825037106[8] = 0;
}
void h_28(double *state, double *unused, double *out_8526241328546912559) {
   out_8526241328546912559[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6917557427390363357) {
   out_6917557427390363357[0] = 1;
   out_6917557427390363357[1] = 0;
   out_6917557427390363357[2] = 0;
   out_6917557427390363357[3] = 0;
   out_6917557427390363357[4] = 0;
   out_6917557427390363357[5] = 0;
   out_6917557427390363357[6] = 0;
   out_6917557427390363357[7] = 0;
   out_6917557427390363357[8] = 0;
}
void h_31(double *state, double *unused, double *out_7312970723032339014) {
   out_7312970723032339014[0] = state[8];
}
void H_31(double *state, double *unused, double *out_9002038103515213548) {
   out_9002038103515213548[0] = 0;
   out_9002038103515213548[1] = 0;
   out_9002038103515213548[2] = 0;
   out_9002038103515213548[3] = 0;
   out_9002038103515213548[4] = 0;
   out_9002038103515213548[5] = 0;
   out_9002038103515213548[6] = 0;
   out_9002038103515213548[7] = 0;
   out_9002038103515213548[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8544072379141929842) {
  err_fun(nom_x, delta_x, out_8544072379141929842);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_575509770703173388) {
  inv_err_fun(nom_x, true_x, out_575509770703173388);
}
void car_H_mod_fun(double *state, double *out_4067700316453588280) {
  H_mod_fun(state, out_4067700316453588280);
}
void car_f_fun(double *state, double dt, double *out_7035847373951105392) {
  f_fun(state,  dt, out_7035847373951105392);
}
void car_F_fun(double *state, double dt, double *out_8058880950702710154) {
  F_fun(state,  dt, out_8058880950702710154);
}
void car_h_25(double *state, double *unused, double *out_4978326154836552473) {
  h_25(state, unused, out_4978326154836552473);
}
void car_H_25(double *state, double *unused, double *out_8971392141638253120) {
  H_25(state, unused, out_8971392141638253120);
}
void car_h_24(double *state, double *unused, double *out_5436580866969982380) {
  h_24(state, unused, out_5436580866969982380);
}
void car_H_24(double *state, double *unused, double *out_2899780125479780395) {
  H_24(state, unused, out_2899780125479780395);
}
void car_h_30(double *state, double *unused, double *out_4703132092552046584) {
  h_30(state, unused, out_4703132092552046584);
}
void car_H_30(double *state, double *unused, double *out_6957018973564049869) {
  H_30(state, unused, out_6957018973564049869);
}
void car_h_26(double *state, double *unused, double *out_8741938713496659387) {
  h_26(state, unused, out_8741938713496659387);
}
void car_H_26(double *state, double *unused, double *out_5229888822764196896) {
  H_26(state, unused, out_5229888822764196896);
}
void car_h_27(double *state, double *unused, double *out_5921836007738214908) {
  h_27(state, unused, out_5921836007738214908);
}
void car_H_27(double *state, double *unused, double *out_6667289882694588139) {
  H_27(state, unused, out_6667289882694588139);
}
void car_h_29(double *state, double *unused, double *out_298541175108799061) {
  h_29(state, unused, out_298541175108799061);
}
void car_H_29(double *state, double *unused, double *out_4953927155825037106) {
  H_29(state, unused, out_4953927155825037106);
}
void car_h_28(double *state, double *unused, double *out_8526241328546912559) {
  h_28(state, unused, out_8526241328546912559);
}
void car_H_28(double *state, double *unused, double *out_6917557427390363357) {
  H_28(state, unused, out_6917557427390363357);
}
void car_h_31(double *state, double *unused, double *out_7312970723032339014) {
  h_31(state, unused, out_7312970723032339014);
}
void car_H_31(double *state, double *unused, double *out_9002038103515213548) {
  H_31(state, unused, out_9002038103515213548);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
