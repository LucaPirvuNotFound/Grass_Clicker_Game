#include "finisher.h"
#include <QMessageBox>
#include <QApplication>

Finisher::Finisher() : PowerUp("Finish Game", 10) {}
void Finisher::activate() {
    QMessageBox::information(nullptr, "Victory", "You finished the game!");
    QApplication::quit();
}
std::shared_ptr<PowerUp> Finisher::clone() const {
    return std::make_shared<Finisher>(*this);
}
