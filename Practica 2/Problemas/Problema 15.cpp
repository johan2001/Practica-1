/*
Elabore un programa que permita hallar la intersección entre un par de rectángulos. Represente
los rectángulos como arreglos de 4 datos de la siguiente manera:
Los primeros 2 datos corresponden a las coordenadas de la esquina superior izquierda del rectángulo (x,y)
Los siguientes 2 datos representan el ancho y la altura del rectángulo como se observa en la Figura 5.
Implemente una función que reciba 2 arreglos que representen los rectángulos A y B, y por referencia retorne un
rectángulo C (con la misma estructura descrita anteriormente) que corresponda a la intersección de A y B como se
observa en la Figura 6.
 */

#include <iostream>
using namespace std;

void Encontrar_intercepcion(int*, int*, int*);
int main(){
    int rec1[4]={5,3,8,4},rec2[4]={3,1,6,7},inter[4];
    Encontrar_intercepcion(rec1,rec2,inter);
    for (int i=0;i < 4; i++) {
        cout << inter[i]<<endl;
    }
}
void Encontrar_intercepcion(int *arreglo1,int *arreglo2, int *inter){
    int x,y,x1,y1;
    x=arreglo1[0]+arreglo1[2];
    y=arreglo1[1]+arreglo1[3];
    x1=arreglo2[0]+arreglo2[2];
    y1=arreglo2[1]+arreglo2[3];

    if(x1 >= arreglo1[0] and  y1 > arreglo1[1] and arreglo2[0]>=0 and arreglo2[0] <= x and arreglo2[1]>=0 and arreglo2[1] <= y){
        if (arreglo1[0] > arreglo2[0]) {
            arreglo2[0] += (arreglo1[0]-arreglo2[0]);
            arreglo2[2] =x1 - arreglo2[0];
            x1 =arreglo2[0]+arreglo2[2];
        }
        if(arreglo1[1] > arreglo2[1]){
            arreglo2[1] += (arreglo1[1]-arreglo2[1]);
            arreglo2[2] =y1 - arreglo2[1];
            y1 =arreglo2[1]+arreglo2[3];
        }
        inter[0] = x - (x - arreglo2[0]);
        inter[1] = y - (y - arreglo2[1]);
        if (x1 >= x){
            inter[2] = x - arreglo2[0];
        }
        else {
            inter[2] = x1 - arreglo2[0];
        }
        if (y1 >= y){
            inter[3] = y - arreglo2[1];
        }
        else {
            inter[3] = y1 - arreglo2[1];
        }
    }
}

