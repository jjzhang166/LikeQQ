# Add more folders to ship with the application, here
folder_01.source = qml/LikeQQ
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

QT       += core gui network declarative quick qml opengl webkitwidgets sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=
RC_FILE = tiger.rc
# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    mainwidgetui.cpp \
    datainterface.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    mainwidgetui.h \
    datainterface.h \
    MyCmd.h

OTHER_FILES += \
    MyCmdJs.js \
    qml/LikeQQ/login/LineItem.qml \
    qml/LikeQQ/login/ITextShow.qml \
    ops.js

RESOURCES += \
    tiger.qrc
