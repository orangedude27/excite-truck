// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_80128668();
int fn_80131818();
int fn_80128658(int);
int fn_80139B70(int, float, float);
extern int lbl_8055E138;
extern int lbl_8055E13C;
extern unsigned char lbl_8042F7C0;
void fn_80139B5C(void *arg0, int arg1) {
    volatile float *p = (volatile float *)((char *)arg0 + 0x60);
    float a = p[0];
    float b = p[2];
    fn_80139B70(arg1, a, b);
}

extern float lbl_80561410;
int fn_80139B70(int arg0, float arg1, float arg2) {
    int i, count, result = 0;
    float *p = (float *)(arg0 + 8);
    count = *(int *)arg0;
    for (i = 0; i < count; i++, p += 2) {
        int next = i + 1;
        int index = next % count;
        float *q = (float *)(arg0 + index * 8);
        float y0 = p[1];
        float y1 = q[3];
        int rising = y0 < y1;
        if (rising) {
            if (arg2 < y0 || arg2 > y1) continue;
        } else if (arg2 < y1 || arg2 > y0) continue;
        {
            float x0 = p[0], x1 = q[2];
            float dy = y1 - y0, dx = -(x1 - x0);
            float vy = arg2 - y0, vx = arg1 - x0;
            if (rising == (dy * vx + dx * vy < lbl_80561410)) result++;
        }
    }
    return result & 1;
}

extern float lbl_80561414;
unsigned long long fn_80139C5C(void *arg0) {
    int count = *(int *)arg0;
    float *point = (float *)((char *)arg0 + 0x10);
    volatile float bounds[4];
    union { float f; unsigned int u; } x, y;
    bounds[0] = *(float *)((char *)arg0 + 8);
    bounds[1] = *(float *)((char *)arg0 + 12);
    bounds[2] = bounds[0];
    bounds[3] = bounds[1];
    if (count > 1) {
        do {
            float px = point[0], py = point[1];
            if (px < bounds[2]) bounds[2] = px;
            if (py < bounds[3]) bounds[3] = py;
            if (px > bounds[0]) bounds[0] = px;
            if (py > bounds[1]) bounds[1] = py;
            point += 2;
        } while (--count > 1);
    }
    x.f = bounds[2] + lbl_80561414 * (bounds[0] - bounds[2]);
    y.f = bounds[3] + lbl_80561414 * (bounds[1] - bounds[3]);
    return ((unsigned long long)x.u << 32) | y.u;
}

void *fn_80131810(void);
void *fn_801284F8(int, const char *);
void *fn_801399FC(void);
extern const char lbl_8032C0C8[];
void *fn_80139D4C(void) {
    void *source;
    void *object;
    int count;
    int (*next)(void *, int);
    void *item;
    int n;

    object = 0;
    source = fn_80131810();
    if (source != 0) {
        object = fn_801284F8(0x90, lbl_8032C0C8);
        if (object != 0) {
            *(void **)((char *)object + 4) = (char *)object + 0x10;
            *(int *)((char *)object + 12) = 0x20;
            *(int *)((char *)object + 8) = 0;
            *(void **)object = source;
            count = 0;
            do {
                item = fn_801399FC();
                n = *(int *)((char *)object + 8);
                count++;
                *(int *)((char *)object + 8) = n + 1;
                ((void **)*(void **)((char *)object + 4))[n] = item;
                next = *(int (**)(void *, int))(*(char **)source + 12);
            } while (next(source, count) != 0);
        }
    }
    return object;
}

void fn_80139E18(void *arg0) {
    int i, offset, value;
    if (arg0 == 0)
        return;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        fn_80128658(*(int *)(*(int *)((char *)arg0 + 4) + offset));
        offset += 4;
        i++;
    }
    *(int *)((char *)arg0 + 8) = 0;
    if (*(int *)arg0 != 0)
        fn_80131818();
    value = 0;
    *(int *)arg0 = value;
    if ((char *)arg0 + 4 != 0) {
        *(int *)((char *)arg0 + 4) = value;
        *(int *)((char *)arg0 + 8) = value;
        *(int *)((char *)arg0 + 12) = value;
    }
    fn_80128668(arg0);
}

int fn_80139EC4(void *arg0, float arg1, float arg2) {
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        if (fn_80139B70(*(int *)(*(int *)((char *)arg0 + 4) + offset), arg1, arg2) != 0)
            return 1;
        offset += 4;
        i++;
    }
    return 0;
}

extern __declspec(section ".data") unsigned char lbl_8042F7C0;
void fn_8013A074(void) {
    int state = lbl_8055E138;
    if (state != 0)
        fn_80131818(state);
    lbl_8055E13C = 0;
    lbl_8042F7C0 = 0;
}

extern int fn_802E30C8(const char *, ...);
extern __declspec(section ".sdata") int lbl_8055E138;
extern __declspec(section ".sdata") int lbl_8055E13C;
extern const char lbl_8032C0F0[];
int *fn_8013A0B0(int *arg0, int arg1, char *arg2) {
    int (**vtable)(char *);
    int value;
    *arg0 = 0;
    if (lbl_8055E138 != 0 && *arg2 != 0) {
        vtable = *(int (***)(char *))lbl_8055E138;
        if (vtable[4](arg2) != 0) {
            *arg0 = vtable[2](arg2);
        } else {
            fn_802E30C8(lbl_8032C0F0, arg1, arg2, &lbl_8042F7C0);
        }
    }
    value = *arg0;
    if (value == 0) {
        vtable = *(int (***)(char *))lbl_8055E13C;
        *arg0 = vtable[23](arg2);
    }
    return arg0;
}

int *fn_8013A198(int *arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = 0;
        if (arg1 > 0)
            fn_80128668();
    }
    return arg0;
}
typedef struct { int (**vtable)(void *, char *); } Obj;
