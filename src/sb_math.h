#ifndef SRC_SB_MATH_H_
#define SRC_SB_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define sb_EPSEQ 1e-17
#define sb_NaN 0.0 / 0.0
#define sb_NEAR_ZERO 1E-15
#define sb_NEG_NaN -0.0 / 0.0
#define sb_INFINITY 1.0 / 0.0
#define sb_NEG_INFINITY -1.0 / 0.0
#define sb_NEG_PI -3.1415926535897932
#define sb_MAX_DOUBLE 9007199254740990
#define sb_LN10 2.30258509299404590109
#define sb_PI 3.14159265358979323846264338327950288

typedef struct {
    int e;
    int sign;
    long double mant;
} parametrs;

int sb_abs(int x);
long double sb_acos(double x);
long double sb_asin(double x);
long double common(double x);
long double sb_atan(double x);
long double sb_ceil(double x);
long double sb_cos(double x);
long double sb_exp(double x);
long double sb_fabs(double x);
long double sb_floor(double x);
long double sb_fmod(double x, double y);
long double log_big_zero_min_two(double x);
void alg(double x, parametrs *param);
long double log_oth(double x);
long double sb_log(double x);
long double sb_pow(double base, double exp);
long double sb_sin(double x);
long double sb_sqrt(double x);
long double sb_tan(double x);

#endif  // SRC_SB_MATH_H_
