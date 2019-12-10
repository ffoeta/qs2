#ifndef DEVICES_HPP
#define DEVICES_HPP

#include "Buffers.hpp"
#include "Package.hpp"

#include "Base.hpp"
#include <vector>


class Device
{
public:
    Device(float l);
    //  вернуть свое событиe
    float nextEvent();
    //  получить пакет
    void takePackage(Package * package);
    //  забрать пакет
    Package * sendPackage();
    //  номер источника пакета
    int getN();
    //  свободно
    bool empty();
private:
    //  смотритель
    Base * superviser_;
    //  расчеты
    float fx();
    //  константа
    float l_;
    //  пакет
    Package * package_;
    //  следующе событие на этом устройстве
    float next_event_;
};

class Devices
{
public:
    Devices(Base * superviser, int n_of_devices, Buffers * buffers, float l);
    //  собрать пакеты
    void foo();
    //  принять пакеты
    void takePackage(Package * package);
    //  выбрать следующее событие
    float nextEvent();
    //  вернуть заявки на утройствах
    std::vector<int> state();
    //  управление
    void inc();
    void dec();
    // проверить есть ли места
    bool ready();
private:
    //  смотритель
    Base * superviser_;
    //  указатель
    int current_;
    //  счетчик
    int counter_;
    //  кол-во устройств
    int n_of_devices_; 
    //  массив с устройствами 
    std::vector<Device> devices_;
};



#endif
