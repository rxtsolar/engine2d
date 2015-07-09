#ifndef GS_DEBUG_H
#define GS_DEBUG_H

#include <iostream>
#include <cstdlib>

namespace gs
{

inline void gsBug(const char* msg)
{
    std::cerr << "Error: " << msg << std::endl;
    exit(1);
}

inline void gsWarn(const char* msg)
{
    std::cerr << "Error: " << msg << std::endl;
}

} // namespace gs

#endif // GS_DEBUG_H
