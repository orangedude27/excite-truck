#include "types.h"

extern void *lbl_8055F4E0;
extern void *lbl_8055F4E4;
extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;

BOOL fn_8026BFF0(s32 x) {
    if (x >= 5) {
        return 0;
    }
    if (x >= 3) {
        return 1;
    }
    return 0;
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

extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;

