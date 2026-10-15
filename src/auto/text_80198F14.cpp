// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#pragma opt_tail_call on

extern "C" void fn_8019EBC0(void);
extern "C" void fn_8019F3D0(void);
extern "C" void fn_801A49E8(void*);
extern "C" void fn_801A49FC(s32);
extern "C" void fn_801796EC(s32, s32*, s32);
extern "C" s32 fn_8012C4E4(void*, void*, s32);
extern "C" s32 fn_801CFF18(s32, s32);

extern "C" void fn_801A44D4(void*);
extern void* lbl_8055A508;
extern void* lbl_8055A510;

void fn_8019F1A4(void) __attribute__((noreturn));

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019A780(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

extern "C" s32 fn_8019BD4C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" s32 fn_8019E834(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8019F3D0(void) {

}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019F3D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8019F560(void) {
    fn_8019F1A4();
}

extern "C" void fn_8019FF88(void) {
    fn_8019EBC0();
}

extern "C" s32 fn_801A010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A2434(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A2EC8(void) {

}

extern "C" void fn_801A44C4(void* arg0) {
    fn_801CFF18(*(s32*)((u8*)arg0 + 0x24), *(s32*)((u8*)arg0 + 0xC));
}

extern "C" void fn_801A44D4(void* arg0) {
    s32* r29;
    s32 r30;
    s32 r31;
    r29 = (s32*)arg0;
    r30 = 0;
    r31 = 0;
    goto check;
loop:
    {
        s32* arr = (s32*)r29[1];
        fn_801A49FC(*(s32*)((u8*)arr + r30));
        r30 += 4;
        r31++;
    }
check:
    {
        s32 limit = r29[0];
        if (r31 < limit) goto loop;
    }
}

extern "C" void fn_801A4538(void* arg0) {
    fn_8012C4E4(arg0, &fn_801A44D4, 0);
}

#pragma opt_tail_call on
void fn_801A4768(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}
#pragma opt_tail_call on
void fn_801A47C8(void* arg0) {
    s32 limit = *(s32*)arg0;
    s32** ptrs = *(s32***)((u8*)arg0 + 4);
    for (s32 i = 0; i < limit; i++) {
        ((u8*)ptrs[i])[0x40] = 1;
    }
}

#pragma opt_tail_call on
void fn_801A47FC(void* arg0) {
    if (arg0) {
        s32 limit = *(s32*)arg0;
        s32** ptrs = *(s32***)((u8*)arg0 + 4);
        for (s32 i = 0; i < limit; i++) {
            fn_801A49E8((void*)ptrs[i]);
        }
    }
}

#pragma opt_tail_call on
void fn_801A4868(void* arg0, u8 arg1) {
    if (*(u8*)((u8*)arg0 + 0x40) != arg1) {
        s32 local38;
        u8 localC;
        local38 = *(s32*)((u8*)arg0 + 0x38);
        localC = arg1;
        fn_801796EC(12, &local38, 8);
        *(u8*)((u8*)arg0 + 0x40) = arg1;
    }
}

void fn_801A48C8(void* arg0) {
    void* ptr = *(void**)((u8*)arg0 + 0x48);
    ((void(*)(void*, void*, void**))(*(void***)((u8*)ptr + 0x18)))(ptr, &lbl_8055A508, &lbl_8055A510);
}

extern "C" s32 fn_801A4F00(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F40(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F80(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4FC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5000(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5040(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5080(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A50C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_801A5100(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" f32 fn_801A511C(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" s32 fn_801A5134(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A4868(void);

extern "C" void fn_801A4868(void);
extern "C" void fn_801A4868(void*, u8);

extern "C" void fn_801A518C(void) {
    fn_801A4868();
}

