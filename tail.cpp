#include "tail.h"

static const QString PATTERN_PIXMAP("tail");

QPixmap * Tail::patternPixmap = 0;

Tail::Tail(QLabel *label) : Rib(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
    thisPixmap = new QPixmap (*patternPixmap);

    label->setPixmap(*thisPixmap);
}

Tail::~Tail()
{

}
