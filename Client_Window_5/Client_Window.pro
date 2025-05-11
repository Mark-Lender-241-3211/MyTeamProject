QT += core gui network widgets

QT += network

CONFIG += c++17

SOURCES += \
    authregform.cpp \
    carcalculationsform.cpp \
    clientapi.cpp \
    main.cpp \
    menegerforms.cpp \
    new_pass_form.cpp \
    passwordhasher.cpp

HEADERS += \
    authregform.h \
    carcalculationsform.h \
    clientapi.h \
    menegerforms.h \
    new_pass_form.h \
    passwordhasher.h

FORMS += \
    authregform.ui \
    carcalculationsform.ui \
    new_pass_form.ui

RESOURCES += \
    image.qrc

win32:RC_FILE = file.rc

TARGET = CarSpecific
