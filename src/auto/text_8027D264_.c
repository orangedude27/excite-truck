// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055C790;
extern void fn_8001D9B4(void *);
extern void *fn_8001285C(int);
extern int lbl_80347DE8;
extern int fn_80007F90(int);
extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_8000DBC8(void *);
extern void fn_8027D96C(void);
extern void fn_8027D9A4(int, int);
extern int fn_80128668(void);
extern int fn_8002F53C(void*, void*, void*, int, int);
extern void *__dt__Q34nw4r2ef6EffectFv_8027D434(void*, int);
extern void *fn_8027D674(void*);
extern void *fn_8027D504(void*);
extern void *fn_8027D304(void*, int);
extern void fn_8027D39C(void);
extern void fn_8027AF94(void*);
extern void fn_8001D868(int*);
extern char lbl_80347CA8[];
extern char lbl_80347CC0[];
extern char lbl_80347CF8[];
extern void *lbl_804A4380;
extern void *fn_8027B60C(void *);
extern void fn_8002F634(void *, void *, int, int);
extern void *fn_8027D280(void *, int);
extern int fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(int);
extern void fn_8027E0C8(void *, int);
extern unsigned char lbl_8055F66C;
extern void fn_8027B834(void);
extern void fn_8027B94C(void);
void fn_8027D264(void) {
    fn_8002F634((char *)&lbl_804A4380, fn_8027D280, 0x3B10, 4);
}

#pragma scheduling invalid_target
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

int fn_8027D578(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void* fn_8027D5B8(void* arg0) {
    int* temp_r6 = (int*)((char*)arg0 + 0x24);
    *(void**)arg0 = lbl_80347CC0;
    *(int**)((char*)arg0 + 0x18) = temp_r6;
    *(int*)((char*)arg0 + 0x20) = 6;
    *(int*)((char*)arg0 + 0x1C) = 0;
    fn_8002F53C(temp_r6, fn_8027D674, __dt__Q34nw4r2ef6EffectFv_8027D434, 0x3C, 6);
    *(char*)((char*)arg0 + 4) = 0;
    return arg0;
}

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
    if ((*(int (**)(void *, int))(*(void ***)obj + 3))(obj, (int)&lbl_8055C77C) != 0) {
        obj = *(void **)((char *)res + 0x20);
        fn_80008188((*(int (**)(void *, int))(*(void ***)obj + 5))(obj, (int)&lbl_8055C774));
    } else {
        fn_80008188(fn_80012820(*(int *)((char *)res + 4)) + 8);
    }
}

void fn_8027D77C(void *arg0) {
    void *res = fn_8001285C(*(int *)((char *)arg0 + 0xC));
    void *obj = *(void **)((char *)res + 0x20);
    (*(void (**)(void *, int))(*(void ***)obj + 5))(obj, (int)&lbl_8055C784);
}

#pragma scheduling push
#pragma scheduling off
void fn_8027D7B8(void *arg0) {
    fn_80007F90(*(int *)((char *)fn_8001285C(((int *)arg0)[3]) + sizeof(int) * 2));
}
#pragma scheduling pop
void fn_8027D810(void *arg0) {
    int id = *(int *)((char *)arg0 + 0xC);
    void *res = fn_8001285C(id);
    void *p = *(void **)((char *)res + 0x20);
    (*(void (**)(void *, int))(*(char **)p + 0x14))(p, (int)&lbl_80347DE8);
}

int fn_8027D850(void *arg0) {
    return *(int *)((char *)arg0 + 0x34);
}

typedef int (*Fn8027D858)(void *, int);
int fn_8027D858(void *arg0) {
    if (*((unsigned char *)arg0 + 0x38) != 0) {
        Fn8027D858 fn = ((Fn8027D858 *)*(void **)arg0)[12];
        int arg1 = *(int *)((char *)arg0 + 0x34);
        return fn(arg0, arg1);
    }
    return -1;
}

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

extern void *lbl_804B2FD8;
extern int memset(void *, int, unsigned int);
extern char lbl_80347DF8[];
extern void fn_802E30C8(char *, int);
void fn_8027D9A4(int arg0, int arg1) {
    if (arg1 != 0)
        return;
    fn_802E30C8(lbl_80347DF8, arg0);
    memset((char *)&lbl_804B2FD8 + arg0 * 8, 0, 8);
}

__declspec(section ".data") extern void *lbl_804B2FD8;
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
extern void fn_8027D96C(void);
extern void fn_8027D9A4(int, int);
void fn_8027DAF4(void) {
    fn_802E6BD8(0x50435252, 1, &lbl_804B2FD8, 0x20, fn_8027D96C);
    fn_8000DBC8(fn_8027D9A4);
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
#pragma pop

