// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
extern void *lbl_804349C0[];
extern void *lbl_804349E0[];
extern int lbl_80333390;
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);

void fn_8019386C(void) {
    fn_80193CE0();
}

void fn_8019416C(void) {

}

void fn_80194AF4(float *out, float *a, float *b, float t) {
    float x, y;
    x = a[0] + t * (b[0] - a[0]);
    y = a[1] + t * (b[1] - a[1]);
    out[0] = x;
    out[1] = y;
    out[2] = a[2] + t * (b[2] - a[2]);
}

extern float PSVECDotProduct(const void *, const void *);
extern void fn_8013B744(int);
extern void fn_80194FD0(void);
void fn_80194F70(void *arg0, float *arg1, float *arg2) {
    float diff[3];
    diff[0] = arg1[0] - arg2[0];
    diff[1] = arg1[1] - arg2[1];
    diff[2] = arg1[2] - arg2[2];
    PSVECDotProduct(arg0, diff);
}

void fn_80194FC4(void) {

}

void fn_80194FC8(void *arg0) {
    fn_8013B744(*(int *)((unsigned char *)arg0 + 0x290));
}

void fn_801955F0(void *arg0, float *arg1) {
    float scale;
    fn_80194FD0();
    scale = *(float *)((unsigned char *)arg0 + 0x2B8);
    arg1[0] += *(float *)((unsigned char *)arg0 + 0x58) * scale;
    arg1[1] += *(float *)((unsigned char *)arg0 + 0x5C) * scale;
}

void fn_801961F8(void) {

}

void fn_8019639C(void) {
    fn_80194844();
}

void fn_80196414(void *arg0) {
    fn_80196DC4(arg0);
}

void fn_80196A9C(void) {
    fn_8019684C();
}

void fn_80198488(void *arg0) {
    int a;
    int b;
    int zero;
    int limit;
    a = *((unsigned char *)arg0 + 0x9C);
    b = *((unsigned char *)arg0 + 0x74);
    limit = (int)*(float *)((unsigned char *)arg0 + 0x2F4);
    if (b + a + 1 > limit) {
        zero = (*(int *)((unsigned char *)arg0 + 0x18) == 0);
        if (zero) {
            if (b != 0) {
                if (*((unsigned char *)arg0 + 0x74) != 0)
                    fn_80193138(*(int *)((unsigned char *)arg0 + 0x90));
                else
                    fn_80193138(-1);
            }
        } else if (a != 0) {
            if (*((unsigned char *)arg0 + 0x9C) != 0)
                fn_80193138(*(int *)((unsigned char *)arg0 + 0xB8));
            else
                fn_80193138(-1);
        }
    }
}

void *fn_80198DD0(void *arg0, int arg1) {
    int i;
    int count;
    void **items;
    if (arg0 == 0) return arg0;
    *(void **)arg0 = &lbl_80333390;
    count = *(int *)((unsigned char *)lbl_804349E0 + 0x20);
    items = (void **)lbl_804349E0;
    for (i = 0; i < count; i++) {
        if (items[i] == arg0) {
            count--;
            *(int *)((unsigned char *)lbl_804349E0 + 0x20) = count;
            items[i] = items[count];
        }
    }
    if (arg1 > 0) fn_80128668(arg0);
    return arg0;
}

void fn_80198EA0(void) {
    fn_80198E7C();
}

typedef unsigned char u8;
extern void *lbl_804349C0[];
extern void *lbl_804349E0[];
extern int lbl_80333390;
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);
int fn_80198EA4(void) { return 0; }

