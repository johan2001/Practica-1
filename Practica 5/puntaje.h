#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "Librerias.h"

class Puntaje: public QGraphicsTextItem
{
private:
    int puntaje;
public:
    Puntaje(QGraphicsItem *parent=0 );
    void Aumentarpuntaje(int valor);
    int getpintaje();

};

#endif // PUNTAJE_H
