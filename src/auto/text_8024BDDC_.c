// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma paired off
#pragma paired_single off
typedef struct { float x, y, z; int color; float u, v; } Vtx;
typedef struct { float x, y, z; } Vec3;
typedef union { double d; float f[2]; } VtxXY;
typedef struct { VtxXY xy; float z; int color; float u, v; } VtxU;
typedef union { double d; float f[2]; } VtxPair;
typedef union { int i; float f; } VtxWord;
extern void fn_80129AFC(void);
extern void fn_802C2B48(void);
extern void fn_802C8530(void);
extern void fn_802C855C(void);
extern void fn_802C8638(float*);
extern void fn_802C86E8(unsigned int);
extern void DrawList_setViewport(int, int, int, int);
extern void fn_802C88BC(int);
extern void fn_802C8BD0(int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, float, float);
extern void fn_802C8D74(void);
extern void fn_802C8DB8(float*, int, unsigned short*, int);
extern void fn_802C974C(float, float, float);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802E30C8(void*, ...);
extern unsigned short fn_802E46F0(void);
extern int fn_802E47B8(void);
extern char lbl_80343E90[];
extern unsigned short lbl_802FA510[];
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern float lbl_80563908;
extern float lbl_8056390C;
extern float lbl_80563910;
extern float lbl_80563914;
extern float lbl_80563918;
extern float lbl_8056391C;
extern void fn_8024BB98(void*);
extern void fn_8024BBF4(void*);
/* C++ this-adjusting thunk: the pointer received is a base subobject at +0x34
   inside the derived object, so adjust back to the object start and tail-call
   the real method. */
void fn_8024BDDC(void* subobject) {
    fn_8024BB98((char*)subobject - 0x34);
}

extern void __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8024A110(void*);
/* C++ this-adjusting destructor thunk: the pointer received is a base subobject
   at +0x34 inside a DisposeCallbackManager, so adjust back to the object start
   and tail-call the real destructor. */
void fn_8024BDE4(void* subobject) {
    __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8024A110((char*)subobject - 0x34);
}

/* C++ this-adjusting thunk: the pointer received is a base subobject at +0x18
   inside the derived object, so adjust back to the object start and tail-call
   the real method fn_8024BBF4. */
void fn_8024BDEC(void* subobject) {
    fn_8024BBF4((char*)subobject - 0x18);
}

extern void fn_8024BCC0(void*);
/* C++ this-adjusting thunk: the pointer received is a base subobject at +0x18
   inside the derived object, so adjust back to the object start and tail-call
   the real method fn_8024BCC0. */
void fn_8024BDF4(void* subobject) {
    fn_8024BCC0((char*)subobject - 0x18);
}

extern void __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC(void*);
/* C++ destructor thunk for a base subobject at +0x18: adjust the pointer back
   to the object start and tail-call the MemorySoundArchive destructor. */
void fn_8024BDFC(void* subobject) {
    __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC((char*)subobject - 0x18);
}

#pragma scheduling invalid_target
void fn_8024BE04(void) {
    unsigned short *tbl;
    char *base;
    float *mp;
    int h;
    int i;
    float m[12];
    Vtx v[4];
    volatile Vec3 p3, p2, p1, p0;
    unsigned short idx[6];
    float one, zero, z;
    base = lbl_80343E90;
    fn_802E30C8(base);
    h = fn_802CAC28(base + 0xC, 0);
    zero = lbl_8056390C;
    one = lbl_80563908;
    z = zero - lbl_80563910;
    for (i = 0;; i++) {
        m[0] = one; m[1] = zero; m[2] = zero; m[3] = zero;
        m[4] = one; m[5] = zero; m[6] = zero; m[7] = zero;
        m[8] = one; m[9] = zero; m[10] = zero; m[11] = z;
        fn_802C8530();
        DrawList_setViewport(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_802C86E8(0xFF7F7F7F);
        fn_802C88BC(3);
        fn_802C974C(lbl_80563914, lbl_80563918, lbl_8056391C);
        mp = m;
        fn_802C8638(mp);
        p0.x = zero; p0.y = zero; p0.z = zero;
        p1.x = one; p1.y = zero; p1.z = zero;
        p2.x = zero; p2.y = one; p2.z = zero;
        p3.x = one; p3.y = one; p3.z = zero;
        v[0].x = zero; v[0].y = zero; v[0].z = zero; v[0].color = -1; v[0].u = zero; v[0].v = zero;
        *(double *)&v[1].x = *(double *)&v[0].x; *(int *)&v[1].z = *(int *)&v[0].z;
        *(double *)&v[2].x = *(double *)&v[0].x; *(int *)&v[2].z = *(int *)&v[0].z;
        v[1].x = one; v[1].y = zero; v[1].z = zero; v[1].color = -1; v[1].u = one; v[1].v = zero;
        v[2].x = zero; v[2].y = one; v[2].z = zero; v[2].color = -1; v[2].u = zero; v[2].v = one;
        *(double *)&v[3].x = *(double *)&v[2].x; *(int *)&v[3].z = *(int *)&v[2].z;
        v[3].x = one; v[3].y = one; v[3].z = zero; v[3].color = -1; v[3].u = one; v[3].v = one;
        tbl = lbl_802FA510;
        idx[0] = tbl[0];
        idx[1] = tbl[1];
        idx[2] = tbl[2];
        idx[3] = tbl[3];
        idx[4] = tbl[4];
        idx[5] = tbl[5];
        fn_802C8BD0(h, tbl[4], tbl[3], tbl[2], tbl[1], tbl[0], v[2].z, v[0].z);
        fn_802C8DB8((float*)v, 4, idx, 6);
        fn_802C8D74();
        fn_802C855C();
        fn_802C2B48();
        if ((i & 0x3f) == 0) fn_802E30C8(base + 0x18, i);
        fn_80129AFC();
        if (fn_802E47B8() != 0 && fn_802E46F0() == 0x1b) break;
    }
    fn_802CAC54(h);
    fn_802E30C8(base + 0x24);
}
