/*-----------------------------------------------------------------------------------
Manuel Alejandro Luque León
002_Modificar_Alumno.cc
Fichero que implementa la funcionalidad de modificar alumnos.
El usuario introduce los parámetros a editar, los nuevos datos del alumno
y posteriormente este es devuelto.
-----------------------------------------------------------------------------------*/
#include "alumno.h"
#include "009_Buscar_Alumnos.cc" //esto habrá que hacerlo con el .h de Buscar_Alumnos



list <Alumno> ModificarAlumno(){

	string straux;
	int intaux;
	list <Alumno> listalumno = BuscarAlumnos();

	for(list <Alumno>::iterator it = listalumno.begin(); it != listalumno.end(); it++){

		int opcion;

		do {
			cout << "¿Qué parámetro desea modificar?" << endl;
			cout << endl;
			cout << "\t1. DNI: " << it->getTelefono() << endl;
			cout << "\t2. Nombre: " << it->getTelefono() << endl;
			cout << "\t3. Apellidos: " << it->getTelefono() << endl;
			cout << "\t4. Teléfono: " << it->getTelefono() << endl;
			cout << "\t5. Dirección: " << it->getDireccion() << endl;
			cout << "\t6. Email: " << it->getEmail() << endl;
			cout << "\t7. Último curso matriculado: " << it->getCurso() << endl;
			cout << "\t8. Nº de equipo: " << it->getNequipo() << endl;
			cout << "\t9. Líder de equipo: ";
			if(it->getLider()){cout << "Sí" <<endl;}
			else{cout << "No" << endl;}
			cout << "\t0. Guardar alumno y salir." << endl;
			cout << endl;             //Para que no quede tan apelotonado

			cout << "Opción número: ";
			cin >> opcion;

			switch (opcion) {
				case '1':
					cout << "DNI:  ";
					cin >> straux;
					(*it).setDNI(straux);
					cout << "\n";
					break;

				case '2':
					cout << "Nombre:  ";
					cin >> straux;
					(*it).setNombre(straux);
					cout << "\n";
					break;

				case '3':
					cout << "Apellidos:  ";
					cin >> straux;
					(*it).setApellido(straux);
					cout << "\n";
					break;

				case '4':
					cout << "Teléfono:  ";
					cin >> intaux;
					(*it).setTelefono(intaux);
					cout << "\n";
					break;

				case '5':
					cout << "Dirección:  ";
					cin >> straux;
					(*it).setDireccion(straux);
					cout << "\n";
					break;

				case '6':
					cout << "Email:  ";
					cin >> straux;
					(*it).setEmail(straux);
					cout << "\n";
					break;

				case '7':
					cout << "Último curso matriculado:  ";
					cin >> intaux;
					(*it).setCurso(intaux);
					cout << "\n";
					break;

				case '8':
					cout << "Nº de equipo:  ";
					cin >> intaux;
					(*it).setNequipo(intaux);
					cout << "\n";
					break;

				case '9':
					(*it).cambiaLider();         //setLider cambia el valor de lider_ cada vez que se ejecuta
					cout << "\n";
					break;

				case '0':
					cout << "Alumno editado correctamente.\n";
					cout << "\n";
					break;

				default:
					cout <<opcion << " no es una opción válida del menú.\n";
					cout << endl;
			}
		}while (opcion != 0 );

	}
	return listalumno;
	//La funcion interna se encargará de guardarlo en la base de datos--
}
