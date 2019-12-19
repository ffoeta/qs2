#ifndef DRAW_HPP
#define DRAW_HPP

#include <QWidget>
#include <QPainter>

#include <QGraphicsView>
#include <QGraphicsItemGroup>

#include <QRect>

#include <vector>
#include <string>

#include "../backend/Package.hpp"

class Draw : public QWidget
{
public:
    Draw(int nSources, int nBuffers, int nDevices);

    std::vector<QGraphicsItemGroup *> sources;
    std::vector<QGraphicsItemGroup *> buffers;
    std::vector<QGraphicsItemGroup *> devices;

    void addStep(Package * package);
private:

    int nSources_;
    int nBuffers_;
    int nDevices_;
protected:
    void paintEvent(QPaintEvent *event);
public slots:
};


#endif
