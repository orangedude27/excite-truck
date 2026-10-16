typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
typedef struct CallbackObject { void **vtable; } CallbackObject;
typedef void (*CallbackMethod)(CallbackObject *, s32);
extern void fn_802E317C(const char *, ...);
extern char lbl_8034CF40[];
extern char lbl_8034CF60[];
extern char lbl_804DB810[];
extern char lbl_8055D1A0[];
extern s32 lbl_8055FF20;
extern s32 fn_802E321C(const char *);
extern s32 fn_802E3270(s32);
extern s32 fn_802E32C4();
extern s32 lbl_8055FF18;
extern s32 lbl_8055FF1C;
extern s32 fn_802E333C(void);
extern char lbl_8034CFB4[];
extern s32 fn_802E33D8(s32, const char *, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FF24;
s32 fn_802E98C8(void);
#pragma small_data on
s32 fn_802E321C(const char *arg0) {
    const char *prefix = lbl_8055D1A0;
    return strncmp(prefix, arg0, strlen(prefix)) == 0;
}
#pragma small_data off
s32 fn_802E333C(void) {
    s32 value = fn_802E32C4();
    if (value == 0) goto use_global;
    goto done;
use_global:
    value = lbl_8055FF18;
done:
    return value;
}

void fn_802E339C(void) {
    s32 *p = (s32 *)fn_802E333C();
    ((void (*)(void))(*(s32 **)((char *)*p + 0x24)))();
}

s32 fn_802E33D0(void) { return 0; }

void fn_802E3498(void) {
    memset(lbl_804DB810, 0, 0x280);
    if (lbl_8055FF18 == 0) lbl_8055FF18 = fn_802E3F94();
}

void fn_802E3550(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        char *entry = lbl_804DB810 + i * 0x28;
        if (((unsigned char *)entry)[0x20] != 0) fn_802E317C(lbl_8034CF40, (s32)entry);
    }
}

s32 fn_802E35C0(const char *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < 16; i++) {
        char *entry = lbl_804DB810 + i * 0x28;
        if (((unsigned char *)entry)[0x20] == 0) {
            entry[0x20] = 1;
            strncpy(entry, arg0, 0x20);
            *(s32 *)(entry + 0x24) = arg1;
            return i;
        }
    }
    fn_802E317C(lbl_8034CF40 + 0x58, arg0);
    return -1;
}

s32 fn_802E367C(s32 arg0) {
    s32 obj = fn_802E333C();
    s32 value = ((s32 (*)(s32, s32))(*(s32 *)obj + 0xC))(obj, arg0);
    if (value != 0) return fn_802E35C0((const char *)arg0, value);
    return -1;
}

s32 fn_802E36D8(s32 arg0) {
    s32 obj = fn_802E333C();
    s32 value = ((s32 (*)(s32, s32))(*(s32 *)obj + 0x10))(obj, arg0);
    if (value != 0) return fn_802E35C0((const char *)arg0, value);
    return -1;
}

void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)fn_802E98C8();
}

