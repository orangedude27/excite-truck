// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *memcpy(void *, const void *, unsigned long);
extern int lbl_8055FFC8;
extern unsigned char lbl_804FC8B0[];
extern int lbl_8055FFC0;
extern unsigned char lbl_8055FFC4;
extern unsigned char lbl_8055FFC5;
extern void *memset(void *, int, unsigned long);
extern void *fn_802E6FBC(void);
extern int fn_802E30C8(const char *, ...);
extern char lbl_8034D678[];
extern int lbl_8055D200;
extern void *fn_801284E8(void *, int);
extern void fn_80128658(void *);
extern unsigned int fn_80132E7C(void *, int);
extern void *fn_802E967C(int, void *, int);
extern int fn_802E7130(void);
extern int fn_802E721C(unsigned int, unsigned int, int);
extern int fn_802E8D8C(void *, void *, int);
extern unsigned int lbl_8034D7B0[];
void fn_802E6B50(void) {
    unsigned int size = 0xC8;
    memset(lbl_804FC8B0, 0, size);
    lbl_8055FFC0 = 0;
    lbl_8055FFC4 = 1;
    lbl_8055FFC5 = 0;
}
#pragma scheduling on
void fn_802E6B94(void) {}

void *fn_802E6B98(int arg0) {
    int sp8 = arg0;
    ((unsigned char *)&lbl_8055FFC8)[4] = 0;
    memcpy(&lbl_8055FFC8, &sp8, 4);
    return &lbl_8055FFC8;
}

#pragma dont_inline on
extern void fn_802E317C(const char *, ...);
extern char lbl_8034D690[];
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma push
#pragma use_lmw_stmw off
void fn_802E6BD8(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    unsigned char *record;
    int i;
    int count;

    fn_802E30C8(lbl_8034D678, fn_802E6B98(a), b, d);
    record = lbl_804FC8B0;
    i = 0;
    goto loop_check;
loop_body:
    if (a == *(unsigned int *)record)
        fn_802E317C(lbl_8034D690, a);
    record += 0x14;
    i++;
loop_check:
    if (i < lbl_8055FFC0)
        goto loop_body;

    count = lbl_8055FFC0;
    record = lbl_804FC8B0 + count * 0x14;
    *(unsigned int *)(record + 0) = a;
    *(unsigned int *)(record + 4) = b;
    *(unsigned int *)(record + 8) = c;
    *(unsigned int *)(record + 0xC) = d;
    lbl_8055FFC0 = count + 1;
    *(unsigned int *)(record + 0x10) = e;
}
#pragma pop
#pragma scheduling on
#pragma dont_inline off

void fn_802E6CA4(void) {}

int fn_802E6CA8(void) {
    unsigned char *allocation;
    char *messages = lbl_8034D678;
    int size;
    int payloadSize;
    unsigned char flags[10];
    int success;
    int readError;
    int i;
    int result;
    int temp;
    unsigned char *desc;
    unsigned char *descIt;
    unsigned char *dataIt;
    unsigned char *slot;
    unsigned char *flagIt;
    void (*callback)(int);

    size = fn_802E7130();
    payloadSize = size - 0x20D0;
    allocation = (unsigned char *)fn_801284E8(messages + 0x40, size);
    memset(allocation, 0, 0x20D0);
    memset(allocation + 0x20D0, 0, payloadSize);
    flags[0] = 0; flags[1] = 0; flags[2] = 0; flags[3] = 0; flags[4] = 0;
    flags[5] = 0; flags[6] = 0; flags[7] = 0; flags[8] = 0; flags[9] = 0;
    success = 0;
    readError = 0;

    if (fn_802E8D8C((void *)lbl_8055D200, allocation, size) == 0) {
        fn_802E30C8(messages + 0x50);
        readError = 1;
    } else {
        temp = *(int *)(allocation + 0x204C);
        if (temp != payloadSize) {
            fn_802E30C8(messages + 0x68, payloadSize);
        } else if (*(unsigned int *)(allocation + 0x2040) != 0x4D435348 ||
                   *(unsigned int *)(allocation + 0x2044) != 4 ||
                   *(unsigned int *)(allocation + 0x2048) != 0x20D0 ||
                   (unsigned int)temp != (unsigned int)payloadSize) {
            fn_802E30C8(messages + 0x88);
            fn_802E30C8(messages + 0xB0,
                        *(unsigned int *)(allocation + 0x2040),
                        *(unsigned int *)(allocation + 0x2044),
                        *(unsigned int *)(allocation + 0x2048),
                        *(unsigned int *)(allocation + 0x204C));
            fn_802E30C8(messages + 0xC4, payloadSize);
        } else {
            result = ((unsigned int (*)(void *))fn_80132E7C)(allocation + 0x20D0);
            if (result != *(unsigned int *)(allocation + 0x2050)) {
                fn_802E30C8(messages + 0xD4, result);
            } else {
                desc = allocation + 0x2058;
                descIt = desc;
                dataIt = allocation + 0x20D0;
                success = 1;
                i = 0;
                goto first_check;
first_body:
                if (fn_802E721C(*(unsigned int *)(descIt + 0),
                                *(unsigned int *)(descIt + 4),
                                *(int *)(descIt + 8)) < 0) success = 0;
                descIt += 0xC;
                i++;
first_check:
                if (i < *(int *)(allocation + 0x2054)) goto first_body;

                if (success != 0) {
                    descIt = desc;
                    i = 0;
                    goto second_check;
second_body:
                    result = fn_802E721C(*(unsigned int *)(descIt + 0),
                                         *(unsigned int *)(descIt + 4),
                                         *(int *)(descIt + 8));
                    if (result >= 0) {
                        (&flags[0])[result] = 1;
                        slot = lbl_804FC8B0 + result * 0x14;
                        callback = *(void (**)(int))(slot + 0x10);
                        if (callback != 0) callback(0);
                        memcpy(*(void **)(slot + 8), dataIt,
                               *(unsigned int *)(slot + 0xC));
                        callback = *(void (**)(int))(slot + 0x10);
                        if (callback != 0) callback(1);
                    } else {
                        success = 0;
                    }
                    {
                        unsigned int amount = *(unsigned int *)(descIt + 8);
                        descIt += 0xC;
                        i++;
                        dataIt += amount;
                    }
second_check:
                    if (i < *(int *)(allocation + 0x2054)) goto second_body;
                }
            }
        }
    }

    fn_80128658(allocation);
    if (success == 0) {
        int anyMissing = 0;
        flagIt = flags;
        {
            int scanCount = lbl_8055FFC0;
            if (scanCount > 0) {
                while (scanCount--) {
                    if (*flagIt == 0) anyMissing = 1;
                    flagIt++;
                }
            }
        }
        if (anyMissing != 0) {
            slot = lbl_804FC8B0;
            i = 0;
            while (i < lbl_8055FFC0) {
                callback = *(void (**)(int))(slot + 0x10);
                if (callback != 0) callback(2);
                slot += 0x14;
                i++;
            }
        }
        if (readError == 0) {
            fn_802E30C8(messages + 0xF8);
        } else {
            fn_802E6FBC();
        }
    }
    return 0;
}

extern char lbl_8034D6B8[];
extern char lbl_8034D784[];
#pragma push
#pragma use_lmw_stmw off
void *fn_802E6FBC(void) {
    register unsigned char *entry;
    register unsigned char *descriptor;
    register int i;
    register int size = fn_802E7130();
    register unsigned char *allocation;
    register unsigned char *data;
    unsigned int amount;
    void (*callback)(int);
    void *result;

    allocation = (unsigned char *)fn_801284E8(lbl_8034D6B8, size);
    memset(allocation, 0, 0x20D0);
    *(unsigned int *)(allocation + 0x2040) = 0x4D435348;
    *(unsigned int *)(allocation + 0x2044) = 4;
    *(unsigned int *)(allocation + 0x2048) = 0x20D0;
    *(unsigned int *)(allocation + 0x204C) = size - 0x20D0;
    *(unsigned int *)(allocation + 0x2054) = lbl_8055FFC0;

    memset(allocation + 0x20D0, 0, size - 0x20D0);
    data = allocation + 0x20D0;
    entry = lbl_804FC8B0;
    descriptor = allocation + 0x2058;
    i = 0;
    goto loop_check;
loop_body:
    *(unsigned int *)(descriptor + 0) = *(unsigned int *)(entry + 0);
    *(unsigned int *)(descriptor + 4) = *(unsigned int *)(entry + 4);
    *(unsigned int *)(descriptor + 8) = *(unsigned int *)(entry + 0xC);
    callback = *(void (**)(int))(entry + 0x10);
    if (callback != 0)
        callback(3);
    memcpy(data, *(void **)(entry + 8), *(unsigned int *)(entry + 0xC));
    callback = *(void (**)(int))(entry + 0x10);
    if (callback != 0)
        callback(4);
    amount = *(unsigned int *)(entry + 0xC);
    i++;
    entry += 0x14;
    data += amount;
    descriptor += 0xC;
loop_check:
    if (i < lbl_8055FFC0)
        goto loop_body;

    *(unsigned int *)(allocation + 0x2050) =
        fn_80132E7C(allocation + 0x20D0, *(unsigned int *)(allocation + 0x204C));
    fn_802E30C8(lbl_8034D784, (size + 0x1FFF) / 0x2000, size);
    result = fn_802E967C(lbl_8055D200, allocation, size);
    fn_80128658(allocation);
    return result;
}
#pragma pop

void fn_802E7128(void) { fn_802E6FBC(); }

void fn_802E712C(void) {}

#pragma scheduling invalid_target
int fn_802E7130(void) {
    int count = lbl_8055FFC0;
    int total = 0x20D0;
    int i = 0;
    unsigned char *entry = lbl_804FC8B0;
    while (i < count) {
        total += *(int *)(entry + 0xC);
        entry += 0x14;
        i++;
    }
    return (total + 0x1FFF) & 0xFFFFE000;
}
#pragma scheduling on

