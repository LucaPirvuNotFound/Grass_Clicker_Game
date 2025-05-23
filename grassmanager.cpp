#include "grassmanager.h"

GrassManager::GrassManager() : m_grass(0), m_passiveIncome(0), m_clickPower(1) {}

GrassManager& GrassManager::getInstance() {
    static GrassManager instance;
    return instance;
}

int GrassManager::getGrass() const { return m_grass; }
void GrassManager::addGrass(int amount) { m_grass += amount; }
bool GrassManager::spendGrass(int amount) {
    if (m_grass >= amount) {
        m_grass -= amount;
        return true;
    }
    return false;
}
void GrassManager::addPassiveIncome(int amount) { m_passiveIncome += amount; }
int GrassManager::getPassiveIncome() const { return m_passiveIncome; }
void GrassManager::addClickPower(int amount) { m_clickPower += amount; }
int GrassManager::getClickPower() const { return m_clickPower; }
