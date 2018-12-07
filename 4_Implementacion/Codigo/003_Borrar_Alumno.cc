#include <list>
using std::list;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "alumno.h"

void BorrarAlumnos(list <Alumno> list_seleccion_alumnos) {
	list <Alumno> :: iterator alumno_seleccion = list_seleccion_alumnos.begin();
	list <Alumno> list_alumnos_bd;
	list <Alumno> :: iterator alumno_bd;
	list_alumnos_bd = getAllStudents();
	for(alumno_bd = list_alumnos_bd.begin(); alumno_bd != list_alumnos_bd.end(); alumno_bd++) {
		if(alumno_bd->getDNI() == alumno_seleccion->getDNI()) {
			/*Erase devuelve un nuevo valor disponible para el iterador y
			hay que asignarlo, porque el iterador se sigue usando en el
			bucle, si no se hace se producirá un segmentation fault*/
			alumno_bd = list_alumnos_bd.erase(alumno_bd);
			alumno_seleccion++;
		}
	}
	WriteDataBase(list_alumnos_bd);
}

bool WriteDataBase(list <Alumno> new_students_list) {
	list <Alumno> :: iterator student;
	ofstream output_stream;
	output_stream.open(BD);
	for(student = new_students_list.begin(); student != new_students_list.end(); student++) {
		output_stream << *student;
	}
}