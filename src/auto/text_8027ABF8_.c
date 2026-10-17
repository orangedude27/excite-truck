// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
extern char lbl_804A433C[];
#pragma pop
extern void *fn_8027ACBC(void *, void *);
#pragma push
#pragma small_data off
void fn_8027ABF8(void *node) {
    fn_8027ACBC(lbl_804A433C, node);
}
int fn_8027AC08(void *arg0, int arg1) {
    int count = *(int *)((char *)arg0 + 0x88);
    void *entry = arg0;
    int i = 0;
    for (; i < count; i++, entry = (char *)entry + 8) {
        if (arg1 == *(int *)((char *)entry + 0x30))
            return *(int *)((char *)arg0 + 0x34 + i * 8);
    }
    return 0;
}
int fn_8027AC50(void *arg0) {
    return *(int *)((char *)arg0 + 0xF0) != 0;
}

int fn_8027AC64(void *arg0) {
    if (*(int *)((char *)arg0 + 0xF0) == 0) {
        return -1;
    }
    return *(int *)((char *)arg0 + 0xF8);
}

#pragma push
#pragma small_data off
int fn_8027AC80(void *arg0) {
    return fn_8027ACBC((void *)&lbl_804A433C, *(void **)((char *)arg0 + 0xE8)) != 0;
}

void *fn_8027ACBC(void *arg0, void *arg1) {
    int count = *(int *)((char *)arg0 + 0x30);
    int i = 0;
    void **entry = (void **)arg0;
    while (count-- > 0) {
        void *item = *entry;
        if ((int)arg1 == *(int *)item)
            return ((void **)arg0)[i];
        entry++;
        i++;
    }
    return 0;
}

#pragma pop
