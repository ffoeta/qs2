#ifndef BASE_HPP
#define BASE_HPP

#include "Package.hpp"

class Base
{
public:
    virtual void addPackage(Package * package) = 0;
    virtual void droppPackage(Package * package) = 0;
    virtual void createdPackage(int n) = 0;
    virtual bool over() = 0;
};

#endif
