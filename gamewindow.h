#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <vector>
#include "poweruphandler.h"

class GameWindow : public QMainWindow {
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void onGrassButtonClicked();
    void updateGrassLabel();
    void updatePowerUps();
    void updateUI();
    void onPowerUpClicked(int index);
    void addPassiveGrass();
    void onMusicButtonToggled();

private:
    QPushButton* grassButton;
    QPushButton* musicToggleButton;
    bool musicEnabled = false;
    QLabel* grassLabel;
    QTimer* uiTimer;
    QTimer* uiPassiveTimer;
    std::vector<QPushButton*> powerUpButtons;
    PowerUpHandler powerUpHandler;
};

#endif // GAMEWINDOW_H
