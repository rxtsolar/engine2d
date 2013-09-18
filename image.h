#ifndef GS_IMAGE_H
#define GS_IMAGE_H

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
    virtual SDL_Surface* getSurface(void) const;
    virtual void applySurface(int x, int y, const GsImage& image);
    virtual void setColorKey(Uint32 ck);
    virtual void setColorKey(Uint8 r, Uint8 g, Uint8 b);
    virtual Uint32 getColorKey(void) const;
    virtual void enableColorKey(void);
    virtual void disableColorKey(void);
protected:
    SDL_Surface* surface;
    Uint32 colorKey;
};

} // namespace gs;

#endif // GS_IMAGE_H
