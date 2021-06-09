QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    forgetpass.cpp \
    main.cpp \
    mainwindow.cpp \
    memberform.cpp \
    signupform.cpp

HEADERS += \
    forgetpass.h \
    mainwindow.h \
    memberform.h \
    signupform.h \
    users.h

FORMS += \
    forgetpass.ui \
    mainwindow.ui \
    memberform.ui \
    signupform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc


