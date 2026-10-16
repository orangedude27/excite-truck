#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F980;
extern void *lbl_8055CD78;
void fn_802AE64C(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

void* fn_802B05DC(void) {
    return lbl_8055CD78;
}

char fn_802B05E4(void) {
    return lbl_8055F980;
}

extern char lbl_8055F981;
char fn_802B05EC(void) {
    return lbl_8055F981;
}

