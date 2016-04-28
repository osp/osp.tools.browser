#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

//    ui->setupUi(this);
//    qDebug() << ui->centralWidget;

    bwv = new BetterWebView( this );
    setCentralWidget(bwv);

    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+P"), this );
    QObject::connect( shortcut, SIGNAL(activated()), bwv, SLOT( doPrint() ) );

    QShortcut *shortcut2 = new QShortcut(QKeySequence("Ctrl+R"), this );
    QObject::connect( shortcut2, SIGNAL(activated()), bwv, SLOT( reload() ) );

    QShortcut *shortcut3 = new QShortcut(QKeySequence("Ctrl+O"), this );
    QObject::connect( shortcut3, SIGNAL(activated()), bwv, SLOT( printDial() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}


