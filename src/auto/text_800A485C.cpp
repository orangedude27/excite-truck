#include <types.h>
extern "C" s32 fn_800A7090(void);
extern "C" s32 fn_800A7610(void *);
extern "C" s32 fn_800A76A0(void *);
extern "C" void *lbl_8055DD94;
extern "C" u32 lbl_8055DD90;
extern "C" s32 lbl_8055DD30;
extern "C" s32 fn_800B8004(s32);
extern "C" s32 fn_800B8048(s32);
extern "C" s32 fn_800B960C(s32, s32, s32, s32, s32 *, s32);
extern "C" s32 lbl_803D2140[];
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void *lbl_80407780[];
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
extern "C" s32 fn_800B74B8(s8);
extern "C" s32 fn_800A5990(s32);
extern "C" s32 fn_800A59CC(s32);
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
extern "C" s32 lbl_80405D18;
extern "C" s32 fn_800BA49C(s32, s32, s32, s32);
extern "C" const char lbl_8031B190[];
extern "C" const char lbl_8031B1C0[];
extern "C" s32 fn_800B76E8(s8);
  #include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#include <revolution/ARC/arc.h>
#include <string.h>
#pragma opt_tail_call on

namespace homebutton {
class HomeButton {
public:
    s32 getPaneNo(const char *name);
};
}
extern "C" const char *lbl_8031D990[];
extern "C" const char *lbl_8031E218[];
extern "C" const char lbl_8031E770[];
extern "C" const char lbl_8031E83C[];
extern "C" void *List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(void *, u16);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" const char lbl_8031E938[];
extern "C" const char lbl_805597D0[];
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

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_800A6048();
s32 fn_800A61D0(void *);
s32 fn_800B75C4(void);
void fn_800C4BD0(void) __attribute__((noreturn));
extern "C" void fn_80128668(void);
void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, s32);
void fn_800DCE10(void*, s32);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void fn_800D1B1C(void);
extern "C" void fn_800D16C4(OSAlarm *, void *);

extern u32 lbl_8055DDB0;
extern "C" const char lbl_8031E9C0[];
DECL_SECTION(".sdata") extern u8 lbl_8055DDA8[];
extern "C" s32 fn_800D1E5C(void *arg0, s32 arg1);
extern "C" void fn_800D1668(s32 arg0, s32 arg1);
extern "C" s32 fn_800604E8(s32, s32, void *);
extern u32 lbl_8055DDF8;
extern "C" void fn_800D1C48(void);

#include <revolution/MEM/mem_allocator.h>
#include <revolution/MEM/mem_expHeap.h>
#include <revolution/MEM/mem_frameHeap.h>
extern "C" s32 fn_800D1EA8(void *arg0, s32 arg1);

extern "C" void fn_800B7610(OSAlarm *alarm, OSContext *ctx);


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
extern "C" s32 VFiPFSTR_ToUpperNStr(s32, s32, u8*);
extern "C" void fn_800B63FC(void);
extern "C" void fn_800B65A0(s8);
extern "C" s32 lbl_80559208;

void fn_800A5954(void) {
    fn_800A6048();
}

extern "C" s32 fn_800A71D8(void *);
extern "C" s32 fn_800A73A0(void *, u16, s32);
extern "C" s32 fn_800A7338(void *);
extern "C" s32 fn_800A7568(void *, s32);
extern "C" s32 fn_800A607C(void);
extern "C" s32 fn_800A5958(void *arg0, s32 *arg1) {
    s32 result;
    *arg1 = 0;
    result = fn_800A607C();
    return result & ((-result | result) >> 31);
}

void fn_800A5990(void) {
    fn_800A61D0(0);
}

extern "C" s32 fn_800A5994(void *arg0, s32 p1, s32 *arg2) {
    s32 result;
    *arg2 = 0;
    result = fn_800A7090();
    return result & ((-result | result) >> 31);
}

extern "C" s32 fn_800A7688(void *, void **, void **);
extern "C" s32 fn_800A7214(void *);
extern "C" s32 fn_800A535C(void);
extern "C" s32 fn_800A52DC(void);
extern "C" s32 VFipdm_disk_convert_sector_into_block(s32 arg1, s32 arg2, u32 size, s32 *arg4, s32 *arg5) {
    u32 shift;

    *arg4 = arg1;
    if (size > 0x200) {
        shift = (size >> 9) & 0x7F;
        *arg5 = arg2;
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
    } else {
        *arg5 = arg2;
        if (size < 0x200)
            return 4;
    }
    return 0;
}

extern "C" s32 VFipdm_disk_convert_block_into_sector(u32 arg1, u32 arg2, u32 size, u32 *arg4, u32 *arg5) {
    u32 shift;

    *arg4 = arg1;
    if (size > 0x200) {
        shift = (size >> 9) & 0x7F;
        *arg5 = arg2;
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
    } else {
        *arg5 = arg2;
        if (size < 0x200)
            return 4;
    }
    return 0;
}

extern "C" s32 fn_800A71C4(u32 *arg0) {
    return ((u32) *arg0 >> 2U) & 1;
}

extern "C" void fn_800A71D0(void *arg0, s32 arg1) {
    (*(s32 *)((u8 *)arg0 + 0x14)) = arg1;
}

extern "C" s32 fn_800A6268(s32);
extern "C" s32 fn_800A71D8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x14));
}

extern "C" s32 fn_800A71E0(void *arg0) {
    s32 temp_r3;

    temp_r3 = fn_800A6268((*(s32 *)((u8 *)arg0 + 4)));
    return temp_r3 & ((s32) (-temp_r3 | temp_r3) >> 0x1F);
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
    s32 temp_r3;
    if (arg2 >= *(u32 *)((u8 *)arg0 + 8))
        return 0x10;
    temp_r3 = VFiPFCACHE_DoReadNumSector((u8 *)arg0 + 0x1634, (s32)arg1, arg2, arg3, arg4);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
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
extern "C" s32 VFiPFCACHE_SearchForPage(s32, s32);
extern "C" s32 fn_800A8AD4(s32);
extern "C" s32 VFiPFCACHE_WriteFATSectorAndFreeIfNeeded(void *arg0, s32 arg1, u32 arg2) {
    s32 temp_r3;
    if (arg2 >= *(u32 *)((u8 *)arg0 + 8))
        return 0x10;
    temp_r3 = fn_800A861C(arg0, (u8 *)arg0 + 0x1630, arg1, arg2);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" void fn_800A90F8(void *arg0, s32 arg1) {
    VFiPFCACHE_SearchForPage(*(s32 *)((u8 *)arg0 + 0x1634), arg1);
}

extern "C" s32 fn_800A9104(void *arg0) {
    s32 temp_r3 = fn_800A8AD4(*(s32 *)((u8 *)arg0 + 0x1630));
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 31);
}

extern "C" void fn_800AF2B8(void *);
extern "C" void fn_800AF2B8(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

extern "C" s32 fn_800AFF28(void *arg0, s32 arg1, u16 arg2) {
    extern s32 fn_800B5618(void *, void *, u16, u16, s32);
    u16 sp8;
    u32 offset = arg1 << 1;
    u16 mask = *(u16 *)arg0 - 1;
    u8 shift = *((u8 *)arg0 + 0x20);
    u32 index = *(u32 *)((u8 *)arg0 + 0x28) + (offset >> shift);
    u16 sector = offset & mask;
    s32 result = 0;
    u32 i = 0;
    sp8 = (u16)((arg2 >> 8) | (arg2 << 8));
    while (i < *((u8 *)arg0 + 0x22)) {
        s32 status = fn_800B5618(arg0, &sp8, (u16)index, sector, 2);
        if (status != 0 && result == 0)
            result = status;
        i++;
        index = (u16)(index + *(u32 *)((u8 *)arg0 + 0xC));
    }
    return result;
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

extern "C" s32 fn_800B6928(s8);
extern "C" s32 fn_800B3754(s32, s32, s32);
extern "C" s32 fn_800AF574(void *);
extern "C" s32 fn_800B5618(void *, void *, u16, u16, s32);
extern "C" s32 fn_800B317C(s32 arg0, s32 arg1) {
    extern s32 fn_800B3754(s32, s32, s32);
    return fn_800B3754(arg0, arg1, 1) == 0;
}

extern "C" void fn_800B3330(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((u8 *)arg0 + 0)) = arg1;
    (*(s32 *)((u8 *)arg0 + 4)) = arg1;
    (*(s32 *)((u8 *)arg0 + 0xC)) = arg2;
}

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

extern "C" s32 fn_800A4BF4(s32, u16 *, s16 *);
extern "C" s32 VFiPFPATH_transformInUnicode(s16 *dst, s32 src, s32 unused) {
    s32 count = 0;
    s32 offset = 0;
    s16 *out = dst;
    while (*(s8 *)(src + offset) != 0) {
        ((s32 (*)(s32, s16 *))(*(u32 *)((u8 *)lbl_803D2140 + 0x48)))(src + offset, out);
        s16 inLen;
        s16 outLen;
        fn_800A4BF4(0, (u16 *)&inLen, &outLen);
        count++;
        out = (s16 *)((u8 *)out + (outLen & ~1));
        offset += inLen;
    }
    *out = 0;
    return count;
}

extern "C" u8 lbl_80559230;
extern "C" u8 lbl_80559231;
s32 fn_800B4D00(void) {
    u8 data[2];
    data[0] = lbl_80559230;
    data[1] = lbl_80559231;
    return VFiPFSTR_StrNCmp(0, data, 0, 1, 2) == 0;
}

s32 fn_800B51FC(u8 *arg0, s32 arg1) {
    s32 value = arg1;
    u32 divisor = 10;
    u32 place = 1;
    s32 digits = 7;
    u8 *p = arg0 + 7;

    while (digits > 1 && value != 0) {
        u32 rem = value % divisor;
        if (rem != 0) {
            value -= rem;
            *p += (s8)(rem / place);
        }
        divisor *= 10;
        digits--;
        p--;
        place *= 10;
    }
    return 0;
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

s32 fn_800B73CC(s32 arg0, s32 arg1) {
    if (arg0 == 0)
        return arg1;
    return 0;
}

extern "C" s32 fn_800B73E4(s32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 == 1) return 1;
    return -1;
}

extern "C" void fn_800B7408(s32* arg0, void* arg1) {
    extern s32 fn_800B6628(void*, s32);
    extern s32 fn_800B73BC(s32);
    extern s32 lbl_803D2140[];
    s32* p = arg0;
    s32 result = 0;
    if (arg0 == 0 || *arg0 == 0) {
        result = 10;
        *(s32*)((u8*)lbl_803D2140 + 0x40) = 10;
        fn_800B73BC(result);
        return;
    }
    while (*p != 0) {
        if (arg1 != 0) result = fn_800B6628(arg1, *(s32*)((u8*)arg1 + 0x50));
        else result = fn_800B6628(0, 0);
        if (result != 0) { fn_800B73BC(result); return; }
        ++p;
    }
    fn_800B73BC(result);
}

extern "C" void* fn_800B1BDC(void*);
extern "C" void fn_800B73BC(void*);
extern "C" void fn_800B74E0(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800B1BDC(alarm));
}

extern "C" void* fn_800B224C(void*);
extern "C" void fn_800B7504(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800B224C(alarm));
}

extern "C" void* fn_800B1FF4(void*);
extern "C" void fn_800B75EC(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800B1FF4(alarm));
}

extern "C" void* fn_800A9B0C(void*);
extern "C" void fn_800B7684(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800A9B0C(alarm));
}

extern "C" void fn_800B7710(void *arg0) {
    extern s32 fn_800B7F28(s32 *);
    s32 sp8;
    s32 spC;
    void *sp10;

    if (*(s32 *)arg0 == 0) {
        sp8 = 1;
        spC = 1;
        sp10 = (u8 *)arg0 + 0x10;
        *(s32 *)((u8 *)arg0 + 8) = fn_800B7F28(&sp8);
        *(s32 *)((u8 *)arg0 + 4) = 0;
        *(s32 *)((u8 *)arg0 + 0xC) = 0;
        *(s32 *)arg0 = 1;
    }
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

void fn_800B78EC(void) {

}

extern "C" void fn_800B78F4(void *arg0, void *arg1) {
    OSCalendarTime time;
    OSTicksToCalendarTime(OSGetTime(), &time);
    ((s32 *)arg0)[0] = time.mday;
    ((s32 *)arg0)[1] = time.month + 1;
    ((s32 *)arg0)[2] = time.min;
    ((s32 *)arg1)[0] = time.hour;
    ((s32 *)arg1)[1] = time.sec;
    ((s32 *)arg1)[2] = time.sec;
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

void fn_800B7C60(void) {
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
        lbl_80405D00[1](arg0);
}

extern "C" s32 fn_800B7E5C(s8 arg0) {
 s32 temp_r3 = fn_800B76E8(arg0);
 if (temp_r3 == -1) return -1;
 if (temp_r3 == 1) return 1;
 return (s32)(-temp_r3 | temp_r3) >> 31;
}

extern "C" s32 OSReport(const char *, ...);
extern "C" s32 OSWaitSemaphore(void);
extern "C" s32 fn_800B76E8(s8);
extern "C" const char lbl_8031B190[];
extern "C" const char lbl_8031B1C0[];
extern "C" const char lbl_8031B24C[];
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
    s32 result;
    result = NANDGetType((char *)&lbl_80405D18);
    if (result != 0) return result;
    if (*(s32 *)((u8 *)arg1 + 0xE4) & 4) result = 0;
    else result = NANDOpen((u8 *)arg1 + 4, (u8 *)arg1 + 0x58, 3);
    if (arg2 != 0) result = -0xC;
    if (result == 0) {
        *(s32 *)arg1 = arg0;
        return 0;
    }
    if (result < 0 && result == -0xC) {
        result = fn_800B814C(arg1);
        if (result == 0) *(s32 *)arg1 = arg0;
    }
    return result;
}

#pragma push
#pragma small_data off
#pragma pop
extern "C" s32 fn_800B8BE8(s32 arg0) {
    if (arg0 == 0) return -0x14;
    if (lbl_8055DD2C == 0) {
        if (NANDInit() != 0) return -0x15;
        if (NANDGetCurrentDir((char *)&lbl_80405D18) != 0) return -0x15;
        lbl_8055DD2C = lbl_8055DD2C + 1;
    }
    fn_800A68DC(arg0);
    return 0;
}

#pragma dont_inline
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
extern "C" u8 lbl_802F31F8[];
extern "C" s32 lbl_8055DD2C;
extern "C" s32 NANDInit(void);
extern "C" s32 NANDGetCurrentDir(char *);
extern "C" s32 lbl_80405D18;
extern "C" s32 fn_800BA49C(s32, s32, s32, s32);
extern "C" const char lbl_8031B190[];
extern "C" const char lbl_8031B1C0[];
extern "C" s32 fn_800B76E8(s8);
extern "C" s32 fn_800B94D4(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(u8 **)arg0 = lbl_802F31F8;
    return 0;
}

#pragma push
#pragma small_data off
extern "C" s32 fn_800BA160(s32 arg0) {
    s32 value;
    s32 mask;
    if (arg0 == 0) return 1;
    value = *(volatile s32 *)(lbl_80407300 + 0x10);
    mask = (-value | value) >> 31;
    return 6 & ~mask;
}
#pragma push
#pragma small_data off
extern "C" u32 lbl_8031C2B8[];
extern "C" u32 lbl_802F3F54[];
extern "C" s32 fn_800BA194(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 == 0 || arg1 == 0 || arg4 != 0) {
        return 1;
    }
    return fn_800BA49C(arg3, arg1, arg2, *(s32 *)(lbl_80407300 + 4));
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
    u32 cleared;

    if (arg0 == 0) {
        return 1;
    }
    flags = *(volatile u32 *)lbl_80407300;
    if (flags & 2) {
        *(volatile s32 *)lbl_80407300 &= 0xFFFFFFFD;
    }
    flags = *(volatile u32 *)lbl_80407300;
    cleared = flags & ~1U;
    *(volatile s32 *)lbl_80407300 = (s32)cleared;
    *(s32 *)((u8 *)lbl_80407300 + 0xC) = 0;
    *(u8 *)((u8 *)lbl_80407300 + 0x14) = 0;
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
            fn_800BA974(*(s32*)(lbl_80407300 + 0xC), &value, 1) == 1) {
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

extern "C" void fn_800BBCB4(void* context) {
    *(s32*)((u8*)context + 0x24) = 0;
    IOS_Close(*(s32*)context);
    *(s32*)context = -1;
}

void fn_800BEDE0(void *arg0, void *arg1) {
    u32 rate;
    *(s32 *)arg1 = *(s32 *)((u8 *)arg0 + 4) == 0;
    rate = 0xAC44;
    switch (*(s16 *)((u8 *)arg0 + 0x1C)) {
    case 1: rate = 0xBB80; break;
    case 2: rate = 0x7D00; break;
    }
    if (*(s32 *)arg1 == 0)
        rate = (rate + (rate >> 31)) >> 1;
    *(u32 *)((u8 *)arg1 + 4) = rate;
    *(s32 *)((u8 *)arg1 + 8) = (s8)*(u8 *)arg0;
    *(s32 *)((u8 *)arg1 + 0x10) = *(s32 *)((u8 *)arg0 + 0xED74);
    *(s32 *)((u8 *)arg1 + 0xC) = *(s32 *)((u8 *)arg0 + 0xED70);
}

u16 fn_800C0DF8(u8 *arg0, s32 arg1, u32 *arg2) {
    u32 bits = *arg2;
    u32 index = (bits >> 3) & 0x1FFF;
    s32 shift = 0x18 - (bits & 7);
    *arg2 = bits + arg1;
    u8 a, b, c;
    if (index < 0x1FFE) {
        a = arg0[index];
        b = arg0[index + 1];
        c = arg0[index + 2];
    } else {
        a = arg0[index];
        b = arg0[(index + 1) & 0x1FFF];
        c = arg0[(index + 2) & 0x1FFF];
    }
    u32 value = (a << 16) | (b << 8) | c;
    return (value & lbl_802F3F54[shift]) >> (shift - arg1);
}

void fn_800C3D9C(void) {
    fn_800C4BD0();
}

extern "C" void* fn_800C4B8C(s32 arg0) {
    void *old = lbl_8055DD94;
    void *next = (char *)old + (arg0 & 0xFFFFFFFC) + ((s32)((arg0 & 3) ? 4 : 0));
    if ((u32)next > (u32)old + 0x1FFFFFFF) {
        return NULL;
    }
    lbl_8055DD94 = next;
    return old;
}

extern void *lbl_8055DD94;
extern "C" void fn_800C4BD0(void* hi) {
    lbl_8055DD94 = hi;
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

extern "C" s32 fn_800C673C(void) {
    if (*(s32*)((u8*)lbl_8055DD98 + 0x10) != 0x12) {
        return -1;
    }
    return *(s32*)((u8*)lbl_8055DD98 + 0xAC);
}

extern "C" void fn_800C675C(u32 size) {
    fn_800CEBE0(lbl_8055DD98, size);
}

u8 fn_800C6768(void) {
    return *(u8 *)((char *)lbl_8055DD98 + 0x88);
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

extern "C" void __dt__Q36nw4hbm3lyt19ArcResourceAccessorFv(void* this_ptr, s32 arg1) {
    void* r30 = this_ptr;
    s32 r31 = arg1;
    
    if (r30 != 0) {
        void* list_ptr = (u8*)r30 + 0x24;
        if (list_ptr != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(list_ptr, 0);
        }
        fn_800DCE10(r30, 0);
    }
    if (r31 > 0) {
        fn_80128668();
    }
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

extern "C" void fn_800CF3B4(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    *(s32 *)((u8 *)arg0 + 0x18) = arg1;
    *(f32 *)((u8 *)arg0 + 4) = arg2;
    *(f32 *)((u8 *)arg0 + 8) = arg3;
    *(f32 *)((u8 *)arg0 + 0x10) = arg4;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
    if (arg1 == 1) {
        *(f32 *)((u8 *)arg0 + 0xC) = arg2;
    } else {
        *(f32 *)((u8 *)arg0 + 0xC) = arg3;
    }
}

extern "C" void fn_800CF3EC(void *arg0) {
    f32 val;
    if (*(s32 *)((u8 *)arg0 + 0x18) == 1)
        val = *(f32 *)((u8 *)arg0 + 4);
    else
        val = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 0xC) = val;
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

void fn_800CFAC8(void *arg0) {
 u8 *p=(u8*)arg0; p[0x18]=0; p[4]=0; p[5]=0; p[6]=0; p[7]=0; p[8]=0; p[9]=0; p[0xA]=0; p[0xB]=0;
}

extern "C" void fn_800CFBB8(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x28) = arg1; }

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
    u16 i = 0;
    void *list = (u8 *)arg0 + 8;
    do {
        void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(list, i);
        void *obj = *(void **)((u8 *)entry + 4);
        ((void (*)(void *))(*(u32 *)(*(u32 *)obj + 0x10)))(obj);
        i++;
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    } while (i < *(u16 *)((u8 *)arg0 + 0x10));
}

extern "C" void draw__Q310homebutton3gui7ManagerFv_800CFE88(void *arg0) {
    u16 i = 0;
    void *list = (u8 *)arg0 + 8;
    do {
        void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(list, i);
        void *obj = *(void **)((u8 *)entry + 4);
        ((void (*)(void *))(*(u32 *)(*(u32 *)obj + 0x18)))(obj);
        i++;
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    } while (i < *(u16 *)((u8 *)arg0 + 0x10));
}

void setAllComponentTriggerTarget__Q310homebutton3gui7ManagerFb(void *arg0, bool arg1) {
    u16 i = 0;
    void *list = (u8 *)arg0 + 8;
    do {
        void *entry = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs(list, i);
        void *obj = *(void **)((u8 *)entry + 4);
        ((void (*)(void *, bool))(*(u32 *)(*(u32 *)obj + 0x50)))(obj, arg1);
        i++;
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
    } while (i < *(u16 *)((u8 *)arg0 + 0x10));
}

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
    lbl_8055DDA0 = 0;
    void *p = (u8 *)arg1 + 0x10;
    void *q = *(void **)p;
    q = (u8 *)q + 0x10;
    (*(void (**)(void *, void *))(*(void ***)arg0 + 20))(arg0, q);
}

extern "C" void fn_800D0560(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C) = arg1;
}

extern "C" s32 getPaneComponentByPane__Q310homebutton3gui11PaneManagerFPQ36nw4hbm3lyt4Pane(void *arg0, void *arg1) {
    u16 i = 0;
    void *item;
    while (i < *(u16 *)((u8 *)arg0 + 0x10)) {
        if (*(void **)((u8 *)arg0 + 8) == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_805597D0, 0xCF, lbl_8031E938);
        }
        item = List_GetNth__Q26nw4hbm2utFPCQ36nw4hbm2ut4ListUs((u8 *)arg0 + 0x18, i);
        if (*(void **)item == arg1) return *(s32 *)((u8 *)item + 4);
        i++;
    }
    return 0;
}

extern "C" s32 fn_800D0814(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x24); }

extern "C" s32 fn_800D0AA8(void *arg0) { return (*(u8 *)((u8 *)arg0 + 0xCF)) & 1; }

extern "C" s32 fn_800D0AB4(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" s32 fn_800D0B90(void) { return 0; }

extern "C" void fn_800D0B98(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x1C) = arg1; }

extern "C" void fn_800D0BA0(void) {

}

void fn_800D0BA4(void *arg0, D0BA4Dispatch *arg1) {
    *(D0BA4Dispatch **)((char *)arg0 + 4) = arg1;
    if (arg1 != 0) {
        arg1->vf3((D0BA4Dispatch *)arg0);
    }
}

extern "C" s32 fn_800D0BD0(void) { return 0; }

extern "C" void soundOnCallback__Q210homebutton10ControllerFP7OSAlarmP9OSContext(OSAlarm *alarm, OSContext *) {
    void *entry;
    void *sound;
    entry = lbl_80407780[(s32)OSGetAlarmUserData(alarm)];
    sound = *(void **)entry;
    if (fn_80060C7C(sound) != 0) fn_80060CC0(sound, 3, 0);
    *((u8 *)entry + 0x41) = 0;
}

extern "C" void *fn_800D0E68(void *arg0, s32 arg1, s32 arg2) {
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
        OSCreateAlarm((OSAlarm *)(lbl_80407600 + temp_r30));
        OSCreateAlarm((OSAlarm *)(lbl_80407600 + 0xC0 + temp_r30));
        *(void **)(lbl_80407600 + 0x180 + arg1 * 4) = arg0;
    }
    return arg0;
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
extern "C" void fn_800D51F4(long, long, long, long, long, long);
#pragma opt_tail_call on
extern "C" void fn_800D11F0(void *arg0) {
    Connect__Q210homebutton9RemoteSpkFl(*(void **)((char *)arg0 + 0x24), *(s32 *)arg0);
}
extern "C" void fn_800D1200(void) {

}

extern "C" void fn_800D1204(void* arg0, f32 arg1) { *(f32*)((u8*)arg0 + 4) = arg1; }

extern "C" s32 fn_800D1E78(void *, s32, s32);
s32 isPlayingSoundId__Q210homebutton10ControllerCFi(void *arg0, s32 arg1) {
    if (fn_800D1E5C(*(void **)((u8 *)arg0 + 0x24), *(s32 *)arg0) == 0) {
        return 0;
    }
    return fn_800D1E78(*(void **)((u8 *)arg0 + 0x24), *(s32 *)arg0, arg1);
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
    if (((s32 (*)(void *))fn_800D1E5C)(*(void **)((u8 *)arg0 + 0x24)) != 0) return;
    *(u8 *)((u8 *)arg0 + 0x1C) = 1;
    WPADControlMotor(*(s32 *)arg0, 1);
}

extern "C" s32 getInfoAsync__Q210homebutton10ControllerFP8WPADInfo(void *this_ptr, void *arg1) {
    u32 val = (u32)*(s32 *)this_ptr;
    
    if ((s32)val >= 4) {
        return -2;
    }
    
    if (fn_800D1E5C((void *)((u8 *)this_ptr + 0x24), (s32)val) != 0) {
        return -2;
    }
    
    if (((u8 *)this_ptr)[0x1C] != 0) {
        return -2;
    }
    
    return fn_800604E8((s32)val, (s32)(u32)arg1, (void *)&fn_800D1668);
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

extern "C" void *fn_800D1948(void *arg0, s32 arg1) {
    void *r26 = arg0;
    if (r26 != NULL) {
        *(u32 *)((u8 *)r26 + 0x1F0) = (u32)&lbl_8031E9C0;
        lbl_8055DDB0 = (u32)r26;
        if (arg1 != 0) {
            BOOL result = ARCInitHandle((void *)arg1, (ARCHandle *)((u8 *)r26 + 0x1D0));
            s32 neg = -result;
            s32 or_result = neg | result;
            ((u8 *)r26)[0x1EC] = (u8)(or_result >> 31);
        } else {
            ((u8 *)r26)[0x1EC] = 0;
        }
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
    if (((u8 *)this_ptr)[0x1EC] != 0) {
        OSAlarm *alarm = (OSAlarm *)((u8 *)this_ptr + 0x1A0);
        OSCreateAlarm(alarm);
        
        OSTime time = OSGetTime();
        s32 time_base = *(s32 *)0x800000F8;
        
        OSSetPeriodicAlarm(alarm, time_base >> 2, 0, (OSAlarmHandler)&fn_800D16C4);
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

extern "C" void fn_800D1C18(void) {
    void* r3 = OSGetAlarmUserData(NULL);
    fn_80060CC0(r3, 4, (u32)&fn_800D1C48);
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
extern void* lbl_804077C0;
extern void fn_800D2E3C(s32, s32, s32, s32);
extern void fn_800D24D4(void*, s32);
extern void* lbl_8055DDBC;
extern "C" void fn_800D2098(void*);
extern "C" void __VprintfThunk(void*);
extern "C" void Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct(void*, void*, const char*, void*);
extern "C" s32 fn_80116A30(void*);
extern "C" void fn_800D1C48(void);
extern "C" s32 fn_80116A38(void*);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void fn_800D1B1C(void);

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

extern "C" void fn_800D2FC8(void) {
    DCStoreRange((void *)lbl_80407BD8[0], lbl_80407BD8[1]);
}

extern "C" s32 fn_800D3824(void) {
    s32 val = lbl_8055DDD4;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}
extern "C" u8 fn_800D3838(u8 *arg0) {
    return *arg0;
}

#pragma opt_tail_call on
#pragma opt_tail_call on
#pragma opt_tail_call on
extern "C" s32 fn_800D40B4(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4) {
    void *r31 = lbl_8055DDD4_ptr;
    s32 r28 = (s32)arg0;
    s32 r29 = (s32)arg1;
    s32 r30 = (s32)arg2;
    
    while (r31 != NULL) {
        if (fn_800D3F94(r31, r28, r29, r30) != 0) {
            return 1;
        }
        r31 = *(void **)((u8 *)r31 + 0xC);
    }
    return 0;
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
extern "C" void *lbl_8031F168;
extern "C" void fn_800D4428(void *arg0) {
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(f32 *)((u8 *)arg0 + 0x10) = lbl_80560E60;
    *(void **)arg0 = lbl_8031F168;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s16 *)((u8 *)arg0 + 0x1C) = 0;
}

extern "C" void Bind__Q36nw4hbm3lyt18AnimTransformBasicFPQ36nw4hbm3lyt8Material(void *arg0, void *arg1) {
    u16 i = 0;
    u8 *entries = (u8 *)*(void **)((u8 *)arg0 + 0xC);
    u8 *offsets = entries + *(s32 *)(entries + 0x10);
    while (i < *(u16 *)(entries + 0xE)) {
        u8 *entry = entries + *(s32 *)(offsets + i * 4);
        if (entry[0x15] == 1 && fn_800D58F0((u8 *)arg1 + 4) != 0) {
            u8 *link = (u8 *)*(void **)((u8 *)arg0 + 0x18) + i * 0x10;
            *(void **)(link + 8) = arg0;
            *(u16 *)(link + 0xC) = i;
            AddAnimationLink__Q36nw4hbm3lyt8MaterialFPQ36nw4hbm3lyt13AnimationLink(arg1, link);
        }
        i++;
    }
}

void fn_800D54E0(long a, long b, long c, long d) {
    fn_800D51F4(a + 4, a + 0x30, b, c, d, b);
}

int fn_800D5500(void *obj, const char *name) {
    void *entry = *(void **)((char *)obj + 0x28);
    while (entry != (char *)obj + 0x28) {
        if (entry == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23d, lbl_8031F510);
        if (strcmp(name, (char *)entry + 8) == 0) {
            if (entry == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23d, lbl_8031F510);
            return *(int *)((char *)entry + 0x88);
        }
        entry = *(void **)entry;
    }
    return 0;
}

extern "C" void* fn_800D55B0(void *self, s32 arg1) {
    if (self != NULL) {
        *(void **)self = lbl_8031F428;
        Clear__Q46nw4hbm2ut6detail12LinkListImplFv((s32 *)self + 1);
        if ((u8 *)self + 0x10 != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 0x10, 0);
        }
        if ((u8 *)self + 4 != NULL) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((u8 *)self + 4, 0);
        }
        fn_800DCE10(self, 0);
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}

extern "C" s32 fn_800D5640(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *node = *(void **)((u8 *)arg0 + 8);
    void *end = (u8 *)arg0 + 8;
    while (node != end) {
        if (node == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F4A4, 0x23D, lbl_8031F480);
        }
        void *next = (u8 *)node + 8;
        if (node == NULL) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F4A4, 0x23D, lbl_8031F480);
        }
        s32 result = ((s32 (*)(long, long, long, long, long))fn_800D51F4)((long)next, (long)((u8 *)node + 0x24), arg1, arg2, arg3);
        if (result != 0) {
            return result;
        }
        node = *(void **)node;
    }
    return 0;
}

extern "C" int fn_800D56FC(void* arg0, const char* arg1, int) {
    char* node = *(char**)((char*)arg0 + 0x14);
    char* end = (char*)arg0 + 0x14;
    for (;;) {
        if (node == end) return 0;
        if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23D, lbl_8031F510);
        if (strcmp(arg1, node + 8) == 0) {
            if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031F534, 0x23D, lbl_8031F510);
            return *(int*)(node + 0x88);
        }
        node = *(char**)node;
    }
}

extern "C" void* fn_800D57AC(void* arg0, const void* arg1) {
    __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(arg0, arg1);
    *(const char**)arg0 = lbl_8031F540;
    return arg0;
}

extern "C" void* __dt__Q36nw4hbm3lyt8BoundingFv(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q36nw4hbm3lyt4PaneFv(arg0, 0);
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

extern "C" void DrawSelf__Q36nw4hbm3lyt8BoundingFRCQ36nw4hbm3lyt8DrawInfo(BoundingPane* self, const DrawInfo* info) {
    Vec2 pos;
    unsigned int color = 0x00FF00FF;
    if ((info->flag >> 3) & 1) {
        self->v24();
        pos = GetVtxPos__Q34nw4r3lyt4PaneCFv(self, 0xFFFF0000);
        DrawLine__Q36nw4hbm3lyt6detailFRCQ36nw4hbm4math4VEC2RCQ36nw4hbm3lyt4SizeQ36nw4hbm2ut5Color(&pos, (const Size*)((const char*)self + 0x4C), color);
    }
}

extern u32 lbl_8055DDE0;
extern "C" u32* fn_800D58B0(void) {
    return &lbl_8055DDE0;
}

void fn_800C7764(void *arg0, s8 arg1) {
    ((u8 *)arg0)[0x24] = (u8)arg1;
}

void fn_800C776C(void *arg0, s32 arg1) {
    ((u32 *)arg0)[0x24 / 4] = (u32)arg1;
}

void fn_800C790C(void *arg0) {
    u16 **ptr = *(u16 ***)((u8 *)arg0 + 4);
    u16 *var_r7 = *ptr;
    s32 var_r9 = 0;
    s32 var_r10 = 0;
    s32 var_r11 = 0;
    s32 var_r8 = 0;
    
    while (*var_r7 != 0) {
        if (*var_r7 == 0x22) {
            *var_r7 = 0;
            if (var_r11 == 0) {
                s32 temp_r4 = var_r10 * 0x18;
                var_r10++;
                var_r11 = 1;
                ((u32 *)((u8 *)arg0 + temp_r4 + var_r8))[0xB0 / 4] = (u32)(ptr + (var_r9 + 1) * 2);
                if (var_r10 == 7) {
                    var_r10 = 0;
                    var_r8 += 4;
                }
            } else {
                var_r11 = 0;
            }
        }
        var_r7 += 2;
        var_r9++;
    }
}

extern "C" u32* fn_800C7C68(void) {
    return &lbl_8055DDF8;
}

extern "C" void fn_800D15B4(void*);
extern "C" void fn_800CA148(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800D15B4(OSGetAlarmUserData(alarm));
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
    for (i = 0; i < 10; i++) {
        if (strcmp(name, lbl_8031E218[i]) == 0) {
            result = i + count;
            break;
        }
    }
    return result;
}

extern "C" s32 fn_800CEDE0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x2C);
}

extern "C" s32 fn_800A4A8C(s32);
extern "C" s32 fn_800A4B54(s32);
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

extern "C" void fn_800A53CC(void *arg0) { *(u16 *)((u8 *)arg0 + 0x1F8C) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F8C) & 0xFFFFFFEF); }

extern "C" s32 fn_800A53DC(void *arg0) { return ((u16)*(u16 *)((u8 *)arg0 + 0x1F8C) >> 5U) & 1; }

extern "C" void fn_800A53E8(void *arg0) { *(u16 *)((u8 *)arg0 + 0x1F8C) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F8C) & 0xFFFFFFDF); }

extern "C" s32 fn_800A53F8(void *arg0) {
    void *sp8 = (void *)fn_800A535C;
    void *spC = (void *)fn_800A52DC;
    s32 result;
    s32 value;

    if (fn_800A7688(*(void **)((u8 *)arg0 + 0x1FBC), &sp8, &spC) != 0)
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

extern "C" s32 fn_800A54AC(void *arg0) {
    s32 result;
    s32 value;
    if (fn_800A76A0(*(void **)((u8 *)arg0 + 0x1FBC)) != 0)
        return -1;
    result = fn_800A7610(*(void **)((u8 *)arg0 + 0x1FBC));
    if (result == 0)
        goto done;
    if (result != 21)
        goto fail;
    value = ((s32 (* volatile)(void *))fn_800A71D8)(*(void **)((u8 *)arg0 + 0x1FBC));
    *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x1F84) = value;
    result = 0x1000;
    goto done;
fail:
    result = -1;
done:
    return result;
}

extern "C" s32 fn_800A5788(void *arg0, s32 arg1) {
    s32 result = fn_800A7568(*(void **)((u8 *)arg0 + 0x1FBC), (arg1 == 1));
    if (result != 0) {
        if (result != 21)
            return -1;
        s32 value = fn_800A71D8(*(void **)((u8 *)arg0 + 0x1FBC));
        *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
        *(s32 *)((u8 *)arg0 + 0x1F84) = value;
        return 0x1000;
    }
    return 0;
}

extern "C" s32 fn_800A5800(void *arg0) {
    s32 result = fn_800A7338(*(void **)((u8 *)arg0 + 0x1FBC));
    if (result != 0) {
        if (result != 21)
            return -1;
        s32 value = fn_800A71D8(*(void **)((u8 *)arg0 + 0x1FBC));
        *(s32 *)((u8 *)lbl_803D2140 + 0x44) = value;
        *(s32 *)((u8 *)arg0 + 0x1F84) = value;
        return 0x1000;
    }
    return 0;
}

extern "C" s32 fn_800A7090(void);
extern "C" s32 fn_800A71A0(void);
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

extern "C" s32 fn_800A7484(void *, u16, s32);
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
            void **r31 = (void **)&lbl_804077C0;
            OSLockMutex(r31);
            fn_800D2E3C(*(s16 *)((u8 *)r30 + 0x1C) - 6, *(s16 *)((u8 *)r30 + 0x1E) - 3,
                        (s32)(*(u16 *)((u8 *)r30 + 4)) * 6 + 12,
                        (s32)(*(u16 *)((u8 *)r30 + 0x20)) * 0xA + 4);
            fn_800D24D4(r30, 0);
            fn_800D2FC8();
            OSUnlockMutex(r31);
        }
    }
}
extern "C" void fn_800D2480(void) {
    if (lbl_8055DDBC == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA40, 0x1F1, lbl_8031EA4C);
    }
    ((u8 *)lbl_8055DDBC)[0x22] = 0;
}

extern "C" void fn_800D16C4(OSAlarm*, void*);
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
extern "C" void fn_800D1C48(void);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *file, s32 line, const char *msg, ...) {
    u32 sp_8[2];
    u32 sp_C;
    u32 sp_10;
    u32 sp_14;
    u32 sp_18;
    u32 sp_1C;
    u32 sp_20;
    u32 sp_24;
    u32 sp_68;
    u32 sp_6C;
    u32 sp_70;
    u32 sp_88[16];
    
    sp_8[0] = (u32)msg;
    sp_8[1] = (u32)file;
    sp_C = (u32)line;
    sp_10 = 0;
    sp_14 = 0;
    sp_18 = 0;
    sp_1C = 0;
    sp_20 = 0;
    sp_24 = 0;
    sp_68 = 0x3000000;
    sp_6C = (u32)&sp_88[0];
    sp_70 = (u32)&sp_8[0];
    
    fn_800D2098(&sp_68);
}
extern s32 lbl_8055DDD4;
extern "C" f32 lbl_80560E40;
extern "C" f32 lbl_80560E3C;
extern "C" s32 fn_80060C7C(void*);
extern "C" s32 lbl_8055DD30;
extern "C" s32 fn_800B8004(s32);
extern "C" s32 fn_800B8048(s32);
extern "C" s32 fn_800B960C(s32, s32, s32, s32, s32 *, s32);
