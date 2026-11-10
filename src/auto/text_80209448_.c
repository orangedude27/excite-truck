// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#define M2C_UNK s32
#define M2C_FIELD(expr, type, offset) (*(type)((u8 *)(expr) + (offset)))
#define M2C_VFUNC(obj, slot, type) ((type)(*(void ***)(obj))[slot])
typedef void *(*M2CPtr0)(void *);
typedef void *(*M2CPtr1)(void *, const char *);
typedef void *(*M2CPtrIndex)(void *, s32);
typedef s32 (*M2CS32_1)(void *, const char *);
typedef f32 (*M2CF32_2)(void *, const char *, f32);
typedef f32 (*M2CF32_1)(void *, const char *);
typedef f32 (*M2CF32_0)(void *);
typedef void *(*M2CPtr2)(void *, const char *, s32);

extern f32 lbl_8056323C;
extern int strcmp(const char *, const char *);
extern void *memset(void *, int, unsigned int);
extern void fn_80127C90(void *, const char *);
extern void *fn_801284F8(s32, const char *);
extern void *fn_80131808(void);
extern void fn_80131818(void *);
extern s32 fn_80137C74(void);
extern void *fn_802077A4(void *, s32, void *, void *);
extern void *fn_80207848(void *, s32);
extern void fn_802E30C8(const char *, ...);
extern void fn_80209904(void);
extern u8 lbl_8033C1E0[], lbl_8033C1F0[], lbl_8033C1FC[], lbl_8033C208[];
extern u8 lbl_8033C21C[], lbl_8033C22C[], lbl_8033C238[], lbl_8033C248[];
extern s32 lbl_8055B4F8, lbl_8055EDBC;
extern u8 lbl_8055B500, lbl_8055B508, lbl_8055B510, lbl_8055B514;
extern u8 lbl_8055B518, lbl_8055B51C, lbl_8055B520, lbl_8055B528;
extern u8 lbl_8055B52C, lbl_8055B534, lbl_8055B53C;
extern f32 lbl_8055EDB8;
extern f32 lbl_80563238, lbl_8056323C, lbl_80563240, lbl_80563244;
extern f32 lbl_80563248, lbl_8056324C, lbl_80563250, lbl_80563254;
#pragma cplusplus on
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_loop_invariants off
#pragma scheduling invalid_target
extern "C" void *fn_80209448(void *arg0) {
extern void *fn_802077A4(void *, s32, void *, void *);
extern void *fn_80207848(void *, s32);
struct Block {
    void *entry;
    f32 f04;
    f32 f08;
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
};
struct MyClass {
    void *vtable;
    Block blocks[6];
    s32 count;
    void *arg0;
    f32 f144;
    f32 f148;
    f32 f14c;
    f32 f150;
    f32 f154;
};
struct M2CKeyObject {
virtual void *f2(const char *);
virtual void *f3();
virtual void *f4();
virtual void *f5();
virtual void *f6(const char *, s32);
};
struct M2CManager {
virtual void *f2(const char *);
virtual void *f3(s32);
};
struct M2CItem {
virtual const char *f2();
virtual void *f3();
virtual void *f4();
virtual void *f5(const char *);
virtual void *f6();
virtual void *f7();
virtual void *f8();
virtual f32 f9(const char *);
virtual void *f10();
virtual void *f11();
virtual void *f12();
virtual void *f13();
virtual void *f14();
virtual void *f15();
virtual void *f16();
virtual void *f17();
virtual void *f18();
virtual void *f19();
virtual void *f20();
virtual void *f21();
virtual void *f22();
virtual void *f23(const char *);
};
struct M2CValues {
virtual void *f2();
virtual void *f3();
virtual void *f4();
virtual void *f5();
virtual void *f6();
virtual void *f7();
virtual void *f8();
virtual f64 f9(const char *);
virtual f32 f10(const char *, f32);
};
MyClass *result;
s32 index;
void *manager;
void *item;
void *text;
void *block;
void *object;
f64 temp_f1;
f32 z, scale, height;
f32 width, half, e, d, c, b, a, y, x;
result = (MyClass *)fn_801284F8(0x158, (const char *)&lbl_8055B500);
if (result != 0) {
result->vtable = (void *)&lbl_8033C1E0;
if (lbl_8055EDBC == 0) {
lbl_8055EDB8 = lbl_80563238;
fn_80127C90((void *)fn_80209904, (const char *)&lbl_8055B520);
}
lbl_8055EDBC++;
result->arg0 = arg0;
result->count = 0;
object = M2C_FIELD(M2C_FIELD(arg0, void **, 0x26C), void **, 0x2134);
object = ((M2CKeyObject *)object)->f2((const char *)&lbl_8033C248);
((M2CKeyObject *)object)->f6((const char *)&lbl_8033C238, lbl_8055B4F8);
manager = fn_80131808();
block = ((M2CManager *)manager)->f2((const char *)&lbl_8055B53C);
result->f14c = ((M2CValues *)block)->f10((const char *)&lbl_8033C22C, lbl_8056323C);
temp_f1 = ((M2CValues *)block)->f9((const char *)&lbl_8033C21C);
width = (f32)temp_f1;
half = lbl_80563240;
result->f144 = temp_f1;
index = 0;
scale = lbl_8056323C;
result->f148 = half * width;
height = lbl_80563244;
z = lbl_80563238;
goto loop_test;
loop_body:
if (strcmp(((M2CItem *)item)->f2(), (const char *)&lbl_8055B534) == 0) {
Block *b_entry = &result->blocks[result->count++];
block = (void *)b_entry;
memset(block, 0, 0x34);
text = ((M2CItem *)item)->f5((const char *)&lbl_8055B52C);
void *entry;
void *obj = result->arg0;
if (M2C_FIELD(obj, s32 *, 0x1F0) != 0x50) {
entry = fn_802077A4(text, 3, (u8 *)obj + 0x118, (u8 *)arg0 + 0x60);
((Block *)block)->entry = entry;
} else {
entry = fn_80207848(text, 2);
if (entry != 0) {
if (fn_80137C74() == 2) {
if ((M2C_FIELD(result->arg0, u8 *, 0x260) & 3) == 0) {
if (height != M2C_FIELD(entry, f32 *, 0x64)) {
M2C_FIELD(entry, u8 *, 0x6C) = 1;
M2C_FIELD(entry, f32 *, 0x64) = height;
}
} else if (scale != M2C_FIELD(entry, f32 *, 0x64)) {
M2C_FIELD(entry, u8 *, 0x6C) = 1;
M2C_FIELD(entry, f32 *, 0x64) = scale;
}
}
if (z != M2C_FIELD(entry, f32 *, 0x68)) {
M2C_FIELD(entry, u8 *, 0x6D) = 1;
M2C_FIELD(entry, f32 *, 0x68) = z;
}
}
((Block *)block)->entry = entry;
}
((Block *)block)->f30 = z;
entry = ((Block *)block)->entry;
if (entry == 0) {
fn_802E30C8((const char *)&lbl_8033C208, text);
result->count--;
} else {
M2C_FIELD(entry, s32 *, 0x10) = M2C_FIELD(arg0, s32 *, 0x1EC);
text = ((M2CItem *)item)->f23((const char *)&lbl_8033C1FC);
y = ((M2CValues *)text)->f10((const char *)&lbl_8055B508, lbl_8056323C);
x = ((M2CValues *)text)->f10((const char *)&lbl_8055B510, lbl_80563248);
a = ((M2CValues *)text)->f10((const char *)&lbl_8055B514, lbl_8056324C);
b = ((M2CValues *)text)->f10((const char *)&lbl_8055B518, lbl_80563250);
c = ((M2CValues *)text)->f10((const char *)&lbl_8055B51C, lbl_80563254);
((Block *)block)->f1c = b;
((Block *)block)->f20 = a;
d = scale / (b - c);
((Block *)block)->f24 = d;
((Block *)block)->f28 = scale / (x - a);
((Block *)block)->f2c = y;
text = M2C_VFUNC(item, 23, M2CPtr1)(item, (const char *)&lbl_8055B528);
e = ((M2CValues *)text)->f10((const char *)&lbl_8055B508, lbl_8056323C);
a = ((M2CValues *)text)->f10((const char *)&lbl_8055B510, lbl_80563248);
x = ((M2CValues *)text)->f10((const char *)&lbl_8055B514, lbl_8056324C);
b = ((M2CValues *)text)->f10((const char *)&lbl_8055B518, lbl_80563250);
c = ((M2CValues *)text)->f10((const char *)&lbl_8055B51C, lbl_80563254);
((Block *)block)->f08 = b;
((Block *)block)->f0c = x;
d = scale / (b - c);
((Block *)block)->f10 = d;
((Block *)block)->f14 = scale / (a - x);
((Block *)block)->f18 = e;
((Block *)block)->f04 = scale / ((M2CItem *)item)->f9((const char *)&lbl_8033C1F0);
}
}
index++;
loop_test:
item = ((M2CManager *)manager)->f3(index);
if (item != 0) goto loop_body;
fn_80131818(manager);
result->f150 = lbl_80563238;
result->f154 = lbl_80563238;
}
return result;
}

extern s32 fn_800216D0(void);
extern s32 fn_801B89F8(void);
extern f32 lbl_80563238;
extern f32 lbl_80563258;
extern f32 lbl_8055B4FC;
void fn_80209904(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f2;
    f32 var_f2_2;
    s32 var_r31;
    var_r31 = 0;
    if ((fn_800216D0() != 0) || (fn_801B89F8() != 0)) {
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        temp_f0 = lbl_8055EDB8 - lbl_80563258;
        var_f2 = lbl_80563238 > temp_f0 ? lbl_80563238 : temp_f0;
        lbl_8055EDB8 = var_f2;
    } else {
        temp_f0_2 = lbl_80563258 + lbl_8055EDB8;
        var_f2_2 = lbl_8055B4FC < temp_f0_2 ? lbl_8055B4FC : temp_f0_2;
        lbl_8055EDB8 = var_f2_2;
    }
}

extern "C" void fn_80209904(void);
extern "C" void fn_80127D58(void *);
extern "C" void fn_80128668(void *);
extern "C" s32 lbl_8055EDBC;
extern "C" u8 lbl_8033C1E0[];
extern "C" void *fn_8020999C(void *arg0, s32 arg1) {
    struct ItemDummy {
        virtual void m0(s32) = 0;
    };
    u8 *p;
    void *item;
    s32 i;
    if (arg0 != 0) {
        *(s32 *)arg0 = (s32)&lbl_8033C1E0[0];
        p = (u8 *)arg0;
        i = 0;
        goto check;
    loop:
        item = *(void **)(p + 4);
        if (item != 0)
            ((ItemDummy *)item)->m0(1);
        p += 0x34;
        i += 1;
    check:
        if (i < *(s32 *)((u8 *)arg0 + 0x13C))
            goto loop;
        if (--lbl_8055EDBC == 0)
            fn_80127D58((void *)fn_80209904);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma pop

extern "C" s32 fn_80178CA4(void);
extern "C" s32 fn_8026A344(s32);
extern f32 lbl_8056325C, lbl_80563260, lbl_80563264, lbl_80563268, lbl_8056326C, lbl_80563270;
extern "C" s32 fn_80178CA4(void);
extern "C" s32 fn_8026A344(s32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80209A64(void *obj, s32 muted) {
    void *cfg = M2C_FIELD(obj, void **, 0x140);
    f32 old = M2C_FIELD(obj, f32 *, 0x154);
    f32 rpm;
    f32 speed = M2C_FIELD(obj, f32 *, 0x14c) * M2C_FIELD(cfg, f32 *, 0x25d0);
    f32 value, factor, weight;
    s32 i, found = 0, count;
    u8 *entry;
    M2C_FIELD(obj, f32 *, 0x154) = old + lbl_8056325C * (lbl_8056323C - old);
    M2C_FIELD(obj, f32 *, 0x150) = speed;
    rpm = M2C_FIELD(cfg, f32 *, 0x25fc);
    count = fn_80178CA4();
    { s32 id;
    for (i = 0; i < count; i++) {
        id = M2C_FIELD(M2C_FIELD(obj, void **, 0x140), s32 *, 0x1ec);
        if (fn_8026A344(i) == id) { found = 1; break; }
    }
    }
    factor = found ? M2C_FIELD(obj, f32 *, 0x144) : M2C_FIELD(obj, f32 *, 0x148);
    if (muted) factor = lbl_80563238;
    entry = (u8 *)obj + 4;
    {
    f32 one = lbl_8056323C, smooth = lbl_80563260, two = lbl_80563264, hi = lbl_80563268, lo = lbl_8056326C, gain = lbl_80563270;
    for (i = 0; i < M2C_FIELD(obj, s32 *, 0x13c); i++, entry += 0x34) {
        f32 a = lbl_8056323C, b = lbl_8056323C, temp, x, out;
        void *sound;
        if (speed < M2C_FIELD(entry, f32 *, 8)) {
            temp = M2C_FIELD(entry, f32 *, 0x10) * (M2C_FIELD(entry, f32 *, 8) - speed);
            a = a < temp ? a : temp;
            a = one - a;
        } else if (speed > M2C_FIELD(entry, f32 *, 0xc)) {
            temp = M2C_FIELD(entry, f32 *, 0x14) * (speed - M2C_FIELD(entry, f32 *, 0xc));
            if (a >= temp) a = temp;
            a = one - a;
        }
        x = (smooth - two * a) * (a * a) * M2C_FIELD(entry, f32 *, 0x18);
        if (rpm < M2C_FIELD(entry, f32 *, 0x1c)) {
            temp = M2C_FIELD(entry, f32 *, 0x24) * (M2C_FIELD(entry, f32 *, 0x1c) - rpm);
            b = b < temp ? b : temp;
            b = one - b;
        } else if (rpm > M2C_FIELD(entry, f32 *, 0x20)) {
            temp = M2C_FIELD(entry, f32 *, 0x28) * (rpm - M2C_FIELD(entry, f32 *, 0x20));
            if (b >= temp) b = temp;
            b = one - b;
        }
        weight = (smooth - two * b) * (b * b) * M2C_FIELD(entry, f32 *, 0x2c);
        sound = M2C_FIELD(entry, void **, 0);
        M2C_FIELD(sound, u8 *, 0x4a) = 0;
        M2C_FIELD(sound, u8 *, 0x4b) = 1;
        M2C_FIELD(sound, u8 *, 0x49) = 1;
        value = speed * M2C_FIELD(entry, f32 *, 4);
        if (value != M2C_FIELD(sound, f32 *, 4)) {
            M2C_FIELD(sound, u8 *, 0x4e) = 1;
            M2C_FIELD(sound, f32 *, 4) = value;
        }
        temp = lbl_8055EDB8 * x * weight - M2C_FIELD(entry, f32 *, 0x30);
        if (hi < temp) temp = hi;
        if (temp <= lo) temp = lo;
        out = M2C_FIELD(entry, f32 *, 0x30) + temp;
        M2C_FIELD(entry, f32 *, 0x30) = out;
        value = (gain + gain * M2C_FIELD(obj, f32 *, 0x154)) * (out * factor);
        if (value != M2C_FIELD(sound, f32 *, 8)) {
            M2C_FIELD(sound, u8 *, 0x4d) = 1;
            M2C_FIELD(sound, f32 *, 8) = value;
        }
    }
    }
}
#pragma pop

#pragma scheduling on
#pragma cplusplus reset
