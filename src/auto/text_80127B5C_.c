// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8041E098[];
extern int lbl_8055DF70;
extern char lbl_80329FC0[];
extern void fn_802E317C(const char *, ...);
extern char lbl_80329FA0[];

void fn_80127B5C(int arg0) {
    char *base = (char *)lbl_8041E098;
    char *entry = base + 8;
    int i;
    int j;
    char *dest;

    *(unsigned char *)base = 1;
    for (i = 0; i < *(int *)(base + 4); i++, entry += 16) {
        void (*func)(void) = *(void (**)(void))entry;
        if (func != 0) {
            func();
        } else {
            void *obj = *(void **)(entry + 4);
            if (obj != 0) {
                ((void (*)(void *))(*(void ***)obj)[3])(obj);
            }
        }
    }

    *(unsigned char *)base = 0;
    j = 0;
    dest = base;
    while (j < *(int *)(base + 4)) {
        if (dest[20] != 0) {
            if (j >= 0 && j < *(int *)(base + 4)) {
                if (*(unsigned char *)lbl_8041E098 != 0) {
                    dest[20] = 1;
                } else {
                    int last = *(int *)(base + 4) - 1;
                    char *src = base + last * 16;
                    *(int *)(base + 4) = last;
                    *(int *)(dest + 8) = *(int *)(src + 8);
                    *(int *)(dest + 12) = *(int *)(src + 12);
                    *(int *)(dest + 16) = *(int *)(src + 16);
                    dest[20] = src[20];
                }
            }
        } else {
            dest += 16;
            j++;
        }
    }

    lbl_8055DF70 = arg0;
}

void fn_80127C8C(void) {

}

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80127C90(int arg0, int arg1) {
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
        *(int *)(entry + 8) = arg0;
        *(int *)(entry + 12) = 0;
        *(int *)(entry + 16) = arg1;
        entry[20] = 0;
    }
    if (available == 0)
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80329FA0);
}
void fn_80127CF4(int arg0, int arg1) {
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
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80329FC0);
}
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
void fn_80127E28(unsigned int arg0) {
    int i;
    int count;
    char *entry;
    int found;
    int last;
    count = lbl_8041E098[1];
    for (i = 0, entry = (char *)lbl_8041E098; i < count; i++, entry += 16) {
        found = 0;
        if (*(int *)(entry + 8) == 0) {
            if (*(unsigned int *)(entry + 12) == arg0)
                found = 1;
        }
        if (found != 0) {
            if (i >= 0 && i < count) {
                if (*(unsigned char *)lbl_8041E098 != 0) {
                    *((char *)lbl_8041E098 + i * 16 + 20) = 1;
                    return;
                }
                last = *(volatile int *)&lbl_8041E098[1];
                last = last - 1;
                *(volatile int *)&lbl_8041E098[1] = last;
                entry = (char *)lbl_8041E098 + i * 16;
                *(int *)(entry + 8) = *(int *)((char *)lbl_8041E098 + last * 16 + 8);
                *(int *)(entry + 12) = *(int *)((char *)lbl_8041E098 + last * 16 + 12);
                *(int *)(entry + 16) = *(int *)((char *)lbl_8041E098 + last * 16 + 16);
                entry[20] = *((char *)lbl_8041E098 + last * 16 + 20);
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
    int *entry = lbl_8041E098;
    int i;
    for (i = 0; i < lbl_8041E098[1]; entry += 4, i++) {
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_80329FE8, entry[4]);
    }
}

void fn_80127F70(void* alarm) {
    fn_80127B5C(fn_802E2C20(alarm));
}

void fn_80127F94(void) {
    if (fn_802E2C20() - lbl_8055DF70 > 0x10)
        fn_80127B5C();
}

