#ifndef AUTO_HPP
#define AUTO_HPP

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "Tables.hpp"

#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include "Interface.hpp"
#include "Tables.hpp"
#include "../backend/Superviser.hpp"

class Auto : public QWidget
{
public:
    Auto(Superviser * superviser, Interface * father);
private:

    Superviser * superviser_;

    Tables * tables_;

    Interface * FATHER;

    void __RUN__();
    void __REBOOT__();
    void __BACK__();

    QWidget *   buttonsHolder_;

    QPushButton *run_;
    QPushButton *reboot_;
    QPushButton *back_;

    
};

#endif
