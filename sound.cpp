#include "sound.h"
#include "debug.h"

namespace gs
{

GsSound::GsSound(void)
{
    sound = 0;
}

GsSound::GsSound(const char* path)
{
    sound = 0;
    loadSound(path);
}

GsSound::~GsSound(void)
{
    destroySound();
}

void GsSound::loadSound(const char* path)
{
    sound = Mix_LoadWAV(path);
    if (!sound)
        gsBug("Mix_LoadWAV");
}

void GsSound::destroySound(void)
{
    if (sound) {
        Mix_FreeChunk(sound);
        sound = 0;
    }
}

void GsSound::play(void)
{
    if (Mix_PlayChannel(-1, sound, 0) < 0)
        gsBug("Mix_PlayChannel");
}


GsMusic::GsMusic(void)
{
    music = 0;
}

GsMusic::GsMusic(const char* path)
{
    music = 0;
    loadMusic(path);
}

GsMusic::~GsMusic(void)
{
    destroyMusic();
}

void GsMusic::loadMusic(const char* path)
{
    music = Mix_LoadMUS(path);
    if (!music)
        gsBug("Mix_LoadWAV");
}

void GsMusic::destroyMusic(void)
{
    if (music) {
        Mix_FreeMusic(music);
        music = 0;
    }
}

void GsMusic::play(void)
{
    if (Mix_PlayMusic(music, -1) < 0)
        gsBug("Mix_PlayMusic");
}

void GsMusic::stop(void)
{
    Mix_HaltMusic();
}

void GsMusic::pause(void)
{
    if (!Mix_PlayingMusic())
        return;
    if (Mix_PausedMusic())
        return;
    Mix_PauseMusic();
}

void GsMusic::resume(void)
{
    if (!Mix_PlayingMusic())
        return;
    if (!Mix_PausedMusic())
        return;
    Mix_ResumeMusic();
}

void GsMusic::toggle(void)
{
    if (!Mix_PlayingMusic())
        return;
    if (Mix_PausedMusic())
        Mix_ResumeMusic();
    else
        Mix_PauseMusic();
}

} // namespace gs
