// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#define M2C_FIELD(expr, type, offset) (*(type)((unsigned char *)(expr) + (offset)))

#include <math.h>
extern float PSVECDotProduct(void *, void *);
extern void PSVECNormalize(void *, void *);
extern float fn_801E88F0(int);
extern void *fn_80287B24(int);
extern void fn_80294CCC(void *, void *, void *, unsigned int, int, float, float);
extern void *fn_802C86DC(void);
extern float fn_802C88E8(void *);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern char lbl_804B42F0[];
extern float lbl_80564518, lbl_8056452C, lbl_80564538, lbl_8056453C, lbl_80564540;

typedef struct { float x, y, z; } Vec80295;
extern char lbl_80349338[];
extern char lbl_8055C998[8], lbl_8055C9A0[4], lbl_8055C9A4[8], lbl_8055C9AC[4];
extern float lbl_8056451C, lbl_80564520, lbl_80564544;
extern int fn_80288070(int, int, int *);
extern int fn_80287E20(int, int);
extern void *fn_80287E80(int, int);
int fn_80287B14(void);
int fn_802CAC54(int);
extern int lbl_8055C990;
extern int lbl_8055C994;
#pragma scheduling off
void fn_8029496C(void) {}

#pragma scheduling invalid_target
void fn_80294C68(void) {
    int i;
    fn_802CAC54(lbl_8055C990);
    fn_802CAC54(lbl_8055C994);
    lbl_8055C990 = -1;
    i = 0;
    lbl_8055C994 = -1;
    while (i < fn_80287B14()) {
        i++;
    }
}
#pragma scheduling on
void fn_80294CC0(void) {}

void fn_80294CC4(void) {}

void fn_80294ED4(void);
void fn_80294CC8(void) { fn_80294ED4(); }

void fn_80294ED4(void) {
    int spD4[3];
    int spC8[3];
    int spF0;
    float spC4;
    float spC0;
    float spBC;
    float spB8;
    float spB4;
    float spB0;
    float spAC;
    float spA8;
    float spA4;
    float spA0;
    float sp9C;
    float sp98;
    float sp94;
    float sp90;
    float sp8C;
    float sp88;
    float sp84;
    float sp80;
    float sp7C;
    float sp78;
    float sp74;
    float sp70;
    float sp6C;
    float sp68;
    float sp64;
    float sp60;
    float sp5C;
    float sp58;
    float sp54;
    float sp50;
    float sp4C;
    float sp48;
    float sp44;
    float sp40;
    float sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    float sp28;
    float sp24;
    float sp20;
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    float sp8;
    unsigned char *var_r14;
    unsigned char *var_r17;
    unsigned char *var_r18;
    unsigned char *var_r21;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f0_4;
    float temp_f0_5;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f1_5;
    float temp_f25;
    float temp_f26;
    float temp_f26_2;
    float temp_f26_3;
    float temp_f27;
    float temp_f28;
    float temp_f28_2;
    float temp_f29;
    float temp_f29_2;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f30;
    float temp_f30_2;
    float temp_f31;
    float temp_f31_2;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f3_5;
    float temp_f4;
    float temp_f4_2;
    float temp_f5;
    float temp_f5_2;
    float temp_f6;
    float temp_f6_2;
    float temp_f6_3;
    float temp_f6_4;
    float temp_f7;
    float temp_f7_2;
    float temp_f7_3;
    float temp_f7_4;
    float var_f1;
    float var_f1_2;
    int temp_r0;
    int temp_r0_2;
    int temp_r3_4;
    int temp_r3_5;
    int var_r15;
    int var_r15_2;
    int var_r17_2;
    int var_r27;
    int var_r4;
    unsigned char temp_r0_3;
    unsigned char temp_r5;
    unsigned char temp_r7;
    void *temp_r16;
    void *temp_r16_2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_6;
    void *temp_r3_7;

    temp_f27 = lbl_80564538;
    temp_r3 = fn_802C86DC();
    spD4[0] = M2C_FIELD(temp_r3, int *, 0);
    spD4[1] = M2C_FIELD(temp_r3, int *, 4);
    spD4[2] = M2C_FIELD(temp_r3, int *, 8);
    spC8[0] = M2C_FIELD(temp_r3, int *, 0xC);
    spC8[1] = M2C_FIELD(temp_r3, int *, 0x10);
    spC8[2] = M2C_FIELD(temp_r3, int *, 0x14);
    fn_802C8BD0(lbl_8055C990);
    temp_f29 = lbl_80564518;
    temp_f30 = lbl_8056451C;
    temp_f31 = lbl_80564540;
    var_r18 = (unsigned char *) lbl_804B42F0;
    temp_f25 = lbl_8056452C;
    temp_f28 = lbl_8056453C;
    spF0 = 0;
loop_40:
    if (1) {
        temp_r16 = fn_80287B24(spF0);
        temp_f26 = fn_801E88F0(-1);
        if (!((fn_802C88E8((unsigned char *) temp_r16 + 0x24) * temp_f26) > temp_f27) && !(M2C_FIELD(temp_r16, int *, 0x68) & 8)) {
            var_r15 = 0;
            if ((int) M2C_FIELD(var_r18, int *, 0x180) > 0) {
                var_r17 = var_r18;
loop_38:
                if (1) {
                    temp_r3_2 = M2C_FIELD(var_r17, void **, 0);
                    temp_r3_3 = (unsigned char *) temp_r3_2 + 0x24;
                    if (&spBC == temp_r3_3) {
                        temp_f6 = M2C_FIELD(temp_r3_3, float *, 4);
                        temp_f0 = M2C_FIELD(temp_r3_2, float *, 0x24);
                        temp_f7 = M2C_FIELD(temp_r3_3, float *, 8);
                        spBC = (temp_f7 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f0 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f6 * M2C_FIELD(temp_r16, float *, 0xC)));
                        spC0 = (temp_f7 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f0 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f6 * M2C_FIELD(temp_r16, float *, 0x10)));
                        spC4 = (temp_f7 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f0 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f6 * M2C_FIELD(temp_r16, float *, 0x14)));
                    } else {
                        spBC = (M2C_FIELD(temp_r3_3, float *, 8) * M2C_FIELD(temp_r16, float *, 0x18)) + ((M2C_FIELD(temp_r3_2, float *, 0x24) * M2C_FIELD(temp_r16, float *, 0)) + (M2C_FIELD(temp_r3_3, float *, 4) * M2C_FIELD(temp_r16, float *, 0xC)));
                        spC0 = (M2C_FIELD(temp_r3_3, float *, 8) * M2C_FIELD(temp_r16, float *, 0x1C)) + ((M2C_FIELD(temp_r3_2, float *, 0x24) * M2C_FIELD(temp_r16, float *, 4)) + (M2C_FIELD(temp_r3_3, float *, 4) * M2C_FIELD(temp_r16, float *, 0x10)));
                        spC4 = (M2C_FIELD(temp_r3_3, float *, 8) * M2C_FIELD(temp_r16, float *, 0x20)) + ((M2C_FIELD(temp_r3_2, float *, 0x24) * M2C_FIELD(temp_r16, float *, 8)) + (M2C_FIELD(temp_r3_3, float *, 4) * M2C_FIELD(temp_r16, float *, 0x14)));
                    }
                    temp_f3 = spBC + M2C_FIELD(temp_r16, float *, 0x24);
                    spBC = temp_f3;
                    temp_f2 = spC0 + M2C_FIELD(temp_r16, float *, 0x28);
                    spC0 = temp_f2;
                    temp_f1 = spC4 + M2C_FIELD(temp_r16, float *, 0x2C);
                    spC4 = temp_f1;
                    spB0 = temp_f3 - M2C_FIELD(temp_r3, float *, 0x24);
                    spB4 = temp_f2 - M2C_FIELD(temp_r3, float *, 0x28);
                    spB8 = temp_f1 - M2C_FIELD(temp_r3, float *, 0x2C);
                    if (PSVECDotProduct(&spB0, &spB0) > temp_f28) {
                        PSVECNormalize(&spB0, &spB0);
                        if (&spA4 == (void *) (var_r17 + 4)) {
                            temp_f6_2 = M2C_FIELD(var_r17, float *, 8);
                            temp_f0_2 = M2C_FIELD(var_r17, float *, 4);
                            temp_f7_2 = M2C_FIELD(var_r17, float *, 0xC);
                            spA4 = (temp_f7_2 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f0_2 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f6_2 * M2C_FIELD(temp_r16, float *, 0xC)));
                            spA8 = (temp_f7_2 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f0_2 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f6_2 * M2C_FIELD(temp_r16, float *, 0x10)));
                            spAC = (temp_f7_2 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f0_2 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f6_2 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            temp_f4 = M2C_FIELD(var_r17, float *, 8);
                            temp_f3_2 = M2C_FIELD(var_r17, float *, 4);
                            temp_f5 = M2C_FIELD(var_r17, float *, 0xC);
                            spA4 = (temp_f5 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f3_2 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f4 * M2C_FIELD(temp_r16, float *, 0xC)));
                            spA8 = (temp_f5 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f3_2 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f4 * M2C_FIELD(temp_r16, float *, 0x10)));
                            spAC = (temp_f5 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f3_2 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f4 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        var_f1 = PSVECDotProduct(&spB0, &spA4);
                        if (temp_f29 < var_f1) {
                            var_f1 = temp_f29;
                        }
                        if (var_f1 > temp_f30) {

                        } else {
                            var_f1 = temp_f30;
                        }
                        temp_f26_2 = temp_f29 - var_f1;
                        sp38 = temp_f30;
                        sp3C = temp_f30;
                        sp40 = temp_f29;
                        if (&sp98 == &sp38) {
                            sp98 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp9C = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            spA0 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp98 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp9C = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            spA0 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        sp2C = temp_f29;
                        sp30 = temp_f30;
                        sp34 = temp_f30;
                        if (&sp8C == &sp2C) {
                            sp8C = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp90 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp94 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp8C = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp90 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp94 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        var_r27 = 0xFF;
                        temp_r3_4 = (int) (temp_f31 * (float) fabs(PSVECDotProduct(&spB0, &sp98)));
                        temp_r0 = temp_r3_4 & ((int) (-temp_r3_4 & ~temp_r3_4) >> 0x1F);
                        if (temp_r0 < 0xFF) {
                            var_r27 = temp_r0;
                        }
                        var_r4 = 0xFF;
                        temp_r3_5 = (int) (temp_f31 * (float) fabs(PSVECDotProduct(&spB0, &sp8C)));
                        temp_r0_2 = temp_r3_5 & ((int) (-temp_r3_5 & ~temp_r3_5) >> 0x1F);
                        if (temp_r0_2 < 0xFF) {
                            var_r4 = temp_r0_2;
                        }
                        temp_r5 = M2C_FIELD(var_r17, unsigned char *, 0x18);
                        temp_r0_3 = M2C_FIELD(var_r17, unsigned char *, 0x19);
                        temp_r7 = M2C_FIELD(var_r17, unsigned char *, 0x1A);
                        sp20 = temp_f29;
                        sp24 = temp_f30;
                        sp28 = temp_f30;
                        if (&sp80 == &sp20) {
                            sp80 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp84 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp88 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp80 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp84 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp88 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        sp14 = temp_f30;
                        sp18 = temp_f30;
                        sp1C = temp_f29;
                        if (&sp68 == &sp14) {
                            sp68 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp6C = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp70 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp68 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp6C = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp70 = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        sp8 = temp_f30;
                        spC = temp_f29;
                        sp10 = temp_f30;
                        if (&sp74 == &sp8) {
                            sp74 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp78 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp7C = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp74 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp78 = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp7C = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        temp_f1_2 = M2C_FIELD(var_r17, float *, 0x14);
                        temp_f2_2 = temp_f26_2 * temp_f1_2;
                        fn_80294CCC(&spBC, &sp80, &sp74, ((temp_r7 | (((temp_r5 << 0x10) & ~0xFF00) | ((temp_r0_3 << 8) & 0xFF00))) & ~0xFF000000) | (var_r27 << 0x18), M2C_FIELD(var_r17, int *, 0x1C), (temp_f1_2 + temp_f2_2) * temp_f25, (M2C_FIELD(var_r17, float *, 0x10) + temp_f2_2) * temp_f25);
                        temp_f1_3 = M2C_FIELD(var_r17, float *, 0x14);
                        temp_f2_3 = temp_f26_2 * temp_f1_3;
                        fn_80294CCC(&spBC, &sp68, &sp74, ((temp_r7 | (((temp_r0_3 << 8) & ~0xFF0000) | ((temp_r5 << 0x10) & 0xFF0000))) & ~0xFF000000) | (var_r4 << 0x18), M2C_FIELD(var_r17, int *, 0x1C), (temp_f1_3 + temp_f2_3) * temp_f25, (M2C_FIELD(var_r17, float *, 0x10) + temp_f2_3) * temp_f25);
                    }
                    var_r17 += 0x20;
                    var_r15 += 1;
                    if (var_r15 < (int) M2C_FIELD(var_r18, int *, 0x180)) goto loop_38;
                }
            }
        }
        var_r18 += 0x184;
        spF0 += 1;
        if (spF0 < fn_80287B14()) goto loop_40;
    }
    fn_802C8D74();
    fn_802C8BD0(lbl_8055C994);
    temp_f29_2 = lbl_80564518;
    temp_f28_2 = lbl_8056451C;
    var_r14 = (unsigned char *) lbl_804B42F0;
    temp_f26_3 = lbl_8056452C;
    temp_f31_2 = lbl_8056453C;
    var_r15_2 = 0;
loop_62:
    if (1) {
        temp_r16_2 = fn_80287B24(var_r15_2);
        temp_f30_2 = fn_801E88F0(-1);
        if (!((fn_802C88E8((unsigned char *) temp_r16_2 + 0x24) * temp_f30_2) > temp_f27) && !(M2C_FIELD(temp_r16_2, int *, 0x68) & 8)) {
            var_r17_2 = 0;
            if ((int) M2C_FIELD(var_r14, int *, 0x180) > 0) {
                var_r21 = var_r14;
loop_60:
                if (1) {
                    temp_r3_6 = M2C_FIELD(var_r21, void **, 0);
                    temp_r3_7 = (unsigned char *) temp_r3_6 + 0x24;
                    if (&sp5C == temp_r3_7) {
                        temp_f6_3 = M2C_FIELD(temp_r3_7, float *, 4);
                        temp_f0_3 = M2C_FIELD(temp_r3_6, float *, 0x24);
                        temp_f7_3 = M2C_FIELD(temp_r3_7, float *, 8);
                        sp5C = (temp_f7_3 * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((temp_f0_3 * M2C_FIELD(temp_r16_2, float *, 0)) + (temp_f6_3 * M2C_FIELD(temp_r16_2, float *, 0xC)));
                        sp60 = (temp_f7_3 * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((temp_f0_3 * M2C_FIELD(temp_r16_2, float *, 4)) + (temp_f6_3 * M2C_FIELD(temp_r16_2, float *, 0x10)));
                        sp64 = (temp_f7_3 * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((temp_f0_3 * M2C_FIELD(temp_r16_2, float *, 8)) + (temp_f6_3 * M2C_FIELD(temp_r16_2, float *, 0x14)));
                    } else {
                        sp5C = (M2C_FIELD(temp_r3_7, float *, 8) * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((M2C_FIELD(temp_r3_6, float *, 0x24) * M2C_FIELD(temp_r16_2, float *, 0)) + (M2C_FIELD(temp_r3_7, float *, 4) * M2C_FIELD(temp_r16_2, float *, 0xC)));
                        sp60 = (M2C_FIELD(temp_r3_7, float *, 8) * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((M2C_FIELD(temp_r3_6, float *, 0x24) * M2C_FIELD(temp_r16_2, float *, 4)) + (M2C_FIELD(temp_r3_7, float *, 4) * M2C_FIELD(temp_r16_2, float *, 0x10)));
                        sp64 = (M2C_FIELD(temp_r3_7, float *, 8) * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((M2C_FIELD(temp_r3_6, float *, 0x24) * M2C_FIELD(temp_r16_2, float *, 8)) + (M2C_FIELD(temp_r3_7, float *, 4) * M2C_FIELD(temp_r16_2, float *, 0x14)));
                    }
                    temp_f3_3 = sp5C + M2C_FIELD(temp_r16_2, float *, 0x24);
                    sp5C = temp_f3_3;
                    temp_f2_4 = sp60 + M2C_FIELD(temp_r16_2, float *, 0x28);
                    sp60 = temp_f2_4;
                    temp_f1_4 = sp64 + M2C_FIELD(temp_r16_2, float *, 0x2C);
                    sp64 = temp_f1_4;
                    sp50 = temp_f3_3 - M2C_FIELD(temp_r3, float *, 0x24);
                    sp54 = temp_f2_4 - M2C_FIELD(temp_r3, float *, 0x28);
                    sp58 = temp_f1_4 - M2C_FIELD(temp_r3, float *, 0x2C);
                    if (PSVECDotProduct(&sp50, &sp50) > temp_f31_2) {
                        PSVECNormalize(&sp50, &sp50);
                        if (&sp44 == (void *) (var_r21 + 4)) {
                            temp_f6_4 = M2C_FIELD(var_r21, float *, 8);
                            temp_f0_4 = M2C_FIELD(var_r21, float *, 4);
                            temp_f7_4 = M2C_FIELD(var_r21, float *, 0xC);
                            sp44 = (temp_f7_4 * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((temp_f0_4 * M2C_FIELD(temp_r16_2, float *, 0)) + (temp_f6_4 * M2C_FIELD(temp_r16_2, float *, 0xC)));
                            sp48 = (temp_f7_4 * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((temp_f0_4 * M2C_FIELD(temp_r16_2, float *, 4)) + (temp_f6_4 * M2C_FIELD(temp_r16_2, float *, 0x10)));
                            sp4C = (temp_f7_4 * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((temp_f0_4 * M2C_FIELD(temp_r16_2, float *, 8)) + (temp_f6_4 * M2C_FIELD(temp_r16_2, float *, 0x14)));
                        } else {
                            temp_f4_2 = M2C_FIELD(var_r21, float *, 8);
                            temp_f3_4 = M2C_FIELD(var_r21, float *, 4);
                            temp_f5_2 = M2C_FIELD(var_r21, float *, 0xC);
                            sp44 = (temp_f5_2 * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((temp_f3_4 * M2C_FIELD(temp_r16_2, float *, 0)) + (temp_f4_2 * M2C_FIELD(temp_r16_2, float *, 0xC)));
                            sp48 = (temp_f5_2 * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((temp_f3_4 * M2C_FIELD(temp_r16_2, float *, 4)) + (temp_f4_2 * M2C_FIELD(temp_r16_2, float *, 0x10)));
                            sp4C = (temp_f5_2 * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((temp_f3_4 * M2C_FIELD(temp_r16_2, float *, 8)) + (temp_f4_2 * M2C_FIELD(temp_r16_2, float *, 0x14)));
                        }
                        var_f1_2 = PSVECDotProduct(&sp50, &sp44);
                        if (temp_f29_2 < var_f1_2) {
                            var_f1_2 = temp_f29_2;
                        }
                        if (var_f1_2 > temp_f28_2) {

                        } else {
                            var_f1_2 = temp_f28_2;
                        }
                        temp_f0_5 = temp_f29_2 - var_f1_2;
                        temp_f3_5 = M2C_FIELD(var_r21, float *, 0x14);
                        temp_f1_5 = M2C_FIELD(var_r21, float *, 0x10);
                        fn_80294CCC(&sp5C, spD4, spC8, M2C_FIELD(var_r21, unsigned char *, 0x1A) | ((((M2C_FIELD(var_r21, unsigned char *, 0x18) << 0x10) | 0x80000000) & ~0xFF00) | ((M2C_FIELD(var_r21, unsigned char *, 0x19) << 8) & 0xFF00)), -1, (temp_f3_5 + (temp_f0_5 * temp_f3_5)) * temp_f26_3, (temp_f1_5 + (temp_f0_5 * temp_f1_5)) * temp_f26_3);
                    }
                    var_r21 += 0x20;
                    var_r17_2 += 1;
                    if (var_r17_2 < (int) M2C_FIELD(var_r14, int *, 0x180)) goto loop_60;
                }
            }
        }
        var_r14 += 0x184;
        var_r15_2 += 1;
        if (var_r15_2 < fn_80287B14()) goto loop_62;
    }
    fn_802C8D74();
}

void fn_80295C70(void *arg0, int arg1, float *arg2, unsigned int arg3, int arg4, float farg0, float farg1) {
    struct Entry { int value; float a,b,c,d,e; unsigned char flags[3]; int tail; };
    struct Obj { unsigned char pad[0x180]; int count; };
    struct Obj *obj = arg0;
    struct Entry *entry = (struct Entry *)((char *)obj + (obj->count << 5));
    entry->value = arg1;
    entry->a = arg2[0];
    entry->b = arg2[1];
    entry->c = arg2[2];
    entry->d = farg1;
    entry->e = farg0;
    entry->flags[0] = arg3 >> 16;
    entry->flags[1] = arg3 >> 8;
    entry->flags[2] = arg3;
    entry->tail = arg4;
    obj->count++;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling on
void fn_80295CC4(void *self, int a, int b, Vec80295 *input, int unused, float *pos, float size) {
    Vec80295 col;
    int id;
    unsigned int packed;
    int extra;
    float base, sx, sy;
    void *obj;
    col = *input;
    if (fn_80288070(a,b,&id)) {
        if (fn_80287E20(a,b)) {
            Vec80295 result, def;
            obj = fn_80287E80(a,b);
            def = col;
            result = ((Vec80295 (*)(void *, char *, Vec80295 *))(*(int **)obj)[14])(obj,lbl_8055C998,&def);
            {
 unsigned int r,g,b;
 int t;
 t=(int)(lbl_80564544*result.z); t=t>0?t:0; b=(unsigned char)(t<255?t:255);
 t=(int)(lbl_80564544*result.y); t=t>0?t:0; g=(unsigned char)(t<255?t:255)<<8;
 t=(int)(lbl_80564544*result.x); t=t>0?t:0;
 r=(unsigned char)(t<255?t:255)<<16;
 packed=b | g | r | 0xFF000000U;
}
            base = ((float (*)(void *, char *, float))(*(int **)obj)[10])(obj,lbl_8055C9A0,size);
            sx = ((float (*)(void *, char *, float))(*(int **)obj)[10])(obj,lbl_8055C9A4,lbl_80564520);
            sy = ((float (*)(void *, char *, float))(*(int **)obj)[10])(obj,lbl_8055C9AC,lbl_80564520);
            if (sx <= lbl_8056451C || sy <= lbl_8056451C) { sy=base; sx=base; }
            extra = ((int (*)(void *, char *, int))(*(int **)obj)[8])(obj,lbl_80349338,0);
        } else {
            {
 unsigned int r,g,b;
 int t;
 t=(int)(lbl_80564544*col.z); t=t>0?t:0; b=(unsigned char)(t<255?t:255);
 t=(int)(lbl_80564544*col.y); t=t>0?t:0; g=(unsigned char)(t<255?t:255)<<8;
 t=(int)(lbl_80564544*col.x)>0?(int)(lbl_80564544*col.x):0;
 r=(unsigned char)(t<255?t:255)<<16;
 packed=b | g | r | 0xFF000000U;
}
            sx=size; sy=size; extra=0;
        }
        fn_80295C70(self,id,pos,packed,extra,sx,sy);
    }
}
#pragma pop

#pragma scheduling on
