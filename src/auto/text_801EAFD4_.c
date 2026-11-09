// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef unsigned char u8;
#pragma ppc_psq_save off

#pragma cplusplus on
class EB000Context {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void dispatch(s32 *, s32, s32);
};
class EBF00Widget {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4(); virtual void p5(); virtual void setVisible(s32);
};
#pragma cplusplus reset
extern char lbl_8033A048[];
extern char lbl_80339E88[];
extern s32 *lbl_8055EBA0;
extern s32 lbl_8055AFB8;
extern s32 lbl_8055AFBC;
extern f32 lbl_8055EBA4;
extern f32 lbl_80562E6C;
extern void *fn_8012C370(s32, u32 *, void *, void *, u8 *);
extern s32 fn_8012C33C(void *);
extern s32 fn_801E2CCC(void *, f32 **);
extern void fn_801EB6A8(s32);
extern s32 fn_801EB000(s32 *, void *);
extern void fn_802CDDC8(void *, s32);
extern void fn_802E317C(const char *, ...);
extern void fn_802AE7F4(void);
extern s32 fn_802C6FC0(void *, s32, s32);
extern s32 lbl_802F9A08[];
extern s32 lbl_804885E8[];
extern f32 lbl_80562E68;
extern f32 lbl_8055EB98[2];
extern void fn_801EB9A4(s32 *);
extern void fn_801EBB7C(void *, s32);
#pragma dont_inline on
s32 fn_801EAFD4(void *arg0) {
    s32 temp = *(s32 *)arg0;
    if (temp == 0x103) {
        return ((s32 *)arg0)[7];
    }
    if (temp == 0x101) {
        return ((s32 *)arg0)[3];
    }
    return 0;
}
#pragma dont_inline off

#pragma push
#pragma scheduling invalid_target
s32 fn_801EB000(s32 *arg0, void *arg1) {
    s32 *item;
    s32 *node;
    s32 *child;
    s32 i;

    node = arg0;
    while (node != 0) {
        if (node[0] & 0x100) {
            fn_801EAFD4(node);
            fn_801EB000((s32 *)node[2], arg1);
        } else {
            switch (node[0]) {
            case 0:
                item = node;
                i = 0;
                while (i < node[5]) {
                    fn_801EB000((s32 *)item[7], arg1);
                    item += 2;
                    i += 1;
                }
                break;
            case 4:
                child = (s32 *)node[2];
                if (child != 0) {
                    ((void (*)(void *, s32 *, s32, s32))
                        ((void **)*(void ***)arg1)[2])(
                        arg1, child, child[2], child[1]);
                }
                break;
            }
        }
        node = (s32 *)node[1];
    }
}
#pragma scheduling on
#pragma pop
s32 fn_801EB0E8(void) { return 0; }

#pragma dont_inline on
s32 fn_801EB0F0(s32 arg0) {
    s32 var_r0 = 0;
    if ((arg0 >= 0) && (arg0 < 0x18)) var_r0 = 1;
    return var_r0;
}
#pragma dont_inline off

#pragma dont_inline on
s32 fn_801EB110(void *arg0) {
    return lbl_804885E8[((u32 *)arg0)[4]];
}
#pragma dont_inline off

#pragma dont_inline on
void fn_801EB128(void) {
    lbl_8055EB98[0] = lbl_80562E68;
    lbl_8055EB98[1] = lbl_80562E68;
}
#pragma dont_inline off

extern void fn_802C61BC(void *, void *, u8, u8, u8, u8, u8, u8);
extern char lbl_80339F6C[];
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801EB13C(void *arg0, s32 arg1) {
    register volatile u8 *v = (volatile u8 *)arg0;
    register u8 b8,bB,b9,bA,b4,b7,b5,b6,bC;
    register char *name = lbl_80339F6C;
    u32 offset,address;

    b8=v[8]; name=lbl_80339F6C;
    bB=v[11]; b9=v[9]; bA=v[10]; v[8]=bB;
    b4=v[4]; b7=v[7]; v[11]=b8; b5=v[5]; b6=v[6]; v[10]=b9;
    bC=v[12]; b8=v[15]; v[9]=bA; b9=v[13]; bB=v[14];
    offset=*(volatile u32 *)(v+8);
    v[4]=b7; address=(u32)v+offset; v[7]=b4; v[5]=b6; v[6]=b5;
    v[12]=b8; v[15]=bC; v[13]=bB; v[14]=b9;
    *(volatile u32 *)(v+8)=address;
    ((void (*)(void *, void *))fn_802C61BC)((void *)address,name);

    if (*(volatile s32 *)v == 1) {
        register u8 a10,a13,a11,a12,a14,a17,a15,a16;
        register u8 a18,a1B,a19,a1A,a1C,a1F,a1D,a1E;
        register u8 t0,t1;
        a10=v[0x10]; a13=v[0x13]; a11=v[0x11]; a12=v[0x12];
        a14=v[0x14]; a17=v[0x17]; a15=v[0x15]; a16=v[0x16];
        a18=v[0x18]; a1B=v[0x1B]; a19=v[0x19]; a1A=v[0x1A];
        a1C=v[0x1C]; a1F=v[0x1F]; a1D=v[0x1D]; a1E=v[0x1E];
        v[0x10]=a13; v[0x13]=a10; v[0x11]=a12; v[0x12]=a11;
        v[0x14]=a17; v[0x17]=a14; v[0x15]=a16; v[0x16]=a15;
        v[0x18]=a1B; v[0x1B]=a18; v[0x19]=a1A; v[0x1A]=a19;
        v[0x1C]=a1F; v[0x1F]=a1C; v[0x1D]=a1E; v[0x1E]=a1D;
        t0=v[0x20]; t1=v[0x23]; v[0x20]=t1; v[0x23]=t0;
        t0=v[0x21]; t1=v[0x22]; v[0x21]=t1; v[0x22]=t0;
        t0=v[0x24]; t1=v[0x27]; v[0x24]=t1; v[0x27]=t0;
        t0=v[0x25]; t1=v[0x26]; v[0x25]=t1; v[0x26]=t0;
        t0=v[0x28]; t1=v[0x2B]; v[0x28]=t1; v[0x2B]=t0;
        t0=v[0x29]; t1=v[0x2A]; v[0x29]=t1; v[0x2A]=t0;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_801EB634(void *, s32);
extern "C" void fn_801EB66C(void *, s32);
extern "C" void fn_801EB13C(void *, s32);
extern "C" s32 fn_801EB0F0(s32);
extern "C" s32 fn_801EB110(void *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" char lbl_80339F7C[];
extern "C" char lbl_80339FA0[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801EB2D4(s32 arg0, register s32 arg1) {
    register s32 node_type;
    u8 *var_r31;
    u8 *var_r30;
    u8 *var_r29;
    u8 *var_r28 = (u8 *)arg0;
    s32 var_r27;
    s32 var_r22 = 0;
    s32 var_r24 = 8;
    u8 temp_r5;
    u8 temp_r0;
    volatile register u8 *temp_r3_11;
    u8 *temp_r27;
    void *temp_obj;

    while (var_r28 != 0) {
        temp_r5 = var_r28[0];
        var_r28[0] = var_r28[3];
        var_r28[3] = temp_r5;
        temp_r5 = var_r28[1];
        var_r28[1] = var_r28[2];
        var_r28[2] = temp_r5;
        fn_801EB634(var_r28 + 4, (s32)arg1);
        enum NodeType { Node0 = 0, Node101 = 0x101, Node102 = 0x102, Node103 = 0x103, Node4 = 4 };
        switch ((NodeType)*(s32 *)var_r28) {
        case 0:
            temp_r5 = var_r28[8];
                            temp_r0 = var_r28[0xB];
                            var_r29 = var_r28;
                            var_r31 = var_r28 + 0x18;
                            var_r30 = var_r28 + 0x1C;
                            var_r28[8] = temp_r0;
                            var_r28[0xB] = temp_r5;
                            var_r27 = 0;
                            temp_r5 = var_r28[9];
                            var_r28[9] = var_r28[0xA];
                            var_r28[0xA] = temp_r5;
                            temp_r5 = var_r28[0xC];
                            var_r28[0xC] = var_r28[0xF];
                            var_r28[0xF] = temp_r5;
                            temp_r5 = var_r28[0xD];
                            var_r28[0xD] = var_r28[0xE];
                            var_r28[0xE] = temp_r5;
                            temp_r5 = var_r28[0x10];
                            var_r28[0x10] = var_r28[0x13];
                            var_r28[0x13] = temp_r5;
                            temp_r5 = var_r28[0x11];
                            var_r28[0x11] = var_r28[0x12];
                            var_r28[0x12] = temp_r5;
                            temp_r5 = var_r28[0x14];
                            var_r28[0x14] = var_r28[0x17];
                            var_r28[0x17] = temp_r5;
                            temp_r5 = var_r28[0x15];
                            var_r28[0x15] = var_r28[0x16];
                            var_r28[0x16] = temp_r5;
                            for (; var_r27 < *(s32 *)(var_r28 + 0x14); var_r27++) {
                                temp_r5 = var_r31[0];
                                var_r31[0] = var_r31[3];
                                var_r31[3] = temp_r5;
                                temp_r5 = var_r31[1];
                                var_r31[1] = var_r31[2];
                                var_r31[2] = temp_r5;
                                fn_801EB634(var_r30, (s32)arg1);
                                fn_801EB2D4((s32)*(s32 *)(var_r29 + 0x1C), arg1);
                                var_r31 += 8;
                                var_r30 += 8;
                                var_r29 += 8;
                            }
            break;
        case 0x101:
            temp_r5 = var_r28[0xC];
            var_r28[0xC] = var_r28[0xF];
            var_r28[0xF] = temp_r5;
            temp_r5 = var_r28[0xD];
            var_r28[0xD] = var_r28[0xE];
            var_r28[0xE] = temp_r5;
            fn_801EB634(var_r28 + 8, (s32)arg1);
            fn_801EB2D4(*(s32 *)(var_r28 + 8), arg1);
            break;
        case 0x102:
        case 0x103:
            temp_r5 = var_r28[0xC];
                                var_r28[0xC] = var_r28[0xF];
                                var_r28[0xF] = temp_r5;
                                temp_r5 = var_r28[0xD];
                                var_r28[0xD] = var_r28[0xE];
                                var_r28[0xE] = temp_r5;
                                temp_r5 = var_r28[0x10];
                                var_r28[0x10] = var_r28[0x13];
                                var_r28[0x13] = temp_r5;
                                temp_r5 = var_r28[0x11];
                                var_r28[0x11] = var_r28[0x12];
                                var_r28[0x12] = temp_r5;
                                temp_r5 = var_r28[0x14];
                                var_r28[0x14] = var_r28[0x17];
                                var_r28[0x17] = temp_r5;
                                temp_r5 = var_r28[0x15];
                                var_r28[0x15] = var_r28[0x16];
                                var_r28[0x16] = temp_r5;
                                temp_r5 = var_r28[0x18];
                                var_r28[0x18] = var_r28[0x1B];
                                var_r28[0x1B] = temp_r5;
                                temp_r5 = var_r28[0x19];
                                var_r28[0x19] = var_r28[0x1A];
                                var_r28[0x1A] = temp_r5;
                                fn_801EB634(var_r28 + 8, (s32)arg1);
                                fn_801EB2D4(*(s32 *)(var_r28 + 8), arg1);
                                if (*(s32 *)var_r28 == 0x103) {
                                    temp_r5 = var_r28[0x1C];
                                    var_r28[0x1C] = var_r28[0x1F];
                                    var_r28[0x1F] = temp_r5;
                                    temp_r5 = var_r28[0x1D];
                                    var_r28[0x1D] = var_r28[0x1E];
                                    var_r28[0x1E] = temp_r5;
                                }
            break;
        case 4:
            fn_801EB66C(var_r28 + 8, (s32)arg1);
                        temp_r3_11 = (u8 *)*(u32 *)(var_r28 + 8);
                        temp_r5 = temp_r3_11[0];
                        temp_r3_11[0] = temp_r3_11[3];
                        temp_r3_11[3] = temp_r5;
                        temp_r5 = temp_r3_11[1];
                        temp_r3_11[1] = temp_r3_11[2];
                        temp_r3_11[2] = temp_r5;
                        fn_801EB13C((void *)*(u32 *)(var_r28 + 8), temp_r5);
                        if (*(s32 *)(*(s32 *)((u8 *)*(volatile s32 *)(var_r28 + 8) + 8)) <= 0) {
                            *(s32 *)(var_r28 + 8) = var_r22;
                        }
                        temp_r27 = (u8 *)*(u32 *)(var_r28 + 8);
                        if (temp_r27 != 0 && *(s32 *)temp_r27 == 1) {
                            if (fn_801EB0F0(*(s32 *)(temp_r27 + 0x10)) != 0) {
                                temp_obj = (void *)fn_801EB110(temp_r27);
                                struct Dummy { virtual void f0(); virtual void f1(void *); };
                                ((Dummy *)temp_obj)->f1(temp_r27);
                            } else {
                                fn_802E30C8(lbl_80339F7C, *(s32 *)(temp_r27 + 0x10));
                                *(s32 *)(temp_r27 + 0x10) = var_r24;
                            }
                        }
            break;
        default:
            fn_802E317C(lbl_80339FA0);
            break;
        }
        var_r28 = (u8 *)*(u32 *)(var_r28 + 4);
    }
}
#pragma scheduling on
#pragma cplusplus off
#pragma dont_inline on
void fn_801EB634(void *arg0, s32 arg1) {
    u8 a, b, c, d;
    a = ((u8 *)arg0)[0];
    d = ((u8 *)arg0)[3];
    ((u8 *)arg0)[0] = d;
    ((u8 *)arg0)[3] = a;
    b = ((u8 *)arg0)[1];
    c = ((u8 *)arg0)[2];
    ((u8 *)arg0)[1] = c;
    ((u8 *)arg0)[2] = b;
    if (*(s32 *)arg0) *(s32 *)arg0 += arg1;
}
#pragma dont_inline off

extern void fn_801EB66C(void *, s32);
void fn_801EB66C(void *arg0, s32 arg1) {
    u8 a, b, c, d;
    a = ((u8 *)arg0)[0];
    d = ((u8 *)arg0)[3];
    ((u8 *)arg0)[0] = d;
    ((u8 *)arg0)[3] = a;
    b = ((u8 *)arg0)[1];
    c = ((u8 *)arg0)[2];
    ((u8 *)arg0)[1] = c;
    ((u8 *)arg0)[2] = b;
    if (*(s32 *)arg0) *(s32 *)arg0 += arg1;
}

void fn_801EB6A4(void) {

}

#pragma dont_inline on
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" s32 fn_802C6DC4(const char *, s32, s32, s32);
extern "C" void fn_802C6FA8(s32);
extern "C" char lbl_80339FD4[];
extern "C" s32 lbl_8055AFC0;
extern "C" void fn_801EB6A8(s32 arg0) {
    struct FirstDispatch {
        virtual void unused0();
        virtual void unused1();
        virtual void dispatch(s32 *);
    };
    struct SecondDispatch {
        virtual void unused0();
        virtual void unused1();
        virtual void unused2();
        virtual void unused3();
        virtual void unused4();
        virtual void unused5();
        virtual void unused6();
        virtual void unused7();
        virtual void unused8();
        virtual void dispatch(s32 *, s32, s32, s32, s32);
    };
    register s32 *item;
    register s32 *node;
    register s32 *context;
    register s32 *child;
    register s32 type;
    register s32 i;
    node = (s32 *)arg0;
    while (node != 0) {
        type = node[0];
        if (type == 4) goto state4;
        if (type >= 4) goto high;
        switch (type) {
        case 0: goto state0;
        default: goto error;
        }
high:
        if (type >= 0x104) goto error;
        if (type < 0x101) goto error;
        goto state_special;
state0:
        item = node;
        i = 0;
        while (i < node[5]) {
            fn_801EB6A8(item[7]);
            item += 2;
            i++;
        }
        goto next;
state_special:
        fn_801EAFD4(node);
        fn_801EB6A8(node[2]);
        goto next;
state4:
        child = (s32 *)node[2];
        if (child != 0) {
            child[1] = fn_802C6DC4((const char *)&lbl_8055AFC0, child[2], 0, 0);
            fn_802C6FA8(child[2]);
            if (child[0] == 1) {
                FirstDispatch *first = (FirstDispatch *)fn_801EB110(child);
                first->dispatch(child);
                context = lbl_8055EBA0;
                SecondDispatch *second = (SecondDispatch *)fn_801EB110(child);
                second->dispatch(child, context[1], child[7], context[2], child[6]);
            }
        }
        goto next;
error:
        fn_802E317C(lbl_80339FD4);
next:
        node = (s32 *)node[1];
    }
}
#pragma cplusplus reset
#pragma scheduling on
#pragma dont_inline off

#pragma cplusplus on
extern "C" void fn_801EB800(void *object, s32 arg1, s32 arg2) {
    struct Dispatch {
        virtual void u0();
        virtual void u1();
        virtual void u2();
        virtual void u3();
        virtual void u4();
        virtual void u5();
        virtual void u6();
        virtual void u7();
        virtual void dispatch(s32, s32);
    };
    ((Dispatch *)object)->dispatch(arg2, arg1);
}
#pragma cplusplus reset
void fn_801EB81C(void) {

}

void fn_801EB820(void) {

}

#pragma dont_inline on
void fn_801EB824(s32 arg0) {
    s32 sp8;
    sp8 = (s32)lbl_8033A048;
    ((s32 (*)(s32, s32 *))fn_801EB000)(arg0, &sp8);
}

void fn_801EB854(void) {
    s32 *var_r31=lbl_802F9A08;
    s32 *var_r30=lbl_804885E8;
    u32 var_r29=0;
    for(;var_r29<0x18;var_r29++,var_r31+=2,var_r30++) {
        fn_801EB96C(var_r30,var_r31[1]);
    }
}

void fn_801EB8BC(void) {
    s32 *p = lbl_804885E8;
    u32 i;
    for (i = 0; i < 0x18; i++, p++) {
        fn_801EB9A4(p);
    }
}
#pragma dont_inline off

#pragma dont_inline on
void fn_801EB90C(void) {
    void **p = (void **)lbl_804885E8;
    u32 i = 0;
    do {
        void *obj = *p;
        void **vtable = *(void ***)obj;
        ((void (*)(void))vtable[6])();
        i++;
        if (i < 0x18) p++;
    } while (i < 0x18);
}
#pragma dont_inline off

void fn_801EB968(void) {

}

s32 fn_801EB96C(s32 *out, s32 callback) {
    register s32 (*fn)(void) = (s32 (*)(void))callback;
    register s32 *ptr = out;
    *ptr = fn();
    return *ptr;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801EB9A4(s32 *arg0) {
    class ThreadObject {
    public:
        virtual void destroy(int);
    };
    ThreadObject *p = *(ThreadObject **)arg0;
    if (p) {
        if (p)
            p->destroy(1);
    }
    *(ThreadObject **)arg0 = 0;
}

extern "C" s32 fn_801EB9FC(void *arg0) {
    u8 sp9;
    u8 sp8;
    u32 sp14;
    u32 sp10;
    f32 *spC;
    char *file = lbl_80339E88;
    char *path;

    lbl_8055EBA0 = (s32 *)((void *(*)(void *, s32, u32 *, u32 *, u8 *, u8 *))fn_8012C370)(
        arg0, 0x47524146, &sp10, &sp14, &sp8, &sp9);
    if (lbl_8055EBA0 == 0)
        goto no_resource;
    if (sp10 != 0x15)
        goto bad_resource;

    fn_801EB128();
    fn_801EB854();
    if (sp9 == 0)
        goto bad_resource;

    fn_801EB634(lbl_8055EBA0, (s32)lbl_8055EBA0);
    fn_801EB2D4(*lbl_8055EBA0, (s32)lbl_8055EBA0);
    fn_801EBB7C((char *)lbl_8055EBA0 + 4, (s32)lbl_8055EBA0);
    fn_801EBB7C((char *)lbl_8055EBA0 + 8, (s32)lbl_8055EBA0);
    fn_802CDDC8((void *)lbl_8055EBA0[1], lbl_8055EBA0[1]);
    fn_802CDDC8((void *)lbl_8055EBA0[2], lbl_8055EBA0[2]);
    fn_801EB6A8(*lbl_8055EBA0);
    fn_801EB90C();
    goto common;

bad_resource:
    fn_802E317C(file + 0x180, sp10, 0x15);
    goto common;

no_resource:
    fn_802AE7F4();

common:
    lbl_8055EBA4 = lbl_80562E6C;
    path = file + 0x194;
    if (fn_8012C33C(path) != 0) {
        lbl_8055AFB8 = fn_802C6FC0(path, 0, 0);
        spC = 0;
        if (fn_801E2CCC(file + 0x1A0, &spC) != 0)
            lbl_8055EBA4 = *spC;
    } else {
        lbl_8055AFB8 = -1;
    }
    lbl_8055AFBC = fn_802C6FC0(file + 0x1B0, 0, 0);
    return lbl_8055EBA0 != 0;
}

#pragma pop
#pragma cplusplus reset
extern void fn_801EBB7C(void *, s32);
void fn_801EBB7C(void *arg0, s32 arg1) {
    u8 a, b, c, d;
    a = ((u8 *)arg0)[0];
    d = ((u8 *)arg0)[3];
    ((u8 *)arg0)[0] = d;
    ((u8 *)arg0)[3] = a;
    b = ((u8 *)arg0)[1];
    c = ((u8 *)arg0)[2];
    ((u8 *)arg0)[1] = c;
    ((u8 *)arg0)[2] = b;
    if (*(s32 *)arg0) *(s32 *)arg0 += arg1;
}

extern s32 lbl_8055AFB8;
extern s32 lbl_8055AFBC;
extern s32 *lbl_8055EBA0;
extern s32 fn_8012C4D8(s32);
extern void fn_802AE9D0(void);
extern void fn_802AEA44(void);
extern void fn_802C6CF8(s32);
extern void fn_802CCE24(s32);
void fn_801EBBB4(void) {
    fn_802C6CF8(lbl_8055AFBC);
    lbl_8055AFBC = -1;
    if (lbl_8055AFB8 != -1) {
        fn_802C6CF8(lbl_8055AFB8);
        lbl_8055AFB8 = -1;
    }
    if (lbl_8055EBA0 != 0) {
        fn_801EB824(*lbl_8055EBA0);
        fn_801EB8BC();
        fn_8012C4D8((s32)lbl_8055EBA0);
        lbl_8055EBA0 = 0;
        return;
    }
    fn_802AE9D0();
}
void fn_801EBC2C(void) {
    if (lbl_8055EBA0 != 0) {
        fn_802CCE24(((s32 *)lbl_8055EBA0)[1]);
        fn_802CCE24(((s32 *)lbl_8055EBA0)[2]);
        return;
    }
    fn_802AEA44();
}

typedef struct {
    void **vt;
} Obj;
extern void fn_802CD254(s32);
extern void fn_801E8718(s32);
extern f32 fn_801E8738(s32);
extern void fn_802BF598(f32);
extern s32 fn_801E85A4(void);
extern void fn_802B0144(void);
void fn_801EBC70(void) {
    if (lbl_8055EBA0 != 0) {
        fn_802CD254(((s32 *)lbl_8055EBA0)[1]);
        fn_802CD254(((s32 *)lbl_8055EBA0)[2]);
    }
}

void fn_801EBCAC(void) {
    if (lbl_8055EBA0 != 0) {
        s32 *p = lbl_804885E8;
        u32 i = 0;
        for (; i < 0x18; i++, p++) {
            Obj *obj = (Obj *)*p;
            ((void (*)(void))obj->vt[7])();
        }
    }
}

void fn_801EBD14(void) {

}

void fn_801EBD18(s32 arg0) {
    f32 temp;
    if (fn_801E85A4() > 1) {
        temp = fn_801E8738(arg0);
        fn_801E8718(arg0);
        fn_802BF598(temp);
    }
}

void fn_801EBD70(void) {
    f32 temp;
    if (lbl_8055EBA0 == 0) {
        fn_802B0144();
        if (fn_801E85A4() == 1) {
            temp = fn_801E8738(-1);
            fn_801E8718(-1);
            fn_802BF598(temp);
        }
    }
}

extern s32 fn_801EA470(void);
extern void fn_801F1C24(void *);
extern void fn_801F4DCC(void);
extern void fn_801FA6B8(void);
extern void fn_80202718(void);
extern void fn_802879E4(s32);
extern void fn_80287A34(s32);
extern void fn_8029790C(s32);
extern void fn_802B01A8(void);
extern void fn_802C7730(void *);
extern void fn_802C7A44(void);
extern void fn_802C7A50(void);
extern void fn_802C7A94(s32);
extern void fn_802C7AD4(void);
extern void fn_802C9648(f32);
extern void fn_802C967C(void);
extern void fn_802CD37C(s32, s32, s32, s32, f32, f32);
extern void fn_802CDAA8(void);
extern void fn_802CDB5C(s32);
extern f32 lbl_80562E70;
void fn_801EBDCC(void) {
 s32 stack[10]; s32 temp_r3; s32 var_r3;
 if (lbl_8055EBA0 != 0) {
  fn_802C7A44(); fn_80202718(); fn_801F1C24(&stack[0]); fn_802C7730(&stack[0]);
  temp_r3=fn_801EA470();
  if(temp_r3) var_r3=lbl_8055EBA0[2]; else var_r3=lbl_8055EBA0[1];
  fn_802CD37C(var_r3,0,0,0,lbl_8055EB98[0],lbl_8055EB98[1]);
  fn_802CDB5C(0); fn_802C7A94(1);
  if(!temp_r3){fn_802C9648(lbl_80562E70);fn_802CDB5C(1);fn_802C7A94(2);fn_802C7A94(3);fn_80287A34(0);fn_802C967C();fn_802CDB5C(2);fn_802879E4(0);fn_802C7A94(4);}
  fn_801FA6B8();fn_802C7730(&stack[0]);fn_802CDB5C(3);fn_802C7A50();
  if(!temp_r3){fn_8029790C(0);fn_801F4DCC();fn_802CDB5C(4);}
  fn_802C7AD4();fn_802CDAA8();
 } else fn_802B01A8();
}

extern void fn_802B0144(void);
void fn_801EB634_keep(void);
void fn_801EBEF4(f32 farg0) {
    lbl_8055EB98[0] = farg0 * farg0;
}

extern f32 lbl_80558DC4[];
extern f32 lbl_80562E74;
extern f32 lbl_80562E78;
extern f32 lbl_80562E7C;
extern double cos(double);
extern double sin(double);
extern double fabs(double);
extern void fn_802C8B08(f32 *);
extern void fn_802C744C(s32, f32 *);
extern void fn_802C9474(u32);
extern f32 *fn_802C86DC(void);
extern void fn_802C9900(f32);
extern void fn_802C9904(void);
extern void fn_802B05D8(void);
extern s32 fn_801E85B4(void);
extern char *fn_801E7E34(void);
#pragma ppc_psq_save off
extern double __fabs(double);
#pragma push
#pragma cplusplus on
#pragma ppc_psq_save off
extern "C" void fn_801EBF00(void) {
    f32 m[12];
    f32 pos[3];
    f32 r[9];
    char *item;
    f32 *p;
    f32 a, scale, c, s, t;
    s32 v;
    u8 b;

    if (lbl_8055EBA0 != 0) {
        ((EBF00Widget *)lbl_804885E8[3])->setVisible(0);
        if (lbl_8055AFB8 != -1) {
            fn_802C8B08(m);
            scale = lbl_80562E68 - lbl_8055EBA4;
            m[9] = m[9] * scale;
            m[10] = m[10] * scale;
            m[11] = m[11] * scale;
            m[0] = lbl_80562E68;
            m[1] = lbl_80562E74;
            m[2] = lbl_80562E74;
            m[3] = lbl_80562E74;
            m[4] = lbl_80562E68;
            m[5] = lbl_80562E74;
            m[6] = lbl_80562E74;
            m[7] = lbl_80562E74;
            m[8] = lbl_80562E68;
            fn_802C744C(lbl_8055AFB8, m);
        }
        ((EBF00Widget *)lbl_804885E8[6])->setVisible(0);
        item = fn_801E7E34() + fn_801E85B4() * 0xE0;
        a = *(f32 *)(item + 0xD8);
        if (!((f32)__fabs(a) <= lbl_80558DC4[0])) {
            v = (s32)(lbl_80562E78 * a);
            v = v > 0 ? v : 0;
            b = 0xFF;
            if (v < 0xFF) b = v;
            fn_802C9474((b << 16) | (b << 8) | b | 0xFF000000);
            p = fn_802C86DC();
            pos[0] = p[9];
            pos[1] = p[10];
            pos[2] = p[11];
            t = *(f32 *)(item + 0xE0);
            c = (f32)cos(t);
            s = (f32)sin(t);
            r[0] = c;
            r[1] = lbl_80562E74;
            r[2] = -s;
            r[3] = lbl_80562E74;
            r[4] = lbl_80562E68;
            r[5] = lbl_80562E74;
            r[6] = s;
            r[7] = lbl_80562E74;
            r[8] = c;
            t = lbl_80562E7C * *(f32 *)(item + 0xD8);
            fn_802C9900(lbl_80562E68 < t ? lbl_80562E68 : t);
            fn_802C744C(lbl_8055AFBC, r);
            fn_802C9904();
        }
    } else {
        fn_802B05D8();
    }
}
#pragma cplusplus reset
#pragma pop
extern f32 lbl_8055EBA4;
extern f32 fn_801EC114(void);
f32 fn_801EC114(void) {
    return lbl_8055EBA4;
}

void fn_801EC11C(void) {
    if (*(s32 *)&lbl_8055EBA0 == 0) {
        fn_802AEAA8();
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_802C6FB4(s32);
extern "C" void fn_802C703C(s32);
extern "C" void fn_801EC130(s32 arg0, void *arg1, s32 arg2) {
    if (((s32 *)arg1)[1] != -1) {
        fn_802C6FB4(arg2);
        fn_802C703C(((s32 *)arg1)[1]);
    }
    if (*(s32 *)arg1 == 1) {
        s32 (*lookup)(void *) = fn_801EB110;
        void *obj = (void *)lookup(arg1);
        struct Dummy {
            virtual void f0();
            virtual void f1();
            virtual void f2();
            virtual void f3(void *);
            virtual void f4();
            virtual void f5(void *);
        };
        ((Dummy *)obj)->f3(arg1);
    }
}
#pragma cplusplus reset
#pragma pop
void fn_801EC19C(void) {

}
extern s32 lbl_802F9A08[];
extern s32 fn_801EB000(s32 *, void *);
extern s32 fn_801EB96C(s32 *, s32);
extern void fn_801EB634(void *, s32);
#pragma dont_inline on
