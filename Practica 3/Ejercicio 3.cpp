#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string abrir_archivo_y_extraer_datos();
void encontrar_palabras_faltantes (char* ,int ,char*, int);
void borrar_palabras(char*);

int main () {

    string palabras1="",palabras2="";
    int longi1, longi2 ;

    palabras1 = abrir_archivo_y_extraer_datos();
    longi1=int(palabras1.size());
    char *pointer1= &palabras1[0];

    palabras2 = abrir_archivo_y_extraer_datos();
    longi2 =int(palabras2.size());
    char *pointer2 = &palabras2[0];


    cout<< endl << "las palabras faltantes son: " <<endl;
    encontrar_palabras_faltantes(pointer1,longi1,pointer2,longi2);
    encontrar_palabras_faltantes(pointer2,longi2,pointer1,longi1);


}


string abrir_archivo_y_extraer_datos(){ //pide el nombre del arichivo lo abre y retorna la informacion que tenga adentro
    fstream fichero;
    string frase ,cadena="", nombre;
    bool des=true;
    while (des) {
        cout << "Dime el nombre del archivo : ";
        getline(cin,nombre);
        fichero.open ( nombre.c_str() , ios::in);
        if (fichero.is_open()) {
            des = false;
            while (! fichero.eof() ) {
                getline(fichero,frase);
                cadena+= frase + " ";
            }

            fichero.close();
        }
        else cout << "El nombre del arichivo no existe" << endl;

    }
    return cadena;
}

void encontrar_palabras_faltantes (char *palabra1,int longi,char *palabra2,int longi2){

    char pal1[20]="",pal2[20]="";
    int cont=0;

    for (int i=0; i < longi; i++) {
        if(palabra1[i]== ' ' or palabra1[i]== '\n'){
            bool des =true;
            cont = 0;
            for (int j=0; j < longi2; j++) {
                 if(palabra2[j]== ' ' or palabra2[j]== '\n'){
                     cont = 0;
                     if(strcmp(pal1,pal2)==0){
                         des =false;
                     }
                     borrar_palabras(pal2);

                 }
                 else {
                     pal2[cont]=palabra2[j];
                     cont +=1;
                 }
            }

            if(des){
                 cout << pal1 <<endl;
            }
            borrar_palabras(pal1);

        }
        else {
            pal1[cont]=palabra1[i];
            cont +=1;
        }
    }
}

void borrar_palabras(char *palabra){
    for (int i=0;i < 20 ; i++) {
        palabra[i] = NULL ;
    }
}
