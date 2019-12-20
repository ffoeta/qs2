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
    this -> n_of_sources_   = n_of_sources;
    this -> n_of_buffers_   = n_of_buffers;
    this -> n_of_devices_   = n_of_devices;

    this -> total_count_    = 0;
    this -> faill_          = 0;

    this -> wait_time_              .clear();
    this -> dev_time_               .clear();
    this -> failled_per_source_     .clear();
    this -> finished_per_source_    .clear();
    this -> created_per_source_     .clear();

    this ->sqr_wait_time_           .clear();
    this ->sqr_device_time_         .clear();

    for (size_t i = 0; i < n_of_sources_; i++)
    {
        this -> wait_time_.push_back(0);
        this -> dev_time_.push_back(0);
        this -> failled_per_source_.push_back(0);
        this -> finished_per_source_.push_back(0);
        this -> created_per_source_.push_back(0);

        this -> sqr_device_time_.push_back(0);
        this -> sqr_wait_time_.push_back(0);
    }

    for (size_t i = 0; i < n_of_devices; i++)
    {
        this -> device_total_time_.push_back(0);
    }
    

    this -> max_packages_   = max_packages;
    this -> a_ = a;
    this -> b_ = b;
    this -> l_ = l;

    this -> source_event_   = 0;
    this -> device_event_   = 0;

    this -> buffers_        = new Buffers(this, n_of_buffers);
    this -> sources_        = new Sources(this, n_of_sources,buffers_,a,b);
    this -> devices_        = new Devices(this, n_of_devices,buffers_,l);
}

void Superviser::set(int n_of_sources, int n_of_buffers, int n_of_devices)
{
    this -> n_of_sources_   = n_of_sources;
    this -> n_of_buffers_   = n_of_buffers;
    this -> n_of_devices_   = n_of_devices;

    this -> total_count_    = 0;
    this -> faill_          = 0;

    this -> wait_time_              .clear();
    this -> dev_time_               .clear();
    this -> failled_per_source_     .clear();
    this -> finished_per_source_    .clear();
    this -> created_per_source_     .clear();

    this ->sqr_wait_time_           .clear();
    this ->sqr_device_time_         .clear();

    for (size_t i = 0; i < n_of_sources_; i++)
    {
        this -> wait_time_.push_back(0);
        this -> dev_time_.push_back(0);
        this -> failled_per_source_.push_back(0);
        this -> finished_per_source_.push_back(0);
        this -> created_per_source_.push_back(0);
    }

    this -> source_event_   = 0;
    this -> device_event_   = 0;

    this -> buffers_        = new Buffers(this, n_of_buffers);
    this -> sources_        = new Sources(this, n_of_sources,buffers_,this -> a_, this -> b_);
    this -> devices_        = new Devices(this, n_of_devices,buffers_,this -> l_);
}


void Superviser::reboot()
{
    if (this -> sources_ != nullptr)
    {
        delete this -> sources_;
    }
    if (this -> buffers_ != nullptr)
    {
        delete this -> buffers_;
    }
    if (this -> devices_ != nullptr)
    {
        delete this -> devices_;
    }
    
    this -> set(n_of_sources_, n_of_buffers_, n_of_devices_, max_packages_, a_, b_, l_);
}


void Superviser::run()
{
    std::cout << total_count_ << std::endl;

    this->source_event_ = sources_->nextEvent();
    this->device_event_ = devices_->nextEvent();

    if (this->device_event_ <= this->source_event_)
    {
        buffers_->getTime(device_event_);
        devices_->foo();
        if (buffers_->ready())
        {
            auto temp = buffers_ -> sendPackage(); 
            devices_->takePackage(temp);
        }
    }
    else
    {   
        buffers_->getTime(source_event_);
        buffers_->recivePackage(sources_->package());
        if (devices_->ready())
        {
            devices_->takePackage(buffers_ -> sendPackage());
        }
    }
}

void Superviser::createdPackage(int n)
{   
    this -> total_count_++;
    this -> created_per_source_.at(n)++;
}

void Superviser::addPackage(Package * package) 
{
    this -> finished_per_source_.at(package->n_of_source_)++;

    this -> wait_time_.at(package->n_of_source_)        += (package->on_device_ - package -> created_at_);
    this -> dev_time_.at(package->n_of_source_)         += (package->left_ - package -> on_device_);

    this -> sqr_wait_time_.at(package->n_of_source_)    += 
        (package -> on_device_ - package ->created_at_) * (package -> on_device_ - package ->created_at_);
    this -> sqr_device_time_.at(package->n_of_source_)  +=
        (package -> left_ - package -> on_device_) * (package -> left_ - package -> on_device_);

    this -> device_total_time_.at(package->n_of_device_) += (package ->left_ - package ->on_device_);   
}

void Superviser::droppPackage(Package * package)
{
    this -> faill_++;
    // this -> wait_time_.at(package->n_of_source_)            += (package->on_device_ - package->created_at_);
    this -> failled_per_source_.at(package->n_of_source_)   ++;
}

bool Superviser::over()
{
    return this -> total_count_ > max_packages_;
}

Picture Superviser::getSource() 
{
    return this -> sources_ -> state();
}

Picture Superviser::getBuffer()
{
    return this -> buffers_ -> state();
}

Picture Superviser::getDevice()
{
    return this -> devices_ -> state();
}

float Superviser::getTime() 
{
    return this->device_event_>source_event_?device_event_:source_event_;
}

int Superviser::getSourceN()
{
    return this -> n_of_sources_;
}

int Superviser::getBufferN()
{
    return this -> n_of_buffers_;
}

int Superviser::getDeviceN()
{
    return this -> n_of_devices_;
}



std::vector<Result> Superviser::getSourcesData()
{
    std::vector<Result> res;
    for (int i = 0; i < n_of_sources_; i++)
    {
        res.push_back({ i, 
                        created_per_source_.at(i), 
                        failled_per_source_.at(i), 
                        this -> wait_time_.at(i)/this -> created_per_source_.at(i),
                        this -> dev_time_.at(i)/this->created_per_source_.at(i),
                        this -> sqr_wait_time_.at(i)/created_per_source_.at(i) - this -> wait_time_.at(i) * this -> wait_time_.at(i)/ 
                            (created_per_source_.at(i) * created_per_source_.at(i)),
                        this -> sqr_device_time_.at(i)/created_per_source_.at(i) - this -> dev_time_.at(i) * this -> dev_time_.at(i)/
                            (created_per_source_.at(i) * created_per_source_.at(i)),
                        (float) failled_per_source_.at(i) / created_per_source_.at(i) * 100,
                        0
        });
    }
    return res;
}

std::vector<Result> Superviser::getDevicesData()
{
    std::vector<Result> res;
    for (int i = 0; i < n_of_devices_; i++)
    {
        res.push_back({0,0,0,0,0,0,0,0,
            this -> device_total_time_.at(i)
        });
    }
    return res;
}