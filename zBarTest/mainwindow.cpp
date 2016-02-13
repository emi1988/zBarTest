#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <zbar.h>
#include<iostream>

using namespace std;
using namespace zbar;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ImageScanner scanner;
    //scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
    scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);

    QImage qimage;
    bool imgLoaded = qimage.load("C:/Users/emi/Dropbox/projekts/qt/zBar_32bit/codePictures/qrCode3.png");

    if(imgLoaded == false)
    {
        qDebug() << "error loading image";
    }

    QImage convertedImage = qimage.convertToFormat(QImage::Format_Grayscale8,Qt::MonoOnly);

    int width = convertedImage.width();
    int height= convertedImage.height();


    unsigned char * data = convertedImage.bits();

    Image image(width, height, "Y800" , data, width*height);
  // Image image(width, height, "GRAY" , data, width*height);

    // scan the image for barcodes
    int n = scanner.scan(image);


    // extract results
    for(Image::SymbolIterator symbol = image.symbol_begin();
        symbol != image.symbol_end();
        ++symbol)
    {
        // do something useful with results
       qDebug() << "decoded " << QString::fromStdString(symbol->get_type_name())
             << " symbol \"" << QString::fromStdString(symbol->get_data()) << '"' << endl;
    }

    // clean up
    image.set_data(NULL, 0);

}

MainWindow::~MainWindow()
{
    delete ui;
}
