// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8024CC54(void *, void *, int);
extern unsigned int fn_8024C768(void);
extern signed char lbl_8055F2C8;
int fn_8024CEF0(void);
extern int fn_8000D984(int);
extern void fn_8000DA80(void);
extern int fn_8000DC70(int);
extern void fn_8000DA1C(void *);
extern int fn_802E8D84(void);
extern void fn_802E7128(void);
void fn_802328D4(void *);
void fn_80128668(void *);
int fn_8000DA10(void);
int fn_8000DB34(int);
int fn_8000DB8C(int);
int fn_8000DBAC(int);
void fn_801345D8(void *, int, const char *, ...);
extern char lbl_80498A00[];
extern int lbl_80498A48[];
extern char lbl_8055C018[];
void fn_8024C370(void) {}

int sprintf(char *, const char *, ...);
extern void fn_80232BA4(char *, int, int, int, float, float, float, float, float);
extern char lbl_8055C08C;
extern float lbl_80563930, lbl_80563940;
extern float fn_8023293C();
extern void fn_80230924(void *, float, float, float, float, float);
extern void fn_80230C30(float *, float *, int, int);
extern double lbl_80563938;

#pragma push
#pragma use_lmw_stmw off
void *fn_8024C374(void *arg0, int arg1) {
    struct Obj {
        char pad0[0x18];
        char field_18;
        char pad1[0x4C - 0x19];
        void *field_4C;
        char pad2[0x78 - 0x50];
        void *field_78;
    } *obj = arg0;
    if (arg0 != 0) {
        if (&obj->field_78 != 0) {
            fn_802328D4(obj->field_78);
            obj->field_78 = 0;
        }
        if (&obj->field_18 != 0 && &obj->field_4C != 0) {
            fn_802328D4(obj->field_4C);
            obj->field_4C = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
void *fn_8024C3FC(void *arg0, int arg1) {
    struct Local { char pad[0x34]; void *field_34; } *obj = arg0;
    if (arg0 != 0) {
        if (&obj->field_34 != 0) {
            fn_802328D4(obj->field_34);
            obj->field_34 = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
__declspec(section ".sdata") extern char lbl_8055C018[];
void fn_8024C464(void) {
    char *buffer = lbl_80498A00;
    int *state = lbl_80498A48;
    int i = 0;
    int zero = 0;
    int one = 1;
    int two = 2;
    do {
        fn_801345D8(buffer, 0x12, lbl_8055C018, fn_8000DB34(i));
        if (fn_8000DBAC(i) == 0 && i == fn_8000DA10()) {
            if (fn_8000DB8C(i) != 0)
                *state = two;
            else
                *state = one;
        } else {
            *state = zero;
        }
        i++;
        buffer += 0x12;
        state++;
    } while (i < 4);
}
#pragma pop

#pragma dont_inline on
int fn_8024C524(void) {
    fn_802E712C();
    fn_802E6CA8();
    fn_8024C464();
    return 0;
}
#pragma dont_inline reset
void fn_802E6FBC(void);
void fn_8000DA80(void);
int fn_8023FAD4(void *, int);
extern int lbl_8055F2C4;
extern char lbl_80343F78[];
extern char lbl_80343F68[];
int fn_80131234(const char *);
int fn_80215214(int, int);
#pragma dont_inline on
int fn_8024C550(void) {
    fn_802E6FBC();
    fn_8024C464();
    return 0;
}
#pragma scheduling invalid_target
int fn_8024C578(int arg0) {
    int result;
    if (((int (*)(void))fn_8000DBAC)() != 0) {
        struct S { int w[4]; short h; } s;
        s.w[0] = 0;
        s.w[1] = 0;
        s.w[2] = 0;
        s.w[3] = 0;
        s.h = 0;
        if (fn_8023FAD4(&s, 0x12) != 0) {
            fn_8000D984(arg0);
            fn_8000DA80();
            fn_8000DA1C(&s);
            fn_802E6FBC();
            fn_8024C464();
            result = 1;
        } else {
            result = 0;
        }
    } else {
        lbl_8055F2C4 = (int)(lbl_80498A00 + arg0 * 0x12);
        fn_8000D984(arg0);
        fn_8024C464();
        result = 1;
    }
    return result;
}
#pragma scheduling reset

#pragma push
#pragma use_lmw_stmw off
int fn_8027B8E4(int, int);
int fn_8027B984(int, int);
int fn_80214A9C(int);
extern int fn_80214CB4();
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8024C628(void) {
    int offset, i, all, player, active;
    player = fn_8000DA10();
    i = 0;
    offset = 0;
    for (; i < 4; ++i) {
        all = 1;
        {
            int j;
            for (j = 0; j < 3; ++j) if (fn_8027B8E4(j, i) == 0) all = 0;
        }
        {
            int k;
            for (k = 0; k < 2; ++k) if (fn_8027B984(k, i) == 0) all = 0;
        }
        if (all) fn_80214A9C(i + 1); else fn_80214A9C(i + 0xB);
        if (i == player) { active = offset + all; fn_80214CB4(active); }
        offset += 2;
    }
}
#pragma scheduling on
int fn_8024C6F4(void) {
    int first;
    int result = 0;
    if (((int (*)())fn_8000DBAC)() == 0 || ((int (*)(int, int, int))fn_80215214)(fn_80131234(lbl_80343F68), (first = fn_80131234(lbl_80343F78)), 0) != 0) {
        result = 1;
    }
    return result;
}

extern int fn_802146BC(int *, int, int, int);
extern void fn_802149C4(int);
extern void fn_802149FC(int);
extern int fn_8024C524(void);
extern int fn_8024C578(int);
extern int lbl_802FA538[];
extern int lbl_802FA54C[];
extern char lbl_804989E8[];
extern char lbl_8055B860[];
extern char lbl_8055BAC0[], lbl_8055C01C[], lbl_8055C024[], lbl_8055C02C[];
extern char lbl_8055C034[], lbl_8055C03C[], lbl_8055C044[], lbl_8055C04C[];
extern char lbl_8055C054[], lbl_8055C05C[], lbl_8055C064[];
extern char lbl_8055C06C[], lbl_8055C074[], lbl_8055C07C[], lbl_8055C084[];
extern unsigned char lbl_8055F2C9, lbl_8055F2CA, lbl_8055F2CC;
__declspec(section ".sdata") extern char lbl_8055B860[];
__declspec(section ".sdata") extern char lbl_8055BAC0[], lbl_8055C01C[], lbl_8055C024[], lbl_8055C02C[];
__declspec(section ".sdata") extern char lbl_8055C034[], lbl_8055C03C[], lbl_8055C044[], lbl_8055C04C[];
__declspec(section ".sdata") extern char lbl_8055C054[], lbl_8055C05C[], lbl_8055C064[];
__declspec(section ".sdata") extern char lbl_8055C06C[], lbl_8055C074[], lbl_8055C07C[], lbl_8055C084[];
#pragma scheduling invalid_target
unsigned int fn_8024C768(void) {
    int args[90];
    int temp_r3;
    int var_r15;
    int var_r16;
    char *temp_r5;
    char *temp_r6;
    char *temp_r7;
    char *temp_r8;
    register char *base;
    register int *table;

    base = lbl_804989E8;
    table = (int *)base;
    temp_r6 = base + 0x18;
    args[12] = (int)(temp_r6);
    args[8] = 0;
    args[9] = 0;
    temp_r5 = base + 0x60;
    args[6] = 8;
    args[11] = 3;
    args[7] = (int)((char *)&fn_8024C628);
    args[5] = (int)(lbl_8055BAC0);
    args[10] = (int)(lbl_8055C01C);
    args[13] = 0;
    args[14] = 0;
    args[16] = 0;
    args[15] = (int)(lbl_8055C01C);
    args[17] = (int)((char *)&fn_8024C6F4);
    args[18] = 0;
    args[19] = 0;
    args[21] = 2;
    args[20] = (int)(lbl_8055C024);
    args[22] = (int)(temp_r5);
    args[23] = 0;
    args[24] = 0;
    args[26] = 3;
    args[25] = (int)(lbl_8055C02C);
    args[27] = (int)(temp_r6 + 0x12);
    args[28] = 0;
    args[29] = 0;
    args[31] = 0;
    args[30] = (int)(lbl_8055C02C);
    args[32] = (int)((char *)&fn_8024C6F4);
    args[33] = 1;
    args[34] = 0;
    args[36] = 2;
    args[35] = (int)(lbl_8055C034);
    args[37] = (int)(temp_r5 + 4);
    args[38] = 0;
    args[39] = 0;
    args[41] = 3;
    args[40] = (int)(lbl_8055C03C);
    args[42] = (int)(temp_r6 + 0x24);
    args[43] = 0;
    args[44] = 0;
    args[46] = 0;
    args[45] = (int)(lbl_8055C03C);
    args[47] = (int)((char *)&fn_8024C6F4);
    temp_r8 = temp_r6 + 0x36;
    temp_r7 = temp_r5 + 0xC;
    args[50] = (int)(lbl_8055C044);
    args[52] = (int)(temp_r5 + 8);
    args[48] = 2;
    args[49] = 0;
    args[51] = 2;
    args[53] = 0;
    args[54] = 0;
    args[56] = 3;
    args[55] = (int)(lbl_8055C04C);
    args[57] = (int)(temp_r8);
    args[58] = 0;
    args[59] = 0;
    args[61] = 0;
    args[60] = (int)(lbl_8055C04C);
    args[62] = (int)((char *)&fn_8024C6F4);
    args[63] = 3;
    args[64] = 0;
    args[66] = 2;
    args[65] = (int)(lbl_8055C054);
    args[67] = (int)(temp_r7);
    args[68] = 0;
    args[69] = 0;
    args[71] = 0;
    args[70] = (int)(lbl_8055C05C);
    args[72] = 0;
    args[73] = 4;
    args[74] = 0;
    args[76] = 0;
    args[75] = (int)(lbl_8055C064);
    args[77] = 0;
    args[78] = 5;
    args[79] = 0;
    args[81] = 6;
    args[80] = (int)(lbl_8055B860);
    args[82] = 0;
    args[83] = -1;
    args[84] = 0x1B;
    args[85] = table[0];
    args[86] = table[1];
    args[87] = table[2];
    args[88] = table[3];
    args[89] = table[4];
    args[0] = *(int *)((char *)lbl_802FA538 + 0);
    args[2] = *(int *)((char *)lbl_802FA538 + 8);
    args[3] = *(int *)((char *)lbl_802FA538 + 0xC);
    args[4] = *(int *)((char *)lbl_802FA538 + 0x10);
    args[1] = (int)(&args[5]);
    ((void (*)(char *, int, int, int, char *, char *, int, int))fn_8024C464)(lbl_8055B860, 6, 5, 4, temp_r7, temp_r8, 0x1B, 2);
    if ((signed char) lbl_8055F2CA == 0) {
        lbl_8055F2CC = 1;
        lbl_8055F2CA = 1;
    }
    var_r15 = 0;
    var_r16 = -1;
loop_19:
    if (var_r15 == 0) {
        if (((int) lbl_8055F2CC != 0) && ((int) lbl_8055F2C9 != 0)) {
            fn_802149C4(args[0]);
        }
        temp_r3 = fn_802146BC(&args[0], -0x3E7, -0x3E7, 1);
        var_r16 = temp_r3;
        if (temp_r3 == -1) {
            lbl_8055F2CC = 1;
            fn_802149FC(args[0]);
        } else {
            lbl_8055F2CC = 0;
        }
        switch (var_r16) {
        case -1:
            var_r15 = 1;
            break;
        case 4:
            fn_8024C524();
            break;
        case 5:
            fn_8024C550();
            break;
        default:
            var_r15 = fn_8024C578(var_r16);
            break;
        }
        goto loop_19;
    }
    return (unsigned int) ((-1 - var_r16) | (var_r16 + 1)) >> 0x1FU;
}
void fn_8024CAAC(int arg0) {
    /* Initialize 4 player/slot entries: copy a resource name (0x12 bytes) into lbl_80498A58, fill/clear per-slot data in lbl_80498AA0, and set the per-slot flag in lbl_8055F2D0. */
    extern char lbl_80498A58[];
    extern char lbl_80498AA0[];
    extern const char lbl_80343FA0[];
    extern const char lbl_80343FB4[];
    extern unsigned char lbl_8055F2D0;
    extern int fn_8001EF98(int, int);
    extern void fn_801308F4(void *, int, int);
    extern void *memset(void *, int, unsigned int);

    char nameFormatBuf[0x64];
    char *nameDest = lbl_80498A58;
    char *dataDest = lbl_80498AA0;
    unsigned char *flagDest;
    int slotIndex;

    slotIndex = 0;
    flagDest = &lbl_8055F2D0;

    do {
        if (fn_8000DBAC(slotIndex) != 0) {
            const char *src = (const char *)fn_80131234(lbl_80343FA0);
            int count = 0x12;
            char *dst = nameDest;
            goto copy_char1;
        count_more1:
            count--;
            if (count > 0)
                goto copy_char1;
            dst[-1] = 0;
            goto copy_done1;
        copy_char1:
            if ((signed char)(*dst++ = *src++) != 0)
                goto count_more1;
        copy_done1:
            memset(dataDest, 0, 0x64);
            *flagDest = arg0;
        } else {
            const char *src;
            int count;
            char *dst;
            fn_801345D8(nameFormatBuf, 0x64, lbl_80343FB4, slotIndex + 1);
            src = (const char *)fn_80131234(nameFormatBuf);
            count = 0x12;
            dst = nameDest;
            goto copy_char2;
        count_more2:
            count--;
            if (count > 0)
                goto copy_char2;
            dst[-1] = 0;
            goto copy_done2;
        copy_char2:
            if ((signed char)(*dst++ = *src++) != 0)
                goto count_more2;
        copy_done2:
            fn_801308F4(dataDest, 0x64, ((int (*)(int, int))fn_8001EF98)(0, slotIndex));
            *flagDest = 1;
        }
        slotIndex++;
        nameDest += 0x12;
        dataDest += 0x64;
        flagDest++;
    } while (slotIndex < 4);
}

#pragma dont_inline reset
#pragma scheduling on
extern unsigned char lbl_8055F2D0;
int fn_80214B44(int);
int fn_80214CB4(void);
void fn_8024CBF4(void) {
    unsigned char *p = &lbl_8055F2D0;
    int i = 0;
    do {
        if (*p == 0)
            fn_80214B44(i + 1);
        i++;
        p++;
    } while (i < 4);
    fn_8000DA10();
    fn_80214CB4();
}

#pragma scheduling invalid_target
#pragma dont_inline on
int fn_8024CC54(void *out, void *arg1, int arg2) {
    int args[90];
    char *base = lbl_804989E8;
    char *temp_r11 = base + 0x70;
    char *temp_r10 = base + 0xB8;
    int temp_r3;

    args[22] = (int)arg1;
    args[37] = (int)arg1;
    args[8] = 0;
    args[9] = 0;
    args[7] = (int)((char *)&fn_8024CBF4);
    args[6] = 8;
    args[5] = (int)lbl_8055BAC0;
    args[10] = (int)lbl_8055C01C;
    args[11] = 3;
    args[12] = (int)temp_r11;
    args[13] = 0;
    args[14] = 0;
    args[16] = 3;
    args[15] = (int)lbl_8055C06C;
    args[17] = (int)temp_r10;
    args[18] = 0;
    args[19] = 0;
    args[21] = 0;
    args[20] = (int)lbl_8055C01C;
    args[23] = 0;
    args[24] = 0;
    args[26] = 3;
    args[25] = (int)lbl_8055C02C;
    args[27] = (int)(temp_r11 + 0x12);
    args[28] = 0;
    args[29] = 0;
    args[31] = 3;
    args[30] = (int)lbl_8055C074;
    args[32] = (int)(temp_r10 + 0x64);
    args[33] = 0;
    args[34] = 0;
    args[36] = 0;
    args[35] = (int)lbl_8055C02C;
    args[38] = 1;
    args[39] = 0;
    args[41] = 3;
    args[40] = (int)lbl_8055C03C;
    args[42] = (int)(temp_r11 + 0x24);
    args[43] = 0;
    args[44] = 0;
    args[45] = (int)lbl_8055C07C;
    args[47] = (int)(temp_r10 + 0xC8);
    args[55] = (int)lbl_8055C04C;
    args[50] = (int)lbl_8055C03C;
    args[46] = 3;
    args[48] = 0;
    args[49] = 0;
    args[51] = 0;
    args[52] = (int)arg1;
    args[53] = 2;
    args[54] = 0;
    args[56] = 3;
    args[57] = (int)(temp_r11 + 0x36);
    args[58] = 0;
    args[59] = 0;
    args[61] = 3;
    args[60] = (int)lbl_8055C084;
    args[62] = (int)(temp_r10 + 0x12C);
    args[63] = 0;
    args[64] = 0;
    args[66] = 0;
    args[65] = (int)lbl_8055C04C;
    args[67] = (int)arg1;
    args[68] = 3;
    args[69] = 0;
    args[71] = 0;
    args[70] = (int)lbl_8055C05C;
    args[72] = 0;
    args[73] = 4;
    args[74] = 0;
    args[76] = 0;
    args[75] = (int)lbl_8055C064;
    args[77] = 0;
    args[78] = 5;
    args[79] = 0;
    args[81] = 6;
    args[80] = (int)lbl_8055B860;
    args[82] = 0;
    args[83] = -1;
    args[84] = 0x1B;
    args[85] = *(int *)(base + 0);
    args[86] = *(int *)(base + 4);
    args[87] = *(int *)(base + 8);
    args[88] = *(int *)(base + 0xC);
    args[89] = *(int *)(base + 0x10);
    args[0] = *(int *)((char *)lbl_802FA54C + 0);
    args[2] = *(int *)((char *)lbl_802FA54C + 8);
    args[3] = *(int *)((char *)lbl_802FA54C + 0xC);
    args[4] = *(int *)((char *)lbl_802FA54C + 0x10);
    args[1] = (int)(&args[5]);

    fn_8024CAAC(arg2);
    temp_r3 = fn_802146BC(&args[0], -0x3E7, -0x3E7, 1);
    if (temp_r3 == -1) {
        return 0;
    }
    if (out != 0) {
        *(int *)out = temp_r3;
    }
    return 1;
}
extern char lbl_80343FC4[];
extern char lbl_80343FF0[];
#pragma scheduling reset
int fn_8024CEF0(void) {
    if (((int (*)(void))fn_8000DBAC)() != 0)
        return 1;
    return ((int (*)(void *, void *, int))fn_80215214)(lbl_80343FF0, lbl_80343FC4, 0);
}
#pragma scheduling invalid_target
int fn_8024CF38(int *arg0) {
    fn_8024CC54(arg0, fn_8024CEF0, 1);
}
#pragma pop
int fn_8024CF48(int *arg0) {
    fn_8024CC54(arg0, 0, 0);
}

void fn_8024CF54(void) {
    lbl_8055F2C8 = 1;
    fn_8024C768();
}

// Keep fn_8024CF38 as a call; inlining it substitutes fn_8024CC54 and changes the target sequence.
#pragma dont_inline on
void fn_8024CF60(void) {
    int sp8;
    if (fn_8024CF38(&sp8) != 0) {
        fn_8000D984(sp8);
        fn_8000DA80();
        fn_8000DC70(sp8);
        ((void (*)(void))fn_8000DA1C)();
        if (fn_802E8D84() != 0)
            fn_802E7128();
    }
}
#pragma dont_inline reset
void fn_8024CFB4(void) {
    int sp8;
    if (((int (*)(int *))fn_8024CF48)(&sp8) != 0) fn_8000D984(sp8);
}

extern double lbl_80563938;
int fn_80232B70(int);
#pragma scheduling invalid_target
void fn_8024CFE8(void *arg0) {
    int denominator = fn_80232B70(*(int *)((char *)arg0 + 0x34));
    int numerator = *(int *)((char *)arg0 + 0x10);
    *(float *)((char *)arg0 + 0x40) = (float)numerator / (float)denominator;
}
#pragma scheduling on
int fn_8024D054(void *arg0, int arg1) {
    int len;
    int lim;
    switch (arg1) {
    case 0x6f:
        len = (int)strlen(*(char **)((char *)arg0 + 0x2c));
        lim = *(int *)((char *)arg0 + 0x30) + 1;
        if (len < lim)
            lim = len;
        *(int *)((char *)arg0 + 0x30) = lim;
        *(char *)((char *)arg0 + 0x48) = 1;
        return 1;
    case 0x20:
        *(char *)((char *)arg0 + 0x48) = 1;
        lim = *(int *)((char *)arg0 + 0x30) - 1;
        *(int *)((char *)arg0 + 0x30) = lim & ~(lim >> 31);
        return 1;
    default:
        return 0;
    }
}

struct S8024D0EC {
    int pad0;
    int unk4;
    int unk8;
    int padC;
    int unk10;
    int pad14;
    char unk18[0x14];
    char *unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    float unk40;
    float unk44;
    unsigned char unk48;
};

#pragma scheduling invalid_target
void fn_8024D0EC(struct S8024D0EC *arg0) {
    float x, y;
    char buf[0x18];
    int count;
    int scale;
    float w;
    float temp2;
    float temp;
    float sx, sy;
    fn_80230C30(&x, &y, arg0->unk4, arg0->unk8);
    if (arg0->unk48 != 0) {
        arg0->unk38 = -1;
    } else {
        scale = arg0->unk10;
        arg0->unk38 = 0xFF000000;
        w = fn_8023293C(arg0->unk34, arg0->unk2C, arg0->unk44);
        temp2 = arg0->unk40 * w;
        fn_80230924((void *)-1, x, y, x + temp2, y - (float)scale, lbl_80563940);
    }
    sy = y;
    sx = x;
    fn_80232BA4(arg0->unk18, arg0->unk34, arg0->unk38, arg0->unk3C, sx, sy, arg0->unk40, lbl_80563930, arg0->unk44);
    count = arg0->unk30;
    sprintf(buf, &lbl_8055C08C, count, count, arg0->unk2C);
    w = fn_8023293C(arg0->unk34, buf, arg0->unk44);
    temp = x + arg0->unk40 * w;
    fn_80230924((void *)-0x2FC1, temp - lbl_80563930, y, lbl_80563930 + temp, y - (float)arg0->unk10, lbl_80563940);
}
#pragma scheduling on
extern float lbl_80563948, lbl_80563944, lbl_8056394C;
extern char lbl_8055C094;
extern char lbl_80343F38[], lbl_80343F20[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8024D248(void *arg0) {
    extern float lbl_80563948, lbl_80563944, lbl_8056394C;
    extern char lbl_8055C094;
    extern char lbl_80343F38[], lbl_80343F20[];
    extern int fn_80232B70(int);
    extern int __cntlzw(unsigned int);

    float f31;
    float f30;
    float f0;
    float f2;
    float f_den;
    int den_int;
    int toggle;
    int count;
    char *dst;
    const char *src;

    f31 = (float)*(int *)((char *)arg0 + 0xC) / lbl_80563948;
    f30 = (float)*(int *)((char *)arg0 + 0x10) * lbl_80563944;

    f31 = (f31 - lbl_8056394C) /
          (*(float *)((char *)arg0 + 0x84) *
           ((float (*)(int, const char *, float, float))fn_8023293C)(
               *(int *)((char *)arg0 + 0x78), &lbl_8055C094,
               *(float *)((char *)arg0 + 0x88), lbl_80563944));

    den_int = fn_80232B70(*(int *)((char *)arg0 + 0x78));
    f2 = f30 - lbl_8056394C;
    f_den = (float)den_int;
    f0 = f2 / f_den;

    f0 = (f0 < f31) ? f0 : f31;

    *(float *)((char *)arg0 + 0x84) = f0;
    src = lbl_80343F38;
    toggle = (unsigned int)__cntlzw(0) >> 5;
    *(char *)((char *)arg0 + 0x6C) = toggle;
    if (toggle) {
        src = lbl_80343F20;
    }
    src = (const char *)fn_80131234(src);

    count = 10;
    dst = (char *)arg0 + 0x6D;
    goto copy_char;
count_more:
    count--;
    if (count > 0)
        goto copy_char;
    dst[-1] = 0;
    goto copy_done;
copy_char:
    if ((signed char)(*dst++ = *src++) != 0)
        goto count_more;
copy_done:
    ;
}
#pragma pop
extern char lbl_80343F00[];
extern void *memset(void *, int, unsigned int);
extern void *memmove(void *, const void *, unsigned int);
extern int __cntlzw(unsigned int);
#pragma scheduling invalid_target
int fn_8024D394(void *arg0, int arg1) {
    char *base = lbl_80343F00;

    switch (arg1) {
    case 0x113: {
        unsigned char *toggle = (unsigned char *)arg0 + 0x6C;
        char *text;
        char *dst;
        int count;
        *toggle = (unsigned char)((unsigned int)__cntlzw((unsigned int)*toggle) >> 5);
        text = base + 0x38;
        if (*toggle != 0)
            text = base + 0x20;
        text = (char *)fn_80131234(text);
        dst = (char *)arg0 + 0x6D;
        count = 0xA;
        goto copy_char;
    check_count:
        --count;
        if (count > 0)
            goto copy_char;
        dst[-1] = 0;
        goto copied_text;
    copy_char:
        {
            char c = *text++;
            *dst++ = c;
            if ((signed char)c == 0)
                goto copied_text;
            goto check_count;
        }
    copied_text:
        goto handled;
    }
    case 0x126:
        *(int *)((char *)arg0 + 0x68) = (*(int *)((char *)arg0 + 0x68) + 3) % 4;
        goto handled;
    case 0x128:
        *(int *)((char *)arg0 + 0x68) = (*(int *)((char *)arg0 + 0x68) + 1) % 4;
        goto handled;
    case 0x125:
        *(int *)((char *)arg0 + 0x64) = (*(int *)((char *)arg0 + 0x64) + 9) % 10;
        goto handled;
    case 0x127:
        *(int *)((char *)arg0 + 0x64) = (*(int *)((char *)arg0 + 0x64) + 1) % 10;
        goto handled;
    case 0xD: {
        int row = *(int *)((char *)arg0 + 0x64);
        int i;
        int length;
        if (row == 9 && 3 == *(int *)((char *)arg0 + 0x68))
            return 0;
        if (row == 8 && *(int *)((char *)arg0 + 0x68) == 3) {
            i = *(int *)((char *)arg0 + 0x48);
            if (i != 0) {
                length = strlen(*(char **)((char *)arg0 + 0x44));
                if (length != 0) {
                    for (; i <= length; ++i)
                        ((char **)((char *)arg0 + 0x44))[0][i - 1] = ((char **)((char *)arg0 + 0x44))[0][i];
                    *(int *)((char *)arg0 + 0x48) = *(int *)((char *)arg0 + 0x48) - 1;
                    ((char **)((char *)arg0 + 0x44))[0][length - 1] = 0;
                    *(unsigned char *)((char *)arg0 + 0x60) = 1;
                }
            }
        } else {
            int column = *(int *)((char *)arg0 + 0x68);
            char *table = base + 0x248;
            char value;
            if (*(unsigned char *)((char *)arg0 + 0x6C) != 0)
                table = base + 0x220;
            value = (signed char)table[column * 10 + row];
            if (*(unsigned char *)((char *)arg0 + 0x60) == 0) {
                memset(*(char **)((char *)arg0 + 0x44), 0, 0x11);
                *(int *)((char *)arg0 + 0x48) = 0;
            }
            length = strlen(*(char **)((char *)arg0 + 0x44));
            if (length != 0x10) {
                while (length > *(int *)((char *)arg0 + 0x48)) {
                    ((char **)((char *)arg0 + 0x44))[0][length] = ((char **)((char *)arg0 + 0x44))[0][length - 1];
                    --length;
                }
                ((char **)((char *)arg0 + 0x44))[0][*(int *)((char *)arg0 + 0x48)] = value;
                *(unsigned char *)((char *)arg0 + 0x60) = 1;
                *(int *)((char *)arg0 + 0x48) = *(int *)((char *)arg0 + 0x48) + 1;
            }
        }
        goto handled;
    }
    default:
        return 0;
    }
handled:
    return 1;
}
#pragma scheduling on
extern void fn_80234AFC(void *, const char *, float, float, ...);
extern float lbl_80563940, lbl_80563944, lbl_80563948, lbl_80563950, lbl_80563954;
extern double lbl_80563938;
extern signed char lbl_80344120[], lbl_80344148[];
extern char lbl_8055C098[1], lbl_8055C0A0[1], lbl_8055C0A8[1];
void fn_8024D810(void *arg0) {
    float x, y;
    float dx, dy, cx, cy, e;
    int row, col, base;
    fn_80230C30(&x, &y, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
    dx = (float)*(int *)((char *)arg0 + 0xC) / lbl_80563948;
    dy = (float)*(int *)((char *)arg0 + 0x10) * lbl_80563944;
    cx = x + dx * (float)(*(int *)((char *)arg0 + 0x64) + 1);
    cy = y - dy * (float)(*(int *)((char *)arg0 + 0x68) + 1);
    e = lbl_80563950;
    fn_80230924((void *)0xFFAF7F00, cx, cy, cx + dx, cy - e, lbl_80563940);
    fn_80230924((void *)0xFFAF7F00, cx, cy, cx + dx, e + (cy - dy), lbl_80563940);
    fn_80230924((void *)0xFFAF7F00, cx, cy, cx + e, cy - dy, lbl_80563940);
    fn_80230924((void *)0xFFAF7F00, cx + dx, cy, cx + dx - e, cy - dy, lbl_80563940);
    x += dx * lbl_80563954;
    y -= dy * lbl_80563954;
    for (row = 0, base = 0; row < 4; row++, base += 10, y -= dy) {
        for (col = 0; col < 10; col++, x += dx) {
            if (row == 3 && col == 9)
                fn_80234AFC((char *)arg0 + 0x78, lbl_8055C098, x, y, 1);
            else if (row == 3 && col == 8)
                fn_80234AFC((char *)arg0 + 0x78, lbl_8055C0A0, x, y, 1);
            else {
                signed char *letters = *(unsigned char *)((char *)arg0 + 0x6C) ? lbl_80344120 : lbl_80344148;
                fn_80234AFC((char *)arg0 + 0x78, lbl_8055C0A8, x, y, 1, letters[base + col]);
            }
        }
    }
}

