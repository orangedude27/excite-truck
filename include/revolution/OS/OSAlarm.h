#ifndef RVL_SDK_OS_ALARM_H
#define RVL_SDK_OS_ALARM_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations
typedef struct OSAlarm OSAlarm;
typedef struct OSContext OSContext;

typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* ctx);

typedef struct OSAlarm {
    OSAlarmHandler handler; // at 0x0, NULL while the alarm is not queued
    u32 tag;                // at 0x4
    s64 end;                // at 0x8, system time the alarm fires (queue key)
    OSAlarm* prev;          // at 0x10, older end time
    OSAlarm* next;          // at 0x14, later end time
    s64 period;             // at 0x18, 0 for a one-shot alarm
    s64 start;              // at 0x20, first end time of a periodic alarm
    void* userData;         // at 0x28
} OSAlarm;

// Doubly linked list of the pending alarms, sorted by ascending end time; the
// head is the one the decrementer is counting down to (see OSAlarm.c).
typedef struct OSAlarmQueue {
    OSAlarm* head; // at 0x0
    OSAlarm* tail; // at 0x4
} OSAlarmQueue;

void __OSInitAlarm(void);
void OSCreateAlarm(OSAlarm* alarm);
void OSSetAlarm(OSAlarm* alarm, s64 tick, OSAlarmHandler handler);
void OSSetPeriodicAlarm(OSAlarm* alarm, s64 tick, s64 period,
                        OSAlarmHandler handler);
void OSCancelAlarm(OSAlarm* alarm);
void OSSetAlarmTag(OSAlarm* alarm, u32 tag);
void OSSetAlarmUserData(OSAlarm* alarm, void* userData);
void* OSGetAlarmUserData(const OSAlarm* alarm);

#ifdef __cplusplus
}
#endif
#endif
