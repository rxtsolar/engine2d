#ifndef GS_DEBUG_H
#define GS_DEBUG_H

#include <iostream>

namespace gs
{

inline void gsBug(const char* msg)
{
    std::cerr << msg << std::endl;
    exit(1);
}

} // namespace gs

#endif // GS_DEBUG_H
