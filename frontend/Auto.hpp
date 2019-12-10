#ifndef AUTO_HPP
#define AUTO_HPP

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "Interface.hpp"

#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include "../backend/Superviser.hpp"

class Auto : public QWidget
{
public:
    Auto(Superviser * superviser, Interface * father);
private:

    Superviser * superviser_;

    Interface * FATHER;

    void init();

    void initializeForm();
    void initializeButtons();

    void __RUN__();
    void __REBOOT__();
    void __BACK__();

    QWidget * buttonsHolder_;
    QWidget * formGroupBox_;
    
    QLabel  * prob_;
    QLabel  * wait_;
    QLabel  * device_;
    QLabel  * system_;

    QPushButton *run_;
    QPushButton *reboot_;
    QPushButton *back_;

    
};

#endif
