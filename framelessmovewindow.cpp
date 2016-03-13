#include "framelessmovewindow.h"
#include <QMouseEvent>
#include <QPoint>

FramelessMoveWindow::FramelessMoveWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
}

FramelessMoveWindow::~FramelessMoveWindow()
{

}

void FramelessMoveWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mMousePoint = e->globalPos() - this->pos();
        e->accept();
        mDragWindow = true;
    }
}

void FramelessMoveWindow::mouseReleaseEvent(QMouseEvent */*e*/)
{
    mDragWindow = false;
}

void FramelessMoveWindow::mouseMoveEvent(QMouseEvent *e)
{
    //左键拖动的判断
    //左键拖动的判断一般放在mouseMoveEvent函数中，但是你不能向e->button() == Qt::LeftButton一样来判断，
    //因为当为鼠标指针移动事件时，e->button()返回值总是为QT::NoButton
    if (mDragWindow && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mMousePoint);
        e->accept();
    }
}

