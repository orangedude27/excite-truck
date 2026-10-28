// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef float f32;
extern double fn_8002F234(double);
extern f32 lbl_80564858, lbl_8056485C, lbl_80564878;
extern s32 lbl_8055F88C;
extern char lbl_80349C88[];
extern s32 fn_801284F8(s32, char *);
extern s32 fn_802A6944(s32, s32, s32);
extern s32 fn_8012850C();
extern s32 fn_8002F37C(s32, void *, s32, s32, s32);
extern void fn_8001BA68(void);
extern char lbl_80349CAC[];
extern s32 lbl_8055CBC0;
extern char lbl_80349CA0[];
extern s32 lbl_8055CBB8, lbl_8055CBBC;
typedef union { double d; struct { f32 x, z; }; } Vec2_802A775C;
typedef struct {
    void *points;
    s32 count;
    s32 unk8;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 radius;
    f32 unk1C;
    f32 dirX;
    f32 dirY;
    f32 dirZ;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    f32 unk38;
    f32 unk3C;
} Obj802A775C;
void fn_802C2C00(s32);
void *fn_801E1F44(void);
void fn_802C2C00(s32);
s32 fn_802C990C(s32);
s32 fn_802C2B78(f32, f32, f32);
f32 fn_802A4A50(void);
s32 fn_802A6A7C(void);
void fn_802A5CA4();
void fn_802A5A38(void);
void fn_802A6790(void *);
extern s32 lbl_8055F888;
extern s32 lbl_8055F88C;
extern f32 lbl_8055F8A0;
s32 fn_802A6A44(s32 *);
void fn_802A5C1C();
void fn_802A59E0(void);
extern s32 lbl_804BCFA8[];
extern s32 lbl_8055F890;
s32 fn_802A7680(s32);
extern s32 lbl_8055F894, lbl_8055F898, lbl_8055F89C;
extern u8 lbl_80349BF0[], lbl_8055CBC8;
s32 fn_802C6CF8(void);
s32 fn_802CAC54(s32);
extern s32 fn_80128670(s32);
extern s32 fn_80128668(void *);
s32 fn_802A597C(void);
s32 fn_8028E398(void);
s32 fn_802A5B8C();
void *fn_802A69D8(void *, s32);
s32 fn_800167F4(void);
s32 fn_802A5384(s32);
s32 fn_802A53B0(void);
s32 fn_80287B38(void *);
s32 fn_802A5878(void);
s32 fn_802CAC28(void *, s32);
void *fn_802AE414(void *);
s32 fn_802C6FC0(void *, s32, s32);
s32 fn_800216F4(void);
f32 fn_801E7E24(void);
s32 fn_802E2C20(void);
extern s32 lbl_8055F8A4;
extern f32 lbl_80564840, lbl_80564844;
extern f32 lbl_80564850, lbl_80564858, lbl_8056485C, lbl_80564888;
void fn_802A6234();
void fn_802A70E4(void *, f32 *);
f32 fn_80129DC4(s32, f32, f32);
extern f32 lbl_80564894, lbl_80564898;
extern f32 __fabsf(f32);
extern char lbl_80558DC4[];
extern f32 lbl_80564854;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
void fn_802A5A90(void);
void fn_802A6D68(void *);
void fn_802D3D50(void);
void fn_802A5FE4(void);
void *fn_801E7E34(void);
s32 fn_802C90F0(s32);
void fn_802C9118(void);
void fn_802C9124(s32, s32, f32, f32, u32, f32, f32, f32, f32);

f32 fn_802A4A50(void) {
    f32 value;
    s32 now;
    s32 delta;
    if (fn_800216F4() != 0) {
        now = fn_802E2C20();
        delta = now - lbl_8055F8A4;
        value = lbl_80564844;
        lbl_8055F8A4 = now;
        if ((f32)delta / lbl_80564840 < value)
            return (f32)delta / lbl_80564840;
        return value;
    }
    return fn_801E7E24();
}

f32 fn_802A4AD4(void) {
    return lbl_8055F8A0;
}

void fn_802A4ADC(void) {
    void *base = lbl_80349BF0;
    s32 result = (s32)fn_801E1F44();
    if (fn_800167F4() == 1) fn_802A5384(result);
    fn_80287B38((void *)fn_802A53B0);
    fn_802A5878();
    lbl_8055F89C = fn_802CAC28((char *)base + 0x28, 0);
    result = (s32)((char *)base + 0x38);
    {
        void **p = fn_802AE414(&lbl_8055CBC8);
        if (p != 0) result = ((s32 (*)(void *, void *, void *))(*(u32 *)((u8 *)*p + 0x18)))(p, (char *)base + 0x48, (void *)result);
    }
    lbl_8055F898 = fn_802C6FC0((void *)result, 0, 0);
}

void fn_802A4B90(void) {
    s32 value;
    value = lbl_8055F898;
    if (value != -1) { ((s32 (*)(s32))fn_802C6CF8)(value); lbl_8055F898 = -1; }
    fn_802CAC54(lbl_8055F89C);
    fn_802A597C();
    value = lbl_8055F894;
    if (value != 0) { ((s32 (*)(s32))fn_8028E398)(value); lbl_8055F894 = 0; }
    value = lbl_8055F888;
    if (value != 0) { ((void (*)(s32, s32))fn_802A5B8C)(value, 1); lbl_8055F888 = 0; }
    value = lbl_8055F88C;
    if (value != 0) { fn_802A69D8((void *)value, 1); lbl_8055F88C = 0; }
}

void fn_802A4C20(void) {
    volatile s32 *flag;
    flag = &lbl_8055F88C;
    if (*flag != 0) ((s32 (*)(s32 *))fn_802A6A44)((s32 *)flag);
    flag = &lbl_8055F888;
    if (*flag != 0) fn_802A5C1C();
    fn_802A59E0();
}

#pragma dont_inline on
void fn_802A4C60(void) {
    volatile s32 *p;
    lbl_8055F8A0 = fn_802A4A50();
    p = (volatile s32 *)&lbl_8055F88C;
    if (*p) fn_802A6A7C();
    p = (volatile s32 *)&lbl_8055F888;
    if (*p) fn_802A5CA4();
    fn_802A5A38();
}
#pragma dont_inline reset
void fn_802A4CA8(void) {
    u8 *p = (u8 *)fn_801E1F44();
    if (p[0x18] != 0) {
        fn_802C2C00(1);
        fn_802C990C(*(s32 *)(p + 8));
        fn_802C2B78(*(f32 *)(p + 0xC), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    }
}

void fn_802A4D00(void) { fn_802C2C00(0); }

#pragma scheduling invalid_target
void fn_802A4D08(void) {
    u8 *state = (u8 *)fn_801E1F44();
    s32 flag;
    f32 value;
    s32 scaled;
    s32 nonnegative;
    s32 alpha;

    fn_802A5A90();
    if (state[0x18] != 0)
        fn_802D3D50();

    flag = lbl_8055F88C;
    if (flag != 0) {
        fn_802A6D68((void *)flag);
    } else {
        flag = lbl_8055F888;
        if (flag != 0)
            ((void (*)(s32))fn_802A5FE4)(flag);
    }

    value = *(f32 *)((u8 *)fn_801E7E34() + 0xDC);
    if (!((f32)__fabs((double)value) <= *(f32 *)(void *)&lbl_80558DC4)) {
        scaled = (s32)(lbl_80564850 * (lbl_80564854 * value));
        nonnegative = scaled & ((-scaled & ~scaled) >> 31);
        alpha = 0xFF;
        if (nonnegative < 0xFF)
            alpha = nonnegative;

        fn_802C90F0(lbl_8055F89C);
        ((void (*)(f32, f32, f32, f32, s32, s32, s32, s32, s32))fn_802C9124)(
            lbl_80564858, lbl_80564858, lbl_8056485C, lbl_8056485C,
            0, 0, lbl_8055CFF0, lbl_8055CFF4,
            (alpha << 24) | 0x00FFFFFF);
        fn_802C9118();
    }
}
#pragma scheduling on
extern void PSVECCrossProduct(float *, float *, float *);
extern float PSVECMag(float *);
extern void fn_802E317C(const char *);
extern const char lbl_80349C48[];
extern const char lbl_8055CBD0[], lbl_8055CBD4[], lbl_8055CBDC[], lbl_8055CBE0[];
extern float lbl_80564860, lbl_80564864;
s32 fn_802A4FA8(float *out, void *object) {
    float v0[3], v1[3], v2[3], v3[3], cross[3];
    void (**vtable)(void *, void *, const char *);
    if (object == 0) return 0;
    vtable = *(void (***)(void *, void *, const char *))object;
    vtable[13](v0, object, lbl_8055CBD0);
    out[0] = v0[0]; out[1] = v0[1]; out[2] = v0[2];
    vtable[13](v1, object, lbl_8055CBD4);
    out[3] = v1[0]; out[4] = v1[1]; out[5] = v1[2];
    vtable[13](v2, object, lbl_8055CBDC);
    out[6] = v2[0]; out[7] = v2[1]; out[8] = v2[2];
    vtable[13](v3, object, lbl_8055CBE0);
    out[9] = v3[0]; out[10] = v3[1]; out[11] = v3[2];
    PSVECCrossProduct(out + 6, out + 9, cross);
    if (lbl_80564864 * PSVECMag(cross) < lbl_80564860) fn_802E317C(lbl_80349C48);
    return 1;
}

extern f32 lbl_8056485C, lbl_80564868, lbl_8056486C, lbl_80564870, lbl_80564874;
extern s32 lbl_8055F894;
extern unsigned char lbl_80349BF0[];
extern unsigned char lbl_804BCFB8[];
extern s32 lbl_8055CBE8;
s32 fn_80287B14(void);
void *fn_80288208(s32);
s32 fn_80287E20(s32);
void *fn_80287E80(void *, s32);
void fn_8028E61C(void *);
s32 fn_8028E2F8(void *, void *, void *, f32, f32, f32, f32);
int sprintf(char *, const char *, ...);
void fn_802A50F8(void) {
    struct { s32 a; s32 b; f32 c[28]; } init;
    char name[4];
    s32 i = 0, j;
    void *obj;
    fn_8028E61C(&init);
    init.b = 0x100; init.a = 0;
    init.c[0] = lbl_80564868; init.c[1] = lbl_8056485C;
    init.c[2] = lbl_8056486C; init.c[3] = lbl_8056486C; init.c[4] = lbl_8056486C;
    init.c[5] = lbl_8056485C; init.c[6] = lbl_8056485C; init.c[7] = lbl_8056485C;
    init.c[10] = lbl_8056485C; init.c[16] = 5;
    init.c[20] = lbl_80564874; init.c[19] = lbl_80564870; init.c[18] = lbl_80564870;
    init.c[21] = lbl_8056485C; init.c[22] = lbl_8056485C;
    init.c[24] = lbl_8056485C; init.c[25] = lbl_8056485C; init.c[26] = lbl_8056485C;
    lbl_8055F894 = fn_8028E2F8(&init, lbl_80349BF0 + 0x80, lbl_80349BF0 + 0x1c, lbl_80564870, lbl_8056486C, lbl_8056485C, lbl_80564868);
    for (i = 0; i < fn_80287B14(); i++) {
        unsigned char *entry = lbl_804BCFB8 + i * 0xC4;
        *(s32 *)(entry + 0xC0) = 0;
        obj = fn_80288208(i);
        if (fn_80287E20(lbl_8055CBE8)) {
            obj = fn_80287E80(obj, lbl_8055CBE8);
            *(s32 *)(entry + 0xC0) = 0;
            for (j = 0; j < 4; ) {
                void *value;
                sprintf(name, (char *)lbl_80349BF0 + 0x8c, j + 1);
                value = ((void *(*)(void *, const char *))(*(void ***)obj)[0x5c/4])(obj, name);
                if (!fn_802A4FA8((float *)(entry + j * 0x30), value)) break;
                *(s32 *)(entry + 0xC0) = ++j;
            }
        }
    }
}

#pragma scheduling invalid_target
void fn_802A5270(f32 arg0) {
    f32 value = *(volatile f32 *)&lbl_8056485C;
    s32 amount;
    s32 result;

    value = (value < arg0) ? value : arg0;
    value = (value > lbl_80564858) ? value : lbl_80564858;
    amount = (s32)(lbl_80564878 * value);
    result = fn_801284F8(0x44, lbl_80349C88);
    if (result != 0) {
        result = fn_802A6944(result, amount, 0);
    }
    lbl_8055F88C = result;
    fn_802A50F8();
}
#pragma scheduling on
extern f32 lbl_80564858, lbl_8056485C, lbl_80564878;
extern char lbl_80349C94[];
s32 fn_801284F8(s32, char *);
void *fn_802A5AE8(void *, s32, s32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802A52FC(f32 arg0) {
    f32 value = lbl_8056485C;
    s32 result;
    s32 amount;
    value = (value < arg0) ? value : arg0;
    value = (value > lbl_80564858) ? value : lbl_80564858;
    amount = (s32)(lbl_80564878 * value);
    result = fn_801284F8(0xBC, lbl_80349C94);
    if (result != 0) result = (s32)fn_802A5AE8((void *)result, amount, 0);
    lbl_8055F888 = result;
}
#pragma scheduling on
#pragma pop
void fn_802A5270(f32);
s32 fn_802A5384(s32 arg0) {
    s32 value = *(s32 *)arg0;

    if (value == 2) {
        goto special;
    }
    if (value >= 2) {
        return;
    }
    if (value < 1) {
        return;
    }
    return ((s32 (*)(f32))fn_802A5270)(lbl_8056485C);
special:
    return ((s32 (*)(f32))fn_802A52FC)(lbl_8056485C);
}

extern void *fn_802AE4C8(s32);
extern s32 fn_802A7370(s32, void *);
extern int strncmp(const char *, const char *, unsigned long);
extern char lbl_8055CBF0;
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_802A5878(void) {
    struct Item {
        virtual const char *name();
        virtual void *child(s32);
    };
    s32 *table;
    Item *list;
    s32 i;
    s32 j;
    Item *child;
    s32 check;
    s32 count;

    lbl_8055F890 = 0;
    if (fn_800167F4() > 1) {
        goto done;
    }
    table = lbl_804BCFA8;
    i = 0;
    while ((list = (Item *)fn_802AE4C8(i)) != 0) {
        j = 0;
        while (list->child(j) != 0) {
            child = (Item *)list->child(j);
            if (strncmp(child->name(), &lbl_8055CBF0, 4) == 0) {
                check = fn_801284F8(0x40, &lbl_8055CBF0);
                if (check != 0) {
                    check = fn_802A7370(check, child);
                }
                count = lbl_8055F890;
                table[count] = check;
                lbl_8055F890 = count + 1;
            }
            j++;
        }
        i++;
    }
done:
    ;
}
#pragma cplusplus off
#pragma pop

void *fn_802A7614(void *, s32);
s32 fn_802A597C(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A7614((void *)*ptr, 1);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
    lbl_8055F890 = 0;
}

void fn_802A59E0(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A7680(*ptr);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
}

void fn_802A775C(void *);
void fn_802A5A38(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A775C((void *)*ptr);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
}

void fn_802A5A90(void);
s32 fn_802A79CC(s32);
void fn_802A5A90(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A79CC(*ptr);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
}

#pragma scheduling invalid_target
void *fn_802A5AE8(void *arg0, s32 arg1, s32 arg2) {
    s32 count = arg1;
    s32 bytes = count * 12;
    void *buffer = ((void *(*)(s32, void *, s32))fn_8012850C)(count * 12 + 16, lbl_80349CA0, count * 12);
    *(s32 *)arg0 = fn_8002F37C((s32)buffer, (void *)fn_8001BA68, 0, 12, count);
    *(s32 *)((u8 *)arg0 + 8) = count;
    *(s32 *)((u8 *)arg0 + 12) = fn_802CAC28((void *)lbl_8055CBBC, 0);
    *(s32 *)((u8 *)arg0 + 16) = fn_802CAC28((void *)lbl_8055CBB8, 0);
    *(s32 *)((u8 *)arg0 + 28) = arg2;
    fn_802A5C1C(arg0);
    return arg0;
}
#pragma scheduling on
extern s32 lbl_804BCFA8[];
extern s32 lbl_8055F890;
s32 fn_802A7680(s32);
#pragma scheduling invalid_target
s32 fn_802A5B8C(s32 arg0, s32 arg1) {
    s32 temp;
    s32 second;
    s32 minusOne = -1;
    volatile s32 *p = (volatile s32 *)arg0;
    if (arg0 != 0) {
        fn_802CAC54(p[4]);
        second = p[3];
        p[4] = minusOne;
        fn_802CAC54(second);
        temp = p[0];
        if ((p[3] = minusOne, temp != 0)) fn_80128670(temp - 0x10);
        p[0] = 0;
        if (arg1 > 0) fn_80128668((void *)arg0);
    }
    return arg0;
}
#pragma scheduling on
void fn_802A5C1C(void *arg0) {
    f32 d;
    f32 b;
    f32 c;
    f32 a;
    f32 *p = (f32 *)arg0;
    d = lbl_80564858;
    a = lbl_8056485C;
    c = lbl_80564850;
    b = lbl_80564888;
    p[8] = a;
    p[9] = c;
    p[10] = b;
    p[11] = d;
    p[12] = d;
    p[13] = d;
    p[14] = d;
    p[15] = d;
    p[16] = d;
    p[17] = d;
    p[18] = d;
    p[19] = d;
    p[20] = d;
    p[21] = a;
    p[22] = d;
    p[6] = d;
    p[5] = d;
    fn_802A6234(b, c, a);
    fn_802A6790(arg0);
}
#pragma scheduling on
extern f32 lbl_8056488C;
extern void *fn_801E8718();
extern void fn_802A62CC(void *, s32);
extern s32 fn_801E8758(s32);
extern f32 PSVECDotProduct(f32 *, f32 *);
extern void fn_802A6470(void *, f32 *, f32 *);
extern void fn_802A6838(void *);
extern void fn_802A6408(void *);
extern void fn_802A6790(void *);
#pragma scheduling invalid_target
void fn_802A5CA4(void *arg0) {
    struct Obj { u8 pad0[0x1C]; s32 model; u8 pad20[0x0C]; f32 pos[3]; f32 axis[3]; f32 scaled[3]; f32 base[3]; };
    struct Work { f32 input[3]; f32 cross[3]; f32 transformed[3]; s32 pad; s32 matrix[12]; } w;
    register f32 *m = (f32 *)w.matrix;
    struct Obj *obj = (struct Obj *)arg0;
    s32 *source = (s32 *)fn_801E8718(obj->model);
    s32 a, b;
    b=source[0]; a=source[1]; w.matrix[0]=b; w.matrix[1]=a;
    a=source[2]; b=source[3]; w.matrix[2]=a; w.matrix[3]=b;
    a=source[4]; b=source[5]; w.matrix[4]=a; w.matrix[5]=b;
    a=source[6]; b=source[7]; w.matrix[6]=a; w.matrix[7]=b;
    a=source[8]; w.matrix[8]=a;
    a=source[9]; b=source[10]; w.matrix[9]=a; w.matrix[10]=b;
    a=source[11]; w.matrix[11]=a;
    fn_802A62CC(obj, w.matrix[9]);
    {
        f32 y=lbl_80564874, x=lbl_80564858, z=x;
        f32 xy3,xx0,xx1,yy4,xx2,yy5,out0,out1,out2;
        w.input[0]=x; w.input[1]=y; w.input[2]=z;
        if (obj->base==(f32 *)&w.input[0]) {
            xy3=y*m[1]; xx0=x*m[0];
            xx1=x*m[3]; yy4=y*m[4];
            xx2=x*m[6]; yy5=y*m[7];
            out0=(xx0+xy3)+z*m[2];
            out1=(xx1+yy4)+z*m[5];
            out2=(xx2+yy5)+z*m[8];
            obj->base[0]=out0; obj->base[1]=out1; obj->base[2]=out2;
        } else {
            obj->base[0]=w.input[0]*m[0]+w.input[1]*m[1]+w.input[2]*m[2];
            obj->base[1]=w.input[0]*m[3]+w.input[1]*m[4]+w.input[2]*m[5];
            obj->base[2]=w.input[0]*m[6]+w.input[1]*m[7]+w.input[2]*m[8];
        }
    }
    {
        f32 scale=lbl_80564844;
        obj->scaled[0]=obj->base[0]*scale;
        obj->scaled[1]=obj->base[1]*scale;
        obj->scaled[2]=obj->base[2]*scale;
    }
    if (fn_801E8758(obj->model)==0) {
        w.transformed[0]=obj->pos[0]-m[9];
        w.transformed[1]=obj->pos[1]-m[10];
        w.transformed[2]=obj->pos[2]-m[11];
        {
            f32 x=w.transformed[0], y=w.transformed[1], z=w.transformed[2];
            f32 out0=x*m[0]+y*m[1]+z*m[2];
            f32 out1=x*m[3]+y*m[4]+z*m[5];
            f32 out2=x*m[6]+y*m[7]+z*m[8];
            w.transformed[0]=out0; w.transformed[1]=out1; w.transformed[2]=out2;
        }
        {
            f32 posScale=lbl_8056488C;
            obj->scaled[0]+=w.transformed[0]*posScale;
            obj->scaled[1]+=w.transformed[1]*posScale;
            obj->scaled[2]+=w.transformed[2]*posScale;
        }
        PSVECCrossProduct((f32 *)&w.matrix[6],obj->axis,w.cross);
        PSVECDotProduct((f32 *)&w.matrix[3],w.cross);
        fn_802A6470(obj,m,w.transformed);
        fn_802A6838(obj); fn_802A6408(obj);
    } else fn_802A6790(obj);
    obj->pos[0]=m[9]; obj->pos[1]=m[10]; obj->pos[2]=m[11];
    obj->axis[0]=m[6]; obj->axis[1]=m[7]; obj->axis[2]=m[8];
}

#pragma push
#pragma processor 750
void fn_802A6234(void *arg0) {
    f32 temp_f30;
    f32 temp_f31;
    s32 var_r31 = (s32)arg0;
    s32 var_r30 = 0;
    do {
        temp_f30 = fn_80129DC4(0, lbl_80564894, lbl_80564898);
        temp_f31 = fn_80129DC4(0, lbl_80564894, lbl_80564898);
        *(f32 *)(var_r31 + 0x5C) = fn_80129DC4(0, lbl_80564894, lbl_80564898);
        var_r30 += 1;
        *(f32 *)(var_r31 + 0x60) = temp_f31;
        *(f32 *)(var_r31 + 0x64) = temp_f30;
        var_r31 += 0xC;
    } while (var_r30 < 8);
}

extern double fn_8002EF30(f32);
extern f32 fn_801E8738(s32);
extern f32 fn_801E8874(s32);
extern f32 fn_801E8894(s32);
extern void fn_801E88B4(f32 *, f32 *, s32 *, f32 *, s32);
extern f32 lbl_80564860;
extern f32 lbl_80564890;
extern f32 lbl_80564894;
extern f32 lbl_8056489C;
extern f32 lbl_805648A0;
extern double lbl_80564848;
#pragma scheduling invalid_target
void fn_802A62CC(void *arg0, s32 arg1) {
    union IntToDouble {
        double value;
        struct { u32 high, low; } words;
    } conversion;
    f32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f10;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;

    temp_f30 = lbl_80564850 * fn_801E8738(*(s32 *)((u8 *)arg0 + 0x1C));
    temp_f31 = fn_801E8874(*(s32 *)((u8 *)arg0 + 0x1C));
    temp_f29 = fn_801E8894(*(s32 *)((u8 *)arg0 + 0x1C));
    fn_801E88B4(&sp14, &sp10, &spC, &sp8, *(s32 *)((u8 *)arg0 + 0x1C));
    temp_f10 = (f32)fn_8002EF30(temp_f30);
    *(f32 *)((u8 *)arg0 + 0x20) = temp_f10;
    temp_f7 = temp_f29 * lbl_8056489C;
    temp_f30_2 = temp_f29 + temp_f31;
    *(f32 *)((u8 *)arg0 + 0x24) = lbl_805648A0 + temp_f31;
    temp_f9 = lbl_80564894 * temp_f30_2;
    temp_f8 = lbl_80564860 * temp_f29 * temp_f31;
    temp_f6 = temp_f31 * temp_f7;
    temp_f29_2 = temp_f9 - temp_f8;
    conversion.words.high = 0x43300000;
    conversion.words.low = (u32)spC ^ 0x80000000;
    temp_f3 = lbl_80564844 * ((f32)(conversion.value - lbl_80564848) * (lbl_80564890 * temp_f31));
    temp_f4 = temp_f29_2 * temp_f29_2;
    temp_f2 = temp_f3 * (temp_f29 - temp_f31);
    *(f32 *)((u8 *)arg0 + 0x28) = (f32)((-temp_f29_2 +
        (f32)fn_8002F234(temp_f4 -
            (lbl_80564890 * temp_f30_2 * (temp_f6 - (temp_f2 / (lbl_80564860 * temp_f10)))))) /
        (lbl_80564860 * temp_f30_2));
}

#pragma pop
f32 fn_80129DC4(s32, f32, f32);
extern f32 lbl_80564894, lbl_80564898;
f32 fn_802A4AD4(void);
f32 fn_80287BC8(f32, f32);
extern f32 lbl_805648A4, lbl_805648A8;
void fn_802A6408(void *arg0) {
    f32 value = (f32)__fabs((double)fn_802A4AD4());
    if (!(value <= *(f32 *)(void *)&lbl_80558DC4)) {
        *(f32 *)((u8 *)arg0 + 0x14) = fn_80287BC8(lbl_805648A4, lbl_805648A8);
        *(f32 *)((u8 *)arg0 + 0x18) = fn_80287BC8(lbl_805648A4, lbl_805648A8);
    }
}

#pragma scheduling push
#pragma scheduling on
#pragma dont_inline on
void fn_802A6758(void *arg0, f32 *arg1) {
    s32 i = *(s32 *)((u8 *)arg0 + 4);
    f32 *base = *(f32 **)arg0;
    f32 z;
    f32 y;
    f32 x;
    x = arg1[0];
    y = arg1[1];
    z = arg1[2];
    base[i * 3] = x;
    base += i * 3;
    base[1] = y;
    base[2] = z;
    *(s32 *)((u8 *)arg0 + 4) += 1;
}
#pragma push
#pragma processor 750
void fn_802A6790(void *arg0) {
    f32 values[3];
    f32 first;
    f32 scaled;
    f32 second;
    f32 third;

    *(s32 *)((u8 *)arg0 + 4) = 0;
    while (*(s32 *)((u8 *)arg0 + 4) < *(s32 *)((u8 *)arg0 + 8)) {
        first = fn_80287BC8(*(f32 *)((u8 *)arg0 + 0x24), *(f32 *)((u8 *)arg0 + 0x28));
        scaled = *(f32 *)((u8 *)arg0 + 0x20) * first;
        second = fn_80287BC8(-scaled, scaled);
        third = fn_80287BC8(-scaled, scaled);
        values[0] = second;
        values[1] = third;
        values[2] = first;
        fn_802A6758(arg0, values);
    }
}

extern float fn_802C9A50(void);
extern void fn_802A6758(void *, float *);
extern double __fabs(double);
extern float lbl_80564850, lbl_80564858, lbl_8056485C;
void fn_802A6838(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    float samples[2];
    float values[3];
    float divisor;
    float dt;
    float speed;
    register float scale;
    float one;
    float curve;
    float product;
    double absX;
    double absY;
    float ax;
    float ay;
    float rx;
    float ry;
    float end;
    float start;
    float next;

    divisor = fn_802C9A50();
    dt = *(float *)(p + 0x20);
    speed = dt / divisor;
    scale = lbl_80564850;
    one = lbl_8056485C;
    while (*(int *)(p + 4) < *(int *)(p + 8)) {
        curve = fn_80287BC8(lbl_80564858, lbl_8056485C);
        product = scale * curve;
        samples[1] = *(float *)(p + 0x54) * (scale - product);
        samples[0] = *(float *)(p + 0x50) * (scale - product);
        absX = __fabs((double)samples[0]);
        absY = __fabs((double)samples[1]);
        ax = one - (float)absX;
        ay = one - (float)absY;
        rx = fn_80287BC8(-ax, ax);
        ry = fn_80287BC8(-ay, ay);
        end = *(float *)(p + 0x28);
        start = *(float *)(p + 0x24);
        next = start + curve * (end - start);
        values[2] = next;
        values[1] = dt * next * (samples[1] + ry);
        values[0] = speed * next * (samples[0] + rx);
        fn_802A6758(arg0, values);
    }
}

#pragma pop
s32 fn_802A6944(s32 arg0, s32 arg1, s32 arg2) {
    s32 *object = (s32 *)arg0;

    object[0] = fn_8002F37C(
        fn_8012850C(arg1 * 0xC + 0x10, lbl_80349CAC),
        (void *)fn_8001BA68,
        0,
        0xC,
        arg1);
    object[2] = arg1;
    object[3] = fn_802CAC28((void *)lbl_8055CBC0, 0);
    object[4] = arg2;
    fn_802A6A44(object);
    return arg0;
}
#pragma scheduling on
void *fn_802A69D8(void *arg0, s32 arg1) {
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(((s32 *)arg0)[3]);
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern f32 lbl_80564850;
extern f32 lbl_80564858;
extern f32 lbl_8056485C;
extern f32 lbl_80564888;
s32 fn_802A711C(void *, f32, f32, f32);
#pragma scheduling invalid_target
s32 fn_802A6A44(s32 *arg0) {
    f32 d;
    f32 b = lbl_80564888;
    f32 c;
    f32 a = lbl_8056485C;
    f32 *p = (f32 *)arg0;

    c = lbl_80564850;
    d = lbl_80564858;
    p[5] = a;
    p[6] = c;
    p[7] = b;
    p[8] = d;
    p[9] = d;
    p[10] = d;
    p[14] = d;
    p[15] = a;
    p[16] = d;
    return fn_802A711C(arg0, b, c, a);
}
#pragma scheduling on
extern float lbl_8055F884;
extern float lbl_805648B4;
extern float fn_802C9A4C(float);
extern int fn_802C86DC(void);
extern void fn_802C8B98(int, int);
extern int fn_801E501C(int, void *, float, int);
extern void fn_801E5174(void *, float, float, float);
extern void fn_801E5348(void);
extern void fn_802C8D74(void);
#pragma push
#pragma processor 750
void fn_802A6D68(void *arg0) {
    float saved;
    if (*(int *)((char *)arg0 + 4) >= 1) {
        saved = fn_802C9A4C(lbl_8055F884);
        fn_802C8B98(*(int *)((char *)arg0 + 0xC), fn_802C86DC());
        if (fn_801E501C(*(int *)((char *)arg0 + 4), (char *)arg0 + 0x2C, lbl_805648B4, 0xFF) != 0) {
            int offset;
            int i;
            i = 0;
            offset = 0;
            while (i < *(int *)((char *)arg0 + 4)) {
                float *entry = (float *)((char *)*(float **)arg0 + offset);
                fn_801E5174(entry, *(float *)((char *)*(float **)arg0 + offset), entry[1], entry[2]);
                offset += 0xC;
                i++;
            }
            fn_801E5348();
        }
        fn_802C8D74();
        fn_802C9A4C(saved);
    }
}

extern float lbl_80564850, lbl_8056485C, lbl_80564860, lbl_80564890, lbl_805648B4, lbl_805648B8, lbl_805648BC;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802A6E34(void *arg0) {
    f32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f10;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;

    temp_f30 = lbl_80564850 * fn_801E8738(*(s32 *)((u8 *)arg0 + 0x10));
    temp_f31 = fn_801E8874(*(s32 *)((u8 *)arg0 + 0x10));
    temp_f29 = fn_801E8894(*(s32 *)((u8 *)arg0 + 0x10));
    fn_801E88B4(&sp14, &sp10, &spC, &sp8, *(s32 *)((u8 *)arg0 + 0x10));
    temp_f10 = (f32)fn_8002EF30(temp_f30);
    *(f32 *)((u8 *)arg0 + 0x14) = temp_f10;
    temp_f7 = temp_f29 * lbl_805648BC;
    temp_f30_2 = temp_f29 + temp_f31;
    *(f32 *)((u8 *)arg0 + 0x18) = lbl_8056485C + temp_f31;
    temp_f9 = lbl_805648B8 * temp_f30_2;
    temp_f8 = lbl_80564860 * temp_f29 * temp_f31;
    temp_f6 = temp_f31 * temp_f7;
    temp_f29_2 = temp_f9 - temp_f8;
    temp_f3 = lbl_805648B4 * ((f32)spC * (lbl_80564890 * temp_f31));
    temp_f4 = temp_f29_2 * temp_f29_2;
    temp_f2 = temp_f3 * (temp_f29 - temp_f31);
    *(f32 *)((u8 *)arg0 + 0x1C) =
        (f32)((-temp_f29_2 + (f32)fn_8002F234(
            (double)(temp_f4 -
                (lbl_80564890 * temp_f30_2 *
                    (temp_f6 - (temp_f2 / (lbl_80564860 * temp_f10))))))) /
            (lbl_80564860 * temp_f30_2));
}
#pragma scheduling on
#pragma pop
s32 fn_802A711C(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 values[3];
    f32 first;
    f32 scaled;
    f32 second;
    f32 third;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    while (*(s32 *)((u8 *)arg0 + 4) < *(s32 *)((u8 *)arg0 + 8)) {
        first = fn_80287BC8(*(f32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x1C));
        scaled = *(f32 *)((u8 *)arg0 + 0x14) * first;
        second = fn_80287BC8(-scaled, scaled);
        third = fn_80287BC8(-scaled, scaled);
        values[0] = second;
        values[1] = third;
        values[2] = first;
        fn_802A70E4(arg0, values);
    }
    return *(s32 *)((u8 *)arg0 + 4);
}

extern f32 lbl_80564850, lbl_80564858, lbl_8056485C, lbl_805648C4;
f32 fn_802C9A50(void);
void fn_802A70E4(void *, f32 *);
void fn_802A71C4(void *arg0) {
    u8 *p = (u8 *)arg0;
    f32 dt = *(f32 *)(p + 0x14);
    f32 speed = dt / fn_802C9A50();
    if (*(f32 *)(p + 0x34) <= lbl_805648C4) {
        f32 scale = lbl_80564850;
        f32 one = lbl_8056485C;
        do {
            f32 curve = fn_80287BC8(lbl_80564858, lbl_8056485C);
            f32 a = scale * curve;
            f32 x = *(f32 *)(p + 0x38) * (scale - a);
            f32 y = *(f32 *)(p + 0x3C) * (scale - a);
            f32 ax = one - __fabsf(x);
            f32 ay = one - __fabsf(y);
            f32 rx = fn_80287BC8(-ax, ax);
            f32 ry = fn_80287BC8(-ay, ay);
            f32 oldx = *(f32 *)(p + 0x18);
            f32 newx = oldx + curve * (*(f32 *)(p + 0x1C) - oldx);
            f32 v[3];
            v[0] = speed * newx * (x + rx);
            v[1] = dt * newx * (y + ry);
            v[2] = newx;
            fn_802A70E4(arg0, v);
        } while (*(s32 *)(p + 4) < *(s32 *)(p + 8));
    } else {
        do {
            f32 curve = fn_80287BC8(lbl_80564858, lbl_8056485C);
            f32 angle = *(f32 *)(p + 0x18) + (curve + -*(f32 *)(p + 0x34) * (curve * curve - curve)) * (*(f32 *)(p + 0x1C) - *(f32 *)(p + 0x18));
            f32 v[3];
            v[0] = speed * fn_80287BC8(-angle, angle);
            v[1] = dt * fn_80287BC8(-angle, angle);
            v[2] = angle;
            fn_802A70E4(arg0, v);
        } while (*(s32 *)(p + 4) < *(s32 *)(p + 8));
    }
}

#pragma pop
extern float fn_80287BC8(float, float);
extern void fn_802A70E4(void *, float *);
extern s32 fn_802CAC54(s32);
extern s32 fn_80128670(s32);
extern s32 fn_80128668(void *);
void *fn_802A7614(void *arg0, s32 arg1) {
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x2C));
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern f32 lbl_80564858, lbl_805648C8;
#pragma push
#pragma processor 750
s32 fn_802A7680(s32 arg0) {
    struct Vec { f32 x, y, z; };
    u8 *object = (u8 *)arg0;
    f32 amplitude = lbl_805648C8;
    s32 offset = 0;
    s32 i = 0;

    while (i < *(s32 *)(object + 4)) {
        f32 angle2;
        f32 angle;
        f32 y;
        f32 z;
        f32 x;
        struct Vec *out;

        angle = *(f32 *)(object + 0x18);
        z = *(f32 *)(object + 0x14) +
            fn_80287BC8(amplitude * -angle, amplitude * angle);
        y = *(f32 *)(object + 0x10) +
            fn_80287BC8(lbl_80564858, *(f32 *)(object + 0x1C));
        angle2 = *(f32 *)(object + 0x18);
        x = *(f32 *)(object + 0xC) +
            fn_80287BC8(amplitude * -angle2, amplitude * angle2);
        out = (struct Vec *)(*(u32 *)object + offset);
        i++;
        offset += 0xC;
        out->x = x;
        out->y = y;
        out->z = z;
    }
    *(f32 *)(object + 0x3C) = lbl_80564858;
}
#pragma pop
extern f32 PSVECSquareDistance(const void *, const void *);
extern double fn_8002F234(double);
extern void *fn_801E8718(s32);
extern f32 lbl_805648CC;
extern f32 lbl_805648D0;
extern f32 lbl_805648D4;
#pragma push
#pragma optimization_level 2
#pragma processor 750
#pragma dont_inline on
void fn_802A775C(void *arg0) {
    s32 offset;
    s32 i;
    Vec2_802A775C sp10;
    Vec2_802A775C sp8;
    f32 sp18[3];
    f32 f29;
    f32 distSq;
    f32 one;
    void *cam;

    cam = (u8 *)fn_801E8718(0) + 0x24;
    distSq = PSVECSquareDistance(cam, (u8 *)arg0 + 0xC);

    if (distSq > *(f32 *)((u8 *)arg0 + 0x18) * *(f32 *)((u8 *)arg0 + 0x18)) {
        f32 t = fn_802A4AD4();
        f32 x = *(f32 *)((u8 *)arg0 + 0x20);
        f32 z = *(f32 *)((u8 *)arg0 + 0x28);
        f32 y = *(f32 *)((u8 *)arg0 + 0x24);
        f32 xx = x * x;
        f32 tx;
        f32 ty;
        f32 zz;
        f32 tz;
        f32 sum;
        f32 len;
        f32 inv;

        sp10.x = x;
        tx = x * t;
        ty = y * t;
        zz = z * z;
        sp10.z = z;
        tz = z * t;
        sum = xx + zz;
        sp18[0] = tx;
        sp18[1] = ty;
        sp18[2] = tz;

        len = (f32)fn_8002F234(sum);
        one = lbl_8056485C;
        offset = 0;
        i = 0;
        inv = -*(f32 *)((u8 *)arg0 + 0x18) * (one / len);
        sp10.x *= inv;
        sp10.z *= inv;

        sp8.d = sp10.d;
        {
            f32 neg_x = -sp8.x;
            sp8.x = sp8.z;
            sp8.z = neg_x;
        }

        while (i < *(s32 *)((u8 *)arg0 + 4)) {
            f32 *pt = (f32 *)(*(u8 **)arg0 + offset);
            if (PSVECSquareDistance(pt, (u8 *)arg0 + 0xC) < *(f32 *)((u8 *)arg0 + 0x18) * *(f32 *)((u8 *)arg0 + 0x18)) {
                pt[0] += sp18[0];
                pt[1] += sp18[1];
                pt[2] += sp18[2];
            } else {
                f32 r = fn_80287BC8(lbl_805648CC, lbl_805648D0);
                f32 f28 = one - r * r;
                f32 ptz = *(f32 *)((u8 *)arg0 + 0x14) + sp8.z * r + sp10.z * f28;
                f32 ry = fn_80287BC8(lbl_80564858, *(f32 *)((u8 *)arg0 + 0x1C));
                pt[0] = *(f32 *)((u8 *)arg0 + 0xC) + sp8.x * r + sp10.x * f28;
                pt[1] = *(f32 *)((u8 *)arg0 + 0x10) + ry;
                pt[2] = ptz;
            }
            offset += 0xC;
            i++;
        }
        f29 = lbl_80564858;
    } else {
        f29 = *(f32 *)((u8 *)arg0 + 0x38) * (lbl_8056485C - (f32)fn_8002F234(distSq) / *(f32 *)((u8 *)arg0 + 0x18));
    }

    if (((f32)__fabs(f29) <= *(f32 *)(void *)&lbl_80558DC4) != ((f32)__fabs(*(f32 *)((u8 *)arg0 + 0x3C)) <= *(f32 *)(void *)&lbl_80558DC4)) {
        fn_802C990C(*(s32 *)((u8 *)arg0 + 0x34));
    }
    fn_802C2B78(lbl_80564850, lbl_805648D4, f29);
    *(f32 *)((u8 *)arg0 + 0x3C) = f29;
}
#pragma pop
extern f32 lbl_80564850, lbl_80564854, lbl_80564858, lbl_8056485C;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern s32 fn_802C90F0(s32);
extern void fn_802C9118(void);
extern void fn_802C9124(s32, s32, f32, f32, u32, f32, f32, f32, f32);
extern void fn_802D3D50(void);
extern void fn_802A5FE4(void);
extern void *fn_801E7E34(void);
#pragma cplusplus on
struct Obj802A5878 {
    virtual void *v0();
    virtual void *v1();
    virtual const char *name();
    virtual Obj802A5878 *child(s32);
};
#pragma cplusplus reset
