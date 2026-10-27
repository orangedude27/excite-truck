#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000A7A8(void);
extern void fn_8000A6D8(void) DECOMP_DONT_INLINE;
extern void fn_8000A808(void);
extern void fn_80128668(void*);
extern void fn_80009DC8(void);
extern void fn_801345D8(void*, s32, void*, s32);
extern u8 lbl_80558A14;
extern void fn_8012DDA8(void*);
extern void fn_8012E498(void*);
extern void fn_801DCDA0(void);
extern void fn_801DCDA4(void);
extern u8 lbl_8055D3B4;
extern u8 lbl_8055D3B5;
extern char lbl_8034F4C8[];
extern void fn_8012E81C(void*);
extern void fn_80129324(s32);
extern void fn_80206518(void);
extern u32 lbl_8055D3B0;
extern u32 lbl_8055D3B8;
extern u8 lbl_802FBC7C[];
extern void fn_8000A8C4();
extern void fn_8020C920(void*);
extern void fn_802103B8(void*);
void fn_8000A644(void* arg0, void* arg1) DECOMP_DONT_INLINE;
void fn_8000AADC(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AAE0(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AA38(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AA9C(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AABC(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AAE4(void* arg0) DECOMP_DONT_INLINE;
void fn_8000AB48(void* arg0, s32 arg1);
void fn_8000ABE0(void* arg0);
u32 fn_8000AC38(void);

void* fn_80009D70(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
void fn_8000A644(void* arg0, void* arg1) {
    s32 count = 0;
    char* dst = (char*)arg0 + 0x20;
    s32* src = (s32*)arg1;
    ((s32*)arg0)[0x3E0 / 4] = src[0x24 / 4];
    while (count < ((s32*)arg0)[0x3C0 / 4]) {
        dst += 0x78;
        *(s32*)(dst - 0x10) = src[4 / 4];
        *(s32*)(dst - 0xC) = src[0x28 / 4];
        src++;
        count++;
    }
    fn_80009DC8();
}
#pragma pop
void fn_8000A688(void (*arg0)(void*), s32 arg1) DECOMP_DONT_INLINE {
    char sp8[0x20];
    ((void (*)(void*, s32, void*, s32))fn_801345D8)(sp8 + 8, 0x20, &lbl_80558A14, arg1);
    arg0(sp8 + 8);
}

extern void *fn_80131810(const char *);
extern void fn_80131818(void *);
extern void fn_802E317C(const char *, ...);
extern int stricmp(const char *, const char *);
extern char lbl_802FBC08[];
extern char lbl_802FBC18[];
extern int lbl_80558A20;
extern int lbl_80558A28;
extern int lbl_80558A30;
#pragma cplusplus on
extern "C" void *fn_80131810(const char *);
extern "C" void fn_80131818(void *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" char lbl_802FBC08[];
extern "C" char lbl_802FBC18[];
extern "C" int lbl_80558A20;
extern "C" int lbl_80558A28;
extern "C" int lbl_80558A30;
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8000A6D8(void) {
    class ManagerView {
    public:
        virtual void unused0() = 0;
        virtual void unused1() = 0;
        virtual void unused2() = 0;
        virtual const char *getName(const char *) = 0;
    };
    class ResourceView {
    public:
        virtual void *getItem(const char *) = 0;
        virtual void unused1() = 0;
        virtual void unused2() = 0;
        virtual const char *getName(const char *) = 0;
    };
    const char *original;
    const char *name;
    void *resource;
    void *manager;
    void *item;
    manager = *(void **)((u8 *)(void *)lbl_8055D3B8 + 0x20);
    original = ((ManagerView *)manager)->getName((const char *)&lbl_80558A20);
    name = (const char *)&lbl_80558A28;
    resource = fn_80131810(lbl_802FBC08);
    if (resource != 0) {
        item = ((ResourceView *)resource)->getItem((const char *)&lbl_80558A20);
        name = ((ResourceView *)item)->getName((const char *)&lbl_80558A30);
        fn_80131818(resource);
    }
    if (stricmp(name, original) != 0) {
        fn_802E317C(lbl_802FBC18, original, name);
    }
}
#pragma pop
#pragma cplusplus reset

void fn_8000AADC(void* arg0) {
    fn_8000A7A8();
}

void fn_8000AAE0(void* arg0) {
    fn_8000A808();
}

#pragma push
#pragma scheduling invalid_target
void fn_8000AAE4(void* arg0) {
    s8* p = (s8*)arg0 + 0x64;
    s32 i;
    for (i = 0; i < ((s32*)arg0)[0x3E0 / 4]; i++) {
        fn_8000AABC(p);
        p += 0x78;
    }
}
#pragma pop
void fn_8000AB44(void) {
    fn_8000A6D8();
}

#pragma push
#pragma scheduling invalid_target
void fn_8000AB48(void* arg0, s32 arg1) {
    char* p;
    s32 i;
    fn_8000A8C4();
    fn_8000AADC(arg0);
    fn_8000A644(arg0, (void*)arg1);
    p = (char*)arg0 + 0x64;
    for (i = 0; i < ((s32*)arg0)[0x3E0 / 4]; i++) {
        fn_8000AA9C(p);
        p += 0x78;
    }
    fn_8012DDA8(&lbl_802FBC7C);
    fn_8020C920(arg0);
    fn_802103B8(arg0);
}
#pragma pop
void fn_8000ABE0(void* arg0) {
    fn_8012E498(&lbl_802FBC7C);
    fn_8000AAE4(arg0);
    fn_8000AAE0(arg0);
    fn_8000AA38(arg0);
}

extern u8 lbl_8034F520[];
void *__AXGetStudio_8000AC2C(void) {
    return lbl_8034F520;
}

u32 fn_8000AC38(void) {
    return lbl_8055D3B8;
}

void fn_8000A7A8(void) {
    char* base = (char*)&lbl_8034F4C8;
    if (lbl_8055D3B4 != 0) {
        fn_8012DDA8(base + 0x58);
    }
    fn_8012DDA8(base + 0x18);
    if (lbl_8055D3B5 != 0) {
        fn_8012DDA8(base + 0x98);
    }
    fn_801DCDA0();
}

void fn_8000A808(void) {
    char* lbl_8034F4C8_ptr = (char*)&lbl_8034F4C8;
    fn_801DCDA4();
    fn_8012E498(lbl_8034F4C8_ptr + 0x18);
    if (lbl_8055D3B4 != 0) {
        fn_8012E498(lbl_8034F4C8_ptr + 0x58);
    }
    if (lbl_8055D3B5 != 0) {
        fn_8012E498(lbl_8034F4C8_ptr + 0x98);
    }
}

void fn_8000A868(void) {
    char* lbl_8034F4C8_ptr = (char*)&lbl_8034F4C8;
    fn_8012E81C(lbl_8034F4C8_ptr + 0x18);
    if (lbl_8055D3B4 != 0) {
        fn_8012E81C(lbl_8034F4C8_ptr + 0x58);
    }
    if (lbl_8055D3B5 != 0) {
        fn_8012E81C(lbl_8034F4C8_ptr + 0x98);
    }
}

void fn_8000AA38(void* arg0) {
    char* base = (char*)&lbl_8034F4C8;
    fn_80129324(lbl_8055D3B0);
    lbl_8055D3B0 = 0;
    fn_80206518();
    fn_8020CA38();
    lbl_8055D3B8 = 0;
    lbl_8055D3B4 = 0;
    lbl_8055D3B5 = 0;
    base[0x18] = 0;
    base[0x98] = 0;
    base[0x58] = 0;
}

void fn_8000AA9C(void* arg0) {
    s8 c = ((u8*)arg0)[0];
    if (c == 0) {
        return;
    }
    fn_8000A688(fn_8012DDA8, (s32)arg0);
}

void fn_8000AABC(void* arg0) {
    s8 c = ((u8*)arg0)[0];
    if (c == 0) {
        return;
    }
    fn_8000A688((void (*)(void*))fn_8012E498, (s32)arg0);
}

