#ifndef STATIC_DTOR_H
#define STATIC_DTOR_H

/* A static-destructor record chained onto the global list by the registration
   helper (tag 0x31, next = previous list head). */
typedef struct {
    unsigned char tag;  /* 0x31, written by the registration helper */
    void *next;         /* previous head of the list */
} StaticDtorRecord;

#endif
