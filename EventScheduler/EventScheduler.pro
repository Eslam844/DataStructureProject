QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data-structure-project-main/BinaryTree.cpp \
    Data-structure-project-main/Database.cpp \
    Data-structure-project-main/Event.cpp \
    Data-structure-project-main/Time.cpp \
    Data-structure-project-main/btiterator.cpp \
    Data-structure-project-main/sqlite3.c \
    model.cpp \
    taskschdulerinterface.cpp \
    updateform.cpp \
    addform.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Data-structure-project-main/BinaryTree.h \
    Data-structure-project-main/Database.h \
    Data-structure-project-main/Event.h \
    Data-structure-project-main/Time.h \
    Data-structure-project-main/btiterator.h \
    Data-structure-project-main/sqlite3.h \
    model.h \
    taskschdulerinterface.h \
    updateform.h \
    addform.h \
    mainwindow.h

FORMS += \
    updateform.ui \
    addform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
