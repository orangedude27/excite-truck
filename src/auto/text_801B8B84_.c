// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Alarm-event queue: a tagged 0x500-byte buffer of AlarmEvent records, a pending
 * count, and the DSP frame counter used as the current time. */
extern void *lbl_8055E760; /* alarm-event queue allocation */
extern void *lbl_8055E764; /* number of pending events */
extern int lbl_80336990[]; /* "alarm_event" allocation tag */
extern int lbl_8055E3C4; /* current DSP frame count */
#define s_alarmEventTag lbl_80336990
#define s_alarmEventQueue lbl_8055E760
#define s_alarmEventCount lbl_8055E764
#define s_frameCount lbl_8055E3C4

void fn_80128670(int);
int fn_8012850C(int, int *);
#pragma scheduling invalid_target
/* Initialize the alarm-event queue: allocate the 0x500-byte buffer tagged
   "alarm_event" and reset the pending-event count to zero. */
void fn_801B8B84(void) {
    s_alarmEventQueue = (void *)fn_8012850C(0x500, s_alarmEventTag);
    s_alarmEventCount = 0;
}
#pragma scheduling on
/* Tear down the alarm-event queue: free the ring-buffer allocation and clear the pointer. */
void fn_801B8BBC(void) {
    fn_80128670((int)s_alarmEventQueue);
    s_alarmEventQueue = 0;
}

void __AXDSPInitCallback_801B8BE8(void) {
    /* AX DSP init callback: reset the pending alarm-event count. */
    s_alarmEventCount = 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_801B8BF4(void) {
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
}
#pragma pop
