#include "grassmanager.h"

int GrassManager::s_grass = 0;
int GrassManager::s_passiveIncome = 0;
int GrassManager::s_clickPower = 1;

int GrassManager::getGrass() { return s_grass; }
void GrassManager::addGrass(int amount) { s_grass += amount; }
bool GrassManager::spendGrass(int amount) {
    if (s_grass >= amount) {
        s_grass -= amount;
        return true;
    }
    return false;
}
void GrassManager::addPassiveIncome(int amount) { s_passiveIncome += amount; }

int GrassManager::getClickPower() {return s_clickPower; }

void GrassManager::addClickPower(int amount) { s_clickPower += amount; }

int GrassManager::getPassiveIncome() {return s_passiveIncome; }
