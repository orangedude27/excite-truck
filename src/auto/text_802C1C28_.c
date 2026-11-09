// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055CFA0, lbl_8055FB2C, lbl_8055FB30;
extern float lbl_804C1050[16];
extern float lbl_8055FB38;
extern float lbl_80564E50, lbl_80564E54, lbl_80564E60, lbl_80564E70, lbl_80564E78, lbl_80564E7C, lbl_80564E80, lbl_80564E84, lbl_80564E88;
extern void *fn_802C110C(int);
extern void *fn_802C120C(void);
extern float fn_80129DC4(int, float, float);
extern void *lbl_8055FB50;
extern char lbl_8034AFB8[4];
extern char lbl_8034AFC8[4];
extern char lbl_8034AFD8[];
extern int lbl_8055FB54;
int fn_8012C33C(void);
int fn_802CAC28(int, int);
void fn_802B52C0(void *);
int fn_802CA294(void *, int, int, int, void *);
int fn_802D9628(short, short, unsigned int);
void fn_802C1C28(void) {}

void fn_802C1C2C(void) {}

void fn_802C1C30(void) {}

void fn_802C1C34(void *arg0, void *obj, int slot) {
    typedef struct { int v[9]; } Block9;
    typedef struct { float v[3]; } Vec3;
    float pos[3], mat[9], vel[3], scale[3];
    int index, i;
    int *info, *data, *entry;
    int **list;
    float *recent;
    void *effect;
    float x, y;
    index = ((int (*)(void *))(*(int **)obj)[9])(obj) - lbl_8055CFA0;
    if (index < 0) return;
    if (index >= lbl_8055FB2C) return;
    info = fn_802C110C(index);
    list = (int **)lbl_8055FB30;
    data = list[index];
    if (data == 0) return;
    if (((int (*)(void *))(*(int **)obj)[8])(obj) == 0x3eb) {
        if (((float *)data)[10] < lbl_80564E70)
            ((void (*)(void *, int))(*(int **)obj)[6])(obj, 0);
        return;
    }
    if (((float *)data)[10] < lbl_80564E70) return;
    recent = &lbl_804C1050[slot * 2];
    if (index != *(int *)recent || lbl_8055FB38 - recent[1] > lbl_80564E78) {
        if (*((unsigned char *)info + 0x28)) {
            float axis[3];
            entry = fn_802C120C();
            entry[1] = (int)data;
            list[index] = 0;
            entry[0] = index;
            *(Block9 *)(entry+2) = *(Block9 *)data;
            *(Vec3 *)(entry+11) = *(Vec3 *)(data+9);
            entry[17] = *(int *)&lbl_8055FB38;
            axis[0] = lbl_80564E54;
            axis[1] = lbl_80564E50;
            axis[2] = lbl_80564E50;
            *(Vec3 *)(entry+14) = *(Vec3 *)axis;
        }
        if (info[15] > 0) {
            for (i=0; i<info[15]; i++) {
                effect = ((void **)info[13])[i];
                *(Vec3 *)pos = *(Vec3 *)(data+9);
                pos[0] += fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                pos[2] += fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                pos[1] += ((float *)info)[11];
                mat[0]=lbl_80564E54; mat[1]=lbl_80564E50; mat[2]=lbl_80564E50;
                mat[3]=lbl_80564E50; mat[4]=lbl_80564E54; mat[5]=lbl_80564E50;
                mat[6]=lbl_80564E50; mat[7]=lbl_80564E50; mat[8]=lbl_80564E54;
                x = fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                y = lbl_80564E80 + fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                vel[0] = fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                vel[1]=y; vel[2]=x;
                x = fn_80129DC4(4, lbl_80564E84, lbl_80564E88);
                y = fn_80129DC4(4, lbl_80564E84, lbl_80564E88);
                scale[0] = fn_80129DC4(4, lbl_80564E84, lbl_80564E88);
                scale[1]=y; scale[2]=x;
                ((void (*)(void *, float *, float *, float *))(*(int **)effect)[10])(effect, mat, vel, scale);
            }
        }
    }
    *(int *)recent = index;
    lbl_804C1050[slot*2+1] = lbl_8055FB38;
}

#pragma dont_inline on
void fn_802C1F80(int arg0) {}

#pragma dont_inline on
void fn_802C1F84(int arg0) {}

void fn_802C1F88(int arg0) {}

extern int lbl_8055FB28;
extern char lbl_8055CFC0[];
extern char lbl_8055CFC8[];
extern char lbl_804C0810[];
extern int strcmp(const char *, const char *);
__declspec(section ".sdata") extern char lbl_8055CFC0[];
__declspec(section ".sdata") extern char lbl_8055CFC8[];
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_802C1F8C(int unused, void *arg1) {
    class FirstInterface {
    public:
        virtual void *resolve();
    };
    class SecondInterface {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *getName(const char *, const char *);
    };
    struct Fn802CEntry {
        char pad[8];
        char name[0x2C];
        void **items;
        int unk38;
        int count;
        char tail[0x20];
    };
    struct Fn802CEntry *entry;
    char *name;
    int i;
    SecondInterface *object;
    FirstInterface *input;

    input = (FirstInterface *)arg1;
    object = (SecondInterface *)input->resolve();
    if (object != 0) {
        name = object->getName(lbl_8055CFC0, lbl_8055CFC8);
        entry = (struct Fn802CEntry *)lbl_804C0810;
        i = 0;
        while (i < lbl_8055FB28) {
            if (strcmp(name, entry->name) == 0) {
                volatile int *countPtr = (volatile int *)((char *)entry + 0x3C);
                void ** volatile *itemsPtr = (void ** volatile *)((char *)entry + 0x34);
                int count = *countPtr;
                void **items = *itemsPtr;
                items[count] = input;
                *countPtr = count + 1;
            }
            entry++;
            i++;
        }
    }
}
#pragma cplusplus off
#pragma pop

void fn_802C2054(int arg0) { fn_802C1F80(arg0 - 4); }

void fn_802C205C(int arg0) { fn_802C1F84(arg0 - 4); }

void fn_802C2064(int arg0) { fn_802C1F88(arg0 - 4); }

void fn_802C1F8C();
void fn_802C206C(int arg0) { fn_802C1F8C(arg0 - 4); }

int fn_802C2074(void *arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28((int)arg0, 0);
    return -2;
}

static int fn_802C2074_noinline(void *arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28((int)arg0, 0);
    return -2;
}

static int fn_802C2074_noinline2(void *arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28((int)arg0, 0);
    return -2;
}

void fn_802C20DC(int *arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}

short fn_802C2120(int arg0) {
    return (short)(((arg0 << 8) / 1024) + 0x80);
}

#pragma dont_inline on
void fn_802C217C(void) {
    fn_802C20DC((int *)&lbl_8055FB50);
    if (lbl_8055FB54 == 0) return;
    fn_802B52B4();
    lbl_8055FB54 = 0;
}
#pragma dont_inline reset
void* fn_802C21B8(void) {
    return lbl_8055FB50;
}

void fn_802C21C0(void) {
    if (lbl_8055FB54 != 0) ((int (*)(int, void *))fn_802B52C0)((int)lbl_8034AFD8, (void *)lbl_8055FB54);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802C21DC(int x, int y, unsigned int color) {
    unsigned int a;
    unsigned int b;
    unsigned int packed;
    short sx;
    short sy;
    int *state;
    short yCoord;
    short xCoord;
    int height;
    int width;
    unsigned int *pixels;
    int index;
    int result;
    if (lbl_8055FB54 != 0) {
        a = (color << 8) & 0xFF00;
        a |= color & 0xFF;
        b = (color << 16) & 0x00FF0000;
        b |= (color >> 8) << 24;
        packed = a | b;
        sx = fn_802C2120(x);
        sy = fn_802C2120(y);
        state = (int *)lbl_8055FB54;
        yCoord = sy;
        height = state[1];
        xCoord = sx;
        width = state[0];
        height--;
        pixels = (unsigned int *)state[2];
        height -= yCoord;
        index = height * width + xCoord;
        pixels[index] = packed;
        result = ((int (*)(int))fn_802CA294)((int)lbl_8055FB50);
        ((void (*)(void *, int, int, unsigned int))fn_802D9628)((void *)result, sx, sy, packed);
    }
}
#pragma pop
