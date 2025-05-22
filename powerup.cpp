#include "powerup.h"

PowerUp::PowerUp(const QString& name, int cost) : m_name(name), m_cost(cost) {}
QString PowerUp::getName() const { return m_name; }
int PowerUp::getCost() const { return m_cost; }
