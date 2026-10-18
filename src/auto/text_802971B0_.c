// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned char u8;
typedef signed int s32;
extern s32 fn_80296D28(s32);
extern s32 fn_80128668(void *);
extern s32 fn_8002F6AC(s32, void *);
void *fn_80297654(void *, s32);
extern char lbl_803493C0[];
extern float lbl_80564578;

extern void *fn_801284F8(s32, const char *);
extern s32 fn_80296B10(s32, s32);
typedef struct { void *pad[5]; s32 (*method)(void *, char *); } Vtbl14;
typedef struct { void *pad[23]; s32 (*method)(void *, char *); } Vtbl5C;
typedef struct { void *pad[3]; s32 (*method)(void *); } VtblC;
typedef struct { void *pad[2]; void (*method)(void *, s32); } Vtbl8;
extern char lbl_80349368[];
extern char lbl_80349378[];
__declspec(section ".sdata") extern char lbl_8055CA30[];
void *fn_802971B0(void *arg0) {
    s32 value;
    void *obj;
    obj = fn_801284F8(8, lbl_80349368);
    if (obj != 0) {
        *(void **)obj = &lbl_803493C0;
        value = ((s32 (*)(void *, char *))(*(void **)((char *)*(void **)arg0 + 0x14)))(arg0, lbl_80349378);
        *(s32 *)((char *)obj + 4) = fn_80296B10(value,
            ((s32 (*)(void *, char *))(*(void **)((char *)*(void **)arg0 + 0x5c)))(arg0, lbl_8055CA30));
    }
    if (obj != 0 && ((s32 (*)(void *))(*(void **)((char *)*(void **)obj + 0xc)))(obj) == 0) {
        if (obj != 0)
            ((void (*)(void *, s32))(*(void **)((char *)*(void **)obj + 8)))(obj, 1);
        obj = 0;
    }
    return obj;
}

extern void *fn_802972A4(void *);
__declspec(section ".sdata") extern char lbl_8055CA48[];
__declspec(section ".sdata") extern char lbl_8055CA50[];
s32 fn_80297354(void *arg0, void *arg1) {
    void *obj;
    float result[3];
    float zeroes[3];
    obj = fn_802972A4(arg1);
    if (obj != 0) {
        ((float (*)(void *, char *))(*(void **)((char *)*(void **)arg1 + 0x24)))(arg1, lbl_8055CA48);
        result[0] = lbl_80564578;
        result[1] = lbl_80564578;
        result[2] = lbl_80564578;
        ((void (*)(float *, void *, char *, float *))(*(void **)((char *)*(void **)arg1 + 0x38)))(zeroes, arg1, lbl_8055CA50, result);
        *(float *)arg0 = 0.0f;
        *(float *)((char *)arg0 + 4) = zeroes[0];
        *(float *)((char *)arg0 + 8) = zeroes[1];
        *(float *)((char *)arg0 + 12) = zeroes[2];
        *(void **)((char *)arg0 + 16) = obj;
        *(float *)((char *)arg0 + 20) = *(float *)arg0 + ((float (*)(void *))(*(void **)((char *)*(void **)obj + 0x10)))(obj);
    }
    return obj != 0;
}

__declspec(section ".sdata") extern char lbl_8055CA58[];
s32 fn_80297450(void **arg0) {
    char *value = ((char *(*)(void))((void **) *arg0)[2])();
    return stricmp(value, lbl_8055CA58) == 0;
}

float fn_8029748C(void *arg0) {
    s32 count = *(s32 *)((u8 *)arg0 + 4);
    float max = lbl_80564578;
    s32 offset = 0;
    while (count > 0) {
        float value = *(float *)(*(u8 **)arg0 + offset + 0x14);
        if (max <= value) max = value;
        offset += 0x18;
        count--;
    }
    return max;
}

void *fn_80297654(void *arg0, s32 arg1) {
    void *object;
    if (arg0 != 0) {
        object = *(void **)((char *)arg0 + 0x10);
        if (object != 0) {
            if (*(void **)((char *)arg0 + 0x10) != 0) {
                ((void (**)(void *, s32))(*(void ***)object))[2](object, 1);
            }
            *(void **)((char *)arg0 + 0x10) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802976D0(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_802976DC(s32 *arg0) {
    fn_8002F6AC(*arg0, &fn_80297654);
    fn_80128668(arg0);
}

#pragma push
#pragma use_lmw_stmw off
s32 fn_8029771C(void *arg0, void *arg1, float arg2) {
    register s32 offset = 0;
    register s32 i = 0;
    u8 *entry;
    float result[3];
    float x, y, z;
    void *object;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        entry = *(u8 **)arg0 + offset;
        if (arg2 >= *(float *)entry && arg2 <= *(float *)(entry + 0x14)) {
            x = *(float *)arg1;
            y = *(float *)((u8 *)arg1 + 4);
            z = *(float *)((u8 *)arg1 + 8);
            result[0] = x + *(float *)(entry + 4);
            result[1] = y + *(float *)(entry + 8);
            result[2] = z + *(float *)(entry + 0xc);
            object = *(void **)(entry + 0x10);
            ((void (*)(void *, float *, float))(*(void (***)(void))object)[5])(object, result, arg2 - *(float *)entry);
        }
        offset += 0x18;
        i++;
    }
    return arg2 < *(float *)((u8 *)arg0 + 8);
}
#pragma pop
void *fn_80297814(void *arg0, s32 arg1) {
    s32 value;
    if (arg0 != 0) {
        value = *(s32 *)((u8 *)arg0 + 4);
        *(void **)arg0 = &lbl_803493C0;
        if (value != 0) fn_80296D28(value);
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_8029788C(void *arg0) {
    s32 val = *(s32 *)((u8 *)arg0 + 4);
    s32 neg = -val;
    return (neg | val) >> 31 & 1;
}

extern s32 fn_80296D2C(s32);
extern s32 fn_802970C8(s32);
extern float lbl_80564578;
extern char lbl_8055CA40[];
extern char *lbl_8055CA38[];
extern char lbl_80349384[];
extern int stricmp(const char *, const char *);
extern int fn_802E317C(char *, ...);
s32 fn_802978A0(void *arg0) {
    return fn_80296D2C(*(s32 *)((u8 *)arg0 + 4));
}

s32 fn_802978A8(void *arg0) {
    return fn_802970C8(*(s32 *)((u8 *)arg0 + 4));
}

