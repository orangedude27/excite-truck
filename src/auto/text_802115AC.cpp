// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" s32 fn_80218C14(s32, s32);
extern "C" s32 fn_802E317C(const char *);
extern "C" s32 fn_80214934(const void *, s32, void *, s32);
extern "C" s32 fn_80029004(const char *, s32);
extern "C" s32 fn_801345D8(void *, s32, const char *, s32, s32, const char *);
extern "C" unsigned long strlen(const char *);
extern "C" char lbl_8055B808[];
extern "C" s32 fn_802C4F14(s32);
extern "C" s32 fn_802C4C90(s32, s32, s32, s32, s32);
extern "C" s32 fn_8021481C(void *);
extern "C" char lbl_8033D388[];
extern "C" char lbl_8033D268[];
extern "C" char lbl_8055B810[];

extern "C" s32 fn_802168E4(void);
extern "C" s32 fn_802168DC(s32);
extern "C" s32 fn_802168D4(s32);
extern "C" s32 fn_802168CC(s32, float);
extern "C" s32 fn_802168E0(s32, s32, s32);
extern "C" char lbl_8033D2E0[];
extern "C" char lbl_8033D328[];
extern "C" char lbl_8033D2A0[];
extern "C" char lbl_8033D274[];

extern "C" s32 fn_802168DC(s32);
extern "C" s32 fn_802168D4(s32);
extern "C" s32 fn_802168CC(s32, float);
extern "C" s32 fn_802168E0(s32, s32, s32);
extern "C" char lbl_8033D2E0[];
extern "C" char lbl_8033D328[];
extern "C" char lbl_8033D2A0[];
extern "C" char lbl_8033D274[];

class VfObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();     // vtable 0x24
    virtual void vf10();    // vtable 0x28
    virtual void vf11();    // vtable 0x2C
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
      virtual void vf16();
  virtual void vf17();
  virtual void vf18();
  virtual void vf19();
  virtual void vf20();
  virtual void vf21();    // vtable 0x5C
};

extern "C" void fn_8021915C(void *, unsigned int);

extern "C" void fn_80221E7C(void);
extern "C" void fn_80215270(void);
extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(void);
extern "C" char lbl_8055B750[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern u8 lbl_8033CAE8[];
extern "C" s32 fn_80214E10(s32);
extern "C" s32 fn_80214FE0(s32, s32, s32, s32);
extern "C" s32 fn_80206430(void);
extern "C" s32 fn_8022BAD0(s32, s32, s32, s32, float);
extern "C" s32 fn_8022AC1C(s32, s32, s32, s32, s32, s32, s32, s32);
extern float lbl_80563450;
extern "C" float fn_80209028(void);
extern "C" int lbl_8055EF5C;
extern "C" unsigned char lbl_80490558[];
extern "C" char *lbl_8055B6B0;

extern "C" s32 fn_80128668(void);
extern "C" s32 (*lbl_8055EF0C)(s32 *);
extern "C" s32 fn_802168BC(s32);
extern "C" void *fn_802115AC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_8021165C(void) {
    fn_80215270();
}

extern s32 lbl_8055EF1C;
extern s32 lbl_8055EF20;
s32 fn_80211660(s32 arg0) {
    if (arg0 == 0) {
        return lbl_8055EF1C;
    }
    return lbl_8055EF20;
}

s32 fn_80211678(u8 *arg0) {
    return ((s8) *arg0 - 0x24) == 0;
}

extern "C" int fn_80211690(int);
extern "C" int fn_80211D24(int);
extern "C" int fn_802E2C20(void);
extern "C" int fn_802ECC10(void);
extern "C" int lbl_8055EF14;
extern "C" float lbl_8055EF10;
extern "C" int lbl_8055EF40;
extern "C" float lbl_80563434;
extern "C" float lbl_80563440;
extern "C" float lbl_80563444;
extern "C" double lbl_80563448;
extern "C" void fn_80211F44(void) { fn_80211690(1); }

extern "C" void fn_80211F4C(void) { fn_80211D24(1); }

extern "C" int fn_80211F54(void) { return lbl_8055EF40 == 0; }

extern "C" void fn_80211F64(void) {
    float temp_f0;
    float var_f3;
    int temp_r31;
    temp_r31 = fn_802E2C20();
    if (fn_802ECC10() == 0) {
        var_f3 = lbl_80563444;
        temp_f0 = lbl_80563440 * (float)(temp_r31 - lbl_8055EF14);
        if (var_f3 < temp_f0) {
            var_f3 = var_f3;
        } else {
            var_f3 = temp_f0;
        }
        lbl_8055EF10 = var_f3;
    } else {
        lbl_8055EF10 = lbl_80563434;
    }
    lbl_8055EF14 = temp_r31;
}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_802121D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 (*lbl_8055EF0C)(s32 *);
extern "C" s32 fn_80212214(s32 arg0) {
    s32 value;
    memcpy(&value, &arg0, 4);
    return value;
}

extern "C" float fn_80212248(s32 arg0) {
    float value;
    memcpy(&value, &arg0, 4);
    return value;
}

extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(void);
extern "C" char lbl_8055B750[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" void *fn_8021227C(void *arg0, char *arg1, s32 arg2) {
    char buf[0x100];
    char *name = arg1;
    void *entry = arg0;
    if (*arg1 == '#') {
        name = arg1 + 1;
        sprintf(buf, lbl_8055B750, name);
    }
    for (;;) {
        s32 id = *(s32 *)((char *)entry + 4);
        if (id == 0x7B) return 0;
        if (id == arg2 && *(char **)entry != 0 &&
            (stricmp(*(char **)entry, name) == 0 ||
             stricmp(*(char **)entry, buf) == 0)) return entry;
        entry = (char *)entry + 0x14;
    }
}

extern "C" s32 fn_80212338(void) { return 0; }

extern "C" void fn_80212340(void *arg0) {
    s32 *p = (s32 *)arg0;
    if (p[4] != 0) {
        fn_8022E4BC(p[4]);
        p[4] = 0;
    }
    if (p[0] != 0) {
        if (fn_80211678() == 0) {
            fn_8022E4BC(p[3]);
        } else {
            fn_8022E960(p[3]);
        }
        p[3] = 0;
    }
}

extern "C" s32 fn_80214934(const void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 end = fn_80029004((const char *)arg1, 0x2e);
    if (end == 0) {
        end = (s32)((const char *)arg1 + strlen((const char *)arg1));
    }
    fn_801345D8(arg2, arg3, lbl_8055B808, (s32)arg0, end - arg1, (const char *)arg1);
    return 0;
}

extern "C" void fn_802149C4(s32 arg0) {
    char sp8[0x64];
    fn_80214934(lbl_8055B810, arg0, sp8, 0x64);
    fn_8021481C(sp8);
}

extern "C" s32 fn_80218C14(s32, s32);
extern "C" s32 fn_80214934(const void*, s32, void*, s32);
extern "C" s32 fn_8021481C(void*);
extern "C" char lbl_8033D388[];
extern "C" char lbl_8033D268[];
extern "C" char lbl_8055B810[];
extern "C" void fn_802149FC(s32 arg0) {
    char sp8[0x64];
    fn_80214934(lbl_8033D268, arg0, sp8, 0x64);
    fn_8021481C(sp8);
}

extern "C" void fn_802192AC(void);
extern "C" void fn_80219354(void);
extern "C" void fn_80214A9C(s32 arg0) {
    if (fn_802168E4() != 0) {
        fn_802168CC(arg0, lbl_80563434);
    } else {
        fn_802E317C(lbl_8033D2A0);
    }
}

extern "C" void fn_80214B44(s32 arg0) {
    if (fn_802168E4() != 0) {
        fn_802168DC(arg0);
    } else {
        fn_802E317C(lbl_8033D2E0);
    }
}

extern "C" void fn_80214C54(s32 arg0, s32 arg1) {
    if (fn_802168E4() != 0) {
        fn_80218C14(arg0, arg1);
    } else {
        fn_802E317C(lbl_8033D388);
    }
}

extern "C" s32 lbl_80490528[];
extern "C" s32 fn_802168E4(void);
extern "C" s32 fn_80218120(void);
extern "C" s32 fn_802E317C(const char *);
extern "C" char lbl_8033D3D4[];
extern "C" s32 fn_80214D04(void) {
    if (fn_802168E4() != 0) {
        return fn_80218120();
    }
    fn_802E317C(lbl_8033D3D4);
    return 0;
}

extern "C" f32 fn_80214D48(void) {
    return lbl_8055EF10;
}

extern "C" void fn_80214D50(s32 arg0) {
    s32 index;
    s32 offset;
    void *obj;
    float value;
    if (fn_80206430() == 0) return;
    index = lbl_8055EF5C + 1;
    lbl_8055EF5C = index;
    if (index >= 4) { index = 0; lbl_8055EF5C = 0; }
    offset = arg0 * 0x18;
    obj = *(void **)(lbl_80490558 + offset + index * 4 + 8);
    if (obj != 0) {
        value = *(float *)(lbl_80490558 + offset + 4) * fn_80209028();
        if (value != *(float *)((char *)obj + 8)) {
            *((u8 *)obj + 0x4D) = 1;
            *(float *)((char *)obj + 8) = value;
            *((u8 *)obj + 0x49) = 1;
            *((u8 *)obj + 0x4B) = 0;
            *((u8 *)obj + 0x4A) = 0;
        }
    }
}

extern "C" void fn_80214FD8(s32 arg0, s32 arg1) {
    ((s32 (*)(s32, s32, s32))fn_80214E10)(arg0, arg1, 0);
}

extern "C" s32 fn_80215194(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_802151D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_80214FE0(s32, s32, s32, s32);
extern "C" void fn_80215214(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_80214FE0(arg0, arg1, arg2, 1);
}

extern "C" void fn_8021521C(s32 arg0, s32 arg1, s32 arg2) { fn_80214FE0(arg0, arg1, 0, arg2); }

extern "C" void fn_80215228(void) { stricmp((const char *)lbl_8033CAE8, lbl_8055B6B0); }

extern void *lbl_8055EF38;
extern "C" void* fn_8021525C(void) {
    return lbl_8055EF38;
}

extern u8 lbl_8033CAE8[];
extern "C" void *fn_80215264(void) {
    return lbl_8033CAE8;
}

extern "C" void fn_80215298(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5, u32 arg6) {
    *arg0 = arg4;
    *arg2 = arg4 + arg6 - 0x1A;
    *arg1 = arg4 + (s32)(((arg6 >> 31) + arg6) >> 1);
    *arg3 = arg5 + 4;
}

#pragma dont_inline on
void fn_802152C8(void) {
}
#pragma dont_inline reset

extern "C" s32 fn_802192A4(void *, s32);
#pragma dont_inline on
extern "C" void fn_802152C8(void);
#pragma dont_inline reset
extern "C" s32 fn_802152CC(void) {
    fn_802152C8();
    return 0;
}
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802152F0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" s32 __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80215348(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            ((s32 (*)(void *))fn_80128668)(arg0);
        }
    }
    return (s32)arg0;
}

void fn_802153A0(void) {
}

extern "C" s32 fn_802168BC(s32);
extern "C" void fn_8021915C(void *, unsigned int);
extern "C" s32 fn_802153A4(void) {
    return 0;
}

extern "C" s32 fn_802153AC(void *arg0, u32 arg1) {
    s32 (*callback)(s32);
    if (arg1 == *(u16 *)((char *)arg0 + 0x244)) {
        callback = *(s32 (**)(s32))((char *)arg0 + 0x248);
        if (callback == 0 || callback(*(s32 *)((char *)arg0 + 0x24C)) != 0) {
            fn_802168BC(*(s32 *)((char *)arg0 + 0x24C));
        }
        return 1;
    }
    return 0;
}

extern "C" void fn_80215414(void) {

}

extern "C" void fn_80215418(void) {

}

extern "C" void fn_8021541C(void) {

}

extern "C" void fn_80215420(void) {

}

extern "C" void fn_80215424(void) {

}

extern "C" void fn_80215428(void *arg0) {
    *(u8 *)((char *)arg0 + 0x19) = 1;
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80215444(void *arg0) {
    *(u8 *)((char *)arg0 + 0x19) = 0;
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80215464(void) {

}

extern "C" void fn_80215468(void) {

}

extern "C" void fn_8021546C(void) {

}

extern "C" void fn_80215470(void) {

}

extern "C" void fn_80215474(void) {

}

extern "C" void fn_80215478(void* arg0) {
    *(u8*)((char*)arg0 + 0x18) = 1;
}

extern "C" void fn_80215484(void* arg0) {
    *(u8*)((char*)arg0 + 0x18) = 0;
}

extern "C" s32 fn_80215490(void) {
    return 0;
}

extern "C" s32 fn_80215498(void) {
    return 0;
}

extern "C" void fn_802154A0(void *arg0) {
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" u32 fn_802154B8(void) { return 1; }

extern "C" s32 fn_802154C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_80215500(void) {

}

extern "C" void fn_80215504(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    fn_8022BAD0(*(s32 *)((char *)arg0 + 8), 0, *(s32 *)((char *)arg0 + 4), arg6, lbl_80563450);
}

extern "C" void fn_80215544(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    fn_8022AC1C(*(s32 *)((char *)arg0 + 8), *(s32 *)((char *)arg0 + 4), arg1, arg2, arg3, arg4, arg5, arg6);
}

extern "C" s32 fn_802155AC(void) {
    return 4;
}

extern "C" void fn_802C4C80(void*);
extern "C" int lbl_8033D528[];
extern "C" void* __dt__14CollisionSpaceFv_802155B4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033D528;
        fn_802C4C80(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_80029004(const char *, s32);
extern "C" s32 fn_801345D8(void *, s32, const char *, s32, s32, const char *);
extern "C" unsigned long strlen(const char *);
extern "C" char lbl_8055B808[];
extern "C" s32 fn_802C4F14(s32);
extern "C" s32 fn_802C4C90(s32, s32, s32, s32, s32);
extern "C" void fn_80215618(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 rem = arg3 % fn_802C4F14(*(s32 *)((char *)arg0 + 4));
    fn_802C4C90(*(s32 *)((char *)arg0 + 4), arg1, arg2, rem, 0);
}

extern "C" s32 fn_80215730(void *arg0) {
    return fn_802C4F14(*(s32*)((u8*)arg0 + 4));
}

  void fn_802C2FC4(int);
  s32 fn_80128668(void *);
void fn_802C40E8(int, int, int);
void fn_802C4F2C(int, int *, int *);
int fn_802C4EE4(int);
int fn_802C4EFC(int);
extern int lbl_8033D504;
void *fn_80215738(void *arg0, int arg1) {
    int temp_r0;
    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = (void *)&lbl_8033D504;
        if (temp_r0 != 0) fn_802C2FC4(temp_r0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802157A8(int arg0, int arg1, int arg2, unsigned int arg3) {
    unsigned int r7 = *(unsigned int *)(arg0 + 0xC);
    int r8 = *(int *)(arg0 + 4);
    unsigned int rem = arg3 - (arg3 / r7) * r7;
    if (r8 != 0) fn_802C40E8(r8, arg1, arg2 - *(int *)(arg0 + 8) * rem);
}

void fn_802157DC(void *arg0, int arg1, int arg2, int *arg3, int *arg4, int *arg5, int *arg6) {
    int var_r0;
    int *temp = *(int **)((char *)arg0 + 4);
    *arg3 = arg1;
    *arg4 = arg2;
    var_r0 = temp != 0 ? temp[2] : 0;
    *arg5 = *arg3 + var_r0;
    *arg6 = *arg4 + *(int *)((char *)arg0 + 8);
}

extern "C" s32 fn_8021581C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" void fn_80215824(void) {

}

extern "C" void fn_80215828(void *arg0) {
    void (*fn)(void) = *(void (**)(void))(*(char **)arg0 + 0x10);
    fn();
}

extern "C" s32 fn_8021583C(void *arg0, s32 arg1, s32 arg2) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 result;
    ((void (*)(s32 *, s32 *, s32 *, s32 *))(*(void ***)arg0)[5])(&sp14, &sp10, &spC, &sp8);
    result = 0;
    if (arg1 >= sp14 && arg1 < spC && arg2 >= sp10 && arg2 < sp8) {
        result = 1;
    }
    return result;
}

extern "C" void fn_802158C8(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf18();
}

extern "C" void fn_802158DC(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf19();
}

extern "C" void fn_802158F0(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf20();
}

extern "C" void fn_80215904(void *arg0) {
    fn_802192AC();
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf5();
}

extern "C" void fn_80215944(void *arg0) {
    fn_80219354();
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf6();
}

extern "C" void fn_80215984(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf10();
}

extern "C" void fn_80215998(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf11();
}

extern "C" void fn_802159AC(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf13();
}

extern "C" void fn_802159C0(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf14();
}

extern "C" void fn_802159D4(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf19();
}

extern "C" void fn_802159E8(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf4();
}

extern "C" void fn_802159FC(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf12();
}

extern "C" void fn_80215A10(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 1;
    void *obj = *(void **)((u8 *)arg0 + 0x244);
    void **vt = *(void ***)obj;
    ((void (*)(void *))*(void **)((u8 *)vt + 0x44))(obj);
}

extern "C" void fn_80215A2C(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    void *obj = *(void **)((u8 *)arg0 + 0x244);
    void **vt = *(void ***)obj;
    ((void (*)(void *))*(void **)((u8 *)vt + 0x48))(obj);
}

extern "C" void fn_80215A48(void *arg0) {
    u8 value = *((u8 *)arg0 + 0x1A);
    *((u8 *)arg0 + 0x19) = 1;
    if (value != 0) *((u8 *)arg0 + 0x234) = 1;
    void *obj = *(void **)((u8 *)arg0 + 0x244);
    void **vt = *(void ***)obj;
    ((void (*)(void *))*(void **)((u8 *)vt + 0x4C))(obj);
}

#pragma dont_inline on
#pragma dont_inline reset
extern "C" void fn_80215A74(void *arg0) {
    u8 *self = (u8 *)arg0;
    u8 enabled = self[0x1A];
    self[0x19] = 0;
    if (enabled == 0) goto done;
    self[0x234] = 1;
    {
        void *obj = *(void **)(self + 0x244);
        ((void (*)(void *))(*(void ***)obj)[20])(obj);
    }
done:
    return;
}
extern "C" s32 fn_80215AA4(void *arg0, s32 arg1) {
    void *obj = *(void **)((u8 *)arg0 + 0x244);
    s32 (**vtable)(void *) = *(s32 (***)(void *))obj;
    if (vtable[22](obj) != 0) return 1;
    return fn_802192A4(arg0, arg1);
}

extern "C" void fn_80215B08(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf21();
}

extern "C" void fn_80215B1C(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf7();
}

extern "C" void fn_80215B30(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf8();
}

extern "C" void fn_80215B44(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf9();
}

extern "C" void fn_802191F0(void);
extern "C" void fn_80215B58(void *arg0, s32 arg1, s32 arg2) {
    fn_802191F0();
    ((void **)*(void ***)((char *)arg0 + 0x244))[1] = (void *)arg1;
    ((void **)*(void ***)((char *)arg0 + 0x244))[2] = (void *)arg2;
}

extern "C" s32 fn_80215BAC(void) {
    return -1;
}

extern "C" void fn_80215BB4(void) {

}

extern "C" void fn_80215BB8(void) {

}

extern "C" void fn_80215BBC(void) {

}

extern "C" s32 fn_80215BC0(void) {
    return 0;
}

extern "C" s32 fn_80214CB4(s32);
extern "C" void fn_80230E90(s32);
extern "C" s32 fn_80215BC8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r6;

    var_r6 = 0;
    if (arg1 >= *(s32 *)((char *)arg0 + 4) && arg1 < *(s32 *)((char *)arg0 + 0xC) &&
        arg2 >= *(s32 *)((char *)arg0 + 8) && arg2 < *(s32 *)((char *)arg0 + 0x10)) {
        var_r6 = 1;
    }
    return var_r6;
}

extern "C" s32 fn_80215C08(void *arg0) {
    return *(s32 *)((char *)arg0 + 0xC) - *(s32 *)((char *)arg0 + 4);
}

extern "C" void fn_80215C18(void *arg0) {
    fn_80214CB4(*(u8 *)((char *)arg0 + 0x18) == 0);
}

extern "C" s32 fn_80215C28(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 0x125:
        fn_80214CB4(0);
        fn_80230E90(0);
        return 1;
    case 0x127:
        fn_80214CB4(1);
        fn_80230E90(0);
        return 1;
    case 0x126:
    case 0x128:
        return 1;
    default:
        return 0;
    }
}

extern "C" void fn_80215CA0(void) {

}

extern "C" void fn_80215CA4(void) {

}

extern "C" void fn_80215CA8(void) {
	fn_80221E7C();
}

extern "C" void fn_80215CAC(void) {

}

extern "C" void fn_80215CB0(void) {

}

extern "C" void fn_80215CB4(void) {

}

extern "C" void fn_80215CB8(void) {

}

extern "C" void fn_80215CBC(void) {

}

extern "C" void fn_80215CC0(void) {

}

extern "C" void fn_80215CC8(void) {

}

extern "C" void fn_80215CCC(void) {

}

extern "C" void fn_80215CD0(void) {

}

extern "C" void fn_80215CD4(void) {

}

extern "C" void fn_80215CD8(void) {

}

extern "C" void fn_80215CDC(void) {

}

extern "C" void fn_80215CE0(void) {

}

extern "C" s32 fn_80215CE4(void) {
    return 0;
}

extern "C" s32 fn_80215CEC(void) {
    return 0;
}

extern "C" void fn_80215CC4(void) {

}

