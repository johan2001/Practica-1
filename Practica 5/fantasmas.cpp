#include "fantasmas.h"

Fantasmas::Fantasmas(int x, int y,QString color, QObject *parent) : QObject(parent)
{


    direction="arriba";
    Color = color;
    miedo = false;
    tiempo =clock();
    posx=x;
    posy=y;
    posxBase=400;
    posyBase=415;
    ancho=25;
    alto=30;
    srand(time(0));
    choque = false;

    if (Color=="rojo"){
        pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rojo-derecha.png");
    }

    else if (Color=="azul"){
        pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-azul-derecha.png");
    }
    else if (Color=="rosado"){
        pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rosado-derecha.png");
    }

    else if (Color=="naranja"){
        pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-naranja-derecha.png");
    }

    timer_direcion  = new QTimer();
    connect(timer_direcion, SIGNAL(timeout()), this, SLOT(cambiardirecion()));
    timer_direcion->start(2000);

    timer  = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(contartiempo()));
    timer->start(0);

    setPos(posx,posy);
}


QRectF Fantasmas::boundingRect() const
{
    return QRectF(0,0,ancho,alto);
}

void Fantasmas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

Fantasmas::~Fantasmas()
{

}

void Fantasmas::cambiardirecion()
{
    int numazul,numrojo,numnaranja,numrosado;
    if (Color=="rojo"){
        numrojo = rand() % 4 + 1;
        if(numrojo ==1 and direction != "derecha" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="derecha";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rojo-derecha.png");
                direction ="derecha";
            }
        }
        else if(numrojo ==2 and direction != "izquierda"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="izquierda";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rojo-izquierda.png");
                direction ="izquierda";
            }
        }
        else if(numrojo ==3 and direction != "arriba" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="arriba";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rojo-arriba.png");
                direction ="arriba";
            }
        }
        else if(numrojo ==4 and direction != "abajo" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="abajo";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rojo-abajo.png");
                direction ="abajo";
            }
        }
    }

    else if (Color=="azul"){
        numazul = rand() % 4 + 5;
        if(numazul ==5 and direction != "derecha"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="derecha";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-azul-derecha.png");
                direction ="derecha";
                }
        }
        else if(numazul ==6 and direction != "izquierda"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="izquierda";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-azul-izquierda.png");
                direction ="izquierda";
            }
        }
        else if(numazul ==7 and direction != "arriba"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="arriba";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-azul-arriba.png");
                direction ="arriba";
            }
        }
        else if(numazul ==8 and direction != "abajo" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="abajo";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-azul-abajo.png");
                direction ="abajo";
            }
        }
    }

    else if (Color=="rosado"){
        numrosado = rand() % 4 + 9;
        if(numrosado ==9 and direction != "derecha" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="derecha";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rosado-derecha.png");
                direction ="derecha";
            }
        }
        else if(numrosado ==10 and direction != "izquierda"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="izquierda";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rosado-izquierda.png");
                direction ="izquierda";
            }
        }
        else if(numrosado ==11 and direction != "arriba" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="arriba";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rosado-arriba.png");
                direction ="arriba";
            }
        }
        else if(numrosado ==12  and direction != "abajo" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="abajo";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-rosado-abajo.png");
                direction ="abajo";
            }
        }
    }

    else if (Color=="naranja"){
        numnaranja = rand() % 4 + 13;
        if(numnaranja ==13 and direction != "derecha"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="derecha";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-naranja-derecha.png");
                direction ="derecha";
            }
        }
        else if(numnaranja ==14 and direction != "izquierda"){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="izquierda";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-naranja-izquierda.png");
                direction ="izquierda";
            }
        }
        else if(numnaranja ==15 and direction != "arriba" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="arriba";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-naranja-arriba.png");
                direction ="arriba";
            }
        }
        else if(numnaranja ==16 and direction != "abajo" ){
            if (miedo){
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-miedo.png");
                direction ="abajo";
            }
            else{
                pixmap=new QPixmap(":/Fotos/Fantasmas/Fantasma-naranja-abajo.png");
                direction ="abajo";
            }
        }
    }
}

void Fantasmas::Mover_izquiera()
{
    posx -= 5;
    setX(posx);
}

void Fantasmas::Mover_derecha()
{
    posx += 5;
    setX(posx);
}

void Fantasmas::Mover_arriba()
{
    posy -= 5;
    setY(posy);
}

void Fantasmas::Mover_abajo()
{
    posy += 5;
    setY(posy);
}

void Fantasmas::Muertos()
{
    posx=posxBase;
    posy=posyBase;
    setPos(posx,posy);
}

void Fantasmas::contartiempo()
{  
    tiempo2 =clock();
    tiempo2 = tiempo2-tiempo;
    if (int(tiempo2)>=8000){miedo=false;}
}

int Fantasmas::getposx()
{
    return posx;
}

int Fantasmas::getposy()
{
    return posy;
}

int Fantasmas::getancho()
{
    return ancho;
}

int Fantasmas::getalto()
{
    return alto;
}

QString Fantasmas::getcolor()
{
    return Color;
}


QString Fantasmas::getdirecion()
{
    return direction;
}

bool Fantasmas::getcoque()
{
    return  choque;
}

bool Fantasmas::getmiedo()
{
    return miedo;
}

void Fantasmas::settiempo(clock_t _tiempo)
{
    tiempo=_tiempo;
}

void Fantasmas::setcolor(QString _color)
{
    Color=_color;
}

void Fantasmas::setdirecion(QString _direcion)
{
    direction = _direcion;
}

void Fantasmas::setchoque(bool _choque)
{
    choque =_choque;
}

void Fantasmas::setmiedo(bool _miedo)
{
    miedo=_miedo;
}

void Fantasmas::setposx(int _posx)
{
    posx=_posx;
}

void Fantasmas::setposy(int _posy)
{
    posy=_posy;
}

