// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 fn_801284F8(s32, void *);
extern void fn_80128668(void *);
extern void *lbl_8055E604;
extern void *lbl_8033596C;
extern void *lbl_8055A8B8;
extern const f32 lbl_80562520;
extern const f32 lbl_8056254C;
extern const f32 lbl_80562550;

extern void fn_801AD888(void **);
void fn_801ADAF4(void *arg0) {
    fn_801AD888((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801AD8C8(void **);
void fn_801ADAFC(void *arg0) {
    fn_801AD8C8((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801AD99C(void **);
void fn_801ADB04(void *arg0) {
    fn_801AD99C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA38(void **);
void fn_801ADB0C(void *arg0) {
    fn_801ADA38((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA7C(void **);
void fn_801ADB14(void *arg0) {
    fn_801ADA7C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA84(void **);
void fn_801ADB1C(void *arg0) {
    fn_801ADA84((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA8C(void **);
void fn_801ADB24(void *arg0) {
    fn_801ADA8C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA94(void **);
void fn_801ADB2C(void *arg0) {
    fn_801ADA94((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA9C(void **);
void fn_801ADB34(void *arg0) {
    fn_801ADA9C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADAB8(void **);
void fn_801ADB3C(void *arg0) {
    fn_801ADAB8((void **)((u8 *)arg0 - 0x23C));
}

void fn_801AE158(void *arg0) {
    struct { f32 field1; f32 field2; f32 field3; } locals;
    locals.field1 = lbl_80562520;
    locals.field2 = lbl_80562520;
    locals.field3 = lbl_80562520;
    *(f32 *)((u8 *)arg0 + 0x1C) = locals.field1;
    *(f32 *)((u8 *)arg0 + 0x20) = locals.field2;
    *(f32 *)((u8 *)arg0 + 0x24) = locals.field3;
}

void *fn_801AE180(void) {
     s32 temp_r12;
     s32 temp_r3;
     s32 temp_r8_2;
     s32 temp_r9;
     s32 var_r4;
     s32 var_r5;
     s32 var_r5_2;
     s32 var_r8;
     u32 temp_r11;
     u32 var_ctr;
     u32 var_ctr_2;
     void **temp_r31;
     u8 *temp_r3_2;
     u8 *temp_r3_3;
     u8 *temp_r5;
     u8 *temp_r5_2;
     u8 *temp_r5_3;
     u8 *temp_r7;
     u8 *temp_r8;
     u8 *var_r6;
 
     temp_r31 = lbl_8055E604;
     temp_r3_2 = (*(void **)((u8 *)(temp_r31) + (0)));
     if ((temp_r3_2 == ((void *)0)) || ((s32) (*(s32 *)((u8 *)(temp_r3_2) + (4))) == 0x40)) {
         temp_r3_3 = (u8 *)fn_801284F8(0xA08, (void *)(*(s32 *)((u8 *)(temp_r31) + (4))));
         if (temp_r3_3 != ((void *)0)) {
             var_r6 = temp_r3_3 + 0x30;
             temp_r5_2 = temp_r3_3 + 0xA08;
             (*(f32 *)((u8 *)(temp_r3_3) + (0xC))) = (f32) lbl_80562520;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x10))) = (f32) lbl_80562520;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x14))) = (f32) lbl_80562520;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x18))) = (f32) lbl_8056254C;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x1C))) = (f32) lbl_80562550;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x20))) = (f32) lbl_80562520;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x24))) = (f32) lbl_80562520;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x28))) = (f32) lbl_80562520;
             (*(f32 *)((u8 *)(temp_r3_3) + (0x2C))) = (f32) lbl_80562520;
             (*(s32 *)((u8 *)(temp_r3_3) + (8))) = 0;
             if (var_r6 < temp_r5_2) {
                 temp_r8 = temp_r3_3 + 0x30;
                 temp_r9 = temp_r5_2 - temp_r8;
                 temp_r11 = (temp_r9 + 0x27) / 40;
                 temp_r12 = temp_r11 + 1;
                 temp_r7 = temp_r3_3 + 0x8C8;
                 if (temp_r12 > 8) {
                     var_r4 = 0;
                     var_r5 = 0;
                     if (temp_r8 <= temp_r5_2) {
                         var_r8 = 1;
                         if (!(temp_r9 & 0x80000000) && ((temp_r9 + 0x27) & 0x80000000)) {
                             var_r8 = 0;
                         }
                         if (var_r8 != 0) {
                             var_r5 = 1;
                         }
                     }
                     if (var_r5 != 0) {
                         temp_r8_2 = temp_r11 & 0x80000000;
                         var_r5_2 = 1;
                         if ((temp_r8_2 == 0) && (temp_r8_2 != (s32) (temp_r12 & 0x80000000))) {
                             var_r5_2 = 0;
                         }
                         if (var_r5_2 != 0) {
                             var_r4 = 1;
                         }
                     }
                     if (var_r4 != 0) {
                         var_ctr = (u32) ((temp_r7 + 0x13F) - var_r6) / 320U;
                         if (var_r6 < temp_r7) {
                             do {
                                 (*(f32 *)((u8 *)(var_r6) + (4))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (8))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xC))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x10))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0x14))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0x18))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x1C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x20))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x24))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0x2C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x30))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x34))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x38))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0x3C))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0x40))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x44))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x48))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x4C))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0x28))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0x54))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x58))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x5C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x60))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0x64))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0x68))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x6C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x70))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x74))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0x50))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0x7C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x80))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x84))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x88))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0x8C))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0x90))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x94))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x98))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x9C))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0x78))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0xA4))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xA8))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xAC))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xB0))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0xB4))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0xB8))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xBC))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xC0))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xC4))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0xA0))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0xCC))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xD0))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xD4))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xD8))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0xDC))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0xE0))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xE4))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xE8))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xEC))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0xC8))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0xF4))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xF8))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0xFC))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x100))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0x104))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0x108))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x10C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x110))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x114))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0xF0))) = 0;
                                 (*(f32 *)((u8 *)(var_r6) + (0x11C))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x120))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x124))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x128))) = (f32) lbl_8056254C;
                                 (*(f32 *)((u8 *)(var_r6) + (0x12C))) = (f32) lbl_80562550;
                                 (*(f32 *)((u8 *)(var_r6) + (0x130))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x134))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x138))) = (f32) lbl_80562520;
                                 (*(f32 *)((u8 *)(var_r6) + (0x13C))) = (f32) lbl_80562520;
                                 (*(s32 *)((u8 *)(var_r6) + (0x118))) = 0;
                                 var_r6 += 0x140;
                                 var_ctr -= 1;
                             } while (var_ctr != 0);
                         }
                     }
                 }
                 temp_r5_3 = temp_r3_3 + 0xA08;
                 var_ctr_2 = (u32) ((temp_r5_3 + 0x27) - var_r6) / 40U;
                 if (var_r6 < temp_r5_3) {
                     do {
                         (*(f32 *)((u8 *)(var_r6) + (4))) = (f32) lbl_80562520;
                         (*(f32 *)((u8 *)(var_r6) + (8))) = (f32) lbl_80562520;
                         (*(f32 *)((u8 *)(var_r6) + (0xC))) = (f32) lbl_80562520;
                         (*(f32 *)((u8 *)(var_r6) + (0x10))) = (f32) lbl_8056254C;
                         (*(f32 *)((u8 *)(var_r6) + (0x14))) = (f32) lbl_80562550;
                         (*(f32 *)((u8 *)(var_r6) + (0x18))) = (f32) lbl_80562520;
                         (*(f32 *)((u8 *)(var_r6) + (0x1C))) = (f32) lbl_80562520;
                         (*(f32 *)((u8 *)(var_r6) + (0x20))) = (f32) lbl_80562520;
                         (*(f32 *)((u8 *)(var_r6) + (0x24))) = (f32) lbl_80562520;
                         (*(s32 *)((u8 *)(var_r6) + (0))) = 0;
                         var_r6 += 0x28;
                         var_ctr_2 -= 1;
                     } while (var_ctr_2 != 0);
                 }
             }
             (*(s32 *)((u8 *)(temp_r3_3) + (4))) = 0;
             (*(void **)((u8 *)(temp_r3_3) + (0))) = ((void *)0);
         }
         (*(void **)((u8 *)(temp_r3_3) + (0))) = (void *) (*(void **)((u8 *)(temp_r31) + (0)));
         (*(void **)((u8 *)(temp_r31) + (0))) = temp_r3_3;
     }
     temp_r5 = (*(void **)((u8 *)(temp_r31) + (0)));
     temp_r3 = (*(s32 *)((u8 *)(temp_r5) + (4)));
     (*(s32 *)((u8 *)(temp_r5) + (4))) = (s32) (temp_r3 + 1);
     return temp_r5 + (temp_r3 * 0x28) + 8;
 }

void fn_801AE4C4(void) {
    void *result = (void *)fn_801284F8(8, &lbl_8033596C);
    if (result != NULL) {
        *(s32 *)result = 0;
        *(void **)((u8 *)result + 4) = &lbl_8055A8B8;
        lbl_8055E604 = result;
    }
}

void fn_801AE50C(void) {
    void *ptr = lbl_8055E604;
    if (ptr != NULL) {
        void *r31;
        do {
            r31 = *(void **)ptr;
            fn_80128668(ptr);
            *(void **)ptr = r31;
            ptr = r31;
        } while (ptr != NULL);
        lbl_8055E604 = NULL;
    }
}

