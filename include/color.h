#ifndef GS_COLOR_H
#define GS_COLOR_H

#include <SDL/SDL.h>

namespace gs
{

class GsColor {
public:
    GsColor(void);
    GsColor(int r, int g, int b);
    GsColor(int r, int g, int b, int a);
    GsColor(const GsColor& color);
    virtual ~GsColor(void);
    virtual GsColor& operator=(const GsColor& color);
    virtual void setColor(int r, int g, int b);
    virtual void setColor(int r, int g, int b, int a);
    virtual void setR(int r);
    virtual void setG(int g);
    virtual void setB(int b);
    virtual void setA(int a);
    virtual int getR(void) const;
    virtual int getG(void) const;
    virtual int getB(void) const;
    virtual int getA(void) const;
protected:
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};

} // namespace gs

#endif // GS_COLOR_H
