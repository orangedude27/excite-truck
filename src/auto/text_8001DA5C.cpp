#include <types.h>
#include <math.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern f32 lbl_8055E3C8;
extern f32 lbl_80560470;
extern f32 lbl_80560474;
extern f32 lbl_80560490;

extern "C" s32 fn_80128668(void);
extern void* lbl_80358680[];

class CollisionEntry {
public:
    virtual void unk0();
    virtual void apply(s32, s32);
};
extern s32 lbl_8055E3C4;
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
extern "C" void** lbl_8055D604;
extern "C" void** lbl_8055D5F4;
extern "C" void** lbl_8055D5F8;

class CleanupEntry {
public:
    virtual void cleanup(s32);
};

class PaneContainer {
public:
    virtual void dummy0();
    virtual void* getPane(const char* name);
};

struct PaneData {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    f32 f10;
    u32 w14;
    u32 w18;
    u32 w1c;
};

extern "C" const char* fn_80131234(const char*);
extern "C" void fn_80147230(void*, const char*, ...);
extern "C" void fn_801476C4(...);
extern "C" s32 fn_80147C50(u32, u32, f32);
extern "C" void fn_80147CEC(void*, void*, void*, f32);
extern "C" void* fn_8017960C(s32);
extern "C" s32 fn_801E85A4(void);
extern "C" void fn_80232928(s32);
extern "C" void fn_80232930(void);

extern char lbl_802FDB68[];
extern char lbl_80558D08[4];
__declspec(section ".data") extern f32 lbl_80558DC4;
extern f32 lbl_8056047C;
extern f32 lbl_80560480;
extern f32 lbl_80560484;
extern f32 lbl_80560488;
extern f32 lbl_8056048C;
extern f32 lbl_80560460;
extern f32 lbl_80560464;
extern f64 lbl_80560468;
f32 fn_8001DA5C(s32 arg0) {
    f64 bias = lbl_80560468;
    f64 angle;
    f64 fraction;
    s32 quotient = lbl_8055E3C4 / arg0;
    s32 remainder;
    union { f64 d; u32 words[2]; } angle_bits;
    union { f64 d; u32 words[2]; } fraction_bits;
    union { f64 d; u32 words[2]; } integer_bits;
    integer_bits.words[0] = 0x43300000;
    integer_bits.words[1] = arg0 ^ 0x8000;
    angle = integer_bits.d - bias;
    remainder = lbl_8055E3C4 - quotient * arg0;
    fraction_bits.words[0] = 0x43300000;
    fraction_bits.words[1] = remainder ^ 0x8000;
    fraction = fraction_bits.d - bias;
    return lbl_80560464 + lbl_80560464 * (f32)sin((f64)(lbl_80560460 * fraction / angle));
}

extern "C" void fn_8001DAD8(void) { extern int fn_8001DA5C(int); fn_8001DA5C(0x40); }

extern "C" void fn_8001DAE0(f32* arg0, f32 arg1) {
    *arg0 = arg1;
}

extern "C" f32 fn_8001DAE8(void) {
    return lbl_8055E3C8;
}

extern "C" s32 fn_8001DD2C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma scheduling off
extern "C" void fn_8001DD6C(void) {
    if (lbl_8055D604 != 0) ((CleanupEntry*)lbl_8055D604)->cleanup(1);
    lbl_8055D604 = 0;
    if (lbl_8055D5FC != 0) ((CleanupEntry*)lbl_8055D5FC)->cleanup(1);
    lbl_8055D5FC = 0;
    if (lbl_8055D600 != 0) ((CleanupEntry*)lbl_8055D600)->cleanup(1);
    lbl_8055D600 = 0;
    if (lbl_8055D5F4 != 0) ((CleanupEntry*)lbl_8055D5F4)->cleanup(1);
    lbl_8055D5F4 = 0;
    if (lbl_8055D5F8 != 0) ((CleanupEntry*)lbl_8055D5F8)->cleanup(1);
    lbl_8055D5F8 = 0;
    for (s32 i = 0; i < 6; i++) {
        if (lbl_80358680[i] != 0) ((CleanupEntry*)lbl_80358680[i])->cleanup(1);
        lbl_80358680[i] = 0;
    }
}
#pragma scheduling reset
void fn_8001DEA8(void) {
    u32 var_r30;
    void ***var_r31;
    
    var_r31 = (void ***)lbl_80358680;
    var_r30 = 0;
    do {
        void **temp = var_r31[0];
        ((void (**)(void *))temp)[4](temp);
        var_r30++;
        var_r31++;
    } while (var_r30 < 6);
}

extern "C" void fn_8001DF04(void) {
}

extern "C" void fn_8001DF08(s32 arg0, s32 arg1) {
    ((CollisionEntry*)lbl_80358680[0])->apply(arg0, arg1);
    ((CollisionEntry*)lbl_80358680[2])->apply(arg0, arg1);
}

extern "C" void fn_8001DF84(s32 arg0) {
    void* p = lbl_80358680[1];
    ((CollisionEntry*)p)->apply(arg0, 0);
}

extern "C" void fn_8001DFA8(s32 arg0) {
    void* obj = ((void**)&lbl_80358680)[3];
    ((void (**)(void*, s32, s32))*(void**)obj)[3](obj, arg0, 0);
}
#pragma scheduling reset
extern "C" void fn_8001DFCC(void) {
    ((CollisionEntry*)lbl_80358680[4])->apply(9, 17);
}

extern "C" void fn_8001DFF0(void) {
    ((CollisionEntry*)lbl_80358680[5])->apply(0, 0);
}

extern "C" void fn_802CAC54(void*);
extern "C" int lbl_802FDC98[];
extern "C" void* __dt__14CollisionSpaceFv(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_802FDC98;
        fn_802CAC54(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_8001E26C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8001E2AC(void* arg0, s32 arg1) {
    PaneData buffer;
    f32* p;
    const char* base = lbl_802FDB68;
    void* truck = fn_8017960C(arg1);
    p = (f32*)arg0 + arg1 * 3;
    bool active = *(f32*)((u8*)truck + 0x2588) > lbl_80560474;
    if (active) {
        if (!((f32)fabs(p[2] - lbl_80560470) <= lbl_80558DC4)) {
            p[1] = lbl_8055E3C8;
            p[2] = lbl_80560470;
        } else {
            p[2] = *(volatile f32*)&p[2] - lbl_8056047C;
        }
    } else {
        p[2] = lbl_80560474;
    }
    p[3] = *(f32*)((u8*)truck + 0x25A0);

    PaneContainer* paneMgr;
    if (fn_801E85A4() == 2) {
        paneMgr = (PaneContainer*)lbl_8055D5F8;
    } else {
        paneMgr = (PaneContainer*)lbl_8055D5F4;
    }
    if (paneMgr == NULL) {
        return;
    }

    if (p[2] > lbl_80560480) {
        arg1 = (s32)(lbl_80560484 * p[2]);
        void* r28 = paneMgr->getPane(base + 0x1FC);
        void* r29 = paneMgr->getPane(base + 0x20C);
        if (r28 != NULL && r29 != NULL) {
            f32 f2 = lbl_80560470;
            f32 f0 = ((lbl_8055E3C8 - p[1]) - f2) / lbl_80560488;
            f2 = (f2 < f0) ? f2 : f0;
            f2 = (f2 > lbl_80560474) ? f2 : lbl_80560474;
            fn_80147CEC(&buffer, r28, r29, lbl_80560474 + f2 * lbl_80560470);
            f32 factor1 = ((f32(*)(void))fn_8001DAD8)();
            u32 c1 = (u32)fn_80147C50(*(u32*)((u8*)r28 + 0x18), *(u32*)((u8*)r29 + 0x18), factor1);
            buffer.w18 = (c1 & 0x00FFFFFF) | (arg1 << 24);
            arg1 <<= 24;
            f32 factor2 = ((f32(*)(void))fn_8001DAD8)();
            u32 c2 = (u32)fn_80147C50(*(u32*)((u8*)r29 + 0x18), *(u32*)((u8*)r28 + 0x18), factor2);
            fn_80232928((c2 & 0x00FFFFFF) | arg1);
            fn_80147230(&buffer, lbl_80558D08, fn_80131234(base + 0x220));
            fn_80232930();
        }
    } else if (p[3] > lbl_8056048C) {
        void* r3 = paneMgr->getPane(base + 0x238);
        if (r3 != NULL) {
            PaneData temp = *(PaneData*)r3;
            f32 factor = ((f32(*)(void))fn_8001DAD8)();
            temp.w18 = fn_80147C50(0xC0FFFFFFU, 0xFFFF2020U, factor);
            fn_801476C4(&temp);
        }
    }
}

extern "C" f32 fn_8001DA5C(s32);
extern f32 lbl_80560490;
#pragma scheduling off
extern "C" void fn_8001E544(void* arg0) {
    f32 a = lbl_80560490;
    f32 b = lbl_80560474;
    ((f32*)arg0)[1] = b;
    ((f32*)arg0)[2] = a;
    ((f32*)arg0)[3] = a;
    ((f32*)arg0)[4] = b;
    ((f32*)arg0)[5] = a;
    ((f32*)arg0)[6] = a;
    ((f32*)arg0)[7] = b;
    ((f32*)arg0)[8] = a;
    ((f32*)arg0)[9] = a;
    ((f32*)arg0)[10] = b;
    ((f32*)arg0)[11] = a;
    ((f32*)arg0)[12] = a;
    ((f32*)arg0)[13] = b;
    ((f32*)arg0)[14] = a;
    ((f32*)arg0)[15] = a;
    ((f32*)arg0)[16] = b;
    ((f32*)arg0)[17] = a;
    ((f32*)arg0)[18] = a;
    ((f32*)arg0)[19] = b;
    ((f32*)arg0)[20] = a;
    ((f32*)arg0)[21] = a;
    ((f32*)arg0)[22] = b;
    ((f32*)arg0)[23] = a;
    ((f32*)arg0)[24] = a;
}
#pragma scheduling on
extern s32 lbl_802FDC70;
extern "C" void* fn_8001E5B0(void* arg0, s32 arg1) {
    void* entry;
    if (arg0 != 0) {
        entry = *(void**)((u8*)arg0 + 0x24);
        *(void**)arg0 = &lbl_802FDC70;
        if (entry != 0) {
            ((void (**)(void*, s32))(*(void***)entry))[1](entry, 1);
        }
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8001E964(void* arg0) {
    f32 value = lbl_80560490;
    *(f32*)((u8*)arg0 + 0x34) = value;
    *(f32*)((u8*)arg0 + 0x2C) = value;
}

extern "C" s32 fn_8001E974(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void* fn_801EA9A0(s32);
extern "C" f32 fn_801E7E18(void);
extern "C" void* fn_801E7E3C(void);
extern "C" void fn_801345D8(char*, s32, const char*, ...);
extern "C" s32 fn_80147ABC(s32, s32, const char*, char*, ...);
extern "C" u32 lbl_802ED840[];
extern "C" char lbl_80558D14[];
extern "C" char lbl_80558D1C[];
extern "C" char lbl_80558D24[];
extern "C" void fn_8001E9B4(s32 arg0, s32 arg1) {
    s32* record = (s32*)(arg0 + arg1 * 8);
    void* object = fn_801EA9A0(arg1);
    f32 now = fn_801E7E18();
    s32 rank = *(s32*)((u8*)object + 0x1C);
    f32 delta;
    f32 thresholds[4];
    void* widget;
    s32 idsA[4];
    s32 idsB[4];
    char nameA[32];
    char nameB[32];
    char temp[30];

    if (rank > record[1]) {
        *(f32*)((u8*)record + 8) = now;
        record[1] = rank;
    }
    delta = now - *(f32*)((u8*)record + 8);
    thresholds[0] = *(f32*)((u8*)&lbl_802ED840[0]);
    thresholds[1] = *(f32*)((u8*)&lbl_802ED840[1]);
    thresholds[2] = *(f32*)((u8*)&lbl_802ED840[2]);
    thresholds[3] = *(f32*)((u8*)&lbl_802ED840[3]);
    widget = lbl_8055D604;
    if (widget != 0 && delta < thresholds[3]) {
        for (s32 row = 0; row < 2; row++) {
            s32* out = row == 0 ? idsB : idsA;
            for (s32 col = 0; col < 4; col++) {
                char text[32];
                fn_801345D8(text, 0x20, lbl_80558D14,
                            row == 0 ? lbl_80558D1C : lbl_80558D24, col);
                out[col] = ((s32 (**)(void*, char*))(*(void***)widget))[3](widget, text);
            }
        }
        void* menu = fn_801E7E3C();
        s32 current = *(s32*)((u8*)record + 4);
        s32 count = *(s32*)((u8*)menu + 8);
        if (current != 1 && current <= 3) {
            if (current < count) {
                const char* text = fn_80131234(lbl_802FDB68 + 0x278);
                for (s32 i = 0; i < 32; i++) {
                    nameA[i] = text[i];
                    if ((s8)text[i] == 0) break;
                }
                fn_801345D8(temp, 0x1E, lbl_802FDB68 + 0x28C, current);
                text = fn_80131234(temp);
                for (s32 i = 0; i < 32; i++) {
                    nameB[i] = text[i];
                    if ((s8)text[i] == 0) break;
                }
            } else if (current == count) {
                const char* text = fn_80131234(lbl_802FDB68 + 0x2A4);
                for (s32 i = 0; i < 32; i++) {
                    nameA[i] = text[i];
                    if ((s8)text[i] == 0) break;
                }
                text = fn_80131234(lbl_802FDB68 + 0x2B8);
                for (s32 i = 0; i < 32; i++) {
                    nameB[i] = text[i];
                    if ((s8)text[i] == 0) break;
                }
            } else {
                return;
            }
            s32 index = 0;
            if (delta < thresholds[1]) {
                index = 0;
            } else if (delta < thresholds[2]) {
                index = 1;
            } else if (delta < thresholds[3]) {
                index = 2;
            }
            f32 t = (delta - thresholds[index]) /
                    (thresholds[index + 1] - thresholds[index]);
            if (t < lbl_80560470) t = lbl_80560470;
            if (t > lbl_80560474) t = lbl_80560474;
            f32 value = lbl_80560474 + t * lbl_80560470;
            fn_80232928(-1);
            fn_80147ABC(idsB[index], idsB[index + 1], lbl_80558D08, nameA, value);
            fn_80147ABC(idsA[index], idsA[index + 1], lbl_80558D08, nameB, value);
            fn_80232930();
        }
    }
}

extern "C" void fn_8001ED2C(void* arg0) {
    f32 value = lbl_80560490;
    *(s32*)((u8*)arg0 + 0x04) = 0;
    *(f32*)((u8*)arg0 + 0x08) = value;
    *(s32*)((u8*)arg0 + 0x0C) = 0;
    *(f32*)((u8*)arg0 + 0x10) = value;
    *(s32*)((u8*)arg0 + 0x14) = 0;
    *(f32*)((u8*)arg0 + 0x18) = value;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(f32*)((u8*)arg0 + 0x20) = value;
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(f32*)((u8*)arg0 + 0x28) = value;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(f32*)((u8*)arg0 + 0x30) = value;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
}

extern "C" s32 fn_8001ED78(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801E85A4(void);
extern "C" void* lbl_802FDE38;
extern "C" void* lbl_802FDE48;
extern "C" void* lbl_802FDE54;
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
extern "C" void fn_8001EDB8(void) {
    void* object = &lbl_802FDE38;
    void** selected;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((void (*)(void*, void*))(*(void***)*selected)[3])(*selected, object);
    fn_801476C4();
}

extern "C" s32 fn_8001EE14(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8001EE54(void) {
    void* object = &lbl_802FDE48;
    void** selected;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((void (*)(void*, void*))(*(void***)*selected)[3])(*selected, object);
    fn_801476C4();

    object = &lbl_802FDE54;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((void (*)(void*, void*))(*(void***)*selected)[3])(*selected, object);
    fn_801476C4();
}

