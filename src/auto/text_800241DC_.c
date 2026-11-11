// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_800241DC(int arg0, int arg1, unsigned int arg2, unsigned int arg3, int (*arg4)()) {
    /* Binary-search an array at arg1 (arg2 elements, arg3-byte stride) using
     * comparator arg4; returns the matching element pointer, arg1, or 0. */
    int *elementPtr;
    unsigned int lowIndex;
    unsigned int highIndex;
    unsigned int midIndex;
    int compareResult;
    if (arg0 == 0 || arg1 == 0 || arg2 == 0 || arg3 == 0 || arg4 == 0)
        return 0;
    compareResult = arg4();
    if (compareResult == 0)
        return arg1;
    if (compareResult < 0)
        return 0;
    highIndex = arg2 - 1;
    lowIndex = 1;
    while (lowIndex <= highIndex) {
        midIndex = (lowIndex + highIndex) >> 1;
        elementPtr = (int *)(arg1 + arg3 * midIndex);
        compareResult = arg4(arg0, elementPtr);
        if (compareResult == 0)
            return (int)elementPtr;
        if (compareResult < 0)
            highIndex = midIndex - 1;
        else
            lowIndex = midIndex + 1;
    }
    return 0;
}
