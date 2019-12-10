#include "Buffers.hpp"

Buffer::Buffer() : package_(nullptr), n_of_source_(-1)
{};

Package  *   Buffer::package()
{
    return this -> package_;
}

void    Buffer::placeIn(Package * package)
{
    this -> package_ = package;
    this -> n_of_source_ = package -> n_of_source_;
}
    
Package    *    Buffer::takeOut()
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
    std::cout << this -> time_ << "is." << std::endl;
}


void Buffers::placeIn(Package * package)
{
    auto temp = this -> current_;
    do
    {
        inc();
    } while ((!buffers_.at(current_).empty()) && (current_ != temp));

    if (current_ == temp)
    {
        this -> superviser_ -> droppPackage(buffers_.at(current_).takeOut());
    }

    buffers_.at(current_).placeIn(package);
    inc();
}
    
Package * Buffers::takeOut()
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
    auto temp = this -> buffers_.at(current_).takeOut();
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

std::vector<int> Buffers::state()
{
    std::vector<int> res;

    for (auto it = buffers_.begin(); it != buffers_.end(); it++ )
    {
        if (it -> empty())
        {
            res.push_back(-1);
            continue;
        }
        res.push_back(it -> getN());
    }

    return res;
}
    