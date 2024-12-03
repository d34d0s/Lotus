#ifndef LT2DTYPES_H
#define LT2DTYPES_H

#include "../lotus.core/lotustypes.h"

typedef struct tag2DPrimitive {
    LTvec3 color;
    LTvertexData vertexData;
} LT2Dprimitive;

typedef struct tagSprite {
    LTvec2 size;
    LTvec2 location;
    LTtexture2D texture;
    LT2Dprimitive primitive;
} LT2Dsprite;

#endif