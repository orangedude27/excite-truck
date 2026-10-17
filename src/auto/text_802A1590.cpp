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
extern "C" s32 fn_802A47A8(void*);
extern "C" void fn_802A2AE8(void*, s32);
extern "C" void fn_802A2BF4(void*, s32);
extern "C" void fn_802A2D04(void*, s32);
extern "C" void fn_802A2E08(void*, s32);
extern "C" void fn_802A44B8(void*, s32);
extern "C" int lbl_80349B78[];
extern "C" int lbl_8055F870;
extern "C" float lbl_80564734;
extern "C" float lbl_80564744;
extern "C" void fn_802A4524(void*);
extern "C" s32 fn_80287B14(void*);

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

extern "C" void* fn_802A1DF4(void* arg0, void* arg1) {
    s32 value;
    *(void**)arg0 = &lbl_80349B78;
    value = (*(s32 (**)(void*, void*))((char*)*(void**)arg1 + 0x14))(arg1, (void*)lbl_8055CBB0);
    fn_802A2AE8(arg0, value);
    fn_802A2BF4(arg0, value);
    fn_802A2D04(arg0, value);
    fn_802A2E08(arg0, value);
    return arg0;
}

extern "C" void* fn_802A1E80(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        void* vtable = &lbl_80349B78;
        *(void**)arg0 = vtable;
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

extern "C" void fn_802A1F00(void *arg0) {
    float f30 = lbl_80564744;
    float f31 = lbl_80564734;
    s32 count = 0;
    void* p = arg0;
    while (count < fn_802A47A8(p)) {
        *(float*)((char*)p + 0x14) = f30;
        count++;
        *(float*)((char*)p + 0x18) = f31;
        *(float*)((char*)p + 0x1C) = f30;
        *(float*)((char*)p + 0x20) = f30;
        p = (char*)p + 0x10;
    }
    fn_802A4524(*(void**)((char*)arg0 + 0x10));
}

extern "C" void fn_802A2118(void *arg0) {
    fn_802A47A8((void*)*(void**)((char*)arg0 + 0x10));
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
    s32 result = (*(s32 (**)(void*, void*))(*(void**)((char*)arg1 + 0x14)))(arg1, (void*)lbl_8055CBB0);
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

extern "C" float fn_80287BC8(float, float);
extern "C" void fn_8028E590(int, float *, float *, float);
extern "C" float lbl_80564730, lbl_80564740, lbl_80564744, lbl_80564758, lbl_8056475C, lbl_80564760, lbl_80564764, lbl_8056476C, lbl_8056477C, lbl_805647A4, lbl_8056481C, lbl_8056482C;
extern "C" void fn_802A3990(void *arg0, void *arg1, int arg2) {
    float sp1C, sp18, sp14, sp10, spC, sp8, temp_f1, temp_f1_2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, var_f0, var_f31, var_f1;
    unsigned char *obj = *(unsigned char **)arg1, *p = obj + arg2 * 0x3C;
    if (*(float *)((char *)arg1 + 8) > lbl_8056476C) return;
    temp_f1 = *(float *)(p + 0x94); if (temp_f1 * temp_f1 < lbl_80564758) return;
    if (*(float *)(p + 0x70) > lbl_80564744) var_f31 = lbl_80564730; else var_f31 = lbl_8056475C;
    if (*(float *)(p + 0x94) > lbl_80564744) var_f1 = lbl_80564730; else var_f1 = lbl_8056475C;
    temp_f8 = *(float *)(p + 0x78) - lbl_80564760 * var_f1; temp_f6 = *(float *)(p + 0x70); temp_f7 = lbl_80564740 + *(float *)(p + 0x74);
    sp14=temp_f6; sp18=temp_f7; sp1C=temp_f8;
    if (&sp14 == &sp14) {
        sp14=temp_f8 * *(float *)(obj+0x18)+(temp_f6 * *(float *)obj+temp_f7 * *(float *)(obj+0xC));
        sp18=temp_f8 * *(float *)(obj+0x1C)+(temp_f6 * *(float *)(obj+4)+temp_f7 * *(float *)(obj+0x10));
        sp1C=temp_f8 * *(float *)(obj+0x20)+(temp_f6 * *(float *)(obj+8)+temp_f7 * *(float *)(obj+0x14));
    } else {
        temp_f3=temp_f8 * *(float *)(obj+0x18)+(temp_f6 * *(float *)obj+temp_f7 * *(float *)(obj+0xC)); sp14=temp_f3;
        temp_f4=temp_f8 * *(float *)(obj+0x1C)+(temp_f3 * *(float *)(obj+4)+temp_f7 * *(float *)(obj+0x10)); sp18=temp_f4;
        sp1C=temp_f8 * *(float *)(obj+0x20)+(temp_f3 * *(float *)(obj+8)+temp_f4 * *(float *)(obj+0x14));
    }
    sp14+=*(float *)(obj+0x24); sp18+=*(float *)(obj+0x28); sp1C+=*(float *)(obj+0x2C);
    var_f0=lbl_805647A4; temp_f5=lbl_80564764+lbl_8056481C*(var_f31* *(float *)(obj+0x50));
    sp8=*(float *)(obj+0x34)+*(float *)obj*temp_f5; spC=*(float *)(obj+0x38)+*(float *)(obj+4)*temp_f5; sp10=*(float *)(obj+0x3C)+*(float *)(obj+8)*temp_f5;
    temp_f1_2=lbl_80564764+lbl_8056482C* *(float *)(obj+0x50); if(var_f0<temp_f1_2){}else var_f0=temp_f1_2;
    sp8+=*(float *)(obj+0xC)*var_f0; temp_f5=*(float *)(obj+0x10)*var_f0; spC+=temp_f5; temp_f4=*(float *)(obj+0x14); sp10+=temp_f4*var_f0;
    fn_8028E590(*(int *)((char *)arg0+4),&sp14,&sp8,-var_f31*fn_80287BC8(lbl_80564744,lbl_8056477C));
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

void fn_802A4118(void *arg0, void *arg1) {
    f32 *p = (f32 *)((char *)arg0 + (*(s32 *)((char *)arg1 + 0x28) * 4));
    f32 f = p[2];
    if (f > (lbl_80564730 - lbl_80558DC4)) {
        p[2] = f - lbl_80564730;
    }
    p[2] += lbl_80564750;
}

extern "C" void fn_802A44B4(void) {
}

#pragma scheduling off
extern "C" void fn_802A4524(void *arg0) {
    *(f32*)((char*)arg0 + 0x18) = lbl_80564744;
    *(s32*)((char*)arg0 + 0x4) = 0;
}
#pragma scheduling on
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