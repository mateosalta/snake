#include "Head.h"

static const QString PATTERN_PIXMAP("head");

QPixmap * Head::patternPixmap = 0;

Head::Head(QLabel *label)  : Rib(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
        thisPixmap = new QPixmap (*patternPixmap);

        label->setPixmap(*thisPixmap);
}

Head::~Head(){

}
