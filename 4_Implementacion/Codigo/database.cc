#include <database.h>
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>

Database::Database() {
	Students_DB = "Students_DataBase.txt";
	Students_DB_Backup = "Students_DataBase.bin";
	Users_DB = "Users_DataBase.txt";
}

bool Database::addStudent(Alumno &new_user) {
    Alumno aux_user("dni", "nombre", "apellidos");
	ifstream input_stream;
    ofstream output_stream;

    input_stream.open(getStudentsDB());
    while(!input_stream.eof) {
        input_stream >> aux_user;
		if(aux_user.getDNI() == new_user.getDNI()) return false;
    }

	output_stream.open(getStudentsDB());
	output_stream << new_user;
	return true;
}

list <Alumno> Database::getAllStudents() {
    list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
    
	input_stream.open(getStudentsDB());
	while(!input_stream.eof()) {
		input_stream >> alumno_aux;
		list_aux.push_back(alumno_aux);
	}
	input_stream.close();
	
	return list_aux;
}

Alumno Database::getStudentByValue(string value, int parameter) {
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
	input_stream.open(getStudentsDB());
	while(!input_stream.eof()) {
		input_stream >> alumno_aux;
		if(CompareValueAndStudent(alumno_aux, value, parameter)) return alumno_aux;
	}
	perror("Ningun usuario coincide con el valor especificado");
	return;
}

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
	return;
}

void Database::WriteStudentsDB(list <Alumno> new_students_list) {
	list <Alumno> :: iterator student;
	ofstream output_stream;
	output_stream.open(getStudentsDB());
	for(student = new_students_list.begin(); student != new_students_list.end(); student++) {
		output_stream << *student;
	}
}

void Database::addUser(Profesor new_user) {
    Profesor aux_user("dni", "nombre", "fichero", "apellidos");
	ifstream input_stream;
    ofstream output_stream;

    input_stream.open(getUsersDB());
    while(!input_stream.eof) {
        input_stream >> aux_user;
		if(aux_user.getDNI() == new_user.getDNI()) {
			perror("Este profesor ya existe");
			return;
		}
    }

	output_stream.open(getStudentsDB());
	output_stream << new_user;
}


void Database::deleteUser(string user_dni) {
	Profesor aux_user("dni", "nombre", "fichero", "apellidos");
	list <Profesor> updated_user_list;
	list <Profesor> :: iterator user;
	ifstream input_stream;
    ofstream output_stream;

	input_stream.open(getUsersDB());
	while(!input_stream.eof) {
		input_stream >> aux_user;
		updated_user_list.push_back(aux_user);
	}
	
	for(user = updated_user_list.begin(); user != updated_user_list.end(); user++) {
		if(user->getDNI() == user_dni) user = updated_user_list.erase(user);
	}

	WriteUsersDB(updated_user_list);
}

void Database::WriteUsersDB(list <Profesor> new_users_list) {
	list <Profesor> :: iterator user;
	ofstream output_stream;
	output_stream.open(getStudentsDB());
	for(user = new_users_list.begin(); user != new_users_list.end(); user++) {
		output_stream << *user;
	}
}