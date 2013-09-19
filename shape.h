#ifndef GS_SHAPE_H
#define GS_SHAPE_H

#include <SDL/SDL.h>

namespace gs
{

class GsRect {
public:
    GsRect(void);
    GsRect(int x, int y, int w, int h);
    GsRect(const GsRect& rect);
    virtual ~GsRect(void);
    virtual GsRect& operator=(const GsRect& rect);
    virtual void setRect(int x, int y, int w, int h);
    virtual void setX(int x);
    virtual void setY(int y);
    virtual void setW(int w);
    virtual void setH(int h);
    virtual int getX(void) const;
    virtual int getY(void) const;
    virtual int getW(void) const;
    virtual int getH(void) const;
protected:
    int x;
    int y;
    int w;
    int h;
};

} // namespace gs

#endif // GS_SHAPE_H
