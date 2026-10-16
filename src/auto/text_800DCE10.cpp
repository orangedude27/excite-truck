// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_80320548;
extern void *lbl_80320570;
extern void *lbl_80320688;
extern void *lbl_80320B5C;
extern void *lbl_80320B8C;
extern "C" s32 fn_80128668(void);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *);

u8 GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index);

extern "C" s32 fn_800DCE10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800DCE50(void **arg0) {
    *arg0 = &lbl_80320548;
}

extern "C" s32 fn_800DCE60(void) {
    return 0;
}

extern "C" void fn_800DCE68(void *arg0, const void *arg1) {
    s16 val;
    u8 b0, b1, b2, b3;
    
    val = ((const s16 *)arg1)[0];
    b0 = (val < 0) ? 0 : (val > 255) ? 255 : (u8)val;
    
    val = ((const s16 *)arg1)[1];
    b1 = (val < 0) ? 0 : (val > 255) ? 255 : (u8)val;
    
    val = ((const s16 *)arg1)[2];
    b2 = (val < 0) ? 0 : (val > 255) ? 255 : (u8)val;
    
    val = ((const s16 *)arg1)[3];
    b3 = (val < 0) ? 0 : (val > 255) ? 255 : (u8)val;
    
    *(u32 *)arg0 = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}

void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *out, const void *this_ptr, u32 index);

u8 GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index);
void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index) {
    if (index >= 4) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80320570, 0x1d3, (const char *)&lbl_80320688);
    }
    GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(out, this_ptr, index >> 1);
}

u8 GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index) {
    if (index >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80320B8C, 0x5f, (const char *)&lbl_80320B5C);
    }
    const u8 *src = (const u8 *)this_ptr + (index * 4) + 0xD8;
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
    out[3] = src[3];
}

