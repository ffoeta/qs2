#ifndef PACKAGE_HPP
#define PACKAGE_HPP

struct Package
{
public:
    Package(int n_of_source, int serial_number, float created_at);

    int n_of_source_;
    int serial_number_;

    float created_at_;
    float on_device_;
    float left_;
};

struct Result
{
public:
    int source;
    int created;
    int failled;
    float await;
    float adevice;
};




#endif
