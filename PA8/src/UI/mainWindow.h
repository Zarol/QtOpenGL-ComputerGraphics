#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>

#include "oglWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    void createActions();
    void createMenus();
    void createMenuBar();

    OGLWidget* oglWidget;

    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionExitProgram;

    QMenu* interactionMenu;
	QAction* actionSphereMove;
	QAction* actionCylinderMove;
};

#endif  //  MAIN_WINDOW_H