// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern char lbl_80488228[];
extern void fn_802DAC54(void);
extern int fn_802C7A40(int, void *, int, int, void *, int);
extern void fn_802C70AC(int, void *, int, int);
extern u8 lbl_80339E18[];
extern void *memset(void *, int, unsigned int);

extern void fn_802C6CF8(s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_801EAB2C(void*);
#pragma cplusplus on
class Dummy_801EAB90 {
public:
    virtual void d0(int);
    virtual void d1(int);
    virtual void d2(int);
    virtual void d3(int);
    virtual void d4(int);
    virtual void d5(int);
    virtual void m6(int);
};
#pragma cplusplus off
extern void fn_801EABA8(void *, void *);
extern void fn_801EAB80(void*, s32);
extern u8 lbl_80339E3C[];

extern int fn_80128668();
extern void MRModel_SetInstanceTransform();
extern int fn_80176948(int, int, int);
extern float lbl_80562E60;
extern float lbl_80562E64;
extern short lbl_80562E28;
extern u8 lbl_80339E60[];
#define kBaseVTable lbl_80339E60
#define kField38Init lbl_80562E28 /* -2 */
void fn_801EAB2C(void * __restrict object) {
    /* Initialize a base sound object: install the base vtable, set the embedded
     * transform to the identity-like pattern [1,0,0,0]*3, and default +0x38 to -2. */
    float b;
    float a;
    void *vptr = &kBaseVTable;
    float *p = (float *)object;
    a = 1.0f;
    b = 0.0f;
    *(float volatile *)((char *)object + 4) = a;
    *(int *)object = (int)vptr;
    p[1] = a;
    p[2] = b;
    p[3] = b;
    p[4] = b;
    p[5] = a;
    p[6] = b;
    p[7] = b;
    p[8] = b;
    p[9] = a;
    p[10] = b;
    p[11] = b;
    p[12] = b;
    *(short *)((char *)object + 0x38) = kField38Init;
}

/* Trampoline during SeqHeap setup: forward (id, object+0x34, object) to fn_80176948. */
void fn_801EAB80(void *object, long id) {
    fn_80176948(id, (long)object + 0x34, (long)object);
}

#pragma cplusplus on
extern "C" void fn_801EAB90(void *obj, int value) {
    /* Forward value plus this object's +0x34 offset to its virtual slot 8. */
    int offset = *(int *)((char *)obj + 0x34);
    ((Dummy_801EAB90 *)obj)->m6(value + offset);
}
void fn_801EABA8(void *arg0, void *arg1) {
    s32 l, k, j, i, h, g, f, e, d, c, b, a;
    s16 m;

    e = *(volatile s32 *)((u8 *)arg1 + 0x10);
    d = *(volatile s32 *)((u8 *)arg1 + 0x0C);
    c = *(volatile s32 *)((u8 *)arg1 + 0x08);
    b = *(volatile s32 *)((u8 *)arg1 + 0x04);
    a = *(volatile s32 *)((u8 *)arg1 + 0x00);
    f = *(volatile s32 *)((u8 *)arg1 + 0x14);
    g = *(volatile s32 *)((u8 *)arg1 + 0x18);
    h = *(volatile s32 *)((u8 *)arg1 + 0x1C);
    i = *(volatile s32 *)((u8 *)arg1 + 0x20);
    j = *(volatile s32 *)((u8 *)arg1 + 0x24);
    k = *(volatile s32 *)((u8 *)arg1 + 0x28);
    l = *(volatile s32 *)((u8 *)arg1 + 0x2C);
    m = *(volatile s16 *)((u8 *)arg1 + 0x30);

    *(s32 *)((u8 *)arg0 + 0x04) = a;
    *(s32 *)((u8 *)arg0 + 0x08) = b;
    *(s32 *)((u8 *)arg0 + 0x0C) = c;
    *(s32 *)((u8 *)arg0 + 0x10) = d;
    *(s32 *)((u8 *)arg0 + 0x14) = e;
    *(s32 *)((u8 *)arg0 + 0x18) = f;
    *(s32 *)((u8 *)arg0 + 0x1C) = g;
    *(s32 *)((u8 *)arg0 + 0x20) = h;
    *(s32 *)((u8 *)arg0 + 0x24) = i;
    *(s32 *)((u8 *)arg0 + 0x28) = j;
    *(s32 *)((u8 *)arg0 + 0x2C) = k;
    *(s32 *)((u8 *)arg0 + 0x30) = l;
    *(s16 *)((u8 *)arg0 + 0x38) = m;
}
#pragma cplusplus off
s16 fn_801EAC3C(void* seqHeap) {
    /* Read the 16-bit field at offset 0x38 of a SeqHeap/sound object. */
    return *(s16*)((u8*)seqHeap + 0x38);
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Initialize a SeqHeap object: run base init, install the SeqHeap vtable, allocate its heap buffer, bind the associated sequence id, and return the object. */
void* fn_801EAC44(void* object, s32 sequenceId, s32 heapSize) {
#define SeqHeapVTable lbl_80339E3C
    fn_801EAB2C(object);
    *(u32*)object = (u32)SeqHeapVTable;
    *(s32*)((u8*)object + 0x3C) = fn_802C6FC0(heapSize, 0, 0);
    fn_801EAB80(object, sequenceId);
    return object;
#undef SeqHeapVTable
}
#pragma scheduling on
#pragma dont_inline off
s32 fn_801EACB8(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* PSSystem::SeqHeap::~SeqHeap (scalars deleting): restore vtable, free heap buffer, and optionally delete. */
void* __dt__Q28PSSystem7SeqHeapFv_801EACF8(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_80339E3C;
        fn_802C6CF8(*(s32*)((u8*)this_ + 0x3C));

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

/* Draw the model handle stored at +0x3C of the object using the transform matrix embedded at +4. */
void fn_801EAD5C(void* obj) {
    MRModel_SetInstanceTransform(*(s32*)((u8*)obj + 0x3C), (u8*)obj + 4);
}

#pragma dont_inline on
/* Constructs an object: runs base initialization, installs vtable lbl_80339E18,
 * initializes the embedded subobject at +0x34, clears the 0x40-byte payload at
 * +0x3C, and marks the handle at +0x70 as invalid (-1). */
void *fn_801EAD6C(void *arg0, s32 arg1) {
    fn_801EAB2C(arg0);
    *(void **)arg0 = lbl_80339E18;
    fn_801EAB80(arg0, arg1);
    memset((u8 *)arg0 + 0x3C, 0, 0x40);
    *(s32 *)((u8 *)arg0 + 0x70) = -1;
    return arg0;
}
/* Dispatch a model/command request: if enabled (+0x70 != -1), build an optional parameter pair from +0x78 and submit via fn_802C70AC. */
void fn_801EADD8(void *arg0) {
    s32 value;
    s32 sp[2];
    if (*(s32 *)((char *)arg0 + 0x70) == -1) {
        return;
    }
    if (*(s32 *)((char *)arg0 + 0x78) == 0) {
        value = 0;
    } else {
        fn_802DAC54();
        sp[0] = *(s32 *)((char *)arg0 + 0x78);
        sp[1] = -0x100;
        value = fn_802C7A40(1, lbl_80488228, 0x50, 1, sp, 2);
    }
    fn_802C70AC(*(s32 *)((char *)arg0 + 0x70), (char *)arg0 + 4, value, *(s32 *)((char *)arg0 + 0x74));
}

#pragma use_lmw_stmw off
/* Copies a model/command descriptor (src, 0x40 bytes) into both the base transform
   region (via fn_801EABA8) and the cached descriptor slot at dst + 0x3C..0x78. */
void fn_801EAE68(void *dst, void *src) {
    s32 w3C, w38, w34, half30, w2C, w28, w24, w20, w1C, w18, w14, w10, w0C, w08, w04, w00;
    fn_801EABA8(dst, src);
    w00 = *(volatile s32 *)((char *)src + 0x00);
    w04 = *(volatile s32 *)((char *)src + 0x04);
    w08 = *(volatile s32 *)((char *)src + 0x08);
    w0C = *(volatile s32 *)((char *)src + 0x0C);
    w10 = *(volatile s32 *)((char *)src + 0x10);
    w14 = *(volatile s32 *)((char *)src + 0x14);
    w18 = *(volatile s32 *)((char *)src + 0x18);
    w1C = *(volatile s32 *)((char *)src + 0x1C);
    w20 = *(volatile s32 *)((char *)src + 0x20);
    w24 = *(volatile s32 *)((char *)src + 0x24);
    w28 = *(volatile s32 *)((char *)src + 0x28);
    w2C = *(volatile s32 *)((char *)src + 0x2C);
    half30 = *(volatile s16 *)((char *)src + 0x30);
    w34 = *(volatile s32 *)((char *)src + 0x34);
    w38 = *(volatile s32 *)((char *)src + 0x38);
    w3C = *(volatile s32 *)((char *)src + 0x3C);
    *(s32 *)((char *)dst + 0x54) = w18;
    *(s32 *)((char *)dst + 0x3C) = w00;
    *(s32 *)((char *)dst + 0x40) = w04;
    *(s32 *)((char *)dst + 0x44) = w08;
    *(s32 *)((char *)dst + 0x48) = w0C;
    *(s32 *)((char *)dst + 0x4C) = w10;
    *(s32 *)((char *)dst + 0x50) = w14;
    *(s32 *)((char *)dst + 0x58) = w1C;
    *(s32 *)((char *)dst + 0x5C) = w20;
    *(s32 *)((char *)dst + 0x60) = w24;
    *(s32 *)((char *)dst + 0x64) = w28;
    *(s32 *)((char *)dst + 0x68) = w2C;
    *(s16 *)((char *)dst + 0x6C) = (s16)half30;
    *(s32 *)((char *)dst + 0x70) = w34;
    *(s32 *)((char *)dst + 0x74) = w38;
    *(s32 *)((char *)dst + 0x78) = w3C;
}
#pragma use_lmw_stmw on
s32 fn_801EAF20(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* No-op stub. */
void fn_801EAF60(void) {

}

void *DrawList_getCurrentMatrix(void);
float PSVECDotProduct(float *, float *, float);
float fn_801EAF64(void *obj) {
    /* Return the camera-space depth of obj's position (+0x28): dot((obj.pos - camera.pos), camera.forward). */
    float delta[3];
    void *camera;

    camera = DrawList_getCurrentMatrix();
    delta[0] = *(float *)((u8 *)obj + 0x28) - *(float *)((u8 *)camera + 0x24);
    delta[1] = *(float *)((u8 *)obj + 0x2C) - *(float *)((u8 *)camera + 0x28);
    delta[2] = *(float *)((u8 *)obj + 0x30) - *(float *)((u8 *)camera + 0x2C);
    return ((float (*)(float *, float *))PSVECDotProduct)(
        delta, (float *)((u8 *)camera + 0x18));
}

extern void *DrawList_getCurrentMatrix(void);
extern float PSVECDotProduct(float *, float *, float);
extern void fn_801EABA8(void *, void *);
extern void fn_802DAC54(void);
extern int fn_802C7A40(int, void *, int, int, void *, int);
extern void fn_802C70AC(int, void *, int, int);
extern void fn_802C6CF8(s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_801EAB2C(void*);
extern void fn_801EAB80(void*, s32);
extern u8 lbl_80339E3C[];
