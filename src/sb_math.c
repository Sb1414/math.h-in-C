#include "sb_math.h"

int sb_abs(int x) {
    return x < 0 ? -x : x;
}

long double sb_acos(double x) {
    if (sb_fabs(x) <= 1) {
        x = sb_PI / 2 - sb_asin(x);
    } else {
        x = sb_NaN;
    }
    return x;
}

long double sb_asin(double x) {
    long double value_asin = sb_NaN;
    if (x > - 0.9  && x < 0.9) {
        value_asin = x;
        long double row = x;
        int i = 2;
        for (int j = 0; j <= 15000; j++) {
            row = row * x * x * (i - 1) * (i - 1) / (i * (i + 1));
            i += 2;
            value_asin += row;
        }
    } else if (x <= 1.0 && x >= 0.9) {
        value_asin = sb_PI / 2 - sb_asin(sb_sqrt(1 - x * x));
    } else if (x >= -1.0 && x <= - 0.9) {
        value_asin = - sb_PI / 2 + sb_asin(sb_sqrt(1 - x * x));
    }
    return value_asin;
}

long double common(double x) {
    long double res = x, y = x;
    for (int i = 1; sb_fabs(res) > sb_EPSEQ; i++) {
        res = -1 * res * x * x * (2 * i - 1) / (2 * i + 1);
        y += res;
    }
    return y;
}

long double sb_atan(double x) {
    long double y = 0;
    if (sb_fabs(x) < 1) {
        y = common(x);
    } else if (sb_fabs(x) == 1 || x == 0) {
        y = x == 1 ? sb_PI / 4 : x == -1 ? sb_NEG_PI / 4 : 0;
    } else {
        y = x > 1 ? sb_PI / 2 - common(1 / x) : sb_NEG_PI / 2 - common(1 / x);
    }
    return y;
}

long double sb_ceil(double x) {
    long double y;
        if (x != x) {
            y = sb_NaN;
        } else if (x == sb_INFINITY || x == -sb_INFINITY) {
            y = x;
        } else {
            long long z = (long long)x;
            y = x > 0 && z < x ? z +=1 : (long double)z;
        }
        return y;
}

long double sb_cos(double x) {
    long double value_cos;
    if (x == sb_INFINITY || x == -sb_INFINITY) {
        value_cos = sb_NaN;
    } else {
        if (x > 2 * sb_PI || x < -2 * sb_PI)
            x = sb_fmod(x, 2 * sb_PI);
        long double row = 1;
        value_cos = 1;
        int i = 0;
        while (sb_fabs(row) > sb_NEAR_ZERO) {
            row = - row * x * x/ ((i + 1) * (i + 2));
            value_cos += row;
            i += 2;
        }
    }
    return value_cos;
}

long double sb_exp(double x) {
    long double result = 1, y = 1;
    int minus = x < 0 ? -1 : 1;
    x *= minus;
    for (int i = 1; sb_fabs(result) > sb_EPSEQ; i++) {
        result *= x / i;
        y += result;
        if (y > sb_MAX_DOUBLE) {
            y = sb_INFINITY;
            break;
        }
    }
    y = minus == -1 ? y > sb_MAX_DOUBLE ? 0 : 1.0 / y : y;
    return y > sb_MAX_DOUBLE ? sb_INFINITY : y;
}

long double sb_fabs(double x) {
    return x > 0 ? x : -x;
}

long double sb_floor(double x) {
    long double y;
    if (x != x) {
        y = sb_NaN;
    } else if (x == sb_INFINITY || x == -sb_INFINITY) {
        y = x;
    } else {
        long long z = (long long)x;
        y = x < 0 && z > x ? z -= 1 : (long double)z;
    }
    return y;
}

long double sb_fmod(double x, double y) {
    long double remain = sb_NaN;
    if (y == sb_INFINITY || y == -sb_INFINITY) {
        if (x != sb_INFINITY && x != -sb_INFINITY && x == x) {
            remain = 0;
        }
    } else if (x == sb_INFINITY || x == -sb_INFINITY) {
        remain = sb_NaN;
    } else if (y) {
        long long int personal = x / y;
        remain = x - y * personal;
    }
    return remain;
}

long double log_big_zero_min_two(double x) {
    x--;
    long double tmp_n = x, res = x;
    for (float i = 1; sb_fabs(tmp_n) > sb_EPSEQ; i++) {
        tmp_n *= -x * i / (i + 1);
        res += tmp_n;
    }
    return res;
}

void alg(double x, parametrs *param) {
    int es = 0;
    param->sign = x < 0 ? -1 : 1;
    x *= param->sign;
    if (x >= 10) {
        while (x >= 10) {
            x /= 10.;
            es++;
        }
    } else if (x < 1 && x > 0) {
        while (x < 1) {
            x *= 10;
            es--;
        }
    }
    param->mant = x;
    param->e = es;
}

long double log_oth(double x) {
    parametrs param = {0};
    alg(x, &param);
    x = param.mant * param.sign / 10;
    long double res = x < 0 ? sb_NEG_NaN
                      : x == 0 ? sb_NEG_INFINITY
                      : log_big_zero_min_two(x) + (param.e + 1) * sb_LN10;
    return res;
}

long double sb_log(double x) {
    return (x > 0 && x < 2) ? log_big_zero_min_two(x) : log_oth(x);
}

long double sb_pow(double base, double exp) {
    return sb_exp(exp * sb_log(base));
}

long double sb_sin(double x) {
    long double value_sin;
    if (x == sb_INFINITY || x == -sb_INFINITY) {
        value_sin = sb_NaN;
    } else {
        if (x > 2 * sb_PI || x < -2 * sb_PI)
            x = sb_fmod(x, 2 * sb_PI);
        value_sin = x;
        long double row = x;
        int i = 1;
        while (sb_fabs(row) > sb_NEAR_ZERO) {
            row = - row * x * x/ ((i + 1) * (i + 2));
            value_sin += row;
            i += 2;
        }
    }
    return value_sin;
}

long double sb_sqrt(double x) {
    long double value_sqrt = 0;
    if (x != x) {
        value_sqrt = sb_NaN;
    } else if (x == sb_INFINITY) {
        value_sqrt = sb_INFINITY;
    } else {
        long double end = x;
        if (x < 0 || x == sb_NaN) {
            value_sqrt = sb_NaN;
        } else {
            long double start = 0;
            while (start <= end) {
                long double mid = 0;
                mid = (start + end) / 2;
                if (mid * mid == x) {
                    value_sqrt = mid;
                    break;
                }
                if (mid * mid < x) {
                    value_sqrt = start;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            long double increment = 0.1;
            for (int i = 0; i <= 6; i++) {
                while (value_sqrt * value_sqrt <= x) {
                    value_sqrt += increment;
                }
                value_sqrt = value_sqrt - increment;
                increment = increment / 10;
            }
        }
    }
    return value_sqrt;
}

long double sb_tan(double x) {
    long double value;
    if (x >= sb_PI && sb_fmod(x, sb_PI) == 0.)
        value = 0;
    else
        value = sb_sin(x) / sb_cos(x);
    return value;
}
