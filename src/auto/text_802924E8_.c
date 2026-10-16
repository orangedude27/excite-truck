// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
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

void fn_80293128(void* arg0) {
    float value = fn_801E7E24(arg0);
    if (__fabsf(value) > lbl_80558DC4) fn_802936C4(arg0);
}

