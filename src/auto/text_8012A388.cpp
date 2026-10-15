#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8012E498(void);
extern void fn_8012CC24(void);

extern "C" void fn_8012A46C(void) {

}

extern "C" void fn_8012B324(void) {

}

extern "C" void fn_8012B328(void) {

}

extern "C" void fn_8012BF24(void) {
    fn_8012E498();
}

extern "C" void fn_8012CC20(void) {
    fn_8012CC24();
}

extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2);

extern "C" s32 fn_8012C4E4(void *arg0, void *arg1, s32 arg2) {
    return fn_8012BC50(arg0, arg1, arg2);
}

