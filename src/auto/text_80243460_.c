// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <string.h>
extern void fn_80241354(void*);
extern s32 lbl_803428B0[][16][3];
/* One row of the menu table: one of 16 selectable items.
 * field 0 is the item's label (a char *, 0 when unused), field 1 its width
 * in grid cells and field 2 its kind (1 label, 2/5 text field, 3 back, 4 action). */
typedef struct MenuTableEntry {
    /* 0x00 */ char *label;
    /* 0x04 */ s32 width;
    /* 0x08 */ s32 kind;
} MenuTableEntry;
/* The whole menu table: 5 groups (pages) of 16 entries each. */
typedef MenuTableEntry MenuTable[5][16];
/* The table under its entry type. */
#define MENU_TABLE (*(MenuTable *)lbl_803428B0)

/* The menu list widget the functions in this file drive. */
typedef struct MenuListObject {
    /* 0x00 */ void *vtable;
    /* 0x04 */ u8 pad_04[0x10];
    /* 0x14 */ s32 field_14;
    /* 0x18 */ char *text;     /* string the player is typing in */
    /* 0x1C */ s32 textLimit;  /* its buffer size, at most 11 */
    /* 0x20 */ s32 font;
    /* 0x24 */ char *field_24;
    /* 0x28 */ u8 edited;
    /* 0x29 */ u8 toggle;      /* flips between the two labels of a 2-char entry */
    /* 0x2C */ s32 groupIndex; /* menu table group (page) the cursor is on */
    /* 0x30 */ s32 entryIndex; /* entry of that group the cursor is on */
    /* 0x34 */ s32 field_34;
} MenuListObject;
extern char lbl_80342CEC[];
s32 fn_80243478(s32);
extern s32 fn_80244558(void *);
extern void fn_80230C30(float *, float *, int, int);
extern void fn_80230F78(signed char *, float *, long, long);
extern void fn_80230924(void *, float, float, float, float, float);
extern void fn_80232BA4(char *, s32, s32, s32, float, float, float, float, float);
extern double fn_8023659C(void);
extern double fn_8002EFB4(double, double);
extern float lbl_80563798, lbl_8056379C, lbl_805637A0, lbl_805637A4;
extern float lbl_805637A8, lbl_805637AC, lbl_805637B0, lbl_805637B4, lbl_805637B8;
extern float lbl_805637BC, lbl_805637C0, lbl_805637C4, lbl_805637D0;
extern float lbl_805637D4, lbl_805637D8, lbl_805637DC, lbl_805637E0;
extern float lbl_805637E4;
extern double lbl_805637C8, lbl_805637E8;

void fn_80243460(void* arg0) {
    fn_80241354((u8*)arg0 - 0x10);
}

extern void fn_80241820(void*);
void fn_80243468(void* arg0) {
    fn_80241820((u8*)arg0 - 0x10);
}

extern void fn_802408B0(void*);
void fn_80243470(void* arg0) {
    fn_802408B0((u8*)arg0 - 0x10);
}

#pragma dont_inline on
s32 fn_80243478(s32 arg0) {
    s32 (*entry)[3] = lbl_803428B0[arg0];
    s32 count = 0;
    s32 i = 0;
    while (i < 16) {
        if ((*entry)[0] == 0) break;
        count++;
        entry++;
        i++;
    }
    return count;
}

s32 fn_80243528(s32 arg0, s32 arg1) {
    s32 n = arg0;
    s32 *base = (s32 *)lbl_803428B0 + arg1 * 48;
    s32 sum = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        sum += base[i * 3 + 1];
    }
    return sum;
}

#pragma unroll on
s32 fn_8024360C(s32 value, s32 tableIndex) {
    s32 start = 0;
    s32 best = 0;
    s32 index = 0;
    s32 length;
    s32 end;
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            length = lbl_803428B0[tableIndex][i * 4 + j][1];
            end = start + length;
            if (length > 0)
                best = index;
            if (value >= start && value < end)
                return index;
            start = end;
            index++;
        }
    }
    return best;
}
#pragma unroll reset

s32 fn_80243710(s32 arg0, s32 arg1) {
    s32 result = 0;
    if (arg0 >= 0 && arg0 <= fn_80243478(arg1)) result = 1;
    return result;
}

/* Menu cursor hold: the group/entry the cursor rested on when it last moved,
 * -1/-1 when there is nothing to hold on to (kept by MenuList_MoveCursor). */
__declspec(section ".sdata") extern s32 lbl_8055BE0C; /* s_cursorHoldGroup */
__declspec(section ".sdata") extern s32 lbl_8055BE10; /* s_cursorHoldEntry */
#define s_cursorHoldGroup lbl_8055BE0C
#define s_cursorHoldEntry lbl_8055BE10
extern s32 fn_80230E90(s32);
extern s32 fn_80243528(s32, s32);
extern s32 fn_8024360C(s32, s32);
extern s32 fn_80243710(s32, s32);
#pragma push
#pragma use_lmw_stmw off
s32 fn_80243764(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 old0 = *(s32 *)arg0;
    s32 old1 = *(volatile s32 *)arg1;
    s32 next = old1 + arg3;
    s32 value, count, current;
    s32 tmpc;
    if ((*(volatile s32 *)arg1 = next) < 0) *(volatile s32 *)arg1 = 4;
    else if (next > 4) *(volatile s32 *)arg1 = 0;
    if (*(volatile s32 *)arg1 != old1) {
        value = fn_8024360C(fn_80243528(*(s32 *)arg0, old1), *(volatile s32 *)arg1);
        count = fn_80243478(*(volatile s32 *)arg1);
        tmpc = fn_80243478(old1);
        if (tmpc != count) {
            if (fn_80243710(lbl_8055BE0C, *(volatile s32 *)arg1) && *(s32 *)arg0 == lbl_8055BE10) {
                value = lbl_8055BE0C;
                lbl_8055BE0C = lbl_8055BE10;
                lbl_8055BE10 = value;
            } else {
                s32 tmp0 = *(s32 *)arg0;
                lbl_8055BE10 = value;
                lbl_8055BE0C = tmp0;
            }
        } else {
            lbl_8055BE10 = -1;
            lbl_8055BE0C = -1;
        }
        *(s32 *)arg0 = value;
    }
    current = *(s32 *)arg0 + arg2;
    *(s32 *)arg0 = current;
    if (current < 0) *(s32 *)arg0 = fn_80243478(*(volatile s32 *)arg1) - 1;
    else if (*(s32 *)arg0 > fn_80243478(*(volatile s32 *)arg1) - 1) *(s32 *)arg0 = 0;
    if (*(s32 *)arg0 != lbl_8055BE10) {
        lbl_8055BE0C = -1;
        lbl_8055BE10 = -1;
    }
    if (old0 != *(s32 *)arg0 || old1 != *(volatile s32 *)arg1) {
        fn_80230E90(0);
        return 1;
    }
    return 0;
}
#pragma pop
void fn_802438EC(char* arg0) {
    s32 len = strlen(arg0);
    if (len > 0) {
        u8* end = (u8*)((u32)len + (u32)arg0);
        if ((s32)end[-1] == '_') end[-1] = 0;
    }
}

__declspec(section ".sdata") extern char lbl_8055BE14[];
void fn_80243938(char *arg0, char *arg1) {
    register int len = strlen(arg0);
    register char *dst = arg0;
    register char *src;

    if (len != 0) {
        if (arg0[len - 1] == '_') goto done;
        if (len + 1 >= (s32)arg1) goto done;
    }

    src = lbl_8055BE14;
    goto scan_test;

scan_body:
    arg1 = (char *)(arg1 - 1);
    dst += 1;

scan_test:
    if (*dst != 0) goto scan_body;
    if ((s32)arg1 <= 0) goto done;
    goto copy_body;

copy_check:
    arg1 = (char *)(arg1 - 1);
    if ((s32)arg1 > 0) goto copy_body;
    dst[-1] = 0;
    goto done;

copy_body:
    while ((*dst++ = *src++) != 0) goto copy_check;

done:
    return;
}

#pragma scheduling invalid_target
void fn_802439E8(void *arg0, s32 arg1, s32 arg2) {
    s32 value = 0xB;
    volatile s32 *field = (volatile s32 *)((u8 *)arg0 + 0x1C);
    *(s32 *)((u8 *)arg0 + 0x18) = arg1;
    *(char **)arg0 = lbl_80342CEC;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *field = arg2;
    if (arg2 <= 0xB)
        value = arg2;
    *field = value;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s32 *)((u8 *)arg0 + 0x2C) = 0;
    *((u8 *)arg0 + 0x29) = 1;
    *((u8 *)arg0 + 0x28) = 0;
}
#pragma scheduling on

extern s32 fn_80232578(s32);
extern s32 fn_802C5130(s32);
extern void fn_802E30C8(const char *, ...);
extern s32 fn_80131234(const char *);
#pragma push
#pragma use_lmw_stmw off
#pragma optimize_for_size on
void fn_80243A38(void *arg0) {
    char *globalBase = (char *)lbl_803428B0;
    s32 *base;
    s32 *entry;
    s32 group;
    s32 i;

    *(s32 *)((u8 *)arg0 + 0x20) = fn_80232578((s32)(globalBase + 0x3C0));
    *(s32 *)((u8 *)arg0 + 0x24) = fn_802C5130((s32)(globalBase + 0x3CC));
    if (*(s32 *)((u8 *)arg0 + 0x24) == 0)
        fn_802E30C8(globalBase + 0x3D8);
    fn_80243938(*(char **)((u8 *)arg0 + 0x18), *(char **)((u8 *)arg0 + 0x1C));

    base = (s32 *)((u8 *)globalBase + 0);
    group = 0;
    do {
        entry = base;
        i = 0;
        while (i < fn_80243478(group)) {
            switch (entry[2]) {
            case 3:
                if (entry[0] == 0 || strlen((char *)entry[0]) < 1)
                    entry[0] = fn_80131234(globalBase + 0x3FC);
                break;
            case 2:
                if (entry[0] == 0 || strlen((char *)entry[0]) < 1)
                    entry[0] = fn_80131234(globalBase + 0x410);
                break;
            case 5:
                if (entry[0] == 0 || strlen((char *)entry[0]) < 1)
                    entry[0] = fn_80131234(globalBase + 0x420);
                break;
            default:
                break;
            }
            entry += 3;
            i++;
        }
        group++;
        base += 48;
    } while (group < 5);
}
#pragma optimize_for_size reset
#pragma pop
extern s32 fn_802328D4(char *);
extern s32 fn_802C519C(char *);
void fn_80243B84(void *arg0) {
    char **obj = (char **)arg0;
    fn_802438EC(obj[6]);
    fn_802C519C(obj[9]);
    obj[9] = 0;
    fn_802328D4(obj[8]);
    obj[8] = 0;
}

extern s32 fn_80128668(void);
extern void fn_80221E7C(void);
extern s32 fn_802328D4(char*);
extern s32 fn_802C519C(char*);
extern char lbl_80342CEC[];
s32 fn_80243BD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80243C18(void) {
    fn_80221E7C();
}

#pragma push
#pragma processor 750
void fn_80243C1C(void *arg0) {
    char buffer[32];
    u8 sp8;
    s16 spC;
    s32 sp10;
    float sp14;
    float sp18;
    float sp1C;
    float f23, f24, f25;
    s32 var_r21, var_r20, var_r19, var_r25, var_r18;
    s32 *entry;
    char *str;
    s32 type;
    s32 color;
    char *dst;
    char *src;
    s32 left;
    s32 limit;
    s32 len2;
    s32 maxIdx;
    float fmodRes;
    s32 eq;
    s32 idx;
    s32 var0;
    s32 col;
    char *buf;
    float cA4 = lbl_805637A4, cA8 = lbl_805637A8, c98 = lbl_80563798, cAC = lbl_805637AC;
    float cB0 = lbl_805637B0, cB8 = lbl_805637B8, cB4 = lbl_805637B4, cBC = lbl_805637BC;
    double cE8 = lbl_805637E8;
    fn_80230C30(&sp1C, &sp18, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    var_r21 = 0;
    do {
        var_r20 = 0;
        do {
            entry = lbl_803428B0[var_r21][0] + var_r20 * 48;
            f24 = sp1C;
            f25 = sp18 - c98 * (float)var_r20;
            var_r19 = 0;
            do {
                var_r25 = 0;
                if (var_r20 == *(s32 *)((u8 *)arg0 + 0x2C) && var_r19 == *(s32 *)((u8 *)arg0 + 0x30))
                    var_r25 = 1;
                str = (char *)entry[0];
                if (str != (char *)0) {
                    type = entry[2];
                    if (type == 1)
                        f23 = lbl_8056379C;
                    else
                        f23 = lbl_805637A0;
                    var_r18 = 0xE0FFFFFF;
                    if (var_r25 != 0)
                        var_r18 = 0xE00000FF;
                    if (type == 1 && strlen(str) == 2) {
                        buffer[0] = str[*(u8 *)((u8 *)arg0 + 0x29)];
                        buffer[1] = 0;
                    } else {
                        dst = buffer;
                        src = str;
                        left = 32;
                        goto copy_body;
                    copy_check:
                        if (--left > 0)
                            goto copy_body;
                        dst[-1] = 0;
                        goto copy_done;
                    copy_body:
                        while ((*dst++ = *src++) != 0)
                            goto copy_check;
                    copy_done:;
                    }
                    sp8 = 0;
                    sp14 = cA4;
                    if (var_r25 != 0) {
                        sp10 = 0;
                        fn_80230F78((signed char *)&sp8, &sp14, (long)&sp10, 0);
                        var_r18 = sp10;
                    }
                    if (var_r21 == 0 || (var_r25 != 0 && sp8 != 0)) {
                        if (var_r25 != 0) {
                            color = 0xFFC34C05;
                        } else if (type == 1) {
                            color = 0x50000000;
                        } else if ((type == 5 || type == 2) && fn_80244558(arg0) == 0) {
                            color = 0x78000000;
                            var_r18 = 0x28000000;
                        } else {
                            color = 0x50000078;
                        }
                        if (var_r21 == 1) {
                            color = (color & 0x00FFFFFF) | ((s32)sp8 << 24);
                            fn_80230924((void *)(long)color, (cAC + f24) - (cA8 * sp14), (c98 * sp14) + (f25 - cAC), (cA8 * sp14) + ((f24 + (cA8 * (float)entry[1])) - cB0), (cB0 + (f25 - c98)) - (c98 * sp14), cA4);
                        } else {
                            fn_80230924((void *)(long)color, (cAC + f24) - cA4, cA4 + (f25 - cAC), cA4 + ((f24 + (cA8 * (float)entry[1])) - cB0), (cB0 + (f25 - c98)) - cA4, cA4);
                        }
                    }
                    if (var_r25 == var_r21) {
                        fn_80232BA4(buffer, *(s32 *)((u8 *)arg0 + 0x20), var_r18, 0x14, cB4 + (f24 + (cB8 * (cA8 * (float)entry[1]))), f25 - cBC, f23, cA4, cAC);
                    }
                }
                var_r19++;
                f24 += cA8 * (float)entry[1];
                entry += 3;
                if (var_r19 >= 16)
                    break;
            } while (1);
            var_r20++;
        } while (var_r20 < 5);
        var_r21++;
    } while (var_r21 < 2);
    f23 = lbl_805637C0 + sp1C;
    f24 = lbl_805637C4 + sp18;
    limit = *(s32 *)((u8 *)arg0 + 0x1C) - 1;
    len2 = fn_80244558(arg0);
    maxIdx = limit - 1;
    if (len2 < maxIdx)
        maxIdx = len2;
    fmodRes = (float)fn_8002EFB4(fn_8023659C(), lbl_805637C8);
    eq = (fmodRes == lbl_805637D0);
    idx = 0;
    while (idx < limit) {
        var0 = 0;
        if (eq != 0 && idx == maxIdx)
            var0 = 1;
        col = -1;
        if (var0 != 0)
            col = 0xFF000000;
        spC = ((char *)*(s32 *)((u8 *)arg0 + 0x18))[idx];
        if (var0 != 0) {
            fn_80230924((void *)0x80FFFF00L, lbl_805637D8 + f24, f24 - lbl_805637D8, lbl_805637DC + ((f23 + (lbl_805637D4 * (float)(idx + 1))) - lbl_805637E0), f24 - lbl_805637D8, cA4);
        }
        buf = lbl_8055BE14;
        if (idx < fn_80244558(arg0))
            buf = (char *)&spC;
        fn_80232BA4(buf, *(s32 *)((u8 *)arg0 + 0x20), col, 0x14, f23 + (lbl_805637D4 * (lbl_805637B8 + (float)idx)), f24, lbl_805637E4, cA4, cAC);
        idx++;
    }
}
#pragma pop
extern float fn_8023293C(s32, char *, float);
extern char lbl_80342CE0[];
__declspec(section ".sdata") extern char lbl_8055BE18[];
extern float lbl_805637AC;
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802440CC(void *arg0) {
    struct V {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22();
        virtual void action(); virtual void other();
    };
    float spacing = lbl_805637AC;
    s32 *entry;
    s32 buffer[8];
    char *src;
    s32 left, i, j;
    char *dst;
    char ch;
    fn_8023293C(*(s32 *)((u8 *)arg0+0x20), lbl_80342CE0, spacing);
    entry = lbl_803428B0[*(s32 *)((u8 *)arg0+0x2c)][*(s32 *)((u8 *)arg0+0x30)];
    switch (entry[2]) {
    case 4:
        ((V *)arg0)->action();
        break;
    case 1:
    case 2:
        if (fn_80244558(arg0) >= *(s32 *)((u8 *)arg0+0x1c)-1) ((V *)arg0)->action();
        if (fn_80244558(arg0)+1 < *(s32 *)((u8 *)arg0+0x1c)) {
            fn_802438EC(*(char **)((u8 *)arg0+0x18));
            buffer[0]=0; buffer[1]=0; buffer[2]=0; buffer[3]=0;
            buffer[4]=0; buffer[5]=0; buffer[6]=0; buffer[7]=0;
            if (entry[2] == 2) {
                if (**(char **)((u8 *)arg0+0x18)) {
                    src=lbl_8055BE18;
                    dst=(char *)buffer;
                    left=32;
                    goto copy1_body;
copy1_check:
                    if (--left > 0) goto copy1_body;
                    dst[-1]=0;
                    goto copy1_done;
copy1_body:
                    while ((*dst++ = *src++) != 0) goto copy1_check;
copy1_done:;
                } else ((char *)buffer)[0]=0;
            } else {
                src=(char *)entry[0];
                if (strlen(src)==2) {
                    ((char *)buffer)[0]=src[*((u8 *)arg0+0x29)];
                    ((char *)buffer)[1]=0;
                } else {
                    s32 left2; char *dst2;
                    dst2=(char *)buffer; left2=32;
                    goto copy2_body;
copy2_check:
                    if (--left2 > 0) goto copy2_body;
                    dst2[-1]=0;
                    goto copy2_done;
copy2_body:
                    while ((*dst2++ = *src++) != 0) goto copy2_check;
copy2_done:;
                }
            }
            s32 left3=*(s32 *)((u8 *)arg0+0x1c);
            char *dst3=*(char **)((u8 *)arg0+0x18);
            while (*dst3) { left3--; dst3++; }
            if (left3>0) {
                src=(char *)buffer;
                goto copy3_body;
copy3_check:
                if (--left3 > 0) goto copy3_body;
                dst3[-1]=0;
                goto copy3_done;
copy3_body:
                while ((*dst3++ = *src++) != 0) goto copy3_check;
copy3_done:;
            }
            fn_80243938(*(char **)((u8 *)arg0+0x18), *(char **)((u8 *)arg0+0x1c));
            if (*(s32 *)((u8 *)arg0+0x1c)==fn_80244558(arg0)+1) {
                for (i=0;i<5;i++) {
                    for (j=0;j<16;j++) {
                        if (lbl_803428B0[i][j][2]==5) {
                            *(s32 *)((u8 *)arg0+0x2c)=i;
                            *(s32 *)((u8 *)arg0+0x30)=j;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case 3:
        ((V *)arg0)->other();
        break;
    case 5:
        if (strlen(*(char **)((u8 *)arg0+0x18))>1) {
            *((u8 *)arg0+0x28)=1;
            fn_802438EC(*(char **)((u8 *)arg0+0x18));
        }
        break;
    }
}
#pragma pop

extern void fn_80243938(char *, char *);
void fn_802443C0(void *arg0) {
    char *str;
    fn_802438EC(*(char **)((char *)arg0 + 0x18));
    str = *(char **)((char *)arg0 + 0x18);
    if (strlen(str) != 0) {
        int len = strlen(str);
        char *end = (char *)(len + (int)str);
        *(end - 1) = 0;
    }
    fn_80243938(*(char **)((char *)arg0 + 0x18), *(char **)((char *)arg0 + 0x1C));
}

void fn_8024442C(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x29) = !*(u8 *)((u8 *)arg0 + 0x29);
}

extern s32 fn_80244558(void *);
#pragma push
#pragma cplusplus on
struct Dummy_80244440 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};
#pragma cplusplus on
extern "C" s32 fn_80244440(void *object, s32 inputCode) {
    /* Dispatch input codes to movement/action/cancel handlers. */
    switch (inputCode) {
    case 0x125: fn_80243764((u8 *)object + 0x30, (u8 *)object + 0x2C, -1, 0); goto handled;
    case 0x127: fn_80243764((u8 *)object + 0x30, (u8 *)object + 0x2C, 1, 0); goto handled;
    case 0x126: fn_80243764((u8 *)object + 0x30, (u8 *)object + 0x2C, 0, -1); goto handled;
    case 0x128: fn_80243764((u8 *)object + 0x30, (u8 *)object + 0x2C, 0, 1); goto handled;
    case 0xD:
        ((Dummy_80244440 *)object)->f22();
        goto handled;
    case 0x1B:
        if (fn_80244558(object) > 0) {
            ((Dummy_80244440 *)object)->f23();
            goto handled;
        }
        return 0;
    default: return 0;
    }
handled:
    return 1;
}
#pragma cplusplus off
u8 fn_80244550(void *arg0) {
    return *((u8 *)arg0 + 0x28);
}

s32 fn_80244558(void *arg0) {
    char *str = *(char **)((u8 *)arg0 + 0x18);
    s32 len = strlen(str);
    if (len > 0 && *(s8 *)((u32)len + (u32)str - 1) == '_') len--;
    return len;
}

