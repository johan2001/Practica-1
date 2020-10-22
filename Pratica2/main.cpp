/*
Problema 12. Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa
que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado
mágico.
 */


#include<iostream>

using namespace std;

void pedir_numeros(int[],int);
void mostar_y_generar_matriz(int (*puntero_matriz)[100],int);
bool saber_si_es_cuadrado_magico(int (*puntero_matriz)[100],int);



int main()
{
    int puntero_matriz[100][100],Dimencion = 0,num=0;
    while (num==0) {
        cout <<"Ingrese el numero de Filas y Columnas:";
        cin >> Dimencion;
        if (Dimencion <= 10 and Dimencion > 0){num=1;}
    }
    mostar_y_generar_matriz(puntero_matriz,Dimencion);
    if(saber_si_es_cuadrado_magico(puntero_matriz,Dimencion)){
        cout <<endl<<endl<< "Es un cuadrado magico"<< endl;
    }
    else {
        cout <<endl<<endl<< "No es un cuadrado magico"<< endl;
    }
}

void mostar_y_generar_matriz(int (*puntero_matriz)[100], int Dimencion){
    int cont=0,numeros[100];
    for (int num=0;num < 100 ;num++) {
        numeros[num]=101;
    }
    pedir_numeros(numeros,Dimencion);
    cout << "La Matriz Ingresasada es:"<<endl<<endl;
    for (int i=0;i < Dimencion;i++) {
        for (int j =0;j < Dimencion;j ++  ) {
            puntero_matriz[i][j] = numeros[cont];
            cout <<puntero_matriz[i][j]<<"  ";
            cont += 1;
        }
        cout <<endl;
        }

}

void pedir_numeros(int numeros[],int Dimencion)
{
    int randon,num=0, filas = 1, colunas=1;
    bool auxdes= true;
    cout << "ingrese un numeros del 1 al "<<Dimencion*Dimencion<<" sin  repetirlo"<<endl;
    while (num < (Dimencion*Dimencion)) {
        bool des=true;
        cout << "[" <<filas<<"]"<<"[" <<colunas<<"] = ";
        cin >> randon;
        if (randon > 0 and randon <=(Dimencion*Dimencion)){
            for (int num2=0;num2 < (Dimencion*Dimencion);num2++) {
               if (randon == numeros[num2]){des=false;break;}
            }
            if (des){
                if(auxdes){
                    colunas ++;
                    if(colunas == Dimencion){
                        auxdes = false;
                    }
                }
                else{
                    filas ++;
                    colunas = 1;
                    auxdes = true;
                }
                numeros[num]=randon;
                num += 1;
            }
            else {
                cout <<"El numero ingresado ya se ecuentra ingrese otro diferencte"<<endl;
            }
        }
        else {
            cout <<"Numero fuera del rango" << endl;
        }

    }
    cout << endl;
}

bool saber_si_es_cuadrado_magico(int (*puntero_matriz)[100],int Dimencion){
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




