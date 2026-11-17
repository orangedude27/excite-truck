// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef long s32;
typedef unsigned long u32;
extern void** fn_801284F8(s32, void*);
extern char lbl_8032C4F0[];
extern char lbl_8032C500[];
extern long fn_80128668(void);

#pragma scheduling invalid_target
/* Allocate a 4-byte subtask-manager object and install its vtable pointer when arg0 is 0. */
void fn_8013C9F4(long arg0) {
    void **object;

    if (arg0 == 0) {
        object = fn_801284F8(4, (void *)lbl_8032C4F0);
        if (object != (void **)0) {
            *object = (void *)lbl_8032C500;
        }
    }
}
#pragma scheduling on
void fn_8013CA3C(void) {

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

long fn_8013CA90(void) {
    return 0;
}

/* Default/stub method: reports zero (false / no result) for a vtable-dispatched query. */
long fn_8013CA98(void) {
    return 0;
}

void fn_8013CAA0(void) {

}

void fn_8013CAA4(void) {

}

void fn_8013CAA8(void) {

}

long fn_8013CAAC(void) {
    return 0;
}

