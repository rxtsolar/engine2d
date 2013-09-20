#ifndef GS_IMAGE_H
#define GS_IMAGE_H

#include <SDL/SDL.h>
#include "color.h"
#include "shape.h"

namespace gs
{

const int DEFAULT_WIDTH = 1280;
const int DEFAULT_HEIGHT = 720;
const int DEFAULT_BPP = 32;

class GsImage {
public:
    GsImage(void);
    GsImage(const char* path);
    GsImage(int width, int height);
    GsImage(const GsImage& image);
    virtual ~GsImage(void);

    virtual GsImage& operator=(const GsImage& image);

    virtual void loadImage(const char* path);
    virtual void destroyImage(void);
    virtual SDL_Surface* __getSurface(void) const;
    virtual void applySurface(int x, int y, const GsImage& image);

    virtual int getWidth(void) const;
    virtual int getHeight(void) const;

    virtual void setColorKey(const GsColor& ck);
    virtual GsColor& getColorKey(void);
    virtual const GsColor& getColorKey(void) const;
    virtual void enableColorKey(void);
    virtual void disableColorKey(void);

    virtual void setRoi(int x, int y, int w, int h);
    virtual GsRect& getRoi(void);
    virtual const GsRect& getRoi(void) const;

    virtual void fillRoiWith(int r, int g, int b);
protected:
    SDL_Surface* surface;
    GsColor colorKey;
    GsRect roi;
};

} // namespace gs;

#endif // GS_IMAGE_H
