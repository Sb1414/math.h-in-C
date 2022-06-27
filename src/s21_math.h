#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_EPSEQ 1e-17
#define s21_NaN 0.0 / 0.0
#define s21_NEAR_ZERO 1E-15
#define s21_NEG_NaN -0.0 / 0.0
#define s21_INFINITY 1.0 / 0.0
#define s21_NEG_INFINITY -1.0 / 0.0
#define s21_NEG_PI -3.1415926535897932
#define s21_MAX_DOUBLE 9007199254740990
#define s21_LN10 2.30258509299404590109
#define s21_PI 3.14159265358979323846264338327950288

typedef struct {
    int e;
    int sign;
    long double mant;
} parametrs;

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double common(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double log_big_zero_min_two(double x);
void alg(double x, parametrs *param);
long double log_oth(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_
