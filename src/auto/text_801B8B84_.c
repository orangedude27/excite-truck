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
#define s_alarmEventQueue lbl_8055E760
#define s_alarmEventCount lbl_8055E764
#define s_frameCount      lbl_8055E3C4
    /* RealName: DispatchAlarmEvents. Run alarm events whose scheduled time has
       arrived: invoke the head's callback, remove it and slide the rest of the
       queue down, stopping as soon as the head is not yet due. */
    struct AlarmEvent { int time; void (*callback)(int, int, int); int a, b, c; };
    int now = s_frameCount;
    goto outer_check;
outer_body: {
    struct AlarmEvent *event = (struct AlarmEvent *)s_alarmEventQueue;
    if (now < event->time)
        return;
    event->callback(event->a, event->b, event->c);
    s_alarmEventCount = (void *)((int)s_alarmEventCount - 1);
    {
        struct AlarmEvent *events;
        int *src;
        int off;
        int i;
        int *dst;
        i = 0;
        off = 0;
        while (i < (int)s_alarmEventCount) {
            events = (struct AlarmEvent *)s_alarmEventQueue;
            src = (int *)&events[i + 1];
            dst = (int *)((char *)events + off);
            *dst++ = src[0];
            dst[0] = src[1];
            dst[1] = src[2];
            dst[2] = src[3];
            dst[3] = src[4];
            i = i + 1;
            off = off + 20;
        }
    }
}
outer_check:
    if ((int)s_alarmEventCount > 0)
        goto outer_body;
#undef s_alarmEventQueue
#undef s_alarmEventCount
#undef s_frameCount
}
#pragma pop
