/*Problema 9:
 Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.
Nota: la salida del programa debe ser:
Original: 87512395.
Suma: 994.*/

#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
    int numero,longitud,ultimo,num,num2,suma=0,potencia;
    char cadena[20];
    cout<<"escribe la cadena de numeros ;)"<<endl;
    cin>>cadena;
    cout<<"escribe el numero de cifras que desees ;)"<<endl;
    cin>>numero;
    longitud=strlen(cadena);
    ultimo=longitud-1;

    for(int i=0;i<(longitud/numero)+1;i++){
        potencia=0;

        for(int a=0;a<numero;a++){
            num=(cadena[ultimo]-48);
            num2=num*pow(10,potencia);
            if(ultimo<0){break;}
            suma=suma+num2;
            potencia++;
            ultimo--;
           }
        }
    cout<<"original: "<<cadena<<endl;
    cout<<"suma: "<<suma<<endl;
}
