#include <SDL/SDL_image.h>
#include "image.h"
#include "debug.h"

namespace gs
{

GsImage::GsImage(void)
{
    surface = 0;
}

GsImage::GsImage(const char* path)
{
    surface = 0;
    loadImage(path);
}

GsImage::GsImage(int width, int height)
{
    surface = SDL_SetVideoMode(width, height, GS_DEF_BPP, SDL_SWSURFACE);
    if (!surface)
        gsBug("SDL_SetVideoMode");
    setRoi(0, 0, surface->w, surface->h);
}

GsImage::GsImage(const GsImage& image)
{
    SDL_Surface* origin = image.__getSurface();
    colorKey = image.getColorKey();
    if (!origin) {
        surface = 0;
    } else {
        surface = SDL_DisplayFormatAlpha(origin);
        if (!surface)
            gsBug("SDL_DispplayFormatAlpha");
        setRoi(0, 0, surface->w, surface->h);
    }
}

GsImage::~GsImage(void)
{
    destroyImage();
}

GsImage& GsImage::operator=(const GsImage& image)
{
    destroyImage();
    SDL_Surface* origin = image.__getSurface();
    colorKey = image.getColorKey();
    if (!origin) {
        surface = 0;
    } else {
        surface = SDL_DisplayFormatAlpha(origin);
        if (!surface)
            gsBug("SDL_DispplayFormatAlpha");
        setRoi(0, 0, surface->w, surface->h);
    }
    return *this;
}

void GsImage::loadImage(const char* path)
{
    SDL_Surface* raw = IMG_Load(path);
    if (!raw)
        gsBug("IMG_Load");
    destroyImage();
    surface = SDL_DisplayFormatAlpha(raw);
    SDL_FreeSurface(raw);
    if (!surface)
        gsBug("SDL_DispplayFormatAlpha");
    setRoi(0, 0, surface->w, surface->h);
}

void GsImage::destroyImage(void)
{
    if (surface)
        SDL_FreeSurface(surface);
    surface = 0;
    setRoi(0, 0, 0, 0);
}

SDL_Surface* GsImage::__getSurface(void) const
{
    return surface;
}

void GsImage::applySurface(int x, int y, const GsImage& image)
{
    const GsRect rect = image.getRoi();
    SDL_Rect offset;
    SDL_Rect clip;
    offset.x = x;
    offset.y = y;
    clip.x = rect.getX();
    clip.y = rect.getY();
    clip.w = rect.getW();
    clip.h = rect.getH();
    SDL_BlitSurface(image.__getSurface(), &clip, surface, &offset);
}

int GsImage::getWidth(void) const
{
    if (surface)
        return surface->w;
    else
        return 0;
}

int GsImage::getHeight(void) const
{
    if (surface)
        return surface->h;
    else
        return 0;
}

void GsImage::setColorKey(const GsColor& ck)
{
    colorKey = ck;
}

const GsColor& GsImage::getColorKey(void) const
{
    return colorKey;
}

GsColor& GsImage::getColorKey(void)
{
    return colorKey;
}

void GsImage::enableColorKey(void)
{
    if (!surface)
        return;
    Uint32 ck = SDL_MapRGB(surface->format,
                           colorKey.getR(),
                           colorKey.getG(),
                           colorKey.getB());
    SDL_SetColorKey(surface, SDL_SRCCOLORKEY, ck);
}

void GsImage::disableColorKey(void)
{
    SDL_SetColorKey(surface, 0, 0);
}

void GsImage::setRoi(int x, int y, int w, int h)
{
    roi.setRect(x, y, w, h);
}

GsRect& GsImage::getRoi(void)
{
    return roi;
}

const GsRect& GsImage::getRoi(void) const
{
    return roi;
}

void GsImage::fillRoiWith(int r, int g, int b)
{
    SDL_Rect rect;
    if (!surface)
        return;
    rect.x = roi.getX();
    rect.y = roi.getY();
    rect.w = roi.getW();
    rect.h = roi.getH();
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, r, g, b));
}

} // namespace gs
