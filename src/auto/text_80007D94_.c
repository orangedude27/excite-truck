// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

typedef struct {
    u8 unk_0x0[0x1E4];
    void* unk_0x1E4;
} Unk8034EF38;

typedef struct {
    u32 unk_0x0;
    const char* unk_0x4;
    const char* unk_0x8;
} Unk802FB70C;

extern Unk8034EF38 lbl_8034EF38;
extern Unk802FB70C lbl_802FB70C[];
extern const char lbl_802FB77C[];
extern const char lbl_80558998[1];
extern const char lbl_805589A0[1];
void fn_80007DA0(void);
void fn_80279464(void);
void fn_80012778(void);
void fn_80131818(void*);
void fn_802E317C(const char*, ...);

void fn_80007F04(void) {
    Unk8034EF38* p = &lbl_8034EF38;
    fn_80131818(p->unk_0x1E4);
    p->unk_0x1E4 = 0;
}

void fn_80007F40(void) {
    fn_80007DA0();
    fn_80279464();
    fn_80012778();
}

const char* fn_80007F90(u32 arg0) {
    Unk802FB70C* p;
    for (p = lbl_802FB70C; p->unk_0x0 != 0; p++) {
        if (p->unk_0x0 == arg0)
            return p->unk_0x4;
    }
    fn_802E317C(lbl_802FB77C, arg0);
    return lbl_80558998;
}

const char* fn_80007FF0(u32 arg0) {
    Unk802FB70C* p;
    for (p = lbl_802FB70C; p->unk_0x0 != 0; p++) {
        if (p->unk_0x0 == arg0)
            return p->unk_0x8;
    }
    fn_802E317C(lbl_802FB77C, arg0);
    return lbl_805589A0;
}

