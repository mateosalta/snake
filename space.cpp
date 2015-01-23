#include "space.h"


static const QString PATTERN_PIXMAP("space");

QPixmap * Space::patternPixmap = 0;

Space::Space(QLabel *label) : Field(label)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);

    //thisPixmap = rotatedPixmap(patternPixmap, RIGHT);
    thisPixmap = patternPixmap;

    label->setPixmap(*thisPixmap);
}

std::string Space::fieldType()
{
    return "Space";
}

/*Space::Space(Field *field) : Field(field)
{
    patternPixmap = pixManager.getPixmap(PATTERN_PIXMAP);

    QTransform myTransform;
    myTransform.rotate(RIGHT);
    thisPixmap = new QPixmap (patternPixmap->transformed(myTransform));

    label->setPixmap(*thisPixmap);
}*/


