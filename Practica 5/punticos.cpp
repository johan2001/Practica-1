#include "punticos.h"

Punticos::Punticos(int x, int y, QString _nombre, QObject *parent): QObject(parent)
{
    nombre = _nombre;
    if (nombre=="punticos"){
        pixmap=new QPixmap(":/Fotos/OBJETOS/punto.png");
        ancho=10;
        alto=10;
    }
    else if(nombre=="punticossuper"){
        pixmap=new QPixmap(":/Fotos/OBJETOS/punto 3.png");
        ancho=20;
        alto=20;
    }

    posx=x;
    posy=y;

    timer  = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(animacion()));
    timer->start(200);

    setPos(posx,posy);
}

QRectF Punticos::boundingRect() const
{
    return QRectF(0,0,ancho,alto);
}

void Punticos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

Punticos::~Punticos()
{

}

QString Punticos::getnombre()
{
    return nombre;
}

void Punticos::animacion()
{

    if(nombre=="punticossuper"){
        if(animar==0){
            pixmap->load("");
        }
        else if (animar==1) {
            posx -= 5;
            setX(posx);
            pixmap->load(":/Fotos/OBJETOS/punto 3.png");
        }
        else if (animar==2){
            posx += 5;
            setX(posx);
            pixmap->load("");
        }
        if(animar==2){animar=0;}
        animar ++;
    }
}
