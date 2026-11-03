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

struct EntryVtable {
    void *_00;
    void *_04;
    const char *(*GetName)(void *);
    void *_0C;
    void *_10;
    void *_14;
    void *_18;
    void *_1C;
    void *_20;
    f32 (*GetFloat)(void *, const void *);
    f32 (*GetFloatDef)(void *, const void *, f32);
};

struct Entry {
    struct EntryVtable *vtable;
};

struct ContainerVtable {
    void *_pad[24];
    struct Entry *(*GetEntry)(void *, int);
};

struct Container {
    struct ContainerVtable *vtable;
};

void *fn_801284F8(unsigned int, const void *);
void *fn_80128668();
int stricmp(const char *, const char *);
void fn_802E30C8(const char *, ...);
extern f32 lbl_8032C118[];
extern f32 lbl_80559C60;
extern char lbl_80559C68[];
extern char lbl_80559C70[];
extern char lbl_80559C78[];
extern char lbl_80559C80[];
extern char lbl_80559C88[];
extern char lbl_80559C90[];
extern char lbl_80559C94[];
extern f32 lbl_80561418, lbl_8056141C, lbl_80561420;
extern f32 lbl_80561424, lbl_80561428, lbl_8056142C;
f32 fn_80134B58(f32 *, f32);

void *fn_8013A264(void *arg0) {
    f32 *p = lbl_8032C118;
    *(f32 *)((u8 *)arg0 + 0xC) = fn_80134B58(p, lbl_80561418);
    *(f32 *)((u8 *)arg0 + 8) = fn_80134B58(p + 4, lbl_80561418);
    *(f32 *)((u8 *)arg0 + 0x10) = fn_80134B58(p + 8, lbl_80561418);
    *(f32 *)((u8 *)arg0 + 0x18) = fn_80134B58(&lbl_80559C60, lbl_8056141C);
    *(f32 *)((u8 *)arg0 + 0x14) = lbl_80561418;
    *(f32 *)((u8 *)arg0 + 0x1C) = lbl_80561418;
    *(f32 *)((u8 *)arg0 + 4) = lbl_80561420;
    *(s32 *)arg0 = 0;
    return arg0;
}

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
