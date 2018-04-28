#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->filename = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(this->filename){
        delete [] this->filename;
    }
}

void MainWindow::test_af2mat(const char* filename)
{
    try{
        // loading grayscale image
        af::array input = af::loadImage(filename).as(u8);
        try{
            // converting af::array to cv::Mat
            cv::Mat output = Converter::af2mat(input);
            // displaying cv::Mat
            cv::imshow("Output in OPENCV",output);
        }
        catch(QString& errorString){
            qCritical() << errorString;
        }
    }
    catch(af::exception& exc){
        qDebug() << exc.what();
    }
}

void MainWindow::test_mat2af(const char* filename)
{
    try{
        // loading grayscale image
        cv::Mat input = cv::imread(filename,cv::IMREAD_GRAYSCALE);
        try{
            // converting cv::Mat to af::array
            af::array output = Converter::mat2af(input);
            // displaying af::array
            af::Window window(output.dims(1), output.dims(0), "Output in ARRAYFIRE");
            do{
                window.image(output);
            } while(!window.close());
        }
        catch(QString& errorString){
            qCritical() << errorString;
        }
    }
    catch(af::exception& exc){
        qDebug() << exc.what();
    }
}

void MainWindow::on_mat2af_clicked()
{
    if(this->filename){
        this->test_mat2af(this->filename);
    }
    else{
        qDebug() << "No filename, cannot open file";
    }

}

void MainWindow::on_af2mat_clicked()
{
    if(this->filename){
        this->test_af2mat(this->filename);
    }
    else{
        qDebug() << "No filename, cannot open file";
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(this->filename){
        delete [] this->filename;
        this->filename = nullptr;
    }
    QString str = QFileDialog::getOpenFileName(this,"Load image",".","*.tif *.png *.bmp *.jpg");
    this->filename = new char[str.length()+1];
    strcpy(filename,str.toStdString().c_str());
    QPixmap pixmap(str);
    ui->image->setPixmap(pixmap);
    if(!ui->af2mat->isEnabled()){
        ui->af2mat->setEnabled(true);
    }
    if(!ui->mat2af->isEnabled()){
        ui->mat2af->setEnabled(true);
    }
    ui->filename->setText(str);
    ui->width->setText(QString::number(pixmap.width())+" px");
    ui->height->setText(QString::number(pixmap.height())+" px");
}
