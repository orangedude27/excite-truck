#include <stdarg.h>
typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
extern s32 lbl_8049870C[];
extern s32 fn_80209030(float);
extern s32 fn_802090BC(s32);
extern s32 fn_8020A5F8(float);
extern s32 fn_802C82C4(s32);
extern s32 fn_802E30C8(s32, s32);
extern s32 fn_80128668();
extern s32 fn_80128670(s32);
#pragma push
#pragma small_data off
extern s32 lbl_8034109C;
#pragma pop
extern s32 fn_80239E5C(void *, s32);
extern s32 lbl_8055BB00;
extern s32 lbl_8055F110;
extern void *lbl_8055F10C;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055BAC8;
s32 fn_80214D04(void);
void fn_80239A94(void) {
    lbl_8055BAC8 = (void*)fn_80214D04();
}

extern s32 fn_80214CB4(void *);
extern s32 fn_80214A38(s32);
extern s32 fn_80214A9C(s32);
extern s32 fn_80214AF0(s32);
extern s32 fn_80131234(void *);
extern s32 fn_8000DA10(void);
extern s32 fn_8000DB34(void);
extern s32 fn_8021521C(s32, s32, s32);
extern s32 fn_8027B9EC(s32);
extern s32 fn_802104D0(void);
extern void *lbl_8055BAC8;
extern s32 lbl_80340B58;
extern s32 lbl_80340B58;
extern s32 lbl_80340C44;
extern s32 lbl_80340C24;
extern s32 lbl_8049870C[];
void fn_80239AB8(void) { fn_80214CB4(lbl_8055BAC8); }

#pragma push
#pragma small_data off
s32 fn_80239DE4(void) {
    s32 *p = (s32 *)lbl_8049870C;
    if (p[6] != p[7] && fn_802104D0()) {
        s32 temp = fn_80131234(&lbl_80340C44);
        s32 arg = fn_80131234(&lbl_80340C24);
        return fn_8021521C(arg, temp, 0);
    }
    return 1;
}
#pragma pop
s32 fn_80239E5C(void *arg0, s32 arg1) {
    s32 *p = (s32 *)arg0;
    fn_80209030(*(float *)((char *)arg0 + 0x14));
    fn_8020A5F8(*(float *)((char *)arg0 + 0x10));
    if (arg1 != 0) {
        ((s32 (*)(s32, ...))fn_802E30C8)((s32)&lbl_8055BB00, p[0]);
    } else if (p[0] != p[1]) {
        ((s32 (*)(s32, ...))fn_802E30C8)((s32)&lbl_8055BB00, p[0]);
    } else {
        goto second;
    }
    fn_802C82C4(p[0]);
second:
    if (arg1 != 0) fn_802090BC(p[2]);
    else if (p[2] != p[3]) fn_802090BC(p[2]);
}

unsigned char fn_80239F6C(void *arg0) { return *(unsigned char *)((char *)arg0 + 0x20); }

extern s32 fn_80209030(float);
extern s32 fn_802090BC(s32);
extern s32 fn_8020A5F8(float);
extern s32 fn_802C82C4(s32);
extern s32 fn_802E30C8(s32, s32);
extern s32 lbl_8055BB00;
extern s32 fn_80239E5C(void *, s32);
extern void *lbl_8055F10C;
extern s32 fn_80128668();
extern s32 lbl_8055F110;
s32 fn_8023A5AC(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        lbl_8055F110 = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

s32 fn_8023A5F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8023A634(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8023A674(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

s32 fn_8023A6B4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

s32 fn_8023A6F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8023A734(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern s32 fn_80128670(s32);
__declspec(section ".data") extern s32 lbl_80341108;
extern s32 fn_802328D4(s32);
#pragma small_data off
__declspec(section ".data") extern s32 lbl_8034109C;
void *__dt__Q28PSSystem7SeqHeapFv_8023A774(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(s32 **)((char *)arg0 + 0xC) = &lbl_8034109C;
        fn_80128670(*(s32 *)((char *)arg0 + 0x10));
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

__declspec(section ".data") extern s32 lbl_803410D8;
void *__dt__Q28PSSystem7SeqHeapFv_8023A7D8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(s32 **)((char *)arg0 + 0xC) = &lbl_803410D8;
        fn_80128670(*(s32 *)((char *)arg0 + 0x10));
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma small_data off
void *fn_8023A83C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(s32 **)arg0 = &lbl_80341108;
        fn_80128670(*(s32 *)((char *)arg0 + 0x18));
        fn_802328D4(*(s32 *)((char *)arg0 + 0x24));
        *(s32 *)((char *)arg0 + 0x24) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
s32 fn_8023A8B0(void) {
    register s32 *obj = (s32 *)lbl_8055F110;
    if (obj != 0 && *((unsigned char *)obj + 0x18) != 0) return 1;
    return 0;
}

#pragma push
#pragma small_data off
extern s32 lbl_80341290;
extern void *fn_8012850C(s32,s32 *);
#pragma push
#pragma small_data off
void *fn_8023A8D8(register void *arg0, register s32 arg1, register s32 arg2, ...) {
 va_list ap;
 s32 offset;
 *(unsigned char *)arg0=0;
 *(s32 *)((char *)arg0+4)=-1;
 *(unsigned char *)((char *)arg0+8)=0;
 *(s32 **)((char *)arg0+0xC)=&lbl_8034109C;
 va_start(ap,arg2);
 *(s32 *)((char *)arg0+0x14)=0;
 do {
  (*(s32 *)((char *)arg0+0x14))++;
 } while(va_arg(ap,s32)!=0);
 va_end(ap);
 *(s32 **)((char *)arg0+0x10)=fn_8012850C(*(s32 *)((char *)arg0+0x14)*4,&lbl_80341290);
 va_start(ap,arg2);
 offset=0;
 do {
  *(s32 *)((char *)*(s32 **)((char *)arg0+0x10)+offset)=arg2;
  offset+=4;
  arg2=va_arg(ap,s32);
 } while(arg2!=0);
 va_end(ap);
 *(s32 *)((char *)arg0+0x1C)=arg1;
 *(s32 *)((char *)arg0+0x18)=*(s32 *)((char *)arg0+0x14);
 return arg0;
}
#pragma pop

extern s32 lbl_803410D8;
extern s32 lbl_803412A4;
extern void *fn_8012850C(s32, s32 *);
#pragma small_data off
void *fn_8023AA2C(void *arg0, s32 arg1, ...) {
    va_list ap;
    s32 *values;
    s32 offset = 0;
    s32 value;

    *(unsigned char *)arg0 = 0;
    *(s32 *)((char *)arg0 + 4) = -1;
    *(unsigned char *)((char *)arg0 + 8) = 0;
    *(s32 *)((char *)arg0 + 0xC) = (s32)&lbl_803410D8;
    *(s32 *)((char *)arg0 + 0x14) = 0;
    va_start(ap, arg1);
    do {
        (*(s32 *)((char *)arg0 + 0x14))++;
        value = va_arg(ap, s32);
    } while (value != 0);
    va_end(ap);
    *(s32 **)((char *)arg0 + 0x10) = (s32 *)fn_8012850C(*(s32 *)((char *)arg0 + 0x14) * 4, &lbl_803412A4);

    va_start(ap, arg1);
    values = *(s32 **)((char *)arg0 + 0x10);
    do {
        value = va_arg(ap, s32);
        *(s32 *)((char *)values + offset) = value;
        offset += 4;
    } while (value != 0);
    va_end(ap);
    *(s32 *)((char *)arg0 + 0x18) = arg1;
    return arg0;
}

__declspec(section ".data") extern s32 lbl_803412B8;
__declspec(section ".data") extern s32 lbl_803412C8;
extern s32 fn_80232578(s32 *);
#pragma push
#pragma small_data off
void *fn_8023AB78(void *arg0, s32 arg1, s32 arg2, ...) {
 va_list ap;
 s32 offset;
 *(s32 *)((char *)arg0+0x14)=0;
 *(s32 **)arg0=&lbl_80341108;
 *(s32 *)((char *)arg0+0x24)=fn_80232578(&lbl_803412C8);
 *(unsigned char *)((char *)arg0+0x28)=0;
 va_start(ap,arg2);
 *(s32 *)((char *)arg0+0x1C)=0;
 do { (*(s32 *)((char *)arg0+0x1C))++; } while(va_arg(ap,s32)!=0);
 va_end(ap);
 *(s32 **)((char *)arg0+0x18)=fn_8012850C(*(s32 *)((char *)arg0+0x1C)*4,&lbl_803412B8);
 va_start(ap,arg2);
 offset=0;
 do {
  *(s32 *)((char *)*(s32 **)((char *)arg0+0x18)+offset)=arg2;
  offset+=4;
  arg2=va_arg(ap,s32);
 } while(arg2!=0);
 va_end(ap);
 *(s32 *)((char *)arg0+0x20)=arg1;
 return arg0;
}
#pragma pop

#pragma small_data on
void fn_8023ACCC(void) {}

void fn_8023ACD0(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x1C);
    s32 *index = *(s32 **)((char *)arg0 + 0x20);
    *(unsigned char *)((char *)arg0 + 0x28) = 1;
    *index = (count + *index - 1) % count;
}

void fn_8023AD00(void *arg0) {
    s32 *index = *(s32 **)((char *)arg0 + 0x20);
    *(unsigned char *)((char *)arg0 + 0x28) = 1;
    *index = (*index + 1) % *(s32 *)((char *)arg0 + 0x1C);
}

s32 fn_8023AD2C(void *arg0) {
    return *(s32 *)*(s32 **)((char *)arg0 + 0x20) > 0;
}

s32 fn_8023AD44(void *arg0) {
    return *(s32 *)*(s32 **)((char *)arg0 + 0x20) < (*(s32 *)((char *)arg0 + 0x1C) - 1);
}

s32 fn_8023AD6C(void *arg0) {
    return ((s32 *)*(char **)((char *)arg0 + 0x18))[*(s32 *)*(s32 **)((char *)arg0 + 0x20)];
}

void fn_8023AD84(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    s32 *index = *(s32 **)((char *)arg0 + 0x18);
    *index = (count + *index - 1) % count;
}

void fn_8023ADAC(void *arg0) {
    s32 *index = *(s32 **)((char *)arg0 + 0x18);
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    *index = (*index + 1) % count;
}

s32 fn_8023ADD0(void *arg0) {
    return *(s32 *)*(s32 **)((char *)arg0 + 0x18) > 0;
}

s32 fn_8023ADE8(void *arg0) {
    return *(s32 *)*(s32 **)((char *)arg0 + 0x18) < (*(s32 *)((char *)arg0 + 0x14) - 1);
}

s32 fn_8023AE10(void *arg0) {
    return ((s32 *)*(char **)((char *)arg0 + 0x10))[*(s32 *)(*(char **)((char *)arg0 + 0x18))];
}

void fn_8023AE28(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    s32 *index = *(s32 **)((char *)arg0 + 0x1C);
    *index = (count + *index - 1) % count;
}

void fn_8023AE50(void *arg0) {
    s32 *index = *(s32 **)((char *)arg0 + 0x1C);
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    *index = (*index + 1) % count;
}

s32 fn_8023AE74(void *arg0) {
    return *(s32 *)*(s32 **)((char *)arg0 + 0x1C) > 0;
}

s32 fn_8023AE8C(void *arg0) {
    return *(s32 *)*(s32 **)((char *)arg0 + 0x1C) < (*(s32 *)((char *)arg0 + 0x14) - 1);
}

s32 fn_8023AEB4(void *arg0) {
    return ((s32 *)*(char **)((char *)arg0 + 0x10))[*(s32 *)(*(char **)((char *)arg0 + 0x1C))];
}

void fn_8023AECC(void *arg0, s32 arg1) {
    (*(s32 *)((char *)arg0 + 0x14)) = arg1;
}

void fn_8023AED4(void *arg0, s32 arg1) {
    *(s32 *)(*(char **)((char *)arg0 + 0x1C)) = arg1;
}

s32 fn_8023AEE0(void *arg0) {
    return *(s32 *)(*(char **)((char *)arg0 + 0x1C));
}

void fn_8023AEEC(void *arg0) {
    *(s32 *)((char *)arg0 + 0x18) = -1;
}

s32 fn_80230E90(s32);
void fn_8023AEF8(void *arg0) {
    unsigned int temp_r31;

    temp_r31 = fn_80214D04() == 4;
    if (*((unsigned char *)arg0 + 0x20) != temp_r31) {
        fn_80230E90(0);
        if (temp_r31 != 0) {
            *(s32 *)((char *)arg0 + 0x1C) = 1;
        } else {
            *(s32 *)((char *)arg0 + 0x1C) = 0;
        }
        *((unsigned char *)arg0 + 0x20) = temp_r31;
    }
}

s32 fn_8023AF6C(void *arg0, s32 arg1) {
    switch (arg1) {
    case 0xD:
        if (*(unsigned char *)((char *)arg0 + 0x20) == 0)
            goto zero_a;
        if (fn_802399DC(0) == 0)
            goto zero_a;
        fn_802168BC(6);
        goto success;
    default:
        goto zero_b;
    }
zero_a:
    return 0;
zero_b:
    return 0;
success:
    return 1;
}

void fn_8023B04C(void) {}

void fn_8023B050(void) {}

void fn_8023B054(void *arg0) {
    if (((s32 (*)(void))(*(void ***)lbl_8055F10C)[24])() == 0) {
        switch (fn_80214D04()) {
        case 1:
            *(s32 *)((char *)arg0 + 0x18) = 1;
            break;
        default:
            *(s32 *)((char *)arg0 + 0x18) = 0;
            break;
        }
    }
}

#pragma push
#pragma small_data off
extern s32 lbl_80341268[];
#pragma pop
extern float lbl_80563730;
extern s32 fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, s32, float);
#pragma scheduling on
void fn_8023B0BC(void *arg0) {
    s32 sp8;
    s32 temp_r28;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    float f;
    s32 temp_r10;
    void *p = arg0;
    temp_r28 = *(s32 *)((char *)p + 0x10);
    temp_r29 = *(s32 *)((char *)p + 0xC);
    temp_r30 = *(s32 *)((char *)p + 8);
    temp_r31 = *(s32 *)((char *)p + 4);
    temp_r3 = fn_80131234(&lbl_80341268[0]);
    temp_r10 = *(s32 *)((char *)p + 0x18);
    f = lbl_80563730;
    sp8 = 0;
    fn_8022BAD0(0xC9, temp_r31, temp_r30, 0, temp_r29, temp_r28, temp_r3, temp_r10, sp8, f);
}
s32 fn_8023B138(void *arg0) {
    register void *object = lbl_8055F10C;
    if (((s32 (*)(void *))(*(void ***)object)[24])(object) == 0) {
        if (fn_80214D04() == 0) {
            *(s32 *)((char *)arg0 + 0x18) = 1;
        } else {
            *(s32 *)((char *)arg0 + 0x18) = 0;
        }
    }
}

void fn_8023B21C(void) {
}

void fn_8023B220(void *arg0) {
    if (fn_802399AC() != 0) {
        return;
    }
    if (*(unsigned char *)((char *)arg0 + 0x1C) != 0) {
        fn_80214B94(6);
        fn_80214AF0(6);
    } else {
        fn_80214B44(6);
        fn_80214A9C(6);
    }
}

void fn_8023B284(void *arg0) {
    if (((s32 (*)(void *))(*(void ***)lbl_8055F10C)[24])(lbl_8055F10C) == 0) {
        s32 value = fn_80214D04();
        if (value == 3) *(s32 *)((char *)arg0 + 0x18) = 1;
        else *(s32 *)((char *)arg0 + 0x18) = 0;
    }
}

void fn_8023B368(void) {}

s32 fn_8023B36C(void) { return 0; }

void fn_8023B374(void *arg0) {
    typedef struct { unsigned char pad[0xC]; void ** volatile dispatch; } Obj8023B374;
    typedef s32 (*Fn8023B374)(void *, s32);
    s32 mode = fn_80210570();
    void *obj;
    if (mode == 2) {
        obj = *(void **)((char *)arg0 + 0x1C);
        ((Fn8023B374)((Obj8023B374 *)obj)->dispatch[12])(obj, 3);
    } else {
        obj = *(void **)((char *)arg0 + 0x1C);
        ((Fn8023B374)((Obj8023B374 *)obj)->dispatch[12])(obj, 2);
    }
    obj = *(void **)((char *)arg0 + 0x1C);
    ((Fn8023B374)((Obj8023B374 *)obj)->dispatch[13])(obj, mode);
}

void fn_8023B400(void) {}

s32 fn_8023B404(void) { return 0; }

void fn_8023B40C(void *arg0) {
    unsigned char state;
    void *obj;
    void **vtable;
    s32 (*call)(void *, s32);

    state = fn_802104D0();
    if (state == 1) {
        fn_80214B94(3);
    } else {
        obj = *(void **)((char *)arg0 + 0x1C);
        vtable = *(void ***)((char *)obj + 0xC);
        call = (s32 (*)(void *, s32))((char *)vtable + 0x34);
        call(obj, 0);
        if (fn_80214D04() == 2) fn_80214CB4((void *)1);
        fn_80214B44(3);
    }
    if (state == 0) {
        *(s32 *)((char *)arg0 + 0x18) = 4;
    } else if (fn_80214D04() == 2) {
        *(s32 *)((char *)arg0 + 0x18) = 1;
    } else {
        *(s32 *)((char *)arg0 + 0x18) = 0;
    }
    if (*(unsigned char *)((char *)arg0 + 0x20) != state && state != 0) {
        obj = *(void **)((char *)arg0 + 0x1C);
        vtable = *(void ***)((char *)obj + 0xC);
        call = (s32 (*)(void *, s32))((char *)vtable + 0x34);
        call(obj, fn_80210570());
        *(unsigned char *)((char *)arg0 + 0x20) = state;
    }
}

void fn_8023B574(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x18) != 0) {
        fn_80214AF0(0x1D);
    } else {
        fn_80214A9C(0x1D);
    }
}

