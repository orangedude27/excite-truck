#include "types.h"

extern f32 lbl_8055E3C8;

typedef struct {
    s32* array;
    s32 count;
} unk_804BD6C4_t;

extern unk_804BD6C4_t lbl_804BD6C4;
extern f32 lbl_8055F8D4;
extern f32 lbl_8055F8D8;
extern f32 lbl_80564954;

s32 fn_802A8A34(void* ptr);
void fn_802A8978(void);
void fn_802A81EC(void);

void fn_802A81EC(void) {

}

void fn_802A8978(void) {
    u8* entry;
    s32 j;
    s32 offset;
    s32 i;
    f32 temp;
    s32* base;

    temp = lbl_8055E3C8;
    lbl_8055F8D4 = temp - lbl_8055F8D8;
    if (temp < lbl_8055F8D8) {
        lbl_8055F8D4 = lbl_80564954;
    }
    lbl_8055F8D8 = temp;
    base = (s32*)&lbl_804BD6C4;
    i = 0;
    offset = 0;
    while (i < base[1]) {
        entry = *(u8**)((u32)base + offset);
        fn_802A8A4C((s32)entry, (s32)(entry + 0x60));
        j = 0;
        while (j < fn_802A8A34((void*)(entry + 0x6c))) {
            fn_802A8A3C((s32)(entry + 0x6c), j);
            fn_802A8A4C((s32)entry);
            j++;
        }
        offset += 4;
        i++;
    }
}

s32 fn_802A8A34(void* ptr) {
    return ((s32*)ptr)[1];
}
