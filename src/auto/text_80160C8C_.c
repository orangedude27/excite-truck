// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 fn_8000DA10(void);
extern void fn_801332D0(s32, s32, s32 *);
extern void fn_80160CF4(void);
extern s32 lbl_8055A0B0;
extern s32 lbl_8055A0B4;
extern s32 lbl_8055A0B8;
extern s32 lbl_8055A0C0;
extern u8 lbl_8055E2DC;

extern s32 fn_80161E40(s32);

extern int lbl_8032F698;
extern void *lbl_8055E2E0;
extern int fn_801476C4(void);
extern float lbl_8056185C;
extern float lbl_8055E3C8;
extern float lbl_80561868;
extern int fn_80161BB8(void);
extern unsigned char lbl_8032FCB0[];
extern int lbl_804348E8[];
extern float lbl_80561848;
extern unsigned char lbl_8042FDEC[0x10];
extern int lbl_8055E304;
extern s32 lbl_8055A0E0;
extern s32 lbl_8055A0E8;
extern u8 lbl_8055E2DD;

#pragma cplusplus on
struct Dummy_801619A8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
#pragma cplusplus off

extern s32 lbl_8055E300;
extern unsigned char lbl_8032F858[];
extern int lbl_8055E2E4;
extern int lbl_8055E2E8;
extern int lbl_8055E2EC;
extern int lbl_8055E2F0;
extern int lbl_8055E2F4;
extern int lbl_8055E2F8;
extern int lbl_8055E2FC;
extern unsigned char lbl_8032F588[];
extern void *fn_80145E70(void *);
extern void *fn_802CAC28(void *, int);
extern void *fn_8023512C(void *);
void* fn_80160C8C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_80160CE4(void) {
    return lbl_8055A0B8 - lbl_8055A0C0;
}

void *fn_801612BC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u32)arg0 + 0xE0 != 0) {
            if ((u32)arg0 + 0xE0 != 0) {
                ((s32 *)arg0)[56] = 0;
                ((s32 *)arg0)[57] = 0;
                ((s32 *)arg0)[58] = 0;
            }
        }
        if (arg0 != 0) {
            if ((u32)arg0 + 0x34 != 0) {
                if ((u32)arg0 + 0x34 != 0) {
                    ((s32 *)arg0)[13] = 0;
                    ((s32 *)arg0)[14] = 0;
                    ((s32 *)arg0)[15] = 0;
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_80161340(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u32)arg0 + 0x34 != 0) {
            if ((u32)arg0 + 0x34 != 0) {
                ((s32 *)arg0)[13] = 0;
                ((s32 *)arg0)[14] = 0;
                ((s32 *)arg0)[15] = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_801613A0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_801615B4(s32 arg0) {
    s32 total = 0;
    s32 i = 0;
    goto test;
body:
    fn_80161E40(i);
    total = total + fn_8016208C();
    i = i + 1;
test:
    if (i < arg0) goto body;
    return total;
}

void fn_80161618(void) {
    s32 offset;
    s32 i;
    s32 value;
    void *item;
    value = fn_8000DA10();
    lbl_8055A0B8 = 1;
    fn_801332D0(value + 0xC, lbl_8055A0B0, &lbl_8055A0B8);
    lbl_8055E2DC = 0;
    lbl_8055A0B4 = lbl_8055A0B8;
    lbl_8055E2DD = 0;
    fn_80160CF4();
    if (*(s32 *)(lbl_8042FDEC + 4) > 1) {
        lbl_8055E304 = 0;
        lbl_8055E300 = **(s32 **)lbl_8042FDEC;
    } else {
        lbl_8055E300 = 0;
        lbl_8055E304 = -1;
    }
    i = 0;
    offset = 0;
    while (i < *(s32 *)(lbl_8042FDEC + 4)) {
        item = *(void **)(*(s32 *)lbl_8042FDEC + offset);
        ((void (*)(void *))(*(void ***)item)[3])(item);
        offset += 4;
        i++;
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_801617BC(void) {
    s32 offset, i;
    s32 *count;
    void *item;
    register void **vtable;
    lbl_8055E2E0 = fn_80145E70(lbl_8032F588 + 0x11C);
    lbl_8055E2E4 = (int)fn_80145E70(lbl_8032F588 + 0x12C);
    lbl_8055E2E8 = (int)fn_802CAC28(lbl_8032F588 + 0x138, 0);
    lbl_8055E2EC = (int)fn_802CAC28(lbl_8032F588 + 0x148, 0);
    lbl_8055E2F0 = (int)fn_802CAC28(lbl_8032F588 + 0x158, 0);
    lbl_8055E2F4 = (int)fn_802CAC28(lbl_8032F588 + 0x168, 0);
    lbl_8055E2F8 = (int)fn_802CAC28(lbl_8032F588 + 0x178, 0);
    lbl_8055E2FC = (int)fn_8023512C(lbl_8032F588 + 0x188);
    count = (s32 *)(lbl_8042FDEC + 4);
    i = 0; offset = 0;
    while (i < *count) {
        item = *(void **)(*(s32 *)lbl_8042FDEC + offset);
        vtable = *(void ***)item;
        ((void (*)(void *))vtable[5])(item);
        offset += 4; i++;
    }
}
#pragma pop
extern s32 lbl_8055A0B0;
extern s32 lbl_8055A0B8;
#pragma cplusplus on
extern "C" void fn_801619A8(void) {
    s32 index = lbl_8055E304;
    if (index >= 0 && index < *(s32 *)(lbl_8042FDEC + 4)) {
        lbl_8055E300 = *(s32 *)(*(char **)lbl_8042FDEC + index * 4);
    }
    if (lbl_8055E300 != 0) {
        ((Dummy_801619A8 *)lbl_8055E300)->f7();
    }
    lbl_8055E2DD = 0;
}
#pragma cplusplus off
void fn_80161A18(void) {
    if (lbl_8055E300 != 0) {
        void **vtable = *(void ***)lbl_8055E300;
        void (*fn)(void) = (void (*)(void))vtable[7];
        fn();
    }
}

void fn_80161A38(s32 arg0, s32 arg1, s32 arg2) {
    register s32 a0 = arg0;
    register s32 a1 = arg1;
    register s32 a2 = arg2;
    if (lbl_8055E300 != 0) {
        ((void (*)(void *, s32, s32, s32))(*(void ***)lbl_8055E300)[0x40 / 4])((void *)lbl_8055E300, a0, a1, a2);
    }
}

s32 fn_80161A70(void) {
    if (lbl_8055E300 != 0) {
        if (((s32 (*)(void))(*(void ***)lbl_8055E300)[9])() != 0) {
            return ((s32 (*)(void *, s32))(*(void ***)lbl_8055E300)[18])((void *)lbl_8055E300, 0);
        }
        return ((s32 (*)(void *, s32))(*(void ***)lbl_8055E300)[17])((void *)lbl_8055E300, 0);
    }
    return 0;
}

void fn_80161AEC(void) {
    if (lbl_8055E300 != 0) {
        void * volatile *vtable = (void * volatile *)*(void ***)lbl_8055E300;
        ((void (*)(void))vtable[0x4C / 4])();
    }
}

s32 fn_80161B0C(void) {
    s32 result = 0;
    if (lbl_8055E300 != 0) {
        typedef struct { void *pad[12]; s32 (*method)(void); } Vtable;
        Vtable *vtable = *(Vtable **)lbl_8055E300;
        if (vtable->method() != 0) {
            if (lbl_8055E2DD == 0) {
                fn_800121A4();
            }
            *(volatile u8 *)&lbl_8055E2DD = 0;
            result = 1;
        }
    }
    return result;
}

f32 fn_80161B70(void) {
    if (lbl_8055E300) {
        volatile void **vtable = *(volatile void ***)lbl_8055E300;
        volatile f32 (*fn)(void *) = (volatile f32 (*)(void *))vtable[13];
        return fn((void *)lbl_8055E300);
    }
    return lbl_80561848;
}

s32 fn_80161B94(void) {
    if (lbl_8055E300 != 0) {
        volatile void * volatile *vptr = (volatile void * volatile *)lbl_8055E300;
        volatile void **vt = (volatile void **)*vptr;
        s32 (*fn)(void *) = (s32 (*)(void *))vt[11];
        return fn((void *)lbl_8055E300);
    }
    return 0;
}

s32 fn_80161BDC(s32 a, s32 b, s32 c) {
    register s32 arg0 = a;
    register s32 arg1 = b;
    register s32 arg2 = c;
    if (lbl_8055E300 != 0) {
        return (*(s32 (**)(void *, s32, s32, s32))(*(char **)lbl_8055E300 + 0x3c))((void *)lbl_8055E300, arg0, arg1, arg2);
    }
    return 0;
}

void fn_80161C18(void) {
    void *obj = (void *)lbl_8055E300;
    if (obj != 0) {
        void (*call)(void) = *(void (**)(void))((char *)*(void **)obj + 0x58);
        call();
    }
}

s32 fn_80161C38(void) {
    s32 val = lbl_8055E300;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}

s32 fn_80161C4C(void) {
    void *obj = (void *)lbl_8055E300;
    void **vtable;
    s32 (*fn)(void);
    if (obj != 0) {
        vtable = *(void ***)obj;
        fn = (s32 (*)(void))vtable[0x50 / 4];
        return fn();
    }
    return 1;
}

s32 fn_80161C70(void) {
    void *obj = (void *)lbl_8055E300;
    if (obj != 0) {
        return ((s32 (*)(void))(*(void ***)obj)[0x54 / 4])();
    }
    return 1;
}

s32 fn_80161D14(void) {
    s32 sp8;
    s32 temp = fn_8000DA10();
    sp8 = 1;
    fn_801332D0(temp + 0xC, lbl_8055A0B0, &sp8);
    return sp8;
}

#pragma dont_inline on
void fn_80161DE4(void) {
    s32 total = fn_801615B4(fn_80161ECC() - 1);
    fn_80161E40(fn_80161ECC() - 1);
    total += fn_8016208C();
    fn_80133348(fn_8000DA10() + 0xC, lbl_8055A0B0, total + 1);
}
#pragma dont_inline reset
int fn_80161ECC(void) {
    int i = 0;
    do {
        i++;
    } while (fn_80161E40(i) >= 0);
    return i;
}

#pragma push
#pragma use_lmw_stmw off
extern s32 fn_8000DB34(void);
extern void *fn_8001285C(void);
extern void *fn_80016464(s32);
extern void *fn_800165DC(s32);
extern void *fn_8001668C(s32);
extern s32 fn_80016544(s32);
extern s32 fn_800169F8(s32);
extern s32 fn_80016970(s32, s32, s32, s32);
extern s32 fn_8001EFC8(void);
extern s32 fn_80137C78(s32);
extern s32 fn_80137C80(s32);
extern s32 fn_80137C84(s32);
extern s32 fn_801615B4(s32);
extern s32 fn_80161D14(void);
extern s32 fn_8023BEC4(s32, void *);
extern s32 fn_802E4A10(void);
extern s32 fn_802E7128(void);
extern int lbl_8032F744;
extern int lbl_8032F750;
extern s32 lbl_8055A0BC;
extern s32 lbl_8055A0C0;
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_80161F10(s32 arg0, s32 arg1) {
    s32 pad[2];
    s32 *manager;
    s32 *item;
    s32 selection;
    s32 index;
    s32 value;
    void *obj;
    void *subobj;
    register void *label1 = &lbl_8032F744;
    register void *label2 = &lbl_8032F750;

    fn_80161D14();
    value = fn_80161E40(arg0);
    obj = fn_8001285C();
    fn_80137C78(1);
    fn_802E4A10();
    fn_80137C84(0);
    manager = *(s32 **)((char *)fn_80016464(0) + 4);
    item = *(s32 **)((char *)fn_800165DC((s32)manager) + 4);
    subobj = *(void **)((char *)obj + 0x20);
    if (((s32 (*)(void *, void *))(*(void **)(*(void ***)subobj + 3)))(subobj, label1)) {
        subobj = *(void **)((char *)obj + 0x20);
        ((void (*)(void *, void *))(*(void **)(*(void ***)subobj + 5)))(subobj, label1);
        item = *(s32 **)((char *)fn_8001668C(0) + 4);
    }
    selection = *(s32 *)((char *)fn_80016464((s32)manager) + 0x50);
    subobj = *(void **)((char *)obj + 0x20);
    if (((s32 (*)(void *, void *))(*(void **)(*(void ***)subobj + 3)))(subobj, label2)) {
        subobj = *(void **)((char *)obj + 0x20);
        index = ((s32 (*)(void *, void *))(*(void **)(*(void ***)subobj + 7)))(subobj, label2);
        selection = *(s32 *)((char *)fn_80016544((s32)item) + index * 4 + 0x64);
    }
    fn_8000DA10();
    fn_8000DB34();
    fn_800169F8(0);
    fn_80016970(0, (s32)manager, (s32)item, selection);
    lbl_8055A0BC = arg0;
    lbl_8055A0C0 = fn_801615B4(arg0);
    fn_8023BEC4(value, &pad[0]);
    lbl_8055A0BC = -1;
    lbl_8055A0C0 = -1;
    fn_80137C80(0);
    fn_8001EFC8();
    fn_80161D14();
    fn_802E7128();
}
#pragma dont_inline reset
#pragma pop

#pragma push
#pragma use_lmw_stmw off
int fn_8016208C(void) {
    extern void *fn_8001285C();
    extern int stricmp(const char *, const char *);
    extern char lbl_8032F5DC[];
    int count = 0, i = 0;
    void *mgr = fn_8001285C(), *iter;
    do {
        void *obj = *(void **)((char *)mgr + 0x20);
        void **vt = *(void ***)obj;
        iter = ((void *(*)(void *, int))vt[0x60 / 4])(obj, i++);
        if (iter != 0) {
            void **ivt = *(void ***)iter;
            const char *name = ((const char *(*)(void *))ivt[2])(iter);
            if (stricmp(name, lbl_8032F5DC) == 0) count++;
        }
    } while (iter != 0);
    return count;
}
#pragma pop
void fn_8016212C(void) {
    fn_801613E0();
}

int fn_80162130(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_80162170(void) {

}

void fn_80162174(void) {
}

void fn_801F62178_dummy(void);
void fn_80162178(void *arg0, int arg1) {
    extern float lbl_8056184C;
    extern int fn_80161438;
    extern void fn_801DF380(int, int *, int);
    int count;
    int offset;
    *(int *)((char *)arg0 + 8) = 0;
    *(unsigned char *)((char *)arg0 + 0x10) = 0;
    *(float *)((char *)arg0 + 0xC) = lbl_8056184C;
    for (count = 0, offset = 0; count < *(int *)((char *)arg0 + 0x38); count++, offset += 8) {
        void *obj = *(void **)((char *)arg0 + 4);
        void **vt = *(void ***)obj;
        ((void (*)(void *, long *, long *))vt[3])(obj, &lbl_8055A0E0, &lbl_8055A0E8);
        {
            int *entry = (int *)(*(char **)((char *)arg0 + 0x34) + offset);
            fn_801DF380(entry[0], &fn_80161438, entry[1]);
        }
    }
}

void fn_80162214(void) {
    if (fn_801C5B60() == 0) {
        fn_801DF074(8, 0);
    }
}

int fn_80162248(void) {
    return 0;
}

int fn_80162250(void) {
    return 0;
}

void fn_80162258(void) {

}

void fn_8016225C(void) {
}

int fn_80162260(void) {
    return 0;
}

extern f64 fn_8002F234(f32);
extern f32 PSVECSquareDistance(void *, void *);
extern s32 fn_80139B5C(void *, s32);
extern void *fn_801B83A0(void);
extern f32 lbl_80561840, lbl_80561850, lbl_80561854, lbl_80561858;
extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
void fn_80162268(void *arg0) {
    u8 *self = arg0;
    s32 i,j,offset;
    int *cars;
    u8 *car,*entry,*flags,*ui;
    f32 velocity[2], length, scale;
    f32 one, threshold, epsilon;
    if (fn_801C5B60() == 0) fn_801DF074(8,0);
    if (((s32 (*)(void *))(*(void ***)self)[9])(self) == 0) {
        one=lbl_80561840; threshold=lbl_80561854; epsilon=lbl_80561850;
        for (i=0,cars=lbl_804348E8; i<fn_801B2F24(); i++,cars++) {
            car=(u8 *)*cars;
            if (*(u32 *)(car+0x10) != 0x50434152) continue;
            for (j=0,offset=0; j<*(s32 *)(self+0xE4); j++,offset+=0x48) {
                entry=*(u8 **)(self+0xE0)+offset;
                if (!entry[0x3C]) continue;
                if (*(s32 *)(entry+0x34)) {
                    if (fn_80139B5C(car,*(s32 *)(entry+0x34))) {
                        flags=entry+i;
                        if (!flags[0x3D]) {
                            velocity[0]=*(f32 *)(car+0x118);
                            velocity[1]=*(f32 *)(car+0x120);
                            length=velocity[0]*velocity[0]+velocity[1]*velocity[1];
                            if (length>epsilon) {
                                scale=one/(f32)fn_8002F234(length);
                                velocity[0]*=scale;
                                velocity[1]*=scale;
                                if (velocity[0]* *(f32 *)(entry+0x2C)+velocity[1]* *(f32 *)(entry+0x30)>threshold) {
                                    ++*(s32 *)(self+0x94);
                                    entry[0x3C]=0;
                                    ui=*(u8 **)(self+0xDC);
                                    ui[0x49]=1; ui[0x4B]=0; ui[0x4A]=0;
                                }
                            }
                        }
                        flags[0x3D]=1;
                        break;
                    } else if (entry[0x3C]) (entry+i)[0x3D]=0;
                } else if (PSVECSquareDistance(entry,car+0x60)<*(f32 *)(self+0xCC)* *(f32 *)(self+0xCC)) {
                    ++*(s32 *)(self+0x94);
                    entry[0x3C]=0;
                    ui=*(u8 **)(self+0xDC);
                    ui[0x49]=1; ui[0x4B]=0; ui[0x4A]=0;
                    break;
                }
            }
        }
        *(f32 *)(self+0x98)+=lbl_80561858;
        if (*(f32 *)(self+0x98)>=*(f32 *)(self+0x84))
            ((void (*)(void *,s32))(*(void ***)self)[24])(self,3);
        if (*(s32 *)(self+0x94)>=*(s32 *)(self+0x80) && self[0x9C]) {
            ((void (*)(void *,s32))(*(void ***)self)[24])(self,1);
            self[0x88]=1;
        }
    } else {
        if ((f32)__fabs(*(f32 *)(self+0x8C))<=lbl_80558DC4) {
            fn_80276DC8(0);
            for(i=0,cars=lbl_804348E8;i<fn_801B2F24();i++,cars++) {
                void *manager=fn_801B83A0();
                ((void (*)(void *,s32,s32))(*(void ***)manager)[37])(manager,*cars,i);
            }
        }
        *(f32 *)(self+0x8C)+=lbl_80561858;
        if(self[0x90]) {
            if (((s32 (*)(void *))(*(void ***)self)[10])(self) && lbl_8055E304==fn_80160CE4()) {
                lbl_8055E2DC=1;
                lbl_8055A0B4=lbl_8055A0B8++;
            } else lbl_8055E2DC=0;
            lbl_8055E304=0;
            if (*(s32 *)(lbl_8042FDEC+4)>0) fn_80176734();
        }
    }
}
#pragma pop
s32 fn_80162734(void *arg0) { return *(s32 *)((u8 *)arg0 + 8) != 0; }

s32 fn_80162748(void *arg0) { return *(s32 *)((u8 *)arg0 + 8) == 1; }

void fn_8016275C(void *arg0, s32 arg1, s32 arg2) {
    if (((s32 (*)(void))(*(void ***)arg0)[0x24 / 4])() != 0)
        goto done;
    if (arg1 == 0) {
        if (((s32 *)lbl_804348E8[arg2])[4] == (s32)0x50434152) {
            ((void (*)(void *, s32))(*(void ***)arg0)[0x60 / 4])(arg0, 2);
            *((u8 *)arg0 + 0x91) = 1;
        }
    } else {
        goto done;
    }
done:
    ;
}

#pragma push
#pragma small_data off
extern int lbl_8032FA38;
extern int lbl_8032FA44;
#pragma pop
extern int lbl_8055E2F8;
extern int lbl_8055A0EC;
extern int lbl_8055A0DC;
extern int fn_801476D8(int, int, int);
extern void fn_80130980(void *, int, int, float);
extern void fn_801475D0(void *, ...);
#pragma push
#pragma small_data off
#pragma processor 750
#pragma use_lmw_stmw off
s32 fn_80162800(void *arg0) {
    s32 sp8;
    s32 pad[2];
    f32 limit = lbl_8055E3C8;
    if (limit > ((f32 (*)(void *))(*(void ***)arg0)[0x34 / 4])(arg0)) {
        if (((s32 (*)(void *))(*(void ***)arg0)[0x28 / 4])(arg0) == 0) {
            ((s32 (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x10 / 4])(lbl_8055E2E0, (void *)&lbl_8032FA38);
            ((void (*)(void *, s32, s32))fn_801476D8)(0, -1, lbl_8055E2F8);
            ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x0C / 4])(lbl_8055E2E0, (void *)&lbl_8032FA44);
            fn_801476C4();
            fn_80130980(&sp8, 0x14, 3, *(f32 *)((char *)arg0 + 0x84) - *(f32 *)((char *)arg0 + 0x98));
            ((void (*)(void *, s32, s32, void *))fn_801475D0)(lbl_8055E2E0, lbl_8055A0EC, lbl_8055A0DC, &sp8);
        }
    }
    return 0;
}
#pragma pop
extern int lbl_8032F698;
extern void *lbl_8055E2E0;
extern int fn_801476C4(void);
s32 fn_801628E8(void *arg0) {
    if (*(f32 *)((u8 *)arg0 + 0x8C) > lbl_8056185C) {
        ((void (*)(int *))(*(void ***)lbl_8055E2E0)[0xC / 4])(&lbl_8032F698);
        fn_801476C4();
    }
    return 1;
}

void *fn_80162938(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = (void *)lbl_8032F858;
        *((void **)arg0 + 0x56C / 4) = (void *)(lbl_8032F858 + 0x68);
        if ((u32)arg0 + 0x56C != 0) {
            if ((u32)arg0 + 0x56C != 0) {
                fn_8015857C((char *)arg0 + 0x56C);
            }
        }
        if ((u32)arg0 + 0x570 != 0) {
            if ((u32)arg0 + 0x570 != 0) {
                *(s32 *)((char *)arg0 + 0x570) = 0;
                *(s32 *)((char *)arg0 + 0x574) = 0;
                *(s32 *)((char *)arg0 + 0x578) = 0;
            }
        }
        if (arg0 != 0) {
            if ((u32)arg0 + 0xE0 != 0) {
                if ((u32)arg0 + 0xE0 != 0) {
                    *(s32 *)((char *)arg0 + 0xE0) = 0;
                    *(s32 *)((char *)arg0 + 0xE4) = 0;
                    *(s32 *)((char *)arg0 + 0xE8) = 0;
                }
            }
            if (arg0 != 0) {
                if ((u32)arg0 + 0x34 != 0) {
                    if ((u32)arg0 + 0x34 != 0) {
                        *(s32 *)((char *)arg0 + 0x34) = 0;
                        *(s32 *)((char *)arg0 + 0x38) = 0;
                        *(s32 *)((char *)arg0 + 0x3C) = 0;
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_80162FE8(void *arg0) {
    f32 temp_f31;
    temp_f31 = *((f32 *)((char *)arg0 + 0x5B8));
    if ((*((s32 (**)(void))((char *)*(void ***)arg0 + 0x28)))() != 0) {
        return *((f32 *)((char *)arg0 + 0x5B4)) > temp_f31;
    }
    return *((s32 *)((char *)arg0 + 8)) != 0;
}

s32 fn_80163058(void *arg0) { return *(s32 *)((u8 *)arg0 + 8) == 1; }

void fn_8016306C(void *arg0, s32 arg1, s32 arg2) {
    if (((s32 (*)(void *))(*(void ***)arg0)[9])(arg0) == 0) {
        switch (arg1) {
        case 2: ((s32 (*)(void *, s32, s32, s32))(*(void ***)arg0)[29])(arg0, 0x10, arg2, 5); break;
        case 1: ((s32 (*)(void *, s32, s32, s32))(*(void ***)arg0)[29])(arg0, 0x11, arg2, 5); break;
        case 3: ((s32 (*)(void *, s32, s32, s32))(*(void ***)arg0)[29])(arg0, 0x12, arg2, 5); break;
        case 4: ((s32 (*)(void *, s32, s32, s32))(*(void ***)arg0)[29])(arg0, 0x13, arg2, 5); break;
        }
    }
    if (((s32 (*)(void *))(*(void ***)arg0)[9])(arg0) == 0 && arg1 == 0) {
        if (((char *)lbl_804348E8[arg2])[0x10] == 'CARP') {
            ((void (*)(void *, s32))(*(void ***)arg0)[24])(arg0, 2);
            *((u8 *)arg0 + 0x91) = 1;
        }
    }
}

#pragma push
#pragma processor 750
s32 fn_801631E0(void *arg0) {
    s32 sp8;
    f32 limit = lbl_8055E3C8;
    if (limit > ((f32 (*)(void *))(*(void ***)arg0)[0x34 / 4])(arg0)) {
        if (((s32 (*)(void *))(*(void ***)arg0)[0x28 / 4])(arg0) == 0) {
            ((s32 (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x10 / 4])(lbl_8055E2E0, &lbl_8032FA38);
            fn_801476D8(0, -1, lbl_8055E2F8);
            ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x0C / 4])(lbl_8055E2E0, &lbl_8032FA44);
            fn_801476C4();
            fn_80130980(&sp8, 0x14, 3, *(f32 *)((char *)arg0 + 0x84) - *(f32 *)((char *)arg0 + 0x98));
            fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, &sp8);
        }
    }
    return 0;
}
#pragma pop

s32 fn_801634F0(void *arg0) {
    s32 result = 0;
    if (((s32 (*)(void *))(*(s32 (**)(void *))(*(char **)arg0 + 0x24)))(arg0) != 0 && *((u8 *)arg0 + 0x90) != 0) result = 1;
    return result;
}

void *fn_80163658(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if ((u32)arg0 + 0xE0 != 0) {
                if ((u32)arg0 + 0xE0 != 0) {
                    ((s32 *)arg0)[56] = 0;
                    ((s32 *)arg0)[57] = 0;
                    ((s32 *)arg0)[58] = 0;
                }
            }
            if (arg0 != 0) {
                if ((u32)arg0 + 0x34 != 0) {
                    if ((u32)arg0 + 0x34 != 0) {
                        ((s32 *)arg0)[13] = 0;
                        ((s32 *)arg0)[14] = 0;
                        ((s32 *)arg0)[15] = 0;
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

u8 fn_80163864(void *arg0) {
    return *((u8 *)arg0 + 0x56C);
}

void fn_8016386C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 == 5 && *((u8 *)arg0 + 0x56D) == 0) {
        if (arg3 >= *((s32 *)((char *)arg0 + 0x570))) {
            *((u8 *)arg0 + 0x56C) = 1;
        }
        *((u8 *)arg0 + 0x56D) = 1;
    }
}

#pragma push
#pragma processor 750
s32 fn_80163C38(void *arg0) {
    s32 sp8;
    s32 pad[4];
    f32 limit;
    void **vtable;
    pad[0] = 0;
    if (*((u8 *)arg0 + 0x56D) == 0) {
        vtable = *(void ***)arg0;
        limit = lbl_8055E3C8;
        if (limit > ((f32 (*)(void *))vtable[0x34 / 4])(arg0)) {
            vtable = *(void ***)arg0;
            if (((s32 (*)(void *))vtable[0x28 / 4])(arg0) == 0) {
                ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0x10 / 4])(lbl_8055E2E0, &lbl_8032FA38);
                fn_801476D8(0, -1, lbl_8055E2F8);
                ((void (*)(void *, void *))(*(void ***)lbl_8055E2E0)[0xC / 4])(lbl_8055E2E0, &lbl_8032FA44);
                fn_801476C4();
                fn_80130980(&sp8, 0x14, 3, *(f32 *)((u8 *)arg0 + 0x84) - *(f32 *)((u8 *)arg0 + 0x98));
                fn_801475D0(lbl_8055E2E0, &lbl_8055A0EC, &lbl_8055A0DC, &sp8);
            }
        }
        return 0;
    }
    return 0;
}
#pragma pop
unsigned char fn_80163F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x56D);
}

unsigned char fn_80163F74(void *arg0) {
    return *((unsigned char *)arg0 + 0x56D);
}

int fn_801643C8(void *arg0) {
    int var_r30;
    int var_r31;
    void *obj;
    register int value;

    var_r30 = 0;
    var_r31 = 0;
    while (var_r31 < *((int *)((char *)arg0 + 0xE4))) {
        obj = *((void **)((char *)arg0 + 0xE0));
        value = *((int *)((char *)obj + var_r30 + 0x34));
        if (value != 0) {
            fn_80128658();
        }
        var_r30 += 0x48;
        var_r31 += 1;
    }
    obj = *((void **)((char *)arg0 + 0xDC));
    if (obj != 0) {
        ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
    }
    fn_802CAC54(*((int *)((char *)arg0 + 0xD0)));
    fn_802C6CF8(*((int *)((char *)arg0 + 0xA0)));
}

int fn_80164468(void *arg0) {
    return *((float *)((char *)arg0 + 0x8C)) < lbl_8056185C;
}

void fn_80164480(void *arg0) {
    int sp10[12];
    float sp8;
    void **vtable = *(void ***)arg0;

    if (((int (*)(void *))vtable[9])(arg0) != 0) {
        if ((lbl_8055E3C8 - *((float *)((char *)arg0 + 0xC))) > lbl_80561868) {
            fn_80020434(sp10, &sp8);
            fn_8026A2CC(sp10, 0, sp8);
            fn_8000C630(0x15, -1);
            return;
        }
        fn_8000C630(0x20, -1);
    }
}

extern s32 fn_802A96E8(void *, s32, s32, s32, s32);
extern s32 fn_802C9950(s32);
extern s32 fn_802C9994(s32);
#pragma use_lmw_stmw off
void fn_80164510(void *arg0, s32 arg1) {
    s32 offset;
    s32 temp_r30;
    s32 temp_r29;
    s32 i;
    void *p;
    temp_r30 = fn_802C9950(-0x100);
    temp_r29 = fn_802C9994(0);
    if (*(s32 *)((char *)arg0 + 0xA0) != -1) {
        i = 0;
        offset = 0;
        while (i < *(s32 *)((char *)arg0 + 0xE4)) {
            p = (char *)*(void **)((char *)arg0 + 0xE0) + offset;
            if (*(u8 *)((char *)p + 0x3C) != 0 && *(s32 *)((char *)p + 0x34) != 0 && *(u8 *)((char *)arg0 + 0xD8) != 0) {
                fn_802A96E8((char *)p + 0xC, 2, *(s32 *)((char *)arg0 + 0xD4), *(s32 *)((char *)arg0 + 0xD0), 0);
            }
            offset += 0x48;
            i++;
        }
    }
    fn_802C9950(temp_r30);
    fn_802C9994(temp_r29);
}
#pragma use_lmw_stmw reset
extern s32 lbl_8055A0E0;
extern s32 lbl_8055A0E8;
extern u8 lbl_8055E2DD;
s32 fn_801645D8(void *arg0, s32 arg1) {
    if (*(float *)((char *)arg0 + 0x8C) > lbl_8056185C) {
        if (arg1 == 0x58) {
            if (*(u8 *)((char *)arg0 + 0x90) != 0)
                lbl_8055E2DD = 1;
            *(u8 *)((char *)arg0 + 0x90) = 1;
            return 1;
        }
        if ((u32)arg1 == 0x1B)
            return (lbl_8055E2DD = 1, 1);
    }
    return 0;
}

s32 fn_80164634(void *arg0) {
    return *(float *)((char *)arg0 + 0x98) > *(float *)((char *)arg0 + 0x84);
}

void fn_801647DC(void *arg0) {
    s32 var_r31;
    s32 var_r30;
    void *temp_r3;

    var_r31 = 0;
    var_r30 = 0;
    while (var_r30 < *(s32 *)((char *)arg0 + 0x38)) {
        temp_r3 = *(void **)((char *)(*(s32 *)((char *)arg0 + 0x34)) + var_r31 + 4);
        if (temp_r3 != 0) {
            if (temp_r3 != 0) {
                ((void (*)(void *, s32))((void **) *(void **)temp_r3)[2])(temp_r3, 1);
            }
        }
        var_r31 += 8;
        var_r30 += 1;
    }
    *(s32 *)((char *)arg0 + 0x38) = 0;
}

int fn_80164868(void) {
    return 1;
}

void fn_80164870(void *arg0, s32 arg1) {
    if (*(u8 *)((char *)arg0 + 0x10) == 0) {
        *(s32 *)((char *)arg0 + 8) = arg1;
        *(u8 *)((char *)arg0 + 0x10) = 1;
        *(float *)((char *)arg0 + 0xC) = lbl_8055E3C8;
    }
}

s32 fn_80164894(s32 arg0, void *arg1, s32 arg2) {
    *(float *)arg1 = *(float *)(0x14 + arg0 + (arg2 << 2));
    return 1;
}

extern f32 lbl_80561870;
extern f32 fn_80164CD4(void);
f32 fn_80164CD4(void) {
    return lbl_80561870;
}

void fn_80164CDC(void *arg0) {
    ((void (*)(void *, s32, s32))(*(void **)((char *)*(void **)((char *)arg0 + 4) + 0x18)))(*(void **)((char *)arg0 + 4), lbl_8055A0E0, lbl_8055A0E8);
}

extern int fn_80128668(void);
int fn_80164CF8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80164D38(void *arg0) {
    *(volatile unsigned char *)((char *)arg0 + 4) = 0;
    *(volatile int *)((char *)arg0 + 8) = 1;
    *(volatile unsigned char *)((char *)arg0 + 5) = 0;
    *(volatile unsigned char *)((char *)arg0 + 6) = 0;
    *(volatile unsigned char *)((char *)arg0 + 7) = 0;
}

void fn_80164D58(void) {

}

void fn_80164D5C(void) {
}

void fn_80164D60(void) {

}

unsigned char fn_80165040(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

unsigned char fn_80165048(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

unsigned char fn_80165050(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

s32 fn_80165058(void *arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r29;
    if ((s32)*(u32 *)((u8 *)fn_801E7E34() + 0xDB0) == 0) {
        if (*(u8 *)((u8 *)arg0 + 6) == 0) {
            switch (arg1) {
            case 0x126:
                temp_r30 = *(s32 *)((u8 *)arg0 + 8) - 1;
                *(s32 *)((u8 *)arg0 + 8) = temp_r30;
                if (temp_r30 < 1) *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4);
                else if (temp_r30 > *(s32 *)((u8 *)&lbl_8042FDEC + 4)) *(s32 *)((u8 *)arg0 + 8) = 1;
                else if ((temp_r30 > fn_80160CE4()) && (temp_r30 < *(s32 *)((u8 *)&lbl_8042FDEC + 4))) *(s32 *)((u8 *)arg0 + 8) = fn_80160CE4();
                fn_80230E90(1);
                return 1;
            case 0x128:
                temp_r29 = *(s32 *)((u8 *)arg0 + 8) + 1;
                *(s32 *)((u8 *)arg0 + 8) = temp_r29;
                if (temp_r29 < 1) *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4);
                else if (temp_r29 > *(s32 *)((u8 *)&lbl_8042FDEC + 4)) *(s32 *)((u8 *)arg0 + 8) = 1;
                else if ((temp_r29 > fn_80160CE4()) && (temp_r29 < *(s32 *)((u8 *)&lbl_8042FDEC + 4))) *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4);
                fn_80230E90(1);
                return 1;
            case 0x58: *(u8 *)((u8 *)arg0 + 4) = 1; return 1;
            case 0x1B: lbl_8055E2DD = 1; return 1;
            }
        } else {
            switch (arg1) {
            case 0x58: *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)&lbl_8042FDEC + 4); *(u8 *)((u8 *)arg0 + 4) = 1; return 1;
            case 0x53: *(u8 *)((u8 *)arg0 + 6) = 0; return 1;
            }
        }
    }
    return 0;
}

extern f32 fn_80165238(void);
f32 fn_80165238(void) {
    return lbl_80561848;
}

int fn_80165240(void) {
    return 0;
}

void fn_80165248(void) {

}

int fn_801657D4(void) { return 1; }

void fn_801657DC(void) {
    int sp10[12];
    float sp8;
    fn_80020434(sp10, &sp8);
    fn_8026A2CC(sp10, 0, sp8);
    fn_8000C630(0x15, -1);
}

void fn_80165820(void) {
}

int fn_80165824(void) { return 0; }

int fn_8016582C(void) { return 0; }

void *__AXGetStudio_80165834(void) {
    return lbl_8032FCB0;
}

int fn_80165840(void) {
    return 0;
}

int fn_80165848(int arg0, int arg1, int arg2, int arg3, int arg4, int *arg5) {
    if (fn_80161BB8() != 0) {
        *arg5 |= 0x1150;
        return 1;
    }
    return 0;
}

int fn_80165894(s32 a0, s32 a1, float *arg2, s32 arg3) {
    if (lbl_804348E8[arg3] != 0) {
        *arg2 = lbl_80561848;
        ((void (*)(int *, float *, s32))(*(int **)(lbl_8042FDEC + (lbl_8055E304 << 2)))[0x38 / 4])((int *)(lbl_8042FDEC + (lbl_8055E304 << 2)), arg2, arg3);
    }
    return 0;
}

int fn_80165900(void) { return 1; }

int fn_80165908(void) { return 0; }
typedef struct VtblA18 { void *pad[7]; void (*f)(void); } VtblA18;
typedef struct ObjA18 { VtblA18 *vtable; } ObjA18;
struct Vtbl_80163D34 { void *v[4]; void (*method)(void *, const char *); };
struct Obj_80163D34 { struct Vtbl_80163D34 *vt; };
