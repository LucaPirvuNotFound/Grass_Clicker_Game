#ifndef POWERUPHANDLER_H
#define POWERUPHANDLER_H

#include <vector>
#include <memory>
#include "powerup.h"

class PowerUpObserver {
public:
    virtual void onPowerUpActivated() = 0;
    virtual ~PowerUpObserver() = default;
};

class PowerUpHandler {
public:
    PowerUpHandler(std::function<void()> onMusicUnlocked = nullptr);
    void tryPurchase(int index);
    const std::vector<std::shared_ptr<PowerUp>>& getActivePowerUps() const;
    void addObserver(PowerUpObserver* observer);

private:
    std::vector<std::shared_ptr<PowerUp>> m_activePowerUps;
    std::vector<std::shared_ptr<PowerUp>> m_powerUpQueue;
    std::vector<std::shared_ptr<PowerUp>> m_purchasedPowerUps;
    std::vector<PowerUpObserver*> m_observers;
    std::function<void()> m_musicUnlockCallback;

    void generateNext();
    void notifyObservers();  // NEW
};

#endif
