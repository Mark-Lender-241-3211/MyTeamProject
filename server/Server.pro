QT -= gui
INCLUDEPATH += "$$OpenSSL-Win64/include"
LIBS += -L"$$OpenSSL-Win64/lib" -llibeay32 -lssleay32
QT += network #Для работы с сетью
QT += sql # для базы данных

CONFIG += c++11 console
CONFIG -= app_bundle
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    carscalculator.cpp \
    main.cpp \
    mytcpserver.cpp \
    databasesingleton.cpp \
    passwordhasher.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    carscalculator.h \
    mytcpserver.h \
    databasesingleton.h \
    passwordhasher.h
