/*Problema 1. Se necesita un programa que permita determinar la mínima combinación de billetes y monedas para
una cantidad de dinero determinada. Los billetes en circulación son de $50.000, $20.000, $10.000, $5.000, $2.000
y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el número de billetes
y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas
disponibles no se puede lograr la cantidad deseada, el sistema deberá decir lo que resta para lograrla. Use arreglos
y ciclos para realizar el programa.
 */
#include <iostream>

using namespace std;

int main()
{
    int num;
    int cifras[3]={50000,20000,10000};
    int *pointer = cifras;
    cout << "Ingrese la cantidad de dinero: " << endl; cin >> num;
    for(int cont = 0;cont < 4; cont++){
        for (int i = 0; i<3 ;i ++) {
            if (num >= *(pointer+i)){
                cout << *(pointer+i) <<" : " << num/ *(pointer+i) <<endl;
                num = num % *(pointer+i);
                if (*(pointer+i) <= 50){
                    break;}
            }
            else{cout << *(pointer+i) << ": 0" <<endl;
                if (*(pointer+i) <= 50){
                    break;}
            }
        }
        cifras[0] =*pointer/10;
        cifras[1] =*(pointer+1)/10;
        cifras[2] =*(pointer+2)/10;
    }
    cout <<"faltante : " << num << endl ;
    return 0;
}
