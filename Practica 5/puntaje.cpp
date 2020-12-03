#include "puntaje.h"

Puntaje::Puntaje(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    puntaje=0;

    setPlainText("Puntaje: " + QString::number(puntaje));
    setDefaultTextColor(Qt::red);
    setFont(QFont("timos",16));
}

void Puntaje::Aumentarpuntaje(int valor)
{
    puntaje += valor;
    setPlainText("Puntaje: " + QString::number(puntaje));
    setDefaultTextColor(Qt::red);
    setFont(QFont("timos",16));
}

int Puntaje::getpintaje()
{
    return puntaje;
}
