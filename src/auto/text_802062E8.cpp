#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_802073A4(void);
extern int lbl_8055ED8C;
extern void *lbl_8055ED90;
extern char lbl_8033BD3C;
extern char lbl_8033BD4C;
extern char lbl_8055B4C0[];
extern char lbl_8055B4C8[];
extern "C" void *fn_80206BF8(int, void*);
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

extern "C" void fn_80206750(void *arg0, int arg1, int arg2) {
    int count = (int)(long)lbl_8055ED88;
    int found = -1;
    int i = 0;
    for (; i < count; i++) {
        if (arg1 == lbl_804891E8[i]) {
            found = i;
            break;
        }
    }
    if (found >= 0 && arg2) {
        *(unsigned char *)((char *)arg0 + 0x4F) = 1;
        *(int *)((char *)arg0 + 0x14) = 1 << found;
    } else {
        *(int *)((char *)arg0 + 0x14) = 0;
        *(unsigned char *)((char *)arg0 + 0x4F) = 1;
    }
}

extern "C" void fn_80206A5C(void* arg0) {
    if (*(unsigned char*)((char*)arg0 + 0x34)) {
        *(unsigned char*)((char*)arg0 + 0x34) = 0;
        float value = *(float*)((char*)arg0 + 0x28);
        void* obj = *(void**)((char*)arg0 + 0xC);
        (*(void (**)(void*, float))(*(unsigned char**)obj + 0x44))(obj, value);
    }
    if (*(unsigned char*)((char*)arg0 + 0x35)) {
        void* obj = *(void**)((char*)arg0 + 0xC);
        *(unsigned char*)((char*)arg0 + 0x35) = 0;
        float value = *(float*)((char*)arg0 + 0x2C);
        (*(void (**)(void*, float))(*(unsigned char**)obj + 0x48))(obj, value);
    }
    if (*(unsigned char*)((char*)arg0 + 0x36)) {
        void* obj = *(void**)((char*)arg0 + 0xC);
        *(unsigned char*)((char*)arg0 + 0x36) = 0;
        float value = *(float*)((char*)arg0 + 0x30);
        (*(void (**)(void*, float))(*(unsigned char**)obj + 0x4C))(obj, value);
    }
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

extern float lbl_80563200;
extern char lbl_8033BDC0;
extern "C" void fn_80208620(int, void *);
extern "C" void fn_8020899C(int, int);
extern "C" int fn_80128668(void *);
extern "C" void fn_80206C70(void *arg0) {
    struct Callback {
        virtual void slot0();
        virtual void slot1(int);
    };
    fn_8012A364(lbl_8055ED90, arg0);
    if (--lbl_8055ED8C == 0) {
        if (lbl_8055ED90)
            ((Callback *)lbl_8055ED90)->slot1(1);
        lbl_8055ED90 = 0;
    }
}

extern "C" float fn_80206CD0(void* arg0, float arg1) {
    float f = lbl_805631FC;
    float x = lbl_80563204 * *(float*)((char*)arg0 + 8);
    if (f <= x) f = x;
    float y = PSVECMag(arg0) - f;
    if (y <= arg1) y = arg1;
    return arg1 / y;
}

extern "C" f32 fn_802072DC(void) {
    return lbl_805631FC;
}

extern "C" void *fn_802072E4(void *, int, int);
extern void fn_802065F8(void);
extern void fn_802085E8(int, void *);
extern void *fn_80208994(int, int, int, float);
extern float lbl_805631F8;
extern char lbl_8033BD90;
extern char lbl_8033BD78;
extern "C" void fn_80207428(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    fn_802072E4(arg0, arg1, arg2);
    *(int *)((char *)arg0 + 0x10) = arg3;
    *(void **)arg0 = &lbl_8033BD78;
    fn_80206750(arg0, arg3, arg4);
}

extern "C" void fn_8020769C(void) {
	fn_802073A4();
}

extern "C" void fn_802066C8(void*, u32);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80207748(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_802066C8(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern int lbl_8055ED94;
extern char lbl_8033BD58;
extern "C" void fn_80206B14(void);
extern "C" void *fn_802072E4(void *, int, int);
extern "C" void fn_802E30C8(const char *, ...);
extern int lbl_8055ED94;
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void fn_80207938(int arg0) {
    fn_802E30C8(&lbl_8033BD58, ++lbl_8055ED94, arg0);
}

