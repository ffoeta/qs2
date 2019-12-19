#ifndef INTERFACE_AUTO_HPP
#define INTERFACE_AUTO_HPP

#include "../backend/Package.hpp"
#include <QWidget>
#include <QTableWidget>

class Tables : public QWidget
{
public:
    Tables(std::vector<Result> sources, std::vector<Result> devices);
private:
    std::vector<Result> sources_; 
    std::vector<Result> devices_;

    QTableWidget *tables[2];
};

#endif