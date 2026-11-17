// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma push
#pragma small_data off
typedef struct { void *p; int a; int b; } GlobalObj;
extern unsigned char lbl_8055F8C8;
extern int lbl_8055F8D0;
extern GlobalObj lbl_804BD6C4;
extern unsigned char lbl_804BD6B8[];
extern void fn_8000D838(void *);
extern void fn_802A8F94(void);
extern void __register_global_object(void *, void (*)(void), void *, int);

#pragma scheduling invalid_target
void fn_802A8F34(void) {
    /* Initialize a global object (storage pointer, capacity 10, count 0) and register its destructor. */
    fn_8000D838(&lbl_8055F8C8);
    lbl_8055F8D0 = 0xFFFF0000;
    *(void **)&lbl_804BD6C4 = (char *)&lbl_804BD6C4 + 12;
    *(int *)((char *)&lbl_804BD6C4 + 8) = 10;
    *(int *)((char *)&lbl_804BD6C4 + 4) = 0;
    ((void (*)(void *, void *, void *))__register_global_object)(&lbl_804BD6C4, fn_802A8F94, (char *)&lbl_804BD6B8);
}
#pragma scheduling on
