// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_804349A0[];
extern int lbl_8055E518;
extern float lbl_80562080, lbl_8056208C, lbl_80562090, lbl_805620AC;
int fn_801B665C();
void fn_80191084();
void fn_801B6650();
int fn_80191100(void *);
void fn_802793B0();
void fn_801902A0(void *arg0) {
    ((void (**)(void))(*(void **)*(void **)((char *)arg0 + 4)))[30]();
}

void fn_801902B4(void *arg0) {
    unsigned int temp_r3;
    int (*callback)(void *);

    fn_80191084(arg0, 0);
    fn_801B6650(*(int *)((char *)arg0 + 0x20));
    callback = (int (*)(void *))fn_80191100;
    temp_r3 = callback(arg0);
    if (temp_r3 != *(unsigned int *)((char *)arg0 + 8)) {
        fn_80191084(arg0);
    } else {
        fn_80191084(arg0, *(unsigned int *)((char *)arg0 + 0xC));
    }
    fn_80191084(arg0, temp_r3);
    if (*(unsigned char *)((char *)arg0 + 0x38) != 0) {
        *(unsigned char *)((char *)arg0 + 0x38) = 0;
        fn_802793B0(*(int *)((char *)arg0 + 0x28));
    }
    ((void (**)(void *))(*(void ***)arg0))[12](arg0);
}

void fn_80190360(int arg0) {
    fn_80191084(arg0, 0);
}

int fn_80190368(int arg0) {
    int result = 0;
    if (arg0 != 1) {
        if (arg0 == 0) {
            result = 1;
        }
    }
    return result;
}

int fn_80190C8C(void *arg0) {
    return (int)(*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 7) & 8);
}

void fn_80190CA8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    ((void (**)(void))(*(void ***)obj))[31]();
}

void fn_80190CBC(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    ((void (**)(void))(*(void ***)obj))[29]();
}

int fn_80190CD0(float a, float b, float c) {
    float y;
    float x;
    x = a - b;
    y = lbl_80562090;
    x = c - b;
    x = (a - b) / (c - b);
    if (y >= x) {
        y = y;
    } else {
        y = x;
    }
    if (y <= lbl_8056208C) {
        y = y;
    } else {
        y = lbl_8056208C;
    }
    return (((int)(lbl_80562080 + (lbl_8056208C + (y * lbl_805620AC)))) >> 4) & 0xF;
}

extern void *lbl_804349A0[];
extern int lbl_8055E518;
int fn_801B665C();
extern float lbl_80562080, lbl_8056208C, lbl_80562090, lbl_805620AC;
int fn_80190D38(float a, float b, float c) {
    float x = (a - b) / (c - b);
    float y = lbl_80562090;
    if (y < x) y = x;
    if (y > lbl_8056208C) y = lbl_8056208C;
    return (int)(lbl_80562080 + (lbl_8056208C + (y * lbl_805620AC)));
}

int fn_80190E00(void *arg0) { return ((int *)arg0)[2]; }

#pragma dont_inline on
void fn_80190E08(void) {
    int i;
    for (i = 0; i < lbl_8055E518; i++) {
        void *obj = lbl_804349A0[i];
        ((void (**)(void *))(*(void ***)obj))[18](obj);
    }
}
#pragma dont_inline reset

void fn_80190E6C(void) {
    fn_80190E08();
}

void fn_80190E70(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x10);
    if (obj != 0) {
        ((void (**)(void))(*(void ***)obj))[11]();
    }
    fn_801B665C();
}

void fn_80190F90(void) {
    fn_80191758();
}

void fn_80191060(void) {
    fn_801B6664();
}

void fn_80191064(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x10);
    if (obj != 0) {
        ((void (**)(void *))(*(void ***)obj))[17](obj);
    }
}

void fn_80191084(void *arg0, void *arg1) {
    void *old = *(void **)((char *)arg0 + 0x10);
    if (arg1 != old) {
        if (old != 0) {
            ((void (**)(void *))(*(void ***)old))[10](old);
        }
        *(void **)((char *)arg0 + 0x10) = arg1;
        if (arg1 != 0) {
            ((void (**)(void *))(*(void ***)arg1))[9](arg1);
        }
    }
}

int fn_80191100(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_80191108(void *arg0, int arg1) {
    void *obj0 = *(void **)((char *)arg0 + 0xC);
    int result = ((int (**)(void *))(*(void ***)obj0))[6](obj0);
    void *obj1 = *(void **)((char *)arg0 + 8);
    return result + ((int (**)(void *, int))(*(void ***)obj1))[6](obj1, arg1 + result);
}

void fn_80192BE4(void) {

}

void fn_80193058(void) {
}

