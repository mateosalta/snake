#include "wall.h"

static const QString PATTERN_PIXMAP("wall");

QPixmap * Wall::patternPixmap = 0;

Wall::Wall(QLabel *label) : Field(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);
    //thisPixmap = new QPixmap (*patternPixmap);
    thisPixmap = patternPixmap;

    label->setPixmap(*thisPixmap);
}

void Wall::action(Snake *reptile)
{
    reptile->die();
}

/*Wall::Wall(Field *field) : Field(field)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);

    QTransform myTransform;
    myTransform.rotate(RIGHT);
    thisPixmap = new QPixmap (patternPixmap->transformed(myTransform));

    label->setPixmap(*thisPixmap);
}*/

