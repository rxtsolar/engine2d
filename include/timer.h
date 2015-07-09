#ifndef GS_TIMER_H
#define GS_TIMER_H

namespace gs
{

class GsTimer {
public:
    GsTimer(void);
    GsTimer(const GsTimer& timer);
    virtual ~GsTimer(void);

    virtual GsTimer& operator=(const GsTimer& timer);

    virtual void start(void);
    virtual void stop(void);
    virtual void pause(void);
    virtual void resume(void);

    virtual int getTicks(void) const;

    virtual bool isStarted(void) const;
    virtual bool isPaused(void) const;

    virtual int __getStartTicks(void) const;
    virtual int __getPausedTicks(void) const;
protected:
    int startTicks;
    int pausedTicks;
    bool started;
    bool paused;
};

} // namespace gs

#endif // GS_TIMER_H
