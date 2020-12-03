#ifndef PUNTICOS_H
#define PUNTICOS_H

#include "Librerias.h"

class Punticos : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    short int animar =0;
    int posx;
    int posy;
    int ancho;
    int alto;
    QPixmap *pixmap;
    QString nombre;
    QTimer *timer;

public:
    Punticos(int x, int y,QString _nombre, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~ Punticos() ;

    QString getnombre();

signals:

public slots:
    void animacion();
};

#endif // PUNTICOS_H
