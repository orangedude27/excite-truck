// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FB84;
__declspec(section ".data") extern unsigned int lbl_8034B008;
extern void *lbl_8055FB80;
extern int fn_80128668(void *);
extern int fn_802BAD9C(int);
/* Insert a new node at the head of the lbl_8055FB80 list: install the lbl_8034B008 vtable at +4, point next at the old head, then publish it as the new head. */
void fn_802C2914(void *node) {
    *(void **)((char *)node + 4) = &lbl_8034B008;
    *(void **)node = lbl_8055FB80;
    lbl_8055FB80 = node;
}

int fn_802C2930(void *node, int shouldFree) {
    /* Unlink `node` from the lbl_8055FB80 list if present; optionally free it; return the original pointer. */
    void *cur;
    void **link;
    if (node != 0) {
        link = (void **)&lbl_8055FB80;
        while ((cur = *link) != 0) {
            if (cur == node) { *link = *(void **)cur; break; }
            link = (void **)cur;
        }
        if (shouldFree > 0) fn_80128668(node);
    }
    return (int)node;
}

#pragma cplusplus on
extern "C" void fn_802C29A0(void) {
    /* Sum calc() over the lbl_8055FB80 node list, commit via fn_802BAD9C, run finish() on each, then mark done. */
    struct Prefix {
        Prefix *next;
    };
    class Node : public Prefix {
    public:
        virtual int calc() = 0;
        virtual void finish() = 0;
    };
    int sum = 0;
    {
        Node *node;
        for (node = (Node *)lbl_8055FB80; node != 0; node = (Node *)node->next)
            sum += node->calc();
    }
    fn_802BAD9C(sum);
    {
        Node *node;
        for (node = (Node *)lbl_8055FB80; node != 0; node = (Node *)node->next)
            node->finish();
    }
    lbl_8055FB84 = 1;
}
#pragma cplusplus off
void fn_802C2A34(void) {
#define sCommitDone lbl_8055FB84
    /* Clear the commit-done flag (part of the UI shutdown reset in fn_802AE9D0). */
    sCommitDone = 0;
#undef sCommitDone
}
