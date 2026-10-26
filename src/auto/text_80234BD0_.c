// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    void *next;
    unsigned int unk4;
    unsigned int unk8;
} StaticObj;
extern char lbl_80497F08[];
extern __declspec(section ".sdata") char lbl_8055F038[];
extern __declspec(section ".sdata") unsigned short lbl_8055F040;
extern __declspec(section ".sdata") unsigned short lbl_8055F042;
extern __declspec(section ".sdata") unsigned short lbl_8055F044;
extern __declspec(section ".sdata") unsigned int lbl_8055F048;
extern __declspec(section ".sdata") unsigned int lbl_8055F04C;
extern __declspec(section ".sdata") unsigned int lbl_8055F060;
void fn_8000D838(char *);
void fn_80234CEC(void);
void fn_80234C94(void);
void __register_global_object(void *, void (*)(void), void *);
#pragma scheduling invalid_target
void fn_80234BD0(void) {
    char *base = lbl_80497F08;
    char *obj;
    fn_8000D838(lbl_8055F038);
    obj = base + 0xC;
    *(void **)(base + 0xC) = obj + 0xC;
    lbl_8055F040 = 0x100;
    lbl_8055F042 = 0x405;
    lbl_8055F044 = 0x401;
    lbl_8055F048 = 0x7F000000;
    lbl_8055F04C = 0xFF000000;
    *(int *)(obj + 8) = 0x30;
    *(int *)(obj + 4) = 0;
    __register_global_object(obj, fn_80234CEC, base);
    obj = base + 0x564;
    *(int *)(obj + 4) = 0;
    *(void **)(base + 0x564) = obj + 0xC;
    *(int *)(obj + 8) = 0x10;
    __register_global_object(obj, fn_80234C94, base + 0x558);
    lbl_8055F060 = 0xFF000000;
}
#pragma scheduling on
