// #include "../headers/Draw.hpp"

// #define TOP_LEFT_X 50
// #define TOP_LEFT_Y 50

// #define SOURCE_WIDTH 7
// #define SOURCE_HEIGHT 7

// #define BUFFER_WIDTH 7
// #define BUFFER_HEIGHT 7

// #define DEVICE_WIDTH 7
// #define DEVICE_HEIGHT 7

// Draw::Draw(int nSources, int nBuffers, int nDevices) :
//     nSources_(nSources), nBuffers_(nBuffers), nDevices_(nDevices)
// {
//     this->setGeometry(0, 0, 100 * 5, 50 * (nBuffers_ + nDevices_ + nSources_));
//     QPalette pal = palette();

//     pal.setColor(QPalette::Background, Qt::blue);
//     this->setAutoFillBackground(true);
//     this->setPalette(pal);
// }

// void Draw::paintEvent(QPaintEvent *event)
// {
//     QPainter painter(this);
//     painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
//     painter.drawRect(TOP_LEFT_X, TOP_LEFT_Y, 100, 80);

// }
