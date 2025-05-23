#include "music.h"
#include "grassmanager.h"
#include "powerupexception.h"

static bool musicAlreadyActivated = false;

Music::Music(std::function<void()> onMusicUnlocked)
    : PowerUp("Music", 5), m_onMusicUnlocked(onMusicUnlocked) {}

void Music::activate() {
    if (musicAlreadyActivated) {
        throw PowerUpException("Music power-up already activated!");
    }

    musicAlreadyActivated = true;

    // increase passive income
    GrassManager::getInstance().addPassiveIncome(5);

    // trigger music button
    if (m_onMusicUnlocked) {
        m_onMusicUnlocked();
    }
}
std::shared_ptr<PowerUp> Music::clone() const {
    return std::make_shared<Music>(m_onMusicUnlocked);
}
