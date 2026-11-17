// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
extern char lbl_804A433C[];
#pragma pop
extern void *fn_8027ACBC(void *, void *);
#pragma push
#pragma small_data off
/* Look up item in the global registry table via fn_8027ACBC. */
void fn_8027ABF8(void *item) {
    fn_8027ACBC(lbl_804A433C, item);
}
#pragma scheduling invalid_target
/* Look an id up in the table of (id, value) pairs a global-registry entry (the
 * object fn_8027ABF8 hands back) carries: the pairs start at +0x30, eight bytes
 * apart, and their count sits at +0x88.  Returns the value stored with the id,
 * or 0 when the table holds no such id. */
int fn_8027AC08(void *table, int id) {
    int i;
    char *entry = (char *)table;
    for (i = 0; i < *(int *)((char *)table + 0x88); entry += 8, i++) {
        if (id == *(int *)(entry + 0x30))
            return *(int *)((char *)table + 0x34 + i * 8);
    }
    return 0;
}
/* Nonzero when the team entry's mode flag (TeamEntry +0xF0) is set. */
int fn_8027AC50(void *team) {
    return *(int *)((char *)team + 0xF0) != 0;
}

int fn_8027AC64(void *team) {
    /* Return the linked "other team" id (TeamEntry +0xF8) when the entry's mode
     * flag (+0xF0) is set, otherwise -1 for an inactive entry. */
    if (*(int *)((char *)team + 0xF0) == 0) {
        return -1;
    }
    return *(int *)((char *)team + 0xF8);
}

#pragma push
#pragma small_data off
int fn_8027AC80(void *arg0) {
    return fn_8027ACBC((void *)&lbl_804A433C, *(void **)((char *)arg0 + 0xE8)) != 0;
}

void *fn_8027ACBC(void *table, void *key) {
    /* Search the global registry table (count at +0x30) for the entry whose first
       int field equals key; return that entry pointer, or NULL if not found. */
    void **entry = (void **)table;
    int index;
    int count = *(int *)((char *)table + 0x30);
    for (index = 0; index < count; index++) {
        int *entryKey = *(int **)entry;
        if ((int)key == *entryKey)
            return ((void **)table)[index];
        entry++;
    }
    return (void *)0;
}

#pragma pop
