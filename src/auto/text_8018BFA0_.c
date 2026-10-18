// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8018C50C(void) {

}

void fn_8018C510(void) {

}

extern int lbl_80332840;
extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern float PSQUATMultiply(void *, void *);
int fn_8018C514(void *arg0, void *arg1) {
    float min = lbl_80561F70;
    int best = 0;
    int i = 1;
    int offset = 0x34;
    while (i < *(int *)((char *)arg0 + 0x26C)) {
        float value = PSQUATMultiply(arg1, (char *)arg0 + offset + 0x20);
        if (value < min) {
            min = value;
            best = i;
        }
        offset += 0x34;
        i++;
    }
    return best;
}

void fn_8018E330(void *arg0) {
    void *manager;
    void *object;
    manager = (void *)fn_801B83A0();
    ((void (*)(void *))(*(void **)((char *)*(void **)manager + 0xA4)))(arg0);
    fn_80161A38(0, *(int *)((char *)arg0 + 0x1EC), 0);
    fn_801DFF1C(*(int *)((char *)arg0 + 0x1EC));
    *(float *)((char *)arg0 + 0x258C) = lbl_80561F74;
    object = *(void **)((char *)arg0 + 0x270);
    *(float *)((char *)arg0 + 0x2690) = lbl_80561F8C;
    *(float *)((char *)arg0 + 0x25BC) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x26A0) = lbl_8055E3C8;
    object = ((void *(*)(void *))(*(void **)((char *)*(void **)object + 0x10)))(object);
    *(int *)((char *)arg0 + 0x26A4) = *(int *)((char *)object + 4);
    *(float *)((char *)arg0 + 0x2588) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x25A0) = lbl_80561F74;
    *(char *)((char *)arg0 + 0x259D) = 0;
    *(char *)((char *)arg0 + 0x259C) = 0;
    *(int *)((char *)arg0 + 0x2638) = 0;
    *(int *)((char *)arg0 + 0x2644) = 0;
    *(float *)((char *)arg0 + 0x2630) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x262C) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x2628) = lbl_80561F74;
}

void fn_8018F6F8(void *arg0) {
    int i;
    char *type = (char *)&lbl_80332840;
    char *entry = (char *)arg0 + 0x152C;
    for (i = 0x11; i != 0; i--) {
        if (*(int *)entry != 0 && *(int *)(entry + 0x7C) == 0 &&
            (unsigned int)(*(int *)type - 0xE) <= 2U) {
            *(int *)(entry + 0x7C) = 4;
            *(char *)(entry + 0x78) = 0;
            *(float *)(entry + 0xC) = lbl_80561F74;
            *(float *)(entry + 0x10) = *(float *)(entry + 0x14) / lbl_80562050;
        }
        type += 0x40;
        entry += 0x80;
    }
}

extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern int lbl_80332840;
int fn_80161A38(int, int, int);
int fn_801DFF1C(int);
float PSQUATMultiply(void *, void *);
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
extern void PSVECCrossProduct(float *, float *, int *);
extern float PSVECDotProduct(int *, float *);
extern void *__AXFXGetLfoSinTable_801769CC(int);
extern void fn_80015A20(int *, float *, float, float, float, float);
extern void fn_80015B20(float *, int *, float *);
extern int fn_80129D18(int, int, float, float, float, float, float, float);
extern void fn_8014452C(int *, float, float, float);
extern void fn_8017B6D4(void *, float *, float *, float, float);
extern void fn_8017B778(void *, float *, float *);
extern void fn_8018BFA0(void *, float *, int *, int, float, float);
extern float lbl_80561F88, lbl_80561F90, lbl_80561F94, lbl_80561F98, lbl_80561F9C, lbl_80561FA0, lbl_80561FA4, lbl_80561FA8, lbl_80561FAC, lbl_80561FB0, lbl_80561FB4, lbl_80561FB8, lbl_80561FBC, lbl_80561FC0, lbl_80561FC4;
