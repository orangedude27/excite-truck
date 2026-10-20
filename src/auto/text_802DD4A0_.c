// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *fn_80128668(void *);
void fn_80128670(int);
extern void *lbl_8055FED8;
extern float lbl_804DB6A0[];
void *fn_802DD4A0(void *arg0, int arg1) {
    void *local = arg0;
    if (arg0 != (void*)0) {
        if ((arg0 != (void*)0) && (arg0 != (void*)0)) {
            *(int*)arg0 = 0;
            *(int*)((char*)arg0 + 4) = 0;
            *(int*)((char*)arg0 + 8) = 0;
        }
        if (arg1 > 0) {
            fn_80128668(local);
        }
    }
    return local;
}

extern int lbl_8055FED0;
extern int lbl_8055FED4;
extern char lbl_8034CB50[];
extern char lbl_8034CB5C[];
void *fn_802D2D14(void);
void *fn_801284F8(int, void *);
int fn_8012850C(int, void *);
void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, int);
void GXInitTexObjFilter(void *, int, int);
static inline void set_size(void *obj, int w, int h, int halve) {
    if (halve) {
        *(int *)((char *)obj + 0x44) = w / 2;
        *(int *)((char *)obj + 0x48) = h / 2;
    } else {
        *(int *)((char *)obj + 0x44) = w;
        *(int *)((char *)obj + 0x48) = h;
    }
}
void fn_802DD4FC(void) {
    void *info = fn_802D2D14();
    lbl_8055FED0 = *(unsigned short *)((char *)info + 4);
    lbl_8055FED4 = *(unsigned short *)((char *)info + 6);
    {
        void *obj = fn_801284F8(0x50, lbl_8034CB50);
        if (obj != 0) {
            *(unsigned char *)((char *)obj + 0x4C) = 1;
            *(int *)((char *)obj + 0x44) = lbl_8055FED0 / 2;
            *(int *)((char *)obj + 0x48) = lbl_8055FED4 / 2;
            goto skip;
            *(int *)((char *)obj + 0x44) = lbl_8055FED0;
            *(int *)((char *)obj + 0x48) = lbl_8055FED4;
skip:
            *(int *)((char *)obj + 0x40) = fn_8012850C(*(int *)((char *)obj + 0x48) * (*(int *)((char *)obj + 0x44) * 2), lbl_8034CB5C);
            GXInitTexObj(obj, *(void **)((char *)obj + 0x40), *(int *)((char *)obj + 0x44), *(int *)((char *)obj + 0x48), 4, 0, 0, 0);
            GXInitTexObjFilter(obj, 1, 1);
            *(unsigned char *)((char *)obj + 0x4D) = 0;
        }
        lbl_8055FED8 = obj;
    }
}

void fn_802DD5F4(void) {
    void *temp_r31 = lbl_8055FED8;

    if (temp_r31 != 0) {
        fn_80128670(*(int*)((char*)temp_r31 + 0x40));
        fn_80128668(temp_r31);
    }
    lbl_8055FED8 = 0;
}

extern float lbl_80565088, lbl_8056508C, lbl_80565090, lbl_80565094;
void fn_802DD63C(int count) {
    float f0 = lbl_80565090;
    float f1 = lbl_8056508C;
    float f2 = lbl_80565094;
    float f3 = lbl_80565088;
    int i;
    float *entry;

    *(int *)((char *)lbl_804DB6A0 + 0x90) = count;
    entry = lbl_804DB6A0;
    for (i = 0; i < *(int *)((char *)lbl_804DB6A0 + 0x90); entry += 9, i++) {
        if (*(int *)((char *)lbl_804DB6A0 + 0x90) < 3) {
            entry[0] = f3; entry[1] = f1; entry[4] = f0; entry[5] = f1;
        } else if (i % 2 == 0) {
            entry[0] = f3; entry[1] = f0; entry[4] = f0; entry[5] = f2;
        } else {
            entry[0] = f0; entry[1] = f1; entry[4] = f2; entry[5] = f1;
        }
        if (*(int *)((char *)lbl_804DB6A0 + 0x90) == 1) {
            entry[2] = f1; entry[3] = f3; entry[6] = f0; entry[7] = f1;
        } else if (i < (*(int *)((char *)lbl_804DB6A0 + 0x90) + 1) / 2) {
            entry[2] = f1; entry[3] = f0; entry[6] = f0; entry[7] = f2;
        } else {
            entry[2] = f0; entry[3] = f3; entry[6] = f2; entry[7] = f1;
        }
        entry[8] = f0;
    }
    *(unsigned char *)((char *)lbl_8055FED8 + 0x4D) = 0;
}

void fn_802DD738(int arg0, float farg0) {
    *(float *)((char *)lbl_804DB6A0 + (arg0 * 0x24) + 0x20) = farg0;
}

void fn_802DD750(void) {
}

#pragma scheduling invalid_target
void fn_802DE774(void) {
    *(int *)((char *)lbl_804DB6A0 + 0x90) = 0;
}
#pragma scheduling on
void fn_802DEA6C(void* alarm) {
    fn_802D3360(fn_802DEF70(alarm));
}
