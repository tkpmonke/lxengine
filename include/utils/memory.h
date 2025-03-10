#pragma once

#include <memory.h>
#include <stdlib.h>


// mostly here just in case you want to swap these out 
// for a custom allocator, i dont feel like writting
// one so stdlib will have to do

#define LXMALLOC malloc
#define LXREALLOC realloc
#define LXMEMCPY memcpy
#define LXFREE free

// how much to reallocate when running out of capacity on a list
#define LXLIST_ALLOCATION_STEP 1.5f
