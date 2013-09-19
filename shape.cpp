#include "shape.h"

namespace gs
{

GsRect::GsRect(void)
{
    setRect(0, 0, 0, 0);
}

GsRect::GsRect(int x, int y, int w, int h)
{
    setRect(x, y, w, h);
}

GsRect::GsRect(const GsRect& rect)
{
    *this = rect;
}

GsRect::~GsRect(void)
{

}

GsRect& GsRect::operator=(const GsRect& rect)
{
    x = rect.getX();
    y = rect.getY();
    w = rect.getW();
    h = rect.getH();
    return *this;
}

void GsRect::setRect(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void GsRect::setX(int x)
{
    this->x = x;
}

void GsRect::setY(int y)
{
    this->y = y;
}

void GsRect::setW(int w)
{
    this->w = w;
}

void GsRect::setH(int h)
{
    this->h = h;
}

int GsRect::getX(void) const
{
    return x;
}

int GsRect::getY(void) const
{
    return y;
}

int GsRect::getW(void) const
{
    return w;
}

int GsRect::getH(void) const
{
    return h;
}

} // namespace gs
