#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_spinBox_valueChanged(int arg1)// изменение колва строк
{
    ui-> tableWidget-> setRowCount(arg1);
}

void MainWindow::on_pushButton_SaveTXT_clicked() //сохранить в текстовом формате
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как txt"),"C:\\Users\\student.GIS\\Downloads\\", tr("Text files (*.txt)"));
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Ошибка", "Файл не выбран");
    }
    else
    {
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly);

        QString str;
        int size = ui-> spinBox-> value();
        str.setNum(size);
        str.append("\n");

        file.write(str.toUtf8());

        for (int i = 0; i< size; i++)
        {
            if (ui->tableWidget-> item(i,0) == nullptr)
            {
                QTableWidgetItem * ti ;
                ti = new QTableWidgetItem;
                ui-> tableWidget-> setItem(i,0,ti);

            }
            str =ui-> tableWidget-> item(i,0)-> text();
            str.append("\n");
            file.write(str.toUtf8());


        }
        file.close();

    }
}

void MainWindow::on_pushButton_OpenTXT_clicked()//считать из текстового формата
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Открыть txt"),"C:\\Users\\student.GIS\\Downloads\\", tr("Text files (*.txt)"));
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Ошибка", "Файл не выбран");
    }
    else
    {
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        QString str;
        int size;
        QByteArray ba;
        bool flag;
        ba = file.readLine();
        str.clear();
        str.append(ba);
        str.remove("\n");
        size = str.toInt(&flag);

        if (!flag)
        {
            QMessageBox::information (this,"Ошбка", "Неправильно");
        }

        else{
            ui-> spinBox-> setValue(size);



            for (int i = 0; i< size; i++)
            {
                if (ui->tableWidget-> item(i,0) == nullptr)
                {
                    QTableWidgetItem * ti ;
                    ti = new QTableWidgetItem;
                    ui-> tableWidget-> setItem(i,0,ti);

                }

                ba = file.readLine();
                str.clear();
                str.append(ba);
                str.remove("\n");
                ui-> tableWidget-> item(i,0)-> setText(str);


            }
        }
        file.close();




    }
}

void MainWindow::on_pushButton_SaveBIN_clicked()// Сохранить вв бинарном формате
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как bin"),"C:\\Users\\student.GIS\\Downloads\\", tr("Binary files (*.bin)"));
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Ошибка", "Файл не выбран");
    }
    else
    {
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly);

        char *mas;
        int size_int = sizeof(int);
        mas = new char [size_int];

        int size = ui-> spinBox-> value();
        memcpy (mas, &size, size_int);
        file.write (mas, size_int);




        for (int i = 0; i< size; i++)
        {
            if (ui->tableWidget-> item(i,0) == nullptr)
            {
                QTableWidgetItem * ti ;
                ti = new QTableWidgetItem;
                ui-> tableWidget-> setItem(i,0,ti);

            }
            int tmp = ui-> tableWidget-> item(i,0)-> text().toInt();
            memcpy (mas, &tmp, size_int);
            file.write(mas, size_int);



        }
        file.close();
        delete [] mas;

    }
}

void MainWindow::on_pushButton_OpenBIN_clicked()// открыть бин
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Открыть bin"),"C:\\Users\\student.GIS\\Downloads\\", tr("Binary files (*.bin)"));
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Ошибка", "Файл не выбран");
    }
    else
    {
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        char *mas;
        int size_int = sizeof(int);
        mas = new char [size_int];

        int size = ui-> spinBox-> value();
        file.read(mas,size_int);
        memcpy (&size,mas, size_int);


        if (file.size() != size_int*(size+1))
        {
            QMessageBox::information(this, "Ошибка", "Неправильно");
        }
        else{
            ui-> spinBox-> setValue(size);

            for (int i = 0; i< size; i++)
            {
                if (ui->tableWidget-> item(i,0) == nullptr)
                {
                    QTableWidgetItem * ti ;
                    ti = new QTableWidgetItem;
                    ui-> tableWidget-> setItem(i,0,ti);

                }
                int tmp;
                file.read(mas,size_int);
                memcpy (&tmp,mas, size_int);
                ui-> tableWidget-> item(i,0) -> setText(QString::number(tmp));



            }
        }


        file.close();
        delete [] mas;

    }

}
