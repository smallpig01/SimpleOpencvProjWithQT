TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

include(../src/opencv320/OpenCV320.pri)
include(../src/MyPoint/MyPoint.pri)
