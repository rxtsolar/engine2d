#ifndef GS_CONST_H
#define GS_CONST_H

#include <cmath>
#include <cfloat>
#include <cstdlib>
#include <SDL/SDL.h>

namespace gs
{

const int GS_DEF_WIDTH = 1280;
const int GS_DEF_HEIGHT = 720;
const int GS_DEF_BPP = 32;
const int GS_DEF_FPS = 30;
const int GS_DEF_ANM_FPS = 2;

const double GS_PI = 4.0 * atan(1.0);
const double GS_EPSILON = FLT_EPSILON;
const double GS_DEG_TO_RAD = GS_PI / 180.0;
const double GS_RAG_TO_DEG = 180.0 / GS_PI;

const int GS_UINT8_MAX = (Uint8)-1;

} // namespace gs

#endif // GS_CONST_H
