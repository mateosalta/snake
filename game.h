#ifndef GAME_H
#define GAME_H

#define GAME_OVER true
#define GAME_PAUSED false

#include <QMainWindow>
#include <QApplication>
#include <QTimer>
#include "board.h"

class Snake;

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

public slots:
    void timeTick();

private:
    Snake *snake;
    Ui::Game *ui;
    Board *board;
    QTimer *timer;
    bool paused;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void Pause(bool type);
    void Unpause();
    void Reset();
};

#endif // GAME_H
