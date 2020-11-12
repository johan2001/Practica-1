#ifndef USUARIOS_H
#define USUARIOS_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class usuarios
{
private:
    string usuario="", contrasena="";
    int saldo;
public:
    usuarios(string _contrasena, string _usuario, int _saldo);
    usuarios()=default;

    void setusuario(string _usuario);
    void setcontrasena(string _contrasena);
    void setsaldo(int _saldo);

    string getusuario();
    string getcontraena();
    int getsaldo();
};


#endif // USUARIOS_H
