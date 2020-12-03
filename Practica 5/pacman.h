#ifndef PACMAN_H
#define PACMAN_H
#include "Librerias.h"

class Pacman : public QObject, public QGraphicsItem
{
private:

    short int mover_derecha =0;
    short int mover_izquierda =0;
    short int mover_arriba =0;
    short int mover_abajo =0;

    int posx, posxBase;
    int posy, posyBase;
    int posBase;
    int ancho;
    int alto;
    int vida = 3;
    bool choque;
    QString direction;
    QPixmap *pixmap;
    QTimer *timerSalto, *timerCaida;

public:
    Pacman(int x, int y, QObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void volverposinicial();
    void Mover_izquiera();
    void Mover_derecha();
    void Mover_arriba();
    void Mover_abajo();
    void Quieto();


    QString getdirecion();
    bool getcoque();
    int getposx();
    int getposy();
    int getancho();
    int getalto();

    void setposx(int _posx);
    void setposy(int _posy);
    void setchoque(bool _choque);


};

#endif // PACMAN_H
