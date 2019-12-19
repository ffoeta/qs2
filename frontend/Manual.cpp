#include "Manual.hpp"
#include <iostream>

Manual::Manual(Superviser * superviser, Interface * father) :
    FATHER(father), superviser_(superviser)
{
    this -> draw_ = new Draw(this -> superviser_ -> getSource().size(),
                             this -> superviser_ -> getBuffer().size(),
                             this -> superviser_ -> getDevice().size());

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

void Manual::feed(std::vector<int> sources, std::vector<int> buffers, std::vector<int> devices)
{

}

void Manual::__RUN__()
{   
    this -> superviser_ -> run();
    this -> superviser_ -> getSource();
    this -> superviser_ -> getBuffer();
    this -> superviser_ -> getDevice();
}

void Manual::__REBOOT__()
{
    this -> superviser_ -> reboot();
}   

void Manual::__BACK__()
{
    this -> FATHER -> __MENU__();
}   
