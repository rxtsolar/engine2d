#include "color.h"
#include "const.h"

namespace gs
{

GsColor::GsColor(void)
{
    setColor(0, 0, 0, 0);
}

GsColor::GsColor(int r, int g, int b)
{
    setColor(r, g, b, 0);
}

GsColor::GsColor(int r, int g, int b, int a)
{
    setColor(r, g, b, a);
}

GsColor::GsColor(const GsColor& color)
{
    *this = color;
}

GsColor::~GsColor(void)
{

}

GsColor& GsColor::operator=(const GsColor& color)
{
    r = color.getR();
    g = color.getG();
    b = color.getB();
    a = color.getA();
    return *this;
}

void GsColor::setColor(int r, int g, int b)
{
    setR(r);
    setG(g);
    setB(b);
}

void GsColor::setColor(int r, int g, int b, int a)
{
    setColor(r, g, b);
    setA(a);
}

void GsColor::setR(int r)
{
    if (r > GS_UINT8_MAX)
        r = GS_UINT8_MAX;
    else if (r < 0)
        r = 0;
    this->r = r;
}

void GsColor::setG(int g)
{
    if (g > GS_UINT8_MAX)
        g = GS_UINT8_MAX;
    else if (g < 0)
        g = 0;
    this->g = g;
}

void GsColor::setB(int b)
{
    if (b > GS_UINT8_MAX)
        b = GS_UINT8_MAX;
    else if (b < 0)
        b = 0;
    this->b = b;
}

void GsColor::setA(int a)
{
    if (a > GS_UINT8_MAX)
        a = GS_UINT8_MAX;
    else if (a < 0)
        a = 0;
    this->a = a;
}

int GsColor::getR(void) const
{
    return r;
}

int GsColor::getG(void) const
{
    return g;
}

int GsColor::getB(void) const
{
    return b;
}

int GsColor::getA(void) const
{
    return a;
}

} // namespace gs
