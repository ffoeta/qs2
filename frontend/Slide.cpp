#include "Slide.hpp"
#include <iostream>


#define TOP_LEFT_X 10
#define TOP_LEFT_Y 10

#define TOP_MIDDLE_X 250
#define TOP_MIDDLE_Y 10

#define TOP_RIGHT_X 450
#define TOP_RIGHT_Y 10


#define SOURCE_WIDTH 120
#define SOURCE_HEIGHT 50

#define BUFFER_WIDTH 120
#define BUFFER_HEIGHT 50

#define DEVICE_WIDTH 120
#define DEVICE_HEIGHT 50


#define HEIGHT  300
#define WIDTH   600



#define D1 30
#define D2 50
#define D3 70






Slide::Slide(Picture sources, Picture buffers, Picture devices) :
    sources_(sources), buffers_(buffers), devices_(devices)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void Slide::presentSources()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    int delta = 0;

    int max = this -> sources_.size();

    if (max >= 5)
    {   
        delta = 20;
        for (int i = 0; i < 3; i++)
        {
            painter.drawRect(TOP_LEFT_X, TOP_LEFT_Y + i * 50 + delta, SOURCE_WIDTH, SOURCE_HEIGHT);
            auto n = QString::fromStdString(std::to_string(i));
            painter.drawText(TOP_LEFT_X + 25, TOP_LEFT_Y + i * 50 + 25 + delta,  n);


            if (this -> sources_.size() != 0)
            {
                auto str = std::to_string(this -> sources_.events.at(i));
                auto temp = QString::fromStdString(str);
                std::cout << this -> sources_.events.at(i) << std::endl;
                painter.drawText(TOP_LEFT_X + 45, TOP_LEFT_Y + i * 50 + 25 + delta,  temp);
            }
        }

        painter.drawRect(TOP_LEFT_X + D1, TOP_LEFT_Y + 210,   3,3);
        painter.drawRect(TOP_LEFT_X + D2, TOP_LEFT_Y + 210,   3,3);
        painter.drawRect(TOP_LEFT_X + D3, TOP_LEFT_Y + 210,   3,3);
        painter.drawRect(TOP_LEFT_X, TOP_LEFT_Y + 245,        SOURCE_WIDTH, SOURCE_HEIGHT);
    
        auto n = QString::fromStdString(std::to_string(sources_.size()-1));
        painter.drawText(TOP_LEFT_X + 25, TOP_LEFT_Y + 210 + 45 + delta,  n);

        if (this -> sources_.size() != 0)
        {
            auto str = std::to_string(this -> sources_.events.at(sources_.size()-1));
            auto temp = QString::fromStdString(str);
            std::cout << this -> sources_.events.at(sources_.size()-1) << std::endl;
            painter.drawText(TOP_LEFT_X + 45, TOP_LEFT_Y + 210 + 45 + delta,  temp);
        }
    } 
    else
    {
        delta = 70;
        for (int i = 0; i < this -> sources_.size(); i++)
        {
            painter.drawRect(TOP_LEFT_X, TOP_LEFT_Y + i * 50 + delta, SOURCE_WIDTH, SOURCE_HEIGHT);
            auto n = QString::fromStdString(std::to_string(i));
            painter.drawText(TOP_LEFT_X + 25, TOP_LEFT_Y + i * 50 + 25 + delta,  n);

            if (this -> sources_.size() != 0)
            {
                auto str = std::to_string(this -> sources_.events.at(i));
                auto temp = QString::fromStdString(str);
                std::cout << this -> sources_.events.at(i) << std::endl;
                painter.drawText(TOP_LEFT_X + 45, TOP_LEFT_Y + i * 50 + 25 + delta,  temp);
            }
        }
    }  
}

void Slide::presentBuffers()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    int delta = 0;

    int max = this -> buffers_.size();

    if (max >= 5)
    {   
        delta = 20;
        for (int i = 0; i < 3; i++)
        {
            painter.drawRect(TOP_MIDDLE_X, TOP_RIGHT_Y + i * 50 + delta, BUFFER_WIDTH, BUFFER_HEIGHT);
            auto n = QString::fromStdString(std::to_string(i));
            painter.drawText(TOP_MIDDLE_X + 25, TOP_MIDDLE_Y + i * 50 + 25 + delta,  n);


            if (this -> buffers_.size() != 0)
            {
                auto str = std::to_string(this -> buffers_.events.at(i));
                auto temp = QString::fromStdString(str);
                std::cout << this -> buffers_.events.at(i) << std::endl;
                painter.drawText(TOP_MIDDLE_X + 45, TOP_MIDDLE_Y + i * 50 + 25 + delta,  temp);
            }
        }

        painter.drawRect(TOP_MIDDLE_X + D1, TOP_MIDDLE_Y + 210,   3,3);
        painter.drawRect(TOP_MIDDLE_X + D2, TOP_MIDDLE_Y + 210,   3,3);
        painter.drawRect(TOP_MIDDLE_X + D3, TOP_MIDDLE_Y + 210,   3,3);
        painter.drawRect(TOP_MIDDLE_X, TOP_MIDDLE_Y + 245,        BUFFER_WIDTH, BUFFER_HEIGHT);
    
        auto n = QString::fromStdString(std::to_string(buffers_.size()-1));
        painter.drawText(TOP_MIDDLE_X + 25, TOP_MIDDLE_Y + 210 + 45 + delta,  n);

        if (this -> buffers_.size() != 0)
        {
            auto str = std::to_string(this -> buffers_.events.at(buffers_.size()-1));
            auto temp = QString::fromStdString(str);
            std::cout << this -> buffers_.events.at(buffers_.size()-1) << std::endl;
            painter.drawText(TOP_MIDDLE_X + 45, TOP_MIDDLE_Y + 210 + 45 + delta,  temp);
        }
    } 
    else
    {
        delta = 70;
        for (int i = 0; i < this -> buffers_.size(); i++)
        {
            painter.drawRect(TOP_MIDDLE_X, TOP_MIDDLE_Y + i * 50 + delta, BUFFER_WIDTH, BUFFER_HEIGHT);
            auto n = QString::fromStdString(std::to_string(i));
            painter.drawText(TOP_MIDDLE_X + 25, TOP_MIDDLE_Y + i * 50 + 25 + delta,  n);

            if (this -> buffers_.size() != 0)
            {
                auto str = std::to_string(this -> buffers_.events.at(i));
                auto temp = QString::fromStdString(str);
                std::cout << this -> buffers_.events.at(i) << std::endl;
                painter.drawText(TOP_MIDDLE_X + 45, TOP_MIDDLE_Y + i * 50 + 25 + delta,  temp);
            }
        }
    }     
}

void Slide::presentDevices()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    int delta = 0;

    int max = this -> devices_.size();

    if (max >= 5)
    {   
        delta = 20;
        for (int i = 0; i < 3; i++)
        {
            painter.drawRect(TOP_RIGHT_X, TOP_RIGHT_Y + i * 50 + delta, DEVICE_WIDTH, DEVICE_HEIGHT);
            auto n = QString::fromStdString(std::to_string(i));
            painter.drawText(TOP_RIGHT_X + 25, TOP_RIGHT_Y + i * 50 + 25 + delta,  n);


            if (this -> devices_.size() != 0)
            {
                auto str = std::to_string(this -> devices_.events.at(i));
                auto temp = QString::fromStdString(str);
                std::cout << this -> devices_.events.at(i) << std::endl;
                painter.drawText(TOP_RIGHT_X + 45, TOP_RIGHT_Y + i * 50 + 25 + delta,  temp);
            }
        }

        painter.drawRect(TOP_RIGHT_X + D1, TOP_RIGHT_Y + 210,   3,3);
        painter.drawRect(TOP_RIGHT_X + D2, TOP_RIGHT_Y + 210,   3,3);
        painter.drawRect(TOP_RIGHT_X + D3, TOP_RIGHT_Y + 210,   3,3);
        painter.drawRect(TOP_RIGHT_X, TOP_RIGHT_Y + 245,        DEVICE_WIDTH, DEVICE_HEIGHT);
    
        auto n = QString::fromStdString(std::to_string(devices_.size()-1));
        painter.drawText(TOP_RIGHT_X + 25, TOP_RIGHT_Y + 210 + 45 + delta,  n);

        if (this -> devices_.size() != 0)
        {
            auto str = std::to_string(this -> devices_.events.at(devices_.size()-1));
            auto temp = QString::fromStdString(str);
            std::cout << this -> devices_.events.at(devices_.size()-1) << std::endl;
            painter.drawText(TOP_RIGHT_X + 45, TOP_RIGHT_Y + 210 + 45 + delta,  temp);
        }
    } 
    else
    {
        delta = 70;
        for (int i = 0; i < this -> devices_.size(); i++)
        {
            painter.drawRect(TOP_RIGHT_X, TOP_RIGHT_Y + i * 50 + delta, DEVICE_WIDTH, DEVICE_HEIGHT);
            auto n = QString::fromStdString(std::to_string(i));
            painter.drawText(TOP_RIGHT_X + 25, TOP_RIGHT_Y + i * 50 + 25 + delta,  n);

            if (this -> devices_.size() != 0)
            {
                auto str = std::to_string(this -> devices_.events.at(i));
                auto temp = QString::fromStdString(str);
                std::cout << this -> devices_.events.at(i) << std::endl;
                painter.drawText(TOP_RIGHT_X + 45, TOP_RIGHT_Y + i * 50 + 25 + delta,  temp);
            }
        }
    }  
}

void Slide::paintEvent(QPaintEvent *event)
{
    this -> presentSources();
    this -> presentBuffers();
    this -> presentDevices();
}

