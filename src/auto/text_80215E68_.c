extern void fn_8021889C(void);

#include <types.h>

extern void *lbl_8055EF88;
extern s32 lbl_8055EF78;
extern u32 lbl_8055EF7C;
extern u32 lbl_8055EF8C;
extern void (*lbl_8055EF90)(void);
extern u8 lbl_8055EF70;
extern u8 lbl_8055F024;
extern u32 lbl_804908C8[16];
extern s32 fn_802C8530(void);
extern s32 fn_80216244(void);
extern s32 fn_802160AC(void);
extern s32 fn_80211F54(void);
extern s32 fn_80019BA8(void);
extern s32 fn_80230DA0(void);
extern s32 fn_802C855C(void);
extern s32 fn_802C2B48(void);
extern s32 fn_80211F64(void);
extern s32 fn_802164D8(void);
extern s32 fn_80129AFC(void);
extern s32 fn_802161CC(s32);
extern s32 fn_80218370();
extern s32 fn_802E97B4(void);
extern void fn_802166B8(void);
#pragma small_data off
extern char lbl_8033D690;
#pragma small_data on
extern s32 fn_80215EC4(s32, s32);
#pragma small_data off
extern void *lbl_80490710;
#pragma small_data on
extern void fn_8002F634(void *, void *, s32, s32);
extern f32 lbl_8055EF94;
extern s32 lbl_8055EF74;
extern s32 fn_80217270(s32);
extern s32 fn_802E317C(const char *);
extern char lbl_8033D7EC;
extern s32 fn_80218464(void);


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
s32 fn_80215E68(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80215EA8(void) {
    fn_8002F634(&lbl_80490710, fn_80215EC4, 0x18, 0x10);
}

s32 fn_80215EC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80215F04(void *arg0) {
    *(char **)arg0 = &lbl_8033D690;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
}

s32 fn_80215F1C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80215F5C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 fn_802C3034(s32);
extern s32 fn_802C3424(s32, s32, s32, s32, s32);
extern s32 lbl_8055FBDC;
extern s32 fn_802E4A10(void);
extern char lbl_8033D768;
extern char lbl_8033D774;
char *fn_80215F9C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x10) != 0) return (char *)&lbl_8033D774;
    return (char *)&lbl_8033D768;
}

void fn_80215FBC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

void fn_80215FCC(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x10) ^= 1;
}

u32 fn_80215FDC(void) { return 1; }

u32 fn_80215FE4(void) { return 1; }

u8 fn_80215FEC(void *arg0) { return *(u8 *)((u8 *)arg0 + 8); }

u8 fn_80215FF4(u8 *arg0) { return *arg0; }

s32 fn_80215FFC(void *arg0) {
    s32 result = 0;
    if (*(u8 *)arg0 != 0 && *(s32 *)((u8 *)arg0 + 4) == fn_802E4A10()) result = 1;
    return result;
}

u32 fn_80216054(void) { return 1; }

void fn_8021605C(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r3;
    fn_802C3034(arg1);
    temp_r4 = *(s32 *)((u8 *)arg0 + 8);
    temp_r3 = *(s32 *)((u8 *)arg0 + 4);
    fn_802C3424(temp_r3, temp_r4, temp_r3 + *(s32 *)((u8 *)arg0 + 0xC), temp_r4 + *(s32 *)((u8 *)arg0 + 0x10), lbl_8055FBDC);
}

extern s32 fn_8021832C(void);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_802C5310(s32, s32, f32, f32, f32);
extern u32 lbl_8055EF80;
extern u32 lbl_8055EF84;
extern f32 lbl_80563458;
extern f64 lbl_80563460;
extern f32 lbl_80563468;
extern f32 lbl_8056346C;
extern f32 lbl_80563470;
extern f32 lbl_80563474;
extern f32 lbl_80563478;
s32 fn_802160AC(void) {
    u8 sp8[0x30];
    s32 temp_r31;
    if (lbl_8055EF88 != 0) temp_r31 = fn_8021832C();
    else temp_r31 = 0;
    if (temp_r31 == 0 && lbl_8055EF7C == 0) return 0;
    fn_802C974C(lbl_80563468, lbl_8056346C, lbl_80563470);
    fn_80230B5C(sp8);
    fn_802C8638(sp8);
    {
        f64 x = (f64)(((u32)lbl_8055EF80 ^ 0x80000000) | 0x43300000) - lbl_80563460;
        f64 y = (f64)(((u32)lbl_8055EF84 ^ 0x80000000) | 0x43300000) - lbl_80563460;
        f32 a = (f32)x - lbl_80563474;
        f32 b = lbl_80563478 - (f32)y;
        if (temp_r31 != 0) fn_802C5310(temp_r31, 0, a, b, lbl_80563458);
        else fn_802C5310(lbl_8055EF7C, 0, a, b, lbl_80563458);
    }
    return 0;
}

void fn_80216194(void) {
    s32 i = 1;
    do {
        fn_802166B8();
    } while (i++ < 3);
}

#pragma dont_inline on
s32 fn_802161CC(s32 arg0) {
    u32 *p = lbl_804908C8;
    s32 i = 0;
    do {
        u32 value = *p;
        if (value != 0 && (arg0 != 0 || value != (u32)lbl_8055EF88)) {
            fn_80218464();
        }
        i++;
        p++;
    } while (i < 16);
}

extern s32 fn_80127A50(void *);
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_8056347C, lbl_80563480;
extern void fn_80217590(void *,s32,s32), fn_802176D4(void *,s32,s32), fn_8021749C(void *,s32,s32), fn_802175F0(void *,s32,s32), fn_80217734(void *,s32,s32);
extern void fn_80217834(void *), fn_80217854(void *);
extern s32 fn_802E47B8(void), fn_802E46F0(void);
extern void fn_80217874(void *,u16);
s32 fn_802164D8(void) {
 s32 event[6];
 if (fn_80127A50(event)) {
  s32 x = (s32)((lbl_8056347C * (f32)event[1]) / (f32)lbl_8055CFF0);
  s32 y = (s32)((lbl_80563480 * (f32)event[2]) / (f32)lbl_8055CFF4);
  lbl_8055EF80=x; lbl_8055EF84=y;
  if (lbl_8055EF88) {
   switch(event[0]) {
   case 0: fn_80217590(lbl_8055EF88,x,y); break;
   case 1: fn_802176D4(lbl_8055EF88,x,y); break;
   case 2: fn_8021749C(lbl_8055EF88,x,y); break;
   case 3: fn_802175F0(lbl_8055EF88,x,y); break;
   case 4: fn_80217734(lbl_8055EF88,x,y); break;
   case 7: fn_80217834(lbl_8055EF88); break;
   case 8: fn_80217854(lbl_8055EF88); break;
   }
  }
 }
 if (fn_802E47B8()) {
  u16 key=fn_802E46F0();
  if(lbl_8055EF88) fn_80217874(lbl_8055EF88,key);
 }
}

#pragma dont_inline reset

void fn_8021662C(void) {
    s32 temp_r31;
    temp_r31 = lbl_8055EF78;
    fn_80211F64();
    if (lbl_8055EF90 != NULL) lbl_8055EF90();
    fn_802164D8();
    if (lbl_8055EF88 != 0) fn_80129AFC();
    fn_802161CC(0);
    if (lbl_8055EF88 != 0) {
        fn_80218370(lbl_8055EF88);
    }
    if (temp_r31 == (s32)lbl_8055EF78) {
        if ((s32)lbl_8055EF70 == 0) fn_802166B8();
        fn_802E97B4();
    }
}

void fn_802166B8(void) {
    fn_802C8530();
    fn_80216244();
    fn_802160AC();
    if (fn_80211F54() == 0) {
        fn_80019BA8();
    }
    if (lbl_8055F024 != 0) {
        fn_80230DA0();
    }
    fn_802C855C();
    fn_802C2B48();
}

extern u32 lbl_8055EF98;
u32 *fn_80216708(void) {
    return &lbl_8055EF98;
}

void fn_80216710(void) {
    lbl_8055EF88 = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 4) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 8) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0xC) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x10) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x14) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x18) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x1C) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x20) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x24) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x28) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x2C) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x30) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x34) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x38) = 0;
    *(s32 *)((u8 *)&lbl_804908C8 + 0x3C) = 0;
    lbl_8055EF7C = 0;
    lbl_8055EF8C = 0;
    lbl_8055EF90 = 0;
}

void fn_8021676C(void) {

}

extern char lbl_8033D7A4;
extern char lbl_8033D7B4;
extern void *fn_801284F8(s32, const char *);
extern void *fn_80216D40(void *, s32, s32, s32, s32, s32, s32);
#pragma small_data off
#pragma small_data on
void *fn_80216770(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 unused) {
    void *result = fn_801284F8(0xDE8, &lbl_8033D7A4);
    s32 i;
    if (result != 0) {
        result = fn_80216D40(result, arg0, arg1, arg2, arg3, arg4, arg5);
    }
    for (i = 0; i < 16; i++) {
        if (lbl_804908C8[i] == 0) {
            lbl_804908C8[i] = (u32)result;
            return result;
        }
    }
    fn_802E317C(&lbl_8033D7B4);
    return 0;
}
void fn_8021683C(u32 arg0) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (lbl_804908C8[i] == arg0) {
            fn_80217270(1);
            lbl_804908C8[i] = 0;
            return;
        }
    }
    fn_802E317C(&lbl_8033D7EC);
}

void fn_802168BC(s32 arg0) {
    lbl_8055EF74 = arg0;
    lbl_8055EF70 = 1;
}

void fn_802168CC(void) {
    fn_8021889C();
}

void fn_802168D0(void) {
    fn_80218968();
}

void fn_802168D4(void) {
    fn_8021885C();
}

void fn_802168D8(void) {
    fn_80218A34();
}

void fn_802168DC(void) {
    fn_80218ADC();
}

void fn_802168E0(void) {
    fn_80218B88();
}

extern void *lbl_8055EF88;
void* fn_802168E4(void) {
    return lbl_8055EF88;
}

void fn_802168EC(void) {
    fn_80218C98();
}

extern char lbl_8055EF99;
void fn_80216CA8(void) {
    lbl_8055EF99 = 1;
}

f32 fn_80216CB4(void) { return lbl_8055EF94; }

