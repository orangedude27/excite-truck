#include <types.h>

extern void *fn_801284F8(u32, const void *);
extern f32 lbl_8055E0A8;
extern f32 lbl_80561304;
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
  extern void *fn_80134EC8(void);
  extern void *fn_80134FF8(void);
  extern void *fn_801350C0(void);
  extern void *fn_801A520C(void *, void *);
  extern void *fn_801B83A0(void);
  extern void fn_801938F4(void);
  extern void fn_802E30C8(const char *, void *);
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
  
  void fn_8013472C(void) {
      void *obj = fn_8001285C(*fn_801E87A8());
      void *sub = *(void **)((u8 *)obj + 0x20);
      u32 entry = *(u32 *)((u8 *)*(void **)sub + 0x5c);
      lbl_8055E0AC = (void *)((s32 (*)(void *, u32 *))entry)(sub, &lbl_80559BD8);
  }
  
  void __AXDSPInitCallback_80134770(void) {
      lbl_8055E0AC = 0;
  }
  
  void fn_80134994(void) {
  
  }
  
  void fn_80134998(void) {
      fn_8013BC34();
      fn_80166898();
      fn_80137904();
      fn_8013A1F0();
  }
  
  void fn_80134A88(void) {
  
  }
  
  void fn_80134B50(void) {
      extern void *lbl_8055E0D4;
      extern void fn_80136F08(void *);
      fn_80136F08(lbl_8055E0D4);
  }
  
  float fn_80134B58(float arg0) {
      extern s32 fn_80134B9C(float, s32);
      extern double atof(void);
      if (fn_80134B9C(arg0, 0) != 0)
          arg0 = (float)atof();
      return arg0;
  }
  
  f32 fn_80134C1C(void) {
      return lbl_8055E0A8;
  }
  
  s32 fn_80134C24(s32 arg0) {
      extern void *fn_8017960C(void);
      if (arg0 >= 0 && arg0 < 8)
          return *(s32 *)((char *)fn_8017960C() + 0x258);
      return -1;
  }
  
  s32 fn_80134C60(s32 arg0, char *arg1) {
      extern s32 sprintf(char *, const char *, ...);
      extern char *strcpy(char *, const char *);
      extern u8 lbl_80559BDC;
      extern u8 lbl_80559BE4;
      extern u8 lbl_80559BEC;
      if (arg0 >= 0) {
          sprintf(arg1, (const char *)&lbl_80559BDC, arg0);
      } else if (arg0 == -0x14) {
          strcpy(arg1, (const char *)&lbl_80559BE4);
      } else {
          strcpy(arg1, (const char *)&lbl_80559BEC);
      }
      return (s32)arg1;
  }
  
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
extern void *lbl_8055E0B0;
extern f32 lbl_80560108;
extern f32 lbl_8056010C;
extern f32 lbl_80561304;
extern f64 lbl_80561308;
extern f64 lbl_80561310;
f32 fn_80134E34(f32 arg0) {
    f32 f30;
    f32 f31;
    if (arg0 < lbl_805612F4) {
        f30 = fn_80134E00();
    } else {
        f30 = arg0;
    }
    f31 = fn_80134C1C();
    fn_80134D20();
    return arg0 - f30 * f31;
}

void *fn_80134E90(void) {
    void *p = fn_801284F8(0x30C, lbl_8032BC50);
    if (p != 0) {
        fn_801938F4();
    }
    return p;
}

void *fn_80134EC8(void) {
    void *obj = fn_801B83A0();
    void *tbl = *(void **)((u8 *)obj + 0x0);
    s32 (*fn)(void) = *(s32 (**)(void))((u8 *)tbl + 0xEC);
    if (fn() != 0) {
        fn_80134E90();
    } else {
        fn_802E30C8(lbl_8032BC5C, obj);
        fn_80134FF8();
    }
    return obj;
}

s32 fn_80134F40(void) {
    return 0;
}

void *fn_80134F48(void) {
    void *p = __AXFXGetLfoSinTable_801769CC();
    s32 flag = 0;
    void *result;
    u32 bits;
    if (*((u8*)fn_801792F8() + 0xD8) & 4) { flag = 1; }
    if (flag) { p = fn_801350C0(); }
    else {
        bits = *((u32*)p + 1);
        if (bits & 0x100) { p = fn_80134E90(); }
        else if (bits & 0x200) { p = fn_80134EC8(); }
        else { p = fn_80134FF8(); }
    }
    result = fn_801284F8(0x2844, lbl_8032BC84);
    if (result != 0) { result = fn_801A520C(result, p); }
    return result;
}
#pragma scheduling off
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

s32 fn_8013519C(s32 arg0) {
    return fn_802E317C(lbl_8032BD98, arg0);
}

extern const char lbl_8032BD98[];
extern s32 fn_802E317C(const char *, ...);
s32 fn_801351AC(void) {
    return 0;
}

void fn_801351B4(void *param) {
    register void **vtable = *(void ***)param;
    register void (*fn)(void) = *(void (**)(void))((u8 *)vtable + 0x10);
    fn();
}

void fn_801351C4(void *arg0, s32 arg1) {
    ((s32 *)arg0)[2] = arg1;
}

extern void fn_8018ADBC(void *, f32);
extern void fn_8018ADB4(void *, f32);
extern void fn_8018ADA4(void *, f32);
void fn_801351CC(void *arg0) {
    fn_8018ADBC(*(void **)((u8 *)arg0 + 8), lbl_80561318);
    fn_8018ADB4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
    fn_8018ADA4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
}

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

