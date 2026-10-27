// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8033BF18[];
extern char lbl_8033C058[];
extern char lbl_8055B4F0;
extern void *lbl_8055B4D8;
extern int lbl_8055B4DC;
extern char lbl_8055B4E8;
extern void *fn_801284F8(int, void *);
extern void fn_8000DBC8(void *);
extern void *fn_802E9A14(void);
extern void fn_8020A72C(void);
extern int fn_8013365C(int, int);
extern void *memset(void *, int, unsigned int);

extern float lbl_8055B4D0;
extern float lbl_8055B4D4;
extern float fn_80208A18(float);
extern char lbl_80489258[];

extern float lbl_80563230;
extern float lbl_80563234;
extern void fn_80208A50(float *);

extern void *lbl_8055EDA8;
extern int lbl_80489238[4];
extern char lbl_8033BEF8[];
extern char lbl_8033BF08[];
extern char lbl_8055B4E0;
extern void fn_801331C4(int, void *, float *);
extern void fn_8013323C(int, void *, float);
extern void fn_801332D0(int, void *, void *);
extern void fn_80209030(float);
extern void fn_80209090(int);
#pragma scheduling invalid_target
#pragma push
#pragma inline_depth(0)
float fn_80208A18(float value) {
    struct Entry {
        float value;
        int id;
    };
    struct State {
        struct Entry entries[8];
        int count;
    };
    struct State *state = (struct State *)lbl_80489258;
    int count = state->count;
    int i;

    for (i = 0; i < count; i++) {
        if (state->entries[i].id != 0) {
            value *= state->entries[i].value;
        }
    }
    return value;
}

void fn_80208A50(float *arg0) {
    lbl_8055B4D4 = fn_80208A18(lbl_8055B4D0);
}

void fn_80208A78(void) {
    fn_801331C4(4, lbl_8033BEF8, &lbl_8055B4D0);
    fn_80209030(lbl_8055B4D0);
    fn_801332D0(4, &lbl_8055B4E0, &lbl_8055EDA8);
    fn_80209090((int)lbl_8055EDA8);
}

#pragma pop

void fn_80208AC8(int arg0, int arg1) {
    float value = lbl_80563230;
    switch (arg1) {
    case 3:
        fn_801331C4(arg0 + 12, lbl_8033BF08, &value);
        fn_8013323C(4, lbl_8033BEF8, value);
        fn_80209030(value);
        break;
    case 1:
    case 2:
        fn_801331C4(4, lbl_8033BEF8, &value);
        fn_8013323C(arg0 + 12, lbl_8033BF08, value);
        break;
    case 0:
        fn_8013323C(4, lbl_8033BEF8, value);
        fn_80209030(value);
        break;
    }
}
#pragma scheduling default
int fn_80208CFC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80208D3C(void) { return lbl_80489238[6]; }

int fn_80208D4C(int index) { return lbl_80489238[index]; }

void fn_80208D60(int arg0) { lbl_80489238[7] = arg0; }

int fn_80208D70(void) { return lbl_80489238[7]; }

extern const char lbl_8033BF28[];
extern char lbl_8055B4E8;
extern int lbl_8055B4DC;
extern void fn_802E317C(const char *, ...);
extern void fn_80133348(int, void *, int);
extern void fn_801336E0(int, void (*)(void));
#pragma scheduling default
#pragma cplusplus on
extern "C" const char lbl_8033BF28[];
extern "C" char lbl_8055B4E8;
extern "C" int lbl_8055B4DC;
extern "C" void fn_802E317C(const char *, ...);
extern "C" void fn_80133348(int, void *, int);
extern "C" void fn_801336E0(int, void (*)(void));
#pragma cplusplus reset
#pragma scheduling default
#pragma cplusplus on
extern "C" void fn_80208D80(int arg0) {
    char *entry = lbl_80489258;
    int enabled;
    int index = 0;
    int index2;
    struct Table {
        void *entries[6];
        int count;
        int value;
    };
    struct Table *base;
    void **items;
    void *object;

    while (index < *(int *)(lbl_80489258 + 0x40)) {
        enabled = *(int *)(entry + 4);
        if (enabled != 0) {
            fn_802E317C(lbl_8033BF28, enabled);
        }
        entry += 8;
        index++;
    }

    if (arg0 != 0) {
        items = (void **)lbl_80489238;
        base = (struct Table *)items;
        for (index2 = 0; index2 < base->count; items++, index2++) {
            object = *items;
            if (object != 0) {
                struct Dummy {
                    virtual void call(int);
                };
                ((struct Dummy *)object)->call(1);
            }
        }
    }

    fn_80133348(4, &lbl_8055B4E8, ((struct Table *)lbl_80489238)->value);
    fn_8013323C(4, lbl_8033BEF8, lbl_8055B4D0);
    fn_80133348(4, &lbl_8055B4E0, (int)lbl_8055EDA8);
    fn_801336E0(lbl_8055B4DC, fn_80208A78);
}
#pragma cplusplus reset
float fn_80209028(void) {
    return lbl_8055B4D4;
}

#pragma scheduling invalid_target
#pragma push
#pragma inline_depth(0)
void fn_80209030(float arg0) {
    float value = lbl_80563230 < arg0 ? lbl_80563230 : arg0;
    value = value > lbl_80563234 ? value : lbl_80563234;
    lbl_8055B4D0 = value;
    fn_8013323C(4, lbl_8033BEF8, (float)(double)value);
    ((void (*)(void))fn_80208A50)();
}
#pragma pop
#pragma scheduling on
void fn_80209090(int arg0) {
    if (arg0 >= 0 && arg0 <= 2) {
        lbl_8055EDA8 = (void *)arg0;
        return;
    }
    lbl_8055EDA8 = 0;
}

void* fn_802090B4(void) {
    return lbl_8055EDA8;
}

extern void fn_802E30C8(const char *, ...);
extern const char lbl_8033C024[];
#pragma scheduling invalid_target
void fn_802090BC(void) {
    fn_802E30C8(lbl_8033C024);
}
extern void *lbl_8055B4D8;
void* fn_802090CC(void) {
    return lbl_8055B4D8;
}

void *fn_802090D4(int arg0)
{
  struct Entry
  {
    float value;
    int id;
  };
  struct State
  {
    struct Entry entries[8];
    int count;
  };
  struct State *state = (struct State *) lbl_80489258;
  int index = state->count;
  void *result;
  result = 0;
  if (((unsigned int) state->count) < 8U)
  {
    state->count = state->count + 1;
    if (1)
    {
    }
    result = ((char *) state) + (index * 8);
    *((int *) (((char *) result) + 4)) = arg0;
    *((float *) (((char *) state) + (index * 8))) = lbl_80563230;
  }
  if (result)
  {
    return result;
  }
  else
  {
    return result;
  }
}

void fn_80209110(void **arg0) {
    void *entry = *arg0;
    int i;
    if (entry != 0) {
        *(int *)((char *)entry + 4) = 0;
        for (i = *(int *)(lbl_80489258 + 0x40); i > 0; i = *(int *)(lbl_80489258 + 0x40)) {
            if (*(int *)(lbl_80489258 + i * 8 - 4) != 0)
                break;
            *(int *)(lbl_80489258 + 0x40) = i - 1;
        }
        fn_80208A50(0);
        *arg0 = 0;
    }
}

#pragma push
#pragma inline_depth(0)
void fn_80209190(float *arg0, float arg1) {
    if (arg0 != 0) {
        float value = lbl_80563230 < arg1 ? lbl_80563230 : arg1;
        value = value > lbl_80563234 ? value : lbl_80563234;
        *arg0 = value;
        fn_80208A50(arg0);
    }
}
#pragma pop

extern float lbl_80563230;
extern float lbl_80563234;
extern float fn_80208A18(float);
extern void fn_80208A50(float *);
extern int fn_80128668(void);
#pragma push
#pragma inline_depth(0)
void fn_802091CC(void) {
    fn_80208A18(lbl_80563230);
}
#pragma pop

int fn_802091D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80209214(void) {
    return 0;
}

extern float lbl_8055B4D0;
extern void fn_801332D0(int, void *, void *);
#pragma scheduling invalid_target
int fn_8020921C(void) {
    struct Config { int value; unsigned int pad; unsigned int version; };
    extern struct Config lbl_8048929C;
    extern unsigned int lbl_8055E044;
    extern void fn_80131318(void);
    unsigned int version;
    volatile struct Config *config;
    config = &lbl_8048929C;
    version = config->version;
    if (version != lbl_8055E044)
        fn_80131318();
    config = &lbl_8048929C;
    return config->value;
}
#pragma scheduling default
int fn_80209260(int arg0) { return arg0 + 4; }

int fn_80209268(void) { return 1; }

int fn_80209270(void) { return 1; }

void fn_80209278(void) {

}

void fn_8020927C(void) {

}

extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
void fn_80209280(void) {
    struct Obj { void *vtable; int pad; int value; };
    struct Obj *obj = (struct Obj *)fn_801284F8(12, lbl_8033C1C0);
    if (obj) {
        obj->vtable = lbl_8033C0E8;
        obj->value = 3;
    }
}

int fn_802092C8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80209308(void) { return 1; }

extern int fn_802E2C20(void);
void fn_80209310(void *arg0) {
    *(int *)((char *)arg0 + 4) = fn_802E2C20();
    *(int *)((char *)arg0 + 8) = 1;
}

void fn_80209348(void *arg0) {
    *(int *)((char *)arg0 + 4) = fn_802E2C20();
    *(int *)((char *)arg0 + 8) = 1;
}

void fn_80209380(void *arg0) {
    *(int *)((char *)arg0 + 8) = 3;
}

void fn_8020938C(void *arg0) {
    *(int *)((char *)arg0 + 8) = 2;
}

void fn_80209398(void *arg0) {
    *(int *)((char *)arg0 + 8) = 1;
}

int fn_802093A4(void *arg0) {
    if (*(int *)((char *)arg0 + 4) + 0x7D0 < fn_802E2C20()) {
        *(int *)((char *)arg0 + 8) = 3;
    }
    return *(int *)((char *)arg0 + 8);
}

void fn_802093EC(void) {

}

void fn_802093F0(void) {

}

void fn_802093F4(void) {

}

void fn_802093F8(void) {

}

int fn_802093FC(void) {
    return 0;
}

void fn_80209404(void) {

}

void fn_80209408(void) {

}

void fn_8020940C(void) {

}
extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
