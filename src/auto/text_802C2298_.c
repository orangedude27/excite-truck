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
extern int fn_802C6FC0(int, int, int);
extern float fn_80129DC4(int, float, float);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802C2298(void) {
    struct Manager { virtual void **get(void *); };
    struct Iterator {
        virtual void *m0(); virtual void *m1(); virtual void *m2(); virtual void *m3();
        virtual void *m4(); virtual void *m5(); virtual void *m6(); virtual void *m7();
        virtual void *m8(); virtual void *m9(); virtual void *m10(); virtual void *m11();
        virtual void *m12(); virtual void *m13(); virtual void *m14(); virtual void *m15();
        virtual void *m16(); virtual void *m17(); virtual void *m18(); virtual void *m19();
        virtual void *m20(); virtual void **find(char *);
    };
    struct Entry {
        virtual void *m0(); virtual void *m1(); virtual void *m2();
        virtual void *create(void *, int, void *);
    };
    char query[0x20];
    float values[3];
    float value0, arg1, arg2;
    int temp_r5;
    int temp_r6;
    void *record;
    void **manager;
    void **iterator;
    int index;
    void **entry;

    *(int *)((char *)lbl_804C109C + 4) = 0;
    manager = (void **)fn_80131810(lbl_8034AFE8);
    if (manager != 0) {
        iterator = ((Manager *)manager)->get((void *)&lbl_8055CFD0);
        index = 1;
        fn_801345D8(query, 0x20, (void *)&lbl_8055CFD8, 0);
        entry = ((Iterator *)iterator)->find(query);
        while (entry != 0) {
            temp_r5 = *(int *)((char *)lbl_804C109C + 4);
            *(int *)((char *)lbl_804C109C + 4) = temp_r5 + 1;
            record = (void *)((char *)*(void **)lbl_804C109C + temp_r5 * 0x14);
            *(int *)record = fn_802C6FC0(
                (int)((Entry *)entry)->create((void *)&lbl_8055CFE0, temp_r5, *(void **)lbl_804C109C),
                0, 0);
            {
                void (*fill)(float *, void *, void *) = (void (*)(float *, void *, void *))(*(void **)((char *)*(void **)entry + 0x34));
                fill(values, entry, (void *)&lbl_8055CFE8);
            }
            value0 = values[0];
            arg1 = lbl_80564E90;
            ((float *)record)[1] = value0;
            arg2 = lbl_80564E94;
            ((float *)record)[2] = values[1];
            ((float *)record)[3] = values[2];
            ((float *)record)[4] = fn_80129DC4(0, arg1, arg2);
            temp_r6 = index;
            index++;
            fn_801345D8(query, 0x20, (void *)&lbl_8055CFD8, temp_r6);
            entry = ((Iterator *)iterator)->find(query);
        }
        fn_80131818(manager);
    }
}
#pragma cplusplus reset
#pragma scheduling on

void fn_802C2410(void) {
    int i = 0;
    while (i < *(int *)((char *)lbl_804C109C + 4)) {
        fn_802C6CF8(*(void **)((char *)lbl_804C109C[0] + i * 0x14));
        i++;
    }
    *(int *)((char *)lbl_804C109C + 4) = 0;
}
