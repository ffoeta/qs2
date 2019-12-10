#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QStackedWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <iostream>

#include "Interface.hpp"

class MainMenu : public QWidget
{
public:
    MainMenu(Interface * father);
private:

    void init();
    
    Interface * FATHER;

    QWidget   *   buttonsHolder_;

    QPushButton * auto_;
    QPushButton * manual_;
    QPushButton * settings_;
    QPushButton * quit_;

    void __AUTO__();
    void __MANUAL__();
    void __SETTINGS__();
    void __QUIT__();

    // Настройка с двумя кнопками -> они переходят в автоматический режим или в ручной
};

#endif