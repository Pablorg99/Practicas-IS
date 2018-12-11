/*-----------------------------------------------------------------------------------
Manuel Alejandro Luque León
002_Mostrar_Alumno.cc
Fichero que implementa la funcionalidad de mostrar alumnos.
La función recibe una lista de alumno y se encarga de mostrarlos en pantalla.
-----------------------------------------------------------------------------------*/
#include "alumno.h"
#include "009_Buscar_Alumnos.cc" //esto habrá que hacerlo con el .h de Buscar_Alumnos

void MostrarAlumno(list <Alumno> listalumno){
    cout << "---------------------------------------------" << endl;
    cout << endl;

    for(list <Alumno>::iterator it = listalumno.begin(); it != listalumno.end(); it++){
        cout << "\t DNI: " << it->getTelefono() << endl;
        cout << "\t Nombre: " << it->getTelefono() << endl;
        cout << "\t Apellidos: " << it->getTelefono() << endl;
        cout << "\t Teléfono: " << it->getTelefono() << endl;
        cout << "\t Dirección: " << it->getDireccion() << endl;
        cout << "\t Email: " << it->getEmail() << endl;
        cout << "\t Último curso matriculado: " << it->getCurso() << endl;
        cout << "\t Nº de equipo: " << it->getNequipo() << endl;
        cout << "\t Líder de equipo: ";
        if(it->getLider()){cout << "Sí" <<endl;}
        else{cout << "No" << endl;}
        cout << endl;
    }

    cout << "---------------------------------------------" << endl;
}
