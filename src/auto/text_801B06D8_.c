#include <types.h>
extern void fn_8018AF04(void *);
extern char lbl_80335A94[];
extern s32 lbl_8055E3C4;
typedef s32 M2C_UNK;
extern void *fn_801B83A0(void);
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern void *fn_80156A40(void);
extern void *fn_801284F8(s32, const char *);
extern void *fn_80135DC4(void *, s32, void *);
extern void *fn_801352B8(void);
extern char lbl_80335B28[], lbl_80335B3C[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern u8 lbl_8055E674;
extern u8 lbl_8055E698;
extern s32 lbl_8055E69C;
extern s32 lbl_8055E67C;
extern s32 lbl_8055E6A8;
extern u8 lbl_8055E691;
extern u8 lbl_8055E692;
extern void *fn_801B2EC0(s32);
extern s32 fn_80128668(void);
void *fn_801B2118(void *, s32);
extern void *fn_801B21B8(void *);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern char lbl_80335BFC[];
extern f32 lbl_805625BC;
extern f32 lbl_80562604;
extern f32 lbl_80562610;
extern void *memset(void *, int, unsigned long);
extern void *lbl_8055E678; /* count (s32) of deity slot indices in the order table lbl_80435C30 */
extern u8 lbl_8055E6A0;
extern f32 lbl_8055E6A4;
extern s32 lbl_8055E688;
extern s32 lbl_8055E66C;
extern s32 lbl_8055E670;
extern void *lbl_8055E680;
extern void *lbl_8055E684; /* base of the deity (AI truck) slot table; one 0x80-byte slot per index */
extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
extern s32 lbl_80435C30[]; /* order table: up to 8 slot indices, sorted by fn_801B11DC (fn_801B1318) */
extern s32 lbl_80435BE8[];
extern void *lbl_8055E694;
extern f32 lbl_805625F0;
extern void *lbl_8055E68C;
extern u8 lbl_8055E690;
extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
extern void fn_801B18B8();
extern void fn_801E89F4(s32);
extern f32 lbl_805625B8;
extern f32 lbl_80562618;
extern void fn_8018A08C(void);
extern f32 lbl_805625DC;
extern f32 lbl_805625E0;
extern double lbl_805625E8;
M2C_UNK memmove(void *, void *, s32);
#pragma dont_inline fn_801B08E8

#pragma cplusplus on
struct Dummy_801B08FC_Child {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(s32);
};
struct Dummy_801B08FC {
    virtual void d0(); virtual void d1();
    virtual void d2(); virtual void d3();
    virtual void *get18();
    virtual void d5();
    virtual Dummy_801B08FC_Child *get20();
    virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11();
    virtual void call34();
};
struct Dummy_801B30E0 {
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void *d5();
    virtual void *d6(); virtual void *d7(); virtual void *d8();
};
struct Dummy_801B0DF0 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void *d8(void *, void *);
};
/* Interface onto the active deity/AI truck controller (gPrimaryObject):
 * queryNode is the +0xC slot that evaluates one track node and fills a result. */
struct DeityNodeQuery {
    virtual void d0();
    virtual void queryNode(s32, s32, s32, void *, s32 *);
};
/* Interface onto the active deity/AI-truck controller (gPrimaryObject):
 * evaluate is the +0x10 vtable slot (d0/d1 fill +0x8/+0xC). */
struct DeityNodeEvaluator {
    virtual void d0();
    virtual void d1();
    virtual void evaluate(s32, s32, s32, void *, s32 *);
};
struct Dummy_801B3084 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void func(s32, s32, s32, s32);
};
#define gPrimaryObject lbl_8055E68C
#pragma cplusplus off
extern s32 fn_80139EC4(f32, f32);
extern s32 fn_802B04D4(f32 *, f32, f32, f32);
extern f32 lbl_805625BC, lbl_805625C0, lbl_805625C4;
extern f32 lbl_80562600;
extern char lbl_80335AD8[], lbl_80335B04[];
extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
s32 fn_801B06D8(void *origin, void *direction, s32 unused) {
    /* Step a ray from origin along direction, returning 1 at the first collision
       or enabled-area hit and 0 if the whole distance is clear. */
    volatile f32 sp18, sp14, sp10, spC, sp8;
    register f32 maxDist;
    register f32 stepInc;
    register f32 firstStep;
    register f32 dist;
    dist = lbl_805625BC;
    stepInc = lbl_805625C0;
    firstStep = dist;
    maxDist = lbl_805625C4;
    while (dist < maxDist) {
        f32 dx = *(f32 *)direction * dist;
        f32 dy = *(f32 *)((u8 *)direction + 4) * dist;
        f32 x = *(f32 *)origin + dx;
        f32 y = *(f32 *)((u8 *)origin + 4) + dy;
        register s32 checkFlag;
        sp14 = firstStep;
        sp8 = x;
        spC = y;
        sp10 = x;
        sp18 = y;
        if (fn_802B04D4((f32 *)&sp10, dy, x, dx)) return 1;
        checkFlag = lbl_8055E66C;
        if (checkFlag && ((s32 (*)(s32, f32, f32))fn_80139EC4)(checkFlag, sp8, spC)) return 1;
        dist += stepInc;
    }
    return 0;
}

extern s32 fn_801784DC(f32 *, f32 *, s32, s32, s32, f32);
extern void fn_801B8040(void *, void *, f32);
extern f32 lbl_805625BC, lbl_805625C8, lbl_805625CC, lbl_805625D0, lbl_805625D4, lbl_805625D8;
#pragma scheduling invalid_target
void fn_801B07B4(void *arg0, void *arg1) {
    register s32 first = *(s32 *)arg1;
    f32 argAngle = *(f32 *)((u8 *)arg1 + 4);
    s32 argWord = *(s32 *)((u8 *)arg1 + 8);
    volatile s32 sp20;
    volatile f32 sp1C;
    void * volatile sp18;
    volatile s32 sp14, sp10, spC;
    volatile f32 sp8;
    f32 x, scale, angle, finalPos, finalScale;

    sp18 = (void *)first;
    sp1C = argAngle;
    sp20 = argWord;
    while (fn_801B06D8(sp18, (u8 *)sp18 + 8, first))
        sp18 = *(void **)((u8 *)sp18 + 0x14);
    fn_801B8040(arg0, (void *)&sp18, lbl_805625BC);
    x = *(f32 *)((u8 *)arg0 + 0x18);
    scale = lbl_805625C8;
    *(f32 *)((u8 *)arg0 + 0x30) = x * scale;
    *(f32 *)((u8 *)arg0 + 0x34) = *(f32 *)((u8 *)arg0 + 0x1C) * scale;
    *(volatile s32 *)((u8 *)arg0 + 0x3C) = 0;
    *(f32 *)((u8 *)arg0 + 0x38) = *(f32 *)((u8 *)arg0 + 0x20) * scale;
    spC = *(s32 *)((u8 *)arg0 + 0x24);
    sp10 = *(s32 *)((u8 *)arg0 + 0x28);
    sp14 = *(s32 *)((u8 *)arg0 + 0x2C);
    if (*(volatile s32 *)&lbl_8055E670 &&
        fn_80139EC4(*(f32 *)(void *)&spC, *(f32 *)(void *)&sp14)) {
        angle = *(f32 *)(void *)&sp10;
        *(f32 *)(void *)&sp10 = angle + lbl_805625CC;
        if (fn_801784DC((f32 *)(void *)&spC, (f32 *)(void *)&sp8, 0, 0, 0,
                        angle))
            *(f32 *)((u8 *)arg0 + 0x28) = lbl_805625D0 + *(f32 *)(void *)&sp8;
    }
    finalPos = *(f32 *)((u8 *)arg0 + 0x28) + lbl_805625D4;
    finalScale = lbl_805625D8;
    *(f32 *)((u8 *)arg0 + 0x34) = finalScale;
    *(f32 *)((u8 *)arg0 + 0x28) = finalPos;
}
#pragma scheduling on
#pragma dont_inline on
/* Forward distance from a base position to a target on a wrapped coordinate:
 * add the wrap span when the target lies behind the base, then subtract the base. */
u32 fn_801B08E8(u32 basePos, u32 targetPos, s32 wrapSpan) {
    u32 wrapped;
    wrapped = targetPos;
    if (wrapped < basePos) wrapped += wrapSpan;
    return wrapped - basePos;
}
#pragma dont_inline reset

#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801B08FC(void *arg0, void *arg1) {
    typedef struct { s32 id; f32 key; } Ent;
    Dummy_801B08FC *self = (Dummy_801B08FC *)arg0;
    s32 cur;
    s32 t1;
    s32 t0;
    u8 *a;
    u8 *b;
    s32 v1, v0;
    u8 *stop;
    u8 *n;
    a = *(u8 **)((u8 *)self->get18() + 4);
    self->get20()->d19((s32)arg1);
    self->get20();
    fn_8018A08C();
    b = *(u8 **)((u8 *)self->get18() + 4);
    cur = *(s32 *)((u8 *)self + 0x60);
    t0 = *(s32 *)(*(u8 **)((u8 *)self->get18() + 0x2c) + 0x18);
    t1 = *(s32 *)(*(u8 **)((u8 *)self->get18() + 0x2c) + 0x18);
    v0 = fn_801B08E8(*(s32 *)(b + 0x10), *(s32 *)(a + 0x10), t0);
    v1 = fn_801B08E8(*(s32 *)(a + 0x10), *(s32 *)(b + 0x10), t1);
    if (((u32)(v1 << __cntlzw(v1 ^ v0)) >> 31) != 0) {
        n = *(u8 **)(b + 0x14);
        stop = *(u8 **)(a + 0x14);
        for (; n != stop; n = *(u8 **)(n + 0x14)) {
            if (*(s32 *)(n + 0x10) == 0) {
                s32 c = *(s32 *)((u8 *)self + 0x14) - 1;
                *(s32 *)((u8 *)self + 0x14) = c > 0 ? c : 0;
                break;
            }
        }
    } else {
        n = *(u8 **)(a + 0x14);
        stop = *(u8 **)(b + 0x14);
        for (; stop != n; n = *(u8 **)(n + 0x14)) {
            if (*(s32 *)(n + 0x10) == 0) {
                Ent *tbl = (Ent *)lbl_80435BE8;
                u32 cnt = (u32)lbl_80435BE8[0x10];
                f32 key = lbl_8055E3C8 - lbl_805625DC * (f32)(cur + 1) * lbl_805625E0;
                if (cnt < 8) {
                    Ent tmp;
                    s32 i;
                    tmp.id = cur;
                    tmp.key = key;
                    for (i = 0; i < (s32)cnt; i++) {
                        if (tbl[i].key > key)
                            break;
                    }
                    memmove(&tbl[i + 1], &tbl[i], (cnt - i) * 8);
                    tbl[i] = tmp;
                    lbl_80435BE8[0x10]++;
                }
                break;
            }
        }
    }
    if ((*(s32 *)((u8 *)__AXFXGetLfoSinTable_801769CC() + 4) & 0x4000) == 0) {
        self->get20();
        fn_8018AF04(0);
        self->call34();
    }
    *(s32 *)((u8 *)self + 0x64) = 0;
    *(s32 *)((u8 *)self + 4) &= ~4;
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

void fn_801B0B8C(void *obj) {
    /* Reset this object's +0x2C flag to 0 and its +0x30 value to the -1.0 default. */
    register f32 defaultValue = lbl_805625F0;
    *(u8 *)((u8 *)obj + 0x2C) = 0;
    *(f32 *)((u8 *)obj + 0x30) = defaultValue;
}

s32 fn_801B0BA0(void *obj) {
    /* Return the 32-bit field at offset 0x5C of the given deity/AI-truck request object. */
    return *(s32 *)((u8 *)obj + 0x5C);
}

s32 fn_801B0BA8(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x58); }

extern f32 lbl_805625F4;
extern char lbl_80335A58[];
extern void fn_802E30C8(const char *, ...);
#pragma push
#pragma processor 750
void fn_801B0BB0(void *arg0, void *arg1) {
    void *temp_r5;
    void *var_r3;
    void *var_r0;
    s32 var_r4;
    f32 threshold = lbl_805625F4;
    f32 value;
    f32 temp_f31;
    temp_r5 = *(void **)((u8 *)arg1 + 4);
    *(void **)arg0 = temp_r5;
    *(f32 *)((u8 *)arg0 + 4) = *(f32 *)((u8 *)arg1 + 8);
    *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)arg1 + 0xC);
    value = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x2C) + 8);
    temp_f31 = value - threshold;
    if (*(f32 *)((u8 *)temp_r5 + 0x1C) > temp_f31) {
        fn_802E30C8(lbl_80335A58);
        var_r3 = *(void **)((u8 *)*(void **)((u8 *)arg1 + 0x2C) + 0x1C);
        var_r4 = 0;
        var_r0 = 0;
        do {
            if (var_r4++ > 0xBB8) {
                var_r0 = 0;
                break;
            }
            var_r0 = var_r3;
            var_r3 = *(void **)((u8 *)var_r3 + 0x14);
        } while (*(f32 *)((u8 *)var_r3 + 0x1C) < temp_f31);
        if (var_r0 != 0) *(void **)arg0 = var_r0;
    }
}

extern void fn_801B30D0(s32);
extern void fn_801B30E0(s32);
extern s32 fn_801B8928(s32, void *, s32);
extern void fn_801B0BB0(void *, void *);
extern void fn_801B07B4(void *, void *);
extern void fn_801B08FC(void *, void *);
#pragma cplusplus on
extern "C" void fn_801B0C78(s32 slotIndex) {
    struct SlotObject {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void *getPayload(); virtual void *getMetadata();
    };
    struct RequestValidator {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual s32 validate(void *request, s32 slotIndex, s32 tableParam, s32 flags);
    };
    struct RequestScratch {
        u32 raw[3]; s32 value; f32 weight; s32 limit;
        u8 request[0x20]; u8 pad[0x20]; s16 marker;
    } scratch;
    /* Build/apply a per-slot request: for PCAR-tagged metadata run slot setup and
     * source value/weight/limit from payload, otherwise from inline fields; validate
     * via optional global validator, then process and finalize the request. */
    void *slotTable = lbl_8055E684;
    SlotObject *slot = (SlotObject *)((u8 *)slotTable + (slotIndex << 7));
    void *metadata;
    bool isPcarResource;

    scratch.marker = -1;
    metadata = slot->getMetadata();
    isPcarResource = *(u32 *)((u8 *)metadata + 0x10) == 0x50434152;
    if (isPcarResource) {
        fn_801B30D0(slotIndex);
        fn_801B30E0(slotIndex);
    }
    if (fn_801B8928(slotIndex, scratch.request, 0) != 0) goto done;
    if (lbl_8055E68C != 0 &&
        ((RequestValidator *)lbl_8055E68C)->validate(scratch.request, slotIndex,
            *(s32 *)((u8 *)*(void * volatile *)&lbl_8055E684 + 0x7C), 0) != 0) goto done;
    scratch.value = 0;
    scratch.limit = 0x2710;
    scratch.weight = lbl_805625BC;
    if (isPcarResource) {
        fn_801B0BB0(scratch.raw, slot->getPayload());
        scratch.value = scratch.raw[0];
        scratch.weight = *(f32 *)&scratch.raw[1];
        scratch.limit = scratch.raw[2];
    } else {
        scratch.value = *(s32 *)((u8 *)slot + 0x4C);
        scratch.weight = *(f32 *)((u8 *)slot + 0x50);
        scratch.limit = *(s32 *)((u8 *)slot + 0x54);
    }
    fn_801B07B4(scratch.request, &scratch.value);
done:
    fn_801B08FC(slot, scratch.request);
}
#pragma cplusplus off
s32 fn_801B0DE0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

/* Address helper: returns the pointer advanced by 4 bytes (the field at +0x4). */
s32 fn_801B0DE8(s32 ptr) { return ptr + 4; }

#pragma cplusplus on
extern "C" s32 fn_801B0DF0(s32 arg0) {
    /* Returns nonzero if the deity/AI-truck slot's resource is a PCAR record (magic 0x50434152 at +0x10). */
    struct Dummy {
        virtual void *d0(void *);
        virtual void *d1(void *);
        virtual void *d2(void *);
        virtual void *d3(void *);
        virtual void *d4(void *);
        virtual void *d5(void *);
        virtual void *d6(void *);
    };
    Dummy *slot = (Dummy *)((u8 *)lbl_8055E684 + (arg0 << 7));
    void *resource = slot->d6(lbl_8055E684);
    return *(u32 *)((u8 *)resource + 0x10) == 0x50434152;
}
#pragma cplusplus reset
extern s32 fn_801B2F40(s32);
extern s32 fn_801B0DF0(s32);
#pragma cplusplus on
extern "C" s32 fn_801B0E40(s32 slotIndex, s32 *minRank) {
    struct DeitySlot {
        virtual void d0();
        virtual void d1();
        virtual void *getRankNode();
    };
    s32 rank;
    s32 forwardRank;
    s32 backRank;
    s32 floorRank;
    s32 requestedRank;
    /* Guard for one deity (AI truck) slot in the ranked order table: from this
     * slot's own rank up to the last entry, fail (0) if any slot holds a 'PCAR'
     * (player car) object. Otherwise walk down from the rank below to *minRank
     * and, at the first player-car slot, push *minRank just past it; succeed
     * with 1. fn_801B2F40(rank - 1) reads the order table (lbl_80435C30) and its
     * result stays in r3 as fn_801B0DF0's slot index -- the cast-call keeps that
     * (a normal call would let the compiler inline the test). */
    void *slotTable = lbl_8055E684;
    DeitySlot *slot = (DeitySlot *)((u8 *)slotTable + (slotIndex << 7));
    void *rankNode;

    rankNode = slot->getRankNode();
    rank = *(s32 *)((u8 *)rankNode + 4);
    forwardRank = rank;
    while (forwardRank <= (s32)lbl_8055E678) {
        fn_801B2F40(forwardRank - 1);
        if (((s32 (*)(void))fn_801B0DF0)() != 0) return 0;
        forwardRank++;
    }
    requestedRank = *minRank;
    backRank = rank - 1;
    floorRank = 1;
    if (requestedRank > 1)
        floorRank = requestedRank;
    while (backRank >= floorRank) {
        fn_801B2F40(backRank - 1);
        if (((s32 (*)(void))fn_801B0DF0)() != 0) {
            *minRank = backRank + 1;
            break;
        }
        backRank--;
    }
    return 1;
}
#pragma cplusplus reset
s32 fn_801B0F18(void) {
    /* Return the +0x4C value field of the deity/AI-truck slot selected by
     * fn_80179630() out of the 0x80-byte-slot table lbl_8055E684. */
    return *(s32 *)((u8 *)lbl_8055E684 + (fn_80179630() << 7) + 0x4C);
}

#pragma dont_inline on
/* Return 1 when the two fixed-point values differ by less than 0x20000, else 0. */
u32 fn_801B0F48(u32 a, u32 b) {
    u32 absDiff = b - a;
    if (a > b) absDiff = a - b;
    return (0x20000U << __cntlzw(absDiff ^ 0x20000)) >> 31;
}
#pragma dont_inline reset

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801B0F70(s32 arg0, s32 arg1) {
    struct Item {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void *getState();
        virtual void *getPayload(void *);
    };
    struct State {
        void *head;
        f32 weight;
        s32 limit;
    };
    struct Request {
        u8 data[0x40];
        s16 marker;
    };
    Item *item = (Item *)((u8 *)lbl_8055E684 + (arg0 << 7));
    void *result = item->getPayload((void *)arg1);
    State state;
    u32 scratch[3];
    Request request;
    s32 isResource = *(u32 *)((u8 *)result + 0x10) == 0x50434152;
    s32 failed;

    state.head = 0;
    state.weight = lbl_805625BC;
    state.limit = 0x2710;
    if (isResource != 0) {
        fn_801B30D0(arg0);
        fn_801B30E0(arg0);
        fn_801B0BB0(scratch, item->getState());
        state.head = (void *)scratch[0];
        state.weight = *(f32 *)&scratch[1];
        state.limit = scratch[2];
    } else {
        state.head = *(void **)((u8 *)item + 0x4C);
        state.weight = *(f32 *)((u8 *)item + 0x50);
        state.limit = *(s32 *)((u8 *)item + 0x54);
    }
    failed = 0;
    if (isResource == 0) {
        if (fn_801B0E40(arg0, &arg1) != 0) {
            s32 found = 0;
            void *thresholdObject = (void *)((s32 (*)(s32))fn_801B0F18)(0);
            s32 threshold = *(s32 *)((u8 *)thresholdObject + 0x10);
            void *node = state.head;
            for (; ((s32 (*)(void *, void *))fn_801B06D8)(node, (u8 *)node + 8) != 0; node = *(void **)((u8 *)node + 0x14)) {
                if (fn_801B0F48(*(u32 *)((u8 *)node + 0x10), (u32)threshold) != 0) {
                    found = 1;
                    break;
                }
            }
            state.head = node;
            if (found != 0) {
                fn_802E30C8(lbl_80335A94, arg0, lbl_8055E3C4);
                failed = 1;
            }
        } else {
            failed = 1;
        }
    }
    if (failed != 0) {
        fn_8018AF04(result);
        return;
    }
    request.marker = -1;
    fn_801B07B4(&request, &state);
    fn_801B08FC(item, &request);
}
#pragma cplusplus reset
#pragma pop

extern f32 lbl_805625F0;
extern void *lbl_8055E68C;
extern u8 lbl_8055E690;
#pragma cplusplus on
#pragma dont_inline on
/* Return nonzero if the slot's vtable method (+0x14) accepts its table entry at +0x7C, or if no object but the fallback flag is set. */
extern "C" s32 fn_801B1130(s32 slotIndex) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 f3(s32, s32);
    };
    s32 result;
    s32 matched;
    s32 altReady;

    result = 1;
    matched = 0;
    if (lbl_8055E68C != 0) {
        Dummy *obj = (Dummy *)lbl_8055E68C;
        if (obj->f3(slotIndex, *(s32 *)((u8 *)lbl_8055E684 + (slotIndex << 7) + 0x7C)) != 0)
            matched = 1;
    }
    if (matched == 0) {
        altReady = 0;
        if (lbl_8055E68C == 0 && lbl_8055E690 != 0)
            altReady = 1;
        if (altReady == 0)
            result = 0;
    }
    return result;
}
#pragma dont_inline reset
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
__declspec(section ".data") extern float lbl_80558DC4;
/* qsort comparator ranking deity/AI-truck slots: slots whose +0x68 matches the
   active cutoff sort by their +0x70 score (within a 52.0 tolerance) and come
   first; the remaining slots sort by resource sort key, then scheduled time. */
extern "C" s32 fn_801B11DC(const void *aSlotIndex, const void *bSlotIndex) {
    extern int __cntlzw(unsigned int);
    struct DeitySlot {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void *getRankData();
    };
    u32 idxA = *(const u32 *)aSlotIndex;
    u32 cutoff = *(u32 *)&lbl_8055E680;
    u32 offA = idxA << 7;
    void *base = *(void **)&lbl_8055E684;
    u32 idxB = *(const u32 *)bSlotIndex;
    u32 offB = idxB << 7;
    DeitySlot *slotA = (DeitySlot *)((u8 *)base + offA);
    DeitySlot *slotB = (DeitySlot *)((u8 *)base + offB);
    u32 flaggedA;
    u32 flaggedB;
    s32 scheduledA;
    s32 scheduledB;
    s32 keyA;
    s32 keyB;
    cutoff += 1;
    flaggedA = (u32)__cntlzw(*(u32 *)((u8 *)slotA + 0x68) - cutoff) >> 5;
    flaggedB = (u32)__cntlzw(*(u32 *)((u8 *)slotB + 0x68) - cutoff) >> 5;
    keyA = *(s32 *)((u8 *)slotA->getRankData() + 0x10);
    keyB = *(s32 *)((u8 *)slotB->getRankData() + 0x10);
    scheduledA = *(s32 *)((u8 *)slotA + 0x74);
    scheduledB = *(s32 *)((u8 *)slotB + 0x74);
    if (flaggedA == 0) goto fallback;
    if (flaggedB == 0) goto fallback;
    {
        f32 scoreA = *(f32 *)((u8 *)slotA + 0x70);
        f32 scoreB = *(f32 *)((u8 *)slotB + 0x70);
        f32 scoreDelta = (f32)(double)__fabsf(scoreA - scoreB);
        if (scoreDelta <= lbl_80558DC4) return 0;
        if (scoreB < scoreA) return 1;
        return -1;
    }
fallback:
    if (flaggedA == 0 && flaggedB == 0) goto compare_keys;
    return flaggedA ? -1 : 1;
compare_keys:
    return keyA == keyB ? scheduledB - scheduledA : keyB - keyA;
}
#pragma pop
#pragma scheduling on
#pragma cplusplus off
/* Address helper: returns a pointer to the field at offset +4 of `obj`. */
s32 fn_801B1310(s32 obj) { return obj + 4; }

extern s32 fn_801B11DC(const void *, const void *);
extern void qsort(void *, unsigned long, unsigned long, s32 (*)(const void *, const void *));
#pragma dont_inline on
void fn_801B1318(void) {
#define deitySlotOrderTable lbl_80435C30
#define deitySlotCount lbl_8055E678
#define deitySlotBase lbl_8055E684
#define CompareDeitySlotRanks fn_801B11DC
    s32 *p;
    s32 i;
    qsort(deitySlotOrderTable, (unsigned long)deitySlotCount, 4, CompareDeitySlotRanks);
    p = deitySlotOrderTable;
    for (i = 0; i < (s32)deitySlotCount; i++) {
        s32 value = *p;
        *(s32 *)((u8 *)deitySlotBase + (value << 7) + 8) = i + 1;
        p++;
    }
#undef deitySlotOrderTable
#undef deitySlotCount
#undef deitySlotBase
#undef CompareDeitySlotRanks
}
#pragma dont_inline reset

extern s32 fn_801B526C(void);
extern s32 fn_8026A344(void);
extern void fn_8026A248(s32, s32);
extern s32 fn_8026A27C(s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" /* Cycle the selected track index by an offset, using a remapped order table unless in a special mode. */
void fn_801B1390(s32 trackIndex, s32 offset) {
    struct Dummy {
        virtual void d0();
        virtual void d1();
        virtual void *d2();
    };
    s32 currentIndex = fn_8026A344();
    if (fn_801B526C() != 0) {
        s32 newIndex = ((s32)lbl_8055E678 + offset + currentIndex) % (s32)lbl_8055E678;
        fn_8026A248(newIndex, trackIndex);
    } else {
        s32 mappedIndex = 0;
        if (currentIndex >= 0 && currentIndex < (s32)lbl_8055E678) {
            Dummy *entry = (Dummy *)((u8 *)lbl_8055E684 + (currentIndex << 7));
            void *result = entry->d2();
            mappedIndex = *(s32 *)((u8 *)result + 4) - 1;
        }
        mappedIndex = ((s32)lbl_8055E678 + offset + mappedIndex) % (s32)lbl_8055E678;
        fn_8026A248(lbl_80435C30[mappedIndex], trackIndex);
    }
}

#pragma scheduling on
#pragma cplusplus off
#pragma dont_inline on
/* Applies any pending track-selection delta for each of the four player slots. */
void fn_801B146C(void) {
    s32 slotIndex = 0;
    do {
        s32 pendingDelta = fn_8026A27C(slotIndex);
        if (pendingDelta != 0) {
            fn_801B1390(slotIndex, pendingDelta);
        }
        slotIndex++;
    } while (slotIndex < 4);
}
#pragma dont_inline reset
// Sets the bits in mask in a flags word when enable is true, else clears them.
void fn_801B14BC(s32 *flags, s32 mask, s32 enable) {
    if (enable) {
        *flags |= mask;
        return;
    }
    *flags &= ~mask;
}

extern const f32 lbl_805625F8;
extern double lbl_805625E8;
extern f32 lbl_805625FC;
extern s32 fn_801366C0(s32,s32,f32);
extern void fn_801B14BC(s32*,s32,s32);
extern s32 fn_8026A27C(s32);
extern void fn_801B1390(s32, s32);
#pragma scheduling on
#pragma dont_inline on
/* Set the vehicle's "wrong way" flag after roughly 30 consecutive frames of being driven
 * backwards along the path; any other frame resets the counter and clears the flag. */
void fn_801B14E4(void *vehicle) {
    struct {
        u8 unk0[0x58];
        s32 follower;
        s32 vecBase;
        u8 unk60[4];
        s32 wrongWayFrames;
    } *base = (void *)vehicle;
    s32 vectorBase = base->vecBase;
    s32 pathFollower = *(s32 *)((u8 *)vehicle + 0x58);
    s32 wrongWay;

    if (fn_801366C0(pathFollower, vectorBase + 0x118, lbl_805625F8)) {
        base->wrongWayFrames += 1;
    } else {
        base->wrongWayFrames = 0;
    }
    wrongWay = (f32)base->wrongWayFrames > lbl_805625FC;
    fn_801B14BC((s32 *)((u8 *)base + 4), 4, wrongWay);
}
#pragma scheduling invalid_target
void fn_801B157C(void *state, s32 eventId) {
    struct Progress {
        u8 unk0[0x2C];
        u8 active;
        u8 pad0[3];
        f32 timer;
        u8 pad1[0x60 - 0x34];
        s32 id;
    } *p = (struct Progress *)state;

    /* Reset a progress entry (mark it active, restart its timer at the default value),
       and, when event dispatch is enabled, notify the event system with its id. */
    p->active = 1;
    p->timer = lbl_8055E3C8;
    if (lbl_8055E690) fn_801CB6B4(p->id, eventId, 2);
}

extern void fn_8000D7F8(s32, f32);
extern void fn_8018B0D0(s32, s32);
extern void fn_801CB55C(s32, s32);
extern void fn_801CB360(s32);
#pragma cplusplus off
#pragma cplusplus on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_801B15A8(s32 arg0, f32 farg0) {
    struct Progress {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void update();
    };
    struct Manager {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34();
        virtual void complete(s32, s32);
    };
    u8 *state = (u8 *)arg0;
    s32 count;
    s32 next;
    s32 total;
    s32 resource;
    if (*(state + 0x78) == 0 && *(state + 0x79) == 0) {
        count = *(s32 *)(state + 0x14);
        if (count == *(s32 *)(state + 0x68)) {
            if (count > 0) {
                register f32 threshold;
                f32 oldTime = *(f32 *)(state + 0x70);
                f32 current = *(f32 *)(state + 0x1C);
                threshold = lbl_80562600;
                f32 delta = farg0 - oldTime;
                *(f32 *)(state + 0x20) = delta;
                if (current > threshold) {
                    *(f32 *)(state + 0x1C) = current < delta ? current : delta;
                } else {
                    *(f32 *)(state + 0x1C) = delta;
                }
                *(f32 *)(state + 0x70) = farg0;
                ((Progress *)*(void **)(state + 0x5C))->update();
                fn_8000D7F8(*(s32 *)(state + 0x60), delta);
                next = *(s32 *)(state + 0x14) + 1;
                *(s32 *)(state + 0x14) = next;
                if (next > *(s32 *)&lbl_8055E694) {
                    *(s32 *)&lbl_8055E694 = next;
                    if (next == (s32)lbl_8055E680 + 1)
                        lbl_8055E698 = 1;
                }
                total = *(s32 *)(state + 0x14);
                *(s32 *)(state + 0x68) = total;
                if (total == (s32)lbl_8055E680 + 1) {
                    fn_802E30C8(lbl_80335AD8, *(s32 *)(state + 0x60), farg0);
                    resource = *(s32 *)(state + 0x5C);
                    *(state + 0x79) = 1;
                    *(s32 *)(state + 0x28) = 3;
                    fn_8018B0D0(resource, 3);
                    ((Manager *)fn_801B83A0())->complete(
                        *(s32 *)(state + 0x5C), *(s32 *)(state + 8));
                    fn_801CB55C(*(s32 *)(state + 0x60), *(s32 *)(state + 8));
                    fn_801CB360(*(s32 *)(state + 0x60));
                    if (*(s32 *)((u8 *)*(void **)(state + 0x5C) + 0x10) == 0x50434152) {
                        lbl_8055E69C += 1;
                        if (lbl_8055E69C == lbl_8055E67C) {
                            s32 offset, i;
                            fn_802E30C8(lbl_80335B04);
                            for (i = 0, offset = 0; i < (s32)lbl_8055E678; i++, offset += 0x80) {
                                u8 *base = (u8 *)lbl_8055E684;
                                *(base + offset + 0x78) = 1;
                            }
                        }
                    }
                }
            } else {
                *(s32 *)(state + 0x14) = count + 1;
            }
        }
    }
}
#pragma scheduling on
#pragma pop
#pragma cplusplus off

#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_801B179C(void *self, s32 index, s32 data) {
    // Initialize this object's fields and create/attach related subobjects from
    // manager-provided resources; increments a global counter for a specific tag.
    struct Manager {
        virtual void d0();
        virtual void d1();
        virtual void *getFirst(s32);
        virtual void *getSecond(s32);
    };
    struct Target {
        virtual void d0();
        virtual void set(void *);
    };
    void *first;
    void *obj;
    void *second;
    void *value;
    s32 size = index + 1;
    *(s32*)((u8*)self + 0x60) = index;
    *(s32*)((u8*)self + 0x5C) = data;
    *(s32*)((u8*)self + 0x6C) = index;
    *(s32*)((u8*)self + 8) = size;
    obj = fn_80156A40();
    first = fn_801284F8(0x68, lbl_80335B28);
    if (first != 0) {
        value = ((Manager *)obj)->getFirst(index);
        first = fn_80135DC4(first, 1, value);
    }
    *(void**)((u8*)self + 0x58) = first;
    second = fn_801284F8(0x34, lbl_80335B3C);
    if (second != 0) second = fn_801352B8();
    *(void**)((u8*)self + 0x3C) = second;
    *(void**)((u8*)second + 0x30) = *(void**)((u8*)self + 0x58);
    value = ((Manager *)obj)->getSecond(index);
    ((Target *)*(void**)((u8*)self + 0x3C))->set(value);
    if ((u32)(*(u32*)((u8*)data + 0x10) + 0xAFBD0000U) == 0x4152U) {
        lbl_8055E67C += 1;
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset
extern void fn_80135F64(s32, f32 *, f32 *, s32, s32, void *, f32, f32, f32, f32, f32);
extern void fn_801353C8(s32, f32 *, f32 *, s32);
/* Build position/offset parameter arrays from a deity slot's source transform
 * (slot+0x5C, scaled local offsets plus base position) and forward them to the
 * slot's attached handlers at +0x58 and +0x3C. */
void fn_801B18B8(void *slot, s32 arg1, s32 arg2) {
    f32 positionData[5];
    f32 offsetData[2];
    f32 baseY;
    f32 scale;
    f32 localY;
    f32 worldY;
    f32 baseX;
    void *source;
    f32 localZ;
    f32 baseZ;
    f32 worldZ;
    f32 localX;
    f32 worldX;

    source = *(void **)((u8 *)slot + 0x5C);
    scale = *(f32 *)((u8 *)source + 0x5BC);
    worldX = *(f32 *)((u8 *)source + 0x54) * scale;
    worldY = *(f32 *)((u8 *)source + 0x5C) * scale;
    baseX = *(f32 *)((u8 *)source + 0x94);
    baseY = *(f32 *)((u8 *)source + 0x9C);
    localZ = *(f32 *)((u8 *)source + 0x58);
    worldX = baseX + worldX;
    baseZ = *(f32 *)((u8 *)source + 0x98);
    worldY = baseY + worldY;
    worldZ = localZ * scale;
    positionData[0] = worldX;
    positionData[1] = worldY;
    worldZ = baseZ + worldZ;
    source = *(void **)((u8 *)slot + 0x5C);
    positionData[2] = worldX;
    localX = *(f32 *)((u8 *)source + 0x54);
    positionData[3] = worldZ;
    offsetData[0] = localX;
    localY = *(f32 *)((u8 *)source + 0x5C);
    positionData[4] = worldY;
    offsetData[1] = localY;
    fn_80135F64(*(s32 *)((u8 *)slot + 0x58), positionData, offsetData, arg1, arg2, source, worldY, worldZ, localZ, worldX, scale);
    fn_801353C8(*(s32 *)((u8 *)slot + 0x3C), positionData, offsetData, 0);
}

#pragma cplusplus on
extern "C" void fn_801B196C(s32 arg0, s32 arg1) {
    struct Manager {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void *d3(s32);
        virtual void d4(s32, void *);
    };
    struct Object {
        virtual void d0();
        virtual void d1();
        virtual void d2(void *, f32 *, s32);
    };
    void *self = (void *)arg0;
    void *entity = *(void **)((u8 *)self + 0x5C);
    Manager *manager;
    Object *object;
    f32 *data;
    f32 scale;
    f32 bx54;
    f32 bx58;
    f32 bx5c;
    f32 dx;
    f32 dy;
    f32 bx94;
    f32 bx98;
    f32 x;
    f32 bx9c;
    f32 dz;
    f32 y;
    f32 z;
    f32 points[5];
    void *result;
    manager = (Manager *)fn_80156A40();
    manager->d4(*(s32 *)((u8 *)entity + 0x1EC), (u8 *)entity + 0x60);
    data = *(f32 **)((u8 *)self + 0x5C);
    scale = *(f32 *)((u8 *)data + 0x5BC);
    bx54 = *(f32 *)((u8 *)data + 0x54);
    bx58 = *(f32 *)((u8 *)data + 0x58);
    bx5c = *(f32 *)((u8 *)data + 0x5C);
    dx = bx54 * scale;
    dy = bx58 * scale;
    bx94 = *(f32 *)((u8 *)data + 0x94);
    bx98 = *(f32 *)((u8 *)data + 0x98);
    x = bx94 + dx;
    bx9c = *(f32 *)((u8 *)data + 0x9C);
    dz = bx5c * scale;
    y = bx98 + dy;
    z = bx9c + dz;
    points[2] = x;
    points[0] = x;
    points[3] = y;
    points[4] = z;
    points[1] = z;
    manager = (Manager *)fn_80156A40();
    result = manager->d3(*(s32 *)((u8 *)self + 0x60));
    object = *(Object **)((u8 *)self + 0x3C);
    object->d2(result, points, 0);
    object = *(Object **)((u8 *)self + 0x3C);
    *(s32 *)((u8 *)self + 0x4C) = *(s32 *)((u8 *)object + 4);
    *(f32 *)((u8 *)self + 0x50) = *(f32 *)((u8 *)object + 8);
    *(s32 *)((u8 *)self + 0x54) = *(s32 *)((u8 *)object + 0xC);
}
#pragma cplusplus reset

#pragma dont_inline reset

extern void *fn_80156A40(void);
extern void *fn_801284F8(s32, const char *);
extern void *fn_80135DC4(void *, s32, void *);
extern void *fn_801352B8(void);
extern char lbl_80335B28[], lbl_80335B3C[];
extern void fn_80135F4C(void *);
#pragma push
#pragma cplusplus on
extern "C" void fn_801B1A5C(void *arg0) {
    /* One pass over a 0x80-byte slot of the AI-truck slot table (lbl_8055E684).
     * The resource manager singleton (fn_80156A40) answers for the slot's index
     * (slot+0x60): its +0x10 method returns the id held by the manager's helper
     * object and its +0x14 method picks one of the configured objects for that
     * index.  Each answer is handed to one of the slot's request objects
     * (slot+0x58 for the helper id, slot+0x3C for the picked object); their +0xC
     * method stores the id at +0x2C and resets the object when it changes.
     * fn_80135F4C then re-evaluates the helper-side object, and the
     * (value, weight, limit) triple each object settled on at +0x4/+0x8/+0xC is
     * copied back into the slot at +0x40..+0x48 and +0x4C..+0x54. */
    struct ResourceManager {
        virtual void v0();
        virtual void v1();
        virtual s32 getHelperId(s32 index); /* +0x10: id of the manager's helper */
        virtual s32 pickObject(s32 index);  /* +0x14: object chosen for index */
    };
    struct RequestObject {
        virtual void v0();
        virtual s32 setRequest(s32 id);     /* +0xC: store the id, reset on change */
        s32 value;                          /* +0x4 */
        f32 weight;                         /* +0x8 */
        s32 limit;                          /* +0xC */
    };
    struct Slot {
        u8 pad0[0x3C];
        RequestObject *configEntry;         /* +0x3C: fed with the picked object */
        s32 helperValue;                    /* +0x40 */
        f32 helperWeight;                   /* +0x44 */
        s32 helperLimit;                    /* +0x48 */
        s32 configValue;                    /* +0x4C */
        f32 configWeight;                   /* +0x50 */
        s32 configLimit;                    /* +0x54 */
        RequestObject *helperEntry;         /* +0x58: fed with the helper's id */
        u8 pad5c[4];                        /* +0x5C: entity this slot belongs to */
        s32 index;                          /* +0x60: passed to the manager */
    };
    Slot *slot = (Slot *)arg0;
    ResourceManager *manager = (ResourceManager *)fn_80156A40();
    s32 helperId = manager->getHelperId(slot->index);
    RequestObject *helperEntry = slot->helperEntry;
    helperEntry->setRequest(helperId);
    s32 objectId = manager->pickObject(slot->index);
    RequestObject *configEntry = slot->configEntry;
    configEntry->setRequest(objectId);

    fn_80135F4C(slot->helperEntry);
    slot->helperValue = slot->helperEntry->value;
    slot->helperWeight = slot->helperEntry->weight;
    slot->helperLimit = slot->helperEntry->limit;
    slot->configValue = slot->configEntry->value;
    slot->configWeight = slot->configEntry->weight;
    slot->configLimit = slot->configEntry->limit;
}
#pragma cplusplus off
#pragma pop
M2C_UNK fn_801353C4(void *, f32 *);                 /* extern */
s32 fn_80136068(void *, f32 *, f32 *);              /* extern */
s32 fn_801363A0(void *);                            /* extern */
s32 fn_801B1130(s32);                               /* extern */
f32 fn_801B2F90(s32, s32);                          /* extern */
M2C_UNK memmove(void *, void *, s32);               /* extern */
extern s32 lbl_8055E3C4;
extern f32 lbl_80562608;
extern f32 lbl_8056260C;
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801B1B30(void *arg0) {
    struct E {
        virtual void d0(); virtual void d1();
        virtual void *f4(s32); virtual void *f5(s32);
    };
    struct F {
        virtual void d0(); virtual void d1();
        virtual void f4(void *, f32 *, s32);
    };
    struct G {
        virtual void d0(); virtual void d1();
        virtual void *f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void *f8();
    };
    struct H {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
        virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
        virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
        virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
        virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
        virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
        virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
        virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
        virtual void d52(); virtual s32 f55();
    };
    struct Stack {
        f32 sp8;
        s32 pad;
        u32 sp10;
        f32 sp14;
        f32 points[5];
    } stack;
    u8 *var_r4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f2;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 var_f2;
    f32 var_f31;
    s32 temp_r31;
    s32 temp_r3_4;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 var_r27;
    s32 var_r29;
    s32 var_r29_2;
    s32 var_r31;
    s32 var_r3;
    s32 var_r4;
    u32 var_ctr;
    void **temp_r28;
    void **temp_r3;
    u8 *temp_r27;
    void *temp_r3_2;
    void *temp_r3_5;
    void *temp_r3_6;
    void *temp_r3_9;
    void *temp_r4;
    void *temp_r4_2;
    void *object;
    temp_f31 = lbl_8055E3C8;
    temp_r4 = M2C_FIELD(arg0, void **, 0x5C);
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (temp_f31 - M2C_FIELD(arg0, f32 *, 0x70));
    temp_f6 = M2C_FIELD(temp_r4, f32 *, 0x5BC);
    temp_f2 = M2C_FIELD(temp_r4, f32 *, 0x54);
    temp_f0 = M2C_FIELD(temp_r4, f32 *, 0x58);
    temp_f1 = M2C_FIELD(temp_r4, f32 *, 0x5C);
    temp_f5 = temp_f2 * temp_f6;
    temp_f3 = temp_f0 * temp_f6;
    temp_f4 = M2C_FIELD(temp_r4, f32 *, 0x94);
    temp_f2 = M2C_FIELD(temp_r4, f32 *, 0x98);
    temp_f4 = temp_f4 + temp_f5;
    temp_f0 = M2C_FIELD(temp_r4, f32 *, 0x9C);
    temp_f1 = temp_f1 * temp_f6;
    temp_f2 = temp_f2 + temp_f3;
    temp_f0 = temp_f0 + temp_f1;
    stack.points[2] = temp_f4;
    stack.points[0] = temp_f4;
    stack.points[3] = temp_f2;
    stack.points[4] = temp_f0;
    stack.points[1] = temp_f0;
    temp_r3 = (void **)((void *(*)(void *, f32, f32, f32, f32, f32, f32))fn_80156A40)(arg0, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6);
    temp_r3_2 = ((E *)temp_r3)->f4(M2C_FIELD(arg0, s32 *, 0x60));
    ((F *)M2C_FIELD(arg0, void **, 0x58))->f4(temp_r3_2, stack.points, 0);
    temp_r3_2 = ((E *)temp_r3)->f5(M2C_FIELD(arg0, s32 *, 0x60));
    ((F *)M2C_FIELD(arg0, void **, 0x3C))->f4(temp_r3_2, stack.points, 0);
    var_r29 = 0;
    if ((fn_801B1130(M2C_FIELD(arg0, s32 *, 0x60)) != 0) && ((s32) lbl_8055E692 == 0)) {
        var_r29 = 1;
    }
    stack.sp8 = lbl_805625BC;
    temp_r3_4 = fn_80136068(M2C_FIELD(arg0, void **, 0x58), stack.points, &stack.sp8);
    var_r31 = temp_r3_4;
    if ((var_r29 == 0) || ((s32) lbl_8055E692 != 0)) {
        if (temp_r3_4 == 0) {
            var_r31 = 2;
        } else if (temp_r3_4 == 1) {
            var_r31 = 3;
        }
    }
    if ((var_r31 == 2) || (var_r31 == 0)) {
        temp_r4_2 = M2C_FIELD(arg0, void **, 0x58);
        temp_r3_5 = M2C_FIELD(arg0, void **, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_r4_2, s32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(temp_r4_2, f32 *, 8);
        M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(temp_r4_2, s32 *, 0xC);
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_r3_5, s32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(temp_r3_5, f32 *, 8);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(temp_r3_5, s32 *, 0xC);
    }
    fn_801353C4(M2C_FIELD(arg0, void **, 0x3C), stack.points);
    temp_r3_6 = M2C_FIELD(arg0, void **, 0x58);
    if ((s32) M2C_FIELD(temp_r3_6, u8 *, 0x64) != 0) {
        if ((s32) M2C_FIELD(arg0, volatile u8 *, 0x78) == 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x60);
        }
    } else {
        temp_r3_7 = ((s32 (*)(void *, void *))fn_801363A0)(temp_r3_6, (u8 *)temp_r3_6 + 4);
        if ((s32) M2C_FIELD(arg0, volatile u8 *, 0x78) == 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = temp_r3_7;
        }
    }
    var_r4 = var_r31 == 0;
    if (((s32) lbl_8055E674 != 0) && ((u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0x10) + 0xAFBD0000) == 0x4152U) && ((s32) lbl_8055E6A8 == 0) && !(lbl_8055E3C4 & 0x3F)) {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        var_r4_2 = (u8 *)lbl_80435BE8;
        temp_f1_2 = temp_f31 - stack.sp8;
        if ((u32) M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) < 8U) {
            stack.sp10 = M2C_FIELD(arg0, s32 *, 0x60);
            var_ctr = M2C_FIELD(&lbl_80435BE8, u32 *, 0x40);
            var_r3 = 0;
            stack.sp14 = temp_f1_2;
            if ((s32) M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) > 0) {
loop_25:
                if (!(M2C_FIELD(var_r4_2, f32 *, 4) > temp_f1_2)) {
                    var_r4_2 += 8;
                    var_r3 += 1;
                    var_ctr -= 1;
                    if (var_ctr != 0U) {
                        goto loop_25;
                    }
                }
            }
            temp_r27 = (u8 *)lbl_80435BE8 + (var_r3 * 8);
            memmove(temp_r27 + 8, temp_r27, (M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) - var_r3) * 8);
            M2C_FIELD(temp_r27, s32 *, 0) = stack.sp10;
            M2C_FIELD(temp_r27, f32 *, 4) = stack.sp14;
            M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) = (u32) (M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) + 1);
        }
        if ((s32) M2C_FIELD(arg0, volatile u8 *, 0x78) == 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) lbl_8055E688;
        }
    }
    if (var_r31 == 1) {
        temp_r3_8 = M2C_FIELD(arg0, s32 *, 0x14) - 1;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (temp_r3_8 & ((s32) (-temp_r3_8 & ~temp_r3_8) >> 0x1F));
    }
    object = (void *)fn_801B83A0();
    if (((H *)object)->f55() != 0) {
        fn_801B14E4(arg0);
    }
    if (((s32) lbl_8055E67C > 1) && ((u32) (M2C_FIELD(((G *)arg0)->f8(), s32 *, 0x10) + 0xAFBD0000) == 0x4152U)) {
        var_f31 = lbl_805625BC;
        var_r27 = 0;
        var_r29_2 = 0;
        for (; var_r27 < (s32) lbl_8055E678; var_r29_2 += 0x80, var_r27++) {
        G *item = (G *)((u8 *)lbl_8055E684 + var_r29_2);
        temp_r3_9 = item->f8();
        if ((var_r27 != (s32) M2C_FIELD(arg0, s32 *, 0x60)) && ((u32) (M2C_FIELD(temp_r3_9, s32 *, 0x10) + 0xAFBD0000) == 0x4152U)) {
            temp_r31 = M2C_FIELD(item->f4(), s32 *, 4);
            if ((s32) M2C_FIELD(((G *)arg0)->f4(), s32 *, 4) > temp_r31) {
                temp_f1_3 = fn_801B2F90(var_r27, M2C_FIELD(arg0, s32 *, 0x60));
                if (var_f31 <= temp_f1_3) {
                    var_f31 = temp_f1_3;
                }
            }
        }
        }
        var_f2 = lbl_80562604;
        temp_f0_2 = lbl_8056260C * (var_f31 - lbl_80562608);
        var_f2 = var_f2 < temp_f0_2 ? var_f2 : temp_f0_2;
        var_f2 = var_f2 > lbl_805625BC ? var_f2 : lbl_805625BC;
        temp_f1_4 = var_f2 * lbl_80562604;
        temp_f31_2 = lbl_805625BC + temp_f1_4;
        M2C_FIELD(((G *)arg0)->f8(), f32 *, 0x5EC) = temp_f31_2;
    }
}
#pragma cplusplus on
extern "C" void fn_801B1FB4(void *node, s32 paramA, s32 paramB, s32 *outResult) {
    /* Zero the output; if the deity/AI truck controller is active, ask its +0xC
       method to evaluate this track node (id at +0x60, scratch at +0x7C). */
    *outResult = 0;
    if (gPrimaryObject == 0) {
        return;
    }
    ((DeityNodeQuery *)gPrimaryObject)->queryNode(paramA, paramB, *(s32 *)((u8 *)node + 0x60), (u8 *)node + 0x7C, outResult);
}
#pragma cplusplus on
extern "C" void fn_801B1FEC(void *deitySlot, s32 nodeIndex, s32 value, s32 *result) {
    /* Ask the active deity/AI-truck controller to evaluate a track node for the
     * given 0x80-byte deity slot, returning its outcome through *result. */
    *result = 0;
    if (lbl_8055E68C == 0) {
        return;
    }
    ((DeityNodeEvaluator *)lbl_8055E68C)->evaluate(nodeIndex, value, *(s32 *)((u8 *)deitySlot + 0x60), (u8 *)deitySlot + 0x7C, result);
}
#pragma cplusplus off

extern s32 fn_80139D4C(const char *);
extern void fn_80204A1C(const char *, u8 *);
extern s32 *fn_801769D8(u8);
extern s32 fn_8012850C(s32, void *);
extern void *fn_8002F37C(void *, void *, s32, s32);
extern void *fn_800081F0(void);
extern void *fn_801B83A0(void);
extern void *fn_8013C9F4(s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801B2024(void *arg0) {
    /* Initialize this subsystem: load named resources/config, derive mode flags
     * from arg0, allocate and set up the object pool, then obtain the primary
     * object (vtable slot 0xE8 initialize) with a fallback. */
    class InitObject {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
        virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
        virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
        virtual void *initialize();
    };
    register char *resourceBase = lbl_80335A58;
    u32 flags;
    u8 modeIndex;
    s32 itemCount;
    s32 poolMemory;
    void *primaryObject;
    lbl_8055E66C = fn_80139D4C(resourceBase + 0xF8);
    lbl_8055E670 = fn_80139D4C(resourceBase + 0x10C);
    fn_80204A1C(resourceBase + 0x120, &lbl_8055E692);
    flags = *(u32 *)((u8 *)arg0 + 4);
    modeIndex = (flags >> 8) & 1;
    lbl_8055E690 = modeIndex;
    lbl_8055E691 = (flags >> 9) & 1;
    itemCount = *fn_801769D8(modeIndex);
    lbl_8055E678 = (void *)itemCount;
    lbl_8055E67C = 0;
    poolMemory = fn_8012850C((itemCount << 7) + 0x10, resourceBase + 0x130);
    lbl_8055E684 =
        ((void *(*)(s32, void *(*)(void *), void (*)(void), s32, s32))fn_8002F37C)(
            poolMemory, fn_801B21B8, (void (*)(void))fn_801B2118, 0x80, itemCount);
    __AXFXGetLfoSinTable_801769CC();
    lbl_8055E680 = fn_800081F0();
    primaryObject = ((InitObject *)fn_801B83A0())->initialize();
    lbl_8055E68C = primaryObject;
    if (primaryObject == 0) {
        primaryObject = fn_8013C9F4(0);
        lbl_8055E68C = primaryObject;
    }
    lbl_8055E674 = 0;
}

#pragma cplusplus on
extern "C" void *fn_801B2118(void *obj, s32 deleteFlag) {
    /* Deleting destructor: restore vtable lbl_80335BFC, destroy owned objects at +0x58 and +0x3C via virtual slot 2 (arg 1), then free when deleteFlag > 0. */
    struct V { virtual void c(s32); };
    void *child58;
    void *child3C;
    if (obj != 0) {
        child58 = *(void **)((u8 *)obj + 0x58);
        *(void **)obj = (void *)lbl_80335BFC;
        if (child58 != 0) {
            ((struct V *)child58)->c(1);
        }
        child3C = *(void **)((u8 *)obj + 0x3C);
        if (child3C != 0) {
            ((struct V *)child3C)->c(1);
        }
        if (deleteFlag > 0) {
            ((s32 (*)(void *))fn_80128668)(obj);
        }
    }
    return obj;
}
#pragma cplusplus off

/* fn_801B2118 stub removed for prototype fix */

void *fn_801B21B8(void *arg0) {
    register float value = lbl_805625BC;
    register int zero = 0;
    *(void **)arg0 = lbl_80335BFC;
    *(s32 *)((u8 *)arg0 + 0x40) = zero;
    *(s32 *)((u8 *)arg0 + 0x48) = 0x2710;
    *(float *)((u8 *)arg0 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x4C) = zero;
    *(s32 *)((u8 *)arg0 + 0x54) = 0x2710;
    *(float *)((u8 *)arg0 + 0x50) = value;
    memset((u8 *)arg0 + 4, zero, 0x38);
    *(float *)((u8 *)arg0 + 0x70) = lbl_805625BC;
    *(s32 *)((u8 *)arg0 + 0x5C) = zero;
    *(s32 *)((u8 *)arg0 + 0x60) = -1;
    *(s32 *)((u8 *)arg0 + 0x6C) = -1;
    *(s32 *)((u8 *)arg0 + 0x58) = zero;
    *(s32 *)((u8 *)arg0 + 0x3C) = zero;
    return arg0;
}

s32 fn_801B224C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma cplusplus on
struct VTable68C {
    virtual void d0();
    virtual void d1();
    virtual void d2(s32);
};
struct VSingle {
    virtual void m(s32);
};
#pragma cplusplus on
extern "C" void fn_8002F6AC(void *, void (*)(void));
extern "C" void fn_80139E18(void *);
#pragma cplusplus on
extern "C" void fn_801B228C(void) {
    /* Shut down the deity/AI truck subsystem: destroy the 0x80-byte slot pool
     * (lbl_8055E684) with fn_801B2118, clear the slot base/count, destroy the
     * primary init object (lbl_8055E68C) via its deleting virtual method, then
     * release the two loaded resource containers (lbl_8055E66C, lbl_8055E670). */
    fn_8002F6AC(lbl_8055E684, (void (*)(void))fn_801B2118);
    lbl_8055E684 = 0;
    lbl_8055E678 = 0;
    if (lbl_8055E68C != 0) {
        if (lbl_8055E68C != 0) {
            ((VSingle *)lbl_8055E68C)->m(1);
        }
        lbl_8055E68C = 0;
    }
    if (lbl_8055E66C != 0) {
        fn_80139E18((void *)lbl_8055E66C);
        lbl_8055E66C = 0;
    }
    if (lbl_8055E670 != 0) {
        fn_80139E18((void *)lbl_8055E670);
        lbl_8055E670 = 0;
    }
}
#pragma cplusplus off
void fn_801B2320(void) {
    /* Snapshot the current scene's clock into the global scheduling base time:
       the root object returned by fn_80178C9C holds a container at +0x2C whose
       +0x18 field is the tick used to schedule AI truck spawns. */
    lbl_8055E688 = *(s32 *)((u8 *)*(void **)((u8 *)fn_80178C9C() + 0x2C) + 0x18);
}

void fn_801B234C(f32 deadline) {
    #define sDeadline      lbl_8055E6A4 /* time at which the scheduled event fires */
    #define sDeadlineArmed lbl_8055E6A0 /* 1 while that deadline is active */
    sDeadline = deadline;
    sDeadlineArmed = 1;
    #undef sDeadline
    #undef sDeadlineArmed
}

void fn_801B235C(void) {
    fn_801E89F4(3);
}

extern s32 lbl_8055E6A8;
extern f32 lbl_805625DC;
extern char lbl_80335B94[];
#pragma dont_inline fn_801B146C
#pragma push
#pragma processor 750
void fn_801B2364(void) {
    f32 currentTime;
    void *entry;
    s32 entryOffset;
    s32 entryIndex;
    s32 state;
    s32 resetOffset;
    s32 resetIndex;

    /* Per-frame update: advance state and, after timeout, activate/dispatch entries and finish. */
    fn_801B146C();
    if (fn_801769F8() != 0) {
        return;
    }
    state = fn_801E89EC();
    currentTime = lbl_8055E3C8;
    if (lbl_8055E6A0 && currentTime >= lbl_8055E6A4) {
        if (state == 0) {
            fn_801E89F4(1);
            for (entryIndex = 0, entryOffset = 0; entryIndex < (s32)lbl_8055E678; entryOffset += 0x80, entryIndex++) {
                entry = (u8 *)lbl_8055E684 + entryOffset;
                fn_8018B0D0(*(s32 *)((u8 *)entry + 0x5C), 2);
                fn_801CB3AC(*(s32 *)((u8 *)entry + 0x60));
            }
        }
        if (lbl_8055E6A8 == 1 && fn_800216D0() != 0) {
            lbl_8055E6AC += lbl_805625DC;
        }
        if (lbl_8055E6A8 == 1 && currentTime > lbl_8055E6AC) {
            fn_802E30C8(lbl_80335B94);
            lbl_8055E6A8 = 0;
            resetIndex = 0;
            resetOffset = 0;
            while (resetIndex < (s32)lbl_8055E678) {
                *(s32 *)((u8 *)lbl_8055E684 + resetOffset + 0x28) = lbl_8055E6A8;
                resetOffset += 0x80;
                resetIndex++;
            }
            if (lbl_8055E691) {
                fn_801B84F8();
            }
        }
    }
}
#pragma pop
extern void fn_801B15A8(s32, f32);
// Processes pending timed object updates and dispatches completion callbacks for queued entries.
void fn_801B24B8(void) {
    struct Table {
        s32 entries[16];
        volatile s32 count;
    };
    register struct Table *pendingTable;
    register s32 baseTime;
    register void *object;
    register s32 *entryPtr;
    register s32 i;
    register s32 scheduledTime;
    register s32 objectIndex;
    register s32 *tableBase;
    register s32 j;

    if (fn_801769F8() != 0)
        return;
    entryPtr = (s32 *)&lbl_80435BE8;
    pendingTable = (struct Table *)entryPtr;
    i = 0;
    goto check_first;
first_loop:
    objectIndex = entryPtr[0];
    baseTime = *(volatile s32 *)&lbl_8055E688;
    object = (u8 *)lbl_8055E684 + (objectIndex << 7);
    scheduledTime = baseTime - i + 9;
    if (*(u8 *)((u8 *)object + 0x78) == 0)
        *(s32 *)((u8 *)object + 0x74) = scheduledTime;
    entryPtr = (s32 *)((u8 *)entryPtr + 8);
    i++;
check_first:
    if (i < pendingTable->count)
        goto first_loop;

    fn_801B1318();

    tableBase = (s32 *)&lbl_80435BE8;
    j = 0;
    goto check_second;
second_loop:
    {
        s32 queuedIndex = pendingTable->entries[0];
        f32 amount = *(f32 *)((u8 *)pendingTable + 4);
        object = (u8 *)lbl_8055E684 + (queuedIndex << 7);
        fn_801B15A8((s32)object, amount);
    }
    pendingTable = (struct Table *)((u8 *)pendingTable + 8);
    j++;
check_second:
    if (j < *(volatile s32 *)((u8 *)tableBase + 0x40))
        goto second_loop;

    *(volatile s32 *)((u8 *)tableBase + 0x40) = 0;
    object = lbl_8055E68C;
    if (object != 0) {
#pragma cplusplus on
        struct Dummy {
            virtual void d0();
            virtual void d1();
            virtual void d2();
            virtual void d3();
            virtual void d4();
            virtual void d5();
            virtual void call();
        };
        ((Dummy *)object)->call();
#pragma cplusplus reset
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_801B25B0(s32 *arg0, s32 *arg1) {
    struct First {
        virtual void v0();
        virtual void v1();
        virtual void *get(s32, void *);
    };
    struct Second {
        virtual void v0();
        virtual void v1();
        virtual void *get();
    };
    register s32 i1 = *arg1;
    register s32 i0 = *arg0;
    void *base = lbl_8055E684;
    First *obj0 = (First *)((u8 *)base + (i0 << 7));
    Second *obj1 = (Second *)((u8 *)base + (i1 << 7));
    void *result0 = obj0->get(i1, base);
    register f32 var_f31 = *(f32 *)((u8 *)result0 + 0x20);
    void *result1 = obj1->get();
    f32 var_f1 = *(f32 *)((u8 *)result1 + 0x20);
    if (var_f31 < lbl_80562604) var_f31 = lbl_80562610;
    if (var_f1 < lbl_80562604) var_f1 = lbl_80562610;
    if (var_f31 < var_f1) return -1;
    return var_f31 > var_f1;
}
#pragma cplusplus off
#pragma pop
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_80019B3C(void);
extern f32 fn_8013B650(int);
extern void fn_801B1A5C(void *);
extern f32 fn_801B88BC(void);
extern u8 lbl_8055E698;
extern s32 lbl_8055E69C;
extern u8 lbl_8055E6B0;
extern char lbl_80335BA8[];
extern char lbl_8055A8C0;
extern f32 lbl_80562614;
extern s32 fn_801B25B0(s32 *, s32 *);
#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_801B265C(void) {
    struct Mgr {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
    };
    s32 order[8];
    s32 j, i;
    s32 *p;
    register f32 temp_f31;

    lbl_8055E6A8 = 1;
    if ((*(s32 *)((u8 *)__AXFXGetLfoSinTable_801769CC() + 0x10) & 1) || fn_80019B3C() != 0) {
        if (lbl_8055E6B0 == 0) {
            lbl_8055E6B0 = 1;
            fn_802E30C8((const char *)&lbl_8055A8C0, lbl_80335BA8);
        }
        lbl_8055E6AC = lbl_8055E3C8 + lbl_80562614;
    } else {
        temp_f31 = lbl_8055E3C8;
        lbl_8055E6AC = temp_f31 + fn_801B88BC();
    }
    lbl_8055E698 = 0;
    lbl_8055E694 = 0;
    lbl_8055E6A4 = lbl_805625BC;
    lbl_8055E69C = 0;
    lbl_8055E6A0 = 0;
    memset(lbl_80435C30, -1, 0x20);
    ((Mgr *)fn_80156A40())->v6();
    for (i = 0, j = 0; i < (s32)lbl_8055E678; j += 0x80, i++) {
        fn_801B1A5C((u8 *)lbl_8055E684 + j);
    }
    for (i = 0, j = 0; i < (s32)lbl_8055E678; j += 0x80, i++) {
        u8 *obj = (u8 *)lbl_8055E684 + j;
        f32 value = lbl_805625F0;
        f32 other;
        if (*(s32 *)(*(u8 **)(obj + 0x5C) + 0x1F0) == 0x51) {
            value = fn_8013B650(*(s32 *)(obj + 0x60));
        }
        other = *(f32 *)(*(u8 **)(obj + 0x5C) + 0x254);
        if (!((f32)(double)__fabsf(other) <= lbl_80558DC4)) {
            value = other;
        }
        *(f32 *)(obj + 0x24) = value;
    }
    for (i = 0; i < (s32)lbl_8055E678; i++) {
        order[i] = i;
    }
    qsort(order, (unsigned long)lbl_8055E678, 4, (s32 (*)(const void *, const void *))fn_801B25B0);
    p = order;
    for (i = 0; i < (s32)lbl_8055E678; i++) {
        *(s32 *)((u8 *)lbl_8055E684 + (*p++ << 7) + 0x6C) = i;
    }
}
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801B2910(void) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual s32 v6();
        virtual void v7();
    };
    s32 i, j;
    s32 a, b, one;
    f32 f31, f30;
    s32 *p;

    lbl_8055E6A0 = 0;
    fn_801E89F4(0);
    *(s32 *)((u8 *)&lbl_80435BE8 + 0x40) = 0;
    for (i = 0, j = 0; i < (s32)lbl_8055E678; j += 0x80, i++) {
        ((Obj *)((u8 *)lbl_8055E684 + j))->v0();
    }
    for (j = 0; j < (s32)lbl_8055E678; j++) {
        u32 idx = *(s32 *)((u8 *)lbl_8055E684 + (j << 7) + 8) - 1;
        lbl_80435C30[idx] = j;
    }
    if (lbl_8055E68C != 0) {
        ((Obj *)lbl_8055E68C)->v7();
    }
    fn_801B234C(lbl_8055E3C8 + lbl_80562618);
    one = (s32)lbl_8055E678 == 1;
    if (one) {
        f31 = lbl_805625BC;
    } else {
        f31 = -lbl_805625B8;
    }
    if (one) {
        f30 = lbl_805625BC;
    } else {
        f30 = lbl_805625B8;
    }
    p = lbl_80435C30;
    a = 0;
    b = 0;
    for (i = 0; i < (s32)lbl_8055E678; p++, i++) {
        u8 *o = (u8 *)lbl_8055E684 + (*p << 7);
        if (!(i & 1) && one) {
            *(s32 *)(o + 0x34) = a;
            *(f32 *)(o + 0x38) = f30;
            a = ((Obj *)o)->v6();
        } else {
            *(s32 *)(o + 0x34) = b;
            *(f32 *)(o + 0x38) = f31;
            b = ((Obj *)o)->v6();
        }
    }
    ((Obj *)fn_80156A40())->v7();
}
#pragma cplusplus off
#pragma use_lmw_stmw reset
#pragma dont_inline reset
/* Resets this object state block and notifies its resource/owner handlers. */
void fn_801B2BE8(void *obj) {
    s32 increment;
    f32 initial;
    s32 resource;

    memset((char *)obj + 4, 0, 0x38);
    increment = *(s32 *)((char *)obj + 0x6C);
    initial = lbl_805625BC;
    *(s32 *)((char *)obj + 8) = increment + 1;
    resource = *(s32 *)((char *)obj + 0x5C);
    *(s32 *)((char *)obj + 0x68) = 0;
    *(f32 *)((char *)obj + 0x70) = initial;
    *(s32 *)((char *)obj + 0x74) = 0;
    *(u8 *)((char *)obj + 0x78) = 0;
    *(u8 *)((char *)obj + 0x79) = 0;
    *(s32 *)((char *)obj + 0x7C) = 0;
    *(s32 *)((char *)obj + 0x64) = 0;
    fn_8018B0D0(resource, 0);
    fn_801CB360(*(s32 *)((char *)obj + 0x60));
    *(s32 *)((char *)obj + 0x28) = 1;
}
#pragma scheduling on
void fn_801B2C6C(void) {

}

#pragma scheduling invalid_target
s32 fn_801B2C70(void *arg0) {
    s32 x;
    unsigned int shifted;
    unsigned int y;
    s32 mask;
    struct Entry {
        s32 unknown0;
        s32 value;
        s32 unknown8;
        u8 unknownC[4];
        u8 flag;
        u8 unknown11[3];
    } *entry;
    s32 zero;
    s32 offset;
    s32 i;
    memset(arg0, 0, 0xB0);
    *(s32 *)arg0 = (s32)lbl_8055E678;
    *(s32 *)((u8 *)arg0 + 4) = lbl_8055E67C;
    zero = 0;
    *(u8 *)((u8 *)arg0 + 0xC) = zero;
    *(u8 *)((u8 *)arg0 + 0xD) = lbl_8055E698;
    x = (unsigned)lbl_8055E69C;
    y = lbl_8055E67C;
    x = y ^ x;
    shifted = x >> 1;
    mask = x & y;
    shifted = shifted - mask;
    *(u8 *)((u8 *)arg0 + 0xE) = (u32)shifted >> 31;
    entry = (struct Entry *)((u8 *)arg0 + 0x10);
    i = 0;
    offset = 0;
    while (i < (s32)lbl_8055E678) {
        i = i + 1;
        entry->value = *(s32 *)((u8 *)lbl_8055E684 + offset + 8);
        offset = offset + 0x80;
        entry->unknown8 = zero;
        entry->flag = zero;
        entry++;
    }
    return 1;
}
extern int fn_801E89EC();
#pragma cplusplus on
extern "C" s32 fn_801B2F40(s32);
extern "C" f32 fn_801B306C(void);
extern "C" void *fn_801B307C(void);
extern "C" void fn_801B2D28(void *arg0) {
    struct Item {
        virtual void d0();
        virtual void d1();
        virtual void *get();
    };
    struct Header {
        u8 padding[0x560];
        void *resource;
    };
    s32 offset;
    u8 *dst;
    s32 index;
    s32 value;

    memset((u8 *)arg0 + 0x560, 0, 0x1C);
    ((Header *)arg0)->resource = fn_801B307C();
    *(s32 *)((u8 *)arg0 + 0x564) = fn_801B2F40(0);
    value = lbl_8055E6A8;
    if (lbl_8055E691)
        value = 0;
    *(s32 *)((u8 *)arg0 + 0x574) = value;
    *(s32 *)((u8 *)arg0 + 0x578) = value;
    *(f32 *)((u8 *)arg0 + 0x56C) = lbl_8055E6A4;
    *(f32 *)((u8 *)arg0 + 0x570) = fn_801B306C();

    dst = (u8 *)arg0;
    index = 0;
    *(void **)((u8 *)arg0 + 0x568) = lbl_8055E680;
    offset = 0;
    while (index < (s32)lbl_8055E678) {
        Item *obj = (Item *)((u8 *)lbl_8055E684 + offset);
        void *result = obj->get();
        struct { u32 value; } first, second;
        u32& tail30 = first.value;
        u32& tail34 = second.value;

        *(u32 *)(dst + 0x3A0) = *(u32 *)((u8 *)result + 0x00);
        *(u32 *)(dst + 0x3A4) = *(u32 *)((u8 *)result + 0x04);
        *(u32 *)(dst + 0x3A8) = *(u32 *)((u8 *)result + 0x08);
        *(f32 *)(dst + 0x3AC) = *(f32 *)((u8 *)result + 0x0C);
        *(u32 *)(dst + 0x3B0) = *(u32 *)((u8 *)result + 0x10);
        *(f32 *)(dst + 0x3B4) = *(f32 *)((u8 *)result + 0x14);
        *(f32 *)(dst + 0x3B8) = *(f32 *)((u8 *)result + 0x18);
        *(f32 *)(dst + 0x3BC) = *(f32 *)((u8 *)result + 0x1C);
        *(f32 *)(dst + 0x3C0) = *(f32 *)((u8 *)result + 0x20);
        *(u32 *)(dst + 0x3C4) = *(u32 *)((u8 *)result + 0x24);
        *(u8 *)(dst + 0x3C8) = *(u8 *)((u8 *)result + 0x28);
        *(f32 *)(dst + 0x3CC) = *(f32 *)((u8 *)result + 0x2C);
        tail30 = *(u32 *)((u8 *)result + 0x30);
        tail34 = *(u32 *)((u8 *)result + 0x34);
        *(u32 *)(dst + 0x3D0) = tail30;
        *(u32 *)(dst + 0x3D4) = tail34;
        dst += 0x38;
        offset += 0x80;
        ++index;
    }

    if (fn_801E89EC() == 0) {
        if (lbl_8055E6A0 != 0) {
            f32 end;
            f32 start;
            start = lbl_8055E3C8;
            end = lbl_8055E6A4;
            *(s32 *)((u8 *)arg0 + 0x39C) = (s32)(end - start) + 1;
        } else {
            *(s32 *)((u8 *)arg0 + 0x39C) = -1;
        }
    } else {
        *(s32 *)((u8 *)arg0 + 0x39C) = 0;
    }
}
#pragma cplusplus reset

#pragma scheduling on
/* Return the 0x80-byte deity (AI truck) slot at slotIndex from the slot table. */
void *fn_801B2EC0(s32 slotIndex) {
#define sDeitySlotBase lbl_8055E684
    return (void *)((u8 *)sDeitySlotBase + (slotIndex << 7));
#undef sDeitySlotBase
}
#pragma dont_inline reset

#pragma dont_inline on
void *fn_801B2ED0(s32 arg0) {
    return fn_801B2EC0(arg0);
}
#pragma dont_inline reset

/* Return the cached contest lap-count target in lbl_8055E680, used as the completion cutoff for deity (AI truck) slots. */
void* fn_801B2ED4(void) {
    return lbl_8055E680;
}

s32 fn_801B2EDC(s32 arg0, s32 arg1) {
    /* Compute the element at lbl_8055E684 + (arg0 << 7), initialize it via fn_801B179C, and return it. */
    void *var_r31;

    var_r31 = (void *)((u8 *)lbl_8055E684 + (arg0 << 7));
    fn_801B179C(var_r31, arg0, arg1);
    return (s32)var_r31;
}

void* fn_801B2F24(void) {
#define deitySlotCount lbl_8055E678
    /* Return the number of deity slot indices held in the order table lbl_80435C30. */
    return deitySlotCount;
#undef deitySlotCount
}

u8 fn_801B2F2C(s32 slotIndex) {
    /* Return the +0x79 completion flag of the given AI-truck (deity) slot. */
#define sDeitySlotBase lbl_8055E684
    return ((u8 *)sDeitySlotBase)[(slotIndex << 7) + 0x79];
#undef sDeitySlotBase
}

s32 fn_801B2F40(s32 rankIndex) {
    /* Return the deity (AI truck) slot index stored at the given 0-based rank
       in the rank-sorted order table; callers pass rank - 1. */
#define deitySlotOrderTable lbl_80435C30
    return deitySlotOrderTable[rankIndex];
#undef deitySlotOrderTable
}

typedef void (*VFnPtr)(void *);
 #define sDeitySlotBase lbl_8055E684 /* base of the 0x80-byte deity (AI truck) slot table */
 #define DEITY_SLOT_RANK 0x6C /* +0x6C: qualifying rank/placement, assigned by the fn_801B25B0 sort */

#pragma cplusplus on
/* RealName: DeitySlot_GetResourceType. Return the magic/tag at +0x10 of the resource held by a deity (AI truck) slot (0x50434152 = "PCAR"). */
extern "C" s32 fn_801B2F54(s32 slotIndex) {
    struct Dummy {
        virtual void *d0(void *);
        virtual void *d1(void *);
        virtual void *d2(void *);
    };
    Dummy *slot = (Dummy *)((u8 *)sDeitySlotBase + (slotIndex << 7));
    void *resource = slot->d2(sDeitySlotBase);
    return *(s32 *)((u8 *)resource + 0x10);
}
#pragma cplusplus reset
extern f32 lbl_8056261C;
extern f32 fn_801365C4(void *, void *);
extern double __fabs(double);
#pragma scheduling invalid_target
f32 fn_801B2F90(s32 arg0, s32 arg1) {
    void *base = lbl_8055E684;
    void *obj0 = (u8 *)base + (arg0 << 7);
    void *obj1 = (u8 *)base + (arg1 << 7);
    s32 *first;
    s32 *second;
    s32 difference;

    if (*(s32 *)((u8 *)obj0 + 8) - 1 < *(s32 *)((u8 *)obj1 + 8) - 1) {
        first = obj0;
        second = obj1;
    } else {
        first = obj1;
        second = obj0;
    }
    difference = first[5] - second[5] - ((u32)first[0x1D] < (u32)second[0x1D]);
    if (difference != 0)
        return lbl_8056261C * (f32)difference;
    {
        double magnitude = __fabs((f64)fn_801365C4(*(void **)(second + 0x16),
                                                  *(void **)(first + 0x16)));
        return (f32)magnitude;
    }
}
#pragma scheduling on
/* Return the qualifying rank/placement (slot +0x6C) of deity/AI-truck slot slotIndex. */
s32 fn_801B3050(s32 slotIndex) {
    return *(s32 *)((u8 *)sDeitySlotBase + (slotIndex << 7) + DEITY_SLOT_RANK);
}

extern f32 fn_801B3064(void);
f32 fn_801B3064(void) {
    return lbl_8055E6A4;
}

extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
f32 fn_801B306C(void) {
    register f32 currentTime = lbl_8055E3C8;
    /* Time remaining until the active event's deadline (deadline - now). */
    return lbl_8055E6AC - currentTime;
}

void* fn_801B307C(void) {
    /* lbl_8055E694 holds the highest step counter any state has reached (a
     * running maximum reset by fn_801B265C, used as a progress snapshot);
     * return it. */
    #define sMaxStepCount lbl_8055E694
    return sMaxStepCount;
    #undef sMaxStepCount
}

#pragma cplusplus on
extern "C" void fn_801B3084(void *entityA, void *entityB, s32 pos, s32 vec) {
    /* Contact-event forwarder: if the primary object exists, read each entity's id
       (+0x1EC) and pass both ids plus the contact position/vector to its virtual
       handler. */
    Dummy_801B3084 *manager = (Dummy_801B3084 *)gPrimaryObject;
    if (manager != 0) {
        manager->func(*(s32 *)((u8 *)entityA + 0x1EC), *(s32 *)((u8 *)entityB + 0x1EC), pos, vec);
    }
}
#pragma cplusplus off
extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
#pragma dont_inline on
/* Update the deity (AI truck) in the 0x80-byte slot at slotIndex, forwarding arg1/arg2 to its position renderer. */
void fn_801B30C0(s32 slotIndex, s32 arg1, s32 arg2) {
    fn_801B18B8((void *)((u8 *)lbl_8055E684 + (slotIndex << 7)), arg1, arg2);
}
#pragma dont_inline reset
/* Run one processing pass over the 0x80-byte AI-truck (deity) slot at
   `slotIndex` in the slot table based at lbl_8055E684. */
void fn_801B30D0(s32 slotIndex) {
    fn_801B196C((s32)((u8 *)lbl_8055E684 + (slotIndex << 7)), (s32)lbl_8055E684);
}

#pragma cplusplus on
extern "C" void fn_801B30E0(s32 recordIndex) {
    /* For the record at recordIndex, find the node in its parent's circular list whose value at
       +0x10 is closest to the reference node's value, then pass the scaled position data to
       fn_801353C8 along with that closest node. */
    void *record = (u8 *)lbl_8055E684 + (recordIndex << 7);
    void *header = ((Dummy_801B30E0 *)record)->d5();
    void *referenceNode = *(void **)((u8 *)record + 0x40);
    void *closestNode;
    if (referenceNode != 0) {
        void *parent = *(void **)((u8 *)header + 0x2C);
        void *firstNode;
        s32 referenceValue = *(s32 *)((u8 *)referenceNode + 0x10);
        void *currentNode = *(void **)((u8 *)parent + 0x1C);
        s32 bestDiff = 0x7FFFFFFF;
        firstNode = currentNode;
        closestNode = 0;
        do {
            s32 difference = *(s32 *)((u8 *)currentNode + 0x10) - referenceValue;
            s32 absDiff = difference < 0 ? -difference : difference;
            if (absDiff < bestDiff) {
                bestDiff = absDiff;
                closestNode = currentNode;
            }
            currentNode = *(void **)((u8 *)currentNode + 0x14);
        } while (currentNode != firstNode);
    } else {
        closestNode = 0;
    }
    {
        void *data = ((Dummy_801B30E0 *)record)->d6();
        f32 scale = *(f32 *)((u8 *)data + 0x5BC);
        f32 scaleX = *(f32 *)((u8 *)data + 0x54) * scale;
        f32 scaleZ = *(f32 *)((u8 *)data + 0x5C) * scale;
        f32 scaleY = *(f32 *)((u8 *)data + 0x58) * scale;
        f32 x = *(f32 *)((u8 *)data + 0x94) + scaleX;
        f32 y = *(f32 *)((u8 *)data + 0x98) + scaleY;
        f32 z = *(f32 *)((u8 *)data + 0x9C) + scaleZ;
        f32 slots[5];
        slots[2] = x;
        slots[3] = y;
        slots[4] = z;
        slots[0] = x;
        slots[1] = z;
        ((void (*)(void *, f32 *, s32, void *, f32, f32, f32, f32, f32, f32))fn_801353C8)(
            header, slots, 0, closestNode, scaleZ, y, scaleY, x, scaleX, scale);
    }
}
#pragma cplusplus off

#pragma push
#pragma processor 750
/* Log deity-stuff qualify info for entryIndex and store id/float into the entry table at lbl_8055E684. */
void fn_801B3208(s32 entryIndex, s32 id, f32 qualifyValue) {
    ((void (*)(const char *, ...))fn_802E317C)(lbl_80335BD8, entryIndex, id, qualifyValue);
    *(s32 *)((u8 *)lbl_8055E684 + (entryIndex << 7) + 0x6C) = id;
    *(f32 *)((u8 *)lbl_8055E684 + (entryIndex << 7) + 0x24) = qualifyValue;
}
#pragma pop
/* Constant predicate (returns 0 / false); likely a virtual getter reached through a dispatch table. */
s32 fn_801B327C(void) { return 0; }

void fn_801B3284(void) {

}

u8 fn_801B3288(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

u32 fn_801B3290(void) {
    /* Constant predicate (returns 1 / true); likely a virtual getter reached through a dispatch table. */
    return 1;
}

void fn_801B3298(void) {

}
#pragma cplusplus on
struct D801B0C78 { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void *h(); virtual void *i(); };
#pragma cplusplus off
