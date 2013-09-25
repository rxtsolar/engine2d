#ifndef GS_SHAPE_H
#define GS_SHAPE_H

#include <SDL/SDL.h>
#include "vect2.h"

namespace gs
{

class GsRect {
public:
    GsRect(void);
    GsRect(int x, int y, int w, int h);
    GsRect(const GsVect2i& p, const GsVect2i& s);
    GsRect(const GsRect& rect);
    virtual ~GsRect(void);

    virtual GsRect& operator=(const GsRect& rect);

    virtual void setRect(int x, int y, int w, int h);
    virtual void setRect(const GsVect2i& p, const GsVect2i& s);
    virtual void setPoint(const GsVect2i& p);
    virtual void setSize(const GsVect2i& s);
    virtual void setX(int x);
    virtual void setY(int y);
    virtual void setW(int w);
    virtual void setH(int h);

    virtual const GsVect2i& getPoint(void) const;
    virtual const GsVect2i& getSize(void) const;
    virtual int getX(void) const;
    virtual int getY(void) const;
    virtual int getW(void) const;
    virtual int getH(void) const;
protected:
    GsVect2i point;
    GsVect2i size;
};

} // namespace gs

#endif // GS_SHAPE_H
