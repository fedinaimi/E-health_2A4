QT       += core gui
QT+= sql
QT       +=printsupport
QT += charts
QT += datavisualization
QT += texttospeech
QT += multimedia
QT +=printsupport multimedia network
QT+= serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actemedicale.cpp \
    arduino.cpp \
    commande.cpp \
    connexion.cpp \
    facture.cpp \
    fournisseur.cpp \
    loginsystem.cpp \
    main.cpp \
    mainwindow.cpp \
    medicament.cpp \
    ordonnance.cpp \
    patient.cpp \
    produit.cpp \
    rendezvous.cpp \
    utilisateur.cpp

HEADERS += \
    actemedicale.h \
    arduino.h \
    commande.h \
    connexion.h \
    facture.h \
    fournisseur.h \
    loginsystem.h \
    mainwindow.h \
    medicament.h \
    ordonnance.h \
    patient.h \
    produit.h \
    rendezvous.h \
    utilisateur.h

FORMS += \
    loginsystem.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Resources/dddde.png \
    sources/docteur-medecine-tenant-comprime-couleur-capsule-dans-main-connexion-reseau-medical-icone-concept-reseau-technologie-medicale_34200-324.jpg \
    sources/logo.png
