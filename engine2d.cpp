#include "engine2d.h"

#include <SDL/SDL_image.h>
#include <ctime>
#include <iostream>

using namespace std;

namespace gs
{

GsEngine2D::GsEngine2D(int argc, char** argv)
{
    if (!init())
        exit(1);
}

GsEngine2D::~GsEngine2D(void)
{
    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
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

SDL_Surface* loadImage(const char* name)
{
    SDL_Surface* optimizedImage = 0;
    SDL_Surface* loadedImage = IMG_Load(name);
    if (!loadedImage)
        return 0;
    optimizedImage = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);
    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface* src, SDL_Surface* dst)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, 0, dst, &offset);
}

bool GsEngine2D::init(void)
{
    srand(time(0));
    screenWidth = 1280;
    screenHeight = 720;
    screenBPP = 32;
    fps = 30;
    running = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    screen = SDL_SetVideoMode(screenWidth, screenHeight,
                              screenBPP, SDL_SWSURFACE);
    if (!screen)
        return false;
    image = loadImage("preview2.jpg");
    if (!image)
        return false;
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
    applySurface(x, y, image, screen);
}

void GsEngine2D::render(void)
{
    if (SDL_Flip(screen) == -1)
        exit(1);
}

void GsEngine2D::delay(void)
{
    SDL_Delay(1000 / fps * 30);
}
} // namespace gs
