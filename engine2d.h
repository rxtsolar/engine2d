#ifndef GS_ENGINE2D_H
#define GS_ENGINE2D_H

#include <SDL/SDL.h>
#include "image.h"

namespace gs
{

class GsEngine2D {
public:
    GsEngine2D(int argc, char** argv);
    virtual ~GsEngine2D(void);
    virtual void start(void);
protected:
    int screenWidth;
    int screenHeight;
    int fps;

    bool running;
    SDL_Event event;

    GsImage* screen;
    GsImage image;

    virtual bool init(void);
    virtual void handle(void);
    virtual void update(void);
    virtual void render(void);
    virtual void delay(void);
};

} // namespace gs

#endif // GS_ENGINE2D_H
