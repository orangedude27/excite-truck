// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <string.h>

extern void *lbl_8055DDF0;
extern void *MEMAllocFromAllocator(void *, u32);
extern void MEMFreeToAllocator(void *, void *);
extern "C" u16 fn_8002AEE8(const u16 *);

extern "C" void lbl_80320548(void);
extern const char lbl_80320570[];
extern const char lbl_80320688[];
extern const char lbl_803206B8[];
extern const char lbl_80320B5C[];
extern const char lbl_80320B8C[];
extern const char lbl_80320BC8[];
extern const char lbl_80320B98[];
extern "C" s32 fn_80128668(void);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...);
extern const char lbl_80320560[];

extern "C" s32 fn_800DCE10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800DCE50(void **arg0) {
    *arg0 = (void *)&lbl_80320548;
}

extern "C" s32 fn_800DCE60(void) {
    return 0;
}

extern "C" void fn_800DCE68(void *arg0, const void *arg1) {
    s16 val;
    u8 b0, b1, b2, b3;
    
    val = ((const s16 *)arg1)[0];
    b0 = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    
    val = ((const s16 *)arg1)[1];
    b1 = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    
    val = ((const s16 *)arg1)[2];
    b2 = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    
    val = ((const s16 *)arg1)[3];
    b3 = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    
    u32 result = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
    *(u32 *)arg0 = result;
}

extern "C" void *fn_8002F53C(void *, void *, void *, s32, s32);
extern "C" void fn_800D7F6C(s32 *);
extern "C" void *__ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(void *, const void *);
extern "C" void *__ct__Q36nw4hbm3lyt8MaterialFPCQ46nw4hbm3lyt3res8MaterialRCQ36nw4hbm3lyt11ResBlockSet(void *, const void *, const void *);
extern "C" void *fn_80107FE4(void *);
extern "C" s32 SetResource__Q36nw4hbm2ut7ResFontFPv(void *, void *);
#pragma push
#pragma small_data off
extern "C" void *__ct__Q36nw4hbm3lyt7TextBoxFPCQ46nw4hbm3lyt3res7TextBoxRCQ36nw4hbm3lyt11ResBlockSet(void *this_, const void *res, const void *blockSet) {
    extern char lbl_803208D4[];
    extern const char lbl_80320560[];
    extern void *lbl_8055DDF0;
    extern f32 lbl_80560ED0;
    extern void fn_800D2DD4(void);
    struct TextBoxVTable {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual void m21(); virtual void m22();
        virtual void reserve(u16);
        virtual void m24(); virtual void m25();
        virtual void setText(const void *, s32, u16);
    };
    struct ResAccessor {
        virtual void m0();
        virtual void *findByName(u32, void *, s32);
        virtual void *find(void *);
    };

    u8 *self = (u8 *)this_;
    const u8 *textBoxRes = (const u8 *)res;
    const u8 *blockSetBytes = (const u8 *)blockSet;
    const char *msg = lbl_80320560;
    volatile f32 sp8;
    volatile f32 spc;
    u16 count;
    s8 quotient;
    u8 rem;
    s32 value;
    void *resource;
    const u8 *entry;
    void *font;
    void *material;

    __ct__Q36nw4hbm3lyt4PaneFPCQ46nw4hbm3lyt3res4Pane(this_, res);
    *(void **)self = (void *)lbl_803208D4;
    fn_8002F53C(self + 0xD8, (void *)fn_800D7F6C, (void *)fn_800D2DD4, 4, 2);

    count = ((u32)*(const u16 *)(textBoxRes + 0x4C) >> 1) & 0xFFFF;
    {
        f32 zero = lbl_80560ED0;
        *(f32 *)(self + 0xE4) = zero;
        *(f32 *)(self + 0xE8) = zero;
    }
    if (count != 0) {
        count = (u16)(count - 1);
        quotient = self[0xFC] / 3;
        *(u32 *)(self + 0xD4) = 0;
        *(u16 *)(self + 0xF8) = 0;
        *(u16 *)(self + 0xFA) = 0;
        *(u32 *)(self + 0xE0) = 0;
        value = quotient * 3 + 1;
        rem = value % 3;
        {
            f32 zero = lbl_80560ED0;
            sp8 = zero;
            spc = zero;
            *(f32 *)(self + 0xE4) = zero;
            *(f32 *)(self + 0xE8) = zero;
            *(f32 *)(self + 0xEC) = zero;
            *(f32 *)(self + 0xF0) = zero;
        }
        *(u32 *)(self + 0xF4) = 0;
        self[0xFC] = (u8)(rem + 3);
        memset(self + 0xFD, 0, 1);
    }
    if (count != 0) {
        ((TextBoxVTable *)this_)->reserve(count);
    }

    if (*(u16 *)(textBoxRes + 0x4E) >= 2 && *(u32 *)(self + 0xD4) != 0) {
        u16 textLength = *(u16 *)(textBoxRes + 0x4E) >> 1;
        u32 index = (u32)(textLength - 1);
        const u8 *string = textBoxRes + *(const u32 *)(textBoxRes + 0x58);
        ((TextBoxVTable *)this_)->setText(string, 0, (u16)index);
    }

    *(u32 *)(self + 0xD8) = *(const u32 *)(textBoxRes + 0x5C);
    *(u32 *)(self + 0xDC) = *(const u32 *)(textBoxRes + 0x60);
    *(f32 *)(self + 0xE4) = *(const f32 *)(textBoxRes + 0x64);
    *(f32 *)(self + 0xE8) = *(const f32 *)(textBoxRes + 0x68);
    self[0xFC] = textBoxRes[0x54];
    *(f32 *)(self + 0xF0) = *(const f32 *)(textBoxRes + 0x6C);
    *(f32 *)(self + 0xEC) = *(const f32 *)(textBoxRes + 0x70);
    if (*(void **)(blockSetBytes + 4) == 0) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x18B, msg + 0x50);
    }
    if (*(u16 *)(textBoxRes + 0x52) >= *(u16 *)(*(u32 *)(blockSetBytes + 4) + 8)) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x18C, msg + 0x88);
    }

    {
        const u8 *table = *(const u8 **)(blockSetBytes + 4) + 0xC;
        u32 entryOffset = *(const u32 *)(table + *(const u16 *)(textBoxRes + 0x52) * 8);
        entry = table + entryOffset;
        resource = ((ResAccessor *)*(void **)(blockSetBytes + 0xC))->find((void *)entry);
    }
    if (resource != 0) {
        *(void **)(self + 0xE0) = resource;
    } else {
        resource = ((ResAccessor *)*(void **)(blockSetBytes + 0xC))->findByName(0x666F6E74, (void *)entry, 0);
        if (resource != 0) {
            font = MEMAllocFromAllocator(lbl_8055DDF0, 0x18);
            if (font != 0) {
                font = fn_80107FE4(font);
                if (SetResource__Q36nw4hbm2ut7ResFontFPv(font, resource) == 0) {
                    ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x19A, msg + 0xD4);
                }
                *(void **)(self + 0xE0) = font;
                self[0xFD] |= 0x80;
            }
        }
    }

    material = MEMAllocFromAllocator(lbl_8055DDF0, 0x5C);
    if (material != 0) {
        if (*(u32 *)(blockSetBytes + 8) == 0) {
            ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x1A4, msg + 0xEC);
        }
        {
            const u8 *table = *(const u8 **)(blockSetBytes + 8);
            u16 index = *(const u16 *)(textBoxRes + 0x50);
            const u8 *materialRes = table + *(const u32 *)(table + index * 4 + 0xC);
            if (material != 0) {
                material = __ct__Q36nw4hbm3lyt8MaterialFPCQ46nw4hbm3lyt3res8MaterialRCQ36nw4hbm3lyt11ResBlockSet(material, materialRes, blockSet);
            }
        }
        *(void **)(self + 0x28) = material;
    }
    return this_;
}
#pragma pop
extern const char lbl_80320580[];
extern void *__dt__Q36nw4hbm3lyt4PaneFv(void *, s32);
extern void fn_8002F634(void *, void *, s32, s32);
extern f32 lbl_80560ED0;
extern char lbl_803208D4[];
extern void fn_800D2DD4(void);
extern void *__dt__Q36nw4hbm3lyt7TextBoxFv(void *arg0, s32 arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_803208D4;
        if (*(u8 *)((char *)arg0 + 0xFD) & 0x80) {
            void *p = *(void **)((char *)arg0 + 0xE0);
            if (!p) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320570, 0x307, lbl_80320580);
            ((void (*)(void *, s32))(*(void ***)p)[1])(p, -1);
            MEMFreeToAllocator(lbl_8055DDF0, p);
            *(u8 *)((char *)arg0 + 0xFD) &= 0x7F;
        }
        *(void **)((char *)arg0 + 0xE0) = 0;
        *(f32 *)((char *)arg0 + 0xE4) = lbl_80560ED0;
        *(f32 *)((char *)arg0 + 0xE8) = lbl_80560ED0;
        void *p = *(void **)((char *)arg0 + 0x28);
        if (p && *(u8 *)((char *)p + 0x54) == 0) {
            ((void (*)(void *, s32))(*(void ***)p)[1])(p, -1);
            MEMFreeToAllocator(lbl_8055DDF0, p);
            *(void **)((char *)arg0 + 0x28) = 0;
        }
        ((void (*)(void *))(*(void ***)arg0)[13])(arg0);
        fn_8002F634((char *)arg0 + 0xD8, fn_800D2DD4, 4, 2);
        __dt__Q36nw4hbm3lyt4PaneFv(arg0, 0);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, void *arg1, u32 index);
extern "C" void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, const void *src, u32 index);
extern "C" void SetTextColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color);
extern "C" void SetVtxColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color);

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *) __attribute__((noreturn));
void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, void *arg1, u32 index) {
    if (index >= 4) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320570, 0x1d3, lbl_80320688);
    }
    GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(this_ptr, arg1, index >> 1);
}

void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, const void *src, u32 index) {
    if (index >= 2) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320B8C, 0x5f, lbl_80320B5C);
    }
    const u8 *base = (const u8 *)src + (index * 4);
    ((u8 *)this_ptr)[0] = base[0xD8];
    ((u8 *)this_ptr)[1] = base[0xD9];
    ((u8 *)this_ptr)[2] = base[0xDA];
    ((u8 *)this_ptr)[3] = base[0xDB];
}

void SetVtxColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color) {
    if (index >= 4) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320570, 0x1de, lbl_80320688);
    }
    u8 colorBytes[4];
    const u8 *c = (const u8 *)color;
    colorBytes[0] = c[0];
    colorBytes[1] = c[1];
    colorBytes[2] = c[2];
    colorBytes[3] = c[3];
    SetTextColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(this_ptr, index >> 1, colorBytes);
}

void SetTextColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color) {
    if (index >= 2) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320BC8, 0x60, lbl_80320B98);
    }
    const u8 *c = (const u8 *)color;
    u8 *base = (u8 *)this_ptr + (index * 4);
    base[0xD8] = c[0];
    base[0xD9] = c[1];
    base[0xDA] = c[2];
    base[0xDB] = c[3];
}

extern "C" u8 GetVtxColorElement__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, u32 index) {
    if (index >= 0x10) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320570, 0x1e6, lbl_803206B8);
    }
    u32 part1 = (index >> 1) & 0x7FFFFFFC;
    u32 part2 = index & 3;
    u8 *base = (u8 *)this_ptr + part1;
    return base[part2 + 0xD8];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7TextBoxFUlUc(void *this_ptr, u32 index, u8 color) {
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    extern const char lbl_80320570[];
    extern const char lbl_803206B8[];
    if (index >= 0x10) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320570, 0x1ee, lbl_803206B8);
    }
    u32 part1 = (index >> 1) & 0x7FFFFFFC;
    u32 part2 = index & 3;
    u8 *base = (u8 *)this_ptr + part1;
    base[part2 + 0xD8] = color;
}

extern "C" void AllocStringBuffer__Q36nw4hbm3lyt7TextBoxFUs(void *this_ptr, u16 len) {
    if (len != 0) {
        u16 bytes = (len + 1) * 2;
        u16 current = *(u16 *)((u8 *)this_ptr + 0xF8);
        if (bytes > current) {
            void *volatile *vptr = *(void *volatile **)this_ptr;
            void *volatile *slot = vptr + 0x1A;
            void (*volatile fn)(void *) = (void (*)(void *))*slot;
            fn(this_ptr);
            void *result = MEMAllocFromAllocator(lbl_8055DDF0, bytes);
            *(void **)((u8 *)this_ptr + 0xD4) = result;
            if (result != NULL) *(u16 *)((u8 *)this_ptr + 0xF8) = bytes;
        }
    }
}

extern "C" void fn_800DEFD8(void *this_ptr) {
    void *buffer = *(void **)((u8 *)this_ptr + 0xD4);
    if (buffer != NULL) {
        MEMFreeToAllocator(lbl_8055DDF0, buffer);
        *(void **)((u8 *)this_ptr + 0xD4) = NULL;
        *(u16 *)((u8 *)this_ptr + 0xF8) = 0;
    }
}

extern "C" void SetString__Q36nw4hbm3lyt7TextBoxFPCwUs(void *this_ptr, const u16 *str, u16 len) {
    const u16 *str_local = str;
    u16 len_local = len;
    void *this_local = this_ptr;
    u32 wlen = fn_8002AEE8(str_local);
    void **vtable = *(void ***)this_local;
    void (*fn)(void*, const u16*, u32) = (void (*)(void*, const u16*, u32))vtable[0x70 / 4];
    fn(this_local, str_local, (u32)(u16)wlen);
}

extern "C" u16 SetString__Q36nw4hbm3lyt7TextBoxFPCwUsUs(void *this_ptr, const u16 *str, u16 offset, u16 len) {
    const char *msg = lbl_80320560;
    u16 *buffer;
    u16 capacity;
    u32 limit;
    u16 count;
    u32 end;
    if (*(u16 **)((u8 *)this_ptr + 0xD4) == 0) {
        ((void (*)(const char *, s32, const char *, ...))Warning__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x2C4, msg + 0x328);
        return 0;
    }
    capacity = *(u16 *)((u8 *)this_ptr + 0xF8);
    if (capacity == 0) {
        limit = 0;
    } else {
        if (capacity < 2) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x25D, msg + 0x2EC);
        limit = (capacity >> 1) - 1;
    }
    if (offset >= limit) {
        ((void (*)(const char *, s32, const char *, ...))Warning__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x2CC, msg + 0x33C);
        return 0;
    }
    limit -= offset;
    count = len;
    if (len > limit) count = limit;
    if (count < len) ((void (*)(const char *, s32, const char *, ...))Warning__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0x2D1, msg + 0x358, len - count);
    buffer = *(u16 **)((u8 *)this_ptr + 0xD4);
    memcpy(buffer + offset, str, count * 2);
    end = offset + count;
    *(u16 *)((u8 *)this_ptr + 0xFA) = end;
    buffer[end] = 0;
    return count;
}

extern "C" s32 fn_800DF1C8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void SetCursor__Q36nw4hbm2ut10CharWriterFff(void *, f32, f32);
extern "C" s32 fn_800DDDF4(f32 *, void *, const u16 *, s32, u8 *, f32);
extern "C" const u16 lbl_80559800[];
extern "C" void fn_800DF81C(f32 *arg0, void *arg1, const u16 *arg2, s32 arg3, f32 arg4) {
    f32 out[4];
    u8 sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f31;
    f32 var_f1, var_f1_2, var_f1_3, var_f1_4;
    s32 temp_r31, var_r30 = arg3;
    u32 var_r29 = (u32)arg2;
    const char *msg = lbl_80320560;

    {
        u32 temp_r11 = (u32)arg1 & 0xFF000000;
        s32 a0 = 1, a1 = 1, a2 = 1, a3 = 1, a4 = 1, a5 = 1;
        if (((u32)(temp_r11 + 0x80000000) > 0U) && ((u32)(((u32)arg1 & 0xFF800000) + 0x7F000000) > 0U)) a5 = 0;
        if ((a5 == 0) && ((u32)(((u32)arg1 & 0xF8000000) + 0x70000000) > 0U)) a4 = 0;
        if ((a4 == 0) && ((u32)(temp_r11 + 0x40000000) > 0U)) a3 = 0;
        if ((a3 == 0) && ((u32)(((u32)arg1 & 0xFF800000) + 0x3F000000) > 0U)) a2 = 0;
        if ((a2 == 0) && ((u32)(((u32)arg1 & 0xF8000000) + 0x30000000) > 0U)) a1 = 0;
        if ((a1 == 0) && ((u32)(((u32)arg1 & 0xFFFFC000) + 0x20000000) > 0U)) a0 = 0;
        if (a0 == 0) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDA, msg + 0x194, arg1);
    }
{
        u32 temp_r10 = (u32)arg0 & 0xFF000000;
        s32 b0 = 1, b1 = 1, b2 = 1, b3 = 1, b4 = 1, b5 = 1;
        if (((u32)(temp_r10 + 0x80000000) > 0U) && ((u32)(((u32)arg0 & 0xFF800000) + 0x7F000000) > 0U)) b5 = 0;
        if ((b5 == 0) && ((u32)(((u32)arg0 & 0xF8000000) + 0x70000000) > 0U)) b4 = 0;
        if ((b4 == 0) && ((u32)(temp_r10 + 0x40000000) > 0U)) b3 = 0;
        if ((b3 == 0) && ((u32)(((u32)arg0 & 0xFF800000) + 0x3F000000) > 0U)) b2 = 0;
        if ((b2 == 0) && ((u32)(((u32)arg0 & 0xF8000000) + 0x30000000) > 0U)) b1 = 0;
        if ((b1 == 0) && ((u32)(((u32)arg0 & 0xFFFFC000) + 0x20000000) > 0U)) b0 = 0;
        if (b0 == 0) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDB, msg + 0x240, arg0);
    }
{
        u32 temp_r10_2 = (u32)arg2 & 0xFF000000;
        s32 c0 = 1, c1 = 1, c2 = 1, c3 = 1, c4 = 1, c5 = 1;
        if (((u32)(temp_r10_2 + 0x80000000) > 0U) && ((u32)(((u32)arg2 & 0xFF800000) + 0x7F000000) > 0U)) c5 = 0;
        if ((c5 == 0) && ((u32)(((u32)arg2 & 0xF8000000) + 0x70000000) > 0U)) c4 = 0;
        if ((c4 == 0) && ((u32)(temp_r10_2 + 0x40000000) > 0U)) c3 = 0;
        if ((c3 == 0) && ((u32)(((u32)arg2 & 0xFF800000) + 0x3F000000) > 0U)) c2 = 0;
        if ((c2 == 0) && ((u32)(((u32)arg2 & 0xF8000000) + 0x30000000) > 0U)) c1 = 0;
        if ((c1 == 0) && ((u32)(((u32)arg2 & 0xFFFFC000) + 0x20000000) > 0U)) c0 = 0;
        if (c0 == 0) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDC, msg + 0x1D0, arg2);
    }

    if (var_r30 < 0) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDD, msg + 0x208, var_r30, 0);
    }
    arg0[0] = lbl_80560ED0;
    arg0[2] = lbl_80560ED0;
    arg0[1] = lbl_80560ED0;
    arg0[3] = lbl_80560ED0;
    SetCursor__Q36nw4hbm2ut10CharWriterFff(arg1, lbl_80560ED0, lbl_80560ED0);
    temp_f31 = lbl_80560ED0;
    do {
        out[0] = temp_f31;
        out[1] = temp_f31;
        out[2] = temp_f31;
        out[3] = temp_f31;
        temp_r31 = fn_800DDDF4(&out[0], arg1, (const u16 *)var_r29, var_r30, &sp8, arg4);
        if (sp8 != 0) {
            fn_800DDDF4(&out[0], arg1, (const u16 *)&lbl_80559800, 1, &sp8, arg4);
        }
        var_f1 = out[0];
        temp_f0 = arg0[0];
        var_r29 += temp_r31 * 2;
        var_r30 -= temp_r31;
        var_f1 = temp_f0 > var_f1 ? var_f1 : temp_f0;
        arg0[0] = var_f1;
        temp_f0_2 = arg0[1];
        var_f1_2 = out[1];
        var_f1_2 = temp_f0_2 > var_f1_2 ? var_f1_2 : temp_f0_2;
        arg0[1] = var_f1_2;
        temp_f0_3 = arg0[2];
        var_f1_3 = out[2];
        var_f1_3 = temp_f0_3 < var_f1_3 ? var_f1_3 : temp_f0_3;
        arg0[2] = var_f1_3;
        temp_f0_4 = arg0[3];
        var_f1_4 = out[3];
        var_f1_4 = temp_f0_4 < var_f1_4 ? var_f1_4 : temp_f0_4;
        arg0[3] = var_f1_4;
    } while (var_r30 > 0);
}

extern "C" unsigned int* fn_800DFC54(void) {
    extern unsigned int lbl_8055DE08;
    return &lbl_8055DE08;
}

