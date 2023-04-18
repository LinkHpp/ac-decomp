#ifndef GAMEALLOC_H
#define GAMEALLOC_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sizeof(struct gameAllocList_s) == 0x10 */
typedef struct gameAllocList_s {
  /* 0x00 */ struct gameAllocList_s* next;
  /* 0x04 */ struct gameAllocList_s* prev;
  /* 0x08 */ size_t alloc_size;
  /* 0x0C */ u32 pad;
} GameAllocList;

/* sizeof(struct gameAlloc_s) == 0x14 */
typedef struct gameAlloc_s {
  /* 0x00 */ GameAllocList head;
  /* 0x10 */ GameAllocList* tail;
} GameAlloc;

#ifdef __cplusplus
};
#endif

#endif