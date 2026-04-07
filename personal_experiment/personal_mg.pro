QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpersondialog.cpp \
    #colleague.cpp \
    #friend.cpp \
    main.cpp \
    mainwindow.cpp \
    #modifypersondialog.cpp \
    page_login.cpp \
    person.cpp \
    person_factory.cpp \
    readfiledialog.cpp \
    registerdialog.cpp \
    #relative.cpp \
    #schoolfellow.cpp \
    showdialog.cpp

HEADERS += \
    addpersondialog.h \
    #colleague.h \
    #friend.h \
    mainwindow.h \
    #modifypersondialog.h \
    page_login.h \
    person.h \
    person_factory.h \
    readfiledialog.h \
    registerdialog.h \
    #relative.h \
    #schoolfellow.h \
    showdialog.h

FORMS += \
    addpersondialog.ui \
    mainwindow.ui \
    #modifypersondialog.ui \
    page_login.ui \
    readfiledialog.ui \
    registerdialog.ui \
    showdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    image/20210217235642_90671.jpeg \
    image/20210308191521_f8dda.jpeg
