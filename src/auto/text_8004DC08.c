#include <types.h>
#include <macros.h>
typedef struct IPCIOVector {
    void *base;
    u32 length;
} IPCIOVector;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void * volatile lbl_8055DA2C;
#pragma small_data on
extern const char lbl_80558F40;
#pragma small_data off
extern int lbl_8055DA44;
extern unsigned int lbl_800030F0;
extern void *memcpy(void *, const void *, unsigned int);
extern void ICFlashInvalidate(void);
extern int lbl_8055DA44;
extern unsigned int lbl_800030F0;
extern void *memcpy(void *, const void *, unsigned int);
extern void ICFlashInvalidate(void);
extern void* memset(void*, int, unsigned int);
extern unsigned int strlen(const char*);
extern char* strcpy(char*, const char*);
int PackArgs(void* arg0, int arg1, char** arg2, int arg3) {
    int i, count = arg1, copied = 0;
    char** p = arg2 + arg1;
    char* strings = (char*)arg0 + 0x2000;
    char* table;
    memset(arg0, 0, 0x2000);
    if (count == 0) { *(int*)((char*)arg0 + 8) = 0; return 1; }
    while (--count >= 0) {
        char* str = *--p;
        strings -= strlen(str) + 1;
        strcpy(strings, str);
        *p = (char*)arg0 + (strings - (char*)arg0);
    }
    table = (char*)arg0 + (((strings - (char*)arg0) & ~3) - (arg1 + 1) * 4);
    i = arg1 + 1;
    if (i != 0) {
        for (copied = 0; i - copied >= 8; copied += 8) {
            int j;
            for (j = 0; j < 8; j++) ((int*)table)[copied+j] = ((int*)arg2)[copied+j];
        }
        for (; copied < i; copied++) ((int*)table)[copied] = ((int*)arg2)[copied];
    }
    ((int*)table)[-1] = arg1;
    *(int*)((char*)arg0 + 8) = table - 4 - (char*)arg0;
    return 1;
}

void fn_8004DD88(void (*target)(void)) {
    ICFlashInvalidate();
    __asm_sync_placeholder();
    target();
}

void __AXDSPInitCallback_8004DDC4(void) {
    lbl_8055DA44 = 1;
}

void __OSGetExecParams(unsigned int *param) {
    unsigned int exec = *(volatile unsigned int *)0x800030F0;
    if (exec >= 0x80000000u) {
        memcpy(param, (void *)exec, 0x1C);
        return;
    }
    *param = 0;
}

void fn_8004DDF4(void* hi) {
    lbl_8055DA2C = hi;
}

extern unsigned char lbl_8037D900[];
extern char lbl_803049C0[];
extern unsigned char lbl_80560C70, lbl_80560C71, lbl_80560C72, lbl_80560C73;
extern void *lbl_8055DA34;
extern unsigned int *lbl_8055DA38, *lbl_8055DA3C, *lbl_8055DA40;
extern int fn_8003AC24(void *callback, ...);
extern int fn_8003AD88(void *buffer, int length, int input, void *callback);
extern int fn_8003A834(void *buffer, void *callback);
extern void DVDLowOpenPartition(unsigned int partition, int arg1, int arg2, int arg3, void *buffer, void *callback);
extern void DVDLowInit(void);
extern int IOS_Open(const char *path, int mode);
extern int IOS_Close(void);
extern int _ES_GetTicketViews(int *fd, unsigned int title_hi, unsigned int title_lo, void *views, unsigned int *count);
extern int _ES_LaunchTitle(int *fd, unsigned int title_hi, unsigned int title_lo, void *views);
extern void OSReport(const char *format, ...);
extern void __OSLaunchMenu(void);
#pragma small_data on
#pragma small_data reset
void fn_8004DDFC(void) {
    unsigned char *base;
    unsigned char *mem;
    unsigned char *partition;
    register unsigned int *entry;
    register unsigned int *selected;
    struct local_state {
        unsigned char b0;
        unsigned char b1;
        unsigned char b2;
        unsigned char b3;
        int fd;
        unsigned int count;
    } state;
    int error;
    unsigned int i;
    unsigned long long title;
    int result;

    state.b0 = lbl_80560C70;
    state.b1 = lbl_80560C71;
    state.b2 = lbl_80560C72;
    state.b3 = lbl_80560C73;
    base = lbl_8037D900 + 0x10000;
    mem = lbl_8037D900;
    state.fd = -1;
    state.count = 1;
    lbl_8055DA2C = 0;
    ((int (*)(void *, int, int, int, int, int, int, void *))fn_8003AC24)((void *)fn_8004DDF4, state.b2, state.b1, state.b0, 0, -1, 1, mem);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    entry = (unsigned int *)(base - 0x4300);
    lbl_8055DA40 = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, 0x10000, (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    entry = (unsigned int *)(base - 0x42E0);
    lbl_8055DA3C = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, *(int *)((unsigned char *)lbl_8055DA40 + 4), (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    selected = 0;
    entry = (unsigned int *)lbl_8055DA3C;
    lbl_8055DA38 = 0;
    for (i = 0; (unsigned char)i < *(unsigned int *)lbl_8055DA40; i++) {
        if (entry[1] == 0) {
            selected = entry;
            lbl_8055DA38 = (unsigned int *)entry;
        }
        entry += 2;
        lbl_8055DA3C = (unsigned int *)entry;
    }
    lbl_8055DA2C = 0;
    partition = base - 0x42C0;
    DVDLowOpenPartition(*(unsigned int *)selected, 0, 0, 0, partition, (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    lbl_8055DA2C = 0;
    fn_8003AC24((void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    partition = base - 0x42C0;
    lbl_8055DA34 = partition;
    error = 0;
    title = *(unsigned long long *)(partition + 0x184);
    result = IOS_Open(&lbl_80558F40, 0);
    state.fd = result;
    if (result < 0)
        error = result;
    if (error != 0) {
        OSReport(lbl_803049C0, error);
        __OSLaunchMenu();
    }

    result = ((int (*)(int *, unsigned long long, void *, unsigned int *))_ES_GetTicketViews)(&state.fd, title, 0, &state.count);
    if (state.count == 1 && result != 0) {
        OSReport(lbl_803049C0, result);
        __OSLaunchMenu();
    }
    result = ((int (*)(int *, unsigned long long, void *, unsigned int *))_ES_GetTicketViews)(&state.fd, title, mem, &state.count);
    if (result != 0) {
        OSReport(lbl_803049C0, result);
        __OSLaunchMenu();
    }
    result = ((int (*)(int *, unsigned long long, void *))_ES_LaunchTitle)(&state.fd, title, mem);
    if (result != 0) {
        OSReport(lbl_803049C0, result);
        __OSLaunchMenu();
    }
    if (state.fd >= 0 && IOS_Close() == 0)
        state.fd = -1;

    DVDLowInit();
    lbl_8055DA2C = 0;
    fn_8003A834(base + 0x740, (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    entry = (unsigned int *)(base - 0x4300);
    lbl_8055DA40 = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, 0x10000, (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    entry = (unsigned int *)(base - 0x42E0);
    lbl_8055DA3C = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, *(int *)((unsigned char *)lbl_8055DA40 + 4), (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0) {
        if (lbl_8055DA2C != (void *)1) {
            const char *format = lbl_803049C0;
            unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
            OSReport(format, status);
            __OSLaunchMenu();
        }
    }

    selected = 0;
    entry = (unsigned int *)lbl_8055DA3C;
    lbl_8055DA38 = 0;
    for (i = 0; (unsigned char)i < *(unsigned int *)lbl_8055DA40; i++) {
        if (entry[1] == 0) {
            selected = entry;
            lbl_8055DA38 = (unsigned int *)entry;
        }
        entry += 2;
        lbl_8055DA3C = (unsigned int *)entry;
    }
    lbl_8055DA2C = 0;
    DVDLowOpenPartition(*(unsigned int *)selected, 0, 0, 0, base - 0x42C0, (void *)fn_8004DDF4);
    if (lbl_8055DA2C != 0 && lbl_8055DA2C != (void *)1) {
        const char *format = lbl_803049C0;
        unsigned int status = *(volatile unsigned int *)&lbl_8055DA2C;
        OSReport(format, status);
        __OSLaunchMenu();
    }
}

extern unsigned char lbl_80560C74, lbl_80560C75, lbl_80560C76, lbl_80560C77;
void __OSLaunchMenu(void) {
    struct LocalState {
        volatile unsigned char b0, b1, b2, b3;
        int fd;
        unsigned int count;
    } state;
    register int fd = -1;
    register unsigned int count = 1;
    int error;
    int result;
    unsigned long long title;
    register unsigned char *titlePtr;
    register unsigned char b0, b1, b2, b3;

    state.count = count;
    state.fd = fd;
    error = 0;
    title = 0x0000000100000002ULL;
    titlePtr = lbl_8037D900;
    b0 = *(volatile unsigned char *)&lbl_80560C74;
    b1 = *(volatile unsigned char *)&lbl_80560C75;
    b2 = *(volatile unsigned char *)&lbl_80560C76;
    b3 = *(volatile unsigned char *)&lbl_80560C77;
    state.b0 = b0;
    state.b1 = b1;
    state.b2 = b2;
    state.b3 = b3;

    result = ((int (*)(const char *, int, unsigned char, unsigned char, unsigned char))IOS_Open)
        (&lbl_80558F40, 0, b2, b1, b0);
    state.fd = result;
    if (result < 0)
        error = result;
    if (error != 0)
        return;

    result = ((int (*)(int *, unsigned long long, void *, unsigned int *))_ES_GetTicketViews)
        ((int *)&state.fd, title, 0, (unsigned int *)&state.count);
    if (state.count != 1)
        return;
    if (result != 0)
        return;

    result = ((int (*)(int *, unsigned long long, void *, unsigned int *))_ES_GetTicketViews)
        ((int *)&state.fd, title, titlePtr, (unsigned int *)&state.count);
    if (result != 0)
        return;

    result = ((int (*)(int *, unsigned long long, void *))_ES_LaunchTitle)
        ((int *)&state.fd, title, titlePtr);
    if (result != 0)
        return;
}

extern int IOS_Open(const char *, int);
extern int IOS_Ioctlv(int, int, int, int, void *);
extern int _ES_GetTicketViews(int *, unsigned int, unsigned int, void *, unsigned int *);
extern int _ES_LaunchTitle(int *, unsigned int, unsigned int, void *);
extern const char lbl_80558F40;
static inline s32 _ES_InitLib(s32 *fd) {
    s32 result = 0;
    *fd = IOS_Open(&lbl_80558F40, 0);
    if (*fd < 0) {
        result = *fd;
    }
    return result;
}

static inline s32 _ES_GetTitleId(s32 *fd, u64 *tidOut) {
    u8 tidWork[256] ALIGN(32);
    u8 vectorWork[32] ALIGN(32);
    IPCIOVector *pVectors = (IPCIOVector *)vectorWork;
    u64 *pTid = (u64 *)tidWork;
    s32 result;

    if (*fd < 0 || tidOut == ((void *)NULL)) {
        return -0x3F9;
    }

    pVectors[0].base = pTid;
    pVectors[0].length = sizeof(u64);

    result = IOS_Ioctlv(*fd, 0x20, 0, 1, pVectors);
    if (result == 0) {
        *tidOut = *pTid;
    }
    return result;
}

void fn_8004E3F0(void) {
    u8 views[256] ALIGN(32);
    u64 titleId ALIGN(32);
    u32 count = 1;
    s32 fd = -1;
    s32 result;

    if (_ES_InitLib(&fd) != 0) {
        return;
    }

    if (_ES_GetTitleId(&fd, &titleId) != 0) {
        return;
    }

    result = ((s32 (*)(s32 *, u64, void *, u32 *))_ES_GetTicketViews)(&fd, titleId, NULL, &count);
    if (count != 1 || result != 0) {
        return;
    }

    if (((s32 (*)(s32 *, u64, void *, u32 *))_ES_GetTicketViews)(&fd, titleId, views, &count) != 0) {
        return;
    }

    if (((s32 (*)(s32 *, u64, void *))_ES_LaunchTitle)(&fd, titleId, views) != 0) {
        return;
    }

    while (1) {
    }
}

