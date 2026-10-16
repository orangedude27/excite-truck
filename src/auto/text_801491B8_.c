// Code of main that had no source file yet: decomp.wtf gave it this one.

#include <types.h>
// split_file divides it into the game's real files (file_status shows its range).

void fn_8014ACCC(void) {

}

void fn_8014ACD0(void) {

}

void fn_8014ACD4(void) {

}

void fn_8014AED0(void *arg0, f32 farg0) {
    ((f32 *)arg0)[0x41] = farg0;
}

f32 fn_8014AED8(void *arg0) {
    return ((f32 *)arg0)[0x41];
}

u8 fn_8014AEE0(void *arg0) {
    return ((u8 *)arg0)[5];
}

u8 fn_8014AEE8(void *arg0) {
    return ((u8 *)arg0)[4];
}

s32 fn_8014C830(s32 arg0) { return arg0 + 0x14; }

void fn_8014DE4C(void) {

}

void fn_8014E704(void) {

}

void fn_8014E7D8(void) {

}

extern s32 fn_80128668(void);
extern void fn_8016783C(void *arg0);
extern void fn_801688FC(s32 arg0);
extern void fn_80168020(void);
extern void fn_8016A0D4(void);
extern void *memset(void *arg0, s32 arg1, s32 arg2);
extern s32 fn_801284F8(s32 arg0, void *arg1);
extern s32 fn_802ADDD8(s32 arg0);
extern void fn_8014F194(void *arg0);
extern s32 fn_80145E70(void *arg0);
extern s32 lbl_8032DB34;
extern s32 lbl_8032DB40;
s32 *fn_801500F8(void *arg0, s32 *arg1) {
    s32 value = *arg1;
    s32 index = ((s32 *)arg0)[1];
    s32 next = index + 1;
    s32 *data = *(s32 **)arg0;
    s32 offset;
    ((s32 *)arg0)[1] = next;
    offset = index * 4;
    *(s32 *)((char *)data + offset) = value;
    return (s32 *)((char *)data + offset);
}

s32 fn_80150AD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80150B18(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80150B58(void *arg0, s32 arg1) {
    ((s32 *)arg0)[8] = arg1;
}

void fn_80151688(void) {

}

void fn_80151914(void) {

}

void fn_801537C8(void) {

}

void fn_80154744(void) {

}

void fn_80154748(void) {

}

void fn_8015474C(void) {

}

void fn_80154750(void) {

}

void fn_80155368(void) {

}

void fn_801556F0(void) {

}

void fn_801556F4(void) {

}

void fn_801556F8(void) {

}

void fn_801556FC(void) {

}

void fn_80155AEC(void) {

}

void fn_80155E58(void *arg0) {
    ((u8 *)arg0)[4] = 0;
}

void fn_801560F4(void) {

}

void fn_80156100(void) {

}

void fn_80156104(void) {

}

void fn_80156108(void) {

}

