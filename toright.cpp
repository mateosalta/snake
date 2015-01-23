#include "toright.h"

static const QString PATTERN_PIXMAP("toRight");

QPixmap * ToRight::patternPixmap = 0;

ToRight::ToRight(QLabel *label) : Rib(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
    thisPixmap = new QPixmap (*patternPixmap);

    label->setPixmap(*thisPixmap);
}

ToRight::~ToRight()
{

}
