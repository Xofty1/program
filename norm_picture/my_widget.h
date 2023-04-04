#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>

class my_widget : public QWidget
{
    Q_OBJECT
public:
    explicit my_widget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

public:
    QImage *image = nullptr;

    void setImageSize(int width, int height);   // функция, которая задаёт размеры изображения

};

#endif // MY_WIDGET_H
