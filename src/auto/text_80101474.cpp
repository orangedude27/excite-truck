// Code of main that had no source file yet: decomp.wtf gave it this one.
extern "C" const char lbl_80327CB8[];
extern "C" const char lbl_80327CCC[];
extern "C" void fn_800EA880(void *, int);
extern "C" int Parse__Q46nw4hbm3snd6detail8WsdTrackFPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUlb(void *, const void *, unsigned long, bool);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Release__Q46nw4hbm3snd6detail7ChannelFv(void *);
extern "C" const char lbl_80328030[];
extern "C" const char lbl_80327EE0[];
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void);
extern int Pause__Q46nw4hbm3snd6detail7AxVoiceFb(int, unsigned char);
extern int ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(int);
extern "C" void ReleaseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFi_801016C0(void *, int);
extern "C" int fn_800EAD00(void *);
extern "C" const char lbl_80328178[];
extern "C" const char lbl_8032818C[];
extern "C" unsigned char lbl_8041D4E0[];
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
namespace nw4hbm { namespace ut { struct Color { unsigned char r, g, b, a; }; struct Glyph; struct PrintFont { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void GetGlyph(void*, unsigned short); }; class CharWriter { public: enum GradationMode { GRADATION_SOLID, GRADATION_VERTICAL, GRADATION_HORIZONTAL }; void PrintGlyph(float, float, float, const Glyph&); void SetTextColor(Color); void SetTextColor(Color, Color); float Print(unsigned short); void SetGradationMode(GradationMode); void SetFontSize(float, float); void SetupGX(); int GetFont() const; }; }}
#pragma cplusplus reset
namespace nw4hbm { namespace snd { namespace detail {
class Channel { public: enum ChannelCallbackStatus { Status }; };
class WsdTrack { public: struct WsdCallback; static void ChannelCallbackFunc(Channel *, Channel::ChannelCallbackStatus, unsigned long); void Close(); int ParseNextTick(const WsdCallback *, unsigned long, bool); };
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
void PauseAllChannel__Q46nw4hbm3snd6detail8WsdTrackFb(void *arg0, unsigned char arg1) {
    void *channel = *(void **)((char *)arg0 + 0x30);
    do {
        if (*(unsigned char *)((char *)channel + 0x3A) &&
            arg1 != (unsigned int)(*(unsigned char *)((char *)channel + 0x39) != 0)) {
            *(unsigned char *)((char *)channel + 0x39) = arg1;
            Pause__Q46nw4hbm3snd6detail7AxVoiceFb(*(int *)((char *)channel + 0xE0), arg1);
        }
        channel = *(void **)((char *)channel + 0xE4);
    } while (channel != 0);
}

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
    unsigned int top=(unsigned int)arg0&0xFF000000U;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U)r10=0;
    if(r10==0&&(unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)(top+0x40000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U)r5=0;
    if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x30,base+0x18,arg0);
    unsigned int magic=*(unsigned int *)header;
    if(magic!=(unsigned int)arg1) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x3C,base+0x50,
            (signed char)(magic>>24),(signed char)(magic>>16),(signed char)(magic>>8),(signed char)magic,
            (signed char)((unsigned int)arg1>>24),(signed char)((unsigned int)arg1>>16),(signed char)((unsigned int)arg1>>8),(signed char)arg1);
        return 0;
    }
    if(*(unsigned short *)(header+4)!=0xFEFF) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x41,base+0x88);
        return 0;
    }
    unsigned short version=*(unsigned short *)(header+6);
    if(version!=arg2) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x4B,base+0xA0,
            (signed char)(version>>8),(signed char)version,(signed char)(arg2>>8),(signed char)arg2);
        return 0;
    }
    if(*(unsigned int *)(header+8)<(((unsigned int)arg3<<3)+0x10)) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x50,base+0xD0);
        return 0;
    }
    if(*(unsigned short *)(header+0xE)<arg3) {
        Warning__Q26nw4hbm2dbFPCciPCce(base,0x55,base+0xEC);
        return 0;
    }
    return 1;
}

extern "C" unsigned char ReadNextCharUTF8__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    void *reader=arg0;const char *base=lbl_80328030;unsigned int top=(unsigned int)reader&0xFF000000U;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)reader&0xFF800000U)+0x7F000000U)!=0U)r10=0;
    if(r10==0&&(unsigned int)(((unsigned int)reader&0xF8000000U)+0x70000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)(top+0x40000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(((unsigned int)reader&0xFF800000U)+0x3F000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)(((unsigned int)reader&0xF8000000U)+0x30000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)(((unsigned int)reader&0xFFFFC000U)+0x20000000U)!=0U)r5=0;
    if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x4C,base+0x18,reader);
    unsigned int p=*(unsigned int *)reader;top=p&0xFF000000U;
    int r4=1;r5=1;r6=1;r7=1;r8=1;r9=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)((p&0xFF800000U)+0x7F000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)((p&0xF8000000U)+0x70000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(top+0x40000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)((p&0xFF800000U)+0x3F000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)((p&0xF8000000U)+0x30000000U)!=0U)r5=0;
    if(r5==0&&(unsigned int)((p&0xFFFFC000U)+0x20000000U)!=0U)r4=0;
    if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x4D,base+0x50);
    unsigned char *ptr=*(unsigned char **)reader;
    unsigned char first=*ptr;
    if((first&0xC0)==0x80)Panic__Q26nw4hbm2dbFPCciPCce(base,0x4F,base+0x8C);
    if(!(first&0x80)){*(unsigned int *)reader=p+1;return first;}
    if((first&0xE0)==0xC0){unsigned char second=ptr[1];*(unsigned int *)reader=p+2;return (unsigned char)(((first&0x1F)<<6)|(second&0x3F));}
    if((first&0xF0)!=0xE0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x64,base+0xC4);
    unsigned char second=ptr[1],third=ptr[2];
    *(unsigned int *)reader=p+3;
    return (unsigned char)(((first&0x0F)<<12)|((second&0x3F)<<6)|(third&0x3F));
}

extern "C" unsigned short ReadNextCharUTF16__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    void *reader=arg0;
    const char *base=lbl_80328030;
    int temp_r11,temp_r6,var_r10,var_r10_2,var_r4,var_r5,var_r5_2,var_r6,var_r7,var_r7_2,var_r8,var_r8_2,var_r9,var_r9_2;
    unsigned short value;
    temp_r11=(unsigned int)reader&0xFF000000U;var_r5=1;var_r6=1;var_r7=1;var_r8=1;var_r9=1;var_r10=1;
    if((unsigned int)(temp_r11+0x80000000U)!=0U&&(unsigned int)(((unsigned int)reader&0xFF800000U)+0x7F000000U)!=0U)var_r10=0;
    if(var_r10==0&&(unsigned int)(((unsigned int)reader&0xF8000000U)+0x70000000U)!=0U)var_r9=0;
    if(var_r9==0&&(unsigned int)(temp_r11+0x40000000U)!=0U)var_r8=0;
    if(var_r8==0&&(unsigned int)(((unsigned int)reader&0xFF800000U)+0x3F000000U)!=0U)var_r7=0;
    if(var_r7==0&&(unsigned int)(((unsigned int)reader&0xF8000000U)+0x30000000U)!=0U)var_r6=0;
    if(var_r6==0&&(unsigned int)(((unsigned int)reader&0xFFFFC000U)+0x20000000U)!=0U)var_r5=0;
    if(var_r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x81,base+0x18,reader);
    temp_r6=*(int *)reader;var_r4=1;var_r5_2=1;var_r7_2=1;temp_r11=temp_r6&0xFF000000;var_r8_2=1;var_r9_2=1;var_r10_2=1;
    if((unsigned int)(temp_r11+0x80000000)!=0U&&(unsigned int)((temp_r6&0xFF800000)+0x7F000000)!=0U)var_r10_2=0;
    if(var_r10_2==0&&(unsigned int)((temp_r6&0xF8000000)+0x70000000)!=0U)var_r9_2=0;
    if(var_r9_2==0&&(unsigned int)(temp_r11+0x40000000)!=0U)var_r8_2=0;
    if(var_r8_2==0&&(unsigned int)((temp_r6&0xFF800000)+0x3F000000)!=0U)var_r7_2=0;
    if(var_r7_2==0&&(unsigned int)((temp_r6&0xF8000000)+0x30000000)!=0U)var_r5_2=0;
    if(var_r5_2==0&&(unsigned int)((temp_r6&0xFFFFC000)+0x20000000)!=0U)var_r4=0;
    if(var_r4==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x82,base+0x50);
    if(*(int *)reader&1)Panic__Q26nw4hbm2dbFPCciPCce(base,0x83,base+0xFC);
    value=**(unsigned short **)reader;*(int *)reader=*(int *)reader+2;return value;
}

extern "C" const char lbl_80328030[];
extern "C" unsigned char ReadNextCharCP1252__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000U;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    if ((unsigned int)(top + 0x80000000U) != 0U && (unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U) r10 = 0;
    if (r10 == 0 && (unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U) r9 = 0;
    if (r9 == 0 && (unsigned int)(top + 0x40000000U) != 0U) r8 = 0;
    if (r8 == 0 && (unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U) r7 = 0;
    if (r7 == 0 && (unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U) r6 = 0;
    if (r6 == 0 && (unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328030, 0x9B, lbl_80328030 + 0x18, arg0);
    unsigned int value = *(unsigned int *)arg0;
    top = value & 0xFF000000U;
    int r4 = 1; r5 = 1; r6 = 1; r7 = 1; r8 = 1; r9 = 1;
    if ((unsigned int)(top + 0x80000000U) != 0U && (unsigned int)((value & 0xFF800000U) + 0x7F000000U) != 0U) r9 = 0;
    if (r9 == 0 && (unsigned int)((value & 0xF8000000U) + 0x70000000U) != 0U) r8 = 0;
    if (r8 == 0 && (unsigned int)(top + 0x40000000U) != 0U) r7 = 0;
    if (r7 == 0 && (unsigned int)((value & 0xFF800000U) + 0x3F000000U) != 0U) r6 = 0;
    if (r6 == 0 && (unsigned int)((value & 0xF8000000U) + 0x30000000U) != 0U) r5 = 0;
    if (r5 == 0 && (unsigned int)((value & 0xFFFFC000U) + 0x20000000U) != 0U) r4 = 0;
    if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328030, 0x9C, lbl_80328030 + 0x50);
    unsigned char *ptr = *(unsigned char **)arg0;
    unsigned char result = *ptr;
    *(unsigned int *)arg0 = value + 1;
    return result;
}

extern "C" unsigned char ReadNextCharSJIS__Q36nw4hbm2ut14CharStrmReaderFv(void *arg0) {
void *reader=arg0;const char *base=lbl_80328030;unsigned int top=(unsigned int)reader&0xFF000000U;
int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)reader&0xFF800000U)+0x7F000000U)!=0U)r10=0;
if(r10==0&&(unsigned int)(((unsigned int)reader&0xF8000000U)+0x70000000U)!=0U)r9=0;
if(r9==0&&(unsigned int)(top+0x40000000U)!=0U)r8=0;
if(r8==0&&(unsigned int)(((unsigned int)reader&0xFF800000U)+0x3F000000U)!=0U)r7=0;
if(r7==0&&(unsigned int)(((unsigned int)reader&0xF8000000U)+0x30000000U)!=0U)r6=0;
if(r6==0&&(unsigned int)(((unsigned int)reader&0xFFFFC000U)+0x20000000U)!=0U)r5=0;
if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0xB4,base+0x18,reader);
unsigned int p=*(unsigned int *)reader;top=p&0xFF000000U;
int r4=1;r5=1;r6=1;r7=1;r8=1;r9=1;
if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)((p&0xFF800000U)+0x7F000000U)!=0U)r9=0;
if(r9==0&&(unsigned int)((p&0xF8000000U)+0x70000000U)!=0U)r8=0;
if(r8==0&&(unsigned int)(top+0x40000000U)!=0U)r7=0;
if(r7==0&&(unsigned int)((p&0xFF800000U)+0x3F000000U)!=0U)r6=0;
if(r6==0&&(unsigned int)((p&0xF8000000U)+0x30000000U)!=0U)r5=0;
if(r5==0&&(unsigned int)((p&0xFFFFC000U)+0x20000000U)!=0U)r4=0;
if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0xB5,base+0x50);
unsigned char first=*(unsigned char *)p;
if((first>=0x81&&first<0xA0)||first>=0xE0){unsigned char second=*((unsigned char *)p+1);*(unsigned int *)reader=p+2;return (unsigned char)((first<<8)|second);}
*(unsigned int *)reader=p+1;return first;
}

extern "C" s32 fn_801033F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void SetFont__Q36nw4hbm2ut10CharWriterFRCQ36nw4hbm2ut4Font(void *arg0, void *arg1) {
    unsigned int top = (unsigned int)arg0 & 0xFF000000U;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    if ((unsigned int)(top+0x80000000U)!=0U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U) r10=0;
    if (r10==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U) r9=0;
    if (r9==0 && (unsigned int)(top+0x40000000U)!=0U) r8=0;
    if (r8==0 && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U) r7=0;
    if (r7==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U) r6=0;
    if (r6==0 && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x85,lbl_80328178+0x14,arg0);
    top=(unsigned int)arg1&0xFF000000U;
    int r4=1; r5=1; r6=1; r7=1; r8=1; r9=1;
    if ((unsigned int)(top+0x80000000U)!=0U && (unsigned int)(((unsigned int)arg1&0xFF800000U)+0x7F000000U)!=0U) r9=0;
    if (r9==0 && (unsigned int)(((unsigned int)arg1&0xF8000000U)+0x70000000U)!=0U) r8=0;
    if (r8==0 && (unsigned int)(top+0x40000000U)!=0U) r7=0;
    if (r7==0 && (unsigned int)(((unsigned int)arg1&0xFF800000U)+0x3F000000U)!=0U) r6=0;
    if (r6==0 && (unsigned int)(((unsigned int)arg1&0xF8000000U)+0x30000000U)!=0U) r5=0;
    if (r5==0 && (unsigned int)(((unsigned int)arg1&0xFFFFC000U)+0x20000000U)!=0U) r4=0;
    if (r4==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x86,lbl_80328178+0x4C,arg1);
    *(void **)((char *)arg0+0x48)=arg1;
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
    unsigned int arg0_int = (unsigned int)arg0;
    char *base = (char *)lbl_80328178;
    unsigned char sp20[4], sp1C[4], sp18[4], sp14[4], sp10[4], spC[4], sp8[4];
    unsigned int temp_r30;
    unsigned int temp_r3;
    int temp_r3_3;
    unsigned int temp_r4;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    int var_r10;
    int var_r5_2;
    SetupGXFontType *temp_r3_2;

    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    temp_r30 = arg0_int & 0xFF000000;
    if (((unsigned int) (temp_r30 + 0x80000000) >= 1U) && ((unsigned int) ((arg0_int & 0xFF800000) + 0x7F000000) >= 1U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((unsigned int) ((arg0_int & 0xF8000000) + 0x70000000) >= 1U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((unsigned int) (temp_r30 + 0x40000000) >= 1U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((unsigned int) ((arg0_int & 0xFF800000) + 0x3F000000) >= 1U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((unsigned int) ((arg0_int & 0xF8000000) + 0x30000000) >= 1U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((unsigned int) ((arg0_int & 0xFFFFC000) + 0x20000000) >= 1U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0xAD, base + 0x14, arg0_int);
    }
    var_r5_2 = 0;
    if (((unsigned int) (temp_r30 + 0x80000000) < 1U) || (temp_r4 = arg0_int & 0xFF800000, (((unsigned int) (temp_r4 + 0x7F000000) < 1U) != 0)) || (temp_r3 = arg0_int & 0xF8000000, (((unsigned int) (temp_r3 + 0x70000000) < 1U) != 0)) || ((unsigned int) (temp_r30 + 0x40000000) < 1U) || ((unsigned int) (temp_r4 + 0x3F000000) < 1U) || ((unsigned int) (temp_r3 + 0x30000000) < 1U) || ((unsigned int) ((arg0_int & 0xFFFFC000) + 0x20000000) < 1U)) {
        var_r5_2 = 1;
    }
    if (var_r5_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x12C, base + 0x14, arg0_int);
    }
    (*(int *)((signed char*)(&lbl_8041D4E0) + (0))) = 0xFF;
    (*(int *)((signed char*)(&lbl_8041D4E0) + (4))) = 0;
    if (((int) (*(int *)((signed char*)(arg0) + (0))) != 0) || ((unsigned int) ((*(int *)((signed char*)(arg0) + (4))) + 0x10000) != -1U)) {
        sp20[0] = (unsigned char) (*(int *)((signed char*)(arg0) + (0)));
        sp20[1] = (*(unsigned char *)((signed char*)(arg0) + (1)));
        sp20[2] = (*(unsigned char *)((signed char*)(arg0) + (2)));
        sp20[3] = (*(unsigned char *)((signed char*)(arg0) + (3)));
        sp1C[0] = (unsigned char) (*(int *)((signed char*)(arg0) + (4)));
        sp1C[1] = (*(unsigned char *)((signed char*)(arg0) + (5)));
        sp1C[2] = (*(unsigned char *)((signed char*)(arg0) + (6)));
        sp1C[3] = (*(unsigned char *)((signed char*)(arg0) + (7)));
        SetupGXWithColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color((unsigned int)&sp20[0], (unsigned int)&sp1C[0]);
        return;
    }
    temp_r3_2 = (SetupGXFontType *)(*(void ***)((signed char*)(arg0) + (0x48)));
    if (temp_r3_2 != 0) {
        temp_r3_3 = temp_r3_2->GetType();
        switch (temp_r3_3) {
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
                GXSetFog(0, &sp18[0], lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
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
            break;
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
            GXSetFog(0, &sp14[0], lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
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
            break;
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
            GXSetFog(0, &sp10[0], lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
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
            break;
        default:
            goto block_49;
        }
        block_49:
        Warning__Q26nw4hbm2dbFPCciPCce(base, 0xCF, base + 0x84, temp_r3_3);
        if ((signed char) lbl_8055DE90 == 0) {
            *(int *)&lbl_8055DE94 = 0;
            __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
            lbl_8055DE90 = 1;
        }
        spC[0] = (unsigned char) lbl_8055DE94;
        spC[1] = lbl_8055DE95;
        spC[2] = lbl_8055DE96;
        spC[3] = lbl_8055DE97;
        GXSetFog(0, &spC[0], lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
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
    if ((signed char) lbl_8055DE90 == 0) {
        *(int *)&lbl_8055DE94 = 0;
        __register_global_object(&lbl_8055DE94, &fn_800D2DD4, &lbl_8041D4D0);
        lbl_8055DE90 = 1;
    }
    sp8[0] = (unsigned char) lbl_8055DE94;
    sp8[1] = lbl_8055DE95;
    sp8[2] = lbl_8055DE96;
    sp8[3] = lbl_8055DE97;
    GXSetFog(0, &sp8[0], lbl_8055DE96, lbl_8055DE95, lbl_80561150, lbl_80561150, lbl_80561150, lbl_80561150);
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
extern "C" void SetColorMapping__Q36nw4hbm2ut10CharWriterFQ36nw4hbm2ut5ColorQ36nw4hbm2ut5Color(void *arg0, void *arg1, void *arg2) {
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    if (temp_r11 + 0x80000000U != 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0) r10 = 0;
    if (r10 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0) r9 = 0;
    if (r9 == 0 && temp_r11 + 0x40000000U != 0) r8 = 0;
    if (r8 == 0 && (((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0) r7 = 0;
    if (r7 == 0 && (((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0) r6 = 0;
    if (r6 == 0 && (((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0xEB, "this", arg0);
    *(unsigned char *)((char *)arg0 + 0) = *(unsigned char *)((char *)arg1 + 0);
    *(unsigned char *)((char *)arg0 + 1) = *(unsigned char *)((char *)arg1 + 1);
    *(unsigned char *)((char *)arg0 + 2) = *(unsigned char *)((char *)arg1 + 2);
    *(unsigned char *)((char *)arg0 + 3) = *(unsigned char *)((char *)arg1 + 3);
    *(unsigned char *)((char *)arg0 + 4) = *(unsigned char *)((char *)arg2 + 0);
    *(unsigned char *)((char *)arg0 + 5) = *(unsigned char *)((char *)arg2 + 1);
    *(unsigned char *)((char *)arg0 + 6) = *(unsigned char *)((char *)arg2 + 2);
    *(unsigned char *)((char *)arg0 + 7) = *(unsigned char *)((char *)arg2 + 3);
}

void nw4hbm::ut::CharWriter::SetGradationMode(GradationMode mode) {
    unsigned char *self=(unsigned char *)this;
    unsigned char *self2;
    register unsigned int top;
    int m;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    unsigned char *source1,*source2,*source3;
    int product_17,product_13,product_f,product_b;
    int alpha;
    register int valid;
    int temp_r4,temp_r3;
    int v=0;
    unsigned int address=(unsigned int)this;
    self2=self;
    m=(int)mode;
    top=address&0xFF000000U;
    if ((unsigned int)(top+0x80000000U)>=1U &&
        (unsigned int)((address&0xFF800000U)+0x7F000000U)>=1U) r10=0;
    if (r10==0 && (unsigned int)((address&0xF8000000U)+0x70000000U)>=1U) r9=0;
    if (r9==0 && (unsigned int)(top+0x40000000U)>=1U) r8=0;
    if (r8==0 && (unsigned int)((address&0xFF800000U)+0x3F000000U)>=1U) r7=0;
    if (r7==0 && (unsigned int)((address&0xF8000000U)+0x30000000U)>=1U) r6=0;
    if (r6==0 && (unsigned int)((address&0xFFFFC000U)+0x20000000U)>=1U) r5=0;
    if (r5==0) {
        const char *base=lbl_80328178;
        Panic__Q26nw4hbm2dbFPCciPCce(base,0x163,base+0x14,self2);
    }

    if (m>=0 && m<=2) v=1;
    if (v==0) {
        const char *base=lbl_80328178;
        Panic__Q26nw4hbm2dbFPCciPCce(base,0x164,base+0xb8,m,0,2);
    }
    *(int *)(self2+0x20)=m;

    valid=0;
    if ((unsigned int)(top+0x80000000U)==0U ||
        (temp_r4=(unsigned int)self2&0xFF800000U,(unsigned int)(temp_r4+0x7F000000U)==0U) ||
        (temp_r3=(unsigned int)self2&0xF8000000U,(unsigned int)(temp_r3+0x70000000U)==0U) ||
        (unsigned int)(top+0x40000000U)==0U ||
        (unsigned int)(((unsigned int)self2&0xFF800000U)+0x3F000000U)==0U ||
        (unsigned int)(((unsigned int)self2&0xF8000000U)+0x30000000U)==0U ||
        (unsigned int)(((unsigned int)self2&0xFFFFC000U)+0x20000000U)==0U) valid=1;
    if (valid==0) {
        const char *base=lbl_80328178;
        Panic__Q26nw4hbm2dbFPCciPCce(base,0x4DA,base+0x14,self2);
    }

    self2[8]=self2[0x18]; self2[9]=self2[0x19]; self2[0xA]=self2[0x1A]; self2[0xB]=self2[0x1B];
    if (*(int *)(self2+0x20)!=1) source1=self2+0x18; else source1=self2+0x1C;
    self2[0xC]=source1[0]; self2[0xD]=source1[1]; self2[0xE]=source1[2]; self2[0xF]=source1[3];
    if (*(int *)(self2+0x20)!=2) source2=self2+0x18; else source2=self2+0x1C;
    self2[0x10]=source2[0]; self2[0x11]=source2[1]; self2[0x12]=source2[2]; self2[0x13]=source2[3];
    if (*(int *)(self2+0x20)==0) source3=self2+0x18; else source3=self2+0x1C;
    self2[0x14]=source3[0]; self2[0x15]=source3[1]; self2[0x16]=source3[2];

    alpha=*(volatile unsigned char *)(self2+0x42);
    product_b=self2[0xB]*alpha; product_f=self2[0xF]*alpha;
    product_13=self2[0x13]*alpha; product_17=source3[3]*alpha;
    self2[0xB]=product_b/255; self2[0xF]=product_f/255;
    self2[0x13]=product_13/255; self2[0x17]=product_17/255;
}

void nw4hbm::ut::CharWriter::SetTextColor(nw4hbm::ut::Color color, nw4hbm::ut::Color color2) {
    unsigned int address=(unsigned int)this;
    unsigned int top;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10;
    unsigned char *self=(unsigned char *)this;
    unsigned char *source1,*source2,*source3;
    int product_17,product_13,product_f,product_b;
    int alpha;
    register int valid;
    int temp_r4,temp_r3;
    top=address&0xFF000000U;
    r10=1;
    if ((unsigned int)(top+0x80000000U)>=1U &&
        (unsigned int)((address&0xFF800000U)+0x7F000000U)>=1U) r10=0;
    if (r10==0 && (unsigned int)((address&0xF8000000U)+0x70000000U)>=1U) r9=0;
    if (r9==0 && (unsigned int)(top+0x40000000U)>=1U) r8=0;
    if (r8==0 && (unsigned int)((address&0xFF800000U)+0x3F000000U)>=1U) r7=0;
    if (r7==0 && (unsigned int)((address&0xF8000000U)+0x30000000U)>=1U) r6=0;
    if (r6==0 && (unsigned int)((address&0xFFFFC000U)+0x20000000U)>=1U) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x19A,lbl_8032818C,this);

    self[0x18]=color.r; self[0x19]=color.g; self[0x1A]=color.b; self[0x1B]=color.a;
    self[0x1C]=color2.r; self[0x1D]=color2.g; self[0x1E]=color2.b; self[0x1F]=color2.a;

    valid=0;
    if ((unsigned int)(top+0x80000000U)==0U ||
        (temp_r4=address&0xFF800000U,(unsigned int)(temp_r4+0x7F000000U)==0U) ||
        (temp_r3=address&0xF8000000U,(unsigned int)(temp_r3+0x70000000U)==0U) ||
        (unsigned int)(top+0x40000000U)==0U ||
        (unsigned int)((address&0xFF800000U)+0x3F000000U)==0U ||
        (unsigned int)((address&0xF8000000U)+0x30000000U)==0U ||
        (unsigned int)((address&0xFFFFC000U)+0x20000000U)==0U) valid=1;
    if (valid==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x4DA,lbl_8032818C,this);

    self[8]=self[0x18]; self[9]=self[0x19]; self[0xA]=self[0x1A]; self[0xB]=self[0x1B];
    if (*(int *)(self+0x20)!=1) source1=self+0x18; else source1=self+0x1C;
    self[0xC]=source1[0]; self[0xD]=source1[1]; self[0xE]=source1[2]; self[0xF]=source1[3];
    if (*(int *)(self+0x20)!=2) source2=self+0x18; else source2=self+0x1C;
    self[0x10]=source2[0]; self[0x11]=source2[1]; self[0x12]=source2[2]; self[0x13]=source2[3];
    if (*(int *)(self+0x20)==0) source3=self+0x18; else source3=self+0x1C;
    self[0x14]=source3[0]; self[0x15]=source3[1]; self[0x16]=source3[2];

    alpha=*(volatile unsigned char *)(self+0x42);
    product_b=self[0xB]*alpha; product_f=self[0xF]*alpha;
    product_13=self[0x13]*alpha; product_17=source3[3]*alpha;
    self[0xB]=product_b/255; self[0xF]=product_f/255;
    self[0x13]=product_13/255; self[0x17]=product_17/255;
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
    unsigned int temp_r11;
    int var_r10;
    int var_r5;
    int var_r6;
    int var_r7;
    int var_r8;
    int var_r9;
    temp_r11 = (unsigned int)arg0 & 0xFF000000U;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((unsigned int)(temp_r11 + 0x80000000U) != 0U) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x7F000000U) != 0U)) var_r10 = 0;
    if ((var_r10 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x70000000U) != 0U)) var_r9 = 0;
    if ((var_r9 == 0) && ((unsigned int)(temp_r11 + 0x40000000U) != 0U)) var_r8 = 0;
    if ((var_r8 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFF800000U) + 0x3F000000U) != 0U)) var_r7 = 0;
    if ((var_r7 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xF8000000U) + 0x30000000U) != 0U)) var_r6 = 0;
    if ((var_r6 == 0) && ((unsigned int)(((unsigned int)arg0 & 0xFFFFC000U) + 0x20000000U) != 0U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce("nw4hbm/ut/CharWriter.cpp", 0x21A, "this", arg0);
    return *(float *)((char *)arg0 + 0x28);
}

void nw4hbm::ut::CharWriter::SetFontSize(float farg0, float farg1) {
    const char *base = lbl_80328178;
    register unsigned int top = (unsigned int)this & 0xFF000000U;
    register int r6, r7, r8, r9, r10, r5;
    register unsigned int fontAddress;
    r6 = 1; r7 = 1; r8 = 1; r9 = 1; r10 = 1; r5 = 1;
    if ((unsigned int)(top + 0x80000000U) >= 1U &&
        (unsigned int)(((unsigned int)this & 0xFF800000U) + 0x7F000000U) >= 1U) r10 = 0;
    if (r10 == 0 && (unsigned int)(((unsigned int)this & 0xF8000000U) + 0x70000000U) >= 1U) r9 = 0;
    if (r9 == 0 && (unsigned int)(top + 0x40000000U) >= 1U) r8 = 0;
    if (r8 == 0 && (unsigned int)(((unsigned int)this & 0xFF800000U) + 0x3F000000U) >= 1U) r7 = 0;
    if (r7 == 0 && (unsigned int)(((unsigned int)this & 0xF8000000U) + 0x30000000U) >= 1U) r6 = 0;
    if (r6 == 0 && (unsigned int)(((unsigned int)this & 0xFFFFC000U) + 0x20000000U) >= 1U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x22F, base + 0x14, this);

    fontAddress = *(unsigned int *)((unsigned char *)this + 0x48);
    top = fontAddress & 0xFF000000U;
    register int r4, r5b, r7b, r8b, r9b, r10b;
    r4 = 1; r5b = 1; r7b = 1; r8b = 1; r9b = 1; r10b = 1;
    if ((unsigned int)(top + 0x80000000U) >= 1U &&
        (fontAddress & 0xFF800000U) + 0x7F000000U >= 1U) r10b = 0;
    if (r10b == 0 && (fontAddress & 0xF8000000U) + 0x70000000U >= 1U) r9b = 0;
    if (r9b == 0 && (unsigned int)(top + 0x40000000U) >= 1U) r8b = 0;
    if (r8b == 0 && (fontAddress & 0xFF800000U) + 0x3F000000U >= 1U) r7b = 0;
    if (r7b == 0 && (fontAddress & 0xF8000000U) + 0x30000000U >= 1U) r5b = 0;
    if (r5b == 0 && (fontAddress & 0xFFFFC000U) + 0x20000000U >= 1U) r4 = 0;
    if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x230, base + 0xF4);

    if (((FontForWidth *)*(void **)((char *)this + 0x48))->v1() < 1) {
        int width = ((FontForWidth *)*(void **)((char *)this + 0x48))->v1();
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x231, base + 0x12C, width, 1);
    }
    if (((FontForWidth *)*(void **)((char *)this + 0x48))->v2() < 1) {
        int height = ((FontForWidth *)*(void **)((char *)this + 0x48))->v2();
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x232, base + 0x180, height, 1);
    }
    farg0 /= (float)((FontForWidth *)*(void **)((char *)this + 0x48))->v1();
    farg1 /= (float)((FontForWidth *)*(void **)((char *)this + 0x48))->v2();

    top = (unsigned int)this & 0xFF000000U;
    r5 = 0;
    if ((unsigned int)(top + 0x80000000U) == 0U ||
        (unsigned int)(((unsigned int)this & 0xFF800000U) + 0x7F000000U) == 0U ||
        (unsigned int)(((unsigned int)this & 0xF8000000U) + 0x70000000U) == 0U ||
        (unsigned int)(top + 0x40000000U) == 0U ||
        (unsigned int)(((unsigned int)this & 0xFF800000U) + 0x3F000000U) == 0U ||
        (unsigned int)(((unsigned int)this & 0xF8000000U) + 0x30000000U) == 0U ||
        (unsigned int)(((unsigned int)this & 0xFFFFC000U) + 0x20000000U) == 0U) r5 = 1;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x1E7, base + 0x14, this);
    *(float *)((char *)this + 0x24) = farg0;
    *(float *)((char *)this + 0x28) = farg1;
}

extern "C" float GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    unsigned int top=(unsigned int)arg0 & 0xFF000000U;
    unsigned int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    if ((unsigned int)(top+0x80000000U)!=0U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U) r10=0;
    if (r10==0U && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U) r9=0;
    if (r9==0U && (unsigned int)(top+0x40000000U)!=0U) r8=0;
    if (r8==0U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U) r7=0;
    if (r7==0U && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U) r6=0;
    if (r6==0U && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U) r5=0;
    if (r5==0U) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x259,lbl_80328178+0x14,arg0);
    unsigned int value=*(unsigned int *)((char *)arg0+0x48);
    top=value&0xFF000000U;
    unsigned int r4=1; r5=1; r6=1; r7=1; r8=1; r9=1;
    if ((unsigned int)(top+0x80000000U)!=0U && (unsigned int)((value&0xFF800000U)+0x7F000000U)!=0U) r9=0;
    if (r9==0U && (unsigned int)((value&0xF8000000U)+0x70000000U)!=0U) r8=0;
    if (r8==0U && (unsigned int)(top+0x40000000U)!=0U) r7=0;
    if (r7==0U && (unsigned int)((value&0xFF800000U)+0x3F000000U)!=0U) r6=0;
    if (r6==0U && (unsigned int)((value&0xF8000000U)+0x30000000U)!=0U) r5=0;
    if (r5==0U && (unsigned int)((value&0xFFFFC000U)+0x20000000U)!=0U) r4=0;
    if (r4==0U) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x25A,lbl_80328178+0xF4);
    FontForWidth *font=(FontForWidth *)value;
    int width=font->v2();
    return *(float *)((char *)arg0+0x24) * (float)width;
}

extern "C" float GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(void *arg0) {
    const char *base = lbl_80328178;
    int top, r4, r5, r6, r7, r8, r9, r10;
    void *font;
    top = (unsigned int)arg0 & 0xFF000000U;
    r5=1; r6=1; r7=1; r8=1; r9=1; r10=1;
    if ((unsigned int)(top+0x80000000U)!=0U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)!=0U) r10=0;
    if (r10==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)!=0U) r9=0;
    if (r9==0 && (unsigned int)(top+0x40000000U)!=0U) r8=0;
    if (r8==0 && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)!=0U) r7=0;
    if (r7==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)!=0U) r6=0;
    if (r6==0 && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)!=0U) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(base,0x26A,base+0x14,arg0);
    font=*(void **)((char *)arg0+0x48);
    top=(unsigned int)font&0xFF000000U; r4=1; r5=1; r7=1; r8=1; r9=1; r10=1;
    if ((unsigned int)(top+0x80000000U)!=0U && (unsigned int)(((unsigned int)font&0xFF800000U)+0x7F000000U)!=0U) r10=0;
    if (r10==0 && (unsigned int)(((unsigned int)font&0xF8000000U)+0x70000000U)!=0U) r9=0;
    if (r9==0 && (unsigned int)(top+0x40000000U)!=0U) r8=0;
    if (r8==0 && (unsigned int)(((unsigned int)font&0xFF800000U)+0x3F000000U)!=0U) r7=0;
    if (r7==0 && (unsigned int)(((unsigned int)font&0xF8000000U)+0x30000000U)!=0U) r5=0;
    if (r5==0 && (unsigned int)(((unsigned int)font&0xFFFFC000U)+0x20000000U)!=0U) r4=0;
    if (r4==0) Panic__Q26nw4hbm2dbFPCciPCce(base,0x26B,base+0xF4);
    #pragma cplusplus on
    int width = ((FontForWidth *)font)->v3();
    #pragma cplusplus reset
    return *(float *)((char *)arg0+0x28) * (float)width;
}

extern "C" float GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801058DC(void *arg0) {
    struct FontVTable { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual int GetWidth(); };
    void *self=arg0;
    const char *base=lbl_80328178;
    unsigned int top=(unsigned int)self&0xFF000000U;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)self&0xFF800000U)+0x7F000000U)!=0U)r10=0;
    if(r10==0&&(unsigned int)(((unsigned int)self&0xF8000000U)+0x70000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)(top+0x40000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(((unsigned int)self&0xFF800000U)+0x3F000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)(((unsigned int)self&0xF8000000U)+0x30000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)(((unsigned int)self&0xFFFFC000U)+0x20000000U)!=0U)r5=0;
    if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x27B,base+0x14,self);
    void *font=*(void **)((char *)self+0x48);
    top=(unsigned int)font&0xFF000000U;
    int r4=1;r5=1;r6=1;r7=1;r8=1;r9=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)font&0xFF800000U)+0x7F000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)(((unsigned int)font&0xF8000000U)+0x70000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(top+0x40000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)(((unsigned int)font&0xFF800000U)+0x3F000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)(((unsigned int)font&0xF8000000U)+0x30000000U)!=0U)r5=0;
    if(r5==0&&(unsigned int)(((unsigned int)font&0xFFFFC000U)+0x20000000U)!=0U)r4=0;
    if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(base,0x27C,base+0xF4);
    int width=((FontVTable *)font)->GetWidth();
    return *(float *)((char *)self+0x28)*(float)width;
}

extern "C" unsigned char IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(void *arg0) {
    int var_r5 = 1;
    int var_r6 = 1;
    int var_r7 = 1;
    int var_r8 = 1;
    int var_r9 = 1;
    int var_r10 = 1;
    unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
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
     register int r6, r7, r8, r9, r10, r5;
     register unsigned int fontAddress;
     unsigned char glyph[0x18];
     float advance;
     float xOffset;
 
     r6 = 1; r7 = 1; r8 = 1; r9 = 1; r10 = 1; r5 = 1;
     if ((unsigned int)(top + 0x80000000U) >= 1U && (unsigned int)(((unsigned int)this & 0xFF800000U) + 0x7F000000U) >= 1U) r10 = 0;
     if (r10 == 0 && (unsigned int)(((unsigned int)this & 0xF8000000U) + 0x70000000U) >= 1U) r9 = 0;
     if (r9 == 0 && (unsigned int)(top + 0x40000000U) >= 1U) r8 = 0;
     if (r8 == 0 && (unsigned int)(((unsigned int)this & 0xFF800000U) + 0x3F000000U) >= 1U) r7 = 0;
     if (r7 == 0 && (unsigned int)(((unsigned int)this & 0xF8000000U) + 0x30000000U) >= 1U) r6 = 0;
     if (r6 == 0 && (unsigned int)(((unsigned int)this & 0xFFFFC000U) + 0x20000000U) >= 1U) r5 = 0;
     if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x328, base + 0x14, this);
 
     fontAddress = *(unsigned int *)((unsigned char *)this + 0x48);
     top = fontAddress & 0xFF000000U;
     register int r4, r5b, r7b, r8b, r9b, r10b;
     r4 = 1; r5b = 1; r7b = 1; r8b = 1; r9b = 1; r10b = 1;
     if ((unsigned int)(top + 0x80000000U) >= 1U && (fontAddress & 0xFF800000U) + 0x7F000000U >= 1U) r10b = 0;
     if (r10b == 0 && (fontAddress & 0xF8000000U) + 0x70000000U >= 1U) r9b = 0;
     if (r9b == 0 && (unsigned int)(top + 0x40000000U) >= 1U) r8b = 0;
     if (r8b == 0 && (fontAddress & 0xFF800000U) + 0x3F000000U >= 1U) r7b = 0;
     if (r7b == 0 && (fontAddress & 0xF8000000U) + 0x30000000U >= 1U) r5b = 0;
     if (r5b == 0 && (fontAddress & 0xFFFFC000U) + 0x20000000U >= 1U) r4 = 0;
     if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base, 0x329, base + 0xF4);
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
 int var_r5=1; int var_r6=1; int var_r7=1; int var_r8=1; int var_r9=1; int var_r10=1;
 unsigned int temp_r11 = (unsigned int)arg0 & 0xFF000000U;
 if ((temp_r11+0x80000000U)>=1U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)>=1U) var_r10=0;
 if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)>=1U) var_r9=0;
 if (var_r9==0 && (temp_r11+0x40000000U)>=1U) var_r8=0;
 if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)>=1U) var_r7=0;
 if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)>=1U) var_r6=0;
 if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)>=1U) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328178,0x3D5,lbl_8032818C,arg0);
 *(float*)((char*)arg0+0x30)=farg0;
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