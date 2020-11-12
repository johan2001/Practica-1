#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "usuarios.h"

using namespace std;


bool comparar_dos_string(string usuario,string contrasena,string _usuario,string _contrasena)// compara dos palabras con otras dos palabras
{
    for (auto cont=0;cont < int(usuario.size());cont++){
        if (usuario[cont] != _usuario[cont]){
            return  false;
        }
    }
    for (auto cont=0;cont < int(contrasena.size());cont++){
        if (contrasena[cont] != _contrasena[cont]){
            return  false;
        }
    }
    return true;
}

bool comparar_string(string nombre,string _nombre)// recibe dos string y los compara entre ellos
{
    for (auto cont=0;cont < int(nombre.size());cont++){
        if (nombre[cont] != _nombre[cont]){
            return  false;
        }
    }
    return true;
}

bool comparar_usuario_clave(map<string,string> usuarios_contrasenas,string _usuario,string _contrasena)
{
    string usuario="",contrasena="";
    for(auto par= begin(usuarios_contrasenas); par != end(usuarios_contrasenas); par++){
         usuario= par->first;
         contrasena = par->second;
         if(comparar_dos_string(usuario,contrasena,_usuario,_contrasena)){return true;}
    }
    return false;

}

bool comparar_cliente(vector<usuarios> _clientes,string _usuario,string _contrasena)
{
    string usuario="",contrasena="";
    for(auto p= begin(_clientes); p != end(_clientes); p++){
         usuario= p->getusuario();
         contrasena = p->getcontraena();
         if(comparar_dos_string(usuario,contrasena,_usuario,_contrasena)){return true;}
    }
    return false;

}

map<string,string> guardar_usuarios_claves(map<string,string> _usuarios_contrasenas,string archivo )// esta funcion recive un arichvo y saca los usuarioa y las contrasenas para almarcenarlas en un dicionarioo
{
    string usuario="",contrasena="";
    bool des =true;
    for(int cont=0;cont < int(archivo.size());cont++){
        if (int(archivo[cont]) == 44){
            des=false;
        }
        else {
            if(int(archivo[cont] != 46)){
                if (des){ usuario += archivo[cont];}
               else{ contrasena += archivo[cont];}
               }
            else {
                _usuarios_contrasenas[usuario]=contrasena;
                des=true;
                usuario="" ;
                contrasena="";
            }
        }
    }
    return _usuarios_contrasenas;
}

vector<usuarios> crear_usuarios(vector <usuarios> _usuarios,string archivo)
{
    string _usuario="", _contrasena="", _saldo="";
    int des =0;
    usuarios user;

    for(int cont=0;cont < int(archivo.size());cont++){
        if (int(archivo[cont]) == 44){
            des+=1;
        }
        else {
            if(int(archivo[cont] != 46)){

                if (des == 0){
                    _usuario += archivo[cont];
                }
                else if (des == 1){
                    _contrasena += archivo[cont];
                }
                else if(des ==2){
                    _saldo += archivo[cont];
                }
            }
            else {
                user.setsaldo(stoi(_saldo));
                user.setusuario(_usuario);
                user.setcontrasena(_contrasena);
                _usuarios.push_back(user);
                des=0;
                _saldo = "";
                _usuario ="";
                _contrasena = "";
                des =0;

            }
        }
    }
    return _usuarios;

}

string abrir_archivo_y_extraer_datos(string nombre)// esaata funcion abre un archivo y estrae todos los datos de el para para guardaros en un string
{
    fstream fichero;
    string frase ,cadena="";
    fichero.open ( nombre.c_str() , ios::in);
    if (fichero.is_open()) {
        while (! fichero.eof() ) {
            getline(fichero,frase);
            cadena+= frase;
        }

        fichero.close();
    }
    return cadena;
}

string codificar(char *binario,int longi){ //recibe una putero con el archivo binario, la longitud de el y la semilla de codificaion, retorna el binario codificado.
    int semilla= 4;
    int cont,cont1=semilla;
    string codificado="";

    for(cont = 0;cont < longi;cont +=semilla){
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

void guardar_en_un_archvio (string _guardar,string _nombre_del_archivo)
{
    fstream fichero;
    fichero.open ( _nombre_del_archivo , ios::out);
    if (fichero.is_open()) {
        fichero << _guardar;
        fichero.close();
    }

}

#endif // FUNCIONES_H
