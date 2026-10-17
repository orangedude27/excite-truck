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
        if (entry[i][0] == 0) return count;
        count++;
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

extern s32 fn_80128668(void);
extern void fn_80221E7C(void);
extern s32 fn_802328D4(char*);
extern s32 fn_802C519C(char*);
extern char lbl_80342CEC[];
s32 fn_80243BD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80243C18(void) {
    fn_80221E7C();
}

extern void fn_80243938(char *, char *);
void fn_802443C0(void *arg0) {
    char *str;
    fn_802438EC(*(char **)((u8 *)arg0 + 0x18));
    str = *(char **)((u8 *)arg0 + 0x18);
    if (strlen(str) != 0) {
        str[strlen(str) - 1] = 0;
    }
    fn_80243938(*(char **)((u8 *)arg0 + 0x18), *(char **)((u8 *)arg0 + 0x1C));
}

void fn_8024442C(void *arg0) {
    u8 *field = (u8 *)arg0 + 0x29;
    *field = !*field;
}

u8 fn_80244550(void *arg0) {
    return *((u8 *)arg0 + 0x28);
}

s32 fn_80244558(void *arg0) {
    char *str = *(char **)((u8 *)arg0 + 0x18);
    s32 len = strlen(str);
    if (len > 0 && *(s8 *)((u32)len + (u32)str - 1) == '_') len--;
    return len;
}

