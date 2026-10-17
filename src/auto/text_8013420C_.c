// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
typedef struct Entry { s32 state; s32 unk4; void *obj; void (*cb)(void *, void *, void *); void *unk10; s32 pad; } Entry;
typedef struct Container { void *data; s32 count; s32 stride; Entry *entries; } Container;

typedef unsigned int u32;
extern void *lbl_80559BD0;
extern char lbl_8032BB18[];
extern char lbl_8032BB24[];
s32 fn_8012850C(s32, void *);
s32 fn_8012C7FC(void *, s32 *);
void fn_8012C958(void *);
void fn_8012C90C(void *);
void fn_80128670(void *);
void fn_80128668(void *);
void fn_802E30C8(const char *, ...);
void *fn_8013420C(Container *arg0, s32 arg1, s32 arg2) {
    s32 i;
    Entry *entry;
    arg0->count = arg1;
    arg0->stride = arg2;
    arg0->data = (void *)fn_8012850C(arg1 * arg2, lbl_80559BD0);
    arg0->entries = (Entry *)fn_8012850C(arg1 * 0x18, lbl_8032BB18);
    for (i = 0; i < arg1; i++) {
        entry = (Entry *)((char *)arg0->entries + i * 0x18);
        entry->unk4 = (s32)((char *)arg0->data + i * arg2);
        entry->state = 0;
        entry->obj = 0;
    }
    return arg0;
}

void *fn_801342B0(Container *arg0, s32 arg1, s32 arg2) {
    s32 i;
    Entry *entry;
    if (arg0 != 0) {
        for (i = 0; i < arg0->count; i++) {
            entry = (Entry *)((char *)arg0->entries + i * 0x18);
            if (entry->state == 1) {
                fn_802E30C8(lbl_8032BB24);
                fn_8012C90C(entry->obj);
                fn_8012C958(entry->obj);
            }
        }
        fn_80128670(arg0->entries);
        fn_80128670(arg0->data);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8013436C(Container *arg0, s32 arg1) {
    s32 i;
    Entry *entry;
    s32 result;
    s32 value;
    for (i = 0; i < arg0->count; i++) {
        entry = (Entry *)((char *)arg0->entries + i * 0x18);
        if (entry->state == 1) {
            value = 0;
            result = fn_8012C7FC(entry->obj, &value);
            if (result != 0) {
                entry->state = 2;
                fn_8012C958(entry->obj);
                entry->obj = 0;
                if (entry->cb != 0) entry->cb((void *)result, (void *)value, entry->unk10);
            }
        }
    }
}

s32 fn_801345A4(Container *arg0, s32 arg1) {
    Entry *entry = &arg0->entries[arg1];
    if (entry->state == 1) return 0;
    entry->state = 0;
    return 1;
}
