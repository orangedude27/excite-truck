// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562708;
extern float lbl_80562704;
extern float lbl_80562738;
void fn_801B7760(int, int, float, float);
void fn_801B78EC(int, int, int, float, float, float);
float fn_8002F234(float, float, float, float, float);
void fn_801B7C8C(int, float *, float *);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_801769A8(void);
extern int fn_801769B8(void);
extern int fn_801796B4(void);
int fn_801B7688(int arg0) {
    int result;
    int state;
    int zero;
    int flags;

    flags = *((int *)__AXFXGetLfoSinTable_801769CC() + 1);
    result = 1;
    if (flags & 0x100) {
        state = fn_801769B8();
        zero = (state == 0);
        if (arg0 == 0x52)
            goto shared;
        if (arg0 >= 0x52)
            goto done;
        if (arg0 == 0x50)
            goto shared;
        if (arg0 > 0x50) {
            if (zero == 0) {
                if (state == 1)
                    result = 0;
            }
        }
        goto done;
shared:
        if (zero != 0)
            result = 0;
        if (state == 1)
            result = 3;
        if (fn_801769A8() & 0x400)
            result = 4;
    } else {
        result = 2;
    }
done:
    if (fn_801796B4() != 0 && (unsigned)(arg0 - 0x50) <= 1)
        result = 0;
    return result;
}

float fn_801B79AC(void) {
    return *(float *)((char *)fn_80137C54(-1) + 4);
}

void PSVECCrossProduct(float *, float *, float *);
void PSVECNormalize(float *, float *);
void fn_801B7BA8(float *arg0, float *arg1, float *arg2) {
    float a[3];
    float b[3];
    float c[3];
    volatile float *p = arg1;
    volatile float *q = arg2;
    float x = p[0];
    float y = p[1];
    float z = p[2];
    float u = q[0];
    float v = q[1];
    a[0] = x; a[1] = y; a[2] = z;
    b[0] = u; b[1] = lbl_80562708; b[2] = v;
    PSVECCrossProduct(a, b, c);
    PSVECCrossProduct(c, a, b);
    PSVECNormalize(c, c);
    PSVECNormalize(a, a);
    PSVECNormalize(b, b);
    arg0[0] = c[0]; arg0[1] = c[1]; arg0[2] = c[2];
    arg0[3] = a[0]; arg0[4] = a[1]; arg0[5] = a[2];
    arg0[6] = b[0]; arg0[7] = b[1]; arg0[8] = b[2];
}

void fn_801B8040(int arg0, int arg1, float farg0) {
    fn_801B7760(arg0, arg1, farg0, lbl_80562708);
}

void fn_801B8048(int arg0, int arg1, float farg0, float farg1) {
    fn_801B78EC(arg0, arg1, 0, farg0, farg1, lbl_80562708);
}

void fn_801B8054(int arg0, int arg1, float farg0, float farg1) {
    fn_801B78EC(arg0, arg1, 1, farg0, farg1, lbl_80562708);
}

extern char lbl_80336718[];
extern int fn_802E317C(char *, ...);
void fn_801B8100(void *arg0, int arg1, int arg2) {
    int result;
    memset(arg0, 0, 0x50);
    if (fn_801796B4() != 0)
        goto done;
    if (fn_801B8630(arg0, arg1, arg2) != 0)
        goto done;
    result = fn_801B7688(arg2);
    *(int *)((char *)arg0 + 0x44) = result;
    if (result >= 3) {
        if (result < 5)
            goto call_f;
        goto log;
    }
    if (result == 0)
        goto call_f;
    if (result > 0)
        goto call_d;
log:
    fn_802E317C(lbl_80336718, result);
    goto done;
call_f:
    fn_801B7F4C(arg0, arg1, arg2);
    goto done;
call_d:
    fn_801B79D4(arg0, arg1, arg2);
done:
    ;
}

