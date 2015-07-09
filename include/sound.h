#ifndef GS_SOUND_H
#define GS_SOUND_H

#include <SDL/SDL_mixer.h>

namespace gs
{

class GsSound {
public:
    GsSound(void);
    GsSound(const char* path);
    virtual ~GsSound(void);

    virtual void loadSound(const char* path);
    virtual void destroySound(void);
    virtual void play(void);
protected:
    Mix_Chunk* sound;
};

class GsMusic {
public:
    GsMusic(void);
    GsMusic(const char* path);
    virtual ~GsMusic(void);

    virtual void loadMusic(const char* path);
    virtual void destroyMusic(void);
    virtual void play(void);
    virtual void stop(void);
    virtual void pause(void);
    virtual void resume(void);
    virtual void toggle(void);
protected:
    Mix_Music* music;
};

} // namespace ge

#endif // GS_SOUND_H
