// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned char u8;
s32 fn_80128670(s32);
s32 fn_80131818(s32);
s32 fn_802E317C(const char *, ...);
extern void* fn_8012850C(s32, const char*);
extern void* fn_80131808(const char*);
extern int fn_801345D8(char*, int, const char*, ...);
extern void* memset(void*, int, unsigned long);
extern char lbl_802FD1B0[];
extern const char lbl_80558C28[4];
typedef unsigned int u32;
#pragma cplusplus on
struct Item_8001880C {
    virtual const char* getName();
    virtual int hasKey(const char*);
    virtual void slot2();
    virtual int getA(const char*);
    virtual void slot4();
    virtual int getB(const char*);
};
struct Dir_8001880C {
    virtual void slot0();
    virtual Item_8001880C* getAt(int);
};
#pragma cplusplus reset
int stricmp(const char *, const char *);
extern u8 lbl_8055D570;
extern s32 lbl_8055D574;
extern s32 lbl_8055D578;
extern s32 lbl_8055D57C;
extern const char lbl_802FD270[];
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8001880C(void) {
    char buf1[0x14];
    char buf2[0x14];
    char* base = lbl_802FD1B0;
    Item_8001880C* item;
    int idx;
    int count;
    int off;
    int* rec;
    int* p;
    u32 n;

    lbl_8055D570 = 1;
    lbl_8055D574 = (s32)fn_80131808(base);
    idx = 0;
    lbl_8055D57C = 0;
    while ((item = ((Dir_8001880C*)lbl_8055D574)->getAt(idx)) != 0) {
        if (stricmp(item->getName(), base + 0x10) == 0 && item->hasKey(lbl_80558C28) != 0) {
            lbl_8055D57C++;
        }
        idx++;
    }
    lbl_8055D578 = (s32)fn_8012850C(lbl_8055D57C * 0x2C, base + 0x1C);
    off = 0;
    count = 0;
    while ((item = ((Dir_8001880C*)lbl_8055D574)->getAt(count)) != 0) {
        if (stricmp(item->getName(), base + 0x10) == 0 && item->hasKey(lbl_80558C28) != 0) {
            rec = (int*)(lbl_8055D578 + off);
            off += 0x2C;
            memset(rec, 0, 0x2C);
            rec[0] = item->getA(lbl_80558C28);
            p = rec;
            n = 0;
            while (1) {
                fn_801345D8(buf1, 0x14, base + 0x28, n + 1);
                fn_801345D8(buf2, 0x14, base + 0x38, n + 1);
                if (item->hasKey(buf1) == 0 || item->hasKey(buf2) == 0) break;
                if (n >= 5) fn_802E317C(base + 0x48, rec[0], 5);
                p[1] = item->getA(buf1);
                *(p += 2) = item->getB(buf2);
                n++;
            }
            if (n == 0) fn_802E317C(base + 0x7C, rec[0]);
        }
        count++;
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
s32 fn_80018A8C(const char *arg0) {
    s32 offset = 0;
    s32 i = 0;
    while (i < lbl_8055D57C) {
        if (stricmp(*(char **)((char *)lbl_8055D578 + offset), arg0) == 0)
            return (s32)((char *)lbl_8055D578 + i * 0x2C);
        offset += 0x2C;
        i++;
    }
    fn_802E317C(lbl_802FD270, arg0);
    return 0;
}
#pragma pop

#pragma cplusplus reset

void fn_80018B24(void) {
    lbl_8055D570 = 0;
    fn_80128670(lbl_8055D578);
    lbl_8055D578 = 0;
    lbl_8055D57C = 0;
    fn_80131818(lbl_8055D574);
}
