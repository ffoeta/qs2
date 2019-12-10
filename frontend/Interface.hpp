#ifndef INTERFACE_HPP
#define INTERFACE_HPP

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

#include "../backend/Superviser.hpp"


class Interface : public QWidget
{
public:
    Interface();

    void __MANUAL__();
    void __MENU__();
    void __AUTO__();
    void __SETTINGS__();

private:

    Superviser * superviser_;


    QStackedWidget * stackedWidget_;
    QWidget *autoWidget_;
    QWidget *mainMenuWidget_;
    QWidget *manualWidget_;
    QWidget *settingsWidget_;

};

#endif
