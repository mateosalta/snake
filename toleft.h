#ifndef TOLEFT_H
#define TOLEFT_H

#include "rib.h"
#include <QPixmap>

class ToLeft : public Rib
{
public:
    ToLeft(QLabel *label);
    ~ToLeft();

private:
    static QPixmap *patternPixmap;
};

#endif // TOLEFT_H
