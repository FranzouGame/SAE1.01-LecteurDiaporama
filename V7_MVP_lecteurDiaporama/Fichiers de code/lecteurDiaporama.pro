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
<<<<<<< HEAD
    creationdiaporama.cpp \
=======
>>>>>>> 677845e5397c578c4e4946ca8a9c75832ca041e8
    database.cpp \
    fenetreapropos.cpp \
    main.cpp \
    lecteurvue.cpp \
    modelelecteur.cpp \
    presentationlecteur.cpp \
    lecteur.cpp \
    diaporama.cpp \
    imagedansdiaporama.cpp

HEADERS += \
    choixdiaporama.h \
    choixvitessedefilement.h \
<<<<<<< HEAD
    creationdiaporama.h \
=======
>>>>>>> 677845e5397c578c4e4946ca8a9c75832ca041e8
    database.h \
    fenetreapropos.h \
    lecteurvue.h \
    modelelecteur.h \
    presentationlecteur.h \
    lecteur.h \
    diaporama.h \
    imagedansdiaporama.h

FORMS += \
    choixdiaporama.ui \
    choixvitessedefilement.ui \
<<<<<<< HEAD
    creationdiaporama.ui \
=======
>>>>>>> 677845e5397c578c4e4946ca8a9c75832ca041e8
    fenetreapropos.ui \
    lecteurvue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
