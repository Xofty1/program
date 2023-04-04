#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: star(QPainter *painter, int x, int y)
{
    QPolygon polygon({QPoint(100+x, 90+y), QPoint(117+x, 120+y), QPoint(150+x, 120+y), QPoint(125+x, 140+y), QPoint(150+x, 180+y),QPoint(100+x, 150+y),QPoint(50+x, 180+y),QPoint(75+x, 140+y),QPoint(50+x, 120+y),QPoint(83+x, 120+y)});

//    painter->scale(0.5,0.5);
    int a = rand()%3800;
    int b = rand()%1300-100;

    for (int i = 0;i<10; i++)
    {
        polygon[i].rx()= (polygon[i].rx()+a)*0.5;
        polygon[i].ry()=(polygon[i].ry()+b)*0.5;
    }
//    if (polygon[1].rx()<1300 and polygon[1].rx()>780)
//    {
//        for (int i = 0;i<10; i++)
//        {

//            polygon[i].rx()+=450;
////            polygon[i].ry()+=400;
//        }
//    }
    //    if ((polygon[0].ry()<750 and polygon[0].ry()>250) and polygon[0].rx()<1300 and polygon[0].rx()>780)
    //         for (int i = 0;i<10; i++)
    //           {
    //             //polygon[i].ry()-=450;
    //             polygon[i].rx()+=450;}

    if ((polygon[0].rx()<1300 && polygon[0].rx()>780) && (polygon[0].ry()<750 && polygon[0].ry()>250))
    {
        for (int i = 0;i<10; i++)
        {

            polygon[i].rx()+=450;
//            polygon[i].ry()+=400;
        }
    }
    if (polygon[0].ry()> 0.75*polygon[0].rx()-660 and polygon[0].rx()>1000 and polygon[0].rx()<1200)
    {

        for (int i = 0;i<10; i++)
        {
            polygon[i].rx()-=610;
        }
    }

    if (polygon[0].ry()> -0.75*polygon[0].rx()+850 and polygon[0].rx()>800 and polygon[0].rx()<=1000)
    {

        for (int i = 0;i<10; i++)
        {
            polygon[i].rx()-=410;
        }
    }
//     painter->scale(0.5,0.5);
    QLinearGradient gradient(0, 0, 0, 255);
    gradient.setColorAt(0, Qt::yellow);
    gradient.setColorAt(1, Qt::red);
    QBrush brush(gradient);

    painter->setBrush(brush);
    painter->drawPolygon(polygon);
//    for (int i = 0;i<10; i++)
//    {
//        polygon[i].rx()-= a;
//        polygon[i].ry()-=b;
//    }
}

void MainWindow:: swan(QPainter *painter, int x, int y)
{
    painter->setPen(Qt::NoPen);
    circle(painter,570+x,725+y,80,40, QColor(255,250,251));//тело
    circle(painter,630+x,680+y,20,70, QColor(255,250,251));// шея
    circle(painter,645+x,620+y,30,15, QColor(255,250,251));//голова
    QPen *pen = new QPen;
    pen->setWidth(0);
    painter-> setPen(*pen);

    circle(painter,570+x,725+y,70,30, QColor(255,250,200));//крыло
    painter-> drawLine(500+x,725+y,570+x,725+y);
    painter-> drawLine(505+x,735+y,570+x,735+y);
    painter-> drawLine(505+x,715+y,570+x,715+y);

    threangle(painter,QColor(255, 102, 0), 670+x,610+y,670+x,630+y,690+x,620+y);//клюв
    circle(painter,637+x,613+y,3,3, QColor(0,0,0));//глаз
    delete pen;
    pen = nullptr;
}

void MainWindow:: rect(QPainter *painter, int x, int y, int width,int height, QColor color)
{
    QRect rectangle = QRect(x, y, width, height); //координаты (50,50), ширина 100, высота 50
    QBrush brush(color);
    painter->setBrush(brush); //задаем цвет заполнения
    painter->drawRect(rectangle); //рисуем прямоугольник
}

void MainWindow:: threangle(QPainter *painter,  QColor color, int x0,int y0, int x1,int y1, int x2,int y2)
{
    QBrush brush(color);
    painter-> setBrush(brush);
    QPoint points[3];
       points[0].setX(x0);
       points[0].setY(y0);

       points[1].setX(x1);
       points[1].setY(y1);

       points[2].setX(x2);
       points[2].setY(y2);

       painter->drawPolygon(points,3,Qt::OddEvenFill);

}

void MainWindow:: house(QPainter *painter)
{
    rect(painter, 800,300,400,400, QColor(205,133,63));// центральный квадрат дома
    rect(painter, 860,420, 100,100, QColor(218,165,32));// окно
    painter-> drawLine(910,420,910,520);//вертикальная полоска на окне
    painter-> drawLine(860,470,960,470);//горизонтальная полоска на окне
    rect(painter, 1000,450,150,250, QColor(205,133,0));// дверь
    threangle(painter,Qt::red,800,300,1200,300,1000,150);// крыша
}

void MainWindow:: moon(QPainter *painter)
{
    circle(painter,1700,150,100,100, QColor(128,128,128)); // луна
    rabbit(painter);
}

void MainWindow:: pond(QPainter *painter)
{
     circle (painter,450,800,300,60,QColor(0,0,111));
}

void MainWindow:: rabbit(QPainter *painter)
{
    circle (painter,1685,100,10,20,QColor(92,92,92));//левое ухо
    circle (painter,1715,100,10,20,QColor(92,92,92));// правое ухо
    circle (painter,1700,170,30,40,QColor(92,92,92));// тело
    circle (painter,1700,125,25,25,QColor(92,92,92));// голова
    circle (painter,1685,210,15,10,QColor(92,92,92));//левая нога
    circle (painter,1715,210,15,10,QColor(92,92,92));// правая нога
    circle (painter,1685,160,10,10,QColor(73,77,78));//левая лапа
    circle (painter,1715,160,10,10,QColor(73,77,78));// правая лапа
}

void MainWindow:: circle(QPainter *painter,int x, int y, int width,int height, QColor color)
{
    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawEllipse(QPointF(x, y), width, height);
}

void MainWindow::on_pushButton_draw_clicked()
{
    int w = ui->widget->width();
    int h = ui->widget->height();

    ui->widget->setImageSize(w, h);

    QImage *img = ui->widget->image;    // указатель на изображение, на котором рисует виджет

    QPainter *painter = new QPainter(img);

    QPen *pen = new QPen;
//    QPen pen(Qt::NoPen);
//    pen->setWidth(25);
//    pen->setColor(Qt::red);

//    painter->setPen(*pen);

//    int x = ui->lineEdit_x->text().toInt();
//    int y = ui->lineEdit_y->text().toInt();

//    painter->drawPoint(x, y);

//    pen-> setColor((QColor(255,0,0,255)));
//     pen->setWidth(5);
//     pen-> setStyle(Qt::DotLine);
//    pen-> setCapStyle(Qt::FlatCap);
//    painter->setPen(*pen);
//    painter-> drawLine(100,100,200,150);

//    pen-> setCapStyle(Qt::RoundCap);
//    painter->setPen(*pen);
//    painter-> drawLine(100,120,200,170);

//    pen-> setCapStyle(Qt::SquareCap);
//    painter->setPen(*pen);
//    painter-> drawLine(100,140,200,190);


//    pen -> setJoinStyle(Qt::RoundJoin);
//    pen-> setStyle(Qt::SolidLine);
//    painter->setPen(*pen);
//    painter-> drawLine(100,160,200,210);


//   QBrush brush;
//   brush.setStyle(Qt::SolidPattern);
//   brush.setColor(Qt::red);
//   painter->setBrush(brush);
//   pen-> setStyle(Qt::SolidLine);
//   pen -> setJoinStyle(Qt::RoundJoin);


//   QLinearGradient gradient(0, 0, 0, 50);
//   gradient.setColorAt(0, Qt::yellow);
//   gradient.setColorAt(1, Qt::red);
//   QBrush brush(gradient);
//   painter->setBrush(brush);




//   QPoint points[10];
//   points[0].setX(100);
//   points[0].setY(90);

//   points[1].setX(120);
//   points[1].setY(120);

//   points[2].setX(150);
//   points[2].setY(120);

//   points[3].setX(120);
//   points[3].setY(140);

//   points[4].setX(150);
//   points[4].setY(180);

//   points[5].setX(100);
//   points[5].setY(150);

//   points[6].setX(50);
//   points[6].setY(180);

//   points[7].setX(80);
//   points[7].setY(140);

//   points[8].setX(50);
//   points[8].setY(120);

//   points[9].setX(80);
//   points[9].setY(120);

//   QPolygon polygon({QPoint(100, 90), QPoint(120, 120), QPoint(150, 120), QPoint(120, 140), QPoint(150, 180),QPoint(100, 150),QPoint(50, 180),QPoint(80, 140),QPoint(50, 120),QPoint(80, 120)});
//   QLinearGradient gradient(0, 0, 0, 50);
//   gradient.setColorAt(0, Qt::yellow);
//   gradient.setColorAt(1, Qt::red);
//   QBrush brush(gradient);

//   painter->setBrush(brush);
//   painter->drawPolygon(polygon);
//    painter->drawPolygon(points,10,Qt::OddEvenFill);



//   QPolygon polygon({QPoint(100, 90), QPoint(120, 120), QPoint(150, 120), QPoint(120, 140), QPoint(150, 180),QPoint(100, 150),QPoint(50, 180),QPoint(80, 140),QPoint(50, 120),QPoint(80, 120)});
//   QLinearGradient gradient(0, 0, 0, 255);
//   gradient.setColorAt(0, Qt::yellow);
//   gradient.setColorAt(1, Qt::red);
//   QBrush brush(gradient);
    pen->setWidth(0);
    painter-> setPen(*pen);


//    star(painter);

//    pen->setWidth(50);
//    painter-> setPen(*pen);

    rect(painter, 0,0,1999,699, QColor(0,255,255));// небо
    bool flag;
    if (!ui-> lineEdit_x->text().isEmpty())
    {
        int n = ui->lineEdit_x->text().toInt(&flag);
    if (flag){
        for (int i = 0; i<n; i++)
        {

            star(painter,0,0);
        }
    }
    else {
        QMessageBox::information(this,"Ошибка","Некорректное количество звезд");
    }
    }
    rect(painter, 0,700,1999,299, Qt::green);// земля

    house(painter);


//    rect(painter, 800,300,400,400, QColor(205,133,63));// центральный квадрат дома
//    rect(painter, 860,420, 100,100, QColor(218,165,32));// окно
//    painter-> drawLine(910,420,910,520);//вертикальная полоска на окне
//    painter-> drawLine(860,470,960,470);//горизонтальная полоска на окне
//    rect(painter, 1000,450,150,250, QColor(205,133,0));// дверь
//    threangle(painter,Qt::red,800,300,1200,300,1000,150);// крыша

//    star(painter);

    moon(painter);
    pond(painter);
    swan(painter,0,0);
    swan(painter,-190,30);
//    circle(painter,500,555,300,300, Qt::red);
//   painter->setBrush(brush);
//   painter->drawPolygon(polygon);

//    QRect rectangle = QRect(0, 700, 999, 299); //координаты (50,50), ширина 100, высота 50
//    painter->setBrush(Qt::green); //задаем цвет заполнения
//    painter->drawRect(rectangle); //рисуем прямоугольник


    painter->end();

    ui->widget->repaint();

    // не забываем освободить память
    delete pen;
    delete painter;

    pen = nullptr;
    painter = nullptr;
}



