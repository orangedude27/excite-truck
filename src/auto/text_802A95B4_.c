#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_8000D838(void*);
extern void fn_802A9680(void*, s32);
extern void __register_global_object(void*, void*, void*);
extern char lbl_80349D88[];
extern char lbl_804BD6F8[];
extern s32 lbl_8055F8E0;
extern s32 lbl_8055F8E8;
extern s32 lbl_8055F8EC;
// split_file divides it into the game's real files (file_status shows its range).

void fn_802A95B4(int arg0) {
    #pragma use_lmw_stmw off
    struct Rec { s32 ptr; s32 id; };
    char *base = lbl_80349D88;
    char *objbase = lbl_804BD6F8;
    s32 neg = -1;
    struct Rec *rec = (struct Rec *)(objbase + 0x48);
    void (*dtor)(void*, s32) = &fn_802A9680;
    fn_8000D838(&lbl_8055F8E0);
    lbl_8055F8E8 = 0xFFFF0000;
    lbl_8055F8EC = 0xFFFF0000;
    rec[0].ptr = (s32)(base + 0x10);
    rec[0].id = neg;
    __register_global_object(&rec[0], (void *)dtor, objbase + 0x18);
    rec[1].ptr = (s32)(base + 0x1c);
    rec[1].id = neg;
    __register_global_object(&rec[1], (void *)dtor, objbase + 0x24);
    rec[2].ptr = (s32)(base + 0x28);
    rec[2].id = neg;
    __register_global_object(&rec[2], (void *)dtor, objbase + 0x30);
    rec[3].ptr = (s32)(base + 0x34);
    rec[3].id = neg;
    __register_global_object(&rec[3], (void *)dtor, objbase + 0x3c);
}
