// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef float f32;
typedef int BOOL;
extern void fn_8023905C();
extern s32 fn_80128668(void);
extern s32 KERNEL_GetTimeMs(void);
extern void fn_80238FCC(u32, u32);
extern void *fn_8022EDC4(void);
extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
extern void fn_802C8B98(s32, s32, u16, u16, u16, u16, u16, u16);
extern void fn_802C8DB8(void *, s32, u16 *, s32);
extern void DrawList_RestoreNormalMode(void);
extern u16 lbl_802FA030[6];
extern u16 lbl_80563718;
extern u16 lbl_8056371A;
extern u16 lbl_8056371C;
extern f32 lbl_80563720;
extern f32 lbl_80563724;
extern f32 lbl_80563728;
extern f32 lbl_8056372C;
extern void *getResourceData(s32, s32, u32 *, s32 *, u8 *, u8 *);
extern void fn_802E30C8(const char *, ...);
extern void Abend_Panic(const char *, ...);
extern char lbl_80340AD0[];
extern char lbl_80340B00[];

#define SWF_DATA(obj) (*(u8 **)((u8 *)(obj) + 0x14))

#define SWAP32_FIELD(base, off) do { \
    ptr = (u8 *)(base); \
    temp2 = ptr[(off) + 0]; \
    ptr[(off) + 0] = ptr[(off) + 3]; \
    ptr[(off) + 3] = temp2; \
    temp2 = ptr[(off) + 1]; \
    ptr[(off) + 1] = ptr[(off) + 2]; \
    ptr[(off) + 2] = temp2; \
} while (0)

#define SWAP16_AT(ptr, off) do { \
    u8 _t; \
    u8 *_p = (u8 *)(ptr); \
    _t = _p[(off) + 0]; \
    _p[(off) + 0] = _p[(off) + 1]; \
    _p[(off) + 1] = _t; \
} while (0)

#define SWAP32_AT(ptr, off) do { \
    u8 _t; \
    u8 *_p = (u8 *)(ptr); \
    _t = _p[(off) + 0]; \
    _p[(off) + 0] = _p[(off) + 3]; \
    _p[(off) + 3] = _t; \
    _t = _p[(off) + 1]; \
    _p[(off) + 1] = _p[(off) + 2]; \
    _p[(off) + 2] = _t; \
} while (0)
static inline s32 clampLow_80238BF4(s32 v) {
    if (v > 0) return v;
    return 0;
}
static inline s32 clampHigh_80238BF4(s32 v) {
    if (v < 0xFF) return v;
    return 0xFF;
}
#pragma scheduling invalid_target
void fn_80238BF4(void *arg0, u8 *arg1) {
    struct LocalFrame {
        u16 indices3[3];
        u8 pad06[2];
        u16 indices6[6];
        u8 pad14[4];
        volatile f32 points[12];
        u8 pad48[8];
        f32 outputs[24];
    } __attribute__((aligned(16))) frame;
    u16 entryIndex = *(u16 *)arg1;
    u16 colorIndex = *(u16 *)(arg1 + 2);
    u8 *record;
    u8 *color;
    u32 packed;
    s32 pointOffset;
    s32 recordOffset;
    s32 count;
    s32 c0, c1, c2, c3;
    s32 state;
    record = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C) + entryIndex * 0x28;
    color = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x20) + colorIndex * 8;
    pointOffset = 0;
    recordOffset = 0;
    count = 0;
    while (count < record[2]) {
        u8 *vertex = record + recordOffset;
        f32 xScale = *(f32 *)(arg1 + 4);
        f32 x = *(f32 *)(vertex + 8);
        volatile f32 *dest = (volatile f32 *)((u8 *)frame.points + pointOffset);
        f32 y = *(f32 *)(vertex + 0xC);
        f32 yScale;
        f32 xAdd;
        f32 xx;
        f32 yy;
        f32 xy;
        f32 yAdd;
        f32 yx;
        f32 xOrigin;
        f32 yOrigin;
        count++;
        yScale = *(f32 *)(arg1 + 8);
        xAdd = *(f32 *)(arg1 + 0xC);
        xx = x * xScale;
        yy = x * yScale;
        recordOffset += 8;
        xy = y * xAdd;
        yAdd = *(f32 *)(arg1 + 0x10);
        yx = y * yAdd;
        xx += xy;
        xOrigin = *(f32 *)(arg1 + 0x14);
        yy += yx;
        yOrigin = *(f32 *)(arg1 + 0x18);
        dest[0] = xOrigin + xx;
        dest[1] = yOrigin + yy;
        dest[2] = lbl_80563720;
        dest[0] = dest[0] - lbl_80563724;
        pointOffset += 0xC;
        dest[1] = -(dest[1] - lbl_80563728);
    }
    packed = *(u32 *)(record + 4);
    c0 = ((s8)color[7] * 2) + (((s8)color[3] * (s32)((((packed >> 24) & 0xFF) * 2))) / 255);
    if (c0 > 0) ; else c0 = 0;
    if (c0 < 0xFF) ; else c0 = 0xFF;
    c1 = ((s8)color[4] * 2) + (((s8)color[0] * (s32)((((packed >> 16) & 0xFF) * 2))) / 255);
    if (c1 > 0) ; else c1 = 0;
    if (c1 < 0xFF) ; else c1 = 0xFF;
    c2 = ((s8)color[5] * 2) + (((s8)color[1] * (s32)((((packed >> 8) & 0xFF) * 2))) / 255);
    if (c2 > 0) ; else c2 = 0;
    if (c2 < 0xFF) ; else c2 = 0xFF;
    c3 = ((s8)color[6] * 2) + (((s8)color[2] * (s32)((((packed) & 0xFF) * 2))) / 255);
    if (c3 > 0) ; else c3 = 0;
    if (c3 < 0xFF) ; else c3 = 0xFF;
    packed = ((u32)c0 << 24) | ((u32)(u8)c1 << 16) | ((u32)(u8)c2 << 8) | (u32)(u8)c3;
    state = (s32)fn_8022EDC4();
    fn_80231380(&frame.outputs[0], (s32)packed, frame.points[0], frame.points[1], lbl_80563720, lbl_80563720, lbl_80563720);
    fn_80231380(&frame.outputs[6], (s32)packed, frame.points[3], frame.points[4], lbl_80563720, lbl_8056372C, lbl_80563720);
    fn_80231380(&frame.outputs[12], (s32)packed, frame.points[6], frame.points[7], lbl_80563720, lbl_80563720, lbl_8056372C);
    if (record[2] == 4) {
        fn_80231380(&frame.outputs[18], (s32)packed, frame.points[9], frame.points[10], lbl_80563720, lbl_8056372C, lbl_8056372C);
    }
    frame.indices3[0] = lbl_80563718;
    frame.indices3[1] = lbl_8056371A;
    frame.indices3[2] = lbl_8056371C;
    frame.indices6[0] = lbl_802FA030[0];
    frame.indices6[1] = lbl_802FA030[1];
    frame.indices6[2] = lbl_802FA030[2];
    frame.indices6[3] = lbl_802FA030[3];
    frame.indices6[4] = lbl_802FA030[4];
    frame.indices6[5] = lbl_802FA030[5];
    fn_802C8B98(*(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x18) + (*(u16 *)record * 0x14)), state,
                lbl_80563718, lbl_802FA030[5], lbl_802FA030[4], lbl_802FA030[3],
                lbl_802FA030[2], lbl_802FA030[1]);
    if (record[2] == 4) {
        fn_802C8DB8(&frame.outputs[0], 4, &frame.indices6[0], 6);
    } else {
        fn_802C8DB8(&frame.outputs[0], 3, &frame.indices3[0], 3);
    }
    DrawList_RestoreNormalMode();
}
void fn_80238FCC(u32 arg0, u32 arg1)
{
  u8 *data = *((u8 **) (((u8 *) arg0) + 0x14));
  s32 stride = *((s32 *) (data + 4));
  s32 offset = 0;
  u8 *entry = (u8 *) ((*((s32 *) (data + 0x24))) + ((s32) ((arg1 % ((u32) stride)) * 0xC)));
  s32 i = 0;
  while ((i + 1) <= (*((u16 *) entry)))
  {
    fn_80238BF4((void *) arg0, (*((u8 **) (entry + 8))) + offset);
    offset += 0x1C;
    i++;
  }

}

#pragma dont_inline on
/* Initializes an SWF/animation state: clears data/frame fields, enables playback/loop flags, and records the current time. */
void fn_8023905C(void *state) {
    *(int *)((char *)state + 0x14) = 0;
    *(int *)((char *)state + 8) = 0;
    *(char *)((char *)state + 4) = 1;
    *(char *)((char *)state + 5) = 1;
    *(int *)state = KERNEL_GetTimeMs();
    *(int *)((char *)state + 0x10) = 0;
    *(int *)((char *)state + 0xC) = 0;
}
#pragma scheduling on
#pragma peephole on
void fn_802390B4(void *arg0, s32 arg1) {
    s32 unused;
    u32 version;
    u8 valid;
    u8 swap;
    void *loaded;

    unused = 0;
    valid = 0;
    swap = 0;
    version = 1;
    loaded = getResourceData(arg1, 0x53574632, &version, &unused, &valid, &swap);
    *(void **)((u8 *)arg0 + 0x14) = loaded;
    if (loaded == 0) {
        fn_802E30C8(lbl_80340AD0, arg1);
        return;
    }
    if (version != 1) {
        Abend_Panic(lbl_80340B00, 1, version);
    }
    if (swap != 0) {
        u8 *data = *(u8 **)((u8 *)arg0 + 0x14);
        u8 *ptr;
        u8 temp2;

        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x00);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x04);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x08);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x0C);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x10);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x14);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x18);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x1C);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x20);
        SWAP32_FIELD(*(u8 **)((u8 *)arg0 + 0x14), 0x24);

        {
            u32 offset;
            u32 i;
            s32 j;

            ptr = *(u8 **)((u8 *)arg0 + 0x14);
            *(u32 *)(ptr + 0x18) = (u32)(data + *(u32 *)(ptr + 0x18));
            *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C) = (u32)(data + *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C));
            *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x20) = (u32)(data + *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x20));
            *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24) = (u32)(data + *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24));

            for (offset = 0, i = 0; i < *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 4); offset += 0xC, i++) {
                u8 *entry = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24) + offset;
                *(u32 *)(entry + 8) = (u32)(data + *(u32 *)(entry + 8));
                if (*(u32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24) + offset + 4) != 0) {
                    *(u32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24) + offset + 4) = (u32)(data + *(u32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24) + offset + 4));
                }
            }

            for (offset = 0, i = 0; i < *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 8); offset += 0x14, i++) {
                u8 *entry = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x18) + offset;
                u8 t = *(u8 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x18) + offset);
                entry[0] = entry[3];
                entry[3] = t;
                t = entry[1];
                entry[1] = entry[2];
                entry[2] = t;
            }

            i = 0;
            if (*(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0xC) != 0) {
                for (offset = 0; i < *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0xC); offset += 0x28, i++) {
                    u8 *table = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C);
                    u8 *entry = table + offset;
                    u8 t = table[offset];
                    entry[0] = entry[1];
                    entry[1] = t;
                    SWAP32_AT(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C) + offset, 4);
                    for (j = 0; j < 0x20; j += 8) {
                        SWAP32_AT(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C) + offset + j, 8);
                        SWAP32_AT(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x1C) + offset + j, 12);
                    }
                }
            }

            for (offset = 0, i = 0; i < *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 4); offset += 0xC, i++) {
                u8 *entry = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x24) + offset;
                s32 subOffset;
                SWAP16_AT(entry, 0);
                for (j = 0, subOffset = 0; j < *(u16 *)entry; j++, subOffset += 0x1C) {
                    u8 *sub = *(u8 **)(entry + 8) + subOffset;
                    SWAP16_AT(sub, 0);
                    SWAP16_AT(sub, 2);
                    SWAP32_AT(sub, 4);
                    SWAP32_AT(sub, 8);
                    SWAP32_AT(sub, 0xC);
                    SWAP32_AT(sub, 0x10);
                    SWAP32_AT(sub, 0x14);
                    SWAP32_AT(sub, 0x18);
                }
            }
        }
    }
}

#pragma scheduling on
s32 fn_8023964C(s32 state) {
    // Reset the timed frame-animator state at `state` and return the same handle.
    fn_8023905C((void *)state);
    return state;
}

s32 fn_8023967C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Advances a frame index on a timed object when its rate timer elapses, clamping or wrapping within min/max bounds. */
void fn_802396BC(void *state) {
    s32 now;
    u32 nextFrame;
    u32 maxFrame;
    u32 minFrame;
    u32 frameRate;

    if (*(u32 **)((u8 *)state + 0x14) != 0 && *((u8 *)state + 4) != 0) {
        now = KERNEL_GetTimeMs();
        frameRate = **(u32 **)((u8 *)state + 0x14);
        if ((u32)(now - *(s32 *)state) >= 1000U / frameRate) {
            maxFrame = *(u32 *)((u8 *)state + 0x10);
            nextFrame = *(u32 *)((u8 *)state + 8) + 1;
            *(u32 *)((u8 *)state + 8) = nextFrame;
            if (nextFrame > maxFrame) {
                if (*((u8 *)state + 5) != 0) {
                    *(u32 *)((u8 *)state + 8) = *(u32 *)((u8 *)state + 0xC);
                } else {
                    *(u32 *)((u8 *)state + 8) = maxFrame;
                }
            } else {
                minFrame = *(u32 *)((u8 *)state + 0xC);
                if (nextFrame < minFrame) {
                    *(u32 *)((u8 *)state + 8) = minFrame;
                }
            }
            *(s32 *)state = now;
        }
    }
}

void fn_8023976C(u32 state) {
    /* If an SWF animation is loaded (+0x14), draw its current frame (index at +0x8). */
    if (*(u32 *)(state + 0x14) != 0) {
        ((void (*)(u32, u32))fn_80238FCC)(state, *(u32 *)(state + 8));
    }
}

extern void fn_802390B4(void *, s32);
extern s32 RegisterTextureByName(void *, s32);
extern void fn_802E30C8(const char *, ...);
extern char lbl_80340B2C[];
void fn_80239784(void *anim, s32 animName) {
    s32 byteOffset;
    s32 entryIndex;
    u8 *swfData;
    /* Loads an SW2 animation into anim: initializes it, reads the SWF data with
       fn_802390B4 (logging an error with animName when the load fails), then walks
       the texture entries, registering each named texture via RegisterTextureByName or
       marking it invalid (-1) when it has no name. */
    ((void (*)())fn_8023905C)();
    fn_802390B4(anim, animName);
    swfData = *(u8 **)((u8 *)anim + 0x14);
    if (swfData == 0) {
        fn_802E30C8(lbl_80340B2C, animName);
        return;
    }
    *(s32 *)((u8 *)anim + 0xC) = 0;
    entryIndex = 0;
    byteOffset = 0;
    *(s32 *)((u8 *)anim + 0x10) = *(s32 *)(swfData + 4) - 1;
    while ((u32)entryIndex < *(u32 *)(*(u8 **)((u8 *)anim + 0x14) + 8)) {
        u8 *texEntry = *(u8 **)(*(u8 **)((u8 *)anim + 0x14) + 0x18) + byteOffset;
        if ((s8)texEntry[4] != 0) {
            void *texture = (void *)RegisterTextureByName(texEntry + 4, 0);
            *(void **)(*(u8 **)(*(u8 **)((u8 *)anim + 0x14) + 0x18) + byteOffset) = texture;
        } else {
            *(s32 *)texEntry = -1;
        }
        byteOffset += 0x14;
        entryIndex++;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_8023986C(void *arg0) {
    /* Release every texture of a loaded SWF animation (each 0x14-byte entry holds
       a texture id in its first word), mark it freed (-2), then free the SWF data
       and clear the pointer at +0x14. */
    s32 byteOffset;
    u32 entryIndex;
    s32 releasedId = -2;
    if (*(void **)((u8 *)arg0 + 0x14) != 0) {
        entryIndex = 0;
        byteOffset = 0;
        while (entryIndex < *(u32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 8)) {
            if (*(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x18) + byteOffset) != -2) {
                fn_802CAC54(*(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x18) + byteOffset));
                *(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x14) + 0x18) + byteOffset) = releasedId;
            }
            byteOffset += 0x14;
            entryIndex++;
        }
        fn_8012C4D8(*(void **)((u8 *)arg0 + 0x14));
        *(u32 *)((u8 *)arg0 + 0x14) = 0;
    }
}
#pragma pop
