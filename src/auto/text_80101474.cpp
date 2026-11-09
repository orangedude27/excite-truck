// Code of main that had no source file yet: decomp.wtf gave it this one.
extern "C" const char lbl_80327CB8[];
extern "C" const char lbl_80327CCC[];
extern "C" void fn_800EA880(void *, int);
extern "C" int Parse__Q46nw4hbm3snd6detail8WsdTrackFPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUlb(void *, const void *, unsigned long, bool);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" const char lbl_803246E0[];
extern "C" const char lbl_80324728[];
extern "C" const char lbl_80324734[];
extern "C" const char lbl_8032477C[];
extern "C" const char lbl_80324788[];
extern "C" const char lbl_803247D0[];
extern "C" float lbl_8056112C, lbl_80561130, lbl_80561134, lbl_80561138;
// WsdPlayer-like interface: only the virtual slots UpdateChannel calls (first slot at 0x8).
struct WsdPlayerIface {
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14(); virtual void s18();
    virtual void s1C(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2C();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3C(); virtual void s40();
    virtual float m44(); virtual float m48(); virtual float m4C(); virtual float m50(); virtual float m54();
    virtual float m58(); virtual float m5C(); virtual void s60(); virtual void s64(); virtual void s68();
    virtual void s6C(); virtual void s70(); virtual void s74(); virtual void s78();
    virtual int m7C(); virtual float m80(); virtual float m84(); virtual float m88(int);
    virtual float m8C(int); virtual float m90(int); virtual float m94(int);
};
extern "C" const char lbl_80328030[];
extern "C" const char lbl_80327EE0[];
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void);
extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(int, unsigned char);
extern int ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(int);
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(void *, int);
extern "C" int fn_800EAD00(void *);
extern "C" const char lbl_80328178[];
extern "C" const char lbl_8032818C[];
extern "C" unsigned char lbl_8041D4E0[];
// NW4HBM_ASSERT_VALID_PTR(this) as expanded in CharWriter.cpp
#define CW_CHECK_THIS(self, line) \
    { \
        unsigned int cw_addr = (unsigned int)(self); \
        int cw_r4 = 1, cw_r5 = 1, cw_r6 = 1, cw_r7 = 1, cw_r8 = 1, cw_r9 = 1; \
        unsigned int cw_top = cw_addr & 0xFF000000U; \
        if (cw_top != 0x80000000U && (cw_addr & 0xFF800000U) != 0x81000000U) cw_r9 = 0; \
        if (cw_r9 == 0 && (cw_addr & 0xF8000000U) != 0x90000000U) cw_r8 = 0; \
        if (cw_r8 == 0 && cw_top != 0xC0000000U) cw_r7 = 0; \
        if (cw_r7 == 0 && (cw_addr & 0xFF800000U) != 0xC1000000U) cw_r6 = 0; \
        if (cw_r6 == 0 && (cw_addr & 0xF8000000U) != 0xD0000000U) cw_r5 = 0; \
        if (cw_r5 == 0 && (cw_addr & 0xFFFFC000U) != 0xE0000000U) cw_r4 = 0; \
        if (cw_r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, line, lbl_8032818C, self); \
    }
extern "C" void __register_global_object(void *, void *, void *);
extern "C" void fn_800D2DD4(void);
extern "C" unsigned char lbl_8055DE90;
extern "C" unsigned char lbl_8055DE94, lbl_8055DE95, lbl_8055DE96, lbl_8055DE97;
extern "C" float lbl_80561150;
extern "C" unsigned char lbl_8041D4D0[];
extern "C" void SetupGXWithColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(unsigned int, unsigned int);
extern "C" void GXSetFog(int, void *, unsigned char, unsigned char, float, float, float, float);
extern "C" void GXSetTevSwapModeTable(int, int, int, int, int);
extern "C" void GXSetZTexture(int, int, int);
extern "C" void GXSetNumChans(int);
extern "C" void GXSetChanCtrl(int, int, int, int, int, int, int);
extern "C" void GXSetNumTexGens(int);
extern "C" void GXSetTexCoordGen2(int, int, int, int, int, int);
extern "C" void GXSetNumIndStages(int);
extern "C" void GXSetBlendMode(int, int, int, int);
extern "C" void GXSetNumTevStages(int);
extern "C" void GXSetTevDirect(int);
extern "C" void GXSetTevSwapMode(int, int, int);
extern "C" void GXSetTevOrder(int, int, int, int);
extern "C" void GXSetTevColor(int, void *, int, int, int);
extern "C" void GXSetTevColorIn(int, int, int, int, int);
extern "C" void GXSetTevAlphaIn(int, int, int, int, int);
extern "C" void GXSetTevColorOp(int, int, int, int, int, int);
extern "C" void GXSetTevAlphaOp(int, int, int, int, int, int);
extern "C" void GXSetVtxAttrFmt(int, int, int, int, int);
extern "C" void GXClearVtxDesc(void);
extern "C" void GXSetVtxDesc(int, int);
extern "C" void GXSetTevOp(int, int);
typedef int s32;
struct Color4 { unsigned char r, g, b, a; };
#pragma cplusplus on
struct FontForWidth { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); };
struct SetupGXFontType { virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3(); virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7(); virtual int f8(); virtual int f9(); virtual int GetType(); };
namespace nw4hbm { namespace ut { struct Color { unsigned char r, g, b, a; }; struct Glyph; struct PrintFont { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void GetGlyph(void*, unsigned short); }; class CharWriter { public: CharWriter(); enum GradationMode { GRADATION_SOLID, GRADATION_VERTICAL, GRADATION_HORIZONTAL }; void PrintGlyph(float, float, float, const Glyph&); void SetTextColor(Color); void SetTextColor(Color, Color); float Print(unsigned short); void SetGradationMode(GradationMode); void SetFontSize(float, float); void SetupGX(); }; }}
#pragma cplusplus reset
namespace nw4hbm { namespace snd { namespace detail {
class Channel { public: enum ChannelCallbackStatus { Status }; };
class WsdTrack { public: struct WsdCallback { virtual int f0() const; virtual int GetWave(void *, void *, void *, int, int, int, unsigned long) const; }; static void ChannelCallbackFunc(Channel *, Channel::ChannelCallbackStatus, unsigned long); void Close(); int ParseNextTick(const WsdCallback *, unsigned long, bool); int Parse(const WsdCallback *, unsigned long, bool); };
}}}
extern int fn_801013B0(int);
extern int InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(int);
extern int fn_800FFA6C(int);
extern int fn_800EC890(void *, int, int, int);
extern float lbl_80561128;
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80101474(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801014CC(s32 arg0) {
    fn_801013B0(arg0 - 8);
}

extern "C" void fn_801014D4(s32 arg0) {
    InvalidateData__Q46nw4hbm3snd6detail9WsdPlayerFPCvPCv(arg0 - 8);
}

extern "C" void fn_801014DC(s32 arg0) {
    fn_800FFA6C(arg0 - 8);
}

extern int fn_800EC890(void *, void *, int, int, int);
#pragma scheduling invalid_target
extern "C" void Init__Q46nw4hbm3snd6detail8WsdTrackFPQ46nw4hbm3snd6detail9WsdPlayer(void *arg0, void *arg1) {
    float defaultValue = lbl_80561128;
    register int value7F = 0x7F;
    register int valueMinus1 = -1;
    register int value40 = 0x40;
    register int value2 = 2;

    *(void **)((char *)arg0 + 0x2C) = arg1;
    *(int *)((char *)arg0 + 0) = 0;
    *(int *)((char *)arg0 + 4) = valueMinus1;
    *(unsigned char *)((char *)arg0 + 0x1D) = value40;
    *(unsigned char *)((char *)arg0 + 0x1C) = value2;
    *(float *)((char *)arg0 + 0x20) = defaultValue;
    *(unsigned char *)((char *)arg0 + 0x24) = value40;
    *(unsigned char *)((char *)arg0 + 0x25) = 0;
    *(unsigned char *)((char *)arg0 + 0x26) = 0;
    *(unsigned char *)((char *)arg0 + 0x27) = 0;
    *(unsigned char *)((char *)arg0 + 0x28) = 0;
    *(unsigned char *)((char *)arg0 + 0x29) = value7F;
    fn_800EC890((char *)arg0 + 0xC, arg1, value2, value40, valueMinus1);
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 0x30) = 0;
}
#pragma scheduling on
extern "C" void NWC24Data_SetDataP(void *arg0, int arg1, int arg2) {
    *(int *)arg0 = arg1;
    *((int *)arg0 + 1) = arg2;
}

void nw4hbm::snd::detail::WsdTrack::Close() {
    void *var_r31;
    ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(this, -1);
    var_r31 = *(void **)((char *)this + 0x30);
    goto check;
loop:
    fn_800EAD00(var_r31);
    var_r31 = *(void **)((char *)var_r31 + 0xE4);
check:
    if (var_r31 != 0) goto loop;
    *(void **)((char *)this + 0x30) = 0;
}

#pragma use_lmw_stmw off
#pragma scheduling on
int nw4hbm::snd::detail::WsdTrack::ParseNextTick(
    const nw4hbm::snd::detail::WsdTrack::WsdCallback *callback,
    unsigned long arg1,
    bool arg2
) {
    register int valid = *(int *)((char *)this + 0x2C);
    void *channel;

    if (valid == 0) {
        const char *message = lbl_80327CCC;
        const char *file = lbl_80327CB8;
        int line = 0x6F;
        Panic__Q26nw4hbm2dbFPCciPCce(file, line, message);
    }
    channel = *(void **)((char *)this + 0x30);
    goto check;

loop:
    if (*(int *)((char *)channel + 0xD4) > 0) {
        *(int *)((char *)channel + 0xD4) -= 1;
        if (*(unsigned char *)((char *)channel + 0x3C) == 0) {
            fn_800EA880(channel, 1);
        }
        if (*(int *)((char *)channel + 0xD4) == 0) {
            Release__Q46nw4hbm3snd6detail7ChannelFv(channel);
        }
    }
    channel = *(void **)((char *)channel + 0xE4);
check:
    if (channel != 0) goto loop;

    if (*(int *)((char *)this + 8) != 0 &&
        *(void **)((char *)this + 0x30) == 0) {
        return -1;
    }
    return Parse__Q46nw4hbm3snd6detail8WsdTrackFPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUlb(
        this, callback, arg1, arg2
    );
}
#pragma scheduling reset
#pragma use_lmw_stmw on
extern "C" void UpdateChannel__Q46nw4hbm3snd6detail8WsdTrackFv(void *);
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void *Instance__15EmissionManagerFv(void);
extern "C" void fn_800E402C(void *);
extern "C" void fn_800E4064(void *);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
#pragma use_lmw_stmw off
extern "C" const char lbl_80327D00[];
#pragma push
#pragma optimization_level 3
#pragma use_lmw_stmw off
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(void *arg0, int arg1) {
    UpdateChannel__Q46nw4hbm3snd6detail8WsdTrackFv(arg0);
    int interrupts = OSDisableInterrupts();
    fn_800E402C(Instance__15EmissionManagerFv());
    void *channel = *(void **)((char *)arg0 + 0x30);
    while (channel != 0) {
        if (*(unsigned char *)((char *)channel + 0x3A) != 0) {
            if (arg1 >= 0) {
                ((0 <= arg1) && (arg1 <= 0x7F)) ? (void)0 : Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327CB8, 0xA0, lbl_80327D00, arg1, 0, 0x7F);
                SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, (unsigned char)arg1);
            }
            Release__Q46nw4hbm3snd6detail7ChannelFv(channel);
        }
        channel = *(void **)((char *)channel + 0xE4);
    }
    fn_800E4064(Instance__15EmissionManagerFv());
    OSRestoreInterrupts(interrupts);
}
#pragma pop
extern "C" void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void *arg0, unsigned char arg1) {
    unsigned char *track = (unsigned char *)arg0;
    void *channel = *(void **)(track + 0x30);
    while (channel != 0) {
        unsigned char *p = (unsigned char *)channel;
        if (p[0x3A] != 0 && arg1 != (p[0x39] != 0)) {
            p[0x39] = arg1;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(int *)((char *)channel + 0xE0), arg1);
        }
        channel = *(void **)(p + 0xE4);
    }
}

#pragma processor gekko
extern "C" void UpdateChannel__Q46nw4hbm3snd6detail8WsdTrackFv(void *arg0) {
    unsigned char *self = (unsigned char *)arg0;
    float f31 = lbl_80561128;
    f31 *= (*(WsdPlayerIface **)(self + 0x2C))->m44();
    float f30 = lbl_80561128;
    f30 *= (*(WsdPlayerIface **)(self + 0x2C))->m48();
    f30 *= *(float *)(self + 0x20);
    unsigned char b = self[0x24];
    float f29 = lbl_8056112C;
    if (b <= 1) f29 += (float)((int)b - 0x3F) / lbl_80561130;
    else f29 += (float)((int)b - 0x40) / lbl_80561130;
    WsdPlayerIface *pl = *(WsdPlayerIface **)(self + 0x2C);
    f29 *= *(float *)((unsigned char *)pl + 0x30);
    f29 += pl->m4C();
    unsigned char b2 = self[0x25];
    float f28 = lbl_8056112C;
    if (b2 <= 1) f28 += (float)((int)b2 + 1) / lbl_80561130;
    else f28 += (float)b2 / lbl_80561130;
    f28 += (float)b2 * lbl_80561134;
    f28 += (*(WsdPlayerIface **)(self + 0x2C))->m50();
    float f27 = lbl_8056112C;
    f27 += (*(WsdPlayerIface **)(self + 0x2C))->m54();
    float f26 = lbl_8056112C;
    f26 += (*(WsdPlayerIface **)(self + 0x2C))->m58();
    float f25 = lbl_8056112C;
    f25 += (*(WsdPlayerIface **)(self + 0x2C))->m5C();
    unsigned char b3 = self[0x29];
    pl = *(WsdPlayerIface **)(self + 0x2C);
    float f24 = lbl_80561128;
    f24 += ((float)b3 / lbl_80561138) - f24;
    f24 += pl->m84();
    unsigned char col[3];
    float acc[3];
    float lo[4];
    float hi[4];
    col[0] = self[0x26]; col[1] = self[0x27]; col[2] = self[0x28];
    float zero1 = lbl_8056112C;
    float k255 = lbl_80561138;
    unsigned char *cp = col;
    float *ap = acc;
    for (int i = 0; i < 3; i++) {
        *ap = zero1;
        *ap += (float)*cp / k255;
        *ap += (*(WsdPlayerIface **)(self + 0x2C))->m88(i);
        cp++; ap++;
    }
    float zero2 = lbl_8056112C;
    float *lp = lo;
    float *hp = hi;
    for (int i = 0; i < 4; i++) {
        *lp = zero2;
        *lp += (*(WsdPlayerIface **)(self + 0x2C))->m90(i);
        *hp = zero2;
        *hp += (*(WsdPlayerIface **)(self + 0x2C))->m94(i);
        lp++; hp++;
    }
    int interrupts = OSDisableInterrupts();
    unsigned char *ch = *(unsigned char **)(self + 0x30);
    float a0 = acc[0], a1 = acc[1], a2 = acc[2];
    while (ch != 0) {
        *(float *)(ch + 0x40) = f31;
        *(float *)(ch + 0x44) = f30;
        *(float *)(ch + 0x48) = f29;
        *(float *)(ch + 0x4C) = f28;
        *(float *)(ch + 0x50) = f27;
        *(float *)(ch + 0x54) = f26;
        *(float *)(ch + 0x58) = f25;
        *(int *)(ch + 0x5C) = (*(WsdPlayerIface **)(self + 0x2C))->m7C();
        *(float *)(ch + 0x60) = (*(WsdPlayerIface **)(self + 0x2C))->m80();
        *(float *)(ch + 0x64) = f24;
        *(float *)(ch + 0x68) = a0;
        *(float *)(ch + 0x6C) = a1;
        *(float *)(ch + 0x70) = a2;
        unsigned char *p = ch;
        float *lq = lo;
        float *hq = hi;
        for (int i = 0; i < 4; i++) {
            float v = (*(WsdPlayerIface **)(self + 0x2C))->m8C(i);
            int ok = 0;
            if (i >= 0 && i < 4) ok = 1;
            if (ok == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80324728, 0xA5, lbl_803246E0, i, 0, 4);
            *(float *)(p + 0x74) = v;
            float w = *lq;
            ok = 0;
            if (i >= 0 && i < 4) ok = 1;
            if (ok == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8032477C, 0xAA, lbl_80324734, i, 0, 4);
            *(float *)(p + 0x84) = w;
            w = *hq;
            ok = 0;
            if (i >= 0 && i < 4) ok = 1;
            if (ok == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803247D0, 0xAF, lbl_80324788, i, 0, 4);
            *(float *)(p + 0x94) = w;
            p += 4; lq++; hq++;
        }
        *(float *)(ch + 0x20) = *(float *)(self + 0xC);
        *(float *)(ch + 0x24) = *(float *)(self + 0x10);
        *(int *)(ch + 0x28) = *(int *)(self + 0x14);
        ch[0x2C] = self[0x18];
        ch[0x2D] = self[0x19];
        ch[0x2E] = self[0x1A];
        ch[0x2F] = self[0x1B];
        ch = *(unsigned char **)(ch + 0xE4);
    }
    OSRestoreInterrupts(interrupts);
}
extern "C" void *AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(int, int, int, void (*)(void *, int, unsigned long), void *);
extern "C" void ChannelCallbackFunc__Q46nw4hbm3snd6detail8WsdTrackFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl(void *, int, unsigned long);
extern "C" void SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(void *, const void *, int);
#pragma push
#pragma optimization_level 3
int nw4hbm::snd::detail::WsdTrack::Parse(const nw4hbm::snd::detail::WsdTrack::WsdCallback *callback, unsigned long arg2, bool arg3) {
    unsigned char sp8[0x10];
    unsigned char sp18[0x90];
    if (*(void **)((char *)this + 0x2C) == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327CB8, 0x189, lbl_80327CCC);
    if (*(int *)((char *)this + 8) == 0) {
        void *owner = *(void **)((char *)this + 0x2C);
        int pitch = *((unsigned char *)this + 0x1D) + *(unsigned char *)((char *)owner + 0x90);
        if (!callback->GetWave((char *)this + 0x20, sp8, sp18,
                               *(int *)this, *(int *)((char *)this + 4), 0, arg2))
            return -1;
        owner = *(void **)((char *)this + 0x2C);
        int maxVoices = *(int *)((char *)owner + 0x8C);
        int count = (int)sp18[2];
        int voices = count > 2 ? 2 : count;
        void *channel = AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(
            voices, maxVoices, pitch,
            ChannelCallbackFunc__Q46nw4hbm3snd6detail8WsdTrackFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl,
            this);
        if (channel == 0) return -1;
        SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, sp8[4]);
        SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, sp8[5]);
        SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, sp8[6]);
        SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, sp8[7]);
        Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(channel, sp18, -1);
        *(void **)((char *)channel + 0xE4) = *(void **)((char *)this + 0x30);
        *(void **)((char *)this + 0x30) = channel;
        *(int *)((char *)this + 8) += 1;
    } else if (*(void **)((char *)this + 0x30) == 0) return -1;
    return 0;
}
#pragma pop
extern "C" const char lbl_80327CB8[];
void nw4hbm::snd::detail::WsdTrack::ChannelCallbackFunc(nw4hbm::snd::detail::Channel *arg0, nw4hbm::snd::detail::Channel::ChannelCallbackStatus arg1, unsigned long arg2) {
    const char *base = lbl_80327CB8;
    void *track = (void *)arg2;
    register void *channel;
    register void *next;
    if (arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x1cf, base + 0x88);
    if (track == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x1d0, base + 0xb8);
    if ((int)arg1 == 2) fn_800EAD00(arg0);
    channel = *(void **)((char *)track + 0x30);
    if (channel == arg0) {
        *(void **)((char *)track + 0x30) = *(void **)((char *)arg0 + 0xe4);
        return;
    }
    if (channel == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x1dd, base + 0xe0);
    next = *(void **)((char *)channel + 0xe4);
    while (next != 0) {
        if (next == arg0) {
            *(void **)((char *)channel + 0xe4) = *(void **)((char *)arg0 + 0xe4);
            return;
        }
        channel = next;
        next = *(void **)((char *)channel + 0xe4);
    }
    Panic__Q26nw4hbm2dbFPCciPCce(base, 0x1e7, base + 0x10c);
}

extern "C" int IsValidBinaryFile__Q26nw4hbm2utFPCQ36nw4hbm2ut16BinaryFileHeaderUlUsUs(const void *arg0, unsigned long arg1, unsigned short arg2, unsigned short arg3) {
    const char *base=lbl_80327EE0;
    const unsigned char *header=(const unsigned char *)arg0;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    unsigned int top=(unsigned int)arg0&0xFF000000U;
    if(top != 0x80000000U&&((unsigned int)arg0&0xFF800000U)!=0x81000000U)r10=0;
    if(r10==0&&((unsigned int)arg0&0xF8000000U)!=0x90000000U)r9=0;
    if(r9==0&&top!=0xC0000000U)r8=0;
    if(r8==0&&((unsigned int)arg0&0xFF800000U)!=0xC1000000U)r7=0;
    if(r7==0&&((unsigned int)arg0&0xF8000000U)!=0xD0000000U)r6=0;
    if(r6==0&&((unsigned int)arg0&0xFFFFC000U)!=0xE0000000U)r5=0;
    if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x30,base+0x18,arg0);
    unsigned int magic=*(unsigned int *)header;
    if(magic!=(unsigned int)arg1) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x3C,base+0x50,
            (signed char)(magic>>24),(signed char)((magic >> 16) & 0xff),(signed char)((magic >> 8) & 0xff),(signed char)(magic & 0xff),
            (signed char)((unsigned int)arg1>>24),(signed char)(((unsigned int)arg1 >> 16) & 0xff),(signed char)(((unsigned int)arg1 >> 8) & 0xff),(signed char)(arg1 & 0xff));
        return 0;
    }
    if(*(unsigned short *)(header+4)!=0xFEFF) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x41,base+0x88);
        return 0;
    }
    unsigned short version=*(unsigned short *)(header+6);
    if(version!=arg2) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x4B,base+0xA0,
            ((unsigned int)version >> 8),(unsigned char)version,(unsigned char)(arg2>>8),(unsigned char)arg2);
        return 0;
    }
    if(*(unsigned int *)(header+8)<(((unsigned int)arg3<<3)+0x10)) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x50,base+0xD0, *(unsigned int *)(header+8));
        return 0;
    }
    if(*(unsigned short *)(header+0xE)<arg3) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x55,base+0xEC, *(unsigned short *)(header+0xE));
        return 0;
    }
    return 1;
}

extern "C" unsigned short ReadNextCharUTF8__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    const char *base=lbl_80328030;
    unsigned int value=(unsigned int)arg0;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    unsigned int t=value&0xFF000000U;
    if(t!=0x80000000U&&(value&0xFF800000U)!=0x81000000U)f=0;
    if(f==0&&(value&0xF8000000U)!=0x90000000U)e=0;
    if(e==0&&t!=0xC0000000U)d=0;
    if(d==0&&(value&0xFF800000U)!=0xC1000000U)c=0;
    if(c==0&&(value&0xF8000000U)!=0xD0000000U)b=0;
    if(b==0&&(value&0xFFFFC000U)!=0xE0000000U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x4C,base+0x18,arg0);
    int g=1,h=1;
    unsigned int v=*(unsigned int *)arg0;
    int i=1,j=1,k=1,l=1;
    unsigned int t2=v&0xFF000000U;
    if(t2!=0x80000000U&&(v&0xFF800000U)!=0x81000000U)l=0;
    if(l==0&&(v&0xF8000000U)!=0x90000000U)k=0;
    if(k==0&&t2!=0xC0000000U)j=0;
    if(j==0&&(v&0xFF800000U)!=0xC1000000U)i=0;
    if(i==0&&(v&0xF8000000U)!=0x90000000U+0x40000000U)h=0;
    if(h==0&&(v&0xFFFFC000U)!=0xE0000000U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x4D,base+0x50);
    unsigned char * volatile *pp=(unsigned char * volatile *)arg0;
    if((**pp&0xC0)==0x80)Panic__Q26nw4hbm2dbFPCciPCce(base,0x4F,base+0x8C);
    unsigned char *ptr=*pp;
    unsigned char first=*ptr;
    if(!(first&0x80)){*pp=*pp+1;return first;}
    if((first&0xE0)==0xC0){
        unsigned int r=((first&0x1F)<<6)|(ptr[1]&0x3F);
        *pp=*pp+2;
        return r;
    }
    if((first&0xF0)!=0xE0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x64,base+0xC4);
    unsigned char *q=*pp;
    unsigned char *n=*pp+3;
    unsigned int r=((q[0]&0x1F)<<12)|((q[1]&0x3F)<<6)|(q[2]&0x3F);
    *pp=n;
    return r;
}

extern "C" unsigned short ReadNextCharUTF16__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    const char *file = lbl_80328030;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)arg0 & 0xFF000000U;
    if (top != 0x80000000U && ((unsigned int)arg0 & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)arg0 & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)arg0 & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)arg0 & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)arg0 & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x81, file + 0x18, arg0);

    int f4 = 1, f5 = 1;
    unsigned int value = *(unsigned int *)arg0;
    int f7 = 1, f8 = 1, f9 = 1, f10 = 1;
    unsigned int top2 = value & 0xFF000000U;
    if (top2 != 0x80000000U && (value & 0xFF800000U) != 0x81000000U) f10 = 0;
    if (f10 == 0 && (value & 0xF8000000U) != 0x90000000U) f9 = 0;
    if (f9 == 0 && top2 != 0xC0000000U) f8 = 0;
    if (f8 == 0 && (value & 0xFF800000U) != 0xC1000000U) f7 = 0;
    if (f7 == 0 && (value & 0xF8000000U) != 0xD0000000U) f5 = 0;
    if (f5 == 0 && (value & 0xFFFFC000U) != 0xE0000000U) f4 = 0;
    if (f4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x82, file + 0x50);

    unsigned int align = *(unsigned int *)arg0;
    if (align & 1) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x83, file + 0xFC);
    }

    unsigned short ch = **(const unsigned short **)arg0;
    *(const unsigned short **)arg0 = (const unsigned short *)(*(const char **)arg0 + 2);
    return ch;
}

extern "C" const char lbl_80328030[];
extern "C" unsigned char ReadNextCharCP1252__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    const char *file = lbl_80328030;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)arg0 & 0xFF000000U;
    if (top != 0x80000000U && ((unsigned int)arg0 & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)arg0 & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)arg0 & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)arg0 & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)arg0 & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(&file[0], 0x9B, &file[0x18], arg0);
    int f4 = 1, f5 = 1;
    unsigned int value = *(unsigned int *)arg0;
    int f6 = 1, f7 = 1, f8 = 1, f9 = 1;
    unsigned int top2 = value & 0xFF000000U;
    if (top2 != 0x80000000U && (value & 0xFF800000U) != 0x81000000U) f9 = 0;
    if (f9 == 0 && (value & 0xF8000000U) != 0x90000000U) f8 = 0;
    if (f8 == 0 && top2 != 0xC0000000U) f7 = 0;
    if (f7 == 0 && (value & 0xFF800000U) != 0xC1000000U) f6 = 0;
    if (f6 == 0 && (value & 0xF8000000U) != 0xD0000000U) f5 = 0;
    if (f5 == 0 && (value & 0xFFFFC000U) != 0xE0000000U) f4 = 0;
    if (f4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328030 + 0, 0x9C, file + 0x50);
    unsigned char result = **(unsigned char **)arg0;
    *(unsigned int *)arg0 = *(unsigned int *)arg0 + 1;
    return result;
}

static inline bool IsSJISLeadByte(unsigned char c) {
    return (c >= 0x81 && c < 0xA0) || c >= 0xE0;
}

extern "C" unsigned short ReadNextCharSJIS__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    const char *file = lbl_80328030;
    const char *name = file;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)arg0 & 0xFF000000U;
    if (top != 0x80000000U && ((unsigned int)arg0 & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)arg0 & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)arg0 & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)arg0 & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)arg0 & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(name, 0xB4, file + 0x18, arg0);

    int f4 = 1, f5 = 1;
    unsigned int value = *(unsigned int *)arg0;
    int f7 = 1, f8 = 1, f9 = 1, f10 = 1;
    unsigned int top2 = value & 0xFF000000U;
    if (top2 != 0x80000000U && (value & 0xFF800000U) != 0x81000000U) f10 = 0;
    if (f10 == 0 && (value & 0xF8000000U) != 0x90000000U) f9 = 0;
    if (f9 == 0 && top2 != 0xC0000000U) f8 = 0;
    if (f8 == 0 && (value & 0xFF800000U) != 0xC1000000U) f7 = 0;
    if (f7 == 0 && (value & 0xF8000000U) != 0xD0000000U) f5 = 0;
    if (f5 == 0 && (value & 0xFFFFC000U) != 0xE0000000U) f4 = 0;
    if (f4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(name, 0xB5, file + 0x50);

    const unsigned char *s = *(const unsigned char **)arg0;
    unsigned char c = *s;
    if (IsSJISLeadByte(c)) {
        unsigned short r = s[1] | (c << 8);
        *(const unsigned char **)arg0 += 2;
        return r;
    }
    *(const unsigned char **)arg0 += 1;
    return c;
}

extern "C" float lbl_80561154;
extern "C" void SetColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(void *arg0, void *arg1, void *arg2);
nw4hbm::ut::CharWriter::CharWriter() {
    unsigned char *self = (unsigned char *)this;
    unsigned char *source1, *source2, *source3;
    nw4hbm::ut::Color colorB, white, colorA;
    unsigned int addr = (unsigned int)this;
    int r9 = 1, r10 = 1, r11 = 1, r12 = 1, r30 = 1, r29 = 1;
    unsigned int top = addr & 0xFF000000U;
    *(int *)(self + 0) = -1;
    *(int *)(self + 4) = -1;
    *(int *)(self + 8) = -1;
    *(int *)(self + 0xC) = -1;
    *(int *)(self + 0x10) = -1;
    *(int *)(self + 0x14) = -1;
    *(int *)(self + 0x18) = -1;
    *(int *)(self + 0x1C) = -1;
    *(self + 0x42) = 0xFF;
    *(self + 0x43) = 0;
    *(float *)(self + 0x44) = lbl_80561150;
    *(int *)(self + 0x48) = 0;
    (*(int *)((signed char *)(&lbl_8041D4E0) + (0))) = 0xFF;
    (*(int *)((signed char *)(&lbl_8041D4E0) + (4))) = 0;
    if (top != 0x80000000U && (addr & 0xFF800000U) != 0x81000000U) r29 = 0;
    if (r29 == 0 && (addr & 0xF8000000U) != 0x90000000U) r30 = 0;
    if (r30 == 0 && top != 0xC0000000U) r12 = 0;
    if (r12 == 0 && (addr & 0xFF800000U) != 0xC1000000U) r11 = 0;
    if (r11 == 0 && (addr & 0xF8000000U) != 0xD0000000U) r10 = 0;
    if (r10 == 0 && (addr & 0xFFFFC000U) != 0xE0000000U) r9 = 0;
    if (r9 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x11C, lbl_8032818C, this);
    *(int *)&colorA = 0;
    *(int *)&colorB = -1;
    SetColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(this, &colorA, &colorB);
    CW_CHECK_THIS(this, 0x163);
    *(int *)(self + 0x20) = 0;
    CW_CHECK_THIS(this, 0x4DA);
    self[8] = self[0x18]; self[9] = self[0x19]; self[0xA] = self[0x1A]; self[0xB] = self[0x1B];
    if (*(int *)(self + 0x20) != 1) source1 = self + 0x18; else source1 = self + 0x1C;
    self[0xC] = source1[0]; self[0xD] = source1[1]; self[0xE] = source1[2]; self[0xF] = source1[3];
    if (*(int *)(self + 0x20) != 2) source2 = self + 0x18; else source2 = self + 0x1C;
    self[0x10] = source2[0]; self[0x11] = source2[1]; self[0x12] = source2[2]; self[0x13] = source2[3];
    if (*(int *)(self + 0x20) == 0) source3 = self + 0x18; else source3 = self + 0x1C;
    self[0x14] = source3[0]; self[0x15] = source3[1]; self[0x16] = source3[2];
    {
        int alpha = *(volatile unsigned char *)(self + 0x42);
        int product_b = self[0xB] * alpha, product_f = self[0xF] * alpha;
        int product_13 = self[0x13] * alpha, product_17 = source3[3] * alpha;
        self[0xB] = product_b / 255; self[0xF] = product_f / 255;
        self[0x13] = product_13 / 255; self[0x17] = product_17 / 255;
    }
    *(int *)&white = -1;
    SetTextColor(white);
    CW_CHECK_THIS(this, 0x1E7);
    *(float *)(self + 0x24) = lbl_80561154;
    *(float *)(self + 0x28) = lbl_80561154;
    CW_CHECK_THIS(this, 0x386);
    *(float *)(self + 0x2C) = lbl_80561150;
    *(float *)(self + 0x30) = lbl_80561150;
    *(float *)(self + 0x34) = lbl_80561150;
    CW_CHECK_THIS(this, 0x2A9);
    *(int *)(self + 0x38) = 1;
    *(int *)(self + 0x3C) = 1;
}

extern "C" s32 fn_801033F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void SetFont__Q36nw4hbm2ut10CharWriterFRCQ36nw4hbm2ut4Font(void *arg0, void *arg1) {
    const char *panicData = lbl_80328178;
    void *writer = arg0;
    void *font = arg1;

    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)writer & 0xFF000000;
    if ((top != 0x80000000) && (((unsigned int)writer & 0xFF800000) != 0x81000000)) r10 = 0;
    if (r10 == 0 && (((unsigned int)writer & 0xF8000000) != 0x90000000)) r9 = 0;
    if (r9 == 0 && (top != 0xC0000000)) r8 = 0;
    if (r8 == 0 && (((unsigned int)writer & 0xFF800000) != 0xC1000000)) r7 = 0;
    if (r7 == 0 && (((unsigned int)writer & 0xF8000000) != 0xD0000000)) r6 = 0;
    if (r6 == 0 && (((unsigned int)writer & 0xFFFFC000) != 0xE0000000)) r5 = 0;
    if (r5 == 0) ((void (*)(const char *, int, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(panicData, 0x85, panicData + 0x14, writer);

    int f4 = 1, f5 = 1, f6 = 1, f7 = 1, f8 = 1, f9 = 1;
    unsigned int ftop = (unsigned int)font & 0xFF000000;
    if ((ftop != 0x80000000) && (((unsigned int)font & 0xFF800000) != 0x81000000)) f9 = 0;
    if (f9 == 0 && (((unsigned int)font & 0xF8000000) != 0x90000000)) f8 = 0;
    if (f8 == 0 && (ftop != 0xC0000000)) f7 = 0;
    if (f7 == 0 && (((unsigned int)font & 0xFF800000) != 0xC1000000)) f6 = 0;
    if (f6 == 0 && (((unsigned int)font & 0xF8000000) != 0xD0000000)) f5 = 0;
    if (f5 == 0 && (((unsigned int)font & 0xFFFFC000) != 0xE0000000)) f4 = 0;
    if (f4 == 0) ((void (*)(const char *, int, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(panicData, 0x86, panicData + 0x4C, font);

    *(void **)((char *)writer + 0x48) = font;
}

extern "C" int GetFont__Q36nw4hbm2ut10CharWriterCFv(int arg0) {
    int var_r5 = 1, var_r6 = 1, var_r7 = 1, var_r8 = 1, var_r9 = 1, var_r10 = 1;
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    if (temp_r11 + 0x80000000U >= 1U && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) >= 1U) var_r10 = 0;
    if (var_r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) >= 1U) var_r9 = 0;
    if (var_r9 == 0 && temp_r11 + 0x40000000U >= 1U) var_r8 = 0;
    if (var_r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) >= 1U) var_r7 = 0;
    if (var_r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) >= 1U) var_r6 = 0;
    if (var_r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) >= 1U) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x97, lbl_8032818C, arg0);
    return *(int *)((char *)arg0 + 0x48);
}

#pragma push
#pragma opt_propagation off
extern "C" void SetupGX__Q36nw4hbm2ut10CharWriterFv(void *arg0) {
    const char *base = lbl_80328178;
    void *arg0_ptr = arg0;
    unsigned int arg0_int = (unsigned int)arg0;
    unsigned char sp20[4], sp1C[4], sp18[4], sp14[4], sp10[4], spC[4], sp8[4];
    unsigned int temp_r30;
    unsigned int temp_r3;
    unsigned int temp_r4;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    int var_r10;
    int var_r5_2;
    SetupGXFontType *temp_r3_2;
    int type;

    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    temp_r30 = arg0_int & 0xFF000000U;
    if (temp_r30 != 0x80000000U && (arg0_int & 0xFF800000U) != 0x81000000U) {
        var_r10 = 0;
    }
    if (var_r10 == 0 && (arg0_int & 0xF8000000U) != 0x90000000U) {
        var_r9 = 0;
    }
    if (var_r9 == 0 && temp_r30 != 0xC0000000U) {
        var_r8 = 0;
    }
    if (var_r8 == 0 && (arg0_int & 0xFF800000U) != 0xC1000000U) {
        var_r7 = 0;
    }
    if (var_r7 == 0 && (arg0_int & 0xF8000000U) != 0xD0000000U) {
        var_r6 = 0;
    }
    if (var_r6 == 0 && (arg0_int & 0xFFFFC000U) != 0xE0000000U) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0xAD, base + 0x14, arg0_int);
    }
    var_r5_2 = 0;
    if (temp_r30 == 0x80000000U ||
        (temp_r4 = arg0_int & 0xFF800000U) == 0x81000000U ||
        (temp_r3 = arg0_int & 0xF8000000U) == 0x90000000U ||
        temp_r30 == 0xC0000000U ||
        temp_r4 == 0xC1000000U ||
        temp_r3 == 0xD0000000U ||
        (arg0_int & 0xFFFFC000U) == 0xE0000000U) {
        var_r5_2 = 1;
    }
    if (var_r5_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x12C, base + 0x14, arg0_int);
    }
    (*(int *)((signed char*)(&lbl_8041D4E0) + (0))) = 0xFF;
    (*(int *)((signed char*)(&lbl_8041D4E0) + (4))) = 0;
    if (*(int*)((char*)arg0 + 0) != 0 || (unsigned int)(*(int*)((char*)arg0 + 4) + 0x10000) != 0xFFFF) {
        sp20[0] = ((unsigned char*)arg0)[0];
        sp20[1] = ((unsigned char*)arg0)[1];
        sp20[2] = ((unsigned char*)arg0)[2];
        sp20[3] = ((unsigned char*)arg0)[3];
        sp1C[0] = ((unsigned char*)arg0)[4];
        sp1C[1] = ((unsigned char*)arg0)[5];
        sp1C[2] = ((unsigned char*)arg0)[6];
        sp1C[3] = ((unsigned char*)arg0)[7];
        SetupGXWithColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color((unsigned int)&sp20[0], (unsigned int)&sp1C[0]);
        return;
    }
    temp_r3_2 = (SetupGXFontType *)(*(void ***)((signed char*)(arg0) + (0x48)));
    if (temp_r3_2 != 0) {
        type = temp_r3_2->GetType();
        switch (type) {
        case 0:
        case 1:
            if ((signed char) lbl_8055DE90 == 0) {
                    *(int *)&lbl_8055DE94 = 0;
                    __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
                    lbl_8055DE90 = 1;
                }
                sp18[0] = (unsigned char) lbl_8055DE94;
                sp18[1] = lbl_8055DE95;
                sp18[2] = lbl_8055DE96;
                sp18[3] = lbl_8055DE97;
                ((void (*)(int, void*, float, float, float, float))GXSetFog)(0, &sp18[0], lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
                GXSetTevSwapModeTable(0, 0, 1, 2, 3);
                GXSetZTexture(0, 0x11, 0);
                GXSetNumChans(1);
                GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
                GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
                GXSetNumTexGens(1);
                GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
                GXSetNumIndStages(0);
                GXSetBlendMode(1, 4, 5, 0xF);
                GXSetNumTevStages(1);
                GXSetTevDirect(0);
                GXSetTevSwapMode(0, 0, 0);
                GXSetTevOrder(0, 0, 0, 4);
                GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
                GXSetTevAlphaIn(0, 7, 4, 5, 7);
                GXSetTevColorOp(0, 0, 0, 0, 1, 0);
                GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
                GXSetVtxAttrFmt(0, 9, 1, 4, 0);
                GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
                GXSetVtxAttrFmt(0, 0xD, 1, 2, 0xF);
                GXClearVtxDesc();
                GXSetVtxDesc(9, 1);
                GXSetVtxDesc(0xB, 1);
                GXSetVtxDesc(0xD, 1);
                return;
        case 2:
        case 3:
            if ((signed char) lbl_8055DE90 == 0) {
                *(int *)&lbl_8055DE94 = 0;
                __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
                lbl_8055DE90 = 1;
            }
            sp14[0] = (unsigned char) lbl_8055DE94;
            sp14[1] = lbl_8055DE95;
            sp14[2] = lbl_8055DE96;
            sp14[3] = lbl_8055DE97;
            ((void (*)(int, void*, float, float, float, float))GXSetFog)(0, &sp14[0], lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
            GXSetTevSwapModeTable(0, 0, 1, 2, 3);
            GXSetZTexture(0, 0x11, 0);
            GXSetNumChans(1);
            GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
            GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
            GXSetNumTexGens(1);
            GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
            GXSetNumIndStages(0);
            GXSetBlendMode(1, 4, 5, 0xF);
            GXSetNumTevStages(1);
            GXSetTevDirect(0);
            GXSetTevSwapMode(0, 0, 0);
            GXSetTevOrder(0, 0, 0, 4);
            GXSetTevOp(0, 0);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
            GXSetVtxAttrFmt(0, 0xD, 1, 2, 0xF);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(0xB, 1);
            GXSetVtxDesc(0xD, 1);
            return;
        case 4:
        case 5:
        case 6:
            if ((signed char) lbl_8055DE90 == 0) {
                *(int *)&lbl_8055DE94 = 0;
                __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
                lbl_8055DE90 = 1;
            }
            sp10[0] = (unsigned char) lbl_8055DE94;
            sp10[1] = lbl_8055DE95;
            sp10[2] = lbl_8055DE96;
            sp10[3] = lbl_8055DE97;
            ((void (*)(int, void*, float, float, float, float))GXSetFog)(0, &sp10[0], lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
            GXSetTevSwapModeTable(0, 0, 1, 2, 3);
            GXSetZTexture(0, 0x11, 0);
            GXSetNumChans(1);
            GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
            GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
            GXSetNumTexGens(1);
            GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
            GXSetNumIndStages(0);
            GXSetBlendMode(1, 4, 5, 0xF);
            GXSetNumTevStages(1);
            GXSetTevDirect(0);
            GXSetTevSwapMode(0, 0, 0);
            GXSetTevOrder(0, 0, 0, 4);
            GXSetTevOp(0, 0);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
            GXSetVtxAttrFmt(0, 0xD, 1, 2, 0xF);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(0xB, 1);
            GXSetVtxDesc(0xD, 1);
            return;
        default:
            Warning__Q26nw4hbm2dbFPCciPCce(base, 0xCF, base + 0x84, type);
            if ((signed char) lbl_8055DE90 == 0) {
                *(int *)&lbl_8055DE94 = 0;
                __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
                lbl_8055DE90 = 1;
            }
            spC[0] = (unsigned char) lbl_8055DE94;
            spC[1] = lbl_8055DE95;
            spC[2] = lbl_8055DE96;
            spC[3] = lbl_8055DE97;
            ((void (*)(int, void*, float, float, float, float))GXSetFog)(0, &spC[0], lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
            GXSetTevSwapModeTable(0, 0, 1, 2, 3);
            GXSetZTexture(0, 0x11, 0);
            GXSetNumChans(1);
            GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
            GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
            GXSetNumTexGens(1);
            GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
            GXSetNumIndStages(0);
            GXSetBlendMode(1, 4, 5, 0xF);
            GXSetNumTevStages(1);
            GXSetTevDirect(0);
            GXSetTevSwapMode(0, 0, 0);
            GXSetTevOrder(0, 0, 0, 4);
            GXSetTevOp(0, 0);
            GXSetVtxAttrFmt(0, 9, 1, 4, 0);
            GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
            GXSetVtxAttrFmt(0, 0xD, 1, 2, 0xF);
            GXClearVtxDesc();
            GXSetVtxDesc(9, 1);
            GXSetVtxDesc(0xB, 1);
            GXSetVtxDesc(0xD, 1);
            return;
        }
    }
    if ((signed char) lbl_8055DE90 == 0) {
        *(int *)&lbl_8055DE94 = 0;
        __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
        lbl_8055DE90 = 1;
    }
    sp8[0] = (unsigned char) lbl_8055DE94;
    sp8[1] = lbl_8055DE95;
    sp8[2] = lbl_8055DE96;
    sp8[3] = lbl_8055DE97;
    ((void (*)(int, void*, float, float, float, float))GXSetFog)(0, &sp8[0], lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
    GXSetTevSwapModeTable(0, 0, 1, 2, 3);
    GXSetZTexture(0, 0x11, 0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumIndStages(0);
    GXSetBlendMode(1, 4, 5, 0xF);
    GXSetNumTevStages(1);
    GXSetTevDirect(0);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 2, 0xF);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
}
#pragma push
#pragma processor 750
#pragma paired_single off
extern "C" void SetColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(void *arg0, void *arg1, void *arg2) {
    int var_r5 = 1;
    int var_r6 = 1;
    int var_r7 = 1;
    int var_r8 = 1;
    int var_r9 = 1;
    int var_r10 = 1;
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    unsigned char c7, c6, c5, c4, c3, c2, c1, c0;
    if (temp_r11 != 0x80000000U && (((unsigned int)arg0 & 0xFF800000U) != 0x81000000U))
        var_r10 = 0;
    if (var_r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) != 0x90000000U))
        var_r9 = 0;
    if (var_r9 == 0 && temp_r11 != 0xC0000000U)
        var_r8 = 0;
    if (var_r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) != 0xC1000000U))
        var_r7 = 0;
    if (var_r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) != 0xD0000000U))
        var_r6 = 0;
    if (var_r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) != 0xE0000000U))
        var_r5 = 0;
    if (var_r5 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0xEB, lbl_8032818C, arg0);
    c0 = ((unsigned char *)arg1)[0];
    c1 = ((unsigned char *)arg1)[1];
    c2 = ((unsigned char *)arg1)[2];
    c3 = ((unsigned char *)arg1)[3];
    c4 = ((unsigned char *)arg2)[0];
    c5 = ((unsigned char *)arg2)[1];
    c6 = ((unsigned char *)arg2)[2];
    c7 = ((unsigned char *)arg2)[3];
    ((unsigned char *)arg0)[0] = c0;
    ((unsigned char *)arg0)[1] = c1;
    ((unsigned char *)arg0)[2] = c2;
    ((unsigned char *)arg0)[3] = c3;
    ((unsigned char *)arg0)[4] = c4;
    ((unsigned char *)arg0)[5] = c5;
    ((unsigned char *)arg0)[6] = c6;
    ((unsigned char *)arg0)[7] = c7;
}
#pragma pop
void nw4hbm::ut::CharWriter::SetGradationMode(GradationMode mode) {
    const char *base = lbl_80328178;
    unsigned int top = (unsigned int)this & 0xFF000000U;
    unsigned int addr = (unsigned int)this;
    unsigned char *self = (unsigned char *)this;
    int m = (int)mode;
    int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
    if (top != 0x80000000U && (addr & 0xFF800000U) != 0x81000000U) f = 0;
    if (f == 0 && (addr & 0xF8000000U) != 0x90000000U) e = 0;
    if (e == 0 && top != 0xC0000000U) d = 0;
    if (d == 0 && (addr & 0xFF800000U) != 0xC1000000U) c = 0;
    if (c == 0 && (addr & 0xF8000000U) != 0xD0000000U) b = 0;
    if (b == 0 && (addr & 0xFFFFC000U) != 0xE0000000U) a = 0;
    if (a == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x163, base + 0x14, self);
    int v = 0;
    if (m >= 0 && m <= 2) v = 1;
    if (v == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x164, base + 0xb8, m, 0, 2);
    *(int *)(self + 0x20) = m;
    int valid = 0;
    if (top == 0x80000000U && (addr & 0xFF800000U) == 0x81000000U && (addr & 0xF8000000U) == 0x90000000U && top == 0xC0000000U && (addr & 0xFF800000U) == 0xC1000000U && (addr & 0xF8000000U) == 0xD0000000U && (addr & 0xFFFFC000U) == 0xE0000000U) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x4DA, base + 0x14, self);
    self[8] = self[0x18]; self[9] = self[0x19]; self[0xA] = self[0x1A]; self[0xB] = self[0x1B];
    unsigned char *source1, *source2, *source3;
    if (*(int *)(self + 0x20) != 1) source1 = self + 0x18; else source1 = self + 0x1C;
    self[0xC] = source1[0]; self[0xD] = source1[1]; self[0xE] = source1[2]; self[0xF] = source1[3];
    if (*(int *)(self + 0x20) != 2) source2 = self + 0x18; else source2 = self + 0x1C;
    self[0x10] = source2[0]; self[0x11] = source2[1]; self[0x12] = source2[2]; self[0x13] = source2[3];
    if (*(int *)(self + 0x20) == 0) source3 = self + 0x18; else source3 = self + 0x1C;
    self[0x14] = source3[0]; self[0x15] = source3[1]; self[0x16] = source3[2];
    int alpha = *(volatile unsigned char *)(self + 0x42);
    int product_b = self[0xB] * alpha, product_f = self[0xF] * alpha;
    int product_13 = self[0x13] * alpha, product_17 = source3[3] * alpha;
    self[0xB] = product_b / 255; self[0xF] = product_f / 255;
    self[0x13] = product_13 / 255; self[0x17] = product_17 / 255;
}

void nw4hbm::ut::CharWriter::SetTextColor(nw4hbm::ut::Color color) {
    unsigned int address = (unsigned int)this;
    unsigned int top = address & 0xFF000000U;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned char *self = (unsigned char *)this;
    unsigned char *source3, *source1, *source2;
    if (top != 0x80000000U && (address & 0xFF800000U) != 0x81000000U)
        r10 = 0;
    if (r10 == 0 && (address & 0xF8000000U) != 0x90000000U)
        r9 = 0;
    if (r9 == 0 && top != 0xC0000000U)
        r8 = 0;
    if (r8 == 0 && (address & 0xFF800000U) != 0xC1000000U)
        r7 = 0;
    if (r7 == 0 && (address & 0xF8000000U) != 0xD0000000U)
        r6 = 0;
    if (r6 == 0 && (address & 0xFFFFC000U) != 0xE0000000U)
        r5 = 0;
    if (r5 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x185, lbl_8032818C, this);
    self[0x18] = color.r;
    self[0x19] = color.g;
    self[0x1A] = color.b;
    self[0x1B] = color.a;
    r5 = 0;
    if (top == 0x80000000U ||
        (address & 0xFF800000U) == 0x81000000U ||
        (address & 0xF8000000U) == 0x90000000U ||
        top == 0xC0000000U ||
        (address & 0xFF800000U) == 0xC1000000U ||
        (address & 0xF8000000U) == 0xD0000000U ||
        (address & 0xFFFFC000U) == 0xE0000000U)
        r5 = 1;
    if (r5 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x4DA, lbl_8032818C, this);
    self[8] = self[0x18];
    self[9] = self[0x19];
    self[0xA] = self[0x1A];
    self[0xB] = self[0x1B];
    if (*(int *)(self + 0x20) != 1)
        source1 = self + 0x18;
    else
        source1 = self + 0x1C;
    self[0xC] = source1[0];
    self[0xD] = source1[1];
    self[0xE] = source1[2];
    self[0xF] = source1[3];
    if (*(int *)(self + 0x20) != 2)
        source2 = self + 0x18;
    else
        source2 = self + 0x1C;
    self[0x10] = source2[0];
    self[0x11] = source2[1];
    self[0x12] = source2[2];
    self[0x13] = source2[3];
    if (*(int *)(self + 0x20) == 0)
        source3 = self + 0x18;
    else
        source3 = self + 0x1C;
    self[0x14] = source3[0];
    self[0x15] = source3[1];
    self[0x16] = source3[2];
    {
        int alpha = *(volatile unsigned char *)(self + 0x42);
        int product_b = self[0xB] * alpha;
        int product_f = self[0xF] * alpha;
        int product_13 = self[0x13] * alpha;
        int product_17 = source3[3] * alpha;
        self[0xB] = product_b / 255;
        self[0xF] = product_f / 255;
        self[0x13] = product_13 / 255;
        self[0x17] = product_17 / 255;
    }
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv(int arg0) {
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    int var_r5 = 1, var_r6 = 1, var_r7 = 1, var_r8 = 1, var_r9 = 1, var_r10 = 1;
    if ((temp_r11 + 0x80000000U) >= 1U && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) >= 1U) var_r10 = 0;
    if (var_r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) >= 1U) var_r9 = 0;
    if (var_r9 == 0 && temp_r11 + 0x40000000U >= 1U) var_r8 = 0;
    if (var_r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) >= 1U) var_r7 = 0;
    if (var_r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) >= 1U) var_r6 = 0;
    if (var_r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x20A, lbl_8032818C, arg0);
    return *(float *)((char *)(unsigned int)arg0 + 0x24);
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(void *arg0) {
    int var_r5 = 1, var_r6 = 1, var_r7 = 1, var_r8 = 1, var_r9 = 1, var_r10 = 1;
    unsigned int p = (unsigned int)arg0;
    unsigned int temp_r11 = p & 0xFF000000U;
    if (temp_r11 + 0x80000000U >= 1U && ((p & 0xFF800000U) + 0x7F000000U) >= 1U) var_r10 = 0;
    if (var_r10 == 0 && ((p & 0xF8000000U) + 0x70000000U) >= 1U) var_r9 = 0;
    if (var_r9 == 0 && temp_r11 + 0x40000000U >= 1U) var_r8 = 0;
    if (var_r8 == 0 && ((p & 0xFF800000U) + 0x3F000000U) >= 1U) var_r7 = 0;
    if (var_r7 == 0 && ((p & 0xF8000000U) + 0x30000000U) >= 1U) var_r6 = 0;
    if (var_r6 == 0 && ((p & 0xFFFFC000U) + 0x20000000U) >= 1U) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x21A, lbl_8032818C, arg0);
    return *(float *)((char *)arg0 + 0x28);
}

void nw4hbm::ut::CharWriter::SetFontSize(float farg0, float farg1) {
    float x = farg0, y = farg1;
    const char *base = lbl_80328178;
    register unsigned int top = (unsigned int)this & 0xFF000000U;
    register int r5, r6, r7, r8, r9, r10;
    r5 = 1; r6 = 1; r7 = 1; r8 = 1; r9 = 1; r10 = 1;
    if (top != 0x80000000U &&
        ((unsigned int)this & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)this & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)this & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)this & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)this & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x22F, base + 0x14, this);

    {
    register int r4 = 1, r5b = 1;
    register unsigned int fontAddress = *(unsigned int *)((unsigned char *)this + 0x48);
    register int r7b = 1, r8b = 1, r9b = 1, r10b = 1;
    register unsigned int fontTop = fontAddress & 0xFF000000U;
    if (fontTop != 0x80000000U &&
        (fontAddress & 0xFF800000U) != 0x81000000U) r10b = 0;
    if (r10b == 0 && (fontAddress & 0xF8000000U) != 0x90000000U) r9b = 0;
    if (r9b == 0 && fontTop != 0xC0000000U) r8b = 0;
    if (r8b == 0 && (fontAddress & 0xFF800000U) != 0xC1000000U) r7b = 0;
    if (r7b == 0 && (fontAddress & 0xF8000000U) != 0xD0000000U) r5b = 0;
    if (r5b == 0 && (fontAddress & 0xFFFFC000U) != 0xE0000000U) r4 = 0;
    if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x230, base + 0xF4);

    }
    if (((FontForWidth *)*(void **)((char *)this + 0x48))->v1() < 1) {
        int width = ((FontForWidth *)*(void **)((char *)this + 0x48))->v1();
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x231, base + 0x12C, width, 1);
    }
    if (((FontForWidth *)*(void **)((char *)this + 0x48))->v2() < 1) {
        int height = ((FontForWidth *)*(void **)((char *)this + 0x48))->v2();
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x232, base + 0x180, height, 1);
    }
    y /= (float)((FontForWidth *)*(void **)((char *)this + 0x48))->v2();
    x /= (float)((FontForWidth *)*(void **)((char *)this + 0x48))->v1();

    r6 = 0;
    if (top == 0x80000000U ||
        ((unsigned int)this & 0xFF800000U) == 0x81000000U ||
        ((unsigned int)this & 0xF8000000U) == 0x90000000U ||
        top == 0xC0000000U ||
        ((unsigned int)this & 0xFF800000U) == 0xC1000000U ||
        ((unsigned int)this & 0xF8000000U) == 0xD0000000U ||
        ((unsigned int)this & 0xFFFFC000U) == 0xE0000000U) r6 = 1;
    if (r6 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x1E7, base + 0x14, this);
    *(float *)((char *)this + 0x24) = x;
    *(float *)((char *)this + 0x28) = y;
}

#pragma push
#pragma opt_propagation off
extern "C" float GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    struct FontVTable {
        virtual void f0();
        virtual int GetWidth() const;
    };
    const char *base = lbl_80328178;
    void *self = arg0;

    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)self & 0xFF000000U;
    if (top != 0x80000000U && ((unsigned int)self & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)self & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)self & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)self & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)self & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) {
        void *s = self;
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x259, base + 0x14, s);
    }

    {
        int f4 = 1, f5 = 1;
        void *font = *(void **)((char *)self + 0x48);
        int f7 = 1, f8 = 1, f9 = 1, f10 = 1;
        unsigned int top2 = (unsigned int)font & 0xFF000000U;
        if (top2 != 0x80000000U && ((unsigned int)font & 0xFF800000U) != 0x81000000U) f10 = 0;
        if (f10 == 0 && ((unsigned int)font & 0xF8000000U) != 0x90000000U) f9 = 0;
        if (f9 == 0 && top2 != 0xC0000000U) f8 = 0;
        if (f8 == 0 && ((unsigned int)font & 0xFF800000U) != 0xC1000000U) f7 = 0;
        if (f7 == 0 && ((unsigned int)font & 0xF8000000U) != 0xD0000000U) f5 = 0;
        if (f5 == 0 && ((unsigned int)font & 0xFFFFC000U) != 0xE0000000U) f4 = 0;
        if (f4 == 0) {
            void *msg = (void *)(base + 0xF4);
            Panic__Q26nw4hbm2dbFPCciPCce(base, 0x25A, (const char *)msg);
        }
    }

    const FontVTable *f = *(const FontVTable **)((char *)self + 0x48);
    int width = f->GetWidth();
    return *(float *)((char *)self + 0x24) * (float)width;
}
#pragma push
#pragma opt_common_subs off
extern "C" float GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(void *arg0) {
    struct FontVTable {
        virtual void f0();
        virtual void f1();
        virtual int GetWidth() const;
    };
    const char *base = lbl_80328178;
    void *self = arg0;

    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)self & 0xFF000000U;
    if (top != 0x80000000U && ((unsigned int)self & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)self & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)self & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)self & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)self & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) {
        void *s = self;
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x26A, &base[0x14], s);
    }

    {
        int f4 = 1, f5 = 1;
        void *font = *(void **)((char *)self + 0x48);
        int f7 = 1, f8 = 1, f9 = 1, f10 = 1;
        unsigned int top2 = (unsigned int)font & 0xFF000000U;
        if (top2 != 0x80000000U && ((unsigned int)font & 0xFF800000U) != 0x81000000U) f10 = 0;
        if (f10 == 0 && ((unsigned int)font & 0xF8000000U) != 0x90000000U) f9 = 0;
        if (f9 == 0 && top2 != 0xC0000000U) f8 = 0;
        if (f8 == 0 && ((unsigned int)font & 0xFF800000U) != 0xC1000000U) f7 = 0;
        if (f7 == 0 && ((unsigned int)font & 0xF8000000U) != 0xD0000000U) f5 = 0;
        if (f5 == 0 && ((unsigned int)font & 0xFFFFC000U) != 0xE0000000U) f4 = 0;
        if (f4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x26B, &base[0xF4]);
    }

    const FontVTable *f = *(const FontVTable **)((char *)self + 0x48);
    int width = f->GetWidth();
    return *(float *)((char *)self + 0x28) * (float)width;
}
#pragma pop
extern "C" float GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801058DC(void *arg0) {
    struct FontVTable {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual int GetWidth() const;
    };
    const char *base = lbl_80328178;
    void *self = arg0;

    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int top = (unsigned int)self & 0xFF000000U;
    if (top != 0x80000000U && ((unsigned int)self & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)self & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)self & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)self & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)self & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) ((void (*)(const char *, int, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base, 0x27B, base + 0x14, self);

    {
        int f4 = 1, f5 = 1;
        void *font = *(void **)((char *)self + 0x48);
        int f7 = 1, f8 = 1, f9 = 1, f10 = 1;
        unsigned int top2 = (unsigned int)font & 0xFF000000U;
        if (top2 != 0x80000000U && ((unsigned int)font & 0xFF800000U) != 0x81000000U) f10 = 0;
        if (f10 == 0 && ((unsigned int)font & 0xF8000000U) != 0x90000000U) f9 = 0;
        if (f9 == 0 && top2 != 0xC0000000U) f8 = 0;
        if (f8 == 0 && ((unsigned int)font & 0xFF800000U) != 0xC1000000U) f7 = 0;
        if (f7 == 0 && ((unsigned int)font & 0xF8000000U) != 0xD0000000U) f5 = 0;
        if (f5 == 0 && ((unsigned int)font & 0xFFFFC000U) != 0xE0000000U) f4 = 0;
        if (f4 == 0) ((void (*)(const char *, int, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base, 0x27C, base + 0xF4, font);
    }

    const FontVTable *f = *(const FontVTable **)((char *)self + 0x48);
    int width = f->GetWidth();
    return *(float *)((char *)self + 0x28) * (float)width;
}

#pragma push
#pragma processor 750
#pragma paired_single off
extern "C" unsigned char IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    register int var_r5 = 1;
    register int var_r6 = 1;
    register int var_r7 = 1;
    register int var_r8 = 1;
    register int var_r9 = 1;
    register int var_r10 = 1;
    register unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    if ((temp_r11 + 0x80000000U) >= 1U &&
        ((((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) >= 1U))
        var_r10 = 0;
    if (var_r10 == 0 &&
        (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) >= 1U)
        var_r9 = 0;
    if (var_r9 == 0 && (temp_r11 + 0x40000000U) >= 1U)
        var_r8 = 0;
    if (var_r8 == 0 &&
        (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) >= 1U)
        var_r7 = 0;
    if (var_r7 == 0 &&
        (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) >= 1U)
        var_r6 = 0;
    if (var_r6 == 0 &&
        (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) >= 1U)
        var_r5 = 0;
    if (var_r5 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x2E2, lbl_8032818C, arg0);
    return *(unsigned char *)((char *)arg0 + 0x43);
}
#pragma pop
extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(void *arg0) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1; var_r6 = 1; var_r7 = 1; var_r8 = 1; var_r9 = 1; var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x301, lbl_8032818C, arg0);
    return *(float *)((char *)arg0 + 0x44);
}

extern "C" double lbl_80561158;
extern "C" float lbl_80561160;
float nw4hbm::ut::CharWriter::Print(unsigned short character) {
    const char *base = lbl_80328178;
    register unsigned int top = (unsigned int)this & 0xFF000000U;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    unsigned int fontAddress;
    unsigned char glyph[0x18];
    float advance;
    float xOffset;
    if (top != 0x80000000U && ((unsigned int)this & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)this & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)this & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)this & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)this & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x328, base + 0x14, this);
    fontAddress = *(unsigned int *)((unsigned char *)this + 0x48);
    top = fontAddress & 0xFF000000U;
    {
        int r4 = 1, r5b = 1, r7b = 1, r8b = 1, r9b = 1, r10b = 1;
        if (top != 0x80000000U && (fontAddress & 0xFF800000U) != 0x81000000U) r10b = 0;
        if (r10b == 0 && (fontAddress & 0xF8000000U) != 0x90000000U) r9b = 0;
        if (r9b == 0 && top != 0xC0000000U) r8b = 0;
        if (r8b == 0 && (fontAddress & 0xFF800000U) != 0xC1000000U) r7b = 0;
        if (r7b == 0 && (fontAddress & 0xF8000000U) != 0xD0000000U) r5b = 0;
        if (r5b == 0 && (fontAddress & 0xFFFFC000U) != 0xE0000000U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x329, base + 0xF4);
    }
    if (character == 0xFFFF) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x32A, base + 0x1D0);
    ((PrintFont *)*(void **)((unsigned char *)this + 0x48))->GetGlyph(glyph, character);
    if (*(unsigned char *)((unsigned char *)this + 0x43) != 0) {
        float scale = *(float *)((unsigned char *)this + 0x24);
        advance = *(float *)((unsigned char *)this + 0x44);
        xOffset = ((advance - (float)(signed char)glyph[6] * scale) * lbl_80561160) +
                  (float)(signed char)glyph[4] * scale;
    } else {
        float scale = *(float *)((unsigned char *)this + 0x24);
        advance = (float)(signed char)glyph[6] * scale;
        xOffset = (float)(signed char)glyph[4] * scale;
    }
    PrintGlyph(*(float *)((unsigned char *)this + 0x2C) + xOffset,
               *(float *)((unsigned char *)this + 0x30),
               *(float *)((unsigned char *)this + 0x34),
               *(const Glyph *)glyph);
    *(float *)((unsigned char *)this + 0x2C) += advance;
    return advance;
}

extern "C" const char lbl_80328178[];
extern "C" const char lbl_8032818C[];
extern "C" void SetCursor__Q36nw4hbm2ut10CharWriterFff(void *arg0, float x, float y) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000;
    int r10 = 1, r9 = 1, r8 = 1, r7 = 1, r6 = 1, r5 = 1;
    if (top + 0x80000000U != 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0) r10 = 0;
    if (r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0) r9 = 0;
    if (r9 == 0 && top + 0x40000000U != 0) r8 = 0;
    if (r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0) r7 = 0;
    if (r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0) r6 = 0;
    if (r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x36F, "this", arg0);
    *(float *)((char *)arg0 + 0x2C) = x;
    *(float *)((char *)arg0 + 0x30) = y;
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf(void *arg0, float farg0) {
    unsigned int temp_r11;
    int var_r10, var_r5, var_r6, var_r7, var_r8, var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = var_r6 = var_r7 = var_r8 = var_r9 = var_r10 = 1;
    if ((temp_r11 + 0x80000000U >= 1U) && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U >= 1U)) var_r10 = 0;
    if (var_r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U >= 1U)) var_r9 = 0;
    if (var_r9 == 0 && temp_r11 + 0x40000000U >= 1U) var_r8 = 0;
    if (var_r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U >= 1U)) var_r7 = 0;
    if (var_r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U >= 1U)) var_r6 = 0;
    if (var_r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U >= 1U) ) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x3C5, "this", arg0);
    *(float *)((char *)arg0 + 0x2C) = farg0;
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(void *arg0, float farg0) {
    int var_r5 = 1; int var_r6 = 1; int var_r7 = 1; int var_r8 = 1; int var_r9 = 1; int var_r10 = 1;
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    if (temp_r11 != 0x80000000U && (((unsigned int)arg0 & 0xFF800000U) != 0x81000000U)) var_r10 = 0;
    if (var_r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) != 0x90000000U)) var_r9 = 0;
    if (var_r9 == 0 && temp_r11 != 0xC0000000U) var_r8 = 0;
    if (var_r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) != 0xC1000000U)) var_r7 = 0;
    if (var_r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) != 0xD0000000U)) var_r6 = 0;
    if (var_r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) != 0xE0000000U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x3D5, lbl_8032818C, arg0);
    *(float*)((char*)arg0 + 0x30) = farg0;
}

extern "C" void MoveCursorX__Q36nw4hbm2ut10CharWriterFf(void *arg0, float dx) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000;
    int r10=1,r9=1,r8=1,r7=1,r6=1,r5=1;
    if (top+0x80000000U != 0 && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0) r10=0;
    if (r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0) r9=0;
    if (r9==0 && top+0x40000000U!=0) r8=0;
    if (r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0) r7=0;
    if (r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0) r6=0;
    if (r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp",0x3F5,"this",arg0);
    *(float *)((char *)arg0+0x2C) += dx;
}

extern "C" void MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(void *arg0, float dx) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r10 = 1;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x405, lbl_8032818C, arg0);
    *(float *)((char *)arg0 + 0x30) += dx;
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(void *arg0) {
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1; var_r6 = 1; var_r7 = 1; var_r8 = 1; var_r9 = 1; var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) > 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) > 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) > 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) > 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) > 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) > 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) > 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178, 0x425, lbl_8032818C, arg0);
    return *(float *)((char *)arg0 + 0x2C);
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(int arg0) {
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 int var_r10=1;
 int var_r9=1;
 int var_r8=1;
 int var_r7=1;
 int var_r6=1;
 int var_r5=1;
 if ((temp_r11+0x80000000U)!=0U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U) var_r10=0;
 if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U) var_r9=0;
 if (var_r9==0 && temp_r11+0x40000000U!=0U) var_r8=0;
 if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U) var_r7=0;
 if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U) var_r6=0;
 if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U) var_r5=0;
 if (var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x435,lbl_8032818C,arg0);
 return *(float*)((char*)arg0+0x30);
}

extern "C" void GXBegin(int, int, int);
extern "C" void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, int);
extern "C" void GXInitTexObjLOD(void *, int, int, float, float, float, int, int, int);
extern "C" void GXLoadTexObj(void *, int);
#pragma processor gekko
void nw4hbm::ut::CharWriter::PrintGlyph(float x, float y, float z, const Glyph &glyph) {
    struct TexCache { int a; unsigned int b; int c, d; };
    const char *base = lbl_80328178;
    unsigned int top0 = (unsigned int)this & 0xFF000000U;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    if (top0 != 0x80000000U && ((unsigned int)this & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && ((unsigned int)this & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && top0 != 0xC0000000U) r8 = 0;
    if (r8 == 0 && ((unsigned int)this & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && ((unsigned int)this & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && ((unsigned int)this & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x467, base + 0x14, this);
    unsigned int top1 = (unsigned int)&glyph & 0xFF000000U;
    int s4 = 1, s5 = 1, s6 = 1, s7 = 1, s8 = 1, s9 = 1;
    if (top1 != 0x80000000U && ((unsigned int)&glyph & 0xFF800000U) != 0x81000000U) s9 = 0;
    if (s9 == 0 && ((unsigned int)&glyph & 0xF8000000U) != 0x90000000U) s8 = 0;
    if (s8 == 0 && top1 != 0xC0000000U) s7 = 0;
    if (s7 == 0 && ((unsigned int)&glyph & 0xFF800000U) != 0xC1000000U) s6 = 0;
    if (s6 == 0 && ((unsigned int)&glyph & 0xF8000000U) != 0xD0000000U) s5 = 0;
    if (s5 == 0 && ((unsigned int)&glyph & 0xFFFFC000U) != 0xE0000000U) s4 = 0;
    if (s4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x468, base + 0x210, &glyph);
    unsigned char *g = (unsigned char *)&glyph;
    unsigned char *self = (unsigned char *)this;
    if (*(unsigned short *)(g + 0xC) < 1) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x469, base + 0x248, *(unsigned short *)(g + 0xC), 1);
    if (*(unsigned short *)(g + 0xE) < 1) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x46A, base + 0x290, *(unsigned short *)(g + 0xE), 1);
    unsigned char gu = g[5];
    unsigned int gx = *(unsigned short *)(g + 0x10);
    unsigned char gv = g[7];
    unsigned int gy = *(unsigned short *)(g + 0x12);
    unsigned int gw = *(unsigned short *)(g + 0xC);
    unsigned int gh = *(unsigned short *)(g + 0xE);
    unsigned short u0 = (gx << 15) / gw;
    unsigned short v0 = (gy << 15) / gh;
    float x1 = x + (float)gu * *(float *)(self + 0x24);
    unsigned short u1 = ((gx + gu) << 15) / gw;
    float y1 = y + (float)gv * *(float *)(self + 0x28);
    unsigned short v1 = ((gy + gv) << 15) / gh;
    int ok0 = 0;
    if (top0 == 0x80000000U || ((unsigned int)self & 0xFF800000U) == 0x81000000U || ((unsigned int)self & 0xF8000000U) == 0x90000000U || top0 == 0xC0000000U || ((unsigned int)self & 0xFF800000U) == 0xC1000000U || ((unsigned int)self & 0xF8000000U) == 0xD0000000U || ((unsigned int)self & 0xFFFFC000U) == 0xE0000000U) ok0 = 1;
    if (ok0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x4A8, base + 0x14, self);
    int ok1 = 0;
    if (top1 == 0x80000000U || ((unsigned int)g & 0xFF800000U) == 0x81000000U || ((unsigned int)g & 0xF8000000U) == 0x90000000U || top1 == 0xC0000000U || ((unsigned int)g & 0xFF800000U) == 0xC1000000U || ((unsigned int)g & 0xF8000000U) == 0xD0000000U || ((unsigned int)g & 0xFFFFC000U) == 0xE0000000U) ok1 = 1;
    if (ok1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x4A9, base + 0x210, g);
    TexCache tex;
    TexCache *cache = (TexCache *)lbl_8041D4E0;
    tex.a = 0; tex.b = *(unsigned int *)g; tex.c = *(int *)(self + 0x38); tex.d = *(int *)(self + 0x3C);
    int diff = 0;
    if (tex.a != cache->a || tex.b != cache->b || tex.c != cache->c || tex.d != cache->d) diff = 1;
    if (diff != 0) {
        unsigned char obj[0x20];
        GXInitTexObj(obj, *(void **)(g + 8), *(unsigned short *)(g + 0xC), *(unsigned short *)(g + 0xE), 0, 0, 0, 0);
        GXInitTexObjLOD(obj, *(int *)(self + 0x38), *(int *)(self + 0x3C), lbl_80561150, lbl_80561150, lbl_80561150, 0, 0, 0);
        GXLoadTexObj(obj, 0);
        volatile TexCache *vt = &tex;
        cache->a = vt->a; cache->b = vt->b; cache->c = vt->c; cache->d = vt->d;
    }
    GXBegin(0x80, 0, 4);
    volatile float *fifo = (volatile float *)0xCC008000;
    volatile int *fifoi = (volatile int *)0xCC008000;
    volatile unsigned short *fifos = (volatile unsigned short *)0xCC008000;
    *fifo = x; *fifo = y; *fifo = z; *fifoi = *(int *)(self + 8); *fifos = u0; *fifos = v0;
    *fifo = x1; *fifo = y; *fifo = z; *fifoi = *(int *)(self + 0xC); *fifos = u1; *fifos = v0;
    *fifo = x1; *fifo = y1; *fifo = z; *fifoi = *(int *)(self + 0x14); *fifos = u1; *fifos = v1;
    *fifo = x; *fifo = y1; *fifo = z; *fifoi = *(int *)(self + 0x10); *fifos = u0; *fifos = v1;
}
extern "C" void GXSetFog(int, void *, unsigned char, unsigned char, float, float, float, float);
extern "C" void GXSetTevSwapModeTable(int, int, int, int, int);
extern "C" void GXSetZTexture(int, int, int);
extern "C" void GXSetNumChans(int);
extern "C" void GXSetChanCtrl(int, int, int, int, int, int, int);
extern "C" void GXSetNumTexGens(int);
extern "C" void GXSetTexCoordGen2(int, int, int, int, int, int);
extern "C" void GXSetNumIndStages(int);
extern "C" void GXSetBlendMode(int, int, int, int);
extern "C" void GXSetNumTevStages(int);
extern "C" void GXSetTevDirect(int);
extern "C" void GXSetTevSwapMode(int, int, int);
extern "C" void GXSetTevOrder(int, int, int, int);
extern "C" void GXSetTevColor(int, void *, int, int, int);
extern "C" void GXSetTevColorIn(int, int, int, int, int);
extern "C" void GXSetTevAlphaIn(int, int, int, int, int);
extern "C" void GXSetTevColorOp(int, int, int, int, int, int);
extern "C" void GXSetTevAlphaOp(int, int, int, int, int, int);
extern "C" void GXSetVtxAttrFmt(int, int, int, int, int);
extern "C" void GXClearVtxDesc(void);
extern "C" void GXSetVtxDesc(int, int);
extern "C" void __register_global_object(void *, void *, void *);
extern "C" void fn_800D2DD4(void);
extern "C" unsigned char lbl_8055DE90;
extern "C" unsigned char lbl_8055DE94, lbl_8055DE95, lbl_8055DE96, lbl_8055DE97;
extern "C" float lbl_80561150;
extern "C" unsigned char lbl_8041D4D0[];
extern "C" void SetupGXWithColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(unsigned int arg0, unsigned int arg1) {
    unsigned char sp8[4], spc[4], sp10[4];
    unsigned char r, g, b;
    if ((signed char)lbl_8055DE90 == 0) {
        lbl_8055DE94 = 0;
        __register_global_object(&lbl_8055DE94, fn_800D2DD4, (void *)0x8041D4D0);
        lbl_8055DE90 = 1;
    }
    sp8[0]=lbl_8055DE94; sp8[1]=lbl_8055DE95; sp8[2]=lbl_8055DE96; sp8[3]=lbl_8055DE97;
    GXSetFog(0, sp8, lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
    GXSetTevSwapModeTable(0,0,1,2,3); GXSetZTexture(0,0x11,0); GXSetNumChans(1);
    GXSetChanCtrl(4,0,0,1,0,0,2); GXSetChanCtrl(5,0,0,0,0,0,2);
    GXSetNumTexGens(1); GXSetTexCoordGen2(0,1,4,0x3c,0,0x7d); GXSetNumIndStages(0);
    GXSetBlendMode(1,4,5,0xf); GXSetNumTevStages(2); GXSetTevDirect(0); GXSetTevDirect(1);
    GXSetTevSwapMode(0,0,0); GXSetTevSwapMode(1,0,0); GXSetTevOrder(0,0,0,0xff);
    r=((unsigned char *)&arg0)[0]; g=((unsigned char *)&arg0)[1]; b=((unsigned char *)&arg0)[2];
    sp10[0]=r; sp10[1]=g; sp10[2]=b; sp10[3]=((unsigned char *)&arg0)[3]; GXSetTevColor(1,sp10,b,g,(s32)r);
    r=((unsigned char *)&arg1)[0]; g=((unsigned char *)&arg1)[1]; b=((unsigned char *)&arg1)[2];
    spc[0]=r; spc[1]=g; spc[2]=b; spc[3]=((unsigned char *)&arg1)[3]; GXSetTevColor(2,spc,b,g,r);
    GXSetTevColorIn(0,2,4,8,0xf); GXSetTevAlphaIn(0,1,2,4,7);
    GXSetTevColorOp(0,0,0,0,1,0); GXSetTevAlphaOp(0,0,0,0,1,0);
    GXSetTevOrder(1,0xff,0xff,4); GXSetTevColorIn(1,0xf,0,0xa,0xf); GXSetTevAlphaIn(1,7,0,5,7);
    GXSetTevColorOp(1,0,0,0,1,0); GXSetTevAlphaOp(1,0,0,0,1,0);
    GXSetVtxAttrFmt(0,9,1,4,0); GXSetVtxAttrFmt(0,0xb,1,5,0); GXSetVtxAttrFmt(0,0xd,1,2,0xf);
    GXClearVtxDesc(); GXSetVtxDesc(9,1); GXSetVtxDesc(0xb,1); GXSetVtxDesc(0xd,1);
}
namespace nw4hbm { namespace ut { struct Glyph { unsigned char pad[0x14]; unsigned short x; unsigned char pad16[2]; unsigned char y; unsigned char pad19[7]; unsigned short width; unsigned short height; unsigned char pad20[0x20]; }; }}