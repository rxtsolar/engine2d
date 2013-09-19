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
    surface = SDL_SetVideoMode(width, height, DEFAULT_BPP, SDL_SWSURFACE);
    if (!surface)
        gsBug("SDL_SetVideoMode");
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
}

void GsImage::destroyImage(void)
{
    if (surface)
        SDL_FreeSurface(surface);
    surface = 0;
}

SDL_Surface* GsImage::__getSurface(void) const
{
    return surface;
}

void GsImage::applySurface(int x, int y, const GsImage& image)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(image.__getSurface(), 0, surface, &offset);
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

} // namespace gs
