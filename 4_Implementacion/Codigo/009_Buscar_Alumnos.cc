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

	do {
		cout << "Indica el tipo de selección que quieres hacer:" << endl;
		cout << "\t1. Todos los alumnos registrados." << endl;
		cout << "\t2. Un equipo" << endl;
		cout << "\t3. Un número determinado de alumnos." << endl;
		cout << "\t4. Un único alumno." << endl;
		cout << "\t5. Volver al menú principal" << endl;

		cin >> opcion_submenu;
		
		switch (opcion_submenu) {
			case 1:
				return SeleccionarTodosAlumnos();    
			break;

			case 2:
				return SeleccionaUnEquipo();
			break;

			case 3:
				return SeleccionarNumeroAlumnos();
			break;
			
			case 4:
				return SeleccionaUnAlumno();
			break;
			
			case 5:
				exit(0);
			break;
			
			default:
				cout << "Elije una opción del menú" << endl;
			break;
		}
	} while(opcion_submenu);
}

list <Alumno> SeleccionarTodosAlumnos() {
    list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
    input_stream.open(BD);
	while(input_stream.eof()) {
		input_stream >> alumno_aux;
		list_aux.push_back(alumno_aux);
	}
	return list_aux;
}

list <Alumno> SeleccionarNumeroAlumnos() {
	list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	int n_alumnos;

	string parametro;
	string valor;

	cout << "Cuantos alumnos quiere seleccionar?"; cin >> n_alumnos;
	
	parametro = SeleccionParametro();
	valor = SeleccionValor(parametro);
	
	for(int i = 0; i < n_alumnos; i++) {
		if(parametro == "dni") alumno_aux = getStudentByDNI(valor);
		else if (parametro == "nombre") alumno_aux = getStudentByNombre(valor);
		else if (parametro == "apellidos") alumno_aux = getStudentByApellidos(valor);
		else exit(0);
		list_aux.push_back(alumno_aux);
	}
	return list_aux;
}

list <Alumno> SeleccionarUnAlumno() {

}

string SeleccionParametro() {
	string parametro;
	int opcion_parametro;
	
	do {	
		cout << "Por qué parametro quiere buscar" << endl;
		cout << "\t1. DNI" << endl;
		cout << "\t2. Nombre" << endl;
		cout << "\t3. Apellidos" << endl;
		cout << "\t4. Voler atrás" << endl;
		
		switch (opcion_parametro) {
			case 1:
				return "dni";
			break;

			case 2:
				return "nombre";
			break;
			
			case 3:
				return "apellidos";
			break;

			case 4:
				return "";
			break;
		
			default:
				cout << "Elije una opción del menú";
			break;
		}
	} while (opcion_parametro != 4);
}

string SeleccionValor(string paramaetro) {

}