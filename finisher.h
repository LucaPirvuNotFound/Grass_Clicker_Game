#ifndef FINISHER_H
#define FINISHER_H

#include "powerup.h"

class Finisher : public PowerUp {
public:
    Finisher();
    void activate() override;
    std::shared_ptr<PowerUp> clone() const override;
};

#endif
