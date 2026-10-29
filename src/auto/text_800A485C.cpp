  #include <types.h>
#include <macros.h>

struct VFiPFENTIterLayout {
    volatile u32 position;
    void *stream;
    u8 pad8[0x38];
    volatile u32 index;
    u32 sentinel;
    u16 length;
    u8 pad4A[2];
    u8 data[0x20];
    u8 shift;
};
extern "C" u8 lbl_80407C00[];
extern "C" u8 lbl_80407E00[];
extern "C" { DECL_SECTION(".sdata") extern s32 lbl_805597E8; }
extern "C" { DECL_SECTION(".sdata") extern volatile u32 lbl_8055DDD0; }
extern "C" void AddAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimationLink(void *, void *);
extern "C" void AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(void *a, void *b);
class PaneAnimTransformDispatch {
public:
    virtual void d0(void *, bool);
    virtual void d1(void *, bool);
    virtual void d2(void *, bool);
    virtual void d3(void *, bool);
    virtual void d4(void *, bool);
    virtual void d5(void *, bool);
    virtual void d6(void *, bool);
    virtual void d7(void *, bool);
    virtual void d8(void *, bool);
    virtual void d9(void *, bool);
    virtual void d10(void *, bool);
    virtual void d11(void *, bool);
    virtual void d12(void *, bool);
    virtual void *bindPane(void *, bool);
    virtual void *bindMaterial(void *, bool);
};
extern "C" u8 lbl_80407560[0x18];
extern "C" const char lbl_8031E9A0[];
extern "C" s32 lbl_8055DD6C;
extern "C" s32 lbl_80559248;
extern "C" s32 *lbl_8055DD70;
extern "C" void *lbl_8055DD7C;
extern "C" const char lbl_8031B838[];
extern "C" s32 IOS_Ioctl(s32, s32, void *, s32, void *, s32);
extern u32 lbl_8055DDE0;
extern "C" s32 fn_800A58E0(void *, s32, s32, s32, s32);
extern "C" void fn_800D120C(void *, void *, s32);
extern "C" u8 lbl_802F3408[];
extern "C" void fn_800B78F4(void *, void *);
extern "C" s32 WPADSetSamplingCallback(s32, void *);
extern "C" s32 fn_800A4B9C(u16 *, u16 *, s32);
extern "C" void fn_800A71D0(void *, s32);
namespace homebutton { namespace gui { class PaneManager { public: void setAllBoundingBoxComponentTriggerTarget(bool); }; } }
namespace homebutton {
class GroupAnmController {
public:
    virtual void d0();
    virtual void calc();
    u8 pad4[8];
    f32 m_value;
    u8 pad10[4];
    s32 m_state;
    u8 pad18[8];
    void *m_list;
    void *m_pane;
    void do_calc();
};
}
static inline s32 fixedMul20(s32 lhs, s32 rhs) {
    return (s32)(((s64)lhs * rhs) >> 20);
}
struct Fn800C0440Context { u8 pad[0xC]; volatile u32 bitIndex; volatile s32 limit; };
extern "C" { DECL_SECTION(".sdata") extern s32 lbl_80559270[]; }
extern "C" s32 fn_800A485C(s32);
extern "C" s32 VFiPFCACHE_DoReadPage(void *, s32, s32, s32, s32);
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_8055920C[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_8055921C[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559220[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559224[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559228[]; }
extern "C" u32 fn_800A4C04(u8 *);
#define fn_800B4D5C_CALL fn_800B4D5##C
extern "C" s32 fn_800A4D44(void *);
extern "C" s32 fn_800A4AD0(u8 *, u8 *);
extern "C" s32 fn_800A4D74(void *, u32);
extern "C" s16 fn_800B4D5C(void *, u32, u32);
extern "C" u8 lbl_80559210, lbl_80559214, lbl_80559230, lbl_80559231;
extern "C" u16 fn_800B25CC(void *, s32);
extern "C" u32 VFiPFPATH_DoMatchFileNameWithPattern(u16, s32 *, u16, s32 *, s32);
extern "C" s32 fn_800A4E80(void *, s32, u32);
extern "C" void fn_800A4D4C(void *, void *);
extern "C" s32 fn_800AF530(void *, void *, s32, s32);
extern "C" char *fn_800A4AAC(char *, char *);
extern "C" s32 fn_800A4A8C(s32);
extern "C" s32 fn_800B7F28(void *);
extern "C" void fn_800A4B78(u16 *, u16 *);
extern "C" s32 VFiPFPATH_transformInUnicode(s16 *, s32, s32);
extern "C" void VFiPFPATH_transformFromUnicodeToNormal(u16 *, u16 *);
namespace nw4hbm { namespace lyt { class Pane; class Material; class AnimTransformBasic { public: void Animate(unsigned long, Pane *); void Animate(unsigned long, Material *); void Bind(Material *); void Bind(Pane *, bool); }; } }

extern "C" const char lbl_8031EE58[];
extern "C" { DECL_SECTION(".sdata") extern const char lbl_805597F0[]; }
extern "C" const char lbl_8031F208[];
extern "C" f32 lbl_80560E64;
class Freeable800C6A1C { public: virtual void free(s32); };
class Freeable28_800C6A1C { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void free(s32); };
extern "C" s32 fn_800A8D08(s32, void **, s32 *, s32, s32 *);
extern "C" s32 fn_800ACA5C(void *, void *, u32);
extern "C" s32 fn_800AFBA8(void *, u16, u32 *);
extern "C" s32 fn_800B00E8(void *, u16, u32 *);
extern "C" s32 fn_800B05C8(void *, u16, u32 *);
class Fn800C6610Dispatch { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(void *); };
class PaneDrawDispatch { public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14();
    virtual s32 isVisible();
};
extern "C" f32 lbl_80560E28, lbl_80560E30;
extern "C" u8 lbl_80560E2C, lbl_80560E2D, lbl_80560E2E, lbl_80560E2F;
extern "C" void updateTrigPane__Q210homebutton10HomeButtonFv(void *);
extern "C" void GXSetCullMode(s32);
extern "C" void GetLayoutRect__Q34nw4lyt6LayoutCFv(f32 *, void *);
extern "C" void *GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(void *, u32);
extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(void *, f32);
extern "C" void Start__Q210homebutton9RemoteSpkFv(void *);
extern "C" void fn_800C81F0(void *, s32);
extern "C" void fn_800D0F78(void *);
extern "C" void fn_800D11CC(void *);
extern "C" void fn_800D11E0(void *);
extern "C" void fn_800D1200(void);
extern "C" void fn_800D1300(void *);
extern "C" void fn_800D16A8(s32 *);
extern "C" f32 lbl_80560DC8, lbl_80560DCC, lbl_80560DD8;
extern "C" u8 lbl_8031D840[];
extern "C" void fn_800CF554(s32, u8 *, f32, f32, f32, f32, f32);
extern "C" s32 lbl_8031D700[];
extern "C" const char lbl_8031E764[];
extern "C" const char lbl_8031E740[];
#include <revolution/OS/OSAlarm.h>
#include <stdarg.h>
namespace nw4hbm { namespace db { namespace detail { struct ConsoleHead; } s32 Console_GetTotalLines(detail::ConsoleHead *); } }
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" const char lbl_8031EA80[];
extern "C" const char lbl_8031EA90[];
extern "C" char lbl_804077C0[];
extern "C" s32 fn_800A53B4(void *);
extern "C" const char lbl_8031F2C8[];
extern "C" const char lbl_8031F2E4[];
extern "C" const char lbl_805597F8[];
extern "C" const char lbl_805597FC[];
extern "C" u32 fn_80116BCC(void *);
extern "C" void fn_800B5CB4(void);
extern "C" void fn_800B0748(void);
extern "C" void fn_800B78EC(void);
extern "C" void fn_800B78F0(void);
extern "C" s32 fn_800B7EAC(s32 *);
extern "C" void fn_800CF27C(void);
extern "C" void fn_800CF284(void);
extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void);
extern "C" void detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(void*, void*, u32, void*, void*, void*);
extern "C" s32 lbl_802F4588[];
  #define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
typedef struct BDF4CState {
    u8 pad0[4];
    s32 field4;
    s32 field8;
    u8 padC[8];
    s32 field14;
    s32 field18;
    u8 pad1C[0x25C];
    s32 field278;
} BDF4CState;
struct VFiPFEntryCopy240 { u32 word[0x90]; };
struct VFiPFEntryLocalFrame { u8 prefix[0x78]; VFiPFEntryCopy240 copied; };
struct VFiPFEntryFlag234 { u8 pad[0x234]; u32 flag; };
extern "C" void VFipf_memcpy(void *, const void *, u32);
extern "C" s32 NANDGetLengthAsync(void *, u32 *);
extern "C" s32 NANDSeek(void *, s32, s32);
extern "C" s32 NANDClose(void *);
extern "C" s32 NANDOpen(void *, void *, s32);
extern "C" u8 lbl_80405D58[];
extern "C" s32 NANDWrite(void *, const void *, u32);
extern "C" u32 lbl_8055DDB0;
extern "C" const char lbl_8031E960[];
extern "C" const char lbl_8031E974[];
extern "C" s32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(s32);
extern "C" s32 WPADCanSendStreamData(s32);
extern "C" s32 WENCGetEncodeData(void *, u32, const s16 *, s32, void *);
extern "C" void fn_80062278(s32, void *, s32);
extern "C" void *iosAlloc(s32, s32);
extern "C" s32 iosFree(s32, void *);
extern "C" s32 IOS_Ioctlv(s32, s32, s32, s32, void *);
extern "C" s32 IOS_IoctlvAsync(s32, s32, s32, s32, void *, void *, void *);
extern "C" void *lbl_8055DD74;
extern "C" void *lbl_8055DD80;
extern "C" void fn_800BAA8C(void);

  namespace homebutton {
  namespace gui {
  struct PaneComponent {
      u8 pad0[0x28];
      void *vtable;
      u8 pad8[0x4];
      void *pane;
      u8 pad4[0x84];
  };
  }
  }
extern "C" void fn_800B36D4(s32 arg0);
extern "C" s32 fn_800B6004(void *);
extern "C" void fn_800B783C(void *arg0);
extern "C" s32 fn_800B77C0(void *arg0);
extern "C" s32 fn_800B5E14(void *arg0);
extern "C" s32 fn_800A98B8(void *arg0, s32 arg1, s32 arg2, void *arg3);
extern "C" s32 fn_800A95B4(void *arg0);
extern "C" s32 fn_800AF574(void *arg0);
extern "C" s32 fn_800AAC08(void *arg0, u32 arg1, void *arg2, void *arg3, s32 arg4, s32 *arg5);
extern "C" s32 fn_800AA924(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 *arg6, s32 *arg7);
extern "C" s32 fn_800A7090(void *arg0, s32 arg1, s32 *arg2);
extern "C" s32 fn_800A7610(void *);
extern "C" s32 fn_800A76A0(void *);
extern "C" void *lbl_8055DD94;
extern "C" u32 lbl_8055DD90;
extern "C" void fn_800C4BD8(s32 *, s32, u32);
extern "C" void fn_800C4B5C(s32, s32);
extern "C" void *fn_800C4B8C(s32);
extern "C" u32 lbl_802EEF40[];
extern "C" void fn_800BEE64(void *, s32, s32);
extern "C" void fn_800C3960(void *, s32, s32, s32);
extern "C" void fn_800C3574(void *, void *, s32, s32, s32);
extern "C" u32 lbl_802F4088[];
extern "C" u32 lbl_802F4108[];
extern "C" { DECL_SECTION(".sdata") extern s32 lbl_8055DD28; }
extern "C" s32 lbl_8055DD30;
extern "C" s32 fn_800B8004(s32);
extern "C" s32 fn_800B8048(s32);
extern "C" s32 fn_800B960C(s32, s32, s32, s32, s32 *, s32);
extern "C" s32 lbl_803D2140[];
extern "C" s32 lbl_8031D7C0[];
extern "C" void fn_800C51BC(s32 *, s32 *, s32 *);
extern "C" void fn_800C5298(s32 *, s32 *, s32 *);
extern "C" void fn_800C5430(s32 *, s32 *, s32 *);
extern "C" void fn_800C5508(void *, void *, void *);
extern "C" void fn_800C55D8(void *, void *, s32 *);
extern "C" void fn_800C56A4(void *, void *, s32);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void *lbl_80407780[];
extern "C" f32 lbl_80560E20;
extern "C" f32 lbl_80560E38;
extern "C" u8 lbl_80407600[];
extern "C" u8 lbl_8055DDA8[];
extern "C" f32 lbl_80560E40;
extern "C" f32 lbl_80560E3C;
extern "C" s32 fn_80060C7C(void*);
class D0BA4Dispatch { public: virtual ~D0BA4Dispatch(); virtual void vf1(); virtual void vf2(); virtual void vf3(D0BA4Dispatch *); };
typedef void (*Unk800B7E18Callback)(u8);
extern "C" Unk800B7E18Callback lbl_80405D00[];
extern "C" s32 lbl_80405C30[];
extern "C" s32 lbl_80405C98[];
extern "C" s32 fn_800A54AC(void *);
extern "C" void fn_800B777C(void *);
extern "C" s32 fn_800B74B8(s8);
extern "C" s32 fn_800A5990(s32);
extern "C" s32 fn_800A59CC(s32);
extern "C" s32 fn_800A71A0(s32 *);
extern "C" void fn_800B7E18(u32);
extern "C" void fn_800B7E38(u8);
  extern "C" Unk800B7E18Callback lbl_8055DD40;
  extern "C" Unk800B7E18Callback lbl_8055DD44;
  extern "C" s32 fn_800BA3F4(Unk800B7E18Callback, Unk800B7E18Callback);
extern "C" s32 fn_800BBB58(s32, void**);
extern "C" s32 fn_800BAD9C(void*, u32*);
extern "C" s32 fn_800BB2C4(void*);
extern "C" s32 IOS_Close(s32);
extern "C" u8 fn_800BA974(s32,u8*,s32);
extern "C" void fn_800A68DC(s32);
extern "C" s32 lbl_80559248;
extern "C" u32 lbl_8055DD68;
extern "C" u8 lbl_80407300[];
extern "C" s32 lbl_8055DD2C;
extern "C" s32 NANDInit(void);
extern "C" s32 NANDGetCurrentDir(char *);
struct Fn800B94ECInitArgs { s32 initialized; s32 mode; void *callback; };
extern "C" char lbl_80405D18[];
extern "C" s32 fn_800BA49C(s32, s32, s32, s32, s32 *);
extern "C" const char lbl_8031B190[];
extern "C" const char lbl_8031B1C0[];
extern "C" s32 fn_800B76E8(s8);
extern "C" s32 fn_800A4B9C(u16 *, u16 *, s32);
extern "C" s32 fn_800A4BF4(s32, u16 *, s16 *);

struct NandEntry {
    u32 key;
    u8 pad0[0x50];
    u32 length;
    u8 nand[0x94];
    s32 error;
};
extern "C" s32 NANDGetLengthAsync(void *, u32 *);
extern "C" s32 NANDSeek(void *, s32, s32);
extern "C" s32 NANDRead(void *, void *, u32);
extern "C" void VFipf_memcpy(void *, const void *, u32);
  #include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#include <revolution/ARC/arc.h>
  #include <string.h>
  #include <printf.h>
  #pragma opt_tail_call on

namespace homebutton {
class Controller {
public:
    s32 m_soundId;
    u8 pad4[0x20];
    void *m_soundPlayer;
    void updateSound();
    void clearCallback();
    s32 isPlayingSoundId(s32) const;
    int isPlayingSoundId(int) const;
};
class FrameController {
public:
    u8 pad0[4];
    f32 m_min;      // 0x4
    f32 m_max;      // 0x8
    f32 m_value;    // 0xC
    f32 m_speed;    // 0x10
    s32 m_state;    // 0x14
    s32 m_dir;      // 0x18
    u8 m_flag;      // 0x1C
    u8 pad1d[3];

    void calc();
};
class EventDispatchA { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual EventDispatchA *first(); };
class EventDispatchB { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22(); virtual void *second(); };
class HomeButtonEventHandler { public: char pad[4]; EventDispatchA *dispatch; const char *text; void onEvent(unsigned long, unsigned long, void *); };
  class TriggerLookup {
  public:
      virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
      virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
      virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
      virtual void d12();
      virtual void *findPane(const char *, s32);
  };
  class TriggerPane;
  class PaneSearch {
  public:
      virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
      virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
      virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
      virtual void d12(); virtual void d13();
      virtual TriggerPane *getPane(void *);
  };
  class TriggerPane {
  public:
      virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
      virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
      virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
      virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
      virtual void d16(); virtual void d17();
      virtual void setTrigger(s32);
  };
  struct HomeButtonPaneAccessor {
      u8 pad[0x10];
      TriggerLookup *lookup;
  };
  class HomeButton {
  public:
      s32 getPaneNo(const char *name);
      void updateTrigPane();
  };
}
extern "C" const char *lbl_8031D990[];
extern "C" const char *lbl_8031E218[];
extern "C" const char lbl_8031E770[];
extern "C" const char lbl_8031E83C[];
extern "C" void *List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(void *, u16);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" const char lbl_8031E938[];
#pragma push
#pragma small_data on
extern "C" char lbl_805597D0[4];
#pragma pop
extern "C" u32 lbl_8055DDA0;

extern "C" void* __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(void*, const void*);
extern "C" void* __dt__Q36nw4hbm3lyt4PaneFv(void*, unsigned int);
extern "C" const char lbl_8031F540[];
extern "C" const char lbl_8031F510[];
extern "C" const char lbl_8031F534[];
extern "C" int strcmp(const char*, const char*);
struct Vec2 { float x, y; };
struct Size { float x, y; };
struct DrawInfo { unsigned char pad[0x50]; unsigned char flag; };
class BoundingPane { public:
 virtual ~BoundingPane();
 virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
 virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
 virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
 virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
 virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
};
extern "C" Vec2 GetVtxPos__Q34nw4r3lyt4PaneCFv(BoundingPane*, unsigned int);
extern "C" void DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(const Vec2*, const Size*, unsigned int);

extern "C" void *fn_80128520(s32);
extern "C" void List_Append__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv(void *, void *);
namespace homebutton { namespace gui { class Manager; class Component { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void *first(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void second(Manager *); }; class Manager { public: s32 update(s32, f32, f32, unsigned long, unsigned long, unsigned long, void *); void init(); void addComponent(Component *); }; } }

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" int fn_800A6048();
extern "C" s32 fn_800A61D0(void *);
s32 fn_800B75C4(void);
void fn_800C4BD0(void) __attribute__((noreturn));
extern "C" void fn_80128668(void);
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, s32);
extern "C" void fn_800DCE10(void*, s32);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void fn_800D1B1C(s32, s32);
extern "C" void fn_800D16C4();

extern u32 lbl_8055DDB0;
extern "C" const char lbl_8031E9C0[];
DECL_SECTION(".sdata") extern u8 lbl_8055DDA8[];
extern "C" s32 fn_800D1E5C(void *arg0, s32 arg1);
extern "C" void fn_800D1668(s32 arg0, s32 arg1);
extern "C" s32 fn_800604E8(s32, s32, void *);
extern u32 lbl_8055DDF8;
extern "C" void fn_800D1C48(s32, s32);

#include <revolution/MEM/mem_allocator.h>
#include <revolution/MEM/mem_expHeap.h>
#include <revolution/MEM/mem_frameHeap.h>
#include "revolution/OS/OSError.h"
extern "C" s32 fn_800D1EA8(void *arg0, s32 arg1);

  extern "C" void fn_800B7610(void *arg0, s32 arg1, s32 arg2);
  typedef __va_list_struct VaList1;


extern "C" MEMAllocator lbl_804075E0;
extern "C" MEMAllocator* lbl_80559708;
extern "C" void* lbl_8055DD98;
extern "C" void* lbl_8055DDF0;
extern "C" const char lbl_8031F4A4[];
extern "C" const char lbl_8031F480[];
extern "C" u32 lbl_8031F428[];
extern "C" void Clear__Q46nw4hbm2ut6detail12LinkListImplFv(void*);
extern "C" void Update__Q36nw4hbm3snd18SoundArchivePlayerFv(void*);
extern "C" void updateSound__Q210homebutton10ControllerFv(void*);
extern "C" void* fn_800C6914(void*, void* = 0);
extern "C" void fn_800C6A1C(void*, s32);
extern "C" void fn_800C6CE8(void*);
extern "C" void fn_800C7998(void*);
extern "C" s32 fn_800B23F8(s32, s32, s32, s32);
extern "C" u16 VFiPFSTR_StrNumChar(s32, s32);
extern "C" s32 VFiPFSTR_StrNCmp(s32, const void*, s32, s32, s32);
extern "C" void VFiPFSTR_ToUpperNStr(s32, u16, u8*);
extern "C" s32 fn_800B63FC(void);
extern "C" void *fn_800B65A0(s8);
extern "C" s32 lbl_80559208;

extern "C" void fn_800A5954(void) {
    fn_800A6048();
}

extern "C" s32 fn_800A71D8(void *);
extern "C" s32 fn_800A73A0(void *, s32, u32, s32, s32, s32);
extern "C" s32 fn_800A7338(void *, s32 = 0);
extern "C" s32 fn_800A7568(void *, s32);
extern "C" s32 fn_800A607C(void);
extern "C" s32 fn_800A5958(void *arg0, s32 *arg1) {
    s32 result;
    *arg1 = 0;
    result = fn_800A607C();
    return result & ((-result | result) >> 31);
}

#pragma dont_inline on
extern "C" s32 fn_800A5990(s32 arg0) {
    return fn_800A61D0((void *)arg0);
}
#pragma dont_inline reset
extern "C" s32 fn_800A5994(void *arg0, s32 p1, s32 *arg2) {
    s32 result;
    *arg2 = 0;
    result = fn_800A7090(arg0, p1, arg2);
    return result & ((-result | result) >> 31);
}

extern "C" s32 fn_800A59FC(void *arg0) {
    struct State {
        u16 value0;
        u16 value2;
        u16 value4;
        u8 value6;
        u8 value7;
        u32 value8;
        u32 valueC;
        u8 pad10[0xC];
        s32 status;
        volatile u8 shift0;
        volatile u8 shift1;
        u8 pad22[2];
        s16 result24;
        u8 pad26[6];
        s32 result2C;
        s32 result30;
        u32 result34;
    };
    State *state = (State *)arg0;
    u32 value = state->value0;
    state->shift0 = 0;
    do {
        state->shift0++;
        value = (value >> 1) & 0x7FFF;
    } while (value != 0);

    value = state->value6;
    state->shift1 = 0;
    do {
        state->shift1++;
        value = (value >> 1) & 0x7FFF;
    } while (value != 0);

    s32 x = ((state->value0 + (state->value4 << 5)) - 1) >> state->shift0;
    state->result24 = (s16)x;
    s32 scaled = state->value7 * state->valueC;
    s32 base = (u16)x + state->value2;
    s32 total = scaled + base;
    state->result30 = total;
    u32 quotient = ((u32)state->value8 - total) >> state->shift1;
    state->result34 = quotient;
    if (quotient < 0xFF5) {
        state->status = 0;
        state->result2C = state->value2 + scaled;
    } else if (quotient < 0xFFF5) {
        state->status = 1;
        state->result2C = state->value2 + scaled;
    } else {
        state->status = 2;
        state->result2C = 0;
    }
}

extern "C" s32 fn_800A59FC(void *);
extern "C" s32 fn_800A6A40(void *);
extern "C" s32 fn_800A5AE4(void *arg0, void *arg1) {
    u16 temp;
    u16 var_r3, var_r3_2, var_r3_3;
    u32 var_r3_4, var_r3_5, var_r3_6;
    u16 var_r3_7, var_r3_8, var_r3_9, var_r5, temp_r3;
    u32 var_r0;
    u32 temp_r4, temp_r4_2, temp_r4_3;
    s32 temp_r0_6;
    s32 var_r30 = 0;

    if (fn_800A6A40(arg1) == 0) {
        var_r30 = 3;
    } else {

        if (((u32)arg1 + 0xB) & 1) {
            var_r3 = (M2C_FIELD(arg1, u8 *, 0xB) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 12) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0xC);
            var_r3 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
        M2C_FIELD(arg0, u16 *, 0) = var_r3;
        M2C_FIELD(arg0, u8 *, 6) = M2C_FIELD(arg1, u8 *, 0xD);

        if (((u32)arg1 + 0xE) & 1) {
            var_r3_2 = (M2C_FIELD(arg1, u8 *, 0xE) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 15) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0xE);
            var_r3_2 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
        M2C_FIELD(arg0, u16 *, 2) = var_r3_2;
        M2C_FIELD(arg0, u8 *, 7) = M2C_FIELD(arg1, u8 *, 0x10);

        if (((u32)arg1 + 0x11) & 1) {
            var_r3_3 = (M2C_FIELD(arg1, u8 *, 0x11) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 18) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x12);
            var_r3_3 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
        M2C_FIELD(arg0, u16 *, 4) = var_r3_3;
        M2C_FIELD(arg0, u8 *, 0x1A) = M2C_FIELD(arg1, u8 *, 0x15);

        if (((u32)arg1 + 0x13) & 1) {
            var_r3_4 = (M2C_FIELD(arg1, u8 *, 0x13) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 20) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x14);
            var_r3_4 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
        if (var_r3_4 == 0) {
            temp_r4 = M2C_FIELD(arg1, u32 *, 0x20);
            var_r3_5 = ((temp_r4 << 8) & 0xFF0000 & ~0xFF000000) | (temp_r4 << 0x18) |
                       (((temp_r4 >> 8U) & 0xFF00 & ~0xFF) | (temp_r4 >> 0x18U));
        } else {
            var_r3_5 = var_r3_4;
        }
        M2C_FIELD(arg0, s32 *, 8) = var_r3_5;

        if (((u32)arg1 + 0x16) & 1) {
            var_r3_6 = (M2C_FIELD(arg1, u8 *, 0x16) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 23) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x16);
            var_r3_6 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
        if (var_r3_6 == 0) {
            temp_r4_2 = M2C_FIELD(arg1, u32 *, 0x24);
            var_r0 = ((temp_r4_2 << 8) & 0xFF0000 & ~0xFF000000) | (temp_r4_2 << 0x18) |
                     (((temp_r4_2 >> 8U) & 0xFF00 & ~0xFF) | (temp_r4_2 >> 0x18U));
        } else {
            var_r0 = var_r3_6;
        }
        M2C_FIELD(arg0, s32 *, 0xC) = var_r0;
        fn_800A59FC(arg0);
        temp_r0_6 = M2C_FIELD(arg0, s32 *, 0x1C);
        if (temp_r0_6 == 2) {
            goto mode2;
        }
        if (temp_r0_6 >= 2) {
            goto invalid_type;
        }
        if (temp_r0_6 < 0) {
            goto invalid_type;
        }
        if (var_r3_6 == 0) {
            var_r30 = 4;
        }
        goto status_done;
mode2:
        if (var_r3_4 != 0 || var_r3_6 != 0) {
            var_r30 = 4;
        }
        if (((u32)arg1 + 0x2A) & 1) {
            var_r3_7 = (M2C_FIELD(arg1, u8 *, 0x2A) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 43) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x2A);
            var_r3_7 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }

        if (((u32)arg1 + 0x28) & 1) {
            var_r3_8 = (M2C_FIELD(arg1, u8 *, 0x28) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 41) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x28);
            var_r3_8 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
            M2C_FIELD(arg0, u16 *, 0x18) = var_r3_8;
            temp_r4_3 = M2C_FIELD(arg1, u32 *, 0x2C);
            M2C_FIELD(arg0, s32 *, 0x10) =
                ((temp_r4_3 << 8) & 0xFF0000 & ~0xFF000000) | (temp_r4_3 << 0x18) |
                (((temp_r4_3 >> 8U) & 0xFF00 & ~0xFF) | (temp_r4_3 >> 0x18U));

        if (((u32)arg1 + 0x30) & 1) {
            var_r3_9 = (M2C_FIELD(arg1, u8 *, 0x30) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 49) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x30);
            var_r3_9 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
            M2C_FIELD(arg0, u16 *, 0x14) = var_r3_9;

        if (((u32)arg1 + 0x32) & 1) {
            var_r5 = (M2C_FIELD(arg1, u8 *, 0x32) & 0xFF) | ((M2C_FIELD(arg1, u8 *, 51) << 8) & 0xFF00);
        } else {
            temp = *(u16 *)((u8 *)arg1 + 0x32);
            var_r5 = ((temp & 0xFF) << 8) | ((temp & 0xFF00) >> 8);
        }
            M2C_FIELD(arg0, u16 *, 0x16) = var_r5;
            M2C_FIELD(arg0, s32 *, 0x2C) =
                M2C_FIELD(arg0, s32 *, 0x30) +
                ((M2C_FIELD(arg0, s32 *, 0x10) - 2) << M2C_FIELD(arg0, u8 *, 0x21));
            if (var_r3_7 != 0)
                var_r30 = 4;
        goto status_done;
invalid_type:
        var_r30 = 4;
status_done:
        temp_r3 = M2C_FIELD(arg0, u16 *, 0x18);
        if (temp_r3 & 0x80) {
            M2C_FIELD(arg0, u8 *, 0x22) = 1;
            M2C_FIELD(arg0, s32 *, 0x28) =
                M2C_FIELD(arg0, u16 *, 2) + ((temp_r3 & 7) * M2C_FIELD(arg0, s32 *, 0xC));
        } else {
            M2C_FIELD(arg0, u8 *, 0x22) = M2C_FIELD(arg0, u8 *, 7);
            M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, u16 *, 2);
        }
    }
    return var_r30;
}

extern "C" s32 fn_800A5E00(void *arg0, void *arg1, u32 *arg2, u32 *arg3) {
 u32 a,b,c,x,y;
 *arg2=-1; *arg3=-1;
 a=M2C_FIELD(arg1,u32*,0); a=(((a<<8)|(a>>24))&0x00FF0000)|(((a<<24)|(a>>8))&0x000000FF)|(((a<<24)|(a>>8))&0x00FF0000)|(((a<<8)|(a>>24))&0xFF000000);
 if(a==0x41615252){
 b=M2C_FIELD(arg1,u32*,0x1E4); b=(((b<<8)|(b>>24))&0x00FF0000)|(((b<<24)|(b>>8))&0x000000FF)|(((b<<24)|(b>>8))&0x00FF0000)|(((b<<8)|(b>>24))&0xFF000000);
 if(b==0x61417272){
 c=M2C_FIELD(arg1,u32*,0x1FC); c=(((c<<8)|(c>>24))&0x00FF0000)|(((c<<24)|(c>>8))&0x000000FF)|(((c<<24)|(c>>8))&0x00FF0000)|(((c<<8)|(c>>24))&0xFF000000);
 if(c==0xAA550000){
 x=M2C_FIELD(arg1,u32*,0x1E8); y=M2C_FIELD(arg1,u32*,0x1EC);
 x=(((x<<8)|(x>>24))&0x00FF0000)|(((x<<24)|(x>>8))&0x000000FF)|(((x<<24)|(x>>8))&0x00FF0000)|(((x<<8)|(x>>24))&0xFF000000);
 y=(((y<<8)|(y>>24))&0x00FF0000)|(((y<<24)|(y>>8))&0x000000FF)|(((y<<24)|(y>>8))&0x00FF0000)|(((y<<8)|(y>>24))&0xFF000000);
 if(x>=2&&x<(u32)(M2C_FIELD(arg0,s32*,0x34)+2))*arg2=x;
 if(y>=2&&y<(u32)(M2C_FIELD(arg0,s32*,0x34)+2))*arg3=y;
 }}}
 return 0;
}

extern "C" s32 fn_800A7688(void *, void **, void **);
extern "C" s32 fn_800A7214(void *);
extern "C" void fn_800A535C(u32);
extern "C" void fn_800A52DC(u32);
extern "C" s32 VFipdm_disk_convert_sector_into_block(void *arg0, s32 arg1, s32 arg2, u32 size, s32 *arg4, s32 *arg5) {
    u32 shift;
    s32 result = 0;

    *arg4 = arg1;
    *arg5 = arg2;
    if (size > 0x200) {
        shift = (size >> 9) & 0x7F;
        if (shift == 2)
            *arg4 <<= 1;
        else if (shift == 4)
            *arg4 <<= 2;
        else if (shift == 8)
            *arg4 <<= 3;

        if (shift == 2)
            *arg5 <<= 1;
        else if (shift == 4)
            *arg5 <<= 2;
        else if (shift == 8)
            *arg5 <<= 3;
    } else if (size < 0x200) {
        result = 4;
    }
    return result;
}

extern "C" s32 VFipdm_disk_convert_block_into_sector(void *arg0, u32 arg1, u32 arg2, u32 size, u32 *arg4, u32 *arg5) {
    u32 shift;
    s32 result = 0;

    *arg4 = arg1;
    *arg5 = arg2;
    if (size > 0x200) {
        shift = (size >> 9) & 0x7F;
        if (shift == 2)
            *arg4 >>= 1;
        else if (shift == 4)
            *arg4 >>= 2;
        else if (shift == 8)
            *arg4 >>= 3;

        if (shift == 2)
            *arg5 >>= 1;
        else if (shift == 4)
            *arg5 >>= 2;
        else if (shift == 8)
            *arg5 >>= 3;
    } else if (size < 0x200) {
        result = 4;
    }
    return result;
}

extern "C" int fn_800A499C(const char *, int, int);

static inline s32 fn_800ACDF8LookupPage(void *arg0, s32 arg1, void **arg2, s32 *arg3) {
    typedef s32 (*LookupCall)(void *, s32, void **, s32 *);
    typedef s32 (*LookupSymbol)(s32, void **, s32 *, s32, s32 *);
    return ((LookupCall)(LookupSymbol)fn_800A8D08)(arg0, arg1, arg2, arg3);
}

static inline s32 fn_800ACDF8ClearPage(void *arg0, s32 arg1) {
    typedef s32 (*ClearCall)(void *, s32);
    typedef s32 (*ClearSymbol)(const char *, int, int);
    return ((ClearCall)(ClearSymbol)fn_800A499C)(arg0, arg1);
}
extern "C" u8 lbl_803D1640[];
extern "C" int fn_800A6048(void) {
    fn_800A499C((const char *)&lbl_803D1640, 0, 0xA2C);
    return 0;
}

extern "C" s32 fn_800B7FC4(s32);
extern "C" s32 fn_800A61D0(void *arg0) {
    volatile u32 *flags = (volatile u32 *)arg0;
    if (*(s16 *)((u8 *)arg0 + 0xC) != 0) return 0x10;
    if (*(s16 *)((u8 *)arg0 + 0xE) != 0) return 0x11;
    if (fn_800B7FC4(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x13;
    *flags &= ~1;
    *(volatile u16 *)((u8 *)&lbl_803D1640 + 2) -= 1;
    return 0;
}

#pragma dont_inline on
extern "C" s32 fn_800A625C(void *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + 0x2C) = arg1;
    return 0;
}
#pragma dont_inline reset

#pragma dont_inline on
extern "C" s32 fn_800A6268(s32 arg0, void *arg1) {
    u32 value1 = *(u32 *)((u8 *)arg0 + 0x1C);
    u32 value0 = *(u32 *)((u8 *)arg0 + 0x18);
    *(u32 *)((u8 *)arg1 + 0x0) = value0;
    *(u32 *)((u8 *)arg1 + 0x4) = value1;
    value1 = *(u32 *)((u8 *)arg0 + 0x24);
    value0 = *(u32 *)((u8 *)arg0 + 0x20);
    *(u32 *)((u8 *)arg1 + 0x8) = value0;
    *(u32 *)((u8 *)arg1 + 0xC) = value1;
    value0 = *(u32 *)((u8 *)arg0 + 0x28);
    *(u32 *)((u8 *)arg1 + 0x10) = value0;
    return 0;
}
#pragma dont_inline reset

extern "C" s32 fn_800A6298(void *arg0, u16 *arg1) {
    *arg1 = *(u16 *)((char *)arg0 + 0x20);
    return 0;
}

extern "C" s32 fn_800A62A8(void *arg0) {
    s16 state = *(s16 *)((u8 *)arg0 + 0xC);
    s32 result;
    void *obj;

    if (state == 0) {
        if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;

        obj = *(void **)((u8 *)arg0 + 4);
        result = ((s32 (*)(void *, void *))(*(u32 **)obj))(arg0, obj);

        if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
        if (result != 0) {
            fn_800A71D0((void *)*(s32 *)((u8 *)arg0 + 0x2C), result);
            return 0x15;
        }
    }

    *(s16 *)((u8 *)arg0 + 0xC) += 1;
    return 0;
}

extern "C" s32 fn_800A6358(void *arg0) {
    s16 state = *(s16 *)((u8 *)arg0 + 0xE);
    s32 result;

    if (state == 0) {
        if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
            return 0x14;

        result = ((s32 (*)(void *, void *))(*(u32 **)((u8 *)*(void **)((u8 *)arg0 + 4) + 8)))(arg0, *(void **)((u8 *)arg0 + 4));
        if (result != 0) {
            if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
                return 0x14;
            fn_800A71D0(*(void **)((u8 *)arg0 + 0x2C), result);
            return 0x15;
        }

        result = ((s32 (*)(void *, void *))(*(u32 **)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x1C)))(arg0, (u8 *)arg0 + 0x18);
        if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
            return 0x14;
        if (result != 0) {
            fn_800A71D0(*(void **)((u8 *)arg0 + 0x2C), result);
            return 0x15;
        }

        if (*(u32 *)((u8 *)arg0 + 0x24) & 1)
            *(u32 *)arg0 |= 2;
        else
            *(u32 *)arg0 &= 0xFFFFFFFD;
    }

    *(s16 *)((u8 *)arg0 + 0xE) += 1;
    return 0;
}

extern "C" void fn_800A71D0(void *, s32);
#pragma dont_inline on
extern "C" s32 fn_800A6480(void *arg0, s32 arg1) {
    s32 result;
    void *obj;
    if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
    obj = *(void **)((u8 *)arg0 + 4);
    result = ((s32 (*)(void *, s32, void *))(*(u32 **)((u8 *)obj + 0x10)))(arg0, arg1, obj);
    if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
    if (result != 0) {
        fn_800A71D0((void *)*(s32 *)((u8 *)arg0 + 0x2C), result);
        return 0x15;
    }
    return 0;
}
#pragma dont_inline reset

extern "C" s32 fn_800A6520(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 result;
    s32 (*convert)(void *, s32, s32, s32, s32 *, s32 *);
    s32 (*convert_back)(void *, s32, s32, s32, s32 *, s32 *);
    s32 (*callback)(void *, s32, s32, s32, s32 *);

    convert = (s32 (*)(void *, s32, s32, s32, s32 *, s32 *))VFipdm_disk_convert_sector_into_block;
    result = convert(arg0, arg2, arg3, arg4, &sp10, &spC);
    if (result != 0)
        return result;
    if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
        return 0x14;
    callback = *(s32 (**)(void *, s32, s32, s32, s32 *))((u8 *)*(void **)((u8 *)arg0 + 4) + 0x14);
    result = callback(arg0, arg1, sp10, spC, arg5);
    if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
        return 0x14;
    convert_back = (s32 (*)(void *, s32, s32, s32, s32 *, s32 *))VFipdm_disk_convert_block_into_sector;
    convert_back(arg0, sp10, *arg5, arg4, &sp8, arg5);
    if (result != 0) {
        fn_800A71D0((void *)*(s32 *)((u8 *)arg0 + 0x2C), result);
        return 0x15;
    }
    return 0;
}

extern "C" s32 fn_800A6624(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 result;
    s32 (*convert)(void *, s32, s32, s32, s32 *, s32 *);
    s32 (*convert_back)(void *, s32, s32, s32, s32 *, s32 *);
    s32 (*callback)(void *, s32, s32, s32, s32 *);

    convert = (s32 (*)(void *, s32, s32, s32, s32 *, s32 *))VFipdm_disk_convert_sector_into_block;
    result = convert(arg0, arg2, arg3, arg4, &sp10, &spC);
    if (result != 0)
        return result;
    if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
        return 0x14;
    callback = *(s32 (**)(void *, s32, s32, s32, s32 *))((u8 *)*(void **)((u8 *)arg0 + 4) + 0x18);
    result = callback(arg0, arg1, sp10, spC, arg5);
    if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0)
        return 0x14;
    convert_back = (s32 (*)(void *, s32, s32, s32, s32 *, s32 *))VFipdm_disk_convert_block_into_sector;
    convert_back(arg0, sp10, *arg5, arg4, &sp8, arg5);
    if (result != 0) {
        fn_800A71D0((void *)*(s32 *)((u8 *)arg0 + 0x2C), result);
        return 0x15;
    }
    return 0;
}

// Matched by preserving the unsigned arg1 comparison while using the existing s32 signature.
extern "C" s32 fn_800A6728(void *arg0, s32 arg1) {
    s16 state = *(s16 *)((u8 *)arg0 + 0xE);
    s32 result = 0;
    void *obj;
    if (state == 1) {
        if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
        obj = *(void **)((u8 *)arg0 + 4);
        result = ((s32 (*)(void *, void *))(*(u32 **)((u8 *)obj + 0xC)))(arg0, obj);
        if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
        if (result != 0) {
            fn_800A71D0(*(void **)((u8 *)arg0 + 0x2C), result);
            result = 0x15;
        }
    } else if (state == 0) return 0xE;
    if (result == 0 || (u32)arg1 == 1) *(s16 *)((u8 *)arg0 + 0xE) -= 1;
    return result;
}

extern "C" s32 fn_800A6808(void *arg0) {
    s16 state = *(s16 *)((u8 *)arg0 + 0xC);
    s32 result;
    void *obj;
    if (state == 1) {
        if (fn_800B8004(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
        obj = *(void **)((u8 *)arg0 + 4);
        result = ((s32 (*)(void *, void *))(*(u32 **)((u8 *)obj + 4)))(arg0, obj);
        if (fn_800B8048(*(s32 *)((u8 *)arg0 + 0x14)) != 0) return 0x14;
        if (result != 0) {
            fn_800A71D0((void *)*(s32 *)((u8 *)arg0 + 0x2C), result);
            return 0x15;
        }
    } else if (state == 0) return 0xD;
    *(s16 *)((u8 *)arg0 + 0xC) -= 1;
    return 0;
}

extern "C" void fn_800A76B4(void *, s32);
extern "C" void fn_800A68C8(void *arg0) {
    *(u32 *)arg0 &= 0xFFFFFFFB;
    fn_800A76B4(arg0, 0);
}

#pragma dont_inline on
extern "C" void fn_800A68DC(s32 arg0) {
    *(u32 *)arg0 |= 4;
    fn_800A76B4((void *)arg0, 1);
}

s32 fn_800A68F0(void *arg0, u32 arg1, s32 *arg2) {
    s32 sp18;
    s32 sp8;
    s16 i;
    s16 j;
    s32 *a;
    s32 *b;
    s32 temp;
    u8 *p;
    *arg2 = 0;
    p = (u8 *)arg0;
    if (p[0x1FE] != 0x55 || p[0x1FF] != 0xAA)
        return 2;
    a = &sp18;
    b = &sp8;
    i = 0;
    do {
        temp = ((u32)p[0x1C9] << 24) + ((u32)p[0x1C8] << 16) + p[0x1C6] + ((u32)p[0x1C7] << 8);
        *a = 0;
        *a = temp;
        *b = ((u32)p[0x1CD] << 24) + ((u32)p[0x1CC] << 16) + ((u32)p[0x1CB] << 8) + p[0x1CA];
        if (temp != 0 && *b != 0) {
            if (i == 0)
                *arg2 = 1;
        } else if (i == 0) {
            return 2;
        }
        i++;
        b++;
        p += 0x10;
        a++;
    } while (i < 4);
    a = &sp8;
    b = &sp18;
    i = 0;
    do {
        if ((u32)(*b + *a) > arg1) {
            if (i == 0)
                *arg2 = 0;
            return 2;
        }
        i++;
        b++;
        a++;
    } while (i < 4);
    return 0;
}

extern "C" s32 fn_800A6A40(void *arg0) {
    s32 var_r5;
    u16 temp_r0;
    u16 var_r4;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r4;

    temp_r4 = *(u8 *)((u8 *)arg0);
    var_r5 = 1;
    if (((temp_r4 != 0xEB) || ((u8)*((u8 *)arg0 + 2) != 0x90)) && (temp_r4 != 0xE9)) {
        var_r5 = 0;
    }
    if (((u8)*((u8 *)arg0 + 0x1FE) != 0x55) || ((u8)*((u8 *)arg0 + 0x1FF) != 0xAA)) {
        var_r5 = 0;
    }
    if ((s32)(((u8 *)arg0 + 0xB)) & 1) {
        var_r4 = (*((u8 *)arg0 + 0xB) & ~0xFF00) | ((*((u8 *)arg0 + 0xC) << 8) & 0xFF00);
    } else {
        temp_r0 = (u16)*((u8 *)arg0 + 0xC);
        var_r4 = ((temp_r0 << 8) & 0xFF00 & ~0xFF) | ((temp_r0 >> 8U) & 0xFF);
    }
    if ((var_r4 != 0x200) && (var_r4 != 0x400) && (var_r4 != 0x800) && (var_r4 != 0x1000)) {
        var_r5 = 0;
    }
    temp_r0_2 = *((u8 *)arg0 + 0xD);
    if ((temp_r0_2 != 1) && (temp_r0_2 != 2) && (temp_r0_2 != 4) && (temp_r0_2 != 8) && (temp_r0_2 != 0x10) && (temp_r0_2 != 0x20) && (temp_r0_2 != 0x40) && (temp_r0_2 != 0x80)) {
        var_r5 = 0;
    }
    temp_r0_3 = *((u8 *)arg0 + 0x15);
    if ((temp_r0_3 != 0xF0) && (temp_r0_3 != 0xF8) && (temp_r0_3 != 0xF9) && (temp_r0_3 != 0xFA) && (temp_r0_3 != 0xFB) && (temp_r0_3 != 0xFC) && (temp_r0_3 != 0xFD) && (temp_r0_3 != 0xFE) && (temp_r0_3 != 0xFF)) {
        var_r5 = 0;
    }
    return var_r5;
}

extern "C" s32 fn_800A6520(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5);
extern "C" s32 fn_800A68F0(void *arg0, u32 arg1, s32 *arg2);
extern "C" s32 fn_800A6B74(void *arg0) {
    s32 outLen;
    s32 flag;
    u32 tbl[8];
    u8 buf[0x200];
    s32 result;
    s32 count;
    s32 i;
    s32 j;
    u32 mode;
    u32 a;
    u32 b;
    u8 *p;

    count = 0;
    *(u32 *)((u8 *)arg0 + 0xC) = 0;
    mode = *(u32 *)((u8 *)arg0 + 8);
    *(u32 *)((u8 *)arg0 + 0x10) = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x18);
    result = fn_800A6520(*(void **)((u8 *)arg0 + 4), (s32)buf, 0, 1, 0x200, &outLen);
    if (result != 0) {
        return result;
    }
    fn_800A68F0(buf, *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x18), &flag);
    if (flag == 0) {
        if (mode >= 2) {
            return 7;
        }
        *(u32 *)((u8 *)arg0 + 0xC) = 0;
        *(u32 *)((u8 *)arg0 + 0x10) = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x18);
        return 0;
    }
    p = buf;
    tbl[4] = ((u32)p[0x1C9] << 24) + ((u32)p[0x1C8] << 16) + ((u32)p[0x1C7] << 8) + p[0x1C6];
    tbl[0] = ((u32)p[0x1CD] << 24) + ((u32)p[0x1CC] << 16) + ((u32)p[0x1CB] << 8) + p[0x1CA];
    tbl[5] = ((u32)p[0x1D9] << 24) + ((u32)p[0x1D8] << 16) + ((u32)p[0x1D7] << 8) + p[0x1D6];
    tbl[1] = ((u32)p[0x1DD] << 24) + ((u32)p[0x1DC] << 16) + ((u32)p[0x1DB] << 8) + p[0x1DA];
    tbl[6] = ((u32)p[0x1E9] << 24) + ((u32)p[0x1E8] << 16) + ((u32)p[0x1E7] << 8) + p[0x1E6];
    tbl[2] = ((u32)p[0x1ED] << 24) + ((u32)p[0x1EC] << 16) + ((u32)p[0x1EB] << 8) + p[0x1EA];
    tbl[7] = ((u32)p[0x1F9] << 24) + ((u32)p[0x1F8] << 16) + ((u32)p[0x1F7] << 8) + p[0x1F6];
    tbl[3] = ((u32)p[0x1FD] << 24) + ((u32)p[0x1FC] << 16) + ((u32)p[0x1FB] << 8) + p[0x1FA];
    i = 0;
    do {
        a = tbl[4 + i];
        b = tbl[i];
        if (a != 0) {
            if (b == 0) {
                return 7;
            }
        }
        result = fn_800A6520(*(void **)((u8 *)arg0 + 4), (s32)buf, a, 1, 0x200, &outLen);
        if (result != 0) {
            return result;
        }
        fn_800A68F0(buf, *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x18), &flag);
        if (flag == 0) {
            if (mode == (u32)count) {
                *(u32 *)((u8 *)arg0 + 0xC) = a;
                *(u32 *)((u8 *)arg0 + 0x10) = b;
                return 0;
            }
            count++;
        } else {
            a = tbl[4 + i];
            j = 0;
            do {
                b = tbl[4 + i] + tbl[4 + j];
                if (b != 0) {
                    result = fn_800A6520(*(void **)((u8 *)arg0 + 4), (s32)buf, b, 1, 0x200, &outLen);
                    if (result != 0) {
                        return result;
                    }
                    fn_800A68F0(buf, *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x18), &flag);
                    if (flag == 0) {
                        b = tbl[j];
                        if (mode == (u32)count) {
                            *(u32 *)((u8 *)arg0 + 0xC) = tbl[4 + i] + tbl[4 + j];
                            *(u32 *)((u8 *)arg0 + 0x10) = tbl[j];
                            return 0;
                        }
                        count++;
                        break;
                    }
                }
                j++;
            } while (j < 2);
        }
        i++;
    } while (i < 4);
    return 0;
}

extern "C" s32 fn_800A6FC4(void *arg0, s32 arg1, u32 arg2) {
    u16 value;
    fn_800A6298(*(void **)((u8 *)arg0 + 4), &value);
    if (arg2 == value)
        return arg1 + M2C_FIELD(arg0, u32 *, 0xC);
    u32 shift = (value >> 9) & 0x7F;
    u32 result = M2C_FIELD(arg0, u32 *, 0xC);
    if (shift == 2)
        result <<= 1;
    else if (shift == 4)
        result <<= 2;
    else if (shift == 8)
        result <<= 3;
    shift = (arg2 >> 9) & 0x7F;
    if (shift == 2)
        result >>= 1;
    else if (shift == 4)
        result >>= 2;
    else if (shift == 8)
        result >>= 3;
    return arg1 + result;
}

#pragma use_lmw_stmw off
extern "C" s32 fn_800A7090(void *arg0, s32 arg1, s32 *arg2) {
    u8 *base;
    u16 index;
    u32 pair;
    u32 table;
    u32 offset;
    u32 record;
    u16 count;
    u16 nextCount;
    s32 result;

    *arg2 = 0;
    if (*(u16 *)&lbl_803D1640 >= 0x1A)
        return 10;

    pair = 0;
    base = (u8 *)&lbl_803D1640;
    index = 0;
    for (; pair < 13; pair++) {
        u8 *entry = base + index * 0x28;
        if ((*(u32 *)(entry + 0x61C) & 1) == 0)
            goto found;
        index++;
        entry = base + index * 0x28;
        if ((*(u32 *)(entry + 0x61C) & 1) == 0)
            goto found;
        index++;
    }

found:
    if (index == 0x1A)
        return 10;

    table = (u32)&lbl_803D1640;
    offset = (u32)index * 0x28;
    result = fn_800A625C(arg0, (s32)(base + index * 0x28 + 0x61C));
    if (result != 0)
        return result;

    record = table + offset;
    count = *(u16 *)&lbl_803D1640;
    nextCount = count + 1;
    *(u16 *)&lbl_803D1640 = nextCount;
    *(u32 *)(record + 0x61C) |= 1;
    *(s32 *)(record + 0x620) = (s32)arg0;
    *(s32 *)(record + 0x624) = arg1;
    *arg2 = (s32)(record + 0x61C);
    return 0;
}
#pragma use_lmw_stmw reset

extern "C" s32 fn_800A71A0(s32 *arg0) {
    *(volatile u32 *)arg0 &= 0xFFFFFFFE;
    *(volatile u16 *)&lbl_803D1640 -= 1;
    return 0;
}

#pragma dont_inline reset

extern "C" s32 fn_800A71C4(u32 *arg0) {
    return ((u32) *arg0 >> 2U) & 1;
}

extern "C" void fn_800A71D0(void *arg0, s32 arg1) {
    (*(s32 *)((u8 *)arg0 + 0x14)) = arg1;
}

extern "C" s32 fn_800A6268(s32, void *);
extern "C" s32 fn_800A71D8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x14));
}

extern "C" s32 fn_800A71E0(s32 arg0, void *arg1) {
    s32 temp_r3;

    temp_r3 = fn_800A6268(*(s32 *)((u8 *)arg0 + 4), arg1);
    return temp_r3 & ((s32) (-temp_r3 | temp_r3) >> 0x1F);
}

extern "C" s32 fn_800A625C(void *, s32);
extern "C" s32 fn_800A62A8(void *);
extern "C" s32 fn_800A7214(void *arg0) {
    s32 result;
    if ((*(u32 *)arg0 & 4) == 0) {
        result = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
        if (result != 0) return result;
    }
    result = fn_800A62A8(*(void **)((u8 *)arg0 + 4));
    if (result != 0) return 0xB;
    *(u32 *)arg0 |= 4;
    return 0;
}

extern "C" s32 fn_800A6358(void *);
extern "C" s32 fn_800A6728(void *, s32);
extern "C" s32 fn_800A6B74(void *);
extern "C" s32 fn_800A728C(void *arg0) {
    s32 result;
    if (!(*(u32 *)arg0 & 8)) {
        result = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
        if (result == 0) {
            result = fn_800A6358(*(void **)((u8 *)arg0 + 4));
            if (result == 0) {
                result = fn_800A6B74(arg0);
                if (result != 0) {
                    fn_800A6728(*(void **)((u8 *)arg0 + 4), 0);
                } else {
                    *(u32 *)arg0 = (*(u32 *)arg0 & ~2) | 8;
                }
            }
        }
    } else {
        result = 0xC;
    }
    return result;
}

extern "C" s32 fn_800A7338(void *arg0, s32 arg1) {
    s32 result = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
    if (result != 0) {
        return result;
    }
    result = fn_800A6480(*(void **)((u8 *)arg0 + 4), arg1);
    return result & ((s32)(-result | result) >> 31);
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_800A73A0(void *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 result;
    u32 flags;
    u32 size;
    u32 end;
    flags = *(u32 *)arg0;
    if (((flags & 8) != 8) || ((flags & 2) == 2)) {
        return 0xF;
    }
    result = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
    if (result != 0) {
        return result;
    }
    size = *(u32 *)((u8 *)arg0 + 0x10);
    if (size <= arg2) {
        return 0x12;
    }
    end = arg2 + arg3;
    if (size < end) {
        arg3 -= end - size;
    }
    result = fn_800A6520(*(void **)((u8 *)arg0 + 4), arg1, fn_800A6FC4(arg0, arg2, arg4), arg3, arg4, (s32 *)arg5);
    if (result != 0) {
        return result;
    }
    return 0;
}

extern "C" s32 fn_800A7484(void *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 result;
    u32 flags;
    u32 size;
    u32 end;
    flags = *(u32 *)arg0;
    if (((flags & 8) != 8) || ((flags & 2) == 2)) {
        return 0xF;
    }
    result = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
    if (result != 0) {
        return result;
    }
    size = *(u32 *)((u8 *)arg0 + 0x10);
    if (size <= arg2) {
        return 0x12;
    }
    end = arg2 + arg3;
    if (size < end) {
        arg3 -= end - size;
    }
    result = fn_800A6624(*(void **)((u8 *)arg0 + 4), arg1, fn_800A6FC4(arg0, arg2, arg4), arg3, arg4, (s32 *)arg5);
    if (result != 0) {
        return result;
    }
    return 0;
}

#pragma pop

#pragma dont_inline on
extern "C" s32 fn_800A7568(void *arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r31 = 0;
    if (*(s32 *)arg0 & 8) {
        temp_r3 = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
        if (temp_r3 != 0) return temp_r3;
        temp_r3_2 = fn_800A6728(*(void **)((u8 *)arg0 + 4), arg1);
        if (temp_r3_2 != 0) var_r31 = temp_r3_2;
    } else var_r31 = 0xE;
    if ((var_r31 == 0) || ((u32)arg1 == 1U)) {
        *(u32 *)arg0 &= ~2U;
        *(u32 *)arg0 &= ~8U;
    }
    return var_r31;
}

extern "C" s32 fn_800A7610(void *arg0) {
    s32 temp;
    if ((*(u32 *)arg0 & 4) != 0) {
        temp = fn_800A625C(*(void **)((u8 *)arg0 + 4), (s32)arg0);
        if (temp != 0) goto done;
    }
    temp = fn_800A6808(*(void **)((u8 *)arg0 + 4));
    if (temp != 0) temp = 0xD;
done:
    if (temp == 0) {
        *(u32 *)arg0 &= ~4U;
        return 0;
    }
    return temp;
}

extern "C" s32 fn_800A7688(void *arg0, void **arg1, void **arg2) {
    *(void **)((u8 *)arg0 + 0x20) = arg1[0];
    *(void **)((u8 *)arg0 + 0x24) = arg1[1];
    return 0;
}

extern "C" s32 fn_800A76A0(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x20) = 0;
    *(u32 *)((u8 *)arg0 + 0x24) = 0;
    return 0;
}

extern "C" void fn_800A76B4(void *arg0, s32 arg1) {
    u16 index;

    for (index = 0; index < 0x1A; index++) {
        u8 *entry = (u8 *)lbl_803D1640 + index * 0x28;
        s32 flags = *(s32 *)(entry + 0x61C);

        if ((flags & 1) == 0)
            continue;
        if (*(void **)(entry + 0x620) != arg0)
            continue;

        *(s32 *)(entry + 0x61C) = flags | 2;
        if (arg1 == 0 && *(void (**)(void))(entry + 0x640) != 0) {
            (*(void (**)(void))(entry + 0x640))();
        } else if (*(void (**)(void))(entry + 0x63C) != 0) {
            (*(void (**)(void))(entry + 0x63C))();
        }
    }
}

extern "C" s32 VFiPFCACHE_SearchForPage(s32 arg0, s32 arg1, s32 arg2) {
    u32 page = (u32)arg2;
    u32 node;
    u32 start;

    if (page + 0x10000 == 0xFFFFU)
        return 0;
    if ((*(u16 *)arg1 & 1) == 0)
        return 0;

    start = *(u32 *)(arg1 + 0x18);
    if (start <= page && start + *(u32 *)(arg1 + 0x14) - 1 >= page) {
        *(u32 *)(arg1 + 8) = *(u32 *)(arg1 + 4) + ((page - start) << *(u8 *)(arg0 + 0x20));
        return arg1;
    }

    node = *(u32 *)(arg1 + 0x20);
    while (node != (u32)arg1) {
        if ((*(u16 *)node & 1) == 0)
            return 0;
        start = *(u32 *)(node + 0x18);
        if (start <= page && start + *(u32 *)(node + 0x14) - 1 >= page) {
            *(u32 *)(node + 8) = *(u32 *)(node + 4) + ((page - start) << *(u8 *)(arg0 + 0x20));
            return node;
        }
        node = *(u32 *)(node + 0x20);
    }
    return 0;
}

extern "C" s32 VFiPFCACHE_SearchForFreePage(void *arg0, void **arg1) {
    void *page = *(void **)((u8 *)arg0 + 0x24);
    while (page != arg0) {
        u16 flags = *(u16 *)page;
        if ((flags & 1) == 0) {
            *arg1 = page;
            return 1;
        }
        if (*(u32 *)((u8 *)page + 0x18) != 0xFFFFFFFF) {
            *arg1 = page;
            return 0;
        }
        page = *(void **)((u8 *)page + 0x24);
    }
    if ((*(u16 *)page & 1) == 0) {
        *arg1 = page;
        return 1;
    }
    if (*(u32 *)((u8 *)page + 0x18) != 0xFFFFFFFF) {
        *arg1 = page;
        return 0;
    }
    *arg1 = 0;
    return 0;
}

extern "C" s32 fn_800A7B34(void *arg0, void *arg1) {
    u32 out;
    u8 shift;
    u32 base;
    u32 expected;
    s32 result;
    u32 pageCount;
    u32 blockEnd;
    s32 blockLength;

    if (arg1 != 0) {
        if ((*(u16 *)arg1 & 2) != 0) {
            base = *(u32 *)((u8 *)arg1 + 0x18);
            if (base != 0xFFFFFFFFU) {
                blockLength = *(s32 *)((u8 *)arg1 + 0x0C);
                if (blockLength == 0) {
                    expected = *(u32 *)((u8 *)arg1 + 0x14);
                    result = fn_800A58E0(arg0, *(s32 *)((u8 *)arg1 + 4), (s32)base, (s32)expected, (s32)&out);
                } else {
                    shift = *(u8 *)((u8 *)arg0 + 0x20);
                    pageCount = (*(u32 *)((u8 *)arg1 + 0x10) >> shift) - ((u32)blockLength >> shift) + 1;
                    blockEnd = base + (((u32)blockLength - *(u32 *)((u8 *)arg1 + 4)) >> shift);
                    result = fn_800A58E0(arg0, blockLength, (s32)blockEnd, (s32)pageCount, (s32)&out);
                    expected = pageCount;
                }
                if (result != 0) {
                    return result;
                }
                if (out != expected) {
                    return 0x11;
                }
                u32 flags = *(u16 *)arg1;
                *(u32 *)((u8 *)arg1 + 0x0C) = 0;
                *(u32 *)((u8 *)arg1 + 0x10) = 0;
                *(u16 *)arg1 = (u16)(flags & 0xFFFFFFFD);
            }
        }
    }
    return 0;
}

extern "C" s32 fn_800A7B34(void *, void *);
extern "C" s32 fn_800A8504(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r7_2;
    void *temp_r7;
    void *temp_r8;
    volatile u16 *flags;
    temp_r7 = *(void **)arg1;
    if ((void *)arg2 != temp_r7) {
        if ((void *)arg2 == (void *)M2C_FIELD(temp_r7, void **, 0x24)) *(void **)arg1 = (void *)arg2;
        else {
            M2C_FIELD(M2C_FIELD((void *)arg2, void **, 0x24), void **, 0x20) = (void *)M2C_FIELD((void *)arg2, void **, 0x20);
            M2C_FIELD(M2C_FIELD((void *)arg2, void **, 0x20), void **, 0x24) = (void *)M2C_FIELD((void *)arg2, void **, 0x24);
            temp_r8 = *(void **)arg1;
            M2C_FIELD((void *)arg2, void **, 0x20) = temp_r8;
            M2C_FIELD((void *)arg2, void **, 0x24) = (void *)M2C_FIELD(*(void **)arg1, void **, 0x24);
            M2C_FIELD(temp_r8, void **, 0x24) = (void *)arg2;
            M2C_FIELD(M2C_FIELD((void *)arg2, void **, 0x24), void **, 0x20) = (void *)arg2;
            *(void **)arg1 = (void *)arg2;
        }
    }
    flags=(volatile u16 *)arg2;
    temp_r0 = *flags;
    temp_r4 = M2C_FIELD((void *)arg2, s32 *, 0xC);
    *flags = (u16)(temp_r0 | 2);
    if (temp_r4 == 0) {
        temp_r0 = M2C_FIELD((void *)arg2, s32 *, 8);
        M2C_FIELD((void *)arg2, s32 *, 0xC) = temp_r0;
        M2C_FIELD((void *)arg2, s32 *, 0x10) = temp_r0;
    } else {
        temp_r7_2 = M2C_FIELD((void *)arg2, s32 *, 8);
        if ((u32)temp_r7_2 < (u32)temp_r4) M2C_FIELD((void *)arg2, s32 *, 0xC) = temp_r7_2;
        else if ((u32)temp_r7_2 > (u32)M2C_FIELD((void *)arg2, s32 *, 0x10)) M2C_FIELD((void *)arg2, s32 *, 0x10) = temp_r7_2;
    }
    if (arg3 != 0) M2C_FIELD((void *)arg2, s32 *, 0x1C) = (s32)M2C_FIELD(arg0, s32 *, 0x1644);
    else M2C_FIELD((void *)arg2, s32 *, 0x1C) = 0;
    temp_r4_2 = M2C_FIELD(arg0, s32 *, 0x1624);
    if ((temp_r4_2 & 1) || ((temp_r4_2 & 4) && (*flags & 4))) {
        temp_r3 = ((s32 (*)(void *, void *))fn_800A7B34)(arg0, (void *)arg2);
        if (temp_r3 != 0) return temp_r3;
    }
    return 0;
}

extern "C" s32 fn_800A58E0(void *, s32, s32, s32, s32);
extern "C" s32 fn_800A8730(void *arg0, u32 *arg1, void *arg2, u32 arg3, s32 arg4, s32 *arg5) {
    register void *var_r30;
    register s32 var_r29;
    register u32 request_length;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r4_2;
    u32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r5_5;
    s32 temp_r5_6;
    s32 temp_r6;
    u32 temp_r0;
    u32 temp_r0_3;
    u32 temp_r31;
    u32 temp_r3_5_u;
    u32 temp_r3_6_u;
    u32 temp_r4_u;
    register s32 temp_r7;
    register u8 temp_r5;
    register u8 temp_r5_2;
    register u8 temp_r5_3;
    register u8 temp_r5_4;
    register u8 temp_r6_2;

    var_r30 = 0;
    var_r29 = arg4;
    request_length = arg4;
    *(volatile s32 *)arg5 = 0;
    temp_r31 = arg3 + request_length;
loop_1:
    if (var_r30 == 0) {
        var_r30 = (void *)*arg1;
        goto loop_9;
    }
    var_r30 = *(void **)((u8 *)var_r30 + 0x20);
    if (var_r30 == (void *)*arg1) {
        var_r30 = 0;
        goto loop_2;
    }
loop_9:
    temp_r7 = *(u32 *)((u8 *)var_r30 + 0x18);
    if (temp_r7 == 0xFFFEFFFF) {
        var_r30 = 0;
        goto loop_2;
    }
    *(u32 *)((u8 *)var_r30 + 8) = *(u32 *)((u8 *)var_r30 + 4);
    var_r30 = *(void **)((u8 *)var_r30 + 0x20);
    if ((*(u16 *)var_r30 & 1) == 0)
        var_r30 = 0;
    else
        goto loop_1;
loop_2:
    if (var_r30 != 0) {
        temp_r7 = *(u32 *)((u8 *)var_r30 + 0x18);
        if ((u32)(temp_r7 + 0x10000) != 0xFFFFFFFF) {
            if ((temp_r7 <= arg3) && ((u32)(temp_r7 + *(u32 *)((u8 *)var_r30 + 0x14)) >= temp_r31)) {
                temp_r5 = *(u8 *)((u8 *)arg0 + 0x20);
                VFipf_memcpy((u8 *)*(void **)((u8 *)var_r30 + 4) + ((arg3 - temp_r7) << temp_r5),
                             arg2, request_length << temp_r5);
                temp_r3_2 = *arg5 + var_r29;
                var_r29 = 0;
                *arg5 = temp_r3_2;
                *(u16 *)var_r30 |= 2;
                temp_r5_2 = *(u8 *)((u8 *)arg0 + 0x20);
                temp_r6 = *(s32 *)((u8 *)var_r30 + 0xC);
                temp_r3_3 = (s32)((u8 *)*(void **)((u8 *)var_r30 + 4) +
                            ((arg3 - *(u32 *)((u8 *)var_r30 + 0x18)) << temp_r5_2));
                temp_r4_u = (u32)temp_r3_3 + ((request_length - 1) << temp_r5_2);
                if (temp_r6 == 0) {
                    *(s32 *)((u8 *)var_r30 + 0xC) = temp_r3_3;
                    *(u32 *)((u8 *)var_r30 + 0x10) = temp_r4_u;
                } else if ((u32)temp_r3_3 < (u32)temp_r6) {
                    *(s32 *)((u8 *)var_r30 + 0xC) = temp_r3_3;
                } else if (*(u32 *)((u8 *)var_r30 + 0x10) < temp_r4_u) {
                    *(u32 *)((u8 *)var_r30 + 0x10) = temp_r4_u;
                }
            } else if ((temp_r7 >= arg3) &&
                       (temp_r4_2 = *(s32 *)((u8 *)var_r30 + 0x14),
                        ((u32)(temp_r7 + temp_r4_2) <= temp_r31))) {
                temp_r5_3 = *(u8 *)((u8 *)arg0 + 0x20);
                VFipf_memcpy(*(void **)((u8 *)var_r30 + 4),
                             (u8 *)arg2 + ((temp_r7 - arg3) << temp_r5_3),
                             temp_r4_2 << temp_r5_3);
                temp_r3_4 = *(s32 *)((u8 *)var_r30 + 0x14);
                var_r29 -= temp_r3_4;
                *arg5 += temp_r3_4;
                *(u16 *)var_r30 |= 2;
                *(s32 *)((u8 *)var_r30 + 0xC) = *(s32 *)((u8 *)var_r30 + 4);
                *(u32 *)((u8 *)var_r30 + 0x10) =
                    *(u32 *)((u8 *)var_r30 + 4) +
                    ((*(u32 *)((u8 *)var_r30 + 0x14) - 1) << *(u8 *)((u8 *)arg0 + 0x20));
            } else if ((temp_r7 > arg3) && (temp_r7 < temp_r31) &&
                       ((u32)(temp_r7 + *(u32 *)((u8 *)var_r30 + 0x14)) >= temp_r31)) {
                temp_r5_4 = *(u8 *)((u8 *)arg0 + 0x20);
                VFipf_memcpy(*(void **)((u8 *)var_r30 + 4),
                             (u8 *)arg2 + ((temp_r7 - arg3) << temp_r5_4),
                             (temp_r31 - temp_r7) << temp_r5_4);
                temp_r4_3 = request_length + arg3;
                temp_r4_4 = temp_r4_3 - *(u32 *)((u8 *)var_r30 + 0x18);
                *arg5 += temp_r4_4;
                var_r29 -= temp_r4_4;
                *(u16 *)var_r30 |= 2;
                temp_r5_5 = *(s32 *)((u8 *)var_r30 + 4);
                *(s32 *)((u8 *)var_r30 + 0xC) = temp_r5_5;
                temp_r3_5_u = temp_r5_5 +
                    (((temp_r4_3 - 1) - *(u32 *)((u8 *)var_r30 + 0x18)) <<
                     *(u8 *)((u8 *)arg0 + 0x20));
                temp_r0 = *(u32 *)((u8 *)var_r30 + 0x10);
                if ((s32)temp_r0 == 0 || temp_r0 < temp_r3_5_u)
                    *(u32 *)((u8 *)var_r30 + 0x10) = temp_r3_5_u;
            } else if (temp_r7 < arg3) {
                temp_r0_2 = *(s32 *)((u8 *)var_r30 + 0x14);
                temp_r3_6_u = temp_r7 + temp_r0_2;
                if (temp_r3_6_u > arg3 && temp_r3_6_u <= temp_r31) {
                    temp_r6_2 = *(u8 *)((u8 *)arg0 + 0x20);
                    temp_r3_7 = arg3 - temp_r7;
                    VFipf_memcpy((u8 *)*(void **)((u8 *)var_r30 + 4) +
                                     (temp_r3_7 << temp_r6_2),
                                 arg2, (temp_r0_2 - temp_r3_7) << temp_r6_2);
                    temp_r3_8 = *(u32 *)((u8 *)var_r30 + 0x14) -
                                (arg3 - *(u32 *)((u8 *)var_r30 + 0x18));
                    *arg5 += temp_r3_8;
                    var_r29 -= temp_r3_8;
                    *(u16 *)var_r30 |= 2;
                    temp_r5_6 = *(s32 *)((u8 *)var_r30 + 0xC);
                    temp_r0_3 = (u32)*(s32 *)((u8 *)var_r30 + 4) +
                        (((*(u32 *)((u8 *)var_r30 + 0x14) -
                           (arg3 - *(u32 *)((u8 *)var_r30 + 0x18))) - 1) <<
                         *(u8 *)((u8 *)arg0 + 0x20));
                    if (temp_r5_6 == 0 || temp_r0_3 < (u32)temp_r5_6)
                        *(s32 *)((u8 *)var_r30 + 0xC) = (s32)temp_r0_3;
                    *(u32 *)((u8 *)var_r30 + 0x10) =
                        *(u32 *)((u8 *)var_r30 + 4) +
                        ((*(u32 *)((u8 *)var_r30 + 0x14) - 1) <<
                         *(u8 *)((u8 *)arg0 + 0x20));
                }
            }
        }
    }

    if (var_r30 != 0 && var_r29 != 0)
        goto loop_1;
    if (var_r29 != 0) {
        temp_r3 = fn_800A58E0(arg0, (s32)arg2, arg3, request_length, (s32)arg5);
        if (temp_r3 != 0)
            return temp_r3;
    }
    return 0;
}

#pragma dont_inline reset
extern "C" void fn_800A8B94(void *arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4) {
    *(s32 *)((u8 *)arg0 + 0x162C) = arg1;
    *(s32 *)((u8 *)arg0 + 0x1638) = arg2;
    *(s16 *)((u8 *)arg0 + 0x1628) = arg3;
    *(s16 *)((u8 *)arg0 + 0x162A) = arg4;
}

extern "C" void fn_800A8BA8(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(s32 *)((u8 *)arg0 + 0x163C) = arg1;
    }
}

extern "C" void fn_800A8BB8(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(s32 *)((u8 *)arg0 + 0x1640) = arg1;
    }
}

extern "C" s32 fn_800A7774(void *, void *, void *, void *, u16, void *, s32);
extern "C" s32 VFiPFCACHE_InitCaches(void *arg0) {
    u32 flags = *(u32 *)((u8 *)arg0 + 0x1624);
    u16 count = *(u16 *)((u8 *)arg0 + 0x1628);
    flags = (flags & ~1U) | 2U;
    u16 extra = *(u16 *)((u8 *)arg0 + 0x162A);
    flags &= ~4U;
    s32 total = (s32)count + (s32)extra;
    *(u32 *)((u8 *)arg0 + 0x1624) = flags;
    fn_800A499C((const char *)*(void **)((u8 *)arg0 + 0x1638), 0, total << 9);
    s32 result = fn_800A7774(arg0, (u8 *)arg0 + 0x1630,
                             *(void **)((u8 *)arg0 + 0x162C),
                             *(void **)((u8 *)arg0 + 0x1638),
                             *(u16 *)((u8 *)arg0 + 0x1628),
                             *(void **)((u8 *)arg0 + 0x163C), 1);
    if (result != 0) {
        return result;
    }
    u16 secondCount = *(u16 *)((u8 *)arg0 + 0x1628);
    void *base = *(void **)((u8 *)arg0 + 0x162C);
    s32 status = fn_800A7774(arg0, (u8 *)arg0 + 0x1634,
                             (u8 *)base + secondCount * 0x28,
                             (u8 *)*(void **)((u8 *)arg0 + 0x1638) + (secondCount << 9),
                             *(u16 *)((u8 *)arg0 + 0x162A),
                             *(void **)((u8 *)arg0 + 0x1640), 0);
    return status & ((-status | status) >> 31);
}

extern "C" s32 fn_800A7C20(void *, s32, void *, s32);
extern "C" s32 fn_800A8D08(s32 arg0, void **arg1, s32 *arg2, s32 arg3, s32 *arg4) {
    s32 result;

    if (*(s32 *)((u8 *)arg0 + 0x1634) == 0) {
        *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x162C) + 4) =
            *(s32 *)((u8 *)arg0 + 0x1638);
        *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x162C) + 8) =
            *(s32 *)((u8 *)arg0 + 0x1638);
        *arg2 = (s32)*(void **)((u8 *)arg0 + 0x162C);
        return 0;
    }
    result = fn_800A7C20((void *)arg0, (s32)((u8 *)arg0 + 0x1634), (void *)arg1, (s32)arg2);
    return result & ((s32)(-result | result) >> 31);
}

extern "C" void VFiPFCACHE_FreeFATPage(void *arg0, void *arg1) {
    u8 *page = (u8 *)arg1;
    void *head = *(void **)((u8 *)arg0 + 0x1630);
    void *nextHead;
    void *tail;
    if (head == 0)
        return;
    *(u32 *)(page + 0xC) = 0;
    *(u16 *)page &= 0xFFFC;
    *(u32 *)(page + 0x10) = 0;
    *(u32 *)(page + 0x18) = -1;
    *(u32 *)(page + 0x1C) = 0;
    head = *(void **)((u8 *)arg0 + 0x1630);
    if (arg1 == head) {
        *(void **)((u8 *)arg0 + 0x1630) = *(void **)(page + 0x20);
        return;
    }
    if (arg1 == *(void **)((u8 *)head + 0x24))
        return;
    *(void **)(*(u8 **)(page + 0x24) + 0x20) = *(void **)(page + 0x20);
    *(void **)(*(u8 **)(page + 0x20) + 0x24) = *(void **)(page + 0x24);
    nextHead = *(void **)((u8 *)arg0 + 0x1630);
    *(void **)(page + 0x20) = nextHead;
    tail = *(void **)((u8 *)arg0 + 0x1630);
    *(void **)(page + 0x24) = *(void **)((u8 *)tail + 0x24);
    *(void **)((u8 *)nextHead + 0x24) = arg1;
    *(void **)(*(u8 **)(page + 0x24) + 0x20) = arg1;
}

extern "C" s32 VFiPFCACHE_FreeFATPage_800A8E10(void *arg0, void *arg1) {
    u8 *page = (u8 *)arg1;
    volatile void **headSlot = (volatile void **)((u8 *)arg0 + 0x1634);
    void *head = (void *)*headSlot;
    void *nextHead;
    void *tail;
    if (head == 0)
        return;
    *(u32 *)(page + 0xC) = 0;
    *(u16 *)page &= 0xFFFC;
    *(u32 *)(page + 0x10) = 0;
    *(u32 *)(page + 0x18) = -1;
    *(u32 *)(page + 0x1C) = 0;
    head = (void *)*headSlot;
    if (arg1 == head) {
        *headSlot = *(void **)(page + 0x20);
        return;
    }
    if (arg1 == *(void **)((u8 *)head + 0x24))
        return;
    *(void **)(*(u8 **)(page + 0x24) + 0x20) = *(void **)(page + 0x20);
    *(void **)(*(u8 **)(page + 0x20) + 0x24) = *(void **)(page + 0x24);
    nextHead = (void *)*headSlot;
    *(void **)(page + 0x20) = nextHead;
    tail = (void *)*headSlot;
    *(void **)(page + 0x24) = *(void **)((u8 *)tail + 0x24);
    *(void **)((u8 *)nextHead + 0x24) = arg1;
    *(void **)(*(u8 **)(page + 0x24) + 0x20) = arg1;
}

#pragma dont_inline on
extern "C" s32 fn_800A8EA0(void *arg0, u32 arg1, void **arg2) {
    s32 result = VFiPFCACHE_DoReadPage(arg0, (s32)((u8 *)arg0 + 0x1630), (s32)arg1, (s32)arg2, 0);
    return result & ((s32)(-result | result) >> 31);
}
#pragma dont_inline reset

extern "C" s32 VFiPFCACHE_DoReadPage(void *, s32, s32, s32, s32);
extern "C" s32 VFiPFCACHE_DoReadNumSector(void *, s32, u32, s32, s32);
extern "C" s32 fn_800A8EE0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3 = VFiPFCACHE_DoReadPage(arg0, (s32)((u8 *)arg0 + 0x1634), arg1, arg2, arg3);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" s32 fn_800A8050(void *, s32, s32, s32, s32);
extern "C" s32 fn_800A8F28(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3 = fn_800A8050(arg0, (s32)((u8 *)arg0 + 0x1634), arg1, arg2, arg3);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" s32 VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded(void *arg0, void *arg1, u32 arg2, s32 arg3, s32 arg4) {
    s32 result;
    if (arg2 >= *(u32 *)((u8 *)arg0 + 8))
        return 0x10;
    result = ((s32 (*)(void *, s32, s32, u32, s32, s32))VFiPFCACHE_DoReadNumSector)(arg0, (s32)((u8 *)arg0 + 0x1634), (s32)arg1, arg2, arg3, arg4);
    return result & ((-result | result) >> 31);
}

extern "C" s32 fn_800A8504(void *, void *, s32, s32);
extern "C" s32 fn_800A8FD0(void *arg0, s32 arg1) {
    s32 temp_r3 = fn_800A8504(arg0, (u8 *)arg0 + 0x1630, arg1, 0);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" s32 fn_800A900C(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r3 = fn_800A8504(arg0, (u8 *)arg0 + 0x1634, arg1, arg2);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" s32 fn_800A861C(void *, void *, s32, u32);
extern "C" s32 VFiPFCACHE_SearchForPage(s32, s32, s32);
extern "C" s32 fn_800A8AD4(s32);
extern "C" s32 VFiPFCACHE_WriteFATSectorAndFreeIfNeeded(void *arg0, s32 arg1, u32 arg2) {
    s32 temp_r3;
    if (arg2 >= *(u32 *)((u8 *)arg0 + 8))
        return 0x10;
    temp_r3 = fn_800A861C(arg0, (u8 *)arg0 + 0x1630, arg1, arg2);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" s32 fn_800A8730(void *, u32 *, void *, u32, s32, s32 *);
extern "C" s32 VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded_800A9098(void *arg0, void *arg1, u32 arg2, s32 arg3, s32 arg4) {
    s32 result;
    if (arg2 >= *(u32 *)((u8 *)arg0 + 8))
        return 0x10;
    result = ((s32 (*)(void *, s32, s32, u32, s32, s32))fn_800A8730)(arg0, (s32)((u8 *)arg0 + 0x1634), (s32)arg1, arg2, arg3, arg4);
    return result & ((-result | result) >> 31);
}

extern "C" void fn_800A90F8(void *arg0, s32 arg1) {
    VFiPFCACHE_SearchForPage((s32)arg0, *(s32 *)((u8 *)arg0 + 0x1634), arg1);
}

extern "C" s32 fn_800A9104(void *arg0) {
    s32 temp_r3 = ((s32 (*)(void *, s32))fn_800A8AD4)(arg0, *(s32 *)((u8 *)arg0 + 0x1630));
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" s32 fn_800A9138(void *arg0, u32 arg1) {
    s32 result = 0;
    void *head;
    void *node;
    if (*(u32 *)((u8 *)arg0 + 0x1624) & 7) {
        head = *(void **)((u8 *)arg0 + 0x1634);
        if (*(u32 *)((u8 *)head + 0x1C) != 0 && *(u32 *)((u8 *)head + 0x1C) == arg1) {
            result = ((s32 (*)(void *, void *))fn_800A7B34)(arg0, head);
            if (result != 0) return result;
        }
        node = *(void **)((u8 *)head + 0x20);
        while (node != head) {
            if (*(u32 *)((u8 *)node + 0x1C) != 0 && *(u32 *)((u8 *)node + 0x1C) == arg1) {
                result = ((s32 (*)(void *, void *))fn_800A7B34)(arg0, node);
                if (result != 0) return result;
            }
            node = *(void **)((u8 *)node + 0x20);
        }
    }
    return result;
}

struct CachePage {
    s32 next;
    s32 prev;
    u32 pad[5];
};
extern "C" s32 fn_800A7C20(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern "C" s32 VFiPFCACHE_FlushAllCaches(void *arg0) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(void *, s32))fn_800A8AD4)(arg0, *(s32 *)((u8 *)arg0 + 0x1630));
    if (temp_r3 != 0) {
        return temp_r3;
    }
    temp_r3 = ((s32 (*)(void *, s32))fn_800A8AD4)(arg0, *(s32 *)((u8 *)arg0 + 0x1634));
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

void VFiPFCACHE_FreeAllCaches(void *arg0) {
    void *node;
    void *head;
    void *next;
    void *prev;
    u16 flags;

loopA:
    node = *(void **)((u8 *)arg0 + 0x1630);
    if (node == 0) goto loopB;
    flags = *(u16 *)node;
    if ((flags & 1) == 0) goto loopB;
    *(u16 *)node = flags & 0xFFFC;
    *(s32 *)((u8 *)node + 0xC) = 0;
    *(s32 *)((u8 *)node + 0x10) = 0;
    *(s32 *)((u8 *)node + 0x18) = -1;
    *(s32 *)((u8 *)node + 0x1C) = 0;
    head = *(void **)((u8 *)arg0 + 0x1630);
    if (node == head) {
        *(void **)((u8 *)arg0 + 0x1630) = *(void **)((u8 *)node + 0x20);
        goto loopA;
    }
    if (node == *(void **)((u8 *)head + 0x24)) goto loopA;
    next = *(void **)((u8 *)node + 0x20);
    prev = *(void **)((u8 *)node + 0x24);
    *(void **)((u8 *)prev + 0x20) = next;
    *(void **)((u8 *)next + 0x24) = prev;
    head = *(void **)((u8 *)arg0 + 0x1630);
    *(void **)((u8 *)node + 0x20) = head;
    *(void **)((u8 *)node + 0x24) = *(void **)((u8 *)head + 0x24);
    *(void **)((u8 *)head + 0x24) = node;
    *(void **)((u8 *)*(void **)((u8 *)node + 0x24) + 0x20) = node;
    goto loopA;

loopB:
    for (;;) {
        node = *(void **)((u8 *)arg0 + 0x1634);
        if (node == 0) return;
        flags = *(u16 *)node;
        if ((flags & 1) == 0) return;
        *(u16 *)node = flags & 0xFFFC;
        *(s32 *)((u8 *)node + 0xC) = 0;
        *(s32 *)((u8 *)node + 0x10) = 0;
        *(s32 *)((u8 *)node + 0x18) = -1;
        *(s32 *)((u8 *)node + 0x1C) = 0;
        head = *(void **)((u8 *)arg0 + 0x1634);
        if (node == head) {
            *(void **)((u8 *)arg0 + 0x1634) = *(void **)((u8 *)node + 0x20);
            continue;
        }
        if (node == *(void **)((u8 *)head + 0x24)) continue;
        next = *(void **)((u8 *)node + 0x20);
        prev = *(void **)((u8 *)node + 0x24);
        *(void **)((u8 *)prev + 0x20) = next;
        *(void **)((u8 *)next + 0x24) = prev;
        head = *(void **)((u8 *)arg0 + 0x1634);
        *(void **)((u8 *)node + 0x20) = head;
        *(void **)((u8 *)node + 0x24) = *(void **)((u8 *)head + 0x24);
        *(void **)((u8 *)head + 0x24) = node;
        *(void **)((u8 *)*(void **)((u8 *)node + 0x24) + 0x20) = node;
    }
}

extern "C" void VFiPFCLUSTER_UpdateLastAccessCluster(void *arg0, s32 arg1) {
    s32 temp_r6 = M2C_FIELD(arg0, s32 *, 0x1C);
    s32 temp_r6_2;
    void *var_r7;
    if (temp_r6 == 0) {
        void *p = M2C_FIELD(arg0, void **, 8);
        M2C_FIELD(p, s32 *, 0x1C) = 0;
        M2C_FIELD(p, u32 *, 0x18) = 0;
        return;
    }
    var_r7 = arg0 == 0 ? 0 : M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x268);
    if (!(temp_r6 & (M2C_FIELD(var_r7, u16 *, 0) - 1)) &&
        !((temp_r6_2 = M2C_FIELD(arg0, s32 *, 0x24)) & (M2C_FIELD(var_r7, u8 *, 6) - 1))) {
        if (temp_r6_2 == 0) return;
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), u32 *, 0x18) = (u32)(temp_r6_2 - 1) >> M2C_FIELD(var_r7, u8 *, 0x21);
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x1C) = (s32)(((u32)((arg1 - 1) - M2C_FIELD(var_r7, s32 *, 0x30)) >> M2C_FIELD(var_r7, u8 *, 0x21)) + 2);
    } else {
        temp_r6_2 = M2C_FIELD(arg0, s32 *, 0x24);
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), u32 *, 0x18) = (u32)temp_r6_2 >> M2C_FIELD(var_r7, u8 *, 0x21);
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x1C) = (s32)(((u32)(arg1 - M2C_FIELD(var_r7, s32 *, 0x30)) >> M2C_FIELD(var_r7, u8 *, 0x21)) + 2);
    }
}

#pragma push
#pragma opt_common_subs off
extern "C" s32 fn_800A95B4(void *arg0) {
    struct Local {
        u32 value8;
        s32 valueC;
        u8 path[0x10];
        u8 temp[0x10];
        u8 input[0x38];
        u8 parsed[0x240];
    } local;

    u8 *object = (u8 *)arg0;
    u8 *volume;
    s32 result;
    s32 index;
    s32 offset;

    local.valueC = 0;
    local.value8 = 0;
    index = 0;
    if ((M2C_FIELD(arg0, u32 *, 0x14) & 1) == 1) {
        result = fn_800A4E80(local.path, (s32)(object + 0x1C), 1);
    } else {
        result = fn_800A4E80(local.path, (s32)(object + 0x444), 2);
    }
    if (result != 0) {
        return result;
    }
    fn_800A4D4C(local.path, object + 0x1C);
    goto process;

retry:
    if (M2C_FIELD(arg0, u32 *, 0x10) >= local.value8) {
        return 10;
    }

process:
    *(s32 *)(local.parsed + 0x234) = M2C_FIELD(arg0, s32 *, 0xC);
    fn_800AF530(local.input, local.temp,
                (s32)M2C_FIELD(arg0, void **, 8),
                (s32)(local.parsed + 0x234));
    result = ((s32 (*)(void *, void *, s32, s32, s32, s32, s32 *, s32 *))fn_800AA924)(
        local.input, local.parsed, (s32)M2C_FIELD(arg0, u32 *, 0x10),
        (s32)local.path, (s32)M2C_FIELD(arg0, u8 *, 0x1B), 0,
        &local.valueC, (s32 *)&local.value8);
    if (result != 0) {
        return result;
    }
    M2C_FIELD(arg0, u32 *, 0x10) = local.value8 + 1;
    if ((local.value8 - 0xF0000) == 0x423F) {
        return 3;
    }
    if (local.value8 < 0xF423F) {
        goto retry;
    }

    fn_800A4AAC((char *)(object + 0x22D), (char *)(local.parsed + 0x20E));
    if ((M2C_FIELD(arg0, u32 *, 0x14) & 2) == 2) {
        ((s32 (*)(s16 *, s32))VFiPFPATH_transformInUnicode)(
            (s16 *)(object + 0x64C), (s32)(object + 0x22D));
    }

    if (*(u16 *)local.parsed != 0) {
        if ((((u32)lbl_803D2140[0x60 / 4] & 2U) == 2U)) {
            lbl_803D2140[0x60 / 4] = (lbl_803D2140[0x60 / 4] & ~3) | 1;
            VFiPFPATH_transformFromUnicodeToNormal(
                (u16 *)(object + 0x23A), (u16 *)local.parsed);
            lbl_803D2140[0x60 / 4] = (lbl_803D2140[0x60 / 4] & ~3) | 2;
        } else {
            VFiPFPATH_transformFromUnicodeToNormal(
                (u16 *)(object + 0x23A), (u16 *)local.parsed);
        }
        if ((M2C_FIELD(arg0, u32 *, 0x14) & 2) == 2) {
            fn_800A4B78((u16 *)(object + 0x666), (u16 *)local.parsed);
        }
    } else {
        object[0x23A] = 0;
        if ((M2C_FIELD(arg0, u32 *, 0x14) & 2) == 2) {
            *(u16 *)(object + 0x666) = 0;
        }
    }

    volume = (u8 *)M2C_FIELD(arg0, void **, 8);
    if (*(s32 *)(volume + 0x161C) != 0) {
        u32 key0;
        u32 key1;
        u16 key2;
        key0 = *(u32 *)(local.parsed + 0x22C);
        key1 = *(u32 *)(local.parsed + 0x238);
        index = 0;
        key2 = *(u16 *)(local.parsed + 0x23C);
        offset = 0;
        while (index < 5) {
            u8 *entry = volume + offset;
            u32 flags = *(u32 *)(entry + 0x40);
            if ((flags & 1) != 0 && (flags & 2) != 0 &&
                key0 == *(u32 *)(entry + 0x2A8) &&
                key1 == *(u32 *)(entry + 0x2B4) &&
                key2 == *(u16 *)(entry + 0x2B8)) {
                *(u32 *)(object + 0x228) = *(u32 *)(volume + index * 0x29C + 0x2A4);
                *(u16 *)(object + 0x224) = *(u16 *)((u8 *)M2C_FIELD(arg0, void **, 8) + index * 0x29C + 0x2A0);
                *(u16 *)(object + 0x226) = *(u16 *)((u8 *)M2C_FIELD(arg0, void **, 8) + index * 0x29C + 0x2A2);
                object[0x22C] = ((u8 *)M2C_FIELD(arg0, void **, 8))[index * 0x29C + 0x298];
                object[0x18] = ((u8 *)M2C_FIELD(arg0, void **, 8))[index * 0x29C + 0x286];
                object[0x19] = ((u8 *)M2C_FIELD(arg0, void **, 8))[index * 0x29C + 0x287];
                object[0x1A] = ((u8 *)M2C_FIELD(arg0, void **, 8))[index * 0x29C + 0x288];
                break;
            }
            offset += 0x29C;
            index++;
        }
    }

    if (*(s32 *)((u8 *)M2C_FIELD(arg0, void **, 8) + 0x161C) == 0 || index == 5) {
        *(u32 *)(object + 0x228) = *(u32 *)(local.parsed + 0x228);
        *(u16 *)(object + 0x224) = *(u16 *)(local.parsed + 0x224);
        *(u16 *)(object + 0x226) = *(u16 *)(local.parsed + 0x226);
        object[0x22C] = local.parsed[0x21C];
        object[0x18] = local.parsed[0x20A];
        object[0x19] = local.parsed[0x20B];
        object[0x1A] = local.parsed[0x20C];
    }
    return 0;
}

extern "C" void fn_800B36CC(s32, s32, s32, s32);
extern "C" void fn_800ACA50(s32, s32, s32, s32);
extern "C" void fn_800B4BD8(char *, u16 *, void *);
extern "C" s32 fn_800A98B8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    u32 frame[0xB4];

    s32 result = ((s32 (*)(s32, void *, void *))fn_800B36CC)(
        arg1, (u8 *)frame + 0x10, frame);
    if (result != 0)
        return result;

    result = ((s32 (*)(void *, void *, s32, void *))fn_800ACA50)(
        (u8 *)frame + 0x20, (u8 *)frame + 0x90, (s32)arg0,
        (u8 *)frame + 0x10);
    if (result != 0)
        return result;

    if ((((u8 *)frame)[0x2AC] & 0x10) == 0)
        return 0x14;

    register s32 zero = 0;
    *(s32 *)((u8 *)arg3 + 0xC) = *(s32 *)((u8 *)frame + 0x2C4);
    *(s32 *)((u8 *)arg3 + 0x10) = zero;
    *(s32 *)((u8 *)arg3 + 8) = *(s32 *)((u8 *)frame + 0x2BC);
    *((s8 *)arg3 + 0x1B) = (s8)arg2;
    *(s32 *)((u8 *)arg3 + 0x14) = zero;

    if ((u32)fn_800A4D44(frame) == 1U) {
        ((void (*)(void *, void *, void *))fn_800B4BD8)(
            (u8 *)arg3 + 0x1C, (void *)zero, frame);
        *(s32 *)((u8 *)arg3 + 0x14) |= 1;
    } else {
        ((void (*)(void *, void *, void *))fn_800B4BD8)(
            (u8 *)arg3 + 0x1C, (u16 *)((u8 *)arg3 + 0x444), frame);
        *(s32 *)((u8 *)arg3 + 0x14) |= 2;
    }

    return fn_800A95B4(arg3);
}

#pragma pop
extern "C" void VFiPFDIR_FinalizeAllDirs(u8 *arg0) {
    u16 i;
    for (i = 0; i < 3; i++) {
        u8 *dir = arg0 + i * 0x280;
        *(s32 *)(dir + 0xE3C) = 0;
        fn_800AF574(dir + 0xE44);
    }
    *(u32 *)(arg0 + 0x15BC) &= ~1U;
    *(u32 *)(arg0 + 0x15DC) &= ~1U;
    *(u32 *)(arg0 + 0x15FC) &= ~1U;
    *(s32 *)(arg0 + 0x1620) = 0;
}

#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_800A9A4C(void *arg0, s32 arg1, s32 arg2) {
    void *vol;
    s32 result;

    vol = ((void *(*)(void))fn_800B36D4)();
    fn_800B77C0((u8 *)vol + 0x1F90);
    result = fn_800B5E14(vol);
    if (result != 0) {
        fn_800B783C((void *)((volatile u8 *)vol + 0x1F90));
        lbl_803D2140[16] = result;
        *(s32 *)((u8 *)vol + 0x1F80) = result;
        return result;
    }
    result = fn_800A98B8(vol, (s32)arg0, arg1, (void *)arg2);
    if (result != 0) {
        *(s32 *)((u8 *)arg2 + 8) = 0;
        lbl_803D2140[16] = result;
        *(s32 *)((u8 *)vol + 0x1F80) = result;
    }
    fn_800B783C((void *)((volatile u8 *)vol + 0x1F90));
    return result;
}
#pragma dont_inline reset
#pragma use_lmw_stmw on

#pragma dont_inline on
#pragma push
#pragma opt_common_subs off
extern "C" void *fn_800A9B0C(void *arg0) {
    void *vol;
    s32 temp_r3;

    vol = *(void **)((u8 *)arg0 + 8);
    fn_800B77C0((u8 *)vol + 0x1F90);
    temp_r3 = fn_800B5E14(vol);
    if (temp_r3 != 0) {
        fn_800B783C((u8 *)vol + 0x1F90);
        lbl_803D2140[16] = temp_r3;
        *(s32 *)((u8 *)vol + 0x1F80) = temp_r3;
        return (void *)temp_r3;
    }
    temp_r3 = fn_800A95B4(arg0);
    if (temp_r3 != 0) {
        lbl_803D2140[16] = temp_r3;
        *(s32 *)((u8 *)vol + 0x1F80) = temp_r3;
    }
    fn_800B783C((u8 *)vol + 0x1F90);
    return (void *)temp_r3;
}
#pragma pop
#pragma dont_inline reset
extern "C" s32 fn_800A9BB4(void *arg0, void *arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 *arg6, s32 arg_sp0) {
 extern s32 VFiPFPATH_cmpName(void*,s32,s32); extern s32 fn_800B317C(void*,s32); extern s32 fn_800B3A70(void*,void*,s32); extern void fn_800B3BEC(void*,u8); extern s32 lbl_803D2140[];
 s32 sp8; s32 mask=arg3; s32 ret=1, valid=1, i; u8 sum=0;
 if((mask&15)==15)return 1;
 if(mask==0)mask=0x40;
 if(arg4&0x80){s32 a=arg4&0x7f,b=arg5&0x7f;if((a&&(a!=(a&mask)))||(b&&(b==(b&mask))))valid=0;}
 else if(arg4!=0x7f&&(u32)mask!=arg4&&(!(mask&arg4)||(mask&arg5)))valid=0;
 if(!valid)return ret;
 if(mask&8){*(u8*)((u8*)arg0+0x20a)=0;*(u16*)arg0=0;}
 fn_800B3BEC((u8*)arg0+0x20e,*(u8*)((u8*)arg1+0xb));
 if(*(u8*)((u8*)arg0+0x20e)==5)*(u8*)((u8*)arg0+0x20e)=0xe5;
 if(*(u8*)((u8*)arg0+0x20a)&&*(u8*)((u8*)arg0+0x20b)==1){
  fn_800B3A70(&sp8,(u8*)arg0+0x20e,0);
  for(i=0;i<11;i++){u8 x=((u8*)&sp8)[i];sum=(sum<<7|sum>>1)+x;}
  if(*(u8*)((u8*)arg0+0x20c)!=sum)return ret;
  ret=fn_800B317C(arg0,arg2)!=0;
 }
 if(ret){if(((lbl_803D2140[0x60/4]&2)==2)&&!(mask&8)){if(!VFiPFPATH_cmpName((u8*)arg0+0x20e,arg2,0))ret=0;}
 else if(!VFiPFPATH_cmpName((u8*)arg0+0x20e,arg2,1))ret=0;}
 if(ret)(*arg6)++;
 return ret;
}

extern "C" s32 fn_800AF530(void *, void *, s32, s32);
extern "C" s32 VFiPFENT_searchEmptyTailSFN(void *, u32, void *, s32 *);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 VFiPFENT_findEmptyTailSFN(void *arg0, void *name, u32 *out) {
    u8 sp18[0x38];
    u8 sp8[0x10];
    u8 *volume = *(u8 **)((u8 *)arg0 + 0x22C);
    u32 *count = out;
    u32 candidate;
    u32 base;
    u32 limit;
    u32 blockIndex;
    u32 byteOffset;
    volatile u32 *entries;
    u32 value;
    u32 blocks;
    s32 result;

    *count = 1;
    fn_800AF530(sp18, sp8, *(s32 *)((u8 *)arg0 + 0x22C),
                (s32)((u8 *)arg0 + 0x234));
    base = 0xF0000;
    candidate = 1;
    limit = base + 0x423F;
    goto candidateCheck;
search:
    result = VFiPFENT_searchEmptyTailSFN(sp18, candidate, name,
                                          *(s32 **)(volume + 0x1F7C));
    if (result != 0)
        return result;
    blockIndex = 0;
    byteOffset = 0;
    goto scan;
scan:
    entries = *(volatile u32 **)(volume + 0x1F7C);
    value = entries[blockIndex];
    if (value != 0xFFFEFFFF)
        goto shift;
    goto advanceWord;
shift:
    entries = *(volatile u32 **)(volume + 0x1F7C);
    value = entries[blockIndex] >> 1;
    entries[blockIndex] = value;
    *count += 1;
    if (entries[blockIndex] & 1)
        goto shift;
    candidate = base + 0x4240;
advanceWord:
    *count += 0x20;
    byteOffset += 4;
    blockIndex++;
    blocks = *(u32 *)(volume + 0x1F74);
    if (blockIndex < blocks)
        goto scan;
    candidate += blocks << 5;
candidateCheck:
    if (candidate <= limit)
        goto search;
    return 0;
}
#pragma pop

extern "C" void fn_800B3A70(u8 *buf, u8 *short_name, u32 flags);
extern "C" void fn_800B3BEC(u8 *buf, u8 *src, u8 flags);
extern "C" u8 VFiPFENT_CalcCheckSum(u8 *p_ent) {
    u8 buf[13];
    u32 sum;
    u32 next;
    u16 i;

    fn_800B3A70(buf, &p_ent[0x20E], 0);
    sum = 0;
    for (i = 0; i < 0xB; i++) {
        next = ((sum & 0xFE) >> 1) + ((sum & 1) ? 0x80 : 0) + buf[i];
        sum = next & 0xFF;
    }
    return (u8)sum;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_800AA4EC(u8 *p_ent, u8 *p_buf) {
    s32 value = (s32)p_buf[0xB];
    ((void (*)(u8 *, u8 *, s32))fn_800B3BEC)(&p_ent[0x20E], p_buf, value);
    if ((s8)p_ent[0x20E] == 5) {
        ((s8 *)p_ent)[0x20E] = -0x1B;
    }
}
#pragma pop
extern "C" void VFiPFENT_loadEntryNumericFieldsFromBuf(u8 *p_ent, u8 *p_buf) {
    u8 byteB = p_buf[0xB];
    u8 byteC = p_buf[0xC];
    u8 byteD = p_buf[0xD];

    p_ent[0x21C] = byteB;
    p_ent[0x21B] = byteC;
    p_ent[0x21D] = byteD;

    __sthbrx(*(u16 *)(p_buf + 0xE), p_ent + 0x21E, 0);
    __sthbrx(*(u16 *)(p_buf + 0x10), p_ent + 0x220, 0);
    __sthbrx(*(u16 *)(p_buf + 0x12), p_ent + 0x222, 0);
    __sthbrx(*(u16 *)(p_buf + 0x16), p_ent + 0x224, 0);
    __sthbrx(*(u16 *)(p_buf + 0x18), p_ent + 0x226, 0);

    {
        u32 word1C = *(u32 *)(p_buf + 0x1C);
        u16 short1A = *(u16 *)(p_buf + 0x1A);
        u16 short14 = *(u16 *)(p_buf + 0x14);
        *(u32 *)(p_ent + 0x228) =
            (word1C << 24) | ((word1C & 0xFF00) << 8) |
            ((word1C >> 8) & 0xFF00) | (word1C >> 24);
        *(u32 *)(p_ent + 0x234) =
            ((u32)(short14 & 0xFF) << 24) |
            ((u32)(short14 & 0xFF00) << 8) |
            ((u32)(short1A & 0xFF) << 8) |
            (short1A >> 8);
    }
}

extern "C" s32 VFiPFENT_LoadLFNEntryFieldsFromBuf(void *arg0, void *arg1) {
    extern s32 fn_800A4C14(u16 *, s32);
    u8 *dst=(u8*)arg0,*src=(u8*)arg1;
    u8 raw=src[0], count=raw&0xBF, tag=src[0xD], index;
    u8 *entry; s32 first;
    if(count>0x14){dst[0x20B]=0;dst[0x20C]=0;dst[0x20A]=0;return 0x21;}
    if(raw&0x40){index=count;dst[0x20A]=0;first=1;}
    else{first=0;if(dst[0x20A]==0)return 0x21;if(raw!=(u8)(dst[0x20B]-1)||tag!=dst[0x20C]){dst[0x20B]=0;dst[0x20C]=0;dst[0x20A]=0;return 0x21;}index=raw;}
    dst[0x20B]=index;dst[0x20C]=tag;entry=dst+(index-1)*0x1A;
    VFipf_memcpy(entry,src+1,0xA);VFipf_memcpy(entry+0xA,src+0xE,0xC);VFipf_memcpy(entry+0x16,src+0x1C,4);
    fn_800A4C14((u16*)entry,0xA);fn_800A4C14((u16*)(entry+0xA),0xC);fn_800A4C14((u16*)(entry+0x16),4);
    if(first){u16 *end=(u16*)(entry+0x1A),*p;*(u16*)(entry+0x1A)=0;p=(u16*)entry;while(p<end){if(*p!=0)p++;else p++;}while(p<end){if(*p!=0xFFFF){dst[0x20A]=0;return 0x21;}p++;}}
    dst[0x20A]++;return 0;
}

extern "C" void fn_800A4C14(void *, s32);
extern "C" void VFiPFENT_storeLFNEntryFieldsToBuf(void *out, u8 *entries, s32 index, s32 type, s32 flag) {
 u8 *dst=(u8*)out; u8 *entry=entries+(index-1)*0x1A;
 dst[0]=flag?(index|0x40):index; dst[0xB]=0xF; dst[0xD]=type; dst[0xC]=0; *(u16*)(dst+0x1A)=0;
 if(flag){u16 *end=(u16*)(entry+0x1A), *p=(u16*)entry; while(p<end&&*p==0)++p; while(p<end)*p++=0xFFFF;}
 VFipf_memcpy(dst+1,entry,0xA); VFipf_memcpy(dst+0xE,entry+0xA,0xC); VFipf_memcpy(dst+0x1C,entry+0x16,4);
 fn_800A4C14(dst+1,0xA); fn_800A4C14(dst+0xE,0xC); fn_800A4C14(dst+0x1C,4);
}

extern "C" s32 fn_800AC1B4(void *, s32);
extern "C" s32 VFiPFENT_ITER_IsAtLogicalEnd(void *);
extern "C" s32 VFiPFENT_ITER_Advance(void *, s32);
extern "C" s32 fn_800A9DC0(void *, void *, s32, s32, s32, s32 *);
extern "C" u32 fn_800B5070(s32, s32 *);
#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
extern "C" s32 fn_800AA924(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 *arg6, s32 *arg7) {
    struct Copy14 { s32 word[14]; };
    s32 outValue;
    s32 name = arg2;
    u8 iter[0x70];
    struct Copy14 *src = (struct Copy14 *)arg0;
    struct Copy14 *dst = (struct Copy14 *)(iter + 8);
    u32 mode = 0;
    u32 flags;
    s32 result;
    u8 state;
    *arg6 = mode; *arg7 = mode;
    *(u8 *)((u8 *)arg1 + 0x20A) = (u8)mode;
    *(u8 *)((u8 *)arg1 + 0x20B) = (u8)mode;
    *(u8 *)((u8 *)arg1 + 0x20C) = (u8)mode;
    *(s16 *)arg1 = (s16)mode;
    flags = lbl_803D2140[0x60 / 4];
    outValue = mode;
    if ((flags & 2) == 2) mode = fn_800B5070(arg3, &name);
    *dst = *src;
    if (mode == 1) {
        result = fn_800AC1B4(iter, name - 1);
        if (result != 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return result; }
        result = fn_800A9DC0(arg1, iter, arg3, arg4, arg5, &outValue);
        if (result == 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return 3; }
        if ((iter[0x4C] & 0x40) == 0) goto regular;
        result = fn_800AC1B4(iter, name);
        if (result != 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return result; }
        result = fn_800A9DC0(arg1, iter, arg3, arg4, arg5, &outValue);
        if (result != 0) goto regular;
        *(s32 *)((u8 *)arg1 + 0x22C) = *(s32 *)((u8 *)arg0 + 0x34);
        *arg6 = outValue; *arg7 = *(s32 *)iter;
        return 0;
    }
regular:
    result = fn_800AC1B4(iter, name);
loop:
    if (result != 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return result; }
    state = iter[0x4C];
    if (state == 0) goto fail_main;
    if (state == 0xE5) {
        *(u8 *)((u8 *)arg1 + 0x20A) = 0;
        *(s16 *)arg1 = 0;
    } else {
        result = fn_800A9DC0(arg1, iter, arg3, arg4, arg5, &outValue);
        if (result == 0) {
            *(s32 *)((u8 *)arg1 + 0x22C) = *(s32 *)((u8 *)arg0 + 0x34);
            *arg6 = outValue; *arg7 = *(s32 *)iter;
            return 0;
        }
    }
    result = VFiPFENT_ITER_Advance(iter, 0);
    if (VFiPFENT_ITER_IsAtLogicalEnd(iter) != 0) goto fail_main;
    goto loop;
fail_main:
    *arg6 = 0xF423F; *arg7 = 0xF423F;
    return 3;
}
#pragma pop
extern "C" void fn_800AABE0(void) {
    s32 spC;
    s32 sp8;
    s32 a, b, c, d, e, f;
    ((void (*)(s32, s32, s32, s32, s32, s32, void *, void *))fn_800AA924)(a, b, c, d, e, f, &spC, &sp8);
}

extern "C" s32 fn_800AE620(s32, s32, s32, s32);
extern "C" s32 fn_800B4D00(void);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_800AAC08(void *arg0, u32 arg1, void *arg2, void *arg3, s32 arg4, s32 *arg5) {
    struct Copy14 { u32 word[14]; };
    struct Copy240 { u32 word[0x90]; };
    u8 iter[0x70];
    u8 converted[0x240];
    u32 callResults[2];
    u16 *temp_r31;
    u32 var_r30;
    u16 var_r29;
    u32 var_r28;
    u32 var_r27;
    u32 var_r26;
    s32 var_r25;
    s32 var_r24;
    s32 var_r23;
    s32 var_r3;
    s32 temp_r0;

    if ((((u32)lbl_803D2140[0x60 / 4] & 2U) == 2U) &&
        ((u32)((s32 (*)(s32))fn_800B4D00)(arg4) == 1U)) return 1;

    temp_r31 = *(u16 **)((u8 *)arg2 + 0x34);
    var_r30 = -1;
    var_r24 = 0;
    *(s32 *)((u8 *)arg3 + 4) = -1;
    var_r23 = 0;
    var_r29 = 0;
    var_r28 = -1;
    *(s32 *)arg3 = -1;
    var_r26 = -1;
    var_r27 = -1;
    var_r25 = 0;
    *(u32 *)(iter + 0x44) = 0;
    *(u32 *)iter = 0;
    *(struct Copy14 *)(iter + 8) = *(struct Copy14 *)arg2;

    var_r3 = fn_800AC1B4(iter, 0);
loop:
    if (var_r3 != 0) return var_r3;
    var_r3 = *(s32 *)(iter + 0x44);
    if ((u32)(var_r3 + 0x10000) == 0xFFFFU) goto done;

    if (var_r25 == 0 && var_r24 == 0) {
        var_r29 = *(u16 *)(iter + 0x48);
        var_r30 = var_r3;
        var_r28 = var_r3;
    }
    if (var_r25 == 0) {
        if (iter[0x4C] == 0 || iter[0x4C] == 0xE5) {
            if (var_r28 != (u32)var_r3) {
                temp_r0 = (var_r27 + 1) == 0;
                if (temp_r0 != 0) var_r27 = var_r3;
                if (temp_r0 == 0) var_r26 = var_r3;
                var_r28 = var_r3;
            }
            var_r24++;
        } else {
            var_r24 = 0;
            var_r27 = -1;
            var_r26 = -1;
        }
    }
    if (var_r24 < arg1) goto scan_entry;
    if (var_r25 == 0) {
        var_r23 = *(s32 *)iter;
        var_r25 = 1;
    }
    if (iter[0x4C] != 0) goto scan_entry;
    goto done;

scan_entry:
    if (iter[0x4C] != 0 && iter[0x4C] != 0xE5 &&
        fn_800A9DC0(converted, iter, arg4, 0x7F, 0, (s32 *)&callResults[0]) == 0) {
        *(struct Copy240 *)arg0 = *(struct Copy240 *)converted;
        *(u32 *)((u8 *)arg0 + 0x22C) = *(u32 *)((u8 *)arg2 + 0x34);
        return 8;
    }
    if (*(u16 *)(iter + 0x48) + 0x20 == *temp_r31) {
        var_r3 = fn_800AE620((s32)arg2, *(s32 *)(iter + 0x40) + 1, 0, (s32)&callResults[1]);
        if (var_r3 != 0) return var_r3;
        if ((u32)(callResults[1] + 0x10000) == 0xFFFFU && (u32)var_r25 == 1U) goto done;
    }
    var_r3 = VFiPFENT_ITER_Advance(iter, 1);
    goto loop;

done:
    if (var_r25 == 0) return 5;
    *(s32 *)arg3 = var_r27;
    *(s32 *)((u8 *)arg3 + 4) = var_r26;
    *(s32 *)((u8 *)arg0 + 0x238) = var_r30;
    *(u16 *)((u8 *)arg0 + 0x23C) = var_r29;
    *arg5 = var_r23;
    return 0;
}
#pragma pop
extern "C" void fn_800AAED8(void) {
    s32 sp8;
    s32 a, b, c, d, e;
    ((void (*)(s32, s32, s32, s32, s32, void *))fn_800AAC08)(a, b, c, d, e, &sp8);
}

extern "C" s32 fn_800AAEFC(s32 arg0, void *arg1) {
    ((s32 *)arg1)[0x8B] = arg0;
    ((s16 *)arg1)[0] = 0x5C;
    ((s16 *)arg1)[1] = 0;
    ((u8 *)arg1)[0x20A] = 0;
    ((u8 *)arg1)[0x20B] = 0;
    ((u8 *)arg1)[0x20C] = 0;
    ((u8 *)arg1)[0x20E] = 0x5C;
    ((u8 *)arg1)[0x20F] = 0;
    ((u8 *)arg1)[0x21B] = 0;
    ((u8 *)arg1)[0x21C] = 0x10;
    ((u8 *)arg1)[0x21D] = 0;
    ((s16 *)arg1)[0x10F] = 0;
    ((s16 *)arg1)[0x110] = 0;
    ((s16 *)arg1)[0x111] = 0;
    ((s16 *)arg1)[0x112] = 0;
    ((s16 *)arg1)[0x113] = 0;
    ((s32 *)arg1)[0x8A] = 0;
    ((s32 *)arg1)[0x8C] = 3;
    ((s32 *)arg1)[0x8D] = 1;
    ((s32 *)arg1)[0x8E] = -1;
    ((s16 *)arg1)[0x11E] = 0;
    return 0;
}

extern "C" s32 fn_800B5700(s32, void *, s32, u16, u32, u32 *, u32);
extern "C" s32 fn_800AB0C0(u8 *p_ent, u32 arg1) {
    u8 buf[32];
    u32 count;
    s32 handle = *(s32 *)(p_ent + 0x22C);
    s32 result;
    u16 tmp;
    u32 tmp32;
    if (*(u32 *)(p_ent + 0x234) == 1) return 14;
    if (arg1 == 1) p_ent[0x21C] |= 0x20;
    fn_800B3A70(buf, p_ent + 0x20E, p_ent[0x21C]);
    if (buf[0] == 0xE5) buf[0] = 5;
    buf[11] = p_ent[0x21C];
    buf[12] = p_ent[0x21B];
    buf[13] = p_ent[0x21D];
tmp = *(u16 *)(p_ent + 542); *(u16 *)(buf + 14) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp = *(u16 *)(p_ent + 544); *(u16 *)(buf + 16) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp = *(u16 *)(p_ent + 546); *(u16 *)(buf + 18) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp = *(u16 *)(p_ent + 548); *(u16 *)(buf + 22) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp = *(u16 *)(p_ent + 550); *(u16 *)(buf + 24) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp = *(u32 *)(p_ent + 0x234) >> 16;
*(u16 *)(buf + 20) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp = *(u32 *)(p_ent + 0x234);
*(u16 *)(buf + 26) = (u16)((tmp << 8) | ((u32)tmp >> 8));
tmp32 = *(u32 *)(p_ent + 0x228);
*(u32 *)(buf + 28) = ((tmp32 << 8) & 0xFF0000) | (tmp32 << 24) | ((tmp32 >> 8) & 0xFF00) | (tmp32 >> 24);
result = fn_800B5700(handle, buf, *(s32 *)(p_ent+0x238), *(u16 *)(p_ent+0x23C), 32, &count, 0);
if (result) return result;
return count == 32 ? 0 : 17;
}

extern "C" s32 VFiPFENT_findEmptyTailSFN(void *, void *, u32 *);
extern "C" s32 VFiPFPATH_parseShortNameNumeric(void *);
extern "C" s32 VFiPFENT_AdjustSFN(void *arg0, s8 *arg1) {
    u32 sp8;
    s8 *name = arg1;
    s8 *p = name + 1;
    u32 index = 1;

    while (*p != 0x7E && *p != 0 && index < 7) {
        index++;
        p++;
    }
    if (index < 7 && *p == 0x7E) {
        index++;
        p = name + index;
        p++;
        while (*p >= '0' && *p <= '9') {
            p++;
        }
        if (*p == '.' || *p == 0) {
            s32 result = VFiPFENT_findEmptyTailSFN(arg0, name, &sp8);
            if (result != 0) {
                return result;
            }
            if (sp8 == 1) {
                return 0;
            }
            VFiPFPATH_parseShortNameNumeric(name);
        }
    }
    return 0;
}

extern "C" u8 fn_800AB2F4(void *arg0, void *arg1, s32 arg2) {
    u8 scratch[0x20];
    fn_800B78F4(scratch + 0x10, scratch);
    *(s16 *)arg0 = (s16)(((*(s32 *)(scratch + 0x18) & 0x1F) |
                           ((*(s32 *)(scratch + 0x14) << 5) & 0x1E0)) |
                          (((*(s32 *)(scratch + 0x10) - 0x7BC) << 9) & 0xFE00));
    *(s16 *)arg1 = (s16)((((*(s32 *)(scratch + 8) >> 1) & 0x1F) |
                           ((*(s32 *)(scratch + 4) << 5) & 0x7E0)) |
                          ((*(s32 *)scratch << 11) & 0xF800));
    return (u8)*(s32 *)(scratch + 0xC);
}

extern "C" s32 fn_800AB378(void *, s32, ...);
extern s32 fn_800B5324(void *, void *, u32, u32, u32 *, u32);
extern "C" s32 fn_800B5324(void *, u8 *, u32, u32, u32, u32 *, s32);
extern "C" s32 fn_800AC1B4(void *arg0, s32 arg1) {
    u32 one = 1;
    u32 sp8;
    s32 var_r31;
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r4;
    u8 temp_r7;
    void *temp_r5;
    temp_r5 = *(void **)((u8 *)arg0 + 0x3C);
    temp_r30 = *(s32 *)arg0;
    *(void **)((u8 *)arg0 + 4) = temp_r5;
    temp_r7 = *(u8 *)((u8 *)temp_r5 + 0x20) - 5;
    *(s32 *)arg0 = arg1;
    *(u8 *)((u8 *)arg0 + 0x6C) = temp_r7;
    *(u16 *)((u8 *)arg0 + 0x4A) = (one << temp_r7) - 1;
    *(s32 *)((u8 *)arg0 + 0x40) = -1;
    temp_r3 = ((s32 (*)(void *, s32))fn_800AB378)(arg0, 0);
    var_r31 = temp_r3;
    if (temp_r3 != 0) {
        *(s32 *)arg0 = temp_r30;
        ((s32 (*)(void *, s32))fn_800AB378)(arg0, 0);
    } else {
        if (*(u32 *)((u8 *)arg0 + 0x44) == 0xFFFFFFFFU) {
            temp_r4 = 0x10;
        } else {
            temp_r3 = fn_800B5324(*(void **)((u8 *)arg0 + 4),
                                   (u8 *)arg0 + 0x4C,
                                   *(u32 *)((u8 *)arg0 + 0x44),
                                   *(u16 *)((u8 *)arg0 + 0x48),
                                   0x20,
                                   &sp8,
                                   0);
            temp_r4 = 0x11;
            if (sp8 == 0x20)
                temp_r4 = temp_r3;
        }
        var_r31 = temp_r4 & (-(temp_r4 != 0));
    }
    return var_r31;
}

extern "C" s32 VFiPFENT_ITER_IsAtLogicalEnd(void *arg0) {
    u32 sp8;
    s32 index;
    u32 old;
    s32 result;
    s32 status;
    VFiPFENTIterLayout *iter = (VFiPFENTIterLayout *)arg0;

    if (iter->sentinel == 0xFFFFFFFFu ||
        iter->data[0] == 0 ||
        iter->position < 0xF423Fu) {
        goto return_zero;
    }
    index = iter->index;
    old = iter->position;
    iter->position = (index + 1) << iter->shift;
    if (((s32 (*)(void *, s32, s32))fn_800AB378)(arg0, 0, index + 1) != 0) {
        iter->position = old;
        iter->index = index;
        goto return_one;
    }

    if (iter->sentinel == 0xFFFFFFFFu) {
        goto use_short_error;
    }
    if (iter->sentinel != 0xFFFFFFFFu) {
        goto read_entry;
    }
use_short_error:
    status = 0x10;
    goto finish_status;

read_entry:
    result = fn_800B5324(iter->stream, iter->data, iter->sentinel,
                         iter->length, 0x20, &sp8, 0);
    status = 0x11;
    if (sp8 == 0x20) {
        status = result;
    }
finish_status:
    return status != 0;

return_one:
    return 1;
return_zero:
    return 0;
}

extern "C" s32 VFiPFENT_ITER_Advance(void *arg0, s32 arg1) {
    void *iter = arg0;
    s32 result;
    s32 error;
    u32 length;
    u32 next;
    u32 index = *(u32 *)iter;
    next = index + 1;

    if (index != next)
        goto normal;
    if (*(u32 *)((u8 *)iter + 0x44) + 0x10000 != 0xFFFF)
        goto normal;
    if (arg1 != 0)
        goto zero;
    *(u32 *)iter = next;
    result = ((s32 (*)(void *, s32))fn_800AB378)(iter, arg1);
    if (result != 0) {
        *(u32 *)iter = index;
        ((s32 (*)(void *, s32))fn_800AB378)(iter, 0);
        goto done;
    }
normal:
    if (*(u32 *)((u8 *)iter + 0x44) + 0x10000 == 0xFFFF) {
        error = 0x10;
    } else {
        result = fn_800B5324(*(void **)((u8 *)iter + 4),
                             (u8 *)iter + 0x4C,
                             *(u32 *)((u8 *)iter + 0x44),
                             *(u16 *)((u8 *)iter + 0x48),
                             0x20,
                             &length,
                             0);
        error = 0x11;
        if (length == 0x20)
            error = result;
    }
    result = error & ((-error | error) >> 31);
    switch (result) {
    case 0:
        goto zero;
    default:
        goto done;
    }
zero:
    result = 0;
done:
    return result;
}

extern "C" s32 fn_800AB378(void *, s32, ...);
s32 fn_800AEBA0(void *, u32, u32 *);
s32 fn_800B5324(void *, void *, u16, s32, u32 *, s32);
s32 fn_800AC4AC(void *arg0, s32 arg1) {
    u32 spC, sp8;
    s32 temp_r29, temp_r3, temp_r3_2, temp_r3_3, var_r30, var_r4;
    u32 temp_r0, temp_r10, temp_r4, temp_r6, temp_r9;
    u8 temp_r8;
    void *temp_r6_2, *temp_r6_3;
    temp_r29 = *(s32 *)((u8 *)arg0);
    if (temp_r29 == 0) return 0;
    temp_r6 = temp_r29 - 1;
    if (*(u32 *)((u8 *)arg0 + 0x40) != (temp_r6 >> *(u8 *)((u8 *)arg0 + 0x6C))) {
        temp_r6_2 = *(void **)((u8 *)arg0 + 4);
        temp_r9 = *(u32 *)((u8 *)arg0 + 0x44);
        temp_r8 = *(u8 *)((u8 *)temp_r6_2 + 6);
        temp_r10 = *(u32 *)((u8 *)temp_r6_2 + 0x30);
        temp_r4 = ((temp_r9 - temp_r10) >> *(u8 *)((u8 *)temp_r6_2 + 0x21)) + 2;
        if ((*(u32 *)((u8 *)arg0 + 0x40) % temp_r8) == 0 || temp_r8 == 1) {
            if (*(s32 *)((u8 *)temp_r6_2 + 0x1C) == 2 || (*(u32 *)*(u32 **)((u8 *)arg0 + 0x10) > 1 && temp_r10 <= temp_r9)) {
                temp_r3 = fn_800AEBA0(temp_r6_2, temp_r4, &spC);
                if (temp_r3 != 0) return temp_r3;
                if (spC == 0xFFFFFFFF) return 0xE;
            } else spC = *(u32 *)*(u32 **)((u8 *)arg0 + 0x10);
        } else spC = temp_r4;
        temp_r6_3 = *(void **)((u8 *)arg0 + 4);
        *(s32 *)((u8 *)arg0) -= 1;
        *(u32 *)((u8 *)arg0 + 0x40) -= 1;
        if (*(s32 *)((u8 *)temp_r6_3 + 0x1C) == 2 || (*(u32 *)*(u32 **)((u8 *)arg0 + 0x10) > 1 && *(u32 *)((u8 *)temp_r6_3 + 0x30) <= *(u32 *)((u8 *)arg0 + 0x44))) {
            *(u32 *)((u8 *)arg0 + 0x44) = ((*(u32 *)((u8 *)arg0 + 0x40) & (*(u8 *)((u8 *)temp_r6_3 + 6) - 1)) + (*(u32 *)((u8 *)temp_r6_3 + 0x30) + ((spC - 2) << *(u8 *)((u8 *)temp_r6_3 + 0x21))));
        } else *(u32 *)((u8 *)arg0 + 0x44) -= 1;
        *(u16 *)((u8 *)arg0 + 0x48) = (*(u32 *)((u8 *)arg0) & *(u16 *)((u8 *)arg0 + 0x4A)) << 5 & 0xFFE0;
        return 0;
    }
    if ((u32)temp_r29 != temp_r6 || *(u32 *)((u8 *)arg0 + 0x44) != 0xFFFFFFFF || arg1 == 0) {
        *(s32 *)((u8 *)arg0) = temp_r6;
        temp_r3_2 = fn_800AB378(arg0, 0);
        var_r30 = temp_r3_2;
        if (temp_r3_2 != 0) {
            *(s32 *)((u8 *)arg0) = temp_r29;
            fn_800AB378(arg0, 0);
        } else {
            if (*(u32 *)((u8 *)arg0 + 0x44) == 0xFFFFFFFF) var_r4 = 0x10;
            else {
                temp_r3_3 = fn_800B5324(*(void **)((u8 *)arg0 + 4), (u8 *)arg0 + 0x4C, *(u16 *)((u8 *)arg0 + 0x48), 0x20, &sp8, 0);
                var_r4 = 0x11;
                if (sp8 == 0x20) var_r4 = temp_r3_3;
            }
            var_r30 = var_r4 & ((-var_r4 | var_r4) >> 31);
        }
        if (var_r30 == 0) var_r30 = 0;
    } else var_r30 = 0;
    return var_r30;
}

extern "C" void VFiPFPATH_getLongNameformShortName(void *, void *, s32);
extern "C" s32 fn_800B5324(void *, u8 *, u32, u32, u32, u32 *, s32);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_800AC708(register void *arg0, register u8 *arg1, register u32 arg2, register s32 *arg3) {
    register u8 *iter;
    s32 status;
    register s32 result;
    register s32 zero;
    s32 callResult;
    u32 sp8;
    u8 spC[13];
    u8 flags;

    status = 0;
    *arg3 = status;
    arg1[0x20A] = (u8)status;
    arg1[0x20B] = (u8)status;
    arg1[0x20C] = (u8)status;
    if ((arg1[0x21C] & 0x10) && (*(u32 *)(arg1 + 0x234) == 1)) return 2;
    iter = (u8 *)arg0;
    zero = 0;
    goto check_end;
status_check:
    if (status != 0) return status;
process:
    if (iter[0x4C] == 0xE5) {
        arg1[0x20A] = (u8)zero;
        *(u16 *)arg1 = (u16)zero;
        goto advance;
    }
    flags = iter[0x57];
    if ((flags & 0xF) == 0xF) {
        if (VFiPFENT_LoadLFNEntryFieldsFromBuf(arg1, iter + 0x4C) != 0) {
            arg1[0x20A] = (u8)zero;
            *(u16 *)arg1 = (u16)zero;
        }
        goto advance;
    }
    if (flags & 8) {
        arg1[0x20A] = (u8)zero;
        *(u16 *)arg1 = (u16)zero;
        goto advance;
    }
    if (!(flags & 0x10)) {
        arg1[0x20A] = (u8)zero;
        *(u16 *)arg1 = (u16)zero;
        goto advance;
    }
    ((void (*)(u8 *, u8 *))fn_800AA4EC)(arg1, iter + 0x4C);
    if (arg1[0x20A] != 0 && arg1[0x20B] == 1 &&
        arg1[0x20C] == ((u8 (*)(u8 *))VFiPFENT_CalcCheckSum)(arg1)) {
        VFiPFENT_loadEntryNumericFieldsFromBuf(arg1, iter + 0x4C);
        *(u32 *)(arg1 + 0x238) = *(u32 *)(iter + 0x44);
        *(u16 *)(arg1 + 0x23C) = *(u16 *)(iter + 0x48);
        *(u32 *)(arg1 + 0x22C) = *(u32 *)(iter + 0x3C);
        flags = arg1[0x21C] & 0x10;
        if (flags && *(u32 *)(arg1 + 0x234) != arg2) {
            arg1[0x20A] = (u8)zero;
            *(u16 *)arg1 = (u16)zero;
            goto advance;
        }
        if (flags && *(u32 *)(arg1 + 0x234) == 0) {
            *(u32 *)(arg1 + 0x234) = 1;
            *arg3 = 1;
        }
    }
    flags = iter[0x58];
    if (flags & 0x18) {
        s32 length;
        VFiPFPATH_getLongNameformShortName(arg1 + 0x20E, spC, flags);
        length = ((s32 (*)(s16 *, s32))VFiPFPATH_transformInUnicode)((s16 *)arg1, (s32)spC);
        arg1[0x20A] = (u8)(length / 13 + (length % 13 != 0));
        arg1[0x20C] = ((u8 (*)(u8 *))VFiPFENT_CalcCheckSum)(arg1);
        arg1[0x20B] = 1;
    }
    VFiPFENT_loadEntryNumericFieldsFromBuf(arg1, iter + 0x4C);
    *(u32 *)(arg1 + 0x238) = *(u32 *)(iter + 0x44);
    flags = arg1[0x21C] & 0x10;
    *(u16 *)(arg1 + 0x23C) = *(u16 *)(iter + 0x48);
    *(u32 *)(arg1 + 0x22C) = *(u32 *)(iter + 0x3C);
    if (flags && *(u32 *)(arg1 + 0x234) != arg2) {
        arg1[0x20A] = (u8)zero;
        *(u16 *)arg1 = (u16)zero;
        *arg3 = zero;
        goto advance;
    }
    if (flags && *(u32 *)(arg1 + 0x234) == 0) {
        *(u32 *)(arg1 + 0x234) = 1;
        *arg3 = 1;
    }
    return 0;
advance:
    {
        u32 old = *(u32 *)iter;
        *(u32 *)iter = old + 1;
        result = fn_800AB378((void *)iter, 0);
        if (result != 0) {
            *(u32 *)iter = old;
            fn_800AB378((void *)iter, 0);
        } else if (*(u32 *)(iter + 0x44) + 0x10000 == 0xFFFF) {
            result = 0x10;
        } else {
            callResult = fn_800B5324(*(void **)(iter + 4),
                                     iter + 0x4C,
                                     *(u32 *)(iter + 0x44),
                                     *(u16 *)(iter + 0x48),
                                     0x20, &sp8, 0);
            if (sp8 != 0x20) result = 0x11;
            else result = callResult;
        }
        result = result & (s32)(-(u32)result | (u32)result) >> 31;
        status = result & (s32)(-(u32)result | (u32)result) >> 31;
    }
check_end:
    if (VFiPFENT_ITER_IsAtLogicalEnd((void *)iter) == 0) goto status_check;
    return 0;
}
#pragma pop
extern "C" s32 fn_800ABC60(s32 arg0, s32 arg1);
extern "C" void fn_800B78F4(void *arg0, void *arg1);
extern "C" s32 fn_800ABC60(s32, s32);
extern "C" void fn_800ACA44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((s32 (*)(s32, s32, s32, s32, s32, s32))fn_800ABC60)(arg0, arg1, arg2, arg3, 0, arg4);
}

extern "C" void fn_800ACA50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((s32 (*)(s32, s32, s32, s32, s32, s32))fn_800ABC60)(arg0, arg1, arg2, arg3, 1, 1);
}

extern s32 fn_800A8D08(void *, s32, void **, s32 *);
extern s32 fn_800B5324(void *, s32, s32, s32, u16, u32 *, s32);
extern s32 fn_800B5700(void *, s32, s32, s32, u16, u32 *, s32);
extern s32 fn_800A499C(s32, s32);
extern "C" s32 VFiPFCACHE_FreeFATPage_800A8E10(void *, void *);
extern "C" s32 fn_800ACDF8(void *arg0, s32 arg1) {
    /* Fix note: execute the two reads before checking whether another page sector remains. */
    void *sp10;
    s32 spC;
    u32 sp8;
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    u32 var_r29;

    temp_r3 = fn_800A8D08(arg0, -1, &sp10, &spC);
    if (temp_r3 != 0)
        return temp_r3;

    var_r29 = 0;
    temp_r30 = *(s32 *)((u8 *)arg0 + 0x30) +
               ((arg1 - 2) << *((u8 *)arg0 + 0x21));
    do {
        temp_r31 = temp_r30 + var_r29;
        if (fn_800B5324(arg0, *(s32 *)((u8 *)sp10 + 8), temp_r31,
                        0, *(u16 *)arg0, &sp8, 1) != 0 ||
            sp8 != *(u16 *)arg0)
            break;
        fn_800A499C(*(s32 *)((u8 *)sp10 + 8), 0);
        if (fn_800B5700(arg0, *(s32 *)((u8 *)sp10 + 8), temp_r31,
                        0, *(u16 *)arg0, &sp8, 1) != 0 ||
            sp8 != *(u16 *)arg0)
            break;
        ++var_r29;
    } while (var_r29 < *((u8 *)arg0 + 6));

    VFiPFCACHE_FreeFATPage_800A8E10(arg0, sp10);
    return 0;
}

extern s32 fn_800A8D08(void *, s32, void **, s32 *);
extern "C" s32 fn_800ACBB0(void *, s32, s32, s32, u32 *, u32 *);
extern "C" s32 VFiPFFAT_WriteClusterPage(void *, u32, u32, u32, s32, void *);
extern "C" s32 fn_800AF144(void *);
extern s32 fn_800B5618(void *, s32, s32, s32, u16);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_800ACDF8(void *, s32);
extern s32 fn_800A8D08(void *, s32, void **, s32 *);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_800ACDF8(void *, s32);
extern "C" s32 VFiPFCACHE_FreeFATPage_800A8E10(void *, void *);
extern "C" s32 fn_800ACBB0(void *, s32, s32, s32, u32 *, u32 *);
extern "C" s32 VFiPFFAT_WriteClusterPage(void *, u32, u32, u32, s32, void *);
extern "C" s32 fn_800AF144(void *);
extern s32 fn_800B5618(void *, s32, s32, s32, u16);
#pragma push
#pragma use_lmw_stmw off
#pragma pop
extern "C" s32 fn_800ADA24(void *arg0, s32 arg1, u32 arg2, u32 *arg3, u32 *arg4, s32 arg5, s32 arg6) {
    void *context = *(void **)((u8 *)arg0 + 0x34);
    u32 first;
    u32 end;
    s32 pageIndex;
    void *page;
    u32 maxCluster;
    u32 cluster;
    register u32 index;
    s32 result;
    s32 savedResult;
    void *buffer;
    u8 *bufferData;

    maxCluster = lbl_802EEF40[*(s32 *)((u8 *)context + 0x1C) * 5 + 2];
    *arg3 = -1;
    *arg4 = -1;
    end = -1;
    result = fn_800ACBB0(context, *(s32 *)((u8 *)context + 0x3C), -1, arg1, &first, &end);
    if (result != 0) return result;
    if (first == -1) return 0;
    if (arg5 != 0) {
        result = fn_800ACDF8(context, arg1);
        if (result != 0) return result;
    }
    result = fn_800A8D08(context, -1, &page, &pageIndex);
    if (result != 0) return result;
    result = fn_800ACA5C(context, page, first);
    if (result != 0) {
        VFiPFCACHE_FreeFATPage_800A8E10(context, page);
        return result;
    }
    *(u16 *)((u8 *)page + 2) = 0;
    cluster = first;
    while (cluster < end) {
        result = VFiPFFAT_WriteClusterPage(arg0, cluster, arg2, cluster + 1, 1, page);
        if (result != 0) {
            VFiPFCACHE_FreeFATPage_800A8E10(context, page);
            return result;
        }
        if ((*(u16 *)((u8 *)context + 0x1FAC) & 4) != 0) {
            if (*(u32 *)((u8 *)context + 0x38) != -1 &&
                *(u32 *)((u8 *)context + 0x38) != 0 &&
                (*(s32 *)((u8 *)context + 0x1C) != 2 ||
                 end != *(u32 *)((u8 *)context + 0x10))) {
                *(u32 *)((u8 *)context + 0x38) -= 1;
            }
        }
        if (*arg3 == -1) *arg3 = cluster;
        *arg4 = cluster;
        arg2++;
        cluster++;
    }
    if (end != -1) {
        result = VFiPFFAT_WriteClusterPage(arg0, end, arg2, maxCluster, 1, page);
        if (result != 0) {
            VFiPFCACHE_FreeFATPage_800A8E10(context, page);
            return result;
        }
    }
    if (*arg3 == -1) {
        *arg3 = cluster;
        *arg4 = cluster;
    }
    {
        if (*(u32 *)((u8 *)context + 0x38) != -1 &&
            *(u32 *)((u8 *)context + 0x38) != 0 &&
            (*(s32 *)((u8 *)context + 0x1C) != 2 ||
             end != *(u32 *)((u8 *)context + 0x10))) {
            *(u32 *)((u8 *)context + 0x38) -= 1;
        }
    }
    *(u32 *)((u8 *)context + 0x3C) = end + 1;
    *(u32 *)((u8 *)arg0 + 0xC) = end;
    *(u32 *)((u8 *)arg0 + 0x10) = arg2;
    *arg4 = end;
    buffer = page;
    bufferData = *(u8 **)((u8 *)buffer + 0x18);
    savedResult = 0;
    for (index = 0; (s32)(u16)index < (s32)*((u8 *)context + 0x22); index++) {
        result = fn_800B5618(context, *(s32 *)((u8 *)buffer + 8),
                             (s32)bufferData, 0, *(u16 *)context);
        if (result != 0 && savedResult == 0) savedResult = result;
        bufferData += *(s32 *)((u8 *)context + 0xC);
    }
    if (savedResult != 0) {
        VFiPFCACHE_FreeFATPage_800A8E10(context, page);
        return savedResult;
    }
    VFiPFCACHE_FreeFATPage_800A8E10(context, page);
    if (*(s32 *)((u8 *)context + 0x1C) == 2 &&
        (*(u16 *)((u8 *)context + 0x1FAC) & 2) != 0 &&
        fn_800AF144(context) != 0) {
        *(u32 *)((u8 *)context + 0x38) = -1;
        *(u16 *)((u8 *)context + 0x1FAC) &= ~4;
    }
    return 0;
}

extern "C" s32 VFiPFFAT_ReadClusterPage(void *, u32, s32, s32 *, s32 *, void *);
extern "C" s32 VFiPFFAT_WriteCluster(void *, s32, s32, s32, s32);
extern "C" s32 fn_800AE7A8(void *, s32, s32);
extern "C" s32 fn_800ADD84(void *arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4, s32 *arg5) {
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    void *sp8;
    s32 temp_cr0_eq;
    s32 temp_r0;
    s32 temp_r10;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r7;
    s32 temp_r9;
    u32 *tableEntry;
    u32 temp_r31;
    u32 temp_r30;
    s32 var_r29;
    u32 var_r28;
    u32 var_r27;
    s32 var_r26;
    s32 *var_r25;

    temp_r10 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x1C);
    *arg5 = -1;
    *arg4 = -1;
    temp_r31 = ((volatile u32 *)lbl_802EEF40)[temp_r10 * 5];
    temp_r0 = *(volatile s32 *)((u8 *)arg0 + 0x14);
    tableEntry = ((u32 *)lbl_802EEF40) + temp_r10 * 5;
    temp_r30 = tableEntry[1];
    if ((temp_r0 != 0) && ((u32)temp_r0 <= (u32)arg1)) {
        var_r25 = &sp14;
        sp14 = *(s32 *)((u8 *)arg0 + 0x18);
        temp_r7 = *(s32 *)((u8 *)arg0 + 0x14);
        var_r28 = (u32)arg1 - temp_r7;
        var_r26 = temp_r7 + 1;
    } else {
        var_r25 = *(s32 **)((u8 *)arg0 + 8);
        var_r28 = (u32)arg1;
        var_r26 = 1;
    }
    var_r29 = *var_r25;
    sp18 = var_r29;
    if ((u32)arg2 == 2U) {
        if (((s32)var_r28 != 0) && (arg3 != 0)) {
            var_r28 = (var_r28 + arg3) - 1;
        } else {
            var_r28 = (u32)arg3;
        }
        temp_r9 = *(s32 *)((u8 *)arg0 + 0xC);
        var_r27 = var_r28;
        if (temp_r9 != 0) {
            var_r29 = temp_r9;
            var_r28 = 0U;
            var_r27 = (*(s32 *)((u8 *)arg0 + 0x10) + arg3) - arg1;
            sp18 = *(s32 *)((u8 *)lbl_802EEF40 + *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x1C) * 0x14 + 8);
            var_r26 = *(s32 *)((u8 *)arg0 + 0x10) + 1;
        }
    } else {
        if (((u32)arg2 == 1U) && (var_r29 == 0)) {
            var_r28 += 1;
        }
        var_r27 = var_r28;
    }
    if ((s32)var_r28 != 0) {
        temp_r3_4 = ((s32 (*)(void *, s32, void **, s32 *))fn_800A8D08)(
            *(void **)((u8 *)arg0 + 0x34), -1, &sp8, &sp10);
        if (temp_r3_4 != 0) {
            return temp_r3_4;
        }
        temp_r3_3 = fn_800ACA5C(*(void **)((u8 *)arg0 + 0x34), sp8, var_r29);
        if (temp_r3_3 != 0) {
            VFiPFCACHE_FreeFATPage_800A8E10(*(void **)((u8 *)arg0 + 0x34), sp8);
            return temp_r3_3;
        }
        *(s16 *)((u8 *)sp8 + 2) = 0;
        spC = 1;
loop_33:
        if (var_r29 != 0) {
            temp_r3_2 = VFiPFFAT_ReadClusterPage(arg0, (u32)var_r29, var_r26, &sp18, &spC, sp8);
            if ((temp_r3_2 != 0) && ((u32)(sp18 + 0x10000) != 0xFFFFU)) {
                VFiPFCACHE_FreeFATPage_800A8E10(*(void **)((u8 *)arg0 + 0x34), sp8);
                return temp_r3_2;
            }
            goto block_26;
        }
        var_r26 -= 1;
        sp18 = *(s32 *)((u8 *)lbl_802EEF40 + *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x1C) * 0x14 + 8);
block_26:
        if ((((u32)sp18 < 2U) ||
             ((u32)sp18 >= (u32)(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x34) + 2))) &&
            ((u32)sp18 < temp_r30)) {
            VFiPFCACHE_FreeFATPage_800A8E10(*(void **)((u8 *)arg0 + 0x34), sp8);
            return 0xE;
        }
        if (((s32)arg2 == 0) || ((u32)sp18 < temp_r30)) {
            var_r29 = sp18;
            var_r26 += 1;
            if (var_r28 == 0)
                goto block_35;
            var_r28 -= 1;
            if ((u32)var_r29 < temp_r31)
                goto loop_33;
        }
block_35:
        var_r27 = var_r28;
        VFiPFCACHE_FreeFATPage_800A8E10(*(void **)((u8 *)arg0 + 0x34), sp8);
        goto block_36;
    }
block_36:
    if (((s32)arg2 != 0) && ((u32)sp18 >= temp_r30)) {
        *arg4 = 0;
        temp_r3_5 = ((s32 (*)(void *, s32, u32, u32 *, s32 *, s32))fn_800ADA24)(
            arg0, var_r27 + 1, var_r26, arg4, &sp18, 0);
        arg2 = temp_r3_5;
        if (temp_r3_5 != 0) {
            if ((u32)(*arg4 + 0x10000) != 0xFFFFU) {
                ((s32 (*)(void *, s32, s32, s32))fn_800AE7A8)(arg0, *arg4, var_r26, -1);
            }
            *arg4 = -1;
            sp18 = -1;
        } else {
            arg2 = 0;
        }
        if (arg2 != 0) {
            return arg2;
        }
        if ((u32)(sp18 + 0x10000) == 0xFFFFU) {
            return 6;
        }
        if ((s32)*var_r25 == 0) {
            *var_r25 = *arg4;
            goto block_51;
        }
        temp_r3 = VFiPFFAT_WriteCluster(arg0, var_r29, var_r26 - 1, *arg4, 1);
        if (temp_r3 != 0) {
            return temp_r3;
        }
block_51:
        var_r29 = sp18;
        goto block_52;
    }
block_52:
    *arg5 = var_r29;
    return 0;
}

extern "C" s32 fn_800AD24C(void *, s32, s32, s32 *, s32 *);
extern "C" s32 fn_800AE108(void *arg0, s32 arg1, s32 arg2, u32 arg3, s32 *arg4, s32 arg5) {
    void *context = *(void **)((u8 *)arg0 + 0x34);
    s32 end = -1;
    s32 one = 1;
    void *object = arg0;
    s32 position = arg1;

    while (end != 0) {
        s32 result = fn_800AD24C(object, position, arg2, &end, &one);
        if (result != 0) return result;
        if ((u32)(position + 1) != (u32)end) {
            u32 index = *(u32 *)((u8 *)context + 0x1C);
            u32 expected = *(u32 *)((u8 *)lbl_802EEF40 + index * 0x14 + 8);
            if ((u32)end == expected) {
                *(s32 *)((u8 *)object + 0xC) = position;
                *(s32 *)((u8 *)object + 0x10) = arg2 - 1;
            }
            break;
        }
        ++*(s32 *)*(void **)((u8 *)object + 0x30);
        *(s32 *)((u8 *)*(void **)((u8 *)object + 0x30) + 4) = end;
        *arg4 += *(u8 *)((u8 *)context + 6);
        if (((u32)*arg4 << *(u8 *)((u8 *)context + 0x20)) >= arg3)
            break;
        position = end;
        ++arg2;
    }
    return 0;
}

extern "C" s32 fn_800ADD84(void *, s32, s32, s32, u32 *, s32 *);
extern "C" s32 fn_800AE3A8(void *arg0, s32 arg1, s32 arg2, u32 *arg3) {
    s32 spC;
    u32 sp8;
    u32 *temp_r7 = *(u32 **)((u8 *)arg0 + 8);
    void *temp_r8 = *(void **)((u8 *)arg0 + 0x34);
    void *temp_r31 = *(void **)((u8 *)arg0 + 0x30);
    u32 temp_r4 = *(u32 *)((u8 *)temp_r8 + 0x1C);
    s32 var_r3;
    if (*temp_r7 == 1) {
        if (temp_r4 <= 1) {
            *arg3 = -1;
            return 0;
        }
        *temp_r7 = *(u32 *)((u8 *)temp_r8 + 0x10);
    }
    *arg3 = -1;
    var_r3 = fn_800ADD84(arg0, arg1, 2, arg2, &sp8, &spC);
    if (var_r3 != 0) goto sentinel;
    if (sp8 >= 2 && sp8 < *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x34) + 2) {
        *arg3 = sp8;
    }
    var_r3 = 0;
    if (var_r3 != 0) goto sentinel;
    if ((*arg3 + 0x10000) == 0xFFFF) {
sentinel:
        return 0;
    }
    *(u32 *)((u8 *)temp_r31 + 8) = *(u32 *)arg0;
    *(s32 *)temp_r31 = arg1;
    *(u32 *)((u8 *)temp_r31 + 4) = *arg3;
    return 0;
}

s32 VFiPFFAT_GetClusterSpecified(s32 *);
s32 fn_800AE3A8(s32, s32 *, u8, u32);
s32 fn_800AE4C0(void *arg0, u32 arg1, u32 arg2, u32 arg3, s32 *arg4) {
    s32 sp8;
    s32 r;
    u32 q, rem;
    u16 bytes;
    u8 clusters, shift;
    void *fat;
    fat = *(void **)((char *)arg0 + 0x34);
    if (**(u32 **)((char *)arg0 + 8) == 1 && *(u32 *)((char *)fat + 0x1C) <= 1) {
        if (arg1 >= *(u16 *)((char *)fat + 0x24))
            *arg4 = -1;
        else
            *arg4 = *(s32 *)((char *)fat + 0x2C) + arg1;
        return 0;
    }
    shift = *(u8 *)((char *)fat + 0x21);
    arg1 >>= shift;
    if (arg2 == 2) {
        bytes = *(u16 *)fat;
        clusters = *(u8 *)((char *)fat + 6);
        q = arg3 / bytes;
        rem = arg3 % bytes;
        q += rem != 0;
        rem = q % clusters;
        q /= clusters;
        q += rem != 0;
        r = fn_800AE3A8(q, &sp8, clusters, q);
    } else {
        r = VFiPFFAT_GetClusterSpecified(&sp8);
    }
    if (r != 0) return r;
    if (sp8 == -1) {
        *arg4 = -1;
        return 0;
    }
    *arg4 = (*(u8 *)((char *)fat + 6) - 1 & arg1) +
        (*(s32 *)((char *)fat + 0x30) + ((sp8 - 2) << *(u8 *)((char *)fat + 0x21)));
    return 0;
}

extern "C" s32 fn_800AF5A0(u16);
extern "C" s32 fn_800AFE14(void *arg0, s32 arg1, s32 *arg2);
extern "C" s32 fn_800B5260(void *, void *, u32, u32, s32);
extern "C" s32 fn_800B0258(void *, s32, s32 *);
extern "C" s32 fn_800AE4C0(s32, s32, s32);
extern "C" s32 fn_800AE620(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sign = (-arg2 | arg2) >> 31;
    s32 result = fn_800AE4C0(arg2 & sign, 0, arg3);
    return (result != 0) ? result : 0;
}

extern "C" s32 VFiPFCACHE_FreeFATPage_800A8E10(void *, void *);
extern "C" s32 fn_800A8D08(s32, void **, s32 *, s32, s32 *);
extern "C" s32 fn_800AFBA8(void *, u16, u32 *);
extern "C" s32 fn_800B00E8(void *, u16, u32 *);
extern "C" s32 fn_800B05C8(void *, u16, u32 *);
extern "C" s32 fn_800AEBA0(void *arg0, u16 arg1, u32 arg2, u32 *arg3, s32 arg_sp0) {
    void *page;
    s32 pageIndex;
    s32 type;
    s32 result;
    u32 value;
    u32 maxValue;

    type = *(s32 *)((u8 *)arg0 + 0x1C);
    maxValue = *(u32 *)((u8 *)lbl_802EEF40 + type * 0x14 + 4);
    *arg3 = -1;
    result = fn_800A8D08(-1, &page, &pageIndex, type, (s32 *)lbl_802EEF40);
    if (result != 0) return result;
    *(u16 *)((u8 *)page + 2) = 0;
    for (;;) {
        if (arg1 >= maxValue) {
            VFiPFCACHE_FreeFATPage_800A8E10(arg0, page);
            return 0xD;
        }
        type = *(s32 *)((u8 *)arg0 + 0x1C);
        if (type == 0) result = fn_800AFBA8(arg0, arg1, &value);
        else if (type == 1) result = fn_800B00E8(arg0, arg1, &value);
        else if (type == 2) result = fn_800B05C8(arg0, arg1, &value);
        else result = 0xF;
        if (result != 0) {
            VFiPFCACHE_FreeFATPage_800A8E10(arg0, page);
            return result;
        }
        if (arg2 == value) {
            *arg3 = arg1;
            return 0;
        }
        arg1--;
        if (arg1 >= 2 && arg1 < *(u32 *)((u8 *)arg0 + 0x34) + 2) continue;
        if (arg1 < maxValue) {
            *arg3 = arg2;
            return 0;
        }
    }
}

s32 fn_800AEF6C(void *arg0) { return 0; }

extern "C" void fn_800AF2B8(void *);
extern "C" void fn_800AF2B8(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

s32 fn_800AF2CC(void *arg0, u32 arg1, s32 arg2, s32 *arg3, u32 *arg4, s32 arg5) {
    s32 end;
    s32 one = 1;
    s32 result;
    s32 type;
    s32 pageCount;
    s32 pageSize;
    s32 count;
    s32 page;
    s32 i;
    s32 pos;
    u32 savedPos = (u32)arg1;
    void *context;

    *arg3 = 0;
    *arg4 = 0;
    if (*(u32 *)*(u32 **)((u8 *)arg0 + 8) < 2)
        return 0;
    if (arg1 < 2)
        return 0;
    if (arg2 == 0)
        return 0;
    context = *(void **)((u8 *)arg0 + 0x34);
    type = *(s32 *)((u8 *)context + 0x1C);
    if (arg2 == -1 && *(s32 *)((u8 *)arg0 + 0xC) != 0) {
        *arg3 = *(s32 *)((u8 *)arg0 + 0xC);
        *arg4 = *(u32 *)((u8 *)lbl_802EEF40 + type * 0x14 + 8);
        return 0;
    }
    pageSize = *(u16 *)context * *(u8 *)((u8 *)context + 6);
    count = arg2 / pageSize;
    if (arg2 % pageSize != 0)
        count++;
    if (*(u32 *)*(u32 **)((u8 *)arg0 + 8) == arg1) {
        page = 1;
    } else {
        page = **(s32 **)((u8 *)arg0 + 0x30) + 1;
    }
    end = -1;
    i = 0;
    while (i < count) {
        result = fn_800AD24C(arg0, arg1, page, &end, &one);
        if (result != 0)
            return result;
        savedPos = arg1;
        if ((u32)end == *(u32 *)((u8 *)lbl_802EEF40 + type * 0x14 + 8)) {
            *(u32 *)((u8 *)arg0 + 0xC) = arg1;
            *(s32 *)((u8 *)arg0 + 0x10) = page - 1;
            goto done;
        }
        arg1 = (u32)end;
        page++;
        i++;
    }
done:
    **(s32 **)((u8 *)arg0 + 0x30) = page - 1;
    *arg3 = savedPos;
    *arg4 = (u32)end;
    return 0;
}

extern "C" s32 VFiPFFAT_TraceClustersChain(void *arg0, s32 arg1, s32 *arg2) {
    s32 result;
    switch (*(s32 *)((u8 *)arg0 + 0x1C)) {
    case 0:
        result = ((s32 (*)(void *, u16))fn_800AF5A0)(arg0, (u16)arg1);
        break;
    case 1:
        result = ((s32 (*)(void *, s32, s32 *))fn_800AFE14)(arg0, arg1, arg2);
        break;
    case 2:
        result = ((s32 (*)(void *, s32, s32 *))fn_800B0258)(arg0, arg1, arg2);
        break;
    default:
        *arg2 = -1;
        result = 0xF;
        break;
    }
    return result & ((-result | result) >> 31);
}

extern "C" s32 fn_800AF4F0(void *arg0, s32 arg1) {
    void *r5;

    r5 = *(void **)((u8 *)arg0 + 0x30);
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)arg0 = 1;
    if (r5 != 0) {
        *(s32 *)((u8 *)r5 + 8) = 0;
    }
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    return 0;
}

extern "C" s32 fn_800AF530(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    *(void **)((u8 *)arg0 + 0x30) = arg1;
    *(s32 *)((u8 *)arg0 + 0x34) = arg2;
    *(s32 *)((u8 *)arg0 + 8) = arg3;
    *(s32 *)arg0 = 1;
    if (arg1 != 0) {
        *(s32 *)((u8 *)arg1 + 8) = 0;
    }
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    return 0;
}

#pragma dont_inline on
extern "C" s32 fn_800AF574(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    return 0;
}
#pragma dont_inline reset

extern "C" s32 fn_800AF584(void *arg0) {
    s32 idx = *(s32 *)((char *)arg0 + 0x1C);
    return *(s32 *)((char *)lbl_802EEF40 + idx * 0x14 + 8);
}

#pragma use_lmw_stmw off
extern "C" s32 fn_800AF8EC(void *arg0, s32 arg1, u32 arg2, void *arg3) {
    extern s32 fn_800B5260(void *, void *, u32, u32, s32);
    extern s32 fn_800B5618(void *, void *, u32, u32, s32);
    s32 r9 = (arg1 + (arg1 >> 1)) & 0xFFFF;
    u32 value = (*(u32 *)((char *)arg0 + 0x28) + (r9 >> *(u8 *)((char *)arg0 + 0x20))) & 0xFFFF;
    u16 index = r9 & (*(u16 *)arg0 - 1);
    u32 nv;
    s32 result = 0;
    s32 oldResult = 0;
    u16 i;

    if (*(u32 *)((char *)arg3 + 0x18) != value) {
        for (i = 0; (s32)i < *(u8 *)((char *)arg0 + 0x22); i++) {
            s32 r = fn_800B5618(arg0, *(void **)((char *)arg3 + 8),
                *(u32 *)((char *)arg3 + 0x18) + (s32)i * *(s32 *)((char *)arg0 + 0xC),
                0, *(u16 *)arg0);
            if (r != 0 && oldResult == 0) oldResult = r;
        }
        result = fn_800B5260(arg0, *(void **)((char *)arg3 + 8), value, 0, *(u16 *)arg0);
        if (result != 0) return result;
        *(u32 *)((char *)arg3 + 0x18) = value;
    }
    if (arg1 & 1) {
        *(u8 *)((u8 *)*(s32 *)((char *)arg3 + 8) + index) =
            (*(u8 *)((u8 *)*(s32 *)((char *)arg3 + 8) + index) & 0xF) | ((arg2 & 0xF) << 4);
        if ((u32)index == (u32)*(u16 *)arg0 - 1) {
            for (i = 0; (s32)i < *(u8 *)((char *)arg0 + 0x22); i++) {
                s32 r = fn_800B5618(arg0, *(void **)((char *)arg3 + 8),
                    *(u32 *)((char *)arg3 + 0x18) + (s32)i * *(s32 *)((char *)arg0 + 0xC),
                    0, *(u16 *)arg0);
                if (r != 0 && oldResult == 0) oldResult = r;
            }
            nv = value + 1;
            result = fn_800B5260(arg0, *(void **)((char *)arg3 + 8), nv, 0, *(u16 *)arg0);
            if (result != 0) return result;
            *(u32 *)((char *)arg3 + 0x18) = nv;
            *(u8 *)*(s32 *)((char *)arg3 + 8) = (u8)(arg2 >> 4);
        } else {
            *(u8 *)((u8 *)*(s32 *)((char *)arg3 + 8) + index + 1) = (u8)(arg2 >> 4);
        }
    } else {
        *(u32 *)((char *)arg3 + 0x18) = index;
        *(u8 *)((u8 *)*(s32 *)((char *)arg3 + 8) + index) = (u8)arg2;
        if ((u32)index == (u32)*(u16 *)arg0 - 1) {
            for (i = 0; (s32)i < *(u8 *)((char *)arg0 + 0x22); i++) {
                s32 r = fn_800B5618(arg0, *(void **)((char *)arg3 + 8),
                    *(u32 *)((char *)arg3 + 0x18) + (s32)i * *(s32 *)((char *)arg0 + 0xC),
                    0, *(u16 *)arg0);
                if (r != 0 && oldResult == 0) oldResult = r;
            }
            nv = value + 1;
            result = fn_800B5260(arg0, *(void **)((char *)arg3 + 8), nv, 0, *(u16 *)arg0);
            if (result != 0) return result;
            *(u32 *)((char *)arg3 + 0x18) = nv;
            *(u8 *)*(s32 *)((char *)arg3 + 8) =
                (*(u8 *)*(s32 *)((char *)arg3 + 8) & 0xF0) | (u8)(arg2 >> 8);
        } else {
            *(u8 *)((u8 *)*(s32 *)((char *)arg3 + 8) + index + 1) =
                (*(u8 *)((u8 *)*(s32 *)((char *)arg3 + 8) + index + 1) & 0xF0) | (u8)(arg2 >> 8);
        }
    }
    if (result != 0) oldResult = result;
    return oldResult;
}

extern "C" s32 fn_800AFE14(void *arg0, s32 arg1, s32 *arg2) {
    u16 value;
    u32 index;
    u16 offset;
    s32 result;
    u32 retry = 1;
    s32 *output = arg2;
    void *object = arg0;
    u32 scaled = (u32)arg1 * 2;
    u16 flags = *(u16 *)((u8 *)object + 0x18);

    index = (u16)(*(u32 *)((u8 *)object + 0x28) +
                  (scaled >> *(u8 *)((u8 *)object + 0x20)));
    offset = (u16)(scaled & (*(u16 *)object - 1));
    if (flags & 0x80)
        retry = flags & 7;
loop:
    result = fn_800B5260(object, &value, index, offset, 2);
    if (result == 0x1000) {
        s32 (*callback)(void *) =
            *(s32 (**)(void *))((u8 *)object + 0x1FC0);
        if (callback != 0) {
            s32 callbackResult = callback(*(void **)((u8 *)object + 0x1F84));
            if (callbackResult == 0)
                goto retryCheck;
            if (callbackResult == 1 &&
                *(u8 *)((u8 *)object + 0x22) >= 2 &&
                retry < *(u8 *)((u8 *)object + 0x22)) {
                retry++;
                index += *(u32 *)((u8 *)object + 0xC);
                goto retryCheck;
            }
        }
    }
    if (result != 0) {
        *output = -1;
        return result;
    }
retryCheck:
    if (result == 0) {
        *output = ((value & 0xFF00) >> 8) | ((value & 0x00FF) << 8);
        return 0;
    }
    goto loop;
}

#pragma use_lmw_stmw reset
extern "C" s32 fn_800AFF28(void *arg0, s32 arg1, u16 arg2) {
    extern s32 fn_800B5618(void *, void *, u16, u16, s32);
    u16 sp8;
    u16 bits = *(u16 *)arg0;
    u32 offset = arg1 << 1;
    u8 shift = *((u8 *)arg0 + 0x20);
    u32 indexValue = *(u32 *)((u8 *)arg0 + 0x28) + (offset >> shift);
    u32 sectorValue = offset & (bits - 1);
    __sthbrx(arg2, &sp8, 0);
    u16 index = indexValue;
    u16 sector = sectorValue;
    u32 i = 0;
    s32 result = 0;
    while (i < *((u8 *)arg0 + 0x22)) {
        s32 status = fn_800B5618(arg0, &sp8, index, sector, 2);
        if (status != 0 && result == 0)
            result = status;
        i++;
        index = (u16)(index + *(u32 *)((u8 *)arg0 + 0xC));
    }
    return result;
}

extern "C" s32 fn_800B5260(void *, void *, u32, u32, s32);
extern "C" s32 fn_800B5618(void *, void *, u16, u16, s32);
extern "C" s32 fn_800AFFE0(void *arg0, s32 arg1, u16 arg2, void *arg3, s32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *ctx = (u8 *)arg3;
    u32 scaled = (u32)arg1 << 1;
    u16 block = (u16)(*(u32 *)(obj + 0x28) + (scaled >> obj[0x20]));
    u16 index = (u16)(scaled & (*(u16 *)obj - 1));
    s32 result = 0;
    u32 i;
    s32 saved = 0;
    volatile s32 *bufferHandle = (volatile s32 *)(ctx + 8);

    if (*(u32 *)(ctx + 0x18) != block) {
        for (i = 0; i < obj[0x22]; i++) {
            s32 r = fn_800B5618(arg0, (void *)*bufferHandle,
                *(u32 *)(ctx + 0x18) + i * *(u32 *)(obj + 0xC),
                0, *(u16 *)obj);
            if (r != 0 && saved == 0)
                saved = r;
        }
        *(u32 *)(ctx + 0x18) = block;
        result = fn_800B5260(arg0, (void *)*bufferHandle, block, 0, *(u16 *)obj);
    }
    *(u8 *)(*bufferHandle + index) = (u8)arg2;
    *(u8 *)(*bufferHandle + index + 1) = (u8)(arg2 >> 8);
    if (result != 0)
        saved = result;
    return saved;
}

extern "C" s32 fn_800B0258(void *arg0, s32 arg1, s32 *arg2) {
    u32 value;
    u32 index;
    u16 offset;
    s32 result;
    u32 retry = 1;
    s32 *output = arg2;
    void *object = arg0;
    u16 flags = *(u16 *)((u8 *)object + 0x18);
    u32 scaled = (u32)arg1 * 4;

    index = (u16)(*(u32 *)((u8 *)object + 0x28) +
                  (scaled >> *(u8 *)((u8 *)object + 0x20)));
    offset = (u16)(scaled & (*(u16 *)object - 1));
    if (flags & 0x80)
        retry = flags & 7;
loop:
    result = fn_800B5260(object, &value, index, offset, 4);
    if (result == 0x1000) {
        s32 (*callback)(void *) =
            *(s32 (**)(void *))((u8 *)object + 0x1FC0);
        if (callback != 0) {
            s32 callbackResult = callback(*(void **)((u8 *)object + 0x1F84));
            if (callbackResult == 0)
                goto retryCheck;
            if (callbackResult == 1 &&
                *(u8 *)((u8 *)object + 0x22) >= 2 &&
                retry < *(u8 *)((u8 *)object + 0x22)) {
                retry++;
                index += *(u32 *)((u8 *)object + 0xC);
                goto retryCheck;
            }
        }
    }
    if (result != 0) {
        *output = -1;
        return result;
    }
retryCheck:
    if (result == 0) {
        u32 upper = __rlwinm(value, 8, 8, 15);
        u32 lower = __rlwinm(value, 24, 16, 23);
        upper = __rlwimi(upper, value, 24, 0, 7);
        lower = __rlwimi(lower, value, 8, 24, 31);
        *output = (upper | lower) & 0x0FFFFFFF;
        return 0;
    }
    goto loop;
}

extern "C" s32 fn_800B037C(void *arg0, s32 arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u32 sp8;
    u32 scaled = (u32)arg1 << 2;
    u32 block = (u16)(*(u32 *)(obj + 0x28) + (scaled >> obj[0x20]));
    u16 index = (u16)(scaled & (*(u16 *)obj - 1));
    u16 i;
    s32 saved;
    s32 result = fn_800B5260(arg0, &sp8, block, index, 4);
    if (result != 0)
        return result;

    saved = 0;
    sp8 = ((sp8 << 8) & 0x00FF0000) | (sp8 << 24) |
        ((sp8 >> 8) & 0x0000FF00) | (sp8 >> 24);
    sp8 &= 0xF0000000;
    sp8 |= (u32)arg2;
    sp8 = ((sp8 << 8) & 0x00FF0000) | (sp8 << 24) |
        ((sp8 >> 8) & 0x0000FF00) | (sp8 >> 24);

    for (i = 0; i < obj[0x22]; i++) {
        result = fn_800B5618(arg0, &sp8, block, index, 4);
        if (result != 0 && saved == 0)
            saved = result;
        block += *(u32 *)(obj + 0xC);
    }
    return saved;
}

extern "C" s32 fn_800B0488(void *arg0, s32 arg1, u32 arg2, void *arg3, s32 arg4) {
    u8 *obj = (u8 *)arg0, *ctx = (u8 *)arg3;
    u32 bytes = (u32)arg1 << 2;
    u32 value = *(u32 *)(obj + 0x28) + (bytes >> obj[0x20]);
    u16 block = (u16)value;
    u32 offset = bytes & (*(u16 *)obj - 1);
    s32 result = 0, saved = 0;
    if (*(u32 *)(ctx + 0x18) != block) {
        u16 i;
        for (i = 0; i < obj[0x22]; i++) {
            s32 r = fn_800B5618(arg0, *(void **)(ctx + 8),
                (u16)(*(s32 *)(ctx + 0x18) + i * *(u32 *)(obj + 0xC)),
                0, *(u16 *)obj);
            if (r && !saved) saved = r;
        }
        result = fn_800B5260(arg0, *(void **)(ctx + 8), block, 0, *(u16 *)obj);
        if (result) return result;
        *(u32 *)(ctx + 0x18) = block;
    }
    u8 *buffer = (u8 *)*(u32 *)(ctx + 8);
    u32 data = *(u32 *)(buffer + offset);
    u32 swapped = (data << 8 & 0x00FF0000) | (data << 24) | (data >> 8 & 0x0000FF00) | (data >> 24);
    swapped = (swapped & 0xF0000000) | (arg2 & 0x0FFFFFFF);
    *(u32 *)(buffer + offset) = (swapped << 8 & 0x00FF0000) | (swapped << 24) | (swapped >> 8 & 0x0000FF00) | (swapped >> 24);
    if (result) saved = result;
    return saved;
}

void fn_800B5CB4(void);
extern "C" void fn_800B5CB4(void);
extern "C" void fn_800B0748(void);
void fn_800B0748(void) {
    fn_800B5CB4();
}

extern "C" s32 VFiPFFILE_Cursor_AdvanceToRead(void *arg0, s32 arg1, s32 arg2) {
    void *var_r9;
    u32 temp_r8;
    u32 temp_r10;
    s32 temp_r7;
    s32 var_r31 = 1;
    u16 temp_r5;
    void *var_r5;
    u32 temp_r6_2;
    void *temp_r6;
    if (arg0 == 0) var_r9 = 0;
    else var_r9 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x268);
    temp_r6 = M2C_FIELD(arg0, void **, 8);
    temp_r10 = M2C_FIELD(temp_r6, u32 *, 0x264);
    temp_r8 = M2C_FIELD(arg0, u16 *, 0x28);
    temp_r8 += arg1;
    temp_r7 = arg2 + (temp_r8 >> M2C_FIELD(var_r9, u8 *, 0x20));
    if ((u32)(M2C_FIELD(arg0, u32 *, 0x1C) + arg1) < temp_r10) {
        if ((M2C_FIELD(var_r9, u16 *, 0) - 1) & temp_r8) M2C_FIELD(arg0, s32 *, 0x20) = temp_r7;
        else M2C_FIELD(arg0, s32 *, 0x20) = -1;
        M2C_FIELD(arg0, u32 *, 0x1C) = M2C_FIELD(arg0, u32 *, 0x1C) + arg1;
    } else if ((s32)temp_r10 == 0) {
        M2C_FIELD(arg0, s32 *, 0x20) = -1;
        M2C_FIELD(arg0, u32 *, 0x1C) = 0;
        if (arg1 != 0) var_r31 = 0;
    } else {
        var_r31 = 0;
        M2C_FIELD(arg0, s32 *, 0x20) = -1;
        M2C_FIELD(arg0, u32 *, 0x1C) = M2C_FIELD(M2C_FIELD(arg0, void **, 8), u32 *, 0x264);
    }
    if (arg0 == 0) var_r5 = 0;
    else var_r5 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x268);
    temp_r6_2 = M2C_FIELD(arg0, u32 *, 0x1C);
    M2C_FIELD(arg0, u32 *, 0x24) = temp_r6_2 >> M2C_FIELD(var_r5, u8 *, 0x20);
    temp_r5 = M2C_FIELD(var_r5, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0x28) = temp_r6_2 & (temp_r5 - 1);
    VFiPFCLUSTER_UpdateLastAccessCluster(arg0, temp_r7);
    return var_r31;
}

extern "C" s32 fn_800B0C10(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    extern s32 fn_800AE620(void *, u32, s32, void *);
    extern s32 fn_800B5324(s32, s32, u16, u32, s32 *, s32);
    extern s32 VFiPFFILE_Cursor_AdvanceToRead(void *, s32, s32);
    s32 sp8, result, sector, length=arg2;
    void *file, *fat;
    u32 cursor, limit;
    *arg3=0;
    if(arg0==0) sector=0;
    else sector=*(s32*)((u8*)*(void**)((u8*)arg0+8)+0x268);
    if(arg2==0)return 0;
    file=*(void**)((u8*)arg0+8);cursor=*(u32*)((u8*)arg0+0x1c);limit=*(u32*)((u8*)file+0x264);
    if(cursor+(u32)arg2>limit){length=limit-cursor;if(length==0)return 0;}
    if(*(u32*)((u8*)arg0+0x20)==0xFFFFFFFF){
        result=fn_800AE620((u8*)file+4,*(u32*)((u8*)arg0+0x24),0,(u8*)arg0+0x20);
        if(result!=0)return result;
        if(*(u32*)((u8*)arg0+0x20)==0xFFFFFFFF){
            *(u32*)((u8*)arg0+0x1c)=*(u32*)((u8*)file+0x264);
            fat=arg0==0?0:*(void**)((u8*)file+0x268);cursor=*(u32*)((u8*)arg0+0x1c);
            *(u32*)((u8*)arg0+0x24)=cursor>>*((u8*)fat+0x20);*(u16*)((u8*)arg0+0x28)=cursor&(*(u16*)fat-1);return 0x1c;
        }
        limit=*(u32*)((u8*)file+0x264);cursor=*(u32*)((u8*)arg0+0x1c);
        if(cursor+(u32)length>limit){
            *(u32*)((u8*)arg0+0x1c)=limit;fat=arg0==0?0:*(void**)((u8*)file+0x268);cursor=*(u32*)((u8*)arg0+0x1c);
            *(u32*)((u8*)arg0+0x24)=cursor>>*((u8*)fat+0x20);*(u16*)((u8*)arg0+0x28)=cursor&(*(u16*)fat-1);return 0x1b;
        }
    }
    result=fn_800B5324(sector,arg1,*(u16*)((u8*)arg0+0x28),length,&sp8,1);
    if(result!=0&&sp8==0)return result;
    *arg3=sp8;VFiPFFILE_Cursor_AdvanceToRead(arg0,sp8,*(s32*)((u8*)arg0+0x20));
    if((u32)sp8!=(u32)length)return result;
    return 0;
}

extern s32 fn_800B0868(void *, s32, u32, u32 *);
extern s32 fn_800B0A60(void *, s32, u32, u32 *);
extern s32 fn_800B0C10(void *, s32, u32, u32 *);
extern "C" s32 fn_800B0DEC(void *arg0, s32 arg1, u32 arg2, s32 *arg3, s32 arg4) {
    /* Fix note: perform the first large read unconditionally; check the cluster threshold only after it. */
    u32 sp8;
    u16 *var_r27;
    u32 var_r30;
    s32 result;
    void *temp_r7;

    temp_r7 = *(void **)((u8 *)arg0 + 8);
    *(void **)((u8 *)temp_r7 + 0x34) = (u8 *)arg0 + 0xC;
    *arg3 = 0;
    result = fn_800B0868(arg0, arg1, arg2, &sp8);
    *arg3 += sp8;
    if (result != 0)
        return result;
    if (sp8 >= arg2)
        return 0;

    var_r30 = arg2 - sp8;
    if (arg0 == 0)
        var_r27 = 0;
    else
        var_r27 = *(u16 **)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x268);

    for (;;) {
        result = fn_800B0A60(arg0, arg1 + *arg3, var_r30, &sp8);
        *arg3 += sp8;
        if (result != 0)
            return result;
        if (sp8 == 0)
            break;
        var_r30 -= sp8;
        if (var_r30 < *var_r27)
            break;
    }

    result = fn_800B0C10(arg0, arg1 + *arg3, var_r30, &sp8);
    *arg3 += sp8;
    return result;
}

extern "C" void *fn_800B0F1C(void *arg0, void *arg1, s32 arg2) {
    u8 *base=(u8*)arg0,*entry=base,*chosen=0; s32 chosenIndex=0,i;
    for(i=0;i<5;i++){
        u32 flags=*(u32*)(entry+0x40);
        if((flags&1)==0 || (flags&0x40000000)==0){if(!chosen){chosen=entry+0x40;chosenIndex=i;}}
        else if(*(u32*)((u8*)arg1+0x22C)==*(u32*)(entry+0x2A8)&&*(u32*)((u8*)arg1+0x238)==*(u32*)(entry+0x2B4)&&*(u16*)((u8*)arg1+0x23C)==*(u16*)(entry+0x2B8)) return base+i*0x29C+0x40;
        entry+=0x29C;
    }
    if(!chosen)return 0;
    *(u32*)chosen=3; *(u16*)(chosen+0x298)=0;
    {u32 *src=(u32*)((u8*)arg1-4),*dst=(u32*)(chosen+0x38); for(i=0;i<0x48;i++){*++dst=*++src;}}
    *(u16*)(chosen+0x27C)=0; *(u16*)(chosen+0x27E)=0; *(u32*)(chosen+0x280)=0; *(u32*)(chosen+0x284)=0; *(u32*)(chosen+0x288)=0;
    fn_800AF530(chosen+4,0,*(u32*)((u8*)arg1+0x22C),(s32)(chosen+0x270));
    if(*(u16*)(base+0x1FB0)&1){
        u32 count=*(u32*)(base+0x1FB8);
        *(u32*)(chosen+0x20)=*(u32*)(base+0x1FB4)+chosenIndex*count*4;
        fn_800A499C((const char*)*(u32*)(chosen+0x20),0,(s32)(count*4));
        *(u32*)(chosen+0x2C)=count; *(u16*)(chosen+0x24)=*(u16*)(base+0x1FB2); *(u16*)(chosen+0x26)=0; *(u32*)(chosen+0x28)=0; *(u32*)(chosen+0x30)=0;
        if(*(u32*)((u8*)arg1+0x228)!=0&&*(u32*)(chosen+0x2C)!=0){**(u32**)(chosen+0x20)=*(u32*)((u8*)arg1+0x234); (*(u32*)(chosen+0x28))++;}
    }
    return chosen;
}

extern "C" s32 VFiPFPATH_parseShortName(void *, void *);

extern "C" s32 fn_800B51FC(void *, s32);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_800B10E0(void *arg0, void *arg1, void *arg2, s32 arg3) {
    VFiPFEntryLocalFrame frame;
    s32 charCount;
    s32 result;
    s32 parsed;
    s32 quotient;
    s32 remainder;
    u8 initialCount;
    u8 loopCount;
    u8 checksum;
    u8 *nextCluster;
    s32 cluster;
    u16 next;
    u32 *flags;

    frame.copied = *(VFiPFEntryCopy240 *)arg1;
    charCount = (u16)VFiPFSTR_StrNumChar((s32)arg2, 1);
    if ((u32)charCount + *(u32 *)((u8 *)&frame.copied + 0x230) > 0x103U) {
        return 1;
    }
    if ((s32)charCount > 0xFF) {
        return 1;
    }
    ((s32 (*)(void *, void *, s32, s32))fn_800AF530)(frame.prefix + 0x40, frame.prefix + 0x10, *(s32 *)((u8 *)&frame.copied + 0x22C), (s32)((u8 *)&frame.copied + 0x234));
    if (*(s32 *)((u8 *)arg0 + 0x161C) >= 5) {
        return 0x15;
    }
    parsed = VFiPFPATH_parseShortName((u8 *)arg1 + 0x20E, arg2);
    if (parsed != 0 && (s8)*((u8 *)arg1 + 0x20E) == 0) {
        return 1;
    }
    if (parsed != 0) {
        result = VFiPFENT_AdjustSFN(&frame.copied, (s8 *)((u8 *)arg1 + 0x20E));
        if (result != 0) {
            return result;
        }
        if ((u32)fn_800A4D44(arg2) == 1U) {
            ((s32 (*)(void *, s32))VFiPFPATH_transformInUnicode)(arg1, fn_800A4D74(arg2, 1));
        } else {
            ((void (*)(void *, void *))fn_800A4B78)(arg1, (void *)(u32)fn_800A4D74((void *)arg2, 1));
        }
    } else {
        *(u16 *)arg1 = 0;
    }
    if (*(s32 *)((u8 *)arg0 + 0x1C) == 2) {
        ((VFiPFEntryFlag234 *)arg1)->flag = 1;
    } else {
        ((VFiPFEntryFlag234 *)arg1)->flag = 0;
    }
    *(s32 *)((u8 *)arg1 + 0x228) = 0;
    *(void **)((u8 *)arg1 + 0x22C) = arg0;
    *((u8 *)arg1 + 0x21B) = 0;
    *((u8 *)arg1 + 0x21C) = 0x20;
    *((u8 *)arg1 + 0x21D) = fn_800AB2F4((u8 *)arg1 + 0x220, (u8 *)arg1 + 0x21E, 0);
    *(u16 *)((u8 *)arg1 + 0x222) = *(u16 *)((u8 *)arg1 + 0x220);
    *(u16 *)((u8 *)arg1 + 0x224) = *(u16 *)((u8 *)arg1 + 0x21E);
    *(u16 *)((u8 *)arg1 + 0x226) = *(u16 *)((u8 *)arg1 + 0x220);

    if (*(u16 *)arg1 != 0 && (*((u8 *)arg1 + 0x21B) & 0x18) == 0) {
        quotient = (s32)charCount / 13;
        remainder = (s32)charCount % 13;
        initialCount = (u8)(quotient + (remainder != 0));
        result = ((s32 (*)(void *, u8, void *, s32 *, s32, s32 *, u32, u32))fn_800AAC08)(
            arg1, (u8)(initialCount + 1), frame.prefix + 0x40, (s32 *)(frame.prefix + 8), (s32)arg2,
            (s32 *)frame.prefix, quotient, (u32)quotient >> 31);
        if (result != 0) {
            return result;
        }
        flags = (u32 *)lbl_803D2140;
        if ((flags[0x60 / 4] & 2) == 2) {
            fn_800B51FC((u8 *)arg1 + 0x20E, *(s32 *)frame.prefix);
        }
        *((u8 *)arg1 + 0x20A) = initialCount;
        cluster = *(s32 *)((u8 *)arg1 + 0x238);
        checksum = ((u8 (*)(u8 *))VFiPFENT_CalcCheckSum)((u8 *)arg1);
        nextCluster = frame.prefix + 8;
        loopCount = initialCount;
        while (loopCount >= 1) {
            VFiPFENT_storeLFNEntryFieldsToBuf(frame.prefix + 0x20, (u8 *)arg1, loopCount, checksum, loopCount == initialCount);
            result = ((s32 (*)(s32, void *, s32, u16, u32, u32 *, u32))fn_800B5700)(
                (s32)arg0, frame.prefix + 0x20, cluster, *(u16 *)((u8 *)arg1 + 0x23C), 0x20,
                (u32 *)(frame.prefix + 4), 0);
            if (result != 0) {
                return result;
            }
            if (*(u32 *)(frame.prefix + 4) != 0x20U) {
                return 0x11;
            }
            next = *(u16 *)((u8 *)arg1 + 0x23C) + 0x20;
            *(u16 *)((u8 *)arg1 + 0x23C) = next;
            if (next >= *(u16 *)arg0) {
                *(u16 *)((u8 *)arg1 + 0x23C) = 0;
                cluster = *(s32 *)nextCluster;
                nextCluster += 4;
            }
            loopCount--;
        }
        *(s32 *)((u8 *)arg1 + 0x238) = cluster;
    } else {
        result = ((s32 (*)(void *, u32, void *, s32 *, s32))fn_800AAED8)(
            arg1, 1, frame.prefix + 0x40, (s32 *)(frame.prefix + 8), (s32)arg2);
        if (result != 0) {
            return result;
        }
    }
    if (((VFiPFEntryFlag234 *)arg1)->flag == 1) {
        ((VFiPFEntryFlag234 *)arg1)->flag = 0;
    }
    return fn_800AB0C0((u8 *)arg1, 1);
}

extern "C" void fn_800B36C4(s32, s32, s32);
extern "C" s32 fn_800B143C(void *arg0, s32 arg1, s32 arg2, void **arg3) {
    struct LocalFrame {
        u32 value8; u32 valueC; u8 pad10[8];
        u8 path18[0x10]; u8 path28[0x10]; u8 pad38[0x38];
        u8 temp70[0x70]; u8 unicodeE0[0x200]; u8 main2e0[0x21C];
        u8 flags4FC; u8 pad4FD[5]; u16 name502; u16 name504; u16 name506;
        u32 record508; void *context50C; u32 pad510; u32 output514;
        u32 value518; u16 value51C;
    } f;
    s32 status;
    s32 i;
    u8 *entry;
    u32 address;
    void *opened;
    void *base;
    u8 *slot;
    void *object;

    *arg3 = 0;
    status = ((s32 (*)(s32, s32, s32))fn_800B36C4)(arg1, (s32)f.path18, (s32)f.path28);
    if (status != 0)
        return 1;
    status = ((s32 (*)(s32, s32, s32, s32, s32))fn_800ACA44)(
        (s32)f.temp70, (s32)f.main2e0, (s32)arg0, arg1, 1);
    if (status != 0)
        return status;
    if ((f.flags4FC & 0x10) == 0)
        return 1;
    {
        u32 pathType = (u32)fn_800A4D44(f.path28);
        if (pathType == 2U) {
            s32 charCount = (u16)VFiPFSTR_StrNumChar((s32)f.path28, 1);
            if (charCount > 0xFF)
                return 1;
            VFiPFPATH_transformFromUnicodeToNormal((u16 *)f.unicodeE0,
                (u16 *)fn_800A4D74(f.path28, 1));
        }
    }
    fn_800A4D4C(f.path28, f.unicodeE0);

    if ((arg2 & 2) != 0) {
        ((s32 (*)(void *, void *, s32, s32))fn_800AF530)(f.pad38, &f.valueC, (s32)f.context50C, (s32)&f.output514);
        status = ((s32 (*)(void *, void *, s32, void *, s32, s32))fn_800AABE0)(
            f.pad38, f.main2e0, 0, f.path28, 0x7F, 0);
        if (status != 0)
            return 3;
        if ((arg2 & 8) && (f.flags4FC & 1))
            return 10;
        if (f.flags4FC & 0x10)
            return 0x17;
        ((void (*)(u16 *, u32 *))fn_800AB2F4)(&f.name502, &f.value8);
    } else {
        status = ((s32 (*)(s32, void *, void *))fn_800B10E0)((s32)arg0, f.main2e0, f.path28);
        if (status == 8) {
            if (arg2 & 0x10)
                return 8;
            register u8 *scan;
            register u32 compareValue;
            register u16 compareName;
            register void *context;
            register u32 flags;
            s32 option;
            option = arg2 & 1;
            if (option) {
                s32 found;
                context = f.context50C;
                compareValue = f.value518;
                scan = (u8 *)context + 0x40;
                compareName = f.value51C;
                for (i = 0; i < 5; i++, scan += 0x29C) {
                    flags = *(u32 *)scan;
                    if ((flags & 1) && (flags & 2) &&
                        context == *(void **)(scan + 0x268) &&
                        compareValue == *(u32 *)(scan + 0x274) &&
                        compareName == *(u16 *)(scan + 0x278)) {
                        found = 1;
                        goto scan_complete;
                    }
                }
                found = 0;
            scan_complete:
                if (found)
                    return 8;
            }
            if ((f.flags4FC & 1) == 0)
                goto after_create_flag;
            if (option != 0)
                goto check_create_flag;
            if (arg2 & 4)
                goto check_create_flag;
            if (arg2 & 8)
                return 10;
        check_create_flag:
        after_create_flag:
            if (f.flags4FC & 0x10)
                return 0x17;
            if (option) {
                if (f.output514 >= 2 && f.output514 + 0x10000 != 0xFFFF && f.record508 != 0)
                    ((s32 (*)(void *, u32, s32, u32))fn_800AE7A8)(f.temp70 + 8, f.output514, -1, f.record508);
                f.output514 = 0;
                f.record508 = 0;
                ((void (*)(u16 *, u16 *))fn_800AB2F4)(&f.name506, &f.name504);
                f.name502 = f.name506;
            } else {
                ((void (*)(u16 *, u32 *))fn_800AB2F4)(&f.name502, &f.value8);
            }
        } else if (status != 0) {
            return status;
        }
    }

    arg0 = f.context50C;
    opened = ((void *(*)(void *, void *))fn_800B0F1C)(arg0, f.main2e0);
    if (opened == 0)
        return 0x15;
    entry = (u8 *)arg0;
    for (i = 0; i < 5; entry += 0x30, i++) {
        if ((*(u32 *)(entry + 0xD4C) & 1) == 0) {
            address = (u32)arg0 + i * 0x30;
            slot = (u8 *)(address + 0xD4C);
            goto slot_found;
        }
    }
    slot = 0;
slot_found:
    if (slot == 0)
        return 0x16;
    *(void * volatile *)(slot + 8) = opened;
    *(s32 *)(slot + 0) = 1;
    *(s32 *)(slot + 4) = arg2;
    *(s32 *)(slot + 0x18) = 0;
    *(u16 *)(slot + 0x2C) = 0;
    ((void (*)(void *))fn_800AF2B8)(slot + 0xC);
    *(s32 *)(slot + 0x20) = -1;
    *(s32 *)(slot + 0x1C) = 0;
    if (slot == 0) {
        object = 0;
    } else {
        object = *(void * volatile *)(slot + 8);
        object = *(void **)((u8 *)object + 0x268);
    }
    *(u32 *)(slot + 0x24) = (u32)(*(u32 *)(slot + 0x1C) >> *(u8 *)((u8 *)object + 0x20));
    *(u16 *)(slot + 0x28) = (u16)(*(u32 *)(slot + 0x1C) & (*(u16 *)object - 1));
    if (arg2 & 1)
        *(u32 *)(*(void **)(slot + 8)) |= 4;
    if (*(s32 *)(slot + 4) & 4) {
        object = *(void **)(slot + 8);
        *(u32 *)(slot + 0x1C) = *(u32 *)((u8 *)object + 0x264);
        if (slot == 0)
            object = 0;
        else
            object = *(void **)((u8 *)*(void * volatile *)(slot + 8) + 0x268);
        *(u32 *)(slot + 0x24) = *(volatile u32 *)(slot + 0x1C) >> *(u8 *)((u8 *)object + 0x20);
        *(u16 *)(slot + 0x28) = (u16)(*(volatile u32 *)(slot + 0x1C) & (*(u16 *)object - 1));
    }
    ++*(u16 *)((u8 *)opened + 0x298);
    *arg3 = slot;
    return 0;
}

#pragma pop

extern "C" s32 fn_800B0DEC(void *, s32, u32, s32 *, s32);
extern "C" s32 VFiPFFILE_p_fread(void *, void *arg1, u32 arg2, u32 arg3, void *arg4, u32 *arg5) {
    u32 bytesRead = 0;
    *arg5 = 0;
    s32 mode = *(s32 *)((u8 *)arg4 + 4);
    if (!(mode & 8) && ((mode & 1) || (mode & 4))) return 0xA;
    if ((*(u16 *)((u8 *)*(void **)((u8 *)arg4 + 8) + 0x27c) & 3) &&
        *(u16 *)((u8 *)arg4 + 0x2c) == 0) return 0x19;
    if (*(u32 *)((u8 *)arg4 + 0x1c) >= *(u32 *)((u8 *)*(void **)((u8 *)arg4 + 8) + 0x264)) return 0x1c;
    s32 result = ((s32 (*)(void *, s32, u32, s32 *, s32))fn_800B0DEC)(
        arg4, (s32)arg1, arg2 * arg3, (s32 *)&bytesRead, (s32)arg4);
    s32 ret = result & ((-result | result) >> 31);
    *arg5 = bytesRead / arg2;
    return ret;
}

extern "C" s32 fn_800A9470(void *,void *);
extern "C" s32 VFiPFFILE_p_finfo(void *arg0, void *arg1) {
    register s32 temp_r3, temp_r5;
    register u32 size;
    register void *file;
    *(void **)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x34) = (u8 *)arg0 + 0xC;
    if (arg0 == 0) file = 0;
    else file = *(void **)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x268);
    *(s32 *)arg1 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x264);
    *(s32 *)((u8 *)arg1 + 4) = *(s32 *)((u8 *)arg0 + 0x1C);
    size = *(u16 *)file << *((u8 *)file + 0x21);
    if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x270) != 0) {
        temp_r3 = fn_800A9470(arg0, (u8 *)arg1 + 0xC);
        if (temp_r3 != 0) return temp_r3;
        temp_r5 = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x264) % size;
        *(s32 *)((u8 *)arg1 + 8) = ((volatile u32 *)arg1)[3] + ((size - temp_r5) & ((-temp_r5 | temp_r5) >> 31));
    } else {
        *(s32 *)((u8 *)arg1 + 0xC) = 0;
        *(s32 *)((u8 *)arg1 + 8) = 0;
    }
    *(s32 *)((u8 *)arg1 + 0x10) = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x27C) & 3;
    *(s32 *)((u8 *)arg1 + 0x14) = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x284);
    *(s32 *)((u8 *)arg1 + 0x18) = *(u16 *)((u8 *)arg0 + 0x2C);
    *(s32 *)((u8 *)arg1 + 0x1C) = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x27E);
    return 0;
}

extern "C" void VFiPFFILE_FinalizeAllFiles(u8 *arg0) {
    extern s32 fn_800AF574(void *);
    u16 i;
    for (i = 0; i < 5; i++) {
        u8 *file = arg0 + i * 0x29C;
        *(s32 *)(file + 0x40) = 0;
        fn_800AF574(file + 0x44);
    }
    *(u32 *)(arg0 + 0xD4C) &= ~1U;
    *(u32 *)(arg0 + 0xD7C) &= ~1U;
    *(u32 *)(arg0 + 0xDAC) &= ~1U;
    *(u32 *)(arg0 + 0xDDC) &= ~1U;
    *(u32 *)(arg0 + 0xE0C) &= ~1U;
    *(s32 *)(arg0 + 0x161C) = 0;
}

extern "C" s32 fn_800B1AFC(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    void *context;
    s32 result;

    *arg2 = 0;
    context = ((void *(*)(void))fn_800B36D4)();
    fn_800B77C0((u8 *)context + 0x1F90);
    result = fn_800B6004(context);

    if (result != 0 && (result != 0xB || arg1 != 2)) {
        fn_800B783C((u8 *)context + 0x1F90);
        lbl_803D2140[16] = result;
        *(s32 *)((u8 *)context + 0x1F80) = result;
    } else {
        result = fn_800B143C(context, arg0, arg1, (void **)arg2);
        if (result != 0) {
            lbl_803D2140[16] = result;
            *(s32 *)((u8 *)context + 0x1F80) = result;
        } else {
            ++*(s32 *)((u8 *)context + 0x161C);
        }
    }

    fn_800B783C((u8 *)context + 0x1F90);
    return result;
}

extern "C" s32 fn_800B6004(void *);
extern "C" void fn_800B786C(void *);
extern "C" void *fn_800B1BDC(void *arg0) {
    u8 *volume;
    s32 result = 0;
    s32 temp_r3;
    u16 count;

    if (arg0 == 0) {
        volume = 0;
    } else {
        volume = *(u8 **)((*(u8 **)((u8 *)arg0 + 8)) + 0x268);
    }

    fn_800B77C0(volume + 0x1F90);
    temp_r3 = fn_800B6004(volume);
    if (temp_r3 != 0 && (temp_r3 != 0xB || *(s32 *)((u8 *)arg0 + 4) != 2)) {
        fn_800B783C(volume + 0x1F90);
        *(s32 *)((u8 *)lbl_803D2140 + 0x40) = temp_r3;
        *(s32 *)(volume + 0x1F80) = temp_r3;
        return (void *)temp_r3;
    }

    if ((*(u32 *)(*(u8 **)((u8 *)arg0 + 8)) & 1) == 0 ||
        (*(u32 *)(*(u8 **)((u8 *)arg0 + 8)) & 2) == 0) {
        fn_800B783C(volume + 0x1F90);
        *(s32 *)((u8 *)lbl_803D2140 + 0x40) = 0xA;
        *(s32 *)(volume + 0x1F80) = 0xA;
        return (void *)0xA;
    }

    *(void **)(volume + 0x1644) = arg0;
    if (((s32)*(u16 *)(*(u8 **)((u8 *)arg0 + 8) + 0x298) - 1) > 0) goto after_poll;
    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 8) + 0x258) & 0x19) goto after_poll;
    if (temp_r3 & 0xB) goto after_poll;
    if ((*(u32 *)(*(u8 **)((u8 *)arg0 + 8)) & 4) == 0 &&
        (*(u32 *)(volume + 0x1F88) & 1) == 1) goto after_poll;
    result = fn_800AB0C0(*(u8 **)((u8 *)arg0 + 8) + 0x3C, 1);

after_poll:
    count = *(u16 *)((u8 *)arg0 + 0x2C);
    if (count != 0) {
        u8 *device = *(u8 **)((u8 *)arg0 + 8);
        if ((*(u16 *)(device + 0x27C) & 1) != 0) {
            *(u16 *)(device + 0x27E) = *(u16 *)(device + 0x27E) - count;
            *(u16 *)((u8 *)arg0 + 0x2C) = 0;
            if (*(u16 *)(*(u8 **)((u8 *)arg0 + 8) + 0x27E) == 0) {
                fn_800B786C(arg0);
            }
            *(u16 *)(*(u8 **)((u8 *)arg0 + 8) + 0x27C) &= 0xFFFC;
        } else if (*(void **)(device + 0x284) != arg0) {
            result = 0x19;
        } else {
            *(u16 *)(device + 0x27E) = 0;
            *(u16 *)((u8 *)arg0 + 0x2C) = 0;
            *(void **)(*(u8 **)((u8 *)arg0 + 8) + 0x284) = 0;
            fn_800B786C(arg0);
            *(u16 *)(*(u8 **)((u8 *)arg0 + 8) + 0x27C) &= 0xFFFC;
        }
    }

    if (result != 0) {
        *(s32 *)((u8 *)lbl_803D2140 + 0x40) = result;
        *(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 8) + 0x38) + 0x1F80) = result;
        *(s32 *)((u8 *)arg0 + 0x18) = result;
    } else {
        if (*(u32 *)(volume + 0x1624) & 2) {
            result = ((s32 (*)(void *))fn_800A9104)(volume);
            if (result != 0) {
                *(s32 *)((u8 *)lbl_803D2140 + 0x40) = result;
                *(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 8) + 0x38) + 0x1F80) = result;
                *(s32 *)((u8 *)arg0 + 0x18) = result;
            } else {
                result = ((s32 (*)(void *, u32))fn_800A9138)(volume, (u32)arg0);
                if (result != 0) {
                    *(s32 *)((u8 *)lbl_803D2140 + 0x40) = result;
                    *(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 8) + 0x38) + 0x1F80) = result;
                    *(s32 *)((u8 *)arg0 + 0x18) = result;
                }
            }
        }
        if (result == 0) {
            u8 *device = *(u8 **)((u8 *)arg0 + 8);
            count = *(u16 *)(device + 0x298);
            count--;
            *(u16 *)(device + 0x298) = count;
            if (count == 0) {
                *(u32 *)(*(u8 **)((u8 *)arg0 + 8)) &= ~1U;
                *(s32 *)(*(u8 **)((u8 *)arg0 + 8) + 0x20) = 0;
            }
            *(u32 *)arg0 &= ~1U;
            --*(s32 *)(volume + 0x161C);
        }
    }

    {
        u8 *lock = volume + 0x1F90;
        *(s32 *)(volume + 0x1644) = 0;
        fn_800B783C(lock);
    }
    return (void *)result;
}

s32 fn_800B1EB8(void *arg0, void *arg1, u32 arg2, u32 arg3, void *arg4, u32 *arg5) {
    u32 bytesRead;
    s32 result;
    s32 temp;
    void *file;
    void *fs;
    s32 flags;

    *arg5 = 0;
    file = arg4 == 0 ? 0 : *(void **)((u8 *)*(void **)((u8 *)arg4 + 8) + 0x268);
    fn_800B77C0((u8 *)file + 0x1F90);
    result = fn_800B5E14(file);
    if (result != 0) {
        fn_800B783C((u8 *)file + 0x1F90);
        lbl_803D2140[16] = result;
        *(s32 *)((u8 *)file + 0x1F80) = result;
        return result;
    }
    fs = *(void **)((u8 *)arg4 + 8);
    flags = *(s32 *)fs;
    if ((flags & 1) != 0 && (flags & 2) != 0) {
        fn_800B783C((u8 *)file + 0x1F90);
        lbl_803D2140[16] = 0x26;
        *(s32 *)((u8 *)file + 0x1F80) = 0x26;
        return 0x26;
    }
    *(void **)((u8 *)file + 0x1644) = arg4;
    result = VFiPFFILE_p_fread(file, arg0, arg2, arg3, arg4, &bytesRead);
    temp = result;
    *arg5 = bytesRead;
    *(s32 *)((u8 *)file + 0x1644) = 0;
    if (result != 0) {
        lbl_803D2140[16] = result;
        fs = *(void **)((u8 *)arg4 + 8);
        fs = *(void **)((u8 *)fs + 0x38);
        *(s32 *)((u8 *)fs + 0x1F80) = result;
        *(s32 *)((u8 *)arg4 + 0x18) = result;
    }
    fn_800B783C((u8 *)file + 0x1F90);
    return temp;
}

extern "C" u8 lbl_802EEEE0[];
u16 fn_800B25CC(void *arg0, s32 arg1) {
    u8 work[0x14];
    s32 var_r0;
    u16 var_r3;
    u32 var_r3_2;
    u32 var_r3_3;
    u32 var_r3_4;
    u8 *temp_r3;
    u8 *temp_r5;
    u8 temp_r0;
    u8 temp_r4;

    if ((u32) M2C_FIELD(arg0, u32 *, 0xC) == 1U) {
        temp_r5 = M2C_FIELD(arg0, u8 **, 0);
        M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_r5 + 1);
        temp_r4 = *temp_r5;
        work[8] = temp_r4;
        work[9] = 0;
        if (((s8) temp_r4 == 0) || ((u8 *)M2C_FIELD(arg0, u32 *, 4) < M2C_FIELD(arg0, u8 **, 0))) {
            return 0U;
        }
        if (M2C_FIELD(&lbl_803D2140, s32 (**)(s8, s32), 0x54)((s8) temp_r4, 1) != 0) {
            temp_r3 = M2C_FIELD(arg0, u8 **, 0);
            temp_r0 = *temp_r3;
            work[9] = temp_r0;
            M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_r3 + 1);
            (*(u16 *)(work + 4)) = (work[8] << 8) + work[9];
        } else if ((M2C_FIELD(&lbl_803D2140, s32 *, 0x38) & 0x10000) || (work[8] >= 0x80U) || ((work[8] >= 0x20U) && (M2C_FIELD((u32)work[8] + (u32)lbl_802EEEE0, u8 *, -0x20) & 2))) {
            (*(u16 *)(work + 4)) = (u16) (s8) work[8];
        } else {
            (*(u16 *)(work + 4)) = 0x5F;
        }
        if (arg1 != 0) {
            M2C_FIELD(&lbl_803D2140, s32 (**)(u8 *, u16 *, s32 *), 0x48)((u8 *)&work[8], &(*(u16 *)(work + 4)), (s32 *)lbl_803D2140);
        }
        goto block_27;
    }
    work[8] = (u8) (u16) *M2C_FIELD(arg0, u16 **, 0);
    work[9] = (u8) ((s32) (u16) *M2C_FIELD(arg0, u16 **, 0) >> 8);
    M2C_FIELD(arg0, u16 **, 0) = M2C_FIELD(arg0, u16 **, 0) + 1;
    work[10] = 0;
    if ((((s8) work[8] == 0) && ((s8) work[9] == 0)) || ((u8 *)M2C_FIELD(arg0, u32 *, 4) < M2C_FIELD(arg0, u8 **, 0))) {
        return 0U;
    }
    (*(u16 *)(work + 4)) = (work[9] << 8) + work[8];
    if (arg1 == 0) {
        M2C_FIELD(&lbl_803D2140, s32 (**)(u16 *, u16 *), 0x4C)(&(*(u16 *)(work + 4)), &(*(u16 *)(work + 2)));
        if (M2C_FIELD(&lbl_803D2140, s32 (**)(s8, s32), 0x54)((s8) ((s32) (*(u16 *)(work + 2)) >> 8), 1) != 0) {
            (*(u16 *)(work + 4)) = (*(u16 *)(work + 2));
        } else if ((M2C_FIELD(&lbl_803D2140, s32 *, 0x38) & 0x10000) || (work[8] >= 0x80U) || ((work[8] >= 0x20U) && (M2C_FIELD((u32)work[8] + (u32)lbl_802EEEE0, u8 *, -0x20) & 2))) {
            (*(u16 *)(work + 4)) = (u16) (s8) work[8];
        } else {
            (*(u16 *)(work + 4)) = 0x5F;
        }
    }
block_27:
    var_r3 = (*(u16 *)(work + 4));
    var_r0 = 0;
    if ((var_r3 >= 0x61U) && (var_r3 <= 0x7AU)) {
        var_r0 = 1;
    }
    if (var_r0 != 0) {
        var_r3 -= 0x20;
    }
    (*(u16 *)(work + 4)) = var_r3;
    if (arg1 != 0) {
        if ((var_r3 >= 0xFF41U) && (var_r3 <= 0xFF5AU)) {
            var_r3_2 = 1U;
            (*(u16 *)work) = var_r3 - 0x20;
        } else {
            var_r3_2 = 0U;
        }
        if (var_r3_2 == 1U) {
            (*(u16 *)(work + 4)) = (*(u16 *)work);
        }
    } else {
        M2C_FIELD(&lbl_803D2140, s32 (**)(u8 *, u16 *, s32 *), 0x48)((u8 *) &(*(u16 *)(work + 4)), &(*(u16 *)work), (s32 *)lbl_803D2140);
        if (((*(u16 *)work) >= 0xFF41U) && ((*(u16 *)work) <= 0xFF5AU)) {
            var_r3_3 = 1U;
            (*(u16 *)work) -= 0x20;
        } else {
            var_r3_3 = 0U;
        }
        if (var_r3_3 == 1U) {
            M2C_FIELD(&lbl_803D2140, s32 (**)(u16 *, u16 *), 0x4C)(&(*(u16 *)work), &(*(u16 *)work));
            var_r3_4 = 1U;
        } else {
            var_r3_4 = 0U;
        }
        if (var_r3_4 == 1U) {
            (*(u16 *)(work + 4)) = (*(u16 *)work);
        }
    }
    return (*(u16 *)(work + 4));
}

extern "C" s32 VFiPFPATH_cmpNameImpl(u8 *arg0, u8 *arg1, s32 *arg2) {
    u16 spA, sp8;
    s32 temp_r23, temp_r3, temp_r3_2, temp_r3_3, temp_r3_4;
    s32 var_r31;
    u16 var_r29, var_r30, var_r3, var_r3_2, var_r3_7, var_r3_8, var_r3_9;
    u32 var_r3_3, var_r3_4, var_r3_5, var_r3_6;
    u8 *var_r27 = arg1;
    u8 *var_r26 = arg0;
    u8 *table = (u8 *)lbl_803D2140;
    s32 *var_r28 = arg2;
    s32 one = 1;
loop_64:
    if ((s8)*var_r27 == 0) return (s8)*var_r26 != 0;
    temp_r23 = M2C_FIELD(table, s32 (**)(u8 *), 0x50)(var_r27);
    var_r31 = M2C_FIELD(table, s32 (**)(u8 *), 0x50)(var_r26);
    if (temp_r23 == 1) var_r3 = fn_800A485C((s8)*var_r27); else var_r3 = fn_800A4C04(var_r27);
    var_r30 = var_r3;
    if (var_r31 == 1) var_r3_2 = fn_800A485C((s8)*var_r26); else var_r3_2 = fn_800A4C04(var_r26);
    var_r29 = var_r3_2;
    if (temp_r23 == 2) {
        M2C_FIELD(table, s32 (**)(u8 *, u16 *), 0x48)(var_r27, &spA);
        if (spA >= 0xFF41U && spA <= 0xFF5AU) { var_r3_3 = 1U; spA -= 0x20; } else var_r3_3 = 0U;
        if (var_r3_3 == 1U) { M2C_FIELD(table, s32 (**)(u16 *, u16 *), 0x4C)(&spA, &spA); var_r3_4 = 1U; } else var_r3_4 = 0U;
        if (var_r3_4 == 1U) var_r30 = spA;
    }
    if (var_r31 == 2) {
        M2C_FIELD(table, s32 (**)(u8 *, u16 *), 0x48)(var_r26, &sp8);
        if (sp8 >= 0xFF41U && sp8 <= 0xFF5AU) { var_r3_5 = 1U; sp8 -= 0x20; } else var_r3_5 = 0U;
        if (var_r3_5 == 1U) { M2C_FIELD(table, s32 (**)(u16 *, u16 *), 0x4C)(&sp8, &sp8); var_r3_6 = 1U; } else var_r3_6 = 0U;
        if (var_r3_6 == 1U) var_r29 = sp8;
    }
    var_r27 = &var_r27[temp_r23];
    switch ((s32)var_r30) {
    case 0x3F:
        if ((s32)var_r29 == 0) return 1;
block_63:
        var_r26 = &var_r26[var_r31]; goto loop_64;
    case 0x2A:
loop_33:
        temp_r3_2 = M2C_FIELD(table, s32 (**)(u8 *), 0x50)(var_r27);
        if (temp_r3_2 != 1) var_r3_7 = fn_800A4C04(var_r27); else var_r3_7 = fn_800A485C((s8)*var_r27);
        var_r30 = var_r3_7; var_r27 = &var_r27[temp_r3_2];
        if (var_r30 == 0x3F) {
            if ((s32)var_r29 == 0) return 1;
            var_r26 = &var_r26[var_r31];
            temp_r3_3 = M2C_FIELD(table, s32 (**)(u8 *), 0x50)(var_r26); var_r31 = temp_r3_3;
            if (temp_r3_3 == 1) var_r3_8 = fn_800A485C((s8)*var_r26); else var_r3_8 = fn_800A4C04(var_r26);
            var_r29 = var_r3_8; goto block_43;
        }
block_43:
        if (var_r30 != 0x3F && var_r30 != 0x2A) {
            if ((s32)var_r30 == 0) return 0;
loop_57:
            if ((s32)var_r29 == 0) {
                if ((s8)*var_r26 == 0 || (s8)*var_r27 == 0) *var_r28 = one;
            default:
                if (var_r29 != var_r30) return 1;
                goto block_63;
            }
        }
        var_r26 = &var_r26[var_r31];
        if (var_r29 == var_r30) {
            temp_r3 = VFiPFPATH_cmpNameImpl(var_r26, var_r27, var_r28);
            if (temp_r3 == 0) return 0;
            if ((s32)*var_r28 != 0) return temp_r3;
            goto block_53;
        }
block_53:
        temp_r3_4 = M2C_FIELD(table, s32 (**)(u8 *), 0x50)(var_r26); var_r31 = temp_r3_4;
        if (temp_r3_4 == 1) var_r3_9 = fn_800A485C((s8)*var_r26); else var_r3_9 = fn_800A4C04(var_r26);
        var_r29 = var_r3_9; goto loop_57;
    }
}

extern "C" s32 fn_800B6928(s8);
extern "C" s32 fn_800AE4C0(s32, s32, s32);
extern "C" s32 fn_800B3754(s32, s32 *, s32);
extern "C" s32 fn_800AF574(void *);
extern "C" s32 fn_800B5618(void *, void *, u16, u16, s32);
extern "C" s32 fn_800B317C(s32 arg0, s32 arg1) {
extern s32 fn_800B3754(s32, s32 *, s32);
return fn_800B3754(arg0, (s32 *)arg1, 1) == 0;
}

extern "C" s32 fn_800B3304(void *arg0, void *arg1) {
    return fn_800A4AD0((u8 *)arg0, (u8 *)arg1) != 0;
}

extern "C" void fn_800B3330(void *arg0, s32 arg1, s32 arg2) {
(*(s32 *)((u8 *)arg0 + 0)) = arg1;
(*(s32 *)((u8 *)arg0 + 4)) = arg1;
(*(s32 *)((u8 *)arg0 + 0xC)) = arg2;
}

extern "C" s32 VFiPFSTR_StrNCmp(s32, const void *, s32, s32, s32);
extern "C" void VFiPFSTR_MoveStrPos(void *, s16, s32);
extern "C" const u8 lbl_8055920C[];
extern "C" const u8 lbl_8055921C[];
extern "C" const u8 lbl_80559220[];
extern "C" const u8 lbl_80559224[];
extern "C" const u8 lbl_80559228[];
#pragma push
#pragma scheduling on
extern "C" s32 VFiPFPATH_GetNextTokenOfPath(void *arg0, s32 arg1) {
    s32 var_r27;
    u32 mode;
    s32 var_r4;
    s32 var_r5;
    u16 temp_r3_3;
    u8 *temp_r4;
    u8 temp_r0;

    var_r27 = 0;
    *(u8 **)arg0 = *(u8 **)((u8 *)arg0 + 4);
    if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055920C, 1, 0, 1) == 0) {
        *(u8 **)((u8 *)arg0 + 4) = 0;
        *(u8 **)arg0 = 0;
        return 0;
    }
          if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055921C, 1, 0, 1) == 0 ||
          VFiPFSTR_StrNCmp((s32)arg0, lbl_80559220, 1, 0, 1) == 0) {
          ((void (*)(void *, s16))VFiPFSTR_MoveStrPos)(arg0, 1);
      }
          if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055921C, 1, 0, 1) == 0 ||
          VFiPFSTR_StrNCmp((s32)arg0, lbl_80559220, 1, 0, 1) == 0) {
          return 2;
      }

    mode = fn_800A4D44(arg0);
    *(u8 **)((u8 *)arg0 + 4) = *(u8 **)arg0;
    if ((u32)(lbl_803D2140[0x60 / 4] & 2) == 2U) {
        var_r27 = ((s32 (*)(void *, u32, u32))fn_800B4D5C)(arg0, 2, arg1);
        if (var_r27 != 0) {
            if (mode == 1U)
                *(u8 **)((u8 *)arg0 + 4) += var_r27;
            else
                *(u8 **)((u8 *)arg0 + 4) += var_r27 * 2;
        }
    }

    if (var_r27 == 0) {
        do {
            if (mode == 1U &&
                ((s32 (**)(s8, s32))((u8 *)lbl_803D2140 + 0x54))[0]
                    ((s8)**(u8 **)((u8 *)arg0 + 4), 1) != 0) {
                *(u8 **)((u8 *)arg0 + 4) += 1;
                if (((s32 (**)(s8, s32))((u8 *)lbl_803D2140 + 0x54))[0]
                        ((s8)**(u8 **)((u8 *)arg0 + 4), 2) == 0 ||
                    (s8)**(u8 **)((u8 *)arg0 + 4) == 0)
                    return 2;
                goto advance;
            }

            if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055921C, 2, 0, 1) == 0)
                goto done;
            if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559220, 2, 0, 1) == 0)
                goto done;

            if ((lbl_803D2140[0x38 / 4] & 0x10000) == 0) {
                if (mode != 1U ||
                    ((temp_r0 = **(u8 **)((u8 *)arg0 + 4)) >= 0x80U) ||
                    (temp_r0 >= 0x20U &&
                     (*((u8 *)((u32)lbl_802EEEE0 + temp_r0) - 0x20) & 1) != 0)) {
                    if (mode == 2U) {
                        temp_r4 = *(u8 **)((u8 *)arg0 + 4);
                        var_r5 = 1;
                        temp_r3_3 = (temp_r4[0] << 8) + temp_r4[1];
                        if (temp_r3_3 < 0x80U) {
                            var_r4 = 0;
                            if ((u8)temp_r3_3 >= 0x20U && (temp_r3_3 & 0xFF00) == 0 &&
                                (lbl_802EEEE0[(u8)((u8)temp_r3_3 - 0x20)] & 1) != 0)
                                var_r4 = 1;
                            if (var_r4 == 0)
                                var_r5 = 0;
                        }
                        if (var_r5 == 0)
                            goto invalid;
                        goto advance;
                    }
                    goto advance;
                }
                goto invalid;
            }
            goto advance;
        invalid:
            if (arg1 == 0 ||
                (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559224, 2, 0, 1) != 0 &&
                 VFiPFSTR_StrNCmp((s32)arg0, lbl_80559228, 2, 0, 1) != 0))
                return 2;
        advance:
            if (mode == 1U)
                *(u8 **)((u8 *)arg0 + 4) += 1;
            else
                *(u8 **)((u8 *)arg0 + 4) += 2;
        } while (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055920C, 2, 0, 1) != 0);
    }
done:
    return 0;
}
#pragma pop
extern "C" void fn_800B36C4(s32 arg0, s32 arg1, s32 arg2) {
fn_800B23F8(arg0, arg1, arg2, 0);
}

extern "C" void fn_800B36CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
fn_800B23F8(arg0, arg1, arg2, 1);
}

extern "C" void fn_800B36D4(s32 arg0) {
u8 sp8;

if ((VFiPFSTR_StrNumChar(arg0, 1) >= 2U) && (VFiPFSTR_StrNCmp(arg0, &lbl_80559208, 1, 1, 1) == 0)) {
VFiPFSTR_ToUpperNStr(arg0, 1, &sp8);
fn_800B65A0((s8)sp8);
return;
}
fn_800B63FC();
}

extern "C" u8 lbl_80559230, lbl_80559231;
extern "C" u8 lbl_80559210, lbl_80559214;
extern "C" s32 fn_800B3754(s32 arg0, s32 *arg1, s32 arg2) {
struct {
s32 sp10[4];
volatile s32 sp20;
volatile s32 sp24;
volatile s32 sp28;
volatile u16 sp2C;
} frame;
u32 var_r31 = 1;
s32 *arg1_ptr = arg1;
volatile s32 *copy = arg1;
s32 *var_r29 = arg1_ptr;
frame.sp20 = arg0;
frame.sp24 = 0;
frame.sp28 = arg2;
frame.sp2C = 0;
u8 spC[2];
u8 sp8[2];
s32 temp_r5;
s32 var_r0;
s32 var_r3_2;
s32 var_r29_2;
u32 temp_r4;
u16 temp_r29;
u16 var_r31_2;
u16 var_r3_3;
u32 var_r4;
u32 var_r3;
u32 result_r0;
u32 temp_r6;

var_r0 = copy[0];
temp_r5 = copy[1];
frame.sp10[0] = var_r0;
frame.sp10[1] = temp_r5;
temp_r5 = copy[2];
var_r0 = copy[3];
frame.sp10[2] = temp_r5;
frame.sp10[3] = var_r0;
if (fn_800A4D44(var_r29) == 1U) {
if ((arg2 == 0) && ((M2C_FIELD(lbl_803D2140, u32 *, 0x60) & 2) == 2)) {
spC[0] = lbl_80559230;
var_r29 = 0;
spC[1] = lbl_80559231;
if (VFiPFSTR_StrNCmp((s32)frame.sp10, spC, 1, 0, 2) == 0) {
var_r29 = (s32 *)1;
}
if (var_r29 == (s32 *)1) {
sp8[0] = lbl_80559230;
var_r31 = 0;
sp8[1] = lbl_80559231;
if (VFiPFSTR_StrNCmp((s32)frame.sp10, sp8, 1, 0, 2) == 0) {
var_r31 = 1;
}
if (var_r31 == 1) {
frame.sp2C += 2;
frame.sp10[0] += 2;
}
}
}
} else if (((M2C_FIELD(lbl_803D2140, u32 *, 0x60) & 2) == 2) &&
  (arg2 == 0) &&
  (VFiPFSTR_StrNCmp((s32)var_r29, &lbl_80559210, 1, 0, 1) != 0) &&
  (VFiPFSTR_StrNCmp((s32)var_r29, &lbl_80559214, 1, 0, 2) != 0) &&
  (((s32 (*)(void *, u32, u32))fn_800B4D5C)(var_r29, 1, 0) == 0)) {
var_r31 = 0;
}
if (var_r31 == 1) {
if (frame.sp28 != 0) {
temp_r6 = frame.sp2C;
if (temp_r6 > 0x20A) {
var_r31_2 = 0;
} else {
var_r0 = 0;
s32 *data = (s32 *)frame.sp20;
var_r4 = *(u16 *)((u8 *)data + temp_r6);
frame.sp2C = temp_r6 + 2;
if ((var_r4 >= 0x61) && (var_r4 <= 0x7A)) {
var_r0 = 1;
}
if (var_r0 != 0) {
var_r4 -= 0x20;
}
var_r31_2 = var_r4;
if ((var_r31_2 >= 0xFF41) && (var_r31_2 <= 0xFF5A)) {
var_r3 = 1;
temp_r29 = var_r31_2 - 0x20;
} else {
var_r3 = 0;
}
if (var_r3 == 1) {
var_r31_2 = temp_r29;
}
}
} else {
temp_r6 = frame.sp2C;
if (temp_r6 >= 0xC) {
var_r31_2 = 0;
} else {
frame.sp2C = temp_r6 + 1;
u8 *path_ptr = (u8 *)frame.sp20;
var_r29_2 = (s8)*(path_ptr + temp_r6);
if (M2C_FIELD(lbl_803D2140, s32 (**)(s8, s32, void *), 0x54)(var_r29_2, 1, (void *)path_ptr) != 0) {
temp_r4 = frame.sp2C;
u8 *base_ptr = (u8 *)frame.sp20;
frame.sp2C = temp_r4 + 1;
var_r29_2 = (u16)(((var_r29_2 << 8) & 0xFF00) + *(base_ptr + temp_r4));
}
var_r3_2 = 0;
if (((u16)var_r29_2 >= 0x61) && ((u16)var_r29_2 <= 0x7A)) {
var_r3_2 = 1;
}
var_r3_3 = (u16)var_r29_2;
if (var_r3_2 != 0) {
var_r3_3 -= 0x20;
}
var_r31_2 = var_r3_3;
}
}
result_r0 = fn_800B25CC(frame.sp10, arg2);
var_r31 = VFiPFPATH_DoMatchFileNameWithPattern(var_r31_2, (s32 *)&frame.sp20, (u16)result_r0, frame.sp10, arg2);
}
return var_r31;
}

s32 fn_800B3A70(char *dst, const char *src, s32 flags) {
    s32 len = 0;
    while (len < 8) {
        char c = *src++;
        *dst++ = c;
        len++;
        if (len >= 8 || c == 0 || c == '.') break;
    }
    if (len == 0) {
        len = 0;
        do {
            char c = *src++;
            *dst++ = c;
            len++;
            if (len >= 2 || c == 0) break;
        } while (1);
    }
    if (!(flags & 8)) {
        if (len < 8) {
            s32 n = 8 - len;
            do { *dst++ = ' '; } while (--n);
            len += 8 - len;
        }
    }
    if (*src != 0) {
        if (!(flags & 8)) src++;
        while (*src != 0) {
            *dst++ = *src++;
            len++;
        }
    }
    if (len < 11) {
        s32 n = 11 - len;
        do { *dst++ = ' '; } while (--n);
    }
    return 0;
}

extern "C" void fn_800B3BEC(u8 *out, u8 *in, u8 flags) {
    s32 last = -1;
    s32 i;
    for (i = 0; i < 8; i++) {
        out[i] = in[i];
        if (in[i] != ' ') last = i;
    }
    for (i = 8; i < 11; i++) {
        if (in[i] != ' ') last = i;
    }
    out += last + 1;
    if (last <= 7) {
        *out = 0;
        return;
    }
    if ((flags & 8) == 0) {
        *out++ = '.';
    }
    i = 8;
    while (i <= last) *out++ = in[i++];
    *out = 0;
}

extern "C" void VFiPFPATH_getLongNameformShortName(void *arg0, void *arg1, s32 flags) {
    u8 *src=(u8 *)arg0, *dst=(u8 *)arg1;
    s32 lower=flags&8, i=0;
    s32 n=2;
    while(n--) {
        s8 c=(s8)src[0];
        if(c==0||c=='.') goto extension;
        if(lower&&c>='A'&&c<='Z') dst[0]=c+0x20; else dst[0]=c;
        c=(s8)src[1]; i++;
        if(c==0||c=='.') goto extension;
        if(lower&&c>='A'&&c<='Z') dst[1]=c+0x20; else dst[1]=c;
        c=(s8)src[2]; i++;
        if(c==0||c=='.') goto extension;
        if(lower&&c>='A'&&c<='Z') dst[2]=c+0x20; else dst[2]=c;
        c=(s8)src[3]; i++;
        if(c==0||c=='.') goto extension;
        if(lower&&c>='A'&&c<='Z') dst[3]=c+0x20; else dst[3]=c;
        i++; src+=4; dst+=4;
    }
extension:
    if((s8)((u8 *)arg0)[i]=='.') { ((u8 *)arg1)[i]='.'; i++; }
    {
        s32 end=i+3;
        u8 *p=(u8 *)arg0+i, *q=(u8 *)arg1+i;
        s32 lowerExt=flags&0x10;
        for(;i<end;i++,p++,q++) {
            s8 c=(s8)*p;
            if(c==0) break;
            if(lowerExt&&c>='A'&&c<='Z') *q=c+0x20; else *q=c;
        }
    }
    ((u8 *)arg1)[i]=0;
}

extern "C" s32 VFiPFPATH_GetLengthFromShortname(s8 *arg0) {
    s32 i = 0;
    s32 length = 0;
    while (arg0[i] != 0) {
        if (i == 8 && (arg0[i] != 0x20 || arg0[i + 1] != 0x20 || arg0[i + 2] != 0x20))
            length++;
        if (arg0[i] != 0x20)
            length++;
        i++;
    }
    return length;
}

typedef s32 (*UnicodeLengthCallback)(const u16 *, void *);
extern "C" s32 VFiPFPATH_GetLengthFromUnicode(const u16 *text) {
    struct Scratch {
        void *state;
        s16 inputLength;
        s16 outputLength;
    } scratch;
    s32 inputIndex = 0;
    s32 outputTotal = 0;
    UnicodeLengthCallback callback;

    while (text[inputIndex] != 0) {
        callback = *(UnicodeLengthCallback *)((u8 *)lbl_803D2140 + 0x4C);
        fn_800A4BF4(callback(text + inputIndex, &scratch.state),
                    (u16 *)&scratch.outputLength, &scratch.inputLength);
        outputTotal += scratch.outputLength;
        inputIndex += scratch.inputLength >> 1;
    }
    return outputTotal;
}

#define fn_800A4B9C_CALL fn_800A4B9C
extern "C" void VFiPFPATH_transformFromUnicodeToNormal(u16 *arg0, u16 *arg1) {
    u8 *out = (u8 *)arg0;
    u16 *src = arg1;
    s16 dot = 0x2E;
    s16 space = 0x20;
    s16 underscore = 0x5F;
    if ((u32)(lbl_803D2140[0x60 / 4] & 2) == 2U) {
        while (*src != 0) {
            if (fn_800A4B9C_CALL(src, (u16 *)&dot, 1) == 0) {
                *out = 0x2E;
            } else if (fn_800A4B9C_CALL(src, (u16 *)&space, 1) == 0) {
                *out = 0x20;
            } else {
                *out = 0x5F;
            }
            out++;
            src += 2;
        }
    } else {
        s32 offset = 0;
        while (src[offset] != 0) {
            ((void (*)(u16 *, u16 *))(*(u32 *)((u8 *)lbl_803D2140 + 0x4C)))(src + offset, arg1);
            s16 inLen;
            s16 outLen;
            fn_800A4BF4(0, (u16 *)&inLen, &outLen);
            out += outLen & ~1;
            offset += inLen;
        }
    }
    *out = 0;
}

extern "C" s32 fn_800A4BF4(s32, u16 *, s16 *);
extern "C" s32 VFiPFPATH_transformInUnicode(s16 *dst, s32 src, s32 unused) {
    s32 offset;
    s32 count;
    const char *source = (const char *)src;
    count = 0;
    offset = 0;
    while (source[offset] != 0) {
        s32 result = ((s32 (*)(const char *, s16 *))(*(u32 *)((u8 *)lbl_803D2140 + 0x48)))(source + offset, dst);
        s16 inLen;
        s16 outLen;
        fn_800A4BF4(result, (u16 *)&inLen, &outLen);
        ++count;
        dst = (s16 *)((u8 *)dst + (outLen & ~1));
        offset += inLen;
    }
    *dst = 0;
    return count;
}

s32 VFiPFPATH_parseShortNameNumeric(char *arg0, s32 arg1) {
    s8 temp[1];
    s32 n=arg1, i, j, k, digits=0, value;
    char *p;
    if(n==0)return 0;
    i=1;p=arg0+1;
    while(*p!='~'){i++;p++;}
    j=i+1;p=arg0+j;
    while(*p!='.'&&*p!=0){j++;p++;}
    k=j+1;
    if(*p=='.'&&arg0[k]!=0){k++;p=arg0+k;while(*p!=0){k++;p++;}}
    p=(char*)(temp+1);
    while(n!=0){value=n%10;n/=10;*p=(s8)(value+0x30);p++;digits++;}
    value=i+digits;
    if(value>=j){
        s32 end=value+1;
        if(end>8)end=8;
        arg0[end+4]=arg0[k];
        arg0[end+3]=arg0[j+2];
        arg0[end+2]=arg0[j+1];
        arg0[end+1]=arg0[j];
        arg0[end]=arg0[i];
    }
    if(value>=8)i=7-digits;
    arg0[i]= '~';
    p=(char*)(temp+1+digits);
    arg0+=i+1;
    if(digits!=0){s32 q=digits>>3,rem;
        while(q--){arg0[0]=p[-1];arg0[1]=p[-2];arg0[2]=p[-3];arg0[3]=p[-4];arg0[4]=p[-5];arg0[5]=p[-6];arg0[6]=p[-7];arg0[7]=p[-8];p-=8;arg0+=8;}
        rem=digits&7;
        while(rem--){*arg0=p[-1];p--;arg0++;}
    }
    return 0;
}

extern "C" s32 fn_800A4D44(void *);
extern "C" s32 fn_800A4AD0(u8 *, u8 *);
extern "C" char *fn_800A4AAC(char *, char *);
extern "C" void fn_800A4B78(u16 *, u16 *);
extern "C" s32 VFiPFSTR_StrCmp(void *, s32);
extern "C" void VFiPFPATH_transformFromUnicodeToNormal(u16 *, u16 *);
extern "C" s32 fn_800B77C0(void *);
extern "C" void fn_800B783C(void *);
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559224[]; }
extern "C" const u8 lbl_8055922C[];
extern "C" void fn_800B4BD8(char *arg0, u16 *arg1, void *arg2) {
    u16 sp8[2];
    u16 **p = (u16 **)arg2;
    if (fn_800A4D44(p) == 1U) {
        if (fn_800A4AD0((u8 *)*p, (u8 *)lbl_8055922C) == 0) {
            fn_800A4AAC(arg0, (char *)lbl_80559224);
            return;
        }
        fn_800A4AAC(arg0, (char *)*p);
        return;
    }
    if (VFiPFSTR_StrCmp(p, (s32)lbl_8055922C) == 0) {
        sp8[0] = 0x2A;
        sp8[1] = 0;
        fn_800A4B78(arg1, sp8);
    } else {
        fn_800A4B78(arg1, *p);
    }
    if ((u32)(lbl_803D2140[0x60 / 4] & 2) == 2U) {
        fn_800B77C0((u8 *)lbl_803D2140 + 0x64);
        lbl_803D2140[0x60 / 4] = (lbl_803D2140[0x60 / 4] & ~3) | 1;
        VFiPFPATH_transformFromUnicodeToNormal((u16 *)arg0, arg1);
        lbl_803D2140[0x60 / 4] = (lbl_803D2140[0x60 / 4] & ~3) | 2;
        fn_800B783C((u8 *)lbl_803D2140 + 0x64);
        return;
    }
    VFiPFPATH_transformFromUnicodeToNormal((u16 *)arg0, arg1);
}

extern "C" u8 lbl_80559230;
extern "C" u8 lbl_80559231;
extern "C" s32 fn_800B4D00(void) {
    u8 data[2];
    s32 result = 0;

    data[0] = lbl_80559230;
    data[1] = lbl_80559231;
    if (VFiPFSTR_StrNCmp(0, data, 1, 0, 2) == 0) {
        result = 1;
    }
    return result;
}

extern "C" s32 fn_800A4D74(void *, u32);
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_8055920C[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_8055921C[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559220[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559228[]; }
extern "C" { DECL_SECTION(".sdata") extern const u8 lbl_80559234[]; }
extern "C" const u8 lbl_80560D98;
extern "C" const u8 lbl_80560D99;
#pragma push
#pragma scheduling on
extern "C" s16 fn_800B4D5C(register void *arg0, register u32 arg1, register u32 arg2) {
volatile u8 sp8;
volatile u8 sp9;
s16 result;
u32 found;
s32 index;
s32 offset;
s32 special;
s32 special2;
s16 value;
sp8 = lbl_80560D98;
sp9 = lbl_80560D99;
result = 0;
found = 0;
if (VFiPFSTR_StrNCmp((s32)arg0, (const void *)&sp8, (s32)arg1, 0, 2) == 0)
goto begin;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559228, (s32)arg1, 0, 1) == 0) {
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559228, (s32)arg1, 1, 1) == 0)
goto begin;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559224, (s32)arg1, 0, 1) == 0)
goto begin;
}
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559224, (s32)arg1, 0, 1) != 0)
goto return_result;
begin:
index = 2;
offset = 4;
parse:
if (fn_800A4D44(arg0) == 1U)
value = (s16)((s8)((u8 *)(u32)fn_800A4D74(arg0, arg1))[(s16)index] - 0x30);
else
value = (s16)(((u16 *)(u32)fn_800A4D74(arg0, arg1))[offset / 2] - 0x30);
if (value < 0 || value > 9) {
if ((s32)arg2 == 0)
goto after_loop;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559224, (s32)arg1, (s16)index, 1) != 0 &&
VFiPFSTR_StrNCmp((s32)arg0, lbl_80559228, (s32)arg1, (s16)index, 1) != 0)
goto after_loop;
if ((u32)arg2 == 1U &&
VFiPFSTR_StrNCmp((s32)arg0, lbl_80559224, (s32)arg1, (s16)index, 1) == 0)
found = 1;
}
offset += 2;
index = (s16)(index + 1);
if (index >= 8)
goto after_loop;
special = 0;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055921C, (s32)arg1, (s16)index, 1) == 0 ||
VFiPFSTR_StrNCmp((s32)arg0, lbl_80559220, (s32)arg1, (s16)index, 1) == 0)
special = 1;
if (special != 0)
goto after_loop;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559234, (s32)arg1, (s16)index, 1) == 0)
goto after_loop;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055920C, (s32)arg1, (s16)index, 1) == 0)
goto after_loop;
goto parse;
after_loop:
if (index == 8 || found == 1) {
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_80559234, (s32)arg1, (s16)index, 1) != 0) {
special2 = 0;
if (VFiPFSTR_StrNCmp((s32)arg0, lbl_8055921C, (s32)arg1, (s16)index, 1) == 0 ||
VFiPFSTR_StrNCmp((s32)arg0, lbl_80559220, (s32)arg1, (s16)index, 1) == 0)
special2 = 1;
if (special2 == 0 ||
VFiPFSTR_StrNCmp((s32)arg0, lbl_8055920C, (s32)arg1, (s16)index, 1) == 0)
result = index;
} else {
result = index;
}
}
return_result:
return result;
}
#pragma pop
extern "C" s32 fn_800B51FC(void *arg0, s32 arg1) {
    s32 position = (s32)arg0 + 7;
    u32 digits = 7;
    u32 divisor = 10;
    u32 place = 1;

    while (digits > 1 && arg1 != 0) {
        u32 rem = arg1 % divisor;
        if (rem != 0) {
            arg1 -= rem;
            *(u8 *)position += (s8)(rem / place);
        }
        divisor *= 10;
        digits--;
        position--;
        place *= 10;
    }
    return 0;
}

extern "C" s32 fn_800A8EA0(void *, u32, void **);
extern "C" s32 fn_800B5260(void *arg0, void *arg1, u32 arg2, u32 arg3, s32 arg4) {
    void *page;
    if (!(M2C_FIELD(arg0, u16 *, 0x1F8C) & 1) || fn_800A53B4(arg0) == 0) {
        return 9;
    }
    if (arg2 >= M2C_FIELD(arg0, u32 *, 8) ||
        arg3 >= M2C_FIELD(arg0, u16 *, 0) ||
        (s32)(arg3 + arg4) > (s32)M2C_FIELD(arg0, u16 *, 0)) {
        return 10;
    }
    s32 result = fn_800A8EA0(arg0, arg2, &page);
    if (result != 0) {
        return result;
    }
    VFipf_memcpy(arg1, M2C_FIELD(page, u8 **, 8) + arg3, arg4);
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_800B5324(void *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4, u32 *arg5, s32 arg6) {
    void *page;
    u32 count;
    s32 result;
    *arg5 = 0;
    if (!(M2C_FIELD(arg0, u16 *, 0x1F8C) & 1) || !fn_800A53B4(arg0)) return 9;
    if ((arg2 >= M2C_FIELD(arg0,u32 *,8) || arg3 >= M2C_FIELD(arg0,u16 *,0) || arg3 + arg4 > M2C_FIELD(arg0,u16 *,0)) && arg3 != 0) return 10;
    if (arg3 != 0 || arg4 < M2C_FIELD(arg0,u16 *,0)) {
        result = ((s32 (*)(void *,u32,void **,s32))fn_800A8EE0)(arg0,arg2,&page,arg6);
        if (result) return result;
        VFipf_memcpy(arg1,M2C_FIELD(page,u8 **,8)+arg3,arg4);
        *arg5 = arg4;
    } else if (arg3 == 0 && !(arg4 & (M2C_FIELD(arg0,u16 *,0)-1))) {
        result = VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded(arg0,arg1,arg2,arg4 >> M2C_FIELD(arg0,u8 *,0x20),(s32)&count);
        if (result) return result;
        *arg5 += count << M2C_FIELD(arg0,u8 *,0x20);
        if (count != arg4 >> M2C_FIELD(arg0,u8 *,0x20)) return 17;
    } else if (arg3 == 0) {
        page = ((void *(*)(void *,u32))fn_800A90F8)(arg0,arg2);
        if (page) {
            arg3 = M2C_FIELD(page,u32 *,0x18) + M2C_FIELD(page,u32 *,0x14) - arg2;
            if (arg3 <= arg4 >> M2C_FIELD(arg0,u8 *,0x20)) {
                VFipf_memcpy(arg1,M2C_FIELD(page,void **,8),arg3 << M2C_FIELD(arg0,u8 *,0x20));
                arg2 += arg3;
                *arg5 += arg3 << M2C_FIELD(arg0,u8 *,0x20);
                arg4 -= arg3 << M2C_FIELD(arg0,u8 *,0x20);
            } else if (arg3 > arg4 >> M2C_FIELD(arg0,u8 *,0x20)) {
                VFipf_memcpy(arg1,M2C_FIELD(page,void **,8),arg4);
                *arg5 += arg4;
                arg4 = 0;
            }
        }
        if (arg4 != 0) {
            arg4 >>= M2C_FIELD(arg0,u8 *,0x20);
            u32 remainder = (arg2 + arg4) % M2C_FIELD(arg0,u32 *,0x1640);
            if (arg4 > remainder) {
                arg3 = arg4 - remainder;
                result = VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded(arg0,arg1+*arg5,arg2,arg3,(s32)&count);
                if (result) return result;
                *arg5 += count << M2C_FIELD(arg0,u8 *,0x20);
                if (count != arg3) return 17;
                arg2 += arg3;
                arg4 -= arg3;
            }
            if (arg4 != 0) {
                result = ((s32 (*)(void *,u32,void **,s32))fn_800A8EE0)(arg0,arg2,&page,arg6);
                if (result) return result;
                VFipf_memcpy(arg1+*arg5,M2C_FIELD(page,void **,8),arg4 << M2C_FIELD(arg0,u8 *,0x20));
                *arg5 += arg4 << M2C_FIELD(arg0,u8 *,0x20);
            }
        }
    } else return 10;
    return 0;
}

extern "C" s32 fn_800B5618(void *arg0, void *arg1, u16 arg2, u16 arg3, s32 arg4) {
    void *page;
    u16 limit;

    if (!(*(u16 *)((u8 *)arg0 + 0x1F8C) & 1) ||
        fn_800A53B4(arg0) == 0 ||
        (*(u16 *)((u8 *)arg0 + 0x1F8C) & 2)) {
        return 9;
    }

    if (arg2 >= *(u32 *)((u8 *)arg0 + 8) ||
        arg3 >= (limit = *(u16 *)arg0) ||
        (s32)(arg3 + arg4) > (s32)limit) {
        return 10;
    }

    s32 result = fn_800A8EA0(arg0, arg2, &page);
    if (result != 0) {
        return result;
    }

    VFipf_memcpy((u8 *)*(void **)((u8 *)page + 8) + arg3, arg1, arg4);
    result = fn_800A8FD0(arg0, (s32)page);
    return result & ((-result | result) >> 31);
}

#pragma pop
extern "C" s32 fn_800A53B4(void *);
extern "C" s32 fn_800A53C0(void *);
extern "C" s32 fn_800A53DC(void *);
extern "C" void fn_800A53E8(void *);
extern "C" void fn_800A53CC(void *);
extern "C" s32 fn_800A5788(void *, s32);
extern "C" s32 fn_800B5988(void *);
extern "C" void VFiPFDIR_FinalizeAllDirs(u8 *);
#pragma dont_inline on
extern "C" s32 fn_800B6004(void *arg0) {
    s32 result;
    u16 flags;
    if (fn_800A53B4(arg0) != 0) {
        if (fn_800A53DC(arg0) != 0 && (*(u16 *)((u8 *)arg0 + 0x1F8C) & 8) == 0) {
            VFiPFFILE_FinalizeAllFiles((u8 *)arg0);
            VFiPFDIR_FinalizeAllDirs((u8 *)arg0);
            if (fn_800A5788(arg0, 1) == 0) {
                if (*(u16 *)((u8 *)arg0 + 0x1F8C) & 8) {
                    *(s32 *)((u8 *)arg0 + 0x1654) = 0;
                    *(s32 *)((u8 *)arg0 + 0x189C) = 0;
                    *(s32 *)((u8 *)arg0 + 0x1AE4) = 0;
                    *(s32 *)((u8 *)arg0 + 0x1D2C) = 0;
                }
                *(u16 *)((u8 *)arg0 + 0x1F8C) &= 0xFFF7;
            }
            fn_800A53E8(arg0);
            lbl_803D2140[13]--;
        }
        if (fn_800A53C0(arg0) != 0) {
            if ((*(u16 *)((u8 *)arg0 + 0x1F8C) & 8) == 0) {
                result = fn_800B5988(arg0);
                if (result == 0) {
                    *(u16 *)((u8 *)arg0 + 0x1FAC) &= 0xFFF8;
                    fn_800A53E8(arg0);
                    lbl_803D2140[13]++;
                    fn_800A53CC(arg0);
                    result = 0;
                }
            } else { fn_800A53CC(arg0); result = 0; }
            if (result == 0) goto done;
        } else goto done;
    } else {
        if (fn_800A53DC(arg0) != 0 && (*(u16 *)((u8 *)arg0 + 0x1F8C) & 8) == 0) {
            VFiPFFILE_FinalizeAllFiles((u8 *)arg0);
            VFiPFDIR_FinalizeAllDirs((u8 *)arg0);
            if (fn_800A5788(arg0, 1) == 0) {
                if (*(u16 *)((u8 *)arg0 + 0x1F8C) & 8) {
                    *(s32 *)((u8 *)arg0 + 0x1654) = 0;
                    *(s32 *)((u8 *)arg0 + 0x189C) = 0;
                    *(s32 *)((u8 *)arg0 + 0x1AE4) = 0;
                    *(s32 *)((u8 *)arg0 + 0x1D2C) = 0;
                }
                *(u16 *)((u8 *)arg0 + 0x1F8C) &= 0xFFF7;
            }
            fn_800A53E8(arg0);
            lbl_803D2140[13]--;
        }
        if (fn_800A53C0(arg0) != 0) fn_800A53CC(arg0);
done:
        result = 0;
    }
    if (result != 0) return result;
    flags = *(u16 *)((u8 *)arg0 + 0x1F8C);
    if ((flags & 8) == 0) return 9;
    return -((flags >> 1) & 1) & 0xB;
}

extern "C" s32 fn_800B6200(void *arg0, void *arg1) {
    u32 key;
    s32 i;
    u32 *base = (u32 *)arg0, *out = (u32 *)arg1, *entry, *src, *dst;
    if ((*(u16 *)((u8 *)arg0 + 0x1F8C) & 8) == 0) return 9;
    fn_800B77C0((u8 *)lbl_803D2140 + 0x64);
    ((void (*)(u32 *))fn_800B78F0)(&key);
    for (i = 1, entry = (u32 *)((u8 *)arg0 + 0x248); i < 4; i++, entry = (u32 *)((u8 *)entry + 0x248)) {
        if ((entry[0x1654 / 4] & 1) && entry[0x1658 / 4] == key) {
            src = entry + 0x165C / 4; dst = out;
            for (i = 0; i < 0x48; i++) { *dst++ = *src++; *dst++ = *src++; }
            goto finish;
        }
    }
    if (((*(u32 *)((u8 *)lbl_803D2140 + 0x88) &= 1), *(u32 *)((u8 *)lbl_803D2140 + 0x88)) &&
        *(u32 *)((u8 *)lbl_803D2140 + 0x8C) == key) goto copy_main;
    if (((*(u32 *)((u8 *)lbl_803D2140 + 0x90) &= 1), *(u32 *)((u8 *)lbl_803D2140 + 0x90)) &&
        *(u32 *)((u8 *)lbl_803D2140 + 0x94) == key) goto allocate;
    if (((*(u32 *)((u8 *)lbl_803D2140 + 0x98) &= 1), *(u32 *)((u8 *)lbl_803D2140 + 0x98)) &&
        *(u32 *)((u8 *)lbl_803D2140 + 0x9C) == key) goto allocate;
copy_main:
    src = base + 0x165C / 4;
    goto copy;
allocate:
    for (i = 1, entry = (u32 *)((u8 *)arg0 + 0x248); i < 4; i++, entry = (u32 *)((u8 *)entry + 0x248)) {
        if ((entry[0x1654 / 4] & 1) == 0) {
            entry[0x1654 / 4] |= 1; entry[0x1658 / 4] = key;
            src = entry + 0x165C / 4;
            goto copy;
        }
    }
    goto finish;
copy:
    dst = out;
    for (i = 0; i < 0x48; i++) { *dst++ = *src++; *dst++ = *src++; }
finish:
    ((void (*)(void *, void *))fn_800B783C)((u8 *)lbl_803D2140 + 0x64, arg1);
    return 0;
}

extern "C" s32 fn_800B63FC(void) {
    s32 key, result = 0, found = 0, i;
    s32 *base = lbl_803D2140;
    fn_800B77C0((u8 *)base + 0x64);
    ((void (*)(s32 *))fn_800B78F0)(&key);
    for (i = 1; i < 4; i++) {
        s32 *entry = (s32 *)((u8 *)base + 0xC + (i - 1) * 0xC);
        if ((entry[0] & 1) && entry[1] == key) { result = entry[2]; found = 1; break; }
    }
    if (!found) {
        s32 *e = (s32 *)((u8 *)base + 0x88);
        s32 flag = e[0] & 1; e[0] = flag;
        if (flag && e[1] == key) found = 1;
        else {
            e = (s32 *)((u8 *)base + 0x90); flag = e[0] & 1; e[0] = flag;
            if (flag && e[1] == key) found = 1;
            else {
                e = (s32 *)((u8 *)base + 0x98); flag = e[0] & 1; e[0] = flag;
                if (flag && e[1] == key) found = 1;
            }
        }
        if (found) {
            for (i = 1; i < 4; i++) {
                s32 *entry = (s32 *)((u8 *)base + i * 0xC);
                if (!(entry[0] & 1)) { entry[0] |= 1; entry[1] = key; result = entry[2]; break; }
            }
        } else result = base[2];
    }
    fn_800B783C((u8 *)base + 0x64);
    return result;
}

extern "C" s32 fn_800A485C(s32);
extern "C" void *fn_800B65A0(s8 arg0) {
    s16 index = fn_800A485C(arg0) - 0x41;
    fn_800B77C0((u8 *)lbl_803D2140 + 0x64);
    if (index < 0 || index >= 0x1A) {
        fn_800B783C((u8 *)lbl_803D2140 + 0x64);
        return 0;
    }
    fn_800B783C((u8 *)lbl_803D2140 + 0x64);
    return (u8 *)lbl_803D2140 + index * 0x1FC8 + 0xA0;
}

extern "C" s32 fn_800B94EC(s32, s32);
extern "C" void fn_800B7710(void *);
extern "C" s32 fn_800A53F8(void *);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_800B6628(void *arg0, void *arg1, s32 arg2) {
    u8 *base;
    u8 *record;
    s32 var_r27 = arg2, var_r31, temp_r3_2, temp_r3_3, temp_r4_2, temp_r4_3, var_ctr, var_r0;
    s8 temp_r0;
    void *temp_r4, *temp_r6, *temp_r7, *var_r3;
    temp_r6 = M2C_FIELD(arg0, void **, 4);
    if ((s32)M2C_FIELD(temp_r6, s32 *, 0xC) == 0) M2C_FIELD(temp_r6, s32 *, 0xC) = 1;
    temp_r4 = M2C_FIELD(arg0, void **, 4);
    if ((s32)M2C_FIELD(temp_r4, s32 *, 0x10) == 0) M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
    base = (u8 *)lbl_803D2140;
    M2C_FIELD(arg0, u8 *, 9) = 0U;
    M2C_FIELD(arg0, s8 *, 8) = 0;
    fn_800B77C0(base + 0x64);
    if (arg1 != 0 && fn_800B94EC((s32)arg1, var_r27) != 0) {
        fn_800B783C(base + 0x64);
        *(s32 *)(base + 0x40) = 0x11;
        return 0x11;
    }
    var_r31 = 0;
    var_r3 = (u8 *)lbl_803D2140 + 0xA0;
    for (var_ctr = 0xD; var_ctr != 0; var_ctr--) {
        record = (u8 *)var_r3;
        if (*(u16 *)((u8 *)var_r3 + 0x1F8C) & 1) {
            u16 flags2 = *(u16 *)((u8 *)var_r3 + 0x3F54);
            var_r3 = (u8 *)var_r3 + 0x1FC8;
            record = (u8 *)var_r3;
            var_r31++;
            if (flags2 & 1) {
                var_r3 = (u8 *)var_r3 + 0x1FC8;
                var_r31++;
                continue;
            }
        }
        break;
    }
    if (var_r31 < 0 || var_r31 >= 0x1A ||
        *(s32 *)((u8 *)lbl_803D2140 + 0x30) < 0 || *(s32 *)((u8 *)lbl_803D2140 + 0x30) >= 0x1A) {
        fn_800B783C((u8 *)lbl_803D2140 + 0x64);
        *(s32 *)((u8 *)lbl_803D2140 + 0x40) = 4;
        return 4;
    }
    *(s32 *)(record + 0x38) = -1;
    *(s32 *)(record + 0x3C) = -1;
    fn_800A499C((const char *)record, 0, 0x1FC8);
    temp_r4_2 = M2C_FIELD(arg0, s32 *, 0);
    *(s32 *)(record + 0x1FBC) = temp_r4_2;
    temp_r0 = (s8)((s16)var_r31 + 0x41);
    *(s8 *)(record + 0x1F8E) = temp_r0;
    fn_800B7710(record + 0x1F90);
    *(s32 *)(record + 0x1F74) = 1;
    *(void **)(record + 0x1F7C) = record + 0x1F78;
    temp_r3_2 = fn_800A53F8(record);
    if (temp_r3_2 != 0) var_r27 = temp_r3_2;
    else {
        temp_r7 = M2C_FIELD(arg0, void **, 4);
        ((void (*)(void *, s32, s32, u16, u16))fn_800A8B94)(
            record, M2C_FIELD(temp_r7, s32 *, 0), M2C_FIELD(temp_r7, s32 *, 4),
            M2C_FIELD(temp_r7, u16 *, 8), M2C_FIELD(temp_r7, u16 *, 0xA));
        fn_800A8BA8(record, M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
        fn_800A8BB8(record, M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x10));
        var_r27 = 0;
    }
    if (var_r27 != 0) {
        fn_800B783C((u8 *)lbl_803D2140 + 0x64);
        *(s32 *)((u8 *)lbl_803D2140 + 0x40) = var_r27;
        return var_r27;
    }
    temp_r0 = (s8)((s16)var_r31 + 0x41);
    *(u16 *)(record + 0x1F8C) |= 1;
    M2C_FIELD(arg0, u8 *, 9) |= 1;
    *(s8 *)(record + 0x1F8E) = temp_r0;
    M2C_FIELD(arg0, s8 *, 8) = temp_r0;
    temp_r4_3 = *(s32 *)((u8 *)lbl_803D2140 + 0x30);
    *(s32 *)((u8 *)lbl_803D2140 + 0x30) = temp_r4_3 + 1;
    if (fn_800A53B4(record) != 0) {
        M2C_FIELD(arg0, u8 *, 9) |= 0x10;
        if (!(*(u16 *)(record + 0x1F8C) & 8)) {
            temp_r3_3 = fn_800B5988(record);
            if (temp_r3_3 != 0) var_r0 = temp_r3_3;
            else {
                *(u16 *)(record + 0x1FAC) &= 0xFFF8;
                fn_800A53E8(record);
                (*(s32 *)((u8 *)lbl_803D2140 + 0x34))++;
                goto block_26;
            }
        } else {
block_26:
            fn_800A53CC(record);
            var_r0 = 0;
        }
        if (var_r0 != 0) {
            *(s32 *)((u8 *)lbl_803D2140 + 0x40) = var_r0;
            *(s32 *)(record + 0x1F80) = var_r0;
            fn_800B783C((u8 *)lbl_803D2140 + 0x64);
            return 0;
        }
        M2C_FIELD(arg0, u8 *, 9) |= 2;
        goto block_30;
    }
block_30:
    fn_800B783C((u8 *)lbl_803D2140 + 0x64);
    return 0;
}
#pragma pop
s32 fn_800B6928(s8 arg0) {
    s16 index = fn_800A485C(arg0) - 0x41;
    u8 *base = (u8 *)lbl_803D2140;
    void *entry;
    u16 flags;
    s32 result;

    fn_800B77C0(base + 0x64);
    if (index < 0 || index >= 0x1A) {
        fn_800B783C(base + 0x64);
        entry = 0;
    } else {
        fn_800B783C(base + 0x64);
        entry = base + index * 0x1FC8 + 0xA0;
    }
    flags = *(u16 *)((u8 *)entry + 0x1F8C);
    if (flags & 8) {
        *(s32 *)(base + 0x40) = 10;
        *(s32 *)((u8 *)entry + 0x1F80) = 10;
        return 10;
    }
    if (!(flags & 1)) {
        *(s32 *)(base + 0x40) = 10;
        *(s32 *)((u8 *)entry + 0x1F80) = 10;
        return 10;
    }
    fn_800B77C0(base + 0x64);
    result = fn_800A54AC(entry);
    if (!result) {
        fn_800B777C((u8 *)entry + 0x1F90);
        result = 0;
    }
    if (result) {
        fn_800B783C(base + 0x64);
        *(s32 *)(base + 0x40) = result;
        *(s32 *)((u8 *)entry + 0x1F80) = result;
        return result;
    }
    *(u16 *)((u8 *)entry + 0x1F8C) &= 0xFFFE;
    result = *(s32 *)(base + 0x30);
    *(s32 *)(base + 0x30) = result - 1;
    fn_800B783C(base + 0x64);
    return 0;
}

extern "C" s32 fn_800B5B94(void *, s32);
extern "C" s32 fn_800B6A8C(s8 arg0, s32 arg1) {
    u8 *var_r31;
    u32 base_address;
    s32 var_r30;
    s16 temp_r28;
    s32 var_r28;
    s32 var_r3;
    s32 temp_r3;
    var_r30 = 0;
    temp_r28 = fn_800A485C((s32)arg0) - 0x41;
    var_r31 = (u8 *)lbl_803D2140;
    fn_800B77C0(var_r31 + 0x64);
    if ((temp_r28 < 0) || (temp_r28 >= 0x1A)) {
        fn_800B783C((u8 *)lbl_803D2140 + 0x64);
        var_r31 = 0;
    } else {
        fn_800B783C(var_r31 + 0x64);
        base_address = (u32)var_r31 + (temp_r28 * 0x1FC8);
        var_r31 = (u8 *)(base_address + 0xA0);
    }
    if (!(M2C_FIELD(var_r31, u16 *, 0x1F8C) & 1)) {
        M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x40) = 0xA;
        return 0xA;
    }
    fn_800B77C0(var_r31 + 0x1F90);
    if (fn_800A53B4(var_r31) != 0) {
        if ((fn_800A53DC(var_r31) != 0) && !(M2C_FIELD(var_r31, u16 *, 0x1F8C) & 8)) {
            VFiPFFILE_FinalizeAllFiles(var_r31);
            VFiPFDIR_FinalizeAllDirs(var_r31);
            if (fn_800A5788(var_r31, 1) == 0) {
                if (M2C_FIELD(var_r31, u16 *, 0x1F8C) & 8) {
                    M2C_FIELD(var_r31, s32 *, 0x1654) = 0;
                    M2C_FIELD(var_r31, s32 *, 0x189C) = 0;
                    M2C_FIELD(var_r31, s32 *, 0x1AE4) = 0;
                    M2C_FIELD(var_r31, s32 *, 0x1D2C) = 0;
                }
                M2C_FIELD(var_r31, u16 *, 0x1F8C) &= ~8;
            }
            fn_800A53E8(var_r31);
            M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x34)--;
        }
        if (fn_800A53C0(var_r31) != 0) {
            if (!(M2C_FIELD(var_r31, u16 *, 0x1F8C) & 8)) {
                var_r3 = fn_800B5988(var_r31);
                switch (var_r3) {
                case 0:
                    M2C_FIELD(var_r31, u16 *, 0x1FAC) &= ~7;
                    fn_800A53E8(var_r31);
                    M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x34)++;
                    goto block_19;
                default:
                    goto block_result;
                }
            } else {
block_19:
                fn_800A53CC(var_r31);
                var_r3 = 0;
            }
block_result:
            if (var_r3 != 0)
                var_r28 = var_r3;
            else
                goto block_31;
        } else {
            goto block_31;
        }
    } else {
        if ((fn_800A53DC(var_r31) != 0) && !(M2C_FIELD(var_r31, u16 *, 0x1F8C) & 8)) {
            VFiPFFILE_FinalizeAllFiles(var_r31);
            VFiPFDIR_FinalizeAllDirs(var_r31);
            if (fn_800A5788(var_r31, 1) == 0) {
                if (M2C_FIELD(var_r31, u16 *, 0x1F8C) & 8) {
                    M2C_FIELD(var_r31, s32 *, 0x1654) = 0;
                    M2C_FIELD(var_r31, s32 *, 0x189C) = 0;
                    M2C_FIELD(var_r31, s32 *, 0x1AE4) = 0;
                    M2C_FIELD(var_r31, s32 *, 0x1D2C) = 0;
                }
                M2C_FIELD(var_r31, u16 *, 0x1F8C) &= ~8;
            }
            fn_800A53E8(var_r31);
            M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x34)--;
        }
        if (fn_800A53C0(var_r31) != 0)
            fn_800A53CC(var_r31);
block_31:
        var_r28 = 0;
    }
    if (var_r28 != 0) {
        fn_800B783C(var_r31 + 0x1F90);
        M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x40) = var_r28;
        M2C_FIELD(var_r31, s32 *, 0x1F80) = var_r28;
        return var_r28;
    }
    if (!(M2C_FIELD(var_r31, u16 *, 0x1F8C) & 8)) {
        fn_800B783C(var_r31 + 0x1F90);
        return 0;
    }
    if ((M2C_FIELD(var_r31, s32 *, 0x161C) != 0) || (M2C_FIELD(var_r31, s32 *, 0x1620) != 0)) {
        var_r30 = 1;
        M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x40) = 0x13;
        M2C_FIELD(var_r31, s32 *, 0x1F80) = 0x13;
        if (!(arg1 & 1)) {
            fn_800B783C(var_r31 + 0x1F90);
            return 0x13;
        }
    }
    temp_r3 = fn_800B5B94(var_r31, arg1);
    if ((temp_r3 != 0) && (var_r30 == 0)) {
        var_r30 = 1;
        M2C_FIELD((u8 *)lbl_803D2140, s32 *, 0x40) = temp_r3;
        M2C_FIELD(var_r31, s32 *, 0x1F80) = temp_r3;
        if (!(arg1 & 1))
            var_r30 = temp_r3;
    }
    fn_800B783C(var_r31 + 0x1F90);
    return var_r30;
}

extern "C" s32 fn_800A4BE8(s32, s32);
extern "C" u16 lbl_802EEF80[];
extern "C" s32 VFiPFCODE_CP932_OEM2Unicode(s32 arg0, u16 *arg1) {
    u8 c = *(u8 *)arg0;
    u8 trail = *((u8 *)arg0 + 1);
    s32 row;
    u16 value;
    if (c < 0x80) {
        *arg1 = c;
        return fn_800A4BE8(1, 2);
    }
    if (c >= 0xa1 && c <= 0xdf) {
        *arg1 = c - 0x140;
        return fn_800A4BE8(1, 2);
    }
    if (c == 0x80 || c == 0x85 || c == 0x86 || c == 0xa0 || c == 0xeb || c == 0xec ||
        (c >= 0xef && c <= 0xf9) || c == 0xff) {
        *arg1 = 0x5f;
        return fn_800A4BE8(1, 2);
    }
    if (trail >= 0xfd) {
        *arg1 = 0x5f;
        return fn_800A4BE8(1, 2);
    }
    if (c >= 0x81 && c <= 0x84) row = c - 0x81;
    else if (c >= 0x87 && c <= 0x9f) row = c - 0x83;
    else if (c >= 0xe0 && c <= 0xea) row = c - 0xc3;
    else if (c >= 0xed && c <= 0xee) row = c - 0xc5;
    else if (c >= 0xfa && c <= 0xfc) row = c - 0xd0;
    else {
        *arg1 = 0x5f;
        return fn_800A4BE8(1, 2);
    }
    trail -= 0x40;
    if (trail >= 0xbd) {
        *arg1 = 0x5f;
        return fn_800A4BE8(1, 2);
    }
    value = lbl_802EEF80[row * 0xbd + trail];
    *arg1 = value;
    if (value == 0) {
        *arg1 = 0x5f;
        return fn_800A4BE8(1, 2);
    }
    return fn_800A4BE8(2, 2);
}

extern unsigned short lbl_802EEF80[];
extern void fn_800A4BE8(int, int);
void VFiPFCODE_CP932_Unicode2OEM(unsigned short *param_1, char *param_2)
{
    short sVar1;
    short sVar2;
    unsigned long long uVar3;
    unsigned short uVar4;
    unsigned short *puVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    unsigned short *puVar9;
    long long lVar10;

    uVar4 = *param_1;
    if (((uVar4 & 0xff) < 0x80) && ((int)(unsigned int)uVar4 >> 8 == 0)) {
        *param_2 = (char)uVar4;
        param_2[1] = '\0';
        fn_800A4BE8(1, 2);
        return;
    }
    uVar3 = (unsigned long long)((int)(unsigned int)uVar4 >> 8) * 0x100 + (uVar4 & 0xff);
    if ((0xff60 < uVar3) && (uVar3 < 0xffa0)) {
        param_2[1] = '\0';
        *param_2 = (char)uVar3 + '@';
        fn_800A4BE8(1, 2);
        return;
    }
    if (uVar3 == 0x5f) {
        *param_2 = '_';
        fn_800A4BE8(1, 2);
        return;
    }
    iVar6 = 0;
    puVar5 = lbl_802EEF80;
    do {
        lVar10 = 0x15;
        puVar9 = puVar5;
        iVar7 = 0;
        do {
            iVar8 = iVar7;
            if ((((((*puVar9 == uVar3) || (iVar8 = iVar7 + 1, puVar9[1] == uVar3)) ||
                (iVar8 = iVar7 + 2, puVar9[2] == uVar3)) ||
               ((iVar8 = iVar7 + 3, puVar9[3] == uVar3 || (iVar8 = iVar7 + 4, puVar9[4] == uVar3)))) ||
              ((iVar8 = iVar7 + 5, puVar9[5] == uVar3 ||
               ((iVar8 = iVar7 + 6, puVar9[6] == uVar3 || (iVar8 = iVar7 + 7, puVar9[7] == uVar3)))))) ||
             (iVar8 = iVar7 + 8, puVar9[8] == uVar3)) break;
            iVar8 = iVar7 + 9;
            puVar9 += 9;
            lVar10--;
            iVar7 = iVar8;
        } while (lVar10 != 0);
        if (iVar8 < 0xbd) break;
        iVar6++;
        puVar5 += 0xbd;
    } while (iVar6 < 0x2d);
    if (iVar8 == 0xbd) {
        *param_2 = '_';
        fn_800A4BE8(1, 2);
        return;
    }
    sVar1 = (short)iVar8;
    sVar2 = (short)iVar6;
    if (iVar6 < 0 || 3 < iVar6) {
        if (iVar6 < 4 || 0x1c < iVar6) {
            if (iVar6 < 0x1d || 0x27 < iVar6) {
                if (iVar6 < 0x28 || 0x29 < iVar6) {
                    if (iVar6 < 0x2a || 0x2c < iVar6) {
                        *param_2 = '_';
                        fn_800A4BE8(1, 2);
                        return;
                    }
                    uVar4 = (sVar2 + 0xd0) * 0x100 | sVar1 + 0x40U;
                } else {
                    uVar4 = (sVar2 + 0xc5) * 0x100 | sVar1 + 0x40U;
                }
            } else {
                uVar4 = (sVar2 + 0xc3) * 0x100 | sVar1 + 0x40U;
            }
        } else {
            uVar4 = (sVar2 + 0x83) * 0x100 | sVar1 + 0x40U;
        }
    } else {
        uVar4 = (sVar2 + 0x81) * 0x100 | sVar1 + 0x40U;
    }
    param_2[1] = (char)uVar4;
    *param_2 = (char)(uVar4 >> 8);
    fn_800A4BE8(2, 2);
}

#pragma dont_inline reset
extern "C" s32 VFiPFCODE_CP932_OEM2Unicode(s32, u16 *);
extern "C" s16 fn_800B7200(s32 arg0) {
    u16 spC;
    s16 spA;
    s16 sp8;
    s32 result = VFiPFCODE_CP932_OEM2Unicode(arg0, &spC);
    fn_800A4BF4(result, (u16 *)&spA, &sp8);
    return spA;
}

extern "C" s32 VFiPFCODE_CP932_isOEMMBchar(u8 arg0, s32 arg1) {
    if (arg1 == 2) {
        if (arg0 < 0x40) return 0;
        if (arg0 <= 0x7e) return 1;
        if (arg0 < 0x80) return 0;
        if (arg0 <= 0xfc) return 1;
        return 0;
    }
    if (arg1 >= 2) return 0;
    if (arg1 == 1) {
        if (arg0 < 0x81) return 0;
        if (arg0 <= 0x9f) return 1;
        if (arg0 < 0xe0) return 0;
        if (arg0 <= 0xfc) return 1;
    }
    return 0;
}

extern "C" s32 VFiPFCODE_CP932_Unicode2OEM(s32, u32*);
extern "C" s32 fn_800A4BF4(s32, u16*, s16*);
extern "C" s32 fn_800B72E4(void) { return 0; }

extern "C" s32 VFiPFAPI_ParseOpenModeString(char *arg0) {
    s32 mode;
    s32 index;
    signed char first;
    signed char next;
    signed char tail;
    if (arg0 == 0) {
        return 10;
    }
    first = arg0[0];
    index = 1;
    switch (first) {
    case 'r':
        mode = 2;
        break;
    case 'w':
        mode = 1;
        break;
    case 'a':
        mode = 4;
        break;
    default:
        return 0;
    }
    if (arg0[1] == 'b') {
        index = 2;
    }
    next = arg0[index++];
    if (next == '+') {
        goto plus;
    }
    if (next >= '+') {
        goto check_text;
    }
    switch (next) {
    case 0:
        goto return_mode;
    default:
        goto return_zero;
    }
check_text:
    switch (next) {
    case 't':
        goto return_mode;
    default:
        goto return_zero;
    }
return_mode:
    return mode;
return_zero:
    return 0;
plus:
    tail = arg0[index];
    switch (tail) {
    case 0:
        return mode | 8;
    default:
        return 0;
    }
}

#pragma dont_inline on
extern "C" s32 fn_800B73BC(s32 arg0) {
    return (-arg0 | arg0) >> 31;
}
#pragma dont_inline reset

extern "C" s32 fn_800B73CC(s32 arg0, s32 arg1) {
    switch (arg0) {
    default:
        return 0;
    case 0:
        return arg1;
    }
}

extern "C" s32 fn_800B73E4(s32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 == 1) return 1;
    return -1;
}

extern "C" s32 fn_800B73BC(s32);

extern "C" void fn_800B7408(volatile s32* arg0, void* arg1) {
 extern s32 fn_800B6628(void*, void*, s32);
 extern s32 fn_800B73BC(s32);
 extern s32 lbl_803D2140[];
 s32 result;
 s32 entry;
 if ((arg0 == 0) || (*arg0 == 0)) {
   result = 10;
   *(s32*)((u8*)lbl_803D2140 + 0x40) = 10;
 } else {
   entry = *arg0;
   do {
     if (arg1 != 0)
       result = fn_800B6628((void*)entry, arg1, *(s32*)((u8*)arg1 + 0x50));
     else
       result = fn_800B6628((void*)entry, 0, 0);
     if (result != 0) {
       fn_800B73BC(result);
       return;
     }
     arg0 = (volatile s32*)((u8*)arg0 + 4);
     entry = *(volatile s32*)((u8*)arg0);
   } while (entry != 0);
 }
 fn_800B73BC(result);
}

#pragma dont_inline on
extern "C" s32 fn_800B74B8(s8 arg0) {
    fn_800B6928(arg0);
    return ((s32 (*)(void))fn_800B73BC)();
}
#pragma dont_inline reset

extern "C" void* fn_800B1BDC(void*);
extern "C" void fn_800B74E0(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC((s32)fn_800B1BDC(alarm));
}

extern "C" void* fn_800B224C(void*);
extern "C" void fn_800B7504(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC((s32)fn_800B224C(alarm));
}

extern "C" void fn_800B1EB8(s32, s32, s32, s32, s32 *);
extern "C" s32 fn_800B75C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result;
    fn_800B1EB8(arg0, arg1, arg2, arg3, &result);
    return result;
}

extern "C" void* fn_800B1FF4(void*);
extern "C" void fn_800B75EC(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC((s32)fn_800B1FF4(alarm));
}

extern "C" s32 fn_800A4E80(void *, s32, u32);
extern "C" s32 fn_800A9A4C(void *, s32, s32);
extern "C" void fn_800B7610(void *arg0, s32 arg1, s32 arg2) {
    s32 local;
    s32 result = fn_800A4E80(&local, (s32)arg0, 1);
    if (result == 0) {
        fn_800A9A4C(&local, arg1, arg2);
    } else {
        M2C_FIELD(lbl_803D2140, s32 *, 0x40) = result;
    }
    ((void (*)(void))fn_800B73BC)();
}

extern "C" void* fn_800A9B0C(void*);
extern "C" void fn_800B7684(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC((s32)fn_800A9B0C(alarm));
}

#pragma dont_inline on
extern "C" s32 fn_800B76A8(s32 arg0, s32 arg1) {
    s32 result = ((s32 (*)(void))fn_800B0748)();
    if (result == 0) {
        fn_800B78EC();
    }
    return fn_800B73BC(result);
}
#pragma dont_inline reset

extern "C" s32 fn_800B6A8C(s8, s32);
#pragma dont_inline fn_800B76E8
extern "C" s32 fn_800B76E8(s8 arg0) {
    extern void fn_800B73E4(void*);
    ((s32 (*)(s8))fn_800B6A8C)(arg0);
    return ((s32 (*)(void))fn_800B73E4)();
}

extern "C" void fn_800B7710(void *arg0) {
    extern s32 fn_800B7F28(void *);
    struct Args { s32 a; s32 b; void *c; } args;

    if (*(s32 *)arg0 == 0) {
        args.a = 1;
        args.b = 1;
        args.c = (u8 *)arg0 + 0x10;
        *(s32 *)((u8 *)arg0 + 8) = fn_800B7F28(&args);
        *(s32 *)((u8 *)arg0 + 4) = 0;
        *(s32 *)((u8 *)arg0 + 0xC) = 0;
        *(s32 *)arg0 = 1;
    }
}

extern "C" void fn_800B777C(void *arg0) {
    if ((*(u32 *)arg0 & 1) != 0) {
        fn_800B7FC4(*(s32 *)((u8 *)arg0 + 8));
        *(u32 *)arg0 = 0;
    }
}

extern "C" s32 fn_800B77C0(void *arg0) {
    u32 thread;
    s32 count;

    if (*(s32 *)((u8 *)arg0 + 4) == 0) {
        fn_800B8004(*(s32 *)((u8 *)arg0 + 8));
        ((s32 (*)(u32 *))fn_800B7EAC)((u32 *)((u8 *)arg0 + 0xC));
    } else {
        ((s32 (*)(u32 *))fn_800B7EAC)(&thread);
        if (*(u32 *)((u8 *)arg0 + 0xC) != thread) {
            fn_800B8004(*(s32 *)((u8 *)arg0 + 8));
            *(u32 *)((u8 *)arg0 + 0xC) = thread;
        }
    }
    count = *(s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = count + 1;
    return count;
}

extern "C" void fn_800B783C(void *arg0) {
    extern s32 fn_800B8048(s32);
    if (--*(s32 *)((u8 *)arg0 + 4) == 0) {
        *(s32 *)((u8 *)arg0 + 0xc) = 0;
        fn_800B8048(*(s32 *)((u8 *)arg0 + 8));
    }
}

extern void *lbl_8055DD10;
extern "C" void __AXDSPInitCallback_800B7860(void) {
    lbl_8055DD10 = 0;
}

extern "C" void fn_800B786C(void *arg0) {
    void *temp_r3;

    fn_800B8048(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 0x288));
    temp_r3 = *(void **)((u8 *)arg0 + 8);
    if (((s32) *(u16 *)((u8 *)temp_r3 + 0x27E) == 0) && (*(s32 *)((u8 *)temp_r3 + 0x280) == 0) && ((s32) lbl_8055DD10 != 0)) {
        fn_800B7FC4(*(s32 *)((u8 *)temp_r3 + 0x288));
        *(s32 *)((u8 *)temp_r3 + 0x288) = 0;
        lbl_8055DD10 = (void *)((s32) lbl_8055DD10 - 1);
    }
}

void fn_800B78EC(void) {

}

void fn_800B78F0(void) {
    ((void (*)(void))fn_800B7EAC)();
}

extern "C" void fn_800B78F4(void *arg0, void *arg1) {
    OSCalendarTime time;
    OSTicksToCalendarTime(OSGetTime(), &time);
    ((s32 *)arg0)[0] = time.year;
    ((s32 *)arg0)[1] = time.month + 1;
    ((s32 *)arg0)[2] = time.mday;
    ((s32 *)arg1)[0] = time.hour;
    ((s32 *)arg1)[1] = time.min;
    ((s32 *)arg1)[2] = time.sec;
}

extern "C" s32 lbl_80559238;
extern "C" s32 fn_800BA404(void);
extern "C" s32 fn_800B7968(u32 arg0, s32 arg1, s32 arg2, void* arg3) {
    s32 sp8;
    s32 sp10;
    s8 temp;
    if (arg0 >= 4) return -2;
    if (arg3 == 0) return -2;
    if (arg0 == 2 && arg1 == 0) return -2;
    if (arg0 == 3 && *(s32*)arg3 == 0) return -2;
    if (arg0 <= 2) {
        if (((s32 (*)(void*, s32*, s32))fn_800A5958)((u8*)&lbl_80559238 + (arg0 << 3), &sp8, lbl_80559238)) return -1;
        if (fn_800A5994((void*)sp8, 0, (s32*)arg3)) return -1;
    }
    *(void**)(&sp10) = arg3;
    if (arg0 == 2) {
        memcpy((u8*)&sp10 + 8, (void*)arg1, 0x4e);
        *(s32*)((u8*)&sp10 + 0x58) = arg2;
    }
    if (((s32 (*)(volatile s32*, void*))fn_800B7408)((volatile s32*)&sp10, arg0 == 2 ? (u8*)&sp10 + 8 : 0)) return -1;
    temp = *(s8*)((u8*)arg3 + 8);
    if (arg0 <= 2) {
        lbl_80405C30[(s32)temp - 0x41] = sp8;
        lbl_80405C98[(s32)temp - 0x41] = *(s32*)arg3;
        if (arg0 == 0 && fn_800BA404()) *((u8*)sp10 + 9) |= 0x10;
    } else {
        lbl_80405C30[(s32)temp - 0x41] = 0;
        lbl_80405C98[(s32)temp - 0x41] = 0;
    }
    return 0;
}

extern "C" s32 fn_800B7B34(s8 arg0) {
    s32 a = lbl_80405C30[arg0 - 0x41];
    s32 b = lbl_80405C98[arg0 - 0x41];
    if (fn_800B74B8(arg0)) return -1;
    if (a && b) {
        if (fn_800A59CC(b)) return -1;
        if (fn_800A5990(a)) return -1;
    }
    return 0;
}

extern "C" s32 fn_800B7BDC(void) {
    s32 result = ((s32 (*)(void))fn_800B74E0)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7C08(void) {
    s32 result = ((s32 (*)(void))fn_800B7504)();
    return (-result | result) >> 31;
}

extern "C" s32 VFipf2_fopen(void);
extern "C" s32 fn_800B7C34(void) {
    s32 r = VFipf2_fopen();
    if (r == 0) {
        r = 0;
    }
    return r;
}

extern "C" void fn_800B7C60(void) {
    fn_800B75C4();
}

extern "C" s32 fn_800B7C64(void) {
    s32 result = ((s32 (*)(void))fn_800B75EC)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7C90(void) {
    s32 result = ((s32 (*)(void))fn_800B7610)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7CBC(void) {
    s32 result = ((s32 (*)(void))fn_800B7684)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B76A8(s32, s32);
extern "C" s32 lbl_8055DD18;
extern "C" s32 lbl_8055DD1C;
extern "C" s32 lbl_8055DD20;
extern "C" s32 fn_800B7CE8(s32 arg0) {
    s32 temp_r3;
    s32 temp_r3_2;

    if (lbl_8055DD1C == 1) {
        return -1;
    }
    lbl_8055DD1C = 1;
    if (lbl_8055DD20 == 0) {
        temp_r3 = ((s32 (*)(s32, s32))fn_800A5954)(0, 0);
        lbl_8055DD20 = temp_r3 == 0;
        if (temp_r3 != 0) {
            lbl_8055DD1C = 0;
            return -1;
        }
    }
    if (lbl_8055DD18 == 0) {
        temp_r3_2 = fn_800B76A8(arg0, 0);
        lbl_8055DD18 = temp_r3_2 == 0;
        if (temp_r3_2 == -1) {
            lbl_8055DD1C = 0;
            return -1;
        }
    }
    lbl_8055DD1C = 0;
    return 0;
}

extern "C" s32 fn_800B7DB0(s32 arg0, Unk800B7E18Callback arg1, Unk800B7E18Callback arg2) {
    s32 result;
    switch (arg0) {
    case 0:
        lbl_80405D00[0] = arg1;
        lbl_80405D00[1] = arg2;
        result = fn_800BA3F4((Unk800B7E18Callback)fn_800B7E18, fn_800B7E38);
        break;
    default:
        return -2;
    }
    return -((u32)(-result | result) >> 31);
}

extern "C" void fn_800B7E18(u32 arg0) {
    if (lbl_80405D00[0]) lbl_80405D00[0]((u8)arg0);
}

extern "C" void fn_800B7E38(u8 arg0) {
    if (lbl_80405D00[1] != 0)
        ((void (*)(u32))lbl_80405D00[1])((u32)arg0);
}

#pragma dont_inline on
extern "C" s32 fn_800B7E5C(s8 arg0) {
    s32 temp_r3 = fn_800B76E8(arg0);
    s32 result;
    if (temp_r3 == -1) {
        result = -1;
    } else if (temp_r3 == 1) {
        result = 1;
    } else {
        s32 normalized = -temp_r3;
        normalized |= temp_r3;
        result = normalized >> 31;
    }
    return result;
}

extern "C" s32 fn_800B7EAC(s32 *arg0) {
    s32 thread;

    if (arg0 == 0) {
        OSReport(lbl_8031B190);
        return -2;
    }
    thread = (s32)OSGetCurrentThread();
    if (thread == 0) {
        OSReport(lbl_8031B1C0);
        *arg0 = 0;
        return -3;
    }
    *arg0 = thread;
    return 0;
}

#pragma dont_inline reset
extern "C" const char lbl_8031B218[];
extern "C" s32 fn_800B7FC4(s32 arg0) {
    if (arg0 == 0) {
        OSReport(lbl_8031B218);
        return -2;
    }
    return 0;
}

extern "C" void OSReport(const char *, ...);
extern "C" s32 OSWaitSemaphore(void);
extern "C" s32 fn_800B76E8(s8);
extern "C" const char lbl_8031B190[];
extern "C" const char lbl_8031B1C0[];
extern "C" const char lbl_8031B24C[];
#pragma dont_inline
extern "C" s32 fn_800B8004(s32 arg0) {
    if (arg0 == 0) {
        OSReport(lbl_8031B24C);
        return -2;
    }
    OSWaitSemaphore();
    return 0;
}

extern "C" s32 OSSignalSemaphore(void);
extern "C" const char lbl_8031B27C[];
#pragma dont_inline
extern "C" s32 fn_800B8048(s32 arg0) {
    if (arg0 == 0) {
        OSReport(lbl_8031B27C);
        return -2;
    }
    OSSignalSemaphore();
    return 0;
}

#pragma push
#pragma small_data off
extern "C" s32 NANDGetType(char *);
extern "C" s32 NANDOpen(void *, void *, s32);
extern "C" s32 fn_800B814C(void *);
extern "C" s32 fn_800B808C(s32 arg0, void *arg1, s32 arg2) {
    s32 result = NANDGetType((char *)&lbl_80405D18);
    if (result != 0)
        return result;

    if (*(s32 *)((u8 *)arg1 + 0xE4) & 4)
        result = 0;
    else
        result = NANDOpen((u8 *)arg1 + 4, (u8 *)arg1 + 0x58, 3);

    if (arg2 != 0)
        result = -0xC;

    if (result == 0)
        goto success;
    if (result >= 0)
        goto done;

    switch (result) {
    case -0xC:
        goto retry;
    default:
        goto done;
    }

retry:
    result = fn_800B814C(arg1);
    if (result != 0)
        goto done;
    *(s32 *)arg1 = arg0;
    goto done;

success:
    *(s32 *)arg1 = arg0;
    result = 0;
done:
    return result;
}

extern "C" s32 fn_800B814C(void *arg0) {
    extern s32 NANDClose(void *); extern s32 NANDDelete(void *);
    extern s32 fn_800B8318(void); extern s32 fn_800B878C(void *,u8*,s32*,s32);
    extern s32 fn_800B8520(void *,u32 *); extern void fn_800B865C(void *);
    u8 buf2[0x200] __attribute__((aligned(32))), buf0[0x200] __attribute__((aligned(32))), buf1[0x200] __attribute__((aligned(32)));
    s32 type,r; u32 zero,remain;
    if((r=fn_800B8318())!=0)return r;
    fn_800A499C((const char*)buf0,0,0x200); zero=0;
    fn_800B878C(arg0,buf0,&type,0);
    if(type!=fn_800B8520(buf0,&zero))fn_800B878C(arg0,buf0,&type,zero);
    r=NANDWrite((u8*)arg0+0x58,buf0,0x200);
    if(r<0){NANDClose((u8*)arg0+0x58);NANDDelete((u8*)arg0+4);return r;}
    remain=*(u32*)((u8*)arg0+0x54)-0x200;
    if(type==2){
        fn_800B865C(buf1); r=NANDWrite((u8*)arg0+0x58,buf1,0x200);
        if(r<0){NANDClose((u8*)arg0+0x58);NANDDelete((u8*)arg0+4);return r;}
        remain-=0x200;
    }
    fn_800A499C((const char*)buf2,0,0x200);
    while(remain>=0x200){
        r=NANDWrite((u8*)arg0+0x58,buf2,0x200);
        if(r<0){NANDClose((u8*)arg0+0x58);NANDDelete((u8*)arg0+4);return r;}
        remain-=0x200;
    }
    if(remain!=0){
        r=NANDWrite((u8*)arg0+0x58,buf2,remain);
        if(r<0){NANDClose((u8*)arg0+0x58);NANDDelete((u8*)arg0+4);return r;}
    }
    return 0;
}

extern "C" s32 fn_800B8318(void *arg0, s32 arg1) {
 extern s32 NANDCreate(void*,s32,s32); extern s32 NANDGetType(void*); extern s32 NANDOpen(void*,void*,s32); extern s32 NANDPrivateCreateDir(void*,s32,s32); extern s32 fn_800A499C(void*,s32,s32); extern s32 fn_800A4AD0(void*,void*); extern s32 lbl_80559244, lbl_80559240;
 u8 path[0x10]; u16 part=0,total=0; s32 result; u8 *src=(u8*)arg0+4,*dst;
 if(*(u32*)((u8*)arg0+0xE4)&4)return 0;
 fn_800A499C(path,0,0x10); dst=path;
loop:
 switch((s8)*src){
 case '/':
  if(part==0){if(total==0){result=NANDGetType(&lbl_80559240);if(result)return result;}src++;goto copy;}
  if((s8)src[1]==0){if(part>0xC)return -20;result=NANDCreate(path,0x30,0);if(result==0||result==-6){NANDOpen(path,(u8*)arg0+0x58,3);return NANDGetType(&lbl_80405D18);}return result;}
  if(part>0xB)return -20;
  result=fn_800A4AD0(path,&lbl_80559244);if(result)result=NANDPrivateCreateDir(path,0x30,0);else result=0;
  if(result!=0&&result!=-6&&result!=-1)return result;
  result=NANDGetType(path);if(result)return result;
  src++;fn_800A499C(path,0,0x10);dst=path;part=0;goto copy;
 case 0:
  if(part>0xC)return -20;result=NANDCreate(path,0x30,0);
  if(result==0||result==-6){NANDOpen(path,(u8*)arg0+0x58,3);return NANDGetType(&lbl_80405D18);}return result;
 default: break;
 }
copy: *dst++=*src++;part++;total++;goto loop;
}

s32 fn_800B8520(void *arg0, u32 *arg1) {
    u32 countA = 0;
    u32 countB = 0;
    u32 temp = 0x200;
    u32 temp2 = 1;
    u32 value;
    u32 total;
    u32 result;
    u16 a;
    u16 b;
    u32 word;
    u32 start;
    u32 end;

    do {
        temp = (temp >> 1) & 0x7FFF;
        if (temp != 0) countA++;
    } while (temp != 0);
    do {
        temp2 = (temp2 >> 1) & 0x7FFF;
        if (temp2 != 0) countB++;
    } while (temp2 != 0);

    if (((u32)((u8 *)arg0 + 0x11) & 1) != 0) {
        value = *((u8 *)arg0 + 0x11) | (*((u8 *)arg0 + 0x12) << 8);
    } else {
        a = *(u16 *)((u8 *)arg0 + 0x12);
        value = ((a >> 8) | (a << 8)) << 5;
    }
    total = value;
    if (((u32)((u8 *)arg0 + 0x16) & 1) != 0) {
        b = *((u8 *)arg0 + 0x16) | (*((u8 *)arg0 + 0x17) << 8);
    } else {
        b = *(u16 *)((u8 *)arg0 + 0x16);
        b = (b >> 8) | (b << 8);
    }
    start = b;
    if (start == 0) {
        word = *(u32 *)((u8 *)arg0 + 0x24);
        start = ((word >> 24) | ((word >> 8) & 0xFF00) | ((word << 8) & 0xFF0000) | (word << 24));
    }
    if (((u32)((u8 *)arg0 + 0x13) & 1) != 0) {
        b = *((u8 *)arg0 + 0x13) | (*((u8 *)arg0 + 0x14) << 8);
    } else {
        b = *(u16 *)((u8 *)arg0 + 0x14);
        b = (b >> 8) | (b << 8);
    }
    end = b;
    if (end == 0) {
        word = *(u32 *)((u8 *)arg0 + 0x20);
        end = ((word >> 24) | ((word >> 8) & 0xFF00) | ((word << 8) & 0xFF0000) | (word << 24));
    }
    result = end - (start * 2 + ((value + 0x1FF) >> countA) + 1);
    *arg1 = result;
    if ((result >> countB) < 0xFF5) return 0;
    if ((result >> countB) < 0xFFF5) return 1;
    return 2;
}

extern "C" s32 fn_800B865C(u8 *arg0) {
    fn_800A499C((const char *)arg0, 0, 0x200);
    if ((u32)arg0 & 3) {
        arg0[0] = 0x52; arg0[1] = 0x52; arg0[2] = 0x61; arg0[3] = 0x41;
    } else *(u32 *)arg0 = 0x52526141;
    if (((u32)arg0 + 0x1E4) & 3) {
        arg0[0x1E4] = 0x72; arg0[0x1E5] = 0x72; arg0[0x1E6] = 0x41; arg0[0x1E7] = 0x61;
    } else *(u32 *)(arg0 + 0x1E4) = 0x72724161;
    if (((u32)arg0 + 0x1E8) & 3) {
        arg0[0x1E8] = 0xFF; arg0[0x1E9] = 0xFF; arg0[0x1EA] = 0xFF; arg0[0x1EB] = 0xFF;
    } else *(u32 *)(arg0 + 0x1E8) = 0xFFFFFFFF;
    if (((u32)arg0 + 0x1EC) & 3) {
        arg0[0x1EC] = 0xFF; arg0[0x1ED] = 0xFF; arg0[0x1EE] = 0xFF; arg0[0x1EF] = 0xFF;
    } else *(u32 *)(arg0 + 0x1EC) = 0xFFFFFFFF;
    if (((u32)arg0 + 0x1FC) & 3) {
        arg0[0x1FC] = 0; arg0[0x1FD] = 0; arg0[0x1FE] = 0x55; arg0[0x1FF] = 0xAA;
    } else *(u32 *)(arg0 + 0x1FC) = 0x55AA;
    return 0;
}

extern "C" s32 fn_800B878C(void *arg0, u8 *buf, s32 *type, s32 size) {
    u32 n = size ? (u32)size : *(u32 *)((u8 *)arg0 + 0x54) >> 9;
    s32 kind, aligned;
    u32 clusters;
    if (n < 0xFF5) { kind=0; clusters=(((n<<2)-n)>>1)+0x1FF; clusters>>=9; }
    else if (n < 0xFFF5) { kind=1; clusters=((n<<1)+0x1FF)>>9; }
    else { kind=2; clusters=((n<<2)+0x1FF)>>9; }
    fn_800A499C((const char *)buf,0,0x200);
    buf[0]=0xEB;buf[2]=0x90;buf[0x1FE]=0x55;buf[0x1FF]=0xAA;
    if ((u32)(buf+0x18)&1) {buf[0x18]=0x3F;buf[0x19]=0;} else *(u16*)(buf+0x18)=0x3F00;
    if ((u32)(buf+0x1A)&1) {buf[0x1A]=0xFF;buf[0x1B]=0;} else *(u16*)(buf+0x1A)=0xFF00;
    if ((u32)(buf+0xB)&1) {buf[0xB]=0;buf[0xC]=2;} else *(u16*)(buf+0xC)=2;
    buf[0xD]=1;
    if ((u32)(buf+0xE)&1) {buf[0xE]=1;buf[0xF]=0;} else *(u16*)(buf+0xE)=0x100;
    aligned=(u32)(buf+0x11)&1;buf[0x10]=2;
    if(aligned){buf[0x11]=0x80;buf[0x12]=0;}else *(u16*)(buf+0x12)=0x8000;
    buf[0x15]=0xF0;
    if(n<0x10000) {
      if((u32)(buf+0x13)&1){buf[0x13]=n;buf[0x14]=n>>8;}else *(u16*)(buf+0x14)=((n&0xFF)<<8)|(n>>8);
      if((u32)(buf+0x20)&3){buf[0x20]=buf[0x21]=buf[0x22]=buf[0x23]=0;}else *(u32*)(buf+0x20)=0;
    } else {
      if((u32)(buf+0x13)&1){buf[0x13]=0;buf[0x14]=0;}else *(u16*)(buf+0x14)=0;
      if((u32)(buf+0x20)&3){buf[0x20]=n;buf[0x21]=n>>8;buf[0x22]=n>>16;buf[0x23]=n>>24;}
      else *(u32*)(buf+0x20)=((n&0xFF)<<24)|((n&0xFF00)<<8)|((n>>8)&0xFF00)|(n>>24);
    }
    if(kind==2){
      if(aligned){buf[0x11]=buf[0x12]=0;}else *(u16*)(buf+0x12)=0;
      if((u32)(buf+0x24)&3){buf[0x24]=clusters;buf[0x25]=clusters>>8;buf[0x26]=clusters>>16;buf[0x27]=clusters>>24;}
      else *(u32*)(buf+0x24)=((clusters&0xFF)<<24)|((clusters&0xFF00)<<8)|((clusters>>8)&0xFF00)|(clusters>>24);
      if((u32)(buf+0x28)&1){buf[0x28]=buf[0x29]=0;}else *(u16*)(buf+0x28)=0;
      if((u32)(buf+0x2A)&1){buf[0x2A]=buf[0x2B]=0;}else *(u16*)(buf+0x2A)=0;
      if((u32)(buf+0x2C)&3){buf[0x2C]=2;buf[0x2D]=buf[0x2E]=buf[0x2F]=0;}else *(u32*)(buf+0x2C)=0x02000000;
      if((u32)(buf+0x30)&1){buf[0x30]=1;buf[0x31]=0;}else *(u16*)(buf+0x30)=0x100;
      buf[0x41]=0;buf[0x42]=0x29;
      if((u32)(buf+0x43)&3){buf[0x43]=0x34;buf[0x44]=0x12;buf[0x45]=buf[0x46]=0;}else *(u32*)(buf+0x4C)=0x34120000;
    }else{
      if(aligned){buf[0x11]=0x80;buf[0x12]=0;}else *(u16*)(buf+0x12)=0x8000;
      if((u32)(buf+0x16)&1){buf[0x16]=clusters;buf[0x17]=clusters>>8;}else *(u16*)(buf+0x16)=((clusters&0xFF)<<8)|(clusters>>8);
      buf[0x25]=0;buf[0x26]=0x29;
      if((u32)(buf+0x27)&3){buf[0x27]=0x34;buf[0x28]=0x12;buf[0x29]=buf[0x2A]=0;}else *(u32*)(buf+0x30)=0x34120000;
    }
    *type=kind;return 0;
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" s32 fn_800B8BE8(s32 arg0) { if (!arg0) return -0x14; if (!lbl_8055DD2C) { if (NANDInit()) return -0x15; if (NANDGetCurrentDir((char *)&lbl_80405D18)) return -0x15; ++lbl_8055DD2C; } fn_800A68DC(arg0); return 0; }

extern "C" s32 fn_800B808C(s32, void *, s32);
extern "C" unsigned char lbl_80405D58[];
extern "C" s32 fn_800B8C74(s32 arg0) {
    unsigned char *entry;
    unsigned char *found = 0;
    s32 i;
    s32 result;
    fn_800B8004(lbl_8055DD30);
    if (arg0 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -20;
    }
    for (i = 0; i < 0x17; i++) {
        entry = lbl_80405D58 + i * 0xF0;
        if (*(s32 *)entry == arg0) break;
    }
    if (i < 0x17 && (*(s32 *)(entry + 0xE4) & 2)) {
        fn_800B8048(lbl_8055DD30);
        return -21;
    }
    for (i = 0; i < 0x17; i++) {
        entry = lbl_80405D58 + i * 0xF0;
        if (*(s32 *)entry == arg0 && !(*(s32 *)(entry + 0xE4) & 2)) { found = entry; break; }
    }
    if (!found) for (i = 0; i < 0x17; i++) {
        entry = lbl_80405D58 + i * 0xF0;
        if (*(s32 *)entry == 0 && *(signed char *)(entry + 4) != 0) { found = entry; break; }
    }
    if (!found) { fn_800B8048(lbl_8055DD30); return -22; }
    if (*(s32 *)found != 0) result = 0;
    else result = fn_800B808C(arg0, found, 0);
    if (result == 0) *(s32 *)(found + 0xE4) |= 2;
    fn_800B8048(lbl_8055DD30);
    return result;
}

s32 fn_800B8E28(s32 arg0) {
    u32 temp;
    s32 temp_r30;
    s32 var_ctr;
    u16 index;
    void *entry;
    entry = 0;
    fn_800B8004(lbl_8055DD30);
    if (arg0 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    index = 0;
    var_ctr = 0x17;
loop:
    temp = index * 0xF0;
    if ((u32)*((u8 *)&lbl_80405D58 + temp) == (u32)arg0) {
        entry = (u8 *)&lbl_80405D58 + temp;
    } else {
        index += 1;
        var_ctr -= 1;
        if (var_ctr != 0) goto loop;
    }
    if (-0x16 & ((s32)~((index - 0x17) | (0x17 - index)) >> 31)) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    M2C_FIELD(entry, s32 *, 0xE4) |= 4;
    temp_r30 = fn_800B808C(arg0, entry, 1);
    M2C_FIELD(entry, s32 *, 0xE4) &= 0xFFFFFFFB;
    fn_800B8048(lbl_8055DD30);
    return temp_r30;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_800B8F20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    s32 result;
    fn_800B8004(lbl_8055DD30);
    *arg4 = 0;
    if (arg0 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    if (arg1 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    result = fn_800B960C(arg3, arg1, arg2, 0x200, arg4, arg0);
    if (result != 0) {
        fn_800B8048(lbl_8055DD30);
        return result;
    }
    fn_800B8048(lbl_8055DD30);
    return 0;
}
#pragma dont_inline reset
extern "C" s32 fn_800B98F8(s32, s32, s32, s32, s32 *, s32);
#pragma dont_inline on
extern "C" s32 fn_800B8FE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    s32 result;
    fn_800B8004(lbl_8055DD30);
    *arg4 = 0;
    if (arg0 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    if (arg1 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    result = fn_800B98F8(arg3, arg1, arg2, 0x200, arg4, arg0);
    if (result != 0) {
        fn_800B8048(lbl_8055DD30);
        return result;
    }
    fn_800B8048(lbl_8055DD30);
    return 0;
}

extern "C" s32 fn_800B90A8(s32 arg0) {
    s32 result;
    u32 length;
    u32 i;
    u8 *entry;
    entry = 0;
    fn_800B8004(lbl_8055DD30);
    if (arg0 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -20;
    }
    for (i = 0; i < 0x17; i++) {
        u8 *cur = lbl_80405D58 + i * 0xF0;
        if (*(u32 *)cur == (u32)arg0) {
            *(s32 *)(cur + 0xEC) = 0;
            break;
        }
    }
    result = (i == 0x17) ? 0 : -0x16;
    if (result == 0) {
        for (i = 0; i < 0x17; i++) {
            u8 *cur = lbl_80405D58 + i * 0xF0;
            if (*(u32 *)cur == (u32)arg0) { entry = cur; break; }
        }
        if (i == 0x17) { fn_800B8048(lbl_8055DD30); return -20; }
        *(u32 *)(entry + 0xE4) &= ~2;
        result = NANDGetLengthAsync(entry + 0x58, &length);
        if (result == 0) {
            result = NANDClose(entry + 0x58);
            if (result >= 0) {
                result = NANDOpen(entry + 4, entry + 0x58, 3);
                if (result >= 0) {
                    result = NANDSeek(entry + 0x58, length, 0);
                    result &= result >> 31;
                }
            }
        }
        if (result < 0) {
            for (i = 0; i < 0x17; i++) {
                u8 *cur = lbl_80405D58 + i * 0xF0;
                if (*(u32 *)cur == (u32)arg0) { *(s32 *)(cur + 0xEC) = result; break; }
            }
            fn_800B8048(lbl_8055DD30);
            return result;
        }
    }
    fn_800B8048(lbl_8055DD30);
    return result;
}

extern "C" s32 NANDClose(void *);
extern "C" s32 fn_800B92A8(s32 arg0) {
    u8 *entry;
    s32 closeResult = 0;
    u16 index;

    fn_800B8004(lbl_8055DD30);
    if (arg0 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }

    for (index = 0; index < 0x17; index++) {
        entry = (u8 *)lbl_80405D58 + index * 0xF0;
        if (*(u32 *)entry == (u32)arg0) {
            closeResult = NANDClose(entry + 0x58);
            fn_800A499C((const char *)entry, 0, 0xF0);
            break;
        }
    }

    fn_800B8048(lbl_8055DD30);
    if (closeResult != 0) {
        return -0x14;
    }
    return index == 0x17 ? -0x16 : 0;
}

extern "C" u8 lbl_80405D58[];
s32 fn_800B9394(s32 arg0, void *arg1) {
    s32 i;
    u32 size;
    u32 q;
    u32 q2;
    u32 temp;
    u32 divisor;
    u32 remainder;
    void *entry = 0;

    fn_800B8004(lbl_8055DD30);
    if (arg0 == 0 || arg1 == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    for (i = 0; i < 0x17; i++) {
        entry = lbl_80405D58 + i * 0xF0;
        if (*(s32 *)entry == arg0) break;
        entry = 0;
    }
    if (entry == 0) {
        fn_800B8048(lbl_8055DD30);
        return -0x14;
    }
    size = *(u32 *)((u8 *)entry + 0x54);
    q = size >> 9;
    *(u8 *)((u8 *)arg1 + 7) = 0x3F;
    *(u8 *)((u8 *)arg1 + 6) = 0xFF;
    *(u32 *)((u8 *)arg1 + 0xC) = 0;
    divisor = (u32)(((u64)size * 0x80808081ULL) >> 39);
    *(u32 *)((u8 *)arg1 + 0x10) = 0;
    q2 = (u32)(((u64)divisor * 0x4104105ULL) >> 32);
    *(u32 *)arg1 = q;
    *(u16 *)((u8 *)arg1 + 8) = 0x200;
    temp = (q2 - q) >> 1;
    remainder = (temp + q2) >> 14;
    *(u16 *)((u8 *)arg1 + 4) = remainder;
    fn_800B8048(lbl_8055DD30);
    return 0;
}

#pragma dont_inline reset

extern "C" u8 lbl_802F31F8[];
extern "C" s32 lbl_8055DD2C;
extern "C" s32 NANDInit(void);
extern "C" s32 NANDGetCurrentDir(char *);
extern "C" const char lbl_8031B190[];
extern "C" const char lbl_8031B1C0[];
extern "C" s32 fn_800B76E8(s8);
extern "C" s32 fn_800B94D4(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(u8 **)arg0 = lbl_802F31F8;
    return 0;
}

extern "C" s32 fn_800B94EC(s32 arg0, s32 arg1) {
    /* Fix note: keep the slot counter full-width between scans and truncate only its table index. */
    u8 *base = (u8 *)lbl_80405D18;
    u32 initCount;
    u32 i;

    if ((u32)fn_800A4A8C(arg0) >= 0x4C)
        return -0x14;
    if (lbl_8055DD28 == 0) {
        fn_800A499C((const char *)(base + 0x40), 0, 0x1590);
        volatile u32 *control = (volatile u32 *)(base + 0x15D0);
        initCount = lbl_8055DD28 + 1;
        *(s32 *)(base + 0x15D0) = 1;
        lbl_8055DD28 = initCount;
        control[1] = 1;
        control[2] = (u32)(base + 0x15DC);
        typedef s32 (*InitFn)(void *, s32, s32);
        s32 result = ((InitFn)fn_800B7F28)((void *)control, 1, initCount);
        lbl_8055DD30 = result;
        if (result == 0)
            return -0x15;
    }

    base += 0x40;
    i = 0;
loop_6:
    u8 *entry = base + (u32)(u16)i * 0xF0;
    if (fn_800A4AD0(entry + 4, (u8 *)arg0) == 0)
        return 0;
    if (*(s32 *)entry == 0) {
        fn_800A4AAC((char *)(entry + 4), (char *)arg0);
        *(s32 *)(entry + 0x54) = arg1;
        goto block_11;
    }
    ++i;
    if (i < 0x17)
        goto loop_6;
block_11:
    return -0x16 & ((s32)~(((s32)(u16)i - 0x17) | (0x17 - (s32)(u16)i)) >> 31);
}

extern "C" s32 fn_800B960C(s32 a0, s32 a1, s32 a2, s32 a3, s32 *out, s32 key) {
    NandEntry *base = (NandEntry *)lbl_80405D58;
    NandEntry *e = 0;
    s32 i;
    s32 n, off, len, res;
    u32 sp20;
    u8 buf[0x200];

    for (i = 0; i < 0x17; i++) {
        if (base[i].key == key) {
            e = &base[i];
            break;
        }
    }
    if (i == 0x17)
        return -0x14;

    n = a0 * a3;
    len = e->length;
    off = a2 * a3;
    if (NANDGetLengthAsync(&e->nand[0], &sp20) != 0 || sp20 != (u32)off)
        res = NANDSeek(&e->nand[0], off, 0);
    else
        res = 0;

    if (res < 0) {
        for (i = 0; i < 0x17; i++)
            if (base[i].key == key) {
                base[i].error = res;
                break;
            }
        return res;
    }

    if ((u32)(off + n) > len) {
        n = len - off;
        off = 0;
        while (n >= 0x200) {
            res = NANDRead(&e->nand[0], buf, 0x200);
            if (res < 0)
                return -0x16;
            VFipf_memcpy((u8 *)a1 + off, buf, res);
            off += res;
            n -= res;
        }
        if (n != 0) {
            res = NANDRead(&e->nand[0], buf, n);
            if (res < 0)
                return -0x16;
            VFipf_memcpy((u8 *)a1 + off, buf, res);
        }
        return -0x16;
    } else {
        off = 0;
        while (n >= 0x200) {
            res = NANDRead(&e->nand[0], buf, 0x200);
            if (res < 0) {
                for (i = 0; i < 0x17; i++)
                    if (base[i].key == key) {
                        base[i].error = res;
                        break;
                    }
                return res;
            }
            VFipf_memcpy((u8 *)a1 + off, buf, res);
            off += res;
            n -= res;
        }
        if (n != 0) {
            res = NANDRead(&e->nand[0], buf, n);
            if (res < 0) {
                for (i = 0; i < 0x17; i++)
                    if (base[i].key == key) {
                        base[i].error = res;
                        break;
                    }
                return res;
            }
            VFipf_memcpy((u8 *)a1 + off, buf, res);
        }
        *out = a0;
        return 0;
    }
}

extern "C" s32 fn_800B98F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    s32 status;
    u32 filelen;
    u32 pos;
    u32 length;
    u32 cur;
    s32 r;
    u32 remain;
    u32 done;
    unsigned char *entry;
    u16 i;
    unsigned char buf[0x200] __attribute__((aligned(32)));

    entry = 0;
    for (i = 0; i < 0x17; i++) {
        if (*(u32 *)(lbl_80405D58 + i * 0xF0) == (u32)arg5) {
            entry = lbl_80405D58 + i * 0xF0;
            break;
        }
    }
    if (i == 0x17) {
        status = -0x16;
    } else {
        status = 0;
    }
    if (status != 0) {
        return -0x14;
    }

    length = arg0 * arg3;
    filelen = *(u32 *)(entry + 0x54);
    pos = arg2 * arg3;

    if (NANDGetLengthAsync(entry + 0x58, &cur) != 0 || cur != pos) {
        r = NANDSeek(entry + 0x58, pos, 0);
    } else {
        r = 0;
    }
    if (r < 0) goto fail;

    if (pos + length > filelen) {
        remain = filelen - pos;
        done = 0;
        while (remain >= 0x200) {
            VFipf_memcpy(buf, (u8 *)arg1 + done, 0x200);
            r = NANDWrite(entry + 0x58, buf, 0x200);
            if (r < 0) return -0x16;
            remain -= r;
            done += r;
        }
        if (remain != 0) {
            VFipf_memcpy(buf, (u8 *)arg1 + done, remain);
            NANDWrite(entry + 0x58, buf, remain);
        }
        return -0x16;
    }

    done = 0;
    while (length >= 0x200) {
        VFipf_memcpy(buf, (u8 *)arg1 + done, 0x200);
        r = NANDWrite(entry + 0x58, buf, 0x200);
        if (r < 0) {
            for (i = 0; i < 0x17; i++) {
                if (*(u32 *)(lbl_80405D58 + i * 0xF0) == (u32)arg5) {
                    *(s32 *)(lbl_80405D58 + i * 0xF0 + 0xEC) = r;
                    break;
                }
            }
            return r;
        }
        length -= r;
        done += r;
    }
    if (length != 0) {
        VFipf_memcpy(buf, (u8 *)arg1 + done, length);
        r = NANDWrite(entry + 0x58, buf, length);
        if (r < 0) {
            for (i = 0; i < 0x17; i++) {
                if (*(u32 *)(lbl_80405D58 + i * 0xF0) == (u32)arg5) {
                    *(s32 *)(lbl_80405D58 + i * 0xF0 + 0xEC) = r;
                    break;
                }
            }
            return r;
        }
    }
    *arg4 = arg0;
    return 0;

fail:
    for (i = 0; i < 0x17; i++) {
        if (*(u32 *)(lbl_80405D58 + i * 0xF0) == (u32)arg5) {
            *(s32 *)(lbl_80405D58 + i * 0xF0 + 0xEC) = r;
            break;
        }
    }
    return r;
}

extern "C" s32 fn_800BC474(s32 *, s32, s32 *);
extern "C" u8 fn_800BA974(s32, u8 *, s32);
extern "C" s32 fn_800B9CC4(s32);
extern "C" s32 lbl_8055DD60;
extern "C" const char lbl_8031B2B0[];
extern "C" s32 fn_800B9BB4(s32 arg0) {
    u8 value;
    if ((arg0 & 1) != 1)
        return 0;

    if (*(volatile s32 *)((u8 *)lbl_80407300 + 8) != 0) {
        lbl_8055DD60 = 2;
        if (fn_800BC474((s32 *)*(volatile s32 *)((u8 *)lbl_80407300 + 8),
                        (s32)fn_800B9CC4, &lbl_8055DD60) != 0)
            OSReport(lbl_8031B2B0);
    }

    if (*(volatile s32 *)((u8 *)lbl_80407300 + 0xC) != 0) {
        if (*(volatile s8 *)((u8 *)lbl_80407300 + 0x14) == 0 &&
            (*fn_800BA974)(*(volatile s32 *)((u8 *)lbl_80407300 + 0xC), &value, 1) == 1)
            *(volatile u8 *)((u8 *)lbl_80407300 + 0x14) = value;

        {
            u8 *after = lbl_80407300;
            fn_800A68DC(*(volatile s32 *)(after + 0xC));
            if (*(volatile s8 *)(after + 0x14) != 0 && lbl_8055DD40 != 0)
                ((void (*)(s8))lbl_8055DD40)(*(volatile s8 *)(after + 0x14));
        }
    }

    *(volatile s32 *)((u8 *)lbl_80407300 + 0x10) = 1;
    return 0;
}

extern "C" const char lbl_8031B2EC[];
#pragma dont_inline on
extern "C" s32 fn_800B9CC4(s32 arg0) {
    u8 value;

    if ((arg0 & 2) != 2)
        return 0;

    *(volatile s32 *)(lbl_80407300 + 0x10) = 0;
    if (*(volatile s32 *)(lbl_80407300 + 8) != 0) {
        lbl_8055DD60 = 1;
        if (fn_800BC474((s32 *)*(volatile s32 *)(lbl_80407300 + 8), (s32)fn_800B9BB4, &lbl_8055DD60) != 0)
            OSReport(lbl_8031B2EC);
    }
    if (*(volatile s32 *)(lbl_80407300 + 0xC) != 0) {
        if (*(volatile s8 *)(lbl_80407300 + 0x14) == 0 &&
            (*fn_800BA974)(*(volatile s32 *)(lbl_80407300 + 0xC), &value, 1) == 1)
            *(volatile u8 *)(lbl_80407300 + 0x14) = value;
        fn_800A68C8((void *)*(volatile s32 *)(lbl_80407300 + 0xC));
        if (*(volatile s8 *)(lbl_80407300 + 0x14) != 0 && lbl_8055DD44 != 0)
            ((void (*)(s8))lbl_8055DD44)(*(volatile s8 *)(lbl_80407300 + 0x14));
    }
    return 0;
}
#pragma dont_inline reset
extern "C" s32 fn_800BA160(s32 arg0) {
    register s32 result;
    register s32 value;
    register s32 mask;
    if (arg0 == 0) return 1;
    result = 6;
    value = *(volatile s32 *)((u8 *)lbl_80407300 + 0x10);
    mask = -value | value;
    mask >>= 31;
    result &= ~mask;
    return result;
}
#pragma push
#pragma small_data off
extern "C" u32 lbl_8031C2B8[];
extern "C" u32 lbl_802F3F54[];
extern "C" s32 fn_800BA194(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 a4;
    s32 val;
    a4 = arg4;
    if (arg0 == 0 || arg1 == 0 || a4 == 0) {
        return 1;
    }
    val = *(s32 *)(lbl_80407300 + 4);
    return fn_800BA49C(arg3, arg1, arg2, val, (s32 *)arg4);
}

extern "C" s32 fn_800BA688(void *, s32, s32, s32, s32 *);
extern "C" s32 fn_800BA1CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 val;
    if (arg0 == 0 || arg1 == 0 || arg4 == 0) return 1;
    val = *(s32 *)(lbl_80407300 + 4);
    return fn_800BA688((void *)arg3, arg1, arg2, val, (s32 *)arg4);
}

extern "C" s32 fn_800BA204(s32 arg0) {
    u32 flags;

    if (arg0 == 0) {
        return 1;
    }
    flags = *(volatile u32 *)lbl_80407300;
    if (flags & 2) {
        *(volatile s32 *)lbl_80407300 &= 0xFFFFFFFD;
    }
    return 0;
}

extern "C" s32 fn_800BA238(s32 arg0) {
    u32 flags;
    if (arg0 == 0) return 1;
    flags = *(volatile u32 *)lbl_80407300;
    if (flags & 2) *(volatile u32 *)lbl_80407300 &= 0xFFFFFFFD;
    (void)*(volatile u32 *)lbl_80407300;
    flags = *(volatile u32 *)lbl_80407300;
    *(volatile u32 *)lbl_80407300 = flags & ~1U;
    *(volatile u32 *)((u8 *)lbl_80407300 + 0xC) = 0;
    *(volatile u8 *)((u8 *)lbl_80407300 + 0x14) = 0;
    return 0;
}

extern "C" u8 lbl_802F3218[];
extern "C" s32 fn_800BA3DC(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(u8 **)arg0 = lbl_802F3218;
    return 0;
}

extern "C" s32 fn_800BA3F4(Unk800B7E18Callback arg0, Unk800B7E18Callback arg1) {
    lbl_8055DD40 = arg0;
    lbl_8055DD44 = arg1;
    return 0;
}

extern "C" s32 fn_800BA404(void) {
    u8 value;
    if (*(u32*)lbl_80407300 & 1) {
        if (*(s8*)(lbl_80407300 + 0x14) == 0 &&
            (*fn_800BA974)(*(s32*)(lbl_80407300 + 0xC), &value, 1) == 1) {
            lbl_80407300[0x14] = value;
        }
        if (*(s32*)(lbl_80407300 + 0x10) != 0) {
            fn_800A68DC(*(s32*)(lbl_80407300 + 0xC));
            return 1;
        }
        return 0;
    }
    return 0;
}

#pragma dont_inline on
extern "C" u8 fn_800BA974(s32 arg0, u8 *arg1, s32 arg2) {
    register u8 count;
    register u8 *out;
    register u8 *record;
    register u32 i;
    register u8 *groupBase;
    register u32 j;

    if (arg1 != 0) {
        if (arg2 == 0)
            return 0;
    }

    record = (u8 *)lbl_803D1640 + 0x61C;
    groupBase = (u8 *)lbl_803D2140;
    out = arg1;
    count = 0;
    for (i = 0; i < 0x1A; i++) {
        if (fn_800A71C4((u32 *)record) != 0 &&
            *(u32 *)(record + 4) == (u32)arg0) {
            register u8 *group = groupBase + 0xA0;
            for (j = 0; j < 13; j++, group += 0x3F90) {
                if (*(u32 *)(group + 0x1FBC) == (u32)record) {
                    count++;
                    *out++ = *(u8 *)(group + 0x1F8E);
                    if ((u32)count == (u32)arg2)
                        break;
                }
                if (*(u32 *)(group + 0x3F84) == (u32)record) {
                    count++;
                    *out++ = *(u8 *)(group + 0x3F56);
                    if ((u32)count == (u32)arg2)
                        break;
                }
            }
            if ((u32)count == (u32)arg2)
                break;
        }
        record += 0x28;
    }
    return count;
}
#pragma dont_inline reset

extern "C" s32 fn_800BB4B0(s32,s32,s32,s32);
extern "C" s32 fn_800BB4C8(s32,s32,s32,s32);
extern "C" u8 lbl_80407360[];
extern "C" s32 fn_800BA49C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s32 temp_r9, var_r25, var_r30, var_r24, temp_r3;
    var_r30=arg1;
    if (!(*(u32 *)lbl_80407300&2)) {*arg4=0; return 0xF;}
    temp_r9=arg0*arg3;
    if (!temp_r9) {*arg4=0; return 1;}
    var_r25=arg2*arg3; *arg4=-1;
    if (!(arg1&0x1F)) {
        if (*(s32 *)(lbl_80407300+0x10)==0) {*arg4=0; return 6;}
        if (arg0==1) temp_r3=fn_800BB4B0(*(s32 *)(lbl_80407300+8),var_r25,var_r30,temp_r9);
        else temp_r3=fn_800BB4C8(*(s32 *)(lbl_80407300+8),var_r25,var_r30,temp_r9);
        if (temp_r3) {if(arg0==1) OSReport(lbl_8031B2B0+0x398,temp_r3); else OSReport(lbl_8031B2B0+0x3E0,temp_r3); *arg4=0; return 0x15;}
        *arg4=arg0; return 0;
    }
    var_r24=0;
    do {
        if(var_r24>=arg0){*arg4=arg0;return 0;}
        if(*(s32 *)(lbl_80407300+0x10)==0){if(var_r24){*arg4=var_r24;return 0;}*arg4=0;return 6;}
        temp_r3=fn_800BB4B0(*(s32 *)(lbl_80407300+8),var_r25,(s32)lbl_80407360,arg3);
        if(temp_r3){OSReport(lbl_8031B2B0+0x428,temp_r3);if(var_r24){*arg4=var_r24;return 0;}*arg4=0;return 0x15;}
        VFipf_memcpy((void *)var_r30,lbl_80407360,arg3);
        var_r30+=arg3;var_r25+=arg3;var_r24++;
    } while(var_r24<arg0);
    *arg4=arg0;return 0;
}

struct IosDevice;
extern "C" s32 fn_800BBEA4(IosDevice *, s32, s32 *, s32);
extern "C" const char lbl_8031B7F8[];
extern "C" s32 fn_800BA874(u32 *outSize, u16 *outBlockSize) {
    u32 info[4];
    u32 word0;
    u32 one;
    u32 word1;
    u16 scale;
    u16 factor;
    u16 exponent;
    u16 shift;
    u16 multiplier;
    u32 mantissa;
    u32 size;
    s32 result;

    fn_800A499C((const char *)info, 0, 0x10);
    result = fn_800BBEA4((IosDevice *)M2C_FIELD(lbl_80407300, void **, 8), 9, (s32 *)info, 0x10);
    if (result != 0) {
        OSReport(lbl_8031B7F8);
        return 0x15;
    }

    word0 = info[1];
    one = 1;
    word1 = info[2];
    scale = 9;
    factor = one << (((word0 >> 7) & 7) + 2);
    exponent = (word1 >> 8) & 0xF;
    mantissa = (word0 >> 22) + ((word1 & 3) << 20);
    mantissa++;
    size = mantissa * factor;
    if (exponent >= 9) {
        scale = exponent;
        if (scale > 0xB)
            scale = 0xB;
    }
    shift = scale - 9;
    multiplier = one << shift;
    *outSize = size * multiplier;
    *outBlockSize = 0x200;
    return 0;
}

extern "C" s32 fn_800BABD0(void *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    const char *str = lbl_8031B838;
    s32 result;

    if (lbl_80559248 < 0) {
        result = (s32)0xC1000000;
    } else {
        *(s32 *)lbl_8055DD7C = arg1;
        *(s32 *)((u8 *)lbl_8055DD7C + 0xC) = arg3;
        *(s32 *)((u8 *)lbl_8055DD7C + 0x10) = 0;
        if (arg2 != 0) {
            result = IOS_Ioctl(*(s32 *)arg0, 2, lbl_8055DD7C, 0x18, lbl_8055DD70, 4);
            if (result != 0) {
                OSReport(str + 0x74);
                result = (s32)0xC1000000;
            } else {
                *arg2 = *lbl_8055DD70;
            }
        } else {
            OSReport(str + 0x90);
            result = (s32)0xC1000000;
        }
    }
    if (result != 0) {
        OSReport(str + 0xAC, str + 0x60, result);
    }
    return result;
}

extern "C" s32 fn_800BAD9C(void *arg0, u32 *arg1) {
    const char *str = lbl_8031B838;
    s32 result = (s32)0xC1000000;

    if (lbl_80559248 >= 0 && arg1 != 0) {
        OSLockMutex(lbl_80407560);
        if (lbl_8055DD6C != 0) {
            OSUnlockMutex(lbl_80407560);
        } else {
            lbl_8055DD6C = 1;
            OSUnlockMutex(lbl_80407560);
            result = IOS_Ioctl(*(s32 *)arg0, 0xB, 0, 0, lbl_8055DD70, 4);
            if (result != 0) {
                OSReport(str + 0x124);
                lbl_8055DD6C = 0;
            } else {
                *arg1 = *lbl_8055DD70;
                lbl_8055DD6C = 0;
            }
        }
    }

    if (result != 0) {
        OSReport(str + 0xAC, str + 0x110, result);
    }
    return result;
}

  extern "C" s32 fn_800BB3F4(s32 arg0) {
    u8 buffer[0x28];
    void* context = buffer;
    u32 flags;
    s32 result = -0x33;
    if (lbl_80559248 >= 0 && fn_800BBB58(arg0, &context) == 0) {
        if (fn_800BAD9C(context, &flags) == 0) {
            if (flags & 0x10000) result = 0;
            else {
                result = fn_800BB2C4(context);
                if (lbl_8055DD68 == 0x10000) result = 0;
            }
        }
        void* closeContext = context;
        *(s32*)((u8*)closeContext + 0x24) = 0;
        IOS_Close(*(s32*)closeContext);
        *(s32*)closeContext = -1;
    }
    return result;
}

extern "C" s32 fn_800BB4E0(s32,s32,s32,s32,s32,s32);
extern "C" s32 fn_800BBB58(s32, void**);
extern "C" s32 fn_800BAD9C(void*, u32*);
extern "C" s32 fn_800BB2C4(void*);
extern "C" s32 IOS_Close(s32);
extern "C" u8 fn_800BA974(s32,u8*,s32);
extern "C" void fn_800A68DC(s32);
extern "C" s32 lbl_80559248;
extern "C" u32 lbl_8055DD68;
extern "C" u8 lbl_80407300[];
extern "C" s32 fn_800BB4B0(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB4E0(a,b,c,d,0,0);
}

extern "C" s32 lbl_8055DD6C;
extern "C" s32 *lbl_8055DD70;
extern "C" s32 lbl_8055DD78;
extern "C" void *lbl_8055DD7C;
extern "C" u8 lbl_80407560[0x18];
extern "C" const char lbl_8031B838[];
extern "C" s32 fn_800BB0A8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_800BC134(void *, s32, s32);
extern "C" s32 IOS_Ioctl(s32, s32, void *, s32, void *, s32);
extern "C" void DCFlushRange(void *, u32);
extern "C" s32 fn_800BB81C(s32,s32,s32,s32,s32,s32);
extern "C" s32 fn_800BB4BC(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB81C(a,b,c,d,0,0);
}

extern "C" s32 fn_800BB4C8(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB4E0(a,b,c,d,0,0);
}

extern "C" s32 fn_800BB4D4(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB81C(a,b,c,d,0,0);
}

extern "C" s32 fn_800BB81C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
const char *str=lbl_8031B838;
u32 var_r30=0x200;
if((u32)arg3<=0x200)var_r30=(u32)arg3;
u32 var_r29=(u32)arg3>>9;
s32 var_r20, sp28[4], sp18[4]; void* dev=(void*)arg0;
if(lbl_80559248<0) var_r20=(s32)0xC1000000;
else if((u32)arg3!=var_r30*var_r29){OSReport(str+0x3B0,str+0x438,(u32)arg3);var_r20=-4;}
else if((u32)arg1!=((u32)arg1&0xFFFFFE00)){OSReport(str+0x454,str+0x438,arg1);var_r20=-4;}
else if((*(u32*)((u8*)dev+0x20)!=0)&&((u32)arg1>*(u32*)((u8*)dev+0x20))){OSReport(str+0x3E0,str+0x438,arg1);var_r20=-4;}
else if(*(s32*)((u8*)dev+0x24)==0){OSReport(str+0x3FC,str+0x438);var_r20=(s32)0xC1000000;}
else {
OSLockMutex(lbl_80407560);
if(lbl_8055DD6C!=0){OSUnlockMutex(lbl_80407560);var_r20=(s32)0xC1000000;}
else {
lbl_8055DD6C=1; OSUnlockMutex(lbl_80407560);
if(*(u32*)((u8*)dev+0x24)==2){
var_r20=fn_800BB0A8(*(s32*)dev,7,3,2,*(s32*)((u8*)dev+0x10),0,0,0,0,(s32)sp18,0,0);
if(var_r20!=0) OSReport(str+0x338,var_r20);
else {
*(s32*)((u8*)dev+0x24)=1;
var_r20=fn_800BB0A8(*(s32*)dev,0x10,3,1,0x200,0,0,0,0,(s32)sp28,0,0);
if(var_r20!=0) OSReport(str+0x358,str+0x234,var_r20);
else {
var_r20=((s32(*)(void*,s32))fn_800BC134)(dev,4);
if(var_r20!=0) OSReport(str+0x358,str+0x234,var_r20);
else {
 s32 fd=*(volatile s32*)dev; *lbl_8055DD70=1; s32 temp_r3=IOS_Ioctl(fd,6,lbl_8055DD70,4,0,0); if(temp_r3!=0){OSReport(str+0x148);temp_r3=(s32)0xC1000000;} var_r20=temp_r3; if(temp_r3!=0){OSReport(str+0x358,str+0x234,temp_r3);}
}
}
}
if(var_r20!=0){lbl_8055DD6C=0;goto done;}
}
DCFlushRange((void*)arg2,(u32)arg3);
var_r20=fn_800BB0A8(*(s32*)dev,0x19,3,1,arg1,arg2,var_r29,var_r30,1,lbl_8055DD78,arg4,arg5);
if(var_r20!=0){OSReport(str+0x474,str+0x438,var_r20);lbl_8055DD6C=0;}
if(arg4==0)lbl_8055DD6C=0;
}
}
done:
return var_r20;
}

struct IosDevice {
    s32 fd;
    u8 pad[0xC];
    s32 field10;
    u8 pad2[0x10];
    u32 state;
};

extern "C" s32 fn_800BB0A8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 lbl_8055DD6C;
extern "C" s32 *lbl_8055DD70;
extern "C" u8 lbl_80407560[0x18];
extern "C" const char lbl_8031B838[];
extern "C" s32 fn_800BC2EC(void *, s32 *);
extern "C" s32 IOS_Ioctl(s32, s32, void *, s32, void *, s32);

extern "C" void fn_800BBCB4(void* context) {
    *(s32*)((u8*)context + 0x24) = 0;
    IOS_Close(*(s32*)context);
    *(s32*)context = -1;
}

extern "C" s32 fn_800BBEA4(IosDevice *dev, s32 arg1, s32 *arg2, s32 arg3) {
    const char *str = lbl_8031B838;
    s32 r30 = 3;
    s32 field10 = dev->field10;
    s32 res;

    if (lbl_80559248 < 0) {
        res = (s32)0xC1000000;
    } else if (dev->state == 0) {
        res = (s32)0xC1000000;
    } else {
        OSLockMutex(lbl_80407560);
        if (lbl_8055DD6C != 0) {
            OSUnlockMutex(lbl_80407560);
            res = (s32)0xC1000000;
        } else {
            lbl_8055DD6C = 1;
            OSUnlockMutex(lbl_80407560);

            if (dev->state == 1) {
                s32 sp18[6];
                res = fn_800BB0A8(dev->fd, 7, 3, 2, 0, 0, 0, 0, 0, (s32)sp18, 0, 0);
                dev->state = 2;
                if (res == (s32)0xC1000003) {
                    res = 0;
                } else if (res != 0) {
                    OSReport(str + 0x5B8, res, (s32)0xC1000003);
                }
                lbl_8055DD6C = 0;
                if (res != 0) {
                    goto end;
                }
            }

            if (arg2 == 0 || arg3 == 0) {
                lbl_8055DD6C = 0;
                res = (s32)0xC1000000;
            } else {
                switch (arg1) {
                case 9:
                case 10:
                    r30 = 3;
                    break;

                case 0x33:
                    res = fn_800BC2EC(dev, arg2);
                    lbl_8055DD6C = 0;
                    goto end;

                case 0x29:
                    res = 0;
                    if (arg2 != 0) {
                        res = IOS_Ioctl(dev->fd, 0xC, 0, 0, (void *)lbl_8055DD70, 4);
                        if (res != 0) {
                            OSReport(str + 0x5E8, res);
                        } else {
                            *arg2 = *lbl_8055DD70;
                        }
                    }
                    lbl_8055DD6C = 0;
                    goto end;

                case 3:
                    res = 0;
                    *arg2 = dev->field10;
                    lbl_8055DD6C = 0;
                    goto end;
                }

                res = fn_800BB0A8(dev->fd, arg1, 3, r30, field10, 0, 0, 0, 0, (s32)arg2, 0, 0);
                lbl_8055DD6C = 0;
            }
        }
    }

end:
    if (res != 0) {
        OSReport(str + 0x36C, str + 0x5A0, res);
    }
    return res;
}

typedef s32 (*FnBB0A8)(s32,s32,s32,s32,s32,s32,s32,s32);
extern "C" s32 fn_800BABD0(void *, s32, s32 *, s32);
extern "C" s32 fn_800BACC4(void *, s32, s32 *, s32);
extern "C" s32 fn_800BC134(void *arg0, s32 arg1, s32 arg2) {
    s32 sp8 = 0, sp10 = 0, sp14 = 0, sp18;
    s32 sp20;
    s32 flag = (arg1 == 4) ? 2 : 0;
    FnBB0A8 call = (FnBB0A8)fn_800BB0A8;
    s32 result = call(*(s32 *)arg0, 0x37, 3, 1, *(s32 *)((u8 *)arg0 + 0x10), 0, 0, 0);
    if (result) {
        OSReport(lbl_8031B838 + 0x618);
        OSReport(lbl_8031B838 + 0x624, lbl_8031B838 + 0x608, result);
        return result;
    }
    result = call(*(s32 *)arg0, 6, 3, 1, flag, 0, 0, 0);
    if (result) {
        OSReport(lbl_8031B838 + 0x638);
        OSReport(lbl_8031B838 + 0x624, lbl_8031B838 + 0x608, result);
        return result;
    }
    result = fn_800BABD0(arg0, 0x28, &sp18, 1);
    if (result) {
        OSReport(lbl_8031B838 + 0x648, lbl_8031B838 + 0x608, 0x28);
        return result;
    }
    if (flag) sp18 |= 2;
    else sp18 &= ~2;
    result = fn_800BACC4(arg0, 0x28, &sp18, 1);
    if (result) OSReport(lbl_8031B838 + 0x668, lbl_8031B838 + 0x608, 0x28);
    return result;
}

extern "C" s32 fn_800BB0A8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 lbl_8055DD78;
extern "C" const char lbl_8031BF54[];
extern "C" const char lbl_8031BF74[];
extern "C" s32 fn_800BC474(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 result;

    if (lbl_80559248 < 0) {
        result = (s32)0xC1000000;
    } else if (arg1 == 0) {
        result = (s32)0xC1000000;
    } else if (arg2 == 0) {
        result = -4;
    } else {
        result = fn_800BB0A8(*arg0, 0x40, 0, 0, *arg2, 0, 0, 0,
                             0, lbl_8055DD78, arg1, (s32)arg2);
    }

    if (result != 0)
        OSReport(lbl_8031BF74, lbl_8031BF54, result);
    return result;
}

extern "C" void fn_800BD710(void *, s16, s16, void *, void *);
extern "C" { DECL_SECTION(".rodata") extern u8 lbl_8031BFA8; }
extern "C" u8 lbl_80559250;
extern "C" u8 lbl_80559258;
extern "C" u8 lbl_80559260;
extern "C" u8 lbl_80559268;
 extern "C" void fn_800BC538(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4, s16 *arg5, s16 *arg6, u8 *arg7, s16 arg_sp8) {
         
 
     u8 *var_r3_3;
     u8 *var_r3_2;
     u8 *var_r3;
     u8 *var_r31;
     u8 *var_r28_3;
     u8 *var_r28_2;
     u8 *var_r28;
     u8 *var_r27;
     u8 *var_r26_2;
     u8 *var_r19_3;
     u8 *var_r19_2;
     u8 *var_r18;
     u8 *var_r17;
     u8 *var_r16;
     u8 *var_r15;
     u8 *temp_r5_9;
     u8 *temp_r5_8;
     u8 *temp_r5_7;
     u8 *temp_r5_6;
     u8 *temp_r5_5;
     u8 *temp_r5_4;
     u8 *temp_r5_3;
     u8 *temp_r5_2;
     u8 *temp_r5_12;
     u8 *temp_r5_11;
     u8 *temp_r5_10;
     u8 *temp_r5;
     u8 *temp_r4_6;
     u8 *temp_r4_5;
     u8 *temp_r4_4;
     u8 *temp_r4_3;
     u8 *temp_r4_2;
     u8 *temp_r4_16;
     u8 *temp_r4_15;
     u8 *temp_r4_14;
     u8 *temp_r4_13;
     u8 *temp_r4_12;
     u8 *var_r19;
     register s32 var_r4_4;
     register s32 var_r4_3;
     register s32 var_r4_2;
     register s32 var_r4;
     register s32 var_r27_3;
     register s32 var_r27_2;
     register s32 var_r26;
     register s32 var_r25;
     register s32 var_r24_2;
     register s32 var_r24;
     register s32 var_r18_2;
     register s32 var_r15_3;
     register s32 var_r15_2;
     register s32 var_ctr_4;
     register s32 var_ctr_3;
     register s32 var_ctr_2;
     register s32 var_ctr;
     register s32 temp_r4_9;
     register s32 temp_r4_8;
     register s32 temp_r4_7;
     register s32 temp_r4_11;
     register s32 temp_r4_10;
     register s32 temp_r4;
     register s16 var_r23;
     register s16 temp_r6_2;
     register s16 temp_r6;
     var_r31 = arg4;
     if (arg3 & 7) {
         if ((s32) M2C_FIELD(arg0, s32 *, 0x9E0) == 0) {
             M2C_FIELD(arg0, s32 *, 0x9E0) = 1;
             M2C_FIELD(arg0, s16 *, 0xA2C) = (s16) M2C_FIELD(arg2, s16 *, 0);
             M2C_FIELD(arg0, s16 *, 0xA2E) = (s16) M2C_FIELD(arg2, s16 *, 2);
             M2C_FIELD(arg0, s16 *, 0xA30) = (s16) M2C_FIELD(arg2, s16 *, 4);
             M2C_FIELD(arg0, s16 *, 0xA32) = (s16) M2C_FIELD(arg2, s16 *, 6);
             M2C_FIELD(arg0, s16 *, 0xA34) = (s16) M2C_FIELD(arg2, s16 *, 8);
             M2C_FIELD(arg0, s16 *, 0xA36) = (s16) M2C_FIELD(arg2, s16 *, 0xA);
             M2C_FIELD(arg0, s16 *, 0xA38) = (s16) M2C_FIELD(arg2, s16 *, 0xC);
             M2C_FIELD(arg0, s16 *, 0xA3A) = (s16) M2C_FIELD(arg2, s16 *, 0xE);
             M2C_FIELD(arg0, s16 *, 0xA3C) = (s16) M2C_FIELD(arg2, s16 *, 0x10);
             M2C_FIELD(arg0, s16 *, 0xA3E) = (s16) M2C_FIELD(arg2, s16 *, 0x12);
             M2C_FIELD(arg0, s16 *, 0xA40) = (s16) M2C_FIELD(arg2, s16 *, 0x14);
             M2C_FIELD(arg0, s16 *, 0xA42) = (s16) M2C_FIELD(arg2, s16 *, 0x16);
             M2C_FIELD(arg0, s16 *, 0xA44) = (s16) M2C_FIELD(arg2, s16 *, 0x18);
             M2C_FIELD(arg0, s16 *, 0xA46) = (s16) M2C_FIELD(arg2, s16 *, 0x1A);
             M2C_FIELD(arg0, s16 *, 0xA48) = (s16) M2C_FIELD(arg2, s16 *, 0x1C);
             M2C_FIELD(arg0, s16 *, 0xA4A) = (s16) M2C_FIELD(arg2, s16 *, 0x1E);
             M2C_FIELD(arg0, s16 *, 0xA4C) = (s16) M2C_FIELD(arg2, s16 *, 0x20);
             M2C_FIELD(arg0, s16 *, 0xA4E) = (s16) M2C_FIELD(arg2, s16 *, 0x22);
             M2C_FIELD(arg0, s16 *, 0xA50) = (s16) M2C_FIELD(arg2, s16 *, 0x24);
             M2C_FIELD(arg0, s16 *, 0xA52) = (s16) M2C_FIELD(arg2, s16 *, 0x26);
             M2C_FIELD(arg0, s16 *, 0xA54) = (s16) M2C_FIELD(arg2, s16 *, 0x28);
             M2C_FIELD(arg0, s16 *, 0xA2A) = 0;
         }
         var_r19 = arg1;
         var_r27 = arg4 + 0x3F00;
         var_r28 = arg4 + 0x1B00;
         var_r24_2 = 0;
 do {
             if ((s32) M2C_FIELD(var_r31, s32 *, 0x1B00) == 0) {
                 M2C_FIELD(var_r31, s32 *, 0x3F00) = 0;
             } else {
                 var_r3 = arg0 + 0x28;
                 var_r4 = 0x14;
                 var_ctr = 0x15;
 loop_7:
                 if (arg_sp8 > (s16) M2C_FIELD(var_r3, s16 *, 0xA2A)) {
                     var_r23 = M2C_FIELD((arg0 + (var_r4 * 2)), s16 *, 0xA2C);
                 } else {
                     var_r3 -= 2;
                     var_r4 -= 1;
                     var_ctr -= 1;
                     if (var_ctr != 0) {
                         goto loop_7;
                     }
                 }
                 if (var_r24_2 >= var_r23) {
                     fn_800BD710(arg0, M2C_FIELD(arg7, s16 *, 2), M2C_FIELD(((u8 *)arg5 + (*var_r19 * 2)), s16 *, 0x2A), var_r28, var_r27);
                 }
             }
             var_r31 += 4;
             var_r27 += 4;
             var_r28 += 4;
             var_r24_2 += 1;
             var_r19 += 1;
             } while (var_r24_2 < (s32) M2C_FIELD(arg0, s32 *, 0x9BC));
         return;
     }
     if (arg3 & 0x10) {
         if ((s32) M2C_FIELD(arg0, s32 *, 0x9E4) == 0) {
             temp_r4 = M2C_FIELD(arg0, s32 *, 4);
             M2C_FIELD(arg0, s32 *, 0x9E4) = 1;
             if ((temp_r4 == 0) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 0)) {
                 temp_r5 = &lbl_8031BFA8 + 0x18;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x18);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5, u8 *, 0xB);
             } else if ((temp_r4 == 0) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 1)) {
                 temp_r4_2 = &lbl_8031BFA8 + 0x28;
                 temp_r5_2 = &lbl_8031BFA8 + 0x40;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x28);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x40);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_2, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_2, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_2, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_2, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_2, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_2, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_2, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_2, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_2, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_2, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_2, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_2, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_2, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_2, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_2, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_2, u8 *, 0xB);
             } else if ((temp_r4 == 0) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 2)) {
                 temp_r4_3 = &lbl_8031BFA8 + 0x50;
                 temp_r5_3 = &lbl_8031BFA8 + 0x68;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x50);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x68);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_3, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_3, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_3, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_3, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_3, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_3, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_3, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_3, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_3, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_3, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_3, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_3, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_3, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_3, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_3, u8 *, 0xB);
             } else if ((temp_r4 == 1) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 0)) {
                 temp_r4_4 = &lbl_8031BFA8 + 0x78;
                 temp_r5_4 = &lbl_8031BFA8 + 0x90;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x78);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x90);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_4, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_4, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_4, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_4, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_4, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_4, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_4, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_4, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_4, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_4, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_4, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_4, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_4, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_4, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_4, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_4, u8 *, 0xB);
             } else if ((temp_r4 == 1) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 1)) {
                 temp_r4_5 = &lbl_8031BFA8 + 0xA0;
                 temp_r5_5 = &lbl_8031BFA8 + 0xB8;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xA0);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0xB8);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_5, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_5, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_5, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_5, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_5, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_5, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_5, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_5, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_5, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_5, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_5, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_5, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_5, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_5, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_5, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_5, u8 *, 0xB);
             } else {
                 temp_r4_6 = &lbl_8031BFA8 + 0xC8;
                 temp_r5_6 = &lbl_8031BFA8 + 0xE0;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xC8);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0xE0);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_6, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_6, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_6, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_6, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_6, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_6, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_6, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_6, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_6, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_6, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_6, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_6, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_6, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_6, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_6, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_6, u8 *, 0xB);
             }
         }
         var_r28_2 = var_r31;
         var_r26 = 0;
         var_r27_2 = 0;
 do {
             if ((s32) M2C_FIELD(var_r28_2, s32 *, 0x1B00) == 0) {
                 M2C_FIELD(var_r28_2, s32 *, 0x3F00) = 0;
             } else {
                 var_r3_2 = arg0;
                 var_r4_2 = 0;
                 var_ctr_2 = 0xC;
 loop_37:
                 if (arg_sp8 > (s16) M2C_FIELD(var_r3_2, s16 *, 0xA56)) {
                     var_r23 = (s16) M2C_FIELD((arg0 + var_r4_2), u8 *, 0x9EC);
                 } else {
                     var_r3_2 += 2;
                     var_r4_2 += 1;
                     var_ctr_2 -= 1;
                     if (var_ctr_2 != 0) {
                         goto loop_37;
                     }
                 }
                 if (var_r26 >= var_r23) {
                     var_r4_3 = 0xB;
                     var_ctr_3 = 2;
 loop_42:
                     if (var_r26 < (s32) M2C_FIELD((arg0 + var_r4_3), u8 *, 0x9EC)) {
                         var_r24 = 0xB - var_r4_3;
                     } else {
                         temp_r4_7 = var_r4_3 - 1;
                         if (var_r26 < (s32) M2C_FIELD((arg0 + temp_r4_7), u8 *, 0x9EC)) {
                             var_r24 = 0xB - temp_r4_7;
                         } else {
                             temp_r4_8 = temp_r4_7 - 1;
                             if (var_r26 < (s32) M2C_FIELD((arg0 + temp_r4_8), u8 *, 0x9EC)) {
                                 var_r24 = 0xB - temp_r4_8;
                             } else {
                                 temp_r4_9 = temp_r4_8 - 1;
                                 if (var_r26 < (s32) M2C_FIELD((arg0 + temp_r4_9), u8 *, 0x9EC)) {
                                     var_r24 = 0xB - temp_r4_9;
                                 } else {
                                     temp_r4_10 = temp_r4_9 - 1;
                                     if (var_r26 < (s32) M2C_FIELD((arg0 + temp_r4_10), u8 *, 0x9EC)) {
                                         var_r24 = 0xB - temp_r4_10;
                                     } else {
                                         temp_r4_11 = temp_r4_10 - 1;
                                         if (var_r26 < (s32) M2C_FIELD((arg0 + temp_r4_11), u8 *, 0x9EC)) {
                                             var_r24 = 0xB - temp_r4_11;
                                         } else {
                                             var_r4_3 = temp_r4_11 - 1;
                                             var_ctr_3 -= 1;
                                             if (var_ctr_3 != 0) {
                                                 goto loop_42;
                                             }
                                         }
                                     }
                                 }
                             }
                         }
                     }
                     var_r16 = var_r31;
                     var_r17 = var_r31 + 0x2400;
                     var_r25 = 0;
                     var_r15 = (u8 *)arg6 + (var_r24 * 6);
                     do {
                         fn_800BD710(arg0, M2C_FIELD(arg7, s16 *, 2), M2C_FIELD(var_r15, s16 *, 0x48), var_r16 + var_r27_2, var_r17 + var_r27_2);
                         var_r25 += 1;
                         var_r16 += 0x900;
                         var_r15 += 2;
                         var_r17 += 0x900;
                     } while (var_r25 < 3);
                 }
             }
             var_r28_2 += 4;
             var_r27_2 += 4;
             var_r26 += 1;
             } while (var_r26 < (s32) M2C_FIELD(arg0, s32 *, 0x9C0));
         return;
     }
     if ((s32) M2C_FIELD(arg0, s32 *, 0x9DC) == 0) {
         M2C_FIELD(arg0, s32 *, 0x9DC) = 1;
         if ((s32) M2C_FIELD(arg0, s32 *, 4) == 0) {
             temp_r6 = M2C_FIELD(arg0, s16 *, 0x1C);
             M2C_FIELD(arg0, u8 *, 0xA00) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 0);
             M2C_FIELD(arg0, u8 *, 0x9F8) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 0);
             M2C_FIELD(arg0, u8 *, 0xA01) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 1);
             M2C_FIELD(arg0, u8 *, 0x9F9) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 1);
             M2C_FIELD(arg0, u8 *, 0xA02) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 2);
             M2C_FIELD(arg0, u8 *, 0x9FA) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 2);
             M2C_FIELD(arg0, u8 *, 0xA03) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 3);
             M2C_FIELD(arg0, u8 *, 0x9FB) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 3);
             M2C_FIELD(arg0, u8 *, 0xA04) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 4);
             M2C_FIELD(arg0, u8 *, 0x9FC) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 4);
             M2C_FIELD(arg0, u8 *, 0xA05) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 5);
             M2C_FIELD(arg0, u8 *, 0x9FD) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 5);
             M2C_FIELD(arg0, u8 *, 0xA06) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 6);
             M2C_FIELD(arg0, u8 *, 0x9FE) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 6);
             M2C_FIELD(arg0, u8 *, 0xA07) = (u8) M2C_FIELD(&lbl_80559250, u8 *, 7);
             M2C_FIELD(arg0, u8 *, 0x9FF) = (u8) M2C_FIELD(&lbl_80559258, u8 *, 7);
             if (temp_r6 == 0) {
                 temp_r5_7 = &lbl_8031BFA8 + 0x18;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x18);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_7, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_7, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_7, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_7, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_7, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_7, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_7, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_7, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_7, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_7, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_7, u8 *, 0xB);
             } else if (temp_r6 == 1) {
                 temp_r4_12 = &lbl_8031BFA8 + 0x28;
                 temp_r5_8 = &lbl_8031BFA8 + 0x40;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x28);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x40);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_12, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_8, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_12, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_8, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_12, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_8, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_12, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_8, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_8, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_8, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_8, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_8, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_8, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_8, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_12, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_8, u8 *, 0xB);
             } else {
                 temp_r4_13 = &lbl_8031BFA8 + 0x50;
                 temp_r5_9 = &lbl_8031BFA8 + 0x68;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x50);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x68);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_13, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_9, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_13, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_9, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_13, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_9, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_13, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_9, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_9, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_9, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_9, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_9, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_9, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_9, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_13, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_9, u8 *, 0xB);
             }
         } else {
             temp_r6_2 = M2C_FIELD(arg0, s16 *, 0x1C);
             M2C_FIELD(arg0, u8 *, 0xA00) = (u8) M2C_FIELD(&lbl_80559260, u8 *, 0);
             M2C_FIELD(arg0, u8 *, 0x9F8) = (u8) M2C_FIELD(&lbl_80559268, u8 *, 0);
             M2C_FIELD(arg0, u8 *, 0xA01) = (u8) M2C_FIELD(&lbl_80559260, u8 *, 1);
             M2C_FIELD(arg0, u8 *, 0x9F9) = (u8) M2C_FIELD(&lbl_80559268, u8 *, 1);
             M2C_FIELD(arg0, u8 *, 0xA02) = (u8) M2C_FIELD(&lbl_80559260, u8 *, 2);
             M2C_FIELD(arg0, u8 *, 0x9FA) = (u8) M2C_FIELD(&lbl_80559268, u8 *, 2);
             M2C_FIELD(arg0, u8 *, 0xA03) = (u8) M2C_FIELD(&lbl_80559260, u8 *, 3);
             M2C_FIELD(arg0, u8 *, 0x9FB) = (u8) M2C_FIELD(&lbl_80559268, u8 *, 3);
             M2C_FIELD(arg0, u8 *, 0xA04) = (u8) M2C_FIELD(&lbl_80559260, u8 *, 4);
             M2C_FIELD(arg0, u8 *, 0x9FC) = (u8) M2C_FIELD(&lbl_80559268, u8 *, 4);
             M2C_FIELD(arg0, u8 *, 0xA05) = (u8) M2C_FIELD(&lbl_80559260, u8 *, 5);
             M2C_FIELD(arg0, u8 *, 0x9FD) = (u8) M2C_FIELD(&lbl_80559268, u8 *, 5);
             if (temp_r6_2 == 0) {
                 temp_r4_14 = &lbl_8031BFA8 + 0x78;
                 temp_r5_10 = &lbl_8031BFA8 + 0x90;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0x78);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0x90);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_14, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_10, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_14, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_10, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_14, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_10, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_14, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_10, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_10, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_10, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_10, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_10, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_10, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_10, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_14, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_10, u8 *, 0xB);
             } else if (temp_r6_2 == 1) {
                 temp_r4_15 = &lbl_8031BFA8 + 0xA0;
                 temp_r5_11 = &lbl_8031BFA8 + 0xB8;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xA0);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0xB8);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_15, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_11, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_15, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_11, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_15, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_11, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_15, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_11, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_11, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_11, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_11, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_11, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_11, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_11, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_15, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_11, u8 *, 0xB);
             } else {
                 temp_r4_16 = &lbl_8031BFA8 + 0xC8;
                 temp_r5_12 = &lbl_8031BFA8 + 0xE0;
                 M2C_FIELD(arg0, s16 *, 0xA56) = (s16) M2C_FIELD(&lbl_8031BFA8, s16 *, 0xC8);
                 M2C_FIELD(arg0, u8 *, 0x9EC) = (u8) M2C_FIELD(&lbl_8031BFA8, u8 *, 0xE0);
                 M2C_FIELD(arg0, s16 *, 0xA58) = (s16) M2C_FIELD(temp_r4_16, s16 *, 2);
                 M2C_FIELD(arg0, u8 *, 0x9ED) = (u8) M2C_FIELD(temp_r5_12, u8 *, 1);
                 M2C_FIELD(arg0, s16 *, 0xA5A) = (s16) M2C_FIELD(temp_r4_16, s16 *, 4);
                 M2C_FIELD(arg0, u8 *, 0x9EE) = (u8) M2C_FIELD(temp_r5_12, u8 *, 2);
                 M2C_FIELD(arg0, s16 *, 0xA5C) = (s16) M2C_FIELD(temp_r4_16, s16 *, 6);
                 M2C_FIELD(arg0, u8 *, 0x9EF) = (u8) M2C_FIELD(temp_r5_12, u8 *, 3);
                 M2C_FIELD(arg0, s16 *, 0xA5E) = (s16) M2C_FIELD(temp_r4_16, s16 *, 8);
                 M2C_FIELD(arg0, u8 *, 0x9F0) = (u8) M2C_FIELD(temp_r5_12, u8 *, 4);
                 M2C_FIELD(arg0, s16 *, 0xA60) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0xA);
                 M2C_FIELD(arg0, u8 *, 0x9F1) = (u8) M2C_FIELD(temp_r5_12, u8 *, 5);
                 M2C_FIELD(arg0, s16 *, 0xA62) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0xC);
                 M2C_FIELD(arg0, u8 *, 0x9F2) = (u8) M2C_FIELD(temp_r5_12, u8 *, 6);
                 M2C_FIELD(arg0, s16 *, 0xA64) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0xE);
                 M2C_FIELD(arg0, u8 *, 0x9F3) = (u8) M2C_FIELD(temp_r5_12, u8 *, 7);
                 M2C_FIELD(arg0, s16 *, 0xA66) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0x10);
                 M2C_FIELD(arg0, u8 *, 0x9F4) = (u8) M2C_FIELD(temp_r5_12, u8 *, 8);
                 M2C_FIELD(arg0, s16 *, 0xA68) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0x12);
                 M2C_FIELD(arg0, u8 *, 0x9F5) = (u8) M2C_FIELD(temp_r5_12, u8 *, 9);
                 M2C_FIELD(arg0, s16 *, 0xA6A) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0x14);
                 M2C_FIELD(arg0, u8 *, 0x9F6) = (u8) M2C_FIELD(temp_r5_12, u8 *, 0xA);
                 M2C_FIELD(arg0, s16 *, 0xA6C) = (s16) M2C_FIELD(temp_r4_16, s16 *, 0x16);
                 M2C_FIELD(arg0, u8 *, 0x9F7) = (u8) M2C_FIELD(temp_r5_12, u8 *, 0xB);
             }
         }
     }
     var_r18 = arg4 + 0x3F00;
     var_r19_2 = arg4 + 0x1B00;
     var_r15_2 = 0;
     do {
         if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA00)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9F8);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA01)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9F9);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA02)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9FA);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA03)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9FB);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA04)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9FC);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA05)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9FD);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA06)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9FE);
         } else if (arg_sp8 > (s32) M2C_FIELD(arg0, u8 *, 0xA07)) {
             var_r23 = (s16) M2C_FIELD(arg0, u8 *, 0x9FF);
         }
         if (var_r15_2 >= var_r23) {
             if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 0)), u8 *, 0x9F8)) {
                 var_r24 = 0;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 1)), u8 *, 0x9F8)) {
                 var_r24 = 1;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 2)), u8 *, 0x9F8)) {
                 var_r24 = 2;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 3)), u8 *, 0x9F8)) {
                 var_r24 = 3;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 4)), u8 *, 0x9F8)) {
                 var_r24 = 4;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 5)), u8 *, 0x9F8)) {
                 var_r24 = 5;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 6)), u8 *, 0x9F8)) {
                 var_r24 = 6;
             } else if (var_r15_2 < (s32) M2C_FIELD((arg0 + (7 - 7)), u8 *, 0x9F8)) {
                 var_r24 = 7;
             }
             fn_800BD710(arg0, M2C_FIELD(arg7, s16 *, 2), M2C_FIELD(((u8 *)arg5 + (var_r24 * 2)), s16 *, 0x2A), var_r19_2, var_r18);
         }
         var_r15_2 += 1;
         var_r19_2 += 4;
         var_r18 += 4;
     } while (var_r15_2 < 0x24);
     var_r27_3 = 0xC;
     var_r18_2 = 0x30;
 while (var_r27_3 < (s32) M2C_FIELD(arg0, s32 *, 0x9C0)) {
         var_r3_3 = arg0;
         var_r4_4 = 0;
         var_ctr_4 = 0xA;
 do {
             if (arg_sp8 > (s16) M2C_FIELD(var_r3_3, s16 *, 0xA56)) {
                 var_r23 = (s16) M2C_FIELD((arg0 + var_r4_4), u8 *, 0x9EC);
                 break;
             }
             var_r3_3 += 2;
             var_r4_4 += 1;
         } while (--var_ctr_4 != 0);
         if (var_r27_3 >= var_r23) {
             if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9F4)) {
                 var_r24 = 0xB - 8;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9F3)) {
                 var_r24 = 0xB - 7;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9F2)) {
                 var_r24 = 0xB - 6;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9F1)) {
                 var_r24 = 0xB - 5;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9F0)) {
                 var_r24 = 0xB - 4;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9EF)) {
                 var_r24 = 0xB - 3;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9EE)) {
                 var_r24 = 0xB - 2;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9ED)) {
                 var_r24 = 0xB - 1;
             } else if (var_r27_3 < (s32) M2C_FIELD(arg0, u8 *, 0x9EC)) {
                 var_r24 = 0xB - 0;
             }
             var_r26_2 = var_r31;
             var_r19_3 = var_r31 + 0x2400;
             var_r15_3 = 0;
             var_r28_3 = (u8 *)arg6 + (var_r24 * 6);
             do {
                 fn_800BD710(arg0, M2C_FIELD(arg7, s16 *, 2), M2C_FIELD(var_r28_3, s16 *, 0x48), var_r26_2 + var_r18_2, var_r19_3 + var_r18_2);
                 var_r15_3 += 1;
                 var_r26_2 += 0x900;
                 var_r28_3 += 2;
                 var_r19_3 += 0x900;
             } while (var_r15_3 < 3);
         }
         var_r18_2 += 4;
         var_r27_3 += 1;
     }
 }

extern "C" s16 fn_800BDD7C(s32, s32, s32 *);
extern "C" s16 fn_800BDE18(s32, s32, s32, s32 *);
extern s16 lbl_802F3418[];
extern s16 lbl_802F3478[];
extern "C" s32 lbl_802F33C8[];
extern "C" s32 lbl_802F33E8[];
extern "C" void fn_800BD970(s32 arg0, s32 arg1, s8 arg2, s32 arg3, s32 *arg4) {
    s32 row, i, n = arg0 * 0x12;
    if (arg3 & 7) {
        for (row = 0; row < arg2; ++row, arg4 = (s32 *)((u8 *)arg4 + 0x2400)) {
            for (i = 1; i < arg0; ++i) {
                s32 k = 0x10 * i + 2;
                s32 *a = (s32 *)((u8 *)arg4 + 0x1b00 + k * 4);
                s32 *b = a - 1;
                s32 *c = lbl_802F33C8;
                s32 *d = lbl_802F33E8;
                s32 j;
                for (j = 0; j < 4; ++j) {
                    s32 x = a[0], y = b[0], co = c[0], si = d[0];
                    b[0] = (s64)y * co >> 24 - ((s64)x * si >> 24);
                    a[0] = ((s64)y * si >> 24) + ((s64)x * co >> 24);
                    x = a[1]; y = b[-1]; co = c[1]; si = d[1];
                    b[-1] = ((s64)y * co >> 24) - ((s64)x * si >> 24);
                    a[1] = ((s64)y * si >> 24) + ((s64)x * co >> 24);
                    a += 2; b -= 2; c += 2; d += 2;
                }
            }
            if (arg1 < n)
                for (i = arg1; i < n; ++i)
                    *((s32 *)((u8 *)arg4 + 0x1b00) + i) = 0;
        }
    } else {
        for (row = 0; row < arg2; ++row, arg4 = (s32 *)((u8 *)arg4 + 0x2400)) {
            s32 *a = (s32 *)((u8 *)arg4 + 0x1b48);
            s32 *b = (s32 *)((u8 *)arg4 + 0x1b44);
            s32 *c = lbl_802F33C8, *d = lbl_802F33E8;
            s32 j;
            for (j = 0; j < 4; ++j) {
                s32 x = a[0], y = b[0], co = c[0], si = d[0];
                b[0] = ((s64)y * co >> 24) - ((s64)x * si >> 24);
                a[0] = ((s64)x * co >> 24) + ((s64)y * si >> 24);
                x = a[1]; y = b[-1]; co = c[1]; si = d[1];
                b[-1] = ((s64)y * co >> 24) - ((s64)x * si >> 24);
                a[1] = ((s64)x * co >> 24) + ((s64)y * si >> 24);
                a += 2; b -= 2; c += 2; d += 2;
            }
        }
    }
}

extern "C" s16 fn_800BDD7C(s32 arg0, s32 arg1, s32 *arg2) {
    u32 value = ((s32 (*)(s32, s32, s32, s32 *))fn_800BDE18)(arg0, arg1, 0xC, arg2);
    while ((value & 0xFFFFU) != 0xFFFU) {
        value = (value * 2) & 0xFFFEU;
        value |= ((s32 (*)(s32, s32, s32, s32 *))fn_800BDE18)(arg0, arg1, 1, arg2);
        if (*arg2 > 0x3FFF)
            return 0;
    }
    return 1;
}

extern "C" s16 fn_800BDE18(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 remaining = arg2;
    s32 take;
    s32 bitsInByte;
    s32 position = *arg3;
    s32 piece;
    s16 result = 0;
    u8 *data = (u8 *)arg1 + (position >> 3);

    bitsInByte = 8 - (position & 7);
    while (remaining > 0) {
        if (bitsInByte == 0) {
            bitsInByte = 8;
            data++;
        }
        take = bitsInByte;
        if ((u32)remaining < (u32)bitsInByte)
            take = remaining;
        piece = data[0] & lbl_802F3408[bitsInByte];
        piece >>= bitsInByte - take;
        result = (s16)(result | (piece << (remaining - take)));
        bitsInByte -= take;
        remaining -= take;
    }
    *arg3 += arg2;
    return result;
}

extern "C" u8 lbl_802F3408[];
extern "C" s32 fn_800BDEB4(const u8 *data, s32 bitCount, u32 *bitOffset) {
    register s32 remaining = bitCount;
    register s32 take;
    register u16 result = 0;
    register s32 byteIndex;
    register s32 bitsInByte;
    register s32 position;
    register s32 startBit;
    register s32 piece;

    if (remaining == 0)
        return 0;
    position = *bitOffset;
    *bitOffset = position + remaining;
    startBit = position & 7;
    byteIndex = (position >> 3) & 0x1FFF;
    bitsInByte = 8 - startBit;
    while (remaining > 0) {
        if (bitsInByte == 0) {
            byteIndex += 1;
            byteIndex &= 0x1FFF;
            bitsInByte = 8;
        }
        take = bitsInByte;
        if ((u32)remaining < (u32)bitsInByte)
            take = remaining;
        piece = data[byteIndex] & lbl_802F3408[bitsInByte];
        piece >>= bitsInByte - take;
        result = (u16)(result | (piece << (remaining - take)));
        bitsInByte -= take;
        remaining -= take;
    }
    return result;
}

extern "C" void *lbl_8055DD88;
extern "C" void fn_800BC538(u8 *, u8 *, u8 *, s32, u8 *, s16 *, s16 *, u8 *, s16); /* extern */
extern "C" void fn_800BF048(void *, u8 *, u8 *, u8 *, u8 *, u8 *, s32 *, u8 *, s16 *, s16 *, s16 *, s16 *, s16 *, s16 *, s16 *); /* extern */
extern "C" u32 fn_800C0E7C(void *, void *, void *, void *, s32 *, void *); /* extern */
extern "C" u32 fn_800C3DA0(void *, void *, s32, s16 *, s16 *, s16 *, s16, s16); /* extern */
extern "C" u32 lbl_80560DA0;
extern "C" u32 lbl_80560DA8;
extern "C" s32 fn_800C0440(void *, s32, void *, s32, s32, s32, s32, s16, s32, s16 *, s16 *);
extern "C" void fn_800C57B0(s32, s32, s32, s32 *);
extern "C" void fn_800C4CF4(void *, s32, s32, s32, s8, s32);
extern "C" s32 fn_800BDF4C(BDF4CState *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5, s32 arg6) {
    struct LocalFrame { u8 pad[0xFC]; s32 table; };
    volatile union { LocalFrame layout; u8 frame[0xC0]; struct { u8 pad0[0x38]; s16 spA0[12]; u8 pad1[0x28]; s16 spE0; s16 spE2; s32 spE4; s32 spE8; s8 spEC; } early; } space;
    space.layout.table = 0x802F0000;
    s16 *spCursor;
    s32 var_r14;
    s32 temp_r17;
    s8 var_r17;
    s32 result, type, bitDepth, tile;
    s16 samplesC[4], samples9[4], samples8[4], samples4[4];
    s16 colorA[4][3], colorB[4][3], colorC[4], colorD[4], colorE[4], colorF[4], colorG[4];
    u8 flags[4], secondary[4], modeBits[4];
    s32 rowBits[4];
    s16 status;
    s32 temp_r0_2;
    s32 temp_r4_2, var_r5, temp_r0_5, temp_r0_6, temp_r0_7;
    u32 temp_r0_4, var_ctr, var_ctr_2;
    u8 temp_r4_3, temp_r4_4;
    u8 *var_r7;
    s32 temp_r7, temp_r6, temp_r3_8, zeroPass, zeroCount;
    u8 *zeroBase, *zeroRow, *zeroGroup;
    space.layout.table += 0x3418;
    arg0->field278 = arg3;
    *(s32 *)(volatile void *)((volatile u8 *)arg0 + 8) = 0;
    lbl_8055DD88 = arg1;
    if (((s16 (*)(s32, s32, s32))fn_800BDD7C)(arg0->field278, arg2, (s32)((u8 *)arg0 + 8)) == 0)
        return 8;
    temp_r17 = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    if (fn_800BDE18(arg0->field278, arg2, 2, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8)) != 1)
        return 0xD;
    var_r14 = *(s32 *)(volatile void *)((volatile u8 *)arg0 + 8) - 0xF;
    if (var_r14 < 0)
        var_r14 += arg0->field278 * 8;
    if (temp_r17 == 0) {
        space.early.spEC = 1;
        *(s32 *)((u8 *)arg0 + 4) = 1;
    } else {
        space.early.spEC = 2;
        *(s32 *)((u8 *)arg0 + 4) = 0;
    }
    space.early.spE2 = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    result = fn_800BDE18(arg0->field278, arg2, 0x10, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    type = (result >> 12) & 0xF;
    if (type == 0) return 0xE;
    if (type == 0xF) return 0xE;
    status = (result >> 10) & 3;
    *(s16 *)((u8 *)arg0 + 0x1C) = status;
    if (status == 3) return 0xF;
    tile = (result >> 6) & 3;
    *(u8 *)arg0 = tile == 3 ? 1 : 2;
    *(s16 *)((u8 *)arg0 + 0x1E) = (result >> 4) & 3;
    if (*(s32 *)((u8 *)arg0 + 4) == 0)
        space.early.spE4 = ((s16 *)(space.layout.table + (status << 5)))[type] * 8;
    else
        space.early.spE4 = ((s16 *)(space.layout.table + 0x60 + (status << 5)))[type] * 8;
    if (((result >> 9) & 1) == 1) space.early.spE4 += 8;
    *arg5 = space.early.spE4 / 8;
    space.early.spE8 = var_r14 + space.early.spE4;
    if (space.early.spE2 == 0)
        fn_800BDE18(arg0->field278, arg2, 0x10, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    space.early.spE0 = fn_800BDE18(arg0->field278, arg2, 9 - *(s32 *)((u8 *)arg0 + 4), (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    bitDepth = (result >> 6) & 3;
    if (bitDepth == 3)
        fn_800BDE18(arg0->field278, arg2, 5 - (*(s32 *)((u8 *)arg0 + 4) * 4), (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    else
        fn_800BDE18(arg0->field278, arg2, 3 - *(s32 *)((u8 *)arg0 + 4), (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
    if (*(s32 *)((u8 *)arg0 + 4) == 0) {
        spCursor = (s16 *)space.early.spA0;
        var_r17 = 0;
    loop31:
        if (var_r17 < (s8)*(u8 *)arg0) {
            result = fn_800BDE18(arg0->field278, arg2, 4, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            spCursor[0] = (result >> 3) & 1;
            var_r17 += 1;
            spCursor[1] = (result >> 2) & 1;
            spCursor[2] = (result >> 1) & 1;
            spCursor[3] = result & 1;
            spCursor += 4;
            goto loop31;
        }
    }
    for (s32 pass = 0; pass < space.early.spEC; ++pass) {
        for (s32 i = 0; i < (s8)*(u8 *)arg0; ++i) {
            s32 index = pass * 2 + i;
            s32 value;
            samplesC[index] = fn_800BDE18(arg0->field278, arg2, 0xC, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            samples9[index] = fn_800BDE18(arg0->field278, arg2, 9, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            samples8[index] = fn_800BDE18(arg0->field278, arg2, 8, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            if (*(s32 *)((u8 *)arg0 + 4) == 0)
                samples4[index] = fn_800BDE18(arg0->field278, arg2, 4, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            else
                samples4[index] = fn_800BDE18(arg0->field278, arg2, 9, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            value = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            flags[index] = value;
            if ((s8)value == 1) {
                modeBits[index] = fn_800BDE18(arg0->field278, arg2, 2, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
                secondary[index] = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
                value = fn_800BDE18(arg0->field278, arg2, 0xA, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
                colorA[index][0] = (value >> 5) & 0x1F;
                colorA[index][1] = value & 0x1F;
                value = fn_800BDE18(arg0->field278, arg2, 9, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
                colorB[index][0] = (value >> 6) & 7;
                colorB[index][1] = (value >> 3) & 7;
                colorB[index][2] = value & 7;
                switch ((s8)modeBits[index]) {
                case 0: rowBits[index] = 1; break;
                case 1: rowBits[index] = 2; break;
                case 3: rowBits[index] = 4; break;
                default: rowBits[index] = secondary[index] != 0 ? 8 : 0x10; break;
                }
            } else {
                rowBits[index] = 0;
                secondary[index] = 0;
                value = fn_800BDE18(arg0->field278, arg2, 0xF, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
                colorA[index][0] = (value >> 10) & 0x1F;
                colorA[index][1] = (value >> 5) & 0x1F;
                colorA[index][2] = value & 0x1F;
                value = fn_800BDE18(arg0->field278, arg2, 7, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
                colorC[index] = (value >> 3) & 0xF;
                colorD[index] = value & 7;
                rowBits[index] = 1;
            }
            if (*(s32 *)((u8 *)arg0 + 4) == 0)
                colorE[index] = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            colorF[index] = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
            colorG[index] = fn_800BDE18(arg0->field278, arg2, 1, (s32 *)(volatile void *)((volatile u8 *)arg0 + 8));
        }
    }
    temp_r4_2 = *(s32 *)(volatile void *)((volatile u8 *)arg0 + 8);
    if (temp_r4_2 < 0)
        var_r5 = (space.early.spE8 >> 3) - ((temp_r4_2 >> 3) + arg0->field278);
    else
        var_r5 = (space.early.spE8 >> 3) - (temp_r4_2 >> 3);
    *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)((u8 *)arg0 + 0x14) >> 3;
    var_r7 = (u8 *)arg2 + (*(s32 *)(volatile void *)((volatile u8 *)arg0 + 8) >> 3);
    if (var_r5 != 0) {
        temp_r0_4 = (u32)var_r5 >> 2;
        var_ctr = temp_r0_4;
        if (temp_r0_4 != 0) {
            do {
                *(u8 *)((u8 *)arg0 + 0xCD70 + (*(s32 *)((u8 *)arg0 + 0x18) & 0x1FFF)) = var_r7[0];
                temp_r0_5 = *(s32 *)((u8 *)arg0 + 0x18) + 1;
                *(s32 *)((u8 *)arg0 + 0x18) = temp_r0_5;
                *(u8 *)((u8 *)arg0 + 0xCD70 + (temp_r0_5 & 0x1FFF)) = var_r7[1];
                temp_r0_6 = *(s32 *)((u8 *)arg0 + 0x18) + 1;
                *(s32 *)((u8 *)arg0 + 0x18) = temp_r0_6;
                *(u8 *)((u8 *)arg0 + 0xCD70 + (temp_r0_6 & 0x1FFF)) = var_r7[2];
                temp_r4_3 = var_r7[3];
                var_r7 += 4;
                temp_r0_7 = *(s32 *)((u8 *)arg0 + 0x18) + 1;
                *(s32 *)((u8 *)arg0 + 0x18) = temp_r0_7;
                *(u8 *)((u8 *)arg0 + 0xCD70 + (temp_r0_7 & 0x1FFF)) = temp_r4_3;
                *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)((u8 *)arg0 + 0x18) + 1;
                var_ctr -= 1;
            } while (var_ctr != 0);
            var_r5 &= 3;
            if (var_r5 != 0)
                goto block61;
        } else {
block61:
            var_ctr_2 = var_r5;
            do {
                temp_r4_4 = *var_r7;
                var_r7 += 1;
                *(u8 *)((u8 *)arg0 + 0xCD70 + (*(s32 *)((u8 *)arg0 + 0x18) & 0x1FFF)) = temp_r4_4;
                *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)((u8 *)arg0 + 0x18) + 1;
                var_ctr_2 -= 1;
            } while (var_ctr_2 != 0);
        }
    }
    temp_r7 = (*(s32 *)((u8 *)arg0 + 0x18) * 8) & 0xFFF8;
    *(s32 *)((u8 *)arg0 + 0x14) = temp_r7;
    if (*(s32 *)((u8 *)arg0 + 4) == 0) {
        temp_r6 = *(s32 *)((u8 *)arg0 + 0x10);
        *(s32 *)((u8 *)arg0 + 0x10) = (temp_r7 - (space.early.spE0 * 8)) - (space.early.spE4 - *(s16 *)((u8 *)&lbl_80560DA0 + (((s8)*(u8 *)arg0 - 1) * 4) + (space.early.spE2 * 2)));
    } else {
        temp_r6 = *(s32 *)((u8 *)arg0 + 0x10);
        *(s32 *)((u8 *)arg0 + 0x10) = (temp_r7 - (space.early.spE0 * 8)) - (space.early.spE4 - *(s16 *)((u8 *)&lbl_80560DA8 + (((s8)*(u8 *)arg0 - 1) * 4) + (space.early.spE2 * 2)));
    }
    temp_r6 = *(s32 *)((u8 *)arg0 + 0x10);
    *(s16 *)((u8 *)arg0 + 0x288) = ((s16 *)(space.layout.table + 0xC0 + (*(s32 *)((u8 *)arg0 + 4) * 6)))[*(s16 *)((u8 *)arg0 + 0x1C)];
    if (temp_r6 < 0) {
        temp_r3_8 = *(s32 *)((u8 *)arg0 + 0xC);
        if (temp_r3_8 == 0 && ((-temp_r6 + 0x200000) - temp_r3_8) > 0x200000) {
            zeroBase = (u8 *)lbl_8055DD88;
            zeroPass = 0;
            while (zeroPass < space.early.spEC) {
                zeroRow = zeroBase;
                zeroCount = 0x30;
                do {
                    ((s16 *)zeroRow)[0] = 0;
                    ((s16 *)zeroRow)[1] = 0;
                    ((s16 *)zeroRow)[2] = 0;
                    ((s16 *)zeroRow)[3] = 0;
                    ((s16 *)zeroRow)[4] = 0;
                    ((s16 *)zeroRow)[5] = 0;
                    ((s16 *)zeroRow)[6] = 0;
                    ((s16 *)zeroRow)[7] = 0;
                    zeroGroup = zeroRow + 0x10;
                    lbl_8055DD88 = zeroGroup;
                    ((s16 *)zeroRow)[8] = 0;
                    ((s16 *)zeroRow)[9] = 0;
                    ((s16 *)zeroRow)[10] = 0;
                    ((s16 *)zeroRow)[11] = 0;
                    ((s16 *)zeroRow)[12] = 0;
                    ((s16 *)zeroRow)[13] = 0;
                    ((s16 *)zeroRow)[14] = 0;
                    ((s16 *)zeroRow)[15] = 0;
                    zeroRow += 0x10;
                    zeroGroup = zeroRow + 0x10;
                    lbl_8055DD88 = zeroGroup;
                    ((s16 *)zeroRow)[8] = 0;
                    ((s16 *)zeroGroup)[1] = 0;
                    ((s16 *)zeroGroup)[2] = 0;
                    ((s16 *)zeroGroup)[3] = 0;
                    ((s16 *)zeroGroup)[4] = 0;
                    ((s16 *)zeroGroup)[5] = 0;
                    ((s16 *)zeroGroup)[6] = 0;
                    ((s16 *)zeroGroup)[7] = 0;
                    zeroBase = zeroGroup + 0x10;
                    zeroRow = zeroBase;
                    lbl_8055DD88 = zeroBase;
                    zeroCount -= 1;
                } while (zeroCount != 0);
                zeroPass += 1;
            }
        }
    }
    {
        s16 *p40 = (s16 *)(u8 *)&space.frame[0x40];
        s16 *p58 = (s16 *)(u8 *)&space.frame[0x58];
        s16 *pB0 = (s16 *)(u8 *)&space.frame[0xB0];
        s16 *p50 = (s16 *)(u8 *)&space.frame[0x50];
        s32 *p90 = rowBits;
        s16 *p2C = (s16 *)(u8 *)&space.frame[0x2C];
        s16 *p78 = (s16 *)(u8 *)&space.frame[0x78];
        s16 *p68 = (s16 *)(u8 *)&space.frame[0x68];
        s16 *p70 = (s16 *)(u8 *)&space.frame[0x70];
        s16 *p60 = samplesC;
        s16 *p48 = samples9;
        s16 *p80 = samples4;
        s16 *p88 = colorG;
        s16 *p20a = (s16 *)((u8 *)arg0 + 0x20);
        s16 *p20b = (s16 *)((u8 *)arg0 + 0x20);
        s16 *pC8 = (s16 *)((u8 *)arg0 + 0xC8);
        s16 *pC8aux = (s16 *)((u8 *)arg0 + 0xC8);
        s16 *pBBA0 = (s16 *)((u8 *)arg0 + 0xBBA0);
        u8 *outRing = (u8 *)arg0 + 0xCD70;
        s8 row = 0;
        while (row < (s8)*(u8 *)arg0) {
            fn_800C3DA0(arg0, outRing, *p90, p20a, p20b, pC8, *p60, *p80);
            fn_800C0440(arg0, (s32)outRing, pBBA0, *p48, *p90, *p70, *p68, *p88,
                        row, pC8aux, p2C);
            p40 += 1; p58 += 1; p68 += 1; p70 += 1; p90 += 1; p2C += 1;
            p60 += 1; pC8 += 0x24; pC8aux += 3; p20a += 0x15; p20b += 0x15;
            p80 += 1; p88 += 1; p48 += 1; pBBA0 += 0x258; row += 1;
        }
        p40 = (s16 *)(u8 *)&space.frame[0x40];
        p58 = (s16 *)(u8 *)&space.frame[0x58];
        pB0 = (s16 *)(u8 *)&space.frame[0xB0];
        p50 = (s16 *)(u8 *)&space.frame[0x50];
        p90 = rowBits;
        p2C = (s16 *)(u8 *)&space.frame[0x2C];
        p78 = (s16 *)(u8 *)&space.frame[0x78];
        row = 0;
        while (row < (s8)*(u8 *)arg0) {
            ((u32 (*)(void *, void *, void *, void *, void *, void *, s32 *, void *,
                      void *, void *, void *, void *, void *, void *, void *))fn_800BF048)(
                arg0, (u8 *)arg0 + 0x28A, (u8 *)arg0 + 0x4CA,
                (u8 *)arg0 + 0x70A, (u8 *)arg0 + 0x94A,
                (u8 *)arg0 + 0x974, p90, (u8 *)arg0 + 0xAB0,
                (u8 *)arg0 + 0xBBA0, p70, p68, p40,
                (u8 *)arg0 + 0x20, (u8 *)arg0 + 0xC8, p78);
            if (*(s16 *)((u8 *)arg0 + 0x1E) & 2)
                fn_800C57B0(*(s32 *)((u8 *)arg0 + 0x9BC),
                            *(s32 *)((u8 *)arg0 + 0x9C0),
                            *p90, (s32 *)((u8 *)arg0 + 0xAB0));
            if (*(s16 *)((u8 *)arg0 + 0x1E) & 1) {
                ((u32 (*)(void *, void *, void *, s32, void *, s16 *, s16 *, u32 *, s16))fn_800BC538)(
                    arg0, (u8 *)arg0 + 0x28A, (u8 *)arg0 + 0x94A,
                    p90[1], (void *)((u8 *)arg0 + 0xAB0),
                    (s16 *)((u8 *)arg0 + 0x20),
                    (s16 *)((u8 *)arg0 + 0xC8), (u32 *)p78, *p2C);
            }
            if ((*p90 & 0xF) != 0)
                fn_800BD970(*(s32 *)((u8 *)arg0 + 0x9C8),
                            *(s32 *)((u8 *)arg0 + 0x9BC),
                            (s8)*(u8 *)arg0, *p90, (s32 *)((u8 *)arg0 + 0xAB0));
            fn_800C0E7C(arg0, (u8 *)arg0 + 0x72B0,
                        (u8 *)arg0 + 0x96B0, (u8 *)arg0 + 0xA8B0,
                        p90, (u8 *)arg0 + 0xAB0);
            if (arg6 == 0) {
                fn_800C4CF4(arg0, (s32)((u8 *)arg0 + 0x52B0),
                            (s32)((u8 *)arg0 + 0xA8B0),
                            (s32)lbl_8055DD88, (s8)*(u8 *)arg0, arg6);
                lbl_8055DD88 = (u8 *)lbl_8055DD88 + (*(u8 *)arg0 * 0x480);
            } else {
                fn_800C4CF4(arg0, (s32)((u8 *)arg0 + 0x52B0),
                            (s32)((u8 *)arg0 + 0xA8B0),
                            (s32)lbl_8055DD88, (s8)*(u8 *)arg0, arg6);
                lbl_8055DD88 = (u8 *)lbl_8055DD88 + 0x480;
            }
            p40 += 2; p58 += 2; pB0 += 6; p50 += 2; p90 += 2; p2C += 1;
            p78 += 2; p68 += 2; p70 += 2; p60 += 2; p48 += 2;
            pC8 += 0x24; pC8aux += 0x24; p20a += 0x15; p20b += 0x15;
            pBBA0 += 0x4B0; row += 1;
        }
    }
    return 0;
}

void fn_800BEDE0(void *arg0, void *arg1) {
    u32 rate;
    s16 mode;
    *(s32 *)arg1 = *(u32 *)((u8 *)arg0 + 4) == 0;
    rate = 0xAC44;
    mode = *(s16 *)((u8 *)arg0 + 0x1C);
    if (mode == 0) {
    } else if (mode == 1) {
        rate = 0xBB80;
    } else if (mode == 2) {
        rate = 0x7D00;
    }
    if (*(s32 *)arg1 == 0)
        rate = (rate + (rate >> 31)) >> 1;
    *(u32 *)((u8 *)arg1 + 4) = rate;
    *(s32 *)((u8 *)arg1 + 8) = (s8)*(u8 *)arg0;
    *(s32 *)((u8 *)arg1 + 0x10) = *(s32 *)((u8 *)arg0 + 0xED74);
    *(s32 *)((u8 *)arg1 + 0xC) = *(s32 *)((u8 *)arg0 + 0xED70);
}

extern "C" s16 fn_800BDD7C(s32, s32, s32 *);
extern "C" s16 fn_800BDE18(s32, s32, s32, s32 *);
extern s16 lbl_802F3418[];
extern s16 lbl_802F3478[];
s32 fn_800BEE64(void *arg0, s32 arg1) {
    s32 sp8=0;
    s16 type, status;
    s32 value, result;
    if(fn_800BDD7C(0x400,arg1,&sp8)==0)return 8;
    type=fn_800BDE18(*(s32*)((u8*)arg0+0x278),arg1,1,&sp8);
    if(fn_800BDE18(*(s32*)((u8*)arg0+0x278),arg1,2,&sp8)!=1)return 0xD;
    *(s32*)((u8*)arg0+4)=type==0?1:0;
    fn_800BDE18(*(s32*)((u8*)arg0+0x278),arg1,1,&sp8);
    result=fn_800BDE18(*(s32*)((u8*)arg0+0x278),arg1,0x10,&sp8);
    type=(result>>12)&15;
    if(type==0||type==15)return 0xE;
    status=(result>>10)&3;
    *(s16*)((u8*)arg0+0x1c)=status;
    if(status==3)return 0xF;
    *(u8*)arg0=(((result>>6)&3)==3)?1:2;
    if(*(s32*)((u8*)arg0+4)==0)
        value=lbl_802F3418[(status<<4)+type]*8;
    else
        value=lbl_802F3478[(status<<4)+type]*8;
    value+=8;
    result=value/8;
    *(s32*)((u8*)arg0+0xed70)=result;
    if(value&7) *(s32*)((u8*)arg0+0xed70)=result+1;
    if(*(s32*)((u8*)arg0+4)==0)
        *(s32*)((u8*)arg0+0xed74)=(s8)*(u8*)arg0*0x900;
    else
        *(s32*)((u8*)arg0+0xed74)=(s8)*(u8*)arg0*0x480;
    return 0;
}

extern "C" u8 lbl_802F34E8[];
extern "C" u8 lbl_8031C098[];
extern "C" { DECL_SECTION(".sdata") extern u8 lbl_80560DB0[]; }
#pragma push
#pragma use_lmw_stmw on
void fn_800BF048(void *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, s32 *arg6, u8 *arg7, s16 *arg_sp8, s16 *arg_spC, s16 *arg_sp10, s16 *arg_sp14, s16 *arg_sp18, s16 *arg_sp1C, s16 *arg_sp20) {
    volatile s32 sp1C;
    volatile s32 sp18;
    volatile s32 sp14;
    volatile s32 sp10;
    volatile s32 spC;
    volatile s32 sp8;
    s16 *var_r14_4;
    s16 *var_r16_2;
    s16 *var_r17_6;
    s16 *var_r22;
    s16 temp_r0;
    s16 temp_r0_2;
    s16 temp_r11_2;
    s16 temp_r12;
    s16 temp_r12_12;
    s16 temp_r14_3;
    s16 temp_r16_2;
    s16 temp_r17;
    s16 temp_r19_2;
    s16 temp_r19_6;
    s16 temp_r19_7;
    s16 temp_r20;
    s16 temp_r24;
    s16 temp_r26_5;
    s16 temp_r26_6;
    s16 var_r0_2;
    s16 var_r0_4;
    s16 var_r0_5;
    s16 var_r15_2;
    s32 *var_r9;
    s32 temp_r0_11;
    s32 temp_r0_13;
    s32 temp_r0_19;
    s32 temp_r0_20;
    s32 temp_r0_3;
    s32 temp_r0_5;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r11;
    s32 temp_r11_4;
    s32 temp_r11_5;
    s32 temp_r11_6;
    s32 temp_r11_7;
    s32 temp_r12_11;
    s32 temp_r12_15;
    s32 temp_r12_17;
    s32 temp_r12_19;
    s32 temp_r12_20;
    s32 temp_r12_4;
    s32 temp_r12_6;
    s32 temp_r12_8;
    s32 temp_r12_9;
    s32 temp_r14;
    s32 temp_r14_7;
    s32 temp_r16_6;
    s32 temp_r16_7;
    s32 temp_r19;
    s32 temp_r20_2;
    s32 temp_r21;
    s32 temp_r21_2;
    s32 temp_r21_3;
    s32 temp_r21_4;
    s32 temp_r22_2;
    s32 temp_r22_7;
    s32 temp_r25;
    s32 temp_r25_3;
    s32 temp_r25_4;
    s32 temp_r25_5;
    s32 temp_r25_7;
    s32 temp_r25_8;
    s32 temp_r26_11;
    s32 temp_r26_3;
    s32 temp_r26_4;
    s32 temp_r26_8;
    s32 temp_r26_9;
    s32 temp_r27;
    s32 temp_r27_2;
    s32 temp_r27_3;
    s32 temp_r27_5;
    s32 temp_r28;
    s32 temp_r28_3;
    s32 temp_r28_4;
    s32 temp_r28_6;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r29_3;
    s32 temp_r29_4;
    s32 temp_r30;
    s32 var_ctr;
    s32 var_ctr_10;
    s32 var_ctr_2;
    s32 var_ctr_5;
    s32 var_ctr_8;
    s32 var_ctr_9;
    s32 var_r0_3;
    s32 var_r0_6;
    s32 var_r12_10;
    s32 var_r12_3;
    s32 var_r12_4;
    s32 var_r16_3;
    register s32 var_r17;
    s32 var_r17_3;
    s32 var_r17_5;
    s32 var_r18;
    s32 var_r18_2;
    s32 var_r18_3;
    s32 var_r18_5;
    s32 var_r21;
    s32 var_r21_3;
    s32 var_r0;
    s8 *var_r12_9;
    u16 temp_r0_15;
    u16 temp_r0_9;
    u16 temp_r12_10;
    u16 temp_r12_13;
    u16 temp_r12_16;
    u16 temp_r12_18;
    u16 temp_r12_21;
    u16 temp_r12_2;
    u16 temp_r12_5;
    u16 temp_r12_7;
    u16 temp_r17_2;
    u16 temp_r17_3;
    u16 temp_r17_4;
    u16 temp_r19_3;
    u16 temp_r19_4;
    u16 temp_r19_5;
    u32 temp_r0_10;
    u32 temp_r0_12;
    u32 temp_r0_16;
    u32 temp_r0_17;
    u32 temp_r0_18;
    u32 temp_r0_21;
    u32 temp_r0_4;
    u32 temp_r0_6;
    u32 temp_r11_3;
    u32 temp_r12_14;
    u32 temp_r12_3;
    u32 temp_r14_4;
    u32 temp_r14_5;
    u32 temp_r14_6;
    u32 temp_r16_3;
    u32 temp_r16_4;
    u32 temp_r16_5;
    u32 temp_r18;
    u32 temp_r18_2;
    u32 temp_r22_3;
    u32 temp_r22_4;
    u32 temp_r22_6;
    u32 temp_r26;
    u32 temp_r26_10;
    u32 temp_r26_2;
    u32 temp_r26_7;
    u32 temp_r27_4;
    u32 temp_r28_2;
    u32 temp_r28_5;
    u32 var_ctr_11;
    u32 var_ctr_12;
    u32 var_ctr_3;
    u32 var_ctr_4;
    u32 var_ctr_6;
    u32 var_ctr_7;
    u32 var_r11_3;
    u32 var_r11_4;
    u32 var_r11_7;
    u8 *var_r11_2;
    u8 *var_r11_5;
    u8 *var_r11_6;
    u8 *var_r12_11;
    register u8 *var_r12_2;
    u8 *var_r12_6;
    u8 *var_r12_8;
    u8 *var_r21_2;
    u8 temp_r0_14;
    u8 temp_r14_2;
    u8 temp_r15;
    u8 temp_r16;
    u8 temp_r22;
    register s32 var_r16;
    s32 var_r17_4;
    u8 *temp_r14_8;
    u8 *temp_r20_3;
    u8 *temp_r21_5;
    u8 *temp_r22_5;
    u8 *temp_r25_2;
    u8 *temp_r25_6;
    u8 *var_r10;
    u8 *var_r11;
    u8 *var_r12;
    u8 *var_r12_12;
    u8 *var_r12_5;
    u8 *var_r12_7;
    u8 *var_r14;
    register u8 *var_r14_2;
    u8 *var_r14_3;
    u8 *var_r14_5;
    u8 *var_r14_6;
    u8 *var_r15;
    u8 *var_r17_2;
    u8 *var_r18_4;

    register u8 *table = lbl_802F34E8;
    var_r9 = arg6;
    var_r10 = arg7;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x9D8) == 0) {
        temp_r11 = M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x9D8) = 1;
        if ((temp_r11 == 0) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 0)) {
            var_r14 = table + 0x5EC;
            M2C_FIELD(arg0, s32 *, 0x9C8) = 0x18;
            var_r15 = table + 0x6C8;
        } else if ((temp_r11 == 0) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 1)) {
            var_r14 = table + 0x618;
            M2C_FIELD(arg0, s32 *, 0x9C8) = 0x16;
            var_r15 = table + 0x710;
        } else if ((temp_r11 == 0) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 2)) {
            var_r14 = table + 0x644;
            M2C_FIELD(arg0, s32 *, 0x9C8) = 0x1F;
            var_r15 = table + 0x758;
        } else if ((temp_r11 == 1) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 0)) {
            var_r14 = table + 0x69C;
            M2C_FIELD(arg0, s32 *, 0x9C8) = 0x1D;
            var_r15 = table + 0x7A0;
        } else if ((temp_r11 == 1) && ((s16) M2C_FIELD(arg0, s16 *, 0x1C) == 1)) {
            var_r14 = table + 0x670;
            M2C_FIELD(arg0, s32 *, 0x9C8) = 0x1E;
            var_r15 = table + 0x7E8;
        } else {
            var_r14 = table + 0x69C;
            M2C_FIELD(arg0, s32 *, 0x9C8) = 0x1D;
            var_r15 = table + 0x830;
        }
        var_r12 = arg5;
        M2C_FIELD(arg4, s16 *, 0) = (s16) M2C_FIELD(var_r14, s16 *, 0);
        M2C_FIELD(arg4, s16 *, 2) = (s16) M2C_FIELD(var_r14, s16 *, 2);
        M2C_FIELD(arg4, s16 *, 4) = (s16) M2C_FIELD(var_r14, s16 *, 4);
        M2C_FIELD(arg4, s16 *, 6) = (s16) M2C_FIELD(var_r14, s16 *, 6);
        M2C_FIELD(arg4, s16 *, 8) = (s16) M2C_FIELD(var_r14, s16 *, 8);
        M2C_FIELD(arg4, s16 *, 0xA) = (s16) M2C_FIELD(var_r14, s16 *, 0xA);
        M2C_FIELD(arg4, s16 *, 0xC) = (s16) M2C_FIELD(var_r14, s16 *, 0xC);
        M2C_FIELD(arg4, s16 *, 0xE) = (s16) M2C_FIELD(var_r14, s16 *, 0xE);
        M2C_FIELD(arg4, s16 *, 0x10) = (s16) M2C_FIELD(var_r14, s16 *, 0x10);
        M2C_FIELD(arg4, s16 *, 0x12) = (s16) M2C_FIELD(var_r14, s16 *, 0x12);
        M2C_FIELD(arg4, s16 *, 0x14) = (s16) M2C_FIELD(var_r14, s16 *, 0x14);
        M2C_FIELD(arg4, s16 *, 0x16) = (s16) M2C_FIELD(var_r14, s16 *, 0x16);
        M2C_FIELD(arg4, s16 *, 0x18) = (s16) M2C_FIELD(var_r14, s16 *, 0x18);
        M2C_FIELD(arg4, s16 *, 0x1A) = (s16) M2C_FIELD(var_r14, s16 *, 0x1A);
        M2C_FIELD(arg4, s16 *, 0x1C) = (s16) M2C_FIELD(var_r14, s16 *, 0x1C);
        M2C_FIELD(arg4, s16 *, 0x1E) = (s16) M2C_FIELD(var_r14, s16 *, 0x1E);
        M2C_FIELD(arg4, s16 *, 0x20) = (s16) M2C_FIELD(var_r14, s16 *, 0x20);
        M2C_FIELD(arg4, s16 *, 0x22) = (s16) M2C_FIELD(var_r14, s16 *, 0x22);
        M2C_FIELD(arg4, s16 *, 0x24) = (s16) M2C_FIELD(var_r14, s16 *, 0x24);
        M2C_FIELD(arg4, s16 *, 0x26) = (s16) M2C_FIELD(var_r14, s16 *, 0x26);
        M2C_FIELD(arg4, s16 *, 0x28) = (s16) M2C_FIELD(var_r14, s16 *, 0x28);
        for (var_ctr = 0; var_ctr < 2; var_ctr++) {
            M2C_FIELD(var_r12, s16 *, 0) = (s16) M2C_FIELD(var_r15, s16 *, 0);
            M2C_FIELD(var_r12, s16 *, 2) = (s16) M2C_FIELD(var_r15, s16 *, 2);
            M2C_FIELD(var_r12, s16 *, 4) = (s16) M2C_FIELD(var_r15, s16 *, 4);
            M2C_FIELD(var_r12, s16 *, 6) = (s16) M2C_FIELD(var_r15, s16 *, 6);
            M2C_FIELD(var_r12, s16 *, 8) = (s16) M2C_FIELD(var_r15, s16 *, 8);
            M2C_FIELD(var_r12, s16 *, 0xA) = (s16) M2C_FIELD(var_r15, s16 *, 0xA);
            M2C_FIELD(var_r12, s16 *, 0xC) = (s16) M2C_FIELD(var_r15, s16 *, 0xC);
            M2C_FIELD(var_r12, s16 *, 0xE) = (s16) M2C_FIELD(var_r15, s16 *, 0xE);
            M2C_FIELD(var_r12, s16 *, 0x10) = (s16) M2C_FIELD(var_r15, s16 *, 0x10);
            M2C_FIELD(var_r12, s16 *, 0x12) = (s16) M2C_FIELD(var_r15, s16 *, 0x12);
            M2C_FIELD(var_r12, s16 *, 0x14) = (s16) M2C_FIELD(var_r15, s16 *, 0x14);
            M2C_FIELD(var_r12, s16 *, 0x16) = (s16) M2C_FIELD(var_r15, s16 *, 0x16);
            M2C_FIELD(var_r12, s16 *, 0x18) = (s16) M2C_FIELD(var_r15, s16 *, 0x18);
            M2C_FIELD(var_r12, s16 *, 0x1A) = (s16) M2C_FIELD(var_r15, s16 *, 0x1A);
            M2C_FIELD(var_r12, s16 *, 0x1C) = (s16) M2C_FIELD(var_r15, s16 *, 0x1C);
            M2C_FIELD(var_r12, s16 *, 0x1E) = (s16) M2C_FIELD(var_r15, s16 *, 0x1E);
            M2C_FIELD(var_r12, s16 *, 0x20) = (s16) M2C_FIELD(var_r15, s16 *, 0x20);
            temp_r0 = M2C_FIELD(var_r15, s16 *, 0x22);
            var_r15 += 0x24;
            M2C_FIELD(var_r12, s16 *, 0x22) = temp_r0;
            var_r12 += 0x24;
            }
        M2C_FIELD(arg0, s32 *, 0x9BC) = (s32) M2C_FIELD(arg4, s16 *, 0x28);
        M2C_FIELD(arg0, s32 *, 0x9C4) = (s32) M2C_FIELD(arg5, s16 *, 0x46);
        M2C_FIELD(arg0, u32 *, 0x9C0) = (u32) (M2C_FIELD(arg5, s16 *, 0x46) / 3);
    }
    sp14 = 0;
loop_236:
    if (sp14 < (s8) M2C_FIELD(arg0, u8 *, 0)) {
        temp_r0_2 = *arg_sp14;
        if (M2C_FIELD(arg0, s16 *, 0x1E) & 2) {
            var_r15_2 = *arg_spC - 2;
        } else {
            var_r15_2 = *arg_spC;
        }
        if (var_r15_2 < 0) {
            var_r15_2 = 0;
        }
        temp_r14 = *var_r9;
        temp_r15 = *(table + 0x400 + var_r15_2);
        temp_r24 = *(s16 *)(lbl_80560DB0 + ((var_r15_2 * 2) & 6));
        if (temp_r14 & 7) {
            if ((s32) M2C_FIELD(arg0, s32 *, 0x9D0) == 0) {
                var_r12_2 = arg1;
                M2C_FIELD(arg0, s32 *, 0x9D0) = 1;
                var_r17 = 0;
loop_39:
                if (var_r17 < (s32) M2C_FIELD(arg0, s32 *, 0x9BC)) {
                    var_r14_2 = arg4;
                    var_r16 = 0;
                    for (var_ctr_2 = 0; var_ctr_2 < 3; var_ctr_2++) {
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 0)) break;
                        var_r16 += 1;
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 2)) break;
                        var_r16 += 1;
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 4)) break;
                        var_r16 += 1;
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 6)) break;
                        var_r16 += 1;
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 8)) break;
                        var_r16 += 1;
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 0xA)) break;
                        var_r16 += 1;
                        if (var_r17 < (s16) M2C_FIELD(var_r14_2, s16 *, 0xC)) break;
                        var_r14_2 += 0xE;
                        var_r16 += 1;
                    }
                    *var_r12_2 = var_r16;
                    var_r17 += 1;
                    var_r12_2 += 1;
                    goto loop_39;
                }
            }
            if (temp_r15 > 0x33U) {
                var_r11 = var_r10;
                var_r12_3 = 0;
loop_43:
                if (var_r12_3 < (s32) M2C_FIELD(arg0, s32 *, 0x9BC)) {
                    M2C_FIELD(var_r11, s32 *, 0x1B00) = 0;
                    var_r11 += 4;
                    var_r12_3 += 1;
                    goto loop_43;
                }
            } else {
                var_r16_2 = arg_sp8;
                var_r17_2 = var_r10;
                var_r11_2 = arg1;
                var_r21 = 0;
loop_74:
                if (var_r21 < (s32) M2C_FIELD(arg0, s32 *, 0x9BC)) {
                    temp_r20 = *var_r16_2;
                    var_r0 = temp_r20;
                    if (temp_r20 == 0) {
                        M2C_FIELD(var_r17_2, s32 *, 0x1B00) = 0;
                    } else {
                        temp_r14_2 = *var_r11_2;
                        temp_r12 = ((s8) *(table + 0x500 + temp_r14_2) * *arg_sp20) + *(s16 *)((u8 *)arg_sp18 + (temp_r14_2 * 2));
                        temp_r14_3 = *(s16 *)(table + 0x518 + (temp_r0_2 * 0x46) + (temp_r12 * 2));
                        if (temp_r20 < 0) {
                            var_r0 = -temp_r20;
                        }
                        if (var_r0 > 0x1FFF) {
                            var_r0 = 0x1FFF;
                        }
                        temp_r12_2 = temp_r15 + *(table + 0x5A4 + (temp_r0_2 * 0x23) + temp_r12);
                        if (!(var_r0 & 0x1F00)) {
                            temp_r0_3 = *(s32 *)(table + (var_r0 * 4));
                            if (temp_r14_3 == 1) {
                                temp_r12_3 = temp_r0_3 * temp_r24;
                                temp_r12_4 = ((s32)(((s64)temp_r0_3 * (s64)temp_r24) >> 20));
                                if (temp_r12_2 > 0x14U) {
                                    var_r12_4 = temp_r12_4 >> (temp_r12_2 - 0x14);
                                } else {
                                    var_r12_4 = temp_r12_4 << (0x14 - temp_r12_2);
                                }
                            } else {
                                temp_r25 = (s32) (temp_r24 * temp_r14_3) >> 4;
                                if (temp_r12_2 > 0x14U) {
                                    temp_r14_4 = temp_r25 * temp_r0_3;
                                    temp_r12_5 = temp_r12_2 - 8;
                                    temp_r12_6 = (((temp_r14_4 << 8) | (temp_r14_4 >> 0x18U)) & ~0xFFFFFF00) | (((s32)(((s64)(temp_r25) * (s64)(temp_r0_3)) >> 32)) << 8);
                                    if (temp_r12_5 < 0x14U) {
                                        var_r12_4 = temp_r12_6 << (0x14 - temp_r12_5);
                                    } else {
                                        var_r12_4 = temp_r12_6 >> (temp_r12_5 - 0x14);
                                    }
                                } else {
                                    temp_r14_5 = temp_r25 * temp_r0_3;
                                    temp_r12_7 = temp_r12_2 - 4;
                                    temp_r12_8 = ((s32)(((s64)temp_r25 * (s64)temp_r0_3) >> 20));
                                    if (temp_r12_7 < 0x14U) {
                                        var_r12_4 = temp_r12_8 << (0x14 - temp_r12_7);
                                    } else {
                                        var_r12_4 = temp_r12_8 >> (temp_r12_7 - 0x14);
                                    }
                                }
                            }
                        } else {
                            temp_r29 = var_r0 * var_r0;
                            temp_r25_2 = lbl_8031C098 + ((var_r0 >> 8) * 0x10);
                            temp_r28 = M2C_FIELD(temp_r25_2, s32 *, 0);
                            temp_r27 = M2C_FIELD(temp_r25_2, s32 *, 4);
                            temp_r0_4 = temp_r29 * temp_r28;
                            temp_r28_2 = temp_r27 * var_r0;
                            temp_r0_5 = ((s32) (((s32)(((s64)temp_r29 * (s64)temp_r28) >> 20)) + ((s32)(((s64)temp_r27 * (s64)var_r0) >> 20)) + M2C_FIELD(temp_r25_2, s32 *, 8)) >> 4) + M2C_FIELD(temp_r25_2, s32 *, 0xC);
                            if (temp_r14_3 == 1) {
                                temp_r12_9 = temp_r0_5 * temp_r24;
                                if (temp_r12_2 > 0x14U) {
                                    var_r12_4 = temp_r12_9 >> (temp_r12_2 - 0x14);
                                } else {
                                    var_r12_4 = temp_r12_9 << (0x14 - temp_r12_2);
                                }
                            } else {
                                temp_r25_3 = temp_r24 * temp_r14_3;
                                temp_r12_10 = temp_r12_2 - 8;
                                temp_r14_6 = temp_r25_3 * temp_r0_5;
                                temp_r14_7 = (((temp_r14_6 << 0x18) | (temp_r14_6 >> 8U)) & ~0xFF000000) | (((s32)(((s64)(temp_r25_3) * (s64)(temp_r0_5)) >> 32)) << 0x18);
                                var_r12_4 = temp_r14_7 >> (temp_r12_10 - 0x14);
                                if (temp_r12_10 < 0x14U) {
                                    var_r12_4 = temp_r14_7 << (0x14 - temp_r12_10);
                                }
                            }
                        }
                        if (temp_r20 < 0) {
                            M2C_FIELD(var_r17_2, s32 *, 0x1B00) = (s32) -var_r12_4;
                        } else {
                            M2C_FIELD(var_r17_2, s32 *, 0x1B00) = var_r12_4;
                        }
                    }
                    var_r16_2 += 2;
                    var_r17_2 += 4;
                    var_r21 += 1;
                    var_r11_2 += 1;
                    goto loop_74;
                }
                var_r12_5 = var_r10 + (var_r21 * 4);
                var_r11_3 = 0x240 - var_r21;
                if (var_r21 < 0x240) {
                    temp_r0_6 = var_r11_3 >> 3U;
                    var_ctr_3 = temp_r0_6;
                    if (temp_r0_6 != 0) {
                        do {
                            M2C_FIELD(var_r12_5, s32 *, 0x1B00) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B04) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B08) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B0C) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B10) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B14) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B18) = 0;
                            M2C_FIELD(var_r12_5, s32 *, 0x1B1C) = 0;
                            var_r12_5 += 0x20;
                            var_ctr_3 -= 1;
                        } while (var_ctr_3 != 0);
                        var_r11_3 &= 7;
                        if (var_r11_3 != 0) {
                            goto block_79;
                        }
                    } else {
block_79:
                        var_ctr_4 = var_r11_3;
                        do {
                            M2C_FIELD(var_r12_5, s32 *, 0x1B00) = 0;
                            var_r12_5 += 4;
                            var_ctr_4 -= 1;
                        } while (var_ctr_4 != 0);
                    }
                }
            }
        } else if (temp_r14 & 0x10) {
            sp8 = -1;
            spC = -1;
            sp10 = -1;
            if ((s32) M2C_FIELD(arg0, s32 *, 0x9D4) == 0) {
                var_r12_6 = arg2;
                M2C_FIELD(arg0, s32 *, 0x9D4) = 1;
                var_r17_3 = 0;
loop_97:
                if (var_r17_3 < (s32) M2C_FIELD(arg0, s32 *, 0x9C4)) {
                    var_r14_3 = arg5;
                    var_r18 = 0;
                    var_ctr_5 = 4;
loop_86:
                    if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 0)) {
                        var_r18 += 1;
                        if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 2)) {
                            var_r18 += 1;
                            if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 4)) {
                                var_r18 += 1;
                                if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 6)) {
                                    var_r18 += 1;
                                    if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 8)) {
                                        var_r18 += 1;
                                        if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 0xA)) {
                                            var_r18 += 1;
                                            if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 0xC)) {
                                                var_r18 += 1;
                                                if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 0xE)) {
                                                    var_r18 += 1;
                                                    if (var_r17_3 >= (s16) M2C_FIELD(var_r14_3, s16 *, 0x10)) {
                                                        var_r14_3 += 0x12;
                                                        var_r18 += 1;
                                                        var_ctr_5 -= 1;
                                                        if (var_ctr_5 != 0) {
                                                            goto loop_86;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    var_r17_3 += 1;
                    *var_r12_6 = (var_r18 % 3) + ((var_r18 / 3) * 0x10);
                    var_r12_6 += 1;
                    goto loop_97;
                }
            }
            var_r14_4 = arg_sp8;
            var_r21_2 = arg2;
            var_r18_2 = 0;
loop_130:
            if (var_r18_2 < (s32) M2C_FIELD(arg0, s32 *, 0x9C4)) {
                temp_r17 = *var_r14_4;
                var_r0_2 = temp_r17;
                if (temp_r17 > 0x1FFF) {
                    var_r0_2 = 0x1FFF;
                }
                temp_r22 = *var_r21_2;
                temp_r19 = (temp_r22 * 4) & 0x3C;
                temp_r20_2 = temp_r22 & 0xF;
                temp_r12_11 = *(&sp8 + temp_r19) + 1;
                *(&sp8 + temp_r19) = temp_r12_11;
                if ((temp_r15 > 0x33U) || (var_r0_2 == 0)) {
                    *(s32 *)(var_r10 + (temp_r20_2 * 0x900) + (temp_r12_11 * 4)) = 0;
                } else {
                    temp_r22_2 = temp_r20_2 * 2;
                    temp_r19_2 = *((((temp_r22 >> 4U) & 0xF) * 6) + (temp_r22_2 + arg_sp1C));
                    temp_r11_2 = *(s16 *)(table + 0x518 + (temp_r0_2 * 0x46) + (temp_r19_2 * 2));
                    if (var_r0_2 < 0) {
                        var_r0_2 = -var_r0_2;
                    }
                    temp_r19_3 = *(table + 0x5A4 + (temp_r0_2 * 0x23) + temp_r19_2) + ((s16) (*(s16 *)((u8 *)arg_sp10 + temp_r22_2) * 2) + temp_r15);
                    if (var_r0_2 > 0x1FFF) {
                        var_r0_2 = 0x1FFF;
                    }
                    if (!(var_r0_2 & 0x1F00)) {
                        temp_r0_7 = *(s32 *)(table + (var_r0_2 * 4));
                        if (temp_r11_2 == 1) {
                            temp_r11_3 = temp_r0_7 * temp_r24;
                            temp_r11_4 = ((s32)(((s64)temp_r0_7 * (s64)temp_r24) >> 20));
                            if (temp_r19_3 > 0x14U) {
                                var_r0_3 = temp_r11_4 >> (temp_r19_3 - 0x14);
                            } else {
                                var_r0_3 = temp_r11_4 << (0x14 - temp_r19_3);
                            }
                        } else {
                            temp_r11_5 = (s32) (temp_r24 * temp_r11_2) >> 4;
                            if (temp_r19_3 > 0x14U) {
                                temp_r22_3 = temp_r11_5 * temp_r0_7;
                                temp_r19_4 = temp_r19_3 - 8;
                                temp_r11_6 = (((temp_r22_3 << 8) | (temp_r22_3 >> 0x18U)) & ~0xFFFFFF00) | (((s32)(((s64)(temp_r11_5) * (s64)(temp_r0_7)) >> 32)) << 8);
                                if (temp_r19_4 < 0x14U) {
                                    var_r0_3 = temp_r11_6 << (0x14 - temp_r19_4);
                                } else {
                                    var_r0_3 = temp_r11_6 >> (temp_r19_4 - 0x14);
                                }
                            } else {
                                temp_r22_4 = temp_r11_5 * temp_r0_7;
                                temp_r19_5 = temp_r19_3 - 4;
                                temp_r11_7 = ((s32)(((s64)temp_r11_5 * (s64)temp_r0_7) >> 20));
                                if (temp_r19_5 < 0x14U) {
                                    var_r0_3 = temp_r11_7 << (0x14 - temp_r19_5);
                                } else {
                                    var_r0_3 = temp_r11_7 >> (temp_r19_5 - 0x14);
                                }
                            }
                        }
                    } else {
                        temp_r22_5 = lbl_8031C098 + ((var_r0_2 >> 8) * 0x10);
                        temp_r29_2 = var_r0_2 * var_r0_2;
                        temp_r28_3 = M2C_FIELD(temp_r22_5, s32 *, 0);
                        temp_r27_2 = M2C_FIELD(temp_r22_5, s32 *, 4);
                        temp_r26 = temp_r29_2 * temp_r28_3;
                        temp_r26_2 = temp_r27_2 * var_r0_2;
                        temp_r26_3 = ((s32) (((s32)(((s64)temp_r29_2 * (s64)temp_r28_3) >> 20)) + ((s32)(((s64)temp_r27_2 * (s64)var_r0_2) >> 20)) + M2C_FIELD(temp_r22_5, s32 *, 8)) >> 4) + M2C_FIELD(temp_r22_5, s32 *, 0xC);
                        if (temp_r11_2 == 1) {
                            temp_r0_8 = temp_r26_3 * temp_r24;
                            if (temp_r19_3 > 0x14U) {
                                var_r0_3 = temp_r0_8 >> (temp_r19_3 - 0x14);
                            } else {
                                var_r0_3 = temp_r0_8 << (0x14 - temp_r19_3);
                            }
                        } else {
                            temp_r25_4 = temp_r24 * temp_r11_2;
                            temp_r0_9 = temp_r19_3 - 8;
                            temp_r22_6 = temp_r25_4 * temp_r26_3;
                            temp_r22_7 = (((temp_r22_6 << 0x18) | (temp_r22_6 >> 8U)) & ~0xFF000000) | (((s32)(((s64)(temp_r25_4) * (s64)(temp_r26_3)) >> 32)) << 0x18);
                            var_r0_3 = temp_r22_7 >> (temp_r0_9 - 0x14);
                            if (temp_r0_9 < 0x14U) {
                                var_r0_3 = temp_r22_7 << (0x14 - temp_r0_9);
                            }
                        }
                    }
                    if (temp_r17 < 0) {
                        *(s32 *)(var_r10 + (temp_r20_2 * 0x900) + (temp_r12_11 * 4)) = -var_r0_3;
                    } else {
                        *(s32 *)(var_r10 + (temp_r20_2 * 0x900) + (temp_r12_11 * 4)) = var_r0_3;
                    }
                }
                var_r14_4 += 2;
                var_r18_2 += 1;
                var_r21_2 += 1;
                goto loop_130;
            }
            temp_r18 = var_r18_2 / 3;
            var_r11_4 = 0xC0 - temp_r18;
            var_r12_7 = var_r10 + (temp_r18 * 4);
            if ((s32) temp_r18 < 0xC0) {
                temp_r0_10 = var_r11_4 >> 3U;
                var_ctr_6 = temp_r0_10;
                if (temp_r0_10 != 0) {
                    do {
                        M2C_FIELD(var_r12_7, s32 *, 0) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x900) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1200) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 4) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x904) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1204) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 8) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x908) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1208) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0xC) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x90C) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x120C) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x10) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x910) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1210) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x14) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x914) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1214) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x18) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x918) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1218) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1C) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x91C) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x121C) = 0;
                        var_r12_7 += 0x20;
                        var_ctr_6 -= 1;
                    } while (var_ctr_6 != 0);
                    var_r11_4 &= 7;
                    if (var_r11_4 != 0) {
                        goto block_135;
                    }
                } else {
block_135:
                    var_ctr_7 = var_r11_4;
                    do {
                        M2C_FIELD(var_r12_7, s32 *, 0) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x900) = 0;
                        M2C_FIELD(var_r12_7, s32 *, 0x1200) = 0;
                        var_r12_7 += 4;
                        var_ctr_7 -= 1;
                    } while (var_ctr_7 != 0);
                }
            }
        } else {
            sp8 = 0xB;
            spC = 0xB;
            sp10 = 0xB;
            if ((s32) M2C_FIELD(arg0, s32 *, 0x9CC) == 0) {
                var_r12_8 = arg3;
                M2C_FIELD(arg0, s32 *, 0x9CC) = 1;
                var_r16_3 = 0;
                do {
                    var_r14_5 = arg4;
                    var_r17_4 = 0;
                    var_ctr_8 = 3;
loop_141:
                    if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 0)) {
                        var_r17_4 += 1;
                        if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 2)) {
                            var_r17_4 += 1;
                            if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 4)) {
                                var_r17_4 += 1;
                                if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 6)) {
                                    var_r17_4 += 1;
                                    if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 8)) {
                                        var_r17_4 += 1;
                                        if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 0xA)) {
                                            var_r17_4 += 1;
                                            if (var_r16_3 >= (s16) M2C_FIELD(var_r14_5, s16 *, 0xC)) {
                                                var_r14_5 += 0xE;
                                                var_r17_4 += 1;
                                                var_ctr_8 -= 1;
                                                if (var_ctr_8 != 0) {
                                                    goto loop_141;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    var_r16_3 += 1;
                    *var_r12_8 = var_r17_4;
                    var_r12_8 += 1;
                } while (var_r16_3 < 0x24);
                var_r12_9 = (s8 *)(arg3 + 0x24);
                var_r17_5 = 0x24;
loop_163:
                if (var_r17_5 < (s32) M2C_FIELD(arg0, s32 *, 0x9C4)) {
                    var_r14_6 = arg5;
                    var_r18_3 = 0;
                    var_ctr_9 = 4;
loop_152:
                    if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 0)) {
                        var_r18_3 += 1;
                        if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 2)) {
                            var_r18_3 += 1;
                            if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 4)) {
                                var_r18_3 += 1;
                                if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 6)) {
                                    var_r18_3 += 1;
                                    if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 8)) {
                                        var_r18_3 += 1;
                                        if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 0xA)) {
                                            var_r18_3 += 1;
                                            if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 0xC)) {
                                                var_r18_3 += 1;
                                                if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 0xE)) {
                                                    var_r18_3 += 1;
                                                    if (var_r17_5 >= (s16) M2C_FIELD(var_r14_6, s16 *, 0x10)) {
                                                        var_r14_6 += 0x12;
                                                        var_r18_3 += 1;
                                                        var_ctr_9 -= 1;
                                                        if (var_ctr_9 != 0) {
                                                            goto loop_152;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    var_r17_5 += 1;
                    *var_r12_9 = (var_r18_3 % 3) + ((var_r18_3 / 3) * 0x10);
                    var_r12_9 += 1;
                    goto loop_163;
                }
            }
            var_r17_6 = arg_sp8;
            var_r18_4 = var_r10;
            var_r11_5 = arg3;
            temp_r20_3 = table + 0x518 + (temp_r0_2 * 0x46);
            temp_r14_8 = table + 0x5A4 + (temp_r0_2 * 0x23);
            var_ctr_10 = 0x24;
            do {
                temp_r19_6 = *var_r17_6;
                var_r0_4 = temp_r19_6;
                if ((temp_r15 > 0x33U) || (temp_r19_6 == 0)) {
                    M2C_FIELD(var_r18_4, s32 *, 0x1B00) = 0;
                } else {
                    temp_r16 = *var_r11_5;
                    temp_r12_12 = ((s8) *(table + 0x500 + temp_r16) * *arg_sp20) + *(s16 *)((u8 *)arg_sp18 + (temp_r16 * 2));
                    temp_r16_2 = *(s16 *)(temp_r20_3 + (temp_r12_12 * 2));
                    if (temp_r19_6 < 0) {
                        var_r0_4 = -temp_r19_6;
                    }
                    if (var_r0_4 > 0x1FFF) {
                        var_r0_4 = 0x1FFF;
                    }
                    temp_r12_13 = temp_r15 + *(temp_r14_8 + temp_r12_12);
                    if (temp_r12_13 > 0x33U) {
                        M2C_FIELD(var_r18_4, s32 *, 0x1B00) = 0;
                    } else {
                        if (var_r0_4 > 0x1FFF) {
                            var_r0_4 = 0x1FFF;
                        }
                        if (!(var_r0_4 & 0x1F00)) {
                            temp_r0_11 = *(s32 *)(table + (var_r0_4 * 4));
                            if (temp_r16_2 == 1) {
                                temp_r12_14 = temp_r0_11 * temp_r24;
                                temp_r12_15 = ((s32)(((s64)temp_r0_11 * (s64)temp_r24) >> 20));
                                if (temp_r12_13 > 0x14U) {
                                    var_r12_10 = temp_r12_15 >> (temp_r12_13 - 0x14);
                                } else {
                                    var_r12_10 = temp_r12_15 << (0x14 - temp_r12_13);
                                }
                            } else {
                                temp_r25_5 = (s32) (temp_r24 * temp_r16_2) >> 4;
                                if (temp_r12_13 > 0x14U) {
                                    temp_r16_3 = temp_r25_5 * temp_r0_11;
                                    temp_r12_16 = temp_r12_13 - 8;
                                    temp_r12_17 = (((temp_r16_3 << 8) | (temp_r16_3 >> 0x18U)) & ~0xFFFFFF00) | (((s32)(((s64)(temp_r25_5) * (s64)(temp_r0_11)) >> 32)) << 8);
                                    if (temp_r12_16 < 0x14U) {
                                        var_r12_10 = temp_r12_17 << (0x14 - temp_r12_16);
                                    } else {
                                        var_r12_10 = temp_r12_17 >> (temp_r12_16 - 0x14);
                                    }
                                } else {
                                    temp_r16_4 = temp_r25_5 * temp_r0_11;
                                    temp_r12_18 = temp_r12_13 - 4;
                                    temp_r12_19 = ((s32)(((s64)temp_r25_5 * (s64)temp_r0_11) >> 20));
                                    if (temp_r12_18 < 0x14U) {
                                        var_r12_10 = temp_r12_19 << (0x14 - temp_r12_18);
                                    } else {
                                        var_r12_10 = temp_r12_19 >> (temp_r12_18 - 0x14);
                                    }
                                }
                            }
                        } else {
                            temp_r29_3 = var_r0_4 * var_r0_4;
                            temp_r25_6 = lbl_8031C098 + ((var_r0_4 >> 8) * 0x10);
                            temp_r28_4 = M2C_FIELD(temp_r25_6, s32 *, 0);
                            temp_r27_3 = M2C_FIELD(temp_r25_6, s32 *, 4);
                            temp_r0_12 = temp_r29_3 * temp_r28_4;
                            temp_r28_5 = temp_r27_3 * var_r0_4;
                            temp_r0_13 = ((s32) (((s32)(((s64)temp_r29_3 * (s64)temp_r28_4) >> 20)) + ((s32)(((s64)temp_r27_3 * (s64)var_r0_4) >> 20)) + M2C_FIELD(temp_r25_6, s32 *, 8)) >> 4) + M2C_FIELD(temp_r25_6, s32 *, 0xC);
                            if (temp_r16_2 == 1) {
                                temp_r12_20 = temp_r0_13 * temp_r24;
                                if (temp_r12_13 > 0x14U) {
                                    var_r12_10 = temp_r12_20 >> (temp_r12_13 - 0x14);
                                } else {
                                    var_r12_10 = temp_r12_20 << (0x14 - temp_r12_13);
                                }
                            } else {
                                temp_r25_7 = temp_r24 * temp_r16_2;
                                temp_r12_21 = temp_r12_13 - 8;
                                temp_r16_5 = temp_r25_7 * temp_r0_13;
                                temp_r16_6 = (((temp_r16_5 << 0x18) | (temp_r16_5 >> 8U)) & ~0xFF000000) | (((s32)(((s64)(temp_r25_7) * (s64)(temp_r0_13)) >> 32)) << 0x18);
                                var_r12_10 = temp_r16_6 >> (temp_r12_21 - 0x14);
                                if (temp_r12_21 < 0x14U) {
                                    var_r12_10 = temp_r16_6 << (0x14 - temp_r12_21);
                                }
                            }
                        }
                        if (temp_r19_6 < 0) {
                            M2C_FIELD(var_r18_4, s32 *, 0x1B00) = (s32) -var_r12_10;
                        } else {
                            M2C_FIELD(var_r18_4, s32 *, 0x1B00) = var_r12_10;
                        }
                    }
                }
                var_r17_6 += 2;
                var_r18_4 += 4;
                var_r11_5 += 1;
                var_ctr_10 -= 1;
            } while (var_ctr_10 != 0);
            var_r12_11 = arg3 + 0x24;
            var_r18_5 = 0x24;
            var_r22 = arg_sp8 + 0x24;
            var_r11_6 = arg2 + 0x24;
loop_228:
            if (var_r18_5 < (s32) M2C_FIELD(arg0, s32 *, 0x9C4)) {
                temp_r0_14 = *var_r12_11;
                temp_r19_7 = *var_r22;
                temp_r21 = (temp_r0_14 * 4) & 0x3C;
                temp_r16_7 = temp_r0_14 & 0xF;
                var_r0_5 = temp_r19_7;
                temp_r25_8 = *(&sp8 + temp_r21) + 1;
                *(&sp8 + temp_r21) = temp_r25_8;
                if ((temp_r15 > 0x33U) || (temp_r19_7 == 0)) {
                    *(s32 *)(var_r10 + (temp_r16_7 * 0x900) + (temp_r25_8 * 4)) = 0;
                } else {
                    temp_r26_4 = temp_r16_7 * 2;
                    temp_r26_5 = *((((s32) *var_r11_6 >> 4) * 6) + (temp_r26_4 + arg_sp1C));
                    temp_r26_6 = *(temp_r20_3 + (temp_r26_5 * 2));
                    temp_r17_2 = *(temp_r14_8 + temp_r26_5) + ((s16) (*(s16 *)((u8 *)arg_sp10 + temp_r26_4) * 2) + temp_r15);
                    if (temp_r17_2 > 0x33U) {
                        *(s32 *)(var_r10 + (temp_r16_7 * 0x900) + (temp_r25_8 * 4)) = 0;
                    } else {
                        if (temp_r19_7 > 0x1FFF) {
                            var_r0_5 = 0x1FFF;
                        }
                        if (!(var_r0_5 & 0x1F00)) {
                            temp_r21_2 = *(s32 *)(table + (var_r0_5 * 4));
                            if (temp_r26_6 == 1) {
                                temp_r26_7 = temp_r21_2 * temp_r24;
                                temp_r21_3 = ((s32)(((s64)temp_r21_2 * (s64)temp_r24) >> 20));
                                if (temp_r17_2 > 0x14U) {
                                    var_r0_6 = temp_r21_3 >> (temp_r17_2 - 0x14);
                                } else {
                                    var_r0_6 = temp_r21_3 << (0x14 - temp_r17_2);
                                }
                            } else {
                                temp_r26_8 = (s32) (temp_r24 * temp_r26_6) >> 4;
                                if (temp_r17_2 > 0x14U) {
                                    temp_r0_15 = temp_r17_2 - 8;
                                    temp_r27_4 = temp_r26_8 * temp_r21_2;
                                    temp_r21_4 = (((temp_r27_4 << 8) | (temp_r27_4 >> 0x18U)) & ~0xFFFFFF00) | (((s32)(((s64)(temp_r26_8) * (s64)(temp_r21_2)) >> 32)) << 8);
                                    if (temp_r0_15 < 0x14U) {
                                        var_r0_6 = temp_r21_4 << (0x14 - temp_r0_15);
                                    } else {
                                        var_r0_6 = temp_r21_4 >> (temp_r0_15 - 0x14);
                                    }
                                } else {
                                    temp_r0_16 = temp_r26_8 * temp_r21_2;
                                    temp_r17_3 = temp_r17_2 - 4;
                                    temp_r26_9 = ((s32)(((s64)temp_r26_8 * (s64)temp_r21_2) >> 20));
                                    var_r21_3 = temp_r26_9 >> (temp_r17_3 - 0x14);
                                    if (temp_r17_3 < 0x14U) {
                                        var_r21_3 = temp_r26_9 << (0x14 - temp_r17_3);
                                    }
                                    var_r0_6 = var_r21_3 << (0x14 - temp_r17_3);
                                }
                            }
                        } else {
                            temp_r21_5 = lbl_8031C098 + ((var_r0_5 >> 8) * 0x10);
                            temp_r28_6 = var_r0_5 * var_r0_5;
                            temp_r29_4 = M2C_FIELD(temp_r21_5, s32 *, 0);
                            sp18 = M2C_FIELD(temp_r21_5, s32 *, 8);
                            temp_r30 = M2C_FIELD(temp_r21_5, s32 *, 4);
                            sp1C = M2C_FIELD(temp_r21_5, s32 *, 0xC);
                            temp_r0_17 = temp_r28_6 * temp_r29_4;
                            temp_r0_18 = temp_r30 * var_r0_5;
                            temp_r0_19 = ((s32) (((s32)(((s64)temp_r28_6 * (s64)temp_r29_4) >> 20)) + ((s32)(((s64)temp_r30 * (s64)var_r0_5) >> 20)) + sp18) >> 4) + sp1C;
                            if (temp_r26_6 == 1) {
                                temp_r0_20 = temp_r0_19 * temp_r24;
                                if (temp_r17_2 > 0x14U) {
                                    var_r0_6 = temp_r0_20 >> (temp_r17_2 - 0x14);
                                } else {
                                    var_r0_6 = temp_r0_20 << (0x14 - temp_r17_2);
                                }
                            } else {
                                temp_r27_5 = temp_r24 * temp_r26_6;
                                temp_r17_4 = temp_r17_2 - 8;
                                temp_r26_10 = temp_r27_5 * temp_r0_19;
                                temp_r26_11 = (((temp_r26_10 << 0x18) | (temp_r26_10 >> 8U)) & ~0xFF000000) | (((s32)(((s64)(temp_r27_5) * (s64)(temp_r0_19)) >> 32)) << 0x18);
                                var_r0_6 = temp_r26_11 >> (temp_r17_4 - 0x14);
                                if (temp_r17_4 < 0x14U) {
                                    var_r0_6 = temp_r26_11 << (0x14 - temp_r17_4);
                                }
                            }
                        }
                        if (temp_r19_7 < 0) {
                            *(s32 *)(var_r10 + (temp_r16_7 * 0x900) + (temp_r25_8 * 4)) = -var_r0_6;
                        } else {
                            *(s32 *)(var_r10 + (temp_r16_7 * 0x900) + (temp_r25_8 * 4)) = var_r0_6;
                        }
                    }
                }
                var_r22 += 2;
                var_r18_5 += 1;
                var_r11_6 += 1;
                var_r12_11 += 1;
                goto loop_228;
            }
            temp_r18_2 = var_r18_5 / 3;
            var_r11_7 = 0xC0 - temp_r18_2;
            var_r12_12 = var_r10 + (temp_r18_2 * 4);
            if ((s32) temp_r18_2 < 0xC0) {
                temp_r0_21 = var_r11_7 >> 3U;
                var_ctr_11 = temp_r0_21;
                if (temp_r0_21 != 0) {
                    do {
                        M2C_FIELD(var_r12_12, s32 *, 0) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x900) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1200) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 4) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x904) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1204) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 8) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x908) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1208) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0xC) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x90C) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x120C) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x10) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x910) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1210) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x14) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x914) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1214) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x18) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x918) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1218) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1C) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x91C) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x121C) = 0;
                        var_r12_12 += 0x20;
                        var_ctr_11 -= 1;
                    } while (var_ctr_11 != 0);
                    var_r11_7 &= 7;
                    if (var_r11_7 != 0) {
                        goto block_233;
                    }
                } else {
block_233:
                    var_ctr_12 = var_r11_7;
                    do {
                        M2C_FIELD(var_r12_12, s32 *, 0) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x900) = 0;
                        M2C_FIELD(var_r12_12, s32 *, 0x1200) = 0;
                        var_r12_12 += 4;
                        var_ctr_12 -= 1;
                    } while (var_ctr_12 != 0);
                }
            }
        }
        var_r9 += 1;
        var_r10 += 0x2400;
        arg_sp14 += 1;
        arg_spC += 1;
        arg_sp8 += 0x258;
        arg_sp18 += 0x15;
        arg_sp20 += 1;
        arg_sp1C += 0x24;
        arg_sp10 += 3;
        sp14 += 1;
        goto loop_236;
    }
}
#pragma pop
extern "C" u8 lbl_802F3D60[];
extern "C" s32 lbl_80559270[];
extern "C" s32 fn_800C083C(s32, s32, s32*);
extern "C" s32 fn_800BDEB4(const u8*, s32, u32*);
extern "C" void fn_800C08A8(void*, s32, s32, s16*, s32, s32, s16*);
extern "C" void fn_800C0B68(struct Fn800C0B68Context*, s32, s32, s16*, s32, s32, s16*);
extern "C" u16 fn_800C0DF8(u8*, s32, u32*);
#pragma push
#pragma use_lmw_stmw on
extern "C" s32 fn_800C0440(
void* arg0, s32 arg1, void* arg2,
s32 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7,
s32 arg8, s16* arg9, s16* arg10
) {
Fn800C0440Context* ctx = (Fn800C0440Context*)arg0;
s32 sp14 = arg4 & 1;
s16 spC = arg7;
void* sp8 = arg2;
s32 sp1C = 0x80320000 - 0x3D68;
s32 sp20 = 0x80320000 - 0x2A80;
volatile s16 sp10;
s16 spE;
register s32 maxOutput;
  register u8* table = (u8*)lbl_802F3D60;
  u32* maskTable = (u32*)(table + 0x1F4);
  s16* decodeTable = (s16*)(table + 0x1D0);
volatile s32 sp18;
register s32 i = 0;
register s32 outputIndex = 0;
register s16* output;
register s16* inputCursor = arg9;
register s8 status;
register s32 type;
register s32 maxForPass;
register s32 sign;
register u32 bits;
register u32 byteIndex;
register s32 shift;
register u32 raw;
register s16 decoded;
register s16 x;
register s16 y;

if (sp14 != 0) {
register s32 tile = *(s32*)((u8*)arg0 + 4);
register s16 row = *(s16*)((u8*)arg0 + 0x1C);
sp10 = ((s16*)(table + tile * 0x60 + row * 0x20))[arg5 + arg6];
spE = ((s16*)(table + 0xC0 + tile * 0x78 + row * 0x28))[arg5];
} else if (arg4 & 0x10) {
sp10 = 0x24;
} else {
sp10 = (s16)lbl_80559270[*(s32*)((u8*)arg0 + 4)];
}

maxOutput = arg3 * 2;
  output = (s16*)sp8;
  sp18 = ((u32)(-sp14 | sp14) >> 31) + 2;
inputCursor = arg9;
while (i < sp18) {
type = *inputCursor;
status = (s8)*((u8*)sp1C + type);
if (type > 0x17) {
type = 0x11;
} else if (type > 0xF) {
type = 0x10;
}

if (i == 0) {
maxForPass = sp10;
}
if (sp14 != 0) {
if (i == 1) {
maxForPass = spE;
}
if (i == 2) {
maxForPass = maxOutput;
}
} else if (i == 1) {
maxForPass = maxOutput;
}
if (maxForPass > maxOutput) {
maxForPass = maxOutput;
}

while (outputIndex < maxForPass) {
raw = (u32)((u16 (*)(u8 *, s32, u32 *))fn_800C0DF8)((u8*)arg1, 0x10, (u32*)&ctx->bitIndex) << 16;
if (type == 0xD || type == 0x10) {
bits = ctx->bitIndex;
ctx->bitIndex = bits + 4;
byteIndex = (bits >> 3) & 0x1FFF;
shift = 0x10 - (bits & 7);
ctx->bitIndex -= 0x14;
sign = ((u32)((u8*)arg1)[(byteIndex + 1) & 0x1FFF] << 8) | ((u8*)arg1)[byteIndex];
sign &= maskTable[shift];
sign >>= shift - 4;
raw |= ((sign & 0xF) << 12);
} else {
ctx->bitIndex -= 0x10;
}

decoded = (s16)fn_800C083C(raw, decodeTable[type], (s32*)(sp20 + type * 4));
x = (s16)((decoded & 0xF0) >> 4);
y = (s16)(decoded & 0xF);
ctx->bitIndex += (s16)decoded >> 8;

if (x == 0xF && status != 0) {
x = (s16)(x + (u16)fn_800BDEB4((const u8*)arg1, status, (u32*)&ctx->bitIndex));
}
if (x != 0) {
bits = ctx->bitIndex;
ctx->bitIndex = bits + 1;
byteIndex = (bits >> 3) & 0x1FFF;
shift = 8 - (bits & 7);
sign = (s32)((u8*)arg1)[byteIndex];
shift -= 1;
sign = (sign >> shift) & 1;
if (sign != 0) {
x = -x;
}
}

if (y == 0xF && status != 0) {
y = (s16)(y + (u16)fn_800BDEB4((const u8*)arg1, status, (u32*)&ctx->bitIndex));
}
if (y != 0) {
bits = ctx->bitIndex;
ctx->bitIndex = bits + 1;
byteIndex = (bits >> 3) & 0x1FFF;
shift = 8 - (bits & 7);
sign = (s32)((u8*)arg1)[byteIndex];
shift -= 1;
sign = (sign >> shift) & 1;
if (sign != 0) {
y = -y;
}
}

output[0] = x;
output[1] = y;
if ((s32)ctx->bitIndex > ctx->limit) {
if (arg8 == 1 && *arg10 == 0) {
*arg10 = (s16)outputIndex;
}
output[0] = 0;
output[1] = 0;
}
output += 2;
outputIndex += 2;
}
++i;
++inputCursor;
}

if (spC == 0) {
fn_800C08A8(arg0, *(s16*)((u8*)arg0 + 0x288), (s32)arg1, (s16*)arg2, outputIndex, arg8, arg10);
} else {
fn_800C0B68((struct Fn800C0B68Context*)arg0, *(s16*)((u8*)arg0 + 0x288), (s32)arg1, (s16*)arg2, outputIndex, arg8, arg10);
}
return 0;
}

s32 fn_800C083C(s32 arg0, s32 arg1, s32 *arg2) {
    u32 *node;
    u16 value;
    u32 index = 0;
    u32 mask = 0xF;
    s32 shift = 0x1C;
    s32 count = arg1;
    s32 result;

    if (arg1 > 0) {
        while (1) {
            node = *(u32 **)(arg2[index * 4]);
            value = *(u16 *)(node + ((mask & (arg0 >> shift)) * 2));
            if (value & 0x8000) {
                return value & 0x7FFF;
            }
            mask = *(u32 *)(lbl_8031C2B8 + ((value * 4) & 0x3C));
            index = value >> 8;
            shift -= value & 0xF;
            if (--count == 0) {
                return 0;
            }
        }
    }
    return 0;
}

#pragma pop
struct Fn800C08A8Context { u8 pad[0xC]; u32 bitIndex; s32 limit; };
extern "C" u8 lbl_8031C2E0[];
#pragma push
#pragma use_lmw_stmw on
extern "C" void fn_800C08A8(void *arg0, s32 arg1, s32 arg2, s16 *arg3, s32 arg4, s32 arg5, s16 *arg6) {
    register s16 var_r0, var_r29, var_r30, var_r31;
    register s32 temp_r26_2, temp_r27, shift;
    s32 temp_r3;
    register u32 temp_r26, temp_r28, temp_r0, var_ctr, var_ctr_2, var_r3_2;
    register u32 temp_r27_2;
    register s32 var_r7;
    register s16 *var_r12, *var_r5;

    var_r7 = arg4;
    var_r12 = arg3 + var_r7;
    var_ctr = (u32)((arg1 + 3) - var_r7) >> 2U;
    
        for (; var_ctr != 0; --var_ctr) {
            if (var_r7 >= arg1) break;            temp_r26 = M2C_FIELD(arg0, u32 *, 0xC);
            temp_r28 = temp_r26 + 6;
            temp_r27 = 0x10 - (temp_r26 & 7);
            M2C_FIELD(arg0, u32 *, 0xC) = temp_r28;
            temp_r26_2 = (temp_r26 >> 3U) & 0x1FFF;
            temp_r26 = ((const u8 *)arg2)[temp_r26_2];
            temp_r26_2 = (temp_r26_2 + 1) & 0x1FFF;
            temp_r27_2 = ((const u8 *)arg2)[temp_r26_2];
            temp_r26 = ((temp_r26 << 8) | temp_r27_2) & lbl_802F3F54[temp_r27];
            temp_r0 = (temp_r26 >> (temp_r27 - 6)) & 0xFFFF;
            temp_r27_2 = lbl_8031C2E0[temp_r0];
            var_r0 = (temp_r27_2 >> 3U) & 1;
            temp_r26 = temp_r28 - (temp_r27_2 >> 4);
            var_r31 = (temp_r27_2 >> 2U) & 1;
            var_r30 = (temp_r27_2 >> 1U) & 1;
            var_r29 = temp_r27_2 & 1;
            M2C_FIELD(arg0, u32 *, 0xC) = temp_r26;
            if (var_r0 != 0) {
                temp_r28 = temp_r26 + 1;
                M2C_FIELD(arg0, u32 *, 0xC) = temp_r28;
                shift = 8 - (temp_r26 & 7);
                shift -= 1;
                temp_r26_2 = (temp_r26 >> 3U) & 0x1FFF;
                if (((s32)((const u8 *)arg2)[temp_r26_2] >> shift) & 1) var_r0 = -var_r0;
            }
            if (var_r31 != 0) {
                temp_r26 = M2C_FIELD(arg0, u32 *, 0xC);
                temp_r28 = temp_r26 + 1;
                M2C_FIELD(arg0, u32 *, 0xC) = temp_r28;
                shift = 8 - (temp_r26 & 7);
                shift -= 1;
                temp_r26_2 = (temp_r26 >> 3U) & 0x1FFF;
                if (((s32)((const u8 *)arg2)[temp_r26_2] >> shift) & 1) var_r31 = -var_r31;
            }
            if (var_r30 != 0) {
                temp_r26 = M2C_FIELD(arg0, u32 *, 0xC);
                temp_r28 = temp_r26 + 1;
                M2C_FIELD(arg0, u32 *, 0xC) = temp_r28;
                shift = 8 - (temp_r26 & 7);
                shift -= 1;
                temp_r26_2 = (temp_r26 >> 3U) & 0x1FFF;
                if (((s32)((const u8 *)arg2)[temp_r26_2] >> shift) & 1) var_r30 = -var_r30;
            }
            if (var_r29 != 0) {
                temp_r26 = M2C_FIELD(arg0, u32 *, 0xC);
                temp_r28 = temp_r26 + 1;
                M2C_FIELD(arg0, u32 *, 0xC) = temp_r28;
                shift = 8 - (temp_r26 & 7);
                shift -= 1;
                temp_r26_2 = (temp_r26 >> 3U) & 0x1FFF;
                if (((s32)((const u8 *)arg2)[temp_r26_2] >> shift) & 1) var_r29 = -var_r29;
            }
            var_r12[0] = var_r0; var_r12[1] = var_r31;
            var_r12[2] = var_r30; var_r12[3] = var_r29;
            if ((s32)M2C_FIELD(arg0, u32 *, 0xC) > M2C_FIELD(arg0, s32 *, 0x10)) {
                if (arg5 == 1 && *arg6 == 0) *arg6 = (s16)var_r7;
                temp_r3 = (s32)(arg1 + 3);
                var_r5 = arg3 + var_r7;
                temp_r3 -= var_r7;
                var_r3_2 = (u32)temp_r3 >> 2;
                if (var_r7 < arg1) {
                arg1 = 0;
                    temp_r0 = var_r3_2 >> 3U;
                    var_ctr_2 = temp_r0;
                    if (temp_r0 != 0) {
                        do {
                            var_r5[0]=arg1; var_r5[1]=arg1; var_r5[2]=arg1; var_r5[3]=arg1;
                            var_r5[4]=arg1; var_r5[5]=arg1; var_r5[6]=arg1; var_r5[7]=arg1;
                            var_r5[8]=arg1; var_r5[9]=arg1; var_r5[10]=arg1; var_r5[11]=arg1;
                            var_r5[12]=arg1; var_r5[13]=arg1; var_r5[14]=arg1; var_r5[15]=arg1;
                            var_r5[16]=arg1; var_r5[17]=arg1; var_r5[18]=arg1; var_r5[19]=arg1;
                            var_r5[20]=arg1; var_r5[21]=arg1; var_r5[22]=arg1; var_r5[23]=arg1;
                            var_r5[24]=arg1; var_r5[25]=arg1; var_r5[26]=arg1; var_r5[27]=arg1;
                            var_r5[28]=arg1; var_r5[29]=arg1; var_r5[30]=arg1; var_r5[31]=arg1;
                            var_r5 += 32; var_ctr_2 -= 1;
                        } while (var_ctr_2 != 0);
                        var_r3_2 &= 7;
                        if (var_r3_2 != 0) goto block_21;
                    } else {
block_21:
                        var_ctr_2 = var_r3_2;
                        do {
                            var_r5[0]=arg1; var_r5[1]=arg1; var_r5[2]=arg1; var_r5[3]=arg1;
                            var_r5 += 4; var_ctr_2 -= 1;
                        } while (var_ctr_2 != 0);
                    }
                }
                return;
            }
            var_r12 += 4;
            var_r7 += 4;
        }
}
#pragma pop

struct Fn800C0B68Context { u8 pad[0xC]; u32 bitIndex; s32 limit; };
extern "C" s32 fn_800BDEB4(const u8 *, s32, u32 *);
#pragma push
#pragma use_lmw_stmw on
extern "C" void fn_800C0B68(Fn800C0B68Context *arg0, s32 arg1, s32 arg2, s16 *arg3, s32 arg4, s32 arg5, s16 *arg6) {
    s16 var_r0, var_r3, var_r4, var_r5;
    s32 temp_r3;
    u32 temp_r5, temp_r8, temp_r8_2, temp_r8_3, temp_r8_4;
    u32 temp_r0, var_ctr, var_ctr_2, var_r3_2;
    s32 shift;
    s16 *var_r5_2, *var_r31 = arg3 + arg4;
    goto block_25;
loop_25:
    temp_r3 = fn_800BDEB4((const u8 *)arg2, 4, &arg0->bitIndex);
    temp_r5 = ~(temp_r3 | temp_r3);
    var_r0 = (s16)((temp_r5 >> 3U) & 1); var_r3 = (s16)((temp_r5 >> 2U) & 1);
    var_r4 = (s16)((temp_r5 >> 1U) & 1); var_r5 = (s16)(temp_r5 & 1);
    if (var_r0 != 0) { temp_r8 = arg0->bitIndex; arg0->bitIndex = temp_r8 + 1; shift = 8 - (temp_r8 & 7); shift -= 1; if (((s32)*((const u8 *)arg2 + ((temp_r8 >> 3U) & 0x1FFF)) >> shift) & 1) var_r0 = -var_r0; }
    if (var_r3 != 0) { temp_r8_2 = arg0->bitIndex; arg0->bitIndex = temp_r8_2 + 1; shift = 8 - (temp_r8_2 & 7); shift -= 1; if (((s32)*((const u8 *)arg2 + ((temp_r8_2 >> 3U) & 0x1FFF)) >> shift) & 1) var_r3 = -var_r3; }
    if (var_r4 != 0) { temp_r8_3 = arg0->bitIndex; arg0->bitIndex = temp_r8_3 + 1; shift = 8 - (temp_r8_3 & 7); shift -= 1; if (((s32)*((const u8 *)arg2 + ((temp_r8_3 >> 3U) & 0x1FFF)) >> shift) & 1) var_r4 = -var_r4; }
    if (var_r5 != 0) { temp_r8_4 = arg0->bitIndex; arg0->bitIndex = temp_r8_4 + 1; shift = 8 - (temp_r8_4 & 7); shift -= 1; if (((s32)*((const u8 *)arg2 + ((temp_r8_4 >> 3U) & 0x1FFF)) >> shift) & 1) var_r5 = -var_r5; }
    var_r31[0] = var_r0; var_r31[1] = var_r3; var_r31[2] = var_r4; var_r31[3] = var_r5;
    if ((s32)arg0->bitIndex > arg0->limit) {
        if (arg5 == 1 && *arg6 == 0) *arg6 = (s16)arg4;
        temp_r3 = (s32)(arg1 + 3);
        var_r5_2 = arg3 + arg4;
        var_r4 = 0;
        temp_r3 -= arg4;
        var_r3_2 = (u32)temp_r3 >> 2;
        if (arg4 < arg1) {
            temp_r0 = var_r3_2 >> 3U; var_ctr = temp_r0;
            if (temp_r0 != 0) {
                do {
                    var_r5_2[0] = var_r4; var_r5_2[1] = var_r4; var_r5_2[2] = var_r4; var_r5_2[3] = var_r4; var_r5_2[4] = var_r4; var_r5_2[5] = var_r4; var_r5_2[6] = var_r4; var_r5_2[7] = var_r4; var_r5_2[8] = var_r4; var_r5_2[9] = var_r4; var_r5_2[10] = var_r4; var_r5_2[11] = var_r4; var_r5_2[12] = var_r4; var_r5_2[13] = var_r4; var_r5_2[14] = var_r4; var_r5_2[15] = var_r4; var_r5_2[16] = var_r4; var_r5_2[17] = var_r4; var_r5_2[18] = var_r4; var_r5_2[19] = var_r4; var_r5_2[20] = var_r4; var_r5_2[21] = var_r4; var_r5_2[22] = var_r4; var_r5_2[23] = var_r4; var_r5_2[24] = var_r4; var_r5_2[25] = var_r4; var_r5_2[26] = var_r4; var_r5_2[27] = var_r4; var_r5_2[28] = var_r4; var_r5_2[29] = var_r4; var_r5_2[30] = var_r4; var_r5_2[31] = var_r4;
                    var_r5_2 += 32; var_ctr -= 1;
                } while (var_ctr != 0);
                var_r3_2 &= 7;
                if (var_r3_2 != 0) goto block_21;
            } else {
block_21:
                var_ctr_2 = var_r3_2;
                do {
                    var_r5_2[0] = var_r4; var_r5_2[1] = var_r4; var_r5_2[2] = var_r4; var_r5_2[3] = var_r4;
                    var_r5_2 += 4; var_ctr_2 -= 1;
                } while (var_ctr_2 != 0);
            }
        }
        return;
    }
block_25:
    var_r31 += 4; arg4 += 4;
    if (arg4 < arg1) goto loop_25;
}
#pragma pop
u16 fn_800C0DF8(u8 *arg0, s32 arg1, u32 *arg2) {
    u32 bits = *arg2;
    u32 index = (bits >> 3) & 0x1FFF;
    s32 shift = 0x18 - (bits & 7);
    *arg2 = bits + arg1;
    volatile u8 *bytes = (volatile u8 *)arg0;
    u8 b;
    u8 c;
    u8 a;
    if (index < 0x1FFE) {
        u32 next = index + 1;
        a = bytes[index];
        b = bytes[next];
        next++;
        c = bytes[next];
    } else {
        u32 next = index + 1;
        a = bytes[index];
        next &= 0x1FFF;
        b = bytes[next];
        next++;
        next &= 0x1FFF;
        c = bytes[next];
    }
    u32 value = ((u32)a << 16) | ((u32)b << 8) | c;
    return (value & lbl_802F3F54[shift]) >> (shift - arg1);
}

extern "C" void fn_800C1984(s32 *, s32 *);
extern "C" void fn_800C18A0(void *arg0, void *arg1) {
    s32 temp[0x12];
    s32 *out = (s32 *)arg1;
    ((void (*)(void *, s32 *))fn_800C1984)(arg0, temp);
    out[0] = temp[9];
    out[1] = temp[10];
    out[2] = temp[11];
    out[3] = temp[12];
    out[4] = temp[13];
    out[5] = temp[14];
    out[6] = temp[15];
    out[7] = temp[16];
    out[8] = temp[17];
    out[18] = -temp[8];
    out[19] = -temp[7];
    out[20] = -temp[6];
    out[21] = -temp[5];
    out[22] = -temp[4];
    out[23] = -temp[3];
    out[24] = -temp[2];
    out[25] = -temp[1];
    out[26] = -temp[0];
}

extern "C" s32 lbl_802F4018[];
extern "C" s32 lbl_802F4060[];
extern "C" void fn_800C1A80(void *, void *, s32 *);
extern "C" void fn_800C1984(s32 *arg0, s32 *arg1) {
    s32 combined[9];
    s32 filtered[9];
    s32 *input = arg0;
    s32 *coeff = lbl_802F4018;
    s32 *combinedOut = combined;
    s32 *scale = lbl_802F4060;
    s32 *filteredOut = filtered;
    for (s32 i = 0; i < 9; i++) {
        s32 left = *input++;
        s32 k = *coeff++;
        s32 c = *scale++;
        s32 reverseIndex = 0x11 - i;
        s32 right = arg0[reverseIndex];
        s32 reverseK = lbl_802F4018[reverseIndex];
        s32 forward = fixedMul20(left, k);
        s32 reverse = fixedMul20(right, reverseK);
        s32 delta = forward - reverse;
        *combinedOut++ = forward + reverse;
        *filteredOut++ = fixedMul20(c, delta);
    }
    fn_800C1A80(combined, filtered, arg1);
}

extern "C" void fn_800C1C1C(void *, s32 *);
extern "C" void fn_800C1A80(void *arg0, void *arg1, s32 *out) {
    s32 v[19]; s32 d;
    fn_800C1C1C(arg0, &v[9]); fn_800C1C1C(arg1, &v[0]);
    *out = v[9];
    d = v[0] - *out; out[1] = d;
    d = v[10] - d; out[2] = d;
    v[1] -= v[0]; d = v[1] - out[2]; out[3] = d;
    d = v[11] - d; out[4] = d;
    v[2] -= v[1]; d = v[2] - out[4]; out[5] = d;
    d = v[12] - d; out[6] = d;
    v[3] -= v[2]; d = v[3] - out[6]; out[7] = d;
    d = v[13] - d; out[8] = d;
    v[4] -= v[3]; d = v[4] - out[8]; out[9] = d;
    d = v[14] - d; out[10] = d;
    v[5] -= v[4]; d = v[5] - out[10]; out[11] = d;
    d = v[15] - d; out[12] = d;
    v[6] -= v[5]; d = v[6] - out[12]; out[13] = d;
    d = v[16] - d; out[14] = d;
    v[7] -= v[6]; d = v[7] - out[14]; out[15] = d;
    out[16] = v[17] - d;
    v[8] -= v[7];
    out[17] = v[8] - out[16];
}

extern "C" void fn_800C1E88(const s32 *a, const s32 *b, s32 *out) {
    register s32 a0 = a[0];
    register s32 a1 = a[1];
    register s32 a2 = a[2];
    register s32 a3 = a[3];
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 zero = 0;
        s64 p = zero;
        p += (s64)a0 * b[0];
        p += (s64)a1 * b[1];
        p += (s64)a2 * b[2];
        p += (s64)a3 * b[3];
        p += (s64)a[4] * b[4];
        p += (s64)a[5] * b[5];
        *out = (s32)(p >> 20);
        if (i & 1) {
            out += 4;
        } else {
            out += 2;
        }
        b += 6;
    }
}

extern "C" void fn_800C1F6C(volatile u32 *dst, const volatile u32 *a, const volatile u32 *b) {
    dst[0] = a[0] + b[0];
    dst[0x40] = a[1] + b[1];
    dst[0x80] = a[2] + b[2];
    dst[0xC0] = a[3] + b[3];
    dst[0x100] = a[4] + b[4];
    dst[0x140] = a[5] + b[5];
    dst[0x180] = a[6] + b[6];
    dst[0x1C0] = a[7] + b[7];
    dst[0x200] = a[8] + b[8];
    dst[0x240] = a[9] + b[9];
    dst[0x280] = a[10] + b[10];
    dst[0x2C0] = a[11] + b[11];
    dst[0x300] = a[12] + b[12];
    dst[0x340] = a[13] + b[13];
    dst[0x380] = a[14] + b[14];
    dst[0x3C0] = a[15] + b[15];
    dst[0x400] = a[16] + b[16];
    dst[0x440] = a[17] + b[17];
}

extern "C" void fn_800C2090(volatile s32 *dst, const volatile s32 *a, const volatile s32 *b) {
    dst[0x000] = a[0] + b[0];
    dst[0x040] = -(a[1] + b[1]);
    dst[0x080] = a[2] + b[2];
    dst[0x0C0] = -(a[3] + b[3]);
    dst[0x100] = a[4] + b[4];
    dst[0x140] = -(a[5] + b[5]);
    dst[0x180] = a[6] + b[6];
    dst[0x1C0] = -(a[7] + b[7]);
    dst[0x200] = a[8] + b[8];
    dst[0x240] = -(a[9] + b[9]);
    dst[0x280] = a[10] + b[10];
    dst[0x2C0] = -(a[11] + b[11]);
    dst[0x300] = a[12] + b[12];
    dst[0x340] = -(a[13] + b[13]);
    dst[0x380] = a[14] + b[14];
    dst[0x3C0] = -(a[15] + b[15]);
    dst[0x400] = a[16] + b[16];
    dst[0x440] = -(a[17] + b[17]);
}

extern s32 lbl_8031D5E0[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_800C21D8(s32* arg0, s32* arg1) {
    s32* coeff = lbl_8031D5E0;
    s32* p = (s32*)((u32)arg0 + 72);
    s32* q = (s32*)((u32)arg1 + 72);
    s32 c0, c1, value;
    c0 = *coeff++;
    value = p[-18];
    c1 = *coeff++;
    p[-18] = (s32)(((s64)value * c0) >> 20);
    q[-18] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-17];
    c1 = *coeff++;
    p[-17] = (s32)(((s64)value * c0) >> 20);
    q[-19] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-16];
    c1 = *coeff++;
    p[-16] = (s32)(((s64)value * c0) >> 20);
    q[-20] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-15];
    c1 = *coeff++;
    p[-15] = (s32)(((s64)value * c0) >> 20);
    q[-21] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-14];
    c1 = *coeff++;
    p[-14] = (s32)(((s64)value * c0) >> 20);
    q[-22] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-13];
    c1 = *coeff++;
    p[-13] = (s32)(((s64)value * c0) >> 20);
    q[-23] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-12];
    c1 = *coeff++;
    p[-12] = (s32)(((s64)value * c0) >> 20);
    q[-24] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-11];
    c1 = *coeff++;
    p[-11] = (s32)(((s64)value * c0) >> 20);
    q[-25] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[-10];
    c1 = *coeff++;
    p[-10] = (s32)(((s64)value * c0) >> 20);
    q[-26] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[0];
    c1 = *coeff++;
    p[0] = (s32)(((s64)value * c0) >> 20);
    q[0] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[1];
    c1 = *coeff++;
    p[1] = (s32)(((s64)value * c0) >> 20);
    q[-1] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[2];
    c1 = *coeff++;
    p[2] = (s32)(((s64)value * c0) >> 20);
    q[-2] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[3];
    c1 = *coeff++;
    p[3] = (s32)(((s64)value * c0) >> 20);
    q[-3] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[4];
    c1 = *coeff++;
    p[4] = (s32)(((s64)value * c0) >> 20);
    q[-4] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[5];
    c1 = *coeff++;
    p[5] = (s32)(((s64)value * c0) >> 20);
    q[-5] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[6];
    c1 = *coeff++;
    p[6] = (s32)(((s64)value * c0) >> 20);
    q[-6] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[7];
    c1 = *coeff++;
    p[7] = (s32)(((s64)value * c0) >> 20);
    q[-7] = (s32)(((s64)value * c1) >> 20);
    c0 = *coeff++;
    value = p[8];
    c1 = *coeff++;
    p[8] = (s32)(((s64)value * c0) >> 20);
    q[-8] = (s32)(((s64)value * c1) >> 20);
}
#pragma pop
extern "C" s32 lbl_8031D670[];
extern "C" void fn_800C2590(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    arg2[0] = arg1[0] + (s32)(((s64)arg0[0] * (s64)lbl_8031D670[0]) >> 20);
    *(s32 *)((u8 *)arg3 - 0) = *(s32 *)((u8 *)arg1 + 68) + (s32)(((s64)arg0[0] * (s64)lbl_8031D670[1]) >> 20);
    arg2[64] = arg1[1] + (s32)(((s64)arg0[1] * (s64)lbl_8031D670[2]) >> 20);
    *(s32 *)((u8 *)arg3 - 256) = *(s32 *)((u8 *)arg1 + 64) + (s32)(((s64)arg0[1] * (s64)lbl_8031D670[3]) >> 20);
    arg2[128] = arg1[2] + (s32)(((s64)arg0[2] * (s64)lbl_8031D670[4]) >> 20);
    *(s32 *)((u8 *)arg3 - 512) = *(s32 *)((u8 *)arg1 + 60) + (s32)(((s64)arg0[2] * (s64)lbl_8031D670[5]) >> 20);
    arg2[192] = arg1[3] + (s32)(((s64)arg0[3] * (s64)lbl_8031D670[6]) >> 20);
    *(s32 *)((u8 *)arg3 - 768) = *(s32 *)((u8 *)arg1 + 56) + (s32)(((s64)arg0[3] * (s64)lbl_8031D670[7]) >> 20);
    arg2[256] = arg1[4] + (s32)(((s64)arg0[4] * (s64)lbl_8031D670[8]) >> 20);
    *(s32 *)((u8 *)arg3 - 1024) = *(s32 *)((u8 *)arg1 + 52) + (s32)(((s64)arg0[4] * (s64)lbl_8031D670[9]) >> 20);
    arg2[320] = arg1[5] + (s32)(((s64)arg0[5] * (s64)lbl_8031D670[10]) >> 20);
    *(s32 *)((u8 *)arg3 - 1280) = *(s32 *)((u8 *)arg1 + 48) + (s32)(((s64)arg0[5] * (s64)lbl_8031D670[11]) >> 20);
    arg2[384] = arg1[6] + (s32)(((s64)arg0[6] * (s64)lbl_8031D670[12]) >> 20);
    *(s32 *)((u8 *)arg3 - 1536) = *(s32 *)((u8 *)arg1 + 44) + (s32)(((s64)arg0[6] * (s64)lbl_8031D670[13]) >> 20);
    arg2[448] = arg1[7] + (s32)(((s64)arg0[7] * (s64)lbl_8031D670[14]) >> 20);
    *(s32 *)((u8 *)arg3 - 1792) = *(s32 *)((u8 *)arg1 + 40) + (s32)(((s64)arg0[7] * (s64)lbl_8031D670[15]) >> 20);
    arg2[512] = arg1[8] + (s32)(((s64)arg0[8] * (s64)lbl_8031D670[16]) >> 20);
    *(s32 *)((u8 *)arg3 - 2048) = *(s32 *)((u8 *)arg1 + 36) + (s32)(((s64)arg0[8] * (s64)lbl_8031D670[17]) >> 20);
}

void fn_800C2A88(s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 i, t;
    for (i=0;i<6;i++) {
        c[i*0x100/4]=b[i];
        d[-i*0x100/4]=b[0x44/4-i];
    }
    t=a[6];
    c[0x600/4]=b[6]+(t*lbl_8031D700[0]>>20);
    d[-0x600/4]=b[0x2C/4]+(t*lbl_8031D700[1]>>20);
    t=a[7];
    c[0x700/4]=b[7]+(t*lbl_8031D700[2]>>20);
    d[-0x700/4]=b[0x28/4]+(t*lbl_8031D700[3]>>20);
    t=a[8];
    c[0x800/4]=b[8]+(t*lbl_8031D700[4]>>20);
    d[-0x800/4]=b[0x24/4]+(t*lbl_8031D700[5]>>20);
}

extern "C" s32 lbl_8031D718[];
extern "C" void fn_800C2C18(s32 *a, s32 *b, s32 *o1, s32 *o2) {
    o1[0]=b[0]; o2[0]= -(-a[0]+b[17]);
    o1[64]=-b[1]; o2[-64]= -a[1]+b[16];
    o1[128]=b[2]; o2[-128]= -(-a[2]+b[15]);
    o1[192]=-b[3]; o2[-192]= -a[3]+b[14];
    o1[256]=b[4]; o2[-256]= -(-a[4]+b[13]);
    o1[320]=-b[5]; o2[-320]= -a[5]+b[12];
    o1[384]=(s32)(((s64)a[6]*lbl_8031D718[0])>>12)+b[6];
    o2[-384]= -((s32)(((s64)a[6]*lbl_8031D718[1])>>12)+b[11]);
    o1[448]= -((s32)(((s64)a[7]*lbl_8031D718[3])>>12)+b[7]);
    o2[-448]= -((s32)(((s64)a[7]*lbl_8031D718[2])>>12)+b[10]);
    o1[512]=(s32)(((s64)a[8]*lbl_8031D718[4])>>12)+b[8];
    o2[-512]= -((s32)(((s64)a[8]*lbl_8031D718[5])>>12)+b[9]);
}

extern u32 lbl_8031D730[];
void fn_800C2DBC(s32 *arg0, s32 *arg1, s32 *arg2) {
    s64 p0=(s64)arg0[0]*lbl_8031D730[0];
    s64 q0=(s64)arg0[0]*lbl_8031D730[1];
    arg1[0]=(s32)(p0>>20);
    arg2[-0]=(s32)(q0>>20);
    s64 p1=(s64)arg0[1]*lbl_8031D730[2];
    s64 q1=(s64)arg0[1]*lbl_8031D730[3];
    arg1[1]=(s32)(p1>>20);
    arg2[-1]=(s32)(q1>>20);
    s64 p2=(s64)arg0[2]*lbl_8031D730[4];
    s64 q2=(s64)arg0[2]*lbl_8031D730[5];
    arg1[2]=(s32)(p2>>20);
    arg2[-2]=(s32)(q2>>20);
    s64 p3=(s64)arg0[3]*lbl_8031D730[6];
    s64 q3=(s64)arg0[3]*lbl_8031D730[7];
    arg1[3]=(s32)(p3>>20);
    arg2[-3]=(s32)(q3>>20);
    s64 p4=(s64)arg0[4]*lbl_8031D730[8];
    s64 q4=(s64)arg0[4]*lbl_8031D730[9];
    arg1[4]=(s32)(p4>>20);
    arg2[-4]=(s32)(q4>>20);
    s64 p5=(s64)arg0[5]*lbl_8031D730[10];
    s64 q5=(s64)arg0[5]*lbl_8031D730[11];
    arg1[5]=(s32)(p5>>20);
    arg2[-5]=(s32)(q5>>20);
    s64 p6=(s64)arg0[6]*lbl_8031D730[12];
    s64 q6=(s64)arg0[6]*lbl_8031D730[13];
    arg1[6]=(s32)(p6>>20);
    arg2[-6]=(s32)(q6>>20);
    s64 p7=(s64)arg0[7]*lbl_8031D730[14];
    s64 q7=(s64)arg0[7]*lbl_8031D730[15];
    arg1[7]=(s32)(p7>>20);
    arg2[-7]=(s32)(q7>>20);
    s64 p8=(s64)arg0[8]*lbl_8031D730[16];
    s64 q8=(s64)arg0[8]*lbl_8031D730[17];
    arg1[8]=(s32)(p8>>20);
    arg2[-8]=(s32)(q8>>20);
}

extern "C" s32 lbl_8031D778[];
extern "C" void fn_800C2F98(s32 *in, s32 *out, s32 *negOut) {
    const s32 *k = lbl_8031D778;
    s32 zero = 0;
    s32 value;
    s32 coefficient;
    s32 result;
    s32 negative;
    s64 product;
    s64 second;

    value = in[0]; out[0] = value; negOut[0] = zero;
    value = in[1]; out[1] = value; negOut[-1] = zero;
    value = in[2]; out[2] = value; negOut[-2] = zero;
    value = in[3]; out[3] = value; negOut[-3] = zero;
    value = in[4]; out[4] = value; negOut[-4] = zero;
    value = in[5]; out[5] = value; negOut[-5] = zero;

    value = in[6];
    coefficient = *k++;
    product = (s64)value * coefficient;
    coefficient = *k++;
    second = (s64)value * coefficient;
    result = (s32)(product >> 20);
    negative = (s32)(second >> 20);
    out[6] = result;
    negOut[-6] = negative;

    value = in[7];
    coefficient = *k++;
    product = (s64)value * coefficient;
    coefficient = *k++;
    second = (s64)value * coefficient;
    result = (s32)(product >> 20);
    negative = (s32)(second >> 20);
    out[7] = result;
    negOut[-7] = negative;

    value = in[8];
    coefficient = *k++;
    product = (s64)value * coefficient;
    coefficient = *k++;
    second = (s64)value * coefficient;
    result = (s32)(product >> 20);
    negative = (s32)(second >> 20);
    out[8] = result;
    negOut[-8] = negative;
}

extern "C" const s32 lbl_8031D790[];
extern "C" void fn_800C3088(volatile s32 *out, const volatile s32 *a, const volatile s32 *b, const volatile s32 *c) {
    s32 term1;
    s32 term2;
    const volatile s32 *k = lbl_8031D790;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = fixedMul20(a[0], k[0]);
    out[7] = fixedMul20(a[1], k[1]);
    out[8] = fixedMul20(a[2], k[2]);
    out[9] = fixedMul20(a[2], k[3]);
    out[10] = fixedMul20(a[1], k[4]);
    out[11] = fixedMul20(a[0], k[5]);
    term1 = fixedMul20(a[6], k[6]);
    term2 = fixedMul20(b[0], k[0]);
    out[12] = term1 + term2;
    term1 = fixedMul20(a[7], k[7]);
    term2 = fixedMul20(b[1], k[1]);
    out[13] = term1 + term2;
    term1 = fixedMul20(a[8], k[8]);
    term2 = fixedMul20(b[2], k[2]);
    out[14] = term1 + term2;
    term1 = fixedMul20(a[8], k[9]);
    term2 = fixedMul20(b[2], k[3]);
    out[15] = term1 + term2;
    term1 = fixedMul20(a[7], k[10]);
    term2 = fixedMul20(b[1], k[4]);
    out[16] = term1 + term2;
    term1 = fixedMul20(a[6], k[11]);
    term2 = fixedMul20(b[0], k[5]);
    out[17] = term1 + term2;
    term1 = fixedMul20(b[6], k[6]);
    term2 = fixedMul20(c[0], k[0]);
    out[18] = term1 + term2;
    term1 = fixedMul20(b[7], k[7]);
    term2 = fixedMul20(c[1], k[1]);
    out[19] = term1 + term2;
    term1 = fixedMul20(b[8], k[8]);
    term2 = fixedMul20(c[2], k[2]);
    out[20] = term1 + term2;
    term1 = fixedMul20(b[8], k[9]);
    term2 = fixedMul20(c[2], k[3]);
    out[21] = term1 + term2;
    term1 = fixedMul20(b[7], k[10]);
    term2 = fixedMul20(c[1], k[4]);
    out[22] = term1 + term2;
    term1 = fixedMul20(b[6], k[11]);
    term2 = fixedMul20(c[0], k[5]);
    out[23] = term1 + term2;
    out[24] = fixedMul20(c[6], k[6]);
    out[25] = fixedMul20(c[7], k[7]);
    out[26] = fixedMul20(c[8], k[8]);
    out[27] = fixedMul20(c[8], k[9]);
    out[28] = fixedMul20(c[7], k[10]);
    term1 = fixedMul20(c[6], k[11]);
    out[30] = 0;
    out[31] = 0;
    out[32] = 0;
    out[33] = 0;
    out[34] = 0;
    out[35] = 0;
    out[29] = term1;
}

extern "C" void fn_800C34B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef void (*Fn3960)(void *, void *, s32, s32, s32, s32);
    if (arg3 == 0) {
        ((Fn3960)fn_800C3960)((void *)arg0, lbl_802F4088, arg2, arg1, 0x3FF, arg3);
        fn_800C3574((void *)arg0, lbl_802F4108, arg2 + 1, arg1 + 4, arg3);
        return;
    }
    ((Fn3960)fn_800C3960)((void *)arg0, lbl_802F4088, arg2, arg1, 0x3FF, arg3);
    fn_800C3574((void *)arg0, lbl_802F4108, arg2 + 1, arg1 + 2, arg3);
}

extern "C" void fn_800C3960(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *m = (s32 *)arg0;
    u16 *out = (u16 *)arg1;
    s32 x, y, k;
    s32 v;

    for (y = 0; y < 32; y++) {
        v = 0;
        for (x = 0; x < 32; x++)
            v += m[x] * m[y + 32 + x];
        m[y + 64] = (s16)((v << 7) | (v >> 25)) & 0x7FFF;
    }
    for (x = 0; x < 32; x++) {
        v = 0;
        for (y = 0; y < 32; y++)
            v += m[x] * m[y + 32 + x];
        m[x + 96] = (s16)((v << 7) | (v >> 25)) & 0x7FFF;
    }
    if (arg3 == 0) {
        out[0] = m[64];
        out[64] = m[96];
    } else {
        out[0] = m[64];
        out[32] = m[96];
    }
}

#pragma push
#pragma opt_dead_assignments off
extern "C" s32 fn_800C3CDC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p;
    fn_800C4B5C(arg2, arg3);
    p = (s32 *)fn_800C4B8C(0xED78);
    ((void (*)(void *, s32, s32))fn_800C4BD8)(p, 0, 0xED78);
    register u16 capacity = 0x400;
    register s32 zero = 0;
    p[1] = zero;
    p[2] = zero;
    p[3] = zero;
    p[5] = zero;
    p[6] = zero;
    *(s32 *)((u8 *)p + 0x9CC) = zero;
    *(s32 *)((u8 *)p + 0x9D0) = zero;
    *(s32 *)((u8 *)p + 0x9D4) = zero;
    *(s32 *)((u8 *)p + 0x9D8) = zero;
    *(s32 *)((u8 *)p + 0x9DC) = zero;
    *(s32 *)((u8 *)p + 0x9E0) = zero;
    *(s32 *)((u8 *)p + 0x9E4) = zero;
    *(s32 *)((u8 *)p + 0x9E8) = zero;
    *(u16 *)((u8 *)p + 0x27C) = capacity;
    *(s32 *)((u8 *)p + 0x278) = arg1;
    fn_800BEE64(p, arg0, zero);
    return (s32)p;
}
#pragma pop
extern "C" void fn_800C3D9C(void) {
    fn_800C4BD0();
}

void fn_800C4B5C(s32 arg0, s32 arg1) {
    u32 temp_r0;
    s32 temp_r5;
    s32 sum;
    temp_r0 = (u32)arg0 << 0x1E;
    temp_r5 = (u32)arg0 >> 0x1F;
    temp_r0 = temp_r0 - temp_r5;
    sum = arg0 + arg1;
    temp_r0 = (temp_r0 << 2) | (temp_r0 >> 0x1E);
    temp_r5 = temp_r0 + temp_r5;
    lbl_8055DD90 = sum - 4;
    temp_r5 = 4 - temp_r5;
    lbl_8055DD94 = (void *)((u32)arg0 + temp_r5);
}

extern "C" void* fn_800C4B8C(s32 arg0) {
    u32 old = (u32)lbl_8055DD94;
    u32 next = old + (arg0 & 0xFFFFFFFC) + (((u32)(-(arg0 & 3) | (arg0 & 3)) >> 29) & 4);
    lbl_8055DD94 = (void*)next;
    if (next > (u32)lbl_8055DD90) {
        lbl_8055DD94 = (void*)old;
        return NULL;
    }
    return (void*)old;
}

extern void *lbl_8055DD94;
extern "C" void fn_800C4BD0(void* hi) {
    lbl_8055DD94 = hi;
}

extern "C" void fn_800C4BD8(s32 *p, s32 value, u32 size) {
    u32 count = size >> 4;
    u32 tail = (size >> 2) & 3;
    if (count != 0) {
        u32 blocks = count >> 3;
        if (blocks != 0) {
            for (; blocks != 0; --blocks) {
                p[0]=value;p[1]=value;p[2]=value;p[3]=value;
                p[4]=value;p[5]=value;p[6]=value;p[7]=value;
                p[8]=value;p[9]=value;p[10]=value;p[11]=value;
                p[12]=value;p[13]=value;p[14]=value;p[15]=value;
                p[16]=value;p[17]=value;p[18]=value;p[19]=value;
                p[20]=value;p[21]=value;p[22]=value;p[23]=value;
                p[24]=value;p[25]=value;p[26]=value;p[27]=value;
                p[28]=value;p[29]=value;p[30]=value;p[31]=value;
                p += 32;
            }
            count &= 7;
        }
        if (count != 0) {
            for (; count != 0; --count) {
                p[0]=value;p[1]=value;p[2]=value;p[3]=value;
                p += 4;
            }
        }
    }
    if (tail != 0) {
        u32 blocks = tail >> 3;
        if (blocks != 0) {
            for (; blocks != 0; --blocks) {
                p[0]=value;p[1]=value;p[2]=value;p[3]=value;
                p[4]=value;p[5]=value;p[6]=value;p[7]=value;
                p += 8;
            }
            tail &= 7;
        }
        if (tail != 0)
            for (; tail != 0; --tail) *p++ = value;
    }
}

s32 fn_800C34B4(s32, s32, s16, s32);
s32 fn_800C4E5C(s32, s32);
void fn_800C4CF4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4, s32 arg5) {
 s32 span = 0x480, i=0, x=0, y=0, z=0, w=0;
 s32 row;
 if (*(s32 *)((char *)arg0+4)==1) span=0x240;
 for (;;) {
   s16 v=*(s16 *)((char *)arg0+0x27c)-0x40;
   *(s16 *)((char *)arg0+0x27c)=v;
   if(v<0) *(s16 *)((char *)arg0+0x27c)=0x3c0;
   row=arg1;
   s32 dst=arg2;
   for(s8 j=0;j<arg4;j++,row+=0x1000,dst+=0x80)
     fn_800C4E5C(dst,row+(*(s16 *)((char *)arg0+0x27c)*4));
   if(arg4==2) {
     if(arg5==0) {
       fn_800C34B4(arg1,arg3+y,*(s16 *)((char *)arg0+0x27c),arg5);
       fn_800C34B4(arg1+0x1000,arg3+((x+1)*2),*(s16 *)((char *)arg0+0x27c),arg5);
     } else {
       fn_800C34B4(arg1,arg3+z,*(s16 *)((char *)arg0+0x27c),arg5);
       fn_800C34B4(arg1+0x1000,arg3+((w+span)*2),*(s16 *)((char *)arg0+0x27c),arg5);
     }
   } else fn_800C34B4(arg1,arg3+z,*(s16 *)((char *)arg0+0x27c),1);
   ++i; x+=0x40; y+=0x80; w+=0x20; z+=0x40; arg2+=0x100;
   if(i>=0x12) break;
 }
}

#pragma push
#pragma opt_common_subs off
extern "C" s32 fn_800C4E5C(s32 arg0, void *arg1) {
    s32 sp[0x20];
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r5_3;
    s32 temp_r6;
    s32 *out = (s32 *)arg1;

    fn_800C56A4(sp, (void *)arg0, 0);
    fn_800C51BC(sp, sp + 16, (s32 *)lbl_8031D7C0);
    fn_800C5298(sp, sp + 8, (s32 *)((u8 *)lbl_8031D7C0 + 0x40));
    fn_800C5430(sp, sp + 4, (s32 *)((u8 *)lbl_8031D7C0 + 0x60));
    fn_800C5508(sp, sp + 2, (void *)((u8 *)lbl_8031D7C0 + 0x70));
    fn_800C55D8(sp, sp + 1, (s32 *)((u8 *)lbl_8031D7C0 + 0x78));

    out[0xC0 / 4] = -sp[0];
    temp_r0 = sp[31] + sp[30] + (sp[24] + sp[28]);
    out[0xBC / 4] = -(sp[16] + temp_r0);
    temp_r4 = (sp[15] + sp[12]) + sp[14];
    out[0xB8 / 4] = -(sp[8] + temp_r4);
    temp_r5 = (sp[23] + sp[20]) + sp[22];
    out[0xB4 / 4] = -(temp_r5 + temp_r0);
    out[0xB0 / 4] = -((sp[7] + sp[4]) + sp[6]);
    temp_r0_2 = temp_r0 + ((sp[26] + sp[27]) - sp[24]);
    out[0xAC / 4] = -(temp_r5 + temp_r0_2);
    temp_r4_2 = (temp_r4 + sp[10]) + sp[11];
    out[0xA8 / 4] = -temp_r4_2;
    out[0xA4 / 4] = -((temp_r0_2 + sp[18]) + sp[19]);
    out[0xA0 / 4] = -(sp[2] + sp[3]);
    temp_r0_3 = temp_r0_2 + (sp[29] - sp[28]);
    out[0x9C / 4] = -((temp_r0_3 + sp[18]) + sp[19]);
    temp_r4_3 = temp_r4_2 + (sp[13] - sp[12]);
    out[0x98 / 4] = -temp_r4_3;
    temp_r5_2 = temp_r5 + (sp[21] - sp[20]);
    out[0x94 / 4] = -(temp_r5_2 + temp_r0_3);
    out[0x90 / 4] = -((sp[7] + sp[5]) + sp[6]);
    temp_r0_4 = temp_r0_3 + ((sp[25] - sp[26]) - sp[27]);
    out[0x8C / 4] = -(temp_r5_2 + temp_r0_4);
    temp_r4_4 = temp_r4_3 + ((sp[9] - sp[10]) - sp[11]);
    out[0x88 / 4] = -temp_r4_4;
    out[0x84 / 4] = -(sp[17] + temp_r0_4);
    temp_r6 = sp[1];
    out[0] = temp_r6;
    temp_r6 = -temp_r6;
    temp_r0_5 = temp_r0_4 - sp[30];
    out[1] = sp[17] + temp_r0_5;
    out[2] = temp_r4_4 - sp[14];
    temp_r5_3 = temp_r5_2 - sp[22];
    out[3] = temp_r5_3 + temp_r0_5;
    out[4] = sp[5] + sp[7];
    temp_r0_6 = temp_r0_5 + (sp[27] - sp[25]);
    out[5] = temp_r5_3 + temp_r0_6;
    out[6] = sp[13] + (sp[15] + sp[11]);
    temp_r0_7 = temp_r0_6 + sp[19];
    out[7] = temp_r0_7;
    out[8] = sp[3];
    out[9] = temp_r0_7 - sp[29];
    out[10] = sp[11] + sp[15];
    out[11] = sp[27] + (sp[31] + sp[23]);
    out[12] = sp[7];
    out[13] = sp[23] + sp[31];
    out[14] = sp[15];
    out[15] = sp[31];
    out[16] = 0;
    out[0x80 / 4] = temp_r6;
    return 0;
}
#pragma pop
extern "C" void fn_800C51BC(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 right0 = arg1[0], diff0 = arg0[0] - right0;
        arg0[0] = right0 + arg0[0];
        arg1[0] = (s32)(((s64)diff0 * arg2[0]) >> 24);
        s32 right1 = arg1[1], diff1 = arg0[1] - right1;
        arg0[1] = right1 + arg0[1];
        arg1[1] = (s32)(((s64)diff1 * arg2[1]) >> 24);
        s32 right2 = arg1[2], diff2 = arg0[2] - right2;
        arg0[2] = right2 + arg0[2];
        arg1[2] = (s32)(((s64)diff2 * arg2[2]) >> 24);
        s32 right3 = arg1[3], diff3 = arg0[3] - right3;
        arg0[3] = right3 + arg0[3];
        arg1[3] = (s32)(((s64)diff3 * arg2[3]) >> 24);
        arg0 += 4;
        arg1 += 4;
        arg2 += 4;
    }
}

void fn_800C5298(s32* arg0, s32* arg1, s32* arg2) {
    s32 i;
    for (i = 0; i < 16; i++) {
        s32 a = arg0[i];
        s32 b = arg1[i];
        s32 c = arg2[i];
        arg0[i] = a + b;
        arg1[i] = (s32)(((s64)(a - b) * c) >> 24);
    }
}

void fn_800C5430(s32 *a, s32 *b, s32 *coeff) {
    s32 i = 4;
    s32 c0 = coeff[0];
    s32 c1 = coeff[1];
    s32 c2 = coeff[2];
    s32 c3 = coeff[3];
    for (; i != 0; i--) {
        register s32 b0 = b[0];
        register s32 a0 = a[0];
        register s32 d0 = a0 - b0;
        register s32 sum0 = a0 + b0;
        a[0] = sum0;
        b[0] = (s32)(((s64)d0 * c0) >> 24);
        register s32 b1 = b[1];
        register s32 a1 = a[1];
        register s32 d1 = a1 - b1;
        register s32 sum1 = a1 + b1;
        a[1] = sum1;
        b[1] = (s32)(((s64)d1 * c1) >> 24);
        register s32 b2 = b[2];
        register s32 a2 = a[2];
        register s32 d2 = a2 - b2;
        register s32 sum2 = a2 + b2;
        a[2] = sum2;
        b[2] = (s32)(((s64)d2 * c2) >> 24);
        register s32 b3 = b[3];
        register s32 a3 = a[3];
        register s32 d3 = a3 - b3;
        register s32 sum3 = a3 + b3;
        a[3] = sum3;
        b[3] = (s32)(((s64)d3 * c3) >> 24);
        a += 8;
        b += 8;
    }
}

extern "C" void fn_800C5508(void *arg0, void *arg1, void *arg2) {
    s32 scale0 = ((s32 *)arg2)[0];
    s32 scale1 = ((s32 *)arg2)[1];
    s32 *dst = (s32 *)arg0;
    s32 *src = (s32 *)arg1;
    for (s32 i = 0; i < 4; i++) {
        s32 b0 = src[0]; s32 a0 = dst[0]; s32 d0 = a0 - b0; s32 sum0 = a0 + b0;
        dst[0] = sum0; src[0] = (s32)(((s64)d0 * scale0) >> 24);
        s32 b1 = src[1]; s32 a1 = dst[1]; s32 d1 = a1 - b1; s32 sum1 = a1 + b1;
        dst[1] = sum1; src[1] = (s32)(((s64)d1 * scale1) >> 24);
        s32 b2 = src[4]; s32 a2 = dst[4]; s32 d2 = a2 - b2; s32 sum2 = a2 + b2;
        dst[4] = sum2; src[4] = (s32)(((s64)d2 * scale0) >> 24);
        s32 b3 = src[5]; s32 a3 = dst[5]; s32 d3 = a3 - b3; s32 sum3 = a3 + b3;
        dst[5] = sum3; src[5] = (s32)(((s64)d3 * scale1) >> 24);
        dst += 8;
        src += 8;
    }
}

extern "C" void fn_800C55D8(void *arg0, void *arg1, s32 *arg2) {
    s32 scale = *arg2;
    s32 *dst = (s32 *)arg0;
    s32 *src = (s32 *)arg1;
    s64 product;
    for (s32 i = 0; i < 4; i++) {
        s32 b0 = src[0]; s32 a0 = dst[0];
        dst[0] = a0 + b0; product = (s64)(a0 - b0) * scale; src[0] = (s32)(product >> 24);
        s32 b1 = src[2]; s32 a1 = dst[2];
        dst[2] = a1 + b1; product = (s64)(a1 - b1) * scale; src[2] = (s32)(product >> 24);
        s32 b2 = src[4]; s32 a2 = dst[4];
        dst[4] = a2 + b2; product = (s64)(a2 - b2) * scale; src[4] = (s32)(product >> 24);
        s32 b3 = src[6]; s32 a3 = dst[6];
        dst[6] = a3 + b3; product = (s64)(a3 - b3) * scale; src[6] = (s32)(product >> 24);
        dst += 8;
        src += 8;
    }
}

extern "C" void fn_800C56A4(void *arg0, void *arg1, s32 arg2) {
    s32 *out = (s32 *)arg0;
    s32 *in = (s32 *)arg1;
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[3];
    out[3] = in[2];
    out[4] = in[7];
    out[5] = in[6];
    out[6] = in[4];
    out[7] = in[5];
    out[8] = in[15];
    out[9] = in[14];
    out[10] = in[12];
    out[11] = in[13];
    out[12] = in[8];
    out[13] = in[9];
    out[14] = in[11];
    out[15] = in[10];
    if (arg2 != 1) {
        out[16] = in[31];
        out[17] = in[30];
        out[18] = in[28];
        out[19] = in[29];
        out[20] = in[24];
        out[21] = in[25];
        out[22] = in[27];
        out[23] = in[26];
        out[24] = in[16];
        out[25] = in[17];
        out[26] = in[19];
        out[27] = in[18];
        out[28] = in[23];
        out[29] = in[22];
        out[30] = in[20];
        out[31] = in[21];
    }
}

void fn_800C57B0(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 *var_r5;
    s32 *var_r5_3;
    s32 *var_r5_4;
    s32 *var_r5_5;
    s32 *var_r5_6;
    s32 *var_r5_7;
    s32 *var_r5_8;
    s32 *var_r7;
    s32 *var_r7_3;
    s32 *var_r7_4;
    s32 *var_r7_5;
    s32 *var_r7_6;
    s32 *var_r7_7;
    s32 *var_r7_8;
    s32 temp_r0;
    s32 temp_r0_10;
    s32 temp_r0_11;
    s32 temp_r0_12;
    s32 temp_r0_13;
    s32 temp_r0_14;
    s32 temp_r0_15;
    s32 temp_r0_16;
    s32 temp_r0_17;
    s32 temp_r0_18;
    s32 temp_r0_19;
    s32 temp_r0_20;
    s32 temp_r0_21;
    s32 temp_r0_22;
    s32 temp_r0_23;
    s32 temp_r0_24;
    s32 temp_r0_25;
    s32 temp_r0_26;
    s32 temp_r0_27;
    s32 temp_r0_28;
    s32 temp_r0_29;
    s32 temp_r0_2;
    s32 temp_r0_30;
    s32 temp_r0_31;
    s32 temp_r0_32;
    s32 temp_r0_33;
    s32 temp_r0_34;
    s32 temp_r0_35;
    s32 temp_r0_36;
    s32 temp_r0_37;
    s32 temp_r0_38;
    s32 temp_r0_39;
    s32 temp_r0_3;
    s32 temp_r0_40;
    s32 temp_r0_41;
    s32 temp_r0_42;
    s32 temp_r0_43;
    s32 temp_r0_44;
    s32 temp_r0_45;
    s32 temp_r0_46;
    s32 temp_r0_47;
    s32 temp_r0_48;
    s32 temp_r0_49;
    s32 temp_r0_4;
    s32 temp_r0_50;
    s32 temp_r0_51;
    s32 temp_r0_52;
    s32 temp_r0_53;
    s32 temp_r0_54;
    s32 temp_r0_55;
    s32 temp_r0_56;
    s32 temp_r0_57;
    s32 temp_r0_58;
    s32 temp_r0_59;
    s32 temp_r0_5;
    s32 temp_r0_60;
    s32 temp_r0_61;
    s32 temp_r0_62;
    s32 temp_r0_63;
    s32 temp_r0_64;
    s32 temp_r0_65;
    s32 temp_r0_66;
    s32 temp_r0_67;
    s32 temp_r0_68;
    s32 temp_r0_69;
    s32 temp_r0_6;
    s32 temp_r0_70;
    s32 temp_r0_71;
    s32 temp_r0_72;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r0_9;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r6;
    s32 temp_r6_10;
    s32 temp_r6_11;
    s32 temp_r6_12;
    s32 temp_r6_13;
    s32 temp_r6_14;
    s32 temp_r6_15;
    s32 temp_r6_16;
    s32 temp_r6_17;
    s32 temp_r6_18;
    s32 temp_r6_19;
    s32 temp_r6_20;
    s32 temp_r6_21;
    s32 temp_r6_22;
    s32 temp_r6_23;
    s32 temp_r6_24;
    s32 temp_r6_25;
    s32 temp_r6_26;
    s32 temp_r6_27;
    s32 temp_r6_2;
    s32 temp_r6_3;
    s32 temp_r6_4;
    s32 temp_r6_5;
    s32 temp_r6_6;
    s32 temp_r6_7;
    s32 temp_r6_8;
    s32 temp_r6_9;
    s32 temp_r8;
    s32 temp_r8_10;
    s32 temp_r8_11;
    s32 temp_r8_12;
    s32 temp_r8_13;
    s32 temp_r8_14;
    s32 temp_r8_15;
    s32 temp_r8_16;
    s32 temp_r8_17;
    s32 temp_r8_18;
    s32 temp_r8_19;
    s32 temp_r8_20;
    s32 temp_r8_21;
    s32 temp_r8_22;
    s32 temp_r8_23;
    s32 temp_r8_24;
    s32 temp_r8_25;
    s32 temp_r8_26;
    s32 temp_r8_27;
    s32 temp_r8_28;
    s32 temp_r8_29;
    s32 temp_r8_2;
    s32 temp_r8_30;
    s32 temp_r8_31;
    s32 temp_r8_32;
    s32 temp_r8_33;
    s32 temp_r8_34;
    s32 temp_r8_35;
    s32 temp_r8_36;
    s32 temp_r8_37;
    s32 temp_r8_38;
    s32 temp_r8_39;
    s32 temp_r8_3;
    s32 temp_r8_40;
    s32 temp_r8_41;
    s32 temp_r8_42;
    s32 temp_r8_43;
    s32 temp_r8_44;
    s32 temp_r8_45;
    s32 temp_r8_46;
    s32 temp_r8_4;
    s32 temp_r8_5;
    s32 temp_r8_6;
    s32 temp_r8_7;
    s32 temp_r8_8;
    s32 temp_r8_9;
    s32 var_cr0_gt;
    s32 var_cr0_gt_2;
    s32 var_ctr_11;
    s32 var_ctr_13;
    s32 var_ctr_15;
    s32 var_ctr_2;
    s32 var_ctr_3;
    s32 var_ctr_5;
    s32 var_ctr_7;
    s32 var_ctr_9;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r10_4;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u32 var_ctr;
    u32 var_ctr_10;
    u32 var_ctr_12;
    u32 var_ctr_14;
    u32 var_ctr_4;
    u32 var_ctr_6;
    u32 var_ctr_8;
    s32 *var_r5_2;
    s32 *var_r7_2;

    temp_r0 = arg2 & 7;
    if (temp_r0 != 0) {
        ;
        var_r7 = arg3 + 0x3F00;
        var_r5 = arg3 + 0x1B00;
        var_r8 = 0;
        if (temp_r0 > 0) {
            temp_r6 = arg0 - 8;
            if (arg0 > 8) {
                var_r9 = 0;
                if ((arg0 >= 8) && (arg0 <= 0x7FFFFFFE)) {
                    var_r9 = 1;
                }
                if (var_r9 != 0) {
                    var_ctr = (u32) (temp_r6 + 7) >> 3U;
                    if (temp_r6 > 0) {
                        do {
                            temp_r6_2 = M2C_FIELD(var_r5, s32 *, 0);
                            var_r8 += 8;
                            temp_r0_2 = M2C_FIELD(var_r7, s32 *, 0);
                            M2C_FIELD(var_r5, s32 *, 0) = temp_r6_2 + temp_r0_2;
                            M2C_FIELD(var_r7, s32 *, 0) = temp_r6_2 - temp_r0_2;
                            temp_r0_3 = M2C_FIELD(var_r5, s32 *, 4);
                            temp_r6_3 = M2C_FIELD(var_r7, s32 *, 4);
                            M2C_FIELD(var_r5, s32 *, 4) = (s32) (temp_r0_3 + temp_r6_3);
                            M2C_FIELD(var_r7, s32 *, 4) = (s32) (temp_r0_3 - temp_r6_3);
                            temp_r0_4 = M2C_FIELD(var_r5, s32 *, 8);
                            temp_r6_4 = M2C_FIELD(var_r7, s32 *, 8);
                            M2C_FIELD(var_r5, s32 *, 8) = (s32) (temp_r0_4 + temp_r6_4);
                            M2C_FIELD(var_r7, s32 *, 8) = (s32) (temp_r0_4 - temp_r6_4);
                            temp_r0_5 = M2C_FIELD(var_r5, s32 *, 0xC);
                            temp_r6_5 = M2C_FIELD(var_r7, s32 *, 0xC);
                            M2C_FIELD(var_r5, s32 *, 0xC) = (s32) (temp_r0_5 + temp_r6_5);
                            M2C_FIELD(var_r7, s32 *, 0xC) = (s32) (temp_r0_5 - temp_r6_5);
                            temp_r0_6 = M2C_FIELD(var_r5, s32 *, 0x10);
                            temp_r6_6 = M2C_FIELD(var_r7, s32 *, 0x10);
                            M2C_FIELD(var_r5, s32 *, 0x10) = (s32) (temp_r0_6 + temp_r6_6);
                            M2C_FIELD(var_r7, s32 *, 0x10) = (s32) (temp_r0_6 - temp_r6_6);
                            temp_r0_7 = M2C_FIELD(var_r5, s32 *, 0x14);
                            temp_r6_7 = M2C_FIELD(var_r7, s32 *, 0x14);
                            M2C_FIELD(var_r5, s32 *, 0x14) = (s32) (temp_r0_7 + temp_r6_7);
                            M2C_FIELD(var_r7, s32 *, 0x14) = (s32) (temp_r0_7 - temp_r6_7);
                            temp_r0_8 = M2C_FIELD(var_r5, s32 *, 0x18);
                            temp_r6_8 = M2C_FIELD(var_r7, s32 *, 0x18);
                            M2C_FIELD(var_r5, s32 *, 0x18) = (s32) (temp_r0_8 + temp_r6_8);
                            M2C_FIELD(var_r7, s32 *, 0x18) = (s32) (temp_r0_8 - temp_r6_8);
                            temp_r0_9 = M2C_FIELD(var_r5, s32 *, 0x1C);
                            temp_r6_9 = M2C_FIELD(var_r7, s32 *, 0x1C);
                            M2C_FIELD(var_r5, s32 *, 0x1C) = (s32) (temp_r0_9 + temp_r6_9);
                            var_r5 += 0x20;
                            M2C_FIELD(var_r7, s32 *, 0x1C) = (s32) (temp_r0_9 - temp_r6_9);
                            var_r7 += 0x20;
                            var_ctr -= 1;
                        } while (var_ctr != 0);
                    }
                }
            }
            var_ctr_2 = arg0 - var_r8;
            if (var_r8 < arg0) {
                do {
                    temp_r0_10 = *var_r5;
                    temp_r4 = *var_r7;
                    *var_r5 = temp_r0_10 + temp_r4;
                    var_r5 += 4;
                    *var_r7 = temp_r0_10 - temp_r4;
                    var_r7 += 4;
                    var_ctr_2 -= 1;
                } while (var_ctr_2 != 0);
            }
        }
    } else {
        temp_r0_11 = arg2 & 8;
        var_cr0_gt = temp_r0_11 > 0;
        if (temp_r0_11 != 0) {
            var_r7_2 = arg3 + 0x3F00;
            var_r5_2 = arg3 + 0x1B00;
            var_ctr_3 = 6;
            do {
                temp_r8 = M2C_FIELD(var_r5_2, s32 *, 0);
                temp_r0_12 = M2C_FIELD(var_r7_2, s32 *, 0);
                M2C_FIELD(var_r5_2, s32 *, 0) = (s32) (temp_r8 + temp_r0_12);
                M2C_FIELD(var_r7_2, s32 *, 0) = (s32) (temp_r8 - temp_r0_12);
                temp_r0_13 = M2C_FIELD(var_r5_2, s32 *, 4);
                temp_r8_2 = M2C_FIELD(var_r7_2, s32 *, 4);
                M2C_FIELD(var_r5_2, s32 *, 4) = (s32) (temp_r0_13 + temp_r8_2);
                M2C_FIELD(var_r7_2, s32 *, 4) = (s32) (temp_r0_13 - temp_r8_2);
                temp_r0_14 = M2C_FIELD(var_r5_2, s32 *, 8);
                temp_r8_3 = M2C_FIELD(var_r7_2, s32 *, 8);
                M2C_FIELD(var_r5_2, s32 *, 8) = (s32) (temp_r0_14 + temp_r8_3);
                M2C_FIELD(var_r7_2, s32 *, 8) = (s32) (temp_r0_14 - temp_r8_3);
                temp_r0_15 = M2C_FIELD(var_r5_2, s32 *, 0xC);
                temp_r8_4 = M2C_FIELD(var_r7_2, s32 *, 0xC);
                M2C_FIELD(var_r5_2, s32 *, 0xC) = (s32) (temp_r0_15 + temp_r8_4);
                M2C_FIELD(var_r7_2, s32 *, 0xC) = (s32) (temp_r0_15 - temp_r8_4);
                temp_r0_16 = M2C_FIELD(var_r5_2, s32 *, 0x10);
                temp_r8_5 = M2C_FIELD(var_r7_2, s32 *, 0x10);
                M2C_FIELD(var_r5_2, s32 *, 0x10) = (s32) (temp_r0_16 + temp_r8_5);
                M2C_FIELD(var_r7_2, s32 *, 0x10) = (s32) (temp_r0_16 - temp_r8_5);
                temp_r0_17 = M2C_FIELD(var_r5_2, s32 *, 0x14);
                temp_r8_6 = M2C_FIELD(var_r7_2, s32 *, 0x14);
                M2C_FIELD(var_r5_2, s32 *, 0x14) = (s32) (temp_r0_17 + temp_r8_6);
                var_r5_2 += 0x18;
                M2C_FIELD(var_r7_2, s32 *, 0x14) = (s32) (temp_r0_17 - temp_r8_6);
                var_r7_2 += 0x18;
                var_ctr_3 -= 1;
            } while (var_ctr_3 != 0);
            ;
            var_r7_3 = arg3 + 0x2430;
            var_r5_3 = arg3 + 0x30;
            var_r9_2 = 0;
            if (var_cr0_gt != 0) {
                temp_r8_7 = arg1 - 8;
                if (arg1 > 8) {
                    var_r10 = 0;
                    if ((arg1 >= 8) && (arg1 <= 0x7FFFFFFE)) {
                        var_r10 = 1;
                    }
                    if (var_r10 != 0) {
                        var_ctr_4 = (u32) (temp_r8_7 + 7) >> 3U;
                        if (temp_r8_7 > 0) {
                            do {
                                temp_r8_8 = M2C_FIELD(var_r5_3, s32 *, 0);
                                var_r9_2 += 8;
                                temp_r0_18 = M2C_FIELD(var_r7_3, s32 *, 0);
                                M2C_FIELD(var_r5_3, s32 *, 0) = temp_r8_8 + temp_r0_18;
                                M2C_FIELD(var_r7_3, s32 *, 0) = temp_r8_8 - temp_r0_18;
                                temp_r0_19 = M2C_FIELD(var_r5_3, s32 *, 4);
                                temp_r8_9 = M2C_FIELD(var_r7_3, s32 *, 4);
                                M2C_FIELD(var_r5_3, s32 *, 4) = (s32) (temp_r0_19 + temp_r8_9);
                                M2C_FIELD(var_r7_3, s32 *, 4) = (s32) (temp_r0_19 - temp_r8_9);
                                temp_r0_20 = M2C_FIELD(var_r5_3, s32 *, 8);
                                temp_r8_10 = M2C_FIELD(var_r7_3, s32 *, 8);
                                M2C_FIELD(var_r5_3, s32 *, 8) = (s32) (temp_r0_20 + temp_r8_10);
                                M2C_FIELD(var_r7_3, s32 *, 8) = (s32) (temp_r0_20 - temp_r8_10);
                                temp_r0_21 = M2C_FIELD(var_r5_3, s32 *, 0xC);
                                temp_r8_11 = M2C_FIELD(var_r7_3, s32 *, 0xC);
                                M2C_FIELD(var_r5_3, s32 *, 0xC) = (s32) (temp_r0_21 + temp_r8_11);
                                M2C_FIELD(var_r7_3, s32 *, 0xC) = (s32) (temp_r0_21 - temp_r8_11);
                                temp_r0_22 = M2C_FIELD(var_r5_3, s32 *, 0x10);
                                temp_r8_12 = M2C_FIELD(var_r7_3, s32 *, 0x10);
                                M2C_FIELD(var_r5_3, s32 *, 0x10) = (s32) (temp_r0_22 + temp_r8_12);
                                M2C_FIELD(var_r7_3, s32 *, 0x10) = (s32) (temp_r0_22 - temp_r8_12);
                                temp_r0_23 = M2C_FIELD(var_r5_3, s32 *, 0x14);
                                temp_r8_13 = M2C_FIELD(var_r7_3, s32 *, 0x14);
                                M2C_FIELD(var_r5_3, s32 *, 0x14) = (s32) (temp_r0_23 + temp_r8_13);
                                M2C_FIELD(var_r7_3, s32 *, 0x14) = (s32) (temp_r0_23 - temp_r8_13);
                                temp_r0_24 = M2C_FIELD(var_r5_3, s32 *, 0x18);
                                temp_r8_14 = M2C_FIELD(var_r7_3, s32 *, 0x18);
                                M2C_FIELD(var_r5_3, s32 *, 0x18) = (s32) (temp_r0_24 + temp_r8_14);
                                M2C_FIELD(var_r7_3, s32 *, 0x18) = (s32) (temp_r0_24 - temp_r8_14);
                                temp_r0_25 = M2C_FIELD(var_r5_3, s32 *, 0x1C);
                                temp_r8_15 = M2C_FIELD(var_r7_3, s32 *, 0x1C);
                                M2C_FIELD(var_r5_3, s32 *, 0x1C) = (s32) (temp_r0_25 + temp_r8_15);
                                var_r5_3 += 0x20;
                                M2C_FIELD(var_r7_3, s32 *, 0x1C) = (s32) (temp_r0_25 - temp_r8_15);
                                var_r7_3 += 0x20;
                                var_ctr_4 -= 1;
                            } while (var_ctr_4 != 0);
                        }
                    }
                }
                var_ctr_5 = arg1 - var_r9_2;
                var_cr0_gt = var_r9_2 > arg1;
                if (var_r9_2 < arg1) {
                    do {
                        temp_r0_26 = *var_r5_3;
                        temp_r8_16 = *var_r7_3;
                        *var_r5_3 = temp_r0_26 + temp_r8_16;
                        var_r5_3 += 4;
                        *var_r7_3 = temp_r0_26 - temp_r8_16;
                        var_r7_3 += 4;
                        var_ctr_5 -= 1;
                    } while (var_ctr_5 != 0);
                }
            }
            ;
            var_r7_4 = arg3 + 0x2D30;
            var_r5_4 = arg3 + 0x930;
            var_r9_3 = 0;
            if (var_cr0_gt != 0) {
                temp_r8_17 = arg1 - 8;
                if (arg1 > 8) {
                    var_r10_2 = 0;
                    if ((arg1 >= 8) && (arg1 <= 0x7FFFFFFE)) {
                        var_r10_2 = 1;
                    }
                    if (var_r10_2 != 0) {
                        var_ctr_6 = (u32) (temp_r8_17 + 7) >> 3U;
                        if (temp_r8_17 > 0) {
                            do {
                                temp_r8_18 = M2C_FIELD(var_r5_4, s32 *, 0);
                                var_r9_3 += 8;
                                temp_r0_27 = M2C_FIELD(var_r7_4, s32 *, 0);
                                M2C_FIELD(var_r5_4, s32 *, 0) = temp_r8_18 + temp_r0_27;
                                M2C_FIELD(var_r7_4, s32 *, 0) = temp_r8_18 - temp_r0_27;
                                temp_r0_28 = M2C_FIELD(var_r5_4, s32 *, 4);
                                temp_r8_19 = M2C_FIELD(var_r7_4, s32 *, 4);
                                M2C_FIELD(var_r5_4, s32 *, 4) = (s32) (temp_r0_28 + temp_r8_19);
                                M2C_FIELD(var_r7_4, s32 *, 4) = (s32) (temp_r0_28 - temp_r8_19);
                                temp_r0_29 = M2C_FIELD(var_r5_4, s32 *, 8);
                                temp_r8_20 = M2C_FIELD(var_r7_4, s32 *, 8);
                                M2C_FIELD(var_r5_4, s32 *, 8) = (s32) (temp_r0_29 + temp_r8_20);
                                M2C_FIELD(var_r7_4, s32 *, 8) = (s32) (temp_r0_29 - temp_r8_20);
                                temp_r0_30 = M2C_FIELD(var_r5_4, s32 *, 0xC);
                                temp_r8_21 = M2C_FIELD(var_r7_4, s32 *, 0xC);
                                M2C_FIELD(var_r5_4, s32 *, 0xC) = (s32) (temp_r0_30 + temp_r8_21);
                                M2C_FIELD(var_r7_4, s32 *, 0xC) = (s32) (temp_r0_30 - temp_r8_21);
                                temp_r0_31 = M2C_FIELD(var_r5_4, s32 *, 0x10);
                                temp_r8_22 = M2C_FIELD(var_r7_4, s32 *, 0x10);
                                M2C_FIELD(var_r5_4, s32 *, 0x10) = (s32) (temp_r0_31 + temp_r8_22);
                                M2C_FIELD(var_r7_4, s32 *, 0x10) = (s32) (temp_r0_31 - temp_r8_22);
                                temp_r0_32 = M2C_FIELD(var_r5_4, s32 *, 0x14);
                                temp_r8_23 = M2C_FIELD(var_r7_4, s32 *, 0x14);
                                M2C_FIELD(var_r5_4, s32 *, 0x14) = (s32) (temp_r0_32 + temp_r8_23);
                                M2C_FIELD(var_r7_4, s32 *, 0x14) = (s32) (temp_r0_32 - temp_r8_23);
                                temp_r0_33 = M2C_FIELD(var_r5_4, s32 *, 0x18);
                                temp_r8_24 = M2C_FIELD(var_r7_4, s32 *, 0x18);
                                M2C_FIELD(var_r5_4, s32 *, 0x18) = (s32) (temp_r0_33 + temp_r8_24);
                                M2C_FIELD(var_r7_4, s32 *, 0x18) = (s32) (temp_r0_33 - temp_r8_24);
                                temp_r0_34 = M2C_FIELD(var_r5_4, s32 *, 0x1C);
                                temp_r8_25 = M2C_FIELD(var_r7_4, s32 *, 0x1C);
                                M2C_FIELD(var_r5_4, s32 *, 0x1C) = (s32) (temp_r0_34 + temp_r8_25);
                                var_r5_4 += 0x20;
                                M2C_FIELD(var_r7_4, s32 *, 0x1C) = (s32) (temp_r0_34 - temp_r8_25);
                                var_r7_4 += 0x20;
                                var_ctr_6 -= 1;
                            } while (var_ctr_6 != 0);
                        }
                    }
                }
                var_ctr_7 = arg1 - var_r9_3;
                var_cr0_gt = var_r9_3 > arg1;
                if (var_r9_3 < arg1) {
                    do {
                        temp_r0_35 = *var_r5_4;
                        temp_r8_26 = *var_r7_4;
                        *var_r5_4 = temp_r0_35 + temp_r8_26;
                        var_r5_4 += 4;
                        *var_r7_4 = temp_r0_35 - temp_r8_26;
                        var_r7_4 += 4;
                        var_ctr_7 -= 1;
                    } while (var_ctr_7 != 0);
                }
            }
            ;
            var_r7_5 = arg3 + 0x3630;
            var_r5_5 = arg3 + 0x1230;
            var_r8_2 = 0;
            if (var_cr0_gt != 0) {
                temp_r6_10 = arg1 - 8;
                if (arg1 > 8) {
                    var_r9_4 = 0;
                    if ((arg1 >= 8) && (arg1 <= 0x7FFFFFFE)) {
                        var_r9_4 = 1;
                    }
                    if (var_r9_4 != 0) {
                        var_ctr_8 = (u32) (temp_r6_10 + 7) >> 3U;
                        if (temp_r6_10 > 0) {
                            do {
                                temp_r6_11 = M2C_FIELD(var_r5_5, s32 *, 0);
                                var_r8_2 += 8;
                                temp_r0_36 = M2C_FIELD(var_r7_5, s32 *, 0);
                                M2C_FIELD(var_r5_5, s32 *, 0) = temp_r6_11 + temp_r0_36;
                                M2C_FIELD(var_r7_5, s32 *, 0) = temp_r6_11 - temp_r0_36;
                                temp_r0_37 = M2C_FIELD(var_r5_5, s32 *, 4);
                                temp_r6_12 = M2C_FIELD(var_r7_5, s32 *, 4);
                                M2C_FIELD(var_r5_5, s32 *, 4) = (s32) (temp_r0_37 + temp_r6_12);
                                M2C_FIELD(var_r7_5, s32 *, 4) = (s32) (temp_r0_37 - temp_r6_12);
                                temp_r0_38 = M2C_FIELD(var_r5_5, s32 *, 8);
                                temp_r6_13 = M2C_FIELD(var_r7_5, s32 *, 8);
                                M2C_FIELD(var_r5_5, s32 *, 8) = (s32) (temp_r0_38 + temp_r6_13);
                                M2C_FIELD(var_r7_5, s32 *, 8) = (s32) (temp_r0_38 - temp_r6_13);
                                temp_r0_39 = M2C_FIELD(var_r5_5, s32 *, 0xC);
                                temp_r6_14 = M2C_FIELD(var_r7_5, s32 *, 0xC);
                                M2C_FIELD(var_r5_5, s32 *, 0xC) = (s32) (temp_r0_39 + temp_r6_14);
                                M2C_FIELD(var_r7_5, s32 *, 0xC) = (s32) (temp_r0_39 - temp_r6_14);
                                temp_r0_40 = M2C_FIELD(var_r5_5, s32 *, 0x10);
                                temp_r6_15 = M2C_FIELD(var_r7_5, s32 *, 0x10);
                                M2C_FIELD(var_r5_5, s32 *, 0x10) = (s32) (temp_r0_40 + temp_r6_15);
                                M2C_FIELD(var_r7_5, s32 *, 0x10) = (s32) (temp_r0_40 - temp_r6_15);
                                temp_r0_41 = M2C_FIELD(var_r5_5, s32 *, 0x14);
                                temp_r6_16 = M2C_FIELD(var_r7_5, s32 *, 0x14);
                                M2C_FIELD(var_r5_5, s32 *, 0x14) = (s32) (temp_r0_41 + temp_r6_16);
                                M2C_FIELD(var_r7_5, s32 *, 0x14) = (s32) (temp_r0_41 - temp_r6_16);
                                temp_r0_42 = M2C_FIELD(var_r5_5, s32 *, 0x18);
                                temp_r6_17 = M2C_FIELD(var_r7_5, s32 *, 0x18);
                                M2C_FIELD(var_r5_5, s32 *, 0x18) = (s32) (temp_r0_42 + temp_r6_17);
                                M2C_FIELD(var_r7_5, s32 *, 0x18) = (s32) (temp_r0_42 - temp_r6_17);
                                temp_r0_43 = M2C_FIELD(var_r5_5, s32 *, 0x1C);
                                temp_r6_18 = M2C_FIELD(var_r7_5, s32 *, 0x1C);
                                M2C_FIELD(var_r5_5, s32 *, 0x1C) = (s32) (temp_r0_43 + temp_r6_18);
                                var_r5_5 += 0x20;
                                M2C_FIELD(var_r7_5, s32 *, 0x1C) = (s32) (temp_r0_43 - temp_r6_18);
                                var_r7_5 += 0x20;
                                var_ctr_8 -= 1;
                            } while (var_ctr_8 != 0);
                        }
                    }
                }
                var_ctr_9 = arg1 - var_r8_2;
                if (var_r8_2 < arg1) {
                    do {
                        temp_r0_44 = *var_r5_5;
                        temp_r4_2 = *var_r7_5;
                        *var_r5_5 = temp_r0_44 + temp_r4_2;
                        var_r5_5 += 4;
                        *var_r7_5 = temp_r0_44 - temp_r4_2;
                        var_r7_5 += 4;
                        var_ctr_9 -= 1;
                    } while (var_ctr_9 != 0);
                }
            }
        } else {
            temp_r0_45 = arg2 & 0x10;
            var_cr0_gt_2 = temp_r0_45 > 0;
            if (temp_r0_45 != 0) {
                ;
                var_r5_6 = arg3;
                var_r7_6 = arg3 + 0x2400;
                var_r9_5 = 0;
                if (var_cr0_gt_2 != 0) {
                    temp_r8_27 = arg1 - 8;
                    if (arg1 > 8) {
                        var_r10_3 = 0;
                        if ((arg1 >= 8) && (arg1 <= 0x7FFFFFFE)) {
                            var_r10_3 = 1;
                        }
                        if (var_r10_3 != 0) {
                            var_ctr_10 = (u32) (temp_r8_27 + 7) >> 3U;
                            if (temp_r8_27 > 0) {
                                do {
                                    temp_r8_28 = M2C_FIELD(var_r5_6, s32 *, 0);
                                    var_r9_5 += 8;
                                    temp_r0_46 = M2C_FIELD(var_r7_6, s32 *, 0);
                                    M2C_FIELD(var_r5_6, s32 *, 0) = temp_r8_28 + temp_r0_46;
                                    M2C_FIELD(var_r7_6, s32 *, 0) = temp_r8_28 - temp_r0_46;
                                    temp_r0_47 = M2C_FIELD(var_r5_6, s32 *, 4);
                                    temp_r8_29 = M2C_FIELD(var_r7_6, s32 *, 4);
                                    M2C_FIELD(var_r5_6, s32 *, 4) = (s32) (temp_r0_47 + temp_r8_29);
                                    M2C_FIELD(var_r7_6, s32 *, 4) = (s32) (temp_r0_47 - temp_r8_29);
                                    temp_r0_48 = M2C_FIELD(var_r5_6, s32 *, 8);
                                    temp_r8_30 = M2C_FIELD(var_r7_6, s32 *, 8);
                                    M2C_FIELD(var_r5_6, s32 *, 8) = (s32) (temp_r0_48 + temp_r8_30);
                                    M2C_FIELD(var_r7_6, s32 *, 8) = (s32) (temp_r0_48 - temp_r8_30);
                                    temp_r0_49 = M2C_FIELD(var_r5_6, s32 *, 0xC);
                                    temp_r8_31 = M2C_FIELD(var_r7_6, s32 *, 0xC);
                                    M2C_FIELD(var_r5_6, s32 *, 0xC) = (s32) (temp_r0_49 + temp_r8_31);
                                    M2C_FIELD(var_r7_6, s32 *, 0xC) = (s32) (temp_r0_49 - temp_r8_31);
                                    temp_r0_50 = M2C_FIELD(var_r5_6, s32 *, 0x10);
                                    temp_r8_32 = M2C_FIELD(var_r7_6, s32 *, 0x10);
                                    M2C_FIELD(var_r5_6, s32 *, 0x10) = (s32) (temp_r0_50 + temp_r8_32);
                                    M2C_FIELD(var_r7_6, s32 *, 0x10) = (s32) (temp_r0_50 - temp_r8_32);
                                    temp_r0_51 = M2C_FIELD(var_r5_6, s32 *, 0x14);
                                    temp_r8_33 = M2C_FIELD(var_r7_6, s32 *, 0x14);
                                    M2C_FIELD(var_r5_6, s32 *, 0x14) = (s32) (temp_r0_51 + temp_r8_33);
                                    M2C_FIELD(var_r7_6, s32 *, 0x14) = (s32) (temp_r0_51 - temp_r8_33);
                                    temp_r0_52 = M2C_FIELD(var_r5_6, s32 *, 0x18);
                                    temp_r8_34 = M2C_FIELD(var_r7_6, s32 *, 0x18);
                                    M2C_FIELD(var_r5_6, s32 *, 0x18) = (s32) (temp_r0_52 + temp_r8_34);
                                    M2C_FIELD(var_r7_6, s32 *, 0x18) = (s32) (temp_r0_52 - temp_r8_34);
                                    temp_r0_53 = M2C_FIELD(var_r5_6, s32 *, 0x1C);
                                    temp_r8_35 = M2C_FIELD(var_r7_6, s32 *, 0x1C);
                                    M2C_FIELD(var_r5_6, s32 *, 0x1C) = (s32) (temp_r0_53 + temp_r8_35);
                                    var_r5_6 += 0x20;
                                    M2C_FIELD(var_r7_6, s32 *, 0x1C) = (s32) (temp_r0_53 - temp_r8_35);
                                    var_r7_6 += 0x20;
                                    var_ctr_10 -= 1;
                                } while (var_ctr_10 != 0);
                            }
                        }
                    }
                    var_ctr_11 = arg1 - var_r9_5;
                    var_cr0_gt_2 = var_r9_5 > arg1;
                    if (var_r9_5 < arg1) {
                        do {
                            temp_r0_54 = *var_r5_6;
                            temp_r8_36 = *var_r7_6;
                            *var_r5_6 = temp_r0_54 + temp_r8_36;
                            var_r5_6 += 4;
                            *var_r7_6 = temp_r0_54 - temp_r8_36;
                            var_r7_6 += 4;
                            var_ctr_11 -= 1;
                        } while (var_ctr_11 != 0);
                    }
                }
                ;
                var_r7_7 = arg3 + 0x2D00;
                var_r5_7 = arg3 + 0x900;
                var_r9_6 = 0;
                if (var_cr0_gt_2 != 0) {
                    temp_r8_37 = arg1 - 8;
                    if (arg1 > 8) {
                        var_r10_4 = 0;
                        if ((arg1 >= 8) && (arg1 <= 0x7FFFFFFE)) {
                            var_r10_4 = 1;
                        }
                        if (var_r10_4 != 0) {
                            var_ctr_12 = (u32) (temp_r8_37 + 7) >> 3U;
                            if (temp_r8_37 > 0) {
                                do {
                                    temp_r8_38 = M2C_FIELD(var_r5_7, s32 *, 0);
                                    var_r9_6 += 8;
                                    temp_r0_55 = M2C_FIELD(var_r7_7, s32 *, 0);
                                    M2C_FIELD(var_r5_7, s32 *, 0) = temp_r8_38 + temp_r0_55;
                                    M2C_FIELD(var_r7_7, s32 *, 0) = temp_r8_38 - temp_r0_55;
                                    temp_r0_56 = M2C_FIELD(var_r5_7, s32 *, 4);
                                    temp_r8_39 = M2C_FIELD(var_r7_7, s32 *, 4);
                                    M2C_FIELD(var_r5_7, s32 *, 4) = (s32) (temp_r0_56 + temp_r8_39);
                                    M2C_FIELD(var_r7_7, s32 *, 4) = (s32) (temp_r0_56 - temp_r8_39);
                                    temp_r0_57 = M2C_FIELD(var_r5_7, s32 *, 8);
                                    temp_r8_40 = M2C_FIELD(var_r7_7, s32 *, 8);
                                    M2C_FIELD(var_r5_7, s32 *, 8) = (s32) (temp_r0_57 + temp_r8_40);
                                    M2C_FIELD(var_r7_7, s32 *, 8) = (s32) (temp_r0_57 - temp_r8_40);
                                    temp_r0_58 = M2C_FIELD(var_r5_7, s32 *, 0xC);
                                    temp_r8_41 = M2C_FIELD(var_r7_7, s32 *, 0xC);
                                    M2C_FIELD(var_r5_7, s32 *, 0xC) = (s32) (temp_r0_58 + temp_r8_41);
                                    M2C_FIELD(var_r7_7, s32 *, 0xC) = (s32) (temp_r0_58 - temp_r8_41);
                                    temp_r0_59 = M2C_FIELD(var_r5_7, s32 *, 0x10);
                                    temp_r8_42 = M2C_FIELD(var_r7_7, s32 *, 0x10);
                                    M2C_FIELD(var_r5_7, s32 *, 0x10) = (s32) (temp_r0_59 + temp_r8_42);
                                    M2C_FIELD(var_r7_7, s32 *, 0x10) = (s32) (temp_r0_59 - temp_r8_42);
                                    temp_r0_60 = M2C_FIELD(var_r5_7, s32 *, 0x14);
                                    temp_r8_43 = M2C_FIELD(var_r7_7, s32 *, 0x14);
                                    M2C_FIELD(var_r5_7, s32 *, 0x14) = (s32) (temp_r0_60 + temp_r8_43);
                                    M2C_FIELD(var_r7_7, s32 *, 0x14) = (s32) (temp_r0_60 - temp_r8_43);
                                    temp_r0_61 = M2C_FIELD(var_r5_7, s32 *, 0x18);
                                    temp_r8_44 = M2C_FIELD(var_r7_7, s32 *, 0x18);
                                    M2C_FIELD(var_r5_7, s32 *, 0x18) = (s32) (temp_r0_61 + temp_r8_44);
                                    M2C_FIELD(var_r7_7, s32 *, 0x18) = (s32) (temp_r0_61 - temp_r8_44);
                                    temp_r0_62 = M2C_FIELD(var_r5_7, s32 *, 0x1C);
                                    temp_r8_45 = M2C_FIELD(var_r7_7, s32 *, 0x1C);
                                    M2C_FIELD(var_r5_7, s32 *, 0x1C) = (s32) (temp_r0_62 + temp_r8_45);
                                    var_r5_7 += 0x20;
                                    M2C_FIELD(var_r7_7, s32 *, 0x1C) = (s32) (temp_r0_62 - temp_r8_45);
                                    var_r7_7 += 0x20;
                                    var_ctr_12 -= 1;
                                } while (var_ctr_12 != 0);
                            }
                        }
                    }
                    var_ctr_13 = arg1 - var_r9_6;
                    var_cr0_gt_2 = var_r9_6 > arg1;
                    if (var_r9_6 < arg1) {
                        do {
                            temp_r0_63 = *var_r5_7;
                            temp_r8_46 = *var_r7_7;
                            *var_r5_7 = temp_r0_63 + temp_r8_46;
                            var_r5_7 += 4;
                            *var_r7_7 = temp_r0_63 - temp_r8_46;
                            var_r7_7 += 4;
                            var_ctr_13 -= 1;
                        } while (var_ctr_13 != 0);
                    }
                }
                ;
                var_r7_8 = arg3 + 0x3600;
                var_r5_8 = arg3 + 0x1200;
                var_r8_3 = 0;
                if (var_cr0_gt_2 != 0) {
                    temp_r6_19 = arg1 - 8;
                    if (arg1 > 8) {
                        var_r9_7 = 0;
                        if ((arg1 >= 8) && (arg1 <= 0x7FFFFFFE)) {
                            var_r9_7 = 1;
                        }
                        if (var_r9_7 != 0) {
                            var_ctr_14 = (u32) (temp_r6_19 + 7) >> 3U;
                            if (temp_r6_19 > 0) {
                                do {
                                    temp_r6_20 = M2C_FIELD(var_r5_8, s32 *, 0);
                                    var_r8_3 += 8;
                                    temp_r0_64 = M2C_FIELD(var_r7_8, s32 *, 0);
                                    M2C_FIELD(var_r5_8, s32 *, 0) = temp_r6_20 + temp_r0_64;
                                    M2C_FIELD(var_r7_8, s32 *, 0) = temp_r6_20 - temp_r0_64;
                                    temp_r0_65 = M2C_FIELD(var_r5_8, s32 *, 4);
                                    temp_r6_21 = M2C_FIELD(var_r7_8, s32 *, 4);
                                    M2C_FIELD(var_r5_8, s32 *, 4) = (s32) (temp_r0_65 + temp_r6_21);
                                    M2C_FIELD(var_r7_8, s32 *, 4) = (s32) (temp_r0_65 - temp_r6_21);
                                    temp_r0_66 = M2C_FIELD(var_r5_8, s32 *, 8);
                                    temp_r6_22 = M2C_FIELD(var_r7_8, s32 *, 8);
                                    M2C_FIELD(var_r5_8, s32 *, 8) = (s32) (temp_r0_66 + temp_r6_22);
                                    M2C_FIELD(var_r7_8, s32 *, 8) = (s32) (temp_r0_66 - temp_r6_22);
                                    temp_r0_67 = M2C_FIELD(var_r5_8, s32 *, 0xC);
                                    temp_r6_23 = M2C_FIELD(var_r7_8, s32 *, 0xC);
                                    M2C_FIELD(var_r5_8, s32 *, 0xC) = (s32) (temp_r0_67 + temp_r6_23);
                                    M2C_FIELD(var_r7_8, s32 *, 0xC) = (s32) (temp_r0_67 - temp_r6_23);
                                    temp_r0_68 = M2C_FIELD(var_r5_8, s32 *, 0x10);
                                    temp_r6_24 = M2C_FIELD(var_r7_8, s32 *, 0x10);
                                    M2C_FIELD(var_r5_8, s32 *, 0x10) = (s32) (temp_r0_68 + temp_r6_24);
                                    M2C_FIELD(var_r7_8, s32 *, 0x10) = (s32) (temp_r0_68 - temp_r6_24);
                                    temp_r0_69 = M2C_FIELD(var_r5_8, s32 *, 0x14);
                                    temp_r6_25 = M2C_FIELD(var_r7_8, s32 *, 0x14);
                                    M2C_FIELD(var_r5_8, s32 *, 0x14) = (s32) (temp_r0_69 + temp_r6_25);
                                    M2C_FIELD(var_r7_8, s32 *, 0x14) = (s32) (temp_r0_69 - temp_r6_25);
                                    temp_r0_70 = M2C_FIELD(var_r5_8, s32 *, 0x18);
                                    temp_r6_26 = M2C_FIELD(var_r7_8, s32 *, 0x18);
                                    M2C_FIELD(var_r5_8, s32 *, 0x18) = (s32) (temp_r0_70 + temp_r6_26);
                                    M2C_FIELD(var_r7_8, s32 *, 0x18) = (s32) (temp_r0_70 - temp_r6_26);
                                    temp_r0_71 = M2C_FIELD(var_r5_8, s32 *, 0x1C);
                                    temp_r6_27 = M2C_FIELD(var_r7_8, s32 *, 0x1C);
                                    M2C_FIELD(var_r5_8, s32 *, 0x1C) = (s32) (temp_r0_71 + temp_r6_27);
                                    var_r5_8 += 0x20;
                                    M2C_FIELD(var_r7_8, s32 *, 0x1C) = (s32) (temp_r0_71 - temp_r6_27);
                                    var_r7_8 += 0x20;
                                    var_ctr_14 -= 1;
                                } while (var_ctr_14 != 0);
                            }
                        }
                    }
                    var_ctr_15 = arg1 - var_r8_3;
                    if (var_r8_3 < arg1) {
                        do {
                            temp_r0_72 = *var_r5_8;
                            temp_r4_3 = *var_r7_8;
                            *var_r5_8 = temp_r0_72 + temp_r4_3;
                            var_r5_8 += 4;
                            *var_r7_8 = temp_r0_72 - temp_r4_3;
                            var_r7_8 += 4;
                            var_ctr_15 -= 1;
                        } while (var_ctr_15 != 0);
                    }
                }
            }
        }
    }
}

extern "C" s32 WENCGetEncodeData(void *infoArg, u32 flag, const s16 *pcmData, s32 samples, void *adpcmArg) {
    const f64 table[] = {0.89843750, 0.89843750, 0.89843750, 0.89843750,
                         1.19921875, 1.59765625, 2.00000000, 2.39843750};

    u8 *dst;
    const s16 *src;
    int i;
    s32 da;
    s32 l3, l2, l1, l0;
    s32 dlx;
    s32 xnc;
    s32 offset;
    s32 index;
    s32 encodeSize;
    s32 xn;
    s32 dl;
    s32 qn;
    s32 dn;
    s32 dlh;
    s32 dlq;
    u8 by;

    encodeSize = (samples + 1) / 2;
    memset(adpcmArg, 0, encodeSize);

    src = pcmData;
    dst = (u8 *)adpcmArg;

    if ((flag & 1) == 0) {
        xn = 0;
        dl = 127;
        qn = 0;
        dn = 0;
        dlh = 0;
        dlq = 0;
    } else {
        xn = ((s32 *)infoArg)[0];
        dl = ((s32 *)infoArg)[1];
        qn = ((s32 *)infoArg)[2];
        dn = ((s32 *)infoArg)[3];
        dlh = ((s32 *)infoArg)[4];
        dlq = ((s32 *)infoArg)[5];
    }

    for (i = 0; i < samples; i++) {
        l0 = 0;
        l1 = 0;
        l2 = 0;
        l3 = 0;

        da = *src++;
        if (da < xn) {
            l3 = 1;
        }

        dn = __abs(da - xn);
        if (dn >= dl) {
            l2 = 1;
            dn -= dl;
        }

        dlh = dl / 2;
        if (dn >= dlh) {
            l1 = 1;
            dn -= dlh;
        }

        dlq = dlh / 2;
        if (dn >= dlq) {
            l0 = 1;
            dn -= dlq;
        }

        dlx = dlq / 2;
        qn = (1 - l3 * 2) * (dl * l2 + dlh * l1 + dlq * l0 + dlx);

        if (qn > 0xFFFF) {
            qn = 0xFFFF;
        }
        if (qn < -0x10000) {
            qn = -0x10000;
        }

        xnc = xn + qn;
        if (xnc > 0x7FFF) {
            xnc = 0x7FFF;
        }
        if (xnc < -0x8000) {
            xnc = -0x8000;
        }

        xn = xnc;
        offset = (i & 1) == 0 ? 4 : 0;

        by = l3 * 8 + l2 * 4 + l1 * 2 + l0;
        dst[i / 2] |= by << offset;

        index = l2 * 4 + l1 * 2 + l0;
        dl *= table[index];

        if (dl <= 127) {
            dl = 127;
        }
        if (dl >= 0x6000) {
            dl = 0x6000;
        }
    }

    ((s32 *)infoArg)[0] = xn;
    ((s32 *)infoArg)[1] = dl;
    ((s32 *)infoArg)[2] = qn;
    ((s32 *)infoArg)[3] = dn;
    ((s32 *)infoArg)[4] = dlh;
    ((s32 *)infoArg)[5] = dlq;

    return samples;
}

extern "C" void* fn_800C64DC(u32 size) {
    return MEMAllocFromAllocator(lbl_80559708, size);
}

extern "C" void fn_800CF170(void*);
extern "C" void* lbl_804075F0[];
extern "C" u32 lbl_8055DD90;

extern "C" void fn_800C64E8(u32 size) {
    MEMFreeToAllocator(lbl_80559708, (void*)size);
}

extern "C" void fn_800C64F4(void* arg0) {
    void* block;

    MEMInitAllocatorForExpHeap(&lbl_804075E0,
                               MEMCreateExpHeapEx(*(void**)((u8*)arg0 + 0x10),
                                                  *(u32*)((u8*)arg0 + 0x24), 0),
                               0x20);
    lbl_80559708 = &lbl_804075E0;
    lbl_8055DDF0 = &lbl_804075E0;
    block = MEMAllocFromAllocator(&lbl_804075E0, 0x758);
    if (block != NULL) {
        if (block != NULL) {
            block = fn_800C6914(block, arg0);
        }
        lbl_8055DD98 = block;
    }
    fn_800C6CE8(lbl_8055DD98);
}

extern "C" void fn_800C657C(void) {
    fn_800C6A1C(lbl_8055DD98, -1);
    MEMFreeToAllocator(lbl_80559708, lbl_8055DD98);
    lbl_8055DD98 = NULL;
    MEMDestroyExpHeap((MEMiHeapHead*)lbl_80559708->heap);
}

extern "C" void fn_800C65C4(void) {
    fn_800C7998(lbl_8055DD98);
}

extern "C" void fn_800C81F0(void*, s32);
extern "C" void fn_800CEBE0(void*, s32);
extern "C" s32 fn_800C65CC(s32 arg0) {
    fn_800C81F0(lbl_8055DD98, arg0);
    if (*(s32*)((u8*)lbl_8055DD98 + 0x10) != 0x12) {
        return -1;
    }
    return *(s32*)((u8*)lbl_8055DD98 + 0xAC);
}

extern "C" void *lbl_8055DD98;
extern "C" f32 lbl_80560DC0;
extern "C" f32 lbl_80560DC4;
extern "C" void fn_800CEDE8(void);
extern "C" void GXSetTevColor(u32, void *);
extern "C" void GXBegin(u8, u8, u16);
extern "C" void fn_800C6610(void) {
    s32 count;
    u8 *entry;
    u8 *base = (u8 *)lbl_8055DD98;
    struct Dispatch {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(void *);
    };

    ((Dispatch **)(base + 0x1E0))[0]->d8(base + 0x200);
    if (*(s32 *)(*(u8 **)(base + 4) + 0x20) == 0) {
        entry = base + 0xC;
        count = 3;
        do {
            ((Dispatch **)(entry + 0x1E4))[0]->d8(base + 0x200);
            count--;
            entry -= 4;
        } while (count >= 0);
    }

    s32 value = *(s32 *)(base + 0x3FC);
    s32 numerator = (value << 8) - value;
    count = (numerator / *(s32 *)(base + 0x400)) & 0xFF;
    fn_800CEDE8();

    u8 color[4];
    u32 packed;
    color[0] = *(u8 *)(base + 0x408);
    color[1] = *(u8 *)(base + 0x409);
    color[2] = *(u8 *)(base + 0x40A);
    color[3] = (u8)count;
    packed = *(u32 *)color;
    GXSetTevColor(1, &packed);
    GXBegin(0x80, 0, 4);
    *(volatile f32 *)0xCC008000 = lbl_80560DC0;
    *(volatile f32 *)0xCC008000 = lbl_80560DC0;
    *(volatile f32 *)0xCC008000 = lbl_80560DC4;
    *(volatile f32 *)0xCC008000 = lbl_80560DC0;
    *(volatile f32 *)0xCC008000 = lbl_80560DC4;
    *(volatile f32 *)0xCC008000 = lbl_80560DC4;
    *(volatile f32 *)0xCC008000 = lbl_80560DC0;
    *(volatile f32 *)0xCC008000 = lbl_80560DC4;
}

extern "C" s32 fn_800C673C(void) {
    if (*(s32*)((u8*)lbl_8055DD98 + 0x10) != 0x12) {
        return -1;
    }
    return *(s32*)((u8*)lbl_8055DD98 + 0xAC);
}

extern "C" void fn_800C675C(u32 size) {
    fn_800CEBE0(lbl_8055DD98, size);
}

extern "C" u8 fn_800C6768(void) {
    return *(u8 *)((char *)lbl_8055DD98 + 0x88);
}

extern "C" s32 AIGetDMAStatus(void);
extern "C" s32 TRKPostEvent(void *);
extern "C" s32 TRKMessageSend(void *);
extern "C" void InitSoundSystem__Q36nw4hbm3snd11SoundSystemFll(s32, s32);
extern "C" void *fn_800ECAEC(void *);
extern "C" s32 fn_800ECB90(void *, s32);
extern "C" void fn_800CEF60(void *, void *, s32);
extern "C" void fn_800C6774(s32 arg0, void *arg1, u32 arg2) {
    const char *file = (const char *)lbl_8031D840;
    void *base;
    void *block;

    MEMInitAllocatorForFrmHeap((MEMAllocator *)lbl_804075F0,
                               MEMCreateFrmHeapEx(arg1, arg2, 0), 0x20);
    base = lbl_8055DD98;
    if (AIGetDMAStatus() == 0) {
        TRKPostEvent(0);
        ((s32 (*)(void))TRKMessageSend)();
    }
    InitSoundSystem__Q36nw4hbm3snd11SoundSystemFll(4, 3);
    block = MEMAllocFromAllocator((MEMAllocator *)lbl_804075F0, 0x150);
    if (block != NULL) {
        if (block != NULL) {
            block = fn_800ECAEC(block);
        }
        *(void **)((u8 *)base + 0x5C8) = block;
    }
    if (*(void * volatile *)((u8 *)base + 0x5C8) == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, (s32)0xEFC, file + 0x4C);
    }
    if (fn_800ECB90(*(void * volatile *)((u8 *)base + 0x5C8), arg0) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, (s32)0xF01, file + 0x80);
    }
    fn_800CEF60(base, *(void * volatile *)((u8 *)base + 0x5C8), 0);
}

extern "C" void fn_800C687C(void) {
    fn_800CF170(lbl_8055DD98);
    MEMDestroyFrmHeap(*(MEMiHeapHead **)(lbl_804075F0 + 1));
}

extern "C" void fn_800C68B0(void) {
    s32 r31;
    u8 *r30;
    r30 = (u8 *)lbl_8055DD98;
    if (*(void **)(r30 + 0x5C0) != NULL) {
        Update__Q36nw4hbm3snd18SoundArchivePlayerFv(*(void **)(r30 + 0x5C0));
    }
    r31 = 0;
    do {
        if (r31 < 4) {
            updateSound__Q210homebutton10ControllerFv(*(void **)(r30 + 0x254));
        }
        r31 += 1;
        r30 += 4;
    } while (r31 < 4);
}

extern "C" void *__ct__Q34nw4r3lyt8DrawInfoFv(void *);
extern "C" void *fn_800C6914(void *arg0, void *arg1) {
    u8 *self = (u8 *)arg0;
    s32 offset, i;
    M2C_FIELD(self, void **, 4) = arg1;
    M2C_FIELD(self, u32 *, 0x1E0) = 0;
    M2C_FIELD(self, u32 *, 0x1F8) = 0;
    __ct__Q34nw4r3lyt8DrawInfoFv(self + 0x200);
    M2C_FIELD(self, u32 *, 0x3FC) = 0;
    M2C_FIELD(self, s32 *, 0x400) = 0x1E;
    M2C_FIELD(self, u32 *, 0x404) = 0;
    M2C_FIELD(self, u8 *, 0x408) = 0;
    M2C_FIELD(self, u8 *, 0x409) = 0;
    M2C_FIELD(self, u8 *, 0x40A) = 0;
    M2C_FIELD(self, s32 *, 0x10) = 2;
    M2C_FIELD(self, s32 *, 0xAC) = -1;
    M2C_FIELD(self, s32 *, 0x14) = -1;
    M2C_FIELD(self, u32 *, 0x18) = 0;
    M2C_FIELD(self, u32 *, 0) = 0;
    M2C_FIELD(self, u32 *, 0x64) = 0;
    M2C_FIELD(self, u8 *, 0x86) = 0;
    M2C_FIELD(self, u32 *, 0x68) = 0;
    M2C_FIELD(self, u32 *, 0x6C) = 0;
    M2C_FIELD(self, u32 *, 0x70) = 0;
    M2C_FIELD(self, u32 *, 0x74) = 0;
    M2C_FIELD(self, u8 *, 0x87) = 0;
    M2C_FIELD(self, u8 *, 0x88) = 0;
    for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
        OSCreateAlarm((OSAlarm *)(self + offset + 0x410));
        OSCreateAlarm((OSAlarm *)(self + 0x4D0 + offset));
    }
    OSCreateAlarm((OSAlarm *)(self + 0x590));
    M2C_FIELD(self, u32 *, 0x5C0) = 0;
    M2C_FIELD(self, u32 *, 0x5C4) = 0;
    M2C_FIELD(self, u32 *, 0x5C8) = 0;
    M2C_FIELD(self, u32 *, 0x5CC) = 0;
    M2C_FIELD(self, u32 *, 0x5D0) = 0;
    M2C_FIELD(self, u32 *, 0x5D4) = 0;
    return arg0;
}

extern "C" void *fn_800D0F1C(void *, s32);
extern "C" s32 fn_800D67B8(s32, s32);
extern "C" void fn_800C6A1C(void *arg0, s32 arg1) {
    u8 *self = (u8 *)arg0;
    s32 i;
    if (arg0 != 0) {
        ((Freeable800C6A1C *)*(void **)(self + 0x1F4))->free(-1);
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0x1F4));
        ((Freeable800C6A1C *)*(void **)(self + 0x1E0))->free(-1);
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0x1E0));
        if (*(s32 *)((u8 *)*(void **)(self + 4) + 0x20) == 0) {
            for (i = 0; i < 4; i++) {
                void *p = *(void **)(self + 0x1E4 + i * 4);
                ((Freeable800C6A1C *)p)->free(-1);
                MEMFreeToAllocator(lbl_80559708, p);
            }
        }
        for (i = 0; i < *(s32 *)(self + 0xC); i++) {
            void *p = *(void **)(self + 0x268 + i * 4);
            ((Freeable800C6A1C *)p)->free(-1);
            MEMFreeToAllocator(lbl_80559708, p);
        }
        for (i = 0; i < 0xF; i++) {
            void *p = *(void **)(self + 0x3C0 + i * 4);
            ((Freeable800C6A1C *)p)->free(-1);
            MEMFreeToAllocator(lbl_80559708, p);
        }
        for (i = 0; i < 0x4A; i++) {
            void *p = *(void **)(self + 0x298 + i * 4);
            ((Freeable800C6A1C *)p)->free(-1);
            MEMFreeToAllocator(lbl_80559708, p);
        }
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0x1FC));
        ((Freeable28_800C6A1C *)*(void **)(self + 0x1F8))->free(-1);
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0x1F8));
        for (i = 0; i < 4; i++) {
            void *p = *(void **)(self + 0x254 + i * 4);
            fn_800D0F1C(p, -1);
            MEMFreeToAllocator(lbl_80559708, p);
        }
        ((Freeable800C6A1C *)((u8 *)*(void **)(self + 0x264) + 0x1F0))->free(-1);
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0x264));
        *(void **)(self + 0x264) = 0;
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0xA4));
        MEMFreeToAllocator(lbl_80559708, *(void **)(self + 0xA8));
        fn_800D67B8((s32)(self + 0x200), -1);
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
}

extern "C" void* __dt__Q36nw4hbm3lyt19ArcResourceAccessorFv(void* this_, s32 flag) {
    if (this_) {
        if ((u8*)this_ + 0x24 != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8*)this_ + 0x24, 0);
        }
        fn_800DCE10(this_, 0);
        if (flag > 0) {
            ((void (*)(void*))fn_80128668)(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_800C771C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800C775C(void *arg0, s32 arg1) {
    (*(u32 *)((u8 *)arg0 + 4)) = arg1;
}

extern "C" void fn_800CF280(void) {

}

void fn_800CF284(void) {

}

extern "C" void fn_800CF288(void) {

}

extern "C" void fn_800CF28C(void) {

}

extern "C" void fn_800CF290(void) {

}

extern "C" void fn_800CF294(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(const char **)((u8 *)arg0) = lbl_8031E770;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
}

extern "C" s32 fn_800CF2B0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void homebutton::GroupAnmController::do_calc() {
    class ComponentDispatch {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void apply(void *, s32, s32);
    };
    struct Node { Node *next; u32 pad; void *object; };
    struct List { u8 pad[0x10]; Node *head; };
    Node *node;
    Node *end;
    const char *message;
    const char *file;
    s32 active;
    if (*(s32 *)((u8 *)this + 0x14) == 1) {
        calc();
        active = 1;
        *(f32 *)((u8 *)*(void **)((u8 *)this + 0x24) + 0x10) = *(f32 *)((u8 *)this + 0xC);
    } else {
        active = 0;
    }
    List *list = *(List **)((u8 *)this + 0x20);
    node = list->head;
    end = (Node *)((u8 *)list + 0x10);
    while (node != end) {
        if (node == 0) {
            file = lbl_8031E764;
            message = lbl_8031E740;
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x23D, message);
        }
        void *object = node->object;
        ((ComponentDispatch *)object)->apply(*(void **)((u8 *)this + 0x24), active, 0);
        node = node->next;
    }
}

extern "C" void fn_800CF3B4(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 value;

    *(s32 *)((u8 *)arg0 + 0x18) = arg1;
    *(f32 *)((u8 *)arg0 + 4) = arg2;
    *(f32 *)((u8 *)arg0 + 8) = arg3;
    *(f32 *)((u8 *)arg0 + 0x10) = arg4;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
    if (arg1 == 1) {
        value = (f32)(f64)arg2;
    } else {
        value = (f32)(f64)arg3;
    }
    *(f32 *)((u8 *)arg0 + 0xC) = value;
}

extern "C" void fn_800CF3EC(void *arg0) {
    f32 val;
    if (*(s32 *)((u8 *)arg0 + 0x18) == 1)
        val = *(f32 *)((u8 *)arg0 + 4);
    else
        val = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 0xC) = val;
}

void homebutton::FrameController::calc() {
    if (m_state != 1) return;
    switch (m_dir) {
    case 0: {
        f32 v = m_value + m_speed;
        m_value = v;
        if (v >= m_min - lbl_80560E20) {
            m_value = m_min - lbl_80560E20;
            m_state = 0;
        }
        break;
    }
    case 1: {
        f32 v = m_value - m_speed;
        m_value = v;
        if (v <= m_max) {
            m_value = m_max;
            m_state = 0;
        }
        break;
    }
    case 2: {
        f32 v = m_value + m_speed;
        m_value = v;
        if (v >= m_min) {
            m_value = m_min - (m_min - m_max);
        }
        break;
    }
    case 3: {
        if (m_flag == 0) {
            f32 v = m_value + m_speed;
            m_value = v;
            if (v >= m_min - lbl_80560E20) {
                m_value = m_min - lbl_80560E20;
                m_flag = 1;
            }
        } else {
            f32 v = m_value - m_speed;
            m_value = v;
            if (v <= m_max) {
                m_value = m_max;
                m_flag = 0;
            }
        }
        break;
    }
    }
}

extern "C" u32 fn_800CF91C(void) { return 1; }

extern "C" u8 fn_800CF924(s32 arg0, s32 arg1) {
    return *(u8 *)((u8 *)(arg0 + arg1) + 4);
}

extern "C" void fn_800CF930(void) {

}

extern "C" void fn_800CF934(void *arg0) {
    struct V { virtual void f(); };
    void *obj = *(void **)((u8 *)arg0 + 4);
    if (obj) ((V *)obj)->f();
}

extern "C" s32 fn_800CF954(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x20); }

extern "C" void fn_800CF95C(s32 arg0, s32 arg1, s8 arg2) { *(s8 *)(arg0 + arg1 + 4) = arg2; }

extern "C" void fn_800CF968(void) {

}

extern "C" void fn_800CF96C(void) {

}

extern "C" void *List_GetNext__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListPCv(const void *, const void *);
extern "C" void List_Remove__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv(void *, void *);
extern "C" void *__dt__Q310homebutton3gui7ManagerFv(void *arg0, s32 arg1) {
    void *node;
    void *list;

    if (arg0 != 0) {
        *(void **)arg0 = (void *)lbl_8031E83C;
        list = (u8 *)arg0 + 8;
        node = List_GetNext__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListPCv(list, 0);
        while (node != 0) {
            List_Remove__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv(list, node);
            if (*(void **)((u8 *)arg0 + 0x14) != 0) {
                MEMFreeToAllocator((MEMAllocator *)*(void **)((u8 *)arg0 + 0x14), node);
            } else {
                ((void (*)(void *))fn_80128668)(node);
            }
            node = List_GetNext__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListPCv(list, 0);
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void homebutton::gui::Manager::init() {
    class ComponentDispatch {
    public:
        virtual void d0();
        virtual void init();
    };
    void *list = (u8 *)this + 8;
    s32 index = 0;
    void *entry;
    ComponentDispatch *component;

    do {
        entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs((u8 *)this + 8, (u16)index);
        component = *(ComponentDispatch **)((u8 *)entry + 4);
        component->init();
        index++;
        if (list == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    } while ((u32)index < *(u16 *)((u8 *)this + 0x10));
}

extern "C" void fn_800CFAC8(void *arg0) {
    u8 *p = (u8 *)arg0;
    p[0x18] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[0xA] = 0;
    p[0xB] = 0;
}

void homebutton::gui::Manager::addComponent(homebutton::gui::Component *arg1) {
    void *first = arg1->first();
    arg1->second(this);
    MEMAllocator *allocator = *(MEMAllocator **)((u8 *)this + 0x14);
    if (allocator != 0) {
        void *entry = MEMAllocFromAllocator(allocator, 0x10);
        if (entry != 0) {
            *(void **)entry = first;
            *((void **)entry + 1) = arg1;
        }
        List_Append__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv((u8 *)this + 8, entry);
    } else {
        void *entry = fn_80128520(0x10);
        if (entry != 0) {
            *(void **)entry = first;
            *((void **)entry + 1) = arg1;
        }
        List_Append__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv((u8 *)this + 8, entry);
    }
}

extern "C" void fn_800CFBB8(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x28) = arg1; }

extern "C" s32 fn_800CFBC0(void *arg0, s32 arg1) {
    void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs((char *)arg0 + 8, arg1 & 0xffff);
    return *(s32 *)((char *)entry + 4);
}

s32 homebutton::gui::Manager::update(s32 arg1, f32 farg0, f32 farg1, unsigned long arg2, unsigned long arg3, unsigned long arg4, void *arg5) {
    u32 sp14, sp8;
    s32 result = 0;
    void *last = 0;
    u16 index = 0;
    while (index < *(u16 *)((u8 *)this + 0x10)) {
        void *item = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs((u8 *)this + 8, index);
        void *obj = *(void **)((u8 *)item + 4);
        typedef s32 (*UpdateFn)(void *, s32, f32, f32, unsigned long, unsigned long, unsigned long, void *);
        typedef s32 (*CheckFn)(void *);
        if (((UpdateFn)(*(void ***)obj)[9])(obj, arg1, farg0, farg1, arg2, arg3, arg4, arg5)) {
            if (((CheckFn)(*(void ***)obj)[10])(obj)) last = obj;
            result = 1;
        }
        index++;
    }
    if (last) {
        if (arg3) {
            typedef void (*PrepareFn)(void *, unsigned long, u32 *);
            typedef s32 (*GetFn)(void *);
            typedef void (*ApplyFn)(void *, s32, s32, unsigned long);
            ((PrepareFn)(*(void ***)last)[7])(last, arg3, &sp14);
            ((ApplyFn)(*(void ***)this)[12])(this, ((GetFn)(*(void ***)last)[8])(last), 0, arg4);
        }
        if (arg5) {
            typedef void (*PrepareFn)(void *, void *, u32 *);
            typedef s32 (*GetFn)(void *);
            typedef void (*ApplyFn)(void *, s32, s32, unsigned long);
            ((PrepareFn)(*(void ***)last)[7])(last, arg5, &sp8);
            ((ApplyFn)(*(void ***)this)[12])(this, ((GetFn)(*(void ***)last)[8])(last), 5, arg4);
        }
    }
    return result;
}

extern "C" u8 fn_800CFDB4(void *arg0) { return *((u8 *)((u8 *)arg0 + 0x24)); }

extern "C" void fn_800CFDBC(void *arg0, s32 arg1, void *arg2) {
    if (arg1 & *(s32 *)((u8 *)arg0 + 0x1C)) {
        *(f32 *)((u8 *)arg0 + 0xC) = *(f32 *)arg2;
        *(f32 *)((u8 *)arg0 + 0x10) = *(f32 *)((u8 *)arg2 + 4);
        *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)((u8 *)arg2 + 8);
        *((u8 *)arg0 + 0x18) = 1;
    }
}

extern "C" void calc__Q310homebutton3gui7ManagerFv_800CFDEC(void *arg0) {
    class ComponentDispatch {
    public:
        virtual void d0();
        virtual void d1();
        virtual void calc();
    };
    void *list = (u8 *)arg0 + 8;

    for (s32 i = 0; (u32)i < (u32)*(u16 *)((u8 *)arg0 + 0x10); i++) {
        void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs((u8 *)arg0 + 8, (u16)i);
        ComponentDispatch *obj = *(ComponentDispatch **)((u8 *)entry + 4);
        obj->calc();
        if (list == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    }
}

extern "C" void draw__Q310homebutton3gui7ManagerFv_800CFE88(void *arg0) {
    class ComponentDispatch {
    public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void draw();
    };
    typedef void (*PanicFn)(const char *, s32, const char *, ...);
    void *list = (u8 *)arg0 + 8;
    s32 i = 0;

    do {
        void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs((u8 *)arg0 + 8, (u16)i);
        ComponentDispatch *obj = *(ComponentDispatch **)((u8 *)entry + 4);
        obj->draw();
        i++;
        if (list == 0)
            ((PanicFn)Panic__Q26nw4hbm2dbFPCciPCce)(lbl_805597D0, 0xCF, lbl_8031E938);
    } while ((u32)i < *(u16 *)((u8 *)arg0 + 0x10));
}

#pragma push
#pragma small_data on
extern "C" void setAllComponentTriggerTarget__Q310homebutton3gui7ManagerFb(void *arg0, bool arg1) {
    struct ManagerLayout {
        u8 pad0[8];
        void *list;
        u8 pad1[4];
        u16 count;
    };
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17();
        virtual void Set(bool);
    };
    ManagerLayout *self = (ManagerLayout *)arg0;
    void *list = &self->list;
    u32 i = 0;
    while (i < self->count) {
        void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(&self->list, (u16)i);
        void *obj = *(void **)((u8 *)entry + 4);
        ((Dummy *)obj)->Set(arg1);
        i++;
        if (list == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    }
}
#pragma pop
extern "C" s32 fn_800D010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800D014C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" u32 lbl_8055DDA0;
extern "C" void fn_800D018C(void *arg0, void *arg1) {
    class Dispatch {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void call(void *);
    };
    void *p = *(void **)((u8 *)arg1 + 0x10);
    lbl_8055DDA0 = 0;
    ((Dispatch *)arg0)->call((u8 *)p + 0x10);
}

extern "C" u8 lbl_8031E878[];
extern "C" u8 lbl_8031E780[];
extern "C" const char lbl_8031E8FC[];
extern "C" const char lbl_8031E8D8[];
extern "C" const char lbl_8031E92C[];
extern "C" const char lbl_8031E908[];
extern "C" u32 lbl_8055DE00;
extern "C" u32 lbl_8055DE10;
extern "C" void *fn_80128520(s32);
extern "C" void List_Append__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv(void *, void *);
extern "C" void fn_800D01AC(void *arg0, void *arg1) {
    struct Dispatch {
        virtual void d0();
        virtual void *d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6(void *);
        virtual void d7();
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual void d13();
        virtual void d14();
        virtual void d15();
        virtual void d16();
        virtual void d17();
        virtual void d18(s32);
        virtual void d19();
        virtual void d20();
        virtual void d21();
        virtual void d22(s32);
        virtual void d23();
        virtual void d24();
    };
    typedef void (*Method0)(void *);
    typedef void (*Method1)(void *, s32);
    typedef void (*MethodPtr)(void *, void *);
    u8 *end = (u8 *)arg1 + 4;
    u8 *node = *(u8 **)((u8 *)arg1 + 4);
    void *object;
    void *entry;
    u8 *member;
    void *child;
    s32 found;

    while (node != end) {
        if (*(void **)((u8 *)arg0 + 0x14) != 0) {
            object = MEMAllocFromAllocator((MEMAllocator *)*(void **)((u8 *)arg0 + 0x14), (u32)0x30);
            entry = MEMAllocFromAllocator((MEMAllocator *)*(void **)((u8 *)arg0 + 0x14), (u32)0x10);
            if (object != 0) {
                u32 objectIndex = lbl_8055DDA0;
                *(void **)object = (void *)lbl_8031E878;
                *((u8 *)object + 0x18) = 0;
                *(u32 *)((u8 *)object + 0x1C) = 0;
                *(u32 *)((u8 *)object + 0x20) = objectIndex;
                *((u8 *)object + 0x24) = 0;
                *(u32 *)((u8 *)object + 0x28) = 0;
                ((Dispatch *)object)->d1();
                *(void **)object = (void *)lbl_8031E780;
                *(u32 *)((u8 *)object + 0x2C) = 0;
            }
            if (entry != 0) {
                if (node == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
                }
                member = node - 4;
                if (member == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E92C, 0x193, lbl_8031E908);
                }
                *(u8 **)entry = member;
                *(void **)((u8 *)entry + 4) = object;
            }
        } else {
            object = fn_80128520(0x30);
            if (object != 0) {
                u32 objectIndex = lbl_8055DDA0;
                *(void **)object = (void *)lbl_8031E878;
                *((u8 *)object + 0x18) = 0;
                *(u32 *)((u8 *)object + 0x1C) = 0;
                *(u32 *)((u8 *)object + 0x20) = objectIndex;
                *((u8 *)object + 0x24) = 0;
                *(u32 *)((u8 *)object + 0x28) = 0;
                ((Method0)((void **)lbl_8031E878)[3])(object);
                *(void **)object = (void *)lbl_8031E780;
                *(u32 *)((u8 *)object + 0x2C) = 0;
            }
            entry = fn_80128520(0x10);
            if (entry != 0) {
                if (node == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
                }
                member = node - 4;
                if (member == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E92C, 0x193, lbl_8031E908);
                }
                *(u8 **)entry = member;
                *(void **)((u8 *)entry + 4) = object;
            }
        }
        List_Append__Q26nw4hbm2utFPQ36nw4hbm2ut4ListPv((u8 *)arg0 + 0x18, entry);
        lbl_8055DDA0 += 1;
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
        }
        member = node - 4;
        if (member == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E92C, 0x193, lbl_8031E908);
        }
        ((Dispatch *)object)->d22((s32)member);
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
        }
        member = node - 4;
        if (member == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E92C, 0x193, lbl_8031E908);
        }
        child = ((Dispatch *)member)->d1();
        found = 0;
        while (child != 0) {
            if (child == &lbl_8055DE00) {
                found = 1;
                break;
            }
            child = *(void **)child;
        }
        if (found != 0) {
            ((Dispatch *)object)->d18(1);
        }
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
        }
        member = node - 4;
        if (member == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E92C, 0x193, lbl_8031E908);
        }
        child = ((void *(*)(void *))(*(void ***)member)[3])(member);
        found = 0;
        while (child != 0) {
            if (child == &lbl_8055DE10) {
                found = 1;
                break;
            }
            child = *(void **)child;
        }
        if (found != 0) {
            ((Method1)(*(void ***)object)[20])(object, 1);
        }
        ((Dispatch *)arg0)->d6(object);
        if (node == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E8FC, 0x23D, lbl_8031E8D8);
        }
        ((Dispatch *)arg0)->d18((s32)(node + 0xC));
        node = *(u8 **)node;
    }
}

extern "C" void fn_800D0560(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C) = arg1;
}

#pragma push
#pragma small_data on
extern "C" s32 getPaneComponentByPane__Q310homebutton3gui11PaneManagerFPQ36nw4hbm3lyt4Pane(u8 *arg0, void *arg1) {
    register void *list = arg0 + 8;
    u32 i = 0;
    do {
        void *item = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(arg0 + 0x18, (u16)i);
        if (*(void **)item == arg1) {
            return *(s32 *)((u8 *)item + 4);
        }
        ++i;
        if (list == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
        }
    } while (i < *(u16 *)(arg0 + 0x10));
    return 0;
}

#pragma push
#pragma small_data on
void homebutton::gui::PaneManager::setAllBoundingBoxComponentTriggerTarget(bool arg0) {
    u8 *self = (u8 *)this;
    u32 index = 0;
    void *list = self + 8;
    void *typeId = &lbl_8055DDE0;
    struct ParentDispatch { virtual void v0(); virtual void *parent(); };
    struct TriggerDispatch {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void setTarget(bool);
    };
    goto loop_check;
loop_body:
    {
        void *item = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(self + 0x18, (u16)index);
        void *component = *(void **)item;
        void *node = ((ParentDispatch *)component)->parent();
        u32 found;
        goto node_check;
node_compare:
        if (node != typeId) goto node_parent;
        found = 1;
        goto type_done;
node_parent:
        node = *(void **)node;
node_check:
        if (node != 0) goto node_compare;
        found = 0;
type_done:
        component = found ? component : 0;
        if (component != 0) {
            ((TriggerDispatch *)*(void **)((u8 *)item + 4))->setTarget(arg0);
        }
    }
    ++index;
loop_check:
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    if (index < *(u16 *)(self + 0x10)) goto loop_body;
}
#pragma pop

#pragma pop
extern "C" void PSMTXConcatArray(const f32*, const f32*, f32*, u32);
extern "C" void PSMTXMultVec(const f32*, const f32*, f32*);
extern "C" void fn_800DB76C(f32*, void*, f32*);
extern "C" f32 lbl_80560E28;
extern "C" s32 contain__Q310homebutton3gui13PaneComponentFff(void *this_, f32 x, f32 y) {
    u8 *self = (u8 *)this_;
    void *pane = *(void **)(self + 0x28);
    if (pane == 0)
        return 0;

    struct Pane {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
        virtual s32 v15();
    };

    s32 n = ((Pane *)pane)->v15();
    if (n == 0)
        return 0;

    f32 mtx[12];
    f32 transformed[4];
    f32 res[4];
    f32 vec[3];

    ((void (*)(const f32 *, f32 *))PSMTXConcatArray)(
        (const f32 *)((u8 *)*(void **)(self + 0x2C) + 0x84), mtx);
    vec[0] = x;
    vec[1] = y;
    vec[2] = lbl_80560E28;
    PSMTXMultVec(mtx, vec, transformed);
    fn_800DB76C(res, *(void **)(self + 0x2C), (f32 *)n);

    if (res[0] <= transformed[0] &&
        transformed[0] <= res[2] &&
        res[3] <= transformed[1] &&
        transformed[1] <= res[1])
        return 1;
    return 0;
}

extern "C" s32 fn_800D0814(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x24); }

#pragma cplusplus on
extern "C" void draw__Q310homebutton3gui13PaneComponentFv(void *arg0) {
    f32 sp10, sp14, f31, f30;
    u8 color[4];
    void *pane = *(void **)((u8 *)arg0 + 0x2C);
    PaneDrawDispatch *dispatch = (PaneDrawDispatch *)*(void **)((u8 *)arg0 + 0x28);
    if (dispatch->isVisible() != 0) {
        color[0]=lbl_80560E2C; color[1]=lbl_80560E2D; color[2]=lbl_80560E2E; color[3]=lbl_80560E2F;
        sp10=*(f32 *)((u8 *)pane+0x4C); sp14=*(f32 *)((u8 *)pane+0x50);
        f31=*(f32 *)((u8 *)pane+0x90); f30=*(f32 *)((u8 *)pane+0xA0);
        if (*(u8 *)((u8 *)arg0+4)) { color[0]=0; color[2]=0xFF; }
        fn_800CF554(8,color,f31-sp10*lbl_80560E30,f30-sp14*lbl_80560E30,f31+sp10*lbl_80560E30,f30-sp14*lbl_80560E30,lbl_80560E28);
        fn_800CF554(8,color,f31+sp10*lbl_80560E30,f30-sp14*lbl_80560E30,f31+sp10*lbl_80560E30,f30+sp14*lbl_80560E30,lbl_80560E28);
        fn_800CF554(8,color,f31+sp10*lbl_80560E30,f30+sp14*lbl_80560E30,f31-sp10*lbl_80560E30,f30+sp14*lbl_80560E30,lbl_80560E28);
        fn_800CF554(8,color,f31-sp10*lbl_80560E30,f30+sp14*lbl_80560E30,f31-sp10*lbl_80560E30,f30-sp14*lbl_80560E30,lbl_80560E28);
    }
}
#pragma cplusplus reset

extern "C" s32 fn_800D0AA8(void *pane);
extern "C" s32 fn_800D0AB4(void *pane);
extern "C" s32 is_visible__Q210homebutton3guiFPQ34nw4r3lyt4Pane(void *pane) {
    void *child;
    if (!(((u8 *)pane)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)pane + 0xC);
    if (!child) return 1;
    if (!(((u8 *)child)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)child + 0xC);
    if (!child) return 1;
    if (!(((u8 *)child)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)child + 0xC);
    if (!child) return 1;
    if (!(((u8 *)child)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)child + 0xC);
    if (!child) return 1;
    if (!fn_800D0AA8(child)) return 0;
    if (fn_800D0AB4(child) == 0) return 1;
    return is_visible__Q210homebutton3guiFPQ34nw4r3lyt4Pane((void *)fn_800D0AB4(child));
}

extern "C" s32 fn_800D0AA8(void *arg0) { return (*(u8 *)((u8 *)arg0 + 0xCF)) & 1; }

extern "C" s32 fn_800D0AB4(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" s32 is_visible__Q210homebutton3guiFPQ34nw4r3lyt4Pane(void *pane);
extern "C" s32 is_visible__Q210homebutton3guiFPQ34nw4lyt4Pane(void *);
extern "C" s32 isVisible__Q310homebutton3gui13PaneComponentFv(void *this_) {
    void *pane = *(void **)((u8 *)this_ + 0x2C);
    void *child;
    if (!(((u8 *)pane)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)pane + 0xC);
    if (!child) return 1;
    if (!(((u8 *)child)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)child + 0xC);
    if (!child) return 1;
    if (!(((u8 *)child)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)child + 0xC);
    if (!child) return 1;
    if (!(((u8 *)child)[0xCF] & 1)) return 0;
    child = *(void **)((u8 *)child + 0xC);
    if (!child) return 1;
    if (!fn_800D0AA8(child)) return 0;
    if (fn_800D0AB4(child) == 0)
        return 1;
    return is_visible__Q210homebutton3guiFPQ34nw4lyt4Pane((void *)fn_800D0AB4(child));
}

extern "C" s32 fn_800D0B90(void) { return 0; }

extern "C" void fn_800D0B98(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x1C) = arg1; }

extern "C" void fn_800D0BA0(void) {

}

extern "C" void fn_800D0BA4(void *arg0, void *arg1) {
    class Dispatch {
    public:
        virtual ~Dispatch();
        virtual void call(void *);
    };
    *(void **)((u8 *)arg0 + 4) = arg1;
    if (arg1 != 0) {
        ((Dispatch *)arg1)->call(arg0);
    }
}

extern "C" s32 fn_800D0BD0(void) { return 0; }

extern "C" void wpadExtensionCallback__Q210homebutton10ControllerFll(s32, s32);
extern "C" s32 WPADSetSamplingCallback_800603D0(void *);
void wpadConnectCallback__Q210homebutton10ControllerFll(s32 chan, s32 status) {
 void *entry;
 void (*callback)(s32,s32);
 if(status==0) {
  entry=lbl_80407780[chan];
  if(*(u8*)((u8*)entry+0x40)==0) {
   *(void**)((u8*)entry+0x2C)=(void*)WPADSetSamplingCallback_800603D0((void*)wpadExtensionCallback__Q210homebutton10ControllerFll);
   *((u8*)entry+0x40)=1;
  }
  fn_80060CC0((void*)chan,0,0);
 } else {
  if(status<0) {
   if(status==-1) {
    entry=lbl_80407780[chan];
    WPADSetSamplingCallback_800603D0(*(void**)((u8*)entry+0x2C));
    *(s32*)((u8*)entry+0x2C)=0;
    *((u8*)entry+0x40)=0; *((u8*)entry+0x42)=0; *((u8*)entry+0x43)=0;
   }
  }
 }
 entry=lbl_80407780[chan];
 callback=*(void (**)(s32,s32))((u8*)entry+0x28);
 if(callback) callback(chan,status);
}

extern "C" u8 lbl_804076C0[];
extern "C" void soundOnCallback__Q210homebutton10ControllerFP7OSAlarmP9OSContext(OSAlarm *, OSContext *);
extern "C" void wpadExtensionCallback__Q210homebutton10ControllerFll(s32 arg0, s32 arg1) {
    void *entry;
    void *sound;
    OSAlarm *alarm;
    void (*callback)(s32, s32);

    switch (arg1) {
    case 0xFF:
        entry = lbl_80407780[arg0];
        sound = *(void **)entry;
        if (fn_80060C7C(sound) != 0) {
            fn_80060CC0(sound, 2, 0);
            alarm = (OSAlarm *)((u8 *)lbl_804076C0 + (s32)sound * 0x30);
            OSSetAlarmUserData(alarm, sound);
            OSCancelAlarm(alarm);
            {
                u32 ticks = *(volatile u32 *)0x800000F8;
                u32 delay = (((ticks >> 2) / 1000U) * 1000U);
                ((void (*)(OSAlarm *, u32, u32, u32, OSAlarmHandler))OSSetAlarm)(
                    alarm, 0x10624DD3, 0, delay,
                    soundOnCallback__Q210homebutton10ControllerFP7OSAlarmP9OSContext);
            }
            *((u8 *)entry + 0x41) = 1;
        }
        break;
    default:
        break;
    }

    entry = lbl_80407780[arg0];
    callback = *(void (**)(s32, s32))((u8 *)entry + 0x2C);
    if (callback != 0) callback(arg0, arg1);
}

extern "C" void soundOnCallback__Q210homebutton10ControllerFP7OSAlarmP9OSContext(OSAlarm *alarm, OSContext *) {
    void *entry;
    void *sound;
    entry = lbl_80407780[(s32)OSGetAlarmUserData(alarm)];
    sound = *(void **)entry;
    if (fn_80060C7C(sound) != 0) fn_80060CC0(sound, 3, 0);
    *((u8 *)entry + 0x41) = 0;
}

extern "C" void *fn_800D0E68(void *arg0, s32 arg1, s32 arg2) {
    u8 *base = lbl_80407600;
    s32 temp_r30;
    s32 zero = 0;

    *(s32 *)((u8 *)arg0 + 0x20) = zero;
    *(s32 *)arg0 = arg1;
    *((u8 *)arg0 + 0x1C) = zero;
    *(f32 *)((u8 *)arg0 + 4) = lbl_80560E38;
    *(s32 *)((u8 *)arg0 + 0x24) = arg2;
    *(s32 *)((u8 *)arg0 + 0x28) = zero;
    *(s32 *)((u8 *)arg0 + 0x2C) = zero;
    *((u8 *)arg0 + 0x40) = zero;
    *((u8 *)arg0 + 0x41) = zero;
    if (arg1 < 4) {
        temp_r30 = arg1 * 0x30;
        lbl_8055DDA8[arg1] = zero;
        OSCreateAlarm((OSAlarm *)(base + temp_r30));
        {
            u8 *secondBase = base + 0xC0;
            OSCreateAlarm((OSAlarm *)(secondBase + temp_r30));
        }
        {
            void **slots = (void **)(base + 0x180);
            slots[arg1] = arg0;
        }
    }
    return arg0;
}

extern "C" void *fn_800D0F1C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 soundHandle = (s32)arg0 + 0x20;
        if (soundHandle != 0) {
            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)((void *)soundHandle);
        }
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}

void homebutton::Controller::clearCallback() {
    WPADSetSamplingCallback(*(s32 *)this, *(void **)((u8 *)this + 0x28));
    *(s32 *)((u8 *)this + 0x28) = 0;
    ((s32 (*)(s32, void *))WPADSetSamplingCallback_800603D0)(*(s32 *)this, *(void **)((u8 *)this + 0x2C));
    *(s32 *)((u8 *)this + 0x2C) = 0;
}

extern "C" void fn_800D1054(void *arg0, void *arg1, s32 arg2) {
    s32 temp_r0, temp_r4, temp_r5, temp_r6_2;
    void *temp_r6, *temp_r7;
    f32 f1, f0;
    temp_r6 = M2C_FIELD(arg1, void **, 0);
    if (temp_r6 == 0) return;
    if (arg2 != 0) {
        if ((u32)M2C_FIELD(temp_r6, u32 *, 0x5C) == 2 &&
            (u32)M2C_FIELD(arg1, u32 *, 0xC) == 2) {
            f1 = M2C_FIELD(arg1, f32 *, 4);
            f0 = M2C_FIELD(arg1, f32 *, 8);
            M2C_FIELD(arg0, f32 *, 8) = f1;
            M2C_FIELD(arg0, f32 *, 0xC) = f0;
        } else {
            M2C_FIELD(arg0, f32 *, 8) = M2C_FIELD(temp_r6, f32 *, 0x20);
            temp_r5 = (s32)M2C_FIELD(arg1, s32 *, 0);
            M2C_FIELD(arg0, f32 *, 0xC) = M2C_FIELD((void *)temp_r5, f32 *, 0x24);
        }
    }
    temp_r7 = M2C_FIELD(arg1, void **, 0);
    M2C_FIELD(arg0, s32 *, 0x10) = M2C_FIELD(temp_r7, s32 *, 4);
    temp_r6_2 = M2C_FIELD(temp_r7, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_r6_2;
    M2C_FIELD(arg0, s32 *, 0x18) = M2C_FIELD(temp_r7, s32 *, 8);
    if ((u32)M2C_FIELD(temp_r7, u32 *, 0x5C) == 2) {
        temp_r0 = M2C_FIELD(temp_r7, s32 *, 0x60);
        temp_r4 = M2C_FIELD(temp_r7, s32 *, 0x64);
        temp_r5 = M2C_FIELD(temp_r7, s32 *, 0x68);
        if (temp_r0 & 0x10) M2C_FIELD(arg0, s32 *, 0x14) = temp_r6_2 | 0x800;
        if (temp_r4 & 0x10) M2C_FIELD(arg0, s32 *, 0x10) |= 0x800;
        if (temp_r5 & 0x10) M2C_FIELD(arg0, s32 *, 0x18) |= 0x800;
        if (temp_r0 & 0x400) M2C_FIELD(arg0, s32 *, 0x14) |= 0x10;
        if (temp_r4 & 0x400) M2C_FIELD(arg0, s32 *, 0x10) |= 0x10;
        if (temp_r5 & 0x400) M2C_FIELD(arg0, s32 *, 0x18) |= 0x10;
        if (temp_r0 & 0x1000) M2C_FIELD(arg0, s32 *, 0x14) |= 0x1000;
        if (temp_r4 & 0x1000) M2C_FIELD(arg0, s32 *, 0x10) |= 0x1000;
        if (temp_r5 & 0x1000) M2C_FIELD(arg0, s32 *, 0x18) |= 0x1000;
        if (temp_r0 & 0x800) M2C_FIELD(arg0, s32 *, 0x14) |= 0x8000;
        if (temp_r4 & 0x800) M2C_FIELD(arg0, s32 *, 0x10) |= 0x8000;
        if (temp_r5 & 0x800) M2C_FIELD(arg0, s32 *, 0x18) |= 0x8000;
    }
}

extern "C" void fn_800D11CC(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
}

extern "C" void fn_800D11E0(void* arg0) {
    f32 value = lbl_80560E3C;
    *(f32*)((u8*)arg0 + 8) = value;
    *(f32*)((u8*)arg0 + 0xC) = value;
}

extern "C" void Connect__Q210homebutton9RemoteSpkFl(void *, s32);
extern "C" s32 fn_800D51F4(long, long, long, long, long, long);
#pragma opt_tail_call on
extern "C" void fn_800D11F0(void *arg0) {
    Connect__Q210homebutton9RemoteSpkFl(*(void **)((char *)arg0 + 0x24), *(s32 *)arg0);
}
extern "C" void fn_800D1200(void) {

}

extern "C" void fn_800D1204(void* arg0, f32 arg1) { *(f32*)((u8*)arg0 + 4) = arg1; }

extern "C" void Play__Q210homebutton9RemoteSpkFliSc(void *, long, int, signed char);
extern "C" OSTime OSGetTime(void);
extern "C" s32 fn_80060C7C(void *);
void fn_800D120C(void *arg0) {
    if (((u8 *)arg0)[0x41] == 0) {
        f32 value = *(f32 *)((u8 *)arg0 + 4);
        Play__Q210homebutton9RemoteSpkFliSc(*(void **)((u8 *)arg0 + 0x24),
            *(s32 *)arg0, (int)(lbl_80560E40 * value), (signed char)(lbl_80560E40 * value));
        if (fn_80060C7C(*(void **)arg0) != 0) {
            if (((u8 *)arg0)[0x42] == 0) {
                OSTime time = OSGetTime();
                *(u32 *)((u8 *)arg0 + 0x34) = (u32)time;
                *(u32 *)((u8 *)arg0 + 0x30) = (u32)(time >> 32);
            }
            ((u8 *)arg0)[0x42] = 1;
            ((u8 *)arg0)[0x43] = 0;
        }
    }
}

extern "C" s32 fn_800D1E78(void *, s32, s32);
#pragma dont_inline
int homebutton::Controller::isPlayingSoundId(int arg0) const {
    if (fn_800D1E5C(m_soundPlayer, m_soundId) == 0) {
        return 0;
    }
    return fn_800D1E78(m_soundPlayer, m_soundId, arg0);
}
extern "C" void fn_800D1300(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x42) = 0;
    *(u8 *)((u8 *)arg0 + 0x43) = 0;
}

extern "C" void fn_800D1548(void *arg0) {
    fn_800D1EA8(*(void **)((char *)arg0 + 0x24), *(s32 *)arg0);
}

extern "C" void fn_800D1558(void) {

}

extern "C" s32 WPADControlMotor(s32, s32);
extern "C" void fn_800D155C(void *arg0) {
    if (*(s32 *)arg0 >= 4) return;
    if (fn_800D1E5C(*(void **)((u8 *)arg0 + 0x24), *(s32 *)arg0) != 0) return;
    *(u8 *)((u8 *)arg0 + 0x1C) = 1;
    WPADControlMotor(*(s32 *)arg0, 1);
}

#pragma dont_inline on
extern "C" void fn_800D15B4(void *arg0) {
    s32 channel = *(s32 *)arg0;
    if (channel >= 4) return;
    if (*(u8 *)((u8 *)arg0 + 0x1C) == 0) return;
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
    WPADControlMotor(channel, 0);
}
#pragma dont_inline reset

extern "C" s32 getInfoAsync__Q210homebutton10ControllerFP8WPADInfo(void* this_ptr, void* arg1) {
    if (*(s32*)this_ptr >= 4) return -2;
    if (fn_800D1E5C(*(s32**)((u8*)this_ptr + 0x24), *(s32*)this_ptr) != 0 ||
        *(u8*)((u8*)this_ptr + 0x1c) != 0) {
        return -2;
    }
    return fn_800604E8(*(s32*)this_ptr, (s32)arg1, (void*)&fn_800D1668);
}

extern "C" void fn_800D1668(s32 arg0, s32 arg1) {
    if (arg1 == 0 && arg0 < 4) {
        lbl_8055DDA8[arg0] = 1;
    }
}

extern "C" u8 fn_800D1688(s32 *arg0) {
    if (*arg0 >= 4) {
        return 0;
    }
    return lbl_8055DDA8[*arg0];
}

extern "C" void fn_800D16A8(s32 *arg0) {
    if (*arg0 < 4) {
        lbl_8055DDA8[*arg0] = 0;
    }
}

extern "C" void fn_800D16C4() {
    if (lbl_8055DDB0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E960, 0x3F, lbl_8031E974);
    }
    s32 neg1 = -1;
    s32 magic = 0x6666;
    s32 zero = 0;
    u8* p = (u8*)lbl_8055DDB0;
    s32 i = 0;
    do {
        if (*(u32*)(p + 0x50) != 0 && fn_80060C7C((void*)i) != 0) {
            s32 lr = OSDisableInterrupts();
            if (WPADCanSendStreamData(i) != 0) {
                u16 buf[0x28];
                u32 enc;
                s32 count = 0x28;
                u32 avail = *(u32*)(p + 0x54) >> 1;
                const s16* src = (const s16*)*(u32*)(p + 0x50);
                s8 scale = (s8)p[0x5d];
                u16* dst = buf;
                if (avail <= 0x28) {
                    count = (s32)avail;
                }
                if (count > 0) {
                    s32 q = count >> 2;
                    if (q != 0) {
                        do {
                            s32 v;
                            v = (src[0] * scale) / 10;
                            dst[0] = (u16)v;
                            v = (src[1] * scale) / 10;
                            dst[1] = (u16)v;
                            v = (src[2] * scale) / 10;
                            dst[2] = (u16)v;
                            v = (src[3] * scale) / 10;
                            dst[3] = (u16)v;
                            src += 4;
                            dst += 4;
                        } while (--q != 0);
                        s32 rem = count & 3;
                        if (rem != 0) {
                            do {
                                *dst = (u16)((*src * scale) / 10);
                                src += 1;
                                dst += 1;
                            } while (--rem != 0);
                        }
                    }
                }
                if (avail <= 0x28) {
                    s32 pad = 0x28 - (s32)avail;
                    if (pad > 0) {
                        s32 q = pad >> 3;
                        if (q != 0) {
                            do {
                                dst[0] = zero; dst[1] = zero; dst[2] = zero; dst[3] = zero;
                                dst[4] = zero; dst[5] = zero; dst[6] = zero; dst[7] = zero;
                                dst += 8;
                            } while (--q != 0);
                            s32 rem = pad & 7;
                            if (rem != 0) {
                                do {
                                    *dst = zero;
                                    dst += 1;
                                } while (--rem != 0);
                            }
                        }
                    }
                }
                WENCGetEncodeData(p + 0x30, p[0x5c] == 0, (const s16*)buf, 0x28, &enc);
                fn_80062278(i, &enc, 0x14);
                p[0x5c] = 0;
                p[0x5e] = 0;
                *(u32*)(p + 0x50) += 0x50;
                s32 v = (s32)*(u32*)(p + 0x54) - 0x50;
                *(u32*)(p + 0x54) = v;
                if (v <= 0) {
                    *(s32*)(p + 0x58) = neg1;
                    *(u32*)(p + 0x50) = zero;
                }
            } else {
                s32 c = (s32)p[0x5e] + 1;
                p[0x5e] = (u8)c;
                if ((s8)(c & 0xff) > 0x12c) {
                    *(u32*)(p + 0x50) = zero;
                }
            }
            OSRestoreInterrupts(lr);
        }
        i += 1;
        p += 0x68;
    } while (i < 4);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_800D1948(void *arg0, s32 arg1) {
    void *r26 = arg0;
    *(u32 *)((u8 *)r26 + 0x1F0) = (u32)&lbl_8031E9C0;
    lbl_8055DDB0 = (u32)r26;
    if (arg1 != 0) {
        BOOL result = ARCInitHandle((void *)arg1, (ARCHandle *)((u8 *)r26 + 0x1D0));
        s32 neg = -result;
        s32 or_result = neg | result;
        ((u8 *)r26)[0x1EC] = (u8)((u32)or_result >> 31);
    } else {
        ((u8 *)r26)[0x1EC] = 0;
    }
    void *r28 = r26;
    s32 r27 = 0;
    s32 r29 = 0;
    s32 r30 = -1;
    u8 r31 = 1;
    do {
        OSCreateAlarm((OSAlarm *)r28);
        *(u32 *)((u8 *)r28 + 0x50) = r29;
        r27++;
        *(u32 *)((u8 *)r28 + 0x58) = r30;
        ((u8 *)r28)[0x5C] = r31;
        ((u8 *)r28)[0x62] = r31;
        r28 = (u8 *)r28 + 0x68;
    } while (r27 < 4);
    return r26;
}
#pragma pop
extern "C" void *fn_800D19F8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(u32 *)((u8 *)arg0 + 0x1F0) = (u32)&lbl_8031E9C0;
        lbl_8055DDB0 = 0;
        ((u8 *)arg0)[0x1EC] = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern "C" void Start__Q210homebutton9RemoteSpkFv(void *this_ptr) {
    register u8 *self = (u8 *)this_ptr;
    if (self[0x1EC] != 0) {
        OSCreateAlarm((OSAlarm *)(self + 0x1A0));
        OSTime time = OSGetTime();
        u32 ticks = *(volatile u32 *)0x800000F8;
        u32 q = (ticks >> 2) / 125000U;
        u32 period = q * 0x0065B9AB;
        u32 interval = period / 8000U;
        ((void (*)(void *, u32, u32, u32, u32, u32, void *))OSSetPeriodicAlarm)(
            self + 0x1A0, q, (u32)(time >> 32), (u32)time, 0, interval, (void *)&fn_800D16C4);
    }
}

extern "C" void fn_800D1AE4(OSAlarm *arg0) {
    OSCancelAlarm((OSAlarm *)((u8 *)arg0 + 0x1A0));
}

extern void* OSGetAlarmUserData(void);
extern "C" void fn_800D1AEC(void) {
    void *r3 = OSGetAlarmUserData();
    fn_80060CC0(r3, 1, (u32)&fn_800D1B1C);
}

extern "C" void fn_800D1B1C(s32 index, s32 mode) {
    u8 *base = (u8 *)lbl_8055DDB0;

    if (base == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E960, 0xA3, lbl_8031E9A0);
    }

    if (mode == -1)
        goto done;
    if (mode >= -1)
        goto play;
    if (mode >= -2)
        goto rearm;
    goto done;

play:
    if (mode >= 1)
        goto done;
    {
        s32 one = 1;
        u8 *entry = base + index * 0x68;
        entry[0x5C] = one;
        ((u32 (*)(s32, u32, void *, u32))fn_80060CC0)(
            index, 4, (void *)fn_800D1C48, one);
    }
    goto done;

rearm:
    {
        void *alarm = base + index * 0x68;
        OSSetAlarmUserData((OSAlarm *)alarm, (void *)index);
        OSCancelAlarm((OSAlarm *)alarm);
        u32 ticks = *(volatile u32 *)0x800000F8;
        u32 delay = ((ticks >> 2) / 1000U) * 0x32U;
        ((void (*)(OSAlarm *, u32, u32, u32, OSAlarmHandler))OSSetAlarm)(
            (OSAlarm *)alarm, 0x10624DD3, 0, delay, (OSAlarmHandler)fn_800D1AEC);
    }

done:
    return;
}

extern "C" void fn_800D1C18(void) {
    void *data = ((void *(*)())OSGetAlarmUserData)();
    fn_80060CC0(data, 4, (u32)&fn_800D1C48);
}

extern "C" void fn_800D1C48(s32 index, s32 mode) {
    u8 *base = (u8 *)lbl_8055DDB0;

    if (base == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031E960, 0xDE, lbl_8031E9A0);
    }

    switch (mode) {
    case 0: {
        u8 *entry = base + index * 0x68;
        entry[0x62] = 1;
        break;
    }
    case -1: {
        u8 *entry = base + index * 0x68;
        entry[0x62] = 0;
        break;
    }
    case -2: {
        void *alarm = base + index * 0x68;
        OSSetAlarmUserData((OSAlarm *)alarm, (void *)index);
        OSCancelAlarm((OSAlarm *)alarm);
        u32 ticks = *(volatile u32 *)0x800000F8;
        u32 delay = ((ticks >> 2) / 1000U) * 0x32U;
        ((void (*)(OSAlarm *, u32, u32, u32, OSAlarmHandler))OSSetAlarm)(
            (OSAlarm *)alarm, 0x10624DD3, 0, delay, (OSAlarmHandler)fn_800D1C18);
        break;
    }
    default:
        break;
    }
}

extern "C" void Connect__Q210homebutton9RemoteSpkFl(void *this_ptr, s32 arg1) {
    if (((u8 *)this_ptr)[0x1EC] != 0) {
        fn_80060CC0((void *)arg1, 1, (u32)&fn_800D1B1C);
        void *ptr = (u8 *)this_ptr + (arg1 * 0x68) + 0x30;
        memset(ptr, 0, 0x20);
        ((u8 *)this_ptr)[(arg1 * 0x68) + 0x5C] = 1;
        ((u8 *)this_ptr)[(arg1 * 0x68) + 0x62] = 0;
    }
}

extern "C" s32 fn_800D1E5C(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)((u8 *)arg0 + arg1 * 0x68);
    s32 val = ptr[0x50 / 4];
    s32 neg = -val;
    return (s32)((u32)(neg | val) >> 31);
}

extern "C" s32 fn_800D1E78(void *arg0, s32 arg1, s32 arg2) {
    void *ptr = (u8 *)arg0 + arg1 * 0x68;
    if (((s32 *)ptr)[0x50 / 4] != 0 && arg2 == ((s32 *)ptr)[0x58 / 4]) {
        return 1;
    }
    return 0;
}

extern "C" s32 fn_800D1EA8(void *arg0, s32 arg1) {
    u8 val = ((u8 *)((u8 *)arg0 + arg1 * 0x68))[0x62];
    s32 result = (s32)val;
    s32 neg = -result;
    return (s32)((u32)(neg | result) >> 31);
}

extern void *lbl_8055DDBC;
extern "C" void __VprintfThunk(const char *, va_list);
extern "C" void Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct(void *, void *, const char *, void *);
extern "C" void fn_800D1EC4(const char *msg, ...) {
    va_list vlist;
    va_start(vlist, msg);
    void *console = lbl_8055DDBC;
    if (console != 0) {
        Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct((void *)3, console, msg, vlist);
    } else {
        __VprintfThunk(msg, vlist);
    }
    va_end(vlist);
}

struct Fn800D1F7CStringTable { const char header[0x28]; const char summary[0x20]; const char node[1]; };
extern "C" const char lbl_8031E9D0[];
extern "C" { DECL_SECTION(".sdata") extern const char lbl_805597D8[]; }
extern "C" { DECL_SECTION(".sdata") extern const char lbl_805597DC[]; }
extern "C" void fn_800D1EC4(const char *, ...);
extern "C" s32 fn_800D3824(void);
extern "C" s32 fn_800D40B4(s32, s32, s32, void *, void *);
extern "C" void fn_800D1F7C(s32 *arg0, s32 arg1) {
    /* Fix note: test the sentinel through its pointer value; the remaining mismatch is immediate selection. */
    u8 scratch[0x104];
    const Fn800D1F7CStringTable *messages =
        (const Fn800D1F7CStringTable *)lbl_8031E9D0;
    u32 temp_r28;
    u32 var_r27;
    s32 var_r0;

    fn_800D1EC4(messages->header);
    fn_800D1EC4(messages->summary);
    var_r27 = 0;
loop_1:
    if (arg0 == 0)
        goto done;
    if (arg0 == (s32 *)0xFFFEFFFF)
        goto done;
    if (((u32)arg0 & 0x80000000) == 0)
        goto done;

    fn_800D1EC4(messages->node, arg0,
                *(s32 *)arg0, *((s32 *)arg0 + 1));
    temp_r28 = (u32)*((s32 *)arg0 + 1);
    if (fn_800D3824() == 0) {
        var_r0 = 0;
    } else if (temp_r28 < 0x80000000 || temp_r28 > 0x82FFFFFF) {
        var_r0 = 0;
    } else {
        typedef s32 (*CheckFn)(s32, s32, s32);
        if (((CheckFn)fn_800D40B4)(temp_r28, (s32)scratch, 0x104) != 0) {
            fn_800D1EC4(lbl_805597D8, scratch);
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
    }
    if (var_r0 == 0)
        fn_800D1EC4(lbl_805597DC);
    var_r27 += 1;
    arg0 = (s32 *)*(s32 *)arg0;
    if (var_r27 < 0x10)
        goto loop_1;
done:
    return;
}

extern "C" s32 fn_800D2DD4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma opt_tail_call on
extern s32 lbl_8055DDD4;
extern void* lbl_8055DDD4_ptr;
extern void* lbl_8055DDBC;
extern "C" s32 fn_800D3F94(void*, s32, s32, s32);
extern u32 lbl_80407BD8[];
extern s32 lbl_8055DDC8;
#pragma opt_tail_call on
void DCStoreRange(const void *, u32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" const char lbl_8031EA80[];
extern "C" const char lbl_8031EA90[];
extern "C" const char lbl_8031EA40[];
extern "C" const char lbl_8031EA4C[];
extern "C" void fn_800D2E3C(s32, s32, s32, s32);
extern "C" void fn_800D24D4(void*, s32);
extern void* lbl_8055DDBC;
extern "C" void fn_800D2098(void*);
extern "C" void __VprintfThunk(const char*, va_list);
extern "C" void Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct(void*, void*, const char*, void*);
extern "C" s32 fn_80116A30(void*);
extern "C" void fn_800D1C48(s32, s32);
extern "C" s32 fn_80116A38(void*);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void fn_800D1B1C(s32, s32);

struct PanicStruct {
    const char *msg;
    const char *file;
    s32 line;
    s32 r7;
    s32 r8;
    s32 r9;
    s32 r10;
    s32 field_68;
    void *field_6C;
    void *field_70;
};

extern "C" s32 fn_800D2E14(void) {
    s32 _r3 = 0;
    if (lbl_8055DDC8 != 0) {
        if (lbl_80407BD8[0] != 0) {
            _r3 = 1;
        }
    }
    return _r3;
}

void fn_800D2E3C(s32 x, s32 y, s32 width, s32 height) {
    s32 right, bottom, startX, startY, row, col;
    u16 *dest;
    u16 screenWidth;
    u16 screenHeight;
    u16 stride;
    if (lbl_80407BD8[0] == 0)
        return;
    screenWidth = *(u16 *)((u8 *)lbl_80407BD8 + 8);
    if (screenWidth == 0x190) {
        x *= 2;
        width *= 2;
    }
    right = x + width;
    startX = x < 0 ? x : 0;
    if (right <= screenWidth)
        screenWidth = right;
    screenHeight = *(u16 *)((u8 *)lbl_80407BD8 + 0xA);
    width = screenWidth - startX;
    if (screenHeight == 0x12C) {
        y *= 2;
        height *= 2;
    }
    bottom = y + height;
    startY = y < 0 ? y : 0;
    if (bottom <= screenHeight)
        screenHeight = bottom;
    height = screenHeight - startY;
    stride = *(u16 *)((u8 *)lbl_80407BD8 + 0xC);
    dest = (u16 *)(lbl_80407BD8[0] + stride * startY * 2 + startX * 2);
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++)
            dest[col] = 0x1080;
        dest += stride;
    }
}

extern "C" void fn_800D2FC8(void) {
    DCStoreRange((void *)lbl_80407BD8[0], lbl_80407BD8[1]);
}

extern "C" const char lbl_8031EBA0[];
extern "C" const char lbl_8031EBB4[];
extern "C" void fn_800D30E8(s32, s32, const char *, s32, s32);
extern "C" void fn_800D2FDC(void *arg0, void *arg1, s32 arg2, const char *fmt, ...) {
    va_list vlist;
    char buffer[0x100];
    u32 enabled = lbl_80407BD8[0];

    if (enabled == 0) {
        goto done;
    }

    va_start(vlist, fmt);
    if (enabled != 0) {
        goto format;
    }
    Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EBA0, 0x287, lbl_8031EBB4);

format:
    if (vsnprintf(buffer, sizeof(buffer), fmt, vlist) <= 0) {
        goto done;
    }

    fn_800D30E8((s32)arg0, (s32)arg1, buffer, (s32)arg2, 0);

done:
    va_end(vlist);
}

extern "C" const char lbl_8031EBF4[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern "C" void fn_800D2E3C(s32, s32, s32, s32);
extern "C" const char *fn_800D3260(s32, s32, const char *, s32);
extern "C" char *strchr(const char *, int);
extern "C" void fn_800D30E8(s32 x, s32 y, const char *str, s32 arg3, s32 arg4) {
    s32 startX = x;
    u16 width = *(u16 *)((u8 *)lbl_80407BD8 + 8);
    s32 scaleX = width < 400 ? 1 : 2;
    s32 maxCols = width / scaleX;

    while ((s8)*str != 0) {
        if (arg4 != 0) {
            const char *p = str;
            s32 len = 0;
            if (str == NULL) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EBA0, 0x132, lbl_8031EBF4);
            }
            for (;;) {
                s8 c = *p++;
                if (c == 0 || c == '\n') {
                    break;
                }
                if (c == '\t') {
                    len = (len + 4) & ~3;
                } else {
                    len++;
                }
            }
            fn_800D2E3C(x - 6, y - 3, (len + 2) * 6, 13);
        }

        const char *next = fn_800D3260(x, y, str, (maxCols - x) / 6);
        s8 c = *next;
        str = next;
        y += 10;
        if (c == '\n') {
            x = startX;
            str++;
        } else if (c != 0) {
            str++;
            if (arg3 == 0) {
                const char *newline = strchr(str, '\n');
                if (newline == NULL) {
                    break;
                }
                x = startX;
                str = newline + 1;
            } else {
                x = 0;
            }
        }
    }
}

extern "C" u8 lbl_802F47D8[];
extern "C" void fn_800D337C(s32,s32,s32);
extern "C" const char *fn_800D3260(s32 arg0, s32 arg1, const char *arg2, s32 arg3) {
    s32 var_r26=arg0;
    s32 var_r27=arg1;
    const char *var_r28=arg2;
    s32 var_r29=arg3;
    s32 var_r30=0;
    s32 temp;
    const void *base=lbl_8031EBA0;
    if (!var_r28) Panic__Q26nw4hbm2dbFPCciPCce((const char *)base,0x2E9,(const char *)base+0x54);
    if (var_r29<=0) Panic__Q26nw4hbm2dbFPCciPCce((const char *)base,0x2EA,(const char *)base+0x7C);
    base=lbl_802F47D8;
    do {
        if (*var_r28==10 || *var_r28==0) return var_r28;
        s32 cls=((const u8 *)base)[(u8)*var_r28&0x7F];
        if(cls==0xFD) { temp=4-(var_r30&3); var_r30+=temp; var_r26+=temp*6; }
        else { if(cls!=0xFF) fn_800D337C(var_r26,var_r27,cls); var_r26+=6; var_r30++; }
        if(var_r30>=var_r29) { if(var_r28[1]==10) var_r28++; return var_r28; }
        var_r28++;
    } while((s8)*var_r28!=0);
    return var_r28;
}

extern "C" u16 lbl_80407BE8[];
extern "C" u32 lbl_8031EC40[];
extern "C" u8  lbl_802F4858[];
extern "C" u8  lbl_802F4958[];
extern "C" void fn_800D337C(s32 arg0, s32 arg1, s32 arg2) {
    u16 *dest;
    u16 *be;
    u32 *pal;
    s32 scaleX, scaleY;
    u16 width, height;
    s32 idx, rem, off;
    s32 i, n;
    s32 v;

    v = arg2;
    if (arg2 >= 100)
        v -= 100;

    rem = v % 5;
    idx = v / 5;
    off = rem * 6;

    pal = (u32 *)(lbl_802F4958 + idx * 28);
    if (arg2 < 100)
        pal = (u32 *)(lbl_802F4858 + idx * 28);

    width  = *(u16 *)((u8 *)lbl_80407BD8 + 8);
    height = *(u16 *)((u8 *)lbl_80407BD8 + 0xA);
    scaleX = width < 400 ? 1 : 2;
    scaleY = height < 300 ? 1 : 2;

    dest = (u16 *)(lbl_80407BD8[0] + scaleY * arg1 * (u16)*(u16 *)((u8 *)lbl_80407BD8 + 0xC) * 2 + arg0 * scaleX * 2);

    if (arg1 >= 0) {
        if (arg0 >= 0) {
            if (width > scaleX * (arg0 + 6)) {
                if (height > scaleY * (arg1 + 7)) {
                    be = lbl_80407BE8;
                    n = scaleX * 6;

                    for (i = 0; i < 7; i++) {
                        u32 pat = *pal++ << off;
                        s32 cnt;
                        if (scaleX == 1) {
                            pat = (pat >> 1) & 0x7E000000;
                        } else {
                            pat = ((lbl_8031EC40[(pat >> 26) & 0xC] << 4)
                                 | lbl_8031EC40[(pat >> 24) & 0xC]
                                 | (lbl_8031EC40[(pat >> 28) & 0xC] << 8)) << 19;
                        }
                        cnt = (n + 1) >> 1;
                        if (n > 0) {
                            do {
                                u32 b30 = pat & 0x40000000;
                                u32 b31 = pat & 0x80000000;
                                u32 b29 = pat & 0x20000000;
                                u32 b28 = pat & 0x10000000;
                                u16 p0 = (u16)((b30 ? be[2] : 0)
                                       | ((b30 ? be[4] : 0x40)
                                       + ((b29 ? be[5] : 0x20) + (b31 ? be[5] : 0x20))));
                                u16 p1;
                                dest[0] = p0;
                                if (scaleY > 1)
                                    dest[*(u16 *)((u8 *)lbl_80407BD8 + 0xC)] = p0;
                                p1 = (u16)((b29 ? be[2] : 0)
                                       | ((b29 ? be[7] : 0x40)
                                       + ((b28 ? be[8] : 0x20) + (b30 ? be[8] : 0x20))));
                                dest[1] = p1;
                                if (scaleY > 1)
                                    dest[*(u16 *)((u8 *)lbl_80407BD8 + 0xC) + 1] = p1;
                                pat <<= 2;
                                dest += 2;
                            } while (--cnt);
                        }
                        dest += *(u16 *)((u8 *)lbl_80407BD8 + 0xC) * scaleY - n;
                    }
                }
            }
        }
    }
}

extern "C" s32 fn_800D3824(void) {
    s32 val = lbl_8055DDD4;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}
extern "C" u8 fn_800D3838(u8 *arg0) {
    return *arg0;
}

extern "C" s32 OSEnableInterrupts(void);
extern "C" s32 DVDReadAsyncPrio(void *, void *, s32, s32, s32, s32);
extern "C" u8 fn_800D3840(s32 arg0) {
    s32 var_r29;
    s32 temp_r28;
    s32 temp_r31;
    s32 var_r31;
    u32 end;
    s32 temp_r4;
    u32 temp_r5;

    temp_r5 = (u32)arg0 & 0x7FFFFFFF;
    var_r29 = temp_r5 - lbl_805597E8;
    if (temp_r5 >= lbl_8055DDD0)
        return 0;
    if (lbl_805597E8 < 0 || var_r29 < 0 || var_r29 >= 0x200) {
        temp_r4 = temp_r5 & 0xFFFFFFE0;
        lbl_805597E8 = temp_r4;
        var_r29 = temp_r5 - temp_r4;
        var_r31 = 0x200;
        end = lbl_8055DDD0;
        if ((u32)(temp_r4 + 0x200) >= end)
            var_r31 = (end - temp_r4 + 0x1F) & 0xFFFFFFE0;
        temp_r28 = OSEnableInterrupts();
        temp_r31 = DVDReadAsyncPrio((void *)lbl_80407E00, (void *)lbl_80407C00, var_r31,
                                    lbl_805597E8, 0, 2);
        do {
        } while (DVDGetCommandBlockStatus((DVDCommandBlock *)lbl_80407E00) != 0);
        OSRestoreInterrupts(temp_r28);
        if (temp_r31 <= 0)
            return 0;
    }
    return lbl_80407C00[var_r29];
}

extern "C" u8 (*lbl_8055DDD8)(const char *);
extern "C" const char lbl_8031EC50[];
extern "C" const char lbl_8031ED84[];
// Fix note: use post-decrement for the delimiter count and signed newline comparison to match the original loop.
extern "C" char *fn_800D3944(char *str, s32 count, u32 delim) {
    s32 inDelim = 0;
    char *p = str;

    if (lbl_8055DDD8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EC50, 0x1B0, lbl_8031ED84);
    }
    if (p == 0) {
        return 0;
    }
    for (;;) {
        u8 c = lbl_8055DDD8(p);
        if (c == 0 || (s32)c == 10) {
            return 0;
        }
        if (inDelim != 0) {
            if (c == delim) {
                inDelim = 0;
            }
        } else if (c != delim) {
            if (count-- == 0) {
                return p;
            }
            inDelim = 1;
        }
        p++;
    }
}

extern "C" u32 fn_800D3A30(const char *arg0) {
    const char *base = lbl_8031EC50;
    u32 value = 0;
    const char *p = arg0;
    u8 c;
    u32 digit;

    if (p == 0) Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x1E6, base + 0x164);
    if (lbl_8055DDD8 == 0) Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x1E7, base + 0x134);
    for (;;) {
        c = lbl_8055DDD8(p);
        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'a' && c <= 'z') digit = c - 'W';
        else if (c >= 'A' && c <= 'Z') digit = c - '7';
        else return value;
        if (value >= 0x10000000) return 0;
        p++;
        value = digit + (value << 4);
    }
}

extern "C" u32 fn_800D3B40(const char *str, char *buffer, s32 count, u32 delim) {
    s32 copied = 0;
    register char *base = (char *)lbl_8031EC50;

    if (str == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x220, base + 0x18C);
    if (buffer == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x221, base + 0x164);
    if (lbl_8055DDD8 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x222, base + 0x134);

    count--;
    for (;;) {
        const char *p = str;
        u8 c = lbl_8055DDD8(p);
        str++;
        if ((u32)c == delim || c == 0 || (s32)c == 10) {
            *buffer = 0;
            return copied;
        }
        copied++;
        *buffer = c;
        buffer++;
        if ((u32)copied >= (u32)count) {
            *buffer = 0;
            return copied;
        }
    }
}

extern "C" s32 fn_800D3C44(register char *var_r24, void *arg1, register u32 var_r25, register char *var_r26, register s32 var_r27) {
    register const char *base = lbl_8031EC50;
    void *var_r30 = 0;
    s32 var_r29;
    s32 var_r23;
    s32 var_r23_2;
    s32 var_r23_3;
    u32 var_r28;
    u32 temp_r0;
    char *temp_r23;
    char *temp_r3_4;
    char *temp_r3_5;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r3_3;

    if (var_r26 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x25A, base + 0x1B4);
    }
    if (var_r27 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x25B, base + 0x1E0);
    }
    if (arg1 != 0) {
        var_r30 = *(void **)((u8 *)arg1 + 0x10);
        var_r29 = *(s32 *)((u8 *)arg1 + 0xC);
    }

loop_6:
    var_r28 = 0;
    if (lbl_8055DDD8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x18D, base + 0x134);
    }

loop_8:
    var_r23 = 1;
    if (lbl_8055DDD8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x169, base + 0x134);
    }
    temp_r3 = (u8)var_r24;
    if (var_r24 == 0) {
        var_r24 = 0;
    } else {
        for (;;) {
            if (((s32)temp_r3 == 0xA) && ((var_r23 -= 1) <= 0)) {
                var_r24++;
                break;
            }
            var_r24++;
            temp_r3 = lbl_8055DDD8(var_r24);
            if (temp_r3 == 0) {
                var_r24 = 0;
                break;
            }
        }
    }
    if (var_r24 == 0) {
        var_r24 = 0;
    } else if ((s32)lbl_8055DDD8(var_r24) != 0x2E) {
        goto loop_8;
    }

    var_r23_2 = 3;
    if (lbl_8055DDD8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x169, base + 0x134);
    }
    temp_r3_2 = (u8)var_r24;
    if (var_r24 == 0) {
        var_r24 = 0;
    } else {
        for (;;) {
            if (((s32)temp_r3_2 == 0xA) && ((var_r23_2 -= 1) <= 0)) {
                var_r24++;
                break;
            }
            var_r24++;
            temp_r3_2 = lbl_8055DDD8(var_r24);
            if (temp_r3_2 == 0) {
                var_r24 = 0;
                break;
            }
        }
    }

    if ((var_r30 == 0) ||
        ((var_r28 = *(u32 *)var_r30, var_r25 >= var_r28) &&
         (var_r25 < var_r28 + *(u32 *)((u8 *)var_r30 + 4)))) {
loop_36:
        var_r23_3 = 1;
        if (lbl_8055DDD8 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(&base[0], 0x169, base + 0x134);
        }
        temp_r3_3 = (u8)var_r24;
        if (var_r24 == 0) {
            var_r24 = 0;
        } else {
            for (;;) {
                if (((s32)temp_r3_3 == 0xA) && ((var_r23_3 -= 1) <= 0)) {
                    var_r24++;
                    break;
                }
                var_r24++;
                temp_r3_3 = lbl_8055DDD8(var_r24);
                if (temp_r3_3 == 0) {
                    var_r24 = 0;
                    break;
                }
            }
        }
        if (var_r24 == 0) {
            return 0;
        }

        temp_r23 = fn_800D3944(var_r24, 1, 0x20);
        if (temp_r23 != 0) {
            var_r23 = ((u32 (*)(void))fn_800D3A30)();
            temp_r3_4 = fn_800D3944(var_r24, 2, 0x20);
            if (temp_r3_4 != 0) {
                temp_r0 = ((u32 (*)(void))fn_800D3A30)();
                if (temp_r0 != 0) {
                    temp_r0 += var_r28;
                    if (var_r25 >= temp_r0) {
                        temp_r0 += (u32)var_r23;
                        if (temp_r0 <= var_r25) {
                            goto loop_36;
                        }
                        temp_r3_5 = fn_800D3944(var_r24, 5, 0x20);
                        if (temp_r3_5 == 0) {
                            *var_r26 = 0;
                            return 1;
                        }
                        if (((u8 (*)(void))lbl_8055DDD8)() != 0x2E) {
                            fn_800D3B40(temp_r3_5, var_r26, var_r27, 0x20);
                            return 1;
                        }
                        goto loop_36;
                    }
                }
                goto loop_36;
            }
        }
        goto block_58;
    }

block_58:
    if (var_r30 != 0) {
        var_r29 -= 1;
        if (var_r29 == 0) {
            return 0;
        }
        var_r30 = (void *)((u8 *)var_r30 + 8);
        goto loop_6;
    }
    goto loop_6;
}

extern "C" BOOL DVDFastOpen(s32 entrynum, void *info);
extern "C" BOOL DVDClose(void *info);
extern "C" s32 fn_800D3F94(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    register const char *base = lbl_8031EC50;
    s32 result;
    if (arg0 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)((u8 *)base + 0), 0x2D3, base + 0x6C);
    }
    if (arg2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)((u8 *)base + 0), 0x2D4, base + 0x1B4);
    }
    if (*(s32 *)arg0 != 0) {
        lbl_8055DDD8 = (u8 (*)(const char *))fn_800D3838;
        return fn_800D3C44(*(char **)arg0, *(void **)((u8 *)arg0 + 4), (u32)arg1, (char *)arg2, arg3);
    }
    if (*(s32 *)((u8 *)arg0 + 8) >= 0 && DVDFastOpen(*(s32 *)((u8 *)arg0 + 8), lbl_80407E00) != 0) {
        lbl_8055DDD8 = (u8 (*)(const char *))fn_800D3840;
        lbl_8055DDD0 = *(u32 *)(lbl_80407E00 + 0x34);
        result = fn_800D3C44((char *)0x80000000, *(void **)((u8 *)arg0 + 4), (u32)arg1, (char *)arg2, arg3);
        DVDClose(lbl_80407E00);
        return result;
    }
    *(u8 *)arg2 = 0;
    return 0;
}

#pragma opt_tail_call on
extern "C" s32 fn_800D40B4(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4) {
    void *r31 = (void *)lbl_8055DDD4;
    s32 r28 = arg2;
    s32 r29 = arg1;
    s32 r30 = arg0;
    while (r31 != NULL) {
        if (fn_800D3F94(r31, r30, r29, r28) != 0) return 1;
        r31 = *(void **)((u8 *)r31 + 0xC);
    }
    return 0;
}
extern "C" f32 lbl_80560E48;
extern "C" f32 lbl_80560E4C;
extern "C" u16 fn_800D4138(const void *arg0, u32 arg1, f32 farg0) {
    const u8 *base = (const u8 *)arg0;
    if (arg1 == 1 || farg0 <= *(f32 *)base) {
        return *(u16 *)(base + 4);
    }
    const u8 *end = base + arg1 * 8;
    if (farg0 >= *(f32 *)(end - 8)) return *(u16 *)(end - 4);
    s32 low = 0;
    s32 high = arg1 - 1;
    while (low != high - 1 && low != high) {
        s32 mid = (low + high) / 2;
        if (farg0 < *(f32 *)(base + mid * 8)) high = mid;
        else low = mid;
    }
    s32 offset = high * 8;
    f32 delta = farg0 - ((const f32 *)base)[high * 2];
    s32 found = 0;
    if (lbl_80560E48 < delta && delta < lbl_80560E4C) found = 1;
    if (found) return *(u16 *)(base + offset + 4);
    return *(u16 *)(base + low * 8 + 4);
}

extern "C" f32 lbl_80560E48, lbl_80560E4C, lbl_80560E50, lbl_80560E54, lbl_80560E58, lbl_80560E5C;
extern "C" f32 fn_800D4220(const void *arg0, u32 arg1, f32 farg0) {
    const u8 *base = (const u8 *)arg0;
    if (arg1 == 1 || farg0 <= *(f32 *)base) return *(f32 *)(base + 4);
    const u8 *end = base + arg1 * 12;
    if (farg0 >= *(f32 *)(end - 12)) return *(f32 *)(end - 8);
    s32 low = 0;
    s32 high = arg1 - 1;
    while (low != high - 1 && low != high) {
        s32 mid = (low + high) / 2;
        if (farg0 < *(f32 *)(base + mid * 12)) high = mid;
        else low = mid;
    }
    const u8 *right = base + high * 12;
    const u8 *left = base + low * 12;
    f32 delta = farg0 - *(f32 *)right;
    if (delta > lbl_80560E48 && delta < lbl_80560E4C) {
        if ((u32)high < arg1 - 1 && *(f32 *)right == *(f32 *)(base + (high + 1) * 12))
            return *(f32 *)(base + (high + 1) * 12 + 4);
        return *(f32 *)(right + 4);
    }
    f32 d = farg0 - *(f32 *)left;
    f32 scale = lbl_80560E50 / (*(f32 *)right - *(f32 *)left);
    f32 a = scale * (d * d);
    f32 b = a * scale;
    f32 c = d * b;
    f32 q = c * scale;
    return *(f32 *)(right + 8) * (c - a) +
        (*(f32 *)(left + 8) * (d + (c - lbl_80560E54 * a)) +
        (*(f32 *)(left + 4) * (lbl_80560E50 + lbl_80560E54 * q - lbl_80560E58 * b) +
        *(f32 *)(right + 4) * (lbl_80560E5C * q + lbl_80560E58 * b)));
}

extern "C" s32 fn_800D43DC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" u16 fn_800D441C(void *arg0) {
    return *(u16 *)(*(u8 **)((u8 *)arg0 + 0xC) + 8);
}

extern "C" s32 fn_800D58F0(void *);
extern "C" void AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(void *, void *);
extern "C" void *lbl_8055DDF0;
extern "C" f32 lbl_80560E60;
extern "C" char lbl_8031F168[];
extern "C" void fn_800D4428(void *arg0) {
    f32 initial = lbl_80560E60;
    char *vtable = lbl_8031F168;
    s32 zero = 0;
    *(s32 *)((u8 *)arg0 + 4) = zero;
    *(s32 *)((u8 *)arg0 + 8) = zero;
    *(s32 *)((u8 *)arg0 + 0xC) = zero;
    *(f32 *)((u8 *)arg0 + 0x10) = initial;
    *(void **)arg0 = vtable;
    *(s32 *)((u8 *)arg0 + 0x14) = zero;
    *(s32 *)((u8 *)arg0 + 0x18) = zero;
    *(s16 *)((u8 *)arg0 + 0x1C) = zero;
}

extern "C" void *__dt__Q36nw4hbm3lyt18AnimTransformBasicFv(void *self, s32 deleting) {
    if (self != 0) {
        *(void **)self = lbl_8031F168;
        if (*(void **)((u8 *)self + 0x18) != 0) {
            MEMFreeToAllocator((MEMAllocator *)lbl_8055DDF0, *(void **)((u8 *)self + 0x18));
        }
        if (*(void **)((u8 *)self + 0x14) != 0) {
            MEMFreeToAllocator((MEMAllocator *)lbl_8055DDF0, *(void **)((u8 *)self + 0x14));
        }
        if (deleting > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}

void nw4hbm::lyt::AnimTransformBasic::Bind(nw4hbm::lyt::Pane *pane, bool bind) {
    register u8 *self = (u8 *)this;
    register u8 *target = (u8 *)pane;
    register u16 i;
    register u8 *offsets = (u8 *)*(void **)(self + 0xC);
    offsets += *(s32 *)(offsets + 0x10);
    for (i = 0; i < *(u16 *)(*(u8 **)(self + 0xC) + 0xE); i++) {
        u8 *entry = target + *(s32 *)(offsets + i * 4);
        void *boundObject;
        if (entry[0x15] == 0) {
            boundObject = ((PaneAnimTransformDispatch *)target)->bindPane(entry, bind);
            if (boundObject != 0) {
                u8 *link = (u8 *)*(void **)(self + 0x18) + i * 0x10;
                *(void **)(link + 8) = self;
                *(u16 *)(link + 0xC) = i;
                AddAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimationLink(
                    boundObject, (u8 *)*(void **)(self + 0x18) + i * 0x10);
            }
        } else {
            boundObject = ((PaneAnimTransformDispatch *)target)->bindMaterial(entry, bind);
            if (boundObject != 0) {
                u8 *link = (u8 *)*(void **)(self + 0x18) + i * 0x10;
                *(void **)(link + 8) = self;
                *(u16 *)(link + 0xC) = i;
                AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(
                    boundObject, (u8 *)*(void **)(self + 0x18) + i * 0x10);
            }
        }
    }
}

extern "C" void AddAnimationLink__Q36nw4hbm3lyt4PaneFPQ36nw4hbm3lyt13AnimationLink(void *, void *);




extern "C" void SetTextureNoWrap__Q36nw4hbm3lyt8MaterialFUcP10TPLPalette(void *, u8, void *);
extern "C" s32 fn_800D9330(void *);
extern "C" s32 GetIndTexSRTAry__Q36nw4hbm3lyt8MaterialFv(void *);
extern "C" void SetColorElement__Q36nw4hbm3lyt8MaterialFUls(void *, s32, s16);
extern "C" const char lbl_8031F274[], lbl_8031F23C[], lbl_8031F2B8[], lbl_8031F280[];
void nw4hbm::lyt::AnimTransformBasic::Animate(unsigned long arg1, nw4hbm::lyt::Material *arg2) {
    const char *file = lbl_8031EE58;
    u8 *entries = (u8 *)*(void **)((u8 *)this + 0xC);
    u8 *animation = entries + *(s32 *)(entries + 0x10);
    u8 *block = animation + *(s32 *)(animation + arg1 * 4);
    u8 *offsetEntry = block + 0x18;
    s32 blockIndex = 0;
    f32 half = lbl_80560E64;
    while (blockIndex < block[0x14]) {
        u8 *record = block + *(s32 *)offsetEntry;
        s32 type = *(s32 *)record;
        u8 *itemOffsets = record + 8;
        switch (type) {
        case 0x524C4D43: {
            s32 itemIndex = 0;
            f32 frame = *(f32 *)((u8 *)this + 0x10);
            while (itemIndex < record[4]) {
                u8 *item = record + *(s32 *)itemOffsets;
                if (item[1] >= 0x20)
                    Panic__Q26nw4hbm2dbFPCciPCce(file, 0x106, file + 0x180);
                if (item[2] != 2)
                    Panic__Q26nw4hbm2dbFPCciPCce(file, 0x107, file + 0xB0);
                s16 value = (s16)(fn_800D4220(item + *(s32 *)(item + 8), *(u16 *)(item + 4), frame) + half);
                if (value < -0x400) value = -0x400;
                if (value > 0x3FF) value = 0x3FF;
                SetColorElement__Q36nw4hbm3lyt8MaterialFUls(arg2, item[1], value);
                itemOffsets += 4;
                itemIndex++;
            }
            break;
        }
        case 0x524C5453: {
            f32 frame = *(f32 *)((u8 *)this + 0x10);
            s32 itemIndex = 0;
            while (itemIndex < record[4]) {
                u8 *item = record + *(s32 *)itemOffsets;
                if (item[0] >= 0xA)
                    Panic__Q26nw4hbm2dbFPCciPCce(file, 0x11F, file + 0x1C8);
                u32 max = (*(u32 *)((u8 *)arg2 + 0x4C) >> 4) & 0xF;
                if (item[0] < max) {
                    if (item[1] >= 5)
                        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x122, file + 0x1FC);
                    if (item[2] != 2)
                        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x123, file + 0xB0);
                    f32 value = fn_800D4220(item + *(s32 *)(item + 8), *(u16 *)(item + 4), frame);
                    u32 count = (*(u32 *)((u8 *)arg2 + 0x50) >> 4) & 0xF;
                    if (item[0] >= count)
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F274, 0x125, lbl_8031F23C);
                    s32 base = fn_800D9330(arg2);
                    *(f32 *)(base + item[0] * 0x14 + item[1] * 4) = value;
                }
                itemOffsets += 4;
                itemIndex++;
            }
            break;
        }
        case 0x524C5450: {
            void **palettes = *(void ***)((u8 *)this + 0x14);
            if (palettes != 0) {
                f32 frame = *(f32 *)((u8 *)this + 0x10);
                s32 itemIndex = 0;
                while (itemIndex < record[4]) {
                    u8 *item = record + *(s32 *)itemOffsets;
                    if (item[0] >= 8)
                        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x137, file + 0x240);
                    u32 count = *(u32 *)((u8 *)arg2 + 0x50) >> 28;
                    if (item[0] < count) {
                        if (item[2] != 1)
                            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x13A, file + 0xF4);
                        if (item[1] == 0) {
                            u16 paletteIndex = fn_800D4138(item + *(s32 *)(item + 8), *(u16 *)(item + 4), frame);
                            SetTextureNoWrap__Q36nw4hbm3lyt8MaterialFUcP10TPLPalette(arg2, item[0], palettes[paletteIndex]);
                        }
                    }
                    itemOffsets += 4;
                    itemIndex++;
                }
            }
            break;
        }
        case 0x524C494D: {
            f32 frame = *(f32 *)((u8 *)this + 0x10);
            s32 itemIndex = 0;
            while (itemIndex < record[4]) {
                u8 *item = record + *(s32 *)itemOffsets;
                if (item[0] >= 3)
                    Panic__Q26nw4hbm2dbFPCciPCce(file, 0x151, file + 0x278);
                u32 max = (*(u32 *)((u8 *)arg2 + 0x4C) >> 12) & 3;
                if (item[0] < max) {
                    if (item[1] >= 5)
                        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x154, file + 0x1FC);
                    if (item[2] != 2)
                        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x155, file + 0xB0);
                    f32 value = fn_800D4220(item + *(s32 *)(item + 8), *(u16 *)(item + 4), frame);
                    u32 count = (*(u32 *)((u8 *)arg2 + 0x50) >> 12) & 3;
                    if (item[0] >= count)
                        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2B8, 0x135, lbl_8031F280);
                    s32 base = GetIndTexSRTAry__Q36nw4hbm3lyt8MaterialFv(arg2);
                    *(f32 *)(base + item[0] * 0x14 + item[1] * 4) = value;
                }
                itemOffsets += 4;
                itemIndex++;
            }
            break;
        }
        }
        offsetEntry += 4;
        blockIndex++;
    }
}

extern "C" const char lbl_8031EE58[];
extern "C" const char lbl_8031F1FC[];
extern "C" const char lbl_8031F1D8[];
extern "C" const char lbl_8031F1CC[];
extern "C" const char lbl_8031F1A8[];
extern "C" void *fn_800D4F98(void *arg0, u32 arg1, u32 arg2) {
    u32 head = (u32)arg0;
    u32 node;
    u32 sentinel;
    const char *file = lbl_8031EE58;

    if (head == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x22F, file + 0x2B0);
    if (arg1 == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x230, file + 0x2DC);

    node = *(u32 *)(head + 4);
    sentinel = head + 4;
    while (node != sentinel) {
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
        if (arg1 == *(u32 *)(node + 8)) {
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1FC, 0x23D, lbl_8031F1D8);
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F1CC, 0x193, lbl_8031F1A8);
            return (void *)node;
        }
        node = *(u32 *)node;
    }
    return 0;
}

extern "C" s32 fn_800D50A8(ARCHandle *handle, const char *name) {
    ARCDir dir;
    ARCDirEntry entry;
    register ARCHandle *h = handle;
    register const char *n = name;
    s32 result = -1;
    if (!ARCOpenDir(h, lbl_805597F8, &dir))
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0x30, lbl_8031F2E4);
    while (ARCReadDir(&dir, &entry)) {
        if (entry.isDir) {
            if (!ARCChangeDir(h, entry.name))
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0x39, lbl_8031F2E4);
            result = fn_800D50A8(h, n);
            if (!ARCChangeDir(h, lbl_805597FC))
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0x3C, lbl_8031F2E4);
            if (result != -1) break;
        } else if (stricmp(n, entry.name) == 0) {
            result = entry.entryNum;
            break;
        }
    }
    if (!fn_80116BCC(&dir))
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0x4D, lbl_8031F2E4);
    return result;
}

extern "C" s32 fn_800D51F4(long a0, long a1, long a2, long a3, long a4, long a5) {
    ARCHandle *arc=(ARCHandle *)a0; const char *path=(const char *)a1; u32 selector=(u32)a2; const char *name=(const char *)a3; u32 *size=(u32 *)a4;
    u8 p[5]; ARCFileInfo info; s32 entry=-1, result=0;
    if (ARCConvertPathToEntrynum(arc,path)!=-1 && ARCChangeDir(arc,path)!=0) {
        if(!selector) entry=fn_800D50A8(arc,name);
        else {
            p[0]=selector>>24; p[1]=selector>>16; p[2]=selector>>8; p[3]=selector; p[4]=0;
            if(ARCConvertPathToEntrynum(arc,(char*)p)!=-1 && ARCChangeDir(arc,(char*)p)!=0) {
                entry=ARCConvertPathToEntrynum(arc,name);
                if(ARCChangeDir(arc,lbl_805597FC)==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8,0x75,lbl_8031F2E4);
            }
        }
        if(ARCChangeDir(arc,lbl_805597FC)==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8,0x7B,lbl_8031F2E4);
    }
    if(entry!=-1) {
        if(ARCFastOpen(arc,entry,&info)==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8,0x83,lbl_8031F2E4);
        result=(s32)ARCGetStartAddrInMem(&info);
        if(size) *size=fn_80116A30(&info);
        fn_80116A38(&info);
    }
    return result;
}

extern "C" void fn_800DCE50(void *arg0);
#pragma push
#pragma small_data off
extern u8 lbl_8031F43C[];
#pragma push
#pragma small_data off
#pragma pop
extern "C" void __ct__Q36nw4hbm3lyt19ArcResourceAccessorFv(void *this_) {
    u32 *p = (u32 *)this_;
    u32 v = (u32)&lbl_8031F43C;

    fn_800DCE50(this_);

    p[0x28 >> 2] = 0;
    p[0x2C >> 2] = 0;
    p[0] = v;
    p[0x20 >> 2] = 0;
    p[0x24 >> 2] = 0;
    p[0x28 >> 2] = (u32)this_ + 0x28;
    p[0x2C >> 2] = (u32)this_ + 0x28;
}
extern "C" const char lbl_8031F2C8[];
#pragma push
#pragma opt_common_subs off
extern "C" s32 fn_800D53FC(void *arg0, void *arg1, const char *arg2) {
    const char *file = lbl_8031F2C8;
    void *handle = arg1;
    const char *name = arg2;
    void *self = arg0;
    if (*(s32 *)((u8 *)self + 0x20) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0xDC, file + 0x7C);
    if (handle == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0xDD, file + 0xA4);
    if (name == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F2C8, 0xDE, file + 0xD8);
    if (ARCInitHandle(handle, (ARCHandle *)((u8 *)self + 4)) == 0)
        return 0;
    *(void **)((u8 *)self + 0x20) = handle;
    strncpy((char *)self + 0x30, name, 0x7F);
    *((u8 *)self + 0xAF) = 0;
    return 1;
}
#pragma pop
extern "C" void fn_800D54E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_800D51F4(arg0 + 4, arg0 + 0x30, arg1, arg2, arg3, arg1);
}

extern "C" s32 fn_800D5500(void *obj, const char *name) {
    void *entry = *(void **)((u8 *)obj + 0x28);
    while (entry != (u8 *)obj + 0x28) {
        if (entry == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23d, lbl_8031F510);
        if (strcmp(name, (char *)entry + 8) == 0) {
            if (entry == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23d, lbl_8031F510);
            return *(s32 *)((u8 *)entry + 0x88);
        }
        entry = *(void **)entry;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
extern "C" void* fn_800D55B0(void *self, s32 arg1) {
    if (self != NULL) {
        *(void **)self = lbl_8031F428;
        Clear__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 4);
        if ((u8 *)self + 0x10 != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 0x10, 0);
        }
        if ((u32 *)self + 1 != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u32 *)self + 1, 0);
        }
        fn_800DCE10(self, 0);
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}
#pragma pop
extern "C" s32 fn_800D5640(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *node = *(void **)((u8 *)arg0 + 8);
    s32 a = arg1;
    s32 b = arg2;
    s32 c = arg3;
    void *end = (u8 *)arg0 + 8;
    while (node != end) {
        if (node == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F4A4, 0x23D, lbl_8031F480);
        }
        void *next = (u8 *)node + 8;
        if (node == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F4A4, 0x23D, lbl_8031F480);
        }
        s32 result = ((s32 (*)(long, long, long, long, long))fn_800D51F4)((long)next, (long)((u8 *)node + 0x24), a, b, c);
        if (result != 0) return result;
        node = *(void **)node;
    }
    return 0;
}
#pragma pop
extern "C" s32 fn_800D56FC(void *obj, const char *name, s32 unused) {
    u32 node = *(u32 *)((u8 *)obj + 0x14);
    u32 end = (u32)obj + 0x14;
    while (node != end) {
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23d, lbl_8031F510);
        if (strcmp(name, (char *)(node + 8)) == 0) {
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23d, lbl_8031F510);
            return *(s32 *)(node + 0x88);
        }
        node = *(u32 *)node;
    }
    return 0;
}

extern "C" void* fn_800D57AC(void* arg0, const void* arg1) {
    __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(arg0, arg1);
    *(const char**)arg0 = lbl_8031F540;
    return arg0;
}

extern "C" void* __dt__Q36nw4hbm3lyt8BoundingFv(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q36nw4hbm3lyt4PaneFv(arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void DrawSelf__Q36nw4hbm3lyt8BoundingFRCQ36nw4hbm3lyt8DrawInfo(BoundingPane *self, const DrawInfo *info) {
    struct ColorArg {
        unsigned int value;
    };
    ColorArg color;

    if ((info->flag >> 3) & 1) {
        self->v22();
        color.value = 0x00FF00FF;
        Vec2 pos = ((Vec2 (*)(BoundingPane *))GetVtxPos__Q34nw4r3lyt4PaneCFv)(self);
        ((void (*)(const Vec2 *, const Size *, const ColorArg *))DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color)(
            &pos, (const Size *)((const u8 *)self + 0x4C), &color);
    }
}

extern u32 lbl_8055DDE0;
extern "C" u32* fn_800D58B0(void) {
    return &lbl_8055DDE0;
}

extern "C" void fn_800C7764(void *arg0, s8 arg1) {
    ((u8 *)arg0)[0x24] = (u8)arg1;
}

extern "C" void fn_800C776C(void *arg0, s32 arg1) {
    ((u32 *)arg0)[0x24 / 4] = (u32)arg1;
}

extern "C" void fn_800C790C(void *arg0) {
    struct Context {
        u8 pad0[4];
        void *inner;
        u8 pad8[0xB0 - 8];
        u16 *table[7][6];
    };
    Context *ctx = (Context *)arg0;
    register u16 *var_r7;
    s32 var_r9 = 0;
    s32 col = 0;
    s32 in_quote = 0;
    u16 *str = *(u16 **)((u8 *)ctx->inner + 8);
    s32 row = 0;
    var_r7 = str;

    while (*var_r7 != 0) {
        if (*var_r7 == 0x22) {
            *var_r7 = 0;
            if (in_quote == 0) {
                u16 *elem = &str[var_r9 + 1];
                ctx->table[col][row] = elem;
                col++;
                in_quote = 1;
                if (col == 7) {
                    col = 0;
                    row++;
                }
            } else {
                in_quote = 0;
            }
        }
        var_r7++;
        var_r9++;
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void fn_800C7998(void *arg0) {
    class HomeButtonDispatch {
    public:
        virtual void d0(); virtual void setup(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8();
        virtual void apply(s32, s32, s32, s32, s32, f32, f32);
    };
    class LayoutDispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12();
        virtual void *findPane(u32, s32);
    };
    f32 rect[4];
    f32 temp_f31;
    u8 *home = (u8 *)arg0;
    u8 *data = lbl_8031D840;
    register s32 zero = 0;
    register s32 one = 1;
    s32 var_r30;
    u8 *child;
    s32 childCount;
    void *pane, *layout;
    HomeButtonDispatch *soundControl;
    LayoutDispatch *layoutDispatch;
    u32 *paneNames;
    s32 paneCount;
    u32 soundIndex;
    u8 flags;

    if (home[0x8B] != 0) return;
    home[0x8C] = zero;
    home[0x8B] = one;
    home[0x8D] = zero;
    home[0x8F] = zero;
    if (*(s32 *)(home + 0xAC) != 3) home[0x8E] = zero;
    GXSetCullMode(0);
    *(s32 *)(home + 0x1C) = zero;
    *(s32 *)(home + 0x20) = zero;
    *(s32 *)(home + 0x24) = zero;
    *(s32 *)(home + 0x28) = zero;
    *(s32 *)(home + 0x2C) = zero;
    *(s32 *)(home + 0x30) = zero;
    *(s32 *)(home + 0x34) = zero;
    *(s32 *)(home + 0x38) = zero;
    *(s32 *)(home + 0x3C) = zero;
    *(s32 *)(home + 0x40) = zero;
    *(s32 *)(home + 0x44) = zero;
    *(s32 *)(home + 0x48) = zero;
    *(s32 *)(home + 0x4C) = zero;
    *(s32 *)(home + 0x50) = zero;
    *(s32 *)(home + 0x10) = zero;
    *(s32 *)home = zero;
    home[0x88] = zero;
    updateTrigPane__Q210homebutton10HomeButtonFv(arg0);

    soundControl = *(HomeButtonDispatch **)(home + 0x1F8);
    soundControl->setup();
    for (var_r30 = 0; var_r30 < 8; var_r30++) {
        soundControl = *(HomeButtonDispatch **)(home + 0x1F8);
        soundControl->apply(var_r30, 0, 0, 0, 0, lbl_80560DD8, lbl_80560DD8);
    }

    temp_f31 = lbl_80560DC8;
    child = home;
    childCount = 0;
    var_r30 = 0;
    for (; childCount < 4; childCount++, child += 4) {
        *(s32 *)(child + 0x54) = var_r30;
        fn_800D11E0(*(void **)(child + 0x254));
        fn_800D11CC(*(void **)(child + 0x254));
        ((void (*)(void *))fn_800D1200)(*(void **)(child + 0x254));
        fn_800D16A8((s32 *)*(void **)(child + 0x254));
        fn_800D0F78(*(void **)(child + 0x254));
        fn_800D1300(*(void **)(child + 0x254));
        *(f32 *)(child + 0x1BC) = temp_f31;
        *(f32 *)(child + 0x1CC) = temp_f31;
    }

    layout = *(void **)(home + 0x1E0);
    GetLayoutRect__Q34nw4lyt6LayoutCFv(rect, layout);
    *(f32 *)(home + 0x234) = rect[0];
    *(f32 *)(home + 0x238) = rect[1];
    *(f32 *)(home + 0x23C) = rect[2];
    *(f32 *)(home + 0x240) = rect[3];

    layoutDispatch = *(LayoutDispatch **)((u8 *)layout + 0x10);
    pane = layoutDispatch->findPane(*(u32 *)(data + 0x950), 1);
    flags = ((u8 *)pane)[0xCF];
    ((u8 *)pane)[0xCF] = flags & 0xFE;

    paneNames = (u32 *)(data + 0x9D8);
    paneNames += 2;
    for (paneCount = 2; paneCount < 7; paneCount++) {
        pane = (*(LayoutDispatch **)((u8 *)*(void **)(home + 0x1E0) + 0x10))->findPane(*paneNames, 1);
        flags = ((u8 *)pane)[0xCF];
        ((u8 *)pane)[0xCF] = flags & 0xFE;
        paneNames++;
    }
    data += 0xA24;
    for (paneCount = 0; paneCount < 3; paneCount++) {
        pane = (*(LayoutDispatch **)((u8 *)*(void **)(home + 0x1E0) + 0x10))->findPane(*(u32 *)data, 1);
        flags = ((u8 *)pane)[0xCF];
        ((u8 *)pane)[0xCF] = flags & 0xFE;
        data += 4;
    }

    Start__Q210homebutton9RemoteSpkFv(*(void **)(home + 0x264));
    if (*(void **)(home + 0x5C0) != 0) {
        for (soundIndex = 0; soundIndex < *(u32 *)(*(u8 **)(home + 0x5C0) + 0x70); soundIndex++) {
            void *soundPlayer = GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(*(void **)(home + 0x5C0), soundIndex);
            SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(soundPlayer, lbl_80560DCC);
        }
    }
    fn_800C81F0(arg0, 0);
    *(s32 *)(home + 0x3FC) = zero;
    *(s32 *)(home + 0x400) = 0x1E;
    *(s32 *)(home + 0x404) = zero;
}
#pragma dont_inline reset
#pragma pop

extern "C" u32* fn_800C7C68(void) {
    return &lbl_8055DDF8;
}

extern "C" u8 fn_80062054(void);
extern "C" void fn_80062088(s32);
extern "C" f32 lbl_80560DDC,lbl_80560DE0,lbl_80560DE4;
extern "C" f32 lbl_80560DD0,lbl_80560DE8;
extern "C" s32 fn_800C7C70(void *arg0) {
 s32 i,j,key,found,count; s32 *entry; void *obj; f32 f; u32 ticks;
 ticks=fn_80062054(); f=lbl_80560DE0*((f32)ticks-127.0f)+lbl_80560DDC;
 *(s32 *)((u8 *)arg0+0x80)=(s32)f; fn_80062088(0x7f);
 for(i=0;i<4;i++){u32 bits=*(u32 *)((u8 *)arg0+0x80)^0x80000000; f=((f32)(s32)bits-2147483648.0f)/lbl_80560DE4; obj=*(void **)((u8 *)arg0+0x254+i*4); fn_800D1204(obj,f); fn_800D11F0(obj);}
 count=*(s32 *)((u8 *)arg0+0x80);
 for(i=0;i<10;i++){key=i+0x15;entry=lbl_802F4588;found=0;
  for(j=0;j<0x25;j++){if(key==entry[0]&&entry[1]==(i<count?10:9))break;found++;if(key==entry[2]&&entry[3]==(i<count?10:9))break;entry+=4;found++;}
  if(j==0x25)found=-1;obj=*(void **)((u8 *)arg0+0x298+found*4);fn_800CF3EC(obj);*(s32 *)((u8 *)obj+0x14)=1;
 }
}

extern "C" s16 fn_80031C74(void);
extern "C" s16 fn_80031C7C(void);
extern "C" s16 fn_80031C84(void);
extern "C" void fn_80031C8C(u16);
extern "C" void fn_80031C94(u32);
extern "C" void fn_80031C9C(u32);
extern "C" void AXGetAuxACallback_8009CDBC(void *, void *);
extern "C" void AXGetAuxACallback(void *, void *);
extern "C" void AXFXSetHooks_8009CDB0(void *, void *);
extern "C" void AXFXReverbHiInit(void *);
extern "C" void AXRegisterAuxACallback(void *, void *);
extern "C" void *fn_800C64DC(u32);
extern "C" void fn_800C64E8(u32);
extern "C" void fn_8009BFBC(void);
extern "C" f32 lbl_80560DC8, lbl_80560DCC, lbl_80560DF0, lbl_80560DF4;
extern "C" void GXSetCullMode(s32);
extern "C" void GetLayoutRect__Q34nw4lyt6LayoutCFv(f32 *, void *);
extern "C" void *GetSoundPlayer__Q36nw4hbm3snd18SoundArchivePlayerFUl(void *, u32);
extern "C" void SetInitialVolume__Q46nw4hbm3snd6detail10BasicSoundFf_800F877C(void *, f32);
extern "C" void Start__Q210homebutton9RemoteSpkFv(void *);
extern "C" void fn_800C81F0(void *, s32);
extern "C" void fn_800D0F78(void *);
extern "C" void fn_800D11CC(void *);
extern "C" void fn_800D11E0(void *);
extern "C" void fn_800D1200(void);
extern "C" void fn_800D1300(void *);
extern "C" void fn_800D16A8(s32 *);
extern "C" f32 lbl_80560DD8;
extern "C" u8 lbl_8031D840[];

extern "C" void fn_800C7E6C(void *arg0) {
    u8 *self = (u8 *)arg0;
    void *object;
    void (*callback)(s32, s32);
    f32 f3, f2, f1, f0;
    if (*(s32 *)(self + 0xAC) == 3) return;
    object = *(void **)(self + 4);
    callback = *(void (**)(s32, s32))((u8 *)object + 0x14);
    if (callback != 0) callback(0, 0);
    *(s16 *)(self + 0x5D8) = fn_80031C74();
    *(s16 *)(self + 0x5DA) = fn_80031C7C();
    *(s16 *)(self + 0x5DC) = fn_80031C84();
    AXGetAuxACallback_8009CDBC(self + 0x5E0, self + 0x5E4);
    AXGetAuxACallback(self + 0x748, self + 0x74C);
    AXFXSetHooks_8009CDB0((void *)fn_800C64DC, (void *)fn_800C64E8);
    f0 = lbl_80560DC8;
    f1 = lbl_80560DF0;
    f2 = lbl_80560DF4;
    f3 = lbl_80560DCC;
    *(f32 *)(self + 0x740) = f0;
    *(f32 *)(self + 0x738) = f1;
    *(f32 *)(self + 0x730) = f2;
    *(f32 *)(self + 0x73C) = f0;
    *(f32 *)(self + 0x744) = f0;
    *(f32 *)(self + 0x734) = f3;
    AXFXReverbHiInit(self + 0x5E8);
    AXRegisterAuxACallback((void *)fn_8009BFBC, self + 0x5E8);
    fn_80031C8C(0x8000);
    fn_80031C94(0);
    fn_80031C9C(0);
    object = *(void **)(self + 4);
    callback = *(void (**)(s32, s32))((u8 *)object + 0x14);
    if (callback != 0) callback(1, 0);
    self[0x8E] = 1;
}

extern "C" void fn_800D15B4(void *);
extern "C" f32 lbl_80560DF8;
extern "C" void fn_800C7F8C(void *, s32);
extern "C" void fn_800C81F0(void *arg0, s32 arg1) {
    /* budget retry 10 */
    u8 *self = (u8 *)arg0;
    (*(void (**)(void *))(*(void ***)*(void **)(self + 0x1F8) + 4))(*(void **)(self + 0x1F8));
    s32 i;
    u8 *cursor;
    cursor = self;
    for (i = 0; i < *(s32 *)(self + 0xC); i++) {
        (*(homebutton::GroupAnmController **)(cursor + 0x268))->do_calc();
        cursor += 4;
    }
    cursor = self;
    for (i = 0; i < 15; i++) {
        (*(homebutton::GroupAnmController **)(cursor + 0x3C0))->do_calc();
        cursor += 4;
    }
    cursor = self;
    for (i = 0; i < 0x4A; i++) {
        (*(homebutton::GroupAnmController **)(cursor + 0x298))->do_calc();
        cursor += 4;
    }
    f32 one = lbl_80560DF8;
    f32 zero = lbl_80560DC8;
    cursor = self;
    for (i = 0; i < 4; i++) {
        f32 *a = (f32 *)(cursor + 0x1BC);
        f32 *b = (f32 *)(cursor + 0x1CC);
        void *controller = *(void **)(cursor + 0x254);
        if (*a > zero) {
            if (self[0x7C + i * 4]) {
                if (!*((u8 *)controller + 0x1C)) {
                    *a = zero;
                    *b = zero;
                    if (*((u8 *)controller + 0x1C))
                        fn_800D15B4(controller);
                }
            } else {
                *a -= *(f32 *)(*(u8 **)(self + 4) + 0x28);
                if (*a <= zero && *(s32 *)(self + 0x10) == 0x11) {
                    fn_800D15B4(controller);
                    *a = zero;
                    *b = one;
                }
            }
        }
        if (*b > zero) {
            *b -= *(f32 *)(*(u8 **)(self + 4) + 0x28);
            if (*b <= zero)
                *b = zero;
        }
        cursor += 4;
    }
    s32 index = *(s32 *)(self + 0x14);
    void *current = *(void **)(self + 0x298 + index * 4);
    fn_800CF3EC(current);
    *(s32 *)((u8 *)current + 0x14) = 1;
    if (arg1 != 0) {
        *(s32 *)(self + 0x10) = 1;
        fn_800C7F8C(arg0, arg1);
    }
    switch (*(s32 *)(self + 0x10)) {
        case 0: *(s32 *)(self + 0x14) = 0; break;
        case 1: *(s32 *)(self + 0x14) = 1; break;
        case 2: *(s32 *)(self + 0x14) = 2; break;
        case 3: *(s32 *)(self + 0x14) = 3; break;
        case 4: *(s32 *)(self + 0x14) = 4; break;
        case 5: *(s32 *)(self + 0x14) = 5; break;
        case 6: *(s32 *)(self + 0x14) = 6; break;
        case 7: *(s32 *)(self + 0x14) = 7; break;
        case 8: *(s32 *)(self + 0x14) = 8; break;
        case 9: *(s32 *)(self + 0x14) = 9; break;
        case 10: *(s32 *)(self + 0x14) = 10; break;
        case 11: *(s32 *)(self + 0x14) = 11; break;
        case 12: *(s32 *)(self + 0x14) = 12; break;
        case 13: *(s32 *)(self + 0x14) = 13; break;
        case 14: *(s32 *)(self + 0x14) = 14; break;
        case 15: *(s32 *)(self + 0x14) = 15; break;
        case 16: *(s32 *)(self + 0x14) = 16; break;
        case 17: *(s32 *)(self + 0x14) = 17; break;
        case 18: *(s32 *)(self + 0x14) = 18; break;
        case 19: *(s32 *)(self + 0x14) = 19; break;
        default: break;
    }
    s32 *p = lbl_802F4588;
    s32 found = 0;
    for (i = 0; i < 0x25; i++) {
        if (p[0] == 2 && p[1] == 0) break;
        if (p[2] == 2 && p[3] == 0) {
            found++;
            break;
        }
        p += 4;
        found += 2;
    }
    if (i == 0x25) found = -1;
    *(s32 *)(self + 0x14) = found;
    {
        s32 *p_z = lbl_802F4588;
        s32 result_z = 0;
        s32 j_z;
        for (j_z = 0x25; j_z > 0; j_z--) {
            if (p_z[0] == 0 && p_z[1] == 0) break;
            if (p_z[2] == 0 && p_z[3] == 0) {
                result_z++;
                break;
            }
            p_z += 4;
            result_z += 2;
        }
        if (j_z == 0) result_z = -1;
        *(s32 *)(self + 0x14) = result_z;
    }
    {
        s32 *p_d6 = lbl_802F4588;
        s32 result_d6 = 0;
        s32 j_d6;
        for (j_d6 = 0x25; j_d6 > 0; j_d6--) {
            if (p_d6[0] == 13 && p_d6[1] == 6) break;
            if (p_d6[2] == 13 && p_d6[3] == 6) {
                result_d6++;
                break;
            }
            p_d6 += 4;
            result_d6 += 2;
        }
        if (j_d6 == 0) result_d6 = -1;
        *(s32 *)(self + 0x14) = result_d6;
    }
    {
        s32 *p_e8 = lbl_802F4588;
        s32 result_e8 = 0;
        s32 j_e8;
        for (j_e8 = 0x25; j_e8 > 0; j_e8--) {
            if (p_e8[0] == 14 && p_e8[1] == 8) break;
            if (p_e8[2] == 14 && p_e8[3] == 8) {
                result_e8++;
                break;
            }
            p_e8 += 4;
            result_e8 += 2;
        }
        if (j_e8 == 0) result_e8 = -1;
        *(s32 *)(self + 0x14) = result_e8;
    }
    {
        s32 *p_d8 = lbl_802F4588;
        s32 result_d8 = 0;
        s32 j_d8;
        for (j_d8 = 0x25; j_d8 > 0; j_d8--) {
            if (p_d8[0] == 13 && p_d8[1] == 8) break;
            if (p_d8[2] == 13 && p_d8[3] == 8) {
                result_d8++;
                break;
            }
            p_d8 += 4;
            result_d8 += 2;
        }
        if (j_d8 == 0) result_d8 = -1;
        *(s32 *)(self + 0x14) = result_d8;
    }
    {
        s32 *p_e6 = lbl_802F4588;
        s32 result_e6 = 0;
        s32 j_e6;
        for (j_e6 = 0x25; j_e6 > 0; j_e6--) {
            if (p_e6[0] == 14 && p_e6[1] == 6) break;
            if (p_e6[2] == 14 && p_e6[3] == 6) {
                result_e6++;
                break;
            }
            p_e6 += 4;
            result_e6 += 2;
        }
        if (j_e6 == 0) result_e6 = -1;
        *(s32 *)(self + 0x14) = result_e6;
    }
    {
        s32 *p_11c = lbl_802F4588;
        s32 result_11c = 0;
        s32 j_11c;
        for (j_11c = 0x25; j_11c > 0; j_11c--) {
            if (p_11c[0] == 17 && p_11c[1] == 12) break;
            if (p_11c[2] == 17 && p_11c[3] == 12) {
                result_11c++;
                break;
            }
            p_11c += 4;
            result_11c += 2;
        }
        if (j_11c == 0) result_11c = -1;
        *(s32 *)(self + 0x14) = result_11c;
    }
    {
        s32 *p_12c = lbl_802F4588;
        s32 result_12c = 0;
        s32 j_12c;
        for (j_12c = 0x25; j_12c > 0; j_12c--) {
            if (p_12c[0] == 18 && p_12c[1] == 12) break;
            if (p_12c[2] == 18 && p_12c[3] == 12) {
                result_12c++;
                break;
            }
            p_12c += 4;
            result_12c += 2;
        }
        if (j_12c == 0) result_12c = -1;
        *(s32 *)(self + 0x14) = result_12c;
    }
    {
        s32 *p_31 = lbl_802F4588;
        s32 result_31 = 0;
        s32 j_31;
        for (j_31 = 0x25; j_31 > 0; j_31--) {
            if (p_31[0] == 3 && p_31[1] == 1) break;
            if (p_31[2] == 3 && p_31[3] == 1) {
                result_31++;
                break;
            }
            p_31 += 4;
            result_31 += 2;
        }
        if (j_31 == 0) result_31 = -1;
        *(s32 *)(self + 0x14) = result_31;
    }
    {
        s32 *p_11 = lbl_802F4588;
        s32 result_11 = 0;
        s32 j_11;
        for (j_11 = 0x25; j_11 > 0; j_11--) {
            if (p_11[0] == 1 && p_11[1] == 1) break;
            if (p_11[2] == 1 && p_11[3] == 1) {
                result_11++;
                break;
            }
            p_11 += 4;
            result_11 += 2;
        }
        if (j_11 == 0) result_11 = -1;
        *(s32 *)(self + 0x14) = result_11;
    }
    {
        s32 *p_42 = lbl_802F4588;
        s32 result_42 = 0;
        s32 j_42;
        for (j_42 = 0x25; j_42 > 0; j_42--) {
            if (p_42[0] == 4 && p_42[1] == 2) break;
            if (p_42[2] == 4 && p_42[3] == 2) {
                result_42++;
                break;
            }
            p_42 += 4;
            result_42 += 2;
        }
        if (j_42 == 0) result_42 = -1;
        *(s32 *)(self + 0x14) = result_42;
    }
    {
        s32 *p_53 = lbl_802F4588;
        s32 result_53 = 0;
        s32 j_53;
        for (j_53 = 0x25; j_53 > 0; j_53--) {
            if (p_53[0] == 5 && p_53[1] == 3) break;
            if (p_53[2] == 5 && p_53[3] == 3) {
                result_53++;
                break;
            }
            p_53 += 4;
            result_53 += 2;
        }
        if (j_53 == 0) result_53 = -1;
        *(s32 *)(self + 0x14) = result_53;
    }
    {
        s32 *p_413 = lbl_802F4588;
        s32 result_413 = 0;
        s32 j_413;
        for (j_413 = 0x25; j_413 > 0; j_413--) {
            if (p_413[0] == 4 && p_413[1] == 19) break;
            if (p_413[2] == 4 && p_413[3] == 19) {
                result_413++;
                break;
            }
            p_413 += 4;
            result_413 += 2;
        }
        if (j_413 == 0) result_413 = -1;
        *(s32 *)(self + 0x14) = result_413;
    }
    {
        s32 *p_514 = lbl_802F4588;
        s32 result_514 = 0;
        s32 j_514;
        for (j_514 = 0x25; j_514 > 0; j_514--) {
            if (p_514[0] == 5 && p_514[1] == 20) break;
            if (p_514[2] == 5 && p_514[3] == 20) {
                result_514++;
                break;
            }
            p_514 += 4;
            result_514 += 2;
        }
        if (j_514 == 0) result_514 = -1;
        *(s32 *)(self + 0x14) = result_514;
    }
    {
        s32 *p_e8b = lbl_802F4588;
        s32 result_e8b = 0;
        s32 j_e8b;
        for (j_e8b = 0x25; j_e8b > 0; j_e8b--) {
            if (p_e8b[0] == 14 && p_e8b[1] == 8) break;
            if (p_e8b[2] == 14 && p_e8b[3] == 8) {
                result_e8b++;
                break;
            }
            p_e8b += 4;
            result_e8b += 2;
        }
        if (j_e8b == 0) result_e8b = -1;
        *(s32 *)(self + 0x14) = result_e8b;
    }
    {
        s32 *p_d8b = lbl_802F4588;
        s32 result_d8b = 0;
        s32 j_d8b;
        for (j_d8b = 0x25; j_d8b > 0; j_d8b--) {
            if (p_d8b[0] == 13 && p_d8b[1] == 8) break;
            if (p_d8b[2] == 13 && p_d8b[3] == 8) {
                result_d8b++;
                break;
            }
            p_d8b += 4;
            result_d8b += 2;
        }
        if (j_d8b == 0) result_d8b = -1;
        *(s32 *)(self + 0x14) = result_d8b;
    }
    {
        s32 *p_e6b = lbl_802F4588;
        s32 result_e6b = 0;
        s32 j_e6b;
        for (j_e6b = 0x25; j_e6b > 0; j_e6b--) {
            if (p_e6b[0] == 14 && p_e6b[1] == 6) break;
            if (p_e6b[2] == 14 && p_e6b[3] == 6) {
                result_e6b++;
                break;
            }
            p_e6b += 4;
            result_e6b += 2;
        }
        if (j_e6b == 0) result_e6b = -1;
        *(s32 *)(self + 0x14) = result_e6b;
    }
    {
        s32 *p_d6b = lbl_802F4588;
        s32 result_d6b = 0;
        s32 j_d6b;
        for (j_d6b = 0x25; j_d6b > 0; j_d6b--) {
            if (p_d6b[0] == 13 && p_d6b[1] == 6) break;
            if (p_d6b[2] == 13 && p_d6b[3] == 6) {
                result_d6b++;
                break;
            }
            p_d6b += 4;
            result_d6b += 2;
        }
        if (j_d6b == 0) result_d6b = -1;
        *(s32 *)(self + 0x14) = result_d6b;
    }
    {
        s32 *p_e8c = lbl_802F4588;
        s32 result_e8c = 0;
        s32 j_e8c;
        for (j_e8c = 0x25; j_e8c > 0; j_e8c--) {
            if (p_e8c[0] == 14 && p_e8c[1] == 8) break;
            if (p_e8c[2] == 14 && p_e8c[3] == 8) {
                result_e8c++;
                break;
            }
            p_e8c += 4;
            result_e8c += 2;
        }
        if (j_e8c == 0) result_e8c = -1;
        *(s32 *)(self + 0x14) = result_e8c;
    }
    {
        s32 *p_d8c = lbl_802F4588;
        s32 result_d8c = 0;
        s32 j_d8c;
        for (j_d8c = 0x25; j_d8c > 0; j_d8c--) {
            if (p_d8c[0] == 13 && p_d8c[1] == 8) break;
            if (p_d8c[2] == 13 && p_d8c[3] == 8) {
                result_d8c++;
                break;
            }
            p_d8c += 4;
            result_d8c += 2;
        }
        if (j_d8c == 0) result_d8c = -1;
        *(s32 *)(self + 0x14) = result_d8c;
    }
    {
        s32 *p_e6c = lbl_802F4588;
        s32 result_e6c = 0;
        s32 j_e6c;
        for (j_e6c = 0x25; j_e6c > 0; j_e6c--) {
            if (p_e6c[0] == 14 && p_e6c[1] == 6) break;
            if (p_e6c[2] == 14 && p_e6c[3] == 6) {
                result_e6c++;
                break;
            }
            p_e6c += 4;
            result_e6c += 2;
        }
        if (j_e6c == 0) result_e6c = -1;
        *(s32 *)(self + 0x14) = result_e6c;
    }
    {
        s32 *p_11cb = lbl_802F4588;
        s32 result_11cb = 0;
        s32 j_11cb;
        for (j_11cb = 0x25; j_11cb > 0; j_11cb--) {
            if (p_11cb[0] == 17 && p_11cb[1] == 12) break;
            if (p_11cb[2] == 17 && p_11cb[3] == 12) {
                result_11cb++;
                break;
            }
            p_11cb += 4;
            result_11cb += 2;
        }
        if (j_11cb == 0) result_11cb = -1;
        *(s32 *)(self + 0x14) = result_11cb;
    }
    {
        s32 *p_12cb = lbl_802F4588;
        s32 result_12cb = 0;
        s32 j_12cb;
        for (j_12cb = 0x25; j_12cb > 0; j_12cb--) {
            if (p_12cb[0] == 18 && p_12cb[1] == 12) break;
            if (p_12cb[2] == 18 && p_12cb[3] == 12) {
                result_12cb++;
                break;
            }
            p_12cb += 4;
            result_12cb += 2;
        }
        if (j_12cb == 0) result_12cb = -1;
        *(s32 *)(self + 0x14) = result_12cb;
    }
    {
        s32 *p_31b = lbl_802F4588;
        s32 result_31b = 0;
        s32 j_31b;
        for (j_31b = 0x25; j_31b > 0; j_31b--) {
            if (p_31b[0] == 3 && p_31b[1] == 1) break;
            if (p_31b[2] == 3 && p_31b[3] == 1) {
                result_31b++;
                break;
            }
            p_31b += 4;
            result_31b += 2;
        }
        if (j_31b == 0) result_31b = -1;
        *(s32 *)(self + 0x14) = result_31b;
    }
    {
        s32 *p_11b = lbl_802F4588;
        s32 result_11b = 0;
        s32 j_11b;
        for (j_11b = 0x25; j_11b > 0; j_11b--) {
            if (p_11b[0] == 1 && p_11b[1] == 1) break;
            if (p_11b[2] == 1 && p_11b[3] == 1) {
                result_11b++;
                break;
            }
            p_11b += 4;
            result_11b += 2;
        }
        if (j_11b == 0) result_11b = -1;
        *(s32 *)(self + 0x14) = result_11b;
    }
    {
        s32 *p_42b = lbl_802F4588;
        s32 result_42b = 0;
        s32 j_42b;
        for (j_42b = 0x25; j_42b > 0; j_42b--) {
            if (p_42b[0] == 4 && p_42b[1] == 2) break;
            if (p_42b[2] == 4 && p_42b[3] == 2) {
                result_42b++;
                break;
            }
            p_42b += 4;
            result_42b += 2;
        }
        if (j_42b == 0) result_42b = -1;
        *(s32 *)(self + 0x14) = result_42b;
    }
    {
        s32 *p_53b = lbl_802F4588;
        s32 result_53b = 0;
        s32 j_53b;
        for (j_53b = 0x25; j_53b > 0; j_53b--) {
            if (p_53b[0] == 5 && p_53b[1] == 3) break;
            if (p_53b[2] == 5 && p_53b[3] == 3) {
                result_53b++;
                break;
            }
            p_53b += 4;
            result_53b += 2;
        }
        if (j_53b == 0) result_53b = -1;
        *(s32 *)(self + 0x14) = result_53b;
    }
    {
        s32 *p_413b = lbl_802F4588;
        s32 result_413b = 0;
        s32 j_413b;
        for (j_413b = 0x25; j_413b > 0; j_413b--) {
            if (p_413b[0] == 4 && p_413b[1] == 19) break;
            if (p_413b[2] == 4 && p_413b[3] == 19) {
                result_413b++;
                break;
            }
            p_413b += 4;
            result_413b += 2;
        }
        if (j_413b == 0) result_413b = -1;
        *(s32 *)(self + 0x14) = result_413b;
    }
    {
        s32 *p_514b = lbl_802F4588;
        s32 result_514b = 0;
        s32 j_514b;
        for (j_514b = 0x25; j_514b > 0; j_514b--) {
            if (p_514b[0] == 5 && p_514b[1] == 20) break;
            if (p_514b[2] == 5 && p_514b[3] == 20) {
                result_514b++;
                break;
            }
            p_514b += 4;
            result_514b += 2;
        }
        if (j_514b == 0) result_514b = -1;
        *(s32 *)(self + 0x14) = result_514b;
    }
    {
        s32 *p_88 = lbl_802F4588;
        s32 result_88 = 0;
        s32 j_88;
        for (j_88 = 0x25; j_88 > 0; j_88--) {
            if (p_88[0] == 8 && p_88[1] == 8) break;
            if (p_88[2] == 8 && p_88[3] == 8) {
                result_88++;
                break;
            }
            p_88 += 4;
            result_88 += 2;
        }
        if (j_88 == 0) result_88 = -1;
        *(s32 *)(self + 0x14) = result_88;
    }
    {
        s32 *p_66 = lbl_802F4588;
        s32 result_66 = 0;
        s32 j_66;
        for (j_66 = 0x25; j_66 > 0; j_66--) {
            if (p_66[0] == 6 && p_66[1] == 6) break;
            if (p_66[2] == 6 && p_66[3] == 6) {
                result_66++;
                break;
            }
            p_66 += 4;
            result_66 += 2;
        }
        if (j_66 == 0) result_66 = -1;
        *(s32 *)(self + 0x14) = result_66;
    }
    {
        s32 *p_30 = lbl_802F4588;
        s32 result_30 = 0;
        s32 j_30;
        for (j_30 = 0x25; j_30 > 0; j_30--) {
            if (p_30[0] == 3 && p_30[1] == 0) break;
            if (p_30[2] == 3 && p_30[3] == 0) {
                result_30++;
                break;
            }
            p_30 += 4;
            result_30 += 2;
        }
        if (j_30 == 0) result_30 = -1;
        *(s32 *)(self + 0x14) = result_30;
    }
    {
        s32 *p_40 = lbl_802F4588;
        s32 result_40 = 0;
        s32 j_40;
        for (j_40 = 0x25; j_40 > 0; j_40--) {
            if (p_40[0] == 4 && p_40[1] == 0) break;
            if (p_40[2] == 4 && p_40[3] == 0) {
                result_40++;
                break;
            }
            p_40 += 4;
            result_40 += 2;
        }
        if (j_40 == 0) result_40 = -1;
        *(s32 *)(self + 0x14) = result_40;
    }
    {
        s32 *p_02 = lbl_802F4588;
        s32 result_02 = 0;
        s32 j_02;
        for (j_02 = 0x25; j_02 > 0; j_02--) {
            if (p_02[0] == 0 && p_02[1] == 2) break;
            if (p_02[2] == 0 && p_02[3] == 2) {
                result_02++;
                break;
            }
            p_02 += 4;
            result_02 += 2;
        }
        if (j_02 == 0) result_02 = -1;
        *(s32 *)(self + 0x14) = result_02;
    }
    {
        s32 *p_01 = lbl_802F4588;
        s32 result_01 = 0;
        s32 j_01;
        for (j_01 = 0x25; j_01 > 0; j_01--) {
            if (p_01[0] == 0 && p_01[1] == 1) break;
            if (p_01[2] == 0 && p_01[3] == 1) {
                result_01++;
                break;
            }
            p_01 += 4;
            result_01 += 2;
        }
        if (j_01 == 0) result_01 = -1;
        *(s32 *)(self + 0x14) = result_01;
    }
    {
        s32 *p_41 = lbl_802F4588;
        s32 result_41 = 0;
        s32 j_41;
        for (j_41 = 0x25; j_41 > 0; j_41--) {
            if (p_41[0] == 4 && p_41[1] == 1) break;
            if (p_41[2] == 4 && p_41[3] == 1) {
                result_41++;
                break;
            }
            p_41 += 4;
            result_41 += 2;
        }
        if (j_41 == 0) result_41 = -1;
        *(s32 *)(self + 0x14) = result_41;
    }
    {
        s32 *p_n14 = lbl_802F4588;
        s32 result_n14 = 0;
        s32 j_n14;
        for (j_n14 = 0x25; j_n14 > 0; j_n14--) {
            if (p_n14[0] == -1 && p_n14[1] == 4) break;
            if (p_n14[2] == -1 && p_n14[3] == 4) {
                result_n14++;
                break;
            }
            p_n14 += 4;
            result_n14 += 2;
        }
        if (j_n14 == 0) result_n14 = -1;
        *(s32 *)(self + 0x14) = result_n14;
    }
    {
        s32 *p_77 = lbl_802F4588;
        s32 result_77 = 0;
        s32 j_77;
        for (j_77 = 0x25; j_77 > 0; j_77--) {
            if (p_77[0] == 7 && p_77[1] == 7) break;
            if (p_77[2] == 7 && p_77[3] == 7) {
                result_77++;
                break;
            }
            p_77 += 4;
            result_77 += 2;
        }
        if (j_77 == 0) result_77 = -1;
        *(s32 *)(self + 0x14) = result_77;
    }
    {
        s32 *p_50 = lbl_802F4588;
        s32 result_50 = 0;
        s32 j_50;
        for (j_50 = 0x25; j_50 > 0; j_50--) {
            if (p_50[0] == 5 && p_50[1] == 0) break;
            if (p_50[2] == 5 && p_50[3] == 0) {
                result_50++;
                break;
            }
            p_50 += 4;
            result_50 += 2;
        }
        if (j_50 == 0) result_50 = -1;
        *(s32 *)(self + 0x14) = result_50;
    }
    {
        s32 *p_60 = lbl_802F4588;
        s32 result_60 = 0;
        s32 j_60;
        for (j_60 = 0x25; j_60 > 0; j_60--) {
            if (p_60[0] == 6 && p_60[1] == 0) break;
            if (p_60[2] == 6 && p_60[3] == 0) {
                result_60++;
                break;
            }
            p_60 += 4;
            result_60 += 2;
        }
        if (j_60 == 0) result_60 = -1;
        *(s32 *)(self + 0x14) = result_60;
    }
    {
        s32 *p_80 = lbl_802F4588;
        s32 result_80 = 0;
        s32 j_80;
        for (j_80 = 0x25; j_80 > 0; j_80--) {
            if (p_80[0] == 8 && p_80[1] == 0) break;
            if (p_80[2] == 8 && p_80[3] == 0) {
                result_80++;
                break;
            }
            p_80 += 4;
            result_80 += 2;
        }
        if (j_80 == 0) result_80 = -1;
        *(s32 *)(self + 0x14) = result_80;
    }
    {
        s32 *p_03 = lbl_802F4588;
        s32 result_03 = 0;
        s32 j_03;
        for (j_03 = 0x25; j_03 > 0; j_03--) {
            if (p_03[0] == 0 && p_03[1] == 3) break;
            if (p_03[2] == 0 && p_03[3] == 3) {
                result_03++;
                break;
            }
            p_03 += 4;
            result_03 += 2;
        }
        if (j_03 == 0) result_03 = -1;
        *(s32 *)(self + 0x14) = result_03;
    }
}

extern "C" void fn_800CA064(void) {
    typedef void (*SetAlarmCallback)(void);
    typedef void (*SetAlarmFn)(OSAlarm *, u32, u32, s32, SetAlarmCallback);
    u32 userData = (u32)((void *(*)(void))((void *(*)(const OSAlarm *))OSGetAlarmUserData))();
    u32 index = userData >> 16;
    u32 low = userData & 0xFFFF;
    void *base = lbl_8055DD98;
    void *entry;
    void *alarm;

    if (fn_80060C7C((void *)index) != 0) {
        entry = *(void **)((u8 *)base + index * 4 + 0x254);
        if (((s32 (*)(void *))fn_800D1548)(entry) != 0) {
            fn_800D120C(entry, *(void **)((u8 *)base + 0x5C0), low);
            return;
        }
    }

    alarm = (u8 *)base + index * 0x30 + 0x4D0;
    OSSetAlarmUserData((OSAlarm *)alarm, (void *)((index << 16) | (index + 2)));
    OSCancelAlarm((OSAlarm *)alarm);
    ((SetAlarmFn)OSSetAlarm)((OSAlarm *)alarm, 0x10624DD3, 0, (((*(volatile u32 *)0x800000F8) >> 2) / 1000U) * 50, fn_800CA064);
}

extern "C" void fn_800D15B4(void*);
extern "C" void fn_800CA148(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800D15B4(OSGetAlarmUserData(alarm));
}

extern "C" void fn_8005EE6C(void);
extern "C" void fn_8005EE70(void);
extern "C" void fn_800CA16C(OSAlarm *alarm, OSContext *ctx) {
    u8 *base = (u8 *)lbl_8055DD98;
    void *userData;
    s32 active;
    u32 ticks;
    u32 period;

    userData = OSGetAlarmUserData(alarm);
    active = 0;
    if (userData == 0) {
        if (((s32 (*)(void))fn_8005EE6C)() != 0) {
            base[0x89] = 1;
            active = 1;
        }
    } else if (((s32 (*)(void))fn_8005EE70)() != 0) {
        active = 1;
    }

    if (active == 0) {
        OSCancelAlarm((OSAlarm *)(base + 0x590));
        OSSetAlarmUserData((OSAlarm *)(base + 0x590), userData);
        ticks = *(volatile u32 *)0x800000F8;
        period = ((ticks >> 2) / 1000U) * 100;
        ((void (*)(OSAlarm *, u32, u32, s32, OSAlarmHandler))OSSetAlarm)(
            (OSAlarm *)(base + 0x590), 0x10624DD3, 0, period, fn_800CA16C);
    }
}

extern "C" void fn_800CA234(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        *(u8 *)((u8 *)lbl_8055DD98 + 0x8a) = 1;
    }
    void *vt = *(void **)((u8 *)lbl_8055DD98 + 0x1b8);
    if (vt == NULL) {
        return;
    }
    (*(void (*)(s32, s32))vt)(arg0, arg1);
}

extern "C" void fn_800CF3EC(void *);
extern "C" void fn_800D1204(void *, f32);
extern "C" void fn_800D120C(void *, void *, s32);
extern "C" void fn_800CAB04(void *arg0, s32 arg1) {
    class VirtualHandler {
    public:
        virtual ~VirtualHandler();
        virtual void vf1();
        virtual void vf2();
        virtual void vf3();
        virtual void vf4();
        virtual void vf5();
        virtual void vf6();
        virtual void vf7();
        virtual void vf8();
        virtual void vf9(s32, s32, s32, s32, void*, f32, f32);
    };

    if (*(s32 *)((u8 *)arg0 + 0x10) == 2) {
        void *temp_r3 = ((void *(*)(void *))fn_800D1558)(*(void **)((u8 *)arg0 + 0x254 + arg1 * 4));
        f32 f1 = (608.0f * *(f32 *)((u8 *)temp_r3 + 8)) * 0.5f;
        f32 f3 = (456.0f * *(f32 *)((u8 *)temp_r3 + 0xc)) * 0.5f;
        if (*(u8 *)((u8 *)arg0 + 0x87) != 0) {
            void *obj4 = *(void **)((u8 *)arg0 + 4);
            f1 *= *(f32 *)((u8 *)obj4 + 0x2c);
            f3 *= *(f32 *)((u8 *)obj4 + 0x30);
        }
        s32 r5 = *(s32 *)((u8 *)temp_r3 + 0x10);
        s32 r6 = *(s32 *)((u8 *)temp_r3 + 0x14);
        s32 r7 = *(s32 *)((u8 *)temp_r3 + 0x18);
        (*(VirtualHandler **)((u8 *)arg0 + 0x1f8))->vf9(arg1, r5, r6, r7, temp_r3, f1, -f3);

        s32 mask = *(s32 *)((u8 *)temp_r3 + 0x10);
        if (((mask & 0x10008000) != 0) && (*(s32 *)((u8 *)arg0 + 0x10) == 2)) {
            s32 st = *(s32 *)arg0;
            if (st == 1) {
                (*(VirtualHandler **)((u8 *)arg0 + 0x1f8))->vf9(arg1, 0, 0, 0, 0, 0.0f, -180.0f);
                *(s32 *)((u8 *)arg0 + 0x14) = 2;
                void *c3c8 = *(void **)((u8 *)arg0 + 0x3c8);
                fn_800CF3EC(c3c8);
                *(s32 *)((u8 *)c3c8 + 0x14) = 1;
                void *c3ec = *(void **)((u8 *)arg0 + 0x3ec);
                fn_800CF3EC(c3ec);
                *(s32 *)((u8 *)c3ec + 0x14) = 1;
                *(s32 *)((u8 *)arg0 + 0x10) = 0xa;
                *(s32 *)arg0 = 0;
                {
                    void *obj4 = *(void **)((u8 *)arg0 + 4);
                    s32 res = 0;
                    typedef s32 (*CbFunc)(s32, s32);
                    CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                    if (cb != 0) res = cb(5, 8);
                    if (res == 0) {
                        void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                        void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                        if (snd5c0 != 0 && snd5d4 != 0) {
                            DetachSound__Q34nw4r3snd11SoundHandleFv();
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 8, 0, 0, 0);
                        }
                    }
                }
                return;
            } else if (st == 0) {
                void *c3cc = *(void **)((u8 *)arg0 + 0x3cc);
                if (*(s32 *)((u8 *)c3cc + 0x14) == 1) {
                    *(s32 *)((u8 *)c3cc + 0x14) = 0;
                }
                void *c3f0 = *(void **)((u8 *)arg0 + 0x3f0);
                if (*(s32 *)((u8 *)c3f0 + 0x14) == 1) {
                    *(s32 *)((u8 *)c3f0 + 0x14) = 0;
                }
                *(s32 *)((u8 *)arg0 + 0xac) = 0;
                *(s32 *)((u8 *)arg0 + 0x14) = 4;
                void *c3d0 = *(void **)((u8 *)arg0 + 0x3d0);
                fn_800CF3EC(c3d0);
                *(s32 *)((u8 *)c3d0 + 0x14) = 1;
                *(s32 *)((u8 *)arg0 + 0x10) = 0xe;
                {
                    void *obj4 = *(void **)((u8 *)arg0 + 4);
                    s32 res = 0;
                    typedef s32 (*CbFunc)(s32, s32);
                    CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                    if (cb != 0) res = cb(5, 1);
                    if (res == 0) {
                        void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                        void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                        if (snd5c0 != 0 && snd5d4 != 0) {
                            DetachSound__Q34nw4r3snd11SoundHandleFv();
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 1, 0, 0, 0);
                        }
                    }
                }
                return;
            }
        } else if (*(s32 *)arg0 == 1 && *(s32 *)((u8 *)arg0 + 0x10) == 2) {
            if ((mask & 0x11000) != 0) {
                s32 cnt = *(s32 *)((u8 *)arg0 + 0x80);
                if (cnt > 0) {
                    cnt--;
                    *(s32 *)((u8 *)arg0 + 0x80) = cnt;
                    s32 idx1 = -1;
                    s32 *p = (s32 *)lbl_802F4588;
                    for (s32 i = 0; i < 37 * 2; i++, p += 2) {
                        if (p[0] == cnt + 0x15 && p[1] == 0xa) { idx1 = i; break; }
                    }
                    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x298 + idx1 * 4) + 0x14) = 0;

                    s32 idx2 = -1;
                    p = (s32 *)lbl_802F4588;
                    for (s32 i = 0; i < 37 * 2; i++, p += 2) {
                        if (p[0] == *(s32 *)((u8 *)arg0 + 0x80) + 0x15 && p[1] == 9) { idx2 = i; break; }
                    }
                    void *p2 = *(void **)((u8 *)arg0 + 0x298 + idx2 * 4);
                    fn_800CF3EC(p2);
                    *(s32 *)((u8 *)p2 + 0x14) = 1;

                    s32 idx3 = -1;
                    p = (s32 *)lbl_802F4588;
                    for (s32 i = 0; i < 37 * 2; i++, p += 2) {
                        if (p[0] == 0xb && p[1] == 5) { idx3 = i; break; }
                    }
                    void *p3 = *(void **)((u8 *)arg0 + 0x298 + idx3 * 4);
                    fn_800CF3EC(p3);
                    *(s32 *)((u8 *)p3 + 0x14) = 1;

                    if (*(s32 *)((u8 *)arg0 + 0x80) == 0) {
                        {
                            void *obj4 = *(void **)((u8 *)arg0 + 4);
                            s32 res = 0;
                            typedef s32 (*CbFunc)(s32, s32);
                            CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                            if (cb != 0) res = cb(5, 0xc);
                            if (res == 0) {
                                void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                                void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                                if (snd5c0 != 0 && snd5d4 != 0) {
                                    DetachSound__Q34nw4r3snd11SoundHandleFv();
                                    detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 0xc, 0, 0, 0);
                                }
                            }
                        }
                        for (s32 i = 0; i < 4; i++) {
                            void *ctrl = *(void **)((u8 *)arg0 + 0x254 + i * 4);
                            fn_800D1204(ctrl, (f32)*(s32 *)((u8 *)arg0 + 0x80) / 10.0f);
                            fn_800D120C(ctrl, *(void **)((u8 *)arg0 + 0x5c0), 1);
                        }
                        return;
                    }
                    {
                        void *obj4 = *(void **)((u8 *)arg0 + 4);
                        s32 res = 0;
                        typedef s32 (*CbFunc)(s32, s32);
                        CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                        if (cb != 0) res = cb(5, 0xa);
                        if (res == 0) {
                            void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                            void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                            if (snd5c0 != 0 && snd5d4 != 0) {
                                DetachSound__Q34nw4r3snd11SoundHandleFv();
                                detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 0xa, 0, 0, 0);
                            }
                        }
                    }
                    for (s32 i = 0; i < 4; i++) {
                        void *ctrl = *(void **)((u8 *)arg0 + 0x254 + i * 4);
                        fn_800D1204(ctrl, (f32)*(s32 *)((u8 *)arg0 + 0x80) / 10.0f);
                        fn_800D120C(ctrl, *(void **)((u8 *)arg0 + 0x5c0), 1);
                    }
                    return;
                }
                {
                    void *obj4 = *(void **)((u8 *)arg0 + 4);
                    s32 res = 0;
                    typedef s32 (*CbFunc)(s32, s32);
                    CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                    if (cb != 0) res = cb(5, 0xd);
                    if (res == 0) {
                        void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                        void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                        if (snd5c0 != 0 && snd5d4 != 0) {
                            DetachSound__Q34nw4r3snd11SoundHandleFv();
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 0xd, 0, 0, 0);
                        }
                    }
                }
            } else if ((mask & 0x20010) != 0) {
                s32 cnt = *(s32 *)((u8 *)arg0 + 0x80);
                if (cnt < 10) {
                    s32 idx1 = -1;
                    s32 *p = (s32 *)lbl_802F4588;
                    for (s32 i = 0; i < 37 * 2; i++, p += 2) {
                        if (p[0] == cnt + 0x15 && p[1] == 9) { idx1 = i; break; }
                    }
                    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x298 + idx1 * 4) + 0x14) = 0;

                    s32 idx2 = -1;
                    p = (s32 *)lbl_802F4588;
                    for (s32 i = 0; i < 37 * 2; i++, p += 2) {
                        if (p[0] == *(s32 *)((u8 *)arg0 + 0x80) + 0x15 && p[1] == 0xa) { idx2 = i; break; }
                    }
                    void *p2 = *(void **)((u8 *)arg0 + 0x298 + idx2 * 4);
                    fn_800CF3EC(p2);
                    *(s32 *)((u8 *)p2 + 0x14) = 1;

                    *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)arg0 + 0x80) + 1;

                    s32 idx3 = -1;
                    p = (s32 *)lbl_802F4588;
                    for (s32 i = 0; i < 37 * 2; i++, p += 2) {
                        if (p[0] == 0xc && p[1] == 5) { idx3 = i; break; }
                    }
                    void *p3 = *(void **)((u8 *)arg0 + 0x298 + idx3 * 4);
                    fn_800CF3EC(p3);
                    *(s32 *)((u8 *)p3 + 0x14) = 1;

                    if (*(s32 *)((u8 *)arg0 + 0x80) == 10) {
                        {
                            void *obj4 = *(void **)((u8 *)arg0 + 4);
                            s32 res = 0;
                            typedef s32 (*CbFunc)(s32, s32);
                            CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                            if (cb != 0) res = cb(5, 0xb);
                            if (res == 0) {
                                void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                                void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                                if (snd5c0 != 0 && snd5d4 != 0) {
                                    DetachSound__Q34nw4r3snd11SoundHandleFv();
                                    detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 0xb, 0, 0, 0);
                                }
                            }
                        }
                        for (s32 i = 0; i < 4; i++) {
                            void *ctrl = *(void **)((u8 *)arg0 + 0x254 + i * 4);
                            fn_800D1204(ctrl, (f32)*(s32 *)((u8 *)arg0 + 0x80) / 10.0f);
                            fn_800D120C(ctrl, *(void **)((u8 *)arg0 + 0x5c0), 1);
                        }
                        return;
                    }
                    {
                        void *obj4 = *(void **)((u8 *)arg0 + 4);
                        s32 res = 0;
                        typedef s32 (*CbFunc)(s32, s32);
                        CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                        if (cb != 0) res = cb(5, 9);
                        if (res == 0) {
                            void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                            void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                            if (snd5c0 != 0 && snd5d4 != 0) {
                                DetachSound__Q34nw4r3snd11SoundHandleFv();
                                detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 9, 0, 0, 0);
                            }
                        }
                    }
                    for (s32 i = 0; i < 4; i++) {
                        void *ctrl = *(void **)((u8 *)arg0 + 0x254 + i * 4);
                        fn_800D1204(ctrl, (f32)*(s32 *)((u8 *)arg0 + 0x80) / 10.0f);
                        fn_800D120C(ctrl, *(void **)((u8 *)arg0 + 0x5c0), 1);
                    }
                    return;
                }
                {
                    void *obj4 = *(void **)((u8 *)arg0 + 4);
                    s32 res = 0;
                    typedef s32 (*CbFunc)(s32, s32);
                    CbFunc cb = *(CbFunc *)((u8 *)obj4 + 0x14);
                    if (cb != 0) res = cb(5, 0xd);
                    if (res == 0) {
                        void *snd5c0 = *(void **)((u8 *)arg0 + 0x5c0);
                        void *snd5d4 = *(void **)((u8 *)arg0 + 0x5d4);
                        if (snd5c0 != 0 && snd5d4 != 0) {
                            DetachSound__Q34nw4r3snd11SoundHandleFv();
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((u8 *)snd5c0 + 0xc, snd5d4, 0xd, 0, 0, 0);
                        }
                    }
                }
            }
        }
    } else if (*(s32 *)arg0 == 1 && *(s32 *)((u8 *)arg0 + 0x10) == 5) {
        s32 off = *(s32 *)((u8 *)arg0 + 0x14);
        void *p3c0 = *(void **)((u8 *)arg0 + 0x3c0 + off * 4);
        if (*(s32 *)((u8 *)p3c0 + 0x14) != 1) {
            void *tr3 = ((void *(*)(void *))fn_800D1558)(*(void **)((u8 *)arg0 + 0x254 + arg1 * 4));
            if (*(s32 *)((u8 *)tr3 + 0x10) != 0) {
                *(s32 *)((u8 *)arg0 + 0x18) = 0xe10;
            }
        }
    }
}

void homebutton::HomeButton::updateTrigPane() {
    s32 state = *(s32 *)this;
    switch (state) {
    case 0: {
        s32 i = 0;
        do {
            if (i < 2 || i == 9) {
                (*(PaneSearch **)((u8 *)this + 0x1F8))->getPane(
                    ((HomeButtonPaneAccessor *)(*(void **)((u8 *)this + 0x1E0)))->lookup->findPane(lbl_8031E218[i], 1)
                )->setTrigger(1);
            } else {
                (*(PaneSearch **)((u8 *)this + 0x1F8))->getPane(
                    ((HomeButtonPaneAccessor *)(*(void **)((u8 *)this + 0x1E0)))->lookup->findPane(lbl_8031E218[i], 1)
                )->setTrigger(0);
            }
            ++i;
        } while (i < 10);
        break;
    }
    case 1: {
        s32 i = 0;
        do {
            if ((i > 0 && i < 7) || i == 9) {
                (*(PaneSearch **)((u8 *)this + 0x1F8))->getPane(
                    ((HomeButtonPaneAccessor *)(*(void **)((u8 *)this + 0x1E0)))->lookup->findPane(lbl_8031E218[i], 1)
                )->setTrigger(1);
            } else {
                (*(PaneSearch **)((u8 *)this + 0x1F8))->getPane(
                    ((HomeButtonPaneAccessor *)(*(void **)((u8 *)this + 0x1E0)))->lookup->findPane(lbl_8031E218[i], 1)
                )->setTrigger(0);
            }
            ++i;
        } while (i < 10);
        break;
    }
    case 2: {
        s32 i = 0;
        do {
            if (i < 7 || i == 9) {
                (*(PaneSearch **)((u8 *)this + 0x1F8))->getPane(
                    ((HomeButtonPaneAccessor *)(*(void **)((u8 *)this + 0x1E0)))->lookup->findPane(lbl_8031E218[i], 1)
                )->setTrigger(0);
            } else {
                (*(PaneSearch **)((u8 *)this + 0x1F8))->getPane(
                    ((HomeButtonPaneAccessor *)(*(void **)((u8 *)this + 0x1E0)))->lookup->findPane(lbl_8031E218[i], 1)
                )->setTrigger(1);
            }
            ++i;
        } while (i < 10);
        break;
    }
    }
}

extern "C" s32 lbl_802F4528[];
extern "C" f32 lbl_80560E18;
#pragma push
#pragma dont_inline on
extern "C" f32 lbl_80560DC8;
extern "C" void fn_800CB820(void *arg0, const char *arg1, void *arg2) {
    s32 paneNo = ((homebutton::HomeButton *)arg0)->getPaneNo(arg1);
    u32 changed = 0;
    if (*(s32 *)(((u8 *)arg0) + 0x10) == 2 && paneNo != -1 &&
        *(s32 *)(((u8 *)arg0) + 0x1C + paneNo * 4) == 0) {
        if (*(s32 *)((u8 *)arg0) != 2 && paneNo < *(s32 *)(((u8 *)arg0) + 8)) {
            s32 i;
            s32 count = *(s32 *)(((u8 *)arg0) + 0x0C);
            s32 *entry = lbl_802F4528;
            for (i = 0; i < count; ++i, entry += 2) {
                if (paneNo != entry[0])
                    continue;
                if (entry[1] == 0)
                    goto found_entry;
            }
            i = -1;
found_entry:
            void *pane = *(void **)(((u8 *)arg0) + 0x268 + i * 4);
            fn_800CF3EC(pane);
            *(s32 *)((u8 *)pane + 0x14) = 1;
            if (*(s32 *)((u8 *)arg0) == 0) {
                if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                    void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    if (callback != 0 && callback(5, 4) == 0 &&
                        *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                        *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                            *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                    }
                    *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                }
                changed = 1;
            }
        } else {
            switch (paneNo - *(s32 *)(((u8 *)arg0) + 8)) {
            case 0: {
                if (arg2 == 0) {
                    s32 activate = 1;
                    if (*(s32 *)((u8 *)arg0) == 2) {
                        void *left = *(void **)(((u8 *)arg0) + 0x3F0);
                        if (*(s32 *)((u8 *)left + 0x14) != 1) {
                            void *right = *(void **)(((u8 *)arg0) + 0x3CC);
                            if (*(s32 *)((u8 *)right + 0x14) != 1)
                                activate = 0;
                        }
                    }
                    if (activate) {
                        void *right = *(void **)(((u8 *)arg0) + 0x3CC);
                        fn_800CF3EC(right);
                        *(s32 *)((u8 *)right + 0x14) = 1;
                        *(s32 *)(((u8 *)arg0) + 0x70) = 3;
                        *(s32 *)(((u8 *)arg0) + 0x68) = 0;
                        if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                            void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                            s32 (*callback)(s32, s32) =
                                *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                            s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                            if (result == 0 &&
                                *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                                *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                                ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                                detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                    (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                    *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                            }
                            *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                        }
                        changed = 1;
                    } else {
                        *(s32 *)(((u8 *)arg0) + 0x68) = 3;
                    }
                }
                break;
            }
            case 1: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 2)
                            goto found_case1_0;
                        ++index;
                        if (entry[2] == 4 && entry[3] == 2)
                            goto found_case1_0;
                        ++index;
                    }
                    index = -1;
found_case1_0:;
                    s32 indexA = 0;
                    s32 indexB = 0;
                    s32 indexC = 0;
                    s32 indexD = 0;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 2)
                            goto found_case1_1;
                        ++indexA;
                        if (entry[2] == 4 && entry[3] == 2)
                            goto found_case1_1;
                        ++indexA;
                    }
                    indexA = -1;
found_case1_1:;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 5 && entry[1] == 3)
                            goto found_case1_2;
                        ++indexB;
                        if (entry[2] == 5 && entry[3] == 3)
                            goto found_case1_2;
                        ++indexB;
                    }
                    indexB = -1;
found_case1_2:;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 0x13)
                            goto found_case1_3;
                        ++indexC;
                        if (entry[2] == 4 && entry[3] == 0x13)
                            goto found_case1_3;
                        ++indexC;
                    }
                    indexC = -1;
found_case1_3:;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 5 && entry[1] == 0x14)
                            goto found_case1_4;
                        ++indexD;
                        if (entry[2] == 5 && entry[3] == 0x14)
                            goto found_case1_4;
                        ++indexD;
                    }
                    indexD = -1;
found_case1_4:;
                    if (*(s32 *)arg0 == 2 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexA * 4) + 0x14) != 1 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexB * 4) + 0x14) != 1 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexC * 4) + 0x14) != 1 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexD * 4) + 0x14) != 1) {
                        *(s32 *)(((u8 *)arg0) + 0x6C) = index;
                    } else {
                        void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                        fn_800CF3EC(pane);
                        *(s32 *)((u8 *)pane + 0x14) = 1;
                        *(s32 *)(((u8 *)arg0) + 0x74) = index;
                        *(s32 *)(((u8 *)arg0) + 0x6C) = 0;
                        if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                            void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                            s32 (*callback)(s32, s32) =
                                *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                            if (callback != 0 && callback(5, 4) == 0 &&
                                *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                                *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                                ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                                detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                    (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                    *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                            }
                            *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                        }
                        changed = 1;
                    }
                }
                if ((s32)arg2 == 1) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 0x13)
                            goto found_case1b_0;
                        ++index;
                        if (entry[2] == 4 && entry[3] == 2)
                            goto found_case1b_0;
                        ++index;
                    }
                    index = -1;
found_case1b_0:;
                    s32 indexA = 0;
                    s32 indexB = 0;
                    s32 indexC = 0;
                    s32 indexD = 0;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 2)
                            goto found_case1b_1;
                        ++indexA;
                        if (entry[2] == 4 && entry[3] == 2)
                            goto found_case1b_1;
                        ++indexA;
                    }
                    indexA = -1;
found_case1b_1:;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 5 && entry[1] == 3)
                            goto found_case1b_2;
                        ++indexB;
                        if (entry[2] == 5 && entry[3] == 3)
                            goto found_case1b_2;
                        ++indexB;
                    }
                    indexB = -1;
found_case1b_2:;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 0x13)
                            goto found_case1b_3;
                        ++indexC;
                        if (entry[2] == 4 && entry[3] == 0x13)
                            goto found_case1b_3;
                        ++indexC;
                    }
                    indexC = -1;
found_case1b_3:;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 5 && entry[1] == 0x14)
                            goto found_case1b_4;
                        ++indexD;
                        if (entry[2] == 5 && entry[3] == 0x14)
                            goto found_case1b_4;
                        ++indexD;
                    }
                    indexD = -1;
found_case1b_4:;
                    if (*(s32 *)arg0 == 2 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexA * 4) + 0x14) != 1 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexB * 4) + 0x14) != 1 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexC * 4) + 0x14) != 1 &&
                        *(s32 *)((u8 *)*(void **)(((u8 *)arg0) + 0x298 + indexD * 4) + 0x14) != 1) {
                        *(s32 *)(((u8 *)arg0) + 0x6C) = index;
                    } else {
                        void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                        fn_800CF3EC(pane);
                        *(s32 *)((u8 *)pane + 0x14) = 1;
                        *(s32 *)(((u8 *)arg0) + 0x74) = index;
                        *(s32 *)(((u8 *)arg0) + 0x6C) = 0;
                        if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                            void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                            s32 (*callback)(s32, s32) =
                                *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                            if (callback != 0 && callback(5, 4) == 0 &&
                                *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                                *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                                ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                                detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                    (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                    *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                            }
                            *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                        }
                        changed = 1;
                    }
                }
                break;
            }
            case 2: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 0x13)
                            goto found_entry_1;
                        ++index;
                        if (entry[2] == 4 && entry[3] == 0x13)
                            goto found_entry_1;
                        ++index;
                    }
                    index = -1;
found_entry_1:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    if (*(s32 *)((u8 *)pane + 0x14) != 1) {
                        fn_800CF3EC(pane);
                        *(s32 *)((u8 *)pane + 0x14) = 1;
                        changed = 1;
                    }
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                    *(s32 *)(((u8 *)arg0) + 0x70) = 2;
                    *(s32 *)(((u8 *)arg0) + 0x68) = 0;
                }
                break;
            }
            case 3: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 5 && entry[1] == 3)
                            goto found_entry_2;
                        ++index;
                        if (entry[2] == 5 && entry[3] == 3)
                            goto found_entry_2;
                        ++index;
                    }
                    index = -1;
found_entry_2:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    if (*(s32 *)((u8 *)pane + 0x14) != 1) {
                        fn_800CF3EC(pane);
                        *(s32 *)((u8 *)pane + 0x14) = 1;
                        changed = 1;
                    }
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                    *(s32 *)(((u8 *)arg0) + 0x70) = 3;
                    *(s32 *)(((u8 *)arg0) + 0x68) = 0;
                }
                break;
            }
            case 4: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 4 && entry[1] == 0x13)
                            goto found_entry_3;
                        ++index;
                        if (entry[2] == 4 && entry[3] == 0x13)
                            goto found_entry_3;
                        ++index;
                    }
                    index = -1;
found_entry_3:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    if (*(s32 *)((u8 *)pane + 0x14) != 1) {
                        fn_800CF3EC(pane);
                        *(s32 *)((u8 *)pane + 0x14) = 1;
                        changed = 1;
                    }
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                    *(s32 *)(((u8 *)arg0) + 0x70) = 4;
                    *(s32 *)(((u8 *)arg0) + 0x68) = 0;
                }
                break;
            }
            case 5: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 5 && entry[1] == 0x14)
                            goto found_entry_4;
                        ++index;
                        if (entry[2] == 5 && entry[3] == 0x14)
                            goto found_entry_4;
                        ++index;
                    }
                    index = -1;
found_entry_4:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    if (*(s32 *)((u8 *)pane + 0x14) != 1) {
                        fn_800CF3EC(pane);
                        *(s32 *)((u8 *)pane + 0x14) = 1;
                        changed = 1;
                    }
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                    *(s32 *)(((u8 *)arg0) + 0x70) = 5;
                    *(s32 *)(((u8 *)arg0) + 0x68) = 0;
                }
                break;
            }
            case 6: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 6 && entry[1] == 4)
                            goto found_entry_5;
                        ++index;
                        if (entry[2] == 6 && entry[3] == 4)
                            goto found_entry_5;
                        ++index;
                    }
                    index = -1;
found_entry_5:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    fn_800CF3EC(pane);
                    *(s32 *)((u8 *)pane + 0x14) = 1;
                    changed = 1;
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                }
                break;
            }
            case 7: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 7 && entry[1] == 4)
                            goto found_entry_6;
                        ++index;
                        if (entry[2] == 7 && entry[3] == 4)
                            goto found_entry_6;
                        ++index;
                    }
                    index = -1;
found_entry_6:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    fn_800CF3EC(pane);
                    *(s32 *)((u8 *)pane + 0x14) = 1;
                    changed = 1;
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                }
                break;
            }
            case 8: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 8 && entry[1] == 4)
                            goto found_entry_7;
                        ++index;
                        if (entry[2] == 8 && entry[3] == 4)
                            goto found_entry_7;
                        ++index;
                    }
                    index = -1;
found_entry_7:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    fn_800CF3EC(pane);
                    *(s32 *)((u8 *)pane + 0x14) = 1;
                    changed = 1;
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                }
                break;
            }
            case 9: {
                if (arg2 == 0) {
                    s32 i;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    for (i = 0; i < 0x25; ++i, entry += 4) {
                        if (entry[0] == 9 && entry[1] == 4)
                            goto found_entry_8;
                        ++index;
                        if (entry[2] == 9 && entry[3] == 4)
                            goto found_entry_8;
                        ++index;
                    }
                    index = -1;
found_entry_8:;
                    void *pane = *(void **)(((u8 *)arg0) + 0x298 + index * 4);
                    fn_800CF3EC(pane);
                    *(s32 *)((u8 *)pane + 0x14) = 1;
                    changed = 1;
                    if (*(s32 *)(((u8 *)arg0) + 0x64) > 2) {
                        void *callbackObject = *(void **)(((u8 *)arg0) + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                            if (callback != 0)
                                result = callback(5, 4);
                        if (result == 0 &&
                            *(void **)(((u8 *)arg0) + 0x5C0) != 0 &&
                            *(void **)(((u8 *)arg0) + 0x5D4) != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(*(void **)(((u8 *)arg0) + 0x5D4));
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)*(void **)(((u8 *)arg0) + 0x5C0) + 0xC,
                                *(void **)(((u8 *)arg0) + 0x5D4), 4, 0, 0, 0);
                        }
                        *(s32 *)(((u8 *)arg0) + 0x64) = 0;
                    }
                }
                break;
            }
            }
        }
    }
    if (paneNo == *(s32 *)(((u8 *)arg0) + 8) + 1 || paneNo == *(s32 *)(((u8 *)arg0) + 8) + 9) {
        s32 base = *(s32 *)(((u8 *)arg0) + 8);
        ++*(s32 *)(((u8 *)arg0) + 0x20 + base * 4);
        ++*(s32 *)(((u8 *)arg0) + 0x40 + base * 4);
    } else {
        ++*(s32 *)(((u8 *)arg0) + 0x1C + paneNo * 4);
    }
    if (arg2 != 0 && changed) {
        s32 i = *(s32 *)arg2;
        void *pane = *(void **)(((u8 *)arg0) + 0x254 + i * 4);
        if (*(u8 *)((u8 *)pane + 0x1C) == 0 &&
            *(f32 *)(((u8 *)arg0) + 0x1CC + i * 4) <= 0.0f) {
            *(f32 *)(((u8 *)arg0) + 0x1BC + i * 4) = lbl_80560E18;
            fn_800D155C(pane);
        }
    }
}

extern "C" s32 getPaneNo__Q210homebutton10HomeButtonFPCc(void *, const char *);
extern "C" void fn_80060750(void *);
extern "C" const char *lbl_8031E264[];
extern "C" void fn_800CD38C(const char *selfArg, const char *paneName) {
    s32 i;
    f32 f;
    u32 bits;
    void *obj;
    register u8 *self;
    register s32 pane;
    self = (u8 *)selfArg;
    pane = ((homebutton::HomeButton *)selfArg)->getPaneNo(paneName);
    if (*(s32 *)(self + 0x10) == 2 && pane != -1) {
        if (*(s32 *)self == 0 && pane < *(s32 *)(self + 8)) {
            s32 count = *(s32 *)(self + 0xC);
            *(s32 *)(self + 0xAC) = pane + 1;
            s32 key = pane + 4;
            s32 index = 0;
            s32 *entry = lbl_802F4528;
            for (i = 0; i < count; i++, entry += 2) {
                if (entry[0] == key && entry[1] == 1)
                    goto found_entry;
                index++;
            }
            index = -1;
        found_entry:;
            *(s32 *)(self + 0x14) = index;
            void *obj = *(void **)(self + 0x268 + index * 4);
            fn_800CF3EC(obj);
            *(s32 *)((u8 *)obj + 0x14) = 1;
            void *callbackObject = *(void **)(self + 4);
            s32 (*callback)(s32, s32) =
                *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
            s32 result = 0;
            if (callback != 0)
                result = callback(5, 5);
            void *soundHandle = *(void **)(self + 0x5C0);
            void *sound = *(void **)(self + 0x5D4);
            if (result == 0 && soundHandle != 0 && sound != 0) {
                ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                    (u8 *)soundHandle + 0xC, sound, 5, 0, 0, 0);
            }
            if (*(s32 *)(self + 0x94 + pane * 4) != 0) {
                *(s32 *)(self + 0x10) = 0xB;
                *(s32 *)self = 2;
            }
        } else {
            switch (pane - *(s32 *)(self + 8)) {
            case 0: {
                void *left = *(void **)(self + 0x3F0);
                if (*(s32 *)((u8 *)left + 0x14) == 1)
                    *(s32 *)((u8 *)left + 0x14) = 0;
                void *right = *(void **)(self + 0x3CC);
                if (*(s32 *)((u8 *)right + 0x14) == 1)
                    *(s32 *)((u8 *)right + 0x14) = 0;
                *(s32 *)(self + 0xAC) = 0;
                *(s32 *)(self + 0x14) = 4;
                void *obj = *(void **)(self + 0x3D0);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                *(s32 *)(self + 0x10) = 0xE;
                void *callbackObject = *(void **)(self + 4);
                s32 (*callback)(s32, s32) =
                    *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                s32 result = 0;
                if (callback != 0)
                    result = callback(5, 1);
                void *soundHandle = *(void **)(self + 0x5C0);
                void *sound = *(void **)(self + 0x5D4);
                if (result == 0 && soundHandle != 0 && sound != 0) {
                    ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                    detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                        (u8 *)soundHandle + 0xC, sound, 1, 0, 0, 0);
                }
                break;
            }
            case 1: {
                *(s32 *)(self + 0x14) = 2;
                void *obj = *(void **)(self + 0x3C8);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                obj = *(void **)(self + 0x3EC);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                *(s32 *)(self + 0x10) = 0xA;
                *(s32 *)self = 0;
                void *callbackObject = *(void **)(self + 4);
                s32 (*callback)(s32, s32) =
                    *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                s32 result = 0;
                if (callback != 0)
                    result = callback(5, 8);
                void *soundHandle = *(void **)(self + 0x5C0);
                void *sound = *(void **)(self + 0x5D4);
                if (result == 0 && soundHandle != 0 && sound != 0) {
                    ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                    detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                        (u8 *)soundHandle + 0xC, sound, 8, 0, 0, 0);
                }
                if (*(s32 *)(self + 0x80) != 0) {
                    for (i = 0; i < 4; i++) {
                        bits = *(u32 *)(self + 0x80) ^ 0x80000000;
                        f = ((f32)(s32)bits - 2147483648.0f) / lbl_80560DE4;
                        obj = *(void **)(self + 0x254 + i * 4);
                        fn_800D1204(obj, f);
                        fn_800D120C(obj, *(void **)(self + 0x5C0), 1);
                    }
                }
                break;
            }
            case 2: {
                void *obj = *(void **)(self + 0x3C4);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                *(s32 *)(self + 0x14) = 9;
                obj = *(void **)(self + 0x3E4);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                *(s32 *)(self + 0x10) = 0xA;
                void *accessor = *(void **)(self + 0x1E0);
                void *lookupObject = *(void **)((u8 *)accessor + 0x10);
                void **lookupVtable = *(void ***)lookupObject;
                void *(*findPane)(void *, const char *, s32) =
                    (void *(*)(void *, const char *, s32))lookupVtable[0x3C / 4];
                for (s32 i = 2; i < 7; i++) {
                    void *paneObject = findPane(lookupObject, lbl_8031E218[i], 1);
                    u8 *trigger = (u8 *)paneObject + 0xCF;
                    *trigger = (*trigger & 0xFE) | 1;
                }
                *(s32 *)self = 1;
                void *callbackObject = *(void **)(self + 4);
                s32 (*callback)(s32, s32) =
                    *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                s32 result = 0;
                if (callback != 0)
                    result = callback(5, 5);
                void *soundHandle = *(void **)(self + 0x5C0);
                void *sound = *(void **)(self + 0x5D4);
                if (result == 0 && soundHandle != 0 && sound != 0) {
                    ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                    detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                        (u8 *)soundHandle + 0xC, sound, 5, 0, 0, 0);
                }
                if (*(s32 *)(self + 0x80) != 0) {
                    for (i = 0; i < 4; i++) {
                        bits = *(u32 *)(self + 0x80) ^ 0x80000000;
                        f = ((f32)(s32)bits - 2147483648.0f) / lbl_80560DE4;
                        obj = *(void **)(self + 0x254 + i * 4);
                        fn_800D1204(obj, f);
                        fn_800D120C(obj, *(void **)(self + 0x5C0), 1);
                    }
                }
                break;
            }
            case 3: {
                s32 value = *(s32 *)(self + 0x80);
                if (value > 0) {
                    value -= 1;
                    *(s32 *)(self + 0x80) = value;
                    s32 key = value + 0x15;
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    s32 i;
                    for (i = 0; i < 0x25; i++, entry += 4) {
                        if (entry[0] == key && entry[1] == 0xA)
                            goto found_ten;
                        index += 1;
                        if (entry[2] == key && entry[3] == 0xA)
                            goto found_ten;
                        index += 1;
                    }
                    index = -1;
                found_ten:
                    void *obj = *(void **)(self + 0x298 + index * 4);
                    *(s32 *)((u8 *)obj + 0x14) = 0;
                    index = 0;
                    entry = lbl_802F4588;
                    for (i = 0; i < 0x25; i++, entry += 4) {
                        if (entry[0] == key && entry[1] == 9)
                            goto found_nine;
                        index += 1;
                        if (entry[2] == key && entry[3] == 9)
                            goto found_nine;
                        index += 1;
                    }
                    index = -1;
                found_nine:
                    obj = *(void **)(self + 0x298 + index * 4);
                    fn_800CF3EC(obj);
                    *(s32 *)((u8 *)obj + 0x14) = 1;
                    if (*(s32 *)(self + 0x80) == 0) {
                        void *callbackObject = *(void **)(self + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                        if (callback != 0)
                            result = callback(5, 12);
                        void *soundHandle = *(void **)(self + 0x5C0);
                        void *sound = *(void **)(self + 0x5D4);
                        if (result == 0 && soundHandle != 0 && sound != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)soundHandle + 0xC, sound, 12, 0, 0, 0);
                        }
                    }
                    for (i = 0; i < 4; i++) {
                        bits = *(u32 *)(self + 0x80) ^ 0x80000000;
                        f = ((f32)(s32)bits - 2147483648.0f) / lbl_80560DE4;
                        obj = *(void **)(self + 0x254 + i * 4);
                        fn_800D1204(obj, f);
                        fn_800D120C(obj, *(void **)(self + 0x5C0), 1);
                    }
                } else {
                    void *callbackObject = *(void **)(self + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    s32 result = 0;
                    if (callback != 0)
                        result = callback(5, 10);
                    void *soundHandle = *(void **)(self + 0x5C0);
                    void *sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 10, 0, 0, 0);
                    }
                    for (i = 0; i < 4; i++) {
                        bits = *(u32 *)(self + 0x80) ^ 0x80000000;
                        f = ((f32)(s32)bits - 2147483648.0f) / lbl_80560DE4;
                        obj = *(void **)(self + 0x254 + i * 4);
                        fn_800D1204(obj, f);
                        fn_800D120C(obj, *(void **)(self + 0x5C0), 1);
                    }
                    {
                        s32 index = 0;
                        s32 *entry = lbl_802F4588;
                        s32 j;
                        for (j = 0; j < 0x25; j++, entry += 4) {
                            if (entry[0] == 0xB && entry[1] == 5)
                                goto found_eleven;
                            index++;
                            if (entry[2] == 0xB && entry[3] == 5)
                                goto found_eleven;
                            index++;
                        }
                        index = -1;
                    found_eleven:
                        obj = *(void **)(self + 0x298 + index * 4);
                        fn_800CF3EC(obj);
                        *(s32 *)((u8 *)obj + 0x14) = 1;
                        s32 value = *(s32 *)(self + 0x80) + 1;
                        *(s32 *)(self + 0x80) = value;
                        s32 soundId = value == 10 ? 11 : 9;
                        void *callbackObject = *(void **)(self + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                        if (callback != 0)
                            result = callback(5, soundId);
                        void *soundHandle = *(void **)(self + 0x5C0);
                        void *sound = *(void **)(self + 0x5D4);
                        if (result == 0 && soundHandle != 0 && sound != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)soundHandle + 0xC, sound, soundId, 0, 0, 0);
                        }
                        for (i = 0; i < 4; i++) {
                            bits = *(u32 *)(self + 0x80) ^ 0x80000000;
                            f = ((f32)(s32)bits - 2147483648.0f) / lbl_80560DE4;
                            obj = *(void **)(self + 0x254 + i * 4);
                            fn_800D1204(obj, f);
                            fn_800D120C(obj, *(void **)(self + 0x5C0), 1);
                        }
                    }
                    {
                        s32 index = 0;
                        s32 *entry = lbl_802F4588;
                        s32 j;
                        for (j = 0; j < 0x25; j++, entry += 4) {
                            if (entry[0] == 0xC && entry[1] == 5)
                                goto found_twelve;
                            index++;
                            if (entry[2] == 0xC && entry[3] == 5)
                                goto found_twelve;
                            index++;
                        }
                        index = -1;
                    found_twelve:
                        obj = *(void **)(self + 0x298 + index * 4);
                        fn_800CF3EC(obj);
                        *(s32 *)((u8 *)obj + 0x14) = 1;
                        void *callbackObject = *(void **)(self + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                        if (callback != 0)
                            result = callback(5, 13);
                        void *soundHandle = *(void **)(self + 0x5C0);
                        void *sound = *(void **)(self + 0x5D4);
                        if (result == 0 && soundHandle != 0 && sound != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)soundHandle + 0xC, sound, 13, 0, 0, 0);
                        }
                    }
                }
                break;
            }
            case 4: {
                if (*(u8 *)(self + 0x84) == 0) {
                    *(u8 *)(self + 0x84) = 1;
                    fn_80060750((void *)1);
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    s32 j;
                    for (j = 0; j < 0x25; j++, entry += 4) {
                        if (entry[0] == 0xE && entry[1] == 8)
                            goto found_eight;
                        index++;
                        if (entry[2] == 0xE && entry[3] == 8)
                            goto found_eight;
                        index++;
                    }
                    index = -1;
                found_eight:
                    obj = *(void **)(self + 0x298 + index * 4);
                    fn_800CF3EC(obj);
                    *(s32 *)((u8 *)obj + 0x14) = 1;
                    index = 0;
                    entry = lbl_802F4588;
                    for (j = 0; j < 0x25; j++, entry += 4) {
                        if (entry[0] == 0x10 && entry[1] == 6)
                            goto found_six;
                        index++;
                        if (entry[2] == 0x10 && entry[3] == 6)
                            goto found_six;
                        index++;
                    }
                    index = -1;
                found_six:
                    obj = *(void **)(self + 0x298 + index * 4);
                    fn_800CF3EC(obj);
                    *(s32 *)((u8 *)obj + 0x14) = 1;
                    s32 value = *(s32 *)(self + 0x80) + 1;
                    *(s32 *)(self + 0x80) = value;
                    if (value == 10) {
                        void *callbackObject = *(void **)(self + 4);
                        s32 (*callback)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                        s32 result = 0;
                        if (callback != 0)
                            result = callback(5, 14);
                        void *soundHandle = *(void **)(self + 0x5C0);
                        void *sound = *(void **)(self + 0x5D4);
                        if (result == 0 && soundHandle != 0 && sound != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)soundHandle + 0xC, sound, 14, 0, 0, 0);
                        }
                        index = 0;
                        entry = lbl_802F4588;
                        for (j = 0; j < 0x25; j++, entry += 4) {
                            if (entry[0] == 0x10 && entry[1] == 0xE)
                                goto found_fourteen;
                            index++;
                            if (entry[2] == 0x10 && entry[3] == 0xE)
                                goto found_fourteen;
                            index++;
                        }
                        index = -1;
                    found_fourteen:
                        obj = *(void **)(self + 0x298 + index * 4);
                        fn_800CF3EC(obj);
                        *(s32 *)((u8 *)obj + 0x14) = 1;
                        void *callbackObject2 = *(void **)(self + 4);
                        s32 (*callback2)(s32, s32) =
                            *(s32 (**)(s32, s32))((u8 *)callbackObject2 + 0x14);
                        s32 result2 = 0;
                        if (callback2 != 0)
                            result2 = callback2(5, 13);
                        soundHandle = *(void **)(self + 0x5C0);
                        sound = *(void **)(self + 0x5D4);
                        if (result2 == 0 && soundHandle != 0 && sound != 0) {
                            ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                            detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                                (u8 *)soundHandle + 0xC, sound, 13, 0, 0, 0);
                        }
                    }
                }
                break;
            }
            case 5: {
                if (*(u8 *)(self + 0x84) != 0) {
                    void *callbackObject = *(void **)(self + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    s32 result = 0;
                    if (callback != 0)
                        result = callback(5, 13);
                    void *soundHandle = *(void **)(self + 0x5C0);
                    void *sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 13, 0, 0, 0);
                    }
                    *(s32 *)(self + 0x10) = 9;
                } else {
                    *(u8 *)(self + 0x84) = 0;
                    fn_80060750((void *)0);
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    s32 j;
                    for (j = 0; j < 0x25; j++, entry += 4) {
                        if (entry[0] == 0xE && entry[1] == 6)
                            goto found_e_six;
                        index++;
                        if (entry[2] == 0xE && entry[3] == 6)
                            goto found_e_six;
                        index++;
                    }
                    index = -1;
                found_e_six:
                    obj = *(void **)(self + 0x298 + index * 4);
                    fn_800CF3EC(obj);
                    *(s32 *)((u8 *)obj + 0x14) = 1;
                    void *callbackObject = *(void **)(self + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    s32 result = 0;
                    if (callback != 0)
                        result = callback(5, 15);
                    void *soundHandle = *(void **)(self + 0x5C0);
                    void *sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 15, 0, 0, 0);
                    }
                    index = 0;
                    entry = lbl_802F4588;
                    for (j = 0; j < 0x25; j++, entry += 4) {
                        if (entry[0] == 0xD && entry[1] == 8)
                            goto found_d_eight;
                        index++;
                        if (entry[2] == 0xD && entry[3] == 8)
                            goto found_d_eight;
                        index++;
                    }
                    index = -1;
                found_d_eight:
                    obj = *(void **)(self + 0x298 + index * 4);
                    fn_800CF3EC(obj);
                    *(s32 *)((u8 *)obj + 0x14) = 1;
                    callbackObject = *(void **)(self + 4);
                    callback = *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    result = 0;
                    if (callback != 0)
                        result = callback(5, 13);
                    soundHandle = *(void **)(self + 0x5C0);
                    sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 13, 0, 0, 0);
                    }
                    *(s32 *)(self + 0x10) = 9;
                }
                break;
            }
            case 6: {
                if (*(u8 *)(self + 0x84) == 0) {
                    *(u8 *)(self + 0x84) = 1;
                    fn_80060750((void *)1);
                    s32 index = 0;
                    s32 *entry = lbl_802F4588;
                    s32 j;
                    for (j = 0; j < 0x25; j++, entry += 4) {
                        if (entry[0] == 0xF && entry[1] == 5)
                            goto found_five;
                        index++;
                        if (entry[2] == 0xF && entry[3] == 5)
                            goto found_five;
                        index++;
                    }
                    index = -1;
                found_five:
                    obj = *(void **)(self + 0x298 + index * 4);
                    fn_800CF3EC(obj);
                    *(s32 *)((u8 *)obj + 0x14) = 1;
                    *(s32 *)(self + 0x10) = 3;
                    *(u8 *)(self + 0x88) = 1;
                    for (i = 0; i < 4; i++) {
                        obj = *(void **)(self + 0x254 + i * 4);
                        *(f32 *)((u8 *)obj + 0x1BC) = lbl_80560DC8;
                        *(f32 *)((u8 *)obj + 0x1CC) = lbl_80560DC8;
                        fn_800D15B4(obj);
                    }
                    *(s32 *)(self + 0x1DC) = 0x1E;
                    void *accessor = *(void **)(self + 0x1E0);
                    void *lookupObject = *(void **)((u8 *)accessor + 0x10);
                    void **lookupVtable = *(void ***)lookupObject;
                    void *(*findPane)(void *, const char *, s32) =
                        (void *(*)(void *, const char *, s32))lookupVtable[0x3C / 4];
                    void *paneObject = findPane(lookupObject, lbl_8031E264[0], 1);
                    u8 *trigger = (u8 *)paneObject + 0xCF;
                    *trigger = (*trigger & 0xFE) | 1;
                    void *callbackObject = *(void **)(self + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    s32 result = 0;
                    if (callback != 0)
                        result = callback(5, 6);
                    void *soundHandle = *(void **)(self + 0x5C0);
                    void *sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 6, 0, 0, 0);
                    }
                }
                break;
            }
            case 7: {
                s32 index = 0;
                s32 *entry = lbl_802F4588;
                s32 j;
                for (j = 0; j < 0x25; j++, entry += 4) {
                    if (entry[0] == 0x13 && entry[1] == 0xD)
                        goto found_thirteen;
                    index++;
                    if (entry[2] == 0x13 && entry[3] == 0xD)
                        goto found_thirteen;
                    index++;
                }
                index = -1;
            found_thirteen:
                obj = *(void **)(self + 0x298 + index * 4);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                *(s32 *)(self + 0x10) = 0xD;
                *(s32 *)self = 0;
                s32 state = *(s32 *)(self + 0xAC);
                if (state == 1) {
                    void *callbackObject = *(void **)(self + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    s32 result = 0;
                    if (callback != 0)
                        result = callback(5, 2);
                    void *soundHandle = *(void **)(self + 0x5C0);
                    void *sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 2, 0, 0, 0);
                    }
                } else if (state == 2) {
                    void *callbackObject = *(void **)(self + 4);
                    s32 (*callback)(s32, s32) =
                        *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                    s32 result = 0;
                    if (callback != 0)
                        result = callback(5, 3);
                    void *soundHandle = *(void **)(self + 0x5C0);
                    void *sound = *(void **)(self + 0x5D4);
                    if (result == 0 && soundHandle != 0 && sound != 0) {
                        ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                        detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                            (u8 *)soundHandle + 0xC, sound, 3, 0, 0, 0);
                    }
                }
                break;
            }
            case 8: {
                s32 index = 0;
                s32 *entry = lbl_802F4588;
                s32 j;
                for (j = 0; j < 0x25; j++, entry += 4) {
                    if (entry[0] == 0x14 && entry[1] == 0xD)
                        goto found_twenty;
                    index++;
                    if (entry[2] == 0x14 && entry[3] == 0xD)
                        goto found_twenty;
                    index++;
                }
                index = -1;
            found_twenty:
                obj = *(void **)(self + 0x298 + index * 4);
                fn_800CF3EC(obj);
                *(s32 *)((u8 *)obj + 0x14) = 1;
                *(s32 *)(self + 0x10) = 0xD;
                *(s32 *)(self + 0xAC) = -1;
                *(s32 *)self = 0;
                void *callbackObject = *(void **)(self + 4);
                s32 (*callback)(s32, s32) =
                    *(s32 (**)(s32, s32))((u8 *)callbackObject + 0x14);
                s32 result = 0;
                if (callback != 0)
                    result = callback(5, 6);
                void *soundHandle = *(void **)(self + 0x5C0);
                void *sound = *(void **)(self + 0x5D4);
                if (result == 0 && soundHandle != 0 && sound != 0) {
                    ((void (*)(void *))DetachSound__Q34nw4r3snd11SoundHandleFv)(sound);
                    detail_StartSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(
                        (u8 *)soundHandle + 0xC, sound, 6, 0, 0, 0);
                }
                break;
            }
            case 9:
                break;
            }
        }
    }
}

#pragma pop
s32 homebutton::HomeButton::getPaneNo(const char *name) {
    register s32 count = *(s32 *)((u8 *)this + 8);
    register s32 result = -1;
    register s32 i;
    for (i = 0; i < count; i++) {
        if (strcmp(name, lbl_8031D990[i]) == 0) {
            result = i;
            break;
        }
    }
    register s32 j;
    for (j = 0; j < 10; j++) {
        if (strcmp(name, lbl_8031E218[j]) == 0) {
            result = j + count;
            break;
        }
    }
    return result;
}

extern "C" f32 lbl_80560DCC;
extern "C" void GXSetCullMode(s32);
extern "C" void fn_800CEBE0(void *arg0, s32 arg1) {
    s32 bits = -arg1; bits |= arg1;
    u32 active = (u32)bits >> 31;
    u8 state = *(u8 *)((u8 *)arg0 + 0x250);
    state = (state & 0xDF) | ((bits << 6) & 0x20);
    *(u8 *)((u8 *)arg0 + 0x87) = (u8)active;
    *(u8 *)((u8 *)arg0 + 0x250) = state;
    volatile f32 sp[6];
    void *obj;
    if (active) {
        void *src = *(void **)((u8 *)arg0 + 4);
        f32 y = *(f32 *)((u8 *)src + 0x2C);
        f32 x = *(f32 *)((u8 *)src + 0x30);
        obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1E0) + 0x10);
        sp[2] = y; sp[3] = x; sp[4] = y; sp[5] = x;
        *(f32 *)((u8 *)obj + 0x44) = y; *(f32 *)((u8 *)obj + 0x48) = x;
        if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x20) == 0) {
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1E4) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = y; *(f32 *)((u8 *)obj + 0x48) = x;
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1E8) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = y; *(f32 *)((u8 *)obj + 0x48) = x;
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1EC) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = y; *(f32 *)((u8 *)obj + 0x48) = x;
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1F0) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = y; *(f32 *)((u8 *)obj + 0x48) = x;
        }
    } else {
        f32 zero = lbl_80560DCC;
        obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1E0) + 0x10);
        sp[0] = zero; sp[1] = zero; sp[4] = zero; sp[5] = zero;
        *(f32 *)((u8 *)obj + 0x44) = zero; *(f32 *)((u8 *)obj + 0x48) = zero;
        if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x20) == 0) {
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1E4) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = zero; *(f32 *)((u8 *)obj + 0x48) = zero;
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1E8) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = zero; *(f32 *)((u8 *)obj + 0x48) = zero;
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1EC) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = zero; *(f32 *)((u8 *)obj + 0x48) = zero;
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1F0) + 0x10);
            *(f32 *)((u8 *)obj + 0x44) = zero; *(f32 *)((u8 *)obj + 0x48) = zero;
        }
    }
    GXSetCullMode(0);
}

extern "C" void fn_800CB820(void *, const char *, void *);
extern "C" void fn_800CD38C(const char *, const char *);
void startLeftEvent__Q210homebutton10HomeButtonFPCc(const char *);
void homebutton::HomeButtonEventHandler::onEvent(unsigned long, unsigned long event, void *arg) {
    EventDispatchA *a = dispatch;
    EventDispatchB *b = (EventDispatchB *)a->first();
    void *owner = b->second();
    switch (event) {
    case 1: fn_800CB820((void *)text, (const char *)((u8 *)owner + 0xB4), arg); break;
    case 2: startLeftEvent__Q210homebutton10HomeButtonFPCc(text); break;
    case 0:
        if ((((unsigned long *)arg)[4] & 0x800) || (((unsigned long *)arg)[4] & 0x01000000))
            fn_800CD38C(text, (const char *)((u8 *)owner + 0xB4));
        break;
    }
}

extern "C" s32 fn_800CEDE0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x2C);
}

extern "C" void PSMTXIdentity(f32 (*)[4]);
extern "C" void GXLoadPosMtxImm(const f32*, u32);
extern "C" void GXSetCurrentMtx(u32);
extern "C" void GXClearVtxDesc(void);
extern "C" void GXSetVtxDesc(u32, u32);
extern "C" void GXSetVtxAttrFmt(u32, u32, u32, u32, u32);
extern "C" void GXSetNumChans(u32);
extern "C" void GXSetChanCtrl(u32, u32, u32, u32, u32, u32, u32);
extern "C" void GXSetNumTexGens(u32);
extern "C" void GXSetNumTevStages(u32);
extern "C" void GXSetTevOrder(u32, u32, u32, u32);
extern "C" void GXSetTevColorIn(u32, u32, u32, u32, u32);
extern "C" void GXSetTevColorOp(u32, u32, u32, u32, u32, u32);
extern "C" void GXSetTevAlphaIn(u32, u32, u32, u32, u32);
extern "C" void GXSetTevAlphaOp(u32, u32, u32, u32, u32, u32);
extern "C" void GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern "C" void GXSetBlendMode(u32, u32, u32, u32);
extern "C" void GXSetAlphaUpdate(u32);
extern "C" void GXSetZMode(u32, u32, u32);
extern "C" void fn_800CEDE8(void) {
    f32 mtx[3][4];
    PSMTXIdentity(mtx);
    GXLoadPosMtxImm((const f32 *)mtx, 0);
    GXSetCurrentMtx(0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxAttrFmt(0, 9, 0, 4, 0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 0, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 0xFF);
    GXSetTevColorIn(0, 0xF, 0xF, 0xF, 2);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 1);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetAlphaCompare(7, 0, 1, 7, 0);
    GXSetBlendMode(1, 4, 5, 5);
    GXSetAlphaUpdate(0);
    GXSetZMode(0, 7, 0);
}

extern "C" void fn_800EB36C(void *);
extern "C" void fn_800ECC58(void);
extern "C" void fn_800EE47C(void);
extern "C" void fn_800F83D0(void);
extern "C" void Shutdown__Q36nw4hbm3snd18SoundArchivePlayerFv(void);
extern "C" void DetachSound__Q34nw4r3snd11SoundHandleFv(void);
extern "C" void fn_800FA350(void);
extern "C" void fn_800CF170(void *arg0) {
    class HandleDispatch { public: virtual void stop2(s32); };
    class PlayerDispatch { public: virtual void pad1(); virtual void pad2(); virtual void stop(s32); };
    struct Object { u8 pad[0x5C0]; PlayerDispatch *player; HandleDispatch *h1; HandleDispatch *h2; HandleDispatch *h3; HandleDispatch *h4; s32 detach; };
    Object *obj = (Object *)arg0;
    if (obj->h1 != 0) {
        fn_800EB36C(obj->h1);
        obj->h1->stop2(-1);
    }
    if (obj->h2 != 0) {
        fn_800ECC58();
        obj->h2->stop2(-1);
    }
    if (obj->h3 != 0) {
        fn_800EE47C();
        obj->h3->stop2(-1);
    }
    if (obj->h4 != 0) {
        fn_800F83D0();
        obj->h4->stop2(-1);
    }
    if (obj->player != 0) {
        Shutdown__Q36nw4hbm3snd18SoundArchivePlayerFv();
        obj->player->stop(-1);
    }
    if (obj->detach != 0)
        if (obj->detach != 0)
            DetachSound__Q34nw4r3snd11SoundHandleFv();
    fn_800FA350();
}

void fn_800CF27C(void) {

}

extern "C" s32 fn_800A4A8C(s32);
extern "C" s32 fn_800A4B54(s32);
extern "C" s32 fn_800A485C(s32 arg0) {
    if ((arg0 >= 0x61) && (arg0 <= 0x7A)) {
        return arg0 - 0x20;
    }
    return arg0;
}

#pragma optimization_level reset
void VFipf_memcpy(void *dstArg, const void *srcArg, u32 size) {
    /* Fix note: preserve the destination alias while testing the original arguments for alignment. */
    register u8 *out = (u8 *)dstArg;
    register const u8 *in = (const u8 *)srcArg;
    u32 blocks;
    u32 words;
    s32 byteAdjustment;
    u32 value;

    if (((u32)dstArg & 3) != 0)
        goto copy_bytes;
    if (((u32)srcArg & 3) != 0)
        goto copy_bytes;

    words = size >> 2;
    if (size <= 3)
        goto copy_bytes;

    blocks = words >> 3;
    byteAdjustment = -(s32)(words << 2);
    if (blocks != 0) {
        do {
            value = *(u32 *)(in + 0x00); *(u32 *)(out + 0x00) = value;
            value = *(u32 *)(in + 0x04); *(u32 *)(out + 0x04) = value;
            value = *(u32 *)(in + 0x08); *(u32 *)(out + 0x08) = value;
            value = *(u32 *)(in + 0x0C); *(u32 *)(out + 0x0C) = value;
            value = *(u32 *)(in + 0x10); *(u32 *)(out + 0x10) = value;
            value = *(u32 *)(in + 0x14); *(u32 *)(out + 0x14) = value;
            value = *(u32 *)(in + 0x18); *(u32 *)(out + 0x18) = value;
            value = *(u32 *)(in + 0x1C);
            in += 0x20;
            *(u32 *)(out + 0x1C) = value;
            out += 0x20;
        } while (--blocks);
    }

    words &= 7;
    if (words != 0) {
        do {
            value = *(u32 *)in;
            in += 4;
            *(u32 *)out = value;
            out += 4;
        } while (--words);
    }

    size += byteAdjustment;
    if (size == 0)
        return;

copy_bytes:
    blocks = size >> 3;
    if (blocks != 0) {
        do {
            out[0] = in[0]; out[1] = in[1];
            out[2] = in[2]; out[3] = in[3];
            out[4] = in[4]; out[5] = in[5];
            out[6] = in[6]; out[7] = in[7];
            in += 8;
            out += 8;
        } while (--blocks);
    }
    blocks = size & 7;
    if (blocks == 0)
        return;
    do {
        *out++ = *in++;
    } while (--blocks);
}
#pragma optimization_level reset

extern "C" int fn_800A499C(const char *dstArg, int fill, int count) {
    u8 *dst = (u8 *)dstArg;
    u32 size = (u32)count;
    u32 words;
    u32 blocks;
    u32 pattern;
    u32 adjust;

    do {
        *dst++ = (u8)fill;
        size--;
    } while (((u32)dst & 3) != 0);

    pattern = (u32)fill;
    pattern |= (u32)fill << 8;
    pattern |= (u32)fill << 16;
    pattern |= (u32)fill << 24;

    if (size > 3) {
        words = size >> 2;
        blocks = words >> 3;
        adjust = -(s32)(words << 2);
        if (blocks != 0) {
            do {
                ((u32*)dst)[0] = pattern;
                ((u32*)dst)[1] = pattern;
                ((u32*)dst)[2] = pattern;
                ((u32*)dst)[3] = pattern;
                ((u32*)dst)[4] = pattern;
                ((u32*)dst)[5] = pattern;
                ((u32*)dst)[6] = pattern;
                ((u32*)dst)[7] = pattern;
                dst += 32;
            } while (--blocks != 0);
        }
        words &= 7;
        while (words != 0) {
            *(u32*)dst = pattern;
            dst += 4;
            words--;
        }
        size += adjust;
    }

    if ((s32)size != 0) {
        u32 bytes = size >> 3;
        if (bytes != 0) {
            do {
                dst[0] = (u8)fill; dst[1] = (u8)fill; dst[2] = (u8)fill; dst[3] = (u8)fill;
                dst[4] = (u8)fill; dst[5] = (u8)fill; dst[6] = (u8)fill; dst[7] = (u8)fill;
                dst += 8;
            } while (--bytes != 0);
            size &= 7;
        }
        while (size != 0) {
            *dst++ = (u8)fill;
            size--;
        }
    }
}

#pragma push
#pragma dont_inline on
extern "C" s32 fn_800A4A8C(s32 arg0) {
    s8 *start = (s8 *)arg0;
    s8 *ptr = start;
    while (*ptr != 0) {
        ++ptr;
    }
    return ptr - start;
}
#pragma pop
extern "C" char *fn_800A4AAC(char *dst, char *src) {
    char *d = dst;
    while ((*d = *src) != 0) {
        src++;
        d++;
    }
    return dst;
}

extern "C" s32 fn_800A4AD0(u8 *arg0, u8 *arg1) {
    u8 a;
    u8 b;
    goto test;
again:
    arg0++;
    arg1++;
test:
    a = *arg0;
    if (a == 0) goto done;
    b = *arg1;
    if (b == 0) goto done;
    if (a == b) goto again;
done:
    return a - *arg1;
}

#pragma scheduling off
extern "C" s32 fn_800A4B08(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 a;
    u8 b;
    while (arg2 != 0) {
        a = *arg0;
        if (a == 0)
            goto zero;
        b = *arg1;
        if (b == 0)
            goto zero;
        if (a != b)
            return a - *(volatile u8 *)arg1;
        arg0++;
        arg1++;
        arg2--;
    }
zero:
    return 0;
}
#pragma scheduling on
#pragma push
#pragma dont_inline on
extern "C" s32 fn_800A4B54(s32 arg0) {
    u8 *start = (u8 *)arg0;
    u8 *ptr = start;
    do {
        ptr += 2;
    } while (*(u16 *)ptr != 0);
    return (ptr - start) >> 1;
}
#pragma pop

extern "C" void fn_800A4B78(u16 *arg0, u16 *arg1) {
    u16 *src = arg1;
    volatile u16 *dst = (volatile u16 *)arg0;
    u16 value;
    goto copy;
loop:
    src++;
    dst++;
copy:
    value = *src;
    *dst = value;
    if (value != 0) {
        goto loop;
    }
}

extern "C" s32 fn_800A4B9C(u16 *arg0, u16 *arg1, s32 count) {
    while (count != 0) {
        u16 right;
        u16 left = *arg0;
        if (left == 0) goto differ;
        right = *arg1;
        if (right == 0) goto differ;
        if (left == right) goto equal;
    differ:
        right = *(volatile u16 *)arg1;
        return left - right;
    equal:
        arg0++;
        arg1++;
        count--;
    }
    return 0;
}

extern "C" s32 fn_800A4BE8(s32 arg0, s32 arg1) { return (arg0 << 16) + arg1; }

extern "C" s32 fn_800A4BF4(s32 arg0, u16 *arg1, s16 *arg2) {
    *arg1 = (u32)arg0 >> 16;
    *arg2 = arg0;
    return arg0;
}

extern "C" u32 fn_800A4C04(u8 *arg0) { return (arg0[1] << 8) | arg0[0]; }

extern "C" void fn_800A4C14(void *arg0, s32 arg1) {
    s32 var_r0;
    u32 temp_r6;
    u32 temp_r7;
    u32 var_ctr;
    u32 var_ctr_2;
    register u32 var_r5;
    u8 *var_r6_2;
    u8 temp_r7_3;
    u8 temp_r8;
    u8 *temp_r4;
    u8 *var_r6;
    u8 *temp_r7_2;
    u8 *buffer = (u8 *)arg0;

    var_r5 = 0;
    if (arg1 != 0) {
        temp_r6 = arg1 + 1;
        temp_r7 = arg1 - 0x10;
        if ((temp_r6 >> 1) > 8) {
            var_r0 = 0;
            if (temp_r6 >= 1 && (u32)arg1 <= temp_r6)
                var_r0 = 1;
            if (var_r0 != 0) {
                var_r6 = buffer;
                var_ctr = (temp_r7 + 0xF) >> 4;
                if (temp_r7 > 0) {
                    for (; var_ctr != 0; --var_ctr) {
                        temp_r7_2 = buffer + var_r5;
                        temp_r8 = var_r6[0];
                        temp_r7_3 = temp_r7_2[1];
                        buffer[var_r5] = temp_r7_3;
                        var_r5 += 0x10;
                        temp_r7_2[1] = temp_r8;
                        temp_r8 = var_r6[2];
                        temp_r7_3 = temp_r7_2[3];
                        temp_r7_2[2] = temp_r7_3;
                        temp_r7_2[3] = temp_r8;
                        temp_r8 = var_r6[4];
                        temp_r7_3 = temp_r7_2[5];
                        temp_r7_2[4] = temp_r7_3;
                        temp_r7_2[5] = temp_r8;
                        temp_r8 = var_r6[6];
                        temp_r7_3 = temp_r7_2[7];
                        temp_r7_2[6] = temp_r7_3;
                        temp_r7_2[7] = temp_r8;
                        temp_r8 = var_r6[8];
                        temp_r7_3 = temp_r7_2[9];
                        temp_r7_2[8] = temp_r7_3;
                        temp_r7_2[9] = temp_r8;
                        temp_r8 = var_r6[0xA];
                        temp_r7_3 = temp_r7_2[0xB];
                        temp_r7_2[0xA] = temp_r7_3;
                        temp_r7_2[0xB] = temp_r8;
                        temp_r8 = var_r6[0xC];
                        temp_r7_3 = temp_r7_2[0xD];
                        temp_r7_2[0xC] = temp_r7_3;
                        temp_r7_2[0xD] = temp_r8;
                        temp_r8 = var_r6[0xE];
                        var_r6 += 0x10;
                        temp_r7_3 = temp_r7_2[0xF];
                        temp_r7_2[0xE] = temp_r7_3;
                        temp_r7_2[0xF] = temp_r8;
                    }
                }
            }
        }
        var_r6_2 = buffer + var_r5;
        var_ctr_2 = ((u32)arg1 + 1 - var_r5) >> 1;
        if (var_r5 < (u32)arg1) {
            do {
                temp_r4 = buffer + var_r5;
                temp_r7_3 = *var_r6_2;
                var_r6_2 += 2;
                temp_r8 = temp_r4[1];
                buffer[var_r5] = temp_r8;
                var_r5 += 2;
                temp_r4[1] = temp_r7_3;
                var_ctr_2--;
            } while (var_ctr_2 != 0);
        }
    }
}

extern "C" void NANDSetUserData(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
}

extern "C" s32 fn_800A4D44(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" void fn_800A4D4C(void *arg0, void *arg1) {
    if (((u32 *)arg0)[0xC / 4] == 1 || (s32)arg1 == 0) {
        ((s32 *)arg0)[8 / 4] = ((s32 *)arg0)[0];
    } else {
        ((s32 *)arg0)[8 / 4] = (s32)arg1;
    }
}

extern "C" s32 fn_800A4D74(void *arg0, u32 arg1) {
    if (arg1 == 1) {
        return ((s32 *)arg0)[0];
    }
    if (arg1 == 2) {
        return ((s32 *)arg0)[1];
    }
    return ((s32 *)arg0)[2];
}

extern "C" void VFiPFSTR_MoveStrPos(void *arg0, s16 arg1, s32 arg2) {
    s16 count = 0;
    struct Data { u8 *pos; u8 *secondary; u32 unk; u32 mode; };
    struct Table { u8 pad[0x54]; s32 (*is_lead)(s8, s32); s32 (*length)(u8 *); };
    Data *data = (Data *)arg0;
    if (data->mode == 1) {
        Table *table = (Table *)lbl_803D2140;
        u8 *str = data->pos;
        while (arg1 != 0) {
            if (table->is_lead((s8)*str, 1) != 0)
                count = (s16)(count + 1);
            count++;
            arg1--;
        }
    } else {
        Table *table = (Table *)lbl_803D2140;
        u8 *str = data->pos;
        s16 i = 0;
        while (i < arg1) {
            s32 len = table->length(str);
            str += len * 2;
            i++;
            count += (s16)len;
        }
    }
    data->pos += count;
}

extern "C" s32 fn_800A4E80(void *arg0, s32 arg1, u32 arg2) {
    if (arg2 == 1) {
        *(s32 *)((u8 *)arg0 + 0) = arg1;
        *(s32 *)((u8 *)arg0 + 4) = (s32)(arg1 + fn_800A4A8C(arg1));
    } else if (arg2 == 2) {
        *(s32 *)((u8 *)arg0 + 0) = arg1;
        *(s32 *)((u8 *)arg0 + 4) = (s32)(arg1 + (fn_800A4B54(arg1) * 2));
    }
        *(u32 *)((u8 *)arg0 + 0xC) = arg2;
      
      return 0;
}

extern "C" u16 fn_800A4F08(void *arg0) {
    return (u16)(*(u32 *)((u8 *)arg0 + 4) - *(u32 *)arg0);
}

extern "C" u16 VFiPFSTR_StrNumChar(s32 arg0, s32 arg1) {
    u8 *str;
    u16 count;

    if ((u32)arg1 == 1U) {
        str = *(u8 **)arg0;
    } else {
        str = *(u8 **)((u8 *)arg0 + 4);
    }

    if (*(u32 *)((u8 *)arg0 + 0xC) == 1U) {
        count = 0;
        while ((s8)*str != 0) {
            if (((s32 (**)(s8, s32))((u8 *)lbl_803D2140 + 0x54))[0]((s8)*str, 1) != 0) {
                str++;
            }
            str++;
            count++;
        }
    } else {
        count = 0;
        while ((s8)str[0] != 0 || (s8)str[1] != 0) {
            str += ((s32 (**)(u8 *))((u8 *)lbl_803D2140 + 0x58))[0](str);
            count++;
        }
    }
    return count;
}

#pragma dont_inline on
typedef s32 (*UnicodeCompareCallback)(s32, u16 *);
extern "C" s32 VFiPFSTR_StrCmp(void *arg0, s32 arg1) {
    u16 converted;
    register u8 *table;
    register u16 *cursor;
    register s32 code = arg1;
    u16 current;

    if (*(volatile u32 *)((u8 *)arg0 + 0xC) == 1)
        return fn_800A4AD0(*(u8 **)arg0, (u8 *)arg1);

    table = (u8 *)lbl_803D2140;
    cursor = *(u16 **)arg0;
loop:
    ((UnicodeCompareCallback *)(table + 0x48))[0](code, &converted);
    current = *cursor;
    code++;
    cursor++;
    if (current == converted && *(cursor - 1) != 0 && converted != 0)
        goto loop;
    return *(cursor - 1) - converted;
}

extern "C" s32 VFiPFSTR_StrNCmp(s32 arg0_, const void *arg1_, s32 arg2_, s32 arg3, s32 arg4_) {
    void *arg0 = (void *)arg0_;
    u32 arg2 = (u32)arg2_;
    u16 *p;
    u32 count = (u32)arg4_;
    u8 *arg1 = (u8 *)arg1_;
    u16 sp8;
    u8 *base;
    u32 result;
    if (*(u32 *)((u8 *)arg0 + 0xC) == 1 || arg2 == 3) {
        if (arg2 == 1) base = *(u8 **)arg0 + arg3;
        else if (arg2 == 2) base = *(u8 **)((u8 *)arg0 + 4) + arg3;
        else base = *(u8 **)((u8 *)arg0 + 8) + arg3;
        return fn_800A4B08(base, arg1, count);
    }
    if (arg2 == 1) p = (u16 *)(*(u8 **)arg0 + arg3 * 2);
    else p = (u16 *)(*(u8 **)((u8 *)arg0 + 4) + arg3 * 2);
    do {
        ((void (*)(u8 *, u16 *))(*(u32 *)((u8 *)lbl_803D2140 + 0x48)))(arg1, &sp8);
        result = *p;
        arg1++;
        count--;
        p++;
    } while ((u16)result == sp8 && (u16)count != 0 && p[-1] != 0 && sp8 != 0);
    return (s32)p[-1] - (s32)sp8;
}

extern "C" void VFipf_memcpy(void *, const void *, u32);
extern "C" void fn_800A52A0(void *arg0, const void *arg1) {
    VFipf_memcpy((u8 *)arg0 + 0x1648, arg1, 0xB);
    *((u8 *)arg0 + 0x1653) = 0;
}

#pragma dont_inline reset
extern "C" void fn_800A52DC(u32 arg0) {
    u8 *base = (u8 *)lbl_803D2140;
    register u8 *ptr = base + 0xA0;
    register s32 i = 0;
    for (; i < 13; ++i) {
        if (*(u32 *)(ptr + 0x1FBC) == arg0) {
            u16 value = *(u16 *)(ptr + 0x1F8C);
            if (value & 8) *(u16 *)(ptr + 0x1F8C) = value | 0x20;
            *(u16 *)(ptr + 0x1F8C) &= ~0xC;
        }
        if (*(u32 *)(ptr + 0x3F84) == arg0) {
            u16 value = *(u16 *)(ptr + 0x3F54);
            if (value & 8) *(u16 *)(ptr + 0x3F54) = value | 0x20;
            *(u16 *)(ptr + 0x3F54) &= ~0xC;
        }
        ptr += 0x3F90;
    }
}

extern "C" void fn_800A535C(u32 arg0) {
    u8 *ptr = (u8 *)lbl_803D2140 + 0xA0;
    s32 i;
    for (i = 0; i < 13; i++, ptr += 0x3F90) {
        if (*(u32 *)(ptr + 0x1FBC) == arg0) {
            *(u16 *)(ptr + 0x1F8C) |= 0x14;
        }
        if (*(u32 *)(ptr + 0x3F84) == arg0) {
            *(u16 *)(ptr + 0x3F54) |= 0x14;
        }
    }
}

extern "C" s32 fn_800A53B4(void *arg0) {
    return (((u16)*(u16 *)((u8 *)arg0 + 0x1F8C)) >> 2) & 1;
}

extern "C" s32 fn_800A53C0(void *arg0) {
    return (((u16)*(u16 *)((u8 *)arg0 + 0x1F8C)) >> 4) & 1;
}

extern "C" void fn_800A53CC(void *arg0) { *(u16 *)((u8 *)arg0 + 0x1F8C) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F8C) & 0xFFFFFFEF); }

extern "C" s32 fn_800A53DC(void *arg0) { return ((u16)*(u16 *)((u8 *)arg0 + 0x1F8C) >> 5U) & 1; }

extern "C" void fn_800A53E8(void *arg0) { *(u16 *)((u8 *)arg0 + 0x1F8C) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F8C) & 0xFFFFFFDF); }

extern "C" s32 fn_800A53F8(void *arg0) {
    void *local1 = (void *)fn_800A535C;
    void *local2 = (void *)fn_800A52DC;
    s32 result;
    s32 value;

    if (fn_800A7688(*(void **)((u8 *)arg0 + 0x1FBC), &local1, &local2) != 0)
        return -1;

    result = fn_800A7214(*(void **)((u8 *)arg0 + 0x1FBC));
    if (result != 0) {
        fn_800A76A0(*(void **)((u8 *)arg0 + 0x1FBC));
        if (result == 0x15) {
            value = fn_800A71D8(*(void **)((u8 *)arg0 + 0x1FBC));
            lbl_803D2140[17] = value;
            *(s32 *)((u8 *)arg0 + 0x1F84) = value;
            return 0x1000;
        }
        return -1;
    }
    return 0;
}

#pragma dont_inline on
extern "C" s32 fn_800A54AC(void *arg0) {
    s32 result;
    s32 value;
    if (fn_800A76A0(*(void **)((u8 *)arg0 + 0x1FBC)) == 0)
        goto continue_check;
    return -1;
continue_check:
    result = fn_800A7610(*(void **)((u8 *)arg0 + 0x1FBC));
    if (result == 0)
        goto done;
    if (result != 21)
        goto error;
    value = fn_800A71D8(*(void **)((u8 *)arg0 + 0x1FBC));
    *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x1F84) = value;
    return 0x1000;
error:
    return -1;
done:
    return 0;
}
#pragma dont_inline on
extern "C" s32 fn_800A5788(void *arg0, s32 arg1) {
    s32 result = fn_800A7568(*(void **)((u8 *)arg0 + 0x1FBC), (arg1 - 1) == 0);
    switch (result) {
    case 21: {
        s32 value = fn_800A71D8(*(void **)((u8 *)arg0 + 0x1FBC));
        *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
        *(s32 *)((u8 *)arg0 + 0x1F84) = value;
        return 0x1000;
    }
    case 0:
        return 0;
    default:
        return -1;
    }
}
#pragma dont_inline reset
extern "C" s32 fn_800A5800(void *arg0, s32 arg1) {
    s32 result = fn_800A7338(*(void **)((u8 *)arg0 + 0x1FBC), arg1);
    switch (result) {
    case 0:
        break;
    case 21: {
        s32 value = ((s32 (*)(void *))fn_800A71D8)(*(void **)((u8 *)arg0 + 0x1FBC));
        *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
        *(s32 *)((u8 *)arg0 + 0x1F84) = value;
        return 0x1000;
    }
    default:
        return -1;
    }
    return 0;
}

extern "C" s32 fn_800A71A0(s32 *);
extern "C" s32 fn_800A7610(void *);
extern "C" s32 fn_800A76A0(void *);
extern "C" s32 fn_800A586C(void *arg0, s32 a, s32 b, s32 c, s32 d) {
    s32 result;
    s32 value;
    result = ((s32 (*)(void *, s32, s32, s32, u16, s32))fn_800A73A0)(*(void **)((u8 *)arg0 + 0x1FBC), a, b, c, *(u16 *)arg0, d);
    if (result == 0) goto zero;
    if (result != 21) goto fail;
    value = ((s32 (* volatile)(void *))fn_800A71D8)(*(void **)((u8 *)arg0 + 0x1FBC));
    *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x1F84) = value;
    return 0x1000;
fail: return -1;
zero: return 0;
}

extern "C" s32 fn_800A7484(void *, s32, u32, s32, s32, s32);
extern "C" s32 fn_800A58E0(void *arg0, s32 a, s32 b, s32 c, s32 d) {
    s32 result;
    s32 value;
    result = ((s32 (*)(void *, s32, s32, s32, u16, s32))fn_800A7484)(*(void **)((u8 *)arg0 + 0x1FBC), a, b, c, *(u16 *)arg0, d);
    if (result == 0) goto zero;
    if (result != 21) goto fail;
    value = ((s32 (* volatile)(void *))fn_800A71D8)(*(void **)((u8 *)arg0 + 0x1FBC));
    *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x1F84) = value;
    return 0x1000;
fail: return -1;
zero: return 0;
}

#pragma opt_tail_call on
#pragma opt_tail_call on
#pragma opt_tail_call on
extern "C" void Console_DrawDirect__Q26nw4hbm2dbFPQ46nw4hbm2db6detail11ConsoleHead(void *arg0) {
    if (arg0 == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x26D, lbl_8031EA90);
    }
    void *r30 = arg0;
    if (fn_800D2E14() != 0) {
        if (((u8 *)r30)[0x22] != 0) {
            OSLockMutex(&lbl_804077C0);
            fn_800D2E3C(*(s16 *)((u8 *)r30 + 0x1C) - 6, *(s16 *)((u8 *)r30 + 0x1E) - 3,
                        (s32)(*(u16 *)((u8 *)r30 + 4)) * 6 + 12,
                        (s32)(*(u16 *)((u8 *)r30 + 0x20)) * 0xA + 4);
            fn_800D24D4(r30, 0);
            fn_800D2FC8();
            OSUnlockMutex(&lbl_804077C0);
        }
    }
}

extern "C" void fn_800D272C(void *arg0, void *arg1) {
    s32 var_ctr_2;
    s32 var_r10;
    s32 var_r11;
    s32 var_r9;
    s32 var_r5;
    s32 var_r4;
    s32 var_r3;
    u16 temp_r10;
    u16 temp_r10_2;
    u16 temp_r11_2;
    u16 temp_r7;
    u16 temp_r7_5;
    u16 temp_r7_6;
    u16 temp_r9;
    u16 temp_r9_2;
    u16 temp_r9_4;
    u16 temp_r9_5;
    u32 temp_r7_2;
    u32 var_ctr;
    u8 *var_r12;
    u8 *var_r29;
    u8 *var_r31;
    u8 *var_r8;
    u8 temp_r11;
    u8 temp_r7_3;
    u8 temp_r7_4;
    u8 temp_r9_3;

    var_r31 = (u8 *)arg1;
    var_r29 = (u8 *)lbl_8031EA80;
    if (!arg0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&var_r29[0], 0x2EB, (const char *)(var_r29 + 0x10));
    }
    if (!var_r31) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&var_r29[0], 0x2EC, (const char *)(var_r29 + 0xF8));
    }
    var_r4 = 2;
    var_r5 = 0x20;
    var_r3 = 0x81;
    var_r8 = ((M2C_FIELD(arg0, u16 *, 4) + 1) * M2C_FIELD(arg0, u16 *, 0xC)) + ((u8 *)M2C_FIELD(arg0, s32 *, 0) + M2C_FIELD(arg0, u16 *, 0xE));
    goto loop_51;
loop_body:
        if (M2C_FIELD(arg0, u16 *, 0xA) & 2) {
            if ((u16) M2C_FIELD(arg0, u16 *, 0xC) != (u16) M2C_FIELD(arg0, u16 *, 6)) {
                goto loop_50;
            }
        } else {
loop_50:
            temp_r11 = *var_r31;
            if ((s32) temp_r11 != 0) {
                var_r9 = 0;
                if ((s32) temp_r11 == 0xA) {
                    var_r31 += 1;
                    *((u8 *)M2C_FIELD(arg0, s32 *, 0) + M2C_FIELD(arg0, u16 *, 0xE) + ((M2C_FIELD(arg0, u16 *, 4) + 1) * M2C_FIELD(arg0, u16 *, 0xC))) = 0;
                    temp_r9 = M2C_FIELD(arg0, u16 *, 0xC) + 1;
                    M2C_FIELD(arg0, u16 *, 0xE) = 0U;
                    M2C_FIELD(arg0, u16 *, 0xC) = temp_r9;
                    M2C_FIELD(arg0, s16 *, 0x10) = 0;
                    if ((temp_r9 == (u16) M2C_FIELD(arg0, u16 *, 6)) && !(M2C_FIELD(arg0, u16 *, 0xA) & 2)) {
                        M2C_FIELD(arg0, u16 *, 0xC) = 0U;
                    }
                    temp_r7 = M2C_FIELD(arg0, u16 *, 0x12);
                    if ((u16) M2C_FIELD(arg0, u16 *, 0xC) == temp_r7) {
                        temp_r9_2 = temp_r7 + 1;
                        M2C_FIELD(arg0, u16 *, 0x12) = temp_r9_2;
                        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 1);
                        if (temp_r9_2 == (u16) M2C_FIELD(arg0, u16 *, 6)) {
                            M2C_FIELD(arg0, u16 *, 0x12) = 0U;
                        }
                    }
                    var_r8 = (u8 *)M2C_FIELD(arg0, s32 *, 0) + ((M2C_FIELD(arg0, u16 *, 4) + 1) * M2C_FIELD(arg0, u16 *, 0xC));
                } else {
                    if ((s32) temp_r11 == 9) {
                        var_r31 += 1;
loop_18:
                        *var_r8 = (u8)var_r4;
                        var_r8 += 1;
                        temp_r11_2 = M2C_FIELD(arg0, u16 *, 0xE) + 1;
                        M2C_FIELD(arg0, u16 *, 0xE) = temp_r11_2;
                        if (temp_r11_2 < (u16) M2C_FIELD(arg0, u16 *, 4)) {
                            if (temp_r11_2 & ((var_r5 << (((u16) M2C_FIELD(arg0, u16 *, 0xA) >> 2U) & 3)) - 1)) {
                                goto loop_18;
                            }
                        }
                        M2C_FIELD(arg0, s16 *, 0x10) = 1;
                    } else {
                        var_r29 = var_r8;
                        var_r12 = var_r31;
                        var_r11 = ((u32) ((temp_r11 | ~var_r3) - ((u32) (temp_r11 - var_r3) >> 1U)) >> 0x1FU) + 1;
                        temp_r10 = M2C_FIELD(arg0, u16 *, 0xE) + var_r11;
                        if (temp_r10 > M2C_FIELD(arg0, u16 *, 4)) {
                            var_r11 = 0;
                        } else {
                            M2C_FIELD(arg0, u16 *, 0xE) = temp_r10;
                            var_r10 = var_r11;
                            if (var_r11 != 0) {
                                temp_r7_2 = (u32) var_r11 >> 3U;
                                var_ctr = temp_r7_2;
                                if (temp_r7_2 != 0) {
                                    do {
                                        M2C_FIELD(var_r29, u8 *, 0) = M2C_FIELD(var_r12, u8 *, 0);
                                        M2C_FIELD(var_r29, u8 *, 1) = (u8) M2C_FIELD(var_r12, u8 *, 1);
                                        M2C_FIELD(var_r29, u8 *, 2) = (u8) M2C_FIELD(var_r12, u8 *, 2);
                                        M2C_FIELD(var_r29, u8 *, 3) = (u8) M2C_FIELD(var_r12, u8 *, 3);
                                        M2C_FIELD(var_r29, u8 *, 4) = (u8) M2C_FIELD(var_r12, u8 *, 4);
                                        M2C_FIELD(var_r29, u8 *, 5) = (u8) M2C_FIELD(var_r12, u8 *, 5);
                                        M2C_FIELD(var_r29, u8 *, 6) = (u8) M2C_FIELD(var_r12, u8 *, 6);
                                        temp_r7_3 = M2C_FIELD(var_r12, u8 *, 7);
                                        var_r12 += 8;
                                        M2C_FIELD(var_r29, u8 *, 7) = temp_r7_3;
                                        var_r29 += 8;
                                        var_ctr -= 1;
                                    } while (var_ctr != 0);
                                    var_r10 = var_r11 & 7;
                                    if (var_r10 != 0) {
                                        goto block_27;
                                    }
                                } else {
block_27:
                                    var_ctr_2 = var_r10;
                                    do {
                                        temp_r7_4 = *var_r12;
                                        var_r12 += 1;
                                        *var_r29 = temp_r7_4;
                                        var_r29 += 1;
                                        var_ctr_2 -= 1;
                                    } while (var_ctr_2 != 0);
                                }
                            }
                        }
                        if (var_r11 != 0) {
                            M2C_FIELD(arg0, s16 *, 0x10) = 1;
                            var_r31 += var_r11;
                            var_r8 += var_r11;
                        } else {
                            var_r9 = 1;
                        }
                    }
                    temp_r7_5 = M2C_FIELD(arg0, u16 *, 4);
                    temp_r10_2 = M2C_FIELD(arg0, u16 *, 0xE);
                    if (temp_r10_2 >= temp_r7_5) {
                        var_r9 = 1;
                    }
                    if (var_r9 != 0) {
                        if (M2C_FIELD(arg0, u16 *, 0xA) & 1) {
loop_38:
                            temp_r9_3 = *var_r31;
                            if ((s32) temp_r9_3 != 0xA) {
                                if ((s32) temp_r9_3 == 0) {

                                } else {
                                    var_r31 += 1;
                                    goto loop_38;
                                }
                            }
                        } else {
                            if ((s32) *var_r31 == 0xA) {
                                var_r31 += 1;
                            }
                            *(((temp_r7_5 + 1) * M2C_FIELD(arg0, u16 *, 0xC)) + ((u8 *)M2C_FIELD(arg0, s32 *, 0) + temp_r10_2)) = 0;
                            temp_r9_4 = M2C_FIELD(arg0, u16 *, 0xC) + 1;
                            M2C_FIELD(arg0, u16 *, 0xE) = 0U;
                            M2C_FIELD(arg0, u16 *, 0xC) = temp_r9_4;
                            M2C_FIELD(arg0, s16 *, 0x10) = 0;
                            if ((temp_r9_4 == (u16) M2C_FIELD(arg0, u16 *, 6)) && !(M2C_FIELD(arg0, u16 *, 0xA) & 2)) {
                                M2C_FIELD(arg0, u16 *, 0xC) = 0U;
                            }
                            temp_r7_6 = M2C_FIELD(arg0, u16 *, 0x12);
                            if ((u16) M2C_FIELD(arg0, u16 *, 0xC) == temp_r7_6) {
                                temp_r9_5 = temp_r7_6 + 1;
                                M2C_FIELD(arg0, u16 *, 0x12) = temp_r9_5;
                                M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 1);
                                if (temp_r9_5 == (u16) M2C_FIELD(arg0, u16 *, 6)) {
                                    M2C_FIELD(arg0, u16 *, 0x12) = 0U;
                                }
                            }
                            var_r8 = (u8 *)M2C_FIELD(arg0, s32 *, 0) + ((M2C_FIELD(arg0, u16 *, 4) + 1) * M2C_FIELD(arg0, u16 *, 0xC));
                        }
                    } else {
                        goto loop_50;
                    }
                }
            }
            goto loop_51;
loop_51:
    temp_r11 = *var_r31;
    if ((s32) temp_r11 != 0) {
        goto loop_body;
    }
    if ((s32) *var_r31 != 0) {
        goto loop_body;
    }
}
}

extern "C" void fn_800D272C(void*, void*);
extern "C" char lbl_804077D8[0x400];
extern "C" { DECL_SECTION(".sdata") extern const char lbl_805597E4[]; }
extern "C" void Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct(void *arg0, void *arg1, const char *arg2, void *arg3) {
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x368, lbl_8031EA90);
    }
    OSLockMutex(&lbl_804077C0);
    vsnprintf(lbl_804077D8, 0x400, arg2, (VaList1 *)arg3);
    if (arg1 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x34B, lbl_8031EA90);
    }
    if (((u32)arg0 & 2) != 0) {
        OSReport(lbl_805597E4, lbl_804077D8);
    }
    if (((u32)arg0 & 1) != 0) {
        fn_800D272C(arg1, lbl_804077D8);
    }
    OSUnlockMutex(&lbl_804077C0);
}
#pragma push
#pragma use_lmw_stmw off
extern "C" void Console_Printf__Q26nw4hbm2dbFPQ46nw4hbm2db6detail11ConsoleHeadPCce(void* head, const char* fmt, ...) {
    f64 sp_28;
    f64 sp_30;
    f64 sp_38;
    f64 sp_40;
    f64 sp_48;
    f64 sp_50;
    f64 sp_58;
    f64 sp_60;
    s32 sp_8;
    s32 sp_C;
    s32 sp_10;
    s32 sp_14;
    s32 sp_18;
    s32 sp_1C;
    s32 sp_20;
    s32 sp_24;
    s32 sp_68;
    s32 sp_6C;
    s32 sp_70;
    if (lbl_80407BD8[0] != 0) {
        sp_28 = (f64)0;
        sp_30 = (f64)0;
        sp_38 = (f64)0;
        sp_40 = (f64)0;
        sp_48 = (f64)0;
        sp_50 = (f64)0;
        sp_58 = (f64)0;
        sp_60 = (f64)0;
    }
    sp_8 = (s32)head;
    sp_C = (s32)fmt;
    sp_68 = 0x02000000;
    sp_6C = (s32)&sp_8;
    sp_70 = (s32)&sp_8;
    if (head == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x368, lbl_8031EA90);
    }
    OSLockMutex((void*)0x804077C0);
    vsnprintf(lbl_804077D8, 0x400, fmt, (VaList1*)&sp_68);
    if (head == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x34B, lbl_8031EA90);
    }
    OSReport(lbl_805597E4, lbl_804077D8);
    fn_800D272C(head, lbl_804077D8);
    OSUnlockMutex((void*)0x804077C0);
}

s32 nw4hbm::db::Console_GetTotalLines(nw4hbm::db::detail::ConsoleHead *head) {
    if (head == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x41A, lbl_8031EA90);
    }
    OSLockMutex(&lbl_804077C0);
    if (head == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x70, lbl_8031EA90);
    }
    s32 lines = (s32)M2C_FIELD(head, u16 *, 0x0C) - (s32)M2C_FIELD(head, u16 *, 0x12);
    if (lines < 0) lines += M2C_FIELD(head, u16 *, 0x06);
    u16 count = (u16)lines;
    if (M2C_FIELD(head, u16 *, 0x10) != 0) count++;
    s32 result = M2C_FIELD(head, s32 *, 0x14) + count;
    OSUnlockMutex(&lbl_804077C0);
    return result;
}

#pragma pop

extern "C" void fn_800D2480(void) {
    if (lbl_8055DDBC == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA40, 0x1F1, lbl_8031EA4C);
    }
    ((u8 *)lbl_8055DDBC)[0x22] = 0;
}

extern "C" void Play__Q210homebutton9RemoteSpkFliSc(void *arg0, long arg1, int arg2, signed char arg3) {
    void *r26 = arg0;
    long r27 = arg1;
    int r28 = arg2;
    signed char r29 = arg3;
    
    if (((u8 *)r26)[0x1EC] != 0) {
        ARCFileInfo info;
        void *r30;
        s32 r31;
        
        ARCFastOpen((ARCHandle *)((u8 *)r26 + 0x1D0), r28, &info);
        r30 = ARCGetStartAddrInMem(&info);
        r31 = fn_80116A30(&info);
        fn_80116A38(&info);
        
        u8 *entry = (u8 *)r26 + ((s32)r27 * 0x68);
        entry[0x5E] = 0;
        *(s32 *)(entry + 0x58) = r28;
        *(s32 *)(entry + 0x54) = r31;
        entry[0x5D] = r29;
        *(s32 *)(entry + 0x50) = (s32)r30;
    }
}

#pragma opt_tail_call on
#pragma opt_tail_call on
extern "C" void fn_800D1C48(s32, s32);
extern u8 lbl_8055DDC0;
extern OSAlarm lbl_80407790;
extern const char lbl_8031E9D0[];
extern "C" const char lbl_805597DC[2];
extern u32 lbl_8055DDB8;
extern "C" void fn_800D2480(void);
namespace nw4hbm {
namespace db {
void Warning(const char* file, int line, const char* msg, ...);
}
}
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *file, s32 line, const char *msg, ...) {
    va_list vlist;
    va_start(vlist, msg);
    ((void (*)(const char *, s32, const char *, va_list))fn_800D2098)(file, line, msg, vlist);
}

void nw4hbm::db::Warning(const char* file, int line, const char* msg, ...) {
    const char* str = lbl_8031E9D0;
    if (!lbl_8055DDC0) {
        OSCreateAlarm(&lbl_80407790);
        lbl_8055DDC0 = 1;
    }
    va_list vlist;
    va_start(vlist, msg);
    void* console = lbl_8055DDBC;
    if (console) {
        Console_Printf__Q26nw4hbm2dbFPQ46nw4hbm2db6detail11ConsoleHeadPCce(console, str + 0xA0, file, line);
        Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct((void*)3, lbl_8055DDBC, msg, vlist);
        Console_Printf__Q26nw4hbm2dbFPQ46nw4hbm2db6detail11ConsoleHeadPCce(lbl_8055DDBC, lbl_805597DC);
        msg = (const char*)lbl_8055DDBC;
        if (!msg)
            Panic__Q26nw4hbm2dbFPCciPCce(str + 0x70, 0x1B2, str + 0x7C);
        u16 viewLines = *(u16*)((u8*)msg + 0x20);
        s32 lines = Console_GetTotalLines((detail::ConsoleHead*)msg) - viewLines;
        if (lines < 0)
            lines = 0;
        if (!msg)
            Panic__Q26nw4hbm2dbFPCciPCce(str + 0x70, 0x22D, str + 0x7C);
        *(s32*)((u8*)msg + 0x18) = lines;
        msg = (const char*)lbl_8055DDBC;
        if (!msg)
            Panic__Q26nw4hbm2dbFPCciPCce(str + 0x70, 0x1F1, str + 0x7C);
        ((u8*)msg)[0x22] = 1;
    } else {
        OSReport(str + 0xA0, file, line);
        __VprintfThunk(msg, vlist);
        OSReport(lbl_805597DC);
    }
    if (lbl_8055DDB8) {
        OSAlarm* alarm = &lbl_80407790;
        OSCancelAlarm(alarm);
        OSSetAlarm(alarm, (u64)lbl_8055DDB8, (OSAlarmHandler)fn_800D2480);
    }
}

extern s32 lbl_8055DDD4;
extern "C" f32 lbl_80560E40;
extern "C" f32 lbl_80560E3C;
  extern "C" s32 fn_80060C7C(void*);
  extern "C" s32 lbl_8055DD30;
  extern "C" s32 fn_800B8004(s32);
  extern "C" s32 fn_800B8048(s32);
  extern "C" s32 fn_800B960C(s32, s32, s32, s32, s32 *, s32);
extern "C" const char lbl_8031E764[];
extern "C" const char lbl_8031E740[];
namespace nw4hbm { namespace db { namespace detail { struct ConsoleHead; } s32 Console_GetTotalLines(detail::ConsoleHead *); } }
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" const char lbl_8031EA80[];
extern "C" const char lbl_8031EA90[];
extern "C" void fn_800A71D0(void *, s32);

extern "C" s32 fn_800BAE98(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11) {
    const char *str = lbl_8031B838;
    s32 r30, r29, res;
    s32 *buf, *m;
    if (arg8 != 0) { r30 = 2; r29 = 1; }
    else { r30 = 1; r29 = 2; }
    buf = (s32 *)iosAlloc(lbl_80559248, 0x40);
    if (buf == 0) {
        OSReport(str + 0x15c, 0x40);
        res = -0x16;
        goto done;
    }
    buf[0] = arg1;
    buf[1] = arg2;
    buf[2] = arg3;
    buf[3] = arg4;
    buf[6] = arg5;
    buf[4] = arg6;
    buf[5] = arg7;
    buf[7] = 1;
    m = (s32 *)lbl_8055DD80; m[0] = (s32)buf;
    m = (s32 *)lbl_8055DD80; m[1] = 0x24;
    m = (s32 *)lbl_8055DD80; m[2] = arg5;
    m = (s32 *)lbl_8055DD80; m[3] = arg6 * arg7;
    m = (s32 *)lbl_8055DD80; m[4] = (s32)lbl_8055DD74;
    m = (s32 *)lbl_8055DD80; m[5] = 0x10;
    if (arg10 != 0) {
        s32 *cb1c = (s32 *)iosAlloc(lbl_80559248, 0x1c);
        if (cb1c == 0) {
            OSReport(str + 0x188);
            res = -0x16;
            goto done;
        }
        cb1c[0] = arg10;
        cb1c[1] = arg11;
        cb1c[5] = arg9;
        cb1c[3] = arg1;
        cb1c[6] = (s32)buf;
        res = IOS_IoctlvAsync(arg0, 7, r30, r29, lbl_8055DD80, (void *)fn_800BAA8C, cb1c);
        if (res != 0) OSReport(str + 0x19c, res);
    } else {
        res = IOS_Ioctlv(arg0, 7, r30, r29, lbl_8055DD80);
        if (res != 0) OSReport(str + 0x19c, res);
        else if (arg9 != 0) *(s32 *)arg9 = *(s32 *)lbl_8055DD74;
    }
done:
    if (arg10 != 0 && res != 0 && buf != 0) iosFree(lbl_80559248, buf);
    return res;
}
extern "C" s32 fn_800B3304(void *, void *);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 VFiPFENT_searchEmptyTailSFN(void *arg0, u32 firstIndex, void *templateArg, s32 *bitmap) {
    u8 local[0x90];
    register void *context = *(void **)((u8 *)arg0 + 0x34);
    register void *state = arg0;
    register u32 first = firstIndex;
    register s32 *bits = bitmap;
    register void *templateName = templateArg;
    register u32 mask;
    register u8 *shortName;
    u32 *dst = (u32 *)(local + 0x28);
    u32 a, b, tilde, end, digits, i, index;
    s8 ch, terminal;
    fn_800A499C((const char *)bits, 0, *(u32 *)((u8 *)context + 0x1F74) * 4);
    b = ((u32 *)state)[0]; a = ((u32 *)state)[1]; dst[0] = b; dst[1] = a;
    a = ((u32 *)state)[2]; b = ((u32 *)state)[3]; dst[2] = a; dst[3] = b;
    a = ((u32 *)state)[4]; b = ((u32 *)state)[5]; dst[4] = a; dst[5] = b;
    a = ((u32 *)state)[6]; b = ((u32 *)state)[7]; dst[6] = a; dst[7] = b;
    a = ((u32 *)state)[8]; b = ((u32 *)state)[9]; dst[8] = a; dst[9] = b;
    a = ((volatile u32 *)state)[10]; b = ((volatile u32 *)state)[11]; dst[10] = a; dst[11] = b;
    a = ((volatile u32 *)state)[12]; b = ((volatile u32 *)state)[13]; dst[12] = a; dst[13] = b;
    state = (void *)fn_800AC1B4(local + 0x20, 0);
    shortName = local + 0x10;
    mask = 1;
    do {
        if ((s32)state != 0) return (s32)state;
        if (local[0x6C] != 0 && local[0x6C] != 0xE5 &&
            (local[0x77] & 0x0F) != 0x0F && (local[0x77] & 8) == 0) {
            fn_800B3BEC(local + 0x10, local + 0x6C, (u8)0);
            tilde = 1;
            while ((s8)shortName[tilde] != '~' && (s8)shortName[tilde] != 0 && tilde < 7)
                tilde++;
            if (tilde < 7 && *(volatile s8 *)(shortName + tilde) == '~') {
                end = tilde + 1;
                while ((ch = (s8)shortName[end]) >= '0' && ch <= '9') end++;
                terminal = *(volatile s8 *)(shortName + end);
                if (terminal == '.' || terminal == 0) {
                    digits = end - tilde - 1;
                    state = (void *)0;
                    i = digits;
                    while (i != 0) {
                        state = (void *)((s32)(s8)shortName[end - i] + (s32)(u32)state * 10 - 0x30);
                        i--;
                    }
                    fn_800A4AAC((char *)local, (char *)templateName);
                    VFiPFPATH_parseShortNameNumeric((char *)local, (u32)state);
                    if (fn_800B3304(local + 0x10, local) == 0 &&
                        (u32)state >= first &&
                        (u32)state < first + *(u32 *)((u8 *)context + 0x1F74) * 32) {
                        index = (u32)state - first;
                        bits[index >> 5] |= mask << index;
                    }
                }
            }
        }
        state = (void *)VFiPFENT_ITER_Advance(local + 0x20, 0);
    } while (VFiPFENT_ITER_IsAtLogicalEnd(local + 0x20) == 0);
    return 0;
}
#pragma pop
extern "C" void VFiPFSTR_ToUpperNStr(s32 arg0, u16 arg1, u8 *arg2) {
    u8 *var_r31;
    u8 *var_r30;
    s32 var_r29;
    u32 var_r3;
    u8 *var_r4;
    s32 var_r0;
    u8 temp_r3;

    var_r30 = arg2;
    var_r29 = (u16)arg1;
    if (*(u32 *)((u8 *)arg0 + 0xC) == 1U) {
        var_r31 = *(u8 **)arg0;
        goto single_check;
        do {
            *var_r30 = (u8)fn_800A485C((s32)(s8)temp_r3);
            var_r30 += 1;
            var_r31 += 1;
            var_r29 -= 1;
        single_check:
            if ((u16)var_r29 == 0) {
                break;
            }
            temp_r3 = *var_r31;
        } while ((s8)temp_r3 != 0);
    } else {
        var_r4 = *(u8 **)arg0;
        goto wide_check;
    wide_body:
        var_r0 = 0;
        if ((var_r3 >= 0x61U) && (var_r3 <= 0x7AU)) {
            var_r0 = 1;
        }
        if (var_r0 != 0) {
            var_r3 -= 0x20;
        }
        var_r30[0] = (u8)var_r3;
        var_r4 += 2;
        var_r29 -= 1;
        var_r30[1] = (u8)(var_r3 >> 8);
        var_r30 += 2;
        goto wide_check;
    wide_check:
        if ((u16)var_r29 == 0) {
            goto wide_done;
        }
        var_r3 = *(u16 *)var_r4;
        if (var_r3 != 0) {
            goto wide_body;
        }
    wide_done:
        *var_r30 = 0;
    }
    *var_r30 = 0;
}
