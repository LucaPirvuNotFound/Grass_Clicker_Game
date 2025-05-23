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
    QPushButton* m_grassButton;
    QPushButton* m_musicToggleButton;
    bool m_musicEnabled = false;
    QLabel* m_grassLabel;
    QLabel* m_PowerUpLabel;
    QTimer* m_uiTimer;
    QTimer* m_uiPassiveTimer;
    std::vector<QPushButton*> m_powerUpButtons;
    PowerUpHandler m_powerUpHandler;
};

#endif // GAMEWINDOW_H
