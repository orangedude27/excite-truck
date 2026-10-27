// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_804C109C[];
extern void fn_802C6CF8(void *);
extern char lbl_8034AFE8[];
extern char lbl_8055CFD0;
extern char lbl_8055CFD8;
extern char lbl_8055CFE0;
extern char lbl_8055CFE8;
extern float lbl_80564E90;
extern float lbl_80564E94;
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern void fn_801345D8(void *, int, void *, ...);
extern int fn_802C6FC0(int, int);
extern float fn_80129DC4(int, float, float);
void fn_802C2298(void) {
    char query[0x20];
    float values[3];
    int temp_r5;
    int temp_r6;
    int index;
    void **iterator;
    void **manager;
    void **entry;
    void *record;
    int *data;

    data = (int *)lbl_804C109C;
    data[1] = 0;
    manager = fn_80131810(lbl_8034AFE8);
    if (manager != 0) {
        iterator = ((void **(*)(void *, void *))(*(void **)((char *)*(void **)manager + 8)))(manager, (void *)&lbl_8055CFD0);
        index = 1;
        fn_801345D8(query, 0x20, (void *)&lbl_8055CFD8, 0);
        entry = ((void **(*)(void *, void *))(*(void **)((char *)*(void **)iterator + 0x5C)))(iterator, query);
        while (entry != 0) {
            temp_r5 = data[1];
            data[1] = temp_r5 + 1;
            record = (void *)((char *)data[0] + temp_r5 * 0x14);
            ((void (*)(void *, void *, int, void *))(*(void **)((char *)*(void **)entry + 0x14)))(entry, (void *)&lbl_8055CFE0, temp_r5, (void *)data[0]);
            *(int *)record = fn_802C6FC0(0, 0);
            ((void (*)(float *, void *, void *))(*(void **)((char *)*(void **)entry + 0x34)))(values, entry, (void *)&lbl_8055CFE8);
            ((float *)record)[1] = values[0];
            ((float *)record)[2] = values[1];
            ((float *)record)[3] = values[2];
            ((float *)record)[4] = fn_80129DC4(0, lbl_80564E90, lbl_80564E94);
            temp_r6 = index;
            index++;
            fn_801345D8(query, 0x20, (void *)&lbl_8055CFD8, temp_r6);
            entry = ((void **(*)(void *, void *))(*(void **)((char *)*(void **)iterator + 0x5C)))(iterator, query);
        }
        fn_80131818(manager);
    }
}

void fn_802C2410(void) {
    int i = 0;
    while (i < *(int *)((char *)lbl_804C109C + 4)) {
        fn_802C6CF8(*(void **)((char *)lbl_804C109C[0] + i * 0x14));
        i++;
    }
    *(int *)((char *)lbl_804C109C + 4) = 0;
}
