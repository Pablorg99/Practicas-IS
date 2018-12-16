#include "profesor.h"
#include <fstream>

bool Profesor::CambiarCoordinador(){
    if(coordinador_){
        coordinador_ = false;
    }
    else{
        coordinador_ = true;
    }
    return coordinador_;
}

ostream &operator<<(ostream &output_stream, const Profesor &profesor) {
	string bool_coordinador;
	if(profesor.getCoordinador()) bool_coordinador = "true";
	else bool_coordinador = "false";

	output_stream << profesor.getDNI() << ',' << profesor.getNombre() << ','
		<< profesor.getFichero() << ',' << profesor.getApellidos() << ',' 
		<< profesor.getTelefono() << ',' << profesor.getDireccion() 
		<< ',' << profesor.getEmail() << ',' << bool_coordinador << '\n';

	return output_stream;
}

istream &operator>>(istream &input_stream, Profesor &profesor) {
	string aux_string;
	bool is_coordinador;
	getline(input_stream, aux_string, ',');
	profesor.setDNI(aux_string);
	getline(input_stream, aux_string, ',');
	profesor.setNombre(aux_string);
	getline(input_stream, aux_string, ',');
	profesor.setFichero(aux_string);
	getline(input_stream, aux_string, ',');
	profesor.setApellido(aux_string);
	getline(input_stream, aux_string, ',');
	profesor.setTelefono(atoi(aux_string.c_str()));
	getline(input_stream, aux_string, ',');
	profesor.setDireccion(aux_string);
	getline(input_stream, aux_string, ',');
	profesor.setEmail(aux_string);
	getline(input_stream, aux_string, '\n');
	if(aux_string == "true") is_coordinador = true;
	else is_coordinador = false;
	profesor.setCoordinador(is_coordinador);

	return input_stream;
}