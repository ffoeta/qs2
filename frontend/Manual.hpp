#ifndef MANUAL_HPP
#define MANUAL_HPP

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>
#include <QString>
#include <QVBoxLayout>

#include "Interface.hpp"
#include "Draw.hpp"

#include "../backend/Superviser.hpp"

class Manual : public QWidget
{
public:
    Manual(Superviser * superviser, Interface * father);
private:

    Interface * FATHER;

    Superviser * superviser_;

    void __RUN__();
    void __REBOOT__();
    void __BACK__();

    QPushButton *run_;
    QPushButton *back_;
    QPushButton *reboot_;
    QLabel      *label_;

};

#endif