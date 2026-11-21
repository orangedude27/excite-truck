// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef long s32;
extern void** fn_801284F8(s32, void*);
extern char lbl_8032C4F0[];
extern char lbl_8032C500[];
extern s32 fn_80128668(void);

/* Allocation tag and vtable of the "csubtasktmgr" (challenge sub-task manager). */
#define csubtasktmgr_tag lbl_8032C4F0
#define csubtasktmgr_vtable lbl_8032C500

#pragma scheduling invalid_target
/* Allocate a four-byte challenge sub-task manager and install its vtable when the
   construction selector is zero. */
void fn_8013C9F4(s32 arg0) {
    void **object;

    if (arg0 == 0) {
        object = fn_801284F8(4, (void *)csubtasktmgr_tag);
        if (object != (void **)0) {
            *object = (void *)csubtasktmgr_vtable;
        }
    }
}
#pragma scheduling on
/* Empty hook: the close-score scan fn_8027AA50 calls it with the index of an entry
 * and of the rival closest to it in score, once that best score gap still exceeds
 * the threshold at lbl_8055F638; the shipped game does nothing here. */
void fn_8013CA3C(s32 closestIndex, s32 entryIndex) {

}

/* CodeWarrior deleting-destructor helper: free object via Mem_freeObject (fn_80128668)
   when deleteFlag > 0, then return object. */
long fn_8013CA40(long object, long deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Default/stub method: reports zero (false / no result) for a vtable-dispatched query. */
long fn_8013CA80(void) {
    return 0;
}

/* Default/stub method: reports one (true / success) for a vtable-dispatched query. */
long fn_8013CA88(void) {
    return 1;
}

/* Default/stub method: reports zero (false / no result) for a vtable-dispatched query. */
long fn_8013CA90(void) {
    return 0;
}

/* Default/stub method: reports zero (false / no result) for a vtable-dispatched query. */
long fn_8013CA98(void) {
    return 0;
}

/* Base-class default for slot +0x18 of the sub-task manager interface, shared by
 * the "csubtasktmgr" vtable (lbl_8032C500) and the "chalsubtaskmgr" vtable
 * (lbl_8032F760): a notification neither manager shipped in this game acts on. */
void fn_8013CAA0(void) {

}

/* Base-class default for slot +0x20 of the sub-task manager interface, shared by
 * the "csubtasktmgr" vtable (lbl_8032C500) and the "chalsubtaskmgr" vtable
 * (lbl_8032F760).  fn_801B24B8 calls it on the current manager (lbl_8055E68C)
 * once every queued timed entry has been applied -- a "wave finished" notice the
 * two managers shipped in this game both ignore. */
void fn_8013CAA4(void) {

}

/* Base-class default for slot +0x24 of the sub-task manager interface, shared by
 * the "csubtasktmgr" vtable (lbl_8032C500) and the "chalsubtaskmgr" vtable
 * (lbl_8032F760).  fn_801B2910 calls it on the current manager (lbl_8055E68C)
 * after it has cleared the timed-entry state and rebuilt the entry order -- a
 * "round reset" notice both managers shipped in this game ignore. */
void fn_8013CAA8(void) {

}

/* Default/stub method: reports zero (false / no result) for a vtable-dispatched query. */
long fn_8013CAAC(void) {
    return 0;
}

