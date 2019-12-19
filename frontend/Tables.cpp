#include "Tables.hpp"
#include <QGridLayout>

Tables::Tables(std::vector<Result> sources, std::vector<Result> devices) :
    sources_(sources), devices_(devices)
{

    auto mainLayout = new QGridLayout;

    int n_sources = sources_.size();
    int n_devices = devices_.size();

    this->tables[0] = new QTableWidget(n_sources, 6);

    for (int i = 0; i < n_sources; i++)
    {
        this->tables[0]->setItem(i, 0, new QTableWidgetItem(tr("%1").arg(sources_.at(i).created)));
        this->tables[0]->setItem(i, 1, new QTableWidgetItem(tr("%1").arg(sources_.at(i).failled)));
        this->tables[0]->setItem(i, 2, new QTableWidgetItem(tr("%1").arg(sources_.at(i).await)));
        this->tables[0]->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(sources_.at(i).adevice)));
        this->tables[0]->setItem(i, 4, new QTableWidgetItem(tr("%1").arg(0)));
        this->tables[0]->setItem(i, 5, new QTableWidgetItem(tr("%1").arg(0)));
    }
    this->tables[0]->setHorizontalHeaderLabels(
        QStringList() 
        << "Кол-во заявок"
        << "Кол-во отказов"
        << "Среднее время ожидания"
        << "Среднее время обработки"
        << "Дисперсия времени ожидания"
        << "Дисперсия времени обработки");

    mainLayout->addWidget(this->tables[0]);

    // Вторая таблица
    this->tables[1] = new QTableWidget(n_devices, 1);
    for (int i = 0; i < n_devices; i++)
    {
        this->tables[1]->setItem(i, 0, new QTableWidgetItem(tr("%1").arg("0")));
    } 

    this->tables[1]->setHorizontalHeaderLabels(QStringList() << "Коэф К");
    
    mainLayout->addWidget(this->tables[1]);

    this -> setLayout(mainLayout);
}
