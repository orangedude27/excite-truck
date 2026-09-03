#include <types.h>
#include <math.h>

/* Review carves for the REXE01 nw4hbm misc cluster
 * (auto_03_800DFC68_text / auto_03_800E252C_text):
 *
 *   GetFrameMaterial__Q36nw4hbm3lyt6WindowCFUl
 *   SinFIdx__Q24nw4r4mathFf / CosFIdx__Q24nw4r4mathFf
 *   __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8
 *   Instance__15EmissionManagerFv
 *   GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv
 *
 * Review-only; not configured.
 */

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, int line,
                                              const char* fmt, ...);
extern "C" void fn_80128668(void*);

#pragma push
#pragma small_data off
extern u8 lbl_80320C14[];
extern u8 lbl_80320CC8[];
extern u8 lbl_80321F80[];
extern u8 lbl_80321FAC[];
extern u8 lbl_80320E38[];      // nw4r math SinCosTbl (4 f32/entry)
extern u8 lbl_80320E38_alias[];
#pragma pop

/* ------------------------------------------------------------------ */
/* Window::GetFrameMaterial(u32)                                       */
/* ------------------------------------------------------------------ */
extern "C" void* GetFrameMaterial__Q36nw4hbm3lyt6WindowCFUl(void* this_,
                                                             u32 idx) {
    void* base;
    void* pMat;

    if (idx >= 8) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80320C14, 0x292,
                                     (const char*)lbl_80320CC8);
    }

    if (idx >= ((u8*)this_)[0x100]) {
        return NULL;
    }

    base = *(void**)&((u8*)this_)[0xFC];
    pMat = *(void**)&((u8*)base)[idx * 8 + 4];

    return pMat;
}

/* ------------------------------------------------------------------ */
/* nw4r::math::SinFIdx / CosFIdx — fidx trig table interpolation       */
/* ------------------------------------------------------------------ */
/* fidx format: 0x10000 == 1.0.  Table entries (16 bytes): sin_val,    */
/* cos_val, sin_delta, cos_delta.                                      */

extern "C" u16 OSf32tou16(f32 arg);
extern "C" f32 OSu16tof32(u16 arg);

extern "C" f32 SinFIdx__Q24nw4r4mathFf(f32 fidx) {
    f32 absFidx = fabsf(fidx);
    u16 whole;
    f32 frac;
    f32 sin;
    f32* tbl = (f32*)lbl_80320E38;

    while (absFidx >= 65536.0f) {
        absFidx -= 65536.0f;
    }

    whole = OSf32tou16(absFidx);
    frac = absFidx - OSu16tof32(whole);

    sin = tbl[(whole & 0xFF) * 4 + 0] + frac * tbl[(whole & 0xFF) * 4 + 2];

    return (fidx < 0.0f) ? -sin : sin;
}

extern "C" f32 CosFIdx__Q24nw4r4mathFf(f32 fidx) {
    f32 absFidx = fabsf(fidx);
    u16 whole;
    f32 frac;
    f32 cos;
    f32* tbl = (f32*)lbl_80320E38;

    while (absFidx >= 65536.0f) {
        absFidx -= 65536.0f;
    }

    whole = OSf32tou16(absFidx);
    frac = absFidx - OSu16tof32(whole);

    cos = tbl[(whole & 0xFF) * 4 + 1] + frac * tbl[(whole & 0xFF) * 4 + 3];

    return cos;
}

/* ------------------------------------------------------------------ */
/* MemorySoundArchive dtor (clone at 0x800E2CB8)                       */
/* ------------------------------------------------------------------ */
extern "C" void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, u32);

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800E2CB8(
    void* this_, s32 flag) {
    if (this_) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(this_, 0);

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* ------------------------------------------------------------------ */
/* EmissionManager::Instance() — game singleton                        */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80407F6C[]; // singleton storage
#pragma pop
extern s8 lbl_8055DE18;   // initialized flag

extern "C" void fn_800E279C(void* p);   // ctor
extern "C" void fn_800E2D74(void* p);   // dtor
extern "C" void __register_global_object(void* p, void* dtor, void* allocator);

#pragma push
#pragma small_data off
extern u8 lbl_80407F60[];
#pragma pop

extern "C" void* Instance__15EmissionManagerFv(void) {
    if (lbl_8055DE18 == 0) {
        fn_800E279C(&lbl_80407F6C);
        __register_global_object(&lbl_80407F6C, (void*)&fn_800E2D74,
                                 (void*)&lbl_80407F60);
        lbl_8055DE18 = 1;
    }

    return &lbl_80407F6C;
}
/* ------------------------------------------------------------------ */
/* AxManager::GetZeroBufferAddress()                                   */
/* ------------------------------------------------------------------ */
extern "C" void* GetZeroBufferAddress__Q46nw4hbm3snd6detail9AxManagerFv(
    void* this_) {
    void* p;

    if (((void**)this_)[0x04 / 4] == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80321F80, 0x172,
                                     (const char*)lbl_80321FAC);
    }

    p = ((void**)this_)[0x04 / 4];

    return p;
}
/* ------------------------------------------------------------------ */
/* AxManager::UnregisterCallback(CallbackListNode*)                    */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80322094[];
extern u8 lbl_80322070[];
#pragma pop

extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
    void* list, void* node);

extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(
    void* this_, void* pNode) {
    u32 level;

    level = OSDisableInterrupts();

    if (pNode == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80322094, 0x233,
                                     (const char*)lbl_80322070);
    }

    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(
        &((u8*)this_)[0x08], pNode);

    OSRestoreInterrupts(level);
}

/* ------------------------------------------------------------------ */
/* AxVoice ctor (clone at 0x800E44BC)                                  */
/* ------------------------------------------------------------------ */
#pragma push
#pragma small_data off
extern u8 lbl_80322498[]; // AxVoice vtable
#pragma pop

extern "C" void* __ct__Q46nw4hbm3snd6detail7AxVoiceFv(void* this_) {
    ((u32*)this_)[0x00 / 4] = 0;
    ((u32*)this_)[0x04 / 4] = 0;
    ((u32*)this_)[0x08 / 4] = (u32)&lbl_80322498;
    ((u32*)this_)[0x10C / 4] = 0;
    ((u8*)this_)[0x11C] = 0;
    ((u8*)this_)[0x11D] = 0;
    ((u8*)this_)[0x11E] = 0;
    ((u8*)this_)[0x11F] = 0;
    ((u8*)this_)[0x121] = 0;
    ((u8*)this_)[0x122] = 0;
    ((u8*)this_)[0x123] = 0;
    ((u32*)this_)[0x1A8 / 4] = 0;
    ((u32*)this_)[0x1AC / 4] = 0;
    ((u32*)this_)[0x0C / 4] = 0;
    ((u32*)this_)[0x10 / 4] = 0;
    ((u32*)this_)[0x14 / 4] = 0;
    ((u32*)this_)[0x18 / 4] = 0;
    ((u32*)this_)[0x1C / 4] = 0;
    ((u32*)this_)[0x20 / 4] = 0;
    ((u32*)this_)[0x24 / 4] = 0;
    ((u32*)this_)[0x28 / 4] = 0;

    return this_;
}
