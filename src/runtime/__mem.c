#include <string.h>

DECL_SECTION(".init") void * memcpy(void * dest, const void * src, size_t count)
{
    const char * csrc = (const char *)src;
    char * cdest = (char *)dest;
    
    if (src >= dest)
    {
        csrc--;
        cdest--;
        count++;
        
        while (--count)
        {
            *++cdest = *++csrc;
        }
    }
    else
    {
        csrc += count;
        cdest += count;
        count++;
        
        while (--count)
        {
            *--cdest = *--csrc;
        }
    }
}

DECL_SECTION(".init") void __fill_mem(void* dst, int val, unsigned long n)
{
	/* Fill n bytes at dst with (unsigned char)val. Aligns to a word boundary,
	   stores 32-byte then 4-byte blocks when large enough, then writes any
	   remaining bytes; pointer-cast stepping is kept as-is for codegen. */
	unsigned long			fillWord = (unsigned char) val;
	unsigned long			count;
	
	((unsigned char *) dst) = ((unsigned char *) dst) - 1;
	
	if (n >= 32)
	{
		count = (~ (unsigned long) dst) & 3;

		if (count) {
			n -= count;
			
			do {
				*++(((unsigned char *) dst)) = fillWord;
			} while (--count);
		}
	
		if (fillWord)
			fillWord |= fillWord << 24 | fillWord << 16 | fillWord <<  8;
		
		((unsigned long *) dst) = ((unsigned long *) (((unsigned char *) dst) + 1)) - 1;
		
		count = n >> 5;
		
		if (count) {
			do {
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
				*++((unsigned long *) dst) = fillWord;
			} while (--count);
		}
		
		count = (n & 31) >> 2;
		
		if (count) {
			do {
				*++((unsigned long *) dst) = fillWord;
			} while (--count);
		}
		
		((unsigned char *) dst) = ((unsigned char *) (((unsigned long *) dst) + 1)) - 1;
		
		n &= 3;
	}
	
	if (n)
		do {
			*++((unsigned char *) dst) = fillWord;
		} while (--n);
	
	return;
}

DECL_SECTION(".init") void * memset(void * dest, int val, size_t count)
{
    __fill_mem(dest, val, count);
    return dest;
}

DECL_WEAK int memcmp(const void* s1, const void* s2, size_t n) {
    const unsigned char* p1;
    const unsigned char* p2;

    for (p1 = (const unsigned char*)s1 - 1,
         p2 = (const unsigned char*)s2 - 1, n++;
         --n;) {
        if (*++p1 != *++p2) {
            return *p1 < *p2 ? -1 : 1;
        }
    }

    return 0;
}

DECL_WEAK size_t strlen(const char* s) {
    const u8* p = (u8*)s - 1;
    size_t len = -1;
    
    do {
        len++;
    } while (*++p);

    return len;
}
