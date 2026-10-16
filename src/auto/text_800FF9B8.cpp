// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
extern "C" u32 lbl_8055DE88;
extern "C" void fn_800FFE94(int);
extern "C" int fn_800FFC5C(int arg0, int arg1) {
    extern void fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" void SetChannelPriority__Q46nw4hbm3snd6detail9WaveSoundFi_800FFC9C(int arg0, int arg1) {
    extern const char lbl_80327500[];
    extern const char lbl_803275A8[];
    extern void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
    extern void SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(int, int);
    int valid = 0;
    if (arg1 >= 0 && arg1 <= 0x7F) valid = 1;
    if (valid == 0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80327500, 0x85, lbl_803275A8, arg1, 0, 0x7F);
    SetChannelPriority__Q46nw4hbm3snd6detail9SeqPlayerFi_80100FA8(arg0 + 0xD8, arg1);
}

extern "C" int fn_800FFE54(void *arg0) {
    return *(int *)((char *)arg0 + 0x1AC) != 0;
}

extern "C" void fn_800FFE68(void *arg0) {
    fn_800FFE94(*(int *)((char *)arg0 + 0x1AC));
}

extern "C" int fn_800FFE70(int arg0) {
    return arg0 + 0xD8;
}

extern "C" int fn_800FFE78(int arg0) { return arg0 + 0xD8; }

extern "C" u32 *fn_800FFE80(void) {
    return &lbl_8055DE88;
}

