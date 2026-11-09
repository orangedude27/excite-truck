// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E764;
void fn_80128670(int);
int fn_8012850C(int, int *);
extern void *lbl_8055E760;
extern int lbl_80336990[];
void fn_801B8B84(void) {
    lbl_8055E760 = (void *)fn_8012850C(0x500, lbl_80336990);
    lbl_8055E764 = 0;
}

void fn_801B8BBC(void) {
    fn_80128670((int)lbl_8055E760);
    lbl_8055E760 = 0;
}

void __AXDSPInitCallback_801B8BE8(void) {
    lbl_8055E764 = 0;
}

extern int lbl_8055E3C4;
#pragma push
#pragma scheduling invalid_target
void fn_801B8BF4(void) {
    struct Entry { int time; void (*callback)(int, int, int); int a, b, c; };
    int now = lbl_8055E3C4;
    goto outer_check;
outer_body: {
    struct Entry *e = (struct Entry *)lbl_8055E760;
    int i;
    int offset;
    if (now < e->time)
        return;
    e->callback(e->a, e->b, e->c);
    lbl_8055E764 = (void *)((int)lbl_8055E764 - 1);
    i = 0;
    offset = 0;
    while (i < (int)lbl_8055E764) {
        int *base = (int *)lbl_8055E760;
        int *src = base + (i + 1) * 5;
        int *dst = base + offset / 4;
        int first = src[0];
        *dst++ = first;
        dst[0] = src[1];
        dst[1] = src[2];
        dst[2] = src[3];
        dst[3] = src[4];
        i = i + 1;
        offset = offset + 0x14;
    }
}
outer_check:
    if ((int)lbl_8055E764 > 0)
        goto outer_body;
}
#pragma pop
