// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void * volatile lbl_8055DA2C;
#pragma small_data on
extern char lbl_80558F40[];
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
    unsigned char *mem;
    unsigned char *base;
    register unsigned char *selected;
    register unsigned char *entry;
    unsigned char b0, b1, b2, b3;
    volatile unsigned char saved[4];
    int error;
    unsigned int i;
    unsigned long long title;
    int fd;
    int result;
    unsigned int count;

    b0 = lbl_80560C70;
    b1 = lbl_80560C71;
    b2 = lbl_80560C72;
    b3 = lbl_80560C73;
    saved[0] = b0;
    saved[1] = b1;
    saved[2] = b2;
    saved[3] = b3;
    mem = lbl_8037D900;
    base = mem + 0x10000;
    fd = -1;
    count = 1;
    lbl_8055DA2C = 0;
    ((int (*)(void *, int, int, int, int, int, int, void *))fn_8003AC24)((void *)fn_8004DDF4, b2, b1, b0, 0, -1, 1, mem);
    if (*(void * volatile *)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    entry = base - 0x4300;
    lbl_8055DA40 = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, 0x10000, (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    entry = base - 0x42E0;
    lbl_8055DA3C = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, *(int *)((unsigned char *)lbl_8055DA40 + 4), (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    selected = 0;
    entry = (unsigned char *)lbl_8055DA3C;
    lbl_8055DA38 = 0;
    for (i = 0; (unsigned char)i < *(unsigned int *)lbl_8055DA40; i++) {
        if (*(int *)(entry + 4) == 0) {
            selected = entry;
            lbl_8055DA38 = (unsigned int *)entry;
        }
        entry += 8;
        lbl_8055DA3C = (unsigned int *)entry;
    }
    lbl_8055DA2C = 0;
    DVDLowOpenPartition(*(unsigned int *)selected, 0, 0, 0, base - 0x42C0, (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    lbl_8055DA2C = 0;
    fn_8003AC24((void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    entry = base - 0x42C0;
    lbl_8055DA34 = entry;
    title = *(unsigned long long *)(entry + 0x184);
    error = 0;
    result = IOS_Open(lbl_80558F40, 0);
    fd = result;
    if (result < 0)
        error = result;
    if (error != 0) {
        OSReport(lbl_803049C0, error);
        __OSLaunchMenu();
    }

    result = ((int (*)(int *, unsigned long long, void *, unsigned int *))_ES_GetTicketViews)(&fd, title, 0, &count);
    if (count == 1 && result != 0) {
        OSReport(lbl_803049C0, result);
        __OSLaunchMenu();
    }
    result = ((int (*)(int *, unsigned long long, void *, unsigned int *))_ES_GetTicketViews)(&fd, title, mem, &count);
    if (result != 0) {
        OSReport(lbl_803049C0, result);
        __OSLaunchMenu();
    }
    result = ((int (*)(int *, unsigned long long, void *))_ES_LaunchTitle)(&fd, title, mem);
    if (result != 0) {
        OSReport(lbl_803049C0, result);
        __OSLaunchMenu();
    }
    if (fd >= 0 && IOS_Close() == 0)
        fd = -1;

    DVDLowInit();
    lbl_8055DA2C = 0;
    fn_8003A834(base + 0x740, (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    entry = base - 0x4300;
    lbl_8055DA40 = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, 0x10000, (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    entry = base - 0x42E0;
    lbl_8055DA3C = (unsigned int *)entry;
    lbl_8055DA2C = 0;
    fn_8003AD88(entry, 0x20, *(int *)((unsigned char *)lbl_8055DA40 + 4), (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }

    selected = 0;
    entry = (unsigned char *)lbl_8055DA3C;
    lbl_8055DA38 = 0;
    for (i = 0; (unsigned char)i < *(unsigned int *)lbl_8055DA40; i++) {
        if (*(int *)(entry + 4) == 0) {
            selected = entry;
            lbl_8055DA38 = (unsigned int *)entry;
        }
        entry += 8;
        lbl_8055DA3C = (unsigned int *)entry;
    }
    lbl_8055DA2C = 0;
    DVDLowOpenPartition(*(unsigned int *)selected, 0, 0, 0, base - 0x42C0, (void *)fn_8004DDF4);
    if (*(volatile void **)&lbl_8055DA2C != 0 && *(volatile void **)&lbl_8055DA2C != (void *)1) {
        OSReport(lbl_803049C0, *(volatile void **)&lbl_8055DA2C);
        __OSLaunchMenu();
    }
}
extern int IOS_Open(const char *, int);
extern int IOS_Ioctlv(int, int, int, int, void *);
extern int _ES_GetTicketViews(int *, unsigned int, unsigned int, void *, unsigned int *);
extern int _ES_LaunchTitle(int *, unsigned int, unsigned int, void *);
extern char lbl_80558F40[];
void fn_8004E3F0(void) {
    int fd;
    int result;
    unsigned int count;
    unsigned int title_hi;
    unsigned int title_lo;
    unsigned int views[0x60];
    unsigned int in[2];
    unsigned int vec[2];

    count = 1;
    fd = -1;
    result = IOS_Open(lbl_80558F40, 0);
    fd = result;
    if (result < 0)
        goto out;
    if (fd != 0)
        goto out;
    if ((result < 0) || (&title_hi == 0)) {
        result = -0x3F9;
        goto out;
    }
    vec[0] = (unsigned int)in;
    vec[1] = 8;
    result = IOS_Ioctlv(fd, 0x20, 0, 1, vec);
    if (result != 0)
        goto out;
    title_hi = in[0];
    title_lo = in[1];
    if (result != 0)
        goto out;
    result = _ES_GetTicketViews(&fd, title_hi, title_lo, 0, &count);
    if (count != 1)
        goto out;
    if (result != 0)
        goto out;
    result = _ES_GetTicketViews(&fd, title_hi, title_lo, views, &count);
    if (result != 0)
        goto out;
    result = _ES_LaunchTitle(&fd, title_hi, title_lo, views);
    if (result != 0)
        goto out;
    for (;;)
        ;
out:
    return;
}

