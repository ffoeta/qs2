#include "Superviser.hpp"

Superviser::Superviser() : 
    source_event_(-1), device_event_(-1), n_of_sources_(-1), 
    n_of_buffers_(-1), n_of_devices_(-1), max_packages_(-1),
    total_count_(0), faill_(0)
{
    this -> sources_ = nullptr;
    this -> buffers_ = nullptr;
    this -> devices_ = nullptr;
};

void Superviser::set(int n_of_sources, int n_of_buffers, int n_of_devices, int max_packages, float a, float b, float l)
{
    this -> n_of_sources_ = n_of_sources;
    this ->  n_of_buffers_ = n_of_buffers;
    this -> n_of_devices_ = n_of_devices;

    this -> max_packages_ = max_packages;
    this -> source_event_ = 0;
    this -> device_event_ = 0;

    this -> buffers_ = new Buffers(this, n_of_buffers);
    this -> sources_ = new Sources(this, n_of_sources,buffers_,a,b);
    this -> devices_ = new Devices(this, n_of_devices,buffers_,l);
}


void Superviser::run()
{
    this->source_event_ = sources_->nextEvent();
    this->device_event_ = devices_->nextEvent();

    std::cout << this -> source_event_ << std::endl;
    std::cout << this -> device_event_ << std::endl;

    

    if (this->device_event_ <= this->source_event_)
    {
        buffers_->getTime(device_event_);
        devices_->foo();
        if (buffers_->ready())
        {
            auto temp = buffers_ -> takeOut(); 
            devices_->takePackage(temp);
        }
    }
    else
    {   
        buffers_->getTime(source_event_);
        buffers_->placeIn(sources_->package());
        if (devices_->ready())
        {
            devices_->takePackage(buffers_ -> takeOut());
        }
    }
}

void Superviser::addPackage(Package * package) 
{
    this -> total_count_ ++;
}

void Superviser::droppPackage(Package * package)
{
    this -> faill_ ++;
}

bool Superviser::over()
{
    return this -> total_count_ > max_packages_;
}

std::vector<int> Superviser::getSource() 
{
    return this -> sources_ -> state();
}

std::vector<int> Superviser::getBuffer()
{
    return this -> buffers_ -> state();
}

std::vector<int> Superviser::getDevice()
{
    return this -> devices_ -> state();
}
