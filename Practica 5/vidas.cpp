#include "vidas.h"

Vidas::Vidas(int x, int y,QObject *parent) : QObject(parent)
{
    posx=x;
    posy=y;
    ancho=25;
    alto=30;
    pixmap=new QPixmap(":/Fotos/Pacman/pacman-derecha.png");
    setPos(posx,posy);
}
QRectF Vidas::boundingRect() const
{
    return QRectF(0,0,ancho,alto);
}

void Vidas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

Vidas::~Vidas()
{

}
