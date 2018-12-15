#include "system.h"
using std::string;


void EliminarAyudante(){
    string dniaux, dniaux2;
    do {
        std::std::cout << "DNI del profesor ayudante a borrar: ";
        std::cin >> dniuaux;
        std::std::cout << "Introduzcalo de nuevo para comprobarlo: ";
        std::cin >> dniuaux2;
        if(! (dniaux == dniaux2) ){
            std::cout << "Error, los DNI introducidos no coinciden. Introduzcalos de nuevo.\n";
        }
    } while(! (dniaux == dniaux2) );

    


}
