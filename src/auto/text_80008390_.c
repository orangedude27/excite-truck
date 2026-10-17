// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
extern void *fn_801E87A8(void);
extern s32 fn_8026E20C(void);
extern void fn_8026E204(s32);
extern s32 lbl_8034F3D0;
void fn_80008618(s32 arg0) {
    s32 value = fn_8026E20C();
    s32 result = value | arg0;
    if (value & arg0)
        result = value & ~arg0;
    fn_8026E204(result);
}

s32 fn_8000865C(void) {
    return (*(u32 *)((char *)fn_801E87A8() + 0x10) >> 1) & 1;
}

void fn_80009C80(void) {
    fn_80009534();
}

extern char lbl_8055D36D;
char fn_80009C84(void) {
    return lbl_8055D36D;
}

