#ifndef CLICKER_H
#define CLICKER_H

#include "powerup.h"

class Clicker : public PowerUp {
public:
    Clicker(int boostlevel = 2);
    void activate() override;
    std::shared_ptr<PowerUp> clone() const override;

private:
    int boostAmount;
};

#endif
