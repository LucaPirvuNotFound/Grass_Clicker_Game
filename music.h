#ifndef MUSIC_H
#define MUSIC_H

#include "powerup.h"

class Music : public PowerUp {
public:
    Music(std::function<void()> onMusicUnlocked = nullptr);
    void activate() override;
    std::shared_ptr<PowerUp> clone() const override;

private:
    std::function<void()> m_onMusicUnlocked;
};

#endif
