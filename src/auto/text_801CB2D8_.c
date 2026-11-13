#include "revolution/BTE/stack/include/btm_api.h"
extern void *memset(void *, int, unsigned long);
extern void fn_8001BE70(void *);
extern void fn_802AE0E0(void);
extern unsigned int fn_801CE898(void);
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
#pragma cplusplus on
struct DummyBase_801CCDAC { int pad; };
struct Dummy_801CCDAC : DummyBase_801CCDAC { virtual int v0(); virtual int v1(int); virtual int v2(f32); };
static inline int fn_801CD130_dispatch(void *obj, f32 value) { return ((Dummy_801CCDAC *)obj)->v2(value); }
#pragma cplusplus reset
extern f32 lbl_805629E4;
extern f32 lbl_805629FC;
extern f32 lbl_80562A08;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80019BA8(void);
extern int fn_8000DA10(void);
extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_800167F4(void);
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
extern int fn_80128668(void *);
#pragma push
#pragma small_data off
extern char lbl_80338024[];
extern char lbl_80338038[];
#pragma pop
extern int fn_8001BF34(int);
extern void fn_8001BF0C(int, f32);
extern int fn_80161C38(void);
extern void fn_801CD7BC(int, int, f32);
extern s32 *lbl_8055E884;
extern unsigned char *fn_801EA9A0();
extern int fn_801EA994(void);
extern void fn_801CCBA4(void);
extern void fn_801CCAEC(int);
extern void fn_801CCB48(int);
extern void fn_801CCCAC(void);
extern int fn_801CE874(int);
extern void fn_801CCDAC(int, int, int);
extern void fn_801CD130(int, int, f32);
extern void fn_801CD4CC(int, int);
extern signed char lbl_8055E880;
extern void fn_801CEA28(void *);
extern void fn_801CEB94(void *);
typedef struct {
    s32 field0;
    s32 field4;
    s32 field8;
} Struct_801CE670;
void fn_801CDE00(s32);
void fn_801CE6CC(void);
void fn_801CE6A0(void);
void fn_801CE69C(void);
void fn_801CE698(void);
void fn_801CE670(Struct_801CE670*, s32, s32);
void fn_801CE6A4(Struct_801CE670*, s32, s32);
void fn_801CE6D0(Struct_801CE670*, s32, s32);
extern void fn_801CB3F8(void);
extern void fn_801CC470(void);
extern void fn_801CC918(void);
void fn_801CB2D8(void) {
    if (fn_80019BA8() == 0) {
        switch (fn_80161C38()) {
        case 0:
            lbl_8055E880 = 1;
            fn_801CC470();
            fn_801CB3F8();
            break;
        default:
            break;
        }
    }
}

void fn_801CB320(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CC918();
    fn_801CB3F8();
}

void fn_801CB360(int arg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCAEC(arg0);
done:
    return;
}

void fn_801CB3AC(int arg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCB48(arg0);
done:
    return;
}

void fn_801CB3F8(void) {
    int count, i;
    if (fn_80019BA8() || fn_80161C38()) return;
    count = fn_801EA994();
    for (i = 0; i < count; i++) fn_801CCAEC(i);
}

void fn_801CB464(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBA4();
}

extern void fn_801CCBB4(void);
void fn_801CB4A0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBB4();
}

extern void fn_801CCBC4(void);
void fn_801CB4DC(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBC4();
}

void fn_801CB518(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    lbl_8055E880 = 0;
    fn_801CCCAC();
}

/* Queue an award event for a player if awards are active and the player entry is valid. */
void fn_801CB55C(int playerIndex, int param) {
    if (fn_80019BA8() || fn_80161C38()) return;
    if (fn_801CE874(playerIndex)) {
        fn_801CCDAC(0x22205, playerIndex, param);
        fn_801CD4CC(playerIndex, param);
    }
}

extern void fn_801CC918(void);
extern void fn_801CC470(void);
extern void fn_801CD5B4(int, int, int);
#pragma scheduling invalid_target
// fn_801CB5DC matches with invalid_target scheduling to preserve argument-copy order.
void fn_801CB5DC(int arg0, int arg1, int arg2) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD5B4(arg0, arg1, arg2);
done:
    return;
}
#pragma scheduling on
void fn_801CB648(int arg0, int arg1, f32 farg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD7BC(arg0, arg1, farg0);
done:
    return;
}
#pragma scheduling on
void fn_801CB6B4(void) {
    if (fn_80019BA8() == 0) {
        if (fn_80161C38() != 0) return;
    }
}

void fn_801CB6E4(int arg0, int arg1, int arg2) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCDAC(arg0, arg1, arg2);
done:
    return;
}

void fn_801CB750(int arg0, int arg1, f32 farg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD130(arg0, arg1, farg0);
done:
    return;
}

extern void fn_801CD970(int);
void fn_801CB7BC(int arg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD970(arg0);
done:
    return;
}

extern void fn_801CDDCC(void);
void fn_801CB808(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CDDCC();
}

extern void fn_801CE6F8(void);
void fn_801CB844(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CE6F8();
}

s32 fn_801CB880(void) {
    if ((fn_80019BA8() != 0) || (fn_80161C38() != 0)) {
        return 1;
    }
    return fn_801CE75C();
}

extern void fn_801CE7A0(void);
void fn_801CB8C0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CE7A0();
}

void fn_801CB8FC(void) {
    fn_801CE8CC();
}

#pragma dont_inline on
int fn_801CB900(int *arg0, int arg1) {
    int result = 0;
    if (arg0 != 0 && arg1 == fn_8001BD28(*arg0)) {
        result = 1;
    }
    return result;
}
#pragma dont_inline reset

#pragma push
#pragma use_lmw_stmw off
extern char lbl_80337AC8[];
extern char lbl_80338010[];
extern void *fn_801284F8(s32, void *);
extern s32 fn_80012854(void);
extern void *fn_8001C070(void *, s32, s32, s32, s32);
extern void *fn_8001BE94(void *, s32, s32, s32, s32);
extern void fn_8001BC38(void *, s32, s32, s32, s32);
extern s32 fn_8001BCF0(void *);
extern s32 fn_8001BD6C(void *, void *);
extern void fn_802E317C(char *, s32);
void *fn_801CB954(s32 arg0, void *arg1, s32 arg2) {
 s32 mode=arg0&0x300; void *result,*item; s32 i,j,best,best2; s32 sp[9],sp2[9],sp3[9];
 switch (mode) {
 case 0x200:
  result=fn_801284F8(0x10,lbl_80337AC8+0x40); if(!result)return result;
  item=fn_801284F8(0x24,lbl_80337AC8+0x4C);
  if(item)item=fn_8001C070(item,fn_8000DA10(),arg0,*(s32*)arg1,*(s32*)((char*)arg1+4));
  *(void**)result=item; *(void**)((char*)result+4)=lbl_80338024; *(void**)((char*)result+8)=0; *(s32*)((char*)result+0xC)=0;
  best=-1;best2=-1;
  for(j=0;j<3;j++)for(i=0;i<fn_80012854();i++){
   if(i==*(s32*)arg1&&j==*(s32*)((char*)arg1+4))continue;
   fn_8001BC38(sp,fn_8000DA10(),arg0,i,j);
   if(fn_8001BCF0(sp)){if(best<0){best=i;best2=j;}else{fn_8001BC38(sp2,fn_8000DA10(),arg0,best,best2);if(fn_8001BD6C(sp,sp2)){best=i;best2=j;}}}
  }
  if(best>=0){item=fn_801284F8(0x24,lbl_80337AC8+0x4C);if(item)item=fn_8001C070(item,fn_8000DA10(),arg0,best,best2);*(void**)((char*)result+8)=item;}
  return result;
 case 0x100:
  result=fn_801284F8(0x10,lbl_80337AC8+0x58);if(!result)return result;
  item=fn_801284F8(0x24,lbl_80337AC8+0x64);
  if(item)item=fn_8001BE94(item,fn_8000DA10(),arg0,*(s32*)arg1,*(s32*)((char*)arg1+4));
  *(void**)result=item;*(void**)((char*)result+4)=lbl_80338010;*(void**)((char*)result+8)=0;*(s32*)((char*)result+0xC)=0;
  best=-1;best2=-1;
  for(j=0;j<3;j++)for(i=0;i<fn_80012854();i++){
   if(i==*(s32*)arg1&&j==*(s32*)((char*)arg1+4))continue;
   fn_8001BC38(sp3,fn_8000DA10(),arg0,i,j);
   if(fn_8001BCF0(sp3)){if(best<0){best=i;best2=j;}else{fn_8001BC38(sp2,fn_8000DA10(),arg0,best,best2);if(fn_8001BD6C(sp3,sp2)){best=i;best2=j;}}}
  }
  if(best>=0){item=fn_801284F8(0x24,lbl_80337AC8+0x64);if(item)item=fn_8001BE94(item,fn_8000DA10(),arg0,best,best2);*(void**)((char*)result+8)=item;}
  return result;
 default:
  fn_802E317C(lbl_80337AC8,arg0); return 0;
 }
}
#pragma pop

void *__dt__Q34nw4r2ef6EffectFv_801CBCA4(void *arg0, int arg1) {
    extern void fn_801CBD04(void *);
    if (arg0) {
        *(void **)((char *)arg0 + 4) = lbl_80338038;
        fn_801CBD04(arg0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801CBD04(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

/* Bounded string copy the game inlines everywhere: copies src into dst including the
   terminator, at most n bytes; when n runs out the last byte written is replaced by 0. */
#define STRNCPY_801CBD48(dst, src, n)              \
    do {                                           \
        char *d_ = (char *)(dst);                  \
        const char *s_ = (const char *)(src);      \
        int n_ = (n);                              \
        for (;;) {                                 \
            char c_ = *s_++;                       \
            *d_++ = c_;                            \
            if (c_ == 0) break;                    \
            if (--n_ <= 0) { d_[-1] = 0; break; }  \
        }                                          \
    } while (0)
extern void *fn_8001285C(s32);
extern char *fn_80131234(char *);
extern void fn_80130978(void *, s32, f32);
extern void fn_801308F4(void *, s32, s32);
extern char *__AXGetStackHead(s32);
extern f32 fn_8001BEE8(void *);
extern void fn_8001BB0C(int, s32, s32);
extern char *fn_8000DB34(int);
extern void fn_802ADFF4(s32, s32);
extern void fn_802AE02C(s32, s32);
extern void fn_802AE168(s32);
extern f32 lbl_805629E0;
extern f32 lbl_805629E8;
extern f32 lbl_805629EC;
extern f32 lbl_805629F0;
extern f32 lbl_805629F4;
extern f32 lbl_805629F8;
extern f32 lbl_80562A00;
#pragma push
#pragma dont_inline on
void fn_801CBD48(void *arg0, void *arg1) {
}
#pragma pop

extern int fn_80145E70(void *);
extern int fn_8001BA74(int);
extern void fn_801CC8FC(void *);
extern void fn_801CC8EC(void *);
extern void *fn_801CC7A0(void *);
extern void **fn_801CC784(void *);
extern void *fn_801CB954();
extern void fn_801CC768(void *, float);
extern void fn_801CC594(void *);
extern void *fn_80207848(void *, int);
extern void *fn_8023512C(void *);
extern float lbl_80562A04;
void fn_801CC470(void) {
    register void *object; register int i; s32 *table; register void *item; void **slot; void *field;;;;;;
    object = fn_801284F8(0x618, lbl_80337AC8 + 0x190);
    if (object != 0) {
        fn_801CC8FC((char *)object + 0x18);
        fn_801CC8EC((char *)object + 0x29C);
        fn_801CC7A0((char *)object + 0x2C0);
        *(int *)((char *)object + 0x40) = fn_80145E70(lbl_80337AC8 + 0x19C);
        *(int *)((char *)object + 0x2A4) = fn_80145E70(lbl_80337AC8 + 0x1AC);
        *((unsigned char *)object + 0x10) = 0;
        table = __AXFXGetLfoSinTable_801769CC();
        *(s32 *)object = table[0]; *((s32 *)object + 1) = table[2];
        *((unsigned char *)object + 0x11) = 1; *((unsigned char *)object + 0x12) = 1;
        *((unsigned char *)object + 0x13) = 1; *((unsigned char *)object + 0x14) = 1;
        i = 1;
        do {
            int mode = fn_8001BA74(i);
            item = ((void *(*)(int, void *))fn_801CB954)(mode, object);
            slot = fn_801CC784((char *)object + 0x18);
            i++; *slot = item;
        } while (i <= 7);
        field = fn_80207848(lbl_80337AC8 + 0x1BC, 1);
        *(void **)((char *)object + 8) = field;
        if (field != 0) fn_801CC768(field, lbl_80562A04);
        *(void **)((char *)object + 0xC) = fn_8023512C(lbl_80337AC8 + 0x1C8);
        fn_801CC594(object);
    }
    lbl_8055E884 = (s32 *)object;
}

#pragma scheduling invalid_target
void fn_801CC594(void *arg0) {
    u8 *base = (u8 *)arg0;
    register s32 offset;
    register s32 index;
    s32 minusOne;
    void *entry;
    void *object;
    f32 floatE4;
    f32 floatFC;
    f32 floatA08;
    void *field;
    if (base[0x10] != 0) return;
    index = 0;
    offset = 0;
    while (index < *(s32 *)(base + 0x1C)) {
        entry = *(void **)((u8 *)*(void **)(base + 0x18) + offset);
        if (entry != 0) fn_8001BE70(*(void **)entry);
        offset += 4;
        ++index;
    }
    *(void **)(base + 0x2A0) = base + 0x29C;
    offset = 0;
    *(s32 *)(base + 0x29C) = offset;
    memset(base + 0x44, offset, 0x258);
    floatE4 = lbl_805629E4;
    floatFC = lbl_805629FC;
    minusOne = -1;
    floatA08 = lbl_80562A08;
    *(s32 *)(base + 0x2A8) = offset;
    *(s32 *)(base + 0x2AC) = offset;
    *(s32 *)(base + 0x2B0) = minusOne;
    *(s32 *)(base + 0x2B4) = minusOne;
    *(f32 *)(base + 0x2B8) = floatA08;
    base[0x2BC] = offset;
    *(s32 *)(base + 0x2C0) = offset;
    *(f32 *)(base + 0x2C4) = floatFC;
    *(s32 *)(base + 0x2D8) = offset;
    *(f32 *)(base + 0x578) = floatE4;
    *(f32 *)(base + 0x57C) = floatFC;
    *(f32 *)(base + 0x580) = floatFC;
    *(f32 *)(base + 0x584) = floatFC;
    *(f32 *)(base + 0x588) = floatE4;
    *(f32 *)(base + 0x58C) = floatFC;
    *(f32 *)(base + 0x590) = floatFC;
    *(f32 *)(base + 0x594) = floatFC;
    *(f32 *)(base + 0x598) = floatE4;
    *(f32 *)(base + 0x59C) = floatFC;
    *(f32 *)(base + 0x5A0) = floatFC;
    *(f32 *)(base + 0x5A4) = floatFC;
    *(f32 *)(base + 0x5A8) = floatE4;
    *(f32 *)(base + 0x5AC) = floatFC;
    *(f32 *)(base + 0x5B0) = floatFC;
    *(f32 *)(base + 0x5B4) = floatFC;
    *(f32 *)(base + 0x5B8) = floatE4;
    *(f32 *)(base + 0x5BC) = floatFC;
    *(f32 *)(base + 0x5C0) = floatFC;
    *(f32 *)(base + 0x5C4) = floatFC;
    *(f32 *)(base + 0x5C8) = floatE4;
    *(f32 *)(base + 0x5CC) = floatFC;
    *(f32 *)(base + 0x5D0) = floatFC;
    *(f32 *)(base + 0x5D4) = floatFC;
    *(f32 *)(base + 0x5D8) = floatE4;
    *(f32 *)(base + 0x5DC) = floatFC;
    *(f32 *)(base + 0x5E0) = floatFC;
    *(f32 *)(base + 0x5E4) = floatFC;
    *(f32 *)(base + 0x5E8) = floatE4;
    *(f32 *)(base + 0x5EC) = floatFC;
    *(f32 *)(base + 0x5F0) = floatFC;
    *(f32 *)(base + 0x5F4) = floatFC;
    *(f32 *)(base + 0x5F8) = floatE4;
    *(f32 *)(base + 0x5FC) = floatFC;
    *(f32 *)(base + 0x600) = floatFC;
    *(f32 *)(base + 0x604) = floatFC;
    field = *(void **)(base + 0x2C8);
    *(f32 *)(base + 0x608) = floatE4;
    *(f32 *)(base + 0x60C) = floatFC;
    *(f32 *)(base + 0x610) = floatFC;
    *(f32 *)(base + 0x614) = floatFC;
    if (field != 0) fn_802AE0E0();
    object = *(void **)(base + 0x2CC);
    if (object != 0) { *((u8 *)object + 0x4A) = 1; *((u8 *)object + 0x4C) = 0; }
    object = *(void **)(base + 0x2D0);
    if (object != 0) { *((u8 *)object + 0x4A) = 1; *((u8 *)object + 0x4C) = 0; }
    object = *(void **)(base + 0x2D4);
    if (object != 0) { *((u8 *)object + 0x4A) = 1; *((u8 *)object + 0x4C) = 0; }
}
#pragma scheduling on

  void fn_801CC768(void *arg0, float arg1) {
    if (arg1 != *(float *)((char *)arg0 + 8)) {
        *(float *)((char *)arg0 + 8) = arg1;
        *((char *)arg0 + 0x4D) = 1;
    }
}

void **fn_801CC784(void *arg0) {
    s32 index = ((s32 *)arg0)[1];
    s32 *base = *(s32 **)arg0;
    ((s32 *)arg0)[1] = index + 1;
    return (void **)((s32)base + (index << 2));
}

extern void *memset(void *, int, unsigned long);
void *fn_801CC7A0(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char *end = base + 0x14C;
    long zero = 0;
    unsigned char *p = base + 0x20;
    *(long *)(base + 8) = 0;
    *(long *)(base + 0xC) = 0;
    *(long *)(base + 0x10) = 0;
    *(long *)(base + 0x14) = 0;
    do {
        memset(p, 0x7A, 3);
        p[3] = zero;
        memset(p + 0x14, 0x7A, 3);
        p[0x17] = zero;
        memset(p + 0x28, 0x7A, 3);
        p[0x2B] = zero;
        p += 0x3C;
    } while (p < end);
    memset(end, 0x7A, 3);
    base[0x14F] = 0;
    memset(base + 0x160, 0x7A, 3);
    base[0x163] = 0;
    memset(base + 0x174, 0x7A, 3);
    base[0x177] = 0;
    memset(base + 0x188, 0x7A, 3);
    base[0x18B] = 0;
    memset(base + 0x19C, 0x7A, 3);
    base[0x19F] = 0;
    memset(base + 0x200, 0x7A, 3);
    base[0x203] = 0;
    memset(base + 0x264, 0x7A, 3);
    base[0x267] = 0;
    memset(base + 0x276, 0x7A, 3);
    base[0x279] = 0;
    return arg0;
}

void fn_801CC8EC(void *arg0) {
    *(void **)((char *)arg0 + 4) = arg0;
    *(int *)arg0 = 0;
}

void fn_801CC8FC(void *arg0) {
    *(int *)arg0 = (int)((char *)arg0 + 12);
    *(int *)((char *)arg0 + 8) = 7;
    *(int *)((char *)arg0 + 4) = 0;
}

/* The award stat handler kept in lbl_8055E884 (its heap name strings at
 * lbl_80337AC8 read "StatHandler::Create: ..." and "award_int"/"award_real").
 * fn_801CC470 allocates the 0x618 bytes, fn_801CC594 initialises them and
 * fn_801CC918 resets them between races.  Only the fields the functions in this
 * file reach are named; the node pool at 0x44 holds the 0x14-byte stat nodes the
 * free list at 0x29C hands out. */
typedef struct {
    /* 0x00 */ u32 unknown0[4];
    /* 0x10 */ u8 paused;         // fn_801CCBA4 sets it, fn_801CCBB4 clears it
    /* 0x11 */ s8 player[4];      // one byte per player slot
    /* 0x15 */ u8 pad15[3];
    /* 0x18 */ void *entries;     // entryCount stat entries, one pointer each
    /* 0x1C */ s32 entryCount;
    /* 0x20 */ u8 pad20[0x24];
    /* 0x44 */ u8 nodes[0x258];   // stat node pool, cleared by a reset
    /* 0x29C */ void *freeList;   // first free node, null when none
    /* 0x2A0 */ void **freeListTail; // last node's next link, &freeList when empty
    /* 0x2A4 */ s32 unknown2A4;
    /* 0x2A8 */ s32 pendingPlace; // place of the award queued, see fn_801CD4CC
    /* 0x2AC */ s32 newCount;
    /* 0x2B0 */ s32 newEntry;     // -1 while none
    /* 0x2B4 */ s32 unknown2B4;   // -1 while none
    /* 0x2B8 */ f32 value;        // lbl_80562A08 (-999) while unset
    /* 0x2BC */ u8 hasValue;
    /* 0x2BD */ u8 pad2BD[3];
    /* 0x2C0 */ s32 state;        // fn_801CE75C tests it for 3
    /* 0x2C4 */ f32 unknown2C4;
    /* 0x2C8 */ void *pool;       // 0x74-byte records, fn_802AE0E0 clears +0x68
    /* 0x2CC */ void *actor[3];   // a reset sets their +0x4A and clears +0x4C
    /* 0x2D8 */ s32 unknown2D8;
    /* 0x2DC */ u8 pad2DC[0x29C];
    /* 0x578 */ f32 floats[10][4]; // reset to {1,0,0,0}
} StatHandler;

#pragma scheduling invalid_target
/* Resets the award stat handler in lbl_8055E884 between races: hands every entry
 * of the current stat set back to its record, empties the node pool and its free
 * list, and returns the handler's counters, its queued award and the ten float
 * groups at the end of it to their starting values.  The three objects it draws
 * the awards with are told to start over, and the record pool they share is
 * cleared.  Nothing happens while the handler is paused. */
void fn_801CC918(void) {
    void *entry;
    f32 one;
    f32 zero;
    register s32 index;
    register u32 byteOffset;
    f32 unset;
    register StatHandler *handler;
    void *actor;
    void *pool;

    handler = (StatHandler *)lbl_8055E884;
    if (handler->paused != 0) return;
    index = 0;
    byteOffset = 0;
    for (; index < handler->entryCount; byteOffset += 4, ++index) {
        entry = *(void **)((char *)handler->entries + byteOffset);
        if (entry) fn_8001BE70(*(void **)entry);
    }
    /* index is still zero from here on: the reset values are written from it. */
    index = 0;
    handler->freeList = (void *)index;
    handler->freeListTail = &handler->freeList;
    memset(handler->nodes, index, sizeof(handler->nodes));
    handler->pendingPlace = index;
    unset = lbl_80562A08;
    handler->newCount = index;
    zero = lbl_805629FC;
    handler->newEntry = -1;
    one = lbl_805629E4;
    handler->unknown2B4 = -1;
    handler->value = unset;
    handler->hasValue = index;
    handler->state = index;
    handler->unknown2C4 = zero;
    handler->unknown2D8 = index;
    handler->floats[0][0] = one; handler->floats[0][1] = zero;
    handler->floats[0][2] = zero; handler->floats[0][3] = zero;
    handler->floats[1][0] = one; handler->floats[1][1] = zero;
    handler->floats[1][2] = zero; handler->floats[1][3] = zero;
    handler->floats[2][0] = one; handler->floats[2][1] = zero;
    handler->floats[2][2] = zero; handler->floats[2][3] = zero;
    handler->floats[3][0] = one; handler->floats[3][1] = zero;
    handler->floats[3][2] = zero; handler->floats[3][3] = zero;
    handler->floats[4][0] = one; handler->floats[4][1] = zero;
    handler->floats[4][2] = zero; handler->floats[4][3] = zero;
    handler->floats[5][0] = one; handler->floats[5][1] = zero;
    handler->floats[5][2] = zero; handler->floats[5][3] = zero;
    handler->floats[6][0] = one; handler->floats[6][1] = zero;
    handler->floats[6][2] = zero; handler->floats[6][3] = zero;
    handler->floats[7][0] = one; handler->floats[7][1] = zero;
    handler->floats[7][2] = zero; handler->floats[7][3] = zero;
    handler->floats[8][0] = one; handler->floats[8][1] = zero;
    handler->floats[8][2] = zero; handler->floats[8][3] = zero;
    handler->floats[9][0] = one; handler->floats[9][1] = zero;
    handler->floats[9][2] = zero; handler->floats[9][3] = zero;
    pool = handler->pool;
    if (pool != 0) ((void (*)(void *))fn_802AE0E0)(pool);
    actor = handler->actor[0];
    if (actor) {
        *(unsigned char *)((char *)actor + 0x4A) = 1;
        *(unsigned char *)((char *)actor + 0x4C) = 0;
    }
    actor = handler->actor[1];
    if (actor) {
        *(unsigned char *)((char *)actor + 0x4A) = 1;
        *(unsigned char *)((char *)actor + 0x4C) = 0;
    }
    actor = handler->actor[2];
    if (actor) {
        *(unsigned char *)((char *)actor + 0x4A) = 1;
        *(unsigned char *)((char *)actor + 0x4C) = 0;
    }
}
#pragma scheduling on
void fn_801CCAEC(int arg0) {
    int index;
    unsigned char *manager;
    char *base;
    (void)arg0;
    base = (char *)lbl_8055E884;
    manager = fn_801EA9A0();
    if (*manager != 0) {
        index = manager[0xB4] & 3;
    } else {
        index = -1;
    }
    if (index >= 0) {
        *(signed char *)(base + index + 0x11) = 1;
    }
}

void fn_801CCB48(int arg0) {
    int index;
    unsigned char *manager;
    char *base;
    (void)arg0;
    base = (char *)lbl_8055E884;
    manager = fn_801EA9A0();
    if (*manager != 0) {
        index = manager[0xB4] & 3;
    } else {
        index = -1;
    }
    if (index >= 0) {
        *(signed char *)(base + index + 0x11) = 0;
    }
}

void fn_801CCBA4(void) {
    *((s8 *)lbl_8055E884 + 0x10) = 1;
}

void fn_801CCBB4(void) {
    *((signed char *)lbl_8055E884 + 0x10) = 0;
}

extern void fn_8001BDA8(void *);
extern int fn_8001BBB4(s32, s32, void *, s32, s32, f32);
#pragma scheduling invalid_target
void fn_801CCBC4(void) {
    void *awardsState;
    void *entry;
    void *object;
    s32 i;
    s32 offset;

    /* Finalize pending awards: clean up entries, then trigger award playback for the matching object (type 0x50). */
    awardsState = lbl_8055E884;
    if (*(u8 *)((u8 *)awardsState + 0x10) != 0)
        return;

    i = 0;
    offset = 0;
    goto check_first;
first_loop:
    entry = *(void **)(*(u8 **)((u8 *)awardsState + 0x18) + offset);
    if (entry != 0)
        fn_8001BDA8(*(void **)entry);
    offset += 4;
    i += 1;
check_first:
    if (i < *(s32 *)((u8 *)awardsState + 0x1C))
        goto first_loop;

    if (fn_801CE898() != 0)
        return;
    if (*(s32 *)((u8 *)awardsState + 0x2AC) == 0)
        return;

    i = 0;
    goto check_second;
second_loop:
    object = fn_801EA9A0(i);
    if (*(s32 *)((u8 *)object + 0x44) == 0x50) {
        ((int (*)(s32, s32, s32, void *, s32, s32, f32))fn_8001BBB4)(
            fn_8000DA10(), *(s32 *)((u8 *)awardsState + 0), *(s32 *)((u8 *)awardsState + 4), (u8 *)object + 0x48,
            *(s32 *)((u8 *)awardsState + 0x2AC), *(s32 *)((u8 *)awardsState + 0x2B0),
            *(f32 *)((u8 *)awardsState + 0x2B8));
        return;
    }
    i += 1;
check_second:
    if (i < fn_801EA994())
        goto second_loop;
}
#pragma scheduling on
extern void fn_80235380(void);
extern void deleteThreads__6SystemFv(void *);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801CCCAC(void) {
    /* Tear down the global manager state (lbl_8055E884): release active/ref-counted
       handle, destroy owned first/element objects via vtable slot 2, delete embedded
       thread groups at +0x40/+0x2A4, clear the items list, free the state, and null
       the global. */
    struct FirstObject { virtual void destroy(int); };
    struct ElementBase { int pad; };
    struct ElementObject : ElementBase { virtual void destroy(int); };
    struct ManagerState {
        char pad0[8];
        void *firstObject;
        int activeHandle;
        char pad10[8];
        void **items;
        int itemCount;
        int field20;
    };
    int i;
    int offset;
    int activeHandle;
    ElementObject *element;
    FirstObject *firstObject;
    ManagerState *manager;
    int *managerWords;

    manager = (ManagerState *)lbl_8055E884;
    if (manager != 0) {
        activeHandle = manager->activeHandle;
        if (activeHandle != 0) ((void (*)(int))fn_80235380)(activeHandle);
        manager->activeHandle = 0;
        firstObject = (FirstObject *)manager->firstObject;
        if (firstObject != 0) {
            if (firstObject != 0) firstObject->destroy(1);
        }
        deleteThreads__6SystemFv((char *)manager + 0x40);
        deleteThreads__6SystemFv((char *)manager + 0x2A4);
        i = 0;
        offset = 0;
        while (i < manager->itemCount) {
            element = (ElementObject *)((char *)manager->items + offset);
            element = *(ElementObject **)element;
            if (element != 0) element->destroy(1);
            offset += 4;
            i++;
        }
        manager->itemCount = 0;
        managerWords = (int *)manager;
        if (&managerWords[6] != 0) {
            if (&managerWords[6] != 0) {
                manager->items = 0;
                manager->itemCount = 0;
                manager->field20 = 0;
            }
        }
        fn_80128668(manager);
    }
    lbl_8055E884 = 0;
}
#pragma scheduling on
#pragma cplusplus reset
extern char lbl_80337CA0[];
extern f32 lbl_805629F0;
extern f32 lbl_80562A0C;
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801CCDAC(int arg0, int arg1, int arg2) {
s32 *temp_r31;
register s32 var_r30;
register s32 var_r29;
s32 var_r0;
s32 var_r0_2;
register s32 var_ctr;
register s32 var_r3;
s32 temp_r3_2, temp_r3_3, temp_r3_4, temp_r3_5, temp_r3_6;
unsigned char *temp_r30;
void *temp_r3;
unsigned char *temp_r3_7;
unsigned char *temp_r0;
unsigned char *temp_r4;
unsigned char *temp_r7;
unsigned char *temp_r7_2, *temp_r7_3, *temp_r7_4, *temp_r7_5;
register unsigned char *var_r4;
register unsigned char *var_r5;
register unsigned char *var_r6;
register unsigned char *var_r7;

if ((fn_801CE898() == 0) &&
(temp_r31 = lbl_8055E884, (*(unsigned char *)((unsigned char *)temp_r31 + 0x10) == 0))) {
temp_r3 = ((void *(*)(s32))fn_801EA9A0)(arg1);
if (*(unsigned char *)temp_r3 != 0)
var_r0 = *(unsigned char *)((unsigned char *)temp_r3 + 0xB4) & 3;
else
var_r0 = -1;
if (var_r0 >= 0)
var_r0_2 = *(unsigned char *)((unsigned char *)temp_r31 + var_r0 + 0x11);
else
var_r0_2 = 1;
if (var_r0_2 == 0) {
var_r30 = 0;
var_r29 = 0;
for (; var_r30 < *(s32 *)((unsigned char *)temp_r31 + 0x1C); ) {
if (fn_801CB900(*(int **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r29 / 4), arg0) == 0)
goto cont_inc;
goto after_search;
cont_inc:
var_r29 += 4;
var_r30 += 1;
}
var_r30 = -1;
after_search:
if (var_r30 < 0)
((void (*)(const char *, ...))fn_802E317C)(lbl_80337CA0, arg0);
temp_r30 = (unsigned char *)*(void **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r30);
if (temp_r30 != 0) {
if (((Dummy_801CCDAC *)temp_r30)->v1(arg2) != 0) {
var_r6 = (unsigned char *)temp_r31;
var_r7 = (unsigned char *)temp_r31 + 0x44;
var_r4 = 0;
var_r5 = 0;
var_r3 = 0;
for (var_ctr = 0; var_ctr < 5; var_ctr++) {
if (*(unsigned char *)(var_r6 + 0x44) == 0) {
var_r5 = var_r7;
goto block_24;
}
if (*(void **)(var_r6 + 0x4C) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + var_r3 * 0x14 + 0x44;
goto scan_done;
} else {
block_24:
temp_r7 = var_r7 + 0x14;
temp_r3_2 = var_r3 + 1;
if (*(unsigned char *)(var_r6 + 0x58) == 0) {
var_r5 = temp_r7;
goto block_28;
}
if (*(void **)(var_r6 + 0x60) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_2 * 0x14 + 0x44;
goto scan_done;
} else {
block_28:
temp_r7_2 = temp_r7 + 0x14;
temp_r3_3 = temp_r3_2 + 1;
if (*(unsigned char *)(var_r6 + 0x6C) == 0) {
var_r5 = temp_r7_2;
goto block_32;
}
if (*(void **)(var_r6 + 0x74) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_3 * 0x14 + 0x44;
goto scan_done;
} else {
block_32:
temp_r7_3 = temp_r7_2 + 0x14;
temp_r3_4 = temp_r3_3 + 1;
if (*(unsigned char *)(var_r6 + 0x80) == 0) {
var_r5 = temp_r7_3;
goto block_36;
}
if (*(void **)(var_r6 + 0x88) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_4 * 0x14 + 0x44;
goto scan_done;
} else {
block_36:
temp_r7_4 = temp_r7_3 + 0x14;
temp_r3_5 = temp_r3_4 + 1;
if (*(unsigned char *)(var_r6 + 0x94) == 0) {
var_r5 = temp_r7_4;
goto block_40;
}
if (*(void **)(var_r6 + 0x9C) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_5 * 0x14 + 0x44;
goto scan_done;
} else {
block_40:
temp_r7_5 = temp_r7_4 + 0x14;
temp_r3_6 = temp_r3_5 + 1;
if (*(unsigned char *)(var_r6 + 0xA8) == 0) {
var_r5 = temp_r7_5;
goto block_44;
}
if (*(void **)(var_r6 + 0xB0) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_6 * 0x14 + 0x44;
goto scan_done;
} else {
block_44:
var_r6 += 0x78;
var_r7 = temp_r7_5 + 0x14;
var_r3 = temp_r3_6 + 1;

}
}
}
}
}
}
}
scan_done:
if (var_r4 != 0) {
*(f32 *)(var_r4 + 4) = lbl_805629F0;
if (var_r4[1] != 0)
*(f32 *)(var_r4 + 4) = *(f32 *)(var_r4 + 4) - lbl_80562A0C;
} else {
if (var_r5 == 0) {
temp_r3_7 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 0x29C);
var_r5 = 0;
if (temp_r3_7 != 0) {
temp_r0 = (unsigned char *)*(void **)(temp_r3_7 + 0x10);
var_r5 = temp_r3_7;
*(void **)((unsigned char *)temp_r31 + 0x29C) = temp_r0;
if (temp_r0 == 0)
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)((unsigned char *)temp_r31 + 0x29C);
*(void **)((unsigned char *)temp_r3_7 + 0x10) = 0;
}
}
*var_r5 = 1;
var_r5[1] = 0;
*(f32 *)(var_r5 + 4) = lbl_805629F0;
*(void **)(var_r5 + 8) = temp_r30;
temp_r4 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 8);
if (temp_r4 != 0) {
*((unsigned char *)temp_r4 + 0x49) = 1;
*((unsigned char *)temp_r4 + 0x4B) = 0;
*((unsigned char *)temp_r4 + 0x4A) = 0;
}
*(void **)(*(void ***)((unsigned char *)temp_r31 + 0x2A0)) = var_r5;
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)(var_r5 + 0x10);
*(s32 *)(var_r5 + 0x10) = 0;
}
}
}
}
}
}
#pragma cplusplus reset
#pragma pop
extern char lbl_80337CCC[];
#pragma push
#pragma scheduling invalid_target
s32 fn_801CD100(void) {
    ((void (*)(const char*, ...))fn_802E317C)(lbl_80337CCC);
    return 0;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma paired_single off
#pragma cplusplus on
#pragma paired_single off
extern "C" void fn_801CD130(int arg0, int arg1, f32 farg0) {
s32 *temp_r31;
register s32 var_r29;
register s32 var_r30;
register s32 var_r0;
register s32 var_r0_2;
register s32 var_ctr;
register unsigned char *var_r3;
s32 temp_r3_2, temp_r3_3, temp_r3_4, temp_r3_5, temp_r3_6;
register unsigned char *temp_r30;
void *temp_r3;
register unsigned char *temp_r3_7;
register unsigned char *temp_r0;
register unsigned char *temp_r4;
register unsigned char *temp_r7;
unsigned char *temp_r7_2, *temp_r7_3, *temp_r7_4, *temp_r7_5;
register unsigned char *var_r5;
register unsigned char *var_r4;
s32 var_r6;
register unsigned char *var_r7;

if ((fn_801CE898() == 0) &&
(temp_r31 = lbl_8055E884, (*(unsigned char *)((unsigned char *)temp_r31 + 0x10) == 0))) {
temp_r3 = ((void *(*)(s32))fn_801EA9A0)(arg1);
if (*(unsigned char *)temp_r3 != 0)
var_r0 = *(unsigned char *)((unsigned char *)temp_r3 + 0xB4) & 3;
else
var_r0 = -1;
if (var_r0 >= 0)
var_r0_2 = *(unsigned char *)((unsigned char *)temp_r31 + var_r0 + 0x11);
else
var_r0_2 = 1;
if (var_r0_2 == 0) {
var_r29 = 0;
var_r30 = 0;
loop_13:
if (fn_801CB900(*(int **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r29), arg0) == 0) {
var_r29 += 1;
var_r30 += 4;
if (var_r30 < *(s32 *)((unsigned char *)temp_r31 + 0x1C))
goto loop_13;
var_r30 = -1;
}
if (var_r30 < 0)
((void (*)(const char *, ...))fn_802E317C)(lbl_80337CA0, arg0);
temp_r30 = (unsigned char *)*(void **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r30);
if (temp_r30 != 0) {
if (((Dummy_801CCDAC *)temp_r30)->v2(farg0) != 0) {
var_r3 = (unsigned char *)temp_r31;
var_r7 = (unsigned char *)temp_r31 + 0x44;
var_r5 = 0;
var_r4 = 0;
var_r6 = 0;
for (var_ctr = 0; var_ctr < 5; var_ctr++) {
if (*(unsigned char *)(var_r3 + 0x44) == 0) {
var_r4 = var_r7;
goto block_24;
}
if (*(void **)(var_r3 + 0x4C) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + var_r6 * 0x14 + 0x44;
goto scan_done;
} else {
block_24:
temp_r7 = var_r7 + 0x14;
temp_r3_2 = var_r6 + 1;
if (*(unsigned char *)(var_r3 + 0x58) == 0) {
var_r4 = temp_r7;
goto block_28;
}
if (*(void **)(var_r3 + 0x60) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_2 * 0x14 + 0x44;
goto scan_done;
} else {
block_28:
temp_r7_2 = temp_r7 + 0x14;
temp_r3_3 = temp_r3_2 + 1;
if (*(unsigned char *)(var_r3 + 0x6C) == 0) {
var_r4 = temp_r7_2;
goto block_32;
}
if (*(void **)(var_r3 + 0x74) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_3 * 0x14 + 0x44;
goto scan_done;
} else {
block_32:
temp_r7_3 = temp_r7_2 + 0x14;
temp_r3_4 = temp_r3_3 + 1;
if (*(unsigned char *)(var_r3 + 0x80) == 0) {
var_r4 = temp_r7_3;
goto block_36;
}
if (*(void **)(var_r3 + 0x88) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_4 * 0x14 + 0x44;
goto scan_done;
} else {
block_36:
temp_r7_4 = temp_r7_3 + 0x14;
temp_r3_5 = temp_r3_4 + 1;
if (*(unsigned char *)(var_r3 + 0x94) == 0) {
var_r4 = temp_r7_4;
goto block_40;
}
if (*(void **)(var_r3 + 0x9C) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_5 * 0x14 + 0x44;
goto scan_done;
} else {
block_40:
temp_r7_5 = temp_r7_4 + 0x14;
temp_r3_6 = temp_r3_5 + 1;
if (*(unsigned char *)(var_r3 + 0xA8) == 0) {
var_r4 = temp_r7_5;
goto block_44;
}
if (*(void **)(var_r3 + 0xB0) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_6 * 0x14 + 0x44;
goto scan_done;
} else {
block_44:
var_r3 += 0x78;
var_r7 = temp_r7_5 + 0x14;
var_r6 = temp_r3_6 + 1;

}
}
}
}
}
}
}
scan_done:
if (var_r5 != 0) {
*(f32 *)(var_r5 + 4) = lbl_805629F0;
if (var_r5[1] != 0)
*(f32 *)(var_r5 + 4) = *(f32 *)(var_r5 + 4) - lbl_80562A0C;
} else {
if (var_r4 == 0) {
temp_r3_7 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 0x29C);
var_r4 = 0;
if (temp_r3_7 != 0) {
temp_r0 = (unsigned char *)*(void **)(temp_r3_7 + 0x10);
var_r4 = temp_r3_7;
*(void **)((unsigned char *)temp_r31 + 0x29C) = temp_r0;
if (temp_r0 == 0)
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)((unsigned char *)temp_r31 + 0x29C);
*(void **)((unsigned char *)temp_r3_7 + 0x10) = 0;
}
}
*var_r4 = 1;
var_r4[1] = 0;
*(f32 *)(var_r4 + 4) = lbl_805629F0;
*(void **)(var_r4 + 8) = temp_r30;
temp_r4 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 8);
if (temp_r4 != 0) {
*((unsigned char *)temp_r4 + 0x49) = 1;
*((unsigned char *)temp_r4 + 0x4B) = 0;
*((unsigned char *)temp_r4 + 0x4A) = 0;
}
*(void **)(*(void ***)((unsigned char *)temp_r31 + 0x2A0)) = var_r4;
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)(var_r4 + 0x10);
*(s32 *)(var_r4 + 0x10) = 0;
}
}
}
}
}
}
#pragma paired_single reset
#pragma cplusplus reset
#pragma paired_single reset
#pragma pop

#pragma pop

extern char lbl_80337D00[];
#pragma push
#pragma scheduling invalid_target
s32 fn_801CD49C(void) {
    ((void (*)(char *, ...))fn_802E317C)(lbl_80337D00);
    return 0;
}

extern void fn_8001EF5C(int, int);
extern char lbl_80337D34[];
void fn_801CD4CC(int playerIndex, int place) {
    u8 *awardsBase;
    u8 *entry;
    s32 slotIndex;
    u8 slotState;

    /* Queue a pending award place for a player, or abort if one is already pending. */
    if (fn_801CE898() != 0) return;
    awardsBase = (u8 *)lbl_8055E884;
    if (awardsBase[0x10] != 0) return;

    entry = ((u8 *(*)(s32))fn_801EA9A0)(playerIndex);
    if (entry[0] != 0) {
        slotIndex = entry[0xB4] & 3;
    } else {
        slotIndex = -1;
    }

    if (slotIndex >= 0) {
        slotState = awardsBase[slotIndex + 0x11];
    } else {
        slotState = 1;
    }
    if (slotState != 0) return;

    entry = ((u8 *(*)(s32))fn_801EA9A0)(playerIndex);
    if (entry[0] == 0) return;

    if (*(s32 *)(awardsBase + 0x2A8) == 0) {
        *(s32 *)(awardsBase + 0x2A8) = place;
        if (place == 1) fn_8001EF5C(1, 1);
    } else {
        ((void (*)(char *, ...))fn_802E317C)(lbl_80337D34);
    }
}

extern int fn_8001BBB8(int, int, int, float);
extern void fn_8001EFC4(int, void *, int);
extern char lbl_80337D5C[];
extern void fn_8001EFC4();
/* Handles an award/grade push for an object, storing ids/data and starting playback if idle. */
void fn_801CD5B4(int arg0, int arg1, int arg2) {
    unsigned char *awardsBase;
    unsigned char *object;
    int slotIndex;
    int slotStatus;
    void *objectData;
    int current;

    if (fn_801CE898() != 0)
        return;
    awardsBase = (unsigned char *)lbl_8055E884;
    if (awardsBase[0x10] != 0)
        return;

    object = ((unsigned char *(*)(int))fn_801EA9A0)(arg0);
    if (object[0] != 0)
        slotIndex = object[0xB4] & 3;
    else
        slotIndex = -1;
    if (slotIndex >= 0)
        slotStatus = (awardsBase + slotIndex)[0x11];
    else
        slotStatus = 1;
    if (slotStatus != 0)
        return;

    object = ((unsigned char *(*)(int))fn_801EA9A0)(arg0);
    if (object[0] == 0)
        return;
    if (*(int *)(awardsBase + 0x2AC) != 0)
        goto warning;

    *(int *)(awardsBase + 0x2AC) = arg1;
    *(int *)(awardsBase + 0x2B0) = arg2;
    fn_8001EF5C(0, arg1);
    if (*(int *)(awardsBase + 0x2B0) == 0)
        fn_8001EF5C(2, 1);

    object = ((unsigned char *(*)(int))fn_801EA9A0)(arg0);
    objectData = object + 0x88;
    ((void (*)(int, void *, int))fn_8001EFC4)(0, objectData, 1);
    if (arg2 == 0)
        ((void (*)(int, void *, int))fn_8001EFC4)(1, objectData, 1);

    if (*(int *)(awardsBase + 0x2B4) < 0 && awardsBase[0x2BC] != 0) {
        slotIndex = *(int *)(awardsBase + 0x2AC);
        if (slotIndex >= 0) {
            current = fn_8000DA10();
            *(int *)(awardsBase + 0x2B4) =
                ((int (*)(int, int, int, int, float))fn_8001BBB8)(
                    current, *(int *)awardsBase, *((int *)awardsBase + 1), slotIndex,
                    *(float *)(awardsBase + 0x2B8));
        }
    }
    goto done;

warning:
    ((void (*)(char *, ...))fn_802E317C)(lbl_80337D5C);
done:
    return;
}

/* Outputs two cached state values from lbl_8055E884 (+0x2AC, +0x2B0) into the
 * provided pointers, or 0/-1 when the current context is unavailable. */
void fn_801CD730(s32 *outValue0, s32 *outValue1) {
    if (fn_801CE898() != 0) {
        if (outValue0 != 0) *outValue0 = 0;
        if (outValue1 != 0) *outValue1 = -1;
    } else {
        if (outValue0 != 0) *outValue0 = *(s32 *)((u8 *)lbl_8055E884 + 0x2AC);
        if (outValue1 != 0) *outValue1 = *(s32 *)((u8 *)lbl_8055E884 + 0x2B0);
    }
}

extern char lbl_80337D90[];
extern f32 lbl_805629FC;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801CD7BC(int arg0, int arg1, f32 farg0) {
    s32 statusIndex;
    register s32 offset;
    register s32 index;
    u8 *object;
    s32 status;
    u8 *base;
    s32 mapIndex;
    s32 current;
    register s32 id;
    if (fn_801CE898() != 0)
        goto done;
    base = (u8 *)lbl_8055E884;
    if (base[0x10] != 0)
        goto done;
    object = ((u8 *(*)(s32))fn_801EA9A0)(arg0);
    if (object[0] != 0)
        statusIndex = object[0xB4] & 3;
    else
        statusIndex = -1;
    if (statusIndex >= 0)
        status = base[statusIndex + 0x11];
    else
        status = 1;
    if (status != 0)
        goto done;
    object = ((u8 *(*)(s32))fn_801EA9A0)(arg0);
    if (object[0] == 0 || arg1 == 0)
        goto done;
    if (*(f32 *)(base + 0x2B8) < lbl_805629FC) {
        id = 0x20507;
        index = 0;
        offset = 0;
loop:
        if (fn_801CB900(*(int **)((u8 *)*(s32 **)(base + 0x18) + offset), id) == 0)
            goto increment;
        goto found;
increment:
        offset += 4;
        index++;
        if (index < *(s32 *)(base + 0x1C))
            goto loop;
        index = -1;
found:
        if (index < 0)
            ((void (*)(const char *, ...))fn_802E317C)(lbl_80337CA0, id);
        ((Dummy_801CCDAC *)*(void **)((u8 *)*(s32 **)(base + 0x18) + index * 4))->v2(farg0);
        *(f32 *)(base + 0x2B8) = farg0;
        *(u8 *)(base + 0x2BC) = 1;
        if (*(s32 *)(base + 0x2B4) < 0 && *(u8 *)(base + 0x2BC) != 0) {
            mapIndex = *(s32 *)(base + 0x2AC);
            if (mapIndex >= 0) {
                current = fn_8000DA10();
                *(s32 *)(base + 0x2B4) = ((s32 (*)(s32, s32, s32, s32, f32))fn_8001BBB8)(
                    current, *(s32 *)base, *(s32 *)(base + 4), mapIndex, *(f32 *)(base + 0x2B8));
            }
        }
    } else {
        ((void (*)(const char *, f32, ...))fn_802E317C)(
            lbl_80337D90, *(f32 *)(base + 0x2B8), (double)farg0);
    }
done:
    return;
}
#pragma cplusplus reset
#pragma pop

extern f32 lbl_805629E4, lbl_805629F0, lbl_805629FC, lbl_80562A10, lbl_80562A14, lbl_80562A18;
extern s32 lbl_802F9930[3];
extern char lbl_8055AB38[];
extern f32 fn_801E7E24(void);
extern s32 fn_8026B0C0(s32);
extern s32 fn_80204CF0(s32, s32, s32 *);
extern void fn_80148070(void *, s32, s32, f32);
extern s32 fn_8001BA6C(void);
extern s32 fn_801345D8(char *, s32, const char *, ...);
extern void fn_80147230(void *, const char *, void *, ...);
extern void fn_801476C4(void *, f32, f32);
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801CD970(int arg0) {
    typedef struct { s32 field0; f32 field4; s32 field8; s32 fieldC; f32 field10; f32 field14; s32 field18; } DataA;
    typedef struct { s32 field0; f32 field4; s32 field8; s32 fieldC; f32 field10; f32 field14; s32 field18; s32 field1C; } DataB;
    typedef struct { u8 field0; u8 active; u8 pad2[2]; f32 timer; void *data; u32 padC; void *next; } Item;
    void *manager; Item *item;
    f32 threshold, delta, temp, ratio, value, blend, clamp;
    char *strings; void *iface;
    DataA *record0; DataB *recordA, *recordB, *recordC;
    DataB local1; DataA local0;
    char out2[0x10]; s32 choices[3]; char out1[0x40]; char vec[0x14];
    s32 index, zero, active;
    strings = lbl_80337AC8;
    if (fn_801CE898() != 0) return;
    manager = lbl_8055E884;
    if (*(s32 *)((char *)manager + 0x40) == 0) return;
    if (*(s32 *)((char *)manager + 0x29C) == 0) return;
    delta = fn_801E7E24(); threshold = lbl_805629FC; active = 1; zero = 0;
    goto check_head;
process_item:
    if (fn_8026B0C0(arg0) != 0) {
        if (*(u8 *)((char *)item + 1) != 0) {
            if (*(f32 *)((char *)item + 4) < lbl_80562A0C) {
                Item *next = *(Item **)((char *)item + 0x10);
                *(Item **)((char *)manager + 0x29C) = next;
                if (next == 0) *(void **)((char *)manager + 0x2A0) = (char *)manager + 0x29C;
                *(void **)((char *)item + 0x10) = (void *)zero;
                *(f32 *)((char *)item + 4) = lbl_80562A10;
                *(u8 *)item = (u8)zero;
                goto check_head;
            }
            *(f32 *)((char *)item + 4) = lbl_80562A14;
        }
        item = 0; goto render_item;
    }
    *(u8 *)((char *)item + 1) = (u8)active;
    temp = *(f32 *)((char *)item + 4) - delta;
    *(f32 *)((char *)item + 4) = temp;
    if (temp < threshold) {
        Item *next = *(Item **)((char *)item + 0x10);
        *(Item **)((char *)manager + 0x29C) = next;
        if (next == 0) *(void **)((char *)manager + 0x2A0) = (char *)manager + 0x29C;
        *(void **)((char *)item + 0x10) = (void *)zero;
        *(u8 *)item = (u8)zero;
        goto check_head;
    }
    goto render_item;
check_head:
    item = *(Item **)((char *)manager + 0x29C);
    if (item != 0) goto process_item;
    item = 0;
    if (item == 0) return;
render_item:
    if (item != 0) {
        iface = *(void **)((char *)manager + 0x40);
        record0 = ((DataA *(*)(void *, char *))(*(void ***)iface)[5])(iface, strings + 0x310);
        if (record0 != 0) {
            value = *(f32 *)((char *)item + 4);
            if (value >= lbl_80562A0C) value = lbl_805629F0 - value;
            temp = record0->field10;
            ratio = (value - lbl_805629FC) / lbl_80562A0C;
            blend = temp + (lbl_80562A18 - (record0->field4 + temp));
            clamp = lbl_805629E4;
            if (clamp >= ratio) clamp = ratio;
            if (clamp > lbl_805629FC) clamp = lbl_805629FC;
            blend = blend + (clamp * (lbl_805629FC - blend));
            if (record0 != 0) {
                local0.field0 = record0->field0;
                *(s32 *)((char *)&local0 + 4) = *(s32 *)((char *)record0 + 4);
                local0.field8 = record0->field8;
                local0.fieldC = record0->fieldC;
                local0.field10 = record0->field10;
                local0.field14 = record0->field14;
                local0.field18 = record0->field18;
                local0.field4 += blend;
                fn_80148070(&local0, -1, *(s32 *)((char *)manager + 0xC), record0->field14);
            }
            recordA = ((DataB *(*)(void *, char *))(*(void ***)iface)[3])(iface, strings + 0x320);
            choices[0] = lbl_802F9930[0]; choices[1] = lbl_802F9930[1]; choices[2] = lbl_802F9930[2];
            index = fn_80204CF0(lbl_802F9930[1], lbl_802F9930[0], lbl_802F9930);
            recordB = ((DataB *(*)(void *, s32))(*(void ***)iface)[3])(iface, choices[index]);
            recordC = ((DataB *(*)(void *, char *))(*(void ***)iface)[3])(iface, strings + 0x334);
            if (recordA != 0 && recordB != 0 && recordC != 0) {
                local1.field0 = recordA->field0; *(s32 *)((char *)&local1 + 4) = *(s32 *)((char *)recordA + 4); local1.field8 = recordA->field8; local1.fieldC = recordA->fieldC;
                local1.field10 = recordA->field10; local1.field14 = recordA->field14; local1.field18 = recordA->field18; local1.field1C = recordA->field1C;
                local1.field4 += blend;
                fn_8001BD38(*(s32 *)((char *)item->data), vec, 0x14, recordA->field10);
                fn_8001BD28(*(s32 *)((char *)item->data));
                fn_801345D8(out1, 0x40, lbl_8055AB38, fn_8001BA6C());
                fn_801345D8(out2, 0x10, lbl_8055AB38, vec);
                fn_80147230(&local1, lbl_8055AB38, out1);
                local1.field0 = recordB->field0; *(s32 *)((char *)&local1 + 4) = *(s32 *)((char *)recordB + 4); local1.field8 = recordB->field8; local1.fieldC = recordB->fieldC;
                local1.field10 = recordB->field10; local1.field14 = recordB->field14; local1.field18 = recordB->field18; local1.field1C = recordB->field1C;
                local1.field4 += blend;
                fn_80147230(&local1, lbl_8055AB38, out2, recordB->field4, recordB->field10);
                local1.field0 = recordC->field0; *(s32 *)((char *)&local1 + 4) = *(s32 *)((char *)recordC + 4); local1.field8 = recordC->field8; local1.fieldC = recordC->fieldC;
                local1.field10 = recordC->field10; local1.field14 = recordC->field14; local1.field18 = recordC->field18; local1.field1C = recordC->field1C;
                local1.field4 += blend;
                fn_801476C4(&local1, recordC->field4, recordC->field10);
            }
        }
    }
}
void fn_801CDDCC(void) {
    if (fn_801CE898() == 0) {
        fn_801CDE00((s32)lbl_8055E884 + 0x2C0);
    }
}

#pragma dont_inline on
void fn_801CDE00(s32 arg0) {
    extern char lbl_80337AC8[];
    extern char lbl_8055AB30[];
    extern char lbl_8055AB3C[];
    extern char lbl_8055AB40[];
    extern char lbl_8055AB44[];
    extern char lbl_8055AB48[];
    extern char lbl_8055AB4C[];
    extern s32 lbl_802FAA40[];
    extern float lbl_805629E4;
    extern float lbl_805629FC;
    void *tmp;
    s32 s31;
    char *base;
    Struct_801CE670 t5, t4, t3, t2, t1, s30, s29, s28, s27, s26, s25, s24, s23, s22, s21, s20, s19, s18, s17, s16, s15, s14, s13, s12, s11, s10, s9, s8, s7, s6, s5, s4, s3, s2, s1;
    s32 dest[108];
    s32 i;
    base = lbl_80337AC8;
    tmp = fn_801284F8(8, (void *)(base + 0x348));
    if (tmp != 0) tmp = (void *)fn_802ADDD8(0x10);
    *(void **)((char *)arg0 + 8) = tmp;
    s31 = ((s32 (*)())fn_80204CF0)();
    for (i = 0; i < 108; i++) dest[i] = 0;
    fn_801CE6D0(&s1, (s32)(base + 0x358), (s32)((char *)arg0 + 0x18));
    dest[0] = s1.field8; dest[1] = s1.field4; dest[2] = s1.field0;
    fn_801CE6A4(&s2, (s32)(base + 0x368), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x20, s1.field8, s1.field4));
    dest[3] = s2.field8; dest[4] = s2.field4; dest[5] = s2.field0;
    fn_801CE6A4(&s3, (s32)(base + 0x378), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x34, s2.field8, s2.field4));
    dest[6] = s3.field8; dest[7] = s3.field4; dest[8] = s3.field0;
    fn_801CE6A4(&s4, (s32)(base + 0x388), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x48, s3.field8, s3.field4));
    dest[9] = s4.field8; dest[10] = s4.field4; dest[11] = s4.field0;
    fn_801CE6A4(&s5, (s32)(base + 0x398), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x5c, s4.field8, s4.field4));
    dest[12] = s5.field8; dest[13] = s5.field4; dest[14] = s5.field0;
    fn_801CE6A4(&s6, (s32)(base + 0x3a8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x70, s5.field8, s5.field4));
    dest[15] = s6.field8; dest[16] = s6.field4; dest[17] = s6.field0;
    fn_801CE6A4(&s7, (s32)(base + 0x3b8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x84, s6.field8, s6.field4));
    dest[18] = s7.field8; dest[19] = s7.field4; dest[20] = s7.field0;
    fn_801CE6A4(&s8, (s32)(base + 0x3c8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x98, s7.field8, s7.field4));
    dest[21] = s8.field8; dest[22] = s8.field4; dest[23] = s8.field0;
    fn_801CE6A4(&s9, (s32)(base + 0x3d8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xac, s8.field8, s8.field4));
    dest[24] = s9.field8; dest[25] = s9.field4; dest[26] = s9.field0;
    fn_801CE6A4(&s10, (s32)(base + 0x3e8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xc0, s9.field8, s9.field4));
    dest[27] = s10.field8; dest[28] = s10.field4; dest[29] = s10.field0;
    fn_801CE6A4(&s11, (s32)(base + 0x3f8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xd4, s10.field8, s10.field4));
    dest[30] = s11.field8; dest[31] = s11.field4; dest[32] = s11.field0;
    fn_801CE6A4(&s12, (s32)(base + 0x408), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xe8, s11.field8, s11.field4));
    dest[33] = s12.field8; dest[34] = s12.field4; dest[35] = s12.field0;
    fn_801CE6A4(&s13, (s32)(base + 0x418), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xfc, s12.field8, s12.field4));
    dest[36] = s13.field8; dest[37] = s13.field4; dest[38] = s13.field0;
    fn_801CE6A4(&s14, (s32)(base + 0x428), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x110, s13.field8, s13.field4));
    dest[39] = s14.field8; dest[40] = s14.field4; dest[41] = s14.field0;
    fn_801CE6A4(&s15, (s32)(base + 0x438), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x124, s14.field8, s14.field4));
    dest[42] = s15.field8; dest[43] = s15.field4; dest[44] = s15.field0;
    fn_801CE6A4(&s16, (s32)(base + 0x448), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x138, s15.field8, s15.field4));
    dest[45] = s16.field8; dest[46] = s16.field4; dest[47] = s16.field0;
    fn_801CE6A4(&s17, (s32)(base + 0x358), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x14c, s16.field8, s16.field4));
    dest[48] = s17.field8; dest[49] = s17.field4; dest[50] = s17.field0;
    fn_801CE6A4(&s18, (s32)(base + 0x458), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x160, s17.field8, s17.field4));
    dest[51] = s18.field8; dest[52] = s18.field4; dest[53] = s18.field0;
    fn_801CE6A4(&s19, (s32)(base + 0x468), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x174, s18.field8, s18.field4));
    dest[54] = s19.field8; dest[55] = s19.field4; dest[56] = s19.field0;
    fn_801CE6A4(&s20, (s32)(base + 0x474), s31 == 0 ? (s32)((void *(*)(void*))fn_801CE6CC)((char *)arg0 + 0x188) : (s32)lbl_8055AB30);
    dest[57] = s20.field8; dest[58] = s20.field4; dest[59] = s20.field0;
    fn_801CE6A4(&s21, (s32)(base + 0x488), s31 == 1 ? (s32)((void *(*)(void*))fn_801CE6CC)((char *)arg0 + 0x188) : (s32)lbl_8055AB30);
    dest[60] = s21.field8; dest[61] = s21.field4; dest[62] = s21.field0;
    fn_801CE6A4(&s22, (s32)(base + 0x49c), s31 == 2 ? (s32)((void *(*)(void*))fn_801CE6CC)((char *)arg0 + 0x188) : (s32)lbl_8055AB30);
    dest[63] = s22.field8; dest[64] = s22.field4; dest[65] = s22.field0;
    fn_801CE6A4(&s23, (s32)(base + 0x4b0), (s32)((void *(*)(void*,s32,s32))fn_801CE6A0)((char *)arg0 + 0x19c, s22.field8, s22.field4));
    dest[66] = s23.field8; dest[67] = s23.field4; dest[68] = s23.field0;
    fn_801CE6A4(&s24, (s32)(base + 0x4c4), (s32)((void *(*)(void*,s32,s32))fn_801CE6A0)((char *)arg0 + 0x200, s23.field8, s23.field4));
    dest[69] = s24.field8; dest[70] = s24.field4; dest[71] = s24.field0;
    fn_801CE6A4(&s25, (s32)(base + 0x4dc), (s32)((void *(*)(void*,s32,s32))fn_801CE69C)((char *)arg0 + 0x276, s24.field8, s24.field4));
    dest[72] = s25.field8; dest[73] = s25.field4; dest[74] = s25.field0;
    fn_801CE6A4(&s26, (s32)(base + 0x4ec), (s32)((void *(*)(void*,s32,s32))fn_801CE698)((char *)arg0 + 0x264, s25.field8, s25.field4));
    dest[75] = s26.field8; dest[76] = s26.field4; dest[77] = s26.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s27, (s32)(base + 0x4f8), (s32)((char *)arg0 + 0x2b8), s26.field8);
    dest[78] = s27.field8; dest[79] = s27.field4; dest[80] = s27.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s28, (s32)(base + 0x358), (s32)((char *)arg0 + 0x2c8), s27.field8);
    dest[81] = s28.field8; dest[82] = s28.field4; dest[83] = s28.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s29, (s32)(base + 0x458), (s32)((char *)arg0 + 0x2d8), s28.field8);
    dest[84] = s29.field8; dest[85] = s29.field4; dest[86] = s29.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s30, (s32)(base + 0x468), (s32)((char *)arg0 + 0x2e8), s29.field8);
    dest[87] = s30.field8; dest[88] = s30.field4; dest[89] = s30.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t1, (s32)lbl_8055AB3C, (s32)((char *)arg0 + 0x2f8), s30.field8);
    dest[90] = t1.field8; dest[91] = t1.field4; dest[92] = t1.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t2, (s32)lbl_8055AB40, (s32)((char *)arg0 + 0x308), t1.field8);
    dest[93] = t2.field8; dest[94] = t2.field4; dest[95] = t2.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t3, (s32)lbl_8055AB44, (s32)((char *)arg0 + 0x318), t2.field8);
    dest[96] = t3.field8; dest[97] = t3.field4; dest[98] = t3.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t4, (s32)lbl_8055AB48, (s32)((char *)arg0 + 0x328), t3.field8);
    dest[99] = t4.field8; dest[100] = t4.field4; dest[101] = t4.field0;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t5, (s32)lbl_8055AB4C, (s32)((char *)arg0 + 0x338), t4.field8);
    dest[102] = t5.field8; dest[103] = t5.field4; dest[104] = t5.field0;
    *(s32 *)((char *)arg0 + 0x1c) = fn_802ADF34(*(s32 *)((char *)arg0 + 8), (void *)(base + 0x504), dest, lbl_802FAA40[0], (void *)&lbl_802FAA40[1], dest[104], dest[103], dest[102]);
    *(void **)((char *)arg0 + 0xc) = fn_80207848((void *)(base + 0x514), 1);
    *(void **)((char *)arg0 + 0x10) = fn_80207848((void *)(base + 0x528), 1);
    *(void **)((char *)arg0 + 0x14) = fn_80207848((void *)(base + 0x53c), 1);
    *(s32 *)arg0 = 0;
    *(float *)((char *)arg0 + 4) = lbl_805629FC;
    *(s32 *)((char *)arg0 + 0x18) = 0;
    if (*(s32 *)((char *)arg0 + 8) != 0) fn_802AE0E0();
}
#pragma dont_inline off

#pragma pop
#pragma paired_single off
#pragma scheduling invalid_target
void fn_801CE670(Struct_801CE670 *arg0, s32 arg1, s32 arg2) {
    Struct_801CE670 local;
    local.field4 = arg1;
    local.field0 = 5;
    local.field8 = arg2;
    *arg0 = local;
}

void fn_801CE698(void) {

}

void fn_801CE69C(void) {

}

void fn_801CE6A0(void) {

}

void fn_801CE6A4(Struct_801CE670 *arg0, s32 arg1, s32 arg2) {
    Struct_801CE670 local;
    local.field4 = arg1;
    local.field0 = 1;
    local.field8 = arg2;
    *arg0 = local;
}

void fn_801CE6CC(void) {

}

extern unsigned char *fn_801EA9A0();
extern s32 *lbl_8055E884;
extern void fn_801CBD48(void *, void *);
extern void fn_802AE220(void *);
extern void fn_8001DFCC(void);
void fn_801CE6D0(Struct_801CE670 *arg0, s32 arg1, s32 arg2) {
    Struct_801CE670 local;
    local.field4 = arg1;
    local.field0 = 3;
    local.field8 = arg2;
    *arg0 = local;
}

void fn_801CE6F8(void) {
    s32 *temp_r31;
    if (fn_801CE898() != 0) return;
    temp_r31 = lbl_8055E884;
    fn_801CBD48((void *)(temp_r31 + 0x2C0 / 4), (void *)temp_r31);
    if (temp_r31[0x2C8 / 4] != 0)
        ((void (*)(void *, void *))fn_802AE220)((void *)temp_r31[0x2C8 / 4], (void *)(temp_r31 + 0x608 / 4));
    if (temp_r31[0x2C0 / 4] == 3)
        fn_8001DFCC();
}

int fn_801CE75C(void) {
    if (fn_801CE898() != 0) {
        return 1;
    }
    return lbl_8055E884[0x2C0 / 4] == 3;
}

extern unsigned int fn_801CE898(void);
extern void fn_802ADE60(void *, int);
/* The one stat/awards manager (0x618 bytes): made by fn_801CC470, reset by
   fn_801CC594 / fn_801CC918 and freed by fn_801CCCAC.  Its stat block starts at
   +0x2C0; the four pointers below the block's state word are the stat objects
   the manager owns. */
#define sStatManager lbl_8055E884
struct StatBlock {
    char pad0[0x2C0];
    s32 state;            /* 0x2C0: block state, 3 once it is done (fn_801CE75C) */
    f32 field2C4;         /* 0x2C4 */
    void *entrySet;       /* 0x2C8: set of 0x74-byte stat entries, freed by fn_802ADE60 */
    void *statObjects[3]; /* 0x2CC, 0x2D0, 0x2D4: stat objects with a virtual destroy */
};
#pragma cplusplus on
extern "C" void fn_801CE7A0(void) {
    /* Give back the four stat objects the manager owns and clear their slots:
       the entry set at +0x2C8 is freed by fn_802ADE60(obj, 1), the three stat
       objects after it through their virtual destroy(1).  Nothing to do while
       the stat info tables are not loaded (fn_801CE898). */
    class StatObject {
    public:
        virtual void destroy(s32);
    };
    StatBlock *block;
    StatObject *stat;

    if (fn_801CE898() != 0) return;
    block = (StatBlock *)sStatManager;
    stat = (StatObject *)block->entrySet;
    if (stat != 0) { fn_802ADE60(stat, 1); block->entrySet = 0; }
    stat = (StatObject *)block->statObjects[0];
    if (stat != 0) { if (stat != 0) stat->destroy(1); block->statObjects[0] = 0; }
    stat = (StatObject *)block->statObjects[1];
    if (stat != 0) { if (stat != 0) stat->destroy(1); block->statObjects[1] = 0; }
    stat = (StatObject *)block->statObjects[2];
    if (stat != 0) { if (stat != 0) stat->destroy(1); block->statObjects[2] = 0; }
}
#pragma cplusplus reset
int fn_801CE874(int arg0) {
    return *fn_801EA9A0();
}

unsigned int fn_801CE898(void) {
    int value = fn_800167F4();
    int temp = value ^ 1;
    int half = temp >> 1;
    temp &= value;
    return (unsigned int)(half - temp) >> 31;
}

extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_8000DA10(void);
extern void *fn_8001BB58(s32, s32, s32);
extern int fn_80160AB4(void);
extern void fn_801CD730(s32 *, s32 *);
#pragma dont_inline on
int fn_801CE8CC(void) {
    s32 spC;
    s32 sp8;
    s32 *lfoTable2;
    s32 *lfoTable1;
    s32 value;
    s32 limit;
    void *candidate;

    /* Check whether a valid object/index is available (early reject, direct lookup, or fallback query). */
    if (fn_801CE898() != 0) return 1;

    limit = fn_80160AB4();
    lfoTable2 = __AXFXGetLfoSinTable_801769CC();
    lfoTable1 = __AXFXGetLfoSinTable_801769CC();
    candidate = (void *)fn_8000DA10();
    candidate = ((void *(*)(int, s32, s32, s32))fn_8001BB58)((int)candidate, *lfoTable1, lfoTable2[2], 0);
    if (candidate != NULL) {
        value = ((s32 *)candidate)[2];
        if ((value >= 0) && (value <= limit)) return 1;
    }

    spC = -1;
    sp8 = 0;
    fn_801CD730(&sp8, &spC);
    if ((spC >= 0) && (spC <= limit)) return 1;
    return 0;
}
#pragma dont_inline reset
/* Deleting destructor for an effect object: releases subobjects, runs base cleanup, and optionally frees storage. */
void *fn_801CE9A0(void *self, s32 shouldDelete) {
    if (self != 0) {
        *(void **)((char *)self + 4) = &lbl_80338024[0];
        fn_801CEA28((char *)self + 8);
        fn_801CEA28((char *)self + 0xC);
        if (self != 0) {
            void (*cleanup)(void *);
            cleanup = fn_801CBD04;
            *(void **)((char *)self + 4) = &lbl_80338038[0];
            cleanup(self);
        }
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}
void fn_801CEA28(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

extern int fn_80128668(void *);
extern void fn_801CBD04(void *);
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
#pragma scheduling off
int fn_801CEA6C(void *arg0, int arg1) {
    int value;
    value = *(int *)arg0;
    if (fn_8001C0EC(value) == 0) goto fail;
    fn_8001C0E8(value, arg1);
    value = *(int *)((char *)arg0 + 8);
    if (value == 0) goto fail;
    if (((int (*)(int, int))fn_8001C0EC)(value, arg1) == 0) goto fail;
    value = *(int *)((char *)arg0 + 0xC);
    if (value == 0) goto fail;
    if (((int (*)(int, int))fn_8001C0EC)(value, arg1) == 0) goto fail;
    return 1;
fail:
    return 0;
}

#pragma scheduling on
/* Destroys an object: resets its vtable/owned fields and optionally frees it. */
void *fn_801CEB0C(void *object, s32 freeFlag) {
    if (object != 0) {
        *(void **)((char *)object + 4) = &lbl_80338010[0];
        fn_801CEB94((char *)object + 8);
        fn_801CEB94((char *)object + 0xC);
        if (object != 0) {
            void (*cleanup)(void *);
            cleanup = fn_801CBD04;
            *(void **)((char *)object + 4) = &lbl_80338038[0];
            cleanup(object);
        }
        if (freeFlag > 0)
            fn_80128668(object);
    }
    return object;
}
void fn_801CEB94(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

/* Check/apply a float value against up to three handles stored at +0x0, +0x8, +0xC: requires +0x0 to pass fn_8001BF34, applies fn_8001BF0C to it, and optional handles at +0x8/+0xC must also pass fn_8001BF34 when non-null. */
s32 fn_801CEBD8(void *obj, f32 value) {
    s32 primaryHandle = *(s32 *)obj;
    if (((s32 (*)(s32, f32))fn_8001BF34)(primaryHandle, value) == 0) goto fail;
    fn_8001BF0C(primaryHandle, value);
    if (*(s32 *)((char *)obj + 8) != 0 &&
        ((s32 (*)(s32, f32))fn_8001BF34)(*(s32 *)((char *)obj + 8), value) == 0) goto fail;
    if (*(s32 *)((char *)obj + 0xC) != 0 &&
        ((s32 (*)(s32, f32))fn_8001BF34)(*(s32 *)((char *)obj + 0xC), value) == 0) goto fail;
    return 1;
fail:
    return 0;
}

