// musprerace — pre-race music (mus_prerace.sng, goalline.sfx).
// Recovered TU window 0x8020C140..0x8020CA28+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020CA28 (+ .ctors slot 0x802ED398) remains in
// auto/text_8020CA28_.c pending a promotion pass.
#include <types.h>
#pragma paired_single off

__declspec(section ".data") extern s32 lbl_80489BE0;
__declspec(section ".data") extern s32 lbl_80489C50;
extern s32 *lbl_8055B5D0;
extern s32 *lbl_8055B5D4;
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
extern f32 lbl_805632DC;
extern void fn_8012E81C(s32 *);
extern s32 fn_8012E938(s32 *);
extern s32 fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern void fn_802064D0(s32 *);

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef float f32;
typedef double f64;

extern f32 fn_8020A5F0(void);
extern void fn_80210444(void);
extern void fn_8020C140(void);

extern s32 lbl_8055EE3C;
extern s8 lbl_8055EE40;
extern s8 lbl_8055EE44;
extern s8 lbl_8055EE45;
extern s8 lbl_8055EE46;
extern f32 lbl_8055EE48;
extern f32 lbl_8055EE4C;
extern f32 lbl_8055EE50;
extern f32 lbl_8055EE54;
extern f32 lbl_805632F0;
extern s8 lbl_8055EE58;
extern f32 lbl_805632D8;
extern f32 lbl_805632E0;
extern f64 lbl_805632E8;
extern void fn_80210510(f32);
extern s32 fn_801E8838(void);

extern void fn_8021037C(void);
extern s32 fn_80207848(const char *, s32);
extern const char lbl_8033C5FC[];
extern s32 lbl_8055EE38;
#pragma scheduling invalid_target
void fn_8020C140(void) {
    f32 v1;
    f32 v2;
    f32 v31;
    f32 dc;
    s32 *base;
    s32 ctr;
    void *obj;
    v1 = lbl_8055EE48 * lbl_8055EE4C;
    if ((u8)lbl_8055EE58 != 0) {
        if ((u8)lbl_8055EE40 != 0)
            v1 = lbl_805632D8 * v1;
        fn_80210510(v1);
        dc = lbl_805632DC;
        obj = *(void **)((char *)&lbl_80489BE0 + 0x20);
        if (obj != 0 && dc != *(f32 *)((char *)obj + 8)) {
            *(char *)((char *)obj + 0x4D) = 1;
            *(f32 *)((char *)obj + 8) = dc;
        }
        obj = *(void **)((char *)&lbl_80489BE0 + 0x44);
        if (obj != 0 && dc != *(f32 *)((char *)obj + 8)) {
            *(char *)((char *)obj + 0x4D) = 1;
            *(f32 *)((char *)obj + 8) = dc;
        }
        obj = *(void **)((char *)&lbl_80489BE0 + 0x68);
        if (obj != 0 && dc != *(f32 *)((char *)obj + 8)) {
            *(char *)((char *)obj + 0x4D) = 1;
            *(f32 *)((char *)obj + 8) = dc;
        }
    } else {
        v31 = v1 * lbl_8055EE54;
        if ((u8)lbl_8055EE46 != 0)
            v31 *= (f32)(0xFF - fn_801E8838()) / lbl_805632E0;
        fn_80210510(lbl_805632DC);
        ctr = 3;
        base = &lbl_80489BE0;
        do {
            obj = *(void **)((char *)base + 0x20);
            if (obj != 0) {
                if ((u8)lbl_8055EE40 != 0)
                    v2 = lbl_805632D8 * v31;
                else
                    v2 = v31;
                if (v2 != *(f32 *)((char *)obj + 8)) {
                    *(char *)((char *)obj + 0x4D) = 1;
                    *(f32 *)((char *)obj + 8) = v2;
                }
            }
            base += 9;
            ctr--;
        } while (ctr != 0);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8020C2AC(void) {
    register s32 *base;
    register s32 *sel;
    register s32 idx;
    register u8 *flag;
    register int one;
    f32 f31val;
    u8 tmp;
    void *o1;
    void *o2;

    lbl_8055EE40 = 0;
    lbl_8055EE48 = fn_8020A5F0();
    base = (s32 *)&lbl_80489BE0;
    f31val = lbl_805632DC;
    lbl_8055EE4C = lbl_805632F0;
    idx = 0;
    lbl_8055EE50 = lbl_805632F0;
    lbl_8055EE54 = lbl_805632F0;
    do {
        sel = 0;
        flag = 0;
        switch (idx) {
        case 0:
            sel = (s32 *)&lbl_80489C50;
            flag = (u8 *)&lbl_8055EE41;
            break;
        case 1:
            sel = lbl_8055B5D0;
            flag = (u8 *)&lbl_8055EE42;
            break;
        case 2:
            sel = lbl_8055B5D4;
            flag = (u8 *)&lbl_8055EE43;
            break;
        }
        if (*flag == 0 && fn_8012E938(sel) != 0) {
            fn_8012E81C(sel);
            tmp = (u8)fn_80128690();
            if (tmp == 0) {
                fn_80128684();
            }
            fn_802064D0((s32 *)&lbl_80489C50);
            if (*(s8 *)base != 0) {
                *(void **)((char *)base + 0x20) = (void *)fn_80207848((const char *)base, 0);
            }
            o1 = *(void **)((char *)base + 0x20);
            if (o1 != 0) {
                if (f31val != *(f32 *)((char *)o1 + 0x64)) {
                    *(s8 *)((char *)o1 + 0x6C) = 1;
                    *(f32 *)((char *)o1 + 0x64) = f31val;
                }
                o2 = *(void **)((char *)base + 0x20);
                if (f31val != *(f32 *)((char *)o2 + 0x68)) {
                    *(s8 *)((char *)o2 + 0x6D) = 1;
                    *(f32 *)((char *)o2 + 0x68) = f31val;
                }
            }
            *flag = 1;
            if (tmp == 0) {
                fn_80128678();
            }
        }
        idx++;
        base = (s32 *)((char *)base + 0x24);
    } while (idx < 3);
    fn_8020C140();
}
#pragma pop
void fn_8020C41C(void) {
    fn_8021037C();
    lbl_8055EE38 = fn_80207848(lbl_8033C5FC, 1);
    lbl_8055EE45 = 0;
    lbl_8055EE46 = 0;
}
#pragma scheduling on
extern s32 fn_8012E498(s32 *);
extern s32 fn_802103BC(void);
__declspec(section ".data") extern s32 lbl_80489BE0;
__declspec(section ".data") extern s32 lbl_80489C50;
extern s32 *lbl_8055B5D0;
extern s32 *lbl_8055B5D4;
__declspec(section ".data") extern s32 lbl_80489BE0;
__declspec(section ".data") extern s32 lbl_80489C50;
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
extern f32 lbl_805632DC;
extern void fn_8012E81C(s32 *);
extern s32 fn_8012E938(s32 *);
extern s32 fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern void fn_802064D0(s32 *);
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
#pragma push
#pragma cplusplus on
extern "C" void fn_8020C45C(void) {
    class Object {
    public:
        virtual void release(s32);
    };
    Object *w1;
    Object *w2;
    w1 = (Object *)lbl_8055EE38;
    if (w1 != 0 && w1 != 0) {
        w1->release(1);
    }
    lbl_8055EE38 = 0;
    fn_802103BC();
    {
        s32 *y1 = &lbl_80489BE0;
        s32 y2 = 0;
        do {
            w1 = *(Object **)((char *)y1 + 0x20);
            if (w1 != 0) {
                *(char *)((char *)w1 + 0x4A) = 1;
                *(char *)((char *)w1 + 0x4C) = 0;
                w2 = *(Object **)((char *)y1 + 0x20);
                if (w2 != 0) {
                    w2->release(1);
                }
                *(Object **)((char *)y1 + 0x20) = 0;
            }
            y2 += 1;
            y1 += 9;
        } while (y2 < 3);
    }
    fn_8012E498(&lbl_80489C50);
    fn_8012E498(lbl_8055B5D4);
    fn_8012E498(lbl_8055B5D0);
    lbl_8055EE43 = 0;
    lbl_8055EE42 = 0;
    lbl_8055EE41 = 0;
}
#pragma pop
/* Initializes pre-race music state (stops track music, resets fade/volume/state flags). */
void fn_8020C54C(void) {
    fn_80210444();
    lbl_8055EE4C = lbl_805632F0;
    lbl_8055EE50 = lbl_805632F0;
    lbl_8055EE54 = lbl_805632F0;
    lbl_8055EE48 = fn_8020A5F0();
    lbl_8055EE40 = 0;
    lbl_8055EE44 = 0;
    lbl_8055EE3C = 0;
    lbl_8055EE45 = 0;
    lbl_8055EE46 = 0;
}

extern void fn_8020C2AC(void);
extern s8 fn_802104B8(void);
extern s8 fn_8000D75C(void);
extern s32 fn_800216D0(void);
extern s32 fn_80009C84(void);
extern s32 fn_801B85CC(void);
extern s32 fn_800216FC(void);
extern s32 fn_802E2C20(void);
extern void fn_80210688(s32);
extern s8 lbl_8055EE58;
extern f32 lbl_805632D8;
extern f64 lbl_805632E8;
extern f32 lbl_805632F4;
extern f32 lbl_805632F8;
extern f32 lbl_805632FC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8020C59C(void) {
           register f64 temp_f31;
           f32 temp_f0, temp_f1, temp_f2, temp_f4;
           s32 which_r31, loop_ptr_r28, active_r29, cached_r30, loop_r27, inner_r26;
    s32 temp_r0, temp_r3, current;
           void *object;
           if ((u8)lbl_8055EE41 == 0 || (u8)lbl_8055EE43 == 0 || (u8)lbl_8055EE42 == 0) fn_8020C2AC();
           lbl_8055EE58 = fn_802104B8();
           lbl_8055EE40 = fn_8000D75C();
           active_r29 = 0;
           if (fn_800216D0() != 0 && fn_80009C84() == 0) active_r29 = 1;
           loop_ptr_r28 = active_r29;
           cached_r30 = 1;
           if (fn_801B85CC() == 0 && fn_80009C84() == 0) cached_r30 = 0;
           if ((u8)lbl_8055EE45 == 0) lbl_8055EE45 = active_r29;
           else { lbl_8055EE46 = 1; loop_ptr_r28 = (u8)lbl_8055EE45; }
           which_r31 = 0;
           if (loop_ptr_r28 != 0) which_r31 = 1;
           else if (cached_r30 != 0) which_r31 = 2;
           if (active_r29 != 0 && fn_800216FC() != 0) which_r31 = -1;
           lbl_8055EE54 = lbl_805632F0;
           if (cached_r30 != 0 && (u8)lbl_8055EE44 == 0) {
               active_r29 = 1;
               lbl_8055EE44 = active_r29;
               if (fn_80009C84() == 0) {
                   lbl_8055EE3C = fn_802E2C20();
                   object = (void *)lbl_8055EE38;
                   if (object != 0) {
                       *(u8 *)((u8 *)object + 0x49) = active_r29;
                       *(u8 *)((u8 *)object + 0x4B) = 0;
                       *(u8 *)((u8 *)object + 0x4A) = 0;
                   }
               }
           } else if (cached_r30 == 0) {
               temp_r3 = lbl_8055EE38;
               if (temp_r3 != 0) {
                   *(u8 *)(temp_r3 + 0x4A) = 1;
                   *(u8 *)(temp_r3 + 0x4C) = 0;
               }
           } else if (fn_80009C84() == 0) {
               temp_r3 = fn_802E2C20();
               if (temp_r3 >= lbl_8055EE3C && temp_r3 < lbl_8055EE3C + 0xFA0) {
                   temp_r0 = temp_r3 - lbl_8055EE3C;
                   temp_f0 = ((f32)temp_r0 - lbl_805632DC) / lbl_805632F4;
                   which_r31 = 0;
                   temp_f4 = lbl_805632F0;
                   temp_f4 = temp_f4 < temp_f0 ? temp_f4 : temp_f0;
                   temp_f4 = temp_f4 > lbl_805632DC ? temp_f4 : lbl_805632DC;
                   lbl_8055EE54 = lbl_805632F0 + temp_f4 * lbl_805632F8;
               }
           }
           temp_f2 = lbl_805632D8;
           temp_f0 = lbl_8055EE50 - lbl_8055EE4C;
           temp_f2 = temp_f2 < temp_f0 ? temp_f2 : temp_f0;
           temp_f2 = temp_f2 > lbl_805632FC ? temp_f2 : lbl_805632FC;
           temp_f1 = lbl_805632F0;
           temp_f0 = lbl_8055EE4C + temp_f2;
           temp_f1 = temp_f1 < temp_f0 ? temp_f1 : temp_f0;
           temp_f1 = temp_f1 > lbl_805632DC ? temp_f1 : lbl_805632DC;
           lbl_8055EE4C = temp_f1;
           fn_8020C140();
           temp_f31 = lbl_805632F0;
           loop_ptr_r28 = (s32)&lbl_80489BE0;
           loop_r27 = 0;
           active_r29 = 1;
           cached_r30 = 0;
           do {
               if (loop_r27 == which_r31) {
                   inner_r26 = 0;
                   if ((u8)lbl_8055EE44 != 0 && which_r31 == 2 && fn_80009C84() == 0) {
                       temp_r3 = fn_802E2C20();
                       if (temp_r3 >= lbl_8055EE3C && temp_r3 < lbl_8055EE3C + 0xFA0) inner_r26 = 1;
                   }
                   current = *(s32 *)((u8 *)loop_ptr_r28 + 0x20);
                   if (current != 0 && inner_r26 == 0) {
                       *(u8 *)(current + 0x4A) = cached_r30;
                       *(u8 *)(current + 0x4B) = active_r29;
                       *(u8 *)(current + 0x49) = active_r29;
                       current = *(s32 *)((u8 *)loop_ptr_r28 + 0x20);
                       if (temp_f31 != *(f32 *)(current + 4)) {
                           *(u8 *)(current + 0x4E) = active_r29;
                           *(f32 *)(current + 4) = temp_f31;
                       }
                   }
               } else {
                   current = *(s32 *)((u8 *)loop_ptr_r28 + 0x20);
                   if (current != 0) {
                       *(u8 *)(current + 0x4A) = active_r29;
                       *(u8 *)(current + 0x4C) = cached_r30;
                   }
               }
               loop_r27 += 1;
               loop_ptr_r28 += 0x24;
           } while (loop_r27 < 3);
           fn_80210688(0);
       }
#pragma pop
void fn_8020C8F4(void) {

}

void fn_8020C8F8(void) {

}

void fn_8020C8FC(void) {

}

void fn_8020C900(s8 arg0) {
    lbl_8055EE40 = arg0;
}

void fn_8020C908(f32 arg0) {
    lbl_8055EE48 = arg0;
    fn_8020C140();
}

void fn_8020C910(f32 arg0) {
    lbl_8055EE50 = arg0;
}

void fn_8020C918(void) {

}

void fn_8020C91C(void) {

}

extern void fn_8012DDA8(s32 *);
extern void fn_801345D8(char *, s32, const char *, ...);
extern const char lbl_8033C5D8[];
extern s32 lbl_80489BE0;
extern s32 lbl_80489C50;
extern s32 lbl_8055B5D8;
extern s32 lbl_8055B5DC;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8020C920(s32 arg0) {
    s32 i = 0;
    s32 j = 0;
    char *dst = (char *)&lbl_80489BE0;
    fn_801345D8((char *)&lbl_80489C50, 32, lbl_8033C5D8 + 52, arg0);
    fn_8012DDA8(&lbl_80489C50);
    fn_8012DDA8(lbl_8055B5D0);
    fn_8012DDA8(lbl_8055B5D4);
    do {
        switch (i) {
        case 0:
            if (j != 1)
                fn_801345D8(dst, 32, lbl_8033C5D8 + 64, arg0, &lbl_8055B5DC);
            else
                fn_801345D8(dst, 32, lbl_8033C5D8 + 64, arg0, &lbl_8055B5D8);
            break;
        case 1:
            fn_801345D8(dst, 32, lbl_8033C5D8 + 80, arg0);
            break;
        default:
            fn_801345D8(dst, 32, lbl_8033C5D8 + 96, arg0);
            break;
        }
        i++;
        dst += 36;
    } while (i < 3);
}
#pragma pop
