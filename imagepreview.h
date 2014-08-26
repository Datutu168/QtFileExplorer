#ifndef IMAGEPREVIEW_H
#define IMAGEPREVIEW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QShortcut>
#include <QScreen>
#include <QRect>

#include "mywindows.h"

class imagePreview : public QWidget
{
    Q_OBJECT
public:
    explicit imagePreview(QWidget *parent = 0);
    void showImage(QString path);
    void updateImage(QString path);
    void hidePreview();
    bool showing;
    void closeEvent(QCloseEvent *event);

signals:

public slots:

private:
    QVBoxLayout *layout;
    QLabel *image;
    QPixmap *im;
    QShortcut *shortcut;
};

#endif // IMAGEPREVIEW_H