#include "music.h"
#include "grassmanager.h"

Music::Music(std::function<void()> onMusicUnlocked)
    : PowerUp("Music", 5), m_onMusicUnlocked(onMusicUnlocked) {}

void Music::activate() {
    GrassManager::addPassiveIncome(5);
    if (m_onMusicUnlocked) {
        m_onMusicUnlocked();
    }
}

std::shared_ptr<PowerUp> Music::clone() const {
    return std::make_shared<Music>(m_onMusicUnlocked);
}
