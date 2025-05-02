#ifndef FLOWER_H
#define FLOWER_H

#include "powerup.h"

class Flower : public PowerUp {
public:
    Flower();
    void activate() override;
    std::shared_ptr<PowerUp> clone() const override;
};

#endif
