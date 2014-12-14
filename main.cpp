#include <QDebug>
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
    QString str = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    qDebug() << "QLibraryInfo::location(QLibraryInfo::TranslationsPath) = " << str; // /usr/share/qt/translations
#endif
///
    QTranslator qtTranslator;
    qtTranslator.load ("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);


/// TODO
//    QTranslator appTranslator;
//    appTranslator.load("jndqcbgrd_" + QLocale::system().name(), ":/translations");
//    app.installTranslator(&appTranslator);

    MainWindow w;
    w.show();

    return app.exec();
}
