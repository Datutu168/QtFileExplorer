#include "fileinfo.h"

fileInfo::fileInfo(QWidget *parent) :
    QWidget(parent)
{
    layout = new QVBoxLayout;

    commonName = new QString("Name: ");
    commonSize = new QString("Size: ");
    commonSizeEnd = new QString("");
    fontSize = new QString("font: 14pt;");

    name = new QLabel(*commonName+"No file chosen");
    size = new QLabel(*commonSize+"0");

    name->setStyleSheet(*fontSize);
    size->setStyleSheet(*fontSize);

    layout->addWidget(name);
    layout->addWidget(size);

    this->setLayout(layout);
}

void fileInfo::setName(QString nameIn){
    name->setText(*commonName+nameIn);
}

void fileInfo::setSize(int sizeIn){
    commonSizeEnd = new QString(" B");
    if (sizeIn > 1000) {
        sizeIn = sizeIn/1000;
        commonSizeEnd = new QString(" kB");
        if (sizeIn > 1000) {
            sizeIn = sizeIn/1000;
            commonSizeEnd = new QString(" mB");
            if (sizeIn > 1000) {
                sizeIn = sizeIn/1000;
                commonSizeEnd = new QString(" gB");
            }
        }

    }
    size->setText(*commonSize+QString::number(sizeIn)+*commonSizeEnd);
}