
#include <fstream>
#include <iostream>


using namespace std;


string abrir_archivo_y_extraer_datos();
void generar_archivo_y_guardar_datos(string);
string archivo_en_binario(char*,int);
string metodo1(char*,int,int);
string metodo2(char*,int,int);
int contar_ceros_y_unos (char*,int,int);


int main () {

    int metodo ,longi,longi2,semilla;
    bool des = true;
    string binario,palabra,codificacion;
    palabra= abrir_archivo_y_extraer_datos(); //guarda el contenido del archivo
    longi=int(palabra.size()); //longitud del lo que contiene el archivo
    char *puntero = &palabra[0]; //un puntero a la variable que continene la informacion del archivo


    binario = archivo_en_binario(puntero,longi);
    longi2= int(binario.size());
    char *puntero2 = &binario[0];


    cout << "Ingrese la semilla: " << endl; cin >> semilla;
    if (longi2 >= semilla){
        while (des) {

            cout << "Ingrese el metodo de codificacion 1 o 2: " <<endl; cin >> metodo;
            switch (metodo) {
            case 1:
                codificacion = metodo1(puntero2,semilla,longi2);
                generar_archivo_y_guardar_datos(codificacion);
                des=false;
                break;
            case 2:
                codificacion = metodo2(puntero2,semilla,longi2);
                generar_archivo_y_guardar_datos(codificacion);
                des=false;
                break;
            default:
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
        cout << "Dime el nombre del archivo a codificar: ";
        getline(cin,nombre);
        fichero.open ( nombre.c_str() , ios::in);
        if (fichero.is_open()) {
            des = false;
            while (! fichero.eof() ) {
                getline(fichero,frase);
                cadena+= frase + '\n';
            }

            fichero.close();
        }
        else cout << "El nombre del arichivo no existe" << endl;

    }
    return cadena;
}

void generar_archivo_y_guardar_datos(string codificado){ //pide el nombre del arichivo lo genera y el string y lo  guarda en el archivo
    ofstream fichero("codificacion.txt") ;
    fichero << codificado;
}

string archivo_en_binario(char *palabra,int longitud){ //recibe una putero con la informacion del archivo y la longitud de el, retorna el archivo convertido a binario
    string numeros="";

    for (int i=0; i < longitud; i++) {
        char bin[8]="";
        int num = int (palabra[i]);
        int num2 = 128 ;
        for (int j = 0 ;j < 8; j++){
            if(num2 <= num ){
                bin[j] ='1';
                num -= num2;
            }
            else {
                bin[j]= '0';
            }
            num2 /= 2;
        }
        for (int j=0;j < 8; j++) {
            numeros += bin[j];

        }
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
        des = contar_ceros_y_unos(binario,semilla,cont);
        switch (des) {
        case 0:
            for (int i = cont;i < cont + semilla;i++){
                if(binario[i]== '0'){codificado += "1";}
                else{codificado += "0";}
            }
            break;
        case 1:
            cont1=1;
            for (int i = cont;i < cont+semilla;i++){
                if (cont1 == 2 or cont1==4){
                    if(binario[i]== '0'){codificado += "1";}
                    else{codificado += "0";}
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
                    if(binario[i]== '0'){codificado += "1";}
                    else{codificado += "0";}
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

    int cont,cont1=semilla;
    string codificado="";

    for(cont = 0;cont < longi2;cont +=semilla){
        if(binario[cont1-1]=='0'){codificado+="0";}
        else {codificado +="1";}
        for (int i = cont;i < (cont + semilla-1);i++){
            if(binario[i]=='0'){codificado+="0";}
            else {codificado +="1";}
        }
        cont1+=semilla;

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
