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
    /* Fix note: clamp four signed channels, stage their bytes, and copy the packed word. */
    const s16 *src = (const s16 *)arg1;
    volatile u8 bytes[4];
    s16 val;

    val = src[0];
    bytes[0] = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    val = src[1];
    bytes[1] = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    val = src[2];
    bytes[2] = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    val = src[3];
    bytes[3] = (u8)((val < 0) ? 0 : (val > 255) ? 255 : val);
    *(u32 *)arg0 = *(const volatile u32 *)bytes;
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

extern "C" s32 fn_800DDDF4(f32 *arg0_ptr, void *arg1_ptr, const u16 *arg2_ptr, s32 arg3, u8 *arg4, f32 farg0) {

extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,u32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern void **GetFont__Q36nw4hbm2ut10CharWriterCFv_80112410(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80111FD0(s32);
extern s32 IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern f32 fn_80111C10(s32);
extern f32 lbl_80560ED0;
extern const char lbl_80320560[],lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80320AC4[],lbl_80320AFC[],lbl_80320B10[],lbl_80320B48[];
class Reader { public: s32 cursor; u16 (Reader::*next)(); };
Reader reader;
struct Context { s32 writer,str; u32 x,y; s32 flags; } context;
class Font { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual s32 ascent(); virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual s32 width(u16); };
class Processor { public: virtual void d0(); virtual void d1(); virtual s32 rectCall(f32*,u16,Context*); };
const char *base = lbl_80320560;
struct Rect { f32 left,top,right,bottom; } saved;
f32 rect[4];

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f27;
    f32 temp_f28;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f2;
    f32 var_f31;
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r14;
    s32 temp_r20;
    s32 temp_r22;
    s32 temp_r23;
    s32 temp_r24;
    s32 temp_r25;
    s32 temp_r30;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5;
    s32 temp_r7;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r21;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r4_5;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u16 var_r26;
    u32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_7;

    temp_r11 = ((s32)arg1_ptr) & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32) (temp_r11) != 0x80000000U) && ((u32) ((((s32)arg1_ptr) & 0xFF800000)) != 0x81000000U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((u32) ((((s32)arg1_ptr) & 0xF8000000)) != 0x90000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32) (temp_r11) != 0xC0000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32) ((((s32)arg1_ptr) & 0xFF800000)) != 0xC1000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32) ((((s32)arg1_ptr) & 0xF8000000)) != 0xD0000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32) ((((s32)arg1_ptr) & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0x10, 0x47, base + 0x194, ((s32)arg1_ptr));
    }
    temp_r10 = ((s32)arg0_ptr) & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32) (temp_r10) != 0x80000000U) && ((u32) ((((s32)arg0_ptr) & 0xFF800000)) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32) ((((s32)arg0_ptr) & 0xF8000000)) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32) (temp_r10) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32) ((((s32)arg0_ptr) & 0xFF800000)) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32) ((((s32)arg0_ptr) & 0xF8000000)) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32) ((((s32)arg0_ptr) & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0x10, 0x48, base + 0x240, ((s32)arg0_ptr));
    }
    temp_r14 = ((s32)arg2_ptr) & 0xFF000000;
    var_r4_2 = 1;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32) (temp_r14) != 0x80000000U) && ((u32) ((((s32)arg2_ptr) & 0xFF800000)) != 0x81000000U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) ((((s32)arg2_ptr) & 0xF8000000)) != 0x90000000U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32) (temp_r14) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) ((((s32)arg2_ptr) & 0xFF800000)) != 0xC1000000U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) ((((s32)arg2_ptr) & 0xF8000000)) != 0xD0000000U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) ((((s32)arg2_ptr) & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0x10, 0x49, base + 0x1D0, ((s32)arg2_ptr));
    }
    if (arg3 < 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0x10, 0x4A, base + 0x208, arg3, 0);
    }
    context.writer = ((s32)arg1_ptr);
    context.x = 0;
    context.y = 0;
    context.flags = 0;
    context.str = ((s32)arg2_ptr);
    temp_r3_3 = GetFont__Q36nw4hbm2ut10CharWriterCFv(((s32)arg1_ptr));
    temp_r11_2 = temp_r3_3 & 0xFF000000;
    var_f31 = lbl_80560ED0;
    var_r21 = 0;
    var_r5_4 = 1;
    var_r6_4 = 1;
    var_r7_4 = 1;
    var_r8_4 = 1;
    var_r9_4 = 1;
    var_r10_2 = 1;
    if (((u32) (temp_r11_2) != 0x80000000U) && ((u32) ((temp_r3_3 & 0xFF800000)) != 0x81000000U)) {
        var_r10_2 = 0;
    }
    if ((var_r10_2 == 0) && ((u32) ((temp_r3_3 & 0xF8000000)) != 0x90000000U)) {
        var_r9_4 = 0;
    }
    if ((var_r9_4 == 0) && ((u32) (temp_r11_2) != 0xC0000000U)) {
        var_r8_4 = 0;
    }
    if ((var_r8_4 == 0) && ((u32) ((temp_r3_3 & 0xFF800000)) != 0xC1000000U)) {
        var_r7_4 = 0;
    }
    if ((var_r7_4 == 0) && ((u32) ((temp_r3_3 & 0xF8000000)) != 0xD0000000U)) {
        var_r6_4 = 0;
    }
    if ((var_r6_4 == 0) && ((u32) ((temp_r3_3 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5_4 = 0;
    }
    if (var_r5_4 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0x10, 0x53, base + 0x278, temp_r3_3);
    }
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, (u32)temp_r3_3);
    var_r4_3 = 1;
    temp_r25 = (s32) &reader.cursor & 0xFF000000;
    var_r5_5 = 1;
    var_r6_5 = 1;
    var_r7_5 = 1;
    var_r8_5 = 1;
    var_r9_5 = 1;
    if (((u32) (temp_r25) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0x81000000U)) {
        var_r9_5 = 0;
    }
    if ((var_r9_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0x90000000U)) {
        var_r8_5 = 0;
    }
    if ((var_r8_5 == 0) && ((u32) (temp_r25) != 0xC0000000U)) {
        var_r7_5 = 0;
    }
    if ((var_r7_5 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0xC1000000U)) {
        var_r6_5 = 0;
    }
    if ((var_r6_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0xD0000000U)) {
        var_r5_5 = 0;
    }
    if ((var_r5_5 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_3 = 0;
    }
    if (var_r4_3 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    temp_r20 = reader.cursor;
    *(f32*)(((s32)arg0_ptr) + 0) = (f32) lbl_80560ED0;
    *(f32*)(((s32)arg0_ptr) + 8) = (f32) lbl_80560ED0;
    var_f1 = fn_80111C10(((s32)arg1_ptr));
    var_f1 = (lbl_80560ED0 > var_f1) ? var_f1 : lbl_80560ED0;
    *(f32*)(((s32)arg0_ptr) + 4) = var_f1;
    var_f1_2 = fn_80111C10(((s32)arg1_ptr));
    var_f1_2 = (lbl_80560ED0 < var_f1_2) ? var_f1_2 : lbl_80560ED0;
    *(f32*)(((s32)arg0_ptr) + 0xC) = var_f1_2;
    var_r6_6 = 0;
    *arg4 = 0;
    if (((u32) (temp_r25) == 0x80000000U) || (temp_r4 = (s32) &reader.cursor & 0xFF800000, (((u32) (temp_r4) == 0x81000000U) != 0)) || (temp_r3_4 = (s32) &reader.cursor & 0xF8000000, (((u32) (temp_r3_4) == 0x90000000U) != 0)) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r4) == 0xC1000000U) || ((u32) (temp_r3_4) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000)) == 0xE0000000U)) {
        var_r6_6 = 1;
    }
    if (var_r6_6 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
    }
    if (((s32)arg2_ptr) & 1) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320A64, 0x3C, lbl_80320A18, ((s32)arg2_ptr));
    }
    var_r5_6 = 0;
    if (((u32) (temp_r14) == 0x80000000U) || (temp_r4_2 = ((s32)arg2_ptr) & 0xFF800000, (((u32) (temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_5 = ((s32)arg2_ptr) & 0xF8000000, (((u32) (temp_r3_5) == 0x90000000U) != 0)) || ((u32) (temp_r14) == 0xC0000000U) || ((u32) (temp_r4_2) == 0xC1000000U) || ((u32) (temp_r3_5) == 0xD0000000U) || ((u32) ((((s32)arg2_ptr) & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_6 = 1;
    }
    if (var_r5_6 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320A04, 0x3D, lbl_803209CC, ((s32)arg2_ptr));
    }
    if (fn_8002F72C(&reader.next, base) != 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_803209B8, 0x3E, lbl_80320980);
    }
    reader.cursor = ((s32)arg2_ptr);
    var_r6_7 = 0;
    saved.left = *(f32*)(((s32)arg0_ptr) + 0);
    saved.top = *(f32*)(((s32)arg0_ptr) + 4);
    saved.right = *(f32*)(((s32)arg0_ptr) + 8);
    saved.bottom = *(f32*)(((s32)arg0_ptr) + 0xC);
    if (((u32) (temp_r25) == 0x80000000U) || (temp_r4_3 = (s32) &reader.cursor & 0xFF800000, (((u32) (temp_r4_3) == 0x81000000U) != 0)) || (temp_r3_6 = (s32) &reader.cursor & 0xF8000000, (((u32) (temp_r3_6) == 0x90000000U) != 0)) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r4_3) == 0xC1000000U) || ((u32) (temp_r3_6) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000)) == 0xE0000000U)) {
        var_r6_7 = 1;
    }
    if (var_r6_7 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f27 = lbl_80560ED0;
    var_r26 = fn_8002F768(&reader.cursor);
    temp_r24 = (s32) &reader.cursor & 0xFF800000;
    temp_r23 = (s32) &reader.cursor & 0xF8000000;
    temp_r22 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r31 = temp_r25;
loop_262:
    var_r3 = 0;
    if ((temp_r31 == 0x80000000U) || ((u32) (temp_r24) == 0x81000000U) || ((u32) (temp_r23) == 0x90000000U) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r24) == 0xC1000000U) || ((u32) (temp_r23) == 0xD0000000U) || ((u32) (temp_r22) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    temp_r3_7 = reader.cursor - ((s32)arg2_ptr);
    if ((s32)temp_r3_7 / 2 > arg3) {
        goto block_273;
    }
    if ((s32) var_r26 < 0x20) {
        rect[0] = var_f31;
        var_r3_2 = 0;
        rect[1] = temp_f27;
        rect[2] = temp_f27;
        rect[3] = temp_f27;
        if (((u32) (temp_r25) == 0x80000000U) || ((u32) (temp_r24) == 0x81000000U) || ((u32) (temp_r23) == 0x90000000U) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r24) == 0xC1000000U) || ((u32) (temp_r23) == 0xD0000000U) || ((u32) (temp_r22) == 0xE0000000U)) {
            var_r3_2 = 1;
        }
        if (var_r3_2 == 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
        }
        context.str = reader.cursor;
        context.flags = var_r21 == 0;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(((s32)arg1_ptr), var_f31);
        temp_r30 = ((Processor*)GetFont__Q36nw4hbm2ut10CharWriterCFv_80112410(((s32)arg1_ptr)))->rectCall(rect, var_r26, &context);
        var_r0 = 1;
        var_r3_3 = 1;
        temp_r7 = context.str & 0xFF000000;
        var_r4_4 = 1;
        var_r5_7 = 1;
        var_r9_6 = 1;
        var_r10_3 = 1;
        if (((u32) (temp_r7) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r10_3 = 0;
        }
        if ((var_r10_3 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32) (temp_r7) != 0xC0000000U)) {
            var_r5_7 = 0;
        }
        if ((var_r5_7 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_4 = 0;
        }
        if ((var_r4_4 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_3 = 0;
        }
        if ((var_r3_3 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(base + 0x10, 0x7B, base + 0x2B0);
        }
        var_r3_4 = 0;
        if (((u32) (temp_r25) == 0x80000000U) || ((u32) (temp_r24) == 0x81000000U) || ((u32) (temp_r23) == 0x90000000U) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r24) == 0xC1000000U) || ((u32) (temp_r23) == 0xD0000000U) || ((u32) (temp_r22) == 0xE0000000U)) {
            var_r3_4 = 1;
        }
        if (var_r3_4 == 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
        }
        if (context.str & 1) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320A64, 0x3C, lbl_80320A18, context.str);
        }
        temp_r5 = context.str & 0xFF000000;
        var_r0_2 = 1;
        var_r3_5 = 1;
        var_r7_6 = 1;
        var_r4_5 = 1;
        var_r8_6 = 1;
        var_r9_7 = 1;
        if (((u32) (temp_r5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32) (temp_r5) != 0xC0000000U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_5 = 0;
        }
        if ((var_r4_5 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_5 = 0;
        }
        if ((var_r3_5 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320A04, 0x3D, lbl_803209CC, context.str);
        }
        if (fn_8002F72C(&reader.next, lbl_80320560) != 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_803209B8, 0x3E, lbl_80320980);
        }
        reader.cursor = context.str;
        var_f1_3 = rect[0];
        temp_f0 = *(f32*)(((s32)arg0_ptr) + 0);
        var_f1_3 = (temp_f0 > var_f1_3) ? var_f1_3 : temp_f0;
        *(f32*)(((s32)arg0_ptr) + 0) = var_f1_3;
        temp_f0_2 = *(f32*)(((s32)arg0_ptr) + 4);
        var_f1_4 = rect[1];
        var_f1_4 = (temp_f0_2 > var_f1_4) ? var_f1_4 : temp_f0_2;
        *(f32*)(((s32)arg0_ptr) + 4) = var_f1_4;
        temp_f0_3 = *(f32*)(((s32)arg0_ptr) + 8);
        var_f1_5 = rect[2];
        var_f1_5 = (temp_f0_3 < var_f1_5) ? var_f1_5 : temp_f0_3;
        *(f32*)(((s32)arg0_ptr) + 8) = var_f1_5;
        temp_f0_4 = *(f32*)(((s32)arg0_ptr) + 0xC);
        var_f1_6 = rect[3];
        var_f1_6 = (temp_f0_4 < var_f1_6) ? var_f1_6 : temp_f0_4;
        *(f32*)(((s32)arg0_ptr) + 0xC) = var_f1_6;
        var_f31 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(((s32)arg1_ptr));
        if ((*(f32*)(((s32)arg0_ptr) + 8) - *(f32*)(((s32)arg0_ptr) + 0)) > farg0) {
            *arg4 = 1;
            goto block_273;
        }
        switch (temp_r30) {
        case 3: goto block_273;                         /* irregular */
        case 4:
            return arg3;
        case 1:
            var_r21 = 0;
            goto block_241;
        case 2:
            var_r21 = 1;
            goto block_241;
        }
    } else {
        if (var_r21 != 0) {
            var_f31 += GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80111FD0(((s32)arg1_ptr));
        }
        var_r21 = 1;
        if (IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(((s32)arg1_ptr)) != 0) {
            var_f31 += GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(((s32)arg1_ptr));
        } else {
            temp_f28 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv(((s32)arg1_ptr));
            var_f31 += (f32) ((Font*)GetFont__Q36nw4hbm2ut10CharWriterCFv(((s32)arg1_ptr)))->width(var_r26) * temp_f28;
        }
        var_f0 = *(f32*)(((s32)arg0_ptr) + 0);
        if (var_f0 > var_f31) {
            var_f0 = var_f31;
        }
        var_f2 = *(f32*)(((s32)arg0_ptr) + 8);
        *(f32*)(((s32)arg0_ptr) + 0) = var_f0;
        if (var_f2 < var_f31) {
            var_f2 = var_f31;
        }
        *(f32*)(((s32)arg0_ptr) + 8) = var_f2;
        if (((f32) var_f2 - *(f32*)(((s32)arg0_ptr) + 0)) > farg0) {
            *arg4 = 1;
block_273:
            if (((s32) *arg4 != 0) && (temp_r20 != 0)) {
                temp_r3_2 = temp_r20 - ((s32)arg2_ptr);
                *(f32*)(((s32)arg0_ptr) + 0) = saved.left;
                *(f32*)(((s32)arg0_ptr) + 4) = saved.top;
                *(f32*)(((s32)arg0_ptr) + 8) = saved.right;
                *(f32*)(((s32)arg0_ptr) + 0xC) = saved.bottom;
                return (s32)temp_r3_2 / 2;
            }
            var_r3_6 = 0;
            if (((u32) (temp_r25) == 0x80000000U) || ((u32) (temp_r24) == 0x81000000U) || ((u32) (temp_r23) == 0x90000000U) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r24) == 0xC1000000U) || ((u32) (temp_r23) == 0xD0000000U) || ((u32) (temp_r22) == 0xE0000000U)) {
                var_r3_6 = 1;
            }
            if (var_r3_6 == 0) {
                ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            temp_r3 = reader.cursor - ((s32)arg2_ptr);
            return (s32)temp_r3 / 2;
        }
block_241:
        var_r3_7 = 0;
        if ((temp_r31 == 0x80000000U) || ((u32) (temp_r24) == 0x81000000U) || ((u32) (temp_r23) == 0x90000000U) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r24) == 0xC1000000U) || ((u32) (temp_r23) == 0xD0000000U) || ((u32) (temp_r22) == 0xE0000000U)) {
            var_r3_7 = 1;
        }
        if (var_r3_7 == 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
        }
        var_r3_8 = 0;
        if ((temp_r31 == 0x80000000U) || ((u32) (temp_r24) == 0x81000000U) || ((u32) (temp_r23) == 0x90000000U) || ((u32) (temp_r25) == 0xC0000000U) || ((u32) (temp_r24) == 0xC1000000U) || ((u32) (temp_r23) == 0xD0000000U) || ((u32) (temp_r22) == 0xE0000000U)) {
            var_r3_8 = 1;
        }
        if (var_r3_8 == 0) {
            ((void (*)(const char*, s32, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
        }
        var_r26 = fn_8002F768(&reader.cursor);
        saved.left = *(f32*)(((s32)arg0_ptr) + 0);
        saved.top = *(f32*)(((s32)arg0_ptr) + 4);
        saved.right = *(f32*)(((s32)arg0_ptr) + 8);
        saved.bottom = *(f32*)(((s32)arg0_ptr) + 0xC);
        goto loop_262;
    }
}

extern const char lbl_80320948[];
extern u32 lbl_80559804;
#pragma small_data on
namespace nw4hbm { namespace ut { struct CharStrmReader { s32 unk0; s32 unk4; s32 unk8; s32 unkC; CharStrmReader(s32 a = 0, s32 b = 0, s32 c = 0, s32 d = 0) : unk0(a), unk4(b), unk8(c), unkC(d) {} }; struct Font { CharStrmReader GetCharStrmReader() const; }; } }
nw4hbm::ut::CharStrmReader nw4hbm::ut::Font::GetCharStrmReader() const {
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    s32 var_r9;
    s32 var_r10;
    s32 temp_r11;
    s32 font = (s32)this;
    nw4hbm::ut::CharStrmReader result;

    temp_r11 = font & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32)(temp_r11 + 0x80000000) != 0U) &&
        ((u32)((font & 0xFF800000) + 0x7F000000) != 0U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) &&
        ((u32)((font & 0xF8000000) + 0x70000000) != 0U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) &&
        ((u32)(temp_r11 + 0x40000000) != 0U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) &&
        ((u32)((font & 0xFF800000) + 0x3F000000) != 0U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) &&
        ((u32)((font & 0xF8000000) + 0x30000000) != 0U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) &&
        ((u32)((font & 0xFFFFC000) + 0x20000000) != 0U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(
            (const char *)&lbl_80559804, 0x75, lbl_80320948, font);
    }

    result.unk4 = *(s32 *)((u8 *)font + 4);
    result.unk0 = 0;
    result.unk8 = *(s32 *)((u8 *)font + 8);
    result.unkC = *(s32 *)((u8 *)font + 0xC);
    return result;
}
extern "C" void AllocStringBuffer__Q36nw4hbm3lyt7TextBoxFUs(void *this_ptr, u16 len) {
    struct VTable { void (*slots[27])(void *); };
    struct Object { VTable *vtable; };
    if (len != 0) {
        u16 bytes = (len + 1) * 2;
        u16 current = *(u16 *)((u8 *)this_ptr + 0xF8);
        if (bytes > current) {
            ((struct Object *)this_ptr)->vtable->slots[26](this_ptr);
            void *result = MEMAllocFromAllocator(lbl_8055DDF0, bytes);
            *(void **)((u8 *)this_ptr + 0xD4) = result;
            if (result != NULL) *(u16 *)((u8 *)this_ptr + 0xF8) = bytes;
        }
    }
}
#pragma scheduling on
extern "C" void fn_800DEFD8(void *this_ptr) {
    void *buffer = *(void **)((u8 *)this_ptr + 0xD4);
    if (buffer != NULL) {
        MEMFreeToAllocator(lbl_8055DDF0, buffer);
        *(void **)((u8 *)this_ptr + 0xD4) = NULL;
        *(u16 *)((u8 *)this_ptr + 0xF8) = 0;
    }
}

#pragma scheduling invalid_target
extern "C" void SetString__Q36nw4hbm3lyt7TextBoxFPCwUs(void *this_ptr, const wchar_t *str, u16 len) {
    class TextBox {
    public:
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
        virtual void m24(); virtual void m25();
        virtual void setString(const wchar_t *, u16, u32);
    };
    u32 wlen = fn_8002AEE8((const u16 *)str);
    ((TextBox *)this_ptr)->setString(str, len, (u32)(u16)wlen);
}
#pragma scheduling on
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
extern "C" unsigned long lbl_80559800;
extern "C" void fn_800DF81C(f32 *arg0, void *arg1, const u16 *arg2, s32 arg3, f32 arg4) {
    f32 out[4];
    u8 sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f31;
    f32 var_f1, var_f1_2, var_f1_3, var_f1_4;
    s32 temp_r31, var_r30 = arg3;
    u32 var_r29 = (u32)arg2;
    const char *msg = lbl_80320560;

    {
        
        s16 a0, a1, a2, a3, a4, a5;
        a0 = 1; a1 = 1; a2 = 1; a3 = 1; a4 = 1; a5 = 1;
        if (((u32)((((u32)arg1) & 0xFF000000) + 0x80000000) != 0U) && ((u32)(((u32)arg1 & 0xFF800000) + 0x7F000000) != 0U)) a5 = 0;
        if ((!a5) && ((u32)(((u32)arg1 & 0xF8000000) + 0x70000000) != 0U)) a4 = 0;
        if ((!a4) && ((u32)((((u32)arg1) & 0xFF000000) + 0x40000000) != 0U)) a3 = 0;
        if ((!a3) && ((u32)(((u32)arg1 & 0xFF800000) + 0x3F000000) != 0U)) a2 = 0;
        if ((!a2) && ((u32)(((u32)arg1 & 0xF8000000) + 0x30000000) != 0U)) a1 = 0;
        if ((!a1) && ((u32)(((u32)arg1 & 0xFFFFC000) + 0x20000000) != 0U)) a0 = 0;
        if (!a0) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDA, msg + 0x194, arg1);
    }
{
        s16 b0, b1, b2, b3, b4, b5;
        b0 = 1; b1 = 1; b2 = 1; b3 = 1; b4 = 1; b5 = 1;
        u32 temp_r10 = (u32)arg0 & 0xFF000000;
        if (((u32)(temp_r10 + 0x80000000) != 0U) && ((u32)(((u32)arg0 & 0xFF800000) + 0x7F000000) != 0U)) b5 = 0;
        if ((!b5) && ((u32)(((u32)arg0 & 0xF8000000) + 0x70000000) != 0U)) b4 = 0;
        if ((!b4) && ((u32)(temp_r10 + 0x40000000) != 0U)) b3 = 0;
        if ((!b3) && ((u32)(((u32)arg0 & 0xFF800000) + 0x3F000000) != 0U)) b2 = 0;
        if ((!b2) && ((u32)(((u32)arg0 & 0xF8000000) + 0x30000000) != 0U)) b1 = 0;
        if ((!b1) && ((u32)(((u32)arg0 & 0xFFFFC000) + 0x20000000) != 0U)) b0 = 0;
        if (!b0) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDB, msg + 0x240, arg0);
    }
{
        s16 c0, c1, c2, c3, c4, c5;
        c0 = 1; c1 = 1; c2 = 1; c3 = 1; c4 = 1; c5 = 1;
        u32 temp_r10_2 = (u32)arg2 & 0xFF000000;
        if (((u32)(temp_r10_2 + 0x80000000) != 0U) && ((u32)(((u32)arg2 & 0xFF800000) + 0x7F000000) != 0U)) c5 = 0;
        if ((!c5) && ((u32)(((u32)arg2 & 0xF8000000) + 0x70000000) != 0U)) c4 = 0;
        if ((!c4) && ((u32)(temp_r10_2 + 0x40000000) != 0U)) c3 = 0;
        if ((!c3) && ((u32)(((u32)arg2 & 0xFF800000) + 0x3F000000) != 0U)) c2 = 0;
        if ((!c2) && ((u32)(((u32)arg2 & 0xF8000000) + 0x30000000) != 0U)) c1 = 0;
        if ((!c1) && ((u32)(((u32)arg2 & 0xFFFFC000) + 0x20000000) != 0U)) c0 = 0;
        if (!c0) ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDC, msg + 0x1D0, arg2);
    }

    if (var_r30 < 0) {
        ((void (*)(const char *, s32, const char *, ...))Panic__Q26nw4hbm2dbFPCciPCce)(msg + 0x10, 0xDD, msg + 0x208, var_r30, 0);
    }
    temp_f31 = lbl_80560ED0;
    arg0[0] = temp_f31;
    arg0[2] = temp_f31;
    arg0[1] = temp_f31;
    arg0[3] = temp_f31;
    SetCursor__Q36nw4hbm2ut10CharWriterFff(arg1, temp_f31, temp_f31);
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

