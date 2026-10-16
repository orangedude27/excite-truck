// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern char lbl_803385D0[];
extern char lbl_803388F0[];
extern char lbl_8033890C[];
extern s32 lbl_8055E3C4;
extern char lbl_80338C40[];
extern char lbl_803387A8[];

typedef struct {
    char *name;
    s32 state;
} UnkStruct_801D6618;
extern char lbl_80338F50[];

void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D4888(void) {
    fn_801D5860();
}

void fn_801D48F4(void) {
    fn_801D58DC();
}

void fn_801D48F8(void) {
    fn_801D592C();
}

void fn_801D48FC(void) {
    fn_801D5A14();
}

void fn_801D4900(void) {
    fn_801D5A1C();
}

void fn_801D4904(void) {
    fn_801D5A24();
}

void fn_801D4908(void) {
    fn_801D5A2C();
}

s32 fn_801D4CB8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801D4F9C(void) {
}

void fn_801D5010(void) {
}

void *__AXFXGetLfoSinTable_801D64F4(void) {
    return lbl_803387A8;
}

s32 fn_801D6500(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D6508(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x1C) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void fn_801D6600(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

extern char lbl_803387A8[];
extern char lbl_803387C8[];
#pragma scheduling on
void fn_801D6618(UnkStruct_801D6618 *arg0) {
    ((volatile UnkStruct_801D6618 *)arg0)->name = lbl_80338C40;
    ((volatile UnkStruct_801D6618 *)arg0)->state = 0;
}
#pragma scheduling reset
void *fn_801D6630(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void *fn_801D67D4(void) {
    return lbl_803387C8;
}

s32 fn_801D67E0(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D67E8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void fn_801E9DC4(void *);
void fn_801796CC(s32, void *, s32);
void fn_801D6814(void *arg0) {
    struct {
        f32 values[6];
        s32 unk18;
        volatile s32 unk1C;
    } data;
    s32 elapsed = lbl_8055E3C4 - (*(s32 *)((u8 *)arg0 + 0x10) + *(s32 *)((u8 *)arg0 + 0xC));
    if (*(s32 *)((u8 *)arg0 + 4) == 2 && elapsed > 0) {
        data.values[0] = *(f32 *)((u8 *)arg0 + 0x14);
        data.values[1] = *(f32 *)((u8 *)arg0 + 0x18);
        data.values[2] = *(f32 *)((u8 *)arg0 + 0x1C);
        data.values[3] = *(f32 *)((u8 *)arg0 + 0x20);
        data.values[4] = *(f32 *)((u8 *)arg0 + 0x24);
        data.values[5] = *(f32 *)((u8 *)arg0 + 0x28);
        fn_801E9DC4(&data.unk18);
        data.unk1C = *(s32 *)((u8 *)arg0 + 0x2C);
        fn_801796CC(10, data.values, sizeof(data));
        if (elapsed >= *(s32 *)((u8 *)arg0 + 8)) {
            *(s32 *)((u8 *)arg0 + 4) = 3;
        }
    }
}

void fn_801D68D0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

void *fn_801D6900(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern u8 lbl_80338868[];
void *fn_801D6C28(void) {
    return lbl_80338868;
}

s32 fn_801D6C3C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void *fn_801D6D80(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void fn_801D6FA0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

void *fn_801D7034(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

s32 fn_801D76CC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_801D770C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_801D774C(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 val = ((s32)arg0 + 0x24);
        if (val == 0) {
            goto skip;
        }
        if (val == 0) {
            goto skip;
        }
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
skip:
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

char *fn_801D77AC(void) {
    return lbl_803388F0;
}

s32 fn_801D77B8(s32 arg0) {
    return ((s32 *)arg0)[2];
}

s32 fn_801D77C0(s32 arg0) {
    s32 *ptr = (s32 *)arg0;
    if (ptr[2] == 0) {
        return arg0;
    }
    ptr[2] = 1;
    return arg0;
}

s32 fn_801D77B8(s32 arg0);
s32 fn_801D77C0(s32 arg0);
void fn_80116BCC(void *);
void fn_80127464(void *);
void fn_801D77D8(void *arg0) {
    void **vtable = *(void ***)arg0;
    ((void (*)(void *))vtable[0xD])(arg0);
}

void fn_801D77E8(void) {

}

void fn_801D77EC(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)arg0;
    s32 count = ptr[0x1D];
    s32 idx = 0;
    s32 byte_offset = 0;
    
    if (count > 0) {
        s32 *array = (s32 *)ptr[0x1C];
        
        for (; idx < count; idx++) {
            if (array[byte_offset / 4] == arg1) {
                goto post_loop;
            }
            byte_offset += 4;
        }
        
        idx = -1;
    }
    
post_loop:
    if (idx == -1) {
        return;
    }
    if (idx < 0) {
        return;
    }
    if (idx >= count) {
        return;
    }
    if (idx == count - 1) {
        ptr[0x1C] = (s32)((s32 *)ptr[0x1C]);
        ((s32 *)ptr[0x1C])[idx] = ((s32 *)ptr[0x1C])[count - 1];
        ptr[0x1D] = count - 1;
    }
}

void fn_801D7874(void *arg0, void *arg1) {
    s32 result;
    s32 count;
    
    ((void (*)(void *))((void ***)arg1)[2])(arg1);
    
    if (((s32 *)arg0)[3] < 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    
    result = ((s32 (*)(void *, void *, s32))((void ***)arg1)[10])(arg1, &lbl_803385D0, -1);
    if (result != ((s32 *)arg0)[3]) {
        return;
    }
    
    count = ((s32 *)arg0)[0x1D];
    ((s32 *)arg0)[0x1D] = count + 1;
    ((s32 *)((s32 *)arg0)[0x1C])[count] = (s32)arg1;
}

void *fn_801D7924(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma scheduling on
s32 fn_801D796C(void *arg0, s32 *arg1, s32 arg2) {
    s32 *entry;
    s32 idx;

    entry = arg1;
    for (idx = 0; idx < arg2; entry++, idx++) {
        if (((s32 *)arg0)[1] != 0) {
            if (fn_801D9B28(((s32 *)arg0)[1], *entry) != 0) {
                return 1;
            }
        } else if (((s32 *)arg0)[2] == *entry) {
            return 1;
        }
    }
    return 0;
}
char *fn_801D7C6C(void) {
    return lbl_8033890C;
}

s32 fn_801D7C78(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

extern s32 fn_802E317C(const char *, ...);
#pragma push
#pragma scheduling off
s32 fn_801D7C80(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)arg0;
    f32 *fptr = (f32 *)arg0;
    s32 result = 0;

    if (ptr[0xA] == 1) {
        ptr[7] = lbl_8055E3C4;
        switch (arg1) {
        case 0:
            fptr[8] = fptr[5];
            fptr[9] = fptr[6];
            break;
        case 1:
            fptr[8] = fptr[6];
            fptr[9] = fptr[5];
            break;
        default:
            fn_802E317C(lbl_80338F50, arg1);
            break;
        }
        ptr[0xA] = 2;
        result = 1;
    }
    return result;
}

void fn_801D85D8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

void fn_801D8600(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

#pragma pop
void fn_801D8620(void) {

}

void fn_801D8938(void) {

}

void fn_801D8B50(void) {

}

void fn_801D8B54(void) {

}

void fn_801D8B58(void) {

}

void fn_801D8B5C(void) {

}

void fn_801D8C18(void) {

}

void fn_801D8C94(void) {

}

void fn_801D8DB0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

void *fn_801D8DC8(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void fn_801D8FE0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

