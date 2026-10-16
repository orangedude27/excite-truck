// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_80320548;
extern const char lbl_80320570[];
extern const char lbl_80320688[];
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
    void *addr = (void *)0x80320548;
    *arg0 = addr;
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

extern "C" void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, void *arg1, u32 index) {
    if (index >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320570, 0x1d3, lbl_80320688);
    }
    GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(this_ptr, arg1, index >> 1);
}

extern "C" void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *this_ptr, const void *src, u32 index) {
    if (index >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B8C, 0x5f, lbl_80320B5C);
    }
    const u8 *base = (const u8 *)src + (index * 4);
    ((u8 *)this_ptr)[0] = base[0xD8];
    ((u8 *)this_ptr)[1] = base[0xD9];
    ((u8 *)this_ptr)[2] = base[0xDA];
    ((u8 *)this_ptr)[3] = base[0xDB];
}

extern "C" void SetVtxColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color) {
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

extern "C" void SetTextColor__Q36nw4hbm3lyt7TextBoxFUlQ36nw4hbm2ut5Color(void *this_ptr, u32 index, const void *color) {
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

