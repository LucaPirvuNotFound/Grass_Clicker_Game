#ifndef POWERUP_H
#define POWERUP_H

#include <QString>
#include <memory>

class PowerUp {
public:
    PowerUp(const QString& name, int cost);
    virtual ~PowerUp() = default;

    virtual void activate() = 0;
    virtual std::shared_ptr<PowerUp> clone() const = 0;

    QString getName() const;
    int getCost() const;

protected:
    QString name;
    int cost;
};

#endif
