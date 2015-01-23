#ifndef TAIL_H
#define TAIL_H

#include "rib.h"
#include <QPixmap>

class Tail : public Rib
{
public:
    Tail(QLabel *label);
    ~Tail();

private:
    static QPixmap *patternPixmap;
};

#endif // TAIL_H
