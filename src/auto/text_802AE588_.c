#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F980;
extern char lbl_8055F984[4];
extern int lbl_8055F988;
extern float lbl_80564B38;
extern int lbl_804BDFF0[8];
extern int lbl_8055CD7C;
extern int fn_8012850C(int, void *);
extern double fn_8002F234(float, float, float);
extern void *lbl_8055CD78;
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

extern int fn_801E8718(int);
extern int fn_802AEB3C();
void fn_802B0144(void) {
    fn_801E8718(-1);
    fn_802AEB3C();
}

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

