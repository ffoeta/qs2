#ifndef DRAW_HPP
#define DRAW_HPP

#include <QWidget>
#include <QPainter>

#include <QGraphicsView>
#include <QGraphicsItemGroup>

#include <QRect>

#include <vector>
#include <string>

#include "../backend/Picture.hpp"
#include "../backend/Package.hpp"

class Slide : public QWidget
{
public:
    Slide(Picture sources, Picture buffers, Picture devices);
private:

    Picture sources_;
    Picture buffers_;
    Picture devices_;

    void presentSources();
    void presentBuffers();
    void presentDevices();

protected:
    void paintEvent(QPaintEvent *event);
};


#endif
