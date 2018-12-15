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

bool Database::addStudent(Alumno &new_student) {
    Alumno aux_student("dni", "nombre", "apellidos");
	ifstream input_stream;
    ofstream output_stream;

    input_stream.open(BD);
    while(input_stream.eof) {
        input_stream >> aux_student;
		if(aux_student.getDNI() == new_student.getDNI()) return false;
    }

	output_stream.open(BD);
	output_stream << new_student;
	return true;
}

list <Alumno> Database::getAllStudents() {
    list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
    
	input_stream.open(BD);
	while(input_stream.eof()) {
		input_stream >> alumno_aux;
		list_aux.push_back(alumno_aux);
	}
	input_stream.close();
	
	return list_aux;
}

Alumno Database::getStudentByValue(string value, int parameter) {
	Alumno alumno_aux("dni", "nombre", "apellidos");
	ifstream input_stream;
	input_stream.open(BD);
	while(input_stream.eof()) {
		input_stream >> alumno_aux;
		if(CompareValueAndStudent(alumno_aux, value, parameter)) return alumno_aux;
	}
	std::cout << "No se ha encontrado ningún alumno con el valor especificado" << std::endl;
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

bool Database::WriteDataBase(list <Alumno> new_students_list) {
	list <Alumno> :: iterator student;
	ofstream output_stream;
	output_stream.open(BD);
	for(student = new_students_list.begin(); student != new_students_list.end(); student++) {
		output_stream << *student;
	}
}