#include "frontend/Interface.hpp"

#include <QApplication>

int main( int argc, char **argv )
{
    std::srand(std::time(nullptr));
    QApplication app(argc, argv);

    Interface interface;
    interface.show();

    return app.exec();
}
