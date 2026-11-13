extern void __AXDSPInitCallback_801769E0(void);
#pragma dont_inline fn_8000B3DC
#pragma dont_inline fn_8000ADE0
extern void fn_8000D000(void *, void *, int);
extern void AXFXSetHooks_80210950(void *, int);
extern float lbl_805601FC, lbl_80560204;
extern unsigned char lbl_8055D3EC;
extern int fn_8000B5A8(int, int);
extern void AXFXSetHooks_8020DE10(void (*)(void), int, unsigned char);
extern int fn_80230B5C(int *);
extern int fn_802C8638(int *);
extern int fn_802C974C(float, float, float);
extern int fn_80010074(int, int, int *, float, float, float);
extern int fn_80011A2C(void);
extern int fn_802C9904(void);
extern int lbl_80558A48;
extern float lbl_805601F8, lbl_80560200, lbl_80560208, lbl_8056020C;
#pragma push
#pragma small_data off
extern char lbl_8034F5F8[], lbl_8034F604[];
#pragma pop
extern char lbl_802FBC90[];
extern void *lbl_8055D3D0;
extern int lbl_80558A50, lbl_80558A58, lbl_80558A60, lbl_80558A68;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8000AC98(void) {
}

int fn_8000AC9C(void) { return 0; }

void fn_8000ACA4(void) {
    return;
}

void fn_8000ACA8(void) {
}

void fn_8000ACAC(void) {
    return;
}

void fn_8000ACB0(void) {
    if (fn_802044E8() == 0) {
        fn_80007238();
    }
}

int fn_802044E8(void);
int fn_80007238();
int fn_80204870(void);
int fn_800074EC(int);
int fn_8000ACDC(int arg0) {
    if (fn_80204870() != 0) {
        return 1;
    }
    return fn_800074EC(arg0);
}

void fn_8000AD20(void) {
}

int fn_8000AD24(void) { return 0; }

int fn_8000AD2C(void) {
    int index = ((char *)lbl_8055D3D0 - lbl_802FBC90) / 0x14;
    switch (index) {
    case 0:
    case 1:
    case 0x12:
        return 0;
    default:
        return 1;
    }
}

int fn_8000AD84(void) {
 int index = ((char *)lbl_8055D3D0 - lbl_802FBC90) / 0x14;
 switch (index) {
 case 0x12:
 case 1:
 case 0x18:
  return 1;
 default:
  return 0;
 }
}

/* lbl_8034F5B8: one record per player (4).  fn_8000AF1C fills `value` from the
 * race config and sets `override` to NO_OVERRIDE; fn_8000C630 queues a one-shot
 * `override` for a player (-1 = all of them) and fn_8000BC44 hands the record's
 * value to that player's object (fn_8026A1F0) every frame. */
struct PlayerRecord {
    int value;    /* 0x00 current game value */
    int override; /* 0x04 value to use once, or NO_OVERRIDE when none is queued */
};
#define NO_OVERRIDE 0x22

extern int lbl_8034F5B8[];
extern int lbl_8034F5D8[];
extern int lbl_8055D3D8, lbl_8055D3DC, lbl_8055D3E8;
extern unsigned char lbl_8055D3D4, lbl_8055D3D5;
extern int lbl_8055D3E0;
extern int fn_802E4A10(void);
extern void *lbl_8055D3D0;
extern int lbl_8055D3DC;
extern int lbl_8055D3E4;
extern char lbl_802FBC90[];
void fn_8000ADE0(int arg0) {
    /* Switch active state: save previous state for certain indices, run exit/enter callbacks from state table, and record current tick. */
    void (*callback)(void);
    if (arg0 != 1 && arg0 != 0x12 && arg0 != 0x18)
        lbl_8055D3DC = arg0;
    if (lbl_8055D3D0 != 0) {
        callback = *(void (**)(void))((char *)lbl_8055D3D0 + 0x10);
        if (callback != 0) callback();
    }
    lbl_8055D3D0 = lbl_802FBC90 + arg0 * 0x14;
    if (lbl_8055D3D0 != 0) {
        callback = *(void (**)(void))((char *)lbl_8055D3D0 + 0xC);
        if (callback != 0) callback();
    }
    lbl_8055D3E4 = fn_802E4A10();
}

int fn_80129374(int, int);
void fn_8000AE78(int arg0) {
    int i = 0;
    do {
        fn_80129374(i, arg0);
        i++;
    } while (i < 2);
}

int fn_800070DC(void);
void fn_8000AEC4(void) {
    fn_800070DC();
}

#pragma push
#pragma scheduling invalid_target
int fn_8000AEC8(int arg0) {
    int i;
    int *p;
    i = lbl_8055D3E0;
    p = lbl_8034F5D8;
    for (; i > 0; i--) {
        if (arg0 == *p) return 1;
        p++;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_8000AF04(void) {
    lbl_8034F5D8[0] = 4;
    lbl_8055D3E0 = 1;
}
#pragma pop
extern int fn_80204024(void);
extern int fn_801E7C1C(void *);
extern void fn_801E8818(void (*)(void), void *);
extern void fn_8012E81C(void *);
extern void fn_8000AB44(void), fn_8023889C(void), fn_801CB808(void);
extern void fn_801617BC(void), fn_802061F8(void), fn_80006D9C(void);
extern void fn_8000CE60(void), fn_8020D178(void), fn_802108C8(void);
extern void fn_802B8744(void), fn_801769EC(void);
extern void *memset(void *, int, unsigned int);
extern void fn_801332D0(int, void *, int *);
extern int fn_8000AEC8(int);
extern void fn_80265D74(void), fn_80128678(void), fn_80206454(void), fn_80127930(void);
extern void fn_802D3E9C(int);
extern void fn_8000AEC4(void);
extern int fn_802E30C8();
#pragma push
#pragma small_data off
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_8000AF1C(void *arg0)
{
  int zero = 0;
  char *config = lbl_802FBC90;
  int active;
  int *entry;
  register int i;
  int val;
  int limit = 0x22;
  void (*callback)(void);
  void *startupMessage;
  lbl_8055D3D8 = zero;
  lbl_8055D3E8 = zero;
  active = fn_80204024();
  lbl_8055D3DC = zero;
  fn_801E7C1C(arg0);
  callback = fn_8000AEC4;
  startupMessage = config + 0x21C;
  fn_801E8818(callback, startupMessage);
  fn_8012E81C(config + 0x228);
  fn_8000AB44();
  fn_8023889C();
  fn_801CB808();
  fn_801617BC();
  fn_802061F8();
  fn_80006D9C();
  fn_8000CE60();
  fn_8020D178();
  fn_802108C8();
  fn_802B8744();
  fn_801769EC();
  ((void (*)(int)) fn_8000AF04)(*((int *) (((char *) arg0) + 0x3E8)));
  entry = lbl_8034F5B8;
  i = 0;
  do
  {
    memset(entry, 0, 8);
    val = *((int *) (&lbl_8034F5D8));
    fn_801332D0(i + 0xC, config + 0x238, &val);
    if ((*((int *) (&lbl_8034F5D8))) >= limit)
    {
      goto invalid;
    }
    if ((*((int *) (&lbl_8034F5D8))) < 0)
    {
      invalid:
      ((int (*)(const char *, ...)) fn_802E30C8)(config + 0x248, i);

      val = *((int *) (&lbl_8034F5D8));
    }
    else
      if (fn_8000AEC8(val) == 0)
    {
      val = *((int *) (&lbl_8034F5D8));
    }
    i++;
    entry[0] = val;
    entry[1] = limit;
    entry += 2;
  }
  while (i < 4);
  lbl_8055D3D5 = 0;
  lbl_8055D3D4 = 1;
  lbl_8055D3D0 = 0;
  if (active != 0)
  {
    fn_8000ADE0(0xD);
    fn_80265D74();
    fn_80128678();
    fn_80206454();
    fn_80127930();
    fn_802D3E9C(0);
  }
}
#pragma scheduling on
#pragma dont_inline reset
  #pragma pop
  
  extern void fn_80127954(void);
extern void fn_80128684(void);
extern void fn_80265D78(void);
extern int fn_80133348(int, int, int);
extern void fn_802B87A0(void);
extern void fn_80210904(void);
extern void fn_8020D1C8(void);
extern void fn_8000CEF0(void);
extern void fn_80006E54(void);
extern void fn_80206228(void);
extern void fn_801618B4(void);
extern void fn_801CB8C0(void);
extern void fn_80238920(void);
extern void fn_801E8820(void (*)(void));
extern void fn_801E7DEC(int);
extern char lbl_802FBEC8[];
#pragma scheduling invalid_target
/* Initialize subsystems and register per-slot callbacks/handlers during startup. */
void fn_8000B09C(int arg0) {
    int *entry;
    int i;

    fn_80127954();
    fn_80128684();
    fn_80265D78();
    entry = lbl_8034F5B8;
    i = 0;
    do {
        fn_80133348(i + 0xC, (int)lbl_802FBEC8, *entry);
        i++;
        entry += 2;
    } while (i < 4);
    fn_802B87A0();
    fn_80210904();
    fn_8020D1C8();
    fn_8000CEF0();
    fn_80006E54();
    fn_80206228();
    fn_801618B4();
    fn_801CB8C0();
    fn_80238920();
    fn_801E8820(fn_8000AEC4);
    fn_801E7DEC(arg0);
}

extern void fn_8017685C(int);
extern void fn_801AF6FC(void);
extern void fn_801AF92C(void *);
extern void *fn_801EA9A0();
extern int fn_802E30C8();
extern unsigned char lbl_8055D3D5;
extern int lbl_8055D3E8;
extern char lbl_802FBF38[];
#pragma scheduling invalid_target
void fn_8000B150(void *arg0) {
    char *entry;
    int i;
    int value;

    fn_8017685C(1);
    fn_801AF6FC();
    if (arg0 == 0)
        return;
    fn_801AF92C(arg0);
    *(unsigned char *)((char *)arg0 + 0xE) = lbl_8055D3D5;
    if (lbl_8055D3D5 == 0) {
        lbl_8055D3E8++;
        *(int *)((char *)arg0 + 8) = lbl_8055D3E8;
        ((void (*)(char *, ...))fn_802E30C8)(lbl_802FBF38, lbl_8055D3E8);
    }
    i = 0;
    entry = (char *)arg0;
    while (i < *(int *)arg0) {
        value = *(int *)((char *)((void *(*)(int))fn_801EA9A0)(i) + 0xAC);
        i++;
        *(int *)(entry + 0x10) = value;
        entry += 0x14;
    }
}
int fn_8000B210(void *arg0) {
    extern int fn_80231504(int);
    if (*(void **)lbl_8055D3D0 != 0) {
        if (((int (*)(void))fn_8000AD2C)() != 0) {
            int saved = fn_80231504(0);
            ((int (*)())*(void **)lbl_8055D3D0)(saved, lbl_8055D3D0);
            return fn_80231504(saved);
        }
        return ((int (*)())*(void **)lbl_8055D3D0)(lbl_8055D3D0);
    }
    return (int)lbl_8055D3D0;
}

extern int fn_8000B210(void *);
void fn_8000B288(void* alarm) {
    fn_801DF110(((int (*)(void *))fn_8000B210)(alarm));
}

extern void fn_802C8530(void);
extern int fn_801DF060(void);
extern void fn_801E81B8(int, void (*)(void *));
extern void fn_801DFFB4(void);
extern void fn_802C9A70(int);
extern int fn_801E8838(void);
extern int fn_800217AC(void);
extern void fn_802C942C(int);
extern void fn_802C855C(void);
extern void fn_802D08C4(int);
extern void fn_802C2B48(void);
void fn_8000B2AC(void) {
    fn_802C8530();
    fn_801E81B8(1, fn_801DF060() != 0
        ? (void (*)(void *))fn_8000B288
        : (void (*)(void *))fn_8000B210);
    fn_801DFFB4();
    fn_802C9A70(0);
    if (fn_801E8838() != 0 && fn_800217AC() != 0) {
        fn_802C942C(fn_801E8838() << 24);
    }
    fn_802C855C();
    fn_801E85A4();
    fn_802D08C4(0);
    fn_802C2B48();
    fn_802D08C4(1);
}

#pragma cplusplus on
extern "C" int fn_8000B33C(void *object, int argument, int fallback) {
    struct Dummy {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual int f4();
        virtual int f5();
        virtual int f6();
        virtual int f7();
        virtual int f8();
        virtual int f9(int);
    };
    int result;
    if (((Dummy *)object)->f1()) {
        result = ((Dummy *)object)->f9(argument);
    } else {
        result = fallback;
    }
    return result;
}
#pragma cplusplus reset
void fn_8000B3B4(void) {
    void (*callback)(void);
    callback = *(void (**)(void))(lbl_802FBC90 + lbl_8055D3DC * 0x14);
    if (callback != 0)
        callback();
}

void fn_8000B3DC(unsigned char arg0) {
    extern unsigned char lbl_8055D3EC;
    extern void fn_8000B3B4(void);
    extern void AXFXSetHooks_8020DE10(void (*)(void), int, unsigned char);
    lbl_8055D3EC = arg0;
    ((void (*)(int))fn_8000ADE0)(0x12);
    AXFXSetHooks_8020DE10((void (*)(void))fn_8000B5A8, lbl_8055D3EC ? (int)fn_8000B3B4 : 0, lbl_8055D3EC);
}

extern int fn_8016212C(void), fn_80265D64(void), fn_80265D6C(void), fn_80265D50(void);
extern int fn_80265D54(int), fn_80176734(void), fn_801CB3F8(void), fn_8001EFB8(void);
extern int fn_802E30C8(void *);
extern void fn_8000B3DC(unsigned char);
extern void fn_8000ADE0(int);
extern unsigned char lbl_8055D3D4, lbl_8055D3D5;
extern char lbl_802FBF80[];
int fn_8000B42C(int arg0) {
    int var_r31 = 1;
    if (fn_8016212C() == 0) {
        switch (arg0) {
        case 0: break;
        case 1:
            if (fn_80265D64() == 0) fn_80176734();
            else if (fn_80265D6C() != 0) fn_80265D54(2);
            else fn_802E30C8(&lbl_802FBF80);
            fn_801CB3F8();
            fn_8001EFB8();
            break;
        case 3:
            if (fn_80265D64() == 0) {
                lbl_8055D3D4 = 0;
                lbl_8055D3D5 = 1;
            } else if (fn_80265D6C() != 0) lbl_8055D3D4 = 0;
            else fn_80265D50();
            break;
        case 2:
            var_r31 = 0;
            fn_8000B3DC(1);
            break;
        }
    }
    if (var_r31 != 0) fn_8000ADE0(lbl_8055D3DC);
    return 1;
}

#pragma scheduling invalid_target
int fn_8000B53C(int arg0) {
    ((void (*)(int))fn_8000ADE0)(0x12);
    AXFXSetHooks_8020DE10((void (*)(void))fn_8000B5A8, lbl_8055D3EC ? (int)fn_8000B3B4 : 0, lbl_8055D3EC);
    if (arg0 == 1) return 1;
    return 0;
}

int fn_8000B5A8(int event, int param) {
    /* Handle a UI/menu event: for event 2 with param 0x58 or 0x0D, switch to
     * state 0x18 and install AXFX hook fn_8000B53C, returning 1; otherwise
     * apply state 1 with callbacks fn_8000B42C/fn_8000B3B4 when lbl_8055D3EC
     * is set, or restore lbl_8055D3DC, and return whether event is 5. */
    if (event == 2 && (param == 0x58 || param == 0xd)) {
        ((void (*)(int))fn_8000ADE0)(0x18);
        AXFXSetHooks_80210950((void *)fn_8000B53C, 0);
        return 1;
    }
    if (lbl_8055D3EC != 0) {
        ((void (*)(int))fn_8000ADE0)(1);
        fn_8000D000((void *)fn_8000B42C, (void *)fn_8000B3B4, 2);
    } else {
        ((void (*)(int))fn_8000ADE0)(lbl_8055D3DC);
    }
    return event == 5;
}

extern int fn_80137C98(int);
extern int fn_801DF238(int);
extern int fn_800075A0(int);
extern int fn_80265D64(void);
extern int fn_801769F8(void);
extern int fn_801E86E8(int, int);
extern void fn_8000D000(void *, void *, int);
extern void fn_801769EC(void);
extern void fn_80206454(void);
extern void fn_80206444(void);
extern void fn_8000BF10(int, int);
extern char lbl_802FBFB0[];
#pragma push
#pragma dont_inline on
/* Dispatch a UI/menu event for a context, gating by current screen state and invoking event-specific handlers. */
void fn_8000B64C(int eventId, int contextId) {
    int playerState;
    int (*eventFilter)(int);
    int selectedValue;

    playerState = fn_80137C98(contextId);
    if (playerState < 0) goto done;
    if (fn_801DF238(eventId) != 0) goto done;
    if (fn_8000AD84() != 0 && contextId != lbl_8055D3E4) goto done;

    eventFilter = *(int (**)(int))((char *)lbl_8055D3D0 + 4);
    if (eventFilter != 0 && eventFilter(eventId) != 0) goto done;
    if (eventId == 0x60) goto done;

    if (eventId >= 0x60) goto high_event;
    if (eventId == 0x50) goto event_50;
    if (eventId >= 0x50) goto check_5c;
    if (eventId == 0x1B) goto event_1b;
    if (eventId >= 0x1B) goto default_event;
    if (eventId != 0x0A) goto default_event;
    goto done;

check_5c:
    if (eventId != 0x5C) goto default_event;
    goto event_5c;

high_event:
    if (eventId >= 0x121) goto check_124;
    if (eventId == 0x7E) goto done;
    if (eventId >= 0x7E) goto default_event;
    if (eventId != 0x70) goto default_event;
    goto event_50;

check_124:
    if (eventId == 0x124) goto event_124;
    if (eventId >= 0x124) goto default_event;
    if (eventId < 0x123) goto done;
    goto default_event;

event_1b:
    if (fn_8000D75C() == 0 &&
        fn_801E8838() == 0 &&
        fn_800075A0(playerState) != 0) {
        fn_8000D000((void *)fn_8000B42C, (void *)fn_8000B3B4, 0);
        fn_8000ADE0(1);
    }
    goto done;

event_50:
    if (fn_80265D64() == 0 && fn_8000D75C() == 0) {
        if (fn_801769F8() != 0) {
            fn_801769EC();
            fn_80206454();
        } else {
            __AXDSPInitCallback_801769E0();
            fn_80206444();
        }
    }
    goto done;

event_124:
    selectedValue = fn_801E86F8(playerState);
    if (selectedValue != -1) {
        selectedValue = fn_801E86F8(playerState);
        fn_801E86E8(selectedValue, playerState);
    }
    goto done;

event_5c:
    if (fn_801769F8() == 0) {
        ((int (*)(char *, ...))fn_802E30C8)(lbl_802FBFB0);
    }
    goto done;

default_event:
    fn_8000BF10(eventId, (int)lbl_8034F5B8);

done:
    return;
}
#pragma pop

#pragma scheduling on
extern int fn_80007554(int, int);
extern int fn_8000BD9C(int, int, int);
extern int fn_801E7DF0(int);
extern int fn_801E7E04(int, int);
extern int fn_801E85A4(void);
extern int fn_801E868C(int, int *, int *);
extern int fn_801E86F8(int);
extern void *fn_801EA9A0(void);
/* Polls per-slot controller/input events and dispatches them: acknowledges type 0/3
 * changes (updating slot state or cycling a config entry in lbl_8034F5B8 when the
 * global at fn_801EA9A0()+0x30 is not 3), and forwards other event types to
 * fn_80007554. */
void fn_8000B838(void) {
    int eventType;
    int eventParam;
    char *slotData = (char *)&lbl_8034F5B8;
    int slot = 0;

    goto check;

loop:
    eventType = 0;
    eventParam = 0;
    if (fn_801E868C(slot, &eventType, &eventParam) != 0) {
        switch (eventType) {
        case 3:
            fn_801E86F8(slot);
            if (*(int *)((char *)fn_801EA9A0() + 0x30) != 3) {
                if (fn_801E7DF0(slot) != 0)
                    fn_801E7E04(slot, 0);
                else
                    fn_801E7E04(slot, 3);
            }
            break;
        case 0:
            fn_801E86F8(slot);
            if (*(int *)((char *)fn_801EA9A0() + 0x30) != 3)
                fn_8000BD9C(slot, 0, (int)slotData);
            break;
        default:
            ((int (*)(int, int, int))fn_80007554)(slot, eventType, eventParam);
            break;
        }
    }
    slotData += 8;
    slot++;
check:
    if (slot < fn_801E85A4())
        goto loop;
}

extern int fn_802ECC10(void);
extern int fn_8000D75C(void);
extern int fn_8000D764(void);
extern int fn_800216D0(void);
extern int fn_80161C70(void);
extern void fn_8000D048(void *, void *, int);
extern void fn_80129AEC(int);
extern void fn_80129B60(void);
extern int fn_801769A8(void);
extern int fn_802E47B8(void);
extern int fn_802E46F0(void);
extern int fn_8020DE1C(void);
extern void fn_80176780(int, int);
extern void fn_8000B64C(int, int);
extern unsigned char lbl_8055D3ED;
#pragma push
#pragma dont_inline on
/* Per-frame home/menu/audio-key handler: tracks home-button state transitions,
 * handles menu open conditions, runs input/audio updates, and dispatches key events.
 */
void fn_8000B950(void) {
    int state;
    int result;
    int key;
    int code;

    state = fn_802ECC10();
    if ((unsigned int)state != (unsigned int)lbl_8055D3ED) {
        lbl_8055D3ED = state;
        if (fn_8000D75C() == 0 &&
            fn_801DF060() == 0 &&
            lbl_8055D3D0 == (void *)lbl_802FBC90) {
            if (state == 0) {
                fn_801769EC();
                fn_80206454();
            } else {
                __AXDSPInitCallback_801769E0();
                fn_80206444();
            }
        }
    }

    if (fn_802ECC10() == 0 &&
        fn_801DF060() == 0 &&
        fn_800216D0() == 0 &&
        fn_80161C70() != 0 &&
        fn_801E8838() == 0 &&
        lbl_8055D3D0 == (void *)lbl_802FBC90) {
        result = fn_8000D764();
        if (result != -1) {
            fn_8000D048((void *)fn_8000B42C, (void *)fn_8000B3B4, 0);
            fn_8000ADE0(1);
            lbl_8055D3E4 = result;
        }
    }

    fn_80129AEC(-1);
    fn_80129B60();
    if ((fn_801769A8() & 0x4000) == 0) {
        fn_8000B838();
    }

    if (fn_802E47B8() == 0)
        return;
    key = fn_802E46F0();
    result = fn_802ECC10();
    key &= ~((-result | result) >> 31);
    if ((unsigned short)key == 0)
        return;
    if ((fn_801769A8() & 0x4000) != 0) {
        code = key & 0xFFFF;
        if (code != 0x58 && code != 0xD)
            goto call_key;
        if (fn_8000D75C() != 0 ||
            fn_8020DE1C() != 0 ||
            fn_801E8838() != 0)
            goto call_key;
        fn_80176780(2, 0);
        return;
    }
call_key:
    fn_8000B64C((unsigned short)key, fn_802E4A10());
}
#pragma pop
extern int fn_80019BA8(void);
extern int fn_801298E8(void *, int);
extern int fn_802E2C20(void);
extern int lbl_8055D3D8;
int fn_8000BB08(void) {
    /* Return 1 if no input activity seen and idle timer exceeds 0xEA60 ticks; otherwise update/clear the idle timestamp and return 0. */
    unsigned char sp8[0x68];
    int temp_r31, var_r30, var_r29, old;
    if (fn_80019BA8() != 0) {
        temp_r31 = fn_802E2C20();
        var_r30 = 0;
        var_r29 = 0;
        do {
            if (fn_801298E8(sp8, var_r29) != 0) {
                if (sp8[0x20]) var_r30 = 1;
                if (sp8[0x21]) var_r30 = 1;
                if (sp8[0x22]) var_r30 = 1;
                if (sp8[0x23]) var_r30 = 1;
                if (sp8[0x24]) var_r30 = 1;
                if (sp8[0x25]) var_r30 = 1;
                if (sp8[0x26]) var_r30 = 1;
                if (sp8[0x27]) var_r30 = 1;
            }
            var_r29++;
        } while (var_r29 < 4);
        if (var_r30 != 0) goto update;
        old = lbl_8055D3D8;
        if (old == 0) goto update;
        if (old == 0) goto update_end;
        if (temp_r31 <= old) goto update_end;
        if (temp_r31 - old <= 0xEA60) goto update_end;
        return 1;
    }
    goto exit;
update:
    lbl_8055D3D8 = temp_r31;
update_end:
    return 0;
exit:
    return 0;
}

/* One pass of the game loop (fn_8000C000 calls it while the running flag
 * lbl_8055D3D4 stays set): gives every player the game value in its record --
 * the one-shot override queued by fn_8000C630 when there is one, otherwise the
 * record's own value, which the override is then cleared back to -- runs the
 * per-frame subsystems, the current game mode's frame callback and the
 * menu/pause and key handling, and finally clears the running flag when the
 * race is over, when it has been finished off or when the player has been idle
 * for a minute. */
void fn_8000BC44(void) {
    extern char lbl_802FBFDC[], lbl_802FBFF8[];
    struct PlayerRecord *record = (struct PlayerRecord *)&lbl_8034F5B8;
    int player = 0;

    goto check;
loop:
    if (record->override == NO_OVERRIDE) {
        fn_8026A1F0(record->value, player, 0);
    } else {
        fn_8026A1F0(record->override, player, 0);
        record->override = NO_OVERRIDE;
    }
    record++;
    player++;
check:
    if (player < fn_801E85AC())
        goto loop;

    fn_800207B0();
    fn_801E7E48();
    fn_80176BAC();
    ((void (*)(int))fn_8000AE78)(fn_8000D75C() == 0);
    /* the current game mode's (lbl_8055D3D0) per-frame callback */
    if (*(void (**)(void))((char *)lbl_8055D3D0 + 8))
        (*(void (**)(void))((char *)lbl_8055D3D0 + 8))();
    fn_8000B950();
    if (fn_801E89EC() == 3) {
        ((void (*)(char *, ...))fn_802E30C8)(lbl_802FBFDC);
        lbl_8055D3D4 = 0;
    } else if (fn_8012742C() != 0) {
        lbl_8055D3D4 = 0;
    }
    if (fn_8000BB08() != 0) {
        ((void (*)(char *, ...))fn_802E30C8)(lbl_802FBFF8);
        fn_8017691C();
    }
}

void fn_8000BD64(void) {
    float value2 = lbl_80560204;
    float value1 = lbl_805601FC;
    *(volatile float *)lbl_8034F5F8 = value1;
    ((volatile float *)lbl_8034F5F8)[2] = value2;
    ((volatile float *)lbl_8034F5F8)[1] = value2;
    *(volatile float *)lbl_8034F604 = value1;
    ((volatile float *)lbl_8034F604)[2] = value2;
    ((volatile float *)lbl_8034F604)[1] = value2;
}

void fn_8000BD98(void) {
    return;
}

/* Handles a command/value lookup for this module. For command 0, it treats *outValue as an element in a ring buffer (lbl_8034F5D8, count lbl_8055D3E0) and replaces it with the next element; specific command IDs map to fixed output values and report handled. */
int fn_8000BD9C(int arg0, int command, int outPtr) {
    int *entry;
    int count, found, i;
    int *outValue = (int *)outPtr;

    switch (command) {
    case 0:
        entry = lbl_8034F5D8;
        count = lbl_8055D3E0;
        found = 0;
        for (i = 0; i < count; i++) {
            if (*outValue == *entry) {
                *outValue = lbl_8034F5D8[(i + 1) % count];
                found = 1;
                break;
            }
            entry++;
        }
        if (found == 0) *outValue = lbl_8034F5D8[0];
        break;
    case 0x170: *outValue = 0; return 1;
    case 0x171: *outValue = 1; return 1;
    case 0x172: *outValue = 2; return 1;
    case 0x173: *outValue = 4; return 1;
    case 0x373: *outValue = 7; return 1;
    case 0x174: *outValue = 5; return 1;
    case 0x175: *outValue = 6; return 1;
    case 0x176: *outValue = 10; return 1;
    case 0x376: *outValue = 16; return 1;
    default: break;
    }
    return 0;
}

void fn_8000BF10(int arg0, int arg1) { fn_8000BD9C(0, arg0, arg1); }

extern char lbl_802FC02C[];
extern float lbl_8055D0B4;
extern int fn_80019B3C(void);
extern int fn_80019B78(void);
extern int fn_800074C4(void);
extern int fn_8000749C(void);
extern int fn_80009C80(void);
extern int fn_80009CB8(void);
extern int fn_80009C8C(void);
extern void fn_801CB4DC(void);
extern void fn_8001EFB4(void);
#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_8000BF20(void *arg0, int arg1) {
    struct Interface {
        virtual void begin(void);
        virtual void submit(void *);
        virtual void finish(void);
    };
    unsigned char frameResult[0xA8];
    int isActive;
    int frameLimit;
    int frameCount;
    int sampleValue;

    /* Runs the main game-loop sequence: initializes state, polls/updates frames
     * until the running flag clears (or a frame limit expires), submits the
     * frame result through the optional callback interface, handles post-frame
     * transitions, and may restart; finally tears down via arg0. */
    isActive = fn_80204024();
    fn_8000AF1C(arg0);
    fn_80176780(0x1200, 0);
    if (arg1 != 0) {
        ((Interface *)arg1)->begin();
    }

restart:
    fn_80206454();
    lbl_8055D3D4 = 1;
    if (isActive == 0) {
        fn_80019B3C();
    }
    fn_80176780(0x10002, 0);

    sampleValue = fn_80019B78();
    frameLimit = ((-sampleValue | sampleValue) >> 31) & 0x1F4;
    frameCount = 0;
    fn_8000BD64();
    goto state_check;

poll:
    fn_8000BC44();
    if (*(volatile unsigned char *)&lbl_8055D3D4 != 0) {
        fn_8000B2AC();
    }
    frameCount++;
    if (frameLimit == 0 || frameCount < frameLimit) {
        goto state_check;
    }
    *(volatile unsigned char *)&lbl_8055D3D4 = 0;
state_check:
    if (*(volatile unsigned char *)&lbl_8055D3D4 != 0) {
        goto poll;
    }

    ((void (*)(int))fn_8000BD98)(frameCount);
    ((void (*)(char *, ...))fn_802E30C8)(lbl_802FC02C, lbl_8055D0B4);
    fn_8000B150(frameResult);
    if (arg1 != 0) {
        ((Interface *)arg1)->submit(frameResult);
    }

    if (frameResult[0xD] != 0 && frameResult[0xE] == 0) {
        fn_801CB4DC();
        fn_8001EFB4();
    } else {
        fn_8001EFB8();
    }

    if (fn_800074C4() != 0) {
        goto restart;
    }
    if (fn_8000749C() != 0) {
        fn_80128684();
        do {
            fn_80009C80();
        } while (fn_80009CB8() != 0);
        fn_80128678();
    }
    fn_80176780(0x1200, 0);
    if (fn_80009C8C() != 0) {
        goto restart;
    }

    if (arg1 != 0) {
        ((Interface *)arg1)->finish();
    }
    fn_8000B09C((int)arg0);
}
#pragma cplusplus reset
#pragma pop
extern void *memcpy(void *, const void *, unsigned int);
extern void fn_8000BF20(void *, int);
#pragma scheduling invalid_target
void fn_8000C0E8(void *arg0) {
    struct Header { unsigned char h0;
        unsigned char h1;
        unsigned char h2;
        unsigned char h3;
        unsigned char h4;
        unsigned char h5;
        unsigned char h6;
        unsigned char h7;
        unsigned char h8;
        unsigned char h9;
        unsigned char h10;
        unsigned char h11;
        unsigned char h12;
        unsigned char h13;
        unsigned char h14;
        unsigned char h15;
        unsigned char h16;
        unsigned char h17;
        unsigned char h18;
        unsigned char h19;
        unsigned char h20;
        unsigned char h21;
        unsigned char h22;
        unsigned char h23;
        unsigned char h24;
        unsigned char h25;
        unsigned char h26;
        unsigned char h27;
        unsigned char h28;
        unsigned char h29;
        unsigned char h30;
        unsigned char h31; };
    struct Payload { unsigned int words[0xF0]; int count; };
    struct Tail { int a, b, c, d; };
    struct Context { struct Header header; struct Payload payload; struct Tail tail; int last; } local;
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *out;
    unsigned char *rec;
    int i;
    unsigned char a, b;

    local.header = *(struct Header *)src;
    local.payload = *(struct Payload *)(src + 0x20);
    local.tail = *(struct Tail *)(src + 0x3E4);
    local.last = 1;
    local.payload.count = 1;
    out = (unsigned char *)&local;
    rec = src;
    i = 0;
    while (i < *(int *)(src + 0x3E0)) {
        if (*(volatile int *)(rec + 0x20) == 0x50) {
            *(unsigned int *)(out + 0x20) = *(unsigned int *)(rec + 0x20);
            b = rec[0x24];
            a = rec[0x25];
            out[0x24] = b;
            out[0x25] = a;
            a = rec[0x26];
            b = rec[0x27];
            out[0x26] = a;
            out[0x27] = b;
            a = rec[0x28];
            b = rec[0x29];
            out[0x28] = a;
            out[0x29] = b;
            a = rec[0x2a];
            b = rec[0x2b];
            out[0x2a] = a;
            out[0x2b] = b;
            a = rec[0x2c];
            b = rec[0x2d];
            out[0x2c] = a;
            out[0x2d] = b;
            a = rec[0x2e];
            b = rec[0x2f];
            out[0x2e] = a;
            out[0x2f] = b;
            a = rec[0x30];
            b = rec[0x31];
            out[0x30] = a;
            out[0x31] = b;
            a = rec[0x32];
            b = rec[0x33];
            out[0x32] = a;
            out[0x33] = b;
            a = rec[0x34];
            b = rec[0x35];
            out[0x34] = a;
            out[0x35] = b;
            a = rec[0x36];
            b = rec[0x37];
            out[0x36] = a;
            out[0x37] = b;
            a = rec[0x38];
            b = rec[0x39];
            out[0x38] = a;
            out[0x39] = b;
            a = rec[0x3a];
            b = rec[0x3b];
            out[0x3a] = a;
            out[0x3b] = b;
            a = rec[0x3c];
            b = rec[0x3d];
            out[0x3c] = a;
            out[0x3d] = b;
            a = rec[0x3e];
            b = rec[0x3f];
            out[0x3e] = a;
            out[0x3f] = b;
            a = rec[0x40];
            b = rec[0x41];
            out[0x40] = a;
            out[0x41] = b;
            a = rec[0x42];
            b = rec[0x43];
            out[0x42] = a;
            out[0x43] = b;
            a = rec[0x44];
            b = rec[0x45];
            out[0x44] = a;
            out[0x45] = b;
            a = rec[0x46];
            b = rec[0x47];
            out[0x46] = a;
            out[0x47] = b;
            a = rec[0x48];
            b = rec[0x49];
            out[0x48] = a;
            out[0x49] = b;
            a = rec[0x4a];
            b = rec[0x4b];
            out[0x4a] = a;
            out[0x4b] = b;
            a = rec[0x4c];
            b = rec[0x4d];
            out[0x4c] = a;
            out[0x4d] = b;
            a = rec[0x4e];
            b = rec[0x4f];
            out[0x4e] = a;
            out[0x4f] = b;
            a = rec[0x50];
            b = rec[0x51];
            out[0x50] = a;
            out[0x51] = b;
            a = rec[0x52];
            b = rec[0x53];
            out[0x52] = a;
            out[0x53] = b;
            a = rec[0x54];
            b = rec[0x55];
            out[0x54] = a;
            out[0x55] = b;
            a = rec[0x56];
            b = rec[0x57];
            out[0x56] = a;
            out[0x57] = b;
            a = rec[0x58];
            b = rec[0x59];
            out[0x58] = a;
            out[0x59] = b;
            a = rec[0x5a];
            b = rec[0x5b];
            out[0x5a] = a;
            out[0x5b] = b;
            a = rec[0x5c];
            b = rec[0x5d];
            out[0x5c] = a;
            out[0x5d] = b;
            a = rec[0x5e];
            b = rec[0x5f];
            out[0x5e] = a;
            out[0x5f] = b;
            a = rec[0x60];
            b = rec[0x61];
            out[0x60] = a;
            out[0x61] = b;
            a = rec[0x62];
            b = rec[0x63];
            out[0x62] = a;
            out[0x63] = b;
            a = rec[0x64];
            b = rec[0x65];
            out[0x64] = a;
            out[0x65] = b;
            a = rec[0x66];
            b = rec[0x67];
            out[0x66] = a;
            out[0x67] = b;
            a = rec[0x68];
            b = rec[0x69];
            out[0x68] = a;
            out[0x69] = b;
            a = rec[0x6a];
            b = rec[0x6b];
            out[0x6a] = a;
            out[0x6b] = b;
            a = rec[0x6c];
            b = rec[0x6d];
            out[0x6c] = a;
            out[0x6d] = b;
            a = rec[0x6e];
            b = rec[0x6f];
            out[0x6e] = a;
            out[0x6f] = b;
            a = rec[0x70];
            b = rec[0x71];
            out[0x70] = a;
            out[0x71] = b;
            a = rec[0x72];
            b = rec[0x73];
            out[0x72] = a;
            out[0x73] = b;
            a = rec[0x74];
            b = rec[0x75];
            out[0x74] = a;
            out[0x75] = b;
            a = rec[0x76];
            b = rec[0x77];
            out[0x76] = a;
            out[0x77] = b;
            a = rec[0x78];
            b = rec[0x79];
            out[0x78] = a;
            out[0x79] = b;
            a = rec[0x7a];
            b = rec[0x7b];
            out[0x7a] = a;
            out[0x7b] = b;
            a = rec[0x7c];
            b = rec[0x7d];
            out[0x7c] = a;
            out[0x7d] = b;
            a = rec[0x7e];
            b = rec[0x7f];
            out[0x7e] = a;
            out[0x7f] = b;
            a = rec[0x80];
            b = rec[0x81];
            out[0x80] = a;
            out[0x81] = b;
            a = rec[0x82];
            b = rec[0x83];
            out[0x82] = a;
            out[0x83] = b;
            *(unsigned int *)(out + 0x84) = *(unsigned int *)(rec + 0x84);
            *(unsigned int *)(out + 0x88) = *(unsigned int *)(rec + 0x88);
            *(unsigned int *)(out + 0x8C) = *(unsigned int *)(rec + 0x8C);
            out[0x90] = rec[0x90];
            *(unsigned int *)(out + 0x94) = *(unsigned int *)(rec + 0x94);
        }
        rec += 0x78;
        i++;
    }
    fn_8000BF20(&local, 0);
}

void fn_8000C5CC(void) {
    char sp8[0x38];

    fn_80230B5C((int *)sp8);
    fn_802C8638((int *)sp8);
    fn_802C974C(lbl_805601F8, lbl_805601FC, lbl_80560200);
    ((int (*)(int, int, const char *, ...))fn_80010074)(-0x100, 9, (const char *)&lbl_80558A48,
        lbl_805601F8, lbl_80560208, lbl_8056020C);
    fn_80011A2C();
    fn_802C9904();
}

#pragma scheduling on
int fn_8000BD9C(int, int, int);
extern float lbl_805601FC, lbl_80560204;
int fn_80230B5C(int *);
int fn_802C8638(int *);
int fn_802C974C(float, float, float);
int fn_80010074(int, int, int *, float, float, float);
int fn_80011A2C(void);
int fn_802C9904(void);
extern int lbl_80558A48;
extern float lbl_805601F8, lbl_80560200, lbl_80560208, lbl_8056020C;
void fn_8000C630(int arg0, int arg1) {
    int i;
    if (arg1 == -1) {
        i = 0;
        do {
            ((int (*)(int, int))fn_8000C630)(arg0, i);
            i++;
        } while (i < 4);
        return;
    }
    *(int *)((char *)&lbl_8034F5B8 + arg1 * 8 + 4) = arg0;
}

int *fn_8000C69C(void) {
    switch (lbl_8055D3DC) {
    case 0: return &lbl_80558A50;
    case 19: return &lbl_80558A58;
    case 20: return &lbl_80558A60;
    default: return &lbl_80558A68;
    }
}

void fn_8000C6E4(void) {
    switch ((int)lbl_8055D3DC) {
    case 0: lbl_8055D3DC = 0x14; return;
    case 20: lbl_8055D3DC = 0x13; return;
    default:
    case 19: lbl_8055D3DC = 0; return;
    }
}

void fn_8000C730(void) {
    switch ((int)lbl_8055D3DC) {
    case 0: lbl_8055D3DC = 0x13; return;
    case 19: lbl_8055D3DC = 0x14; return;
    default:
    case 20: lbl_8055D3DC = 0; return;
    }
}

