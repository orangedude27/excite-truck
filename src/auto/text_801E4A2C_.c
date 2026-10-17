// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef signed short s16;
extern s32 fn_80128668(s32 *);
extern s32 fn_802C4C80(s32);
extern s32 fn_802C4FF8(const char *);
extern s32 fn_802C4F2C(s32, s32 *, s32 *);
extern s32 fn_802C501C(void);
void fn_801E4A2C(s32 *arg0) {
    if (arg0 != 0) {
        fn_802C4C80(*arg0);
        fn_80128668(arg0);
    }
}
