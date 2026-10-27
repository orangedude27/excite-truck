// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
extern float lbl_80562B2C;
extern float lbl_80562B28;
extern float lbl_80562B30;
extern int lbl_8055E960;
extern void fn_802C7040(int);
extern void fn_802C9900(float);
extern void fn_802C9904(void);
extern unsigned int lbl_8055AD90;
extern const char lbl_803391EC[];
extern int strcmp(const char *, const char *);
extern void *fn_801284F8(int, const char *);
extern int fn_801D94DC(void *, void *, const char *, int);

#pragma cplusplus on
struct DtbManager801D9394 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void *getAt(int);
};
struct DtbItem801D9394 {
    virtual const char *getName();
    virtual void f1();
    virtual void f2();
    virtual const char *getString(const char *);
};
#pragma cplusplus reset
extern unsigned char lbl_8055E968;
extern void *lbl_8055E96C;
extern float lbl_80562B2C;
extern void fn_80178DBC(int, float);
extern void fn_801D9AB8(void *, float);
extern void fn_801D611C(s32);
extern void fn_801D77E8(s32);
extern void fn_801D77EC(s32);
extern void fn_801D7874(s32);

extern void fn_80128668(void*);
void* fn_801D9090(void* arg0, s32 arg1) {
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

void fn_801D90E8(s32 arg0) {
    fn_801D611C(arg0 - 4);
}

void fn_801D90F0(s32 arg0) {
    fn_801D77E8(arg0 - 4);
}

void fn_801D90F8(s32 arg0) {
    fn_801D77EC(arg0 - 4);
}

void fn_801D9100(s32 arg0) {
    fn_801D7874(arg0 - 4);
}

void fn_801D9108(int arg0) { fn_801D8938(arg0 - 4); }

void fn_801D9110(int arg0) { fn_801D893C(arg0 - 4); }

void fn_801D9118(int arg0) { fn_801D89C0(arg0 - 4); }

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_801D9120(float *out, float *values, int count, float weight) {
    float value = values[count - 1];
    if (count == 1) {
        out[1] = weight * value;
        out[0] = weight * (lbl_80562B28 - value);
    } else {
        fn_801D9120(out, values, count - 1, weight * (lbl_80562B28 - value));
        fn_801D9120(out + (1 << (count - 1)), values, count - 1, weight * value);
    }
}
#pragma dont_inline off
#pragma scheduling default
void fn_801D91D8(void) {
    extern void *lbl_8055E96C;
    extern void *lbl_8055E964;
    void *node;
    void *item;
    int count;
    int i;
    void **entries;
    int found;
    for (node = lbl_8055E96C; node != 0; node = *(void **)((char *)node + 0x54)) {
        for (item = lbl_8055E964; item != 0; item = *(void **)((char *)item + 0x34)) {
            entries = *(void ***)item;
            count = *(int *)((char *)item + 4);
            found = -1;
            for (i = 0; i < count; i++) {
                if (entries[i] == node) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                int used = *(int *)((char *)node + 0x2C);
                int base = *(int *)((char *)node + 0x28);
                *(int *)((char *)node + 0x2C) = used + 1;
                *(void **)((char *)base + used * 4) = item;
            }
        }
    }
}

extern void *lbl_8055E96C;
extern void *lbl_8055E964;
extern int lbl_8055E960;
extern float lbl_80562B28;
extern int fn_802C6CF8(int);
extern int fn_801D985C(int *);
extern int fn_801D9948(int *);
extern void fn_801D9120(float *, float *, int, float);
void *fn_801D9260(int count) {
    extern void *lbl_8055E96C;
    void *node = lbl_8055E96C;
    do {
        node = *(void **)((char *)node + 0x54);
        if (node == 0)
            break;
        count--;
    } while (count >= 0);
    return node;
}

#pragma cplusplus on
extern "C" void fn_801D9394(void **head, DtbManager801D9394 *manager, const char *name, int arg3) {
    struct Node {
        char field00[0x20];
        float value;
        int field24;
        char *textPtr;
        int field2C;
        int field30;
        char field34[0x20];
        char field54[4];
    };
    float value = lbl_80562B2C;
    Node *node;
    DtbItem801D9394 *item;
    int index = 0;
    const char *text;
    int left;
    char *out;
    while ((item = (DtbItem801D9394 *)manager->getAt(index)) != 0) {
        if (strcmp(item->getName(), name) == 0) {
            node = (Node *)fn_801284F8(0x58, name);
            if (node != 0) {
                node->textPtr = (char *)node + 0x34;
                node->field30 = 8;
                node->field2C = 0;
                text = item->getString((const char *)&lbl_8055AD90);
                out = (char *)node;
                left = 0x20;
                goto copy_check;
copy_loop:
                if (--left > 0)
                    goto copy_check;
                out[-1] = 0;
                goto copy_done;
copy_check:
                {
                    unsigned char c = *text++;
                    *out++ = c;
                    if ((signed char)c != 0)
                        goto copy_loop;
                }
copy_done:
                node->field24 = 0;
                fn_801D94DC((char *)node + 0x24, item, lbl_803391EC, arg3);
                *(int *)((char *)node + 0x54) = 0;
                node->value = value;
            }
            *(void **)((char *)node + 0x54) = *head;
            *head = node;
        }
        ++index;
    }
}
#pragma cplusplus reset
extern const char lbl_803391A8[];
extern const char lbl_803391B4[];
extern float lbl_8055AD68;
extern float lbl_8055AD70;
extern int lbl_8055AD78;
extern void fn_802E317C(const char*, const char*, ...);
int fn_801D94DC(void *head, void *list, const char *name, int object) {
    int index = 0;
    void *item;
    void *found;
    void *node;
    void *obj = (void *)object;
    item = ((void *(*)(void*, int))(*(void***)list)[0x60 / 4])(list, index);
    while (item != 0) {
        const char *text = ((const char *(*)(void*))(*(void***)item)[2])(item);
        if (strcmp(text, name) == 0) {
            node = fn_801284F8(0x10, name);
            if (node != 0) {
                *(float*)((char*)node + 0) = ((float(*)(void*, const float*))(*(void***)item)[0x24 / 4])(item, &lbl_8055AD68);
                *(float*)((char*)node + 4) = ((float(*)(void*, const float*))(*(void***)item)[0x24 / 4])(item, &lbl_8055AD70);
                found = ((void*(*)(void*, const char*))(*(void***)item)[0x14 / 4])(item, lbl_803391A8);
                if (((int(*)(void*, void*))(*(void***)obj)[0x10 / 4])(obj, found) == 0)
                    fn_802E317C(lbl_803391B4, found);
                found = ((void*(*)(void*, void*))(*(void***)obj)[2])(obj, found);
                *(int*)((char*)node + 8) = ((int(*)(void*, const int*))(*(void***)found)[0x1C / 4])(found, &lbl_8055AD78);
                *(void**)((char*)node + 0xC) = 0;
            }
            *(void**)((char*)node + 0xC) = *(void**)head;
            *(void**)head = node;
        }
        index++;
        item = ((void *(*)(void*, int))(*(void***)list)[0x60 / 4])(list, index);
    }
    return 0;
}

void fn_801D9828(void) {
    fn_802C6CF8(lbl_8055E960);
    fn_801D985C((int *)&lbl_8055E96C);
    fn_801D9948((int *)&lbl_8055E964);
}

extern void fn_801D98F0(void **);
int fn_801D985C(int *arg0) {
    register s32 zero = 0;
    register void *node = *(void **)arg0;
    register void *next;

    goto check;
loop:
    next = *(void **)((char *)node + 0x54);
    fn_801D98F0((void **)((char *)node + 0x24));
    if ((char *)node + 0x28 != 0) {
        if ((char *)node + 0x28 != 0) {
            *(s32 *)((char *)node + 0x28) = zero;
            *(s32 *)((char *)node + 0x2C) = zero;
            *(s32 *)((char *)node + 0x30) = zero;
        }
    }
    fn_80128668(node);
    node = next;
check:
    if (node != 0)
        goto loop;
    *arg0 = 0;
}

void fn_801D98F0(void **arg0) {
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((char *)node + 0xC);
        fn_80128668(node);
        node = next;
    }
    *arg0 = 0;
}

int fn_801D9948(int *arg0) {
    /* Fix note: walk and release each node, clear its embedded arrays, then reset the head. */
    struct Node {
        int field0, field4, field8, fieldC, field10;
        int *items;
        int count;
        int field1C, field20, field24, field28, field2C, field30;
        struct Node *next;
    };
    register struct Node *node = (struct Node *)*arg0;
    register int *head = arg0;
    register int zero = 0;
    register int i;
    register int offset;
    while (node != 0) {
        register struct Node *next = node->next;
        if (node == 0) break;
        i = 0;
        offset = 0;
        while (i < node->count) {
            fn_802C6CF8(*(int *)((char *)node->items + offset));
            offset += 4;
            i += 1;
        }
        if ((char *)node + 0x14 != 0) {
            if ((char *)node + 0x14 != 0) {
                node->items = (int *)zero;
                node->count = zero;
                node->field1C = zero;
            }
        }
        if (node != 0) {
            if (node != 0) {
                node->field0 = zero;
                node->field4 = zero;
                node->field8 = zero;
            }
        }
        fn_80128668(node);
        node = next;
    }
    *head = zero;
}

void fn_801D9A08(void) {
    void *node = lbl_8055E96C;
    while (node != 0) {
        fn_801D9AB8(node, lbl_80562B2C);
        node = *(void **)((char *)node + 0x54);
    }
    lbl_8055E968 = 0;
}

void *fn_801D9A54(const char *arg0) {
    void *node = lbl_8055E96C;
    while (node != 0) {
        if (strcmp(arg0, (const char *)node) == 0)
            return node;
        node = *(void **)((char *)node + 0x54);
    }
    return 0;
}

#pragma scheduling off
void fn_801D9AB8(void *arg0, float weight) {
    void *node;
    float value;
    if (lbl_8055E968 != 0)
        return;
    *(float *)((char *)arg0 + 0x20) = weight;
    node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        value = *(float *)node;
        fn_80178DBC(*(int *)((char *)node + 8),
                    value + weight * (*(float *)((char *)node + 4) - value));
        node = *(void **)((char *)node + 0xC);
    }
}
#pragma scheduling on
extern unsigned char lbl_8055E968;
extern float lbl_80562B2C;
extern int strcmp(const char *, const char *);
extern void fn_80178DBC(int, float);
extern void fn_801D9AB8(void *, float);
int fn_801D9B28(void *arg0, int arg1) {
    void *node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(int *)((char *)node + 8) == arg1)
            return 1;
        node = *(void **)((char *)node + 0xC);
    }
    return 0;
}

void fn_801D9B58(void) {
    float workspace[10];
    float *sampleDest;
    float *weight;
    float threshold;
    void *markNode;
    void *node;
    void *child;
    int i;
    int offset;
    int count;

    fn_802C7040(lbl_8055E960);
    markNode = lbl_8055E96C;
    do {
        if (*(float *)((char *)markNode + 0x20) > lbl_80562B2C) {
            i = 0;
            offset = 0;
            do {
                ++i;
                child = *(void **)((char *)*(void **)((char *)markNode + 0x28) + offset);
                offset += 4;
                *(unsigned char *)((char *)child + 0x30) = 1;
            } while (i < *(int *)((char *)markNode + 0x2C));
        }
        markNode = *(void **)((char *)markNode + 0x54);
    } while (markNode != 0);

    node = lbl_8055E964;
    threshold = lbl_80562B30;
    do {
        if (*(unsigned char *)((char *)node + 0x30) != 0) {
            count = *(int *)((char *)node + 4);
            i = 0;
            offset = 0;
            sampleDest = workspace;
            do {
                ++i;
                child = *(void **)((char *)*(void **)node + offset);
                offset += 4;
                *sampleDest++ = *(float *)((char *)child + 0x20);
            } while (i < count);

            fn_801D9120(workspace + 2, workspace, count, lbl_80562B28);
            if (threshold > workspace[2])
                fn_802C9900(threshold);
            else
                fn_802C9900(workspace[2]);

            fn_802C7040(*(int *)*(void **)((char *)node + 0x14));
            count = *(int *)((char *)node + 0x18);
            i = 1;
            offset = 4;
            weight = workspace + 3;
            while (i < count) {
                fn_802C9900(*weight++);
                fn_802C7040(*(int *)((char *)*(void **)((char *)node + 0x14) + offset));
                offset += 4;
                ++i;
            }
            *(unsigned char *)((char *)node + 0x30) = 0;
        }
        node = *(void **)((char *)node + 0x34);
    } while (node != 0);
    fn_802C9904();
}

