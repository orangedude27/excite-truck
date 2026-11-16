// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

/* Record fn_8000D838 chains onto the global static-destructor list. */
typedef struct {
    unsigned char tag;  /* 0x31, written by fn_8000D838 */
    void *next;         /* 0x4 previous head of the list (lbl_8055D450) */
} StaticDtorRecord;

extern StaticDtorRecord lbl_8055E5F8; /* this module's record, in .sbss */
extern int lbl_8055E600;              /* state word right behind it */
void fn_8000D838(void *);
void fn_801AE570(void);

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED23C = fn_801AE570;

void fn_801AE570(void) {
#define RegisterStaticDtor fn_8000D838
#define s_dtorRecord       lbl_8055E5F8
#define s_stateWord        lbl_8055E600
    /* C++ static initializer (its .ctors entry is at 0x802ED23C) of the module
     * whose code starts at fn_801AE600: chain this module's static-destructor
     * record onto the global list, then set the module's state word to the
     * 0xFFFF0000 "nothing set yet" sentinel. */
    RegisterStaticDtor(&s_dtorRecord);
    s_stateWord = 0xFFFF0000;
#undef s_stateWord
#undef s_dtorRecord
#undef RegisterStaticDtor
}
