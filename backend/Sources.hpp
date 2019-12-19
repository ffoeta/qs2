#ifndef SOURCES_HPP
#define SOURCES_HPP

#include "Buffers.hpp"
#include "Package.hpp"
#include "Picture.hpp"
#include "Base.hpp"
#include <vector>

class Source
{
public:
    Source(int n_of_source, float a, float b);
    //  следующее событие на источнике
    float nextEvent();
    //  отправить пакет
    Package * package();
    // номер источника
    int getN();
private:
    //  расчеты
    float fx();
    //  номер источника
    int n_;
    //  константы
    float a_;
    float b_;
    //  пакет
    Package * package_;

    int counter_;
    float next_event_;
};

class Sources
{
public:
    Sources(Base * superviser, int n_of_sources, Buffers * buffers, float a, float b);
    //  следующее событие
    float nextEvent();
    //  снимок состояния
    Picture state();
    //создать пакет
    Package * package();
    //  номер источника
    int getN();
private:
    //  заявок создано
    std::vector<int> counter_;
    // смотритель
    Base * superviser_;
    // кол-во источников
    int n_of_sources_;
    // буфер
    Buffers * buffers_;
    //источники
    std::vector<Source> sources_;  
};



#endif
