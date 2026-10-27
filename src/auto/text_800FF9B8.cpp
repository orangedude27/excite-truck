// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

namespace nw4hbm { namespace snd { namespace detail {
struct WsdTrack { struct WsdCallback; };
class WaveSound {
public:
    virtual void unk_00() = 0;
    virtual void unk_04() = 0;
    virtual void unk_08() = 0;
    virtual void unk_0c() = 0;
    virtual void unk_10() = 0;
    virtual void unk_14() = 0;
    virtual void unk_18() = 0;
    virtual void unk_1c() = 0;
    virtual void unk_20() = 0;
    virtual void unk_24() = 0;
    virtual void unk_28() = 0;
    virtual void unk_2c() = 0;
    virtual void unk_30() = 0;
    virtual void unk_34() = 0;
    virtual void unk_38() = 0;
    virtual void unk_3c() = 0;
    virtual void unk_40() = 0;
    virtual void unk_44() = 0;
    virtual void unk_48() = 0;
    virtual void unk_4c() = 0;
    virtual void unk_0x58() = 0;
    void Prepare(const void *, long, int, const WsdTrack::WsdCallback *, unsigned long);
};
}}}

typedef unsigned int u32;
extern "C" u32 lbl_8055DE88;
extern "C" void fn_800FFE94(int);
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void *);
extern "C" void __ct__Q46nw4hbm3snd6detail9WsdPlayerFv(void *, void *);
extern "C" char lbl_803275EC[];
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FF9B8(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *fn_800FFA10(void *arg0, int arg1) {
    __ct__Q44nw4r3snd6detail10BasicSoundFv(arg0);
    *(void **)arg0 = lbl_803275EC;
    __ct__Q46nw4hbm3snd6detail9WsdPlayerFv((char *)arg0 + 0xD8, lbl_803275EC);
    *(int *)((char *)arg0 + 0x1B0) = arg1;
    *(int *)((char *)arg0 + 0x1AC) = 0;
    return arg0;
}

extern "C" int fn_800FFA6C(int arg0, int arg1) {
    extern void fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" const char lbl_80327500[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Prepare__Q46nw4hbm3snd6detail9WsdPlayerFPCviiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl(void *, const void *, long, int, const nw4hbm::snd::detail::WsdTrack::WsdCallback *, unsigned long);
void nw4hbm::snd::detail::WaveSound::Prepare(const void *arg1, long arg2, int arg3, const nw4hbm::snd::detail::WsdTrack::WsdCallback *arg4, unsigned long arg5) {
    const char *base = lbl_80327500;
    if (!arg1) Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x43, base + 0x18);
    if (!arg4) Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x44, base + 0x48);
    if (*(int *)((char *)this + 0x10) == 0) Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x45, base + 0x74);
    this->unk_0x58();
    Prepare__Q46nw4hbm3snd6detail9WsdPlayerFPCviiPCQ56nw4hbm3snd6detail8WsdTrack11WsdCallbackUl((char *)this + 0xD8, arg1, arg2, arg3, arg4, arg5);
}

extern "C" int fn_800FFC5C(int arg0, int arg1) {
    extern void fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFC9C(int arg0, int arg1) {
    extern const char lbl_80327500[];
    extern const char lbl_803275A8[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern void SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(int, int);
    int valid = 0;
    if (arg1 >= 0 && arg1 <= 0x7F) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327500, 0x85, lbl_803275A8, arg1, 0, 0x7F);
    SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(arg0 + 0xD8, arg1);
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *, int);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" const char lbl_803257D4[];
extern "C" const char lbl_803257B0[];
extern "C" const char lbl_80325804[];
extern "C" const char lbl_803257E0[];
#pragma use_lmw_stmw off
extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFD24(void* arg0, int arg1) {
    void* soundNode;
    int priority;
    void* list;
    void* end;
    void* cursor;

    SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(arg0, arg1);
    priority = *(unsigned char*)((unsigned char*)arg0 + 0x74) + *(int*)((unsigned char*)arg0 + 0x40);
    if (priority > 0x7f) {
        priority = 0x7f;
    } else {
        priority &= ~(priority >> 31);
    }
    list = *(void**)((unsigned char*)arg0 + 0x1b0);
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
    }
    soundNode = (unsigned char*)arg0 + 0xb8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((unsigned char*)list + 4, soundNode);
    cursor = *(void**)((unsigned char*)list + 8);
    end = (unsigned char*)list + 8;
    while (cursor != end) {
        if (cursor == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80325804, 0x23d, lbl_803257E0);
        }
        int value = *(unsigned char*)((unsigned char*)cursor - 0x44) + *(int*)((unsigned char*)cursor - 0x78);
        if (value > 0x7f) {
            value = 0x7f;
        } else {
            value &= ~(value >> 31);
        }
        if (priority < value) {
            break;
        }
        cursor = *(void**)cursor;
    }
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803257D4, 0x233, lbl_803257B0);
    }
    void* node = cursor;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((unsigned char*)list + 4, &node, soundNode);
}
extern "C" int fn_800FFE54(void *arg0) {
    return *(int *)((char *)arg0 + 0x1AC) != 0;
}

extern "C" void fn_800FFE68(void *arg0) {
    fn_800FFE94(*(int *)((char *)arg0 + 0x1AC));
}

extern "C" int fn_800FFE70(int arg0) {
    return arg0 + 0xD8;
}

extern "C" int fn_800FFE78(int arg0) { return arg0 + 0xD8; }

extern "C" u32 *fn_800FFE80(void) {
    return &lbl_8055DE88;
}
#pragma use_lmw_stmw off
