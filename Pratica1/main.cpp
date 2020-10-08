#include <iostream>

using namespace std;
void cambio_de_maquina_expendedora();
void suma_de_horas();
void euler();
void fibonacci();
void suma_de_numeros_elevados();
void minimo_comu_multiplo();
void numeros_primos();
void maximo_palindrime();
void serie_de_collazt();
void numeros_triaguales();
bool primo (int);
bool palindromo (int);
int divisores(int);

int main()
{
    cout << "*******************Poblemas Practica 1 ******************" << endl;
    cout << "Ingrese 1 para cambio de una maquina expendedora" << endl;
    cout << "Ingrese 2 para suma de tiempo a las horas" << endl;
    cout << "Ingrese 3 para calcular euler" << endl;
    cout << "Ingrese 4 para la serie de Fibonacci" << endl;
    cout << "Ingrese 5 para suma de numeros elevado si mismo" << endl;
    cout << "Ingrese 6 para minimo comun multiplo" << endl;
    cout << "Ingrese 7 para suma de numeros primos" << endl;
    cout << "Ingrese 8 para maximo palindrome" << endl;
    cout << "Ingrese 9 para serie de Collazt" << endl;
    cout << "Ingrese 10 para secuencia de numero triangulares" << endl;

    int opcion = 0;
    cout << "Ingrese una opcion o presione 0 salir"<<endl;
    cin>>opcion;
    while (opcion !=0) {

        if (opcion==1){
            cambio_de_maquina_expendedora();
        }
        else if (opcion==2){
            suma_de_horas();
        }
        else if (opcion==3){
            euler();
        }
        else if (opcion==4){
            fibonacci();
        }
        else if (opcion==5){
            suma_de_numeros_elevados();
        }
        else if (opcion==6){
            minimo_comu_multiplo();
        }
        else if (opcion==7){
            numeros_primos();
        }
        else if (opcion==8){
            maximo_palindrime();
        }
        else if (opcion==9){
            serie_de_collazt();
        }
        else if (opcion==10){
            numeros_triaguales();
        }
        cout << "Ingrese una opcion o presione 0 salir"<<endl;
        cin>>opcion;
    }
    return 0;
}

void cambio_de_maquina_expendedora(){

    int num,cinco = 50000,dos = 20000,uno = 10000;
    cout << "Ingrese y un numero " << endl; cin >> num;
    for(int cont = 0;cont < 4; cont++){
        if (num >= cinco){
            cout << cinco <<" : " << num/ cinco <<endl;
            num = num % cinco;
            if (cinco <= 50){
                break;}
        }
        else{cout << cinco << ": 0" <<endl;
            if (cinco <= 50){
                break;}
        }
        if (num >= dos){
            cout << dos <<" : " << num/ dos <<endl;
            num = num % dos;
        }
        else{cout << dos << ": 0" <<endl;}

        if (num >=  uno){
            cout << uno <<" : " << num/ uno <<endl;
            num = num % uno;
        }
        else{cout << uno << ": 0" <<endl;}

        cinco /= 10;
        dos /= 10;
        uno /= 10;
    }
    cout <<"faltante : " << num << endl ;
}

void suma_de_horas(){

    unsigned int num1 ,num2, hora,minutos,hora2,minutos2 ;
    cout << "Igrese una Hora : " << endl; cin >> num1;
    cout << "Igrese la Hora a sumar : " << endl ; cin >> num2 ;
    if ((num1 % 100 >= 1 & num1 %100 < 60)&((num1 /100) >=1 & (num1 /100) <=24))
    {
        hora =num1 /100 ;
        minutos=num1 % 100;
    }
    else{cout<<"invalido:"<< num1 <<" es un tiempo invalido" << endl;
        return ;}

    if ((num2 % 100 >= 1 & num2%100 < 60) & ((num2 /100) >=1 & (num2 /100) <=24))
    {
        hora2 =num2 /100 ;
        minutos2 =num2 % 100;
    }
    else {cout<<"invalido:"<< num2 <<" es un tiempo invalido" << endl;
        return;}

    if(hora+hora2 <= 24 & minutos+minutos2 < 60)
    {
        cout <<"la hora es "<< hora+hora2 <<":"<< minutos+minutos2 << endl;
    }
    else{
        if (hora+hora2 <= 23 & minutos+minutos2 >= 60){
            cout<<"la hora es "<< (hora+hora2)+ 1 <<":"<< (minutos + minutos2)- 60 << endl;
        }
    }
}

void euler(){
    int num1 ;
    float e =1,num2 = 1, div;
    cout << "Ingrese un numero: " <<endl; cin >> num1;
    num1--;
    for (;num1 > 0;num1 --)
    {
        div=1;
        for (float num3=1;num3<=num2;num3 ++) {
            div *=num3;
        }
        num2 ++;
        e += 1/div;
    }
    cout <<"e es apoximadamente : "<<e<<endl;
}

void fibonacci(){
    long long int num1,num2,fin=0;
    long long int figo[100];
    figo[0] = 0;
    figo[1] = 1;
    cout << "Ingrese un numero: " <<endl; cin >> num1;
    for (num2 =1;figo[num2] <= num1 ;num2++)
    {
        figo[num2+1] = figo[num2-1] + figo[num2];


    }
    for (num2 = 1;figo[num2] <= num1;num2++) {

        if (figo[num2] % 2== 0){
           fin += figo[num2];
        }
    }
    cout << "el resultado de la suma es: "<< fin << endl;
}

void suma_de_numeros_elevados(){
    int num1,num2=1,num3,num4,final=0;
    cout << "Ingrese un numero: " <<endl; cin >> num1;

    while (num1 > 0) {
        num2 = (num1%10);
        num4 = num2;
        for (num3=1;num3<num2;num3++) {
            num4 *= num2;
        }
        final +=num4;
        num1 /=10;
    }
    cout <<"Resultado de la suma es : "<< final << endl;
}

void minimo_comu_multiplo(){
    int num1,num3,num4,num5=1;
    cout << "ingrese un numero: "<< endl;
    cin >> num1;
    for (int num2=2;num2 <= num1;num2++)
    {
        num4 = 2;
        num3 = 0;
        while (num3 == 0) {
            if (num2%num4==0){
                num3 ++;
                num5 *=num4;
            }
            else {
                num4 ++;
            }
        }
    }
    cout <<"El minumo cumun multiplo es: "<< num5 << endl;
}

void numeros_primos(){
    int num1,num3=0;
    cout << "ingrese un numero: "<< endl;
    cin >> num1;
    for (int num2=1;num2 <= num1;num2++){
        if (primo (num2)){
            num3 +=num2;
        }
    }
    cout <<"El resultado de la suma es: "<< num3 << endl;

}

void maximo_palindrime(){

    int maxpalin=0,num1=143,num2=777, numfinal1 = 0 , numfinal2=0;

    for (;num1 > 0;num1--)
    {
        if (palindromo(num1 * num2)){
           if (num1*num2 > maxpalin){
               maxpalin = num1*num2;
               numfinal1=num1;
               numfinal2=num2;
           }
        }
        else {
            num2 --;
            for (;num2 > 0;num2--){
                if (palindromo(num1 * num2)){
                    if (num1*num2 > maxpalin){
                        maxpalin= num1*num2;
                        numfinal1=num1;
                        numfinal2=num2;
                    }
                }
            }

        }

    }
    cout << numfinal1 <<"*"<<numfinal2 <<"="<<maxpalin<<endl;
}

void serie_de_collazt(){
    int num1, num2, inte, sem=0, M = 0;
    cout<<"Ingrese un numero: "<<endl; cin >> num1;
    num1--;
    for (;num1 > 0; num1--)
    {
        num2 = num1;
        inte =0;
        while (num2 !=1)
        {
            if(num2 % 2 == 0) {
                num2 = num2/2;
                inte ++;
            }
            else {
                num2 = (3*num2)+1;
                inte ++;
            }
        }
        if (inte > M){
            sem = num1;
            M = inte;
        }
    }
    cout <<"La serie mas larga es con la semilla: " << sem <<" tiene " << M << " terminos."<<endl;
}

void numeros_triaguales(){
    int num1,num2= 1,num3=2;
    cout << "ingrese un numero" << endl; cin >> num1;
    while(num1 >= divisores(num2))
    {
        num2 = num2 + num3;
        num3 ++;
    }
    cout << "El numero "<< num2 <<" que tiene " << divisores(num2)<<" divisores."<<endl;
}

bool primo (int num){
    int des = 0;
    if (num % 2 == 0)
    {
        if(num == 2){return true;}
        else{return false;}
    }
    else
    {
        for (int cont = 1;cont <= num;cont++)
        {
            if ((num % cont) == 0)
            {
                 des++;
            }
        }
        if(des == 2){return true;}
        else{return false;}
    }
}

bool palindromo ( int num){
    int  ulti=0, prim=0, des=0 , numeros[10];
    while (num > 0)
    {
        numeros[prim]= num%10;
        num /= 10;
        prim ++;
    }
    prim --;
    while (prim > ulti)
    {
        if (numeros[prim]==numeros[ulti]){
            prim --;
            ulti ++;
        }
        else {
            des=1;
            break;
        }
    }
    if (des == 0){
        return true;
    }
    else {
        return false;
    }
}

int divisores(int a)
{
    int div = 0;
    for (int cont=1;cont <= a;cont++)
    {
     if(a % cont==0 )div ++;
    }
    return div;
}
