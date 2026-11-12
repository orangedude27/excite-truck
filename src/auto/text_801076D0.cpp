#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
#include <stdarg.h>
extern "C" const char lbl_80329530[];
extern f32 lbl_80561178, lbl_80561188;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef s32 DWRet;
namespace nw4hbm { namespace ut { class ResFont { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int GetEncoding(); bool SetResource(void*); }; struct List; void List_Remove(List*, void*); void List_Init(List*, unsigned short); void List_Append(List*, void*); void* List_GetNth(const List*, unsigned short); void* List_GetNext(const List*, const void*); struct Font; struct Glyph; struct CharWidths { s8 left; u8 glyphWidth; u8 charWidth; }; class CharWriter { public: void* pad[20]; f32 cursorX; void* pad2[2]; void* font; void* GetFont() const; void SetFont(const Font&); }; namespace detail { class ResFontBase { public: u16 GetTextureFormat() const; s32 GetLineFeed() const; s32 GetDescent() const; s8 GetBaselinePos() const; u8 GetWidth() const; u8 GetCellHeight() const; DWRet GetDefaultCharWidths() const; void GetGlyph(nw4hbm::ut::Glyph*, unsigned short) const; void GetGlyphFromIndex(nw4hbm::ut::Glyph*, unsigned short) const; void SetLineFeed(int); void SetDefaultCharWidths(const CharWidths&); }; } } }

extern "C" const char lbl_80328828[];
extern "C" const char lbl_80328834[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern "C" char *lbl_8055DEB0;
extern "C" int lbl_80559928;
extern "C" int vsnprintf(char *, unsigned int, const char *, va_list);
extern "C" void *alloca(unsigned int);
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

/* nw4hbm::ut: one code range of a font's code-map list (ut_ResFontBase.cpp).
 * A map covers start_code..end_code; FindGlyphIndex turns a code inside that
 * range into a glyph index in one of the three ways named below.  Callers walk
 * the list through `next` (see ResFontBase::GetGlyph / SetAlternateChar). */
namespace nw4hbm { namespace ut {
struct FontCodePair { /* binary-search entry, sorted by code */
    /* 0x00 */ u16 code;
    /* 0x02 */ u16 index;
};
struct FontCodeBinaryMap {
    /* 0x00 */ u16 count;
    /* 0x02 */ FontCodePair pairs[1];
};
struct FontCodeMap {
    /* 0x00 */ u16 start_code;
    /* 0x02 */ u16 end_code;
    /* 0x04 */ u16 map_type; /* FontCodeMapType */
    /* 0x06 */ u16 pad_06;
    /* 0x08 */ const FontCodeMap* next;
    union {
        /* 0x0C */ u16 offset;                    /* OFFSET: start_code's index */
        /* 0x0C */ u16 indices[1];                /* INDEX:  one entry per code */
        /* 0x0C */ FontCodeBinaryMap binary;      /* BINARY: sorted (code, index) pairs */
    } map;
};

/* nw4hbm::ut::FontInformation -- the small header a font resource is parsed
 * into, which ResFontBase::SetResourceBuffer installs as its mFontInfo (the
 * pointer at +0x14) and every ResFontBase accessor validates before use.
 * Only the members the accessors in this file read or write are named; the
 * other offsets are the ones those accessors show. */
struct FontInformation {
    /* 0x00 */ u8 pad_00;
    /* 0x01 */ s8 line_feed;              /* GetLineFeed / SetLineFeed */
    /* 0x02 */ u16 alternate_char;        /* glyph index SetAlternateChar keeps */
    /* 0x04 */ CharWidths default_widths; /* left, glyph width, character width */
    /* 0x07 */ u8 width_07;               /* one of the GetWidth variants */
    /* 0x08 */ const void* glyph_header;  /* cell size +0/+1, baseline +2,
                                           * texture format +0xA, sheet
                                           * columns +0xC and rows +0xE */
    /* 0x0C */ const void* index_map;     /* (first, last] index ranges */
    /* 0x10 */ const void* code_map;      /* the FontCodeMap list */
    /* 0x14 */ u8 width_14;               /* GetWidth; GetDescent = 0x14 - 0x16 */
    /* 0x15 */ u8 width_15;               /* GetWidth */
    /* 0x16 */ u8 width_16;               /* GetWidth */
};
} }

/* FontCodeMap::map_type; at global scope so the switch in FindGlyphIndex can
 * name its cases without qualifying them. */
enum FontCodeMapType {
    FONT_CODE_MAP_TYPE_OFFSET = 0, /* index = offset + (code - start_code) */
    FONT_CODE_MAP_TYPE_INDEX = 1,  /* index = indices[code - start_code] */
    FONT_CODE_MAP_TYPE_BINARY = 2  /* index = binary search of the pairs */
};

#pragma push
#pragma use_lmw_stmw off
extern "C" void* __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void* self, int doFree) {
    extern const char lbl_80328680[];
    const char* file = lbl_80328680;
    if (self != 0) {
        void* head = (char*)self + 4;
        void* node = *(void**)head;
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
    struct LocalSelf { int count; void* first; };
    register void* stop;
    void* head;
    register void* nextNode;
    void* prevNode;
    const char* file;
    void* next;
    void* zero;
    file = lbl_80328680;
    if (*iterator == &((LocalSelf*)self)->first)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x1F, file + 0xD0);
    iterator = (void**)*iterator;
    head = (char*)self + 4;
    zero = 0;
    stop = *(void**)iterator;
    while ((void*)iterator != stop) {
        next = *(void**)iterator;
        if (*(s32*)self == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x60, file + 0x10);
        if (!iterator)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x61, file + 0x34);
        if ((void*)iterator == head)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x62, file + 0x58);
        nextNode = *(void**)iterator;
        prevNode = *(void**)((char*)iterator + 4);
        if (!nextNode)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x65, file + 0x80);
        *(void**)((char*)nextNode + 4) = prevNode;
        if (!prevNode)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x67, file + 0xA8);
        *(void**)prevNode = nextNode;
        --*(s32*)self;
        *(void**)iterator = zero;
        *(void**)((char*)iterator + 4) = zero;
        iterator = (void**)next;
    }
    return stop;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void Clear__Q46nw4hbm2ut6detail12LinkListImplFv(void *self) {
    extern const char lbl_80328680[];
    void *nextNode;
    void *head;
    void *prev;
    void *next;
    const char *file;
    void *node;
    void *list = self;
    file = lbl_80328680;
    node = *(void **)((char *)list + 4);
    head = (char *)list + 4;
    while (node != head) {
        next = *(void **)node;
        if (*(s32 *)list == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x60, file + 0x10);
        if (node == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x61, file + 0x34);
        if (node == head)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x62, file + 0x58);
        prev = *(void **)((char *)node + 4);
        nextNode = *(void **)node;
        if (nextNode == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x65, file + 0x80);
        *(void **)((char *)nextNode + 4) = prev;
        if (!prev)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328680, 0x67, file + 0xA8);
        *(void **)prev = nextNode;
        --*(s32 *)list;
        *(void **)node = 0;
        *(void **)((char *)node + 4) = 0;
        node = next;
    }
}
#pragma use_lmw_stmw off
extern "C" void* Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void* arg0, void** arg1, void* arg2) {
    extern const char lbl_80328680[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    struct FileName { char name[16]; };
    const char* file = lbl_80328680;
    void* node;
    void* prev;
    if (arg2 == 0) Panic__Q26nw4hbm2dbFPCciPCce(((struct FileName*)file)->name, 0x4A, file + 0x34);
    node = *arg1;
    if (node == 0) Panic__Q26nw4hbm2dbFPCciPCce(((struct FileName*)file)->name, 0x4C, file + 0xFC);
    prev = *(void**)((char*)node + 4);
    if (prev == 0) Panic__Q26nw4hbm2dbFPCciPCce(((struct FileName*)file)->name, 0x4F, file + 0x124);
    if (*(void**)arg2 != 0) Panic__Q26nw4hbm2dbFPCciPCce(((struct FileName*)file)->name, 0x51, file + 0x150);
    if (*(void**)((char*)arg2 + 4) != 0) Panic__Q26nw4hbm2dbFPCciPCce(((struct FileName*)file)->name, 0x52, file + 0x17C);
    *(void**)arg2 = node;
    *(void**)((char*)arg2 + 4) = prev;
    *(void**)((char*)node + 4) = arg2;
    *(void**)prev = arg2;
    ++*(int*)arg0;
    return arg2;
}
#pragma use_lmw_stmw reset
extern "C" void* Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(int* arg0, void* arg1) {
    extern const char lbl_80328680[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
    const char* file = (const char*)&lbl_80328680[0];
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
#pragma use_lmw_stmw reset
void nw4hbm::ut::List_Init(nw4hbm::ut::List *list, unsigned short size) {
    if (list == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0x29, lbl_80328834);
    *(unsigned short *)((char *)list + 0xA) = size;
    *(int *)list = 0;
    *(int *)((char *)list + 4) = 0;
    *(unsigned short *)((char *)list + 8) = 0;
}

void nw4hbm::ut::List_Append(nw4hbm::ut::List* list, void* item) {
    const char* file = lbl_80328828;
    if (list == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x59, file + 0xC);
    if (item == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x5A, file + 0x34);
    if (*(void**)list == 0) {
        if (list == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x40, file + 0xC);
        if (item == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x41, file + 0x34);
        u16 stride = *(u16*)((char*)list + 0xA);
        void* node = (char*)item + stride;
        *(void**)((char*)node + 4) = 0;
        *(void**)node = 0;
        u16 count = *(u16*)((char*)list + 8);
        *(void**)list = item;
        *(void**)((char*)list + 4) = item;
        *(u16*)((char*)list + 8) = count + 1;
    } else {
        u16 stride = *(u16*)((char*)list + 0xA);
        void* tail = *(void**)((char*)list + 4);
        void* node = (char*)item + stride;
        *(void**)node = tail;
        *(void**)((char*)node + 4) = 0;
        *(void**)((char*)tail + stride + 4) = item;
        u16 count = *(u16*)((char*)list + 8);
        *(void**)((char*)list + 4) = item;
        *(u16*)((char*)list + 8) = count + 1;
    }
}

void nw4hbm::ut::List_Remove(nw4hbm::ut::List* list, void* item) {
    const char* file = lbl_80328828;
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0xcb, file + 0xc);
    if (item == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0xcc, file + 0x34);
    unsigned short offset = *(unsigned short*)((char*)list + 0xa);
    char* link = (char*)item + offset;
    void* prev = *(void**)link;
    if (prev == 0) *(void**)list = *(void**)(link + 4);
    else *(void**)((char*)prev + offset + 4) = *(void**)(link + 4);
    void* next = *(void**)(link + 4);
    if (next == 0) *(void**)((char*)list + 4) = *(void**)link;
    else *(void**)((char*)next + *(unsigned short*)((char*)list + 0xa)) = *(void**)link;
    *(void**)link = 0;
    *(void**)(link + 4) = 0;
    *(unsigned short*)((char*)list + 8) -= 1;
}

void* nw4hbm::ut::List_GetNext(const nw4hbm::ut::List* list, const void* item) {
    if (list == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328828, 0xF5, lbl_80328834);
    if (item == 0) return *(void**)list;
    return *(void**)((char*)item + *(unsigned short*)((char*)list + 0xA) + 4);
}

extern "C" const char lbl_80328828[];
extern "C" const char lbl_80328834[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
#pragma push
#pragma use_lmw_stmw off
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
#pragma pop
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
    const char* file = lbl_80328888;
    u32 p = (u32)this;
    s32 v5 = 1, v6 = 1, v7 = 1, v8 = 1, v9 = 1, v10 = 1;
    u32 t11 = p & 0xFF000000;
    if ((t11 != 0x80000000U) && ((p & 0xFF800000U) != 0x81000000U)) v10 = 0;
    if ((v10 == 0) && ((p & 0xF8000000U) != 0x90000000U)) v9 = 0;
    if ((v9 == 0) && (t11 != 0xC0000000U)) v8 = 0;
    if ((v8 == 0) && ((p & 0xFF800000U) != 0xC1000000U)) v7 = 0;
    if ((v7 == 0) && ((p & 0xF8000000U) != 0xD0000000U)) v6 = 0;
    if ((v6 == 0) && ((p & 0xFFFFC000U) != 0xE0000000U)) v5 = 0;
    if (v5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x61, file + 0x10, (void*)this);
    u32 q = (u32)resource;
    s32 v4b = 1, v5b = 1, v6b = 1, v7b = 1, v8b = 1, v9b = 1;
    u32 t10 = q & 0xFF000000;
    if ((t10 != 0x80000000U) && ((q & 0xFF800000U) != 0x81000000U)) v9b = 0;
    if ((v9b == 0) && ((q & 0xF8000000U) != 0x90000000U)) v8b = 0;
    if ((v8b == 0) && (t10 != 0xC0000000U)) v7b = 0;
    if ((v7b == 0) && ((q & 0xFF800000U) != 0xC1000000U)) v6b = 0;
    if ((v6b == 0) && ((q & 0xF8000000U) != 0xD0000000U)) v5b = 0;
    if ((v5b == 0) && ((q & 0xFFFFC000U) != 0xE0000000U)) v4b = 0;
    if (v4b == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x62, file + 0x48, (void*)resource);
    if (q & 0x1F) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x63, file + 0x80, (void*)resource);
    s32 existing = *(s32*)((u8*)this + 0x10);
    void* info = 0;
    if (existing != 0) { Warning__Q26nw4hbm2dbFPCciPCce(file + 0, 0x6B, file + 0xCC); return false; }
    if (*(u32*)resource == 0x52464E55) {
        u8* block = (u8*)resource + *(u16*)((u8*)resource + 0xC);
        s32 i = 0;
        while (i < (s32)*(u16*)((u8*)resource + 0xE)) {
            s32 a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
            u32 r = (u32)block; u32 t = r & 0xFF000000;
            if ((t != 0x80000000U) && ((r & 0xFF800000U) != 0x81000000U)) f = 0;
            if ((f == 0) && ((r & 0xF8000000U) != 0x90000000U)) e = 0;
            if ((e == 0) && (t != 0xC0000000U)) d = 0;
            if ((d == 0) && ((r & 0xFF800000U) != 0xC1000000U)) c = 0;
            if ((c == 0) && ((r & 0xF8000000U) != 0xD0000000U)) b = 0;
            if ((b == 0) && ((r & 0xFFFFC000U) != 0xE0000000U)) a = 0;
            if (a == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0, 0x7C, file + 0xEC, (void*)block);
            if (*(u32*)block == 0x46494E46) { info = block + 8; break; }
            ++i; block += *(u32*)(block + 4);
        }
    } else {
        u16 version = *(u16*)((u8*)resource + 6);
        if (version == 0x104) {
            if (IsValidBinaryFile__Q26nw4hbm2utFPCQ36nw4hbm2ut16BinaryFileHeaderUlUsUs(resource, 0x52464E54, 0x104, 2) == 0) { Warning__Q26nw4hbm2dbFPCciPCce(file + 0, 0x96, file + 0x128); return false; }
        } else if (IsValidBinaryFile__Q26nw4hbm2utFPCQ36nw4hbm2ut16BinaryFileHeaderUlUsUs(resource, 0x52464E54, 0x102, 2) == 0) { Warning__Q26nw4hbm2dbFPCciPCce(file + 0, 0xA0, file + 0x128); return false; }
        info = Rebuild__Q36nw4hbm2ut7ResFontFPQ36nw4hbm2ut16BinaryFileHeader(resource);
    }
    if (info == 0) return false;
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

/* nw4hbm::ut::detail::ResFontBase::SetResourceBuffer(void* pUserBuffer,
 * FontInformation* pFontInfo) -- those are the original parameter names, the
 * ones the assertion strings below print.
 *
 * Installs a font's raw resource buffer (mResource) and the FontInformation
 * rebuilt from it (mFontInfo) as the base class's two members.  nw4hbm's debug
 * build first checks that both pointers point into memory the library owns and
 * that neither member is set yet, so a ResFontBase's buffers can only be
 * installed once.
 */
extern "C" void SetResourceBuffer__Q46nw4hbm2ut6detail11ResFontBaseFPvPQ36nw4hbm2ut15FontInformation(void* self, void* resource, void* info) {
    /* ResFontBase's two pointers, which the assertions below name; the 0x10
     * bytes in front of them are the class's own bookkeeping. */
    struct ResFontBaseMembers { void* unused[4]; void* mResource; void* mFontInfo; };
    /* lbl_80329140 is this file's debug blob: +0xC is "ut_ResFontBase.cpp",
     * and +0x20, +0x5C, +0x98 and +0xC4 the nw4hbm::db messages quoted here. */
    const char* file=lbl_80329140;

    /* nw4hbm::db's valid-pointer check, unrolled by the compiler: each flag
     * stays 1 while the address was found in one of the ranges tested so far,
     * and the last one decides whether to panic.  The ranges are MEM1
     * (0x80000000, with the 8 MiB expanded at 0x81000000), MEM2 (0x90000000),
     * their uncached mirrors (0xC0000000, 0xC1000000, 0xD0000000) and the
     * 16 KiB block at 0xE0000000.  The flags keep their one-letter names: the
     * allocator binds them to r10..r5 in that order, and naming them after
     * their range flips the binding and breaks the match. */
    u32 resourceAddr=(u32)resource;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    u32 t=resourceAddr&0xFF000000U;
    if(t!=0x80000000U&&(resourceAddr&0xFF800000U)!=0x81000000U)f=0;
    if(f==0&&(resourceAddr&0xF8000000U)!=0x90000000U)e=0;
    if(e==0&&t!=0xC0000000U)d=0;
    if(d==0&&(resourceAddr&0xFF800000U)!=0xC1000000U)c=0;
    if(c==0&&(resourceAddr&0xF8000000U)!=0xD0000000U)b=0;
    if(b==0&&(resourceAddr&0xFFFFC000U)!=0xE0000000U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x4F,file+0x20,resource);

    /* The same check over the FontInformation the caller rebuilt. */
    u32 v=(u32)info;
    int g=1,h=1,i=1,j=1,k=1,l=1;
    u32 t2=v&0xFF000000U;
    if(t2!=0x80000000U&&(v&0xFF800000U)!=0x81000000U)l=0;
    if(l==0&&(v&0xF8000000U)!=0x90000000U)k=0;
    if(k==0&&t2!=0xC0000000U)j=0;
    if(j==0&&(v&0xFF800000U)!=0xC1000000U)i=0;
    if(i==0&&(v&0xF8000000U)!=0xD0000000U)h=0;
    if(h==0&&(v&0xFFFFC000U)!=0xE0000000U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x50,file+0x5C,info);

    /* "NW4HBM:Failed assertion mResource == NULL" and "mFontInfo == NULL". */
    if(((ResFontBaseMembers*)self)->mResource!=0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x51,file+0x98);
    if(((ResFontBaseMembers*)self)->mFontInfo!=0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x52,file+0xC4);
    ((ResFontBaseMembers*)self)->mResource=resource;
    ((ResFontBaseMembers*)self)->mFontInfo=info;
}

// Validates this and font info pointer; returns width byte from font data.
u8 nw4hbm::ut::detail::ResFontBase::GetWidth() const {
    const char* file=lbl_80329140;
    u32 value=(u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    u32 t=value&0xFF000000U;
    if (t!=0x80000000U && (value&0xFF800000U)!=0x81000000U) f=0;
    if (f==0 && (value&0xF8000000U)!=0x90000000U)e=0;
    if (e==0 && t!=0xC0000000U)d=0;
    if (d==0 && (value&0xFF800000U)!=0xC1000000U)c=0;
    if (c==0 && (value&0xF8000000U)!=0xD0000000U)b=0;
    if (b==0 && (value&0xFFFFC000U)!=0xE0000000U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x80,file+0xF0,this);
    int g=1,h=1;
    u32 v=*(u32*)((char*)this+0x14);
    int i=1,j=1,k=1,l=1;
    u32 t2=v&0xFF000000U;
    if(t2!=0x80000000U&&(v&0xFF800000U)!=0x81000000U)l=0;
    if(l==0&&(v&0xF8000000U)!=0x90000000U)k=0;
    if(k==0&&t2!=0xC0000000U)j=0;
    if(j==0&&(v&0xFF800000U)!=0xC1000000U)i=0;
    if(i==0&&(v&0xF8000000U)!=0xD0000000U)h=0;
    if(h==0&&(v&0xFFFFC000U)!=0xE0000000U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x81,file+0x128);
    return *(u8*)(*(u32*)((char*)this+0x14)+0x15);
}

// Returns the font width value from this resource font's referenced data.
// Also validates that this and its referenced data pointers are in valid address ranges.
extern "C" u8 GetWidth__Q46nw4hbm2ut6detail11ResFontBaseCFv_801094E8(void* self) {
    const char* fileName = lbl_80329140;
    u32 address = (u32)self;
    int validA = 1, validB = 1, validC = 1, validD = 1, validE = 1, validF = 1;
    u32 highByte = address & 0xFF000000U;
    if (highByte != 0x80000000U && (address & 0xFF800000U) != 0x81000000U) validF = 0;
    if (validF == 0 && (address & 0xF8000000U) != 0x90000000U) validE = 0;
    if (validE == 0 && highByte != 0xC0000000U) validD = 0;
    if (validD == 0 && (address & 0xFF800000U) != 0xC1000000U) validC = 0;
    if (validC == 0 && (address & 0xF8000000U) != 0xD0000000U) validB = 0;
    if (validB == 0 && (address & 0xFFFFC000U) != 0xE0000000U) validA = 0;
    if (validA == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0xC, 0x91, fileName + 0xF0, self);
    int refValidA = 1, refValidB = 1;
    u32 refAddress = *(u32*)((char*)self + 0x14);
    int refValidC = 1, refValidD = 1, refValidE = 1, refValidF = 1;
    u32 refHighByte = refAddress & 0xFF000000U;
    if (refHighByte != 0x80000000U && (refAddress & 0xFF800000U) != 0x81000000U) refValidF = 0;
    if (refValidF == 0 && (refAddress & 0xF8000000U) != 0x90000000U) refValidE = 0;
    if (refValidE == 0 && refHighByte != 0xC0000000U) refValidD = 0;
    if (refValidD == 0 && (refAddress & 0xFF800000U) != 0xC1000000U) refValidC = 0;
    if (refValidC == 0 && (refAddress & 0xF8000000U) != 0xD0000000U) refValidB = 0;
    if (refValidB == 0 && (refAddress & 0xFFFFC000U) != 0xE0000000U) refValidA = 0;
    if (refValidA == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0xC, 0x92, fileName + 0x128);
    return *(u8*)(*(u32*)((char*)self + 0x14) + 0x14);
}

extern "C" u8 GetWidth__Q46nw4hbm2ut6detail11ResFontBaseCFv_801096F0(void* self) {
    // Returns the glyph width from the resource font data, asserting this and its data pointers are valid.
    const char* file = lbl_80329140;
    u32 ptr = (u32)self;
    int valid0 = 1, valid1 = 1, valid2 = 1, valid3 = 1, valid4 = 1, valid5 = 1;
    u32 region = ptr & 0xFF000000U;
    if (region != 0x80000000U && (ptr & 0xFF800000U) != 0x81000000U) valid5 = 0;
    if (valid5 == 0 && (ptr & 0xF8000000U) != 0x90000000U) valid4 = 0;
    if (valid4 == 0 && region != 0xC0000000U) valid3 = 0;
    if (valid3 == 0 && (ptr & 0xFF800000U) != 0xC1000000U) valid2 = 0;
    if (valid2 == 0 && (ptr & 0xF8000000U) != 0xD0000000U) valid1 = 0;
    if (valid1 == 0 && (ptr & 0xFFFFC000U) != 0xE0000000U) valid0 = 0;
    if (valid0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0xA2, file + 0xF0, self);
    int dataValid0 = 1, dataValid1 = 1;
    u32 dataPtr = *(u32*)((char*)self + 0x14);
    int dataValid2 = 1, dataValid3 = 1, dataValid4 = 1, dataValid5 = 1;
    u32 dataRegion = dataPtr & 0xFF000000U;
    if (dataRegion != 0x80000000U && (dataPtr & 0xFF800000U) != 0x81000000U) dataValid5 = 0;
    if (dataValid5 == 0 && (dataPtr & 0xF8000000U) != 0x90000000U) dataValid4 = 0;
    if (dataValid4 == 0 && dataRegion != 0xC0000000U) dataValid3 = 0;
    if (dataValid3 == 0 && (dataPtr & 0xFF800000U) != 0xC1000000U) dataValid2 = 0;
    if (dataValid2 == 0 && (dataPtr & 0xF8000000U) != 0xD0000000U) dataValid1 = 0;
    if (dataValid1 == 0 && (dataPtr & 0xFFFFC000U) != 0xE0000000U) dataValid0 = 0;
    if (dataValid0 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0xA3, file + 0x128);
    return *(u8*)(*(u32*)((char*)self + 0x14) + 0x16);
}

s32 nw4hbm::ut::detail::ResFontBase::GetDescent() const {
    /* Return font descent from the referenced font data after validating the
       this pointer and the data pointer against expected MEM1/MEM2 address ranges. */
    const char *file = lbl_80329140;
    u32 thisValue = (u32)this;
    int validAll = 1, validD = 1, validC = 1, validB = 1, validA = 1, validMem1 = 1;
    u32 top = thisValue & 0xFF000000U;
    if (top != 0x80000000U && (thisValue & 0xFF800000U) != 0x81000000U) validMem1 = 0;
    if (validMem1 == 0 && (thisValue & 0xF8000000U) != 0x90000000U) validA = 0;
    if (validA == 0 && top != 0xC0000000U) validB = 0;
    if (validB == 0 && (thisValue & 0xFF800000U) != 0xC1000000U) validC = 0;
    if (validC == 0 && (thisValue & 0xF8000000U) != 0xD0000000U) validD = 0;
    if (validD == 0 && (thisValue & 0xFFFFC000U) != 0xE0000000U) validAll = 0;
    if (validAll == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0xB3, file + 0xF0, this);
    int dataValidAll = 1, dataValidD = 1;
    u32 dataPtrValue = *(u32*)((char*)this + 0x14);
    int dataValidC = 1, dataValidB = 1, dataValidA = 1, dataValidMem1 = 1;
    u32 dataTop = dataPtrValue & 0xFF000000U;
    if (dataTop != 0x80000000U && (dataPtrValue & 0xFF800000U) != 0x81000000U) dataValidMem1 = 0;
    if (dataValidMem1 == 0 && (dataPtrValue & 0xF8000000U) != 0x90000000U) dataValidA = 0;
    if (dataValidA == 0 && dataTop != 0xC0000000U) dataValidB = 0;
    if (dataValidB == 0 && (dataPtrValue & 0xFF800000U) != 0xC1000000U) dataValidC = 0;
    if (dataValidC == 0 && (dataPtrValue & 0xF8000000U) != 0xD0000000U) dataValidD = 0;
    if (dataValidD == 0 && (dataPtrValue & 0xFFFFC000U) != 0xE0000000U) dataValidAll = 0;
    if (dataValidAll == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0xB4, file + 0x128);
    u8 *data = *(u8**)((char*)this + 0x14);
    return data[0x14] - data[0x16];
}

extern "C" s32 GetBaselinePos__Q46nw4hbm2ut6detail11ResFontBaseCFv(void *self) {
    /* Return the font baseline position from the referenced font data after
       validating the this pointer and the data pointer against expected MEM1/MEM2 ranges. */
    const char *file = lbl_80329140;
    u32 thisValue = (u32)self;
    int validAll = 1, validD = 1, validC = 1, validB = 1, validA = 1, validMem1 = 1;
    u32 top = thisValue & 0xFF000000U;
    if (top != 0x80000000U && (thisValue & 0xFF800000U) != 0x81000000U) validMem1 = 0;
    if (validMem1 == 0 && (thisValue & 0xF8000000U) != 0x90000000U) validA = 0;
    if (validA == 0 && top != 0xC0000000U) validB = 0;
    if (validB == 0 && (thisValue & 0xFF800000U) != 0xC1000000U) validC = 0;
    if (validC == 0 && (thisValue & 0xF8000000U) != 0xD0000000U) validD = 0;
    if (validD == 0 && (thisValue & 0xFFFFC000U) != 0xE0000000U) validAll = 0;
    if (validAll == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0xC4, file + 0xF0, self);
    int dataValidAll = 1, dataValidD = 1;
    u32 dataPtrValue = *(u32*)((char*)self + 0x14);
    int dataValidC = 1, dataValidB = 1, dataValidA = 1, dataValidMem1 = 1;
    u32 dataTop = dataPtrValue & 0xFF000000U;
    if (dataTop != 0x80000000U && (dataPtrValue & 0xFF800000U) != 0x81000000U) dataValidMem1 = 0;
    if (dataValidMem1 == 0 && (dataPtrValue & 0xF8000000U) != 0x90000000U) dataValidA = 0;
    if (dataValidA == 0 && dataTop != 0xC0000000U) dataValidB = 0;
    if (dataValidB == 0 && (dataPtrValue & 0xFF800000U) != 0xC1000000U) dataValidC = 0;
    if (dataValidC == 0 && (dataPtrValue & 0xF8000000U) != 0xD0000000U) dataValidD = 0;
    if (dataValidD == 0 && (dataPtrValue & 0xFFFFC000U) != 0xE0000000U) dataValidAll = 0;
    if (dataValidAll == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0xC5, file + 0x128);
    return *(s8*)(*(u32*)(*(u32*)((char*)self + 0x14) + 8) + 2);
}

/* Returns the font resource's cell height after validating this and its resource pointer. */
u8 nw4hbm::ut::detail::ResFontBase::GetCellHeight() const {
    const char* file=lbl_80329140;
    u32 value=(u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    u32 t=value&0xFF000000U;
    if (t!=0x80000000U && (value&0xFF800000U)!=0x81000000U) f=0;
    if (f==0 && (value&0xF8000000U)!=0x90000000U)e=0;
    if (e==0 && t!=0xC0000000U)d=0;
    if (d==0 && (value&0xFF800000U)!=0xC1000000U)c=0;
    if (c==0 && (value&0xF8000000U)!=0xD0000000U)b=0;
    if (b==0 && (value&0xFFFFC000U)!=0xE0000000U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xD5,file+0xF0,this);
    int g=1,h=1;
    u32 v=*(u32*)((char*)this+0x14);
    int i=1,j=1,k=1,l=1;
    u32 t2=v&0xFF000000U;
    if(t2!=0x80000000U&&(v&0xFF800000U)!=0x81000000U)l=0;
    if(l==0&&(v&0xF8000000U)!=0x90000000U)k=0;
    if(k==0&&t2!=0xC0000000U)j=0;
    if(j==0&&(v&0xFF800000U)!=0xC1000000U)i=0;
    if(i==0&&(v&0xF8000000U)!=0xD0000000U)h=0;
    if(h==0&&(v&0xFFFFC000U)!=0xE0000000U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xD6,file+0x128);
    return *(u8*)(*(u32*)(*(u32*)((char*)this+0x14)+8)+1);
}

// Returns the cell height from this resource font's texture data.
// Also validates that this and its referenced data pointers are in valid address ranges.
extern "C" u8 GetCellHeight__Q46nw4hbm2ut6detail11ResFontBaseCFv_80109F24(void* self) {
    const char* fileName = lbl_80329140;
    u32 address = (u32)self;
    int validA = 1, validB = 1, validC = 1, validD = 1, validE = 1, validF = 1;
    u32 highByte = address & 0xFF000000U;
    if (highByte != 0x80000000U && (address & 0xFF800000U) != 0x81000000U) validF = 0;
    if (validF == 0 && (address & 0xF8000000U) != 0x90000000U) validE = 0;
    if (validE == 0 && highByte != 0xC0000000U) validD = 0;
    if (validD == 0 && (address & 0xFF800000U) != 0xC1000000U) validC = 0;
    if (validC == 0 && (address & 0xF8000000U) != 0xD0000000U) validB = 0;
    if (validB == 0 && (address & 0xFFFFC000U) != 0xE0000000U) validA = 0;
    if (validA == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0xC, 0xE6, fileName + 0xF0, self);
    int refValidA = 1, refValidB = 1;
    u32 refAddress = *(u32*)((char*)self + 0x14);
    int refValidC = 1, refValidD = 1, refValidE = 1, refValidF = 1;
    u32 refHighByte = refAddress & 0xFF000000U;
    if (refHighByte != 0x80000000U && (refAddress & 0xFF800000U) != 0x81000000U) refValidF = 0;
    if (refValidF == 0 && (refAddress & 0xF8000000U) != 0x90000000U) refValidE = 0;
    if (refValidE == 0 && refHighByte != 0xC0000000U) refValidD = 0;
    if (refValidD == 0 && (refAddress & 0xFF800000U) != 0xC1000000U) refValidC = 0;
    if (refValidC == 0 && (refAddress & 0xF8000000U) != 0xD0000000U) refValidB = 0;
    if (refValidB == 0 && (refAddress & 0xFFFFC000U) != 0xE0000000U) refValidA = 0;
    if (refValidA == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0xC, 0xE7, fileName + 0x128);
    return *(u8*)(*(u32*)(*(u32*)((char*)self + 0x14) + 8));
}

/* Returns a font resource height byte at +3 after validating this and its resource pointer. */
extern "C" u8 GetCellHeight__Q46nw4hbm2ut6detail11ResFontBaseCFv_8010A130(void* self) {
    const char* file=lbl_80329140;
    u32 value=(u32)self;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    u32 t=value&0xFF000000U;
    if (t!=0x80000000U && (value&0xFF800000U)!=0x81000000U) f=0;
    if (f==0 && (value&0xF8000000U)!=0x90000000U)e=0;
    if (e==0 && t!=0xC0000000U)d=0;
    if (d==0 && (value&0xFF800000U)!=0xC1000000U)c=0;
    if (c==0 && (value&0xF8000000U)!=0xD0000000U)b=0;
    if (b==0 && (value&0xFFFFC000U)!=0xE0000000U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xF7,file+0xF0,self);
    int g=1,h=1;
    u32 v=*(u32*)((char*)self+0x14);
    int i=1,j=1,k=1,l=1;
    u32 t2=v&0xFF000000U;
    if(t2!=0x80000000U&&(v&0xFF800000U)!=0x81000000U)l=0;
    if(l==0&&(v&0xF8000000U)!=0x90000000U)k=0;
    if(k==0&&t2!=0xC0000000U)j=0;
    if(j==0&&(v&0xFF800000U)!=0xC1000000U)i=0;
    if(i==0&&(v&0xF8000000U)!=0xD0000000U)h=0;
    if(h==0&&(v&0xFFFFC000U)!=0xE0000000U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0xF8,file+0x128);
    return *(u8*)(*(u32*)(*(u32*)((char*)self+0x14)+8)+3);
}

extern "C" u8 fn_8010A33C(void) {
    return 2;
}

// Returns the texture format from this resource font's texture data.
// Also validates that this and its referenced data pointers are in valid address ranges.
u16 nw4hbm::ut::detail::ResFontBase::GetTextureFormat() const {
    const char* fileName = lbl_80329140;
    u32 address = (u32)this;
    int validA = 1, validB = 1, validC = 1, validD = 1, validE = 1, validF = 1;
    u32 highByte = address & 0xFF000000U;
    if (highByte != 0x80000000U && (address & 0xFF800000U) != 0x81000000U) validF = 0;
    if (validF == 0 && (address & 0xF8000000U) != 0x90000000U) validE = 0;
    if (validE == 0 && highByte != 0xC0000000U) validD = 0;
    if (validD == 0 && (address & 0xFF800000U) != 0xC1000000U) validC = 0;
    if (validC == 0 && (address & 0xF8000000U) != 0xD0000000U) validB = 0;
    if (validB == 0 && (address & 0xFFFFC000U) != 0xE0000000U) validA = 0;
    if (validA == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0xC, 0x117, fileName + 0xF0, this);
    int refValidA = 1, refValidB = 1;
    u32 refAddress = *(u32*)((char*)this + 0x14);
    int refValidC = 1, refValidD = 1, refValidE = 1, refValidF = 1;
    u32 refHighByte = refAddress & 0xFF000000U;
    if (refHighByte != 0x80000000U && (refAddress & 0xFF800000U) != 0x81000000U) refValidF = 0;
    if (refValidF == 0 && (refAddress & 0xF8000000U) != 0x90000000U) refValidE = 0;
    if (refValidE == 0 && refHighByte != 0xC0000000U) refValidD = 0;
    if (refValidD == 0 && (refAddress & 0xFF800000U) != 0xC1000000U) refValidC = 0;
    if (refValidC == 0 && (refAddress & 0xF8000000U) != 0xD0000000U) refValidB = 0;
    if (refValidB == 0 && (refAddress & 0xFFFFC000U) != 0xE0000000U) refValidA = 0;
    if (refValidA == 0) Panic__Q26nw4hbm2dbFPCciPCce(fileName + 0xC, 0x118, fileName + 0x128);
    return *(u16*)(*(u32*)(*(u32*)((char*)this + 0x14) + 8) + 0xA);
}

/* nw4hbm::ut::detail::ResFontBase::GetLineFeed() -- the font's line feed
 * (leading), kept as the signed byte at mFontInfo + 1.  nw4hbm's debug build
 * first checks that `this` and then mFontInfo point into memory the library
 * accepts, so a ResFontBase whose resource was never installed panics here. */
s32 nw4hbm::ut::detail::ResFontBase::GetLineFeed() const {
    const char *file = lbl_80329140;
    u32 selfAddr = (u32)this;
    /* nw4hbm::db's valid-pointer check, unrolled by the compiler: a flag stays
     * 1 while the address has not matched any range checked so far (MEM1
     * 0x80000000 and the 8 MiB expanded at 0x81000000, MEM2 0x90000000, their
     * uncached mirrors 0xC0000000, 0xC1000000 and 0xD0000000, and the 16 KiB
     * block at 0xE0000000), and `valid` is the verdict.  The flags are declared
     * innermost check last, which is what binds them to r5..r10 in that order;
     * see SetLineFeed, which asserts the same three things. */
    int valid = 1, matched_d0 = 1, matched_c1 = 1, matched_c0 = 1, matched_mem2 = 1, matched_mem1 = 1;
    u32 selfTop = selfAddr & 0xFF000000U;
    if (selfTop != 0x80000000U && (selfAddr & 0xFF800000U) != 0x81000000U) matched_mem1 = 0;
    if (matched_mem1 == 0 && (selfAddr & 0xF8000000U) != 0x90000000U) matched_mem2 = 0;
    if (matched_mem2 == 0 && selfTop != 0xC0000000U) matched_c0 = 0;
    if (matched_c0 == 0 && (selfAddr & 0xFF800000U) != 0xC1000000U) matched_c1 = 0;
    if (matched_c1 == 0 && (selfAddr & 0xF8000000U) != 0xD0000000U) matched_d0 = 0;
    if (matched_d0 == 0 && (selfAddr & 0xFFFFC000U) != 0xE0000000U) valid = 0;
    /* "this(=%p) is not valid pointer." */
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x128, file + 0xF0, this);
    /* the same check over mFontInfo; it needs two flags fewer (r4 and r5) and
     * its message names the field but not an address. */
    int info_valid = 1, info_matched_d0 = 1;
    u32 fontInfoPtr = *(u32*)((char*)this + 0x14);
    int info_matched_c1 = 1, info_matched_c0 = 1, info_matched_mem2 = 1, info_matched_mem1 = 1;
    u32 fontInfoTop = fontInfoPtr & 0xFF000000U;
    if (fontInfoTop != 0x80000000U && (fontInfoPtr & 0xFF800000U) != 0x81000000U) info_matched_mem1 = 0;
    if (info_matched_mem1 == 0 && (fontInfoPtr & 0xF8000000U) != 0x90000000U) info_matched_mem2 = 0;
    if (info_matched_mem2 == 0 && fontInfoTop != 0xC0000000U) info_matched_c0 = 0;
    if (info_matched_c0 == 0 && (fontInfoPtr & 0xFF800000U) != 0xC1000000U) info_matched_c1 = 0;
    if (info_matched_c1 == 0 && (fontInfoPtr & 0xF8000000U) != 0xD0000000U) info_matched_d0 = 0;
    if (info_matched_d0 == 0 && (fontInfoPtr & 0xFFFFC000U) != 0xE0000000U) info_valid = 0;
    if (info_valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x129, file + 0x128);
    /* mFontInfo is read out again for the load itself, and the byte reaches the
     * caller sign-extended into r3. */
    return ((const FontInformation *)*(u32 *)((char *)this + 0x14))->line_feed;
}

s32 nw4hbm::ut::detail::ResFontBase::GetDefaultCharWidths() const {
    const char* file=lbl_80329140;
    u32 value=(u32)this;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    u32 t=value&0xFF000000U;
    if (t!=0x80000000U && (value&0xFF800000U)!=0x81000000U) f=0;
    if (f==0 && (value&0xF8000000U)!=0x90000000U)e=0;
    if (e==0 && t!=0xC0000000U)d=0;
    if (d==0 && (value&0xFF800000U)!=0xC1000000U)c=0;
    if (c==0 && (value&0xF8000000U)!=0xD0000000U)b=0;
    if (b==0 && (value&0xFFFFC000U)!=0xE0000000U)a=0;
    if(a==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x139,file+0xF0,this);
    int g=1,h=1;
    u32 v=*(u32*)((char*)this+0x14);
    int i=1,j=1,k=1,l=1;
    u32 t2=v&0xFF000000U;
    if(t2!=0x80000000U&&(v&0xFF800000U)!=0x81000000U)l=0;
    if(l==0&&(v&0xF8000000U)!=0x90000000U)k=0;
    if(k==0&&t2!=0xC0000000U)j=0;
    if(j==0&&(v&0xFF800000U)!=0xC1000000U)i=0;
    if(i==0&&(v&0xF8000000U)!=0xD0000000U)h=0;
    if(h==0&&(v&0xFFFFC000U)!=0xE0000000U)g=0;
    if(g==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x13A,file+0x128);
    u8* p=(u8*)*(u32*)((char*)this+0x14);
    return (((u32)*(u16*)(p+4)<<8)|p[6])<<8;
}

/*
 * nw4hbm::ut::detail::ResFontBase::SetDefaultCharWidths (ut_ResFontBase.cpp).
 * Checks its three pointers the way nw4hbm::db does, then copies the caller's
 * CharWidths over the font information's default character widths
 * (mFontInfo (@0x14) -> +4 left, +5 glyph width, +6 character width), which is
 * what GetDefaultCharWidths() reads back.
 * The file string is lbl_80329140: +0xC "ut_ResFontBase.cpp", +0xF0
 * "this(=%p) is not valid pointer.", +0x128 "mFontInfo(=%p) ...", +0x164
 * "& widths(=%p) ..."; a pointer is valid only inside one of the Wii's mapped
 * areas (0x80000000, 0x81000000, 0x90000000, 0xC0000000, 0xC1000000,
 * 0xD0000000 or 0xE0000000).
 */
void nw4hbm::ut::detail::ResFontBase::SetDefaultCharWidths(const CharWidths& widths) {
    const char* file = lbl_80329140;
    register int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
    register u32 selfAddr = (u32)this;
    register u32 selfTop = selfAddr & 0xFF000000U;
    if (selfTop != 0x80000000U && (selfAddr & 0xFF800000U) != 0x81000000U) r10 = 0;
    if (r10 == 0 && (selfAddr & 0xF8000000U) != 0x90000000U) r9 = 0;
    if (r9 == 0 && selfTop != 0xC0000000U) r8 = 0;
    if (r8 == 0 && (selfAddr & 0xFF800000U) != 0xC1000000U) r7 = 0;
    if (r7 == 0 && (selfAddr & 0xF8000000U) != 0xD0000000U) r6 = 0;
    if (r6 == 0 && (selfAddr & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
    if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x14A, file + 0xF0, this);

    {
        /* nw4hbm asserts mFontInfo (@0x14) is a valid pointer (line 0x14B) */
        register int v4 = 1, v5 = 1;
        register u32 fontInfoPtr = *(u32*)((char*)this + 0x14);
        register int v7 = 1, v8 = 1, v9 = 1, v10 = 1;
        register u32 fontInfoTop = fontInfoPtr & 0xFF000000U;
        if (fontInfoTop != 0x80000000U && (fontInfoPtr & 0xFF800000U) != 0x81000000U) v10 = 0;
        if (v10 == 0 && (fontInfoPtr & 0xF8000000U) != 0x90000000U) v9 = 0;
        if (v9 == 0 && fontInfoTop != 0xC0000000U) v8 = 0;
        if (v8 == 0 && (fontInfoPtr & 0xFF800000U) != 0xC1000000U) v7 = 0;
        if (v7 == 0 && (fontInfoPtr & 0xF8000000U) != 0xD0000000U) v5 = 0;
        if (v5 == 0 && (fontInfoPtr & 0xFFFFC000U) != 0xE0000000U) v4 = 0;
        if (v4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x14B, file + 0x128);
    }

    {
        /* ... and that the caller's CharWidths really lives somewhere (0x14C) */
        register int w4 = 1, w5 = 1, w6 = 1, w7 = 1, w8 = 1, w9 = 1;
        register u32 widthsAddr = (u32)&widths;
        register u32 widthsTop = widthsAddr & 0xFF000000U;
        if (widthsTop != 0x80000000U && (widthsAddr & 0xFF800000U) != 0x81000000U) w9 = 0;
        if (w9 == 0 && (widthsAddr & 0xF8000000U) != 0x90000000U) w8 = 0;
        if (w8 == 0 && widthsTop != 0xC0000000U) w7 = 0;
        if (w7 == 0 && (widthsAddr & 0xFF800000U) != 0xC1000000U) w6 = 0;
        if (w6 == 0 && (widthsAddr & 0xF8000000U) != 0xD0000000U) w5 = 0;
        if (w5 == 0 && (widthsAddr & 0xFFFFC000U) != 0xE0000000U) w4 = 0;
        if (w4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x14C, file + 0x164, &widths);
    }

    u8* fontInfo = *(u8**)((char*)this + 0x14);
    fontInfo[4] = widths.left;
    fontInfo[5] = widths.glyphWidth;
    fontInfo[6] = widths.charWidth;
}

extern "C" u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void *, void *, u16);
#pragma push
#pragma use_lmw_stmw off
/*
 * ResFontBase::SetAlternateChar - if `code` falls inside one of the font's
 * code maps, resolve its glyph index, store it as the alternate character and
 * return true; otherwise leave the font unchanged and return false.
 */
extern "C" s32 SetAlternateChar__Q46nw4hbm2ut6detail11ResFontBaseFUs(nw4hbm::ut::detail::ResFontBase* self, u16 code) {
    const char* file = lbl_80329140;
    register u32 top = (u32)self & 0xFF000000U;
    {
        register int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
        if (top != 0x80000000U && ((u32)self & 0xFF800000U) != 0x81000000U) r10 = 0;
        if (r10 == 0 && ((u32)self & 0xF8000000U) != 0x90000000U) r9 = 0;
        if (r9 == 0 && top != 0xC0000000U) r8 = 0;
        if (r8 == 0 && ((u32)self & 0xFF800000U) != 0xC1000000U) r7 = 0;
        if (r7 == 0 && ((u32)self & 0xF8000000U) != 0xD0000000U) r6 = 0;
        if (r6 == 0 && ((u32)self & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
        if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x15E, file + 0xF0, self);
    }
    {
        register int r4 = 1, r5 = 1;
        u8* fontInfo = *(u8**)((char*)self + 0x14);
        register int r7 = 1;
        register int r8 = 1, r9 = 1, r10 = 1;
        register u32 fontInfoTag = (u32)fontInfo & 0xFF000000U;
        if (fontInfoTag != 0x80000000U && ((u32)fontInfo & 0xFF800000U) != 0x81000000U) r10 = 0;
        if (r10 == 0 && ((u32)fontInfo & 0xF8000000U) != 0x90000000U) r9 = 0;
        if (r9 == 0 && fontInfoTag != 0xC0000000U) r8 = 0;
        if (r8 == 0 && ((u32)fontInfo & 0xFF800000U) != 0xC1000000U) r7 = 0;
        if (r7 == 0 && ((u32)fontInfo & 0xF8000000U) != 0xD0000000U) r5 = 0;
        if (r5 == 0 && ((u32)fontInfo & 0xFFFFC000U) != 0xE0000000U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x15F, file + 0x128);
    }
    {
        register u32 b, a;
        register int valid = 0;
        if (top == 0x80000000U ||
            (a = (u32)self & 0xFF800000U) == 0x81000000U ||
            (b = (u32)self & 0xF8000000U) == 0x90000000U ||
            top == 0xC0000000U ||
            a == 0xC1000000U ||
            b == 0xD0000000U ||
            ((u32)self & 0xFFFFC000U) == 0xE0000000U)
            valid = 1;
        if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F6, file + 0xF0, self);
    }
    {
        register int r4 = 1, r5 = 1;
        u8* fontInfo = *(u8**)((char*)self + 0x14);
        register int r7 = 1;
        register int r8 = 1, r9 = 1, r10 = 1;
        register u32 fontInfoTag = (u32)fontInfo & 0xFF000000U;
        if (fontInfoTag != 0x80000000U && ((u32)fontInfo & 0xFF800000U) != 0x81000000U) r10 = 0;
        if (r10 == 0 && ((u32)fontInfo & 0xF8000000U) != 0x90000000U) r9 = 0;
        if (r9 == 0 && fontInfoTag != 0xC0000000U) r8 = 0;
        if (r8 == 0 && ((u32)fontInfo & 0xFF800000U) != 0xC1000000U) r7 = 0;
        if (r7 == 0 && ((u32)fontInfo & 0xF8000000U) != 0xD0000000U) r5 = 0;
        if (r5 == 0 && ((u32)fontInfo & 0xFFFFC000U) != 0xE0000000U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F7, file + 0x128);
    }
    register u8 *codeMap=*(u8**)(*(u8**)((u8*)self+0x14)+0x10);
    register u16 glyphIndex;
    while (codeMap!=0) {
        if (*(u16*)codeMap<=code && code<=*(u16*)(codeMap+2)) {
            glyphIndex=::FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(self,codeMap,code);
            goto checkIndex;
        }
        codeMap=*(u8**)(codeMap+8);
    }
    glyphIndex=0xFFFF;
checkIndex:
    if (glyphIndex!=0xFFFF) {
        *(u16*)(*(u8**)((u8*)self+0x14)+2)=glyphIndex;
        return 1;
    }
    return 0;
}
#pragma pop

/*
 * nw4hbm::ut::detail::ResFontBase::SetLineFeed (ut_ResFontBase.cpp).
 * Puts the line feed into the font information's line-feed byte,
 * mFontInfo (@0x14) -> +1, which is what GetLineFeed() reads back; it has to
 * fit in a signed byte.  The strings are all in lbl_80329140: +0xC
 * "ut_ResFontBase.cpp", +0xF0 "this(=%p) is not valid pointer.", +0x128
 * "mFontInfo(=%p) is not valid pointer." and +0x1A0 "linefeed is out of
 * bounds(%d)\n%d <= linefeed ...", which is given the value and the range.
 */
void nw4hbm::ut::detail::ResFontBase::SetLineFeed(int lineFeed) {
    const char* file = lbl_80329140;
    u32 selfAddr = (u32)this;
    /* nw4hbm::db pointer check: matched_<range> says the address fell in one of
     * the ranges accepted up to that range (MEM1 0x80000000/0x81000000, MEM2
     * 0x90000000, 0xC0000000, 0xC1000000, 0xD0000000, the ROM mirror at
     * 0xE0000000), so `valid` is the verdict.  They are declared innermost
     * check last: the compiler gives them r5..r10 in declaration order. */
    int valid = 1, matched_d0 = 1, matched_c1 = 1, matched_c0 = 1, matched_mem2 = 1, matched_mem1 = 1;
    u32 selfTop = selfAddr & 0xFF000000U;
    if (selfTop != 0x80000000U && (selfAddr & 0xFF800000U) != 0x81000000U) matched_mem1 = 0;
    if (matched_mem1 == 0 && (selfAddr & 0xF8000000U) != 0x90000000U) matched_mem2 = 0;
    if (matched_mem2 == 0 && selfTop != 0xC0000000U) matched_c0 = 0;
    if (matched_c0 == 0 && (selfAddr & 0xFF800000U) != 0xC1000000U) matched_c1 = 0;
    if (matched_c1 == 0 && (selfAddr & 0xF8000000U) != 0xD0000000U) matched_d0 = 0;
    if (matched_d0 == 0 && (selfAddr & 0xFFFFC000U) != 0xE0000000U) valid = 0;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x177, file + 0xF0, this);
    /* the same check on mFontInfo, whose panic names the field but not its
     * address (the two flags it still needs are r4 and r5) */
    int info_valid = 1, info_matched_d0 = 1;
    u32 fontInfoPtr = *(u32*)((char*)this + 0x14);
    int info_matched_c1 = 1, info_matched_c0 = 1, info_matched_mem2 = 1, info_matched_mem1 = 1;
    u32 fontInfoTop = fontInfoPtr & 0xFF000000U;
    if (fontInfoTop != 0x80000000U && (fontInfoPtr & 0xFF800000U) != 0x81000000U) info_matched_mem1 = 0;
    if (info_matched_mem1 == 0 && (fontInfoPtr & 0xF8000000U) != 0x90000000U) info_matched_mem2 = 0;
    if (info_matched_mem2 == 0 && fontInfoTop != 0xC0000000U) info_matched_c0 = 0;
    if (info_matched_c0 == 0 && (fontInfoPtr & 0xFF800000U) != 0xC1000000U) info_matched_c1 = 0;
    if (info_matched_c1 == 0 && (fontInfoPtr & 0xF8000000U) != 0xD0000000U) info_matched_d0 = 0;
    if (info_matched_d0 == 0 && (fontInfoPtr & 0xFFFFC000U) != 0xE0000000U) info_valid = 0;
    if (info_valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x178, file + 0x128);
    /* and the assert that the line feed fits in the signed byte it is stored
     * in; mFontInfo is read out again for the store itself */
    int inRange = 0;
    if (lineFeed >= -128 && lineFeed <= 127) inRange = 1;
    if (!inRange) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x179, file + 0x1A0, lineFeed, -128, 127);
    *(s8*)(*(u32*)((char*)this + 0x14) + 1) = lineFeed;
}

#pragma push
#pragma scheduling off
extern "C" s8 fn_8010B2BC(void *arg0) {
    struct V { virtual u32 a0()=0; virtual u32 a1()=0; virtual u32 a2()=0; virtual u32 a3()=0; virtual u32 a4()=0; virtual u32 a5()=0; virtual u32 a6()=0; virtual u32 a7()=0; virtual u32 a8()=0; virtual u32 a9()=0; virtual u32 a10()=0; virtual u32 a11()=0; virtual u32 a12()=0; virtual u32 a13()=0; virtual u32 a14()=0; virtual u32 a15()=0; virtual u32 a16()=0; virtual u32 f()=0; };
    u32 value = ((V *)arg0)->f();
    volatile u8 c;
    volatile u8 b;
    volatile u8 a;
    u8 tmp;
    s8 ret;
    a = (u8)(value >> 24);
    b = (u8)(value >> 16);
    tmp = (u8)(value >> 8);
    ret = tmp;
    c = tmp;
    return ret;
}
#pragma pop
extern "C" const char lbl_80329140[];
extern "C" u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void*, void*, u16);
extern "C" u32 GetCharWidths__Q46nw4hbm2ut6detail11ResFontBaseCFUs(void *self, u16 code) {
    const char *file = lbl_80329140;
    u32 value = (u32)self;
    u32 t;
    int a, b, c, d, e, f, ok;
    u8 *info, *map, *width, *entry;
    register u16 glyph;

    a = 1; b = 1; c = 1; d = 1; e = 1; f = 1;
    t = value & 0xFF000000U;
    if (t != 0x80000000U && (value & 0xFF800000U) != 0x81000000U) f = 0;
    if (f == 0 && (value & 0xF8000000U) != 0x90000000U) e = 0;
    if (e == 0 && t != 0xC0000000U) d = 0;
    if (d == 0 && (value & 0xFF800000U) != 0xC1000000U) c = 0;
    if (c == 0 && (value & 0xF8000000U) != 0xD0000000U) b = 0;
    if (b == 0 && (value & 0xFFFFC000U) != 0xE0000000U) a = 0;
    if (a == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1E2, file + 0xF0, self);

    {
        int g = 1, h = 1;
        u32 v = *(u32 *)((char *)self + 0x14);
        int i = 1, j = 1, k = 1, l = 1;
        u32 t2 = v & 0xFF000000U;
        if (t2 != 0x80000000U && (v & 0xFF800000U) != 0x81000000U) l = 0;
        if (l == 0 && (v & 0xF8000000U) != 0x90000000U) k = 0;
        if (k == 0 && t2 != 0xC0000000U) j = 0;
        if (j == 0 && (v & 0xFF800000U) != 0xC1000000U) i = 0;
        if (i == 0 && (v & 0xF8000000U) != 0xD0000000U) h = 0;
        if (h == 0 && (v & 0xFFFFC000U) != 0xE0000000U) g = 0;
        if (g == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1E3, file + 0x128);
    }

    ok = 0;
    if (t == 0x80000000U || (value & 0xFF800000U) == 0x81000000U || (value & 0xF8000000U) == 0x90000000U
        || t == 0xC0000000U || (value & 0xFF800000U) == 0xC1000000U || (value & 0xF8000000U) == 0xD0000000U
        || (value & 0xFFFFC000U) == 0xE0000000U) ok = 1;
    if (ok == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F6, file + 0xF0, self);

    {
        int g = 1, h = 1;
        u32 v = *(u32 *)((char *)self + 0x14);
        int i = 1, j = 1, k = 1, l = 1;
        u32 t2 = v & 0xFF000000U;
        if (t2 != 0x80000000U && (v & 0xFF800000U) != 0x81000000U) l = 0;
        if (l == 0 && (v & 0xF8000000U) != 0x90000000U) k = 0;
        if (k == 0 && t2 != 0xC0000000U) j = 0;
        if (j == 0 && (v & 0xFF800000U) != 0xC1000000U) i = 0;
        if (i == 0 && (v & 0xF8000000U) != 0xD0000000U) h = 0;
        if (h == 0 && (v & 0xFFFFC000U) != 0xE0000000U) g = 0;
        if (g == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F7, file + 0x128);
    }

    map = *(u8 **)(*(u8 **)((char *)self + 0x14) + 0x10);
    while (map != 0) {
        if (*(u16 *)map <= code && code <= *(u16 *)(map + 2)) {
            glyph = FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(self, map, code);
            goto checkGlyph;
        }
        map = *(u8 **)(map + 8);
    }
    glyph = 0xFFFF;
checkGlyph:
    if (glyph == 0xFFFF) glyph = *(u16 *)(*(u8 **)((char *)self + 0x14) + 2);

    ok = 0;
    if (t == 0x80000000U || (value & 0xFF800000U) == 0x81000000U || (value & 0xF8000000U) == 0x90000000U
        || t == 0xC0000000U || (value & 0xFF800000U) == 0xC1000000U || (value & 0xF8000000U) == 0xD0000000U
        || (value & 0xFFFFC000U) == 0xE0000000U) ok = 1;
    if (ok == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x267, file + 0xF0, self);

    {
        int g = 1, h = 1;
        u32 v = *(u32 *)((char *)self + 0x14);
        int i = 1, j = 1, k = 1, l = 1;
        u32 t2 = v & 0xFF000000U;
        if (t2 != 0x80000000U && (v & 0xFF800000U) != 0x81000000U) l = 0;
        if (l == 0 && (v & 0xF8000000U) != 0x90000000U) k = 0;
        if (k == 0 && t2 != 0xC0000000U) j = 0;
        if (j == 0 && (v & 0xFF800000U) != 0xC1000000U) i = 0;
        if (i == 0 && (v & 0xF8000000U) != 0xD0000000U) h = 0;
        if (h == 0 && (v & 0xFFFFC000U) != 0xE0000000U) g = 0;
        if (g == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x268, file + 0x128);
    }

    info = *(u8 **)((char *)self + 0x14);
    width = *(u8 **)(info + 0xC);
    while (width) {
        if (*(u16 *)width <= glyph && glyph <= *(u16 *)(width + 2)) {
            int g = 1, h = 1;
            u32 w = (u32)width;
            int i = 1, j = 1, k = 1, l = 1;
            u32 tw = w & 0xFF000000U;
            if (tw != 0x80000000U && (w & 0xFF800000U) != 0x81000000U) l = 0;
            if (l == 0 && (w & 0xF8000000U) != 0x90000000U) k = 0;
            if (k == 0 && tw != 0xC0000000U) j = 0;
            if (j == 0 && (w & 0xFF800000U) != 0xC1000000U) i = 0;
            if (i == 0 && (w & 0xF8000000U) != 0xD0000000U) h = 0;
            if (h == 0 && (w & 0xFFFFC000U) != 0xE0000000U) g = 0;
            if (g == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x28B, file + 0x1E4, width);
            entry = width + 8 + 3 * (glyph - *(u16 *)width);
            return ((u32)*(u16 *)entry << 16) | ((u32)entry[2] << 8);
        }
        width = *(u8 **)(width + 4);
    }
    entry = info + 4;
    return ((u32)*(u16 *)entry << 16) | ((u32)entry[2] << 8);
}

#pragma push
#pragma use_lmw_stmw off
/* Resolves character `code` to a glyph: finds its index in the font's
 * code-map list (falling back to the font's default glyph index) and fills in
 * `glyph` from that index. The repeated blocks are NW4R's debug pointer-range
 * checks, which panic unless `this` / mFontInfo lie in a known address range. */
void nw4hbm::ut::detail::ResFontBase::GetGlyph(nw4hbm::ut::Glyph* glyph, unsigned short code) const {
    const char* file = lbl_80329140;
    register u32 thisPage = (u32)this & 0xFF000000U;
    {
        /* Each flag keeps the OR of the address-range tests done so far. */
        register int ok1 = 1, ok2 = 1, ok3 = 1, ok4 = 1, ok5 = 1, ok6 = 1;
        if (thisPage != 0x80000000U && ((u32)this & 0xFF800000U) != 0x81000000U) ok6 = 0;
        if (ok6 == 0 && ((u32)this & 0xF8000000U) != 0x90000000U) ok5 = 0;
        if (ok5 == 0 && thisPage != 0xC0000000U) ok4 = 0;
        if (ok4 == 0 && ((u32)this & 0xFF800000U) != 0xC1000000U) ok3 = 0;
        if (ok3 == 0 && ((u32)this & 0xF8000000U) != 0xD0000000U) ok2 = 0;
        if (ok2 == 0 && ((u32)this & 0xFFFFC000U) != 0xE0000000U) ok1 = 0;
        if (ok1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1E2, file + 0xF0, this);
    }
    {
        register int ok1 = 1, ok2 = 1;
        u8* fontInfo = *(u8**)((char*)this + 0x14);
        register int ok3 = 1;
        register int ok4 = 1, ok5 = 1, ok6 = 1;
        register u32 fontInfoPage = (u32)fontInfo & 0xFF000000U;
        if (fontInfoPage != 0x80000000U && ((u32)fontInfo & 0xFF800000U) != 0x81000000U) ok6 = 0;
        if (ok6 == 0 && ((u32)fontInfo & 0xF8000000U) != 0x90000000U) ok5 = 0;
        if (ok5 == 0 && fontInfoPage != 0xC0000000U) ok4 = 0;
        if (ok4 == 0 && ((u32)fontInfo & 0xFF800000U) != 0xC1000000U) ok3 = 0;
        if (ok3 == 0 && ((u32)fontInfo & 0xF8000000U) != 0xD0000000U) ok2 = 0;
        if (ok2 == 0 && ((u32)fontInfo & 0xFFFFC000U) != 0xE0000000U) ok1 = 0;
        if (ok1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1E3, file + 0x128);
    }
    {
        register u32 maskedRange, maskedPage;
        register int isValid = 0;
        if (thisPage == 0x80000000U ||
            (maskedPage = (u32)this & 0xFF800000U) == 0x81000000U ||
            (maskedRange = (u32)this & 0xF8000000U) == 0x90000000U ||
            thisPage == 0xC0000000U ||
            maskedPage == 0xC1000000U ||
            maskedRange == 0xD0000000U ||
            ((u32)this & 0xFFFFC000U) == 0xE0000000U)
            isValid = 1;
        if (isValid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F6, file + 0xF0, this);
    }
    {
        register int ok1 = 1, ok2 = 1;
        u8* fontInfo = *(u8**)((char*)this + 0x14);
        register int ok3 = 1;
        register int ok4 = 1, ok5 = 1, ok6 = 1;
        register u32 fontInfoPage = (u32)fontInfo & 0xFF000000U;
        if (fontInfoPage != 0x80000000U && ((u32)fontInfo & 0xFF800000U) != 0x81000000U) ok6 = 0;
        if (ok6 == 0 && ((u32)fontInfo & 0xF8000000U) != 0x90000000U) ok5 = 0;
        if (ok5 == 0 && fontInfoPage != 0xC0000000U) ok4 = 0;
        if (ok4 == 0 && ((u32)fontInfo & 0xFF800000U) != 0xC1000000U) ok3 = 0;
        if (ok3 == 0 && ((u32)fontInfo & 0xF8000000U) != 0xD0000000U) ok2 = 0;
        if (ok2 == 0 && ((u32)fontInfo & 0xFFFFC000U) != 0xE0000000U) ok1 = 0;
        if (ok1 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x1F7, file + 0x128);
    }
    /* mFontInfo (@0x14) -> mCodeMap (@0x10); each map is
     * { u16 start; u16 end; u16 method; u16 pad; Map* next (@8); ... }. */
    u8* codeMap = *(u8**)(*(u8**)((char*)this + 0x14) + 0x10);
    u16 glyphIndex;
    while (codeMap != 0) {
        if (*(u16*)codeMap <= code && code <= *(u16*)(codeMap + 2)) {
            glyphIndex = ::FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs((void*)this, codeMap, code);
            goto check_index;
        }
        codeMap = *(u8**)(codeMap + 8);
    }
    glyphIndex = 0xFFFF;
check_index:
    glyphIndex = glyphIndex != 0xFFFF ? glyphIndex : *(u16*)(*(u8**)((char*)this + 0x14) + 2);
    GetGlyphFromIndex(glyph, glyphIndex);
}

/* nw4hbm::ut::detail::ResFontBase::GetWidth() const: validate this and its font data pointer, then return font width byte. */
extern "C" u8 GetWidth__Q46nw4hbm2ut6detail11ResFontBaseCFv_8010BD8C(void* self) {
    const char* file=lbl_80329140;
    u32 selfAddr=(u32)self;
    int ok1=1,ok2=1,ok3=1,ok4=1,ok5=1,ok6=1;
    u32 hi=selfAddr&0xFF000000U;
    if (hi!=0x80000000U && (selfAddr&0xFF800000U)!=0x81000000U) ok6=0;
    if (ok6==0 && (selfAddr&0xF8000000U)!=0x90000000U)ok5=0;
    if (ok5==0 && hi!=0xC0000000U)ok4=0;
    if (ok4==0 && (selfAddr&0xFF800000U)!=0xC1000000U)ok3=0;
    if (ok3==0 && (selfAddr&0xF8000000U)!=0xD0000000U)ok2=0;
    if (ok2==0 && (selfAddr&0xFFFFC000U)!=0xE0000000U)ok1=0;
    if(ok1==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x1C8,file+0xF0,self);
    int fontOk1=1,fontOk2=1;
    u32 fontAddr=*(u32*)((char*)self+0x14);
    int fontOk3=1,fontOk4=1,fontOk5=1,fontOk6=1;
    u32 fontHi=fontAddr&0xFF000000U;
    if(fontHi!=0x80000000U&&(fontAddr&0xFF800000U)!=0x81000000U)fontOk6=0;
    if(fontOk6==0&&(fontAddr&0xF8000000U)!=0x90000000U)fontOk5=0;
    if(fontOk5==0&&fontHi!=0xC0000000U)fontOk4=0;
    if(fontOk4==0&&(fontAddr&0xFF800000U)!=0xC1000000U)fontOk3=0;
    if(fontOk3==0&&(fontAddr&0xF8000000U)!=0xD0000000U)fontOk2=0;
    if(fontOk2==0&&(fontAddr&0xFFFFC000U)!=0xE0000000U)fontOk1=0;
    if(fontOk1==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xC,0x1C9,file+0x128);
    return *(u8*)(*(u32*)((char*)self+0x14)+7);
}

#pragma pop

/*
 * nw4hbm::ut::detail::ResFontBase::FindGlyphIndex(const FontCodeMap*, u16) const
 * Turns a character code into an index into the font's glyph table using one of
 * the font's code maps -- the caller has already picked the map whose
 * start_code..end_code covers the code.  Returns 0xFFFF when the map holds no
 * entry for it.  (self and code_map stay void*: the callers in this file walk
 * the map list with u8*.)
 */
extern "C" u16 FindGlyphIndex__Q46nw4hbm2ut6detail11ResFontBaseCFPCQ36nw4hbm2ut11FontCodeMapUs(void *self, void *code_map, u16 code) {
    typedef nw4hbm::ut::FontCodePair CodePair;
    typedef nw4hbm::ut::FontCodeBinaryMap BinaryMap;
    const char* file = lbl_80329140; /* "ut_ResFontBase.cpp" and this file's panic messages */
    u32 value = (u32)self;
    /* nw4hbm::db pointer check: matched_<range> says the address fell in one of
     * the ranges accepted up to that range (MEM1 0x80000000/0x81000000, MEM2
     * 0x90000000, 0xC0000000, 0xC1000000, 0xD0000000, the ROM mirror at
     * 0xE0000000), so `valid` is the verdict.  They are declared innermost
     * check last: the compiler gives them r5..r10 in declaration order. */
    int valid = 1, matched_d0 = 1, matched_c1 = 1, matched_c0 = 1, matched_mem2 = 1, matched_mem1 = 1;
    u32 top = value & 0xFF000000U;
    if (top != 0x80000000U && (value & 0xFF800000U) != 0x81000000U) matched_mem1 = 0;
    if (matched_mem1 == 0 && (value & 0xF8000000U) != 0x90000000U) matched_mem2 = 0;
    if (matched_mem2 == 0 && top != 0xC0000000U) matched_c0 = 0;
    if (matched_c0 == 0 && (value & 0xFF800000U) != 0xC1000000U) matched_c1 = 0;
    if (matched_c1 == 0 && (value & 0xF8000000U) != 0xD0000000U) matched_d0 = 0;
    if (matched_d0 == 0 && (value & 0xFFFFC000U) != 0xE0000000U) valid = 0;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x21B, file + 0xF0, self);
    /* the same check on the code map, panicking with its address */
    u32 map_value = (u32)code_map;
    int map_valid = 1, map_matched_d0 = 1, map_matched_c1 = 1, map_matched_c0 = 1, map_matched_mem2 = 1, map_matched_mem1 = 1;
    u32 map_top = map_value & 0xFF000000U;
    if (map_top != 0x80000000U && (map_value & 0xFF800000U) != 0x81000000U) map_matched_mem1 = 0;
    if (map_matched_mem1 == 0 && (map_value & 0xF8000000U) != 0x90000000U) map_matched_mem2 = 0;
    if (map_matched_mem2 == 0 && map_top != 0xC0000000U) map_matched_c0 = 0;
    if (map_matched_c0 == 0 && (map_value & 0xFF800000U) != 0xC1000000U) map_matched_c1 = 0;
    if (map_matched_c1 == 0 && (map_value & 0xF8000000U) != 0xD0000000U) map_matched_d0 = 0;
    if (map_matched_d0 == 0 && (map_value & 0xFFFFC000U) != 0xE0000000U) map_valid = 0;
    if (map_valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x21C, file + 0x21C, code_map);
    const nw4hbm::ut::FontCodeMap* map = (const nw4hbm::ut::FontCodeMap*)code_map;
    u16 result = 0xFFFF; /* no entry for this code */
    switch (map->map_type) {
    case FONT_CODE_MAP_TYPE_OFFSET: /* a block of codes sits consecutively in the glyph table */
        result = (u16)(map->map.offset + (code - map->start_code));
        break;
    case FONT_CODE_MAP_TYPE_INDEX: /* one glyph index per code */
        result = map->map.indices[code - map->start_code];
        break;
    case FONT_CODE_MAP_TYPE_BINARY: { /* (code, index) pairs sorted by code */
        const BinaryMap* binary = &map->map.binary;
        const CodePair* low = &binary->pairs[0];
        const CodePair* high = &binary->pairs[binary->count - 1];
        while (low <= high) {
            const CodePair* mid = low + (high - low) / 2;
            if (mid->code < code) low = mid + 1;
            else if (code < mid->code) high = mid - 1;
            else { result = mid->index; break; }
        }
        break;
    }
    default: /* none of the three map types */
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x255, file + 0x254);
        break;
    }
    return result;
}

#pragma push
#pragma use_lmw_stmw off
void nw4hbm::ut::detail::ResFontBase::GetGlyphFromIndex(nw4hbm::ut::Glyph* glyph, unsigned short index) const {
    const char* file = lbl_80329140;
    register u32 top = (u32)this & 0xFF000000U;
    {
        register int r5 = 1, r6 = 1, r7 = 1, r8 = 1, r9 = 1, r10 = 1;
        if (top != 0x80000000U && ((u32)this & 0xFF800000U) != 0x81000000U) r10 = 0;
        if (r10 == 0 && ((u32)this & 0xF8000000U) != 0x90000000U) r9 = 0;
        if (r9 == 0 && top != 0xC0000000U) r8 = 0;
        if (r8 == 0 && ((u32)this & 0xFF800000U) != 0xC1000000U) r7 = 0;
        if (r7 == 0 && ((u32)this & 0xF8000000U) != 0xD0000000U) r6 = 0;
        if (r6 == 0 && ((u32)this & 0xFFFFC000U) != 0xE0000000U) r5 = 0;
        if (r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x29F, file + 0xF0, this);
    }
    {
        register int r4 = 1, r5 = 1;
        u8* info = *(u8**)((char*)this + 0x14);
        register int r7 = 1;
        register int r8 = 1, r9 = 1, r10 = 1;
        register u32 infoTop = (u32)info & 0xFF000000U;
        if (infoTop != 0x80000000U && ((u32)info & 0xFF800000U) != 0x81000000U) r10 = 0;
        if (r10 == 0 && ((u32)info & 0xF8000000U) != 0x90000000U) r9 = 0;
        if (r9 == 0 && infoTop != 0xC0000000U) r8 = 0;
        if (r8 == 0 && ((u32)info & 0xFF800000U) != 0xC1000000U) r7 = 0;
        if (r7 == 0 && ((u32)info & 0xF8000000U) != 0xD0000000U) r5 = 0;
        if (r5 == 0 && ((u32)info & 0xFFFFC000U) != 0xE0000000U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x2A0, file + 0x128);
    }
    u8 *info=*(u8**)((char*)this+0x14);
    u8 *font=*(u8**)(info+8);
    u32 columns=*(u16*)(font+0xc), rows=*(u16*)(font+0xe);
    register u32 cellw=font[0]+1, cellh=font[1]+1;
    register u32 sheet=index/(columns*rows);
    u32 rem=index%(columns*rows);
    u32 row=rem/columns;
    u32 col=rem%columns;
    u32 x=col*cellw;
    u32 y=row*cellh;
    *(u32*)glyph=*(u32*)(font+0x14)+sheet*(*(u32*)(font+4));
    {
        register u32 a, b;
        register int valid = 0;
        if (top == 0x80000000U ||
            (a = (u32)this & 0xFF800000U) == 0x81000000U ||
            (b = (u32)this & 0xF8000000U) == 0x90000000U ||
            top == 0xC0000000U ||
            a == 0xC1000000U ||
            b == 0xD0000000U ||
            ((u32)this & 0xFFFFC000U) == 0xE0000000U)
            valid = 1;
        if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x267, file + 0xF0, this);
    }
    {
        register int r4 = 1, r5 = 1;
        u8* info = *(u8**)((char*)this + 0x14);
        register int r7 = 1;
        register int r8 = 1, r9 = 1, r10 = 1;
        register u32 infoTop = (u32)info & 0xFF000000U;
        if (infoTop != 0x80000000U && ((u32)info & 0xFF800000U) != 0x81000000U) r10 = 0;
        if (r10 == 0 && ((u32)info & 0xF8000000U) != 0x90000000U) r9 = 0;
        if (r9 == 0 && infoTop != 0xC0000000U) r8 = 0;
        if (r8 == 0 && ((u32)info & 0xFF800000U) != 0xC1000000U) r7 = 0;
        if (r7 == 0 && ((u32)info & 0xF8000000U) != 0xD0000000U) r5 = 0;
        if (r5 == 0 && ((u32)info & 0xFFFFC000U) != 0xE0000000U) r4 = 0;
        if (r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0xC, 0x268, file + 0x128);
    }
    info=*(u8**)((char*)this+0x14);
    u8 *map=*(u8**)(info+0xc);
    u8 *entry;
    while(map != 0) {
        if (*(u16*)map <= index && index <= *(u16*)(map+2)) {
            register int r4=1,r5=1,r6=1,r7=1,r8=1,r9=1;
            register u32 mapTop=(u32)map & 0xff000000U;
            if(mapTop!=0x80000000U && ((u32)map&0xff800000U)!=0x81000000U)r9=0;
            if(r9==0 && ((u32)map&0xf8000000U)!=0x90000000U)r8=0;
            if(r8==0 && mapTop!=0xc0000000U)r7=0;
            if(r7==0 && ((u32)map&0xff800000U)!=0xc1000000U)r6=0;
            if(r6==0 && ((u32)map&0xf8000000U)!=0xd0000000U)r5=0;
            if(r5==0 && ((u32)map&0xffffc000U)!=0xe0000000U)r4=0;
            if(r4==0)Panic__Q26nw4hbm2dbFPCciPCce(file+0xc,0x28b,file+0x1e4,map);
            entry=map+8+3*(index-*(u16*)map);
            goto found;
        }
        map=*(u8**)(map+4);
    }
    entry=info+4;
found:
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

extern "C" f32 fn_8010F81C(void *writer, s32 arg1, s32 arg2);
extern "C" f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(void *);
extern "C" f32 GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(void *);
extern "C" f32 fn_8010DC74(void *writer, const char *fmt, ...) {
    va_list args;
    char *buf;
    int len;
    unsigned char copy[0x60];
    unsigned char *s = (unsigned char *)writer;
    int i;
    f32 w;
    f32 h1;
    f32 h2;

    va_start(args, fmt);
    if (lbl_8055DEB0 != 0) {
        buf = lbl_8055DEB0;
    } else {
        buf = (char *)(((unsigned int)alloca((unsigned int)lbl_80559928) + 7) & ~(unsigned int)7);
    }
    len = vsnprintf(buf, (unsigned int)lbl_80559928, fmt, args);
    va_end(args);

    s = (unsigned char *)writer;
    for (i = 0; i < 0x60; i++) copy[i] = s[i];

    w = fn_8010F81C(copy, (s32)buf, len);
    h1 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770(copy);
    h2 = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658(copy);
    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)writer, h1, h2);
    fn_801033F0(copy, 0);
    return w;
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
    var_r10 = 1;
    var_r9 = 1;
    var_r8 = 1;
    var_r7 = 1;
    var_r6 = 1;
    var_r5 = 1;
    if (((u32)temp_r11 != 0x80000000U) &&
        ((arg0 & 0xFF800000U) != 0x81000000U)) var_r10 = 0;
    if ((var_r10 == 0) && ((arg0 & 0xF8000000U) != 0x90000000U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)temp_r11 != 0xC0000000U)) var_r8 = 0;
    if ((var_r8 == 0) && ((arg0 & 0xFF800000U) != 0xC1000000U)) var_r7 = 0;
    if ((var_r7 == 0) && ((arg0 & 0xF8000000U) != 0xD0000000U)) var_r6 = 0;
    if ((var_r6 == 0) && ((arg0 & 0xFFFFC000U) != 0xE0000000U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F2, base + 0x48, arg0);
    temp_r10 = arg1 & 0xFF000000;
    var_r9_2 = 1;
    var_r8_2 = 1;
    var_r7_2 = 1;
    var_r6_2 = 1;
    var_r5_2 = 1;
    var_r4 = 1;
    if (((u32)temp_r10 != 0x80000000U) &&
        ((arg1 & 0xFF800000U) != 0x81000000U)) var_r9_2 = 0;
    if ((var_r9_2 == 0) && ((arg1 & 0xF8000000U) != 0x90000000U)) var_r8_2 = 0;
    if ((var_r8_2 == 0) && ((u32)temp_r10 != 0xC0000000U)) var_r7_2 = 0;
    if ((var_r7_2 == 0) && ((arg1 & 0xFF800000U) != 0xC1000000U)) var_r6_2 = 0;
    if ((var_r6_2 == 0) && ((arg1 & 0xF8000000U) != 0xD0000000U)) var_r5_2 = 0;
    if ((var_r5_2 == 0) && ((arg1 & 0xFFFFC000U) != 0xE0000000U)) var_r4 = 0;
    if (var_r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F3, base + 0xF8, arg1);
    temp_r10_2 = var_r29 & 0xFF000000;
    var_r9_3 = 1;
    var_r8_3 = 1;
    var_r7_3 = 1;
    var_r6_3 = 1;
    var_r5_3 = 1;
    var_r4_2 = 1;
    if (((u32)temp_r10_2 != 0x80000000U) &&
        ((var_r29 & 0xFF800000U) != 0x81000000U)) var_r9_3 = 0;
    if ((var_r9_3 == 0) && ((var_r29 & 0xF8000000U) != 0x90000000U)) var_r8_3 = 0;
    if ((var_r8_3 == 0) && ((u32)temp_r10_2 != 0xC0000000U)) var_r7_3 = 0;
    if ((var_r7_3 == 0) && ((var_r29 & 0xFF800000U) != 0xC1000000U)) var_r6_3 = 0;
    if ((var_r6_3 == 0) && ((var_r29 & 0xF8000000U) != 0xD0000000U)) var_r5_3 = 0;
    if ((var_r5_3 == 0) && ((var_r29 & 0xFFFFC000U) != 0xE0000000U)) var_r4_2 = 0;
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
        var_f1 = (temp_f0 > var_f1) ? var_f1 : temp_f0;
        *(f32 *)arg1 = var_f1;
        temp_f0_2 = *(f32 *)(arg1 + 4);
        var_f1_2 = spC;
        var_f1_2 = (temp_f0_2 > var_f1_2) ? var_f1_2 : temp_f0_2;
        *(f32 *)(arg1 + 4) = var_f1_2;
        temp_f0_3 = *(f32 *)(arg1 + 8);
        var_f1_3 = sp10;
        var_f1_3 = (temp_f0_3 < var_f1_3) ? var_f1_3 : temp_f0_3;
        *(f32 *)(arg1 + 8) = var_f1_3;
        temp_f0_4 = *(f32 *)(arg1 + 0xC);
        var_f1_4 = sp14;
        var_f1_4 = (temp_f0_4 < var_f1_4) ? var_f1_4 : temp_f0_4;
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
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    s32 var_r9;
    s32 var_r10;
    s32 temp_r11;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r4_5;
    s32 var_r4_6;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
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
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s32 var_r9_5;
    s32 var_r9_6;
    s32 var_r9_7;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r10_3;
    s32 temp_r10_4;
    s32 temp_r10_5;
    s32 temp_r10_6;
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
        if ((u32)temp_r11 == 0x80000000U) {
        } else if (((u32)arg0 & 0xFF800000) == 0x81000000U) {
        } else {
            var_r10 = 0;
        }
        if ((var_r10 == 0) && ((u32)((s32) arg0 & 0xF8000000) != 0x90000000U)) {
            var_r9 = 0;
        }
        if ((var_r9 == 0) && ((u32)temp_r11 != 0xC0000000U)) {
            var_r8 = 0;
        }
        if ((var_r8 == 0) && ((u32)((s32) arg0 & 0xFF800000) != 0xC1000000U)) {
            var_r7 = 0;
        }
        if ((var_r7 == 0) && ((u32)((s32) arg0 & 0xF8000000) != 0xD0000000U)) {
            var_r6 = 0;
        }
        if ((var_r6 == 0) && ((u32)((s32) arg0 & 0xFFFFC000) != 0xE0000000U)) {
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
        if (((u32)temp_r10 != 0x80000000U) && ((u32)((s32) &rectA[0] & 0xFF800000) != 0x81000000U)) {
            var_r9_2 = 0;
        }
        if ((var_r9_2 == 0) && ((u32)((s32) &rectA[0] & 0xF8000000) != 0x90000000U)) {
            var_r8_2 = 0;
        }
        if ((var_r8_2 == 0) && ((u32)temp_r10 != 0xC0000000U)) {
            var_r7_2 = 0;
        }
        if ((var_r7_2 == 0) && ((u32)((s32) &rectA[0] & 0xFF800000) != 0xC1000000U)) {
            var_r6_2 = 0;
        }
        if ((var_r6_2 == 0) && ((u32)((s32) &rectA[0] & 0xF8000000) != 0xD0000000U)) {
            var_r5_2 = 0;
        }
        if ((var_r5_2 == 0) && ((u32)((s32) &rectA[0] & 0xFFFFC000) != 0xE0000000U)) {
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
        if (((u32)temp_r10_2 != 0x80000000U) && ((u32)(arg3 & 0xFF800000) != 0x81000000U)) {
            var_r9_3 = 0;
        }
        if ((var_r9_3 == 0) && ((u32)(arg3 & 0xF8000000) != 0x90000000U)) {
            var_r8_3 = 0;
        }
        if ((var_r8_3 == 0) && ((u32)temp_r10_2 != 0xC0000000U)) {
            var_r7_3 = 0;
        }
        if ((var_r7_3 == 0) && ((u32)(arg3 & 0xFF800000) != 0xC1000000U)) {
            var_r6_3 = 0;
        }
        if ((var_r6_3 == 0) && ((u32)(arg3 & 0xF8000000) != 0xD0000000U)) {
            var_r5_3 = 0;
        }
        if ((var_r5_3 == 0) && ((u32)(arg3 & 0xFFFFC000) != 0xE0000000U)) {
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
        {
            s32 copyA_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
            s32 copyA_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
            (*(s32*)(copyA+0x24)) = copyA_24;
            (*(s32*)(copyA+0x28)) = copyA_28;
        }
        {
            s32 copyA_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
            s32 copyA_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
            (*(s32*)(copyA+0x2C)) = copyA_2C;
            (*(s32*)(copyA+0x30)) = copyA_30;
        }
        (*(s32*)(copyA+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
        {
            s32 copyA_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
            s32 copyA_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
            (*(s32*)(copyA+0x38)) = copyA_38;
            (*(s32*)(copyA+0x3C)) = copyA_3C;
        }
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
        if (((u32)temp_r10_3 != 0x80000000U) && ((u32)((s32) arg0 & 0xFF800000) != 0x81000000U)) {
            var_r9_4 = 0;
        }
        if ((var_r9_4 == 0) && ((u32)((s32) arg0 & 0xF8000000) != 0x90000000U)) {
            var_r8_4 = 0;
        }
        if ((var_r8_4 == 0) && ((u32)temp_r10_3 != 0xC0000000U)) {
            var_r7_4 = 0;
        }
        if ((var_r7_4 == 0) && ((u32)((s32) arg0 & 0xFF800000) != 0xC1000000U)) {
            var_r6_4 = 0;
        }
        if ((var_r6_4 == 0) && ((u32)((s32) arg0 & 0xF8000000) != 0xD0000000U)) {
            var_r5_4 = 0;
        }
        if ((var_r5_4 == 0) && ((u32)((s32) arg0 & 0xFFFFC000) != 0xE0000000U)) {
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
        if (((u32)temp_r10_4 != 0x80000000U) && ((u32)(arg3 & 0xFF800000) != 0x81000000U)) {
            var_r9_5 = 0;
        }
        if ((var_r9_5 == 0) && ((u32)(arg3 & 0xF8000000) != 0x90000000U)) {
            var_r8_5 = 0;
        }
        if ((var_r8_5 == 0) && ((u32)temp_r10_4 != 0xC0000000U)) {
            var_r7_5 = 0;
        }
        if ((var_r7_5 == 0) && ((u32)(arg3 & 0xFF800000) != 0xC1000000U)) {
            var_r6_5 = 0;
        }
        if ((var_r6_5 == 0) && ((u32)(arg3 & 0xF8000000) != 0xD0000000U)) {
            var_r5_5 = 0;
        }
        if ((var_r5_5 == 0) && ((u32)(arg3 & 0xFFFFC000) != 0xE0000000U)) {
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
        {
            s32 copyB_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
            s32 copyB_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
            (*(s32*)(copyB+0x24)) = copyB_24;
            (*(s32*)(copyB+0x28)) = copyB_28;
        }
        {
            s32 copyB_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
            s32 copyB_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
            (*(s32*)(copyB+0x2C)) = copyB_2C;
            (*(s32*)(copyB+0x30)) = copyB_30;
        }
        (*(s32*)(copyB+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
        {
            s32 copyB_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
            s32 copyB_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
            (*(s32*)(copyB+0x38)) = copyB_38;
            (*(s32*)(copyB+0x3C)) = copyB_3C;
        }
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
        if (((u32)temp_r10_5 != 0x80000000U) && ((u32)((s32) arg0 & 0xFF800000) != 0x81000000U)) {
            var_r9_6 = 0;
        }
        if ((var_r9_6 == 0) && ((u32)((s32) arg0 & 0xF8000000) != 0x90000000U)) {
            var_r8_6 = 0;
        }
        if ((var_r8_6 == 0) && ((u32)temp_r10_5 != 0xC0000000U)) {
            var_r7_6 = 0;
        }
        if ((var_r7_6 == 0) && ((u32)((s32) arg0 & 0xFF800000) != 0xC1000000U)) {
            var_r6_6 = 0;
        }
        if ((var_r6_6 == 0) && ((u32)((s32) arg0 & 0xF8000000) != 0xD0000000U)) {
            var_r5_6 = 0;
        }
        if ((var_r5_6 == 0) && ((u32)((s32) arg0 & 0xFFFFC000) != 0xE0000000U)) {
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
        if (((u32)temp_r10_6 != 0x80000000U) && ((u32)(arg3 & 0xFF800000) != 0x81000000U)) {
            var_r9_7 = 0;
        }
        if ((var_r9_7 == 0) && ((u32)(arg3 & 0xF8000000) != 0x90000000U)) {
            var_r8_7 = 0;
        }
        if ((var_r8_7 == 0) && ((u32)temp_r10_6 != 0xC0000000U)) {
            var_r7_7 = 0;
        }
        if ((var_r7_7 == 0) && ((u32)(arg3 & 0xFF800000) != 0xC1000000U)) {
            var_r6_7 = 0;
        }
        if ((var_r6_7 == 0) && ((u32)(arg3 & 0xF8000000) != 0xD0000000U)) {
            var_r5_7 = 0;
        }
        if ((var_r5_7 == 0) && ((u32)(arg3 & 0xFFFFC000) != 0xE0000000U)) {
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
        {
            s32 copyC_28 = (*(s32 *)((u8*)(arg0) + (0x28)));
            s32 copyC_24 = (*(s32 *)((u8*)(arg0) + (0x24)));
            (*(s32*)(copyC+0x24)) = copyC_24;
            (*(s32*)(copyC+0x28)) = copyC_28;
        }
        {
            s32 copyC_30 = (*(s32 *)((u8*)(arg0) + (0x30)));
            s32 copyC_2C = (*(s32 *)((u8*)(arg0) + (0x2C)));
            (*(s32*)(copyC+0x2C)) = copyC_2C;
            (*(s32*)(copyC+0x30)) = copyC_30;
        }
        (*(s32*)(copyC+0x34)) = (*(s32 *)((u8*)(arg0) + (0x34)));
        {
            s32 copyC_3C = (*(s32 *)((u8*)(arg0) + (0x3C)));
            s32 copyC_38 = (*(s32 *)((u8*)(arg0) + (0x38)));
            (*(s32*)(copyC+0x38)) = copyC_38;
            (*(s32*)(copyC+0x3C)) = copyC_3C;
        }
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

// Panic strings of nw4hbm's ut_TextWriterBase.cpp (the TextWriter copy this unit holds).
#define UT_TEXTWRITERBASE_CPP lbl_80329560 /* "ut_TextWriterBase.cpp" */
#define UT_TEXTWRITERBASE_PTR_ERROR lbl_80329578 /* "NW4HBM:Pointer Error\nthis(=%p) is not valid pointer." */
// NW4HBM_ASSERT_VALID_PTR(this) as expanded in ut_TextWriterBase.cpp: nw4hbm::db::Panic
// unless the pointer lies in one of the Wii's mapped windows (MEM1, MEM2, IO, ...).
#define TWB_CHECK_THIS(self, line) \
    { \
        unsigned int twb_addr = (unsigned int)(self); \
        int twb_r4 = 1, twb_r5 = 1, twb_r6 = 1, twb_r7 = 1, twb_r8 = 1, twb_r9 = 1; \
        unsigned int twb_top = twb_addr & 0xFF000000U; \
        if (twb_top != 0x80000000U && (twb_addr & 0xFF800000U) != 0x81000000U) twb_r9 = 0; \
        if (twb_r9 == 0 && (twb_addr & 0xF8000000U) != 0x90000000U) twb_r8 = 0; \
        if (twb_r8 == 0 && twb_top != 0xC0000000U) twb_r7 = 0; \
        if (twb_r7 == 0 && (twb_addr & 0xFF800000U) != 0xC1000000U) twb_r6 = 0; \
        if (twb_r6 == 0 && (twb_addr & 0xF8000000U) != 0xD0000000U) twb_r5 = 0; \
        if (twb_r5 == 0 && (twb_addr & 0xFFFFC000U) != 0xE0000000U) twb_r4 = 0; \
        if (twb_r4 == 0) Panic__Q26nw4hbm2dbFPCciPCce(UT_TEXTWRITERBASE_CPP, line, UT_TEXTWRITERBASE_PTR_ERROR, self); \
    }

/* The ut_TextWriterBase.cpp copy of nw4hbm::ut::CharWriter's print position block: +0x4C
 * is the space its print code adds to a measured line width after every glyph (and the
 * amount MoveCursorX advances the cursor by), +0x50 the cursor X that
 * SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111D88 stores; the constructor fn_80111B64
 * clears both.  The game's symbol table names the accessors of +0x4C SetCursorX and
 * GetScaleH -- names the other copies of this class in the game use for their own fields. */
struct CharWriterSpacing {
    unsigned char pad[0x4C];
    float charSpace;
};

/* nw4hbm::ut::CharWriter::SetCursorX(f32) (ut_TextWriterBase.cpp): put the
   writer's cursor at this absolute X. The writer pointer is first checked
   against the Wii's memory windows; one outside them panics. */
extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111D88(nw4hbm::ut::CharWriter *writer, float x) {
    /* One flag per window, all six believed at first; declared high to low,
       which is the order the checks below clear them in reversed. */
    int inIO = 1;           /* 0xE0000000-0xE0003FFF, the IO window */
    int inD0 = 1;           /* ... or 0xD0000000-0xD7FFFFFF */
    int inC1 = 1;           /* ... or 0xC1000000-0xC17FFFFF */
    int inC0 = 1;           /* ... or 0xC0000000-0xC0FFFFFF */
    int inMem2 = 1;         /* ... or 0x90000000-0x97FFFFFF, MEM2 */
    int inMem1 = 1;         /* ... or 0x80000000-0x80FFFFFF / 0x81000000-0x817FFFFF, MEM1 */
    unsigned int top = (unsigned int)writer & 0xFF000000U;
    if (top != 0x80000000U && (((unsigned int)writer & 0xFF800000U) != 0x81000000U)) inMem1 = 0;
    if (inMem1 == 0 && (((unsigned int)writer & 0xF8000000U) != 0x90000000U)) inMem2 = 0;
    if (inMem2 == 0 && top != 0xC0000000U) inC0 = 0;
    if (inC0 == 0 && (((unsigned int)writer & 0xFF800000U) != 0xC1000000U)) inC1 = 0;
    if (inC1 == 0 && (((unsigned int)writer & 0xF8000000U) != 0xD0000000U)) inD0 = 0;
    if (inD0 == 0 && (((unsigned int)writer & 0xFFFFC000U) != 0xE0000000U)) inIO = 0;
    if (inIO == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80329560, 0x105, lbl_80329578, writer);
    writer->cursorX = x;
}

/* nw4hbm::ut::CharWriter::SetCursorX(f32) of the ut_TextWriterBase.cpp copy of the text
   writer: after the pointer check it stores the writer's own left margin (+0x4C), the
   amount its print code adds to the cursor X -- and to a measured line width -- at every
   line break. The symbol table gives this setter the same name as the cursor-X one above. */
extern "C" void SetCursorX__Q36nw4hbm2ut10CharWriterFf_80111EAC(void *writer, float leftMargin) {
    TWB_CHECK_THIS(writer, 0x116); // NW4HBM_ASSERT_VALID_PTR(this)
    *(float *)((char *)writer + 0x4C) = leftMargin;
}

extern "C" float GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80111FD0(CharWriterSpacing *writer) {
    TWB_CHECK_THIS(writer, 0x138); // NW4HBM_ASSERT_VALID_PTR(this)
    return writer->charSpace;
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

/* Sets the CharWriter's font pointer after validating both writer and font addresses. */
extern "C" void SetFont__Q36nw4hbm2ut10CharWriterFRCQ36nw4hbm2ut4Font_80112200(void* self, const void* font) {
    const char* file = lbl_80329530;
    u32 value = (u32)self;
    int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
    u32 t = value & 0xFF000000U;
    if (t != 0x80000000U && (value & 0xFF800000U) != 0x81000000U) f = 0;
    if (f == 0 && (value & 0xF8000000U) != 0x90000000U) e = 0;
    if (e == 0 && t != 0xC0000000U) d = 0;
    if (d == 0 && (value & 0xFF800000U) != 0xC1000000U) c = 0;
    if (c == 0 && (value & 0xF8000000U) != 0xD0000000U) b = 0;
    if (b == 0 && (value & 0xFFFFC000U) != 0xE0000000U) a = 0;
    if (a == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x72, file + 0x48, self);
    u32 v = (u32)font;
    int g = 1, h = 1, i = 1, j = 1, k = 1, l = 1;
    u32 t2 = v & 0xFF000000U;
    if (t2 != 0x80000000U && (v & 0xFF800000U) != 0x81000000U) l = 0;
    if (l == 0 && (v & 0xF8000000U) != 0x90000000U) k = 0;
    if (k == 0 && t2 != 0xC0000000U) j = 0;
    if (j == 0 && (v & 0xFF800000U) != 0xC1000000U) i = 0;
    if (i == 0 && (v & 0xF8000000U) != 0xD0000000U) h = 0;
    if (h == 0 && (v & 0xFFFFC000U) != 0xE0000000U) g = 0;
    if (g == 0) Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x73, file + 0x80, font);
    *(const void**)((char*)self + 0x5c) = font;
}

/* Returns the CharWriter's font pointer (nw4hbm::ut::CharWriter::GetFont const). */
extern "C" void *GetFont__Q36nw4hbm2ut10CharWriterCFv_80112410(void *writer) {
    TWB_CHECK_THIS(writer, 0x97);
    return *(void **)((char *)writer + 0x5C);
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

#pragma push
#pragma use_lmw_stmw off
extern "C" f32 fn_80112960(u8 *arg0, u8 *arg1) {
    extern s32 fn_8002AEE8(s32);
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
    register s32 r5 = 1;
    register s32 r6 = 1;
    register s32 r7 = 1;
    register s32 r8 = 1;
    register s32 r9 = 1;
    register s32 r10 = 1;
    register u32 hi0 = (u32)arg0 & 0xFF000000U;
    if ((hi0 != 0x80000000U) &&
        (((u32)arg0 & 0xFF800000U) != 0x81000000U)) {
        r10 = 0;
    }
    if ((r10 == 0) && (((u32)arg0 & 0xF8000000U) != 0x90000000U)) {
        r9 = 0;
    }
    if ((r9 == 0) && (hi0 != 0xC0000000U)) {
        r8 = 0;
    }
    if ((r8 == 0) && (((u32)arg0 & 0xFF800000U) != 0xC1000000U)) {
        r7 = 0;
    }
    if ((r7 == 0) && (((u32)arg0 & 0xF8000000U) != 0xD0000000U)) {
        r6 = 0;
    }
    if ((r6 == 0) && (((u32)arg0 & 0xFFFFC000U) != 0xE0000000U)) {
        r5 = 0;
    }
    if (r5 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2DD, file + 0x48, arg0);
    }

    register s32 r4 = 1;
    register s32 r5_2 = 1;
    register s32 r6_2 = 1;
    register s32 r7_2 = 1;
    register s32 r8_2 = 1;
    register s32 r9_2 = 1;
    register u32 hi1 = (u32)arg1 & 0xFF000000U;
    if ((hi1 != 0x80000000U) &&
        (((u32)arg1 & 0xFF800000U) != 0x81000000U)) {
        r9_2 = 0;
    }
    if ((r9_2 == 0) && (((u32)arg1 & 0xF8000000U) != 0x90000000U)) {
        r8_2 = 0;
    }
    if ((r8_2 == 0) && (hi1 != 0xC0000000U)) {
        r7_2 = 0;
    }
    if ((r7_2 == 0) && (((u32)arg1 & 0xFF800000U) != 0xC1000000U)) {
        r6_2 = 0;
    }
    if ((r6_2 == 0) && (((u32)arg1 & 0xF8000000U) != 0xD0000000U)) {
        r5_2 = 0;
    }
    if ((r5_2 == 0) && (((u32)arg1 & 0xFFFFC000U) != 0xE0000000U)) {
        r4 = 0;
    }
    if (r4 == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2DE, file + 0x130, arg1);
    }
    const s32 arg2 = fn_8002AEE8((s32)arg1);
    int valid0 = !((((u32)arg0 & 0xff000000U) != 0x80000000U) &&
        (((u32)arg0 & 0xff800000U) != 0x81000000U) &&
        (((u32)arg0 & 0xf8000000U) != 0x90000000U) &&
        (((u32)arg0 & 0xff000000U) != 0xc0000000U) &&
        (((u32)arg0 & 0xff800000U) != 0xc1000000U) &&
        (((u32)arg0 & 0xf8000000U) != 0xd0000000U) &&
        (((u32)arg0 & 0xffffc000U) != 0xe0000000U));
    if (!valid0)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2c1, file + 0x48, arg0);
    int valid1 = !((((u32)arg1 & 0xff000000U) != 0x80000000U) &&
        (((u32)arg1 & 0xff800000U) != 0x81000000U) &&
        (((u32)arg1 & 0xf8000000U) != 0x90000000U) &&
        (((u32)arg1 & 0xff000000U) != 0xc0000000U) &&
        (((u32)arg1 & 0xff800000U) != 0xc1000000U) &&
        (((u32)arg1 & 0xf8000000U) != 0xd0000000U) &&
        (((u32)arg1 & 0xffffc000U) != 0xe0000000U));
    if (!valid1)
        Panic__Q26nw4hbm2dbFPCciPCce(file + 0x30, 0x2c2, file + 0x130, arg1);
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
    f32 scale, result;
    result = fn_801142F8(&copy, (s32)arg1, arg2);
    scale = GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106770((s32)&copy);
    SetCursor__Q36nw4hbm2ut10CharWriterFff((s32)arg0,
        GetScaleH__Q36nw4hbm2ut10CharWriterCFv_80106658((s32)&copy), scale);
    fn_801033F0(&copy, 0);
    return result;
}
#pragma pop
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
    if (((u32)temp_r11 != 0x80000000U) &&
        ((arg0 & 0xFF800000U) != 0x81000000U)) var_r10 = 0;
    if ((var_r10 == 0) && ((arg0 & 0xF8000000U) != 0x90000000U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)temp_r11 != 0xC0000000U)) var_r8 = 0;
    if ((var_r8 == 0) && ((arg0 & 0xFF800000U) != 0xC1000000U)) var_r7 = 0;
    if ((var_r7 == 0) && ((arg0 & 0xF8000000U) != 0xD0000000U)) var_r6 = 0;
    if ((var_r6 == 0) && ((arg0 & 0xFFFFC000U) != 0xE0000000U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F2, base + 0x48, arg0);
    temp_r10 = arg1 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r4 = 1;
    if (((u32)temp_r10 != 0x80000000U) &&
        ((arg1 & 0xFF800000U) != 0x81000000U)) var_r4 = 0;
    if ((var_r4 == 0) && ((arg1 & 0xF8000000U) != 0x90000000U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)temp_r10 != 0xC0000000U)) var_r8 = 0;
    if ((var_r8 == 0) && ((arg1 & 0xFF800000U) != 0xC1000000U)) var_r7 = 0;
    if ((var_r7 == 0) && ((arg1 & 0xF8000000U) != 0xD0000000U)) var_r6 = 0;
    if ((var_r6 == 0) && ((arg1 & 0xFFFFC000U) != 0xE0000000U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F3, base + 0xF8, arg1);
    temp_r10_2 = var_r29 & 0xFF000000;
    var_r5 = 1;
    var_r6 = 1;
    var_r7 = 1;
    var_r8 = 1;
    var_r9 = 1;
    var_r4 = 1;
    if (((u32)temp_r10_2 != 0x80000000U) &&
        ((var_r29 & 0xFF800000U) != 0x81000000U)) var_r4 = 0;
    if ((var_r4 == 0) && ((var_r29 & 0xF8000000U) != 0x90000000U)) var_r9 = 0;
    if ((var_r9 == 0) && ((u32)temp_r10_2 != 0xC0000000U)) var_r8 = 0;
    if ((var_r8 == 0) && ((var_r29 & 0xFF800000U) != 0xC1000000U)) var_r7 = 0;
    if ((var_r7 == 0) && ((var_r29 & 0xF8000000U) != 0xD0000000U)) var_r6 = 0;
    if ((var_r6 == 0) && ((var_r29 & 0xFFFFC000U) != 0xE0000000U)) var_r5 = 0;
    if (var_r5 == 0) Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F4, base + 0x130, var_r29);
    if (var_r30 < 0)
        Panic__Q26nw4hbm2dbFPCciPCce(base + 0x30, 0x3F5, base + 0x168, var_r30, 0);
    register f32 zero = 0.0f;
    rect[0] = zero;
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
