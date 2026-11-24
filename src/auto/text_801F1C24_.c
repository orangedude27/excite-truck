// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_801F2570(int);

struct BillboardIndices { unsigned short a[6]; };
extern void *fn_802C86DC(void);
extern float fn_801E7E18(void);
extern float PSVECDotProduct(float *, float *);
extern double fn_8002EFB0();
extern void fn_8029231C();
extern void PSVECNormalize(void *, void *);
extern void *fn_801284F8(int, void *);
__declspec(section ".data") extern int lbl_8033A6A0[2];
__declspec(section ".data") extern int lbl_8033A710[2];
#pragma push
#pragma small_data off
#pragma pop
extern int lbl_8033A628, lbl_8033A8C8;
__declspec(section ".data") extern int lbl_8033A610, lbl_8033A684;
extern const char lbl_8033A988[];
extern const char lbl_8033A6E0[];
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033A8F8;
#pragma pop
__declspec(section ".data") extern int lbl_8033A644, lbl_8033A868, lbl_8033A928;
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033AA90;
#pragma pop
extern int lbl_8055B124, lbl_8055B120;
extern float lbl_80562F40, lbl_80562F44;
extern const char lbl_8033ABA0[];
extern const char lbl_8033AB3C[];
extern const char lbl_8033AAE0[];
extern const char lbl_8033AB80[];
extern int fn_802E317C(const void *, ...);
extern int *fn_801F1CE8(int);
extern const char lbl_8033A9E8[];
extern int lbl_8055B118;
extern const char lbl_8033A740[];
extern int lbl_8055B138;
#pragma dont_inline fn_801F1CE8
#pragma push
#pragma small_data off
#pragma pop
#pragma scheduling invalid_target
#pragma dont_inline on
extern void PSVECCrossProduct(float *, float *, float *);
int fn_801F1C24(void *arg0) {
    /* Build a camera-facing orthonormal basis (right, up, forward) from the camera direction. */
    extern float lbl_80562F48;
    extern float lbl_80562F4C;
    struct Vec { float x, y, z; };
    struct Frame { struct Vec right, up, forward; };
    struct Frame *basis = (struct Frame *)arg0;
    char *camera;
    float f1, f0, f2, cameraX;

    camera = (char *)fn_802C86DC();
    f2 = lbl_80562F40;
    f0 = lbl_80562F44;
    *(volatile float *)&basis->up.x = f2;
    f1 = lbl_80562F48;
    *(volatile float *)&basis->up.y = f0;
    basis->up.z = f2;
    cameraX = *(float *)(camera + 0x18);
    basis->forward.x = cameraX * f1;
    basis->forward.y = *(float *)(camera + 0x1C) * f1;
    basis->forward.z = *(float *)(camera + 0x20) * f1;
    PSVECCrossProduct((float *)&basis->up, (float *)&basis->forward, (float *)&basis->right);
    if (PSVECDotProduct((float *)&basis->right, (float *)&basis->right) > lbl_80562F4C) {
        PSVECNormalize((float *)&basis->right, (float *)&basis->right);
    } else {
        f2 = lbl_80562F40;
        f1 = lbl_80562F44;
        basis->right.y = f2;
        basis->right.x = f1;
        basis->right.z = f2;
    }
    PSVECCrossProduct((float *)&basis->forward, (float *)&basis->right, (float *)&basis->up);
}

int *fn_801F1CE8(int params) {
    /* Return the address of the raw 16-byte value field (+0x2C) of a TMH render parameter block. */
    return (int *)(params + 0x2C);
}

int fn_801F1CF0(int arg0) {
    /* Return whether the vector from the camera to this object (+0x24) points against the object's direction (+0x18). */
    float delta[3];
    void *camera;
    float cz, cy, cx, z, y, x;
    char *base = (char *)arg0;

    camera = fn_802C86DC();
    x = *(float *)(base + 0x24);
    y = *(float *)(base + 0x28);
    cx = *(float *)((char *)camera + 0x24);
    z = *(float *)(base + 0x2C);
    delta[0] = x - cx;
    cy = *(float *)((char *)camera + 0x28);
    delta[1] = y - cy;
    cz = *(float *)((char *)camera + 0x2C);
    delta[2] = z - cz;
    return PSVECDotProduct(delta, (float *)(base + 0x18)) < lbl_80562F40;
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801F1D68(void) {
#define RegisterClassSlot fn_801284F8
#define GenericTag lbl_8055B118
#define GenericVtable lbl_8033A9E8
    /* Register the "Generic" class: look up its 4-byte slot in the class
       registry and install its vtable there. */
    void **slot = (void **)RegisterClassSlot(4, (void *)&GenericTag);
    if (slot != 0) {
        *slot = (void *)&GenericVtable;
    }
#undef RegisterClassSlot
#undef GenericTag
#undef GenericVtable
}

void *fn_801F1DA4(void) {
    /* Allocate a PointFacing instance and point it at its vtable. */
    void **object = (void **)fn_801284F8(4, (void *)&lbl_8033A610);
    if (object != 0) {
        *object = (void *)lbl_8033A988;
    }
    return (void *)object;
}

#pragma scheduling invalid_target
void *fn_801F1DE4(void) {
    /* Allocate an AxisFacing instance (tag "AxisFacing", 4 bytes) and point it at its vtable. */
    extern const char lbl_8033A61C[], lbl_8033A9B8[];
    void **object = (void **)fn_801284F8(4, (void *)lbl_8033A61C);
    if (object != 0) {
        *object = (void *)lbl_8033A9B8;
    }
    return (void *)object;
}
#pragma scheduling on
/* Allocates and initializes a 0x40-byte "Sky" object (vtable lbl_8033A928)
 * with a 3x3 identity matrix (stored as 12 floats starting at +0x0C),
 * flags at +0x08/+0x3C, and zeros elsewhere. */
void fn_801F1E24(void) {
    void *object = fn_801284F8(0x40, &lbl_8055B120);
    if (object != 0) {
        float zero;
        float one;
        one = 1.0f;
        *(void **)object = &lbl_8033A928;
        zero = 0.0f;
        *(int *)((char *)object + 0x3C) = 0;
        *(float *)((char *)object + 0xC) = one;
        *(float *)((char *)object + 0x10) = zero;
        *(float *)((char *)object + 0x14) = zero;
        *(float *)((char *)object + 0x18) = zero;
        *(float *)((char *)object + 0x1C) = one;
        *(float *)((char *)object + 0x20) = zero;
        *(float *)((char *)object + 0x24) = zero;
        *(float *)((char *)object + 0x28) = zero;
        *(float *)((char *)object + 0x2C) = one;
        *(float *)((char *)object + 0x30) = zero;
        *(float *)((char *)object + 0x34) = zero;
        *(float *)((char *)object + 0x38) = zero;
        *(int *)((char *)object + 8) = 1;
    }
}
#pragma push
#pragma small_data off
void fn_801F1EA8(void) {
    /* Allocate and initialize a Sun object (0x14 bytes, vtable lbl_8033A8F8). */
    #define kSunAllocTag   lbl_8055B124
    #define vtbl_Sun       lbl_8033A8F8

    void *p = fn_801284F8(0x14, &kSunAllocTag);
    if (p != 0) {
        *(void **)p = &vtbl_Sun;
        *(int *)((char *)p + 0x10) = 0;
    }

    #undef kSunAllocTag
    #undef vtbl_Sun
}
#pragma pop
extern int fn_802CAC28(void *, int);
extern void *fn_802C86DC(void);
extern int lbl_8033A628, lbl_8033A8C8, lbl_8033A660, lbl_8033AC58;
__declspec(section ".data") extern int lbl_8033A660;
__declspec(section ".data") extern int lbl_8033AC58;
extern char lbl_8033A808[];
__declspec(section ".data") extern int lbl_8033A958;
extern int lbl_8055B128;
extern float lbl_80562F40;
#pragma push
#pragma small_data off
extern int lbl_8033A628;
extern int lbl_8033A8C8;
#pragma pop
__declspec(section ".data") extern int lbl_8033A628;
__declspec(section ".data") extern int lbl_8033A8C8;
/* Allocates a 12-byte AmbientColor object (lbl_8033A628 tag) and initializes its vtable to lbl_8033A8C8 with fields cleared. */
void fn_801F1EEC(void) {
    void *object = fn_801284F8(12, &lbl_8033A628);
    if (object != 0) {
        *(void **)object = &lbl_8033A8C8;
        *(int *)((char *)object + 8) = 0;
        *(char *)((char *)object + 4) = 0;
    }
}

__declspec(section ".data") extern int lbl_8033A638;
__declspec(section ".data") extern int lbl_8033A898;
// Allocate and initialize a 12-byte object: install lbl_8033A898 at +0,
// clear the byte flag at +4 and the field at +8.
void fn_801F1F38(void) {
    void *p = fn_801284F8(12, &lbl_8033A638);
    if (p != 0) {
        *(void **)p = &lbl_8033A898;
        *(int *)((char *)p + 8) = 0;
        *(char *)((char *)p + 4) = 0;
    }
}

/* Allocate and initialize a 12-byte object with vtable lbl_8033A868. */
void fn_801F1F84(void) {
    void *obj = fn_801284F8(0xC, &lbl_8033A644);
    if (obj != 0) {
        float zero = lbl_80562F40;
        *(void **)obj = &lbl_8033A868;
        *(float *)((char *)obj + 8) = zero;
        *(char *)((char *)obj + 4) = 0;
    }
}

__declspec(section ".data") extern int lbl_8033A654;
__declspec(section ".data") extern int lbl_8033A838;
/* Allocates and initializes a fog-color object (vtable lbl_8033A838). */
void fn_801F1FD4(void) {
    void *object = fn_801284F8(12, &lbl_8033A654);
    if (object != 0) {
        *(void **)object = &lbl_8033A838;
        *(int *)((char *)object + 8) = 0;
        *(char *)((char *)object + 4) = 0;
    }
}

#pragma push
#pragma small_data off
/* Allocate an 8-byte "Rotator" object (tag lbl_8055B128) and initialize its vtable/data fields. */
void fn_801F2020(void) {
    void *object = fn_801284F8(8, &lbl_8055B128);
    if (object != 0) {
        *(void **)object = lbl_8033A808;
        *(int *)((char *)object + 4) = 0;
    }
}
#pragma push
#pragma scheduling invalid_target
void *fn_801F2064(void) {
    /* Allocate an 8-byte CollisionSpace object: set its vtable and load "turn.tex". */
    void *object = fn_801284F8(8, &lbl_8033A660);
    if (object) { *(void **)object = &lbl_8033A958; *(int *)((char *)object + 4) = fn_802CAC28(&lbl_8033AC58, 0); }
    return object;
}
#pragma pop
extern const char lbl_8033A66C[];
extern const char lbl_8033A7D0[];
#pragma scheduling invalid_target
void *fn_801F20C8(void) {
    void **object = (void **)fn_801284F8(4, (void *)lbl_8033A66C);
    /* Allocate an "OptTerrain" object and point it at its vtable. */
    if (object != 0) {
        *object = (void *)lbl_8033A7D0;
    }
    return object;
}
#pragma scheduling on

#pragma push
#pragma small_data off
/* Construct an XFader object (12 bytes): allocate it with tag "XFader", set its vtable, and clear two fields. */
void fn_801F2108(void) {
    extern int lbl_8055B130;
    extern int lbl_8033A7A0[];
#define XFader_name lbl_8055B130
#define XFader_vtable lbl_8033A7A0
    void *fader = fn_801284F8(0xC, &XFader_name);
    if (fader != 0) {
        *(void **)fader = &XFader_vtable;
        *(int *)((char *)fader + 4) = 0;
        *(int *)((char *)fader + 8) = 0;
    }
#undef XFader_name
#undef XFader_vtable
}

extern const char lbl_8033A678[];
extern const char lbl_8033A770[];
#pragma scheduling invalid_target
void *fn_801F2150(void) {
    void **object = (void **)fn_801284F8(4, (void *)lbl_8033A678);
    /* Allocate a FlareSource instance and point it at its vtable. */
    if (object != 0) {
        *object = (void *)lbl_8033A770;
    }
    return object;
}

void fn_801F2190(void) {
#define RegisterClassSlot fn_801284F8
#define WaterTag lbl_8055B138
#define WaterVtable lbl_8033A740
    /* Register the "Water" class: look up its 4-byte slot in the class
       registry and install its vtable there. */
    void **slot = (void **)RegisterClassSlot(4, (void *)&WaterTag);
    if (slot != 0) {
        *slot = (void *)&WaterVtable;
    }
#undef RegisterClassSlot
#undef WaterTag
#undef WaterVtable
}
#pragma scheduling on
#pragma dont_inline off

void *fn_801F21CC(void) {
    /* Allocate a PinkTriangle instance (tag "PinkTriangle", 4 bytes) and point it at its vtable, lbl_8033A6E0. */
    void **object = (void **)fn_801284F8(4, (void *)&lbl_8033A684);
    if (object != 0) {
        *object = (void *)lbl_8033A6E0;
    }
    return (void *)object;
}

#pragma scheduling invalid_target
void *fn_801F220C(void) {
    extern const char lbl_8033A694[], lbl_8033A6B0[];
    void **object = (void **)fn_801284F8(4, (void *)lbl_8033A694);
    /* Allocate a FacingTest instance and point it at its vtable. */
    if (object != 0) {
        *object = (void *)lbl_8033A6B0;
    }
    return (void *)object;
}
#pragma scheduling on

#pragma scheduling on

#pragma push
#pragma small_data off
/* Allocate an 8-byte "Scrolling" object and, if successful, set its vtable
 * pointer (lbl_8033A710) and clear its field at offset +4. */
void fn_801F224C(void) {
#define kScrollingTag lbl_8033A6A0
#define kScrollingVTable lbl_8033A710
    void *p;
    if ((p = fn_801284F8(8, &kScrollingTag)) != 0) {
        *(void **)p = &kScrollingVTable;
        *(int *)((char *)p + 4) = 0;
    }
#undef kScrollingTag
#undef kScrollingVTable
}
#pragma pop
int fn_801F2294(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_801F22D4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_801F2314(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma small_data off
int fn_801F2354(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma small_data off
int fn_801F2394(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

int fn_801F23D4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

int fn_801F2414(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_801F2454(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_801F2494(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_801F24D4(void *unused, void *head) {
    /* Walks a linked list of model-instance nodes, updating each one's visibility/distance via DrawModelInstance. Node layout: +4 instance id, +0xC next. */
    void *node = head;
    while (node != 0) {
        DrawModelInstance(*(int *)((char *)node + 4));
        node = *(void **)((char *)node + 0xC);
    }
}

/* Tear down a tree node: release its left/right subtrees and the node's own model. */
void fn_801F2514(void *arg0, void *arg1) {
    int stack[12];
    fn_801F1C24(&stack[0]);
    fn_802C7730(&stack[0]);
    if (arg1 != 0) {
        fn_801F2570(*(int *)((char *)arg1 + 4));
        DrawModelInstance(*(int *)((char *)*(void **)arg1 + 4));
        fn_801F2570(*(int *)((char *)arg1 + 8));
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_801F2570(int node) {
    void *nL;
    void *nR;
    void *nLL;
    void *nLR;
    void *nRL;
    void *nRR;
    void *nLLL;
    void *nLLR;
    void *nLRL;
    void *nLRR;
    void *nRLL;
    void *nRLR;
    void *nRRL;
    void *nRRR;
    void *nLLLL;
    void *nLLLR;
    void *nLLRL;
    void *nLLRR;
    void *nLRLL;
    void *nLRLR;
    void *nLRRL;
    void *nLRRR;
    void *nRLLL;
    void *nRLLR;
    void *nRLRL;
    void *nRLRR;
    void *nRRLL;
    void *nRRLR;
    void *nRRRL;
    void *nRRRR;
    void *nLLLLL;
    void *nLLLLR;
    void *nLLLRL;
    void *nLLLRR;
    void *nLLRLL;
    void *nLLRLR;
    void *nLLRRL;
    void *nLLRRR;
    void *nLRLLL;
    void *nLRLLR;
    void *nLRLRL;
    void *nLRLRR;
    void *nLRRLL;
    void *nLRRLR;
    void *nLRRRL;
    void *nLRRRR;
    void *nRLLLL;
    void *nRLLLR;
    void *nRLLRL;
    void *nRLLRR;
    void *nRLRLL;
    void *nRLRLR;
    void *nRLRRL;
    void *nRLRRR;
    void *nRRLLL;
    void *nRRLLR;
    void *nRRLRL;
    void *nRRLRR;
    void *nRRRLL;
    void *nRRRLR;
    void *nRRRRL;
    void *nRRRRR;
    /* In-order walk of the model-instance tree rooted at `node`, unrolled five
     * levels deep: for each node recurse into its left child (+4), hide the
     * node's model instance (DrawModelInstance), then recurse into its right child
     * (+8); beyond five levels the walk restarts via fn_801F2570. Local names
     * nL/nR/nLL/... encode the left/right path from this root. */
    if ((void *)node != 0) {
        nL = *(void **)((char *)(void *)node + 4);
        if (nL != 0) {
            nLL = *(void **)((char *)nL + 4);
            if (nLL != 0) {
                nLLL = *(void **)((char *)nLL + 4);
                if (nLLL != 0) {
                    nLLLL = *(void **)((char *)nLLL + 4);
                    if (nLLLL != 0) {
                        nLLLLL = *(void **)((char *)nLLLL + 4);
                        if (nLLLLL != 0) {
                            fn_801F2570(*(int *)((char *)nLLLLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLLLL) + 4));
                            fn_801F2570(*(int *)((char *)nLLLLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLLLL) + 4));
                        nLLLLR = *(void **)((char *)nLLLL + 8);
                        if (nLLLLR != 0) {
                            fn_801F2570(*(int *)((char *)nLLLLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLLLR) + 4));
                            fn_801F2570(*(int *)((char *)nLLLLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nLLL) + 4));
                    nLLLR = *(void **)((char *)nLLL + 8);
                    if (nLLLR != 0) {
                        nLLLRL = *(void **)((char *)nLLLR + 4);
                        if (nLLLRL != 0) {
                            fn_801F2570(*(int *)((char *)nLLLRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLLRL) + 4));
                            fn_801F2570(*(int *)((char *)nLLLRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLLLR) + 4));
                        nLLLRR = *(void **)((char *)nLLLR + 8);
                        if (nLLLRR != 0) {
                            fn_801F2570(*(int *)((char *)nLLLRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLLRR) + 4));
                            fn_801F2570(*(int *)((char *)nLLLRR + 8));
                        }
                    }
                }
                DrawModelInstance(*(int *)((char *)(*(void **)nLL) + 4));
                nLLR = *(void **)((char *)nLL + 8);
                if (nLLR != 0) {
                    nLLRL = *(void **)((char *)nLLR + 4);
                    if (nLLRL != 0) {
                        nLLRLL = *(void **)((char *)nLLRL + 4);
                        if (nLLRLL != 0) {
                            fn_801F2570(*(int *)((char *)nLLRLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLRLL) + 4));
                            fn_801F2570(*(int *)((char *)nLLRLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLLRL) + 4));
                        nLLRLR = *(void **)((char *)nLLRL + 8);
                        if (nLLRLR != 0) {
                            fn_801F2570(*(int *)((char *)nLLRLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLRLR) + 4));
                            fn_801F2570(*(int *)((char *)nLLRLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nLLR) + 4));
                    nLLRR = *(void **)((char *)nLLR + 8);
                    if (nLLRR != 0) {
                        nLLRRL = *(void **)((char *)nLLRR + 4);
                        if (nLLRRL != 0) {
                            fn_801F2570(*(int *)((char *)nLLRRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLRRL) + 4));
                            fn_801F2570(*(int *)((char *)nLLRRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLLRR) + 4));
                        nLLRRR = *(void **)((char *)nLLRR + 8);
                        if (nLLRRR != 0) {
                            fn_801F2570(*(int *)((char *)nLLRRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLLRRR) + 4));
                            fn_801F2570(*(int *)((char *)nLLRRR + 8));
                        }
                    }
                }
            }
            DrawModelInstance(*(int *)((char *)(*(void **)nL) + 4));
            nLR = *(void **)((char *)nL + 8);
            if (nLR != 0) {
                nLRL = *(void **)((char *)nLR + 4);
                if (nLRL != 0) {
                    nLRLL = *(void **)((char *)nLRL + 4);
                    if (nLRLL != 0) {
                        nLRLLL = *(void **)((char *)nLRLL + 4);
                        if (nLRLLL != 0) {
                            fn_801F2570(*(int *)((char *)nLRLLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRLLL) + 4));
                            fn_801F2570(*(int *)((char *)nLRLLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLRLL) + 4));
                        nLRLLR = *(void **)((char *)nLRLL + 8);
                        if (nLRLLR != 0) {
                            fn_801F2570(*(int *)((char *)nLRLLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRLLR) + 4));
                            fn_801F2570(*(int *)((char *)nLRLLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nLRL) + 4));
                    nLRLR = *(void **)((char *)nLRL + 8);
                    if (nLRLR != 0) {
                        nLRLRL = *(void **)((char *)nLRLR + 4);
                        if (nLRLRL != 0) {
                            fn_801F2570(*(int *)((char *)nLRLRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRLRL) + 4));
                            fn_801F2570(*(int *)((char *)nLRLRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLRLR) + 4));
                        nLRLRR = *(void **)((char *)nLRLR + 8);
                        if (nLRLRR != 0) {
                            fn_801F2570(*(int *)((char *)nLRLRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRLRR) + 4));
                            fn_801F2570(*(int *)((char *)nLRLRR + 8));
                        }
                    }
                }
                DrawModelInstance(*(int *)((char *)(*(void **)nLR) + 4));
                nLRR = *(void **)((char *)nLR + 8);
                if (nLRR != 0) {
                    nLRRL = *(void **)((char *)nLRR + 4);
                    if (nLRRL != 0) {
                        nLRRLL = *(void **)((char *)nLRRL + 4);
                        if (nLRRLL != 0) {
                            fn_801F2570(*(int *)((char *)nLRRLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRRLL) + 4));
                            fn_801F2570(*(int *)((char *)nLRRLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLRRL) + 4));
                        nLRRLR = *(void **)((char *)nLRRL + 8);
                        if (nLRRLR != 0) {
                            fn_801F2570(*(int *)((char *)nLRRLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRRLR) + 4));
                            fn_801F2570(*(int *)((char *)nLRRLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nLRR) + 4));
                    nLRRR = *(void **)((char *)nLRR + 8);
                    if (nLRRR != 0) {
                        nLRRRL = *(void **)((char *)nLRRR + 4);
                        if (nLRRRL != 0) {
                            fn_801F2570(*(int *)((char *)nLRRRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRRRL) + 4));
                            fn_801F2570(*(int *)((char *)nLRRRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nLRRR) + 4));
                        nLRRRR = *(void **)((char *)nLRRR + 8);
                        if (nLRRRR != 0) {
                            fn_801F2570(*(int *)((char *)nLRRRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nLRRRR) + 4));
                            fn_801F2570(*(int *)((char *)nLRRRR + 8));
                        }
                    }
                }
            }
        }
        DrawModelInstance(*(int *)((char *)(*(void **)(void *)node) + 4));
        nR = *(void **)((char *)(void *)node + 8);
        if (nR != 0) {
            nRL = *(void **)((char *)nR + 4);
            if (nRL != 0) {
                nRLL = *(void **)((char *)nRL + 4);
                if (nRLL != 0) {
                    nRLLL = *(void **)((char *)nRLL + 4);
                    if (nRLLL != 0) {
                        nRLLLL = *(void **)((char *)nRLLL + 4);
                        if (nRLLLL != 0) {
                            fn_801F2570(*(int *)((char *)nRLLLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLLLL) + 4));
                            fn_801F2570(*(int *)((char *)nRLLLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRLLL) + 4));
                        nRLLLR = *(void **)((char *)nRLLL + 8);
                        if (nRLLLR != 0) {
                            fn_801F2570(*(int *)((char *)nRLLLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLLLR) + 4));
                            fn_801F2570(*(int *)((char *)nRLLLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nRLL) + 4));
                    nRLLR = *(void **)((char *)nRLL + 8);
                    if (nRLLR != 0) {
                        nRLLRL = *(void **)((char *)nRLLR + 4);
                        if (nRLLRL != 0) {
                            fn_801F2570(*(int *)((char *)nRLLRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLLRL) + 4));
                            fn_801F2570(*(int *)((char *)nRLLRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRLLR) + 4));
                        nRLLRR = *(void **)((char *)nRLLR + 8);
                        if (nRLLRR != 0) {
                            fn_801F2570(*(int *)((char *)nRLLRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLLRR) + 4));
                            fn_801F2570(*(int *)((char *)nRLLRR + 8));
                        }
                    }
                }
                DrawModelInstance(*(int *)((char *)(*(void **)nRL) + 4));
                nRLR = *(void **)((char *)nRL + 8);
                if (nRLR != 0) {
                    nRLRL = *(void **)((char *)nRLR + 4);
                    if (nRLRL != 0) {
                        nRLRLL = *(void **)((char *)nRLRL + 4);
                        if (nRLRLL != 0) {
                            fn_801F2570(*(int *)((char *)nRLRLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLRLL) + 4));
                            fn_801F2570(*(int *)((char *)nRLRLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRLRL) + 4));
                        nRLRLR = *(void **)((char *)nRLRL + 8);
                        if (nRLRLR != 0) {
                            fn_801F2570(*(int *)((char *)nRLRLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLRLR) + 4));
                            fn_801F2570(*(int *)((char *)nRLRLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nRLR) + 4));
                    nRLRR = *(void **)((char *)nRLR + 8);
                    if (nRLRR != 0) {
                        nRLRRL = *(void **)((char *)nRLRR + 4);
                        if (nRLRRL != 0) {
                            fn_801F2570(*(int *)((char *)nRLRRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLRRL) + 4));
                            fn_801F2570(*(int *)((char *)nRLRRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRLRR) + 4));
                        nRLRRR = *(void **)((char *)nRLRR + 8);
                        if (nRLRRR != 0) {
                            fn_801F2570(*(int *)((char *)nRLRRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRLRRR) + 4));
                            fn_801F2570(*(int *)((char *)nRLRRR + 8));
                        }
                    }
                }
            }
            DrawModelInstance(*(int *)((char *)(*(void **)nR) + 4));
            nRR = *(void **)((char *)nR + 8);
            if (nRR != 0) {
                nRRL = *(void **)((char *)nRR + 4);
                if (nRRL != 0) {
                    nRRLL = *(void **)((char *)nRRL + 4);
                    if (nRRLL != 0) {
                        nRRLLL = *(void **)((char *)nRRLL + 4);
                        if (nRRLLL != 0) {
                            fn_801F2570(*(int *)((char *)nRRLLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRLLL) + 4));
                            fn_801F2570(*(int *)((char *)nRRLLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRRLL) + 4));
                        nRRLLR = *(void **)((char *)nRRLL + 8);
                        if (nRRLLR != 0) {
                            fn_801F2570(*(int *)((char *)nRRLLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRLLR) + 4));
                            fn_801F2570(*(int *)((char *)nRRLLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nRRL) + 4));
                    nRRLR = *(void **)((char *)nRRL + 8);
                    if (nRRLR != 0) {
                        nRRLRL = *(void **)((char *)nRRLR + 4);
                        if (nRRLRL != 0) {
                            fn_801F2570(*(int *)((char *)nRRLRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRLRL) + 4));
                            fn_801F2570(*(int *)((char *)nRRLRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRRLR) + 4));
                        nRRLRR = *(void **)((char *)nRRLR + 8);
                        if (nRRLRR != 0) {
                            fn_801F2570(*(int *)((char *)nRRLRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRLRR) + 4));
                            fn_801F2570(*(int *)((char *)nRRLRR + 8));
                        }
                    }
                }
                DrawModelInstance(*(int *)((char *)(*(void **)nRR) + 4));
                nRRR = *(void **)((char *)nRR + 8);
                if (nRRR != 0) {
                    nRRRL = *(void **)((char *)nRRR + 4);
                    if (nRRRL != 0) {
                        nRRRLL = *(void **)((char *)nRRRL + 4);
                        if (nRRRLL != 0) {
                            fn_801F2570(*(int *)((char *)nRRRLL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRRLL) + 4));
                            fn_801F2570(*(int *)((char *)nRRRLL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRRRL) + 4));
                        nRRRLR = *(void **)((char *)nRRRL + 8);
                        if (nRRRLR != 0) {
                            fn_801F2570(*(int *)((char *)nRRRLR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRRLR) + 4));
                            fn_801F2570(*(int *)((char *)nRRRLR + 8));
                        }
                    }
                    DrawModelInstance(*(int *)((char *)(*(void **)nRRR) + 4));
                    nRRRR = *(void **)((char *)nRRR + 8);
                    if (nRRRR != 0) {
                        nRRRRL = *(void **)((char *)nRRRR + 4);
                        if (nRRRRL != 0) {
                            fn_801F2570(*(int *)((char *)nRRRRL + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRRRL) + 4));
                            fn_801F2570(*(int *)((char *)nRRRRL + 8));
                        }
                        DrawModelInstance(*(int *)((char *)(*(void **)nRRRR) + 4));
                        nRRRRR = *(void **)((char *)nRRRR + 8);
                        if (nRRRRR != 0) {
                            fn_801F2570(*(int *)((char *)nRRRRR + 4));
                            DrawModelInstance(*(int *)((char *)(*(void **)nRRRRR) + 4));
                            fn_801F2570(*(int *)((char *)nRRRRR + 8));
                        }
                    }
                }
            }
        }
    }
}
#pragma use_lmw_stmw reset
#pragma pop

void fn_801F2D84(void *unused, void *node) {
    /* Builds camera basis, updates render state, then applies DrawModelInstance to each node in a linked list. */
    extern int fn_801F1C24(void *);
    extern int fn_802C7730(void *);
    int stack[12];
    void *p = node;

    fn_801F1C24(&stack[0]);
    fn_802C7730(&stack[0]);
    goto check;

body:
    DrawModelInstance(*(int *)((char *)p + 4));
    p = *(void **)((char *)p + 0xC);

check:
    if (p != 0) {
        goto body;
    }
}

void fn_801F2DD4(void *unused, void *node) {
    /* Builds camera basis, updates render state, then applies DrawModelInstance to each node in a linked list. */
    extern int fn_801F1C24(void *);
    extern int fn_802C7730(void *);
    int stack[12];
    void *p = node;
    fn_801F1C24(&stack[0]);
    fn_802C7730(&stack[0]);
    goto check;
body:
    DrawModelInstance(*(int *)((char *)p + 4));
    p = *(void **)((char *)p + 0xC);
check:
    if (p != 0) {
        goto body;
    }
}

#pragma push
#pragma small_data off
#pragma processor 750
#pragma use_lmw_stmw off
void *__dt__14CollisionSpaceFv_801F2E24(void *arg0, int arg1) {
    /* Scalar-deleting destructor for CollisionSpace: reset vtable, destroy owned subobject, and optionally free. */
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_8033A958;
        fn_802CAC54(*(void **)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
void fn_801F2E88(void *arg0, void *arg1) {
    extern float fn_801F3174(void);
    extern void fn_801F3198(void *);
    extern void fn_801F3158(float *,float *);
    extern void fn_801F3124(unsigned int *,unsigned int *);
    extern float lbl_80562F48, lbl_80562F50, lbl_80562F54, lbl_80562F58, lbl_80562F5C, lbl_80562F60, lbl_80562F64;
    extern unsigned short lbl_802F9B20[6];
    extern float *GXInitLightAttnA_80144B44(void *, float, float, float);
    extern unsigned int fn_80144C68(int,int,int,int);
    extern void fn_8001BA68(void *);
    extern void fn_801C0E60(void *,void *,void *);
    extern void fn_80144B54(void *,void *);
    extern int fn_80144DAC();
    extern void fn_801BFD34(void *,void *,void *);
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *,int,void *,int);
    extern void fn_802C8D74(void);
    unsigned int vertices[4][6];
    float matrix[12];
    unsigned int base[6];
    float t4[3],t3[3],t2[3],t1[3],t0[3];
    unsigned short indices[6];
    float vec[3];
    float scale2 = lbl_80562F58, scale3 = lbl_80562F5C, scale0 = lbl_80562F50, scale1 = lbl_80562F54;
    register void *pos;
    void *p = arg1;
    while (p != 0) {
        void *camera = fn_802C86DC();
        int frame;
        float v1,v,u1,u,fu,fv;
        fn_8001BA68(vec);
        pos = (char *)p + 0x20;
        fn_801C0E60(vec,pos,(char *)camera + 0x24);
        fn_801F3198(vec);
        frame = (int)(scale0 * (-((float (*)(float,float))fn_801F3174)(vec[0],vec[2]) / scale1));
        if (frame < 0) frame += 32;
        fu = (float)(frame % 8);
        fv = (float)(frame / 8);
        u = scale2 * fu;
        v = scale3 * fv;
        u1 = scale2 + u;
        v1 = scale3 + v;
        fn_801F3158((float *)base,GXInitLightAttnA_80144B44(t0,lbl_80562F40,lbl_80562F40,lbl_80562F40));
        ((float *)base)[4]=u;
        ((float *)base)[5]=v;
        base[3]=fn_80144C68(255,255,255,255);
        fn_801F3124(vertices[0],base);
        fn_801F3124(vertices[1],base);
        fn_801F3124(vertices[2],base);
        fn_801F3124(vertices[3],base);
        *(struct BillboardIndices *)indices = *(struct BillboardIndices *)lbl_802F9B20;
        ((float *)vertices[3])[4]=u1;
        ((float *)vertices[1])[4]=u1;
        ((float *)vertices[3])[5]=v1;
        ((float *)vertices[2])[5]=v1;
        fn_80144B54(matrix,camera);
        fn_80144DAC(matrix+9,pos);
        fn_801BFD34(vertices[0],GXInitLightAttnA_80144B44(t1,lbl_80562F60,lbl_80562F44,lbl_80562F40),matrix);
        fn_801BFD34(vertices[1],GXInitLightAttnA_80144B44(t2,lbl_80562F64,lbl_80562F44,lbl_80562F40),matrix);
        fn_801BFD34(vertices[2],GXInitLightAttnA_80144B44(t3,lbl_80562F60,lbl_80562F48,lbl_80562F40),matrix);
        fn_801BFD34(vertices[3],GXInitLightAttnA_80144B44(t4,lbl_80562F64,lbl_80562F48,lbl_80562F40),matrix);
        fn_802C8BD0(*(int *)((char *)arg0+4));
        fn_802C8DB8(vertices,4,indices,6);
        fn_802C8D74();
        p=*(void **)((char *)p+12);
    }
}
#pragma pop

#pragma pop
/* Copy one 24-byte billboard vertex template (four attribute words followed by two UV
   floats) from the source record into the destination vertex. */
void fn_801F3124(unsigned int *dst, unsigned int *srcRecord) {
    unsigned int word3, word2, word1, word0;
    float float1, float0;
    volatile unsigned int *srcWords = (volatile unsigned int *)srcRecord;
    volatile float *srcFloats = (volatile float *)((char *)srcRecord + 16);
    word0 = srcWords[0];
    word1 = srcWords[1];
    word2 = srcWords[2];
    word3 = srcWords[3];
    float0 = srcFloats[0];
    float1 = srcFloats[1];
    dst[0] = word0;
    dst[1] = word1;
    dst[2] = word2;
    dst[3] = word3;
    ((float *)dst)[4] = float0;
    ((float *)dst)[5] = float1;
}

void fn_801F3158(float *dst, float *src) {
    /* Copy a 3-component (12-byte) float vector from src into dst. */
    float z, y, x;
    x = src[0];
    y = src[1];
    z = src[2];
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

float fn_801F3174(void) {
    /* atan2 wrapper: callers cast this to float(float,float); the two floats stay in
     * f1/f2 and pass straight to fn_8002EFB0, whose double result is rounded here. */
    return fn_8002EFB0();
}

// Normalize a 3D vector in place.
void fn_801F3198(void *vec) {
    PSVECNormalize(vec, vec);
}

void *fn_801F31A0(void *obj, int shouldFree) {
    /* Clear the object's field at +0x3C; optionally free the object. */
    if (obj != 0) {
        *(int *)((char *)obj + 0x3C) = 0;
        if (shouldFree > 0) fn_80128668();
    }
    return obj;
}

#pragma optimize_for_size on
void fn_801F31E8(int unused, unsigned char *data) {
    /* Byte-swap each 4-byte word in the 0x200-byte table at offset 0x2C of data (32 blocks of 16 bytes). */
    unsigned char *block = data + 0x2C;
    int blockIndex;
    for (blockIndex = 0; blockIndex < 0x20; blockIndex++) {
        unsigned char temp;
        temp = block[0]; block[0] = block[3]; block[3] = temp;
        temp = block[1]; block[1] = block[2]; block[2] = temp;
        temp = block[4]; block[4] = block[7]; block[7] = temp;
        temp = block[5]; block[5] = block[6]; block[6] = temp;
        temp = block[8]; block[8] = block[0xB]; block[0xB] = temp;
        temp = block[9]; block[9] = block[0xA]; block[0xA] = temp;
        temp = block[0xC]; block[0xC] = block[0xF]; block[0xF] = temp;
        temp = block[0xD]; block[0xD] = block[0xE]; block[0xE] = temp;
        block += 0x10;
    }
}
#pragma optimize_for_size reset
void fn_801F3280(void *obj, int value) {
    /* Set the object's field at +0x3C (the one fn_801F31A0 clears) to value. */
    *(int *)((char *)obj + 0x3C) = value;
}

extern float lbl_80562F64, lbl_80562F70;
extern double cos(double);
extern float fn_801E8738(int);
extern void fn_802C70AC(int, void *, int, int);

/* One of the 32 direction planes of the sky dome: the normal and the angle
 * around it the plane covers. */
struct SkyPlane {
    float normal[3];
    float angle;
};

/* The resource a Sky draws: the model to draw (+0x04) and the 32 direction
 * planes at +0x2C, which fn_801F31E8 byte-swaps after loading. */
struct SkyResource {
    int unk_00;
    int model;
    int pad_08[9];
    struct SkyPlane planes[32];
};

/* The sky: a 3x4 matrix (rotation at +0x0C, position at +0x30, which is kept on
 * the camera) and the resource to draw. */
struct Sky {
    void *vtable;
    int planeCount;               /* planes the camera looks along */
    int mode;                     /* 1 tests every plane, anything else takes all */
    float matrix[12];
    struct SkyResource *resource;
};

/* The 3x4 camera matrix of fn_802C86DC: three basis columns, then the position. */
struct Camera {
    float basis[6];
    float viewAxis[3];            /* the axis the camera looks along */
    float position[3];
};

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_loop_invariants off
void fn_801F3288(struct Sky *sky) {
    /* Works out which of the sky dome's 32 direction planes the camera looks
     * along: a plane counts when the camera's view axis lies nearer to its
     * normal than the plane's own angle, widened by the scene's sky parameter.
     * The sky's matrix keeps its position on the camera, and the matrix goes to
     * the sky model together with the mask of the planes that counted. */
    float baseAngle, dot;
    struct SkyPlane *plane;
    struct SkyPlane *walk;
    struct Camera *camera;
    int mask;
    unsigned int i;
    sky->planeCount = 0;
    if (sky->resource != 0 && sky->mode != 0) {
        camera = (struct Camera *)fn_802C86DC();
        sky->matrix[9] = camera->position[0];
        walk = (struct SkyPlane *)sky->resource;   /* the resource; its planes start at +0x2C */
        sky->matrix[10] = camera->position[1];
        plane = (struct SkyPlane *)((char *)walk + 0x2C);
        sky->matrix[11] = camera->position[2];
        if (sky->mode == 1) {
            mask = 1;
            baseAngle = lbl_80562F64 * (lbl_80562F70 * fn_801E8738(-1));
            i = 0;
            walk = plane;
            do {
                dot = PSVECDotProduct(camera->viewAxis, plane->normal);
                if (dot > (float)cos(baseAngle + walk->angle)) {
                    mask |= 1 << i;
                    sky->planeCount = sky->planeCount + 1;
                }
                i++;
                plane = plane + 1;
                walk = walk + 1;
            } while (i < 0x20);
        } else {
            sky->planeCount = 0x20;
            mask = -1;
        }
        fn_802C70AC(sky->resource->model, sky->matrix, -1, mask);
    }
}
#pragma pop
/* Fetches a byte buffer by id and byte-swaps four 4-byte words in place (big-endian to little-endian conversion for 32-bit fields). */
void fn_801F33BC(void *unused, int id) {
    extern int *fn_801F1CE8(int);
    unsigned char *bytes = (unsigned char *)fn_801F1CE8(id);
    unsigned char tmp;
    tmp = bytes[0]; bytes[0] = bytes[3]; bytes[3] = tmp;
    tmp = bytes[1]; bytes[1] = bytes[2]; bytes[2] = tmp;
    tmp = bytes[4]; bytes[4] = bytes[7]; bytes[7] = tmp;
    tmp = bytes[5]; bytes[5] = bytes[6]; bytes[6] = tmp;
    tmp = bytes[8]; bytes[8] = bytes[11]; bytes[11] = tmp;
    tmp = bytes[9]; bytes[9] = bytes[10]; bytes[10] = tmp;
    tmp = bytes[12]; bytes[12] = bytes[15]; bytes[15] = tmp;
    tmp = bytes[13]; bytes[13] = bytes[14]; bytes[14] = tmp;
}

#pragma small_data off
__declspec(section ".data") extern int lbl_8033A8F8;
/* Scalar-deleting destructor for PSSystem::SeqHeap: restores the vtable, tears down
 * associated state, and optionally frees the object storage. */
void *__dt__Q28PSSystem7SeqHeapFv_801F3460(void *this_, int shouldDelete) {
    if (this_ != 0) {
        *(void **)this_ = &lbl_8033A8F8;
        fn_802C9994(-1, &lbl_8033A8F8);
        if (shouldDelete > 0) fn_80128668(this_);
    }
    return this_;
}
#pragma small_data on
/* Copies a transform record's id and x/y/z values from the indexed source data. */
void fn_801F34C4(void *dest, int sourceIndex) {
    extern int *fn_801F1CE8(int);
    int *source = fn_801F1CE8(sourceIndex);
    *(int *)((char *)dest + 0x10) = source[0];
    *(float *)((char *)dest + 4) = ((float *)source)[1];
    *(float *)((char *)dest + 8) = ((float *)source)[2];
    *(float *)((char *)dest + 0xC) = ((float *)source)[3];
}

#pragma push
#pragma processor 750
void fn_801F3514(void *arg0) {
    extern float lbl_80562F74, lbl_80562F78, lbl_80562F7C, lbl_80562F80, lbl_80562F84, lbl_80562F88, lbl_80562F8C, lbl_80562F64, lbl_8055EC04, lbl_80562F48;
    extern char lbl_8033ABC4[], lbl_8033ABF0[], lbl_8033AC18[];
    extern int *fn_801E1F44(void);
    extern int fn_802C9994();
    extern int fn_802923C4();
    extern int fn_802C9A1C();
    extern void fn_802E30C8(const char *, ...);
    extern double fn_8002F234(float);
    extern double atan(double);
    extern double sin(double);
    extern double cos(double);
    float v[3];
    float f31, f30, t, sq;
    char *p = (char *)arg0;

    if (*(int *)(p + 0x10) == 0) {
        float c, b, a;
        a = lbl_80562F40; b = lbl_80562F74; c = lbl_80562F78;
        *(int *)(p + 0x10) = 0xFDFEE7;
        *(float *)(p + 4) = a;
        *(float *)(p + 8) = b;
        *(float *)(p + 0xC) = c;
        fn_802E30C8(lbl_8033ABC4);
    }
    if (*fn_801E1F44() == 1) {
        float c, b, a;
        a = lbl_80562F40; b = lbl_80562F7C; c = lbl_80562F80;
        *(int *)(p + 0x10) = 0x75889B;
        *(float *)(p + 4) = a;
        *(float *)(p + 8) = b;
        *(float *)(p + 0xC) = c;
    }
    fn_802C9994(*(int *)(p + 0x10));
    fn_802923C4(*(int *)(p + 0x10));
    v[0] = *(float *)(p + 4) * lbl_80562F48;
    v[1] = *(float *)(p + 8) * lbl_80562F48;
    v[2] = *(float *)(p + 0xC) * lbl_80562F48;
    PSVECNormalize(v, v);
    sq = v[2] * v[2];
    f30 = (float)fn_8002F234(v[0] * v[0] + sq);
    f31 = -v[1];
    if ((float)atan(f31 / f30) < lbl_8055EC04) {
        fn_802E30C8(lbl_8033AC18, (lbl_80562F84 * (float)atan(f31 / f30)) / lbl_80562F88, (lbl_80562F84 * lbl_8055EC04) / lbl_80562F88);
        v[0] = v[0] * ((float)cos(lbl_8055EC04) / f30);
        v[1] = -(float)sin(lbl_8055EC04);
        v[2] = v[2] * ((float)cos(lbl_8055EC04) / f30);
    }
    t = lbl_80562F44 + -v[1];
    fn_802E30C8(lbl_8033ABF0, lbl_80562F64 + (lbl_80562F8C * -v[0]) / t, lbl_80562F64 + (lbl_80562F8C * -v[2]) / t);
    fn_802C9A1C(v);
}
#pragma pop
/* Advance the sun/flare position by the velocity vector stored at +4 of the object (tail-call into fn_8029231C). */
void fn_801F371C(int object) {
    fn_8029231C(object + 4);
}

int fn_801F3724(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree
     * when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

extern int *fn_801F1CE8(int);
extern int fn_80128668(void);
extern int *fn_801E1F44(void);
extern int fn_802C9950(int);
void fn_801F3764(void *self, int source) {
    /* Load method for a 4-byte TMH render parameter: copy the raw value word
     * from the source parameter block (offset 0x2C, via fn_801F1CE8) into this
     * parameter's value field and mark it loaded, so a later accessor uses the
     * value instead of a default. */
    struct TmhValueParam {
        void *vtable;         /* 0x00 */
        unsigned char loaded; /* 0x04: the value below is set */
        int value;            /* 0x08 */
    } *param = (struct TmhValueParam *)self;

    param->value = *fn_801F1CE8(source);
    param->loaded = 1;
}

/* Set the draw/text color: a dim gray when the current state is 1, otherwise a lighter gray. */
void fn_801F37A4(void) {
    if (*fn_801E1F44() == 1) {
        fn_802C9950(0xFF646464);
        return;
    }
    fn_802C9950(0xFF909090);
}

#pragma scheduling invalid_target
void fn_801F37EC(void) {
#define kAmbientColorPanic lbl_8033ABA0 /* "AmbientColorTMH: shouldn't draw!" */
    /* Fatal abort: an AmbientColorTMH was drawn when it shouldn't have been. */
    fn_802E317C(kAmbientColorPanic);
#undef kAmbientColorPanic
}
int fn_801F37FC(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_801F383C(void *dst, int src) {
    /* Copy the 4-byte value at offset 0x2C of src into dst+8 and mark dst as initialized. */
    *(int *)((char *)dst + 8) = *fn_801F1CE8(src);
    *(char *)((char *)dst + 4) = 1;
}

/* One 4-byte word of a render parameter block's raw 16-byte value field (the
   field at +0x2C that fn_801F1CE8 returns), addressed byte by byte so its byte
   order can be flipped. */
struct ValueWordBytes { unsigned char b[4]; };

void fn_801F387C(void *unused, int arg1) {
    /* ShadowColorTMH's byte-swap method: reverse the byte order of each of the
       four words of the source parameter block's raw value field at +0x2C. */
    extern int *fn_801F1CE8(int);
    struct ValueWordBytes *words = (struct ValueWordBytes *)fn_801F1CE8(arg1);
    unsigned char tmp;
    tmp = words[0].b[0]; words[0].b[0] = words[0].b[3]; words[0].b[3] = tmp;
    tmp = words[0].b[1]; words[0].b[1] = words[0].b[2]; words[0].b[2] = tmp;
    tmp = words[1].b[0]; words[1].b[0] = words[1].b[3]; words[1].b[3] = tmp;
    tmp = words[1].b[1]; words[1].b[1] = words[1].b[2]; words[1].b[2] = tmp;
    tmp = words[2].b[0]; words[2].b[0] = words[2].b[3]; words[2].b[3] = tmp;
    tmp = words[2].b[1]; words[2].b[1] = words[2].b[2]; words[2].b[2] = tmp;
    tmp = words[3].b[0]; words[3].b[0] = words[3].b[3]; words[3].b[3] = tmp;
    tmp = words[3].b[1]; words[3].b[1] = words[3].b[2]; words[3].b[2] = tmp;
}

void fn_801F3920(void *params) {
    extern int fn_80297990(int);
    /* Install the shadow-volume handle from the parameter block (+8) when its
     * flag byte (+4) is set, otherwise reset it to the invalid-handle sentinel. */
    if (*(unsigned char *)((char *)params + 4) != 0) {
        fn_80297990(*(int *)((char *)params + 8));
    } else {
        fn_80297990(0x80000000);
    }
}

#pragma scheduling invalid_target
void fn_801F393C(void) {
    /* Panics ("ShadowColorTMH: shouldn't draw!") if the shadow-color TMH is drawn when it shouldn't be. */
    #define sShadowColorPanic lbl_8033AB80
    fn_802E317C(sShadowColorPanic);
    #undef sShadowColorPanic
}

int fn_801F394C(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_801F398C(void *unused, int arg1) {
    /* Byte-swap four 4-byte words at offset 0x2C of the given object. */
    extern int *fn_801F1CE8(int);
    unsigned char *data = (unsigned char *)fn_801F1CE8(arg1);
    unsigned char tmp;
    tmp = data[0]; data[0] = data[3]; data[3] = tmp;
    tmp = data[1]; data[1] = data[2]; data[2] = tmp;
    tmp = data[4]; data[4] = data[7]; data[7] = tmp;
    tmp = data[5]; data[5] = data[6]; data[6] = tmp;
    tmp = data[8]; data[8] = data[11]; data[11] = tmp;
    tmp = data[9]; data[9] = data[10]; data[10] = tmp;
    tmp = data[12]; data[12] = data[15]; data[15] = tmp;
    tmp = data[13]; data[13] = data[14]; data[14] = tmp;
}

void fn_801F3A30(void *arg0, int arg1) {
    extern int *fn_801F1CE8(int);
    extern float lbl_80562F90;
    unsigned char byte;
    float value;
    byte = (unsigned char)*fn_801F1CE8(arg1);
    value = (float)byte;
    *(unsigned char *)((char *)arg0 + 4) = 1;
    *(float *)((char *)arg0 + 8) = value / lbl_80562F90;
}

float fn_801F3A94(void *params) {
    extern float fn_802923EC(float);
    /* Apply the value from params (+8) when its override flag (+4) is set, otherwise the default 1.0. */
    if (*(unsigned char *)((char *)params + 4) != 0) {
        return fn_802923EC(*(float *)((char *)params + 8));
    }
    return fn_802923EC(lbl_80562F44);
}

#pragma scheduling invalid_target
extern const char lbl_8033AB5C[];
int fn_801F3AB0(void) {
    /* Log the "SunIntensityTMH: shouldn't draw!" warning. */
    return fn_802E317C(lbl_8033AB5C);
}

int fn_801F3AC0(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_801F3B00(void *self, int source) {
    /* FogColorTMH's load method: take the colour word out of the source
     * parameter block's raw 16-byte value field (the one at +0x2C that
     * fn_801F1CE8 points at), keep it as this parameter's colour and mark the
     * value as loaded, so fn_801F3BE4 will hand it to the fog colour setter
     * instead of the default. */
    struct FogColorTmh {
        void *vtable;         /* 0x00 */
        unsigned char loaded; /* 0x04: the colour below is set */
        int color;            /* 0x08 */
    } *fog = (struct FogColorTmh *)self;

    fog->color = *fn_801F1CE8(source);
    fog->loaded = 1;
}

// Byte-swap four consecutive 32-bit words in place (reverse each word's bytes)
// at the buffer returned by fn_801F1CE8 for the given argument.
void fn_801F3B40(void *unused, int arg1) {
    extern int *fn_801F1CE8(int);
    unsigned char *bytes = (unsigned char *)fn_801F1CE8(arg1);
    unsigned char temp;
    temp = bytes[0]; bytes[0] = bytes[3]; bytes[3] = temp;
    temp = bytes[1]; bytes[1] = bytes[2]; bytes[2] = temp;
    temp = bytes[4]; bytes[4] = bytes[7]; bytes[7] = temp;
    temp = bytes[5]; bytes[5] = bytes[6]; bytes[6] = temp;
    temp = bytes[8]; bytes[8] = bytes[11]; bytes[11] = temp;
    temp = bytes[9]; bytes[9] = bytes[10]; bytes[10] = temp;
    temp = bytes[12]; bytes[12] = bytes[15]; bytes[15] = temp;
    temp = bytes[13]; bytes[13] = bytes[14]; bytes[14] = temp;
}

/* FogColorTmh's apply method: hand the stored colour word (+8) to the fog
 * colour setter when one was loaded (flag at +4), otherwise use the default
 * fog colour 0x00C9C9EB. */
void fn_801F3BE4(void *fog) {
    extern void fn_802C990C(int);
    if (*(unsigned char *)((char *)fog + 4) != 0) {
        fn_802C990C(*(int *)((char *)fog + 8));
    } else {
        fn_802C990C(0x00C9C9EB);
    }
}

#pragma scheduling invalid_target
void fn_801F3C04(void) {
    #define sFogColorNoDrawMsg lbl_8033AB3C /* "FogColorTMH: shouldn't draw!" */
    /* Report a fatal panic: a FogColorTMH parameter must never be drawn. */
    fn_802E317C(sFogColorNoDrawMsg);
    #undef sFogColorNoDrawMsg
}

void fn_801F3C14(int unused, unsigned char *data) {
    /* Byte-swap three 12-byte blocks at offset 0x18 and reverse the 4-byte value at offset 0x14. */
    unsigned char *block = data + 0x18;
    int blockIndex;
    for (blockIndex = 0; blockIndex < 3; blockIndex++, block += 0xC) {
        unsigned char temp;
        temp = block[0]; block[0] = block[3]; block[3] = temp;
        temp = block[1]; block[1] = block[2]; block[2] = temp;
        temp = block[4]; block[4] = block[7]; block[7] = temp;
        temp = block[5]; block[5] = block[6]; block[6] = temp;
        temp = block[8]; block[8] = block[0xB]; block[0xB] = temp;
        temp = block[9]; block[9] = block[0xA]; block[0xA] = temp;
    }
    {
        unsigned char firstByte = data[0x14];
        unsigned char secondByte = data[0x15];
        data[0x14] = data[0x17]; data[0x17] = firstByte;
        data[0x15] = data[0x16]; data[0x16] = secondByte;
    }
}

#pragma push
#pragma processor 750
void fn_801F3CAC(void *unused, void *list) {
    extern float fn_801E7E18(void);
    extern void fn_80144DC8(void *);
    extern void fn_80015EB0(void *, float);
    extern void fn_80015B20(void *, void *, void *);
    extern void fn_802C744C(int, void *);
    struct Buffers {
        char sp8[0x24];
        float sp2c[3];
    } buffers;
    void *node;
    float scale;

    /* For each node in the list, build a transform buffer from its scale/offset
     * data and submit it for the node's id. */
    node = list;
    while (node != 0) {
        scale = *(float *)((char *)node + 0x30) * fn_801E7E18();
        fn_80144DC8(buffers.sp8);
        fn_80015EB0(buffers.sp8, scale);
        fn_80015B20(buffers.sp8, buffers.sp8, (char *)node + 0x34);
        fn_80144DAC(buffers.sp2c, (float *)((char *)node + 0x20));
        fn_802C744C(*(int *)((char *)node + 4), buffers.sp8);
        node = *(void **)((char *)node + 0xC);
    }
}
#pragma pop
extern int lbl_8033AA90, lbl_8033AA18, lbl_8033AA24;
extern void fn_801F3E60(void);
#pragma pop
extern int lbl_8055B158;
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int, int);
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033AA90, lbl_8033AA18, lbl_8033AA24;
#pragma processor 750
#pragma scheduling invalid_target
void fn_801F3D34(void *arg0, int arg1, void *arg2) {
    float temp_f31;
    void *temp_r31;
    int temp_r30;
    void *temp_r3;
    float temp_f2;
    float temp_f1;
    float temp_f0;
    if (*(void **)((char *)arg0 + 4) == 0) {
        temp_r31 = fn_801284F8(0xC, &lbl_8055B158);
        if (temp_r31 != 0) {
            *(void **)temp_r31 = &lbl_8033AA90;
            temp_r3 = fn_8012850C(0x190, &lbl_8033AA18);
            *(void **)((char *)temp_r31 + 4) =
                fn_8002F37C(temp_r3, fn_801F3E60, 0, 0x18, 0x10);
            *(int *)((char *)temp_r31 + 8) = 0;
        }
        *(void **)((char *)arg0 + 4) = temp_r31;
        fn_802CD320(arg1, temp_r31);
    }
    temp_r31 = *(void **)((char *)arg0 + 4);
    temp_f31 = *(float *)((char *)arg2 + 0x30);
    temp_r30 = *(int *)((char *)arg2 + 0x2C);
    if (*(int *)((char *)temp_r31 + 8) >= 0x10) {
        fn_802E317C((const void *)&lbl_8033AA24);
    }
    temp_r3 = *(void **)((char *)temp_r31 + 4);
    temp_r3 = (char *)temp_r3 + *(int *)((char *)temp_r31 + 8) * 0x18;
    temp_f2 = *(float *)((char *)arg2 + 0x20);
    *(int *)temp_r3 = temp_r30;
    temp_f1 = *(float *)((char *)arg2 + 0x24);
    *(float *)((char *)temp_r3 + 4) = temp_f2;
    temp_f0 = *(float *)((char *)arg2 + 0x28);
    *(float *)((char *)temp_r3 + 8) = temp_f1;
    *(float *)((char *)temp_r3 + 0xC) = temp_f0;
    *(void **)((char *)temp_r3 + 0x10) = (char *)arg2 + 0x34;
    *(float *)((char *)temp_r3 + 0x14) = temp_f31;
    (*(int *)((char *)temp_r31 + 8))++;
}
#pragma scheduling on
#pragma processor default
/* Empty stub. */
void fn_801F3E60(void) {

}

/* No-op stub. */
void fn_801F3E64(void) {

}

#pragma push
#pragma small_data off
#pragma pop
void fn_801F3E68(int unused, unsigned char *buffer) {
    unsigned char b0 = buffer[0x2C];
    unsigned char b1 = buffer[0x2D];
    /* Byte-swap the 4-byte field at +0x2C in place, then turn the resulting
     * index into a single-bit mask (1 << (index - 1)). */
    buffer[0x2C] = buffer[0x2F];
    buffer[0x2F] = b0;
    buffer[0x2D] = buffer[0x2E];
    buffer[0x2E] = b1;
    *(unsigned int *)(buffer + 0x2C) = 1 << (*(unsigned int *)(buffer + 0x2C) - 1);
}
/* No-op stub. */
void fn_801F3EA0(void) {

}

#pragma push
#pragma small_data off
#pragma pop
void fn_801F3EA4(int arg0, int arg1, void *listA, int entryA, void *listB, int entryB) {
    /* Turn on the 0x40 flag of two material-list (mlist) entries.
     * Each list keeps an array of 32-byte entries at +0x24; fn_802CD33C(list, index, 0)
     * sets bit 0x40 of the entry's u16 flags at +0x12.  arg0/arg1 arrive in r3/r4
     * and are ignored. */
    fn_802CD33C(listA, entryA, 0);
    fn_802CD33C(listB, entryB, 0);
}
extern int fn_802CD33C(int, int, int);
extern int lbl_8033A7A0_arr[];
void *fn_801F3EF8(void *arg0, int arg1) {
    extern int lbl_8033A7A0[];
#define vtable_801F3EF8 lbl_8033A7A0
#define DeleteObject fn_80128668
    /* Construct/destroy helper: set vtable, optionally delete the object, and return it. */
    if (arg0 != 0) {
        *(void * volatile *)arg0 = (void *)&vtable_801F3EF8[0];
        if (arg1 > 0) {
            DeleteObject();
        }
    }
    return arg0;
#undef vtable_801F3EF8
#undef DeleteObject
}
/* RealName: SwapTwoDwordByteOrder_801F3F44 */
void fn_801F3F44(int unused, volatile unsigned char *buffer) {
    /* Reverse the byte order of two 4-byte fields at offsets 0x2C and 0x30. */
    unsigned char temp;
    temp = buffer[0x2C]; buffer[0x2C] = buffer[0x2F]; buffer[0x2F] = temp;
    temp = buffer[0x2D]; buffer[0x2D] = buffer[0x2E]; buffer[0x2E] = temp;
    temp = buffer[0x30]; buffer[0x30] = buffer[0x33]; buffer[0x33] = temp;
    temp = buffer[0x31]; buffer[0x31] = buffer[0x32]; buffer[0x32] = temp;
}
/* Empty stub. */
void fn_801F3F88(void) {

}

extern float fn_802C88D4(void *);
extern int fn_802C9900(float);
extern int fn_802C9904(void);
#pragma push
#pragma processor 750
void fn_801F3F8C(void *table, void *node) {
    /* For each listed model instance, compute a metric; when it passes the entry's
       threshold, draw the instance with a clamped alpha, then reset the draw state. */
    float minAlpha = 0.0f;
    float maxAlpha = 1.0f;
    while (node != 0) {
        int entryIndex = *(int *)((char *)node + 0x14);
        if (entryIndex >= 0 && entryIndex < 0x30) {
            char *entry = *(char **)((char *)table + 4) + entryIndex * 0x18;
            float metric = fn_802C88D4(entry);
            float threshold = *(float *)(entry + 0x14);
            if (metric > threshold) {
                float alpha = *(float *)(entry + 0x10) * (metric - threshold);
                if (maxAlpha < alpha) alpha = maxAlpha;
                if (alpha > minAlpha) alpha = alpha; else alpha = minAlpha;
                fn_802C9900(alpha);
                DrawModelInstance(*(int *)(entry + 0xC));
                fn_802C9904();
            }
        }
        node = *(void **)((char *)node + 0xC);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801F405C(void *arg0, void *arg1, void *arg2, int arg3) {
    extern void *fn_801284F8(int, void *);
    extern int fn_802E317C(const void *, ...);
    extern void fn_802C77F0(int, float *);
    extern const char lbl_8033AB0C[], lbl_8033AB18[];
    extern char lbl_8033AA78[];
    extern float lbl_80562F44, lbl_80562F64;
    struct Pool { char pad[0x544]; int count; };
    struct Owner { char pad[8]; struct Pool *pool; };
    struct Config { int unused; int kind; char pad0[0x18]; float x, y, z; float start, end; };
    struct Record { int unused; float x, y, z; int kind; float rate, end; int id; };
    struct Owner *owner = (struct Owner *)arg0;
    struct Config *config = (struct Config *)arg2;
    struct Record *entry;
    struct Pool *pool;
    float v[6];
    int count, kind;
    float hi, start, end, baseY, baseX, factor, lo;
    if (owner->pool == 0) {
        void *allocated = fn_801284F8(0x548, (void *)lbl_8033AB0C);
        if (allocated != 0) {
            *(char **)allocated = lbl_8033AA78;
            *(int *)((char *)allocated + 0x544) = 0;
        }
        owner->pool = (struct Pool *)allocated;
        fn_802CD320((int)arg1, allocated);
    }
    pool = owner->pool;
    count = pool->count;
    if (count >= 0x30) fn_802E317C(lbl_8033AB18);
    count = pool->count;
    entry = (struct Record *)((char *)pool + count * 0x1C);
    fn_802C77F0(config->kind, (float *)v);
    hi = v[1];
    lo = v[0];
    hi = hi - lo;
    factor = lbl_80562F64;
    start = hi * factor;
    baseX = config->x;
    lo = lo + start;
    start = config->start;
    end = config->end;
    start = start - end;
    hi = lbl_80562F44;
    baseY = config->y;
    hi = hi / start;
    kind = config->kind;
    baseX = baseX + lo;
    entry->x = baseX;
    start = v[3];
    baseX = v[2];
    start = start - baseX;
    start = start * factor;
    start = baseX + start;
    start = baseY + start;
    entry->y = start;
    start = v[5];
    baseY = v[4];
    start = start - baseY;
    start = start * factor;
    start = baseY + start;
    start = config->z + start;
    entry->z = start;
    entry->kind = kind;
    entry->rate = hi;
    entry->end = end;
    ((volatile int *)((char *)pool + pool->count * 0x1C))[7] = arg3;
    pool->count = pool->count + 1;
}
/* Byte-reverses five contiguous 4-byte fields at offsets 0x2C-0x3F in place. */
void fn_801F41CC(int unused, volatile unsigned char *bytes) {
    unsigned char tmp;
    tmp = bytes[0x2c]; bytes[0x2c] = bytes[0x2f]; bytes[0x2f] = tmp;
    tmp = bytes[0x2d]; bytes[0x2d] = bytes[0x2e]; bytes[0x2e] = tmp;
    tmp = bytes[0x30]; bytes[0x30] = bytes[0x33]; bytes[0x33] = tmp;
    tmp = bytes[0x31]; bytes[0x31] = bytes[0x32]; bytes[0x32] = tmp;
    tmp = bytes[0x34]; bytes[0x34] = bytes[0x37]; bytes[0x37] = tmp;
    tmp = bytes[0x35]; bytes[0x35] = bytes[0x36]; bytes[0x36] = tmp;
    tmp = bytes[0x38]; bytes[0x38] = bytes[0x3b]; bytes[0x3b] = tmp;
    tmp = bytes[0x39]; bytes[0x39] = bytes[0x3a]; bytes[0x3a] = tmp;
    tmp = bytes[0x3c]; bytes[0x3c] = bytes[0x3f]; bytes[0x3f] = tmp;
    tmp = bytes[0x3d]; bytes[0x3d] = bytes[0x3e]; bytes[0x3e] = tmp;
}

#pragma scheduling invalid_target
void fn_801F4270(void) {
    /* Abort with a panic: local flare sources are not supported by trackmod. */
    #define sLocalFlareUnsupported lbl_8033AAE0
    fn_802E317C(sLocalFlareUnsupported);
    #undef sLocalFlareUnsupported
}

/* FlareSource::Draw -- slot +0x20 of the FlareSource vtable (lbl_8033A770), the
 * per-frame draw method the other scene objects implement (Sky's is
 * fn_801F3288, PointFacing's fn_801F2DD4).  Flares draw nothing at all:
 * trackmod has no support for local flare sources, which the class's
 * +0x10 method (fn_801F4270) reports by panicking. */
void fn_801F4280(void) {

}

void fn_801F4284(void *unused, void *arg1) {
    extern unsigned char lbl_8033AAB8[]; /* "Water objects not currently supported" */
    volatile unsigned char *p;
    int i;
    /* Report unsupported water objects, then byte-swap three 12-byte blocks at offset 0x2C. */
    fn_802E317C(lbl_8033AAB8);
    p = (volatile unsigned char *)arg1 + 0x2C;
    for (i = 0; i < 3; i++, p += 12) {
        unsigned char tmp;
        tmp = p[0]; p[0] = p[3]; p[3] = tmp;
        tmp = p[1]; p[1] = p[2]; p[2] = tmp;
        tmp = p[4]; p[4] = p[7]; p[7] = tmp;
        tmp = p[5]; p[5] = p[6]; p[6] = tmp;
        tmp = p[8]; p[8] = p[11]; p[11] = tmp;
        tmp = p[9]; p[9] = p[10]; p[10] = tmp;
    }
}

/* Empty stub. */
void fn_801F4330(void) {

}

extern int DrawModelInstance(int);
extern int fn_802CD320(int, void *);
extern unsigned char lbl_8033AAB8[];
extern unsigned char lbl_8033AA48[];
extern unsigned char lbl_8055B140[];
int fn_801F4334(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* No-op stub. */
void fn_801F4374(void) {

}

extern void *fn_802AE414(void *);
extern int lbl_8033AAA8, lbl_8033AA60, lbl_8055B150, lbl_8055B148;
#pragma small_data off
extern int lbl_8033AAA8, lbl_8033AA60;
#pragma small_data on
extern int lbl_8055B150, lbl_8055B148;
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033AAA8, lbl_8033AA60;
#pragma push
#pragma small_data off
#pragma pop
#pragma cplusplus on
extern "C" void fn_801F4378(void *arg0, int arg1, void *arg2, int arg3) {
    struct Dummy {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual float get(int) = 0;
    };
    int count;
    int value;
    void *path;
    void *obj;
    void *newobj;
    void *item;
    float f;

    path = (char *)arg2 + 0x2C;
    obj = *(void **)((char *)arg0 + 4);
    if (obj == 0) {
        newobj = fn_801284F8(0x108, (void *)&lbl_8033AAA8);
        if (newobj != 0) {
            *(void **)newobj = (void *)&lbl_8033AA60;
            *(int *)((char *)newobj + 0x104) = 0;
            *(void **)((char *)arg0 + 4) = newobj;
            fn_802CD320(arg1, newobj);
        }
    }
    obj = *(void **)((char *)arg0 + 4);
    value = *(int *)((char *)arg2 + 4);
    count = *(int *)((char *)obj + 0x104);
    f = lbl_80562F40;
    arg2 = (char *)obj + (count << 4);
    *(int *)((char *)arg2 + 4) = value;
    *(int *)((char *)arg2 + 8) = arg3;
    *(float *)((char *)arg2 + 0xC) = f;
    *(float *)((char *)arg2 + 0x10) = f;
    item = fn_802AE414(path);
    if (item != 0) {
        *(float *)((char *)arg2 + 0xC) = ((Dummy *)item)->get((int)&lbl_8055B150);
        *(float *)((char *)arg2 + 0x10) = ((Dummy *)item)->get((int)&lbl_8055B148);
    }
    count = *(int *)((char *)obj + 0x104);
    *(int *)((char *)obj + 0x104) = count + 1;
}
#pragma cplusplus reset
/* No-op stub. */
void fn_801F447C(void) {

}

/* For each node in a linked list starting at head: if the object at node+0x2C passes
 * fn_801F1CF0 (camera-facing / dot-product test), call DrawModelInstance on the node's
 * value at +4. Node layout used: +4 value, +0xC next, +0x2C test object. */
void fn_801F4480(int unused, void *head)
{
    int value;
    void *node;

    node = head;
    goto check;
loop:
    value = *(int *)((char *)node + 4);
    if (fn_801F1CF0((int)((char *)node + 0x2C))) {
        DrawModelInstance(value);
    }
    node = *(void **)((char *)node + 0xC);
check:
    if (node != 0) {
        goto loop;
    }
}

#pragma scheduling invalid_target
__declspec(section ".sdata") extern unsigned char lbl_8055B140[];
/* Allocate and initialize a small 0xC-byte object (vtable lbl_8033AA48, fields +4 and +8) and register it via fn_802CD320 for the given target. */
void fn_801F44DC(void *unused, int target, int baseValue, int param) {
#define mlftoTag      lbl_8055B140
#define mlftoVTable   lbl_8033AA48
    int adjustedValue = baseValue + 0x2C;
    void *object = fn_801284F8(0xC, mlftoTag);
    if (object != 0) {
        *(void **)object = (void *)mlftoVTable;
        *(int *)((char *)object + 4) = adjustedValue;
        *(int *)((char *)object + 8) = param;
    }
    fn_802CD320(target, object);
#undef mlftoVTable
#undef mlftoTag
}
/* Empty stub. */
void fn_801F4550(void) {

}

int fn_801F4554(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_801F4594(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_801F45D4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma small_data off
void *fn_801F4614(void *object, int shouldDelete) {
    /* Destructor-like cleanup: restore the base vtable, free the owned buffer if present, and optionally delete the object. */
    extern int fn_80128670(int);
#define vtable lbl_8033AA90
#define FreeArray fn_80128670
#define DeleteObject fn_80128668
    int ownedBuffer;
    if (object != 0) {
        ownedBuffer = *(int *)((char *)object + 4);
        *(void **)object = &vtable;
        if (ownedBuffer != 0) FreeArray(ownedBuffer - 0x10);
        if (shouldDelete > 0) ((int (*)(void *))DeleteObject)(object);
    }
    return object;
#undef vtable
#undef FreeArray
#undef DeleteObject
}

extern double sin(double);
extern float fn_80144514(float, float, float, float, float, float);
/* In-place 3x3 matrix product dst = right * left; when dst aliases either
 * input the nine dot products are buffered first so nothing is overwritten. */
static inline void CombineMtx_801F4684(float *dst, const float *left, const float *right) {
    float v0, v1, v2, v3, v4, v5, v6, v7, v8;
    if (dst == left || dst == right) {
        v0 = fn_80144514(right[0], left[0], right[3], left[1], right[6], left[2]);
        v1 = fn_80144514(right[0], left[3], right[3], left[4], right[6], left[5]);
        v2 = fn_80144514(right[0], left[6], right[3], left[7], right[6], left[8]);
        v3 = fn_80144514(right[1], left[0], right[4], left[1], right[7], left[2]);
        v4 = fn_80144514(right[1], left[3], right[4], left[4], right[7], left[5]);
        v5 = fn_80144514(right[1], left[6], right[4], left[7], right[7], left[8]);
        v6 = fn_80144514(right[2], left[0], right[5], left[1], right[8], left[2]);
        v7 = fn_80144514(right[2], left[3], right[5], left[4], right[8], left[5]);
        v8 = fn_80144514(right[2], left[6], right[5], left[7], right[8], left[8]);
        dst[0] = v0; dst[3] = v1; dst[6] = v2;
        dst[1] = v3; dst[4] = v4; dst[7] = v5;
        dst[2] = v6; dst[5] = v7; dst[8] = v8;
    } else {
        dst[0] = fn_80144514(right[0], left[0], right[3], left[1], right[6], left[2]);
        dst[3] = fn_80144514(right[0], left[3], right[3], left[4], right[6], left[5]);
        dst[6] = fn_80144514(right[0], left[6], right[3], left[7], right[6], left[8]);
        dst[1] = fn_80144514(right[1], left[0], right[4], left[1], right[7], left[2]);
        dst[4] = fn_80144514(right[1], left[3], right[4], left[4], right[7], left[5]);
        dst[7] = fn_80144514(right[1], left[6], right[4], left[7], right[7], left[8]);
        dst[2] = fn_80144514(right[2], left[0], right[5], left[1], right[8], left[2]);
        dst[5] = fn_80144514(right[2], left[3], right[5], left[4], right[8], left[5]);
        dst[8] = fn_80144514(right[2], left[6], right[5], left[7], right[8], left[8]);
    }
}
extern void fn_802CDAB4(int, int, float *);
/* Virtual method (slot +0xC of the vtable lbl_8033AA90 this class is constructed
 * with; its deleting destructor is fn_801F4614).  For every entry of the spin
 * list -- {vtable, entries, count} with 0x18-byte entries -- build a rotation
 * about Y by spinRate * game-time, combine it with the entry's own 3x3 matrix,
 * append the entry's position and submit the 3x4 transform as that object's
 * draw transform (fn_802CDAB4 -> fn_802D0514). */
#pragma scheduling invalid_target
void fn_801F4684(register void *spinList, register int drawContext) {
    struct SpinEntry {
        int objectIndex;      /* object the finished transform is submitted for */
        float x, y, z;        /* position */
        float *baseMtx;       /* the entry's own 3x3 matrix */
        float spinRate;       /* spin speed about Y, radians per second */
    };
    struct SpinList {
        void *vtable;
        struct SpinEntry *entries;
        int count;
    };
    register float *baseMtx;
    register int byteOffset;
    register int index = 0;
    if (((struct SpinList *)spinList)->count > 0) {
        register float one;
        register float zero;
        zero = lbl_80562F40;
        one = lbl_80562F44;
        byteOffset = 0;
        while (index < ((struct SpinList *)spinList)->count) {
            register struct SpinEntry *entry;
            register float c;
            register float angle;
            register float s;
            float transform[12];
            entry = (struct SpinEntry *)((char *)((struct SpinList *)spinList)->entries + byteOffset);
            angle = entry->spinRate * fn_801E7E18();
            c = (float)cos(angle);
            s = (float)sin(angle);
            transform[0] = c; transform[1] = zero; transform[2] = -s;
            transform[3] = zero; transform[4] = one; transform[5] = zero;
            transform[6] = s; transform[7] = zero; transform[8] = c;
            baseMtx = entry->baseMtx;
            CombineMtx_801F4684(transform, transform, baseMtx);
            transform[9] = entry->x;
            transform[10] = entry->y;
            transform[11] = entry->z;
            fn_802CDAB4(drawContext, entry->objectIndex, transform);
            byteOffset += sizeof(struct SpinEntry);
            index += 1;
        }
    }
}
#pragma scheduling on
/* Empty stub. */
void fn_801F49F4(void) {

}

void fn_801F49F8(void *table, int drawContext) {
    /* Collect records whose id passes the draw-context flag test, then for each selected item draw its model with an alpha clamped to [0,1] when its metric exceeds the threshold. */
    void *selectedItems[0x30];
    void *item;
    void **cursor;
    char *record;
    char *itemData;
    int selectedIndex;
    int selectedCount;
    int recordIndex;
    float minAlpha;
    float maxAlpha;
    float value;
    record = (char *)table;
    itemData = (char *)table + 4;
    selectedCount = 0;
    recordIndex = 0;
    while (recordIndex < *(int *)((char *)table + 0x544)) {
        if (fn_802CDB20(drawContext, *(int *)((char *)record + 0x1C)) != 0) {
            selectedItems[selectedCount++] = itemData;
        }
        record += 0x1C;
        itemData += 0x1C;
        recordIndex++;
    }
    maxAlpha = lbl_80562F44;
    cursor = selectedItems;
    minAlpha = lbl_80562F40;
    selectedIndex = 0;
    while (selectedIndex < selectedCount) {
        item = *cursor;
        value = fn_802C88D4(item);
        if (value > *(float *)((char *)item + 0x14)) {
            value = *(float *)((char *)item + 0x10) * (value - *(float *)((char *)item + 0x14));
            value = (maxAlpha < value) ? maxAlpha : value;
            value = (value > minAlpha) ? value : minAlpha;
            fn_802C9900(value);
            DrawModelInstance(*(int *)((char *)item + 0xC));
            fn_802C9904();
        }
        cursor++;
        selectedIndex++;
    }
}

/* Stub: always returns the fixed value 4 (count/version for its interface). */
int fn_801F4B04(void) { return 4; }

/* Stub: always returns the fixed value 3 (count/version for its interface). */
int fn_801F4B0C(void) { return 3; }

/* Empty stub. */
void fn_801F4B14(void) {

}

#pragma push
#pragma paired_single off
#pragma paired off
extern double fn_8002EFB4(float, double);
extern int fn_802C7A3C(float, float, float);
extern double lbl_80562FA0;
extern float lbl_80562FA8;
void fn_801F4B18(void *collection, int arg1) {
    // For each active entry in the collection, convert its pair of scaled values
    // into an index/result and apply a 3x4 value matrix via fn_802C70AC.
    struct LocalValues {
        float scaledLow;
        float scaledHigh;
        float values[12];
    } local;
    float scale;
    float low;
    float high;
    float first;
    float value10;
    float value0C;
    int result;
    int *entry;
    int index;

    scale = fn_801E7E18();
    low = lbl_80562F40;
    high = lbl_80562F44;
    local.values[1] = low;
    local.values[0] = high;
    local.values[2] = low;
    local.values[3] = low;
    local.values[4] = high;
    local.values[5] = low;
    local.values[6] = low;
    local.values[7] = low;
    local.values[8] = high;
    local.values[9] = low;
    local.values[10] = low;
    local.values[11] = low;

    entry = (int *)collection;
    index = 0;
    while (index < *(int *)((char *)collection + 0x104)) {
        if (fn_802CDB20(arg1, entry[2]) != 0) {
            value10 = ((float *)entry)[4];
            value0C = ((float *)entry)[3];
            local.scaledHigh = value10 * scale;
            local.scaledLow = value0C * scale;
            first = (float)fn_8002EFB4(local.scaledHigh, lbl_80562FA0);
            result = fn_802C7A3C((float)fn_8002EFB4(local.scaledLow, lbl_80562FA0),
                                 first, lbl_80562FA8);
            fn_802C70AC(entry[1], local.values, result, -1);
        }
        entry += 4;
        index++;
    }
}
#pragma pop

extern int fn_801F1CF0(int);
extern int fn_802CDAFC(int, int);
extern int fn_802CDB20(int, int);
void fn_801F4C34(void *arg0, int arg1) {
    int *p = (int *)arg0;
    if (fn_802CDB20(arg1, p[2]) != 0 && fn_801F1CF0(p[1]) == 0) {
        fn_802CDAFC(arg1, p[2]);
    }
}

/* Stub: always returns -1 (the "none / invalid index" sentinel). */
int fn_801F4C98(void) { return -1; }

/* No-op stub. */
void fn_801F4CA0(void) {

}
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern int DrawModelInstance(int);
