// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B54;
void fn_801DA198(int, float);
extern void *fn_80128668(void *);
extern void fn_80128670(void *);
extern int lbl_80339288[];
extern float fn_801DA6B8(int);
extern void *fn_801284F8(int, void *);
extern void fn_801D0DDC(void *);
extern int lbl_803381C0[];
extern int lbl_80339258[];
extern void *lbl_8055AD98;
extern void *lbl_8055E984;

#pragma scheduling off
void fn_801DA6EC(void) {
    void *obj;
    obj = fn_801284F8(0x580C, lbl_8055AD98);
    if (obj != 0) {
        *(void **)obj = lbl_803381C0;
        fn_801D0DDC(obj);
        *(void **)obj = lbl_80339258;
        *(void **)((char *)obj + 4) = (char *)lbl_80339258 + 0x1C;
        lbl_8055E984 = obj;
        *(int *)((char *)obj + 0x5808) = 0;
    }
}

extern int fn_801D9FC4(char **, const char *);
extern void *fn_8012850C(int, void *);
extern int strcmp(const char *, const char *);
extern char lbl_8055ADB0[];
extern char lbl_80339240[];
extern char lbl_8033924C[];
void *fn_801DA8C8(const char *arg0, const char *arg1) {
    void *space;
    const char *name;
    const char *text;
    char *stack[512];
    char *entry;
    char *result;
    int count;
    int offset;
    int i;
    int matchAll;

    space = lbl_8055E984;
    name = arg0;
    text = arg1;
    offset = 0;
    count = 0;
    result = 0;
    matchAll = strcmp(name, lbl_8055ADB0) == 0;
    entry = (char *)space + 8;
    i = 0;
    while (i < *(int *)((char *)space + 0x5808)) {
        if (matchAll || strcmp(entry, name) == 0) {
            if (fn_801D9FC4((char **)*(void **)((char *)entry + 0x28), text) != 0) {
                *(char **)((char *)stack + offset) = entry;
                count += 1;
                offset += 4;
            }
        }
        entry += 0x2C;
        i += 1;
    }
    if (count > 0) {
        char *dst;
        int len;

        result = fn_801284F8(0x20, lbl_80339240);
        if (result != 0) {
            signed char c;

            *(void **)result = lbl_80339288;
            *(int *)((char *)result + 0xC) = count;
            dst = (char *)result + 0x10;
            len = 0x10;
            for (;;) {
                c = *text;
                text += 1;
                *dst = c;
                dst += 1;
                if (c == 0)
                    break;
                if (--len <= 0) {
                    *(dst - 1) = 0;
                    break;
                }
            }
            *(int *)((char *)result + 8) = 0;
            *(void **)((char *)result + 4) = (void *)fn_8012850C(*(int *)((char *)result + 0xC) * 4, lbl_8033924C);
            for (i = 0; i < count; i++) {
                void **arr;
                int pos;

                arr = *(void ***)((char *)result + 4);
                pos = *(int *)((char *)result + 8);
                *(void **)((char *)arr + pos * 4) = stack[i];
                pos += 1;
                *(int *)((char *)result + 8) = pos;
            }
        }
    }
    return result;
}

#pragma scheduling on
#pragma push
#pragma use_lmw_stmw off
#pragma pop
void *__dt__14CollisionSpaceFv_801DAB70(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80339288;
        fn_80128670(*(void **)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

float fn_801DABD4(void *arg0) {
    float value;
    float max = lbl_80562B54;
    int offset = 0;
    int i = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        value = fn_801DA6B8(*(int *)((char *)(*(void ***)((char *)arg0 + 4))[offset / 4] + 0x28));
        if (max > value) {
        } else {
            max = value;
        }
        offset += 4;
        i += 1;
    }
    return max;
}

float fn_801DAC5C(void *arg0) {
    float value;
    float max;
    int count;
    int offset;
    int i;
    void **items;
    count = *(int *)((char *)arg0 + 8);
    offset = 0;
    max = lbl_80562B54;
    if (count > 0) {
        items = *(void ***)((char *)arg0 + 4);
        for (i = 0; i < count; i++) {
            value = *(float *)((char *)(*(void **)((char *)items[offset / 4] + 0x28)) + 0xC);
            if (max > value) {
            } else {
                max = value;
            }
            offset += 4;
        }
    }
    return max;
}

extern void fn_801DA064(int, void *);
extern void fn_801DA198(int, float);
extern void fn_802E30C8(char *, int, void *);
extern char lbl_803392F0[];
void fn_801DACA0(void *arg0, float arg1) {
    float value;
    int i;
    int offset;
    void *entry;
    void *context;
    value = lbl_80562B54;
    if (arg1 < value)
        value = (*(float (**)(void *))(*(char ***)arg0 + 3))(arg0);
    context = (char *)arg0 + 0x10;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        entry = *(void **)((char *)*(void ***)((char *)arg0 + 4) + offset);
        if (*((unsigned char *)entry + 0x18) != 0)
            fn_802E30C8(lbl_803392F0, i, context);
        *((unsigned char *)entry + 0x18) = 1;
        *((float *)((char *)entry + 0x1C)) = arg1;
        fn_801DA064(*(int *)((char *)entry + 0x28), context);
        fn_801DA198(*(int *)((char *)entry + 0x28), value);
        offset += 4;
        i++;
    }
}

#pragma scheduling off
int fn_801DAD7C(void *arg0) {
    int count;
    int index;
    void **items;
    count = *(int *)((char *)arg0 + 8);
    index = 0;
    items = *(void ***)((char *)arg0 + 4);
    if (count <= 0)
        return 1;
    while (count-- > 0) {
        if (*((unsigned char *)items[index] + 0x18) != 0)
            return 0;
        index++;
    }
    return 1;
}
#pragma scheduling on
void fn_801DADBC(void *arg0) {
    int i = 0;
    int offset = 0;
    void **items;
    while (i < *(int *)((char *)arg0 + 8)) {
        items = *(void ***)((char *)arg0 + 4);
        fn_801DA198(*(int *)((char *)items[offset / 4] + 0x28), lbl_80562B54);
        offset += 4;
        i++;
    }
}
#pragma scheduling off
extern void fn_801D9F44(void *, int);
extern void fn_801D9F24(void *);
extern void fn_801D0DFC(void *);
#pragma scheduling off
void *fn_801DAE28(void *arg0, int arg1) {
    unsigned char *entry;
    int i;
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 4) = (char *)lbl_80339258 + 0x1C;
        *(void **)arg0 = lbl_80339258;
        entry = (unsigned char *)arg0 + 8;
        i = 0;
        lbl_8055E984 = 0;
        while (i < *(int *)((char *)arg0 + 0x5808)) {
            fn_801D9F44(*(void **)(entry + 0x28), 1);
            fn_801D9F24(*(void **)(entry + 0x24));
            entry += 0x2C;
            i++;
        }
        if (arg0 != 0) {
            *(void **)arg0 = lbl_803381C0;
            fn_801D0DFC(arg0);
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
void fn_801DAEF4(void) {

}

void fn_801DAEF8(void) {

}

void fn_801DAEFC(void *arg0) {
    unsigned char *entry;
    int i;
    entry = (unsigned char *)arg0 + 8;
    i = 0;
    for (; i < *(int *)((char *)arg0 + 0x5808); i++) {
        unsigned char flag = entry[0x19];
        fn_801DA198(*(int *)(entry + 0x28), (entry[0x18] = flag, lbl_80562B54));
        entry += 0x2C;
    }
}

extern float lbl_80562B58, lbl_80562B5C;
extern unsigned char lbl_8055E980;
extern char lbl_8055ADB4[], lbl_80339318[];
extern void fn_801DA0EC(int, float);
extern int fn_801DA294(int, void *, float *, float *);
extern void fn_8017CFFC(int, void *, float *, float *);
extern float fn_801EA0E8(float, float);
extern int fn_801DA648(int);
extern int fn_801DA688(int);
void fn_801DAF68(void *arg0) {
    unsigned char *entry = (unsigned char *)arg0 + 8;
    int i;
    for (i = 0; i < *(int *)((char *)arg0 + 0x5808); i++, entry += 0x2C) {
        if (entry[0x18] == 0 && entry[0x10] == 0) continue;
        if (entry[0x18]) fn_801DA0EC(*(int *)(entry+0x28), lbl_80562B58 * *(float *)(entry+0x1C));
        {
            float a,b,c,d,e,f; unsigned char scratch[0x30];
            if (fn_801DA294(*(int *)(entry+0x28), scratch, &a, &d)) {
                a*=lbl_80562B5C; b*=lbl_80562B5C; c*=lbl_80562B5C;
                d*=lbl_80562B5C; e*=lbl_80562B5C; f*=lbl_80562B5C;
                if(entry[0x10]) *(float *)(scratch+0x28)=*(float *)(entry+0x14)+fn_801EA0E8(*(float *)(scratch+0x24),*(float *)(scratch+0x2C));
                fn_8017CFFC(*(int *)(entry+0x20),scratch,&a,&d);
            } else if(!lbl_8055E980) {
                lbl_8055E980=1; fn_802E30C8(lbl_8055ADB4,0,lbl_80339318);
            }
        }
        if (*(float *)(entry+0x1C) > lbl_80562B54) {
            if(fn_801DA688(*(int *)(entry+0x28)) && !entry[0x19]) entry[0x18]=0;
        } else if(fn_801DA648(*(int *)(entry+0x28))) {
            if(entry[0x19]) fn_801DA198(*(int *)(entry+0x28),lbl_80562B54); else entry[0x18]=0;
        }
    }
}

