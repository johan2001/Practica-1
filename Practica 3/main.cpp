#include "funciones.h"

using namespace std;


int main()
{
    int modo=5,lonc=0, saldo = 0;
    string usuario,contrasena;
    string archivo_con_usuarios_y_contrasenas, archivo_con_clientes;
    map<string,string>usuario_y_contrasenas;
    vector <usuarios> clientes;

    //sacos las contraseñas del archivo donde se encuetra
    archivo_con_usuarios_y_contrasenas=abrir_archivo_y_extraer_datos("usuario administrativo.txt");
    usuario_y_contrasenas=guardar_usuarios_claves(usuario_y_contrasenas,archivo_con_usuarios_y_contrasenas);
    archivo_con_clientes=abrir_archivo_y_extraer_datos("usuarios.txt");
    clientes = crear_usuarios(clientes,archivo_con_clientes);
    cout << "*************************************" << endl;
    cout << "*************BIENVENIDO**************" << endl;
    cout << "*************************************" << endl;
    cout<< endl;
    cout<< endl;

    while (modo!=0) {

        cout << "************************************************" << endl;
        cout << "* Salir (0)  Administrativo  (1)   Usuario  (2)*" << endl;
        cout << "************************************************" << endl;
        cin >> modo;

        //menu del programa
        switch (modo) {
        case 0:{}
        break;
        case 1 :{
            int opciones =2;
            cout<< "nombre de usuario: ";
            cin >> usuario;
            cout<< endl << "contrasena: ";
            cin >> contrasena;
            cout << endl;
            char *_contrasena = &contrasena[0];
            lonc =int(contrasena.size());
            contrasena = archivo_en_binario(_contrasena,lonc);
            char *_contrasena2 = &contrasena[0];
            lonc =int(contrasena.size());
            contrasena = codificar(_contrasena2,lonc);
            if (comparar_usuario_clave(usuario_y_contrasenas,usuario,contrasena)){

                cout << "**************************************" << endl;
                cout << "******BIENVENIDO ADMINISTRADOR********" << endl;
                cout << "**************************************" << endl;
                cout<< endl;
                while (opciones != 0) {
                    cout << "*********************************" << endl;
                    cout << "* Salir (0)  Nuevo Usuario  (1) *" << endl;
                    cout << "*********************************" << endl;
                    cin >> opciones;
                    cout<< endl;
                    cout<< endl;
                    switch (opciones) {
                    case 0:{}
                    break;
                    case 1:{                    
                        cout << endl << "ingrese el Numero de cedula: ";
                        cin >> usuario;
                        cout << endl << "ingrese la clave del usuario: ";
                        cin >> contrasena;
                        cout << endl << "ingrese la saldo:  ";
                        cin >> saldo;
                        if (comparar_cliente(clientes,usuario,contrasena)){
                            cout << "usuario existente"<<endl;
                        }
                        else {
                            usuarios user;
                            user.setsaldo(saldo);
                            user.setusuario(usuario);
                            user.setcontrasena(contrasena);
                            clientes.push_back(user);
                        }

                    }
                    break;

                    default: cout<<endl<< "opcion no valido" <<endl;
                    }

                }
            }
            else{cout <<endl<< "usuarios o clave no valida"<<endl;}
        }
        break;
        case 2 :{
            int opciones =2;
            cout<< "Ingrese su numero de cedula: ";
            cin >> usuario;
            cout<< endl << "Ingrese su contrasena: ";
            cin >> contrasena;
            cout << endl;
            if (comparar_cliente(clientes,usuario,contrasena)){

                cout << "*************************************" << endl;
                cout << "*********BIENVENIDO USUARIO**********" << endl;
                cout << "*************************************" << endl;
                while (opciones != 0) {
                    cout << "********************************************************" << endl;
                    cout << "* Salir (0)  Consultar saldo  (1)  Retirar dinero  (2) *" << endl;
                    cout << "********************************************************" << endl;
                    cin >> opciones;
                    cout<< endl;
                    cout<< endl;
                    switch (opciones) {
                    case 0:{}
                    break;
                    case 1:{
                          for(auto p= begin(clientes); p != end(clientes); p++){
                              if(comparar_string(p->getusuario(),usuario)){
                                  cout << "***********************************************" << endl;
                                  cout << "* Su saldo actual es:  "<<p->getsaldo()<<" COP *"<< endl;
                                  cout << "***********************************************" << endl;
                                  p->setsaldo(p->getsaldo() - 1000);
                              }
                          }
                    }
                    break;
                    case 2:{
                        int retiro=0;
                        for(auto p= begin(clientes); p != end(clientes); p++){
                            if(comparar_string(p->getusuario(),usuario)){
                                cout << "****************************************************" << endl;
                                cout << "* Ingrese la cantidad de diero que quiere retirar: *" << endl;
                                cout << "****************************************************" << endl;
                                cin >> retiro;
                                p->setsaldo(p->getsaldo() - 1000 - retiro);
                            }
                        }
                    }
                    break;
                    default: cout<<endl<< "opcion no valido" <<endl;
                    }

                }
            }
        else{cout <<endl<< "usuarios o clave no valida"<<endl;}
        }
        break;

        default:
            cout<< "modo no disonible" <<endl;
        }
    }
    string guardar;
    for(auto p= begin(clientes); p != end(clientes); p++){
        guardar += p->getusuario()+ ",";
        guardar += p->getcontraena() + ",";
        guardar += to_string(p->getsaldo()) + "." + "\n" ;
    }
    guardar_en_un_archvio(guardar,"usuarios.txt");

    return 0;
}
