#include <iostream>
using std::cout;
using std::cin;
#include "alumno.h"

Alumno InsertaAlumno(){
  Alumno alumno;
  cout << "--Insertar alumno--" << endl;
  string aux;

  //Introduce DNI
  cout << "DNI:  ";
  cin >> aux;
  //Comprobaciónd e formato de DNI--//En mantenimiento
  while(compruebaDNI(aux)) {
    cout << "Error. Formato de DNI incorrecto."<<endl;
    cout << "Introduzcalo de nuevo. DNI:  " << endl;
  }
  alumno.setDNI(aux);
  //----------------------------------------------

  //Introduce Nombre
  cout << "Nombre:  ";
  cin >> aux;
  alumno.setNombre(aux);

  //Introduce Apellido
  cout << "Apellido:  ";
  cin >> aux;
  alumno.setApellido(aux);

  while()
//--Tranquilidad que está en proceso--
  return alumno;
}


//-----------------Para lo del DNI----------------------
bool compruebaDNI(string aux){
  if(aux.length() != 8){return false;}
  for(int i=0; i<7; i++){
    if( !( isdigit( (aux.c_str())[i] ) ) ) {
      return false;
    }
  }
  if( !( isalpha( (aux.c_str())[7] ) ) ) {
    return false;
  }
  return true;
}
//-----------------------------------------------------
