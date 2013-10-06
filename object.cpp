#include "object.h"

using namespace std;

namespace gs
{

// class GsObject
GsObject::GsObject(void)
{
    collision = false;
}

GsObject::GsObject(const GsSprite& sprite)
{
    collision = false;
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
    collision = object.isWithCollision();
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

void GsObject::enableCollision(void)
{
    collision = true;
}

void GsObject::disableCollision(void)
{
    collision = false;
}

bool GsObject::isWithCollision(void) const
{
    return collision;
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
GsMovObject::GsMovObject(void) : GsObject()
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
    collision = object.isWithCollision();
    bound = object.getBound();
    sprite = object.getSprite();
    velocity = object.getVelocity();
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

void GsMovObject::update(const vector<GsMovObject*>& obstacles)
{
    GsRect newBound = bound;
    vector<GsMovObject*>::const_iterator it;
    newBound.setPoint(bound.getPoint() + velocity);
    if (collision) {
        for (it = obstacles.begin(); it != obstacles.end(); it++) {
            if (*it == this)
                continue;
            if (!(*it)->isWithCollision())
                continue;
            if (newBound.conflictWith((*it)->getBound()))
                return;
        }
    }
    bound = newBound;
}


// class GsAccObject
GsAccObject::GsAccObject(void) : GsMovObject()
{
    capVelocity = 0;
}

GsAccObject::GsAccObject(const GsSprite& sprite) : GsMovObject(sprite)
{
    capVelocity = 0;
}

GsAccObject::GsAccObject(const GsAccObject& object)
{
    *this = object;
}

GsAccObject::~GsAccObject(void)
{

}

GsAccObject& GsAccObject::operator=(const GsAccObject& object)
{
    collision = object.isWithCollision();
    bound = object.getBound();
    sprite = object.getSprite();
    velocity = object.getVelocity();
    capVelocity = object.getCapVelocity();
    acceleration = object.getAcceleration();
    return *this;
}

void GsAccObject::setCapVelocity(double cap)
{
    capVelocity = GsVect2d(cap, cap);
}

void GsAccObject::setCapVelocity(const GsVect2d& cap)
{
    capVelocity = cap;
}

const GsVect2d& GsAccObject::getCapVelocity(void) const
{
    return capVelocity;
}

void GsAccObject::setAcceleration(double ax, double ay)
{
    acceleration = GsVect2d(ax, ay);
}

void GsAccObject::setAcceleration(const GsVect2d& accel)
{
    acceleration = accel;
}

double GsAccObject::getAx(void) const
{
    return acceleration.getX();
}

double GsAccObject::getAy(void) const
{
    return acceleration.getY();
}

const GsVect2d& GsAccObject::getAcceleration(void) const
{
    return acceleration;
}

void GsAccObject::update(const vector<GsAccObject*>& obstacles)
{
    GsRect newBound = bound;
    vector<GsAccObject*>::const_iterator it;
    velocity += acceleration;
    velocity = min(abs(velocity), capVelocity) * sign(velocity);
    newBound.setPoint(bound.getPoint() + velocity);
    if (collision) {
        for (it = obstacles.begin(); it != obstacles.end(); it++) {
            if (*it == this)
                continue;
            if (!(*it)->isWithCollision())
                continue;
            if (newBound.conflictWith((*it)->getBound()))
                return;
        }
    }
    bound = newBound;
}

} // namespace gs
