// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <MSL/extras.h>

extern void fn_80128668(void*);
extern void fn_802C6CF8(void*);
typedef struct {
    char* unk_0x0;
    s32 unk_0x4;
    u8 unk_0x8[4];
} Unk8016A0AC;
extern Unk8016A0AC lbl_80430340;

void fn_8016A0AC(void) {
}

void fn_8016A0B0(void* alarm) {
    fn_8016AC90(fn_8016A8F8(alarm));
}

extern void fn_8002F6AC(void*, void *(*)(void*, s32));
extern void* fn_8016B550(void*, s32);
extern s32 lbl_80430318;
extern s32 lbl_804302F0;
extern f32 lbl_80561958;
extern f32 lbl_8056195C;
extern f32 lbl_8055E3C8;
void fn_8016A0D4(void) {
 s32 i=0, off=0; u8* ptr;
 while(i < *(s32*)((u8*)&lbl_80430340+4)) { ptr=(u8*)(*(u32*)&lbl_80430340)+off; ptr[0x28]=0; off+=0x2c; i++; }
 i=0; off=0;
 while(i < *(s32*)((u8*)&lbl_80430318+4)) { ptr=(u8*)(*(u32*)&lbl_80430318)+off; ptr[0x3c]=0; off+=0x48; ptr[0x3d]=0; *(f32*)(ptr+0x40)=lbl_80561958; *(f32*)(ptr+0x44)=lbl_8056195C; i++; }
}

extern f32 lbl_8055E3C8;
void fn_8016A240(const char *arg0) {
    s32 *state = &lbl_80430340.unk_0x4;
    s32 i = 0;
    s32 offset = 0;
    s32 zero = 0;
    u8 *entry;
    while (i < *state) {
        if (stricmp(lbl_80430340.unk_0x0 + offset + 1, arg0) == 0) {
            s32 j = 0;
            entry = (u8 *)lbl_80430340.unk_0x0 + offset;
            entry[0x28] = zero;
            while (j < *(s32 *)(entry + 0x24)) {
                u8 *record = (u8 *)lbl_80430318 + ((*(s32 *)(entry + 0x20) + j) * 0x48);
                if (record[0x3c] != 0) {
                    record[0x3c] = zero;
                    *(f32 *)(record + 0x44) = lbl_8055E3C8;
                }
                j++;
            }
        }
        offset += 0x2c;
        i++;
    }
}

void fn_8016A68C(void* arg0) {
    fn_8016B634(fn_8016B598(arg0));
}

extern f32 lbl_80561970;
s32 fn_8016A6B0(const char *arg0, s32 arg1) {
    s32 i = 0;
    s32 nameOffset = 0;
    s32 itemOffset = 0;
    s32 count = *(s32 *)((char *)&lbl_80430340 + 4);
    while (i < count) {
        if (stricmp(*(char **)&lbl_80430340 + nameOffset + 1, arg0) == 0 &&
            arg1 == *(s32 *)((char *)&lbl_80430318 + itemOffset + 4)) {
            f32 a = *(f32 *)((char *)&lbl_80430318 + i * 0x48 + 0x38);
            f32 b = *(f32 *)((char *)&lbl_80430318 + i * 0x48 + 0x30);
            union { f32 f; s32 i; } result;
            result.f = b;
            return result.i;
        }
        nameOffset += 0x2c;
        itemOffset += 0x48;
        i++;
    }
    { union { f32 f; s32 i; } result; result.f = lbl_80561970; return result.i; }
}

#pragma use_lmw_stmw off
s32 fn_8016A878(const char* arg0) {
    s32* state;
    s32 offset;
    s32 count;
    s32 i;
    state = &lbl_80430340.unk_0x4;
    count = 0;
    i = 0;
    offset = 0;
    while (i < *state) {
        if (stricmp(lbl_80430340.unk_0x0 + offset + 1, arg0) == 0) count++;
        offset += 0x2C;
        i++;
    }
    return count;
}
#pragma use_lmw_stmw on
void fn_8016AC18(u8* arg0) { *arg0 = 0; }

void* fn_8016AC24(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (*(u8*)arg0 != 0) {
            fn_802C6CF8(*(void**)((u8*)arg0 + 0x20));
            *(u8*)arg0 = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8016B4F0(u8* arg0) { *arg0 = 0; }

u8* fn_8016B4FC(u8* arg0, s32 arg1) { if(arg0) { *arg0=0; if(arg1>0) fn_80128668(arg0); } return arg0; }

void fn_8016B544(u8* arg0) { *arg0 = 0; }

void* fn_8016B550(void* arg0, s32 arg1) { if(arg0) { *(u8*)arg0=0; if(arg1>0) fn_80128668(arg0); } return arg0; }

