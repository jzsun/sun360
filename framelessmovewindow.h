#ifndef FRAMELESSMOVEWINDOW_H
#define FRAMELESSMOVEWINDOW_H

#include <QMainWindow>
class QMouseEvent;
class QPoint;

class FramelessMoveWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FramelessMoveWindow(QWidget *parent = 0);
    ~FramelessMoveWindow();

private:
    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);
    void mouseMoveEvent(QMouseEvent * e);

    QPoint mMousePoint;
    bool mDragWindow;
};

#endif // FRAMELESSMOVEWINDOW_H
