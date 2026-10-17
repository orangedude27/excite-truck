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
    s32 temp_r3;
    temp_r3 = fn_802E32C4();
    if (temp_r3 != 0) {
        return temp_r3;
    }
    return (s32)&lbl_8055FF18;
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
          s32 obj = (s32)fn_802E333C();
      s32 value = ((s32 (*)(s32, s32))(*(s32 *)obj + 0xC))(obj, arg0);
    if (value != 0) return fn_802E35C0((const char *)arg0, value);
    return -1;
}

s32 fn_802E36D8(s32 arg0) {
          s32 obj = (s32)fn_802E333C();
      s32 value = ((s32 (*)(s32, s32))(*(s32 *)obj + 0x10))(obj, arg0);
    if (value != 0) return fn_802E35C0((const char *)arg0, value);
    return -1;
}

void fn_802E3734(s32 *arg0) {
    s32 obj = fn_802E33D8(*arg0, lbl_8034CFB4, 0xE4);
    s32 entry = *(s32 *)(obj + 0x24);
    ((void (*)(s32))(*(s32 *)entry + 0x2C))(entry);
    ((void (*)(s32, s32))(*(s32 *)entry + 0x1C))(entry, entry);
    *(s32 *)(obj + 0x24) = 0;
    *((unsigned char *)obj + 0x20) = 0;
    *arg0 = -1;
}

void fn_802E37C4(s32 arg0) {
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x125);
    ((void (*)(s32))(*(s32 *)*(s32 *)(obj + 0x24) + 0x18))(*(s32 *)(obj + 0x24));
}

void fn_802E3898(s32 arg0, const char *arg1, s32 *arg2) {
    s32 total;
    s32 result;
    s32 obj;
    s32 entry;
    s32 count;
    total = *arg2;
    obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x142);
    result = 0;
    if (total > 0) {
        do {
            entry = *(s32 *)(obj + 0x24);
            count = ((s32 (*)(s32, const char *, s32))(*(s32 *)entry + 8))(entry, arg1, total - result);
            if (count < 0) { result = count; break; }
            if (count <= 0) break;
            result += count;
            arg1 += count;
        } while (total > 0);
    }
    *arg2 = result;
}

void fn_802E3930(s32 arg0, s32 arg1, s32 arg2) {
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x15e);
    s32 entry = *(s32 *)(obj + 0x24);
    ((void (*)(s32, s32, s32))(*(s32 **)entry)[4])(entry, arg1, arg2);
}

void fn_802E3990(s32 arg0) {
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x16c);
    s32 entry = *(s32 *)(obj + 0x24);
    ((void (*)(s32))(*(s32 **)entry)[5])(entry);
}

s32 fn_802E39D0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8 = arg2;
    fn_802E3898(arg0, (const char *)arg1, &sp8);
    return sp8 == arg2;
}

void fn_802E3A14(s32 arg0, s32 arg1) {
 s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x1ab);
 s32 entry = *(s32 *)(obj + 0x24);
 ((void (*)(s32,s32))(*(s32 **)entry)[8])(entry,arg1);
}

s32 fn_802E3A64(s32 arg0,s32 arg1,s32 arg2) {
 s32 obj=fn_802E33D8(arg0,lbl_8034CFB4,0x1c3);
 s32 entry=*(s32 *)(obj+0x24);
 s32 result=((s32 (*)(s32,s32,s32))(*(s32 **)entry)[3])(entry,arg1,arg2);
 return arg2==result;
}

void fn_802E3D00(void) {
}

s32 fn_802E3D04(s32 arg0) {
    s32 (*method)(s32);
    s32 *obj;
    s32 value;
    obj = (s32 *)fn_802E336C();
    if (obj == 0) return -1;
    method = (s32 (*)(s32))(*(s32 **)obj)[4];
    value = method(arg0);
    if (value == 0) return -1;
    return fn_802E35C0((const char *)arg0, value);
}

s32 fn_802E3D68(s32 arg0) {
    s32 (*method)(s32);
    s32 *obj;
    s32 value;
    obj = (s32 *)fn_802E336C();
    if (obj == 0) return -1;
    method = (s32 (*)(s32))(*(s32 **)obj)[3];
    value = method(arg0);
    if (value == 0) return -1;
    return fn_802E35C0((const char *)arg0, value);
}

void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)fn_802E98C8();
}

