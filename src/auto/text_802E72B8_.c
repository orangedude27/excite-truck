// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E3990(void);
extern int fn_802E3734(int *);
extern int fn_802E72C8(void);
extern int fn_802E36D8(void *);
extern void fn_802E3A14(int);
extern void fn_802E3930(int, void *, int);
extern unsigned char lbl_804FC978[];
extern int lbl_8055FFD8;
extern int lbl_8055FFDC;
extern signed char lbl_8055FFE0;
extern int lbl_8034D7D8;
extern int fn_802E30C8(int *, int, int, int);
#pragma dont_inline fn_802E72B8
int fn_802E72B8(int arg0) {
    return (arg0 + 0x7ff) / 2048;
}

void fn_802E7318(void) {
    lbl_8055FFDC = 0;
    lbl_8055FFD8 = 0;
    lbl_8055FFE0 = 1;
}

void fn_802E7330(void) {
    int *p = &lbl_8034D7D8;
    int a = lbl_8055FFD8;
    int b = lbl_8055FFDC;
    lbl_8055FFE0 = 0;
    fn_802E30C8(p, a, 0x100, b);
}

extern int stricmp(const char *, const char *);
extern int fn_802E37C4(void);
extern int fn_802E72B8(int);
int fn_802E7354(const char *name) {
    int index = 0;
    int fileIndex;
    int size;
    int blocks;
    int remaining;
    unsigned char *entry;
    char *dst;
    const char *src;
    signed char c;

    entry = lbl_804FC978;
    goto search_test;
search_body:
    if (stricmp(name, (char *)(entry + 0x10)) == 0)
        return index;
    entry += 0x90;
    index++;
search_test:
    if (index < lbl_8055FFD8)
        goto search_body;

    fileIndex = fn_802E36D8((void *)name);
    if (fileIndex == -1)
        return fileIndex;
    index = lbl_8055FFD8;
    entry = lbl_804FC978;
    entry += index * 0x90;
    lbl_8055FFD8 = index + 1;
    dst = (char *)(entry + 0x10);
    src = name;
    remaining = 0x80;
    goto copy_body;
copy_limit:
    remaining--;
    if (remaining > 0)
        goto copy_body;
    *--dst = 0;
    goto copy_end;
copy_body:
    c = *src;
    src++;
    *dst = c;
    dst++;
    if (c != 0)
        goto copy_limit;
copy_end:
    size = fn_802E37C4();
    blocks = fn_802E72B8(size);
    *(int *)(entry + 0) = lbl_8055FFDC;
    lbl_8055FFDC += blocks;
    *(int *)(entry + 4) = lbl_8055FFDC;
    *(int *)(entry + 8) = size;
    fn_802E3734(&fileIndex);
    return index;
}

void fn_802E746C(int arg0, int *arg1, int *arg2) {
    unsigned char *entry = lbl_804FC978 + arg0 * 0x90;
    *arg1 = *(int *)entry;
    *arg2 = *(int *)(entry + 8);
}

#pragma push
#pragma use_lmw_stmw off
int fn_802E748C(int arg0, void *arg1, int arg2, int arg3) {
    unsigned char *temp_r31;
    int var_r5;
    int temp_r3_2;
    int temp_r3;
    int temp_r29;
    temp_r3_2 = fn_802E72C8();
    if (temp_r3_2 < 0) return -1;
    temp_r31 = lbl_804FC978 + temp_r3_2 * 0x90;
    temp_r3 = fn_802E36D8(temp_r31 + 0x10);
    if (temp_r3 == -1) return -1;
    temp_r29 = (arg0 - *(int *)temp_r31) << 11;
    ((void (*)(int, int))fn_802E3A14)(temp_r3, temp_r29);
    var_r5 = (*(int *)(temp_r31 + 8) - temp_r29 + 0x1f) & ~0x1f;
    if (var_r5 > arg2) var_r5 = arg2;
    fn_802E3930(temp_r3, arg1, var_r5);
    return temp_r3;
}
#pragma pop
void fn_802E7544(void) { fn_802E3990(); }

void fn_802E7548(int arg0) { fn_802E3734(&arg0); }

