#include "clicker.h"
#include "grassmanager.h"

Clicker::Clicker(int boostLevel) : PowerUp("Clicker", 5 * boostLevel), boostAmount(boostLevel) {}
void Clicker::activate() {
    GrassManager::addClickPower(boostAmount);
}
std::shared_ptr<PowerUp> Clicker::clone() const {
    return std::make_shared<Clicker>(*this);
}
