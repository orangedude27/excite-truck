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
/* Links a freed heap block into the free list, coalescing with adjacent free blocks. */
void Block_link(void *heap, unsigned int *block) {
    unsigned int blockFlags, blockSize, mergedSize, prevBlockSize;
    unsigned int *freeListSentinel, *freeHead, *nextBlock, *unlinkTmp, *largestBlock;
    unsigned int *currentBlock, *prevBlock;
    union {
        unsigned int word;
        struct {
            unsigned int size : 29;
            unsigned int flags : 3;
        } bits;
    } combined;

    blockSize = block[0];
    blockFlags = blockSize & 0xFFFFFFF8;
    block[0] = blockSize & 0xFFFFFFFD;
    *(unsigned int *)((char *)block + blockFlags) &= 0xFFFFFFFB;
    *(unsigned int *)((char *)block + blockFlags - 4) = blockFlags;

    freeListSentinel = (unsigned int *)((char *)heap + (*(unsigned int *)((char *)heap + 0xC) & 0xFFFFFFF8)) - 1;
    freeHead = (unsigned int *)*freeListSentinel;
    if (freeHead != 0) {
        nextBlock = (unsigned int *)freeHead[2];
        currentBlock = block;
        currentBlock[2] = (unsigned int)nextBlock;
        nextBlock[3] = (unsigned int)currentBlock;
        currentBlock[3] = *freeListSentinel;
        ((unsigned int *)*freeListSentinel)[2] = (unsigned int)currentBlock;
        *freeListSentinel = (unsigned int)currentBlock;

        if (!(block[0] & 4)) {
            prevBlockSize = *(unsigned int *)((char *)block - 4);
            if (prevBlockSize & 2) {
                currentBlock = block;
            } else {
                prevBlock = (unsigned int *)((char *)block - prevBlockSize);
                blockFlags = *prevBlock & 7;
                *prevBlock = blockFlags;
                mergedSize = prevBlockSize + (block[0] & 0xFFFFFFF8);
                combined.word = blockFlags;
                combined.bits.size = mergedSize >> 3;
                blockFlags = combined.word;
                *prevBlock = blockFlags;
                if (!(blockFlags & 2)) {
                    mergedSize = prevBlockSize + (((volatile unsigned int *)block)[0] & 0xFFFFFFF8);
                    *(unsigned int *)((char *)prevBlock + mergedSize - 4) = mergedSize;
                }
                freeHead = (unsigned int *)*freeListSentinel;
                if (freeHead == block)
                    *freeListSentinel = freeHead[3];
                ((unsigned int *)block[3])[2] = block[2];
                unlinkTmp = (unsigned int *)block[3];
                ((unsigned int *)unlinkTmp[2])[3] = (unsigned int)unlinkTmp;
                currentBlock = prevBlock;
            }
        }

        *freeListSentinel = (unsigned int)currentBlock;
        ((void (*)(unsigned int *, unsigned int **))SubBlock_merge_next)(currentBlock, (unsigned int **)freeListSentinel);
    } else {
        *freeListSentinel = (unsigned int)block;
        block[2] = (unsigned int)block;
        block[3] = (unsigned int)block;
    }

    largestBlock = (unsigned int *)*freeListSentinel;
    blockSize = largestBlock[0] & 0xFFFFFFF8;
    if (*(unsigned int *)((char *)heap + 8) < blockSize)
        *(unsigned int *)((char *)heap + 8) = blockSize;
}
