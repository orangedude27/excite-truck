#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012850C(int, int);
extern char lbl_80330B7C[];
extern char lbl_80330B8C[];
extern char lbl_8055A248[];
extern char lbl_8055A268[];
extern void fn_80130978(void *, s32, f32);
extern void fn_8014784C(void *, const char *, const char *, s32);
extern void fn_801475D0(void *, const char *, const char *, void *);
extern void fn_8016A438(void);
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern f32 lbl_805619A0;
extern char lbl_80330AEC[];
extern char lbl_803306D0[];
extern void fn_801345D8(void *, s32, void *, s32);
extern void fn_802E317C(const char *, ...);
extern void fn_8016A15C(char *);
void *fn_80128668(void *);
void fn_802C6CF8(int);
extern s32 fn_8002F6AC(void *);
extern void *fn_80128668(void *);
extern s32 fn_8002F37C(void *, void *, s32, s32);
extern void fn_8016B4FC(void *);
extern s32 fn_802BAA68(s32, void *);
extern void fn_8016CDE0(void *);
extern void *fn_8016C168(void *, s32);
extern void *fn_8016C29C(void *, int);
extern int fn_8016C25C(int, int);
#pragma cplusplus on
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual int d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual f32 d14(); virtual void d15();
    virtual void d16();
    virtual void v4C();
};
#pragma cplusplus reset
void *fn_8016B79C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)((u8 *)arg0 + 0x10);
        if (value != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(value, fn_8016B4FC);
            *(s32 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0x14) = 0;
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_8016B550(void *);
void *fn_8016B834(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)((u8 *)arg0 + 0x10);
        if (value != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(value, fn_8016B550);
            *(s32 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0x14) = 0;
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_8016AC24(void *);
void *fn_8016B8CC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)((u8 *)arg0 + 0x10);
        if (value != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(value, fn_8016AC24);
            *(s32 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0x14) = 0;
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8016C168(void *arg0, s32 arg1) {
    void *temp_r30;
    void *temp_r30_2;
    if (arg0 != 0) {
        if (*((u8 *)arg0 + 8) != 0) {
            temp_r30 = *(void **)arg0;
            *((u8 *)arg0 + 8) = 0;
            if (temp_r30 != 0) {
                ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)temp_r30 + 0xC), fn_8016C29C);
                if (temp_r30 != 0) {
                    *(s32 *)temp_r30 = 0;
                    *((s32 *)temp_r30 + 1) = 0;
                    *((s32 *)temp_r30 + 2) = 0;
                }
                fn_80128668(temp_r30);
            }
            temp_r30_2 = *((void **)arg0 + 1);
            *(void **)arg0 = 0;
            if (temp_r30_2 != 0) {
                ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)temp_r30_2 + 0xC), fn_8016C25C);
                if (temp_r30_2 != 0) {
                    *(s32 *)temp_r30_2 = 0;
                    *((s32 *)temp_r30_2 + 1) = 0;
                    *((s32 *)temp_r30_2 + 2) = 0;
                }
                fn_80128668(temp_r30_2);
            }
            *((void **)arg0 + 1) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_8016C25C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) { fn_80128668((void *)arg0); }
    return arg0;
}

void *fn_8016C29C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (*((unsigned char *)arg0 + 16) != 0) {
            int temp = *(int *)arg0;
            *((unsigned char *)arg0 + 16) = 0;
            if (temp != -1) {
                fn_802C6CF8(temp);
                *(int *)arg0 = -1;
            }
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8016C55C(void *arg0, void *arg1) {
    int index;
    void *dst;
    index = ((int *)arg0)[1];
    ((int *)arg0)[1] = index + 1;
    dst = (void *)((char *)*((void **)arg0) + index * 16);
    *(unsigned char *)dst = *(unsigned char *)arg1;
    *(int *)((char *)dst + 4) = *(int *)((char *)arg1 + 4);
    *(float *)((char *)dst + 8) = *(float *)((char *)arg1 + 8);
    *(float *)((char *)dst + 12) = *(float *)((char *)arg1 + 12);
}

void *fn_8016C598(void *arg0, int arg1, int arg2) {
    int temp = fn_8012850C(arg1 * 16, arg2);
    ((int *)arg0)[0] = temp;
    ((int *)arg0)[3] = temp;
    ((int *)arg0)[2] = arg1;
    ((int *)arg0)[1] = 0;
    return arg0;
}

int fn_8016C760(void *arg0) { return ((int *)arg0)[1]; }

extern f32 lbl_805619A0;
void fn_8016CD10(void *arg0) {
    *((f32 *)((u8 *)arg0 + 0x34)) = lbl_805619A0;
    *((u8 *)arg0 + 0x30) = 0;
    *((u8 *)arg0 + 0x31) = 0;
}

void fn_8016CD28(void *arg0) {
    int zero = 0;
    int minusOne = -1;
    *((u8 *)arg0 + 0x10) = zero;
    ((int *)arg0)[0] = minusOne;
    ((int *)arg0)[1] = zero;
    ((int *)arg0)[2] = zero;
    ((int *)arg0)[3] = 3;
}

s32 fn_8016CD4C(void *arg0) { s32 *base=*(s32 **)arg0; s32 index=((s32 *)arg0)[1]; ((s32 *)arg0)[1]=index+1; return (s32)base+index*0x14; }

void *fn_8016CD68(void *arg0,s32 arg1,s32 arg2) {
 s32 temp; s32 size=arg1*0x14;
 fn_8012850C(size+0x10,arg2);
 temp=fn_8002F37C(fn_8016CDE0,fn_8016C168,0x14,arg1);
 ((s32 *)arg0)[0]=temp; ((s32 *)arg0)[3]=temp; ((s32 *)arg0)[2]=arg1; ((s32 *)arg0)[1]=0; return arg0;
}

void fn_8016CDE0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0) = 0;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

s32 fn_8016CDF8(void *arg0, void *obj) {
    char sp8[0x1E];
    s32 count = 0;
    fn_801345D8(sp8, 0x1E, lbl_8033072C, 0);
    while (((s32 (*)(void *, char *))(*(u32 **)obj)[3])(obj, sp8) != 0) {
        count++;
        fn_801345D8(sp8, 0x1E, lbl_803308A0, count);
    }
    return count;
}

void fn_8016CE94(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 4) = arg1;
}

extern f32 lbl_80561980;
extern char lbl_8033072C[];
extern char lbl_803308A0[];
void *fn_8016CEC0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    fn_8000DA10();
    *(f32 *)((u8 *)arg0 + 0xC) = lbl_80561980;
    return arg0;
}

void fn_8016CEFC(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

extern char lbl_80330A90[];
extern f32 lbl_80561984;
extern void fn_802C2914(void);
extern void *fn_80131808(void *);
extern void *fn_8023512C(void *);
extern void *fn_802076A0(void *, s32, s32, s32);
extern s32 fn_80204CF0(void);
void *fn_8016D024(void *arg0) {
    void *temp_r6;
    void *temp_r3;

    fn_802C2914();
    *(void **)((u8 *)arg0 + 4) = lbl_80330A90;
    *(void **)((u8 *)arg0 + 0x14) = fn_80131808(lbl_803306D0 + 0x1E0);
    *(void **)((u8 *)arg0 + 0x20) = fn_8023512C(lbl_803306D0 + 0x1F8);
    *(void **)((u8 *)arg0 + 0x4C) = fn_802076A0(lbl_803306D0 + 0x204, 1, 0, 0);
    *(void **)((u8 *)arg0 + 0x50) = fn_802076A0(lbl_803306D0 + 0x210, 1, 0, 0);
    *(void **)((u8 *)arg0 + 0x58) = fn_802076A0(lbl_803306D0 + 0x220, 1, 0, 0);
    *(void **)((u8 *)arg0 + 0x54) = fn_802076A0(lbl_803306D0 + 0x22C, 1, 0, 0);
    *(void **)((u8 *)arg0 + 0x5C) = fn_802076A0(lbl_803306D0 + 0x23C, 1, 0, 0);
    *(void **)((u8 *)arg0 + 0x60) = fn_802076A0(lbl_803306D0 + 0x24C, 1, 0, 0);
    temp_r6 = *(void **)((u8 *)arg0 + 0x4C);
    *(void **)((u8 *)arg0 + 0x64) = fn_802076A0(lbl_803306D0 + 0x258, 1, 0, 0);
    *(s32 *)((u8 *)arg0 + 0x24) = -1;
    *(u8 *)((u8 *)arg0 + 0x48) = 0;
    *(u8 *)((u8 *)arg0 + 0x49) = 0;
    *(u8 *)((u8 *)arg0 + 0x4A) = 1;
    *(f32 *)((u8 *)arg0 + 0x28) = lbl_80561980;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
    *(s32 *)((u8 *)arg0 + 0x3C) = 0;
    if (temp_r6 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r6 + 8)) {
        *(u8 *)((u8 *)temp_r6 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r6 + 8) = lbl_80561984;
    }
    temp_r3 = *(void **)((u8 *)arg0 + 0x50);
    if (temp_r3 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r3 + 8)) {
        *(u8 *)((u8 *)temp_r3 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r3 + 8) = lbl_80561984;
    }
    temp_r3 = *(void **)((u8 *)arg0 + 0x58);
    if (temp_r3 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r3 + 8)) {
        *(u8 *)((u8 *)temp_r3 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r3 + 8) = lbl_80561984;
    }
    temp_r3 = *(void **)((u8 *)arg0 + 0x54);
    if (temp_r3 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r3 + 8)) {
        *(u8 *)((u8 *)temp_r3 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r3 + 8) = lbl_80561984;
    }
    temp_r3 = *(void **)((u8 *)arg0 + 0x5C);
    if (temp_r3 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r3 + 8)) {
        *(u8 *)((u8 *)temp_r3 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r3 + 8) = lbl_80561984;
    }
    temp_r3 = *(void **)((u8 *)arg0 + 0x60);
    if (temp_r3 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r3 + 8)) {
        *(u8 *)((u8 *)temp_r3 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r3 + 8) = lbl_80561984;
    }
    temp_r3 = *(void **)((u8 *)arg0 + 0x64);
    if (temp_r3 != 0 && lbl_80561984 != *(f32 *)((u8 *)temp_r3 + 8)) {
        *(u8 *)((u8 *)temp_r3 + 0x4D) = 1;
        *(f32 *)((u8 *)temp_r3 + 8) = lbl_80561984;
    }
    *(s32 *)((u8 *)arg0 + 0x40) = fn_80204CF0();
    return arg0;
}

void fn_8016D278(void *arg0) { *(u32 *)arg0=(u32)arg0+0xC; *(u32 *)((u8 *)arg0+8)=8; *(u32 *)((u8 *)arg0+4)=0; }

s32 fn_8016D544(void *arg0) {
    s32 *list = *(s32 **)((u8 *)arg0 + 0x18);
    s32 count = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)list + 4)) {
        s32 *items = *(s32 **)list;
        s32 n = *(s32 *)((u8 *)items + i * 0x14 + 4);
        s32 j = 0;
        s32 found = 0;
        while (j < n) {
            if (*(s32 *)((u8 *)items + i * 0x14 + j * 0x44 + 0xC) == 0) {
                found = 1;
            }
            j++;
        }
        count += found;
        i++;
    }
    return count;
}

s32 fn_802BAA68(s32, void *);
void fn_8016D5B8(void *arg0) {
    s32 *list = *(s32 **)((u8 *)arg0 + 0x18);
    s32 i = 0;
    while (i < *(s32 *)((u8 *)list + 4)) {
        s32 *items = *(s32 **)list;
        s32 n = *(s32 *)((u8 *)items + i * 0x14 + 4);
        s32 j = 0;
        while (j < n) {
            s32 *item = (s32 *)((u8 *)items + i * 0x14 + j * 0x44);
            if (*(s32 *)((u8 *)item + 0xC) == 0) {
                *(s32 *)((u8 *)item + 4) = fn_802BAA68(*(s32 *)((u8 *)item + 8), (void *)((u8 *)item + 0x14));
            }
            j++;
        }
        i++;
    }
}

s32 fn_8016DD98(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    switch (value) {
        case 0: return 5;
        case 1: return 0xA;
        case 2: return 0xF;
        default: {
            void (*report)(const char *, ...) = fn_802E317C;
            report(lbl_80330AEC);
            return 0;
        }
    }
}

s32 fn_8016DE08(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_8016DE10(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

extern f32 lbl_8055E3C8;
extern f32 lbl_80561998;
extern void fn_8001B450(s32);
extern void fn_802BAF98(void *, s8);
void fn_8016DFB8(void *arg0) {
    char sp8;
    char pad[0x28];
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    if (value == 1) {
        fn_801345D8(&sp8, 0x1e, lbl_803306D0 + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 1) {
        fn_801345D8(&sp8, 0x1e, lbl_803306D0 + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 3) {
        fn_801345D8(&sp8, 0x1e, lbl_803306D0 + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
    } else {
        fn_802E317C(lbl_803306D0 + 0x288);
    }
    fn_8016A15C(&sp8);
}

void fn_8016E06C(void *arg0) {
    s32 index = *(s32 *)((u8 *)arg0 + 0x2c);
    if (index < *(s32 *)((u8 *)arg0 + 0x3c)) {
        u8 *item = (u8 *)*(void **)((u8 *)arg0 + 0x18) + index * 0x14;
        s32 i;
        s32 offset;
        *item = 1;
        *(f32 *)(item + 0xc) = lbl_8055E3C8;
        *(s32 *)(item + 0x10) = 0;
        i = 0;
        offset = 0;
        while (i < *(s32 *)item) {
            if (*(s32 *)((u8 *)*(void **)item + offset + 4) != 0) {
                fn_802BAF98((u8 *)*(void **)item + offset, 1);
            }
            offset += 0x44;
            i += 1;
        }
    }
}

void fn_8016E118(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    if (value != -1) {
        fn_8001B450(value);
        *(s32 *)((u8 *)arg0 + 0x24) = -1;
    }
}

void fn_8016E15C(void *arg0, void *arg1) {
    s32 i;
    s32 offset;
    *(f32 *)((u8 *)arg0 + 0xc) = lbl_80561998;
    *(u8 *)((u8 *)arg0 + 9) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        i += 1;
        *(u8 *)((u8 *)*(void **)arg1 + offset + 0x30) = 0;
        offset += 0x38;
    }
}

s32 fn_8016E1A4(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x14);
}

void fn_8016E314(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0) = *(f32 *)((u8 *)arg0 + 4);
}

u8 fn_8016E320(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x9c);
}

extern f32 lbl_805619C0;
extern f32 fn_8016E878(void);
f32 fn_8016E878(void) {
    return lbl_805619C0;
}

extern char lbl_80330BC8[];
extern char lbl_80330BD8[];
extern void *fn_80145E70(const char *);
extern s32 fn_801284F8(s32, const char *);
extern void *fn_802ADDD8(s32);
extern void fn_8016EA9C(void *);
extern void fn_8016E984(void *);
extern s32 fn_80179650(void);
void fn_8016E880(void *arg0, void *arg1) {
    s32 count = *(s32 *)((u8 *)arg0 + 8);
    s32 index = 0;
    s32 offset = 0;
    void *items = *(void **)((u8 *)arg0 + 4);
    void *entry = arg1;
    *(s32 *)arg1 = count;
    *(s32 *)((u8 *)arg1 + 4) = fn_80179650();
    *((u8 *)arg1 + 0xD) = 1;
    *((u8 *)arg1 + 0xE) = 0;
    do {
        *(s32 *)((u8 *)entry + 0x10) = index;
        index += 1;
        *((u8 *)entry + 0x20) = 0;
        *(s32 *)((u8 *)entry + 0x18) =
            **(s32 **)((u8 *)items + offset);
        offset += 4;
        *(s32 *)((u8 *)entry + 0x14) = 1;
        *((u8 *)arg1 + 0xC) = 1;
        entry = (u8 *)entry + 0x14;
    } while (index < count);
}

void fn_8016E918(void *arg0) {
    s32 result;
    *(void **)((u8 *)arg0 + 0x98) = fn_80145E70(lbl_80330BC8);
    result = fn_801284F8(8, lbl_80330BD8);
    if (result != 0)
        *(void **)((u8 *)arg0 + 0xB8) = ((void *(*)(s32, s32))fn_802ADDD8)(result, 1);
    fn_8016EA9C((u8 *)arg0 + 0xAC);
    fn_8016E984((u8 *)arg0 + 0xAC);
}

extern f32 lbl_805619A4;
extern void fn_802AE0E0(s32);
#pragma scheduling off
void fn_8016E984(void *arg0) {
    s32 temp = *(s32 *)((u8 *)arg0 + 0xC);
    void *p;
    *(f32 *)((u8 *)arg0 + 4) = lbl_805619A4;
    *(s32 *)arg0 = 0;
    *((u8 *)arg0 + 8) = 1;
    *((u8 *)arg0 + 9) = 0;
    *((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0xF8) = 0;
    *(s32 *)((u8 *)arg0 + 0xFC) = 0;
    *(s32 *)((u8 *)arg0 + 0x100) = 0;
    *(s32 *)((u8 *)arg0 + 0x104) = 0;
    if (temp != 0) fn_802AE0E0(temp);
    p = *(void **)((u8 *)arg0 + 0x14);
    if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
    p = *(void **)((u8 *)arg0 + 0x18);
    if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
    p = *(void **)((u8 *)arg0 + 0x1C);
    if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
    p = *(void **)((u8 *)arg0 + 0x24);
    *((u8 *)arg0 + 0x20) = 0;
    if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
    p = *(void **)((u8 *)arg0 + 0x28);
    if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
    p = *(void **)((u8 *)arg0 + 0x2C);
    if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
}
#pragma scheduling on
extern f32 fn_8016FD58(void);
f32 fn_8016FD58(void) {
    return lbl_8055E3C8;
}

void fn_8016FD60(void *arg0, void *arg1) {
    s32 g;
    s32 d, c, b, a;
    f32 f, e;
    volatile s32 *src = (volatile s32 *)arg1;
    volatile f32 *fsrc = (volatile f32 *)((u8 *)arg1 + 0x10);
    a = src[0]; b = src[1]; c = src[2]; d = src[3];
    e = fsrc[0]; f = fsrc[1]; g = src[6];
    *(s32 *)arg0 = a;
    *((s32 *)arg0 + 1) = b;
    *((s32 *)arg0 + 2) = c;
    *((s32 *)arg0 + 3) = d;
    *(f32 *)((u8 *)arg0 + 0x10) = e;
    *(f32 *)((u8 *)arg0 + 0x14) = f;
    *((s32 *)arg0 + 6) = g;
}

void fn_8016FD9C(f32 *arg0, void *arg1) {
    char sp8[0x20];
    f32 value = *arg0;
    if (lbl_80561980 > value) {
        value = lbl_80561980;
    }
    fn_80130978(sp8, 0x20, value);
    fn_8014784C(arg1, lbl_80330B7C, lbl_80330B8C, 0);
    fn_801475D0(arg1, lbl_8055A248, lbl_8055A268, sp8);
}

#pragma cplusplus on
extern "C" void fn_8016FE1C(void *arg0) {
    ((TObj4C *)arg0)->v4C();
}
#pragma cplusplus reset
void fn_8016FF98(void *arg0) {
    s32 i = 0;
    s32 found = 0;
    s32 count = *(s32 *)((u8 *)arg0 + 8);
    void **items = *(void ***)((u8 *)arg0 + 4);
    if (count > 0) {
        for (; i < count; i++) {
            if (*((u8 *)items[i] + 8) != 0) {
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        fn_8016A438();
    }
}

extern char lbl_80330B7C[];
extern char lbl_80330B8C[];
extern char lbl_8055A248[];
extern char lbl_8055A268[];
extern void fn_80130978(void *, s32, f32);
extern void fn_8014784C(void *, const char *, const char *, s32);
extern void fn_801475D0(void *, const char *, const char *, void *);
extern void fn_8016A438(void);
s32 fn_8016FFE4(void) { return 0x1408; }

extern f64 fn_8002F234(f32, f32, f32, f32, f32);
void fn_80170DA8(void *arg0, void *arg1) {
    s32 index;
    s32 next;
    s32 *pool;
    u8 *items;
    u8 *item;
    volatile f32 sp1C, sp18, sp14, sp10, spC, sp8;
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;

    pool = *(s32 **)((u8 *)arg0 + 4);
    index = *(s32 *)((u8 *)arg0 + 0x10);
    next = index + 1;
    if (next < *(s32 *)((u8 *)pool + 4)) {
        items = (u8 *)*pool;
        item = items + next * 0x38;
        x = *(f32 *)((u8 *)arg1 + 0x60);
        y = *(f32 *)((u8 *)arg1 + 0x68);
        dx = *(f32 *)(item + 0x24) - x;
        sp18 = *(f32 *)(item + 0x24);
        dy = *(f32 *)(item + 0x2C) - y;
        sp1C = *(f32 *)(item + 0x2C);
        sp10 = x;
        sp14 = y;
        sp8 = dx;
        spC = dy;
        if ((f32)fn_8002F234(dx * dx + dy * dy, y, x, dx, dy) < *(f32 *)(item + 0x34)) {
            *(u8 *)(items + index * 0x38 + 0x30) = 0;
            *(s32 *)((u8 *)arg0 + 0x10) = next;
            pool = *(s32 **)((u8 *)arg0 + 4);
            items = (u8 *)*pool;
            *(u8 *)(items + next * 0x38 + 0x30) = 1;
        }
    }
}

s32 fn_80170E78(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x1ec); }

f32 fn_80170E80(f32 *arg0) { return *arg0; }

extern s32 fn_8017960C(s32);
s32 fn_80170E88(void *arg0) {
    return fn_8017960C(*(s32 *)((u8 *)arg0 + 4));
}

u8 fn_80170E90(void *arg0) { return *(u8 *)((u8 *)arg0 + 8); }

extern char lbl_803306D0[];
extern char lbl_80330AEC[];
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern void fn_801345D8(void *, s32, void *, s32);
extern void fn_802E317C(const char *, ...);
void fn_80170E98(void *arg0, void *arg1, s32 arg2) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    if (value == 1) {
        fn_801345D8(arg1, arg2, lbl_803306D0 + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 1) {
        fn_801345D8(arg1, arg2, lbl_803306D0 + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 3) {
        fn_801345D8(arg1, arg2, lbl_803306D0 + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
    } else {
        fn_802E317C(lbl_803306D0 + 0x288);
    }
}

s32 fn_80170F1C(void *arg0) {
    s32 result = 0;
    if (fn_801B8514() != 0 && *((u8 *)arg0 + 0x79) != 0 && *((u8 *)arg0 + 0x9C) == 0) {
        result = 1;
    }
    return result;
}

s32 fn_80170F7C(void *arg0) {
    if ((*(s32 (**)(void))(*(void ***)arg0 + 9))() != 0) {
        return *(s32 *)((u8 *)arg0 + 0xAC) == 2;
    }
    return 0;
}

u32 fn_80170FD4(void) { return 1; }

extern f32 lbl_80561A1C;
extern s32 fn_802AE220(s32);
extern s32 fn_8001DFCC(void);
u32 fn_80170FDC(void *arg0) {
    s32 temp_r4;
    if ((lbl_8055E3C8 - *(f32 *)((u8 *)arg0 + 0xA0)) < lbl_80561A1C) {
        ((void (*)(void *))(*(void ***)((u8 *)arg0))[0x13])(arg0);
    } else {
        if (*(u8 *)((u8 *)arg0 + 0xB4) != 0)
            ((void (*)(void *))(*(void ***)((u8 *)arg0))[0x13])(arg0);
        if (*(s32 *)((u8 *)arg0 + 0xB8) != 0)
            fn_802AE220(0);
    }
    if (((s32 (*)(void *))(*(void ***)((u8 *)arg0))[0x1A])(arg0) != 0)
        fn_8001DFCC();
    temp_r4 = *(s32 *)((u8 *)arg0 + 0xAC);
    return ((4 - temp_r4) | (temp_r4 - 4)) >> 31;
}

s32 fn_801711F8(void *arg0) {
    return *((u8 *)arg0 + 0x79) == 0;
}

void fn_80171208(void *arg0, s32 arg1) {
    fn_801B0C78((void *)arg1);
}

extern f32 lbl_80558DC4;
extern f32 lbl_80561A28;
extern f32 PSVECDotProduct(const void *, const void *, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
__declspec(section ".data") extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_8017133C(void *arg0, s32 arg1, s8 *arg2) {
    class Base {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual f32 f12();
    };
    class Pcr {
    public:
        virtual void p0(); virtual void p1(); virtual void p2();
        virtual s32 m3();
    };
    s32 result;
    s32 index;
    void *holder;
    void *data;
    void *item;
    s32 r25;
    s32 d;
    s32 r4v;
    s32 cond;
    void *obj;
    volatile f32 sp1C, sp18, sp14, sp10, spC, sp8;
    f32 x, y, dx, dy;
    f32 v;

    result = 0;
    v = lbl_8055E3C8;
    if (v > ((Base *)arg0)->f12() && *(u8 *)((u8 *)arg0 + 0x78) == 0) {
        index = arg1 * 4;
        data = (void *)fn_8017960C(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4));
        cond = ((f32)__fabs((f64)*(f32 *)((u8 *)data + 0x2690)) <= lbl_80558DC4);
        if (cond) {
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
            r4v = *(s32 *)((u8 *)arg0 + 0x5C);
            if (r4v < *(s32 *)((u8 *)arg0 + 0x6C)) {
                holder = (u8 *)(**(s32 ***)((u8 *)arg0 + 0x48)) + r4v * 0x14;
                if (*(void **)((u8 *)holder + 4) != 0 &&
                    *(s32 *)((u8 *)*(void **)((u8 *)holder + 4) + 4) > 0 &&
                    *(u8 *)((u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38 + 0x30) != 0) {
                    data = (void *)fn_8017960C(*(s32 *)((u8 *)obj + 4));
                    item = (u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38;
                    x = *(f32 *)((u8 *)data + 0x60);
                    y = *(f32 *)((u8 *)data + 0x68);
                    dx = *(f32 *)((u8 *)item + 0x24) - x;
                    dy = *(f32 *)((u8 *)item + 0x2C) - y;
                    sp10 = *(f32 *)((u8 *)item + 0x24);
                    sp14 = *(f32 *)((u8 *)item + 0x2C);
                    sp18 = x;
                    sp1C = y;
                    sp8 = dx;
                    spC = dy;
                    r25 = ((f32)fn_8002F234(dx * dx + dy * dy, y, x, dx, dy) > *(f32 *)((u8 *)item + 0x34));
                    d = (PSVECDotProduct((u8 *)item + 0x18, (u8 *)data + 0x54, *(f32 *)((u8 *)item + 0x34)) < lbl_80561980);
                    if (*(s32 *)((u8 *)holder + 0x10) == *(s32 *)((u8 *)*(void **)((u8 *)holder + 4) + 4) - 1 && r25) {
                        *(u8 *)((u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38 + 0x30) = 0;
                        result = 0;
                    } else {
                        if (r25 || d) {
                            if (*(u8 *)((u8 *)obj + 8) == 0) {
                                *(u8 *)((u8 *)obj + 8) = 1;
                                *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                            }
                            if (*(f32 *)((u8 *)obj + 0xC) > lbl_80561A28) {
                                *arg2 = 1;
                            } else {
                                *arg2 = 0;
                            }
                        } else {
                            *(u8 *)((u8 *)obj + 8) = 0;
                            *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                            *arg2 = 0;
                        }
                        result = 1;
                    }
                } else {
                    result = 0;
                }
            } else {
                result = 0;
            }
        }
        if (result == 0 &&
            *(s32 *)((u8 *)(void *)fn_8017960C(*(s32 *)((u8 *)obj + 4)) + 0x10) == 0x50434152) {
            data = (void *)fn_8017960C(*(s32 *)((u8 *)obj + 4));
            if (((Pcr *)*(void **)((u8 *)data + 0x270C))->m3() & 0x10) {
                obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
                if (*(u8 *)((u8 *)obj + 8) == 0) {
                    *(u8 *)((u8 *)obj + 8) = 1;
                    *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                }
            } else {
                if (!(((Pcr *)*(void **)((u8 *)data + 0x270C))->m3() & 0x10)) {
                    obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
                    if (*(u8 *)((u8 *)obj + 8) != 0) {
                        *(u8 *)((u8 *)obj + 8) = 0;
                        *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                    }
                }
            }
        }
    }
    return result;
}
#pragma cplusplus reset
#pragma pop
extern char lbl_80330BC8[];
extern char lbl_80330BD8[];
extern void *fn_80145E70(const char *);
extern s32 fn_801284F8(s32, const char *);
extern void *fn_802ADDD8(s32);
extern void fn_8016EA9C(void *);
extern void fn_8016E984(void *);
extern s32 fn_80179650(void);
