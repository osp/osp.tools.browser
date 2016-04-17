#include "betterwebview.h"

BetterWebView::BetterWebView(QWidget *parent) : QWebView(parent)
{
    show();

    load(QUrl("http://localhost:8000/articles/ecolo/article.html"));
    page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
}

void BetterWebView::doPrint() {
    qDebug() << "print";

    QString filename = QFileDialog::getSaveFileName(
        this,
        tr("Save PDF"),
        QDir::currentPath(),
        tr("PDF files (*.pdf);All files (*.*)") );
    if( !filename.isNull() ) {
      qDebug() << filename;
    } else {
        return;
    }

    QPrinter printer;
    float scalefactor = 72 / 96.f; // print resolution <> screen resolution
    scalefactor = 1;
    QSizeF papersize( 578 * scalefactor, 748 * scalefactor );

    printer.setOutputFormat( QPrinter::PdfFormat );
    printer.setPrintRange( QPrinter::AllPages );
    printer.setResolution( QPrinter::HighResolution );
    printer.setPageMargins( 0,0,0,0, QPrinter::Point );
    printer.setPaperSize( papersize, QPrinter::Point );
    printer.setFullPage( true );
    printer.setFontEmbeddingEnabled( true );
    printer.setOutputFileName( filename );

    qDebug() << printer.supportedResolutions();

    //scalefactor = 72 / 96.f; // print resolution <> screen resolution

    //
    
//    this->setFixedSize(printer.width() * scalefactor, printer.height() * scalefactor);
//    this->page()->setViewportSize(QSize(printer.width() * scalefactor, printer.height() * scalefactor));
    this->print( &printer );
}

void BetterWebView::zoomIn() {

    qDebug() << "zoom in";
    this->setZoomFactor( this->zoomFactor() * 1.1 );

}

void BetterWebView::zoomOut() {

    qDebug() << "zoom out";
    this->setZoomFactor( this->zoomFactor() * 0.9 );

}
