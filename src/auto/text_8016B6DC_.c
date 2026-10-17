// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
} InitObj;
extern InitObj lbl_804302E0[];
extern __declspec(section ".sdata") char lbl_8055E358[];
extern __declspec(section ".sdata") int lbl_8055E360;
void fn_8000D838(char *);
void fn_8016B79C(void);
void fn_8016B834(void);
void fn_8016B8CC(void);
void __register_global_object(InitObj *, void (*)(void), InitObj *);
