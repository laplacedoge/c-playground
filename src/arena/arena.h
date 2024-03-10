#ifndef __ARENA_H__
#define __ARENA_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct _Arena {
    struct _Arena_Meta {
        struct _Arena * nextLand;
        size_t landLen;
        size_t freeLen;
    } meta;

    uint8_t land[];
} Arena;

Arena * Arena_New(void);

void Arena_Del(Arena * arena);

void * Arena_Alloc(Arena * arena, size_t len);

void Arena_Free(Arena * arena, void * ptr);

#endif
