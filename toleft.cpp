#include "toleft.h"

static const QString PATTERN_PIXMAP("toLeft");

QPixmap * ToLeft::patternPixmap = 0;

ToLeft::ToLeft(QLabel *label) : Rib(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
    thisPixmap = new QPixmap (*patternPixmap);

    label->setPixmap(*thisPixmap);
}

ToLeft::~ToLeft()
{

}
