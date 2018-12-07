/*-----------------------------------------------------------------------------------
Pablo Rodríguez Guillén
009_Buscar_Alumnos.cc
Fichero que implementa la funcionalidad de seleccionar alumnos.
El usuario selecciona un tipo de búsqueda, introduce los valores de búsqueda y se 
devuelve una lista con los alumnos que coinciden con estos valores, comprobando estos
en la base de datos. De manera que la lista queda cargada en el sistema.
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
    int opcion_submenu;

	while(true) {
		cout << "Indica el tipo de selección que quieres hacer:" << endl;
		cout << "\t1. Todos los alumnos registrados." << endl;
		cout << "\t2. Un equipo." << endl;
		cout << "\t3. Un número determinado de alumnos." << endl;
		cout << "\t4. Un único alumno." << endl;
		cout << "\t5. Volver al menú principal." << endl;

		cin >> opcion_submenu;
		
		switch (opcion_submenu) {
			case 1:
				return getAllStudents();    
				break;

			case 2:
				int n_equipo;
				cout << "Introduzca el número del equipo que desea seleccionar: ";
				cin >> n_equipo;
				return SeleccionarUnEquipo(n_equipo);
				break;

			case 3:
				int n_alumnos;
				cout << "Introduzca el número de alumnos que desea seleccioanr: ";
				cin >> n_alumnos;
				return SeleccionarNumeroAlumnos(n_alumnos);
				break;
			
			case 4:
				return SeleccionarNumeroAlumnos(1);
				break;
			
			case 5:
				return;
				break;
			
			default:
				cout << "Elija una opción del menú." << endl;
		}
	}
}

list <Alumno> getAllStudents() {
    list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
    
	input_stream.open(BD);
	while(input_stream.eof()) {
		input_stream >> alumno_aux;
		list_aux.push_back(alumno_aux);
	}
	input_stream.close();
	
	return list_aux;
}

list <Alumno> SeleccionarUnEquipo(int n_equipo) {
	list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
	
	input_stream.open(BD);
	while(input_stream.eof()) {
		input_stream >> alumno_aux;
		if(alumno_aux.getNequipo() == n_equipo) {
			cout << alumno_aux.getApellidosyNombre() << " seleccionado" << endl;
			list_aux.push_back(alumno_aux);	
		}
	}
	
	return list_aux;
}

list <Alumno> SeleccionarNumeroAlumnos(int n_alumnos) {
	list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	int parametro;
	string valor;

	parametro = PedirParametro();
	//Sale de la función si PedirParametro devuelve 0
	if(!parametro) return;
	
	for(int i = 0; i < n_alumnos; i++) {
		valor = PedirValor(parametro);
		alumno_aux = getStudentByValue(valor, parametro);
		cout << alumno_aux.getApellidosyNombre() << " seleccionado" << endl;
		list_aux.push_back(alumno_aux);
	}
	
	return list_aux;
}

int PedirParametro() {
	int opcion_parametro;
	
	while(true) {	
		cout << "Por qué parametro desea buscar:" << endl;
		cout << "\t1. DNI." << endl;
		cout << "\t2. Nombre." << endl;
		cout << "\t3. Apellidos." << endl;
		cout << "\t4. Cancelar Búsqueda." << endl;
		cin >> opcion_parametro;

		switch (opcion_parametro) {
			case 1:
				return 1;
				break;

			case 2:
				return 2;
				break;
			
			case 3:
				return 3;
				break;

			case 4:
				return 0;
				break;
		
			default:
				cout << "Elija una opción del menú." << endl;
		}
	}
}

string PedirValor(int parametro) {
	string valor;

	switch (parametro) {
		case 1:
			cout << "Introduzca un DNI: ";
			cin >> valor;
			return valor;
			break;

		case 2:
			cout << "Introduzca un nombre: ";
			cin >> valor;
			return valor;
			break;

		case 3:
			cout << "Introduzca unos apellidos: ";
			cin >> valor;
			return valor;
			break;
	}
}

Alumno getStudentByValue(string value, int parameter) {
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
	input_stream.open(BD);
	while(input_stream.eof()) {
		input_stream >> alumno_aux;
		if(CompareValueAndStudent(alumno_aux, value, parameter)) return alumno_aux;
	}
	cout << "No se ha encontrado ningún alumno con el valor especificado" << endl;
	return;
}

bool CompareValueAndStudent(Alumno &alumno_aux, string value, int parameter) {
	switch (parameter) {
		case 1:
			if(alumno_aux.getDNI() == value) return true;
		break;

		case 2:
			if(alumno_aux.getNombre() == value) return true;
		break;
		
		case 3:
			if(alumno_aux.getApellidos() == value) return true;
		break;
	
		default:
			return false;
		break;
	}
	return;
}