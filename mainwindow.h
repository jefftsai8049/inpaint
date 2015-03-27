#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QColorDialog>
#include <QColor>
#include <QDebug>

#include "opencv.hpp"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QColor maskColor;
    cv::Mat src;
    cv::Mat mask;

private slots:
    void on_openFile_pushButton_clicked();

    void on_choosColor_epushButton_clicked();

    void on_inpaint_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
