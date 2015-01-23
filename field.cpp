#include "field.h"

Field::Field(QLabel *Label)
{
    this->label = Label;
}

/*Field::Field(Field *field)
{
    this->label = field->getLabel();
    field->setLabel(0);
    delete field;
}*/

Field::~Field()
{
    //delete label;
}

std::string Field::fieldType()
{
    return "Field";
}

void Field::action(Snake */*reptile*/)
{

}

QLabel *Field::getLabel()
{
    return label;
}

void Field::setLabel(QLabel *Label)
{
    label = Label;
}

QPixmap *rotatedPixmap(QPixmap *original, int newAngle)
{
    QTransform myTransform;
    myTransform.rotate(newAngle);
    QPixmap *newPix = new QPixmap (original->transformed(myTransform));
    return newPix;
}
