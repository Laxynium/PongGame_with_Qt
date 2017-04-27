#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
class MainMenu;
class Settings;
class Game;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void InitWindowsSizes();
    void connectButtons();
private:
    QStackedWidget widgets;
    MainMenu*mainMenu=nullptr;
    Settings*settings=nullptr;
    Game*game=nullptr;
};

#endif // MAINWINDOW_H
