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
    char name[30];
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
extern void fn_801345D8(void*, s32, void*, ...);
extern s32 fn_802C6FC0(void*, s32, s32);
extern void fn_802E30C8(void*, ...);
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
extern char lbl_80430318[];
extern Ctr804302F0 lbl_804302F0;
extern f32 lbl_80561958;
extern f32 lbl_8056195C;
extern f32 lbl_8055E3C8;
#pragma small_data off
#pragma scheduling invalid_target
void fn_8016A0D4(void) {
    s32 i;
    for (i = 0; i < lbl_80430340.unk_0x4; i++) {
        ((u8 *)lbl_80430340.unk_0x0)[i * 0x2C + 0x28] = 0;
    }

    {
        register s32 *recordCount;
        register u8 *entry;
        register s32 recordOffset;
        register s32 count;
        register u8 clear;
        register f32 value1;
        register f32 value2;

        value2 = lbl_80561958;
        value1 = lbl_8056195C;
        recordCount = (s32 *)(lbl_80430318 + 4);
        count = 0;
        recordOffset = 0;
        clear = 0;

        goto check_second;
    second_loop:
        count++;
        entry = (u8 *)(*(s32 *)lbl_80430318) + recordOffset;
        entry[0x3C] = clear;
        recordOffset += 0x48;
        entry[0x3D] = clear;
        *(f32 *)(entry + 0x40) = value2;
        *(f32 *)(entry + 0x44) = value1;
    check_second:
        if (count < *recordCount)
            goto second_loop;
    }
}
#pragma scheduling on
#pragma small_data on
extern f32 lbl_8055E3C8;
#pragma push
#pragma small_data off
void fn_8016A240(const char *arg0) {
    register Unk8016A0AC *table = &lbl_80430340;
    register s32 *state = &table->unk_0x4;
    register volatile s32 *recordSlot = (s32 *)lbl_80430318;
    register s32 i = 0;
    register s32 offset = 0;
    register s32 zero = 0;

    while (i < *state) {
        if (stricmp(table->unk_0x0 + offset + 1, arg0) == 0) {
            register s32 j = 0;
            register u8 *entry = (u8 *)table->unk_0x0 + offset;
            entry[0x28] = zero;
            while (j < *(s32 *)(entry + 0x24)) {
                register u8 *record = (u8 *)(*recordSlot) + ((*(s32 *)(entry + 0x20) + j) * 0x48);
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
#pragma pop
extern f32 PSVECSquareDistance(void *, void *);
extern s32 fn_8017960C(void);
extern u8 lbl_8055E364;
extern f64 lbl_80561968;
extern f32 lbl_80561960;
#pragma push
#pragma paired_single off
#pragma ppc_psq_save off
s32 fn_8016A30C(void) {
 f32 a,b; s32 f,e,g,c,h,d; s32 one=1; void *p;
 c=fn_8017960C(); if(c) { a=lbl_80561960; f=0;e=0;g=0;
 goto check;
 loop:
 d=0;h=0;p=(void *)(*(s32 *)&lbl_80430318+g);
 if(*(u8 *)((u8 *)p+0x3c) && !*(u8 *)((u8 *)p+0x3d)) h=one;
 if(h) { b=(f32)*(s32 *)((u8 *)p+4); if(lbl_8055E364)b+=a;
 if(PSVECSquareDistance((void *)(c+0x60),(u8 *)p+0x30)<b*b) {*(u8 *)((u8 *)p+0x3d)=one;d=one;*(f32 *)((u8 *)p+0x40)=lbl_8055E3C8;} }
 if(d)f++; g+=0x48;e++;
 check:
 if(e < *(s32 *)((u8 *)&lbl_80430318+4)) goto loop;
 return f;} return 0;
}
#pragma pop

void fn_8016B634(s32 arg0);

void fn_8016A68C(void* arg0) {
    fn_8016B634(fn_8016B598(arg0));
}

extern f32 lbl_80561970;
typedef struct { f32 first; f32 second; } FloatPair8016A6B0;
FloatPair8016A6B0 fn_8016A6B0(const char *arg0, s32 arg1) {
    /* Fix note: compare each name and item ID, then return both selected float bit patterns. */
    register s32 nameOffset;
    register s32 itemOffset;
    register s32 i;
    register volatile s32 *nameCount = (volatile s32 *)&lbl_80430340.unk_0x4;
    i = 0;
    nameOffset = 0;
    itemOffset = 0;
    while (i < *nameCount) {
        if (stricmp(lbl_80430340.unk_0x0 + nameOffset + 1, arg0) == 0) {
            char *records = *(char **)lbl_80430318;
            if (arg1 == *(s32 *)(records + itemOffset + 4)) {
                FloatPair8016A6B0 result;
                result.second = *(f32 *)(records + i * 0x48 + 0x38);
                result.first = *(f32 *)(records + i * 0x48 + 0x30);
                return result;
            }
        }
        nameOffset += 0x2c;
        itemOffset += 0x48;
        i++;
    }
    {
        FloatPair8016A6B0 result;
        result.first = lbl_80561970;
        result.second = lbl_80561970;
        return result;
    }
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
    void* obj;
    Entry28* entry;
    volatile Ctr804302F0* vc;
    u8* d;
    u8* s;
    s32 k;
    s32 sj;
    s32 cur;
    s32 i;
    s32 var24;

    obj = *(void**)((char*)fn_8000AC38() + 0x20);
    lbl_8055E364 = ((s32(*)(void*, void*, s32))((*(void***)obj)[0xC]))(obj, &lbl_80330460, 0);

    if (lbl_804302F0.ptr10 != 0) {
        fn_8002F6AC(lbl_804302F0.ptr10, fn_8016AC24);
        lbl_804302F0.ptr10 = 0;
        lbl_804302F0.cap = 0;
        lbl_804302F0.data = 0;
        lbl_804302F0.count = 0;
        lbl_804302F0.limit = 0;
    }
    lbl_804302F0.cap = 5;
    lbl_804302F0.ptr10 = (Entry28*)fn_8002F37C((void*)fn_8012850C(lbl_804302F0.cap * 0x28 + 0x10, &lbl_80330528), fn_8016AC18, fn_8016AC24, 0x28, lbl_804302F0.cap);
    lbl_804302F0.data = lbl_804302F0.ptr10;
    lbl_804302F0.limit = lbl_804302F0.cap;
    lbl_804302F0.count = 0;
    var24 = 1;

    while (lbl_804302F0.count + 1 <= lbl_804302F0.limit && var24 < 0x64) {
        cur = lbl_804302F0.count;
        entry = &lbl_804302F0.data[cur];
        lbl_804302F0.count = cur + 1;
        if (entry->name[0] != 0) {
            fn_802C6CF8((void*)entry->handle);
            entry->name[0] = 0;
        }
        if (lbl_8055E364 != 0) {
            fn_801345D8(entry->name + 1, 0x1e, &lbl_803306B4, var24);
        } else {
            fn_801345D8(entry->name + 1, 0x1e, &lbl_803306A0, var24);
        }
        if (fn_8012C33C(entry->name + 1) != 0) {
            entry->handle = fn_802C6FC0(entry->name + 1, 0, 0);
            entry->id = var24;
            entry->name[0] = 1;
            fn_802E30C8(&lbl_80330688, var24, entry->name + 1);
        }
        if (entry->name[0] == 0) {
            vc = &lbl_804302F0;
            i = vc->count - 1;
            if (i >= 0) {
                if (i < vc->count) {
                    if (i != vc->count - 1) {
                        sj = (vc->count - 1) * 0x28;
                        d = (u8*)lbl_804302F0.data + i * 0x28;
                        s = (u8*)lbl_804302F0.data + sj;
                        for (k = 0; k < 0x1f; k++) {
                            d[k] = s[k];
                        }
                        *(s32*)(d + 0x20) = *(s32*)(s + 0x20);
                        *(s32*)(d + 0x24) = *(s32*)(s + 0x24);
                    }
                    vc->count = vc->count - 1;
                }
            }
        }
        var24++;
    }
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

int fn_8016B598(void) {
    register char *first;
    register char *second;

    first = (char *)&lbl_80430340;
    if (*(void **)(first + 0x10) != 0) {
        fn_8002F6AC(*(void **)(first + 0x10), (void *(*)(void *, s32))fn_8016B4FC);
        *(s32 *)(first + 0x10) = 0;
        *(s32 *)(first + 0x14) = 0;
        lbl_80430340.unk_0x0 = 0;
        *(s32 *)(first + 4) = 0;
        *(s32 *)(first + 8) = 0;
    }
    second = lbl_80430318;
    if (*(void **)(second + 0x10) != 0) {
        fn_8002F6AC(*(void **)(second + 0x10), fn_8016B550);
        *(s32 *)(second + 0x10) = 0;
        *(s32 *)(second + 0x14) = 0;
        *(s32 *)second = 0;
        *(s32 *)(second + 4) = 0;
        *(s32 *)(second + 8) = 0;
    }
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8016B634(s32 arg0) {
    register s32 count = 0;
    register s32 offset = 0;
    register void* entry;

    while (count < lbl_804302F0.count) {
        entry = (void*)((u8*)lbl_804302F0.data + offset);
        if (*(u8*)entry != 0) {
            fn_802C6CF8(*(void**)((u8*)entry + 0x20));
            *(u8*)entry = 0;
        }
        offset += 0x28;
        count++;
    }
    if (lbl_804302F0.ptr10 != 0) {
        fn_8002F6AC(lbl_804302F0.ptr10, fn_8016AC24);
        lbl_804302F0.ptr10 = 0;
        lbl_804302F0.cap = 0;
        lbl_804302F0.data = 0;
        lbl_804302F0.count = 0;
        lbl_804302F0.limit = 0;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw on
