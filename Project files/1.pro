QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addform.cpp \
    adminform.cpp \
    deleteform.cpp \
    editform.cpp \
    forgetpass.cpp \
    main.cpp \
    mainwindow.cpp \
    memberform.cpp \
    rent.cpp \
    returnbook.cpp \
    searchform.cpp \
    searchincat.cpp \
    showall.cpp \
    signupform.cpp

HEADERS += \
    addform.h \
    adminform.h \
    book.h \
    deleteform.h \
    editform.h \
    forgetpass.h \
    mainwindow.h \
    memberform.h \
    rent.h \
    returnbook.h \
    searchform.h \
    searchincat.h \
    showall.h \
    signupform.h \
    users.h

FORMS += \
    addform.ui \
    adminform.ui \
    deleteform.ui \
    editform.ui \
    forgetpass.ui \
    mainwindow.ui \
    memberform.ui \
    rent.ui \
    returnbook.ui \
    searchform.ui \
    searchincat.ui \
    showall.ui \
    signupform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc


