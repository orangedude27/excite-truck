// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8002194C(void*, unsigned int, int*);
struct Node80021F88 { void *next; unsigned int avail; };
int fn_80021F88(void** arg0, int arg1, int* arg2) {
    void* node; unsigned int size; int result;
    size=(arg1+15)&~7; if(size<0x50)size=0x50; *arg2=0; node=*arg0;
    if(!node)return 0;
    for(;;) {
        if(size<=*(unsigned int*)((char*)node+8)) {
            result=fn_8002194C(node,size,0);
            if(result){*arg0=node;break;}
        }
        if(*(unsigned int*)((char*)node+8)>8 && *(unsigned int*)arg2<*(unsigned int*)((char*)node+8)-8) *(unsigned int*)arg2=*(unsigned int*)((char*)node+8)-8;
        node=*(void**)((char*)node+4); if(node==*arg0)return 0;
    }
    return result+8;
}
