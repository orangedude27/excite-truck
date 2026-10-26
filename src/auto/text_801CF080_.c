#include "types.h"

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
void fn_801CFA48(void *arg0) {
 typedef struct { unsigned char *ptr1; int count1; unsigned char *ptr2; int count2; unsigned char *ptr3; int count3; } tFA48View;
 volatile tFA48View *p=(volatile tFA48View *)arg0;
 volatile unsigned char *b=(volatile unsigned char *)arg0;
 unsigned char temp,temp2;
 volatile unsigned char *base,*item;
 int offset,i1,count1,i2,count2,i3;
 temp=b[0]; item=(volatile unsigned char *)arg0+0x18; temp2=b[3]; i1=0; offset=0; b[0]=temp2; b[3]=temp;
        temp=b[1]; temp2=b[2]; b[1]=temp2; b[2]=temp;
        temp=b[4]; temp2=b[7]; b[4]=temp2; b[7]=temp;
        temp=b[5]; temp2=b[6]; b[5]=temp2; b[6]=temp;
        temp=b[8]; temp2=b[11]; b[8]=temp2; b[11]=temp;
        temp=b[9]; temp2=b[10]; b[9]=temp2; b[10]=temp;
        temp=b[12]; temp2=b[15]; b[12]=temp2; b[15]=temp;
        temp=b[13]; temp2=b[14]; b[13]=temp2; b[14]=temp;
        temp=b[16]; temp2=b[19]; b[16]=temp2; b[19]=temp;
        temp=b[17]; temp2=b[18]; b[17]=temp2; b[18]=temp;
        temp=b[20]; temp2=b[23]; b[20]=temp2; b[23]=temp;
        temp=b[21]; temp2=b[22]; b[21]=temp2; b[22]=temp;
 count1=p->count1; count2=p->count2; count1*=0x18; p->ptr1=(unsigned char *)item; item+=count1; p->ptr2=(unsigned char *)item; count2*=0xC; item+=count2; p->ptr3=(unsigned char *)item;
 goto check1;
loop1:
 base=p->ptr1; i1++; item=base+offset; temp=base[offset]; temp2=item[3]; offset+=0x18; item[0]=temp2; item[3]=temp;
        temp=item[1]; temp2=item[2]; item[1]=temp2; item[2]=temp;
        temp=item[4]; temp2=item[7]; item[4]=temp2; item[7]=temp;
        temp=item[5]; temp2=item[6]; item[5]=temp2; item[6]=temp;
        temp=item[8]; temp2=item[11]; item[8]=temp2; item[11]=temp;
        temp=item[9]; temp2=item[10]; item[9]=temp2; item[10]=temp;
        temp=item[12]; temp2=item[15]; item[12]=temp2; item[15]=temp;
        temp=item[13]; temp2=item[14]; item[13]=temp2; item[14]=temp;
        temp=item[16]; temp2=item[19]; item[16]=temp2; item[19]=temp;
        temp=item[17]; temp2=item[18]; item[17]=temp2; item[18]=temp;
        temp=item[20]; temp2=item[23]; item[20]=temp2; item[23]=temp;
        temp=item[21]; temp2=item[22]; item[21]=temp2; item[22]=temp;
check1:
 if(i1<p->count1) goto loop1;
 i2=0; offset=0; goto check2;
loop2:
 base=p->ptr2; i2++; item=base+offset; temp=base[offset]; temp2=item[3]; offset+=0xC; item[0]=temp2; item[3]=temp;
        temp=item[1]; temp2=item[2]; item[1]=temp2; item[2]=temp;
        temp=item[4]; temp2=item[7]; item[4]=temp2; item[7]=temp;
        temp=item[5]; temp2=item[6]; item[5]=temp2; item[6]=temp;
        temp=item[8]; temp2=item[11]; item[8]=temp2; item[11]=temp;
        temp=item[9]; temp2=item[10]; item[9]=temp2; item[10]=temp;
check2:
 if(i2<p->count2) goto loop2;
 i3=0; offset=0; goto check3;
loop3:
 base=p->ptr3; item=base+offset; temp=base[offset]; temp2=item[1]; item[0]=temp2; item[1]=temp; temp=item[2]; temp2=item[3]; item[2]=temp2; item[3]=temp;
        temp=item[24]; temp2=item[27]; item[24]=temp2; item[27]=temp;
        temp=item[25]; temp2=item[26]; item[25]=temp2; item[26]=temp;
        temp=item[28]; temp2=item[31]; item[28]=temp2; item[31]=temp;
        temp=item[29]; temp2=item[30]; item[29]=temp2; item[30]=temp;
        temp=item[32]; temp2=item[35]; item[32]=temp2; item[35]=temp;
        temp=item[33]; temp2=item[34]; item[33]=temp2; item[34]=temp;
        temp=item[4]; temp2=item[5]; item[4]=temp2; item[5]=temp;
        temp=item[36]; temp2=item[39]; item[36]=temp2; item[39]=temp;
        temp=item[37]; temp2=item[38]; item[37]=temp2; item[38]=temp;
        temp=item[40]; temp2=item[43]; item[40]=temp2; item[43]=temp;
        temp=item[41]; temp2=item[42]; item[41]=temp2; item[42]=temp;
        temp=item[44]; temp2=item[47]; item[44]=temp2; item[47]=temp;
        temp=item[45]; temp2=item[46]; item[45]=temp2; item[46]=temp;
        temp=item[6]; temp2=item[7]; item[6]=temp2; item[7]=temp;
        temp=item[48]; temp2=item[51]; item[48]=temp2; item[51]=temp;
        temp=item[49]; temp2=item[50]; item[49]=temp2; item[50]=temp;
        temp=item[52]; temp2=item[55]; item[52]=temp2; item[55]=temp;
        temp=item[53]; temp2=item[54]; item[53]=temp2; item[54]=temp;
        temp=item[56]; temp2=item[59]; item[56]=temp2; item[59]=temp;
        temp=item[57]; temp2=item[58]; item[57]=temp2; item[58]=temp;
 temp=item[8]; offset+=0x3C; i3++; temp2=item[0xB]; item[8]=temp2; item[0xB]=temp;
        temp=item[9]; temp2=item[10]; item[9]=temp2; item[10]=temp;
        temp=item[12]; temp2=item[15]; item[12]=temp2; item[15]=temp;
        temp=item[13]; temp2=item[14]; item[13]=temp2; item[14]=temp;
        temp=item[16]; temp2=item[19]; item[16]=temp2; item[19]=temp;
        temp=item[17]; temp2=item[18]; item[17]=temp2; item[18]=temp;
        temp=item[20]; temp2=item[23]; item[20]=temp2; item[23]=temp;
        temp=item[21]; temp2=item[22]; item[21]=temp2; item[22]=temp;
check3:
 if(i3<p->count3) goto loop3;
}

extern s32 fn_8012C370(s32, s32 *, s32, s32, u8 *);
extern void fn_801CFA48(void *);
#pragma scheduling invalid_target
void fn_801CFEAC(void) {
    s32 spC;
    u8 sp8;
    s32 temp_r31;

    spC = 1;
    sp8 = 0;
    temp_r31 = fn_8012C370(0x504D7368, &spC, 0, 0, &sp8);
    if (sp8 != 0) {
        fn_801CFA48((void *)0);
    }
}
#pragma scheduling on
void fn_801CFF14(void) {
    fn_8012C4D8();
}

extern void fn_802C8B08(float *);
extern void PSVECCrossProduct(const float *, const float *, float *);

extern void fn_801E41D8(void *, void *, int, float);
extern float lbl_80562A38;
extern float lbl_80562A40;
extern float lbl_80562A44;
#pragma ppc_psq_save off
#pragma scheduling invalid_target
void fn_801CFF18(void *arg0, float *arg1) {
    unsigned int m[12];
    float scratch[12];
    float points[3][3];
    float tz, ty, tx;
    int offset, i;

    if (arg1 != 0) {
        unsigned int *src = (unsigned int *)arg1;
        m[0] = src[0]; m[1] = src[1]; m[2] = src[2]; m[3] = src[3];
        m[4] = src[4]; m[5] = src[5]; m[6] = src[6]; m[7] = src[7];
        m[8] = src[8]; m[9] = src[9]; m[10] = src[10]; m[11] = src[11];
    } else {
        float zero = lbl_80562A38;
        float one = lbl_80562A40;
        ((float *)m)[1] = zero;
        ((float *)m)[0] = one;
        ((float *)m)[2] = zero;
        ((float *)m)[3] = zero;
        ((float *)m)[4] = one;
        ((float *)m)[5] = zero;
        ((float *)m)[6] = zero;
        ((float *)m)[7] = zero;
        ((float *)m)[8] = one;
        ((float *)m)[9] = zero;
        ((float *)m)[10] = zero;
        ((float *)m)[11] = zero;
    }
    fn_802C8B08(scratch);
    tx = ((float *)m)[9];
    ty = ((float *)m)[10];
    tz = ((float *)m)[11];

    for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0x14); offset += 0x3C, i++) {
        char *index = (char *)*(void **)((char *)arg0 + 0x10) + offset;
        float *dst = &points[0][0];
        int j;
        for (j = 0; j < 3; j++) {
            int indexValue = *(short *)(index + 2);
            char *vertices = *(char **)((char *)arg0 + 8);
            float *src = (float *)(vertices + indexValue * 0xC);
            float *matrix = (float *)m;
            if (dst == src) {
                float x = matrix[3] * src[1] + matrix[0] * src[0] + matrix[6] * src[2];
                float y = matrix[4] * src[1] + matrix[1] * src[0] + matrix[7] * src[2];
                float z = matrix[5] * src[1] + matrix[2] * src[0] + matrix[8] * src[2];
                dst[0] = x;
                dst[1] = y;
                dst[2] = z;
            } else {
                dst[0] = matrix[3] * src[1] + matrix[0] * src[0] + matrix[6] * src[2];
                dst[1] = matrix[4] * src[1] + matrix[1] * src[0] + matrix[7] * src[2];
                dst[2] = matrix[5] * src[1] + matrix[2] * src[0] + matrix[8] * src[2];
            }
            dst[0] += tx;
            dst[1] += ty;
            dst[2] += tz;
            index += 2;
            dst += 3;
        }

        {
            float v1[3], v2[3], normal[3], eye[3];
            v1[0] = points[1][0] - points[0][0];
            v1[1] = points[1][1] - points[0][1];
            v1[2] = points[1][2] - points[0][2];
            v2[0] = points[2][0] - points[0][0];
            v2[1] = points[2][1] - points[0][1];
            v2[2] = points[2][2] - points[0][2];
            PSVECCrossProduct(v1, v2, normal);
            eye[0] = points[0][0] - scratch[9];
            eye[1] = points[0][1] - scratch[10];
            eye[2] = points[0][2] - scratch[11];
            if (!(PSVECDotProduct(normal, eye) > lbl_80562A38)) {
                fn_801E41D8(points[0], points[1], 0x80FFFF00, lbl_80562A44);
                fn_801E41D8(points[1], points[2], 0x80FFFF00, lbl_80562A44);
                fn_801E41D8(points[2], points[0], 0x80FFFF00, lbl_80562A44);
            }
        }
    }
}
#pragma scheduling on
#pragma ppc_psq_save reset
