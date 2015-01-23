#ifndef SPACE_H
#define SPACE_H

#include "field.h"
#include <QPixmap>

class Space : public Field
{
public:
    Space(QLabel *label);
    //Space(Field *field);
    std::string fieldType();
private:
    static QPixmap *patternPixmap;
};

#endif // SPACE_H
