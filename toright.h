#ifndef TORIGHT_H
#define TORIGHT_H

#include "rib.h"
#include <QPixmap>

class ToRight : public Rib
{
public:
    ToRight(QLabel *label);
    ~ToRight();

private:
    static QPixmap *patternPixmap;
};

#endif // TORIGHT_H
