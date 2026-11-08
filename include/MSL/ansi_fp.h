#ifndef _MSL_COMMON_ANSI_FP_H
#define _MSL_COMMON_ANSI_FP_H

#define SIGDIGLEN 36

typedef struct decimal {
	char sign;
	char unk1;
	short exp;
	struct {
		unsigned char length;
		unsigned char text[36];
		unsigned char unk41;
	} sig;
} decimal;

/* how many significant digits __num2dec is to produce, and in what style */
enum decform_style {
	decform_style_normal,      /* fixed point */
	decform_style_scientific,  /* one digit before the radix point */
	decform_style_engineering  /* exponent is a multiple of 3 */
};

typedef struct decform {
	char style;   /* enum decform_style */
	char unk1;
	short digits; /* significant digits */
} decform;

void __ull2dec(decimal*, unsigned long long);
void __timesdec(decimal*, const decimal*, const decimal*);
void __str2dec(decimal*, const char*, short);
void __two_exp(decimal*, long);
int __equals_dec(const decimal*, const decimal*);
int __less_dec(const decimal*, const decimal*);
void __minus_dec(decimal*, const decimal*, const decimal*);
void __num2dec_internal(decimal*, double);
void __num2dec(const decform*, double, decimal*);
double __dec2num(const decimal*);

#endif
