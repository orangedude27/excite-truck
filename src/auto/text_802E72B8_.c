// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E3990(void);
extern int fn_802E3734(int *);
extern int fn_802E72C8(void);
extern int fn_802E36D8(void *);
extern void fn_802E3A14(int);
extern void fn_802E3930(int, void *, int);
extern unsigned char lbl_804FC978[];
void fn_802E746C(int arg0, int *arg1, int *arg2) {
    unsigned char *entry = lbl_804FC978 + arg0 * 0x90;
    *arg1 = *(int *)entry;
    *arg2 = *(int *)(entry + 8);
}

int fn_802E748C(int arg0, void *arg1, int arg2, int arg3) {
    int index, handle, offset;
    unsigned char *entry;
    index = fn_802E72C8();
    if (index < 0) return -1;
    entry = lbl_804FC978 + index * 0x90;
    handle = fn_802E36D8(entry + 0x10);
    if (handle == -1) return -1;
    offset = (arg0 - *(int *)entry) << 11;
    fn_802E3A14(offset);
    index = (*(int *)(entry + 8) - offset + 0x1f) & ~0x1f;
    if (index > arg2) index = arg2;
    fn_802E3930(handle, arg1, index);
    return handle;
}

void fn_802E7544(void) { fn_802E3990(); }

void fn_802E7548(int arg0) { fn_802E3734(&arg0); }

