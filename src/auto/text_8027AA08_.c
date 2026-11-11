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
    /* Scans entries for close scores and notifies for pairs whose score distance exceeds a threshold. */
    char *currentEntry;
    char *candidateEntry;
    int i;
    int currentScore;
    int closestValue;
    int closestIndex;
    int j;
    int candidateValue;
    int previousDistance;

    if ((unsigned char)lbl_8055F634 != 0) {
        currentEntry = lbl_804A3EE0;
        i = 0;
        while (i < *(int *)(lbl_804A3EE0 + 0x3EC)) {
            currentScore = fn_8027ABF8(*(int *)(currentEntry + 0x94));
            candidateEntry = lbl_804A3EE0;
            closestValue = -1;
            closestIndex = -1;
            j = 0;
            while (j < *(int *)(lbl_804A3EE0 + 0x3EC)) {
                if (j != i) {
                    candidateValue = *(int *)(candidateEntry + 0x94);
                    if (closestValue == -1 ||
                        ((previousDistance = fn_8027AC08(currentScore, closestValue)),
                         fn_8027AC08(currentScore, candidateValue) < previousDistance)) {
                        closestValue = candidateValue;
                        closestIndex = j;
                    }
                }
                candidateEntry += 0x78;
                j++;
            }
            if (closestValue != -1 && fn_8027AC08(currentScore, closestValue) > lbl_8055F638)
                fn_8013CA3C(closestIndex, i);
            currentEntry += 0x78;
            i++;
        }
    }
}
