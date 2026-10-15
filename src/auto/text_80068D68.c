// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"

extern u8 lbl_803C0F78[];
extern u8 lbl_80316570[];
extern void fn_80070954(u32 code, void *msg, u16 param);
extern void fn_8007096C(u32 code, void *msg, u16 param1, u16 param2);
extern void fn_800709CC(u32 code, void *msg, s32 param1, s32 param2, u16 param3, u16 param4, u8 param5, u16 param6);

void fn_8006EACC(void) {

}

void fn_8006EAD0(void) {

}

void fn_8006EAD4(void) {

}

void fn_8006EAD8(void) {

}

void fn_8006EBF0(void) {

}

void fn_8006EC20(void) {
    fn_80068E08();
}

void fn_80072C38(void) {
    BTM_CancelRemoteDeviceName();
}

void fn_80073A1C(void) {

}

void fn_8007AD38(void) {

}

void fn_8007BC88(void) {

}

void fn_8007DEF4(void *arg0) {
    GKI_freebuf(arg0);
}

void fn_80089E3C(void) {

}

void fn_800911DC(void) {

}

void fn_800932D8(void) {

}

void fn_8009BFBC(void) {
    AXFXReverbHiExpCallback();
}

