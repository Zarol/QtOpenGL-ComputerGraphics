#The type to build (application, library, subdirectories)
TEMPLATE = app  

#Directory of the executable / binary file
DESTDIR = ../bin/

#The name of the app / library
TARGET = Labyrinth.exe

#QT libraries this project uses
QT += core gui opengl
QT += multimedia

#Necessary for Qt5 and above
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Any external libraries this build uses
LIBS += -lassimp -lBulletDynamics -lBulletSoftBody -lBulletCollision -lLinearMath

#General project configuration options.
CONFIG += warn_on c++11

#Compiler flags
QMAKE_CXXFLAGS_WARD_ON += -Wall -pedantic

#Specifies the #include directories which should be searched when compiling the project.
INCLUDEPATH = ../src/ /usr/include/bullet

#A list of filenames of header (.h) files used when building the project.
HEADERS += \
    #3D
    ../src/3D/modelLoader.h \
    ../src/3D/renderable.h \
    ../src/3D/transform3d.h \
    ../src/3D/colorVertex.h \
    ../src/3D/uvVertex.h \
    #Controls
    ../src/Controls/camera3d.h \
    ../src/Controls/input.h \
    ../src/Controls/time.h \
    #Entity
    ../src/Entity/colorEntity.h \
    ../src/Entity/colorPhysicsEntity.h \
    ../src/Entity/uvEntity.h \
    ../src/Entity/uvPhysicsEntity.h \
    #Maze
    ../src/Maze/cell.h \
    ../src/Maze/labyrinth.h \
    ../src/Maze/mazeGenerator.h \
    ../src/Maze/ball.h \
    ../src/Maze/wall.h \
    #UI
    ../src/UI/mainWindow.h \
    ../src/UI/oglWidget.h \
    ../src/UI/titleWidget.h \
    ../src/UI/winWidget.h

#A list of source code files to be used when building the project.
SOURCES += \
    #3D
    ../src/3D/modelLoader.cpp \
    ../src/3D/transform3d.cpp \
    ../src/3D/colorVertex.cpp \
    ../src/3D/uvVertex.cpp \
    #Controls
    ../src/Controls/camera3d.cpp \
    ../src/Controls/input.cpp \
    ../src/Controls/time.cpp \
    #Entity
    ../src/Entity/colorEntity.cpp \
    ../src/Entity/colorPhysicsEntity.cpp \
    ../src/Entity/uvEntity.cpp \
    ../src/Entity/uvPhysicsEntity.cpp \
    #Maze
    ../src/Maze/cell.cpp \
    ../src/Maze/labyrinth.cpp \
    ../src/Maze/mazeGenerator.cpp \
    ../src/Maze/ball.cpp \    
    ../src/Maze/wall.cpp \
    #UI
    ../src/UI/mainWindow.cpp \
    ../src/UI/oglWidget.cpp \
    ../src/UI/titleWidget.cpp \
    ../src/UI/winWidget.cpp \
    #Main
    ../src/main.cpp

#A list of resource (.qrc / .rc) files to be included in the final project.
RESOURCES += \
    shader_resource.qrc
