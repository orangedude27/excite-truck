// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562844;
extern float lbl_80562848;
extern int lbl_8055E798;
extern int lbl_8055E79C;
int fn_801BD628(float *arg0) {
    int result = 0;
    if (arg0[0] >= lbl_80562844 && arg0[0] <= lbl_80562848 &&
        arg0[1] >= lbl_80562844 && arg0[1] <= lbl_80562848 &&
        arg0[2] >= lbl_80562844 && arg0[2] <= lbl_80562848) {
        result = 1;
    }
    return result;
}

void fn_801BD694(int arg0) {
    extern int lbl_8055E78C, lbl_8055E790, lbl_8055E794, lbl_8055E798, lbl_8055E79C, lbl_8055E7A0, lbl_8055E7A4;
    extern signed char lbl_8055E7A8;
    extern char lbl_80336A50[], lbl_8055A924[], lbl_8055A92C[], lbl_8055A934[], lbl_8055A93C[];
    extern void fn_801BD78C(void), fn_801BD788(void), fn_801BD784(void);
    extern void *fn_8012850C(int, const char *);
    extern void *fn_8002F37C(void *, void (*)(void), int, int, int);
    int temp;
    lbl_8055E790 = arg0; lbl_8055E78C = 0;
    fn_8012850C(arg0 * 0xB0 + 0x10, lbl_80336A50);
    lbl_8055E794 = (int)fn_8002F37C(0, fn_801BD78C, 0xB0, arg0, 0);
    temp = lbl_8055E790;
    fn_8012850C(temp * 0x1F0 + 0x10, lbl_8055A924);
    lbl_8055E798 = (int)fn_8002F37C(0, fn_801BD788, 0x1F0, temp, 0);
    temp = lbl_8055E790;
    fn_8012850C(temp * 0x190 + 0x10, lbl_8055A92C);
    lbl_8055E79C = (int)fn_8002F37C(0, fn_801BD784, 0x190, temp, 0);
    fn_8012850C(lbl_8055E790 * 0x14, lbl_8055A934);
    lbl_8055E7A4 = (int)fn_8012850C(lbl_8055E790, lbl_8055A93C);
    lbl_8055E7A8 = 1;
}

void fn_801BD784(void) {

}

void fn_801BD788(void) {

}

void fn_801BD78C(void) {

}

void fn_801BDA70(void) {
    fn_80279D40();
}

extern float lbl_80562838, lbl_8056283C, lbl_80562854;
extern float fn_8002F234(float);
void fn_801BE168(int index, float *v, float *a, float *b, float w) {
    extern int lbl_8055E794;
    float out[4], t = v[0] + v[4] + v[8], q;
    int i, j, k;
    float *dst = (float *)(lbl_8055E794 + index * 0xB0);
    dst[0]=v[9]; dst[1]=v[10]; dst[2]=v[11]; dst[3]=w;
    if (t > lbl_80562838) {
        q=fn_8002F234(lbl_8056283C+t); out[3]=lbl_80562854*q;
        out[0]=lbl_80562854/q*(v[5]-v[7]); out[1]=lbl_80562854/q*(v[6]-v[2]); out[2]=lbl_80562854/q*(v[1]-v[3]);
    } else {
        i=0; if(v[4]>v[0]) i=1; if(v[8]>v[i*3]) i=2;
        j=(i+1)%3; k=(j+1)%3;
        q=fn_8002F234(lbl_8056283C+v[i*3+i]-(v[j*3+j]+v[k*3+k]));
        out[i]=lbl_80562854*q; out[3]=lbl_80562854/q*(v[j*3+k]-v[k*3+j]);
        out[j]=lbl_80562854/q*(v[i*3+j]+v[j*3+i]); out[k]=lbl_80562854/q*(v[i*3+k]+v[k*3+i]);
    }
    dst[16]=-out[0]; dst[17]=-out[1]; dst[18]=-out[2]; dst[19]=out[3];
    dst[20]=a[0]; dst[21]=a[1]; dst[22]=a[2]; dst[23]=0.0f;
    dst[24]=b[0]; dst[25]=b[1]; dst[26]=b[2]; dst[27]=0.0f;
}

void fn_801BEB1C(int arg0, int *arg1) {
    *arg1 = lbl_8055E798 + arg0 * 0x1F0;
}

extern float lbl_80562838;
extern float lbl_8056283C;
extern float lbl_805628A4;
extern int fn_801E9E78(int, void *, void *);
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A4;
extern int lbl_8055E78C;
void fn_801BEDA8(int *arg0, int *arg1, int *arg2, int *arg3, int *arg4) {
    *arg0 = lbl_8055E794;
    *arg1 = lbl_8055E798;
    *arg2 = lbl_8055E79C;
    *arg3 = lbl_8055E7A4;
    *arg4 = lbl_8055E78C;
}

void fn_801BF0C4(void *arg0, void *arg1, int arg2) {
    if (fn_801E9E78(arg2, arg1, arg0) == 0) {
        float a = lbl_80562838;
        float b = lbl_8056283C;
        float c = lbl_80562838;
        float d = lbl_805628A4;
        ((float *)arg1)[0] = a;
        ((float *)arg1)[1] = b;
        ((float *)arg1)[2] = c;
        ((float *)arg0)[1] = d;
    }
}

void fn_801BF12C(float *arg0, float *arg1) {
    float d;
    float c;
    float b;
    float a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
}

void fn_801BF150(void *arg0, float farg0, float farg1, float farg2, float farg3) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
    ((float *)arg0)[3] = farg3;
}

void fn_801BF164(float *arg0, float *arg1) {
    float d;
    float c;
    float b;
    float a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
}

void GXInitLightAttnA_801BF188(void *arg0, float farg0, float farg1, float farg2) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
}

void fn_801BF198(void *arg0, void *arg1) {
    float temp_f0 = ((float *)arg1)[0];
    float temp_f1 = ((float *)arg1)[1];
    float temp_f2 = ((float *)arg1)[2];
    ((float *)arg0)[1] = temp_f1;
    ((float *)arg0)[0] = temp_f0;
    ((float *)arg0)[2] = temp_f2;
}

void fn_801BF1B4(void) {

}

void fn_801BF1B8(int arg0, char arg1) {
    extern int lbl_8055E7A0;
    ((char *)lbl_8055E7A0)[arg0] = arg1;
}

extern float lbl_80562838;
extern float lbl_8056283C;
extern float lbl_805628A4;
extern int fn_801E9E78(int, void *, void *);
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A4;
extern int lbl_8055E78C;
extern int lbl_8055E78C;
extern int lbl_8055E790;
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A0;
extern int lbl_8055E7A4;
extern signed char lbl_8055E7A8;
extern char lbl_80336A50[];
extern char lbl_8055A924[];
extern char lbl_8055A92C[];
extern char lbl_8055A934[];
extern char lbl_8055A93C[];
