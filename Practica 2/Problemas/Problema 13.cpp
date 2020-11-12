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

int Numeros_De_Estrellas(int(*Matriz)[8]);
void generar_numeros_aleatorios(int[]);

int main()
{

    int Matriz[6][8]={{ 0, 3, 4, 0, 0, 0, 6, 8},
                       { 5,13, 6, 0, 0, 0, 2, 3},
                       { 2, 6, 2, 7, 3, 0,10, 0},
                       { 0, 0, 4,15, 4, 1, 6, 0},
                       { 0, 0, 7,12, 6, 9,10, 4},
                       { 5, 0, 6,10, 6, 4, 8, 0}};

    int resul =Numeros_De_Estrellas(Matriz);
    cout << "hay "<<resul << " estrellas en la matriz."<<endl;
}

int Numeros_De_Estrellas (int (*Matriz)[8]){
    int cont=0,estrella;
    for(int i=0;i < 6; i++){
        estrella=0;
        for(int j=0;j < 8; j++){
            if (j>0){estrella += *(*(Matriz +i)+(j-1));}
            if (i>0){estrella += *(*(Matriz+(i-1))+j);}
            estrella += *(*(Matriz+i)+(j+1)) + *(*(Matriz+(i+1))+j);
            if((estrella/5 > 6)){cont+=1;}
        }
    }
    return cont;
}

void generar_numeros_aleatorios(int numeros[] ) //genera numeros aleatorios hasta el rango*rango sin repetirlos y los almacenas en un array
{
    srand(time_t(nullptr));
    int randon,num=0, des;
    while (num <=24) {
        des=0;
        randon = 1+rand()%(26-1);
        for (int num2=0;num2 < 25;num2++) {
           if (randon==numeros[num2]){des=1;}
        }
        if (des ==0){
            numeros[num]=randon;
            num += 1;
        }
    }
}


