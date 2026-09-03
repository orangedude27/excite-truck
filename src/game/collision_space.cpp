#include <types.h>

/* Review carve for REXE01 __dt__14CollisionSpaceFv@0x8001E014
 * (game auto_03_8001DA5C_text).  Game C++ object destructor; not
 * configured/review only.
 */

extern void fn_802CAC54(void* obj);
extern void fn_80128668(void* obj);

#pragma push
#pragma small_data off
extern void* lbl_802FDC98; // vtable
#pragma pop

struct CollisionSpace {
    void* vtable;   // at 0x0
    void* field_4;  // at 0x4
    u8 pad8[0x60 - 0x8];
};

extern "C" void* __dt__14CollisionSpaceFv(CollisionSpace* this_,
                                          s32 deleteFlag) {
    if (this_) {
        this_->vtable = (void*)&lbl_802FDC98;
        fn_802CAC54(this_->field_4);

        if (deleteFlag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}