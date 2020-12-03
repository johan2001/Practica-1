#ifndef FANTASMAS_H
#define FANTASMAS_H

#include "Librerias.h"

class Fantasmas : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int posx, posxBase;
    int posy, posyBase;
    int ancho;
    int alto;
    clock_t tiempo;
    clock_t tiempo2;
    bool choque;
    bool miedo;
    QString Color;
    QString direction;
    QTimer *timer_direcion;
    QTimer *timer;
    QPixmap *pixmap;
public:
    Fantasmas(int x, int y,QString color, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~ Fantasmas() ;


    void Mover_izquiera();
    void Mover_derecha();
    void Mover_arriba();
    void Mover_abajo();
    void Muertos();


    int getposx();
    int getposy();
    int getancho();
    int getalto();
    QString getcolor();
    QString getdirecion();
    bool getcoque();
    bool getmiedo();

    void settiempo(clock_t _tiempo);
    void setcolor(QString _color);
    void setdirecion(QString _direcion);
    void setchoque(bool _choque);
    void setmiedo(bool _miedo);
    void setposx(int _posx);
    void setposy(int _posy);


signals:

public slots:
    void contartiempo();
    void cambiardirecion();

};


#endif // FANTASMAS_H
