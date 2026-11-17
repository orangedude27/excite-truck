// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).
extern int fn_801B64B4(void *);

#pragma scheduling off
extern int fn_801E3CB4(void *, void *, int, float);
extern int fn_801E3FC8(void *, int, float);
extern int fn_801E4040(void *, void *, int, int, float);
extern int fn_801E41E0(void *, int, float);
extern int fn_801E43BC(void *, float, float);
extern void fn_802C8E70(void *, float *);
extern int fn_802C8FF4(float *, float);
extern void fn_80010724(int, int, void *);
extern void fn_802E317C(char *, ...);
extern float lbl_805626C0;
extern float lbl_805626C4;
extern char lbl_80335F40[];
extern int strlen(const char *);
#pragma scheduling invalid_target
int fn_801B64B4(void *p) {
    unsigned char *data = (unsigned char *)p;
    float converted[4];
    switch (data[0]) {
    case 0: {
        float f = *(float *)(data + 0x1C);
        fn_801E3CB4(data + 4, data + 0x10, *(int *)(data + 0x20), f);
        return 0x24;
    }
    case 1: {
        float f = *(float *)(data + 0x1C);
        fn_801E4040(data + 4, data + 0x10, *(int *)(data + 0x20), *(int *)(data + 0x24), f);
        return 0x28;
    }
    case 2: {
        float f = *(float *)(data + 0x10);
        fn_801E3FC8(data + 4, *(int *)(data + 0x14), f);
        return 0x18;
    }
    case 3:
        fn_802C8E70(data + 4, converted);
        if (fn_802C8FF4(converted, lbl_805626C0) != 0) {
            fn_80010724((int)converted[0], (int)converted[1], data + 0x10);
        }
        return strlen((char *)(data + 0x10)) + 0x11;
    case 4: {
        float f = *(float *)(data + 0x10);
        fn_801E41E0(data + 4, *(int *)(data + 0x14), f);
        return 0x18;
    }
    case 5: {
        float f = *(float *)(data + 0x34);
        fn_801E43BC(data + 4, f, lbl_805626C4);
        return 0x38;
    }
    default:
        fn_802E317C(lbl_80335F40);
        return 0;
    }
}
#pragma scheduling off
void fn_801B6604(void) {
    /* Register fn_801B64B4 as a handler for world event type 3. */
    fn_801EEFDC(fn_801B64B4, 3);
}
#pragma scheduling reset
/* Unregisters the fn_801B64B4 world-event handler (registered for type 3 by
   fn_801B6604) by clearing its slot in the event handler table. */
void fn_801B6614(void) { fn_801EF024(fn_801B64B4); }
