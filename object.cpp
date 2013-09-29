#include "object.h"

namespace gs
{

// class GsObject
GsObject::GsObject(void)
{

}

GsObject::GsObject(const GsSprite& sprite)
{
    setSprite(sprite);
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
    sprite = object.getSprite();
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

void GsObject::setSprite(const GsSprite& sprite)
{
    this->sprite = sprite;
}

const GsSprite& GsObject::getSprite(void) const
{
    return sprite;
}

void GsObject::displayOn(GsImage& image)
{
    sprite.update();
    sprite.applySpriteOn(image, position.getX(), position.getY());
}


// class GsMovObject
GsMovObject::GsMovObject(void)
{

}

GsMovObject::GsMovObject(const GsSprite& sprite) : GsObject(sprite)
{

}

GsMovObject::GsMovObject(const GsMovObject& object)
{
    *this = object;
}

GsMovObject::~GsMovObject(void)
{

}

GsMovObject& GsMovObject::operator=(const GsMovObject& object)
{
    position = object.getPosition();
    velocity = object.getVelocity();
    sprite = object.getSprite();
    return *this;
}

void GsMovObject::setVelocity(double vx, double vy)
{
    velocity = GsVect2d(vx, vy);
}

void GsMovObject::setVelocity(const GsVect2d& velo)
{
    velocity = velo;
}

double GsMovObject::getVx(void) const
{
    return velocity.getX();
}

double GsMovObject::getVy(void) const
{
    return velocity.getY();
}

const GsVect2d& GsMovObject::getVelocity(void) const
{
    return velocity;
}

void GsMovObject::update(void)
{
    position += velocity;
}

} // namespace gs
