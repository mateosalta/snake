#ifndef PIXMAPS_H
#define PIXMAPS_H
#include <QPixmap>
#include <QHash>


class Pixmaps
{
public:
    Pixmaps();
    ~Pixmaps();
    QPixmap *getPixmap(QString path);

private:
    QHash<QString, QPixmap *> patterns;

};

extern Pixmaps pixManager;

#endif // PIXMAPS_H
