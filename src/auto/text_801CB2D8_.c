#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80019BA8(void);
extern int fn_80161C38(void);
extern int fn_801EA994(void);
extern void fn_801CCBA4(void);
extern void fn_801CCAEC(int);
extern void fn_801CCCAC(void);
extern int fn_801CE874(int);
extern void fn_801CCDAC(int, int, int);
extern void fn_801CD4CC(int, int);
extern signed char lbl_8055E880;
extern void fn_801CB3F8(void);
extern void fn_801CC470(void);
extern void fn_801CC918(void);
void fn_801CB360(int arg0) {
    if (fn_80019BA8() == 0 && fn_80161C38() == 0) {
        fn_801CCAEC(arg0);
    }
}

void fn_801CB3F8(void) {
    int count, i;
    if (fn_80019BA8() || fn_80161C38()) return;
    count = fn_801EA994();
    for (i = 0; i < count; i++) fn_801CCAEC(i);
}

void fn_801CB464(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBA4();
}

extern void fn_801CCBB4(void);
void fn_801CB4A0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBB4();
}

extern void fn_801CCBC4(void);
void fn_801CB4DC(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBC4();
}

void fn_801CB518(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    lbl_8055E880 = 0;
    fn_801CCCAC();
}

void fn_801CB55C(int arg0, int arg1) {
    if (fn_80019BA8() || fn_80161C38()) return;
    if (fn_801CE874(arg0)) {
        fn_801CCDAC(0x22205, arg0, arg1);
        fn_801CD4CC(arg0, arg1);
    }
}

extern void fn_801CC918(void);
extern void fn_801CC470(void);
extern void fn_801CD5B4(int, int, int);
void fn_801CB5DC(int arg0, int arg1, int arg2) {
    if (fn_80019BA8() == 0 && fn_80161C38() == 0) {
        fn_801CD5B4(arg0, arg1, arg2);
    }
}

extern void fn_801CDDCC(void);
void fn_801CB808(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CDDCC();
}

extern void fn_801CE6F8(void);
void fn_801CB844(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CE6F8();
}

extern void fn_801CE7A0(void);
void fn_801CB8C0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CE7A0();
}

void fn_801CB8FC(void) {
    fn_801CE8CC();
}

void fn_801CBD04(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

void fn_801CE698(void) {

}

void fn_801CE69C(void) {

}

void fn_801CE6A0(void) {

}

void fn_801CE6CC(void) {

}

void fn_801CEA28(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

void fn_801CEB94(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

