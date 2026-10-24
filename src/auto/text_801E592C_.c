#include <types.h>

extern void *fn_802C6C34(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
s32 *fn_801E592C(void) {
    s32 i;
    s32 n;
    void *sp;

    sp = fn_802C6C34();
    n = *(s32 *)((s8 *)sp + 0x10);
    for (i = 0; i < n; i++) {
        s32 *entry = ((s32 ***)sp)[5][i];
        if ((u32)(entry[0] + 0xB2AE0000) == 0x424E) {
            return entry;
        }
    }
    return NULL;
}
#pragma scheduling on
void fn_801E598C(void) {

}

s32 fn_801E5990(void *arg0) {
    return ((s32 *)arg0)[2];
}

extern void fn_80015B20(void *, void *, void *);
extern void fn_8001BA68(void *);
extern void fn_801BFE7C(void *, void *, void *);
extern void fn_801C0E60(void *, void *, void *);
extern void fn_801C7254(void *, s32, s32, s32, s32, s32, s32, s32);
extern void fn_801E67B4(void *, void *, void *);
extern void fn_802C7A38(s32, void *, s32);
void fn_801E65BC(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 sp68[0x180];
    s32 sp14[12];
    s32 sp38[12];
    s32 sp8[2];
    s32 *a = (s32 *)arg1;
    s32 *b = (s32 *)((u8 *)arg0 + 0x10);
    s32 i;
    s32 temp = ((s32 *)arg0)[3];
    if (arg3 != 0) {
        s32 *out = (s32 *)arg3;
        out[0]=a[0]; out[1]=a[1]; out[2]=a[2]; out[3]=a[3];
        out[4]=a[4]; out[5]=a[5]; out[6]=a[6]; out[7]=a[7];
        out[8]=a[8]; out[9]=a[9]; out[10]=a[10]; out[11]=a[11];
    }
    for (i=0; i<arg2; i++) {
        s32 idx=b[13];
        if (idx>=0) {
            sp14[0]=b[0]; sp14[1]=b[1]; sp14[2]=b[2]; sp14[3]=b[3];
            sp14[4]=b[4]; sp14[5]=b[5]; sp14[6]=b[6]; sp14[7]=b[7];
            sp14[8]=b[8]; sp14[9]=b[9]; sp14[10]=b[10]; sp14[11]=b[11];
            fn_801C7254(sp14,b[7],b[6],b[5],b[4],b[3],b[2],b[1]);
            fn_80015B20(&sp68[idx*12],a,sp14);
            fn_8001BA68(sp8);
            fn_801E67B4(sp8,b+9,&sp68[idx*12]);
            fn_801C0E60(&sp68[idx*12+9],b+9,sp8);
            fn_801BFE7C(&sp68[idx*12+9],&sp68[idx*12+9],&sp38[9]);
            fn_801C0E60(&sp68[idx*12+9],&sp68[idx*12+9],b+9);
        }
        a+=12; b+=14;
    }
    fn_802C7A38(0,sp68,temp);
}

void fn_801E67B4(void *arg0, void *arg1, void *arg2) {
    float *out = (float *)arg0;
    float *v = (float *)arg1;
    float *m = (float *)arg2;
    float x, y, z;
    if (arg0 == arg1) {
        x = v[0]; y = v[1]; z = v[2];
        out[0] = x*m[0] + y*m[3] + z*m[6];
        out[1] = x*m[1] + y*m[4] + z*m[7];
        out[2] = x*m[2] + y*m[5] + z*m[8];
        return;
    }
    out[0] = v[0]*m[0] + v[1]*m[3] + v[2]*m[6];
    out[1] = v[0]*m[1] + v[1]*m[4] + v[2]*m[7];
    out[2] = v[0]*m[2] + v[1]*m[5] + v[2]*m[8];
}

