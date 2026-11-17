// strm — streaming ("StrmEnd: used %d of %d entries").
// Recovered TU window 0x802E72B8..0x802E7570 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E7570 (+ .ctors slot 0x802ED60C) remains in
// auto/text_802E7570_.c pending a promotion pass.
  typedef struct {
      int startSector;
      int endSector;
      int size;
      char name[0x80];
  } StreamEntry;
  extern void fn_802E3990(void);
extern int fn_802E3734(int *);
extern int fn_802E72C8(int);
extern int fn_802E36D8(void *);
extern void fn_802E3A14(int);
extern void fn_802E3930(int, void *, int);
extern unsigned char lbl_804FC978[];
extern int lbl_8055FFD8;
extern int lbl_8055FFDC;
extern signed char lbl_8055FFE0;
extern const char lbl_8034D7D8[];
extern int fn_802E30C8(const char *, ...);
#pragma dont_inline on
/* Round a byte count up to a whole number of 2048-byte sectors (ceil(size/2048)). */
int fn_802E72B8(int size) {
    return (size + 0x7ff) / 2048;
}

#pragma push
#pragma scheduling invalid_target
int fn_802E72C8(int arg0) {
    unsigned char *entry = lbl_804FC978;
    int index = 0;
    int remaining;
    for (remaining = lbl_8055FFD8; remaining > 0; remaining--) {
        if (arg0 >= *(int *)entry && arg0 < *(int *)(entry + 4))
            return index;
        entry += 0x90;
        index++;
    }
    return -1;
}
#pragma pop

void fn_802E7318(void) {
    /* Begin streaming: reset the sector cursor and entry count, and set the active flag. */
    lbl_8055FFDC = 0;
    lbl_8055FFD8 = 0;
    lbl_8055FFE0 = 1;
}

#pragma scheduling invalid_target
void fn_802E7330(void) {
    /* Stop stream loading, clear the active flag, and log the entries used out of 0x100 plus the sectors used. */
    lbl_8055FFE0 = 0;
    fn_802E30C8(lbl_8034D7D8, lbl_8055FFD8, 0x100, lbl_8055FFDC);
}
#pragma scheduling on
extern int stricmp(const char *, const char *);
extern int fn_802E37C4(void);
extern int fn_802E72B8(int);
int fn_802E7354(const char *name) {
    int index;
    unsigned char *entry;
    int fileIndex;
    int size;
    int blocks;
    int remaining;
    char *dst;
    signed char c;
    entry = lbl_804FC978;
    index = 0;
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
        goto fail;
    index = lbl_8055FFD8;
    entry = lbl_804FC978 + index * 0x90;
    lbl_8055FFD8 = index + 1;
    dst = (char *)(entry + 0x10);
    remaining = 0x80;
    goto copy_start;
dec:
    if (--remaining <= 0) {
        dst[-1] = 0;
        goto done;
    }
copy_start:
    c = *name++;
    *dst++ = c;
    if (c != 0)
        goto dec;
done:
    size = fn_802E37C4();
    blocks = fn_802E72B8(size);
    *(int *)entry = lbl_8055FFDC;
    lbl_8055FFDC += blocks;
    *(int *)(entry + 4) = lbl_8055FFDC;
    *(int *)(entry + 8) = size;
    fn_802E3734(&fileIndex);
    return index;
fail:
    return -1;
}

void fn_802E746C(int index, int *outStartSector, int *outSize) {
    /* Report the start sector (in 2048-byte units) and byte size of stream entry `index`. */
    StreamEntry *entry = (StreamEntry *)(lbl_804FC978 + index * 0x90);
    *outStartSector = entry->startSector;
    *outSize = entry->size;
}

#pragma push
#pragma use_lmw_stmw off
/* Open the stream entry containing arg0, seek to its byte offset, and read up to arg2 bytes into arg1. */
int fn_802E748C(int arg0, void *arg1, int arg2, int arg3) {
    unsigned char *temp_r31;
    int var_r5;
    int temp_r3_2;
    int temp_r3;
    int temp_r29;
    temp_r3_2 = fn_802E72C8(arg0);
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

/* Close the file/stream handle by value; fn_802E3734 takes the handle by address and invalidates it. */
void fn_802E7548(int handle) { fn_802E3734(&handle); }

