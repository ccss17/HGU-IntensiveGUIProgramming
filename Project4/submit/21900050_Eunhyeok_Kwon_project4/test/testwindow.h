#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "mechanism/connectgame.h"
#include "graphics/connectboard.h"
#include "ai/ai1.h"

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>

namespace Ui {
class TestWindow;
}

class TestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);
    ~TestWindow();

private:
    Ui::TestWindow *ui;
    ConnectGame *connectGame;
    ConnectBoard *connectBoard;
    AI1 *ai1;

private slots:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // TESTWINDOW_H
