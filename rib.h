#ifndef RIB_H
#define RIB_H

#include "field.h"
#include <QPixmap>

class Rib : public Field
{
public:
    Rib(QLabel *label);
    ~Rib();
    void action(Snake *reptile);
    void setAngle(int newAngle);
    int getAngle();

protected:
    int angle;
};



#endif // RIB_H
