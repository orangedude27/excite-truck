// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
extern unsigned char lbl_80349278[];
extern float lbl_8056450C;
extern void fn_80293CD0(void*, int, int, int);
extern void fn_80293EB0(void*);
extern unsigned char lbl_804B4168[];
extern void fn_80292EA8(void *);
extern void fn_80292EB4(void *);
void fn_802924E8(void) {
    fn_80292EA8(lbl_804B4168);
}

void fn_80292618(void) {
}

void fn_8029261C(void) {
    fn_80292EB4(lbl_804B4168);
}

void fn_80292628(void) {
    s32 i;
    unsigned char *entry = lbl_804B4168;
    for (i = 0; i < *(s32 *)(lbl_804B4168 + 0x180); i++, entry += 0x18) {
        void *obj = *(void **)(entry + 0x10);
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[3])(obj);
    }
}

extern int fn_802928D4(int, int, int, int, int, int);
void fn_802929D8(int arg0, int arg1, int arg2, int arg3) {
    fn_802928D4(0, arg0, arg1, arg2, arg3, arg1);
}

void fn_80292B48(void *arg0) {
    if (fn_80292FB4(lbl_804B4168, arg0) != 0 && arg0 != 0) {
        void *vtable = *(void **)arg0;
        void (*method)(void *, int) = *(void (**)(void *, int))((char *)vtable + 8);
        method(arg0, 1);
    }
}

typedef unsigned char u8;
typedef signed char s8;
extern int fn_8002B1D8(const char *, const char *, int);
extern int strcmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
extern int lbl_802FA998[];
extern char lbl_80349208[];
void fn_80292EA8(void *arg0) { *(s32 *)((u8 *)arg0 + 0x180) = 0; }

void fn_80292EB4(void *arg0) { *(s32 *)((u8 *)arg0 + 0x180) = 0; }

int fn_80292EC0(void *arg0, const char *arg1, s32 *arg2, s32 arg3) {
    s32 i;
    u8 *entry;
    for (i = 0, entry = (u8 *)arg0; i < *(s32 *)((u8 *)arg0 + 0x180); i++, entry += 0x18) {
        if (fn_8002B1D8(arg1, (char *)entry, 0xF) == 0) {
            *arg2 = i;
            return 1;
        }
    }
    return 0;
}

void fn_80292F40(void *arg0, void *arg1, const char *arg2) {
    s32 count = *(s32 *)((u8 *)arg0 + 0x180);
    u8 *entry = (u8 *)arg0 + count * 0x18;
    strncpy((char *)entry, arg2, 0x10);
    *(void **)(entry + 0x10) = arg1;
    *(s32 *)(entry + 0x14) = 1;
    *(s32 *)((u8 *)arg0 + 0x180) = count + 1;
}

extern float fn_801E7E24(void*);
extern void fn_802936C4(void*);
extern float lbl_80558DC4;
extern int fn_802C9950(int);
extern int fn_802C9994(int);
extern int fn_802C744C(void*, void*);
extern int fn_80128668(void*);
extern void fn_80293530(void*);
extern int fn_80293374(void*, void*);
extern char lbl_80349250[];
extern void* fn_802935A0(void*);
extern float lbl_805644D4;
extern char lbl_8055C988[];
extern char lbl_80349224[];
extern int fn_802C6CF8(int);
extern u8 lbl_80349294[];
void* __dt__Q34nw4r2ef6EffectFv_802930BC(void* arg0, int arg1) {
    if (arg0) {
        *(void**)arg0 = lbl_80349294;
        fn_80293530(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8029311C(void* arg0) {
    *(s32*)((u8*)arg0 + 0x2fac) = 0;
}

#pragma push
#pragma small_data off
#pragma pop
__declspec(section ".data") extern float lbl_80558DC4;
void fn_80293128(void* arg0) {
    float value = fn_801E7E24(arg0);
    float abs = (float)__fabs((double)value);
    if (!(abs <= lbl_80558DC4)) fn_802936C4(arg0);
}

#pragma push
#pragma scheduling invalid_target
void fn_80293530(void* arg0) {
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}
#pragma pop
void* fn_80293A00(void* arg0, void* arg1, int unused, int arg2, int arg3, int arg4) {
    *(void**)arg0 = lbl_80349278;
    fn_80293CD0(arg0, arg2, arg3, arg4);
    *(float*)((u8*)arg0 + 4) = lbl_8056450C;
    if (arg1) {
        void** vt = *(void***)arg1;
        *(float*)((u8*)arg0 + 4) = ((float (*)(void*, const char*))vt[10])(arg1, lbl_8055C988);
    }
    *(int*)((u8*)arg0 + 0x4c2c) = 0;
    return arg0;
}

extern unsigned char lbl_80349278[];
extern float lbl_8056450C;
extern void fn_80293CD0(void*, int, int, int);
extern void fn_80293EB0(void*);
void* __dt__Q34nw4r2ef6EffectFv_80293A88(void* arg0, int arg1) {
    if (arg0) {
        *(void**)arg0 = lbl_80349278;
        fn_80293EB0(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80293AE8(void* arg0) { *(int*)((u8*)arg0 + 0x4c2c) = 0; }

extern void fn_80293F20(void*);
void fn_80293AF4(void* arg0) {
    float value = fn_801E7E24(arg0);
    float abs = (float)__fabs((double)value);
    if (!(abs <= lbl_80558DC4)) fn_80293F20(arg0);
}

void fn_80293B44(void *arg0) {
    u8 *record = (u8 *)arg0 + 0x2C;
    s32 i = 0;
    goto check;
body:
    fn_802C744C(*(void **)((u8 *)arg0 + (*(u8 *)(record + 0x48) * 4) + 8), record);
    record += 0x4C;
    i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x4C2C)) goto body;
}

extern int fn_8012C33C(void *);
extern void fn_801345D8(void *, int, const char *, int, int);
extern void fn_80292CD8(void *, int, u8 *);
extern int fn_802C6FC0(void *, int, int);
extern char lbl_80349250[];
extern void *memset(void *, int, unsigned int);
void fn_80293CD0(void *arg0, int arg1, int arg2, int arg3) {
    char name[0x20];
    int i;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    for (i = 0; i < 8; i++) {
        fn_801345D8(name, 0x20, lbl_80349250, arg1, i + 1);
        if (fn_8012C33C(name) != 0) {
            if (arg3 != 0 && *(s8 *)arg3 != 0) fn_80292CD8(name, arg2, (u8 *)arg3);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            *(s32 *)((u8 *)arg0 + i * 4 + 8) = fn_802C6FC0(name, arg2, 0);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            i++;
            *(s32 *)((u8 *)arg0 + 0x28) = i;
        }
    }
    i = *(s32 *)((u8 *)arg0 + 0x28);
    for (; i < 8; i++) *(s32 *)((u8 *)arg0 + i * 4 + 8) = -1;
}

#pragma push
#pragma scheduling invalid_target
void fn_80293EB0(void* arg0) {
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}
#pragma pop

extern unsigned char lbl_8034925C[];
extern void fn_80294710(void *);
void *__dt__Q34nw4r2ef6EffectFv_802942DC(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_8034925C;
        fn_80294710(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8029433C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x222C) = 0;
}

extern void fn_80294780(void*);
void fn_80294348(void* arg0) {
    float value = fn_801E7E24(arg0);
    float abs = (float)__fabs((double)value);
    if (!(abs <= lbl_80558DC4)) fn_80294780(arg0);
}

#pragma scheduling off
void fn_80294398(void *arg0) {
    u8 *record = (u8 *)arg0 + 0x2C;
    s32 i = 0;
    goto check;
body:
    fn_802C744C(*(void **)((u8 *)arg0 + (*(u8 *)(record + 0x40) * 4) + 8), record);
    record += 0x44;
    i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x222C)) goto body;
}

void fn_80294530(void *arg0, int arg1, int arg2, int arg3) {
    char name[0x20];
    int i;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    for (i = 0; i < 8; i++) {
        fn_801345D8(name, 0x20, lbl_80349250, arg1, i + 1);
        if (fn_8012C33C(name) != 0) {
            if (arg3 != 0 && *(s8 *)arg3 != 0) fn_80292CD8(name, arg2, (u8 *)arg3);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            *(s32 *)((u8 *)arg0 + i * 4 + 8) = fn_802C6FC0(name, arg2, 0);
            i = *(s32 *)((u8 *)arg0 + 0x28);
            i++;
            *(s32 *)((u8 *)arg0 + 0x28) = i;
        }
    }
    i = *(s32 *)((u8 *)arg0 + 0x28);
    for (; i < 8; i++) *(s32 *)((u8 *)arg0 + i * 4 + 8) = -1;
}

#pragma push
#pragma scheduling on
void fn_80294710(void* arg0) {
    u8 *cursor = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x28)) {
        fn_802C6CF8(*(s32*)(cursor + 8));
        *(s32*)(cursor + 8) = -1;
        cursor += 4;
        i++;
    }
}
#pragma pop
extern float lbl_80564510, lbl_805644D4, lbl_80564500, lbl_805644FC, lbl_805644D8;
extern unsigned char lbl_804B4030[];
void fn_80294780(void *arg0) {
    unsigned char *base = (unsigned char *)arg0, *cur = base + 0x2c, *out = cur, *src;
    int i = 0;
    float dt = fn_801E7E24(arg0), scale = lbl_805644D4 - lbl_80564510 * dt;
    float x, y, z, vy;
    goto check;
body:
    if (*(float *)(cur + 0x3c) >= lbl_805644D8 && !(*(float *)(cur + 0x3c) > lbl_805644FC)) {
        x = *(float *)(cur + 0x30) * scale;
        y = *(float *)(cur + 0x34) * scale;
        z = *(float *)(cur + 0x38) * scale;
        vy = y - (lbl_80564500 * dt) * *(float *)(base + 4);
        *(float *)(out + 0x24) = *(float *)(cur + 0x24) + x * dt;
        *(float *)(out + 0x28) = *(float *)(cur + 0x28) + vy * dt;
        *(float *)(out + 0x2c) = *(float *)(cur + 0x2c) + z * dt;
        src = lbl_804B4030 + *(cur + 0x41) * 0x34;
        *(unsigned int *)(out + 0x00) = *(unsigned int *)(src + 0x10);
        *(unsigned int *)(out + 0x04) = *(unsigned int *)(src + 0x14);
        *(unsigned int *)(out + 0x08) = *(unsigned int *)(src + 0x18);
        *(unsigned int *)(out + 0x0c) = *(unsigned int *)(src + 0x1c);
        *(unsigned int *)(out + 0x10) = *(unsigned int *)(src + 0x20);
        *(unsigned int *)(out + 0x14) = *(unsigned int *)(src + 0x24);
        *(unsigned int *)(out + 0x18) = *(unsigned int *)(src + 0x28);
        *(unsigned int *)(out + 0x1c) = *(unsigned int *)(src + 0x2c);
        *(unsigned int *)(out + 0x20) = *(unsigned int *)(src + 0x30);
        *(float *)(out + 0x30) = x;
        *(float *)(out + 0x34) = vy;
        *(float *)(out + 0x38) = z;
        *(float *)(out + 0x3c) = *(float *)(cur + 0x3c) + dt;
        out[0x40] = cur[0x40];
        out[0x41] = cur[0x41];
        out += 0x44;
    }
    i++; cur += 0x44;
check:
    if (i < *(int *)(base + 0x222c)) goto body;
    *(int *)(base + 0x222c) = (out - (base + 0x2c)) / 0x44;
}

#pragma scheduling on
