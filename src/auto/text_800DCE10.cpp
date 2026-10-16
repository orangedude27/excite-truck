// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055DDF0;
extern void *MEMAllocFromAllocator(void *, u32);
extern void MEMFreeToAllocator(void *, void *);
extern "C" u16 fn_8002AEE8(const u16 *);

extern void lbl_80320548(void);
extern const char lbl_80320570[];
extern const char lbl_80320688[];
extern const char lbl_803206B8[];
extern const char lbl_80320B5C[];
extern const char lbl_80320B8C[];
extern const char lbl_80320BC8[];
extern const char lbl_80320B98[];
extern "C" s32 fn_80128668(void);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *);

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

extern "C" void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, void *arg1, u32 index);
extern "C" void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, const void *src, u32 index);
extern "C" void SetTextColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color);
extern "C" void SetVtxColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color);

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *) __attribute__((noreturn));
void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, void *arg1, u32 index) {
    if (index >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320570, 0x1d3, lbl_80320688);
    }
    GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(this_ptr, arg1, index >> 1);
}

void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, const void *src, u32 index) {
    if (index >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B8C, 0x5f, lbl_80320B5C);
    }
    const u8 *base = (const u8 *)src + (index * 4);
    ((u8 *)this_ptr)[0] = base[0xD8];
    ((u8 *)this_ptr)[1] = base[0xD9];
    ((u8 *)this_ptr)[2] = base[0xDA];
    ((u8 *)this_ptr)[3] = base[0xDB];
}

void SetVtxColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color) {
    if (index >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320570, 0x1de, lbl_80320688);
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
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320BC8, 0x60, lbl_80320B98);
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
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320570, 0x1e6, lbl_803206B8);
    }
    u32 part1 = (index >> 1) & 0x7FFFFFFC;
    u32 part2 = index & 3;
    u8 *base = (u8 *)this_ptr + part1;
    return base[part2 + 0xD8];
}

extern "C" void SetVtxColorElement__Q36nw4hbm3lyt7TextBoxFUlUc(void *this_ptr, u32 index, u8 color) {
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
            void *vtbl = *(void **)this_ptr;
            void (*fn)(void*) = (void (*)(void*))*(void **)((u8 *)vtbl + 0x68);
            fn(this_ptr);
            void *result = MEMAllocFromAllocator(lbl_8055DDF0, bytes);
            *(void **)((u8 *)this_ptr + 0xD4) = result;
            if (result != NULL) {
                *(u16 *)((u8 *)this_ptr + 0xF8) = bytes;
            }
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

extern "C" s32 fn_800DF1C8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" unsigned int* fn_800DFC54(void) {
    extern unsigned int lbl_8055DE08;
    return &lbl_8055DE08;
}

