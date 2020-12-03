#ifndef VIDAS_H
#define VIDAS_H

#include "Librerias.h"

class Vidas : public QObject, public QGraphicsItem
{
private:
    int posx;
    int posy;
    int ancho;
    int alto;
    QPixmap *pixmap;

public:
    Vidas(int x, int y, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~ Vidas() ;
};

#endif // VIDAS_H
