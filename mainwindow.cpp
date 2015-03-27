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

void MainWindow::on_openFile_pushButton_clicked()
{
    QFileDialog OP;
    QString fileName = OP.getOpenFileName(this, tr("Open File"),"",tr("Images (*.bmp *.jpg)"));
//    if(fileName.isEmpty())
//        return;

    src = cv::imread(fileName.toStdString());
    cv::imshow("src",src);



}

void MainWindow::on_choosColor_epushButton_clicked()
{
    QColorDialog CD;
    maskColor = CD.getColor();
//    if(!maskColor.isValid())
//        return;

    cv::Mat src_HSV;
    cv::cvtColor(src,src_HSV,cv::COLOR_BGR2HSV);
    cv::Mat HSV[3];
    cv::split(src_HSV,HSV);
    cv::imshow("H",HSV[0]);
    cv::imshow("S",HSV[1]);
    cv::imshow("V",HSV[2]);


    mask.create(src.rows,src.cols,CV_8UC1);
    mask.zeros(src.rows,src.cols,CV_8UC1);
    //    cv::imshow("mask",mask);
    int range = 50;

    qDebug() << maskColor.hue()<< maskColor.saturation()<< maskColor.value();
    qDebug() << maskColor.hue()+range << maskColor.hue()-range << maskColor.saturation()+range <<maskColor.saturation()-range <<maskColor.value()+range<<maskColor.value()-range;
    for(int i = 0; i<src.rows ; i++)
    {
        for(int j = 0; j<src.cols; j++)
        {

            if(HSV[0].at<uchar>(i,j) < maskColor.hue()+range && HSV[0].at<uchar>(i,j) > maskColor.hue()-range)
            {

                if(HSV[1].at<uchar>(i,j) < maskColor.saturation()+range && HSV[1].at<uchar>(i,j) > maskColor.saturation()-range)
                {
                    if(HSV[2].at<uchar>(i,j) < maskColor.value()+range && HSV[2].at<uchar>(i,j) > maskColor.value()-range)
                    {

                        mask.at<uchar>(i,j) = 255;


                    }
                }
            }
            //            if(HSV[0].at<uchar>(i,j) <50 && HSV[1].at<uchar>(i,j) >200&&HSV[2].at<uchar>(i,j) >200)
            //            {
            //                mask.at<uchar>(i,j) = 255;
            //                qDebug() <<  HSV[0].at<uchar>(i,j) <<HSV[1].at<uchar>(i,j)<<HSV[2].at<uchar>(i,j);
            //            }

        }

    }
    cv::imshow("mask",mask);
    cv::imwrite("mask.bmp",mask);
}

void MainWindow::on_inpaint_pushButton_clicked()
{



    cv::Mat dst;
    cv::inpaint(src,mask,dst,5,cv::INPAINT_NS);
    cv::imwrite("yayaya.bmp",dst);
    cv::imshow("dst",dst);
}
