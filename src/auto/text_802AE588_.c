#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802B4E44(int);
extern void fn_802DBE4C(void);
extern void fn_802BDD58(void);
extern void fn_802DBECC(void);
extern void fn_802B2D94(int);
extern void fn_802B4E30(void);
extern char lbl_8055F980;
extern char lbl_8055F984[4];
extern int lbl_8055F988;
extern float lbl_80564B38;
extern int lbl_804BDFF0[8];
extern int lbl_8055CD7C;
extern int fn_8012850C(int, void *);
extern double fn_8002F234(float, float, float);
extern void *lbl_8055CD78;
extern void fn_80128668(void*);
void* fn_802AE588(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802AE5E0(int arg0) {
    int *ptr = &lbl_804BDFF0[1];
    int total = 0;
    int i = 2;
loop:
    *ptr = total;
    total += (i + 1) * 4;
    i *= 2;
    ptr++;
    if (i <= arg0) goto loop;
    *(int *)lbl_8055F984 = fn_8012850C(total * 2, &lbl_8055CD7C);
}

extern void fn_802AE64C(void *);
extern void fn_802C9950(int);
extern void fn_802C9994(int);
extern void fn_802C10C4(void);
extern char fn_802B05E4(void);
extern void fn_802BF40C(void);
extern void fn_802C2410(void);
extern void fn_802BDC60(void);
extern void fn_802B9D08(void);
extern void fn_802C2A34(void);
extern void fn_802B5808(void);
extern void fn_802C217C(void);
extern void fn_802B1FD4(void);
extern void fn_802C2874(void);
extern void fn_802B0954(void);
extern void fn_802B4BDC(void);
extern void fn_802BBCC4(void);
extern void fn_802BE840(void);
extern void fn_802C10B8(void);
extern int fn_802E2C20();
extern void fn_802BEB70(void);
extern int fn_802E30C8(char *, char *, ...);
extern void fn_802AE774(void);
extern int lbl_8055F970;
extern char lbl_8034A048[];
extern char lbl_8034A064[];
void fn_802AE644(void) { fn_802AE64C(lbl_8055F984); }

void fn_802AE64C(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

void fn_802AE690(void *arg0) {
    float y = *(float *)((char *)arg0 + 0x18);
    int result;
    if (y * *(float *)((char *)arg0 + 0x20) > lbl_80564B38) {
        if (y > lbl_80564B38) result = 3;
        else result = 0;
        lbl_8055F988 = result;
        return;
    }
    if (y > lbl_80564B38) result = 1;
    else result = 2;
    lbl_8055F988 = result;
}

float fn_802AE6E0(void *arg0, void *arg1) {
    float y0 = *(float *)((char *)arg0 + 8);
    float y1 = *(float *)((char *)arg1 + 8);
    float x0 = *(float *)arg0;
    float x1 = *(float *)arg1;
    float dy = y0 - y1;
    float dx = x0 - x1;
    float dy2 = dy * dy;
    float dx2 = dx * dx;
    return (float)fn_8002F234(dx2 + dy2, dy, y0);
}

int fn_802AE7AC(void) {
    int val = *(int *)lbl_8055F984;
    unsigned int tmp = (unsigned int)(-val) | (unsigned int)val;
    return (int)(tmp >> 31);
}

void fn_802AE7C0(void) {
    fn_802C9950(0x555766);
    fn_802C9994(0xFFF5D9);
}

void fn_802AE9D0(void) {
    lbl_8055CD78 = (void *)-1;
    fn_802C10C4();
    if (fn_802B05E4() == 0) fn_802BF40C();
    fn_802C2410();
    fn_802BDC60();
    fn_802B9D08();
    fn_802C2A34();
    fn_802B5808();
    fn_802C217C();
    fn_802B1FD4();
    fn_802C2874();
    fn_802B0954();
    fn_802B4BDC();
    fn_802BBCC4();
    fn_802BE840();
    fn_802AE644();
    lbl_8055F970 = 0;
}

void fn_802AEA44(void) {
    volatile int start;
    volatile char *buffer;
    fn_802C10B8();
    buffer = lbl_8034A048;
    start = fn_802E2C20((char *)buffer);
    fn_802BEB70();
    if (fn_802E2C20() - start > 0x1F4) {
        fn_802E30C8(lbl_8034A064, (char *)buffer);
    }
    fn_802AE774();
}

extern void fn_802BDC3C(void);
extern void fn_802B59A4(int);
extern void fn_802B0288();
extern void fn_802BB674(int, int);
extern void fn_802C10CC(int);
extern int lbl_8055F974;
extern int lbl_8055F978;
void fn_802AEAA8(void) { fn_802BDC3C(); }

void fn_802AEAAC(void) {
    int offset, i;
    if (lbl_8055F970 == 0) {
        fn_802B59A4(0);
        fn_802B0288();
    }
    i = 0;
    offset = 0;
    lbl_8055F974 = *(int *)(lbl_8055F970 + 4);
    lbl_8055F978 = *(int *)(lbl_8055F970 + 8);
    do {
        fn_802BB674(*(int *)((char *)lbl_8055F970 + offset + 0xC), i);
        offset += 8;
    } while (++i < 4);
    fn_802C10CC(*(int *)(lbl_8055F970 + 0x2C));
}

void fn_802AFE64(int *arg0, short a, short b, short c, short d, int e, int f, int g, float h, int j) {
    int index = *arg0;
    char *p;
    *arg0 = index + 1;
    p = (char *)arg0 + index * 0x1C;
    *(short *)(p + 4) = a;
    *(short *)(p + 6) = b;
    *(short *)(p + 8) = c;
    *(short *)(p + 10) = d;
    *(float *)(p + 12) = h;
    *(int *)(p + 16) = e;
    *(int *)(p + 20) = f;
    *(int *)(p + 24) = j;
    *(int *)(p + 28) = g;
}

void fn_802AFEA4(int *arg0, short arg1) {
    int index = *arg0;
    *arg0 = index + 1;
    *(short *)((char *)arg0 + index * 0x1C + 8) = arg1;
}

int fn_802AFF54(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802AFF5C(int *arg0, int arg1) {
    return *arg0 + arg1 * 0x24;
}

void fn_802AFF6C(void *arg0) {
    *(unsigned short *)*(void **)arg0 = *(unsigned short *)((char *)arg0 + 4) - 1;
}

void fn_802AFF80(void *arg0, short arg1) {
    unsigned short index = *(unsigned short *)((char *)arg0 + 4);
    unsigned short limit = *(unsigned short *)((char *)arg0 + 6);
    if (index >= limit) return;
    *(short *)(*(short **)arg0 + index) = arg1;
    *(unsigned short *)((char *)arg0 + 4) = index + 1;
}

void fn_802B0024(void *arg0, short arg1) {
    unsigned short count = *(unsigned short *)((char *)arg0 + 4);
    unsigned short limit = *(unsigned short *)((char *)arg0 + 6);
    if (limit != 0) {
        *(unsigned short *)((char *)*(void **)arg0) = 0;
        *(unsigned short *)((char *)arg0 + 4) = 1;
    }
    count = *(unsigned short *)((char *)arg0 + 4);
    limit = *(unsigned short *)((char *)arg0 + 6);
    if (count < limit) {
        *(short *)((char *)*(void **)arg0 + count * 2) = arg1;
        *(unsigned short *)((char *)arg0 + 4) = count + 1;
    }
}

extern unsigned short fn_802B127C(int, int);
extern float fn_801DCF48(int, float, float);
extern float lbl_80564AF0;
extern double lbl_80564B70;
unsigned short fn_802B0070(int arg0) {
    return fn_802B127C(lbl_8055F974, arg0);
}

void fn_802B009C(void *arg0, int arg1, int arg2, int arg3) {
    *(float *)arg0 = (float)arg2 * lbl_80564AF0;
    *(float *)((char *)arg0 + 8) = (float)arg3 * lbl_80564AF0;
    *(float *)((char *)arg0 + 4) = fn_801DCF48(arg1, *(float *)arg0, *(float *)((char *)arg0 + 8));
}

void fn_802B0114(void) {
}

s32 fn_802B0118(void *arg0) {
    return (*(u32 *)((u8 *)arg0 + 8) >> 6) & 7;
}

s32 fn_802B0124(void *arg0) {
    return (*(u32 *)((u8 *)arg0 + 8) >> 23) & 1;
}

s32 fn_802B0130(void *arg0) {
    s16 value = *(s16 *)((u8 *)arg0 + 4);
    return (s32)(((u32)value >> 31) + value) >> 1;
}

extern int fn_801E8718(int);
extern int fn_802AEB3C();
void fn_802B0144(void) {
    fn_801E8718(-1);
    fn_802AEB3C();
}

void fn_802B016C(void) {
    fn_802DBE4C();
    fn_802B14B4(lbl_8055F974);
    fn_802BDD54();
    fn_802B2D94(lbl_8055F978);
    fn_802B4E30();
    fn_802DBECC();
}

void fn_802B01A8(void) {
    int result;
    fn_802DBE4C();
    result = 1;
    if ((*(unsigned int *)((char *)fn_801E87A8() + 0x10) >> 1) & 1)
        result = 2;
    result = fn_802C9C58(result);
    fn_802B14B4(lbl_8055F974);
    fn_802C9C58(result);
    fn_802DBECC();
    fn_802AE728();
    fn_80202718();
    fn_8029790C(0);
    fn_802AE7C0();
}

void fn_802B0218(void) {
    if (fn_802AE7AC() != 0) {
        fn_802DBE4C();
        fn_802B2D94(lbl_8055F978);
        fn_802B4E30();
        fn_802DBECC();
    }
}

#pragma dont_inline fn_802AE7AC
void fn_802B0254(void) {
    if (fn_802AE7AC() != 0) {
        fn_802DBE4C();
        fn_802BDD58();
        fn_802DBECC();
    }
}
void fn_802B0288(void *arg0) {
    if ((void *)lbl_8055F970 != arg0)
        fn_802B4E44(*(int *)((char *)arg0 + 8));
    lbl_8055F970 = (int)arg0;
}

extern void fn_802C10C8(void);
void fn_802B05D8(void) { fn_802C10C8(); }

void* fn_802B05DC(void) {
    return lbl_8055CD78;
}

char fn_802B05E4(void) {
    return lbl_8055F980;
}

extern char lbl_8055F981;
char fn_802B05EC(void) {
    return lbl_8055F981;
}

