// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;
typedef s32 (*UnkFn_80245080)(void);

struct Unk_80245080_Sub {
    u8 pad[0xC];
    UnkFn_80245080 unk_0C;
};

struct Unk_80245080 {
    u8 pad[0x20];
    struct Unk_80245080_Sub* unk_20;
    s32 unk_24;
};

extern struct Unk_80245080* lbl_8055F244;
extern s32 lbl_804988B0;

s32 fn_802E8D7C(s32);
void fn_80236900(void);
