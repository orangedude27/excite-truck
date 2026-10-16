// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80208408(void);
extern void fn_80208858(void);
extern signed long fn_80128668(void);

typedef struct Vt_80207960 {
    void (*f0)(void);
    void (*f1)(void*, signed long);
    void (*f2)(void*);
} Vt_80207960;

void fn_80207960(void) {
	return;
}

void fn_80207C48(void) {
	return;
}

void fn_80207C4C(void) {
	return;
}

void fn_80207C7C(void) {
	return;
}

void fn_80208404(void) {

}

void fn_802085E8(void) {
	fn_80208408();
}

void fn_80208994(void) {
	fn_80208858();
}

void fn_80208998(void) {
	fn_80208858();
}

void fn_8020899C(void* arg0, void* arg1) {
    typedef struct {
        char pad[0xc];
        void (*f)(void*);
    } Vt_8020899C;
    ((Vt_8020899C*)*(void**)arg1)->f(arg1);
}

void fn_802089B0(void* self) {
    if (self == 0) {
        return;
    }
    ((Vt_80207960*)*(void**)self)->f1(self, 1);
}

signed long fn_802089D0(signed long arg0, signed long arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        fn_80128668();
    }
    return arg0;
}

void fn_802085EC(void) {
	fn_80208408();
}

signed long fn_802085F0(void* arg0, signed long x) {
    switch (x) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            return 1;
        default:
            return 0;
    }
}

