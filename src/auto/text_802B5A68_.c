typedef signed long s32;
typedef unsigned long u32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FA31;
extern s32 lbl_8055FA3C;
extern s32 lbl_8055FA40;
extern s32 fn_802B59A4(s32);
extern s32 fn_802B321C(s32, void **, s32, s32);
extern s32 fn_802B3F0C(s32);
void fn_802B5B6C(void) {
    fn_802B59A4(lbl_8055FA3C);
}

void fn_802B5CAC(void) {
    fn_802B5C24(1);
}

void fn_802B5CC4(void) {
    fn_802B5CB4(1);
}

extern s32 fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_802B05DC(void);
extern s32 fn_802B5D2C(const char *, s32);
#pragma small_data on
extern const char lbl_8055CE38[];
extern const char lbl_8055CE40[];
extern const char lbl_8055CE48[];
extern const char lbl_8055CE50[];
#pragma small_data off
extern s32 lbl_8055FA28;
extern float lbl_8055FA08;
extern float lbl_80564C5C;
extern s32 fn_802B32E0(s32);
extern s32 fn_802B4E44(s32);
extern s32 sscanf(const char *, const char *, ...);
s32 fn_802B5DD0(s32 arg0) {
    s32 temp_r31;
    s32 temp_r3;
    s32 result;

    temp_r31 = fn_802B5D2C(lbl_8055CE48, arg0);
    temp_r3 = fn_802B05DC();
    result = 0;
    if ((temp_r31 != -1) && (temp_r31 != temp_r3)) {
        result = 1;
    }
    return result;
}

#pragma push
#pragma small_data off
#pragma pop
extern double lbl_80564C68;
extern float lbl_80564C70;
extern s32 fn_802E2C20(void);
void fn_802B5E24(s32 arg0) {
    lbl_8055FA28 = fn_802B5D2C(lbl_8055CE48, arg0);
    lbl_8055FA08 = lbl_80564C5C;
}
u32 fn_802B5E8C(s32 arg0) {
    s32 result = fn_802B5D2C(lbl_8055CE50, arg0);
    return (u32)((-1 - result) | (result + 1)) >> 31;
}

extern void* lbl_8055FA44;
s32 fn_802B5D94(void);
void fn_802B5EC4(void) {
    lbl_8055FA44 = (void*)fn_802B5D94();
}

extern s32 lbl_8055FA38;
extern s32 fn_80128678(void);
extern s32 fn_80128684(void);
extern void *fn_80156A40(void);
extern s32 fn_802A7BDC(s32);
extern void fn_802BBEE4(void);
extern void fn_802C21C0(void);
void fn_802B5F24(s32 arg0) {
    s32 i;
    s32 result;
    fn_80128684();
    i = 0;
    do {
        result = (*(s32 (**)(s32))(*(s32 *)fn_80156A40() + 3))(0);
        if (result == 0) break;
        fn_802A7BDC(arg0);
        i++;
    } while (i < 10);
    fn_80128678();
}

#pragma push
#pragma small_data off
#pragma pop
void fn_802B618C(void) {
    fn_802B59A4(lbl_8055FA3C);
    fn_80128684();
    fn_80128678();
}

void fn_802B61B8(void) {
    if (lbl_8055FA38 <= 3) {
        if (lbl_8055FA38 < 3) {
            if (lbl_8055FA38 >= 2) fn_802BBEE4();
            return;
        }
        fn_802C21C0();
    }
}

void fn_802B61E0(void) {
    lbl_8055FA08 = (float)fn_802E2C20() / lbl_80564C70;
}

s32 fn_802B6270(void) {
    return lbl_8055FA40 == 7;
}

extern void lbl_8034A898(void);
void fn_802B7884(void *);
void fn_802B7918(void);
void fn_802B7CF0(void) {
    fn_802B7884(lbl_8034A898);
    fn_802B7918();
}

void fn_802B8C98(void) {
    lbl_8055FA31 = 0;
}
