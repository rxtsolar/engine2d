#include "sprite.h"
#include "const.h"
#include "debug.h"

namespace gs
{

GsSprite::GsSprite(void)
{
    fps = GS_DEF_ANM_FPS;
    status = 0;
    frames = 0;
    slots = 0;
}

GsSprite::GsSprite(const GsSprite& sprite)
{
    *this = sprite;
}

GsSprite::~GsSprite(void)
{

}

GsSprite& GsSprite::operator=(const GsSprite& sprite)
{
    image = sprite.getImage();
    size = sprite.getSize();
    timer = sprite.getTimer();
    fps = sprite.getFps();
    status = sprite.getStatus();
    frames = sprite.getFrames();
    slots = sprite.getSlots();
    return *this;
}

void GsSprite::loadImage(const char* path)
{
    setImage(GsImage(path));
}

void GsSprite::setImage(const GsImage& image)
{
    this->image = image;
    this->image.resetRoi();
    size = this->image.getRoi().getSize();
    status = 0;
    frames = 1;
    slots = 1;
}

const GsImage& GsSprite::getImage(void) const
{
    return image;
}

void GsSprite::setTimer(const GsTimer& timer)
{
    this->timer = timer;
}

const GsTimer& GsSprite::getTimer(void) const
{
    return timer;
}

void GsSprite::setFps(int fps)
{
    this->fps = fps;
}

int GsSprite::getFps(void) const
{
    return fps;
}

void GsSprite::setSize(int w, int h)
{
    size = GsVect2i(w, h);
}

void GsSprite::setSize(const GsVect2i& size)
{
    this->size = size;
}

const GsVect2i& GsSprite::getSize(void) const
{
    return size;
}

void GsSprite::setStatus(int i)
{
    status = i;
}

void GsSprite::setConfig(int f, int s)
{
    frames = f;
    slots = s;
    calcSize();
}

int GsSprite::getStatus(void) const
{
    return status;
}

void GsSprite::setFrames(int n)
{
    frames = n;
    calcSize();
}

int GsSprite::getFrames(void) const
{
    return frames;
}

void GsSprite::setSlots(int s)
{
    slots = s;
    calcSize();
}

int GsSprite::getSlots(void) const
{
    return slots;
}

void GsSprite::setColorKey(const GsColor& ck)
{
    image.setColorKey(ck);
}

const GsColor& GsSprite::getColorKey(void) const
{
    return image.getColorKey();
}

void GsSprite::enableColorKey(void)
{
    image.enableColorKey();
}

void GsSprite::disableColorKey(void)
{
    image.disableColorKey();
}

void GsSprite::update(void)
{
    GsVect2i offsetX;
    GsVect2i offsetY;
    GsRect roi;
    if (!frames)
        return;
    if (!slots)
        gsBug("slots is zero");
    if (timer.isStarted() && timer.getTicks() < 1000 / fps)
        return;
    timer.start();
    status = (status + 1) % frames;
    offsetX = GsVect2i(size.getX(), 0) * (status % slots);
    offsetY = GsVect2i(0, size.getY()) * (status / slots);
    image.setRoi(GsRect(offsetX + offsetY, size));
}

void GsSprite::applySpriteOn(GsImage& image, int x, int y)
{
    image.applySurface(x, y, this->image);
}

void GsSprite::calcSize(void)
{
    GsRect roi;
    int row;
    int col;
    if (!frames || !slots)
        gsBug("frames or slots is zero");
    image.resetRoi();
    roi = image.getRoi();
    col = slots;
    row = (frames + slots - 1) / slots;
    size = GsVect2i(roi.getW() / col, roi.getH() / row);
}

} // namespace gs
