extern "C" {
extern void* lbl_8055EC98;
extern const char lbl_8033B8C8[];
void fn_80128668(void*);
void fn_801FF5D4(void*, void*, float);
void fn_801FCA54(void*, int, int);
void fn_801FF7D4(void*, void*);
void fn_802E317C(const char*, ...);
void fn_801FCF18(void*, int, int);
void fn_801FF484(void*, void*);
float fn_801E7E24(void);
extern float lbl_80558DC4;
void fn_801FF6FC(void*);
void fn_801FF3AC(void*, float);
float fabs(float);
}
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_801FEFBC(void) {

}

extern "C" void fn_801FEFC0(void) {

}

extern "C" void fn_801FF114(void) {

}

extern "C" void fn_801FF118(void) {

}

extern "C" void fn_801FF168(void) {

}

extern "C" void fn_801FF16C(void* arg0) {
    float value = fn_801E7E24();
    if (fabs(value) > lbl_80558DC4) fn_801FF3AC((char*)arg0 + 0xE08, value);
}

extern "C" int fn_801FF1BC(void) { return 3; }

extern "C" void fn_801FF1C4(void* arg0, int arg1, int arg2) {
    char* p = (char*)arg0;
    if (*(int*)(p + 0xE04) >= 0x20) fn_802E317C(lbl_8033B8C8);
    fn_801FCF18(p + *(int*)(p + 0xE04) * 0x70 + 4, arg1, arg2);
    fn_801FF484(p + 0xE08, p + *(int*)(p + 0xE04) * 0x70 + 4);
    ++*(int*)(p + 0xE04);
}

extern "C" void fn_801FF260(void* arg0) {
    float value = fn_801E7E24();
    if (fabs(value) > lbl_80558DC4) fn_801FF6FC((char*)arg0 + 0x1008);
}

extern "C" void fn_801FF2B8(void* arg0, int arg1, int arg2) {
 char* p = (char*)arg0;
 if (*(int*)(p + 0x1004) >= 0x40) fn_802E317C(&lbl_8033B8C8[0]);
 fn_801FCA54(p + (*(int*)(p + 0x1004) << 6) + 4, arg1, arg2);
 fn_801FF7D4(p + 0x1008, p + (*(int*)(p + 0x1004) << 6) + 4);
 ++*(int*)(p + 0x1004);
}

extern "C" void fn_801FF354(void* arg0) {
 lbl_8055EC98 = arg0;
 *(int*)((char*)arg0 + 0x2C0) = 0;
}

extern "C" void* fn_801FF364(void* arg0, int arg1) {
 if (arg0 != 0) { lbl_8055EC98 = 0; if (arg1 > 0) fn_80128668(arg0); }
 return arg0;
}

extern "C" void fn_801FF3AC(void* arg0, float arg1) {
 char* entry = (char*)arg0;
 int i = 0;
 while (i < *(int*)((char*)arg0 + 0x2C0)) {
  fn_801FF5D4(arg0, entry, arg1);
  entry += 0x58;
  ++i;
 }
}

extern "C" void fn_801FF644(void*, void*);
extern "C" void fn_801FF420(void* arg0) {
    int i = 0;
    char* entry = (char*)arg0;
    while (i < *(int*)((char*)arg0 + 0x2C0)) {
        fn_801FF644(arg0, entry);
        entry += 0x58;
        ++i;
    }
}

extern "C" void fn_801FEFC4(void) {

}

extern "C" void fn_801FF0D4(void* arg0) {
    *(int*)arg0 = 0;
    *((int*)arg0 + 1) = 0;
}

extern "C" void fn_801FF108(void* arg0) {
    fn_801FF420((char*)arg0 + 0xE08);
}

extern "C" void fn_801FF110(void) {

}

