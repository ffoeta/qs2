#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <vector>

struct Picture
{
    Picture()
    {
        events = std::vector<float>(0);
        numbers = std::vector<int>(0);
    };
    void add(float time, int number)
    {
        events.push_back(time);
        numbers.push_back(number);
    };
    int size()
    {
        return this->events.size();
    };
    std::vector<float> events;
    std::vector<int>   numbers;
};

#endif
