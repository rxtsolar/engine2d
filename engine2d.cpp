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
    timer.stop();
    delete screen;
    Mix_CloseAudio();
    SDL_Quit();
}

void GsEngine2D::start(void)
{
    running = true;
    while (running) {
        fpsTimer.start();

        handle();
        update();
        render();

        if (fpsTimer.getTicks() < 1000 / fps)
            SDL_Delay(1000 / fps - fpsTimer.getTicks());
    }
}

bool GsEngine2D::init(void)
{
    GsImage image;
    GsSprite sprite;
    srand(time(0));
    screenWidth = 1280;
    screenHeight = 720;
    fps = GS_DEF_FPS;
    running = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        return false;

    screen = new GsImage(screenWidth, screenHeight);
    screen->setRoi(screenWidth/4, screenHeight/4,
                   screenWidth/2, screenHeight/2);

    image = GsImage("background.jpg");
    sprite.setImage(image);
    objects.push_back(new GsAccObject(sprite));

    image = GsImage("foo.jpg");
    image.setColorKey(GsColor(0, 0xff, 0xff));
    image.enableColorKey();
    sprite.setImage(image);
    objects.push_back(new GsAccObject(sprite));

    image = GsImage("sheet.jpg");
    image.setColorKey(GsColor(0, 0xff, 0xff));
    image.enableColorKey();
    sprite.setImage(image);
    sprite.setConfig(4, 2);
    objects.push_back(new GsAccObject(sprite));
    objects[2]->setPosition(400, 400);
    objects[1]->enableCollision();
    objects[2]->enableCollision();
    //objects[1]->setCapVelocity(4);
    //objects[2]->setCapVelocity(8);
    objects[1]->setDecelRate(0.3, 0.3);
    objects[2]->setDecelRate(0.1, 0.1);

    focus = 1;

    sound.loadSound("jump.wav");

    music.loadMusic("tristram.mp3");

    SDL_WM_SetCaption("My Game", 0);
    SDL_ShowCursor(0);

    timer.start();
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
            if (event.key.keysym.sym == SDLK_s)
                focus = !(focus - 1) + 1;
        }
    }
}

void GsEngine2D::update(void)
{
    Uint8* keyStates = SDL_GetKeyState(0);
    double ax = 0;
    double ay = 0;

    screen->fillRoiWith(0xff, 0xff, 0xff);
    objects[0]->setPosition(0, 0);
    objects[0]->displayOn(*screen);

    if (keyStates[SDLK_UP])
        ay = -2;
    else if (keyStates[SDLK_DOWN])
        ay = 2;
    else
        ay = 0;
    if (keyStates[SDLK_LEFT])
        ax = -2;
    else if (keyStates[SDLK_RIGHT])
        ax = 2;
    else
        ax = 0;
    objects[focus]->setAcceleration(ax, ay);
    objects[focus]->update(objects);
    objects[1]->displayOn(*screen);
    objects[2]->displayOn(*screen);
}

void GsEngine2D::render(void)
{
    if (SDL_Flip(screen->__getSurface()) == -1)
        gsBug("SDL_Flip failed");
}

} // namespace gs
