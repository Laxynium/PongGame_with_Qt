#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
class MainMenu;
class Settings;
class PauseMenu;
class Game;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
void stopGame();
void startGame();
void restartGame();
private:
    void InitWindowsSizes();
    void connectButtons();
    void connectToGameSignals();
private:
    QStackedWidget widgets;
    MainMenu*mainMenu=nullptr;
    Settings*settings=nullptr;
    PauseMenu*pauseMenu=nullptr;
    Game*game=nullptr;

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // MAINWINDOW_H
