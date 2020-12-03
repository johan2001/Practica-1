#include "objetos.h"

Objetos::Objetos(int x, int y, QString clase, QObject *parent): QObject(parent)
{
    Clase=clase;
    posx=x;
    posy=y;
    ancho = 31;
    alto=37;
    if (Clase =="nombre"){
        pixmap =new QPixmap(":/Fotos/Wall5.png");
    }
    else if (Clase == "pared"){
        pixmap =new QPixmap(":/Fotos/descarga.jpg");
    }
    else if(Clase == "negro"){
        pixmap =new QPixmap(":/Fotos/imagen-negra-3.jpg");
    }

    setPos(posx,posy);
}

QRectF Objetos::boundingRect() const
{
     return QRectF(0,0,ancho,alto);
}

void Objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

void Objetos::colisionespacman(Pacman *pacman)
{
    int posizquierdaObjeto = posx, posderechaObjeto = posx+ancho, posarribaObjeto = posy, posabajoObjeto = posy+alto;
    int posizquierdaPacman = pacman->getposx(), posderechaPacman = pacman->getposx()+pacman->getancho(), posarribaPacman = pacman->getposy(), posabajoPacman = pacman->getposy()+pacman->getalto();

    if (pacman->getdirecion()=="izquierda" and( Clase == "pared" or Clase =="nombre" )) {
        if(posizquierdaPacman > posizquierdaObjeto and posizquierdaPacman < posderechaObjeto and((posarribaPacman > posarribaObjeto + 3  and posarribaPacman < posabajoObjeto - 3 ) or (posabajoPacman > posarribaObjeto + 3 and posabajoPacman < posabajoObjeto - 3)) ){
            pacman->setposx(posderechaObjeto + 1);
            pacman->setchoque(true);
        }
    }
    else if (pacman->getdirecion()=="derecha" and( Clase == "pared" or Clase =="nombre" )) {
        if(posderechaPacman > posizquierdaObjeto and posderechaPacman < posderechaObjeto and ((posarribaPacman > posarribaObjeto + 3  and posarribaPacman < posabajoObjeto - 3 ) or (posabajoPacman > posarribaObjeto + 3 and posabajoPacman < posabajoObjeto - 3)) ){
            pacman->setposx(posizquierdaObjeto - pacman->getancho() - 1);
            pacman->setchoque(true);
        }
    }
    else if (pacman->getdirecion()=="arriba" and( Clase == "pared" or Clase =="nombre" )) {
        if( posarribaPacman > posarribaObjeto and posarribaPacman < posabajoObjeto  and ((posizquierdaPacman > posizquierdaObjeto + 3  and posizquierdaPacman < posderechaObjeto - 3 ) or (posderechaPacman >posizquierdaObjeto + 3 and posderechaPacman < posderechaObjeto - 3)) ){
            pacman->setposy(posabajoObjeto  + 1);
            pacman->setchoque(true);
        }
    }
    else if (pacman->getdirecion()=="abajo" and( Clase == "pared" or Clase =="nombre" )) {
        if( posabajoPacman > posarribaObjeto and posabajoPacman < posabajoObjeto  and ((posizquierdaPacman > posizquierdaObjeto + 3  and posizquierdaPacman < posderechaObjeto - 3) or (posderechaPacman >posizquierdaObjeto+3 and posderechaPacman < posderechaObjeto-3)) ){
            pacman->setposy(posarribaObjeto - pacman->getalto() - 1 );
            pacman->setchoque(true);
        }
    }
}

void Objetos::colisionesfantasmas(Fantasmas *pacman)
{
    int posizquierdaObjeto = posx, posderechaObjeto = posx+ancho, posarribaObjeto = posy, posabajoObjeto = posy+alto;
    int posizquierdaFantasma = pacman->getposx(), posderechaPacman = pacman->getposx()+pacman->getancho(), posarribaPacman = pacman->getposy(), posabajoPacman = pacman->getposy()+pacman->getalto();

    if (pacman->getdirecion()=="izquierda" and( Clase == "pared" or Clase =="nombre" )) {
        if(posizquierdaFantasma > posizquierdaObjeto and posizquierdaFantasma < posderechaObjeto and((posarribaPacman > posarribaObjeto + 2  and posarribaPacman < posabajoObjeto - 2 ) or (posabajoPacman > posarribaObjeto + 2 and posabajoPacman < posabajoObjeto - 2)) ){
            pacman->setposx(posderechaObjeto + 1);
            pacman->setchoque(true);
        }
    }
    else if (pacman->getdirecion()=="derecha" and( Clase == "pared" or Clase =="nombre" )) {
        if(posderechaPacman > posizquierdaObjeto and posderechaPacman < posderechaObjeto and ((posarribaPacman > posarribaObjeto+2  and posarribaPacman < posabajoObjeto-2) or (posabajoPacman > posarribaObjeto+2 and posabajoPacman < posabajoObjeto-2)) ){
            pacman->setposx(posizquierdaObjeto - pacman->getancho() - 1);
            pacman->setchoque(true);
        }
    }
    else if (pacman->getdirecion()=="arriba" and( Clase == "pared" or Clase =="nombre" )) {
        if( posarribaPacman > posarribaObjeto and posarribaPacman < posabajoObjeto  and ((posizquierdaFantasma > posizquierdaObjeto+2  and posizquierdaFantasma < posderechaObjeto - 2) or (posderechaPacman >posizquierdaObjeto + 2 and posderechaPacman < posderechaObjeto-2)) ){
            pacman->setposy(posabajoObjeto  + 1);
            pacman->setchoque(true);
        }
    }
    else if (pacman->getdirecion()=="abajo" and( Clase == "pared" or Clase =="nombre" )) {
        if( posabajoPacman > posarribaObjeto and posabajoPacman < posabajoObjeto  and ((posizquierdaFantasma > posizquierdaObjeto +2  and posizquierdaFantasma < posderechaObjeto-2) or (posderechaPacman >posizquierdaObjeto+2 and posderechaPacman < posderechaObjeto-2)) ){
            pacman->setposy(posarribaObjeto - pacman->getalto() - 1 );
            pacman->setchoque(true);
        }
    }
}

int Objetos::getposx()
{
    return posx;
}

int Objetos::getposy()
{
    return  posy;
}

int Objetos::getancho()
{
    return ancho;
}

int Objetos::getalto()
{
    return alto;
}

QString Objetos::getclase()
{
    return Clase;
}
