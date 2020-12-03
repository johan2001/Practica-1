#ifndef OBJETOS_H
#define OBJETOS_H

#include "Librerias.h"
#include "pacman.h"
#include "fantasmas.h"

class Objetos: public QObject, public QGraphicsItem
{
private:
    int posx, posy;
    int ancho, alto;
    QPixmap *pixmap;
    QString Clase;

public:
    explicit Objetos(int x,int y,QString clase, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void colisionespacman(Pacman *pacman);
    void colisionesfantasmas(Fantasmas *pacman);

    int getposx();
    int getposy();
    int getancho();
    int getalto();
    QString getclase();
};

#endif // OBJETOS_H
