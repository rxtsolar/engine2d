#include "engine2d.h"
#include "debug.h"

#include <ctime>
#include <iostream>

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
    Mix_CloseAudio();
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
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        return false;

    screen = new GsImage(screenWidth, screenHeight);
    screen->setRoi(screenWidth/4, screenHeight/4,
                   screenWidth/2, screenHeight/2);

    image = GsImage("background.jpg");
    objects.push_back(GsObject(image));

    image = GsImage("foo.jpg");
    image.setColorKey(GsColor(0, 0xff, 0xff));
    image.enableColorKey();
    objects.push_back(GsObject(image));

    image = GsImage("sheet.jpg");
    image.setColorKey(GsColor(0, 0xff, 0xff));
    image.enableColorKey();
    objects.push_back(GsObject(image));

    sound.loadSound("jump.wav");

    music.loadMusic("tristram.mp3");

    SDL_WM_SetCaption("My Game", 0); 
    SDL_ShowCursor(0);
    return true;
}

void GsEngine2D::handle(void)
{
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = false;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_j)
                sound.play();
            if (event.key.keysym.sym == SDLK_m)
                music.play();
            if (event.key.keysym.sym == SDLK_p)
                music.toggle();
        }
    }
}

void GsEngine2D::update(void)
{
    int x = rand() % 200;
    int y = rand() % 200;

    screen->fillRoiWith(0xff, 0xff, 0xff);
    objects[0].setPosition(0, 0);
    objects[0].displayOn(*screen);
    objects[1].setPosition(x, y);
    objects[1].displayOn(*screen);
}

void GsEngine2D::render(void)
{
    if (SDL_Flip(screen->__getSurface()) == -1)
        gsBug("SDL_Flip failed");
}

void GsEngine2D::delay(void)
{
    SDL_Delay(1000 / fps * 30);
}

} // namespace gs
