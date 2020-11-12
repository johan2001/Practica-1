#include <fstream>
#include <iostream>


using namespace std;


string abrir_archivo_y_extraer_datos();
void generar_archivo_y_guardar_datos(string);
string archivo_en_char(char*,int);
string metodo1(char*,int,int);
string metodo2(char*,int,int);
int contar_ceros_y_unos (char*,int,int);


int main () {

    int metodo ,longi,longi2=0,semilla;
    bool des = true;
    string binario="",palabra="",codificacion="";
    codificacion= abrir_archivo_y_extraer_datos(); //guarda el contenido del archivo
    longi=int(codificacion.size()); //longitud del lo que contiene el archivo
    char *puntero = &codificacion[0]; //un puntero a la variable que continene la informacion del archivo


    cout << "Ingrese la semilla: " << endl; cin >> semilla;
    if (longi >= semilla){
        while (des) {

            cout << "Ingrese el metodo de codificacion 1 o 2: " <<endl; cin >> metodo;
            if (metodo==1) {
                binario = metodo1(puntero,semilla,longi);
                longi2= int(binario.size());
                char *puntero2 = &binario[0];
                palabra = archivo_en_char(puntero2,longi2);
                generar_archivo_y_guardar_datos(palabra);
                des=false;
            }

            else if (metodo==2) {
                binario = metodo2(puntero,semilla,longi);
                longi2= int(binario.size());
                char *puntero3 = &binario[0];
                palabra = archivo_en_char(puntero3,longi2);

                generar_archivo_y_guardar_datos(palabra);
                des=false;

            }

            else {
                cout << endl;
                cout << "Metodo no existe"<< endl;
                cout << endl;
            }

        }
    }
    else {
        cout << "La semilla es demaciado grande" <<endl;
    }

    return 0;
}


string abrir_archivo_y_extraer_datos(){ //pide el nombre del arichivo lo abre y retorna la informacion que tenga adentro
    fstream fichero;
    string frase ,cadena="", nombre;
    bool des=true;
    while (des) {
        cout << "Dime el nombre del archivo a decodificar: ";
        getline(cin,nombre);
        fichero.open ( nombre.c_str() , ios::in);
        if (fichero.is_open()) {
            des = false;
            while (! fichero.eof() ) {
                getline(fichero,frase);
                cadena+= frase;
            }

            fichero.close();
        }
        else cout << "El nombre del arichivo no existe" << endl;

    }
    return cadena;
}

void generar_archivo_y_guardar_datos(string codificado){ //pide el nombre del arichivo lo genera y el string y lo  guarda en el archivo

    ofstream fichero("decodificacion.txt") ;

    fichero << codificado;
}

string archivo_en_char(char *palabra,int longitud){ //recibe una putero con la informacion del archivo y la longitud de el, retorna el archivo convertido a binario
    string numeros="";
    longitud = longitud / 8 ;
    int j=0,cont=8;

    for (int i=0; i < longitud; i++) {
        int div=128,num=0;
        for (;j< cont; j++) {
            num += (int(palabra[j])-48) * div;
            div /=2;
        }
        cont += 8;
        numeros += char(num);
    }
    return numeros;
}

string metodo1(char *binario,int semilla,int longi2){ //recibe una putero con el archivo binario, la longitud de el y la semilla de codificaion, retorna el binario codificado.
    int  cont=0, des,cont1;
    string codificado="";
    for(int i=0;i<semilla;i++){
        if(binario[i] == '0'){codificado += "1";}
        else{codificado += "0";}
    }
    for(cont = semilla;cont < longi2;cont +=semilla){
        char *puntero =&codificado[0];
        des = contar_ceros_y_unos(puntero,semilla,cont);
        switch (des) {
        case 0:
            for (int i = cont;i < cont + semilla;i++){
                if(binario[i]== '1'){codificado += "0";}
                else{codificado += "1";}
            }
            break;
        case 1:
            cont1=1;
            for (int i = cont;i < cont+semilla;i++){
                if (cont1 == 2 or cont1==4){
                    if(binario[i]== '1'){codificado += "0";}
                    else{codificado += "1";}
                }
                else{
                    if(binario[i]== '0'){codificado += "0";}
                    else{codificado += "1";}
                }

                cont1 += 1;
            }
            break;
        case 2:
            cont1=1;
            for (int i = cont;i < cont+semilla;i++){
                if (cont1 == 3){
                    if(binario[i]== '1'){codificado += "0";}
                    else{codificado += "1";}
                }
                else{
                    if(binario[i]== '0'){codificado += "0";}
                    else{codificado += "1";}
                }

                cont1 += 1;
            }
            break;
        }
    }
    return codificado;
}

string metodo2(char *binario,int semilla,int longi2){ //recibe una putero con el archivo binario, la longitud de el y la semilla de codificaion, retorna el binario codificado.

    int cont;
    string codificado="";

    for(cont = 0;cont < longi2;cont +=semilla){

        for (int i = cont+1;i < (cont+semilla) ;i++){
            if(binario[i]=='0'){codificado+="0";}
            else {codificado +="1";}
        }
        if(binario[cont]=='0'){codificado+="0";}
        else {codificado +="1";}

    }

    return codificado;
}

int contar_ceros_y_unos (char* binario,int semilla,int cont){
    int ceros=0,unos=0;
    for (int i = (cont-semilla); i < cont;i++){
        if(binario[i] == '0'){ceros+=1;}
        else{unos+=1;}
    }
    if(unos> ceros){return 2;}
    else if(ceros > unos){return 1;}
    else {return 0;}

}

