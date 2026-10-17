#include <types.h>
class Unk8012A570 { public: virtual ~Unk8012A570(); };

extern "C" s32 lbl_8055E004;
extern "C" void **lbl_8055E008;
extern "C" u32 lbl_805599A0;
extern "C" u8 lbl_8032A6F8[];
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

extern void fn_8012E498(void);
extern void fn_8012CC24(void);

extern "C" void fn_8012A46C(void) {

}

#pragma dont_inline on
extern "C" void *fn_8012A570(u32, void *) {
    if (lbl_8055E004 == 0) {
        void *p = fn_801284F8(0x20, (void *)&lbl_8032A6F8);
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

extern "C" void fn_8012A648(void) {
    void *p = fn_8012A570(0x18, &lbl_805599A0);
    fn_8012A364(lbl_8055E008, p);
}
#pragma dont_inline reset
#pragma scheduling reset
#pragma dont_inline on
extern "C" void fn_8012A67C(void) {
    lbl_8055E004 = 0;
    delete (Unk8012A570 *)lbl_8055E008;
    lbl_8055E008 = 0;
}

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
extern "C" void fn_8012A7FC(void) {
    lbl_8055DFF9 = 1;
    fn_802E2D74(0x32);
}

extern "C" s32 fn_8012AB34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result = 0;
    if (fn_802E39D0(arg0, 0x34) != 0) {
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

#pragma dont_inline reset

extern "C" void fn_8012AC28(s32, s32);
extern "C" void fn_8012AC98(s32 arg0) {
    fn_8012AC28(arg0, 0);
}

extern "C" s32 fn_8012B2C4(s32, s32, s32);
extern "C" void fn_8012B314(s32 arg0, s32 arg1, s32 arg2) {
    fn_8012B2C4(arg1, arg0, arg2);
}

extern "C" void fn_8012B324(void) {

}

extern "C" void fn_8012B328(void) {

}

s32 fn_8012B50C(void *arg0, void *arg1) {
    if ((*(u32 *)((char *)arg0 + 0x34) & 0x20) &&
        (*(u32 *)((char *)arg1 + 0x34) & 0x10)) {
        return 1;
    }
    return 0;
}

extern "C" u32 fn_8012BB18(void) { return 1; }

void fn_8012BC24(s32 **arg0, s32 *arg1) {
    s32 *var = *arg0;

    while (var != 0) {
        if (var == arg1) {
            *arg0 = (s32 *)((char *)arg1 + 0xA8)[0];
            return;
        }
        var = (s32 *)((char *)var + 0xA8);
    }
}

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

#pragma use_lmw_stmw off
extern "C" s32 fn_8012C370(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 result;
    s32 i = 0;

    do {
        lbl_8055DFF9 = 0;
        result = fn_8012B85C(arg0, arg1, arg2, arg3, arg4, arg5);
        if (lbl_8055DFF9 != 0 && result == 0) {
            fn_802E30C8(lbl_8032AB78, arg0);
            fn_80127464();
            i++;
        }
    } while (i < 10);
    return result;
}
#pragma use_lmw_stmw off
extern "C" void fn_8012C41C(s32 (*arg0)(void *, void *, void *, s32), s32 arg1, const char *arg2) {
    s32 off;
    void *node;
    s32 i;
    void *arg2b;
    s32 arg1b;

    for (node = lbl_8055E000; node != NULL;
         node = *(void **)((u8 *)node + 0xA8)) {
        if (arg2 == 0 || stricmp((const char *)node, arg2) == 0) {
            arg2b = node;
            arg1b = arg1;
            i = 0;
            off = 0;
            while (i < *(s32 *)((u8 *)node + 0x88)) {
                u8 *entry = *(u8 **)((u8 *)node + 0x60) + off;
                if (*(u32 *)(entry + 0x34) & 8) {
                    if (arg0(entry, *(void **)(entry + 0x20), arg2b, arg1b) == 0) {
                        return;
                    }
                }
                off += 0x44;
                i++;
            }
        }
    }
}
#pragma use_lmw_stmw reset
extern "C" void fn_8012C4D8(void *arg0) {
    fn_8012BC50(arg0, 0, 0);
}

extern "C" void fn_8012CC20(void) {
    fn_8012CC24();
}

extern "C" u32 fn_8012D3D0(void) { return 1; }

extern "C" void fn_8012D40C(s32);
extern "C" void fn_8012D1A8(s32);
extern "C" void fn_8012D3D8(s32 arg0) {
    fn_8012D40C(arg0);
    fn_8012D1A8(arg0);
}

extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_8012DCC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern "C" void fn_80127E28(void *);
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
};
struct Unk8012DFCCList {
    Unk8012DFCCNode *head;
    Unk8012DFCCNode **tail;
};


extern "C" s32 fn_8012CAA0(s32);
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
    *(s32 *)((u8 *)arg0 + 0x4c) = fn_8012CAA0(arg2);
    *(s32 *)((u8 *)arg0 + 8) = 1;
}

extern "C" s32 fn_8012E490(s32 *arg0) {
    return *arg0;
}

extern "C" s32 fn_8012E674(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

extern "C" s32 fn_8012EE78(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

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

