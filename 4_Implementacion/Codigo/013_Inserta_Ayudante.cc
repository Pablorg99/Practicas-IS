#include <iostream>
using std::cout;
using std::cin;
#include "profesor.h"

Profesor InsertaAyudante(){
  Profesor ayudante;
  cout << "--Insertar ayudante--" << endl;
  string straux;
  int intaux;

  //Introduce DNI
  cout << "DNI:  ";
  cin >> straux;
  //Comprobaciónd e formato de DNI
  while(!compruebaDNI(straux)) {
    cout << "Error. Formato de DNI incorrecto."<<endl;
    cout << "Introduzcalo de nuevo. DNI:  " << endl;
    cin >> straux;
  }
  ayudante.setDNI(straux);

  //Introduce Nombre
  cout << "Nombre:  ";
  cin >> straux;
  ayudante.setNombre(straux);

  //Introduce Apellido
  cout << "Apellido:  ";
  cin >> straux;
  ayudante.setApellido(straux);

  //Introduce contraseña
  cout << "Contraseña:  ";
  cin >> straux;
  ayudante.setContrasena(straux);

  int opcion;

  do {
    cout << "¿Qué otro parámetro desea rellenar?" << endl;
    cout << "\t1. Teléfono:" << ayudante.getTelefono() << endl;
    cout << "\t2. Dirección:" << ayudante.getDireccion() << endl;
    cout << "\t3. Email:" << ayudante.getEmail() << endl;
    cout << "\t4. Guardar profesor ayudante y salir." << endl;
    cout << enld;             //Para que no quede tan apelotonado

    cout << "Opción número: ";
    cin >> opcion;

   switch (opcion) {
       case '1':
           cout << "Teléfono:  ";
           cin >> intaux;
           ayudante.setTelefono(intaux);
           cout << "\n";
           break;

       case '2':
           cout << "Dirección:  ";
           cin >> straux;
           ayudante.setDireccion(straux);
           cout << "\n";
           break;
       case '3':
           cout << "Email:  ";
           cin >> aux;
           ayudante.setEmail(aux);
           cout << "\n";
           break;

       case '4':
           cout << "Profesor ayudante guardado correctamente.\n";
           cout << "\n";
           break;

       default: cout <<opcion << " no es una opción válida del menú.\n";

       cout << endl;
     }
   }while (selection != 4 );

  return ayudante;
}
