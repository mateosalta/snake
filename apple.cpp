#include "apple.h"
#include "board.h"

static const QString PATTERN_PIXMAP("apple");

QPixmap * Apple::patternPixmap = 0;

Apple::Apple(QLabel *label, Board *board) : Field(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
    label->setPixmap(*patternPixmap);
    this->board = board;
}

Apple::~Apple()
{

}

std::string Apple::fieldType()
{
    return "Apple";
}

void Apple::action(Snake *reptile)
{
    reptile->eatApple();
    board->createApple();
}

