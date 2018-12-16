/*
José Márquez Doblas
Sistema realizado para la practica de Ingenieria del Software
*/

#include "system.h"
#include "buscar_profesor"

using std::cout
using std::cin
using std::endl

bool ModificarProfesor(){

	string straux;
	int intaux;
	list <Profesor> listprofesor = BD.BuscarProfesor(); //No esta hecha esa parte

    if (!profesor_.getCoordinador()){
        cout << "No tiene permisos para realizar esta acción" <<endl;
        return false
    };

	for(list <Profesor>::iterator it = listprofesor.begin(); it != listprofesor.end(); it++){

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
			cout << "\t7. Coordinador: ";
			if(it->getCoordinador()){cout << "Sí" <<endl;}
			else{cout << "No" << endl;}
            cout << "\t8.Password: "
			cout << "\t0. Guardar profesor y salir." << endl;
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
					(*it).setCoordinador();         //setLider cambia el valor de lider_ cada vez que se ejecuta
					cout << "\n";
					break;

				case '0':
                    //ATENCION esta parte no está hecha
                    bd.borrarProfesor(it->getDNI());
                    Profesor profesor;
                    profesor = *it;
                    bd.insertarProfesor(profesor)
					cout << "Profesor editado y guardado correctamente.\n"; //Falta la comprobación de errores
					cout << "\n";
					break;

				default:
					cout <<opcion << " no es una opción válida del menú.\n";
					cout << endl;
			}
		}while (opcion != 0 );

	}
}
