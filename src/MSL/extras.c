#include "extras.h"
#include <cctype>

int stricmp(const char* str1, const char* str2) {
	char a_var;
	char b_var;

	do {
		b_var = tolower(*str1++);
		a_var = tolower(*str2++);

		if (b_var < a_var) {
			return -1;
		}
		if (b_var > a_var) {
			return 1;
		}
	} while (b_var != 0);

	return 0;
}

int strnicmp(const char* str1, const char* str2, int n) {
    return __msl_strnicmp(str1, str2, n);
}

static void qsort_swap(unsigned char* lhs, unsigned char* rhs, size_t size) {
    while (size--) {
        unsigned char tmp = *lhs;
        *lhs++ = *rhs;
        *rhs++ = tmp;
    }
}

void qsort(void* base, size_t count, size_t size,
           int (*compare)(const void*, const void*)) {
    size_t root;

    if (count < 2 || size == 0)
        return;

    /* Build a max heap, then repeatedly move its root to the end. */
    root = count / 2;
    while (root != 0) {
        size_t child;
        unsigned char* item;
        --root;
        item = (unsigned char*)base + root * size;
        child = root * 2 + 1;

        while (child < count) {
            unsigned char* child_ptr = (unsigned char*)base + child * size;
            if (child + 1 < count &&
                compare(child_ptr, child_ptr + size) < 0) {
                ++child;
                child_ptr += size;
            }
            if (compare(item, child_ptr) >= 0)
                break;
            qsort_swap(item, child_ptr, size);
            item = child_ptr;
            child = child * 2 + 1;
        }
    }

    for (count--; count != 0; --count) {
        unsigned char* first = (unsigned char*)base;
        unsigned char* last = first + count * size;
        qsort_swap(first, last, size);
        root = 0;
        while (root * 2 + 1 < count) {
            size_t child = root * 2 + 1;
            unsigned char* item = first + root * size;
            unsigned char* child_ptr = first + child * size;
            if (child + 1 < count &&
                compare(child_ptr, child_ptr + size) < 0) {
                ++child;
                child_ptr += size;
            }
            if (compare(item, child_ptr) >= 0)
                break;
            qsort_swap(item, child_ptr, size);
            root = child;
        }
    }
}
