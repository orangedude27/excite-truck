// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8012C4D8(void);
void fn_80128670(int);
void fn_80128668(void *);
void *fn_8012C370(int, unsigned int, unsigned int *, unsigned int *, int, unsigned char *);
void *fn_80131234(void *);
void fn_802E317C(char *, ...);
extern char lbl_803401F8[];
extern char lbl_80340220[];
#pragma scheduling invalid_target
void *fn_8022E0EC(int arg0) {
    unsigned int size;
    unsigned int extra;
    unsigned char flag;
    char *base;
    char *rec;
    char *src;
    char a;
    int count;
    char *dst;
    char t;

    base = fn_8012C370(arg0, 0x4C415954, &size, &extra, 0, &flag);
    if (base != 0) {
        if (size != 5) {
            fn_802E317C(lbl_803401F8, arg0, size, 5);
        }
        if (flag != 0) {
            rec = base + 0x68;
            *(char **)(base + 0x64) = rec;
            t = base[0x0];
base[0x0] = base[0x3];
base[0x3] = t;
t = base[0x1];
base[0x1] = base[0x2];
base[0x2] = t;
            for (;;) {
                t = rec[0x0];
rec[0x0] = rec[0x3];
rec[0x3] = t;
t = rec[0x1];
rec[0x1] = rec[0x2];
rec[0x2] = t;
t = rec[0x4];
rec[0x4] = rec[0x7];
rec[0x7] = t;
t = rec[0x5];
rec[0x5] = rec[0x6];
rec[0x6] = t;
t = rec[0x8];
rec[0x8] = rec[0xb];
rec[0xb] = t;
t = rec[0x9];
rec[0x9] = rec[0xa];
rec[0xa] = t;
t = rec[0xc];
rec[0xc] = rec[0xf];
rec[0xf] = t;
t = rec[0xd];
rec[0xd] = rec[0xe];
rec[0xe] = t;
t = rec[0x10];
rec[0x10] = rec[0x13];
rec[0x13] = t;
t = rec[0x11];
rec[0x11] = rec[0x12];
rec[0x12] = t;
t = rec[0x14];
rec[0x14] = rec[0x17];
rec[0x17] = t;
t = rec[0x15];
rec[0x15] = rec[0x16];
rec[0x16] = t;
t = rec[0x18];
rec[0x18] = rec[0x1b];
rec[0x1b] = t;
t = rec[0x19];
rec[0x19] = rec[0x1a];
rec[0x1a] = t;
t = rec[0x1c];
rec[0x1c] = rec[0x1f];
rec[0x1f] = t;
t = rec[0x1d];
rec[0x1d] = rec[0x1e];
rec[0x1e] = t;
t = rec[0x80];
rec[0x80] = rec[0x83];
rec[0x83] = t;
t = rec[0x81];
rec[0x81] = rec[0x82];
rec[0x82] = t;
t = rec[0x84];
rec[0x84] = rec[0x87];
rec[0x87] = t;
t = rec[0x85];
rec[0x85] = rec[0x86];
rec[0x86] = t;
t = rec[0x88];
rec[0x88] = rec[0x8b];
rec[0x8b] = t;
t = rec[0x89];
rec[0x89] = rec[0x8a];
rec[0x8a] = t;
t = rec[0x8c];
rec[0x8c] = rec[0x8f];
rec[0x8f] = t;
t = rec[0x8d];
rec[0x8d] = rec[0x8e];
rec[0x8e] = t;
t = rec[0x90];
rec[0x90] = rec[0x93];
rec[0x93] = t;
t = rec[0x91];
rec[0x91] = rec[0x92];
rec[0x92] = t;
t = rec[0x94];
rec[0x94] = rec[0x97];
rec[0x97] = t;
t = rec[0x95];
rec[0x95] = rec[0x96];
rec[0x96] = t;
t = rec[0x98];
rec[0x98] = rec[0x9b];
rec[0x9b] = t;
t = rec[0x99];
rec[0x99] = rec[0x9a];
rec[0x9a] = t;
t = rec[0x9c];
rec[0x9c] = rec[0x9f];
rec[0x9f] = t;
t = rec[0x9d];
rec[0x9d] = rec[0x9e];
rec[0x9e] = t;
t = rec[0xa0];
rec[0xa0] = rec[0xa3];
rec[0xa3] = t;
t = rec[0xa1];
rec[0xa1] = rec[0xa2];
rec[0xa2] = t;
t = rec[0xa4];
rec[0xa4] = rec[0xa7];
rec[0xa7] = t;
t = rec[0xa5];
rec[0xa5] = rec[0xa6];
rec[0xa6] = t;
t = rec[0xa8];
rec[0xa8] = rec[0xab];
rec[0xab] = t;
t = rec[0xa9];
rec[0xa9] = rec[0xaa];
rec[0xaa] = t;
t = rec[0xac];
rec[0xac] = rec[0xaf];
rec[0xaf] = t;
t = rec[0xad];
rec[0xad] = rec[0xae];
rec[0xae] = t;
t = rec[0xb0];
rec[0xb0] = rec[0xb3];
rec[0xb3] = t;
t = rec[0xb1];
rec[0xb1] = rec[0xb2];
rec[0xb2] = t;
                if (*(unsigned int *)rec == 0) {
                    break;
                }
                if (rec[0x40] == 0x7c) {
                    src = fn_80131234(rec + 0x41);
                    dst = rec + 0x40;
                    count = 0x40;
                    goto copy_character;
                count_more:
                    count--;
                    if (count > 0) {
                        goto copy_character;
                    }
                    dst[-1] = 0;
                    goto copy_done;
                copy_character:
                    a = *src++;
                    *dst++ = a;
                    if (a != 0) {
                        goto count_more;
                    }
                copy_done:
                    ;
                }
                rec += 0x134;
            }
        }
    } else {
        fn_802E317C(lbl_80340220, arg0);
    }
    return base;
}
#pragma scheduling on
void fn_8022E4BC(void) {
    fn_8012C4D8();
}

void fn_8022E960(void *arg0) {
    fn_80128670(*(int *)((char *)arg0 + 0x64));
    fn_80128668(arg0);
}

