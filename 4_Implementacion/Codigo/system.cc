#include "system.h"
#include <iostream>
#include <string>
#include <fstream>

system::system(){
    BDusuarios_ = "usuarios.txt";
}
//Lee el fichero de credenciales e inicia el sistema si este usuario es valido
void system::LeeCredenciales(string ficheroCredenciales){
    std::ifstream fichero;
    fichero.open(ficheroCredenciales);

    //Lee las credenciales
    std::string credencial;
    fichero >> credencial;

    //Devolvera el usaurio si existe y Error si no
    Profesor usuario("0", "0", "0", "0");
    usuario = getUsuarioByCredencial(credencial);

    start(usuario);
}

void system::start(Profesor usuario){

}

Profesor system::getUsuarioByCredencial(string credencial){
    std::ifstream BDusuarios;
    BDusuarios.open(BDusuarios_);


    std::string aux;
    while(BDusuarios.eof()){
        BDusuarios >> aux;
        if(aux == credencial){
            //Lee el usuario y lo devuelve
        }
    }
    perror("Usuario no encontrado");

}
