#include "system.h"
#include <iostream>

int main(int argc, char const *argv[]){
    //system sistema;
    string credenciales;
    if (argc != 2){
        std::cout<<"Error de identificación\n";
        std::cout<<"Por favor, adjunte el nombre de su fichero de credenciales\n";
        std::cout<<"En caso de que sea la primera vez que incia el sistema adjunte el fichero facilitado por el fabricante del software\n";
        return 0;
    }
    credenciales = argv[1];
    Profesor usuario("dni", "nombre", "fichero", "apellido");
    Database BD;
    System system(credenciales, usuario, BD);
    return 0;
}
