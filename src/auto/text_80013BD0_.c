#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float fabsf(float);
extern void *lbl_8055D350;
extern f32 lbl_80560368, lbl_805603B4, lbl_80560360, lbl_805603A0, lbl_805603A8, lbl_805603AC;
extern u8 lbl_802FCD44[], lbl_802FCD78[], lbl_80558BA0[];
extern void fn_80013EDC(void *, s32, void *, void *, f32, f32, f32);
void fn_8001480C(void *arg0) {
 *(f32 *)((u8 *)arg0+0x10)=*(f32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x2C)+0x4C);
}

void fn_80014820(void *arg0) {
 void *p;
 f32 f;
 *(f32 *)((u8 *)arg0+0xC)=*(f32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x2C)+0x34);
 p=*(void **)((u8 *)lbl_8055D350+0x2C);
 f=lbl_805603A8*(fabsf(*(f32 *)((u8 *)arg0+0x10)-*(f32 *)((u8 *)p+0x4C))/lbl_805603A0);
 if (lbl_80560368<f) {} else { lbl_80560368=f; }
 if (lbl_80560368>lbl_805603AC) {} else { lbl_80560368=lbl_805603AC; }
 *(f32 *)((u8 *)arg0+0x10)=*(f32 *)((u8 *)arg0+0x10)+(lbl_80560368*(*(f32 *)((u8 *)p+0x4C)-*(f32 *)((u8 *)arg0+0x10)));
}

void fn_80014A98(void *arg0) {
 void *p=*(void **)((u8 *)lbl_8055D350+0x30);
 fn_80013EDC(lbl_802FCD44,0,lbl_802FCD78,lbl_80558BA0,*(f32 *)((u8 *)arg0+0x2C),*(s32 *)((u8 *)p+0x24)==3?*(f32 *)((u8 *)p+0x1C):*(f32 *)((u8 *)p+0x14),lbl_80560360);
}

s32 fn_80014ADC(void) { return 0; }

s32 fn_80014AE4(void) {
 s32 a=0,b=0,c=1,d=1;
 void *p=lbl_8055D350,*q;
 if (*(s32 *)((u8 *)p+4)==1 && *(s32 *)((u8 *)*(void **)((u8 *)p+0x30)+0x10)>0) a=1;
 q=*(void **)((u8 *)p+0x30);
 if (!(*(f32 *)((u8 *)q+0x1C)>lbl_80560368) && *(s32 *)((u8 *)q+0x10)!=*(s32 *)((u8 *)*(void **)((u8 *)p+0xC)+8)) d=0;
 if (d==0 && a==0) c=0;
 if (c!=0 && *(f32 *)((u8 *)q+0x14)<lbl_805603B4) b=1;
 if (b!=0) return 1;
 if (*(s32 *)((u8 *)q+0x10)>*(s32 *)((u8 *)*(void **)((u8 *)p+0xC)+8)) return 1;
 return 0;
}

