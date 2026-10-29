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
#pragma use_lmw_stmw off
void fn_801E65BC(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 sp68[0x188];
    s32 sp38[12];
    s32 sp14[12];
    s32 sp8[2];
    register s32 *a;
    register s32 *b;
    register s32 i;
    register s32 idx;
    register s32 temp;
    register s32 count;
    s32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
    s32 b0, b1, b2, b3, b4, b5, b6, b7, b8;

    count = arg2;
    if (arg3 != 0) {
        a0=((s32 *)arg1)[0]; a1=((s32 *)arg1)[1];
        a2=((s32 *)arg1)[2]; a3=((s32 *)arg1)[3];
        a4=((s32 *)arg1)[4]; a5=((s32 *)arg1)[5];
        a6=((s32 *)arg1)[6]; a7=((s32 *)arg1)[7];
        a8=((s32 *)arg1)[8]; a9=((s32 *)arg1)[9];
        a10=((s32 *)arg1)[10]; a11=((s32 *)arg1)[11];
        ((s32 *)arg3)[0]=a0; ((s32 *)arg3)[1]=a1;
        ((s32 *)arg3)[2]=a2; ((s32 *)arg3)[3]=a3;
        ((s32 *)arg3)[4]=a4; ((s32 *)arg3)[5]=a5;
        ((s32 *)arg3)[6]=a6; ((s32 *)arg3)[7]=a7;
        ((s32 *)arg3)[8]=a8; ((s32 *)arg3)[9]=a9;
        ((s32 *)arg3)[10]=a10; ((s32 *)arg3)[11]=a11;
    }
    temp = ((s32 *)arg0)[3];
    a = (s32 *)arg1;
    b = (s32 *)((u8 *)arg0 + 0x10);
    i = 0;
    while (i < count) {
        idx = b[13];
        if (idx >= 0) {
            a0=a[0]; a1=a[1]; a2=a[2]; a3=a[3];
            a4=a[4]; a5=a[5]; a6=a[6]; a7=a[7];
            a8=a[8]; a9=a[9]; a10=a[10]; a11=a[11];
            b0=b[0]; b1=b[1]; b2=b[2]; b3=b[3];
            b4=b[4]; b5=b[5]; b6=b[6]; b7=b[7]; b8=b[8];
            sp38[0]=a0; sp38[1]=a1; sp38[2]=a2; sp38[3]=a3;
            sp38[4]=a4; sp38[5]=a5; sp38[6]=a6; sp38[7]=a7;
            sp38[8]=a8; sp38[9]=a9; sp38[10]=a10; sp38[11]=a11;
            sp14[0]=b0; sp14[1]=b1; sp14[2]=b2; sp14[3]=b3;
            sp14[4]=b4; sp14[5]=b5; sp14[6]=b6; sp14[7]=b7;
            sp14[8]=b8;
            fn_801C7254(sp14, b7, b6, b5, b4, b3, b2, b1);
            fn_80015B20(&sp68[idx * 12], sp38, sp14);
            fn_8001BA68(sp8);
            fn_801E67B4(sp8, b + 9, &sp68[idx * 12]);
            fn_801C0E60(&sp68[idx * 12 + 9], b + 9, sp8);
            fn_801BFE7C(&sp68[idx * 12 + 9], &sp68[idx * 12 + 9], &sp38[9]);
            fn_801C0E60(&sp68[idx * 12 + 9], &sp68[idx * 12 + 9], b + 9);
        }
        a += 12;
        b += 14;
        i++;
    }
    fn_802C7A38(0, sp68, temp);
}

void fn_801E67B4(void *arg0, void *arg1, void *arg2) {
    float *out = (float *)arg0;
    float *v = (float *)arg1;
    float *m = (float *)arg2;
    if (arg0 == arg1) {
        float yv = v[1];
        float xv = v[0];
        float zv = v[2];
        float x_y = yv * m[3];
        float y_y = yv * m[4];
        float z_y = yv * m[5];
        float x_x = xv * m[0];
        float y_x = xv * m[1];
        float z_x = xv * m[2];
        float x_z = zv * m[6];
        float y_z = zv * m[7];
        float z_z = zv * m[8];
        out[0] = (x_x + x_y) + x_z;
        out[1] = (y_x + y_y) + y_z;
        out[2] = (z_x + z_y) + z_z;
        return;
    }
    out[0] = v[0] * m[0] + v[1] * m[3] + v[2] * m[6];
    out[1] = v[0] * m[1] + v[1] * m[4] + v[2] * m[7];
    out[2] = v[0] * m[2] + v[1] * m[5] + v[2] * m[8];
}

