// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

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
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();    // vtable 0x5C
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
extern "C" float fn_80209028(void);
extern "C" int lbl_8055EF5C;
extern "C" unsigned char lbl_80490558[];
extern "C" char *lbl_8055B6B0;

extern "C" void fn_8021165C(void) {
    fn_80215270();
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

void fn_802152C8(void) {
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

extern "C" u32 fn_802154B8(void) { return 1; }

extern "C" s32 fn_802154C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_80215500(void) {

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

extern "C" s32 fn_8021581C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" void fn_80215824(void) {

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

