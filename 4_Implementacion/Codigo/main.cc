#include "system.h"
#include <iostream>

int main(int argc, char const *argv[]){
    //system sistema;
    string credenciales;
    if (argc != 2){
        std::cout<<"Error de identificación\n";
        std::cout<<"Por favor, indique su fichero de credenciales\n";
        return 0;
    }
    credenciales = argv[1];
    Profesor usuario("dni", "nombre", "fichero", "apellido");
    Database BD;
    System system(credenciales, usuario, BD);
    return 0;
}
