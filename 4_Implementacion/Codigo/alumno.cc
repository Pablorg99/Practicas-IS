#include "alumno.h"

Alumno::Alumno(string dni, string nombre, string apellidos,
  int telefono, string direccion, string email,
  int curso, int Nequipo, bool lider): Persona(dni, nombre, 
  apellidos, telefono, direccion, email){
    setCurso(curso);
    setNequipo(Nequipo);
    //La función setLider necesita corregirse, aquí se pasa un booleano y la función recibe un objeto Alumno
    setLider(lider);
  }
  
void Alumno::setLider(Alumno aux){
  if(aux.getLider()){ lider_ = false; }
  else{ lider_ = true; }
}
