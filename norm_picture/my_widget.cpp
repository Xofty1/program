#include "my_widget.h"

my_widget::my_widget(QWidget *parent)
    : QWidget{parent}
{

}

void my_widget::paintEvent(QPaintEvent *event)
{
    if(image != nullptr)
    {
        QPainter *painter = new QPainter(this);

        painter->drawImage(0, 0, *image);

        painter->end();
    }

    event->accept();
}


void my_widget::setImageSize(int width, int height)
{
    if(image != nullptr)
    {
        delete image;
    }

    image = new QImage(width, height, QImage::Format_ARGB32_Premultiplied);
}
