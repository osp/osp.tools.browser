#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QtDebug>
#include <QHBoxLayout>
#include "betterwebview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    BetterWebView * bwv;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
