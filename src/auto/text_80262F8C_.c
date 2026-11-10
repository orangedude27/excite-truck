// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
extern s32 fn_801333E8(s32, const u8 *, u8 *, u8 *);
extern const u8 lbl_803462A8[];
extern const u8 lbl_80346048[];
extern s32 lbl_8055F434;
extern s32 lbl_8055C440;
extern f32 lbl_80563BC8;
extern s32 fn_80230E90(s32);
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
extern s32 fn_80128668(void);
extern s32 fn_80131234(const u8 *, const u8 *);
extern void fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 fn_802328D4(s32);
extern const u8 lbl_80346324[];
extern const u8 lbl_80346120[];
extern f32 lbl_80563BD4;
s32 fn_80262F8C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80262FCC(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = fn_8023659C();
    *((u8 *)arg0 + 0x1C) = 0;
    fn_80214A9C(0x1D);
}

void fn_8026300C(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = fn_8023659C();
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x18);
    if ((temp_f1 < temp_f0) || ((temp_f1 - temp_f0) > lbl_80563BC8)) {
        *((u8 *)arg0 + 0x1C) = 1;
    }
    if (*((u8 *)arg0 + 0x1C) != 0) {
        fn_80214AF0(0x1D);
    }
}

s32 fn_80263070(void *arg0) {
    return *((u8 *)arg0 + 0x1C) == 0;
}

s32 fn_80263080(void) {
    s32 temp_r0;
    temp_r0 = lbl_8055F434 - 1;
    lbl_8055F434 = temp_r0;
    if (temp_r0 < 0) {
        lbl_8055F434 = 0;
    }
    fn_80230E90(0);
    return 0;
}

s32 fn_802630C0(void) {
    s32 current = lbl_8055F434;
    s32 bound = lbl_8055C440;
    current++;
    lbl_8055F434 = current;
    if (current > bound) {
        lbl_8055F434 = bound;
    }
    fn_80230E90(0);
    return 0;
}

extern int fn_80263104(void);
int fn_80263104(void) {
    return lbl_8055F434 == lbl_8055C440;
}

void fn_8026311C(void) {}

s32 fn_80263658(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_80263698(void *arg0, s32 arg1) {
    struct VTable_80263698 {
        virtual void destroy(s32);
    };
    if (arg0 != 0) {
        void *child = *(void **)((char *)arg0 + 0x30);
        *(void **)arg0 = (void *)lbl_80346048;
        if (child == 0)
            goto cleanup;
        if (child == 0)
            goto cleanup;
        ((VTable_80263698 *)child)->destroy(1);
    cleanup:
        if (arg0 != 0) {
            *(void **)arg0 = (void *)lbl_80346120;
            ((s32 (*)(s32, const u8 *))fn_802328D4)(*(s32 *)((char *)arg0 + 0x18), lbl_80346120);
            *(s32 *)((char *)arg0 + 0x18) = 0;
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma scheduling on
#pragma cplusplus off
extern const u8 lbl_80346048[];
extern f32 lbl_80563BD8;
extern f32 lbl_80563BE8;
extern f32 lbl_80563BEC;
extern s32 fn_802E2C20(void);
extern s32 fn_802E8528(s32, f32, f32);
void *fn_80263740(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(const u8 **)arg0 = lbl_80346120;
            fn_802328D4(*(s32 *)((u8 *)arg0 + 0x18));
            *(s32 *)((u8 *)arg0 + 0x18) = 0;
        }
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void *fn_802637B0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(const u8 **)arg0 = lbl_80346120;
        fn_802328D4(*(s32 *)((u8 *)arg0 + 0x18));
        *(s32 *)((u8 *)arg0 + 0x18) = 0;
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void fn_8026381C(void) {}

void fn_80263820(void *arg0) {
    if (lbl_8055F434 == lbl_8055C440)
        *(s32 *)((u8 *)arg0 + 0x18) = 1;
    else
        *(s32 *)((u8 *)arg0 + 0x18) = 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_80263848(void *arg0, s32 arg1) {
    s32 temp_r28;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    void *p = arg0;
    temp_r28 = *(s32 *)((char *)p + 0x10);
    temp_r29 = *(s32 *)((char *)p + 0xC);
    temp_r30 = *(s32 *)((char *)p + 8);
    temp_r31 = *(s32 *)((char *)p + 4);
    temp_r3 = ((s32 (*)(const u8 *))fn_80131234)(lbl_80346324);
    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, s32, f32))fn_8022BAD0)(0x12, temp_r31, temp_r30, 0, temp_r29, temp_r28, temp_r3, *(s32 *)((char *)p + 0x18), 0, 1.0f);
}
#pragma pop
void fn_802638C4(void) {}

#pragma scheduling on
s32 fn_802638C8(void *arg0, s32 arg1) {
    if (*((u8 *)arg0 + 0x29) == 0) goto done;
    if (arg1 == 0x126) goto done;
    if (arg1 < 0x126) {
        if (arg1 < 0x125) goto done;
        goto set_value;
    }
    if (arg1 < 0x128) goto clear_value;
    goto done;
set_value:
    if (*((u8 *)arg0 + 0x28) != 0) goto done;
    *((u8 *)arg0 + 0x28) = 1;
    goto done;
clear_value:
    if (*((u8 *)arg0 + 0x28) == 0) goto done;
    *((u8 *)arg0 + 0x28) = 0;
done:
    return 0;
}

void fn_8026392C(void *arg0) {
    s32 value;
    value = lbl_8055F434;
    if (value == *(s32 *)((u8 *)arg0 + 0x20)) {
        *(s32 *)((u8 *)arg0 + 0x1C) = 1;
        *((u8 *)arg0 + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)arg0 + 0x1C) = 0;
        *((u8 *)arg0 + 0x29) = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
s32 fn_8026395C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x24) = arg1;
    *(s32 *)((u8 *)arg0 + 0x20) = arg1 * 2;
    return fn_801333E8(arg1 + 8, lbl_803462A8, (u8 *)arg0 + 0x28, (u8 *)arg0);
}
#pragma pop
extern s32 fn_80133460(s32, const u8 *, u8, s32);
extern s32 fn_801333E8(s32, const u8 *, u8 *, u8 *);
extern const u8 lbl_803462B8[];
extern const u8 lbl_803462A8[];
extern const u8 lbl_80346280[];
void fn_80263980(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    fn_80133460(value + 8, lbl_803462B8, *((u8 *)arg0 + 0x28), value);
}

extern double lbl_80563BE0;
s32 fn_80263998(void *arg0, s32 arg1) {
    u8 *self = (u8 *)arg0;

    if (self[0x29] != 0) {
        switch (arg1) {
        case 0x125:
            if (self[0x28] == 0) {
                self[0x28] = 1;
                *(f32 *)(self + 0x2C) = (f32)fn_802E2C20() / lbl_80563BD8;
            }
            break;
        case 0x126:
            break;
        case 0x127:
            if (self[0x28] != 0)
                self[0x28] = 0;
            break;
        }
    }

    if (self[0x29] != 0) {
        switch (arg1) {
        case 0x125:
            if (self[0x28] == 0)
                self[0x28] = 1;
            break;
        case 0x126:
            break;
        case 0x127:
            if (self[0x28] != 0)
                self[0x28] = 0;
            break;
        }
    }

    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma fp_contract on
void fn_80263AB4(void *arg0) {
    union {
        double value;
        unsigned int words[2];
    } converted;
    double raw;
    double bias;

    converted.words[1] = (unsigned int)fn_802E2C20() ^ 0x80000000;
    converted.words[0] = 0x43300000;
    raw = converted.value;
    bias = lbl_80563BE0;

    if ((f32)(raw - bias) / lbl_80563BD8 - *(f32 *)((u8 *)arg0 + 0x2C) < lbl_80563BE8) {
        fn_802E8528(*(s32 *)((u8 *)arg0 + 0x24), lbl_80563BD4, lbl_80563BEC);
    } else {
        ((s32 (*)(s32, f32, f32))fn_802E8528)(
            *(s32 *)((u8 *)arg0 + 0x24), lbl_80563BEC, lbl_80563BEC);
    }

    if (lbl_8055F434 == *(s32 *)((u8 *)arg0 + 0x20)) {
        *(s32 *)((u8 *)arg0 + 0x1C) = 1;
        *((u8 *)arg0 + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)arg0 + 0x1C) = 0;
        *((u8 *)arg0 + 0x29) = 0;
    }
}
#pragma pop
extern const u8 lbl_80346280[];
#pragma push
#pragma scheduling invalid_target
void fn_80263B68(void *arg0, s32 arg1) {
    s32 value;
    *(s32 *)((u8 *)arg0 + 0x24) = arg1;
    *(s32 *)((u8 *)arg0 + 0x20) = (arg1 * 2) + 1;
    ((void (*)(s32, const u8 *, u8 *))fn_801333E8)(arg1 + 8, lbl_80346280, (u8 *)arg0 + 0x28);
    value = *(s32 *)((u8 *)arg0 + 0x24);
    *(s32 *)((u8 *)arg0 + 0x2C) |= 1 << value;
}
#pragma pop
extern const u8 lbl_80346294[];
void fn_80263BCC(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    fn_80133460(value + 8, lbl_80346294, *((u8 *)arg0 + 0x28), value);
}

#pragma scheduling invalid_target
s32 fn_80263BE4(void *arg0, s32 arg1) {
    u8 *self = (u8 *)arg0;
    if (self[0x29] != 0) {
        switch (arg1) {
        case 0x125:
            if (self[0x28] == 0) {
                self[0x28] = 1;
                self[0x2A] = 1;
            }
            break;
        case 0x126:
            break;
        case 0x127:
            if (self[0x28] != 0)
                self[0x28] = 0;
            break;
        }
    }
    if (self[0x29] != 0) {
        switch (arg1) {
        case 0x125:
            if (self[0x28] == 0)
                self[0x28] = 1;
            break;
        case 0x126:
            break;
        case 0x127:
            if (self[0x28] != 0)
                self[0x28] = 0;
            break;
        }
    }
    return 0;
}
#pragma scheduling on
void fn_80263CA8(void *arg0) {
    if (*((u8 *)arg0 + 0x2A) != 0) {
        void *temp = *(void **)((u8 *)arg0 + 0x30);
        *((u8 *)arg0 + 0x2A) = 0;
        *(s32 *)((u8 *)temp + 0x14) = *(s32 *)((u8 *)arg0 + 0x2C);
        *((u8 *)temp + 0x4F) = 1;
        temp = *(void **)((u8 *)arg0 + 0x30);
        *((u8 *)temp + 0x49) = 1;
        *((u8 *)temp + 0x4B) = 0;
        *((u8 *)temp + 0x4A) = 0;
    }
    if (lbl_8055F434 == *(s32 *)((u8 *)arg0 + 0x20)) {
        *(s32 *)((u8 *)arg0 + 0x1C) = 1;
        *((u8 *)arg0 + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)arg0 + 0x1C) = 0;
        *((u8 *)arg0 + 0x29) = 0;
    }
}

void fn_80263D10(void) {}

void fn_80263D14(void) {}

extern const u8 lbl_80346310[], lbl_803462FC[], lbl_803462E8[], lbl_803462D4[];
void fn_80263D18(void *arg0, int arg_sp0) {
    struct Object {
        int unk0; int field4; int field8; int fieldC; int field10;
        int unk14; int unk18; int field1C; int field20; int unk24;
        unsigned char field28; unsigned char field29;
    };
    struct Object *obj = (struct Object *)arg0;
    int var_r31, var_r30;
    int a, b, c, d, e;
    if (obj->field29) {
        if (obj->field28) { var_r31=3; var_r30=0; }
        else { var_r31=0; var_r30=3; }
    } else if (obj->field28) { var_r31=2; var_r30=0; }
    else { var_r31=0; var_r30=2; }
    {
        int value = obj->field20;
        int sign = (int)((unsigned int)value >> 31);
        int low = value & 1;
        if (((low ^ sign) - sign) != 0) {
            a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
            e=((int (*)(const u8 *))fn_80131234)(lbl_80346310);
            ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,f32,s32))fn_8022BAD0)(
                0xC9,d,c,0,b,a,e,obj->field1C,lbl_80563BD4,0);
        } else {
            a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
            e=((int (*)(const u8 *))fn_80131234)(lbl_803462FC);
            ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,f32,s32))fn_8022BAD0)(
                0xC9,d,c,0,b,a,e,obj->field1C,lbl_80563BD4,0);
        }
    }
    a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
    e=((int (*)(const u8 *))fn_80131234)(lbl_803462E8);
    ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,f32,s32))fn_8022BAD0)(
        0xCA,d+0x159,c+2,0,b,a,e,var_r31,lbl_80563BD4,0);
    a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
    e=((int (*)(const u8 *))fn_80131234)(lbl_803462D4);
    ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,f32,s32))fn_8022BAD0)(
        0xCA,d+0x1BD,c+2,0,b,a,e,var_r30,lbl_80563BD4,0);
}

