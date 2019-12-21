#ifndef BUFFERS_HPP
#define BUFFERS_HPP

#include "Package.hpp"
#include "Picture.hpp"
#include "Base.hpp"
#include <vector>
#include <iostream>

class Buffer
{
public:
    Buffer();
    //  пакет
    Package * package();
    //  получить и распределить пакет
    void recievePackage(Package * package);
    //  отдать пакет
    Package * sendPackage();
    //  пустой ли буфер
    bool empty();
    //  номер источника пакета
    int getN();
private:  
    //  номер пакета
    int n_of_source_;
    //  смотритель
    Base * superviser_;
    //  пакет
    Package * package_;
};

//__________________________________________________________________
//__________________________________________________________________


class Buffers
{
public:
    Buffers(Base * superviser, int n_of_buffers);
    //  положить заявку
    void recivePackage(Package * package);
    //  найдена дыра в i
    //  ее нужно устранить,
    void load(Package * package, int i);
    //  отдать заявку
    Package * sendPackage();
    //  есть ли в буфере заявки
    bool ready();
    //  заявки в буферах
    Picture state();
    //  получить время
    void getTime(float time);
private:
    //  время
    float time_;
    //  смотритель
    Base * superviser_;
    //  последний пришедший
    int last_;
    //  кол-во буферов
    int n_of_buffers_;
    //  буферы
    std::vector<Buffer> buffers_;
};




#endif
