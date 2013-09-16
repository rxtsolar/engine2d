#ifndef _ENGINE2D_H_
#define _ENGINE2D_H_

#include <SDL/SDL.h>

namespace gs
{

class Engine2D {
public:
    Engine2D(int argc, char** argv);
    virtual ~Engine2D(void);
    virtual void start(void);
protected:
    int screenWidth;
    int screenHeight;
    int screenBPP;
    int fps;

    bool running;
    SDL_Event event;

    SDL_Surface* screen;
    SDL_Surface* image;

    virtual bool init(void);
    virtual void handle(void);
    virtual void update(void);
    virtual void render(void);
    virtual void delay(void);
};

} // namespace gs

#endif // _ENGINE2D_H_
