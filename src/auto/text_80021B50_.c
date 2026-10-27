// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

void Block_link(void *arg0, unsigned int *arg1);
typedef struct {
    void (*function)(void *, unsigned int *);
    unsigned int size;
    const unsigned long long *extab;
} BlockLinkExtabIndex;

#pragma section ".extab"
DECL_SECTION(".extab") const unsigned long long etb_80004520 = 0x1008000000000000ULL;
#pragma section ".extabindex"
DECL_SECTION(".extabindex") const BlockLinkExtabIndex eti_80004700 = {
    Block_link, 0x150, &etb_80004520
};

extern void SubBlock_merge_next(unsigned int **);
void Block_link(void *arg0, unsigned int *arg1) {
    unsigned int flags, size, new_size, prev_size;
    unsigned int *sentinel, *head, *next, *tmp, *block;
    unsigned int *current, *merged;
    union {
        unsigned int word;
        struct {
            unsigned int size : 29;
            unsigned int flags : 3;
        } bits;
    } combined;

    size = arg1[0];
    flags = size & 0xFFFFFFF8;
    arg1[0] = size & 0xFFFFFFFD;
    *(unsigned int *)((char *)arg1 + flags) &= 0xFFFFFFFB;
    *(unsigned int *)((char *)arg1 + flags - 4) = flags;

    sentinel = (unsigned int *)((char *)arg0 + (*(unsigned int *)((char *)arg0 + 0xC) & 0xFFFFFFF8)) - 1;
    head = (unsigned int *)*sentinel;
    if (head != 0) {
        next = (unsigned int *)head[2];
        current = arg1;
        current[2] = (unsigned int)next;
        next[3] = (unsigned int)current;
        current[3] = *sentinel;
        ((unsigned int *)*sentinel)[2] = (unsigned int)current;
        *sentinel = (unsigned int)current;

        if (!(arg1[0] & 4)) {
            prev_size = *(unsigned int *)((char *)arg1 - 4);
            if (prev_size & 2) {
                current = arg1;
            } else {
                merged = (unsigned int *)((char *)arg1 - prev_size);
                flags = *merged & 7;
                *merged = flags;
                new_size = prev_size + (arg1[0] & 0xFFFFFFF8);
                combined.word = flags;
                combined.bits.size = new_size >> 3;
                flags = combined.word;
                *merged = flags;
                if (!(flags & 2)) {
                    new_size = prev_size + (((volatile unsigned int *)arg1)[0] & 0xFFFFFFF8);
                    *(unsigned int *)((char *)merged + new_size - 4) = new_size;
                }
                head = (unsigned int *)*sentinel;
                if (head == arg1)
                    *sentinel = head[3];
                ((unsigned int *)arg1[3])[2] = arg1[2];
                tmp = (unsigned int *)arg1[3];
                ((unsigned int *)tmp[2])[3] = (unsigned int)tmp;
                current = merged;
            }
        }

        *sentinel = (unsigned int)current;
        ((void (*)(unsigned int *, unsigned int **))SubBlock_merge_next)(current, (unsigned int **)sentinel);
    } else {
        *sentinel = (unsigned int)arg1;
        arg1[2] = (unsigned int)arg1;
        arg1[3] = (unsigned int)arg1;
    }

    block = (unsigned int *)*sentinel;
    size = block[0] & 0xFFFFFFF8;
    if (*(unsigned int *)((char *)arg0 + 8) < size)
        *(unsigned int *)((char *)arg0 + 8) = size;
}
