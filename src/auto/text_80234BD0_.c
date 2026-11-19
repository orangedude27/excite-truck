// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    void *next;
    unsigned int unk4;
    unsigned int unk8;
} StaticObj;
typedef struct { unsigned int field0; } Head;
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
    register unsigned int *base asm("r29") = (unsigned int *)lbl_80497F08;
    StaticObj *obj;
    fn_8000D838(lbl_8055F038);
    obj = (StaticObj *)(base + 3);
    obj->next = (char *)obj + 0xC;
    lbl_8055F040 = 0x100;
    lbl_8055F042 = 0x405;
    lbl_8055F044 = 0x401;
    lbl_8055F048 = 0x7F000000;
    lbl_8055F04C = 0xFF000000;
    obj->unk8 = 0x30;
    obj->unk4 = 0;
    __register_global_object(obj, fn_80234CEC, base);
    obj = (StaticObj *)(base + 0x159);
    obj->unk4 = 0;
    obj->next = (char *)obj + 0xC;
    obj->unk8 = 0x10;
    __register_global_object(obj, fn_80234C94, base + 0x156);
    lbl_8055F060 = 0xFF000000;
}
#pragma scheduling on
