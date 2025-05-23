#ifndef GRASSMANAGER_H
#define GRASSMANAGER_H

class GrassManager {
public:
    static GrassManager& getInstance();

    int getGrass() const;
    void addGrass(int amount);
    bool spendGrass(int amount);
    int getPassiveIncome() const;
    void addPassiveIncome(int amount);
    void addClickPower(int amount);
    int getClickPower() const;

private:
    GrassManager();

    int m_grass;
    int m_passiveIncome;
    int m_clickPower;
};

#endif
