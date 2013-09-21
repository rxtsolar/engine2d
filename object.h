#ifndef GS_OBJECT_H
#define GS_OBJECT_H

#include "image.h"

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
    virtual int getX(void) const;
    virtual int getY(void) const;

    virtual void setImage(const GsImage& image);
    virtual GsImage& getImage(void);
    virtual const GsImage& getImage(void) const;

    virtual void displayOn(GsImage& image);
protected:
    int x;
    int y;
    GsImage image;
};

} // namespace gs

#endif // GS_OBJECT_H
