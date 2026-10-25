// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FB84;
__declspec(section ".data") extern unsigned int lbl_8034B008;
extern void *lbl_8055FB80;
extern int fn_80128668(void *);
extern int fn_802BAD9C(int);
void fn_802C2914(void *arg0) {
    *(void **)((char *)arg0 + 4) = &lbl_8034B008;
    *(void **)arg0 = lbl_8055FB80;
    lbl_8055FB80 = arg0;
}

int fn_802C2930(void *arg0, int arg1) {
    void *node;
    void **link;
    if (arg0 != 0) {
        link = (void **)&lbl_8055FB80;
        while ((node = *link) != 0) {
            if (node == arg0) { *link = *(void **)node; break; }
            link = (void **)node;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return (int)arg0;
}

#pragma cplusplus on
extern "C" void fn_802C29A0(void) {
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
    lbl_8055FB84 = 0;
}
