#include "Auto.hpp"
#include <iostream>

Auto::Auto(Superviser * superviser, Interface * father) :
    FATHER(father), superviser_(superviser)
{   
    QVBoxLayout *layout = new QVBoxLayout;

    init();

    layout->addWidget(this->formGroupBox_);
    layout->addWidget(this->buttonsHolder_);

    this->setLayout(layout);

}

void Auto::init() {
    this->initializeButtons();
    this->initializeForm();
}



void Auto::initializeButtons() {
    this->buttonsHolder_ = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    back_ = new QPushButton(tr("back"));
    layout->addWidget(back_);

    reboot_ = new QPushButton(tr("reboot"));
    layout->addWidget(reboot_);

    run_ = new QPushButton(tr("run"));
    layout->addWidget(run_);


    connect(this->back_,
        &QPushButton::clicked, this, &Auto::__BACK__);

    connect(this->reboot_,
        &QPushButton::clicked, this, &Auto::__REBOOT__);

    connect(this->run_,
        &QPushButton::clicked, this, &Auto::__RUN__);

    buttonsHolder_->setLayout(layout);
}


void Auto::initializeForm() {
    this->formGroupBox_= new QWidget;
    QFormLayout *layout = new QFormLayout;

    prob_       = new QLabel();
    wait_       = new QLabel();
    device_     = new QLabel();
    system_     = new QLabel();

    layout->addRow(prob_);
    layout->addRow(wait_);
    layout->addRow(device_);
    layout->addRow(system_);

    formGroupBox_->setLayout(layout);
}

void Auto::__RUN__() {
    while (!this -> superviser_ -> over())
    {
        this -> superviser_ -> run();
    }
}

void Auto::__BACK__() {
    this -> FATHER -> __MENU__();
}

void Auto::__REBOOT__() {
    std::cout << "DISABLED" << std::endl;
}
