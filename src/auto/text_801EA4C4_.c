// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned char u8;
typedef float f32;

/* CarMgr keeps its per-level car table in a heap block tagged "CarMgr::info"
   (lbl_8055EB78, 0x608 bytes, fn_801EA4C4): eight CarMgrEntry records and then
   the counts and the slot table at 0x5E0.  The car type stored at +0x44 is one
   of the five values CarTypeIsReal (fn_802794AC) knows about; they spell 'P'
   to 'T'. */
enum CarType {
    CAR_TYPE_P = 0x50, /* a real car */
    CAR_TYPE_Q = 0x51, /* a real car */
    CAR_TYPE_R = 0x52, /* real only while fn_80265D7C agrees */
    CAR_TYPE_S = 0x53, /* real while bit 0 of the car info's +0x10 is set */
    CAR_TYPE_T = 0x54  /* never a real car */
};

/* One car of the table.  fn_801EA59C installs a car from its definition (the
   word at +0x00 of it is the CarType, the 0x74 bytes after it are copied in
   whole), fn_801EA9DC refreshes 0x0C-0x40 from the live object every frame. */
struct CarMgrEntry {
    u8 active;                /* 0x00 whether this car is in play at all */
    u8 pad1[3];
    s32 index;                /* 0x04 this record's number in the table */
    s32 unk08;                /* 0x08 fn_801EAB10 writes it */
    char live[0x44 - 0x0C];   /* 0x0C state refreshed by fn_801EA9DC */
    s32 carType;              /* 0x44 one of enum CarType */
    char definition[0xBC - 0x48]; /* 0x48 the car definition copied in */
};                            /* 0xBC */

/* The table's header, sitting right after the eight records. */
struct CarMgrTail {
    s32 entryCount; /* 0x5E0 highest record used + 1 */
    s32 realCount;  /* 0x5E4 highest record whose car type is real, + 1 */
    s32 slots[8];   /* 0x5E8 slot -> record; fn_801EA4C4 seeds it with 0..7 */
};                  /* 0x5E0, 0x28 bytes; the block ends at 0x608 */

extern s32 lbl_8055EB78;
extern s32 lbl_8055EB7C;
extern char lbl_80339E08[];
extern s32 fn_80265D7C(void);
extern void fn_80128668(s32);
extern void *fn_801284F8(s32, void *);
extern unsigned int memset(void *, int, unsigned int);
#pragma scheduling invalid_target
/* Initialize the car manager info block (0x608 bytes tagged "CarMgr::info") and seed its trailing slot table with indices 0..7. */
void fn_801EA4C4(void) {
    void *carInfoBlock;
    lbl_8055EB7C = 1;
    carInfoBlock = fn_801284F8(0x608, lbl_80339E08);
    lbl_8055EB78 = (s32)carInfoBlock;
    memset(carInfoBlock, 0, 0x608);
    *(s32 *)(lbl_8055EB78 + 0x5E8) = 0;
    *(s32 *)(lbl_8055EB78 + 0x5EC) = 1;
    *(s32 *)(lbl_8055EB78 + 0x5F0) = 2;
    *(s32 *)(lbl_8055EB78 + 0x5F4) = 3;
    *(s32 *)(lbl_8055EB78 + 0x5F8) = 4;
    *(s32 *)(lbl_8055EB78 + 0x5FC) = 5;
    *(s32 *)(lbl_8055EB78 + 0x600) = 6;
    *(s32 *)(lbl_8055EB78 + 0x604) = 7;
}
#pragma scheduling on
void fn_801EA56C(void) {
    fn_80128668(*(s32 *)&lbl_8055EB78);
    lbl_8055EB78 = 0;
    lbl_8055EB7C = 0;
}

void fn_801EA59C(s32 arg0, s32 arg1, void *arg2) {
    u8 *entry;
    s32 version;
    s32 allow;
    u8 active;
    entry = (u8 *)(*(s32 *)&lbl_8055EB78 + arg0 * 0xBC);
    version = *(s32 *)arg2;
    *(s32 *)(entry + 0x44) = version;
    entry[0x48] = ((u8 *)arg2)[0x4];
    entry[0x49] = ((u8 *)arg2)[0x5];
    entry[0x4a] = ((u8 *)arg2)[0x6];
    entry[0x4b] = ((u8 *)arg2)[0x7];
    entry[0x4c] = ((u8 *)arg2)[0x8];
    entry[0x4d] = ((u8 *)arg2)[0x9];
    entry[0x4e] = ((u8 *)arg2)[0xa];
    entry[0x4f] = ((u8 *)arg2)[0xb];
    entry[0x50] = ((u8 *)arg2)[0xc];
    entry[0x51] = ((u8 *)arg2)[0xd];
    entry[0x52] = ((u8 *)arg2)[0xe];
    entry[0x53] = ((u8 *)arg2)[0xf];
    entry[0x54] = ((u8 *)arg2)[0x10];
    entry[0x55] = ((u8 *)arg2)[0x11];
    entry[0x56] = ((u8 *)arg2)[0x12];
    entry[0x57] = ((u8 *)arg2)[0x13];
    entry[0x58] = ((u8 *)arg2)[0x14];
    entry[0x59] = ((u8 *)arg2)[0x15];
    entry[0x5a] = ((u8 *)arg2)[0x16];
    entry[0x5b] = ((u8 *)arg2)[0x17];
    entry[0x5c] = ((u8 *)arg2)[0x18];
    entry[0x5d] = ((u8 *)arg2)[0x19];
    entry[0x5e] = ((u8 *)arg2)[0x1a];
    entry[0x5f] = ((u8 *)arg2)[0x1b];
    entry[0x60] = ((u8 *)arg2)[0x1c];
    entry[0x61] = ((u8 *)arg2)[0x1d];
    entry[0x62] = ((u8 *)arg2)[0x1e];
    entry[0x63] = ((u8 *)arg2)[0x1f];
    entry[0x64] = ((u8 *)arg2)[0x20];
    entry[0x65] = ((u8 *)arg2)[0x21];
    entry[0x66] = ((u8 *)arg2)[0x22];
    entry[0x67] = ((u8 *)arg2)[0x23];
    entry[0x68] = ((u8 *)arg2)[0x24];
    entry[0x69] = ((u8 *)arg2)[0x25];
    entry[0x6a] = ((u8 *)arg2)[0x26];
    entry[0x6b] = ((u8 *)arg2)[0x27];
    entry[0x6c] = ((u8 *)arg2)[0x28];
    entry[0x6d] = ((u8 *)arg2)[0x29];
    entry[0x6e] = ((u8 *)arg2)[0x2a];
    entry[0x6f] = ((u8 *)arg2)[0x2b];
    entry[0x70] = ((u8 *)arg2)[0x2c];
    entry[0x71] = ((u8 *)arg2)[0x2d];
    entry[0x72] = ((u8 *)arg2)[0x2e];
    entry[0x73] = ((u8 *)arg2)[0x2f];
    entry[0x74] = ((u8 *)arg2)[0x30];
    entry[0x75] = ((u8 *)arg2)[0x31];
    entry[0x76] = ((u8 *)arg2)[0x32];
    entry[0x77] = ((u8 *)arg2)[0x33];
    entry[0x78] = ((u8 *)arg2)[0x34];
    entry[0x79] = ((u8 *)arg2)[0x35];
    entry[0x7a] = ((u8 *)arg2)[0x36];
    entry[0x7b] = ((u8 *)arg2)[0x37];
    entry[0x7c] = ((u8 *)arg2)[0x38];
    entry[0x7d] = ((u8 *)arg2)[0x39];
    entry[0x7e] = ((u8 *)arg2)[0x3a];
    entry[0x7f] = ((u8 *)arg2)[0x3b];
    entry[0x80] = ((u8 *)arg2)[0x3c];
    entry[0x81] = ((u8 *)arg2)[0x3d];
    entry[0x82] = ((u8 *)arg2)[0x3e];
    entry[0x83] = ((u8 *)arg2)[0x3f];
    entry[0x84] = ((u8 *)arg2)[0x40];
    entry[0x85] = ((u8 *)arg2)[0x41];
    entry[0x86] = ((u8 *)arg2)[0x42];
    entry[0x87] = ((u8 *)arg2)[0x43];
    entry[0x88] = ((u8 *)arg2)[0x44];
    entry[0x89] = ((u8 *)arg2)[0x45];
    entry[0x8a] = ((u8 *)arg2)[0x46];
    entry[0x8b] = ((u8 *)arg2)[0x47];
    entry[0x8c] = ((u8 *)arg2)[0x48];
    entry[0x8d] = ((u8 *)arg2)[0x49];
    entry[0x8e] = ((u8 *)arg2)[0x4a];
    entry[0x8f] = ((u8 *)arg2)[0x4b];
    entry[0x90] = ((u8 *)arg2)[0x4c];
    entry[0x91] = ((u8 *)arg2)[0x4d];
    entry[0x92] = ((u8 *)arg2)[0x4e];
    entry[0x93] = ((u8 *)arg2)[0x4f];
    entry[0x94] = ((u8 *)arg2)[0x50];
    entry[0x95] = ((u8 *)arg2)[0x51];
    entry[0x96] = ((u8 *)arg2)[0x52];
    entry[0x97] = ((u8 *)arg2)[0x53];
    entry[0x98] = ((u8 *)arg2)[0x54];
    entry[0x99] = ((u8 *)arg2)[0x55];
    entry[0x9a] = ((u8 *)arg2)[0x56];
    entry[0x9b] = ((u8 *)arg2)[0x57];
    entry[0x9c] = ((u8 *)arg2)[0x58];
    entry[0x9d] = ((u8 *)arg2)[0x59];
    entry[0x9e] = ((u8 *)arg2)[0x5a];
    entry[0x9f] = ((u8 *)arg2)[0x5b];
    entry[0xa0] = ((u8 *)arg2)[0x5c];
    entry[0xa1] = ((u8 *)arg2)[0x5d];
    entry[0xa2] = ((u8 *)arg2)[0x5e];
    entry[0xa3] = ((u8 *)arg2)[0x5f];
    entry[0xa4] = ((u8 *)arg2)[0x60];
    entry[0xa5] = ((u8 *)arg2)[0x61];
    entry[0xa6] = ((u8 *)arg2)[0x62];
    entry[0xa7] = ((u8 *)arg2)[0x63];
    *(s32 *)(entry + 0xa8) = *(s32 *)((u8 *)arg2 + 0x64);
    *(s32 *)(entry + 0xac) = *(s32 *)((u8 *)arg2 + 0x68);
    *(s32 *)(entry + 0xb0) = *(s32 *)((u8 *)arg2 + 0x6c);
    entry[0xB4] = ((u8 *)arg2)[0x70];
    *(s32 *)(entry + 0xB8) = *(s32 *)((u8 *)arg2 + 0x74);
    active = 1;
    if (version != 0x50) {
        allow = 0;
        if (version == 0x52 && fn_80265D7C() != 0) allow = 1;
        if (allow == 0) active = 0;
    }
    entry[0] = active;
    *(s32 *)(entry + 8) = arg1;
    *(s32 *)(entry + 4) = arg0;
    if (arg0 >= *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E0)) *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E0) = arg0 + 1;
    if (fn_802794AC(*(s32 *)arg2, 0) != 0 && arg0 >= *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E4)) *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E4) = arg0 + 1;
}

s32 fn_801EA994(void) {
    return *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E4);
}

s32 fn_801EA9A0(s32 arg0) {
    return lbl_8055EB78 + (arg0 * 0xBC);
}

s32 fn_801EA9B0(s32 arg0) {
    return *(s32 *)&lbl_8055EB78 + (*(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + (arg0 << 2) + 0x5E8) * 0xBC);
}

s32 fn_801EA9CC(s32 arg0) {
    return lbl_8055EB78 + (arg0 * 0xBC);
}

#pragma scheduling invalid_target
void fn_801EA9DC(s32 arg0, void *arg1) {
    u8 *entry;
    s32 value0;
    s32 value;
    s32 index;
    s32 word;
    u8 byte;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    value0 = *(volatile s32 *)arg1;
    value = *(volatile s32 *)((u8 *)arg1 + 4);
    entry = (u8 *)*(s32 *)&lbl_8055EB78 + arg0 * 0xBC;
    *(s32 *)(entry + 0x0C) = value0;
    index = value - 1;
    word = *(volatile s32 *)((u8 *)arg1 + 8);
    *(s32 *)(entry + 0x10) = value;
    f0 = *(volatile f32 *)((u8 *)arg1 + 0x0C);
    *(s32 *)(entry + 0x14) = word;
    word = *(volatile s32 *)((u8 *)arg1 + 0x10);
    *(f32 *)(entry + 0x18) = f0;
    f1 = *(volatile f32 *)((u8 *)arg1 + 0x14);
    *(s32 *)(entry + 0x1C) = word;
    f2 = *(volatile f32 *)((u8 *)arg1 + 0x18);
    *(f32 *)(entry + 0x20) = f1;
    f3 = *(volatile f32 *)((u8 *)arg1 + 0x1C);
    *(f32 *)(entry + 0x24) = f2;
    f4 = *(volatile f32 *)((u8 *)arg1 + 0x20);
    *(f32 *)(entry + 0x28) = f3;
    word = *(volatile s32 *)((u8 *)arg1 + 0x24);
    *(f32 *)(entry + 0x2C) = f4;
    byte = *(volatile u8 *)((u8 *)arg1 + 0x28);
    *(s32 *)(entry + 0x30) = word;
    f5 = *(volatile f32 *)((u8 *)arg1 + 0x2C);
    *(u8 *)(entry + 0x34) = byte;
    word = *(volatile s32 *)((u8 *)arg1 + 0x30);
    *(f32 *)(entry + 0x38) = f5;
    value0 = *(volatile s32 *)((u8 *)arg1 + 0x34);
    *(s32 *)(entry + 0x3C) = word;
    *(s32 *)(entry + 0x40) = value0;
    if (index < 0) index = *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E0) - 1;
    value = *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E0) - 1;
    if (value < index) index = value;
    *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + (index << 2) + 0x5E8) = arg0;
}
#pragma scheduling on
/* CarMgr::info: give record `index` the car type `carType` and say whether that
   type puts the car in play at all.  A 'P' car is always in play; an 'R' car
   only while fn_80265D7C agrees (it is a stub that always says no in this
   build, and takes the record's index); any other type leaves the record
   inactive.  fn_801EA59C does the same for a whole car definition. */
void fn_801EAA94(s32 index, s32 carType) {
    u8 active;
    s32 allowed;
    struct CarMgrEntry *entry;
    active = 1;
    entry = (struct CarMgrEntry *)(lbl_8055EB78 + index * sizeof(struct CarMgrEntry));
    entry->carType = carType;
    if (carType != CAR_TYPE_P) {
        allowed = 0;
        if (carType == CAR_TYPE_R && ((s32 (*)(s32))fn_80265D7C)(index) != 0) allowed = 1;
        if (allowed == 0) active = 0;
    }
    entry->active = active;
}

void fn_801EAB10(s32 arg0, s32 arg1) {
    *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78 + arg0 * 0xBC) + 8) = arg1;
}

