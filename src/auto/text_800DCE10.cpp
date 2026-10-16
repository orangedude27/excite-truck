// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_80320548;
extern void *lbl_80320570;
extern void *lbl_80320688;
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

void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index);
void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index);

void GetVtxColor__Q36nw4hbm3lyt7TextBoxCFUl(u8 *out, const void *this_ptr, u32 index) {
    if (index >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80320B8C, 0x5f, (const char *)&lbl_80320B5C);
    }
    const u8 *src = (const u8 *)this_ptr + (index * 4) + 0xD8;
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
    out[3] = src[3];
}

extern "C" void GetTextColor__Q36nw4hbm3lyt7TextBoxCFUl(void *arg0, const void *arg1, u32 index) {
    if (index >= 2) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)&lbl_80320B8C, 0x5f, (const char *)&lbl_80320B5C);
    }
    const u8 *src = (const u8 *)arg1 + (index * 4) + 0xD8;
    ((u8 *)arg0)[0] = src[0];
    ((u8 *)arg0)[1] = src[1];
    ((u8 *)arg0)[2] = src[2];
    ((u8 *)arg0)[3] = src[3];
}

