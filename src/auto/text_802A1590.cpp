#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" s32 fn_80128668(void);
extern "C" void fn_8028E398(void*);
extern "C" int lbl_80349B28[];
extern "C" int lbl_80349B50[];
extern "C" int lbl_80349AD8[];
extern "C" int lbl_8055CBB0[];
extern "C" void fn_802A3500(void*, s32);
extern "C" void fn_802A30BC(void*, s32);
extern "C" void fn_802A31DC(void*, s32);
extern "C" void fn_802A2AE8(void*, s32);
extern "C" void fn_802A2BF4(void*, s32);
extern "C" void fn_802A2D04(void*, s32);
extern "C" void fn_802A2E08(void*, s32);
extern "C" void fn_802A44B8(void*, s32);
extern "C" int lbl_80349B78[];
extern "C" int lbl_8055F870;

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

extern "C" void fn_802A1CC0(void) {
}

extern "C" void fn_802A1DC0(void) {
    if (lbl_8055F870 != 0) {
        fn_8028E398((void *)lbl_8055F870);
        lbl_8055F870 = 0;
    }
}

extern "C" void* fn_802A1E80(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349B78;
        fn_802A44B8(*(void**)((char*)arg0 + 0x10), 1);
        fn_8028E398(*(void**)((char*)arg0 + 0xC));
        fn_8028E398(*(void**)((char*)arg0 + 8));
        fn_8028E398(*(void**)((char*)arg0 + 4));
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" f32 lbl_80558DC4;
extern "C" f32 lbl_80564730;
extern "C" f32 lbl_80564750;
extern "C" f32 lbl_80564744;
extern "C" int lbl_80349AB0[];
extern "C" void fn_8028E584(void*, void*);
extern "C" s32 fn_80287B14(void*);
extern "C" void fn_802A2A38(void* arg0, void* arg1) {
    s32 index = *(s32*)((char*)arg1 + 0x28);
    f32* value = (f32*)((char*)arg0 + (index << 4) + 0x20);
    if (*value > lbl_80564730 - lbl_80558DC4) {
        fn_8028E584(*(void**)((char*)arg0 + 0xC), (char*)arg1 + 0xC);
    }
    index = *(s32*)((char*)arg1 + 0x28);
    value = (f32*)((char*)arg0 + (index << 4) + 0x20);
    if (*value > lbl_80564730 - lbl_80558DC4) {
        *value -= lbl_80564730;
    }
    *value += lbl_80564750;
}

extern "C" void* fn_802A2EEC(void* arg0, void* arg1) {
    *(void**)arg0 = lbl_80349B50;
    s32 result = (*(s32 (**)(void*, void*))(*(void**)((char*)arg1 + 0x14)))(arg1, &lbl_8055CBB0);
    fn_802A30BC(arg0, result);
    fn_802A31DC(arg0, result);
    return arg0;
}

extern "C" void* __dt__8JUTVideoFv(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80349B50;
        fn_8028E398(*(void**)((char*)arg0 + 8));
        fn_8028E398(*(void**)((char*)arg0 + 4));
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void* fn_802A3314(void* arg0, void* arg1) {
    *(void**)arg0 = lbl_80349B28;
    void* vtable = *(void**)arg1;
    s32 result = (*(s32 (**)(void*, void*))( (char*)vtable + 0x14))(arg1, (void*)lbl_8055CBB0);
    fn_802A3500(arg0, result);
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

extern "C" int lbl_80349B50[];
extern "C" int lbl_80349AD8[];
extern "C" int lbl_8055CBB0[];
extern "C" void fn_802A3500(void*, s32);
extern "C" void fn_802A30BC(void*, s32);
extern "C" void fn_802A31DC(void*, s32);
extern "C" void* __dt__14CollisionSpaceFv_802A392C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80349AD8;
        fn_8028E398(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void* __dt__14CollisionSpaceFv_802A3D98(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349AB0;
        fn_8028E398(*(void**)((char*)arg0 + 4));
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802A3DFC(void* arg0) {
    f32* cursor = (f32*)((char*)arg0 + 8);
    s32 i = 0;
    do {
        *cursor = lbl_80564744;
        cursor++;
        i++;
    } while (i < fn_80287B14(arg0));
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

extern "C" void fn_802A49DC(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v5();
}

extern "C" void fn_802A49F0(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v6();
}

extern "C" u32 fn_802A4A18(void) { return 1; }

extern "C" u8 fn_802A4A20(void) {
    return 2;
}

extern "C" u32 fn_802A4A28(void) { return 3; }

extern "C" u32 fn_802A4A30(void) { return 4; }

extern "C" u32 fn_802A4A38(void) { return 5; }

extern "C" u32 fn_802A4A40(void) { return 6; }

