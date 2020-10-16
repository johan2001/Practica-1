/*
Problema 3. Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.
 */

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
bool comparar_palabras (char[],char[]);
int main()
{
    char a[20], b[20];
    cout << "ingrese una palabra: "<<endl;
    gets(a);
    cout << "ingrese una palabra: "<<endl;
    gets(b);
    if (comparar_palabras(a,b)){cout <<"son iguales"<<endl;}
    else {
        cout<<"son diferentes "<<endl;    }
    return 0;
}
bool comparar_palabras (char pal1[],char pal2[]){

    unsigned int long1 = strlen(pal1),long2 = strlen(pal2);


    if (long1 == long2){
        for (unsigned int num1=0;num1 < long1;num1++) {
            if( pal1[num1] != pal2[num1]){
                return false;
            }
        }
        return true;
    }

    else {
        return false;
    }
}


