#include "color.h"

namespace gs
{

GsColor::GsColor(void)
{
    setColor(0, 0, 0);
}

GsColor::GsColor(int r, int g, int b)
{
    setColor(r, g, b);
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
    this->r = r;
    this->g = g;
    this->b = b;
    a = 0;
}

void GsColor::setColor(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void GsColor::setR(int r)
{
    this->r = r;
}

void GsColor::setG(int g)
{
    this->g = g;
}

void GsColor::setB(int b)
{
    this->b = b;
}

void GsColor::setA(int a)
{
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
