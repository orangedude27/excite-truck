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
extern "C" s32 fn_8012E9F0(s32, s32);
extern "C" void fn_8012E67C(s32, s32);
extern "C" void fn_8012D3D8(s32);
extern "C" void fn_8012D8A8(s32);
extern "C" void *fn_801282EC(u32);
extern "C" void *fn_8012850C(u32, void *);
extern "C" void *memset(void *, s32, u32);
extern "C" u8 lbl_805599C8[];
extern "C" u8 lbl_805599D0[];

extern void fn_8012E498(void);
extern void fn_8012CC24(void);

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
    s32 result;
    void *buffer;
    const char *strings;

    strings = lbl_8032A630;
    buffer = (char *)arg3 + *(s32 *)((char *)arg2 + 0x2C);
    buffer = (char *)buffer - 8;
    *(void **)((char *)arg2 + 0x3C) = buffer;
    fn_8012A46C((char *)buffer + 8, strings);
    result = fn_80132E7C((char *)buffer + 8, *(s32 *)((char *)arg2 + 0x28)) == *(s32 *)((char *)arg2 + 0x30);
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

extern "C" s32 fn_8012A388(void *);
extern "C" s32 fn_8012A470(void *, s32, void *, void *);
extern "C" s32 fn_80132E7C(void *, s32);
extern "C" const char lbl_8032A7E8[];
extern "C" s32 fn_8012AA60(void *arg0, s32 arg1, s32 arg2) {
 s32 count=*(s32*)((char*)arg0+0x88);
 void *base=*(void**)((char*)arg0+0x60);
 s32 result=*(s32*)((char*)arg0+0x94);
 void *p=base;
 if (result == fn_80132E7C(base,count*0x44)) {
  s32 i=0;
  while(i<count) {
   fn_8012A388(p);
   if (*(s32*)((char*)p+0x2c)+*(s32*)((char*)p+0x28)>arg1) goto next;
   if(fn_8012A470(arg0,i,p,base)==0){result=0;break;}
  next:
   p=(char*)p+0x44; ++i;
  }
 } else { fn_802E30C8("%s",arg0); }
 return result;
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

extern "C" void fn_8012AC28(s32 arg0, s32 arg1) {
    u8 buffer[0x104];
    s32 spC = -1;
    s32 sp8;

    fn_802E4CA8(buffer, arg0, 0x104);
    if (fn_802E7354(buffer) != -1) {
        fn_802E746C(&spC, &sp8);
        if (arg1 != 0) *(s32 *)arg1 = sp8;
    }
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

extern "C" u8 *fn_8012B4E4(u8 *arg0, u8 *arg1) {
    s8 ch = (s8)*arg0;
    *arg1 = ch == 0x2A;
    if (ch == 0x2A)
        return arg0 + 1;
    return arg0;
}

extern "C" s32 fn_8012B50C(void *arg0, void *arg1) {
    if ((*(u32 *)((char *)arg0 + 0x34) & 0x20) &&
        (*(u32 *)((char *)arg1 + 0x34) & 0x10)) return 1;
    return 0;
}

extern "C" const char lbl_8032A630[];
extern "C" const char lbl_805599A4[];
extern "C" s32 strstr(const char *, const char *);
extern "C" void fn_8012BA1C(void *arg0) {
    s32 i, offset, j, offset2, value;
    i = 0; offset = 0;
    while (i < *(s32 *)((char *)arg0 + 0x88)) {
        value = *(s32 *)(*(char **)((char *)arg0 + 0x60) + offset + 0x38);
        if (value > 0) fn_802E30C8(lbl_8032A630 + 0x470, arg0);
        offset += 0x44; i++;
    }
    if (strstr((const char *)arg0, lbl_805599A4) != 0 && stricmp((const char *)arg0, lbl_8032A630 + 0x4A0) != 0) {
        j = 0; offset2 = 0;
        while (j < *(s32 *)((char *)arg0 + 0x88)) {
            value = *(s32 *)(*(char **)((char *)arg0 + 0x60) + offset2 + 0x34);
            if ((value & 0xA) == 8) fn_802E30C8(lbl_8032A630 + 0x4AC, arg0);
            offset2 += 0x44; j++;
        }
    }
}

extern "C" u32 fn_8012BB18(void) { return 1; }

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

extern "C" void *fn_8012BD3C(void *arg0, const char *arg1) {
    void *entry = arg0;
    do {
        if (stricmp(arg1, (const char *)entry) == 0) break;
        entry = *(void **)((char *)entry + 0xA8);
    } while (entry != 0);
    return entry;
}

extern "C" void *fn_8012B32C(const char *);
extern "C" void fn_8012748C(s32);
extern "C" const char lbl_8032AB2C[];
extern "C" const char lbl_8032AB58[];
extern "C" void *fn_8012BD98(const char *arg0, void **arg1, s32 arg2) {
    s32 tries = 0;
    void *p = fn_8012BD3C(*arg1, arg0);
    if (p == 0) {
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
            if (lbl_8055DFF9 == 0 || p != 0) break;
            ++tries;
        } while (tries < 10);
        if (p == 0) {
            fn_802E30C8(lbl_8032AB58, arg0);
            fn_8012748C(2);
        }
    } else ++*(s32 *)((char *)p + 0x9C);
    return p;
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

extern "C" s32 fn_8012B534(s32 *, s32);
extern "C" s32 fn_8012C33C(void) {
    s32 sp8;
    return fn_8012B534(&sp8, 0) != 0;
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

extern "C" void fn_8012D33C(u32 *arg0, u32 *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
    arg0[4] = arg1[4];
    arg0[5] = arg1[5];
    arg0[6] = arg1[6];
    arg0[7] = arg1[7];
    arg0[8] = arg1[8];
    arg0[9] = arg1[9];
    arg0[10] = arg1[10];
    arg0[11] = arg1[11];
    arg0[12] = arg1[12];
}

extern "C" u32 fn_8012D3D0(void) { return 1; }

extern "C" void fn_8012D40C(s32);
extern "C" void fn_8012D1A8(s32);
extern "C" void fn_8012D3D8(s32 arg0) {
    fn_8012D40C(arg0);
    fn_8012D1A8(arg0);
}

s32 fn_8012D838(void *arg0) {
    s32 temp_r0;

    fn_8012D40C((long)arg0);
    temp_r0 = *(s32 *)((u8 *)arg0 + 0xB8);
    switch (temp_r0) {
    case 2:
        return 1;
    case 3:
        return 2;
    case 1:
        return 0;
    default:
        return 0;
    }
}

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

extern "C" void fn_8012D024(void *, s32);
extern "C" void fn_8012E40C(void *arg0, s32 arg1) {
    fn_8012D40C((s32)arg0);
    fn_8012D1A8((s32)arg0);
    *(volatile s32 *)((u8 *)arg0 + 0xBC) = 0;
    fn_8012D024(arg0, arg1);
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
 s32 i;
 u8 *p;
 for (i=0, p=(u8 *)arg0+4; i<2; i++, p+=0x10) {
  if (*(s32 *)(p+4)) {
   fn_8012C90C((void *)*(s32 *)(p+4));
   fn_8012C958((void *)*(s32 *)(p+4));
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
    s32 i;
    s32 *base = (s32 *)((char *)arg0 + 4);
    s32 *p;
    s32 result;
    for (i = 0, p = base; i < 2; i++, p += 4) {
        if (p[1] != 0) {
            fn_8012C90C((void *)p[1]);
            fn_8012C958((void *)p[1]);
            p[1] = 0;
            p[3] = 0;
        }
    }
    *(s32 *)((char *)arg0 + 0x28) = 0;
    for (i = 0, p = base; i < 2; i++, p += 4) {
        result = fn_8012C5B8(arg1, arg2, arg3);
        p[1] = result;
        if (result == 0) return 0;
        *(s32 *)((char *)arg0 + 0x24) = fn_8012C6F0((void *)result);
    }
    fn_8012EE80(arg0);
    return 1;
}

extern "C" s32 fn_8012EE78(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

extern "C" s32 fn_8012EFB0(void *arg0, void *arg1, s32 arg2) {
 s32 pos=*(s32 *)((u8 *)arg0+0x28), i; u8 *p;
 if(pos+arg2>=*(s32 *)((u8 *)arg0+0x24)) return 0;
 for(i=0,p=(u8 *)arg0;i<2;i++,p+=0x10) {
  s32 start;
  if(*(s32 *)(p+0xC)!=2) continue;
  start=*(s32 *)(p+8);
  if(pos>=start && pos<start+*(s32 *)arg0) {
   memcpy(arg1,(u8 *)*(void **)p+(pos-start),arg2);
   *(s32 *)((u8 *)arg0+0x28)+=arg2; return 1;
  }
 }
 return 0;
}

extern "C" s32 fn_8012D838(s32);
extern "C" void fn_8012F06C(void *arg0) {
    s32 done;
    s32 entry;
    s32 state;
    if (*(u8 *)((char *)arg0 + 0xA20) == 0) {
        *(u8 *)((char *)arg0 + 0xA20) = 1;
        do {
            done = 0;
            entry = fn_8012E490((s32 *)((char *)arg0 + 0xA18));
            if (entry != 0) {
                state = fn_8012D838(*(s32 *)(entry + 0x4C));
                if (state != 1) {
                    if (state >= 0) {
                        if (state < 3) {
                            fn_8012E40C((void *)*(s32 *)(entry + 0x4C), (s32)(entry + 0xC));
                        }
                    } else {
                        /* negative states are ignored */
                    }
                    if (state >= 0 && state < 1) {
                        void *p = fn_8012BD3C(lbl_8055E000, (const char *)(entry + 0xC));
                        *(s32 *)((char *)p + 0x9C) = *(s32 *)(entry + 8);
                        *(u8 *)((char *)p + 0xAD) = 1;
                        fn_8012E3D4((char *)arg0 + 0xA18);
                        done = 1;
                    }
                }
            }
        } while (done != 0);
        *(u8 *)((char *)arg0 + 0xA20) = 0;
    }
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
    void *file = *(void **)((u8 *)arg0 + 4);
    void *context;
    s32 offset;
    s32 base;
    s32 temp;
    if ((*(u32 *)((u8 *)file + 0x34) & 8) == 0) {
        file = *(void **)((u8 *)arg0 + 4);
        context = *(void **)((u8 *)arg0 + 8);
        base = *(s32 *)((u8 *)context + 0x80);
        temp = *(s32 *)((u8 *)file + 0x2C);
        offset = base + (arg3 + temp);
        context = *(void **)((u8 *)arg0 + 8);
        *(s32 *)((u8 *)arg0 + 0xC) = fn_802E748C(*(s32 *)((u8 *)context + 0xA4) + offset / 2048, base, file);
        *(s32 *)((u8 *)arg0 + 0x10) = arg1 + (offset & 0x7FF);
        *(s32 *)((u8 *)arg0 + 0x14) = arg2;
    } else {
        fn_802E30C8(lbl_8032AC34, file);
        file = *(void **)((u8 *)arg0 + 4);
        memcpy((void *)arg1, (void *)(*(u32 *)((u8 *)file + 0x3C) + 8), *(u32 *)((u8 *)file + 0x28));
        *(s32 *)((u8 *)arg0 + 0x10) = arg1;
        *(s32 *)((u8 *)arg0 + 0xC) = -1;
        *(s32 *)((u8 *)arg0 + 0x14) = arg2;
    }
}

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

extern "C" const char lbl_8032AE20[];
extern "C" void *fn_8012CB44(void *arg0, s32 arg1) {
    s32 i;
    s32 offset;
    u32 flags;
    void *p;
    if (arg0 != 0) {
        if (*(u8 *)((char *)arg0 + 0xAC) != 0) {
            i = 0;
            offset = 0;
            while (i < *(s32 *)((char *)arg0 + 0x88)) {
                p = (char *)*(void **)((char *)arg0 + 0x60) + offset;
                if (*(u32 *)((char *)p + 0x34) & 4)
                    fn_802E317C(lbl_8032AE20);
                ++i;
                p = (char *)*(void **)((char *)arg0 + 0x60) + offset;
                flags = *(u32 *)((char *)p + 0x34);
                offset += 0x44;
                *(u32 *)((char *)p + 0x34) = flags & 0xFFFFFFF0;
            }
            p = *(void **)((char *)arg0 + 0x64);
            if (p != 0) fn_8012C4D8(p);
            p = *(void **)((char *)arg0 + 0xA0);
            if (p != 0) fn_80128660((s32)p);
            *(u8 *)((char *)arg0 + 0xAC) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

