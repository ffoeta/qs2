#include "MainMenu.hpp"

MainMenu::MainMenu(Interface * father) : 
    FATHER(father)
{
    init();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->buttonsHolder_);

    this->setLayout(layout);
}

void MainMenu::init()
{
    this->buttonsHolder_ = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    quit_ = new QPushButton(tr("quit"));    
    connect(quit_, &QPushButton::clicked, this, [this]() { this->__QUIT__();});

    settings_ = new QPushButton(tr("settings"));
    connect(settings_, &QPushButton::clicked, this, [this]() { this->__SETTINGS__();});

    manual_ = new QPushButton(tr("manual"));
    connect(manual_, &QPushButton::clicked, this, [this]() { this->__MANUAL__();});

    auto_ = new QPushButton(tr("auto"));
    connect(auto_, &QPushButton::clicked, this, [this]() { this->__AUTO__();});

    layout->addWidget(auto_);
    layout->addWidget(manual_);
    layout->addWidget(settings_);
    layout->addWidget(quit_);

    buttonsHolder_->setLayout(layout);
}

void MainMenu::__AUTO__() 
{
    this -> FATHER -> __AUTO__();
}

void MainMenu::__MANUAL__() 
{
    this -> FATHER -> __MANUAL__();
}

void MainMenu::__SETTINGS__() 
{
    this -> FATHER -> __SETTINGS__();
}

void MainMenu::__QUIT__() 
{
    exit(0);
}
