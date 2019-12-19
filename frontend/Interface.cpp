#include "Interface.hpp"

#include "Auto.hpp"
#include "Manual.hpp"
#include "MainMenu.hpp"
#include "Settings.hpp"

Interface::Interface()
{
    this -> superviser_ = new Superviser();
    superviser_ -> set(3,3,3,100,0,1,3);

    // окна
    autoWidget_ = new Auto(superviser_, this);
    mainMenuWidget_ = new MainMenu(this);
    manualWidget_ = new Manual(superviser_, this);
    settingsWidget_ = new Settings(superviser_, this);

    //управление
    stackedWidget_ = new QStackedWidget(this);

    //добавляем виджеты 
    stackedWidget_->addWidget(autoWidget_);
    stackedWidget_->addWidget(mainMenuWidget_);
    stackedWidget_->addWidget(manualWidget_);
    stackedWidget_->addWidget(settingsWidget_);

    //выбираем текущий
    this -> __MENU__();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget_);
    this -> setLayout (layout);
}

void Interface::__MANUAL__()
{
    this -> manualWidget_ = new Manual(superviser_, this);
    stackedWidget_->addWidget(manualWidget_);
    this -> stackedWidget_ -> setCurrentWidget(manualWidget_);
}

void Interface::__MENU__()
{
    this -> stackedWidget_ -> setCurrentWidget(mainMenuWidget_);
}

void Interface::__AUTO__() 
{
    this -> autoWidget_ = new Auto(superviser_, this);
    stackedWidget_->addWidget(autoWidget_);
    this -> stackedWidget_ -> setCurrentWidget(autoWidget_);
}

void Interface::__SETTINGS__() 
{
    this -> stackedWidget_ -> setCurrentWidget(settingsWidget_);
}
