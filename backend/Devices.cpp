#include "Devices.hpp"
#include <math.h>
#include <iostream>

Device::Device(float l) : 
    package_(nullptr), next_event_(RAND_MAX), l_(l)
{};

float Device::nextEvent() 
{
    return this -> next_event_;
};

void Device::takePackage(Package * package)
{
    this -> package_ = package;

    this -> package_ ->left_ = package_  -> on_device_ + fx();
    
    next_event_ = this -> package_ ->left_;
};

Package * Device::sendPackage()
{
    next_event_ = RAND_MAX;

    auto temp = this -> package_;
    this -> package_ = nullptr;

    return temp;
};

bool Device::empty()
{
    return this -> package_ == nullptr;
}

float Device::fx()
{
    return (-1.0 / this->l_*log(rand()/(double)RAND_MAX));
}

int Device::getN()
{
    return this -> package_ -> n_of_source_;
}


//__________________________________________________________________
//__________________________________________________________________


Devices::Devices(Base * superviser, int n_of_devices, Buffers * buffers, float l) : 
    superviser_(superviser), n_of_devices_(n_of_devices), current_(0)
{
    for (int i = 0; i < n_of_devices_; i++)
    {
        auto temp = new Device(l);
        devices_.push_back(*temp);
    }
};

void Devices::inc() 
{
	if (current_ + 1 == n_of_devices_)
	{
		current_ = 0;
	} else 
	{
		current_++;
	}
};

void Devices::dec() 
{
	if (current_ - 1 < 0) 
	{
		current_ = n_of_devices_-1;
	} else
	{
		current_--;
	}
}

//принять и распределить пакет
void Devices::takePackage(Package * package)
{
    do {
        inc();
    } while (!devices_.at(current_).empty());

    package -> n_of_device_ = current_;
    devices_.at(current_).takePackage(package);
    inc();
};

// обработать заявки
void Devices::foo()
{
    float event = this -> nextEvent();

    do {
        inc();
    } while (devices_.at(current_).nextEvent() != event);

    this -> counter_++;

    this -> superviser_ -> addPackage(devices_.at(current_).sendPackage());
}

// следующее событие 
float Devices::nextEvent() 
{
    float nextEvent = RAND_MAX;
    
    for (auto it = this -> devices_.begin(); it != this -> devices_.end(); it++ )
    {
        if (it -> nextEvent() < nextEvent) 
        {
            nextEvent = it -> nextEvent();
        }
    }
    std::cout << std::endl;
    return nextEvent;
};


//вернуть все что лежит на устройстве
Picture Devices::state()
{
    Picture res;

    for (auto it = devices_.begin(); it != devices_.end(); it++ )
    {
        if (!it -> empty())
        {
            res.add(it -> nextEvent(), it -> getN());
        }
    }

    return res;
}

//имются пакеты
bool Devices::ready()
{
    for (auto it = devices_.begin(); it != devices_.end(); it++ )
    {
        if (it -> empty())
        {
            return true;
        }
    }
    return false;
}


