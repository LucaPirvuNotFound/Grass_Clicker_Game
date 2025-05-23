#ifndef FLOWER_H
#define FLOWER_H

#include "grassmanager.h"
#include "powerup.h"
#include <memory>
#include <QDebug>

template<typename T>
class Flower : public PowerUp {
public:
    Flower(const T& value) : PowerUp("Flower", 10), m_value(value) {}

    void activate() override {
        GrassManager::getInstance().addPassiveIncome(static_cast<int>(m_value));
    }

    std::shared_ptr<PowerUp> clone() const override {
        return std::make_shared<Flower<T>>(*this);
    }

    template<typename U>
    void displayExtraInfo(const U& extra) const {
        qDebug() << "Flower power-up with value:" << m_value << "and extra info:" << extra;
    }

private:
    T m_value;
};


#endif
