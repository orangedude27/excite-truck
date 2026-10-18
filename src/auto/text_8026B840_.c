#include "types.h"

extern void *lbl_8055F4E0;
extern void *lbl_8055F4E4;
extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;

void fn_8026B840(void) {}

f32 fn_8026B844(f32 f) {
    f32 c = lbl_80563D78;
    if (f > c) {
        f32 t = (f - lbl_80563D7C) / lbl_80563D80;
        if (c > t) c = t;
        return c;
    }
    {
        f32 t = (lbl_80563D7C + f) / lbl_80563D84;
        if (c < t) c = t;
    }
    return c;
}

BOOL fn_8026BFF0(s32 x) {
    switch (x) { case 3: case 4: return TRUE; default: return FALSE; }
}

void* fn_8026DDD0(void) {
    return lbl_8055F4E0;
}

void fn_8026E204(void* hi) {
    lbl_8055F4E4 = hi;
}

extern void *lbl_8055F4E4;
void* fn_8026E20C(void) {
    return lbl_8055F4E4;
}

void* fn_8026E214(void* value) {
    void* old = lbl_8055F4E8;
    lbl_8055F4E8 = value;
    return old;
}

extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;

