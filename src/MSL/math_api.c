#include <MSL/math.h>

/* Review-source carve for auto_fpclassifyf_text / auto_fpclassifyd_text. */
int __fpclassifyf(float value) {
    unsigned long bits = *(unsigned long*)&value;

    switch (bits & 0x7F800000) {
    case 0x7F800000:
        return (bits & 0x007FFFFF) != 0 ? 1 : 2;
    case 0:
        return (bits & 0x007FFFFF) != 0 ? 5 : 3;
    default:
        return 4;
    }
}

int __fpclassifyd(double value) {
    unsigned long* bits = (unsigned long*)&value;

    switch (bits[0] & 0x7FF00000) {
    case 0x7FF00000:
        return ((bits[0] & 0x000FFFFF) != 0 || bits[1] != 0) ? 1 : 2;
    case 0:
        return ((bits[0] & 0x000FFFFF) != 0 || bits[1] != 0) ? 5 : 3;
    default:
        return 4;
    }
}
