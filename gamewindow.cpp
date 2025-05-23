#include "gamewindow.h"
#include "grassmanager.h"
#include "powerupcounter.h"
#include "flower.h"
#include <QString>

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent),
    m_powerUpHandler([this]() {
        m_musicToggleButton->show();
    })
{
    setFixedSize(600, 500);
    setWindowTitle("Grass Clicker");

    m_grassButton = new QPushButton("Click Grass", this);
    m_grassButton->setGeometry(250, 150, 100, 50);
    connect(m_grassButton, &QPushButton::clicked, this, &GameWindow::onGrassButtonClicked);

    m_grassLabel = new QLabel("Grass: 0", this);
    m_grassLabel->setGeometry(250, 100, 200, 30);

    for (int i = 0; i < 4; ++i) {
        QPushButton* btn = new QPushButton(this);
        btn->setGeometry(50 + i * 130, 400, 120, 50);
        btn->hide();
        m_powerUpButtons.push_back(btn);
        connect(btn, &QPushButton::clicked, this, [this, i]() { onPowerUpClicked(i); });
    }

    m_uiTimer = new QTimer(this);
    m_uiPassiveTimer = new QTimer(this);
    connect(m_uiTimer, &QTimer::timeout, this, &GameWindow::addPassiveGrass);
    connect(m_uiPassiveTimer, &QTimer::timeout, this, &GameWindow::updateUI);
    m_uiTimer->start(1000); // updates every 1s
    m_uiPassiveTimer->start(500); //updates every 0.5s

    m_musicToggleButton = new QPushButton("Toggle Music", this);
    m_musicToggleButton->setGeometry(10, 10, 120, 30);
    m_musicToggleButton->hide(); // hidden by default
    connect(m_musicToggleButton, &QPushButton::clicked, this, &GameWindow::onMusicButtonToggled);

    /*m_powerUpHandler = m_powerUpHandler([this]() {
        m_musicToggleButton->show();
    });*/
    m_PowerUpLabel = new QLabel("Power-Ups Owned: 0", this);
    m_PowerUpLabel->setGeometry(450, 10, 150, 30);

    PowerUpCounter* powerUpCounter = new PowerUpCounter(m_PowerUpLabel);
    m_powerUpHandler.addObserver(powerUpCounter);

    std::shared_ptr<Flower<int>> debug = std::make_shared<Flower<int>>(5);
    debug->displayExtraInfo<std::string>("Hello");

    std::shared_ptr<Flower<float>> debug2 = std::make_shared<Flower<float>>(32.98);
    debug2->displayExtraInfo<int>(100);
    updatePowerUps();
}

GameWindow::~GameWindow() {}

void GameWindow::onGrassButtonClicked() {
    GrassManager::getInstance().addGrass(GrassManager::getInstance().getClickPower());
    updateGrassLabel();
}

void GameWindow::onPowerUpClicked(int index) {
    m_powerUpHandler.tryPurchase(index);
    updatePowerUps();
}

void GameWindow::updateGrassLabel() {
    m_grassLabel->setText("Grass: " + QString::number(GrassManager::getInstance().getGrass()));
    //updatePowerUps();
}

void GameWindow::updateUI() {
    m_grassLabel->setText("Grass: " + QString::number(GrassManager::getInstance().getGrass()));
    updatePowerUps();
}

void GameWindow::updatePowerUps() {
    const auto& active = m_powerUpHandler.getActivePowerUps();
    for (int i = 0; i < 4; ++i) {
        if (i < static_cast<int>(active.size())) {
            const auto& pu = active[i];
            m_powerUpButtons[i]->setText(pu->getName() + " (" + QString::number(pu->getCost()) + ")");
            m_powerUpButtons[i]->setEnabled(GrassManager::getInstance().getGrass() >= pu->getCost());
            m_powerUpButtons[i]->show();
        } else {
            m_powerUpButtons[i]->hide();
        }
    }

}

void GameWindow::addPassiveGrass() {
    GrassManager::getInstance().addGrass(GrassManager::getInstance().getPassiveIncome());
    updateGrassLabel();
}

void GameWindow::onMusicButtonToggled() {
    m_musicEnabled = !m_musicEnabled;
    m_musicToggleButton->setText(m_musicEnabled ? "Music: ON" : "Music: OFF");
}
