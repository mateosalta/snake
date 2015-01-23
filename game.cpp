#include <iostream>
#include "game.h"
#include "snake.h"
#include "ui_game.h"

#define START_SPEED 400

using namespace std;

Game::Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Game){
    ui->setupUi(this);
    board = new Board(ui->gridLayoutWidget, ui->gridLayout, 16);
    snake = new Snake(board);

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeTick()));
    timer->start(START_SPEED);


    //Ekran Game Over.
    QPalette palette = ui->pauseFrame->palette();
    palette.setColor( backgroundRole(), QColor( 200, 200, 255) );
    ui->pauseFrame->setPalette( palette );
    ui->pauseFrame->setAutoFillBackground( true );
    ui->pauseFrame->hide();

    paused = false;
}

Game::~Game()
{
    delete board;
    delete snake;
    delete timer;
    delete ui;
}

void Game::timeTick()
{
    if (snake->isAlive() && !paused){
        snake->move();
        ui->scoreLabel->setText(QString::number(snake->getEatenApples()));
    }
    else if (!snake->isAlive()) {
        timer->stop(); // All the actions for "game over" event.
        Pause(GAME_OVER);
    }
}

void Game::keyPressEvent(QKeyEvent *event){
    cout << event->text().toStdString() << endl;

    bool pressedPause = (event->key() == Qt::Key_Escape) ? true : false;

    if (paused){
        if (event->key() == Qt::Key_R){
            Reset();
            Unpause();
        }
        else if(snake->isAlive() && pressedPause)
            Unpause();
    } else if (pressedPause){
            Pause(GAME_PAUSED);
    }
    else {
        if(event->key() == Qt::Key_W) snake->setDirection(UP);
        else if (event->key() == Qt::Key_S) snake->setDirection(DOWN);
        else if (event->key() == Qt::Key_A) snake->setDirection(LEFT);
        else if (event->key() == Qt::Key_D) snake->setDirection(RIGHT);
        timer->stop();
        timeTick();
        timer->start(START_SPEED);
    }

}

void Game::keyReleaseEvent(QKeyEvent */*event*/)
{
    //cout << event->text().toStdString() << endl;
}

void Game::Pause(bool type)
{
    if(type == GAME_OVER){
        ui->pauseTitle->setText("Game Over");
        ui->pressUnpause->hide();
    }
    else{
        ui->pauseTitle->setText("Pause");
        ui->pressUnpause->show();
    }

    ui->pauseFrame->show();
    paused = true;
}

void Game::Unpause()
{
    ui->pauseFrame->hide();
    paused = false;
}

void Game::Reset()
{
    delete board;
    delete snake;
    board = new Board(ui->gridLayoutWidget, ui->gridLayout, 16);
    snake = new Snake(board);
    snake->move();
    timer->start(START_SPEED);
}
