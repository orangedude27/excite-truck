// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef float f32;
typedef int BOOL;
extern void fn_8023905C(void);
extern s32 fn_80128668(void);
extern s32 fn_802E2C20(void);
extern void fn_80238FCC(u32, u32);
s32 fn_8023964C(s32 arg0) {
    fn_8023905C();
    return arg0;
}

s32 fn_8023967C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_802396BC(void *arg0) {
    s32 now;
    u32 next;
    u32 max;
    u32 min;
    u32 rate;

    if (*(u32 **)((u8 *)arg0 + 0x14) != 0 && *((u8 *)arg0 + 4) != 0) {
        now = fn_802E2C20();
        rate = **(u32 **)((u8 *)arg0 + 0x14);
        if ((u32)(now - *(s32 *)arg0) >= 1000U / rate) {
            max = *(u32 *)((u8 *)arg0 + 0x10);
            next = *(u32 *)((u8 *)arg0 + 8) + 1;
            *(u32 *)((u8 *)arg0 + 8) = next;
            if (next > max) {
                if (*((u8 *)arg0 + 5) != 0) {
                    *(u32 *)((u8 *)arg0 + 8) = *(u32 *)((u8 *)arg0 + 0xC);
                } else {
                    *(u32 *)((u8 *)arg0 + 8) = max;
                }
            } else {
                min = *(u32 *)((u8 *)arg0 + 0xC);
                if (next < min) {
                    *(u32 *)((u8 *)arg0 + 8) = min;
                }
            }
            *(s32 *)arg0 = now;
        }
    }
}

void fn_8023976C(u32 arg0) {
    if (*(u32 *)(arg0 + 0x14) != 0) {
        ((void (*)(u32, u32))fn_80238FCC)(arg0, *(u32 *)(arg0 + 8));
    }
}

s32 fn_802E2C20(void);
void fn_80238BF4(void *, s32);
void fn_802CAC54(void);
void fn_8012C4D8(void);
void fn_8023986C(void *arg0) {
    void *state = *(void **)((u8 *)arg0 + 0x14);
    if (state != 0) {
        u32 i = 0;
        u32 offset = 0;
        s32 sentinel = -2;
        do {
            s32 *values = *(s32 **)((u8 *)state + 0x18);
            if (*(s32 *)((u8 *)values + offset) != -2) {
                fn_802CAC54();
                values = *(s32 **)((u8 *)state + 0x18);
                *(s32 *)((u8 *)values + offset) = sentinel;
            }
            offset += 0x14;
            i++;
        } while (i < *(u32 *)((u8 *)state + 8));
        fn_8012C4D8();
        *(void **)((u8 *)arg0 + 0x14) = 0;
    }
}

