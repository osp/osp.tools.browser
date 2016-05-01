#include "betterwebview.h"

BetterWebView::BetterWebView(QWidget *parent) : QWebView(parent)
{
    show();

    load(QUrl("http://localhost:8000/document"));
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
    QSizeF papersize( 618, 444 );

    printer.setOutputFormat( QPrinter::PdfFormat );
    printer.setPrintRange( QPrinter::AllPages );
    //printer.setResolution( QPrinter::HighResolution );
    printer.setResolution( 300 );
    printer.setPageMargins( 0,0,0,0, QPrinter::Millimeter );
    printer.setPaperSize( papersize, QPrinter::Millimeter );
    printer.setFullPage( true );
    printer.setFontEmbeddingEnabled( true );
    printer.setOutputFileName( filename );


    //float scalefactor = 72 / 96; // print resolution <> screen resolution
    //float scalefactor = 1280 / 10.23622; // screen width in pixels <> screen width in pt

    // Example of use of a painter, connected to a printer. But the scale doesn't seem to do anything here
    // QPainter painter;
    // painter.begin(&printer);
    // painter.scale(3, 3);
    // painter.setWindow(0,0,234 * scalefactor, 321 * scalefactor  );
    // painter.end();

    // From François: change la taille de la fenêtre, et la rend fixe
    //this->setFixedSize(printer.width() * scalefactor, printer.height() * scalefactor);
    // From François: change la taille du viewport
    //this->page()->setViewportSize(QSize(printer.width() * scalefactor, printer.height() * scalefactor));


    this->print( &printer );
}


void BetterWebView::reload() {
    qDebug() << "reload";
    this->QWebView::reload();
}


void BetterWebView::printDial() {
    qDebug() << "print dialog";

    QPrinter printer;
    QSizeF papersize( 234, 321 );

    printer.setOutputFormat( QPrinter::PdfFormat );
    printer.setPrintRange( QPrinter::AllPages );
    printer.setResolution( 300 );
    printer.setPageMargins( 0,0,0,0, QPrinter::Millimeter );
    printer.setPaperSize( papersize, QPrinter::Millimeter );
    printer.setFullPage( true );
    printer.setFontEmbeddingEnabled( true );
    printer.setOutputFileName( "/home/svilayphiou/_qt.pdf" );

    QPrintDialog *dialog = new QPrintDialog(&printer);
    if ( dialog->exec() == QDialog::Accepted)
          this->print(&printer);

}

