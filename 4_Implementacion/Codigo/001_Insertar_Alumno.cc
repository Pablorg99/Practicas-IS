/*-----------------------------------------------------------------------------------
Manuel Alejandro Luque León
001_Insertar_Alumno.cc
Fichero que implementa la funcionalidad de añadir alumnos.
El usuario introduce los datos del alumno y posteriormente este
es devuelto.
-----------------------------------------------------------------------------------*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "alumno.h"

//Devuelve true si el alumno es añadido correctamente, false en caso contrario
bool InsertarAlumno(){
	cout << "--Insertar alumno--" << endl;
	string dniaux, nombreaux, straux;
	int intaux;

	//Introduce DNI
	cout << "DNI:  ";
	cin >> dniaux;

	//Introduce Nombre
	cout << "Nombre:  ";
	cin >> nombreaux;

	//Introduce Apellido
	cout << "Apellido:  ";
	cin >> straux;

	Alumno alumno(dniaux, nombreaux, straux);

	int opcion;

	do {
		cout << "¿Qué otro parámetro desea rellenar?" << endl;
		cout << endl;
		cout << "\t1. Teléfono:" << alumno.getTelefono() << endl;
		cout << "\t2. Dirección:" << alumno.getDireccion() << endl;
		cout << "\t3. Email:" << alumno.getEmail() << endl;
		cout << "\t4. Último curso matriculado:" << alumno.getCurso() << endl;
		cout << "\t5. Nº de equipo:" << alumno.getNequipo() << endl;
		cout << "\t6. Líder de equipo:";
		if(alumno.getLider()){cout << "Sí" <<endl;}
		else{cout << "No" << endl;}
		cout << "\t7. Guardar alumno y salir." << endl;
		cout << endl;             //Para que no quede tan apelotonado


		cout << "Opción número: ";
		cin >> opcion;

		switch (opcion) {
			case '1':
				cout << "Teléfono:  ";
				cin >> intaux;
				alumno.setTelefono(intaux);
				cout << "\n";
				break;

			case '2':
				cout << "Dirección:  ";
				cin >> straux;
				alumno.setDireccion(straux);
				cout << "\n";
				break;
				case '3':
				cout << "Email:  ";
				cin >> straux;
				alumno.setEmail(straux);
				cout << "\n";
				break;

			case '4':
				cout << "Último curso matriculado:  ";
				cin >> intaux;
				alumno.setCurso(intaux);
				cout << "\n";
				break;

			case '5':
				cout << "Nº de equipo:  ";
				cin >> intaux;
				alumno.setNequipo(intaux);
				cout << "\n";
				break;

			case '6':
				alumno.cambiaLider();         //setLider cambia el valor de lider_ cada vez que se ejecuta
				cout << "\n";
				break;

			case '7':
				cout << "Alumno guardado correctamente.\n";
				cout << "\n";
				break;

			default:
				cout <<opcion << " no es una opción válida del menú.\n";
				cout << endl;
		}
	}while (opcion != 7 );
	return addStudent(alumno);
}

bool addStudent(Alumno &new_student) {
    Alumno aux_student("dni", "nombre", "apellidos");
	ifstream input_stream;
    ofstream output_stream;

    input_stream.open(BD);
    while(input_stream.eof) {
        input_stream >> aux_student;
		if(aux_student.getDNI() == new_student.getDNI()) return false;
    }

	output_stream.open(BD);
	output_stream << new_student;
	return true;
}

//-----------------Para lo del DNI----------------------
bool compruebaDNI(string aux){
	if(aux.length() != 9){return false;}
	for(int i=0; i<8; i++){
		if( !( isdigit( (aux.c_str())[i] ) ) ) {
			return false;
		}
	}
	if( !( isalpha( (aux.c_str())[8] ) ) ) {
		return false;
	}
	return true;
}
//-----------------------------------------------------
