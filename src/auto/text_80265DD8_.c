// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F488;
extern float lbl_8055F484;
extern float lbl_80499980[8];
extern float lbl_80563C6C;
extern float lbl_80563C20;
void fn_802693F4(void);
extern void fn_80265E08(void*);
extern float lbl_80563C24;
extern float lbl_8055C4E0;
extern float lbl_8055C4E4;
extern int lbl_8055C4E8;
extern int lbl_8055C4EC;
extern int lbl_804999A0[];
extern float fn_80129DC4(int, float, float);
extern int fn_80129D90(int, int, int);
extern float PSVECMag(void*);
void* fn_80265DD8(void* arg0) {
    fn_80265E08(arg0);
    return arg0;
}

void fn_80266070(void* arg0, void* arg1, void* arg2, void* arg3) {
    float scale = *(float*)((char*)arg0 + 0x10);
    float x = *(float*)((char*)arg3 + 0) * scale;
    float y = *(float*)((char*)arg3 + 4) * scale;
    float z = *(float*)((char*)arg3 + 8) * scale;
    float mag;
    float f;
    float* out = arg1;
    float* base = arg2;
    *(float*)((char*)0 + 0); 
    mag = PSVECMag(arg3);
    f = *(float*)((char*)arg0 + 0x14) * mag;
    out[0] = base[0] + x;
    out[1] = base[1] + (y + f);
    out[2] = base[2] + z;
}

char fn_8026A38C(void) {
    return lbl_8055F488;
}

extern float lbl_8055F484;
extern float lbl_80563C6C;
extern float lbl_80499980[8];
extern float lbl_80563C20;
void fn_802693F4(void);
void fn_8026A51C(void) {
    fn_802693F4();
}

float fn_8026A520(int arg0) {
    if (arg0 >= 0 && (unsigned int)arg0 < 8U) {
        return lbl_80499980[arg0];
    }
    return lbl_80563C20;
}

void fn_8026A54C(float arg0) {
    lbl_8055F484 = arg0;
}

int fn_8026A554(int *arg0) {
    int index = *arg0;
    if (index >= 0 && (unsigned int)index < 8U) {
        lbl_80499980[index] = lbl_80563C6C;
    }
    return 4;
}

