// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "revolution/MTX/vec.h"

extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern void *fn_8012850C(s32, const char *);
extern void *fn_8002F37C(void *, void (*)(void), void *, s32, s32);
extern void *fn_802CE3A4(s32, s32, s32);
extern s32 fn_802CE630(void *, const char *, s32);
extern void fn_802E30C8(const char *, ...);
extern void fn_802025D4(void);
extern int sprintf(char *, const char *, ...);
extern char lbl_8033B9F8[];
extern char lbl_804888B8[];
extern char lbl_8055B418;
extern char lbl_8055B420;
extern float lbl_805630A4;
extern int lbl_8055B414, lbl_8055ECDC;
extern int lbl_8055ECC0;
extern int lbl_8055ECC4;
extern int lbl_8055ECC8;
extern int lbl_8055ECCC;
extern int lbl_8055ECD0;
extern unsigned char lbl_8055ECE0;
extern void fn_802CE6C0(int);
extern int fn_802CE49C(int);
extern int fn_802CE850(int);
extern int fn_80128670(int);
extern void *fn_801E87A8(void);
extern int fn_802C9C58(int);
extern void fn_802C7A44(void);
extern int fn_802C7040(int);
extern void fn_802C7A50(void);
extern float lbl_805630A0;
extern unsigned char lbl_80488964[];
extern void fn_802C6CF8(int);

/* Model transform handed to fn_802C70AC: a 3x3 basis stored as three column
 * Vecs, followed by the translation. */
struct ModelTransform {
    Vec basis[3];
    Vec translate;
};

/* lbl_804888E0: the models picked out for this frame by fn_80202718 - up to
 * 0x20 model ids followed by their count (at +0x80). */
struct ModelIdList {
    s32 id[0x20];
    s32 count;
};

extern int lbl_8055B410;
extern int lbl_8055ECD4;
extern int fn_801E85A4(void);
extern int fn_8012C33C(void);
extern int fn_802C6FC0(int, int, int);
#pragma push
#pragma dont_inline on
int fn_80202218(void) {
    if (fn_801E85A4() == 1) {
        return lbl_8055ECD4;
    }
    return lbl_8055B410;
}
#pragma pop

int fn_80202248(int arg0) {
    int result = -1;
    if (fn_8012C33C() != 0) {
        result = fn_802C6FC0(arg0, 0, 0);
    }
    return result;
}

#pragma push
#pragma dont_inline on
void fn_802022A0(int *arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -1) {
        fn_802C6CF8(temp_r0);
        *arg0 = -1;
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_802022E4(const Vec *arg0) {
    float bestDist = lbl_805630A0;
    int offset = 0;
    int best = 0;
    int i = 0;
    while (i < lbl_8055ECC0) {
        float d = PSVECSquareDistance(arg0, (const Vec *)((char *)lbl_8055ECC4 + offset));
        if (d < bestDist) {
            bestDist = d;
            best = i;
        }
        offset += 0x10;
        i++;
    }
    return best;
}
#pragma pop

#pragma push
#pragma dont_inline on
int fn_80202378(int arg0, int arg1, int arg2, int arg3) {
    if (arg3 >= lbl_8055ECC0) return -1;
    if (arg3 >= (arg1 * 2) + 1) return -1;
    return ((arg2 * (arg3 - arg1)) + ((lbl_8055ECC0 * 0x64) + arg0)) % lbl_8055ECC0;
}

#pragma pop
void *fn_802023C8(void) { return lbl_80488964; }

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma dont_inline on
extern "C" void fn_802023D4(void) {
    struct Manager { virtual void *get(void *); };
    struct Position { f32 x, y, z; };
    struct Interface {
        virtual void f0(); virtual void f1(); virtual void f2();
        virtual void f3(); virtual void f4(); virtual s32 getCount(void *);
        virtual void f6(); virtual void f7(); virtual void f8();
        virtual void f9(); virtual void f10();
        virtual Position getPosition(const char *);
    };
    register char *config;
    register char *state;
    register s32 offset;
    register void *manager;
    register void *interface;
    register s32 count;
    register s32 i;
    register s32 size;
    register f32 *position_defaults;
    register s32 *flags;
    register s32 *last_flag;
    s32 *entry;
    char name1[32];
    char name2[32];
    void *buffer;

    config = lbl_8033B9F8;
    lbl_8055ECD4 = 7;
    state = lbl_804888B8;
    manager = fn_80131808(config);
    interface = ((Manager *)manager)->get(config + 0x10);
    count = ((Interface *)interface)->getCount(&lbl_8055B418);
    lbl_8055ECC0 = count;
    if (count > 0) {
        size = count << 4;
        buffer = fn_8012850C(size + 0x10, config + 0x1C);
        lbl_8055ECC4 = (s32)fn_8002F37C(buffer, fn_802025D4, NULL, 0x10, lbl_8055ECC0);
        lbl_8055ECC8 = (s32)fn_802CE3A4(lbl_8055ECC0, 0x20, 0x20000);
        i = 0;
        offset = 0;
        while (i < lbl_8055ECC0) {
            entry = (s32 *)((char *)lbl_8055ECC4 + offset);
            sprintf(name1, (const char *)&lbl_8055B420, i);
            const Position &position = ((Interface *)interface)->getPosition(name1);
            ((f32 *)entry)[0] = position.x;
            ((f32 *)entry)[1] = position.y;
            ((f32 *)entry)[2] = position.z;
            sprintf(name2, config + 0x28, i);
            entry[3] = fn_802CE630((void *)lbl_8055ECC8, name2, 0);
            offset += 0x10;
            i++;
        }
    } else {
        lbl_8055ECC4 = 0;
        lbl_8055ECC8 = 0;
    }
    fn_80131818(manager);
    lbl_8055ECCC = fn_80202248((int)(config + 0x34));
    if (lbl_8055ECCC != -1) fn_802E30C8(config + 0x44);
    lbl_8055ECD0 = fn_80202248((int)(config + 0x5C));
    if (lbl_8055ECD0 != -1) fn_802E30C8(config + 0x6C);
    position_defaults = (f32 *)(state + 0xAC);
    flags = (s32 *)(state + 0x18);
    last_flag = (s32 *)(state + 0x28);
    lbl_8055B414 = -1;
    position_defaults[0] = lbl_805630A4;
    position_defaults[1] = lbl_805630A4;
    position_defaults[2] = lbl_805630A4;
    lbl_8055ECE0 = 0;
    lbl_8055ECDC = -1;
    flags[0] = -1;
    flags[1] = -1;
    flags[2] = -1;
    flags[3] = -1;
    last_flag[0x20] = 0;
}
#pragma cplusplus reset
#pragma pop

void fn_802025D4(void) {

}

void fn_802025D8(void) {
    extern int lbl_8055ECC0;
    extern int lbl_8055ECC4;
    extern int lbl_8055ECC8;
    extern int lbl_8055ECCC;
    extern int lbl_8055ECD0;
    extern int lbl_804888E0[];
    extern void fn_802022A0(int *);
    extern void fn_802CE6C0(int);
    extern int fn_802CE49C(int);
    extern int fn_80128670(int);
    int offset;
    int count;

    fn_802022A0(&lbl_8055ECD0);
    fn_802022A0(&lbl_8055ECCC);
    count = 0;
    offset = 0;
    goto test;
loop:
    fn_802CE6C0(*(int *)((char *)lbl_8055ECC4 + offset + 12));
    offset += 0x10;
    count += 1;
test:
    if (count < lbl_8055ECC0)
        goto loop;
    if (lbl_8055ECC0 > 0) {
        fn_802CE49C(lbl_8055ECC8);
        lbl_8055ECC8 = 0;
        if (lbl_8055ECC4 != 0)
            fn_80128670(lbl_8055ECC4 - 0x10);
        lbl_8055ECC4 = 0;
    }
    lbl_8055ECC0 = 0;
    lbl_804888E0[0x20] = 0;
}

void fn_8020268C(void) {
    int saved;
    unsigned int flags = *(unsigned int *)((char *)fn_801E87A8() + 16);
    int arg = 2;
    if ((flags >> 1) & 1) arg = 1;
    saved = fn_802C9C58(arg);
    if (lbl_8055ECCC != -1) { fn_802C7A44(); fn_802C7040(lbl_8055ECCC); fn_802C7A50(); }
    fn_802C9C58(0);
    if (lbl_8055ECD0 != -1) { fn_802C7A44(); fn_802C7040(lbl_8055ECD0); fn_802C7A50(); }
    fn_802C9C58(saved);
}

#pragma scheduling invalid_target
void fn_80202718(int arg0) {
    extern int lbl_804888E0[], lbl_804888D0[];
    extern unsigned char lbl_8055ECD8;
    extern void *fn_802C86DC(void);
    extern int fn_801E85B4(void);
    extern void fn_801E86F8(int);
    extern void *fn_801EA9A0(void);
    extern void fn_801DCEF0(void);
    extern int fn_802CE728(int);
    extern void fn_802C7458(int, int);
    int *rec;
    int i;
    int base;
    int dir;
    int center, result, count;
    int *data;
    float x, y, z;
    float *o;
    Vec local;
    lbl_804888E0[0x20] = 0;
    if (lbl_8055ECD8) {
        void *p;
        fn_801E86F8(-1);
        p = fn_801EA9A0();
        p = *(void **)((char *)p + 8);
        if (*(short *)((char *)p + 0x30) >= 0) fn_801DCEF0();
        return;
    }
    if (lbl_8055ECC0 == 0) {
        fn_8020268C();
        return;
    }
    o = (float *)fn_802C86DC();
    center = fn_802022E4((Vec *)(o + 9));
    lbl_804888D0[fn_801E85B4()] = center;
    data = (int *)(lbl_8055ECC4 + (((center + 1) % lbl_8055ECC0) * 16));
    dir = 1;
    x = ((float *)data)[0] - o[9];
    y = ((float *)data)[1] - o[10];
    z = ((float *)data)[2] - o[11];
    local.x = z * o[2] + (x * o[0] + y * o[1]);
    local.y = z * o[5] + (x * o[3] + y * o[4]);
    local.z = z * o[8] + (x * o[6] + y * o[7]);
    if (local.z < lbl_805630A4) dir = -1;
    base = fn_80202218();
    count = lbl_8055B414;
    if (count >= 0) {
        base = 0;
        center = count;
    }
    for (i = 0; (result = fn_80202378(center, base, dir, i)) >= 0; i++) {
        rec = (int *)(lbl_8055ECC4 + result * 16);
        fn_802CE744(rec[3], 0);
        result = fn_802CE728(rec[3]);
        if (result != -1) {
            fn_802C7458(result, -13);
            count = lbl_804888E0[0x20];
            if ((unsigned int)count < 0x20) {
                lbl_804888E0[count] = result;
                lbl_804888E0[0x20] = count + 1;
            }
        }
    }
    fn_8020268C();
}
#pragma scheduling on
extern int lbl_8055ECDC;
extern int fn_802023E4(void);
extern int fn_80202218(void);
extern void *fn_802023C8(void);
extern int fn_802022E4(const Vec *);
extern int fn_80202378(int, int, int, int);
extern int fn_802CE744(int, int);
extern int fn_802CE4F4(int);
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80202924(void) {
    /* Refresh visible modpool slots around a requested position when enabled, then service the pool. */
    int nearestIndex, baseIndex, iterIndex, slotIndex;
    int *slotRecord;
    Vec requestedPos;

    if (lbl_8055ECC0 <= 0)
        return;
    lbl_8055ECDC = -1;
    if (lbl_8055ECE0 != 0) {
        requestedPos = *(Vec *)fn_802023C8();
        nearestIndex = fn_802022E4(&requestedPos);
        lbl_8055ECDC = nearestIndex;
        baseIndex = fn_80202218();
        iterIndex = 0;
        goto test;
loop:
        slotRecord = (int *)(lbl_8055ECC4 + (slotIndex << 4));
        fn_802CE744(slotRecord[3], 0);
        iterIndex++;
test:
        slotIndex = fn_80202378(nearestIndex, baseIndex, 1, iterIndex);
        if (slotIndex >= 0)
            goto loop;
    }
    lbl_8055ECE0 = 0;
    fn_802CE4F4(lbl_8055ECC8);
}
void fn_802029FC(void) {
    extern double lbl_805630A8;
    extern float lbl_805630A4, lbl_805630B0, lbl_805630B4;
    extern int lbl_804888E0[];
    extern float fn_801E7E18(void);
    extern double fn_8002EFB4();
    extern int fn_802C7A3C(float, float, float);
    extern void fn_802C70AC(int, float *, int, int);
    float values[12];
    float first;
    int *base, *entry;
    int result, index;

    first = fn_801E7E18();
    result = fn_802C7A3C(lbl_805630B0 - (float)fn_8002EFB4(first, lbl_805630A8),
                         lbl_805630A4, lbl_805630B4);
    values[0] = lbl_805630B0;
    values[1] = lbl_805630A4;
    values[2] = lbl_805630A4;
    values[3] = lbl_805630A4;
    values[4] = lbl_805630B0;
    values[5] = lbl_805630A4;
    values[6] = lbl_805630A4;
    values[7] = lbl_805630A4;
    values[8] = lbl_805630B0;
    values[9] = lbl_805630A4;
    values[10] = lbl_805630A4;
    values[11] = lbl_805630A4;
    entry = lbl_804888E0;
    base = entry;
    index = 0;
    goto test;
loop:
    fn_802C70AC(*entry, values, result, 8);
    entry++;
    index++;
test:
    if (index < base[0x20])
        goto loop;
}

#pragma scheduling on
#pragma pop
extern unsigned char lbl_8055ECE0;
extern int lbl_8055ECC8, lbl_8055ECCC, lbl_8055ECD0;
extern int lbl_804888E0[];
extern float lbl_805630A4, lbl_805630B0, lbl_805630B4;
extern double lbl_805630A8;
extern double fn_8002EFB4(double);
extern int fn_802C7A3C(float, float, float);
extern void fn_802C70AC(int, float *, int, int);
int fn_802CE850(int);
void fn_802CE6C0(int);
int fn_802CE49C(int);
int fn_80128670(int);
void fn_802022A0(int *);
void *fn_801E87A8(void);
int fn_802C9C58(int);
void fn_802C7A44(void);
int fn_802C7040(int);
void fn_802C7A50(void);
#pragma push
#pragma scheduling on
#pragma peephole off
void fn_80202AD4(float *arg0) {
    float c, b, a;
    int flag;
    a = arg0[0];
    flag = 1;
    b = arg0[1];
    c = arg0[2];
    ((float *)lbl_80488964)[0] = a;
    ((float *)lbl_80488964)[1] = b;
    ((float *)lbl_80488964)[2] = c;
    lbl_8055ECE0 = flag;
}
#pragma pop
int fn_80202B00(void) {
    extern int lbl_8055ECC0;
    extern int lbl_8055ECC4;
    extern int fn_802CE850(int);
    int offset;
    int count;
    int i;

    if (lbl_8055ECC0 <= 0)
        goto return_zero;
    count = 0;
    i = 0;
    offset = 0;
    goto test;
loop:
    if (fn_802CE850(*(int *)((char *)lbl_8055ECC4 + offset + 12)) == 1)
        count++;
    offset += 16;
    i++;
test:
    if (i < lbl_8055ECC0)
        goto loop;
    return count;
return_zero:
    return 0;
}

