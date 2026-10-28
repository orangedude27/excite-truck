// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern float lbl_80563B88;
extern void fn_80214A9C(s32);
extern void fn_80214AF0(s32);
extern void fn_80230E90(s32);
extern void fn_80236914(void);
extern u8 lbl_8055F3E9;
extern u8 lbl_8055F3EA;
extern u8 lbl_8055F3EB;
#pragma push
#pragma small_data on
extern u8 *lbl_8055F420;
#pragma pop
extern u8 lbl_8055BAC0;
extern u8 lbl_8055BAB8;
extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
#pragma push
#pragma small_data off
extern u8 lbl_80345EA0[];
extern u8 lbl_80345E28[];
#pragma pop
extern u8 lbl_8055F3EC;
s32 fn_8025FE8C(void) {
    void *temp_r4;
    if ((s32)lbl_8055F3E9 != 0 && (s32)lbl_8055F3EC == 0) {
        temp_r4 = *(void **)(lbl_8055F420 + 0x14);
        *(u8 *)((u8 *)temp_r4 + 0x49) = 1;
        *(u8 *)((u8 *)temp_r4 + 0x4B) = 0;
        *(u8 *)((u8 *)temp_r4 + 0x4A) = 0;
        lbl_8055F3EC = 1;
    }
    return 0;
}

extern void fn_800167FC(s32);
extern void *fn_80012820(s32);
extern void *fn_8025007C(s32);
extern s32 fn_8024DAE0(s32,s32,s32,void*,s32);
extern void fn_802E317C(void *, ...);
extern s32 lbl_8055C400;
#pragma push
#pragma small_data off
extern u8 lbl_80345B40[];
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8025FECC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Inner3 {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual s32 vfunc_18(const void*, s32);
    };

    struct Inner2 {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual Inner3* vfunc_5c(const void*);
    };

    struct Obj {
        u8 pad[0x80];
        Inner2* inner;
    };

    struct Handle {
        virtual ~Handle();
        virtual void vfunc_0c(s32, s32, s32);
    };

    const char* base = (const char*)lbl_80345B40;
    if (lbl_8055C400 >= 0) {
        return 1;
    }

    fn_800167FC(1);
    Obj* obj = (Obj*)fn_80012820(arg2);
    s32 val = 0;
    s32 check;
    if (obj != 0 && obj->inner != 0 && (check = (s32)obj->inner->vfunc_5c(base + 0x90), ((u32)(-check | check) >> 31) != 0)) {
        val = obj->inner->vfunc_5c(base + 0x90)->vfunc_18(base + 0xa0, 0);
    } else {
        fn_802E317C((void*)(base + 0xb0));
    }

    Handle* handle = 0;
    if (val != 0) {
        handle = (Handle*)fn_8025007C(1);
        handle->vfunc_0c(val, 1, 0);
    } else {
        fn_802E317C((void*)(base + 0x104));
    }

    s32 ret = fn_8024DAE0(arg0, arg1, 0, handle, arg3);
    delete handle;
    return ret;
}
#pragma pop
void fn_802607C4(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 1;
}

void fn_802607D0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1E) = 1;
}

void fn_802607DC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
}

void fn_802607EC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 0;
}

void fn_802607F8(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1C) == 0) {
        *(u8 *)((u8 *)arg0 + 0x1C) = 1;
        *(u8 *)((u8 *)arg0 + 0x1F) = 1;
    }
}

void fn_80260814(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 0;
}

void fn_80260820(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1C) == 0) {
        *(u8 *)((u8 *)arg0 + 0x1E) = 1;
        *(u8 *)((u8 *)arg0 + 0x1C) = 1;
    }
}

void fn_8026083C(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1C) = 0;
}

void fn_80260848(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x1D) = 1;
}

#pragma push
#pragma small_data off
void *fn_80260854(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80345E28;
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x24), (s32 *)lbl_80345E28);
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        fn_802328D4(*(s32 *)((u8 *)arg0 + 0x28));
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
extern s32 fn_80128668(void);
extern s32 fn_802328D4(s32);
extern s32 fn_80235380(s32, s32 *);
#pragma push
#pragma small_data off
void *fn_802608D4(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80345EA0;
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x20), (s32 *)&lbl_80345EA0);
        *(s32 *)((u8 *)arg0 + 0x20) = 0;
        fn_802328D4(*(s32 *)((u8 *)arg0 + 0x24));
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern void *lbl_8055F3E4;
extern u8 lbl_8055F3E8;
extern s32 lbl_802FA6C0[];
extern u8 lbl_80498F00;
extern s32 fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(s32);
extern void *fn_8027B878(s32);
extern void fn_8026003C(void);
extern s32 fn_802146BC(s32 *, s32, s32, s32);
extern s32 fn_80261948(s32 *);
extern s32 fn_802619A0(s32 *);
extern s32 fn_802619D8(s32 *, s32);
extern s32 fn_80261A08(s32 *, s32);
extern void fn_802619E8(void *, s32, s32);
extern void fn_80261980(void *, s32, s32, s32);
extern void fn_80261A18(void *, s32);
extern void fn_80261A7C(void *, s32);
extern void fn_80261AE8(s32 *, s32);
extern void fn_80261AF0(s32 *, s32);
extern void fn_80261C68(s32 *);
extern void fn_80262120(void *);
extern void fn_8026213C(void *);
extern void fn_80261688(void *, s32, s32, s32);
extern void fn_80260E04(s32 *, s32 *);
extern void fn_80261AA0(void);
extern void fn_80261A40(s32);
extern s32 fn_802616A8(void);
extern s32 fn_802613E0(void);
extern s32 fn_80261178(void *);
extern s32 fn_802610C8(void);
extern s32 fn_80260E30(void);
#pragma push
#pragma small_data on
#pragma pop
#pragma push
#pragma small_data off
#pragma pop
extern s32 table[];
#pragma push
#pragma small_data on
#pragma pop
#pragma push
#pragma small_data off
#pragma pop
#pragma cplusplus on
extern "C" s32 fn_80260DC4(s32, s32);
extern "C" void fn_80260954(s32 arg0) {
    struct Dummy { virtual void destroy(s32); };
          typedef struct {
              s32 word[5];
          } Obj20;
          typedef struct {
              s32 header[6];
              s32 bufA[9];
              s32 bufB[15];
              Obj20 objects[19];
          } Frame;
      
          Frame frame;
        s32 *header;
       s32 value;
          s32 sp8;
          s32 args[5];
          s32 initialMode;
          s32 currentMode;
          s32 result;
          s32 i;
          s32 offset;
          u8 *stringBase = (u8 *)&lbl_80345B40;
          void *object;
          
          header = frame.header;
        initialMode = fn_80012810();
          if (initialMode != 0x130) {
              if (initialMode != 0x134) {
                  fn_80012794();
              }
              fn_80012790(0x130);
          }
          lbl_8055F3E4 = fn_8027B878(arg0);
          fn_8026213C(frame.bufA);
          fn_80262120(frame.bufB);
          *(void **)&lbl_8055F420 = &header[0];
          header[4] = arg0;
          header[1] = 0;
          header[0] = 0;
          header[5] = 0;
          fn_80261C68(header);
      
      loop_6:
          fn_8026003C();
          if (lbl_8055F3E8 != 0) {
              fn_80261AF0(header, header[4] + 1);
              lbl_8055F3E8 = 0;
              if (header[4] == 0) {
                  lbl_8055F3EB = 0;
                  result = -1;
                  goto loop_end;
              }
          }
      
          fn_80261AE8(&sp8, header[4]);
          fn_80261A7C(&frame.objects[0], (s32)fn_80261AA0);
          fn_80261A18(&frame.objects[1], (s32)fn_80261A40);
      
          value = *(s32 *)(u32)fn_80261A08(frame.bufB, 0);
           fn_802619E8(&frame.objects[2], (s32)(stringBase + 0x1B8), value);
          value = *(s32 *)(u32)fn_80261A08(frame.bufB, 1);
           fn_802619E8(&frame.objects[3], (s32)(stringBase + 0x1C8), value);
          value = *(s32 *)(u32)fn_80261A08(frame.bufB, 2);
           fn_802619E8(&frame.objects[4], (s32)(stringBase + 0x1D8), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 0);
           fn_802619E8(&frame.objects[5], (s32)(stringBase + 0x1E8), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 1);
           fn_802619E8(&frame.objects[6], (s32)(stringBase + 0x1F8), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 2);
           fn_802619E8(&frame.objects[7], (s32)(stringBase + 0x208), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 3);
           fn_802619E8(&frame.objects[8], (s32)(stringBase + 0x218), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 4);
           fn_802619E8(&frame.objects[9], (s32)(stringBase + 0x228), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 5);
           fn_802619E8(&frame.objects[10], (s32)(stringBase + 0x238), value);
          fn_80261980(&frame.objects[11], (s32)(stringBase + 0x248),
                      fn_802619A0(&sp8), 0);
          fn_80261980(&frame.objects[12], (s32)(stringBase + 0x258),
                      fn_80261948(&sp8), 0);
          fn_80261688(&frame.objects[13], 0x126, 0, (s32)fn_802616A8);
          fn_80261688(&frame.objects[14], 0x128, 0, (s32)fn_802613E0);
          fn_80261688(&frame.objects[15], 0xD, -2, (s32)fn_80261178);
          fn_80261688(&frame.objects[16], 0x121, 0, (s32)fn_802610C8);
          fn_80261688(&frame.objects[17], 0x1B, -1, (s32)fn_80260E30);
          fn_80260E04((s32 *)&frame.objects[18], (s32 *)&lbl_80498F00);
      
          args[0] = lbl_802FA6C0[0];
          args[1] = lbl_802FA6C0[1];
          args[2] = lbl_802FA6C0[2];
          args[3] = lbl_802FA6C0[3];
          args[4] = lbl_802FA6C0[4];
          args[1] = (s32)header;
      
      loop_10:
         result = fn_802146BC(args, -0x3E7, -0x3E7, 1);
         if (result == -1) {
             goto result_minus_one;
         }
         if (result >= 0) {
             goto result_retry;
         }
         if (result >= -2) {
             goto result_minus_two;
         }
         goto result_retry;
 
     result_retry:
         fn_802E317C(stringBase + 0x268);
         goto loop_10;
 
     result_minus_two:
         fn_80260DC4((s32)&sp8, -1);
         result = -2;
         goto result_done;
 
     result_minus_one:
         fn_80260DC4((s32)&sp8, -1);
         result = -1;
         goto result_done;
 
     result_done:
     loop_end:
          if (result != -1) {
              goto loop_6;
          }
      
          *(void **)&lbl_8055F420 = 0;
          if (header[5] != 0) {
              if (header[5] != 0) {
                  object = (void *)header[5];
                                  ((Dummy *)object)->destroy(1);
              }
              header[5] = 0;
          }
          lbl_8055F3EC = 0;
      
          for (i = 0, offset = 0; i < header[2]; offset += 4, i++) {
              object = *(void **)((u8 *)(u32)frame.bufA[0] + offset);
              if (object != 0) {
                                  ((Dummy *)object)->destroy(1);
              }
          }
          for (i = 0, offset = 0; i < header[3]; offset += 4, i++) {
              object = *(void **)((u8 *)(u32)frame.bufB[0] + offset);
              if (object != 0) {
                                  ((Dummy *)object)->destroy(1);
              }
          }
      
          frame.bufB[0] = 0;
          frame.bufB[1] = 0;
          frame.bufB[2] = 0;
          frame.bufA[0] = 0;
          frame.bufA[1] = 0;
          frame.bufA[2] = 0;
      
          currentMode = fn_80012810();
          if (initialMode != currentMode) {
              if (currentMode != 0x134) {
                  fn_80012794();
              }
              if (initialMode != 0x134) {
                  fn_80012790(initialMode);
              }
          }
      }
#pragma cplusplus reset
#pragma cplusplus reset
s32 fn_80260DC4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80260E04(s32 *arg0, s32 *arg1) {
    s32 e;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    e = arg1[4];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
    arg0[4] = e;
}

s32 fn_80260E30(void) {
    s32 i, j, count;
    void *obj;
    u32 *base = (u32 *)lbl_8055F420;
    if (!lbl_8055F3EB)
        return 1;
    lbl_8055F3EB = 0;
    for (i = 0, j = 0; i < (s32)base[3]; i++, j += 4) {
        obj = *(void **)((u8 *)base[0xF] + j);
        ((void (*)(void *))(*(u32 *)*(void **)obj + 0x6C))(obj);
    }
    for (i = 0, j = 0; i < (s32)base[2]; i++, j += 4) {
        if (!lbl_8055F3EB) {
            obj = *(void **)((u8 *)base[6] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x60))(obj);
            obj = *(void **)((u8 *)base[6] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x6C))(obj);
        } else if (i == (s32)base[0]) {
            obj = *(void **)((u8 *)base[6] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x68))(obj);
        } else if (i == (s32)(base[1] * 2) || i == (s32)(base[1] * 2 + 1)) {
            obj = *(void **)((u8 *)base[6] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x64))(obj);
            obj = *(void **)((u8 *)base[6] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x6C))(obj);
        } else {
            obj = *(void **)((u8 *)base[6] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x6C))(obj);
        }
    }
    for (i = 0, j = 0; i < (s32)base[3]; i++, j += 4) {
        if (!lbl_8055F3EB) {
            if (i == (s32)base[1]) {
                obj = *(void **)((u8 *)base[0xF] + j);
                ((void (*)(void *))(*(u32 *)*(void **)obj + 0x68))(obj);
            } else {
                obj = *(void **)((u8 *)base[0xF] + j);
                ((void (*)(void *))(*(u32 *)*(void **)obj + 0x64))(obj);
                obj = *(void **)((u8 *)base[0xF] + j);
                ((void (*)(void *))(*(u32 *)*(void **)obj + 0x6C))(obj);
            }
        } else if (i == (s32)base[1]) {
            obj = *(void **)((u8 *)base[0xF] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x68))(obj);
            obj = *(void **)((u8 *)base[0xF] + j);
            count = base[1] * 4;
            obj = *(void **)((u8 *)base[0xF] + count);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x70))(obj);
        } else {
            obj = *(void **)((u8 *)base[0xF] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x60))(obj);
            obj = *(void **)((u8 *)base[0xF] + j);
            ((void (*)(void *))(*(u32 *)*(void **)obj + 0x6C))(obj);
        }
    }
    return 0;
}

s32 fn_802610C8(void) {
    s32 result = 0;
    u32 *base;
    void *object;
    void **vtable;
    if (lbl_8055F3EB != 0) {
        lbl_8055F3EA = 1;
        fn_80214A9C(30);
        base = (u32 *)lbl_8055F420;
        object = *(void **)(base + base[0] + 0x18);
        vtable = *(void ***)object;
        result = ((s32 (*)(void *))vtable[9])(object);
        base = (u32 *)lbl_8055F420;
        object = *(void **)(base + base[0] + 0x18);
        vtable = *(void ***)object;
        ((void (*)(void *, u32 *))vtable[8])(object, base);
        fn_8025C204(result);
        fn_80214AF0(30);
        fn_80230E90(0);
        lbl_8055F3EA = 0;
    }
    return 0;
}

s32 fn_80261178(void *arg0) {
    s32 i = 0;
    s32 offset = 0;
    u32 *base;
    void *obj;
    void **vt;
    if (lbl_8055F3EB != 0) return 1;
    lbl_8055F3EB = 1;
    base = (u32 *)lbl_8055F420;
    base[0] = base[1] * 2;
    for (i = 0; i < (s32)base[2]; i++, offset += 4) {
        obj = *(void **)((u8 *)arg0 + 0x18 + offset);
        vt = *(void ***)obj;
        ((void (*)(void *))vt[0x60/4])(obj);
        obj = *(void **)((u8 *)base + 0x18 + offset);
        vt = *(void ***)obj;
        ((void (*)(void *))vt[0x6c/4])(obj);
    }
    i = 0; offset = 0;
    for (; i < (s32)base[3]; i++, offset += 4) {
        obj = *(void **)((u8 *)base + 0x3c + offset);
        vt = *(void ***)obj;
        ((void (*)(void *))vt[0x64/4])(obj);
        obj = *(void **)((u8 *)base + 0x3c + offset);
        vt = *(void ***)obj;
        ((void (*)(void *))vt[0x6c/4])(obj);
    }
    return 0;
}

s32 fn_802613E0(void) {
    s32 j, i, count;
    volatile u32 *base = (volatile u32 *)lbl_8055F420;
    void *obj; void **vt;
    if (!lbl_8055F3EB) {
        base[1]++;
        if ((s32)base[1] >= (s32)base[3]) base[1] = base[3] - 1;
    } else {
        base[0]++;
        count = base[1] * 2 + 1;
        if ((s32)base[0] > count) base[0] = count;
    }
    for (i=0,j=0;i<(s32)base[2];i++,j+=4) {
        if (!lbl_8055F3EB) {
            obj=*(void **)(base[6]+j); vt=*(void ***)obj; ((void(*)(void*))vt[24])(obj);
            obj=*(void **)(base[6]+j); vt=*(void ***)obj; ((void(*)(void*))vt[27])(obj);
        } else if(i==(s32)base[0]) {
            obj=*(void **)(base[6]+j); vt=*(void ***)obj; ((void(*)(void*))vt[26])(obj);
        } else if(i==(s32)(base[1]*2)||i==(s32)(base[1]*2+1)) {
            obj=*(void **)(base[6]+j); vt=*(void ***)obj; ((void(*)(void*))vt[25])(obj);
            obj=*(void **)(base[6]+j); vt=*(void ***)obj; ((void(*)(void*))vt[27])(obj);
        } else { obj=*(void **)(base[6]+j); vt=*(void ***)obj; ((void(*)(void*))vt[27])(obj); }
    }
    for(i=0,j=0;i<(s32)base[3];i++,j+=4) {
        if(!lbl_8055F3EB) {
            if(i==(s32)base[1]) { obj=*(void **)(base[0xF]+j); vt=*(void ***)obj; ((void(*)(void*))vt[26])(obj); }
            else { obj=*(void **)(base[0xF]+j); vt=*(void ***)obj; ((void(*)(void*))vt[25])(obj); obj=*(void **)(base[0xF]+j); vt=*(void ***)obj; ((void(*)(void*))vt[27])(obj); }
        } else if(i==(s32)base[1]) {
            obj=*(void **)(base[0xF]+j); vt=*(void ***)obj; ((void(*)(void*))vt[26])(obj);
            count=base[1]*4; obj=*(void **)(base[0xF]+count); vt=*(void ***)obj; ((void(*)(void*))vt[28])(obj);
        } else { obj=*(void **)(base[0xF]+j); vt=*(void ***)obj; ((void(*)(void*))vt[24])(obj); obj=*(void **)(base[0xF]+j); vt=*(void ***)obj; ((void(*)(void*))vt[27])(obj); }
    }
    return 0;
}

extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
#pragma push
#pragma scheduling invalid_target
void fn_80261688(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p = (s32 *)arg0;
    p[2] = arg3;
    p[1] = 6;
    p[0] = (s32)&lbl_8055B860;
    p[3] = arg2;
    p[4] = arg1;
}
#pragma pop
s32 fn_802616A8(void) {
    s32 j, i;
    s32 count;
    u32 *base = (u32 *)lbl_8055F420;
    void *obj;
    void **vt;
    if (!lbl_8055F3EB) {
        base[1] = base[1] - 1;
        if ((s32)base[1] < 0) base[1] = 0;
    } else {
        base[0] = base[0] - 1;
        count = base[1] * 2;
        if ((s32)base[0] < count) base[0] = count;
    }
    for (i = 0, j = 0; i < (s32)base[2]; i++, j += 4) {
        if (!lbl_8055F3EB) {
            obj = *(void **)((u8 *)base[6] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x60/4])(obj);
            obj = *(void **)((u8 *)base[6] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x6c/4])(obj);
        } else if (i == (s32)base[0]) {
            obj = *(void **)((u8 *)base[6] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x68/4])(obj);
        } else if (i == (s32)(base[1] * 2) || i == (s32)(base[1] * 2 + 1)) {
            obj = *(void **)((u8 *)base[6] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x64/4])(obj);
            obj = *(void **)((u8 *)base[6] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x6c/4])(obj);
        } else {
            obj = *(void **)((u8 *)base[6] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x6c/4])(obj);
        }
    }
    for (i = 0, j = 0; i < (s32)base[3]; i++, j += 4) {
        if (!lbl_8055F3EB) {
            if (i == (s32)base[1]) {
                obj = *(void **)((u8 *)base[0xF] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x68/4])(obj);
            } else {
                obj = *(void **)((u8 *)base[0xF] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x64/4])(obj);
                obj = *(void **)((u8 *)base[0xF] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x6c/4])(obj);
            }
        } else if (i == (s32)base[1]) {
            obj = *(void **)((u8 *)base[0xF] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x68/4])(obj);
            count = base[1] * 4;
            obj = *(void **)((u8 *)base[0xF] + count); vt = *(void ***)obj; ((void (*)(void *))vt[0x70/4])(obj);
        } else {
            obj = *(void **)((u8 *)base[0xF] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x60/4])(obj);
            obj = *(void **)((u8 *)base[0xF] + j); vt = *(void ***)obj; ((void (*)(void *))vt[0x6c/4])(obj);
        }
    }
    return 0;
}

s32 fn_80261948(s32 *arg0) {
    s32 *p = lbl_802FA6A8;
    s32 values[3];
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[*arg0];
}

#pragma scheduling invalid_target
void fn_80261980(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 zero;
    *(s32 *)arg0 = arg1;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 4) = 3;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0xC) = arg3;
    *(s32 *)((u8 *)arg0 + 0x10) = zero;
}
#pragma scheduling on
extern s32 lbl_802FA6B4[];
s32 fn_802619A0(s32 *arg0) {
    s32 *p = lbl_802FA6B4;
    s32 values[3];
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[*arg0];
}

s32 fn_802619D8(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

void fn_802619E8(void *arg0, s32 arg1, s32 arg2) {
    s32 zero = 0;
    *(s32 *)arg0 = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 5;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0xC) = zero;
    *(s32 *)((u8 *)arg0 + 0x10) = zero;
}

s32 fn_80261A08(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

void fn_80261A18(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAB8;
    *(s32 *)((u8 *)arg0 + 0xC) = 2;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261A40(s32 arg0) {
    fn_80236914();
    if (arg0 == 2) {
        lbl_8055F3E9 = 1;
    } else {
        lbl_8055F3E9 = 0;
    }
}

void fn_80261A7C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAC0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261AA0(void) {
    s32 i;
    i = 0;
    goto check;
loop:
    fn_80214A9C(i + 10);
    i++;
check:
    if (i < *(s32 *)(lbl_8055F420 + 0xC)) goto loop;
}

extern void fn_801345D8(char *, s32, const char *, ...);
extern s32 fn_80131234(const void *);
#pragma push
#pragma small_data off
extern char lbl_80345DE0[];
extern char lbl_80345E0C[];
extern u8 lbl_80498F20;
extern s32 lbl_802FA6D4[];
#pragma pop
#pragma push
#pragma small_data on
extern u8 lbl_8055C418;
extern u8 lbl_8055C420;
#pragma pop

void fn_80261AE8(s32 *arg0, s32 arg1) { *arg0 = arg1; }

#pragma cplusplus on
extern "C" void *fn_801284F8(s32, void *);
extern "C" void *fn_80207848(void *, s32);
extern "C" void *fn_8023512C(void *);
extern "C" void *fn_80232578(void *);
extern "C" void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
extern "C" void fn_80261C68(s32 *arg0) {
    struct Dummy {
        virtual void slot0();
        virtual s32 slot1();
        virtual void *slot2(s32);
        virtual void slot3();
        virtual s32 slot4();
        virtual void *slot5(s32);
        virtual void slot6();
        virtual void slot7();
        virtual void slot8();
        virtual void slot9();
        virtual void slot10();
        virtual void slot11();
        virtual void slot12();
        virtual void slot13();
        virtual void slot14();
        virtual void slot15();
        virtual void slot16();
        virtual void slot17();
        virtual void slot18();
        virtual void slot19();
        virtual void slot20();
        virtual void slot21();
        virtual void slot22();
        virtual void slot23();
        virtual void slot24();
        virtual void slot25();
        virtual void slot26();
    };
    u8 *stringBase;
    u8 *group;
    s32 outer;
    s32 inner;
    s32 i;
    u32 j;
    s32 count;
    s32 max;
    void *object;
    void *item;
    float targetValue;
    u32 *base;

    stringBase = (u8 *)&lbl_80345B40;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = ((Dummy *)lbl_8055F3E4)->slot1();
    memset((u8 *)arg0 + 0x60, 0, 0x18);
    memset((u8 *)arg0 + 0x54, 0, 0xC);
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0x40) = 0;
    group = (u8 *)arg0;
    outer = 0;
    goto outerCheck;
outerBody:
    *(void **)(group + 0x54) = ((Dummy *)lbl_8055F3E4)->slot2(outer);
    object = fn_801284F8(0x2C, stringBase + 0x144);
    if (object != 0) {
        item = ((Dummy *)lbl_8055F3E4)->slot2(outer);
        *(s32 *)((u8 *)object + 0x14) = 0;
        *(void **)object = lbl_80345E28;
        *(s32 *)((u8 *)object + 0x20) = outer;
        *(void **)((u8 *)object + 0x18) = item;
        *(u8 *)((u8 *)object + 0x1C) = 0;
        *(u8 *)((u8 *)object + 0x1D) = 1;
        *(u8 *)((u8 *)object + 0x1E) = 0;
        *(u8 *)((u8 *)object + 0x1F) = 0;
        *(void **)((u8 *)object + 0x24) = fn_8023512C(stringBase + 0x150);
        *(void **)((u8 *)object + 0x28) = fn_80232578(stringBase + 0x15C);
    }
    {
        u32 *array = *(u32 **)((u8 *)arg0 + 0x3C);
        count = *(s32 *)((u8 *)arg0 + 0x40);
        *(s32 *)((u8 *)arg0 + 0x40) = count + 1;
        array[count] = (u32)object;
    }
    inner = 0;
    goto innerCheck;
innerBody:
    item = ((Dummy *)*(void **)(group + 0x54))->slot5(inner);
    count = *(s32 *)((u8 *)arg0 + 8);
    ((u32 *)arg0 + count)[0x18] = (u32)item;
    item = fn_801284F8(0x28, stringBase + 0x168);
    if (item != 0) {
        object = ((Dummy *)lbl_8055F3E4)->slot2(outer);
        object = ((Dummy *)object)->slot5(inner);
        *(s32 *)((u8 *)item + 0x14) = 0;
        *(void **)item = lbl_80345EA0;
        *(void **)((u8 *)item + 0x18) = object;
        *(u8 *)((u8 *)item + 0x1E) = 0;
        *(u8 *)((u8 *)item + 0x1C) = 0;
        *(u8 *)((u8 *)item + 0x1D) = 1;
        *(void **)((u8 *)item + 0x20) = fn_8023512C(stringBase + 0x150);
        *(void **)((u8 *)item + 0x24) = fn_80232578(stringBase + 0x15C);
    }
    {
        u32 *array = *(u32 **)((u8 *)arg0 + 0x18);
        count = *(s32 *)((u8 *)arg0 + 0x1C);
        *(s32 *)((u8 *)arg0 + 0x1C) = count + 1;
        array[count] = (u32)item;
    }
    inner++;
    *(s32 *)((u8 *)arg0 + 8) += 1;
innerCheck:
    count = ((Dummy *)*(void **)(group + 0x54))->slot4();
    max = 6;
    if (count < 6) max = count;
    if (inner < max) goto innerBody;
    group += 4;
    outer++;
outerCheck:
    count = ((Dummy *)lbl_8055F3E4)->slot1();
    max = 3;
    if (count < 3) max = count;
    if (outer < max) goto outerBody;

    object = fn_80207848(stringBase + 0x178, 0);
    *(void **)((u8 *)arg0 + 0x14) = object;
    if (object != 0) {
        targetValue = lbl_80563B88;
        if (targetValue != *(float *)((u8 *)object + 8)) {
            *(u8 *)((u8 *)object + 0x4D) = 1;
            *(float *)((u8 *)object + 8) = targetValue;
        }
    } else {
        fn_802E317C(stringBase + 0x188);
    }

    i = 0;
    j = 0;
    goto firstCheck;
firstBody:
    if (lbl_8055F3EB == 0) {
        object = *(void **)((u8 *)base[6] + j);
        ((Dummy *)object)->slot22();
        object = *(void **)((u8 *)(*(u32 **)&lbl_8055F420)[6] + j);
        ((Dummy *)object)->slot25();
    } else if (i == (s32)base[0]) {
        object = *(void **)((u8 *)base[6] + j);
        ((Dummy *)object)->slot24();
    } else if (i == (s32)base[1] * 2 || i == (s32)base[1] * 2 + 1) {
        object = *(void **)((u8 *)base[6] + j);
        ((Dummy *)object)->slot23();
        object = *(void **)((u8 *)(*(u32 **)&lbl_8055F420)[6] + j);
        ((Dummy *)object)->slot25();
    } else {
        object = *(void **)((u8 *)base[6] + j);
        ((Dummy *)object)->slot25();
    }
    j += 4;
    i++;
firstCheck:
    base = (u32 *)lbl_8055F420;
    if (i < (s32)base[2]) goto firstBody;

    i = 0;
    j = 0;
    goto secondCheck;
secondBody:
    if (lbl_8055F3EB == 0) {
        if (i == (s32)base[1]) {
            object = *(void **)((u8 *)base[0xF] + j);
            ((Dummy *)object)->slot24();
        } else {
            object = *(void **)((u8 *)base[0xF] + j);
            ((Dummy *)object)->slot23();
            object = *(void **)((u8 *)(*(u32 **)&lbl_8055F420)[0xF] + j);
            ((Dummy *)object)->slot25();
        }
    } else if (i == (s32)base[1]) {
        object = *(void **)((u8 *)base[0xF] + j);
        ((Dummy *)object)->slot24();
        object = *(void **)((u8 *)(*(u32 **)&lbl_8055F420)[0xF] + *(s32 *)(lbl_8055F420 + 4) * 4);
        ((Dummy *)object)->slot26();
    } else {
        object = *(void **)((u8 *)base[0xF] + j);
        ((Dummy *)object)->slot22();
        object = *(void **)((u8 *)(*(u32 **)&lbl_8055F420)[0xF] + j);
        ((Dummy *)object)->slot25();
    }
    j += 4;
    i++;
secondCheck:
    base = (u32 *)lbl_8055F420;
    if (i < (s32)base[3]) goto secondBody;
}
#pragma scheduling on
#pragma cplusplus reset

void fn_80262120(void *arg0) {
    s32 zero;
    *(s32 *)arg0 = (s32)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 8) = 3;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 4) = zero;
}

#pragma scheduling invalid_target
void fn_8026213C(void *arg0) {
    *(s32 *)arg0 = (s32)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 8) = 6;
    *(s32 *)((u8 *)arg0 + 4) = 0;
}
#pragma scheduling on
void fn_80262158(void) {
}

void fn_8026215C(void) {
}

s32 fn_80262160(void) {
    return 0;
}

void fn_80262168(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1E) && lbl_8055F3E9 && !lbl_8055F3EA) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    }
    if (lbl_8055F3EB && !lbl_8055F3EA) {
        fn_80214AF0(0x1E);
        return;
    }
    fn_80214A9C(0x1E);
}

extern void fn_80230C30(float *, float *, s32, s32);
extern void fn_80230F78(u8 *, float *, u32 *, s32);
extern void fn_802354A0(void *, s32, s32, float, float, float, float, float);
extern void fn_80232BA4(char *, s32, s32, s32, float, float, float, float, float);
extern void fn_801308F4(char *, s32, s32);
extern void fn_801345D8(char *, s32, const char *, ...);
extern void *__AXGetStackHead(void);
extern u8 lbl_8055F3F4;
extern float lbl_8055F3F0;
extern char lbl_8055C428;
extern char lbl_8055C42C;
extern char lbl_8055C434;
extern double lbl_80563BA8;
extern float lbl_80563B88;
extern float lbl_80563B8C;
extern float lbl_80563B90;
extern float lbl_80563B94;
extern float lbl_80563B98;
extern float lbl_80563B9C;
extern float lbl_80563BA0;
#pragma cplusplus on
extern "C" void fn_802621F0(void *arg0) {
    struct Dummy {
        virtual void m0() = 0;
        virtual char *m1() = 0;
        virtual void m2() = 0;
        virtual char *m3() = 0;
        virtual void m4() = 0;
        virtual void m5() = 0;
        virtual void m6() = 0;
        virtual void m7() = 0;
        virtual s32 m8() = 0;
        virtual s32 m9() = 0;
        virtual s32 m10() = 0;
        virtual s32 m11() = 0;
        virtual void m12() = 0;
        virtual s32 m13() = 0;
        virtual void m14() = 0;
        virtual s32 m15() = 0;
    };
    char text2[0x1E];
    char text1[0x1E];
    u8 alpha;
    float width;
    float height;
    s32 output;
    float scale;
    s32 mode;
    s32 color2;
    s32 marker;
    Dummy *obj;
    char *name;
    if ((signed char)lbl_8055F3F4 == 0) {
        s32 initial = *(volatile s32 *)((u8 *)arg0 + 0x10);
        float initialFloat = (float)initial;
        lbl_8055F3F4 = 1;
        lbl_8055F3F0 = -initialFloat * lbl_80563B8C;
    }
    fn_80230C30(&width, &height, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    output = -1;
    mode = 0;
    marker = -1;
    {
        volatile u8 enabled = *(volatile u8 *)((u8 *)arg0 + 0x1C);
        color2 = -1;
        if (enabled != 0) {
            output = -1;
            mode = 1;
            marker = -1;
            color2 = -1;
        } else if (*(u8 *)((u8 *)arg0 + 0x1D) != 0) {
            output = -1;
            marker = -1;
            color2 = -1;
        }
    }
    fn_802354A0(*(void **)((u8 *)arg0 + 0x20), mode, color2,
                width, height, lbl_80563B90,
                (float)*(s32 *)((u8 *)arg0 + 0xC),
                (float)*(s32 *)((u8 *)arg0 + 0x10));
    if (*(u8 *)((u8 *)arg0 + 0x1C) != 0 && lbl_8055F3EA == 0) {
        fn_80230F78(&alpha, &scale, (u32 *)&output, 0);
        {
            s32 xValue = *(volatile s32 *)((u8 *)arg0 + 0xC);
            s32 yValue = *(volatile s32 *)((u8 *)arg0 + 0x10);
            float xFloat = (float)xValue;
            float yFloat = (float)yValue;
            float xUnit = lbl_80563B8C * xFloat;
            float yUnit = lbl_80563B8C * yFloat;
            float xScaled = scale * xUnit;
            float yScaled = scale * yUnit;
            float ratio = lbl_80563B88 + scale;
            float right = ratio * yFloat;
            float bottom = ratio * xFloat;
            u32 packedColor = (u32)color2 & 0x0000FF00;
            packedColor |= (u32)alpha << 24;
            packedColor |= (u32)color2 & 0xFFFF;
            fn_802354A0(*(void **)((u8 *)arg0 + 0x20), mode,
                        packedColor, width - yScaled, height + xScaled,
                        lbl_80563B90, right, bottom);
        }
    }
    obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18);
    fn_80232BA4(obj->m1(), *(s32 *)((u8 *)arg0 + 0x24), output, 0x11,
                lbl_80563B94 + width, height + lbl_8055F3F0,
                lbl_80563B98, lbl_80563B90, lbl_80563B88);
    obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18);
    if (obj->m9() != -1) {
        obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18);
        obj->m9();
        name = (char *)__AXGetStackHead();
    } else {
        name = &lbl_8055C428;
    }
    fn_80232BA4(name, *(s32 *)((u8 *)arg0 + 0x24), marker, 0x14,
                lbl_80563B9C + width, height + lbl_8055F3F0,
                lbl_80563B98, lbl_80563B90, lbl_80563B88);
    obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18);
    fn_801308F4(text1, 0x1E, obj->m13());
    obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18);
    if (obj->m8() <= 0) {
        fn_801345D8(text2, 0x1E, &lbl_8055C42C, &text1[1]);
    } else {
        obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18);
        fn_801308F4(text2, 0x1E, obj->m8());
        fn_801345D8(text2, 0x1E, &lbl_8055C434, text2, &text1[1]);
    }
    fn_80232BA4(text2, *(s32 *)((u8 *)arg0 + 0x24), output, 0x12,
                lbl_80563BA0 + width, height + lbl_8055F3F0,
                lbl_80563B98, lbl_80563B90, lbl_80563B88);
}
#pragma cplusplus reset
void fn_80262574(void) {
}

void fn_80262578(void) {
}

s32 fn_8026257C(void) {
    return 0;
}

void fn_80262584(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1F) && lbl_8055F3E9) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1F) = 0;
    }
}

