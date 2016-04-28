#ifndef BETTERWEBVIEW_H
#define BETTERWEBVIEW_H

#include <QWidget>
//#include <QWebView>
//#include <QWebInspector>
//#include <QWebSettings>
#include <QtWebKitWidgets>
#include <QtDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPaintEngine>
#include <QFileDialog>
#include <QtDebug>



class BetterWebView : public QWebView {

Q_OBJECT

public:
    explicit BetterWebView(QWidget *parent = 0);

signals:

public slots:
    void doPrint();
    void reload();
    void printDial();
};

#endif // BETTERWEBVIEW_H
