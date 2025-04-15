#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8544072379141929842);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_575509770703173388);
void car_H_mod_fun(double *state, double *out_4067700316453588280);
void car_f_fun(double *state, double dt, double *out_7035847373951105392);
void car_F_fun(double *state, double dt, double *out_8058880950702710154);
void car_h_25(double *state, double *unused, double *out_4978326154836552473);
void car_H_25(double *state, double *unused, double *out_8971392141638253120);
void car_h_24(double *state, double *unused, double *out_5436580866969982380);
void car_H_24(double *state, double *unused, double *out_2899780125479780395);
void car_h_30(double *state, double *unused, double *out_4703132092552046584);
void car_H_30(double *state, double *unused, double *out_6957018973564049869);
void car_h_26(double *state, double *unused, double *out_8741938713496659387);
void car_H_26(double *state, double *unused, double *out_5229888822764196896);
void car_h_27(double *state, double *unused, double *out_5921836007738214908);
void car_H_27(double *state, double *unused, double *out_6667289882694588139);
void car_h_29(double *state, double *unused, double *out_298541175108799061);
void car_H_29(double *state, double *unused, double *out_4953927155825037106);
void car_h_28(double *state, double *unused, double *out_8526241328546912559);
void car_H_28(double *state, double *unused, double *out_6917557427390363357);
void car_h_31(double *state, double *unused, double *out_7312970723032339014);
void car_H_31(double *state, double *unused, double *out_9002038103515213548);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}