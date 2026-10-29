// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8020A76C(void);
extern char *fn_8020A774(int);
extern void fn_8023895C(void);
extern void fn_802389E4(void);
extern void fn_80238A74(int, int, const char *, int);
extern void fn_80238B44(int, int, int, int, int);
extern void fn_802E6B38(int, char *);
extern int lbl_8055EE24, lbl_8055EE28;
extern char lbl_8033C5CC[];
extern char lbl_8055B5C8;
extern int sprintf(char *, const char *, ...);
#pragma scheduling invalid_target
void fn_8020BF58(void) {
    struct { char sp8[64]; char sp48[64]; char padding[0xD0]; } scratch;
    register int var_r29 asm("r29");
    register int var_r28 asm("r28");
    register int temp_r26 asm("r26");
    register int temp_r27 asm("r27");
    register int zero asm("r31") = 0;
    register unsigned int temp_r0 asm("r0");
    register unsigned int temp_r3 asm("r3");
    int var_r3, var_r3_3, var_r6_2, var_r5;
    unsigned int temp_r4;
    char *var_r3_2, *var_r6;
    unsigned char temp_r4_2;
    fn_8023895C();
    fn_80238A74(0xC, 0xC, lbl_8033C5CC, 0xFF2D2DC8);
    if (lbl_8055EE24 == 1) {
        fn_80238B44(7, 7, 0x15E, 0x1C0, 0x8C000000);
        var_r29 = 0;
        do {
            fn_802E6B38(var_r29, scratch.sp48);
            temp_r0 = (unsigned int)var_r29 << 28;
            temp_r3 = (unsigned int)var_r29 >> 31;
            temp_r0 -= temp_r3;
            temp_r0 = (temp_r0 << 4) | (temp_r0 >> 28);
            temp_r0 += temp_r3;
            var_r3 = 0x14;
            if (var_r29 / 16 != 0)
                var_r3 = 0x122;
            fn_80238A74(var_r3, (temp_r0 * 0xE) + 0x1A, scratch.sp48, -0x100);
            var_r29 += 1;
        } while (var_r29 < 0x20);
    } else if (lbl_8055EE24 == 0) {
        fn_80238B44(7, 7, 0x12C, 0x1C0, 0x8C000000);
        var_r29 = fn_8020A76C() * 2;
        for (var_r28 = 0; var_r28 < var_r29; var_r28++) {
            var_r3_2 = fn_8020A774(var_r28 / 2);
            temp_r4 = (unsigned int)var_r28 >> 31;
            temp_r27 = ((var_r28 & 1) ^ temp_r4) - temp_r4;
            temp_r26 = (int)(temp_r4 + var_r28) >> 1;
            if (temp_r27 == 0) {
                var_r6 = scratch.sp8;
                var_r5 = 0x40;
                goto copy_text_body;
            copy_text_limit:
                if (--var_r5 <= 0) {
                    *(var_r6 - 1) = zero;
                    goto copy_text_done;
                }
            copy_text_body:
                temp_r4_2 = (unsigned char)*var_r3_2;
                var_r3_2 += 1;
                *var_r6 = temp_r4_2;
                var_r6 += 1;
                if ((signed char)temp_r4_2 == 0)
                    goto copy_text_done;
                else
                    goto copy_text_limit;
            copy_text_done:
                ;
            } else {
                sprintf(scratch.sp8, (const char *)&lbl_8055B5C8, *(float *)(var_r3_2 + 0x20));
            }
            var_r6_2 = -0x100;
            if (temp_r26 == lbl_8055EE28)
                var_r6_2 = 0xFF2D2DC8;
            var_r3_3 = 0x14;
            if (temp_r27 != 0)
                var_r3_3 = 0xF0;
            fn_80238A74(var_r3_3, (temp_r26 * 0xE) + 0x1A, scratch.sp8, var_r6_2);
        }
    }
    fn_802389E4();
}
#pragma scheduling on
