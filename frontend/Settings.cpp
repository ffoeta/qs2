#include "Settings.hpp"

Settings::Settings(Superviser * superviser, Interface * father) :
    FATHER(father), superviser_(superviser)
{
    this -> init();

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(this->buttonsHolder_);
    layout->addWidget(this->formGroupBox_);

    this->setLayout(layout);
}

void Settings::init()
{
    initializeFormLines();
    initializeButtons();
}

void Settings::initializeFormLines()
{
    this->formGroupBox_ = new QGroupBox(tr("setup"));
    QFormLayout *layout = new QFormLayout;

    this->lineEdits_[0] = new QLineEdit(tr("3"));
    this->lineEdits_[1] = new QLineEdit(tr("3"));
    this->lineEdits_[2] = new QLineEdit(tr("3"));
    this->lineEdits_[3] = new QLineEdit(tr("10000"));
    this->lineEdits_[5] = new QLineEdit(tr("0"));
    this->lineEdits_[6] = new QLineEdit(tr("1"));
    this->lineEdits_[4] = new QLineEdit(tr("3"));

    layout->addRow(new QLabel(tr("Sources:")), this->lineEdits_[0]);
    layout->addRow(new QLabel(tr("Buffers:")), this->lineEdits_[1]);
    layout->addRow(new QLabel(tr("Devices:")), this->lineEdits_[2]);
    layout->addRow(new QLabel(tr("N packages:")), this->lineEdits_[3]);
    layout->addRow(new QLabel(tr("Source A:")), this->lineEdits_[5]);
    layout->addRow(new QLabel(tr("Source B:")), this->lineEdits_[6]);
    layout->addRow(new QLabel(tr("Device const:")), this->lineEdits_[4]);

    this->formGroupBox_->setLayout(layout);
}

void Settings::initializeButtons()
{
    this->buttonsHolder_ = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    set_ = new QPushButton(tr("set"));
    layout->addWidget(set_);
    connect(set_, &QPushButton::clicked, this, [this]() { this->__SET__();});

    back_ = new QPushButton(tr("go back"));
    layout->addWidget(back_);
    connect(back_, &QPushButton::clicked, this, [this]() { this->__BACK__();});

    buttonsHolder_->setLayout(layout);
}

void Settings::save() {
    int n_soruces = this->lineEdits_[0]->text().toInt();
    int n_buffers = this->lineEdits_[1]->text().toInt();
    int n_devices = this->lineEdits_[2]->text().toInt();
    int n_requests = this->lineEdits_[3]->text().toInt();
    double a = this->lineEdits_[4]->text().toDouble();
    double b = this->lineEdits_[5]->text().toDouble();
    double l = this->lineEdits_[6]->text().toDouble();

    this -> superviser_ -> set(n_soruces, n_buffers, n_devices, n_requests, a, b, l);
}

void Settings::__SET__() {
    this -> save();
    this -> FATHER -> __MENU__();
}

void Settings::__BACK__() {
    this -> FATHER -> __MENU__();
}