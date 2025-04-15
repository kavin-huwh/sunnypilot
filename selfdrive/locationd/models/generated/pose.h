#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3039420483993860343);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8695657740442878095);
void pose_H_mod_fun(double *state, double *out_7820924518988244848);
void pose_f_fun(double *state, double dt, double *out_5896986433657445748);
void pose_F_fun(double *state, double dt, double *out_9070954291872551139);
void pose_h_4(double *state, double *unused, double *out_465271435169248184);
void pose_H_4(double *state, double *unused, double *out_5473301169682226033);
void pose_h_10(double *state, double *unused, double *out_7120793259445942863);
void pose_H_10(double *state, double *unused, double *out_4773805674865799228);
void pose_h_13(double *state, double *unused, double *out_9068625888459029095);
void pose_H_13(double *state, double *unused, double *out_2261027344349893232);
void pose_h_14(double *state, double *unused, double *out_1147034822821919030);
void pose_H_14(double *state, double *unused, double *out_5908417696327109632);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}