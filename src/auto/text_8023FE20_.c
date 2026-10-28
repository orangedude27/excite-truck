// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
extern int fn_80131234(void *);
extern void *fn_8027DB40(s32);
extern void *memset(void *, int, unsigned int);
extern int fn_801345D8(void *, int, void *, int);
extern void *fn_8001668C(void *, s32);
extern void *fn_80016BC8(void *, s32);
extern void *fn_80018A8C(void *, s32, s32 *, s32);
extern s32 fn_80255918(void *, void *);
extern char lbl_8034287C[];
extern float lbl_80563750;
extern u8 lbl_8055F1FC;
extern s32 lbl_8055F200;
extern float lbl_80563758;
extern char lbl_803425A8[];
extern char lbl_8034288C[];
extern s32 fn_8023512C(char *, s32, char *, s32);
extern s32 fn_80232578(char *, char *, s32);
extern char lbl_80498828[];
extern void *fn_80241098(void *);
extern void fn_802E317C(char *, ...);
void fn_8023FE20(void) {
    register int *p = (int *)lbl_80498828;
    *p++ = -1;
    p[3] = -1;
}

s32 fn_8023FE34(void) {
    register s32 *p = (s32 *)lbl_80498828;
    s32 result = 0;
    if (*p++ >= 0) result = 1;
    if (p[3] < 0) return result;
    return result + 1;
}

extern char lbl_803422C0[];
#pragma scheduling invalid_target
void fn_8023FE60(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    register s32 *cursor = (s32 *)lbl_80498828;
    register s32 found = 0;
    register s32 index = 0;
    for (; index < 2; cursor += 4, index++) {
        if (cursor[0] < 0) continue;
        if (found == arg0) {
            if (arg1 != 0) {
                register s32 *table = (s32 *)lbl_80498828;
                table += index * 4;
                *arg1 = table[2];
            }
            if (arg2 != 0) {
                register s32 *table = (s32 *)lbl_80498828;
                table += index * 4;
                *arg2 = table[3];
            }
            if (arg3 != 0)
                *arg3 = *(s32 *)((char *)lbl_80498828 + index * 16);
            return;
        }
        found++;
    }
    fn_802E317C(lbl_803422C0, arg0, found);
}
#pragma scheduling on
extern char lbl_80342618[];
s32 fn_802407B0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

s32 fn_802407F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void *fn_80240830(void *arg0, s32 arg1) {
    register void *prev;
    if (arg0 != 0) {
        prev = *(void **)((char *)arg0 + 0x24);
        *(void **)((char *)arg0 + 0x0C) = lbl_80342618;
        if (prev != 0) {
            register void *vtable = *(void **)prev;
            register void *method = *(void **)((char *)vtable + 8);
            ((void (*)(void *, s32))method)(prev, 1);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern char lbl_80342618[];
extern char lbl_803426B0[];
extern s32 lbl_8055F1F4;
extern s32 fn_80235380(s32, s32);
void *fn_802408B0(void *arg0, s32 arg1) {
    s32 temp_r4;
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 0xC) = lbl_803426B0;
        *(void **)((char *)arg0 + 0x10) = lbl_803426B0 + 0x18;
        temp_r4 = lbl_8055F1F4;
        lbl_8055F1F4 = temp_r4 - 1;
        fn_80235380(*(s32 *)((char *)arg0 + 0x44), temp_r4);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern char lbl_80342734[];
extern s32 fn_802328D4(s32, s32);
void *fn_80240928(void *arg0, s32 arg1) {
    s32 zero = 0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg0 + 0x24) = zero;
        *(void **)arg0 = lbl_80342734;
        *(s32 *)((char *)arg0 + 0x20) = zero;
        fn_802328D4(*(s32 *)((char *)arg0 + 0x18), (s32)lbl_80342734);
        *(s32 *)((char *)arg0 + 0x18) = zero;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802409A4(void *arg0, signed char arg1) {
    *(signed char *)((char *)arg0 + 0x2E8) = arg1;
}

void fn_802409AC(void *arg0, s32 arg1) {
    s32 count = *(s32 *)((char *)arg0 + 0x2C);
    s32 i;
    char *entry = (char *)arg0;
    void *item;
    *(s32 *)(entry + 0x18 + count * 4) = arg1;
    *(s32 *)(entry + 0x2C) = count + 1;
    for (i = 0; i < *(s32 *)(entry + 0x2C); i++) {
        s32 value = **(s32 **)(entry + 0x34);
        s32 selected = *(u8 *)(entry + 0x38) != 0 && i == *(s32 *)(entry + 0x30);
        item = *(void **)(entry + 0x18);
        entry += 4;
        *(u8 *)item = selected;
        *(s32 *)((char *)item + 4) = value;
    }
}

void *fn_80240A1C(void *arg0, int *arg1, void *arg2) {
extern unsigned char *fn_802E85B8(int); extern char lbl_80342650[]; extern char lbl_8055BD60;
char *base=(char*)arg0; char *dst; char *src; int i,n,v; unsigned char c; 
*(void**)(base+0x28)=arg2; *(void**)base=lbl_80342650; *(int*)(base+0x14)=0; *(int*)(base+0x2c)=0; *(int*)(base+0x30)=0; *(int**)(base+0x34)=arg1; base[0x38]=1;
dst=base+0x39;src=&lbl_8055BD60;for(n=0;n<32;n++){c=*src++;*dst++=c;if((signed char)c==0)break;}if(n==31)*dst=0;
*(int*)(*(char**)(base+0x28)+0xd8)=*arg1;
v=*arg1;
if(v<0){dst=base+0x39;src=&lbl_8055BD60;for(n=0;n<32;n++){c=*src++;*dst++=c;if((signed char)c==0)break;}if(n==31)*dst=0;}
else{src=(char*)fn_802E85B8(v);dst=base+0x39;for(n=0;n<32;n++){c=*src++;*dst++=c;if((signed char)c==0)break;}if(n==31)*dst=0;}
for(i=0;i<*(int*)(base+0x2c);i++){char *out=*(char**)(base+i*4+0x18);out[0]=base[0x38]&&i==*(int*)(base+0x30);*(int*)(out+4)=*arg1;}
return arg0;
}

#pragma optimize_for_size off
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_80240BA4(void *arg0, s32 arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    s32 index, result, i, n, wordA, wordB, count, j;
    void *item, *record, *ctx, *info, *vtable, *infoDst;
    register void *self = arg0;
    register void *desired = arg2;
    char *src, *dst, *entries, *output, *zeroBase, *textItem, *object;
    signed char c;
    struct Collection {
        virtual s32 f0() = 0;
        virtual s32 f1() = 0;
        virtual s32 f2() = 0;
        virtual s32 getCount() = 0;
        virtual void *getItem(s32) = 0;
        virtual s32 getResult(s32) = 0;
        virtual void f8() = 0;
        virtual void f9() = 0;
        virtual void f10() = 0;
        virtual void f11() = 0;
        virtual void f12() = 0;
        virtual void f13() = 0;
        virtual void f14() = 0;
        virtual void f15() = 0;
        virtual void f16() = 0;
        virtual void f17() = 0;
        virtual void f18() = 0;
        virtual void f19() = 0;
        virtual void f20() = 0;
        virtual void f21() = 0;
        virtual void f22() = 0;
        virtual void f23() = 0;
        virtual void draw(s32, void *, void *) = 0;
    };

    *(s32 *)((u8 *)self + 0x10) = arg1;
    *(u8 *)((u8 *)self + 0x0) = 0;
    *(s32 *)((u8 *)self + 0x4) = -1;
    *(u8 *)((u8 *)self + 0x8) = 0;
    *(void **)((u8 *)self + 0x0C) = lbl_80342618;
    *(void **)((u8 *)self + 0x14) = desired;
    *(void **)((u8 *)self + 0x18) = arg3;
    *(void **)((u8 *)self + 0x1C) = arg4;
    *(void **)((u8 *)self + 0x20) = arg5;
    *(void **)((u8 *)self + 0x24) = fn_8027DB40(6);
    *(u8 *)((u8 *)self + 0x8) = 1;
    *(s32 *)((u8 *)self + 0x28) = 0;

    count = ((Collection *)*(void **)((u8 *)self + 0x24))->getCount();
    j = 0;
    while (j < count) {
        item = ((Collection *)*(void **)((u8 *)self + 0x24))->getItem(j);
        record = fn_8001668C(item, 0);
        if (*(s32 *)((u8 *)record + 4) == *(s32 *)desired) {
            *(s32 *)((u8 *)self + 0x28) = j;
            break;
        }
        j++;
    }

    index = *(s32 *)((u8 *)self + 0x28);
    if (index < 0) goto done;
    if (index >= ((Collection *)*(void **)((u8 *)self + 0x24))->getCount()) goto done;

    item = ((Collection *)*(void **)((u8 *)self + 0x24))->getItem(index);
    record = fn_8001668C(item, 0);
    *(s32 *)(*(void **)((u8 *)self + 0x14)) = *(s32 *)((u8 *)record + 4);
    *(s32 *)(*(void **)((u8 *)self + 0x10)) = *(s32 *)((u8 *)record + 0x9C);

    dst = (char *)arg0 + 0x2C;
    src = (char *)item;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    src = (char *)record + 0xC;
    dst = (char *)arg0 + 0x4C;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    result = ((Collection *)*(void **)((u8 *)self + 0x24))->getResult(*(s32 *)((u8 *)self + 0x28));
    *(s32 *)((u8 *)self + 0x6C) = result;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x20) + 0xDD) = (result == 0);

    ctx = *(void **)((u8 *)self + 0x18);
    if (*(void **)((u8 *)ctx + 0x28) != 0) {
        index = *(s32 *)((u8 *)ctx + 0x2C);
        item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
        *(s32 *)((u8 *)item + 4) = index;
    }
    *(void **)((u8 *)ctx + 0x28) = record;
    index = *(s32 *)((u8 *)ctx + 0x2C);
    if (*(s32 *)((u8 *)record + 0x98) - 1 < index) {
        index = *(s32 *)((u8 *)record + 0x98) - 1;
    }
    *(s32 *)((u8 *)ctx + 0x2C) = index;

    item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
    index = *(s32 *)((u8 *)item + 4);
    *(s32 *)((u8 *)ctx + 0x2C) = index;
    *(u8 *)((u8 *)ctx + 0x5C) = 0;
    if (index >= 0 && index < *(s32 *)((u8 *)record + 0x98)) {
        item = *(void **)((u8 *)record + 0x64 + index * 4);
        *(void **)(*(void **)((u8 *)ctx + 0x34)) = item;
        fn_80255918(*(void **)((u8 *)ctx + 0x38), item);
        ((int (*)(void *, int, void *, ...))fn_801345D8)(
            (u8 *)ctx + 0x5C, 0x40, lbl_8034287C,
            *(s32 *)((u8 *)ctx + 0x2C) + 1);
        src = (char *)fn_80131234((u8 *)ctx + 0x5C);
        dst = (char *)ctx + 0x5C;
        n = 0x40;
        do {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
            c = *src++;
            *dst++ = c;
        } while (c != 0);
    }

    *(s32 *)(*(void **)((u8 *)ctx + 0x30)) = *(s32 *)((u8 *)ctx + 0x2C);
    *(s32 *)((u8 *)ctx + 0x48) = -0xFA;
    *(float *)((u8 *)ctx + 0x4C) = (float)*(s32 *)((u8 *)ctx + 0x2C);
    *(float *)((u8 *)ctx + 0x50) = (float)*(s32 *)((u8 *)ctx + 0x2C);

    infoDst = *(void **)((u8 *)self + 0x1C);
    info = fn_80018A8C((u8 *)self + 0x2C, *(s32 *)((u8 *)ctx + 0x2C),
                       (s32 *)*(void **)((u8 *)ctx + 0x30),
                       *(s32 *)((u8 *)ctx + 0x2C));
    if (info != 0) {
        ((s32 *)infoDst)[0] = ((s32 *)info)[0];
        wordA = ((s32 *)info)[2];
        wordB = ((s32 *)info)[1];
        ((s32 *)infoDst)[1] = wordB;
        ((s32 *)infoDst)[2] = wordA;
        wordA = ((s32 *)info)[4];
        wordB = ((s32 *)info)[3];
        ((s32 *)infoDst)[3] = wordB;
        ((s32 *)infoDst)[4] = wordA;
        wordA = ((s32 *)info)[6];
        wordB = ((s32 *)info)[5];
        ((s32 *)infoDst)[5] = wordB;
        ((s32 *)infoDst)[6] = wordA;
        wordA = ((s32 *)info)[8];
        wordB = ((s32 *)info)[7];
        ((s32 *)infoDst)[7] = wordB;
        ((s32 *)infoDst)[8] = wordA;
        wordA = ((s32 *)info)[10];
        wordB = ((s32 *)info)[9];
        ((s32 *)infoDst)[9] = wordB;
        ((s32 *)infoDst)[10] = wordA;

        entries = (char *)infoDst;
        zeroBase = (char *)infoDst;
        output = (char *)infoDst + 0xF4;
        textItem = (char *)infoDst + 8;
        object = (char *)infoDst + 0x2C;
        i = 0;
        do {
            src = *(char **)(entries + 4);
            if (src != 0) {
                dst = output;
                n = 0x64;
                do {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                    c = *src++;
                    *dst++ = c;
                } while (c != 0);
            } else {
                *(u8 *)(zeroBase + 0xF4) = 0;
            }
            ((Collection *)object)->draw(i, textItem, (u8 *)infoDst + 0x2E8);
            entries += 8;
            zeroBase += 0x64;
            output += 0x64;
            textItem += 8;
            object += 0x28;
            i++;
        } while (i < 5);
    } else {
        memset(infoDst, 0, 0x2C);
        *(u8 *)((u8 *)infoDst + 0xF4) = 0;
        *(u8 *)((u8 *)infoDst + 0x158) = 0;
        *(u8 *)((u8 *)infoDst + 0x1BC) = 0;
        *(u8 *)((u8 *)infoDst + 0x220) = 0;
        *(u8 *)((u8 *)infoDst + 0x284) = 0;
    }
done:
    return arg0;
}
#pragma scheduling on
#pragma cplusplus reset

extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern void *memset(void *, int, unsigned int);
void fn_80241010(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32 *)((u8 *)arg0 + 0x24) = arg2;
    *(s32 *)((u8 *)arg0 + 0x1C) = arg1 + 1;
    *(s32 *)((u8 *)arg0 + 0x20) = arg3;
}

void *fn_80241024(void *arg0) {
    fn_8002F53C((u8 *)arg0 + 0x2C, fn_80241098, fn_80240928, 0x28, 5);
    memset(arg0, 0, 0x2C);
    *(u8 *)((u8 *)arg0 + 0xF4) = 0;
    *(u8 *)((u8 *)arg0 + 0x158) = 0;
    *(u8 *)((u8 *)arg0 + 0x1BC) = 0;
    *(u8 *)((u8 *)arg0 + 0x220) = 0;
    *(u8 *)((u8 *)arg0 + 0x284) = 0;
    return arg0;
}

void *fn_80241098(void *arg0) {
    s32 zero = 0;
    s32 minusOne = -1;
    *(void **)arg0 = lbl_80342734;
    *(s32 *)((u8 *)arg0 + 0x14) = zero;
    *(s32 *)((u8 *)arg0 + 0x1C) = minusOne;
    *(s32 *)((u8 *)arg0 + 0x24) = zero;
    *(s32 *)((u8 *)arg0 + 0x20) = zero;
    *(s32 *)((u8 *)arg0 + 0x18) = ((s32 (*)(char *))fn_80232578)(lbl_8034288C);
    return arg0;
}

void *fn_802410F8(void *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 temp_r4;
    s32 temp_r3;
    float temp_f0;
    *(void **)((u8 *)arg0 + 0xC) = lbl_803426B0;
    *(s32 *)((u8 *)arg0 + 4) = -1;
    *(u8 *)arg0 = 0;
    *((u8 *)arg0 + 8) = 1;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
    *(void **)((u8 *)arg0 + 0x10) = lbl_803426B0 + 0x18;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x2C) = *arg2;
    *(s32 **)((u8 *)arg0 + 0x30) = arg2;
    *(s32 *)((u8 *)arg0 + 0x34) = arg1;
    *(s32 *)((u8 *)arg0 + 0x38) = arg3;
    temp_r4 = lbl_8055F1F4;
    *(s32 *)((u8 *)arg0 + 0x3C) = temp_r4;
    lbl_8055F1F4 = temp_r4 + 1;
    temp_r3 = ((s32 (*)(char *))fn_8023512C)(lbl_803425A8);
    temp_f0 = lbl_80563758;
    *(s32 *)((u8 *)arg0 + 0x44) = temp_r3;
    *(float *)((u8 *)arg0 + 0x58) = temp_f0;
    *(float *)((u8 *)arg0 + 0x54) = temp_f0;
    *(u8 *)((u8 *)arg0 + 0x5C) = 0;
    return arg0;
}

s32 fn_802411A4(s32 *arg0) {
    if (lbl_8055F1FC != 0) {
        *arg0 = lbl_8055F200;
        return 1;
    }
    return 0;
}

#pragma dont_inline on
extern void fn_8023FE20(void);
void fn_802411C8(void) { fn_8023FE20(); }
#pragma dont_inline reset

#pragma dont_inline on
extern s32 fn_8023FE34(void);
void fn_802411CC(void) { fn_8023FE34(); }
#pragma dont_inline reset

extern void fn_8023FE60();
void fn_802411D0(void) { fn_8023FE60(); }

#pragma dont_inline fn_802411D4
s32 fn_802411D4(void) {
    s32 var_r31;
    var_r31 = 0;
    if ((fn_802E8504(0) != 0) && (fn_802E8504(1) != 0)) {
        var_r31 = 1;
    }
    return var_r31;
}

extern u8 lbl_8055F1FC;
extern s32 lbl_8055F200;
extern float lbl_80563758;
extern char lbl_803425A8[];
extern char lbl_8034288C[];
s32 fn_8023512C(char *, s32, char *, s32);
s32 fn_80232578(char *, char *, s32);
void fn_80241224(void) {}

void fn_80241228(void) {
}

extern int fn_80230C30(float *, float *, int, int);
extern int fn_801345D8(void *, int, void *, int);
extern int fn_80131234(void *);
extern int fn_80232BA4(int, int, int, float, float, float, float, float);
extern int lbl_802FA300[3];
extern char lbl_80342898[];
extern float lbl_8056375C, lbl_80563760, lbl_80563764;
#pragma processor 750
void fn_8024122C(void *arg0) {
    char sp10[0x1E];
    float y, x;
    int index;
    float value;
    int b;
    int text;
    int *thresholds;
    volatile int *tag;
    int currentTag;
    fn_80230C30(&y, &x, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
    if (*(int *)((char *)arg0 + 0x1C) >= 0) {
        tag = *(volatile int * volatile *)((char *)arg0 + 0x24);
        thresholds = lbl_802FA300;
        currentTag = *tag;
        index = 0;
        if (currentTag != 0 && currentTag >= thresholds[0])
            index = 1;
        tag = *(volatile int * volatile *)((char *)arg0 + 0x24);
        currentTag = *tag;
        if (currentTag != 0 && currentTag >= thresholds[1])
            index = 2;
        tag = *(volatile int * volatile *)((char *)arg0 + 0x24);
        currentTag = *tag;
        if (currentTag != 0 && currentTag >= thresholds[2])
            index = 3;
        ((int (*)(void *, int, void *, ...))fn_801345D8)(sp10, 0x1E, lbl_80342898, *(int *)((char *)arg0 + 0x1C), index);
        value = lbl_8056375C;
        b = 0xA;
        if (*(unsigned char *)*(void **)((char *)arg0 + 0x20)) {
            value = lbl_80563760;
            b = 9;
        }
        text = fn_80131234(sp10);
        ((int (*)(int, int, int, int, float, float, float, float, float))fn_80232BA4)(text, *(int *)((char *)arg0 + 0x18), -0x100, b, y, x, value, lbl_80563758, lbl_80563764);
    }
}
#pragma processor reset
extern void fn_80216D28(void);
extern int fn_80214D50(int);
extern float fn_8023659C(int *);
extern float lbl_80563764, lbl_80563768, lbl_8056376C, lbl_80563770;
extern float lbl_80563774, lbl_80563778, lbl_8056377C;
#pragma optimize_for_size off
#pragma scheduling invalid_target
s32 fn_80241354(void *arg0, s32 arg1) {
    char *base = (char *)arg0;
    s32 direction = arg1;
    s32 active = 0;
    void *child;
    volatile unsigned char *dst;
    unsigned char *src;
    int i, n, count, index, frame, boundary;
    int *animation;
    unsigned char c;
    float t, curveValue;
    float start, end, diff, temp;
    int result;
    result = ((int (*)(void *))((void **)*(void **)(base + 0x0C))[4])(arg0);
    if (result != 0) {
        active = 1;
        switch (direction) {
        case 0x127:
        index = *(int *)(base + 0x2C) + 1;
        *(int *)(base + 0x2C) = index;
        count = *(int *)((char *)*(void **)(base + 0x28) + 0x98);
        boundary = 0;
        if (index >= count) {
            *(int *)(base + 0x2C) = count - 1;
            boundary = 1;
        }
        if (boundary != 0) {
            fn_80216D28();
            fn_80214D50(1);
            goto done;
        }
        if (*(void **)(base + 0x28) != 0) {
            index = *(volatile int *)(base + 0x2C);
            child = fn_80016BC8(*(void **)(base + 0x28), *(int *)(base + 0x3C));
            *(int *)((char *)child + 4) = index;
        }
        index = *(int *)(base + 0x2C);
        *(signed char *)(base + 0x5C) = 0;
        if (index >= 0 && index < *(int *)((char *)*(void **)(base + 0x28) + 0x98)) {
            child = *(void **)((char *)*(void **)(base + 0x28) + 0x64 + index * 4);
            **(void ***)(base + 0x34) = child;
            fn_80255918(*(void **)(base + 0x38), child);
            ((int (*)(void *, int, char *, ...))fn_801345D8)(base + 0x5C, 0x40, lbl_8034287C, *(int *)(base + 0x2C) + 1);
            src = (unsigned char *)fn_80131234(base + 0x5C);
            dst = (unsigned char *)(base + 0x5C);
            n = 0x40;
            goto copy_body_forward;
copy_check_forward:
            if (--n <= 0) {
                dst[-1] = 0;
                goto copy_done_forward;
            }
copy_body_forward:
            c = *src++;
            *dst++ = c;
            if ((signed char)c != 0) goto copy_check_forward;
copy_done_forward:
            ;
        }
        index = *(int *)(base + 0x2C);
        animation = *(int **)(base + 0x30);
        *animation = index;
        frame = (int)(fn_8023659C(animation) * lbl_80563768);
        temp = (float)(frame - *(int *)(base + 0x48)) / lbl_8056376C;
        t = lbl_80563764;
        if (t < temp) t = temp;
        if (t > lbl_80563758) t = lbl_80563758;
        curveValue = lbl_80563770;
        if (t >= lbl_80563770) {
            if (t > lbl_80563764) {
                curveValue = lbl_80563764;
            } else if (t > lbl_80563758) {
                curveValue = t * (lbl_80563774 * t * t) + lbl_80563778 * t * t;
            } else {
                curveValue = t * (lbl_80563774 * t * t) - lbl_80563778 * t * t;
            }
        }
        start = *(float *)(base + 0x4C);
        end = *(float *)(base + 0x50);
        diff = end - start;
        *(int *)(base + 0x48) = frame;
        *(float *)(base + 0x58) = lbl_8056377C;
        *(float *)(base + 0x4C) = start + curveValue * diff;
        *(float *)(base + 0x50) = (float)*(int *)(base + 0x2C);
        break;
        case 0x125:
        index = *(int *)(base + 0x2C) - 1;
        *(int *)(base + 0x2C) = index;
        boundary = 0;
        if (index < 0) {
            *(int *)(base + 0x2C) = 0;
            boundary = 1;
        }
        if (boundary != 0) {
            fn_80216D28();
            fn_80214D50(1);
            goto done;
        }
        if (*(void **)(base + 0x28) != 0) {
            index = *(volatile int *)(base + 0x2C);
            child = fn_80016BC8(*(void **)(base + 0x28), *(int *)(base + 0x3C));
            *(int *)((char *)child + 4) = index;
        }
        index = *(int *)(base + 0x2C);
        *(signed char *)(base + 0x5C) = 0;
        if (index >= 0 && index < *(int *)((char *)(char *)*(void **)(base + 0x28) + 0x98)) {
            child = *(void **)((char *)*(void **)(base + 0x28) + 0x64 + index * 4);
            **(void ***)(base + 0x34) = child;
            fn_80255918(*(void **)(base + 0x38), child);
            ((int (*)(void *, int, char *, ...))fn_801345D8)(base + 0x5C, 0x40, lbl_8034287C, *(int *)(base + 0x2C) + 1);
            src = (unsigned char *)fn_80131234(base + 0x5C);
            dst = (unsigned char *)(base + 0x5C);
            n = 0x40;
            goto copy_body_backward;
copy_check_backward:
            if (--n <= 0) {
                dst[-1] = 0;
                goto copy_done_backward;
            }
copy_body_backward:
            c = *src++;
            *dst++ = c;
            if ((signed char)c != 0) goto copy_check_backward;
copy_done_backward:
            ;
        }
        index = *(int *)(base + 0x2C);
        animation = *(int **)(base + 0x30);
        *animation = index;
        frame = (int)(fn_8023659C(animation) * lbl_80563768);
        temp = (float)(frame - *(int *)(base + 0x48)) / lbl_8056376C;
        t = lbl_80563764;
        if (t < temp) t = temp;
        if (t > lbl_80563758) t = lbl_80563758;
        curveValue = lbl_80563770;
        if (t >= lbl_80563770) {
            if (t > lbl_80563764) {
                curveValue = lbl_80563764;
            } else if (t > lbl_80563758) {
                curveValue = t * (lbl_80563774 * t * t) + lbl_80563778 * t * t;
            } else {
                curveValue = t * (lbl_80563774 * t * t) - lbl_80563778 * t * t;
            }
        }
        start = *(float *)(base + 0x4C);
        end = *(float *)(base + 0x50);
        diff = end - start;
        *(int *)(base + 0x48) = frame;
        *(float *)(base + 0x54) = lbl_8056377C;
        *(float *)(base + 0x4C) = start + curveValue * diff;
        *(float *)(base + 0x50) = (float)*(int *)(base + 0x2C);
        break;
        default:
        case 0x126:
            active = 0;
            break;
        }
    }
done:
    return active;
}
#pragma scheduling on
#pragma optimize_for_size on
void fn_80241DE8(void *arg0) {
    s32 *p = (s32 *)arg0;
    s32 *entry = p;
    s32 i;

    for (i = 0; i < p[11]; i++, entry += 1) {
        s32 *out = *(s32 **)(entry + 6);
        *out = (p[14] != 0 && i == p[12]);
        out[1] = *(s32 *)p[9];
    }
}

#pragma scheduling invalid_target
s32 fn_80241E40(void *arg0) {
    s32 i;
    void *entry;
    void *out;
    s32 value;
    s32 result;

    if (*(s32 *)*(s32 **)((char *)arg0 + 0x34) == fn_802E4A10() &&
        *(u8 *)((char *)arg0 + 0x38) == 0) {
        return 0;
    }
    entry = arg0;
    i = 0;
    while (i < *(s32 *)((char *)arg0 + 0x2C)) {
        value = *(s32 *)*(s32 **)((char *)arg0 + 0x34);
        result = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30)) ? 1 : 0;
        out = *(void **)((char *)entry + 0x18);
        entry = (char *)entry + 4;
        i++;
        *(u8 *)out = result;
        *(s32 *)((char *)out + 4) = value;
    }
    return 1;
}
#pragma scheduling on
s32 fn_80241EE8(s32 arg0) {
    return arg0 + 0x4C;
}

#pragma optimize_for_size off
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80241EF0(void *arg0, s32 arg1) {
    s32 index, result, i, n, wordA, wordB;
    void *item, *record, *ctx, *info, *vtable, *infoDst;
    char *src, *dst, *entries, *output, *zeroBase, *textItem, *object;
    signed char c;
    struct Collection {
        virtual s32 f0() = 0;
        virtual s32 f1() = 0;
        virtual s32 f2() = 0;
        virtual s32 getCount() = 0;
        virtual void *getItem(s32) = 0;
        virtual s32 getResult(s32) = 0;
        virtual void f8() = 0;
        virtual void f9() = 0;
        virtual void f10() = 0;
        virtual void f11() = 0;
        virtual void f12() = 0;
        virtual void f13() = 0;
        virtual void f14() = 0;
        virtual void f15() = 0;
        virtual void f16() = 0;
        virtual void f17() = 0;
        virtual void f18() = 0;
        virtual void f19() = 0;
        virtual void f20() = 0;
        virtual void f21() = 0;
        virtual void f22() = 0;
        virtual void f23() = 0;
        virtual void draw(s32, void *, void *) = 0;
    };

    index = *(s32 *)((u8 *)arg0 + 0x28);
    *(s32 *)((u8 *)arg0 + 0x28) = index + 1;
    if (*(s32 *)((u8 *)arg0 + 0x28) >=
        ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount()) {
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
    }
    index = *(s32 *)((u8 *)arg0 + 0x28);
    if (index < 0) return;
    if (index >= ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount()) return;
    item = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getItem(index);
    record = fn_8001668C(item, 0);
    *(s32 *)(*(void **)((u8 *)arg0 + 0x14)) = *(s32 *)((u8 *)record + 4);
    *(s32 *)(*(void **)((u8 *)arg0 + 0x10)) = *(s32 *)((u8 *)record + 0x9C);

    dst = (char *)arg0 + 0x2C;
    src = (char *)item;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    src = (char *)record + 0xC;
    dst = (char *)arg0 + 0x4C;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    result = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getResult(*(s32 *)((u8 *)arg0 + 0x28));
    *(s32 *)((u8 *)arg0 + 0x6C) = result;
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0xDD) = (result == 0);

    ctx = *(void **)((u8 *)arg0 + 0x18);
    if (*(void **)((u8 *)ctx + 0x28) != 0) {
        index = *(s32 *)((u8 *)ctx + 0x2C);
        item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
        *(s32 *)((u8 *)item + 4) = index;
    }
    *(void **)((u8 *)ctx + 0x28) = record;
    index = *(s32 *)((u8 *)ctx + 0x2C);
    if (*(s32 *)((u8 *)record + 0x98) - 1 < index) {
        index = *(s32 *)((u8 *)record + 0x98) - 1;
    }
    *(s32 *)((u8 *)ctx + 0x2C) = index;

    item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
    index = *(s32 *)((u8 *)item + 4);
    *(s32 *)((u8 *)ctx + 0x2C) = index;
    *(u8 *)((u8 *)ctx + 0x5C) = 0;
    if (index >= 0 && index < *(s32 *)((u8 *)record + 0x98)) {
        item = *(void **)((u8 *)record + 0x64 + index * 4);
        *(void **)(*(void **)((u8 *)ctx + 0x34)) = item;
        fn_80255918(*(void **)((u8 *)ctx + 0x38), item);
        ((int (*)(void *, int, void *, ...))fn_801345D8)(
            (u8 *)ctx + 0x5C, 0x40, lbl_8034287C,
            *(s32 *)((u8 *)ctx + 0x2C) + 1);
        src = (char *)fn_80131234((u8 *)ctx + 0x5C);
        dst = (char *)ctx + 0x5C;
        n = 0x40;
        do {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
            c = *src++;
            *dst++ = c;
        } while (c != 0);
    }

    *(s32 *)(*(void **)((u8 *)ctx + 0x30)) = *(s32 *)((u8 *)ctx + 0x2C);
    *(s32 *)((u8 *)ctx + 0x48) = -0xFA;
    *(float *)((u8 *)ctx + 0x4C) = (float)*(s32 *)((u8 *)ctx + 0x2C);
    *(float *)((u8 *)ctx + 0x50) = (float)*(s32 *)((u8 *)ctx + 0x2C);

    infoDst = *(void **)((u8 *)arg0 + 0x1C);
    info = fn_80018A8C((u8 *)arg0 + 0x2C, *(s32 *)((u8 *)ctx + 0x2C),
                       (s32 *)*(void **)((u8 *)ctx + 0x30),
                       *(s32 *)((u8 *)ctx + 0x2C));
    if (info != 0) {
        ((s32 *)infoDst)[0] = ((s32 *)info)[0];
        wordA = ((s32 *)info)[2];
        wordB = ((s32 *)info)[1];
        ((s32 *)infoDst)[1] = wordB;
        ((s32 *)infoDst)[2] = wordA;
        wordA = ((s32 *)info)[4];
        wordB = ((s32 *)info)[3];
        ((s32 *)infoDst)[3] = wordB;
        ((s32 *)infoDst)[4] = wordA;
        wordA = ((s32 *)info)[6];
        wordB = ((s32 *)info)[5];
        ((s32 *)infoDst)[5] = wordB;
        ((s32 *)infoDst)[6] = wordA;
        wordA = ((s32 *)info)[8];
        wordB = ((s32 *)info)[7];
        ((s32 *)infoDst)[7] = wordB;
        ((s32 *)infoDst)[8] = wordA;
        wordA = ((s32 *)info)[10];
        wordB = ((s32 *)info)[9];
        ((s32 *)infoDst)[9] = wordB;
        ((s32 *)infoDst)[10] = wordA;

        entries = (char *)infoDst;
        zeroBase = (char *)infoDst;
        output = (char *)infoDst + 0xF4;
        textItem = (char *)infoDst + 8;
        object = (char *)infoDst + 0x2C;
        i = 0;
        do {
            src = *(char **)(entries + 4);
            if (src != 0) {
                dst = output;
                n = 0x64;
                do {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                    c = *src++;
                    *dst++ = c;
                } while (c != 0);
            } else {
                *(u8 *)(zeroBase + 0xF4) = 0;
            }
            ((Collection *)object)->draw(i, textItem, (u8 *)infoDst + 0x2E8);
            entries += 8;
            zeroBase += 0x64;
            output += 0x64;
            textItem += 8;
            object += 0x28;
            i++;
        } while (i < 5);
    } else {
        memset(infoDst, 0, 0x2C);
        *(u8 *)((u8 *)infoDst + 0xF4) = 0;
        *(u8 *)((u8 *)infoDst + 0x158) = 0;
        *(u8 *)((u8 *)infoDst + 0x1BC) = 0;
        *(u8 *)((u8 *)infoDst + 0x220) = 0;
        *(u8 *)((u8 *)infoDst + 0x284) = 0;
    }
}
#pragma scheduling on
#pragma cplusplus reset
#pragma optimize_for_size on

extern void *fn_8001668C(void *, s32);
extern void *fn_80016BC8(void *, s32);
extern void *fn_80018A8C(void *, s32, s32 *, s32);
extern s32 fn_80255918(void *, void *);
extern char lbl_8034287C[];
extern float lbl_80563750;
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_802422DC(void *arg0, s32 arg1) {
    s32 index, result, i, n, wordA, wordB;
    void *item, *ctx, *info, *vtable, *infoDst;
    register void *record;
    char *src, *dst, *entries, *output, *zeroBase, *textItem, *object;
    signed char c;
    struct Collection {
        virtual s32 f0() = 0;
        virtual s32 f1() = 0;
        virtual s32 f2() = 0;
        virtual s32 getCount() = 0;
        virtual void *getItem(s32) = 0;
        virtual s32 getResult(s32) = 0;
        virtual void f8() = 0;
        virtual void f9() = 0;
        virtual void f10() = 0;
        virtual void f11() = 0;
        virtual void f12() = 0;
        virtual void f13() = 0;
        virtual void f14() = 0;
        virtual void f15() = 0;
        virtual void f16() = 0;
        virtual void f17() = 0;
        virtual void f18() = 0;
        virtual void f19() = 0;
        virtual void f20() = 0;
        virtual void f21() = 0;
        virtual void f22() = 0;
        virtual void f23() = 0;
        virtual void draw(s32, void *, void *) = 0;
    };

    index = *(s32 *)((u8 *)arg0 + 0x28) - 1;
    *(s32 *)((u8 *)arg0 + 0x28) = index;
    if (index < 0) {
        index = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount() - 1;
        *(s32 *)((u8 *)arg0 + 0x28) = index;
    }
    index = *(s32 *)((u8 *)arg0 + 0x28);
    if (index < 0) return;
    if (index >= ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount()) return;
    item = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getItem(index);
    record = fn_8001668C(item, 0);
    *(s32 *)(*(void **)((u8 *)arg0 + 0x14)) = *(s32 *)((u8 *)record + 4);
    *(s32 *)(*(void **)((u8 *)arg0 + 0x10)) = *(s32 *)((u8 *)record + 0x9C);

    dst = (char *)arg0 + 0x2C;
    src = (char *)item;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    src = (char *)record + 0xC;
    dst = (char *)arg0 + 0x4C;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    result = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getResult(*(s32 *)((u8 *)arg0 + 0x28));
    *(s32 *)((u8 *)arg0 + 0x6C) = result;
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0xDD) = (result == 0);

    ctx = *(void **)((u8 *)arg0 + 0x18);
    if (*(void **)((u8 *)ctx + 0x28) != 0) {
        index = *(s32 *)((u8 *)ctx + 0x2C);
        item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
        *(s32 *)((u8 *)item + 4) = index;
    }
    *(void **)((u8 *)ctx + 0x28) = record;
    index = *(s32 *)((u8 *)ctx + 0x2C);
    if (*(s32 *)((u8 *)record + 0x98) - 1 < index) {
        index = *(s32 *)((u8 *)record + 0x98) - 1;
    }
    *(s32 *)((u8 *)ctx + 0x2C) = index;

    item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
    index = *(s32 *)((u8 *)item + 4);
    *(s32 *)((u8 *)ctx + 0x2C) = index;
    *(u8 *)((u8 *)ctx + 0x5C) = 0;
    if (index >= 0 && index < *(s32 *)((u8 *)record + 0x98)) {
        item = *(void **)((u8 *)record + 0x64 + index * 4);
        *(void **)(*(void **)((u8 *)ctx + 0x34)) = item;
        fn_80255918(*(void **)((u8 *)ctx + 0x38), item);
        ((int (*)(void *, int, void *, ...))fn_801345D8)(
            (u8 *)ctx + 0x5C, 0x40, lbl_8034287C,
            *(s32 *)((u8 *)ctx + 0x2C) + 1);
        src = (char *)fn_80131234((u8 *)ctx + 0x5C);
        dst = (char *)ctx + 0x5C;
        n = 0x40;
        do {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
            c = *src++;
            *dst++ = c;
        } while (c != 0);
    }

    *(s32 *)(*(void **)((u8 *)ctx + 0x30)) = *(s32 *)((u8 *)ctx + 0x2C);
    *(s32 *)((u8 *)ctx + 0x48) = -0xFA;
    *(float *)((u8 *)ctx + 0x4C) = (float)*(s32 *)((u8 *)ctx + 0x2C);
    *(float *)((u8 *)ctx + 0x50) = (float)*(s32 *)((u8 *)ctx + 0x2C);

    infoDst = *(void **)((u8 *)arg0 + 0x1C);
    info = fn_80018A8C((u8 *)arg0 + 0x2C, *(s32 *)((u8 *)ctx + 0x2C),
                       (s32 *)*(void **)((u8 *)ctx + 0x30),
                       *(s32 *)((u8 *)ctx + 0x2C));
    if (info != 0) {
        ((s32 *)infoDst)[0] = ((s32 *)info)[0];
        wordA = ((s32 *)info)[2];
        wordB = ((s32 *)info)[1];
        ((s32 *)infoDst)[1] = wordB;
        ((s32 *)infoDst)[2] = wordA;
        wordA = ((s32 *)info)[4];
        wordB = ((s32 *)info)[3];
        ((s32 *)infoDst)[3] = wordB;
        ((s32 *)infoDst)[4] = wordA;
        wordA = ((s32 *)info)[6];
        wordB = ((s32 *)info)[5];
        ((s32 *)infoDst)[5] = wordB;
        ((s32 *)infoDst)[6] = wordA;
        wordA = ((s32 *)info)[8];
        wordB = ((s32 *)info)[7];
        ((s32 *)infoDst)[7] = wordB;
        ((s32 *)infoDst)[8] = wordA;
        wordA = ((s32 *)info)[10];
        wordB = ((s32 *)info)[9];
        ((s32 *)infoDst)[9] = wordB;
        ((s32 *)infoDst)[10] = wordA;

        entries = (char *)infoDst;
        zeroBase = (char *)infoDst;
        output = (char *)infoDst + 0xF4;
        textItem = (char *)infoDst + 8;
        object = (char *)infoDst + 0x2C;
        i = 0;
        do {
            src = *(char **)(entries + 4);
            if (src != 0) {
                dst = output;
                n = 0x64;
                do {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                    c = *src++;
                    *dst++ = c;
                } while (c != 0);
            } else {
                *(u8 *)(zeroBase + 0xF4) = 0;
            }
            ((Collection *)object)->draw(i, textItem, (u8 *)infoDst + 0x2E8);
            entries += 8;
            zeroBase += 0x64;
            output += 0x64;
            textItem += 8;
            object += 0x28;
            i++;
        } while (i < 5);
    } else {
        memset(infoDst, 0, 0x2C);
        *(u8 *)((u8 *)infoDst + 0xF4) = 0;
        *(u8 *)((u8 *)infoDst + 0x158) = 0;
        *(u8 *)((u8 *)infoDst + 0x1BC) = 0;
        *(u8 *)((u8 *)infoDst + 0x220) = 0;
        *(u8 *)((u8 *)infoDst + 0x284) = 0;
    }
}
#pragma scheduling on
#pragma cplusplus reset
s32 fn_802426C0(void *arg0) {
    s32 index = *(s32 *)((char *)arg0 + 0x28);
    void *object;
    volatile void **vtable;
    s32 count;
    if (index >= 0) {
        object = *(void **)((char *)arg0 + 0x24);
        vtable = *(volatile void ***)object;
        count = (*(s32 (**)(void *))((char *)vtable + 0x14))(object);
        if (index < count) {
            object = *(void **)((char *)arg0 + 0x24);
            vtable = *(volatile void ***)object;
            return (*(s32 (**)(void *, s32))((char *)vtable + 0x1c))(object, index);
        }
    }
    return 0;
}

extern void fn_80214A9C(s32);
extern void fn_80214AF0(s32);
extern void fn_802E317C(char *, ...);
extern u8 *fn_802E85B8(s32);
extern char lbl_80342840[];
extern char lbl_8055BD60;
#pragma scheduling invalid_target
void fn_80242738(void *arg0, s32 arg1) {
    s32 outer, i, n, count, selected, current, previous;
    s32 modeA, modeB, mode;
    u8 *base, *widget, *entry, *child, *list;
    u8 *src, *dst;
    signed char c;

    lbl_8055F1FC = 0;
    count = 2;
    base = (u8 *)arg0;
    outer = 0;
    do {
        widget = *(u8 **)(base + 0x18);
        **(s32 **)(widget + 0x34) = outer;
        *(s32 *)(*(u8 **)(widget + 0x28) + 0xD8) = **(s32 **)(widget + 0x34);

        selected = **(s32 **)(widget + 0x34);
        if (selected < 0) {
            src = (u8 *)&lbl_8055BD60;
            dst = widget + 0x39;
            n = 0x20;
            do {
                if (--n <= 0) {
                    dst[-1] = 0;
                    break;
                }
                c = *src++;
                *dst++ = (u8)c;
            } while (c != 0);
        } else {
            src = fn_802E85B8(selected);
            dst = widget + 0x39;
            n = 0x20;
            do {
                if (--n <= 0) {
                    dst[-1] = 0;
                    break;
                }
                c = *src++;
                *dst++ = (u8)c;
            } while (c != 0);
        }

        entry = base;
        i = 0;
        goto init_child_check;
init_child_body:
        child = *(u8 **)(entry + 0x18);
        *(u8 *)child = (*(u8 *)(widget + 0x38) != 0 &&
                        i == *(s32 *)(widget + 0x30));
        *(s32 *)(child + 4) = **(s32 **)(widget + 0x34);
        entry += 4;
        i++;
init_child_check:
        if (i < *(volatile s32 *)(widget + 0x2C)) goto init_child_body;
        outer++;
        *(s32 *)(widget + 0x34) = 2;
        base += 0x20;
    } while (outer < count);

    *(u8 *)((u8 *)arg0 + 0x58) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s32 *)((u8 *)arg0 + 0x50) = 0;

    modeA = *(s32 *)((u8 *)arg0 + 0x34);
    modeB = *(s32 *)((u8 *)arg0 + 0x54);
    selected = 0;
    mode = 0;
    if (modeA <= 1 || modeA == 4) {
        if (modeA == 4) selected = 1;
        if (modeB <= 1 || modeB == 4) {
            if (modeB == 4) selected++;
            mode = (selected - 2) >= 0;
        }
    }
    if (*(u8 *)((u8 *)arg0 + 0x58) != mode) {
        *(s32 *)((u8 *)arg0 + 0x30) = 0;
        *(s32 *)((u8 *)arg0 + 0x50) = 0;
    }

    base = (u8 *)arg0 + 0x18;
    for (outer = 0; outer < 2; outer++, base += 0x20) {
        current = *(s32 *)(base + 0x1C);
        previous = *(s32 *)(base + 0x18);
        if (current != previous) {
            switch (current) {
            case 0:
                break;
            case 1:
                fn_80214AF0(*(s32 *)(base + 4));
                fn_80214A9C(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                break;
            case 2:
            case 3:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                fn_80214AF0(*(s32 *)(base + 0x14));

                list = *(u8 **)base;
                *(u8 *)(list + 0x38) = 1;
                entry = list;
                selected = *(s32 *)(list + 0x30);
                i = 0;
                goto on_child_check;
on_child_body:
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (*(u8 *)(list + 0x38) != 0 && i == selected);
                *(s32 *)(child + 4) = **(s32 **)(list + 0x34);
                entry += 4;
                i++;
on_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto on_child_body;
                if (outer != 0 && current == 2) {
                    fn_80214A9C(*(s32 *)(base + 0x10));
                } else {
                    fn_80214AF0(*(s32 *)(base + 0x10));
                }
                break;
            case 4:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214AF0(*(s32 *)(base + 0x0C));
                fn_80214A9C(*(s32 *)(base + 0x14));
                fn_80214AF0(*(s32 *)(base + 0x10));

                list = *(u8 **)base;
                *(u8 *)(list + 0x38) = 0;
                entry = list;
                selected = *(s32 *)(list + 0x30);
                i = 0;
                goto off_child_check;
off_child_body:
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (*(u8 *)(list + 0x38) != 0 && i == selected);
                *(s32 *)(child + 4) = **(s32 **)(list + 0x34);
                entry += 4;
                i++;
off_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto off_child_body;
                break;
            default:
                fn_802E317C(lbl_80342840, 0, outer);
                break;
            }
            *(s32 *)(base + 0x18) = current;
        }
    }

    (mode != 0 ? fn_80214AF0 : fn_80214A9C)(0x1E);
    if (mode != 0) {
        for (i = 7; i <= 0xA; i++) {
            fn_80214A9C(i);
        }
    }
    *(u8 *)((u8 *)arg0 + 0x58) = (u8)mode;
}

extern s32 lbl_8055F1F8;
extern s32 fn_802E8504(s32);
#pragma cplusplus on
extern "C" s32 lbl_8055F1F8;
extern "C" s32 fn_802E8504(s32);
extern "C" u8 *fn_802E85B8(s32);
extern "C" void fn_80214A9C(s32);
extern "C" void fn_80214AF0(s32);
extern "C" void fn_802E317C(char *, ...);
#pragma optimize_for_size off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_80242B1C(void *arg0) {
    s32 refreshIndex;
    unsigned int outer;
    s32 i, n, selected, selectedValue, current, previous;
    s32 modeA, modeB, mode;
    s32 tick, quotient;
    u8 *base, *widget, *slot, *entry, *child, *list;
    u8 *src, *dst;
    char c;

    tick = lbl_8055F1F8 + 1;
    lbl_8055F1F8 = tick;
    if (tick - (tick / 10) * 10 == 0) {
        base = (u8 *)arg0;
        slot = base + 0x18;
        outer = 0;
        do {
            if (*(s32 *)(base + 0x34) > 1 &&
                fn_802E8504(**(s32 **)(*(u8 **)(base + 0x18) + 0x34)) == 0) {
                widget = *(u8 **)slot;
                **(s32 **)(widget + 0x34) = -1;
                *(s32 *)(*(u8 **)(widget + 0x28) + 0xD8) =
                    **(s32 **)(widget + 0x34);

#pragma optimize_for_size on
                selected = **(s32 **)(widget + 0x34);
                if (selected < 0) {
                    src = (u8 *)&lbl_8055BD60;
                    dst = widget + 0x39;
                    n = 0x20;
                    do {
                        if (--n <= 0) {
                            dst[-1] = 0;
                            break;
                        }
                        c = *src++;
                        *dst++ = (u8)c;
                    } while (c != 0);
                } else {
                    src = fn_802E85B8(selected);
                    dst = widget + 0x39;
                    n = 0x20;
                    do {
                        if (--n <= 0) {
                            dst[-1] = 0;
                            break;
                        }
                        c = *src++;
                        *dst++ = (u8)c;
                    } while (c != 0);
                }

#pragma optimize_for_size off
                entry = widget;
                i = 0;
                goto init_child_check;
init_child_body:
                selectedValue = **(s32 **)(widget + 0x34);
                n = (*(u8 *)(widget + 0x38) != 0 &&
                     i == *(s32 *)(widget + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i++;
init_child_check:
                if (i < *(volatile s32 *)(widget + 0x2C)) goto init_child_body;
                *(s32 *)(slot + 0x1C) = 1;
            }
            outer++;
            base += 0x20;
            slot += 0x20;
        } while (outer < 2U);
    }

#pragma optimize_for_size on
    modeA = *(s32 *)((u8 *)arg0 + 0x34);
    selected = 0;
    mode = 0;
    if (modeA <= 1) goto mode_a_ok;
    if (modeA == 4) goto mode_a_ok;
    mode = 0;
    goto mode_done;
mode_a_ok:
    if (modeA == 4) selected = 1;
    modeB = *(s32 *)((u8 *)arg0 + 0x54);
    if (modeB <= 1) goto mode_b_ok;
    if (modeB == 4) goto mode_b_ok;
    mode = 0;
    goto mode_done;
mode_b_ok:
    if (modeB == 4) selected++;
    mode = selected >= 2;
mode_done:
#pragma optimize_for_size off
    if (*(u8 *)((u8 *)arg0 + 0x58) != mode) {
        *(s32 *)((u8 *)arg0 + 0x30) = 0;
        *(s32 *)((u8 *)arg0 + 0x50) = 0;
    }

    base = (u8 *)arg0 + 0x18;
    for (refreshIndex = 0; (unsigned int)refreshIndex < 2U; refreshIndex++, base += 0x20) {
        current = *(s32 *)(base + 0x1C);
        previous = *(s32 *)(base + 0x18);
        if (current != previous) {
            switch (current) {
            case 0:
                break;
            case 1:
                fn_80214AF0(*(s32 *)(base + 4));
                fn_80214A9C(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                break;
            case 2:
            case 3:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                fn_80214AF0(*(s32 *)(base + 0x14));
                if (refreshIndex != 0 && *(s32 *)(base + 0x1C) == 2) {
                    fn_80214A9C(*(s32 *)(base + 0x10));
                } else {
                    fn_80214AF0(*(s32 *)(base + 0x10));
                }
                list = *(u8 **)base;
                *(u8 *)(list + 0x38) = 1;
                entry = list;
                i = 0;
                goto on_child_check;
on_child_body:
                selectedValue = **(s32 **)(list + 0x34);
                n = (*(u8 *)(list + 0x38) != 0 &&
                     i == *(s32 *)(list + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i++;
on_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto on_child_body;
                break;
            case 4:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214AF0(*(s32 *)(base + 0x0C));
                fn_80214A9C(*(s32 *)(base + 0x14));
                fn_80214AF0(*(s32 *)(base + 0x10));
                list = *(u8 **)base;
                *(u8 *)(list + 0x38) = 0;
                entry = list;
                i = 0;
                goto off_child_check;
off_child_body:
                selectedValue = **(s32 **)(list + 0x34);
                n = (*(u8 *)(list + 0x38) != 0 &&
                     i == *(s32 *)(list + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i++;
off_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto off_child_body;
                break;
            default:
                fn_802E317C(lbl_80342840, 0, refreshIndex);
                break;
            }
            *(s32 *)(base + 0x18) = *(s32 *)(base + 0x1C);
        }
    }

    (mode != 0 ? fn_80214AF0 : fn_80214A9C)(0x1E);
    if (mode != 0) {
        for (i = 7; i <= 0xA; i++) {
            fn_80214A9C(i);
        }
    }
    *(u8 *)((u8 *)arg0 + 0x58) = (u8)mode;
    if (fn_802411D4() == 0) {
        lbl_8055F1FC = 1;
        lbl_8055F200 = 0;
    }
}
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma optimize_for_size on
