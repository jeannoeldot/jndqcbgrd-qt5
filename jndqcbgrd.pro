#-------------------------------------------------
#
# Project created by QtCreator 2014-06-25T20:04:30
#
#-------------------------------------------------
isEmpty( PREFIX ){
 PREFIX =  /usr
}

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += printsupport

TEMPLATE = app

CONFIG += qt \
    warn_on

DEFINES += PREFIX=\"$${PREFIX}\"

TARGET = jndqcbgrd

SOURCES += main.cpp\
    mainwindow.cpp \
    creationcomptedlg.cpp \
    cmouvement.cpp \
    ccompte.cpp \
    testretourcreationdlg.cpp \
    previsionbudgetdlg.cpp \
    modificationnomdlg.cpp \
    entreesmouvementsdlg.cpp \
    entreeunmouvementdlg.cpp

HEADERS  += mainwindow.h \
    constantes.h \
    creationcomptedlg.h \
    miseaupoint.h \
    cmouvement.h \
    ccompte.h \
    testretourcreationdlg.h \
    previsionbudgetdlg.h \
    modificationnomdlg.h \
    entreesmouvementsdlg.h \
    entreeunmouvementdlg.h

FORMS    += mainwindow.ui \
    creationcomptedlg.ui \
    testretourcreationdlg.ui \
    previsionbudgetdlg.ui \
    modificationnomdlg.ui \
    entreesmouvementsdlg.ui \
    entreeunmouvementdlg.ui

RESOURCES += \
    jndqcbgrd.qrc

OTHER_FILES += \
    desktop/jndqcbgrd.desktop \
    desktop/jndqcbgrd.png \
    COPYING

# TODO
#TRANSLATIONS += jndqcbgrd_fr.ts

unix:!mac {
    binary.path += $${PREFIX}/bin/
    binary.files += jndqcbgrd
    pixmap.path +=  $${PREFIX}/share/pixmaps/
    pixmap.files +=  desktop/jndqcbgrd.png
    desktop.path +=  $${PREFIX}/share/applications/
    desktop.files +=  desktop/jndqcbgrd.desktop
    INSTALLS += binary \
                pixmap \
                desktop
}

DISTFILES += \
    README
