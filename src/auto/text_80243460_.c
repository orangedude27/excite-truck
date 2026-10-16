// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <string.h>
extern void fn_80241354(void*);
extern s32 lbl_803428B0[][16][3];
s32 fn_80243478(s32);

void fn_80243460(void* arg0) {
    fn_80241354((u8*)arg0 - 0x10);
}

extern void fn_80241820(void*);
void fn_80243468(void* arg0) {
    fn_80241820((u8*)arg0 - 0x10);
}

extern void fn_802408B0(void*);
void fn_80243470(void* arg0) {
    fn_802408B0((u8*)arg0 - 0x10);
}

#pragma dont_inline on
s32 fn_80243478(s32 arg0) {
    s32 count = 0;
    s32 (*entry)[3] = lbl_803428B0[arg0];
    s32 i;
    for (i = 0; i < 16; i++) {
        if ((*entry)[0] == 0) return count;
        count++;
        entry++;
    }
    return count;
}
s32 fn_80243710(s32 arg0, s32 arg1) {
    s32 result = 0;
    if (arg0 >= 0 && arg0 <= fn_80243478(arg1)) result = 1;
    return result;
}

void fn_802438EC(char* arg0) {
    s32 len = strlen(arg0);
    if (len > 0) {
        u8* end = (u8*)((u32)len + (u32)arg0);
        if ((s32)end[-1] == '_') end[-1] = 0;
    }
}

