// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern const int lbl_802ED860[];
void fn_80022064(void *arg0, void *arg1, void **arg2, int index, void *arg4, unsigned int size) {
    struct Node {
        void *prev;
        void **next;
        unsigned int entrySize;
        void *head;
        int unk10;
    };
    struct Node *node = (struct Node *)arg0;
    unsigned int entry = lbl_802ED860[index];
    unsigned int step = entry + 4;
    unsigned int count = size / step;
    unsigned int i;
    unsigned char *current = (unsigned char *)arg4;
    unsigned char *next;

    node->prev = arg1;
    node->next = arg2;
    ((struct Node *)arg1)->next = arg0;
    *arg2 = arg0;
    node->entrySize = entry;
    for (i = 0; i < count - 1; i++) {
        next = current + step;
        *(void **)current = arg0;
        *(void **)(current + 4) = next;
        current = next;
    }
    *(void **)current = arg0;
    *(void **)(current + 4) = 0;
    node->head = arg4;
    node->unk10 = 0;
}
