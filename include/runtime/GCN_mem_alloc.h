#ifndef RUNTIME_GCN_MEM_ALLOC_H
#define RUNTIME_GCN_MEM_ALLOC_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

void* __sys_alloc(size_t size);
void __sys_free(void* block);

#ifdef __cplusplus
}
#endif
#endif
