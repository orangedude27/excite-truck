#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000A7A8(void);
extern void fn_8000A6D8(void) DECOMP_DONT_INLINE;
extern void fn_8000A808(void);
extern void fn_80128668(void*);
extern void fn_80009DC8();
extern char *fn_80016474(s32);
extern char *fn_80016544(s32);
extern s32 *fn_8001675C(s32, s32);
extern s32 fn_80016804(s32, s32);
extern s32 fn_80137C74(void);
extern char lbl_80558A08[];
extern char lbl_80558A10[];
extern f32 lbl_805601F0;

typedef struct ListEntry_80009DC8 {
    s32 kind;
    char name[0x40];
    char label[0x20];
    f32 f64;
    s32 key;
    s32 key2;
    union {
        u8 raw;
        struct {
            u8 hi : 6;
            u8 lo : 2;
        };
    } bits;
    s32 f74;
} ListEntry_80009DC8;

static inline void StoreEntry_80009DC8(ListEntry_80009DC8 *dst, ListEntry_80009DC8 src) {
    *dst = src;
}

static inline void CopyStr_80009DC8(char *dst, const char *src, s32 n) {
    u8 c;
    goto body;
decr:
    if (--n <= 0) {
        dst[-1] = 0;
        return;
    }
body:
    c = *src++;
    *dst++ = c;
    if ((s8)c != 0) goto decr;
}
extern void fn_801345D8(void*, s32, void*, s32);
extern u8 lbl_80558A14;
extern void fn_8012DDA8(void*);
extern void fn_8012E498(void*);
extern void fn_801DCDA0(void);
extern void fn_801DCDA4(void);
extern u8 lbl_8055D3B4;
extern u8 lbl_8055D3B5;
extern char lbl_8034F4C8[];
extern void fn_8012E81C(void*);
extern void fn_80129324(s32);
extern void fn_80206518(void);
extern u32 lbl_8055D3B0;
extern u32 lbl_8055D3B8;
extern u8 lbl_802FBC7C[];
extern void loadTrackResources();
extern void musicPreRaceSetup(void*);
extern void fn_802103B8(void*);
void fn_8000A644(void* arg0, void* arg1) DECOMP_DONT_INLINE;
void fn_8000AADC(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AAE0(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AA38(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AA9C(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AABC(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AAE4(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AB48(void* arg0, s32 arg1);
void fn_8000ABE0(void* arg0);
u32 fn_8000AC38(void);

#pragma push
#pragma processor 750
/* Deleting-destructor style helper: clears three 32-bit fields and optionally frees the object. */
void* fn_80009D70(void* object, s32 shouldDelete) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma use_lmw_stmw off
extern char lbl_80558A08[0x40];
extern char lbl_80558A10[0x20];
#pragma opt_lifetimes off
void fn_80009DC8(void *arg0) {
    ListEntry_80009DC8 *list = (ListEntry_80009DC8 *)((u8 *)arg0 + 0x20);
    s32 *countp = (s32 *)((u8 *)arg0 + 0x3E0);
    s32 count = *countp;
    f32 zero = lbl_805601F0;
    ListEntry_80009DC8 *p = list;
    s32 i;
    for (i = 0; i < count; i++, p++) {
        char *a = fn_80016474(p->key);
        char *b = fn_80016544(p->key2);
        s32 f74;
        s32 n;
        p->bits.raw = 0;
        f74 = *(s32 *)(b + 0xA4);
        p->f74 = f74;
        p->f64 = zero;
        CopyStr_80009DC8(p->label, b + 0x2C, 0x20);
        p->kind = 0x51;
        for (n = 0; n < fn_80137C74(); n++) {
            if (fn_80016804(p->key, n) != 0) {
                p->kind = 0x50;
                p->bits.raw = (p->bits.raw & 0xFC) | (n & 3);
            }
        }
        CopyStr_80009DC8(p->name, a + 8, 0x40);
    }
    if (*(u32 *)((u8 *)arg0 + 0x3E8) & 0x1000) {
        s32 k = *countp / 2;
        ListEntry_80009DC8 *q = list + k;
        for (; k < *countp; k++, q++) q->kind = 0x54;
    }
    if (*(u32 *)((u8 *)arg0 + 0x3E8) & 0x400) {
        ListEntry_80009DC8 tmp;
        volatile int wide[86];
        u8 n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
        s32 j, kind;
        tmp.kind = 0x54;
        CopyStr_80009DC8(tmp.name, lbl_80558A08, 0x40);
        CopyStr_80009DC8(tmp.label, lbl_80558A10, 0x20);
        tmp.key = -0x1F;
        tmp.key2 = -0x1F;
        tmp.bits.raw = 0;
        tmp.f74 = 0;
        kind = tmp.kind;
        n0=tmp.name[0]; n1=tmp.name[1]; n2=tmp.name[2]; n3=tmp.name[3];
        n4=tmp.name[4]; n5=tmp.name[5]; n6=tmp.name[6]; n7=tmp.name[7];
        n8=tmp.name[8]; n9=tmp.name[9]; n10=tmp.name[10]; n11=tmp.name[11];
        wide[0]=((u8*)&tmp)[0x10]; wide[1]=((u8*)&tmp)[0x11]; wide[2]=((u8*)&tmp)[0x12]; wide[3]=((u8*)&tmp)[0x13];
        wide[4]=((u8*)&tmp)[0x14]; wide[5]=((u8*)&tmp)[0x15]; wide[6]=((u8*)&tmp)[0x16]; wide[7]=((u8*)&tmp)[0x17];
        wide[8]=((u8*)&tmp)[0x18]; wide[9]=((u8*)&tmp)[0x19]; wide[10]=((u8*)&tmp)[0x1a]; wide[11]=((u8*)&tmp)[0x1b];
        wide[12]=((u8*)&tmp)[0x1c]; wide[13]=((u8*)&tmp)[0x1d]; wide[14]=((u8*)&tmp)[0x1e]; wide[15]=((u8*)&tmp)[0x1f];
        wide[16]=((u8*)&tmp)[0x20]; wide[17]=((u8*)&tmp)[0x21]; wide[18]=((u8*)&tmp)[0x22]; wide[19]=((u8*)&tmp)[0x23];
        wide[20]=((u8*)&tmp)[0x24]; wide[21]=((u8*)&tmp)[0x25]; wide[22]=((u8*)&tmp)[0x26]; wide[23]=((u8*)&tmp)[0x27];
        wide[24]=((u8*)&tmp)[0x28]; wide[25]=((u8*)&tmp)[0x29]; wide[26]=((u8*)&tmp)[0x2a]; wide[27]=((u8*)&tmp)[0x2b];
        wide[28]=((u8*)&tmp)[0x2c]; wide[29]=((u8*)&tmp)[0x2d]; wide[30]=((u8*)&tmp)[0x2e]; wide[31]=((u8*)&tmp)[0x2f];
        wide[32]=((u8*)&tmp)[0x30]; wide[33]=((u8*)&tmp)[0x31]; wide[34]=((u8*)&tmp)[0x32]; wide[35]=((u8*)&tmp)[0x33];
        wide[36]=((u8*)&tmp)[0x34]; wide[37]=((u8*)&tmp)[0x35]; wide[38]=((u8*)&tmp)[0x36]; wide[39]=((u8*)&tmp)[0x37];
        wide[40]=((u8*)&tmp)[0x38]; wide[41]=((u8*)&tmp)[0x39]; wide[42]=((u8*)&tmp)[0x3a]; wide[43]=((u8*)&tmp)[0x3b];
        wide[44]=((u8*)&tmp)[0x3c]; wide[45]=((u8*)&tmp)[0x3d]; wide[46]=((u8*)&tmp)[0x3e]; wide[47]=((u8*)&tmp)[0x3f];
        wide[48]=((u8*)&tmp)[0x40]; wide[49]=((u8*)&tmp)[0x41]; wide[50]=((u8*)&tmp)[0x42]; wide[51]=((u8*)&tmp)[0x43];
        wide[52]=((u8*)&tmp)[0x44]; wide[53]=((u8*)&tmp)[0x45]; wide[54]=((u8*)&tmp)[0x46]; wide[55]=((u8*)&tmp)[0x47];
        wide[56]=((u8*)&tmp)[0x48]; wide[57]=((u8*)&tmp)[0x49]; wide[58]=((u8*)&tmp)[0x4a]; wide[59]=((u8*)&tmp)[0x4b];
        wide[60]=((u8*)&tmp)[0x4c]; wide[61]=((u8*)&tmp)[0x4d]; wide[62]=((u8*)&tmp)[0x4e]; wide[63]=((u8*)&tmp)[0x4f];
        wide[64]=((u8*)&tmp)[0x50]; wide[65]=((u8*)&tmp)[0x51]; wide[66]=((u8*)&tmp)[0x52]; wide[67]=((u8*)&tmp)[0x53];
        wide[68]=((u8*)&tmp)[0x54]; wide[69]=((u8*)&tmp)[0x55]; wide[70]=((u8*)&tmp)[0x56]; wide[71]=((u8*)&tmp)[0x57];
        wide[72]=((u8*)&tmp)[0x58]; wide[73]=((u8*)&tmp)[0x59]; wide[74]=((u8*)&tmp)[0x5a]; wide[75]=((u8*)&tmp)[0x5b];
        wide[76]=((u8*)&tmp)[0x5c]; wide[77]=((u8*)&tmp)[0x5d]; wide[78]=((u8*)&tmp)[0x5e]; wide[79]=((u8*)&tmp)[0x5f];
        wide[80]=((u8*)&tmp)[0x60]; wide[81]=((u8*)&tmp)[0x61]; wide[82]=((u8*)&tmp)[0x62]; wide[83]=((u8*)&tmp)[0x63];
        wide[84]=*(s32 *)&tmp.f64;
        wide[85]=0;
        for (j = 0; j < count; j++) {
            ListEntry_80009DC8 *e = list + (*countp)++;
            s32 r = fn_8001675C(1, j)[1];
            e->kind = kind;
            e->name[0]=n0; e->name[1]=n1; e->name[2]=n2; e->name[3]=n3;
            e->name[4]=n4; e->name[5]=n5; e->name[6]=n6; e->name[7]=n7;
            e->name[8]=n8; e->name[9]=n9; e->name[10]=n10; e->name[11]=n11;
            ((u8*)e)[0x10]=wide[0]; ((u8*)e)[0x11]=wide[1]; ((u8*)e)[0x12]=wide[2]; ((u8*)e)[0x13]=wide[3];
            ((u8*)e)[0x14]=wide[4]; ((u8*)e)[0x15]=wide[5]; ((u8*)e)[0x16]=wide[6]; ((u8*)e)[0x17]=wide[7];
            ((u8*)e)[0x18]=wide[8]; ((u8*)e)[0x19]=wide[9]; ((u8*)e)[0x1a]=wide[10]; ((u8*)e)[0x1b]=wide[11];
            ((u8*)e)[0x1c]=wide[12]; ((u8*)e)[0x1d]=wide[13]; ((u8*)e)[0x1e]=wide[14]; ((u8*)e)[0x1f]=wide[15];
            ((u8*)e)[0x20]=wide[16]; ((u8*)e)[0x21]=wide[17]; ((u8*)e)[0x22]=wide[18]; ((u8*)e)[0x23]=wide[19];
            ((u8*)e)[0x24]=wide[20]; ((u8*)e)[0x25]=wide[21]; ((u8*)e)[0x26]=wide[22]; ((u8*)e)[0x27]=wide[23];
            ((u8*)e)[0x28]=wide[24]; ((u8*)e)[0x29]=wide[25]; ((u8*)e)[0x2a]=wide[26]; ((u8*)e)[0x2b]=wide[27];
            ((u8*)e)[0x2c]=wide[28]; ((u8*)e)[0x2d]=wide[29]; ((u8*)e)[0x2e]=wide[30]; ((u8*)e)[0x2f]=wide[31];
            ((u8*)e)[0x30]=wide[32]; ((u8*)e)[0x31]=wide[33]; ((u8*)e)[0x32]=wide[34]; ((u8*)e)[0x33]=wide[35];
            ((u8*)e)[0x34]=wide[36]; ((u8*)e)[0x35]=wide[37]; ((u8*)e)[0x36]=wide[38]; ((u8*)e)[0x37]=wide[39];
            ((u8*)e)[0x38]=wide[40]; ((u8*)e)[0x39]=wide[41]; ((u8*)e)[0x3a]=wide[42]; ((u8*)e)[0x3b]=wide[43];
            ((u8*)e)[0x3c]=wide[44]; ((u8*)e)[0x3d]=wide[45]; ((u8*)e)[0x3e]=wide[46]; ((u8*)e)[0x3f]=wide[47];
            ((u8*)e)[0x40]=wide[48]; ((u8*)e)[0x41]=wide[49]; ((u8*)e)[0x42]=wide[50]; ((u8*)e)[0x43]=wide[51];
            ((u8*)e)[0x44]=wide[52]; ((u8*)e)[0x45]=wide[53]; ((u8*)e)[0x46]=wide[54]; ((u8*)e)[0x47]=wide[55];
            ((u8*)e)[0x48]=wide[56]; ((u8*)e)[0x49]=wide[57]; ((u8*)e)[0x4a]=wide[58]; ((u8*)e)[0x4b]=wide[59];
            ((u8*)e)[0x4c]=wide[60]; ((u8*)e)[0x4d]=wide[61]; ((u8*)e)[0x4e]=wide[62]; ((u8*)e)[0x4f]=wide[63];
            ((u8*)e)[0x50]=wide[64]; ((u8*)e)[0x51]=wide[65]; ((u8*)e)[0x52]=wide[66]; ((u8*)e)[0x53]=wide[67];
            ((u8*)e)[0x54]=wide[68]; ((u8*)e)[0x55]=wide[69]; ((u8*)e)[0x56]=wide[70]; ((u8*)e)[0x57]=wide[71];
            ((u8*)e)[0x58]=wide[72]; ((u8*)e)[0x59]=wide[73]; ((u8*)e)[0x5a]=wide[74]; ((u8*)e)[0x5b]=wide[75];
            ((u8*)e)[0x5c]=wide[76]; ((u8*)e)[0x5d]=wide[77]; ((u8*)e)[0x5e]=wide[78]; ((u8*)e)[0x5f]=wide[79];
            ((u8*)e)[0x60]=wide[80]; ((u8*)e)[0x61]=wide[81]; ((u8*)e)[0x62]=wide[82]; ((u8*)e)[0x63]=wide[83];
            *(s32 *)((u8 *)e + 0x64) = wide[84];
            e->key = -0x1F;
            ((u8 *)e)[0x70] = wide[85];
            e->f74 = 0;
            e->key2 = r;
            CopyStr_80009DC8(e->label, fn_80016544(r) + 0x2C, 0x20);
        }
    }
}

#pragma push
#pragma processor 750
#pragma pop

#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Copy key pairs from data into the list's 0x78-byte entries at owner+0x20, take the entry count from data+0x24, then finalize the list. */
void fn_8000A644(void* owner, void* data) {
    s32 key2;
    s32 key;
    s32* dst;
    s32* base;
    s32 count;
    u8* src = (u8*)data;
    base = (s32*)((u8*)owner + 0x20);
    dst = base;
    count = 0;
    ((s32*)owner)[0x3E0 / 4] = *(s32*)(src + 0x24);
    while (count < base[0x3C0 / 4]) {
        key = *(s32*)(src + 4);
        key2 = *(s32*)(src + 0x28);
        src += 4;
        dst[0x68 / 4] = key;
        dst[0x6C / 4] = key2;
        dst += 0x78 / 4;
        count++;
    }
    fn_80009DC8(owner);
}
#pragma push
#pragma scheduling invalid_target
/* RealName: FormatCarPathAndCallback */
/* Build a ".car" path from an index into a temp buffer, then pass it to a callback. */
void fn_8000A688(void (*callback)(void *), s32 carIndex) DECOMP_DONT_INLINE {
#define sCarPathFmt lbl_80558A14 /* "%s.car" */
    char pathBuffer[0x20];
    ((void (*)(void *, s32, void *, s32, ...))fn_801345D8)(pathBuffer, 0x20, &sCarPathFmt, carIndex);
    callback(pathBuffer);
#undef sCarPathFmt
}
#pragma pop
extern void *fn_80131810(const char *);
extern void releaseValueFile(void *);
extern void Abend_Panic(const char *, ...);
extern int stricmp(const char *, const char *);
extern char lbl_802FBC08[];
extern char lbl_802FBC18[];
extern int lbl_80558A20;
extern int lbl_80558A28;
extern int lbl_80558A30;
#pragma cplusplus on
extern "C" void *fn_80131810(const char *);
extern "C" void releaseValueFile(void *);
extern "C" void Abend_Panic(const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" char lbl_802FBC08[];
extern "C" char lbl_802FBC18[];
extern "C" int lbl_80558A20;
extern "C" int lbl_80558A28;
extern "C" int lbl_80558A30;
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8000A6D8(void) {
    /* Warns if the active weather differs from the weather specified in weather.val. */
    class ManagerView {
    public:
        virtual void unused0() = 0;
        virtual void unused1() = 0;
        virtual void unused2() = 0;
        virtual const char *getName(const char *) = 0;
    };
    class ResourceView {
    public:
        virtual void *getItem(const char *) = 0;
        virtual void unused1() = 0;
        virtual void unused2() = 0;
        virtual const char *getName(const char *) = 0;
    };
    const char *contestWeather;
    const char *resourceWeather;
    void *resource;
    void *manager;
    void *item;
    manager = *(void **)((u8 *)(void *)lbl_8055D3B8 + 0x20);
    contestWeather = ((ManagerView *)manager)->getName((const char *)&lbl_80558A20);
    resourceWeather = (const char *)&lbl_80558A28;
    resource = fn_80131810(lbl_802FBC08);
    if (resource != 0) {
        item = ((ResourceView *)resource)->getItem((const char *)&lbl_80558A20);
        resourceWeather = ((ResourceView *)item)->getName((const char *)&lbl_80558A30);
        releaseValueFile(resource);
    }
    if (stricmp(resourceWeather, contestWeather) != 0) {
        Abend_Panic(lbl_802FBC18, contestWeather, resourceWeather);
    }
}
#pragma pop
#pragma cplusplus reset

void fn_8000AADC(void* arg0) {
    /* Tail-call thunk: queue this session's track effect resource sets for loading via fn_8000A7A8. */
    fn_8000A7A8();
}

void fn_8000AAE0(void* arg0) {
    /* Tail-call thunk: leave the track, releasing the effect sets that fn_8000AADC's
     * load pass queued (fn_8000A808 does the work; the object pointer is unused). */
    fn_8000A808();
}

#pragma push
#pragma scheduling invalid_target
/* Call fn_8000AABC for each 0x78-byte entry in the container (count at +0x3E0). */
void fn_8000AAE4(void* arg0) {
    s8* p = (s8*)arg0 + 0x64;
    s32 i;
    for (i = 0; i < ((s32*)arg0)[0x3E0 / 4]; i++) {
        fn_8000AABC(p);
        p += 0x78;
    }
}
#pragma pop
void fn_8000AB44(void) {
    /* Tail-call thunk: run the track's weather consistency check (fn_8000A6D8),
     * which warns when the active weather differs from the one in weather.val. */
    fn_8000A6D8();
}

#pragma push
#pragma scheduling invalid_target
void fn_8000AB48(void* arg0, s32 arg1) {
    /* Sets up per-entry UI/resource state from arg1, runs per-slot init callbacks, then loads overlays and initializes pre-race/track music for arg0. */
    char* p;
    s32 i;
    loadTrackResources();
    fn_8000AADC(arg0);
    fn_8000A644(arg0, (void*)arg1);
    p = (char*)arg0 + 0x64;
    for (i = 0; i < ((s32*)arg0)[0x3E0 / 4]; i++) {
        fn_8000AA9C(p);
        p += 0x78;
    }
    fn_8012DDA8(&lbl_802FBC7C);
    musicPreRaceSetup(arg0);
    fn_802103B8(arg0);
}
#pragma pop
void fn_8000ABE0(void *object) {
    /* Unload the overlays resource and tear down the object's state. */
#define sOverlaysResource lbl_802FBC7C

    fn_8012E498(&sOverlaysResource);
    fn_8000AAE4(object);
    fn_8000AAE0(object);
    fn_8000AA38(object);

#undef sOverlaysResource
}

extern u8 lbl_8034F520[];
/* Returns the game's AX studio state block: a 0x80-byte .bss buffer holding
 * the mixer/studio state that the AX sound library updates each frame. */
void *__AXGetStudio_8000AC2C(void) {
#define sAxStudio lbl_8034F520 /* 0x80-byte AX studio state block */
    return sAxStudio;
#undef sAxStudio
}

/* Return the global root object pointer; callers read the manager pointer at +0x20 of it. */
u32 fn_8000AC38(void) {
#define sGlobalRoot lbl_8055D3B8
    return sGlobalRoot;
#undef sGlobalRoot
}

// Enters a track: queues the track effect sets whose names loadTrackResources built in
// the block at lbl_8034F4C8 (+0x18 always, +0x58 while lbl_8055D3B4, +0x98 while
// lbl_8055D3B5); fn_8012DDA8 loads one by name.  fn_801DCDA0 is an empty stub.
void fn_8000A7A8(void) {
    char* base = (char*)&lbl_8034F4C8;
    if (lbl_8055D3B4 != 0) {
        fn_8012DDA8(base + 0x58);
    }
    fn_8012DDA8(base + 0x18);
    if (lbl_8055D3B5 != 0) {
        fn_8012DDA8(base + 0x98);
    }
    fn_801DCDA0();
}

// Leaves a track: shuts the ground down and releases the three track effect
// sets whose names loadTrackResources built in the block at lbl_8034F4C8.
void fn_8000A808(void) {
    /* fn_801DCDA4 frees the ground heightmap block lbl_80446F08 and clears the
     * ground update callback; fn_8012E498 releases one effect set by name and
     * frees its resource once nothing uses it any more. */
    typedef struct TrackEffectNames {
        char unused_00[0x18];
        char trackName[0x40];    /* 0x18 "%s.trk" of the track name */
        char resourceName[0x40]; /* 0x58 "%s_%s.trk", set while lbl_8055D3B4 */
        char weatherName[0x40];  /* 0x98 "%s_%s.trk", set while lbl_8055D3B5 */
    } TrackEffectNames;
    TrackEffectNames* names = (TrackEffectNames*)&lbl_8034F4C8;

    fn_801DCDA4();
    fn_8012E498(names->trackName);
    if (lbl_8055D3B4 != 0) {
        fn_8012E498(names->resourceName);
    }
    if (lbl_8055D3B5 != 0) {
        fn_8012E498(names->weatherName);
    }
}

void fn_8000A868(void) {
    /* Wait until the track effect sets whose names are stored in lbl_8034F4C8 (+0x18 always, +0x58 when lbl_8055D3B4, +0x98 when lbl_8055D3B5) have finished loading. */
    typedef struct TrackEffectNames {
        char unused_00[0x18];
        char trackName[0x40];    /* 0x18 */
        char resourceName[0x40]; /* 0x58 */
        char weatherName[0x40];  /* 0x98 */
    } TrackEffectNames;
    TrackEffectNames* names = (TrackEffectNames*)&lbl_8034F4C8;

    fn_8012E81C(names->trackName);
    if (lbl_8055D3B4 != 0) {
        fn_8012E81C(names->resourceName);
    }
    if (lbl_8055D3B5 != 0) {
        fn_8012E81C(names->weatherName);
    }
}

#pragma push
#pragma scheduling invalid_target
void loadTrackResources(void* arg0) {
    /* Load/setup track-related resources for arg0: build paths/names, query resource
     * items and weather name, set flags/strings, init subsystems, and cache "speech" id. */
    extern void fn_802E3D00(void);
    extern void* fn_8001285C(void*);
    extern void fn_800124DC(void*, s32, s32, f32);
    extern void fn_800125C4(void);
    extern void fn_80206484(void*);
    extern s32 fn_801292CC(const char*);
    extern f32 lbl_805601F4;
    extern u8 lbl_80558A34;
    extern u8 lbl_80558A3C;

    char* base = lbl_8034F4C8;
    char* db = lbl_802FBC08;
    void* resource;
    void* object;
    void* item;
    char* originalName;
    s32 compareResult;
    u32 differs;

    fn_802E3D00();
    ((void (*)(void*, s32, void*, ...))fn_801345D8)(base + 0x18, 0x40, &lbl_80558A34, arg0);
    resource = fn_8001285C(*(void**)((u8*)arg0 + 0x3E4));
    lbl_8055D3B8 = (u32)resource;
    object = *(void**)((u8*)resource + 0x20);
#pragma cplusplus on
    struct ResourceView {
        virtual void unused0();
        virtual void unused1();
        virtual void unused2();
        virtual void unused3();
        virtual void* getItem(const char*, s32);
    };
    item = ((ResourceView*)object)->getItem(db + 0x40, 0);
#pragma cplusplus reset
    if (item != 0) {
        lbl_8055D3B4 = 1;
        ((void (*)(void*, s32, void*, ...))fn_801345D8)(base + 0x58, 0x40, db + 0x4C, arg0, (s32)item);
    } else {
        lbl_8055D3B4 = 0;
        ((void (*)(void*, s32, void*, ...))fn_801345D8)(base + 0x58, 0x40, &lbl_80558A34, arg0);
    }
    object = *(void**)((u8*)lbl_8055D3B8 + 0x20);
#pragma cplusplus on
    struct ManagerView {
        virtual void unused0();
        virtual void unused1();
        virtual void unused2();
        virtual const char* getName(const char*);
    };
    originalName = (char*)((ManagerView*)object)->getName((const char*)&lbl_80558A20);
#pragma cplusplus reset
    compareResult = stricmp(originalName, (const char*)&lbl_80558A28);
    differs = (u32)(-compareResult | compareResult) >> 31;
    lbl_8055D3B5 = (u8)differs;
    if (differs != 0) {
        ((void (*)(void*, s32, void*, ...))fn_801345D8)(base + 0x98, 0x40, db + 0x4C, arg0, (s32)originalName);
    } else {
        base[0x98] = 0;
    }
    fn_800124DC(db + 0x58, 1, 1, lbl_805601F4);
    fn_80206484(db + 0x68);
    lbl_8055D3B0 = (u32)fn_801292CC((const char*)&lbl_80558A3C);
    fn_800125C4();
}
#pragma pop

void fn_8000AA38(void* arg0) {
    /* Release and clear the sound/UI state block and its three string slots. */
    char* base = (char*)&lbl_8034F4C8;
    fn_80129324(lbl_8055D3B0);
    lbl_8055D3B0 = 0;
    fn_80206518();
    fn_8020CA38();
    lbl_8055D3B8 = 0;
    lbl_8055D3B4 = 0;
    lbl_8055D3B5 = 0;
    base[0x18] = 0;
    base[0x98] = 0;
    base[0x58] = 0;
}

void fn_8000AA9C(void* carName) {
    /* If carName is a non-empty car-name string, load the effect set named by
     * it with ".car" appended (the load twin of fn_8000AABC). */
    s8 firstChar = ((u8*)carName)[0];
    if (firstChar == 0) {
        return;
    }
    fn_8000A688(fn_8012DDA8, (s32)carName);
}

/* If carName is a non-empty car-name string, release the effect loaded under
 * that name with ".car" appended (the unload twin of fn_8000AA9C). */
void fn_8000AABC(void* carName) {
    s8 firstChar = ((u8*)carName)[0];
    if (firstChar == 0) {
        return;
    }
    fn_8000A688((void (*)(void*))fn_8012E498, (s32)carName);
}

