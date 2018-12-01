#include "alumno.h"

Alumno::Alumno(string dni, string nombre, string apellidos,
  int telefono, string direccion, string email,
  int curso, int Nequipo, bool lider): Persona(string dni,
  string nombre, string apellidos, int telefono,
  string direccion, string email){
    setcurso(curso);
    setNequipo(Nequipo);
    setlider(lider);
  }

void setLider(Alumno aux){
  if(aux.getLider()){ lider_ = false; }
  else{ lider_ = true; }
}
