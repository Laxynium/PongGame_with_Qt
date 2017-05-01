#include "mainwindow.h"
#include <QWidget>
#include "Menus/mainmenu.h"
#include "Menus/settings.h"
#include "pausemenu.h"
#include "Game/game.h"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QAction>
#include <QKeyEvent>
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),mainMenu(new MainMenu(this)),
      settings(new Settings(this)),pauseMenu(new PauseMenu(this)),game(new Game(this))
{
    setBaseSize(640,480);
   // setFixedSize(640,480);
    widgets.addWidget(mainMenu);
    widgets.addWidget(settings);
    widgets.addWidget(game->getView());
    widgets.addWidget(pauseMenu);
    setCentralWidget(&widgets);
    //widgets.setCurrentWidget(game->getView());
    connectButtons();
    connectToGameSignals();
   }
MainWindow::~MainWindow()
{

}

void MainWindow::stopGame()
{
    widgets.setCurrentIndex(3);
}

void MainWindow::startGame()
{
    widgets.setCurrentIndex(2);
    game->startGame();
}

void MainWindow::restartGame()
{
    widgets.setCurrentIndex(2);
    game->restartGame();
}

void MainWindow::InitWindowsSizes()
{

}

void MainWindow::connectButtons()
{
    auto mainMenuUI=mainMenu->getUi();
    connect(mainMenuUI.quit_button,&QPushButton::clicked,[this](){QApplication::quit();});
    connect(mainMenuUI.settings_button,&QPushButton::clicked,[this](){widgets.setCurrentWidget(settings);});
    connect(mainMenuUI.start_button,&QPushButton::clicked,this,&MainWindow::restartGame);
    auto pauseMenuUI=pauseMenu->getUi();
    connect(pauseMenuUI.resume_button,&QPushButton::clicked,this,&MainWindow::startGame);
    connect(pauseMenuUI.restart_button,&QPushButton::clicked,this,&MainWindow::restartGame);
    connect(pauseMenuUI.backtomenu_button,&QPushButton::clicked,[this]{widgets.setCurrentIndex(0);});
    auto settingsUI=settings->getUi();
    connect(settingsUI.back_button,&QPushButton::clicked,[this](){widgets.setCurrentWidget(mainMenu);});
}

void MainWindow::connectToGameSignals()
{
    connect(game,&Game::gameStopped,this,&MainWindow::stopGame);
}
