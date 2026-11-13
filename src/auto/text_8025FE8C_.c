// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;
struct Words5_80260E04 { s32 w[5]; };
extern float lbl_80563B88;
extern void fn_80214A9C(s32);
extern s32 fn_8025C204(s32);
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
    /* If a global state flag is set, returns success early. Otherwise looks up an
     * object by arg2, queries it for a resource/value (logging errors via
     * fn_802E317C on failure), wraps a valid value in a temporary handle, passes
     * it to fn_8024DAE0, then deletes the handle and returns the result. */
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

extern void *fn_80016464(int);
extern void *fn_80016510(int);
extern void *fn_8001285C(void);
#pragma cplusplus reset
void fn_8026003C(void) {
    int temp;
    temp = *(int *)((char *)fn_80016464(0) + 4);
    (void)temp;
    (void)fn_80016510(0);
    (void)fn_80016464(0);
    (void)fn_8001285C();
}
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

/* --- one group row of the challenge-difficulty selector ------------------ */
/* 0x2C bytes, allocated by fn_80260DC4 with the vtable named below: the item
   rows (SelectorItem, below) have the same shape without the group number at
   0x20.  Slot 0x8 of both vtables is the row's destructor, which the screen
   loop's cleanup calls as destroy(1). */
typedef struct {
    void *vtable;      /* 0x00 the vtable above */
    s32   base[4];     /* 0x04 widget base class */
    s32   unused_0x14; /* 0x14 kept zero */
    void *data;        /* 0x18 the data node this row shows */
    u8    on_cursor;   /* 0x1C the cursor is on this row */
    u8    dim;         /* 0x1D draw this row dimmed */
    u8    expanded;    /* 0x1E this row's group is open */
    u8    pad_0x1F;    /* 0x1F */
    s32   group;       /* 0x20 which group of the data source this row shows */
    void *art;         /* 0x24 gArt resource, from fn_8023512C */
    void *font;        /* 0x28 gText font block, from fn_80232578 */
} SelectorGroupRow;
#define SELECTOR_GROUP_VTABLE lbl_80345E28

#pragma push
#pragma small_data off
/* Deleting destructor of one challenge-selector group row -- slot 0x8 of its
 * vtable, which the screen loop's cleanup calls as destroy(1).  It drops the
 * two resources the row was built with (the gArt animation and the gText
 * font) and then frees the row itself when the delete flag is set. */
void *fn_80260854(SelectorGroupRow *row, s32 deleteFlag) {
    if (row != 0) {
        row->vtable = &SELECTOR_GROUP_VTABLE;
        /* fn_80235380 only reads its first argument; the vtable is what the
         * store above leaves in the second register. */
        fn_80235380((s32)row->art, (s32 *)&SELECTOR_GROUP_VTABLE);
        row->art = 0;
        fn_802328D4((s32)row->font);
        row->font = 0;
        if (deleteFlag > 0) fn_80128668(row);
    }
    return row;
}
extern s32 fn_80128668(void);
extern s32 fn_802328D4(s32);
extern s32 fn_80235380(s32, s32 *);
/* --- one item row of the challenge-difficulty selector ------------------- */
/* 0x28 bytes, allocated by fn_80261C68 with the vtable named below; the group
   rows (vtable lbl_80345E28) have the same shape plus their index at 0x20.
   Slot 0x8 of both vtables is the destructor fn_80260854/fn_802608D4, which
   the screen's cleanup loop calls as destroy(1). */
typedef struct {
    void *vtable;      /* 0x00 the vtable above */
    s32   base[4];     /* 0x04 widget base class */
    s32   unused_0x14; /* 0x14 kept zero */
    void *data;        /* 0x18 the data node this row shows */
    u8    on_cursor;   /* 0x1C the cursor is on this row */
    u8    dim;         /* 0x1D draw this row dimmed */
    u8    expanded;    /* 0x1E this row's group is open */
    u8    pad_0x1F;    /* 0x1F */
    void *art;         /* 0x20 gArt resource, from fn_8023512C */
    void *font;        /* 0x24 gText font block, from fn_80232578 */
} SelectorItem;
#define SELECTOR_ITEM_VTABLE lbl_80345EA0
#pragma push
#pragma small_data off
/* Deleting destructor of one challenge-selector item row -- slot 0x8 of its
 * vtable, which the screen's cleanup loop calls as destroy(1).  It drops the
 * two resources the row was built with (the gArt animation and the gText font)
 * and then frees the row itself when the delete flag is set. */
void *fn_802608D4(SelectorItem *item, s32 deleteFlag) {
    if (item != 0) {
        *(void **)item = &SELECTOR_ITEM_VTABLE;
        /* fn_80235380 only reads its first argument; the vtable is what the
         * store above leaves in the second register. */
        fn_80235380((s32)item->art, (s32 *)&SELECTOR_ITEM_VTABLE);
        item->art = 0;
        fn_802328D4((s32)item->font);
        item->font = 0;
        if (deleteFlag > 0) ((void (*)(void *))fn_80128668)(item);
    }
    return item;
}
extern void *lbl_8055F3E4;
extern u8 lbl_8055F3E8;
extern s32 lbl_802FA6C0[];
extern u8 lbl_80498F00[];
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
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
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
          
          
        initialMode = fn_80012810();
          if (initialMode != 0x130) {
              if (initialMode != 0x134) {
                  fn_80012794();
              }
              fn_80012790(0x130);
          }
          lbl_8055F3E4 = fn_8027B878(arg0);
          header = frame.header;
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
#pragma pop
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
    volatile s32 *src = arg1;
    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    e = src[4];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
    arg0[4] = e;
}

#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_80260E30(void) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21();
        virtual void f60(); virtual void f64(); virtual void f68(); virtual void f6c(); virtual void f70();
    };
    s32 offset;
    s32 i;
    s32 ret;
    if (lbl_8055F3EB) {
        lbl_8055F3EB = 0;
        offset = 0;
        i = 0;
        for (; i < *(s32 *)(lbl_8055F420 + 0xC); offset += 4, i++) {
            (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f6c();
        }
        i = 0;
        offset = 0;
        for (; i < *(s32 *)(lbl_8055F420 + 8); offset += 4, i++) {
            if (lbl_8055F3EB == 0) {
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x18) + offset))->f60();
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x18) + offset))->f6c();
            } else if (i == *(s32 *)lbl_8055F420) {
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x18) + offset))->f68();
            } else if (i == *(s32 *)(lbl_8055F420 + 4) * 2 || i == *(s32 *)(lbl_8055F420 + 4) * 2 + 1) {
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x18) + offset))->f64();
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x18) + offset))->f6c();
            } else {
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x18) + offset))->f6c();
            }
        }
        i = 0;
        register offset = 0;
        for (; i < *(s32 *)(lbl_8055F420 + 0xC); offset += 4, i++) {
            if (!lbl_8055F3EB) {
                if (i == *(s32 *)(lbl_8055F420 + 4)) {
                    (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f68();
                } else {
                    (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f64();
                    (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f6c();
                }
            } else if (i == *(s32 *)(lbl_8055F420 + 4)) {
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f68();
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + *(s32 *)(lbl_8055F420 + 4) * 4))->f70();
            } else {
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f60();
                (*(Obj **)(*(u8 **)(lbl_8055F420 + 0x3C) + offset))->f6c();
            }
        }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
#pragma push
#pragma cplusplus on
/* If active, lock, invoke two virtual getters on the current manager object, pass results to handler, then unlock/clear state. */
extern "C" s32 fn_802610C8(void) {
    struct Manager {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual s32 getParam(u8 *self);
        virtual s32 getValue();
    };
    s32 value = 0;
    u32 *managerBase;
    Manager *manager;
    s32 param;
    if (lbl_8055F3EB != 0) {
        lbl_8055F3EA = 1;
        fn_80214A9C(30);
        managerBase = (u32 *)lbl_8055F420;
        manager = *(Manager **)(managerBase + managerBase[0] + 0x18);
        value = manager->getValue();
        managerBase = (u32 *)lbl_8055F420;
        manager = *(Manager **)(managerBase + managerBase[0] + 0x18);
        param = manager->getParam((u8 *)managerBase);
        ((s32 (*)(s32, s32))fn_8025C204)(param, value);
        fn_80214AF0(30);
        fn_80230E90(0);
        lbl_8055F3EA = 0;
    }
    return 0;
}
#pragma pop
/* --- the two-level selector of the challenge-difficulty screen --------- */
/* lbl_8055F420 points at the frame header the screen loop (fn_80260954)
   builds on its stack, which carries the state of its cursor: a list of
   groups (the difficulties, from the data source lbl_8055F3E4) and, inside
   each group, its items.  fn_80261C68 creates the two widget arrays and
   stores them at 0x18 and 0x3C; the input callbacks fn_80261178 (enter),
   fn_802616A8 (up), fn_802613E0 (down) and fn_80260E30 (leave) move the
   cursor and repaint both lists, and lbl_8055F3EB says which list the
   cursor is in. */
typedef struct {
    s32 cursor;                 /* 0x00 item the cursor is on */
    s32 group;                  /* 0x04 group the cursor is on */
    s32 item_count;             /* 0x08 widgets in the item array */
    s32 group_count;            /* 0x0C widgets in the group array */
    u8  pad_0x10[8];
    u8 *item_widgets;           /* 0x18 SelectorWidget *[item_count] */
    u8  pad_0x1C[0x20];
    u8 *group_widgets;          /* 0x3C SelectorWidget *[group_count] */
} SelectorView;
#define SELECTOR          ((SelectorView *)lbl_8055F420)
#define SELECTOR_IN_ITEMS (lbl_8055F3EB) /* 0: cursor on a group, 1: in its items */

/* --- a group or item widget of that selector --------------------------- */
/* Slots 0x08-0x5C belong to the widget base class (its Draw is the slot the
   .data vtables fill at 0x28, fn_802621F0 for items).  The selector only
   uses the five state setters below, which set the flags Draw reads: 0x1C
   = the cursor is on this widget, 0x1D = dim it.  0x60 and 0x64 are the
   slots the two vtables (lbl_80345E28 groups, lbl_80345EA0 items) point at
   fn_802607C4/fn_802607EC and fn_80260848/fn_80260814, which set and clear
   byte 0x1D; the last three are named from how the selector calls them. */
struct SelectorWidget {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C();
    virtual void setDim();      /* 0x60 */
    virtual void clearDim();    /* 0x64 */
    virtual void setCursor();   /* 0x68 */
    virtual void clearCursor(); /* 0x6C */
    virtual void setExpanded(); /* 0x70 */
};
#pragma pop
#pragma push
#pragma cplusplus on
/* Open the group the selector's cursor is on (input event 0xD of the challenge
 * screen, the pair of fn_80260E30, which closes it again).
 *
 * Only reachable from the group list: from inside a group the callback reports
 * that it did nothing by returning 1.  Otherwise the cursor moves into the
 * group, on its first item (the group holds the two items group * 2 and
 * group * 2 + 1), and both widget lists are repainted as fn_802613E0 does it:
 * the item under the cursor gets setCursor(), the two items of the open group
 * come out of the dim state, everything else is dimmed, and the open group is
 * the one widget that gets setExpanded().
 */
extern "C" s32 fn_80261178(void *unused) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS != 0) return 1;

    /* the cursor goes into the group it was standing on */
    SELECTOR_IN_ITEMS = 1;
    i = 0;
    offset = 0;
    SELECTOR->cursor = SELECTOR->group << 1;

    /* repaint the item list */
    for (; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            /* the cursor is not here, so the whole list dims */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            /* the two items of the group that was opened stay bright */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }

    /* repaint the group list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            /* the group the cursor is inside: open, and let it show its items */
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
    return 0;
}
/* Move the selector's cursor down (input event 0x128 of the challenge screen).
 *
 * The cursor walks the group list while it is outside one, and the items of
 * its group once it is inside; either way it stops at the last entry.  Both
 * widget lists are then repainted: the widget the cursor is on gets
 * setCursor(), the items of the group the cursor belongs to are taken out of
 * the dim state, and everything else is dimmed and cleared.  fn_802616A8 is
 * the same walk upwards.
 */
extern "C" s32 fn_802613E0(void) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS == 0) {
        /* still on the group list: go to the next group */
        SELECTOR->group += 1;
        if (SELECTOR->group >= SELECTOR->group_count) {
            SELECTOR->group = SELECTOR->group_count - 1;
        }
    } else {
        /* inside the group: go to its next item, the last of the two shown */
        SELECTOR->cursor += 1;
        if (SELECTOR->cursor > SELECTOR->group * 2 + 1) {
            SELECTOR->cursor = SELECTOR->group * 2 + 1;
        }
    }

    /* repaint the item list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            /* the cursor is not here, so the whole list dims */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            /* the two items of the group the cursor is in stay bright */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }

    /* repaint the group list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            /* the group the cursor is inside: open, and let it show its items */
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
    return 0;
}
#pragma cplusplus off
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
#pragma push
#pragma cplusplus on
/* Move the selector's cursor up (the input event pairing with fn_802613E0).
 *
 * The cursor walks the group list while it is outside one, and the items of
 * its group once it is inside; either way it stops at the first entry.  Both
 * widget lists are then repainted as fn_802613E0 does it: the widget holding
 * the cursor gets setCursor(), the items of the cursor's group come out of the
 * dim state and everything else is dimmed and cleared.
 */
extern "C" s32 fn_802616A8(void) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS == 0) {
        /* still on the group list: go back to the previous group */
        SELECTOR->group -= 1;
        if (SELECTOR->group < 0) {
            SELECTOR->group = 0;
        }
    } else {
        /* inside the group: go to its previous item, the first of the two shown */
        SELECTOR->cursor -= 1;
        if (SELECTOR->cursor < SELECTOR->group * 2) {
            SELECTOR->cursor = SELECTOR->group * 2;
        }
    }

    /* repaint the item list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            /* the cursor is not here, so the whole list dims */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            /* the two items of the group the cursor is in stay bright */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }

    /* repaint the group list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            /* the group the cursor is inside: open, and let it show its items */
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
    return 0;
}
#pragma pop
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
    lbl_8055F3E9 = arg0 == 2;
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
extern u8 lbl_80498F20[];
extern s32 lbl_802FA6D4[];
#pragma pop
#pragma push
#pragma small_data on
extern u8 lbl_8055C418;
extern u8 lbl_8055C420;
#pragma pop

void fn_80261AE8(s32 *arg0, s32 arg1) { *arg0 = arg1; }

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80261AF0(s32 *arg0, s32 arg1) {
    struct Frame {
        s32 args[6];
        s32 objects[6][5];
        char buffer[116];
    } frame;
    register s32 zero = 0;
    register s32 zero1 = 0;
    register s32 zero2 = 0;
    register s32 three = 3;
    register s32 two = 2;
    register s32 six = 6;
    register s32 minusTwo = -2;
    register s32 thirteen = 13;
    register s32 eight = 8;
    register s32 *a = lbl_802FA6D4;
    register s32 *b = (s32*)lbl_80498F00;
    register s32 func = (s32)fn_80261A40;
    s32 hash1;
    s32 hash2;
    fn_801345D8(frame.buffer, 0x64, lbl_80345DE0, arg1);
    frame.objects[0][0] = zero;
    frame.objects[0][1] = 5;
    frame.objects[0][2] = (s32)lbl_80498F20;
    frame.objects[0][3] = zero1;
    frame.objects[0][4] = zero;
    hash1 = fn_80131234(lbl_80345E0C);
    frame.objects[1][0] = (s32)&lbl_8055C418;
    frame.objects[1][1] = three;
    frame.objects[1][2] = hash1;
    frame.objects[1][3] = zero1;
    frame.objects[1][4] = zero;
    hash2 = fn_80131234(frame.buffer);
    frame.objects[2][0] = (s32)&lbl_8055C420;
    frame.objects[2][1] = three;
    frame.objects[2][2] = hash2;
    frame.objects[2][3] = zero2;
    frame.objects[2][4] = zero;
    frame.objects[3][0] = (s32)&lbl_8055B860;
    frame.objects[3][1] = six;
    frame.objects[3][2] = zero;
    frame.objects[3][3] = minusTwo;
    frame.objects[3][4] = thirteen;
    frame.objects[4][0] = (s32)&lbl_8055BAB8;
    frame.objects[4][1] = eight;
    frame.objects[4][2] = func;
    frame.objects[4][3] = two;
    frame.objects[4][4] = zero;
    frame.objects[5][0] = b[0];
    frame.objects[5][1] = b[1];
    frame.objects[5][2] = b[2];
    frame.objects[5][3] = b[3];
    frame.objects[5][4] = b[4];
    frame.args[0] = a[0];
    frame.args[2] = a[2];
    frame.args[3] = a[3];
    frame.args[4] = a[4];
    frame.args[1] = (s32)frame.objects;
    fn_802146BC(frame.args, -0x3E7, -0x3E7, 1);
}
#pragma pop

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
    s32 count;
    s32 max;
    void *object;
    void *item;
    float targetValue;
    u32 *base;
    register s32 i;
    register s32 j;
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

void fn_80262168(void *obj) {
    /* If the object's flag at +0x1E is set while lbl_8055F3E9 is set and lbl_8055F3EA is clear,
       clear that flag and call fn_80230E90(0). Then enable UI element 0x1E with fn_80214AF0 if
       lbl_8055F3EB is set and lbl_8055F3EA is clear, otherwise disable it with fn_80214A9C. */
    if (*(u8 *)((u8 *)obj + 0x1E) && lbl_8055F3E9 && !lbl_8055F3EA) {
        fn_80230E90(0);
        *(u8 *)((u8 *)obj + 0x1E) = 0;
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
extern "C" void fn_802621F0(void *arg0) { struct Dummy { virtual void m0() = 0; virtual char *m1() = 0; virtual void m2() = 0; virtual char *m3() = 0; virtual void m4() = 0; virtual void m5() = 0; virtual void m6() = 0; virtual void m7() = 0; virtual s32 m8() = 0; virtual s32 m9() = 0; virtual s32 m10() = 0; virtual s32 m11() = 0; virtual void m12() = 0; virtual s32 m13() = 0; virtual void m14() = 0; virtual s32 m15() = 0; }; char text2[0x1E]; char text1[0x1E]; u8 alpha; float width; float height; s32 output; float scale; s32 mode; s32 color2; s32 marker; Dummy *obj; char *name; if ((signed char)lbl_8055F3F4 == 0) { s32 initial = *(s32 *)((u8 *)arg0 + 0x10); float initialFloat = (float)initial; lbl_8055F3F4 = 1; lbl_8055F3F0 = -initialFloat * lbl_80563B8C; } fn_80230C30(&width, &height, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8)); output = -1; mode = 0; marker = -1; color2 = -1; if (*(u8 *)((u8 *)arg0 + 0x1C) != 0) { output = -1; mode = 1; marker = -1; color2 = -1; } else if (*(u8 *)((u8 *)arg0 + 0x1D) != 0) { output = -1; marker = -1; color2 = -1; } fn_802354A0(*(void **)((u8 *)arg0 + 0x20), mode, color2, width, height, lbl_80563B90, (float)*(s32 *)((u8 *)arg0 + 0xC), (float)*(s32 *)((u8 *)arg0 + 0x10)); if (*(u8 *)((u8 *)arg0 + 0x1C) != 0 && lbl_8055F3EA == 0) { fn_80230F78(&alpha, &scale, (u32 *)&output, 0); { s32 xValue = *(s32 *)((u8 *)arg0 + 0xC); s32 yValue = *(s32 *)((u8 *)arg0 + 0x10); float xFloat = (float)xValue; float yFloat = (float)yValue; float xUnit = lbl_80563B8C * xFloat; float yUnit = lbl_80563B8C * yFloat; float xScaled = scale * xUnit; float yScaled = scale * yUnit; float ratio = lbl_80563B88 + scale; float right = ratio * xFloat; float bottom = ratio * yFloat; u32 packedColor = ((u32)color2 & 0xFF00) | ((u32)alpha << 24) | ((u32)color2 & 0xFFFF); fn_802354A0(*(void **)((u8 *)arg0 + 0x20), mode, packedColor, width - xScaled, height + yScaled, lbl_80563B90, right, bottom); } } obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); fn_80232BA4(obj->m1(), *(s32 *)((u8 *)arg0 + 0x24), output, 0x11, lbl_80563B94 + width, height + lbl_8055F3F0, lbl_80563B98, lbl_80563B90, lbl_80563B88); obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); if (obj->m9() != -1) { obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); obj->m9(); name = (char *)__AXGetStackHead(); } else { name = &lbl_8055C428; } fn_80232BA4(name, *(s32 *)((u8 *)arg0 + 0x24), marker, 0x14, lbl_80563B9C + width, height + lbl_8055F3F0, lbl_80563B98, lbl_80563B90, lbl_80563B88); obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); fn_801308F4(text1, 0x1E, obj->m13()); obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); if (obj->m8() <= 0) { fn_801345D8(text2, 0x1E, &lbl_8055C42C, &text1[1]); } else { obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); fn_801308F4(text2, 0x1E, obj->m8()); fn_801345D8(text2, 0x1E, &lbl_8055C434, text2, &text1[1]); } fn_80232BA4(text2, *(s32 *)((u8 *)arg0 + 0x24), output, 0x12, lbl_80563BA0 + width, height + lbl_8055F3F0, lbl_80563B98, lbl_80563B90, lbl_80563B88); }
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

