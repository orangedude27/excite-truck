// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void fn_80221E7C(void);
extern "C" void fn_80215270(void);
extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(void);
extern "C" char lbl_8055B750[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);

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
        if (id == 0x7B) {
            return 0;
        }
        if (id == arg2 && *(char **)entry != 0) {
            if (stricmp(*(char **)entry, name) == 0 ||
                stricmp(*(char **)entry, buf) == 0) {
                return entry;
            }
        }
        entry = (char *)entry + 0x14;
    }
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

void fn_802153A0(void) {
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

extern "C" s32 fn_80215BAC(void) {
    return -1;
}

extern "C" void fn_80215BB4(void) {

}

extern "C" void fn_80215BB8(void) {

}

extern "C" void fn_80215BBC(void) {

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

extern "C" void fn_80215CC4(void) {

}

