// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* __sys_alloc(unsigned int);
typedef struct Block {
    struct Block* prev;
    struct Block* next;
    unsigned int max_size;
    unsigned int size_flags;
    unsigned int sb_size;
    unsigned int sb_link;
} Block;
extern void Block_link(void*, void*, int, int);
static inline Block* Pool_expand(Block** list, unsigned int size) {
    unsigned int total = (size + 0x1f) & ~7;
    Block* b;
    if (total < 0x10000) total = 0x10000;
    b = (Block*)__sys_alloc(total);
    if (b == 0) return 0;
    b->size_flags = total | 3;
    *(unsigned int*)((char*)b + total - 8) = total | 3;
    b->sb_link = (unsigned int)b | 1;
    b->sb_size = total - 0x18;
    *(unsigned int*)((char*)b + total - 0xc) = total - 0x18;
    b->max_size = total - 0x18;
    *(unsigned int*)((char*)b + (b->size_flags & ~7) - 4) = 0;
    Block_link(b, (char*)b + 0x10, 0, 0);
    if (*list) {
        Block* head = *list;
        b->prev = head->prev;
        head->prev->next = b;
        b->next = *list;
        (*list)->prev = b;
        *list = b;
    } else {
        *list = b;
        b->prev = b;
        b->next = b;
    }
    return b;
}
extern int fn_8002194C(void*, unsigned int, int*);
int fn_80021D48(void** arg0, int arg1, int* arg2) {
    void* node; unsigned int size,total; int result;
    if(arg2)*arg2=0; size=(arg1+15)&~7; if(size<0x50)size=0x50; node=*arg0;
    if(!node) { total=(size+31)&~7; if(total<0x10000)total=0x10000; node=__sys_alloc(total);
      if(node) { unsigned int flags=total|3; int end=(int)node|1, remain=total-0x18;
        *(unsigned int*)((char*)node+12)=flags; *(unsigned int*)((char*)node+total-8)=flags;
        *(int*)((char*)node+20)=end; *(int*)((char*)node+16)=remain;
        *(int*)((char*)node+total-4)=remain; *(int*)((char*)node+8)=remain; *(int*)((char*)node+total-4)=0;
        Block_link((char*)node+16,(char*)node+total-4,0,end);
        if(*arg0) { void* head=*arg0; void* first=*(void**)head;
          *(void**)node=first; *(void**)((char*)first+4)=node; *(void**)((char*)node+4)=head;
          *(void**)head=node; *arg0=node;
        } else { *arg0=node; *(void**)node=node; *(void**)((char*)node+4)=node; }
      }
    }
    if(!node)return 0;
    for(;;) { if(size<=*(unsigned int*)((char*)node+8)) { result=fn_8002194C(node,size,arg2); if(result){*arg0=node;return result+8;} }
      node=*(void**)((char*)node+4); if(node==*arg0) {
        total=(size+31)&~7; if(total<0x10000)total=0x10000; node=__sys_alloc(total);
        if(node) { unsigned int flags=total|3; int end=(int)node|1, remain=total-0x18;
          *(unsigned int*)((char*)node+12)=flags; *(unsigned int*)((char*)node+total-8)=flags;
          *(int*)((char*)node+20)=end; *(int*)((char*)node+16)=remain;
          *(int*)((char*)node+total-4)=remain; *(int*)((char*)node+8)=remain; *(int*)((char*)node+total-4)=0;
          Block_link((char*)node+16,(char*)node+total-4,0,end);
          if(*arg0) { void* head=*arg0; void* first=*(void**)head;
            *(void**)node=first; *(void**)((char*)first+4)=node; *(void**)((char*)node+4)=head;
            *(void**)head=node; *arg0=node;
          } else { *arg0=node; *(void**)node=node; *(void**)((char*)node+4)=node; }
        }
        if(!node)return 0; result=fn_8002194C(node,size,arg2); return result+8;
      }
    }
}
