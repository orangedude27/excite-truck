#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055D644;
extern unsigned char lbl_8055D645;
extern int lbl_8055D638;
extern int lbl_8055D63C;
extern int lbl_8055D640;
extern unsigned char lbl_8055D670;
extern int lbl_8055D64C;
extern unsigned int lbl_8055E044;
extern float lbl_805604A8;
extern float lbl_805604AC;
extern float lbl_805604B0;
extern float lbl_805604B4;
extern float lbl_805604B8;
extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);
extern void fn_801345D8(void*, ...);
  extern void fn_8000B3DC(s32);
  extern unsigned char lbl_8055D648;
  extern void fn_80230AD8(void*);
  extern void fn_80230B38(void*);
  extern void fn_80230B5C(void*);
  extern void fn_800209A0(int, float);
void fn_8001FD7C(void);
void fn_8001FF34(int);
struct cfg_t {
    char f0[0xc];
    char f1[0xc];
    char f2[0x10];
    char f3[0x10];
    char f4[0x10];
    char f5[0x10];
    char f6[0x10];
    char f7[0x10];
};
struct lbl_8035BAE4_t {
    int unk_0;
    int unk_4;
    unsigned int unk_8;
};
extern struct lbl_8035BAE4_t lbl_8035BAE4;
extern char lbl_802FE1C0[0x100];
int fn_802E2C20(void);
void fn_80176734(void);
int fn_801312EC(void*, void*);
void fn_80131318(void);
int fn_80232BA4(int, int, int, int, float, float, float, float, float);

#pragma dont_inline on
void fn_8001FD7C(void) {
    struct cfg_t* p = (struct cfg_t*) lbl_802FE138;
    fn_8012E81C(&p->f0[0]);
    lbl_8055D64C = fn_80232578(p->f1);
    lbl_8055D650 = fn_80232578(p->f2);
    lbl_8055D654 = fn_8023512C(p->f3);
    lbl_8055D658 = fn_8023512C(p->f4);
    lbl_80558D78 = fn_802CAC28(p->f5, 0);
    lbl_80558D7C = fn_802CAC28(p->f6, 0);
    lbl_80558D80 = fn_802CAC28(p->f7, 0);
    lbl_80558D84 = fn_802CAC28(&p->f7[0x10], 0);
}
#pragma dont_inline off

void fn_8001FE20(void) {
    lbl_8055D62C = 0;
    fn_802CAC54(lbl_80558D84);
    lbl_80558D84 = -2;
    fn_802CAC54(lbl_80558D80);
    lbl_80558D80 = -2;
    fn_802CAC54(lbl_80558D78);
    lbl_80558D78 = -2;
    fn_802CAC54(lbl_80558D7C);
    lbl_80558D7C = -2;
    fn_802328D4(lbl_8055D64C);
    lbl_8055D64C = 0;
    fn_802328D4(lbl_8055D650);
    lbl_8055D650 = 0;
    fn_80235380(lbl_8055D654);
    lbl_8055D654 = 0;
    fn_80235380(lbl_8055D658);
    lbl_8055D658 = 0;
}

void fn_8001FEB8(void) {
    lbl_8055D645 = 1;
    lbl_8055D640 = fn_802E2C20();
    fn_80176734();
}

void fn_8001FEE8(void) {
    int temp_r3;
    int var_r4;

    temp_r3 = fn_802E2C20();
    var_r4 = 0;
    lbl_8055D63C = temp_r3;
    lbl_8055D638 = temp_r3;
    lbl_8055D640 = var_r4;
    lbl_8055D644 = var_r4 + 1;
    lbl_8055D645 = var_r4;
}

#pragma dont_inline on
void fn_8001FF24(void) {
    lbl_8055D644 = 0;
    lbl_8055D645 = 0;
}
#pragma dont_inline off

extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);

void fn_8001FFD0(int arg0, int arg1, void* arg2, int arg3) {
    switch (arg1) {
        case 0x180201:
            fn_801345D8(arg2, arg3, &lbl_802FE138[0xac], arg0 + 1);
            return;
        case 0x180303:
            fn_801345D8(arg2, arg3, &lbl_802FE138[0x98], arg0 + 1);
            return;
        case 0x180304:
            fn_801345D8(arg2, arg3, &lbl_802FE138[0xc0], arg0 + 1);
            return;
    }
    fn_801345D8(arg2, arg3, &lbl_802FE138[0xd4], arg0 + 1);
}

void fn_8002017C(void) {
    fn_8000B3DC(0);
}

int fn_80020184(void) {
    s32 temp_r3;
    u32 temp_r3_2;

    temp_r3_2 = (((fn_802E2C20() - lbl_8055D63C) - 0x12C) << 8) / 1000;
    temp_r3 = temp_r3_2 & ((s32) (-(s32) temp_r3_2 & ~temp_r3_2) >> 0x1F);
    if (temp_r3 >= 0xFF) {
        temp_r3 = 0xFF;
    }
    return 0xFF - temp_r3;
}

void fn_80020430(void) {
    fn_8001FF24();
}

extern int fn_80020434(void*, float*);
extern int fn_8026A2CC(void*, int, float);
extern int fn_8000C630(int, int);
void fn_800207B0(void) {
    char sp10[0x30];
    float sp8;

    if ((lbl_8055D644 != 0) && (lbl_8055D645 == 0)) {
        fn_802E2C20();
    }
    if ((lbl_8055D644 != 0) && (lbl_8055D645 != 0) && ((fn_801E8838() > 0xF0) || ((fn_802E2C20() - lbl_8055D640) > 0x4B0))) {
        lbl_8055D645 = 0;
        lbl_8055D644 = 0;
    }
    if (lbl_8055D644 != 0) {
        fn_80020434(&sp10, &sp8);
        fn_8026A2CC(&sp10, 0, sp8);
        fn_8000C630(0x15, -1);
    }
}

extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern double lbl_805604E8;
extern float lbl_805604F0;
extern float lbl_805604F4;
extern float lbl_805604F8;
extern float lbl_805604FC;
extern int fn_802354A0(int, int, s32, f32, f32, f32, f32, f32);
void fn_80020860(int arg0) {
    fn_802354A0(lbl_8055D654, 0, (arg0 << 0x18) | 0xFF0000 | 0xFFFF,
                 lbl_805604F8 * (lbl_805604F0 * (f32) lbl_8055CFF0 / lbl_805604F4),
                 lbl_805604FC * (f32) lbl_8055CFF4, lbl_805604B4,
                 lbl_805604F0 * (f32) lbl_8055CFF0 / lbl_805604F4,
                 (f32) lbl_8055CFF4);
}

int fn_800213DC(int arg0) {
    if (!lbl_8055D644) return 0;
    if (lbl_8055D645) return 1;
    if (fn_801E8838()) return 1;
    if (fn_802E4A10()) return 1;
    if (arg0 == 0x58) fn_8001FEB8();
    else if (arg0 == 0x1B) fn_8002017C();
    return 1;
}

void fn_8002167C(void) {
    fn_8001FF24();
}

void fn_80021680(void) {
    fn_80020860(0xFF);
    fn_800209A0(0xFF, lbl_805604B4);
    fn_8001FF34(-1);
}

void __AXDSPInitCallback_800216B8(void) { lbl_8055D62C = 2; }

void fn_800216C4(void) {

}

#pragma push
#pragma inline_depth 0
void fn_800216C8(void) {
    fn_8001FF34(-1);
}
extern int lbl_8055D668, lbl_8055D66C;
extern char *lbl_80558D8C;
extern void fn_8000DA10(void);
extern int fn_8001BA90(int, int, int, int);
extern void fn_8001BA70(int, int, unsigned char *, int);
#pragma dont_inline on
int fn_800216D0(void) {
    int result = 0;
    if (lbl_8055D644) {
        if (!lbl_8055D645) result = 1;
    }
    return result;
}
unsigned char fn_800216F4(void) {
    return lbl_8055D644;
}

int fn_800216FC(void) {
    if (lbl_8055D644 != 0) return fn_80020184();
    return 0;
}

int fn_8002173C(void) {
    int sp8;
    if (lbl_8055D62C != 0) {
        fn_80230B5C(&sp8);
        fn_80230AD8(&sp8);
        switch (lbl_8055D62C) {
            case 2:
                fn_800216C8();
                break;
            case 1:
                fn_80021680();
                break;
        }
        fn_80230B38(NULL);
        return 1;
    }
    return 0;
}

int fn_800217AC(void) {
    if (lbl_8055D648 != 0) {
        return 0;
    }
    if (lbl_8055D644 != 0) {
        if (lbl_8055D645 == 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}

void fn_800218F4(void) {
    fn_8001FD7C();
}

void fn_800218F8(void) {
    fn_8001FE20();
}
void fn_8001FF34(int arg0) {
    unsigned int temp;
    if ((char)lbl_8055D670 == 0) {
        fn_801312EC(&lbl_8035BAE4, &lbl_802FE1C0);
        lbl_8055D670 = 1;
    }
    temp = ((struct lbl_8035BAE4_t*) &lbl_8035BAE4)->unk_8;
    if (temp != lbl_8055E044) {
        fn_80131318();
    }
    fn_80232BA4(lbl_8035BAE4.unk_4, lbl_8055D64C, arg0, 0x12, lbl_805604A8, lbl_805604AC, lbl_805604B0, lbl_805604B4, lbl_805604B8);
}
