// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E8D8;
extern int lbl_8055E8DC;
struct Entry { int first; int second; int value; };
extern struct Entry lbl_80438758[];
extern void fn_80128668(void *);
void *fn_801D0B34(void *object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            ((int *)object)[0] = 0;
            ((int *)object)[1] = 0;
            ((int *)object)[2] = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

void *fn_801D0B8C(void *object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            ((int *)object)[0] = 0;
            ((int *)object)[1] = 0;
            ((int *)object)[2] = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Reset the global key/value entry registry (table lbl_80438758, live count lbl_8055E8D8) used by fn_801D0BF8/fn_801D0C58/fn_801D0C84: zero the entry count and its companion counter lbl_8055E8DC. Called once while initializing the physics module. */
void fn_801D0BE4(void) {
    lbl_8055E8D8 = 0;
    lbl_8055E8DC = 0;
}

void fn_801D0BF4(void) {

}

int fn_801D0BF8(int arg0, int arg1) {
    struct Entry *entry = lbl_80438758;
    int i;
    int count = lbl_8055E8D8;
    if (count > 0) {
        for (i = 0; i < count; entry++, i++) {
            if (arg0 == entry->first && arg1 == entry->second)
                return lbl_80438758[i].value;
        }
    }
    return 0;
}

#pragma push
#pragma optimization_level 3
void fn_801D0C58(int arg0, int arg1, int arg2) {
    register volatile struct Entry *entry;
    register int count;
    count = lbl_8055E8D8;
    entry = (volatile struct Entry *)&lbl_80438758[count];
    entry->second = arg2;
    ((volatile struct Entry *)lbl_80438758)[count].first = arg1;
    ((volatile struct Entry *)lbl_80438758)[count].value = arg0;
    *(volatile int *)&lbl_8055E8D8 = count + 1;
}
#pragma pop
void fn_801D0C84(unsigned int arg0) {
    int count = lbl_8055E8D8;
    struct Entry *entry = lbl_80438758;
    struct Entry *base = entry;
    int i;
    for (i = 0; i < count; ) {
        if ((unsigned int)entry->value == arg0) {
            int off;
            count--;
            off = count * 12;
            lbl_8055E8D8 = count;
            entry->first = *(int *)((char *)base + off);
            entry->second = *(int *)((char *)base + off + 4);
            entry->value = *(int *)((char *)base + off + 8);
        } else {
            entry++;
            i++;
        }
    }
}

