#include "pacman.h"


Pacman::Pacman(int x, int y, QObject *parent) : QObject(parent)
{
    pixmap=new QPixmap(":/Fotos/Pacman/pacman.png");
    direction="";
    posx=x;
    posy=y;
    posxBase=x;
    posyBase=y;
    ancho=25;
    alto=30;
    posBase=posy;
    choque = false;


    setPos(posx,posy);
}


QRectF Pacman::boundingRect() const
{
    return QRectF(0,0,ancho,alto);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

void Pacman::Mover_izquiera()
{
    direction ="izquierda";
    posx -= 5;
    setX(posx);
    if(mover_izquierda==0){
        pixmap->load(":/Fotos/Pacman/pacman.png");
    }
    else if (mover_izquierda==1) {
        pixmap->load(":/Fotos/Pacman/pacman-izquierda.png");
    }
    else if (mover_izquierda==2){
        pixmap->load(":/Fotos/Pacman/pacman-izquierda-2.png");
    }
    if(mover_izquierda==2){mover_izquierda=0;}
    mover_izquierda ++;
}

void Pacman::Mover_derecha()
{
    direction ="derecha";
    posx += 5;
    setX(posx);
    if(mover_derecha==0){
        pixmap->load(":/Fotos/Pacman/pacman.png");
    }
    else if (mover_derecha==1) {
        pixmap->load(":/Fotos/Pacman/pacman-derecha.png");
    }
    else if (mover_derecha==2){
        pixmap->load(":/Fotos/Pacman/pacman-derecha-2.png");
    }
    if(mover_derecha==2){mover_derecha=0;}
    mover_derecha ++;
}

void Pacman::Mover_arriba()
{
    direction ="arriba";
    posy -= 5;
    setY(posy);
    if(mover_arriba==0){
        pixmap->load(":/Fotos/Pacman/pacman.png");
    }
    else if (mover_arriba==1) {
        pixmap->load(":/Fotos/Pacman/pacman-arriba.png");
    }
    else if (mover_arriba==2){
        pixmap->load(":/Fotos/Pacman/pacman-arriba-2.png");
    }
    if(mover_arriba==2){mover_arriba=0;}
    mover_arriba ++;
}

void Pacman::Mover_abajo()
{
    direction ="abajo";
    posy += 5;
    setY(posy);
    if(mover_abajo==0){
        pixmap->load(":/Fotos/Pacman/pacman.png");
    }
    else if (mover_abajo==1) {
        pixmap->load(":/Fotos/Pacman/pacman-abajo.png");
    }
    else if (mover_abajo==2){
        pixmap->load(":/Fotos/Pacman/pacman-abajo-2.png");
    }
    if(mover_abajo==2){mover_abajo=0;}
    mover_abajo ++;
}

void Pacman::Quieto()
{
    direction = "quieto";
    setPos(posx,posy);
}

void Pacman::volverposinicial()
{
    posx=posxBase;
    posy=posyBase;
    setPos(posx,posy);
}

bool Pacman::getcoque()
{
    return choque;
}

int Pacman::getposx()
{
    return posx;
}

int Pacman::getposy()
{
    return posy;
}

int Pacman::getancho()
{
    return ancho;
}

int Pacman::getalto()
{
    return alto;
}

void Pacman::setposx(int _posx)
{
    posx=_posx;
}

void Pacman::setposy(int _posy)
{
    posy=_posy;
}

void Pacman::setchoque(bool _choque)
{
    choque = _choque;
}

QString Pacman::getdirecion()
{
    return direction;
}
