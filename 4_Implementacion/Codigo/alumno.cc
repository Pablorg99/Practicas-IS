#include "alumno.h"
#include <fstream>
#include <iostream>

Alumno::Alumno(string dni, string nombre, string apellidos,
	int telefono, string direccion, string email,
	int curso, int Nequipo, bool lider) : Persona(dni, nombre,
	apellidos, telefono, direccion, email){
	setCurso(curso);
	setNequipo(Nequipo);
	setLider(lider);
}

bool Alumno::unicoLider() {
	Alumno aux("dni", "nombre", "apellidos");
	std::ifstream file("Students_DataBase.txt");
	while(file >> aux){
			if( this->getNequipo() == aux.getNequipo() ){
				if(aux.getLider()){return false;}
			}
	}

	file.close();
	return true;
}

void Alumno::setLider(bool nuevo_lider) {
	if( nuevo_lider && !unicoLider() ){
		exit(-1);
	}
	lider_ = false;
}

void Alumno::cambiaLider(){     //Se encarga de cambiar el valor de lider_ entre true y false
	if(!getLider() && !unicoLider()) { exit(-1); }
	else{ if(getLider()) { setLider(false); }
		else { setLider(true); }
	}
}

ostream &operator<<(ostream &output_stream, const Alumno &alumno) {
	string bool_lider;
	if(alumno.getLider()) bool_lider = "true";
	else bool_lider = "false";

	output_stream << alumno.getDNI() << ',' << alumno.getNombre() << ','
		 << alumno.getApellidos() << ',' << alumno.getTelefono() << ','
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
	alumno.setTelefono(atoi(aux_string.c_str()));
	getline(input_stream, aux_string, ',');
	alumno.setDireccion(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setEmail(aux_string);
	getline(input_stream, aux_string, ',');
	alumno.setCurso(atoi(aux_string.c_str()));
	getline(input_stream, aux_string, ',');
	alumno.setNequipo(atoi(aux_string.c_str()));
	getline(input_stream, aux_string, '\n');
	if(aux_string == "true") is_lider = true;
	else is_lider = false;
	alumno.setLider(is_lider);

	return input_stream;
}
