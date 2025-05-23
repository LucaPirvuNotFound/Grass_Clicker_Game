#include "poweruphandler.h"
#include "grassmanager.h"
#include "flower.h"
#include "clicker.h"
#include "music.h"
#include "finisher.h"
#include "templateutils.h"
#include "powerupexception.h"
#include <cstdlib>

PowerUpHandler::PowerUpHandler(std::function<void()> onMusicUnlocked)
    : m_musicUnlockCallback(onMusicUnlocked) {
    for (int i = 0; i < 9; ++i) {
        int r = rand() % 3;
        switch (r) {
        case 0: m_powerUpQueue.push_back(std::make_shared<Flower<int>>(6.04));
            //std::shared_ptr<Flower<int>> debug = m_powerUpQueue[m_powerUpQueue.size() - 1];
            //debug->displayExtraInfo<std::string>("Hello");
            break;
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

    if (dynamic_cast<Music*>(powerUp.get()) != nullptr) {
        for (const auto& active : m_purchasedPowerUps) {
            if (dynamic_cast<Music*>(active.get()) != nullptr) {
                throw PowerUpException("Cannot activate multiple Music power-ups.");
            }
        }
    }

    if (GrassManager::getInstance().spendGrass(powerUp->getCost())) {
        try {
            activatePowerUp(powerUp);
            m_purchasedPowerUps.push_back(powerUp);
            m_activePowerUps.erase(m_activePowerUps.begin() + index);
            notifyObservers();
            generateNext();
        } catch (const PowerUpException& ex) {
            qDebug("PowerUp Exception: %s", ex.what());
        }
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

void PowerUpHandler::addObserver(PowerUpObserver* observer) {
    m_observers.push_back(observer);
}

void PowerUpHandler::notifyObservers() {
    for (auto observer : m_observers) {
        observer->onPowerUpActivated();
    }
}
