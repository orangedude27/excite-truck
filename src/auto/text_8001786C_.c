typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* fn_80016544(s32);
extern s32 fn_800168B0(s32, s32);
extern s32 fn_800167F4(void);
extern void* fn_800167B8(s32);
extern void* fn_80016510(s32);
extern s32 fn_8001786C(s32);
extern char lbl_8055D564;
extern void* lbl_8055D560;
s32 atoi(void);
void fn_800178BC(void* arg0, s32 arg1, s32 arg2) {
    s32 index1;
    s32 index2;
    index1 = *(s32*)((char*)arg0);
    *(s32*)((char*)arg0 + index1 * 4 + 4) = arg1;
    index2 = *(s32*)((char*)arg0 + 0x24);
    *(s32*)((char*)arg0) = index1 + 1;
    *(s32*)((char*)arg0 + index2 * 4 + 0x28) = arg2;
    *(s32*)((char*)arg0 + 0x24) = index2 + 1;
}

int fn_800178F0(void) { return 0; }

void fn_800178F8(s32 arg0, s32 arg1) {
    void* temp = fn_80016544(arg1);
    fn_800168B0(arg0, *(s32*)((char*)temp + (*(s32*)((char*)temp + 0x94) * 4) + 0x64));
}

extern s32 fn_800179E4(void *, s32, s32);
void fn_80017A20(void *arg0, s32 *arg1) {
    fn_800179E4(arg0, (s32)(arg1 + 1), arg1[0]);
}

void fn_80017AC8(void* arg0) {
    s32 i;
    s32 index;
    s32* items;
    extern s32 fn_80129D18(s32);
    for (i = 0; i < *(s32*)((char*)arg0 + 4); i++) {
        items = *(s32**)arg0;
        index = fn_80129D18(1);
        /* swap */
        {
            s32 temp = items[i];
            items[i] = items[index];
            items[index] = temp;
        }
    }
}

s32 fn_80017F40(void) {
    return fn_800167F4() == 1;
}

void fn_800182A0(void* arg0, void* arg1) {
    s32 i;
    s32 index;
    s32 value;

    for (i = 0; i < *(s32*)((char*)arg1); i++) {
        index = *(s32*)((char*)arg0);
        value = *(s32*)((char*)arg1 + i * 4 + 4);
        *(s32*)((char*)arg0 + index * 4 + 4) = value;
        *(s32*)((char*)arg0) = index + 1;
    }
    for (i = 0; i < *(s32*)((char*)arg1 + 0x24); i++) {
        index = *(s32*)((char*)arg0 + 0x24);
        value = *(s32*)((char*)arg1 + i * 4 + 0x28);
        *(s32*)((char*)arg0 + index * 4 + 0x28) = value;
        *(s32*)((char*)arg0 + 0x24) = index + 1;
    }
}

void fn_80018318(void* arg0, s32 arg1) {
    s32 pad[17];
    s32 sp50;
    s32 sp8;
    s32 temp;
    extern void fn_8013C804(void);
    extern void fn_80017944(s32*);
    extern s32 fn_80017F6C(s32);
    extern void fn_80017DD4(s32*, s32, s32*);
    extern void fn_80018030(void*, s32);
    extern void fn_800180FC(void*, s32);
    extern void fn_8013C8B8(void);
    fn_8013C804();
    fn_80017944(&sp50);
    temp = fn_80017F6C(arg1) - sp50;
    fn_80017DD4(&sp8, temp & ~(temp >> 31), &sp50);
    memset(arg0, 0, 0x48);
    fn_800182A0(arg0, &sp8);
    fn_800182A0(arg0, &sp50);
    fn_80018030(arg0, arg1);
    fn_800180FC(arg0, arg1);
    fn_8013C8B8();
}

void fn_80018794(void) {
    lbl_8055D560 = (void*)atoi();
}

void fn_800187F8(void) {
    lbl_8055D564 = 1;
}
