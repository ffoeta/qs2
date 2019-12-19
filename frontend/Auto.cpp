#include "Auto.hpp"
#include <iostream>

Auto::Auto(Superviser * superviser, Interface * father) :
    FATHER(father), superviser_(superviser)
{   
    QVBoxLayout *layout = new QVBoxLayout;

    auto sources_data = this -> superviser_ -> getSourcesData();
    auto devices_data = this -> superviser_ -> getDevicesData();

    this -> tables_ = new Tables(sources_data, devices_data);

    back_       = new QPushButton(tr("back"));
    reboot_     = new QPushButton(tr("reboot"));
    run_        = new QPushButton(tr("run"));

    this->buttonsHolder_ = new QWidget;

    QHBoxLayout *bLayout = new QHBoxLayout;

    bLayout->addWidget(back_);
    bLayout->addWidget(reboot_);
    bLayout->addWidget(run_);

    connect(this->back_,
        &QPushButton::clicked, this, &Auto::__BACK__);

    connect(this->reboot_,
        &QPushButton::clicked, this, &Auto::__REBOOT__);

    connect(this->run_,
        &QPushButton::clicked, this, &Auto::__RUN__);

    buttonsHolder_->setLayout(bLayout);

    layout -> addWidget(buttonsHolder_);
    layout -> addWidget(tables_);

    this -> setLayout(layout);
}

void Auto::__RUN__() {
    while (!this -> superviser_ -> over())
    {
        this -> superviser_ -> run();
    }

    auto sources_data = this -> superviser_ -> getSourcesData();
    auto devices_data = this -> superviser_ -> getDevicesData();
    
    auto temp = this -> tables_;

    this -> tables_ = new Tables(sources_data, devices_data);

    this ->layout()->addWidget(this->tables_);

    delete temp;  

    // for (int i = 0; i < sources_data.size(); i++)
    // {
    //     std::cout << "-------------------"      << std::endl;
    //     std::cout << "Source:            "      << sources_data.at(i).source    << std::endl;
    //     std::cout << "Created:           "      << sources_data.at(i).created   << std::endl;
    //     std::cout << "Failled:           "      << sources_data.at(i).failled   << std::endl;
    //     std::cout << "Average wait:      "      << sources_data.at(i).await     << std::endl;
    //     std::cout << "Average on device: "      << sources_data.at(i).adevice   << std::endl;
    //     std::cout << "-------------------"      << std::endl;
    // }
}

void Auto::__BACK__() {
    this -> FATHER -> __MENU__();
}

void Auto::__REBOOT__() {
    this -> superviser_ -> reboot();
}
