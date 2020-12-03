#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include "Librerias.h"
#include "pacman.h"
#include "objetos.h"
#include "fantasmas.h"
#include "punticos.h"
#include "puntaje.h"
#include "vidas.h"
#include "gameover.h"
#include "win.h"


namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT
private:
    Gameover *gameover;
    Win *win;
    int vidas=3;
    Ui::Juego *ui;
    QGraphicsScene *scene;
    QMap<int,bool> keys;
    Pacman *pacman;
    Puntaje *puntaje;

    //Matriz que armara el mapa(mundo)
    /* 0: puntos
     * 1: Muros
     * 2: Fantasma Rojo
     * 3: Muros Nombre
     * 4: teletraportador
     * 5: Fantasma Rosado
     * 6: Fantasma Naranja
     * 7: Fantasma Azul
     * 8: punto grandes
     */
    int mapa[15][38]=
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,8,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,8,1},
        {1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1},
        {1,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,0,0,0,3,3,3,3,3,0,3,3,3,3,3,0,3,0,0,0,0,0,0,3,0,0,0,3,3,0,0,3,0,0,0,0,1},
        {1,1,1,1,0,0,0,3,0,0,0,3,9,9,9,3,0,3,0,0,0,0,0,3,0,3,0,0,3,3,0,0,3,0,1,1,1,1},
        {4,9,9,9,5,0,0,3,0,0,0,3,9,9,9,3,8,3,3,3,3,8,0,3,0,3,0,0,3,0,3,0,3,0,9,9,9,4},
        {1,1,1,1,0,3,0,3,0,0,0,3,9,9,9,3,0,3,0,0,3,0,3,0,0,0,3,0,3,0,0,3,3,0,1,1,1,1},
        {1,0,0,0,0,3,3,3,0,0,0,3,3,3,3,3,0,3,0,0,3,0,3,0,0,0,3,0,3,0,0,3,3,0,0,0,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,7,1,1,0,1},
        {1,0,1,1,0,1,1,1,1,0,0,0,0,9,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,8,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,1,1,0,1},
        {1,8,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    QList<Objetos*> listObjetos;
    QList<Fantasmas*> listFantasmas;
    QList<Punticos*> listPunticos;
    QList<Vidas*> ListdeVidas;
    QTimer *timerColisiones;
    QMediaPlayer *cirena;
    QMediaPlayer *miedo;
    QMediaPlayer *comer;
    QMediaPlayer *comerfantasmas;
    QMediaPlayer *muertepacman;

public:
    explicit Juego(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);

    ~Juego();

public slots:
    void colisiones();

};

#endif // JUEGO_H
