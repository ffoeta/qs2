#include "Buffers.hpp"

Buffer::Buffer() : package_(nullptr), n_of_source_(-1)
{};

Package  *   Buffer::package()
{
    return this -> package_;
}

void    Buffer::recievePackage(Package * package)
{
    this -> package_ = package;
    this -> n_of_source_ = package -> n_of_source_;
}
    
Package    *    Buffer::sendPackage()
{
    Package * temp = this -> package_;
    this -> package_ = nullptr;
    this -> n_of_source_ = -1;
    return temp;
}

bool Buffer::empty()
{
    return this->package_ == nullptr;
}

int Buffer::getN()
{
    return this -> n_of_source_;
}

//__________________________________________________________________
//__________________________________________________________________



Buffers::Buffers(Base * superviser, int n_of_buffers) : 
    superviser_(superviser), n_of_buffers_(n_of_buffers), last_(-1)
{
    for (int i = 0; i < n_of_buffers_; i++)
    {
        auto temp = new Buffer();
        buffers_.push_back(*temp);
    }
};

void Buffers::getTime(float time)
{
    this -> time_ = time;
}

//принять и расположить в ожидании
void Buffers::recivePackage(Package * package)
{
    if (this -> buffers_.at(n_of_buffers_-1).empty())
    {
        for (int i = 0; i < this -> n_of_buffers_; i++)
        {
            if (this -> buffers_.at(i).empty())
            {
                this -> buffers_.at(i).recievePackage(package);
                break;
            }
        }
    }
    else
    {
        this -> superviser_ ->droppPackage(this -> buffers_.at(this -> n_of_buffers_ - 1).sendPackage());
        this -> buffers_.at(this -> n_of_buffers_ - 1).recievePackage(package);
    }
}
    
Package * Buffers::sendPackage()
{
    int n_of_source = RAND_MAX;
    for (auto it = this -> buffers_.begin(); it != this -> buffers_.end(); it++ )
    {
        if (!it -> empty())
        {
            if (it -> package() -> n_of_source_ < n_of_source)
            {
                n_of_source = it -> package() -> n_of_source_;
            }
        }
    }


    int k = 0;

    for (auto it = this -> buffers_.begin(); it != this -> buffers_.end(); it++)
    {
        if (it -> getN() == n_of_source)
        {
            break;
        }
        k++;
    }

    auto temp = this -> buffers_.at(k).sendPackage();
    temp -> on_device_ = this -> time_;

    this -> buffers_.erase(this -> buffers_.begin() + k);
    buffers_.push_back(*(new Buffer()));

    return temp;
}

bool Buffers::ready() 
{
    for (auto it = this -> buffers_.begin(); it != this -> buffers_.end(); it++ )
    {
        if (!it -> empty()) 
        {
            return true;
        }
    }
    return false;
}

Picture Buffers::state()
{
    Picture res;

    for (auto it = buffers_.begin(); it != buffers_.end(); it++ )
    {
        if (it -> package() != nullptr)
        {
            res.add(it ->package() ->created_at_, it -> getN());
        }
    }

    return res;
}
    