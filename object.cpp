#include "object.h"

using namespace std;

namespace gs
{

// class GsObject
GsObject::GsObject(void)
{

}

GsObject::GsObject(const GsSprite& sprite)
{
    setSprite(sprite);
    setSize(sprite.getSize());
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
    bound = object.getBound();
    sprite = object.getSprite();
    return *this;
}

void GsObject::setPosition(int x, int y)
{
    bound.setPoint(GsVect2i(x, y));
}

void GsObject::setPosition(const GsVect2i& pos)
{
    bound.setPoint(pos);
}

int GsObject::getX(void) const 
{
    return bound.getX();
}

int GsObject::getY(void) const
{
    return bound.getY();
}

const GsVect2i& GsObject::getPosition(void) const
{
    return bound.getPoint();
}

void GsObject::setSize(int w, int h)
{
    bound.setSize(GsVect2i(w, h));
}

void GsObject::setSize(const GsVect2i& size)
{
    bound.setSize(size);
}

int GsObject::getW(void) const
{
    return bound.getW();
}

int GsObject::getH(void) const
{
    return bound.getH();
}

const GsVect2i& GsObject::getSize(void) const
{
    return bound.getSize();
}

void GsObject::setBound(int x, int y, int w, int h)
{
    bound.setRect(x, y, w, h);
}

void GsObject::setBound(const GsRect& rect)
{
    bound = rect;
}

const GsRect& GsObject::getBound(void) const
{
    return bound;
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
    sprite.applySpriteOn(image, bound.getX(), bound.getY());
}

bool GsObject::conflictWith(const GsObject& object) const
{
    return bound.conflictWith(object.getBound());
}

bool GsObject::conflictWith(const vector<GsObject*>& objects) const
{
    vector<GsObject*>::const_iterator it;
    for (it = objects.begin(); it != objects.end(); it++)
        if (bound.conflictWith((*it)->getBound()))
            return true;
    return false;
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
    bound = object.getBound();
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
    bound.setPoint(bound.getPoint() + velocity);
}

} // namespace gs
