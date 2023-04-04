#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_draw_clicked();
    void star(QPainter *painter, int x, int y);
    void rect(QPainter *painter, int x, int y, int width,int height,QColor color);
    void threangle (QPainter *painter, QColor color, int x0,int y0, int x1,int y1, int x2,int y2);
    void house(QPainter *painter);
    void moon(QPainter *painter);
    void circle(QPainter *painter, int x, int y, int width,int height, QColor color);
    void rabbit(QPainter *painter);
    void pond(QPainter *painter);
    void swan(QPainter *painter, int x, int y);

//    // функция, которая вызывается каждый раз,
//    // когда программа перерисовывает интерфейс
//    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;

//    QImage *image = nullptr;    // указатель на изображние
};
#endif // MAINWINDOW_H
