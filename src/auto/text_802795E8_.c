// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern void *lbl_8055F618;
extern s32 lbl_8055F61C;
extern void fn_80128670(s32);
extern void *fn_8012850C(s32, const char *);
extern void fn_8027974C(void);
extern void fn_802E30C8(const char *);
extern char lbl_80347818[];
extern char lbl_80347824[];
extern void *memset(void *, int, u32);
void fn_802797A8(s32 *arg0, s32 arg1) {
    s32 i;
    s32 offset;
    char *entry;
    s32 *src;

    src = arg0;
    lbl_8055F61C = arg1;
    lbl_8055F618 = fn_8012850C(arg1 * 0x2B8, lbl_80347818);
    i = 0;
    offset = 0;
    while (i < lbl_8055F61C) {
        entry = (char *)lbl_8055F618 + offset;
        memset(entry, 0, 0x2B8);
        i++;
        offset += 0x2B8;
        *(s32 *)entry = *src;
        src++;
    }
    fn_8027974C();
}

void fn_80279848(void) {
    fn_80128670((s32)lbl_8055F618);
    lbl_8055F618 = 0;
}

void *fn_80279874(s32 arg0) {
    s32 i;
    s32 count;
    char *entry;
    char *base;

    count = lbl_8055F61C;
    base = (char *)lbl_8055F618;
    entry = base;
    i = 0;
    while (count > 0) {
        if (*(s32 *)entry == arg0) {
            return base + i * 0x2B8;
        }
        entry += 0x2B8;
        i++;
        count--;
    }
    fn_802E30C8(lbl_80347824);
    return 0;
}

f32 fn_802798E8(void *arg0) {
    return *(f32 *)((char *)arg0 + 0x294);
}

