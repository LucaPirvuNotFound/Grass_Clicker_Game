#include "grassmanager.h"

int GrassManager::grass = 0;
int GrassManager::passiveIncome = 0;
int GrassManager::clickPower = 1;

int GrassManager::getGrass() { return grass; }
void GrassManager::addGrass(int amount) { grass += amount; }
bool GrassManager::spendGrass(int amount) {
    if (grass >= amount) {
        grass -= amount;
        return true;
    }
    return false;
}
void GrassManager::addPassiveIncome(int amount) { passiveIncome += amount; }

int GrassManager::getClickPower() {return clickPower; }

void GrassManager::addClickPower(int amount) { clickPower += amount; }

int GrassManager::getPassiveIncome() {return passiveIncome; }
