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
    void set(int n_of_sources, int n_of_buffers, int n_of_devices);
    void reboot();
    void run();

    void addPackage(Package * package) override;
    void droppPackage(Package * package) override;
    void createdPackage(int n) override;
    bool over() override;

    Picture getSource();
    Picture getBuffer();
    Picture getDevice();

    int getSourceN();
    int getBufferN();
    int getDeviceN();

    std::vector<float>  getWaitTime();
    std::vector<float>  getDeviceTime();
    std::vector<int>    getFaillCount();

    std::vector<Result> getSourcesData();
    std::vector<Result> getDevicesData();

private:
    Sources * sources_;
    Buffers * buffers_;
    Devices * devices_;

    int total_count_;
    int faill_;

    std::vector<float>  wait_time_;
    std::vector<float>  dev_time_;

    std::vector<int>    finished_per_source_;

    std::vector<int>    created_per_source_;

    std::vector<int>    failled_per_source_;

    int n_of_sources_;
    int n_of_buffers_;
    int n_of_devices_;

    int   max_packages_;
    int   a_;
    int   b_;
    int   l_;
    
    float source_event_;
    float device_event_;
};

#endif
