QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authregform.cpp \
    functions_to_client.cpp \
    main.cpp \
    mainwindow.cpp \
    menegerforms.cpp

HEADERS += \
    authregform.h \
    functions_to_client.h \
    mainwindow.h \
    menegerforms.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    authregform.ui \
    mainwindow.ui

win32:RC_FILE = file.rc

RESOURCES += \
    image.qrc


