#include <iostream>
using std::cout;
using std::cin;
#include "alumno.h"

Alumno InsertaAlumno(){
  Alumno alumno;
  cout << "--Insertar alumno--" << endl;
  string straux;
  int intaux;

  //Introduce DNI
  cout << "DNI:  ";
  cin >> straux;
  //Comprobaciónd e formato de DNI--//En mantenimiento
  while(!compruebaDNI(straux)) {
    cout << "Error. Formato de DNI incorrecto."<<endl;
    cout << "Introduzcalo de nuevo. DNI:  " << endl;
    cin >> straux;
  }
  alumno.setDNI(straux);

  //Introduce Nombre
  cout << "Nombre:  ";
  cin >> straux;
  alumno.setNombre(straux);

  //Introduce Apellido
  cout << "Apellido:  ";
  cin >> straux;
  alumno.setApellido(straux);

  int opcion;

  do {
    cout << "¿Qué otro parámetro desea rellenar?" << endl;
    cout << "\t1. Teléfono:" << alumno.getTelefono() << endl;
    cout << "\t2. Dirección:" << alumno.getDireccion() << endl;
    cout << "\t3. Email:" << alumno.getEmail() << endl;
    cout << "\t4. Último curso matriculado:" << alumno.getCurso() << endl;
    cout << "\t5. Nº de equipo:" << alumno.getNequipo() << endl;
    cout << "\t6. Líder de equipo:";
    if(alumno.getLider()){cout << "Sí" <<endl;}
    else{cout << "No" << endl;}
    cout << "\t7. Guardar alumno y salir." << endl;
    cout << enld;             //Para que no quede tan apelotonado

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
           cin >> aux;
           alumno.setEmail(aux);
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
           alumno.setLider(alumno);         //setLider cambia el valor de lider_ cada vez que se ejecuta
           cout << "\n";
           break;

       case '7':
           cout << "Alumno guardado correctamente.\n";
           cout << "\n";
           break;

       default: cout <<opcion << " no es una opción válida del menú.\n";

       cout << endl;
     }
   }while (selection != 7 );

  return alumno;
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
