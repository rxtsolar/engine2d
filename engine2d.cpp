#include "engine2d.h"
#include "debug.h"

#include <ctime>
#include <iostream>
#include <SDL/SDL_image.h>

using namespace std;

namespace gs
{

GsEngine2D::GsEngine2D(int argc, char** argv)
{
    if (!init())
        gsBug("init failed");
}

GsEngine2D::~GsEngine2D(void)
{
    delete screen;
    SDL_Quit();
}

void GsEngine2D::start(void)
{
    running = true;
    while (running) {
        handle();
        update();
        render();
        delay();
    }
}

bool GsEngine2D::init(void)
{
    GsImage image;
    srand(time(0));
    screenWidth = 1280;
    screenHeight = 720;
    fps = 30;
    running = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    screen = new GsImage(screenWidth, screenHeight);
    image = GsImage("background.jpg");
    images.push_back(image);
    image = GsImage("foo.jpg");
    image.setColorKey(0, 0xff, 0xff);
    image.enableColorKey();
    images.push_back(image);
    SDL_WM_SetCaption("My Game", 0); 
    SDL_ShowCursor(0);
    return true;
}

void GsEngine2D::handle(void)
{
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            running = false;
}

void GsEngine2D::update(void)
{
    int x = rand() % 200;
    int y = rand() % 200;
    screen->applySurface(0, 0, images[0]);
    screen->applySurface(x, y, images[1]);
}

void GsEngine2D::render(void)
{
    if (SDL_Flip(screen->getSurface()) == -1)
        gsBug("SDL_Flip failed");
}

void GsEngine2D::delay(void)
{
    SDL_Delay(1000 / fps * 30);
}

} // namespace gs
