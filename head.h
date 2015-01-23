#ifndef HEAD_H
#define HEAD_H

#include "rib.h"
#include <QPixmap>

class Head : public Rib
{
public:
    Head(QLabel *label);
    ~Head();

private:
    static QPixmap *patternPixmap;
};

#endif // HEAD_H
