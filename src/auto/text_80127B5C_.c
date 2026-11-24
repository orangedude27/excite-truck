// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8041E098[];
extern int lbl_8055DF70;
extern char lbl_80329FC0[];
extern void Abend_Panic(const char *, ...);
extern char lbl_80329FA0[];

#pragma cplusplus on
struct B5Obj {
    virtual void slot0();
    virtual void call();
};
static inline void b5_dispatch(void *obj) {
    ((B5Obj *)obj)->call();
}
static inline void b5_dispatch_nonnull(void *obj) {
    if (obj != 0) {
        ((B5Obj *)obj)->call();
    }
}
#pragma cplusplus off

#pragma use_lmw_stmw off
void fn_80127B5C(int arg0) {
#pragma scheduling invalid_target
    unsigned char *entry;
    int i;
    int j;
    int count;

    ((unsigned char *)lbl_8041E098)[0] = 1;
    entry = (unsigned char *)lbl_8041E098 + 8;
    for (i = 0; i < lbl_8041E098[1]; entry += 16, i++) {
        void (*func)(void) = *(void (**)(void))entry;
        if (func != 0) {
            func();
        } else {
            void *obj = *(void **)(entry + 4);
            if (obj != 0) {
                void (*fn)(void *) = *(void (**)(void *))((char *)(*(void **)obj) + 0xC);
                fn(obj);
            }
        }
    }

    ((unsigned char *)lbl_8041E098)[0] = 0;
    entry = (unsigned char *)lbl_8041E098;
    j = 0;
    while (j < (count = *(volatile int *)&lbl_8041E098[1])) {
        if (entry[20] != 0) {
            if (j >= 0 && j < count) {
                if (((unsigned char *)lbl_8041E098)[0] != 0) {
                    entry[20] = 1;
                } else {
                    int last = *(volatile int *)&lbl_8041E098[1] - 1;
                    unsigned char *src = (unsigned char *)lbl_8041E098 + last * 16;
                    *(volatile int *)&lbl_8041E098[1] = last;
                    *(int *)(entry + 8) = *(int *)(src + 8);
                    *(int *)(entry + 12) = *(int *)(src + 12);
                    *(int *)(entry + 16) = *(int *)(src + 16);
                    entry[20] = src[20];
                }
            }
        } else {
            entry += 16;
            j++;
        }
    }

    lbl_8055DF70 = arg0;
}
#pragma use_lmw_stmw reset
/* Start-up hook of the "bg" background-task manager (the module whose log
 * strings read "bg: too many tasks (adding %s)" and "bg: Unfreed hook! \"%s\"").
 * It has nothing to do: the hook table at lbl_8041E098 sits in .bss (168 bytes =
 * an 8-byte header -- iteration flag at +0, entry count at +4 -- followed by 10
 * 16-byte entries of callback/object/name/deleted), so it is already empty when
 * the kernel start-up sequence (fn_802E2A5C) calls this.  fn_80127EF8 is the
 * matching shut-down, which reports the hooks that were never removed. */
void fn_80127C8C(void) {

}

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80127C90(int callback, int arg) {
    /* Register a callback task in the bg task table if space is available; log overflow otherwise. */
    int count;
    int *base;
    int masked;
    int shifted;
    int value;
    unsigned int available;
    char *entry;
    base = lbl_8041E098;
    count = base[1];
    value = count ^ 10;
    masked = value & 10;
    shifted = value >> 1;
    available = (unsigned int)(shifted - masked) >> 31;
    if (available != 0) {
        base[1] = count + 1;
        entry = (char *)base + count * 16;
        *(int *)(entry + 8) = callback;
        *(int *)(entry + 12) = 0;
        *(int *)(entry + 16) = arg;
        entry[20] = 0;
    }
    if (available == 0)
        ((void (*)(const char *, ...))Abend_Panic)(lbl_80329FA0);
}
void fn_80127CF4(int arg0, int arg1) {
    /* Register an object task in the bg task table if space is available; log overflow otherwise. */
    int count;
    int *base;
    int masked;
    int shifted;
    int value;
    unsigned int available;
    char *entry;
    base = lbl_8041E098;
    count = base[1];
    value = count ^ 10;
    masked = value & 10;
    shifted = value >> 1;
    available = (unsigned int)(shifted - masked) >> 31;
    if (available != 0) {
        base[1] = count + 1;
        entry = (char *)base + count * 16;
        *(int *)(entry + 8) = 0;
        *(int *)(entry + 12) = arg0;
        *(int *)(entry + 16) = arg1;
        entry[20] = 0;
    }
    if (available == 0)
        ((void (*)(const char *, ...))Abend_Panic)(lbl_80329FC0);
}
/* Remove the alarm entry whose id matches arg0 and whose object slot (+0xC) is 0.
 * If the table is currently iterating (lbl_8041E098 byte 0 set), mark the entry
 * for deferred deletion (byte at +0x14). Otherwise swap-remove it with the last
 * entry and decrement the count at +4. Entries are 16 bytes. */
void fn_80127D58(unsigned int arg0) {
    char *entry = (char *)lbl_8041E098;
    int i = 0;
    int count = *(int *)(entry + 4);
    for (; i < count; entry += 16, i++) {
        int found = 0;
        if (*(unsigned int *)(entry + 8) == arg0 && *(int *)(entry + 12) == 0)
            found = 1;
        if (found != 0) {
            if (i < 0)
                return;
            if (i >= count)
                return;
            if (*(unsigned char *)lbl_8041E098 != 0) {
                char *mark = (char *)lbl_8041E098;
                mark += i * 16;
                mark[20] = 1;
                return;
            }
            {
                char *dest;
                int last;
                char *base = (char *)lbl_8041E098;
                last = *(int *)(base + 4);
                dest = base + i * 16;
                last--;
                *(int *)(base + 4) = last;
                {
                    char *src = base + last * 16;
                    *(int *)(dest + 8) = *(int *)(src + 8);
                    *(int *)(dest + 12) = *(int *)(src + 12);
                    *(int *)(dest + 16) = *(int *)(src + 16);
                    dest[20] = src[20];
                }
            }
            return;
        }
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Remove the object-task entry whose object pointer (+0xC) matches arg0 and whose
 * callback slot (+8) is 0. If the table is currently iterating (lbl_8041E098 byte 0
 * set), mark the entry for deferred deletion (byte at +0x14). Otherwise swap-remove
 * it with the last entry and decrement the count at +4. Entries are 16 bytes. */
void fn_80127E28(unsigned int object) {
    char *cursor = (char *)lbl_8041E098;
    int i = 0;
    int count = *(int *)(cursor + 4);
    for (; i < count; cursor += 16, i++) {
        int matched = 0;
        if (*(int *)(cursor + 8) == 0 && *(unsigned int *)(cursor + 12) == object)
            matched = 1;
        if (matched != 0) {
            if (i < 0)
                return;
            if (i >= count)
                return;
            if (*(unsigned char *)lbl_8041E098 != 0) {
                char *mark = (char *)lbl_8041E098;
                mark += i * 16;
                mark[20] = 1;
                return;
            }
            {
                char *dest;
                int last;
                char *base = (char *)lbl_8041E098;
                last = *(volatile int *)(base + 4);
                dest = base + i * 16;
                last--;
                *(volatile int *)(base + 4) = last;
                {
                    char *src = base + last * 16;
                    *(int *)(dest + 8) = *(int *)(src + 8);
                    *(int *)(dest + 12) = *(int *)(src + 12);
                    *(int *)(dest + 16) = *(int *)(src + 16);
                    dest[20] = src[20];
                }
            }
            return;
        }
    }
}
#pragma pop
extern int fn_802E2C20();
extern void fn_80127B5C();
extern int lbl_8055DF70;
extern int lbl_8041E098[];
extern char lbl_80329FE8[];
extern char lbl_80329FC0[];
extern char lbl_80329FA0[];
extern void fn_802E30C8();
void fn_80127EF8(void) {
    /* Log each hook that was not freed before shutdown. */
    int *hookEntry = lbl_8041E098;
    int i;

    for (i = 0; i < lbl_8041E098[1]; hookEntry += 4, i++) {
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_80329FE8, hookEntry[4]);
    }
}

/* OSAlarm callback: dispatch pending background tasks, recording the current
 * elapsed-millisecond time (fn_802E2C20) as the last dispatch time. */
void fn_80127F70(void* alarm) {
    fn_80127B5C(fn_802E2C20(alarm));
}

void fn_80127F94(void) {
    /* Dispatch pending background tasks when over 16 ms have elapsed since the last dispatch (lbl_8055DF70). */
    if (fn_802E2C20() - lbl_8055DF70 > 0x10)
        fn_80127B5C();
}

