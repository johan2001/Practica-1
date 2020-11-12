#include "usuarios.h"

usuarios::usuarios(string _contrasena, string _usuario, int _saldo)
{
    usuario=_usuario;
    contrasena =_contrasena;
    saldo =_saldo;
}

void usuarios::setusuario(string _usuario)
{
    usuario = _usuario;
}

void usuarios::setcontrasena(string _contrasena)
{
    contrasena = _contrasena;
}

void usuarios::setsaldo(int _saldo)
{
    saldo =_saldo;
}

string usuarios::getusuario()
{
    return usuario;
}

string usuarios::getcontraena()
{
    return contrasena;
}

int usuarios::getsaldo()
{
    return saldo;
}


