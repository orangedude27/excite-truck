// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055DA2C;
extern char lbl_80558F40[];
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

