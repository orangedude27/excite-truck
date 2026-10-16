// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <revolution/OS/OSMessage.h>

/* forward decls for helpers defined further down in this file */
extern "C" s32 fn_80128668(void *);
extern "C" void fn_800FDE60(void);
extern "C" void fn_800FE1D0(void);
extern u8 lbl_8055DE80;
#pragma push
#pragma small_data off
extern u8 lbl_8041B138[];
#pragma pop

extern u32 lbl_80559900;

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern double __ieee754_pow(double, double);
extern "C" double fn_8002EFBC(double, double);

#pragma push
#pragma small_data off
extern u8 lbl_80327010[];
extern u8 lbl_80327020[];
extern f32 lbl_805610C8; // 1.0
extern f32 lbl_805610CC; // 2.0
extern f32 lbl_805610D0; // 0.5
extern f32 lbl_805610E4; // 256.0
extern f32 lbl_805610E8; // 0.0
extern double lbl_805610F0; // 32000.0
extern double lbl_805610F8; // 2.0
extern double lbl_80561100; // 10.0
extern double lbl_80561108; // 1.0
extern f32 lbl_802F6124[]; // pan table
#pragma pop

extern "C" void fn_8002F634(void*, void*, s32, s32);
extern "C" s32 ExecuteSingle__Q46nw4hbm3snd6detail11TaskManagerFv(void*);
extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void Stop__Q36nw4hbm3snd10WavePlayerFv(void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, u32);

#pragma push
#pragma small_data off
extern u8 lbl_80327334[];
extern u8 lbl_802F5210[];
#pragma pop

extern f32 lbl_805610D4; // 1.0
extern f32 lbl_805610D8; // 0.0
extern f32 lbl_805610DC; // 128.0
extern f32 lbl_805610E0; // 0.0

extern "C" u32 fn_800FEB9C(void);

extern "C" void fn_800FDE28(void *arg0) {
    void *p = *(void **)arg0;
    if (p && *(void **)((u8 *)p + 0x5F4) == arg0) {
        *(void **)((u8 *)p + 0x5F4) = NULL;
    }
    if (*(void **)arg0) {
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_800FDFF8(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

extern "C" s32 fn_800FE0DC(void *arg0) {
    void *p = *(void **)((u8 *)arg0 + 0x18);
    return *(s32 *)((u8 *)p + 0x40);
}

extern "C" void *fn_800FE648(void) {
    if (lbl_8055DE80 == 0) {
        lbl_8041B138[0x2360] = 0;
        lbl_8055DE80 = 1;
    }
    return lbl_8041B138;
}

extern "C" void fn_800FE804(void *arg0) {
    OSSendMessage((OSMessageQueue *)((u8 *)arg0 + 0x2320), (OSMessage)0x1, 0);
}

extern "C" s32 fn_800FE814(s32 arg0) {
    u32 msg;

    OSInitMessageQueue((OSMessageQueue *)(arg0 + 0x2320), (OSMessage *)(arg0 + 0x2340), 8);
    for (;;) {
        OSReceiveMessage((OSMessageQueue *)(arg0 + 0x2320), (OSMessage *)&msg, 1);
        if (msg == 1) {
            fn_800FDE60();
            fn_800FE1D0();
            continue;
        }
        if (msg != 2) {
            continue;
        }
        return 0;
    }
}

extern "C" f32 CalcVolumeRatio__Q46nw4hbm3snd6detail4UtilFf(f32 value) {
    f32 v;
    s32 idx;

    if (value > lbl_805610D4) {
        v = lbl_805610D4;
    } else if (value < lbl_805610D8) {
        v = lbl_805610D8;
    } else {
        v = value;
    }

    idx = (s32)(lbl_805610DC * v);
    return lbl_802F5210[idx + 0x388];
}

extern "C" f32 CalcPanRatio__Q46nw4hbm3snd6detail4UtilFf(f32 pan) {
    f32 v;
    f32 t;

    if (pan > lbl_805610C8) {
        v = lbl_805610C8;
    } else if (pan < lbl_805610E0) {
        v = lbl_805610E0;
    } else {
        v = pan;
    }

    t = lbl_805610C8 + v;
    return lbl_802F6124[(s32)(lbl_805610D0 +
                              lbl_805610E4 * (t * lbl_805610D0))];
}

extern "C" f32 CalcSurroundPanRatio__Q46nw4hbm3snd6detail4UtilFf(f32 pan) {
    f32 v;

    if (pan > lbl_805610CC) {
        v = lbl_805610CC;
    } else if (pan < lbl_805610E8) {
        v = lbl_805610E8;
    } else {
        v = pan;
    }

    return lbl_802F6124[(s32)(lbl_805610D0 +
                              lbl_805610E4 * (v * lbl_805610D0))];
}

extern "C" s32 CalcLpfFreq__Q46nw4hbm3snd6detail4UtilFf(f32 value) {
    f32 v;

    if (value > lbl_805610C8) {
        v = lbl_805610C8;
    } else if (value < lbl_805610E8) {
        v = lbl_805610E8;
    } else {
        v = value;
    }

    return (s32)(lbl_805610F0 * fn_8002EFBC(lbl_80561100 * ((double)v - lbl_80561108), lbl_805610F8));
}

u32 fn_800FEB9C(void) {
    u32 val = lbl_80559900 * 0x19660D;
    val += 0x3C6F0000;
    u32 out = val;
    out -= 0x0CA1;
    lbl_80559900 = out;
    return out >> 16;
}

extern "C" void *GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(
    s32 type, u32 arg, void *pBase) {
    if (type == 1) {
        return (void *)(arg + (u32)pBase);
    }

    if (type == 0) {
        return (void *)arg;
    }

    Panic__Q26nw4hbm2dbFPCciPCce((const char *)lbl_80327010, 0x1F6,
                                 (const char *)lbl_80327020);
    return NULL;
}

extern "C" void fn_800FEC1C(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

extern "C" void __dt__Q36nw4hbm3snd10WavePlayerFv(void *this_, u32 arg1) {
    if (this_ != NULL) {
        *(void **)this_ = lbl_80327334;
        u32 level = OSDisableInterrupts();
        Stop__Q36nw4hbm3snd10WavePlayerFv(this_);
        if (*(void **)((u8 *)this_ + 0x18) != NULL) {
            Free__Q46nw4hbm3snd6detail7AxVoiceFv(*(void **)((u8 *)this_ + 0x18));
        }
        *(void **)((u8 *)this_ + 0x18) = NULL;
        *(void **)((u8 *)this_ + 0x10) = NULL;
        OSRestoreInterrupts(level);
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv((void *)((u8 *)this_ + 4), 0);
        if (arg1 > 0) {
            fn_80128668(this_);
        }
    }
}

extern "C" s32 fn_80128668(void *);

extern "C" void fn_800FDE60(void);
extern "C" void fn_800FE1D0(void);

#pragma push
#pragma small_data off
extern u8 lbl_8041B138[];
#pragma pop
extern u8 lbl_8055DE80;
extern "C" s32 fn_800FF940(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        ((s32 (*)(void))fn_80128668)();
    }
    return arg0;
}

