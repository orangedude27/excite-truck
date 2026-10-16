// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EE08;
void* fn_8020A76C(void) {
    return lbl_8055EE08;
}

extern void fn_802E59BC(void *);
extern void fn_802E5950(int, int);
extern void fn_802E6138(void);
extern void fn_802E61D8(void *);
void fn_8020AA0C(void *arg0) {
    int value = *(int *)((char *)arg0 + 8);
    if (value != 0) {
        fn_802E61D8((void *)value);
        if (*(int *)((char *)arg0 + 0xC) != 0) {
            fn_802E61D8(*(void **)((char *)arg0 + 0xC));
        }
        if (*(int *)((char *)arg0 + 0xC) != 0) {
            fn_802E6138();
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        if (*(int *)((char *)arg0 + 8) != 0) {
            fn_802E6138();
            *(int *)((char *)arg0 + 8) = 0;
        }
    }
    *(int *)((char *)arg0 + 4) = 3;
    *((unsigned char *)arg0 + 0x3E) = 0;
}

extern void fn_802E59BC(void *); void fn_8020AC18(void *arg0, int arg1) { fn_802E59BC((void *)arg1); }

extern void fn_802E5A54(void);
void fn_8020AC20(void) {
    lbl_8055EE08 = 0;
    fn_802E5A54();
}

void fn_8020B2D0(void) {

}

void fn_8020B340(void) {
    fn_802E5824();
}

void fn_8020B344(void) {
    fn_802E5828();
}

void fn_8020BCB0(void) {

}

void fn_8020BCB4(void) {

}

