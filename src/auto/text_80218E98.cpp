// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

class TruckIface {
public:
    virtual ~TruckIface();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

extern "C" void fn_8023976C(s32);
extern "C" void fn_80218F80(void);
extern "C" void fn_8023986C(s32);
extern "C" void fn_8023967C(s32, s32);
extern "C" void fn_8021915C(void *, u32);
extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_801284F8(s32, const char *);
extern "C" s32 fn_8023964C(void);
extern "C" void fn_80239784(s32, void *);
extern char lbl_8033DDA4[];
extern char lbl_8033DE28[];
extern char lbl_8033DCDC[];


extern "C" void fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern "C" s32 fn_8012850C(void *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern "C" char *strcpy(char *, const char *);
extern "C" void fn_80219568(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80219718(void *);
extern "C" void fn_80219440(void *, s32, void *, s32);
extern f32 lbl_805634A4;
extern char lbl_8033D878[];
extern char lbl_8033F768[];

extern "C" void fn_80219044(void);
extern "C" void fn_8021AC24(void);
extern "C" void fn_802C519C(void *);
extern "C" void fn_8021915C(void *, u32);
extern "C" s32 fn_80128668(void *);
extern "C" void *lbl_8033EDC8[];
extern "C" void *lbl_8033ED44[];

extern f32 lbl_805634A0;
extern f32 lbl_805634A4;
extern f32 lbl_805634B0;
extern f32 lbl_805634B4;

extern "C" void fn_802191F0(void *arg0, s32 arg1, s32 arg2) {
    void *obj = arg0;
    void **vt = *(void ***)obj;
    s32 size = ((s32 (*)(void *))vt[30])(obj);
    s32 x = arg1 + size;
    s32 end = arg2 + (*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = x;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = end;
}

extern "C" void fn_80219264(void *arg0, s32 arg1, s32 arg2) {
    void **vtable = *(void ***)arg0;
    ((void (*)(void *, s32, s32))vtable[7])(arg0,
        *(s32 *)((u8 *)arg0 + 4) + arg1,
        *(s32 *)((u8 *)arg0 + 8) + arg2);
}

extern "C" void fn_80219284(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)arg0 + 4) + arg1;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) + arg2;
}

void fn_802192A0(void) {

}

extern "C" s32 fn_802192A4(void) { return 0; }

extern "C" void fn_80219354(void) { fn_80219044(); }

extern "C" void fn_80219044();
extern f32 lbl_805634A0;
extern f32 lbl_805634A4;
extern f32 lbl_805634B0;
extern f32 lbl_805634B4;
extern "C" void fn_80219358(void *arg0, f32 value) {
    if (value >= lbl_805634B0) {
        if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
            return;
        *(u8 *)((u8 *)arg0 + 0x1A) = 1;
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
        return;
    }
    if (*(u8 *)((u8 *)arg0 + 0x1A) == 0) {
        if (*(f32 *)((u8 *)arg0 + 0x20) < lbl_805634B4) {
            *(f32 *)((u8 *)arg0 + 0x20) = lbl_805634A4;
            if (value > lbl_805634B0)
                *(f32 *)((u8 *)arg0 + 0x28) = lbl_805634A4 / value;
        }
    }
    *(f32 *)((u8 *)arg0 + 0x1C) = lbl_805634A0;
}

extern "C" void fn_80219440(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 idx;
    s32 value = fn_8012850C((void *)arg3, lbl_8033D878);
    idx = *(s32 *)((u8 *)arg0 + 0x230);
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x34) = arg1;
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x30) = (s32)arg2;
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x38) = arg3;
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x3C) = value;
    memcpy((void *)value, arg2, (unsigned long)arg3);
    *(s32 *)((u8 *)arg0 + 0x230) = *(s32 *)((u8 *)arg0 + 0x230) + 1;
}

extern void fn_802179A0(s32);
extern void fn_80218198(s32, s32);
extern "C" void fn_802194F4(void* arg0) {
    fn_802179A0(*(s32*)((u8*)arg0 + 0x2C));
}

extern "C" void fn_802194FC(void* arg0) {
    fn_80218198(*(s32*)((u8*)arg0 + 0x2C), 0);
}

extern void fn_80217AC0(s32);
extern "C" void fn_80219508(void* arg0) {
    fn_80217AC0(*(s32*)((u8*)arg0 + 0x2C));
}

extern "C" void fn_80219510(void* arg0, s32 arg1, s32 arg2) {
    s32 v244 = -arg1;
    *(s32*)((u8*)arg0 + 0x244) = v244;
    *(u8*)((u8*)arg0 + 0x24C) = 1;
    *(s32*)((u8*)arg0 + 0x248) = -arg2;
}

extern "C" void fn_8021952C(void* arg0, s32 arg1, s32 arg2) {
    void* r7 = *(void**)((u8*)arg0 + 0x2C);
    if (*(u8*)((u8*)arg0 + 0x24C) != 0) {
        s32 dx = *(s32*)((u8*)arg0 + 0x244) + arg1;
        *(s32*)((u8*)r7 + 0x454) += dx;
        s32 dy = *(s32*)((u8*)arg0 + 0x248) + arg2;
        *(s32*)((u8*)r7 + 0x458) += dy;
    }
}

extern "C" s32 fn_80219658(void) { return 0; }

extern "C" void fn_80219660(void *arg0, s32 unused) {
    void **vt = *(void ***)arg0;
    s32 a = *(s32 *)((u8 *)arg0 + 8);
    s32 b = *(s32 *)((u8 *)arg0 + 4);
    s32 c = *(s32 *)((u8 *)arg0 + 0x10) - a;
    s32 x = ((s32 (*)(void *))vt[33])(arg0);
    s32 y = ((s32 (*)(void *))vt[34])(arg0);
    s32 z = ((s32 (*)(void *))vt[30])(arg0);
    fn_8022BAD0(*(s32 *)((u8 *)arg0 + 0x250),
                 *(s32 *)((u8 *)arg0 + 0x244) + b,
                 *(s32 *)((u8 *)arg0 + 0x248) + a,
                 *(s32 *)((u8 *)arg0 + 0x24C), z, c, y, x, lbl_805634A4);
}

extern "C" void fn_80219870(void *arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    fn_80219568(arg0, arg1, arg2, 0, arg7, 0, 0, 0);
    *(void **)arg0 = lbl_8033F768;
    strcpy((char *)arg0 + 0x258, arg3);
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    fn_80219440(arg0, 0, (void *)arg4, 1);
    fn_80219718(arg0);
}

extern "C" void fn_8021915C(void*, u32);
extern "C" s32 fn_80128668(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8021B404(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8021C974(void) { return 0; }

extern "C" void *fn_8021C97C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    fn_8021AC24();
    *(s32 *)((u8 *)arg0 + 0x258) = arg4;
    *(u32 *)arg0 = (u32)lbl_8033EDC8;
    *(s32 *)((u8 *)arg0 + 0x254) = arg5;
    return arg0;
}

extern "C" void fn_8021C9D8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x258) > 0)
        ((void (**)(void *))(*(void ***)((u8 *)arg0 + 0x254)))[5](*(void **)((u8 *)arg0 + 0x254));
    else
        ((void (**)(void *))(*(void ***)((u8 *)arg0 + 0x254)))[6](*(void **)((u8 *)arg0 + 0x254));
}

extern "C" void fn_8021AC24(void);
extern "C" void fn_802C519C(void *);
extern "C" void fn_8021915C(void *, u32);
extern "C" s32 fn_80128668(void *);
extern "C" void *fn_8021CAD4(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033ED44;
        fn_802C519C(*(void **)((u8 *)arg0 + 0x24C));
        fn_802C519C(*(void **)((u8 *)arg0 + 0x250));
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_80221E7C(void *arg0) {
    void *temp = *(void **)((u8 *)arg0 + 0x14);
    if (temp != 0 && *(u8 *)((u8 *)temp + 0x1A) != 0)
        *(u8 *)((u8 *)temp + 0x234) = 1;
}

extern "C" void fn_80221EA0(void *arg0) {
    fn_80219440(*(void **)((u8 *)arg0 + 0x14), 0, 0, 0);
}

extern "C" void fn_80222120(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x248) = 1;
    ((void (**)(void *))(*(void ***)arg0))[19](arg0);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_802328D4(void*);
extern "C" int lbl_8033F9E0[];
extern "C" void* __dt__14CollisionSpaceFv_80222584(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033F9E0;
        fn_802328D4(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" u32 fn_80223AAC(void) { return 1; }

extern "C" void *fn_80228418(void *p,void *q,s32 a){s32 r;fn_80218F80();*(s32*)((u8*)p+0x244)=0;*(void**)p=lbl_8033DE28;*(u8*)((u8*)p+0x248)=0;if(a){*(s32*)((u8*)p+0x244)=a;}else{const char *name=lbl_8033DCDC;r=fn_801284F8(0x18,name);if(r)r=fn_8023964C();*(s32*)((u8*)p+0x244)=r;*(u8*)((u8*)p+0x248)=1;}fn_80239784(*(s32*)((u8*)p+0x244),(u8*)q+0x40);return p;}

extern "C" void *fn_802284BC(void *p,s32 a){if(p){*(void**)p=lbl_8033DE28;fn_8023986C(*(s32*)((u8*)p+0x244));if(*(u8*)((u8*)p+0x248))fn_8023967C(*(s32*)((u8*)p+0x244),1);*(s32*)((u8*)p+0x244)=0;fn_8021915C(p,0);if(a>0)fn_80128668(p);}return p;}

extern "C" void fn_8022854C(void *p){fn_8023976C(*(s32*)((u8*)p+0x244));}

extern "C" void fn_802396BC(s32);
extern "C" void fn_80228554(void *p){fn_802396BC(*(s32*)((u8*)p+0x244));}

extern "C" void *fn_8022855C(void *p,s32 unused,s32 a,s32 b){fn_80218F80();*(s32*)((u8*)p+0x244)=a;*(void**)p=lbl_8033DDA4;*(s32*)((u8*)p+0x248)=b;return p;}

extern "C" s32 fn_80228DA4(void) { return 0; }

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229054(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229168(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802291C4(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229220(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022927C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802293E0(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022943C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229498(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802294F4(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" u32 fn_80229614(void) { return 1; }

extern "C" u32 fn_80229620(void) { return 1; }

extern "C" void fn_8022984C(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x254);
    *p = (u8)((s8)(*p == 0));
}

extern "C" void fn_80229864(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_80229884(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" s32 fn_802298A4(s32 arg0) {
    return arg0 + 0x258;
}

extern "C" u32 fn_80229ADC(void) { return 1; }

extern "C" s32 fn_80229C9C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" s32 fn_80229CA4(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" s32 fn_80229CAC(s32);
extern "C" s32 fn_80229CAC(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" void fn_80229CB4(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 1;
    (*(f32 *)((u8 *)arg0 + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" void fn_80229CD8(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 0;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" s32 fn_80229D5C(s32);
extern "C" s32 fn_80229D5C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229D64(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" u32 fn_80229EC4(void) { return 1; }

extern "C" u32 fn_80229ECC(void) { return 1; }

extern "C" void fn_80229ED4(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_80229EF4(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" s32 fn_80229F58(s32);
extern "C" s32 fn_80229F58(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" void fn_8022A014(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_8022A034(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" s32 fn_80229CA4(s32);
extern "C" s32 fn_80229C9C(s32);
extern "C" void fn_80229CB4(void *);
extern "C" void fn_80229CD8(void *);
extern void fn_80219044(void *);
