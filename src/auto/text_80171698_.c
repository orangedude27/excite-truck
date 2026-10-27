#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];
extern void fn_80128658(void *);
extern void fn_80128668(void *);
extern void fn_801777D0(void *);
extern void __dt__Q210JASDrumSet5TPercFv(void *, int);
extern char lbl_80330ED8[];
void *fn_801717B4(void *arg0, int arg1) {
    struct Local {
        void *field_00;
        void *field_04;
        unsigned char *field_08;
        int field_0C;
        int field_10;
        char pad[0xA00];
    };
    struct Local *obj = (struct Local *)arg0;
    int i;
    int offset;
    unsigned char *item;
    int zero;

    if (arg0 != 0) {
        obj->field_00 = lbl_80330ED8;
        obj->field_04 = lbl_80330ED8 + 0x10;
        if (arg0 != 0) {
            fn_801777D0(&obj->field_04);
            i = 0;
            offset = 0;
            zero = 0;
            while (i < obj->field_0C) {
                item = obj->field_08 + offset;
                fn_80128658(*(void **)(item + 0x18));
                *(void **)(item + 0x18) = (void *)zero;
                offset += 0x28;
                i++;
            }
            __dt__Q210JASDrumSet5TPercFv((char *)obj + 0xA14, -1);
            if (&obj->field_08 != 0) {
                if (&obj->field_08 != 0) {
                    obj->field_08 = (unsigned char *)zero;
                    obj->field_0C = zero;
                    obj->field_10 = zero;
                }
            }
            if (arg1 > 0)
                fn_80128668(obj);
        }
    }
    return obj;
}

void fn_8017188C(void *arg0) {
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)arg0 + 0xC)) {
        unsigned char *entry = *(unsigned char **)((char *)arg0 + 8) + offset;
        if (entry[0x25] && !entry[0x24] && *(int *)*(void **)(entry + 0x18) > 1)
            ((void (*)(void *, void *, int, const char *))fn_80141558)((char *)arg0 + 0xA14, entry, 2, fn_8000FDF0 + 0x110);
        offset += 0x28;
        i++;
    }
}

void fn_80171930(void) {
}

extern s32 fn_801B2F24(void);
extern s32 fn_801B2F54(s32);
extern void fn_8017960C(s32);
extern s32 fn_80139B5C(s32);
extern void fn_801D488C(s32, s32, s32, f32 *, f32, f32, f32);
extern f32 lbl_80561A30;
#pragma push
#pragma paired off
#pragma paired_single off
void fn_80171934(void *p) {
    s32 outerCount;
    u8 *item;
    s32 off;
    s32 outer;
    s32 inner;
    f32 scale;
    outerCount = fn_801B2F24();
    scale = lbl_80561A30;
    outer = 0;
    while (outer < outerCount) {
        inner = 0;
        off = 0;
        while (inner < *(s32 *)((u8 *)p + 0xC)) {
            item = *(u8 **)((u8 *)p + 8) + off;
            if (item[0x24] == 0 && fn_801B2F54(outer) >= *(s32 *)(item + 0x20)) {
                s32 selection = ((s32 (*)(s32))fn_8017960C)(outer);
                if (((s32 (*)(s32, s32))fn_80139B5C)(selection, *(s32 *)(item + 0x18)) != 0) {
                    f32 z, y, x;
                    f32 vec[3];
                    vec[0] = *(f32 *)(item + 0) + *(f32 *)(item + 0xC);
                    x = vec[0] * scale;
                    vec[1] = *(f32 *)(item + 4) + *(f32 *)(item + 0x10);
                    y = vec[1] * scale;
                    vec[2] = *(f32 *)(item + 8) + *(f32 *)(item + 0x14);
                    vec[1] = y;
                    vec[0] = x;
                    vec[2] *= scale;
                    ((void (*)(s32, s32, s32, f32 *))fn_801D488C)(*(s32 *)(item + 0x1C), 1, 1, vec);
                    item[0x24] = 1;
                }
            }
            off += 0x28;
            inner++;
        }
        outer++;
    }
}
#pragma pop
void fn_80171A4C(void *arg0) {
    int count = 0;
    int offset = 0;
    while (count < *(int *)((char *)arg0 + 12)) {
        unsigned char *base = *(unsigned char **)((char *)arg0 + 8);
        base[offset + 0x24] = 0;
        offset += 0x28;
        count++;
    }
}

void fn_80171CE0(void) {

}

