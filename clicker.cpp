#include "clicker.h"
#include "grassmanager.h"

Clicker::Clicker(int boostLevel) : PowerUp("Clicker", 5 * boostLevel), m_boostAmount(boostLevel) {}
void Clicker::activate() {
    GrassManager::getInstance().addClickPower(m_boostAmount);
}
std::shared_ptr<PowerUp> Clicker::clone() const {
    return std::make_shared<Clicker>(*this);
}
