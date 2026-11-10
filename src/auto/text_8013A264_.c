// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;

typedef struct Node604 {
    f32 lo;
    f32 hi;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    struct Node604 *next;
} Node604;

typedef struct AIConfig {
    Node604 *head;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} AIConfig;

#pragma push
#pragma cplusplus on
struct Entry {
    virtual const char *GetName();
    virtual void _0C();
    virtual void _10();
    virtual void _14();
    virtual void _18();
    virtual void _1C();
    virtual void _20();
    virtual f32 GetFloat(const void *);
    virtual f32 GetFloatDef(const void *, f32);
};

struct Container {
    virtual void _00();
    virtual void _04();
    virtual void _08();
    virtual void _0C();
    virtual void _10();
    virtual void _14();
    virtual void _18();
    virtual void _1C();
    virtual void _20();
    virtual void _24();
    virtual void _28();
    virtual void _2C();
    virtual void _30();
    virtual void _34();
    virtual void _38();
    virtual void _3C();
    virtual void _40();
    virtual void _44();
    virtual void _48();
    virtual void _4C();
    virtual void _50();
    virtual void _54();
    virtual Entry *GetEntry(int);
};
#pragma pop

void *fn_801284F8(unsigned int, const void *);
void *fn_80128668();
int stricmp(const char *, const char *);
void fn_802E30C8(const char *, ...);
extern f32 lbl_8032C118[];
extern f32 lbl_80559C60;
extern char lbl_80559C68;
extern char lbl_80559C70;
extern char lbl_80559C78;
extern char lbl_80559C80;
extern char lbl_80559C88;
extern char lbl_80559C90;
extern char lbl_80559C94;
extern f32 lbl_80561418, lbl_8056141C, lbl_80561420;
extern f32 lbl_80561424, lbl_80561428, lbl_8056142C;
f32 fn_80134B58(f32 *, f32);

#pragma push
#pragma scheduling invalid_target
void *fn_8013A264(void *arg0) {
    f32 *p = lbl_8032C118;
    *(f32 *)((u8 *)arg0 + 0xC) = fn_80134B58(p, *(volatile f32 *)&lbl_80561418);
    *(f32 *)((u8 *)arg0 + 8) = fn_80134B58(p + 4, *(volatile f32 *)&lbl_80561418);
    *(f32 *)((u8 *)arg0 + 0x10) = fn_80134B58(p + 8, *(volatile f32 *)&lbl_80561418);
    *(f32 *)((u8 *)arg0 + 0x18) = fn_80134B58(&lbl_80559C60, *(volatile f32 *)&lbl_8056141C);
    *(f32 *)((u8 *)arg0 + 0x14) = lbl_80561418;
    *(f32 *)((u8 *)arg0 + 0x1C) = lbl_80561418;
    *(f32 *)((u8 *)arg0 + 4) = lbl_80561420;
    *(s32 *)arg0 = 0;
    return arg0;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8013A2FC(AIConfig *config, struct Container *container, int i) {
    const char *base = (const char *)lbl_8032C118;
    if (container != 0) {
        Node604 *node;
        f32 step;
        f32 min;
        f32 max;
        struct Entry *entry;

        max = lbl_80561424;
        i = 0;
        min = lbl_80561428;
        step = lbl_8056142C;

        for (; (entry = container->GetEntry(i)) != 0; i++) {
            if (stricmp(entry->GetName(), base + 0x34) == 0) {
                node = (Node604 *)fn_801284F8(0x28, base + 0x40);
                node->lo = entry->GetFloat(&lbl_80559C68);
                node->hi = entry->GetFloat(&lbl_80559C70);
                node->f8 = entry->GetFloatDef(&lbl_80559C78, config->f4);
                node->fC = entry->GetFloatDef(&lbl_80559C80, config->f8);
                node->f10 = entry->GetFloatDef(&lbl_80559C88, config->fC);
                node->f14 = entry->GetFloatDef(base + 0x20, config->f10);
                node->f18 = entry->GetFloatDef(base + 0x4C, config->f14);
                node->f1C = entry->GetFloatDef(&lbl_80559C60, config->f18);
                node->f20 = entry->GetFloatDef(base + 0x58, config->f1C);
                node->next = config->head;
                config->head = node;

                if (node->lo > node->hi) {
                    Node604 *copy = (Node604 *)fn_801284F8(0x28, base + 0x40);
                    if (copy != 0) {
                        *copy = *node;
                    }
                    node->hi = max;
                    copy->lo = min;
                    copy->f8 = step;
                    copy->next = config->head;
                    config->head = copy;
                }
            }
        }

        fn_802E30C8(base + 0x68, i, (i != 1) ? &lbl_80559C90 : &lbl_80559C94);
    }
}
#pragma cplusplus reset
#pragma pop

void **fn_8013A598(void **arg0, s32 arg1) {
    if (arg0 != 0) {
        while (*arg0 != 0) {
            *arg0 = *(void **)((u8 *)*arg0 + 0x24);
            fn_80128668();
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8013A604(void **arg0, f32 value) {
    Node604 *node = (Node604 *)*arg0;
    s32 found;
    while (node != 0) {
        found = 0;
        if (value >= node->lo && value <= node->hi) found = 1;
        if (found) return (u8 *)node + 8;
        node = node->next;
    }
    return (u8 *)arg0 + 4;
}
