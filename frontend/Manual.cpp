#include "Manual.hpp"
#include <iostream>

Manual::Manual(Superviser * superviser, Interface * father) :
    FATHER(father), superviser_(superviser)
{
    Picture ns = this -> superviser_ -> getSource();
    Picture nb = this -> superviser_ -> getBuffer();
    Picture nd = this -> superviser_ -> getDevice();

    this -> slide_ = new Slide(ns, nb, nd);
    this -> slide_ -> setFixedSize(620,320);

    this->run_ = new QPushButton(tr("PRESS ME"));
    this->reboot_ = new QPushButton(tr("REBOOT"));
    this->back_ = new QPushButton(tr("BACK"));

    QGridLayout * layout = new QGridLayout();

    layout->addWidget(this->run_);
    layout->addWidget(this->reboot_);
    layout->addWidget(this->back_);
    layout->addWidget(this->slide_);

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

    auto temp = this -> slide_;
    this -> slide_ = new Slide( this -> superviser_ -> getSource(), 
                                this -> superviser_ -> getBuffer(), 
                                this -> superviser_ -> getDevice());
    this -> slide_ -> setFixedSize(620,320);

    this ->layout()->addWidget(this->slide_);

    delete temp;
}

void Manual::__REBOOT__()
{
    this -> superviser_ -> reboot();
}   

void Manual::__BACK__()
{
    this -> FATHER -> __MENU__();
}   
