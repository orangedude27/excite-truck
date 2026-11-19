// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern const int lbl_802ED860[];
/* Initializes a pool header and builds a linked free list of fixed-size blocks in the provided buffer. */
void fn_80022064(void *arg0, void *arg1, void **arg2, int index, void *arg4, unsigned int size) {
    struct Node {
        void *prev;
        void **next;
        unsigned int entrySize;
        void *head;
        int unk10;
    };
    struct Node *pool = (struct Node *)arg0;
    unsigned int blockSize = lbl_802ED860[index];
    unsigned int blockStride = blockSize + 4;
    unsigned int blockCount = size / blockStride;
    unsigned int i;
    unsigned char *currentBlock = (unsigned char *)arg4;
    unsigned char *nextBlock;

    pool->prev = arg1;
    pool->next = arg2;
    ((struct Node *)arg1)->next = arg0;
    *arg2 = arg0;
    pool->entrySize = blockSize;
    for (i = 0; i < blockCount - 1; i++) {
        nextBlock = currentBlock + blockStride;
        *(void **)currentBlock = arg0;
        *(void **)(currentBlock + 4) = nextBlock;
        currentBlock = nextBlock;
    }
    *(void **)currentBlock = arg0;
    *(void **)(currentBlock + 4) = 0;
    pool->head = arg4;
    pool->unk10 = 0;
}
