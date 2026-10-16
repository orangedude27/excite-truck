// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern f32 lbl_805640C0;
extern f32 lbl_805640C4;
extern f32 lbl_805640C8;
extern void* lbl_8055F5F0;
s32 stricmp(const char*, const char*);
void* fn_80279004(s32, s32);

typedef struct Node_80279254 {
    u8 pad0[0x243C];
    char name[0x20];
    s32 count;
    struct Node_80279254* next;
} Node_80279254;

s32 fn_80278A1C(void) {
    return 0;
}
