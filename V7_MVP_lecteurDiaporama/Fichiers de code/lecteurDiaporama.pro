QT       += core gui
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choixdiaporama.cpp \
    choixvitessedefilement.cpp \
    fenetreapropos.cpp \
    creationdiaporama.cpp \
    main.cpp \
    lecteurvue.cpp \
    presentationlecteur.cpp \
    lecteur.cpp \
    diaporama.cpp \
    imagedansdiaporama.cpp \
    database.cpp

HEADERS += \
    choixdiaporama.h \
    choixvitessedefilement.h \
    fenetreapropos.h \
    creationdiaporama.h \
    lecteurvue.h \
    presentationlecteur.h \
    lecteur.h \
    diaporama.h \
    imagedansdiaporama.h \
    database.h

FORMS += \
    choixdiaporama.ui \
    choixvitessedefilement.ui \
    fenetreapropos.ui \
    creationdiaporama.ui \
    lecteurvue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
