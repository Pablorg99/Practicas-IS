#include "system.h"
#include <iostream>
#include <string>
#include <fstream>


void system::LeeCredenciales(string ficheroCredenciales){
    std::ifstream fichero;
    fichero.open(ficheroCredenciales);

    std::string usuario;
    fichero >> usuario;
    string pwd;
    fichero >> pwd;

    start(usuario, pwd);
}

void system::start(string usuario, string pwd){
}

