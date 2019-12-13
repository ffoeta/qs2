#include "Sources.hpp"

#include <iostream>

Source::Source(int n_of_source, float a, float b) : 
    n_(n_of_source), package_(nullptr), next_event_(0), counter_(0), a_(a), b_(b)
{
    this -> package();
    counter_++;
};

float Source::nextEvent() 
{
    return this -> next_event_;
};

Package * Source::package()
{
    auto temp = this -> package_;

    next_event_ += this -> fx();    
    this -> package_ = new Package(n_, counter_, next_event_);

    return temp;
};

float Source::fx()
{
    return a_+(b_-a_)*(rand()%100)/100;
};

int Source::getN()
{
    return this -> n_;
};



//__________________________________________________________________
//__________________________________________________________________



Sources::Sources(Base * superviser, int n_of_sources, Buffers * buffers, float a, float b) : 
    superviser_(superviser), n_of_sources_(n_of_sources), buffers_(buffers)
{
    for (int i = 0; i < n_of_sources_; i++)
    {
        auto temp = new Source(i,a,b);
        sources_.push_back(*temp);
    }
};

Package * Sources::package()
{
    auto event = this -> nextEvent();

    for (auto it = this -> sources_.begin(); it != this -> sources_.end(); it++ )
    {
        if (it -> nextEvent() == event)
        {
            this -> superviser_ -> createdPackage(it ->getN());
            return it -> package();
        }
    }
    return nullptr;
}

float Sources::nextEvent() 
{
    float nextEvent = RAND_MAX;
    for (auto it = this -> sources_.begin(); it != this -> sources_.end(); it++ )
    {
        if (it -> nextEvent() < nextEvent) 
        {
            nextEvent = it -> nextEvent();
        }
    }
    return nextEvent;
};


std::vector<int> Sources::state()
{
    std::vector<int> res;

    for (auto it = sources_.begin(); it != sources_.end(); it++ )
    {
        res.push_back(it -> getN());
    }

    return res;
}
