#include "database.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>

//Constructor de la base de datos
Database::Database() {
	Students_DB = "Students_DataBase.txt";
	Students_DB_Backup = "Students_DataBase.bin";
	Users_DB = "Users_DataBase.txt";
}

//Funcion que inserta un estudiante en la base de datos
bool Database::addStudent(Alumno &new_user) {
    Alumno aux_user("dni", "nombre", "apellidos");
	ifstream input_stream;
    ofstream output_stream;

    input_stream.open(getStudentsDB());
    while(input_stream >> aux_user) {
		if(aux_user.getDNI() == new_user.getDNI()) return false;
    }

	output_stream.open(getStudentsDB(), std::ios_base::app);
	output_stream << new_user;
	return true;
}

//Devuelve un usuario buscando por su DNI
Profesor Database::getUserByDNI(string dni){
	Profesor profesor_aux("dni", "nombre", "fichero", "apellidos");
	ifstream input_stream;
	input_stream.open(getUsersDB());
	while(input_stream >> profesor_aux) {
		if(profesor_aux.getDNI() == dni) return profesor_aux;
	}
	perror("Ningun usuario coincide con el valor especificado");
	return profesor_aux;
}

//Devuelve todos los alumnos de la BD
list <Alumno> Database::getAllStudents() {
    list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
    
	input_stream.open(getStudentsDB());
	while(input_stream >> alumno_aux) {
		list_aux.push_back(alumno_aux);
	}
	input_stream.close();
	
	return list_aux;
}

//Devuelve un alumno buscado por un parametro dinamico
Alumno Database::getStudentByValue(string value, int parameter) {
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
	input_stream.open(getStudentsDB());
	while(input_stream >> alumno_aux) {
		if(CompareValueAndStudent(alumno_aux, value, parameter)) return alumno_aux;
	}
	perror("Ningun usuario coincide con el valor especificado");
	return alumno_aux;
}

//Compara el valor de un parametro dinamico de un estudiante
bool Database::CompareValueAndStudent(Alumno &alumno_aux, string value, int parameter) {
	switch (parameter) {
		case 1:
			if(alumno_aux.getDNI() == value) return true;
		break;

		case 2:
			if(alumno_aux.getNombre() == value) return true;
		break;
		
		case 3:
			if(alumno_aux.getApellidos() == value) return true;
		break;
	
		default:
			return false;
		break;
	}
	return true;
}

//Escribe la base de datos de alumnos con una lista de alumnos
void Database::WriteStudentsDB(list <Alumno> new_students_list) {
	list <Alumno> :: iterator student;
	ofstream output_stream;
	output_stream.open(getStudentsDB());
	for(student = new_students_list.begin(); student != new_students_list.end(); student++) {
		output_stream << *student;
	}
}

//Inserta un usuario en el sistema
void Database::addUser(Profesor new_user) {
    Profesor aux_user("dni", "nombre", "fichero", "apellidos");
	ifstream input_stream;
    ofstream output_stream;

    input_stream.open(getUsersDB());
    while(input_stream >> aux_user) {
		if(aux_user.getDNI() == new_user.getDNI()) {
			perror("Este profesor ya existe");
			return;
		}
    }

	output_stream.open(getUsersDB(), std::ios_base::app);
	output_stream << new_user;
}

//Devuelve una lista con todos los usuarios del sistema
list <Profesor> Database::getAllUsers() {
    list <Profesor> list_aux;
	Profesor user_aux("dni", "nombre", "fichero", "apellidos");
	ifstream input_stream;
    
	input_stream.open(getUsersDB());
	while(input_stream >> user_aux) {
		list_aux.push_back(user_aux);
	}
	input_stream.close();
	
	return list_aux;
}

//elimna un usaurio del sistema por su DNI
void Database::deleteUser(string user_dni) {
	Profesor aux_user("dni", "nombre", "fichero", "apellidos");
	list <Profesor> updated_user_list;
	list <Profesor> :: iterator user;
	ifstream input_stream;
    ofstream output_stream;

	input_stream.open(getUsersDB());
	while(input_stream >> aux_user) {
		updated_user_list.push_back(aux_user);
	}
	
	for(user = updated_user_list.begin(); user != updated_user_list.end(); user++) {
		if(user->getDNI() == user_dni) user = updated_user_list.erase(user);
	}

	WriteUsersDB(updated_user_list);
}

//Busca por las credenciales a un usuario y lo devuelve
Profesor Database::getUserByCredentials(string credentials) {
	ifstream credentials_file;
	string credentials_from_file;
	list <Profesor> users_list = getAllUsers();
	list <Profesor> :: iterator user;
	for(user = users_list.begin(); user != users_list.end(); user++) {
		credentials_file.open(user->getFichero());
		getline(credentials_file, credentials_from_file);
		if(credentials_from_file == credentials) return *user;
	}
	perror("No existe ningún profesor con esos credenciales");
	exit(-1);
}

//Escribe una lista de usuarios en la BD de usuarios
void Database::WriteUsersDB(list <Profesor> new_users_list) {
	list <Profesor> :: iterator user;
	ofstream output_stream;
	output_stream.open(getUsersDB());
	for(user = new_users_list.begin(); user != new_users_list.end(); user++) {
		output_stream << *user;
	}
}