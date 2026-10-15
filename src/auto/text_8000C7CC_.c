// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055D400;
extern u8 lbl_8055D404;
extern u8 lbl_8055D405;
extern u8 lbl_8055D406;
extern u8 lbl_8055D407;
extern s32 lbl_8055D408;
extern s32 lbl_8055D40C;
extern s32 lbl_8055D420;
extern void **lbl_8055D414;
extern void **lbl_8055D418;
extern void **lbl_8055D41C;
extern s32 lbl_8055D410;

void fn_802066C8(void*, u32);
void fn_80128668(void*);
void fn_8000CCB8(void);
void fn_80209110(s32);

s32 fn_8000CFA8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802066C8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}
