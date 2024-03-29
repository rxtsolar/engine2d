#ifndef GS_ENGINE2D_H
#define GS_ENGINE2D_H

#include <vector>
#include "image.h"
#include "sound.h"
#include "timer.h"
#include "vect2.h"
#include "object.h"
#include "sprite.h"

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

    GsTimer timer;
    GsTimer fpsTimer;
    GsImage* screen;
    std::vector<GsAccObject*> objects;
    GsSound sound;
    GsMusic music;
    int focus;

    virtual bool init(void);
    virtual void handle(void);
    virtual void update(void);
    virtual void render(void);
};

} // namespace gs

#endif // GS_ENGINE2D_H
