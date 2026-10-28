#include <types.h>
extern "C" s8 lbl_8055DFF8;
extern "C" u8 lbl_805599B8;
extern "C" const char lbl_8032AE9C[];
extern "C" void fn_8012BEF0(s32);
extern "C" void fn_8012DBD0(void);
extern "C" s32 lbl_8055DFFC;
extern "C" const char lbl_8032AE60[];
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
extern "C" void fn_80127464(void);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void fn_802E317C(const char *, ...);
extern "C" const char lbl_8032AB78[];
extern "C" u8 lbl_8055DFF9;
extern "C" void *lbl_8055E000;
extern "C" s32 fn_8012BC50(void *, void *, s32);
extern "C" s32 fn_8012E9F0(s32, s32);


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
extern "C" u8 lbl_805599C8[];
extern "C" u8 lbl_805599D0[];
extern "C" u8 lbl_805599E0;

extern "C" void fn_8012E498(void *);
extern void fn_8012CC24(void);
extern "C" u32 fn_8012D3D0(void);
/* fn_8012CC24: two args (object*, char* path list), returns s32. */
extern "C" void fn_8012D33C(u32 *, u32 *);
extern "C" void fn_8012D1A8(s32);
extern "C" void fn_8012D024(void *, s32, s32);

#pragma use_lmw_stmw off
extern "C" s32 fn_8012A388(void *arg0) {
    u8 t0;
    u8 t24;
    u8 t25;
    u8 t26;
    u8 t27;
    u8 t28;
    u8 t29;
    u8 t30;
    u8 t31;
    u8 t6;
    t6 = *(u8 *)((char *)arg0 + 0x24);
    t0 = *(u8 *)((char *)arg0 + 0x26);
    *(u8 *)((char *)arg0 + 0x24) = *(u8 *)((char *)arg0 + 0x27);
    t31 = *(u8 *)((char *)arg0 + 0x20);
    *(u8 *)((char *)arg0 + 0x27) = t6;
    t27 = *(u8 *)((char *)arg0 + 0x21);
    *(u8 *)((char *)arg0 + 0x26) = *(u8 *)((char *)arg0 + 0x25);
    t30 = *(u8 *)((char *)arg0 + 0x28);
    *(u8 *)((char *)arg0 + 0x25) = t0;
    t26 = *(u8 *)((char *)arg0 + 0x29);
    *(u8 *)((char *)arg0 + 0x21) = *(u8 *)((char *)arg0 + 0x22);
    t29 = *(u8 *)((char *)arg0 + 0x2C);
    t25 = *(u8 *)((char *)arg0 + 0x2D);
    t28 = *(u8 *)((char *)arg0 + 0x30);
    t24 = *(u8 *)((char *)arg0 + 0x31);
    *(u8 *)((char *)arg0 + 0x20) = *(u8 *)((char *)arg0 + 0x23);
    *(u8 *)((char *)arg0 + 0x23) = t31;
    *(u8 *)((char *)arg0 + 0x22) = t27;
    *(u8 *)((char *)arg0 + 0x28) = *(u8 *)((char *)arg0 + 0x2B);
    *(u8 *)((char *)arg0 + 0x2B) = t30;
    *(u8 *)((char *)arg0 + 0x29) = *(u8 *)((char *)arg0 + 0x2A);
    *(u8 *)((char *)arg0 + 0x2A) = t26;
    *(u8 *)((char *)arg0 + 0x2C) = *(u8 *)((char *)arg0 + 0x2F);
    *(u8 *)((char *)arg0 + 0x2F) = t29;
    *(u8 *)((char *)arg0 + 0x2D) = *(u8 *)((char *)arg0 + 0x2E);
    *(u8 *)((char *)arg0 + 0x2E) = t25;
    *(u8 *)((char *)arg0 + 0x30) = *(u8 *)((char *)arg0 + 0x33);
    *(u8 *)((char *)arg0 + 0x33) = t28;
    *(u8 *)((char *)arg0 + 0x31) = *(u8 *)((char *)arg0 + 0x32);
    *(u8 *)((char *)arg0 + 0x32) = t24;
    *(u32 *)((char *)arg0 + 0x38) = 0;
    *(u32 *)((char *)arg0 + 0x34) = 0;
    *(u32 *)((char *)arg0 + 0x24) &= 0xFFFF;
    return 0;
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
            const char *message = strings + 0x88;
            fn_802E317C(message, arg0, arg1, arg2);
        }
        *(u32 *)((char *)arg2 + 0x34) |= 8;
    } else {
        const char *message = strings + 0xA8;
        fn_802E30C8(message, arg0, arg1, arg2);
    }
    return result;
}
#pragma use_lmw_stmw reset
#pragma dont_inline reset
#pragma dont_inline on
extern "C" void *fn_8012A570(u32, void *) {
    if (lbl_8055E004 == 0) {
        void *name = lbl_8032A6F8;
        void *p = fn_801284F8(0x20, name);
        if (p) p = fn_8012A13C(p, lbl_8032A6F8, 0x20, 0x18);
        lbl_8055E008 = (void **)p;
    }
    void *p = fn_8012A2D8(lbl_8055E008);
    if (p) ++lbl_8055E004;
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
    const char *messages = lbl_8032A630;
    u32 *data = (u32 *)arg0;
    volatile u8 buffer[5];
    u32 first;
    u8 fourth;
    u32 second;
    u8 third;
    u32 value;

    fn_80132E7C((void *)arg0, 0x30);
    value = data[0];
    if (value != 0x52535430) {
        *(volatile u32 *)buffer = 0x52535430;
        first = buffer[0];
        fourth = buffer[3];
        second = buffer[1];
        third = buffer[2];
        buffer[0] = fourth;
        buffer[3] = first;
        buffer[1] = third;
        buffer[2] = second;
        buffer[4] = 0;
        fn_802E30C8(messages + 0xDC, (const char *)arg1, value, (const char *)buffer);
        goto failed;
    }
    value = data[2];
    if (value != 8) {
        fn_802E30C8(messages + 0x114, (const char *)arg1, value, 8);
        goto failed;
    }
    value = data[1];
    if (value != 0x34) {
        fn_802E30C8(messages + 0x148, (const char *)arg1, value, 0x34);
        goto failed;
    }
    value = data[4];
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
extern "C" s32 fn_802E746C(s32 *, s32 *);
#pragma scheduling off
extern "C" void fn_8012A7FC(void) {
    lbl_8055DFF9 = 1;
    fn_802E2D74(0x32);
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
    s32 result;
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

extern "C" void fn_8012AC28(s32 arg0, s32 arg1) {
    u8 buffer[0x104];
    s32 spC = -1;
    s32 sp8;
    s32 result;
    fn_802E4CA8(buffer, arg0, 0x104);
    result = fn_802E7354(buffer);
    if (result != -1) {
        ((s32 (*)(s32, s32 *, s32 *))fn_802E746C)(result, &spC, &sp8);
        if (arg1 != 0) *(s32 *)arg1 = sp8;
    }
}

#pragma dont_inline reset

extern "C" void fn_8012AC28(s32, s32);
extern "C" void fn_8012AC98(s32 arg0) {
    fn_8012AC28(arg0, 0);
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8012ACA0(void *arg0, void *arg1, s32 arg2) {
    u32 messages = (u32)lbl_8032A630;
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
#pragma pop
extern "C" s32 fn_8012B2C4(s32, s32, s32);
extern "C" void fn_8012B314(s32 arg0, s32 arg1, s32 arg2) {
    fn_8012B2C4(arg1, arg0, arg2);
}

extern "C" void fn_8012B324(void) {

}

extern "C" void fn_8012B328(void) {

}

extern "C" void *fn_8012AFE0(void *, void *);
extern char lbl_8032A960[];
#pragma scheduling invalid_target
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

extern "C" const char lbl_8032A630[];
extern "C" const char lbl_805599A4[1];
extern "C" s32 strstr(const char *, const char *);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012BA1C(void *arg0) {
    struct EntryView {
        u8 pad[0x38];
        s32 value;
    };
    const char *strings = lbl_8032A630;
    s32 offset, i;
    s32 j, offset2;
    register s32 value;
    register EntryView *entry;
    register u32 flags;

    i = 0;
    offset = 0;
    while (i < *(s32 *)((char *)arg0 + 0x88)) {
        entry = (EntryView *)(*(u8 **)((char *)arg0 + 0x60) + offset);
        value = entry->value;
        if (value > 0) fn_802E30C8(strings + 0x470, arg0);
        offset += 0x44;
        i++;
    }
    if (strstr((const char *)arg0, &lbl_805599A4[0]) != 0 &&
        stricmp((const char *)arg0, strings + 0x4A0) != 0) {
        j = 0;
        offset2 = 0;
        while (j < *(s32 *)((char *)arg0 + 0x88)) {
            entry = (EntryView *)(*(u8 **)((char *)arg0 + 0x60) + offset2);
            flags = *(u32 *)((u8 *)entry + 0x34);
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
        i = 0;
        offset = 0;
        while (i < *(s32 *)((u8 *)arg1 + 0x88)) {
            entry = *(u8 **)((u8 *)arg1 + 0x60) + offset;
            flags = *(u32 *)(entry + 0x34);
            if ((flags & 4) != 0) {
                fn_802E317C(lbl_8032AE20);
            }
            i++;
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
extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2) {
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
    u8 *r31 = *(u8 **)((u8 *)arg0 - 8);
    if (r31 == NULL) {
        return 0;
    }
    if (*(s32 *)(r31 + 0x38) != 0) {
        *(s32 *)(r31 + 0x38) -= 1;
    } else {
        fn_802E30C8(lbl_8032AAFC, r31);
    }
    if (*(s32 *)(r31 + 0x38) == 0) {
        if (arg1 != NULL) {
            ((void (*)(void *, s32))arg1)(arg0, arg2);
        }
        if (*(u32 *)(r31 + 0x34) & 4) {
            register Struct8012BC50 *s = (Struct8012BC50 *)r31;
            fn_80128660(s->field_40);
            s->f1 = 0;
            s->field_40 = 0;
            s->field_3c = 0;
            s->f3 = 0;
        }
    }
    return *(s32 *)(r31 + 0x38) == 0;
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
#pragma scheduling off
#pragma dont_inline on
#pragma use_lmw_stmw off
extern "C" void *fn_8012BD98(const char *arg0, void **arg1, s32 arg2) {
    void *p;
    s32 tries;
    p = fn_8012BD3C(*arg1, arg0);
    if (p == 0) {
        tries = 0;
        do {
            lbl_8055DFF9 = 0;
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

#pragma scheduling invalid_target
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
    char *src1;
    s32 pathNameLength, remaining2;
    char *src2, *dst1, *dst2;
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
                dst1 = filename; pathNameLength = 0x80; goto scan_test_1;
scan_step_1:
                --pathNameLength; ++dst1;
scan_test_1:
                if ((s8)*dst1 != 0) goto scan_step_1;
                if (pathNameLength <= 0) goto suffix_done_1;
                src1 = (char *)&lbl_805599D8; goto append_1;
limit_1:
                --pathNameLength; if (pathNameLength > 0) goto append_1; dst1[-1] = 0; goto suffix_done_1;
append_1:
                ch1 = *src1++; *dst1++ = ch1; if ((s8)ch1 != 0) goto limit_1;
suffix_done_1:
                inner = ((s32 (*)(char *))fn_802E36D8)(filename);
                if (inner != -1) {
                    fn_802E3A14(inner, 0x14); fn_802E3804(inner, header, 0x14);
                    if (header[0] == 0) {
                        src2 = filename; dst2 = name; remaining2 = 0x80; goto copy_name_body;
copy_name_limit:
                        --remaining2; if (remaining2 > 0) goto copy_name_body; dst2[-1] = 0; goto copy_name_done;
copy_name_body:
                        ch2 = *src2++; *dst2++ = ch2; if ((s8)ch2 != 0) goto copy_name_limit;
copy_name_done:
                        ;
                        if ((s8)*fn_80029004(name, '.') != 0) *fn_80029004(name, '.') = 0;
                        dst1 = name; pathNameLength = 0x80; goto scan_test_2;
scan_step_2:
                        --pathNameLength; ++dst1;
scan_test_2:
                        if ((s8)*dst1 != 0) goto scan_step_2;
                        if (pathNameLength <= 0) goto suffix_done_2;
                        src1 = (char *)&lbl_805599E0; goto append_2;
limit_2:
                        --pathNameLength; if (pathNameLength > 0) goto append_2; dst1[-1] = 0; goto suffix_done_2;
append_2:
                        ch1 = *src1++; *dst1++ = ch1; if ((s8)ch1 != 0) goto limit_2;
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
extern "C" s32 fn_8012B534(s32 *, s32);
extern "C" s32 fn_8012C33C(void) {
    s32 sp8;
    return ((s32 (*)(s32, s32 *, s32))fn_8012B534)(0, &sp8, 0) != 0;
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
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8012C41C(s32 (*arg0)(void *, void *, void *, s32), s32 arg1, const char *arg2) {
    s32 off;
    void *node;
    s32 i;
    for (node = lbl_8055E000; node != NULL; node = *(void **)((u8 *)node + 0xA8)) {
        if (arg2 == 0 || stricmp((const char *)node, arg2) == 0) {
            i = 0;
            off = 0;
            while (i < *(s32 *)((u8 *)node + 0x88)) {
                u8 *entry = *(u8 **)((u8 *)node + 0x60) + off;
                if (*(u32 *)(entry + 0x34) & 8) {
                    volatile void *param = *(void **)(entry + 0x20);
                    if (arg0(entry, (void *)param, node, arg1) == 0) return;
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
    s32 *record;
    u8 *source, *destination, byte;
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
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        if (record[0x34 / 4] & 4)
            fn_802E317C(lbl_8032AE20);
        count++;
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        value = record[0x34 / 4];
        index += 0x44;
        record[0x34 / 4] = value & ~0xF;
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
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        if (record[0x34 / 4] & 4)
            fn_802E317C(lbl_8032AE20);
        count++;
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        value = record[0x34 / 4];
        index += 0x44;
        record[0x34 / 4] = value & ~0xF;
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
#pragma dont_inline reset

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
extern "C" void fn_8012D1A8(s32);
extern "C" void fn_8012D3D8(s32 arg0) {
    fn_8012D40C(arg0);
    fn_8012D1A8(arg0);
}

#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8012D40C(s32 arg0) {
    u8 *self = (u8 *)arg0;
    s32 *object = (s32 *)self;
    s32 state, count, index, value, result, temp, handle, size, limit, done;
    s32 *record;
    u8 *data, *source, *destination, byte;
    void *parser;
    u8 parseBuffer[0x40];

    state = object[0xB8 / 4];
    if (state == 2 && fn_802E7544(object[0xB4 / 4]) != 0) {
        fn_802E7548(object[0xB4 / 4]);
        data = *(u8 **)(self + 0xC8);
        object[0xB4 / 4] = -1;
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
        object[0xA4 / 4] = 0;
        if (object[0x84 / 4] + object[0x90 / 4] > object[0xCC / 4])
            fn_802E317C(lbl_8032ADF4);
        if (object[0x78 / 4] & 1) {
            object[0x64 / 4] = 0;
            result = fn_8012ACA0(self + 4, (u8 *)*(void **)(self + 0xC8) + object[0x84 / 4], object[0xC0 / 4] - object[0x84 / 4]);
        } else {
            object[0x64 / 4] = (s32)((u8 *)*(void **)(self + 0xC8) + object[0x84 / 4]);
            result = fn_8012AA60(self + 4, object[0xC0 / 4] - object[0x84 / 4], object[0x84 / 4]);
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
    if (state == 2) {
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
    } else if (state == 3) {
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
    }
    object[0xB8 / 4] = 1;
    ((void (*)(void *))fn_8012B324)(self + 0x24);
    object[0xBC / 4]++;
    done = 0;
    while (!done) {
        parser = ((void *(*)(void *, void *, s32))fn_8012B314)(self + 4, parseBuffer, object[0xBC / 4]);
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
                source = (u8 *)parser;
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

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012DBD0(void) {
    void *object;
    s32 i;
    u32 offset;
    s32 last;
    u32 *base;
    u32 endAddress;

    if (lbl_8055DFFC != 0) {
        object = fn_801284F8(0xA24, lbl_8032ACA0);
        if (object != 0) {
            *(void **)object = lbl_8032ACB0;
            *(s32 *)((char *)object + 0xC) = 0x20;
            *(void ***)((char *)object + 8) = (void **)((char *)object + 0x18);
            *(void **)((char *)object + 0x14) = 0;
            *(s32 *)((char *)object + 0x10) = 0;
            i = 0;
            offset = 0;
            goto loop_test;
        loop_body:
            base = *(u32 * volatile *)((char *)object + 8);
            *(u32 *)((char *)base + offset) = (u32)((char *)base + (u32)(i + 1) * 0x50);
            offset += 0x50;
            i += 1;
        loop_test:
            last = *(s32 *)((char *)object + 0xC) - 1;
            if (i < last) goto loop_body;
            base = *(u32 * volatile *)((char *)object + 8);
            *(u32 *)((char *)base + (u32)last * 0x50) = 0;
            endAddress = (u32)object + 0xA18;
            base = *(u32 * volatile *)((char *)object + 8);
            *(u32 *)((char *)object + 0x14) = (u32)base;
            *(s32 *)((char *)object + 0xA18) = 0;
            *(u32 *)((char *)object + 0xA1C) = endAddress;
            fn_80127CF4((s32)object, (s32)lbl_8032ACD0);
            *(u8 *)((char *)object + 0xA20) = 0;
        }
        lbl_8055E014 = (nw4r::ef::Effect *)object;
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
extern "C" void fn_8012DEE4(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s32 one = 1;
    s32 zero = 0;
    void *entry;
    s32 done;
    s32 state;

    if (obj[0xA20] != 0) return;
    obj[0xA20] = (u8)one;
    do {
        done = 0;
        entry = *(void **)(obj + 0xA18);
        if (entry != 0) {
            state = fn_8012D838(*(s32 *)((u8 *)entry + 0x4C));
            if (state == 1) goto after_state;
            if (state < 1) {
                if (state >= 0) goto state_zero;
                goto after_state;
            }
            if (state < 3) goto state_two;
            goto after_state;
        state_zero:
            fn_8012CC24(*(void **)((u8 *)entry + 0x4C), (u8 *)entry + 0xC);
            goto after_state;
        state_two:
            {
                void *node = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
                *(s32 *)((u8 *)node + 0x9C) = *(s32 *)((u8 *)entry + 8);
                *(u8 *)((u8 *)node + 0xAD) = (u8)one;
            }
            entry = *(void **)(obj + 0xA18);
            if (entry != 0) {
                void *next = *(void **)((u8 *)entry + 4);
                *(void **)(obj + 0xA18) = next;
                if (next == 0) *(void **)(obj + 0xA1C) = obj + 0xA18;
                *(void **)((u8 *)entry + 4) = (void *)zero;
            }
            done = 1;
        after_state:
            ;
        }
    } while (done != 0);
    obj[0xA20] = 0;
}
#pragma pop

extern "C" void fn_8012DFCC(Unk8012DFCCList *arg0, Unk8012DFCCNode *arg1) {
    *arg0->tail = arg1;
    arg0->tail = &arg1->next;
    arg1->next = 0;
}

extern "C" void fn_8012DFE8(void *arg0, const char *arg1, s32 arg2) {
    char *dst = (char *)arg0 + 0xc;
    int count = 0x40;
    while ((*dst++ = *arg1++) != 0) {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }
    *(s32 *)((u8 *)arg0 + 0x4c) = fn_8012CAA0(arg2, (void *)arg1);
    *(s32 *)((u8 *)arg0 + 8) = 1;
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

extern "C" void fn_8012D024(void *, s32, s32);
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
    void *object;
    void *effect;
    void *entry;
    s32 remaining;
    s32 removed;

    fn_8012E81C((s32)arg0);
    object = fn_8012BD3C(lbl_8055E000, (const char *)arg0);
    if (object != 0) {
        remaining = *(s32 *)((u8 *)object + 0x9C) - 1;
        *(s32 *)((u8 *)object + 0x9C) = remaining;
        if (remaining == 0) {
            effect = lbl_8055E014;
            if (effect != 0) {
                removed = 0;
                entry = (void *)fn_8012E490((s32 *)((u8 *)effect + 0xA18));
                while (entry != 0) {
                    if (stricmp((const char *)((u8 *)entry + 0xC), (const char *)arg0) == 0) {
                        fn_8012E67C((s32)effect, (s32)arg0);
                        break;
                    }
                    entry = *(void **)((u8 *)entry + 4);
                }

                entry = (void *)fn_8012E490((s32 *)((u8 *)effect + 0xA18));
                while (entry != 0) {
                    if (stricmp((const char *)((u8 *)entry + 0xC), (const char *)arg0) == 0) {
                        fn_802E317C(lbl_8032ACF4);
                    }
                    entry = *(void **)((u8 *)entry + 4);
                }

                for (entry = (void *)fn_8012E674((u8 *)effect + 8);
                     entry != 0; entry = *(void **)entry) {
                    if (stricmp((const char *)((u8 *)entry + 0xC), (const char *)arg0) == 0) {
                        fn_8012E630(entry);
                        fn_8012E5E4((u8 *)effect + 8, entry);
                        removed = 1;
                        continue;
                    }
                }
                if (removed != 0) return;
            }
            fn_8012BB20((s32)&lbl_8055E000, object);
        }
    }
}

extern "C" void fn_8012E5E4(void *arg0, void *arg1) {
    void **link = (void **)((u8 *)arg0 + 8);
    void *node;
    s32 found = 0;
    node = *link;
    while (node != 0) {
        if (node == arg1) {
            *link = *(void **)node;
            found = 1;
            break;
        }
        link = (void **)node;
        node = *link;
    }
    if (found != 0) {
        *(void **)arg1 = *(void **)((u8 *)arg0 + 0xC);
        *(void **)((u8 *)arg0 + 0xC) = arg1;
    }
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

extern "C" const char lbl_8032AD2C[];
extern "C" const char lbl_8032AD6C[];
extern "C" const char lbl_8032AD88[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012E81C(s32 arg0) {
    nw4r::ef::Effect *effect = lbl_8055E014;
    s32 limit;
    void *entry;
    s32 start;
    s32 current;
    const char *format;

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
 for (i=0, p=(u8 *)arg0+4; i<2; i++, p+=0x10) {
  if (*(s32 *)(p+4)) {
   fn_8012C958((void *)*(s32 *)(p+4));
   fn_8012C90C((void *)*(s32 *)(p+4));
   *(s32 *)(p+4)=0;
  }
 }
 fn_80128670(*(s32 *)((u8 *)arg0+8));
 fn_80128668(arg0);
}

extern "C" s32 fn_8012C5B8(s32, s32, s32);
extern "C" s32 fn_8012C6F0(void *);
extern "C" void fn_8012EE80(void *);
extern "C" s32 fn_8012EDA8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *p;
    s32 *base = (s32*)((char*)arg0 + 4);
    s32 j;
    s32 i;
    s32 result;
    for (p = base, i = 0; i < 2; i++, p += 4) {
        if (p[1]) {
            fn_8012C90C((void*)p[1]);
            fn_8012C958((void*)p[1]);
            p[1] = 0;
            p[3] = 0;
        }
    }
    *(s32*)((char*)arg0 + 0x28) = 0;
    for (j = 0; j < 2; j++, base += 4) {
        result = fn_8012C5B8(arg1, arg2, arg3);
        base[1] = result;
        if (!result) return 0;
        *(s32*)((char*)arg0 + 0x24) = fn_8012C6F0((void*)result);
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
    struct Entry {
        s32 first;
        void *file;
        s32 position;
        s32 state;
    };
    struct Buffer {
        s32 size;
        Entry entries[2];
        s32 limit;
        s32 boundary;
    };

    Buffer *buffer = (Buffer *)arg0;
    Entry *entries = buffer->entries;
    Entry *cursor = entries;
    s32 i;
    s32 end = buffer->boundary;
    s32 status;
    s32 pos;
    s32 len;
    s32 request;

    for (i = 0; i < 2; i++, cursor++) {
        status = cursor->state;
        if (status != 0) {
            if (status == 1 && fn_8012C7FC(cursor->file, 0))
                cursor->state = 2;
            pos = cursor->position + buffer->size;
            if (pos > end)
                end = pos;
        }
    }

    i = 0;
    cursor = 0;
    for (; i < 2; i++, entries++) {
        status = entries->state;
        if (status != 0)
            goto check_state;
        if (entries->file != 0)
            goto process_entry;

check_state:
        if (status != 2)
            goto next_entry;
        pos = entries->position + buffer->size;
        if (pos >= buffer->boundary)
            goto next_entry;

process_entry:
        entries->position = end;
        pos = end;
        len = buffer->size;
        end += len;
        request = len;
        if (pos + len > buffer->limit)
            request = buffer->limit - pos;
        if (request > 0) {
            fn_8012C720(entries->file, entries->first, request, pos);
            entries->state = 1;
        } else {
            entries->state = (s32)cursor;
        }

next_entry:
        ;
    }
}
#pragma pop

extern "C" s32 fn_8012EFB0(void *arg0, void *arg1, s32 arg2) {
    s32 pos = *(s32 *)((u8 *)arg0 + 0x28);
    s32 i;
    if (pos + arg2 >= *(s32 *)((u8 *)arg0 + 0x24)) return 0;
    for (i = 0; i < 2; i++) {
        u8 *p = (u8 *)arg0 + 4 + i * 0x10;
        s32 start;
        if (*(s32 *)(p + 0xC) != 2) continue;
        start = *(s32 *)(p + 8);
        if (pos >= start && pos < start + *(s32 *)arg0) {
            memcpy(arg1, (u8 *)*(void **)p + (pos - start), arg2);
            *(s32 *)((u8 *)arg0 + 0x28) += arg2;
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
    struct Item {
        u8 pad[0x20];
        s32 key;
        s32 value;
    };
    struct Manager {
        u8 pad[0x60];
        Item *items;
    };
    struct Allocation {
        s32 magic;
        Item *item;
        Manager *manager;
        s32 state;
        s32 reserved10;
        s32 reserved14;
    };

    s32 index;
    s32 result = 0;
    Manager *manager = (Manager *)((s32 *(*)(s32, s32 *, s32))fn_8012B534)(arg0, &index, 1);
    if (manager != 0) {
        Item *item = (Item *)((char *)manager->items + index * 0x44);
        if ((u32)item->key == (u32)arg1) {
            *(s32 *)arg2 = item->value;
            void *allocation = fn_8012A570(0x18, (void *)lbl_8032ABF8);
            if (allocation != 0) {
                volatile Allocation *object = (volatile Allocation *)allocation;
                object->state = -1;
                object->reserved10 = 0;
                object->item = 0;
                object->manager = 0;
                object->reserved14 = 0;
                object->magic = 0x19AFEE2A;
                object->item = item;
                result = (s32)allocation;
                object->manager = manager;
            }
        } else {
            u8 queryText[5];
            u8 entryText[5];
            u8 zero = 0;
            u8 q0, q3, q1, q2;
            u8 e0, e3, e1, e2;

            *(u32 *)queryText = (u32)arg1;
            queryText[4] = zero;
            q0 = queryText[0];
            q3 = queryText[3];
            q1 = queryText[1];
            q2 = queryText[2];
            queryText[0] = q3;
            queryText[3] = q0;
            queryText[1] = q2;
            queryText[2] = q1;

            *(u32 *)entryText = (u32)item->key;
            entryText[4] = zero;
            e0 = entryText[0];
            e3 = entryText[3];
            e1 = entryText[1];
            e2 = entryText[2];
            entryText[0] = e3;
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
extern "C" void fn_8012C720(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *context;
    void *file = *(void * volatile *)((u8 *)arg0 + 4);
    void *successFile;
    s32 offset;
    s32 temp;
    if ((*(volatile u32 *)((u8 *)file + 0x34) & 8) == 0) {
        successFile = *(void * volatile *)((u8 *)arg0 + 4);
        context = *(void * volatile *)((u8 *)arg0 + 8);
        temp = arg3 + *(volatile s32 *)((u8 *)successFile + 0x2C);
        context = (void *)*(volatile s32 *)((u8 *)context + 0x80);
        offset = (s32)context + temp;
        context = *(void * volatile *)((u8 *)arg0 + 8);
        *(s32 *)((u8 *)arg0 + 0xC) = ((s32 (*)(s32, s32, s32, s32))fn_802E748C)(
            *(volatile s32 *)((u8 *)context + 0xA4) + offset / 2048, arg1, arg2, arg3);
        *(s32 *)((u8 *)arg0 + 0x10) = arg1 + (offset & 0x7FF);
        *(s32 *)((u8 *)arg0 + 0x14) = arg2;
    } else {
        fn_802E30C8(lbl_8032AC34, file);
        file = *(void * volatile *)((u8 *)arg0 + 4);
        memcpy((void *)arg1, (void *)(*(u32 *)((u8 *)file + 0x3C) + 8), *(u32 *)((u8 *)file + 0x28));
        *(s32 *)((u8 *)arg0 + 0x10) = arg1;
        *(s32 *)((u8 *)arg0 + 0xC) = -1;
        *(s32 *)((u8 *)arg0 + 0x14) = arg2;
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_8012C7FC(void *arg0, s32 *arg1) {
    void *entry;
    s32 result = 0;
    s32 temp;
    temp = *(s32 *)((char *)arg0 + 0xC);
    if (temp != -1 && fn_802E7544(temp)) {
        fn_802E7548(*(s32 *)((char *)arg0 + 0xC));
        *(s32 *)((char *)arg0 + 0xC) = -1;
    }
    temp = *(s32 *)((char *)arg0 + 0xC);
    if (temp == -1 && *(s32 *)((char *)arg0 + 0x10)) {
        entry = *(void **)((char *)arg0 + 4);
        if (*(s32 *)((char *)arg0 + 0x14) < *(s32 *)((char *)entry + 0x28) ||
            *(u32 *)((char *)entry + 0x30) == ((u32 (*)(void))fn_80132E7C)()) {
            result = *(s32 *)((char *)arg0 + 0x10);
            if (arg1) *arg1 = *(s32 *)((char *)entry + 0x28);
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
    void *p = fn_8012A2D8(lbl_8055E010);
    if (p) {
        s32 count = lbl_8055E00C;
        count++;
        lbl_8055E00C = count;
    }
}

extern "C" s32 stricmp(const char *, const char *);
extern "C" s32 fn_8012B85C(s32, s32, s32, s32, s32, s32);
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
extern "C" s32 fn_8012CAA0(s32 arg0, void *arg1) {
    void *obj = ((void *(*)(s32, void *))fn_8012C9C8)(0xD0, &lbl_805599C0);
    if (obj != 0) {
        s32 zero = 0;
        *(u8 *)((u8 *)obj + 0xB0) = zero;
        *(s32 *)((u8 *)obj + 0xB8) = 1;
        *(s32 *)((u8 *)obj + 0xB4) = -1;
        *(s32 *)((u8 *)obj + 0xCC) = (arg0 + 0x7FF) & ~0x7FF;
        fn_801282F4();
        fn_801282EC(0x80);
        *(s32 *)((u8 *)obj + 0xC8) =
            ((s32 (*)(void *, s32))fn_801284F0)(arg1, *(s32 *)((u8 *)obj + 0xCC));
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
            i = 0; offset = 0;
            while (i < *(s32 *)((char *)arg0 + 0x88)) {
                base = *(void **)((char *)arg0 + 0x60);
                entry = (char *)base + offset;
                flags = *(u32 *)((char *)entry + 0x34);
                if (flags & 4) fn_802E317C(lbl_8032AE20);
                base = *(void **)((char *)arg0 + 0x60);
                entry = (char *)base + offset;
                flags = *(u32 *)((char *)entry + 0x34);
                ++i;
                offset += 0x44;
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

