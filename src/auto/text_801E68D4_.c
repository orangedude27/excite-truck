// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef signed char s8;
typedef long s32;

/* Drop a reference to a loaded resource (forwards to Resource_Release). */
void fn_801E6CC4(void) {
    Resource_Release();
}

extern void fn_801E6924(s32);
extern void fn_801E598C(s32);
extern void fn_802C6CF8(s32);
extern void fn_80128668(s32);
extern void fn_8012ED20(s32);
extern s32 fn_8012EC90(s32);
/* The anim streaming-buffer pool: the 8 buffers of 0x4000 bytes fn_801E6978 asks
 * the allocator for, and the in-use flag of each (0 free, 1 taken).  fn_801E68D4
 * hands out the next free one and fn_801E6924 gives one back. */
extern s8 lbl_8055EAC8[8];
extern s32 lbl_80487CC0[8];

extern s32 fn_801E5E24(s32, void*, s32, void*);
extern void fn_801BFD34(void*, void*, s32);
extern void fn_80015B20(void*, void*, s32);
extern void fn_802C70AC(s32, void*, s32, s32);
extern void Abend_Panic(const char*, ...);
extern char lbl_80339A20[]; /* "anim: release_buffer: unknown buffer %p" */
#pragma scheduling invalid_target
/* RealName: AnimBufferPool_Acquire — return the next free anim streaming buffer, or 0 if all 8 slots are in use. */
s32 fn_801E68D4(void) {
#define sAnimBufferInUse lbl_8055EAC8
#define sAnimBufferPool  lbl_80487CC0
    s32 i;
    s32 buffer;
    u8 *inUsePtr;

    for (i = 0, inUsePtr = (u8 *)sAnimBufferInUse; i < 8; ++inUsePtr, ++i) {
        if (*inUsePtr == 0) {
            buffer = sAnimBufferPool[i];
            sAnimBufferInUse[i] = 1;
#undef sAnimBufferInUse
#undef sAnimBufferPool
            return buffer;
        }
    }
#undef sAnimBufferInUse
#undef sAnimBufferPool
    return 0;
}
#pragma scheduling invalid_target
/* Give a streaming buffer back to the anim buffer pool: clears the in-use flag of
 * the slot holding `buffer`, and reports "anim: release_buffer: unknown buffer %p"
 * (lbl_80339A20) when no slot holds it.  fn_801E68D4 takes the next free slot;
 * fn_801E6B98 releases the one an animation player was streaming into. */
void fn_801E6924(s32 buffer) {
    s32* slot = lbl_80487CC0;
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((unsigned int)*slot == (unsigned int)buffer) {
            lbl_8055EAC8[i] = 0;
            return;
        }
        slot++;
    }
    Abend_Panic(&lbl_80339A20[0], buffer);
}
#pragma scheduling reset

extern char lbl_80339A20[0x40];
/* Allocate 8 resource buffers (0x4000 bytes each) into lbl_80487CC0 and clear
 * their corresponding in-use flags in lbl_8055EAC8. */
void fn_801E6978(void) {
    volatile s32 *bufferSlot = lbl_80487CC0;
    volatile s8 *inUseFlag = lbl_8055EAC8;
    s32 index = 0;

    do {
        *bufferSlot = fn_8012EC90(0x4000);
        index += 1;
        *inUseFlag = 0;
        bufferSlot += 1;
        inUseFlag += 1;
    } while (index < 8);
}

#pragma scheduling invalid_target
void fn_801E69EC(void) {
    /* Free every buffer in the anim streaming-buffer pool. */
#define sAnimBufferPool lbl_80487CC0
    s32* var_r31 = sAnimBufferPool;
    s32 var_r30 = 0;
    do {
        fn_8012ED20(*var_r31);
        var_r30 += 1;
        var_r31 += 1;
    } while (var_r30 < 8);
#undef sAnimBufferPool
}
extern s32 *fn_801E592C(void);
extern s32 fn_801E5990(void *);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void *fn_801284F8(s32, const char *);
extern void *memset(void *, int, unsigned long);
extern const char lbl_80339A48[];
extern char lbl_8055AEF8;
extern float lbl_80562D78;
extern float lbl_80562D7C;
#pragma scheduling on
void *fn_801E6A3C(s32 arg0, s32 arg1, s32 arg2) {
    void *result;
    s32 handle;
    s32 *entry;
    float *dst;
    float *src;
    u8 *base;
    s32 i;
    float zero;
    float one;
    float initial;

    result = (void *)arg0;
    handle = fn_802C6FC0(arg0, arg2, 0);
    entry = fn_801E592C();
    if (entry == 0) {
        ((void (*)(const char *, ...))Abend_Panic)(lbl_80339A48, result, (void *)handle);
    }
    result = fn_801284F8(0x73C, (const char *)&lbl_8055AEF8);
    memset(result, 0, 0x73C);
    *(s32 *)((u8 *)result + 8) = fn_801E5990(entry);
    initial = 0.0f;
    *(s32 **)((u8 *)result + 4) = entry;
    *(s32 *)result = handle;
    *(float *)((u8 *)result + 0x38) = initial;
    *(s32 *)((u8 *)result + 0x10) = 0;
    *(s32 *)((u8 *)result + 0x18) = 0;
    *(s32 *)((u8 *)result + 0x1C) = -1;
    *((u8 *)result + 0xD) = 0;
    if (arg1 == 1) {
        *((u8 *)result + 0xD) = 1;
    }
    one = 0.0f;
    *(s32 *)((u8 *)result + 0x14) = 0;
    base = (u8 *)result;
    zero = 1.0f;
    dst = (float *)(base + 0x3C);
    *((u8 *)result + 0xC) = 0;
    src = (float *)(base + 0x53C);
    i = 0;
    while (i < *(s32 *)((u8 *)result + 8) + 1) {
        dst[0] = one;
        i++;
        dst[1] = one;
        dst[2] = one;
        dst[3] = zero;
        dst[4] = one;
        dst[5] = one;
        dst[6] = one;
        dst[7] = zero;
        dst[9] = one;
        dst[8] = one;
        dst += 10;
        src[0] = one;
        src[1] = one;
        src[2] = one;
        src += 4;
        *(float *)(base + 0x548) = zero;
        base += 0x10;
    }
    return result;
}
/* Free an animation player object (the 0x73C-byte AnimPlayer fn_801E6A3C builds):
 * hand its streaming buffer slot back to the 8-slot pool, release its resource
 * entry and model handle, then return the object's memory to the allocator. */
void fn_801E6B98(void* object) {
    /* Head of the animation player object built by fn_801E6A3C; the file's
       AnimPlayer typedef (further down) describes the whole 0x73C bytes. */
    struct AnimPlayerHead {
        s32 handle;     /* 0x00 model handle */
        void* res;      /* 0x04 MRBN resource entry */
        s32 trackCount; /* 0x08 */
        u8 flagC;       /* 0x0C */
        u8 flagD;       /* 0x0D */
        u8 padE[2];
        void* data;     /* 0x10 animation data */
        s32 stream;     /* 0x14 streaming buffer slot */
    };
    struct AnimPlayerHead* player = (struct AnimPlayerHead*)object;
    s32 stream = player->stream;
    if (stream != 0) {
        /* the cast keeps -ipa file from inlining this call */
        ((void (*)(s32))fn_801E6924)(stream);
    }
    fn_801E598C((s32)player->res);
    fn_802C6CF8(player->handle);
    fn_80128668((s32)object);
}

extern void *fn_8012C370(const char *, unsigned int, int *, int *, unsigned char *, unsigned char *);
extern char *strcpy(char *, const char *);
extern char *fn_80029004(const char *, int);
extern void fn_80028E00(char *, const char *);
extern const char lbl_80339A64[];
extern const char lbl_80339A78[];
extern char lbl_8055AF00;
void *fn_801E6BEC(char *arg0) {
    /* Load an animation resource by path, validate its version, and derive its base name with ".an0". */
    struct {
        unsigned char swapEndian;
        unsigned char isNew;
        unsigned char pad[2];
        int version;
        int dataSize;
    } loadInfo;
    char *path = arg0;
    char *animData;

    loadInfo.dataSize = 0;
    loadInfo.isNew = 0;
    loadInfo.swapEndian = 0;
    animData = (char *)fn_8012C370(path, 0x416e696d, &loadInfo.version, &loadInfo.dataSize, &loadInfo.isNew, &loadInfo.swapEndian);
    if (animData == 0)
        Abend_Panic(lbl_80339A64, path);
    if ((unsigned int)loadInfo.version != 2)
        Abend_Panic(lbl_80339A78, path, loadInfo.version, 2);
    strcpy(animData + 0x10, path);
    {
        char *dot = fn_80029004(animData + 0x10, 0x2e);
        if (dot != 0)
            *dot = 0;
    }
    fn_80028E00(animData + 0x10, &lbl_8055AF00);
    return animData;
}

/* Set the byte-sized flag at offset 0xC of an animation-data object (whose name string starts at +0x10). */
void fn_801E6CC8(void* animData, s8 value) {
    ((s8*)animData)[0xC] = value;
}

typedef unsigned int u32;
extern int fn_8012EDA8(void *, int, u32 *);
extern void Abend_Panic(const char *, ...);
typedef unsigned long long u64;
typedef struct AnimTrack {
    float a[4];
    float b[4];
    float t0;
    float t1;
} AnimTrack;
typedef struct AnimKey {
    s32 n;
    float t;
    float v[4];
} AnimKey;
typedef struct AnimData {
    s32 count;
    s32 inlineCount;
    s32 trackCount;
    float endTime;
    char name[16];
    u64 keys[1];
} AnimData;
typedef struct AnimPlayer {
    s32 handle;
    void *res;
    s32 trackCount;
    u8 flagC;
    u8 flagD;
    u8 padE[2];
    AnimData *data;
    s32 stream;
    s32 frame;
    s32 cached;
    AnimKey cache;
    float time;
    AnimTrack tr[32];
    float out[32][4];
} AnimPlayer;

extern float lbl_80562D80;
extern float lbl_80562D84;
extern float lbl_80562D88;
extern float lbl_80562D8C;
extern float lbl_80562D90;
extern float lbl_80562D94;
extern s32 lbl_8055EAD0;
extern char lbl_80339B48[];
extern void fn_8012EE80(s32);
extern s32 fn_8012EE78(s32);
extern s32 fn_8012EFB0(s32, void *, s32);
extern void fn_802E30C8(const char *, ...);
extern double fn_8002F234(double);

#define NORM(v) (((float)(u32)(v) - lbl_80562D78) / lbl_80562D80)
#define CLAMP(v) \
    t = (lbl_80562D7C < NORM(v)) ? lbl_80562D7C : NORM(v); \
    t = (t > lbl_80562D78) ? t : lbl_80562D78;

#define NORMC(v) (((float)(u32)(v) - cZero) / cDiv)
#define CLAMPC(v) \
    t = (cOne < NORMC(v)) ? cOne : NORMC(v); \
    t = (t > cZero) ? t : cZero;

#pragma dont_inline on
#pragma push
#pragma processor 750
void fn_801E6CD0(void *arg0, void *arg1, float farg0) {
    float *dst;
    float *src;
    s32 i;
    double a, b, c, d;
    u32 sp8;
    const char *messages = lbl_80339A20;

    *(void **)((u8 *)arg0 + 0x10) = arg1;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = -1;
    *(float *)((u8 *)arg0 + 0x38) = -farg0;
    if (arg1 != 0 && *(s32 *)((u8 *)arg1 + 8) > *(s32 *)((u8 *)arg0 + 8))
        Abend_Panic(messages + 0x80);

    dst = (float *)((u8 *)arg0 + 0x3C);
    src = (float *)arg0;
    i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 8) + 1) {
        a = src[0x53C / 4];
        i++;
        dst[4] = a;
        b = src[0x540 / 4];
        dst[5] = b;
        c = src[0x544 / 4];
        dst[6] = c;
        d = src[0x548 / 4];
        src += 4;
        dst[7] = d;
        dst[0] = (float)a;
        dst[1] = (float)b;
        dst[2] = (float)c;
        dst[3] = (float)d;
        dst[9] = -farg0;
        dst[8] = -farg0;
        dst += 10;
    }

    if (arg1 != 0 && *(s32 *)arg1 > *(s32 *)((u8 *)arg1 + 4)) {
        if (*((u8 *)arg0 + 0xD) == 0)
            Abend_Panic(messages + 0xB8);
        if (*(s32 *)((u8 *)arg0 + 0x14) == 0)
            *(s32 *)((u8 *)arg0 + 0x14) = fn_801E68D4();
        if (*(s32 *)((u8 *)arg0 + 0x14) == 0) {
            *(void **)((u8 *)arg0 + 0x10) = 0;
            return;
        }
        if (fn_8012EDA8((u8 *)arg1 + 0x10, 0x416E6D30, &sp8) == 0)
            Abend_Panic(messages + 0x100, (u8 *)arg1 + 0x10);
        if (sp8 != 2) Abend_Panic(messages + 0x58, (u8 *)arg1 + 0x10, 2);
    } else if (*(s32 *)((u8 *)arg0 + 0x14) != 0) {
        fn_801E6924(*(s32 *)((u8 *)arg0 + 0x14));
        *(s32 *)((u8 *)arg0 + 0x14) = 0;
    }
}
#pragma pop

#pragma push
#pragma processor 750
void fn_801E6E9C(AnimPlayer *obj, float dt) {
    AnimData *data = obj->data;
    float cScale, cBase, cMul, cDiv, cTScale, cZero, cOne;
    float time = obj->time;
    float t;
    AnimKey key;
    struct {
        u32 hi;
        u32 lo;
    } raw;
    AnimTrack *e;
    s32 i;

    if (data != 0) {
        if (obj->stream != 0) {
            fn_8012EE80(obj->stream);
        }
        cOne = lbl_80562D7C;
        cZero = lbl_80562D78;
        cTScale = lbl_80562D84;
        cDiv = lbl_80562D80;
        cMul = lbl_80562D90;
        cBase = lbl_80562D88;
        cScale = lbl_80562D8C;
        while (obj->frame < data->count) {
            if (obj->cached != obj->frame) {
                if (obj->frame < data->inlineCount) {
                    u32 *src = (u32 *)&data->keys[obj->frame];
                    raw.lo = src[1];
                    raw.hi = src[0];
                } else if (fn_8012EFB0(obj->stream, &raw, 8) == 0) {
                    if (lbl_8055EAD0 == 0) {
                        fn_802E30C8(lbl_80339B48, obj->frame, fn_8012EE78(obj->stream));
                    }
                    lbl_8055EAD0 = lbl_8055EAD0 + 1;
                    if (lbl_8055EAD0 > 200) {
                        lbl_8055EAD0 = 0;
                    }
                    break;
                }
                key.n = (s32)(raw.lo & 0x3f) - 1;
                CLAMPC((((raw.lo >> 6) | (raw.hi << 26)) & 0x3ff) << 6);
                key.t = cZero + t * cTScale;
                if ((raw.lo & 0x3f) != 0) {
                    CLAMPC((((raw.lo >> 16) | (raw.hi << 16)) & 0xfff) << 4);
                    key.v[0] = cBase + t * cScale;
                    CLAMPC((((raw.lo >> 28) | (raw.hi << 4)) & 0xfff) << 4);
                    key.v[1] = cBase + t * cScale;
                    CLAMPC(((raw.hi >> 8) & 0xfff) << 4);
                    key.v[2] = cBase + t * cScale;
                    CLAMPC(((raw.hi >> 20) & 0xfff) << 4);
                    key.v[3] = cBase + t * cScale;
                } else {
                    CLAMPC(((raw.lo >> 16) | (raw.hi << 16)) & 0xffff);
                    key.v[0] = cMul * (cBase + t * cScale);
                    CLAMPC(raw.hi & 0xffff);
                    key.v[1] = cMul * (cBase + t * cScale);
                    CLAMPC(raw.hi >> 16);
                    key.v[2] = cMul * (cBase + t * cScale);
                }
                obj->cache = key;
                obj->cached = obj->frame;
            } else {
                key = obj->cache;
            }
            e = &obj->tr[key.n + 1];
            if (!(time >= e->t1)) {
                break;
            }
            e->a[0] = e->b[0];
            e->a[1] = e->b[1];
            e->a[2] = e->b[2];
            e->a[3] = e->b[3];
            e->b[0] = key.v[0];
            e->b[1] = key.v[1];
            e->b[2] = key.v[2];
            e->b[3] = key.v[3];
            e->t0 = e->t1;
            e->t1 = key.t + ((e->t1 > cZero) ? e->t1 : cZero);
            obj->frame++;
        }
        time = time + dt;
        obj->time = time;
        if (obj->flagC != 0 && obj->frame >= data->count && time >= data->endTime) {
            fn_801E6CD0(obj, data, lbl_80562D78);
        }
    }
    {
        float zero = lbl_80562D7C;
        float lo = lbl_80562D94;
        float zz = lbl_80562D78;
        for (i = 0; i < obj->trackCount + 1; i++) {
            AnimTrack *k = &obj->tr[i];
            float t0 = k->t0;
            float lim = k->t1 - lo;
            float s, r;
            t0 = (t0 < lim) ? t0 : lim;
            s = (time - t0) / (k->t1 - t0);
            if (zero < s) s = zero;
            if (!(s > zz)) s = zz;
            r = zero - s;
            if (i > 0) {
                float len;
                obj->out[i][0] = k->a[0] * r + k->b[0] * s;
                obj->out[i][1] = k->a[1] * r + k->b[1] * s;
                obj->out[i][2] = k->a[2] * r + k->b[2] * s;
                obj->out[i][3] = k->a[3] * r + k->b[3] * s;
                len = (float)fn_8002F234(obj->out[i][0] * obj->out[i][0] + (obj->out[i][1] * obj->out[i][1] + (obj->out[i][3] * obj->out[i][3] + obj->out[i][2] * obj->out[i][2])));
                len = zero / len;
                obj->out[i][0] *= len;
                obj->out[i][1] *= len;
                obj->out[i][2] *= len;
                obj->out[i][3] *= len;
            } else {
                obj->out[i][0] = k->a[0] * r + k->b[0] * s;
                obj->out[i][1] = k->a[1] * r + k->b[1] * s;
                obj->out[i][2] = k->a[2] * r + k->b[2] * s;
                obj->out[i][3] = zz;
            }
        }
    }
}
#pragma pop

/* Draws the model for an animation node by building its world transform and submitting it. */
void fn_801E75C8(void* node, s32 param) {
    u8 sp[0x5c];
    s32 temp_r31;

    temp_r31 = fn_801E5E24(*(s32*)((u8*)node + 4), (u8*)node + 0x53c,
                             *(s32*)((u8*)node + 8), sp + 0x30);
    fn_801BFD34(sp + 0x24, sp + 0x54, param);
    fn_80015B20(sp, sp + 0x30, param);
    fn_802C70AC(*(s32*)node, sp, temp_r31, -1);
}
#pragma scheduling reset
s32 fn_801E7650(void *arg0) {
#define mCurrentEntry ((u8 *)arg0 + 0x10)
#define mIndex ((u8 *)arg0 + 0x18)
#define mTime ((u8 *)arg0 + 0x38)
    /* Return non-zero when the current entry is valid and its index/time thresholds are reached. */
    s32 result;
    s32 *entry;
    entry = *(s32 **)mCurrentEntry;
    if (entry != 0) {
        result = 0;
        if (*(s32 *)mIndex >= entry[0] && *(float *)mTime >= *(float *)((u8 *)entry + 0xC)) {
            result = 1;
        }
        return result;
    }
    return 0;
#undef mCurrentEntry
#undef mIndex
#undef mTime
}

/* RealName: GetMaxTrackedObjects — returns the cap (8) used to clamp the
 * nearby-object counter lbl_8055EC64 in updateStageDistanceAnims. */
int fn_801E7698(void) {
    return 8;
}

