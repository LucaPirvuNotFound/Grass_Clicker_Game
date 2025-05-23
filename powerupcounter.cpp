#include "powerupcounter.h"

PowerUpCounter::PowerUpCounter(QLabel* label, QObject* parent)
    : QObject(parent), m_label(label) {
    if (m_label) {
        m_label->setText("Power-Ups Owned: 0");
    }
}

void PowerUpCounter::onPowerUpActivated() {
    ++m_count;
    if (m_label) {
        m_label->setText("Power-Ups Owned: " + QString::number(m_count));
    }
}
