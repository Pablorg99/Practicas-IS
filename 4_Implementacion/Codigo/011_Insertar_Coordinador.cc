#include <iostream>
#include "system.h"
using std::cout;
using std::cin;
using std::endl;


bool system::registro(){
    Profesor coordinador;

    coordinador = RegistroProfesor();
    coordinador.setCoordinador(); //Tiene que ser True
    //Guardamos al profesor 
    BDusuarios_.InsertarProfesor(coordinador);

}

