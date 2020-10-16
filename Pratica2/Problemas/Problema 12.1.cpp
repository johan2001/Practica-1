/*
Problema 14. Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
imprima la matriz rotada 90, 180 y 270 grados.
 */


#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;

void generar_numeros_aleatorios(int[]);
void mostar_y_generar_matriz();
bool saber_si_es_cuadrado_magico();

int **puntero_matriz,Dimencion;

int main()
{
    mostar_y_generar_matriz();
    if(saber_si_es_cuadrado_magico()){cout << "Es un cuadrado maigico"<< endl;}
    else {
        cout << "No es un cuadrado maigico"<< endl;
    }
}

void mostar_y_generar_matriz(){
    int num=0, cont=0,numeros[100];
    for (int num=0;num < 100 ;num++) {
        numeros[num]=101;
    }
    while (num==0) {
        cout <<"Ingrese el numero de Filas y Columnas:";
        cin >> Dimencion;
        if (Dimencion <= 10 and Dimencion > 0){num=1;}
    }
    generar_numeros_aleatorios(numeros);
    puntero_matriz = new int*[Dimencion];//reservando memoria para las filas
    for (num=0 ;num <Dimencion;num++) {
        puntero_matriz[num]= new int[Dimencion];// reservardo memoria para las columnas
        }
    for (int i=0;i < Dimencion;i++) {
        for (int j =0;j < Dimencion;j ++  ) {
            puntero_matriz[i][j] = numeros[cont];
            cout <<puntero_matriz[i][j]<<"  ";
            cont += 1;
        }
        cout <<endl;
        }

}

void generar_numeros_aleatorios(int numeros[] ) //genera numeros aleatorios sin repetirlos y los almacenas en un array
{
    srand(time(nullptr));
    int randon,num=0;
    while (num < (Dimencion*Dimencion)) {
        bool des=true;
        randon = 1+rand()%(Dimencion*Dimencion);
        for (int num2=0;num2 < (Dimencion*Dimencion);num2++) {
           if (randon == numeros[num2]){des=false;break;}
        }
        if (des){
            numeros[num]=randon;
            num += 1;
        }
    }
}

bool saber_si_es_cuadrado_magico(){
    if (Dimencion==1){return true;}
    int colum=0 ,fil=0, diagp=0,diags=0;
    for (int i=0 ;i < Dimencion;i ++) {
        colum=0;fil=0;
        for (int j=0;j < Dimencion;j++) {
            colum += puntero_matriz[i][j];
            fil += puntero_matriz[j][i];
            if (i==j){
                diagp += puntero_matriz[i][j];
            }
        }
        if (colum !=fil){return  false;}
    }
    int i=0,j=Dimencion-1;
    while (i<Dimencion) {
        diags +=puntero_matriz[i][j];
        i += 1;
        j -= 1;
    }
    if(diagp != diags){return false;}
    return true;
}


