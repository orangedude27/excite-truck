#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" s32 fn_80128668(void);

namespace ebi {
namespace title {
class TPlaneSub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void update(); // 0x20
};

class TBlackPlane {
public:
    TBlackPlane() {}
    void* m_pad; // 0x0
    TPlaneSub* m_a; // 0x4
    TPlaneSub* m_b; // 0x8
    void updateAfterCamera();
};
} // namespace title
} // namespace ebi

extern "C" u8 fn_802A4A20(void);
extern "C" s32 fn_802A16EC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8028E398(void*);
extern "C" int lbl_80349B28[];
extern "C" void* __dt__14CollisionSpaceFv_802A3370(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349B28;
        fn_8028E398(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" int lbl_80349B00[];
extern "C" void* __dt__14CollisionSpaceFv_802A366C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349B00;
        fn_8028E398(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_802A4958(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" u8 fn_802A4998(void) {
    return 0;
}

extern "C" void fn_802A49A0(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v2();
}

extern "C" void fn_802A49C8(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v4();
}

extern "C" u32 fn_802A4A18(void) { return 1; }

extern "C" u8 fn_802A4A20(void) {
    return 2;
}

extern "C" u32 fn_802A4A28(void) { return 3; }

extern "C" u32 fn_802A4A30(void) { return 4; }

extern "C" u32 fn_802A4A38(void) { return 5; }

extern "C" u32 fn_802A4A40(void) { return 6; }

