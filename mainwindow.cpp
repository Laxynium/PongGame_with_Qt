#include "mainwindow.h"
#include <QWidget>
#include "Menus/mainmenu.h"
#include "Menus/settings.h"
#include "Game/game.h"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QAction>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),mainMenu(new MainMenu),
      settings(new Settings()),game(new Game(this))
{
    setBaseSize(640,480);
   // setFixedSize(640,480);
    widgets.addWidget(mainMenu);
    widgets.addWidget(settings);
    widgets.addWidget(game->getView());
    setCentralWidget(&widgets);
    widgets.setCurrentWidget(game->getView());
    connectButtons();
   }
MainWindow::~MainWindow()
{

}

void MainWindow::InitWindowsSizes()
{

}

void MainWindow::connectButtons()
{
    auto mainMenuUI=mainMenu->getUi();
    connect(mainMenuUI.quit_button,&QPushButton::clicked,[this](){QApplication::quit();});
    connect(mainMenuUI.settings_button,&QPushButton::clicked,[this](){widgets.setCurrentWidget(settings);});
    connect(mainMenuUI.start_button,&QPushButton::clicked,[this](){/*TODO Write action*/;});
    auto settingsUI=settings->getUi();
    connect(settingsUI.back_button,&QPushButton::clicked,[this](){widgets.setCurrentWidget(mainMenu);});
}
