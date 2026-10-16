#include <types.h>

extern "C" void *lbl_8032D1E8;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_801460F4(void) {
}

extern "C" void fn_80146200(void) {

}

extern "C" void fn_8014630C(void) {
}

extern "C" void fn_8014647C(void *);
extern "C" void fn_8014647C(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

extern "C" void *fn_80146490(void *arg0) {
    void *p = arg0;
    if (p != NULL) {
        if (((s32 *)p)[0x28 / 4] == 0) {
            if (p != NULL) {
                void *fn = *(void **)p;
                ((void * (*)(void *, s32))((void **)fn)[2])(p, 1);
            }
            return NULL;
        }
    }
    return p;
}

extern "C" void fn_80128668(void *);
extern "C" void fn_80146584(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80128670(s32);
extern "C" void fn_80131818(void);
extern "C" void fn_80145DD8(void *);
extern "C" void fn_80146584(void *);
extern "C" void fn_801465C8(void *);
extern "C" void fn_80146638(void *);
extern "C" void fn_801466B4(void *);
extern "C" void fn_80146730(void *);
extern "C" void fn_801467AC(void *);
extern "C" void *lbl_8032D1E8;
extern "C" void fn_801465C8(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80146638(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            s32 x = ((s32 *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_801466B4(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            s32 x = ((s32 *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80146730(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            s32 x = ((s32 *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void *fn_80148294(const char *, void *);
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
extern "C" void *fn_801481C8(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        lbl_8055E200 = *(f32 *)arg0;
        lbl_8055E204 = *(f32 *)((u8 *)arg0 + 4);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80148218(void) {
}

extern "C" s32 fn_8014821C(void) {
    return 0;
}

extern "C" void fn_80148224(void) {
}

extern "C" void fn_80148228(void) {
}

extern "C" void fn_80148244(void) {
}

extern "C" s32 fn_80148248(void) {
    return 0;
}

extern "C" void fn_80148250(void *arg0) {
    (*(void (**)(void))(*(u8 **)(*(u32 *)((u8 *)arg0 + 4)) + 0x28))();
}

extern "C" u32 lbl_80559E68;
extern "C" u32 *fn_80148264(void) {
    return &lbl_80559E68;
}

extern "C" s32 DVDGetCurrentDiskID(void) {
    return 0x40000000;
}

extern "C" s32 fn_80148274(void) {
    return 0xC0C0C0C0;
}

extern "C" void fn_80148280(void) {

}

extern "C" void *fn_801484A4(const char *, void *);
extern "C" s32 fn_80148464(void *arg0, const char *arg1) {
    void *entry = fn_801484A4(arg1, *(void **)((u8 *)arg0 + 0x3C));
    if (entry != NULL) return *(s32 *)((u8 *)entry + 8);
    return 0;
}

extern "C" int stricmp(const char *, const char *);
extern "C" void *fn_801484A4(const char *arg0, void *arg1) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), arg0) == 0) {
            return (void *)(*(u32 *)arg1 + i * 0xC);
        }
        offset += 0xC;
        i++;
    }
    return NULL;
}

extern "C" void fn_80148610(void *arg0) { ((u8 *)arg0)[4] = (u8)(!((u8 *)arg0)[4]); }

extern "C" u8 fn_80148624(void *arg0) { return ((u8 *)arg0)[4]; }

extern "C" void fn_80148DFC(void *);
extern "C" void fn_80148DFC(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80148E6C(void *);
extern "C" void fn_80148E6C(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80148EDC(void *);
extern "C" void fn_80148EDC(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_8014822C(void) {

}

extern "C" s32 fn_80148230(void) {
    return -1;
}

extern "C" s32 fn_80148238(void) {
    return 0xFF808080;
}

