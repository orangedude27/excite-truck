// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F680;
void* fn_8027ED70(void) {
    return lbl_8055F680;
}

void fn_802872DC(void* arg0) {
    ((void (**)(void*))(*(void***)*(void**)((char*)arg0 + 4)))[3](*(void**)((char*)arg0 + 4));
}

void fn_802872F0(void* arg0) {
    ((void (**)(void*))(*(void***)*(void**)((char*)arg0 + 4)))[4](*(void**)((char*)arg0 + 4));
}

void fn_80287304(void* arg0) {
    ((void (**)(void*))(*(void***)*(void**)((char*)arg0 + 4)))[5](*(void**)((char*)arg0 + 4));
}

void fn_80287318(void* arg0) {
    ((void (**)(void*))(*(void***)*(void**)((char*)arg0 + 4)))[6](*(void**)((char*)arg0 + 4));
}

void fn_80287360(void) {
}

int fn_80287364(void* arg0) {
    int i;
    void* item;

    for (i = 0; i < ((int (*)(void*))(*(void***)arg0)[6])(arg0); i++) {
        item = ((void* (*)(void*, int))(*(void***)arg0)[7])(arg0, i);
        if (((int (*)(void))(*(void***)item)[16])() == 0) {
            return 0;
        }
    }
    return 1;
}

void fn_802873F8(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void** vtable = *(void***)obj;
    ((void (*)(void))vtable[9])();
}

int fn_8028740C(void* arg0) {
    int i;
    void* item;

    for (i = 0; i < ((int (*)(void*))(*(void***)arg0)[6])(arg0); i++) {
        item = ((void* (*)(void*, int))(*(void***)arg0)[7])(arg0, i);
        if (((int (*)(void))(*(void***)item)[18])() == 0) {
            return 0;
        }
    }
    return 1;
}

