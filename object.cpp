#include "object.h"

namespace gs
{

GsObject::GsObject(void)
{
    x = 0;
    y = 0;
}

GsObject::GsObject(const GsImage& image)
{
    x = 0;
    y = 0;
    setImage(image);
}

GsObject::GsObject(const GsObject& object)
{
    *this = object;
}

GsObject::~GsObject(void)
{

}

GsObject& GsObject::operator=(const GsObject& object)
{
    x = object.getX();
    y = object.getY();
    image = object.getImage();
    return *this;
}

void GsObject::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int GsObject::getX(void) const 
{
    return x;
}

int GsObject::getY(void) const
{
    return y;
}

void GsObject::setImage(const GsImage& image)
{
    this->image = image;
}

GsImage& GsObject::getImage(void)
{
    return image;
}

const GsImage& GsObject::getImage(void) const
{
    return image;
}

void GsObject::displayOn(GsImage& image)
{
    image.applySurface(x, y, this->image);
}

} // namespace gs
