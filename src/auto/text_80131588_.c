// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern s32 fn_80128668(void);
extern int stricmp(const char*, const char*);
extern s32 fn_80131C88(s32);

unsigned char* fn_801317F0(void* arg0) {
    unsigned char* p = *(unsigned char**)((char*)arg0 + 4);
    if ((int)*p == 0x24) return p + 6;
    return p;
}

extern int fn_80131588(int, int);
void fn_80131808(int arg0) { fn_80131588(arg0, 0); }

void fn_80131818(void) {
    fn_8012C4D8();
}

extern void fn_802E30C8(const char*, ...);
extern const char lbl_8032B510[];
extern char lbl_8032B64C[], lbl_8032B574[], lbl_8042F530[];
extern int lbl_80559B08, lbl_80559B0C;
extern signed char lbl_8055E060;
extern void* lbl_8042F53C[];
extern s32 fn_80131920(s32, s32);
extern void __register_global_object(void*, void (*)(void*), void*);
int fn_8013181C(void) {
    if (lbl_8032B510) {
        fn_802E30C8(lbl_8032B510);
    }
    return 0;
}

void* fn_8013184C(void) {
    if (lbl_8055E060 == 0) {
        ((void* volatile*)lbl_8042F53C)[0] = lbl_8032B64C;
        ((void* volatile*)lbl_8042F53C)[0] = lbl_8032B574;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        ((void* volatile*)lbl_8042F53C)[1] = &lbl_80559B0C;
        ((void* volatile*)lbl_8042F53C)[2] = &lbl_80559B08;
        ((void* volatile*)lbl_8042F53C)[3] = 0;
        ((void* volatile*)lbl_8042F53C)[4] = 0;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        ((void* volatile*)lbl_8042F53C)[6] = 0;
        __register_global_object(lbl_8042F53C, (void (*)(void*))((s32(*)(s32,s32))fn_80131920), lbl_8042F530);
        lbl_8055E060 = 1;
    }
    return lbl_8042F53C;
}

s32 fn_801318E0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131920(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131B10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131B50(void* arg0) {
    s32 count = *(s32*)((char*)arg0 + 0xC);
    s32 h = 0xBABBA;
    s32 i = 0;
    if (count > 0) {
        do {
            char* s = *(char**)((char*)arg0 + 0x10 + i);
            char* c;
            do {
                c = s++;
                h = h * 33 + (s8)*c;
            } while (*c);
            s = *(char**)((char*)arg0 + 0x10 + i + 4);
            do {
                c = s++;
                h = h * 33 + (s8)*c;
            } while (*c);
            i += 8;
        } while (--count);
    }
    return h;
}

s32 fn_80131BD0(void* arg0, const char* name) {
    s32 index = 0;
    char* found = NULL;
    s32 offset = 0;
    while (index < *(s32*)((char*)arg0 + 0xC)) {
        char* t = *(char**)((char*)arg0 + 0x10);
        if (stricmp(name, t + offset) == 0) {
            found = *(char**)((char*)arg0 + 0x10) + index * 8;
            break;
        }
        offset += 8;
        index++;
    }
    if (found == NULL && *(void**)((char*)arg0 + 0x14) != NULL) {
        found = (char*)fn_80131C88((s32)name);
    }
    return found != NULL;
}

s32 fn_80132098(void* arg0, s32 index, void* dst1, void* dst2) {
    if (index >= 0 && index < *(s32*)((char*)arg0 + 0xC)) {
        char* base = *(char**)((char*)arg0 + 0x10);
        *(void**)dst1 = *(void**)(base + index * 8);
        *(void**)dst2 = *(void**)(base + index * 8 + 4);
        return 1;
    }
    return 0;
}

extern int atoi(const char*);
s32 fn_801321BC(void* arg0) {
    void** vtable = *(void***)(*(void**)arg0);
    return ((s32(*)(int(*)(const char*)))vtable[5])(atoi);
}

s32 fn_80132C48(void) { return 0; }

extern void fn_802E317C(const char*, ...);
extern const char lbl_8032B73C[];
typedef struct { void** vtable; } Unk80132BD0;
