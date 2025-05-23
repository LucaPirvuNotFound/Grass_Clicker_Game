#ifndef POWERUPCOUNTER_H
#define POWERUPCOUNTER_H

#include <QObject>
#include <QLabel>
#include "poweruphandler.h"

class PowerUpCounter : public QObject, public PowerUpObserver {
    Q_OBJECT

public:
    explicit PowerUpCounter(QLabel* label, QObject* parent = nullptr);

    void onPowerUpActivated() override;

private:
    int m_count = 0;
    QLabel* m_label;
};

#endif // POWERUPCOUNTER_H
