#ifndef SUPERVISER_HPP
#define SUPERVISER_HPP

#include "Sources.hpp"
#include "Buffers.hpp"
#include "Devices.hpp"

#include "Base.hpp"

class Superviser : public Base
{
public:
    Superviser();

    void set(int n_of_sources, int n_of_buffers, int n_of_devices, int max_packages, float a, float b, float l);
    void run();

    void addPackage(Package * package) override;
    void droppPackage(Package * package) override;
    bool over() override;

    std::vector<int> getSource();
    std::vector<int> getBuffer();
    std::vector<int> getDevice();

private:
    Sources * sources_;
    Buffers * buffers_;
    Devices * devices_;

    int total_count_;
    int faill_;

    int n_of_sources_;
    int n_of_buffers_;
    int n_of_devices_;

    int   max_packages_;
    float source_event_;
    float device_event_;
};

#endif
