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

typedef struct {
    u8 flag;
    char name[31];
    s32 handle;
    s32 id;
} Entry28;
typedef struct {
    Entry28* data;
    s32 count;
    s32 limit;
    s32 pad0c;
    Entry28* ptr10;
    s32 cap;
} Ctr804302F0;
extern void* fn_8000AC38(void);
extern s32 fn_8002F37C(void*, void*, void*, s32, s32);
extern s32 fn_8012850C(s32, void*);
extern s32 fn_8012C33C(void*);
extern void fn_801345D8(void*, s32, void*, s32);
extern s32 fn_802C6FC0(void*, s32, s32);
extern void fn_802E30C8(void*, s32, void*);
extern s32 fn_8016A8F8(void*);
extern void fn_8016AC18(u8*);
extern void* fn_8016AC24(void*, s32);
extern char lbl_80330460[];
extern char lbl_80330528[];
extern char lbl_80330688[];
extern char lbl_803306A0[];
extern char lbl_803306B4[];

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

extern f32 PSVECSquareDistance(void *, void *);
extern s32 fn_8017960C(void);
extern u8 lbl_8055E364;
extern f64 lbl_80561968;
extern f32 lbl_80561960;
s32 fn_8016A30C(void) {
 f32 a,b; s32 c,d,e,f,g,h; void *p;
 c=fn_8017960C(); if(c) { a=lbl_80561960; f=0;e=0;g=0;
 loop: if(e < *(s32 *)((u8 *)&lbl_80430318+4)) { d=0;h=0;p=(void *)(*(s32 *)&lbl_80430318+g);
 if(*(u8 *)((u8 *)p+0x3c) && !*(u8 *)((u8 *)p+0x3d)) h=1;
 if(h) { b=(f32)*(s32 *)((u8 *)p+4); if(lbl_8055E364)b+=a;
 if(PSVECSquareDistance((void *)(c+0x60),(u8 *)p+0x30)<b*b) {*(u8 *)((u8 *)p+0x3d)=1;d=1;*(f32 *)((u8 *)p+0x40)=lbl_8055E3C8;} }
 if(d)f++; g+=0x48;e++;goto loop;} return f;} return 0;
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

s32 fn_8016A8F8(void* alarm) {
    Ctr804302F0* c = (Ctr804302F0*)&lbl_804302F0;
    void* obj;
    void** vtable;
    Entry28* entry;
    s32 cur;
    s32 i;
    s32 var24 = 1;

    obj = *(void**)((char*)fn_8000AC38() + 0x20);
    vtable = *(void**)obj;
    lbl_8055E364 = ((s32(*)(void*, void*, s32))vtable[0xC])(obj, &lbl_80330460, 0);

    if (c->ptr10 != 0) {
        fn_8002F6AC(c->ptr10, fn_8016AC24);
        c->ptr10 = 0;
        c->cap = 0;
        c->data = 0;
        c->count = 0;
        c->limit = 0;
    }
    c->cap = 5;
    c->ptr10 = (Entry28*)fn_8002F37C((void*)fn_8012850C(5 * 0x28 + 0x10, &lbl_80330528), fn_8016AC18, fn_8016AC24, 0x28, 5);
    c->data = c->ptr10;
    c->limit = c->cap;
    c->count = 0;

    while (c->count + 1 <= c->limit && var24 < 0x64) {
        cur = c->count;
        entry = &c->data[cur];
        c->count = cur + 1;
        if (entry->flag != 0) {
            fn_802C6CF8((void*)entry->handle);
            entry->flag = 0;
        }
        if (lbl_8055E364 != 0) {
            fn_801345D8(entry->name, 0x1e, &lbl_803306B4, var24);
        } else {
            fn_801345D8(entry->name, 0x1e, &lbl_803306A0, var24);
        }
        if (fn_8012C33C(entry->name) != 0) {
            entry->handle = fn_802C6FC0(entry->name, 0, 0);
            entry->id = var24;
            entry->flag = 1;
            fn_802E30C8(&lbl_80330688, var24, entry->name);
        }
        if (entry->flag == 0) {
            i = c->count - 1;
            if (i >= 0) {
                if (i < c->count) {
                    if (i != c->count - 1) {
                        c->data[i] = c->data[c->count - 1];
                    }
                    c->count = c->count - 1;
                }
            }
        }
        var24++;
    }
    return 0;
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

