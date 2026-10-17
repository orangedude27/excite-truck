// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80208408(void);
extern void fn_80208858(void);
extern signed long fn_80128668(void);
extern void* fn_802090B4(void);
extern signed long fn_802E317C(const char*, ...);
extern signed long fn_8026A344(signed long);
extern signed long fn_80206570(signed long);
extern int __cntlzw(unsigned int);

typedef struct SoundMgrObj {
    char pad0[0x10];
    signed long field_10;
    char pad14[0x34];
    signed long field_44;
    char pad48[0x20];
    float field_68;
} SoundMgrObj;

typedef struct SoundMgr {
    char pad0[0xc];
    void** list;
    char pad10[0x4];
    signed long count;
} SoundMgr;

typedef struct Vt_80207960 {
    void (*f0)(void);
    void (*f1)(void*, signed long);
    void (*f2)(void*);
} Vt_80207960;

void fn_80207960(void) {
	return;
}

signed long fn_80207964(signed long arg0) {
    if (arg0 != 0) {
        goto nonzero;
    }
    return 1;
nonzero:
    return 0;
}

void fn_80207980(void* arg0) {
    *(signed long*)arg0 = 0;
    *((signed long*)arg0 + 1) = 0;
}

extern void fn_80207DE0(void*);
extern void fn_802E30C8(const char*, ...);
extern void fn_80128670(void);
extern void fn_80127E28(void*);
extern char lbl_8033BE08[];
extern char lbl_8033BEE8[];
void* fn_80207B60(void* arg0, signed long arg1) {
    signed long i;
    signed long offset;
    void* obj;
    if (arg0 == 0) return arg0;
    *(void**)arg0 = lbl_8033BEE8;
    fn_80207DE0(arg0);
    i = 0; offset = 0;
    while (i < *(signed long*)((char*)arg0 + 0x10)) {
        fn_802E30C8(lbl_8033BE08, *(signed long*)((char*)*(void***)((char*)arg0 + 0xC) + offset) + 0x37);
        offset += 4; i++;
    }
    if (*(void**)((char*)arg0 + 0xC) != 0) {
        fn_80128670();
        *(void**)((char*)arg0 + 0xC) = 0;
    }
    obj = *(void**)((char*)arg0 + 0x90);
    *(signed long*)((char*)arg0 + 0x10) = 0;
    if (obj != 0) (*(void (**)(void*))(*(void**)(*(char**)obj + 0x24)))(obj);
    fn_80127E28(arg0);
    *(char*)((char*)arg0 + 4) = 0;
    if (arg1 > 0) fn_80128668();
    return arg0;
}

void fn_80207C48(void) {
	return;
}

void fn_80207C4C(void) {
	return;
}

void fn_80207C50(void* arg0, void* arg1, signed long arg2) {
    signed long c = *((signed long*)arg1 + 2);
    signed long b = *((signed long*)arg1 + 1);
    signed long a = *(signed long*)arg1;
    void* dst = (void*)((char*)arg0 + arg2 * 0xC);
    *(signed long*)((char*)dst + 0x5C) = a;
    *(signed long*)((char*)dst + 0x60) = b;
    *(signed long*)((char*)dst + 0x64) = c;
}

void fn_80207C74(void* arg0, signed long arg1) {
    *(signed long*)((char*)arg0 + 0x8C) = arg1;
}

void fn_80207C7C(void) {
	return;
}

void fn_80207E70(void* arg0);

void fn_80207C80(void* arg0) {
    signed long i = 0;
    signed long offset = 0;
    while (i < *(signed long*)((char*)arg0 + 0x10)) {
        fn_802067C8(*(signed long*)((char*)*(void***)((char*)arg0 + 0xC) + offset),
                    (char*)arg0 + 0x5C, *(signed long*)((char*)arg0 + 0x8C));
        offset += 4;
        i += 1;
    }
    fn_8020835C(arg0);
    fn_80207F34(arg0);
    i = 0;
    offset = 0;
    while (i < *(signed long*)((char*)arg0 + 0x10)) {
        fn_80206824(*(signed long*)((char*)*(void***)((char*)arg0 + 0xC) + offset),
                    (char*)arg0 + 0x5C, *(signed long*)((char*)arg0 + 0x8C));
        offset += 4;
        i += 1;
    }
    fn_8020815C(arg0);
    fn_80207E70(arg0);
}

signed long fn_80207D40(void* arg0) {
    signed long temp_r3;

    temp_r3 = fn_802E2C20();
    if ((signed long)(temp_r3 - *(signed long*)(((signed char*)arg0) + 8)) <= 0x10) {
        return 0;
    }
    *(signed long*)(((signed char*)arg0) + 8) = temp_r3;
    return 1;
}

void fn_80207D8C(void* arg0) { if (fn_80207D40(arg0)) { fn_80207C80(arg0); (*(void (**)(void*, void*))(*(void***)((char*)arg0 + 0x90)))(*(void**)((char*)arg0 + 0x90), (char*)arg0 + 0x5C); } }

extern void fn_80207C80(void*);
extern void* lbl_802F9DC8[];
extern char lbl_8033BE20[];
void fn_80207DE0(void* arg0) {
    void* var_r28;
    void* var_r30;
    signed long var_r29;
    signed long var_r31;
    void* temp_vt;
    signed long temp_arg;

    var_r31 = 0;
    var_r29 = 0;
    var_r28 = arg0;
    var_r30 = var_r28;
    temp_vt = 0;
    temp_arg = 1;
    while (var_r29 < *(signed long*)(((signed char*)var_r28) + 0x114)) {
        void** temp_r3 = (void**)((signed char*)var_r30 + 0x94);
        if (*temp_r3 != 0) {
            temp_vt = *temp_r3;
            (*(void(**)(signed long))((void**)temp_vt)[2])(temp_arg);
        }
        *temp_r3 = (void*)var_r31;
        var_r30 = (void*)(((signed char*)var_r30) + 4);
        var_r29 += 1;
    }
    *(signed long*)(((signed char*)var_r28) + 0x114) = 0;
}

extern void* memmove(void*, const void*, unsigned long);
void fn_80207E70(void* arg0) {
    void* cur;
    void* dst;
    void* src;
    signed long i;
    void* base;
    void* temp;
    void* sub;
    void* vt;
    signed long temp_r5;
    base = arg0;
    cur = base;
    src = (char*)base + 0x98;
    dst = (char*)base + 0x94;
    i = 0;
    while (i < *(signed long*)((char*)base + 0x114)) {
        temp = *(void**)((char*)cur + 0x94);
        sub = *(void**)((char*)temp + 0xC);
        vt = *(void**)sub;
        if (((signed long (**)(void*))((char*)vt + 0x24))[0](sub) == 3) {
            temp = *(void**)((char*)cur + 0x94);
            if (temp != 0) {
                vt = *(void**)temp;
                ((void (**)(void*, signed long))((char*)vt + 0x8))[0](temp, 1);
            }
            temp_r5 = *(signed long*)((char*)base + 0x114) - 1;
            *(signed long*)((char*)base + 0x114) = temp_r5;
            memmove(dst, src, (unsigned long)(temp_r5 - i) * 4);
        } else {
            cur = (char*)cur + 4;
            src = (char*)src + 4;
            dst = (char*)dst + 4;
            i++;
        }
    }
}

void fn_80208404(void) {

}

void fn_802085E8(void) {
	fn_80208408();
}

void fn_80208994(void) {
	fn_80208858();
}

void fn_80208998(void) {
	fn_80208858();
}

void fn_8020899C(void* arg0, void* arg1) {
    typedef struct {
        char pad[0xc];
        void (*f)(void*);
    } Vt;
    ((Vt*)*(void**)arg1)->f(arg1);
}

void fn_802089B0(void* self) {
    typedef struct {
        char pad[0x8];
        void (*f)(void*, signed long);
    } Vt;
    if (self == 0) {
        return;
    }
    ((Vt*)*(void**)self)->f(self, 1);
}

signed long fn_802089D0(signed long arg0, signed long arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        fn_80128668();
    }
    return arg0;
}

void fn_802085EC(void) {
	fn_80208408();
}

signed long fn_802085F0(void* arg0, signed long x) {
    switch (x) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            return 1;
        default:
            return 0;
    }
}

