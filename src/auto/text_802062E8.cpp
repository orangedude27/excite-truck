#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_802073A4(void);
extern int lbl_8055ED8C;
extern void *lbl_8055ED90;
extern char lbl_8033BD3C;
extern float lbl_805631FC;
extern float lbl_80563204;
extern "C" int fn_8012A364(void*, void*);
extern "C" int fn_801284F8(int, void*);
extern "C" void *fn_8012A13C(void*, int, int);
extern "C" int fn_8012A2D8(void*);
extern "C" float PSVECMag(void*);

extern void *lbl_8055ED88;
extern "C" int fn_80206430(void) {
    extern int lbl_8055ED80;
    int val = lbl_8055ED80;
    unsigned int tmp = (unsigned int)(-val) | (unsigned int)val;
    return (int)(tmp >> 31);
}

extern "C" void fn_80206444(void) {
    extern int lbl_8055ED80;
    *(unsigned char*)((unsigned char*)&lbl_8055ED80 + 5) = 1;
}

extern "C" void fn_80206454(void) {
    extern int lbl_8055ED80;
    *(unsigned char*)((unsigned char*)&lbl_8055ED80 + 5) = 0;
}

extern "C" void fn_80206464(void* hi) {
    lbl_8055ED88 = hi;
}

extern "C" void fn_8020646C(long, long);
extern long lbl_804891E8[];
extern "C" void fn_8020646C(long arg0, long arg1) {
    lbl_804891E8[arg0] = arg1;
}

void fn_80206480(void) {
    return;
}

extern "C" void fn_80208D70(void);
extern "C" void *fn_80208D4C(void);
extern "C" int fn_80206430(void);
extern "C" void fn_80206484(int arg0) {
    extern void fn_80208D70(void);
    extern void *fn_80208D4C(void);
    fn_80208D70();
    ((void (**)(int))*(void ***)fn_80208D4C())[11](arg0);
}

void fn_802064C8(void) {
    return;
}

extern "C" void fn_802064D0(int arg0) {
    extern void fn_80208D70(void); extern void* fn_80208D4C(void);
    fn_80208D70(); void** obj=(void**)fn_80208D4C();
    ((void (*)(int))(*(void***)obj)[13])(arg0);
}

extern "C" void fn_80206518(void) {
    extern void fn_80208D70(void); extern void* fn_80208D4C(void);
    fn_80208D70(); void** obj=(void**)fn_80208D4C();
    ((void (*)(void))(*(void***)obj)[14])();
}

extern "C" void fn_80206550(unsigned int size) {
    extern int lbl_8055ED80; extern void* fn_80207C74(int, unsigned int);
    fn_80207C74(lbl_8055ED80, size);
}

extern int lbl_8055ED80;
extern "C" int fn_80207C50(int,int,int);
extern "C" void fn_8020655C(int a, int b) { fn_80207C50(lbl_8055ED80,a,b); }

extern void* fn_80207C74(int, unsigned int);
extern int lbl_802F9DA0;
extern void* fn_80208D4C(void);
extern void fn_80208D70(void);
extern "C" void* fn_80206570(int index) {
    int values[10]; int* p=(int*)&lbl_802F9DA0; int i;
    for(i=0;i<10;i++) values[i]=p[i];
    if(index<10) return (void*)values[index];
    return (void*)0x8033BD30;
}

extern "C" void fn_80206B08(void) {
	return;
}

extern "C" void fn_80206B0C(void) {
	return;
}

extern "C" void fn_80206B10(void) {
	return;
}

extern "C" void fn_80206BF4(void) {
	return;
}

extern "C" void fn_8020769C(void) {
	fn_802073A4();
}

