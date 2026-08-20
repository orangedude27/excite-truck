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
	unsigned long			v = (unsigned char) val;
	unsigned long			i;
	
	((unsigned char *) dst) = ((unsigned char *) dst) - 1;
	
	if (n >= 32)
	{
		i = (~ (unsigned long) dst) & 3;

		if (i) {
			n -= i;
			
			do {
				*++(((unsigned char *) dst)) = v;
			} while (--i);
		}
	
		if (v)
			v |= v << 24 | v << 16 | v <<  8;
		
		((unsigned long *) dst) = ((unsigned long *) (((unsigned char *) dst) + 1)) - 1;
		
		i = n >> 5;
		
		if (i) {
			do {
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
			} while (--i);
		}
		
		i = (n & 31) >> 2;
		
		if (i) {
			do {
				*++((unsigned long *) dst) = v;
			} while (--i);
		}
		
		((unsigned char *) dst) = ((unsigned char *) (((unsigned long *) dst) + 1)) - 1;
		
		n &= 3;
	}
	
	if (n)
		do {
			*++((unsigned char *) dst) = v;
		} while (--n);
	
	return;
}

DECL_SECTION(".init") void * memset(void * dest, int val, size_t count)
{
    __fill_mem(dest, val, count);
    return dest;
}

DECL_WEAK int memcmp(const void* s1, const void* s2, size_t n) {
    const unsigned char* p1 = (const unsigned char*)s1 - 1;
    const unsigned char* p2 = (const unsigned char*)s2 - 1;
    n++;
    while (--n) {
        if (*++p1 != *++p2) {
            return *p1 - *p2;
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
