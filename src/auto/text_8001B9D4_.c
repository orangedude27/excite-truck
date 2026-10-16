#include <types.h>

typedef struct Unk8001BBBC {
    s32 unk_0x0;
    s32 unk_0x4;
    s32 unk_0x8;
} Unk8001BBBC;

extern s8 lbl_8055D5C8;
extern void fn_8001C9C4(void);
extern void fn_8001CAF8(void);
extern s32 fn_8001D25C(s32);
extern s32 fn_8001CDB8(s32, s32, s32, s32, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).



extern void fn_8001C4D4(void);
void fn_8001BA50(void *arg0) {
    ((s8 *)arg0)[0x10] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = -1;
}

void fn_8001BA68(void) {
}

void fn_8001BA6C(void) {
    fn_8001C714();
}

void fn_8001BA70(void) {
    fn_8001C73C();
}

void fn_8001BA74(void) {
    fn_8001C960();
}

void fn_8001BA78(void) {
    lbl_8055D5C8 = 1;
    fn_8001C9C4();
}

void fn_8001BA84(void) {
    lbl_8055D5C8 = 0;
    fn_8001CAF8();
}

#pragma scheduling off
s32 fn_8001BA90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp = fn_8001D25C(arg2);
    if (temp != 0) {
        return fn_8001CDB8(arg0, arg1, temp, arg3, arg4);
    }
    return arg4;
}
#pragma scheduling reset
void fn_8001BBB4(void) {
    fn_8001D020();
}

void fn_8001BBB8(void) {
    fn_8001CF8C();
}

extern void fn_8001D234(s32, s32 *, s32 *, s32 *);
void fn_8001BBBC(void *arg0, s32 arg1) {
    s32 values[3];
    fn_8001D234(arg1, &values[0], &values[1], &values[2]);
    ((s32 *)arg0)[0] = values[0];
    ((s32 *)arg0)[1] = values[1];
    ((s32 *)arg0)[2] = values[2];
}

s32 fn_8001BCF0(void *arg0) {
    s32 var_r5 = 0;
    
    s32 ptr = ((s32 *)arg0)[6] + ((s32 *)arg0)[3] * 0xC;
    
    if (*((u8 **)ptr + 0x10) != 0)
        goto done;
    
    if (((u8 *)arg0)[0x20] == 0)
        goto done;
    
    var_r5 = 1;
done:
    return var_r5;
}

s32 fn_8001BD28(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_8001BD6C(void *arg0, void *arg1) {
    s32 r3 = ((s32 *)arg0)[6];
    s32 r4 = ((s32 *)arg0)[3];
    s32 r5 = ((s32 *)arg1)[6];
    s32 r6 = ((s32 *)arg1)[3];
    s32 result = fn_8001D2E4(r3, r4, r5, r6);
    return result >> 31;
}

void fn_8001C0E8(void) {
    fn_8001BC28();
}

void fn_8001C4D4(void) {

}

void fn_8001C4D8(void) {
    fn_8001C4D4();
    __builtin_unreachable();
}

void fn_8001C4DC(void) {
    fn_8001C4D8();
}

void fn_8001D7A4(void) {

}

