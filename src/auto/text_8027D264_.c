// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055C790;
extern void fn_8001D9B4(void *);
extern void *fn_8001285C(int);
extern void fn_80007FF0(int);
extern char lbl_80347DE8[];
extern int fn_80007F90(int);
extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_8000DBC8(void *);
extern char lbl_804B2FD8[];
extern void fn_8027D96C(int);
extern void fn_8027D9A4(int, int);
extern int fn_80128668(void);
extern int fn_8002F53C(void*, void*, void*, int, int);
extern void *__dt__Q34nw4r2ef6EffectFv_8027D434(void*, int);
extern void *fn_8027D674(void*);
extern void *fn_8027D504(void*);
extern void *fn_8027D304(void*, int);
extern void *fn_8027D39C(void *, int);
extern void fn_8027AF94(void*);
extern void fn_8001D868(int*);
extern char lbl_80347CA8[];
extern char lbl_80347CC0[];
extern char lbl_80347CF8[];
extern char lbl_804A4380[];
extern void *fn_8027B60C(void *);
extern void fn_8002F634(void *, void *, int, int);
extern void *fn_8027D280(void *, int);
extern int fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(int);
extern void fn_8027E0C8(void *, int);
extern unsigned char lbl_8055F66C;
extern void fn_8027B834(void);
typedef struct Ent_8027DB40 { const char *name; int id; int val; } Ent_8027DB40;
typedef struct VTbl_8027DB40 { void *s[3]; void (*add)(void *, int, int, int); } VTbl_8027DB40;
typedef struct Obj_8027DB40 { VTbl_8027DB40 *vt; } Obj_8027DB40;
extern int fn_80019714(void);
extern int fn_80018FB4(void);
extern Ent_8027DB40 *fn_80019054(int);
extern int fn_80019088(void);
extern int fn_80016604(int);
extern int *fn_8001668C(int, int);
extern int fn_80018FA8(int);
extern int fn_80019144(int);
extern int fn_800194CC(void);
extern int fn_80019534(void);
extern int fn_80019604(void);
extern int fn_80019664(void);
extern int stricmp(const char *, const char *);
extern char lbl_8055C794[8];
void fn_8027DE68(void);
extern void *fn_8025007C(int);
extern void fn_8027B94C(void);
#pragma scheduling invalid_target
void fn_8027D264(void) {
    fn_8002F634(lbl_804A4380, fn_8027D280, 0x3B10, 4);
}
#pragma scheduling on
void *fn_8027D280(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8002F634((char *)arg0 + 0x2370, fn_8027D304, 0xBD0, 2);
        fn_8002F634(arg0, fn_8027D304, 0xBD0, 3);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma scheduling on
void *fn_8027D304(void *arg0, int arg1) {
    struct Local {
        void *field_00;
        int field_04;
        int field_08;
        int field_0C;
        int field_10;
        int field_14;
    };
    struct Local *obj = (struct Local *)arg0;
    if (arg0 != 0) {
        obj->field_00 = lbl_80347CA8;
        fn_8027B60C(obj);
        if (&obj->field_08 != 0) {
            fn_8002F634((char *)obj + 0x14, fn_8027D39C, 0x1F4, 6);
            if (&obj->field_08 != 0) {
                obj->field_08 = 0;
                obj->field_0C = 0;
                obj->field_10 = 0;
            }
        }
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(obj);
    }
    return obj;
}

void fn_8027B288(void *);
void *fn_8027D39C(void *arg0, int arg1) {
    struct Local {
        void *vtable;
        char pad[0x14];
        int field_18;
        int field_1C;
        int field_20;
    };
    struct Local *obj = (struct Local *)arg0;
    if (arg0 != 0) {
        obj->vtable = lbl_80347CC0;
        fn_8027B288(obj);
        if (&obj->field_18 != 0) {
            fn_8002F634((char *)obj + 0x24, __dt__Q34nw4r2ef6EffectFv_8027D434, 0x3C, 6);
            if (&obj->field_18 != 0) {
                obj->field_18 = 0;
                obj->field_1C = 0;
                obj->field_20 = 0;
            }
        }
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(obj);
        }
    }
    return obj;
}

void *__dt__Q34nw4r2ef6EffectFv_8027D434(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_80347CF8;
        fn_8027AF94(arg0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void *fn_8027D494(void *arg0) {
    fn_8002F53C(arg0, fn_8027D504, fn_8027D304, 0xBD0, 3);
    fn_8002F53C((char *)arg0 + 0x2370, fn_8027D504, fn_8027D304, 0xBD0, 2);
    return arg0;
}

void *fn_8027D5B8(void *);
void *fn_8027D504(void *arg0) {
    struct Local {
        void *field_00;
        int field_04;
        void *field_08;
        int field_0C;
        int field_10;
    };
    struct Local *obj = (struct Local *)arg0;
    obj->field_00 = lbl_80347CA8;
    obj->field_04 = 0;
    obj->field_0C = 0;
    obj->field_08 = (char *)arg0 + (unsigned short)0x14;
    obj->field_10 = 6;
    fn_8002F53C((char *)arg0 + 0x14, fn_8027D5B8, fn_8027D39C, 0x1F4, 6);
    return arg0;
}

int fn_8027D578(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma scheduling invalid_target
void *fn_8027D5B8(void *arg0) {
    int *temp_r6;
    *(void **)arg0 = lbl_80347CC0;
    temp_r6 = (int *)((char *)arg0 + 0x24);
    *(int **)((char *)arg0 + 0x18) = temp_r6;
    *(int *)((char *)arg0 + 0x20) = 6;
    *(int *)((char *)arg0 + 0x1C) = 0;
    fn_8002F53C(temp_r6, fn_8027D674, __dt__Q34nw4r2ef6EffectFv_8027D434, 0x3C, 6);
    *(char *)((char *)arg0 + 4) = 0;
    return arg0;
}
#pragma scheduling on
int fn_8027D634(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void *fn_8027D674(void *arg0) {
    char *p = (char *)arg0;
    *(void **)p = lbl_80347CF8;
    p[4] = 0;
    fn_8001D868((int *)(p + 0x14));
    return arg0;
}

int fn_8027D6BC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_8027D6FC(void *arg0) {
    void *res = fn_8001285C(*(int *)((char *)arg0 + 0xC));
    void *obj = *(void **)((char *)res + 0x20);
    if ((*(int (**)(void *, int))(*(char **)obj + 0xC))(obj, (int)&lbl_8055C77C) != 0) {
        obj = *(void **)((char *)res + 0x20);
        fn_80008188((*(int (**)(void *, int))(*(char **)obj + 0x14))(obj, (int)&lbl_8055C774));
    } else {
        fn_80008188(fn_80012820(*(int *)((char *)res + 4)) + 8);
    }
}

#pragma cplusplus on
extern "C" void fn_8027D77C(void *arg0) {
    struct Input {
        char pad[0xC];
        int id;
    };
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(int);
    };
    void *res = fn_8001285C(((Input *)arg0)->id);
    void *obj = *(void **)((char *)res + 0x20);
    ((Obj *)obj)->v3((int)&lbl_8055C784);
}
#pragma scheduling invalid_target
extern "C" void fn_8027D7B8(void *arg0) {
    fn_80007F90(*(int *)((char *)fn_8001285C(((int *)arg0)[3]) + sizeof(int) * 2));
}

#pragma scheduling invalid_target
extern "C" void fn_8027D7E4(void *arg0) {
    fn_80007FF0(*(int *)((char *)fn_8001285C(((int *)arg0)[3]) + sizeof(int) * 2));
}
#pragma scheduling on
extern "C" void fn_8027D810(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(int);
    };
    void *res = fn_8001285C(*(volatile int *)((char *)arg0 + 0xC));
    void *obj = *(void **)((char *)res + 0x20);
    ((Obj *)obj)->v3((int)lbl_80347DE8);
}
#pragma cplusplus off
#pragma scheduling on
int fn_8027D850(void *arg0) {
    return *(int *)((char *)arg0 + 0x34);
}

typedef int (*Fn8027D858)(void *, int);
#pragma cplusplus on
extern "C" int fn_8027D858(void *arg0) {
    class Obj {
    public:
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
        virtual int v10(int);
    };
    if (*(unsigned char *)((char *)arg0 + 0x38) != 0) {
        return ((Obj *)arg0)->v10(*(int *)((char *)arg0 + 0x34));
    }
    return -1;
}
#pragma cplusplus off
void fn_8027D880(void *arg0) {
    fn_8001D9B4((char *)arg0 + 0x14);
}

extern void fn_8001DA48(void *);
void fn_8027D888(void *arg0) {
    fn_8001DA48((char *)arg0 + 0x14);
}

int fn_8027D890(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D898(void *arg0) { return *(int *)((char *)arg0 + 0x30); }

int fn_8027D8A0(void *arg0) {
    return *(int *)((char *)arg0 + 0x28);
}

#pragma cplusplus on
extern "C" void fn_8027D8A8(void *arg0) {
    class Obj {
    public:
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
        virtual int v12();
    };
    int value = ((Obj *)arg0)->v12();
    ((int (*)(void *, int))fn_8001DA48)((char *)arg0 + 0x14, value);
}
#pragma cplusplus off
int fn_8027D8EC(void *arg0) { return *(int *)((char *)arg0 + 0x2C); }

int fn_8027D8F4(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D8FC(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8027D904(void *arg0) { return *(int *)((char *)arg0 + 0x14); }

int fn_8027D90C(void *arg0) { return *(int *)((char *)arg0 + 0x1C); }

int fn_8027D914(void *arg0, int arg1) {
    return ((int *)arg0)[6] + arg1 * 0x3C;
}

unsigned char fn_8027D924(void *arg0) {
    return ((unsigned char *)arg0)[0x1F0];
}

unsigned char fn_8027D92C(void *arg0) { return ((unsigned char *)arg0)[0x1F1]; }

unsigned char fn_8027D934(void *arg0) { return ((unsigned char *)arg0)[0x1F2]; }

unsigned char fn_8027D93C(void *arg0) {
    return ((unsigned char *)arg0)[0x1F3];
}

int fn_8027D944(int arg0) {
    return arg0 + 0x18C;
}

int fn_8027D94C(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D954(void *arg0, int arg1) {
    return ((int *)arg0)[2] + arg1 * 0x1F4;
}

unsigned char fn_8027D964(void *arg0) { return ((unsigned char *)arg0)[0xBCC]; }

void fn_8027D96C(int arg0) {
    if (arg0 == 1) {
        return;
    }
    if (arg0 < 1) {
        if (arg0 < 0) {
            return;
        }
    } else if (arg0 >= 3) {
        return;
    }
    memset(lbl_804B2FD8, 0, 0x20);
}

  extern char lbl_804B2FD8[];
  extern int memset(void *, int, unsigned int);
  extern char lbl_80347DF8[];
  extern void fn_802E30C8(char *, ...);
void fn_8027D9A4(int arg0, int arg1) {
    if (arg1 != 0) {
        return;
    }
    fn_802E30C8(lbl_80347DF8, arg0);
    memset(lbl_804B2FD8 + arg0 * 8, 0, 8);
}

__declspec(section ".data") extern char lbl_804B2FD8[];
void fn_8027DA08(void) {
 int sp14,sp10,spC,sp8;
 int *entry;
 int value;
 int i1;
 int total;
 int weight;
 int i2;
 int index;
 index=fn_8000DA10()<<3;
 entry=(int *)((char *)&lbl_804B2FD8+index);
 entry[0]=0;
 i1=0;
 do { fn_8027BCC0(i1,&sp14,&sp10); entry[0]+=sp14; i1++; } while(i1<3);
 total=0; weight=0; i2=0;
 do { fn_8027BCC8(i2,&spC,&sp8); i2++; total+=spC; weight+=sp8; } while(i2<3);
 value=total*100/weight;
 value &= (-value & ~value)>>31;
 if(value>=100) value=100;
 entry[1]=value;
}

extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_802E6BD8(int, int, void *, int, void *);
extern void fn_8000DBC8(void *);
extern void fn_8027D96C(int);
extern void fn_8027D9A4(int, int);
void fn_8027DAF4(void) {
    fn_802E6BD8(0x50435252, 1, &lbl_804B2FD8, 0x20, fn_8027D96C);
    fn_8000DBC8(fn_8027D9A4);
}

#pragma use_lmw_stmw off
void *fn_8027DB40(int arg0) {
    int flagA;
    int bit2;
    int i;
    int cnt;
    Ent_8027DB40 *e;
    int bit1Zero;
    int limit;
    int filtered;
    int bit1;
    Obj_8027DB40 *obj;
    int *info;
    int b, c;

    flagA = arg0 & 1;
    bit1 = (arg0 >> 1) & 1;
    bit2 = (arg0 >> 2) & 1;
    if (fn_80019714() != 0) {
        flagA = 1;
    }
    limit = fn_80018FB4();
    filtered = 0;
    if (flagA == 0 && ((int (*)(int))fn_8027DE68)(0) == 0) {
        filtered = 1;
    }
    cnt = 0;
    for (i = 0; i < fn_80019088(); i++) {
        e = fn_80019054(i);
        if ((filtered == 0 || e->val <= limit) && e != 0 && stricmp(e->name, lbl_8055C794) == 0
            && fn_80016604(e->id) > 0) {
            cnt++;
        }
    }
    if (fn_800194CC() != 0) {
        cnt++;
    }
    if (fn_80019604() != 0) {
        cnt++;
    }
    obj = (Obj_8027DB40 *)fn_8025007C(cnt);
    bit1Zero = (bit1 == 0);
    for (i = 0; i < fn_80019088(); i++) {
        e = fn_80019054(i);
        if ((filtered == 0 || e->val <= limit) && e != 0 && stricmp(e->name, lbl_8055C794) == 0
            && fn_80016604(e->id) > 0) {
            info = fn_8001668C(e->id, 0);
            bit1 = 1;
            if (flagA == 0 && fn_80018FA8(e->id) == 0) {
                bit1 = 0;
            }
            b = 0;
            if (!(info[0xA0 / 4] & 2) && info[8 / 4] != info[4 / 4]) {
                b = 1;
            }
            if (bit1 == 0 && bit2 != 0) {
                continue;
            }
            c = 0;
            if (b != 0 && (flagA != 0 || (bit1Zero != 0 && fn_80019144(e->id) != 0))) {
                c = 1;
            }
            obj->vt->add(obj, e->id, bit1, c);
        }
    }
    if (fn_800194CC() != 0) {
        obj->vt->add(obj, fn_80019534(), 1, 0);
    }
    if (fn_80019604() != 0) {
        obj->vt->add(obj, fn_80019664(), 1, 0);
    }
    return obj;
}
void fn_8027DDCC(int arg0) {
    int oldState;
    int state;
    lbl_8055F66C = 1;
    oldState = fn_80012810();
    if (oldState != 0x130) {
        if (oldState != 0x134) fn_80012794();
        fn_80012790(0x130);
    }
    fn_8027E0C8(fn_8027B834, arg0);
    lbl_8055F66C = 0;
    state = fn_80012810();
    if (oldState != state) {
        if (state != 0x134) fn_80012794();
        if (oldState != 0x134) fn_80012790(oldState);
    }
}

void fn_8027DE68(void) {
    fn_8027B94C();
}

void fn_8027DE6C(void) {
    fn_8027B77C();
    fn_8027BF38();
    fn_8027B690();
    fn_8027DA08();
}

#pragma dont_inline on
int fn_8027DE98(int index) {
    return *(int *)((char *)&lbl_804B2FD8 + index * 8);
}
#pragma dont_inline reset

void fn_8027DEAC(void* alarm) {
    fn_8027DE98(fn_8000DA10(alarm));
}

void* fn_8027DED0(void) {
    return lbl_8055C790;
}

void fn_8027DED8(void) {
}

extern void *fn_8027DB40(int);
extern void *fn_8025007C(int);
extern int fn_8024DAE0(int, int, int, void *, int);
extern char lbl_80347E30[];
extern char lbl_80347E40[];
#pragma push
#pragma use_lmw_stmw off
int fn_8027DEDC(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int result;
    void *obj;
    int found;
    void *manager;

    fn_800167FC(1);
    manager = (void *)fn_80012820(arg2);
    found = 0;
    if (manager != 0) {
        obj = *(void **)((char *)manager + 0x80);
        if (obj != 0) {
            result = ((int (*)(void *, const char *))*(void **)((char *)*(void **)obj + 0x5C))(obj, lbl_80347E30);
            if (((unsigned int)(-result | result) >> 31) != 0) {
                obj = *(void **)((char *)manager + 0x80);
                obj = (void *)((int (*)(void *, const char *))*(void **)((char *)*(void **)obj + 0x5C))(obj, lbl_80347E30);
                found = ((int (*)(void *, const char *, int))*(void **)((char *)*(void **)obj + 0x18))(obj, lbl_80347E40, 0);
            }
        }
    }
    if (found == 0) {
        manager = fn_8027DB40(0);
    } else {
        manager = fn_8025007C(1);
        ((void (*)(void *, int, int, int))*(void **)((char *)*(void **)manager + 0xC))(manager, found, 1, 0);
    }
    result = fn_8024DAE0(arg0, arg1, 0, manager, arg3);
    if (manager != 0) {
        ((void (*)(void *, int))*(void **)((char *)*(void **)manager + 8))(manager, 1);
    }
    return result;
}

void *fn_80012870(int, int);
void fn_8023BF4C(void *);
void fn_8027E024(int arg0, int arg1, int arg2) {
    struct Args {
        int list;
        int found;
        int arg2;
        int arg0;
    } args;
    int index;
    int key = arg1;
    void *result;

    result = fn_8001285C(arg1);
    args.list = *(int *)((char *)result + 4);
    args.found = -1;
    index = *(int *)((char *)((void *(*)(int))fn_80012820)(args.list) + 0x70);
    goto test;
loop:
    if (key != *(int *)fn_80012870(args.list, index)) {
        goto test;
    }
    args.found = index;
test:
    if (index-- > 0) {
        goto loop;
    }
    args.arg2 = arg2;
    args.arg0 = arg0;
    fn_8023BF4C(&args);
}

extern void *fn_80016464(int arg0);
extern void *fn_80016510(void *arg0);
extern void *fn_80016544(int arg0);
extern void fn_80016970(int arg0, int arg1, int arg2, int arg3);
extern int fn_8000DA10(void);
extern void fn_8000DB34(void);
extern void fn_800169F8(int arg0);
extern void fn_802E4A10(void);
extern void fn_80137C84(int arg0);
extern void fn_8001FD4C(int arg0);
extern void fn_80016A44(int arg0);
extern void fn_802840F4(void);
extern void fn_802840F8(void);
extern int fn_802840FC(int *arg0, void *arg1, unsigned char *arg2);
extern int fn_8027BAB8(void *arg0);
extern int fn_80019098(void *arg0);
extern int fn_8001931C(void *arg0);
extern int fn_800194C8(void);
extern int fn_800195C0(void);
extern void fn_8001EFB0(int *arg0);
extern void fn_80284580(int arg0, int arg1, void *arg2, int *arg3);
extern void fn_8025A204(void);
extern void fn_8001EFBC(void);
extern void fn_802E7128(void);
void fn_8027E0C8(void *arg0, int arg1) {
    int v28b;
    int v20b;
    int v48;
    int v40;
    int info;
    int a19604;
    int bab1;
    int i17;
    void *list;
    int v22;
    int v21;
    int v20;
    int v19;
    int flag18;
    int a194CC;
    int idx16;
    int idx14;
    int spE8;
    unsigned char buf[0xB0];
    unsigned char frame[0x14];
    int z20;
    int z1C;
    int z18;
    int key;
    int sp10;
    int spC;
    void *cb;
    int sel;
    void *item;
    int tmp27;
    int flag29;
    int cnt30;
    void *obj29;
    int diff;
    int a19604new;
    cb = arg0;
    key = -1;
    spE8 = *(int *)((char *)fn_80016464(0) + 4);
    sp10 = *(int *)((char *)fn_80016510(*(void **)((char *)fn_80016464(0) + 0x4C)) + 4);
    spC = *(int *)((char *)fn_80016464(0) + 0x50);
    list = ((void *(*)(int))cb)(arg1);
    fn_802840F4();
    memset(frame, 0, 0x14);
retry:
    memset(frame, 0, 0x14);
    if (((int (*)(int *, int *, int, int))fn_8027DEDC)(&sp10, &spC, *(int *)((char *)fn_8001285C(key) + 4), arg1) == 0) {
        goto retry;
    }
    idx14 = -1;
    idx16 = -1;
    v22 = 0;
    v21 = 0;
    v20 = 0;
    v19 = 0;
    flag18 = 1;
    for (i17 = 0; i17 < ((int (*)(void *))*(void **)((char *)*(void **)list + 0xC))(list); i17++) {
        item = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, i17);
        bab1 = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x20))(item);
        flag18 = (flag18 != 0 && bab1 != 0) ? 1 : 0;
        for (a19604 = 0; a19604 < ((int (*)(void *))*(void **)((char *)*(void **)item + 0x18))(item); a19604++) {
            tmp27 = (int)((void *(*)(void *, int))*(void **)((char *)*(void **)item + 0x1C))(item, a19604);
            if (key == ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x20))((void *)tmp27)) {
                idx14 = i17;
                idx16 = a19604;
                v22 = ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x40))((void *)tmp27);
                v21 = ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x48))((void *)tmp27);
                v20 = bab1;
                v19 = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x28))(item);
            }
        }
    }
    item = (void *)((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x28))((void *)tmp27);
    bab1 = fn_8027BAB8(list);
    info = (int)fn_80016544(sp10);
    flag29 = 0;
    tmp27 = !(*(int *)((char *)info + 0xA0) & 2);
    if (tmp27 != 0 && fn_80019144(info + 0x2C) != 0) {
        flag29 = 1;
    }
    a194CC = fn_800194CC();
    a19604 = fn_80019604();
    fn_802840F8();
    fn_80016970(0, spE8, sp10, spC);
    fn_8000DA10();
    ((void (*)(int, int))fn_800169F8)(((int (*)(void))fn_8000DB34)(), 0);
    ((void (*)(int, int))fn_80137C84)(((int (*)(void))fn_802E4A10)(), 0);
    fn_8001FD4C(((int (*)(int))fn_8027DE68)(0) == 0);
    if (((int (*)(void *))*(void **)((char *)*(void **)item + 0x20))(item) != 0) {
        sel = 0;
    } else {
        sel = ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x38))((void *)tmp27);
    }
    lbl_8055C790 = (void *)sel;
    memset(buf, 0, 0xB0);
    fn_8027E024((int)buf, key, arg1);
    lbl_8055C790 = (void *)-1;
    fn_80016A44(0);
    fn_8001FD4C(0);
    list = ((void *(*)(int))cb)(arg1);
    fn_802840F4();
    if (((int *)buf)[2] > 0) {
        fn_8027DA08();
        tmp27 = ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x28))((void *)tmp27);
        cnt30 = 0;
        if (tmp27 != 0 && fn_80019144(info + 0x2C) != 0) {
            cnt30 = 1;
        }
        z18 = 0;
        z1C = 0;
        z20 = 0;
        fn_8001EFB0(&z18);
        obj29 = fn_8025007C(2);
        if (flag29 == 0 && cnt30 != 0) {
            ((void (*)(void *, int, int, int))*(void **)((char *)*(void **)obj29 + 0xC))(obj29, fn_80019098((char *)info + 0x2C), 1, 0);
            info = fn_8001931C((char *)info + 0x2C);
            ((void (*)(void *, int, int))*(void **)((char *)*(void **)obj29 + 0x10))(obj29, ((int (*)(void *))*(void **)((char *)*(void **)obj29 + 0x14))(obj29) - 1, info);
        }
        if (a194CC == 0 && fn_800194C8() != 0) {
            ((void (*)(void *, int, int, int))*(void **)((char *)*(void **)obj29 + 0xC))(obj29, fn_80019534(), 1, 0);
            a194CC = fn_800195C0();
            ((void (*)(void *, int, int))*(void **)((char *)*(void **)obj29 + 0x10))(obj29, ((int (*)(void *))*(void **)((char *)*(void **)obj29 + 0x14))(obj29) - 1, a194CC);
        }
        fn_80284580(z1C, z20, obj29, &spC);
        if (obj29 != 0) {
            ((void (*)(void *, int))*(void **)((char *)*(void **)obj29 + 8))(obj29, 1);
        }
        fn_8025A204();
        fn_8001EFBC();
        if (((int (*)(void *))*(void **)((char *)*(void **)list + 0x14))(list) != 0) {
            v40 = ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x40))((void *)tmp27);
            v48 = ((int (*)(void *))*(void **)((char *)*(void **)(tmp27) + 0x48))((void *)tmp27);
            v20b = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x20))(item);
            v28b = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x28))(item);
            idx14 = fn_8027BAB8(list);
            a194CC = 1;
            for (idx16 = 0; idx16 < ((int (*)(void *))*(void **)((char *)*(void **)list + 0xC))(list); idx16++) {
                item = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx16);
                bab1 = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x20))(item);
                a194CC = (a194CC != 0 && bab1 != 0) ? 1 : 0;
            }
            a19604new = fn_80019604();
            diff = (int)item - tmp27;
            *(int *)(frame + 4) = diff;
            *(int *)(frame + 8) = key;
            frame[0] = (diff > 0) ? 1 : 0;
            frame[0xC] = (v22 == 0 && v40 != 0) ? 1 : 0;
            frame[0xD] = (v21 == 0 && v48 != 0) ? 1 : 0;
            frame[0xE] = (v20 == 0 && v20b != 0) ? 1 : 0;
            frame[0xF] = (v19 == 0 && v28b != 0) ? 1 : 0;
            frame[0x10] = (flag18 == 0 && a194CC != 0) ? 1 : 0;
            frame[0x11] = (bab1 == 0 && idx14 != 0) ? 1 : 0;
            frame[0x12] = (a19604 == 0 && a19604new != 0) ? 1 : 0;
        }
    }
    fn_802E7128();
    if (fn_802840FC(&key, list, frame) != 0) {
        goto retry;
    }
    fn_802840F8();
}

#pragma pop

