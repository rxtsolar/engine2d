#include "object.h"

namespace gs
{

GsObject::GsObject(void)
{

}

GsObject::GsObject(const GsImage& image)
{
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
    position = object.getPosition();
    image = object.getImage();
    return *this;
}

void GsObject::setPosition(int x, int y)
{
    position = GsVect2i(x, y);
}

void GsObject::setPosition(const GsVect2i& pos)
{
    position = pos;
}

int GsObject::getX(void) const 
{
    return position.getX();
}

int GsObject::getY(void) const
{
    return position.getY();
}

const GsVect2i& GsObject::getPosition(void) const
{
    return position;
}

void GsObject::setImage(const GsImage& image)
{
    this->image = image;
}

const GsImage& GsObject::getImage(void) const
{
    return image;
}

void GsObject::displayOn(GsImage& image)
{
    image.applySurface(position.getX(), position.getY(), this->image);
}

} // namespace gs
