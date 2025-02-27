#pragma once

#include "stdlib.h"


// mostly here just in case you want to swap these out 
// for a custom allocator, i dont feel like writting
// one so stdlib will have to do

#define LZMALLOC malloc
#define LZREALLOC realloc
#define LZFREE free

// how much to reallocate when running out of capacity on a list
#define LZLIST_ALLOCATION_STEP 1.5f
