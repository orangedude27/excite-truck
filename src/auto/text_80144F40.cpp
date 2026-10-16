#include <types.h>

extern "C" f32 lbl_805615D0;
extern "C" s32 fn_801450A0(u32, u32, f32);
extern "C" void fn_80147DC0(void *, s32, s32);
extern "C" void fn_801476D8(void *, s32, s32);
extern "C" s32 fn_80147C50(u32, u32, f32);

extern "C" void *lbl_8032D1E8;
extern "C" void *fn_80148294(const char *, void *);
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
extern "C" int stricmp(const char *, const char *);
extern "C" void fn_80148334(s32, s32, void *);
extern "C" void fn_801483D4(s32, s32, void *);
extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32);
extern "C" f32 fn_801452B4(f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148DFC(void *);
extern "C" void fn_80148E6C(void *);
extern "C" void fn_80148EDC(void *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" f32 lbl_805615F0;
extern "C" f32 fn_801452D4(f32 arg0) { return lbl_805615F0 - arg0; }

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

extern "C" f32 fn_800108C8(const char *, f32);
extern "C" void fn_80235380();
extern "C" void fn_80145B94(void *, u32);
extern "C" void fn_80146BD4(u8 *arg0, const s8 *arg1, s32 arg2) {
    s32 count = arg2;
    if (count > 0) {
        do {
            count--;
        } while (count > 0);
        *arg0 = 0;
    }
    while ((s8)*arg1 != 0) {
        *arg0++ = (u8)*arg1++;
    }
}

extern "C" void *lbl_8032D214;
extern "C" void fn_8002F6AC(s32, void *);
extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *, s32);
extern "C" s32 fn_80147070(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern "C" void fn_80147204(void *arg0, const char *arg1) {
    if (arg0 != 0) {
        if ((u8)*arg1 == 1)
            arg1++;
        fn_800108C8(arg1, *(f32 *)((u8 *)arg0 + 0x10));
        return;
    }
    return;
}

extern "C" void fn_801476C4(void *arg0) {
    if (arg0 != 0)
        fn_80145B94(arg0, *(u32 *)((u8 *)arg0 + 0x1c));
}

extern "C" void fn_80147BD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    u32 tmp;
    fn_80147DC0(&tmp, arg0, arg1);
    fn_801476D8(&tmp, fn_80147C50(arg2, arg3, arg5), arg4);
}

extern "C" s32 fn_80147C50(u32 arg0, u32 arg1, f32 arg2) {
    s32 a = fn_801450A0(arg0 & 0xFF, arg1 & 0xFF, arg2);
    s32 b = fn_801450A0((arg0 >> 8) & 0xFF, (arg1 >> 8) & 0xFF, arg2);
    s32 c = fn_801450A0((arg0 >> 16) & 0xFF, (arg1 >> 16) & 0xFF, arg2);
    s32 d = fn_801450A0(arg0 >> 24, arg1 >> 24, arg2);
    return (a & 0xFF) | ((b & 0xFF) << 8) | ((c & 0xFF) << 16) | ((d & 0xFF) << 24);
}

extern "C" void fn_80147EE0(void *arg0, f32 scale) {
    f32 x = *(f32 *)((u8 *)arg0 + 0x10);
    f32 decay = lbl_805615D0;
    f32 y = *(f32 *)((u8 *)arg0 + 0x14);
    f32 dx = x * scale;
    f32 gx = x * decay;
    f32 xpos = *(f32 *)((u8 *)arg0 + 4);
    f32 dy = y * scale;
    f32 gy = y * decay;
    f32 ypos = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 0x14) = dy;
    xpos = xpos + gx;
    scale = dx * decay;
    *(f32 *)((u8 *)arg0 + 0x10) = dx;
    ypos = ypos + gy;
    decay = dy * decay;
    *(f32 *)((u8 *)arg0 + 4) = xpos - scale;
    *(f32 *)((u8 *)arg0 + 8) = ypos - decay;
}

extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32);
extern "C" f32 fn_801452B4(f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148100(void *arg0) {
    fn_801470B0(*(s32 *)((u8 *)arg0 + 0x18), -1,
        *(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 4),
        *(f32 *)((u8 *)arg0 + 8), *(f32 *)((u8 *)arg0 + 0x10),
        *(f32 *)((u8 *)arg0 + 0x14), lbl_805615D4, lbl_805615D4,
        lbl_805615D4, lbl_805615D4);
}

extern "C" void fn_80148134(f32 *arg0, f32 *arg1, s32 arg2, f32 farg1) {
    if (arg0 != NULL) *arg0 = fn_801451DC(arg2);
    if (arg1 != NULL) *arg1 = fn_801452B4(farg1);
}

extern "C" void fn_8014819C(void *arg0, f32 farg0, f32 farg1) {
    *(f32 *)arg0 = lbl_8055E200;
    *(f32 *)((u8 *)arg0 + 4) = lbl_8055E204;
    lbl_8055E200 += farg0;
    lbl_8055E204 += farg1;
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
    struct VTable {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    VTable *obj = *(VTable **)((u8 *)arg0 + 4);
    obj->f8();
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

extern "C" void fn_80148284(void *arg0, s32 arg1) {
    fn_80148294((const char *)arg1, *(void **)((u8 *)arg0 + 0x30));
}

extern "C" void *fn_80148294(const char *arg0, void *arg1) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), arg0) == 0) {
            return (void *)(*(u32 *)arg1 + i * 0x20);
        }
        offset += 0x20;
        i++;
    }
    return NULL;
}

extern "C" void fn_80148334(s32, s32, void *);
extern "C" void fn_80148324(void *arg0, s32 arg1) {
    fn_80148334(arg1, *(s32 *)((u8 *)arg0 + 0x2C), arg0);
}

extern "C" void fn_80148334(s32 arg0, s32 arg1, void *arg2) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), (const char *)arg0) == 0) {
            return;
        }
        offset += 0x28;
        i++;
    }
}

extern "C" void fn_801483C4(void *arg0, s32 arg1) {
    fn_801483D4(arg1, *(s32 *)((u8 *)arg0 + 0x34), arg0);
}

extern "C" void fn_801483D4(s32 arg0, s32 arg1, void *arg2) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), (const char *)arg0) == 0) {
            return;
        }
        offset += 0x1C;
        i++;
    }
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

extern "C" void deleteThreads__6SystemFv(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        ((void (*)(void *, s32))((void **)*(void **)p)[2])(p, 1);
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

