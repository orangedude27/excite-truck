#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8015474C(void);
extern s32 fn_80128668(void);
extern void fn_80128668(void*);
extern void fn_80138AD8(void* this_, u32 a);
extern u8 lbl_8032E46C[];
extern u8 lbl_8032E448[];

extern void **lbl_8055E27C;

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

extern "C" {
extern "C" void fn_8015474C(s32);
void fn_80156188(s32 arg0) {
    fn_8015474C(arg0 - 4);
}

extern "C" s32 fn_801556FC(s32);
extern "C" void fn_801561C8(s32 arg0) {
    fn_801556FC(arg0 - 0xC);
}

extern "C" s32 fn_80155700(s32);
extern "C" void fn_801561D0(s32 arg0) {
    fn_80155700(arg0 - 0xC);
}

extern "C" s32 fn_80155AEC(s32);
extern "C" void fn_801561D8(s32 arg0) {
    fn_80155AEC(arg0 - 0xC);
}

extern "C" s32 fn_80155AF0(s32);
extern "C" void fn_801561E0(s32 arg0) {
    fn_80155AF0(arg0 - 0xC);
}

extern "C" s32* fn_801E87A8();
extern "C" void* fn_8001285C(s32);
s32 fn_8015621C(void) {
    return *(s32*)((char*)fn_8001285C(*fn_801E87A8()) + 0x20);
}

s32 fn_801568E0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80156920(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern f32 fn_80129DC4(s32, s32, s32, f32, f32);
extern f32 lbl_8055E3C8;

void fn_80156960(void *arg0) {
    void *inp = arg0;
    s32 count = 0;
    void *out = arg0;
    f32 f31 = lbl_8055E3C8;
    
    do {
        s32 divisor = ((s32 *)inp)[2];
        void *data_ptr = (void *)((s32 *)inp)[1];
        s32 idx = count - ((count / divisor) * divisor);
        s32 val = *(s32 *)((u8 *)data_ptr + (idx * 8));
        f32 f1 = ((f32 *)inp)[0xDC / 4];
        f32 f2 = ((f32 *)inp)[0xE0 / 4];
        f32 result = fn_80129DC4(4, divisor, (s32)(long)data_ptr, f1, f2);
        result = f31 + result;
        ((f32 *)out)[0xE4 / 4] = result;
        *(s32 *)((u8 *)out + 0xE8) = val;
        out = (u8 *)out + 8;
        count++;
    } while (count < 8);
}

void fn_801569FC(void) {
    void *ptr = lbl_8055E27C;
    if (ptr != 0) {
        void (*fn)(s32) = (void (*)(s32))*(void**)((u8*)*(void***)ptr + 0x28);
        fn(1);
    }
    lbl_8055E27C = 0;
}

s32 fn_80156A40(void) {
    return (s32)lbl_8055E27C;
}

extern void fn_80128668(void*);
extern void **lbl_8055E27C;
extern u8 lbl_8032E46C[];
extern void fn_80138AD8(void* this_, u32 a);
void* __dt__Q28PSSystem7SeqHeapFv_80156A4C(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E46C;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E46C);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

s32 fn_80156AB0(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_80156AB8(void *arg0) {
    return ((s32 *)arg0)[1];
}

extern u8 lbl_8032E448[];
extern void fn_80138AD8(void* this_, u32 a);
void* __dt__Q28PSSystem7SeqHeapFv_80156AC4(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E448;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E448);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

s32 fn_80156B28(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_80156B30(void *arg0, s32 arg1) {
    if (arg1 == 0) return ((s32 *)arg0)[1];
    return 0;
}

}

void fn_80156AC0(void) {

}

void fn_80156B48(void) {

}

void fn_80156B4C(void) {
    return;
}

void fn_80156B50(void) {
    return;
}

s32 fn_80156C60(void *arg0, s32 arg1) {
    if (arg1 >= ((s32 *)arg0)[2]) return 0;
    return ((s32 *)((s32 *)arg0)[1])[arg1 * 2];
}

extern s32 fn_80129D90(s32, s32, s32);
void fn_80156DCC(void *arg0, s32 arg1) {
    s32 temp_r28 = arg1 * 8;
    void *temp_r31 = (u8 *)arg0 + temp_r28;
    f32 temp_f31 = lbl_8055E3C8;
    u32 temp_r30 = *(u32 *)((u8 *)temp_r31 + 0xE8);
    s32 temp_r3 = fn_80129D90(4, 0, ((s32 *)arg0)[2]);
    u32 *temp_r5 = (u32 *)((s32 *)arg0)[1];
    u32 var_r29 = *(u32 *)((u8 *)temp_r5 + temp_r3 * 8);
    if (var_r29 == temp_r30) {
        s32 count = ((s32 *)arg0)[2];
        s32 next = temp_r3 + 1;
        s32 index = next - ((next / count) * count);
        var_r29 = *(u32 *)((u8 *)temp_r5 + index * 8);
    }
    *(f32 *)((u8 *)arg0 + temp_r28 + 0xE4) = temp_f31 +
      fn_80129DC4(4, ((s32 *)arg0)[2], (s32)(long)temp_r5,
                  *(f32 *)((u8 *)arg0 + 0xDC), *(f32 *)((u8 *)arg0 + 0xE0));
    *(u32 *)((u8 *)temp_r31 + 0xE8) = var_r29;
}

extern "C" void* fn_801570D0(void* arg0, s32 arg1) {
    extern u8 lbl_8032E3F8[];
    struct Obj { virtual void c(s32); };
    if (arg0 != 0) {
        Obj* obj = *(Obj**)((u8*)arg0 + 8);
        *(u32*)arg0 = (u32)lbl_8032E3F8;
        if (obj != 0) {
            obj->c(1);
        }
        obj = *(Obj**)((u8*)arg0 + 4);
        if (obj != 0) {
            obj->c(1);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80157170(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_b->v2();
}

extern "C" void fn_80157184(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v1();
}

extern "C" void fn_80157198(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_b->v2();
}

extern "C" void fn_801571AC(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v2();
}

void ebi::title::TBlackPlane::updateAfterCamera() {
    m_b->v3();
    m_a->v3();
}

extern "C" void fn_80157210(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v4();
}

extern "C" void fn_80157224(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v5();
}

extern "C" void fn_80157238(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v6();
}

