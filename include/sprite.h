#ifndef GS_SPRITE_H
#define GS_SPRITE_H

#include "image.h"
#include "shape.h"
#include "timer.h"

namespace gs
{

class GsSprite {
public:
    GsSprite(void);
    GsSprite(const GsSprite& sprite);
    virtual ~GsSprite(void);

    virtual GsSprite& operator=(const GsSprite& sprite);

    virtual void loadImage(const char* path);
    virtual void setImage(const GsImage& image);
    virtual const GsImage& getImage(void) const;

    virtual void setSize(int w, int h);
    virtual void setSize(const GsVect2i& size);
    virtual const GsVect2i& getSize(void) const;

    virtual void setTimer(const GsTimer& timer);
    virtual const GsTimer& getTimer(void) const;

    virtual void setFps(int fps);
    virtual int getFps(void) const;

    virtual void setStatus(int i);
    virtual int getStatus(void) const;

    virtual void setConfig(int f, int s);
    virtual void setFrames(int n);
    virtual int getFrames(void) const;
    virtual void setSlots(int s);
    virtual int getSlots(void) const;

    virtual void setColorKey(const GsColor& ck);
    virtual const GsColor& getColorKey(void) const;
    virtual void enableColorKey(void);
    virtual void disableColorKey(void);

    virtual void update(void);
    virtual void applySpriteOn(GsImage& image, int x, int y);
protected:
    GsImage image;
    GsVect2i size;
    GsTimer timer;
    int fps;
    int status;
    int frames;
    int slots;

    virtual void calcSize(void);
};

} // namespace gs

#endif // GS_SPRITE_H
