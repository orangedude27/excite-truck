// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <MSL/extras.h>

#pragma cplusplus on
class ObjVt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual s32 f(void* a, s32 b);
};
#pragma cplusplus off

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
extern void *getDifficultySettingString(void*);
extern void *fn_80131810(void);
extern void releaseValueFile(void*);
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

/* Empty stub. */
void fn_8016A0AC(void) {
}

/* Once the scene's objects exist, register their names (fn_8016A8F8) and
   rebuild the course/path graph (fn_8016AC90). The forwarded argument is an
   unused callback context; both callees ignore it. */
void fn_8016A0B0(void* unused) {
    fn_8016AC90(fn_8016A8F8(unused));
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
/* Clears active flags in both object/record tables and resets each record's per-entry state and timer values. */
void fn_8016A0D4(void) {
    s32 entryIndex;
    for (entryIndex = 0; entryIndex < lbl_80430340.unk_0x4; entryIndex++) {
        ((u8 *)lbl_80430340.unk_0x0)[entryIndex * 0x2C + 0x28] = 0;
    }
    {
        register u8 *record;
        register s32 recordOffset;
        register s32 recordIndex;
        register f32 resetValue1;
        register f32 resetValue2;
        resetValue2 = lbl_80561958;
        resetValue1 = lbl_8056195C;
        recordIndex = 0;
        recordOffset = 0;
        goto check_record;
    next_record:
        recordIndex++;
        record = (u8 *)(*(s32 *)lbl_80430318) + recordOffset;
        record[0x3C] = 0;
        recordOffset += 0x48;
        record[0x3D] = 0;
        *(f32 *)(record + 0x40) = resetValue2;
        *(f32 *)(record + 0x44) = resetValue1;
    check_record:
        if (recordIndex < *(s32 *)(lbl_80430318 + 4))
            goto next_record;
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Enable the named object class: mark its table entry active and enable/reset
   every record it owns. Returns 1 if the name was found, 0 otherwise. */
s32 fn_8016A15C(const char *name) {
    register s32 found;
    register f32 resetTime = lbl_80561958;
    s32 recordIdx;
    u8 *entry;
    u8 *record;
    s32 entryOffset;
    s32 entryIdx;
    found = 0;
    entryIdx = 0;
    entryOffset = 0;
    while (entryIdx < lbl_80430340.unk_0x4) {
        if (stricmp(lbl_80430340.unk_0x0 + entryOffset + 1, name) == 0) {
            entry = (u8 *)lbl_80430340.unk_0x0 + entryOffset;
            entry[0x28] = 1;
            recordIdx = 0;
            while (recordIdx < *(s32 *)(entry + 0x24)) {
                record = (u8 *)*(s32 *)lbl_80430318 + ((*(s32 *)(entry + 0x20) + recordIdx) * 0x48);
                record[0x3d] = 0;
                *(f32 *)(record + 0x40) = resetTime;
                record[0x3c] = 1;
                *(f32 *)(record + 0x44) = lbl_8055E3C8;
                recordIdx++;
            }
            found = 1;
        }
        entryOffset += 0x2c;
        entryIdx++;
    }
    return found;
}
#pragma pop
extern f32 lbl_8055E3C8;
#pragma push
#pragma small_data off
void fn_8016A240(const char *name) {
    /* Deactivate the named object group: clear its active flag and reset each active instance's timer. */
    s32 instanceIndex;
    u8 *group;
    u8 *instance;
    s32 groupOffset;
    s32 groupIndex;
    groupIndex = 0;
    groupOffset = 0;
    while (groupIndex < lbl_80430340.unk_0x4) {
        if (stricmp(lbl_80430340.unk_0x0 + groupOffset + 1, name) == 0) {
            group = (u8 *)lbl_80430340.unk_0x0 + groupOffset;
            group[0x28] = 0;
            instanceIndex = 0;
            while (instanceIndex < *(s32 *)(group + 0x24)) {
                instance = (u8 *)*(s32 *)lbl_80430318 + ((*(s32 *)(group + 0x20) + instanceIndex) * 0x48);
                if (instance[0x3c] != 0) {
                    instance[0x3c] = 0;
                    *(f32 *)(instance + 0x44) = lbl_8055E3C8;
                }
                instanceIndex++;
            }
        }
        groupOffset += 0x2c;
        groupIndex++;
    }
}
#pragma pop
extern f32 PSVECSquareDistance(void *, void *);
extern s32 getRegisteredObject(void);
extern u8 lbl_8055E364;
extern f64 lbl_80561968;
extern f32 lbl_80561960;
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
s32 fn_8016A30C(void)
{
  /* Activate nearby entries in lbl_80430318 for the current player object:
     mark each unvisited active entry within radius as visited, record the time,
     and return how many were activated this call. */
  f32 radiusBonus;
  f32 radius;
  s32 player;
  s32 activated;
  u8 *entry;
  s32 candidate;
  s32 offset;
  s32 activatedCount;
  s32 index;
  f32 *radiusBonusPtr;

  player = getRegisteredObject();
  radiusBonusPtr = &radiusBonus;
  if (player)
  {
    radiusBonus = lbl_80561960;
    activatedCount = 0;
    index = 0;
    offset = 0;
    while (index < *(s32 *)(lbl_80430318 + 4))
    {
      activated = 0;
      candidate = 0;
      entry = (u8 *)(*(s32 *)lbl_80430318 + offset);
      if (entry[0x3c] && !entry[0x3d])
      {
        candidate = 1;
      }
      if (candidate)
      {
        radius = (f32)(*(s32 *)(entry + 4));
        if (lbl_8055E364)
        {
          radius += *radiusBonusPtr;
        }
        if (PSVECSquareDistance((void *)(player + 0x60), entry + 0x30) < (radius * radius))
        {
          entry[0x3d] = 1;
          activated = 1;
          *(f32 *)(entry + 0x40) = lbl_8055E3C8;
        }
      }
      if (activated)
      {
        activatedCount++;
      }
      offset += 0x48;
      index++;
    }
    return activatedCount;
  }
  return 0;
}
#pragma push
#pragma processor 750
void fn_8016A438(void) {
    Blk8016A438 blk;
    register s32 j;
    register char *ent;
    register char *rec;
    register s32 offset;
    register s32 index;
    f32 c78;
    f32 c74 = lbl_80561974;
    f32 c70 = lbl_80561970;
    f32 c60 = lbl_80561960;
    f32 now;
    f32 t;
    f32 scale;
    f32 c7c = lbl_8056197C;
    c78 = lbl_80561978;
    index = 0;
    offset = 0;
    while (index < lbl_80430340.unk_0x4) {
        ent = lbl_80430340.unk_0x0 + offset;
        j = *(s32 *)(ent + 0x24);
        while (j-- > 0) {
            rec = *(char **)lbl_80430318 + (*(s32 *)(ent + 0x20) + j) * 0x48;
            if (*(u8 *)rec == 0)
                continue;
            now = fn_801E7E18();
            t = ((now - *(f32 *)(rec + 0x44)) - c70) / c74;
            if (c60 < t)
                t = c60;
            t = (t > c70) ? t : c70;
            scale = c70 + t * c60;
            scale = (*(u8 *)(rec + 0x3C) != 0) ? scale : (c60 - scale);
            if (scale > c78) {
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
                    if (now - *(f32 *)(rec + 0x40) > c7c && *(u8 *)(rec + 0x3C) != 0) {
                        *(u8 *)(rec + 0x3C) = 0;
                        *(f32 *)(rec + 0x44) = lbl_8055E3C8;
                    }
                } else {
                    fn_802C70AC(*(s32 *)(*(char **)(rec + 8) + 0x20), blk.f, -1, 2);
                }
                fn_802C9904();
            }
        }
        offset += 0x2c;
        index++;
    }
}
#pragma pop

void fn_8016B634(s32 arg0);

/* Shut down the model subsystem: clear the two manager pools (fn_8016B598),
   then release the model-entry pool (fn_8016B634). */
void fn_8016A68C(void* arg0) {
    fn_8016B634(fn_8016B598(arg0));
}

extern f32 lbl_80561970;
typedef struct { f32 first; f32 second; } FloatPair8016A6B0;
FloatPair8016A6B0 fn_8016A6B0(const char *arg0, s32 arg1) {
    register s32 nameOffset;
    register s32 recordOffset;
    register s32 index;
    /* Find the course marker record matching name (arg0) and ring type (arg1),
       returning its (first, second) position pair, or (0, 0) if not found. */
    index = 0;
    nameOffset = 0;
    recordOffset = 0;
    while (index < lbl_80430340.unk_0x4) {
        if (stricmp(lbl_80430340.unk_0x0 + nameOffset + 1, arg0) == 0) {
            char *records = *(char **)lbl_80430318;
            if (arg1 == *(s32 *)(records + recordOffset + 4)) {
                FloatPair8016A6B0 result;
                result.second = *(f32 *)(records + index * 0x48 + 0x38);
                result.first = *(f32 *)(records + index * 0x48 + 0x30);
                return result;
            }
        }
        nameOffset += 0x2c;
        recordOffset += 0x48;
        index++;
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
    veh = ((void*(*)(s32))getRegisteredObject)(arg1);
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
/* Count how many named entries in the lbl_80430340 table match the given name (case-insensitive). */
s32 fn_8016A878(const char* name) {
    s32* entryCountPtr;
    s32 entryOffset;
    s32 matchCount;
    s32 index;
    entryCountPtr = &lbl_80430340.unk_0x4;
    matchCount = 0;
    index = 0;
    entryOffset = 0;
    while (index < *entryCountPtr) {
        if (stricmp(lbl_80430340.unk_0x0 + entryOffset + 1, name) == 0) matchCount++;
        entryOffset += 0x2C;
        index++;
    }
    return matchCount;
}

#pragma cplusplus on
extern "C" s32 fn_8016A8F8(void* alarm) {
    s32 cur;
    void* obj;
    Entry28* entry;
    volatile Ctr804302F0* vc;
    u8* d;
    u8* s;
    s32 sj;
    s32 i;
    s32 n;
    s32 var24;
    obj = *(void**)((char*)fn_8000AC38() + 0x20);
    lbl_8055E364 = ((ObjVt*)obj)->f(&lbl_80330460, 0);
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
        cur = ((volatile Ctr804302F0 *)&lbl_804302F0)->count;
        entry = &lbl_804302F0.data[cur];
        lbl_804302F0.count = cur + 1;
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
            vc = &lbl_804302F0;
            i = vc->count - 1;
            if (i >= 0) {
                n = vc->count;
                if (i < n) {
                    if (i != n - 1) {
                        sj = (n - 1) * 0x28;
                        d = (u8*)lbl_804302F0.data + i * 0x28;
                        s = (u8*)lbl_804302F0.data + sj;
                        d[0] = s[0];
                        {
                            struct Name30 { char v[30]; };
                            *(struct Name30 *)(d + 1) = *(struct Name30 *)(s + 1);
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
#pragma cplusplus off
/* Pool element init callback: clear the byte flag at +0 of a 0x28-byte entry. */
void fn_8016AC18(u8* entry) { *entry = 0; }

/* Destroy/cleanup helper: if the object is live, release its owned resource at +0x20 and mark it dead, then optionally free the object. */
void* fn_8016AC24(void* self, s32 shouldDelete) {
    if (self != 0) {
        if (*(u8*)self != 0) {
            fn_802C6CF8(*(void**)((u8*)self + 0x20));
            *(u8*)self = 0;
        }
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

#pragma push
#pragma use_lmw_stmw off
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
    float v2[3];
    float v1[3];
    float base;
    float limit;
    aMgr = (Ctr804302F0 *)(lbl_804302E0 + 0x38);
    bMgr = (Ctr804302F0 *)(lbl_804302E0 + 0x60);
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
    cfg = getDifficultySettingString((char*)lbl_80330460 + 0x14);
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
                if (strcmp((char *)((void *(*)(void*))(*(void ***)item)[2])(item), (char*)lbl_80330460 + 0x24) == 0) {
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
                                            s32 ctr = ((Ctr804302F0 *)(lbl_804302E0 + 0x10))->count;
                                            AEntry *p2;
                                            for (p2 = (AEntry *)((Ctr804302F0 *)(lbl_804302E0 + 0x10))->data; ctr > 0; p2++, ctr--) {
                                                if (p2->ptr4 == aEnt->ptr4) { found = (s32)(p2 - (AEntry *)((Ctr804302F0 *)(lbl_804302E0 + 0x10))->data); break; }
                                            }
                                            if (found >= 0) {
                                                aEnt->ptr8 = &((AEntry *)((Ctr804302F0 *)(lbl_804302E0 + 0x10))->data)[found];
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
                                v2[2] = cur->data[11] - prev->data[11];
                                if (((f32(*)(f32*, f32*))PSVECDotProduct)(v2, v1) < limit) {
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
            releaseValueFile(iter);
            return 0;
        }
        fn_802E30C8((char*)lbl_80330460 + 0x30, ((void *(*)(void*, void*))(*(void ***)obj)[5])(obj, (char*)lbl_80330460 + 0x58));
        return 0;
    }
    fn_802E30C8((char*)lbl_80330460 + 0x64);
    return 0;
}
#pragma pop
/* Pool-element initializer: clear a newly allocated element's first
 * (in-use/state) byte, matching the clear done by the pool's release callback. */
void fn_8016B4F0(u8* element) { *element = 0; }

/* RealName: unknown (pool element dtor/init helper; clears first byte and optionally frees when flag > 0) */
u8 *fn_8016B4FC(u8 *ptr, s32 shouldFree) {
    /* Clear the object and, when requested, release its storage. */
    if (ptr) {
        *ptr = 0;
        if (shouldFree > 0) fn_80128668(ptr);
    }
    return ptr;
}

/* Pool-element initializer for the A manager: clear a newly allocated element's
 * first (in-use/state) byte, matching the clear in the release callback fn_8016B550. */
void fn_8016B544(u8* element) { *element = 0; }

/* Reset the object's byte flag and optionally free it. */
void *fn_8016B550(void *object, s32 shouldFree) {
    if (object) {
        *(u8 *)object = 0;
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma optimize_for_size on
/* Shut down the model subsystem's two managers: destroy each one's owned array
 * through its element destructor, clear every manager field, and return 0 when
 * the record manager had no array to destroy. */
int fn_8016B598(void) {
    #define gModelEntryManager lbl_80430340
    #define gModelRecordManager lbl_80430318
    if (*(void **)((char *)&gModelEntryManager + 0x10) != 0) {
        fn_8002F6AC(*(void **)((char *)&gModelEntryManager + 0x10), (void *(*)(void *, s32))fn_8016B4FC);
        *(s32 *)((char *)&gModelEntryManager + 0x10) = 0;
        *(s32 *)((char *)&gModelEntryManager + 0x14) = 0;
        gModelEntryManager.unk_0x0 = 0;
        *(s32 *)((char *)&gModelEntryManager + 4) = 0;
        *(s32 *)((char *)&gModelEntryManager + 8) = 0;
    }
    {
        void *recordArray = *(void **)(gModelRecordManager + 0x10);
        if (recordArray != 0) {
            fn_8002F6AC(recordArray, fn_8016B550);
            *(s32 *)(gModelRecordManager + 0x10) = 0;
            *(s32 *)(gModelRecordManager + 0x14) = 0;
            *(s32 *)gModelRecordManager = 0;
            *(s32 *)(gModelRecordManager + 4) = 0;
            *(s32 *)(gModelRecordManager + 8) = 0;
        } else {
            return (int)recordArray;
        }
    }
    #undef gModelEntryManager
    #undef gModelRecordManager
}
#pragma optimize_for_size reset
void fn_8016B634(s32 arg0) {
    register void *entry;
    register s32 offset;
    register s32 count;
    count = 0;
    offset = 0;

    /* Release all active model entries, then destroy the model-entry pool. */
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
