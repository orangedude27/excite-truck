// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef float f32;
#define F(p,o) (*(f32 *)((char *)(p)+(o)))
#define I(p,o) (*(s32 *)((char *)(p)+(o)))
#define B(p,o) (*(unsigned char *)((char *)(p)+(o)))
extern s32 lbl_8055E0D4;
extern s32 lbl_8055E0D0;
extern s32 lbl_80559BF8;
extern void fn_80136AA8(void*);
extern void fn_80136A18(s32, s32);
extern s32 fn_801284F8(s32, s32*);
  extern s32 fn_801368F8(s32, s32);
extern f32 lbl_80561368;
extern f32 lbl_8056136C;
extern f32 lbl_80561370;
extern f32 lbl_80561374;
extern s32 lbl_8032BEB4[];
extern void fn_801376A8(s32, s32 *, s32, s32, s32 *);
extern void fn_80136D20(void *, s32);
extern s32 fn_8017960C(s32);
extern s32 fn_802C6C34(s32);
extern void *fn_801B2ED0(s32);
#pragma push
#pragma scheduling invalid_target
extern s32 lbl_8032BE98[];
extern s32 lbl_8032BEA8[];
extern s32 fn_8012850C(s32, s32);
extern s32 fn_801284E8(s32, s32);
extern s32 fn_8002F37C(s32, s32, s32, s32);
extern void *memset(void *, s32, s32);
extern float fn_8013672C(void);
extern void fn_801369EC(void *);
#pragma push
#pragma scheduling invalid_target
s32 fn_801368F8(s32 arg0, s32 arg1) {
    s32 pairs;
    s32 count;
    s32 stride;
    s32 size;
    s32 data;
    pairs = ((s32)((arg1 * (arg1 - 1)) >> 31) + arg1 * (arg1 - 1)) >> 1;
    *(s32 *)arg0 = arg1;
    count = 1;
    if (pairs > 1)
        count = pairs;
    fn_8012850C(count * 0x2C + 0x10, (s32)lbl_8032BE98);
    *(s32 *)(arg0 + 8) = fn_8002F37C((s32)&fn_801369EC, 0, 0x2C, count);
    stride = arg1 * 4 - arg1;
    size = stride * 4 + 0x18;
    *(s32 *)(arg0 + 0xC) = size;
    data = arg1 * size;
    *(s32 *)(arg0 + 0x10) = fn_801284E8((s32)lbl_8032BEA8, data);
    if (*(s32 *)(arg0 + 0x10) != 0 && *(s32 *)(arg0 + 8) != 0) {
        memset((void *)0, 0, data);
        fn_80136AA8((void *)arg0);
    }
    *(f32 *)(arg0 + 0x14) = fn_8013672C();
    return arg0;
}
#pragma pop

void fn_801369EC(void *arg0) {
    f32 value = lbl_80561368;
    *(s32 *)((char *)arg0 + 0x14) = -1;
    *(f32 *)((char *)arg0 + 0x28) = value;
    *(f32 *)((char *)arg0 + 0x24) = value;
    *(f32 *)((char *)arg0 + 0x20) = value;
    *(f32 *)((char *)arg0 + 0x1C) = value;
    *(s32 *)((char *)arg0 + 0xC) = -1;
    *(signed char *)arg0 = 0;
}

#pragma dont_inline on
void fn_80136A18(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        if (*(s32 *)(arg0 + 0x10) != 0) {
            fn_80128658();
            *(s32 *)(arg0 + 0x10) = 0;
        }
        if (*(s32 *)(arg0 + 8) != 0) {
            if (*(s32 *)(arg0 + 8) != 0)
                fn_80128670(*(s32 *)(arg0 + 8) - 0x10);
            *(s32 *)(arg0 + 8) = 0;
        }
        lbl_8055E0D0 = 0;
        if (arg1 > 0)
            fn_80128668((void *)arg0);
    }
}
#pragma dont_inline reset

void fn_80136CB8(void *arg0, s32 arg1) {
    s32 base;
    f32 value;
    fn_80136D20(arg0, arg1);
    value = lbl_80561368;
    base = *(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC);
    *(f32 *)((char *)base + 8) = value;
    *(f32 *)((char *)base + 0xC) = value;
    base = *(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC);
    *(f32 *)((char *)base + 0x10) = value;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma opt_propagation off
extern "C" void fn_80136D20(void *arg0, s32 arg1) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void *v4();
    };
    int stride = *(int*)((char*)arg0 + 0xC);
    void *base = *(void**)((char*)arg0 + 0x10);
    void *entry = (char*)base + arg1 * stride;
    void *obj = ((Dummy*)fn_801B2ED0(arg1))->v4();

    if (*(unsigned char*)((char*)entry + 0x15) != 0) {
        *(unsigned char*)((char*)entry + 0x14) = 0;
        void *r5 = *(void**)((char*)obj + 4);
        float f2 = *(float*)((char*)obj + 8);
        void *r4 = *(void**)((char*)r5 + 0x14);
        float f1 = *(float*)((char*)r5 + 0x2C);
        float f0 = *(float*)((char*)r4 + 0x2C);
        float f3 = *(float*)((char*)obj + 0x40);

        f0 = (f0 - f1) * f2 + f1;
        f2 = f3 + f0;

        f1 = *(float*)((char*)obj + 0x48) + *(float*)((char*)r5 + 0x30);
        if (*(unsigned char*)((char*)entry + 0x14) != 0) {
            f1 = *(float*)((char*)arg0 + 0x14) - f1;
        }

        *(float*)((char*)entry + 8) = *(float*)((char*)obj + 0x44);
        *(float*)((char*)entry + 0) = f2;
        *(float*)((char*)entry + 4) = f1;

        f2 = *(float*)((char*)entry + 0xC);
        *(float*)((char*)entry + 0xC) = *(float*)((char*)obj + 0x4C);

        if (*(unsigned char*)((char*)entry + 0x14) != 0) {
            *(float*)((char*)entry + 0xC) *= lbl_8056136C;
        }

        f0 = *(float*)((char*)entry + 0xC);
        f1 = (f0 - f2) / lbl_80561370;
        f3 = *(float*)((char*)entry + 0x10);
        f0 = (f1 - f3) * lbl_80561374 + f3;
        *(float*)((char*)entry + 0x10) = f0;

        unsigned char flag = *(unsigned char*)((char*)*(void**)((char*)obj + 4) + 0x35);
        *(unsigned char*)((char*)entry + 0x16) = flag;
        if ((flag & ~1) && (flag & 1)) {
            void *sub = *(void**)((char*)*(void**)((char*)obj + 4) + 0x14);
            if (!(*(unsigned char*)((char*)sub + 0x35) & 1)) {
                *(unsigned char*)((char*)entry + 0x16) &= ~1;
            }
        }
    } else {
        float zero = lbl_80561368;
        *(float*)((char*)entry + 4) = zero;
        *(float*)((char*)entry + 0) = zero;
        *(float*)((char*)entry + 0xC) = zero;
        *(float*)((char*)entry + 8) = zero;
        *(unsigned char*)((char*)entry + 0x16) = 0;
    }
}
#pragma opt_propagation reset
#pragma scheduling reset
#pragma cplusplus reset
#pragma pop

void fn_80136E8C(void *arg0, s32 arg1, signed char arg2) {
    *(signed char *)((char *)*(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC) + 0x15) = arg2;
}

void fn_80136EA4(void *arg0, s32 arg1) {
    s32 values[3];
    s32 *source;
    s32 stride;
    s32 index;
    s32 base;
    s32 destination;

    source = lbl_8032BEB4;
    values[0] = *source++;
    values[1] = *source++;
    values[2] = *source++;
    stride = *(s32 *)((char *)arg0 + 0xC);
    index = *(s32 *)arg0;
    base = *(s32 *)((char *)arg0 + 0x10);
    destination = base + arg1 * stride;
    destination += index * 8;
    destination += 0x18;
    fn_801376A8((s32)arg0, (s32 *)destination, (s32)values, arg1, (s32 *)base);
}

extern void *fn_801B2ED0(int);
extern void fn_8013776C(void*);
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_801B2ED0(int);
extern "C" void fn_8013776C(void*);
extern "C" void fn_80136F08(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void *v6();
    };
    void *entry;
    int i;
    int count;
    int pairCount;
    int pairOffset;
    int j;

    i = 0;
    while (i < *(int*)arg0) {
        int stride = *(int*)((char*)arg0 + 0xC);
        entry = (char*)*(void**)((char*)arg0 + 0x10) + i * stride;
        void *obj = fn_801B2ED0(i);
        obj = ((Dummy*)obj)->v6();
        *(float*)entry = *(float*)((char*)obj + 0x60);
        *(float*)((char*)entry + 4) = *(float*)((char*)obj + 0x68);
        *(float*)((char*)entry + 8) = *(float*)((char*)obj + 0x118);
        *(float*)((char*)entry + 0xC) = *(float*)((char*)obj + 0x120);
        *((unsigned char*)entry + 0x16) = 1;
        i++;
    }
    count = *(int*)arg0;
    pairCount = count * (count - 1) / 2;
    j = 0;
    pairOffset = 0;
    while (j < pairCount) {
        void *p;
        void *a;
        void *b;
        int stride;
        void *base;
        void *pair;

        stride = *(int*)((char*)arg0 + 0xC);
        pair = (char*)*(void**)((char*)arg0 + 8) + pairOffset;
        base = *(void**)((char*)arg0 + 0x10);
        a = (char*)base + *(int*)((char*)pair + 0xC) * stride;
        b = (char*)base + *(int*)((char*)pair + 0x14) * stride;
        *(float*)((char*)pair + 0x24) = *(float*)((char*)b + 8) - *(float*)((char*)a + 8);
        *(float*)((char*)pair + 0x28) = *(float*)((char*)b + 0xC) - *(float*)((char*)a + 0xC);
        p = (char*)*(void**)((char*)arg0 + 8) + pairOffset;
        *(float*)((char*)p + 0x1C) = *(float*)((char*)b + 0) - *(float*)((char*)a + 0);
        *(float*)((char*)p + 0x20) = *(float*)((char*)b + 4) - *(float*)((char*)a + 4);
        fn_8013776C((char*)*(void**)((char*)arg0 + 8) + pairOffset);
        pairOffset += 0x2C;
        j++;
    }
}
#pragma scheduling reset
#pragma cplusplus reset
#pragma pop
s32 fn_8013705C(f32 arg0, f32 arg1) {
    return arg0 * arg1 >= lbl_80561368;
}

extern float PSVECDotProduct(const void *, const void *);
s32 fn_80137078(void *arg0, void *arg1, f32 farg0, f32 farg1) {
    f32 sp28, sp24, sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    f32 temp_f10, temp_f11, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5;
    f32 temp_f6, temp_f7, temp_f8, temp_f9;
    temp_f10 = *(f32 *)((char *)arg0 + 0x1C) * farg0;
    temp_f8 = *(f32 *)((char *)arg0 + 0x20) * farg0;
    temp_f11 = *(f32 *)((char *)arg0 + 0x24) + (*(f32 *)((char *)arg0 + 0x18) * farg0);
    temp_f6 = *(f32 *)((char *)arg1 + 0x24) + (*(f32 *)((char *)arg1 + 0x18) * farg1);
    temp_f7 = *(f32 *)((char *)arg0 + 0x2C);
    temp_f4 = *(f32 *)((char *)arg1 + 0x28) + (*(f32 *)((char *)arg1 + 0x1C) * farg1);
    temp_f9 = *(f32 *)((char *)arg0 + 0x28) + temp_f10;
    temp_f3 = *(f32 *)((char *)arg1 + 0x2C) + (*(f32 *)((char *)arg1 + 0x20) * farg1);
    temp_f5 = temp_f7 + temp_f8;
    sp20 = temp_f11;
    temp_f2 = temp_f11 - temp_f6;
    temp_f1 = temp_f9 - temp_f4;
    sp24 = temp_f9;
    sp28 = temp_f5;
    sp14 = temp_f6;
    sp18 = temp_f4;
    sp1C = temp_f3;
    sp8 = temp_f2;
    spC = temp_f1;
    sp10 = temp_f5 - temp_f3;
    PSVECDotProduct(&sp8, (char *)arg1 + 0x18);
    return PSVECDotProduct(&sp8, (char *)arg1 + 0x18) < lbl_80561368;
}

#pragma dont_inline on
s32 fn_80137140(s32 arg0, s32 arg1) {
    register void *p27;
    register void *p28;
    register void *p29;
    register void *p30;
    register s32 p31;
    p27 = (void *)fn_8017960C(arg0);
    p28 = (void *)fn_8017960C(arg1);
    p29 = (void *)fn_802C6C34(*(s32 *)((char *)p27 + 0x59C));
    p30 = (void *)fn_802C6C34(*(s32 *)((char *)p28 + 0x59C));
    p31 = 0;
    if (fn_80137078((char *)p27 + 0x3C, (char *)p28 + 0x3C, *(f32 *)((char *)p29 + 0x40), *(f32 *)((char *)p30 + 0x3C))) {
        if (fn_80137078((char *)p28 + 0x3C, (char *)p27 + 0x3C, *(f32 *)((char *)p30 + 0x40), *(f32 *)((char *)p29 + 0x3C))) {
            p31 = 1;
        }
    }
    return p31;
}
#pragma dont_inline reset
extern float lbl_80561368;
extern float lbl_80561394;
extern float __fabsf(float);
extern double __fabs(double);
int fn_80137598(void *arg0, void *arg1, void *arg2) {
    unsigned char a;
    unsigned char b;
    int id;
    float diff;

    if (arg1 == 0 || arg2 == 0)
        goto null_arg;

    id = *(int*)((char*)arg0 + 4);
    if (id == *(int*)((char*)arg1 + 0xC))
        a = *(unsigned char*)((char*)arg1 + 8);
    else
        a = *(unsigned char*)((char*)arg1 + 0x10);

    if (id == *(int*)((char*)arg2 + 0xC))
        b = *(unsigned char*)((char*)arg2 + 8);
    else
        b = *(unsigned char*)((char*)arg2 + 0x10);

    if (a ^ b) {
        if (a != 0)
            return -1;
        return 1;
    }

    if (a != 0 && b != 0) {
        if (*(unsigned char*)arg1 != 0 || *(unsigned char*)arg2 != 0) {
            if (*(unsigned char*)arg1 ^ *(unsigned char*)arg2) {
                if (*(unsigned char*)arg1 == 0)
                    return -1;
                return 1;
            }
            return 0;
        }

        diff = *(float*)((char*)arg1 + 4) - *(float*)((char*)arg2 + 4);
        if ((float)__fabs(diff) < lbl_80561394)
            return 0;
        if (diff > lbl_80561368)
            return 1;
        return -1;
    }

    return 0;

null_arg:
    return arg1 == 0 ? 1 : -1;
}

s32 fn_8002F768(void *, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801376A8(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 *arg4) {
    struct CompareObject { s32 compare(s32, s32); };
    typedef s32 (CompareObject::*CompareMethod)(s32, s32);
    s32 *item;
    s32 flag;
    s32 start;
    s32 length;
    s32 end;
    s32 index;
    s32 temp;
    CompareMethod *method;
    s32 *array;
    *(s32 *)(arg0 + 4) = arg3;
    length = *(volatile s32 *)arg0;
    array = arg1;
    method = (CompareMethod *)arg2;
    start = 0;
    do {
        index = start + 1;
        item = array + index;
        end = length;
        flag = 1;
        while (index < length) {
            if ((((CompareObject *)arg0)->*(*method))(item[-1], item[0]) > 0) {
                temp = item[-1];
                end = index + 1;
                item[-1] = item[0];
                item[0] = temp;
                if (flag != 0) {
                    temp = index - 2;
                    start = temp & ~(temp >> 31);
                }
                flag = 0;
            }
            item++;
            index++;
        }
        length = end;
    } while (flag == 0);
}
#pragma scheduling on
#pragma cplusplus reset
#pragma pop
void fn_8013776C(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f0 = *(f32 *)((char *)arg0 + 0x20);
    temp_f1 = *(f32 *)((char *)arg0 + 0x1C);
    *(f32 *)((char *)arg0 + 0x18) = temp_f1 * temp_f1 + temp_f0 * temp_f0;
}

void fn_80137788(void *arg0, s32 arg1, void *arg2) {
    extern f32 lbl_8056136C;
    s32 state;
    s32 stride;
    s32 id;
    s32 difference;
    s32 entries;
    s32 entry;
    s32 equal;
    unsigned char flag;
    f32 x;
    f32 y;
    f32 scale;

    state = lbl_8055E0D0;
    stride = *(s32 *)((char *)state + 0xC);
    id = *(s32 *)((char *)arg0 + 0x14);
    difference = id - arg1;
    entries = *(s32 *)((char *)state + 0x10);
    entry = entries + arg1 * stride;
    flag = *(unsigned char *)((char *)entry + 0x14);
    equal = difference == 0;
    if ((equal ^ flag) != 0) {
        x = *(f32 *)((char *)arg0 + 0x1C);
        scale = lbl_8056136C;
        y = *(f32 *)((char *)arg0 + 0x20);
        x = x * scale;
        y = y * scale;
        *(f32 *)arg2 = x;
        *(f32 *)((char *)arg2 + 4) = y;
        return;
    }
    x = *(f32 *)((char *)arg0 + 0x1C);
    y = *(f32 *)((char *)arg0 + 0x20);
    *(f32 *)arg2 = x;
    *(f32 *)((char *)arg2 + 4) = y;
}

void fn_801377EC(void *arg0, s32 arg1, void *arg2) {
    extern f32 lbl_8056136C;
    s32 state;
    s32 stride;
    s32 id;
    s32 difference;
    s32 entries;
    s32 entry;
    unsigned char flag;
    f32 x;
    f32 y;
    f32 scale;

    state = lbl_8055E0D0;
    stride = *(s32 *)((char *)state + 0xC);
    id = *(s32 *)((char *)arg0 + 0x14);
    difference = id - arg1;
    entries = *(s32 *)((char *)state + 0x10);
    entry = entries + arg1 * stride;
    flag = *(unsigned char *)((char *)entry + 0x14);
    if (((difference == 0) ^ flag) != 0) {
        x = *(f32 *)((char *)arg0 + 0x24);
        scale = lbl_8056136C;
        y = *(f32 *)((char *)arg0 + 0x28);
        x = x * scale;
        y = y * scale;
        *(f32 *)arg2 = x;
        *(f32 *)((char *)arg2 + 4) = y;
        return;
    }
    x = *(f32 *)((char *)arg0 + 0x24);
    y = *(f32 *)((char *)arg0 + 0x28);
    *(f32 *)arg2 = x;
    *(f32 *)((char *)arg2 + 4) = y;
}

float fn_80137850(void *arg0)
{
  float new_var;
  float *new_var2;
  int index = (*((int *) (((char *) arg0) - (-0x18)))) * (*((int *) (lbl_8055E0D0 + 0xC)));
  int base;
  float *p = (float *) ((*((int *) (lbl_8055E0D0 + 0x10))) + index);
  new_var2 = *((float **) arg0);
  return p[0] + ((new_var = new_var2[1]) * p[2]);
}

void fn_80137884(s32 arg0) {
 s32 var_r3 = fn_801284F8(0x18, &lbl_80559BF8);
 if (var_r3 != 0) var_r3 = ((s32 (*)(s32, s32))fn_801368F8)(var_r3, arg0);
 lbl_8055E0D4 = var_r3;
 lbl_8055E0D0 = var_r3;
}

void fn_801378D0(void) {
 fn_80136A18(lbl_8055E0D4, 1);
 lbl_8055E0D4 = 0; lbl_8055E0D0 = 0;
}

void fn_80137904(void) { fn_80136AA8((void*)lbl_8055E0D4); }
