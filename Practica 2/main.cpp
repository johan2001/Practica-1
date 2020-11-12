/*
Problema 4. Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
y retorne dicho número. Escriba un programa de prueba.
 */

#include<iostream>
#include<conio.h>
#include<string.h>

int converti_cadena_a_numer (char[]);
using namespace std;

int main()
{
    char a[20];
    int num;
    cout << "ingrese un numero: "<<endl;
    cin.getline(a,20);
    num = converti_cadena_a_numer(a);
    cout << num + 2 << endl;
    return 0;
}
int converti_cadena_a_numer (char cadena[]){

    char numeros []={"123456789"};
    int longitud = strlen(cadena);
    int mulp,num=0,pos=longitud-1,pos2=0  ;

    for (int num2=0;num2 < longitud ;num2++) {
        mulp = 1;
        for(int num3 =0;num3 < pos ;num3++){
            mulp *= 10;
        }
        for (int num4=0;num4 <9; num4++) {
            if (cadena[pos2] == numeros[num4]){
                num +=(num4+1)*mulp;
                break;
            }
        }
        pos -= 1;
        pos2 += 1;
    }
    return num;
}





