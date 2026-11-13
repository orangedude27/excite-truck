#include <types.h>
struct E7FC { char pad[0x28]; int v28; unsigned int v30; };
extern "C" int sprintf(char *, const char *, ...);
extern "C" s32 lbl_80559984;
extern "C" char lbl_805599AC[];
extern "C" void fn_801282F4(void);
extern "C" void fn_801284F0(void *, void *);
extern "C" s32 fn_802E36D8(void);
extern "C" void fn_802E3A14(s32, s32);
extern "C" s32 fn_802E3804(s32, void *, s32);
extern "C" void fn_802E3734(s32 *);
extern "C" s8 lbl_8055DFF8;
extern "C" u8 lbl_805599B8;
extern "C" const char lbl_8032AE9C[];
extern "C" void fn_8012BEF0(s32);
extern "C" void fn_8012DBD0(void);
extern "C" s32 lbl_8055DFFC;
extern "C" const char lbl_8032AE60[];
extern "C" const char lbl_8032A8E8[];
extern "C" void fn_8012C4D8(void *);
extern "C" s32 fn_80128668(void *);
struct Fn8012AFE0Ent { u8 pad[0x34]; u32 flags; u8 pad2[0xC]; };
extern "C" const char lbl_8032ADF4[];
extern "C" const char lbl_8032AE20[];
extern "C" void fn_80128660(s32);
extern "C" s32 fn_802E748C(s32, s32, void *);
extern "C" s32 fn_802E2C20(void);
extern "C" void fn_8002B0D8(char *);
extern "C" char *fn_80029004(char *, int);
extern "C" s32 fn_8012C370(s32, s32, s32, s32, s32, s32);
class Unk8012A570 { public: virtual ~Unk8012A570(); };

extern "C" s32 lbl_8055E004;
extern "C" void **lbl_8055E008;
extern "C" u32 lbl_805599A0;
extern "C" u8 lbl_8032A6F8[];
extern "C" s32 lbl_8055E00C;
extern "C" void **lbl_8055E010;
extern "C" u8 lbl_8032AC88[];
extern "C" u8 lbl_8032ACA0[];
extern "C" u8 lbl_8032ACD0[];
extern "C" u8 lbl_8032ACB0[];
namespace nw4r { namespace ef { class Effect; } }
extern "C" nw4r::ef::Effect *lbl_8055E014;
extern "C" void fn_80127CF4(s32, s32);
extern "C" void *fn_801284F8(u32, void *);
extern "C" void **fn_8012A13C(void *, void *, u32, u32);
extern "C" void *fn_8012A2D8(void **);
extern "C" void fn_8012A364(void **, void *);
extern "C" void *fn_8012A570(u32, void *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" s32 stricmp(const char *, const char *);
extern "C" s32 fn_8012B85C(s32, s32, s32, s32, s32, s32);
extern "C" const char lbl_805599A4[1];
extern "C" void *fn_8012B534(char *arg0, s32 *arg1, u32 arg2);
extern "C" void fn_80127464(void);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void fn_802E317C(const char *, ...);
extern "C" const char lbl_8032AB78[];
extern "C" u8 lbl_8055DFF9;
extern "C" void *lbl_8055E000;
extern "C" s32 fn_8012BC50(void *, void *, s32);
extern "C" s32 fn_8012E9F0(s32, s32);
extern "C" const char lbl_8032AD88[];
extern "C" const char lbl_8032AD6C[];
extern "C" const char lbl_8032AD2C[];
extern "C" const char lbl_8032ADA0[];
extern "C" const char lbl_8032ADDC[];

extern "C" void *fn_8012CB44(void *, s32);
extern "C" void fn_8012CA40(void *);
extern "C" void fn_8012E67C(s32, s32);
extern "C" void fn_8012E5E4(void *, void *);
extern "C" void fn_8012E630(void *);
extern "C" s32 fn_8012E674(void *);
extern "C" void fn_8012D3D8(s32);
extern "C" void fn_8012D8A8(s32);
extern "C" void *fn_801282EC(u32);
extern "C" void *fn_8012850C(u32, void *);
extern "C" void *memset(void *, s32, u32);
extern "C" u8 lbl_805599C8;
extern "C" u8 lbl_805599D0;
extern "C" u8 lbl_805599E0;

extern "C" void fn_8012E498(void *);
extern void fn_8012CC24(void);
extern "C" u32 fn_8012D3D0(void);
/* fn_8012CC24: two args (object*, char* path list), returns s32. */
extern "C" void fn_8012D33C(u32 *, u32 *);
extern "C" void fn_8012D1A8(s32 arg0);
extern "C" s32 fn_8012D024(void *, s32, s32);

#pragma use_lmw_stmw off
extern "C" s32 fn_8012A388(void *arg0) {
    u8 t0; u8 t24; u8 t25; u8 t26; u8 t27; u8 t28; u8 t29; u8 t30; u8 t31; u8 t6;
    t6 = *(u8 *)((char *)arg0 + 0x24); t0 = *(u8 *)((char *)arg0 + 0x26);
    *(u8 *)((char *)arg0 + 0x24) = *(u8 *)((char *)arg0 + 0x27); t31 = *(u8 *)((char *)arg0 + 0x20);
    *(u8 *)((char *)arg0 + 0x27) = t6; t27 = *(u8 *)((char *)arg0 + 0x21);
    *(u8 *)((char *)arg0 + 0x26) = *(u8 *)((char *)arg0 + 0x25); t30 = *(u8 *)((char *)arg0 + 0x28);
    *(u8 *)((char *)arg0 + 0x25) = t0; t26 = *(u8 *)((char *)arg0 + 0x29);
    *(u8 *)((char *)arg0 + 0x21) = *(u8 *)((char *)arg0 + 0x22); t29 = *(u8 *)((char *)arg0 + 0x2C);
    t25 = *(u8 *)((char *)arg0 + 0x2D); t28 = *(u8 *)((char *)arg0 + 0x30); t24 = *(u8 *)((char *)arg0 + 0x31);
    *(u8 *)((char *)arg0 + 0x20) = *(u8 *)((char *)arg0 + 0x23); *(u8 *)((char *)arg0 + 0x23) = t31;
    *(u8 *)((char *)arg0 + 0x22) = t27; *(u8 *)((char *)arg0 + 0x28) = *(u8 *)((char *)arg0 + 0x2B);
    *(u8 *)((char *)arg0 + 0x2B) = t30; *(u8 *)((char *)arg0 + 0x29) = *(u8 *)((char *)arg0 + 0x2A);
    *(u8 *)((char *)arg0 + 0x2A) = t26; *(u8 *)((char *)arg0 + 0x2C) = *(u8 *)((char *)arg0 + 0x2F);
    *(u8 *)((char *)arg0 + 0x2F) = t29; *(u8 *)((char *)arg0 + 0x2D) = *(u8 *)((char *)arg0 + 0x2E);
    *(u8 *)((char *)arg0 + 0x2E) = t25; *(u8 *)((char *)arg0 + 0x30) = *(u8 *)((char *)arg0 + 0x33);
    *(u8 *)((char *)arg0 + 0x33) = t28; *(u8 *)((char *)arg0 + 0x31) = *(u8 *)((char *)arg0 + 0x32);
    *(u8 *)((char *)arg0 + 0x32) = t24; *(u32 *)((char *)arg0 + 0x38) = 0;
    *(u32 *)((char *)arg0 + 0x34) = 0; *(u32 *)((char *)arg0 + 0x24) &= 0xFFFF;
    return (s32)arg0;
}
#pragma use_lmw_stmw reset
extern "C" const char lbl_8032A630[];
extern "C" void fn_8012A46C(void *, const char *);
extern "C" s32 fn_80132E7C(void *, s32);
extern "C" void fn_8012A46C(void *, const char *) {

}

#pragma dont_inline on
#pragma use_lmw_stmw off
extern "C" s32 fn_8012A470(void *arg0, s32 arg1, void *arg2, void *arg3) {
    register const char *strings = lbl_8032A630;
    register char *buffer;
    s32 result;

    buffer = (char *)arg3 + *(s32 *)((char *)arg2 + 0x2C) - 8;
    *(void **)((char *)arg2 + 0x3C) = buffer;
    fn_8012A46C(buffer + 8, strings);
    result = (u32)__cntlzw((u32)*(s32 *)((char *)arg2 + 0x30) -
                           (u32)fn_80132E7C((char *)*(void **)((char *)arg2 + 0x3C) + 8,
                                            *(s32 *)((char *)arg2 + 0x28))) >> 5;
    if (result) {
        if (*(u32 *)((char *)arg2 + 0x34) & 8) {
            fn_802E30C8(strings + 0xC);
            fn_802E30C8(strings + 0x34);
            fn_802E30C8(strings + 0x5C);
            fn_802E30C8(strings + 0xC);
            fn_802E317C(strings + 0x88, arg0, arg1, arg2);
        }
        *(u32 *)((char *)arg2 + 0x34) |= 8;
    } else {
        fn_802E30C8(strings + 0xA8, arg0, arg1, arg2);
    }
    return result;
}
#pragma use_lmw_stmw reset
#pragma dont_inline reset
#pragma dont_inline on
extern "C" void *fn_8012A570(u32 arg0, void *arg1) {
    void *value;
    (void)arg0;
    (void)arg1;
    if (lbl_8055E004 == 0) {
        value = fn_801284F8(0x20, lbl_8032A6F8);
        if (value != 0) {
            value = (void *)fn_8012A13C(value, lbl_8032A6F8, 0x20, 0x18);
        }
        lbl_8055E008 = (void **)value;
    }
    void *p = fn_8012A2D8(lbl_8055E008);
    if (p != 0) {
        lbl_8055E004 += 1;
    }
    return p;
}
#pragma dont_inline reset
extern "C" void fn_8012A5E8(void *arg0) {
    fn_8012A364(lbl_8055E008, arg0);
    if (--lbl_8055E004 == 0) {
        delete (Unk8012A570 *)lbl_8055E008;
        lbl_8055E008 = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012A648(void) {
    void *p = fn_8012A570(0x18, &lbl_805599A0);
    fn_8012A364(lbl_8055E008, p);
}
#pragma pop
#pragma dont_inline reset
#pragma scheduling reset
#pragma dont_inline on
extern "C" void fn_8012A67C(void) {
    lbl_8055E004 = 0;
    delete (Unk8012A570 *)lbl_8055E008;
    lbl_8055E008 = 0;
}

#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_8012A6C8(s32 arg0, s32 arg1, s32 arg2) {
    /* Validates an RSTM/"RST0" header (magic, header size, version, and optional expected field) after running its 0x30-byte checksum/init; logs a mismatch and returns 0 on failure, 1 on success. */
    const char *messages = lbl_8032A630;
    u32 *header = (u32 *)arg0;
    volatile u8 magicText[5];
    u32 firstByte;
    u8 fourthByte;
    u32 secondByte;
    u8 thirdByte;
    u32 value;

    fn_80132E7C((void *)arg0, 0x30);
    value = header[0];
    if (value != 0x52535430) {
        *(volatile u32 *)magicText = 0x52535430;
        firstByte = magicText[0];
        fourthByte = magicText[3];
        secondByte = magicText[1];
        thirdByte = magicText[2];
        magicText[0] = fourthByte;
        magicText[3] = firstByte;
        magicText[1] = thirdByte;
        magicText[2] = secondByte;
        magicText[4] = 0;
        fn_802E30C8(messages + 0xDC, (const char *)arg1, value, (const char *)magicText);
        goto failed;
    }
    value = header[2];
    if (value != 8) {
        fn_802E30C8(messages + 0x114, (const char *)arg1, value, 8);
        goto failed;
    }
    value = header[1];
    if (value != 0x34) {
        fn_802E30C8(messages + 0x148, (const char *)arg1, value, 0x34);
        goto failed;
    }
    value = header[4];
    if (value != (u32)arg2 && arg2 != 0) {
        fn_802E30C8(messages + 0x180, (const char *)arg1, value, arg2);
        goto failed;
    }
    return 1;
failed:
    return 0;
}
#pragma pop
#pragma scheduling reset

extern "C" s32 fn_802E2D74(s32);
extern "C" s32 fn_802E39D0(s32, s32);
extern "C" void fn_8012A80C(s32);
extern "C" s32 fn_8012A6C8(s32, s32, s32);
extern "C" s32 fn_8012AB34(s32, s32, s32, s32);
extern "C" s32 fn_802E36D8(void);
extern "C" s32 fn_802E37C4(void);
extern "C" void fn_802E3734(s32 *);
extern "C" s32 fn_802E4CA8(void *, s32, s32);
extern "C" s32 fn_802E7354(void *);
extern "C" s32 fn_802E746C(s32, s32 *, s32 *);
#pragma scheduling off
extern "C" void fn_8012A7FC(void) {
    lbl_8055DFF9 = 1;
    fn_802E2D74(0x32);
}

static inline void Swap4(u8 *q) {
    u8 t = q[0]; q[0] = q[3]; q[3] = t;
    t = q[1]; q[1] = q[2]; q[2] = t;
}

extern "C" void fn_8012A80C(s32 arg0) {
    u8 *p=(u8 *)arg0;
    u8 a0=p[0],a1=p[1],a2=p[2],a3=p[3],a4=p[4],a5=p[5],a6=p[6],a7=p[7];
    u8 a8=p[8],a9=p[9],a10=p[10],a11=p[11],a12=p[12],a13=p[13],a14=p[14],a15=p[15];
    u8 a16=p[16],a17=p[17],a18=p[18],a19=p[19],a20=p[20],a21=p[21],a22=p[22],a23=p[23];
    u8 a24=p[24],a25=p[25],a26=p[26],a27=p[27],a28=p[28],a29=p[29],a30=p[30],a31=p[31];
    u8 a32=p[32],a33=p[33],a34=p[34],a35=p[35],a36=p[36],a37=p[37],a38=p[38],a39=p[39];
    u8 a40=p[40],a41=p[41],a42=p[42],a43=p[43],a44=p[44],a45=p[45],a46=p[46],a47=p[47];
    u8 a48=p[48],a49=p[49],a50=p[50],a51=p[51];
    p[0]=a3;p[1]=a2;p[2]=a1;p[3]=a0;p[4]=a7;p[5]=a6;p[6]=a5;p[7]=a4;
    p[8]=a11;p[9]=a10;p[10]=a9;p[11]=a8;p[12]=a15;p[13]=a14;p[14]=a13;p[15]=a12;
    p[16]=a19;p[17]=a18;p[18]=a17;p[19]=a16;p[20]=a23;p[21]=a22;p[22]=a21;p[23]=a20;
    p[24]=a27;p[25]=a26;p[26]=a25;p[27]=a24;p[28]=a31;p[29]=a30;p[30]=a29;p[31]=a28;
    p[32]=a35;p[33]=a34;p[34]=a33;p[35]=a32;p[36]=a39;p[37]=a38;p[38]=a37;p[39]=a36;
    p[40]=a43;p[41]=a42;p[42]=a41;p[43]=a40;p[44]=a47;p[45]=a46;p[46]=a45;p[47]=a44;
    p[48]=a51;p[49]=a50;p[50]=a49;p[51]=a48;
}

#pragma scheduling reset
extern "C" s32 fn_8012A388(void *);
extern "C" s32 fn_802E7544(s32);
extern "C" void fn_802E7548(s32);
extern "C" const char lbl_8032AC68[];
extern "C" s32 fn_8012A470(void *, s32, void *, void *);
extern "C" s32 fn_80132E7C(void *, s32);
extern "C" const char lbl_8032A7E8[];
extern int __cntlzw(unsigned int);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
extern "C" s32 fn_8012AA60(void *arg0, s32 arg1, s32 arg2) {
    s32 count;
    register s32 result;
    void *base;
    void *p;
    s32 i;

    count = *(s32 *)((char *)arg0 + 0x88);
    p = *(void **)((char *)arg0 + 0x60);
    result = *(s32 *)((char *)arg0 + 0x94);
    base = p;
    result = (u32)__cntlzw((u32)(fn_80132E7C(p, count * 0x44) - result)) >> 5;
    if (result != 0) {
        for (i = 0; i < count; i++) {
            fn_8012A388(p);
            if (*(s32 *)((char *)p + 0x2C) + *(s32 *)((char *)p + 0x28) <= arg1) {
                if (fn_8012A470(arg0, i, p, base) == 0) {
                    result = 0;
                    break;
                }
            }
            p = (char *)p + 0x44;
        }
    } else {
        fn_802E30C8(lbl_8032A7E8, arg0);
    }
    return result;
}
#pragma pop
extern "C" s32 fn_8012AB34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result = 0;
    if (((s32 (*)(s32, s32, s32))fn_802E39D0)(arg0, arg1, 0x34) != 0) {
        fn_8012A80C(arg1);
        result = fn_8012A6C8(arg1, arg2, arg3);
    }
    return result;
}

extern "C" s32 fn_8012ABB0(s32 arg0, s32 arg1) {
    s32 sp8 = fn_802E36D8();
    if (sp8 != -1 && fn_8012AB34(sp8, arg1, arg0, fn_802E37C4()) == 0) {
        fn_802E3734(&sp8);
        sp8 = -1;
    }
    return sp8;
}

extern "C" s32 fn_8012AC28(s32 arg0, s32 arg1) {
    u8 buffer[0x104];
    s32 spC;
    s32 sp8;
    s32 result;
    spC = -1;
    fn_802E4CA8(buffer, arg0, 0x104);
    result = fn_802E7354(buffer);
    if (result != -1) {
        fn_802E746C(result, &spC, &sp8);
        if (arg1 != 0) *(s32 *)arg1 = sp8;
    }
    return spC;
}

#pragma dont_inline reset

extern "C" void fn_8012AC98(s32 arg0) {
    fn_8012AC28(arg0, 0);
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8012ACA0(void *arg0, void *arg1, s32 arg2) {
    char sp10[128];
    s32 spC;
    u8 sp8;
    s32 var_r25, var_r5, var_r5_2;
    u32 var_r24, var_r26;
    char *var_r4, *var_r4_2, *var_r6, *var_r6_2;
    u8 temp_r3, temp_r3_2;
    u8 temp_r4, temp_r4_2, temp_r4_3, temp_r4_4, temp_r4_5;
    u8 temp_r4_6, temp_r4_7, temp_r4_8, temp_r4_9, temp_r4_10;
    u32 temp_r4_11;
    u8 *temp_r3_3, *temp_r26, *var_r25_2, *var_r31;
    u8 *messages = (u8 *)lbl_8032A630;
    if (lbl_8055DFFC == 0) fn_802E317C((const char *)(messages + 0x1D0), arg0);
    var_r4 = (char *)arg0; var_r6 = sp10; var_r5 = 0x80;
    goto loop_5_copy;
loop_5_limit:
    var_r5 -= 1;
    if (var_r5 > 0) goto loop_5_copy;
    var_r6[-1] = 0;
    goto loop_5_done;
loop_5_copy:
    temp_r3 = *var_r4++;
    *var_r6++ = temp_r3;
    if ((s8)temp_r3 != 0) goto loop_5_limit;
loop_5_done:
    if ((s8)*fn_80029004(sp10, 0x2E) != 0) *fn_80029004(sp10, 0x2E) = 0;
    var_r6_2 = sp10; var_r5_2 = 0x80;
    goto loop_10_test;
loop_10_step:
    var_r5_2 -= 1;
    var_r6_2 += 1;
loop_10_test:
    if ((s8)*var_r6_2 != 0) goto loop_10_step;
    if (var_r5_2 <= 0) goto loop_10_done;
    var_r4_2 = (char *)&lbl_805599E0;
    goto loop_15_copy;
loop_15_limit:
    var_r5_2 -= 1;
    if (var_r5_2 > 0) goto loop_15_copy;
    var_r6_2[-1] = 0;
    goto loop_10_done;
loop_15_copy:
    temp_r3_2 = *var_r4_2++;
    *var_r6_2++ = temp_r3_2;
    if ((s8)temp_r3_2 != 0) goto loop_15_limit;
loop_10_done:
    fn_8002B0D8(sp10);
    temp_r3_3 = (u8 *)fn_8012C370((s32)sp10, 0x45544F43, (s32)&spC, 0, 0, (s32)&sp8);
    if (temp_r3_3 != 0 && sp8 != 0) {
        temp_r4 = temp_r3_3[0]; temp_r3_3[0] = temp_r3_3[3]; temp_r3_3[3] = temp_r4;
        temp_r4_2 = temp_r3_3[1]; temp_r3_3[1] = temp_r3_3[2]; temp_r3_3[2] = temp_r4_2;
        temp_r4_3 = temp_r3_3[4]; temp_r3_3[4] = temp_r3_3[7]; temp_r3_3[7] = temp_r4_3;
        temp_r4_4 = temp_r3_3[5]; temp_r3_3[5] = temp_r3_3[6]; temp_r3_3[6] = temp_r4_4;
        temp_r4_5 = temp_r3_3[8]; temp_r3_3[8] = temp_r3_3[0xB]; temp_r3_3[0xB] = temp_r4_5;
        temp_r4_6 = temp_r3_3[9]; temp_r3_3[9] = temp_r3_3[0xA]; temp_r3_3[0xA] = temp_r4_6;
        temp_r4_7 = temp_r3_3[0xC]; temp_r3_3[0xC] = temp_r3_3[0xF]; temp_r3_3[0xF] = temp_r4_7;
        temp_r4_8 = temp_r3_3[0xD]; temp_r3_3[0xD] = temp_r3_3[0xE]; temp_r3_3[0xE] = temp_r4_8;
        temp_r4_9 = temp_r3_3[0x10]; temp_r3_3[0x10] = temp_r3_3[0x13]; temp_r3_3[0x13] = temp_r4_9;
        temp_r4_10 = temp_r3_3[0x11]; temp_r3_3[0x11] = temp_r3_3[0x12]; temp_r3_3[0x12] = temp_r4_10;
        temp_r4_11 = *(u32 *)temp_r3_3;
        if (temp_r4_11 != 0 || *(u32 *)(temp_r3_3 + 4) != 0x14)
            fn_802E317C(lbl_8032AE60, 0, 0, *(u32 *)(temp_r3_3 + 4), 0x14);
        var_r25_2 = temp_r3_3 + 0x14; var_r26 = 0;
        goto loop_23_test;
loop_23:
        fn_8012A388(var_r25_2);
        var_r25_2 += 0x44; var_r26 += 1;
loop_23_test:
        if (var_r26 < *(u32 *)(temp_r3_3 + 0xC)) goto loop_23;
    }
    if (temp_r3_3 == 0) fn_802E317C((const char *)(messages + 0x200), arg0);
    if (*(u32 *)((u8 *)arg0 + 0x7C) != *(u32 *)(temp_r3_3 + 8))
        fn_802E317C((const char *)(messages + 0x228), arg0);
    if (*(u32 *)((u8 *)arg0 + 0x88) != *(u32 *)(temp_r3_3 + 0xC))
        fn_802E317C((const char *)(messages + 0x258), arg0);
    if (*(u32 *)((u8 *)arg0 + 0x8C) != *(u32 *)(temp_r3_3 + 0x10))
        fn_802E317C((const char *)(messages + 0x288), arg0);
    temp_r26 = temp_r3_3 + 0x14; var_r31 = temp_r26; var_r25 = 1; var_r24 = 0;
    goto loop_37_test;
loop_37:
    if (*(s32 *)(var_r31 + 0x2C) + *(s32 *)(var_r31 + 0x28) <= arg2) {
        if (fn_8012A470(arg0, var_r24, var_r31, arg1) == 0) { var_r25 = 0; goto loop_37_done; }
    }
    var_r31 += 0x44; var_r24 += 1;
loop_37_test:
    if (var_r24 < *(u32 *)(temp_r3_3 + 0xC)) goto loop_37;
loop_37_done:
    *(void **)((u8 *)arg0 + 0x60) = temp_r26;
    *(void **)((u8 *)arg0 + 0x64) = temp_r3_3;
    return var_r25;
}

extern "C" void *fn_8012AFE0(void *arg0, void *arg1) {
    u32 buf[13];
    s32 handle;
    u8 *p = 0;
    u8 *name = (u8 *)arg0;
    u8 c;
    u8 *src;
    s32 n;
    u8 *dst;
    u8 c2;
    s32 n2;
    u8 *dst2;
    s32 size;
    s32 data;
    s32 var_r31;
    s32 res;

    handle = ((s32 (*)(void *, void *))fn_8012ABB0)(arg0, buf);
    if (handle != -1) {
        p = (u8 *)fn_801284F8(0xB0, (void *)lbl_8032A8E8);
        if (p != 0) {
            var_r31 = ((s32 (*)(void *))fn_8012AC98)(name);
            p[0xAC] = 0;
            src = (u8 *)arg1; dst = p; n = 0x20;
            goto copy1;
limit1:
            n -= 1;
            if (n > 0) goto copy1;
            dst[-1] = 0;
            goto done1;
copy1:
            c = *src++; *dst++ = c;
            if ((s8)c != 0) goto limit1;
done1:
            dst2 = p + 0x20; n2 = 0x40;
            goto copy2;
limit2:
            n2 -= 1;
            if (n2 > 0) goto copy2;
            dst2[-1] = 0;
            goto done2;
copy2:
            c2 = *name++; *dst2++ = c2;
            if ((s8)c2 != 0) goto limit2;
done2:
            *(s32 *)(p + 0xA8) = 0;
            *(s32 *)(p + 0x60) = 0;
            if (buf != 0) {
                *(u32 *)(p + 0x68) = buf[0];
                *(u32 *)(p + 0x6C) = buf[1];
                *(u32 *)(p + 0x70) = buf[2];
                *(u32 *)(p + 0x74) = buf[3];
                *(u32 *)(p + 0x78) = buf[4];
                *(u32 *)(p + 0x7C) = buf[5];
                *(u32 *)(p + 0x80) = buf[6];
                *(u32 *)(p + 0x84) = buf[7];
                *(u32 *)(p + 0x88) = buf[8];
                *(u32 *)(p + 0x8C) = buf[9];
                *(u32 *)(p + 0x90) = buf[10];
                *(u32 *)(p + 0x94) = buf[11];
                *(u32 *)(p + 0x98) = buf[12];
            } else {
                memset(p + 0x68, 0, 0x34);
            }
            *(s32 *)(p + 0x9C) = 1;
            *(s32 *)(p + 0xA0) = 0;
            *(s32 *)(p + 0xA4) = var_r31;
            p[0xAC] = 1;
            *(s32 *)(p + 0x64) = 0;
            p[0xAD] = 0;
        }
        size = buf[9];
        fn_801282F4();
        fn_801282EC(0x80);
        data = (s32)((void *(*)(void *, s32))fn_801284F0)(arg1, size);
        fn_802E3A14(handle, *(s32 *)(p + 0x80));
        fn_802E3804(handle, (void *)data, size);
        *(s32 *)(p + 0xA0) = data;
        if (buf[3] & 1) {
            *(s32 *)(p + 0x60) = 0;
            res = fn_8012ACA0(p, (void *)data, size);
        } else {
            *(s32 *)(p + 0x60) = *(s32 *)(p + 0xA0);
            res = ((s32 (*)(void *, s32))fn_8012AA60)(p, size);
        }
        if (res == 0) {
            fn_8012A7FC();
            if (p != 0) {
                if (p[0xAC] != 0) {
                    var_r31 = 0;
                    n = 0;
                    while (var_r31 < *(s32 *)(p + 0x88)) {
                        u8 *e = (u8 *)*(void **)(p + 0x60) + n;
                        u32 fl = *(u32 *)(e + 0x34);
                        if (fl & 4) fn_802E317C(lbl_8032AE20);
                        var_r31 += 1;
                        e = (u8 *)*(void **)(p + 0x60) + n;
                        n += 0x44;
                        *(u32 *)(e + 0x34) = *(u32 *)(e + 0x34) & ~0xF;
                    }
                    if (*(s32 *)(p + 0x64) != 0) fn_8012C4D8(*(void **)(p + 0x64));
                    if (*(s32 *)(p + 0xA0) != 0) fn_80128660(*(s32 *)(p + 0xA0));
                    p[0xAC] = 0;
                }
                fn_80128668(p);
            }
            p = 0;
        }
        fn_802E3734(&handle);
    }
    return p;
}

#pragma pop
extern "C" int sprintf(char *, const char *, ...);
extern "C" s32 lbl_80559984;
extern "C" char lbl_805599AC[];
extern "C" s32 fn_8012B2C4(s32, s32, s32);
extern "C" void *fn_8012B314(s32 arg0, s32 arg1, s32 arg2) {
    return (void *)fn_8012B2C4(arg1, arg0, arg2);
}

extern "C" void fn_8012B324(void) {

}

extern "C" void fn_8012B328(void) {

}

extern "C" void *fn_8012AFE0(void *, void *);
extern char lbl_8032A960[];
#pragma scheduling invalid_target
/* Look up a named resource by iterating candidate nodes until fn_8012AFE0 resolves one (logs "res: loading %s"). */
extern "C" void *fn_8012B32C(const char *arg0) {
    u8 scratch[0x48];
    void *result = 0;
    s32 index;
    void *node;

    fn_802E30C8(lbl_8032A960, arg0);
    index = 0;
    for (;;) {
        node = ((void *(*)(void *, void *, s32))fn_8012B314)((void *)arg0, scratch, index);
        if (node == 0)
            break;
        result = fn_8012AFE0(node, (void *)arg0);
        if (result != 0) {
            ((void (*)(void))fn_8012B328)();
            break;
        }
        ((void (*)(void *))fn_8012B324)(node);
        index += 1;
    }
    return result;
}
#pragma scheduling on

extern "C" char *fn_80029004(char *, int);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012B3D4(char *arg0, int arg1, char *arg2, int arg3, char *arg4) {
    /* Splits path in arg4 at the last '/': copies directory part to arg0 (arg1 bytes max)
       and filename part to arg2 (arg3 bytes max). If no '/', arg0 becomes empty and arg2 gets the whole path. */
    char *src;
    char *dst;
    char *slash;
    int count;

    src = arg4;
    dst = arg0;
    count = arg1;
    while ((signed char)(*dst++ = *src++) != 0) {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }

    slash = fn_80029004(arg0, 0x2F);
    if (slash != 0) {
        *slash = 0;
        src = slash + 1;
        dst = arg2;
        count = arg3;
        while ((signed char)(*dst++ = *src++) != 0) {
            if (--count <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    } else {
        *arg0 = 0;
        src = arg4;
        dst = arg2;
        count = arg3;
        while ((signed char)(*dst++ = *src++) != 0) {
            if (--count <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    }
}
#pragma pop

#pragma scheduling invalid_target
extern "C" u8 *fn_8012B4E4(u8 *arg0, s8 *arg1) {
    s8 ch = (s8)*arg0;
    *arg1 = (s8)(ch - 0x2A == 0);
    if (ch == 0x2A)
        return arg0 + 1;
    return arg0;
}
#pragma scheduling on
extern "C" s32 fn_8012B50C(void *arg0, void *arg1) {
    if ((*(u32 *)((char *)arg0 + 0x34) & 0x20) &&
        (*(u32 *)((char *)arg1 + 0x34) & 0x10)) return 1;
    return 0;
}

extern "C" const char lbl_8032A970[];
extern "C" const char lbl_8032A99C[];
extern "C" u8 lbl_805599B4;
extern "C" void fn_8012D908(s32);
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
/* Finds a resource manager/entry by parsed path and name, handling wildcards, duplicate-name
 * warnings, and flags controlling "not ready" and missing-resource behavior. */
extern "C" void *fn_8012B534(char *arg0, s32 *arg1, u32 arg2) {
    u8 wildcard;
    char name[0x100];
    char dir[0x100];
    s32 flag0;
    s32 flag1;
    u8 *result;
    s32 offset;
    u8 *manager;
    s32 index;

    flag0 = arg2 & 1;
    flag1 = (arg2 >> 1) & 1;
    arg0 = (char *)fn_8012B4E4((u8 *)arg0, (s8 *)&wildcard);
    fn_8012B3D4(dir, 0x100, name, 0x100, arg0);
    if (wildcard != 0 && (s8)dir[0] == 0) {
        fn_802E30C8(lbl_8032A970, arg0);
    }
    *arg1 = -1;
    result = 0;
    for (manager = (u8 *)lbl_8055E000; manager != 0; manager = *(u8 **)(manager + 0xA8)) {
        if ((s8)dir[0] == 0 || stricmp((char *)manager, dir) == 0) {
            for (index = 0, offset = 0; index < *(s32 *)(manager + 0x88); offset += 0x44, index++) {
                if (stricmp((char *)(*(u8 **)(manager + 0x60) + offset), name) == 0) {
                    if (*arg1 != -1) {
                        fn_8012B50C((char *)*(u8 **)(result + 0x60) + *arg1 * 0x44,
                                    (char *)*(u8 **)(manager + 0x60) + offset);
                    } else {
                        result = manager;
                        *arg1 = index;
                    }
                }
            }
        }
    }
    if (result != 0 && *(u8 *)(result + 0xAD) != 0 && flag1 == 0) {
        fn_802E317C(lbl_8032A99C, result != 0 ? (char *)result : (char *)&lbl_805599B4, arg0);
    }
    if (flag0 == 0 && result != 0 && wildcard == 0 &&
        (*(u32 *)(*(u8 **)(result + 0x60) + *arg1 * 0x44 + 0x34) & 8) == 0) {
        result = 0;
    }
    if (result == 0 && flag1 == 0) {
        fn_8012D908((s32)arg0);
    }
    return result;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling on
extern "C" s32 fn_8012B6FC(void *arg0, s32 arg1) {
    s32 size2;
    u8 *entry;
    u8 *header;
    void *object;
    s32 handle;
    s32 startTime;
    u32 flags;
    const char *strings;
    s32 size;
    entry = (u8 *)*(void **)((u8 *)arg0 + 0x60) + arg1 * 0x44;
    flags = *(u32 *)(entry + 0x34);
    strings = lbl_8032A630;
    if (!(flags & 8)) {
        size2 = (size = *(s32 *)(entry + 0x28)) + 0x80;
        ((void (*)(s32))fn_801282F4)(size);
        size = 0x80;
        fn_801282EC(size);
        object = ((void *(*)(void *, s32))fn_801284F0)(entry, size2);
        if (object != 0) {
            startTime = fn_802E2C20();
            handle = ((s32 (*)(void *))fn_802E36D8)((u8 *)arg0 + 0x20);
            if (handle != -1) {
                *(void **)((u8 *)object + 0x78) = entry;
                *(u32 *)((u8 *)object + 0x7C) = 0x4D474921;
                header = (u8 *)object + 0x78;
                fn_802E3A14(handle, *(s32 *)(entry + 0x2C) + *(s32 *)((u8 *)arg0 + 0x80));
                fn_802E3804(handle, header + 8, *(s32 *)(entry + 0x28));
                if (*(u32 *)(entry + 0x30) == (u32)fn_80132E7C(header + 8, *(s32 *)(entry + 0x28))) {
                    flags = *(u32 *)(entry + 0x34) | 0xC;
                    *(u32 *)(entry + 0x34) = flags;
                    *(void **)(entry + 0x3C) = header;
                    *(void **)(entry + 0x40) = object;
                    ((void (*)(void *, const char *))fn_8012A46C)(header + 8, strings + 0x3B0);
                    fn_802E30C8(strings + 0x3C0, arg0, entry, fn_802E2C20() - startTime);
                } else {
                    fn_802E30C8(strings + 0x3E4, entry);
                    fn_8012A7FC();
                }
                fn_802E3734(&handle);
            }
            flags = *(u32 *)(entry + 0x34);
            if (!(flags & 8)) {
                fn_80128660((s32)object);
            }
        }
    }
    flags = *(u32 *)(entry + 0x34);
    return (flags >> 3) & 1;
}

#pragma scheduling invalid_target
extern "C" s32 fn_8012B85C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 sp8;
    volatile u8 requestName[5];
    volatile u8 entryName[5];
    u8 *manager;
    const char *strings = lbl_8032A630;
    u8 *result = 0;
    manager = ((u8 *(*)(s32, s32 *, s32))fn_8012B534)(arg0, &sp8, 0);
    if (manager != 0) {
        if (fn_8012B6FC(manager, sp8) != 0) {
            u8 *entry = *(u8 **)(manager + 0x60) + sp8 * 0x44;
            if ((u32)arg1 == *(u32 *)(entry + 0x20)) {
                s32 flags;
                s32 count;
                *(u32 *)(entry + 0x34) |= 2;
                if ((s8 *)arg5 != 0) {
                    flags = *(s32 *)(entry + 0x34);
                    *(s32 *)(entry + 0x34) = flags | 1;
                    *(s8 *)arg5 = !(flags & 1);
                }
                if ((s32 *)arg3 != 0) *(s32 *)arg3 = *(s32 *)(entry + 0x28);
                if ((s8 *)arg4 != 0) *(s8 *)arg4 = *(s32 *)(entry + 0x38) == 0;
                count = *(s32 *)(entry + 0x38);
                *(s32 *)(entry + 0x38) = count + 1;
                if (count == 0) {
                    *(u32 *)(*(u8 **)(entry + 0x3C) + 4) = 0x4D474921;
                    **(u8 ***)(entry + 0x3C) = entry;
                }
                *(s32 *)arg2 = *(s32 *)(entry + 0x24);
                result = *(u8 **)(entry + 0x3C) + 8;
                ((void (*)(void *, const char *))fn_8012A46C)(result, strings + 0x408);
            } else {
                u8 *request = (u8 *)requestName;
                u32 first;
                u8 fourth;
                u32 second;
                u8 third;
                *(volatile u32 *)request = arg1;
                first = requestName[0];
                fourth = requestName[3];
                second = requestName[1];
                third = requestName[2];
                requestName[0] = fourth;
                requestName[3] = first;
                requestName[1] = third;
                requestName[2] = second;
                requestName[4] = 0;
                *(volatile u32 *)entryName = *(u32 *)(entry + 0x20);
                first = entryName[0];
                fourth = entryName[3];
                second = entryName[1];
                third = entryName[2];
                entryName[0] = fourth;
                entryName[3] = first;
                entryName[1] = third;
                entryName[2] = second;
                entryName[4] = 0;
                fn_802E30C8(strings + 0x414, arg0, (const char *)request, (const char *)entryName);
            }
        } else {
            fn_802E30C8(strings + 0x450, arg0);
        }
    }
    return (s32)result;
}
#pragma scheduling on

#pragma dont_inline reset
#pragma scheduling reset
#pragma pop

extern "C" const char lbl_8032A630[];
extern "C" const char lbl_805599A4[1];
extern "C" s32 strstr(const char *, const char *);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012BA1C(void *arg0) {
    const char *strings = lbl_8032A630;
    s32 offset, i;
    s32 j, offset2;
    register s32 value;
    register u8 *entry;
    register u32 flags;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((char *)arg0 + 0x88)) {
        entry = *(u8 **)((char *)arg0 + 0x60) + offset;
        value = *(s32 *)(entry + 0x38);
        if (value > 0) fn_802E30C8(strings + 0x470, arg0);
        offset += 0x44;
        i++;
    }
    if (strstr((const char *)arg0, &lbl_805599A4[0]) != 0 && stricmp((const char *)arg0, strings + 0x4A0) != 0) {
        j = 0;
        offset2 = 0;
        while (j < *(s32 *)((char *)arg0 + 0x88)) {
            entry = *(u8 **)((char *)arg0 + 0x60) + offset2;
            flags = *(u32 *)(entry + 0x34);
            if ((flags & 0xA) == 8) fn_802E30C8(strings + 0x4AC, arg0);
            offset2 += 0x44;
            j++;
        }
    }
}
#pragma pop
extern "C" void fn_8012BC24(void **, void *);
extern "C" void fn_8012C4D8(void *);
extern "C" s32 fn_80128668(void *);
extern "C" u32 fn_8012BB18(void) { return 1; }

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012BB20(s32 arg0, void *arg1) {
    s32 i;
    s32 offset;
    u32 flags;
    u8 *entry;

    if (((u32 (*)(void *))fn_8012BB18)(arg1) == 0) return;
    fn_8012BA1C(arg1);
    fn_8012BC24((void **)arg0, arg1);
    if (arg1 == 0) return;
    if (*(u8 *)((u8 *)arg1 + 0xAC) != 0) {
        for (i = 0, offset = 0; i < *(s32 *)((u8 *)arg1 + 0x88); i++) {
            entry = *(u8 **)((u8 *)arg1 + 0x60) + offset;
            flags = *(u32 *)(entry + 0x34);
            if ((flags & 4) != 0) {
                fn_802E317C(lbl_8032AE20);
            }
            entry = *(u8 **)((u8 *)arg1 + 0x60) + offset;
            flags = *(u32 *)(entry + 0x34);
            offset += 0x44;
            *(u32 *)(entry + 0x34) = flags & 0xFFFFFFF0;
        }
        if (*(s32 *)((u8 *)arg1 + 0x64) != 0) {
            fn_8012C4D8(*(void **)((u8 *)arg1 + 0x64));
        }
        if (*(s32 *)((u8 *)arg1 + 0xA0) != 0) {
            fn_80128660(*(s32 *)((u8 *)arg1 + 0xA0));
        }
        *(u8 *)((u8 *)arg1 + 0xAC) = 0;
    }
    fn_80128668(arg1);
}

#pragma pop
extern "C" void fn_8012BC24(void **arg0, void *arg1) {
    void **var = arg0;
    while (*var != 0) {
        if (*var == arg1) {
            *var = *(void **)((char *)arg1 + 0xA8);
            return;
        }
        var = (void **)((char *)*var + 0xA8);
    }
}

extern "C" const char lbl_8032AAFC[];
#pragma scheduling reset
/* Decrement a control block's refcount and invoke a release callback/cleanup when it reaches zero. */
extern "C" s32 fn_8012BC50(void *ownerPtr, void *onRelease, s32 releaseArg) {
    struct Struct8012BC50 {
        u8 pad[0x34];
        u32 f0 : 28;
        u32 f1 : 2;
        u32 f2 : 1;
        u32 f3 : 1;
        s32 field_38;
        s32 field_3c;
        s32 field_40;
    };
    u8 *controlBlock = *(u8 **)((u8 *)ownerPtr - 8);
    if (controlBlock == NULL) {
        return 0;
    }
    if (*(s32 *)(controlBlock + 0x38) != 0) {
        *(s32 *)(controlBlock + 0x38) -= 1;
    } else {
        fn_802E30C8(lbl_8032AAFC, controlBlock);
    }
    if (*(s32 *)(controlBlock + 0x38) == 0) {
        if (onRelease != NULL) {
            ((void (*)(void *, s32))onRelease)(ownerPtr, releaseArg);
        }
        if (*(u32 *)(controlBlock + 0x34) & 4) {
            register Struct8012BC50 *releaseState = (Struct8012BC50 *)controlBlock;
            fn_80128660(releaseState->field_40);
            releaseState->f1 = 0;
            releaseState->field_40 = 0;
            releaseState->field_3c = 0;
            releaseState->f3 = 0;
        }
    }
    return *(s32 *)(controlBlock + 0x38) == 0;
}
extern "C" void *fn_8012BD3C(void *arg0, const char *arg1) {
    void *entry = arg0;
    goto test;
body:
    if (stricmp(arg1, (const char *)entry) == 0) goto done;
    entry = *(void **)((char *)entry + 0xA8);
test:
    if (entry != 0) goto body;
done:
    return entry;
}

extern "C" void *fn_8012B32C(const char *);
extern "C" void fn_8012748C(s32);
extern "C" const char lbl_8032AB2C[];
extern "C" const char lbl_8032AB58[];
#pragma scheduling invalid_target
extern "C" void *fn_8012BD98(const char *arg0, void **arg1, s32 arg2) {
    void *p;
    s32 tries;
    s32 zero;
    p = fn_8012BD3C(*arg1, arg0);
    if (p == 0) {
        tries = 0;
        zero = 0;
        do {
            lbl_8055DFF9 = (u8)zero;
            p = fn_8012B32C(arg0);
            if (p != 0) {
                *(void **)((char *)p + 0xA8) = *arg1;
                *arg1 = p;
            } else if (lbl_8055DFF9 != 0) {
                fn_802E30C8(lbl_8032AB2C, arg0);
                fn_80127464();
            }
            if (lbl_8055DFF9 != 0 && p == 0) ++tries;
            else break;
        } while (tries < 10);
        if (p == 0) {
            fn_802E30C8(lbl_8032AB58, arg0);
            fn_8012748C(2);
        }
    } else ++*(s32 *)((char *)p + 0x9C);
    return p;
}
extern "C" s32 fn_8012BE90(void) {
    fn_8012A648();
    lbl_8055DFF8 = 1;
    void *p = fn_801284F8(1, &lbl_805599B8);
    if (p)
        fn_8012BEF0((s32)lbl_8032AE9C);
    lbl_8055DFFC = (s32)p;
    fn_8012DBD0();
    return 1;
}
#pragma scheduling on

#pragma use_lmw_stmw reset
#pragma dont_inline reset
#pragma scheduling reset
extern "C" void fn_8012DDA8(s32);
extern "C" void fn_8012E81C(s32);
extern "C" void fn_8012BEF0(s32 arg0) {
    fn_8012DDA8(arg0);
    fn_8012E81C(arg0);
}

extern "C" void fn_8012E498(void *);
extern "C" void fn_8012BF24(void *arg0) {
    fn_8012E498(arg0);
}

extern "C" s32 fn_802E3BB4(s32, char *, s32);
extern "C" void fn_802E3A14(s32, s32);
extern "C" s32 fn_802E3804(s32, void *, s32);
extern "C" s32 fn_802E3C24(s32, char *, s32);
extern "C" void fn_802E3CA4(s32);
extern "C" void fn_8012C4D8(void *);
extern "C" s32 lbl_802F8E50[3];
extern "C" const char lbl_8032AF4C[];
extern "C" const char lbl_8032AF0C[];
extern "C" const char lbl_8032AEF4[];
extern "C" const char lbl_8032AED4[];
extern "C" const char lbl_8032AEB4[];
extern "C" u8 lbl_805599D8;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus reset
extern "C" void fn_8012BF28(void) {
    s32 paths[3], header[5], inner, size;
    s32 *pathPtr, *table;
    u32 i;
    s32 handle;
    char filename[128], name[128];
    char *src_a1;
    s32 rem_s1;
    char *dst_s1;
    char *src_c;
    s32 rem_c;
    char *dst_c;
    char *src_a2;
    s32 rem_s2;
    char *dst_s2;
    u8 ch1, ch2;
    u8 ok;
    u8 *data;
    if (lbl_8055DFFC == 0) return;
    table = lbl_802F8E50;
    paths[0] = *table++; paths[1] = *table++; paths[2] = *table;
    pathPtr = paths; i = 0;
    do {
        s32 opened = fn_802E3BB4(*pathPtr, filename, 0x80);
        if ((u32)(opened + 0x10000) != 0xFFFF) {
            handle = opened;
            do {
                *fn_80029004(filename, '.') = 0;
                dst_s1 = filename; rem_s1 = 0x80; goto scan_test_1;
scan_step_1:
                --rem_s1; ++dst_s1;
scan_test_1:
                if ((s8)*dst_s1 != 0) goto scan_step_1;
                if (rem_s1 <= 0) goto suffix_done_1;
                src_a1 = (char *)&lbl_805599D8; goto append_1;
limit_1:
                --rem_s1; if (rem_s1 > 0) goto append_1; dst_s1[-1] = 0; goto suffix_done_1;
append_1:
                ch1 = *src_a1++; *dst_s1++ = ch1; if ((s8)ch1 != 0) goto limit_1;
suffix_done_1:
                inner = ((s32 (*)(char *))fn_802E36D8)(filename);
                if (inner != -1) {
                    fn_802E3A14(inner, 0x14); fn_802E3804(inner, header, 0x14);
                    if (header[0] == 0) {
                        src_c = filename; dst_c = name; rem_c = 0x80; goto copy_name_body;
copy_name_limit:
                        --rem_c; if (rem_c > 0) goto copy_name_body; dst_c[-1] = 0; goto copy_name_done;
copy_name_body:
                        ch2 = *src_c++; *dst_c++ = ch2; if ((s8)ch2 != 0) goto copy_name_limit;
copy_name_done:
                        ;
                        if ((s8)*fn_80029004(name, '.') != 0) *fn_80029004(name, '.') = 0;
                        dst_s2 = name; rem_s2 = 0x80; goto scan_test_2;
scan_step_2:
                        --rem_s2; ++dst_s2;
scan_test_2:
                        if ((s8)*dst_s2 != 0) goto scan_step_2;
                        if (rem_s2 <= 0) goto suffix_done_2;
                        src_a2 = (char *)&lbl_805599E0; goto append_2;
limit_2:
                        --rem_s2; if (rem_s2 > 0) goto append_2; dst_s2[-1] = 0; goto suffix_done_2;
append_2:
                        ch1 = *src_a2++; *dst_s2++ = ch1; if ((s8)ch1 != 0) goto limit_2;
suffix_done_2:
                        fn_8002B0D8(name);
                        data = (u8 *)fn_8012C370((s32)name, 0x45544F43, (s32)&size, 0, 0, (s32)&ok);
                        if (data != 0 && ok != 0) {
                            u8 t; u32 n; u8 *entry;
                            t=data[0]; data[0]=data[3]; data[3]=t; t=data[1]; data[1]=data[2]; data[2]=t;
                            t=data[4]; data[4]=data[7]; data[7]=t; t=data[5]; data[5]=data[6]; data[6]=t;
                            t=data[8]; data[8]=data[0xB]; data[0xB]=t; t=data[9]; data[9]=data[0xA]; data[0xA]=t;
                            t=data[0xC]; data[0xC]=data[0xF]; data[0xF]=t; t=data[0xD]; data[0xD]=data[0xE]; data[0xE]=t;
                            t=data[0x10]; data[0x10]=data[0x13]; data[0x13]=t; t=data[0x11]; data[0x11]=data[0x12]; data[0x12]=t;
                            u32 magic = *(u32 *)data; if (magic != 0 || *(u32 *)(data+4) != 0x14)
                                fn_802E317C(lbl_8032AE60, magic, 0, *(u32 *)(data+4), 0x14);
                            entry = data+0x14; n=0; while (n < *(u32 *)(data+0xC)) { fn_8012A388(entry); entry += 0x44; ++n; }
                        }
                        if (data != 0) {
                            if ((u32)header[2] != *(u32 *)(data+8)) {
                                if ((u32)header[3] == *(u32 *)(data+0xC)) {
                                    fn_802E30C8(lbl_8032AF4C, filename);
                                    *(u32 *)(data+8)=header[2]; *(u32 *)(data+0x10)=header[4];
                                    fn_802E3804(inner, data+0x14, header[3]*0x44);
                                } else fn_802E30C8(lbl_8032AF0C, filename);
                            }
                            fn_8012C4D8(data);
                        } else fn_802E30C8(lbl_8032AEF4, filename);
                    } else {
                        fn_802E30C8(lbl_8032AED4, filename); fn_802E3734(&inner); goto read_rest;
                    }
                } else fn_802E30C8(lbl_8032AEB4, filename);
read_rest:
                ;
            } while (fn_802E3C24(handle, filename, 0x80) != 0);
            fn_802E3CA4(handle);
        }
        ++pathPtr; ++i;
    } while (i < 3);
}
#pragma cplusplus on
extern "C" s32 fn_8012C33C(char *arg0) {
    s32 sp8;
    return fn_8012B534(arg0, &sp8, 0) != 0;
}

#pragma use_lmw_stmw off
extern "C" s32 fn_8012C370(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 result;
    s32 i = 0;
    do {
        lbl_8055DFF9 = 0;
        result = fn_8012B85C(arg0, arg1, arg2, arg3, arg4, arg5);
        if (lbl_8055DFF9 == 0 || result != 0)
            break;
        fn_802E30C8(lbl_8032AB78, arg0);
        fn_80127464();
        i++;
    } while (i < 10);
    return result;
}
/* Bit in struct ResEntry flags: the entry's resource is loaded/available
 * (fn_8012B534 rejects entries without it, fn_8012B6FC loads those that lack it). */
#define RES_ENTRY_LOADED 8

/* One entry of a resource manager's table (stride 0x44); the name is at +0x00
 * (fn_8012B534 compares it with stricmp). */
struct ResEntry {
    /* 0x00 */ char name[0x20];
    /* 0x20 */ void *data; /* per-type tag, e.g. 'SFX0' for sound effects */
    char pad24[4];
    /* 0x28 */ s32 size;
    char pad2C[8];
    /* 0x34 */ u32 flags;
    char pad38[0xC];
};

/* One resource manager in the global list lbl_8055E000; the manager's directory
 * name is the string at +0x00 and the list link is +0xA8. */
struct ResManager {
    /* 0x00 */ char dirName[0x60];
    /* 0x60 */ u8 *entries; /* struct ResEntry[entryCount], stride 0x44 */
    char pad64[0x24];
    /* 0x88 */ s32 entryCount;
    char pad8C[0x1C];
    /* 0xA8 */ struct ResManager *next;
};

#pragma push
#pragma use_lmw_stmw off
/* Walks the global resource-manager list (lbl_8055E000) and calls
 * callback(entry, entry->data, manager, userData) for every loaded entry
 * (RES_ENTRY_LOADED) of every manager whose directory matches dirName --
 * every manager when dirName is NULL. Stops at the first callback returning 0. */
extern "C" void fn_8012C41C(s32 (*callback)(void *, void *, void *, s32), s32 userData, const char *dirName) {
    s32 off;
    struct ResManager *manager;
    s32 i;
    for (manager = (struct ResManager *)lbl_8055E000; manager != NULL; manager = manager->next) {
        if (dirName == 0 || stricmp((const char *)manager, dirName) == 0) {
            i = 0;
            off = 0;
            while (i < manager->entryCount) {
                struct ResEntry *entry = (struct ResEntry *)(manager->entries + off);
                if (entry->flags & RES_ENTRY_LOADED) {
                    volatile void *param = entry->data;
                    if (callback(entry, (void *)param, manager, userData) == 0) return;
                }
                off += 0x44;
                i++;
            }
        }
    }
}
#pragma pop
extern "C" void fn_8012C4D8(void *arg0) {
    fn_8012BC50(arg0, 0, 0);
}

extern "C" void fn_8012CC20(void) {
    ((s32 (*)(void))(void *)&fn_8012CC24)();
}

#pragma dont_inline on
extern "C" s32 fn_8012CC24(void *arg0, void *arg1) {
    u8 *self = (u8 *)arg0;
    s32 sum, count, value, result, temp, handle, size, done;
    u32 *record;
    u8 *destination, *source, byte;
    void *parser;
    u8 parseBuffer[0x40];

    if (*(s32 *)(self + 0xB8) == 2 && fn_802E7544(*(s32 *)(self + 0xB4)) != 0 &&
        ((u32 (*)(void *))fn_8012D3D0)(arg0) != 0) {
        fn_802E7548(*(s32 *)(self + 0xB4));
        *(s32 *)(self + 0xB4) = -1;
        fn_8012D33C((u32 *)(self + 0x6C), (u32 *)*(void **)(self + 0xC8));
        fn_8012A80C((s32)(self + 0x6C));
        sum = *(s32 *)(self + 0x90) + *(s32 *)(self + 0x84);
        *(s32 *)(self + 0xA4) = 0;
        if (sum > *(s32 *)(self + 0xCC))
            fn_802E317C(lbl_8032ADF4);
        if (*(s32 *)(self + 0x78) & 1) {
            *(s32 *)(self + 0x64) = 0;
            result = ((s32 (*)(void *, void *, s32, s32))fn_8012ACA0)(
                self + 4, (u8 *)*(void **)(self + 0xC8) + *(s32 *)(self + 0x84),
                *(s32 *)(self + 0xC0) - *(s32 *)(self + 0x84), *(s32 *)(self + 0x84));
        } else {
            *(s32 *)(self + 0x64) = (s32)((u8 *)*(void **)(self + 0xC8) + *(s32 *)(self + 0x84));
            result = fn_8012AA60(self + 4, *(s32 *)(self + 0xC0) - *(s32 *)(self + 0x84),
                                 *(s32 *)(self + 0x84));
        }
        if (result != 0) {
            ((void (*)(void *))fn_8012B328)(self + 4);
            *(s32 *)(self + 0xAC) = (s32)lbl_8055E000;
            lbl_8055E000 = self + 4;
            *(s32 *)(self + 0xB8) = 3;
        } else {
            fn_8012D1A8((s32)arg0);
            ((void (*)(void *))fn_8012B324)(self + 0x24);
            value = *(s32 *)(self + 0xBC);
            *(s32 *)(self + 0xBC) = value + 1;
            fn_8012D024(arg0, (s32)(self + 4), value);
        }
    }
    switch (*(s32 *)(self + 0xB8)) {
    case 2:
    {
        s32 index;

        if (*(s32 *)(self + 0xB4) != -1) {
            fn_802E7548(*(s32 *)(self + 0xB4));
            *(s32 *)(self + 0xB4) = -1;
        }
        count = 0;
        index = 0;
        goto record_check_two;
    record_body_two:
        record = (u32 *)(*(s32 *)(self + 0x64) + index);
        if (record[0x34 / 4] & 4)
            fn_802E317C(lbl_8032AE20);
        count++;
        record = (u32 *)(*(s32 *)(self + 0x64) + index);
        index += 0x44;
        record[0x34 / 4] &= ~0xF;
    record_check_two:
        if (count < *(s32 *)(self + 0x8C))
            goto record_body_two;
        if (*(s32 *)(self + 0x68) != 0)
            fn_8012C4D8((void *)*(s32 *)(self + 0x68));
        if (*(s32 *)(self + 0xA4) != 0)
            fn_80128660(*(s32 *)(self + 0xA4));
        *(u8 *)(self + 0xB0) = 0;
        break;
    }
    case 3:
    {
        s32 index;

        fn_8012BA1C(self + 4);
        fn_8012BC24((void **)&lbl_8055E000, self + 4);
        count = 0;
        index = 0;
        goto record_check_three;
    record_body_three:
        record = (u32 *)(*(s32 *)(self + 0x64) + index);
        if (record[0x34 / 4] & 4)
            fn_802E317C(lbl_8032AE20);
        count++;
        record = (u32 *)(*(s32 *)(self + 0x64) + index);
        index += 0x44;
        record[0x34 / 4] &= ~0xF;
    record_check_three:
        if (count < *(s32 *)(self + 0x8C))
            goto record_body_three;
        if (*(s32 *)(self + 0x68) != 0)
            fn_8012C4D8((void *)*(s32 *)(self + 0x68));
        if (*(s32 *)(self + 0xA4) != 0)
            fn_80128660(*(s32 *)(self + 0xA4));
        *(u8 *)(self + 0xB0) = 0;
        break;
    }
    default:
        break;
    }
    *(s32 *)(self + 0xB8) = 1;
    *(s32 *)(self + 0xBC) = 0;
    done = 0;
    do {
        parser = ((void *(*)(void *, void *, s32))fn_8012B314)(arg1, parseBuffer,
                                                               *(s32 *)(self + 0xBC));
        if (!parser)
            goto func_exit;
        done = 0;
        temp = ((s32 (*)(void *, s32 *))fn_8012AC28)(parser, &size);
        if (temp != -1) {
            value = *(s32 *)(self + 0xCC);
            *(s32 *)(self + 0xC0) = value;
            if (value > *(s32 *)(self + 0xC0))
                goto parse_next;
            handle = ((s32 (*)(s32, void *))fn_802E748C)(temp, *(void **)(self + 0xC8));
            *(s32 *)(self + 0xB4) = handle;
            if (handle != -1) {
                *(s32 *)(self + 0xB8) = 2;
                source = (u8 *)arg1;
                destination = self + 4;
                {
                    s32 limit = 32;
                    goto copy_name_body;
                copy_name_limit:
                    limit--;
                    if (limit > 0)
                        goto copy_name_body;
                    destination[-1] = 0;
                    goto copy_name_done;
                copy_name_body:
                    byte = *source++;
                    *destination++ = byte;
                    if ((s8)byte != 0)
                        goto copy_name_limit;
                }
            copy_name_done:
                source = (u8 *)parser;
                destination = self + 0x24;
                {
                    s32 limit = 64;
                    goto copy_path_body;
                copy_path_limit:
                    limit--;
                    if (limit > 0)
                        goto copy_path_body;
                    destination[-1] = 0;
                    goto copy_path_done;
                copy_path_body:
                    byte = *source++;
                    *destination++ = byte;
                    if ((s8)byte != 0)
                        goto copy_path_limit;
                }
            copy_path_done:
                *(s32 *)(self + 0xAC) = 0;
                *(s32 *)(self + 0x64) = 0;
                memset(self + 0x6C, 0, 0x34);
                *(s32 *)(self + 0xA0) = 1;
                done = 1;
                *(s32 *)(self + 0xA4) = 0;
                *(s32 *)(self + 0xA8) = temp;
                *(u8 *)(self + 0xB0) = 1;
                *(s32 *)(self + 0x68) = 0;
                *(u8 *)(self + 0xB1) = 0;
                *(s32 *)self = fn_802E2C20() + *(s32 *)(self + 0xC0) / 3000 + 0x1F4;
            }
        }
    parse_next:
        *(s32 *)(self + 0xBC) = *(s32 *)(self + 0xBC) + 1;
    } while (!done);
func_exit:
    return done;
}

extern "C" s32 fn_8012D024(void *arg0, s32 arg1, s32 arg2) {
    s32 done = 0;
    u8 *parser;
    u8 *self = (u8 *)arg0;
    u8 byte;
    u8 *source;
    s32 limit;
    u8 *destination;
    u8 byte2;
    s32 limit2;
    u8 *destination2;
    u8 parseBuffer[0x40];
    s32 size;
    s32 temp;

    do {
        parser = ((u8 *(*)(void *, void *, s32))fn_8012B314)((void *)arg1, parseBuffer,
                                                              *(s32 *)(self + 0xBC));
        if (!parser)
            goto func_exit;
        done = 0;
        temp = ((s32 (*)(void *, s32 *))fn_8012AC28)(parser, &size);
        if (temp != -1) {
            s32 value = *(s32 *)(self + 0xCC);
            *(s32 *)(self + 0xC0) = value;
            if (value > *(s32 *)(self + 0xC0))
                goto parse_next;
            s32 handle = ((s32 (*)(s32, void *))fn_802E748C)(temp, *(void **)(self + 0xC8));
            *(s32 *)(self + 0xB4) = handle;
            if (handle != -1) {
                *(s32 *)(self + 0xB8) = 2;
                source = (u8 *)arg1;
                destination = self + 4;
                limit = 32;
                goto copy_name_body;
            copy_name_limit:
                limit--;
                if (limit > 0)
                    goto copy_name_body;
                destination[-1] = 0;
                goto copy_name_done;
            copy_name_body:
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte != 0)
                    goto copy_name_limit;
            copy_name_done:
                source = (u8 *)parser;
                destination2 = self + 0x24;
                limit2 = 64;
                goto copy_path_body;
            copy_path_limit:
                limit2--;
                if (limit2 > 0)
                    goto copy_path_body;
                destination2[-1] = 0;
                goto copy_path_done;
            copy_path_body:
                byte2 = *source++;
                *destination2++ = byte2;
                if ((s8)byte2 != 0)
                    goto copy_path_limit;
            copy_path_done:
                *(s32 *)(self + 0xAC) = 0;
                *(s32 *)(self + 0x64) = 0;
                memset(self + 0x6C, 0, 0x34);
                *(s32 *)(self + 0xA0) = 1;
                done = 1;
                *(s32 *)(self + 0xA4) = 0;
                *(s32 *)(self + 0xA8) = temp;
                *(u8 *)(self + 0xB0) = 1;
                *(s32 *)(self + 0x68) = 0;
                *(u8 *)(self + 0xB1) = 0;
                *(s32 *)self = fn_802E2C20() + *(s32 *)(self + 0xC0) / 3000 + 0x1F4;
            }
        }
    parse_next:
        *(s32 *)(self + 0xBC) = *(s32 *)(self + 0xBC) + 1;
    } while (!done);
func_exit:
    return done;
}

extern "C" s32 fn_802E748C(s32 arg0, s32 arg1, void *arg2);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012D024_old(void *arg0, s32 arg1, s32 arg2) {
    u8 sp80[0x80];
    void *parser;
    u8 sp8[8];
    u8 *path;
    s32 timestamp;
    s32 value;
    s32 result;
    u8 *source;
    u8 *destination;
    s32 limit;
    u8 byte;

    // Call fn_8012B314 to get parser
    parser = fn_8012B314(arg1, (s32)sp80, *(s32 *)((u8 *)arg0 + 0xBC));

    if (parser == NULL) {
        return;
    }

    // Call fn_8012AC28 to parse the record
    fn_8012AC28((s32)parser, (s32)sp8);
    result = *(s32 *)sp8;
    if (result == -1) {
        return;
    }

    // Load and store timestamp value
    value = *(s32 *)((u8 *)arg0 + 0xCC);
    *(s32 *)((u8 *)arg0 + 0xC0) = value;

    // Load handle from fn_802E748C
    result = fn_802E748C(result, *(s32 *)((u8 *)arg0 + 0xC8), NULL);
    *(s32 *)((u8 *)arg0 + 0xB4) = result;

    if (result != -1) {
        // Copy name from arg1 (pointer) to arg0+4
        source = (u8 *)arg1;
        destination = (u8 *)arg0 + 4;
        limit = 32;
        do {
            limit--;
            if (limit > 0) {
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte == 0) {
                    break;
                }
            } else {
                destination[-1] = 0;
                break;
            }
        } while (1);

        // Copy path from parser to arg0+0x24
        path = (u8 *)parser;
        destination = (u8 *)arg0 + 0x24;
        limit = 64;
        do {
            limit--;
            if (limit > 0) {
                byte = *path++;
                *destination++ = byte;
                if ((s8)byte == 0) {
                    break;
                }
            } else {
                destination[-1] = 0;
                break;
            }
        } while (1);

        // Clear memory with memset
        memset((u8 *)arg0 + 0x6C, 0, 0x34);

        // Calculate timestamp
        timestamp = fn_802E2C20();
        // timestamp += (0x57619f1 * value) >> 38 + sign correction
        s32 scaled = ((s64)0x57619f1 * (s64)value) >> 38;
        if (scaled < 0) {
            scaled++;
        }
        timestamp += (s32)scaled;
        timestamp += 0x1F4;

        *(s32 *)((u8 *)arg0 + 0) = timestamp;

        // Set some flags
        *(s32 *)((u8 *)arg0 + 0xBC) = *(s32 *)((u8 *)arg0 + 0xBC) + 1;
        *(s32 *)((u8 *)arg0 + 0xA0) = 1;
        *(s32 *)((u8 *)arg0 + 0xA4) = 0;
        *(s32 *)((u8 *)arg0 + 0xA8) = result;
        *(u8 *)((u8 *)arg0 + 0xB0) = 1;
        *(s32 *)((u8 *)arg0 + 0x68) = 0;
        *(u8 *)((u8 *)arg0 + 0xB1) = 0;
    }
}

extern "C" void fn_8012D1A8(s32 arg0) {
    u8 *self = (u8 *)arg0;
    s32 off;
    s32 i;
    switch (*(s32 *)(self + 0xB8)) {
    case 2:
        if (*(s32 *)(self + 0xB4) != -1) {
            fn_802E7548(*(s32 *)(self + 0xB4));
            *(s32 *)(self + 0xB4) = -1;
        }
        for (i = 0, off = 0; i < *(s32 *)(self + 0x8C); i++, off += 0x44) {
            if (((Fn8012AFE0Ent *)(*(s32 *)(self + 0x64) + off))->flags & 4) {
                fn_802E317C(lbl_8032AE20);
            }
            Fn8012AFE0Ent *e = (Fn8012AFE0Ent *)(*(s32 *)(self + 0x64) + off);
            e->flags &= ~0xF;
        }
        if (*(s32 *)(self + 0x68) != 0) {
            fn_8012C4D8((void *)*(s32 *)(self + 0x68));
        }
        if (*(s32 *)(self + 0xA4) != 0) {
            fn_80128660(*(s32 *)(self + 0xA4));
        }
        *(u8 *)(self + 0xB0) = 0;
        break;
    case 3:
        fn_8012BA1C(self + 4);
        fn_8012BC24((void **)&lbl_8055E000, self + 4);
        for (i = 0, off = 0; i < *(s32 *)(self + 0x8C); i++, off += 0x44) {
            if (((Fn8012AFE0Ent *)(*(s32 *)(self + 0x64) + off))->flags & 4) {
                fn_802E317C(lbl_8032AE20);
            }
            Fn8012AFE0Ent *e = (Fn8012AFE0Ent *)(*(s32 *)(self + 0x64) + off);
            e->flags &= ~0xF;
        }
        if (*(s32 *)(self + 0x68) != 0) {
            fn_8012C4D8((void *)*(s32 *)(self + 0x68));
        }
        if (*(s32 *)(self + 0xA4) != 0) {
            fn_80128660(*(s32 *)(self + 0xA4));
        }
        *(u8 *)(self + 0xB0) = 0;
        *(s32 *)(self + 0xB8) = 1;
        break;
    }
}

#pragma pop

extern "C" void fn_8012D33C(u32 *arg0, u32 *arg1) {
    u32 v4 = arg1[4];
    u32 v3 = arg1[3];
    u32 v2 = arg1[2];
    u32 v1 = arg1[1];
    u32 v0 = arg1[0];
    u32 v5 = arg1[5];
    u32 v6 = arg1[6];
    u32 v7 = arg1[7];
    u32 v8 = arg1[8];
    u32 v9 = arg1[9];
    u32 v10 = arg1[10];
    u32 v11 = arg1[11];
    u32 v12 = arg1[12];
    arg0[0] = v0;
    arg0[1] = v1;
    arg0[2] = v2;
    arg0[3] = v3;
    arg0[4] = v4;
    arg0[5] = v5;
    arg0[6] = v6;
    arg0[7] = v7;
    arg0[8] = v8;
    arg0[9] = v9;
    arg0[10] = v10;
    arg0[11] = v11;
    arg0[12] = v12;
}

extern "C" u32 fn_8012D3D0(void) { return 1; }

extern "C" void fn_8012D40C(s32);
extern "C" void fn_8012D1A8(s32 arg0);
extern "C" void fn_8012D3D8(s32 arg0) {
    fn_8012D40C(arg0);
    fn_8012D1A8(arg0);
}

#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8012D40C(s32 arg0) {
    u8 *self = (u8 *)arg0;
    s32 *object = (s32 *)self;
    s32 state, value, result, count, index, limit, done;
    s32 temp, handle, size;
    s32 *record;
    u8 *data, *source, *destination, byte;
    u8 *parser;
    u8 parseBuffer[0x40];
    state = object[0xB8 / 4];
    if (state == 2 && fn_802E7544(object[0xB4 / 4]) != 0) {
        fn_802E7548(object[0xB4 / 4]);
        object[0xB4 / 4] = -1;
        data = *(u8 **)(self + 0xC8);
        *(s32 *)(self + 0x6C) = *(s32 *)(data + 0);
        *(s32 *)(self + 0x70) = *(s32 *)(data + 4);
        *(s32 *)(self + 0x74) = *(s32 *)(data + 8);
        *(s32 *)(self + 0x78) = *(s32 *)(data + 12);
        *(s32 *)(self + 0x7C) = *(s32 *)(data + 16);
        *(s32 *)(self + 0x80) = *(s32 *)(data + 20);
        *(s32 *)(self + 0x84) = *(s32 *)(data + 24);
        *(s32 *)(self + 0x88) = *(s32 *)(data + 28);
        *(s32 *)(self + 0x8C) = *(s32 *)(data + 32);
        *(s32 *)(self + 0x90) = *(s32 *)(data + 36);
        *(s32 *)(self + 0x94) = *(s32 *)(data + 40);
        *(s32 *)(self + 0x98) = *(s32 *)(data + 44);
        *(s32 *)(self + 0x9C) = *(s32 *)(data + 48);
        fn_8012A80C((s32)(self + 0x6C));
        {
            s32 sum = object[0x90 / 4] + object[0x84 / 4];
            object[0xA4 / 4] = 0;
            if (sum > object[0xCC / 4])
                fn_802E317C(lbl_8032ADF4);
        }
        if (object[0x78 / 4] & 1) {
            s32 off = object[0x84 / 4];
            s32 arg2val = object[0xC0 / 4] - off;
            object[0x64 / 4] = 0;
            result = fn_8012ACA0(self + 4, (u8 *)*(void **)(self + 0xC8) + off, arg2val);
        } else {
            s32 off = object[0x84 / 4];
            s32 arg2val = object[0xC0 / 4] - off;
            object[0x64 / 4] = (s32)((u8 *)*(void **)(self + 0xC8) + off);
            result = fn_8012AA60(self + 4, arg2val, off);
        }
        if (result != 0) {
            ((void (*)(void *))fn_8012B328)(self + 4);
            object[0xAC / 4] = (s32)lbl_8055E000;
            lbl_8055E000 = self + 4;
            object[0xB8 / 4] = 3;
            return;
        }
    }
    state = object[0xB8 / 4];
    switch (state) {
    case 2:
        if (object[0xB4 / 4] != -1) {
            fn_802E7548(object[0xB4 / 4]);
            object[0xB4 / 4] = -1;
        }
        count = 0;
        index = 0;
        goto record_check_two;
    record_body_two:
        record = (s32 *)(object[0x64 / 4] + index);
        if (record[0x34 / 4] & 4)
            fn_802E317C(lbl_8032AE20);
        count++;
        record = (s32 *)(object[0x64 / 4] + index);
        value = record[0x34 / 4];
        index += 0x44;
        record[0x34 / 4] = value & ~0xF;
    record_check_two:
        if (count < object[0x8C / 4])
            goto record_body_two;
        if (object[0x68 / 4] != 0)
            fn_8012C4D8((void *)object[0x68 / 4]);
        if (object[0xA4 / 4] != 0)
            fn_80128660(object[0xA4 / 4]);
        *(u8 *)(self + 0xB0) = 0;
        break;
    case 3:
        fn_8012BA1C(self + 4);
        fn_8012BC24((void **)&lbl_8055E000, self + 4);
        count = 0;
        index = 0;
        goto record_check_three;
    record_body_three:
        record = (s32 *)(object[0x64 / 4] + index);
        if (record[0x34 / 4] & 4)
            fn_802E317C(lbl_8032AE20);
        count++;
        record = (s32 *)(object[0x64 / 4] + index);
        value = record[0x34 / 4];
        index += 0x44;
        record[0x34 / 4] = value & ~0xF;
    record_check_three:
        if (count < object[0x8C / 4])
            goto record_body_three;
        if (object[0x68 / 4] != 0)
            fn_8012C4D8((void *)object[0x68 / 4]);
        if (object[0xA4 / 4] != 0)
            fn_80128660(object[0xA4 / 4]);
        *(u8 *)(self + 0xB0) = 0;
        break;
    }
    object[0xB8 / 4] = 1;
    ((void (*)(void *))fn_8012B324)(self + 0x24);
    object[0xBC / 4]++;
    done = 0;
    while (!done) {
        parser = ((u8 *(*)(void *, void *, s32))fn_8012B314)(self + 4, parseBuffer, object[0xBC / 4]);
        if (!parser)
            return;
        temp = ((s32 (*)(s32, s32 *))fn_8012AC28)((s32)parser, &size);
        if (temp != -1) {
            value = object[0xCC / 4];
            object[0xC0 / 4] = value;
            if (value > value)
                goto parse_next;
            handle = ((s32 (*)(s32, void *))fn_802E748C)(temp, *(void **)(self + 0xC8));
            object[0xB4 / 4] = handle;
            if (handle != -1) {
                source = self + 4;
                destination = source;
                object[0xB8 / 4] = 2;
                limit = 32;
                goto copy_name_body;
            copy_name_limit:
                limit--;
                if (limit > 0)
                    goto copy_name_body;
                destination[-1] = 0;
                goto copy_name_done;
            copy_name_body:
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte != 0)
                    goto copy_name_limit;
            copy_name_done:
                source = parser;
                destination = self + 0x24;
                limit = 64;
                goto copy_path_body;
            copy_path_limit:
                limit--;
                if (limit > 0)
                    goto copy_path_body;
                destination[-1] = 0;
                goto copy_path_done;
            copy_path_body:
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte != 0)
                    goto copy_path_limit;
            copy_path_done:
                object[0xAC / 4] = 0;
                object[0x64 / 4] = 0;
                memset(self + 0x6C, 0, 0x34);
                object[0xA0 / 4] = 1;
                done = 1;
                object[0xA4 / 4] = 0;
                object[0xA8 / 4] = temp;
                *(u8 *)(self + 0xB0) = 1;
                object[0x68 / 4] = 0;
                *(u8 *)(self + 0xB1) = 0;
                object[0] = fn_802E2C20() + object[0xC0 / 4] / 3000 + 0x1F4;
            }
        }
    parse_next:
        object[0xBC / 4]++;
    }
}
#pragma scheduling on
#pragma dont_inline reset
extern "C" s32 fn_8012D838(s32 arg0) {
    s32 state;
    fn_8012D40C(arg0);
    state = *(s32 *)((u8 *)arg0 + 0xB8);
    switch (state) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    default:
        return 0;
    }
}

extern "C" void fn_8012D8A8(s32 arg0) {
    if (arg0 != 0) {
        fn_8012D40C(arg0);
        fn_8012D1A8(arg0);
        fn_80128660(*(s32 *)((char *)arg0 + 0xC8));
        *(s32 *)((char *)arg0 + 0xB8) = 0;
        fn_8012CB44((void *)(arg0 + 4), -1);
        fn_8012CA40((void *)arg0);
    }
}

// --- res: mounted resource sets and their on-disc "ETOC" tables -------------
//
// lbl_8055E014 is the external-TOC manager built by fn_8012DBD0 (0xA24 bytes):
// a pool of 0x20 mount nodes at +0x8 and the list of mounted sets at +0xA18.
// Every mounted set has a "<set>.toc" resource whose data is an ETOC block: a
// ResTocHeader followed by entryCount ResTocEntry records (fn_8012A388 knows an
// entry's fields).  The block is written little-endian, so its words are
// byte-reversed in place the first time it is read in.

#define RES_TOC_MANAGER ((ResTocManager *)lbl_8055E014)
#define RES_TOC_FOURCC 0x45544F43            // 'ETOC'
#define RES_TOC_HEADER_SIZE 0x14             // ResTocHeader must be this size
#define RES_TOC_ENTRY_SIZE 0x44              // one ETOC entry
#define RES_TOC_EXT_PATH ((char *)&lbl_805599E0)  // ".toc"

struct ResTocMount {  // one resource set whose load is in flight, 0x50 bytes
    void *poolNext;   // 0x00: next free node in the manager's pool (fn_8012E460)
    ResTocMount *next;
    s32 uses;         // 0x08: times this set has been asked for (fn_8012DDA8)
    char name[0x40];  // 0x0C: resource set name, e.g. "tracks"
    void *request;    // 0x4C: fn_8012CAA0 request reading the set (fn_8012DFE8)
};

struct ResTocMountList {
    ResTocMount *head;
    ResTocMount **tail;
};

struct ResTocManager {
    u8 unk_0x0[0xA18];         // +0x8: the 0x20-node pool, +0x18: its free list
    ResTocMountList mounts;    // the sets being loaded, in queue order
    u8 pumping;                // 0xA20: fn_8012DEE4 is working the queue
};

// fn_8012B534 could not find NAME (arg0) in any loaded resource table.  Ask
// every mounted set's on-disc ETOC table whether it lists NAME; if one does,
// the set is mounted but its resources have not been set yet, which is the
// "Get-Before-Wait" error the res-CRIP() message reports with the set's name.
extern "C" void fn_8012D908(s32 arg0) {
    char tocPath[128];
    s32 tocOffset;
    u8 startedLoad;
    char *nameSrc;
    s32 nameLeft;
    char *pathDst;
    char *extSrc;
    s32 extLeft;
    char *extDst;
    u8 c, c2;
    u8 swap0, swap1, swap2, swap3, swap4;
    u8 swap5, swap6, swap7, swap8, swap9;
    u32 tocVersion;
    ResTocMount *mount;
    ResTocMount *matched;
    u8 *toc;
    u32 nameIndex;
    u32 hasName;
    u32 entryIndex;
    u8 *nameEntry;
    u8 *entry;

    if (lbl_8055E014 == 0) return;  // no external-TOC manager yet
    mount = RES_TOC_MANAGER->mounts.head;
    matched = 0;
    goto mount_test;
mount_loop:
    // tocPath = "<set name>.toc", the resource holding this set's ETOC block
    nameSrc = mount->name; pathDst = tocPath; nameLeft = sizeof(tocPath);
    goto name_copy;
name_limit:
    nameLeft -= 1;
    if (nameLeft > 0) goto name_copy;
    pathDst[-1] = 0;
    goto name_done;
name_copy:
    c = *nameSrc++; *pathDst++ = c;
    if ((s8)c != 0) goto name_limit;
name_done:
    if ((s8)*fn_80029004(tocPath, '.') != 0) *fn_80029004(tocPath, '.') = 0;  // cut the set name's own extension
    extDst = tocPath; extLeft = sizeof(tocPath);
    goto ext_scan_test;
ext_scan_step:
    extLeft -= 1; extDst += 1;
ext_scan_test:
    if ((s8)*extDst != 0) goto ext_scan_step;  // walk to the end of the name
    if (extLeft <= 0) goto path_ready;
    extSrc = RES_TOC_EXT_PATH;
    goto ext_copy;
ext_limit:
    extLeft -= 1;
    if (extLeft > 0) goto ext_copy;
    extDst[-1] = 0;
    goto path_ready;
ext_copy:
    c2 = *extSrc++; *extDst++ = c2;
    if ((s8)c2 != 0) goto ext_limit;
path_ready:
    fn_8002B0D8(tocPath);  // map the path through the current character table
    // Read the set's ETOC resource; startedLoad is set when this call had to
    // start the read, so the block that came in is still little-endian.
    toc = (u8 *)fn_8012C370((s32)tocPath, RES_TOC_FOURCC, (s32)&tocOffset, 0, 0, (s32)&startedLoad);
    if (toc != 0 && startedLoad != 0) {
        // byte-reverse the ETOC header's five words
        swap0 = toc[0]; toc[0] = toc[3]; toc[3] = swap0;
        swap1 = toc[1]; toc[1] = toc[2]; toc[2] = swap1;
        swap2 = toc[4]; toc[4] = toc[7]; toc[7] = swap2;
        swap3 = toc[5]; toc[5] = toc[6]; toc[6] = swap3;
        swap4 = toc[8]; toc[8] = toc[0xB]; toc[0xB] = swap4;
        swap5 = toc[9]; toc[9] = toc[0xA]; toc[0xA] = swap5;
        swap6 = toc[0xC]; toc[0xC] = toc[0xF]; toc[0xF] = swap6;
        swap7 = toc[0xD]; toc[0xD] = toc[0xE]; toc[0xE] = swap7;
        swap8 = toc[0x10]; toc[0x10] = toc[0x13]; toc[0x13] = swap8;
        swap9 = toc[0x11]; toc[0x11] = toc[0x12]; toc[0x12] = swap9;
        tocVersion = *(u32 *)toc;
        if (tocVersion != 0 || *(u32 *)(toc + 4) != RES_TOC_HEADER_SIZE)
            fn_802E317C(lbl_8032AE60, tocVersion, 0, *(u32 *)(toc + 4), RES_TOC_HEADER_SIZE);

        entry = toc + RES_TOC_HEADER_SIZE; entryIndex = 0;
        goto entry_test;
entry_loop:
        fn_8012A388(entry);  // byte-reverse one entry
        entry += RES_TOC_ENTRY_SIZE; entryIndex += 1;
entry_test:
        if (entryIndex < *(u32 *)(toc + 0xC)) goto entry_loop;  // entryCount
    }
    nameEntry = toc + RES_TOC_HEADER_SIZE; hasName = 0; nameIndex = 0;
    goto name_test;
name_loop:
    if (stricmp((const char *)nameEntry, (const char *)arg0) == 0) {
        hasName = 1; goto name_found;
    }
    nameEntry += RES_TOC_ENTRY_SIZE; nameIndex += 1;
name_test:
    if (nameIndex < *(u32 *)(toc + 0xC)) goto name_loop;
name_found:
    if (hasName != 0) matched = mount;
    fn_8012C4D8(toc);  // release the ETOC resource again
    mount = mount->next;
mount_test:
    if (mount != 0 && matched == 0) goto mount_loop;
    if (matched != 0) fn_802E317C(lbl_8032ADA0, matched->name, (const char *)arg0);
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012DBD0(void) {
    /* Allocate and initialize the async set queue/effect object when enabled, then register it. */
    void *queue;
    s32 index;
    u32 slotOffset;
    s32 lastIndex;
    u32 *entryBase;
    u32 endAddress;

    if (lbl_8055DFFC != 0) {
        queue = fn_801284F8(0xA24, lbl_8032ACA0);
        if (queue != 0) {
            *(void **)queue = lbl_8032ACB0;
            *(s32 *)((char *)queue + 0xC) = 0x20;
            *(void ***)((char *)queue + 8) = (void **)((char *)queue + 0x18);
            *(void **)((char *)queue + 0x14) = 0;
            *(s32 *)((char *)queue + 0x10) = 0;
            index = 0;
            slotOffset = 0;
            goto loop_test;
        loop_body:
            entryBase = *(u32 * volatile *)((char *)queue + 8);
            *(u32 *)((char *)entryBase + slotOffset) = (u32)((char *)entryBase + (u32)(index + 1) * 0x50);
            slotOffset += 0x50;
            index += 1;
        loop_test:
            lastIndex = *(s32 *)((char *)queue + 0xC) - 1;
            if (index < lastIndex) goto loop_body;
            entryBase = *(u32 * volatile *)((char *)queue + 8);
            *(u32 *)((char *)entryBase + (u32)lastIndex * 0x50) = 0;
            endAddress = (u32)queue + 0xA18;
            entryBase = *(u32 * volatile *)((char *)queue + 8);
            *(u32 *)((char *)queue + 0x14) = (u32)entryBase;
            *(s32 *)((char *)queue + 0xA18) = 0;
            *(u32 *)((char *)queue + 0xA1C) = endAddress;
            fn_80127CF4((s32)queue, (s32)lbl_8032ACD0);
            *(u8 *)((char *)queue + 0xA20) = 0;
        }
        lbl_8055E014 = (nw4r::ef::Effect *)queue;
    }
}
#pragma pop

extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_8012DCC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern "C" void fn_80127E28(void *);
extern "C" void fn_80128660(s32);
extern "C" void fn_80128670(s32);
extern "C" void fn_8012C90C(void *);
extern "C" void fn_8012C958(void *);
extern "C" void *memcpy(void *, const void *, u32);
extern "C" u8 lbl_8032ACB0[];
namespace nw4r { namespace ef {
class Effect {
public:
    virtual ~Effect();
};
} }
extern "C" nw4r::ef::Effect *lbl_8055E014;

struct Unk8012DFCCNode {
    void *unk_0x0;
    Unk8012DFCCNode *next;
    s32 unk_0x8;
    char unk_0xC[0x40];
};
struct Unk8012DFCCList {
    Unk8012DFCCNode *head;
    Unk8012DFCCNode **tail;
};


extern "C" s32 fn_8012CAA0(s32, void * = 0);
#pragma dont_inline on
extern "C" void fn_8012DD00(void) {
    if (lbl_8055E014) {
        delete lbl_8055E014;
        lbl_8055E014 = 0;
    }
}

extern "C" void *__dt__Q34nw4r2ef6EffectFv(void *arg0, s32 arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_8032ACB0;
        fn_80127E28(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8012DFE8(void *, const char *, s32);
extern "C" void fn_8012DEE4(void *);
extern "C" void fn_8012DFCC(Unk8012DFCCList *, Unk8012DFCCNode *);
extern "C" void *fn_8012E060(void *, const char *);
extern "C" s32 fn_8012D838(s32);
extern "C" void *fn_8012E3D4(void *);
extern "C" void fn_8012E40C(void *, s32);
extern "C" void fn_8012E2CC(void *);
extern "C" void *fn_8012E460(void *);
extern "C" s32 fn_8012E490(s32 *);
extern "C" const char lbl_8032ACE0[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012DDA8(s32 arg0) {
    nw4r::ef::Effect *obj;
    Unk8012DFCCNode *node;
    s32 found;
    if (fn_8012BD3C(lbl_8055E000, (const char *)arg0) != 0) {
        return;
    }
    obj = lbl_8055E014;
    if (obj == 0) {
        return;
    }
    found = 0;
    node = (Unk8012DFCCNode *)fn_8012E490((s32 *)((char *)obj + 0xA18));
    do {
        if (stricmp(node->unk_0xC, (const char *)arg0) == 0) {
            found = 1;
            node->unk_0x8 += 1;
            break;
        }
        node = node->next;
    } while (node != 0);
    if (found == 0) {
        fn_802E30C8(lbl_8032ACE0, (const char *)arg0);
        node = (Unk8012DFCCNode *)fn_8012E460((char *)obj + 8);
        if (node == 0) {
            fn_8012E2CC(obj);
            node = (Unk8012DFCCNode *)fn_8012E460((char *)obj + 8);
        }
        if (node != 0) {
            fn_8012DFE8(node, (const char *)arg0, (s32)fn_8012E060((char *)obj + 4, (const char *)arg0));
            fn_8012DFCC((Unk8012DFCCList *)((char *)obj + 0xA18), node);
            fn_8012DEE4(obj);
            found = 1;
        }
        if (found == 0) {
            ((void *(*)(const char *, void **))fn_8012BD98)((const char *)arg0, &lbl_8055E000);
        }
    }
}
#pragma pop

extern "C" s32 fn_8012CC24(void *, void *);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Work the manager's load queue (fn_8012DDA8 queues a set and calls this): while
 * the set at the head has no read in flight, start one with fn_8012CC24; once
 * its request has the set in memory, give the loaded resource the use count the
 * queue collected, mark it ready and retire the queue node.  Stops as soon as
 * the head stops making progress; the manager's pumping byte keeps a set that
 * finishes inside fn_8012CC24 from re-entering this. */
extern "C" void fn_8012DEE4(void *arg0) {
    ResTocManager *manager = (ResTocManager *)arg0;
    s32 one = 1;
    s32 zero = 0;
    ResTocMount *entry;
    s32 progress;
    s32 state;

    if (manager->pumping != 0) return;
    manager->pumping = (u8)one;
    do {
        progress = 0;
        entry = manager->mounts.head;
        if (entry != 0) {
            state = fn_8012D838((s32)entry->request);
            switch (state) {
            case 0:  // idle: have the request read on with this set's path list
                fn_8012CC24(entry->request, entry->name);
                break;
            case 2: {  // the set is in memory: hand it the queue's use count
                void *node = fn_8012BD3C(lbl_8055E000, entry->name);
                *(s32 *)((u8 *)node + 0x9C) = entry->uses;  // resource use count
                *(u8 *)((u8 *)node + 0xAD) = (u8)one;       // resource is ready
                entry = manager->mounts.head;
                if (entry != 0) {
                    ResTocMount *next = entry->next;
                    manager->mounts.head = next;
                    if (next == 0) manager->mounts.tail = &manager->mounts.head;
                    entry->next = (ResTocMount *)zero;
                }
                progress = 1;
                break;
            }
            default:  // a read is still in flight: nothing more to do for now
                break;
            }
        }
    } while (progress != 0);
    manager->pumping = 0;
}
#pragma pop

extern "C" void fn_8012DFCC(Unk8012DFCCList *arg0, Unk8012DFCCNode *arg1) {
    *arg0->tail = arg1;
    arg0->tail = &arg1->next;
    arg1->next = 0;
}

extern "C" void fn_8012DFE8(void *arg0, const char *arg1, s32 arg2) {
    const unsigned char *src = (const unsigned char *)arg1;
    int count = 0x40;
    char *dst = (char *)arg0 + 0xc;
    unsigned char c;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
done:
    *(s32 *)((u8 *)arg0 + 0x4c) = fn_8012CAA0(arg2, (void *)arg1);
    *(s32 *)((u8 *)arg0 + 8) = 1;
}

extern "C" void *fn_8012E060(void *arg0, const char *arg1) {
    char sp10[0x80];
    s32 spC;
    u8 sp8;
    char *var_r4;
    s32 var_r5;
    char *var_r6;
    char *var_r4_2;
    s32 var_r5_2;
    char *var_r6_2;
    u8 temp_r3;
    u8 temp_r3_2;
    void *data;
    u8 t;
    u8 t2;
    u32 n;
    u8 *entry;
    void *ret;
    char *dot;
    var_r4 = (char *)arg1; var_r6 = sp10; var_r5 = 0x80;
    goto path_copy;
path_limit:
    var_r5 -= 1;
    if (var_r5 > 0) goto path_copy;
    var_r6[-1] = 0;
    goto path_done;
path_copy:
    temp_r3 = *var_r4++; *var_r6++ = temp_r3;
    if ((s8)temp_r3 != 0) goto path_limit;
path_done:
    dot = fn_80029004(sp10, 0x2E);
    if ((s8)*dot != 0) {
        dot = fn_80029004(sp10, 0x2E);
        *dot = 0;
    }
    var_r6_2 = sp10; var_r5_2 = 0x80;
    goto scan_test;
scan_step:
    var_r5_2 -= 1; var_r6_2 += 1;
scan_test:
    if ((s8)*var_r6_2 != 0) goto scan_step;
    if (var_r5_2 <= 0) goto path_all_done;
    var_r4_2 = (char *)&lbl_805599E0;
    goto suffix_copy;
suffix_limit:
    var_r5_2 -= 1;
    if (var_r5_2 > 0) goto suffix_copy;
    var_r6_2[-1] = 0;
    goto path_all_done;
suffix_copy:
    temp_r3_2 = *var_r4_2++; *var_r6_2++ = temp_r3_2;
    if ((s8)temp_r3_2 != 0) goto suffix_limit;
path_all_done:
    fn_8002B0D8(sp10);
    data = (void *)fn_8012C370((s32)sp10, 0x45544F43, (s32)&spC, 0, 0, (s32)&sp8);
    if (data != 0 && sp8 != 0) {
        u8 *d = (u8 *)data;
        t = d[0]; d[0] = d[3]; d[3] = t;
        t = d[1]; d[1] = d[2]; d[2] = t;
        t = d[4]; d[4] = d[7]; d[7] = t;
        t = d[5]; d[5] = d[6]; d[6] = t;
        t = d[8]; d[8] = d[0xB]; d[0xB] = t;
        t = d[9]; d[9] = d[0xA]; d[0xA] = t;
        t = d[0xC]; d[0xC] = d[0xF]; d[0xF] = t;
        t = d[0xD]; d[0xD] = d[0xE]; d[0xE] = t;
        t = d[0x10]; d[0x10] = d[0x13]; d[0x13] = t;
        t = d[0x11]; d[0x11] = d[0x12]; d[0x12] = t;
        if (*(u32 *)d != 0 || *(u32 *)(d + 4) != 0x14)
            fn_802E317C(lbl_8032AE60, *(u32 *)d, 0, *(u32 *)(d + 4), 0x14);
        entry = d + 0x14; n = 0;
        goto entries_test;
entries_loop:
        fn_8012A388(entry); entry += 0x44; n += 1;
entries_test:
        if (n < *(u32 *)(d + 0xC)) goto entries_loop;
    }
    if (data == 0) fn_802E317C(lbl_8032ADDC, arg1);
    ret = (void *)(*(s32 *)((char *)data + 0x10) + 0x80);
    fn_8012C4D8(data);
    return ret;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012E2CC(void *arg0) {
    u8 *obj = (u8 *)arg0;
    void *done;
    void *entry;
    void *node;
    s32 state;

    done = *(void **)(obj + 0xA18);
    if (done == 0) return;
    goto check_status;
retry_status:
    fn_80127464();
    fn_802E2D74(0xA);
check_status:
    if (fn_8012D838(*(s32 *)((u8 *)done + 0x4C)) != 2) goto retry_status;
    if (obj[0xA20] != 0) return;
    obj[0xA20] = 1;
    do {
        done = 0;
        entry = (void *)fn_8012E490((s32 *)(obj + 0xA18));
        if (entry != 0) {
            state = fn_8012D838(*(s32 *)((u8 *)entry + 0x4C));
            if (state == 1) goto after_state;
            if (state >= 1) goto state_ge_one;
            if (state < 0) goto after_state;
            goto state_zero;
state_ge_one:
            if (state < 3) goto state_two;
            goto after_state;
state_two:
            fn_8012E40C((void *)*(s32 *)((u8 *)entry + 0x4C), (s32)((u8 *)entry + 0xC));
            goto after_state;
state_zero:
            node = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
            *(s32 *)((u8 *)node + 0x9C) = *(s32 *)((u8 *)entry + 8);
            *(u8 *)((u8 *)node + 0xAD) = 1;
            fn_8012E3D4(obj + 0xA18);
            done = (void *)1;
after_state:
            ;
        }
    } while (done != 0);
    obj[0xA20] = 0;
}
#pragma pop

extern "C" void *fn_8012E3D4(void *arg0) {
    void *temp_r0;
    void *temp_r4;
    void *var_r5;
    temp_r4 = *(void **)arg0;
    var_r5 = 0;
    if (temp_r4 != 0) {
        temp_r0 = *(void **)((u8 *)temp_r4 + 4);
        var_r5 = temp_r4;
        *(void **)arg0 = temp_r0;
        if (temp_r0 == 0) {
            *(void **)((u8 *)arg0 + 4) = arg0;
        }
        *(void **)((u8 *)temp_r4 + 4) = 0;
    }
    return var_r5;
}

extern "C" void fn_8012E40C(void *arg0, s32 arg1) {
    void *self = arg0;
    fn_8012D40C((s32)self);
    fn_8012D1A8((s32)self);
    *(s32 *)((u8 *)self + 0xBC) = 0;
    ((void (*)(void *, s32))fn_8012D024)(self, arg1);
}

extern "C" void *fn_8012E460(void *arg0) {
    void *node = *(void **)((u8 *)arg0 + 0xC);
    void *result = 0;
    if (node != 0) {
        result = node;
        *(void **)((u8 *)arg0 + 0xC) = *(void **)node;
        *(void **)node = *(void **)((u8 *)arg0 + 8);
        *(void **)((u8 *)arg0 + 8) = node;
    }
    return result;
}

extern "C" s32 fn_8012E490(s32 *arg0) {
    return *arg0;
}

extern "C" const char lbl_8032ACF4[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012E498(void *arg0) {
    s32 removed;
    s32 entry;
    s32 effect;
    s32 object;
    fn_8012E81C((s32)arg0);
    object = (s32)fn_8012BD3C(lbl_8055E000, (const char *)arg0);
    if (object != 0 && --*(s32 *)(object + 0x9C) == 0) {
        effect = (s32)lbl_8055E014;
        if (effect != 0) {
            removed = 0;
            entry = fn_8012E490((s32 *)(effect + 0xA18));
            while (entry != 0) {
                if (stricmp((const char *)(entry + 0xC), (const char *)arg0) == 0) {
                    fn_8012E67C(effect, (s32)arg0);
                    break;
                }
                entry = *(s32 *)(entry + 4);
            }
            entry = fn_8012E490((s32 *)(effect + 0xA18));
            while (entry != 0) {
                if (stricmp((const char *)(entry + 0xC), (const char *)arg0) == 0) {
                    fn_802E317C(lbl_8032ACF4);
                }
                entry = *(s32 *)(entry + 4);
            }
            entry = fn_8012E674((void *)(effect + 8));
            while (entry != 0) {
                if (stricmp((const char *)(entry + 0xC), (const char *)arg0) == 0) {
                    fn_8012E630((void *)entry);
                    fn_8012E5E4((void *)(effect + 8), (void *)entry);
                    removed = 1;
                    goto next_entry;
                }
next_entry:
                entry = *(s32 *)entry;
            }
            if (removed != 0) return;
        }
        fn_8012BB20((s32)&lbl_8055E000, (void *)object);
    }
}
#pragma pop
#pragma scheduling reset

extern "C" void fn_8012E5E4(void *arg0, void *arg1) {
    void *node;
    s32 found;
    void **link;
    link = (void **)((u8 *)arg0 + 8);
    found = 0;
    while ((node = *link) != 0) {
        if (node == arg1) {
            *link = *(void **)node;
            found = 1;
            break;
        }
        link = (void **)node;
    }
    if (found == 0) return;
    *(void **)arg1 = *(void **)((u8 *)arg0 + 0xC);
    *(void **)((u8 *)arg0 + 0xC) = arg1;
}

extern "C" void fn_8012E630(void *arg0) {
    fn_8012D3D8(*(s32 *)((u8 *)arg0 + 0x4C));
    fn_8012D8A8(*(s32 *)((u8 *)arg0 + 0x4C));
    *(s32 *)((u8 *)arg0 + 0x4C) = 0;
    *((u8 *)arg0 + 0xC) = 0;
}

  extern "C" s32 fn_8012E674(void *arg0) {
      return *(s32*)((u8*)arg0 + 8);
  }

  #pragma push
  #pragma scheduling invalid_target
/* Waits for the pending resource request named `name` on loader `loader` to
 * finish loading (state 2), draining the loader's request queue meanwhile, then
 * clears the resource entry's "pending" flag (+0xAD). */
extern "C" void fn_8012E67C(s32 loader, s32 name) {
    u8 *self = (u8 *)loader;
    s32 start, deadline, now, done;
    void *entry;
    void *resEntry;
    u8 *req;
    for (req = *(u8 **)(self + 0xA18); req != 0; req = *(u8 **)(req + 4)) {
        if (stricmp((const char *)name, (const char *)(req + 0xC)) == 0) {
            start = fn_802E2C20();
            deadline = start + 0x7D0;
            while (fn_8012D838(*(s32 *)(req + 0x4C)) != 2) {
                fn_80127464();
                fn_802E2D74(0xA);
                now = fn_802E2C20();
                if (now > deadline) {
                    fn_802E30C8(lbl_8032AD88, (const char *)(req + 0xC));
                    deadline = now + 0x7D0;
                }
            }
            if (self[0xA20] == 0) {
                self[0xA20] = 1;
                do {
                    done = 0;
                    entry = (void *)fn_8012E490((s32 *)(self + 0xA18));
                    if (entry != 0) {
                        switch (fn_8012D838(*(s32 *)((u8 *)entry + 0x4C))) {
                        case 0:
                            fn_8012E40C((void *)*(s32 *)((u8 *)entry + 0x4C), (s32)((u8 *)entry + 0xC));
                            break;
                        case 2:
                            resEntry = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
                            *(s32 *)((u8 *)resEntry + 0x9C) = *(s32 *)((u8 *)entry + 8);
                            *(u8 *)((u8 *)resEntry + 0xAD) = 1;
                            fn_8012E3D4(self + 0xA18);
                            done = 1;
                            break;
                        }
                    }
                } while (done != 0);
                self[0xA20] = 0;
            }
            fn_802E30C8(lbl_8032AD6C, (const char *)(req + 0xC), fn_802E2C20() - start);
            break;
        }
    }
    resEntry = fn_8012BD3C(lbl_8055E000, (const char *)name);
    if (resEntry != 0) {
        *(u8 *)((u8 *)resEntry + 0xAD) = 0;
    } else {
        fn_802E30C8(lbl_8032AD2C, (const char *)name);
    }
}
  #pragma pop

extern "C" const char lbl_8032AD2C[];
extern "C" const char lbl_8032AD6C[];
extern "C" const char lbl_8032AD88[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012E81C(s32 arg0) {
    s32 limit;
    void *entry;
    s32 start;
    s32 current;
    const char *format;
    nw4r::ef::Effect *effect = lbl_8055E014;

    if (effect == 0) return;
    entry = (void *)fn_8012E490((s32 *)((u8 *)effect + 0xA18));
    while (entry != 0) {
        if (stricmp((const char *)arg0,
                    (const char *)((u8 *)entry + 0xC)) == 0) {
            start = fn_802E2C20();
            limit = start + 0x7D0;
            format = lbl_8032AD88;
            do {
                fn_80127464();
                fn_802E2D74(0xA);
                current = fn_802E2C20();
            } while (current <= limit);
            fn_802E30C8(format, (const char *)((u8 *)entry + 0xC));
            limit = current + 0x7D0;
            if (fn_8012D838(*(s32 *)((u8 *)entry + 0x4C)) == 2) {
                fn_8012DEE4(effect);
                fn_802E30C8(lbl_8032AD6C,
                            (const char *)((u8 *)entry + 0xC),
                            fn_802E2C20() - start);
                return;
            }
        }
        entry = *(void **)((u8 *)entry + 4);
    }
    {
        void *found = fn_8012BD3C(lbl_8055E000, (const char *)arg0);
        if (found != 0) {
            *(u8 *)((u8 *)found + 0xAD) = 0;
            return;
        }
    }
    fn_802E30C8(lbl_8032AD2C, (const char *)arg0);
}
#pragma pop

extern "C" s32 fn_8012E938(s32 arg0) {
    return fn_8012BD3C(lbl_8055E000, (const char *)arg0) != 0;
}

extern "C" void fn_8012E96C(s32 arg0) {
    s32 sp8;
    s32 result;
    s32 arg = arg0;
    nw4r::ef::Effect *entry = lbl_8055E014;
    if (entry != 0) {
        result = ((s32 (*)(s32, s32 *, s32))fn_8012B534)(arg0, &sp8, 3);
        if (result == 0) {
            result = fn_8012E9F0((s32)entry, arg);
            if (result != 0)
                fn_8012E67C((s32)entry, result + 0xC);
        } else {
            fn_8012E67C((s32)entry, result);
        }
    }
}

// Which mounted resource set owns the resource name arg1?  Walks arg0's mount
// list the way fn_8012D908 does - "<set>.toc" read as an ETOC block, its header
// and entries byte-reversed if the read just brought it in - and returns the
// mount whose table lists arg1 (fn_8012E96C reports the set by its name at
// +0xC), or 0 when no mounted set has it.
extern "C" s32 fn_8012E9F0(s32 manager, s32 resName) {
    char tocPath[128];
    s32 tocOffset;
    u8 startedLoad;
    char *nameSrc;
    s32 nameLeft;
    char *pathDst;
    char *extSrc;
    s32 extLeft;
    char *extDst;
    u8 c, c2;
    u8 swap0, swap1, swap2, swap3, swap4;
    u8 swap5, swap6, swap7, swap8, swap9;
    u32 tocVersion;
    u8 *toc;
    ResTocMount *matched;
    ResTocMount *mount;
    u32 nameIndex;
    u32 hasName;
    u32 entryIndex;
    u8 *nameEntry;
    u8 *entry;

    mount = ((ResTocManager *)manager)->mounts.head;
    matched = 0;
    goto mount_test;
mount_loop:
    // tocPath = "<set name>.toc", the resource holding this set's ETOC block
    nameSrc = mount->name; pathDst = tocPath; nameLeft = sizeof(tocPath);
    goto name_copy;
name_limit:
    nameLeft -= 1;
    if (nameLeft > 0) goto name_copy;
    pathDst[-1] = 0;
    goto name_done;
name_copy:
    c = *nameSrc++; *pathDst++ = c;
    if ((s8)c != 0) goto name_limit;
name_done:
    if ((s8)*fn_80029004(tocPath, '.') != 0) *fn_80029004(tocPath, '.') = 0;  // cut the set name's own extension
    extDst = tocPath; extLeft = sizeof(tocPath);
    goto ext_scan_test;
ext_scan_step:
    extLeft -= 1; extDst += 1;
ext_scan_test:
    if ((s8)*extDst != 0) goto ext_scan_step;  // walk to the end of the name
    if (extLeft <= 0) goto path_ready;
    extSrc = RES_TOC_EXT_PATH;
    goto ext_copy;
ext_limit:
    extLeft -= 1;
    if (extLeft > 0) goto ext_copy;
    extDst[-1] = 0;
    goto path_ready;
ext_copy:
    c2 = *extSrc++; *extDst++ = c2;
    if ((s8)c2 != 0) goto ext_limit;
path_ready:
    fn_8002B0D8(tocPath);  // map the path through the current character table
    // Read the set's ETOC resource; startedLoad is set when this call had to
    // start the read, so the block that came in is still little-endian.
    toc = (u8 *)fn_8012C370((s32)tocPath, RES_TOC_FOURCC, (s32)&tocOffset, 0, 0, (s32)&startedLoad);
    if (toc != 0 && startedLoad != 0) {
        // byte-reverse the ETOC header's five words
        swap0 = toc[0]; toc[0] = toc[3]; toc[3] = swap0;
        swap1 = toc[1]; toc[1] = toc[2]; toc[2] = swap1;
        swap2 = toc[4]; toc[4] = toc[7]; toc[7] = swap2;
        swap3 = toc[5]; toc[5] = toc[6]; toc[6] = swap3;
        swap4 = toc[8]; toc[8] = toc[0xB]; toc[0xB] = swap4;
        swap5 = toc[9]; toc[9] = toc[0xA]; toc[0xA] = swap5;
        swap6 = toc[0xC]; toc[0xC] = toc[0xF]; toc[0xF] = swap6;
        swap7 = toc[0xD]; toc[0xD] = toc[0xE]; toc[0xE] = swap7;
        swap8 = toc[0x10]; toc[0x10] = toc[0x13]; toc[0x13] = swap8;
        swap9 = toc[0x11]; toc[0x11] = toc[0x12]; toc[0x12] = swap9;
        tocVersion = *(u32 *)toc;
        if (tocVersion != 0 || *(u32 *)(toc + 4) != RES_TOC_HEADER_SIZE)
            fn_802E317C(lbl_8032AE60, tocVersion, 0, *(u32 *)(toc + 4), RES_TOC_HEADER_SIZE);

        entry = toc + RES_TOC_HEADER_SIZE; entryIndex = 0;
        goto entry_test;
entry_loop:
        fn_8012A388(entry);  // byte-reverse one entry
        entry += RES_TOC_ENTRY_SIZE; entryIndex += 1;
entry_test:
        if (entryIndex < *(u32 *)(toc + 0xC)) goto entry_loop;  // entryCount
    }
    // does this set's table have an entry named arg1?
    nameEntry = toc + RES_TOC_HEADER_SIZE; hasName = 0; nameIndex = 0;
    goto name_test;
name_loop:
    if (stricmp((const char *)nameEntry, (const char *)resName) == 0) {
        hasName = 1; goto name_found;
    }
    nameEntry += RES_TOC_ENTRY_SIZE; nameIndex += 1;
name_test:
    if (nameIndex < *(u32 *)(toc + 0xC)) goto name_loop;
name_found:
    if (hasName != 0) matched = mount;
    fn_8012C4D8(toc);  // release the ETOC resource again
    mount = mount->next;
mount_test:
    if (mount != 0 && matched == 0) goto mount_loop;
    return (s32)matched;
}

// One prefetch slot of a ResourceStream, 0x10 bytes.
struct ResourceStreamEntry {
    s32 buffer;              // +0x00 where the chunk lands in the stream's buffer
    void *request;           // +0x04 async read of the chunk (fn_8012C720/fn_8012C7FC)
    s32 position;            // +0x08 file offset the chunk was read from
    s32 state;               // +0x0C StreamSlotState
};

// What a prefetch slot is doing.
enum StreamSlotState {
    STREAM_SLOT_FREE = 0,    // holds nothing
    STREAM_SLOT_READING = 1, // the disc read of the chunk is running
    STREAM_SLOT_READY = 2    // the chunk is in memory and can be read from
};

#define STREAM_SLOT_COUNT 2  // prefetch slots in a ResourceStream

// Double-buffered streaming reader over a resource file ("ResourceStream"), 0x2C
// bytes. The slots read the file ahead in chunks of `size` bytes into the buffer
// of 2 * size bytes made by fn_8012EC90; fn_8012EE80 runs the machine each frame
// and fn_8012EFB0 takes bytes out of a ready chunk at `boundary`.
struct ResourceStream {
    s32 size;                                  // +0x00 bytes of the file one slot holds
    ResourceStreamEntry entries[STREAM_SLOT_COUNT];  // +0x04 the prefetch slots
    s32 limit;                                 // +0x24 size of the streamed file
    s32 boundary;                              // +0x28 offset the reader has reached
};

// Heap-name tags fn_801284F8/fn_8012850C record with an allocation (strings in .sdata).
#define RES_STREAM_HEAP      ((void *)&lbl_805599C8)  // "resbuf": the stream object
#define RES_STREAM_DATA_HEAP ((void *)&lbl_805599D0)  // "resbufb": its read-ahead buffer

extern "C" void *fn_8012EC90(s32 arg0) {
    s32 count = arg0;
    void *obj = fn_801284F8(0x2C, (void *)&lbl_805599C8);
    memset(obj, 0, 0x2C);
    *(s32 *)obj = count;
    fn_801282EC(0x80);
    s32 data = (s32)fn_8012850C(count << 1, (void *)&lbl_805599D0);
    *(s32 *)((u8 *)obj + 8) = 0;
    *(s32 *)((u8 *)obj + 4) = data;
    *(s32 *)((u8 *)obj + 0x10) = 0;
    *(s32 *)((u8 *)obj + 0x18) = 0;
    *(s32 *)((u8 *)obj + 0x14) = data + count;
    *(s32 *)((u8 *)obj + 0x20) = 0;
    *(s32 *)((u8 *)obj + 0x28) = 0;
    *(s32 *)((u8 *)obj + 0x24) = 0;
    return obj;
}

extern "C" void fn_8012ED20(void *arg0) {
 u8 *p;
 s32 i;
 struct S { s32 a; s32 b; };
 for (i=0, p=(u8 *)arg0+4; i<2; i++, p+=0x10) {
  if (*(s32 *)(p+4)) {
   fn_8012C90C((void *)*(s32 *)(p+4));
   fn_8012C958((void *)*(s32 *)(p+4));
   *(s32 *)(p+4)=0;
  }
 }
 fn_80128670(((struct S *)arg0)->b);
 fn_80128668(arg0);
}

extern "C" s32 fn_8012C5B8(s32, s32, s32);
extern "C" s32 fn_8012C6F0(void *);
extern "C" void fn_8012EE80(void *);
extern "C" s32 fn_8012EDA8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *slot;
    s32 *slots = (s32 *)((char *)arg0 + 4);
    s32 slotIndex;
    s32 initIndex;
    s32 handle;
    /* Reset both stream slots (release any active request), open the resource
       identified by (arg1,arg2,arg3) into each slot, record its data size, then
       start the prefetch; returns 0 if a slot cannot be opened. */
    for (slot = slots, initIndex = 0; initIndex < 2; initIndex++, slot += 4) {
        if (slot[1]) {
            fn_8012C90C((void *)slot[1]);
            fn_8012C958((void *)slot[1]);
            slot[1] = 0;
            slot[3] = 0;
        }
    }
    *(s32 *)((char *)arg0 + 0x28) = 0;
    for (slotIndex = 0; slotIndex < 2; slotIndex++, slots += 4) {
        handle = fn_8012C5B8(arg1, arg2, arg3);
        slots[1] = handle;
        if (!handle) return 0;
        *(s32 *)((char *)arg0 + 0x24) = fn_8012C6F0((void *)handle);
    }
    fn_8012EE80(arg0);
    return 1;
}

extern "C" s32 fn_8012EE78(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

extern "C" s32 fn_8012C7FC(void *, s32 *);
extern "C" void fn_8012C720(void *, s32, s32, s32);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012EE80(void *arg0) {
    // Run the ResourceStream prefetch machine once: retire the reads that have
    // finished, then give every free or already-read-past slot the next chunk of
    // the file, reading it into that slot's half of the stream buffer.
    ResourceStream *stream = (ResourceStream *)arg0;
    ResourceStreamEntry *slot = stream->entries;
    ResourceStreamEntry *scan = slot;
    s32 i;
    s32 j;
    s32 end = stream->boundary;  // file offset just past the chunks held in memory
    s32 state;
    s32 pos;
    s32 len;
    s32 request;

    // a slot whose disc read finished is now readable; find the end of the held range
    for (i = 0; i < STREAM_SLOT_COUNT; i++, scan++) {
        state = scan->state;
        if (state != STREAM_SLOT_FREE) {
            if (state == STREAM_SLOT_READING && fn_8012C7FC(scan->request, 0))
                scan->state = STREAM_SLOT_READY;
            pos = scan->position + stream->size;
            if (pos > end)
                end = pos;
        }
    }

    j = 0;
    scan = 0;  // null, stored as the FREE state below
    for (; j < STREAM_SLOT_COUNT; j++, slot++) {
        state = slot->state;
        if (state != STREAM_SLOT_FREE)
            goto check_state;
        if (slot->request != 0)  // a slot the file was just opened into
            goto fill_slot;
check_state:
        if (state != STREAM_SLOT_READY)
            goto next_slot;  // still reading
        pos = slot->position + stream->size;
        if (pos >= stream->boundary)
            goto next_slot;  // the reader has not passed this chunk yet
fill_slot:
        slot->position = end;
        pos = end;
        len = stream->size;
        end += len;
        request = len;
        if (pos + len > stream->limit)
            request = stream->limit - pos;  // the last chunk is short
        if (request > 0) {
            fn_8012C720(slot->request, slot->buffer, request, pos);
            slot->state = STREAM_SLOT_READING;
        } else {
            slot->state = (s32)scan;  // nothing left to read: the slot goes free
        }
next_slot:
        ;
    }
}
#pragma pop

/* Reads bytes from the current buffered stream chunk if available; advances read position on success. */
extern "C" s32 fn_8012EFB0(void *stream, void *dst, s32 length) {
    s32 pos = *(s32 *)((u8 *)stream + 0x28);
    s32 i;
    if (pos + length >= *(s32 *)((u8 *)stream + 0x24)) return 0;
    for (i = 0; i < 2; i++) {
        u8 *slot = (u8 *)stream + 4 + i * 0x10;
        s32 start;
        if (*(s32 *)(slot + 0xC) != 2) continue;
        start = *(s32 *)(slot + 8);
        if (pos >= start && pos < start + *(s32 *)stream) {
            memcpy(dst, (u8 *)*(void **)slot + (pos - start), length);
            *(s32 *)((u8 *)stream + 0x28) += length;
            return 1;
        }
    }
    return 0;
}

extern "C" s32 fn_8012D838(s32);
#pragma scheduling invalid_target
extern "C" void fn_8012F06C(void *arg0) {
    u8 *obj = (u8 *)arg0;
    if (obj[0xA20] == 0) {
        s32 one = 1;
        s32 done;
        obj[0xA20] = (u8)one;
        do {
            done = 0;
            void *entry = (void *)fn_8012E490((s32 *)(obj + 0xA18));
            if (entry != 0) {
                s32 state = fn_8012D838(*(s32 *)((u8 *)entry + 0x4C));
                if (state == 1) goto after_state;
                if (state >= 1) goto state_ge_one;
                if (state >= 0) goto state_zero;
                goto after_state;
state_ge_one:
                if (state < 3) {
                    fn_8012E40C((void *)*(s32 *)((u8 *)entry + 0x4C), (s32)((u8 *)entry + 0xC));
                }
                goto after_state;
state_zero:
                {
                    void *node = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
                    *(s32 *)((u8 *)node + 0x9C) = *(s32 *)((u8 *)entry + 8);
                    *(u8 *)((u8 *)node + 0xAD) = (u8)one;
                    fn_8012E3D4(obj + 0xA18);
                    done = 1;
                }
after_state:
                ;
            }
        } while (done != 0);
        obj[0xA20] = 0;
    }
}
#pragma scheduling on
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void fn_802E317C(const char *, ...);
extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2);
extern "C" void fn_8012BF24(void *);
extern "C" s32 fn_80128668(void *);
extern "C" const char lbl_8032AEA8[];
extern "C" const char lbl_8032AB9C[];
extern "C" const char lbl_8032ABC8[];
extern "C" const char lbl_8032ABEC[];
extern "C" s32 lbl_8055DFFC;
extern "C" s8 lbl_8055DFF8;
extern "C" void *lbl_8055E000;

extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2);

extern "C" s32 fn_8012C4E4(void *arg0, void *arg1, s32 arg2) {
    return fn_8012BC50(arg0, arg1, arg2);
}

#pragma scheduling off
extern "C" void fn_8012C4E8(void) {
    void *node;
    s32 p;

    fn_8012DD00();
    fn_8012A67C();
    p = lbl_8055DFFC;
    if (p != 0) {
        fn_8012BF24((void *)lbl_8032AEA8);
        fn_80128668((void *)p);
    }
    node = lbl_8055E000;
    lbl_8055DFFC = 0;
    lbl_8055DFF8 = 0;
    while (node != NULL) {
        fn_802E30C8(lbl_8032AB9C, node, *(s32 *)((u8 *)node + 0x9C));
        node = *(void **)((u8 *)node + 0xA8);
    }
    fn_802E317C(lbl_8032ABC8);
}
#pragma scheduling reset
extern "C" void *fn_8012C58C(void *arg0) {
    void *var_r5 = (void *)&lbl_8032ABEC;

    if (arg0 != NULL &&
        (u32)(*(u32 *)((u8 *)arg0 - 4) - 0x4D470000) == 0x4921U) {
        var_r5 = *(void **)((u8 *)arg0 - 8);
    }
    return var_r5;
}

extern "C" const char lbl_8032ABF8[];
extern "C" const char lbl_8032AC08[];
#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_8012C5B8(s32 arg0, s32 arg1, s32 arg2) {
    long index;
    long result = 0;
    s32 *manager;
    s32 *entry;
    manager = ((s32 *(*)(s32, s32 *, s32))fn_8012B534)(arg0, &index, 1);
    if (manager != 0) {
        entry = (s32 *)((char *)*(void **)((char *)manager + 0x60) + index * 0x44);
        if (*(u32 *)((char *)entry + 0x20) == (u32)arg1) {
            *(s32 *)arg2 = *(s32 *)((char *)entry + 0x24);
            register void *allocation = fn_8012A570(0x18, (void *)lbl_8032ABF8);
            if (allocation != 0) {
                volatile s32 *fields = (volatile s32 *)allocation;
                fields[3] = -1;
                fields[4] = 0;
                fields[1] = 0;
                fields[2] = 0;
                result = (s32)allocation;
                fields[5] = 0;
                fields[0] = 0x19AFEE2A;
                fields[1] = (s32)entry;
                fields[2] = (s32)manager;
            }
        } else {
            char queryText[5];
            char entryText[5];
            char e0, e3, e1, e2;
            char q0, q3, q1, q2;
            *(u32 *)queryText = (u32)arg1;
            q0 = queryText[0];
            q3 = queryText[3];
            queryText[4] = 0;
            q1 = queryText[1];
            q2 = queryText[2];
            queryText[0] = q3;
            queryText[3] = q0;
            queryText[2] = q1;
            queryText[1] = q2;
            *(u32 *)entryText = *(u32 *)((char *)entry + 0x20);
            entryText[4] = 0;
            e0 = entryText[0];
            e3 = entryText[3];
            e1 = entryText[1];
            e2 = entryText[2];
            entryText[0] = (unsigned)e3;
            entryText[3] = e0;
            entryText[1] = e2;
            entryText[2] = e1;
            fn_802E30C8(lbl_8032AC08, queryText, entryText);
        }
    }
    return result;
}
#pragma pop

extern "C" s32 fn_8012C6F0(void *arg0) {
    s32 temp_r4;
    void *temp_r5;
    temp_r5 = *(void **)((u8 *)arg0 + 4);
    temp_r4 = *(s32 *)((u8 *)temp_r5 + 0x2C) +
              *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x80);
    return ((temp_r4 + *(s32 *)((u8 *)temp_r5 + 0x28) + 0x7FF) & 0xFFFFF800) -
           (temp_r4 & 0xFFFFF800);
}

extern "C" s32 fn_802E748C(s32, s32, void *);
extern "C" const char lbl_8032AC34[];
extern "C" void fn_8012C720(void *request, s32 buffer, s32 size, s32 fileOffset) {
    /* Start or satisfy a stream read request: queue a disc read unless the file is resident, then copy resident data. */
    void *context;
    void *file = *(void * volatile *)((u8 *)request + 4);
    void *residentFile;
    s32 offset;
    s32 adjustedOffset;
    if ((*(volatile u32 *)((u8 *)file + 0x34) & 8) == 0) {
        residentFile = *(void * volatile *)((u8 *)request + 4);
        context = *(void * volatile *)((u8 *)request + 8);
        adjustedOffset = fileOffset + *(volatile s32 *)((u8 *)residentFile + 0x2C);
        context = (void *)*(volatile s32 *)((u8 *)context + 0x80);
        offset = (s32)context + adjustedOffset;
        context = *(void * volatile *)((u8 *)request + 8);
        *(s32 *)((u8 *)request + 0xC) = ((s32 (*)(s32, s32, s32, s32))fn_802E748C)(
            *(volatile s32 *)((u8 *)context + 0xA4) + offset / 2048, buffer, size, fileOffset);
        *(s32 *)((u8 *)request + 0x10) = buffer + (offset & 0x7FF);
        *(s32 *)((u8 *)request + 0x14) = size;
    } else {
        fn_802E30C8(lbl_8032AC34, file);
        file = *(void * volatile *)((u8 *)request + 4);
        memcpy((void *)buffer, (void *)(*(u32 *)((u8 *)file + 0x3C) + 8), *(u32 *)((u8 *)file + 0x28));
        *(s32 *)((u8 *)request + 0x10) = buffer;
        *(s32 *)((u8 *)request + 0xC) = -1;
        *(s32 *)((u8 *)request + 0x14) = size;
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_8012C7FC(void *arg0, s32 *arg1) {
    char *entry;
    s32 result = 0;
    s32 temp;
    temp = *(s32 *)((char *)arg0 + 0xC);
    if (temp != -1 && fn_802E7544(temp)) {
        fn_802E7548(*(s32 *)((char *)arg0 + 0xC));
        *(s32 *)((char *)arg0 + 0xC) = -1;
    }
    temp = *(s32 *)((char *)arg0 + 0xC);
    if (temp == -1 && *(s32 *)((char *)arg0 + 0x10)) {
        entry = *(char **)((char *)arg0 + 4);
        if (*(s32 *)((char *)arg0 + 0x14) < *(s32 *)(entry + 0x28) ||
            *(u32 *)(entry + 0x30) == ((u32 (*)(void))fn_80132E7C)()) {
            result = *(s32 *)((char *)arg0 + 0x10);
            if (arg1) *arg1 = *(s32 *)(entry + 0x28);
        } else {
            fn_802E30C8(lbl_8032AC68, entry);
            fn_8012C720(arg0, *(s32 *)((char *)arg0 + 0x10) -
                ((*(s32 *)((char *)*(void **)((char *)arg0 + 4) + 0x2C) +
                  *(s32 *)((char *)*(void **)((char *)arg0 + 8) + 0x80)) & 0x7FF),
                *(s32 *)((char *)arg0 + 0x14), 0);
        }
    }
    return result;
}
#pragma pop
extern "C" void fn_802E7548(s32);
extern "C" u8 lbl_8032AC88[];
extern "C" void fn_8012C90C(void *arg0) {
    s32 temp_r0 = *(s32 *)((u8 *)arg0 + 0xC);
    if (temp_r0 != -1) {
        fn_802E7548(temp_r0);
        *(s32 *)((u8 *)arg0 + 0xC) = -1;
        *(s32 *)((u8 *)arg0 + 0x10) = 0;
    }
}

extern "C" void fn_8012C958(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0xC) != -1) {
        fn_8012C90C(arg0);
    }
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 0x10) = 0;
        *(s32 *)((u8 *)arg0 + 0xC) = -1;
        *(s32 *)((u8 *)arg0 + 4) = 0;
        *(s32 *)((u8 *)arg0 + 8) = 0;
        *(s32 *)((u8 *)arg0 + 0x14) = 0;
        *(u32 *)arg0 = 0x19AFEE2A;
        fn_8012A5E8(arg0);
    }
}

extern "C" void fn_8012C9C8(void) {
    if (lbl_8055E00C == 0) {
        void *p = fn_801284F8(0x20, lbl_8032AC88);
        if (p) p = fn_8012A13C(p, lbl_8032AC88, 0x20, 0xD0);
        lbl_8055E010 = (void **)p;
    }
    if (fn_8012A2D8(lbl_8055E010) != 0) {
        lbl_8055E00C = lbl_8055E00C + 1;
    }
}
  
  extern "C" void fn_80127464(void);
  extern "C" const char lbl_8032AB78[];
  extern "C" u8 lbl_8055DFF9;
  extern "C" s32 lbl_8055E00C;
  extern "C" void **lbl_8055E010;
  extern "C" void fn_8012CA40(void *arg0) {
    fn_8012A364(lbl_8055E010, arg0);
    if (--lbl_8055E00C == 0) {
        delete (Unk8012A570 *)lbl_8055E010;
        lbl_8055E010 = 0;
    }
}

extern "C" u32 lbl_805599C0;
extern "C" void fn_801282F4(void);
extern "C" void fn_801284F0(void *, void *);
/* Allocates and initializes a 0xD0-byte object, computing an aligned size and fetching its buffer. */
extern "C" s32 fn_8012CAA0(s32 requestedSize, void *source) {
    void *obj = ((void *(*)(s32, void *))fn_8012C9C8)(0xD0, &lbl_805599C0);
    if (obj != 0) {
        s32 zero = 0;
        *(u8 *)((u8 *)obj + 0xB0) = zero;
        *(s32 *)((u8 *)obj + 0xB8) = 1;
        *(s32 *)((u8 *)obj + 0xB4) = -1;
        *(s32 *)((u8 *)obj + 0xCC) = (requestedSize + 0x7FF) & ~0x7FF;
        fn_801282F4();
        fn_801282EC(0x80);
        *(s32 *)((u8 *)obj + 0xC8) =
            ((s32 (*)(void *, s32))fn_801284F0)(source, *(s32 *)((u8 *)obj + 0xCC));
        *(s32 *)((u8 *)obj + 0xC0) = zero;
    }
    return (s32)obj;
}

extern "C" const char lbl_8032AE20[];
extern "C" void *fn_8012CB44(void *arg0, s32 arg1) {
    s32 i, offset;
    u32 flags;
    void *base, *entry;
    if (arg0 != 0) {
        if (*(u8 *)((char *)arg0 + 0xAC) != 0) {
            i = 0;
            offset = 0;
            while (i < *(s32 *)((char *)arg0 + 0x88)) {
                base = *(void **)((char *)arg0 + 0x60);
                entry = (char *)base + offset;
                flags = *(u32 *)((char *)entry + 0x34);
                if ((flags & 4) != 0) fn_802E317C(lbl_8032AE20);
                base = *(void **)((char *)arg0 + 0x60);
                entry = (char *)base + offset;
                flags = *(u32 *)((char *)entry + 0x34);
                i = i + 1;
                offset = offset + 0x44;
                *(u32 *)((char *)entry + 0x34) = flags & 0xFFFFFFF0;
            }
            base = *(void **)((char *)arg0 + 0x64);
            if (base != 0) fn_8012C4D8(base);
            base = *(void **)((char *)arg0 + 0xA0);
            if (base != 0) fn_80128660((s32)base);
            *(u8 *)((char *)arg0 + 0xAC) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

