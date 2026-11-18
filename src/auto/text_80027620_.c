// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma cplusplus on
#pragma exceptions on
extern "C" void qsort(void *arg0, unsigned int arg1, int arg2, int (*arg3)(void *, void *)) {
    register int half;
    register int negsize;
    register unsigned int child;
    register int root;
    register int last;
    register int parent;
    register int item;
    register int second;
    register unsigned int i;
    register unsigned int n;
    char *var_r3;
    char *var_r3_2;
    char *var_r4;
    char *var_r4_2;
    int var_r5;
    int var_r5_2;
    int tmp6;
    int tmp6_2;

    if (arg1 >= 2U) {
        n = arg1;
        i = (arg1 >> 1) + 1;
        root = (int)arg0 + arg2 * (i - 1);
        half = i * arg2;
        last = (int)arg0 + arg2 * (arg1 - 1);
        negsize = arg2 - arg2 * 2;
    heap_test:
        if (i > 1U) {
            half -= arg2;
            root -= arg2;
            i -= 1;
            goto block9;
        }
    extract:
        var_r3_2 = (char *)last - 1;
        var_r4_2 = (char *)root - 1;
        var_r5_2 = arg2 + 1;
        while (--var_r5_2 != 0) {
            tmp6_2 = var_r4_2[1];
            var_r4_2[1] = var_r3_2[1];
            var_r4_2++;
            var_r3_2[1] = tmp6_2;
            var_r3_2++;
        }
        n -= 1;
        if (n == 1U) goto end;
        last -= arg2;
    block9:
        child = i;
        item = (int)((char *)arg0 + (half + negsize));
        goto check;
    sift:
        child *= 2;
        parent = item;
        item = (int)arg0 + arg2 * (child - 1);
        if (child < n) {
            second = item + arg2;
            if (arg3((void *)item, (void *)second) < 0) {
                item = second;
                child += 1;
            }
        }
        if (arg3((void *)parent, (void *)item) >= 0) goto heap_test;
        var_r3 = (char *)item - 1;
        var_r4 = (char *)parent - 1;
        var_r5 = arg2 + 1;
        while (--var_r5 != 0) {
            tmp6 = var_r4[1];
            var_r4[1] = var_r3[1];
            var_r3[1] = tmp6;
            var_r4++;
            var_r3++;
        }
        goto check;
    check:
        if (child * 2 > n) {
            goto heap_test;
        } else {
            goto sift;
        }
    }
end:
    ;
}
