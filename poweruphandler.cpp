#include "poweruphandler.h"
#include "grassmanager.h"
#include "flower.h"
#include "clicker.h"
#include "music.h"
#include "finisher.h"
#include <cstdlib>

PowerUpHandler::PowerUpHandler(std::function<void()> onMusicUnlocked)
    : musicUnlockCallback(onMusicUnlocked) {
    for (int i = 0; i < 9; ++i) {
        int r = rand() % 3;
        switch (r) {
        case 0: powerUpQueue.push_back(std::make_shared<Flower>()); break;
        case 1: powerUpQueue.push_back(std::make_shared<Clicker>()); break;
        case 2: powerUpQueue.push_back(std::make_shared<Music>(musicUnlockCallback)); break;
        }
    }
    powerUpQueue.push_back(std::make_shared<Finisher>()); // Always last
    generateNext();
}

void PowerUpHandler::tryPurchase(int index) {
    if (index < 0 || index >= static_cast<int>(activePowerUps.size())) return;

    auto& powerUp = activePowerUps[index];
    if (GrassManager::spendGrass(powerUp->getCost())) {
        powerUp->activate();
        activePowerUps.erase(activePowerUps.begin() + index);
        generateNext();
    }
}

const std::vector<std::shared_ptr<PowerUp>>& PowerUpHandler::getActivePowerUps() const {
    return activePowerUps;
}

void PowerUpHandler::generateNext() {
    while (activePowerUps.size() < 4 && !powerUpQueue.empty()) {
        activePowerUps.push_back(powerUpQueue.front());
        powerUpQueue.erase(powerUpQueue.begin());
    }
}
