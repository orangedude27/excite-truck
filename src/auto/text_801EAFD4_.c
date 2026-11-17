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
extern void fn_802CDDC8(void *, s32);
extern void fn_802E317C(const char *, ...);
extern void fn_802AE7F4(void);
extern void fn_802AEAA8(void);
extern s32 fn_802C6FC0(void *, s32, s32);
extern s32 lbl_802F9A08[];
extern s32 lbl_804885E8[];
extern f32 lbl_80562E68;
extern f32 lbl_8055EB98[2];
extern void fn_801EB9A4(s32 *);
extern void fn_801EBB7C(void *, s32);
#pragma dont_inline on
/* Returns the type-specific field of a scene-graph node: field 7 for a type-0x103
 * node, field 3 for a type-0x101 node, and 0 for any other type. */
s32 fn_801EAFD4(void *node) {
    s32 type = *(s32 *)node;
    if (type == 0x103) {
        return ((s32 *)node)[7];
    }
    if (type == 0x101) {
        return ((s32 *)node)[3];
    }
    return 0;
}
#pragma dont_inline off

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801EB000(s32 *firstNode, void *context) {
    /* Walk a node list depth-first: recurse into grouped/child nodes and dispatch
       drawable nodes through the context callback. */
    s32 *itemNode;
    s32 *node;
    s32 *childNode;
    s32 index;
    node = firstNode;
    while (node != 0) {
        if (node[0] & 0x100) {
            fn_801EAFD4(node);
            fn_801EB000((s32 *)node[2], context);
        } else {
            switch (node[0]) {
            case 0:
                itemNode = node;
                index = 0;
                while (index < node[5]) {
                    fn_801EB000((s32 *)itemNode[7], context);
                    itemNode += 2;
                    index += 1;
                }
                break;
            case 4:
                childNode = (s32 *)node[2];
                if (childNode != 0) {
                    ((EB000Context *)context)->dispatch(childNode, childNode[2], childNode[1]);
                }
                break;
            }
        }
        node = (s32 *)node[1];
    }
}
#pragma scheduling reset
#pragma cplusplus reset
/* Stub: reports 0 (no result / success). Unused placeholder in this graphics-model utility unit. */
s32 fn_801EB0E8(void) { return 0; }

#pragma dont_inline on
// Returns nonzero when modelType is a recognized graphics model type (0..0x17);
// used before indexing the model-type table and reporting unknown types.
s32 fn_801EB0F0(s32 modelType) {
    s32 isKnown = 0;
    if ((modelType >= 0) && (modelType < 0x18)) isKnown = 1;
    return isKnown;
}
#pragma dont_inline off

#pragma dont_inline on
s32 fn_801EB110(void *node) {
    /* Look up the cached subsystem object for this node's model-type id (word 4) in the 24-entry cache table. */
    return lbl_804885E8[((u32 *)node)[4]];
}
#pragma dont_inline off

#pragma dont_inline on
/* Reset the pair of global float scale factors (passed to the scene render call) to 1.0. */
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
    volatile u8 *v = (volatile u8 *)arg0;
    u32 offset, address;
    u8 a, b, c, d, e, f, g, h, i, j, k, l;
    char *name = lbl_80339F6C;
    a = v[8]; b = v[11]; c = v[9]; d = v[10]; v[8] = b;
    e = v[4]; f = v[7]; v[11] = a; g = v[5]; h = v[6]; v[10] = c;
    i = v[12]; j = v[15]; v[9] = d; k = v[13]; l = v[14];
    offset = *(volatile u32 *)(v + 8);
    v[4] = f; address = (u32)v + offset; v[7] = e; v[5] = h; v[6] = g;
    v[12] = j; v[15] = i; v[13] = l; v[14] = k;
    *(volatile u32 *)(v + 8) = address;
    fn_802C61BC((void *)address, name, l, j, h, f, e, i);
    if (*(volatile s32 *)v == 1) {
        u8 a10, a13, a11, a12, a14, a17, a15, a16;
        u8 a18, a1B, a19, a1A, a1C, a1F, a1D, a1E;
        u8 t0, t1;
        a10 = v[0x10]; a13 = v[0x13]; a11 = v[0x11]; a12 = v[0x12];
        a14 = v[0x14]; a17 = v[0x17]; a15 = v[0x15]; a16 = v[0x16];
        a18 = v[0x18]; a1B = v[0x1B]; a19 = v[0x19]; a1A = v[0x1A];
        a1C = v[0x1C]; a1F = v[0x1F]; a1D = v[0x1D]; a1E = v[0x1E];
        v[0x10] = a13; v[0x13] = a10; v[0x11] = a12; v[0x12] = a11;
        v[0x14] = a17; v[0x17] = a14; v[0x15] = a16; v[0x16] = a15;
        v[0x18] = a1B; v[0x1B] = a18; v[0x19] = a1A; v[0x1A] = a19;
        v[0x1C] = a1F; v[0x1F] = a1C; v[0x1D] = a1E; v[0x1E] = a1D;
        t0 = v[0x20]; t1 = v[0x23]; v[0x20] = t1; v[0x23] = t0;
        t0 = v[0x21]; t1 = v[0x22]; v[0x21] = t1; v[0x22] = t0;
        t0 = v[0x24]; t1 = v[0x27]; v[0x24] = t1; v[0x27] = t0;
        t0 = v[0x25]; t1 = v[0x26]; v[0x25] = t1; v[0x26] = t0;
        t0 = v[0x28]; t1 = v[0x2B]; v[0x28] = t1; v[0x2B] = t0;
        t0 = v[0x29]; t1 = v[0x2A]; v[0x29] = t1; v[0x2A] = t0;
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
#pragma use_lmw_stmw off
extern "C" void fn_801EB2D4(s32 arg0, register s32 arg1) {
    u8 *var_r31;
    u8 *var_r30;
    u8 *var_r29;
    u8 *var_r28 = (u8 *)arg0;
    s32 var_r27;
    s32 var_r22 = 0;
    s32 var_r24 = 8;
    u32 nt6;
    u8 temp_r5;
    u8 temp_r0;
    u8 *temp_r27;
    void *temp_obj;
    u8 *ptr4;
    u8 ba4;
    u8 bb4;
    while (var_r28 != 0) {
        temp_r5 = var_r28[0];
        var_r28[0] = var_r28[3];
        var_r28[3] = temp_r5;
        temp_r5 = var_r28[1];
        var_r28[1] = var_r28[2];
        var_r28[2] = temp_r5;
        fn_801EB634(var_r28 + 4, (s32)arg1);
        nt6 = *(u32 *)var_r28;
        switch (nt6) {
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
            ptr4 = (u8 *)*(u32 *)(var_r28 + 8);
            ba4 = ptr4[0];
            bb4 = ptr4[3];
            ptr4[0] = bb4;
            ptr4[3] = ba4;
            ba4 = ptr4[1];
            bb4 = ptr4[2];
            ptr4[1] = bb4;
            ptr4[2] = ba4;
            fn_801EB13C((void *)*(u32 *)(var_r28 + 8), ba4);
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
            fn_802E317C((const char *)lbl_80339FA0);
            break;
        }
        var_r28 = (u8 *)*(u32 *)(var_r28 + 4);
    }
}
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma cplusplus off
#pragma dont_inline on
void fn_801EB634(void *word, s32 base) {
    u8 b0, b1, b2, b3;
    /* Byte-swap the stored 32-bit word in place, then add the base address to
     * turn the stored (big-endian) offset into a pointer, unless it is zero. */
    b0 = ((u8 *)word)[0];
    b3 = ((u8 *)word)[3];
    ((u8 *)word)[0] = b3;
    ((u8 *)word)[3] = b0;
    b1 = ((u8 *)word)[1];
    b2 = ((u8 *)word)[2];
    ((u8 *)word)[1] = b2;
    ((u8 *)word)[2] = b1;
    if (*(s32 *)word) *(s32 *)word += base;
}
#pragma dont_inline off

extern void fn_801EB66C(void *, s32);
/* Byte-swaps the 32-bit field at *field (on-disk big-endian to native) and,
 * when the result is nonzero, adds base to turn the stored offset into a pointer. */
void fn_801EB66C(void *field, s32 base) {
    u8 byte0, byte1, byte2, byte3;
    byte0 = ((u8 *)field)[0];
    byte3 = ((u8 *)field)[3];
    ((u8 *)field)[0] = byte3;
    ((u8 *)field)[3] = byte0;
    byte1 = ((u8 *)field)[1];
    byte2 = ((u8 *)field)[2];
    ((u8 *)field)[1] = byte2;
    ((u8 *)field)[2] = byte1;
    if (*(s32 *)field) *(s32 *)field += base;
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
    while (node) {
        type = node[0];
        if (type == 4) { goto state4; }
        if (type >= 4) { goto high; }
        switch (type) {
        case 0: goto state0;
        default: goto error;
        }
high:
        if (type >= 0x104) { goto error; }
        if (type < 0x101) { goto error; }
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
        if (child) {
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
extern "C" void fn_801EB800(void *object, s32 argA, s32 argB) {
    /* C-callable thunk: invoke the virtual method at vtable slot 0x28 on object, passing (argB, argA). */
    struct Dispatch {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void dispatch(s32, s32);
    };
    ((Dispatch *)object)->dispatch(argB, argA);
}
#pragma cplusplus reset
void fn_801EB81C(void) {

}

void fn_801EB820(void) {

}

#pragma dont_inline on
/* Walk the node tree rooted at node using a dispatch context whose vtable is lbl_8033A048. */
void fn_801EB824(s32 node) {
    s32 dispatchVtable;
    dispatchVtable = (s32)lbl_8033A048;
    ((s32 (*)(s32, s32 *))fn_801EB000)(node, &dispatchVtable);
}

/* Initialize 24 cached values by calling each getter in the descriptor table and storing its result in the corresponding slot. */
void fn_801EB854(void) {
#define descriptorTable lbl_802F9A08
#define cachedValues lbl_804885E8
    s32 *descriptor = descriptorTable;
    s32 *cacheSlot = cachedValues;
    u32 index = 0;
    for (; index < 0x18; index++, descriptor += 2, cacheSlot++) {
        fn_801EB96C(cacheSlot, descriptor[1]);
    }
#undef descriptorTable
#undef cachedValues
}

/* Destroy all cached subsystem objects stored in the table. */
void fn_801EB8BC(void) {
#define sCachedSubsystemTable lbl_804885E8
    s32 *entry = sCachedSubsystemTable;
    u32 index;
    for (index = 0; index < 0x18; index++, entry++) {
        fn_801EB9A4(entry);
    }
#undef sCachedSubsystemTable
}
#pragma dont_inline off

#pragma cplusplus on
/* Calls vtable slot 4 on each of the 24 cached subsystem entry objects. */
extern "C" void fn_801EB90C(void) {
    class Entry {
    public:
        virtual void u0();
        virtual void u1();
        virtual void u2();
        virtual void u3();
        virtual void f();
    };
    void **entryPtr = (void **)lbl_804885E8;
    u32 index;
    for (index = 0; index < 0x18; index++, entryPtr++) {
        ((Entry *)*entryPtr)->f();
    }
}
#pragma cplusplus reset

void fn_801EB968(void) {

}

s32 fn_801EB96C(s32 *cacheSlot, s32 getter) {
    /* Calls a zero-argument getter, stores its result in a cache slot, and returns that value. */
    register s32 (*get)(void) = (s32 (*)(void))getter;
    register s32 *slot = cacheSlot;
    *slot = get();
    return *slot;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801EB9A4(s32 *arg0) {
    /* Destroy the cached subsystem object stored in this slot, if any, and clear the slot. */
    class ThreadObject {
    public:
        virtual void destroy(int);
    };
    ThreadObject *object = *(ThreadObject **)arg0;
    if (object) {
        if (object)
            object->destroy(1);
    }
    *(ThreadObject **)arg0 = 0;
}
extern "C" s32 fn_801EB9FC(void *resourceMgr) {
    /* Load the "Simple Model" EB resource (FARG, version 0x15), build its object
       and material lists, then open its parameter/sound archives and record their handles. */
    u8 hasExtraSetup;
    u8 spare8;
    u32 spareSize;
    u32 version;
    f32 *valueOut;
    char *strings = lbl_80339E88;
    char *archivePath;
    s32 handle;

#define gEBContext lbl_8055EBA0
#define gEBDefaultValue lbl_8055EBA4
#define gParamHandle lbl_8055AFB8
#define gSoundHandle lbl_8055AFBC

    gEBContext = (s32 *)((void *(*)(void *, s32, u32 *, u32 *, u8 *, u8 *))fn_8012C370)(
        resourceMgr, 0x47524146, &version, &spareSize, &spare8, &hasExtraSetup);
    if (gEBContext == 0)
        goto no_resource;
    if (version != 0x15)
        goto bad_resource;

    fn_801EB128();
    fn_801EB854();
    if (hasExtraSetup != 0) {
        fn_801EB634(gEBContext, (s32)gEBContext);
        fn_801EB2D4(*gEBContext, (s32)gEBContext);
        fn_801EBB7C((char *)gEBContext + 4, (s32)gEBContext);
        fn_801EBB7C((char *)gEBContext + 8, (s32)gEBContext);
        fn_802CDDC8((void *)gEBContext[1], gEBContext[1]);
        fn_802CDDC8((void *)gEBContext[2], gEBContext[2]);
    }
    fn_801EB6A8(*gEBContext);
    ((void (*)(void))fn_801EB90C)();
    goto common;

bad_resource:
    fn_802E317C(strings + 0x180, version, 0x15);
    goto common;

no_resource:
    fn_802AE7F4();

common:
    gEBDefaultValue = lbl_80562E6C;
    archivePath = strings + 0x194;
    if (fn_8012C33C(archivePath) != 0) {
        handle = fn_802C6FC0(archivePath, 0, 0);
        gParamHandle = handle;
        valueOut = 0;
        if (((s32 (*)(s32, void *, f32 **))fn_801E2CCC)(handle, strings + 0x1A0, &valueOut) != 0)
            gEBDefaultValue = *valueOut;
    } else {
        gParamHandle = -1;
    }
    gSoundHandle = fn_802C6FC0(strings + 0x1B0, 0, 0);
    return gEBContext != 0;

#undef gSoundHandle
#undef gParamHandle
#undef gEBDefaultValue
#undef gEBContext
}

#pragma pop
#pragma cplusplus reset
extern void fn_801EBB7C(void *, s32);
void fn_801EBB7C(void *word, s32 base) {
    u8 b0, b1, b2, b3;
    /* Byte-swap the stored 32-bit word in place, then add the base address to
     * turn the stored (big-endian) offset into a pointer, unless it is zero. */
    b0 = ((u8 *)word)[0];
    b3 = ((u8 *)word)[3];
    ((u8 *)word)[0] = b3;
    ((u8 *)word)[3] = b0;
    b1 = ((u8 *)word)[1];
    b2 = ((u8 *)word)[2];
    ((u8 *)word)[1] = b2;
    ((u8 *)word)[2] = b1;
    if (*(s32 *)word) *(s32 *)word += base;
}

extern s32 lbl_8055AFB8;
extern s32 lbl_8055AFBC;
extern s32 *lbl_8055EBA0;
extern s32 fn_8012C4D8(s32);
extern void fn_802AE9D0(void);
extern void fn_802AEA44(void);
extern void fn_802C6CF8(s32);
extern void fn_802CCE24(s32);
/* Shut down the EB context: stop its sound handles, tear down and free the active object if present, otherwise run fallback cleanup. */
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
    /* If an EB context is active, prepare its two subordinate resource lists; otherwise run the fallback cleanup. */
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

#define gEBContext lbl_8055EBA0
#define MLIST_Clear fn_802CD254

typedef struct {
    s32 root;
    s32 materialListA;
    s32 materialListB;
} EBContext;

extern void fn_802CD254(s32);
extern void fn_801E8718(s32);
extern f32 fn_801E8738(s32);
extern void fn_802BF598(f32);
extern s32 fn_801E85A4(void);
extern void fn_802B0144(void);
void fn_801EBC70(void) {
    /* If the EB context is active, clear both of its material lists. */
    if (gEBContext != 0) {
        MLIST_Clear(((EBContext *)gEBContext)->materialListA);
        MLIST_Clear(((EBContext *)gEBContext)->materialListB);
    }
}

#pragma cplusplus on
/* If the global subsystem object exists, invoke virtual method v5() on each of the 24 entries in lbl_804885E8. */
extern "C" void fn_801EBCAC(void) {
    class Entry {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    if (lbl_8055EBA0 != 0) {
        s32 *entryPtr = lbl_804885E8;
        u32 index = 0;
        for (; index < 0x18; index++, entryPtr++) {
            Entry *entry = (Entry *)*entryPtr;
            entry->v5();
        }
    }
}
#pragma cplusplus reset
void fn_801EBD14(void) {

}

void fn_801EBD18(s32 playerIndex) {
    f32 value;
    /* In multiplayer, notify the player's race slot of its current value. */
    if (fn_801E85A4() > 1) {
        value = fn_801E8738(playerIndex);
        fn_801E8718(playerIndex);
        fn_802BF598(value);
    }
}

/* When no active context exists and there is exactly one player, reset state
 * and apply the default player's stored value to the current slot object. */
void fn_801EBD70(void) {
    f32 value;
    if (lbl_8055EBA0 == 0) {
        fn_802B0144();
        if (fn_801E85A4() == 1) {
            value = fn_801E8738(-1);
            fn_801E8718(-1);
            fn_802BF598(value);
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
    /* Run the render/scene update sequence when a scene context exists; fallback otherwise. */
    s32 stack[10];
    s32 temp_r3;
    s32 var_r3;

    if (lbl_8055EBA0 != 0) {
        fn_802C7A44();
        fn_80202718();
        fn_801F1C24(&stack[0]);
        fn_802C7730(&stack[0]);
        temp_r3 = fn_801EA470();
        if (temp_r3) {
            var_r3 = lbl_8055EBA0[2];
        } else {
            var_r3 = lbl_8055EBA0[1];
        }
        fn_802CD37C(var_r3, 0, 0, 0, lbl_8055EB98[0], lbl_8055EB98[1]);
        fn_802CDB5C(0);
        fn_802C7A94(1);
        if (!temp_r3) {
            fn_802C9648(lbl_80562E70);
            fn_802CDB5C(1);
            fn_802C7A94(2);
            fn_802C7A94(3);
            fn_80287A34(0);
            fn_802C967C();
            fn_802CDB5C(2);
            fn_802879E4(0);
            fn_802C7A94(4);
        }
        fn_801FA6B8();
        fn_802C7730(&stack[0]);
        fn_802CDB5C(3);
        fn_802C7A50();
        if (!temp_r3) {
            fn_8029790C(0);
            fn_801F4DCC();
            fn_802CDB5C(4);
        }
        fn_802C7AD4();
        fn_802CDAA8();
    } else {
        fn_802B01A8();
    }
}

extern void fn_802B0144(void);
void fn_801EB634_keep(void);
/* Store the square of scale into the first of the two global render scale factors. */
void fn_801EBEF4(f32 scale) {
    lbl_8055EB98[0] = scale * scale;
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
#pragma use_lmw_stmw off
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_801EBF00(void) {
    /* Draw the active weather layer while the EB effect is enabled: hide the two
     * UI markers, draw model lbl_8055AFB8 with the view matrix scaled by
     * (1 - lbl_8055EBA4), then draw model lbl_8055AFBC yawed by the entry's +0xE0
     * angle and tinted/brightened by its +0xD8 fade. If disabled, run the fallback fn_802B05D8. */
    struct Locals {
        f32 rotMtx[9];           /* yaw-rotation matrix for lbl_8055AFBC */
        volatile f32 viewPos[3]; /* camera translation, stored but never read */
        f32 modelMtx[12];        /* view matrix with scaled translation for lbl_8055AFB8 */
    } l;
    char *entry;                 /* current 0xE0-byte weather entry */
    f32 *viewMtx;
    f32 scale, sine, tmp, fade, magnitude, cosine;
    s32 scaled, intensity;
    if (lbl_8055EBA0 != 0) {
        ((EBF00Widget *)lbl_804885E8[3])->setVisible(0);
        if (lbl_8055AFB8 != -1) {
            fn_802C8B08(l.modelMtx);
            scale = lbl_80562E68 - lbl_8055EBA4;
            l.modelMtx[9] = l.modelMtx[9] * scale;
            l.modelMtx[10] = l.modelMtx[10] * scale;
            l.modelMtx[11] = l.modelMtx[11] * scale;
            l.modelMtx[0] = lbl_80562E68;
            l.modelMtx[1] = lbl_80562E74;
            l.modelMtx[2] = lbl_80562E74;
            l.modelMtx[3] = lbl_80562E74;
            l.modelMtx[4] = lbl_80562E68;
            l.modelMtx[5] = lbl_80562E74;
            l.modelMtx[6] = lbl_80562E74;
            l.modelMtx[7] = lbl_80562E74;
            l.modelMtx[8] = lbl_80562E68;
            fn_802C744C(lbl_8055AFB8, l.modelMtx);
        }
        ((EBF00Widget *)lbl_804885E8[6])->setVisible(0);
        entry = fn_801E7E34() + fn_801E85B4() * 0xE0;
        fade = *(f32 *)(entry + 0xD8);
        magnitude = (f32)__fabs((double)fade);
        if (!(magnitude <= lbl_80558DC4[0])) {
            scaled = (s32)(lbl_80562E78 * fade);
            scaled = scaled > 0 ? scaled : 0;
            intensity = 0xFF;
            if (scaled < 0xFF) intensity = scaled;
            fn_802C9474(0xFF000000 | ((intensity & 0xff) << 16) | ((intensity & 0xff) << 8) | (intensity & 0xff));
            viewMtx = fn_802C86DC();
            l.viewPos[0] = viewMtx[9];
            l.viewPos[1] = viewMtx[10];
            l.viewPos[2] = viewMtx[11];
            tmp = *(f32 *)(entry + 0xE0);
            cosine = (f32)cos(tmp);
            sine = (f32)sin(tmp);
            l.rotMtx[0] = cosine;
            l.rotMtx[1] = lbl_80562E74;
            l.rotMtx[2] = -sine;
            l.rotMtx[3] = lbl_80562E74;
            l.rotMtx[4] = lbl_80562E68;
            l.rotMtx[5] = lbl_80562E74;
            l.rotMtx[6] = sine;
            l.rotMtx[7] = lbl_80562E74;
            l.rotMtx[8] = cosine;
            tmp = lbl_80562E7C * *(f32 *)(entry + 0xD8);
            fn_802C9900(lbl_80562E68 < tmp ? lbl_80562E68 : tmp);
            fn_802C744C(lbl_8055AFBC, l.rotMtx);
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
#define gEBDefaultValue lbl_8055EBA4
/* Read the EB ("Simple Model") subsystem's scale parameter: 0.5 unless the
 * parameter archive loaded by fn_801EB9FC supplies another value. The sun /
 * lens-flare mover scales its offset by it (fn_8029231C) and the weather draw
 * shrinks the model translation by 1 - it (fn_801EBF00). */
f32 fn_801EC114(void) {
    return gEBDefaultValue;
}
#undef gEBDefaultValue

void fn_801EC11C(void) {
    // If the EB resource context was never loaded, run its fallback path.
    if (*(s32 *)&lbl_8055EBA0 == 0) {
        fn_802AEAA8();
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_802C6FB4(s32);
extern "C" void fn_802C703C(s32);
extern "C" void fn_801EC130(s32 unused, void *arg1, s32 arg2) {
    /* If arg1 has a valid secondary id (offset +4 != -1), update it via
       fn_802C6FB4(arg2) and fn_802C703C(arg1[1]). If arg1's type (offset +0)
       is 1, look up its object via fn_801EB110 and invoke virtual f3(arg1). */
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
extern s32 fn_801EB96C(s32 *, s32);
extern void fn_801EB634(void *, s32);
#pragma dont_inline on
