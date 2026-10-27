typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef int M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void TRKProcessInput(void *, unsigned int);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" int ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(void *, void *, int, int, int);
extern "C" void *ReadWaveParam__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8WaveDataiPCv(void *, void *, int, const void *);
extern "C" void *AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(int, int, int, int, int);
extern "C" void SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi(void *, int);
extern "C" void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(void *, const void *, int);
extern float lbl_80560F88, lbl_80560F8C, lbl_80560F90;
extern double lbl_80560F98, lbl_80560FA0;
extern "C" int IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(void *);
extern "C" void fn_800E6A44(void);
extern "C" void fn_80033538(unsigned short);
extern "C" void AIRegisterDMACallback(void *);
extern "C" void AXRegisterAuxACallback(int, int);
extern "C" void AXRegisterAuxBCallback(int, int);
extern "C" void AXRegisterAuxCCallback(int, int);
extern "C" void fn_800E4364(void *, int);
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void *, void **);
extern int lbl_8055DE20;
extern void fn_80128668(void);

extern "C" unsigned int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(unsigned int);
extern "C" void AXSetVoiceState(void *, unsigned int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern const char lbl_80322094[];
extern const char lbl_80322070[];
extern const char lbl_80321F80[];
extern const char lbl_80321FAC[];
extern const char lbl_80322790[];
extern const char lbl_80322830[];
extern const char lbl_80322858[];
extern const char lbl_80322708[];
extern const char lbl_80322734[];
extern "C" unsigned int GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void *);
extern const char lbl_80559820[];
extern const char lbl_80559828[];
extern float lbl_80560F38;
extern float lbl_80560F3C;
extern float lbl_80560F40;
extern float lbl_80560F58;
extern "C" void fn_800339B0(void *, short *);
extern "C" void fn_80033A34(void *, float);
extern const char lbl_803227EC[];
extern "C" void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern "C" void detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern const char lbl_803221A8[];
extern const char lbl_803222F0[];
extern const char lbl_80322438[];
// Vtable dispatcher class for indirect virtual calls (MWCC ABI: 2 leading dtor slots).
class VfObj {
public:
    virtual ~VfObj();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();   // vtable 0x60 = 10th named method (0x18 + 9*4)
    virtual void vf17();   // vtable 0x64
    virtual void vf18();   // vtable 0x68
    virtual void vf19();   // vtable 0x6C
    virtual void vf20();   // vtable 0x70
    virtual void vf21();   // vtable 0x74
    virtual void vf22();   // vtable 0x78
    virtual VfObj *vf23();   // vtable 0x60
};
// fn_800E9B28 variant: vf23 returns VfObj* (vtable 0x5C), vf12 takes a float (0x40).
class VfObjF {
public:
    virtual ~VfObjF();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(float);   // vtable 0x40
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(float);   // vtable 0x40
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
      virtual VfObjF *vf22();   // vtable 0x5C
  virtual VfObjF *vf23();
};
// Minimal shapes matching the target's use of BasicSound/SoundPlayer (0x10 player
// field, byte field at 0x74, and Remove/Insert calls taking the raw pointers).
class BasicSound;
class SoundPlayer;
typedef unsigned char u8;
typedef unsigned short u16;
extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *fn_80128668(void *);
extern "C" void *__register_global_object(void *, void *, void *);
extern "C" void *fn_800E279C(void *);
extern "C" unsigned char lbl_8055DE18;
#pragma push
#pragma small_data off
extern int lbl_80407F6C;
extern int lbl_80407F60;
#pragma pop
extern "C" void *fn_8002F634(void *, void *, int, int);
extern "C" void *__dt__Q46nw4hbm3snd6detail7AxVoiceFv(void *, int);
extern "C" void *fn_800E2D74(void *, int);
extern "C" void TRKGetFreeBuffer(void *);
extern "C" void fn_800E4764(void *);
#pragma push
#pragma small_data off
extern u8 lbl_80322498[];
extern const char lbl_803220C4[];
extern const char lbl_803220A0[];
#pragma pop
typedef float f32;
extern float lbl_80560F38;
extern float lbl_80560F3C;
#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern float lbl_80560F00;
extern float lbl_80560F04;
#pragma push
#pragma small_data off
extern float lbl_80320E38[];
#pragma pop
extern "C" f32 SinFIdx__Q24nw4r4mathFf(f32 angle) {
    f32 index = __fabsf(angle);
    while (index >= lbl_80560F00) index -= lbl_80560F00;
    u16 quantized = ((u16 *)&index)[0];
    f32 *entry = (f32 *)((char *)lbl_80320E38 + ((quantized * 0x10) & 0xFF0));
    f32 value = entry[0] + (index - index) * entry[2];
    if (angle < lbl_80560F04) value = -value;
    return value;
}

extern "C" f32 CosFIdx__Q24nw4r4mathFf(f32 angle) {
    f32 index = __fabsf(angle);
    while (index >= lbl_80560F00) index -= lbl_80560F00;
    u16 quantized = ((u16 *)&index)[0];
    f32 *entry = (f32 *)((char *)lbl_80320E38 + ((quantized * 0x10) & 0xFF0));
    f32 fraction = index;
    return entry[1] + fraction * entry[3];
}

#pragma push
#pragma small_data off
extern float lbl_80560F04, lbl_80560F08, lbl_80560F0C, lbl_80560F10, lbl_80560F14, lbl_80560F18;
extern float lbl_80321E48[];
#pragma pop
extern "C" float Atan2FIdx__Q24nw4r4mathFff(float y, float x) {
    float f1 = y;
    float f3;
    float f4 = lbl_80560F04;
    int mode;
    if (x == f4 && f1 == f4) return f4;
    if (x <= f4) {
        if (f1 <= f4) {
            if (x <= f1) { f3=x; mode=0; }
            else { f3=f1; f4=lbl_80560F0C; f1=x; mode=1; }
        } else {
            f1 = -f1;
            if (x <= f1) { f3=x; mode=1; }
            else { f3=f1; f4=lbl_80560F10; f1=x; mode=0; }
        }
    } else {
        if (f1 <= f4) {
            float f0=-x;
            if (f0 <= f1) { f3=f0; f4=lbl_80560F14; mode=1; }
            else { f3=f1; f4=lbl_80560F0C; f1=f0; mode=0; }
        } else {
            float f0=-x;
            f1=-f1;
            if (f0 <= f1) { f3=f0; f4=lbl_80560F18; mode=0; }
            else { f3=f1; f4=lbl_80560F10; f1=f0; mode=1; }
        }
    }
    f1 = f1 / f3 * lbl_80560F08;
    if (mode) {
        u16 i = *(u16 *)&f1;
        float *e = (float *)((char *)lbl_80321E48 + i * 8);
        return f4 - (e[0] + (f1 - (float)i) * e[1]);
    } else {
        u16 i = *(u16 *)&f1;
        float *e = (float *)((char *)lbl_80321E48 + i * 8);
        return f4 + (e[0] + (f1 - (float)i) * e[1]);
    }
}

extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void fn_8002F53C(void *, void *, void *, s32, s32); /* extern */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *, int);
extern "C" void fn_800E2C98(void *);
extern f32 lbl_80560F20;
extern f32 lbl_80560F24;
#pragma push
#pragma processor 750
void *fn_800E279C(void *arg0) {
    u8 *temp_r10;
    s32 temp_r10_2;
    s32 temp_r10_3;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r7_3;
    s32 temp_r7_4;
    u8 *temp_r8;
    s32 temp_r8_2;
    s32 temp_r8_3;
    u8 *temp_r9;
    s32 temp_r9_2;
    s32 temp_r9_3;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r7;
    s32 var_r7_2;
    u32 var_ctr;
    u32 var_ctr_2;
    u32 var_ctr_3;
    u32 var_ctr_4;
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r6;
    u8 *temp_r6_2;
    u8 *var_r5;
    u8 *var_r5_2;

    temp_r8 = (u8 *)((char *)arg0 + 0xC);
    temp_r9 = (u8 *)((char *)arg0 + 0x18);
    temp_r10 = (u8 *)((char *)arg0 + 0x24);
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, u8 **, 0xC) = temp_r8;
    M2C_FIELD(arg0, u8 **, 0x10) = temp_r8;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, u8 **, 0x18) = temp_r9;
    M2C_FIELD(arg0, u8 **, 0x1C) = temp_r9;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, u8 **, 0x24) = temp_r10;
    M2C_FIELD(arg0, u8 **, 0x28) = temp_r10;
    fn_8002F53C((u8 *)((char *)arg0 + 0x2C), &__ct__Q46nw4hbm3snd6detail7AxVoiceFv, &__dt__Q46nw4hbm3snd6detail7AxVoiceFv, 0x1B0, 0x40);
    var_r5 = (u8 *)((char *)arg0 + 0x6C7C);
    temp_r3 = (u8 *)((char *)arg0 + 0x6C9C);
    M2C_FIELD(arg0, s8 *, 0x6C30) = 0;
    M2C_FIELD(arg0, s8 *, 0x6C31) = 1;
    M2C_FIELD(arg0, s8 *, 0x6C32) = 0;
    M2C_FIELD(arg0, s8 *, 0x6C33) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C34) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, f32 *, 0x6C38) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, s32 *, 0x6C3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C40) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C44) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, f32 *, 0x6C48) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, s32 *, 0x6C4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C50) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C54) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, f32 *, 0x6C58) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, s32 *, 0x6C5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C60) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C64) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C68) = -1;
    M2C_FIELD(arg0, f32 *, 0x6C6C) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, f32 *, 0x6C70) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, s32 *, 0x6C74) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C78) = 0;
    if (var_r5 < temp_r3) {
        temp_r6 = (u8 *)((char *)arg0 + 0x6C7C);
        temp_r4 = (u8 *)((char *)arg0 + 0x6C1C);
        temp_r7 = temp_r3 - temp_r6;
        temp_r8_2 = temp_r7 + 0xF;
        temp_r9_2 = temp_r8_2 / 16;
        temp_r10_2 = temp_r9_2 + 1;
        if (temp_r10_2 > 8) {
            var_r3 = 0;
            var_r6 = 0;
            if (temp_r6 <= temp_r3) {
                var_r7 = 1;
                if (!(temp_r7 & 0x80000000) && (temp_r8_2 & 0x80000000)) {
                    var_r7 = 0;
                }
                if (var_r7 != 0) {
                    var_r6 = 1;
                }
            }
            if (var_r6 != 0) {
                temp_r7_2 = temp_r9_2 & 0x80000000;
                var_r6_2 = 1;
                if ((temp_r7_2 == 0) && (temp_r7_2 != (s32) (temp_r10_2 & 0x80000000))) {
                    var_r6_2 = 0;
                }
                if (var_r6_2 != 0) {
                    var_r3 = 1;
                }
            }
            if (var_r3 != 0) {
                var_ctr = (u32) ((temp_r4 + 0x7F) - var_r5) >> 7U;
                if (var_r5 < temp_r4) {
                    for (var_r3 = 0; var_r3 < (s32)var_ctr; var_r3++) {
                        M2C_FIELD(var_r5, f32 *, 0) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 4) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 8) = 0;
                        M2C_FIELD(var_r5, s32 *, 0xC) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x10) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x14) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x18) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x1C) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x20) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x24) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x28) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x2C) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x30) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x34) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x38) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x3C) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x40) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x44) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x48) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x4C) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x50) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x54) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x58) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x5C) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x60) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x64) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x68) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x6C) = 0;
                        M2C_FIELD(var_r5, f32 *, 0x70) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, f32 *, 0x74) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5, s32 *, 0x78) = 0;
                        M2C_FIELD(var_r5, s32 *, 0x7C) = 0;
                        var_r5 += 0x80;
                    }
                }
            }
        }
        temp_r3_2 = (u8 *)((char *)arg0 + 0x6C9C);
        var_ctr_2 = (u32) ((temp_r3_2 + 0xF) - var_r5) >> 4U;
        if (var_r5 < temp_r3_2) {
            do {
                M2C_FIELD(var_r5, f32 *, 0) = (f32) lbl_80560F20;
                M2C_FIELD(var_r5, f32 *, 4) = (f32) lbl_80560F20;
                M2C_FIELD(var_r5, s32 *, 8) = 0;
                M2C_FIELD(var_r5, s32 *, 0xC) = 0;
                var_r5 += 0x10;
                var_ctr_2 -= 1;
            } while (var_ctr_2 != 0);
        }
    }
    var_r5_2 = (u8 *)((char *)arg0 + 0x6CAC);
    temp_r3_3 = (u8 *)((char *)arg0 + 0x6CCC);
    M2C_FIELD(arg0, f32 *, 0x6C9C) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, f32 *, 0x6CA0) = (f32) lbl_80560F20;
    M2C_FIELD(arg0, s32 *, 0x6CA4) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CA8) = 0;
    if (var_r5_2 < temp_r3_3) {
        temp_r6_2 = (u8 *)((char *)arg0 + 0x6CAC);
        temp_r4_2 = (u8 *)((char *)arg0 + 0x6C4C);
        temp_r7_3 = temp_r3_3 - temp_r6_2;
        temp_r8_3 = temp_r7_3 + 0xF;
        temp_r9_3 = temp_r8_3 / 16;
        temp_r10_3 = temp_r9_3 + 1;
        if (temp_r10_3 > 8) {
            var_r3_2 = 0;
            var_r6_3 = 0;
            if (temp_r6_2 <= temp_r3_3) {
                var_r7_2 = 1;
                if (!(temp_r7_3 & 0x80000000) && (temp_r8_3 & 0x80000000)) {
                    var_r7_2 = 0;
                }
                if (var_r7_2 != 0) {
                    var_r6_3 = 1;
                }
            }
            if (var_r6_3 != 0) {
                temp_r7_4 = temp_r9_3 & 0x80000000;
                var_r6_4 = 1;
                if ((temp_r7_4 == 0) && (temp_r7_4 != (s32) (temp_r10_3 & 0x80000000))) {
                    var_r6_4 = 0;
                }
                if (var_r6_4 != 0) {
                    var_r3_2 = 1;
                }
            }
            if (var_r3_2 != 0) {
                var_ctr_3 = (u32) ((temp_r4_2 + 0x7F) - var_r5_2) >> 7U;
                if (var_r5_2 < temp_r4_2) {
                    for (var_r3_2 = 0; var_r3_2 < (s32)var_ctr_3; var_r3_2++) {
                        M2C_FIELD(var_r5_2, f32 *, 0) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 4) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 8) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0xC) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x10) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x14) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x18) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x1C) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x20) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x24) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x28) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x2C) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x30) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x34) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x38) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x3C) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x40) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x44) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x48) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x4C) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x50) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x54) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x58) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x5C) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x60) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x64) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x68) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x6C) = 0;
                        M2C_FIELD(var_r5_2, f32 *, 0x70) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, f32 *, 0x74) = (f32) lbl_80560F20;
                        M2C_FIELD(var_r5_2, s32 *, 0x78) = 0;
                        M2C_FIELD(var_r5_2, s32 *, 0x7C) = 0;
                        var_r5_2 += 0x80;
                    }
                }
            }
        }
        temp_r3_4 = (u8 *)((char *)arg0 + 0x6CCC);
        var_ctr_4 = (u32) ((temp_r3_4 + 0xF) - var_r5_2) >> 4U;
        if (var_r5_2 < temp_r3_4) {
            do {
                M2C_FIELD(var_r5_2, f32 *, 0) = (f32) lbl_80560F20;
                M2C_FIELD(var_r5_2, f32 *, 4) = (f32) lbl_80560F20;
                M2C_FIELD(var_r5_2, s32 *, 8) = 0;
                M2C_FIELD(var_r5_2, s32 *, 0xC) = 0;
                var_r5_2 += 0x10;
                var_ctr_4 -= 1;
            } while (var_ctr_4 != 0);
        }
    }
    fn_8002F53C((u8 *)((char *)arg0 + 0x6CCC), &fn_800E2C98, &__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8, 0xC, 3);
    M2C_FIELD(arg0, s32 *, 0x6C3C) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C34) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6C38) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6C40) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C44) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6C48) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6C4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C50) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C54) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6C58) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6C5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C60) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C6C) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6C70) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6C74) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C78) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C9C) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6CA0) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6CA4) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CA8) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CFC) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C7C) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6C80) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6C84) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C88) = 0;
    M2C_FIELD(arg0, f32 *, 0x6CAC) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6CB0) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6CB4) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CB8) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CF4) = 0;
    M2C_FIELD(arg0, s32 *, 0x6D00) = 0;
    M2C_FIELD(arg0, f32 *, 0x6C8C) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6C90) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6C94) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C98) = 0;
    M2C_FIELD(arg0, f32 *, 0x6CBC) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, f32 *, 0x6CC0) = (f32) lbl_80560F24;
    M2C_FIELD(arg0, s32 *, 0x6CC4) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CC8) = 0;
    M2C_FIELD(arg0, s32 *, 0x6CF8) = 0;
    M2C_FIELD(arg0, s32 *, 0x6D04) = 0;
    return (void *)arg0;
}
#pragma pop
extern "C" void fn_800E2C98(void *arg0) {
    int *p = (int *)((char *)arg0 + 4);
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)arg0 = 0;
    *(int *)((char *)arg0 + 4) = (int)p;
    *(int *)((char *)arg0 + 8) = (int)p;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
extern "C" void *Instance__15EmissionManagerFv(void) {
    if ((signed char)lbl_8055DE18 == 0) {
        fn_800E279C(&lbl_80407F6C);
        __register_global_object(&lbl_80407F6C, (void *)fn_800E2D74, &lbl_80407F60);
        lbl_8055DE18 = 1;
    }
    return &lbl_80407F6C;
}

extern "C" void *fn_800E2D74(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8002F634((char *)arg0 + 0x6ccc, (void *)__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8, 0xc, 3);
        fn_8002F634((char *)arg0 + 0x2c, (void *)__dt__Q46nw4hbm3snd6detail7AxVoiceFv, 0x1b0, 0x40);
        if ((char *)arg0 + 0x20 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0x20, 0);
        if ((char *)arg0 + 0x14 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0x14, 0);
        if ((char *)arg0 + 8 != 0) __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 8, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern const char lbl_80322124[];
extern const char lbl_80322100[];
extern const char lbl_803220F4[];
extern const char lbl_803220D0[];
extern "C" void fn_800E2F84(void *self) {
    if (*((u8 *)self + 0x6C30) != 0) {
        AIRegisterDMACallback(*(void **)((char *)self + 0x6C2C));
        fn_800E4364(self, 0); fn_800E4364(self, 1); fn_800E4364(self, 2);
        AXRegisterAuxACallback(*(int *)((char *)self + 0x6CF0), *(int *)((char *)self + 0x6CFC));
        AXRegisterAuxBCallback(*(int *)((char *)self + 0x6CF4), *(int *)((char *)self + 0x6D00));
        AXRegisterAuxCCallback(*(int *)((char *)self + 0x6CF8), *(int *)((char *)self + 0x6D04));
        *(int *)((char *)self + 0x6CF0) = 0; *(int *)((char *)self + 0x6CFC) = 0;
        *(int *)((char *)self + 0x6CF4) = 0; *(int *)((char *)self + 0x6D00) = 0;
        *(int *)((char *)self + 0x6CF8) = 0; *(int *)((char *)self + 0x6D04) = 0;
        *(int *)((char *)self + 4) = 0;
        while (*(int *)((char *)self + 0x14) != 0) {
            void *node = *(void **)((char *)self + 0x18);
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
            void *voice = (char *)node - 0x1A8;
            if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            Stop__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
            Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
            void (*callback)(void *, int, void *) = *(void (**)(void *, int, void *))((char *)voice + 0x10C);
            if (callback != 0) callback(voice, 2, *(void **)((char *)voice + 0x110));
        }
        while (*(int *)((char *)self + 0x20) != 0) {
            void *it = *(void **)((char *)self + 0x24);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator((char *)self + 0x20, &it);
        }
        *(u8 *)((char *)self + 0x6C30) = 0;
    }
}

#pragma push
#pragma small_data off
extern double lbl_80560F28;
#pragma pop
extern "C" f32 fn_800E310C(void *arg0) {
    int a = *(int *)((char *)arg0 + 0x6C50);
    int b = *(int *)((char *)arg0 + 0x6C4C);
    float x;
    if (a >= b) x = *(float *)((char *)arg0 + 0x6C48);
    else x = *(float *)((char *)arg0 + 0x6C44) +
        (float)a * (*(float *)((char *)arg0 + 0x6C48) - *(float *)((char *)arg0 + 0x6C44)) / (float)b;

    int c = *(int *)((char *)arg0 + 0x6C60);
    int d = *(int *)((char *)arg0 + 0x6C5C);
    float y;
    if (c >= d) y = *(float *)((char *)arg0 + 0x6C58);
    else y = *(float *)((char *)arg0 + 0x6C54) +
        (float)c * (*(float *)((char *)arg0 + 0x6C58) - *(float *)((char *)arg0 + 0x6C54)) / (float)d;

    int e = *(int *)((char *)arg0 + 0x6C40);
    int f = *(int *)((char *)arg0 + 0x6C3C);
    float z;
    if (e >= f) z = *(float *)((char *)arg0 + 0x6C38);
    else z = *(float *)((char *)arg0 + 0x6C34) +
        (float)e * (*(float *)((char *)arg0 + 0x6C38) - *(float *)((char *)arg0 + 0x6C34)) / (float)f;
    return x * y * z;
}

extern "C" int DVDGetDriveStatus(void);
extern "C" void fn_80031C8C(unsigned short);
extern "C" void fn_80031C94(unsigned short);
extern "C" void fn_80031C9C(unsigned short);
extern float lbl_80560F20, lbl_80560F24, lbl_80560F30;
extern "C" void fn_800E3228(void *arg0) {
    int status = DVDGetDriveStatus();
    if (status == 0) {
        if (*((unsigned char *)arg0 + 0x6C33) != 0) {
            unsigned char *node, *current, *sentinel;
            unsigned int interruptState;
            *((unsigned char *)arg0 + 0x6C33) = 0;
            interruptState = OSDisableInterrupts();
            current = *(unsigned char **)((unsigned char *)arg0 + 0x18);
            sentinel = (unsigned char *)arg0 + 0x18;
            while (current != sentinel) {
                node = current;
                current = *(unsigned char **)node;
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                if (*(unsigned char *)(node - 0x8C) != 0) {
                    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                    *(unsigned char *)(node - 0x85) |= 2;
                }
            }
            OSRestoreInterrupts(interruptState);
        }
    } else if (status != 1 && *((unsigned char *)arg0 + 0x6C33) == 0) {
        unsigned char *node, *current, *sentinel;
        unsigned int interruptState;
        *((unsigned char *)arg0 + 0x6C33) = 1;
        interruptState = OSDisableInterrupts();
        current = *(unsigned char **)((unsigned char *)arg0 + 0x18);
        sentinel = (unsigned char *)arg0 + 0x18;
        while (current != sentinel) {
            node = current;
            current = *(unsigned char **)node;
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            if (*(unsigned char *)(node - 0x8C) != 0) {
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                *(unsigned char *)(node - 0x85) |= 2;
            }
        }
        OSRestoreInterrupts(interruptState);
    }
    {
        float scale, lower, upper;
        unsigned char *entry;
        int i;
        upper = lbl_80560F24;
        entry = (unsigned char *)arg0;
        lower = lbl_80560F20;
        i = 0;
        scale = lbl_80560F30;
        for (; i < 3; i++, entry += 0x10) {
            int changed = 0;
            int limit, value;
            volatile int *v = (volatile int *)(entry + 0x6CA8);
            value = *v; limit = *(volatile int *)(entry + 0x6CA4);
            if (value < limit) {
                value = *v; limit = *(volatile int *)(entry + 0x6CA4);
                if (value < limit) *v = value + 1;
                changed = 1;
            }
            v = (volatile int *)(entry + 0x6C78);
            value = *v; limit = *(volatile int *)(entry + 0x6C74);
            if (limit > value) {
                value = *v; limit = *(volatile int *)(entry + 0x6C74);
                if (value < limit) *v = value + 1;
                value = *v; limit = *(volatile int *)(entry + 0x6C74);
                if (limit <= value) fn_800E4364(arg0, i);
                changed = 1;
            }
            if (changed != 0) {
                float first, second, product;
                int count, total;
                count = *(volatile int *)(entry + 0x6CA8);
                total = *(volatile int *)(entry + 0x6CA4);
                product = lbl_80560F24;
                if (count >= total) first = *(float *)(entry + 0x6CA0);
                else {
                    float start = *(float *)(entry + 0x6C9C);
                    first = start + ((float)count * (*(float *)(entry + 0x6CA0) - start)) / (float)total;
                }
                if (first > upper) first = upper;
                else if (first < lower) first = lower;
                product *= first;
                count = *(volatile int *)(entry + 0x6C78);
                total = *(volatile int *)(entry + 0x6C74);
                if (count >= total) second = *(float *)(entry + 0x6C70);
                else {
                    float start = *(float *)(entry + 0x6C6C);
                    second = start + ((float)count * (*(float *)(entry + 0x6C70) - start)) / (float)total;
                }
                if (second > upper) second = upper;
                else if (second < lower) second = lower;
                product *= second;
                value = (int)(scale * product);
                switch (i) {
                case 0: fn_80031C8C((unsigned short)value); break;
                case 1: fn_80031C94((unsigned short)value); break;
                case 2: fn_80031C9C((unsigned short)value); break;
                }
            }
        }
    }
    {
        int changed = 0;
        volatile int *v;
        int value;
        v = (volatile int *)((unsigned char *)arg0 + 0x6C50);
        value = *v;
        if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C4C)) {
            value = *v;
            if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C4C)) *v = value + 1;
            changed = 1;
        }
        v = (volatile int *)((unsigned char *)arg0 + 0x6C60);
        value = *v;
        if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C5C)) {
            value = *v;
            if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C5C)) *v = value + 1;
            changed = 1;
        }
        v = (volatile int *)((unsigned char *)arg0 + 0x6C40);
        value = *v;
        if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C3C)) {
            value = *v;
            if (value < *(volatile int *)((unsigned char *)arg0 + 0x6C3C)) *v = value + 1;
            changed = 1;
        }
        if (changed != 0) {
            unsigned char *node, *current;
            unsigned int interruptState = OSDisableInterrupts();
            node = *(unsigned char **)((unsigned char *)arg0 += 0x18);
            while (node != arg0) {
                current = node;
                node = *(unsigned char **)current;
                if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                if (*(unsigned char *)(current - 0x8C) != 0) {
                    if (current == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                    *(unsigned char *)(current - 0x85) |= 0x10;
                }
            }
            OSRestoreInterrupts(interruptState);
        }
    }
}

extern "C" void *GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(void *self) {
    if (*(void **)((char *)self + 4) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x172, lbl_80321FAC);
    }
    return *(void **)((char *)self + 4);
}

extern "C" void RegisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNodePFv_v(void *self, void *node, void (*callback)(void)) {
    void *pThis = self;
    void *pNode = node;
    void (*pCallback)(void) = callback;
    unsigned int level = OSDisableInterrupts();
    if (pNode == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    *(void (**)(void))((char *)pNode + 8) = pCallback;
    void *iterator = (char *)pThis + 12;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)pThis + 8, &iterator, pNode);
    OSRestoreInterrupts(level);
}

extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void *self, void *node) {
    unsigned int level = OSDisableInterrupts();
    if (node == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)self + 8, node);
    OSRestoreInterrupts(level);
}

extern "C" void fn_80031C6C(int);
extern "C" void SetOutputMode__Q46nw4hbm3snd6detail9AxManagerFQ36nw4hbm3snd10OutputMode(void *self, int mode) {
    if (*(int *)self == mode) return;
    *(int *)self = mode;
    switch (mode) {
    case 0: fn_80031C6C(0); break;
    case 1: fn_80031C6C(1); break;
    case 2: fn_80031C6C(2); break;
    case 3: fn_80031C6C(0); break;
    }
    unsigned int interrupts = OSDisableInterrupts();
    void *end = (char *)self + 0x18;
    void *node = *(void **)((char *)self + 0x18);
    while (node != end) {
        void *next = *(void **)node;
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        if (*((unsigned char *)node - 0x8c) != 0) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
            *((unsigned char *)node - 0x85) |= 0x20;
        }
        node = next;
    }
    OSRestoreInterrupts(interrupts);
}

extern "C" int fn_800E394C(int *arg0) { return *arg0; }

extern "C" int Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *, int, int, int, void (*)(void *, int, void *), void *);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern const char lbl_80321FC8[];
extern const char lbl_80322154[];
extern const char lbl_80322130[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_800E3954(char *self, int count, int columns, int priority, void (*callback)(void *, int, void *), void *callbackArg) {

    int stolen;
    void *oldVoice;
    void *node;
    void *voice;
    unsigned int interruptState = OSDisableInterrupts();

    if (*(int *)((char *)self + 0x20) != 0) goto acquire_setup;
    stolen = 0;
    if (*(int *)((char *)self + 0x20) != 0) goto stolen_result;
    if (*(int *)((char *)self + 0x14) == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
    node = *(void **)((char *)self + 0x18);
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
    oldVoice = (char *)node - 0x1A8;
    if (oldVoice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220F4, 0x193, lbl_803220D0);
    if (*(int *)((char *)oldVoice + 0x124) <= priority) goto steal_voice;
    stolen = 0;
    goto stolen_result;
steal_voice:
    stolen = *(int *)((char *)oldVoice + 0x104) * *(int *)((char *)oldVoice + 0x108);
    Stop__Q46nw4hbm3snd6detail7AxVoiceFv(oldVoice);
    Free__Q46nw4hbm3snd6detail7AxVoiceFv(oldVoice);
    {
        void (*done)(void *, int, void *) = *(void (**)(void *, int, void *))((char *)oldVoice + 0x10C);
        if (done != 0) done(oldVoice, 2, *(void **)((char *)oldVoice + 0x110));
    }
stolen_result:
    if (stolen == 0) {
        OSRestoreInterrupts(interruptState);
        return 0;
    }
acquire_setup:
    if (*(int *)((char *)self + 0x20) == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322124, 0x1F1, lbl_80322100);
    node = *(void **)((char *)self + 0x24);
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
    voice = (char *)node - 0x1A8;
    if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220F4, 0x193, lbl_803220D0);
    if (!Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(voice, count, columns, priority, callback, callbackArg)) {
        Warning__Q26nw4hbm2dbFPCciPCce(lbl_80321F80, 0x1F1, lbl_80321FC8);
        OSRestoreInterrupts(interruptState);
        return 0;
    }
    *(unsigned int *)((char *)voice + 0x124) = (unsigned char)priority;
    unsigned int secondState = OSDisableInterrupts();
    if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *link = (char *)voice + 0x1A8;
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)self + 0x20, link);
    void *sentinel = (char *)self + 0x18;
    node = *(void **)((char *)self + 0x18);
    while (node != sentinel) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        if (*(int *)((char *)node - 0x84) > *(int *)((char *)voice + 0x124)) break;
        node = *(void **)node;
    }
    if (voice == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322154, 0x233, lbl_80322130);
    void *iterator = node;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode((char *)self + 0x14, &iterator, link);
    OSRestoreInterrupts(secondState);
    if (*((unsigned char *)self + 0x6C31) != 0) {
        node = *(void **)(self += 0x18);
        while (node != (void *)self) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
            if (*(int *)((char *)node - 0x84) != 0xFF) {
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
                void *entryVoice = (char *)node - 0x1A8;
                int row = 0;
                char *rowData = (char *)entryVoice;
                while (row < *(int *)((char *)entryVoice + 0x104)) {
                    char *buffer = rowData;
                    int column = 0;
                    while (column < *(int *)((char *)entryVoice + 0x108)) {
                        void *input = *(void **)(buffer + 0xC);
                        if (input != 0) TRKProcessInput(input, 0x10);
                        buffer += 4;
                        column++;
                    }
                    rowData += 0x10;
                    row++;
                }
            }
            node = *(void **)node;
        }
    }
    OSRestoreInterrupts(interruptState);
    return voice;
}
#pragma pop
extern "C" void fn_800E402C(void *arg0) {
    OSDisableInterrupts();
    *(u8 *)((char *)arg0 + 0x6C31) = 0;
    ((void (*)(void))OSRestoreInterrupts)();
}

extern "C" void TRKProcessInput(void *, unsigned int);
extern "C" void fn_800E4064(void *arg0, void *arg1) {
    unsigned int interrupts = OSDisableInterrupts();
    void *node = *(void **)((char *)arg0 + 0x18);
    *(unsigned char *)((char *)arg0 + 0x6c31) = 1;
    void *sentinel = (char *)arg0 + 0x18;
    while (node != sentinel) {
        if (!node) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
        if (*(unsigned int *)((char *)node - 0x84) != 0xff) {
            if (!node) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23d, lbl_803220A0);
            char *base = (char *)node - 0x1a8;
            for (int i = 0; i < *(int *)(base + 0x104); i++) {
                char *entry = base + i * 0x10;
                for (int j = 0; j < *(int *)(base + 0x108); j++) {
                    void *input = *(void **)(entry + 0xc);
                    if (input) TRKProcessInput(input, 0x10);
                    entry += 4;
                }
            }
        }
        node = *(void **)node;
    }
    OSRestoreInterrupts(interrupts);
}

#pragma use_lmw_stmw off
extern "C" void UpdateAllVoices__Q46nw4hbm3snd6detail9AxManagerFv(void *this_) {
    void *end = (char *)this_ + 0x18;
    unsigned int level = OSDisableInterrupts();
    void *iterator = *(void **)end;
    while (iterator != end) {
        void *node = iterator;
        iterator = *(void **)iterator;
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803220C4, 0x23D, lbl_803220A0);
        fn_800E4764((char *)node - 0x1A8);
    }
    OSRestoreInterrupts(level);
}
#pragma use_lmw_stmw reset
extern "C" void Clear__Q46nw4hbm2ut6detail12LinkListImplFv(void *);
extern "C" void AXRegisterAuxACallback(int, int);
extern "C" void AXRegisterAuxBCallback(int, int);
extern "C" void AXRegisterAuxCCallback(int, int);
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800E4364(void *arg0, int arg1) {
    extern const char lbl_80322198[];
    extern const char lbl_80322160[];
    extern const char lbl_80322064[];
    extern const char lbl_80322040[];
    unsigned int interrupt;
    int valid;
    void *base;
    void *list;
    void *node;
    void *sentinel;

    interrupt = OSDisableInterrupts();
    valid = 0;
    if (arg1 >= 0 && arg1 < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322198, 0xBD, lbl_80322160, arg1, 0, 3);
    base = (char *)arg0 + arg1 * 0xC;
    if (*(int *)((char *)base + 0x6CCC) == 0) {
        OSRestoreInterrupts(interrupt);
        return;
    }
    list = (char *)base + 0x6CCC;
    node = *(void **)((char *)list + 4);
    sentinel = (char *)list + 4;
    while (node != sentinel) {
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322064, 0x23D, lbl_80322040);
        (*(void (**)(void *))((char *)(*(void **)((char *)node - 4)) + 0x10))((char *)node - 4);
        node = *(void **)node;
    }
    Clear__Q46nw4hbm2ut6detail12LinkListImplFv(list);
    switch (arg1) {
    case 0: AXRegisterAuxACallback(0, 0); break;
    case 1: AXRegisterAuxBCallback(0, 0); break;
    case 2: AXRegisterAuxCCallback(0, 0); break;
    }
    OSRestoreInterrupts(interrupt);
}
#pragma pop
extern "C" void __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void *this_) {
    ((unsigned long *)this_)[0x00 / 4] = 0;
    ((unsigned long *)this_)[0x04 / 4] = 0;
    ((unsigned long *)this_)[0x08 / 4] = (unsigned long)&lbl_80322498;
    ((unsigned long *)this_)[0x10C / 4] = 0;
    ((u8 *)this_)[0x11C] = 0;
    ((u8 *)this_)[0x11D] = 0;
    ((u8 *)this_)[0x11E] = 0;
    ((u8 *)this_)[0x11F] = 0;
    ((u8 *)this_)[0x121] = 0;
    ((u8 *)this_)[0x122] = 0;
    ((u8 *)this_)[0x123] = 0;
    ((unsigned long *)this_)[0x1A8 / 4] = 0;
    ((unsigned long *)this_)[0x1AC / 4] = 0;
    ((unsigned long *)this_)[0x0C / 4] = 0;
    ((unsigned long *)this_)[0x10 / 4] = 0;
    ((unsigned long *)this_)[0x14 / 4] = 0;
    ((unsigned long *)this_)[0x18 / 4] = 0;
    ((unsigned long *)this_)[0x1C / 4] = 0;
    ((unsigned long *)this_)[0x20 / 4] = 0;
    ((unsigned long *)this_)[0x24 / 4] = 0;
    ((unsigned long *)this_)[0x28 / 4] = 0;
}

extern "C" int fn_800E4520(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma use_lmw_stmw off
extern "C" void *__dt__Q46nw4hbm3snd6detail7AxVoiceFv(void *this_, int arg1) {
    if (this_ != 0) {
        *(void **)((char *)this_ + 8) = (void *)&lbl_80322498;
        unsigned char *base;
        unsigned char *slot;
        int i;
        int j;
        base = (unsigned char *)this_;
        i = 0;
        while (i < 2) {
            slot = base;
            j = 0;
            while (j < 4) {
                void *buffer = *(void **)(slot + 0xC);
                if (buffer != 0)
                    TRKGetFreeBuffer(buffer);
                slot += 4;
                j++;
            }
            base += 0x10;
            i++;
        }
        if (arg1 > 0)
            fn_80128668(this_);
    }
    return this_;
}
#pragma use_lmw_stmw reset
extern "C" void InitParam__Q46nw4hbm3snd6detail7AxVoiceFiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *self, int count, int arg2, void (*callback)(void *, int, void *), void *arg4) {
    int i;
    for (i = 0; i < count; i++) *(int *)((char *)self + 0x2C + i * 0x34) = 0;
    *(int *)((char *)self + 0x104) = count;
    *(int *)((char *)self + 0x108) = arg2;
    *(void (**)(void *, int, void *))((char *)self + 0x10C) = callback;
    *(void **)((char *)self + 0x110) = arg4;
    *((char *)self + 0x123) = 0;
    *((char *)self + 0x11F) = 0;
    *((char *)self + 0x120) = 0;
    *((char *)self + 0x11E) = 0;
    *((char *)self + 0x121) = 1;
    *((char *)self + 0x122) = 0;
    *(float *)((char *)self + 0x188) = lbl_80560F38;
    *(float *)((char *)self + 0x18C) = lbl_80560F38;
    *(float *)((char *)self + 0x190) = lbl_80560F38;
    *(float *)((char *)self + 0x194) = lbl_80560F38;
    *(float *)((char *)self + 0x198) = lbl_80560F38;
    *(float *)((char *)self + 0x19C) = lbl_80560F3C;
    *(float *)((char *)self + 0x1A0) = lbl_80560F38;
    *(short *)((char *)self + 0x1A4) = 0;
    *(float *)((char *)self + 0x138) = lbl_80560F38;
    *(float *)((char *)self + 0x128) = lbl_80560F3C;
    *(float *)((char *)self + 0x12C) = lbl_80560F3C;
    *(float *)((char *)self + 0x130) = lbl_80560F3C;
    *(float *)((char *)self + 0x134) = lbl_80560F3C;
    *(int *)((char *)self + 0x13C) = 1;
    *(float *)((char *)self + 0x140) = lbl_80560F38;
    *(float *)((char *)self + 0x144) = lbl_80560F38;
    *(float *)((char *)self + 0x148) = lbl_80560F3C;
    *(float *)((char *)self + 0x14C) = lbl_80560F3C;
    *(float *)((char *)self + 0x150) = lbl_80560F3C;
    *(float *)((char *)self + 0x154) = lbl_80560F38;
    *(float *)((char *)self + 0x164) = lbl_80560F38;
    *(float *)((char *)self + 0x174) = lbl_80560F3C;
    *(float *)((char *)self + 0x158) = lbl_80560F38;
    *(float *)((char *)self + 0x168) = lbl_80560F38;
    *(float *)((char *)self + 0x178) = lbl_80560F3C;
    *(float *)((char *)self + 0x15C) = lbl_80560F38;
    *(float *)((char *)self + 0x16C) = lbl_80560F38;
    *(float *)((char *)self + 0x17C) = lbl_80560F3C;
    *(float *)((char *)self + 0x160) = lbl_80560F38;
    *(float *)((char *)self + 0x170) = lbl_80560F38;
    *(float *)((char *)self + 0x180) = lbl_80560F3C;
    *(float *)((char *)self + 0x184) = lbl_80560F38;
}

extern "C" int TRKInitializeMessageBuffers(unsigned int, void (*)(void *), void *);
extern "C" void VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv(void *);
extern "C" void RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void InitParam__Q46nw4hbm3snd6detail7AxVoiceFiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *, int, int, void (*)(void *, int, void *), void *);
extern const char lbl_803224E4[];
extern const char lbl_803224C0[];
#pragma use_lmw_stmw off
extern "C" int Acquire__Q46nw4hbm3snd6detail7AxVoiceFiiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(void *self, int count, int columns, int priority, void (*callback)(void *, int, void *), void *callbackArg) {
    int buffers[8], valid, rows, ncols, total, made, result, remaining, i, j;
    unsigned int bufferSize, interruptState, nextSize;
    int *bufferOut, *bufferIn;
    char *voice, *row, *manager, *node, *sentinel;
    const char *fileName = lbl_803221A8;
    valid = 0;
    if (count >= 1 && count <= 2) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x124, fileName + 0x10, count, 1, 2);
    if (count > 2) rows = 2;
    else { rows = 1; if (count >= 1) rows = count; }
    valid = 0;
    if (columns >= 1 && columns <= 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x127, fileName + 0x5C, columns, 1, 4);
    if (columns > 4) ncols = 4;
    else { ncols = 1; if (columns >= 1) ncols = columns; }
    interruptState = OSDisableInterrupts();
    bufferSize = 0x10;
    if (priority == 0xFF) bufferSize = 0x1F;
    if (*((unsigned char *)self + 0x11C) != 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x12E, fileName + 0xA8);
    total = rows * ncols;
    bufferOut = buffers;
    made = 0;
    while (made < total) {
        result = TRKInitializeMessageBuffers(bufferSize, VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv, self);
        if (result == 0) {
            remaining = total - made;
            manager = (char *)Instance__15EmissionManagerFv();
            const char *poolFile = lbl_803224E4;
            const char *poolMessage = lbl_803224C0;
            node = *(char **)(manager + 0x18);
            sentinel = manager + 0x18;
            while (node != sentinel) {
                if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(poolFile, 0x242, poolMessage);
                if (priority >= *(int *)(node - 0x84)) {
                    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(poolFile, 0x242, poolMessage);
                    remaining -= *(int *)(node - 0xA4) * *(int *)(node - 0xA0);
                    if (remaining > 0) { node = *(char **)node; continue; }
                }
                break;
            }
            if (remaining > 0) {
                bufferIn = buffers; i = 0;
                while (i < made) { TRKGetFreeBuffer((void *)(unsigned int)*bufferIn); bufferIn++; i++; }
                OSRestoreInterrupts(interruptState);
                return 0;
            }
            nextSize = bufferSize;
            if (bufferSize < 0x1F) nextSize = bufferSize + 1;
            result = TRKInitializeMessageBuffers(nextSize, VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv, self);
        }
        if (result == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName, 0x167, fileName + 0xD0);
        if (result == 0) {
            bufferIn = buffers; i = 0;
            while (i < made) { TRKGetFreeBuffer((void *)(unsigned int)*bufferIn); bufferIn++; i++; }
            OSRestoreInterrupts(interruptState);
            return 0;
        }
        *bufferOut = result; bufferOut++; made++;
    }
    voice = (char *)self; bufferIn = buffers; i = 0;
    while (i < rows) {
        row = voice; j = 0;
        while (j < ncols) {
            TRKProcessInput((void *)(unsigned int)*bufferIn, bufferSize);
            *(int *)(row + 0xC) = *bufferIn;
            bufferIn++; j++; row += 4;
        }
        voice += 0x10; i++;
    }
    InitParam__Q46nw4hbm3snd6detail7AxVoiceFiiPFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv_vPv(self, rows, ncols, callback, callbackArg);
    void *disposeManager = GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
    RegisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(disposeManager, self);
    *((unsigned char *)self + 0x11C) = 1;
    OSRestoreInterrupts(interruptState);
    return 1;
}
#pragma use_lmw_stmw reset
extern "C" void *GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(void);
extern "C" void UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(void *, void *);
extern "C" void FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(void *, void *);
#pragma use_lmw_stmw off
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *self) {
    int zero;
    int interruptState = OSDisableInterrupts();
    if (*((unsigned char *)self + 0x11C) == 0) {
        OSRestoreInterrupts(interruptState);
        return;
    }
    zero = 0;
    char *row = (char *)self;
    char *entry;
    int rowIndex = 0;
    while (rowIndex < *((int *)((char *)self + 0x104))) {
        entry = row;
        int column = 0;
        while (column < *((int *)((char *)self + 0x108))) {
            if (*((int *)(entry + 0xC)) != 0) {
                TRKGetFreeBuffer(*((void **)(entry + 0xC)));
                *((int *)(entry + 0xC)) = zero;
            }
            entry += 4;
            column++;
        }
        row += 0x10;
        rowIndex++;
    }
    *((int *)((char *)self + 0x104)) = zero;
    UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(
        GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv(), self);
    FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(
        Instance__15EmissionManagerFv(), self);
    *((unsigned char *)self + 0x11C) = zero;
    OSRestoreInterrupts(interruptState);
}
#pragma use_lmw_stmw reset
extern float lbl_80560F44;
extern const char lbl_803222A0[];
extern "C" void fn_800E5E74(void *, int, int, int, int, int, int);
extern "C" void fn_800E68EC(void *, int, int, void *, int);
extern "C" void fn_80033408(void *, int);
extern double lbl_80560F48;
#pragma fp_contract on
#pragma peephole on
extern "C" void Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(void *arg0, const void *arg1) {
    unsigned char *self = (unsigned char *)arg0;
    unsigned char *entry;
    const unsigned char *inst;
    unsigned char *output;
    unsigned char *env;
    unsigned char *mix;
    int i;
    const unsigned char *wave = (const unsigned char *)arg1;
    int format;
    if (wave[0] == 1) {
        format = 10;
    } else {
        format = 0;
        if (wave[0] == 0) format = 25;
    }
    *(int *)(self + 0x118) = format;
    *(int *)(self + 0x114) = *(int *)(wave + 4);
    entry = self;
    inst = wave;
    output = self;
    env = self + 0x30;
    mix = self + 0x58;
    i = 0;
    while (i < *(int *)(self + 0x104)) {
        if (*(int *)(entry + 0xC) != 0) {
            if (*(int *)(inst + 0x10) == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x1BC, lbl_803222A0);
            *(int *)(output + 0x2C) = *(int *)(inst + 0x10);
            *(unsigned short *)(output + 0x30) = *(unsigned short *)(inst + 0x24);
            *(unsigned short *)(output + 0x32) = *(unsigned short *)(inst + 0x26);
            *(unsigned short *)(output + 0x34) = *(unsigned short *)(inst + 0x28);
            *(unsigned short *)(output + 0x36) = *(unsigned short *)(inst + 0x2A);
            *(unsigned short *)(output + 0x38) = *(unsigned short *)(inst + 0x2C);
            *(unsigned short *)(output + 0x3A) = *(unsigned short *)(inst + 0x2E);
            *(unsigned short *)(output + 0x3C) = *(unsigned short *)(inst + 0x30);
            *(unsigned short *)(output + 0x3E) = *(unsigned short *)(inst + 0x32);
            *(unsigned short *)(output + 0x40) = *(unsigned short *)(inst + 0x34);
            *(unsigned short *)(output + 0x42) = *(unsigned short *)(inst + 0x36);
            *(unsigned short *)(output + 0x44) = *(unsigned short *)(inst + 0x38);
            *(unsigned short *)(output + 0x46) = *(unsigned short *)(inst + 0x3A);
            *(unsigned short *)(output + 0x48) = *(unsigned short *)(inst + 0x3C);
            *(unsigned short *)(output + 0x4A) = *(unsigned short *)(inst + 0x3E);
            *(unsigned short *)(output + 0x4C) = *(unsigned short *)(inst + 0x40);
            *(unsigned short *)(output + 0x4E) = *(unsigned short *)(inst + 0x42);
            *(unsigned short *)(output + 0x50) = *(unsigned short *)(inst + 0x44);
            *(unsigned short *)(output + 0x52) = *(unsigned short *)(inst + 0x46);
            *(unsigned short *)(output + 0x54) = *(unsigned short *)(inst + 0x48);
            *(unsigned short *)(output + 0x56) = *(unsigned short *)(inst + 0x4A);
            *(unsigned short *)(output + 0x58) = *(unsigned short *)(inst + 0x4C);
            *(unsigned short *)(output + 0x5A) = *(unsigned short *)(inst + 0x4E);
            *(unsigned short *)(output + 0x5C) = *(unsigned short *)(inst + 0x50);
            *(unsigned short *)(output + 0x5E) = *(unsigned short *)(inst + 0x52);
            fn_800E5E74(arg0, i, wave[1] != 0, *(int *)(self + 0x118), *(int *)(inst + 0x10), *(int *)(wave + 8), *(int *)(wave + 0xC));
            if (*(int *)(self + 0x118) == 0) {
                ((void (*)(void *, int, int, void *))fn_800E68EC)(arg0, i, *(int *)(self + 0x118), env);
                ((void (*)(void *, int, int, void *))fn_800E6A44)(arg0, i, *(int *)(self + 0x118), mix);
            }
        }
        entry += 0x10; inst += 0x44; output += 0x34; env += 0x34; mix += 0x34; i++;
    }
    float zero0;
    float zero1;
    zero1 = lbl_80560F38;
    zero0 = lbl_80560F3C;
    unsigned char *param = self;
    int j = 0;
    while (j < *(int *)(self + 0x108)) {
        *(float *)(param + 0x94) = zero1;
        j++;
        *(float *)(param + 0x98) = zero1;
        *(float *)(param + 0x9C) = zero0;
        *(float *)(param + 0xA0) = zero0;
        *(float *)(param + 0xA4) = zero0;
        *(float *)(param + 0xA8) = zero0;
        *(int *)(param + 0xAC) = 0;
        param += 0x1C;
    }
    {
        int k;
        int n;
        unsigned char *base;
        unsigned char *slot;
        base = self; k = 0;
        while (k < *(int *)(self + 0x104)) {
            slot = base; n = 0;
            while (n < *(int *)(self + 0x108)) {
                void *voice = *(void **)(slot + 0xC);
                if (voice != 0) ((void (*)(void *, int))fn_80033538)(voice, 0);
                slot += 4; n++;
            }
            base += 0x10; k++;
        }
    }
    {
        int mixMode;
        int k;
        int n;
        unsigned char *base;
        unsigned char *slot;
        register unsigned int rateInt = *(unsigned int *)(self + 0x114);
        union { double value; unsigned int words[2]; } conversion;
        conversion.words[1] = rateInt;
        conversion.words[0] = 0x43300000;
        conversion.words[1] ^= 0x80000000;
        register double converted = conversion.value;
        register double bias = lbl_80560F48;
        if ((*(float *)(self + 0x184) * (float)(converted - bias) / lbl_80560F40) > lbl_80560F44) mixMode = 2;
        else if ((*(float *)(self + 0x184) * (float)(converted - bias) / lbl_80560F40) > lbl_80560F38) mixMode = 3;
        else mixMode = 4;
        base = self; k = 0;
        while (k < *(int *)(self + 0x104)) {
            slot = base; n = 0;
            while (n < *(int *)(self + 0x108)) {
                void *voice = *(void **)(slot + 0xC);
                if (voice != 0) fn_80033408(voice, mixMode);
                slot += 4; n++;
            }
            base += 0x10; k++;
        }
    }
    self[0x11F] = 0; self[0x120] = 0; self[0x11D] = 0; self[0x11E] = 0;
    self[0x123] |= 0x70;
}
extern "C" void fn_800E519C(void *arg0) {
    unsigned int level = OSDisableInterrupts();
    u8 *p = (u8 *)arg0;
    p[0x11D] = 1;
    p[0x11F] = 0;
    p[0x123] |= 1;
    OSRestoreInterrupts(level);
}

extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *self) {
    unsigned int level;
    unsigned int innerLevel;
    void *item;
    int active;
    int innerIndex;
    int outer;
    unsigned char *row;
    unsigned char *voice;

    level = OSDisableInterrupts();
    if (*((unsigned char *)self + 0x11E) != 0) {
        innerLevel = OSDisableInterrupts();
        item = *(void **)((unsigned char *)self + 0xC);
        if (item == 0) {
            OSRestoreInterrupts(innerLevel);
            active = 0;
        } else {
            active = (*(unsigned short *)((unsigned char *)item + 0x148) == 1);
            OSRestoreInterrupts(innerLevel);
        }
        if (active != 0) {
            row = (unsigned char *)self;
            outer = 0;
            while (outer < *(int *)((unsigned char *)self + 0x104)) {
                voice = row;
                innerIndex = 0;
                while (innerIndex < *(int *)((unsigned char *)self + 0x108)) {
                    item = *(void **)(voice + 0xC);
                    if (item != 0) AXSetVoiceState(item, 0);
                    voice += 4;
                    innerIndex++;
                }
                row += 0x10;
                outer++;
            }
        }
        *((unsigned char *)self + 0x11E) = 0;
    }
    *((unsigned char *)self + 0x120) = 0;
    *((unsigned char *)self + 0x11F) = 0;
    *((unsigned char *)self + 0x11D) = 0;
    OSRestoreInterrupts(level);
}

extern "C" void Pause__Q46nw4hbm3snd6detail7AxVoiceFb(void *this_, u8 paused) {
    unsigned int level = OSDisableInterrupts();
    if (*(u8 *)((char *)this_ + 0x11F) == paused) {
        OSRestoreInterrupts(level);
        return;
    }
    *(u8 *)((char *)this_ + 0x11F) = paused;
    u8 flags = *(u8 *)((char *)this_ + 0x123);
    *(u8 *)((char *)this_ + 0x123) = flags | 2;
    OSRestoreInterrupts(level);
}

extern "C" void fn_800E5338(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x188);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x10;
    }
}

extern "C" void SetVeVolume__Q46nw4hbm3snd6detail7AxVoiceFff(void *self, float arg0, float arg1) {
    float f0 = lbl_80560F3C;
    if (arg1 < f0) {
        float f2 = arg0 > lbl_80560F38
            ? lbl_80560F38
            : (arg0 < f0 ? f0 : arg0);
        if (f2 != *(float *)((char *)self + 0x1A0)) {
            *(float *)((char *)self + 0x1A0) = f2;
            *(unsigned char *)((char *)self + 0x123) |= 0x10;
        }
    } else {
        float f3 = arg0 > lbl_80560F38
            ? lbl_80560F38
            : (arg0 < f0 ? f0 : (f0 = arg0));
        float f1 = lbl_80560F38;
        f1 = arg1 > f1
            ? f1
            : (f1 = lbl_80560F3C, (arg1 < f1 ? f1 : arg1));
        if (f1 != *(float *)((char *)self + 0x19C) || f3 != *(float *)((char *)self + 0x1A0)) {
            *(float *)((char *)self + 0x19C) = f1;
            *(float *)((char *)self + 0x1A0) = f3;
            *(unsigned char *)((char *)self + 0x123) |= 0x10;
        }
    }
}

extern "C" void fn_800E5444(void *arg0, float farg0) {
    if (farg0 != *(float *)((char *)arg0 + 0x184)) {
        *(float *)((char *)arg0 + 0x184) = farg0;
        *(unsigned char *)((char *)arg0 + 0x123) |= 8;
    }
}

extern float lbl_80560F38;
extern float lbl_80560F50;
extern float lbl_80560F54;
extern float lbl_80560F3C;
extern "C" void fn_800E5464(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F50) {
        value = lbl_80560F50;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x128);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E54A8(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F54) {
        value = lbl_80560F54;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x12C);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E54EC(void *arg0, float farg0) {
    if (farg0 != *(float *)((char *)arg0 + 0x130)) {
        *(float *)((char *)arg0 + 0x130) = farg0;
        *(unsigned char *)((char *)arg0 + 0x123) |= 0x20;
    }
}

extern "C" void fn_800E550C(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F54) {
        value = lbl_80560F54;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x134);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E5550(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x138);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x40;
    }
}

extern "C" void fn_800E5594(void *arg0, int arg1) {
    int *field = (int *)((char *)arg0 + 0x13c);
    if (arg1 != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = arg1;
        *flags |= 0x20;
    }
}

extern "C" void fn_800E55B4(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80560F38) {
        value = lbl_80560F38;
    } else if (arg1 < lbl_80560F3C) {
        value = lbl_80560F3C;
    } else {
        value = arg1;
    }
    float *field = (float *)((char *)arg0 + 0x140);
    if (value != *field) {
        unsigned char *flags = (unsigned char *)arg0 + 0x123;
        *field = value;
        *flags |= 0x20;
    }
}

extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif(void *self, int index, f32 value) {
    int valid = 0;
    if (index >= 0 && index < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2C2, lbl_803222F0, index, 0, 4);
    if (value > lbl_80560F38) value = lbl_80560F38;
    else if (value < lbl_80560F3C) value = lbl_80560F3C;
    f32 *slot = (f32 *)((char *)self + 0x154 + index * 4);
    if (value != *slot) {
        *slot = value;
        *((u8 *)self + 0x123) |= 0x20;
    }
}

extern const char lbl_803223BC[];
extern "C" void fn_800E56D0(void *arg0, float arg1) {
    float sum = arg1 + lbl_80560F38;
    float value;
    if (sum > lbl_80560F38) {
        value = sum;
    } else {
        if (sum < lbl_80560F3C) value = sum;
        else value = lbl_80560F3C;
    }
    float *field = (float *)((char *)arg0 + 0x144);
    if (value != *field) {
        *field = value;
        *((unsigned char *)arg0 + 0x123) |= 0x20;
    }
}

extern const char lbl_80322338[];
extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E5718(void *self, int channel, float volume) {
    int valid = 0;
    if (channel >= 0 && channel < 3) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2D9, lbl_80322338, channel, 0, 3);
    float result;
    if (volume > lbl_80560F38) {
        result = lbl_80560F38;
    } else if (volume < lbl_80560F3C) {
        result = lbl_80560F3C;
    } else {
        result = volume;
    }
    float *slot = (float *)((unsigned char *)self + 0x148 + channel * 4);
    if (result != *slot) {
        *slot = result;
        *((unsigned char *)self + 0x123) |= 0x20;
    }
}

extern "C" void SetRemoteSend__Q46nw4hbm3snd6detail7AxVoiceFif(void *self, int index, float value) {
    int valid = 0;
    if (index >= 0 && index < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2E5, lbl_803222F0, index, 0, 4);

    float adjusted = value + lbl_80560F38;
    if (adjusted <= lbl_80560F38) {
        if (adjusted < lbl_80560F3C) adjusted = lbl_80560F3C;
    }
    float *send = (float *)((unsigned char *)self + 0x164 + index * 4);
    if (adjusted != *send) {
        *send = adjusted;
        *((unsigned char *)self + 0x123) |= 0x20;
    }
}

extern "C" void SetRemoteOutVolume__Q46nw4hbm3snd6detail7AxVoiceFif_800E58CC(void *self, int channel, float volume) {
    int valid = 0;
    if (channel >= 0 && channel < 4) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x2F1, lbl_803222F0, channel, 0, 4);
    float value;
    if (volume > lbl_80560F38) {
    } else {
        if (volume < lbl_80560F3C) {
        } else {
            value = volume;
        }
    }
    float *slot = (float *)((unsigned char *)self + 0x174 + channel * 4);
    if (value != *slot) {
        *slot = value;
        *((unsigned char *)self + 0x123) |= 0x20;
    }
}

extern "C" void *Instance__15EmissionManagerFv(void);
extern "C" void fn_800E3DDC(void *);
void SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(void *arg0, int arg1) {
    int valid;
    valid = 0;
    if (arg1 >= 0 && arg1 <= 0xFF) valid = 1;
    if (valid == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x306, lbl_803223BC, arg1, 0, 0xFF);
    }
    *(int *)((char *)arg0 + 0x124) = arg1;
    Instance__15EmissionManagerFv();
    fn_800E3DDC(arg0);
}

extern "C" int GetCurrentPlayingDspAddress__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    unsigned int level = OSDisableInterrupts();
    void *voice = *(void **)((char *)self + 0xc);
    void *dsp = (char *)voice + 0x138;
    if (dsp == 0) {
        OSRestoreInterrupts(level);
        return 0;
    }
    int address = (*(unsigned short *)((char *)dsp + 0x84) << 16) +
                  *(unsigned short *)((char *)dsp + 0x86);
    OSRestoreInterrupts(level);
    return address;
}

extern "C" void fn_800E5A8C(void) {
    fn_800E6A44();
}

extern "C" void fn_80033538(unsigned short);
extern "C" void SetBaseAddress__Q46nw4hbm3snd6detail7AxVoiceFiPCv(void *self, int index, const void *address) {
    unsigned int level = OSDisableInterrupts();
    *(const void **)((char *)self + index * 0x34 + 0x2C) = address;
    OSRestoreInterrupts(level);
}

extern "C" int IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    unsigned int irq = OSDisableInterrupts();
    unsigned int start, end, address, buffer;
    int format;
    if (*(int *)((char *)self + 0x2c) == 0) { OSRestoreInterrupts(irq); return 0; }
    OSDisableInterrupts();
    address = *(unsigned int *)((char *)self + 0xc) + 0x138;
    if (address == 0) { OSRestoreInterrupts(irq); start = 0; }
    else { start = (*(unsigned short *)(address + 0x84) << 16) | *(unsigned short *)(address + 0x86); OSRestoreInterrupts(irq); }
    Instance__15EmissionManagerFv();
    buffer = (unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(0);
    if (buffer != 0) buffer += 0x80000000;
    format = *(int *)((char *)self + 0x118);
    switch (format) {
    case 0: end = buffer * 2 + 2; break;
    case 10: end = buffer >> 1; break;
    case 25: end = buffer; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); end = 0; break;
    }
    switch (format) {
    case 0: address = end + 0x200; break;
    case 10: address = end + 0x80; break;
    case 25: address = end + 0x100; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x362, lbl_80322438); address = end; break;
    }
    if (end <= start && start < address) { OSRestoreInterrupts(irq); return 1; }
    OSRestoreInterrupts(irq);
    return 0;
}

extern "C" int GetCurrentPlayingSample__Q46nw4hbm3snd6detail7AxVoiceCFv(void *self) {
    int level = OSDisableInterrupts();
    int size = *(int *)((char *)self + 0x2C);
    if (size == 0) {
        OSRestoreInterrupts(level);
        return 0;
    }
    int finished = IsPlayFinished__Q46nw4hbm3snd6detail7AxVoiceCFv(self);
    int inner = OSDisableInterrupts();
    void *base = *(void **)((char *)self + 0xC);
    unsigned char *pos = base ? (unsigned char *)base + 0x138 : 0;
    int position = 0;
    if (pos) {
        if (finished) position = ((int)*(unsigned short *)(pos + 0x80) << 16) + *(unsigned short *)(pos + 0x82);
        else position = ((int)*(unsigned short *)(pos + 0x84) << 16) + *(unsigned short *)(pos + 0x86);
    }
    OSRestoreInterrupts(inner);
    int format = *(int *)((char *)self + 0x118);
    if (size != 0) size += (int)0x80000000;
    int result = 0;
    switch (format) {
    case 10: result = position - ((unsigned int)size >> 1); break;
    case 0: {
        unsigned int rem = position - size * 2;
        result = ((rem & 0xF) + ((rem >> 4) * 0xE)) - 2;
        break;
    }
    case 25: result = position - size; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438); break;
    }
    OSRestoreInterrupts(level);
    return result + (finished ? 1 : 0);
}

extern "C" void SetLoopStart__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *arg0, int arg1, const void *arg2, unsigned long arg3) {
    int format;
    unsigned int interrupt;
    unsigned int value;
    unsigned int temp;
    int offset;
    int i;
    unsigned int *voice;
    unsigned int start;
    unsigned int end;

    interrupt = OSDisableInterrupts();
    format = *(int *)((char *)arg0 + 0x118);
    value = (unsigned int)arg2;
    if (arg2 != 0) value += 0x80000000;
    start = 0;
    switch (format) {
    case 0:
        temp = arg3 / 7;
        offset = (arg3 - temp) >> 1;
        temp = offset + temp;
        start = (arg3 - ((temp >> 3) * 0xE)) + (value * 2) + ((temp * 2) & 0xFFFFFFF0) + 2;
        break;
    case 25:
        start = value + arg3;
        break;
    case 10:
        start = (value >> 1) + arg3;
        break;
    default:
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438);
        break;
    }
    offset = arg1 * 0x10;
    value = start >> 16;
    end = start & 0xFFFF;
    voice = (unsigned int *)((char *)arg0 + offset);
    i = 0;
    while (i < *(int *)((char *)arg0 + 0x108)) {
        unsigned int *channel = (unsigned int *)((char *)voice[i] + 0xC);
        OSDisableInterrupts();
        *(unsigned short *)((char *)channel + 0x1B4) = value;
        *(unsigned short *)((char *)channel + 0x1B6) = end;
        temp = *(unsigned int *)((char *)channel + 0x1C);
        if (!(temp & 0x800)) *(unsigned int *)((char *)channel + 0x1C) = temp | 0x2000;
        OSRestoreInterrupts(0);
        i++;
    }
    OSRestoreInterrupts(interrupt);
}

extern "C" void SetLoopEnd__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *self, int index, const void *address, unsigned long length) {
    extern unsigned int OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(unsigned int);
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern const char lbl_803221A8[], lbl_80322438[];
    unsigned int irq = OSDisableInterrupts();
    unsigned int start = (unsigned int)address;
    unsigned int end = (unsigned int)length;
    unsigned int mode = *(unsigned int *)((char *)self + 0x118);
    unsigned int loopEnd = 0;
    unsigned int count;
    unsigned int i;
    void *voice;
    if (start != 0) start += 0x80000000;
    switch (mode) {
    case 0: {
        unsigned int n = end - 1;
        unsigned int q = n / 7;
        unsigned int x = ((n - q) >> 1) + q;
        loopEnd = n - ((x >> 3) * 14) + start * 2 + ((x * 2) & 0xFFFFFFF0) + 2;
        break;
    }
    case 25: loopEnd = start + end - 1; break;
    case 10: loopEnd = end + (start >> 1) - 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    voice = (char *)self + index * 0x10;
    count = *(unsigned int *)((char *)self + 0x108);
    for (i = 0; i < count; i++) {
        void *obj = *(void **)((char *)voice + 0xC);
        OSDisableInterrupts();
        *(unsigned short *)((char *)obj + 0x1B8) = (unsigned short)(loopEnd >> 16);
        *(unsigned short *)((char *)obj + 0x1BA) = (unsigned short)loopEnd;
        if ((*(unsigned int *)((char *)obj + 0x1C) & 0x800) == 0)
            *(unsigned int *)((char *)obj + 0x1C) |= 0x4000;
        OSRestoreInterrupts(0);
        voice = (char *)voice + 4;
    }
    OSRestoreInterrupts(irq);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void SetLoopFlag__Q46nw4hbm3snd6detail7AxVoiceFb(void *self, bool loop) {
    unsigned int level = OSDisableInterrupts();
    char *group = (char *)self;
    int i;
    for (i = 0; i < *(int *)((char *)self + 0x104); i++, group += 0x10) {
        char *entry = group;
        int j;
        for (j = 0; j < *(int *)((char *)self + 0x108); j++, entry += 4) {
            void *voice = *(void **)(entry + 0xC);
            unsigned int inner = OSDisableInterrupts();
            *(unsigned short *)((char *)voice + 0x1B0) = loop;
            unsigned int flags = *(unsigned int *)((char *)voice + 0x1C);
            if ((flags & 0x800) == 0) *(unsigned int *)((char *)voice + 0x1C) = flags | 0x1000;
            OSRestoreInterrupts(inner);
        }
    }
    OSRestoreInterrupts(level);
}

#pragma dont_inline on
extern "C" void StopAtPoint__Q46nw4hbm3snd6detail7AxVoiceFiPCvUl(void *arg0, int arg1, const void *arg2, unsigned long arg3) {
    int irq=OSDisableInterrupts();
    void *emission=Instance__15EmissionManagerFv();
    unsigned int address=(unsigned int)GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(emission);
    int format=*(int *)((char *)arg0+0x118);
    if(address) address+=0x80000000;
    unsigned int start=0;
    switch(format) {
    case 0: start=address*2+2; break;
    case 25: start=address; break;
    case 10: start=address>>1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8,0x561,lbl_80322438); break;
    }
    unsigned int offset=(unsigned int)arg2;
    if(offset) offset+=0x80000000;
    unsigned int end=0;
    switch(format) {
    case 0: {
        unsigned int x=arg3-1;
        unsigned int q=x/7;
        unsigned int t=((x-q)>>1)+q;
        end=(x-((t>>3)*0xE)) + (((unsigned int)offset)*2) + ((t*2)&0xFFFFFFF0) + 2;
        break;
    }
    case 25: end=offset+arg3-1; break;
    case 10: end=arg3+(offset>>1)-1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8,0x561,lbl_80322438); break;
    }
    unsigned int i=0;
    char *entry=(char *)arg0+arg1*0x10;
    do {
        void *voice=*(void **)(entry+0xC);
        if(voice) {
            unsigned int *flags=(unsigned int *)((char *)voice+0x1C);
            OSDisableInterrupts();
            *(unsigned short *)((char *)voice+0x1B4)=start>>16;
            *(unsigned short *)((char *)voice+0x1B6)=start;
            if(!(*flags&0x800))*flags|=0x2000;
            OSRestoreInterrupts(0);
            OSDisableInterrupts();
            *(unsigned short *)((char *)voice+0x1B8)=end>>16;
            *(unsigned short *)((char *)voice+0x1BA)=end;
            if(!(*flags&0x800))*flags|=0x4000;
            OSRestoreInterrupts(0);
            OSDisableInterrupts();
            *(unsigned short *)((char *)voice+0x1B0)=0;
            if(!(*flags&0x800))*flags|=0x1000;
            OSRestoreInterrupts(0);
        }
        entry+=4; i++;
    } while(i<*(int *)((char *)arg0+0x108));
    OSRestoreInterrupts(irq);
}
#pragma use_lmw_stmw off
extern "C" void SetVoiceType__Q46nw4hbm3snd6detail7AxVoiceFQ56nw4hbm3snd6detail7AxVoice9VoiceType(void *self, unsigned int type) {
    {
        int j;
        int i;
        unsigned char *base;
        unsigned char *slot;
        base = (unsigned char *)self;
        i = 0;
        while (i < *(int *)((unsigned char *)self + 0x104)) {
            slot = base;
            j = 0;
            while (j < *(int *)((unsigned char *)self + 0x108)) {
                void *voice = *(void **)(slot + 0xC);
                if (voice != 0)
                    ((void (*)(void *, int))fn_80033538)(voice, (unsigned short)type);
                slot += 4;
                j++;
            }
            base += 0x10;
            i++;
        }
    }
}
#pragma use_lmw_stmw reset
extern "C" void UpdateAxSrc__Q46nw4hbm3snd6detail7AxVoiceFb(void *arg0, int arg1) {
    unsigned char *self = (unsigned char *)arg0;
    float scale = (float)(*(unsigned int *)(self + 0x114));
    float ratio = (*(float *)(self + 0x184) * scale) / lbl_80560F40;
    float max = lbl_80560F38;
    float min = lbl_80560F3C;
    float gain = lbl_80560F58;
    int i = 0, offset = 0, j;
    unsigned char *src = self;
    short values[6];
    while (i < *(int *)(self + 0x108)) {
        float volume = *(float *)(src + 0x98);
        if (volume > max) volume = max;
        else if (volume < min) volume = min;
        if (arg1) {
            unsigned int sample = (unsigned int)(gain * ratio * volume);
            values[0] = (short)(sample >> 16);
            values[1] = (short)sample;
            values[2] = values[3] = values[4] = values[5] = 0;
            unsigned char *channel = self + offset;
            for (j = 0; j < *(int *)(self + 0x104); j++) {
                fn_800339B0(*(void **)(channel + 0xc), values);
                channel += 0x10;
            }
        } else {
            unsigned char *channel = self + offset;
            for (j = 0; j < *(int *)(self + 0x104); j++) {
                fn_80033A34(*(void **)(channel + 0xc), ratio * volume);
                channel += 0x10;
            }
        }
        src += 0x1c; offset += 4; i++;
    }
}

extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void fn_80033918(void *, void *);
extern "C" void fn_800E68EC(void *arg0, int arg1, int arg2, void *arg3, int arg4) {
    unsigned char sp8[0x28];
    int i;
    void **entry;
    if (arg1 >= 2)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x434, lbl_803221A8 + 0x258);
    switch (arg2) {
    case 0:
        if (arg3 == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x439, lbl_803221A8 + 0x2A0);
        memcpy(sp8, arg3, 0x20);
        *(u16 *)(sp8 + 0x20) = *(u16 *)((char *)arg3 + 0x20);
        *(u16 *)(sp8 + 0x22) = *(u16 *)((char *)arg3 + 0x22);
        *(u16 *)(sp8 + 0x24) = *(u16 *)((char *)arg3 + 0x24);
        *(u16 *)(sp8 + 0x26) = *(u16 *)((char *)arg3 + 0x26);
        break;
    case 10:
        memset(sp8, 0, 0x20);
        *(u16 *)(sp8 + 0x20) = 0x800;
        *(u16 *)(sp8 + 0x22) = 0;
        *(u16 *)(sp8 + 0x24) = 0;
        *(u16 *)(sp8 + 0x26) = 0;
        break;
    case 25:
        memset(sp8, 0, 0x20);
        *(u16 *)(sp8 + 0x20) = 0x100;
        *(u16 *)(sp8 + 0x22) = 0;
        *(u16 *)(sp8 + 0x24) = 0;
        *(u16 *)(sp8 + 0x26) = 0;
        break;
    }
    entry = (void **)((char *)arg0 + (arg1 << 4));
    for (i = 0; i < *(int *)((char *)arg0 + 0x108); i++) {
        fn_80033918(entry[3], sp8);
        entry = (void **)((char *)entry + 4);
    }
}

extern "C" void fn_800337C4(void *, unsigned short *);
extern float lbl_80560F5C;
extern "C" int fn_800E6B24(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    unsigned short sp8[2];
    float *var_r30;
    float temp_f29 = lbl_80560F5C;
    float var_f31;
    float temp_f30;
    int var_r26 = 0, var_r25 = 0, var_r28 = 0;
    unsigned char *var_r29 = p;
    var_f31 = lbl_80560F38 * *(float *)(p + 0x188);
    var_f31 *= fn_800E310C(Instance__15EmissionManagerFv());
    if (p[0x122] != 0) var_f31 = lbl_80560F3C;
    var_r30 = (float *)(p + 0x18c);
    while (var_r25 < *(int *)(p + 0x108)) {
        unsigned char *var_r27 = p + var_r28;
        int var_r24 = 0;
        temp_f30 = var_f31 * *(float *)(var_r29 + 0x94);
        while (var_r24 < *(int *)(p + 0x104)) {
            int var_r22, var_r23;
            if (p[0x121] == 0) {
                unsigned int state = OSDisableInterrupts();
                void *voice = *(void **)(p + 0xC);
                if (voice == 0) {
                    OSRestoreInterrupts(state);
                    var_r22 = 0;
                } else {
                    var_r22 = (*(unsigned short *)((unsigned char *)voice + 0x148) - 1) == 0;
                    OSRestoreInterrupts(state);
                }
                if (var_r22 != 0) {
                    var_r23 = (int)(temp_f29 * (*(float *)var_r30 * *(float *)(p + 0x19C)));
                    var_r22 = (int)(temp_f29 * (temp_f30 * *(float *)(p + 0x1A0)));
                } else {
                    var_r23 = (int)(temp_f29 * (temp_f30 * *(float *)(p + 0x19C)));
                    var_r22 = (int)(temp_f29 * (temp_f30 * *(float *)(p + 0x1A0)));
                }
            } else {
                var_r23 = (int)(temp_f29 * (temp_f30 * *(float *)(p + 0x19C)));
                var_r22 = (int)(temp_f29 * (temp_f30 * *(float *)(p + 0x1A0)));
            }
            sp8[0] = (unsigned short)var_r23;
            sp8[1] = ((unsigned short)var_r22 - (unsigned short)var_r23) / 96;
            fn_800337C4(*(void **)(var_r27 + 0xC), sp8);
            if ((unsigned short)var_r22 != (unsigned short)var_r23) var_r26 = 1;
            var_r27 += 0x10; var_r24++;
        }
        *var_r30 = temp_f30; var_r30++; var_r29 += 0x1c; var_r28 += 4; var_r25++;
    }
    if (p[0x121] == 0) {
        unsigned int state = OSDisableInterrupts();
        void *voice = *(void **)(p + 0xC);
        if (voice == 0) {
            OSRestoreInterrupts(state);
        } else {
            int ready = (*(unsigned short *)((unsigned char *)voice + 0x148) - 1) == 0;
            OSRestoreInterrupts(state);
            if (ready != 0) goto done;
        }
    } else goto done;
    p[0x121] = 0;
done:
    *(float *)(p + 0x19c) = *(float *)(p + 0x1a0);
    return var_r26;
}

extern "C" void CalcAXPBMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP8_AXPBMIX(void *, int, int, void *);
extern "C" void CalcAXPBRMTMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP11_AXPBRMTMIX(void *, int, int, void *);
extern "C" void fn_80033584(void *, void *);
extern "C" void fn_80033C8C(void *, int);
extern "C" void fn_80033CD8(void *, void *);
extern "C" void UpdateAxMix__Q46nw4hbm3snd6detail7AxVoiceFv(void *self) {
    char mix[0x30];
    char rmt[0x20];
    char *row = (char *)self;
    char *entry;
    int outer = 0;
    int inner;
    while (outer < *((int *)((char *)self + 0x104))) {
        entry = row;
        inner = 0;
        while (inner < *((int *)((char *)self + 0x108))) {
            CalcAXPBMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP8_AXPBMIX(self, outer, inner, mix);
            fn_80033584(*((void **)(entry + 0xC)), mix);
            if (*((unsigned int *)((char *)self + 0x13C)) <= 1) {
                fn_80033C8C(*((void **)(entry + 0xC)), 0);
            } else {
                CalcAXPBRMTMIX__Q46nw4hbm3snd6detail7AxVoiceFiiP11_AXPBRMTMIX(self, outer, inner, rmt);
                fn_80033C8C(*((void **)(entry + 0xC)), 1);
                fn_80033CD8(*((void **)(entry + 0xC)), rmt);
            }
            entry += 4;
            inner++;
        }
        row += 0x10;
        outer++;
    }
}

extern "C" int GetDspAddressBySample__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void* arg0, unsigned long arg1, int arg2) {
    u32 base = (u32)arg0;
    if (base != 0) base += 0x80000000;
    int result = 0;
    switch (arg2) {
    case 0: {
        u32 sample = (u32)arg1;
        u32 doubledBase = base << 1;
        u32 quotient = sample / 7;
        u32 block = quotient + ((sample - quotient) >> 1);
        u32 remainder = sample - ((block >> 3) * 14);
        result = (int)(remainder + doubledBase);
        result += (int)((block << 1) & 0xFFFFFFF0);
        result += 2;
        break;
    }
    case 25: result = base + arg1; break;
    case 10: result = (base >> 1) + arg1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x561, lbl_80322438); break;
    }
    return result;
}

extern "C" int GetSampleByDspAddress__Q46nw4hbm3snd6detail7AxVoiceFPCvUlQ56nw4hbm3snd6detail7AxVoice6Format(const void *arg0, unsigned int arg1, int arg2) {
    unsigned int address = (unsigned int)arg0;
    int result = 0;
    if (address != 0) address += 0x80000000;
    switch (arg2) {
    case 0: { unsigned int delta = arg1 - address * 2; result = ((delta & 15) + ((delta >> 4) * 14)) - 2; break; }
    case 25: result = arg1 - address; break;
    case 10: result = arg1 - (address >> 1); break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x583, lbl_80322438); break;
    }
    return result;
}

extern "C" unsigned int GetSampleByByte__Q46nw4hbm3snd6detail7AxVoiceFUlQ56nw4hbm3snd6detail7AxVoice6Format(unsigned int arg0, int arg1) {
    int result = 0;
    switch (arg1) {
    case 0:
        result = (arg0 >> 3) * 14;
        if ((arg0 & 7) != 0) result += (((int)(arg0 & 7) - 1) * 2);
        break;
    case 25: result = arg0; break;
    case 10: result = arg0 >> 1; break;
    default: Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x5A4, lbl_80322438); break;
    }
    return result;
}

extern float lbl_80560F38, lbl_80560F3C, lbl_80560F54, lbl_80560F60, lbl_80560F64, lbl_80560F68, lbl_80560F6C, lbl_80560F70, lbl_80560F74, lbl_80560F78;
void TransformDpl2Pan__Q44nw4r3snd6detail5VoiceFPfPfff(void *self, float *out0, float *out1, float a, float b) {
    float d = b - lbl_80560F38;
    float aa = a < 0.0f ? -a : a;
    float ad = d < 0.0f ? -d : d;
    if (aa == ad) {
        if (d == lbl_80560F3C) { *out0 = a; *out1 = lbl_80560F60 + lbl_80560F64 * d; }
        else { *out0 = lbl_80560F68 * a; *out1 = lbl_80560F60 + lbl_80560F6C * d; }
    } else if (a == lbl_80560F3C) {
        if (d == lbl_80560F3C) { *out0 = (lbl_80560F70 + lbl_80560F74 * (-d / a)) * aa; *out1 = lbl_80560F60 + lbl_80560F54 * d + lbl_80560F64 * a; }
        else { *out0 = (lbl_80560F70 + lbl_80560F78 * (-d / a)) * aa; *out1 = lbl_80560F60 + lbl_80560F6C * a; }
    } else if (d == lbl_80560F3C) {
        *out0 = (lbl_80560F74 * (-d / a) - lbl_80560F70) * aa; *out1 = lbl_80560F60 + lbl_80560F54 * d - lbl_80560F6C * a;
    } else { *out0 = (lbl_80560F78 * (-d / a) - lbl_80560F70) * aa; *out1 = lbl_80560F60 + lbl_80560F6C * -a; }
    *out1 += lbl_80560F38;
}

void InvalidateWaveData__Q46nw4hbm3snd6detail7AxVoiceFPCvPCv(void *self, const void *start, const void *end) {
    unsigned int irq = OSDisableInterrupts();
    if (*((u8 *)self + 0x11C)) {
        int count = *(int *)((char *)self + 0x104);
        char *voice = (char *)self;
        int found = 0;
        int i;
        for (i = count; i > 0; --i) {
            void *address = *(void **)(voice + 0x2C);
            if (start <= address && address <= end) found = 1;
            voice += 0x34;
        }
        if (found) {
            unsigned int lock = OSDisableInterrupts();
            if (*((u8 *)self + 0x11E)) {
                unsigned int nested = OSDisableInterrupts();
                void *manager = *(void **)((char *)self + 0xC);
                int last = 0;
                if (manager == 0) {
                    OSRestoreInterrupts(nested);
                } else {
                    unsigned short voices = *(unsigned short *)((char *)manager + 0x148);
                    last = (voices == 1);
                    OSRestoreInterrupts(nested);
                }
                if (last) {
                    char *row = (char *)self;
                    int rowIndex;
                    for (rowIndex = 0; rowIndex < *(int *)((char *)self + 0x104); rowIndex++) {
                        char *slot = row;
                        int slotIndex;
                        for (slotIndex = 0; slotIndex < *(int *)((char *)self + 0x108); slotIndex++) {
                            void *voiceState = *(void **)(slot + 0xC);
                            if (voiceState) AXSetVoiceState(voiceState, 0);
                            slot += 4;
                        }
                        row += 0x10;
                    }
                }
                *((u8 *)self + 0x11E) = 0;
            }
            *((u8 *)self + 0x120) = 0;
            *((u8 *)self + 0x11F) = 0;
            *((u8 *)self + 0x11D) = 0;
            OSRestoreInterrupts(lock);
            void (*callback)(void *, int, int) = *(void (**)(void *, int, int))((char *)self + 0x10C);
            if (callback) callback(self, 1, *(int *)((char *)self + 0x110));
        }
    }
    OSRestoreInterrupts(irq);
}

extern "C" void fn_800E80B4(void) {

}

extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *self, const void *bank);
extern "C" void *fn_800E80B8(void *arg0) {
    __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(arg0, (const void *)0);
    *(int *)((char *)arg0 + 0xC) = 0;
    return arg0;
}

extern "C" int fn_800E80F0(int arg0, int arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

extern "C" void *NoteOn__Q46nw4hbm3snd6detail4BankCFRCQ46nw4hbm3snd6detail10NoteOnInfo(void *self, const void *info) {
    unsigned char inst[0x10];
    unsigned char wave[0xA0];
    if (!ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(self, inst,
        *(int *)info, *(int *)((const char *)info + 4), *(int *)((const char *)info + 8))) return 0;
    if (!ReadWaveParam__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8WaveDataiPCv(self, wave,
        *(int *)(inst + 8), *(void **)((char *)self + 0xC))) return 0;
    int voices = wave[2] <= 2 ? wave[2] : 2;
    void *channel = AllocChannel__Q46nw4hbm3snd6detail7ChannelFiiiPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(
        voices, *(int *)((char *)info + 0x18), *(int *)((char *)info + 0x14),
        *(int *)((char *)info + 0x1C), *(int *)((char *)info + 0x20));
    if (channel == 0) return 0;
    *(int *)((char *)channel + 0xCC) = *(int *)((char *)info + 4);
    *(int *)((char *)channel + 0xD0) = *(int *)(wave + 0x10);
    *(float *)((char *)channel + 0xB4) =
        ((float)*(int *)((char *)info + 8) / lbl_80560F88) *
        ((float)*(int *)((char *)info + 8) / lbl_80560F88) *
        ((float)*(int *)(wave + 0x12) / lbl_80560F88);
    *(float *)((char *)channel + 0xC0) = *(float *)(wave + 0x14);
    SetAttack__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, wave[0x0C]);
    SetDecay__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, wave[0x0D]);
    SetSustain__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, wave[0x0E]);
    SetRelease__Q46nw4hbm3snd6detail12EnvGeneratorFi((char *)channel + 8, wave[0x0F]);
    *(float *)((char *)channel + 0xB8) =
        ((float)((int)wave[0x11] - 0x40) / lbl_80560F8C) +
        ((float)*(int *)((char *)info + 0x10) / lbl_80560F8C);
    *(float *)((char *)channel + 0xBC) = lbl_80560F90;
    Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(channel, wave, *(int *)((char *)info + 0xC));
    return channel;
}

extern const char lbl_803224F0[];
extern "C" void *__ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *self, const void *bank) {
    register void *result = self;
    register const unsigned char *input = (const unsigned char *)bank;
    register const char *messages = lbl_803224F0;
    *(void **)result = 0;
    *(void **)((char *)result + 4) = 0;
    *(void **)((char *)result + 8) = 0;
    if (input == 0) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x58, messages + 0xB8);
    unsigned int magic = *(unsigned int *)input;
    if (magic != 0x52424E4B) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x36, messages + 0x14);
    magic = *(unsigned int *)input;
    if (magic != 0x52424E4B) return result;
    unsigned short version = *(unsigned short *)(input + 6);
    if (version < 0x100) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x3E, messages + 0x60);
    version = *(unsigned short *)(input + 6);
    if (version < 0x100) return result;
    if (version > 0x101) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x44, messages + 0x60);
    unsigned short check = *(unsigned short *)(input + 6);
    if (check < 0x100 || check > 0x101) return result;
    *(const void **)result = input;
    const char *data = (const char *)input + *(unsigned int *)(input + 0x10);
    *(const char **)((char *)result + 4) = data;
    if (*(unsigned int *)data != 0x44415441) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x61, messages + 0xE4);
    const char *wave = (const char *)input + *(unsigned int *)(input + 0x18);
    *(const char **)((char *)result + 8) = wave;
    if (*(unsigned int *)wave != 0x57415645) Panic__Q26nw4hbm2dbFPCciPCce(messages, 0x65, messages + 0x13C);
    return result;
}

extern "C" int ReadInstInfo__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8InstInfoiii(void *arg0, void *arg1, int arg2, int arg3, int arg4) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern void *fn_800E8690(void *, void *, int);
    extern unsigned int GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void *);
    extern const char lbl_803224F0[];
    extern const char lbl_80322760[];
    extern const char lbl_80559830[];
    extern float lbl_80560FA8;
    char *base = (char *)lbl_803224F0;
    char *reader = (char *)arg0;
    char *inst = (char *)arg1;
    char *ref;
    char *entry;
    char *blob;
    int *table;
    int count;
    int value;
    unsigned int address;

    if (arg1 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x7B, base + 0x194);
    if (*(void **)reader == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base, 0x7C, base + 0x1C0);
    if (*(void **)reader == 0)
        return 0;
    table = *(int **)(reader + 4);
    count = table[2];
    if (arg2 < 0 || arg2 >= count)
        return 0;
    entry = (char *)table + arg2 * 8;
    ref = entry + 0xC;
    if ((unsigned char)entry[0xD] == 4)
        return 0;
    if ((unsigned char)entry[0xD] != 1) {
        ref = (char *)fn_800E8690(reader, ref, arg3);
        if (ref == 0)
            return 0;
    }
    if ((unsigned char)ref[1] == 4)
        return 0;
    if ((unsigned char)ref[1] != 1) {
        ref = (char *)fn_800E8690(reader, ref, arg4);
        if (ref == 0)
            return 0;
    }
    if ((unsigned char)ref[1] != 1)
        return 0;
    blob = (char *)*(int *)(reader + 4) + 8;
    if ((unsigned char)ref[1] != 1)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559830, 0x70, lbl_80322760);
    address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv((unsigned char)ref[0], *(unsigned int *)(ref + 4), blob);
    if (address == 0)
        return 0;
    value = *(int *)address;
    if (value < 0)
        return 0;
    *(int *)inst = value;
    inst[4] = ((char *)address)[4];
    inst[5] = ((char *)address)[5];
    inst[6] = ((char *)address)[6];
    inst[7] = ((char *)address)[7];
    inst[8] = ((char *)address)[0xC];
    inst[9] = ((char *)address)[0xE];
    if (*(unsigned short *)((char *)*(int *)reader + 6) == 0x101) {
        inst[0xA] = ((char *)address)[0xD];
        *(float *)(inst + 0xC) = *(float *)((char *)address + 0x10);
    } else {
        inst[0xA] = 0x7F;
        *(float *)(inst + 0xC) = lbl_80560FA8;
    }
    return 1;
}

extern "C" void *fn_800E8690(void *arg0, void *arg1, int arg2) {
    unsigned char type = *((unsigned char *)arg1 + 1);
    unsigned char *data;
    unsigned int base, address;
    int i;
    if (type == 1) return arg1;
    if (type == 0) return 0;
    if (type == 2) {
        base = *(unsigned int *)((char *)arg0 + 4) + 8;
        if (type != 2) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559820, 0x71, lbl_80322708);
        address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*(unsigned char *)arg1, *(unsigned int *)((char *)arg1 + 4), (const void *)base);
        data = (unsigned char *)address;
        if (!data) return 0;
        for (i = 0; i < data[0]; i++)
            if (arg2 <= data[i + 1]) return (void *)((((unsigned int)data[0] + 4) & ~3) + (unsigned int)(data + i * 8));
        return 0;
    }
    if (type == 3) {
        base = *(unsigned int *)((char *)arg0 + 4) + 8;
        if (type != 3) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80559828, 0x72, lbl_80322734);
        address = GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(*(unsigned char *)arg1, *(unsigned int *)((char *)arg1 + 4), (const void *)base);
        data = (unsigned char *)address;
        if (!data) return 0;
        if (arg2 < data[0] || arg2 > data[1]) return 0;
        return data + (arg2 - data[0]) * 8 + 4;
    }
    return 0;
}

extern "C" unsigned int GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(unsigned char, unsigned int, const void *);
extern "C" void fn_800FEC1C(void *, void *);
extern "C" void ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv(void *, void *, const void *);
extern "C" const char lbl_803224F0[], lbl_803226B0[], lbl_803226DC[];
extern "C" char lbl_80559818;
extern "C" void *ReadWaveParam__Q46nw4hbm3snd6detail14BankFileReaderCFPQ46nw4hbm3snd6detail8WaveDataiPCv(void *self, void *wave, int index, const void *src) {
    unsigned int count;
    void *bank;
    void *entry;
    void *base;
    unsigned int data;
    unsigned char type;
    unsigned char pad[0x18];
    if (*(void **)self == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803224F0, 0x107, lbl_803226B0);
    if (*(void **)self == 0) return 0;
    bank = *(void **)((char *)self + 8);
    if (bank == 0) return 0;
    count = *(unsigned int *)((char *)bank + 8);
    base = (char *)bank + 8;
    if ((unsigned int)index >= count) return 0;
    entry = (char *)bank + (index << 3);
    if (*((unsigned char *)entry + 0xd)) Panic__Q26nw4hbm2dbFPCciPCce(&lbl_80559818, 0x6f, lbl_803226DC);
    type = *((unsigned char *)entry + 0xc);
    data = *(unsigned int *)((char *)entry + 0x10);
    bank = (void *)(unsigned int)GetDataRefAddressImpl__Q46nw4hbm3snd6detail4UtilFQ56nw4hbm3snd6detail4Util7RefTypeUlPCv(type, data, base);
    if (bank == 0) return 0;
    fn_800FEC1C(pad, bank);
    ReadWaveParam__Q46nw4hbm3snd6detail14WaveFileReaderCFPQ46nw4hbm3snd6detail8WaveDataPCv(pad, wave, src);
    return 0;
}

extern void __ct__Q46nw4hbm3snd6detail14BankFileReaderFPCv(void *);
extern char lbl_80322880[];
extern "C" void __ct__Q44nw4r3snd6detail10BasicSoundFv(void *arg0) {
    float zeroFloat = lbl_80560FB0;
    void *vtable = &lbl_80322880;
    int zero = 0;
    int minusOne = -1;
    *(void **)arg0 = vtable;
    *(int *)((char *)arg0 + 4) = zero;
    *(int *)((char *)arg0 + 8) = zero;
    *(int *)((char *)arg0 + 0xC) = zero;
    *(int *)((char *)arg0 + 0x10) = zero;
    *(int *)((char *)arg0 + 0x14) = zero;
    *(int *)((char *)arg0 + 0x18) = zero;
    *(int *)((char *)arg0 + 0x1C) = zero;
    *(int *)((char *)arg0 + 0x20) = zero;
    *(int *)((char *)arg0 + 0x24) = zero;
    *(float *)((char *)arg0 + 0x44) = zeroFloat;
    *(float *)((char *)arg0 + 0x48) = zeroFloat;
    *(int *)((char *)arg0 + 0x4C) = zero;
    *(int *)((char *)arg0 + 0x50) = zero;
    *(float *)((char *)arg0 + 0x54) = zeroFloat;
    *(float *)((char *)arg0 + 0x58) = zeroFloat;
    *(int *)((char *)arg0 + 0x5C) = zero;
    *(int *)((char *)arg0 + 0x60) = zero;
    *(int *)((char *)arg0 + 0x78) = minusOne;
    *(float *)((char *)arg0 + 0x7C) = zeroFloat;
    *(float *)((char *)arg0 + 0x80) = zeroFloat;
    *(int *)((char *)arg0 + 0x84) = zero;
    *(int *)((char *)arg0 + 0x88) = zero;
    *(int *)((char *)arg0 + 0xB8) = zero;
    *(int *)((char *)arg0 + 0xBC) = zero;
    *(int *)((char *)arg0 + 0xC0) = zero;
    *(int *)((char *)arg0 + 0xC4) = zero;
    *(int *)((char *)arg0 + 0xC8) = zero;
    *(int *)((char *)arg0 + 0xCC) = zero;
    *(int *)((char *)arg0 + 0xD0) = zero;
    *(int *)((char *)arg0 + 0xD4) = zero;
}

extern "C" void InitParam__Q44nw4r3snd6detail10BasicSoundFv(void* self) {
    extern float lbl_80560FB4;
    int current = 0, total = 0;
    float base = lbl_80560FB0, target = lbl_80560FB4;
    *((unsigned char*)self+0x67)=0; *((unsigned char*)self+0x68)=0; *((unsigned char*)self+0x64)=0; *((unsigned char*)self+0x65)=0; *((unsigned char*)self+0x66)=0; *((unsigned char*)self+0x69)=0;
    *(int*)((char*)self+0x6c)=0; *(int*)((char*)self+0x70)=0;
    *(float*)((char*)self+0x44)=base; *(float*)((char*)self+0x48)=base; *(int*)((char*)self+0x4c)=0; *(int*)((char*)self+0x50)=0;
    *(float*)((char*)self+0x54)=target; *(float*)((char*)self+0x58)=target; *(int*)((char*)self+0x5c)=0; *(int*)((char*)self+0x60)=0;
    if (current < total) base += (float)current * (base-base)/(float)total;
    *(float*)((char*)self+0x44)=base; *(float*)((char*)self+0x48)=target; *(int*)((char*)self+0x4c)=1; *(int*)((char*)self+0x50)=0;
    *(float*)((char*)self+0x8c)=target; *(float*)((char*)self+0x98)=target; *(float*)((char*)self+0x90)=lbl_80560FB0; *(float*)((char*)self+0x94)=lbl_80560FB0;
    *(float*)((char*)self+0x7c)=target; *(float*)((char*)self+0x80)=target; *(int*)((char*)self+0x84)=0; *(int*)((char*)self+0x88)=0; *(int*)((char*)self+0xa0)=1; *((unsigned char*)self+0x9c)=0;
    *(float*)((char*)self+0xa4)=target; *(float*)((char*)self+0xa8)=target; *(float*)((char*)self+0xac)=target; *(float*)((char*)self+0xb0)=target; *(float*)((char*)self+0xb4)=target;
    *(float*)((char*)self+0x28)=target; *(float*)((char*)self+0x2c)=target; *(float*)((char*)self+0x30)=lbl_80560FB0; *(float*)((char*)self+0x34)=lbl_80560FB0; *(float*)((char*)self+0x38)=lbl_80560FB0; *(float*)((char*)self+0x3c)=lbl_80560FB0; *(int*)((char*)self+0x40)=0;
}

extern "C" void fn_800E8ADC(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x65) == 0)
        *(unsigned char *)((char *)arg0 + 0x64) = 1;
}

extern "C" void Stop__Q44nw4r3snd6detail10BasicSoundFi(void *self, int target) {
    struct SoundObj {
        virtual ~SoundObj();
        virtual void x1(); virtual void x2(); virtual void x3();
        virtual void a(); virtual void b(); virtual void c(); virtual void d();
        virtual void stop();
        virtual void f(); virtual void g(); virtual void h(); virtual void i();
        virtual void j(); virtual void k(); virtual void l(); virtual void m();
        virtual void n(); virtual void o(); virtual void p(); virtual void q();
        virtual SoundObj *get();
        virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6();
        virtual void m7(); virtual void m8(); virtual void m9();
        virtual void m10(); virtual void m11(); virtual void m12();
        virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18();
        virtual void m19(); virtual void m20(); virtual void m21();
        virtual void m22(); virtual void m23(); virtual void m24();
        virtual void m25(); virtual void m26(); virtual void m27();
        virtual void m28(); virtual void m29(); virtual void clear(int);
    };
    struct VoiceObj {
        virtual ~VoiceObj();
        virtual void x1(); virtual void x2(); virtual void x3();
        virtual int valid();
        virtual void a();
        virtual int isPlaying();
        virtual int isReady();
    };
    struct Fields {
        unsigned char pad[0x44];
        float start; float end;
        int total; int elapsed;
        unsigned char pad2[0x12];
        unsigned char flags[4];
    };
    SoundObj *sound = (SoundObj *)self;
    SoundObj *voice = sound->get();
    Fields *fields = (Fields *)self;
    if (target == 0 || ((VoiceObj *)voice)->valid() == 0 ||
        ((VoiceObj *)voice)->isPlaying() == 0 || ((VoiceObj *)voice)->isReady() != 0) {
        sound->stop();
        return;
    }
    int total = fields->total;
    int elapsed = fields->elapsed;
    float start = fields->start;
    float end = fields->end;
    float current;
    if (elapsed >= total) current = end;
    else current = start + (float)elapsed * (end - start) / (float)total;
    fields->start = current;
    fields->end = lbl_80560FB0;
    fields->total = (int)((float)target * current);
    fields->elapsed = 0;
    sound->clear(0);
    fields->flags[0] = 0; fields->flags[1] = 0;
    fields->flags[2] = 0; fields->flags[3] = 1;
}

extern "C" void fn_800E8F54(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x6C) = arg1;
    *(unsigned char *)((char *)arg0 + 0x66) = (unsigned int)((-arg1) & ~arg1) >> 31;
}

extern "C" float lbl_80560FB4;
extern "C" void FadeIn__Q44nw4r3snd6detail10BasicSoundFi(void* self, int duration) {
    if (*((unsigned char*)self + 0x69) == 0) {
        int total = *(int*)((unsigned char*)self + 0x4C);
        int current = *(int*)((unsigned char*)self + 0x50);
        float volume;
        if (current < total)
            volume = *(float*)((unsigned char*)self + 0x44) +
                     (float)current * (*(float*)((unsigned char*)self + 0x48) - *(float*)((unsigned char*)self + 0x44)) / (float)total;
        else
            volume = *(float*)((unsigned char*)self + 0x48);
        int newDuration = (int)((float)duration * (lbl_80560FB4 - volume));
        if (current < total)
            volume = *(float*)((unsigned char*)self + 0x44) +
                     (float)current * (*(float*)((unsigned char*)self + 0x48) - *(float*)((unsigned char*)self + 0x44)) / (float)total;
        else
            volume = *(float*)((unsigned char*)self + 0x48);
        *(float*)((unsigned char*)self + 0x44) = volume;
        *(float*)((unsigned char*)self + 0x48) = lbl_80560FB4;
        *(int*)((unsigned char*)self + 0x4C) = newDuration;
        *(int*)((unsigned char*)self + 0x50) = 0;
    }
}

typedef void (*vfn0_t)(void*);
extern "C" void fn_800E9070(VfObj *this_) {
    VfObj *first = this_->vf23();
    first->vf6();
}

extern "C" int fn_800E90AC(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x67) != 0;
}

extern "C" void SetPlayerPriority__Q46nw4hbm3snd6detail10BasicSoundFi(void *this_, int priority) {
    int valid = 0;
    if (priority >= 0) {
        if (priority <= 0x7F) valid = 1;
    }
    if (!valid) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x202, lbl_803227EC, priority, 0, 0x7F);
    }
    *(char *)((char *)this_ + 0x74) = priority;
    void *player = *(void **)((char *)this_ + 0x10);
    if (player != 0) {
        detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
        player = *(void **)((char *)this_ + 0x10);
        detail_InsertPriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(player, this_);
    }
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf(void *this_, float vol) {
    BasicSound *sound = (BasicSound *)this_;
    if (!(vol >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x216, lbl_80322830);
    }
    *(f32*)&((u8*)sound)[0x8C] = vol;
}

extern "C" void SetVolume__Q46nw4hbm3snd6detail10BasicSoundFfi(void *this_, float volume, int arg2) {
    char *p = (char *)this_;
    float f;
    if (!(volume >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x225, lbl_80322830);
    }
    int a = *(int *)(p + 0x84);
    int b = *(int *)(p + 0x88);
    if (b < a) {
        f = *(float *)(p + 0x7C) + ((float)(b ^ 0x8000) * (*(float *)(p + 0x80) - *(float *)(p + 0x7C))) / (float)(a ^ 0x8000);
    } else {
        f = *(float *)(p + 0x80);
    }
    *(float *)(p + 0x7C) = f;
    *(float *)(p + 0x80) = volume;
    *(int *)(p + 0x84) = arg2;
    *(int *)(p + 0x88) = 0;
}

extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800E9AAC(void *this_, float vol) {
    if (!(vol >= lbl_80560FB0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322790, 0x234, lbl_80322858);
    }

    *(float *)((char *)this_ + 0x98) = vol;
}

#pragma push
#pragma small_data off
extern float lbl_80560FB0;
#pragma pop
extern "C" void fn_800E9B18(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x90) = farg0;
}

extern "C" void fn_800E9B20(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x94) = arg1;
}

extern "C" void fn_800E9B28(void *arg0, float arg1) {
    VfObjF *obj = (VfObjF *)arg0;
    VfObjF *result = obj->vf22();
    result->vf15(arg1);
}

extern "C" void fn_800E9B74(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    *(int *)((char *)arg0 + 0x18) = arg1;
    *(int *)((char *)arg0 + 0x1C) = arg2;
    *(int *)((char *)arg0 + 0x20) = arg3;
    *(int *)((char *)arg0 + 0x24) = arg4;
}

extern "C" int fn_800E9B88(void *arg0) {
    return *(int *)((char *)arg0 + 8) != 0;
}

extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void *);
extern "C" void fn_800E9B9C(void *arg0) {
    DetachSound__Q34nw4r3snd11SoundHandleFv(*(void **)((char *)arg0 + 8));
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" void fn_800E9BA4(void *this_, int vol) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual Dispatch *call();
    };
    *(int *)((char *)this_ + 0x78) = vol;
    this_ = ((Dispatch *)this_)->call();
    *(int *)((char *)this_ + 4) = vol;
}
extern int lbl_8055DE20;
extern void fn_80128668(void);
extern "C" int fn_800E9BE4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" int *fn_800E9C24(void) {
    return &lbl_8055DE20;
}
extern const char lbl_803221A8[];
extern const char lbl_80322438[];
extern float lbl_80560F38;
extern float lbl_80560F3C;
class ShutdownA { public: virtual ~ShutdownA(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual ShutdownA *get(); };
class ShutdownB { public: virtual ~ShutdownB(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual int check(); };
class ShutdownC { public: virtual ~ShutdownC(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(float); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19(); virtual void c20(); virtual void c21(); virtual void c22(); virtual ShutdownC *get(); };
extern void DetachSound__Q34nw4r3snd11SoundHandleFv();
extern void detail_FreePlayerHeap__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern void detail_RemovePriorityList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
extern void detail_RemoveSoundList__Q36nw4hbm3snd11SoundPlayerFPQ46nw4hbm3snd6detail10BasicSound_800F8880(void *, void *);
extern void RemoveSoundList__Q46nw4hbm3snd6detail19ExternalSoundPlayerFPQ46nw4hbm3snd6detail10BasicSound(void *, void *);
#pragma push
#pragma small_data off
extern const char lbl_80322034[];
extern const char lbl_80322010[];
extern const char lbl_80322470[];
#pragma pop

extern "C" void VoiceCallback__Q46nw4hbm3snd6detail7AxVoiceFPv(void *arg0) {
    char *self = (char *)arg0;
    unsigned int level = OSDisableInterrupts();
    char *voice = (char *)*(void **)(self + 0x14);
    if (voice == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803221A8, 0x51F, lbl_80322470);
    }
    void (*callback)(void *, void *, int) = (void (*)(void *, void *, int))(*(void ***)(voice + 0x10C));
    if (callback != 0) {
        callback(voice, (void *)(*(int *)(voice + 0x110)), 3);
    }
    char *row = voice;
    int rowIndex = 0;
    int zero = 0;
    while (rowIndex < *(int *)(row + 0x104)) {
        char *entry = row;
        int column = 0;
        while (column < *(int *)(row + 0x108)) {
            int buffer = *(int *)(entry + 0xC);
            if (buffer != 0 && buffer != (int)self) {
                TRKGetFreeBuffer((void *)buffer);
            }
            entry += 4;
            column++;
        }
        row += 0x10;
        rowIndex++;
    }
    GetInstance__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv();
    UnregisterDisposeCallback__Q46nw4hbm3snd6detail22DisposeCallbackManagerFPQ46nw4hbm3snd6detail19DisposeCallbackBase(0, voice);
    Instance__15EmissionManagerFv();
    FreeVoice__Q46nw4hbm3snd6detail9AxManagerFPQ46nw4hbm3snd6detail7AxVoice(0, voice);
    *(unsigned char *)(voice + 0x11F) = zero;
    *(unsigned char *)(voice + 0x11D) = zero;
    *(int *)(voice + 0x104) = zero;
    *(unsigned char *)(voice + 0x11C) = zero;
    OSRestoreInterrupts(level);
}
