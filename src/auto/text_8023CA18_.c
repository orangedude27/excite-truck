#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
extern char lbl_803415CC[0xC0];
extern s32 lbl_8055BB68;
extern char lbl_803415E8[];
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8023CA18(void) {
    if (lbl_8055BB68 == 0) {
        fn_80214A9C(0x1F);
    }
    fn_80214A9C(1);
}

void fn_8023CA50(void) {}

s32 fn_8023CB54(void) {
    fn_801330E8(4);
    fn_8023CA54();
    return 0;
}

s32 fn_8023CB80(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80128668(void *);
extern "C" void *fn_8023D134(void *arg0, s32 arg1) {
    struct VTable_8023D134 {
        virtual void slot0();
        virtual void slot1();
        virtual void destroy(s32);
    };
    if (arg0 != NULL) {
        void *prev = *(void **)((u8 *)arg0 + 0x38);
        *(void **)arg0 = (void *)lbl_803415E8;
        if (prev != NULL) {
            if (prev != NULL)
                ((VTable_8023D134 *)prev)->destroy(1);
            *(void **)((u8 *)arg0 + 0x38) = NULL;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
#pragma cplusplus off
void fn_8023D1C0(void) {
    lbl_8055BB68 = 0;
    fn_8023CC84(lbl_803415CC);
    lbl_8055BB68 = 2;
}

void fn_8023D1F8(void) {}

extern void fn_80221EA0(void *, s32, s32, s32);
extern s32 fn_80208D3C(void);
extern void *fn_80208D4C(s32);
extern char *strcpy(char *, const char *);
extern const char lbl_8055BB98[];
void fn_8023D1FC(void *p) {
    s32 n;
    void *item;
    fn_80221EA0(p, 2, *(s32 *)((u8 *)p + 0x24), 4);
    fn_80221EA0(p, 0, *(s32 *)((u8 *)p + 0x18), 4);
    fn_80221EA0(p, 1, *(s32 *)((u8 *)p + 0x20), 4);
    fn_80221EA0(p, 3, *(s32 *)((u8 *)p + 0x1c), 4);
    fn_80221EA0(p, 4, *(s32 *)((u8 *)p + 0x2c), 4);
    fn_80221EA0(p, 5, *(s32 *)((u8 *)p + 0x30), 4);
    fn_80221EA0(p, 6, *(s32 *)((u8 *)p + 0x34), 4);
    n = **(s32 **)((u8 *)p + 0x24);
    if (n >= 0 && n < fn_80208D3C()) {
        item = fn_80208D4C(n);
        strcpy(*(char **)((u8 *)p + 0x28), ((const char *(*)(void *))(*(s32 **)item)[3])(item));
    } else {
        strcpy(*(char **)((u8 *)p + 0x28), lbl_8055BB98);
    }
}

extern s32 lbl_8055BB68;
typedef struct Obj8023 {
    u8 pad[0x18];
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    char *f28;
    s32 f2c;
    s32 f30;
    s32 f34;
} Obj8023;
typedef struct Vtbl8023 {
    void *v0;
    void *v1;
    void *v2;
    const char *(*v3)(void *);
} Vtbl8023;
