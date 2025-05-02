#include "gamewindow.h"
#include "grassmanager.h"
#include <QString>

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(600, 500);
    setWindowTitle("Grass Clicker");

    grassButton = new QPushButton("Click Grass", this);
    grassButton->setGeometry(250, 150, 100, 50);
    connect(grassButton, &QPushButton::clicked, this, &GameWindow::onGrassButtonClicked);

    grassLabel = new QLabel("Grass: 0", this);
    grassLabel->setGeometry(250, 100, 200, 30);

    for (int i = 0; i < 4; ++i) {
        QPushButton* btn = new QPushButton(this);
        btn->setGeometry(50 + i * 130, 400, 120, 50);
        btn->hide();
        powerUpButtons.push_back(btn);
        connect(btn, &QPushButton::clicked, this, [this, i]() { onPowerUpClicked(i); });
    }

    uiTimer = new QTimer(this);
    uiPassiveTimer = new QTimer(this);
    connect(uiTimer, &QTimer::timeout, this, &GameWindow::addPassiveGrass);
    connect(uiPassiveTimer, &QTimer::timeout, this, &GameWindow::updateUI);
    uiTimer->start(1000); // updates every 1s
    uiPassiveTimer->start(500); //updates every 0.5s

    musicToggleButton = new QPushButton("Toggle Music", this);
    musicToggleButton->setGeometry(10, 10, 120, 30);
    musicToggleButton->hide(); // hidden by default
    connect(musicToggleButton, &QPushButton::clicked, this, &GameWindow::onMusicButtonToggled);

    powerUpHandler = PowerUpHandler([this]() {
        musicToggleButton->show();
    });

    updatePowerUps();
}

GameWindow::~GameWindow() {}

void GameWindow::onGrassButtonClicked() {
    GrassManager::addGrass(GrassManager::getClickPower());
    updateGrassLabel();
}

void GameWindow::onPowerUpClicked(int index) {
    powerUpHandler.tryPurchase(index);
    updatePowerUps();
}

void GameWindow::updateGrassLabel() {
    grassLabel->setText("Grass: " + QString::number(GrassManager::getGrass()));
    //updatePowerUps();
}

void GameWindow::updateUI() {
    grassLabel->setText("Grass: " + QString::number(GrassManager::getGrass()));
    updatePowerUps();
}

void GameWindow::updatePowerUps() {
    const auto& active = powerUpHandler.getActivePowerUps();
    for (int i = 0; i < 4; ++i) {
        if (i < static_cast<int>(active.size())) {
            const auto& pu = active[i];
            powerUpButtons[i]->setText(pu->getName() + " (" + QString::number(pu->getCost()) + ")");
            powerUpButtons[i]->setEnabled(GrassManager::getGrass() >= pu->getCost());
            powerUpButtons[i]->show();
        } else {
            powerUpButtons[i]->hide();
        }
    }
}

void GameWindow::addPassiveGrass() {
    GrassManager::addGrass(GrassManager::getPassiveIncome());
    updateGrassLabel();
}

void GameWindow::onMusicButtonToggled() {
    musicEnabled = !musicEnabled;
    musicToggleButton->setText(musicEnabled ? "Music: ON" : "Music: OFF");
}
