#include <math.h>
#include <check.h>
#include <stdlib.h>
#include "sb_math.h"

START_TEST(sb_abs_test) {
    for (int i = -1234567; i < 123456; i += 10) {
        ck_assert_int_eq(sb_abs(i), abs(i));
    }
    ck_assert_int_eq(sb_abs(-4), abs(-4));
    ck_assert_int_eq(sb_abs(-123), abs(-123));
} END_TEST

START_TEST(sb_acos_test) {
    for (double i = -10.; i < 10.; i += 1.) {
        ck_assert_uint_eq(sb_acos(i), acos(i));
    }
    for (double i = -1; i < 1; i += 0.01) {
        ck_assert_uint_eq(sb_acos(i), acos(i));
    }
    ck_assert_uint_eq(sb_acos(0.43), acos(0.43));
    ck_assert_uint_eq(sb_acos(-1), acos(-1));
    ck_assert_uint_eq(sb_acos(-0.999), acos(-0.999));
} END_TEST

START_TEST(sb_asin_test) {
    for (double i = 0.; i < 2; i += 1) {
        ck_assert_uint_eq(sb_asin(i), asin(i));
    }
    for (double i = -1; i < 5; i += 0.01) {
        ck_assert_uint_eq(sb_asin(i), asin(i));
    }
    ck_assert_uint_eq(sb_asin(0.43), asin(0.43));
    ck_assert_uint_eq(sb_asin(0.12), asin(0.12));
} END_TEST

START_TEST(sb_atan_test) {
    for (double i = -1; i <= 1; i += 0.01) {
        ck_assert_uint_eq(sb_atan(i), atan(i));
    }
    ck_assert_uint_eq(sb_atan(0.43), atan(0.43));
    ck_assert_uint_eq(sb_atan(0.12), atan(0.12));
    ck_assert_uint_eq(sb_atan(1), atan(1));
    ck_assert_uint_eq(sb_atan(-1), atan(-1));
    ck_assert_uint_eq(sb_atan(0), atan(0));
    ck_assert_uint_eq(sb_atan(12345), atan(12345));
    ck_assert_uint_eq(sb_atan(0.001), atan(0.001));
    ck_assert_ldouble_eq_tol(sb_atan(-1), atan(-1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_atan(-100), atan(-100), 1e-6);
    ck_assert_ldouble_eq_tol(sb_atan(-500000), atan(-500000), 1e-6);
}
END_TEST

START_TEST(sb_ceil_test) {
    ck_assert_uint_eq(sb_ceil(-0), ceil(-0));
    ck_assert_uint_eq(sb_ceil(1.5), ceil(1.5));
    ck_assert_uint_eq(sb_ceil(0.45), ceil(0.45));
    ck_assert_uint_eq(sb_ceil(1234567), ceil(1234567));
    ck_assert_ldouble_eq_tol(sb_ceil(0), ceil(0), 1e-6);
    ck_assert_ldouble_eq_tol(sb_ceil(-1), ceil(-1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_ceil(11.5), ceil(11.5), 1e-6);
    ck_assert_ldouble_eq_tol(sb_ceil(0.0001), ceil(0.0001), 1e-6);
    ck_assert_ldouble_eq_tol(sb_ceil(1000000000000.2), \
    ceil(1000000000000.2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_ceil(-25.99999999999), \
    ceil(-25.99999999999), 1e-6);
    ck_assert_ldouble_eq_tol(sb_ceil(-200000000000000.9995555464654878484), \
    ceil(-200000000000000.9995555464654878484), 1e-6);
}
END_TEST

START_TEST(sb_cos_test) {
    ck_assert_uint_eq(sb_cos(112343), cos(112343));
    ck_assert_uint_eq(sb_cos(-312345), cos(-312345));
    ck_assert_ldouble_eq_tol(sb_cos(0), cos(0), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(sb_PI), cos(sb_PI), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(sb_PI / 3), cos(sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(sb_PI / 6), cos(sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(sb_PI / 2), cos(sb_PI / 2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(sb_PI / 4), cos(sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-sb_PI / 4), cos(-sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-sb_PI / 2), cos(-sb_PI / 2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-sb_PI / 3), cos(-sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-sb_PI / 6), cos(-sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(2 * sb_PI / 3), \
    cos(2 * sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(5 * sb_PI / 6), \
    cos(5 * sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(2 * sb_PI / 4), \
    cos(2 * sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(3 * sb_PI / 4), \
    cos(3 * sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(126.8647465), cos(126.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-235.3456458), cos(-235.3456458), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(75846.8647465), cos(75846.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-92553.3456458), \
    cos(-92553.3456458), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(5659782464.8647465), \
    cos(5659782464.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_cos(-5237385933.3456458), \
    cos(-5237385933.3456458), 1e-6);
}
END_TEST

START_TEST(sb_exp_test) {
    for (double i = -10; i < 10; i++) {
        ck_assert_uint_eq(sb_exp(i), exp(i));
    }
    ck_assert_uint_eq(sb_exp(5), exp(5));
    ck_assert_uint_eq(sb_exp(-2), exp(-2));
    ck_assert_ldouble_infinite(sb_exp(4647475856));
    ck_assert_uint_eq(sb_exp(1234567), exp(1234567));
    ck_assert_ldouble_eq_tol(sb_exp(1), exp(1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_exp(0), exp(0), 1e-6);
    ck_assert_uint_eq(sb_exp(-1234567), exp(-1234567));
    ck_assert_ldouble_eq_tol(sb_exp(-1), exp(-1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_exp(-5), exp(-5), 1e-6);
    ck_assert_ldouble_eq_tol(sb_exp(-30), exp(-30), 1e-7);
    ck_assert_ldouble_eq_tol(sb_exp(-13.253678), exp(-13.253678), 1e-6);
    ck_assert_ldouble_eq_tol(sb_exp(-5647475856), exp(-5647475856), 1e-6);
    ck_assert_ldouble_eq_tol(sb_exp(-5.946047569), exp(-5.946047569), 1e-6);
}
END_TEST

START_TEST(sb_fabs_test) {
  ck_assert_uint_eq(sb_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_uint_eq(sb_fabs(-45.345), fabs(-45.345));
  ck_assert_uint_eq(sb_fabs(1.0), fabs(1.0));
}
END_TEST

START_TEST(sb_floor_test) {
    ck_assert_uint_eq(sb_floor(-0.), floor(-0.));
    ck_assert_uint_eq(sb_floor(1.5), floor(1.5));
    ck_assert_uint_eq(sb_floor(0.45), floor(0.45));
    ck_assert_ldouble_eq_tol(sb_floor(0), floor(0), 1e-6);
    ck_assert_ldouble_eq_tol(sb_floor(-1), floor(-1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_floor(11.5), floor(11.5), 1e-6);
    ck_assert_ldouble_eq_tol(sb_floor(0.0001), floor(0.0001), 1e-6);
    ck_assert_ldouble_eq_tol(sb_floor(1000000000000.2), \
    floor(1000000000000.2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_floor(-25.99999999999), \
    floor(-25.99999999999), 1e-6);
    ck_assert_ldouble_eq_tol(sb_floor(-200000000000000.9995555464654878484), \
    floor(-200000000000000.9995555464654878484), 1e-6);
}
END_TEST

START_TEST(sb_fmod_test) {
    double n = 200000000000000000000.1, m = 10000000000000000;
    ck_assert_ldouble_nan(sb_fmod(2000, 0));
    ck_assert_ldouble_eq_tol(sb_fmod(2, 1), fmod(2, 1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_fmod(2, 1), fmod(2, 1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_fmod(n, m), fmod(n, m), 1e-6);
    ck_assert_ldouble_eq_tol(sb_fmod(25, 11), fmod(25, 11), 1e-6);
    ck_assert_ldouble_eq_tol(sb_fmod(-12, 5), fmod(-12, 5), 1e-6);
    ck_assert_ldouble_eq_tol(sb_fmod(0, 123), fmod(0, 123), 1e-6);
    ck_assert_uint_eq(sb_fmod(23.456, 4.355), fmod(23.456, 4.355));
    ck_assert_uint_eq(sb_fmod(456.87678, 3.7), fmod(456.87678, 3.7));
    ck_assert_uint_eq(sb_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1));
    ck_assert_ldouble_eq_tol(sb_fmod(-333.666, 145), \
    fmod(-333.666, 145), 1e-6);
    ck_assert_ldouble_eq_tol(sb_fmod(8989989882, -148989.5989), \
    fmod(8989989882, -148989.5989), 1e-6);
}
END_TEST

START_TEST(sb_log_test) {
    for (double i = -1.; i < 10; i+= 0.1) {
        ck_assert_uint_eq(sb_log(i), log(i));
    }
    for (double i = 0.; i < 2; i+= 0.01) {
        ck_assert_uint_eq(sb_log(i), log(i));
    }
    ck_assert_ldouble_nan(sb_log(-1));
    ck_assert_ldouble_infinite(sb_log(0));
    ck_assert_uint_eq(sb_log(1.1), log(1.1));
    ck_assert_uint_eq(sb_log(12356), log(12356));
    ck_assert_ldouble_eq_tol(sb_log(1), log(1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_log(0.5), log(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(sb_log(123), log(123), 1e-6);
    ck_assert_ldouble_eq_tol(sb_log(0.1234), log(0.1234), 1e-6);
    ck_assert_ldouble_eq_tol(sb_log(0.9876), log(0.9876), 1e-6);
    ck_assert_ldouble_eq_tol(sb_log(sb_PI), log(sb_PI), 1e-6);
    ck_assert_ldouble_eq_tol(sb_log(547893), log(547893), 1e-6);
}
END_TEST

START_TEST(sb_pow_test) {
    ck_assert_uint_eq(sb_pow(2.6, 3.45), pow(2.6, 3.45));
    ck_assert_uint_eq(sb_pow(3.0, 14.0), pow(3.0, 14.0));
    ck_assert_uint_eq(sb_pow(31.456, 4.3), pow(31.456, 4.3));
    ck_assert_uint_eq(sb_pow(31.456, 0.3), pow(31.456, 0.3));
    ck_assert_uint_eq(sb_pow(4.3, 4.3), pow(4.3, 4.3));
    ck_assert_uint_eq(sb_pow(-1234, 4.3), pow(-1234, 4.3));
    ck_assert_uint_eq(sb_pow(-1234, -4.3), pow(-1234, -4.3));
    ck_assert_uint_eq(sb_pow(1234, -4.3), pow(1234, -4.3));
} END_TEST

START_TEST(sb_sin_test) {
    for (double i = -sb_PI; i < sb_PI; i+= 0.01) {
        ck_assert_uint_eq(sb_sin(i), sin(i));
    }
    ck_assert_ldouble_eq_tol(sb_sin(0), sin(0), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(sb_PI), sin(sb_PI), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(sb_PI / 3), sin(sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(sb_PI / 6), sin(sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(sb_PI / 2), sin(sb_PI / 2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(sb_PI / 4), sin(sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-sb_PI / 4), sin(-sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-sb_PI / 2), sin(-sb_PI / 2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-sb_PI / 3), sin(-sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-sb_PI / 6), sin(-sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(2 * sb_PI / 3), \
    sin(2 * sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(5 * sb_PI / 6), \
    sin(5 * sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(2 * sb_PI / 4), \
    sin(2 * sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(3 * sb_PI / 4), \
    sin(3 * sb_PI / 4), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(126.8647465), sin(126.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-235.3456458), sin(-235.3456458), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(75846.8647465), sin(75846.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-92553.3456458), \
    sin(-92553.3456458), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(5659782464.8647465), \
    sin(5659782464.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sin(-5237385933.3456458), \
    sin(-5237385933.3456458), 1e-6);
}
END_TEST

START_TEST(sb_sqrt_test) {
    ck_assert_ldouble_nan(sb_sqrt(-1.234567));
    ck_assert_ldouble_eq_tol(sb_sqrt(0), sqrt(0), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(1), sqrt(1), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(3), sqrt(3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(sb_PI), sqrt(sb_PI), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(788544), sqrt(788544), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(sb_PI / 3), sqrt(sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(sb_PI / 6), sqrt(sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(sb_PI / 2), sqrt(sb_PI / 2), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(126.8647465), sqrt(126.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(277715298169), \
    sqrt(277715298169), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(75846.8647465), \
    sqrt(75846.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(1234567898675), \
    sqrt(1234567898675), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(2 * sb_PI / 3), \
    sqrt(2 * sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(5 * sb_PI / 6), \
    sqrt(5 * sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_sqrt(2129412464.86474652345), \
    sqrt(2129412464.86474652345), 1e-6);
} END_TEST

START_TEST(sb_tan_test) {
    for (double i = -100; i < 100; i += 2) {
        ck_assert_uint_eq(sb_tan(i), tan(i));
    }
    for (double i = -1; i < 1; i += 0.02) {
        ck_assert_uint_eq(sb_tan(i), tan(i));
    }
    ck_assert_uint_eq(sb_tan(0.23), tan(0.23));
    ck_assert_uint_eq(sb_tan(1234567), tan(1234567));
    ck_assert_ldouble_eq_tol(sb_tan(0), tan(0), 1e-6);
    ck_assert_uint_eq(sb_tan(-1234567), tan(-1234567));
    ck_assert_ldouble_eq_tol(sb_tan(sb_PI), tan(sb_PI), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(sb_PI / 3), tan(sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(sb_PI / 6), tan(sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(126.8647465), tan(126.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(-235.3456458), tan(-235.3456458), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(75846.8647465), tan(75846.8647465), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(-92553.3456458), \
    tan(-92553.3456458), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(2 * sb_PI / 3), \
    tan(2 * sb_PI / 3), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(5 * sb_PI / 6), \
    tan(5 * sb_PI / 6), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(2129412464.86474652345), \
    tan(2129412464.86474652345), 1e-6);
    ck_assert_ldouble_eq_tol(sb_tan(-2129538533.34564586457), \
    tan(-2129538533.34564586457), 1e-6);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sb_abs_test);
    tcase_add_test(tc1_1, sb_acos_test);
    tcase_add_test(tc1_1, sb_asin_test);
    tcase_add_test(tc1_1, sb_atan_test);
    tcase_add_test(tc1_1, sb_ceil_test);
    tcase_add_test(tc1_1, sb_cos_test);
    tcase_add_test(tc1_1, sb_exp_test);
    tcase_add_test(tc1_1, sb_fabs_test);
    tcase_add_test(tc1_1, sb_floor_test);
    tcase_add_test(tc1_1, sb_fmod_test);
    tcase_add_test(tc1_1, sb_log_test);
    tcase_add_test(tc1_1, sb_pow_test);
    tcase_add_test(tc1_1, sb_sin_test);
    tcase_add_test(tc1_1, sb_sqrt_test);
    tcase_add_test(tc1_1, sb_tan_test);
    srunner_run_all(sr, CK_ENV);
    srunner_free(sr);
    return 0;
}
