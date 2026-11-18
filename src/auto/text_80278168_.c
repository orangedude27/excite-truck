// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(const char *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80278210(void);
extern void fn_8027820C(void);
extern void fn_8026A600(void);
extern void fn_80144DC8(void);
extern char lbl_8049FD58[];
__declspec(section ".sdata") extern char lbl_8055F590[];

typedef struct {
    unsigned char b0;
    unsigned char pad0[0x187];
    unsigned char b188;
    unsigned char pad1[0xD7F];
    unsigned char bF08;
    unsigned char pad2[0x89F];
    unsigned char b17A8;
} Blob8049FD58;

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80278168(void) {
    char *base = lbl_8049FD58;
    fn_8000D838(lbl_8055F590);
    fn_8002F53C(&base[0], fn_80278210, 0, 0x50, 4);
    fn_8002F53C(&base[0x188], fn_8027820C, 0, 0x48, 0x30);
    fn_8002F53C(&base[0xF08], fn_8026A600, 0, 0x228, 4);
    fn_8002F53C(&base[0x17A8], fn_80144DC8, 0, 0x30, 4);
}
