// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801DE88C(void) {

}

extern int lbl_8055E9E8;
extern int lbl_8055E9DC;
extern int lbl_8055E9EC;
extern int lbl_8055ADF0;
extern int lbl_8055ADF4;
extern int lbl_8055E9E0;
extern float lbl_80562BE8;
extern float lbl_80562BF4;
extern int lbl_80339570;
extern int lbl_804872B0;
extern char lbl_804873B8[];
extern int fn_801E85A4(void);
extern int fn_801DE9F0(int, int);
extern int fn_80209190(int, float);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_801769EC(void);
extern int fn_8000DA10(void);
extern void fn_801332D0(int, int*, int*);
int fn_801DF060(void) {
    int val = lbl_8055E9E8;
    unsigned int tmp = (unsigned int)(-val) | (unsigned int)val;
    return (int)(tmp >> 31);
}

extern float lbl_80562BF8, lbl_80562BFC, lbl_80562C00, lbl_80562C04, lbl_80562C08, lbl_80562C0C, lbl_80562C10;
extern int lbl_8055AE28;
extern int lbl_803395C4;
extern int fn_801769F8(void);
extern void fn_80011278(int, float, float, float, float);
extern void fn_800103B8(int, int, int, int, float, float, float, float);
extern void fn_8000FF88(int, int, int, float, float, float);
extern void fn_801DE890(int);
extern void fn_80011A2C(void);
int fn_801DF110(void) {
    int idx = lbl_8055E9E8;
    int *base = (int *)((char *)&lbl_804872B0);
    int *entry;
    int (*callback)(int, int);
    int *object;
    if (idx == 0) return 0;
    if (fn_801769F8() == 0) return 1;
    entry = base + idx * 7;
    callback = (int (*)(int,int))entry[6];
    if (callback == 0) {
        fn_80011278(-1, lbl_80562BF8, lbl_80562BFC, lbl_80562C00, lbl_80562C04);
        fn_800103B8(-1, 0xC, (int)&lbl_8055AE28, entry[1], lbl_80562BF4, lbl_80562BE8, lbl_80562C08, lbl_80562C0C);
        fn_8000FF88(-1, 0xC, (int)&lbl_803395C4, lbl_80562BF4, lbl_80562BE8, lbl_80562C10);
        fn_801DE890(idx);
    } else callback(entry[2], entry[1]);
    object = (int *)entry[4];
    if (object != 0) (*(void (**)(void))(*(int *)*object + 0xC))();
    fn_80011A2C();
    return 1;
}

int fn_801DF238(int arg0) {
    extern int fn_801769F8(void);
    extern int fn_801DE9F0(int, int);
    extern void fn_801DEB10(void);
    extern void fn_800121A4(void);
    extern void fn_801331C4(int, int *, float *);
    extern int lbl_804874A8[];
    extern int lbl_803394FC;
    extern int lbl_8055E9F4;
    extern float lbl_80562BF4;
    // Fix note: handles eligible event types, samples the selected object, and advances the four-entry ring index.
    float value;
    int *object;
    if (lbl_8055E9E8 != 0) {
        if (fn_801769F8() != 0) {
            if (arg0 == 0x58 || (arg0 < 0x58 && arg0 == 0xD)) {
                if (lbl_8055E9E8 == 8 && lbl_8055E9E0 < *(int *)((char *)&lbl_804873B8 + 4))
                    fn_801DE9F0(8, 0);
                else
                    fn_801DEB10();
                object = (int *)lbl_804874A8[lbl_8055E9F4];
                if (object != 0 && *(unsigned char *)((char *)object + 0x19) == 0) {
                    value = lbl_80562BF4;
                    fn_801331C4(4, &lbl_803394FC, &value);
                    object = (int *)lbl_804874A8[lbl_8055E9F4];
                    if (value != *(float *)((char *)object + 8)) {
                        *((unsigned char *)object + 0x4D) = 1;
                        *(float *)((char *)object + 8) = value;
                    }
                    object = (int *)lbl_804874A8[lbl_8055E9F4];
                    *((unsigned char *)object + 0x49) = 1;
                    *((unsigned char *)object + 0x4B) = 0;
                    *((unsigned char *)object + 0x4A) = 0;
                } else fn_800121A4();
                lbl_8055E9F4 = (lbl_8055E9F4 + 1) & 3;
            }
        }
        return 1;
    }
    return 0;
}

#pragma small_data off
void fn_801DF380(int arg0, int arg1, int arg2, int arg3) {
    int *base = (int *)lbl_804873B8;
    int index = *(int *)((char *)&lbl_804873B8 + 4);
    int *entry = (int *)((char *)base + index * 0x1C);
    *(int *)((char *)&lbl_804873B8 + 4) = index + 1;
    entry[6] = arg2;
    entry[4] = arg3;
    entry[2] = arg0;
    entry[1] = arg1;
    *(unsigned char *)entry = 0;
}
#pragma small_data on
extern void *memcpy(void *, const void *, unsigned int);
extern unsigned long long fn_802E2C9C(int);
extern void fn_801331C4(int, int *, float *);
