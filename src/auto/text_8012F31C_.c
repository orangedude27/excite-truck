#include "types.h"
#include "string.h"
extern void fn_80128668(void);
extern void fn_80128670(s32);
extern void *fn_801284F8(s32, s32 *);
extern s32 lbl_8032AFC4;
extern s32 lbl_8032AFB8;
extern s32 lbl_8032AFD4;
extern s32 fn_8012850C(s32, s32 *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8032AFB8;
extern s32 lbl_8032AFD4;
extern s32 fn_8012850C(s32, s32 *);
void *fn_8012F31C(s32 arg0) {
    void *result = fn_801284F8(8, &lbl_8032AFB8);
    if (result != 0) {
        ((s32 *)result)[1] = arg0;
        ((s32 *)result)[0] = fn_8012850C(arg0, &lbl_8032AFD4);
    }
    return result;
}

void fn_8012F3CC(s32 arg0) {
    s32 *p = (s32 *)fn_801284F8(8, &lbl_8032AFC4);
    if (p != 0) { p[0] = arg0; p[1] = 0; }
}

void fn_8012F418(s32 *arg0) {
    if (arg0 == 0) return;
    arg0[1] = (s32)((u32)0x2bad2bad);
    arg0[0] = 0;
    fn_80128668();
}

void fn_8012F43C(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

void fn_8012F448(void *arg0, s32 arg1) {
    ((s32 *)arg0)[1] = arg1;
}

s32 fn_8012F450(void *arg0) {
    return ((s32 *)arg0)[1];
}

void fn_8012F458(void *arg0, s32 arg1) {
    s32 value = arg1;
    memcpy(**(u8 ***)arg0 + ((s32 *)arg0)[1], &value, 4);
    ((s32 *)arg0)[1] += 4;
}

void fn_8012F4AC(void *arg0, s32 arg1, s32 arg2) {
    void *data = **(void ***)arg0;
    s32 offset = *(s32 *)((u8 *)arg0 + 4);
    memcpy((u8 *)data + offset, *(void **)arg0, arg1);
    *(s32 *)((u8 *)arg0 + 4) = offset + arg2;
}

void fn_8012F550(void *arg0, s32 *arg1, s32 arg2) {
    *arg1 = *(*(s32 **)arg0) + ((s32 *)arg0)[1];
    ((s32 *)arg0)[1] += arg2;
}

