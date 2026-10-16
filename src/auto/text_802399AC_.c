typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
extern s32 lbl_8049870C[];
extern s32 fn_80209030(float);
extern s32 fn_802090BC(s32);
extern s32 fn_8020A5F8(float);
extern s32 fn_802C82C4(s32);
extern s32 fn_802E30C8(s32, s32);
extern s32 fn_80128668();
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
extern s32 lbl_80340C44;
extern s32 lbl_80340C24;
extern s32 lbl_8049870C[];
void fn_80239AB8(void) { fn_80214CB4(lbl_8055BAC8); }

s32 fn_80239DE4(void) {
    s32 *p = (s32 *)lbl_8049870C;
    if (p[6] != p[7] && fn_802104D0()) {
        s32 temp = fn_80131234(&lbl_80340C44);
        s32 arg = fn_80131234(&lbl_80340C24);
        return fn_8021521C(arg, temp, 0);
    }
    return 1;
}

s32 fn_80239E5C(void *arg0, s32 arg1) {
    s32 *p = (s32 *)arg0;
    fn_80209030(*(float *)((char *)arg0 + 0x14));
    fn_8020A5F8(*(float *)((char *)arg0 + 0x10));
    if (arg1 == 0) {
        if (p[0] != p[1]) {
            fn_802E30C8((s32)&lbl_8055BB00, p[0]);
            fn_802C82C4(p[0]);
        }
    } else {
        fn_802E30C8((s32)&lbl_8055BB00, p[0]);
        fn_802C82C4(p[0]);
    }
    if (arg1 == 0) {
        if (p[2] != p[3]) fn_802090BC(p[2]);
    } else {
        fn_802090BC(p[2]);
    }
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

s32 fn_8023A6F4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8023AD6C(void *arg0) {
    return ((s32 *)*(char **)((char *)arg0 + 0x18))[*(s32 *)*(s32 **)((char *)arg0 + 0x20)];
}

void fn_8023AD84(void *arg0) {
    s32 *index = *(s32 **)((char *)arg0 + 0x18);
    s32 count = *(s32 *)((char *)arg0 + 0x14);
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
        if (fn_80214D04() == 3) {
            *(s32 *)((char *)arg0 + 0x18) = 1;
        } else {
            *(s32 *)((char *)arg0 + 0x18) = 0;
        }
    }
}

void fn_8023B368(void) {}

s32 fn_8023B36C(void) { return 0; }

void fn_8023B374(void *arg0) {
    s32 mode = fn_80210570();
    void *obj;
    void **vtable;
    s32 (*call)(void *, s32);
    obj = *(void **)((char *)arg0 + 0x1C);
    if (mode == 2) {
        vtable = *(void ***)((char *)obj + 0xC);
        call = (s32 (*)(void *, s32))((char *)vtable + 0x30);
        call(obj, 3);
    } else {
        vtable = *(void ***)((char *)obj + 0xC);
        call = (s32 (*)(void *, s32))((char *)vtable + 0x30);
        call(obj, 2);
    }
    vtable = *(void ***)((char *)obj + 0xC);
    call = (s32 (*)(void *, s32))((char *)vtable + 0x34);
    call(obj, mode);
}

void fn_8023B400(void) {}

s32 fn_8023B404(void) { return 0; }

void fn_8023B574(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x18) != 0) {
        fn_80214AF0(0x1D);
    } else {
        fn_80214A9C(0x1D);
    }
}

