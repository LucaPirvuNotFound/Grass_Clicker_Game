#include "poweruphandler.h"
#include "grassmanager.h"
#include "flower.h"
#include "clicker.h"
#include "music.h"
#include "finisher.h"
#include <cstdlib>

PowerUpHandler::PowerUpHandler(std::function<void()> onMusicUnlocked)
    : m_musicUnlockCallback(onMusicUnlocked) {
    for (int i = 0; i < 9; ++i) {
        int r = rand() % 3;
        switch (r) {
        case 0: m_powerUpQueue.push_back(std::make_shared<Flower>()); break;
        case 1: m_powerUpQueue.push_back(std::make_shared<Clicker>()); break;
        case 2: m_powerUpQueue.push_back(std::make_shared<Music>(m_musicUnlockCallback)); break;
        }
    }
    m_powerUpQueue.push_back(std::make_shared<Finisher>()); // Always last
    generateNext();
}

void PowerUpHandler::tryPurchase(int index) {
    if (index < 0 || index >= static_cast<int>(m_activePowerUps.size())) return;

    auto& powerUp = m_activePowerUps[index];
    if (GrassManager::spendGrass(powerUp->getCost())) {
        powerUp->activate();
        m_activePowerUps.erase(m_activePowerUps.begin() + index);
        generateNext();
    }
}

const std::vector<std::shared_ptr<PowerUp>>& PowerUpHandler::getActivePowerUps() const {
    return m_activePowerUps;
}

void PowerUpHandler::generateNext() {
    while (m_activePowerUps.size() < 4 && !m_powerUpQueue.empty()) {
        m_activePowerUps.push_back(m_powerUpQueue.front());
        m_powerUpQueue.erase(m_powerUpQueue.begin());
    }
}
