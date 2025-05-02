#include "music.h"
#include "grassmanager.h"

Music::Music(std::function<void()> onMusicUnlocked)
    : PowerUp("Music", 5), onMusicUnlocked(onMusicUnlocked) {}

void Music::activate() {
    GrassManager::addPassiveIncome(5);
    if (onMusicUnlocked) {
        onMusicUnlocked();
    }
}

std::shared_ptr<PowerUp> Music::clone() const {
    return std::make_shared<Music>(onMusicUnlocked);
}
