#include "math.h"
extern f64 fn_8002F234(f32, f32, f32);
struct Hit { float x; s32 y; };
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055A070[4];
__declspec(section ".sdata") extern char lbl_8055A078[];
extern int lbl_8055E29C;
extern int lbl_8055E2A0;
void fn_8015F584(int *arg0);
void fn_8015F5F4(int *arg0);
extern float lbl_805617D0;
int stricmp(const char *, const char *);
void fn_80136594(int *, void *, void *);
void* fn_8015EBF8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_8015EC50(unsigned short *arg0, void *arg1) {
    int value;
    fn_80136594(&value, arg1, (char *)arg0 + 4);
    *arg0 = (value - ((int *)((void **)arg1)[11])[7]) / 60;
}

int fn_8015ECC0(void *arg0) {
    register int result = 0;
    register int test = 0;
    if (((int *)arg0)[8] < 1000 && ((unsigned int *)arg0)[6] == 0x54554245) {
        test = 1;
    }
    if (test != 0) {
        if ((float)fabs(((float *)((void **)arg0)[3])[7]) > lbl_805617D0) {
            result = test;
        }
    }
    return result;
}

#pragma push
#pragma auto_inline off
#pragma push
#pragma cplusplus on
extern "C" int fn_8015ED18(void **node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)lbl_8055A070) == 0;
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma cplusplus on
extern "C" int fn_8015ED54(void **node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)lbl_8055A078) == 0;
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma cplusplus on
extern "C" int fn_8015ED90(void **arg0) {
    class Object {
    public:
        virtual void unused01();
        virtual void unused02();
        virtual void unused03();
        virtual void unused04();
        virtual void unused05();
        virtual void unused06();
        virtual void unused07();
        virtual void unused08();
        virtual void unused09();
        virtual void unused10();
        virtual void unused11();
        virtual void unused12();
        virtual void unused13();
        virtual void unused14();
        virtual void unused15();
        virtual void unused16();
        virtual void unused17();
        virtual void unused18();
        virtual void unused19();
        virtual void unused20();
        virtual void unused21();
        virtual void unused22();
        virtual void **get_child(int);
    };
    int count = 0;
    int i;
    void **child;
    if (arg0 != 0) {
        for (i = 0; (child = ((Object *)arg0)->get_child(i)) != 0; i++) {
            if (fn_8015ED18(child))
                count++;
        }
    }
    return count;
}
#pragma cplusplus reset
#pragma pop

extern int fn_8015ED54(void **);
extern void fn_802E30C8(const char *, int, const char *);
extern char lbl_8032F488[];
extern char lbl_8055A080[], lbl_8055A090[], lbl_8055A08C[], lbl_8055A094[];
void fn_8015EF84(void **arg0) {
    int found = 0;
    int index = 0;
    void **obj;
    if (arg0 != 0) {
        while ((obj = ((void **(*)(void *, int))((void **)*arg0)[0x18])(arg0, index)) != 0) {
            if (fn_8015ED54(obj)) {
                double x = ((double (*)(void *, char *))((void **)*obj)[0xF])(obj, lbl_8055A080);
                float radius = ((float (*)(void *, char *))((void **)*obj)[9])(obj, lbl_8055A090);
                float y = (float)x;
                float radius2 = radius * radius;
                int i = 0;
                int offset = 0;
                found++;
                while (i < *(int *)(lbl_8055E29C + 4)) {
                    char *array = *(char **)lbl_8055E29C;
                    char *entry = array + offset;
                    float dy = y - *(float *)(entry + 8);
                    float dx = (float)(x - *(float *)(entry + 4));
                    if (dx * dx + dy * dy < radius2) {
                        int count = *(int *)(lbl_8055E29C + 4);
                        if (i >= 0 && i < count) {
                            int last = count - 1;
                            if (i != last) {
                                char *from = array + last * 16;
                                *(short *)(entry + 0) = *(short *)(from + 0);
                                *(short *)(entry + 2) = *(short *)(from + 2);
                                *(int *)(entry + 4) = *(int *)(from + 4);
                                *(int *)(entry + 8) = *(int *)(from + 8);
                                *(float *)(entry + 12) = *(float *)(from + 12);
                            }
                            *(int *)(lbl_8055E29C + 4) = count - 1;
                        }
                    } else {
                        offset += 16;
                        i++;
                    }
                }
            }
            index++;
        }
    }
    if (found > 0) {
        fn_802E30C8(lbl_8032F488, found, found == 1 ? lbl_8055A08C : lbl_8055A094);
    }
}

#pragma push
#pragma inline_depth 0
int fn_8015F148(void **arg0, int arg1) {
    int count = 0;
    int i;
    int j;
    void **child;
    int (*predicate)(void *) = fn_8015ECC0;

    for (i = 0; i < arg1; i++) {
        child = *(void ***)arg0;
        if (child != 0) {
            for (j = 0; j < ((int *)child)[0]; j++) {
                void *item = *(void **)((char *)child[1] + j * 4);
                if (predicate((char *)item + 0x3C))
                    count++;
            }
        }
        arg0++;
    }
    return count;
}

extern f32 lbl_805617D4, lbl_805617D8, lbl_805617DC, lbl_805617E0;
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
void fn_8015F1E4(void *arg0, void *arg1) {
    void *inputState = *(void **)((char *)arg1 + 0xC);
    f32 base = *(f32 *)((char *)arg1 + 0x24);
    f32 x = *(f32 *)((char *)inputState + 0x18);
    f32 z = *(f32 *)((char *)inputState + 0x20);
    f32 speed = (f32)((double (*)(f32))fn_8002F234)(x * x + z * z);
    void *state = *(void **)((char *)arg1 + 0xC);
    f32 threshold = lbl_805617D4;
    f32 angle = base + ((lbl_805617D8 * speed) * lbl_805617DC);
    f32 result[5];
    *(f32 *)((char *)arg0 + 0xC) = angle;
    {
        f32 y = *(f32 *)((char *)state + 0x1C);
        if (y < threshold) {
            f32 delta = *(f32 *)((char *)arg1 + 0x28) - lbl_805617E0;
            result[2] = *(f32 *)((char *)state + 0x24) + *(f32 *)((char *)state + 0x18) * delta;
            result[3] = *(f32 *)((char *)state + 0x28) + *(f32 *)((char *)state + 0x1C) * delta;
            result[4] = *(f32 *)((char *)state + 0x2C) + *(f32 *)((char *)state + 0x20) * delta;
        } else {
            f32 delta = -(*(f32 *)((char *)arg1 + 0x28) - lbl_805617E0);
            result[2] = *(f32 *)((char *)state + 0x24) + *(f32 *)((char *)state + 0x18) * delta;
            result[3] = *(f32 *)((char *)state + 0x28) + *(f32 *)((char *)state + 0x1C) * delta;
            result[4] = *(f32 *)((char *)state + 0x2C) + *(f32 *)((char *)state + 0x20) * delta;
        }
    }
    *(f32 *)((char *)arg0 + 4) = result[2];
    *(f32 *)((char *)arg0 + 8) = result[4];
    *(u16 *)((char *)arg0 + 2) = 0;
}
#pragma pop
void fn_8015F1E4();
extern f64 fn_8002F234(f32, f32, f32);
void fn_8015EC50(unsigned short *, void *);
int fn_8015ECC0(void *);
void fn_8015F320(void **arg0, int arg1, void *arg2) {
    int outer;
    int inner;
    int offset;
    void **list;
    void *child;
    void *item;
    void *entry;
    int (*predicate)(void *);
    void (*apply)(unsigned short *, void *);

    predicate = fn_8015ECC0;
    apply = fn_8015EC50;
    list = arg0;
    outer = 0;
    while (outer < arg1) {
        child = *list;
        if (child != 0) {
            inner = 0;
            offset = 0;
            while (inner < *(int *)child) {
                item = *(void **)((char *)*((void ***)((char *)child + 4)) + offset);
                entry = *(void **)((char *)item + 0x3C);
                if (predicate(entry)) {
                    volatile int *registry = (volatile int *)lbl_8055E29C;
                    int count = registry[1];
                    void *array = (void *)registry[0];
                    registry[1] = count + 1;
                    item = (char *)array + count * 0x10;
                    fn_8015F1E4(item, entry);
                    apply((unsigned short *)item, arg2);
                }
                offset += 4;
                inner++;
            }
        }
        list++;
        outer++;
    }
}

#pragma pop
int fn_8015F3EC(unsigned short *arg0, unsigned short *arg1) {
    return *arg0 - *arg1;
}

extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, int);
extern void fn_80265DCC(void *, int, int, void *);
extern int fn_8015F3EC(unsigned short *, unsigned short *);
extern char lbl_8032F4A0[];
extern int lbl_8055A098, lbl_8055E29C, lbl_8055E2A0;
void fn_8015F3FC(void *arg0) {
    register int offset;
    register int *src;
    register int i;
    register int index;
    register int outIndex;
    int max;
    int count;
    int *dst, *array, *out;
    if (*(int *)(lbl_8055E29C + 4) <= 0) return;
    fn_80265DCC(*(void **)lbl_8055E29C, *(int *)(lbl_8055E29C + 4), 0x10, fn_8015F3EC);
    count = (int)(*(unsigned int *)(*(int *)((char *)arg0 + 0x2c) + 0x18) >> 16);
    dst = (int *)fn_801284F8(0x10, lbl_8032F4A0);
    if (!dst) return;
    array = (int *)fn_8012850C(count * 4, (int)&lbl_8055A098);
    dst[0] = (int)array;
    dst[2] = count;
    dst[1] = 0;
    dst[3] = (int)array;
    *(int *)&lbl_8055E2A0 = (int)dst;
    if (count <= 0) return;
    for (i = 0; i < count; i++) {
        index = 0;
        offset = 0;
        max = *(int *)(lbl_8055E29C + 4) - 1;
        do {
            offset += 0x10;
            index++;
            if (index >= max) break;
        } while (*(unsigned short *)((char *)*(int *)lbl_8055E29C + offset) < i);
        max = *(int *)(lbl_8055E29C + 4) - 1;
        if (index == max && *(unsigned short *)((char *)*(int *)lbl_8055E29C + offset) < i) {
            src = (int *)*(int *)lbl_8055E29C;
            out = *(int **)&lbl_8055E2A0;
            outIndex = out[1];
            out[1] = outIndex + 1;
            *(int *)(out[0] + 4 * outIndex) = (int)src;
        } else {
            src = (int *)((char *)*(int *)lbl_8055E29C + offset);
            out = *(int **)&lbl_8055E2A0;
            outIndex = out[1];
            out[1] = outIndex + 1;
            *(int *)(out[0] + 4 * outIndex) = (int)src;
        }
    }
}

#pragma pop
void fn_8015F554(void) {
}

void fn_8015F558(void) {
    fn_8015F584(&lbl_8055E2A0);
    fn_8015F5F4(&lbl_8055E29C);
}

void fn_8015F584(int *arg0) { void *p=*(void **)arg0; if(p) { if(p) { fn_80128670(((s32 *)p)[3]); if(p) { ((s32*)p)[0]=0; ((s32*)p)[1]=0; ((s32*)p)[2]=0; } fn_80128668(p); } *(void **)arg0=0; } }

void fn_8015F5F4(int *arg0) { void *p=*(void **)arg0; if(p) { if(p) { s32 x=((s32*)p)[3]; if(x) fn_80128670(x-0x10); if(p) { ((s32*)p)[0]=0; ((s32*)p)[1]=0; ((s32*)p)[2]=0; } fn_80128668(p); } *(void **)arg0=0; } }

extern void *fn_80178C9C(void);
extern void **fn_80131810(const char *);
extern void fn_80131818(void **);
extern int fn_8015F148(void **, int);
extern int fn_8015ED90(void **);
extern void fn_8015F320(void **, int, void *);
extern void fn_8015EF84(void **);
extern void fn_8015EE14(void **, void *);
extern void fn_8015F3FC(void *);
extern void *fn_8002F37C(void *, void (*)(void *), void (*)(void *), int, int);
extern void fn_8015F79C(void);
extern char lbl_8032F4AC[], lbl_8032F4B8[];
__declspec(section ".sdata") extern char lbl_8055A0A0[];
extern int lbl_8055A098, lbl_8055E29C;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8015F670(void **arg0, s32 arg1) {
    struct Resource {
        virtual void **get(const char *);
    };
    void **object;
    void *context;
    void **resource;
    s32 count;
    void *record;
    void *array;
    context = fn_80178C9C();
    resource = fn_80131810(lbl_8032F4AC);
    if (resource != 0) {
        object = ((Resource *)resource)->get(lbl_8055A0A0);
    } else {
        object = 0;
    }
    count = fn_8015F148(arg0, arg1);
    count += fn_8015ED90(object);
    if (count > 0) {
        register const char *recordName = lbl_8032F4B8;
        record = fn_801284F8(0x10, recordName);
        if (record != 0) {
            register int arraySize = (count << 4) + 0x10;
            register int arrayTag = (int)&lbl_8055A098;
            array = fn_8012850C(arraySize, arrayTag);
            array = fn_8002F37C(array, (void (*)(void *))fn_8015F79C, 0, 0x10, count);
            *(void **)record = array;
            *(s32 *)((char *)record + 8) = count;
            *(s32 *)((char *)record + 4) = 0;
            *(void **)((char *)record + 0xC) = array;
        }
        lbl_8055E29C = (s32)record;
        fn_8015F320(arg0, arg1, context);
        fn_8015EF84(object);
        fn_8015EE14(object, context);
        fn_8015F3FC(context);
    }
    if (resource != 0) {
        fn_80131818(resource);
    }
}
#pragma cplusplus reset
#pragma pop

void fn_8015F79C(void) {
}



extern f32 lbl_805617D4, lbl_805617E4, lbl_805617E8, lbl_805617EC, lbl_805617F0;
extern f32 lbl_8056182C;
extern f64 fn_8002F234(f32, f32, f32);
f32 PSVECDotProduct(void *, void *);
#pragma scheduling invalid_target
s32 fn_8015F7A0(s32 arg0, void *arg1, void *arg2) {
    register f32 scale = (f32)arg0 * lbl_805617E4;
    register f32 t = (PSVECDotProduct(arg1, arg2) - lbl_805617EC) / lbl_805617F0;
    register f32 clamp = lbl_805617E8;
    if (clamp >= t) clamp = t;
    if (clamp <= lbl_805617D4) clamp = lbl_805617D4;
    return (s32)(-scale + clamp * (scale - -scale));
}
#pragma scheduling on
extern f32 lbl_8055E2A4;
extern f32 lbl_805617DC;
extern f32 lbl_80561808;
extern f64 lbl_805617F8;
__declspec(section ".sdata") extern f64 lbl_805617F8;
s32 fn_8015F848(f32 *arg0, f32 farg0) {
    f32 *var_r5;
    f32 *temp_r7;
    f32 *var_r6;
    f32 temp_f2;
    f32 temp_f6;
    f32 threshold;
    f32 spacing;
    f32 multiplier;
    f64 magic;
    s32 temp_r0;
    s32 var_ctr;
    s32 var_r9;
    s32 var_r8;

    var_r5 = arg0;
    var_r8 = -1;
    var_r9 = 0;
    threshold = lbl_8055E2A4;
    spacing = lbl_80561808;
    multiplier = lbl_805617DC;
    magic = *(volatile f64 *)&lbl_805617F8;
    do {
        temp_f6 = *var_r5;
        if (temp_f6 < farg0) {
            if (var_r8 > 0) {
                temp_r0 = var_r8 * 8;
                temp_r7 = (f32 *)((char *)arg0 + temp_r0);
                if ((f32)fabs((double)(*temp_r7 - temp_f6)) < farg0 * multiplier &&
                    threshold * (f32)((double)(var_r9 - var_r8) - magic) < spacing) {
                    var_ctr = (var_r9 + 1) - var_r8;
                    var_r6 = temp_r7;
                    if (var_r8 <= var_r9) {
                        do {
                            temp_f2 = *var_r5;
                            temp_f6 = *temp_r7;
                            if (temp_f6 < temp_f2)
                                temp_f6 = temp_f2;
                            *var_r6 = temp_f6;
                            var_r6 = (f32 *)((char *)var_r6 + 8);
                            temp_r7 = (f32 *)((char *)temp_r7 + 8);
                        } while (--var_ctr != 0);
                    }
                }
            }
            var_r8 = var_r9;
        }
        var_r9 += 1;
        var_r5 = (f32 *)((char *)var_r5 + 8);
    } while (var_r9 < 0x40);
    return ((u32)var_r8 >> 31) ^ 1;
}

extern long lbl_8055E2A8;
extern float lbl_8056180C;
void fn_8015F92C(float *arg0, float farg0) {
    s32 v = lbl_8055E2A8;
    register s32 i = 0;
    s32 count = (((s32)(v + ((u32)v >> 31))) >> 1) + 1;
    float value = farg0;
    float temp;
    register float *base = arg0;
    for (; i < count; i++) {
        temp = base[64];
        if (value < temp) value = temp;
        temp = arg0[(32 - i) * 2];
        if (value < temp) value = temp;
        base += 2;
    }
    {
        float scale = lbl_8056180C;
        float delta;
        float result;
        float current0, current1, current2, current3;
        float current4, current5, current6, current7;
        for (i = 0; i < 8; i++) {
            current0 = arg0[0]; delta = current0 - value; result = delta * scale; arg0[0] = current0 + result;
            current1 = arg0[2]; delta = current1 - value; result = delta * scale; arg0[2] = current1 + result;
            current2 = arg0[4]; delta = current2 - value; result = delta * scale; arg0[4] = current2 + result;
            current3 = arg0[6]; delta = current3 - value; result = delta * scale; arg0[6] = current3 + result;
            current4 = arg0[8]; delta = current4 - value; result = delta * scale; arg0[8] = current4 + result;
            current5 = arg0[10]; delta = current5 - value; result = delta * scale; arg0[10] = current5 + result;
            current6 = arg0[12]; delta = current6 - value; result = delta * scale; arg0[12] = current6 + result;
            current7 = arg0[14]; delta = current7 - value; result = delta * scale; arg0[14] = current7 + result;
            arg0 += 16;
        }
    }
}

#pragma scheduling invalid_target
s32 fn_8015FA44(void *arg0, s32 arg1, f32 arg2) {
    s32 result = -1;
    s32 i;
    if (((s32 *)((char *)arg0 + arg1 * 8))[1] != 1) {
        for (i = arg1 + 1; i < 0x40; i++) {
            void *p = (char *)arg0 + i * 8;
            if (*(f32 *)p > arg2) {
                result = i;
                break;
            }
            if (((s32 *)p)[1] == 1) break;
            if (((s32 *)p)[1] == 2) result = i;
        }
    }
    return result;
}
#pragma scheduling on
s32 fn_8015FAB8(s32 *arg0, s32 arg1, f32 arg2) {
    s32 result = -1;
    s32 i;
    if (arg0[arg1 * 2 + 1] != 2) {
        for (i = arg1 - 1; i >= 0; i--) {
            if (*(f32 *)&arg0[i * 2] > arg2) { result = i; break; }
            if (arg0[i * 2 + 1] == 2) break;
            if (arg0[i * 2 + 1] == 1) result = i;
        }
    }
    return result;
}
#pragma scheduling reset
extern f32 lbl_80561810;
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8015FB28(void *arg0, void *arg1) {
    volatile u32 *dst = (volatile u32 *)arg0;
    volatile u32 *src = (volatile u32 *)arg1;
    volatile f32 *dstFloat = (volatile f32 *)arg0;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word28;
    u32 word24;
    u32 word2C;
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    f32 velocityX;
    f32 velocityY;
    f32 velocityZ;
    f32 scale;
    f32 scaledX;
    f32 scaledY;
    f32 scaledZ;
    f32 positionX;
    f32 positionY;
    f32 positionZ;
    f32 newX;
    f32 newY;
    f32 newZ;

    word18 = src[6];
    word1C = src[7];
    dst[6] = word18;
    word20 = src[8];
    dst[7] = word1C;
    word28 = src[10];
    dst[8] = word20;
    word24 = src[9];
    word2C = src[11];
    dst[9] = word24;
    velocityX = dstFloat[6];
    scale = lbl_80561810;
    dst[10] = word28;
    velocityZ = dstFloat[8];
    scaledX = velocityX * scale;
    velocityY = dstFloat[7];
    dst[11] = word2C;
    scaledZ = velocityZ * scale;
    scaledY = velocityY * scale;
    positionY = dstFloat[10];
    positionX = dstFloat[9];
    newY = positionY + scaledY;
    positionZ = dstFloat[11];
    newX = positionX + scaledX;
    word0 = src[0];
    newZ = positionZ + scaledZ;
    word4 = src[1];
    word8 = src[2];
    wordC = src[3];
    word10 = src[4];
    word14 = src[5];
    dst[0] = word0;
    dst[1] = word4;
    dst[2] = word8;
    dst[3] = wordC;
    dst[4] = word10;
    dst[5] = word14;
    dstFloat[9] = newX;
    dstFloat[10] = newY;
    dstFloat[11] = newZ;
}
#pragma processor reset
#pragma use_lmw_stmw reset
extern f32 lbl_805617D4;
void fn_80160230(void *arg0, void *arg1) {
    register f32 c, b, a;
    a = *(f32 *)((u8 *)arg1 + 0);
    b = lbl_805617D4;
    c = *(f32 *)((u8 *)arg1 + 4);
    *(f32 *)((u8 *)arg0 + 0) = a;
    *(f32 *)((u8 *)arg0 + 4) = b;
    *(f32 *)((u8 *)arg0 + 8) = c;
}

s32 fn_8016024C(s32 arg0, s32 arg1) {
    if (arg1 < arg0) {
        return arg1;
    }
    return arg0;
}

void fn_8016025C(void *arg0, f32 farg0, f32 farg1) {
    *(f32 *)((u8 *)arg0 + 0) = farg0;
    *(f32 *)((u8 *)arg0 + 4) = farg1;
}

int fn_80160268(int arg0) {
    int temp_r4;
    temp_r4 = arg0 >> 31;
    return (temp_r4 ^ arg0) - temp_r4;
}

void fn_80160278(void) {
}

void fn_8016027C(void *arg0, f32 farg0, f32 farg1) {
    *(f32 *)((u8 *)arg0 + 0) = farg0;
    *(f32 *)((u8 *)arg0 + 4) = farg1;
}

void fn_80160288(void *arg0, void *arg1) {
    struct Pair { u32 first; u32 second; };
    *(struct Pair *)arg0 = *(struct Pair *)arg1;
}

f32 fn_8016029C(f32 *arg0, f32 *arg1) {
    f32 a = arg1[0];
    f32 b = arg1[2];
    arg0[0] = a;
    arg0[1] = b;
    return a;
}

void fn_801602B0(void) {
}

s32 fn_801602B4(s32 arg0) {
    return arg0 + 0x3C;
}

s32 fn_801602BC(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

s32 fn_801602CC(void *arg0) {
    return ((s32 *)arg0)[1];
}

extern float fn_80160588(void *, void *, void *);
extern float fn_801605C8(void *, void *, void *);
extern float lbl_8055E2A4, lbl_805617D4, lbl_805617DC, lbl_805617E8, lbl_80561800, lbl_80561828;
void fn_801602D4(struct Hit *arg0, void *arg1, void *arg2, float arg3) {
    float dist, pos, height, low, high, t;
    s16 type;
    int first, last, i;
    dist = fn_80160588(arg2, (char *)arg1 + 4, (char *)arg2 + 0x10) - *(float *)((char *)arg1 + 0xC);
    if (dist > lbl_805617D4 && dist < arg3) {
        pos = fn_801605C8(arg2, (char *)arg1 + 4, (char *)arg2 + 0x10);
        height = *(float *)((char *)arg1 + 0xC);
        low = -lbl_80561800 * lbl_805617DC;
        if (pos + height > low) {
            high = lbl_80561800 * lbl_805617DC;
            if (pos - height < high) {
                type = *(s16 *)((char *)arg1 + 2);
                first = last = 0;
                switch (type) {
                case 0:
                    t = (pos - height - low) / (high - low);
                    if (t < lbl_805617E8) t = lbl_805617E8;
                    if (t > lbl_805617D4) t = lbl_805617D4;
                    first = (int)(lbl_805617D4 + t * lbl_80561828);
                    t = (lbl_8055E2A4 + pos + height - low) / (high - low);
                    if (t < lbl_805617E8) t = lbl_805617E8;
                    if (t > lbl_805617D4) t = lbl_805617D4;
                    last = (int)(lbl_805617D4 + t * lbl_80561828);
                    break;
                case 2:
                    t = (pos + lbl_8055E2A4 - low) / (high - low);
                    if (t < lbl_805617E8) t = lbl_805617E8;
                    if (t > lbl_805617D4) t = lbl_805617D4;
                    last = (int)(lbl_805617D4 + t * lbl_80561828);
                    break;
                case 1:
                    t = (pos - low) / (high - low);
                    if (t < lbl_805617E8) t = lbl_805617E8;
                    if (t > lbl_805617D4) t = lbl_805617D4;
                    first = (int)(lbl_805617D4 + t * lbl_80561828);
                    last = 0x40;
                    break;
                default:
                    break;
                }
                for (i = first; i < last; i++) {
                    if (dist < arg0[i].x) {
                        arg0[i].x = dist;
                        arg0[i].y = type;
                    }
                }
            }
        }
    }
}

#pragma scheduling invalid_target
f32 fn_801605C8(void *arg0, void *arg1, void *arg2) {
    f32 spC;
    f32 sp8;
    f32 temp_f2;
    f32 temp_f3;
    f32 result1;
    f32 result2;

    temp_f3 = *(f32 *)arg1 - *(f32 *)arg2;
    temp_f2 = *(f32 *)((u8 *)arg1 + 4) - *(f32 *)((u8 *)arg2 + 4);
    result1 = temp_f3 * *(f32 *)((u8 *)arg0 + 4);
    *(volatile f32 *)&sp8 = temp_f3;
    result2 = temp_f2 * -*(f32 *)arg0;
    *(volatile f32 *)&spC = temp_f2;
    return result1 + result2;
}

#pragma scheduling invalid_target
void *fn_8016060C(void *arg0, void *arg1) {
    volatile f32 *dst = (volatile f32 *)arg0;
    volatile f32 *src = (volatile f32 *)arg1;
    f32 x = src[6];
    f32 y = src[8];
    register f32 magnitude;
    register f32 limit;
    f32 clamped;
    f32 inputX;
    f32 outputX;
    f32 inputY;
    f32 outputY;
    f32 normalizedX;
    f32 normalizedY;
    register f32 scale;

    dst[0] = x;
    dst[1] = y;
    magnitude = (f32)fn_8002F234(x * x + y * y, y, x);
    limit = lbl_8056182C;
    if (limit > magnitude)
        clamped = limit;
    else
        clamped = magnitude;
    inputX = src[9];
    scale = lbl_805617E8 / clamped;
    outputX = dst[0];
    inputY = src[11];
    outputY = dst[1];
    dst[4] = inputX;
    normalizedX = outputX * scale;
    dst[5] = inputY;
    normalizedY = outputY * scale;
    dst[0] = normalizedX;
    dst[1] = normalizedY;
    dst[2] = normalizedY;
    dst[3] = -normalizedX;
    return arg0;
}
#pragma scheduling on
void fn_801606B8(void) {
}

