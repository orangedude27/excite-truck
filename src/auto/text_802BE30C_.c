#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void*);
extern void fn_802BE694(void);
extern void fn_802BE72C(void);
extern void *lbl_8055FAC8;
extern struct {
    void *ptr;
    s32 value;
    s32 flags;
} lbl_804C07E4;
void* fn_802BE30C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802BE780(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

s32 fn_802BE7C4(s32 arg0, s32 arg1, s32 arg2) {
    s32 divisor = arg2 << 1;
    s32 a = ((arg0 - arg2) + 0x200) / divisor;
    s32 b = 0x400 / divisor;
    s32 c = ((arg1 - arg2) + 0x200) / divisor;
    return a + c * b;
}

void fn_802BE7F4(void) {}

void fn_802BE7F8(void) {
    fn_802BE694();
    lbl_804C07E4.ptr = lbl_8055FAC8;
    lbl_804C07E4.flags = 0x800284;
    lbl_804C07E4.value = 0;
}

void fn_802BE840(void) { fn_802BE72C(); }

