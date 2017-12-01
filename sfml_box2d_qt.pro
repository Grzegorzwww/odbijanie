TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


win32 {


LIBS += -L"C:\Users\gwarchol-virtual\Documents\QT_Projekty\sfm_qt_lib\install\lib"
LIBS += -L"C:\Users\gwarchol-virtual\Documents\QT_Projekty\box2d_qt_lib\Box2D"
LIBS += -lBox2D

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "C:\Users\gwarchol-virtual\Documents\QT_Projekty\sfm_qt_lib\install\include"
DEPENDPATH += "C:\Users\gwarchol-virtual\Documents\QT_Projekty\sfm_qt_lib\install\include"

INCLUDEPATH += "C:\Users\gwarchol-virtual\Documents\QT_Projekty\box2d_qt_lib\include"
DEPENDPATH += "C:\Users\gwarchol-virtual\Documents\QT_Projekty\box2d_qt_lib\include"

}


unix{


LIBS += -L"/home/gwarchol/qt_workspace/SFML/lib"
LIBS += -L"/home/gwarchol/qt_workspace/box2d/lib"
LIBS += -lBox2D

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d


INCLUDEPATH += "/home/gwarchol/qt_workspace/SFML/include"
DEPENDPATH += "/home/gwarchol/qt_workspace/SFML/include"

INCLUDEPATH += "/home/gwarchol/qt_workspace/box2d/include"
DEPENDPATH += "/home/gwarchol/qt_workspace/box2d/include"

}






SOURCES += main.cpp \
    game.cpp \
    ball.cpp \
    player.cpp \
    ground.cpp \
    paletka.cpp \
    menu.cpp \
    colisioncollector.cpp

HEADERS += \
    defines.h \
    game.h \
    ball.h \
    player.h \
    ground.h \
    paletka.h \
    menu.h \
    colisioncollector.h

