#ifndef GS_IMAGE_H
#define GS_IMAGE_H

#include <SDL/SDL.h>
#include "color.h"
#include "shape.h"

namespace gs
{

const int GS_DEF_WIDTH = 1280;
const int GS_DEF_HEIGHT = 720;
const int GS_DEF_BPP = 32;

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
    virtual SDL_Surface* const __getSurface(void) const;
    virtual void applySurface(int x, int y, const GsImage& image);

    virtual int getWidth(void) const;
    virtual int getHeight(void) const;

    virtual void setColorKey(const GsColor& ck);
    virtual const GsColor& getColorKey(void) const;
    virtual void enableColorKey(void);
    virtual void disableColorKey(void);

    virtual void setRoi(int x, int y, int w, int h);
    virtual const GsRect& getRoi(void) const;

    virtual void fillRoiWith(int r, int g, int b);
protected:
    SDL_Surface* surface;
    GsColor colorKey;
    GsRect roi;
};

} // namespace gs;

#endif // GS_IMAGE_H
