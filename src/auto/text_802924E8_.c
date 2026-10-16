// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
extern unsigned char lbl_804B4168[];
extern void fn_80292EA8(void *);
extern void fn_80292EB4(void *);
void fn_802924E8(void) {
    fn_80292EA8(lbl_804B4168);
}

void fn_80292618(void) {
}

void fn_8029261C(void) {
    fn_80292EB4(lbl_804B4168);
}

void fn_80292628(void) {
    s32 i;
    unsigned char *entry = lbl_804B4168;
    for (i = 0; i < *(s32 *)(lbl_804B4168 + 0x180); i++, entry += 0x18) {
        void *obj = *(void **)(entry + 0x10);
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[3])(obj);
    }
}

typedef unsigned char u8;
typedef signed char s8;
extern int fn_8002B1D8(const char *, const char *, int);
extern int strcmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
extern int lbl_802FA998[];
extern char lbl_80349208[];
void fn_80292EA8(void *arg0) { *(s32 *)((u8 *)arg0 + 0x180) = 0; }

