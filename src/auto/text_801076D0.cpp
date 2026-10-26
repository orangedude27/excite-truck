#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
extern "C" const char lbl_80329530[];
extern f32 lbl_80561178, lbl_80561188;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
namespace nw4hbm { namespace ut { class ResFont { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int GetEncoding(); bool SetResource(void*); }; struct List; void List_Remove(List*, void*); void List_Init(List*, unsigned short); void List_Append(List*, void*); void* List_GetNth(const List*, unsigned short); void* List_GetNext(const List*, const void*); struct Font; struct Glyph; struct CharWidths; class CharWriter { public: void* pad[23]; void* font; void* GetFont() const; void SetFont(const Font&); }; namespace detail { class ResFontBase { public: u16 GetTextureFormat() const; s8 GetLineFeed() const; s32 GetDescent() const; s8 GetBaselinePos() const; s32 GetDefaultCharWidths() const; void GetGlyph(nw4hbm::ut::Glyph*, unsigned short) const; void GetGlyphFromIndex(nw4hbm::ut::Glyph*, unsigned short) const; void SetLineFeed(int); void SetDefaultCharWidths(const CharWidths&); }; } } }

extern "C" const char lbl_80328828[];
extern "C" const char lbl_80328834[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" f32 GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801058DC(s32);
extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32, f32);
extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(s32, f32);
extern "C" void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32, f32, f32);
extern "C" void fn_801033F0(void*, unsigned int);
extern "C" u8 fn_8010A33C(void);
extern "C" s32 fn_80109040(s32, s32);
extern "C" s32 fn_80128668(void);
extern "C" s32 fn_80109040(s32, s32);
extern "C" s32 fn_80128668(void);
extern "C" void* fn_80108FFC(void*, const void*);
extern "C" const char lbl_803290E8[];
extern "C" const char lbl_803293A8[];
extern "C" const char lbl_80329400[];
extern "C" const char lbl_80329140[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void* __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* self, int doFree) {
    extern const char lbl_80328680[];
    const char* file = lbl_80328680;
    if (self != 0) {
        void* head = (char*)self + 4;
        void* node = *(void**)((char*)self + 4);
        while (node != head) {
            void* next = *(void**)node;
            if (*(s32*)self == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x60, file + 0x10);
            if (node == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x61, file + 0x34);
            if (node == head)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x62, file + 0x58);
            void* prevNode = *(void**)((char*)node + 4);
            void* nextNode = *(void**)node;
            if (nextNode == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x65, file + 0x80);
            *(void**)((char*)nextNode + 4) = prevNode;
            if (prevNode == 0)
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x67, file + 0xA8);
            *(void**)prevNode = nextNode;
            --*(s32*)self;
            *(void**)node = 0;
            *(void**)((char*)node + 4) = 0;
            node = next;
        }
        if (doFree > 0)
            ((s32 (*)(s32))fn_80128668)((s32)self);
    }
    return self;
}

extern "C" void* Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void* self, void** iterator) {
    extern const char lbl_80328680[];
    const char* file = lbl_80328680;
    void* head = (char*)self + 4;
    void* first = *iterator;
    if (first == head)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x1F, file + 0xD0);
    void* node = *iterator;
    void* stop = *(void**)node;
    while (node != stop) {
        void* next = *(void**)node;
        if (*(s32*)self == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x60, file + 0x10);
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x61, file + 0x34);
        if (node == head)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x62, file + 0x58);
        void* nextNode = *(void**)node;
        void* prevNode = *(void**)((char*)node + 4);
        if (nextNode == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x65, file + 0x80);
        *(void**)((char*)nextNode + 4) = prevNode;
        if (prevNode == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x67, file + 0xA8);
        *(void**)prevNode = nextNode;
        --*(s32*)self;
        *(void**)node = 0;
        *(void**)((char*)node + 4) = 0;
        node = next;
    }
    return stop;
}

#pragma pop
extern "C" void Clear__Q46nw4hbm2ut6detail12LinkListImplFv(void *self) {
    extern const char lbl_80328680[];
    void *head = (char *)self + 4;
    void *node = *(void **)((char *)self + 4);
    while (node != head) {
        void *next = *(void **)node;
        if (*(s32 *)self == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x60, lbl_80328680 + 0x10);
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x61, lbl_80328680 + 0x34);
        if (node == head)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x62, lbl_80328680 + 0x58);
        void *prev = *(void **)((char *)node + 4);
        void *nextNode = *(void **)node;
        if (nextNode == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x65, lbl_80328680 + 0x80);
        *(void **)((char *)nextNode + 4) = prev;
        if (prev == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x67, lbl_80328680 + 0xA8);
        *(void **)prev = nextNode;
        --*(s32 *)self;
        *(void **)node = 0;
        *(void **)((char *)node + 4) = 0;
        node = next;
    }
}

extern "C" void* Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void* arg0, void** arg1, void* arg2) {
    extern const char lbl_80328680[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    const char* file = lbl_80328680;
    void* node;
    void* prev;
    if (arg2 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x4A, file + 0x34);
    node = *arg1;
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x4C, file + 0xFC);
    prev = *(void**)((char*)node + 4);
    if (prev == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x4F, file + 0x124);
    if (*(void**)arg2 != 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x51, file + 0x150);
    if (*(void**)((char*)arg2 + 4) != 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x52, file + 0x17C);
    *(void**)arg2 = node;
    *(void**)((char*)arg2 + 4) = prev;
    *(void**)((char*)node + 4) = arg2;
    *(void**)prev = arg2;
    ++*(int*)arg0;
    return arg2;
}

extern "C" void* Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(int* arg0, void* arg1) {
    extern const char lbl_80328680[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    const char* file = lbl_80328680;
    void* next;
    void* prev;
    if (*arg0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x60, file + 0x10);
    if (arg1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x61, file + 0x34);
    if (arg1 == (char*)arg0 + 4) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x62, file + 0x58);
    next = *(void**)arg1;
    prev = *(void**)((char*)arg1 + 4);
    if (next == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x65, file + 0x80);
    *(void**)((char*)next + 4) = prev;
    if (prev == 0) Panic__Q26nw4hbm2dbFPCciPCce(file, 0x67, file + 0xA8);
    *(void**)prev = next;
    --*arg0;
    *(void**)arg1 = 0;
    *(void**)((char*)arg1 + 4) = 0;
    return next;
}

void nw4hbm::ut::List_Init(nw4hbm::ut::List *list, unsigned short size) {
    if (list == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0x29, lbl_80328834);
    *(unsigned short *)((char *)list + 0xA) = size;
    *(int *)list = 0;
    *(int *)((char *)list + 4) = 0;
    *(unsigned short *)((char *)list + 8) = 0;
}

void nw4hbm::ut::List_Append(nw4hbm::ut::List* list, void* item) {
    register nw4hbm::ut::List* savedList = list;
    register void* savedItem = item;
    const char* file = lbl_80328828;
    if (savedList == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x59, file + 0xC);
    if (savedItem == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x5A, file + 0x34);
    if (*(void**)savedList == 0) {
        if (savedList == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x40, file + 0xC);
        if (savedItem == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file, 0x41, file + 0x34);
        *(void**)((char*)savedItem + *(u16*)((char*)savedList + 0xA) + 4) = 0;
        *(void**)savedItem = 0;
        u16 count = *(u16*)((char*)savedList + 8);
        *(void**)savedList = savedItem;
        *(void**)((char*)savedList + 4) = savedItem;
        *(u16*)((char*)savedList + 8) = count + 1;
    } else {
        u16 stride = *(u16*)((char*)savedList + 0xA);
        void* tail = *(void**)((char*)savedList + 4);
        *(void**)((char*)savedItem + stride) = tail;
        *(void**)((char*)savedItem + stride + 4) = 0;
        *(void**)((char*)tail + stride + 4) = savedItem;
        u16 count = *(u16*)((char*)savedList + 8);
        *(void**)((char*)savedList + 4) = savedItem;
        *(u16*)((char*)savedList + 8) = count + 1;
    }
}

void* nw4hbm::ut::List_GetNext(const nw4hbm::ut::List* list, const void* item) {
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0xF5, lbl_80328834);
    if (item == 0) return *(void**)list;
    return *(void**)((char*)item + *(unsigned short*)((char*)list + 0xA) + 4);
}

extern "C" const char lbl_80328828[];
extern "C" const char lbl_80328834[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
void* nw4hbm::ut::List_GetNth(const nw4hbm::ut::List* list, unsigned short index) {
    int i = 0;
    void* node = 0;
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0x129, lbl_80328834);
    do {
        if (i == index) return node;
        i++;
        if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0xf5, lbl_80328834);
        void* next;
        if (node == 0) next = *(void**)list;
        else next = *(void**)((char*)node + *(unsigned short*)((char*)list + 0xa) + 4);
        node = next;
    } while (node != 0);
    return 0;
}

extern "C" void* fn_80107FE4(void* arg0, const void* arg1) {
    fn_80108FFC(arg0, arg1);
    *(const char**)arg0 = lbl_803290E8;
    return arg0;
}

extern "C" void* __dt__Q36nw4hbm2ut7ResFontFv(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_80109040((s32)arg0, 0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" const char lbl_80328888[];
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" int IsValidBinaryFile__Q26nw4hbm2utFPCQ36nw4hbm2ut16BinaryFileHeaderUlUsUs(const void*, u32, u16, u16);
extern "C" void* Rebuild__Q36nw4hbm2ut7ResFontFPQ36nw4hbm2ut16BinaryFileHeader(void*);
extern "C" void SetResourceBuffer__Q46nw4hbm2ut6detail11ResFontBaseFPvPQ36nw4hbm2ut15FontInformation(void*, void*, void*);
extern "C" void InitReaderFunc__Q36nw4hbm2ut4FontFQ36nw4hbm2ut12FontEncoding(void*, int);
#pragma push
#pragma use_lmw_stmw off
bool nw4hbm::ut::ResFont::SetResource(void* resource) {
    const char* const file = lbl_80328888;
    u32 p = (u32)this;
    s32 v5 = 1, v6 = 1, v7 = 1, v8 = 1, v9 = 1, v10 = 1;
    u32 t11 = p & 0xFF000000;
    if ((t11 != 0x80000000U) &&
        ((p & 0xFF800000U) != 0x81000000U))
        v10 = 0;
    if ((v10 == 0) && ((p & 0xF8000000U) != 0x90000000U))
        v9 = 0;
    if ((v9 == 0) && (t11 != 0xC0000000U))
        v8 = 0;
    if ((v8 == 0) && ((p & 0xFF800000U) != 0xC1000000U))
        v7 = 0;
    if ((v7 == 0) && ((p & 0xF8000000U) != 0xD0000000U))
        v6 = 0;
    if ((v6 == 0) && ((p & 0xFFFFC000U) != 0xE0000000U))
        v5 = 0;
    if (v5 == 0)
        ((void (*)(const char*, int, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(file, 0x61, file + 0x10, this);

    u32 q = (u32)resource;
    s32 v4b = 1, v5b = 1, v6b = 1, v7b = 1, v8b = 1, v9b = 1;
    u32 t10 = q & 0xFF000000;
    if ((t10 != 0x80000000U) &&
        ((q & 0xFF800000U) != 0x81000000U))
        v9b = 0;
    if ((v9b == 0) && ((q & 0xF8000000U) != 0x90000000U))
        v8b = 0;
    if ((v8b == 0) && (t10 != 0xC0000000U))
        v7b = 0;
    if ((v7b == 0) && ((q & 0xFF800000U) != 0xC1000000U))
        v6b = 0;
    if ((v6b == 0) && ((q & 0xF8000000U) != 0xD0000000U))
        v5b = 0;
    if ((v5b == 0) && ((q & 0xFFFFC000U) != 0xE0000000U))
        v4b = 0;
    if (v4b == 0)
        ((void (*)(const char*, int, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(file, 0x62, file + 0x48, resource);
    if (q & 0x1F)
        ((void (*)(const char*, int, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(file, 0x63, file + 0x80, resource);

    s32 existing = *(s32*)((u8*)this + 0x10);
    void* info = 0;
    if (existing != 0) {
        ((void (*)(const char*, int, const char*, ...))Warning__Q26nw4hbm2dbFPCciPCce)(file, 0x6B, file + 0xCC);
        return false;
    }
    if (*(u32*)resource == 0x52464E55) {
        u8* block = (u8*)resource + *(u16*)((u8*)resource + 0xC);
        s32 i = 0;
        while (i < (s32)*(u16*)((u8*)resource + 0xE)) {
            s32 a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
            u32 r = (u32)block;
            u32 t = r & 0xFF000000;
            if ((t != 0x80000000U) &&
                ((r & 0xFF800000U) != 0x81000000U))
                f = 0;
            if ((f == 0) && ((r & 0xF8000000U) != 0x90000000U))
                e = 0;
            if ((e == 0) && (t != 0xC0000000U))
                d = 0;
            if ((d == 0) && ((r & 0xFF800000U) != 0xC1000000U))
                c = 0;
            if ((c == 0) && ((r & 0xF8000000U) != 0xD0000000U))
                b = 0;
            if ((b == 0) && ((r & 0xFFFFC000U) != 0xE0000000U))
                a = 0;
            if (a == 0)
                ((void (*)(const char*, int, const char*, ...))Panic__Q26nw4hbm2dbFPCciPCce)(file, 0x7C, file + 0xEC, block);
            if (*(u32*)block == 0x46494E46) {
                info = block + 8;
                break;
            }
            ++i;
            block += *(u32*)(block + 4);
        }
    } else {
        u16 version = *(u16*)((u8*)resource + 6);
        if (version == 0x104) {
            if (IsValidBinaryFile__Q26nw4hbm2utFPCQ36nw4hbm2ut16BinaryFileHeaderUlUsUs(
                    resource, 0x52464E54, 0x104, 2) == 0) {
                ((void (*)(const char*, int, const char*, ...))Warning__Q26nw4hbm2dbFPCciPCce)(file, 0x96, file + 0x128);
                return false;
            }
        } else if (IsValidBinaryFile__Q26nw4hbm2utFPCQ36nw4hbm2ut16BinaryFileHeaderUlUsUs(
                       resource, 0x52464E54, 0x102, 2) == 0) {
            ((void (*)(const char*, int, const char*, ...))Warning__Q26nw4hbm2dbFPCciPCce)(file, 0xA0, file + 0x128);
            return false;
        }
        info = Rebuild__Q36nw4hbm2ut7ResFontFPQ36nw4hbm2ut16BinaryFileHeader(resource);
    }
    if (info == 0)
        return false;
    SetResourceBuffer__Q46nw4hbm2ut6detail11ResFontBaseFPvPQ36nw4hbm2ut15FontInformation(this, resource, info);
    InitReaderFunc__Q36nw4hbm2ut4FontFQ36nw4hbm2ut12FontEncoding(this, GetEncoding());
    return true;
}
#pragma pop
extern "C" void* memcpy(void*, const void*, unsigned long);
#pragma push
#pragma scheduling off
extern "C" void* fn_80108FFC(void* arg0, const void* arg1) {
    struct Struct12 {
        u32 a, b, c;
    };
    *(const void* volatile*)arg0 = lbl_80329400;
    *(Struct12*)((char*)arg0 + 4) = *(const Struct12*)(const void*)lbl_80329140;
    *(const void**)arg0 = lbl_803293A8;
    *(u32*)((char*)arg0 + 0x10) = 0;
    *(u32*)((char*)arg0 + 0x14) = 0;
    return arg0;
}
#pragma pop
extern "C" s32 fn_80109040(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void SetResourceBuffer__Q46nw4hbm2ut6detail11ResFontBaseFPvPQ36nw4hbm2ut15FontInformation(void* self, void* resource, void* info) {
    const char* file = lbl_80329140;
    u32 address = (u32)resource;
    u32 infoAddress = (u32)info;
    u32 valid = 1;
    if ((address & 0xFF000000) != 0x80000000 &&
        (address & 0xFF800000) != 0x81000000)
        valid = 0;
    if (valid == 0 && (address & 0xF8000000) != 0x78000000)
        valid = 1;
    if (valid == 0 && (address & 0xFF000000) != 0x40000000)
        valid = 1;
    if (valid == 0 && (address & 0xFF800000) != 0xC1000000)
        valid = 1;
    if (valid == 0 && (address & 0xF8000000) != 0xD0000000)
        valid = 1;
    if (valid == 0 && (address & 0xFFFFC000) != 0xE0000000)
        valid = 1;
    if (valid == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x4F, file + 0x20, resource);

    valid = 1;
    if ((infoAddress & 0xFF000000) != 0x80000000 &&
        (infoAddress & 0xFF800000) != 0x81000000)
        valid = 0;
    if (valid == 0 && (infoAddress & 0xF8000000) != 0x78000000)
        valid = 1;
    if (valid == 0 && (infoAddress & 0xFF000000) != 0x40000000)
        valid = 1;
    if (valid == 0 && (infoAddress & 0xFF800000) != 0xC1000000)
        valid = 1;
    if (valid == 0 && (infoAddress & 0xF8000000) != 0xD0000000)
        valid = 1;
    if (valid == 0 && (infoAddress & 0xFFFFC000) != 0xE0000000)
        valid = 1;
    if (valid == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x50, file + 0x5C, info);
    if (*(void**)((char*)self + 0x10) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x51, file + 0x98);
    if (*(void**)((char*)self + 0x14) != 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x52, file + 0xC4);
    *(void**)((char*)self + 0x10) = resource;
    *(void**)((char*)self + 0x14) = info;
}

s32 nw4hbm::ut::detail::ResFontBase::GetDescent() const {
    const u32 value = (u32)this;
    const u32 data = *(const u32*)(value + 0x14);
    if (((value & 0xFF000000) + 0x80000000 != 0) &&
        ((value & 0xFF800000) + 0x7F000000 != 0) &&
        ((value & 0xF8000000) + 0x70000000 != 0) &&
        ((value & 0xFF000000) + 0x40000000 != 0) &&
        ((value & 0xFF800000) + 0x3F000000 != 0) &&
        ((value & 0xF8000000) + 0x30000000 != 0) &&
        ((value & 0xFFFFC000) + 0x20000000 != 0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140 + 0xC, 0xB3, lbl_80329140 + 0xF0, this);
    }
    if (((data & 0xFF000000) + 0x80000000 != 0) &&
        ((data & 0xFF800000) + 0x7F000000 != 0) &&
        ((data & 0xF8000000) + 0x70000000 != 0) &&
        ((data & 0xFF000000) + 0x40000000 != 0) &&
        ((data & 0xFF800000) + 0x3F000000 != 0) &&
        ((data & 0xF8000000) + 0x30000000 != 0) &&
        ((data & 0xFFFFC000) + 0x20000000 != 0)) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140 + 0xC, 0xB4, lbl_80329140 + 0x128);
    }
    return ((u8*)data)[0x14] - ((u8*)data)[0x16];
}

s8 nw4hbm::ut::detail::ResFontBase::GetBaselinePos() const {
    const char* file=lbl_80329140;
    u32 value=(u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    if ((u32)((value&0xFF000000U)+0x80000000U)!=0U && (u32)((value&0xFF800000U)+0x7F000000U)!=0U) f=0;
    if (f==0 && (u32)((value&0xF8000000U)+0x70000000U)!=0U)e=0;
    if (e==0 && (u32)((value&0xFF000000U)+0x40000000U)!=0U)d=0;
    if (d==0 && (u32)((value&0xFF800000U)+0x3F000000U)!=0U)c=0;
    if (c==0 && (u32)((value&0xF8000000U)+0x30000000U)!=0U)b=0;
    if (b==0 && (u32)((value&0xFFFFC000U)+0x20000000U)!=0U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xC4,file+0xF0,this);
    u32 v=*(u32*)((char*)this+0x14);
    int g=1,h=1,i=1,j=1,k=1,l=1;
    if((u32)((v&0xFF000000U)+0x80000000U)!=0U&&(u32)((v&0xFF800000U)+0x7F000000U)!=0U)l=0;
    if(l==0&&(u32)((v&0xF8000000U)+0x70000000U)!=0U)k=0;
    if(k==0&&(u32)((v&0xFF000000U)+0x40000000U)!=0U)j=0;
    if(j==0&&(u32)((v&0xFF800000U)+0x3F000000U)!=0U)i=0;
    if(i==0&&(u32)((v&0xF8000000U)+0x30000000U)!=0U)h=0;
    if(h==0&&(u32)((v&0xFFFFC000U)+0x20000000U)!=0U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xC5,file+0x128);
    return *(s8*)(*(u32*)((char*)v+8)+2);
}

extern "C" u8 GetCellHeight__Q46nw4hbm2ut6detail11ResFontBaseCFv_80109F24(void* self) {
    const char* file = lbl_80329140;
    u32 value = (u32)self;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    if ((u32)((value & 0xFF000000U) + 0x80000000U) != 0U && (u32)((value & 0xFF800000U) + 0x7F000000U) != 0U) f=0;
    if (f==0 && (u32)((value & 0xF8000000U) + 0x70000000U) != 0U) e=0;
    if (e==0 && (u32)((value & 0xFF000000U) + 0x40000000U) != 0U) d=0;
    if (d==0 && (u32)((value & 0xFF800000U) + 0x3F000000U) != 0U) c=0;
    if (c==0 && (u32)((value & 0xF8000000U) + 0x30000000U) != 0U) b=0;
    if (b==0 && (u32)((value & 0xFFFFC000U) + 0x20000000U) != 0U) a=0;
    if (a==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xE6,file+0xF0,self);
    u32 v=*(u32*)((char*)self+0x14);
    int g=1,h=1,i=1,j=1,k=1,l=1;
    if ((u32)((v&0xFF000000U)+0x80000000U)!=0U && (u32)((v&0xFF800000U)+0x7F000000U)!=0U) l=0;
    if (l==0 && (u32)((v&0xF8000000U)+0x70000000U)!=0U) k=0;
    if (k==0 && (u32)((v&0xFF000000U)+0x40000000U)!=0U) j=0;
    if (j==0 && (u32)((v&0xFF800000U)+0x3F000000U)!=0U) i=0;
    if (i==0 && (u32)((v&0xF8000000U)+0x30000000U)!=0U) h=0;
    if (h==0 && (u32)((v&0xFFFFC000U)+0x20000000U)!=0U) g=0;
    if (g==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xE7,file+0x128);
    return *(u8*)*(u32*)((char*)v+8);
}

extern "C" u8 GetCellHeight__Q46nw4hbm2ut6detail11ResFontBaseCFv_8010A130(void* self) {
    const char* file = lbl_80329140;
    u32 value = (u32)self;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    if ((u32)((value & 0xFF000000U) + 0x80000000U) != 0U && (u32)((value & 0xFF800000U) + 0x7F000000U) != 0U) f=0;
    if (f==0 && (u32)((value & 0xF8000000U) + 0x70000000U) != 0U) e=0;
    if (e==0 && (u32)((value & 0xFF000000U) + 0x40000000U) != 0U) d=0;
    if (d==0 && (u32)((value & 0xFF800000U) + 0x3F000000U) != 0U) c=0;
    if (c==0 && (u32)((value & 0xF8000000U) + 0x30000000U) != 0U) b=0;
    if (b==0 && (u32)((value & 0xFFFFC000U) + 0x20000000U) != 0U) a=0;
    if (a==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xF7,file+0xF0,self);
    u32 v=*(u32*)((char*)self+0x14);
    int g=1,h=1,i=1,j=1,k=1,l=1;
    if ((u32)((v&0xFF000000U)+0x80000000U)!=0U && (u32)((v&0xFF800000U)+0x7F000000U)!=0U) l=0;
    if (l==0 && (u32)((v&0xF8000000U)+0x70000000U)!=0U) k=0;
    if (k==0 && (u32)((v&0xFF000000U)+0x40000000U)!=0U) j=0;
    if (j==0 && (u32)((v&0xFF800000U)+0x3F000000U)!=0U) i=0;
    if (i==0 && (u32)((v&0xF8000000U)+0x30000000U)!=0U) h=0;
    if (h==0 && (u32)((v&0xFFFFC000U)+0x20000000U)!=0U) g=0;
    if (g==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xF8,file+0x128);
    return *(u8*)(*(u32*)((char*)v+8)+3);
}

extern "C" u8 fn_8010A33C(void) {
    return 2;
}

u16 nw4hbm::ut::detail::ResFontBase::GetTextureFormat() const {
    const char* file = lbl_80329140;
    u32 value = (u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    if ((u32)((value & 0xFF000000U) + 0x80000000U) != 0U && (u32)((value & 0xFF800000U) + 0x7F000000U) != 0U) f=0;
    if (f==0 && (u32)((value & 0xF8000000U) + 0x70000000U) != 0U) e=0;
    if (e==0 && (u32)((value & 0xFF000000U) + 0x40000000U) != 0U) d=0;
    if (d==0 && (u32)((value & 0xFF800000U) + 0x3F000000U) != 0U) c=0;
    if (c==0 && (u32)((value & 0xF8000000U) + 0x30000000U) != 0U) b=0;
    if (b==0 && (u32)((value & 0xFFFFC000U) + 0x20000000U) != 0U) a=0;
    if (a==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x117,file+0xF0,this);
    u32 v=*(u32*)((char*)this+0x14);
    int g=1,h=1,i=1,j=1,k=1,l=1;
    if ((u32)((v&0xFF000000U)+0x80000000U)!=0U && (u32)((v&0xFF800000U)+0x7F000000U)!=0U) l=0;
    if (l==0 && (u32)((v&0xF8000000U)+0x70000000U)!=0U) k=0;
    if (k==0 && (u32)((v&0xFF000000U)+0x40000000U)!=0U) j=0;
    if (j==0 && (u32)((v&0xFF800000U)+0x3F000000U)!=0U) i=0;
    if (i==0 && (u32)((v&0xF8000000U)+0x30000000U)!=0U) h=0;
    if (h==0 && (u32)((v&0xFFFFC000U)+0x20000000U)!=0U) g=0;
    if (g==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x118,file+0x128);
    return *(u16*)(*(u32*)((char*)v+8)+0xA);
}

s8 nw4hbm::ut::detail::ResFontBase::GetLineFeed() const {
    const char* file = lbl_80329140;
    u32 value = (u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    if ((u32)((value & 0xFF000000U)+0x80000000U)!=0U && (u32)((value & 0xFF800000U)+0x7F000000U)!=0U) f=0;
    if (f==0 && (u32)((value&0xF8000000U)+0x70000000U)!=0U)e=0;
    if (e==0 && (u32)((value&0xFF000000U)+0x40000000U)!=0U)d=0;
    if (d==0 && (u32)((value&0xFF800000U)+0x3F000000U)!=0U)c=0;
    if (c==0 && (u32)((value&0xF8000000U)+0x30000000U)!=0U)b=0;
    if (b==0 && (u32)((value&0xFFFFC000U)+0x20000000U)!=0U)a=0;
    if (a==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x128,file+0xF0,this);
    u32 v=*(u32*)((char*)this+0x14);
    int g=1,h=1,i=1,j=1,k=1,l=1;
    if ((u32)((v&0xFF000000U)+0x80000000U)!=0U && (u32)((v&0xFF800000U)+0x7F000000U)!=0U) l=0;
    if (l==0 && (u32)((v&0xF8000000U)+0x70000000U)!=0U) k=0;
    if (k==0 && (u32)((v&0xFF000000U)+0x40000000U)!=0U) j=0;
    if (j==0 && (u32)((v&0xFF800000U)+0x3F000000U)!=0U) i=0;
    if (i==0 && (u32)((v&0xF8000000U)+0x30000000U)!=0U) h=0;
    if (h==0 && (u32)((v&0xFFFFC000U)+0x20000000U)!=0U) g=0;
    if (g==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x129,file+0x128);
    return *(s8*)(*(u32*)((char*)v+8)+1);
}

s32 nw4hbm::ut::detail::ResFontBase::GetDefaultCharWidths() const {
    const char* file=lbl_80329140;
    u32 value=(u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    if ((u32)((value&0xFF000000U)+0x80000000U)!=0U && (u32)((value&0xFF800000U)+0x7F000000U)!=0U)f=0;
    if(f==0&&(u32)((value&0xF8000000U)+0x70000000U)!=0U)e=0;
    if(e==0&&(u32)((value&0xFF000000U)+0x40000000U)!=0U)d=0;
    if(d==0&&(u32)((value&0xFF800000U)+0x3F000000U)!=0U)c=0;
    if(c==0&&(u32)((value&0xF8000000U)+0x30000000U)!=0U)b=0;
    if(b==0&&(u32)((value&0xFFFFC000U)+0x20000000U)!=0U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x139,file+0xF0,this);
    u32 v=*(u32*)((char*)this+0x14);
    int g=1,h=1,i=1,j=1,k=1,l=1;
    if((u32)((v&0xFF000000U)+0x80000000U)!=0U&&(u32)((v&0xFF800000U)+0x7F000000U)!=0U)l=0;
    if(l==0&&(u32)((v&0xF8000000U)+0x70000000U)!=0U)k=0;
    if(k==0&&(u32)((v&0xFF000000U)+0x40000000U)!=0U)j=0;
    if(j==0&&(u32)((v&0xFF800000U)+0x3F000000U)!=0U)i=0;
    if(i==0&&(u32)((v&0xF8000000U)+0x30000000U)!=0U)h=0;
    if(h==0&&(u32)((v&0xFFFFC000U)+0x20000000U)!=0U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x13A,file+0x128);
    u32 p=*(u32*)((char*)v+8);
    return (*(u16*)((char*)v+4)<<16) | (*(u8*)((char*)v+6)<<8);
}

void nw4hbm::ut::detail::ResFontBase::SetDefaultCharWidths(const CharWidths& widths) {
    const char* base = lbl_80329140;
    register int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    register u32 address = (u32)this;
    register u32 top = address & 0xFF000000U;
    if ((u32)(top + 0x80000000U) >= 1U && (u32)((address & 0xFF800000U) + 0x7F000000U) >= 1U) r10 = 0;
    if (r10 == 0 && (u32)((address & 0xF8000000U) + 0x70000000U) >= 1U) r9 = 0;
    if (r9 == 0 && (u32)(top + 0x40000000U) >= 1U) r8 = 0;
    if (r8 == 0 && (u32)((address & 0xFF800000U) + 0x3F000000U) >= 1U) r7 = 0;
    if (r7 == 0 && (u32)((address & 0xF8000000U) + 0x30000000U) >= 1U) r6 = 0;
    if (r6 == 0 && (u32)((address & 0xFFFFC000U) + 0x20000000U) >= 1U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0xC, 0x14A, base + 0xF0, this);

    {
        register int v4 = 1, v5 = 1;
        register u32 data = *(u32*)((char*)this + 0x14);
        register int v7 = 1, v8 = 1, v9 = 1, v10 = 1;
        register u32 top2 = data & 0xFF000000U;
        if ((u32)(top2 + 0x80000000U) >= 1U && (u32)((data & 0xFF800000U) + 0x7F000000U) >= 1U) v10 = 0;
        if (v10 == 0 && (u32)((data & 0xF8000000U) + 0x70000000U) >= 1U) v9 = 0;
        if (v9 == 0 && (u32)(top2 + 0x40000000U) >= 1U) v8 = 0;
        if (v8 == 0 && (u32)((data & 0xFF800000U) + 0x3F000000U) >= 1U) v7 = 0;
        if (v7 == 0 && (u32)((data & 0xF8000000U) + 0x30000000U) >= 1U) v5 = 0;
        if (v5 == 0 && (u32)((data & 0xFFFFC000U) + 0x20000000U) >= 1U) v4 = 0;
        if (v4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0xC, 0x14B, base + 0x128);
    }

    {
        register int w4 = 1, w5 = 1, w6 = 1, w7 = 1, w8 = 1, w9 = 1;
        register u32 address3 = (u32)&widths;
        register u32 top3 = address3 & 0xFF000000U;
        if ((u32)(top3 + 0x80000000U) >= 1U && (u32)((address3 & 0xFF800000U) + 0x7F000000U) >= 1U) w9 = 0;
        if (w9 == 0 && (u32)((address3 & 0xF8000000U) + 0x70000000U) >= 1U) w8 = 0;
        if (w8 == 0 && (u32)(top3 + 0x40000000U) >= 1U) w7 = 0;
        if (w7 == 0 && (u32)((address3 & 0xFF800000U) + 0x3F000000U) >= 1U) w6 = 0;
        if (w6 == 0 && (u32)((address3 & 0xF8000000U) + 0x30000000U) >= 1U) w5 = 0;
        if (w5 == 0 && (u32)((address3 & 0xFFFFC000U) + 0x20000000U) >= 1U) w4 = 0;
        if (w4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0xC, 0x14C, base + 0x164, &widths);
    }

    u32 data = *(u32*)((char*)this + 0x14);
    ((u8*)data)[4] = ((const u8*)&widths)[0];
    ((u8*)data)[5] = ((const u8*)&widths)[1];
    ((u8*)data)[6] = ((const u8*)&widths)[2];
}

extern "C" u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void *, void *, u16);
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 SetAlternateChar__Q46nw4hbm2ut6detail11ResFontBaseFUs(void *self, u16 code) {
    const char *file = lbl_80329140;
    register u32 top = (u32)self & 0xFF000000U;
    {
        register int r5=1, r6=1, r7=1, r8=1, r9=1, r10=1;
        if ((u32)(top+0x80000000U)<=0U) goto skip_first_0;
        if ((u32)(((u32)self&0xFF800000U)+0x7F000000U)<=0U) goto skip_first_0;
        r10=0;
skip_first_0: ;
        if (r10==0) {
            if ((u32)(((u32)self&0xF8000000U)+0x70000000U)<=0U) goto skip_next_3;
            r9=0;
        }
skip_next_3: ;
        if (r9==0) {
            if ((u32)(top+0x40000000U)<=0U) goto skip_next_4;
            r8=0;
        }
skip_next_4: ;
        if (r8==0) {
            if ((u32)(((u32)self&0xFF800000U)+0x3F000000U)<=0U) goto skip_next_5;
            r7=0;
        }
skip_next_5: ;
        if (r7==0) {
            if ((u32)(((u32)self&0xF8000000U)+0x30000000U)<=0U) goto skip_next_6;
            r6=0;
        }
skip_next_6: ;
        if (r6==0) {
            if ((u32)(((u32)self&0xFFFFC000U)+0x20000000U)<=0U) goto skip_next_7;
            r5=0;
        }
skip_next_7: ;
        if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x15E,file+0xF0,self);
    }
    register u8 *info;
    {
        register int r4=1, r5=1;
        info=*(u8**)((u8*)self+0x14);
        register int r7=1;
        register int r8=1, r9=1, r10=1;
        register u32 infoTop=(u32)info&0xFF000000U;
        if ((u32)(infoTop+0x80000000U)<=0U) goto skip_first_1;
        if ((u32)(((u32)info&0xFF800000U)+0x7F000000U)<=0U) goto skip_first_1;
        r10=0;
skip_first_1: ;
        if (r10==0) {
            if ((u32)(((u32)info&0xF8000000U)+0x70000000U)<=0U) goto skip_next_8;
            r9=0;
        }
skip_next_8: ;
        if (r9==0) {
            if ((u32)(infoTop+0x40000000U)<=0U) goto skip_next_9;
            r8=0;
        }
skip_next_9: ;
        if (r8==0) {
            if ((u32)(((u32)info&0xFF800000U)+0x3F000000U)<=0U) goto skip_next_10;
            r7=0;
        }
skip_next_10: ;
        if (r7==0) {
            if ((u32)(((u32)info&0xF8000000U)+0x30000000U)<=0U) goto skip_next_11;
            r5=0;
        }
skip_next_11: ;
        if (r5==0 && (u32)(((u32)info&0xFFFFC000U)+0x20000000U)>0U) r4=0;
        if (r4==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x15F,file+0x128);
    }
    {
        register int valid=0;
        u32 p=(u32)self, part1, part2;
        if ((u32)(top+0x80000000U)<=0U ||
            ((part1=p&0xFF800000U),(u32)(part1+0x7F000000U)<=0U) ||
            ((part2=p&0xF8000000U),(u32)(part2+0x70000000U)<=0U) ||
            (u32)(top+0x40000000U)<=0U ||
            (u32)(part1+0x3F000000U)<=0U ||
            (u32)(part2+0x30000000U)<=0U ||
            (u32)((p&0xFFFFC000U)+0x20000000U)<=0U) valid=1;
        if (valid==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x1F6,file+0xF0,self);
    }
    {
        register int r4=1, r5=1;
        info=*(u8**)((u8*)self+0x14);
        register int r7=1;
        register int r8=1, r9=1, r10=1;
        register u32 infoTop=(u32)info&0xFF000000U;
        if ((u32)(infoTop+0x80000000U)<=0U) goto skip_first_2;
        if ((u32)(((u32)info&0xFF800000U)+0x7F000000U)<=0U) goto skip_first_2;
        r10=0;
skip_first_2: ;
        if (r10==0) {
            if ((u32)(((u32)info&0xF8000000U)+0x70000000U)<=0U) goto skip_next_12;
            r9=0;
        }
skip_next_12: ;
        if (r9==0) {
            if ((u32)(infoTop+0x40000000U)<=0U) goto skip_next_13;
            r8=0;
        }
skip_next_13: ;
        if (r8==0) {
            if ((u32)(((u32)info&0xFF800000U)+0x3F000000U)<=0U) goto skip_next_14;
            r7=0;
        }
skip_next_14: ;
        if (r7==0) {
            if ((u32)(((u32)info&0xF8000000U)+0x30000000U)<=0U) goto skip_next_15;
            r5=0;
        }
skip_next_15: ;
        if (r5==0 && (u32)(((u32)info&0xFFFFC000U)+0x20000000U)>0U) r4=0;
        if (r4==0) Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x1F7,file+0x128);
    }
    register u8 *map=*(u8**)(*(u8**)((u8*)self+0x14)+0x10);
    register u16 index;
    while (map!=0) {
        if (*(u16*)map<=code && code<=*(u16*)(map+2)) {
            index=::FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(self,map,code);
            goto checkIndex;
        }
        map=*(u8**)(map+8);
    }
    index=0xFFFF;
checkIndex:
    if (index!=0xFFFF) {
        *(u16*)(*(u8**)((u8*)self+0x14)+2)=index;
        return 1;
    }
    return 0;
}
#pragma pop

void nw4hbm::ut::detail::ResFontBase::SetLineFeed(int lineFeed) {
    u32 p = (u32)this;
    int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
    if ((u32)((p & 0xFF000000) + 0x80000000) != 0 && (u32)((p & 0xFF800000) + 0x7F000000) != 0) a = 0;
    if (a == 0 && (u32)((p & 0xF8000000) + 0x70000000) != 0) b = 0;
    if (b == 0 && (u32)((p & 0xFF000000) + 0x40000000) != 0) c = 0;
    if (c == 0 && (u32)((p & 0xFF800000) + 0x3F000000) != 0) d = 0;
    if (d == 0 && (u32)((p & 0xF8000000) + 0x30000000) != 0) e = 0;
    if (e == 0 && (u32)((p & 0xFFFFC000) + 0x20000000) != 0) f = 0;
    if (f == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140 + 0xC, 0x177, lbl_80329140 + 0xF0, this);
    s32* field = (s32*)((char*)this + 0x14);
    p = (u32)*field;
    a = b = c = d = e = f = 1;
    if ((u32)((p & 0xFF000000) + 0x80000000) != 0 && (u32)((p & 0xFF800000) + 0x7F000000) != 0) a = 0;
    if (a == 0 && (u32)((p & 0xF8000000) + 0x70000000) != 0) b = 0;
    if (b == 0 && (u32)((p & 0xFF000000) + 0x40000000) != 0) c = 0;
    if (c == 0 && (u32)((p & 0xFF800000) + 0x3F000000) != 0) d = 0;
    if (d == 0 && (u32)((p & 0xF8000000) + 0x30000000) != 0) e = 0;
    if (e == 0 && (u32)((p & 0xFFFFC000) + 0x20000000) != 0) f = 0;
    if (f == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140 + 0xC, 0x178, lbl_80329140 + 0x128);
    if (lineFeed < -128 || lineFeed > 127)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140 + 0xC, 0x179, lbl_80329140 + 0x1A0, lineFeed, -128, 127);
    *(s8*)((char*)*field + 1) = lineFeed;
}

extern "C" s8 fn_8010B2BC(void *arg0) {
    struct V { virtual u32 a0()=0; virtual u32 a1()=0; virtual u32 a2()=0; virtual u32 a3()=0; virtual u32 a4()=0; virtual u32 a5()=0; virtual u32 a6()=0; virtual u32 a7()=0; virtual u32 a8()=0; virtual u32 a9()=0; virtual u32 a10()=0; virtual u32 a11()=0; virtual u32 a12()=0; virtual u32 a13()=0; virtual u32 a14()=0; virtual u32 a15()=0; virtual u32 a16()=0; virtual u32 f()=0; };
    u32 value = ((V *)arg0)->f();
    volatile u8 c;
    volatile u8 b;
    volatile u8 a;
    a = (u8)(value >> 24);
    b = (u8)(value >> 16);
    c = (u8)(value >> 8);
    return (s8)(value >> 8);
}

extern "C" const char lbl_80329140[];
extern "C" u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void*, void*, u16);
u32 GetCharWidths__Q46nw4hbm2ut6detail11ResFontBaseCFUs(void *self, u16 code) {
    u8 *info, *map, *width, *entry;
    u16 glyph;
    if (!self) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1E2,lbl_80329140+0xF0,self);
    info=*(u8**)((char*)self+0x14);
    if (!info) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1E3,lbl_80329140+0x128);
    if (!self) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1F6,lbl_80329140+0xF0,self);
    if (!info) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x1F7,lbl_80329140+0x128);
    map=*(u8**)(info+0x10);
    while(map && (code<*(u16*)map || code>*(u16*)(map+2))) map=*(u8**)(map+8);
    glyph=map ? FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(self,map,code) : 0xFFFF;
    if(glyph==0xFFFF) glyph=*(u16*)(info+2);
    if (!self) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x267,lbl_80329140+0xF0,self);
    if (!info) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x268,lbl_80329140+0x128);
    width=*(u8**)(info+0xC);
    while(width && (glyph<*(u16*)width || glyph>*(u16*)(width+2))) width=*(u8**)(width+4);
    if(width) entry=width+8+5*(glyph-*(u16*)width);
    else entry=info+4;
    return ((u32)*(u16*)(entry+4)<<16) | ((u32)entry[6]<<8);
}

#pragma push
#pragma use_lmw_stmw off
void nw4hbm::ut::detail::ResFontBase::GetGlyph(nw4hbm::ut::Glyph* glyph, unsigned short code) const {
    const char* file = lbl_80329140;
    register u32 top = (u32)this & 0xFF000000U;
    {
        register int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
        if ((u32)(top + 0x80000000U) >= 1U && (u32)(((u32)this & 0xFF800000U) + 0x7F000000U) >= 1U) r10 = 0;
        if (r10 == 0 && (u32)(((u32)this & 0xF8000000U) + 0x70000000U) >= 1U) r9 = 0;
        if (r9 == 0 && (u32)(top + 0x40000000U) >= 1U) r8 = 0;
        if (r8 == 0 && (u32)(((u32)this & 0xFF800000U) + 0x3F000000U) >= 1U) r7 = 0;
        if (r7 == 0 && (u32)(((u32)this & 0xF8000000U) + 0x30000000U) >= 1U) r6 = 0;
        if (r6 == 0 && (u32)(((u32)this & 0xFFFFC000U) + 0x20000000U) >= 1U) r5 = 0;
        if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1E2, file + 0xF0, this);
    }
    {
        register int r4 = 1, r5 = 1;
        u8* info = *(u8**)((char*)this + 0x14);
        register int r7 = 1;
        register int r8 = 1, r9 = 1, r10 = 1;
        register u32 infoTop = (u32)info & 0xFF000000U;
        if ((u32)(infoTop + 0x80000000U) >= 1U && (u32)(((u32)info & 0xFF800000U) + 0x7F000000U) >= 1U) r10 = 0;
        if (r10 == 0 && (u32)(((u32)info & 0xF8000000U) + 0x70000000U) >= 1U) r9 = 0;
        if (r9 == 0 && (u32)(infoTop + 0x40000000U) >= 1U) r8 = 0;
        if (r8 == 0 && (u32)(((u32)info & 0xFF800000U) + 0x3F000000U) >= 1U) r7 = 0;
        if (r7 == 0 && (u32)(((u32)info & 0xF8000000U) + 0x30000000U) >= 1U) r5 = 0;
        if (r5 == 0 && (u32)(((u32)info & 0xFFFFC000U) + 0x20000000U) >= 1U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1E3, file + 0x128);
    }
    {
        register int valid = 0;
        if ((u32)(top + 0x80000000U) < 1U ||
            (u32)(((u32)this & 0xFF800000U) + 0x7F000000U) < 1U ||
            (u32)(((u32)this & 0xF8000000U) + 0x70000000U) < 1U ||
            (u32)(top + 0x40000000U) < 1U ||
            (u32)(((u32)this & 0xFF800000U) + 0x3F000000U) < 1U ||
            (u32)(((u32)this & 0xF8000000U) + 0x30000000U) < 1U ||
            (u32)(((u32)this & 0xFFFFC000U) + 0x20000000U) < 1U)
            valid = 1;
        if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F6, file + 0xF0, this);
    }
    {
        register int r4 = 1, r5 = 1;
        u8* info = *(u8**)((char*)this + 0x14);
        register int r7 = 1;
        register int r8 = 1, r9 = 1, r10 = 1;
        register u32 infoTop = (u32)info & 0xFF000000U;
        if ((u32)(infoTop + 0x80000000U) >= 1U && (u32)(((u32)info & 0xFF800000U) + 0x7F000000U) >= 1U) r10 = 0;
        if (r10 == 0 && (u32)(((u32)info & 0xF8000000U) + 0x70000000U) >= 1U) r9 = 0;
        if (r9 == 0 && (u32)(infoTop + 0x40000000U) >= 1U) r8 = 0;
        if (r8 == 0 && (u32)(((u32)info & 0xFF800000U) + 0x3F000000U) >= 1U) r7 = 0;
        if (r7 == 0 && (u32)(((u32)info & 0xF8000000U) + 0x30000000U) >= 1U) r5 = 0;
        if (r5 == 0 && (u32)(((u32)info & 0xFFFFC000U) + 0x20000000U) >= 1U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F7, file + 0x128);
    }
    u8* map = *(u8**)(*(u8**)((char*)this + 0x14) + 0x10);
    u16 index;
    while (map != 0) {
        if (*(u16*)map <= code && code <= *(u16*)(map + 2)) {
            index = ::FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs((void*)this, map, code);
            goto check_index;
        }
        map = *(u8**)(map + 8);
    }
    index = 0xFFFF;
check_index:
    index = index != 0xFFFF ? index : *(u16*)(*(u8**)((char*)this + 0x14) + 2);
    GetGlyphFromIndex(glyph, index);
}
#pragma pop

u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void *self, const void *mapArg, u16 code) {
    const u16 *map=(const u16 *)mapArg;
    const char *base=lbl_80329140;
    unsigned int top=(unsigned int)self&0xFF000000U;
    int r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)self&0xFF800000U)+0x7F000000U)!=0U)r10=0;
    if(r10==0&&(unsigned int)(((unsigned int)self&0xF8000000U)+0x70000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)(top+0x40000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(((unsigned int)self&0xFF800000U)+0x3F000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)(((unsigned int)self&0xF8000000U)+0x30000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)(((unsigned int)self&0xFFFFC000U)+0x20000000U)!=0U)r5=0;
    if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(base+0xC,0x21B,base+0xF0,self);
    top=(unsigned int)map&0xFF000000U;
    int r4=1;r5=1;r6=1;r7=1;r8=1;r9=1;
    if((unsigned int)(top+0x80000000U)!=0U&&(unsigned int)(((unsigned int)map&0xFF800000U)+0x7F000000U)!=0U)r9=0;
    if(r9==0&&(unsigned int)(((unsigned int)map&0xF8000000U)+0x70000000U)!=0U)r8=0;
    if(r8==0&&(unsigned int)(top+0x40000000U)!=0U)r7=0;
    if(r7==0&&(unsigned int)(((unsigned int)map&0xFF800000U)+0x3F000000U)!=0U)r6=0;
    if(r6==0&&(unsigned int)(((unsigned int)map&0xF8000000U)+0x30000000U)!=0U)r5=0;
    if(r5==0&&(unsigned int)(((unsigned int)map&0xFFFFC000U)+0x20000000U)!=0U)r4=0;
    if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(base+0xC,0x21C,base+0x21C,map);
    u16 result=0xFFFF;
    switch(map[2]) {
    case 0: result=(u16)(map[6]+(u16)(code-map[0])); break;
    case 1: result=map[6+(u16)(code-map[0])]; break;
    case 2: {
        const u16 *low=map+7;
        const u16 *high=map+6+map[6]*2;
        while(low<=high) {
            const u16 *mid=low+(((high-low)/4+(((high-low)/4)>>31))&~1);
            if(mid[0]<code) low=mid+2;
            else if(code<mid[0]) high=mid-2;
            else {result=mid[1];break;}
        }
        break;
    }
    default: Panic__Q26nw4hbm2dbFPCciPCce(base+0xC,0x255,base+0x254); break;
    }
    return result;
}

#pragma push
#pragma use_lmw_stmw off
void GetGlyphFromIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPQ36nw4hbm2ut5GlyphUs(void *self, void *glyph, u16 index) {
 u32 ptr=(u32)self, idx=index, width,height,x,y; u8 *info,*font,*map,*entry; u32 r4,r5,r6,r7,r8,r9,r10;
 r5=r6=r7=r8=r9=r10=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r10=0;
 if(r10==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r6=0;
 if(r6==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r5=0;
 if(r5==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x29F,lbl_80329140+0xF0,self);
 info=*(u8**)((char*)self+0x14); ptr=(u32)info; r4=r5=r7=r8=r9=r10=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r10=0;
 if(r10==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r5=0;
 if(r5==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r4=0;
 if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x2A0,lbl_80329140+0x128);
 font=*(u8**)(info+8); width=*(u16*)(font+0xC); height=*(u16*)(font+0xE);
 x=*(u8*)font+1; y=font[1]+1;
 *(u32*)glyph=*(u32*)(font+0x14)+(idx/(width*height)) * *(u32*)(font+4);
 x=((idx%(width*height))%width)*x; y=((idx%(width*height))/width)*y;
 ptr=(u32)self;
 if((u32)((ptr&0xFF000000)+0x80000000)==0||(u32)((ptr&0xFF800000)+0x7F000000)==0||(u32)((ptr&0xF8000000)+0x70000000)==0||(u32)((ptr&0xFF000000)+0x40000000)==0||(u32)((ptr&0xFF800000)+0x3F000000)==0||(u32)((ptr&0xF8000000)+0x30000000)==0||(u32)((ptr&0xFFFFC000)+0x20000000)==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x267,lbl_80329140+0xF0,self);
 info=*(u8**)((char*)self+0x14); ptr=(u32)info; r4=r5=r7=r8=r9=r10=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r10=0;
 if(r10==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r5=0;
 if(r5==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r4=0;
 if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x268,lbl_80329140+0x128);
 map=*(u8**)(info+0xC); while(map&&(index<*(u16*)map||index>*(u16*)(map+2)))map=*(u8**)(map+4);
 if(map){entry=map+8+5*(index-*(u16*)map);ptr=(u32)map;r4=r5=r6=r7=r8=r9=1;
 if((u32)((ptr&0xFF000000)+0x80000000)!=0&&(u32)((ptr&0xFF800000)+0x7F000000)!=0)r9=0;
 if(r9==0&&(u32)((ptr&0xF8000000)+0x70000000)!=0)r8=0;
 if(r8==0&&(u32)((ptr&0xFF000000)+0x40000000)!=0)r7=0;
 if(r7==0&&(u32)((ptr&0xFF800000)+0x3F000000)!=0)r6=0;
 if(r6==0&&(u32)((ptr&0xF8000000)+0x30000000)!=0)r5=0;
 if(r5==0&&(u32)((ptr&0xFFFFC000)+0x20000000)!=0)r4=0;
 if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329140+0xC,0x28B,lbl_80329140+0x1E4,map);
 }else entry=info+4;
 ((u8*)glyph)[4]=entry[0];((u8*)glyph)[5]=entry[1];((u8*)glyph)[6]=entry[2];((u8*)glyph)[7]=font[1];
 *(u32*)((char*)glyph+8)=*(u16*)(font+0xA);*(u16*)((char*)glyph+0xC)=*(u16*)(font+0x10);*(u16*)((char*)glyph+0xE)=*(u16*)(font+0x12);
 *(u16*)((char*)glyph+0x10)=x+1;*(u16*)((char*)glyph+0x12)=y+1;
}
#pragma pop
extern "C" void lbl_8032951C(void);
extern "C" void fn_8010C7DC(void **arg0) {
    *arg0 = (void *)&lbl_8032951C;
}

extern "C" s32 fn_8010C7EC(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8010C82C(s32 arg0, s32 arg1, void *arg2) {
 extern const char lbl_80329458[]; extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*,int,const char*,...);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(s32), fn_8010D9E4(s32);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(s32), IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32); extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
 s32 p=(s32)arg2, hi=p&0xFF000000, r4,r5,r6,r7,r8,r9;
 if(arg1>=32) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x55,lbl_80329458+0x18);
 r4=r5=r6=r7=r8=r9=1;
 if ((u32)(hi+0x80000000)<1U && (u32)((p&0xFF800000)+0x7F000000)<1U) r4=0;
 if(r4==0 && (u32)((p&0xF8000000)+0x70000000)<1U) r5=0;
 if(r5==0 && (u32)(hi+0x40000000)<1U) r6=0;
 if(r6==0 && (u32)((p&0xFF800000)+0x3F000000)<1U) r7=0;
 if(r7==0 && (u32)((p&0xF8000000)+0x30000000)<1U) r8=0;
 if(r8==0 && (u32)((p&0xFFFFC000)+0x20000000)<1U) r9=0;
 if(r9==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x56,lbl_80329458+0x40,arg2);
 if(arg1==10) {
 r5=0;
 if((u32)(hi+0x80000000)<1U || (u32)((p&0xFF800000)+0x7F000000)<1U || (u32)((p&0xF8000000)+0x70000000)<1U || (u32)(hi+0x40000000)<1U || (u32)((p&0xFF800000)+0x3F000000)<1U || (u32)((p&0xF8000000)+0x30000000)<1U || (u32)((p&0xFFFFC000)+0x20000000)<1U) r5=1;
 if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xC3,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p; f32 y=*(f32*)(p+8), w=fn_8010D9E4(obj);
 SetCursor__Q36nw4hbm2ut10CharWriterFff(obj,y,GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj)+w); return 3;
 }
 if(arg1==9) {
 r5=0;
 if((u32)(hi+0x80000000)<1U || (u32)((p&0xFF800000)+0x7F000000)<1U || (u32)((p&0xF8000000)+0x70000000)<1U || (u32)(hi+0x40000000)<1U || (u32)((p&0xFF800000)+0x3F000000)<1U || (u32)((p&0xF8000000)+0x30000000)<1U || (u32)((p&0xFFFFC000)+0x20000000)<1U) r5=1;
 if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xD3,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p, font=GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(obj);
 if(font>0) { f32 fw=IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(obj)?GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(obj):GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(obj);
 f32 y=*(f32*)(p+8), step=(f32)font*fw, width=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj)-y;
 s32 n=(s32)(width/step); SetCursorX__Q36nw4hbm2ut10CharWriterFf(obj,y+step*(f32)(n+1)); } return 1;
 } return 0;
}

extern "C" s32 fn_8010CBAC(void *self, void *arg0, s32 arg1, void *arg2) {
 extern const char lbl_80329458[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*,int,const char*,...);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(s32), fn_8010D9E4(s32);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(s32), IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32); extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
 s32 p=(s32)arg0, hi=p&0xFF000000, r4,r5,r6,r7,r8,r9,r10;
 r5=r6=r7=r8=r9=r10=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r10=0;
 if(r10==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r9=0;
 if(r9==0 && (u32)(hi+0x40000000)!=0) r8=0;
 if(r8==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r5=0;
 if(r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x84,lbl_80329458+0x78,arg0);
 if(arg1>=32) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x85,lbl_80329458+0x18);
 p=(s32)arg2; hi=p&0xFF000000; r4=r5=r6=r7=r8=r9=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r9=0;
 if(r9==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r8=0;
 if(r8==0 && (u32)(hi+0x40000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r5=0;
 if(r5==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r4=0;
 if(r4==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x86,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p;
 if(arg1==10) {
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xC3,lbl_80329458+0x40,arg2);
  s32 o=*(s32*)p; f32 y=*(f32*)(p+8), w=fn_8010D9E4(o); SetCursor__Q36nw4hbm2ut10CharWriterFff(o,y,GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(o)+w);
  f32 left=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)arg0=left; f32 right=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj)+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(*(s32*)p);
  f32 t=*(f32*)((char*)arg0+4), b=*(f32*)((char*)arg0+8), x=right-t, z=b-left;
  *(f32*)((char*)arg0+4)=x>=0?t:right; *(f32*)arg0=z>=0?left:b; *(f32*)((char*)arg0+8)=z>=0?b:left; *(f32*)((char*)arg0+12)=x>=0?right:t; return 3;
 }
 if(arg1==9) {
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xD3,lbl_80329458+0x40,arg2);
  s32 font=GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(obj);
  if(font>0) { f32 fw=IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(obj)?GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(obj):GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(obj); f32 y=*(f32*)(p+8), step=(f32)font*fw, width=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj)-y; s32 n=(s32)(width/step); SetCursorX__Q36nw4hbm2ut10CharWriterFf(obj,y+step*(f32)(n+1)); }
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj); *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  f32 t=*(f32*)((char*)arg0+4), left=*(f32*)arg0, right=t+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(obj), b=*(f32*)((char*)arg0+8), y=right-t, x=b-left;
  *(f32*)arg0=x>=0?left:b; *(f32*)((char*)arg0+8)=x>=0?b:left; *(f32*)((char*)arg0+4)=y>=0?t:right; *(f32*)((char*)arg0+12)=y>=0?right:t; return 1;
 }
 return 0;
}

extern "C" void lbl_80329508(void);
extern "C" void fn_8010D0E0(void **arg0) {
    *arg0 = (void *)&lbl_80329508;
}

extern "C" s32 fn_8010D0F0(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8010D4B0(void *self, void *arg0, s32 arg1, void *arg2) {
 extern const char lbl_80329458[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*,int,const char*,...);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32), GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(s32), GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(s32), fn_80111C10(s32);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_801120E8(s32), IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32); extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
 s32 p=(s32)arg2, hi=p&0xFF000000, r4,r5,r6,r7,r8,r9,r10;
 r5=r6=r7=r8=r9=r10=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r10=0;
 if(r10==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r9=0;
 if(r9==0 && (u32)(hi+0x40000000)!=0) r8=0;
 if(r8==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r5=0;
 if(r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x84,lbl_80329458+0x78,arg0);
 if(arg1>=32) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x85,lbl_80329458+0x18);
 p=(s32)arg2; hi=p&0xFF000000; r4=r5=r6=r7=r8=r9=1;
 if((u32)(hi+0x80000000)!=0 && (u32)((p&0xFF800000)+0x7F000000)!=0) r9=0;
 if(r9==0 && (u32)((p&0xF8000000)+0x70000000)!=0) r8=0;
 if(r8==0 && (u32)(hi+0x40000000)!=0) r7=0;
 if(r7==0 && (u32)((p&0xFF800000)+0x3F000000)!=0) r6=0;
 if(r6==0 && (u32)((p&0xF8000000)+0x30000000)!=0) r5=0;
 if(r5==0 && (u32)((p&0xFFFFC000)+0x20000000)!=0) r4=0;
 if(r4==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0x86,lbl_80329458+0x40,arg2);
 s32 obj=*(s32*)p;
 if(arg1==10) {
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xC3,lbl_80329458+0x40,arg2);
  s32 o=*(s32*)p; f32 y=*(f32*)(p+8), w=fn_80111C10(o); SetCursor__Q36nw4hbm2ut10CharWriterFff(o,y,GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(o)+w);
  f32 left=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj);
  *(f32*)arg0=left; f32 right=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj)+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(*(s32*)p);
  f32 t=*(f32*)((char*)arg0+4), b=*(f32*)((char*)arg0+8), x=right-t, z=b-left;
  *(f32*)((char*)arg0+4)=x>=0?t:right; *(f32*)arg0=z>=0?left:b; *(f32*)((char*)arg0+8)=z>=0?b:left; *(f32*)((char*)arg0+12)=x>=0?right:t; return 3;
 }
 if(arg1==9) {
  r5=0; if((u32)(hi+0x80000000)==0 || (u32)((p&0xFF800000)+0x7F000000)==0 || (u32)((p&0xF8000000)+0x70000000)==0 || (u32)(hi+0x40000000)==0 || (u32)((p&0xFF800000)+0x3F000000)==0 || (u32)((p&0xF8000000)+0x30000000)==0 || (u32)((p&0xFFFFC000)+0x20000000)==0) r5=1;
  if(!r5) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329458,0xD3,lbl_80329458+0x40,arg2);
  s32 font=GetFont__Q36nw4hbm2ut10CharWriterCFv_801120E8(obj);
  if(font>0) { f32 fw=IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(obj)?GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(obj):GetFontWidth__Q36nw4hbm2ut10CharWriterCFv(obj); f32 y=*(f32*)(p+8), step=(f32)font*fw, width=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj)-y; s32 n=(s32)(width/step); SetCursorX__Q36nw4hbm2ut10CharWriterFf(obj,y+step*(f32)(n+1)); }
  *(f32*)((char*)arg0+8)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(obj); *(f32*)((char*)arg0+4)=GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(obj);
  f32 t=*(f32*)((char*)arg0+4), left=*(f32*)arg0, right=t+GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801056A4(obj), b=*(f32*)((char*)arg0+8), y=right-t, x=b-left;
  *(f32*)arg0=x>=0?left:b; *(f32*)((char*)arg0+8)=x>=0?b:left; *(f32*)((char*)arg0+4)=y>=0?t:right; *(f32*)((char*)arg0+12)=y>=0?right:t; return 1;
 }
 return 0;
}

extern "C" f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32);
extern "C" s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern "C" f32 fn_8010D9E4(s32 arg0) {
 extern const char lbl_80329560[]; extern const char lbl_80329578[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
 extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
 extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32);
 struct V { virtual u32 a0()=0; virtual u32 a1()=0; virtual u32 a2()=0; virtual u32 a3()=0; virtual u32 a4()=0; virtual u32 a5()=0; virtual u32 a6()=0; virtual u32 a7()=0; virtual u32 a8()=0; virtual u32 a9()=0; virtual u32 a10()=0; virtual u32 f()=0; };
 u8 var_r5=1,var_r6=1,var_r7=1,var_r8=1,var_r9=1,var_r10=1;
 s32 temp_r11=arg0&0xFF000000;
 s32 var_r30;
 if (((u32)(temp_r11+0x80000000U)<1U)&&((u32)((arg0&0xFF800000)+0x7F000000)<1U)) var_r10=0;
 if ((var_r10==0)&&((u32)((arg0&0xF8000000)+0x70000000)<1U)) var_r9=0;
 if ((var_r9==0)&&((u32)(temp_r11+0x40000000U)<1U)) var_r8=0;
 if ((var_r8==0)&&((u32)((arg0&0xFF800000)+0x3F000000)<1U)) var_r7=0;
 if ((var_r7==0)&&((u32)((arg0&0xF8000000)+0x30000000)<1U)) var_r6=0;
 if ((var_r6==0)&&((u32)((arg0&0xFFFFC000)+0x20000000)<1U)) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0xF1,lbl_80329578,arg0);
 V *p=(V*)GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
 var_r30=p?p->f():0;
 return *(f32*)(arg0+0x50)+(f32)var_r30*GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
}

extern "C" const char lbl_80329560[];
extern "C" const char lbl_80329578[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_8010DB5C(s32 arg0) {
    u8 var_r5 = 1, var_r6 = 1, var_r7 = 1, var_r8 = 1, var_r9 = 1, var_r10 = 1;
    u32 temp_r11 = (u32)arg0 & 0xFF000000U;
    if ((((u32)(temp_r11 + 0x80000000U)) >= 1U) && (((u32)((arg0 & 0xFF800000) + 0x7F000000)) >= 1U)) var_r10 = 0;
    if ((var_r10 == 0) && (((u32)((arg0 & 0xF8000000) + 0x70000000)) >= 1U)) var_r9 = 0;
    if ((var_r9 == 0) && (((u32)(temp_r11 + 0x40000000U)) >= 1U)) var_r8 = 0;
    if ((var_r8 == 0) && (((u32)((arg0 & 0xFF800000) + 0x3F000000)) >= 1U)) var_r7 = 0;
    if ((var_r7 == 0) && (((u32)((arg0 & 0xF8000000) + 0x30000000)) >= 1U)) var_r6 = 0;
    if ((var_r6 == 0) && (((u32)((arg0 & 0xFFFFC000) + 0x20000000)) >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560, 0x15A, lbl_80329578, arg0);
    return *(s32 *)(arg0 + 0x54);
}

extern "C" s32 fn_8010E3BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32);
extern s32 IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern f32 lbl_80561178;
extern const char lbl_80329530[],lbl_80329938[],lbl_80329900[],lbl_803298EC[],lbl_803298B4[],lbl_803298A0[],lbl_80329824[],lbl_80320AFC[],lbl_80320AC4[],lbl_80320B48[],lbl_80320B10[];
class Reader { public: s32 cursor; u16 (Reader::*next)(); };
Reader reader;
f32 rect[4];
struct Context { s32 writer,str; f32 x,y; s32 flags; } context;
class Font { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual s32 ascent(); virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual s32 width(u16); };
class Processor { public: virtual void d0(); virtual void d1(); virtual s32 rectCall(f32*,u16,Context*); };

    s32 temp_r24;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    s32 var_r9;
    s32 var_r10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f28;
    f32 temp_f29;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f31;
    s32 temp_r25;
    s32 temp_r26;
    s32 temp_r29;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r4_5;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r14;
    s32 var_r19;
    s32 var_r20;
    s32 var_r20_2;
    s32 var_r30;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r5_8;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u16 var_r27;
    u32 temp_r31;
    void **temp_r3_8;































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r14;
    s32 temp_r20;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    char *base = (char *)lbl_80329530;

    temp_r24 = arg0 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32) (temp_r24) != 0x80000000U) && ((u32) ((arg0 & 0xFF800000)) != 0x81000000U)) {
        var_r10 = 0;
    }
    if ((var_r10 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0x90000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32) (temp_r24) != 0xC0000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32) ((arg0 & 0xFF800000)) != 0xC1000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0xD0000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32) ((arg0 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5 = 0;
    }
    if (var_r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37D, base + 0x48, arg0);
    }
    temp_r10 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32) (temp_r10) != 0x80000000U) && ((u32) ((arg1 & 0xFF800000)) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32) (temp_r10) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32) ((arg1 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32) ((arg1 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37E, base + 0xF8, arg1);
    }
    temp_r14 = arg2 & 0xFF000000;
    var_r4_2 = 1;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32) (temp_r14) != 0x80000000U) && ((u32) ((arg2 & 0xFF800000)) != 0x81000000U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0x90000000U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32) (temp_r14) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) ((arg2 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) ((arg2 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37F, base + 0x130, arg2);
    }
    if (arg3 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x380, base + 0x168, arg3, 0);
    }
    context.writer = arg0;
    context.str = arg2;
    context.flags = 0;
    *(u32*)((u8*)&context + 8) = 0;
    *(u32*)((u8*)&context + 12) = 0;
    temp_r3 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    temp_r11 = temp_r3 & 0xFF000000;
    var_f31 = lbl_80561178;
    var_r19 = 0;
    var_r5_4 = 1;
    var_r6_4 = 1;
    var_r7_4 = 1;
    var_r8_4 = 1;
    var_r9_4 = 1;
    var_r10_2 = 1;
    if (((u32) (temp_r11) != 0x80000000U) && ((u32) ((temp_r3 & 0xFF800000)) != 0x81000000U)) {
        var_r10_2 = 0;
    }
    if ((var_r10_2 == 0) && ((u32) ((temp_r3 & 0xF8000000)) != 0x90000000U)) {
        var_r9_4 = 0;
    }
    if ((var_r9_4 == 0) && ((u32) (temp_r11) != 0xC0000000U)) {
        var_r8_4 = 0;
    }
    if ((var_r8_4 == 0) && ((u32) ((temp_r3 & 0xFF800000)) != 0xC1000000U)) {
        var_r7_4 = 0;
    }
    if ((var_r7_4 == 0) && ((u32) ((temp_r3 & 0xF8000000)) != 0xD0000000U)) {
        var_r6_4 = 0;
    }
    if ((var_r6_4 == 0) && ((u32) ((temp_r3 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r5_4 = 0;
    }
    if (var_r5_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x386, base + 0x20C, temp_r3);
    }
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, temp_r3);
    var_r5_5 = 0;
    *(f32*)(arg1 + 0) = (f32) lbl_80561178;
    *(f32*)(arg1 + 8) = (f32) lbl_80561178;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4 = arg0 & 0xFF800000, (((u32) (temp_r4) == 0x81000000U) != 0)) || (temp_r3_2 = arg0 & 0xF8000000, (((u32) (temp_r3_2) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4) == 0xC1000000U) || ((u32) (temp_r3_2) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_5 = 1;
    }
    if (var_r5_5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_3 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_3 != 0) {
        var_r20 = ((Font*)temp_r3_3)->ascent();
    } else {
        var_r20 = 0;
    }
    var_f1 = *(f32*)(arg0 + 0x50) + ((f32) var_r20 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    var_f1 = (lbl_80561178 > var_f1) ? var_f1 : lbl_80561178;
    *(f32*)(arg1 + 4) = var_f1;
    var_r5_6 = 0;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4_2 = arg0 & 0xFF800000, (((u32) (temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_4 = arg0 & 0xF8000000, (((u32) (temp_r3_4) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4_2) == 0xC1000000U) || ((u32) (temp_r3_4) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_6 = 1;
    }
    if (var_r5_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_5 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_5 != 0) {
        var_r20_2 = ((Font*)temp_r3_5)->ascent();
    } else {
        var_r20_2 = 0;
    }
    var_f1_2 = *(f32*)(arg0 + 0x50) + ((f32) var_r20_2 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    var_f1_2 = (lbl_80561178 < var_f1_2) ? var_f1_2 : lbl_80561178;
    *(f32*)(arg1 + 0xC) = var_f1_2;
    temp_r23 = (s32) &reader.cursor & 0xFF000000;
    var_r4_3 = 1;
    var_r5_7 = 1;
    var_r6_5 = 1;
    var_r7_5 = 1;
    var_r8_5 = 1;
    var_r9_5 = 1;
    if (((u32) (temp_r23) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0x81000000U)) {
        var_r9_5 = 0;
    }
    if ((var_r9_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0x90000000U)) {
        var_r8_5 = 0;
    }
    if ((var_r8_5 == 0) && ((u32) (temp_r23) != 0xC0000000U)) {
        var_r7_5 = 0;
    }
    if ((var_r7_5 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0xC1000000U)) {
        var_r6_5 = 0;
    }
    if ((var_r6_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0xD0000000U)) {
        var_r5_7 = 0;
    }
    if ((var_r5_7 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_3 = 0;
    }
    if (var_r4_3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
    }
    var_r5_8 = 0;
    if (((u32) (temp_r14) == 0x80000000U) || (temp_r4_3 = arg2 & 0xFF800000, (((u32) (temp_r4_3) == 0x81000000U) != 0)) || (temp_r3_6 = arg2 & 0xF8000000, (((u32) (temp_r3_6) == 0x90000000U) != 0)) || ((u32) (temp_r14) == 0xC0000000U) || ((u32) (temp_r4_3) == 0xC1000000U) || ((u32) (temp_r3_6) == 0xD0000000U) || ((u32) ((arg2 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_8 = 1;
    }
    if (var_r5_8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, arg2);
    }
    var_r14 = 0;
    if ((fn_8002F72C(&reader.next, base + 0xC) != 0) && (fn_8002F72C(&reader.next, base + 0x18) != 0) && (fn_8002F72C(&reader.next, base + 0x24) != 0)) {
        var_r14 = 1;
    }
    if (var_r14 != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
    }
    reader.cursor = arg2;
    var_r6_6 = 0;
    if (((u32) (temp_r23) == 0x80000000U) || (temp_r4_4 = (s32) &reader.cursor & 0xFF800000, (((u32) (temp_r4_4) == 0x81000000U) != 0)) || (temp_r3_7 = (s32) &reader.cursor & 0xF8000000, (((u32) (temp_r3_7) == 0x90000000U) != 0)) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r4_4) == 0xC1000000U) || ((u32) (temp_r3_7) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000)) == 0xE0000000U)) {
        var_r6_6 = 1;
    }
    if (var_r6_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f28 = lbl_80561178;
    var_r27 = fn_8002F768(&reader.cursor);
    temp_r22 = (s32) &reader.cursor & 0xFF800000;
    temp_r21 = (s32) &reader.cursor & 0xF8000000;
    temp_r20 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r26 = arg0 & 0xFF800000;
    temp_r25 = arg0 & 0xF8000000;
    temp_r31 = temp_r23 + 0x80000000;
loop_279:
    var_r3 = 0;
    if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    if ((s32) (reader.cursor - arg2) > arg3) {
        goto block_290;
    }
    if ((s32) var_r27 < 0x20) {
        rect[0] = var_f31;
        var_r3_2 = 0;
        rect[1] = temp_f28;
        rect[2] = temp_f28;
        rect[3] = temp_f28;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_2 = 1;
        }
        if (var_r3_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
        }
        context.str = reader.cursor;
        context.flags = var_r19 == 0;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, var_f31);
        temp_r3_8 = *(void***)(arg0+0x5C);
        temp_r29 = ((Processor*)temp_r3_8)->rectCall(rect,var_r27,&context);
        var_r0 = 1;
        var_r3_3 = 1;
        temp_r5 = context.str & 0xFF000000;
        var_r4_4 = 1;
        var_r8_6 = 1;
        var_r9_6 = 1;
        var_r10_3 = 1;
        if (((u32) (temp_r5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r10_3 = 0;
        }
        if ((var_r10_3 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32) (temp_r5) != 0xC0000000U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_4 = 0;
        }
        if ((var_r4_4 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_3 = 0;
        }
        if ((var_r3_3 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3A8, base + 0x244);
        }
        var_r3_4 = 0;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_4 = 1;
        }
        if (var_r3_4 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
        }
        temp_r4_5 = context.str & 0xFF000000;
        var_r0_2 = 1;
        var_r3_5 = 1;
        var_r6_7 = 1;
        var_r7_6 = 1;
        var_r8_7 = 1;
        var_r9_7 = 1;
        if (((u32) (temp_r4_5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r8_7 = 0;
        }
        if ((var_r8_7 == 0) && ((u32) (temp_r4_5) != 0xC0000000U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r6_7 = 0;
        }
        if ((var_r6_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_5 = 0;
        }
        if ((var_r3_5 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, context.str);
        }
        var_r30 = 0;
        if ((fn_8002F72C(&reader.next, base + 0xC) != 0) && (fn_8002F72C(&reader.next, base + 0x18) != 0) && (fn_8002F72C(&reader.next, base + 0x24) != 0)) {
            var_r30 = 1;
        }
        if (var_r30 != 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
        }
        reader.cursor = context.str;
        var_f1_3 = rect[0];
        temp_f0 = *(f32*)(arg1 + 0);
        if (!(temp_f0 > var_f1_3))
            var_f1_3 = temp_f0;
        *(f32*)(arg1 + 0) = var_f1_3;
        temp_f0_2 = *(f32*)(arg1 + 4);
        var_f1_4 = rect[1];
        if (!(temp_f0_2 > var_f1_4))
            var_f1_4 = temp_f0_2;
        *(f32*)(arg1 + 4) = var_f1_4;
        temp_f0_3 = *(f32*)(arg1 + 8);
        var_f1_5 = rect[2];
        if (!(temp_f0_3 < var_f1_5))
            var_f1_5 = temp_f0_3;
        *(f32*)(arg1 + 8) = var_f1_5;
        temp_f0_4 = *(f32*)(arg1 + 0xC);
        var_f1_6 = rect[3];
        if (!(temp_f0_4 < var_f1_6))
            var_f1_6 = temp_f0_4;
        *(f32*)(arg1 + 0xC) = var_f1_6;
        var_f31 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
        switch (temp_r29) {                         /* irregular */
        case 4:
            return arg3;
        case 1:
            var_r19 = 0;
            goto block_268;
        case 2:
            var_r19 = 1;
            goto block_268;
        case 3:
block_290:
            var_r3_6 = 0;
            if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
                var_r3_6 = 1;
            }
            if (var_r3_6 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            return reader.cursor - arg2;
        }
    } else {
        if (var_r19 != 0) {
            var_r3_7 = 0;
            if (((u32) (temp_r24) == 0x80000000U) || ((u32) (temp_r26) == 0x81000000U) || ((u32) (temp_r25) == 0x90000000U) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r26) == 0xC1000000U) || ((u32) (temp_r25) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
                var_r3_7 = 1;
            }
            if (var_r3_7 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x138, base + 0x48, arg0);
            }
            var_f31 += *(f32*)(arg0 + 0x4C);
        }
        var_r19 = 1;
        if (IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(arg0) != 0) {
            var_f31 += GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(arg0);
        } else {
            temp_f29 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv(arg0);
            var_f31 += (f32) ((Font*)GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0))->width(var_r27) * temp_f29;
        }
        var_f0 = *(f32*)(arg1 + 0);
        if (!(var_f0 > var_f31)) {
        } else {
            var_f0 = var_f31;
        }
        var_f1_7 = *(f32*)(arg1 + 8);
        *(f32*)(arg1 + 0) = var_f0;
        if (!(var_f1_7 < var_f31)) {
        } else {
            var_f1_7 = var_f31;
        }
        *(f32*)(arg1 + 8) = var_f1_7;
block_268:
        var_r3_8 = 0;
        if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_8 = 1;
        }
        if (var_r3_8 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
        }
        var_r27 = fn_8002F768(&reader.cursor);
        goto loop_279;
    }
}

#pragma push
#pragma optimize_for_size on
extern "C" void fn_8010F430(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern const char lbl_80329530[];
    extern f32 lbl_80561178;
    extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32, f32, f32);
    volatile f32 sp14, sp10, spC, sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f31;
    f32 var_f1, var_f1_2, var_f1_3, var_f1_4;
    s32 temp_r10, temp_r10_2, temp_r11, temp_r3;
    s32 var_r10, var_r29, var_r30;
    s32 var_r4, var_r4_2, var_r5, var_r5_2, var_r5_3;
    s32 var_r6, var_r6_2, var_r6_3, var_r7, var_r7_2, var_r7_3;
    s32 var_r8, var_r8_2, var_r8_3, var_r9, var_r9_2, var_r9_3;
    const char *base = lbl_80329530;
    temp_r11 = arg0 & 0xFF000000;
    var_r29 = arg2;
    var_r30 = arg3;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32)(temp_r11 + 0x80000000U) >= 1U) &&
        ((u32)((arg0 & 0xFF800000U) + 0x7F000000U) >= 1U)) var_r10 = 0;
    if ((var_r10 == 0) && ((u32)((arg0 & 0xF8000000U) + 0x70000000U) >= 1U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)(temp_r11 + 0x40000000U) >= 1U)) var_r8 = 0;
    if ((var_r8 == 0) && ((u32)((arg0 & 0xFF800000U) + 0x3F000000U) >= 1U)) var_r7 = 0;
    if ((var_r7 == 0) && ((u32)((arg0 & 0xF8000000U) + 0x30000000U) >= 1U)) var_r6 = 0;
    if ((var_r6 == 0) && ((u32)((arg0 & 0xFFFFC000U) + 0x20000000U) >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F2, base + 0x48, arg0);
    temp_r10 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32)(temp_r10 + 0x80000000U) >= 1U) &&
        ((u32)((arg1 & 0xFF800000U) + 0x7F000000U) >= 1U)) var_r9_2 = 0;
    if ((var_r9_2 == 0) && ((u32)((arg1 & 0xF8000000U) + 0x70000000U) >= 1U)) var_r8_2 = 0;
    if ((var_r8_2 == 0) && ((u32)(temp_r10 + 0x40000000U) >= 1U)) var_r7_2 = 0;
    if ((var_r7_2 == 0) && ((u32)((arg1 & 0xFF800000U) + 0x3F000000U) >= 1U)) var_r6_2 = 0;
    if ((var_r6_2 == 0) && ((u32)((arg1 & 0xF8000000U) + 0x30000000U) >= 1U)) var_r5_2 = 0;
    if ((var_r5_2 == 0) && ((u32)((arg1 & 0xFFFFC000U) + 0x20000000U) >= 1U)) var_r4 = 0;
    if (var_r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F3, base + 0xF8, arg1);
    temp_r10_2 = var_r29 & 0xFF000000;
    var_r4_2 = 1;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32)(temp_r10_2 + 0x80000000U) >= 1U) &&
        ((u32)((var_r29 & 0xFF800000U) + 0x7F000000U) >= 1U)) var_r9_3 = 0;
    if ((var_r9_3 == 0) && ((u32)((var_r29 & 0xF8000000U) + 0x70000000U) >= 1U)) var_r8_3 = 0;
    if ((var_r8_3 == 0) && ((u32)(temp_r10_2 + 0x40000000U) >= 1U)) var_r7_3 = 0;
    if ((var_r7_3 == 0) && ((u32)((var_r29 & 0xFF800000U) + 0x3F000000U) >= 1U)) var_r6_3 = 0;
    if ((var_r6_3 == 0) && ((u32)((var_r29 & 0xF8000000U) + 0x30000000U) >= 1U)) var_r5_3 = 0;
    if ((var_r5_3 == 0) && ((u32)((var_r29 & 0xFFFFC000U) + 0x20000000U) >= 1U)) var_r4_2 = 0;
    if (var_r4_2 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F4, base + 0x130, var_r29);
    if (var_r30 < 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F5, base + 0x168, var_r30, 0);
    register f32 zero = lbl_80561178;
    *(f32 *)arg1 = zero;
    *(f32 *)(arg1 + 8) = zero;
    *(f32 *)(arg1 + 4) = zero;
    *(f32 *)(arg1 + 0xC) = zero;
    SetCursor__Q36nw4hbm2ut10CharWriterFff(arg0, zero, zero);
    temp_f31 = lbl_80561178;
    do {
        sp8 = temp_f31;
        spC = temp_f31;
        sp10 = temp_f31;
        sp14 = temp_f31;
        temp_r3 = fn_8010E3BC(arg0, (s32)&sp8, var_r29, var_r30);
        var_f1 = sp8;
        var_r29 += temp_r3;
        temp_f0 = *(f32 *)arg1;
        var_r30 -= temp_r3;
        if (temp_f0 > var_f1) {
        } else {
            var_f1 = temp_f0;
        }
        *(f32 *)arg1 = var_f1;
        temp_f0_2 = *(f32 *)(arg1 + 4);
        var_f1_2 = spC;
        if (temp_f0_2 > var_f1_2) {
        } else {
            var_f1_2 = temp_f0_2;
        }
        *(f32 *)(arg1 + 4) = var_f1_2;
        temp_f0_3 = *(f32 *)(arg1 + 8);
        var_f1_3 = sp10;
        if (temp_f0_3 < var_f1_3) {
        } else {
            var_f1_3 = temp_f0_3;
        }
        *(f32 *)(arg1 + 8) = var_f1_3;
        temp_f0_4 = *(f32 *)(arg1 + 0xC);
        var_f1_4 = sp14;
        if (temp_f0_4 < var_f1_4) {
        } else {
            var_f1_4 = temp_f0_4;
        }
        *(f32 *)(arg1 + 0xC) = var_f1_4;
    } while (var_r30 > 0);
}
#pragma pop
extern "C" f32 fn_8010F81C(void *writer, s32 arg1, s32 arg2) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32);
extern void MoveCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(s32,f32),Print__Q36nw4hbm2ut10CharWriterFUs(s32,u16),SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(s32,f32),SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern void fn_801033F0(void*,unsigned int);
extern void fn_8010E3BC(void*,f32*,s32,s32);
extern f32 fn_80110D68(s32,f32*,f32*,s32,s32);
extern f32 lbl_80561178,lbl_80561188;
extern const char lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80320AC4[],lbl_80320AFC[],lbl_80320B10[],lbl_80320B48[],lbl_80329530[];
 extern const char lbl_80329938[],lbl_80329900[],lbl_803298EC[],lbl_803298B4[],lbl_803298A0[],lbl_80329824[];
 class TagProcessor { public: virtual void dummy(); virtual s32 process(u16,s32*); };
 class FontMetrics { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual s32 ascent(); };
 nw4hbm::ut::CharWriter copyRight;
 nw4hbm::ut::CharWriter copyCenter;
 class Reader { public: s32 cursor; u16 (Reader::*next)(); };
 Reader reader;
 struct { s32 writer, str; f32 x, y; s32 flags; } context;
 f32 rectRight[4], rectCenter[4];

    void **sp114;
    void **spB4;
    f32 spC;
    f32 sp8;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f31;
    f32 var_f0;
    f32 var_f29;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f24;
    s32 temp_r18;
    s32 temp_r18_2;
    s32 temp_r19;
    s32 arg0=(s32)writer;
    s32 temp_r19_2;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    const char *message_base = lbl_80329530;
    s32 temp_r24;
    s32 temp_r25;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_5;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_5;
    s32 temp_r4_7;
    s32 temp_r4_8;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r14;
    s32 var_r20;
    s32 var_r3;
    s32 var_r3_10;
    s32 var_r3_11;
    s32 var_r3_12;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r3_9;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r7_7;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r8_8;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    s32 var_r9_8;
    u16 var_r19;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r31;
    u32 temp_r3_3;
    u32 temp_r4_4;
    u32 temp_r4_6;
    void **temp_r3_4;

    temp_r22 = arg0 & 0xFF000000;
    var_r10 = 1;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    if (((u32)(temp_r22) != 0x80000000U) && ((u32)(arg0 & 0xFF800000) != 0x81000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32)(arg0 & 0xF8000000) != 0x90000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32)(temp_r22) != 0xC0000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32)(arg0 & 0xFF800000) != 0xC1000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32)(arg0 & 0xF8000000) != 0xD0000000U)) {
        var_r5 = 0;
    }
    if ((var_r5 == 0) && ((u32)(arg0 & 0xFFFFC000) != 0xE0000000U)) {
        var_r10 = 0;
    }
    if (var_r10 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x41F, message_base + 0x48, arg0);
    }
    temp_r18 = arg1 & 0xFF000000;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    var_r9_2 = 1;
    if (((u32)(temp_r18) != 0x80000000U) && ((u32)(arg1 & 0xFF800000) != 0x81000000U)) {
        var_r9_2 = 0;
    }
    if ((var_r9_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0x90000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32)(temp_r18) != 0xC0000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32)(arg1 & 0xFF800000) != 0xC1000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0xD0000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32)(arg1 & 0xFFFFC000) != 0xE0000000U)) {
        var_r4 = 0;
    }
    if (var_r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x420, message_base + 0x130, arg1);
    }
    var_r14 = 0;
    if (((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF000000) + 0x80000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF800000) + 0x7F000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xF8000000) + 0x70000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF000000) + 0x40000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFF800000) + 0x3F000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xF8000000) + 0x30000000) == 0U) || ((u32) ((GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0) & 0xFFFFC000) + 0x20000000) == 0U)) {
        var_r14 = 1;
    }
    if (var_r14 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x421, message_base + 0x280, GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0));
    }
    if (arg2 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x422, message_base + 0x168, arg2, 0);
    }
    spC = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
    temp_f1 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
    temp_f28 = (f32) temp_f1;
    sp8 = (f32) temp_f1;
    var_r20 = 0;
    var_f29 = fn_80110D68(arg0, &spC, &sp8, arg1, arg2);
    GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
    temp_f1_2 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
    context.x = 0.0f;
    context.y = 0.0f;
    context.flags = 0;
    context.writer = arg0;
    context.str = arg1;
    context.x = spC;
    context.y = sp8;
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0));
    var_r4_2 = 1;
    temp_r21 = (s32) &reader.cursor & 0xFF000000;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32)(temp_r21) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x7F000000) != 0U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x70000000) != 0U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32)(temp_r21) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x3F000000) != 0U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x30000000) != 0U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) != 0U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
    }

    var_r5_4 = 0;
    if (((u32)(temp_r18) == 0x80000000U) || (temp_r4 = arg1 & 0xFF800000, (((u32)(temp_r4) == 0x81000000U) != 0)) || (temp_r3 = arg1 & 0xF8000000, (((u32)(temp_r3) == 0x90000000U) != 0)) || ((u32)(temp_r18) == 0xC0000000U) || ((u32)(temp_r4) == 0xC1000000U) || ((u32)(temp_r3) == 0xD0000000U) || ((u32)(arg1 & 0xFFFFC000) == 0xE0000000U)) {
        var_r5_4 = 1;
    }
    if (var_r5_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, arg1);
    }
    if (fn_8002F72C(&reader.next, message_base + 0xC) != 0 && fn_8002F72C(&reader.next, message_base + 0x18) != 0 && fn_8002F72C(&reader.next, message_base + 0x24) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
    }
    reader.cursor = arg1;
    var_r6_4 = 0;
    if (((u32)(temp_r21) == 0x80000000U) || (temp_r4_2 = (s32) &reader.cursor & 0xFF800000, (((u32)(temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_2 = (s32) &reader.cursor & 0xF8000000, (((u32)(temp_r3_2) == 0x90000000U) != 0)) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r4_2) == 0xC1000000U) || ((u32)(temp_r3_2) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) == 0U)) {
        var_r6_4 = 1;
    }
    if (var_r6_4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f31 = lbl_80561178;
    temp_f25 = lbl_80561188;
    var_r19 = (reader.*reader.next)();
    temp_r28 = (s32) &reader.cursor & 0xFF800000;
    temp_r27 = (s32) &reader.cursor & 0xF8000000;
    temp_r26 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r25 = arg0 & 0xFF800000;
    temp_r24 = arg0 & 0xF8000000;
    temp_r23 = arg0 & 0xFFFFC000;
    temp_r31 = temp_r21 + 0x80000000;
loop_286:
    var_r3 = 0;
    if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    temp_r3_3 = reader.cursor - arg1;
    if ((s32)temp_r3_3 <= arg2) {
        if ((s32) var_r19 < 0x20) {
            var_r3_2 = 0;
            if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                var_r3_2 = 1;
            }
            if (var_r3_2 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            context.str = reader.cursor;
            context.flags = var_r20 == 0;
            temp_r3_4 = *(void ***)(arg0 + 0x5C);
            temp_r3_5 = ((TagProcessor*)temp_r3_4)->process(var_r19, &context.writer);
            switch (temp_r3_5) {                    /* irregular */
            case 4:
                break;
            case 3:
                var_r0 = 1;
                var_r3_3 = 1;
                var_r7_4 = 1;
                temp_r4_3 = context.str & 0xFF000000;
                var_r8_4 = 1;
                var_r9_4 = 1;
                var_r10_2 = 1;
                if (((u32)(temp_r4_3) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r10_2 = 0;
                }
                if ((var_r10_2 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r9_4 = 0;
                }
                if ((var_r9_4 == 0) && ((u32)(temp_r4_3) != 0xC0000000U)) {
                    var_r8_4 = 0;
                }
                if ((var_r8_4 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r7_4 = 0;
                }
                if ((var_r7_4 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_3 = 0;
                }
                if ((var_r3_3 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0 = 0;
                }
                if (var_r0 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x449, message_base + 0x244);
                }
                temp_r0 = *(s32 *)(arg0 + 0x58) & 3;
                if (temp_r0 == 1) {
                    var_r3_4 = 0;
                    temp_r4_4 = context.str - arg1;
                    temp_r19 = arg2 - temp_r4_4;
                    if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                        var_r3_4 = 1;
                    }
                    if (var_r3_4 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x35D, message_base + 0x48, arg0);
                    }
                    temp_r4_5 = context.str & 0xFF000000;
                    var_r0_2 = 1;
                    var_r3_5 = 1;
                    var_r6_5 = 1;
                    var_r7_5 = 1;
                    var_r8_5 = 1;
                    var_r9_5 = 1;
                    if (((u32)(temp_r4_5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                        var_r9_5 = 0;
                    }
                    if ((var_r9_5 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                        var_r8_5 = 0;
                    }
                    if ((var_r8_5 == 0) && ((u32)(temp_r4_5) != 0xC0000000U)) {
                        var_r7_5 = 0;
                    }
                    if ((var_r7_5 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                        var_r6_5 = 0;
                    }
                    if ((var_r6_5 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                        var_r3_5 = 0;
                    }
                    if ((var_r3_5 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                        var_r0_2 = 0;
                    }
                    if (var_r0_2 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x35E, message_base + 0x130, context.str);
                    }
                    if (temp_r19 < 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x35F, message_base + 0x168, temp_r19, 0);
                    }
                    rectRight[0] = temp_f31;
                    rectRight[1] = temp_f31;
                    rectRight[2] = temp_f31;
                    rectRight[3] = temp_f31;
                    *(u8 *)((u8*)&copyRight+0) = *(u8 *)(arg0 + 0);
                    *(u8 *)((u8*)&copyRight+1) = *(u8 *)(arg0 + 1);
                    *(u8 *)((u8*)&copyRight+2) = *(u8 *)(arg0 + 2);
                    *(u8 *)((u8*)&copyRight+3) = *(u8 *)(arg0 + 3);
                    *(u8 *)((u8*)&copyRight+4) = *(u8 *)(arg0 + 4);
                    *(u8 *)((u8*)&copyRight+5) = *(u8 *)(arg0 + 5);
                    *(u8 *)((u8*)&copyRight+6) = *(u8 *)(arg0 + 6);
                    *(u8 *)((u8*)&copyRight+7) = *(u8 *)(arg0 + 7);
                    *(u8 *)((u8*)&copyRight+8) = *(u8 *)(arg0 + 8);
                    *(u8 *)((u8*)&copyRight+9) = *(u8 *)(arg0 + 9);
                    *(u8 *)((u8*)&copyRight+10) = *(u8 *)(arg0 + 0xA);
                    *(u8 *)((u8*)&copyRight+11) = *(u8 *)(arg0 + 0xB);
                    *(u8 *)((u8*)&copyRight+12) = *(u8 *)(arg0 + 0xC);
                    *(u8 *)((u8*)&copyRight+13) = *(u8 *)(arg0 + 0xD);
                    *(u8 *)((u8*)&copyRight+14) = *(u8 *)(arg0 + 0xE);
                    *(u8 *)((u8*)&copyRight+15) = *(u8 *)(arg0 + 0xF);
                    *(u8 *)((u8*)&copyRight+16) = *(u8 *)(arg0 + 0x10);
                    *(u8 *)((u8*)&copyRight+17) = *(u8 *)(arg0 + 0x11);
                    *(u8 *)((u8*)&copyRight+18) = *(u8 *)(arg0 + 0x12);
                    *(u8 *)((u8*)&copyRight+19) = *(u8 *)(arg0 + 0x13);
                    *(u8 *)((u8*)&copyRight+20) = *(u8 *)(arg0 + 0x14);
                    *(u8 *)((u8*)&copyRight+21) = *(u8 *)(arg0 + 0x15);
                    *(u8 *)((u8*)&copyRight+22) = *(u8 *)(arg0 + 0x16);
                    *(u8 *)((u8*)&copyRight+23) = *(u8 *)(arg0 + 0x17);
                    *(u8 *)((u8*)&copyRight+24) = *(u8 *)(arg0 + 0x18);
                    *(u8 *)((u8*)&copyRight+25) = *(u8 *)(arg0 + 0x19);
                    *(u8 *)((u8*)&copyRight+26) = *(u8 *)(arg0 + 0x1A);
                    *(u8 *)((u8*)&copyRight+27) = *(u8 *)(arg0 + 0x1B);
                    *(u8 *)((u8*)&copyRight+28) = *(u8 *)(arg0 + 0x1C);
                    *(u8 *)((u8*)&copyRight+29) = *(u8 *)(arg0 + 0x1D);
                    *(u8 *)((u8*)&copyRight+30) = *(u8 *)(arg0 + 0x1E);
                    *(u8 *)((u8*)&copyRight+31) = *(u8 *)(arg0 + 0x1F);
                    *(s32 *)((u8*)&copyRight+32) = *(s32 *)(arg0 + 0x20);
                    *(s32 *)((u8*)&copyRight+36) = *(s32 *)(arg0 + 0x24);
                    *(s32 *)((u8*)&copyRight+40) = *(s32 *)(arg0 + 0x28);
                    *(s32 *)((u8*)&copyRight+44) = *(s32 *)(arg0 + 0x2C);
                    *(s32 *)((u8*)&copyRight+48) = *(s32 *)(arg0 + 0x30);
                    *(s32 *)((u8*)&copyRight+52) = *(s32 *)(arg0 + 0x34);
                    *(s32 *)((u8*)&copyRight+56) = *(s32 *)(arg0 + 0x38);
                    *(s32 *)((u8*)&copyRight+60) = *(s32 *)(arg0 + 0x3C);
                    *(u8 *)((u8*)&copyRight+64) = *(u8 *)(arg0 + 0x40);
                    *(u8 *)((u8*)&copyRight+65) = *(u8 *)(arg0 + 0x41);
                    *(u8 *)((u8*)&copyRight+66) = *(u8 *)(arg0 + 0x42);
                    *(u8 *)((u8*)&copyRight+67) = *(u8 *)(arg0 + 0x43);
                    *(f32 *)((u8*)&copyRight+68) = *(f32 *)(arg0 + 0x44);
                    *(s32 *)((u8*)&copyRight+72) = *(s32 *)(arg0 + 0x48);
                    *(f32 *)((u8*)&copyRight+76) = *(f32 *)(arg0 + 0x4C);
                    *(f32 *)((u8*)&copyRight+80) = *(f32 *)(arg0 + 0x50);
                    *(s32 *)((u8*)&copyRight+84) = *(s32 *)(arg0 + 0x54);
                    *(s32 *)((u8*)&copyRight+88) = *(s32 *)(arg0 + 0x58);
                    *(void ***)((u8*)&copyRight+92) = *(void ***)(arg0 + 0x5C);
                    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyRight, temp_f31, temp_f31);
                    fn_8010E3BC((u8*)&copyRight, &rectRight[0], context.str, temp_r19);
                    fn_801033F0((u8*)&copyRight, 0);
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x + ((var_f29 - (rectRight[2] - rectRight[0])) * temp_f25));
                } else if (temp_r0 == 2) {
                    var_r3_6 = 0;
                    temp_r4_6 = context.str - arg1;
                    temp_r19_2 = arg2 - temp_r4_6;
                    if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                        var_r3_6 = 1;
                    }
                    if (var_r3_6 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x35D, message_base + 0x48, arg0);
                    }
                    temp_r4_7 = context.str & 0xFF000000;
                    var_r0_3 = 1;
                    var_r3_7 = 1;
                    var_r6_6 = 1;
                    var_r7_6 = 1;
                    var_r8_6 = 1;
                    var_r9_6 = 1;
                    if (((u32)(temp_r4_7) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                        var_r9_6 = 0;
                    }
                    if ((var_r9_6 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                        var_r8_6 = 0;
                    }
                    if ((var_r8_6 == 0) && ((u32)(temp_r4_7) != 0xC0000000U)) {
                        var_r7_6 = 0;
                    }
                    if ((var_r7_6 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                        var_r6_6 = 0;
                    }
                    if ((var_r6_6 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                        var_r3_7 = 0;
                    }
                    if ((var_r3_7 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                        var_r0_3 = 0;
                    }
                    if (var_r0_3 == 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x35E, message_base + 0x130, context.str);
                    }
                    if (temp_r19_2 < 0) {
                        Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x35F, message_base + 0x168, temp_r19_2, 0);
                    }
                    rectCenter[0] = temp_f31;
                    rectCenter[1] = temp_f31;
                    rectCenter[2] = temp_f31;
                    rectCenter[3] = temp_f31;
                    *(u8 *)((u8*)&copyCenter+0) = *(u8 *)(arg0 + 0);
                    *(u8 *)((u8*)&copyCenter+1) = *(u8 *)(arg0 + 1);
                    *(u8 *)((u8*)&copyCenter+2) = *(u8 *)(arg0 + 2);
                    *(u8 *)((u8*)&copyCenter+3) = *(u8 *)(arg0 + 3);
                    *(u8 *)((u8*)&copyCenter+4) = *(u8 *)(arg0 + 4);
                    *(u8 *)((u8*)&copyCenter+5) = *(u8 *)(arg0 + 5);
                    *(u8 *)((u8*)&copyCenter+6) = *(u8 *)(arg0 + 6);
                    *(u8 *)((u8*)&copyCenter+7) = *(u8 *)(arg0 + 7);
                    *(u8 *)((u8*)&copyCenter+8) = *(u8 *)(arg0 + 8);
                    *(u8 *)((u8*)&copyCenter+9) = *(u8 *)(arg0 + 9);
                    *(u8 *)((u8*)&copyCenter+10) = *(u8 *)(arg0 + 0xA);
                    *(u8 *)((u8*)&copyCenter+11) = *(u8 *)(arg0 + 0xB);
                    *(u8 *)((u8*)&copyCenter+12) = *(u8 *)(arg0 + 0xC);
                    *(u8 *)((u8*)&copyCenter+13) = *(u8 *)(arg0 + 0xD);
                    *(u8 *)((u8*)&copyCenter+14) = *(u8 *)(arg0 + 0xE);
                    *(u8 *)((u8*)&copyCenter+15) = *(u8 *)(arg0 + 0xF);
                    *(u8 *)((u8*)&copyCenter+16) = *(u8 *)(arg0 + 0x10);
                    *(u8 *)((u8*)&copyCenter+17) = *(u8 *)(arg0 + 0x11);
                    *(u8 *)((u8*)&copyCenter+18) = *(u8 *)(arg0 + 0x12);
                    *(u8 *)((u8*)&copyCenter+19) = *(u8 *)(arg0 + 0x13);
                    *(u8 *)((u8*)&copyCenter+20) = *(u8 *)(arg0 + 0x14);
                    *(u8 *)((u8*)&copyCenter+21) = *(u8 *)(arg0 + 0x15);
                    *(u8 *)((u8*)&copyCenter+22) = *(u8 *)(arg0 + 0x16);
                    *(u8 *)((u8*)&copyCenter+23) = *(u8 *)(arg0 + 0x17);
                    *(u8 *)((u8*)&copyCenter+24) = *(u8 *)(arg0 + 0x18);
                    *(u8 *)((u8*)&copyCenter+25) = *(u8 *)(arg0 + 0x19);
                    *(u8 *)((u8*)&copyCenter+26) = *(u8 *)(arg0 + 0x1A);
                    *(u8 *)((u8*)&copyCenter+27) = *(u8 *)(arg0 + 0x1B);
                    *(u8 *)((u8*)&copyCenter+28) = *(u8 *)(arg0 + 0x1C);
                    *(u8 *)((u8*)&copyCenter+29) = *(u8 *)(arg0 + 0x1D);
                    *(u8 *)((u8*)&copyCenter+30) = *(u8 *)(arg0 + 0x1E);
                    *(u8 *)((u8*)&copyCenter+31) = *(u8 *)(arg0 + 0x1F);
                    *(s32 *)((u8*)&copyCenter+32) = *(s32 *)(arg0 + 0x20);
                    *(s32 *)((u8*)&copyCenter+36) = *(s32 *)(arg0 + 0x24);
                    *(s32 *)((u8*)&copyCenter+40) = *(s32 *)(arg0 + 0x28);
                    *(s32 *)((u8*)&copyCenter+44) = *(s32 *)(arg0 + 0x2C);
                    *(s32 *)((u8*)&copyCenter+48) = *(s32 *)(arg0 + 0x30);
                    *(s32 *)((u8*)&copyCenter+52) = *(s32 *)(arg0 + 0x34);
                    *(s32 *)((u8*)&copyCenter+56) = *(s32 *)(arg0 + 0x38);
                    *(s32 *)((u8*)&copyCenter+60) = *(s32 *)(arg0 + 0x3C);
                    *(u8 *)((u8*)&copyCenter+64) = *(u8 *)(arg0 + 0x40);
                    *(u8 *)((u8*)&copyCenter+65) = *(u8 *)(arg0 + 0x41);
                    *(u8 *)((u8*)&copyCenter+66) = *(u8 *)(arg0 + 0x42);
                    *(u8 *)((u8*)&copyCenter+67) = *(u8 *)(arg0 + 0x43);
                    *(f32 *)((u8*)&copyCenter+68) = *(f32 *)(arg0 + 0x44);
                    *(s32 *)((u8*)&copyCenter+72) = *(s32 *)(arg0 + 0x48);
                    *(f32 *)((u8*)&copyCenter+76) = *(f32 *)(arg0 + 0x4C);
                    *(f32 *)((u8*)&copyCenter+80) = *(f32 *)(arg0 + 0x50);
                    *(s32 *)((u8*)&copyCenter+84) = *(s32 *)(arg0 + 0x54);
                    *(s32 *)((u8*)&copyCenter+88) = *(s32 *)(arg0 + 0x58);
                    *(void ***)((u8*)&copyCenter+92) = *(void ***)(arg0 + 0x5C);
                    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyCenter, temp_f31, temp_f31);
                    fn_8010E3BC((u8*)&copyCenter, &rectCenter[0], context.str, temp_r19_2);
                    fn_801033F0((u8*)&copyCenter, 0);
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x + (var_f29 - (rectCenter[2] - rectCenter[0])));
                } else {
                    var_f0 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0) - context.x;
                    if (var_f29 < var_f0) {

                    } else {
                        var_f0 = var_f29;
                    }
                    var_f29 = var_f0;
                    SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, context.x);
                }
                var_r20 = 0;
            default:
block_207:
                var_r0_4 = 1;
                var_r3_8 = 1;
                var_r4_3 = 1;
                temp_r5 = context.str & 0xFF000000;
                var_r8_7 = 1;
                var_r9_7 = 1;
                var_r10_3 = 1;
                if (((u32)(temp_r5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r10_3 = 0;
                }
                if ((var_r10_3 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r9_7 = 0;
                }
                if ((var_r9_7 == 0) && ((u32)(temp_r5) != 0xC0000000U)) {
                    var_r8_7 = 0;
                }
                if ((var_r8_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r4_3 = 0;
                }
                if ((var_r4_3 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_8 = 0;
                }
                if ((var_r3_8 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0_4 = 0;
                }
                if (var_r0_4 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x471, message_base + 0x244);
                }
                var_r3_9 = 0;
                if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                    var_r3_9 = 1;
                }
                if (var_r3_9 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329938, 0x31, lbl_80329900, (s32) &reader.cursor);
                }

                temp_r4_8 = context.str & 0xFF000000;
                var_r0_5 = 1;
                var_r3_10 = 1;
                var_r6_7 = 1;
                var_r7_7 = 1;
                var_r8_8 = 1;
                var_r9_8 = 1;
                if (((u32)(temp_r4_8) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                    var_r9_8 = 0;
                }
                if ((var_r9_8 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                    var_r8_8 = 0;
                }
                if ((var_r8_8 == 0) && ((u32)(temp_r4_8) != 0xC0000000U)) {
                    var_r7_7 = 0;
                }
                if ((var_r7_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                    var_r6_7 = 0;
                }
                if ((var_r6_7 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                    var_r3_10 = 0;
                }
                if ((var_r3_10 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                    var_r0_5 = 0;
                }
                if (var_r0_5 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298EC, 0x32, lbl_803298B4, context.str);
                }
                if (fn_8002F72C(&reader.next, message_base + 0xC) != 0 && fn_8002F72C(&reader.next, message_base + 0x18) != 0 && fn_8002F72C(&reader.next, message_base + 0x24) != 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(lbl_803298A0, 0x35, lbl_80329824);
                }
                reader.cursor = context.str;
                goto block_275;
            case 1:
                var_r20 = 0;
                goto block_207;
            case 2:
                var_r20 = 1;
                goto block_207;
            }
        } else {
            temp_f24 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(arg0);
            if (var_r20 != 0) {
                var_r3_11 = 0;
                if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                    var_r3_11 = 1;
                }
                if (var_r3_11 == 0) {
                    Panic__Q26nw4hbm2dbFPCciPCce(message_base + 0x30, 0x138, message_base + 0x48, arg0);
                }
                MoveCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *(f32 *)(arg0 + 0x4C));
            }
            var_r20 = 1;
            temp_r18_2 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
            temp_f26 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
            MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(arg0, (f32) -((FontMetrics*)temp_r18_2)->ascent() * temp_f26);
            Print__Q36nw4hbm2ut10CharWriterFUs(arg0, var_r19);
            SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, temp_f24);
block_275:
            var_r3_12 = 0;
            if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                var_r3_12 = 1;
            }
            if (var_r3_12 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
            }
            var_r19 = (reader.*reader.next)();
            goto loop_286;
        }
    }
    temp_r0_2 = *(s32 *)(arg0 + 0x58) & 0x300;
    if ((temp_r0_2 == 0x100) || (temp_r0_2 == 0x200)) {
        SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, (f64) temp_f28);
    } else {
        MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(arg0, temp_f28 - (f32) temp_f1_2);
    }
    return var_f29;
}

#pragma dont_inline on
extern "C" f32 fn_80110D68(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4) {
    const char *base = lbl_80329530;
    u8 copyA[0x60], copyB[0x60], copyC[0x60];
    f32 rectA[4], rectB[4], rectC[4];
    f32 temp_f2;
    f32 var_f2;
    f32 var_f31;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r10_3;
    s32 temp_r10_4;
    s32 temp_r10_5;
    s32 temp_r10_6;
    s32 temp_r11;
    s32 var_r10;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r4_5;
    s32 var_r4_6;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r6_7;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r7_7;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r0_4;

    var_f31 = lbl_80561178;
    temp_r0 = (*(s32 *)((u8*)(arg0) + (0x58))) & 0x333;
    var_f2 = (f32)(var_f31);
    if ((temp_r0 != 0x300) && ((s32) temp_r0 != 0)) {
        temp_r11 = (s32) arg0 & 0xFF000000;
        rectA[0] = var_f31;
        var_r5 = 1;
        rectA[1] = var_f31;
        var_r6 = 1;
        var_r7 = 1;
        rectA[2] = var_f31;
        var_r8 = 1;
        var_r9 = 1;
        var_r10 = 1;
        rectA[3] = var_f31;
        if ((u32)(temp_r11 + 0x80000000) == 0U) {
        } else if ((u32)(((s32)arg0 & 0xFF800000) + 0x7F000000) == 0U) {
        } else {
            var_r10 = 0;
        }
        if ((var_r10 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r9 = 0;
        }
        if ((var_r9 == 0) && ((u32) (temp_r11 + 0x40000000) >= 1U)) {
            var_r8 = 0;
        }
        if ((var_r8 == 0) && ((u32) (((s32) arg0 & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r7 = 0;
        }
        if ((var_r7 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r6 = 0;
        }
        if ((var_r6 == 0) && ((u32) (((s32) arg0 & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r5 = 0;
        }
        if (var_r5 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x224, base + 0x48, arg0);
        }
        var_r4 = 1;
        temp_r10 = (s32) &rectA[0] & 0xFF000000;
        var_r5_2 = 1;
        var_r6_2 = 1;
        var_r7_2 = 1;
        var_r8_2 = 1;
        var_r9_2 = 1;
        if (((u32) (temp_r10 + 0x80000000) >= 1U) && ((u32) (((s32) &rectA[0] & 0xFF800000) + 0x7F000000) >= 1U)) {
            var_r9_2 = 0;
        }
        if ((var_r9_2 == 0) && ((u32) (((s32) &rectA[0] & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r8_2 = 0;
        }
        if ((var_r8_2 == 0) && ((u32) (temp_r10 + 0x40000000) >= 1U)) {
            var_r7_2 = 0;
        }
        if ((var_r7_2 == 0) && ((u32) (((s32) &rectA[0] & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r6_2 = 0;
        }
        if ((var_r6_2 == 0) && ((u32) (((s32) &rectA[0] & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r5_2 = 0;
        }
        if ((var_r5_2 == 0) && ((u32) (((s32) &rectA[0] & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r4 = 0;
        }
        if (var_r4 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x225, base + 0xF8, &rectA[0]);
        }
        temp_r10_2 = arg3 & 0xFF000000;
        var_r4_2 = 1;
        var_r5_3 = 1;
        var_r6_3 = 1;
        var_r7_3 = 1;
        var_r8_3 = 1;
        var_r9_3 = 1;
        if (((u32) (temp_r10_2 + 0x80000000) >= 1U) && ((u32) ((arg3 & 0xFF800000) + 0x7F000000) >= 1U)) {
            var_r9_3 = 0;
        }
        if ((var_r9_3 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r8_3 = 0;
        }
        if ((var_r8_3 == 0) && ((u32) (temp_r10_2 + 0x40000000) >= 1U)) {
            var_r7_3 = 0;
        }
        if ((var_r7_3 == 0) && ((u32) ((arg3 & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r6_3 = 0;
        }
        if ((var_r6_3 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r5_3 = 0;
        }
        if ((var_r5_3 == 0) && ((u32) ((arg3 & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r4_2 = 0;
        }
        if (var_r4_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x226, base + 0x130, (f32 *) arg3);
        }
        if (arg4 < 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x227, base + 0x168, arg4, 0);
        }
        copyA[0x0] = (*(u8 *)((u8*)(arg0) + (0)));
        copyA[0x1] = (*(u8 *)((u8*)(arg0) + (1)));
        copyA[0x2] = (*(u8 *)((u8*)(arg0) + (2)));
        copyA[0x3] = (*(u8 *)((u8*)(arg0) + (3)));
        copyA[0x4] = (*(u8 *)((u8*)(arg0) + (4)));
        copyA[0x5] = (*(u8 *)((u8*)(arg0) + (5)));
        copyA[0x6] = (*(u8 *)((u8*)(arg0) + (6)));
        copyA[0x7] = (*(u8 *)((u8*)(arg0) + (7)));
        copyA[0x8] = (*(u8 *)((u8*)(arg0) + (8)));
        copyA[0x9] = (*(u8 *)((u8*)(arg0) + (9)));
        copyA[0xA] = (*(u8 *)((u8*)(arg0) + (0xA)));
        copyA[0xB] = (*(u8 *)((u8*)(arg0) + (0xB)));
        copyA[0xC] = (*(u8 *)((u8*)(arg0) + (0xC)));
        copyA[0xD] = (*(u8 *)((u8*)(arg0) + (0xD)));
        copyA[0xE] = (*(u8 *)((u8*)(arg0) + (0xE)));
        copyA[0xF] = (*(u8 *)((u8*)(arg0) + (0xF)));
        copyA[0x10] = (*(u8 *)((u8*)(arg0) + (0x10)));
        copyA[0x11] = (*(u8 *)((u8*)(arg0) + (0x11)));
        copyA[0x12] = (*(u8 *)((u8*)(arg0) + (0x12)));
        copyA[0x13] = (*(u8 *)((u8*)(arg0) + (0x13)));
        copyA[0x14] = (*(u8 *)((u8*)(arg0) + (0x14)));
        copyA[0x15] = (*(u8 *)((u8*)(arg0) + (0x15)));
        copyA[0x16] = (*(u8 *)((u8*)(arg0) + (0x16)));
        copyA[0x17] = (*(u8 *)((u8*)(arg0) + (0x17)));
        copyA[0x18] = (*(u8 *)((u8*)(arg0) + (0x18)));
        copyA[0x19] = (*(u8 *)((u8*)(arg0) + (0x19)));
        copyA[0x1A] = (*(u8 *)((u8*)(arg0) + (0x1A)));
        copyA[0x1B] = (*(u8 *)((u8*)(arg0) + (0x1B)));
        copyA[0x1C] = (*(u8 *)((u8*)(arg0) + (0x1C)));
        copyA[0x1D] = (*(u8 *)((u8*)(arg0) + (0x1D)));
        copyA[0x1E] = (*(u8 *)((u8*)(arg0) + (0x1E)));
        copyA[0x1F] = (*(u8 *)((u8*)(arg0) + (0x1F)));
        (*(s32*)(copyA+0x20)) = (*(s32 *)((u8*)(arg0) + (0x20)));
        s32 copyA_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
        s32 copyA_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
        (*(s32*)(copyA+0x24)) = copyA_24;
        (*(s32*)(copyA+0x28)) = copyA_28;
        s32 copyA_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
        s32 copyA_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
        (*(s32*)(copyA+0x2C)) = copyA_2C;
        (*(s32*)(copyA+0x30)) = copyA_30;
        (*(s32*)(copyA+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
        s32 copyA_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
        s32 copyA_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
        (*(s32*)(copyA+0x38)) = copyA_38;
        (*(s32*)(copyA+0x3C)) = copyA_3C;
        copyA[0x40] = (*(u8 *)((u8*)(arg0) + (0x40)));
        copyA[0x41] = (*(u8 *)((u8*)(arg0) + (0x41)));
        copyA[0x42] = (*(u8 *)((u8*)(arg0) + (0x42)));
        copyA[0x43] = (*(u8 *)((u8*)(arg0) + (0x43)));
        (*(f32*)(copyA+0x44)) = (*(f32 *)((u8*)(arg0) + (0x44)));
        (*(s32*)(copyA+0x48)) = (*(s32 *)((u8*)(arg0) + (0x48)));
        (*(f32*)(copyA+0x4C)) = (*(f32 *)((u8*)(arg0) + (0x4C)));
        (*(f32*)(copyA+0x50)) = (*(f32 *)((u8*)(arg0) + (0x50)));
        (*(s32*)(copyA+0x54)) = (*(s32 *)((u8*)(arg0) + (0x54)));
        (*(s32*)(copyA+0x58)) = (*(s32 *)((u8*)(arg0) + (0x58)));
        (*(s32*)(copyA+0x5C)) = (*(s32 *)((u8*)(arg0) + (0x5C)));
        fn_8010F430((s32)&copyA[0x0], (s32)&rectA[0], arg3, arg4);
        fn_801033F0(&copyA[0x0], 0);
        var_f31 = rectA[0] + rectA[2];
        var_f2 = rectA[1] + rectA[3];
    }
    temp_r0_2 = (*(s32 *)((u8*)(arg0) + (0x58))) & 0x30;
    if (temp_r0_2 == 0x10) {
        *arg1 -= var_f31 * lbl_80561188;
    } else if (temp_r0_2 == 0x20) {
        *arg1 -= var_f31;
    }
    temp_r0_3 = (*(s32 *)((u8*)(arg0) + (0x58))) & 0x300;
    if (temp_r0_3 == 0x100) {
        *arg2 -= var_f2 * lbl_80561188;
    } else if (temp_r0_3 == 0x200) {
        *arg2 -= var_f2;
    }
    temp_r0_4 = (*(s32 *)((u8*)(arg0) + (0x58))) & 3;
    if (temp_r0_4 == 1) {
        temp_r10_3 = (s32) arg0 & 0xFF000000;
        var_r4_3 = 1;
        var_r5_4 = 1;
        var_r6_4 = 1;
        var_r7_4 = 1;
        var_r8_4 = 1;
        var_r9_4 = 1;
        if (((u32) (temp_r10_3 + 0x80000000) >= 1U) && ((u32) (((s32) arg0 & 0xFF800000) + 0x7F000000) >= 1U)) {
            var_r9_4 = 0;
        }
        if ((var_r9_4 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r8_4 = 0;
        }
        if ((var_r8_4 == 0) && ((u32) (temp_r10_3 + 0x40000000) >= 1U)) {
            var_r7_4 = 0;
        }
        if ((var_r7_4 == 0) && ((u32) (((s32) arg0 & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r6_4 = 0;
        }
        if ((var_r6_4 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r5_4 = 0;
        }
        if ((var_r5_4 == 0) && ((u32) (((s32) arg0 & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r4_3 = 0;
        }
        if (var_r4_3 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35D, base + 0x48, arg0);
        }
        temp_r10_4 = arg3 & 0xFF000000;
        var_r4_4 = 1;
        var_r5_5 = 1;
        var_r6_5 = 1;
        var_r7_5 = 1;
        var_r8_5 = 1;
        var_r9_5 = 1;
        if (((u32) (temp_r10_4 + 0x80000000) >= 1U) && ((u32) ((arg3 & 0xFF800000) + 0x7F000000) >= 1U)) {
            var_r9_5 = 0;
        }
        if ((var_r9_5 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r8_5 = 0;
        }
        if ((var_r8_5 == 0) && ((u32) (temp_r10_4 + 0x40000000) >= 1U)) {
            var_r7_5 = 0;
        }
        if ((var_r7_5 == 0) && ((u32) ((arg3 & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r6_5 = 0;
        }
        if ((var_r6_5 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r5_5 = 0;
        }
        if ((var_r5_5 == 0) && ((u32) ((arg3 & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r4_4 = 0;
        }
        if (var_r4_4 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35E, base + 0x130, (f32 *) arg3);
        }
        if (arg4 < 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35F, base + 0x168, arg4, 0);
        }
        rectB[0] = lbl_80561178;
        rectB[1] = lbl_80561178;
        rectB[2] = lbl_80561178;
        rectB[3] = lbl_80561178;
        copyB[0x0] = (*(u8 *)((u8*)(arg0) + (0)));
        copyB[0x1] = (*(u8 *)((u8*)(arg0) + (1)));
        copyB[0x2] = (*(u8 *)((u8*)(arg0) + (2)));
        copyB[0x3] = (*(u8 *)((u8*)(arg0) + (3)));
        copyB[0x4] = (*(u8 *)((u8*)(arg0) + (4)));
        copyB[0x5] = (*(u8 *)((u8*)(arg0) + (5)));
        copyB[0x6] = (*(u8 *)((u8*)(arg0) + (6)));
        copyB[0x7] = (*(u8 *)((u8*)(arg0) + (7)));
        copyB[0x8] = (*(u8 *)((u8*)(arg0) + (8)));
        copyB[0x9] = (*(u8 *)((u8*)(arg0) + (9)));
        copyB[0xA] = (*(u8 *)((u8*)(arg0) + (0xA)));
        copyB[0xB] = (*(u8 *)((u8*)(arg0) + (0xB)));
        copyB[0xC] = (*(u8 *)((u8*)(arg0) + (0xC)));
        copyB[0xD] = (*(u8 *)((u8*)(arg0) + (0xD)));
        copyB[0xE] = (*(u8 *)((u8*)(arg0) + (0xE)));
        copyB[0xF] = (*(u8 *)((u8*)(arg0) + (0xF)));
        copyB[0x10] = (*(u8 *)((u8*)(arg0) + (0x10)));
        copyB[0x11] = (*(u8 *)((u8*)(arg0) + (0x11)));
        copyB[0x12] = (*(u8 *)((u8*)(arg0) + (0x12)));
        copyB[0x13] = (*(u8 *)((u8*)(arg0) + (0x13)));
        copyB[0x14] = (*(u8 *)((u8*)(arg0) + (0x14)));
        copyB[0x15] = (*(u8 *)((u8*)(arg0) + (0x15)));
        copyB[0x16] = (*(u8 *)((u8*)(arg0) + (0x16)));
        copyB[0x17] = (*(u8 *)((u8*)(arg0) + (0x17)));
        copyB[0x18] = (*(u8 *)((u8*)(arg0) + (0x18)));
        copyB[0x19] = (*(u8 *)((u8*)(arg0) + (0x19)));
        copyB[0x1A] = (*(u8 *)((u8*)(arg0) + (0x1A)));
        copyB[0x1B] = (*(u8 *)((u8*)(arg0) + (0x1B)));
        copyB[0x1C] = (*(u8 *)((u8*)(arg0) + (0x1C)));
        copyB[0x1D] = (*(u8 *)((u8*)(arg0) + (0x1D)));
        copyB[0x1E] = (*(u8 *)((u8*)(arg0) + (0x1E)));
        copyB[0x1F] = (*(u8 *)((u8*)(arg0) + (0x1F)));
        (*(s32*)(copyB+0x20)) = (*(s32 *)((u8*)(arg0) + (0x20)));
        s32 copyB_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
        s32 copyB_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
        (*(s32*)(copyB+0x24)) = copyB_24;
        (*(s32*)(copyB+0x28)) = copyB_28;
        s32 copyB_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
        s32 copyB_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
        (*(s32*)(copyB+0x2C)) = copyB_2C;
        (*(s32*)(copyB+0x30)) = copyB_30;
        (*(s32*)(copyB+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
        s32 copyB_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
        s32 copyB_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
        (*(s32*)(copyB+0x38)) = copyB_38;
        (*(s32*)(copyB+0x3C)) = copyB_3C;
        copyB[0x40] = (*(u8 *)((u8*)(arg0) + (0x40)));
        copyB[0x41] = (*(u8 *)((u8*)(arg0) + (0x41)));
        copyB[0x42] = (*(u8 *)((u8*)(arg0) + (0x42)));
        copyB[0x43] = (*(u8 *)((u8*)(arg0) + (0x43)));
        (*(f32*)(copyB+0x44)) = (*(f32 *)((u8*)(arg0) + (0x44)));
        (*(s32*)(copyB+0x48)) = (*(s32 *)((u8*)(arg0) + (0x48)));
        (*(f32*)(copyB+0x4C)) = (*(f32 *)((u8*)(arg0) + (0x4C)));
        (*(f32*)(copyB+0x50)) = (*(f32 *)((u8*)(arg0) + (0x50)));
        (*(s32*)(copyB+0x54)) = (*(s32 *)((u8*)(arg0) + (0x54)));
        (*(s32*)(copyB+0x58)) = (*(s32 *)((u8*)(arg0) + (0x58)));
        (*(s32*)(copyB+0x5C)) = (*(s32 *)((u8*)(arg0) + (0x5C)));
        SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyB[0x0], lbl_80561178, lbl_80561178);
        fn_8010E3BC((s32)&copyB[0x0], (s32)&rectB[0], arg3, arg4);
        temp_f2 = rectB[2] - rectB[0];
        fn_801033F0(&copyB[0x0], 0);
        temp_f2 = var_f31 - temp_f2;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *arg1 + (temp_f2 * lbl_80561188));
    } else if (temp_r0_4 == 2) {
        temp_r10_5 = (s32) arg0 & 0xFF000000;
        var_r4_5 = 1;
        var_r5_6 = 1;
        var_r6_6 = 1;
        var_r7_6 = 1;
        var_r8_6 = 1;
        var_r9_6 = 1;
        if (((u32) (temp_r10_5 + 0x80000000) >= 1U) && ((u32) (((s32) arg0 & 0xFF800000) + 0x7F000000) >= 1U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32) (temp_r10_5 + 0x40000000) >= 1U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32) (((s32) arg0 & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r6_6 = 0;
        }
        if ((var_r6_6 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r5_6 = 0;
        }
        if ((var_r5_6 == 0) && ((u32) (((s32) arg0 & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r4_5 = 0;
        }
        if (var_r4_5 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35D, base + 0x48, arg0);
        }
        temp_r10_6 = arg3 & 0xFF000000;
        var_r4_6 = 1;
        var_r5_7 = 1;
        var_r6_7 = 1;
        var_r7_7 = 1;
        var_r8_7 = 1;
        var_r9_7 = 1;
        if (((u32) (temp_r10_6 + 0x80000000) >= 1U) && ((u32) ((arg3 & 0xFF800000) + 0x7F000000) >= 1U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x70000000) >= 1U)) {
            var_r8_7 = 0;
        }
        if ((var_r8_7 == 0) && ((u32) (temp_r10_6 + 0x40000000) >= 1U)) {
            var_r7_7 = 0;
        }
        if ((var_r7_7 == 0) && ((u32) ((arg3 & 0xFF800000) + 0x3F000000) >= 1U)) {
            var_r6_7 = 0;
        }
        if ((var_r6_7 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x30000000) >= 1U)) {
            var_r5_7 = 0;
        }
        if ((var_r5_7 == 0) && ((u32) ((arg3 & 0xFFFFC000) + 0x20000000) >= 1U)) {
            var_r4_6 = 0;
        }
        if (var_r4_6 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35E, base + 0x130, (f32 *) arg3);
        }
        if (arg4 < 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35F, base + 0x168, arg4, 0);
        }
        rectC[0] = lbl_80561178;
        rectC[1] = lbl_80561178;
        rectC[2] = lbl_80561178;
        rectC[3] = lbl_80561178;
        copyC[0x0] = (*(u8 *)((u8*)(arg0) + (0)));
        copyC[0x1] = (*(u8 *)((u8*)(arg0) + (1)));
        copyC[0x2] = (*(u8 *)((u8*)(arg0) + (2)));
        copyC[0x3] = (*(u8 *)((u8*)(arg0) + (3)));
        copyC[0x4] = (*(u8 *)((u8*)(arg0) + (4)));
        copyC[0x5] = (*(u8 *)((u8*)(arg0) + (5)));
        copyC[0x6] = (*(u8 *)((u8*)(arg0) + (6)));
        copyC[0x7] = (*(u8 *)((u8*)(arg0) + (7)));
        copyC[0x8] = (*(u8 *)((u8*)(arg0) + (8)));
        copyC[0x9] = (*(u8 *)((u8*)(arg0) + (9)));
        copyC[0xA] = (*(u8 *)((u8*)(arg0) + (0xA)));
        copyC[0xB] = (*(u8 *)((u8*)(arg0) + (0xB)));
        copyC[0xC] = (*(u8 *)((u8*)(arg0) + (0xC)));
        copyC[0xD] = (*(u8 *)((u8*)(arg0) + (0xD)));
        copyC[0xE] = (*(u8 *)((u8*)(arg0) + (0xE)));
        copyC[0xF] = (*(u8 *)((u8*)(arg0) + (0xF)));
        copyC[0x10] = (*(u8 *)((u8*)(arg0) + (0x10)));
        copyC[0x11] = (*(u8 *)((u8*)(arg0) + (0x11)));
        copyC[0x12] = (*(u8 *)((u8*)(arg0) + (0x12)));
        copyC[0x13] = (*(u8 *)((u8*)(arg0) + (0x13)));
        copyC[0x14] = (*(u8 *)((u8*)(arg0) + (0x14)));
        copyC[0x15] = (*(u8 *)((u8*)(arg0) + (0x15)));
        copyC[0x16] = (*(u8 *)((u8*)(arg0) + (0x16)));
        copyC[0x17] = (*(u8 *)((u8*)(arg0) + (0x17)));
        copyC[0x18] = (*(u8 *)((u8*)(arg0) + (0x18)));
        copyC[0x19] = (*(u8 *)((u8*)(arg0) + (0x19)));
        copyC[0x1A] = (*(u8 *)((u8*)(arg0) + (0x1A)));
        copyC[0x1B] = (*(u8 *)((u8*)(arg0) + (0x1B)));
        copyC[0x1C] = (*(u8 *)((u8*)(arg0) + (0x1C)));
        copyC[0x1D] = (*(u8 *)((u8*)(arg0) + (0x1D)));
        copyC[0x1E] = (*(u8 *)((u8*)(arg0) + (0x1E)));
        copyC[0x1F] = (*(u8 *)((u8*)(arg0) + (0x1F)));
        (*(s32*)(copyC+0x20)) = (*(s32 *)((u8*)(arg0) + (0x20)));
        s32 copyC_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
        s32 copyC_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
        (*(s32*)(copyC+0x24)) = copyC_24;
        (*(s32*)(copyC+0x28)) = copyC_28;
        s32 copyC_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
        s32 copyC_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
        (*(s32*)(copyC+0x2C)) = copyC_2C;
        (*(s32*)(copyC+0x30)) = copyC_30;
        (*(s32*)(copyC+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
        s32 copyC_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
        s32 copyC_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
        (*(s32*)(copyC+0x38)) = copyC_38;
        (*(s32*)(copyC+0x3C)) = copyC_3C;
        copyC[0x40] = (*(u8 *)((u8*)(arg0) + (0x40)));
        copyC[0x41] = (*(u8 *)((u8*)(arg0) + (0x41)));
        copyC[0x42] = (*(u8 *)((u8*)(arg0) + (0x42)));
        copyC[0x43] = (*(u8 *)((u8*)(arg0) + (0x43)));
        (*(f32*)(copyC+0x44)) = (*(f32 *)((u8*)(arg0) + (0x44)));
        (*(s32*)(copyC+0x48)) = (*(s32 *)((u8*)(arg0) + (0x48)));
        (*(f32*)(copyC+0x4C)) = (*(f32 *)((u8*)(arg0) + (0x4C)));
        (*(f32*)(copyC+0x50)) = (*(f32 *)((u8*)(arg0) + (0x50)));
        (*(s32*)(copyC+0x54)) = (*(s32 *)((u8*)(arg0) + (0x54)));
        (*(s32*)(copyC+0x58)) = (*(s32 *)((u8*)(arg0) + (0x58)));
        (*(s32*)(copyC+0x5C)) = (*(s32 *)((u8*)(arg0) + (0x5C)));
        SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyC[0x0], lbl_80561178, lbl_80561178);
        fn_8010E3BC((s32)&copyC[0x0], (s32)&rectC[0], arg3, arg4);
        temp_f2 = rectC[2] - rectC[0];
        fn_801033F0(&copyC[0x0], 0);
        temp_f2 = var_f31 - temp_f2;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *arg1 + temp_f2);
    } else {
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *arg1);
    }
    if ((u32) ((*(s32 *)((u8*)(arg0) + (0x58))) & 0x300) == 0x300) {
        SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, *arg2);
    } else {
        SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, *arg2 + GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801058DC(arg0));
    }
    return var_f31;
}
#pragma dont_inline reset
extern "C" void* fn_80111B64(void* arg0) {
    extern void __ct__Q36nw4hbm2ut10CharWriterFv(void*);
    extern f32 lbl_80561178;
    extern s32 lbl_8055DEB8;
    f32 value;
    __ct__Q36nw4hbm2ut10CharWriterFv(arg0);
    value = lbl_80561178;
    *(f32*)((char*)arg0 + 0x4C) = value;
    *(f32*)((char*)arg0 + 0x50) = value;
    *(s32*)((char*)arg0 + 0x54) = 4;
    *(s32*)((char*)arg0 + 0x58) = 0;
    *(s32*)((char*)arg0 + 0x5C) = (s32)&lbl_8055DEB8;
    return arg0;
}

extern "C" void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80111BB8(void* arg0, int arg1) {
    extern void fn_801033F0(void*, unsigned int);
    extern void fn_80128668(void*);
    if (arg0 != 0) {
        fn_801033F0(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" f32 fn_80111C10(s32 arg0) {
    s32 temp_r11;
    s32 var_r5 = 1, var_r6 = 1, var_r7 = 1, var_r8 = 1, var_r9 = 1, var_r10 = 1;
    s32 var_r30, font;
    temp_r11 = arg0 & 0xFF000000;
    if ((u32)(temp_r11 + 0x80000000) < 1U && (u32)((arg0 & 0xFF800000) + 0x7F000000) < 1U) var_r10 = 0;
    if (var_r10 == 0 && (u32)((arg0 & 0xF8000000) + 0x70000000) < 1U) var_r9 = 0;
    if (var_r9 == 0 && (u32)(temp_r11 + 0x40000000) < 1U) var_r8 = 0;
    if (var_r8 == 0 && (u32)((arg0 & 0xFF800000) + 0x3F000000) < 1U) var_r7 = 0;
    if (var_r7 == 0 && (u32)((arg0 & 0xF8000000) + 0x30000000) < 1U) var_r6 = 0;
    if (var_r6 == 0 && (u32)((arg0 & 0xFFFFC000) + 0x20000000) < 1U) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560, 0xF1, lbl_80329578, arg0);
    font = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (font) {
        struct V { virtual int a0()=0; virtual int a1()=0; virtual int a2()=0; virtual int a3()=0; virtual int a4()=0; virtual int a5()=0; virtual int a6()=0; virtual int a7()=0; virtual int a8()=0; virtual int a9()=0; virtual int a10()=0; virtual int a11()=0; virtual int a12()=0; };
        var_r30 = ((V*)font)->a12();
    } else var_r30 = 0;
    return *(f32*)(arg0 + 0x50) + (f32)var_r30 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0);
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111D88(void *arg0, float farg0) {
 int var_r5=1; int var_r6=1; int var_r7=1; int var_r8=1; int var_r9=1; int var_r10=1;
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 if ((unsigned int)(temp_r11+0x80000000U)<1U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)<1U) var_r10=0;
 if (var_r10==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)<1U) var_r9=0;
 if (var_r9==0 && (unsigned int)(temp_r11+0x40000000U)<1U) var_r8=0;
 if (var_r8==0 && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)<1U) var_r7=0;
 if (var_r7==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)<1U) var_r6=0;
 if (var_r6==0 && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)<1U) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x105,lbl_80329578,arg0);
 *(float*)((char*)arg0+0x50)=farg0;
}

extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111EAC(void *arg0, float farg0) {
 int var_r5=1; int var_r6=1; int var_r7=1; int var_r8=1; int var_r9=1; int var_r10=1;
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 if ((unsigned int)(temp_r11+0x80000000U)<1U && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x7F000000U)<1U) var_r10=0;
 if (var_r10==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x70000000U)<1U) var_r9=0;
 if (var_r9==0 && (unsigned int)(temp_r11+0x40000000U)<1U) var_r8=0;
 if (var_r8==0 && (unsigned int)(((unsigned int)arg0&0xFF800000U)+0x3F000000U)<1U) var_r7=0;
 if (var_r7==0 && (unsigned int)(((unsigned int)arg0&0xF8000000U)+0x30000000U)<1U) var_r6=0;
 if (var_r6==0 && (unsigned int)(((unsigned int)arg0&0xFFFFC000U)+0x20000000U)<1U) var_r5=0;
 if(var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x116,lbl_80329578,arg0);
 *(float*)((char*)arg0+0x4C)=farg0;
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80111FD0(int arg0) {
 unsigned int temp_r11=(unsigned int)arg0&0xFF000000U;
 int var_r5=1,var_r6=1,var_r7=1,var_r8=1,var_r9=1,var_r10=1;
 if ((temp_r11+0x80000000U)>=1U && (((unsigned int)arg0&0xFF800000U)+0x7F000000U)>=1U) var_r10=0;
 if (var_r10==0 && (((unsigned int)arg0&0xF8000000U)+0x70000000U)>=1U) var_r9=0;
 if (var_r9==0 && temp_r11+0x40000000U>=1U) var_r8=0;
 if (var_r8==0 && (((unsigned int)arg0&0xFF800000U)+0x3F000000U)>=1U) var_r7=0;
 if (var_r7==0 && (((unsigned int)arg0&0xF8000000U)+0x30000000U)>=1U) var_r6=0;
 if (var_r6==0 && (((unsigned int)arg0&0xFFFFC000U)+0x20000000U)>=1U) var_r5=0;
 if (var_r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x138,lbl_80329578,arg0);
 return *(float*)((char*)arg0+0x4C);
}

extern "C" s32 GetFont__Q36nw4hbm2ut10CharWriterCFv_801120E8(void *arg0) {
 extern const char lbl_80329560[]; extern const char lbl_80329578[];
 extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
 u32 p=(u32)arg0; u32 hi=p&0xFF000000;
 s32 r5=1,r6=1,r7=1,r8=1,r9=1,r10=1;
 if ((u32)(hi+0x80000000)<1U && (u32)((p&0xFF800000)+0x7F000000)<1U) r10=0;
 if (r10==0 && (u32)((p&0xF8000000)+0x70000000)<1U) r9=0;
 if (r9==0 && (u32)(hi+0x40000000)<1U) r8=0;
 if (r8==0 && (u32)((p&0xFF800000)+0x3F000000)<1U) r7=0;
 if (r7==0 && (u32)((p&0xF8000000)+0x30000000)<1U) r6=0;
 if (r6==0 && (u32)((p&0xFFFFC000)+0x20000000)<1U) r5=0;
 if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x15A,lbl_80329578,arg0);
 return *(s32*)((char*)arg0+0x54);
}

void* nw4hbm::ut::CharWriter::GetFont() const {
    const unsigned int p = (unsigned int)this;
    unsigned int r5=1, r6=1, r7=1, r8=1, r9=1, r10=1;
    unsigned int r11=p&0xFF000000;
    if ((r11+0x80000000U)!=0 && ((p&0xFF800000)+0x7F000000U)!=0) r10=0;
    if (r10==0 && ((p&0xF8000000)+0x70000000U)!=0) r9=0;
    if (r9==0 && (r11+0x40000000U)!=0) r8=0;
    if (r8==0 && ((p&0xFF800000)+0x3F000000U)!=0) r7=0;
    if (r7==0 && ((p&0xF8000000)+0x30000000U)!=0) r6=0;
    if (r6==0 && ((p&0xFFFFC000)+0x20000000U)!=0) r5=0;
    if (r5==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560,0x97,lbl_80329578,this);
    return font;
}

extern "C" const char lbl_80329530[];
extern "C" f32 fn_80112528(void *arg0, const char *arg1, s32 arg2) {
    extern f32 fn_801142F8(void *, s32, s32);
    extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32);
    extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32);
    extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32, f32, f32);
    extern void fn_801033F0(void *, unsigned int);
    struct WriterCopy {
        u8 prefix[0x20];
        u32 word20;
        u32 word24;
        u32 word28;
        u32 word2C;
        u32 word30;
        u32 word34;
        u32 word38;
        u32 word3C;
        u8 bytes40[4];
        f32 float44;
        u32 word48;
        f32 float4C;
        f32 float50;
        u32 word54;
        u32 word58;
        u32 word5C;
    };
    register const char *file = lbl_80329530;
    register s32 r6 = 1;
    register s32 r7 = 1;
    register s32 r5 = 1;
    register s32 r8 = 1;
    register s32 r9 = 1;
    register s32 r10 = 1;
    register u32 hi0 = (u32)arg0 & 0xFF000000U;
    if (((u32)(hi0 + 0x80000000U) >= 1U) &&
        ((u32)(((u32)arg0 & 0xFF800000U) + 0x7F000000U) >= 1U)) {
        r10 = 0;
    }
    if ((r10 == 0) && ((u32)(((u32)arg0 & 0xF8000000U) + 0x70000000U) >= 1U)) {
        r9 = 0;
    }
    if ((r9 == 0) && ((u32)(hi0 + 0x40000000U) >= 1U)) {
        r8 = 0;
    }
    if ((r8 == 0) && ((u32)(((u32)arg0 & 0xFF800000U) + 0x3F000000U) >= 1U)) {
        r7 = 0;
    }
    if ((r7 == 0) && ((u32)(((u32)arg0 & 0xF8000000U) + 0x30000000U) >= 1U)) {
        r6 = 0;
    }
    if ((r6 == 0) && ((u32)(((u32)arg0 & 0xFFFFC000U) + 0x20000000U) >= 1U)) {
        r5 = 0;
    }
    if (r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2C1, file + 0x48, arg0);
    }

    register s32 r4 = 1;
    register s32 r5_2 = 1;
    register s32 r6_2 = 1;
    register s32 r7_2 = 1;
    register s32 r8_2 = 1;
    register s32 r9_2 = 1;
    register u32 hi1 = (u32)arg1 & 0xFF000000U;
    if (((u32)(hi1 + 0x80000000U) >= 1U) &&
        ((u32)(((u32)arg1 & 0xFF800000U) + 0x7F000000U) >= 1U)) {
        r9_2 = 0;
    }
    if ((r9_2 == 0) && ((u32)(((u32)arg1 & 0xF8000000U) + 0x70000000U) >= 1U)) {
        r8_2 = 0;
    }
    if ((r8_2 == 0) && ((u32)(hi1 + 0x40000000U) >= 1U)) {
        r7_2 = 0;
    }
    if ((r7_2 == 0) && ((u32)(((u32)arg1 & 0xFF800000U) + 0x3F000000U) >= 1U)) {
        r6_2 = 0;
    }
    if ((r6_2 == 0) && ((u32)(((u32)arg1 & 0xF8000000U) + 0x30000000U) >= 1U)) {
        r5_2 = 0;
    }
    if ((r5_2 == 0) && ((u32)(((u32)arg1 & 0xFFFFC000U) + 0x20000000U) >= 1U)) {
        r4 = 0;
    }
    if (r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2C2, file + 0x130, arg1);
    }
    if (arg2 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2C3, file + 0x168, arg2, 0);
    }

    WriterCopy *source = (WriterCopy *)arg0;
    WriterCopy copy;
    copy.prefix[0] = source->prefix[0];
    copy.prefix[1] = source->prefix[1];
    copy.prefix[2] = source->prefix[2];
    copy.prefix[3] = source->prefix[3];
    copy.prefix[4] = source->prefix[4];
    copy.prefix[5] = source->prefix[5];
    copy.prefix[6] = source->prefix[6];
    copy.prefix[7] = source->prefix[7];
    copy.prefix[8] = source->prefix[8];
    copy.prefix[9] = source->prefix[9];
    copy.prefix[10] = source->prefix[10];
    copy.prefix[11] = source->prefix[11];
    copy.prefix[12] = source->prefix[12];
    copy.prefix[13] = source->prefix[13];
    copy.prefix[14] = source->prefix[14];
    copy.prefix[15] = source->prefix[15];
    copy.prefix[16] = source->prefix[16];
    copy.prefix[17] = source->prefix[17];
    copy.prefix[18] = source->prefix[18];
    copy.prefix[19] = source->prefix[19];
    copy.prefix[20] = source->prefix[20];
    copy.prefix[21] = source->prefix[21];
    copy.prefix[22] = source->prefix[22];
    copy.prefix[23] = source->prefix[23];
    copy.prefix[24] = source->prefix[24];
    copy.prefix[25] = source->prefix[25];
    copy.prefix[26] = source->prefix[26];
    copy.prefix[27] = source->prefix[27];
    copy.prefix[28] = source->prefix[28];
    copy.prefix[29] = source->prefix[29];
    copy.prefix[30] = source->prefix[30];
    copy.prefix[31] = source->prefix[31];
    copy.word20 = source->word20;
    u32 pair24 = source->word24;
    u32 pair28 = source->word28;
    copy.word24 = pair24;
    copy.word28 = pair28;
    u32 pair2C = source->word2C;
    u32 pair30 = source->word30;
    copy.word2C = pair2C;
    copy.word30 = pair30;
    copy.word34 = source->word34;
    u32 pair38 = source->word38;
    u32 pair3C = source->word3C;
    copy.word38 = pair38;
    copy.word3C = pair3C;
    copy.bytes40[0] = source->bytes40[0];
    copy.bytes40[1] = source->bytes40[1];
    copy.bytes40[2] = source->bytes40[2];
    copy.bytes40[3] = source->bytes40[3];
    copy.float44 = source->float44;
    copy.word48 = source->word48;
    copy.float4C = source->float4C;
    copy.float50 = source->float50;
    copy.word54 = source->word54;
    copy.word58 = source->word58;
    copy.word5C = source->word5C;
    f32 result = fn_801142F8(&copy, (s32)arg1, arg2);
    f32 scale = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770((s32)&copy);
    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)arg0,
        GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658((s32)&copy), scale);
    fn_801033F0(&copy, 0);
    return result;
}

extern "C" f32 fn_80112960(u8 *arg0, u8 *arg1) {
    extern s32 fn_8002AEE8(s32);
    extern f32 fn_801142F8(void *, s32, s32);
    extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(void *);
    extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(void *);
    extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(void *, f32, f32);
    extern void fn_801033F0(void *, s32);
    u8 writer[0x60];
    s32 width = fn_8002AEE8((s32)arg1);
    f32 result = fn_801142F8(writer, (s32)arg1, width);
    f32 scale = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(writer);
    GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(writer);
    SetCursor__Q36nw4hbm2ut10CharWriterFff(arg0, 0.0f, scale);
    fn_801033F0(writer, 0);
    return result;
}

extern "C" s32 fn_80112EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(s32);
extern s32 IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(s32);
extern void SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32);
extern s32 fn_8002F72C(void*,const void*);
extern u16 fn_8002F768(s32*);
extern f32 lbl_80561178;
extern const char lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80329530[],lbl_80329938[],lbl_80329900[],lbl_803298EC[],lbl_803298B4[],lbl_803298A0[],lbl_80329824[],lbl_80320AFC[],lbl_80320AC4[],lbl_80320B48[],lbl_80320B10[];
class Reader { public: s32 cursor; u16 (Reader::*next)(); };
Reader reader;
struct Context { s32 writer,str; u32 x,y; s32 flags; } context;
f32 rect[4];
class Font { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual s32 ascent(); virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual s32 width(u16); };
class Processor { public: virtual void d0(); virtual void d1(); virtual s32 rectCall(f32*,u16,Context*); };

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f28;
    f32 temp_f29;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f31;
    const char* base;
    u16 var_r28;
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r14;
    s32 temp_r20;
    s32 temp_r21;
    s32 temp_r22;
    u32 temp_r24;
    s32 temp_r23;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r30;
    s32 temp_r3_2;
    u32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r5;
    s32 temp_r7;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r19;
    s32 var_r20;
    s32 var_r20_2;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r4_5;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r5_8;
    s32 var_r5_9;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_3;
    s32 var_r6_4;
    s32 var_r6_5;
    s32 var_r6_6;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    u32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_9;
    void **temp_r3_10;

    base = lbl_80329530;
    temp_r24 = arg0 & 0xFF000000;
    var_r10 = 1;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    if (((u32) (temp_r24) != 0x80000000U) && ((u32) ((arg0 & 0xFF800000)) != 0x81000000U)) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0x90000000U)) {
        var_r8 = 0;
    }
    if ((var_r8 == 0) && ((u32) (temp_r24) != 0xC0000000U)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((u32) ((arg0 & 0xFF800000)) != 0xC1000000U)) {
        var_r6 = 0;
    }
    if ((var_r6 == 0) && ((u32) ((arg0 & 0xF8000000)) != 0xD0000000U)) {
        var_r5 = 0;
    }
    if ((var_r5 == 0) && ((u32) ((arg0 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r10 = 0;
    }
    if (var_r10 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37D, base + 0x48, arg0);
    }
    var_r9_2 = arg1 & 0xFF000000;
    temp_r10 = 1;
    var_r4 = 1;
    var_r5_2 = 1;
    var_r6_2 = 1;
    var_r7_2 = 1;
    var_r8_2 = 1;
    if (((u32) (var_r9_2) != 0x80000000U) && ((u32) ((arg1 & 0xFF800000)) != 0x81000000U)) {
        var_r8_2 = 0;
    }
    if ((var_r8_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0x90000000U)) {
        var_r7_2 = 0;
    }
    if ((var_r7_2 == 0) && ((u32) (var_r9_2) != 0xC0000000U)) {
        var_r6_2 = 0;
    }
    if ((var_r6_2 == 0) && ((u32) ((arg1 & 0xFF800000)) != 0xC1000000U)) {
        var_r5_2 = 0;
    }
    if ((var_r5_2 == 0) && ((u32) ((arg1 & 0xF8000000)) != 0xD0000000U)) {
        var_r4 = 0;
    }
    if ((var_r4 == 0) && ((u32) ((arg1 & 0xFFFFC000)) != 0xE0000000U)) {
        temp_r10 = 0;
    }
    if (temp_r10 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37E, base + 0xF8, arg1);
    }
    temp_r14 = arg2 & 0xFF000000;
    var_r4_2 = 1;
    var_r5_3 = 1;
    var_r6_3 = 1;
    var_r7_3 = 1;
    var_r8_3 = 1;
    var_r9_3 = 1;
    if (((u32) (temp_r14) != 0x80000000U) && ((u32) ((arg2 & 0xFF800000)) != 0x81000000U)) {
        var_r9_3 = 0;
    }
    if ((var_r9_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0x90000000U)) {
        var_r8_3 = 0;
    }
    if ((var_r8_3 == 0) && ((u32) (temp_r14) != 0xC0000000U)) {
        var_r7_3 = 0;
    }
    if ((var_r7_3 == 0) && ((u32) ((arg2 & 0xFF800000)) != 0xC1000000U)) {
        var_r6_3 = 0;
    }
    if ((var_r6_3 == 0) && ((u32) ((arg2 & 0xF8000000)) != 0xD0000000U)) {
        var_r5_3 = 0;
    }
    if ((var_r5_3 == 0) && ((u32) ((arg2 & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_2 = 0;
    }
    if (var_r4_2 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x37F, base + 0x130, arg2);
    }
    if (arg3 < 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x380, base + 0x168, arg3, 0);
    }
    context.writer = arg0;
    context.x = 0;
    context.y = 0;
    context.flags = 0;
    context.str = arg2;
    temp_r3_2 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    var_r9_4 = temp_r3_2 & 0xFF000000;
    var_f31 = lbl_80561178;
    var_r19 = 0;
    temp_r11 = 1;
    var_r10_2 = 1;
    var_r5_4 = 1;
    var_r6_4 = 1;
    var_r7_4 = 1;
    var_r8_4 = 1;
    if (((u32) (var_r9_4) != 0x80000000U) && ((u32) ((temp_r3_2 & 0xFF800000)) != 0x81000000U)) {
        var_r8_4 = 0;
    }
    if ((var_r8_4 == 0) && ((u32) ((temp_r3_2 & 0xF8000000)) != 0x90000000U)) {
        var_r7_4 = 0;
    }
    if ((var_r7_4 == 0) && ((u32) (var_r9_4) != 0xC0000000U)) {
        var_r6_4 = 0;
    }
    if ((var_r6_4 == 0) && ((u32) ((temp_r3_2 & 0xFF800000)) != 0xC1000000U)) {
        var_r5_4 = 0;
    }
    if ((var_r5_4 == 0) && ((u32) ((temp_r3_2 & 0xF8000000)) != 0xD0000000U)) {
        var_r10_2 = 0;
    }
    if ((var_r10_2 == 0) && ((u32) ((temp_r3_2 & 0xFFFFC000)) != 0xE0000000U)) {
        temp_r11 = 0;
    }
    if (temp_r11 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x386, base + 0x20C, temp_r3_2);
    }
    GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, temp_r3_2);
    var_r5_5 = 0;
    temp_f0 = lbl_80561178;
    *(f32*)(arg1 + 0) = temp_f0;
    *(f32*)(arg1 + 8) = temp_f0;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4 = arg0 & 0xFF800000, (((u32) (temp_r4) == 0x81000000U) != 0)) || (temp_r3_3 = arg0 & 0xF8000000, (((u32) (temp_r3_3) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4) == 0xC1000000U) || ((u32) (temp_r3_3) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_5 = 1;
    }
    if (var_r5_5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_4 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_4 != 0) {
        var_r20 = ((Font*)temp_r3_4)->ascent();
    } else {
        var_r20 = 0;
    }
    var_f1 = *(f32*)(arg0 + 0x50) + ((f32) var_r20 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    var_f1 = (lbl_80561178 > var_f1) ? var_f1 : lbl_80561178;
    *(f32*)(arg1 + 4) = var_f1;
    var_r5_6 = 0;
    if (((u32) (temp_r24) == 0x80000000U) || (temp_r4_2 = arg0 & 0xFF800000, (((u32) (temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_5 = arg0 & 0xF8000000, (((u32) (temp_r3_5) == 0x90000000U) != 0)) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r4_2) == 0xC1000000U) || ((u32) (temp_r3_5) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_6 = 1;
    }
    if (var_r5_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0xF1, base + 0x48, arg0);
    }
    temp_r3_6 = GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0);
    if (temp_r3_6 != 0) {
        var_r20_2 = ((Font*)temp_r3_6)->ascent();
    } else {
        var_r20_2 = 0;
    }
    var_f1_2 = *(f32*)(arg0 + 0x50) + ((f32) var_r20_2 * GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(arg0));
    if (lbl_80561178 >= var_f1_2) { var_f1_2 = lbl_80561178; }
    *(f32*)(arg1 + 0xC) = var_f1_2;
    temp_r23 = (s32) &reader.cursor & 0xFF000000;
    var_r4_3 = 1;
    var_r5_7 = 1;
    var_r6_5 = 1;
    var_r7_5 = 1;
    var_r8_5 = 1;
    var_r9_5 = 1;
    if (((u32) (temp_r23) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0x81000000U)) {
        var_r9_5 = 0;
    }
    if ((var_r9_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0x90000000U)) {
        var_r8_5 = 0;
    }
    if ((var_r8_5 == 0) && ((u32) (temp_r23) != 0xC0000000U)) {
        var_r7_5 = 0;
    }
    if ((var_r7_5 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000)) != 0xC1000000U)) {
        var_r6_5 = 0;
    }
    if ((var_r6_5 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000)) != 0xD0000000U)) {
        var_r5_7 = 0;
    }
    if ((var_r5_7 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000)) != 0xE0000000U)) {
        var_r4_3 = 0;
    }
    if (var_r4_3 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
    }
    if (arg2 & 1) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, arg2);
    }
    var_r5_8 = 0;
    if (((u32) (temp_r14) == 0x80000000U) || (temp_r4_3 = arg2 & 0xFF800000, (((u32) (temp_r4_3) == 0x81000000U) != 0)) || (temp_r3_7 = arg2 & 0xF8000000, (((u32) (temp_r3_7) == 0x90000000U) != 0)) || ((u32) (temp_r14) == 0xC0000000U) || ((u32) (temp_r4_3) == 0xC1000000U) || ((u32) (temp_r3_7) == 0xD0000000U) || ((u32) ((arg2 & 0xFFFFC000)) == 0xE0000000U)) {
        var_r5_8 = 1;
    }
    if (var_r5_8 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, arg2);
    }
    if (fn_8002F72C(&reader.next, lbl_80329530) != 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
    }
    reader.cursor = arg2;
    var_r6_6 = 0;
    if (((u32) (temp_r23) == 0x80000000U) || (temp_r4_4 = (s32) &reader.cursor & 0xFF800000, (((u32) (temp_r4_4) == 0x81000000U) != 0)) || (temp_r3_8 = (s32) &reader.cursor & 0xF8000000, (((u32) (temp_r3_8) == 0x90000000U) != 0)) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r4_4) == 0xC1000000U) || ((u32) (temp_r3_8) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000)) == 0xE0000000U)) {
        var_r6_6 = 1;
    }
    if (var_r6_6 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
    }
    temp_f28 = lbl_80561178;
    var_r28 = fn_8002F768(&reader.cursor);
    temp_r22 = (s32) &reader.cursor & 0xFF800000;
    temp_r21 = (s32) &reader.cursor & 0xF8000000;
    temp_r20 = (s32) &reader.cursor & 0xFFFFC000;
    temp_r27 = arg0 & 0xFF800000;
    temp_r26 = arg0 & 0xF8000000;
    temp_r31 = temp_r23 + 0x80000000;
loop_275:
    if (!((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U))) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
    }
    if ((s32) var_r28 < 0x20) {
        rect[0] = var_f31;
        var_r3_2 = 0;
        rect[1] = temp_f28;
        rect[2] = temp_f28;
        rect[3] = temp_f28;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_2 = 1;
        }
        if (var_r3_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
        }
        context.str = reader.cursor;
        context.flags = var_r19 == 0;
        SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, var_f31);
        temp_r3_10 = *(void***)(arg0+0x5C);
        temp_r30 = ((Processor*)temp_r3_10)->rectCall(rect,var_r28,&context);
        var_r0 = 1;
        var_r3_3 = 1;
        temp_r7 = context.str & 0xFF000000;
        var_r4_4 = 1;
        var_r5_9 = 1;
        var_r9_6 = 1;
        var_r10_3 = 1;
        if (((u32) (temp_r7) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r10_3 = 0;
        }
        if ((var_r10_3 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32) (temp_r7) != 0xC0000000U)) {
            var_r5_9 = 0;
        }
        if ((var_r5_9 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_4 = 0;
        }
        if ((var_r4_4 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_3 = 0;
        }
        if ((var_r3_3 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3A8, base + 0x244);
        }
        var_r3_4 = 0;
        if (((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_4 = 1;
        }
        if (var_r3_4 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
        }
        if (context.str & 1) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, context.str);
        }
        temp_r5 = context.str & 0xFF000000;
        var_r0_2 = 1;
        var_r3_5 = 1;
        var_r7_6 = 1;
        var_r4_5 = 1;
        var_r8_6 = 1;
        var_r9_7 = 1;
        if (((u32) (temp_r5) != 0x80000000U) && ((u32) ((context.str & 0xFF800000)) != 0x81000000U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32) ((context.str & 0xF8000000)) != 0x90000000U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32) (temp_r5) != 0xC0000000U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32) ((context.str & 0xFF800000)) != 0xC1000000U)) {
            var_r4_5 = 0;
        }
        if ((var_r4_5 == 0) && ((u32) ((context.str & 0xF8000000)) != 0xD0000000U)) {
            var_r3_5 = 0;
        }
        if ((var_r3_5 == 0) && ((u32) ((context.str & 0xFFFFC000)) != 0xE0000000U)) {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, context.str);
        }
        if (fn_8002F72C(&reader.next, lbl_80329530) != 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
        }
        reader.cursor = context.str;
        var_f1_3 = rect[0];
        temp_f0 = *(f32*)(arg1 + 0);
        if (temp_f0 <= var_f1_3) { var_f1_3 = temp_f0; }
        *(f32*)(arg1 + 0) = var_f1_3;
        temp_f0_2 = *(f32*)(arg1 + 4);
        var_f1_4 = rect[1];
        if (temp_f0_2 <= var_f1_4) { var_f1_4 = temp_f0_2; }
        *(f32*)(arg1 + 4) = var_f1_4;
        temp_f0_3 = *(f32*)(arg1 + 8);
        var_f1_5 = rect[2];
        if (temp_f0_3 >= var_f1_5) { var_f1_5 = temp_f0_3; }
        *(f32*)(arg1 + 8) = var_f1_5;
        temp_f0_4 = *(f32*)(arg1 + 0xC);
        var_f1_6 = rect[3];
        if (temp_f0_4 >= var_f1_6) { var_f1_6 = temp_f0_4; }
        *(f32*)(arg1 + 0xC) = var_f1_6;
        var_f31 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(arg0);
        switch (temp_r30) {                         /* irregular */
        case 4:
            return arg3;
        case 1:
            var_r19 = 0;
            goto block_264;
        case 2:
            var_r19 = 1;
            goto block_264;
        case 3:
block_286:
            if (!(((u32) (temp_r23) == 0x80000000U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U))) {
                Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
            }
            temp_r3 = reader.cursor - arg2;
            return (reader.cursor - arg2) >> 1;
        }
    } else {
        if (var_r19 != 0) {
            var_r3_7 = 0;
            if (((u32) (temp_r24) == 0x80000000U) || ((u32) (temp_r27) == 0x81000000U) || ((u32) (temp_r26) == 0x90000000U) || ((u32) (temp_r24) == 0xC0000000U) || ((u32) (temp_r27) == 0xC1000000U) || ((u32) (temp_r26) == 0xD0000000U) || ((u32) ((arg0 & 0xFFFFC000)) == 0xE0000000U)) {
                var_r3_7 = 1;
            }
            if (var_r3_7 == 0) {
                Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x138, base + 0x48, arg0);
            }
            var_f31 += *(f32*)(arg0 + 0x4C);
        }
        var_r19 = 1;
        if (IsWidthFixed__Q36nw4hbm2ut10CharWriterCFv(arg0) != 0) {
            var_f31 += GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80105C2C(arg0);
        } else {
            temp_f29 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv(arg0);
            var_f31 += (f32) ((Font*)GetFont__Q36nw4hbm2ut10CharWriterCFv(arg0))->width(var_r28) * temp_f29;
        }
        var_f0 = *(f32*)(arg1 + 0);
        if (var_f0 > var_f31) {
            var_f0 = var_f31;
        }
        var_f1_7 = *(f32*)(arg1 + 8);
        *(f32*)(arg1 + 0) = var_f0;
        if (var_f1_7 < var_f31) {
            var_f1_7 = var_f31;
        }
        *(f32*)(arg1 + 8) = var_f1_7;
block_264:
        var_r3_8 = 0;
        if ((temp_r31 == 0U) || ((u32) (temp_r22) == 0x81000000U) || ((u32) (temp_r21) == 0x90000000U) || ((u32) (temp_r23) == 0xC0000000U) || ((u32) (temp_r22) == 0xC1000000U) || ((u32) (temp_r21) == 0xD0000000U) || ((u32) (temp_r20) == 0xE0000000U)) {
            var_r3_8 = 1;
        }
        if (var_r3_8 == 0) {
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
        }
        var_r28 = fn_8002F768(&reader.cursor);
        goto loop_275;
    }
}

#pragma push
#pragma optimize_for_size on
extern "C" void fn_80113F08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern const char lbl_80329530[];
    extern f32 lbl_80561178;
    extern void SetCursor__Q36nw4hbm2ut10CharWriterFff(s32, f32, f32);
    volatile f32 sp14, sp10, spC, sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f31;
    f32 var_f1, var_f1_2, var_f1_3, var_f1_4;
    s32 temp_r3;
    s32 var_r29, var_r30;
    s32 var_r4, var_r5, var_r6, var_r7, var_r8, var_r9, var_r10;
    s32 temp_r10, temp_r10_2;
    s32 temp_r11;
    const char *base = lbl_80329530;
    volatile f32 *rect = (volatile f32 *)arg1;
    temp_r11 = arg0 & 0xFF000000;
    var_r29 = arg2;
    var_r30 = arg3;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r10 = 1;
    if (((u32)(temp_r11 + 0x80000000U) >= 1U) &&
        ((u32)((arg0 & 0xFF800000U) + 0x7F000000U) >= 1U)) var_r10 = 0;
    if ((var_r10 == 0) && ((u32)((arg0 & 0xF8000000U) + 0x70000000U) >= 1U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)(temp_r11 + 0x40000000U) >= 1U)) var_r8 = 0;
    if ((var_r8 == 0) && ((u32)((arg0 & 0xFF800000U) + 0x3F000000U) >= 1U)) var_r7 = 0;
    if ((var_r7 == 0) && ((u32)((arg0 & 0xF8000000U) + 0x30000000U) >= 1U)) var_r6 = 0;
    if ((var_r6 == 0) && ((u32)((arg0 & 0xFFFFC000U) + 0x20000000U) >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F2, base + 0x48, arg0);
    temp_r10 = arg1 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r4 = 1;
    if (((u32)(temp_r10 + 0x80000000U) >= 1U) &&
        ((u32)((arg1 & 0xFF800000U) + 0x7F000000U) >= 1U)) var_r4 = 0;
    if ((var_r4 == 0) && ((u32)((arg1 & 0xF8000000U) + 0x70000000U) >= 1U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)(temp_r10 + 0x40000000U) >= 1U)) var_r8 = 0;
    if ((var_r8 == 0) && ((u32)((arg1 & 0xFF800000U) + 0x3F000000U) >= 1U)) var_r7 = 0;
    if ((var_r7 == 0) && ((u32)((arg1 & 0xF8000000U) + 0x30000000U) >= 1U)) var_r6 = 0;
    if ((var_r6 == 0) && ((u32)((arg1 & 0xFFFFC000U) + 0x20000000U) >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F3, base + 0xF8, arg1);
    temp_r10_2 = var_r29 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r4 = 1;
    if (((u32)(temp_r10_2 + 0x80000000U) >= 1U) &&
        ((u32)((var_r29 & 0xFF800000U) + 0x7F000000U) >= 1U)) var_r4 = 0;
    if ((var_r4 == 0) && ((u32)((var_r29 & 0xF8000000U) + 0x70000000U) >= 1U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)(temp_r10_2 + 0x40000000U) >= 1U)) var_r8 = 0;
    if ((var_r8 == 0) && ((u32)((var_r29 & 0xFF800000U) + 0x3F000000U) >= 1U)) var_r7 = 0;
    if ((var_r7 == 0) && ((u32)((var_r29 & 0xF8000000U) + 0x30000000U) >= 1U)) var_r6 = 0;
    if ((var_r6 == 0) && ((u32)((var_r29 & 0xFFFFC000U) + 0x20000000U) >= 1U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F4, base + 0x130, var_r29);
    if (var_r30 < 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F5, base + 0x168, var_r30, 0);
    register f32 zero = lbl_80561178;
    *(f32 *)arg1 = zero;
    rect[2] = zero;
    rect[1] = zero;
    rect[3] = zero;
    SetCursor__Q36nw4hbm2ut10CharWriterFff(arg0, zero, zero);
    temp_f31 = lbl_80561178;
    do {
        sp8 = temp_f31;
        spC = temp_f31;
        sp10 = temp_f31;
        sp14 = temp_f31;
        temp_r3 = fn_80112EA0(arg0, (s32)&sp8, var_r29, var_r30);
        var_f1 = sp8;
        var_r29 += temp_r3 * 2;
        temp_f0 = rect[0];
        var_r30 -= temp_r3;
        var_f1 = temp_f0 > var_f1 ? var_f1 : temp_f0;
        rect[0] = var_f1;
        temp_f0_2 = rect[1];
        var_f1_2 = spC;
        var_f1_2 = temp_f0_2 > var_f1_2 ? var_f1_2 : temp_f0_2;
        rect[1] = var_f1_2;
        temp_f0_3 = rect[2];
        var_f1_3 = sp10;
        var_f1_3 = temp_f0_3 < var_f1_3 ? var_f1_3 : temp_f0_3;
        rect[2] = var_f1_3;
        temp_f0_4 = rect[3];
        var_f1_4 = sp14;
        var_f1_4 = temp_f0_4 < var_f1_4 ? var_f1_4 : temp_f0_4;
        rect[3] = var_f1_4;
    } while (var_r30 > 0);
}
#pragma pop
    extern "C" f32 fn_801142F8(void *writer, s32 arg1, s32 arg2) {
                      extern void GetCharStrmReader__Q36nw4hbm2ut4FontCFv(void*,s32);
                      extern s32 GetFont__Q36nw4hbm2ut10CharWriterCFv(s32);
                      extern f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(s32),GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(s32);
                      extern void MoveCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524(s32,f32),Print__Q36nw4hbm2ut10CharWriterFUs(s32,u16),SetCursorX__Q36nw4hbm2ut10CharWriterFf(s32,f32),SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(s32,f32),SetCursor__Q36nw4hbm2ut10CharWriterFff(s32,f32,f32);
                      extern s32 fn_8002F72C(void*,const void*);
                      extern u16 fn_8002F768(s32*);
                      extern void fn_801033F0(void*,unsigned int);
                      extern void fn_80112EA0(void*,f32*,s32,s32);
                      extern f32 fn_80115848(s32,f32*,f32*,s32,s32);
                      extern f32 lbl_80561178,lbl_80561188;
                      extern const char lbl_80320980[],lbl_803209B8[],lbl_803209CC[],lbl_80320A04[],lbl_80320A18[],lbl_80320A64[],lbl_80320A78[],lbl_80320AB0[],lbl_80320AC4[],lbl_80320AFC[],lbl_80320B10[],lbl_80320B48[],lbl_80329530[];
                       nw4hbm::ut::CharWriter copyRight;
                       nw4hbm::ut::CharWriter copyCenter;
                       class Reader { public: s32 cursor; u16 (Reader::*next)(); };
                       Reader reader;
                       struct { s32 writer, str; f32 x, y; s32 flags; } context;
                       f32 rectRight[4], rectCenter[4];
                       const char *messageBase;
             void *arg0;
                              
                          void **sp114;
                          void **spB4;
                          f32 spC;
                          f32 sp8;
                          f32 temp_f25;
                          f32 temp_f26;
                          f32 temp_f28;
                          f32 temp_f31;
                          f32 var_f0;
                          f32 var_f29;
                          f32 temp_f1;
                          f32 temp_f1_2;
                          f32 temp_f24;
                          s32 var_r5;
                   s32 var_r6;
                  s32 var_r7;
                 s32 var_r8;
                s32 var_r9;
               s32 var_r10;
                    s32 temp_r18;
                          s32 temp_r18_2;
                          s32 temp_r19;
                          s32 temp_r19_2;                      s32 temp_r21;
                                        s32 temp_r23;
                          s32 temp_r24;
                          s32 temp_r25;
                          s32 temp_r26;
                          s32 temp_r27;
                          s32 temp_r28;
                          s32 temp_r3;
                          s32 temp_r3_2;
                          s32 temp_r3_5;
                          s32 temp_r4;
                          s32 temp_r4_2;
                          s32 temp_r4_3;
                          s32 temp_r4_5;
                          s32 temp_r4_7;
                          s32 temp_r4_8;
                          s32 temp_r5;
                          s32 var_r0;
                          s32 var_r0_2;
                          s32 var_r0_3;
                          s32 var_r0_4;
                          s32 var_r0_5;
                                     s32 var_r10_2;
                          s32 var_r10_3;
                          s32 var_r14;
                          s32 var_r20;
                          s32 var_r3;
                          s32 var_r3_10;
                          s32 var_r3_11;
                          s32 var_r3_12;
                          s32 var_r3_2;
                          s32 var_r3_3;
                          s32 var_r3_4;
                          s32 var_r3_5;
                          s32 var_r3_6;
                          s32 var_r3_7;
                          s32 var_r3_8;
                          s32 var_r3_9;
                          s32 var_r4;
                          s32 var_r4_2;
                          s32 var_r4_3;
                                s32 var_r5_2;
                          s32 var_r5_3;
                          s32 var_r5_4;
                                 s32 var_r6_2;
                          s32 var_r6_3;
                          s32 var_r6_4;
                          s32 var_r6_5;
                          s32 var_r6_6;
                          s32 var_r6_7;
                                  s32 var_r7_2;
                          s32 var_r7_3;
                          s32 var_r7_4;
                          s32 var_r7_5;
                          s32 var_r7_6;
                          s32 var_r7_7;
                                   s32 var_r8_2;
                          s32 var_r8_3;
                          s32 var_r8_4;
                          s32 var_r8_5;
                          s32 var_r8_6;
                          s32 var_r8_7;
                          s32 var_r8_8;
                                    s32 var_r9_2;
                          s32 var_r9_3;
                          s32 var_r9_4;
                          s32 var_r9_5;
                          s32 var_r9_6;
                          s32 var_r9_7;
                          s32 var_r9_8;
          u32 temp_r22;
                          u16 var_r19;
                          u32 temp_r0;
                          u32 temp_r0_2;
                          u32 temp_r31;
                          u32 temp_r3_3;
                          u32 temp_r4_4;
                          u32 temp_r4_6;
                          void **temp_r3_4;
                      
                          
                    arg0 = writer;
                     temp_r22 = ((u32)arg0) & 0xFF000000;
                          messageBase = lbl_80329530;
                          var_r5 = 1;
                          var_r6 = 1;
                          var_r7 = 1;
                          var_r8 = 1;
                          var_r9 = 1;
                          var_r10 = 1;
                          if (((u32)(temp_r22) != 0x80000000U) && ((u32)(((u32)arg0) & 0xFF800000) != 0x81000000U)) {
                              var_r10 = 0;
                          }
                          if ((var_r10 == 0) && ((u32)(((u32)arg0) & 0xF8000000) != 0x90000000U)) {
                              var_r9 = 0;
                          }
                          if ((var_r9 == 0) && ((u32)(temp_r22) != 0xC0000000U)) {
                              var_r8 = 0;
                          }
                          if ((var_r8 == 0) && ((u32)(((u32)arg0) & 0xFF800000) != 0xC1000000U)) {
                              var_r7 = 0;
                          }
                          if ((var_r7 == 0) && ((u32)(((u32)arg0) & 0xF8000000) != 0xD0000000U)) {
                              var_r6 = 0;
                          }
                          if ((var_r6 == 0) && ((u32)(((u32)arg0) & 0xFFFFC000) != 0xE0000000U)) {
                              var_r5 = 0;
                          }
                          if (var_r5 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x41F, messageBase + 0x48, arg0);
                          }
                          temp_r18 = arg1 & 0xFF000000;
                          var_r4 = 1;
                          var_r5_2 = 1;
                          var_r6_2 = 1;
                          var_r7_2 = 1;
                          var_r8_2 = 1;
                          var_r9_2 = 1;
                          if (((u32)(temp_r18) != 0x80000000U) && ((u32)(arg1 & 0xFF800000) != 0x81000000U)) {
                              var_r9_2 = 0;
                          }
                          if ((var_r9_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0x90000000U)) {
                              var_r8_2 = 0;
                          }
                          if ((var_r8_2 == 0) && ((u32)(temp_r18) != 0xC0000000U)) {
                              var_r7_2 = 0;
                          }
                          if ((var_r7_2 == 0) && ((u32)(arg1 & 0xFF800000) != 0xC1000000U)) {
                              var_r6_2 = 0;
                          }
                          if ((var_r6_2 == 0) && ((u32)(arg1 & 0xF8000000) != 0xD0000000U)) {
                              var_r5_2 = 0;
                          }
                          if ((var_r5_2 == 0) && ((u32)(arg1 & 0xFFFFC000) != 0xE0000000U)) {
                              var_r4 = 0;
                          }
                          if (var_r4 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x420, messageBase + 0x130, arg1);
                          }
                          var_r14 = 0;
                          if (((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xFF000000) + 0x80000000) == 0U) || ((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xFF800000) + 0x7F000000) == 0U) || ((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xF8000000) + 0x70000000) == 0U) || ((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xFF000000) + 0x40000000) == 0U) || ((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xFF800000) + 0x3F000000) == 0U) || ((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xF8000000) + 0x30000000) == 0U) || ((u32) ((((u32)GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0)) & 0xFFFFC000) + 0x20000000) == 0U)) {
                              var_r14 = 1;
                          }
                          if (var_r14 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x421, messageBase + 0x280, GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0));
                          }
                          if (arg2 < 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x422, messageBase + 0x168, arg2, 0);
                          }
                          spC = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658((s32)arg0);
                          temp_f1 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770((s32)arg0);
                          temp_f28 = (f32) temp_f1;
                          sp8 = (f32) temp_f1;
                          var_r20 = 0;
                          var_f29 = fn_80115848((s32)arg0, &spC, &sp8, arg1, arg2);
                          GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658((s32)arg0);
                          temp_f1_2 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770((s32)arg0);
                          context.x = 0.0f;
                          context.y = 0.0f;
                          context.flags = 0;
                          context.writer = (s32)arg0;
                          context.str = arg1;
                          context.x = spC;
                          context.y = sp8;
                          GetCharStrmReader__Q36nw4hbm2ut4FontCFv(&reader.cursor, GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0));
                          var_r4_2 = 1;
                          temp_r21 = (s32) &reader.cursor & 0xFF000000;
                          var_r5_3 = 1;
                          var_r6_3 = 1;
                          var_r7_3 = 1;
                          var_r8_3 = 1;
                          var_r9_3 = 1;
                          if (((u32)(temp_r21) != 0x80000000U) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x7F000000) != 0U)) {
                              var_r9_3 = 0;
                          }
                          if ((var_r9_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x70000000) != 0U)) {
                              var_r8_3 = 0;
                          }
                          if ((var_r8_3 == 0) && ((u32)(temp_r21) != 0xC0000000U)) {
                              var_r7_3 = 0;
                          }
                          if ((var_r7_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFF800000) + 0x3F000000) != 0U)) {
                              var_r6_3 = 0;
                          }
                          if ((var_r6_3 == 0) && ((u32) (((s32) &reader.cursor & 0xF8000000) + 0x30000000) != 0U)) {
                              var_r5_3 = 0;
                          }
                          if ((var_r5_3 == 0) && ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) != 0U)) {
                              var_r4_2 = 0;
                          }
                          if (var_r4_2 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
                          }
                          if (arg1 & 1) {
                              Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, arg1);
                          }
                          var_r5_4 = 0;
                          if (((u32)(temp_r18) == 0x80000000U) || (temp_r4 = arg1 & 0xFF800000, (((u32)(temp_r4) == 0x81000000U) != 0)) || (temp_r3 = arg1 & 0xF8000000, (((u32)(temp_r3) == 0x90000000U) != 0)) || ((u32)(temp_r18) == 0xC0000000U) || ((u32)(temp_r4) == 0xC1000000U) || ((u32)(temp_r3) == 0xD0000000U) || ((u32)(arg1 & 0xFFFFC000) == 0xE0000000U)) {
                              var_r5_4 = 1;
                          }
                          if (var_r5_4 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, arg1);
                          }
                          if (fn_8002F72C(&reader.next, messageBase) != 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
                          }
                          reader.cursor = arg1;
                          var_r6_4 = 0;
                          if (((u32)(temp_r21) == 0x80000000U) || (temp_r4_2 = (s32) &reader.cursor & 0xFF800000, (((u32)(temp_r4_2) == 0x81000000U) != 0)) || (temp_r3_2 = (s32) &reader.cursor & 0xF8000000, (((u32)(temp_r3_2) == 0x90000000U) != 0)) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r4_2) == 0xC1000000U) || ((u32)(temp_r3_2) == 0xD0000000U) || ((u32) (((s32) &reader.cursor & 0xFFFFC000) + 0x20000000) == 0U)) {
                              var_r6_4 = 1;
                          }
                          if (var_r6_4 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
                          }
                          temp_f31 = lbl_80561178;
                          temp_f25 = lbl_80561188;
                          var_r19 = (reader.*reader.next)();
                          temp_r28 = (s32) &reader.cursor & 0xFF800000;
                          temp_r27 = (s32) &reader.cursor & 0xF8000000;
                          temp_r26 = (s32) &reader.cursor & 0xFFFFC000;
                          temp_r25 = ((u32)arg0) & 0xFF800000;
                          temp_r24 = ((u32)arg0) & 0xF8000000;
                          temp_r23 = ((u32)arg0) & 0xFFFFC000;
                          temp_r31 = temp_r21 + 0x80000000;
                      loop_286:
                          var_r3 = 0;
                          if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                              var_r3 = 1;
                          }
                          if (var_r3 == 0) {
                              Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
                          }
                          temp_r3_3 = reader.cursor - arg1;
                          if ((s32) ((s32) ((temp_r3_3 >> 0x1FU) + temp_r3_3) >> 1) <= arg2) {
                              if ((s32) var_r19 < 0x20) {
                                  var_r3_2 = 0;
                                  if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                                      var_r3_2 = 1;
                                  }
                                  if (var_r3_2 == 0) {
                                      Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AFC, 0x44, lbl_80320AC4, (s32) &reader.cursor);
                                  }
                                  context.str = reader.cursor;
                                  context.flags = var_r20 == 0;
                                  temp_r3_4 = *(void ***)(((u8 *)arg0) + 0x5C);
                                  temp_r3_5 = (*(s32 (**)(void **, u16, s32 *))((char*)*temp_r3_4+0xC))(temp_r3_4, var_r19, &context.writer);
                                  switch (temp_r3_5) {                    /* irregular */
                                  case 4:
                                      break;
                                  case 3:
                                      var_r0 = 1;
                                      var_r3_3 = 1;
                                      var_r7_4 = 1;
                                      temp_r4_3 = context.str & 0xFF000000;
                                      var_r8_4 = 1;
                                      var_r9_4 = 1;
                                      var_r10_2 = 1;
                                      if (((u32)(temp_r4_3) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                                          var_r10_2 = 0;
                                      }
                                      if ((var_r10_2 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                                          var_r9_4 = 0;
                                      }
                                      if ((var_r9_4 == 0) && ((u32)(temp_r4_3) != 0xC0000000U)) {
                                          var_r8_4 = 0;
                                      }
                                      if ((var_r8_4 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                                          var_r7_4 = 0;
                                      }
                                      if ((var_r7_4 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                                          var_r3_3 = 0;
                                      }
                                      if ((var_r3_3 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                                          var_r0 = 0;
                                      }
                                      if (var_r0 == 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x449, messageBase + 0x244);
                                      }
                                      temp_r0 = *(s32 *)(((u8 *)arg0) + 0x58) & 3;
                                      if (temp_r0 == 1) {
                                          var_r3_4 = 0;
                                          temp_r4_4 = context.str - arg1;
                                          temp_r19 = arg2 - ((s32) ((temp_r4_4 >> 0x1FU) + temp_r4_4) >> 1);
                                          if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                                              var_r3_4 = 1;
                                          }
                                          if (var_r3_4 == 0) {
                                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x35D, messageBase + 0x48, arg0);
                                          }
                                          temp_r4_5 = context.str & 0xFF000000;
                                          var_r0_2 = 1;
                                          var_r3_5 = 1;
                                          var_r6_5 = 1;
                                          var_r7_5 = 1;
                                          var_r8_5 = 1;
                                          var_r9_5 = 1;
                                          if (((u32)(temp_r4_5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                                              var_r9_5 = 0;
                                          }
                                          if ((var_r9_5 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                                              var_r8_5 = 0;
                                          }
                                          if ((var_r8_5 == 0) && ((u32)(temp_r4_5) != 0xC0000000U)) {
                                              var_r7_5 = 0;
                                          }
                                          if ((var_r7_5 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                                              var_r6_5 = 0;
                                          }
                                          if ((var_r6_5 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                                              var_r3_5 = 0;
                                          }
                                          if ((var_r3_5 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                                              var_r0_2 = 0;
                                          }
                                          if (var_r0_2 == 0) {
                                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x35E, messageBase + 0x130, context.str);
                                          }
                                          if (temp_r19 < 0) {
                                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x35F, messageBase + 0x168, temp_r19, 0);
                                          }
                                          rectRight[0] = temp_f31;
                                          rectRight[1] = temp_f31;
                                          rectRight[2] = temp_f31;
                                          rectRight[3] = temp_f31;
                                          *(u8 *)((u8*)&copyRight+0) = *(u8 *)(((u8 *)arg0) + 0);
                                          *(u8 *)((u8*)&copyRight+1) = *(u8 *)(((u8 *)arg0) + 1);
                                          *(u8 *)((u8*)&copyRight+2) = *(u8 *)(((u8 *)arg0) + 2);
                                          *(u8 *)((u8*)&copyRight+3) = *(u8 *)(((u8 *)arg0) + 3);
                                          *(u8 *)((u8*)&copyRight+4) = *(u8 *)(((u8 *)arg0) + 4);
                                          *(u8 *)((u8*)&copyRight+5) = *(u8 *)(((u8 *)arg0) + 5);
                                          *(u8 *)((u8*)&copyRight+6) = *(u8 *)(((u8 *)arg0) + 6);
                                          *(u8 *)((u8*)&copyRight+7) = *(u8 *)(((u8 *)arg0) + 7);
                                          *(u8 *)((u8*)&copyRight+8) = *(u8 *)(((u8 *)arg0) + 8);
                                          *(u8 *)((u8*)&copyRight+9) = *(u8 *)(((u8 *)arg0) + 9);
                                          *(u8 *)((u8*)&copyRight+10) = *(u8 *)(((u8 *)arg0) + 0xA);
                                          *(u8 *)((u8*)&copyRight+11) = *(u8 *)(((u8 *)arg0) + 0xB);
                                          *(u8 *)((u8*)&copyRight+12) = *(u8 *)(((u8 *)arg0) + 0xC);
                                          *(u8 *)((u8*)&copyRight+13) = *(u8 *)(((u8 *)arg0) + 0xD);
                                          *(u8 *)((u8*)&copyRight+14) = *(u8 *)(((u8 *)arg0) + 0xE);
                                          *(u8 *)((u8*)&copyRight+15) = *(u8 *)(((u8 *)arg0) + 0xF);
                                          *(u8 *)((u8*)&copyRight+16) = *(u8 *)(((u8 *)arg0) + 0x10);
                                          *(u8 *)((u8*)&copyRight+17) = *(u8 *)(((u8 *)arg0) + 0x11);
                                          *(u8 *)((u8*)&copyRight+18) = *(u8 *)(((u8 *)arg0) + 0x12);
                                          *(u8 *)((u8*)&copyRight+19) = *(u8 *)(((u8 *)arg0) + 0x13);
                                          *(u8 *)((u8*)&copyRight+20) = *(u8 *)(((u8 *)arg0) + 0x14);
                                          *(u8 *)((u8*)&copyRight+21) = *(u8 *)(((u8 *)arg0) + 0x15);
                                          *(u8 *)((u8*)&copyRight+22) = *(u8 *)(((u8 *)arg0) + 0x16);
                                          *(u8 *)((u8*)&copyRight+23) = *(u8 *)(((u8 *)arg0) + 0x17);
                                          *(u8 *)((u8*)&copyRight+24) = *(u8 *)(((u8 *)arg0) + 0x18);
                                          *(u8 *)((u8*)&copyRight+25) = *(u8 *)(((u8 *)arg0) + 0x19);
                                          *(u8 *)((u8*)&copyRight+26) = *(u8 *)(((u8 *)arg0) + 0x1A);
                                          *(u8 *)((u8*)&copyRight+27) = *(u8 *)(((u8 *)arg0) + 0x1B);
                                          *(u8 *)((u8*)&copyRight+28) = *(u8 *)(((u8 *)arg0) + 0x1C);
                                          *(u8 *)((u8*)&copyRight+29) = *(u8 *)(((u8 *)arg0) + 0x1D);
                                          *(u8 *)((u8*)&copyRight+30) = *(u8 *)(((u8 *)arg0) + 0x1E);
                                          *(u8 *)((u8*)&copyRight+31) = *(u8 *)(((u8 *)arg0) + 0x1F);
                                          *(s32 *)((u8*)&copyRight+32) = *(s32 *)(((u8 *)arg0) + 0x20);
                                          *(s32 *)((u8*)&copyRight+36) = *(s32 *)(((u8 *)arg0) + 0x24);
                                          *(s32 *)((u8*)&copyRight+40) = *(s32 *)(((u8 *)arg0) + 0x28);
                                          *(s32 *)((u8*)&copyRight+44) = *(s32 *)(((u8 *)arg0) + 0x2C);
                                          *(s32 *)((u8*)&copyRight+48) = *(s32 *)(((u8 *)arg0) + 0x30);
                                          *(s32 *)((u8*)&copyRight+52) = *(s32 *)(((u8 *)arg0) + 0x34);
                                          *(s32 *)((u8*)&copyRight+56) = *(s32 *)(((u8 *)arg0) + 0x38);
                                          *(s32 *)((u8*)&copyRight+60) = *(s32 *)(((u8 *)arg0) + 0x3C);
                                          *(u8 *)((u8*)&copyRight+64) = *(u8 *)(((u8 *)arg0) + 0x40);
                                          *(u8 *)((u8*)&copyRight+65) = *(u8 *)(((u8 *)arg0) + 0x41);
                                          *(u8 *)((u8*)&copyRight+66) = *(u8 *)(((u8 *)arg0) + 0x42);
                                          *(u8 *)((u8*)&copyRight+67) = *(u8 *)(((u8 *)arg0) + 0x43);
                                          *(f32 *)((u8*)&copyRight+68) = *(f32 *)(((u8 *)arg0) + 0x44);
                                          *(s32 *)((u8*)&copyRight+72) = *(s32 *)(((u8 *)arg0) + 0x48);
                                          *(f32 *)((u8*)&copyRight+76) = *(f32 *)(((u8 *)arg0) + 0x4C);
                                          *(f32 *)((u8*)&copyRight+80) = *(f32 *)(((u8 *)arg0) + 0x50);
                                          *(s32 *)((u8*)&copyRight+84) = *(s32 *)(((u8 *)arg0) + 0x54);
                                          *(s32 *)((u8*)&copyRight+88) = *(s32 *)(((u8 *)arg0) + 0x58);
                                          *(void ***)((u8*)&copyRight+92) = *(void ***)(((u8 *)arg0) + 0x5C);
                                          SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyRight, temp_f31, temp_f31);
                                          fn_80112EA0((u8*)&copyRight, &rectRight[0], context.str, temp_r19);
                                          fn_801033F0((u8*)&copyRight, 0);
                                          SetCursorX__Q36nw4hbm2ut10CharWriterFf((s32)arg0, context.x + ((var_f29 - (rectRight[2] - rectRight[0])) * temp_f25));
                                      } else if (temp_r0 == 2) {
                                          var_r3_6 = 0;
                                          temp_r4_6 = context.str - arg1;
                                          temp_r19_2 = arg2 - ((s32) ((temp_r4_6 >> 0x1FU) + temp_r4_6) >> 1);
                                          if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                                              var_r3_6 = 1;
                                          }
                                          if (var_r3_6 == 0) {
                                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x35D, messageBase + 0x48, arg0);
                                          }
                                          temp_r4_7 = context.str & 0xFF000000;
                                          var_r0_3 = 1;
                                          var_r3_7 = 1;
                                          var_r6_6 = 1;
                                          var_r7_6 = 1;
                                          var_r8_6 = 1;
                                          var_r9_6 = 1;
                                          if (((u32)(temp_r4_7) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                                              var_r9_6 = 0;
                                          }
                                          if ((var_r9_6 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                                              var_r8_6 = 0;
                                          }
                                          if ((var_r8_6 == 0) && ((u32)(temp_r4_7) != 0xC0000000U)) {
                                              var_r7_6 = 0;
                                          }
                                          if ((var_r7_6 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                                              var_r6_6 = 0;
                                          }
                                          if ((var_r6_6 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                                              var_r3_7 = 0;
                                          }
                                          if ((var_r3_7 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                                              var_r0_3 = 0;
                                          }
                                          if (var_r0_3 == 0) {
                                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x35E, messageBase + 0x130, context.str);
                                          }
                                          if (temp_r19_2 < 0) {
                                              Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x35F, messageBase + 0x168, temp_r19_2, 0);
                                          }
                                          rectCenter[0] = temp_f31;
                                          rectCenter[1] = temp_f31;
                                          rectCenter[2] = temp_f31;
                                          rectCenter[3] = temp_f31;
                                          *(u8 *)((u8*)&copyCenter+0) = *(u8 *)(((u8 *)arg0) + 0);
                                          *(u8 *)((u8*)&copyCenter+1) = *(u8 *)(((u8 *)arg0) + 1);
                                          *(u8 *)((u8*)&copyCenter+2) = *(u8 *)(((u8 *)arg0) + 2);
                                          *(u8 *)((u8*)&copyCenter+3) = *(u8 *)(((u8 *)arg0) + 3);
                                          *(u8 *)((u8*)&copyCenter+4) = *(u8 *)(((u8 *)arg0) + 4);
                                          *(u8 *)((u8*)&copyCenter+5) = *(u8 *)(((u8 *)arg0) + 5);
                                          *(u8 *)((u8*)&copyCenter+6) = *(u8 *)(((u8 *)arg0) + 6);
                                          *(u8 *)((u8*)&copyCenter+7) = *(u8 *)(((u8 *)arg0) + 7);
                                          *(u8 *)((u8*)&copyCenter+8) = *(u8 *)(((u8 *)arg0) + 8);
                                          *(u8 *)((u8*)&copyCenter+9) = *(u8 *)(((u8 *)arg0) + 9);
                                          *(u8 *)((u8*)&copyCenter+10) = *(u8 *)(((u8 *)arg0) + 0xA);
                                          *(u8 *)((u8*)&copyCenter+11) = *(u8 *)(((u8 *)arg0) + 0xB);
                                          *(u8 *)((u8*)&copyCenter+12) = *(u8 *)(((u8 *)arg0) + 0xC);
                                          *(u8 *)((u8*)&copyCenter+13) = *(u8 *)(((u8 *)arg0) + 0xD);
                                          *(u8 *)((u8*)&copyCenter+14) = *(u8 *)(((u8 *)arg0) + 0xE);
                                          *(u8 *)((u8*)&copyCenter+15) = *(u8 *)(((u8 *)arg0) + 0xF);
                                          *(u8 *)((u8*)&copyCenter+16) = *(u8 *)(((u8 *)arg0) + 0x10);
                                          *(u8 *)((u8*)&copyCenter+17) = *(u8 *)(((u8 *)arg0) + 0x11);
                                          *(u8 *)((u8*)&copyCenter+18) = *(u8 *)(((u8 *)arg0) + 0x12);
                                          *(u8 *)((u8*)&copyCenter+19) = *(u8 *)(((u8 *)arg0) + 0x13);
                                          *(u8 *)((u8*)&copyCenter+20) = *(u8 *)(((u8 *)arg0) + 0x14);
                                          *(u8 *)((u8*)&copyCenter+21) = *(u8 *)(((u8 *)arg0) + 0x15);
                                          *(u8 *)((u8*)&copyCenter+22) = *(u8 *)(((u8 *)arg0) + 0x16);
                                          *(u8 *)((u8*)&copyCenter+23) = *(u8 *)(((u8 *)arg0) + 0x17);
                                          *(u8 *)((u8*)&copyCenter+24) = *(u8 *)(((u8 *)arg0) + 0x18);
                                          *(u8 *)((u8*)&copyCenter+25) = *(u8 *)(((u8 *)arg0) + 0x19);
                                          *(u8 *)((u8*)&copyCenter+26) = *(u8 *)(((u8 *)arg0) + 0x1A);
                                          *(u8 *)((u8*)&copyCenter+27) = *(u8 *)(((u8 *)arg0) + 0x1B);
                                          *(u8 *)((u8*)&copyCenter+28) = *(u8 *)(((u8 *)arg0) + 0x1C);
                                          *(u8 *)((u8*)&copyCenter+29) = *(u8 *)(((u8 *)arg0) + 0x1D);
                                          *(u8 *)((u8*)&copyCenter+30) = *(u8 *)(((u8 *)arg0) + 0x1E);
                                          *(u8 *)((u8*)&copyCenter+31) = *(u8 *)(((u8 *)arg0) + 0x1F);
                                          *(s32 *)((u8*)&copyCenter+32) = *(s32 *)(((u8 *)arg0) + 0x20);
                                          *(s32 *)((u8*)&copyCenter+36) = *(s32 *)(((u8 *)arg0) + 0x24);
                                          *(s32 *)((u8*)&copyCenter+40) = *(s32 *)(((u8 *)arg0) + 0x28);
                                          *(s32 *)((u8*)&copyCenter+44) = *(s32 *)(((u8 *)arg0) + 0x2C);
                                          *(s32 *)((u8*)&copyCenter+48) = *(s32 *)(((u8 *)arg0) + 0x30);
                                          *(s32 *)((u8*)&copyCenter+52) = *(s32 *)(((u8 *)arg0) + 0x34);
                                          *(s32 *)((u8*)&copyCenter+56) = *(s32 *)(((u8 *)arg0) + 0x38);
                                          *(s32 *)((u8*)&copyCenter+60) = *(s32 *)(((u8 *)arg0) + 0x3C);
                                          *(u8 *)((u8*)&copyCenter+64) = *(u8 *)(((u8 *)arg0) + 0x40);
                                          *(u8 *)((u8*)&copyCenter+65) = *(u8 *)(((u8 *)arg0) + 0x41);
                                          *(u8 *)((u8*)&copyCenter+66) = *(u8 *)(((u8 *)arg0) + 0x42);
                                          *(u8 *)((u8*)&copyCenter+67) = *(u8 *)(((u8 *)arg0) + 0x43);
                                          *(f32 *)((u8*)&copyCenter+68) = *(f32 *)(((u8 *)arg0) + 0x44);
                                          *(s32 *)((u8*)&copyCenter+72) = *(s32 *)(((u8 *)arg0) + 0x48);
                                          *(f32 *)((u8*)&copyCenter+76) = *(f32 *)(((u8 *)arg0) + 0x4C);
                                          *(f32 *)((u8*)&copyCenter+80) = *(f32 *)(((u8 *)arg0) + 0x50);
                                          *(s32 *)((u8*)&copyCenter+84) = *(s32 *)(((u8 *)arg0) + 0x54);
                                          *(s32 *)((u8*)&copyCenter+88) = *(s32 *)(((u8 *)arg0) + 0x58);
                                          *(void ***)((u8*)&copyCenter+92) = *(void ***)(((u8 *)arg0) + 0x5C);
                                          SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyCenter, temp_f31, temp_f31);
                                          fn_80112EA0((u8*)&copyCenter, &rectCenter[0], context.str, temp_r19_2);
                                          fn_801033F0((u8*)&copyCenter, 0);
                                          SetCursorX__Q36nw4hbm2ut10CharWriterFf((s32)arg0, context.x + (var_f29 - (rectCenter[2] - rectCenter[0])));
                                      } else {
                                          var_f0 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658((s32)arg0) - context.x;
                                          if (var_f29 < var_f0) {
                      
                                          } else {
                                              var_f0 = var_f29;
                                          }
                                          var_f29 = var_f0;
                                          SetCursorX__Q36nw4hbm2ut10CharWriterFf((s32)arg0, context.x);
                                      }
                                      var_r20 = 0;
                                  default:
                      block_207:
                                      var_r0_4 = 1;
                                      var_r3_8 = 1;
                                      var_r4_3 = 1;
                                      temp_r5 = context.str & 0xFF000000;
                                      var_r8_7 = 1;
                                      var_r9_7 = 1;
                                      var_r10_3 = 1;
                                      if (((u32)(temp_r5) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                                          var_r10_3 = 0;
                                      }
                                      if ((var_r10_3 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                                          var_r9_7 = 0;
                                      }
                                      if ((var_r9_7 == 0) && ((u32)(temp_r5) != 0xC0000000U)) {
                                          var_r8_7 = 0;
                                      }
                                      if ((var_r8_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                                          var_r4_3 = 0;
                                      }
                                      if ((var_r4_3 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                                          var_r3_8 = 0;
                                      }
                                      if ((var_r3_8 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                                          var_r0_4 = 0;
                                      }
                                      if (var_r0_4 == 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x471, messageBase + 0x244);
                                      }
                                      var_r3_9 = 0;
                                      if (((u32)(temp_r21) == 0x80000000U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                                          var_r3_9 = 1;
                                      }
                                      if (var_r3_9 == 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320AB0, 0x3B, lbl_80320A78, (s32) &reader.cursor);
                                      }
                                      if (context.str & 1) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A64, 0x3C, lbl_80320A18, context.str);
                                      }
                                      temp_r4_8 = context.str & 0xFF000000;
                                      var_r0_5 = 1;
                                      var_r3_10 = 1;
                                      var_r6_7 = 1;
                                      var_r7_7 = 1;
                                      var_r8_8 = 1;
                                      var_r9_8 = 1;
                                      if (((u32)(temp_r4_8) != 0x80000000U) && ((u32)(context.str & 0xFF800000) != 0x81000000U)) {
                                          var_r9_8 = 0;
                                      }
                                      if ((var_r9_8 == 0) && ((u32)(context.str & 0xF8000000) != 0x90000000U)) {
                                          var_r8_8 = 0;
                                      }
                                      if ((var_r8_8 == 0) && ((u32)(temp_r4_8) != 0xC0000000U)) {
                                          var_r7_7 = 0;
                                      }
                                      if ((var_r7_7 == 0) && ((u32)(context.str & 0xFF800000) != 0xC1000000U)) {
                                          var_r6_7 = 0;
                                      }
                                      if ((var_r6_7 == 0) && ((u32)(context.str & 0xF8000000) != 0xD0000000U)) {
                                          var_r3_10 = 0;
                                      }
                                      if ((var_r3_10 == 0) && ((u32)(context.str & 0xFFFFC000) != 0xE0000000U)) {
                                          var_r0_5 = 0;
                                      }
                                      if (var_r0_5 == 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320A04, 0x3D, lbl_803209CC, context.str);
                                      }
                                      if (fn_8002F72C(&reader.next, messageBase) != 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(lbl_803209B8, 0x3E, lbl_80320980);
                                      }
                                      reader.cursor = context.str;
                                      goto block_275;
                                  case 1:
                                      var_r20 = 0;
                                      goto block_207;
                                  case 2:
                                      var_r20 = 1;
                                      goto block_207;
                                  }
                              } else {
                                  temp_f24 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770((s32)arg0);
                                  if (var_r20 != 0) {
                                      var_r3_11 = 0;
                                      if (((u32)(temp_r22) == 0x80000000U) || ((u32)(temp_r25) == 0x81000000U) || ((u32)(temp_r24) == 0x90000000U) || ((u32)(temp_r22) == 0xC0000000U) || ((u32)(temp_r25) == 0xC1000000U) || ((u32)(temp_r24) == 0xD0000000U) || ((u32)(temp_r23) == 0xE0000000U)) {
                                          var_r3_11 = 1;
                                      }
                                      if (var_r3_11 == 0) {
                                          Panic__Q26nw4hbm2dbFPCciPCce(messageBase + 0x30, 0x138, messageBase + 0x48, arg0);
                                      }
                                      MoveCursorX__Q36nw4hbm2ut10CharWriterFf((s32)arg0, *(f32 *)(((u8 *)arg0) + 0x4C));
                                  }
                                  var_r20 = 1;
                                  temp_r18_2 = GetFont__Q36nw4hbm2ut10CharWriterCFv((s32)arg0);
                                  temp_f26 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80104F90((s32)arg0);
                                  MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524((s32)arg0, (f32) -(*(s32 (**)(s32))(*(s32*)temp_r18_2+0x1C))(temp_r18_2) * temp_f26);
                                  Print__Q36nw4hbm2ut10CharWriterFUs((s32)arg0, var_r19);
                                  SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC((s32)arg0, temp_f24);
                      block_275:
                                  var_r3_12 = 0;
                                  if ((temp_r31 == 0U) || ((u32)(temp_r28) == 0x81000000U) || ((u32)(temp_r27) == 0x90000000U) || ((u32)(temp_r21) == 0xC0000000U) || ((u32)(temp_r28) == 0xC1000000U) || ((u32)(temp_r27) == 0xD0000000U) || ((u32)(temp_r26) == 0xE0000000U)) {
                                      var_r3_12 = 1;
                                  }
                                  if (var_r3_12 == 0) {
                                      Panic__Q26nw4hbm2dbFPCciPCce(lbl_80320B48, 0x4A, lbl_80320B10, (s32) &reader.cursor);
                                  }
                                  var_r19 = (reader.*reader.next)();
                                  goto loop_286;
                              }
                          }
                          temp_r0_2 = *(s32 *)(((u8 *)arg0) + 0x58) & 0x300;
                          if ((temp_r0_2 == 0x100) || (temp_r0_2 == 0x200)) {
                              SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC((s32)arg0, (f64) temp_f28);
                          } else {
                              MoveCursorX__Q36nw4hbm2ut10CharWriterFf_80106524((s32)arg0, temp_f28 - (f32) temp_f1_2);
                          }
                          return var_f29;
                      }

#pragma dont_inline on
extern "C" f32 fn_80115848(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4) {
     const char *base = lbl_80329530;
     u8 copyA[0x60], copyB[0x60], copyC[0x60];
     f32 rectA[4], rectB[4], rectC[4];
     f32 temp_f2;
     f32 var_f2;
     f32 var_f31;
     s32 temp_r10;
     s32 temp_r10_2;
     s32 temp_r10_3;
     s32 temp_r10_4;
     s32 temp_r10_5;
     s32 temp_r10_6;
     s32 temp_r11;
     s32 var_r10;
     s32 var_r4;
     s32 var_r4_2;
     s32 var_r4_3;
     s32 var_r4_4;
     s32 var_r4_5;
     s32 var_r4_6;
     s32 var_r5;
     s32 var_r5_2;
     s32 var_r5_3;
     s32 var_r5_4;
     s32 var_r5_5;
     s32 var_r5_6;
     s32 var_r5_7;
     s32 var_r6;
     s32 var_r6_2;
     s32 var_r6_3;
     s32 var_r6_4;
     s32 var_r6_5;
     s32 var_r6_6;
     s32 var_r6_7;
     s32 var_r7;
     s32 var_r7_2;
     s32 var_r7_3;
     s32 var_r7_4;
     s32 var_r7_5;
     s32 var_r7_6;
     s32 var_r7_7;
     s32 var_r8;
     s32 var_r8_2;
     s32 var_r8_3;
     s32 var_r8_4;
     s32 var_r8_5;
     s32 var_r8_6;
     s32 var_r8_7;
     s32 var_r9;
     s32 var_r9_2;
     s32 var_r9_3;
     s32 var_r9_4;
     s32 var_r9_5;
     s32 var_r9_6;
     s32 var_r9_7;
     u32 temp_r0;
     u32 temp_r0_2;
     u32 temp_r0_3;
     u32 temp_r0_4;
 
     var_f31 = lbl_80561178;
     temp_r0 = (*(s32 *)((u8*)(arg0) + (0x58))) & 0x333;
     var_f2 = var_f31;
     if ((temp_r0 != 0x300) && ((s32) temp_r0 != 0)) {
         temp_r11 = (s32) arg0 & 0xFF000000;
         rectA[0] = var_f31;
         var_r5 = 1;
         rectA[1] = var_f31;
         var_r6 = 1;
         var_r7 = 1;
         rectA[2] = var_f31;
         var_r8 = 1;
         var_r9 = 1;
         var_r10 = 1;
         rectA[3] = var_f31;
         if ((u32)(temp_r11 + 0x80000000) == 0U) {
         } else if ((u32)(((s32)arg0 & 0xFF800000) + 0x7F000000) == 0U) {
         } else {
             var_r10 = 0;
         }
         if ((var_r10 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r9 = 0;
         }
         if ((var_r9 == 0) && ((u32) (temp_r11 + 0x40000000) >= 1U)) {
             var_r8 = 0;
         }
         if ((var_r8 == 0) && ((u32) (((s32) arg0 & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r7 = 0;
         }
         if ((var_r7 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r6 = 0;
         }
         if ((var_r6 == 0) && ((u32) (((s32) arg0 & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r5 = 0;
         }
         if (var_r5 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x224, base + 0x48, arg0);
         }
         var_r4 = 1;
         temp_r10 = (s32) &rectA[0] & 0xFF000000;
         var_r5_2 = 1;
         var_r6_2 = 1;
         var_r7_2 = 1;
         var_r8_2 = 1;
         var_r9_2 = 1;
         if (((u32) (temp_r10 + 0x80000000) >= 1U) && ((u32) (((s32) &rectA[0] & 0xFF800000) + 0x7F000000) >= 1U)) {
             var_r9_2 = 0;
         }
         if ((var_r9_2 == 0) && ((u32) (((s32) &rectA[0] & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r8_2 = 0;
         }
         if ((var_r8_2 == 0) && ((u32) (temp_r10 + 0x40000000) >= 1U)) {
             var_r7_2 = 0;
         }
         if ((var_r7_2 == 0) && ((u32) (((s32) &rectA[0] & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r6_2 = 0;
         }
         if ((var_r6_2 == 0) && ((u32) (((s32) &rectA[0] & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r5_2 = 0;
         }
         if ((var_r5_2 == 0) && ((u32) (((s32) &rectA[0] & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r4 = 0;
         }
         if (var_r4 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x225, base + 0xF8, &rectA[0]);
         }
         temp_r10_2 = arg3 & 0xFF000000;
         var_r4_2 = 1;
         var_r5_3 = 1;
         var_r6_3 = 1;
         var_r7_3 = 1;
         var_r8_3 = 1;
         var_r9_3 = 1;
         if (((u32) (temp_r10_2 + 0x80000000) >= 1U) && ((u32) ((arg3 & 0xFF800000) + 0x7F000000) >= 1U)) {
             var_r9_3 = 0;
         }
         if ((var_r9_3 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r8_3 = 0;
         }
         if ((var_r8_3 == 0) && ((u32) (temp_r10_2 + 0x40000000) >= 1U)) {
             var_r7_3 = 0;
         }
         if ((var_r7_3 == 0) && ((u32) ((arg3 & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r6_3 = 0;
         }
         if ((var_r6_3 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r5_3 = 0;
         }
         if ((var_r5_3 == 0) && ((u32) ((arg3 & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r4_2 = 0;
         }
         if (var_r4_2 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x226, base + 0x130, (f32 *) arg3);
         }
         if (arg4 < 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x227, base + 0x168, arg4, 0);
         }
         copyA[0x0] = (*(u8 *)((u8*)(arg0) + (0)));
         copyA[0x1] = (*(u8 *)((u8*)(arg0) + (1)));
         copyA[0x2] = (*(u8 *)((u8*)(arg0) + (2)));
         copyA[0x3] = (*(u8 *)((u8*)(arg0) + (3)));
         copyA[0x4] = (*(u8 *)((u8*)(arg0) + (4)));
         copyA[0x5] = (*(u8 *)((u8*)(arg0) + (5)));
         copyA[0x6] = (*(u8 *)((u8*)(arg0) + (6)));
         copyA[0x7] = (*(u8 *)((u8*)(arg0) + (7)));
         copyA[0x8] = (*(u8 *)((u8*)(arg0) + (8)));
         copyA[0x9] = (*(u8 *)((u8*)(arg0) + (9)));
         copyA[0xA] = (*(u8 *)((u8*)(arg0) + (0xA)));
         copyA[0xB] = (*(u8 *)((u8*)(arg0) + (0xB)));
         copyA[0xC] = (*(u8 *)((u8*)(arg0) + (0xC)));
         copyA[0xD] = (*(u8 *)((u8*)(arg0) + (0xD)));
         copyA[0xE] = (*(u8 *)((u8*)(arg0) + (0xE)));
         copyA[0xF] = (*(u8 *)((u8*)(arg0) + (0xF)));
         copyA[0x10] = (*(u8 *)((u8*)(arg0) + (0x10)));
         copyA[0x11] = (*(u8 *)((u8*)(arg0) + (0x11)));
         copyA[0x12] = (*(u8 *)((u8*)(arg0) + (0x12)));
         copyA[0x13] = (*(u8 *)((u8*)(arg0) + (0x13)));
         copyA[0x14] = (*(u8 *)((u8*)(arg0) + (0x14)));
         copyA[0x15] = (*(u8 *)((u8*)(arg0) + (0x15)));
         copyA[0x16] = (*(u8 *)((u8*)(arg0) + (0x16)));
         copyA[0x17] = (*(u8 *)((u8*)(arg0) + (0x17)));
         copyA[0x18] = (*(u8 *)((u8*)(arg0) + (0x18)));
         copyA[0x19] = (*(u8 *)((u8*)(arg0) + (0x19)));
         copyA[0x1A] = (*(u8 *)((u8*)(arg0) + (0x1A)));
         copyA[0x1B] = (*(u8 *)((u8*)(arg0) + (0x1B)));
         copyA[0x1C] = (*(u8 *)((u8*)(arg0) + (0x1C)));
         copyA[0x1D] = (*(u8 *)((u8*)(arg0) + (0x1D)));
         copyA[0x1E] = (*(u8 *)((u8*)(arg0) + (0x1E)));
         copyA[0x1F] = (*(u8 *)((u8*)(arg0) + (0x1F)));
         (*(s32*)(copyA+0x20)) = (*(s32 *)((u8*)(arg0) + (0x20)));
         s32 copyA_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
         s32 copyA_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
         (*(s32*)(copyA+0x24)) = copyA_24;
         (*(s32*)(copyA+0x28)) = copyA_28;
         s32 copyA_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
         s32 copyA_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
         (*(s32*)(copyA+0x2C)) = copyA_2C;
         (*(s32*)(copyA+0x30)) = copyA_30;
         (*(s32*)(copyA+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
         s32 copyA_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
         s32 copyA_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
         (*(s32*)(copyA+0x38)) = copyA_38;
         (*(s32*)(copyA+0x3C)) = copyA_3C;
         copyA[0x40] = (*(u8 *)((u8*)(arg0) + (0x40)));
         copyA[0x41] = (*(u8 *)((u8*)(arg0) + (0x41)));
         copyA[0x42] = (*(u8 *)((u8*)(arg0) + (0x42)));
         copyA[0x43] = (*(u8 *)((u8*)(arg0) + (0x43)));
         (*(f32*)(copyA+0x44)) = (*(f32 *)((u8*)(arg0) + (0x44)));
         (*(s32*)(copyA+0x48)) = (*(s32 *)((u8*)(arg0) + (0x48)));
         (*(f32*)(copyA+0x4C)) = (*(f32 *)((u8*)(arg0) + (0x4C)));
         (*(f32*)(copyA+0x50)) = (*(f32 *)((u8*)(arg0) + (0x50)));
         (*(s32*)(copyA+0x54)) = (*(s32 *)((u8*)(arg0) + (0x54)));
         (*(s32*)(copyA+0x58)) = (*(s32 *)((u8*)(arg0) + (0x58)));
         (*(s32*)(copyA+0x5C)) = (*(s32 *)((u8*)(arg0) + (0x5C)));
         fn_80113F08((s32)&copyA[0x0], (s32)&rectA[0], arg3, arg4);
         fn_801033F0(&copyA[0x0], 0);
         var_f31 = rectA[0] + rectA[2];
         var_f2 = rectA[1] + rectA[3];
     }
     temp_r0_2 = (*(s32 *)((u8*)(arg0) + (0x58))) & 0x30;
     if (temp_r0_2 == 0x10) {
         *arg1 -= var_f31 * lbl_80561188;
     } else if (temp_r0_2 == 0x20) {
         *arg1 -= var_f31;
     }
     temp_r0_3 = (*(s32 *)((u8*)(arg0) + (0x58))) & 0x300;
     if (temp_r0_3 == 0x100) {
         *arg2 -= var_f2 * lbl_80561188;
     } else if (temp_r0_3 == 0x200) {
         *arg2 -= var_f2;
     }
     temp_r0_4 = (*(s32 *)((u8*)(arg0) + (0x58))) & 3;
     if (temp_r0_4 == 1) {
         temp_r10_3 = (s32) arg0 & 0xFF000000;
         var_r4_3 = 1;
         var_r5_4 = 1;
         var_r6_4 = 1;
         var_r7_4 = 1;
         var_r8_4 = 1;
         var_r9_4 = 1;
         if (((u32) (temp_r10_3 + 0x80000000) >= 1U) && ((u32) (((s32) arg0 & 0xFF800000) + 0x7F000000) >= 1U)) {
             var_r9_4 = 0;
         }
         if ((var_r9_4 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r8_4 = 0;
         }
         if ((var_r8_4 == 0) && ((u32) (temp_r10_3 + 0x40000000) >= 1U)) {
             var_r7_4 = 0;
         }
         if ((var_r7_4 == 0) && ((u32) (((s32) arg0 & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r6_4 = 0;
         }
         if ((var_r6_4 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r5_4 = 0;
         }
         if ((var_r5_4 == 0) && ((u32) (((s32) arg0 & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r4_3 = 0;
         }
         if (var_r4_3 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35D, base + 0x48, arg0);
         }
         temp_r10_4 = arg3 & 0xFF000000;
         var_r4_4 = 1;
         var_r5_5 = 1;
         var_r6_5 = 1;
         var_r7_5 = 1;
         var_r8_5 = 1;
         var_r9_5 = 1;
         if (((u32) (temp_r10_4 + 0x80000000) >= 1U) && ((u32) ((arg3 & 0xFF800000) + 0x7F000000) >= 1U)) {
             var_r9_5 = 0;
         }
         if ((var_r9_5 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r8_5 = 0;
         }
         if ((var_r8_5 == 0) && ((u32) (temp_r10_4 + 0x40000000) >= 1U)) {
             var_r7_5 = 0;
         }
         if ((var_r7_5 == 0) && ((u32) ((arg3 & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r6_5 = 0;
         }
         if ((var_r6_5 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r5_5 = 0;
         }
         if ((var_r5_5 == 0) && ((u32) ((arg3 & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r4_4 = 0;
         }
         if (var_r4_4 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35E, base + 0x130, (f32 *) arg3);
         }
         if (arg4 < 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35F, base + 0x168, arg4, 0);
         }
         rectB[0] = lbl_80561178;
         rectB[1] = lbl_80561178;
         rectB[2] = lbl_80561178;
         rectB[3] = lbl_80561178;
         copyB[0x0] = (*(u8 *)((u8*)(arg0) + (0)));
         copyB[0x1] = (*(u8 *)((u8*)(arg0) + (1)));
         copyB[0x2] = (*(u8 *)((u8*)(arg0) + (2)));
         copyB[0x3] = (*(u8 *)((u8*)(arg0) + (3)));
         copyB[0x4] = (*(u8 *)((u8*)(arg0) + (4)));
         copyB[0x5] = (*(u8 *)((u8*)(arg0) + (5)));
         copyB[0x6] = (*(u8 *)((u8*)(arg0) + (6)));
         copyB[0x7] = (*(u8 *)((u8*)(arg0) + (7)));
         copyB[0x8] = (*(u8 *)((u8*)(arg0) + (8)));
         copyB[0x9] = (*(u8 *)((u8*)(arg0) + (9)));
         copyB[0xA] = (*(u8 *)((u8*)(arg0) + (0xA)));
         copyB[0xB] = (*(u8 *)((u8*)(arg0) + (0xB)));
         copyB[0xC] = (*(u8 *)((u8*)(arg0) + (0xC)));
         copyB[0xD] = (*(u8 *)((u8*)(arg0) + (0xD)));
         copyB[0xE] = (*(u8 *)((u8*)(arg0) + (0xE)));
         copyB[0xF] = (*(u8 *)((u8*)(arg0) + (0xF)));
         copyB[0x10] = (*(u8 *)((u8*)(arg0) + (0x10)));
         copyB[0x11] = (*(u8 *)((u8*)(arg0) + (0x11)));
         copyB[0x12] = (*(u8 *)((u8*)(arg0) + (0x12)));
         copyB[0x13] = (*(u8 *)((u8*)(arg0) + (0x13)));
         copyB[0x14] = (*(u8 *)((u8*)(arg0) + (0x14)));
         copyB[0x15] = (*(u8 *)((u8*)(arg0) + (0x15)));
         copyB[0x16] = (*(u8 *)((u8*)(arg0) + (0x16)));
         copyB[0x17] = (*(u8 *)((u8*)(arg0) + (0x17)));
         copyB[0x18] = (*(u8 *)((u8*)(arg0) + (0x18)));
         copyB[0x19] = (*(u8 *)((u8*)(arg0) + (0x19)));
         copyB[0x1A] = (*(u8 *)((u8*)(arg0) + (0x1A)));
         copyB[0x1B] = (*(u8 *)((u8*)(arg0) + (0x1B)));
         copyB[0x1C] = (*(u8 *)((u8*)(arg0) + (0x1C)));
         copyB[0x1D] = (*(u8 *)((u8*)(arg0) + (0x1D)));
         copyB[0x1E] = (*(u8 *)((u8*)(arg0) + (0x1E)));
         copyB[0x1F] = (*(u8 *)((u8*)(arg0) + (0x1F)));
         (*(s32*)(copyB+0x20)) = (*(s32 *)((u8*)(arg0) + (0x20)));
         s32 copyB_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
         s32 copyB_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
         (*(s32*)(copyB+0x24)) = copyB_24;
         (*(s32*)(copyB+0x28)) = copyB_28;
         s32 copyB_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
         s32 copyB_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
         (*(s32*)(copyB+0x2C)) = copyB_2C;
         (*(s32*)(copyB+0x30)) = copyB_30;
         (*(s32*)(copyB+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
         s32 copyB_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
         s32 copyB_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
         (*(s32*)(copyB+0x38)) = copyB_38;
         (*(s32*)(copyB+0x3C)) = copyB_3C;
         copyB[0x40] = (*(u8 *)((u8*)(arg0) + (0x40)));
         copyB[0x41] = (*(u8 *)((u8*)(arg0) + (0x41)));
         copyB[0x42] = (*(u8 *)((u8*)(arg0) + (0x42)));
         copyB[0x43] = (*(u8 *)((u8*)(arg0) + (0x43)));
         (*(f32*)(copyB+0x44)) = (*(f32 *)((u8*)(arg0) + (0x44)));
         (*(s32*)(copyB+0x48)) = (*(s32 *)((u8*)(arg0) + (0x48)));
         (*(f32*)(copyB+0x4C)) = (*(f32 *)((u8*)(arg0) + (0x4C)));
         (*(f32*)(copyB+0x50)) = (*(f32 *)((u8*)(arg0) + (0x50)));
         (*(s32*)(copyB+0x54)) = (*(s32 *)((u8*)(arg0) + (0x54)));
         (*(s32*)(copyB+0x58)) = (*(s32 *)((u8*)(arg0) + (0x58)));
         (*(s32*)(copyB+0x5C)) = (*(s32 *)((u8*)(arg0) + (0x5C)));
         SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyB[0x0], lbl_80561178, lbl_80561178);
         fn_80112EA0((s32)&copyB[0x0], (s32)&rectB[0], arg3, arg4);
         temp_f2 = rectB[2] - rectB[0];
         fn_801033F0(&copyB[0x0], 0);
         temp_f2 = var_f31 - temp_f2;
         SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *arg1 + (temp_f2 * lbl_80561188));
     } else if (temp_r0_4 == 2) {
         temp_r10_5 = (s32) arg0 & 0xFF000000;
         var_r4_5 = 1;
         var_r5_6 = 1;
         var_r6_6 = 1;
         var_r7_6 = 1;
         var_r8_6 = 1;
         var_r9_6 = 1;
         if (((u32) (temp_r10_5 + 0x80000000) >= 1U) && ((u32) (((s32) arg0 & 0xFF800000) + 0x7F000000) >= 1U)) {
             var_r9_6 = 0;
         }
         if ((var_r9_6 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r8_6 = 0;
         }
         if ((var_r8_6 == 0) && ((u32) (temp_r10_5 + 0x40000000) >= 1U)) {
             var_r7_6 = 0;
         }
         if ((var_r7_6 == 0) && ((u32) (((s32) arg0 & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r6_6 = 0;
         }
         if ((var_r6_6 == 0) && ((u32) (((s32) arg0 & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r5_6 = 0;
         }
         if ((var_r5_6 == 0) && ((u32) (((s32) arg0 & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r4_5 = 0;
         }
         if (var_r4_5 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35D, base + 0x48, arg0);
         }
         temp_r10_6 = arg3 & 0xFF000000;
         var_r4_6 = 1;
         var_r5_7 = 1;
         var_r6_7 = 1;
         var_r7_7 = 1;
         var_r8_7 = 1;
         var_r9_7 = 1;
         if (((u32) (temp_r10_6 + 0x80000000) >= 1U) && ((u32) ((arg3 & 0xFF800000) + 0x7F000000) >= 1U)) {
             var_r9_7 = 0;
         }
         if ((var_r9_7 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x70000000) >= 1U)) {
             var_r8_7 = 0;
         }
         if ((var_r8_7 == 0) && ((u32) (temp_r10_6 + 0x40000000) >= 1U)) {
             var_r7_7 = 0;
         }
         if ((var_r7_7 == 0) && ((u32) ((arg3 & 0xFF800000) + 0x3F000000) >= 1U)) {
             var_r6_7 = 0;
         }
         if ((var_r6_7 == 0) && ((u32) ((arg3 & 0xF8000000) + 0x30000000) >= 1U)) {
             var_r5_7 = 0;
         }
         if ((var_r5_7 == 0) && ((u32) ((arg3 & 0xFFFFC000) + 0x20000000) >= 1U)) {
             var_r4_6 = 0;
         }
         if (var_r4_6 == 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35E, base + 0x130, (f32 *) arg3);
         }
         if (arg4 < 0) {
             Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x35F, base + 0x168, arg4, 0);
         }
         rectC[0] = lbl_80561178;
         rectC[1] = lbl_80561178;
         rectC[2] = lbl_80561178;
         rectC[3] = lbl_80561178;
         copyC[0x0] = (*(u8 *)((u8*)(arg0) + (0)));
         copyC[0x1] = (*(u8 *)((u8*)(arg0) + (1)));
         copyC[0x2] = (*(u8 *)((u8*)(arg0) + (2)));
         copyC[0x3] = (*(u8 *)((u8*)(arg0) + (3)));
         copyC[0x4] = (*(u8 *)((u8*)(arg0) + (4)));
         copyC[0x5] = (*(u8 *)((u8*)(arg0) + (5)));
         copyC[0x6] = (*(u8 *)((u8*)(arg0) + (6)));
         copyC[0x7] = (*(u8 *)((u8*)(arg0) + (7)));
         copyC[0x8] = (*(u8 *)((u8*)(arg0) + (8)));
         copyC[0x9] = (*(u8 *)((u8*)(arg0) + (9)));
         copyC[0xA] = (*(u8 *)((u8*)(arg0) + (0xA)));
         copyC[0xB] = (*(u8 *)((u8*)(arg0) + (0xB)));
         copyC[0xC] = (*(u8 *)((u8*)(arg0) + (0xC)));
         copyC[0xD] = (*(u8 *)((u8*)(arg0) + (0xD)));
         copyC[0xE] = (*(u8 *)((u8*)(arg0) + (0xE)));
         copyC[0xF] = (*(u8 *)((u8*)(arg0) + (0xF)));
         copyC[0x10] = (*(u8 *)((u8*)(arg0) + (0x10)));
         copyC[0x11] = (*(u8 *)((u8*)(arg0) + (0x11)));
         copyC[0x12] = (*(u8 *)((u8*)(arg0) + (0x12)));
         copyC[0x13] = (*(u8 *)((u8*)(arg0) + (0x13)));
         copyC[0x14] = (*(u8 *)((u8*)(arg0) + (0x14)));
         copyC[0x15] = (*(u8 *)((u8*)(arg0) + (0x15)));
         copyC[0x16] = (*(u8 *)((u8*)(arg0) + (0x16)));
         copyC[0x17] = (*(u8 *)((u8*)(arg0) + (0x17)));
         copyC[0x18] = (*(u8 *)((u8*)(arg0) + (0x18)));
         copyC[0x19] = (*(u8 *)((u8*)(arg0) + (0x19)));
         copyC[0x1A] = (*(u8 *)((u8*)(arg0) + (0x1A)));
         copyC[0x1B] = (*(u8 *)((u8*)(arg0) + (0x1B)));
         copyC[0x1C] = (*(u8 *)((u8*)(arg0) + (0x1C)));
         copyC[0x1D] = (*(u8 *)((u8*)(arg0) + (0x1D)));
         copyC[0x1E] = (*(u8 *)((u8*)(arg0) + (0x1E)));
         copyC[0x1F] = (*(u8 *)((u8*)(arg0) + (0x1F)));
         (*(s32*)(copyC+0x20)) = (*(s32 *)((u8*)(arg0) + (0x20)));
         s32 copyC_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
         s32 copyC_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
         (*(s32*)(copyC+0x24)) = copyC_24;
         (*(s32*)(copyC+0x28)) = copyC_28;
         s32 copyC_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
         s32 copyC_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
         (*(s32*)(copyC+0x2C)) = copyC_2C;
         (*(s32*)(copyC+0x30)) = copyC_30;
         (*(s32*)(copyC+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
         s32 copyC_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
         s32 copyC_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
         (*(s32*)(copyC+0x38)) = copyC_38;
         (*(s32*)(copyC+0x3C)) = copyC_3C;
         copyC[0x40] = (*(u8 *)((u8*)(arg0) + (0x40)));
         copyC[0x41] = (*(u8 *)((u8*)(arg0) + (0x41)));
         copyC[0x42] = (*(u8 *)((u8*)(arg0) + (0x42)));
         copyC[0x43] = (*(u8 *)((u8*)(arg0) + (0x43)));
         (*(f32*)(copyC+0x44)) = (*(f32 *)((u8*)(arg0) + (0x44)));
         (*(s32*)(copyC+0x48)) = (*(s32 *)((u8*)(arg0) + (0x48)));
         (*(f32*)(copyC+0x4C)) = (*(f32 *)((u8*)(arg0) + (0x4C)));
         (*(f32*)(copyC+0x50)) = (*(f32 *)((u8*)(arg0) + (0x50)));
         (*(s32*)(copyC+0x54)) = (*(s32 *)((u8*)(arg0) + (0x54)));
         (*(s32*)(copyC+0x58)) = (*(s32 *)((u8*)(arg0) + (0x58)));
         (*(s32*)(copyC+0x5C)) = (*(s32 *)((u8*)(arg0) + (0x5C)));
         SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)&copyC[0x0], lbl_80561178, lbl_80561178);
         fn_80112EA0((s32)&copyC[0x0], (s32)&rectC[0], arg3, arg4);
         temp_f2 = rectC[2] - rectC[0];
         fn_801033F0(&copyC[0x0], 0);
         temp_f2 = var_f31 - temp_f2;
         SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *arg1 + temp_f2);
     } else {
         SetCursorX__Q36nw4hbm2ut10CharWriterFf(arg0, *arg1);
     }
     if ((u32) ((*(s32 *)((u8*)(arg0) + (0x58))) & 0x300) == 0x300) {
         SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, *arg2);
     } else {
         SetCursorX__Q36nw4hbm2ut10CharWriterFf_801062CC(arg0, *arg2 + GetFontWidth__Q36nw4hbm2ut10CharWriterCFv_801058DC(arg0));
     }
     return var_f31;
 }
namespace nw4hbm { namespace ut { struct List { unsigned char data[0xA]; unsigned short stride; }; } }
struct List_Remove_Link { List_Remove_Link *prev; List_Remove_Link *next; };
struct List_Remove_List { void *head; void *tail; u16 count; u16 offset; };
