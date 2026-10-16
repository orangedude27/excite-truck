#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float fabsf(float);
extern void *lbl_8055D350;
extern f32 lbl_80560368, lbl_805603B4, lbl_80560360, lbl_8056039C, lbl_805603A0, lbl_805603A4, lbl_805603A8, lbl_805603AC, lbl_80562068;
extern u8 lbl_802FCD44[], lbl_802FCD78[], lbl_80558BA0[];
extern void fn_80013EDC(void *, s32, void *, void *, f32, f32, f32);
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[], lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
void fn_80014750(void *arg0) {
    void *manager;
    void *state;
    f32 value;
    if (*(u8 *)((u8 *)arg0 + 8)) {
        manager=lbl_8055D350;
        if (lbl_80562068-lbl_8056039C <= *(f32 *)((u8 *)manager+0x10)-*(f32 *)((u8 *)*(void **)((u8 *)manager+0xC)+0xC)) return;
        fn_8000C630(0x17,-1);
        return;
    }
    manager=lbl_8055D350;
    state=*(void **)((u8 *)manager+0xC);
    value=*(f32 *)((u8 *)state+0x10);
    if (!(value>lbl_8056039C && value<lbl_805603A0) && !(value>lbl_805603A4)) return;
    if (!((*(u32 *)((u8 *)*(void **)((u8 *)manager+0x2C)+0x2C0)&0x20)!=0)) return;
    fn_8000C630(0x17,-1);
}

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

s32 fn_800151D4(void) { return 1; }

s32 fn_800151DC(void *arg0) {
    void *manager = lbl_8055D350;
    s32 result = 0;
    if ((*(u32 *)((u8 *)manager + 0x20) & 0x400) &&
        (*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x2C) + 0x2C0) & 0x10)) {
        void *obj = *(void **)((u8 *)arg0 + 0x50);
        void **vt = *(void ***)obj;
        ((void (*)(void *, void *))((u8 *)vt + 0xC))(obj, lbl_80558BBC);
        fn_801476C4();
    }
    if ((*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x30)) & 4) && (*(u32 *)((u8 *)manager + 0x20) & 0x200)) result = 1;
    if (result) {
        void *obj = *(void **)((u8 *)arg0 + 0x50);
        void **vt = *(void ***)obj;
        ((void (*)(void *, void *))((u8 *)vt + 0xC))(obj, lbl_802FCDB4);
        fn_801476C4();
    }
    return result;
}

extern void fn_801476C4(void);
extern u8 lbl_80558BBC[];
extern u8 lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
void fn_80015AA0(void *arg0, f32 angle) {
    f32 c = (f32)cos();
    f32 s = (f32)sin(angle);
    f32 *m = (f32 *)arg0;
    m[0]=c; m[1]=s; m[2]=lbl_80560360; m[3]=-s;
    m[4]=c; m[5]=lbl_80560360; m[6]=lbl_80560360; m[7]=lbl_80560360;
    m[8]=lbl_80560368;
}

s32 fn_80016288(void) {
    return 0;
}

extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[];
extern u8 lbl_802FCE88[];
void *__AXFXGetLfoSinTable(void) {
    return lbl_802FCE88;
}
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
