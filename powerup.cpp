#include "powerup.h"

PowerUp::PowerUp(const QString& name, int cost) : name(name), cost(cost) {}
QString PowerUp::getName() const { return name; }
int PowerUp::getCost() const { return cost; }
