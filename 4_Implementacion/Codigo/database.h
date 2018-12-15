#ifndef DATABASE_H
#define DATABASE_H

#include "alumno.h"
#include <list>
using std::list;

class Database {
	private:
		string Students_DB;
		string Students_DB_Backup;
		string Users_DB; 
	public:
		Database();
		bool addStudent(Alumno &new_student);
		list <Alumno> getAllStudents();
		Alumno getStudentByValue(string value, int parameter);
		bool CompareValueAndStudent(Alumno &alumno_aux, string value, int parameter);
		bool WriteDataBase(list <Alumno> new_students_list);

};




#endif
