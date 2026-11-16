// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
/* Destroys/resets a 12-byte object, zeroing its three fields, and frees it when deleting > 0. */
void *fn_802BB7CC(void *self, int deleting) {
    if (self != 0) {
        if (self != 0) {
            *(int *)self = 0;
            *((int *)self + 1) = 0;
            *((int *)self + 2) = 0;
        }
        if (deleting > 0)
            fn_80128668(self);
    }
    return self;
}

void *fn_802BB824(void *object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when shouldDelete > 0 (deleting-destructor helper). */
    if (object != 0) {
        if (object != 0) {
            *(int *)object = 0;
            *((int *)object + 1) = 0;
            *((int *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma push
#pragma dont_inline on
int fn_802BB87C(int path) {
    int isReady = 0;
    if (path != 0 && fn_8012C33C() != 0) isReady = 1;
    if (isReady != 0) return fn_802CAC28(path, 0);
    return -2;
}
#pragma pop

void fn_802BB8E4(int *handlePtr) {
    /* Releases the handle if set, then marks it as invalid (-2). */
    int handle = *handlePtr;
    if (handle != -2) {
        fn_802CAC54(handle);
        *handlePtr = -2;
    }
}

int fn_802BB928(int arg0) {
    return (arg0 + 0x200) / 2;
}

short fn_802BB93C(int arg0) {
    unsigned int value = (unsigned int)arg0 + 0x200;
    unsigned int sign = value >> 31;
    int rounded = (int)sign + (int)value;
    return (short)(0x1FF - (rounded >> 1));
}

extern int fn_802CAC54(int);
extern int lbl_804C00B0[];
extern int fn_802D9628(short, short, unsigned int);
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802BB958(short arg0, int arg1, unsigned char *arg2, unsigned char *arg3) {
    int *var_r31; // v4
    short temp_r30;
    int temp_r29;
    int var_r28;
    temp_r30 = fn_802BB928(arg0);
    temp_r29 = fn_802BB93C(arg1);
    var_r31 = lbl_804C00B0;
    var_r28 = 0;
    do {
        int value = *var_r31;
        if (value != 0) {
            unsigned char temp_r4 = *arg2;
            if (temp_r4 != *arg3) {
                ((void (*)(void *, int, int, unsigned int))fn_802D9628)(
                    (void *)value, temp_r30, temp_r29,
                    ((unsigned int)temp_r4 << 24) | ((unsigned int)temp_r4 << 16) |
                    ((unsigned int)temp_r4 << 8) | temp_r4);
            }
        }
        var_r28 += 1;
        var_r31 += 1;
        arg3++;
        arg2++;
    } while (var_r28 < 6);
}

extern void *fn_802B51E4(int, int);
extern void fn_802B52B4(void *);
extern int fn_802B52C0(int, void *);
extern char *strchr(const char *, int);
extern char lbl_8055CF18;
int fn_802BBA08(void *arg0, int arg1) {
    struct Image {
        int width;
        int height;
        int *pixels;
    };
    struct Image *image;
    int *layers;
    int *p;
    int y, x, pix, shift, k;
    char filename[0x80];
    char *dst;
    char *dst2;
    char *src;
    char *dot;
    int n;
    int m;
    char c;
    char d;
    char *name;

    name = (char *)arg0;
    image = (struct Image *)fn_802B51E4(0x200, 0x200);
    if (image != 0) {
        layers = &lbl_804C00B0[arg1];
        for (y = 0; y < 0x200; y++) {
            for (x = 0; x < 0x200; x++) {
                pix = 0;
                p = layers;
                for (k = 0, shift = 0; k < 3; k++, p++, shift += 8) {
                    if (*p != 0) {
                        pix |= ((fn_802D972C((void *)*p, y, x) >> 8) & 0xFF) << shift;
                    }
                }
                image->pixels[(image->height - 1 - x) * image->width + y] = pix;
            }
        }
        dst = filename;
        n = 0x80;
        goto body1;
        for (;;) {
            if (--n <= 0) {
                *--dst = 0;
                break;
            }
body1:
            c = *name++;
            *dst++ = c;
            if (c == 0) break;
        }
        if (strchr(filename, '.') != 0) {
            dot = strchr(filename, '.');
            *dot = 0;
        }
        dst2 = filename;
        m = 0x80;
        src = (char *)&lbl_8055CF18;
        goto scan;
        for (;;) {
            m--;
            dst2++;
scan:
            if (*dst2 == 0) break;
        }
        if (m > 0) {
            goto body2;
            for (;;) {
                if (--m <= 0) {
                    *--dst2 = 0;
                    break;
                }
body2:
                d = *src++;
                *dst2++ = d;
                if (d == 0) break;
            }
        }
        fn_802B52C0((int)filename, image);
        fn_802B52B4(image);
    }
}

#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_802BBBC8(void) {
    extern int lbl_80564CF8;
    extern int lbl_80564CFC;
    extern int lbl_804C0098[];
    extern int lbl_804C00B0[];
    extern signed char lbl_8055CF30;
    extern signed char lbl_8055FA90;
    extern char lbl_8034AAB8[];
    extern char lbl_8034AAC4[];
    extern void fn_801345D8(char *, int, char *, ...);
    extern void fn_802E317C(char *, ...);
    extern int fn_802CA294(int);
    extern signed char fn_802B05E4(void);
    char sp10[0x20];
    int args[2];
    register int *var_r27;
    register int *var_r26;
    register int var_r25;
    register signed char *colors;
    int temp_r3;
    int var_r3;

    args[0] = lbl_80564CF8;
    var_r27 = lbl_804C0098;
    var_r26 = lbl_804C00B0;
    args[1] = lbl_80564CFC;
    var_r25 = 0;
    colors = &lbl_8055CF30;
    for (; var_r25 < 6;) {
        fn_801345D8(sp10, 0x20, lbl_8034AAB8, args[var_r25 / 3], colors[var_r25 % 3]);
        temp_r3 = fn_802BB87C((int)sp10);
        *var_r27 = temp_r3;
        if (temp_r3 == -2) {
            fn_802E317C(lbl_8034AAC4, var_r25);
        }
        temp_r3 = *var_r27;
        if (temp_r3 == -2) {
            var_r3 = 0;
        } else {
            var_r3 = fn_802CA294(temp_r3);
        }
        var_r25 += 1;
        *var_r26 = var_r3;
        var_r27++;
        var_r26++;
    }
    lbl_8055FA90 = fn_802B05E4();
}
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma inline_depth(0)
void fn_802BBCC4(void) {
    /* Release up to 6 tracked resource handles in lbl_804C0098 and clear their corresponding flags in lbl_804C00B0. */
    extern int lbl_804C0098[];
    extern int lbl_804C00B0[];
    int *handle = lbl_804C0098;
    int *flag = lbl_804C00B0;
    int i = 0;
    do {
        fn_802BB8E4(handle);
        i += 1;
        *flag = 0;
        handle++;
        flag++;
    } while (i < 6);
}

#pragma push
#pragma use_lmw_stmw off
unsigned char fn_802BBD38(int arg0, int arg1, int arg2) {
    extern signed char lbl_8055FA90;
    extern int fn_802D972C(void *, int, int);
    int *slot;
    int value;
    int x;
    short y;
    int x2;
    int y2;
    register int invalid;
    register int result;

    if ((unsigned char)lbl_8055FA90 != 0)
        return (unsigned char)(~((arg2 - 1) | (1 - arg2)) >> 31);

    result = 0;
    slot = lbl_804C00B0 + arg2;
    value = *slot;
    if (value != 0) {
        x = fn_802BB928(arg0);
        y = fn_802BB93C(arg1);
        invalid = 0;
        if ((short)x < 0 || (short)x >= 0x200 || y < 0 || y >= 0x200)
            invalid = 1;

        if (invalid == 0) {
            y2 = (short)fn_802BB93C(arg1);
            x2 = (short)fn_802BB928(arg0);
            value = *slot;
            result = (unsigned char)(((unsigned int)((int (*)(void *, int, int))fn_802D972C)(
                (void *)value, x2, y2)) >> 8);
        } else {
            result = (unsigned char)(~((arg2 - 2) | (2 - arg2)) >> 31);
        }
    }
    return (unsigned char)result;
}
#pragma pop
  extern int lbl_804C0098[];
extern void fn_802BB8E4(int*);
extern int fn_802D972C(void *, int, int);
extern int fn_802E30C8(const char*, ...);
extern char lbl_8034AAF0[];
#pragma scheduling invalid_target
#pragma push
#pragma use_lmw_stmw off
void fn_802BBE34(void) {
    int *ptr;
    int outer;
    int inner;
    unsigned int sum;
    int count;
    for (outer = 0; outer < 0x200; outer++) {
        for (inner = 0; inner < 0x200; inner++) {
            sum = 0;
            for (count = 0, ptr = lbl_804C00B0; count < 6; count++, ptr++) {
                if (*ptr != 0) {
                    sum += ((unsigned int)((int (*)(void *, int, int))fn_802D972C)(
                        (void *)*ptr, outer, inner) >> 8) & 0xFF;
                }
            }
            if (sum != 0xFF) {
                fn_802E30C8(lbl_8034AAF0, outer, inner, sum);
            }
        }
    }
}
#pragma pop
extern int fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern int fn_802BBA08(void *, int);
extern int lbl_8055CF20;
extern int lbl_8055CF28;
#pragma push
#pragma scheduling invalid_target
void fn_802BBEE4(void) {
    /* Rebuild cached state, then run two setup passes bracketed by begin/end guards when not enabled. */
    register int savedState;
    register unsigned char isEnabled;

    fn_802BBE34();
    savedState = fn_80128690();
    isEnabled = (unsigned char)savedState;
    if (isEnabled == 0)
        fn_80128684();
    fn_802BBA08(&lbl_8055CF20, 0);
    fn_802BBA08(&lbl_8055CF28, 3);
    isEnabled = (unsigned char)savedState;
    if (isEnabled == 0)
        fn_80128678();
}
#pragma pop
extern const char lbl_8034AB00[];
#pragma push
#pragma scheduling invalid_target
/* Logs when the sum of six channel bytes is not 0xFF. */
void fn_802BBF44(unsigned char *bytes, int channelIndex) {
#define sInvalidChecksumFmt lbl_8034AB00
    register unsigned int byte5;
    register unsigned int byte4;
    register unsigned int byte3;
    register unsigned int byte2;
    register unsigned int byte1;
    register unsigned int byte0;
    unsigned int sum;

    byte0 = bytes[0];
    byte1 = bytes[1];
    byte2 = bytes[2];
    byte3 = bytes[3];
    byte4 = bytes[4];
    byte5 = bytes[5];
    sum = byte0 + byte1;
    sum += byte2;
    sum += byte3;
    sum += byte4;
    sum += byte5;
    if (sum != 0xFF) {
        fn_802E30C8(sInvalidChecksumFmt, byte0, byte1, byte2,
                    byte3, byte4, byte5, channelIndex);
    }
#undef sInvalidChecksumFmt
}
#pragma pop
int fn_802BBF94(unsigned char arg0) {
    int res = (arg0 >> 4) & 0xF;
    return __rlwimi(res, arg0, 0, 24, 27);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
/* Normalizes 6 nibble-duplicated bytes and adjusts them so their sum becomes 0xFF. */
void fn_802BBFA4(unsigned char *arg0, int arg1, int arg2, int arg3) {
    register unsigned char *base = arg0;
    register int index = arg1;
    register int skip = arg2;
    register int i = 0;
    register int value0;
    register int value1;
    register int value2;
    register int value3;
    register int value4;
    register int value5;
    register int sum;
    register int j;
    int delta;
    int value;

    do {
        arg0[i] = (unsigned char)fn_802BBF94(arg0[i]);
        i++;
    } while (i < 6);

    value0 = base[0];
    value1 = base[1];
    value2 = base[2];
    value3 = base[3];
    value4 = base[4];
    value5 = base[5];
    sum = value0 + value1;
    sum += value2;
    sum += value3;
    sum += value4;
    sum += value5;
    if (sum != 0xFF) {
        value = base[index];
        delta = sum - 0xFF;
        if (value >= delta) {
            base[index] = value - delta;
            return;
        }
        j = 0;
        while (sum != 0xFF && j < 6) {
            if (j != skip) {
                value = *base;
                delta = sum - 0xFF;
                if (delta < value) {
                    value = delta;
                }
                sum -= value;
                *base -= value;
            }
            j++;
            base++;
        }
    }
}
#pragma pop
extern int fn_802B05DC(void);
extern void *memset(void *, int, unsigned long);
extern float lbl_80564D00;
extern float lbl_80564D04;
extern double lbl_80564D08;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_802BC09C(short arg0, int arg1, int arg2, signed char arg3, float farg0) {
    unsigned char sp10[6];
    unsigned char sp8[6];
    int result = 0;
    int cur = fn_802B05DC();
    if (arg2 != cur) {
        int bad;
        int x = fn_802BB928(arg0);
        short y = fn_802BB93C(arg1);
        int i;
        float f, a, b;
        unsigned char base, old;
        unsigned char *d;
        unsigned char *s;
        bad = 0;
        if ((short)x < 0 || (short)x >= 0x200 || y < 0 || y >= 0x200) bad = 1;
        if (bad == 0) {
            unsigned char *w = sp10;
            for (i = 0; i < 6; i++) { *w = fn_802BBD38(arg0, arg1, i); w++; }
            if (cur == -1 || sp10[cur] < 0x80) {
                if (cur == -1) base = 0;
                else base = sp10[cur];
                memset(sp8, 0, 6);
                sp8[arg2] = arg3;
                d = sp8;
                s = sp10;
                for (i = 0; i < 3; i++) {
                    double ds0, dd0, ds1, dd1;
                    int hi = 0x43300000;
                    ((int *)&ds0)[0] = hi; ((int *)&ds0)[1] = s[0];
                    a = (float)(ds0 - lbl_80564D08);
                    ((int *)&dd0)[0] = hi; ((int *)&dd0)[1] = d[0];
                    b = (float)(dd0 - lbl_80564D08);
                    f = a + farg0 * (b - a);
                    if (f < lbl_80564D00) f = f - lbl_80564D04;
                    else f = lbl_80564D04 + f;
                    d[0] = (unsigned char)(int)f;
                    ((int *)&ds1)[0] = hi; ((int *)&ds1)[1] = s[1];
                    a = (float)(ds1 - lbl_80564D08);
                    ((int *)&dd1)[0] = hi; ((int *)&dd1)[1] = d[1];
                    b = (float)(dd1 - lbl_80564D08);
                    f = a + farg0 * (b - a);
                    if (f < lbl_80564D00) f = f - lbl_80564D04;
                    else f = lbl_80564D04 + f;
                    d[1] = (unsigned char)(int)f;
                    s += 2;
                    d += 2;
                }
                if (cur != -1) {
                    old = sp8[cur];
                    sp8[cur] = base;
                    if (old > base) sp8[arg2] = sp8[arg2] - (old - base);
                    else sp8[arg2] = sp8[arg2] - (base - old);
                }
                ((void (*)(unsigned char *, int, int))fn_802BBFA4)(sp8, arg2, cur);
                fn_802BBF44(sp8, arg2);
                fn_802BB958(arg0, arg1, sp8, sp10);
                result = 1;
            }
        }
    }
    return result;
}
#pragma pop
extern int lbl_804C0098[4];
int __AXGetStackHead_802BC30C(int index) { return lbl_804C0098[index]; }
extern int fn_802CAC54(int);
extern int lbl_804C00B0[6];
extern int fn_802D9628(short, short, unsigned int);
