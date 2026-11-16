// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055DF50;
extern int lbl_8055DF54;
extern int lbl_8055DF58;
extern int lbl_8055DF5C;
extern int lbl_8055DF60;
extern int lbl_8041DF58[][5];
extern int fn_80127AA0(void);
extern int fn_80127464(int);
extern int fn_80127AB8(void *);
void fn_80127A24(void) {
    typedef int (*FlushFn)(void);
    // Flush pending alarm work through fn_80127464, then clear the 16-entry record ring (lbl_8041DF58)
    // by resetting its read (lbl_8055DF50) and write (lbl_8055DF54) indices.
    ((FlushFn)fn_80127464)();
    lbl_8055DF54 = 0;
    lbl_8055DF50 = 0;
}

void fn_80127A50(int record) {
    /* Forward to the alarm helper, then pop the next 5-word record from the
       16-entry ring (lbl_8041DF58) into the caller's buffer. */
    fn_80127464(record);
    fn_80127AB8((void *)record);
}

void fn_80127A84(int *outX, int *outY, int *outButtons) {
    /* Copy the current pointer X/Y position and button bitmask into the caller's outputs. */
    *outX = lbl_8055DF58;
    *outY = lbl_8055DF5C;
    *outButtons = lbl_8055DF60;
}

int fn_80127AA0(void) {
    return lbl_8055DF50 == lbl_8055DF54;
}

#pragma push
#pragma dont_inline on
int fn_80127AB8(void *arg0) {
    int index;
    volatile int (*table)[5];
    int (*row)[5];
    int *dst = (int *)arg0;
    if (fn_80127AA0() != 0) goto fail;
    index = lbl_8055DF50;
    table = (volatile int (*)[5])lbl_8041DF58;
    row = (int (*)[5])table + index;
    dst[0] = table[index][0];
    dst[1] = row[0][1];
    dst[2] = row[0][2];
    dst[3] = row[0][3];
    dst[4] = row[0][4];
    lbl_8055DF50 = (lbl_8055DF50 + 1) % 16;
    return 1;
fail:
    return 0;
}
#pragma pop
