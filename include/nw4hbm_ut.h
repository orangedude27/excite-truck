#ifndef NW4HBM_UT_H
#define NW4HBM_UT_H

#include <types.h>

namespace nw4hbm { namespace ut {
/* One RGBA color: four bytes, read as a word when taken whole. */
struct Color { u8 b0, b1, b2, b3; };
} }

#endif
