#include "ansi_fp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern double lbl_80560570;
extern double lbl_80560578;
extern double lbl_80560580;
extern double lbl_80560588;
extern double lbl_80560590;
extern float lbl_80558DB4[]; /* __float_huge (HUGE_VAL), not small data */
extern double lbl_802FE660[];
extern char lbl_802ED878[];
extern double copysign(double, double);
extern double fn_8002EFBC(double, double);
extern double ldexp(double, int);
extern int __fpclassifyd(double);
double __dec2num(const decimal *dec) {
    const decimal *d = dec;
    unsigned char *end;
    short exp;
    double nan_code;
    double num;
    double trend;
    decimal temp;
    decimal max;
    decimal mid;
    decimal high;
    decimal low;
    decimal diff;
    if (d->sig.length == 0) {
        return copysign(lbl_80560570, d->sign == 0 ? lbl_80560578 : lbl_80560580);
    }
    switch (d->sig.text[0]) {
    case '0':
        return copysign(lbl_80560570, d->sign == 0 ? lbl_80560578 : lbl_80560580);
    case 'I':
        return copysign((double)*(float *)&lbl_80558DB4, d->sign == 0 ? lbl_80560578 : lbl_80560580);
    case 'N':
        *(unsigned long long *)&nan_code = 0x7FF0000000000000ULL;
        if (d->sign) {
            *(unsigned long long *)&nan_code |= 0x8000000000000000ULL;
        }
        *(unsigned long long *)&nan_code |= 0x0008000000000000ULL;
        return nan_code;
    }
    temp = *d;
    {
        unsigned char *p = temp.sig.text;
        end = p + temp.sig.length;
        while (p < end) {
            *p = *p - '0';
            p++;
        }
        exp = temp.exp + temp.sig.length - 1;
        temp.exp = exp;
        __str2dec(&max, lbl_802ED878 + 0xB8, 308);
        if (__less_dec(&max, &temp)) {
            return copysign((double)*(float *)&lbl_80558DB4, d->sign == 0 ? lbl_80560578 : lbl_80560580);
        }
        num = (double)temp.sig.text[0];
        p = temp.sig.text + 1;
        while (p < end) {
            int chunk = (end - p) % 8;
            int val = 0;
            int i;
            double scaled;
            double sum;
            if (chunk == 0) {
                chunk = 8;
            }
            for (i = 0; i < chunk; i++) {
                val = val * 10 + *p++;
            }
            scaled = num * lbl_802FE660[chunk - 1];
            sum = scaled + (double)val;
            if (val != 0 && sum == scaled) {
                break;
            }
            num = sum;
            exp -= chunk;
        }
        if (exp < 0) {
            num /= fn_8002EFBC(lbl_80560588, (double)-exp);
        } else {
            num *= fn_8002EFBC(lbl_80560588, (double)exp);
        }
        num = ldexp(num, exp);
    }
    if (__fpclassifyd(num) == 2) {
        num = lbl_80560590;
    }
    __num2dec_internal(&mid, num);
    if (!__equals_dec(&mid, &temp)) {
        int adjust;
        adjust = __less_dec(&mid, &temp);
        trend = num;
        for (;;) {
            if (adjust) {
                *(unsigned long long *)&trend += 1;
                if (__fpclassifyd(trend) == 2) {
                    break;
                }
            } else {
                *(unsigned long long *)&trend -= 1;
            }
            __num2dec_internal(&high, trend);
            if (!adjust || __less_dec(&high, &temp)) {
                if (!adjust && !__less_dec(&temp, &high)) {
                    double tmp;
                    low = mid;
                    mid = high;
                    high = low;
                    tmp = num;
                    num = trend;
                    trend = tmp;
                    goto check;
                }
                mid = high;
                num = trend;
                continue;
            }
        check:
            __minus_dec(&low, &temp, &mid);
            __minus_dec(&diff, &high, &temp);
            if (__equals_dec(&low, &diff)) {
                if (((int *)&num)[1] & 1) {
                    num = trend;
                }
            } else if (!__less_dec(&low, &diff)) {
                num = trend;
            }
            break;
        }
    }
    if (temp.sign) {
        num = -num;
    }
    return num;
}
