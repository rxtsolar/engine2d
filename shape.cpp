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

GsRect::GsRect(const GsVect2i& p, const GsVect2i& s)
{
    setRect(p, s);
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
    point = GsVect2i(rect.getX(), rect.getY());
    size = GsVect2i(rect.getW(), rect.getH());
    return *this;
}

void GsRect::setRect(int x, int y, int w, int h)
{
    point = GsVect2i(x, y);
    size = GsVect2i(w, h);
}

void GsRect::setRect(const GsVect2i& p, const GsVect2i& s)
{
    point = p;
    size = s;
}

void GsRect::setPoint(const GsVect2i& p)
{
    point = p;
}

void GsRect::setSize(const GsVect2i& s)
{
    size = s;
}

void GsRect::setX(int x)
{
    point.setX(x);
}

void GsRect::setY(int y)
{
    point.setY(y);
}

void GsRect::setW(int w)
{
    size.setX(w);
}

void GsRect::setH(int h)
{
    size.setY(h);
}

const GsVect2i& GsRect::getPoint(void) const
{
    return point;
}

const GsVect2i& GsRect::getSize(void) const
{
    return size;
}

int GsRect::getX(void) const
{
    return point.getX();
}

int GsRect::getY(void) const
{
    return point.getY();
}

int GsRect::getW(void) const
{
    return size.getX();
}

int GsRect::getH(void) const
{
    return size.getY();
}

} // namespace gs
