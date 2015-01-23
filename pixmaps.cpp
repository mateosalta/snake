#include "pixmaps.h"
#include <iostream>

Pixmaps pixManager;

Pixmaps::Pixmaps()
{

}

Pixmaps::~Pixmaps()
{
    QHashIterator<QString, QPixmap *> it(patterns);
    while(it.hasNext()){
        it.next();
        std::cout << "Usuwam QPixmap " << it.key().toStdString() << std::endl;
        delete it.value();
    }
}

QPixmap *Pixmaps::getPixmap(QString path)
{
    if (patterns.contains(path))
        return patterns[path];
    else {
        QPixmap *pix = new QPixmap(":/img/"+path+".svg");
        patterns[path] = pix;
        return pix;
    }
}

