// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F93C;
extern int lbl_8055F940;
extern int lbl_8055F944;
extern int lbl_8055F948;
extern signed char lbl_8055F94C;
extern const char lbl_8055CC88;
extern const char lbl_8055CCB8;
extern float lbl_80564AB0;
extern double atof(const char *);
extern int fn_802E2C20(void);
extern int sscanf(const char *, const char *, ...);
void *fn_802AC0E8(void *arg0, const char *arg1, int arg2) {
    char *node = (char *)arg0;
    int key = arg2;
    const char *name = arg1;
    if (node == 0)
        return 0;
    while (*(int *)node != 0) {
        if (*(int *)node == key && strcmp(*(const char **)(node + 4), name) == 0)
            return node;
        node += 0xC;
    }
    return 0;
}

#pragma scheduling invalid_target
int fn_802AC174(const char *arg0) {
    int sp8;
    sp8 = 0;
    if (sscanf(arg0, &lbl_8055CC88, &sp8) == 1)
        return sp8;
    return -1;
}
#pragma scheduling on
extern char *strstr(const char *, const char *);
extern int lbl_802FAA50[];
#pragma use_lmw_stmw off
int fn_802AC1BC(const char *arg0, int arg1) {
    int entries[24];
    int *src = lbl_802FAA50 - 1;
    int *dst = entries - 1;
    int i = 12;
    int flags = 0;
    int has_align = 0;
    int has_no_align = 0;
    do {
        dst[1] = src[1];
        dst[2] = src[2];
        src += 2;
        dst += 2;
    } while (--i != 0);
    {
        int *entry = entries;
        while (entry[0] != 0) {
            if (strstr(arg0, (const char *)entry[0]) != 0) {
                int masked = flags & 7;
                unsigned char align = ((unsigned char *)entry)[8];
                if (align != 0) masked = flags & ~7;
                flags = masked | entry[1];
                has_align = (has_align != 0 || align != 0);
                has_no_align = (has_no_align != 0 || align == 0);
            }
            entry = (int *)((char *)entry + 12);
        }
    }
    if (has_align == 0) flags |= 4;
    if (has_no_align == 0) flags |= 0x10;
    return flags;
}
#pragma use_lmw_stmw on
int fn_802AC2B4(void **arg0, int arg1, float *arg2) {
    if (arg0 != 0 && ((int (*)(void *))((void **)*arg0)[3])(arg0) != 0) {
        if (arg2 != 0) {
            *arg2 = ((float (*)(void *, int))((void **)*arg0)[9])(arg0, arg1);
        }
        return 1;
    }
    return 0;
}

#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" float fn_802AC344(void *arg0, void *arg1, float *arg2) {
    struct InterfaceA {
        virtual void v0();
        virtual int hasKey(const char *);
        virtual void v2();
        virtual char *getKey(const char *);
    };
    struct InterfaceB {
        virtual void v0();
        virtual int hasEntry(const char *);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float getFloat(const char *);
    };

    float f31;
    float f30;
    char *str;

    if (arg2 != 0) {
        f31 = *arg2;
    } else {
        f31 = lbl_80564AB0;
    }

    if (((InterfaceA *)arg0)->hasKey(&lbl_8055CCB8) != 0) {
        str = ((InterfaceA *)arg0)->getKey(&lbl_8055CCB8);
        f30 = lbl_80564AB0;
        if (*str == '+') {
            f30 = f31;
            str++;
        }
        if (arg1 != 0 && ((InterfaceB *)arg1)->hasEntry(str) != 0) {
            f30 += ((InterfaceB *)arg1)->getFloat(str);
        } else {
            f30 += (float)atof(str);
        }
        return f30;
    }
    return f31;
}
#pragma pop

extern float fn_802AC344(void *, void *, float *);
float fn_802AC454(void *arg0, void *arg1, float *arg2) { return fn_802AC344(arg0, arg1, arg2); }

void fn_802AC458(void) {
    lbl_8055F93C = 0;
    lbl_8055F944 = fn_802E2C20();
    lbl_8055F948 = 0;
    lbl_8055F940 = 0;
    lbl_8055F94C = 1;
}

void fn_802AC49C(void) {
    lbl_8055F93C = 0;
}

extern float lbl_80564ACC;
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FA4[];
extern void fn_802AD4C4(void *, int, float);
extern int strcmp(const char *, const char *);
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FB0[];
extern void fn_802E30C8(const char *, ...);
extern void *fn_801284F8(int, void *, void *);
extern void *fn_8012850C(int, void *);
extern int fn_802AC4A8(const char *, int);
extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_802328D4(void *);
extern void fn_802C6CF8(void *);
void fn_802AD308(void) {}

void fn_802AD30C(void *arg0) {
    struct Record {
        int type;
        int pad4;
        int pad8;
        void *ptr;
        int pad10[6];
    };
    struct Group {
        int pad0;
        int pad4;
        void *ptr;
    };
    int refCount;
    int i;

    /* Release a resource object: decrement its refcount, and on last reference
       destroy child records/groups and free owned allocations. */
    refCount = *(int *)((char *)arg0 + 0x18) - 1;
    *(int *)((char *)arg0 + 0x18) = refCount;
    if (refCount <= 0) {
        lbl_8055F93C = (char *)lbl_8055F93C - 1;
        for (i = 0; i < *(int *)((char *)arg0 + 0x1C); i++) {
            if ((*(struct Record **)((char *)arg0 + 0x20))[i].type == 1) {
                fn_802328D4((*(struct Record **)((char *)arg0 + 0x20))[i].ptr);
            } else if ((*(struct Record **)((char *)arg0 + 0x20))[i].type == 2) {
                fn_802C6CF8((*(struct Record **)((char *)arg0 + 0x20))[i].ptr);
            }
        }

        for (i = 0; i < *(int *)((char *)arg0 + 0x24); i++) {
            void *ptr = (*(struct Group **)((char *)arg0 + 0x28))[i].ptr;
            if (ptr != 0) {
                fn_80128670((char *)ptr - 0x10);
            }
        }

        if (*(void **)((char *)arg0 + 0x20) != 0) {
            fn_80128670(*(void **)((char *)arg0 + 0x20));
        }
        if (*(void **)((char *)arg0 + 0x28) != 0) {
            fn_80128670(*(void **)((char *)arg0 + 0x28));
        }
        fn_80128668(arg0);
    }
}

#pragma scheduling invalid_target
void fn_802AD414(void *arg0, float farg0) {
    float base = lbl_80564ACC;
    int outer = 0;
    int offset = 0;
    while (outer < *(int *)((char *)arg0 + 0x24)) {
        int inner = 0;
        int byteOffset = 0;
        char *group = *(char **)((char *)arg0 + 0x28) + offset;
        int count = *(int *)(group + 4);
        if (count > 0) {
            char *entries = *(char **)(group + 8);
            do {
                float a = *(float *)(entries + byteOffset);
                char *entry = entries + byteOffset;
                float b = *(float *)(entries + byteOffset + 0x38);
                if (farg0 >= a && farg0 <= base + b) {
                    int idx = *(int *)group;
                    char *records = *(char **)((char *)arg0 + 0x20);
                    char *record = records + idx * 0x28;
                    int *p = *(int **)(record + 4);
                    if (p) *p = *(int *)(entry + 0x34);
                    break;
                }
                byteOffset += 0x38;
                inner++;
            } while (--count > 0);
        }
        offset += 0xC;
        outer++;
    }
}

extern float lbl_80564AB4, lbl_80564ACC, lbl_80564AD0, lbl_80564AD4, lbl_80564AD8, lbl_80564AC0;
extern char lbl_8055CD68;
extern int fn_802C2C00(int);
extern void fn_8012F57C(float *, void *, void *, float);
extern void fn_802C9900(void);
extern void fn_802C9904(void);
extern void fn_802C744C(int, float *);
extern void fn_802C70AC(int, float *, int, int);
extern int fn_8023389C(int, unsigned int, int, float *, char *, int, ...);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802AD4C4(void *arg0, int arg1, float t) {
    char *obj = (char *)arg0;
    float *off = (float *)arg1;
    float m[12];
    float sp30[4];
    float sp20[3];
    float sp14[3];
    float sp8[3];
    int h;
    int i;
    int boff;
    float one, eps, lo, c1, c2, zero, half;
    h = fn_802C2C00(0);
    one = lbl_80564AB4;
    eps = lbl_80564ACC;
    lo = lbl_80564AD0;
    c1 = lbl_80564AD4;
    c2 = lbl_80564AD8;
    zero = lbl_80564AB0;
    boff = 0;
    for (i = 0; i < *(int *)(obj + 0x24); i++, boff += 0xC) {
        char *seg = *(char **)(obj + 0x28) + boff;
        int n = *(int *)(seg + 4) - 1;
        int j;
        int jo = 0;
        for (j = 0; j < n; j++, jo += 0x38) {
            char *a = *(char **)(seg + 8) + jo;
            char *b = *(char **)(seg + 8) + (j + 1) * 0x38;
            float f23, u, f4, f6, a0 = *(float *)a;
            if (t >= a0 && t <= *(float *)b + eps) {
                char *c;
                float *p2;
                u = (t - a0) / (*(float *)b - a0);
                if (one < u) u = one;
                u = (u > zero) ? u : zero;
                f23 = zero + u * one;
                switch (*(int *)(a + 0x30)) {
                case 1:
                    if (f23 < lo) {
                        f23 = lo;
                    } else if (f23 > one) {
                        f23 = one;
                    } else if (f23 > zero) {
                        f23 = f23 * (c1 * f23 * f23) + c2 * f23 * f23;
                    } else {
                        f23 = f23 * (c1 * f23 * f23) - c2 * f23 * f23;
                    }
                    break;
                case 2:
                    f23 = f23 * f23;
                    break;
                case 3:
                    f23 = one - (one - f23) * (one - f23);
                    break;
                }
                fn_8012F57C(sp30, a + 0x20, b + 0x20, f23);
                sp20[2] = *(float *)(a + 0x1C) + f23 * (*(float *)(b + 0x1C) - *(float *)(a + 0x1C));
                sp20[1] = *(float *)(a + 0x18) + f23 * (*(float *)(b + 0x18) - *(float *)(a + 0x18));
                sp20[0] = *(float *)(a + 0x14) + f23 * (*(float *)(b + 0x14) - *(float *)(a + 0x14));
                if (off != 0) f4 = off[0]; else f4 = lbl_80564AB4;
                if (off != 0) {
                    sp20[0] += off[1];
                    sp20[1] += off[2];
                    sp20[2] += off[3];
                }
                f6 = one;
                {
                    float x = sp30[0], y = sp30[1], z = sp30[2], w = sp30[3];
                    float y2 = y + y, z2 = z + z, x2 = x + x;
                    float yy = y * y2, zz = z * z2, xx = x * x2;
                    float wx = w * x2, wy = w * y2, wz = w * z2;
                    float yz = y * z2, xz = x * z2, xy = x * y2;
                    m[0] = one - (yy + zz);
                    m[4] = one - (xx + zz);
                    m[7] = yz - wx;
                    m[8] = one - (xx + yy);
                    m[5] = yz + wx;
                    m[2] = xz - wy;
                    m[6] = xz + wy;
                    m[3] = xy - wz;
                    m[1] = xy + wz;
                    m[9] = sp20[0] * f4;
                    m[10] = sp20[1] * f4;
                    m[11] = sp20[2] * f4;
                }
                sp14[2] = *(float *)(a + 0xC) + f23 * (*(float *)(b + 0xC) - *(float *)(a + 0xC));
                sp14[1] = *(float *)(a + 8) + f23 * (*(float *)(b + 8) - *(float *)(a + 8));
                sp14[0] = *(float *)(a + 4) + f23 * (*(float *)(b + 4) - *(float *)(a + 4));
                c = *(char **)(obj + 0x20) + *(int *)seg * 0x28;
                p2 = *(float **)(c + 8);
                if (p2 != 0) {
                    m[9] += p2[1] * f4;
                    m[10] += p2[2] * f4;
                    m[11] += p2[3] * f4;
                    f6 = one * (*(float **)(c + 8))[0];
                }
                if (*(int *)c == 2) {
                    if (sp8 == (float *)(c + 0x14)) {
                        float c14 = *(float *)(c + 0x14), c18 = *(float *)(c + 0x18), c1c = *(float *)(c + 0x1C);
                        sp8[0] = c1c * m[6] + (c14 * m[0] + c18 * m[3]);
                        sp8[1] = c1c * m[7] + (c14 * m[1] + c18 * m[4]);
                        sp8[2] = c1c * m[8] + (c14 * m[2] + c18 * m[5]);
                    } else {
                        sp8[0] = *(float *)(c + 0x1C) * m[6] + (*(float *)(c + 0x14) * m[0] + *(float *)(c + 0x18) * m[3]);
                        sp8[1] = *(float *)(c + 0x1C) * m[7] + (*(float *)(c + 0x14) * m[1] + *(float *)(c + 0x18) * m[4]);
                        sp8[2] = *(float *)(c + 0x1C) * m[8] + (*(float *)(c + 0x14) * m[2] + *(float *)(c + 0x18) * m[5]);
                    }
                    m[9] += sp8[0];
                    m[10] += sp8[1];
                    m[11] += sp8[2];
                    {
                        float k = f6 * (f4 * (sp14[0] * *(float *)(c + 0x10)));
                        m[0] *= k; m[1] *= k; m[2] *= k;
                        k = f6 * (f4 * (sp14[1] * *(float *)(c + 0x10)));
                        m[3] *= k; m[4] *= k; m[5] *= k;
                        k = f6 * (f4 * (sp14[2] * *(float *)(c + 0x10)));
                        m[6] *= k; m[7] *= k; m[8] *= k;
                    }
                    fn_802C9900();
                    {
                        int r;
                        if (*(int **)(c + 0x24) != 0) r = **(int **)(c + 0x24); else r = *(int *)(c + 0x20);
                        if (r < 0) {
                            fn_802C744C(*(int *)(c + 0xC), m);
                        } else {
                            fn_802C70AC(*(int *)(c + 0xC), m, -1, 1 << r);
                        }
                    }
                    fn_802C9904();
                } else if (*(int *)c == 1) {
                    unsigned int col = *(unsigned int *)(c + 0x14);
                    float lerp = *(float *)(a + 0x10) + f23 * (*(float *)(b + 0x10) - *(float *)(a + 0x10));
                    float v = lerp * (float)(col >> 24);
                    int iv;
                    half = lbl_80564AC0;
                    if (v < zero) v = v - half; else v = half + v;
                    iv = (int)v;
                    if (iv < 0) iv = 0;
                    if (iv > 0xFF) iv = 0xFF;
                    fn_8023389C(*(int *)(c + 0xC), (col & 0x00FFFFFF) | ((unsigned int)iv << 24), *(int *)(c + 0x10), m, &lbl_8055CD68, *(int *)(c + 0x1C),
                        zero, zero, zero, f6 * (f4 * (sp14[0] * *(float *)(c + 0x18))), one);
                }
                break;
            }
        }
    }
    fn_802C2C00(h);
}
#pragma pop

#pragma push
#pragma processor 750
extern void fn_8023895C(void);
extern void fn_80238B44(int, int, int, int, int);
extern void fn_80238A80(int, int, int, const char *, ...);
extern void fn_802389E4(void);
extern char lbl_80349F84[];
extern char lbl_80349F98[];
extern int lbl_8055CD1C;
extern void *lbl_804BD7C0[];
void fn_802ADBB4(void) {
    /* Renders a debug overlay for the current animation entry: updates the time offset while
       active, draws index/name and elapsed time, and evaluates the selected animation. */
    int currentTime = fn_802E2C20();
    float elapsedSeconds;
    int isValidIndex;

    if ((unsigned char)lbl_8055F94C != 0) {
        lbl_8055F944 = currentTime - lbl_8055F948;
    }
    elapsedSeconds = (float)(currentTime - lbl_8055F944) * 0.001f;
    fn_8023895C();
    fn_80238B44(0, 0, 0x12C, 0x32, 0xC0000000);
    isValidIndex = (lbl_8055F940 >= 0 && lbl_8055F940 < (int)lbl_8055F93C);
    fn_80238A80(10, 10, 0xC0FFFFFF, lbl_80349F84, lbl_8055F940, isValidIndex ? lbl_804BD7C0[lbl_8055F940] : &lbl_8055CD1C);
    fn_80238A80(10, 30, 0xC0FFFFFF, lbl_80349F98, elapsedSeconds);
    fn_802389E4();
    if (lbl_8055F940 >= 0 && lbl_8055F940 < (int)lbl_8055F93C) {
        fn_802AD4C4(lbl_804BD7C0[lbl_8055F940], 0, elapsedSeconds);
    }
}
#pragma pop

#pragma scheduling on
int fn_802ADCF8(int key) {
    /* Debug menu key handler: D-pad/select/enter-like controls update animation index or timer state. */
    int newIndex;
    int maxIndexMinus1;
    int nextIndex;
    int toggle;

    switch (key) {
    case 0x5B: /* move up */
        nextIndex = lbl_8055F940 - 1;
        lbl_8055F940 = nextIndex < -1 ? -1 : nextIndex;
        return 1;
    case 0x5D: /* move down */
        maxIndexMinus1 = (int)lbl_8055F93C - 1;
        newIndex = lbl_8055F940 + 1;
        if (maxIndexMinus1 < newIndex) {
            newIndex = maxIndexMinus1;
        }
        lbl_8055F940 = newIndex;
        return 1;
    case 0x22: /* reset timer */
        lbl_8055F944 = fn_802E2C20();
        lbl_8055F948 = 0;
        return 1;
    case 0x27: /* toggle timer */
        toggle = ((unsigned char)lbl_8055F94C == 0);
        lbl_8055F94C = toggle;
        if (toggle) {
            lbl_8055F948 = fn_802E2C20() - lbl_8055F944;
        }
        return 1;
    default:
        return 0;
    }
}

void *fn_802ADDD8(void *arg0,int arg1) {
 int *obj; int data;
 obj=(int *)((void*(*)(int, void*))fn_801284F8)(0x10,&lbl_80349FA4);
 if(obj){data=(int)fn_8012850C(arg1*0x74,&lbl_8055CD70);obj[0]=data;obj[2]=arg1;obj[1]=0;obj[3]=data;}
 *(int **)arg0=obj; *(float *)((char *)arg0+4)=lbl_8055E3C8; return arg0;
}

extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_802AD30C(void *);
#pragma scheduling invalid_target
void *fn_802ADE60(void **holder, int freeHolder) {
    int entryCount;
    int entryOffset;
    void *set;
    int zero;
    /* Destroy an entry-set holder: release each entry's resource, free the set
       buffer and clear the header, then optionally free the holder itself. */
    if (holder != 0) {
        entryCount = *(int *)((char *)*holder + 4);
        entryOffset = entryCount * 0x74;
        goto loop_test;
        do {
            fn_802AD30C(*(void **)(*(char **)*holder + entryOffset + 0x64));
loop_test:
            entryOffset -= 0x74;
        } while (entryCount-- > 0);
        *(int *)((char *)*holder + 4) = 0;
        set = *holder;
        if (set != 0) {
            if (set != 0) {
                fn_80128670(*(void **)((char *)set + 0xC));
                if (set != 0) {
                    zero = 0;
                    *(int *)((char *)set + 0) = zero;
                    *(int *)((char *)set + 4) = zero;
                    *(int *)((char *)set + 8) = zero;
                }
            }
            fn_80128668(set);
        }
        if (freeHolder > 0) fn_80128668(holder);
    }
    return holder;
}
int fn_802ADF34(void **arg0, char *arg1, int arg2) {
    int result;
    char *header;
    int count;
    char *dst;
    char *entry;
    int index;
    char *base;
    unsigned char c;
    result = fn_802AC4A8(arg1, arg2);
    if (result != 0) {
        header = (char *)*arg0;
        index = ((int *)header)[1];
        base = ((char **)header)[0];
        entry = &base[index * 0x74];
        index++;
        ((int *)header)[1] = index;
        dst = entry;
        count = 0x64;
        goto copy;
check:
        count--;
        if (count > 0) goto copy;
        dst[-1] = 0;
        goto copied;
copy:
        c = *arg1++;
        *dst++ = c;
        if ((signed char)c != 0) goto check;
copied:
        *(int *)(entry + 0x64) = result;
        entry[0x68] = 0;
        entry[0x69] = 0;
        header = (char *)*arg0;
        return ((int *)header)[1] - 1;
    }
    return -1;
}
#pragma scheduling on
void fn_802ADFF4(int **arg0,int arg1){unsigned char *p=*(unsigned char **)*arg0+arg1*0x74;if(p[0x68]==0){p[0x68]=1;p[0x69]=0;*(float *)(p+0x6c)=lbl_8055E3C8;}}

/* Pause an animation entry by index, recording its pause time; warn and mark it running if it was not already started. */
void fn_802AE02C(void *manager, int animIndex) {
    char **entriesHolder;
    char *entriesBase;
    unsigned char *entry;
    entriesHolder = *(char ***)manager;
    entriesBase = *entriesHolder;
    entry = (unsigned char *)entriesBase + animIndex * 0x74;
    if (!entry[0x69]) {
        if (!entry[0x68]) {
            fn_802E30C8(lbl_80349FB0, animIndex, animIndex);
            entry[0x68] = 1;
            *(float *)(entry + 0x6c) = *(float *)((char *)manager + 4);
        }
        entry[0x69] = 1;
        *(float *)(entry + 0x70) = *(float *)((char *)manager + 4);
    }
}

void fn_802AE0B8(int **arg0,int arg1){unsigned char *p; p=(unsigned char *)**arg0+arg1*0x74;if(p[0x69])p[0x69]=0;}

void fn_802AE0E0(void **arg0) {
    int off;
    int i;
    i = 0;
    off = 0;
    while (i < *(int *)(*(char **)arg0 + 4)) {
        *(unsigned char *)(*(char **)*(char **)arg0 + off + 0x68) = 0;
        off += 0x74;
        i++;
    }
}

void fn_802AE118(void *arg0) {
    int off;
    int i;
    i = 0;
    off = 0;
    while (i < *(int *)(*(char **)arg0 + 4)) {
        if (*(unsigned char *)((unsigned char *)*(char **)*(char **)arg0 + off + 0x68) != 0) {
            *(float *)((unsigned char *)*(char **)*(char **)arg0 + off + 0x6C) =
                *(float *)((char *)arg0 + 4) -
                *(float *)(*(char **)((unsigned char *)*(char **)*(char **)arg0 + off + 0x64) + 0x2C);
        }
        off += 0x74;
        i++;
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Update each active entry's accumulated and previous time from the current time value. */
void fn_802AE168(void *arg0) {
    extern float lbl_8055E3C8;
    extern void fn_802AD414(void *, float);
    int offset = 0;
    int i = 0;
    unsigned char *entry;
    *(float *)((char *)arg0 + 4) = lbl_8055E3C8;
    while (i < *(int *)(*(char **)arg0 + 4)) {
        entry = (unsigned char *)*(char **)*(char **)arg0 + offset;
        if (entry[0x69]) {
            *(float *)(entry + 0x6c) = *(float *)(entry + 0x6c) + (*(float *)((char *)arg0 + 4) - *(float *)(entry + 0x70));
            *(float *)(entry + 0x70) = *(float *)((char *)arg0 + 4);
        }
        if (entry[0x68]) fn_802AD414(*(void **)(entry + 0x64), *(float *)((char *)arg0 + 4) - *(float *)(entry + 0x6c));
        offset += 0x74;
        i++;
    }
}
#pragma pop
/* Evaluate active timeline entries at the current time, passing an extra parameter. */
void fn_802AE220(void *arg0, int arg1) {
    int offset = 0;
    int i = 0;
    unsigned char *entry;

    while (i < *(int *)(*(char **)arg0 + 4)) {
        entry = (unsigned char *)*(char **)*(char **)arg0 + offset;
        if (entry[0x68]) {
            fn_802AD4C4(*(void **)(entry + 0x64), arg1,
                        *(float *)((char *)arg0 + 4) - *(float *)(entry + 0x6c));
        }
        offset += 0x74;
        i++;
    }
}

