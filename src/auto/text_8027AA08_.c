// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F634;
extern int fn_80128668(void);
int fn_8027AA08(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

char fn_8027AA48(void) {
    return lbl_8055F634;
}

extern int fn_8027ABF8(int);
extern int fn_8027AC08(int, int);
extern void fn_8013CA3C(int, int);
extern int lbl_8055F638;
extern char lbl_804A3EE0[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8027AA50(int arg0) {
    char *outer;
    char *inner;
    int i;
    int score;
    int best_value;
    int best_index;
    int j;
    int other_value;
    int old_score;

    if ((unsigned char)lbl_8055F634 != 0) {
        outer = lbl_804A3EE0;
        i = 0;
        while (i < *(int *)(lbl_804A3EE0 + 0x3EC)) {
            score = fn_8027ABF8(*(int *)(outer + 0x94));
            inner = lbl_804A3EE0;
            best_value = -1;
            best_index = -1;
            j = 0;
            while (j < *(int *)(lbl_804A3EE0 + 0x3EC)) {
                if (j != i) {
                    other_value = *(int *)(inner + 0x94);
                    if (best_value == -1 ||
                        ((old_score = fn_8027AC08(score, best_value)),
                         fn_8027AC08(score, other_value) < old_score)) {
                        best_value = other_value;
                        best_index = j;
                    }
                }
                inner += 0x78;
                j++;
            }
            if (best_value != -1 && fn_8027AC08(score, best_value) > lbl_8055F638)
                fn_8013CA3C(best_index, i);
            outer += 0x78;
            i++;
        }
    }
}
