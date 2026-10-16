#include <types.h>

typedef struct Unk8001BBBC {
    s32 unk_0x0;
    s32 unk_0x4;
    s32 unk_0x8;
} Unk8001BBBC;

extern s8 lbl_8055D5C8;
#pragma push
#pragma small_data off
extern s32 lbl_803583C8;
#pragma pop
extern void fn_8002F634(void *, void *, s32, s32);
extern s32 fn_8001BA10(s32, s32);
extern void *lbl_80358658[];
extern s32 lbl_802ED7B8[];
extern const char lbl_802FD85C[];
extern s32 fn_802E317C(const char *);
extern void fn_8001C9C4(void);
extern void fn_8001CAF8(void);
extern s32 fn_8001D25C(s32);
extern s32 fn_8001CDB8(s32, s32, s32, s32, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).



extern void fn_8001C4D4(void);
void fn_8001B9F4(void) {
    fn_8002F634(&lbl_803583C8, fn_8001BA10, 0x14, 0x10);
}

s32 fn_8001BA10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_8001BA50(void *arg0) {
    ((s8 *)arg0)[0x10] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = -1;
}

void fn_8001BA68(void) {
}

void fn_8001BA6C(void) {
    fn_8001C714();
}

void fn_8001BA70(void) {
    fn_8001C73C();
}

void fn_8001BA74(void) {
    fn_8001C960();
}

void fn_8001BA78(void) {
    lbl_8055D5C8 = 1;
    fn_8001C9C4();
}

void fn_8001BA84(void) {
    lbl_8055D5C8 = 0;
    fn_8001CAF8();
}

#pragma scheduling off
s32 fn_8001BA90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp = fn_8001D25C(arg2);
    if (temp != 0) {
        return fn_8001CDB8(arg0, arg1, temp, arg3, arg4);
    }
    return arg4;
}

void fn_8001BB0C(s32 arg0, s32 arg1, volatile s32 arg2, volatile s32 arg3) {
    s32 saved2 = arg2;
    s32 saved3 = arg3;
    fn_8001CE34(arg0, fn_8001D25C(arg1), saved2, saved3);
}

void fn_8001BB58(s32 arg0, s32 arg1, volatile s32 arg2, volatile s32 arg3) {
    s32 a = arg2;
    s32 b = arg3;
    fn_8001CE74(arg0, fn_8001D25C(arg1), a, b);
}
#pragma scheduling reset
void fn_8001BBB4(void) {
    fn_8001D020();
}

void fn_8001BBB8(void) {
    fn_8001CF8C();
}

extern void fn_8001D234(s32, s32 *, s32 *, s32 *);
void fn_8001BBBC(Unk8001BBBC *arg0, s32 arg1) {
    Unk8001BBBC value;
    fn_8001D234(arg1, &value.unk_0x0, &value.unk_0x4, &value.unk_0x8);
    *arg0 = value;
}

s32 ARCGetStartOffset(void *arg0) { return ((s32 *)arg0)[2]; }

s32 fn_8001BC18(s32 arg0) { return arg0 + 0x14; }

s32 fn_8001BC20(s32 arg0) { return arg0 + 0x1C; }

s32 fn_8001BCF0(void *arg0) {
    s32 var_r5 = 0;
    
    s32 ptr = ((s32 *)arg0)[6] + ((s32 *)arg0)[3] * 0xC;
    
    if (*((u8 **)ptr + 0x10) != 0)
        goto done;
    
    if (((u8 *)arg0)[0x20] == 0)
        goto done;
    
    var_r5 = 1;
done:
    return var_r5;
}

s32 fn_8001BD28(void *arg0) {
    return ((s32 *)arg0)[1];
}

u8 fn_8001BD30(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x10);
}

s32 fn_8001BD6C(void *arg0, void *arg1) {
    s32 r3 = ((s32 *)arg0)[6];
    s32 r4 = ((s32 *)arg0)[3];
    s32 r5 = ((s32 *)arg1)[6];
    s32 r6 = ((s32 *)arg1)[3];
    s32 result = fn_8001D2E4(r3, r4, r5, r6);
    return result >> 31;
}

void fn_8001BE70(void *arg0) {
    s32 index = *(s32 *)((u8 *)arg0 + 0xC);
    s32 base = *(s32 *)((u8 *)arg0 + 0x18);
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)(base + index * 0xC + 8);
    *(u8 *)((u8 *)arg0 + 0x20) = 0;
}

void *fn_8001BE94(void *dest, int val, size_t count) {
    fn_8001BC38(dest, val, count);
    return dest;
}

s32 fn_8001BC18(s32 arg0);
#pragma dont_inline reset
f32 fn_8001BEC4(s32 arg0) {
    return *(f32 *)fn_8001BC18(arg0);
}
void fn_8001BF0C(f32 arg0) {
    f32 temp = arg0;
    fn_8001BC28(*(s32 *)&temp);
}

void *fn_8001C070(void *dest, int val, size_t count) {
    fn_8001BC38(dest, val, count);
    return dest;
}

#pragma dont_inline on
s32 fn_8001C0A0(void) {
    return *(s32 *)((s32 (*)(void))fn_8001BC18)();
}

s32 fn_8001C0C4(void) {
    return *(s32 *)((s32 (*)(void))fn_8001BC20)();
}

#pragma dont_inline reset
void fn_8001C0E8(void) {
    fn_8001BC28();
}

s32 fn_8001C200(const char *arg0, const char *arg1) {
    if (stricmp(arg0, arg1) == 0 || stricmp(arg0, "???") == 0 || stricmp(arg1, "???") == 0) {
        return 1;
    }
    return 0;
}

s32 fn_8001C27C(void *arg0, u32 arg1, const char *arg2) {
    s32 result = 0;
    if (*(u32 *)arg0 == arg1 && fn_8001C200(*(const char **)((u8 *)arg0 + 4), arg2) != 0) {
        result = 1;
    }
    return result;
}

s32 fn_8001C2CC(s32 arg0, u32 arg1, const char *arg2, s32 arg3) {
    s32 i = 0;
    s32 offset = 0;
    void *entry;
    void *record;
    for (;;) {
        entry = lbl_80358658[arg0];
        if (i >= *(s32 *)((u8 *)entry + 4)) {
            return 0;
        }
        record = (void *)(*(s32 *)entry + offset);
        if (fn_8001C27C(record, arg1, arg2) != 0) {
            return (s32)record;
        }
        offset += 0x2C;
        i++;
    }
}

void fn_8001C4D4(void) {

}

void fn_8001C4D8(void) {
    fn_8001C4D4();
    __builtin_unreachable();
}

void fn_8001C4DC(void) {
    fn_8001C4D8();
}

extern void *lbl_80358658[];
extern s32 lbl_802ED7B8[];
extern const char lbl_802FD85C[];
extern s32 fn_802E317C(const char *);
s32 *fn_8001C4E0(s32 arg0) {
    s32 compare = arg0;
    register s32 *entry = lbl_802ED7B8;
    do {
        if (*entry == compare) {
            return entry;
        }
        entry = (s32 *)((u8 *)entry + 0xC);
    } while (*entry != 0);
    fn_802E317C(lbl_802FD85C);
    return 0;
}

extern unsigned char fn_8001D464[];
extern void fn_8001D528(void *);
void fn_8001D5D8(void) {
    fn_8001D528(fn_8001D464);
}

extern unsigned char fn_8001D474[];
void fn_8001D5E4(void) {
    fn_8001D528(fn_8001D474);
}

void fn_8001D7A4(void) {

}

