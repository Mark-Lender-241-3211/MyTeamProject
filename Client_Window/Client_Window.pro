QT += core gui network widgets

QT += network

CONFIG += c++17

SOURCES += \
    authregform.cpp \
    carcalculationsform.cpp \
    clientapi.cpp \
    functions_to_client.cpp \
    main.cpp \
    mainwindow.cpp \
    menegerforms.cpp \
    new_pass_form.cpp \
    passwordhasher.cpp

HEADERS += \
    authregform.h \
    carcalculationsform.h \
    clientapi.h \
    functions_to_client.h \
    mainwindow.h \
    menegerforms.h \
    new_pass_form.h \
    passwordhasher.h

FORMS += \
    authregform.ui \
    carcalculationsform.ui \
    mainwindow.ui \
    new_pass_form.ui

RESOURCES += \
    image.qrc
