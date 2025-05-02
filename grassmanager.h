#ifndef GRASSMANAGER_H
#define GRASSMANAGER_H

class GrassManager {
public:
    static int getGrass();
    static void addGrass(int amount);
    static bool spendGrass(int amount);
    static int getPassiveIncome();
    static void addPassiveIncome(int amount);
    static void addClickPower(int amount);
    static int getClickPower();

private:
    static int grass;
    static int passiveIncome;
    static int clickPower;
};

#endif
