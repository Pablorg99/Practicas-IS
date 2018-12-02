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


ostream &operator<<(ostream &output_stream, const Alumno &alumno) {
  //IN PROGRESS
  size_t string_size;
  string_size = alumno.getDNI().size();
  output_stream.write(alumno.getDNI().data(), string_size);
  string_size = alumno.getNombre().size();
  output_stream.write(alumno.getNombre().data(), string_size);
  string_size = alumno.getApellidos().size();
  output_stream.write(alumno.getApellidos().data(), string_size);

  string_size = alumno.getDireccion().size();
  output_stream.write(alumno.getDireccion().data(), string_size);

}
istream &operator>>(istream &input_stream, Alumno &alumno) {
  //IN PROGRESS  
}
