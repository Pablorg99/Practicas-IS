#include "alumno.h"

Alumno::Alumno(string dni, string nombre, string apellidos,
	int telefono, string direccion, string email,
	int curso, int Nequipo, bool lider): Persona(dni, nombre, 
	apellidos, telefono, direccion, email){
	setCurso(curso);
	setNequipo(Nequipo);
	//La función setLider necesita corregirse, aquí se pasa un booleano y la función recibe un objeto Alumno
	lider_ = lider;
}

void Alumno::cambiaLider(){
	//Falta comprobar nº lideres en equipo = 1
	if(getLider()) lider_ = false;
	else lider_ = true;
}

void Alumno::setLider(bool nuevo_lider) {
	//Falta comprobar nº lideres en equipo = 1
	lider_ = nuevo_lider;
}

ostream &operator<<(ostream &output_stream, const Alumno &alumno) {
	string bool_lider;
	if(alumno.getLider()) bool_lider = "true";
	else bool_lider = "false";
	
	output_stream << alumno.getDNI() << ',' << alumno.getNombre() << 
		alumno.getApellidos() << ',' << alumno.getTelefono() << ','
		<< alumno.getDireccion() << ',' << alumno.getEmail() << ','
		<< alumno.getCurso() << ',' << alumno.getNequipo() << ','
		<< bool_lider << '\n';
	
	return output_stream;
}

istream &operator>>(istream &input_stream, Alumno &alumno) {
	string aux_string;
	bool is_lider;
	getline(input_stream, aux_string, ',');
	alumno.setDNI(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setNombre(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setApellido(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setTelefono(stoi(aux_string));
	getline(input_stream, aux_string, ',');
	alumno.setDireccion(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setEmail(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setCurso(stoi(aux_string));
	getline(input_stream, aux_string, ',');
	alumno.setNequipo(stoi(aux_string));
	getline(input_stream, aux_string, '\n');
	if(aux_string == "true") is_lider = true;
	else is_lider = false;
	alumno.setLider(is_lider);
	
	return input_stream;
}
