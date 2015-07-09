#include "timer.h"

#include <ctime>
#include <SDL/SDL.h>

namespace gs
{

GsTimer::GsTimer(void)
{
    startTicks = 0;
    pausedTicks = 0;
    started = false;
    paused = false;
}

GsTimer::GsTimer(const GsTimer& timer)
{
    *this = timer;
}

GsTimer::~GsTimer(void)
{

}

GsTimer& GsTimer::operator=(const GsTimer& timer)
{
    startTicks = timer.__getStartTicks();
    pausedTicks = timer.__getPausedTicks();
    started = timer.isStarted();
    paused = timer.isPaused();
    return *this;
}

void GsTimer::start(void)
{
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void GsTimer::stop(void)
{
    started = false;
    paused = false;
}

void GsTimer::pause(void)
{
    if (started && !paused) {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void GsTimer::resume(void)
{
    if (paused) {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

int GsTimer::getTicks(void) const
{
    if (!started)
        return 0;
    if (paused)
        return pausedTicks;
    else
        return SDL_GetTicks() - startTicks;
}

bool GsTimer::isStarted(void) const
{
    return started;
}

bool GsTimer::isPaused(void) const
{
    return paused;
}

int GsTimer::__getStartTicks(void) const
{
    return startTicks;
}

int GsTimer::__getPausedTicks(void) const
{
    return pausedTicks;
}

} // namespace gs
