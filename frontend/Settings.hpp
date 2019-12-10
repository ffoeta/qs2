#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "Interface.hpp"

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

class Settings : public QWidget
{
public:
    Settings(Superviser * superviser, Interface * father);
private:

    Interface * FATHER;

    Superviser * superviser_;

    void init();

    void __SET__();
    void __BACK__();

    void save();

    void initializeButtons();
    void initializeFormLines();
    
    QWidget *buttonsHolder_;

    QPushButton * set_;
    QPushButton * back_;

    QGroupBox *formGroupBox_;
    QLineEdit *lineEdits_[7];
};

#endif
