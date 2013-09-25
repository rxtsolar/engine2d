#ifndef GS_OBJECT_H
#define GS_OBJECT_H

#include "image.h"
#include "vect2.h"

namespace gs
{

class GsObject {
public:
    GsObject(void);
    GsObject(const GsImage& image);
    GsObject(const GsObject& object);
    virtual ~GsObject(void);

    virtual GsObject& operator=(const GsObject& object);

    virtual void setPosition(int x, int y);
    virtual void setPosition(const GsVect2i& pos);
    virtual int getX(void) const;
    virtual int getY(void) const;
    virtual const GsVect2i& getPosition(void) const;

    virtual void setImage(const GsImage& image);
    virtual const GsImage& getImage(void) const;

    virtual void displayOn(GsImage& image);
protected:
    GsVect2i position;
    GsImage image;
};

} // namespace gs

#endif // GS_OBJECT_H
