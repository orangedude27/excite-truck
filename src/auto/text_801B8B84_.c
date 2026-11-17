// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E764;
void fn_80128670(int);
int fn_8012850C(int, int *);
extern void *lbl_8055E760;
extern int lbl_80336990[];
#pragma scheduling invalid_target
/* Initialize the alarm-event queue: allocate the 0x500-byte buffer tagged
   "alarm_event" and reset the pending-event count to zero. */
void fn_801B8B84(void) {
    lbl_8055E760 = (void *)fn_8012850C(0x500, lbl_80336990);
    lbl_8055E764 = 0;
}
#pragma scheduling on
/* Tear down the alarm-event queue: free the ring-buffer allocation held in lbl_8055E760, then clear the pointer. */
void fn_801B8BBC(void) {
    fn_80128670((int)lbl_8055E760);
    lbl_8055E760 = 0;
}

void __AXDSPInitCallback_801B8BE8(void) {
    /* AX DSP init callback: reset the pending alarm-event count. */
    #define s_alarmEventCount lbl_8055E764
    s_alarmEventCount = 0;
    #undef s_alarmEventCount
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
    int offw;
    if (now < e->time)
        return;
    e->callback(e->a, e->b, e->c);
    lbl_8055E764 = (void *)((int)lbl_8055E764 - 1);
    i = 0;
    offw = 0;
    while (i < (int)lbl_8055E764) {
        int *base = (int *)lbl_8055E760;
        int *src = base + (i + 1) * 5;
        int *dst = base + offw;
        *dst++ = src[0];
        dst[0] = src[1];
        dst[1] = src[2];
        dst[2] = src[3];
        dst[3] = src[4];
        i = i + 1;
        offw = offw + 5;
    }
}
outer_check:
    if ((int)lbl_8055E764 > 0)
        goto outer_body;
}
#pragma pop
