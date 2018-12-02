/*-----------------------------------------------------------------------------------
Pablo Rodríguez Guillén
009_Buscar_Alumnos.cc
Fichero que implementa la funcionalidad de seleccionar alumnos.
El usuario selecciona un tipo de búsqueda y posteriormente se carga en el sistema
una lista de alumnos extraida de la base de datos
-----------------------------------------------------------------------------------*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <list>
using std::list;
#include <fstream>
using std::ifstream;
#include "alumno.h"

list <Alumno> BuscarAlumnos() {
    int opcion_submenu = 0;

    cout << "Indica el tipo de selección que quieres hacer:" << endl;
    cout << "\t1. Todos los alumnos registrados." << endl;
    cout << "\t2. Un número determinado de alumnos." << endl;
    cout << "\t3. Un único alumno." << endl;
    cout << "\t4. Volver al menú principal" << endl;

    cin >> opcion_submenu;

    
    switch (opcion_submenu) {
        case 1:
            return SeleccionarTodosAlumnos();    
        break;

        case 2:
            return SeleccionarNumeroAlumnos();
        break;

        case 3:
            return SeleccionarUnAlumno();
        break;
        
        case 4:
            return 0; //VolverMenuPrincipal (in progress)
        break;
        
        default:
            return 0; //VolverMenuPrincipal (in progress)
        break;
    }
}

list <Alumno> SeleccionarTodosAlumnos() {
    list <Alumno> list_aux;
    ifstream input_stream;
    input_stream.open("DataBase.bin", );
}

list <Alumno> SeleccionarNumeroAlumnos() {

}

list <Alumno> SeleccionarUnAlumno() {

}
