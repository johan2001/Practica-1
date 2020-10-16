/*
Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
 */

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main()
{
    int num,cont=0;
    char palabra[20],numero[20];
    cout <<"ingrese una palabra:"<<endl;
    gets(palabra);
    int longitud = strlen(palabra);
    cout << "Original: ";
    for (num = 0;num < longitud;num++) {
        cout <<palabra[num];
    }
    cout<<endl;
    for (num = 0;num < longitud;num++){
        if (palabra[num]>=48 and palabra[num]<=57){
            numero[cont]=palabra[num];
            palabra[num]= 126 ;
            cont += 1;
        }
    }
    cout<<"Texto: ";
    for (num = 0;num < longitud;num++){
        if (palabra[num] != 126){cout<<palabra[num];}
    }
    cout<<". Numeros: ";
    for (num = 0;num < cont;num++){cout <<numero[num];}
    cout<<"."<<endl;

}




