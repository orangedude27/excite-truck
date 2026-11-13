#include <types.h>

extern void *fn_801284F8(u32, const void *);
extern f32 lbl_8055E0A8;
extern void *lbl_8042F758[];
extern void *lbl_8055E0D4;
extern f32 lbl_80561304;
extern void *lbl_8055E0B0;
extern f32 lbl_80560108, lbl_8056010C;
extern f64 lbl_80561308, lbl_80561310;
extern void *fn_8001285C(s32);
extern s32 *fn_801E87A8(void);
extern u32 lbl_80559BD8;
extern const char lbl_8032BC84[], lbl_8032BC94[], lbl_8032BCA0[];
extern const char lbl_8032BD08[], lbl_8032BCC0[];
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_801792F8(void);
  extern s32 fn_80134D54(void);
  extern f32 fn_80134D78(void);
  extern f32 fn_80134DF8(void);
  extern s32 fn_801769A8(void);
  extern void *fn_80134E90(void);
      /* fn_80134EC8 takes bits arg; see definition */
  extern void *fn_80134FF8(void);
  extern void *fn_801350C0(void);
  extern void *fn_801A520C(void *, void *);
  extern void *fn_801B83A0(void);
  extern void *fn_801938F4(void *);
  extern void fn_802E30C8(const char *, ...);
  extern const char lbl_8032BC50[];
  extern const char lbl_8032BC5C[];
  
  extern s32 fn_80128668(void);
  extern f32 lbl_805612F4;
  extern f32 lbl_80561318;
  extern const char lbl_8032BD98[];
  extern s32 fn_802E317C(const char *, ...);
  
  // Code of main that had no source file yet: decomp.wtf gave it this one.
  // split_file divides it into the game's real files (file_status shows its range).
  
  extern void *lbl_8055E0AC;
  extern void *fn_8001285C(s32);
  extern s32 *fn_801E87A8(void);
  extern u32 lbl_80559BD8;
  void fn_8013471C(void *arg0, s32 arg1) {
      *(s32 *)arg0 = arg1;
      *((u8 *)arg0 + 4) = 1;
  }
  
#pragma dont_inline fn_8013472C
#pragma push
  #pragma cplusplus on
extern "C" void fn_8013472C(void) {
    struct Dummy {
        virtual void f0();
        virtual void f2();
        virtual void f1();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f21();
        virtual void *f22(u32 *);
        virtual void f20();
    };
    register void *sub = *(void **)((u8 *)fn_8001285C(*fn_801E87A8()) + 0x20);
    lbl_8055E0AC = ((Dummy *)sub)->f22(&lbl_80559BD8);
}
#pragma cplusplus reset
#pragma pop
  #pragma dont_inline __AXDSPInitCallback_80134770
void __AXDSPInitCallback_80134770(void) {
      lbl_8055E0AC = 0;
  }

extern char lbl_8032BBE8[];
extern f32 lbl_805612E8, lbl_805612EC, lbl_805612F0, lbl_805612F8, lbl_805612FC, lbl_80561300;
extern f32 lbl_8055E0A0, lbl_8055E0A4;
extern f32 fn_80134B58(s32, f32);
extern void fn_8013B4E0(void*, void*);
extern f32 fn_8013672C(void);
extern void fn_80137884(s32);
extern void fn_80139044(void);
extern void fn_8013BAE4(s32);
extern void fn_801663C8(s32, void*, void*);
extern void fn_8013A1E8(void);
extern void fn_8015F554(void);
extern void fn_80160850(void);
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8013477C(void *arg0) {
    register char *strings = lbl_8032BBE8;
    register unsigned char *entry;
    register void **out;
    register unsigned char *obj = (unsigned char *)arg0 + 0x20;
    register s32 i;
    register s32 count;
    register unsigned char *end;
    void *slot;
    f32 value;
    f32 temp;
    f32 f0;
    f32 f1;
    f32 f2;

#pragma dont_inline on
    fn_8013472C();
#pragma dont_inline reset
    count = *(s32 *)(obj + 0x3C0);
    *(volatile s32 *)&lbl_8055E0B0 = count;
    end = obj + count * 0x78;
#pragma scheduling invalid_target
    while (count > 0 && *(s32 *)(end - 0x78) == 0x53) {
        count--;
        *(volatile s32 *)&lbl_8055E0B0 = count;
        end -= 0x78;
    }
#pragma scheduling on
    fn_8013B4E0(obj, arg0);
    value = fn_80134B58((s32)(strings + 0x0C), lbl_805612F0);
    lbl_8055E0A0 = value;
    if (value < lbl_805612F4) {
        temp = lbl_805612E8 * fn_80134B58((s32)(strings + 12 - 12), lbl_805612EC);
        lbl_8055E0A0 = fn_8013672C() - temp;
    }
    f1 = fn_80134B58((s32)(strings + 0x1C), lbl_805612FC);
    f2 = lbl_805612F8;
    fn_802E30C8(strings + 0x28, (lbl_8055E0A8 = f0 = f2 * f1, f0 / f2), f2);
    f1 = fn_8013672C();
    f0 = f1 * lbl_80561300;
    lbl_8055E0A4 = fn_80134B58((s32)(strings + 0x44), f0);
    fn_80137884(*(s32 *)&lbl_8055E0B0);
    fn_801E87A8();
    fn_80139044();
    fn_8013BAE4(*(s32 *)&lbl_8055E0B0);
    fn_801663C8(*(s32 *)&lbl_8055E0B0, obj, (unsigned char *)arg0 + 0x3E4);
#pragma scheduling invalid_target
    entry = obj;
    out = lbl_8042F758;
    i = 0;
    while (i < *(s32 *)(obj + 0x3C0)) {
        if (*(s32 *)entry != 0x53) {
            slot = fn_801284F8(8, strings + 0x58);
            if (slot != 0) {
                *out = ((void *(*)(void *, s32))fn_8013471C)(slot, i);
            }
        }
        entry += 0x78;
        out++;
        i++;
    }
#pragma scheduling on
    fn_8013A1E8();
    fn_8015F554();
    fn_80160850();
}
#pragma use_lmw_stmw reset
#pragma pop
extern void fn_80160AE4(void);
extern void fn_8015F558(void);
extern void fn_8013A1EC(void);
extern void fn_8013B56C(void);
extern void fn_80166814(void);
extern void fn_801378D0(void);
extern void __AXDSPInitCallback_80134770(void);
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8013490C(void) {
    register void **entries;
    register s32 index;
    register s32 zero;
    void *item;

    /* Shut down AX/DSP-related subsystems, free/clear 8 tracked resource slots in lbl_8042F758, then reset DSP callback/state. */
    fn_80160AE4();
    fn_8015F558();
    fn_8013A1EC();
    fn_8013B56C();
    fn_80166814();
    entries = lbl_8042F758;
    index = 0;
    zero = 0;
    do {
        item = *entries;
        if (item == 0)
            goto skip_clear;
        if (item == 0)
            goto clear_item;
        ((void (*)(void *))fn_80128668)(item);
clear_item:
        *entries = (void *)zero;
skip_clear:
        index++;
        entries++;
    } while (index < 8);
    __AXDSPInitCallback_80134770();
    fn_801378D0();
}
#pragma dont_inline off
#pragma scheduling on

  
  void fn_80134994(void) {
  
  }
  
  void fn_80134998(void) {
      fn_8013BC34();
      fn_80166898();
      fn_80137904();
      fn_8013A1F0();
  }

/* Re-arms the AI cars' proximity records after a restart: for each of the eight
 * "AI::AICarInfo" slots in lbl_8042F758 (allocated by fn_8013477C, one per AI car,
 * holding its car/actor index and a reset flag), resets its entry in the global
 * "Proxer" object lbl_8055E0D4 (fn_80136CB8 = fn_80136D20 update + zero its smoothed
 * values), runs the per-car hook fn_8013A200 (an empty stub) and sets the flag so the
 * next flush (fn_80134A8C) re-initializes that car again. */
void fn_801349C4(void) {
    extern void fn_80136CB8(void *, s32);
    extern void fn_8013A200(s32);
    struct AICarInfo { s32 carIndex; u8 needsReset; };
    struct AICarInfo **slots = (struct AICarInfo **)lbl_8042F758;
    struct AICarInfo *carInfo;
    s32 i = 0;
    do {
        carInfo = *slots;
        if (carInfo != 0) {
            fn_80136CB8(lbl_8055E0D4, carInfo->carIndex);
            fn_8013A200(carInfo->carIndex);
            carInfo->needsReset = 1;
        }
        i++;
        slots++;
    } while (i < 8);
}

extern s32 lbl_8055E3C4;
#pragma dont_inline on
s32 fn_80134A44(s32 arg0) {
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        return (arg0 + lbl_8055E3C4) & 1;
    case -1:
        return lbl_8055E3C4 & 1;
    default:
        return arg0;
    }
}
#pragma dont_inline reset

  
  void fn_80134A88(void) {
  
  }

#pragma scheduling invalid_target
/* Flushes per-entry pending changes: for each active entry in the table, applies
 * the enabled/disabled state transition, clears its flag, notifies by value, then
 * finalizes the owner context and runs end-of-frame updates. */
void fn_80134A8C(void) {
    extern void *lbl_8042F758[];
    extern void *lbl_8055E0D4;
    extern void *lbl_8055E0B0;
      extern void fn_80136CB8(void *, s32);
      extern void fn_80136D20(void *, s32);
    extern s32 fn_80134A44(s32);
    extern void fn_801371E0(void *);
    extern void fn_8013A204(s32);
    extern void fn_8013BC54(void);
    extern void fn_80166A24(void);
    struct Entry { s32 value; u8 flag; };
    struct Entry *entry;
    s32 index;
    struct Entry **entries = (struct Entry **)lbl_8042F758;
    for (index = 0; index < *(s32 *)&lbl_8055E0B0; index++) {
        entry = entries[index];
        if (entry != 0) {
            if (entry->flag != 0)
                fn_80136CB8(lbl_8055E0D4, entry->value);
            else
                fn_80136D20(lbl_8055E0D4, entry->value);
            entry->flag = 0;
            fn_8013A204(entry->value);
        }
    }
    if (fn_80134A44(-1) != 0)
        fn_801371E0(lbl_8055E0D4);
    fn_8013BC54();
    fn_80166A24();
}
#pragma scheduling on
  
  void fn_80134B50(void) {
      extern void *lbl_8055E0D4;
      extern void fn_80136F08(void *);
      fn_80136F08(lbl_8055E0D4);
  }
  
#pragma push
#pragma processor 750
float fn_80134B58(s32 arg0, float arg1)
{
    extern s32 fn_80134B9C(s32, s32);
    extern double atof(void);
    float result = arg1;
    if (fn_80134B9C(arg0, 0) != 0) {
        result = (float)atof();
    }
    return result;
}
#pragma push
#pragma cplusplus on
extern "C" s32 fn_80134B9C(s32 key, s32 defaultValue) {
    struct Dummy {
        virtual s32 f0();
        virtual s32 f1(s32);
        virtual s32 f2();
        virtual s32 f3(s32);
    };
    s32 result;
    /* Look up key via global interface lbl_8055E0AC (f1 tests, f3 retrieves); return defaultValue if unavailable. */
    if (lbl_8055E0AC != 0 && ((Dummy *)lbl_8055E0AC)->f1(key) != 0) {
        result = ((Dummy *)lbl_8055E0AC)->f3(key);
    } else {
        result = defaultValue;
    }
    return result;
}
#pragma cplusplus reset
#pragma pop
  
  f32 fn_80134C1C(void) {
      return lbl_8055E0A8;
  }
  
  s32 fn_80134C24(s32 arg0) {
      extern void *fn_8017960C(void);
      if (arg0 >= 0 && arg0 < 8)
          return *(s32 *)((char *)fn_8017960C() + 0x258);
      return -1;
  }
  
s32 fn_80134C60(s32 arg0, char *arg1)
{
    extern s32 sprintf(char *, const char *, ...);
    extern char *strcpy(char *, const char *);
    extern u8 lbl_80559BDC, lbl_80559BE4, lbl_80559BEC;
    if (arg0 >= 0) {
        sprintf(arg1, (const char *)&lbl_80559BDC, arg0);
    } else if (arg0 != -0x14) {
        strcpy(arg1, (const char *)&lbl_80559BEC);
    } else {
        strcpy(arg1, (const char *)&lbl_80559BE4);
    }
    return (s32)arg1;
}
  
#pragma dont_inline on
s32 fn_80134CD4(s32 arg0, s32 arg1) {
    extern s32 fn_80134C60(s32, char *);
    s32 result;
    if (arg0 >= 0) {
        result = fn_80134C24(arg0);
        fn_80134C60(result, (char *)arg1);
    } else {
        fn_80134C60(-0x28, (char *)arg1);
    }
    return arg1;
}
#pragma dont_inline reset
  f32 fn_80134D20(void) {
      extern f32 lbl_8055E0A0;
      extern f32 lbl_8055E0A4;
      if (fn_801769A8() & 0x800) {
          return lbl_8055E0A4;
      }
      return lbl_8055E0A0;
  }
  
s32 fn_80134D54(void) {
    fn_801769A8();
    return 0;
}

#pragma dont_inline on
f32 fn_80134D78(void) {
    unsigned long temp_r3;
    s32 half;
    f32 value0;
    value0 = (f32)((u32 (*)(void))fn_80134D54)();
    temp_r3 = (s32)lbl_8055E0B0 + 1;
    half = (s32)(((u32)temp_r3 >> 31) + temp_r3) >> 1;
    return lbl_80561304 + (lbl_80560108 * value0) + ((f32)half * lbl_8056010C);
}
#pragma dont_inline reset

#pragma dont_inline on
f32 fn_80134DF8(void) {
    return lbl_80561304;
}
#pragma dont_inline reset

f32 fn_80134E00(void) {
    if ((fn_801769A8() >> 8) & 1) {
        return fn_80134D78();
    }
    return fn_80134DF8();
}

extern f32 fn_80134C1C(void);
extern f32 fn_80134D20(void);
extern f32 fn_80134E00(void);
#pragma dont_inline on
extern void *lbl_8055E0B0;
extern f32 lbl_80560108;
extern f32 lbl_8056010C;
extern f32 lbl_80561304;
extern f64 lbl_80561308;
extern f64 lbl_80561310;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
f32 fn_80134E34(f32 arg0) {
    f32 f30;
    f32 f31;
    if (arg0 < lbl_805612F4) {
        f30 = fn_80134E00();
    } else {
        f30 = arg0;
    }
    f31 = fn_80134C1C();
    return fn_80134D20() - f30 * f31;
}
#pragma scheduling on
#pragma pop
void *fn_80134E90(void) {
    void *p = fn_801284F8(0x30C, lbl_8032BC50);
    if (p != 0) {
        p = fn_801938F4(p);
    }
    return p;
}

#pragma push
#pragma cplusplus on
extern "C" void *fn_80134EC8(s32 arg0)
{
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
        virtual void f26();
        virtual void f27();
        virtual void f28();
        virtual void f29();
        virtual void f30();
        virtual void f31();
        virtual void f32();
        virtual void f33();
        virtual void f34();
        virtual void f35();
        virtual void f36();
        virtual void f37();
        virtual void f38();
        virtual void f39();
        virtual void f40();
        virtual void f41();
        virtual void f42();
        virtual void f43();
        virtual void f44();
        virtual void f45();
        virtual void f46();
        virtual void f47();
        virtual void f48();
        virtual void f49();
        virtual void f50();
        virtual void f51();
        virtual void f52();
        virtual void f53();
        virtual void f54();
        virtual void f55();
        virtual void f56();
        virtual s32 f57();
    };
    void *obj = fn_801B83A0();
    s32 result = ((Dummy *)obj)->f57();
    if (result == 0) {
        switch (arg0) {
        case 0x180201:
            return fn_80134E90();
        default:
            fn_802E30C8(lbl_8032BC5C, (void *)arg0);
            return fn_80134FF8();
        }
    }
    return (void *)result;
}
#pragma cplusplus reset
#pragma pop
s32 fn_80134F40(void) {
    return 0;
}

// Select an AX/effect factory implementation from global state/config, then allocate and construct an object with it.
void *fn_80134F48(void) {
    void *factory = __AXFXGetLfoSinTable_801769CC();
    s32 useAltFactory = 0;
    void *result;
    u32 bits;
    if (*((u8*)fn_801792F8() + 0xD8) & 4) useAltFactory = 1;
    if (useAltFactory) factory = fn_801350C0();
    else {
        bits = *((u32*)factory + 1);
        if (bits & 0x100) factory = fn_80134E90();
        else if (bits & 0x200) factory = ((void *(*)(s32))fn_80134EC8)(bits);
        else factory = fn_80134FF8();
    }
    {
        register const void *name = lbl_8032BC84;
        register u32 id = 0x2844;
        result = fn_801284F8(id, name);
    }
    if (result != 0) result = fn_801A520C(result, factory);
    return result;
}
#pragma scheduling invalid_target
void *fn_80134FF8(void) {
    void **p = fn_801284F8(4, lbl_8032BC94);
    if (p != 0) {
        *p = (void*)lbl_8032BD08;
    }
    return p;
}
#pragma scheduling on
s32 fn_80135038(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_80135078(void) {
    void *p = fn_801284F8(12, lbl_8032BCA0);
    if (p != 0) {
        *(const void**)p = lbl_8032BCC0;
        *((u8*)p + 4) = 0;
    }
    return p;
}

void *fn_801350C0(void) {
    void *p = fn_801284F8(12, lbl_8032BCA0);
    if (p != 0) {
        *(const void**)p = lbl_8032BCC0;
        *((u8*)p + 4) = 1;
    }
    return p;
}

void* fn_80135108(void) {
    return lbl_8055E0B0;
}

s32 fn_80135110(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80135150(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80135190(void) {

}

void fn_80135194(void) {

}

void fn_80135198(void) {

}

#pragma scheduling invalid_target
int fn_8013519C(void) {
    return fn_802E317C(lbl_8032BD98);
}
extern const char lbl_8032BD98[];
extern s32 fn_802E317C(const char *, ...);
s32 fn_801351AC(void) {
    return 0;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801351B4(void* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
    };
    ((Dummy*)obj)->f2();
}
#pragma cplusplus reset
#pragma pop
void fn_801351C4(void *arg0, s32 arg1) {
    ((s32 *)arg0)[2] = arg1;
}

extern void fn_8018ADBC(void *, f32);
extern void fn_8018ADB4(void *, f32);
extern void fn_8018ADA4(void *, f32);
#pragma push
#pragma processor 750
#pragma peephole off
#pragma scheduling invalid_target
void fn_801351CC(void *arg0) {
    f32 first = *(volatile f32 *)&lbl_80561318;
    fn_8018ADBC(*(void **)((u8 *)arg0 + 8), first);
    fn_8018ADB4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
    fn_8018ADA4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
}
#pragma pop
void fn_80135218(void) {

}


s32 fn_8013521C(void *arg0) {
    u8 temp_r3;

    temp_r3 = *(u8 *)((u8 *)arg0 + 4);
    return ((s32)(-(s32)temp_r3 | temp_r3) >> 0x1F) & 0x100;
}

s32 fn_80135234(void) {
    return 0;
}

void fn_8013523C(void *arg0, void *arg1, void *arg2, s32 *arg3, s32 *arg4) {
    *arg4 = 0;
    *arg3 = 0;
}

s32 fn_8013524C(void) {
    return 0;
}

void fn_80135254(void) {

}

void fn_80135258(void) {

}

void fn_8013525C(void) {

}

void fn_80135260(void) {

}

void fn_80135264(void) {

}

void fn_80135268(void) {

}

void fn_8013526C(void) {

}

