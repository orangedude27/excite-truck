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
s32 fn_8016AC90(s32);
extern char lbl_80330510[];
extern char lbl_803304F8[];
extern char lbl_80330654[];
extern char lbl_8033062C[];
extern char lbl_80330604[];
extern char lbl_80330688[];
extern char lbl_80330540[];
extern char lbl_80330578[];
extern char lbl_803305A0[];
extern char lbl_803305D8[];
extern char lbl_80430318[];
extern char lbl_8055A1D0[];
extern char lbl_8055A1D8[];
extern char lbl_8055A1E0[];
extern char lbl_8055A1E8[];
extern char lbl_8055A1F0[];
extern char lbl_8055A1F8[];
extern char lbl_8055A200[];
extern void fn_8016B4F0(u8*);
extern u8 *fn_8016B4FC(u8*, s32);
extern void fn_8016B544(u8*);
extern void *fn_8016B550(void*, s32);
extern char lbl_804302E0[];
extern float lbl_8056195C;
extern void *fn_8000AC38(void);
extern void *fn_80204EA0(void*);
extern void *fn_80131810(void);
extern void fn_80131818(void*);
extern float PSVECDotProduct(float*, float*, float);
extern void* fn_8016AC24(void*, s32);
extern char lbl_80330460[];
extern char lbl_80330528[];
extern char lbl_80330688[];
extern char lbl_803306A0[];
extern char lbl_803306B4[];
typedef struct { f32 f[9]; s32 w[3]; } Blk8016A438;
extern f32 fn_801E7E18(void);
extern void fn_802C9900(f32);
extern void fn_802C9904(void);
extern void fn_802C70AC(s32, f32*, s32, s32);
extern f32 lbl_80561960;
extern f32 lbl_80561970;
extern f32 lbl_80561974;
extern f32 lbl_80561978;
extern f32 lbl_8056197C;

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
        clear = 0;
        recordCount = (s32 *)(lbl_80430318 + 4);
        count = 0;
        recordOffset = 0;

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

s32 fn_8016A15C(const char *arg0) {
    register s32 i = 0;
    register s32 offset = 0;
    register s32 found = 0;
    register f32 fval = lbl_80561958;
    s32 j;
    u8 *entry;
    u8 *record;
    while (i < lbl_80430340.unk_0x4) {
        if (stricmp(lbl_80430340.unk_0x0 + offset + 1, arg0) == 0) {
            entry = (u8 *)lbl_80430340.unk_0x0 + offset;
            entry[0x28] = 1;
            j = 0;
            while (j < *(s32 *)(entry + 0x24)) {
                record = (u8 *)*(s32 *)lbl_80430318 + ((*(s32 *)(entry + 0x20) + j) * 0x48);
                record[0x3d] = 0;
                *(f32 *)(record + 0x40) = fval;
                record[0x3c] = 1;
                *(f32 *)(record + 0x44) = lbl_8055E3C8;
                j++;
            }
            found = 1;
        }
        offset += 0x2c;
        i++;
    }
    return found;
}

#pragma scheduling on
#pragma small_data on
extern f32 lbl_8055E3C8;
#pragma push
#pragma small_data off
void fn_8016A240(const char *arg0) {
    s32 *state;
    s32 offset;
    s32 i;
    s32 zero;

    state = &lbl_80430340.unk_0x4;
    i = 0;
    offset = 0;
    zero = 0;

    while (i < *state) {
        if (stricmp(lbl_80430340.unk_0x0 + offset + 1, arg0) == 0) {
            s32 j = 0;
            char *entry = lbl_80430340.unk_0x0 + offset;
            entry[0x28] = zero;
            while (j < *(s32 *)(entry + 0x24)) {
                char *record = *(char **)lbl_80430318 + (*(s32 *)(entry + 0x20) + j) * 0x48;
                if (*(u8 *)(record + 0x3c) != 0) {
                    *(u8 *)(record + 0x3c) = zero;
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
s32 fn_8016A30C(void) {
 f32 a,b; s32 f,e,g,c,h,d; void *p;
 c=fn_8017960C(); if(c) { a=lbl_80561960; f=0;e=0;g=0;
 goto check;
 loop:
 d=0;h=0;p=(void *)(*(s32 *)&lbl_80430318+g);
 if(*(u8 *)((u8 *)p+0x3c) && !*(u8 *)((u8 *)p+0x3d)) h=1;
 if(h) { b=(f32)*(s32 *)((u8 *)p+4); if(lbl_8055E364)b+=a;
 if(PSVECSquareDistance((void *)(c+0x60),(u8 *)p+0x30)<b*b) {*(u8 *)((u8 *)p+0x3d)=1;d=1;*(f32 *)((u8 *)p+0x40)=lbl_8055E3C8;} }
 if(d)f++; g+=0x48;e++;
 check:
 if(e < *(s32 *)((u8 *)&lbl_80430318+4)) goto loop;
 return f;} return 0;
}

#pragma ppc_psq_save off
void fn_8016A438(void) {
    Blk8016A438 blk;
    s32 i;
    s32 j;
    char *ent;
    char *rec;
    f32 now;
    f32 t;
    f32 scale;
    for (i = 0; i < lbl_80430340.unk_0x4; i++) {
        ent = lbl_80430340.unk_0x0 + i * 0x2C;
        j = *(s32 *)(ent + 0x24);
        while (j-- > 0) {
            rec = *(char **)lbl_80430318 + (*(s32 *)(ent + 0x20) + j) * 0x48;
            if (*(u8 *)rec == 0)
                continue;
            now = fn_801E7E18();
            t = ((now - *(f32 *)(rec + 0x44)) - lbl_80561970) / lbl_80561974;
            if (t > lbl_80561960)
                t = lbl_80561960;
            if (!(t > lbl_80561970))
                t = lbl_80561970;
            scale = lbl_80561970 + t * lbl_80561960;
            if (*(u8 *)(rec + 0x3C) == 0)
                scale = lbl_80561960 - scale;
            if (scale > lbl_80561978) {
                fn_802C9900(scale);
                blk = *(Blk8016A438 *)(rec + 0xC);
                blk.f[0] *= scale;
                blk.f[1] *= scale;
                blk.f[2] *= scale;
                blk.f[3] *= scale;
                blk.f[4] *= scale;
                blk.f[5] *= scale;
                blk.f[6] *= scale;
                blk.f[7] *= scale;
                blk.f[8] *= scale;
                if (*(u8 *)(rec + 0x3D) != 0) {
                    fn_802C70AC(*(s32 *)(*(char **)(rec + 8) + 0x20), blk.f, -1, 4);
                    if (now - *(f32 *)(rec + 0x40) > lbl_8056197C && *(u8 *)(rec + 0x3C) != 0) {
                        *(u8 *)(rec + 0x3C) = 0;
                        *(f32 *)(rec + 0x44) = lbl_8055E3C8;
                    }
                } else {
                    fn_802C70AC(*(s32 *)(*(char **)(rec + 8) + 0x20), blk.f, -1, 2);
                }
                fn_802C9904();
            }
        }
    }
}
#pragma ppc_psq_save reset

void fn_8016B634(s32 arg0);

void fn_8016A68C(void* arg0) {
    fn_8016B634(fn_8016B598(arg0));
}

extern f32 lbl_80561970;
typedef struct { f32 first; f32 second; } FloatPair8016A6B0;
FloatPair8016A6B0 fn_8016A6B0(const char *arg0, s32 arg1) {
    register s32 nameOffset;
    register s32 itemOffset;
    register s32 i;
    i = 0;
    nameOffset = 0;
    itemOffset = 0;
    while (i < lbl_80430340.unk_0x4) {
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

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
/* Counts entries in the named group whose projected offset from the vehicle is below the threshold. */
s32 fn_8016A780(const char *arg0, s32 arg1) {
    register void *veh;
    register s32 nameOff;
    register s32 itemOff;
    register s32 count;
    register s32 i;
    register const char *name;
    register f32 thresh;
    name = arg0;
    count = 0;
    veh = ((void*(*)(s32))fn_8017960C)(arg1);
    if (veh != 0) {
        thresh = lbl_80561970;
        i = 0;
        nameOff = 0;
        itemOff = 0;
        while (i < lbl_80430340.unk_0x4) {
            if (stricmp(lbl_80430340.unk_0x0 + nameOff + 1, name) == 0) {
                char *rec = *(char **)lbl_80430318 + itemOff;
                f32 d[3];
                d[0] = *(f32 *)(rec + 0x30) - *(f32 *)((char *)veh + 0x60);
                d[1] = *(f32 *)(rec + 0x34) - *(f32 *)((char *)veh + 0x64);
                d[2] = *(f32 *)(rec + 0x38) - *(f32 *)((char *)veh + 0x68);
                if (((f32(*)(f32*, f32*))PSVECDotProduct)(d, (f32 *)(rec + 0x24)) < thresh) {
                    count++;
                }
            }
            nameOff += 0x2c;
            itemOff += 0x48;
            i++;
        }
    }
    return count;
}
#pragma pop

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

s32 fn_8016AC90(s32 unused) {
    typedef struct AEntry { u8 flag; u8 pad1[3]; void *ptr4; void *ptr8; float data[11]; u8 b3c; u8 b3d; u8 pad3e[2]; float f40; float f44; } AEntry;
    typedef struct BEntry { u8 flag; char name[31]; s32 first; s32 count; u8 last; } BEntry;
    Ctr804302F0 *aMgr;
    Ctr804302F0 *bMgr;
    void *obj;
    void *cfg;
    void *iter;
    void *item;
    void *sub;
    s32 i;
    s32 j;
    s32 k2;
    AEntry *aEnt;
    BEntry *bEnt;
    float floats[12];
    float v1[3];
    float v2[3];
    float limit;
    float base;
    aMgr = (Ctr804302F0 *)&lbl_80430318;
    bMgr = (Ctr804302F0 *)&lbl_80430340;
    if (aMgr->ptr10 != 0) {
        fn_8002F6AC(aMgr->ptr10, fn_8016B550);
        aMgr->ptr10 = 0;
        aMgr->cap = 0;
        aMgr->data = 0;
        aMgr->count = 0;
        aMgr->limit = 0;
    }
    aMgr->cap = 0xb4;
    aMgr->ptr10 = (void*)fn_8002F37C((void*)fn_8012850C(aMgr->cap * 0x48 + 0x10, &lbl_80330510), fn_8016B544, fn_8016B550, 0x48, aMgr->cap);
    aMgr->data = aMgr->ptr10;
    aMgr->limit = aMgr->cap;
    aMgr->count = 0;
    if (bMgr->ptr10 != 0) {
        fn_8002F6AC(bMgr->ptr10, (void*(*)(void*,s32))fn_8016B4FC);
        bMgr->ptr10 = 0;
        bMgr->cap = 0;
        bMgr->data = 0;
        bMgr->count = 0;
        bMgr->limit = 0;
    }
    bMgr->cap = 0x24;
    bMgr->ptr10 = (void*)fn_8002F37C((void*)fn_8012850C(bMgr->cap * 0x2c + 0x10, &lbl_803304F8), fn_8016B4F0, (void*)fn_8016B4FC, 0x2c, bMgr->cap);
    bMgr->data = bMgr->ptr10;
    bMgr->limit = bMgr->cap;
    bMgr->count = 0;
    obj = *(void **)((char *)fn_8000AC38() + 0x20);
    cfg = fn_80204EA0(&lbl_80330460[0x14]);
    if (((s32 (*)(void*, void*, s32))(*(void ***)obj)[3])(obj, cfg, 0) != 0) {
        ((void *(*)(void*, void*))(*(void ***)obj)[5])(obj, cfg);
        iter = fn_80131810();
        if (iter != 0) {
            limit = lbl_80561970;
            base = lbl_8056195C;
            for (i = 0; ; i++) {
                item = ((void *(*)(void*, s32))(*(void ***)iter)[2])(iter, i);
                if (item == 0) break;
                ((void (*)(void*))(*(void ***)item)[2])(item);
                if (strcmp((char *)((void *(*)(void*))(*(void ***)item)[2])(item), &lbl_80330460[0x24]) == 0) {
                    bEnt = &((BEntry *)bMgr->data)[bMgr->count];
                    bMgr->count++;
                    bEnt->flag = 0;
                    if (((void *(*)(void*, char*))(*(void ***)item)[2])(item, lbl_8055A1E0) != 0) {
                        char *nm = ((char *(*)(void*, void*))(*(void ***)item)[5])(item, lbl_8055A1D8);
                        s32 k = 0x1e;
                        char *dst = bEnt->name;
                        while (k-- > 0) {
                            char c = *nm++;
                            *dst++ = c;
                            if (c == 0) break;
                        }
                        dst[-1] = 0;
                        bEnt->first = aMgr->count;
                        bEnt->count = 0;
                        for (j = 0; ; j++) {
                            sub = ((void *(*)(void*, s32))(*(void ***)iter)[24])(item, j);
                            if (sub == 0) break;
                            ((void (*)(void*))(*(void ***)sub)[2])(sub);
                            if (strcmp((char *)((void *(*)(void*))(*(void ***)sub)[2])(sub), lbl_8055A1D0) == 0) {
                                aEnt = &((AEntry *)aMgr->data)[aMgr->count];
                                aMgr->count++;
                                aEnt->flag = 0;
                                if (((s32 (*)(void*, void*, s32, void*))(*(void ***)sub)[3])(sub, lbl_8055A200, aMgr->count, aMgr->data) != 0) {
                                    if (((s32 (*)(void*, void*, s32, void*))(*(void ***)sub)[3])(sub, lbl_8055A1F8, aMgr->count, aMgr->data) == 0) {
                                        fn_802E30C8(&lbl_8033062C);
                                    } else {
                                        aEnt->ptr4 = ((void *(*)(void*, void*))(*(void ***)sub)[7])(sub, lbl_8055A1F0);
                                        ((void (*)(void*, void*, void*))(*(void ***)sub)[17])(floats, sub, lbl_8055A1E8);
                                        aEnt->data[0] = floats[0];
                                        aEnt->data[1] = floats[1];
                                        aEnt->data[2] = floats[2];
                                        aEnt->data[3] = floats[3];
                                        aEnt->data[4] = floats[4];
                                        aEnt->data[5] = floats[5];
                                        aEnt->data[6] = floats[6];
                                        aEnt->data[7] = floats[7];
                                        aEnt->data[8] = floats[8];
                                        aEnt->data[9] = floats[9];
                                        aEnt->data[10] = floats[10];
                                        {
                                            s32 found = -1;
                                            s32 ctr = ((Ctr804302F0 *)&lbl_804302F0)->count;
                                            AEntry *p2;
                                            for (p2 = (AEntry *)((Ctr804302F0 *)&lbl_804302F0)->data; ctr > 0; p2++, ctr--) {
                                                if (p2->ptr4 == aEnt->ptr4) { found = (s32)(p2 - (AEntry *)((Ctr804302F0 *)&lbl_804302F0)->data); break; }
                                            }
                                            if (found >= 0) {
                                                aEnt->ptr8 = &((AEntry *)((Ctr804302F0 *)&lbl_804302F0)->data)[found];
                                                aEnt->b3c = 0;
                                                aEnt->f44 = base;
                                                aEnt->flag = 1;
                                            } else {
                                                fn_802E30C8(&lbl_80330654, aEnt->ptr4);
                                            }
                                        }
                                    }
                                } else {
                                    fn_802E30C8(&lbl_80330604);
                                }
                                if (aEnt->flag != 0) {
                                    bEnt->count++;
                                } else {
                                    if (aMgr->count > 0) {
                                        aMgr->count--;
                                    }
                                }
                            }
                        }
                        if (bEnt->count > 2) {
                            AEntry *firstEnt = &((AEntry *)aMgr->data)[bEnt->first];
                            AEntry *secondEnt = &((AEntry *)aMgr->data)[bEnt->first + 1];
                            v1[0] = secondEnt->data[9] - firstEnt->data[9];
                            v1[1] = secondEnt->data[10] - firstEnt->data[10];
                            v1[2] = secondEnt->data[11] - firstEnt->data[11];
                            for (k2 = bEnt->first + 2; k2 < bEnt->first + bEnt->count; k2++) {
                                AEntry *cur = &((AEntry *)aMgr->data)[k2];
                                AEntry *prev = &((AEntry *)aMgr->data)[k2 - 1];
                                v2[0] = cur->data[9] - prev->data[9];
                                v2[1] = cur->data[10] - prev->data[10];
                                if (PSVECDotProduct(v2, v1, cur->data[11] - prev->data[11]) < limit) {
                                    fn_802E30C8(&lbl_803305A0);
                                    fn_802E30C8(&lbl_80330578, bEnt->name + 1);
                                    fn_802E30C8(&lbl_80330540);
                                }
                            }
                        }
                        bEnt->last = 0;
                        bEnt->flag = 1;
                    } else {
                        fn_802E30C8(&lbl_803305D8);
                    }
                    if (bEnt->flag == 0 && bMgr->count > 0) {
                        bMgr->count--;
                    }
                }
            }
            fn_80131818(iter);
            return 0;
        }
        fn_802E30C8(&lbl_80330460[0x30], ((void *(*)(void*, void*))(*(void ***)obj)[5])(obj, &lbl_80330460[0x58]));
        return 0;
    }
    fn_802E30C8(&lbl_80330460[0x64]);
    return 0;
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
    register void *entry;
    register s32 offset;
    register s32 count;
    count = 0;
    offset = 0;

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
