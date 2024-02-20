QT += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database/databasemanager.cpp \
    etudiant/etudiant.cpp \
    main.cpp \
    mainwindow\mainwindow.cpp \
    welcome/welcome.cpp

HEADERS += \
    database/databasemanager.h \
    etudiant/etudiant.h \
    mainwindow\mainwindow.h \
    welcome/welcome.h

FORMS += \
    etudiant/etudiant.ui \
    mainwindow\mainwindow.ui \
    welcome/welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
