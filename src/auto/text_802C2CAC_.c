// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern const char lbl_8034B078[];
extern const char lbl_8034B0E4[];
extern void fn_802C3918(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3C68(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3D74(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3F00(s32,s32,s32,s32,s32,s32,s32,s32);

extern u8 lbl_8055CFF8;
extern u8 lbl_8055D000;
extern void *fn_801284E8(void *, s32);
void fn_802C2CE8(void *, s32, s32, s8);
void fn_802C3014(void *);

void fn_802C5024(s32, s32, s32, s32);

extern void fn_8012C4D8(void);

extern s32 lbl_8055FC00;
extern void fn_802C3754(s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_802DB2C8(void);
extern void fn_802C3478(s32, s32, s32, s32, u32);
extern void fn_802C356C(s32, s32, s32, s32, u32);
extern void fn_802C365C(s32, s32, s32, s32, u32);
s32 fn_802C2CAC(s32 arg0) {
    return (((arg0 << 9) & 0xF80000) | 0xFF000000 | ((arg0 << 6) & 0xF800)) | ((arg0 & 0x1F) << 3);
}

s32 fn_802C2CC4(s32 arg0) {
    unsigned int value = ((unsigned int)arg0 << 8) & 0x00F80000;
    value |= 0xFF000000;
    value |= ((unsigned int)arg0 << 5) & 0x0000FC00;
    value |= ((unsigned int)arg0 & 0x1F) << 3;
    return (s32)value;
}

void fn_802C2CDC(void *arg0, s32 arg1, s32 arg2) {
    fn_802C2CE8(arg0, arg1, arg2, (s8)lbl_8055CFF8);
}

void fn_802C2CE8(void *arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 scale;
    *(s8 *)arg0 = arg3;
    ((u8 *)arg0)[1] = 0x82;
    scale = (arg3 == 5) ? 4 : 2;
    *(void **)((u8 *)arg0 + 4) = fn_801284E8(&lbl_8055D000, arg1 * arg2 * scale);
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = arg2;
    if (arg3 == 5)
        *(s32 *)((u8 *)arg0 + 0x10) = arg1 * scale;
    fn_802C3014(arg0);
}

void fn_802C2D94(void *arg0) {
    fn_80128658(*(s32 *)((u8 *)arg0 + 4));
    memset(arg0, 0, 0x24);
}

extern void *fn_8012C370(s32,u32 *,s32 *,s32,u8 *);
extern void fn_802E317C(const char *,...);
extern const char lbl_8034B020[],lbl_8034B048[];
void *fn_802C2DD4(s32 arg0) {
    u32 sp10; s32 spC; u8 sp8; s32 y,x; u32 *p; u32 value; u8 t; void *obj;
    obj=((void *(*)(s32,s32,u32 *,s32 *,s32,u8 *))fn_8012C370)(arg0,0x43414E56,&sp10,&spC,0,&sp8);
    if(obj) {
      if(sp10==1) { if(sp8) {
        t=((u8 *)obj)[4];((u8 *)obj)[4]=((u8 *)obj)[7];((u8 *)obj)[7]=t;
        t=((u8 *)obj)[5];((u8 *)obj)[5]=((u8 *)obj)[6];((u8 *)obj)[6]=t;
        t=((u8 *)obj)[8];((u8 *)obj)[8]=((u8 *)obj)[11];((u8 *)obj)[11]=t;
        t=((u8 *)obj)[9];((u8 *)obj)[9]=((u8 *)obj)[10];((u8 *)obj)[10]=t;
        for(x=0;x<4;x++){t=((u8 *)obj)[12+x];((u8 *)obj)[12+x]=((u8 *)obj)[15-x];((u8 *)obj)[15-x]=t;
        t=((u8 *)obj)[16+x];((u8 *)obj)[16+x]=((u8 *)obj)[19-x];((u8 *)obj)[19-x]=t;
        t=((u8 *)obj)[20+x];((u8 *)obj)[20+x]=((u8 *)obj)[23-x];((u8 *)obj)[23-x]=t;
        t=((u8 *)obj)[24+x];((u8 *)obj)[24+x]=((u8 *)obj)[27-x];((u8 *)obj)[27-x]=t;
        t=((u8 *)obj)[28+x];((u8 *)obj)[28+x]=((u8 *)obj)[31-x];((u8 *)obj)[31-x]=t;
        t=((u8 *)obj)[32+x];((u8 *)obj)[32+x]=((u8 *)obj)[35-x];((u8 *)obj)[35-x]=t;}
        p=(u32 *)((u8 *)obj+0x24);*(void **)((u8 *)obj+4)=p;
        for(y=0;y<*(s32 *)((u8 *)obj+0xC);y++)for(x=0;x<*(s32 *)((u8 *)obj+8);x++){value=*p;*p=(value<<24)|(value>>8);p++;}
      }} else fn_802E317C(lbl_8034B020,arg0,1);
    } else fn_802E317C(lbl_8034B048,arg0);
    return obj;
}

void fn_802C2FC4(void) {
    ((void (*)(void))fn_8012C4D8)();
}

#pragma scheduling invalid_target
void fn_802C2FC8(void *arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    s32 var_r0;
    s32 var_r10;
    var_r10 = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x14) = (s32)(arg1 & ((arg1 >> 31) - 1));
    *(s32 *)((u8 *)arg0 + 0x18) = (s32)(arg2 & ((arg2 >> 31) - 1));
    if (arg3 < var_r10) {
        var_r10 = arg3;
    }
    var_r0 = *(s32 *)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 0x1C) = var_r10;
    if (arg4 < var_r0) {
        var_r0 = arg4;
    }
    *(s32 *)((u8 *)arg0 + 0x20) = var_r0;
}
#pragma scheduling on
void fn_802C3014(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x20) = *(s32 *)((u8 *)arg0 + 0xC);
}

s32 fn_802C3034(s32 value) {
    s32 old;

    old = lbl_8055FC00;
    lbl_8055FC00 = value;
    return old;
}

s32 fn_802C3044(void *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((u8 *)arg0 + 0x10) * arg2 + (*(s32 *)((u8 *)arg0 + 4) + arg1 * 2);
}

s32 fn_802C3060(void *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((u8 *)arg0 + 0x10) * arg2 + (*(s32 *)((u8 *)arg0 + 4) + arg1 * 4);
}

s32 fn_802C307C(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 x0 = *arg1;
    s32 x1;
    s32 x2;
    if (x0 >= *(s32 *)((u8 *)arg0 + 0x1C)) return 0;
    if (*arg2 >= *(s32 *)((u8 *)arg0 + 0x20)) return 0;
    x1 = *(s32 *)((u8 *)arg0 + 0x14);
    if (x0 < x1) *arg1 = x1;
    x1 = *(s32 *)((u8 *)arg0 + 0x18);
    if (*arg2 < x1) *arg2 = x1;
    x1 = *(s32 *)((u8 *)arg0 + 0x1C);
    if (*arg3 > x1) *arg3 = x1;
    x2 = *(s32 *)((u8 *)arg0 + 0x20);
    if (*arg4 > x2) *arg4 = x2;
    if (*arg1 >= *arg3) return 0;
    return *arg2 < *arg4;
}

s32 fn_802C3130(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 >= *(s32 *)((u8 *)arg0 + 0x14) && arg2 >= *(s32 *)((u8 *)arg0 + 0x18) && arg1 < *(s32 *)((u8 *)arg0 + 0x1C) && arg2 < *(s32 *)((u8 *)arg0 + 0x20)) return 1;
    return 0;
}

s32 fn_802C3170(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    s32 temp_r0, temp_r0_2, temp_r10, temp_r10_2, temp_r11, temp_r12, temp_r31;
    s32 temp_r3, temp_r4, temp_r4_2, temp_r6, temp_r6_2, temp_r6_3;
    temp_r11 = *arg1;
    temp_r31 = *(s32 *)((u8 *)arg0 + 0x14);
    if (temp_r11 + *arg5 < temp_r31) return 0;
    temp_r12 = *arg2;
    if (temp_r12 + *arg6 < *(s32 *)((u8 *)arg0 + 0x18)) return 0;
    if (temp_r11 >= *(s32 *)((u8 *)arg0 + 0x1C)) return 0;
    if (temp_r12 >= *(s32 *)((u8 *)arg0 + 0x20)) return 0;
    if (temp_r11 < temp_r31) {
        temp_r10 = temp_r31 - temp_r11;
        *arg3 += temp_r10;
        *arg5 -= temp_r10;
        *arg1 = *(s32 *)((u8 *)arg0 + 0x14);
    }
    temp_r6 = *(s32 *)((u8 *)arg0 + 0x18);
    temp_r10_2 = *arg2;
    if (temp_r10_2 < temp_r6) {
        temp_r6_2 = temp_r6 - temp_r10_2;
        *arg4 += temp_r6_2;
        *arg6 -= temp_r6_2;
        *arg2 = *(s32 *)((u8 *)arg0 + 0x18);
    }
    temp_r0 = *arg1;
    temp_r4 = *arg5;
    temp_r6_3 = *(s32 *)((u8 *)arg0 + 0x1C);
    temp_r0 += temp_r4;
    if (temp_r0 > temp_r6_3) *arg5 = temp_r4 - (temp_r0 - temp_r6_3);
    temp_r0_2 = *arg2;
    temp_r4_2 = *arg6;
    temp_r3 = *(s32 *)((u8 *)arg0 + 0x20);
    temp_r0_2 += temp_r4_2;
    if (temp_r0_2 > temp_r3) *arg6 = temp_r4_2 - (temp_r0_2 - temp_r3);
    if (*arg5 <= 0) return 0;
    return *arg6 > 0;
}

extern const char lbl_8034B060[];
extern void fn_802C3320();
extern void fn_802C33A8(s32, s32, u32);
extern void fn_802E317C(const char *, ...);
void fn_802C32B8(s32 arg0, s32 arg1, u32 arg2) {
    u8 *state = (u8 *)lbl_8055FC00;
    s8 mode;
    s32 flag;
    if (state[1] & 4) return;
    mode = (s8)state[0];
    flag = 0;
    if (mode != 5 && mode != 6) flag = 1;
    if (flag != 0) {
        fn_802C3320();
        return;
    }
    if ((s8)state[0] == 5) {
        fn_802C33A8(arg0, arg1, arg2);
        return;
    }
    fn_802E317C(lbl_8034B060, (s32)(s8)*(u8 *)lbl_8055FC00);
}

#pragma push
#pragma inline_depth(0)
void fn_802C3320(s32 arg0, s32 arg1, u32 arg2) {
    u32 value;
    if (fn_802C3130((void *)lbl_8055FC00, arg0, arg1) != 0) {
        value = arg2 >> 16;
        if ((s8)*(u8 *)lbl_8055FC00 == 3)
            value = arg2 & 0xFFFF;
        *(u16 *)fn_802C3044((void *)lbl_8055FC00, arg0, arg1) = (u16)value;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(0)
void fn_802C33A8(s32 arg0, s32 arg1, u32 arg2) {
    u32 *pixel;
    u32 value;
    if (fn_802C3130((void *)lbl_8055FC00, arg0, arg1) != 0) {
        pixel = (u32 *)fn_802C3060((void *)lbl_8055FC00, arg0, arg1);
        value = ((arg2 >> 8) & 0x00F80000) | 0xFF000000;
        value = (value & ~0x0000FC00) | ((arg2 >> 11) & 0x0000FC00);
        value = (value & ~0x000000F8) | ((arg2 >> 13) & 0x000000F8);
        *pixel = value;
    }
}

void fn_802C3424(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
    s8 mode = *(s8 *)lbl_8055FC00;
    s32 flag = 0;
    if (mode != 5 && mode != 6)
        flag = 1;
    if (flag != 0) {
        if (*(volatile s8 *)lbl_8055FC00 != 1) {
            fn_802C3478(arg0, arg1, arg2, arg3, arg4);
            return;
        }
        fn_802C365C(arg0, arg1, arg2, arg3, arg4);
        return;
    }
    if (*(volatile s8 *)lbl_8055FC00 != 5)
        return;
    fn_802C356C(arg0, arg1, arg2, arg3, arg4);
}

#pragma pop

#pragma push
#pragma processor 750
#pragma inline_depth(0)
void fn_802C3478(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    s32 width, height, skip, n;
    s32 mode;
    u16 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    pixel = color >> 16;
    mode = *(u8 *)lbl_8055FC00;
    width = x1 - x0;
    height = y1 - y0;
    if (mode == 3) pixel = (u16)color;
    p = (u16 *)fn_802C3044((void *)lbl_8055FC00, x0, y0);
    skip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 2) / 2;
    do {
        n = width;
        do {
            --n;
            *p++ = pixel;
        } while (n > 0);
        --height;
        p += skip;
    } while (height > 0);
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma inline_depth(0)
void fn_802C356C(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    s32 width, height, skip, n;
    u32 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    pixel = ((color >> 8) & 0xF80000) | 0xFF000000;
    pixel = (pixel & ~0xFC00) | ((color >> 11) & 0xFC00);
    width = x1 - x0;
    height = y1 - y0;
    pixel = (pixel & ~0xF8) | ((color >> 13) & 0xF8);
    p = (u32 *)fn_802C3060((void *)lbl_8055FC00, x0, y0);
    skip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 4) / 4;
    do {
        n = width;
        do {
            --n;
            *p++ = pixel;
        } while (n > 0);
        --height;
        p += skip;
    } while (height > 0);
}

#pragma push
#pragma inline_depth(0)
#pragma processor 750
#pragma use_lmw_stmw off
#pragma optimize_for_size off
void fn_802C365C(s32 x0, s32 y0, s32 x1, s32 y1, u32 color) {
    u32 pixel;
    s32 low;
    s32 width, height, n;
    u32 skip;
    u16 *p;
    if (x1 == x0 || y1 == y0) return;
    if (!fn_802C307C((void *)lbl_8055FC00, &x0, &y0, &x1, &y1)) return;
    low = (s32)((color * 8) & 0xF8) >> 4;
    pixel = ((s32)color >> 3) & 0xF00;
    pixel = (pixel & ~0xF0) | (((s32)color >> 2) & 0xF0);
    width = x1 - x0;
    pixel = low | pixel;
    height = y1 - y0;
    p = (u16 *)fn_802C3044((void *)lbl_8055FC00, x0, y0);
    skip = (*(s32 *)((u8 *)lbl_8055FC00 + 0x10) - width * 2);
    skip = ((skip >> 31) + skip) & ~1;
    do {
        n = width;
        do {
            --n;
            *p = pixel | (*p & 0xF000);
            ++p;
        } while (n > 0);
        --height;
        p = (u16 *)((u8 *)p + skip);
    } while (height > 0);
}
#pragma pop

#pragma pop
extern const char lbl_8034B094[];
extern void fn_802C4108();
extern void fn_802C4610();
extern void fn_802C4388();
extern void fn_802C4108(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C4610(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C4388(s32,s32,s32,s32,s32,s32,s32,s32);
void fn_802C3850(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 mode = *(u8 *)arg0;
    s32 flag = 0;
    if ((s8)mode != 5 && (s8)mode != 6) flag = 1;
    if (flag) {
        flag = 0;
        if (*(s8 *)arg5 != 5 && *(s8 *)arg5 != 6) flag = 1;
        if (flag) {
            fn_802C4108(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
            return;
        }
    }
    if ((s8)mode == 5 && (s32)*(u8 *)arg5 == 5) {
        fn_802C4610(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
        return;
    }
    if ((s8)mode == 5) {
        flag = 0;
        if (*(s8 *)arg5 != 5 && *(s8 *)arg5 != 6) flag = 1;
        if (flag) {
            fn_802C4388(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
            return;
        }
    }
    fn_802E317C(lbl_8034B094, (s32)*(s8 *)arg0, (s32)*(s8 *)arg5);
}

extern s32 fn_802C3170(void *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern const char lbl_8034B0B8[];
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
void fn_802C3918(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 temp_r0, temp_r29, temp_r31;
    s32 temp_r4, temp_r5, temp_r6, temp_r0_4, temp_r4_4;
    s32 var_r4, var_r4_2, var_r7;
    u16 *var_r30, *var_r30_2, *var_r30_3, *var_r30_4;
    u16 *var_r3, *var_r3_2, *var_r3_3, *var_r3_4;
    u16 temp_r0_2, temp_r7, temp_r7_2, temp_r8;
    s8 temp_r4_2, temp_r5_2;

    sp8 = arg1; spC = arg2; sp10 = arg6; sp14 = arg7;
    sp1C = arg3 - arg1; sp18 = arg4 - arg2;
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        var_r30 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
        var_r3 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
        temp_r31 = sp1C;
        temp_r5 = temp_r31 * 2;
        temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
        temp_r29 = sp18;
        temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
        temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
        temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
        temp_r5 &= ~1;
        temp_r6 = temp_r0 & ~1;
        do {
            var_r4 = sp1C;
loop_copy:
            temp_r0_2 = *var_r30;
            var_r4--;
            var_r30++;
            *var_r3 = temp_r0_2;
            var_r3++;
            if (var_r4 > 0) goto loop_copy;
            var_r30 = (u16 *)((u8 *)var_r30 + temp_r5);
            var_r3 = (u16 *)((u8 *)var_r3 + temp_r6);
            temp_r0 = sp18 - 1;
            sp18 = temp_r0;
        } while (temp_r0 > 0);

        temp_r5_2 = *(s8 *)arg5;
        temp_r4_2 = *(s8 *)arg0;
        if (temp_r4_2 != temp_r5_2) {
            if (temp_r4_2 == 4 && temp_r5_2 == 3) {
                var_r30_2 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
                var_r3_2 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
                sp1C = temp_r31;
                temp_r5 = temp_r31 * 2;
                sp18 = temp_r29;
                temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
                temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
                temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
                temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
                temp_r5 &= ~1;
                temp_r6 = temp_r0 & ~1;
                do {
                    var_r4_2 = sp1C;
loop_10:
                    temp_r7 = *var_r30_2;
                    var_r4_2--;
                    var_r30_2++;
                    temp_r0_2 = (temp_r7 >> 1) & 0x7FE0;
                    temp_r0_2 |= temp_r7 & 0x1F;
                    *var_r3_2 = temp_r0_2;
                    var_r3_2++;
                    if (var_r4_2 > 0) goto loop_10;
                    var_r30_2 = (u16 *)((u8 *)var_r30_2 + temp_r5);
                    var_r3_2 = (u16 *)((u8 *)var_r3_2 + temp_r6);
                    temp_r0 = sp18 - 1;
                    sp18 = temp_r0;
                } while (temp_r0 > 0);
                return;
            }
            if (temp_r4_2 == 3 && temp_r5_2 == 4) {
                var_r30_3 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
                var_r3_3 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
                sp1C = temp_r31;
                temp_r5 = temp_r31 * 2;
                sp18 = temp_r29;
                temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
                temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
                temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
                temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
                temp_r5 &= ~1;
                temp_r6 = temp_r0 & ~1;
                do {
                    var_r7 = sp1C;
loop_17:
                    temp_r8 = *var_r30_3;
                    var_r7--;
                    var_r30_3++;
                    temp_r0_4 = ((s32)temp_r8 * 2) & 0x400;
                    temp_r4_4 = ((s32)temp_r8 * 2) & 0xFFC0;
                    temp_r4_4 |= temp_r8 & 0x1F;
                    temp_r0_4 = temp_r4_4 | (temp_r0_4 >> 5);
                    *var_r3_3 = temp_r0_4;
                    var_r3_3++;
                    if (var_r7 > 0) goto loop_17;
                    var_r30_3 = (u16 *)((u8 *)var_r30_3 + temp_r5);
                    var_r3_3 = (u16 *)((u8 *)var_r3_3 + temp_r6);
                    temp_r0 = sp18 - 1;
                    sp18 = temp_r0;
                } while (temp_r0 > 0);
                return;
            }
            if (temp_r4_2 == 1 && temp_r5_2 == 4) {
                var_r30_4 = (u16 *)fn_802C3044((void *)arg0, sp8, spC);
                var_r3_4 = (u16 *)fn_802C3044((void *)arg5, sp10, sp14);
                sp1C = temp_r31;
                temp_r5 = temp_r31 * 2;
                sp18 = temp_r29;
                temp_r6 = *(s32 *)((u8 *)arg0 + 0x10) - temp_r5;
                temp_r4 = *(s32 *)((u8 *)arg5 + 0x10) - temp_r5;
                temp_r5 = ((u32)temp_r6 >> 31) + temp_r6;
                temp_r0 = ((u32)temp_r4 >> 31) + temp_r4;
                temp_r5 &= ~1;
                temp_r6 = temp_r0 & ~1;
                do {
                    var_r4 = sp1C;
loop_24:
                    temp_r7_2 = *var_r30_4;
                    var_r4--;
                    var_r30_4++;
                    temp_r0_2 = ((temp_r7_2 & 0xF) << 1);
                    temp_r0_2 |= (temp_r7_2 << 3) & 0x780;
                    temp_r0_2 |= (temp_r7_2 << 4) & 0xF000;
                    *var_r3_4 = temp_r0_2;
                    var_r3_4++;
                    if (var_r4 > 0) goto loop_24;
                    var_r30_4 = (u16 *)((u8 *)var_r30_4 + temp_r5);
                    var_r3_4 = (u16 *)((u8 *)var_r3_4 + temp_r6);
                    temp_r0 = sp18 - 1;
                    sp18 = temp_r0;
                } while (temp_r0 > 0);
                return;
            }
            fn_802E317C(lbl_8034B0B8, (s32)temp_r4_2, (s32)temp_r5_2);
        }
    }
}
#pragma pop

// Keep the target scheduling and helper calls: these reproduce the original copy loop.
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_802C3C68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                 s32 arg5, s32 arg6, s32 arg7) {
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    s32 *src, *dst;
    s32 i, widthBytes, skipSrc, skipDst;
    sp8 = arg1;
    spC = arg2;
    sp10 = arg6;
    sp14 = arg7;
    sp1C = arg3 - arg1;
    sp18 = arg4 - arg2;
    if (fn_802C3170((void *)arg5, &sp10, &sp14, &sp8, &spC, &sp1C, &sp18) != 0) {
        src = (s32 *)fn_802C3060((void *)arg0, sp8, spC);
        dst = (s32 *)fn_802C3060((void *)arg5, sp10, sp14);
        widthBytes = sp1C * 4;
        skipSrc = (*(s32 *)((char *)arg0 + 0x10) - widthBytes) / 4;
        skipDst = (*(s32 *)((char *)arg5 + 0x10) - widthBytes) / 4;
        do {
            i = sp1C;
loop_3:
            {
                s32 t = *src;
                i--;
                src++;
                *dst = t;
                dst++;
            }
            if (i > 0)
                goto loop_3;
            src += skipSrc;
            dst += skipDst;
            sp18--;
        } while (sp18 > 0);
    }
}

extern const char lbl_8034B100[];
void fn_802C3F00(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5,s32 arg6,s32 arg7) {
    s32 sp1C,sp18,sp14,sp10,spC,sp8;
    s16 *dst;
    u32 *src;
    s32 pitch,skipSrc,skipDst,i,row;
    u32 pixel;
    sp8=arg1; spC=arg2; sp10=arg6; sp14=arg7; sp1C=arg3-arg1; sp18=arg4-arg2;
    if(fn_802C3170((void *)arg5,&sp10,&sp14,&sp8,&spC,&sp1C,&sp18)!=0) {
        src=(u32 *)fn_802C3060((void *)arg0,sp8,spC);
        dst=(s16 *)fn_802C3044((void *)arg5,sp10,sp14);
        pitch=*(s32 *)((u8 *)arg5+0x10)-sp1C*2;
        skipSrc=(*(s32 *)((u8 *)arg0+0x10)-sp1C*4)/4;
        skipDst=(pitch+((u32)pitch>>31))/2;
        if(*(s8 *)arg5==3) {
            row=sp18;
            do {
                i=sp1C;
                do { pixel=*src++; *dst++=((pixel&255)>>3)|(((pixel>>6)&0x3E0)&~0x7C00)|((((pixel>>16)&255)>>3)<<10); } while(--i>0);
                src+=skipSrc; dst+=skipDst;
            } while(--row>0);
        } else if(*(s8 *)arg5==4) {
            row=sp18;
            do {
                i=sp1C;
                do { pixel=*src++; *dst++=(((pixel>>8)&0xF800)&~0x7E0)|((pixel>>5)&0x7E0)|((pixel>>3)&0x1F); } while(--i>0);
                src+=skipSrc; dst+=skipDst;
            } while(--row>0);
        } else fn_802E317C((char *)lbl_8034B100,*(s8 *)arg0);
    }
}

void fn_802C40B8(void *arg0, s32 arg1, s32 arg2) {
    if ((*(u8 *)((u8 *)lbl_8055FC00 + 1) & 4) != 0) {
        fn_802DB2C8();
        return;
    }
    fn_802C3754((s32)arg0, 0, 0,
        *(s32 *)((u8 *)arg0 + 8), *(s32 *)((u8 *)arg0 + 0xC),
        lbl_8055FC00, arg1, arg2);
}

void fn_802C40E8(void *arg0, s32 arg1, s32 arg2) {
    fn_802C3850((s32)arg0, 0, 0,
        *(s32 *)((u8 *)arg0 + 8), *(s32 *)((u8 *)arg0 + 0xC),
        lbl_8055FC00, arg1, arg2);
}

extern void *fn_8012C370(s32, u32 *, s32 *, s32, u8 *);
extern const char lbl_8034B144[];
void *fn_802C49E8(s32 arg0) {
    u32 size;
    s32 unused;
    u8 swap;
    u8 *obj;
    u8 *p;
    s32 x;
    s32 y;
    s32 count;
    u32 *words;
    u32 temp;

    obj = (u8 *)fn_8012C370(0x53544D50, &size, &unused, 0, &swap);
    if (obj == 0)
        return 0;
    if (size != 3)
        fn_802E317C(lbl_8034B144, arg0, 3);
    if (swap != 0) {
        for (x = 0; x < 5; x++) {
            u32 base = x * 4;
            u8 t = obj[base];
            obj[base] = obj[base + 3];
            obj[base + 3] = t;
            t = obj[base + 1];
            obj[base + 1] = obj[base + 2];
            obj[base + 2] = t;
        }
        p = obj + 0x814;
        for (x = 0; x < 2; x++) {
            u8 t = p[x * 4];
            p[x * 4] = p[x * 4 + 3];
            p[x * 4 + 3] = t;
            t = p[x * 4 + 1];
            p[x * 4 + 1] = p[x * 4 + 2];
            p[x * 4 + 2] = t;
        }
        p = obj + 0x818;
        {
            u8 t = p[0];
            p[0] = p[3]; p[3] = t;
            t = p[1]; p[1] = p[2]; p[2] = t;
        }
        *(u32 *)(obj + 0x814) = (u32)(obj + 0x81c);
        words = (u32 *)(obj + 0x814);
        count = *(u32 *)(obj + 4) * *(u32 *)(obj + 0x10);
        for (y = 0; y < count; y++) {
            u32 *word = (u32 *)((u8 *)words[0] + y * 4);
            *word = *word + *(u32 *)(obj + 0x818);
        }
        p = obj + 0x414;
        for (x = 0; x < 0x40; x++) {
            u8 t = p[0]; p[0] = p[3]; p[3] = t;
            t = p[1]; p[1] = p[2]; p[2] = t;
            t = p[4]; p[4] = p[7]; p[7] = t;
            t = p[5]; p[5] = p[6]; p[6] = t;
            t = p[8]; p[8] = p[11]; p[11] = t;
            t = p[9]; p[9] = p[10]; p[10] = t;
            t = p[12]; p[12] = p[15]; p[15] = t;
            t = p[13]; p[13] = p[14]; p[14] = t;
            p += 16;
        }
    }
    return obj;
}

#pragma scheduling on
#pragma dont_inline reset
void fn_802C4C80(void* arg0) {
    if (arg0 == NULL) {
        return;
    }
    fn_8012C4D8();
}

s32 fn_802C4EE4(s32* arg0) {
    if (arg0 != NULL) {
        return *arg0;
    }
    return 0;
}

s32 fn_802C4EFC(s32* arg0) {
    if (arg0 != NULL) {
        return arg0[1];
    }
    return 0;
}

s32 fn_802C4F14(s32* arg0) {
    if (arg0 != NULL) {
        return arg0[4];
    }
    return 0;
}

void fn_802C4F2C(void *arg0, s32 *arg1, s32 *arg2) {
    if (arg0 == 0) {
        *arg2 = 0;
        *arg1 = 0;
    } else {
        *arg1 = *(s32 *)((u8 *)arg0 + 8);
        *arg2 = *(s32 *)((u8 *)arg0 + 0xC);
    }
}

#pragma push
#pragma inline_depth(0)
void fn_802C4F58(s32 arg0, s32 arg1, const char *arg2, s32 arg3) {
    s32 var_r31 = arg3;
    const char *var_r30 = arg2;
    s32 var_r29 = arg1;
    s32 var_r28 = arg0;
    s32 ch;
    while ((ch = (s8)*var_r30++) != 0) {
        if ((s8)ch < 0x20 || (u8)ch > 0x7F)
            fn_802C5024(var_r28, var_r29, 0x23, var_r31);
        else
            fn_802C5024(var_r28, var_r29, ch, var_r31);
        var_r28 += 8;
    }
}
#pragma pop
extern unsigned int strlen(const char *);
unsigned int fn_802C4FF8(const char *s) { return strlen(s) * 8; }

int fn_802C501C(void) {
    return 8;
}

void fn_802C5024(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {}
extern const char lbl_8034B060[];
extern void fn_802C3320();
extern void fn_802C33A8();
extern void fn_802E317C(const char *, ...);
extern void fn_802C3850();
extern const char lbl_8034B078[];
extern void fn_802C3918(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3C68(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3D74(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802C3F00(s32,s32,s32,s32,s32,s32,s32,s32);
extern void fn_802DB2C8(void);
extern void fn_802C3478(s32, s32, s32, s32, u32);
extern void fn_802C365C(s32, s32, s32, s32, u32);
extern void fn_802C356C(s32, s32, s32, s32, u32);
