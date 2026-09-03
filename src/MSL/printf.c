#include <stdio.h>
#include <string.h>

/* Review-source carve for the REXE01 MSL printf auto-unit
 * (__FileWrite@80027238, __StringWrite@80027290, vprintf@800272FC,
 * vsprintf@800273F8).  The full FILE layout is not modeled in this
 * project yet; these two writer callbacks are self-contained. */

extern size_t __fwrite(const void* buffer, size_t size, size_t count,
                       FILE* file);

void* __FileWrite(void* pFile, const char* pBuffer, size_t char_num) {
    return (__fwrite(pBuffer, 1, char_num, (FILE*)pFile) == char_num ? pFile
                                                                     : 0);
}

typedef struct __OutStrCtrl {
    void* CharStr; // at 0x0
    size_t MaxCharCount; // at 0x4
    size_t CharsWritten; // at 0x8
} __OutStrCtrl;

void* __StringWrite(void* pCtrl, const char* pBuffer, size_t char_num) {
    size_t chars;
    __OutStrCtrl* ctrl = (__OutStrCtrl*)pCtrl;

    chars = ((ctrl->CharsWritten + char_num) <= ctrl->MaxCharCount)
                ? char_num
                : ctrl->MaxCharCount - ctrl->CharsWritten;
    memcpy((char*)ctrl->CharStr + ctrl->CharsWritten, pBuffer, chars);
    ctrl->CharsWritten += chars;

    return (void*)1;
}