#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern u8 lbl_8055E674;
extern s32 lbl_8055E67C;
extern u8 lbl_8055E691;
extern u8 lbl_8055E692;
extern void *fn_801B2EC0(s32);
extern s32 fn_80128668(void);
extern char lbl_80335BFC[];
extern f32 lbl_805625BC;
extern f32 lbl_80562604;
extern f32 lbl_80562610;
extern void *memset(void *, int, unsigned long);
extern void *lbl_8055E678;
extern u8 lbl_8055E6A0;
extern f32 lbl_8055E6A4;
extern s32 lbl_8055E688;
extern s32 lbl_8055E66C;
extern s32 lbl_8055E670;
extern void *lbl_8055E680;
extern void *lbl_8055E684;
extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
extern s32 lbl_80435C30[];
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

extern s32 fn_80139EC4(f32, f32);
extern s32 fn_802B04D4(f32 *, f32, f32, f32);
extern f32 lbl_805625BC, lbl_805625C0, lbl_805625C4;
extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
s32 fn_801B06D8(void *arg0, void *arg1, s32 arg2) {
    f32 sp18, sp14, sp10, spC, sp8;
    register f32 step = lbl_805625BC;
    register f32 increment = lbl_805625C0;
    register f32 start = step;
    register f32 limit = lbl_805625C4;
    while (step < limit) {
        f32 dx = *(f32 *)arg1 * step;
        f32 dy = *(f32 *)((u8 *)arg1 + 4) * step;
        f32 x = *(f32 *)arg0 + dx;
        f32 y = *(f32 *)((u8 *)arg0 + 4) + dy;
        sp14 = start;
        sp8 = x; spC = y; sp10 = x; sp18 = y;
        if (fn_802B04D4(&sp10, dy, x, dx)) return 1;
        if (lbl_8055E66C && fn_80139EC4(sp8, spC)) return 1;
        step += increment;
    }
    return 0;
}
#pragma pop
u32 fn_801B08E8(u32 arg0, u32 arg1, s32 arg2) {
    u32 var_r4;
    var_r4 = arg1;
    if (var_r4 < arg0) var_r4 += arg2;
    return var_r4 - arg0;
}

void fn_801B0B8C(void *arg0) {
    register f32 value = lbl_805625F0;
    *(u8 *)((u8 *)arg0 + 0x2C) = 0;
    *(f32 *)((u8 *)arg0 + 0x30) = value;
}

s32 fn_801B0BA0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x5C);
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
    register f32 threshold = lbl_805625F4;
    f32 temp_f31;

    temp_r5 = *(void **)((u8 *)arg1 + 4);
    *(void **)arg0 = temp_r5;
    *(f32 *)((u8 *)arg0 + 4) = *(f32 *)((u8 *)arg1 + 8);
    *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)arg1 + 0xC);
    temp_f31 = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x2C) + 8) - threshold;
    if (*(f32 *)((u8 *)temp_r5 + 0x1C) > temp_f31) {
        fn_802E30C8(lbl_80335A58);
        var_r3 = *(void **)((u8 *)*(void **)((u8 *)arg1 + 0x2C) + 0x1C);
        var_r0 = 0;
        var_r4 = 0;
        do {
            var_r0 = var_r3;
            var_r4++;
            if (var_r4 > 0xBB8) {
                var_r0 = 0;
                break;
            }
            var_r3 = *(void **)((u8 *)var_r3 + 0x14);
        } while (*(f32 *)((u8 *)var_r3 + 0x1C) < temp_f31);
        if (var_r0 != 0) *(void **)arg0 = var_r0;
    }
}
#pragma pop
s32 fn_801B0DE0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

s32 fn_801B0DE8(s32 arg0) { return arg0 + 4; }

s32 fn_801B0DF0(s32 arg0) {
    void *base = lbl_8055E684;
    void *obj = ((void **)base)[arg0 << 5];
    void *result = ((void *(*)(void *, void *))*(void **)((u8 *)obj + 0x20))((u8 *)base + (arg0 << 7), base);
    return *(u32 *)((u8 *)result + 0x10) == 0x50434152;
}

extern s32 fn_801B2F40(s32);
extern s32 fn_801B0DF0(s32);
s32 fn_801B0E40(s32 arg0, s32 *arg1) {
    s32 temp_r31;
    s32 var_r30;
    s32 var_r31;
    void *base;
    void **obj;
    void **vtable;

    base = lbl_8055E684;
    obj = (void **)((u8 *)base + (arg0 << 7));
    vtable = *(void ***)obj;
    base = ((void *(*)(void *, void *))vtable[4])(obj, base);
    temp_r31 = *(s32 *)((u8 *)base + 4);
    var_r30 = temp_r31;
    while (var_r30 <= (s32)lbl_8055E678) {
        fn_801B2F40(var_r30 - 1);
        if (fn_801B0DF0(0) != 0) return 0;
        var_r30++;
    }
    var_r30 = temp_r31 - 1;
    var_r31 = *arg1;
    if (var_r31 <= 1) var_r31 = 1;
    while (var_r30 >= var_r31) {
        fn_801B2F40(var_r30 - 1);
        if (fn_801B0DF0(0) != 0) {
            *arg1 = var_r30 + 1;
            break;
        }
        var_r30--;
    }
    return 1;
}

s32 fn_801B0F18(void) {
    return *(s32 *)((u8 *)lbl_8055E684 + (fn_80179630() << 7) + 0x4C);
}

u32 fn_801B0F48(u32 arg0, u32 arg1) {
    u32 diff = arg1 - arg0;
    if (arg0 > arg1) diff = arg0 - arg1;
    return (0x20000U << __cntlzw(diff ^ 0x20000)) >> 31;
}

extern f32 lbl_805625F0;
extern void *lbl_8055E68C;
extern u8 lbl_8055E690;
s32 fn_801B1130(s32 arg0) {
    s32 var_r30;
    s32 var_r31;
    s32 var_r3;
    var_r31 = 1;
    var_r30 = 0;
    if (lbl_8055E68C != NULL) {
        void **obj = (void **)lbl_8055E68C;
        void **vtable = *(void ***)obj;
        s32 (*method)(void *, s32, s32) = (s32 (*)(void *, s32, s32))vtable[5];
        if (method(obj, arg0, *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x7C)) != 0) var_r30 = 1;
    }
    if (var_r30 == 0) {
        var_r3 = 0;
        if (lbl_8055E68C == NULL && lbl_8055E690 != 0) var_r3 = 1;
        if (var_r3 == 0) var_r31 = 0;
    }
    return var_r31;
}

s32 fn_801B11DC(const void *arg0, const void *arg1) {
    extern f32 lbl_80558DC4;
    u32 *a = *(u32 **)arg0;
    u32 *b = *(u32 **)arg1;
    void *base = lbl_8055E684;
    void *obj0 = (u8 *)base + (a[0] << 7);
    void *obj1 = (u8 *)base + (b[0] << 7);
    void **vt0 = *(void ***)obj0;
    void **vt1 = *(void ***)obj1;
    s32 cmp0 = ((s32 (*)(void *, s32, void *))vt0[4])(obj0, b[0], base);
    s32 cmp1 = ((s32 (*)(void *))vt1[4])(obj1);
    s32 next0 = *(s32 *)((u8 *)obj0 + 0x10);
    s32 next1 = *(s32 *)((u8 *)obj1 + 0x10);
    if (cmp0 == 0 && cmp1 == 0) {
        f32 f0 = *(f32 *)((u8 *)obj0 + 0x70);
        f32 f1 = *(f32 *)((u8 *)obj1 + 0x70);
        if (__fabsf(f0 - f1) <= lbl_80558DC4) return 0;
        if (f0 < f1) return 1;
        return -1;
    }
    if (cmp0 == 0) return -1;
    if (cmp1 == 0) return 1;
    if (next0 == next1) return *(s32 *)((u8 *)obj0 + 0x74) - *(s32 *)((u8 *)obj1 + 0x74);
    return next0 - next1;
}

s32 fn_801B1310(s32 arg0) { return arg0 + 4; }

extern s32 fn_801B11DC(const void *, const void *);
extern void qsort(void *, unsigned long, unsigned long, s32 (*)(const void *, const void *));
void fn_801B1318(void) {
    s32 *p;
    s32 i;
    qsort(lbl_80435C30, (unsigned long)lbl_8055E678, 4, fn_801B11DC);
    p = lbl_80435C30;
    i = 0;
    while (i < (s32)lbl_8055E678) {
        s32 value = *p;
        s32 next = i + 1;
        i = next;
        *(s32 *)((u8 *)lbl_8055E684 + (value << 7) + 8) = next;
        p = p + 1;
    }
}

extern s32 fn_801B526C(void);
extern s32 fn_8026A344(void);
extern void fn_8026A248(s32, s32);
void fn_801B1390(s32 arg0, s32 arg1) {
    s32 keep0 = arg0;
    s32 keep1 = arg1;
    s32 count;
    s32 index;

    count = fn_8026A344();
    if (fn_801B526C() != 0) {
        index = ((s32)lbl_8055E678 + keep1 + count) % (s32)lbl_8055E678;
        fn_8026A248(index, keep0);
    } else {
        index = 0;
        if (count >= 0 && count < (s32)lbl_8055E678) {
            void **obj = (void **)((u8 *)lbl_8055E684 + (count << 7));
            void **vtable = *(void ***)obj;
            s32 (*method)(void *, void *) = (s32 (*)(void *, void *))vtable[4];
            void *result = (void *)method(obj, lbl_8055E684);
            index = *(s32 *)((u8 *)result + 4) - 1;
        }
        index = ((s32)lbl_8055E678 + keep1 + index) % (s32)lbl_8055E678;
        fn_8026A248(lbl_80435C30[index], keep0);
    }
}

void fn_801B14BC(s32 *arg0,s32 arg1,s32 arg2) {
    if(arg2){*arg0 |= arg1;return;}
    *arg0 &= ~arg1;
}

extern f32 lbl_805625F8;
extern double lbl_805625E8;
extern f32 lbl_805625FC;
extern s32 fn_801366C0(s32,s32,f32);
extern void fn_801B14BC(s32*,s32,s32);
extern s32 fn_8026A27C(s32);
extern void fn_801B1390(s32, s32);
void fn_801B14E4(void *arg0) {
    s32 value;
    if (fn_801366C0(*(s32*)((u8*)arg0+0x58),*(s32*)((u8*)arg0+0x5C)+0x118,lbl_805625F8))
        *(s32*)((u8*)arg0+0x64) += 1;
    else
        *(s32*)((u8*)arg0+0x64) = 0;
    value=*(s32*)((u8*)arg0+0x64);
    fn_801B14BC((s32*)((u8*)arg0+4),4,(f32)value >= lbl_805625FC);
}

void fn_801B157C(void *arg0,s32 arg1) {
    *(u8*)((u8*)arg0+0x2C)=1;*(f32*)((u8*)arg0+0x30)=lbl_8055E3C8;
    if(lbl_8055E690)fn_801CB6B4(*(s32*)((u8*)arg0+0x60),arg1,2);
}

#pragma dont_inline on
void fn_801B18B8(void *arg0, s32 arg1, s32 arg2) {
    f32 p0[4]; f32 p1[2];
    void *obj = lbl_8055E684;
    f32 scale=*(f32*)((u8*)obj+0x5BC);
    f32 x=*(f32*)((u8*)obj+0x94)+*(f32*)((u8*)obj+0x54)*scale;
    f32 y=*(f32*)((u8*)obj+0x9C)+*(f32*)((u8*)obj+0x5C)*scale;
    f32 z=*(f32*)((u8*)obj+0x98)+*(f32*)((u8*)obj+0x58)*scale;
    p0[0]=x;p0[1]=y;p0[2]=x;p0[3]=z;p1[0]=*(f32*)((u8*)obj+0x54);p1[1]=*(f32*)((u8*)obj+0x5C);
    fn_80135F64(*(s32*)((u8*)obj+0x58),p0,p1,arg1,arg2,obj,y,z,*(f32*)((u8*)obj+0x58),x,scale);
    fn_801353C8(*(s32*)((u8*)obj+0x3C),p0,p1,0);
}
#pragma dont_inline reset

extern void *fn_80156A40(void);
extern void fn_80135F4C(void *);
void fn_801B1A5C(void *arg0) {
    void *obj;
    void **vtable;
    void *a;
    void *b;
    void **vt;
    obj = fn_80156A40();
    vtable = *(void ***)obj;
    a = ((void *(*)(void *, void *))vtable[4])(obj, *(void **)((u8 *)arg0 + 0x60));
    b = *(void **)((u8 *)arg0 + 0x58);
    vt = *(void ***)b;
    ((void (*)(void *, void *))vt[3])(b, a);
    a = ((void *(*)(void *, void *))vtable[5])(obj, *(void **)((u8 *)arg0 + 0x60));
    b = *(void **)((u8 *)arg0 + 0x3C);
    vt = *(void ***)b;
    ((void (*)(void *, void *))vt[3])(b, a);
    fn_80135F4C(*(void **)((u8 *)arg0 + 0x58));
    b = *(void **)((u8 *)arg0 + 0x58);
    a = *(void **)((u8 *)arg0 + 0x3C);
    *(s32 *)((u8 *)arg0 + 0x40) = *(s32 *)((u8 *)b + 4);
    *(f32 *)((u8 *)arg0 + 0x44) = *(f32 *)((u8 *)b + 8);
    *(s32 *)((u8 *)arg0 + 0x48) = *(s32 *)((u8 *)b + 0xC);
    *(s32 *)((u8 *)arg0 + 0x4C) = *(s32 *)((u8 *)a + 4);
    *(f32 *)((u8 *)arg0 + 0x50) = *(f32 *)((u8 *)a + 8);
    *(s32 *)((u8 *)arg0 + 0x54) = *(s32 *)((u8 *)a + 0xC);
}

void fn_801B1FB4(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    void **vtable;
    *arg3 = 0;
    if (lbl_8055E68C == 0) return;
    vtable = *(void ***)lbl_8055E68C;
    ((void (*)(void *, f32, f32, s32, void *))vtable[3])(
        lbl_8055E68C, 0.0f, 0.0f,
        *(s32 *)((u8 *)arg0 + 0x60), (u8 *)arg0 + 0x7C);
}

void fn_801B1FEC(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    void **vtable;
    *arg3 = 0;
    if (lbl_8055E68C == 0) return;
    vtable = *(void ***)lbl_8055E68C;
    ((void (*)(void *, s32, void *))vtable[4])(lbl_8055E68C,
        *(s32 *)((u8 *)arg0 + 0x60), (u8 *)arg0 + 0x7C);
}

void fn_801B2118(void) {}

void *fn_801B21B8(void *arg0) {
    register f32 value = lbl_805625BC;
    register s32 zero = 0;
    *(void **)arg0 = lbl_80335BFC;
    *(s32 *)((u8 *)arg0 + 0x40) = zero;
    *(s32 *)((u8 *)arg0 + 0x48) = 0x2710;
    *(f32 *)((u8 *)arg0 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x4C) = zero;
    *(s32 *)((u8 *)arg0 + 0x54) = 0x2710;
    *(f32 *)((u8 *)arg0 + 0x50) = value;
    memset((u8 *)arg0 + 4, zero, 0x38);
    *(s32 *)((u8 *)arg0 + 0x5C) = zero;
    *(f32 *)((u8 *)arg0 + 0x70) = lbl_805625BC;
    *(s32 *)((u8 *)arg0 + 0x60) = -1;
    *(s32 *)((u8 *)arg0 + 0x6C) = -1;
    *(s32 *)((u8 *)arg0 + 0x58) = zero;
    *(s32 *)((u8 *)arg0 + 0x3C) = zero;
    return arg0;
}

s32 fn_801B224C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern void fn_801B2118(void);
void fn_801B228C(void) {
    fn_8002F6AC(lbl_8055E684, fn_801B2118);
    lbl_8055E684 = 0;
    lbl_8055E678 = 0;
    if (lbl_8055E68C != 0) {
        if (lbl_8055E68C != 0) {
            ((void (*)(void *, s32))(*(void ***)lbl_8055E68C)[2])(lbl_8055E68C, 1);
        }
        lbl_8055E68C = 0;
    }
    if (lbl_8055E66C != 0) {
        fn_80139E18();
        lbl_8055E66C = 0;
    }
    if (lbl_8055E670 != 0) {
        fn_80139E18();
        lbl_8055E670 = 0;
    }
}

void fn_801B2320(void) {
    lbl_8055E688 = *(s32 *)((u8 *)*(void **)((u8 *)fn_80178C9C() + 0x2C) + 0x18);
}

void fn_801B234C(f32 farg0) {
    lbl_8055E6A4 = farg0;
    lbl_8055E6A0 = 1;
}

void fn_801B235C(void) {
    fn_801E89F4(3);
}

extern s32 lbl_8055E6A8;
extern f32 lbl_805625DC;
extern char lbl_80335B94[];
#pragma push
#pragma processor 750
void fn_801B2364(void) {
 f32 time;
 void *obj;
 s32 offset, i, state;
 s32 off, j;
 fn_801B146C();
 if(fn_801769F8()!=0) return;
 state=fn_801E89EC();
 time=lbl_8055E3C8;
 if(lbl_8055E6A0 && time>=lbl_8055E6A4) {
  if(state==0) {
   fn_801E89F4(1);
   for(i=0,offset=0;i<(s32)lbl_8055E678;offset+=0x80,i++) {
    obj=(u8*)lbl_8055E684+offset;
    fn_8018B0D0(*(s32*)((u8*)obj+0x5C),2);
    fn_801CB3AC(*(s32*)((u8*)obj+0x60));
   }
  }
  if(lbl_8055E6A8==1 && fn_800216D0()!=0) lbl_8055E6AC+=lbl_805625DC;
  if(lbl_8055E6A8==1 && time>lbl_8055E6AC) {
   fn_802E30C8(lbl_80335B94);
   lbl_8055E6A8=0;
   j=0; off=0;
   while(j<(s32)lbl_8055E678) {
    *(s32*)((u8*)lbl_8055E684+off+0x28)=lbl_8055E6A8;
    off+=0x80; j++;
   }
   if(lbl_8055E691) fn_801B84F8();
  }
 }
}
#pragma pop
void fn_801B24B8(void) {
    s32 *entry;
    s32 i;
    s32 count;
    void *obj;
    void **vtable;
    if (fn_801769F8() != 0) return;
    entry = (s32 *)&lbl_80435BE8;
    i = 0;
    count = *(s32 *)((u8 *)&lbl_80435BE8 + 0x40);
    while (i < count) {
        obj = (u8 *)lbl_8055E684 + (entry[0] << 7);
        if (*(u8 *)((u8 *)obj + 0x78) == 0)
            *(s32 *)((u8 *)obj + 0x74) = lbl_8055E688 - i + 9;
        entry = (s32 *)((u8 *)entry + 8);
        i++;
    }
    fn_801B1318();
    entry = (s32 *)&lbl_80435BE8;
    i = 0;
    count = *(s32 *)((u8 *)&lbl_80435BE8 + 0x40);
    while (i < count) {
        obj = (u8 *)lbl_8055E684 + (entry[0] << 7);
        fn_801B15A8((s32)obj, *(f32 *)((u8 *)entry + 4));
        entry = (s32 *)((u8 *)entry + 8);
        i++;
    }
    *(s32 *)((u8 *)&lbl_80435BE8 + 0x40) = 0;
    obj = lbl_8055E68C;
    if (obj != 0) {
        vtable = *(void ***)obj;
        ((void (*)(void *))vtable[8])(obj);
    }
}

s32 fn_801B25B0(s32 *arg0, s32 *arg1) {
    f32 var_f31;
    f32 var_f1;
    s32 index0 = *arg0;
    s32 index1 = *arg1;
    void *base = lbl_8055E684;
    void *obj0 = (u8 *)base + (index0 << 7);
    void *obj1 = (u8 *)base + (index1 << 7);
    void **vtable0 = *(void ***)obj0;
    void *result0 = ((void *(*)(void *, s32, void *))vtable0[4])(obj0, index1, base);
    void **vtable1 = *(void ***)obj1;
    ((void (*)(void *))vtable1[4])(obj1);
    var_f31 = *(f32 *)((u8 *)result0 + 0x20);
    var_f1 = *(f32 *)((u8 *)obj1 + 0x20);
    if (var_f31 < lbl_80562604) var_f31 = lbl_80562610;
    if (var_f1 < lbl_80562604) var_f1 = lbl_80562610;
    if (var_f31 < var_f1) return -1;
    return var_f31 > var_f1;
}

extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_80019B3C(void);
extern f32 fn_8013B650(int);
extern void fn_801B1A5C(void *);
extern f32 fn_801B88BC(void);
extern u8 lbl_8055E698;
extern s32 lbl_8055E69C;
extern u8 lbl_8055E6B0;
extern char lbl_80335BA8[];
extern void *lbl_8055A8C0;
extern f32 lbl_80562614;
extern s32 fn_801B25B0(s32 *, s32 *);
#pragma push
#pragma processor 750
void fn_801B265C(void) {
    s32 *stack;
    s32 i, j, k;
    s32 count = (s32)lbl_8055E678;
    void *base = lbl_8055E684;
    register f32 temp_f31;

    lbl_8055E6A8 = 1;
    if ((*(s32 *)((u8 *)__AXFXGetLfoSinTable_801769CC() + 0x10) & 1) || fn_80019B3C() != 0) {
        if (lbl_8055E6B0 == 0) {
            lbl_8055E6B0 = 1;
            fn_802E30C8(lbl_80335BA8, lbl_8055A8C0);
        }
        lbl_8055E6AC = lbl_8055E3C8 + lbl_80562614;
    } else {
        temp_f31 = lbl_8055E3C8;
        lbl_8055E6AC = fn_801B88BC() + temp_f31;
    }
    lbl_8055E698 = 0;
    lbl_8055E694 = 0;
    lbl_8055E6A4 = lbl_805625BC;
    lbl_8055E69C = 0;
    lbl_8055E6A0 = 0;
    memset(lbl_80435C30, -1, 0x20);
    {
        void *obj = fn_80156A40();
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[8])(obj);
    }
    i = 0;
    j = 0;
    while (i < count) {
        fn_801B1A5C((u8 *)base + j);
        j += 0x80;
        i++;
    }
    i = 0;
    j = 0;
    while (i < count) {
        void *obj = (u8 *)base + j;
        f32 value = lbl_805625F0;
        if (*(s32 *)((u8 *)obj + 0x5C + 0x1F0) == 0x51) {
            value = fn_8013B650(*(s32 *)((u8 *)obj + 0x60));
        }
        if (__fabsf(*(f32 *)((u8 *)obj + 0x5C + 0x254)) > lbl_80558DC4) {
            value = *(f32 *)((u8 *)obj + 0x5C + 0x254);
        }
        *(f32 *)((u8 *)obj + 0x24) = value;
        j += 0x80;
        i++;
    }
    stack = (s32 *)0;
    k = 0;
    if (count > 0) {
        s32 n = count - 8;
        if (count > 8) {
            if ((count & 7) == 0 && count <= 0x7FFFFFFE) {
                s32 m = (n + 7) >> 3;
                if (n > 0) {
                    do {
                        stack[k] = k;
                        stack[k + 1] = k + 1;
                        stack[k + 2] = k + 2;
                        stack[k + 3] = k + 3;
                        stack[k + 4] = k + 4;
                        stack[k + 5] = k + 5;
                        stack[k + 6] = k + 6;
                        stack[k + 7] = k + 7;
                        k += 8;
                        m--;
                    } while (m != 0);
                }
            }
        }
        if (k < count) {
            do {
                stack[k] = k;
                k++;
            } while (k < count);
        }
    }
    qsort(stack, (unsigned long)count, 4, (s32 (*)(const void *, const void *))fn_801B25B0);
    i = 0;
    j = 0;
    while (j < count) {
        *(s32 *)((u8 *)base + (stack[i] << 7) + 0x6C) = j;
        i++;
        j++;
    }
}
#pragma pop
void fn_801B2910(void) {
    register s32 var_r30;
    register s32 var_r31;
    register s32 var_r4;
    register s32 var_r6;
    register s32 var_r27;
    register s32 var_r28;
    register s32 var_r29;
    s32 i;
    s32 n;
    s32 *p;
    f32 f30;
    f32 f31;
    void *obj;
    void **vtable;

    lbl_8055E6A0 = 0;
    fn_801E89F4(0);
    *(s32 *)((u8 *)&lbl_80435BE8 + 0x40) = 0;
    var_r30 = 0;
    var_r31 = 0;
    while (var_r30 < (s32)lbl_8055E678) {
        obj = (u8 *)lbl_8055E684 + var_r31;
        vtable = *(void ***)obj;
        ((void (*)(void *))vtable[2])(obj);
        var_r31 += 0x80;
        var_r30++;
    }
    var_r4 = 0;
    if ((s32)lbl_8055E678 > 0) {
        n = (s32)lbl_8055E678 - 8;
        if ((s32)lbl_8055E678 > 8) {
            var_r6 = 0;
            if (((s32)lbl_8055E678 & 7) == 0 && (s32)lbl_8055E678 <= 0x7FFFFFFE) var_r6 = 1;
            if (var_r6 != 0) {
                s32 *src = (s32 *)lbl_8055E684;
                i = (n + 7) >> 3;
                if (n > 0) {
                    do {
                        lbl_80435C30[*(s32 *)((u8 *)src + 8) - 1] = var_r4;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x88) - 1] = var_r4 + 1;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x108) - 1] = var_r4 + 2;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x188) - 1] = var_r4 + 3;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x208) - 1] = var_r4 + 4;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x288) - 1] = var_r4 + 5;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x308) - 1] = var_r4 + 6;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x388) - 1] = var_r4 + 7;
                        src = (s32 *)((u8 *)src + 0x400);
                        var_r4 += 8;
                        i--;
                    } while (i != 0);
                }
            }
        }
        if (var_r4 < (s32)lbl_8055E678) {
            i = (s32)lbl_8055E678 - var_r4;
            do {
                obj = (u8 *)lbl_8055E684 + (var_r4 << 7);
                lbl_80435C30[*(s32 *)((u8 *)obj + 8) - 1] = var_r4;
                var_r4++;
                i--;
            } while (i != 0);
        }
    }
    if (lbl_8055E68C != 0) {
        vtable = *(void ***)lbl_8055E68C;
        ((void (*)(void *))vtable[8])(lbl_8055E68C);
    }
    fn_801B234C(lbl_80562618 + lbl_8055E3C8);
    if (__cntlzw(((s32)lbl_8055E678 - 1) << 27) != 31) {
        f31 = lbl_805625BC;
        f30 = lbl_805625BC;
    } else {
        f31 = -lbl_805625B8;
        f30 = lbl_805625B8;
    }
    p = lbl_80435C30;
    var_r29 = 0;
    var_r28 = 0;
    var_r27 = 0;
    while (var_r27 < (s32)lbl_8055E678) {
        obj = (u8 *)lbl_8055E684 + (*p << 7);
        vtable = *(void ***)obj;
        if (var_r27 & 1) {
            *(s32 *)((u8 *)obj + 0x34) = var_r29;
            *(f32 *)((u8 *)obj + 0x38) = f30;
            var_r29 = (s32)((void *(*)(void *))vtable[7])(obj);
        } else {
            *(s32 *)((u8 *)obj + 0x34) = var_r28;
            *(f32 *)((u8 *)obj + 0x38) = f31;
            var_r28 = (s32)((void *(*)(void *))vtable[7])(obj);
        }
        p++;
        var_r27++;
    }
    obj = fn_80156A40();
    vtable = *(void ***)obj;
    ((void (*)(void *))vtable[8])(obj);
}

void fn_801B2BE8(void *arg0) {
    memset((char *)arg0 + 4, 0, 0x38);
    *(s32 *)((char *)arg0 + 8) = *(s32 *)((char *)arg0 + 0x6C) + 1;
    *(s32 *)((char *)arg0 + 0x68) = 0;
    *(f32 *)((char *)arg0 + 0x70) = lbl_805625BC;
    *(s32 *)((char *)arg0 + 0x74) = 0;
    *(u8 *)((char *)arg0 + 0x78) = 0;
    *(u8 *)((char *)arg0 + 0x79) = 0;
    *(s32 *)((char *)arg0 + 0x7C) = 0;
    *(s32 *)((char *)arg0 + 0x64) = 0;
    fn_8018B0D0(*(s32 *)((char *)arg0 + 0x5C), 0);
    fn_801CB360(*(s32 *)((char *)arg0 + 0x60));
    *(s32 *)((char *)arg0 + 0x28) = 1;
}

void fn_801B2C6C(void) {

}

#pragma dont_inline on
void *fn_801B2EC0(s32 arg0) {
    return (void *)((u8 *)lbl_8055E684 + (arg0 << 7));
}
#pragma dont_inline reset

#pragma dont_inline on
void *fn_801B2ED0(s32 arg0) {
    return fn_801B2EC0(arg0);
}
#pragma dont_inline reset

void* fn_801B2ED4(void) {
    return lbl_8055E680;
}

s32 fn_801B2EDC(s32 arg0, s32 arg1) {
    void *var_r31;
    
    var_r31 = (void *)((u8 *)lbl_8055E684 + (arg0 << 7));
    fn_801B179C(var_r31, arg0, arg1);
    return (s32)var_r31;
}

void* fn_801B2F24(void) {
    return lbl_8055E678;
}

u8 fn_801B2F2C(s32 arg0) {
    return ((u8 *)lbl_8055E684)[(arg0 << 7) + 0x79];
}

s32 fn_801B2F40(s32 arg0) {
    return lbl_80435C30[arg0];
}

typedef void (*VFnPtr)(void *);
s32 fn_801B2F54(s32 arg0) {
    void **obj = (void **)((u8 *)lbl_8055E684 + (arg0 << 7));
    void **vtable = *(void ***)obj;
    ((void (*)(void *))vtable[4])(obj);
    return *(s32 *)(obj + 4);
}

s32 fn_801B3050(s32 arg0) {
    return *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x6C);
}

extern f32 fn_801B3064(void);
f32 fn_801B3064(void) {
    return lbl_8055E6A4;
}

extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
f32 fn_801B306C(void) {
    f32 a = lbl_8055E3C8;
    f32 b = lbl_8055E6AC;
    return (b + 0.0f) - a;
}

void* fn_801B307C(void) {
    return lbl_8055E694;
}

void fn_801B3084(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    void *obj = lbl_8055E68C;
    s32 a = *(s32 *)((u8 *)arg0 + 0x1EC);
    s32 b = *(s32 *)((u8 *)arg1 + 0x1EC);
    if (obj != NULL) {
        void **vtable = *(void ***)obj;
        ((void (*)(void *, s32, s32, s32, s32))vtable[6])(obj, a, b, arg2, arg3);
    }
}

extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
void fn_801B30C0(void) {
}

void fn_801B30D0(s32 arg0) {
    fn_801B196C((s32)((u8 *)lbl_8055E684 + (arg0 << 7)), (s32)lbl_8055E684);
}

#pragma push
#pragma processor 750
void fn_801B3208(s32 arg0, s32 arg1, f32 farg0) {
    fn_802E317C(lbl_80335BD8, arg0, arg1);
    *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x6C) = arg1;
    *(f32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x24) = farg0;
}
#pragma pop
s32 fn_801B327C(void) { return 0; }

void fn_801B3284(void) {

}

u8 fn_801B3288(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

u32 fn_801B3290(void) { return 1; }

void fn_801B3298(void) {

}
