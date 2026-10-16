// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_802073A4(void);

extern void *lbl_8055ED88;
extern "C" void fn_80206464(void* hi) {
    lbl_8055ED88 = hi;
}

extern "C" void fn_8020646C(long, long);
extern long lbl_804891E8[];
extern "C" void fn_8020646C(long arg0, long arg1) {
    lbl_804891E8[arg0] = arg1;
}

void fn_80206480(void) {
    return;
}

void fn_802064C8(void) {
    return;
}

extern "C" void fn_80206550(unsigned int size) {
    extern int lbl_8055ED80; extern void* fn_80207C74(int, unsigned int);
    fn_80207C74(lbl_8055ED80, size);
}

extern int lbl_8055ED80;
extern "C" int fn_80207C50(int,int,int);
extern "C" void fn_8020655C(int a, int b) { fn_80207C50(lbl_8055ED80,a,b); }

extern void* fn_80207C74(int, unsigned int);
extern int lbl_802F9DA0;
extern void* fn_80208D4C(void);
extern void fn_80208D70(void);
extern "C" void* fn_80206570(int index) {
    int values[10]; int* p=(int*)&lbl_802F9DA0; int i;
    for(i=0;i<10;i++) values[i]=p[i];
    if(index<10) return (void*)values[index];
    return (void*)0x8033BD30;
}

extern "C" void fn_80206B08(void) {
	return;
}

extern "C" void fn_80206B0C(void) {
	return;
}

extern "C" void fn_80206B10(void) {
	return;
}

extern "C" void fn_80206BF4(void) {
	return;
}

extern "C" void fn_8020769C(void) {
	fn_802073A4();
}

