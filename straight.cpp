#include "straight.h"

static const QString PATTERN_PIXMAP("straight");

QPixmap * Straight::patternPixmap = 0;

Straight::Straight(QLabel *label) : Rib(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
    thisPixmap = new QPixmap (*patternPixmap);

    label->setPixmap(*thisPixmap);
}

Straight::~Straight()
{

}

