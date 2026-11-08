// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8012C4D8(void);
void fn_80128670(int);
void fn_80128668(void *);
void *fn_8012C370(int, unsigned int, unsigned int *, unsigned int *, int, unsigned char *);
void *fn_80131234(void *);
void fn_802E317C(char *, ...);
extern char lbl_803401F8[];
extern char lbl_80340220[];

// "LAYT" layout resource.  fn_8022E0EC loads one through the resource manager
// (fn_8012C370) and byte-swaps it; fn_8022E4C0 builds the same records in
// memory for the fallback dialog, and fn_802123B8 turns each entry into a
// message-window node.  The block is big-endian: a 0x68-byte header followed
// by 0x134-byte auto-item entries, the list ended by an entry whose first
// word is 0.  Header +0x64 points at the first entry (which sits right after
// the header in the file).  An entry holds its type (+0x00), a mode/id
// (+0x04), its rectangle (+0x08 x, +0x0c y, +0x14 width, +0x18 height,
// +0x1c scale), a name string (+0x20, 0x20 bytes) and a text string (+0x40,
// 0x40 bytes); +0x80..+0xb3 are the appearance words (colour at +0x9c).  A
// text starting with '|' is a reference to the string-table entry named by
// the rest of it, which fn_8022E0EC resolves in place.
#define LAYT_TAG 0x4C415954 // 'LAYT'
#define LAYT_VERSION 5
#define LAYT_ENTRY_SIZE 0x134

// Byte-reverse the big-endian 32-bit word at (p)[off], through the calling
// function's `t` temporary.
#define SWAP_BE32(p, off)          \
    t = (p)[off];                  \
    (p)[off] = (p)[(off) + 3];     \
    (p)[(off) + 3] = t;            \
    t = (p)[(off) + 1];            \
    (p)[(off) + 1] = (p)[(off) + 2]; \
    (p)[(off) + 2] = t;

#pragma scheduling invalid_target
/* Load the "LAYT" layout resource named `name` and get it ready to use.

   The resource manager hands back the block as it is stored on disc, which is
   big-endian, so the header's and every entry's 32-bit fields are byte-reversed
   here - but only when this call is the one that brought the block in
   (`firstLoad`), since one already in memory has been swapped once.  An entry's
   text may be a "|name" reference into the string table; those are resolved in
   place.  Returns the layout, whose +0x64 points at its first entry, or 0 when
   the resource is missing. */
void *fn_8022E0EC(const char *name) {
    unsigned int version;
    unsigned int size;
    unsigned char firstLoad;
    char *layout;
    char *entry;
    char *src;
    char ch;
    int remaining;
    char *dst;
    char t;

    layout = fn_8012C370((int)name, LAYT_TAG, &version, &size, 0, &firstLoad);
    if (layout != 0) {
        if (version != LAYT_VERSION) {
            fn_802E317C(lbl_803401F8, name, version, LAYT_VERSION);
        }
        if (firstLoad != 0) {
            entry = layout + 0x68;
            *(char **)(layout + 0x64) = entry;
            SWAP_BE32(layout, 0x0); // layout id
            for (;;) {
                SWAP_BE32(entry, 0x00); // type
                SWAP_BE32(entry, 0x04); // mode / id
                SWAP_BE32(entry, 0x08); // x
                SWAP_BE32(entry, 0x0c); // y
                SWAP_BE32(entry, 0x10);
                SWAP_BE32(entry, 0x14); // width
                SWAP_BE32(entry, 0x18); // height
                SWAP_BE32(entry, 0x1c); // scale
                // The name at +0x20 and the text at +0x40 are byte strings and
                // are left alone; the appearance words follow at +0x80..+0xb3.
                SWAP_BE32(entry, 0x80);
                SWAP_BE32(entry, 0x84);
                SWAP_BE32(entry, 0x88);
                SWAP_BE32(entry, 0x8c);
                SWAP_BE32(entry, 0x90);
                SWAP_BE32(entry, 0x94);
                SWAP_BE32(entry, 0x98);
                SWAP_BE32(entry, 0x9c); // colour
                SWAP_BE32(entry, 0xa0);
                SWAP_BE32(entry, 0xa4);
                SWAP_BE32(entry, 0xa8);
                SWAP_BE32(entry, 0xac);
                SWAP_BE32(entry, 0xb0);
                if (*(unsigned int *)entry == 0) {
                    break; // a type of 0 ends the entry list
                }
                if (entry[0x40] == '|') {
                    // "|name": replace the reference with the string it names.
                    src = fn_80131234(entry + 0x41);
                    dst = entry + 0x40;
                    remaining = 0x40;
                    goto copy_character;
                copy_more:
                    remaining--;
                    if (remaining > 0) {
                        goto copy_character;
                    }
                    dst[-1] = 0; // too long: cut the text short
                    goto copy_done;
                copy_character:
                    ch = *src++;
                    *dst++ = ch;
                    if (ch != 0) {
                        goto copy_more;
                    }
                copy_done:
                    ;
                }
                entry += LAYT_ENTRY_SIZE;
            }
        }
    } else {
        fn_802E317C(lbl_80340220, name);
    }
    return layout;
}
#pragma scheduling on
void fn_8022E4BC(void) {
    fn_8012C4D8();
}

void *memset(void *, int, unsigned int);
char *strcpy(char *, const char *);
int sprintf(char *, const char *, ...);
int strcmp(const char *, const char *);
void *fn_801284F8(unsigned int, const char *);
void *fn_8012850C(unsigned int, const void *);
#pragma small_data on
extern const char lbl_8055B960;
extern const char lbl_8055B968;
extern const char lbl_8055B96C;
extern const char lbl_8055B974;
extern const char lbl_8055B978;
extern float lbl_805635D8;
extern float lbl_805635DC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_8022E4C0(void *arg0) {
    unsigned char *base;
    unsigned char *entry;
    unsigned char *cur;
    unsigned char *next;
    char *strings;
    register int zero;
    int index;
    int type;
    int y;
    int dy;
    int add_default;
    register float scale;

    strings = lbl_803401F8;
    base = fn_801284F8(0x68, &lbl_8055B960);
    memset(base, 0, 0x68);
    *(unsigned char **)(base + 0x64) =
        fn_8012850C(0x13400, strings + 0x60);
    memset(*(void **)(base + 0x64), 0, 0x13400);
    zero = 0;
    entry = *(unsigned char **)(base + 0x64) + zero * 0x134;
    *(int *)(entry + 0x00) = 0x21;
    *(int *)(entry + 0x04) = 6;
    *(int *)(entry + 0x08) = 0;
    *(int *)(entry + 0x0c) = 0;
    *(int *)(entry + 0x14) = 0x280;
    *(int *)(entry + 0x18) = 0x1e0;
    strcpy((char *)(entry + 0x40), strings + 0x6c);
    zero = 1;
    entry = *(unsigned char **)(base + 0x64) + zero * 0x134;
    *(int *)(entry + 0x00) = 0x1c;
    strcpy((char *)(entry + 0x40), *(char **)arg0);
    *(int *)(entry + 0x08) = 0x140;
    *(int *)(entry + 0x0c) = 0x1e;
    *(int *)(entry + 0x14) = 0x20;
    *(int *)(entry + 0x18) = 0x20;
    *(int *)(entry + 0x04) = 0xc;
    *(float *)(entry + 0x1c) = lbl_805635D8;
    strcpy((char *)(entry + 0x20), strings + 0x7c);
    *(int *)(entry + 0x90) = -1;
    *(int *)(entry + 0x9c) = 0xff000000;
    *(int *)(entry + 0xb0) = 0x1a;
    *(int *)(entry + 0x84) = 2;
    index = 0x268;
    cur = *(unsigned char **)((unsigned char *)arg0 + 4);
    scale = lbl_805635DC;
    y = 0x5a;
    type = *(int *)(cur + 4);
    while (type != 0x7b) {
        dy = 0x1e;
        add_default = 1;
        if (type == 6) {
            dy = 0;
            add_default = 0;
        } else if (type == 9) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = 0x32;
            *(int *)(next + 0x08) = 0x10e;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0x8a;
            *(int *)(next + 0x18) = 0xe;
            strcpy((char *)(next + 0x20), *(char **)cur);
        } else if (type == 3) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = 0x1c;
            sprintf((char *)(next + 0x40), &lbl_8055B968, *(char **)cur);
            *(int *)(next + 0x08) = 0x12c;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0x20;
            *(int *)(next + 0x18) = 0x20;
            *(int *)(next + 0x04) = 0xc;
            *(float *)(next + 0x1c) = scale;
            strcpy((char *)(next + 0x20), strings + 0x7c);
            *(int *)(next + 0x90) = -1;
            *(int *)(next + 0x9c) = 0xff000000;
            *(int *)(next + 0xb0) = 0x1a;
            *(int *)(next + 0x84) = 2;
        } else if (type == 0x10 || type == 7) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = (type == 0x10) ? 0x31 : 0xa;
            *(int *)(next + 0x08) = 0x12c;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0x72;
            *(int *)(next + 0x18) = 0x23;
            strcpy((char *)(next + 0x20), *(char **)cur);
            strcpy((char *)(next + 0x40), &lbl_8055B96C);
        } else if (type == 0) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = 2;
            *(int *)(next + 0x04) = 0x19;
            *(int *)(next + 0x08) = 0xc8;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0x72;
            *(int *)(next + 0x18) = 0x23;
            strcpy((char *)(next + 0x20), *(char **)cur);
            strcpy((char *)(next + 0x40), *(char **)cur);
            add_default = 0;
        } else if (type == 2) {
            if (cur == *(unsigned char **)((unsigned char *)arg0 + 4)
                || *(int *)(cur - 0x10) != 9
                || strcmp(*(char **)cur, *(char **)(cur - 0x14)) != 0) {
                next = *(unsigned char **)(base + 0x64) + index;
                index += 0x134;
                *(int *)(next + 0x00) = 7;
                *(int *)(next + 0x08) = 0xc8;
                *(int *)(next + 0x0c) = y;
                *(int *)(next + 0x14) = 0x72;
                *(int *)(next + 0x18) = 0x23;
                strcpy((char *)(next + 0x20), *(char **)cur);
                strcpy((char *)(next + 0x40), &lbl_8055B974);
                add_default = 0;
            } else {
                dy = 0;
                add_default = 0;
            }
        } else if (type == 0xc) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = 9;
            *(int *)(next + 0x08) = 0xc8;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0x72;
            *(int *)(next + 0x18) = 0x23;
            strcpy((char *)(next + 0x20), *(char **)cur);
            strcpy((char *)(next + 0x40), &lbl_8055B978);
        } else if (type == 0xa) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = 0x17;
            *(int *)(next + 0x08) = 0xc8;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0xc8;
            *(int *)(next + 0x18) = 0x50;
            strcpy((char *)(next + 0x20), *(char **)cur);
            dy = *(int *)(next + 0x18) + 5;
        } else if (type == 5) {
            if (*(char **)cur != 0) {
                next = *(unsigned char **)(base + 0x64) + index;
                index += 0x134;
                *(int *)(next + 0x00) = 0x1a;
                *(int *)(next + 0x08) = 0xc8;
                *(int *)(next + 0x0c) = y;
                *(int *)(next + 0x14) = 0xc8;
                *(int *)(next + 0x18) = 0x32;
                strcpy((char *)(next + 0x20), *(char **)cur);
                dy = 0x32;
            }
        }
        if (add_default && *(char **)cur != 0) {
            next = *(unsigned char **)(base + 0x64) + index;
            index += 0x134;
            *(int *)(next + 0x00) = 0x1c;
            strcpy((char *)(next + 0x40), *(char **)cur);
            *(int *)(next + 0x08) = 0x64;
            *(int *)(next + 0x0c) = y;
            *(int *)(next + 0x14) = 0x20;
            *(int *)(next + 0x18) = 0x20;
            *(int *)(next + 0x04) = 0xc;
            *(float *)(next + 0x1c) = scale;
            strcpy((char *)(next + 0x20), strings + 0x7c);
            *(int *)(next + 0x90) = -1;
            *(int *)(next + 0x9c) = 0xff000000;
            *(int *)(next + 0xb0) = 0x1a;
            *(int *)(next + 0x84) = 2;
        }
        y += dy;
        cur += 0x14;
        type = *(int *)(cur + 4);
    }
    return base;
}
#pragma pop

void fn_8022E960(void *arg0) {
    fn_80128670(*(int *)((char *)arg0 + 0x64));
    fn_80128668(arg0);
}

