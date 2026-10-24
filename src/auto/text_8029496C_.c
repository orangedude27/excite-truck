// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#define M2C_FIELD(expr, type, offset) (*(type)((unsigned char *)(expr) + (offset)))

typedef struct { float x, y, z; } Vec80295;

#include <math.h>
extern float PSVECDotProduct(const Vec80295 *, const Vec80295 *);
extern void PSVECNormalize(const Vec80295 *, Vec80295 *);
extern float fn_801E88F0(int);
extern void *fn_80287B24(int);
extern void fn_80294CCC(const Vec80295 *, const Vec80295 *, const Vec80295 *, unsigned int, int, float, float);
extern void *fn_802C86DC(void);
extern float fn_802C88E8(void *);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern char lbl_804B42F0[];
extern float lbl_80564518, lbl_8056452C, lbl_80564538, lbl_8056453C, lbl_80564540;
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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80294ED4(void) {
    Vec80295 sp8;
    Vec80295 sp14;
    Vec80295 sp20;
    Vec80295 sp2C;
    Vec80295 sp38;
    Vec80295 sp44;
    Vec80295 sp50;
    Vec80295 sp5C;
    Vec80295 sp68;
    Vec80295 sp74;
    Vec80295 sp80;
    Vec80295 sp8C;
    Vec80295 sp98;
    Vec80295 spA4;
    Vec80295 spB0;
    Vec80295 spBC;
    Vec80295 spC8;
    Vec80295 spD4;

    Vec80295 *ptr_sp74;
    Vec80295 *ptr_sp14;
    Vec80295 *ptr_sp68;
    Vec80295 *ptr_sp20;
    Vec80295 *ptr_sp80;
    Vec80295 *ptr_sp2C;
    Vec80295 *ptr_sp8C;
    Vec80295 *ptr_sp38;
    Vec80295 *ptr_sp98;
    Vec80295 *ptr_spA4;
    Vec80295 *ptr_spBC;

    int spF0;

    unsigned char *var_r14;
    unsigned char *var_r17;
    unsigned char *var_r18;
    unsigned char *var_r21;
    float temp_f31;
    float temp_f30;
    float temp_f29;
    float temp_f28;
    float temp_f27;
    float temp_f26;
    float temp_f25;
    float temp_f31_2;
    float temp_f30_2;
    float temp_f29_2;
    float temp_f28_2;
    float temp_f26_3;
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
    float temp_f26_2;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
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
    spD4 = *(Vec80295 *) temp_r3;
    spC8 = *(Vec80295 *) ((unsigned char *) temp_r3 + 0xC);
    fn_802C8BD0(lbl_8055C990);
    temp_f29 = lbl_80564518;
    temp_f30 = lbl_8056451C;
    temp_f31 = lbl_80564540;
    var_r18 = (unsigned char *) lbl_804B42F0;
    temp_f25 = lbl_8056452C;
    temp_f28 = lbl_8056453C;
    ptr_sp74 = &sp74;
    ptr_sp14 = &sp14;
    ptr_sp68 = &sp68;
    ptr_sp20 = &sp20;
    ptr_sp80 = &sp80;
    ptr_sp2C = &sp2C;
    ptr_sp8C = &sp8C;
    ptr_sp38 = &sp38;
    ptr_sp98 = &sp98;
    ptr_spA4 = &spA4;
    ptr_spBC = &spBC;
    spF0 = 0;
    do {
        temp_r16 = fn_80287B24(spF0);
        temp_f26 = fn_801E88F0(-1);
        if (!((fn_802C88E8((unsigned char *) temp_r16 + 0x24) * temp_f26) > temp_f27) && !(M2C_FIELD(temp_r16, int *, 0x68) & 8)) {
            var_r15 = 0;
            if ((int) M2C_FIELD(var_r18, int *, 0x180) > 0) {
                var_r17 = var_r18;
                do {
                    temp_r3_2 = M2C_FIELD(var_r17, void **, 0);
                    temp_r3_3 = (unsigned char *) temp_r3_2 + 0x24;
                    if (ptr_spBC == temp_r3_3) {
                        temp_f6 = M2C_FIELD(temp_r3_3, float *, 4);
                        temp_f0 = M2C_FIELD(temp_r3_2, float *, 0x24);
                        temp_f7 = M2C_FIELD(temp_r3_3, float *, 8);
                        spBC.x = (temp_f7 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f0 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f6 * M2C_FIELD(temp_r16, float *, 0xC)));
                        spBC.y = (temp_f7 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f0 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f6 * M2C_FIELD(temp_r16, float *, 0x10)));
                        spBC.z = (temp_f7 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f0 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f6 * M2C_FIELD(temp_r16, float *, 0x14)));
                    } else {
                        spBC.x = (M2C_FIELD(temp_r3_3, float *, 8) * M2C_FIELD(temp_r16, float *, 0x18)) + ((M2C_FIELD(temp_r3_2, float *, 0x24) * M2C_FIELD(temp_r16, float *, 0)) + (M2C_FIELD(temp_r3_3, float *, 4) * M2C_FIELD(temp_r16, float *, 0xC)));
                        spBC.y = (M2C_FIELD(temp_r3_3, float *, 8) * M2C_FIELD(temp_r16, float *, 0x1C)) + ((M2C_FIELD(temp_r3_2, float *, 0x24) * M2C_FIELD(temp_r16, float *, 4)) + (M2C_FIELD(temp_r3_3, float *, 4) * M2C_FIELD(temp_r16, float *, 0x10)));
                        spBC.z = (M2C_FIELD(temp_r3_3, float *, 8) * M2C_FIELD(temp_r16, float *, 0x20)) + ((M2C_FIELD(temp_r3_2, float *, 0x24) * M2C_FIELD(temp_r16, float *, 8)) + (M2C_FIELD(temp_r3_3, float *, 4) * M2C_FIELD(temp_r16, float *, 0x14)));
                    }
                    temp_f3 = spBC.x + M2C_FIELD(temp_r16, float *, 0x24);
                    spBC.x = temp_f3;
                    temp_f2 = spBC.y + M2C_FIELD(temp_r16, float *, 0x28);
                    spBC.y = temp_f2;
                    temp_f1 = spBC.z + M2C_FIELD(temp_r16, float *, 0x2C);
                    spBC.z = temp_f1;
                    spB0.x = temp_f3 - M2C_FIELD(temp_r3, float *, 0x24);
                    spB0.y = temp_f2 - M2C_FIELD(temp_r3, float *, 0x28);
                    spB0.z = temp_f1 - M2C_FIELD(temp_r3, float *, 0x2C);
                    if (PSVECDotProduct(&spB0, &spB0) > temp_f28) {
                        PSVECNormalize(&spB0, &spB0);
                        if (ptr_spA4 == (void *) (var_r17 + 4)) {
                            temp_f6_2 = M2C_FIELD(var_r17, float *, 8);
                            temp_f0_2 = M2C_FIELD(var_r17, float *, 4);
                            temp_f7_2 = M2C_FIELD(var_r17, float *, 0xC);
                            spA4.x = (temp_f7_2 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f0_2 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f6_2 * M2C_FIELD(temp_r16, float *, 0xC)));
                            spA4.y = (temp_f7_2 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f0_2 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f6_2 * M2C_FIELD(temp_r16, float *, 0x10)));
                            spA4.z = (temp_f7_2 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f0_2 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f6_2 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            temp_f4 = M2C_FIELD(var_r17, float *, 8);
                            temp_f3_2 = M2C_FIELD(var_r17, float *, 4);
                            temp_f5 = M2C_FIELD(var_r17, float *, 0xC);
                            spA4.x = (temp_f5 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f3_2 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f4 * M2C_FIELD(temp_r16, float *, 0xC)));
                            spA4.y = (temp_f5 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f3_2 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f4 * M2C_FIELD(temp_r16, float *, 0x10)));
                            spA4.z = (temp_f5 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f3_2 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f4 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        var_f1 = PSVECDotProduct(&spB0, ptr_spA4);
                        if (temp_f29 < var_f1) {
                            var_f1 = temp_f29;
                        }
                        if (var_f1 > temp_f30) {

                        } else {
                            var_f1 = temp_f30;
                        }
                        temp_f26_2 = temp_f29 - var_f1;
                        sp38.x = temp_f30;
                        sp38.y = temp_f30;
                        sp38.z = temp_f29;
                        if (ptr_sp98 == ptr_sp38) {
                            sp98.x = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp98.y = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp98.z = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp98.x = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp98.y = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp98.z = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        sp2C.x = temp_f29;
                        sp2C.y = temp_f30;
                        sp2C.z = temp_f30;
                        if (ptr_sp8C == ptr_sp2C) {
                            sp8C.x = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp8C.y = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp8C.z = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp8C.x = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp8C.y = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp8C.z = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        var_r27 = 0xFF;
                        temp_r3_4 = (int) (temp_f31 * (float) fabs(PSVECDotProduct(&spB0, ptr_sp98)));
                        temp_r0 = temp_r3_4 & ((int) (-temp_r3_4 & ~temp_r3_4) >> 0x1F);
                        if (temp_r0 < 0xFF) {
                            var_r27 = temp_r0;
                        }
                        var_r4 = 0xFF;
                        temp_r3_5 = (int) (temp_f31 * (float) fabs(PSVECDotProduct(&spB0, ptr_sp8C)));
                        temp_r0_2 = temp_r3_5 & ((int) (-temp_r3_5 & ~temp_r3_5) >> 0x1F);
                        if (temp_r0_2 < 0xFF) {
                            var_r4 = temp_r0_2;
                        }
                        temp_r5 = M2C_FIELD(var_r17, unsigned char *, 0x18);
                        temp_r0_3 = M2C_FIELD(var_r17, unsigned char *, 0x19);
                        temp_r7 = M2C_FIELD(var_r17, unsigned char *, 0x1A);
                        sp20.x = temp_f29;
                        sp20.y = temp_f30;
                        sp20.z = temp_f30;
                        if (ptr_sp80 == ptr_sp20) {
                            sp80.x = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp80.y = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp80.z = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp80.x = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp80.y = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp80.z = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f29 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        sp14.x = temp_f30;
                        sp14.y = temp_f30;
                        sp14.z = temp_f29;
                        if (ptr_sp68 == ptr_sp14) {
                            sp68.x = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp68.y = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp68.z = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp68.x = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp68.y = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp68.z = (temp_f29 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f30 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        sp8.x = temp_f30;
                        sp8.y = temp_f29;
                        sp8.z = temp_f30;
                        if (ptr_sp74 == &sp8) {
                            sp74.x = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp74.y = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp74.z = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x14)));
                        } else {
                            sp74.x = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x18)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 0)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0xC)));
                            sp74.y = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x1C)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 4)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x10)));
                            sp74.z = (temp_f30 * M2C_FIELD(temp_r16, float *, 0x20)) + ((temp_f30 * M2C_FIELD(temp_r16, float *, 8)) + (temp_f29 * M2C_FIELD(temp_r16, float *, 0x14)));
                        }
                        temp_f1_2 = M2C_FIELD(var_r17, float *, 0x14);
                        temp_f2_2 = temp_f26_2 * temp_f1_2;
                        fn_80294CCC(ptr_spBC, ptr_sp80, ptr_sp74, ((temp_r7 | (((temp_r5 << 0x10) & ~0xFF00) | ((temp_r0_3 << 8) & 0xFF00))) & ~0xFF000000) | (var_r27 << 0x18), M2C_FIELD(var_r17, int *, 0x1C), (temp_f1_2 + temp_f2_2) * temp_f25, (M2C_FIELD(var_r17, float *, 0x10) + temp_f2_2) * temp_f25);
                        temp_f1_3 = M2C_FIELD(var_r17, float *, 0x14);
                        temp_f2_3 = temp_f26_2 * temp_f1_3;
                        fn_80294CCC(ptr_spBC, ptr_sp68, ptr_sp74, ((temp_r7 | (((temp_r0_3 << 8) & ~0xFF0000) | ((temp_r5 << 0x10) & 0xFF0000))) & ~0xFF000000) | (var_r4 << 0x18), M2C_FIELD(var_r17, int *, 0x1C), (temp_f1_3 + temp_f2_3) * temp_f25, (M2C_FIELD(var_r17, float *, 0x10) + temp_f2_3) * temp_f25);
                    }
                    var_r17 += 0x20;
                    var_r15 += 1;
                    } while (var_r15 < (int) M2C_FIELD(var_r18, int *, 0x180));
            }
        }
        var_r18 += 0x184;
        spF0 += 1;
        } while (spF0 < fn_80287B14());
    fn_802C8D74();
    fn_802C8BD0(lbl_8055C994);
    temp_f29_2 = lbl_80564518;
    temp_f28_2 = lbl_8056451C;
    var_r14 = (unsigned char *) lbl_804B42F0;
    temp_f26_3 = lbl_8056452C;
    temp_f31_2 = lbl_8056453C;
    var_r15_2 = 0;
    do {
        temp_r16_2 = fn_80287B24(var_r15_2);
        temp_f30_2 = fn_801E88F0(-1);
        if (!((fn_802C88E8((unsigned char *) temp_r16_2 + 0x24) * temp_f30_2) > temp_f27) && !(M2C_FIELD(temp_r16_2, int *, 0x68) & 8)) {
            var_r17_2 = 0;
            if ((int) M2C_FIELD(var_r14, int *, 0x180) > 0) {
                var_r21 = var_r14;
                do {
                    temp_r3_6 = M2C_FIELD(var_r21, void **, 0);
                    temp_r3_7 = (unsigned char *) temp_r3_6 + 0x24;
                    if (&sp5C.x == temp_r3_7) {
                        temp_f6_3 = M2C_FIELD(temp_r3_7, float *, 4);
                        temp_f0_3 = M2C_FIELD(temp_r3_6, float *, 0x24);
                        temp_f7_3 = M2C_FIELD(temp_r3_7, float *, 8);
                        sp5C.x = (temp_f7_3 * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((temp_f0_3 * M2C_FIELD(temp_r16_2, float *, 0)) + (temp_f6_3 * M2C_FIELD(temp_r16_2, float *, 0xC)));
                        sp5C.y = (temp_f7_3 * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((temp_f0_3 * M2C_FIELD(temp_r16_2, float *, 4)) + (temp_f6_3 * M2C_FIELD(temp_r16_2, float *, 0x10)));
                        sp5C.z = (temp_f7_3 * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((temp_f0_3 * M2C_FIELD(temp_r16_2, float *, 8)) + (temp_f6_3 * M2C_FIELD(temp_r16_2, float *, 0x14)));
                    } else {
                        sp5C.x = (M2C_FIELD(temp_r3_7, float *, 8) * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((M2C_FIELD(temp_r3_6, float *, 0x24) * M2C_FIELD(temp_r16_2, float *, 0)) + (M2C_FIELD(temp_r3_7, float *, 4) * M2C_FIELD(temp_r16_2, float *, 0xC)));
                        sp5C.y = (M2C_FIELD(temp_r3_7, float *, 8) * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((M2C_FIELD(temp_r3_6, float *, 0x24) * M2C_FIELD(temp_r16_2, float *, 4)) + (M2C_FIELD(temp_r3_7, float *, 4) * M2C_FIELD(temp_r16_2, float *, 0x10)));
                        sp5C.z = (M2C_FIELD(temp_r3_7, float *, 8) * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((M2C_FIELD(temp_r3_6, float *, 0x24) * M2C_FIELD(temp_r16_2, float *, 8)) + (M2C_FIELD(temp_r3_7, float *, 4) * M2C_FIELD(temp_r16_2, float *, 0x14)));
                    }
                    temp_f3_3 = sp5C.x + M2C_FIELD(temp_r16_2, float *, 0x24);
                    sp5C.x = temp_f3_3;
                    temp_f2_4 = sp5C.y + M2C_FIELD(temp_r16_2, float *, 0x28);
                    sp5C.y = temp_f2_4;
                    temp_f1_4 = sp5C.z + M2C_FIELD(temp_r16_2, float *, 0x2C);
                    sp5C.z = temp_f1_4;
                    sp50.x = temp_f3_3 - M2C_FIELD(temp_r3, float *, 0x24);
                    sp50.y = temp_f2_4 - M2C_FIELD(temp_r3, float *, 0x28);
                    sp50.z = temp_f1_4 - M2C_FIELD(temp_r3, float *, 0x2C);
                    if (PSVECDotProduct(&sp50, &sp50) > temp_f31_2) {
                        PSVECNormalize(&sp50, &sp50);
                        if (&sp44.x == (void *) (var_r21 + 4)) {
                            temp_f6_4 = M2C_FIELD(var_r21, float *, 8);
                            temp_f0_4 = M2C_FIELD(var_r21, float *, 4);
                            temp_f7_4 = M2C_FIELD(var_r21, float *, 0xC);
                            sp44.x = (temp_f7_4 * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((temp_f0_4 * M2C_FIELD(temp_r16_2, float *, 0)) + (temp_f6_4 * M2C_FIELD(temp_r16_2, float *, 0xC)));
                            sp44.y = (temp_f7_4 * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((temp_f0_4 * M2C_FIELD(temp_r16_2, float *, 4)) + (temp_f6_4 * M2C_FIELD(temp_r16_2, float *, 0x10)));
                            sp44.z = (temp_f7_4 * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((temp_f0_4 * M2C_FIELD(temp_r16_2, float *, 8)) + (temp_f6_4 * M2C_FIELD(temp_r16_2, float *, 0x14)));
                        } else {
                            temp_f4_2 = M2C_FIELD(var_r21, float *, 8);
                            temp_f3_4 = M2C_FIELD(var_r21, float *, 4);
                            temp_f5_2 = M2C_FIELD(var_r21, float *, 0xC);
                            sp44.x = (temp_f5_2 * M2C_FIELD(temp_r16_2, float *, 0x18)) + ((temp_f3_4 * M2C_FIELD(temp_r16_2, float *, 0)) + (temp_f4_2 * M2C_FIELD(temp_r16_2, float *, 0xC)));
                            sp44.y = (temp_f5_2 * M2C_FIELD(temp_r16_2, float *, 0x1C)) + ((temp_f3_4 * M2C_FIELD(temp_r16_2, float *, 4)) + (temp_f4_2 * M2C_FIELD(temp_r16_2, float *, 0x10)));
                            sp44.z = (temp_f5_2 * M2C_FIELD(temp_r16_2, float *, 0x20)) + ((temp_f3_4 * M2C_FIELD(temp_r16_2, float *, 8)) + (temp_f4_2 * M2C_FIELD(temp_r16_2, float *, 0x14)));
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
                        fn_80294CCC(&sp5C, &spD4, &spC8, M2C_FIELD(var_r21, unsigned char *, 0x1A) | ((((M2C_FIELD(var_r21, unsigned char *, 0x18) << 0x10) | 0x80000000) & ~0xFF00) | ((M2C_FIELD(var_r21, unsigned char *, 0x19) << 8) & 0xFF00)), -1, (temp_f3_5 + (temp_f0_5 * temp_f3_5)) * temp_f26_3, (temp_f1_5 + (temp_f0_5 * temp_f1_5)) * temp_f26_3);
                    }
                    var_r21 += 0x20;
                    var_r17_2 += 1;
                    } while (var_r17_2 < (int) M2C_FIELD(var_r14, int *, 0x180));
            }
        }
        var_r14 += 0x184;
        var_r15_2 += 1;
        } while (var_r15_2 < fn_80287B14());
    fn_802C8D74();
}
#pragma pop
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
