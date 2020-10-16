/*
Problema 18. Las permutaciones lexicográficas son permutaciones ordenadas numérica o alfabéticamente, por
ejemplo las permutaciones lexicográficas de 0,1 y 2 son: 012, 021, 102, 120, 201, 210. Escribir un programa que
reciba un número n y halle la enésima permutación lexicográfica de los números entre 0 y 9.
Ejemplo: para n= 1000000, la permutación lexicográfica es 2783915460.
Nota: la salida del programa debe ser:
La permutacion numero 1000000 es: 2783915460.
 */

#include <iostream>
#include <algorithm>

using namespace std;

void pedir_numero(int &);
bool hallar_la_permutacion(int *areglo,int num);

int main(){
    int num,lista[10]={9,8,7,6,5,4,3,2,1,0};
    pedir_numero(num);
    hallar_la_permutacion(lista,num);
    cout << "la permutacion del numero " << num <<" es: " ;
    for (int i = 0 ;i <= 9;i++) {
        cout << lista[i];
    }
    cout <<"."<< endl ;

}

bool hallar_la_permutacion(int *areglo,int num){
    int inter=1;
    while(inter < num){
        next_permutation(areglo , areglo+10);
        inter ++;


    }
    return true;
}

void pedir_numero(int &num){
    bool des=true;
    int resul=1;
    for (int i = 2;i <= 10;i++) {
        resul *= i;
    }
    while (des) {
        cout << "Ingresa un numero: " <<endl;
        cin >> num;
        if (num >= resul){cout <<"La combinación no existe: "<<endl;}
        else {
            des =false;
        }
    }
}
