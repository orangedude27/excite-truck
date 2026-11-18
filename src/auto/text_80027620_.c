// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma cplusplus on
#pragma exceptions on
extern "C" void qsort(void *list, unsigned int number, int width, int (*comp)(void *, void *)) {
    /* MSL qsort: an in-place heap sort.  First a max-heap is built by sifting every
     * node from the middle of the array back to the root; then the root (largest
     * element) is swapped with the last element of the heap, the heap shrinks by one
     * and the root is sifted down again, leaving the array sorted ascending by
     * `comp'.  Elements are `width' bytes wide and are swapped byte by byte. */
    register int half;
    register int negwidth;
    register unsigned int child;
    register int root;
    register int last;
    register int parent;
    register int item;
    register int second;
    register unsigned int i;
    register unsigned int n;
    char *from;
    char *from0;
    char *to;
    char *to0;
    int cnt;
    int cnt0;
    int tmp;
    int tmp0;

    if (number >= 2U) {
        n = number;
        i = (number >> 1) + 1;
        root = (int)list + width * (i - 1);
        half = i * width;
        last = (int)list + width * (number - 1);
        negwidth = width - width * 2;
    heapify:
        /* one node further up, or the heap is built */
        if (i > 1U) {
            half -= width;
            root -= width;
            i -= 1;
            goto sift_down;
        }
    extract_max:
        /* swap the heap root and the last element, byte by byte */
        from0 = (char *)last - 1;
        to0 = (char *)root - 1;
        cnt0 = width + 1;
        while (--cnt0 != 0) {
            tmp0 = to0[1];
            to0[1] = from0[1];
            to0++;
            from0[1] = tmp0;
            from0++;
        }
        n -= 1;
        if (n == 1U) goto done;
        last -= width;
    sift_down:
        child = i;
        item = (int)((char *)list + (half + negwidth));
        goto has_child;
    sift_body:
        /* step down to the larger child */
        child *= 2;
        parent = item;
        item = (int)list + width * (child - 1);
        if (child < n) {
            second = item + width;
            if (comp((void *)item, (void *)second) < 0) {
                item = second;
                child += 1;
            }
        }
        if (comp((void *)parent, (void *)item) >= 0) goto heapify;
        from = (char *)item - 1;
        to = (char *)parent - 1;
        cnt = width + 1;
        while (--cnt != 0) {
            tmp = to[1];
            to[1] = from[1];
            to++;
            from[1] = tmp;
            from++;
        }
        goto has_child;
    has_child:
        if (child * 2 > n) {
            goto heapify;
        } else {
            goto sift_body;
        }
    }
done:
    ;
}
