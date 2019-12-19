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
    superviser_(superviser), n_of_buffers_(n_of_buffers), current_(0)
{
    for (int i = 0; i < n_of_buffers_; i++)
    {
        auto temp = new Buffer();
        buffers_.push_back(*temp);
    }
};

void Buffers::inc() 
{
	if (current_ + 1 == n_of_buffers_)
	{
		current_ = 0;
	} else 
	{
		current_++;
	}
};

void Buffers::dec() 
{
	if (current_ - 1 < 0) 
	{
		current_ = n_of_buffers_-1;
	} else
	{
		current_--;
	}
}

void Buffers::getTime(float time)
{
    this -> time_ = time;
}


void Buffers::recivePackage(Package * package)
{
    auto temp = this -> current_;
    do
    {
        inc();
    } while ((!buffers_.at(current_).empty()) && (current_ != temp));

    if (current_ == temp)
    {
        if (!buffers_.at(current_).empty())
        {
            this -> superviser_ -> droppPackage(buffers_.at(current_).sendPackage());
        }
    }

    buffers_.at(current_).recievePackage(package);
    inc();
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

    do
    {
        inc();
    } while (buffers_.at(current_).getN()  != n_of_source);

    auto temp = this -> buffers_.at(current_).sendPackage();
    temp -> on_device_ = this -> time_;
    
    inc();
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
    