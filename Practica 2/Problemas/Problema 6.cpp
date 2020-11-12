/*
Problema 6. Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por ma-
yúsculas, los demás caracteres no deben ser alterados.
 */

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main()
{
    char palabra[20];
    cout <<"ingrese una palbra:"<<endl;
    gets(palabra);
    int longitud = strlen(palabra);
    cout << "Original: ";
    for (int num = 0;num < longitud;num++) {
        cout <<palabra[num];
        if (palabra[num]>= 97 and palabra[num]<=122){
            palabra[num]=palabra[num] - 32;
        }
    }
    cout <<". En mayuscula: ";
    for (int num = 0;num < longitud;num++){
        cout <<palabra[num];
    }
    cout <<endl;

}




