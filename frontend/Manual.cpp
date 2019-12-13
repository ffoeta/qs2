#include "Manual.hpp"
#include <iostream>

Manual::Manual(Superviser * superviser, Interface * father) :
    FATHER(father), superviser_(superviser)
{

    this->run_ = new QPushButton(tr("PRESS ME"));
    this->reboot_ = new QPushButton(tr("REBOOT"));
    this->back_ = new QPushButton(tr("BACK"));

    QGridLayout * layout = new QGridLayout();

    layout->addWidget(this->run_);
    layout->addWidget(this->reboot_);
    layout->addWidget(this->back_);

    connect(this->run_,
            &QPushButton::clicked, this, &Manual::__RUN__);

    connect(this->reboot_,
            &QPushButton::clicked, this, &Manual::__REBOOT__);

    connect(this->back_,
            &QPushButton::clicked, this, &Manual::__BACK__);

    this->setLayout(layout);
}

void Manual::__RUN__()
{   
    this -> superviser_ -> run();
}

void Manual::__REBOOT__()
{
    this -> superviser_ -> reboot();
}   

void Manual::__BACK__()
{
    this -> FATHER -> __MENU__();
}   
