#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);

    startTimer(2000/60);

    gameover = new Gameover();
    win = new Win();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/Fotos/imagen-negra-3.jpg").scaled(1200,600)); //Intoducir fondo

    for (int i=0;i<15;i++) {
        for (int j=0;j<38;j++) {


            if(mapa[i][j]== 1){
                listObjetos.push_back(new Objetos(j*31,i*37,"pared"));
                scene->addItem(listObjetos.last());
            }

            if(mapa[i][j]== 2){
                listFantasmas.push_back(new Fantasmas(j*31,i*37,"rojo"));
                scene->addItem(listFantasmas.last());
            }

            if(mapa[i][j]== 3){
                listObjetos.push_back(new Objetos(j*31,i*37,"nombre"));
                scene->addItem(listObjetos.last());
            }

            if(mapa[i][j]== 4){
                listObjetos.push_back(new Objetos(j*31,i*37,"negro"));
                scene->addItem(listObjetos.last());
            }

            if(mapa[i][j]== 5){
                listFantasmas.push_back(new Fantasmas(j*31,i*37,"rosado"));
                scene->addItem(listFantasmas.last());
            }


            if(mapa[i][j]== 6){
                listFantasmas.push_back(new Fantasmas(j*31,i*37,"naranja"));
                scene->addItem(listFantasmas.last());
            }

            if(mapa[i][j]== 7){
                listFantasmas.push_back(new Fantasmas(j*31,i*37,"azul"));
                scene->addItem(listFantasmas.last());
            }
            if(mapa[i][j]== 8){
                listPunticos.push_back(new Punticos(j*31+10,i*37+15,"punticossuper"));
                scene->addItem(listPunticos.last());
            }
            if(mapa[i][j]== 0){
                listPunticos.push_back(new Punticos(j*31+10,i*37+15,"punticos"));
                scene->addItem(listPunticos.last());
            }
        }
    }

    ListdeVidas.push_back(new Vidas(1150,-25));
    scene->addItem(ListdeVidas.last());
    ListdeVidas.push_back(new Vidas(1100,-25));
    scene->addItem(ListdeVidas.last());
    ListdeVidas.push_back(new Vidas(1050,-25));
    scene->addItem(ListdeVidas.last());

    pacman = new Pacman(400,415);
    scene->addItem(pacman);

    puntaje = new Puntaje();
    puntaje->setPos(puntaje->x(),puntaje->y()-25);
    scene->addItem(puntaje);

    timerColisiones=new QTimer;
    connect(timerColisiones,SIGNAL(timeout()),this,SLOT(colisiones()));
    timerColisiones->start(0);

    comer=new QMediaPlayer();
    comer->setMedia(QUrl("qrc:/Musica/pacman_chomp.wav"));

    cirena=new QMediaPlayer();
    cirena->setMedia(QUrl("qrc:/Musica/pacman-siren.mp3"));

    comerfantasmas=new QMediaPlayer();
    comerfantasmas->setMedia(QUrl("qrc:/Musica/pacman-eating-ghost.mp3"));

    muertepacman=new QMediaPlayer();
    muertepacman->setMedia(QUrl("qrc:/Musica/pacman-dies.mp3"));

    miedo=new QMediaPlayer();
    miedo->setMedia(QUrl("qrc:/Musica/mix_09s (audio-joiner.com).mp3"));

}

Juego::~Juego()
{
    delete ui;
}

void Juego::keyPressEvent(QKeyEvent *event)
    {
    keys[event->key()]=true; QWidget::keyPressEvent(event);
    }


void Juego::keyReleaseEvent(QKeyEvent *event)
    {
    keys[event->key()]=false; QWidget::keyReleaseEvent(event);
    }


void Juego::timerEvent(QTimerEvent *)
{

    if(pacman->getcoque()){
        if (pacman->getdirecion()=="izquierda"){
            pacman->Quieto();
            pacman->setchoque(false);
        }
        else if (pacman->getdirecion()=="derecha"){    
            pacman->Quieto();
            pacman->setchoque(false);
        }
        else if (pacman->getdirecion()=="arriba"){
            pacman->Quieto();
            pacman->setchoque(false);
        }
        else if (pacman->getdirecion()=="abajo"){
            pacman->Quieto();
            pacman->setchoque(false);
        }
    }
    else {
        if(keys[Qt::Key_A]){
            pacman->Mover_izquiera();
            for(int i=0;i<listFantasmas.size();i++){
                if (listFantasmas.at(i)->getdirecion()=="izquierda"){listFantasmas.at(i)->Mover_izquiera();}
                if (listFantasmas.at(i)->getdirecion()=="derecha"){listFantasmas.at(i)->Mover_derecha();}
                if (listFantasmas.at(i)->getdirecion()=="arriba"){listFantasmas.at(i)->Mover_arriba();}
                if (listFantasmas.at(i)->getdirecion()=="abajo"){listFantasmas.at(i)->Mover_abajo();}
            }
        }

        else if(keys[Qt::Key_D]){
            pacman->Mover_derecha();
            for(int i=0;i<listFantasmas.size();i++){
                if (listFantasmas.at(i)->getdirecion()=="izquierda"){listFantasmas.at(i)->Mover_izquiera();}
                if (listFantasmas.at(i)->getdirecion()=="derecha"){listFantasmas.at(i)->Mover_derecha();}
                if (listFantasmas.at(i)->getdirecion()=="arriba"){listFantasmas.at(i)->Mover_arriba();}
                if (listFantasmas.at(i)->getdirecion()=="abajo"){listFantasmas.at(i)->Mover_abajo();}
            }
        }

        else if(keys[Qt::Key_W]){
            pacman->Mover_arriba();
            for(int i=0;i<listFantasmas.size();i++){
                if (listFantasmas.at(i)->getdirecion()=="izquierda"){listFantasmas.at(i)->Mover_izquiera();}
                if (listFantasmas.at(i)->getdirecion()=="derecha"){listFantasmas.at(i)->Mover_derecha();}
                if (listFantasmas.at(i)->getdirecion()=="arriba"){listFantasmas.at(i)->Mover_arriba();}
                if (listFantasmas.at(i)->getdirecion()=="abajo"){listFantasmas.at(i)->Mover_abajo();}
            }
        }

        else if(keys[Qt::Key_S]){
            pacman->Mover_abajo();
            for(int i=0;i<listFantasmas.size();i++){
                if (listFantasmas.at(i)->getdirecion()=="izquierda"){listFantasmas.at(i)->Mover_izquiera();}
                if (listFantasmas.at(i)->getdirecion()=="derecha"){listFantasmas.at(i)->Mover_derecha();}
                if (listFantasmas.at(i)->getdirecion()=="arriba"){listFantasmas.at(i)->Mover_arriba();}
                if (listFantasmas.at(i)->getdirecion()=="abajo"){listFantasmas.at(i)->Mover_abajo();}
            }
        }

        else{
            if (pacman->getdirecion() == "izquierda"){pacman->Mover_izquiera();}
            if (pacman->getdirecion() == "derecha"){pacman->Mover_derecha();}
            if (pacman->getdirecion() == "arriba"){pacman->Mover_arriba();}
            if (pacman->getdirecion() == "abajo"){pacman->Mover_abajo();}
            if (pacman->getdirecion() == "quieto"){pacman->Quieto();}
            for(int i=0;i<listFantasmas.size();i++){
                if (listFantasmas.at(i)->getdirecion()=="izquierda"){listFantasmas.at(i)->Mover_izquiera();}
                if (listFantasmas.at(i)->getdirecion()=="derecha"){listFantasmas.at(i)->Mover_derecha();}
                if (listFantasmas.at(i)->getdirecion()=="arriba"){listFantasmas.at(i)->Mover_arriba();}
                if (listFantasmas.at(i)->getdirecion()=="abajo"){listFantasmas.at(i)->Mover_abajo();}
            }
        }
    }
}
void Juego::colisiones()
{
    for(int i=0;i<listObjetos.size();i++){
        listObjetos.at(i)->colisionespacman(pacman);
        if (listObjetos.at(i)->collidesWithItem(pacman) and listObjetos.at(i)->getclase()=="negro" ){
            if (pacman->getdirecion()=="derecha"){
                pacman->setposx(40);
            }
            else {
                pacman->setposx(1100);
            }
        }
    }
    for(int a=0;a<listObjetos.size();a++){
        for(int j=0;j<listFantasmas.size();j++){
            listObjetos.at(a)->colisionesfantasmas(listFantasmas.at(j));
            if(listFantasmas.at(j)->getcoque()==true){
                listFantasmas.at(j)->cambiardirecion();
                listFantasmas.at(j)->setchoque(false);
            }
            if (listObjetos.at(a)->collidesWithItem(listFantasmas.at(j)) and listObjetos.at(a)->getclase()=="negro" ){
                if (listFantasmas.at(j)->getdirecion()== "derecha"){
                    listFantasmas.at(j)->setposx(40);
                }
                else {
                    listFantasmas.at(j)->setposx(1100);
                }
            }
        }
    }
    for (int w=0;w<listFantasmas.size();w++) {
        if (listFantasmas.at(w)->collidesWithItem(pacman)){
            if(listFantasmas.at(w)->getmiedo()){
                comerfantasmas->play();
                puntaje->Aumentarpuntaje(200);
                listFantasmas.at(w)->Muertos();
                listFantasmas.at(w)->setmiedo(false);
                listFantasmas.at(w)->cambiardirecion();
            }
            else {
                scene->removeItem(ListdeVidas.at(0));
                ListdeVidas.removeAt(0);
                pacman->volverposinicial();
                vidas -= 1;
                if (vidas==0){
                    muertepacman->play();
                    hide();
                    gameover->show();
                }
            }
        }
    }
    if (listPunticos.size()==0){
        hide();
        win->show();
    }
    for (int e=0;e<listPunticos.size();e++) {
        if(listPunticos.at(e)->collidesWithItem(pacman)){
            if (comer->state() == QMediaPlayer::PlayingState){
                comer->setPosition(0);
            }
            else if (comer->state() == QMediaPlayer::StoppedState){
                comer->play();
            }

            if (listPunticos.at(e)->getnombre()=="punticossuper"){
                puntaje->Aumentarpuntaje(50);
                miedo->play();
                scene->removeItem(listPunticos.at(e));
                listPunticos.removeAt(e);
                clock_t tiempo;
                tiempo =clock();
                for (int i2=0;i2<listFantasmas.size();i2++) {
                    listFantasmas.at(i2)->setmiedo(true);
                    listFantasmas.at(i2)->cambiardirecion();
                    listFantasmas.at(i2)->settiempo(tiempo);
                }

            }
            if (listPunticos.at(e)->getnombre()=="punticos"){
                puntaje->Aumentarpuntaje(10);
                scene->removeItem(listPunticos.at(e));
                listPunticos.removeAt(e);
            }
        }
    }
}
