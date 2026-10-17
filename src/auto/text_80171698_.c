// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];
void fn_8017188C(void *arg0) {
    int i;
    int offset;
    unsigned char *base;
    i = 0;
    offset = 0;
    base = *(unsigned char **)((char *)arg0 + 8);
    while (i < *(int *)((char *)arg0 + 12)) {
        unsigned char *p = base + offset;
        if (p[0x25] && !p[0x24] && *(int *)*(void **)(p + 0x18) > 1)
            fn_80141558((char *)arg0 + 0xa14, 2, fn_8000FDF0 + 0x110);
        offset += 0x28;
        i++;
    }
}

void fn_80171930(void) {
}

void fn_80171CE0(void) {

}

