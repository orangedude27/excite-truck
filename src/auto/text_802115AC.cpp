// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void fn_80221E7C(void);
extern "C" void fn_80215270(void);

extern "C" void fn_8021165C(void) {
    fn_80215270();
}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_802121D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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

