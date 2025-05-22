#ifndef POWERUPHANDLER_H
#define POWERUPHANDLER_H

#include <vector>
#include <memory>
#include "powerup.h"

class PowerUpHandler {
public:
    PowerUpHandler(std::function<void()> onMusicUnlocked = nullptr);
    void tryPurchase(int index);
    const std::vector<std::shared_ptr<PowerUp>>& getActivePowerUps() const;

private:
    std::vector<std::shared_ptr<PowerUp>> m_activePowerUps;
    std::vector<std::shared_ptr<PowerUp>> m_powerUpQueue;
    std::function<void()> m_musicUnlockCallback;
    void generateNext();
};

#endif
