#include <stddef.h>
#include <stdlib.h>

#include "arena.h"

#ifndef ARENA_DEF_LAND_LEN
#   define ARENA_DEF_LAND_LEN   (1024 * 4)
#endif

static const size_t gDefLandLen = ARENA_DEF_LAND_LEN;

Arena * Arena_New(void) {
    Arena * newArena;

    /* Allocate pool. */
    newArena = malloc(sizeof(Arena) + gDefLandLen);
    if (newArena == NULL) {
        return NULL;
    }

    /* Initialize metadata. */
    newArena->meta.nextLand = NULL;
    newArena->meta.landLen = gDefLandLen;
    newArena->meta.freeLen = newArena->meta.landLen;

    return newArena;
}

void Arena_Del(Arena * arena) {
    Arena * curtArena;
    Arena * nextArena;

    /* Free pools. */
    curtArena = arena;
    do {
        nextArena = curtArena->meta.nextLand;
        free(curtArena);
        curtArena = nextArena;
    } while (curtArena != NULL);
}

void * Arena_Alloc(Arena * arena, size_t len);

void Arena_Free(Arena * arena, void * ptr);
