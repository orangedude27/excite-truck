#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*
 * Review-source carve for the REXE01 MSL printf auto-unit.
 *
 * TP and Petari contain the complete MSL formatter implementation. REXE01's
 * sprintf wrapper uses the same __StringWrite control object, but its local
 * __pformatter has the older four-argument ABI.
 */

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

typedef void* (*PrintfWriteProc)(void*, const char*, size_t);

extern int __pformatter(PrintfWriteProc, void*, const char*, va_list);

int sprintf(char* s, const char* format, ...) {
    va_list args;
    __OutStrCtrl osc;
    int end;

    va_start(args, format);
    osc.CharStr = s;
    osc.MaxCharCount = (size_t)-1;
    osc.CharsWritten = 0;
    end = __pformatter(__StringWrite, &osc, format, args);
    va_end(args);

    if (s) {
        if (end < (int)(size_t)-1) {
            s[end] = '\0';
        } else {
            s[-2] = '\0';
        }
    }

    return end;
}

int vsnprintf(char* s, size_t n, const char* format, va_list args) {
    __OutStrCtrl osc;
    int end;

    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;
    end = __pformatter(__StringWrite, &osc, format, args);

    if (s) {
        if (end < n) {
            s[end] = '\0';
        } else if (n != 0) {
            s[n - 1] = '\0';
        }
    }

    return end;
}

int vsprintf(char* s, const char* format, va_list args) {
    __OutStrCtrl osc;
    int end;

    osc.CharStr = s;
    osc.MaxCharCount = (size_t)-1;
    osc.CharsWritten = 0;
    end = __pformatter(__StringWrite, &osc, format, args);

    if (s) {
        if (end < (int)(size_t)-1) {
            s[end] = '\0';
        } else {
            s[-2] = '\0';
        }
    }

    return end;
}

int snprintf(char* s, size_t n, const char* format, ...) {
    va_list args;
    __OutStrCtrl osc;
    int end;

    va_start(args, format);
    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;
    end = __pformatter(__StringWrite, &osc, format, args);
    va_end(args);

    if (s) {
        if (end < n) {
            s[end] = '\0';
        } else if (n != 0) {
            s[n - 1] = '\0';
        }
    }

    return end;
}
