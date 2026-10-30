#include "revolution/BTE/stack/include/btm_api.h"
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
    if (fn_80019BA8() == 0) {
        if (fn_80161C38() == 0) {
            fn_801CC918();
            fn_801CB3F8();
        } else {
            return;
        }
    }
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

void fn_801CB55C(int arg0, int arg1) {
    if (fn_80019BA8() || fn_80161C38()) return;
    if (fn_801CE874(arg0)) {
        fn_801CCDAC(0x22205, arg0, arg1);
        fn_801CD4CC(arg0, arg1);
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
 if(mode==0x200) {
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
 }
 if(mode==0x100) {
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
 }
 fn_802E317C(lbl_80337AC8,arg0); return 0;
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
    register void *object;
    register int i;
    register s32 *table;
    register void *item;
    void **slot;
    void *field;

    object = fn_801284F8(0x618, lbl_80337AC8 + 0x190);
    if (object != 0) {
        fn_801CC8FC((char *)object + 0x18);
        fn_801CC8EC((char *)object + 0x29C);
        fn_801CC7A0((char *)object + 0x2C0);
        *(int *)((char *)object + 0x40) = fn_80145E70(lbl_80337AC8 + 0x19C);
        *(int *)((char *)object + 0x2A4) = fn_80145E70(lbl_80337AC8 + 0x1AC);
        *((unsigned char *)object + 0x10) = 0;
        table = __AXFXGetLfoSinTable_801769CC();
        *(s32 *)object = table[0];
        *((s32 *)object + 1) = table[2];
        *((unsigned char *)object + 0x11) = 1;
        *((unsigned char *)object + 0x12) = 1;
        *((unsigned char *)object + 0x13) = 1;
        *((unsigned char *)object + 0x14) = 1;
        i = 1;
        do {
            int mode = fn_8001BA74(i);
            item = ((void *(*)(int, void *))fn_801CB954)(mode, object);
            slot = fn_801CC784((char *)object + 0x18);
            i++;
            *slot = item;
        } while (i <= 7);
        field = fn_80207848(lbl_80337AC8 + 0x1BC, 1);
        *(void **)((char *)object + 8) = field;
        if (field != 0)
            fn_801CC768(field, lbl_80562A04);
        *(void **)((char *)object + 0xC) = fn_8023512C(lbl_80337AC8 + 0x1C8);
        fn_801CC594(object);
    }
    lbl_8055E884 = (s32 *)object;
}

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

    *(long *)(base + 8) = zero;
    *(long *)(base + 0xC) = zero;
    *(long *)(base + 0x10) = zero;
    *(long *)(base + 0x14) = zero;
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

void fn_801CC918(void) {
    extern void fn_8001BE70(void *);
    extern void fn_802AE0E0(void);
    extern float lbl_805629E4;
    extern float lbl_805629FC;
    extern float lbl_80562A08;
    register unsigned char *base;
    register int i;
    register int offset;
    void *entry;
    void *object;
    float floatA08;
    float floatFC;
    float floatE4;

    base = (unsigned char *)lbl_8055E884;
    if (base[0x10] != 0) return;
    i = 0;
    offset = 0;
    for (; i < *(int *)(base + 0x1C); offset += 4, ++i) {
        entry = *(void **)((char *)*(void **)(base + 0x18) + offset);
        if (entry != 0) fn_8001BE70(*(void **)entry);
    }

    i = 0;
    *(int *)(base + 0x29C) = i;
    *(void **)(base + 0x2A0) = base + 0x29C;
    memset(base + 0x44, i, 0x258);
    *(int *)(base + 0x2A8) = i;
    floatA08 = lbl_80562A08;
    *(int *)(base + 0x2AC) = i;
    floatFC = lbl_805629FC;
    *(int *)(base + 0x2B0) = -1;
    floatE4 = lbl_805629E4;
    *(int *)(base + 0x2B4) = -1;
    *(float *)(base + 0x2B8) = floatA08;
    *(unsigned char *)(base + 0x2BC) = i;
    *(int *)(base + 0x2C0) = i;
    *(float *)(base + 0x2C4) = floatFC;
    *(int *)(base + 0x2D8) = i;
    *(float *)(base + 1400) = floatE4;
    *(float *)(base + 1404) = floatFC;
    *(float *)(base + 1408) = floatFC;
    *(float *)(base + 1412) = floatFC;
    *(float *)(base + 1416) = floatE4;
    *(float *)(base + 1420) = floatFC;
    *(float *)(base + 1424) = floatFC;
    *(float *)(base + 1428) = floatFC;
    *(float *)(base + 1432) = floatE4;
    *(float *)(base + 1436) = floatFC;
    *(float *)(base + 1440) = floatFC;
    *(float *)(base + 1444) = floatFC;
    *(float *)(base + 1448) = floatE4;
    *(float *)(base + 1452) = floatFC;
    *(float *)(base + 1456) = floatFC;
    *(float *)(base + 1460) = floatFC;
    *(float *)(base + 1464) = floatE4;
    *(float *)(base + 1468) = floatFC;
    *(float *)(base + 1472) = floatFC;
    *(float *)(base + 1476) = floatFC;
    *(float *)(base + 1480) = floatE4;
    *(float *)(base + 1484) = floatFC;
    *(float *)(base + 1488) = floatFC;
    *(float *)(base + 1492) = floatFC;
    *(float *)(base + 1496) = floatE4;
    *(float *)(base + 1500) = floatFC;
    *(float *)(base + 1504) = floatFC;
    *(float *)(base + 1508) = floatFC;
    *(float *)(base + 1512) = floatE4;
    *(float *)(base + 1516) = floatFC;
    *(float *)(base + 1520) = floatFC;
    *(float *)(base + 1524) = floatFC;
    *(float *)(base + 1528) = floatE4;
    *(float *)(base + 1532) = floatFC;
    *(float *)(base + 1536) = floatFC;
    *(float *)(base + 1540) = floatFC;
    *(float *)(base + 1544) = floatE4;
    *(float *)(base + 1548) = floatFC;
    *(float *)(base + 1552) = floatFC;
    *(float *)(base + 1556) = floatFC;
    if (*(int *)(base + 0x2C8) != 0) fn_802AE0E0();
    object = *(void **)(base + 0x2CC);
    if (object != 0) {
        *(unsigned char *)((char *)object + 0x4A) = 1;
        *(unsigned char *)((char *)object + 0x4C) = 0;
    }
    object = *(void **)(base + 0x2D0);
    if (object != 0) {
        *(unsigned char *)((char *)object + 0x4A) = 1;
        *(unsigned char *)((char *)object + 0x4C) = 0;
    }
    object = *(void **)(base + 0x2D4);
    if (object != 0) {
        *(unsigned char *)((char *)object + 0x4A) = 1;
        *(unsigned char *)((char *)object + 0x4C) = 0;
    }
}

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
    s32 *state;
    void *entry;
    void *object;
    s32 i;
    s32 offset;

    state = lbl_8055E884;
    if (*(u8 *)((u8 *)state + 0x10) != 0)
        return;

    i = 0;
    offset = 0;
    goto check_first;
first_loop:
    entry = *(void **)(*(u8 **)((u8 *)state + 0x18) + offset);
    if (entry != 0)
        fn_8001BDA8(*(void **)entry);
    offset += 4;
    i += 1;
check_first:
    if (i < state[0x1C / 4])
        goto first_loop;

    if (fn_801CE898() != 0)
        return;
    if (state[0x2AC / 4] == 0)
        return;

    i = 0;
    goto check_second;
second_loop:
    object = fn_801EA9A0(i);
    if (*(s32 *)((u8 *)object + 0x44) == 0x50) {
        ((int (*)(s32, s32, s32, void *, s32, s32, f32))fn_8001BBB4)(
            fn_8000DA10(), state[0], state[1], (u8 *)object + 0x48,
            state[0x2AC / 4], state[0x2B0 / 4],
            *(f32 *)((u8 *)state + 0x2B8));
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
    struct FirstObject { virtual void destroy(int); };
    struct ElementBase { int pad; };
    struct ElementObject : ElementBase { virtual void destroy(int); };
    struct State {
        char pad0[8];
        void *first;
        int active;
        char pad10[8];
        void **items;
        int count;
        int field20;
    };
    int i;
    int offset;
    int active;
    ElementObject *element;
    FirstObject *first;
    State *state;
    int *words;

    state = (State *)lbl_8055E884;
    if (state != 0) {
        active = state->active;
        if (active != 0) ((void (*)(int))fn_80235380)(active);
        state->active = 0;
        first = (FirstObject *)state->first;
        if (first != 0) {
            if (first != 0) first->destroy(1);
        }
        deleteThreads__6SystemFv((char *)state + 0x40);
        deleteThreads__6SystemFv((char *)state + 0x2A4);
        i = 0;
        offset = 0;
        while (i < state->count) {
            element = (ElementObject *)((char *)state->items + offset);
            element = *(ElementObject **)element;
            if (element != 0) element->destroy(1);
            offset += 4;
            i++;
        }
        state->count = 0;
        words = (int *)state;
        if (&words[6] != 0) {
            if (&words[6] != 0) {
                state->items = 0;
                state->count = 0;
                state->field20 = 0;
            }
        }
        fn_80128668(state);
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
register s32 var_r29;
register s32 var_r30;
s32 var_r0;
s32 var_r0_2;
register s32 var_ctr;
unsigned char *var_r3;
s32 temp_r3_2, temp_r3_3, temp_r3_4, temp_r3_5, temp_r3_6;
unsigned char *temp_r30;
void *temp_r3;
unsigned char *temp_r3_7;
unsigned char *temp_r0;
unsigned char *temp_r4;
unsigned char *temp_r7;
unsigned char *temp_r7_2, *temp_r7_3, *temp_r7_4, *temp_r7_5;
unsigned char *var_r5;
unsigned char *var_r4;
s32 var_r6;
unsigned char *var_r7;

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
if (fn_801CB900(*(int **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r30 / 4), arg0) == 0) {
var_r30 += 4;
var_r29 += 1;
if (var_r29 < *(s32 *)((unsigned char *)temp_r31 + 0x1C))
goto loop_13;
var_r29 = -1;
}
if (var_r29 < 0)
((void (*)(const char *, ...))fn_802E317C)(lbl_80337CA0, arg0);
temp_r30 = (unsigned char *)*(void **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r29);
if (temp_r30 != 0) {
if (((Dummy_801CCDAC *)temp_r30)->v1(arg2) != 0) {
var_r3 = (unsigned char *)temp_r31;
var_r7 = (unsigned char *)temp_r31 + 0x44;
var_r5 = 0;
var_r4 = 0;
var_r6 = 0;
for (var_ctr = 5; var_ctr != 0; var_ctr--) {
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
var_r30 = 0;
var_r29 = 0;
loop_13:
if (fn_801CB900(*(int **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r29 / 4), arg0) == 0) {
var_r29 += 4;
var_r30 += 1;
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
void fn_801CD4CC(int arg0, int arg1) {
    u8 *base;
    u8 *entry;
    s32 index;
    u8 state;
    if (fn_801CE898() != 0) return;
    base = (u8 *)lbl_8055E884;
    if (base[0x10] != 0) return;
    entry = ((u8 *(*)(s32))fn_801EA9A0)(arg0);
    if (entry[0] != 0) {
        index = entry[0xB4] & 3;
    } else {
        index = -1;
    }
    if (index >= 0) {
        state = base[index + 0x11];
    } else {
        state = 1;
    }
    if (state != 0) return;
    entry = ((u8 *(*)(s32))fn_801EA9A0)(arg0);
    if (entry[0] == 0) return;
    if (*(s32 *)(base + 0x2A8) == 0) {
        *(s32 *)(base + 0x2A8) = arg1;
        if (arg1 == 1) fn_8001EF5C(1, 1);
    } else {
        ((void (*)(char *, ...))fn_802E317C)(lbl_80337D34);
    }
}

extern int fn_8001BBB8(int, int, int, float);
extern void fn_8001EFC4(int, void *, int);
extern char lbl_80337D5C[];
extern void fn_8001EFC4();
void fn_801CD5B4(int arg0, int arg1, int arg2) {
    unsigned char *base;
    unsigned char *object;
    int index;
    int status;
    void *data;
    int current;

    if (fn_801CE898() != 0)
        return;
    base = (unsigned char *)lbl_8055E884;
    if (base[0x10] != 0)
        return;

    object = ((unsigned char *(*)(int))fn_801EA9A0)(arg0);
    if (object[0] != 0)
        index = object[0xB4] & 3;
    else
        index = -1;
    if (index >= 0)
        status = (base + index)[0x11];
    else
        status = 1;
    if (status != 0)
        return;

    object = ((unsigned char *(*)(int))fn_801EA9A0)(arg0);
    if (object[0] == 0)
        return;
    if (*(int *)(base + 0x2AC) != 0)
        goto warning;

    *(int *)(base + 0x2AC) = arg1;
    *(int *)(base + 0x2B0) = arg2;
    fn_8001EF5C(0, arg1);
    if (*(int *)(base + 0x2B0) == 0)
        fn_8001EF5C(2, 1);

    object = ((unsigned char *(*)(int))fn_801EA9A0)(arg0);
    data = object + 0x88;
    ((void (*)(int, void *, int))fn_8001EFC4)(0, data, 1);
    if (arg2 == 0)
        ((void (*)(int, void *, int))fn_8001EFC4)(1, data, 1);

    if (*(int *)(base + 0x2B4) < 0 && base[0x2BC] != 0) {
        index = *(int *)(base + 0x2AC);
        if (index >= 0) {
            current = fn_8000DA10();
            *(int *)(base + 0x2B4) =
                ((int (*)(int, int, int, int, float))fn_8001BBB8)(
                    current, *(int *)base, *((int *)base + 1), index,
                    *(float *)(base + 0x2B8));
        }
    }
    goto done;

warning:
    ((void (*)(char *, ...))fn_802E317C)(lbl_80337D5C);
done:
    return;
}

void fn_801CD730(s32 *arg0, s32 *arg1) {
    if (fn_801CE898() != 0) {
        if (arg0 != 0) *arg0 = 0;
        if (arg1 != 0) *arg1 = -1;
    } else {
        if (arg0 != 0) *arg0 = *(s32 *)((u8 *)lbl_8055E884 + 0x2AC);
        if (arg1 != 0) *arg1 = *(s32 *)((u8 *)lbl_8055E884 + 0x2B0);
    }
}

extern char lbl_80337D90[];
extern f32 lbl_805629FC;
#pragma push
#pragma paired_single off
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801CD7BC(int arg0, register int arg1, f32 farg0) {
    s32 statusIndex;
    register s32 offset;
    register s32 index;
    u8 *object;
    s32 status;
    u8 *base;
    register s32 mapIndex;
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
#pragma paired_single reset
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
#pragma push
#pragma paired_single reset
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
    fn_801CBD48((void *)temp_r31, (void *)(temp_r31 + 0x2C0 / 4));
    if (temp_r31[0x2C8 / 4] != 0)
        fn_802AE220((void *)(temp_r31 + 0x608 / 4));
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
extern void fn_802ADE60(int);
void fn_801CE7A0(void) {
    s32 *state;
    void *ptr;
    if (fn_801CE898() != 0) return;
    state = lbl_8055E884;
    ptr = (void *)state[0x2C8 / 4];
    if (ptr != 0) { fn_802ADE60(1); state[0x2C8 / 4] = 0; }
    ptr = (void *)state[0x2CC / 4];
    if (ptr != 0) { if (ptr != 0) ((void (*)(void *, int))((u32 *)*(u32 *)ptr)[2])(ptr, 1); state[0x2CC / 4] = 0; }
    ptr = (void *)state[0x2D0 / 4];
    if (ptr != 0) { if (ptr != 0) ((void (*)(void *, int))((u32 *)*(u32 *)ptr)[2])(ptr, 1); state[0x2D0 / 4] = 0; }
    ptr = (void *)state[0x2D4 / 4];
    if (ptr != 0) { if (ptr != 0) ((void (*)(void *, int))((u32 *)*(u32 *)ptr)[2])(ptr, 1); state[0x2D4 / 4] = 0; }
}

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
    s32 *temp_r30;
    s32 *temp_r31;
    s32 temp_r0;
    s32 temp_r29;
    void *temp_r3;
    if (fn_801CE898() != 0) return 1;
    temp_r29 = fn_80160AB4();
    temp_r30 = __AXFXGetLfoSinTable_801769CC();
    temp_r31 = __AXFXGetLfoSinTable_801769CC();
    temp_r3 = (void *)fn_8000DA10();
    temp_r3 = ((void *(*)(int, s32, s32, s32))fn_8001BB58)((int)temp_r3, *temp_r31, temp_r30[2], 0);
    if (temp_r3 != NULL) {
        temp_r0 = ((s32 *)temp_r3)[2];
        if ((temp_r0 >= 0) && (temp_r0 <= temp_r29)) return 1;
    }
    spC = -1;
    sp8 = 0;
    fn_801CD730(&sp8, &spC);
    if ((spC >= 0) && (spC <= temp_r29)) return 1;
    return 0;
}
#pragma dont_inline reset
void *fn_801CE9A0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 4) = &lbl_80338024[0];
        fn_801CEA28((char *)arg0 + 8);
        fn_801CEA28((char *)arg0 + 0xC);
        if (arg0 != 0) {
            void (*cleanup)(void *);
            cleanup = fn_801CBD04;
            *(void **)((char *)arg0 + 4) = &lbl_80338038[0];
            cleanup(arg0);
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
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

void *fn_801CEB0C(void *arg0, s32 arg1) {
    void (*cleanup)(void *);
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 4) = &lbl_80338010[0];
        fn_801CEB94((char *)arg0 + 8);
        fn_801CEB94((char *)arg0 + 0xC);
        if (arg0 != 0) {
            cleanup = fn_801CBD04;
            *(void **)((char *)arg0 + 4) = &lbl_80338038[0];
            cleanup(arg0);
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling on
void fn_801CEB94(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

s32 fn_801CEBD8(void *arg0, f32 farg0) {
    s32 temp = *(s32 *)arg0;
    if (((s32 (*)(s32, f32))fn_8001BF34)(temp, farg0) == 0) goto fail;
    fn_8001BF0C(temp, farg0);
    if (*(s32 *)((char *)arg0 + 8) != 0 &&
        ((s32 (*)(s32, f32))fn_8001BF34)(*(s32 *)((char *)arg0 + 8), farg0) == 0) goto fail;
    if (*(s32 *)((char *)arg0 + 0xC) != 0 &&
        ((s32 (*)(s32, f32))fn_8001BF34)(*(s32 *)((char *)arg0 + 0xC), farg0) == 0) goto fail;
    return 1;
fail:
    return 0;
}

