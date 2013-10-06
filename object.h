#ifndef GS_OBJECT_H
#define GS_OBJECT_H

#include "sprite.h"
#include "image.h"
#include "vect2.h"
#include <vector>

namespace gs
{

class GsObject {
public:
    GsObject(void);
    GsObject(const GsSprite& sprite);
    GsObject(const GsObject& object);
    virtual ~GsObject(void);

    virtual GsObject& operator=(const GsObject& object);

    virtual void setPosition(int x, int y);
    virtual void setPosition(const GsVect2i& pos);
    virtual int getX(void) const;
    virtual int getY(void) const;
    virtual const GsVect2i& getPosition(void) const;

    virtual void setSize(int w, int h);
    virtual void setSize(const GsVect2i& size);
    virtual int getW(void) const;
    virtual int getH(void) const;
    virtual const GsVect2i& getSize(void) const;

    virtual void setBound(int x, int y, int w, int h);
    virtual void setBound(const GsRect& rect);
    virtual const GsRect& getBound(void) const;

    virtual void setSprite(const GsSprite& sprite);
    virtual const GsSprite& getSprite(void) const;

    virtual void displayOn(GsImage& image);

    virtual void enableCollision(void);
    virtual void disableCollision(void);
    virtual bool isWithCollision(void) const;

    virtual bool conflictWith(const GsObject& object) const;
    virtual bool conflictWith(const std::vector<GsObject*>& objects) const;
protected:
    bool collision;
    GsRect bound;
    GsSprite sprite;
};

class GsMovObject : public GsObject {
public:
    GsMovObject(void);
    GsMovObject(const GsSprite& sprite);
    GsMovObject(const GsMovObject& object);
    virtual ~GsMovObject(void);

    virtual GsMovObject& operator=(const GsMovObject& object);

    virtual void setVelocity(double vx, double vy);
    virtual void setVelocity(const GsVect2d& velo);
    virtual double getVx(void) const;
    virtual double getVy(void) const;
    virtual const GsVect2d& getVelocity(void) const;

    virtual void update(const std::vector<GsMovObject*>& obstacles);
protected:
    GsVect2d velocity;
};

class GsAccObject : public GsMovObject {
public:
    GsAccObject(void);
    GsAccObject(const GsSprite& sprite);
    GsAccObject(const GsAccObject& object);
    virtual ~GsAccObject(void);

    virtual GsAccObject& operator=(const GsAccObject& object);

    virtual void setAcceleration(double ax, double ay);
    virtual void setAcceleration(const GsVect2d& accel);
    virtual double getAx(void) const;
    virtual double getAy(void) const;
    virtual const GsVect2d& getAcceleration(void) const;

    virtual void update(const std::vector<GsAccObject*>& obstacles);
protected:
    GsVect2d acceleration;
};

} // namespace gs

#endif // GS_OBJECT_H
