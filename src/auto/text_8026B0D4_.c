// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>
#include <types.h>
#include <macros.h>
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, int, int, int);
extern unsigned char lbl_8055F4B0[1];
extern char lbl_80499E60[];
extern void fn_8026B118(void);
#pragma scheduling invalid_target
void fn_8026B0D4(void) {
    /* Initializes a fixed-size object pool/storage (4 entries of 0x6C bytes) using callback fn_8026B118. */
#define poolStorage lbl_80499E60
#define poolState lbl_8055F4B0
#define Pool_Init fn_8002F53C
#define Pool_ClearState fn_8000D838
#define Pool_ConstructEntry fn_8026B118

    Pool_ClearState(poolState);
    Pool_Init(poolStorage, Pool_ConstructEntry, 0, 0x6C, 4);

#undef poolStorage
#undef poolState
#undef Pool_Init
#undef Pool_ClearState
#undef Pool_ConstructEntry
}
#pragma scheduling on
#include <types.h>
#include <macros.h>
DECL_SECTION(".ctors") funcptr_t D_802ED488 = fn_8026B0D4;
