#include "Package.hpp"

Package::Package(int n_of_source, int serial_number, float created_at) : 
    n_of_source_(n_of_source), serial_number_(serial_number), created_at_(created_at), 
    on_device_(-1), left_(-1), n_of_device_(-1)
{};
